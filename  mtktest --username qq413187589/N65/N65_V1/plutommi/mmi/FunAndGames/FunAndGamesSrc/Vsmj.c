/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/
/*****************************************************************************
 * Filename:
 * ---------
 * vsmj.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Game 
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 ****************************************************************************/
#include "MMI_include.h"
#include "GameDefs.h"

#ifdef IS_VSMJ_BASE_GAME
#include "GameInc.h"
#include "VsmjProts.h"
#include "VsmjResDef.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__      //added for multi-language
#include "GameProts.h"
#endif

/* gdi */
#include "lcd_sw_rnd.h"
#include "gd_primitive.h"
/* gdi */

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

/* debug term */
/*#define VSMJ_DEBUG_ON*/
/* debug term */

/***************************************************************************** 
* Define // 2players
*****************************************************************************/
#define TABLE_NUM (144)
#define NUM_PLAYER (2)

/* render part,frame */
#define SCORE_POS_X (30)
#define SCORE_POS_Y (30)
#define SCORE_UNIT_HEIGHT (30)
#define SCORE_FRAME (5)
#define SCORE_WIDTH (210)
#define SCORE_HEIGHT (290)

#define USER_TILE_WIDTH (18)
#define USER_TILE_HEIGHT (25)

#define TABLE_TILE_WIDTH (7)
#define TABLE_TILE_HEIGHT (10)

#define TABLE_UPDOWN_POS_X (280)
#define TABLE_UP_POS_Y  (50)
#define TABLE_DOWN_POS_Y   (200)
#define TABLE_LEFTRIGHT_POS_Y (180)
#define TABLE_LEFT_POS_X   (40)
#define TABLE_RIGHT_POS_X  (195)
#define GRAVE_POS_X (7)
#define GRAVE_POS_Y (53)

const S16 USER_LOCK_POS_X[2] = {1, 301};
const S16 USER_LOCK_POS_Y[2] = {215, 1};
const S16 USER_FLOWER_POS_X[2] = {1, 175};
const S16 USER_FLOWER_POS_Y[2] = {179, 27};
const S16 USER_OWN_POS_X[2] = {1, 31};
const S16 USER_OWN_POS_Y[2] = {215, 1};
const S16 USER_HIGHLIGHT_POS_X[2] = {301, 1};
const S16 USER_HIGHLIGHT_POS_Y[2] = {215, 1};

#define MMI_GX_VSMJ_NUM_POSITION_X (188)
#define MMI_GX_VSMJ_NUM_POSITION_Y (193)
/*shaokai modify it start 090902  144->124*/
#define MMI_GX_VSMJ_RECT_POS_X1 (124)
/*shaokai modify it end 090902*/
#define MMI_GX_VSMJ_RECT_POS_Y1 (206)
#define MMI_GX_VSMJ_RECT_POS_X2 (201)
#define MMI_GX_VSMJ_RECT_POS_Y2 (205)
#define MMI_GX_VSMJ_LEFT_BRICK_POS_X (148)
#define MMI_GX_VSMJ_LEFT_BRICK_POS_Y (176)
#define MMI_GX_VSMJ_EATCASE_BG_HEIGHT (5)
#define MMI_GX_VSMJ_GUNCASE_BG_HEIGHT (5)

#define SIGN_POS_X (10)
#define SIGN_POS_Y (110)

#define PLAYER_SPECIAL_POS_X  (40)
#define PLAYER_SPECIAL_POS_Y  (40)
#define PLAYER_SPECIAL_UNIT_WIDTH   (30)
#define PLAYER_SPECIAL_UNIT_HEIGHT (30)

#define PLAYER_ORIGINAL_SCORE 2000
#define COM_ORIGINAL_SCORE 10000

#ifdef __MMI_GAME_VSMJ_240x320__
#define MMI_GX_VSMJ_LCD_WIDTH   (240)
#define MMI_GX_VSMJ_LCD_HEIGHT  (320) 
#elif defined(__MMI_GAME_VSMJ_320x240__)
#define MMI_GX_VSMJ_LCD_WIDTH   (320)
#define MMI_GX_VSMJ_LCD_HEIGHT  (240)
#endif


const S16 HIGHLIGHT_FREE_POS_X[2] = {301, 1};
const S16 HIGHLIGHT_FREE_POS_Y[2] = {185, 27};
const S32 TOTAL_GAMES[3] = {4, 8, 16};

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* enum */
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
//added for multi-language support
typedef enum
{
    MMI_VSMJ_STRING_GAMEOVER,
    MMI_VSMJ_STRING_TOTAL
}mmi_vsmj_string_enum;
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

typedef enum
{
    MOVE_PICK_TILE = 0,
    MOVE_PICK_CHECK,
    MOVE_PICK_SPECIAL,
    MOVE_REPLENISH_TILE,
    MOVE_DISCARD_TILE,
    MOVE_DISCARD_CHECK_START,
    MOVE_DISCARD_CHECK_CONTINUE,
    MOVE_DISCARD_SPECIAL,
    MOVE_DECLARE_HOU,
    MOVE_RESULT,
    MOVE_LIOU_GU
} gx_vsmj_gamemove_enum;

typedef enum
{
    PLAYER_1 = 0,
    COM_1,
    COM_2,
    COM_3
} gx_vsmj_user_id_enum;

typedef enum
{
    PP_OWN_0 = 0,
    PP_OWN_1,
    PP_OWN_2,
    PP_OWN_3,
    PP_OWN_4,
    PP_OWN_5,
    PP_OWN_6,
    PP_OWN_7,
    PP_OWN_8,
    PP_OWN_9,
    PP_OWN_10,
    PP_OWN_11,
    PP_OWN_12,
    PP_OWN_13,
    PP_OWN_14,
    PP_OWN_15,
    PP_OWN_16,
    PP_HIGHLIGHT,
    PP_SPECIAL_HOU,
    PP_SPECIAL_PON,
    PP_SPECIAL_EAT_0,
    PP_SPECIAL_EAT_1,
    PP_SPECIAL_EAT_2,
    PP_SPECIAL_BUGUN_0,
    PP_SPECIAL_BUGUN_1,
    PP_SPECIAL_BUGUN_2,
    PP_SPECIAL_BUGUN_3,
    PP_SPECIAL_HANDGUN_0,
    PP_SPECIAL_HANDGUN_1,
    PP_SPECIAL_HANDGUN_2,
    PP_SPECIAL_HANDGUN_3,
    PP_SPECIAL_CANCEL,
    PP_ELSE,
    PP_PENNOTDOWN
} gx_vsmj_pen_pos_enum;

typedef enum
{
    TE_EAST = 0,
    TE_WEST,
    TE_SOUTH,
    TE_NORTH,
    TE_CHUNG,
    TE_FA,
    TE_BAI,

    NU_1W,
    NU_2W,
    NU_3W,
    NU_4W,
    NU_5W,
    NU_6W,
    NU_7W,
    NU_8W,
    NU_9W,

    NU_1S,
    NU_2S,
    NU_3S,
    NU_4S,
    NU_5S,
    NU_6S,
    NU_7S,
    NU_8S,
    NU_9S,

    NU_1T,
    NU_2T,
    NU_3T,
    NU_4T,
    NU_5T,
    NU_6T,
    NU_7T,
    NU_8T,
    NU_9T,

    FL_SPRING,
    FL_SUMMER,
    FL_AUTUMN,
    FL_WINTER,

    FL_M,
    FL_L,
    FL_Z,
    FL_J,

    TILE_TOTALID,

    TILE_EMPTY,
    WALL_EAT,
    WALL_PON,
    WALL_GUNSHOW,
    WALL_GUNHIDE,
    WALL_END
} gx_vsmj_tile_id_enum;

typedef enum
{
    CHK_NOTUSED = 0,
    CHK_USED,
    CHK_QUAD,
    CHK_TRIPLE,
    CHK_LINE_L,
    CHK_LINE_M,
    CHK_LINE_R,
    CHK_PAIR,
    CHK_INHLINE_L,
    CHK_INHLINE_R,
    CHK_OUTHLINE_L,
    CHK_OUTHLINE_R,
    CHK_SINGLE,
    CHK_MISSION_OCCUPY,
    CHK_END,
    POS_DESK,
    POS_GRAVE,
    POS_HAND,
    POS_HIGH,
    POS_LOCK
} gx_vsmj_chk_status_enum;

typedef enum
{
    SIGN_OFF = 0,
    SIGN_EAT,
    SIGN_PON,
    SIGN_GUN,
    SIGN_HOU,
    SIGN_LIOU_GU
} gx_vsmj_sign_enum;

typedef enum
{
    SCORE_8_FLOWER = 0,
    SCORE_7_1_FLOWER,
    SCORE_PICK_BY_OWN,
    SCORE_PICK_BY_REPLENISH,
    SCORE_MEN_CHIN,
    SCORE_MEN_CHIN_ZE_MO,
    SCORE_FLOWER_SEASON_SET,
    SCORE_FLOWER_PLANT_SET,
    SCORE_SEA_MOON,
    SCORE_CHUAN_CHIO,
    SCORE_BIG_3_YUANG,
    SCORE_SMALL_3_YUANG,
    SCORE_3_YUANG_CHUNG,
    SCORE_3_YUANG_FA,
    SCORE_3_YUANG_BAI,
    SCORE_BIG_4_WIND,
    SCORE_SMALL_4_WIND,
    SCORE_3_ENKE,
    SCORE_4_ENKE,
    SCORE_5_ENKE,
    SCORE_NUM_1_COLOR,
    SCORE_MIX_1_COLOR,
    SCORE_PAIR_PAIR_HOU,
    SCORE_TOTALNUM
} gx_vsmj_score_enum;

typedef enum
{
    COM_STRATEGY_1,
    COM_STRATEGY_2
} gx_vsmj_com_strategy_enum;

typedef enum
{
    HIGHLIGHT_EATCASE_0 = PP_SPECIAL_EAT_0,
    HIGHLIGHT_EATCASE_1 = PP_SPECIAL_EAT_1,
    HIGHLIGHT_EATCASE_2 = PP_SPECIAL_EAT_2,
    HIGHLIGHT_GUNCASE_0 = PP_SPECIAL_BUGUN_0,
    HIGHLIGHT_GUNCASE_1 =PP_SPECIAL_BUGUN_1,
    HIGHLIGHT_GUNCASE_2 =PP_SPECIAL_BUGUN_2,
    HIGHLIGHT_GUNCASE_3 =PP_SPECIAL_BUGUN_3,
    HIGHLIGHT_GUNCASE_4 =PP_SPECIAL_HANDGUN_0,
    HIGHLIGHT_GUNCASE_5 =PP_SPECIAL_HANDGUN_1,
    HIGHLIGHT_GUNCASE_6 =PP_SPECIAL_HANDGUN_2,
    HIGHLIGHT_GUNCASE_7 =PP_SPECIAL_HANDGUN_3,
    HIGHLIGHT_EAT = PP_SPECIAL_EAT_0,
    HIGHLIGHT_PON = PP_SPECIAL_PON,
    HIGHLIGHT_GUN = PP_SPECIAL_BUGUN_0,
    HIGHLIGHT_HOU = PP_SPECIAL_HOU,
    HIGHLIGHT_CANCEL = PP_SPECIAL_CANCEL
} gx_vsmj_highlight_case_enum;

/* basic game variable struct */
typedef struct
{
    BOOL is_gameover;
    BOOL is_new_game;
    U8 game_level;
    S16 game_grade;
    U16 timer_elapse;
} gx_vsmj_context_struct;

/* struct */
typedef struct
{
    gx_vsmj_tile_id_enum id;
    gx_vsmj_chk_status_enum pos;
} gx_vsmj_tile_struct;

typedef struct
{
    gx_vsmj_tile_struct *hand[18];
    gx_vsmj_tile_struct *flower[9];
    gx_vsmj_tile_struct *lock[26];
    gx_vsmj_user_id_enum id;
    BOOL can_hou;
    BOOL can_bugun[4];
    BOOL can_handgun[4];
    BOOL can_pon;
    BOOL can_eat[3];
    gx_vsmj_tile_id_enum bugun_id[4];
    gx_vsmj_tile_id_enum handgun_id[4];
    U16 start_pos_x;
    U16 hand_left;
} gx_vsmj_user_struct;

/***************************************************************************** 
* Local Function
*****************************************************************************/

void mmi_gx_vsmj_enter_game(void);  /* entry function of the game */
void mmi_gx_vsmj_init_game(void);
void mmi_gx_vsmj_exit_game(void);
void mmi_gx_vsmj_render(void);
void mmi_gx_vsmj_framemove(void);
void mmi_gx_vsmj_draw_gameover(void);
void mmi_gx_vsmj_gameover(void);
S16 mmi_gx_vsmj_calc_best_grade(S16 old_grade, S16 new_grade);
void mmi_gx_vsmj_cyclic_timer(void);

BOOL mmi_gx_vsmj_check_eat(gx_vsmj_user_struct *user_ptr, U8 type);
BOOL mmi_gx_vsmj_check_pon(gx_vsmj_user_struct *user_ptr);
BOOL mmi_gx_vsmj_check_bugun(gx_vsmj_user_struct *user_ptr);
BOOL mmi_gx_vsmj_check_handgun(gx_vsmj_user_struct *user_ptr);
BOOL mmi_gx_vsmj_check_hou(gx_vsmj_user_struct *user_ptr);
BOOL mmi_gx_vsmj_check_multi(U8 multi_time, gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[]);
BOOL mmi_gx_vsmj_check_link(U8 link_time, gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[]);
void mmi_gx_vsmj_player_move(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_com_move(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_com_think_count_value(gx_vsmj_chk_status_enum status, S16 *value);
void mmi_gx_vsmj_stagegen(void);
void mmi_gx_vsmj_throwdice(void);
void mmi_gx_vsmj_sendtile(void);    /* send tiles to player and com at game start */
void mmi_gx_vsmj_render_table(void);
void mmi_gx_vsmj_render_user(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_render_highlight(void);
void mmi_gx_vsmj_render_special_bar(void);
void mmi_gx_vsmj_render_sign(void);
void mmi_gx_vsmj_render_pen_cursor(void);
void mmi_gx_vsmj_render_scorescreen(void);
void mmi_gx_vsmj_discard_tile(gx_vsmj_tile_id_enum target_id, gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_pick_tile(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_replenish_tile(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_handgun(gx_vsmj_tile_id_enum target_id, gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_pon(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_eat(gx_vsmj_user_struct *user_ptr, U8 type);
void mmi_gx_vsmj_bugun(gx_vsmj_tile_id_enum target_id, gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_declare_hou(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_count_score(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_com_think_st_1(gx_vsmj_user_struct *user_ptr);
void mmi_gx_vsmj_com_think_st_2(gx_vsmj_user_struct *user_ptr);
S16 mmi_gx_vsmj_find_no_with_tile_id(gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[]);
void mmi_gx_vsmj_insert_tile(gx_vsmj_tile_struct *tile_target_ptr, gx_vsmj_tile_struct *tile_set_ptr[]);
BOOL mmi_gx_vsmj_eliminate_tile(gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[]);
void mmi_gx_vsmj_sort_tile(gx_vsmj_tile_struct *tile_set_ptr[]);
void mmi_gx_vsmj_pick_tile(gx_vsmj_user_struct *user_ptr);
BOOL mmi_gx_vsmj_hou_trial(gx_vsmj_tile_struct *tile_set_ptr[], BOOL pair_used);
BOOL mmi_gx_vsmj_set_chk(
        gx_vsmj_tile_id_enum target_id,
        gx_vsmj_chk_status_enum original_status,
        gx_vsmj_chk_status_enum to_status,
        gx_vsmj_tile_struct *tile_set_ptr[]);
S16 mmi_gx_vsmj_com_think_check_ting_num(gx_vsmj_tile_struct *tile_set[]);
void mmi_gx_vsmj_check_connection(gx_vsmj_tile_struct *tile_set_ptr[], gx_vsmj_chk_status_enum *temp_ptr);
void mmi_gx_vsmj_com_think_count_value(gx_vsmj_chk_status_enum status, S16 *value);
void mmi_gx_vsmj_reset_chk_all_stat_only(gx_vsmj_chk_status_enum *chk_set_ptr);
void mmi_gx_vsmj_reset_chk(gx_vsmj_tile_struct *tile_set_ptr[]);
void mmi_gx_vsmj_reset_chk_all(gx_vsmj_tile_struct *tile_set_ptr[]);

S32 mmi_gx_vsmj_get_highlight_tile_index(void);

/* Key Handler */
void mmi_gx_vsmj_key_ok_pressed(void);
void mmi_gx_vsmj_key_up_release(void);
void mmi_gx_vsmj_key_down_release(void);
void mmi_gx_vsmj_key_left_release(void);
void mmi_gx_vsmj_key_right_release(void);

S32 mmi_gx_vsmj_get_next_eatcase(S32 eatcase);
S32 mmi_gx_vsmj_get_last_eatcase(S32 eatcase);
S32 mmi_gx_vsmj_get_next_guncase(S32 guncase);
S32 mmi_gx_vsmj_get_last_guncase(S32 guncase);
S32 mmi_gx_vsmj_get_next_specialcase(S32 eatcase);
S32 mmi_gx_vsmj_get_last_specialcase(S32 eatcase);

#ifdef VSMJ_DEBUG_ON
void mmi_gx_vsmj_key_1_release(void);
void mmi_gx_vsmj_key_2_release(void);
void mmi_gx_vsmj_key_3_release(void);
S32 debug_case = 0;
#endif
 
#ifdef VSMJ_DEBUG_ON_
void mmi_gx_vsmj_debug(void);
#endif

/* Game play functions */

/* key functions */
#ifdef __MMI_TOUCH_SCREEN__
void mmi_gx_vsmj_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_gx_vsmj_pen_up_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* key functions */

/***************************************************************************** 
* Local Variable
*****************************************************************************/

static gx_vsmj_context_struct g_gx_vsmj_context = 
{
    FALSE,  /* is_gameover */
    TRUE,   /* is_new_game */
    0,      /* game_level */
    0,      /* game_grade */
    200     /* timer_elapse */
};

gx_vsmj_tile_struct tile_table[TABLE_NUM];

gx_vsmj_tile_struct wall_eat = 
{
    WALL_EAT,
    POS_HAND
};
gx_vsmj_tile_struct wall_pon = 
{
    WALL_PON,
    POS_HAND
};
gx_vsmj_tile_struct wall_gunshow = 
{
    WALL_GUNSHOW,
    POS_HAND
};
gx_vsmj_tile_struct wall_gunhide = 
{
    WALL_GUNHIDE,
    POS_HAND
};
gx_vsmj_tile_struct wall_end = 
{
    WALL_END,
    CHK_END
};

gx_vsmj_tile_struct tile_empty = 
{
    TILE_EMPTY,
    POS_HAND
};

gx_vsmj_user_struct user[NUM_PLAYER];
gx_vsmj_com_strategy_enum com_strategy[NUM_PLAYER];
gx_vsmj_user_struct *last_user = &user[0];
gx_vsmj_user_struct *current_user = &user[0];
gx_vsmj_tile_struct *highlight = &wall_end;
gx_vsmj_tile_struct *grave[96]; /* at most 144-16-16-2*8(liou gu) =96 */

S16 start_index = 0;            /* save the position of table to pick (num acc. to scr) */
S16 end_index = TABLE_NUM - 1;  /* save the position of table to replenish (num acc. to scr ) */
S16 grave_index = 0;
S16 table_offset = 0;

S16 gun_times = 0;  /* used to determine how many tiles left on table => liou gu */
S16 game_delay = 0;

gx_vsmj_gamemove_enum game_move;
gx_vsmj_pen_pos_enum pen_pos = PP_PENNOTDOWN;

gx_vsmj_sign_enum sign;
U8 sign_delay = 0;

S16 pen_last_x = 0;
S16 pen_last_y = 0;

                     /* score relative *//* haven't put in init!!!!!!!! */
BOOL score_8_flower;
BOOL score_7_1_flower;
BOOL score_last_by_own;
BOOL score_hou_by_replenish;
BOOL bonus_hou[SCORE_TOTALNUM];

S32 highlight_special;
S32 highlight_eatcase;
S32 highlight_guncase;
S32 highlight_tile_index;
S32 game_number;

gx_vsmj_user_id_enum	banker;

#ifdef  __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ /*added for game multi-language*/
static U16 mmi_vsmj_language_index;
#define MMI_VSMJ_STRING_COUNT MMI_VSMJ_STRING_TOTAL
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#ifdef VSMJ_DEBUG_ON_
S16 gx_vsmj_debug[40];
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_enter_gfx
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_enter_gfx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_ID_GX_VSMJ_GAME_ICON;   /* game icon img ID */
    GFX.game_data.game_str_id = STR_ID_GX_VSMJ_GAME_NAME;   /* game name string ID */

    GFX.game_data.menu_resume_str_id = STR_GAME_RESUME; /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_GAME_NEW;       /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_GAME_LEVEL;   /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_GAME_GRADE;   /* "Best Grade" string ID */

    GFX.game_data.menu_help_str_id = STR_GAME_HELP; /* "Game Help" string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_ID_GX_VSMJ_LEVEL1;   /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_ID_GX_VSMJ_LEVEL2; /* level string ID */
	GFX.game_data.level_str_id_list[2] = STR_ID_GX_VSMJ_LEVEL3; /* level string ID */

    /* add slot in NVRAMEnum.h */
    GFX.game_data.grade_nvram_id_list[0] = NVRAM_GX_VSMJ_LEVEL1;  /* grade slot in NVRAM (short) */
    GFX.game_data.grade_nvram_id_list[1] = NVRAM_GX_VSMJ_LEVEL2;        /* grade slot in NVRAM */
	GFX.game_data.grade_nvram_id_list[2] = NVRAM_GX_VSMJ_LEVEL3;
    GFX.game_data.level_nvram_id = NVRAM_GX_VSMJ_LEVEL; /* current lvl idnex  in NVRAM (byte) */

    /* help */
    GFX.game_data.help_str_id = STR_ID_GX_VSMJ_HELP_DESCRIPTION;        /* help description string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&g_gx_vsmj_context.game_grade);    /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&g_gx_vsmj_context.game_level);     /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) (&g_gx_vsmj_context.is_new_game);      /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = mmi_gx_vsmj_calc_best_grade;    /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = mmi_gx_vsmj_enter_game; /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = mmi_gx_vsmj_exit_game;   /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = mmi_gx_vsmj_draw_gameover;   /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_calc_best_grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  best of old_grade and new_grade
 *****************************************************************************/
S16 mmi_gx_vsmj_calc_best_grade(S16 old_grade, S16 new_grade)
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
 *  mmi_gx_vsmj_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	game_number++;
	if (game_number > TOTAL_GAMES[g_gx_vsmj_context.game_level] ||
		g_gx_vsmj_context.game_grade <= 0 ||
		g_gx_vsmj_context.game_grade >= PLAYER_ORIGINAL_SCORE + COM_ORIGINAL_SCORE)
	{
		/* game over, show gameover screen */
		g_gx_vsmj_context.is_gameover = TRUE;
		g_gx_vsmj_context.is_new_game = TRUE;

		mmi_gfx_entry_gameover_screen();
	}
	else
	{
		/*start a new game to play*/
    #ifndef __MMI_GAME_VSMJ_320x240__
		gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
		gdi_layer_resize(MMI_GX_VSMJ_LCD_HEIGHT, MMI_GX_VSMJ_LCD_WIDTH);
    #endif

		/* set winner of the last game is banker */
		/* liou gu -> don't change banker */
		if (game_move != MOVE_LIOU_GU)
		{
			if (current_user->id == PLAYER_1)
			{
				banker = PLAYER_1;
			}
			else
			{
				banker = COM_1;
			}
		}

		mmi_gx_vsmj_init_game();

		g_gx_vsmj_context.is_new_game = FALSE;
		g_gx_vsmj_context.is_gameover = FALSE;

		mmi_gx_vsmj_cyclic_timer();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_draw_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_draw_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* put gameover sound here */
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    mmi_gfx_draw_gameover_screen(
        IMG_ID_GX_VSMJ_GOTEXT,
        IMG_ID_GX_VSMJ_GRADESMAP,
        IMG_ID_GX_VSMJ_GOPIC,
        g_gx_vsmj_context.game_grade);
#else
    mmi_gfx_draw_gameover_screen(
        mmi_gfx_get_multilanguage_image_ID(
         mmi_vsmj_language_index, 
         IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE0, 
         MMI_VSMJ_STRING_COUNT, 
         MMI_VSMJ_STRING_GAMEOVER),
        IMG_ID_GX_VSMJ_GRADESMAP,
        IMG_ID_GX_VSMJ_GOPIC,
        g_gx_vsmj_context.game_grade);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_enter_game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_enter_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__  //used for multilanguage
    mmi_vsmj_language_index = g_mmi_game_current_language_index;
    mmi_gfx_check_image_get_valid_language(
        &mmi_vsmj_language_index, 
        IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE0, 
        MMI_VSMJ_STRING_COUNT);
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#ifndef __MMI_GAME_VSMJ_320x240__
    gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_270);
    gdi_layer_resize(MMI_GX_VSMJ_LCD_HEIGHT, MMI_GX_VSMJ_LCD_WIDTH);
#endif

    if (g_gx_vsmj_context.is_new_game == TRUE)
    {
        banker = PLAYER_1; /* set original banker is player */
		game_number = 1; 
		g_gx_vsmj_context.game_grade = PLAYER_ORIGINAL_SCORE; /* set original score of the player */
        mmi_gx_vsmj_init_game();    /* is new game, otherwise resume game */
    }

    g_gx_vsmj_context.is_new_game = FALSE;
    g_gx_vsmj_context.is_gameover = FALSE;

	/* keyhandler */
	SetKeyHandler(mmi_gx_vsmj_key_ok_pressed, KEY_ENTER, KEY_EVENT_UP);
	SetKeyHandler(mmi_gx_vsmj_key_ok_pressed, KEY_LSK, KEY_EVENT_UP);
#ifndef __MMI_GAME_VSMJ_320x240__
    SetKeyHandler(mmi_gx_vsmj_key_left_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_right_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_up_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_down_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_gx_vsmj_key_up_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_down_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_right_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_left_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
#endif
	
#ifdef VSMJ_DEBUG_ON
	SetKeyHandler(mmi_gx_vsmj_key_1_release, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_gx_vsmj_key_2_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_gx_vsmj_key_3_release, KEY_3, KEY_EVENT_UP);
#endif

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_gx_vsmj_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_gx_vsmj_pen_up_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* keyhandler */

    mmi_gx_vsmj_cyclic_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_exit_game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_exit_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GAME_VSMJ_320x240__
    gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_resize(MMI_GX_VSMJ_LCD_WIDTH, MMI_GX_VSMJ_LCD_HEIGHT);
#endif

    gui_fill_rectangle(0, 0, MMI_GX_VSMJ_LCD_WIDTH - 1, MMI_GX_VSMJ_LCD_HEIGHT - 1, gui_color(0, 0, 0));

    gui_cancel_timer(mmi_gx_vsmj_cyclic_timer); /* cancle the looping timer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_init_game
 * DESCRIPTION
 *  Game initilization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_init_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* basic game variable */
    g_gx_vsmj_context.is_new_game = FALSE;
    g_gx_vsmj_context.is_gameover = FALSE;
    /* basic game variable */

    /* set id */
    user[0].id = PLAYER_1;
    user[1].id = COM_1;
    /* set id */

    for (i = 0; i < NUM_PLAYER; i++)
    {
        user[i].flower[0] = &wall_end;
        user[i].hand[0] = &wall_end;
        user[i].lock[0] = &wall_end;
        user[i].can_hou = FALSE;
        user[i].can_bugun[0] = FALSE;
        user[i].can_bugun[1] = FALSE;
        user[i].can_bugun[2] = FALSE;
        user[i].can_bugun[3] = FALSE;
        user[i].can_handgun[0] = FALSE;
        user[i].can_handgun[1] = FALSE;
        user[i].can_handgun[2] = FALSE;
        user[i].can_handgun[3] = FALSE;
        user[i].can_pon = FALSE;
        user[i].can_eat[0] = FALSE;
        user[i].can_eat[1] = FALSE;
        user[i].can_eat[2] = FALSE;
        user[i].bugun_id[0] = TILE_EMPTY;
        user[i].bugun_id[1] = TILE_EMPTY;
        user[i].bugun_id[2] = TILE_EMPTY;
        user[i].bugun_id[3] = TILE_EMPTY;
        user[i].handgun_id[0] = TILE_EMPTY;
        user[i].handgun_id[1] = TILE_EMPTY;
        user[i].handgun_id[2] = TILE_EMPTY;
        user[i].handgun_id[3] = TILE_EMPTY;
        user[i].start_pos_x = 0;
        user[i].hand_left = 17;
    }

    for (i = 0; i < NUM_PLAYER; i++)
    {
        com_strategy[i] = COM_STRATEGY_2;    
    }

    start_index = 0;
    end_index = TABLE_NUM - 1;
    grave_index = 0;
    grave[grave_index] = &wall_end;
    table_offset = 0;
    gun_times = 0;
    highlight = &wall_end;

    mmi_gx_vsmj_stagegen();
    mmi_gx_vsmj_throwdice();
    mmi_gx_vsmj_sendtile();

    game_move = MOVE_PICK_CHECK;

	if (banker == PLAYER_1)
	{
		current_user = &user[0];
	}
	else
	{
		current_user = &user[1];
	}

    pen_last_x = 100;
    pen_last_y = 200;

    sign_delay = 0;
    sign = SIGN_OFF;

    game_delay = 0;

    highlight_special = -1;
    highlight_eatcase = -1;
    highlight_guncase = -1;
    highlight_tile_index = 17;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* gdi_draw_solid_rect(0,0,MMI_GX_VSMJ_LCD_WIDTH-1,MMI_GX_VSMJ_LCD_HEIGHT-1,gd_color_from_rgb_24(0,59,169,25)); */
    switch (game_move)
    {
        case MOVE_RESULT:
        #ifndef __MMI_GAME_VSMJ_320x240__
            gdi_draw_solid_rect(0, 0, MMI_GX_VSMJ_LCD_HEIGHT - 1, MMI_GX_VSMJ_LCD_WIDTH - 1, GDI_COLOR_BLUE);
        #else
            gdi_draw_solid_rect(0, 0, MMI_GX_VSMJ_LCD_WIDTH - 1, MMI_GX_VSMJ_LCD_HEIGHT - 1, GDI_COLOR_BLUE);
        #endif
            mmi_gx_vsmj_render_scorescreen();
            break;

        default:
        #ifndef __MMI_GAME_VSMJ_320x240__
			gui_fill_rectangle(0, 0, MMI_GX_VSMJ_LCD_HEIGHT - 1, MMI_GX_VSMJ_LCD_WIDTH - 1, gui_color(153, 153, 204));
        #else
            gui_fill_rectangle(0, 0, MMI_GX_VSMJ_LCD_WIDTH - 1, MMI_GX_VSMJ_LCD_HEIGHT - 1, gui_color(153, 153, 204));
        #endif
            mmi_gx_vsmj_render_table();
            /* render all user */
            mmi_gx_vsmj_render_user(&user[0]);
            mmi_gx_vsmj_render_user(&user[1]);
            /* render all user */
            mmi_gx_vsmj_render_highlight();
            mmi_gx_vsmj_render_special_bar();
            mmi_gx_vsmj_render_sign();

            break;
    }
    gdi_lcd_repaint_all();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_highlight
 * DESCRIPTION
 *  Render the table images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (game_move)
    {
        case MOVE_DISCARD_CHECK_CONTINUE:
        case MOVE_DISCARD_CHECK_START:
        case MOVE_DISCARD_SPECIAL:
            gdi_image_draw_id(
                HIGHLIGHT_FREE_POS_X[last_user->id],
                HIGHLIGHT_FREE_POS_Y[last_user->id],
                (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id));
            break;

        case MOVE_PICK_TILE:
        case MOVE_REPLENISH_TILE:
            gdi_image_draw_id(
                USER_HIGHLIGHT_POS_X[current_user->id],
                USER_HIGHLIGHT_POS_Y[current_user->id],
                IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
            break;
        case MOVE_PICK_CHECK:
        case MOVE_PICK_SPECIAL:
        case MOVE_DISCARD_TILE:
        case MOVE_DECLARE_HOU:
            if (highlight->id != WALL_END)
            {
                if (current_user->id == PLAYER_1 || game_move == MOVE_DECLARE_HOU)
                {
					if (current_user->id != PLAYER_1 && game_move == MOVE_DECLARE_HOU)
					{
						gdi_image_draw_id(
							USER_HIGHLIGHT_POS_X[current_user->id],
							USER_HIGHLIGHT_POS_Y[current_user->id],
							(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id));
					}
					else
					{
						gdi_image_draw_id(
							USER_HIGHLIGHT_POS_X[current_user->id],
							USER_HIGHLIGHT_POS_Y[current_user->id],
							(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id));
						gdi_image_draw_id(USER_HIGHLIGHT_POS_X[current_user->id], USER_HIGHLIGHT_POS_Y[current_user->id] - 4, IMG_ID_GX_VSMJ_TOP_SOLID);
						
						/* draw arrowhead */
						if (game_move == MOVE_DISCARD_TILE)
						{ 
							if (highlight_tile_index == mmi_gx_vsmj_get_highlight_tile_index())
							{
								gdi_image_draw_id(USER_HIGHLIGHT_POS_X[current_user->id] + 3,
									USER_HIGHLIGHT_POS_Y[current_user->id] - 19,
									IMG_ID_GX_VSMJ_ARROWHEAD);
							}
						}
					}
                }
                else
                {
                    gdi_image_draw_id(
                        USER_HIGHLIGHT_POS_X[current_user->id],
                        USER_HIGHLIGHT_POS_Y[current_user->id],
                        IMG_ID_GX_VSMJ_BRICK_USER_UP_BACK);
                }
            }
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_table
 * DESCRIPTION
 *  Render the table images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* to be refined later */
    S16 i;

    S16 tile_pos_x;
    S16 tile_pos_y;

    S32 str_w;
    S32 str_h;

    S16 dx;
    S16 num_buffer;
    S16 position_shift;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* draw games */
	gui_measure_string((UI_string_type) GetString(STR_ID_GX_VSMJ_CUR_GAME), &str_w, &str_h);

	gui_fill_rectangle(
		MMI_GX_VSMJ_RECT_POS_X1, 
		MMI_GX_VSMJ_RECT_POS_Y1 -str_h - 4,
		MMI_GX_VSMJ_RECT_POS_X1 + str_w + 24, 
		MMI_GX_VSMJ_RECT_POS_Y1,
		gui_color(0, 255, 0));
	gui_draw_rectangle(
		MMI_GX_VSMJ_RECT_POS_X1, 
		MMI_GX_VSMJ_RECT_POS_Y1 -str_h - 4,
		MMI_GX_VSMJ_RECT_POS_X1 + str_w + 24, 
		MMI_GX_VSMJ_RECT_POS_Y1,
		gui_color(0, 0, 0));

	gui_set_font(&MMI_medium_font);
	gui_push_text_clip();
    gui_set_text_clip(
		MMI_GX_VSMJ_RECT_POS_X1, 
		MMI_GX_VSMJ_RECT_POS_Y1 - str_h - 2,
		MMI_GX_VSMJ_RECT_POS_X1 + str_w, 
		MMI_GX_VSMJ_RECT_POS_Y1 - 2);
    gui_set_text_color(gui_color(0, 0, 0));
	if (r2lMMIFlag == 1)
	{
        gui_move_text_cursor(MMI_GX_VSMJ_RECT_POS_X1 + 2 + str_w, MMI_GX_VSMJ_RECT_POS_Y1 -str_h - 2);
	}
	else
	{
        gui_move_text_cursor(MMI_GX_VSMJ_RECT_POS_X1 + 2, MMI_GX_VSMJ_RECT_POS_Y1 -str_h - 2);
	}
    gui_print_text((UI_string_type) GetString(STR_ID_GX_VSMJ_CUR_GAME));
    gui_pop_text_clip();

	num_buffer = game_number;
    position_shift = MMI_GX_VSMJ_RECT_POS_X1 + str_w + 13;
    do
    {
        image_id = IMG_ID_GX_VSMJ_NUMBER_0 + (num_buffer % 10);
        num_buffer = num_buffer / 10;
        gdi_image_draw_id(position_shift, MMI_GX_VSMJ_RECT_POS_Y1 - (str_h + 15) / 2, (U16) image_id);
        position_shift = position_shift - 9;
    } while (num_buffer != 0);

	/* draw score */
	num_buffer = g_gx_vsmj_context.game_grade;
    position_shift = 270;
    do
    {
        image_id = IMG_ID_GX_VSMJ_NUMBER_0 + (num_buffer % 10);
        num_buffer = num_buffer / 10;
        gdi_image_draw_id(position_shift, 195, (U16) image_id);
        position_shift = position_shift - 9;
    } while (num_buffer != 0);

	num_buffer = PLAYER_ORIGINAL_SCORE + COM_ORIGINAL_SCORE - g_gx_vsmj_context.game_grade;
    position_shift = 80;
    do
    {
        image_id = IMG_ID_GX_VSMJ_NUMBER_0 + (num_buffer % 10);
        num_buffer = num_buffer / 10;
        gdi_image_draw_id(position_shift, 30, (U16) image_id);
        position_shift = position_shift - 9;
    } while (num_buffer != 0);

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

    /* draw grave */

    tile_pos_x = GRAVE_POS_X;
    tile_pos_y = GRAVE_POS_Y;
    dx = USER_TILE_WIDTH;
    for (i = 0; i < grave_index; i++)
    {
        gdi_image_draw_id(tile_pos_x, tile_pos_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + grave[i]->id));
        tile_pos_x = tile_pos_x + dx;
        if (i % 17 == 16)
        {
            tile_pos_y = tile_pos_y + USER_TILE_HEIGHT;
            tile_pos_x = GRAVE_POS_X;
        }
    }
    /* draw grave */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_user
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  user_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_user(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;
    S16 draw_x;
    S16 draw_y;
    BOOL highlight_is_skipped = TRUE;
    S16 shift_x, shift_x_count;
    S16 tile_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw flower */
    draw_x = USER_FLOWER_POS_X[user_ptr->id];
    draw_y = USER_FLOWER_POS_Y[user_ptr->id];

    i = 0;
    while (user_ptr->flower[i]->id != WALL_END)
    {
        gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->flower[i]->id));
        draw_x += USER_TILE_WIDTH;
        i++;
    }
    /* draw flower */

    /* draw lock */
    shift_x_count = 0;
    if (user_ptr->id == COM_1)
    {
        shift_x = -1;
        tile_width = -1 * USER_TILE_WIDTH;
    }
    else
    {
        shift_x = 1;
        tile_width = USER_TILE_WIDTH;
    }

    draw_x = USER_LOCK_POS_X[user_ptr->id];
    draw_y = USER_LOCK_POS_Y[user_ptr->id];

    i = 0;
    while (user_ptr->lock[i]->id != WALL_END)
    {
        switch (user_ptr->lock[i]->id)
        {
            case WALL_END:
            case WALL_PON:
            case WALL_EAT:
            case TILE_EMPTY:
                i++;
                draw_x += shift_x;
                shift_x_count++;
                break;
            case WALL_GUNSHOW:
				if (user_ptr->id == COM_1)
				{
					gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					draw_x += tile_width;
					gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					gdi_image_draw_id(
						draw_x,
						draw_y - (shift_x * 5),
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					draw_x += tile_width;
					gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					draw_x += tile_width;
					i += 5;
				}
				else
				{
					gdi_image_draw_id(draw_x, draw_y - 5, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
					draw_x += tile_width;
					gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
					gdi_image_draw_id(
						draw_x,
						draw_y - 13,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					gdi_image_draw_id(draw_x, draw_y + 9, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
					draw_x += tile_width;
					gdi_image_draw_id(draw_x, draw_y - 5, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
					gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
					draw_x += tile_width;
					i += 5;
				}

                break;
            case WALL_GUNHIDE:  /* 2ppl: user id 0,1 up / down need one image */
                /* 4ppl: user id 0,2 up/down one image,  1,3 need one image */
                /* currently only ver image */
                if (game_move != MOVE_DECLARE_HOU)
                {
					if (user_ptr->id == COM_1)
					{
						gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						gdi_image_draw_id(draw_x, draw_y - (shift_x * 5), IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						draw_x += tile_width;
						i = i + 5;  /* pass the gun tile ,to the next wall */
					}
					else
					{
						gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						gdi_image_draw_id(
						draw_x,
						draw_y - 10,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						gdi_image_draw_id(draw_x, draw_y + 12, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
						draw_x += tile_width;
						i = i + 5;  /* pass the gun tile ,to the next wall */
					}
                }
                else
                {
                    if (user_ptr->id == COM_1)
					{
						gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						gdi_image_draw_id(
							draw_x,
							draw_y - (shift_x * 5),
							(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						draw_x += tile_width;
						i += 5;
					}
					else
					{
						gdi_image_draw_id(draw_x, draw_y - 5, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
						gdi_image_draw_id(
							draw_x,
							draw_y - 13,
							(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						gdi_image_draw_id(draw_x, draw_y + 9, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
						draw_x += tile_width;
						gdi_image_draw_id(draw_x, draw_y - 5, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i + 1]->id));
						gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
						draw_x += tile_width;
						i += 5;
					}
                }
                break;

            default:
				if (user_ptr->id == COM_1)
				{
					gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i]->id));
				}
				else
				{
					gdi_image_draw_id(draw_x, draw_y - 5, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->lock[i]->id));
					gdi_image_draw_id(draw_x, draw_y + 17, IMG_ID_GX_VSMJ_BOTTOM_SOLID);
				}
                draw_x += tile_width;
                i++;
                break;
        }
    }
    /* draw lock */

    /* draw own */
    if (user_ptr->id == COM_1)
    {
        draw_x = USER_OWN_POS_X[user_ptr->id] - shift_x_count;
        /* draw_y=USER_OWN_POS_Y[user_ptr->id]; */
    }

    user_ptr->start_pos_x = draw_x;
    /* user_ptr->start_pos_y = draw_y; */

    if (user_ptr->id == current_user->id)
        if (game_move != MOVE_DISCARD_CHECK_START && game_move != MOVE_DISCARD_CHECK_CONTINUE)
            if (highlight->id != WALL_END)
            {
                highlight_is_skipped = FALSE;
            }

    if (user_ptr->id == PLAYER_1 || game_move == MOVE_DECLARE_HOU)
    {
		if(user_ptr->id != PLAYER_1 && game_move == MOVE_DECLARE_HOU)
		{
			j = 0;
			while (user_ptr->hand[j]->id != WALL_END)
			{
				if (highlight_is_skipped)
				{
					gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->hand[j]->id));
					draw_x += USER_TILE_WIDTH;
					j++;
				}
				else
				{
					if (user_ptr->hand[j]->id == highlight->id)
					{
						/* skip once to pass highlight offset */
						highlight_is_skipped = TRUE;
						j++;
					}
					else
					{
						gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->hand[j]->id));
						draw_x += USER_TILE_WIDTH;
						j++;
					}
				}
			}
		}
		else
		{
			j = 0;
			while (user_ptr->hand[j]->id != WALL_END)
			{
				if (highlight_is_skipped)
				{
					gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->hand[j]->id));
					gdi_image_draw_id(draw_x, draw_y - 4, IMG_ID_GX_VSMJ_TOP_SOLID);

					if (highlight_tile_index == j)
					{
						gdi_image_draw_id(draw_x + 3, draw_y - 19, IMG_ID_GX_VSMJ_ARROWHEAD);
					}
					draw_x += USER_TILE_WIDTH;
					j++;
				}
				else
				{
					if (user_ptr->hand[j]->id == highlight->id)
					{
						/* skip once to pass highlight offset */
						highlight_is_skipped = TRUE;
						j++;
					}
					else
					{
						gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + user_ptr->hand[j]->id));
						gdi_image_draw_id(draw_x, draw_y - 4, IMG_ID_GX_VSMJ_TOP_SOLID);
						if (highlight_tile_index == j)
						{
							gdi_image_draw_id(draw_x + 3, draw_y - 19, IMG_ID_GX_VSMJ_ARROWHEAD);
						}
						draw_x += USER_TILE_WIDTH;
						j++;
					}
				}
			}
		}
    }
    else
    {
        j = 0;
        while (user_ptr->hand[j]->id != WALL_END)
        {
            if (highlight_is_skipped)
            {
                /* gdi_image_draw_id(draw_x,draw_y,IMG_ID_GX_VSMJ_BRICK_USER_UP_BACK); */
                gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
                draw_x += USER_TILE_WIDTH;
                j++;
            }
            else
            {
                if (user_ptr->hand[j]->id == highlight->id)
                {
                    /* skip once to pass highlight offset */
                    highlight_is_skipped = TRUE;
                    j++;
                }
                else
                {
                    /* gdi_image_draw_id(draw_x,draw_y,IMG_ID_GX_VSMJ_BRICK_USER_UP_BACK); */
                    gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK);
                    draw_x += USER_TILE_WIDTH;
                    j++;
                }
            }
        }
    }
	j = 0;
	while (user_ptr->hand[j] != &wall_end)
	{
		j++;
	}
        user_ptr->hand_left = j;
    /* draw own */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_special_bar
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_special_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 EatCase;
    S32 GunCase;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_SPECIAL)
    {
        if (current_user->id == PLAYER_1)
        {
            /* eat base */
			EatCase = 0;

			for (i = 0; i < 3; i++)
			{
				if (current_user->can_eat[i])
				{
					EatCase++;
				}
			}

			if (EatCase > 0)
			{
				if (highlight_special == HIGHLIGHT_EAT)
				{
					gdi_image_draw_id(PLAYER_SPECIAL_POS_X, PLAYER_SPECIAL_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_EAT_HIGHLIGHT);
				}
				else
				{
					gdi_image_draw_id(PLAYER_SPECIAL_POS_X, PLAYER_SPECIAL_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_EAT_BASE);
				}

				gdi_image_draw_id(PLAYER_SPECIAL_POS_X - 17, 
					PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT, 
					IMG_ID_GX_VSMJ_EATCASE_BG1);

				for (i = 1; i < EatCase * 6; i++)
				{
					gdi_image_draw_id(PLAYER_SPECIAL_POS_X - 17, 
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + i * MMI_GX_VSMJ_EATCASE_BG_HEIGHT, 
						IMG_ID_GX_VSMJ_EATCASE_BG2);
				}

				gdi_image_draw_id(PLAYER_SPECIAL_POS_X - 17, 
					PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + EatCase * 6 * MMI_GX_VSMJ_EATCASE_BG_HEIGHT, 
					IMG_ID_GX_VSMJ_EATCASE_BG3);
				

				EatCase = 0;
				/* eat 0~2 */
				if (current_user->can_eat[0])
				{
					EatCase++;
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id - 2));
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + USER_TILE_WIDTH - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id - 1));
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + 2 * USER_TILE_WIDTH - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id));
					if (highlight_eatcase == HIGHLIGHT_EATCASE_0)
					{
						gdi_image_draw_id(PLAYER_SPECIAL_POS_X - 14,
							PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT - 2,
							IMG_ID_GX_VSMJ_EATCASE_HIGHLIGHT);
					}
				}
				if (current_user->can_eat[1])
				{
					EatCase++;
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id - 1));
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + USER_TILE_WIDTH - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id));
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + 2 * USER_TILE_WIDTH - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id + 1));	
					if (highlight_eatcase == HIGHLIGHT_EATCASE_1)
					{
						gdi_image_draw_id(PLAYER_SPECIAL_POS_X - 14,
							PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT - 2,
							IMG_ID_GX_VSMJ_EATCASE_HIGHLIGHT);
					}
				}
				if (current_user->can_eat[2])
				{
					EatCase++;
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id));
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + USER_TILE_WIDTH - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id + 1));
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + 2 * USER_TILE_WIDTH - 12,
						PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT,
						(U16) (IMG_ID_GX_VSMJ_BRICK_EAST + highlight->id + 2));	
					if (highlight_eatcase == HIGHLIGHT_EATCASE_2)
					{
						gdi_image_draw_id(PLAYER_SPECIAL_POS_X - 14,
							PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((EatCase - 1) * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT - 2,
							IMG_ID_GX_VSMJ_EATCASE_HIGHLIGHT);
					}
				}
			}
			else
			{
				gdi_image_draw_id(PLAYER_SPECIAL_POS_X, PLAYER_SPECIAL_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_EAT_INVALID);
			}
            /* pon */
			if (current_user->can_pon)
			{
				if (highlight_special == HIGHLIGHT_PON)
				{
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + PLAYER_SPECIAL_UNIT_WIDTH,
						PLAYER_SPECIAL_POS_Y,
						IMG_ID_GX_VSMJ_SPECIAL_PON_HIGHLIGHT);
				}
				else
				{
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + PLAYER_SPECIAL_UNIT_WIDTH,
						PLAYER_SPECIAL_POS_Y,
						IMG_ID_GX_VSMJ_SPECIAL_PON_BASE);
				}
			}
			else
			{
				gdi_image_draw_id(
					PLAYER_SPECIAL_POS_X + PLAYER_SPECIAL_UNIT_WIDTH,
					PLAYER_SPECIAL_POS_Y,
					IMG_ID_GX_VSMJ_SPECIAL_PON_INVALID);
			}

            /* gun base */
            GunCase = 0;
            
            for (i = 0; i < 4; i++)
            {
                if (current_user->can_bugun[i])
                {
                    GunCase++;
                }
                if (current_user->can_handgun[i])
                {
                    GunCase++;
                }
            }
            if (GunCase > 0)
            {
                if (highlight_special == HIGHLIGHT_GUN)
                {
                    gdi_image_draw_id(
                        PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH,
                        PLAYER_SPECIAL_POS_Y,
                        IMG_ID_GX_VSMJ_SPECIAL_GUN_HIGHLIGHT);
                }
                else
                {
                    gdi_image_draw_id(
                        PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH,
                        PLAYER_SPECIAL_POS_Y,
                        IMG_ID_GX_VSMJ_SPECIAL_GUN_BASE);
                }

                gdi_image_draw_id(PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 12, 
                    PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT, 
                    IMG_ID_GX_VSMJ_GUNCASE_BG1);
                
                for (i = 1; i < GunCase * 6; i++)
                {
                    gdi_image_draw_id(PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 12, 
                        PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + i * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT, 
                        IMG_ID_GX_VSMJ_GUNCASE_BG2);
                }
                
                gdi_image_draw_id(PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 12, 
                    PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + GunCase * 6 * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT, 
                    IMG_ID_GX_VSMJ_GUNCASE_BG3);

                GunCase = 0;
                for (i = 0; i < 4; i++)
                {
                    if (current_user->can_bugun[i])
                    {
                        GunCase++;
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->bugun_id[i]));
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7 + USER_TILE_WIDTH,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->bugun_id[i]));
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7 + 2 * USER_TILE_WIDTH,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->bugun_id[i]));
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7 + 3 * USER_TILE_WIDTH,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->bugun_id[i]));
                        if (highlight_guncase == HIGHLIGHT_GUNCASE_0 + i)
                        {
                            gdi_image_draw_id(PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 9,
                                PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT - 2,
                                IMG_ID_GX_VSMJ_GUNCASE_HIGHLIGHT);
                        }                  
                    }
                }
                for (i = 0; i < 4; i++)
                {
                    if (current_user->can_handgun[i])
                    {
                        GunCase++;
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->handgun_id[i]));
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7 + USER_TILE_WIDTH,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->handgun_id[i]));
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7 + 2 * USER_TILE_WIDTH,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->handgun_id[i]));
                        gdi_image_draw_id(
                            PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 7 + 3 * USER_TILE_WIDTH,
                            PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT,
                            (U16) (IMG_ID_GX_VSMJ_BRICK_EAST + current_user->handgun_id[i]));
                        if (highlight_guncase == HIGHLIGHT_GUNCASE_4 + i)
                        {
                            gdi_image_draw_id(PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 9,
                                PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + ((GunCase - 1) * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT - 2,
                                IMG_ID_GX_VSMJ_GUNCASE_HIGHLIGHT);
                        }
                    }
                }
			}
			else
			{
				gdi_image_draw_id(
					PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH,
					PLAYER_SPECIAL_POS_Y,
					IMG_ID_GX_VSMJ_SPECIAL_GUN_INVALID);
			}
            /* hou */
			if (current_user->can_hou)
			{
				if (highlight_special == HIGHLIGHT_HOU)
				{
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + 3 * PLAYER_SPECIAL_UNIT_WIDTH,
						PLAYER_SPECIAL_POS_Y,
						IMG_ID_GX_VSMJ_SPECIAL_HOU_HIGHLIGHT);
				}
				else
				{
					gdi_image_draw_id(
						PLAYER_SPECIAL_POS_X + 3 * PLAYER_SPECIAL_UNIT_WIDTH,
						PLAYER_SPECIAL_POS_Y,
						IMG_ID_GX_VSMJ_SPECIAL_HOU_BASE);
				}
			}
			else
			{
				gdi_image_draw_id(
					PLAYER_SPECIAL_POS_X + 3 * PLAYER_SPECIAL_UNIT_WIDTH,
					PLAYER_SPECIAL_POS_Y,
					IMG_ID_GX_VSMJ_SPECIAL_HOU_INVALID);

			}

            /* cancel */
			if (highlight_special == HIGHLIGHT_CANCEL)
			{
				gdi_image_draw_id(
					PLAYER_SPECIAL_POS_X + 4 * PLAYER_SPECIAL_UNIT_WIDTH,
					PLAYER_SPECIAL_POS_Y,
					IMG_ID_GX_VSMJ_SPECIAL_CANCEL_HIGHLIGHT);
			}
			else
			{
				gdi_image_draw_id(
					PLAYER_SPECIAL_POS_X + 4 * PLAYER_SPECIAL_UNIT_WIDTH,
					PLAYER_SPECIAL_POS_Y,
					IMG_ID_GX_VSMJ_SPECIAL_CANCEL_BASE);
			}
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_sign
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_sign(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 dx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sign_delay > 15)
    {
        dx = 0 - 8 * (sign_delay - 16);
    }
    else if (sign_delay < 9)
    {
        dx = 0 - 5 * (9 - sign_delay);
    }

    if (sign_delay != 0)
    {
        switch (sign)
        {
            case SIGN_OFF:
                break;
            case SIGN_EAT:
                gdi_image_draw_id(SIGN_POS_X + dx, SIGN_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_EAT_BASE);
                break;
            case SIGN_PON:
                gdi_image_draw_id(SIGN_POS_X + dx, SIGN_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_PON_BASE);
                break;
            case SIGN_GUN:
                gdi_image_draw_id(SIGN_POS_X + dx, SIGN_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_GUN_BASE);
                break;
            case SIGN_HOU:      /* fix one */
                gdi_image_draw_id(SIGN_POS_X, SIGN_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_HOU_BASE);
                break;
            case SIGN_LIOU_GU:  /* fix one */
                gdi_image_draw_id(SIGN_POS_X, SIGN_POS_Y, IMG_ID_GX_VSMJ_SPECIAL_LIOU_GU);
                break;
        }

        /* sign_delay will -- in framemove */
    }
    else
    {
        sign = SIGN_OFF;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_pen_cursor
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_pen_cursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_user->id == PLAYER_1)
    {
        gdi_image_draw_id(pen_last_x, pen_last_y, IMG_ID_GX_VSMJ_PEN_CURSOR_OFF);
    }
    else
    {
        gdi_image_draw_id(pen_last_x, pen_last_y, IMG_ID_GX_VSMJ_PEN_CURSOR_ON);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_render_scorescreen
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_render_scorescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    S16 draw_y, draw_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*gdi_lcd_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_resize(MMI_GX_VSMJ_LCD_WIDTH, MMI_GX_VSMJ_LCD_HEIGHT);*/

    gdi_draw_solid_rect(0, 0, 240, 320, GDI_COLOR_WHITE);
    /*gdi_draw_frame_rect(
        SCORE_POS_X - SCORE_FRAME,
        SCORE_POS_Y - SCORE_FRAME,
        SCORE_WIDTH,
        SCORE_HEIGHT,
        GDI_COLOR_GREEN,
        GDI_COLOR_GRAY,
        SCORE_FRAME);*/
    gdi_draw_frame_rect(
        SCORE_POS_X,// - SCORE_FRAME,
        SCORE_POS_Y,// - SCORE_FRAME,
        SCORE_HEIGHT,
        SCORE_WIDTH,        
        GDI_COLOR_GREEN,
        GDI_COLOR_GRAY,
        SCORE_FRAME);

	j = 0;
	for (i = 0; i < SCORE_TOTALNUM; i++)
    {
        if (bonus_hou[i])
        {
            j++;
        }
    }

    draw_y = SCORE_POS_Y + 20;
	if (j > 5)
	{
		draw_x = SCORE_POS_X + 20;
	}
	else
	{
		draw_x = (320 - 100) / 2;
	}

    j = 0;
    for (i = 0; i < SCORE_TOTALNUM; i++)
    {
        if (bonus_hou[i])
        {
            gdi_image_draw_id(draw_x, draw_y, (U16) (IMG_ID_GX_VSMJ_SCORE_8_FLOWER + i));
            /* draw text image and tai number all in one */
            draw_y += SCORE_UNIT_HEIGHT;
            j++;
            if (j == 5)
            {
                draw_x = draw_x + 120;
                draw_y = SCORE_POS_Y + 20;
            }

        }
    }

    if (j == 0) /* none special */
    {
        gdi_image_draw_id(draw_x, draw_y, IMG_ID_GX_VSMJ_SCORE_NOTHING);
    }

    /* add draw tai num image code here */
    /* another way:use the gameover screen to show current score at hand : use title "current score" blahblah
       with game grade box showing total score,gameover scr used as a  game set screen */
    /* 0829 : realize upper solution,will need a gameover screen with "current score" title */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_cyclic_timer
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_cyclic_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sign_delay > 0)
    {
        sign_delay--;
    }

    if (game_delay > 0)
    {
        game_delay--;
    }

    if (g_gx_vsmj_context.is_gameover == FALSE)
    {
        if (game_delay == 0)
        {
            mmi_gx_vsmj_framemove();
            mmi_gx_vsmj_render();
        }
    }
    else
    {
        mmi_gx_vsmj_gameover();
        return;
    }
    gui_start_timer(g_gx_vsmj_context.timer_elapse, mmi_gx_vsmj_cyclic_timer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_gx_vsmj_pen_down_hdlr(mmi_pen_point_struct pos)    /* all done */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GAME_VSMJ_320x240__
    S32 tmp;
#endif
    S32 GunCase;
    gx_vsmj_pen_pos_enum GunPos[4];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_GAME_VSMJ_320x240__
    tmp = pos.x;
    pos.x = pos.y;
    pos.y = (MMI_GX_VSMJ_LCD_WIDTH - 1) - tmp;
#endif

    pen_last_x = pos.x;
    pen_last_y = pos.y;

	if (pen_pos == PP_PENNOTDOWN)
	{
		if (highlight != &wall_end && pos.x > USER_HIGHLIGHT_POS_X[current_user->id]
			&& pos.x < USER_HIGHLIGHT_POS_X[current_user->id] + USER_TILE_WIDTH
			&& pos.y > USER_HIGHLIGHT_POS_Y[current_user->id]
			&& pos.y < USER_HIGHLIGHT_POS_Y[current_user->id] + USER_TILE_HEIGHT)
		{
			pen_pos = PP_HIGHLIGHT;
			highlight_tile_index = -1;
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X + PLAYER_SPECIAL_UNIT_WIDTH
				 && pos.x < PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH
				 && pos.y > PLAYER_SPECIAL_POS_Y && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT)
		{
			pen_pos = PP_SPECIAL_PON;
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X + 3 * PLAYER_SPECIAL_UNIT_WIDTH
				 && pos.x < PLAYER_SPECIAL_POS_X + 4 * PLAYER_SPECIAL_UNIT_WIDTH
				 && pos.y > PLAYER_SPECIAL_POS_Y && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT)
		{
			pen_pos = PP_SPECIAL_HOU;
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X + 4 * PLAYER_SPECIAL_UNIT_WIDTH
				 && pos.x < PLAYER_SPECIAL_POS_X + 5 * PLAYER_SPECIAL_UNIT_WIDTH
				 && pos.y > PLAYER_SPECIAL_POS_Y && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT)
		{
			pen_pos = PP_SPECIAL_CANCEL;
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X - 17
				 && pos.x < PLAYER_SPECIAL_POS_X + 3 * USER_TILE_WIDTH - 12
				 && pos.y > PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + MMI_GX_VSMJ_EATCASE_BG_HEIGHT
				 && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + (6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT)
		{
			if (current_user->can_eat[0])
			{
				pen_pos = PP_SPECIAL_EAT_0;
			}
			else if (current_user->can_eat[1])
			{
				pen_pos = PP_SPECIAL_EAT_1;
			}
			else if (current_user->can_eat[2])
			{
				pen_pos = PP_SPECIAL_EAT_2;
			}
			else
			{
				pen_pos = PP_ELSE;
			}
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X - 17
				 && pos.x < PLAYER_SPECIAL_POS_X + 3 * USER_TILE_WIDTH - 12
				 && pos.y > PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + (6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT
				 && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + (2 * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT)
		{
			if (current_user->can_eat[0])
			{
				if (current_user->can_eat[1])
				{
					pen_pos = PP_SPECIAL_EAT_1;
				}
				else if (current_user->can_eat[2])
				{
					pen_pos = PP_SPECIAL_EAT_2;
				}
				else
				{
					pen_pos = PP_ELSE;
				}
			}
			else if (current_user->can_eat[1])
			{
				if (current_user->can_eat[2])
				{
					pen_pos = PP_SPECIAL_EAT_2;
				}
				else
				{
					pen_pos = PP_ELSE;
				}
			}
			else
			{
				pen_pos = PP_ELSE;
			}
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X - 17
				 && pos.x < PLAYER_SPECIAL_POS_X + 3 * USER_TILE_WIDTH - 12
				 && pos.y > PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + (2 * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT
				 && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + (3 * 6 + 1) * MMI_GX_VSMJ_EATCASE_BG_HEIGHT)
		{
			if (current_user->can_eat[0] && current_user->can_eat[1] && current_user->can_eat[2])
			{
				pen_pos = PP_SPECIAL_EAT_2;
			}
			else
			{
				pen_pos = PP_ELSE;
			}
		}
		else if (pos.x > PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH - 12
				 && pos.x < PLAYER_SPECIAL_POS_X + 2 * PLAYER_SPECIAL_UNIT_WIDTH + 4 * USER_TILE_WIDTH - 7
				 && pos.y > PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + MMI_GX_VSMJ_GUNCASE_BG_HEIGHT
				 && pos.y < PLAYER_SPECIAL_POS_Y + PLAYER_SPECIAL_UNIT_HEIGHT + (4 * 6 + 1) * MMI_GX_VSMJ_GUNCASE_BG_HEIGHT)
		{
		    GunCase = 0;
            
                    for (i = 0; i < 4; i++)
		{
                        if (current_user->can_bugun[i])
			{
                            GunPos[GunCase] = PP_SPECIAL_BUGUN_0 + i;
                            GunCase++;
			}
                    }           
                    for (i = 0; i < 4; i++)
                    {
                        if (current_user->can_handgun[i])
                        {
                            GunPos[GunCase] = PP_SPECIAL_HANDGUN_0 + i;
                            GunCase++;
                        }
                    }

                    i = (pos.y - PLAYER_SPECIAL_POS_Y - PLAYER_SPECIAL_UNIT_HEIGHT) / PLAYER_SPECIAL_UNIT_HEIGHT;
                     if (i < GunCase)
			{
				pen_pos = GunPos[i];
			}
		}
		else if (highlight != &wall_end && pos.x > current_user->start_pos_x &&
				 pos.x < current_user->start_pos_x + (current_user->hand_left - 1) * USER_TILE_WIDTH &&
				 pos.y > USER_OWN_POS_Y[current_user->id] && pos.y < USER_OWN_POS_Y[current_user->id] + USER_TILE_HEIGHT)
		{
			pen_pos = (gx_vsmj_pen_pos_enum) (PP_OWN_0 + (pos.x - current_user->start_pos_x) / USER_TILE_WIDTH);
			highlight_tile_index = -1;
		}
		else if (highlight == &wall_end && pos.x > current_user->start_pos_x &&
				 pos.x < current_user->start_pos_x + current_user->hand_left * USER_TILE_WIDTH &&
				 pos.y > USER_OWN_POS_Y[current_user->id] && pos.y < USER_OWN_POS_Y[current_user->id] + USER_TILE_HEIGHT)
		{
			pen_pos = (gx_vsmj_pen_pos_enum) (PP_OWN_0 + (pos.x - current_user->start_pos_x) / USER_TILE_WIDTH);
			highlight_tile_index = -1;
		}
		/*else
		{
			pen_pos = PP_ELSE;
		}*/
	}
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_gx_vsmj_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_debug
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  void
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef _VSMJ_DEBUG_ON_
void mmi_gx_vsmj_debug(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 buf[20];
    S16 buf_USC2[40];
    S32 str_width;
    S32 str_height;
    S16 x = 0;
    S16 y = 0;
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 40; i++)
    {
        y += 12;
        if (i % 10 == 0)
        {
            y = 0;
            x += 30;
        }

        gui_set_font(&MMI_medium_font);

        gui_set_text_color(gui_color(200, 63, 40));
        gui_set_text_border_color(gui_color(0, 0, 0));

        sprintf(buf, "%d", gx_vsmj_debug[i]);
        mmi_asc_to_ucs2(buf_USC2, buf);

        gui_measure_string((UI_string_type) buf_USC2, &str_width, &str_height);
        gui_move_text_cursor(x, y);
        gui_print_bordered_text((UI_string_type) buf_USC2);

    }
}
#endif /* VSMJ_DEBUG_ON */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_find_no_with_tile_id
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  target_id           [IN]        
 *  tile_set_ptr        [?]         
 *  ptr(?)              [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_gx_vsmj_find_no_with_tile_id(gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (tile_set_ptr[i]->id == target_id)
        {
            return i;
        }

        if (tile_set_ptr[i]->id == WALL_END)
        {
            return -1;
        }

        i++;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_insert_tile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tile_target_ptr     [?]     
 *  tile_set_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_insert_tile(gx_vsmj_tile_struct *tile_target_ptr, gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* for later usage, must make highlight one be the first in array relative to other same id tile */
    S16 i;
    gx_vsmj_tile_struct *tile_ptr = tile_target_ptr;    /* so insert wont change highlight's value */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (tile_set_ptr[i]->id == TILE_EMPTY)
        {
            tile_set_ptr[i] = tile_ptr;
            return;
        }
        else if (tile_set_ptr[i]->id == tile_target_ptr->id)
        {
            gx_vsmj_tile_struct *tile_ptr_temp = tile_set_ptr[i];

            tile_set_ptr[i] = tile_ptr;
            tile_ptr = tile_ptr_temp;
        }
        else if (tile_set_ptr[i]->id == WALL_END)   /* didnt find a hole, so put it at the end */
        {
            tile_set_ptr[i] = tile_ptr;
            tile_set_ptr[i + 1] = &wall_end;
            return;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_eliminate_tile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target_id           [IN]        
 *  tile_set_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
/* return true when found one and eliminate it */
/* false when didnt find any */
BOOL mmi_gx_vsmj_eliminate_tile(gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (tile_set_ptr[i]->id != WALL_END)
    {
        if (tile_set_ptr[i]->id == target_id)
        {
            tile_set_ptr[i] = &tile_empty;
            return TRUE;
        }

        i++;
    }

    /* didn't find any */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_sort_tile
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  tile_set_ptr        [?]         
 *  ptr(?)              [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_sort_tile(gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;
    gx_vsmj_tile_struct *tile_temp_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    /* sort order */
    while (tile_set_ptr[i]->id != WALL_END)
    {
        j = 0;
        while (tile_set_ptr[j + 1]->id != WALL_END)
        {
            if (tile_set_ptr[j]->id > tile_set_ptr[j + 1]->id)
            {
                tile_temp_ptr = tile_set_ptr[j];
                tile_set_ptr[j] = tile_set_ptr[j + 1];
                tile_set_ptr[j + 1] = tile_temp_ptr;
            }
            j++;
        }
        i++;
    }

    /* clear empty and move wall back */
    i = 0;
    while (1)
    {
        if (tile_set_ptr[i]->id == TILE_EMPTY)
        {
            tile_set_ptr[i] = &wall_end;
            break;
        }
        else if (tile_set_ptr[i]->id == WALL_END)
        {
            break;;
        }
        i++;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_pick_tile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_pick_tile(gx_vsmj_user_struct *user_ptr)   /* all done */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight = &tile_table[start_index++];
    highlight->pos = POS_HIGH;

    /* clear special hou parameter , player give up so he can come here */
    score_7_1_flower = FALSE;
    score_8_flower = FALSE;
    score_last_by_own = TRUE;
    /*score_hou_by_replenish = FALSE;*/
    /* clear special hou parameter ,player give up so he can come here */

    if (highlight->id < FL_SPRING)
    {
        mmi_gx_vsmj_insert_tile(highlight, user_ptr->hand);
        mmi_gx_vsmj_sort_tile(user_ptr->hand);

        game_move = MOVE_PICK_CHECK;
    }
    else
    {
        mmi_gx_vsmj_insert_tile(highlight, user_ptr->flower);
        highlight = &wall_end;        
		/* flower has its stack order, no need to sort,and simple insert wont make any empty block */
		game_move = MOVE_REPLENISH_TILE;

        if (end_index - start_index + gun_times < 16 + 16)
        {
            /* pop out liou gu sign for some ticks and gameover */
            sign = SIGN_LIOU_GU;
            game_delay = 20;
            sign_delay = 20;
            game_move = MOVE_LIOU_GU;
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_replenish_tile
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_replenish_tile(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    highlight = &tile_table[end_index--];
    highlight->pos = POS_HIGH;

    /* clear special hou parameter , player give up so he can come here */
    score_7_1_flower = FALSE;
    score_8_flower = FALSE;
    score_last_by_own = TRUE;
    /*score_hou_by_replenish = FALSE;*/
    /* clear special hou parameter ,player give up so he can come here */

    if (highlight->id < FL_SPRING)
    {
        mmi_gx_vsmj_insert_tile(highlight, user_ptr->hand);
        mmi_gx_vsmj_sort_tile(user_ptr->hand);

        game_move = MOVE_PICK_CHECK;
    }
    else
    {
        mmi_gx_vsmj_insert_tile(highlight, user_ptr->flower);
        highlight = &wall_end;
        /* flower has its stack order, no need to sort,and simple insert wont make any empty block */
        game_move = MOVE_REPLENISH_TILE;

        if (end_index - start_index + gun_times < 16 + 16)
        {
            /* pop out liou gu sign for some ticks and gameover */
            sign = SIGN_LIOU_GU;
            game_delay = 20;
            sign_delay = 20;
            game_move = MOVE_LIOU_GU;
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_discard_tile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  target_id       [IN]        
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_discard_tile(gx_vsmj_tile_id_enum target_id, gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear special hou parameter , player give up so he can come here */
    score_7_1_flower = FALSE;
    score_8_flower = FALSE;
    score_hou_by_replenish = FALSE;
    score_last_by_own = FALSE;
    /* clear special hou parameter ,player give up so he can come here */

    highlight = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(target_id, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(target_id, user_ptr->hand);
    mmi_gx_vsmj_sort_tile(user_ptr->hand);

    last_user = user_ptr;
    game_move = MOVE_DISCARD_CHECK_START;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_handgun
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  target_id       [IN]        
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_handgun(gx_vsmj_tile_id_enum target_id, gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    score_hou_by_replenish = TRUE;
    
    gun_times++;    /* count total gun_times for liou_gu */

    i = mmi_gx_vsmj_find_no_with_tile_id(WALL_END, user_ptr->lock);
    if (game_move == MOVE_DISCARD_SPECIAL)
    {
        user_ptr->lock[i] = &wall_gunshow;
    }
    else if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_TILE)
    {
        user_ptr->lock[i] = &wall_gunhide;
    }

    i++;

    for (j = 0; j < 4; j++)
    {
        user_ptr->lock[i] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(target_id, user_ptr->hand)];
        mmi_gx_vsmj_eliminate_tile(target_id, user_ptr->hand);
        i++;
    }
    user_ptr->lock[i] = &wall_end;

    mmi_gx_vsmj_sort_tile(user_ptr->hand);

    highlight = &wall_end;
    game_move = MOVE_REPLENISH_TILE;

    highlight_tile_index = -1;

    sign_delay = 20;
    sign = SIGN_GUN;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_bugun
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_bugun(gx_vsmj_tile_id_enum target_id, gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    score_hou_by_replenish = TRUE;
    
    gun_times++;

    if (target_id == highlight->id)
    {
        i = mmi_gx_vsmj_find_no_with_tile_id(highlight->id, user_ptr->lock);

        user_ptr->lock[i - 1] = &wall_gunshow;
        user_ptr->lock[i + 3] = highlight;

        mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
        mmi_gx_vsmj_sort_tile(user_ptr->hand);

        highlight = &wall_end;
    }
    else
    {
        i = mmi_gx_vsmj_find_no_with_tile_id(target_id, user_ptr->lock);

        user_ptr->lock[i - 1] = &wall_gunshow;
        user_ptr->lock[i + 3] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(target_id, user_ptr->hand)];

        mmi_gx_vsmj_eliminate_tile(target_id, user_ptr->hand);
        mmi_gx_vsmj_sort_tile(user_ptr->hand);
     }
    game_move = MOVE_REPLENISH_TILE;  

    highlight_tile_index = -1;

    sign_delay = 20;
    sign = SIGN_GUN;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_pon
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_pon(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_gx_vsmj_find_no_with_tile_id(WALL_END, user_ptr->lock);
    user_ptr->lock[i] = &wall_pon;
    user_ptr->lock[i + 1] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(highlight->id, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
    user_ptr->lock[i + 2] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(highlight->id, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
    user_ptr->lock[i + 3] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(highlight->id, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
    user_ptr->lock[i + 4] = &tile_empty;
    user_ptr->lock[i + 5] = &wall_end;

    mmi_gx_vsmj_sort_tile(user_ptr->hand);

    highlight = &wall_end;
    game_move = MOVE_DISCARD_TILE;

	if (current_user->id == PLAYER_1)
    {
        highlight_tile_index = 0;
    }
    else
	{
		highlight_tile_index = -1;
	}

    sign_delay = 20;
    sign = SIGN_PON;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_eat
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  type            [IN]        
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_eat(gx_vsmj_user_struct *user_ptr, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 d1 = 0;
	S16 d2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case 0:
            d1 = -2;
            d2 = -1;
            break;
        case 1:
            d1 = -1;
            d2 = 1;
            break;
        case 2:
            d1 = 1;
            d2 = 2;
            break;
    }

    i = mmi_gx_vsmj_find_no_with_tile_id(WALL_END, user_ptr->lock);

    user_ptr->lock[i] = &wall_eat;
    user_ptr->lock[i + 1] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(highlight->id + d1, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(highlight->id + d1, user_ptr->hand);
    user_ptr->lock[i + 2] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(highlight->id, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
    user_ptr->lock[i + 3] = user_ptr->hand[mmi_gx_vsmj_find_no_with_tile_id(highlight->id + d2, user_ptr->hand)];
    mmi_gx_vsmj_eliminate_tile(highlight->id + d2, user_ptr->hand);
    user_ptr->lock[i + 4] = &tile_empty;
    user_ptr->lock[i + 5] = &wall_end;

    mmi_gx_vsmj_sort_tile(user_ptr->hand);

    highlight = &wall_end;
    game_move = MOVE_DISCARD_TILE;

	if (current_user->id == PLAYER_1)
    {
        highlight_tile_index = 0;
    }
    else
	{
		highlight_tile_index = -1;
	} 

    sign_delay = 20;
    sign = SIGN_EAT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_hou
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  user_ptr        [?]         
 *  ptr(?)          [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_hou(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gx_vsmj_tile_struct tile_set[18];
    gx_vsmj_tile_struct *tile_set_ptr[18];
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize */
    i = 0;
    while (user_ptr->hand[i]->id != WALL_END)
    {
        tile_set_ptr[i] = &tile_set[i];
        tile_set[i].id = user_ptr->hand[i]->id;
        tile_set[i].pos = CHK_NOTUSED;
        i++;
    }
    tile_set[i].id = WALL_END;
    tile_set[i].pos = CHK_END;
    tile_set_ptr[i] = &tile_set[i];
    /* initialize */

    return mmi_gx_vsmj_hou_trial(tile_set_ptr, FALSE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_eat
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  user_ptr        [?]         
 *  type            [IN]        
 *  ptr(?)          [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_eat(gx_vsmj_user_struct *user_ptr, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 d1 = 0;
	S16 d2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* skip loop for never work case */
    if (highlight->id <= TE_BAI)
    {
        return FALSE;
    }
    /* skip loop for never work case */

    switch (type)
    {
        case 0: /* xxo */
            /* skip loop for never work case */
            switch (highlight->id)
            {
                case NU_1S:
                case NU_2S:
                case NU_1T:
                case NU_2T:
                case NU_1W:
                case NU_2W:
                    return FALSE;
                    break;
            }
            /* skip loop for never work case */
            d1 = -2;
            d2 = -1;
            break;

        case 1: /* xox */
            /* skip loop for never work case */
            switch (highlight->id)
            {
                case NU_1S:
                case NU_9S:
                case NU_1T:
                case NU_9T:
                case NU_1W:
                case NU_9W:
                    user_ptr->can_eat[1] = FALSE;
                    return FALSE;
                    break;
            }
            /* skip loop for never work case */
            d1 = -1;
            d2 = 1;
            break;

        case 2: /* oxx */
            /* skip loop for never work case */
            switch (highlight->id)
            {
                case NU_8S:
                case NU_9S:
                case NU_8T:
                case NU_9T:
                case NU_8W:
                case NU_9W:
                    user_ptr->can_eat[2] = FALSE;
                    return FALSE;
                    break;
            }
            /* skip loop for never work case */
            d1 = 1;
            d2 = 2;
            break;
    }

    if (mmi_gx_vsmj_find_no_with_tile_id(highlight->id + d1, user_ptr->hand) != -1)
        if (mmi_gx_vsmj_find_no_with_tile_id(highlight->id + d2, user_ptr->hand) != -1)
        {
            return TRUE;
        }

    /* fail */
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_pon
 * DESCRIPTION
 *  check pon
 * PARAMETERS
 *  user_ptr        [?]         
 *  ptr(?)          [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_pon(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 num_found = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (user_ptr->hand[i]->id != WALL_END)
    {
        if (user_ptr->hand[i]->id == highlight->id)
        {
            num_found++;
        }
        i++;
    }

    if (num_found >= 3) /* have 2 in hand already and include the one from highlight */
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_bugun
 * DESCRIPTION
 *  check gun
 * PARAMETERS
 *  user_ptr        [?]         
 *  ptr(?)          [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_bugun(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S32 GunCase = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (current_user->id == user_ptr->id)
    {
        for (i = 0; i < 26; i++)
        {
            if (user_ptr->lock[i]->id == WALL_END)
            {
                break;
            }
            if (user_ptr->lock[i]->id == WALL_PON)
            {
                if (-1 != mmi_gx_vsmj_find_no_with_tile_id(user_ptr->lock[i + 1]->id, user_ptr->hand))
                {
                    user_ptr->can_bugun[GunCase] = TRUE;
                    user_ptr->bugun_id[GunCase] = user_ptr->lock[i + 1]->id;
                    GunCase++;
                }
            }
        }
    }
    else
    {
        if (highlight->id != WALL_END)
        {
            i = mmi_gx_vsmj_find_no_with_tile_id(highlight->id, user_ptr->lock);    /* no of first tile with highlight id */
            if (i != -1)    /* tile exist */
            {
                if (user_ptr->lock[i + 1]->id == highlight->id)
                {
                    if (user_ptr->lock[i + 2]->id == highlight->id)
                    {
                        user_ptr->can_bugun[GunCase] = TRUE;
                        user_ptr->bugun_id[GunCase] = highlight->id;
                        GunCase++;
                    }
                }
            }
        }
    }
    
    if (GunCase > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_handgun
 * DESCRIPTION
 *  check gun
 * PARAMETERS
 *  user_ptr        [?]         
 *  ptr(?)          [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_handgun(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* all in hand cases */
    S16 i;
    gx_vsmj_tile_id_enum temp_tile_id;
    U8 num_found_set = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (user_ptr->hand[i]->id != WALL_END)
    {
        user_ptr->hand[i]->pos = CHK_NOTUSED;
        i++;
    }

    for (temp_tile_id = TE_EAST; temp_tile_id <= NU_9T; temp_tile_id++)
    {
        if (mmi_gx_vsmj_check_multi(4, temp_tile_id, user_ptr->hand))
        {
            if (current_user->id == user_ptr->id || temp_tile_id == highlight->id) /*when others user discard, can't hide gun*/
            {
                user_ptr->can_handgun[num_found_set] = TRUE;
                user_ptr->handgun_id[num_found_set] = temp_tile_id;
                num_found_set++;
            }
        }
    }

    if (num_found_set > 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_multi
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  multi_time          [IN]        
 *  target_id           [IN]        
 *  tile_set_ptr        [?]         
 *  ptr(?)              [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_multi(U8 multi_time, gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 temp_multi_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (tile_set_ptr[i]->id != WALL_END)
    {
        if (tile_set_ptr[i]->id == target_id)
            if (tile_set_ptr[i]->pos == CHK_NOTUSED)
            {
                temp_multi_time++;

                if (temp_multi_time == multi_time)
                {
                    return TRUE;
                }
            }
        i++;
    }

    /* didnt' get in return true=>fail */
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_link
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  link_time           [IN]        
 *  target_id           [IN]        
 *  tile_set_ptr        [?]         
 *  ptr(?)              [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_check_link(U8 link_time, gx_vsmj_tile_id_enum target_id, gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* basically for 2 and 3 node link check only */
    S16 i;
    U8 num_link_found = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* skip loop for never work case */
    if (target_id >= TE_EAST && target_id <= TE_BAI)
    {
        return FALSE;
    }
    if (target_id == NU_9S || target_id == NU_9W || target_id == NU_9T)
    {
        return FALSE;
    }

    if (link_time == 3)
        if (target_id == NU_8S || target_id == NU_8W || target_id == NU_8T)
        {
            return FALSE;
        }
    /* skip loop for never work case */

    i = 0;
    while (tile_set_ptr[i]->id != WALL_END)
    {
        if (tile_set_ptr[i]->id == target_id + num_link_found)
            if (tile_set_ptr[i]->pos == CHK_NOTUSED)
            {
                num_link_found++;
                if (num_link_found == link_time)
                {
                    return TRUE;
                }
            }
        i++;
    }

    /* didnt get in return true =>fail */
    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_framemove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    gx_vsmj_user_id_enum target_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (game_move)
    {
    case MOVE_DISCARD_CHECK_START:
        
        /* check special move possibility */
        for (i = 0; i < NUM_PLAYER; i++)
        {
            /* reset */
            user[i].can_hou = FALSE;
            user[i].can_bugun[0] = FALSE;
            user[i].can_bugun[1] = FALSE;
            user[i].can_bugun[2] = FALSE;
            user[i].can_bugun[3] = FALSE;
            user[i].can_handgun[0] = FALSE;
            user[i].can_handgun[1] = FALSE;
            user[i].can_handgun[2] = FALSE;
            user[i].can_handgun[3] = FALSE;
            user[i].can_pon = FALSE;
            user[i].can_eat[0] = FALSE;
            user[i].can_eat[1] = FALSE;
            user[i].can_eat[2] = FALSE;
            /* reset */
            
            if (user[i].id != last_user->id)    /* not the one just discarded highlight tile */
            {
                /* initialize */
                mmi_gx_vsmj_insert_tile(highlight, user[i].hand);
                mmi_gx_vsmj_sort_tile(user[i].hand);
                /* initialize */
                
                /* check if the next player can eat */
                if (user[i].id == last_user->id + 1 || (user[i].id == 0 && last_user->id == NUM_PLAYER - 1))
                {
                    user[i].can_eat[0] = mmi_gx_vsmj_check_eat(&user[i], 0);
                    user[i].can_eat[1] = mmi_gx_vsmj_check_eat(&user[i], 1);
                    user[i].can_eat[2] = mmi_gx_vsmj_check_eat(&user[i], 2);
                }
                
                user[i].can_hou = mmi_gx_vsmj_check_hou(&user[i]);
                user[i].can_pon = mmi_gx_vsmj_check_pon(&user[i]);
                mmi_gx_vsmj_check_handgun(&user[i]);
                
                /* move temp highlight out */
                mmi_gx_vsmj_eliminate_tile(highlight->id, user[i].hand);
                mmi_gx_vsmj_sort_tile(user[i].hand);
                /* move temp highlight out */
            }
            else
            {
                user[i].can_hou = FALSE;
                user[i].can_bugun[0] = FALSE;
                user[i].can_bugun[1] = FALSE;
                user[i].can_bugun[2] = FALSE;
                user[i].can_bugun[3] = FALSE;
                user[i].can_handgun[0] = FALSE;
                user[i].can_handgun[1] = FALSE;
                user[i].can_handgun[2] = FALSE;
                user[i].can_handgun[3] = FALSE;
                user[i].can_pon = FALSE;
                user[i].can_eat[0] = FALSE;
                user[i].can_eat[1] = FALSE;
                user[i].can_eat[2] = FALSE;
            }
        }
        game_move = MOVE_DISCARD_CHECK_CONTINUE;
        break;
        
    case MOVE_DISCARD_CHECK_CONTINUE:
        target_id = last_user->id;
        for (i = 0; i < NUM_PLAYER; i++)
        {
            if (user[i].can_hou)
            {
                target_id = user[i].id;
            }
        }
        for (i = 0; i < NUM_PLAYER; i++)
        {
            if (user[i].can_pon || user[i].can_handgun[0])
            {
                target_id = user[i].id;
            }
        }
        for (i = 0; i < NUM_PLAYER; i++)
        {
            if (user[i].can_eat[0] || user[i].can_eat[1] || user[i].can_eat[2])
            {
                target_id = user[i].id;
            }
        }
        
        if (target_id != last_user->id) /* someone else have a special move to choice */
        {
            mmi_gx_vsmj_insert_tile(highlight, user[target_id].hand);
            mmi_gx_vsmj_sort_tile(user[target_id].hand);
            
            current_user = &user[target_id];
            game_move = MOVE_DISCARD_SPECIAL;
            
            if (current_user->can_eat[0])
            {
                highlight_eatcase = HIGHLIGHT_EATCASE_0;
            }
            else if (current_user->can_eat[1])
            {
                highlight_eatcase = HIGHLIGHT_EATCASE_1;
            }
            else
            {
                highlight_eatcase = HIGHLIGHT_EATCASE_2;
            }
            
            i = 0;
            while (i < 8)
            {
                if (i < 4) 
                {
                    if (current_user->can_bugun[i])
                    {
                        highlight_guncase = HIGHLIGHT_GUNCASE_0 + i;
                        i = 8;
                    }
                }
                else
                {
                    if (current_user->can_handgun[i - 4])
                    {
                        highlight_guncase = HIGHLIGHT_GUNCASE_0 + i;
                        i = 8;
                    }
                }
                i++;
            }
            
            if (current_user->can_hou)
            {
                highlight_special = HIGHLIGHT_HOU;
            }
            else if (current_user->can_eat[0] || current_user->can_eat[1] || current_user->can_eat[2])
            {
                highlight_special = HIGHLIGHT_EAT;
            }
            else if (current_user->can_pon)
            {
                highlight_special = HIGHLIGHT_PON;
            }
            else
            {
                highlight_special = HIGHLIGHT_GUN;
            }
        }
        else
        {
            /* drop to grave */
            highlight->pos = POS_GRAVE;
            grave[grave_index++] = highlight;
            highlight = &wall_end;
            /* drop to grave */
            
            if (last_user->id != NUM_PLAYER - 1)
            {
                target_id = last_user->id + 1;
            }
            else
            {
                target_id = 0;
            }
            
            current_user = &user[target_id];
            game_move = MOVE_PICK_TILE;
            if (end_index - start_index + gun_times < 16 + 16)
            {
                /* pop out liou gu sign for some ticks and gameover */
                sign = SIGN_LIOU_GU;
                game_delay = 20;
                sign_delay = 20;
                game_move = MOVE_LIOU_GU;
                return;
            }
        }
        break;
        
            case MOVE_DECLARE_HOU:
                game_delay = 20;
                game_move = MOVE_RESULT;
                mmi_gx_vsmj_count_score(current_user);
                break;
                
            case MOVE_RESULT:
                g_gx_vsmj_context.is_gameover = TRUE;
                break;
                
            case MOVE_LIOU_GU:
                g_gx_vsmj_context.is_gameover = TRUE;
                break;
                
            default:
                if (current_user->id == PLAYER_1)
                {
                    mmi_gx_vsmj_player_move(current_user);
                }
                else    /* computer move */
                {
                    mmi_gx_vsmj_com_move(current_user);
                }
                break;
        }
        pen_pos = PP_PENNOTDOWN;
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_player_move
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_player_move(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 choice;
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (game_move)
    {
    case MOVE_PICK_TILE:                                /* full done */
                                                        /*switch (pen_pos)
                                                        {
                                                        case PP_PENNOTDOWN:
                                                        break;
    default:*/
        mmi_gx_vsmj_pick_tile(user_ptr);
        /*break;
    }*/
        break;
        
    case MOVE_PICK_CHECK:   /* full done */
        user_ptr->can_pon = FALSE;
        user_ptr->can_bugun[0] = FALSE;
        user_ptr->can_bugun[1] = FALSE;
        user_ptr->can_bugun[2] = FALSE;
        user_ptr->can_bugun[3] = FALSE;
        user_ptr->can_hou = FALSE;
        user_ptr->can_eat[0] = FALSE;
        user_ptr->can_eat[1] = FALSE;
        user_ptr->can_eat[2] = FALSE;
        user_ptr->can_handgun[0] = FALSE;
        user_ptr->can_handgun[1] = FALSE;
        user_ptr->can_handgun[2] = FALSE;
        user_ptr->can_handgun[3] = FALSE;
        
        user_ptr->can_hou = mmi_gx_vsmj_check_hou(user_ptr);
        mmi_gx_vsmj_check_bugun(user_ptr);
        mmi_gx_vsmj_check_handgun(user_ptr);
        
        if (user_ptr->can_hou || user_ptr->can_handgun[0] || user_ptr->can_bugun[0])
        {
            game_move = MOVE_PICK_SPECIAL;
            
            i = 0;
            while (i < 8)
            {
                if (i < 4) 
                {
                    if (user_ptr->can_bugun[i])
                    {
                        highlight_guncase = HIGHLIGHT_GUNCASE_0 + i;
                        i = 8;
                    }
                }
                else 
                {
                    if (user_ptr->can_handgun[i - 4])
                    {
                        highlight_guncase = HIGHLIGHT_GUNCASE_0 + i;
                        i = 8;
                    }
                }
                i++;
            }
            if (user_ptr->can_hou)
            {
                highlight_special = HIGHLIGHT_HOU;
            }
            else
            {
                highlight_special = HIGHLIGHT_GUN;
            }
        }
        else
        {
            game_move = MOVE_DISCARD_TILE;
            
            if (highlight != &wall_end)
            {
                highlight_tile_index = mmi_gx_vsmj_get_highlight_tile_index();
            }
            else
            {
                highlight_tile_index = 0;
            }
        }
        
        break;
        
    case MOVE_PICK_SPECIAL: /* full done */
        switch (pen_pos)
        {
        case PP_SPECIAL_HOU:
            if (user_ptr->can_hou)
            {
                mmi_gx_vsmj_declare_hou(user_ptr);
            }
            break;
            
        case PP_SPECIAL_BUGUN_0:
            if (user_ptr->can_bugun[0])
            {
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[0], user_ptr);
            }
            break;
        case PP_SPECIAL_BUGUN_1:
            if (user_ptr->can_bugun[1])
            {
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[1], user_ptr);
            }
            break;
        case PP_SPECIAL_BUGUN_2:
            if (user_ptr->can_bugun[2])
            {
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[2], user_ptr);
            }
            break;
        case PP_SPECIAL_BUGUN_3:
            if (user_ptr->can_bugun[3])
            {
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[3], user_ptr);
            }
            break;
        case PP_SPECIAL_HANDGUN_0:
            if (user_ptr->can_handgun[0])
            {
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
            }
            break;
        case PP_SPECIAL_HANDGUN_1:
            if (user_ptr->can_handgun[1])
            {
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
            }
            break;
        case PP_SPECIAL_HANDGUN_2:
            if (user_ptr->can_handgun[2])
            {
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
            }
            break;
        case PP_SPECIAL_HANDGUN_3:
            if (user_ptr->can_handgun[3])
            {
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
            }
            break;
        case PP_SPECIAL_CANCEL:
            game_move = MOVE_DISCARD_TILE;
            
            if (highlight != &wall_end)
            {
                highlight_tile_index = mmi_gx_vsmj_get_highlight_tile_index();
            }
            else
            {
                highlight_tile_index = 0;
            }
            break;
            
        default:
            break;
        }
        
        if (game_move != MOVE_PICK_SPECIAL) /* have made a choice so move changed */
        {
            user_ptr->can_pon = FALSE;
            user_ptr->can_bugun[0] = FALSE;
            user_ptr->can_bugun[1] = FALSE;
            user_ptr->can_bugun[2] = FALSE;
            user_ptr->can_bugun[3] = FALSE;
            user_ptr->can_hou = FALSE;
            user_ptr->can_eat[0] = FALSE;
            user_ptr->can_eat[1] = FALSE;
            user_ptr->can_eat[2] = FALSE;
            user_ptr->can_handgun[0] = FALSE;
            user_ptr->can_handgun[1] = FALSE;
            user_ptr->can_handgun[2] = FALSE;
            user_ptr->can_handgun[3] = FALSE;
        }
        break;
        
        case MOVE_REPLENISH_TILE:   /* full done */
                                    /*switch (pen_pos)
                                    {
                                    case PP_PENNOTDOWN:
                                    break;
                                    
        default:*/
            mmi_gx_vsmj_replenish_tile(user_ptr);
            /*break;
                }*/
            break;
            
        case MOVE_DISCARD_TILE: /* full done */
            
            switch (pen_pos)
            {
            case PP_OWN_0:
            case PP_OWN_1:
            case PP_OWN_2:
            case PP_OWN_3:
            case PP_OWN_4:
            case PP_OWN_5:
            case PP_OWN_6:
            case PP_OWN_7:
            case PP_OWN_8:
            case PP_OWN_9:
            case PP_OWN_10:
            case PP_OWN_11:
            case PP_OWN_12:
            case PP_OWN_13:
            case PP_OWN_14:
            case PP_OWN_15:
            case PP_OWN_16:
                choice = pen_pos;
                if (user_ptr->hand[choice]->id >= highlight->id)
                {
                    choice++;   /* skip highlight one */
                }
                
                i = 0;
                while (user_ptr->hand[i]->id != WALL_END)
                {
                    if (i == choice)
                    {
                        mmi_gx_vsmj_discard_tile(user_ptr->hand[choice]->id, user_ptr);
                        break;
                    }
                    i++;
                }
                break;
                
            case PP_HIGHLIGHT:
                if (highlight->id != WALL_END)
                {
                    mmi_gx_vsmj_discard_tile(highlight->id, user_ptr);
                }
                break;
                
            default:
                break;
            }
            break;
            
            case MOVE_DISCARD_SPECIAL:  /* full done */
                switch (pen_pos)
                {
                case PP_SPECIAL_HOU:
                    if (user_ptr->can_hou)
                    {
                        mmi_gx_vsmj_declare_hou(user_ptr);
                    }
                    break;
                    
                case PP_SPECIAL_BUGUN_0:
                    if (user_ptr->can_bugun[0])
                    {
                        mmi_gx_vsmj_bugun(user_ptr->can_bugun[0], user_ptr);
                    }
                    break;
                case PP_SPECIAL_BUGUN_1:
                    if (user_ptr->can_bugun[1])
                    {
                        mmi_gx_vsmj_bugun(user_ptr->can_bugun[1], user_ptr);
                    }
                    break;
                case PP_SPECIAL_BUGUN_2:
                    if (user_ptr->can_bugun[2])
                    {
                        mmi_gx_vsmj_bugun(user_ptr->can_bugun[2], user_ptr);
                    }
                    break;
                case PP_SPECIAL_BUGUN_3:
                    if (user_ptr->can_bugun[3])
                    {
                        mmi_gx_vsmj_bugun(user_ptr->can_bugun[3], user_ptr);
                    }
                    break;
                case PP_SPECIAL_HANDGUN_0:
                    if (user_ptr->can_handgun[0])
                    {
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
                    }
                    break;
                case PP_SPECIAL_HANDGUN_1:
                    if (user_ptr->can_handgun[1])
                    {
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
                    }
                    break;
                case PP_SPECIAL_HANDGUN_2:
                    if (user_ptr->can_handgun[2])
                    {
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
                    }
                    break;
                case PP_SPECIAL_HANDGUN_3:
                    if (user_ptr->can_handgun[3])
                    {
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
                    }
                    break;
                case PP_SPECIAL_PON:
                    if (user_ptr->can_pon)
                    {
                        mmi_gx_vsmj_pon(user_ptr);
                    }
                    break;
                    
                case PP_SPECIAL_EAT_0:
                    if (user_ptr->can_eat[0])
                    {
                        mmi_gx_vsmj_eat(user_ptr, 0);
                    }
                    break;
                case PP_SPECIAL_EAT_1:
                    if (user_ptr->can_eat[1])
                    {
                        mmi_gx_vsmj_eat(user_ptr, 1);
                    }
                    break;
                case PP_SPECIAL_EAT_2:
                    if (user_ptr->can_eat[2])
                    {
                        mmi_gx_vsmj_eat(user_ptr, 2);
                    }
                    break;
                case PP_SPECIAL_CANCEL:
                    /* clean all */
                    user_ptr->can_pon = FALSE;
                    user_ptr->can_bugun[0] = FALSE;
                    user_ptr->can_bugun[1] = FALSE;
                    user_ptr->can_bugun[2] = FALSE;
                    user_ptr->can_bugun[3] = FALSE;
                    user_ptr->can_hou = FALSE;
                    user_ptr->can_eat[0] = FALSE;
                    user_ptr->can_eat[1] = FALSE;
                    user_ptr->can_eat[2] = FALSE;
                    user_ptr->can_handgun[0] = FALSE;
                    user_ptr->can_handgun[1] = FALSE;
                    user_ptr->can_handgun[2] = FALSE;
                    user_ptr->can_handgun[3] = FALSE;
                    
                    /* remove the highlight added for checkment */
                    mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
                    mmi_gx_vsmj_sort_tile(user_ptr->hand);
                    
                    game_move = MOVE_DISCARD_CHECK_CONTINUE;
                    break;
                    
                }
                break;
                
            case MOVE_DECLARE_HOU:  /* shouldn't  come here */
                break;
        }
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_com_move
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_com_move(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (game_move)
    {
        case MOVE_PICK_TILE:    /* full done */
            mmi_gx_vsmj_pick_tile(user_ptr);
            break;

        case MOVE_PICK_CHECK:   /* full done */
            user_ptr->can_pon = FALSE;
            user_ptr->can_bugun[0] = FALSE;
            user_ptr->can_bugun[1] = FALSE;
            user_ptr->can_bugun[2] = FALSE;
            user_ptr->can_bugun[3] = FALSE;
            user_ptr->can_hou = FALSE;
            user_ptr->can_eat[0] = FALSE;
            user_ptr->can_eat[1] = FALSE;
            user_ptr->can_eat[2] = FALSE;
            user_ptr->can_handgun[0] = FALSE;
            user_ptr->can_handgun[1] = FALSE;
            user_ptr->can_handgun[2] = FALSE;
            user_ptr->can_handgun[3] = FALSE;

            mmi_gx_vsmj_check_bugun(user_ptr);
            mmi_gx_vsmj_check_handgun(user_ptr);
            user_ptr->can_hou = mmi_gx_vsmj_check_hou(user_ptr);

            if (user_ptr->can_hou)
            {
                mmi_gx_vsmj_declare_hou(user_ptr);
            }
            else
            {
                game_move = MOVE_DISCARD_TILE;
            }
            break;

        case MOVE_PICK_SPECIAL:
            break;

        case MOVE_REPLENISH_TILE:   /* full done */
            mmi_gx_vsmj_replenish_tile(user_ptr);
            break;

        case MOVE_DISCARD_TILE: /* full done */
            if (com_strategy[user_ptr->id] == COM_STRATEGY_1)
            {
                mmi_gx_vsmj_com_think_st_1(user_ptr);
            }
            else if (com_strategy[user_ptr->id] == COM_STRATEGY_2)
            {
                mmi_gx_vsmj_com_think_st_2(user_ptr);
            }
            break;

        case MOVE_DISCARD_SPECIAL:  /* full done */
            if (user_ptr->can_hou)
            {
                mmi_gx_vsmj_declare_hou(user_ptr);
            }
            else
            {
                if (com_strategy[user_ptr->id] == COM_STRATEGY_1)
                {
                    mmi_gx_vsmj_com_think_st_1(user_ptr);
                }
                else if (com_strategy[user_ptr->id] == COM_STRATEGY_2)
                {
                    mmi_gx_vsmj_com_think_st_2(user_ptr);
                }
            }
            break;

        case MOVE_DECLARE_HOU:
            /* shouldn't  come here */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_declare_hou
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_declare_hou(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    game_move = MOVE_DECLARE_HOU;

    game_delay = 20;
    sign_delay = 20;
    sign = SIGN_HOU;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_count_score
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_count_score(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /* for check hou set */
    /* for check hou set */

    U8 temp_flower[2] = {0, 0};
    U8 temp_3yuang[3] = {0, 0, 0};
    U8 temp_4wind[4] = {0, 0, 0, 0};
    U8 temp_W = 0;
    U8 temp_T = 0;
    U8 temp_S = 0;
    U8 temp_TEXT = 0;
    U8 temp_num_pon_gun_atlock = 0;
    U8 temp_num_pon_gun_athand = 0;
    BOOL temp_link_exist = FALSE;
    S16 temp_score = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SCORE_TOTALNUM; i++)
    {
        bonus_hou[i] = FALSE;
    }
    
    bonus_hou[SCORE_8_FLOWER] = score_8_flower;
    bonus_hou[SCORE_7_1_FLOWER] = score_7_1_flower;
    bonus_hou[SCORE_PICK_BY_OWN] = score_last_by_own;
    bonus_hou[SCORE_PICK_BY_REPLENISH] = score_hou_by_replenish;
    /* men-chin */
    /* only have hide gun at lock */
    i = 0;
    bonus_hou[SCORE_MEN_CHIN] = TRUE;
    while (user_ptr->lock[i]->id != WALL_END)
    {
        if (user_ptr->lock[i]->id == WALL_EAT ||
            user_ptr->lock[i]->id == WALL_PON ||
            user_ptr->lock[i]->id == WALL_GUNSHOW)
        {
            bonus_hou[SCORE_MEN_CHIN] = FALSE;
            break;
        }
        i++;
    }
    
    /* men_chin ze mo */
    if (bonus_hou[SCORE_MEN_CHIN] && bonus_hou[SCORE_PICK_BY_OWN])
    {
        bonus_hou[SCORE_MEN_CHIN] = FALSE;
        bonus_hou[SCORE_PICK_BY_OWN] = FALSE;
        bonus_hou[SCORE_MEN_CHIN_ZE_MO] = TRUE;
    }
    /* men_chin ze mo */
    
    /* flower gun */
    for (i = 0; user_ptr->flower[i]->id != WALL_END; i++)
    {
        if (user_ptr->flower[i]->id >= FL_SPRING && user_ptr->flower[i]->id <= FL_WINTER)
        {
            temp_flower[0]++;
        }
        else if (user_ptr->flower[i]->id >= FL_M && user_ptr->flower[i]->id <= FL_J)
        {
            temp_flower[1]++;
        }
    }
    if (temp_flower[0] == 4)
    {
        bonus_hou[SCORE_FLOWER_SEASON_SET] = TRUE;
    }
    if (temp_flower[1] == 4)
    {
        bonus_hou[SCORE_FLOWER_PLANT_SET] = TRUE;
    }
    /* flower gun */
    
    /* big small 3 yuang, 3-yuang-pai */
    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
    {
        if (user_ptr->hand[i]->id == TE_CHUNG)
        {
            temp_3yuang[0]++;
        }
        else if (user_ptr->hand[i]->id == TE_FA)
        {
            temp_3yuang[1]++;
        }
        else if (user_ptr->hand[i]->id == TE_BAI)
        {
            temp_3yuang[2]++;
        }
    }
    for (i = 0; user_ptr->lock[i]->id != WALL_END; i++)
    {
        if (user_ptr->lock[i]->id == TE_CHUNG)
        {
            temp_3yuang[0]++;
        }
        else if (user_ptr->lock[i]->id == TE_FA)
        {
            temp_3yuang[1]++;
        }
        else if (user_ptr->lock[i]->id == TE_BAI)
        {
            temp_3yuang[2]++;
        }
    }
    
    if (temp_3yuang[0] >= 3 && temp_3yuang[1] >= 3 && temp_3yuang[2] >= 3)
    {
        bonus_hou[SCORE_BIG_3_YUANG] = TRUE;
    }
    else if ((temp_3yuang[0] == 2 && temp_3yuang[1] >= 3 && temp_3yuang[2] >= 3)
        || (temp_3yuang[0] >= 3 && temp_3yuang[1] == 2 && temp_3yuang[2] >= 3)
        || (temp_3yuang[0] >= 3 && temp_3yuang[1] >= 3 && temp_3yuang[2] == 2))
    {
        bonus_hou[SCORE_SMALL_3_YUANG] = TRUE;
    }
    else
    {
        if (temp_3yuang[0] >= 3)
        {
            bonus_hou[SCORE_3_YUANG_CHUNG] = TRUE;
        }
        if (temp_3yuang[1] >= 3)
        {
            bonus_hou[SCORE_3_YUANG_FA] = TRUE;
        }
        if (temp_3yuang[2] >= 3)
        {
            bonus_hou[SCORE_3_YUANG_BAI] = TRUE;
        }
    }
    /* big small 3 yuang , 3-yuang-pai */
    
    /* big small 4 shi */
    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
    {
        if (user_ptr->hand[i]->id == TE_EAST)
        {
            temp_4wind[0]++;
        }
        else if (user_ptr->hand[i]->id == TE_WEST)
        {
            temp_4wind[1]++;
        }
        else if (user_ptr->hand[i]->id == TE_SOUTH)
        {
            temp_4wind[2]++;
        }
        else if (user_ptr->hand[i]->id == TE_NORTH)
        {
            temp_4wind[3]++;
        }
    }
    for (i = 0; user_ptr->lock[i]->id != WALL_END; i++)
    {
        if (user_ptr->lock[i]->id == TE_EAST)
        {
            temp_4wind[0]++;
        }
        else if (user_ptr->lock[i]->id == TE_WEST)
        {
            temp_4wind[1]++;
        }
        else if (user_ptr->lock[i]->id == TE_SOUTH)
        {
            temp_4wind[2]++;
        }
        else if (user_ptr->lock[i]->id == TE_NORTH)
        {
            temp_4wind[3]++;
        }
    }
    if (temp_4wind[0] >= 3 && temp_4wind[1] >= 3 && temp_4wind[2] >= 3 && temp_4wind[3] >= 3)
    {
        bonus_hou[SCORE_BIG_4_WIND] = TRUE;
    }
    else if ((temp_4wind[0] == 2 && temp_4wind[1] >= 3 && temp_4wind[2] >= 3 && temp_4wind[3] >= 3)
        || (temp_4wind[0] >= 3 && temp_4wind[1] == 2 && temp_4wind[2] >= 3 && temp_4wind[3] >= 3)
        || (temp_4wind[0] >= 3 && temp_4wind[1] >= 3 && temp_4wind[2] == 2 && temp_4wind[3] >= 3)
        || (temp_4wind[0] >= 3 && temp_4wind[1] >= 3 && temp_4wind[2] >= 3 && temp_4wind[3] == 2))
    {
        bonus_hou[SCORE_SMALL_4_WIND] = TRUE;
    }
    /* big small 4 shi */
    
    /*
    * else
    * {
    * if (temp_4wind[0]>=3)
    * bonus_hou[SCORE_4_WIND_EAST]=TRUE;
    * if (temp_4wind[1]>=3)
    * bonus_hou[SCORE_4_WIND_WEST]=TRUE;
    * if (temp_4wind[2]>=3)
    * bonus_hou[SCORE_4_WIND_SOUTH]=TRUE;
    * if (temp_4wind[3]>=3)
    * bonus_hou[SCORE_4_WIND_NORTH]=TRUE;
    * }
    */ /* no boarder => nowind score */
    
    /* sea_moon */
    if (end_index - start_index + gun_times == 16)
    {
        if (score_last_by_own)
        {
            bonus_hou[SCORE_SEA_MOON] = TRUE;
        }
    }
    /* sea_moon , sea_fish */
    
    /* chuan chio */
    if (user_ptr->hand[2]->id == WALL_END && score_last_by_own == FALSE)        /* so only 1 hand tile not in lock */
    {
        bonus_hou[SCORE_CHUAN_CHIO] = TRUE; /* rule: cant count together with ze-mo */
    }
    /* chuan chio */
    
    /* the one-color s */
    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
    {
        if (user_ptr->hand[i]->id >= NU_1W && user_ptr->hand[i]->id <= NU_9W)
        {
            temp_W++;
        }
        else if (user_ptr->hand[i]->id >= NU_1T && user_ptr->hand[i]->id <= NU_9T)
        {
            temp_T++;
        }
        else if (user_ptr->hand[i]->id >= NU_1S && user_ptr->hand[i]->id <= NU_9S)
        {
            temp_S++;
        }
        else if (user_ptr->hand[i]->id >= TE_EAST && user_ptr->hand[i]->id <= TE_BAI)
        {
            temp_TEXT++;
        }
    }
    for (i = 0; user_ptr->lock[i]->id != WALL_END; i++)
    {
        if (user_ptr->lock[i]->id >= NU_1W && user_ptr->lock[i]->id <= NU_9W)
        {
            temp_W++;
        }
        else if (user_ptr->lock[i]->id >= NU_1T && user_ptr->lock[i]->id <= NU_9T)
        {
            temp_T++;
        }
        else if (user_ptr->lock[i]->id >= NU_1S && user_ptr->lock[i]->id <= NU_9S)
        {
            temp_S++;
        }
        else if (user_ptr->lock[i]->id >= TE_EAST && user_ptr->lock[i]->id <= TE_BAI)
        {
            temp_TEXT++;
        }
    }
    if (temp_W == 0 && temp_T == 0 && temp_S == 0 && temp_TEXT > 0)
    {
        /* cancel text_1_color , rarely used*/
        /*bonus_hou[SCORE_TEXT_1_COLOR]=TRUE;*/
    }
    else if ((temp_W > 0 && temp_T == 0 && temp_S == 0 && temp_TEXT == 0)
        || (temp_W == 0 && temp_T > 0 && temp_S == 0 && temp_TEXT == 0)
        || (temp_W == 0 && temp_T == 0 && temp_S > 0 && temp_TEXT == 0)
        || (temp_W == 0 && temp_T == 0 && temp_S == 0 && temp_TEXT > 0))
    {
        bonus_hou[SCORE_NUM_1_COLOR] = TRUE;
    }
    else if ((temp_W > 0 && temp_T == 0 && temp_S == 0 && temp_TEXT > 0)
        || (temp_W == 0 && temp_T > 0 && temp_S == 0 && temp_TEXT > 0)
        || (temp_W == 0 && temp_T == 0 && temp_S > 0 && temp_TEXT > 0))
    {
        bonus_hou[SCORE_MIX_1_COLOR] = TRUE;
    }
    /* the one-color s */
    
    /* get hou set info */
    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
    mmi_gx_vsmj_hou_trial(user_ptr->hand, FALSE);
    /* get hou set info */
    
    /* 3,4,5 en ke */
    i = 0;
    while (user_ptr->lock[i]->id != WALL_END)
    {
        if (user_ptr->lock[i]->id == WALL_GUNHIDE)
        {
            temp_num_pon_gun_atlock++;
        }
        i++;
    }
    i = 0;
    j = 0;
    if (score_last_by_own)
    {
        while (user_ptr->hand[i]->id != WALL_END && 
            user_ptr->hand[i + 1]->id != WALL_END &&
            user_ptr->hand[i + 2]->id != WALL_END)
        {
        /*if (user_ptr->hand[i]->pos == CHK_TRIPLE)
        {
				    j++;
        }*/
            if (user_ptr->hand[i]->id == user_ptr->hand[i + 1]->id &&
                user_ptr->hand[i]->id == user_ptr->hand[i + 2]->id &&
                user_ptr->hand[i]->id != user_ptr->hand[i + 3]->id)
            {
                j++;
            }
            i++;
        }
    }
    else
    {
        while (user_ptr->hand[i]->id != WALL_END && 
            user_ptr->hand[i + 1]->id != WALL_END &&
            user_ptr->hand[i + 2]->id != WALL_END)
        {
            if (user_ptr->hand[i]->id != highlight->id)
            {
                if (user_ptr->hand[i]->id == user_ptr->hand[i + 1]->id &&
                    user_ptr->hand[i]->id == user_ptr->hand[i + 2]->id)
                {
                    j++;
                    i = i + 3;
                    if (user_ptr->hand[i]->id == user_ptr->hand[i - 1]->id)
                    {
                        i++;
                    }
                }
                else
                {
                    i++;
                }
            }
            else
            {
                if (user_ptr->hand[i]->id == user_ptr->hand[i + 1]->id &&
                    user_ptr->hand[i]->id == user_ptr->hand[i + 2]->id &&
                    user_ptr->hand[i]->id == user_ptr->hand[i + 3]->id)
                {
                    j++;
                    i = i + 4;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    temp_num_pon_gun_athand = j;/* / 3;*/
    switch (temp_num_pon_gun_athand + temp_num_pon_gun_atlock)
    {
    case 3:
        bonus_hou[SCORE_3_ENKE] = TRUE;
        break;
    case 4:
        bonus_hou[SCORE_4_ENKE] = TRUE;
        break;
    case 5:
        bonus_hou[SCORE_5_ENKE] = TRUE;
        break;
    default:
        break;
    }
    /* 3,4,5 en ke */
    
    /* duei duei hou */
    i = 0;
    while (user_ptr->lock[i]->id != WALL_END)
    {
        if (user_ptr->lock[i]->id == WALL_EAT)
        {
            temp_link_exist = TRUE;
            break;
        }
        i++;
    }
    
    i = 0;
    /*while (user_ptr->hand[i]->id != WALL_END)
    {
    if (user_ptr->hand[i]->pos == CHK_LINE_R)
    {
    temp_link_exist = TRUE;
    break;
    }
    i++;
        }*/
    j = 0;
    while (user_ptr->hand[i]->id != WALL_END && 
        user_ptr->hand[i + 1]->id != WALL_END)
    {
        if (user_ptr->hand[i]->id == user_ptr->hand[i + 1]->id)
        {
            if (user_ptr->hand[i]->id == user_ptr->hand[i + 2]->id)
            {
                i = i + 3;
            }
            else
            {
                if (j == 0)
                {
                    j = 1;
                    i = i + 2;
                }
                else
                {
                    temp_link_exist = TRUE;
                    break;
                }
            }
        }
        else
        {
            temp_link_exist = TRUE;
            break;
        }
    }
    
    if (temp_link_exist == FALSE)
    {
        bonus_hou[SCORE_PAIR_PAIR_HOU] = TRUE;
    }
    /* duei duei hou */
    
    /***********send score*************/
    if (bonus_hou[SCORE_8_FLOWER])
    {
        temp_score += 8;
    }
    if (bonus_hou[SCORE_7_1_FLOWER])
    {
        temp_score += 8;
    }
    
    /* hou by 8_flower and 7_1_flower have no chance of the following bonus */
    if (bonus_hou[SCORE_8_FLOWER] || bonus_hou[SCORE_7_1_FLOWER])
    {
        if (user_ptr->id == PLAYER_1)   /* win */
        {
            g_gx_vsmj_context.game_grade = g_gx_vsmj_context.game_grade + temp_score * 100 + 200;
        }
        else    /* lose */
        {
            g_gx_vsmj_context.game_grade = g_gx_vsmj_context.game_grade - temp_score * 100 - 200;
        }
        return;
        
    }
    
    if (bonus_hou[SCORE_PICK_BY_OWN])
    {
        temp_score += 1;
    }
    
    if (bonus_hou[SCORE_PICK_BY_REPLENISH])
    {
        temp_score += 1;
    }
    
    if (bonus_hou[SCORE_MEN_CHIN])
    {
        temp_score += 1;
    }
    
    if (bonus_hou[SCORE_MEN_CHIN_ZE_MO])
    {
        temp_score += 3;
    }
    
    if (bonus_hou[SCORE_FLOWER_SEASON_SET])
    {
        temp_score += 2;
    }
    
    if (bonus_hou[SCORE_FLOWER_PLANT_SET])
    {
        temp_score += 2;
    }
    
    if (bonus_hou[SCORE_SEA_MOON])
    {
        temp_score += 1;
    }
    /*
    * if (bonus_hou[SCORE_SEA_FISH])
    * temp_score += 1;
    */
    if (bonus_hou[SCORE_CHUAN_CHIO])
    {
        temp_score += 2;
    }
    
    if (bonus_hou[SCORE_BIG_3_YUANG])
    {
        temp_score += 8;
    }
    
    if (bonus_hou[SCORE_SMALL_3_YUANG])
    {
        temp_score += 4;
    }
    
    if (bonus_hou[SCORE_3_YUANG_CHUNG])
    {
        temp_score += 1;
    }
    
    if (bonus_hou[SCORE_3_YUANG_FA])
    {
        temp_score += 1;
    }
    
    if (bonus_hou[SCORE_3_YUANG_BAI])
    {
        temp_score += 1;
    }
    
    if (bonus_hou[SCORE_BIG_4_WIND])
    {
        temp_score += 16;
    }
    
    if (bonus_hou[SCORE_SMALL_4_WIND])
    {
        temp_score += 8;
    }
    
    if (bonus_hou[SCORE_3_ENKE])
    {
        temp_score += 2;
    }
    
    if (bonus_hou[SCORE_4_ENKE])
    {
        temp_score += 5;
    }
    
    if (bonus_hou[SCORE_5_ENKE])
    {
        temp_score += 8;
    }
    
    /*
    * if (bonus_hou[SCORE_TEXT_1_COLOR])
    * temp_score += 8;
    */
    
    if (bonus_hou[SCORE_NUM_1_COLOR])
    {
        temp_score += 8;
    }
    
    if (bonus_hou[SCORE_MIX_1_COLOR])
    {
        temp_score += 4;
    }
    
    if (bonus_hou[SCORE_PAIR_PAIR_HOU])
    {
        temp_score += 1;
    }
    
    if (user_ptr->id == PLAYER_1)   /* win */
    {
        g_gx_vsmj_context.game_grade = g_gx_vsmj_context.game_grade + 200 + temp_score * 100;   /* ©³+score per tai*¥x¼Æ */
    }
    else    /* lose */
    {
        g_gx_vsmj_context.game_grade = g_gx_vsmj_context.game_grade - 200 - temp_score * 100;
    }
    /**********send score*********************/
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_com_think_st_1
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_com_think_st_1(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* let com check hou first,come here if failed to hou */

    S16 ting_num = -1;
    S16 temp_ting_num = 0;
    gx_vsmj_tile_id_enum todrop_tile_id = 0;
    gx_vsmj_tile_id_enum temp_id = 0;
    U8 to_move_type = 0;        /* 0 for original,1 for normal drop, 2 for pon ,3 for eat0,4 for eat1,5 for eat2 ,
                                   6 for bu_gun no.1 , 7 for bu_gun no.1 , 8 for bu_gun no.1 , 9 for bu_gun no.1 ,
                                   10 for gun_inhand no.1 ,11 inhand no.2 , 12 inhand no.3 , 13 inhand no.4 */
    S16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
    
    switch (game_move)
    {
    case MOVE_DISCARD_TILE:
        to_move_type = 1;   /* initialize */
        
        /* think move start */
        /* have normal drop case,handgun case ,bu_gun case case */
        /* bu_gun->handgun->normal drop */
        
        /* bu_gun case */
        for (i = 0; user_ptr->can_bugun[i] == TRUE; i++)
        {
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            
            mmi_gx_vsmj_set_chk(user_ptr->bugun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->bugun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            
            if (temp_ting_num > ting_num)
            {
                ting_num = temp_ting_num;
                to_move_type = 6 + i;
                todrop_tile_id = temp_id;
            }
        }
        /* bu_gun case */
        
        /* actually same with normal drop's drop_highlight case,so check bugun first will keep bu_gun
        if no other way have a better ting num,then com get one more chance to pick tile 
        with highest hou chance */
        
        /* handgun case */
        for (i = 0; user_ptr->can_handgun[i] == TRUE; i++)
        {
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            
            if (temp_ting_num > ting_num)
            {
                ting_num = temp_ting_num;
                to_move_type = 10 + i;   /* 10 for handgun0,11 for 1,12 for 2, 13 for 3 */
                todrop_tile_id = temp_id;
            }
        }
        /* handgun case */
        
        /* normal drop case */
        for (temp_id = 0; temp_id <= NU_9T; temp_id++)
        {
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            
            if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))      /* true if tile is in hand, else just pass */
            {
                mmi_gx_vsmj_reset_chk(user_ptr->hand);
                temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);      /* if this tile not in hand,then no use & no harm */
                
                if (temp_ting_num > ting_num)
                {
                    ting_num = temp_ting_num;
                    to_move_type = 1;
                    todrop_tile_id = temp_id;
                }
            }
        }
        /* normal drop case */
        
        /* think move done */
        
        if (ting_num > 0)   /* have a way to ting ,take action */
        {
            com_strategy[user_ptr->id] = COM_STRATEGY_2;
            
            switch (to_move_type)
            {
            case 1:
                mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                break;
                
            case 6:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[0], user_ptr);
                break;
                
            case 7:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[1], user_ptr);
                break;
                
            case 8:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[2], user_ptr);
                break;
                
            case 9:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[3], user_ptr);
                break;
                
            case 10:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
                break;
                
            case 11:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
                break;
                
            case 12:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
                break;
                
            case 13:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
                break;
                
            default:
                /* shouldn't come here */
                break;
            }
        }
        else    /* no one-way ting,start to count connection value */
        {
            gx_vsmj_chk_status_enum think_base[18];
            gx_vsmj_chk_status_enum think_temp[18];
            S16 base_value;
            S16 temp_value;
            
            /* initialize */
            i = 0;
            base_value = 0;
            while (user_ptr->hand[i]->id != WALL_END)
            {
                think_base[i] = CHK_SINGLE;
                think_temp[i] = CHK_NOTUSED;
                mmi_gx_vsmj_com_think_count_value(think_base[i], &base_value);
                i++;
            }
            think_base[i] = CHK_END;
            think_temp[i] = CHK_END;
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
            /* initialize */
            
            /* bu gun case */
            for (i = 0; user_ptr->can_bugun[i] == TRUE; i++)
            {
                temp_value = 9;
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                
                mmi_gx_vsmj_set_chk(user_ptr->bugun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                mmi_gx_vsmj_set_chk(user_ptr->bugun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                
                for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                {
                    mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                }
                
                if (temp_value > base_value)
                {
                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                    {
                        think_base[i] = think_temp[i];
                    }
                    
                    base_value = temp_value;
                    to_move_type = 10 + i;
                    todrop_tile_id = temp_id;
                }
            }
            /* bu gun case */
            
            /* handgun case */
            for (i = 0; user_ptr->can_handgun[i] == TRUE; i++)
            {
                temp_value = 9;
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                
                for (j = 0; user_ptr->hand[j]->id != WALL_END; j++)
                {
                    mmi_gx_vsmj_com_think_count_value(think_temp[j], &temp_value);
                }
                
                if (temp_value > base_value)
                {
                    for (j = 0; user_ptr->hand[j]->id != WALL_END; j++)
                    {
                        think_base[j] = think_temp[j];
                    }
                    
                    base_value = temp_value;
                    to_move_type = 10 + i;
                    todrop_tile_id = temp_id;
                }
                
            }
            /* handgun case */
            
            /* normal drop case */
            for (temp_id = TE_EAST; temp_id <= NU_9T; temp_id++)
            {
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                
                if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                {
                    temp_value = 0;
                    mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                    mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    
                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                    {
                        mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                    }
                    
                    if (temp_value > base_value)
                    {
                        for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                        {
                            think_base[i] = think_temp[i];
                        }
                        
                        base_value = temp_value;
                        to_move_type = 1;
                        todrop_tile_id = temp_id;
                    }
                    
                }
            }
            /* normal drop case */
            
            /* got todrop_tile_id,to_move_type */
            /* check result and make decision */
            switch (to_move_type)
            {
            case 1:
                mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                break;
                
            case 6:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[0], user_ptr);
                break;
                
            case 7:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[1], user_ptr);
                break;
                
            case 8:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[2], user_ptr);
                break;
                
            case 9:
                mmi_gx_vsmj_bugun(user_ptr->bugun_id[3], user_ptr);
                break;
                
            case 10:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
                break;
                
            case 11:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
                break;
                
            case 12:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
                break;
                
            case 13:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
                break;
                
            default:
                /* shouldn't come here */
                break;
            }
                }
                break;
                /*********************************************************************************************/
            case MOVE_DISCARD_SPECIAL:
                to_move_type = 0;   /* initial */
                
                /* have original set, eat0,eat1,eat2,pon,gunhand, case */
                /* original ->eat012->pon->gunhand */
                
                /* put everything after original so if they have the same ting number,
                original will be the choice */
                /* gunhand case has at most 1 choice at this state */
                
                /* think move start */
                /* original case */
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                
                if (temp_ting_num > ting_num)
                {
                    ting_num = temp_ting_num;
                    to_move_type = 0;
                    todrop_tile_id = temp_id;
                }
                /* original case */
                
                /* eat0-> drop case */
                if (user_ptr->can_eat[0] == TRUE)
                {
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    
                    /* kick the three used to make a link */
                    mmi_gx_vsmj_set_chk(highlight->id - 2, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    /* kick the three used to make a link */
                    
                    for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                    {
                        mmi_gx_vsmj_reset_chk(user_ptr->hand);
                        if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                        {
                            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                            mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                            
                            if (temp_ting_num > ting_num)
                            {
                                ting_num = temp_ting_num;
                                to_move_type = 3;
                                todrop_tile_id = temp_id;
                            }
                        }
                    }
                    /* restore the 3 used to make a link */
                    mmi_gx_vsmj_set_chk(highlight->id - 2, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    /* restrore the 3 used to make a link */
                }
                /* eat0 drop case */
                
                /* eat1-> drop case */
                if (user_ptr->can_eat[1] == TRUE)
                {
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    
                    /* kick the two used to make a link */
                    mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    /* kick the two used to make a link */
                    
                    for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                    {
                        mmi_gx_vsmj_reset_chk(user_ptr->hand);
                        if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                        {
                            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                            mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                            
                            if (temp_ting_num > ting_num)
                            {
                                ting_num = temp_ting_num;
                                to_move_type = 4;
                                todrop_tile_id = temp_id;
                            }
                        }
                    }
                    /* restore the two used to make a link */
                    mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    /* restrore the two used to make a link */
                }
                /* eat1 drop case */
                
                /* eat2-> drop case */
                if (user_ptr->can_eat[2] == TRUE)
                {
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    
                    /* kick the two used to make a link */
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id + 2, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    /* kick the two used to make a link */
                    for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                    {
                        mmi_gx_vsmj_reset_chk(user_ptr->hand);
                        if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                        {
                            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                            mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                            
                            if (temp_ting_num > ting_num)
                            {
                                ting_num = temp_ting_num;
                                to_move_type = 5;
                                todrop_tile_id = temp_id;
                            }
                        }
                    }
                    /* restore the two used to make a link */
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id + 2, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    /* restrore the two used to make a link */
                }
                /* eat2 drop case */
                
                /* pon-> drop case */
                if (user_ptr->can_pon == TRUE)
                {
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    
                    /* kick the three used to make a triple */
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    /* kick the hjree used to make a triple */
                    for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                    {
                        mmi_gx_vsmj_reset_chk(user_ptr->hand);
                        if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                        {
                            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                            mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                            
                            if (temp_ting_num > ting_num)
                            {
                                ting_num = temp_ting_num;
                                to_move_type = 2;
                                todrop_tile_id = temp_id;
                            }
                        }
                    }
                    /* restore the three used to make a triple */
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    /* restrore the two used to make a triple */
                }
                /* pon drop case */
                
                /* handgun case */
                for (i = 0; user_ptr->can_handgun[i] == TRUE; i++)
                {
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    
                    mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    
                    if (temp_ting_num > ting_num)
                    {
                        ting_num = temp_ting_num;
                        to_move_type = 10 + i;   /* 7 for handgun0,8 for 1,9 for 2, 10 for 3 */
                        todrop_tile_id = temp_id;
                    }
                }
                /* handgun case */
                
                if (ting_num > 0)   /* have a way to get ting, take action */
                {
                    com_strategy[user_ptr->id] = COM_STRATEGY_2;
                    
                    switch (to_move_type)
                    {
                        /* 0: original, 2:pon , 3: eat0 ,4: eat1,5:eat2,7:handgun0~3 */
                    case 0:
                        /* clear all */
                        user_ptr->can_pon = FALSE;
                        user_ptr->can_bugun[0] = FALSE;
                        user_ptr->can_bugun[1] = FALSE;
                        user_ptr->can_bugun[2] = FALSE;
                        user_ptr->can_bugun[3] = FALSE;
                        user_ptr->can_hou = FALSE;
                        user_ptr->can_eat[0] = FALSE;
                        user_ptr->can_eat[1] = FALSE;
                        user_ptr->can_eat[2] = FALSE;
                        user_ptr->can_handgun[0] = FALSE;
                        user_ptr->can_handgun[1] = FALSE;
                        user_ptr->can_handgun[2] = FALSE;
                        user_ptr->can_handgun[3] = FALSE;
                        /* cancel special */
                        mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
                        mmi_gx_vsmj_sort_tile(user_ptr->hand);
                        game_move = MOVE_DISCARD_CHECK_CONTINUE;
                        
                        break;
                        
                    case 2:
                        mmi_gx_vsmj_pon(user_ptr);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 3:
                        mmi_gx_vsmj_eat(user_ptr, 0);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 4:
                        mmi_gx_vsmj_eat(user_ptr, 1);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 5:
                        mmi_gx_vsmj_eat(user_ptr, 2);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 7:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
                        break;
                        
                    case 8:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
                        break;
                        
                    case 9:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
                        break;
                        
                    case 10:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
                        break;
                    }
                    
                }
                else    /* no one-way-ting move,start counting connection */
                {
                    gx_vsmj_chk_status_enum think_base[18];
                    gx_vsmj_chk_status_enum think_temp[18];
                    S16 base_value = 0;
                    S16 temp_value = 0;
                    
                    /* initialize */
                    i = 0;
                    while (user_ptr->hand[i]->id != WALL_END)
                    {
                        think_base[i] = CHK_SINGLE;
                        think_temp[i] = CHK_NOTUSED;
                        mmi_gx_vsmj_com_think_count_value(think_base[i], &base_value);
                        i++;
                    }
                    think_base[i] = CHK_END;
                    think_temp[i] = CHK_END;
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                    /* initialize */
                    
                    /* need original,eat 0~2, pon,handgun */
                    
                    /* original case */
                    temp_value = 0;
                    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                    mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                    
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                    mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                    mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    
                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                    {
                        mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                    }
                    
                    if (temp_value > base_value)
                    {
                        for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                        {
                            think_base[i] = think_temp[i];
                        }
                        base_value = temp_value;
                        to_move_type = 0;
                        todrop_tile_id = temp_id;
                    }
                    /* original case */
                    
                    /* eat0 case */
                    if (user_ptr->can_eat[0])
                    {
                        mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                        mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                        
                        mmi_gx_vsmj_set_chk(highlight->id - 2, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        
                        for (temp_id = TE_EAST; temp_id <= NU_9T; temp_id++)
                        {
                            mmi_gx_vsmj_reset_chk(user_ptr->hand);
                            mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                            
                            if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                            {
                                temp_value = 27;
                                mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                                mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                                
                                for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                {
                                    mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                                }
                                
                                if (temp_value > base_value)
                                {
                                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                    {
                                        think_base[i] = think_temp[i];
                                    }
                                    
                                    base_value = temp_value;
                                    to_move_type = 3;
                                    todrop_tile_id = temp_id;
                                }
                            }
                            
                        }
                        mmi_gx_vsmj_set_chk(highlight->id - 2, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                    }
                    /* eat0 case */
                    
                    /* eat1 case */
                    if (user_ptr->can_eat[1])
                    {
                        mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                        mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                        
                        mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        
                        for (temp_id = TE_EAST; temp_id <= NU_9T; temp_id++)
                        {
                            mmi_gx_vsmj_reset_chk(user_ptr->hand);
                            mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                            
                            if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                            {
                                temp_value = 27;
                                mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                                mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                                
                                for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                {
                                    mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                                }
                                
                                if (temp_value > base_value)
                                {
                                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                    {
                                        think_base[i] = think_temp[i];
                                    }
                                    
                                    base_value = temp_value;
                                    to_move_type = 4;
                                    todrop_tile_id = temp_id;
                                }
                            }
                            
                        }
                        mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    }
                    /* eat1 case */
                    
                    /* eat2 case */
                    if (user_ptr->can_eat[2])
                    {
                        mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                        mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                        
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id + 2, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        
                        for (temp_id = TE_EAST; temp_id <= NU_9T; temp_id++)
                        {
                            mmi_gx_vsmj_reset_chk(user_ptr->hand);
                            mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                            
                            if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                            {
                                temp_value = 27;
                                mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                                mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                                
                                for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                {
                                    mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                                }
                                
                                if (temp_value > base_value)
                                {
                                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                    {
                                        think_base[i] = think_temp[i];
                                    }
                                    
                                    base_value = temp_value;
                                    to_move_type = 5;
                                    todrop_tile_id = temp_id;
                                }
                            }
                        }
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id + 2, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                    }
                    /* eat2 case */
                    
                    /* pon case */
                    if (user_ptr->can_pon)
                    {
                        mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                        mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                        
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        
                        for (temp_id = TE_EAST; temp_id <= NU_9T; temp_id++)
                        {
                            mmi_gx_vsmj_reset_chk(user_ptr->hand);
                            mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                            
                            if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                            {
                                temp_value = 27;
                                mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                                mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                                
                                for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                {
                                    mmi_gx_vsmj_com_think_count_value(think_temp[i], &temp_value);
                                }
                                
                                if (temp_value > base_value)
                                {
                                    for (i = 0; user_ptr->hand[i]->id != WALL_END; i++)
                                    {
                                        think_base[i] = think_temp[i];
                                    }
                                    
                                    base_value = temp_value;
                                    to_move_type = 2;
                                    todrop_tile_id = temp_id;
                                }
                            }
                        }
                        
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                    }
                    /* pon case */
                    
                    /* handgun case */
                    for (i = 0; user_ptr->can_handgun[i] == TRUE; i++)
                    {
                        temp_value = 9;
                        mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                        mmi_gx_vsmj_reset_chk_all_stat_only(think_temp);
                        
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                        mmi_gx_vsmj_check_connection(user_ptr->hand, think_temp);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                        for (j = 0; user_ptr->hand[j]->id != WALL_END; j++)
                        {
                            mmi_gx_vsmj_com_think_count_value(think_temp[j], &temp_value);
                        }
                        
                        if (temp_value > base_value)
                        {
                            for (j = 0; user_ptr->hand[j]->id != WALL_END; j++)
                            {
                                think_base[j] = think_temp[j];
                            }
                            
                            base_value = temp_value;
                            to_move_type = 10 + i;
                            todrop_tile_id = temp_id;
                        }
                    }
                    /* handgun case */
                    
                    /* got todrop_tile_id,to_move_type */
                    /* check result and make decision */
                    switch (to_move_type)
                    {
                        /* 0: original, 1: normal drop, 2:pon , 3: eat0 ,4: eat1,5:eat2,6:bugun,7:handgun0~3 */
                    case 0:
                        /* clear all */
                        user_ptr->can_pon = FALSE;
                        user_ptr->can_bugun[0] = FALSE;
                        user_ptr->can_bugun[1] = FALSE;
                        user_ptr->can_bugun[2] = FALSE;
                        user_ptr->can_bugun[3] = FALSE;
                        user_ptr->can_hou = FALSE;
                        user_ptr->can_eat[0] = FALSE;
                        user_ptr->can_eat[1] = FALSE;
                        user_ptr->can_eat[2] = FALSE;
                        user_ptr->can_handgun[0] = FALSE;
                        user_ptr->can_handgun[1] = FALSE;
                        user_ptr->can_handgun[2] = FALSE;
                        user_ptr->can_handgun[3] = FALSE;
                        /* cancel special */
                        mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
                        mmi_gx_vsmj_sort_tile(user_ptr->hand);
                        game_move = MOVE_DISCARD_CHECK_CONTINUE;
                        break;
                        
                    case 2:
                        mmi_gx_vsmj_pon(user_ptr);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 3:
                        mmi_gx_vsmj_eat(user_ptr, 0);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 4:
                        mmi_gx_vsmj_eat(user_ptr, 1);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 5:
                        mmi_gx_vsmj_eat(user_ptr, 2);
                        mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                        break;
                        
                    case 7:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
                        break;
                        
                    case 8:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
                        break;
                        
                    case 9:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
                        break;
                        
                    case 10:
                        mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
                        break;
                        
                    default:
                        /* shouldn't come here */
                        break;
                    }
                }
                break;
                
            default:
                /* shouldn't come here */
                break;
                
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_com_think_st_2
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  user_ptr        [?]         
 *  S16(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_com_think_st_2(gx_vsmj_user_struct *user_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* let com check hou first,come here if failed to hou */
   /*******************************************/

    S16 ting_num = -1;
    S16 temp_ting_num = 0;
    gx_vsmj_tile_id_enum todrop_tile_id = 0;
    gx_vsmj_tile_id_enum temp_id = 0;
    U8 to_move_type = 0;        /* 0 for original,1 for normal drop, 2 for pon ,3 for eat0,4 for eat1,5 for eat2 ,
                                   6 for bu_gun no.1 , 7 for bu_gun no.1 , 8 for bu_gun no.1 , 9 for bu_gun no.1 ,
                                   10 for gun_inhand no.1 ,11 inhand no.2 , 12 inhand no.3 , 13 inhand no.4 */
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_gx_vsmj_reset_chk_all(user_ptr->hand);

    switch (game_move)
    {
        /* case MOVE_PICK_SPECIAL: */
    case MOVE_DISCARD_TILE:
        to_move_type = 1;   /* initialize */
        
        /* think move start */
        /* have normal drop case,handgun case ,bu_gun case case */
        /* bu_gun->handgun->normal drop */
        
        /* bu_gun case */
        for (i = 0; user_ptr->can_bugun[i] == TRUE; i++)
        {
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            
            mmi_gx_vsmj_set_chk(user_ptr->bugun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->bugun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            
            if (temp_ting_num > ting_num)
            {
                ting_num = temp_ting_num;
                to_move_type = 6 + i;
                todrop_tile_id = temp_id;
            }
        }
        /* bu_gun case */
        
        /* actually same with normal drop's drop_highlight case,so check bugun first will keep bu_gun
        if no other way have a better ting num,then com get one more chance to pick tile 
        with highest hou chance */
        
        /* handgun case */
        for (i = 0; user_ptr->can_handgun[i] == TRUE; i++)
        {
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
            
            if (temp_ting_num > ting_num)
            {
                ting_num = temp_ting_num;
                to_move_type = 10 + i;   /* 7 for handgun0,8 for 1,9 for 2, 10 for 3 */
                todrop_tile_id = temp_id;
            }
        }
        /* handgun case */
        
        /* normal drop case */
        for (temp_id = 0; temp_id <= NU_9T; temp_id++)
        {
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            
            if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))      /* true if tile is in hand, else just pass */
            {
                mmi_gx_vsmj_reset_chk(user_ptr->hand);
                temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);      /* if this tile not in hand,then no use & no harm */
                
                if (temp_ting_num > ting_num)
                {
                    ting_num = temp_ting_num;
                    to_move_type = 1;
                    todrop_tile_id = temp_id;
                }
            }
        }
        /* normal drop case */
        
        /* think move done */
        switch (to_move_type)
        {
        case 1:
            mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
            break;
            
        case 6:
            mmi_gx_vsmj_bugun(user_ptr->bugun_id[0], user_ptr);
            break;
            
        case 7:
            mmi_gx_vsmj_bugun(user_ptr->bugun_id[1], user_ptr);
            break;
            
        case 8:
            mmi_gx_vsmj_bugun(user_ptr->bugun_id[2], user_ptr);
            break;
            
        case 9:
            mmi_gx_vsmj_bugun(user_ptr->bugun_id[3], user_ptr);
            break;
            
        case 10:
            mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
            break;
            
        case 11:
            mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
            break;
            
        case 12:
            mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
            break;
            
        case 13:
            mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
            break;
            
        default:
            /* shouldn't come here */
            break;
        }
        break;
        
        case MOVE_DISCARD_SPECIAL:
            to_move_type = 0;   /* initial */
            
            /* have original set, eat0,eat1,eat2,pon,gunhand, case */
            /* original ->eat012->pon->gunhand */
            
            /* put everything after original so if they have the same ting number,
            original will be the choice */
            
            /* gunhand case has at most 1 choice at this state */
            
            /* think move start */
            /* original case */
            mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
            temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
            
            if (temp_ting_num > ting_num)
            {
                ting_num = temp_ting_num;
                to_move_type = 0;
                todrop_tile_id = temp_id;
            }
            /* original case */
            
            /* eat0-> drop case */
            if (user_ptr->can_eat[0] == TRUE)
            {
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                
                /* kick the three used to make a link */
                mmi_gx_vsmj_set_chk(highlight->id - 2, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                /* kick the three used to make a link */
                
                for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                {
                    mmi_gx_vsmj_reset_chk(user_ptr->hand);
                    if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                    {
                        temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                        mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                        if (temp_ting_num > ting_num)
                        {
                            ting_num = temp_ting_num;
                            to_move_type = 3;
                            todrop_tile_id = temp_id;
                        }
                    }
                }
                /* restore the 3 used to make a link */
                mmi_gx_vsmj_set_chk(highlight->id - 2, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                /* restrore the 3 used to make a link */
            }
            /* eat0 drop case */
            
            /* eat1-> drop case */
            if (user_ptr->can_eat[1] == TRUE)
            {
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                
                /* kick the two used to make a link */
                mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                /* kick the two used to make a link */
                
                for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                {
                    mmi_gx_vsmj_reset_chk(user_ptr->hand);
                    if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                    {
                        temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                        mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                        if (temp_ting_num > ting_num)
                        {
                            ting_num = temp_ting_num;
                            to_move_type = 4;
                            todrop_tile_id = temp_id;
                        }
                    }
                }
                /* restore the two used to make a link */
                mmi_gx_vsmj_set_chk(highlight->id - 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                /* restrore the two used to make a link */
            }
            /* eat1 drop case */
            
            /* eat2-> drop case */
            if (user_ptr->can_eat[2] == TRUE)
            {
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                
                /* kick the two used to make a link */
                mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id + 2, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                /* kick the two used to make a link */
                for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                {
                    mmi_gx_vsmj_reset_chk(user_ptr->hand);
                    if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                    {
                        temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                        mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                        if (temp_ting_num > ting_num)
                        {
                            ting_num = temp_ting_num;
                            to_move_type = 5;
                            todrop_tile_id = temp_id;
                        }
                    }
                }
                /* restore the two used to make a link */
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id + 1, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id + 2, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                /* restrore the two used to make a link */
            }
            /* eat2 drop case */
            
            /* pon-> drop case */
            if (user_ptr->can_pon == TRUE)
            {
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                
                /* kick the three used to make a triple */
                mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                /* kick the hjree used to make a triple */
                for (temp_id = 0; temp_id <= NU_9T; temp_id++)
                {
                    mmi_gx_vsmj_reset_chk(user_ptr->hand);
                    if (mmi_gx_vsmj_set_chk(temp_id, CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand))
                    {
                        temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                        mmi_gx_vsmj_set_chk(temp_id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                        
                        if (temp_ting_num > ting_num)
                        {
                            ting_num = temp_ting_num;
                            to_move_type = 2;
                            todrop_tile_id = temp_id;
                        }
                    }
                }
                /* restore the three used to make a triple */
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                /* restrore the two used to make a triple */
            }
            /* pon drop case */
            
            /* handgun case */
            for (i = 0; user_ptr->can_handgun[i] == TRUE; i++)
            {
                mmi_gx_vsmj_reset_chk_all(user_ptr->hand);
                
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                mmi_gx_vsmj_set_chk(user_ptr->handgun_id[i], CHK_NOTUSED, CHK_MISSION_OCCUPY, user_ptr->hand);
                temp_ting_num = mmi_gx_vsmj_com_think_check_ting_num(user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                mmi_gx_vsmj_set_chk(highlight->id, CHK_MISSION_OCCUPY, CHK_NOTUSED, user_ptr->hand);
                
                if (temp_ting_num > ting_num)
                {
                    ting_num = temp_ting_num;
                    to_move_type = 10 + i;   /* 7 for handgun0,8 for 1,9 for 2, 10 for 3 */
                    todrop_tile_id = temp_id;
                }
            }
            /* handgun case */
            
            switch (to_move_type)
            {
                /* 0: original, 1: normal drop, 2:pon , 3: eat0 ,4: eat1,5:eat2,6:bugun,7:handgun0~3 */
            case 0:
                /* clear all */
                user_ptr->can_pon = FALSE;
                user_ptr->can_bugun[0] = FALSE;
                user_ptr->can_bugun[1] = FALSE;
                user_ptr->can_bugun[2] = FALSE;
                user_ptr->can_bugun[3] = FALSE;
                user_ptr->can_hou = FALSE;
                user_ptr->can_eat[0] = FALSE;
                user_ptr->can_eat[1] = FALSE;
                user_ptr->can_eat[2] = FALSE;
                user_ptr->can_handgun[0] = FALSE;
                user_ptr->can_handgun[1] = FALSE;
                user_ptr->can_handgun[2] = FALSE;
                user_ptr->can_handgun[3] = FALSE;
                /* cancel special */
                mmi_gx_vsmj_eliminate_tile(highlight->id, user_ptr->hand);
                mmi_gx_vsmj_sort_tile(user_ptr->hand);
                game_move = MOVE_DISCARD_CHECK_CONTINUE;
                break;
                
            case 2:
                mmi_gx_vsmj_pon(user_ptr);
                mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                break;
                
            case 3:
                mmi_gx_vsmj_eat(user_ptr, 0);
                mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                break;
                
            case 4:
                mmi_gx_vsmj_eat(user_ptr, 1);
                mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                break;
                
            case 5:
                mmi_gx_vsmj_eat(user_ptr, 2);
                mmi_gx_vsmj_discard_tile(todrop_tile_id, user_ptr);
                break;
                
            case 7:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[0], user_ptr);
                break;
                
            case 8:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[1], user_ptr);
                break;
                
            case 9:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[2], user_ptr);
                break;
                
            case 10:
                mmi_gx_vsmj_handgun(user_ptr->handgun_id[3], user_ptr);
                break;
            }
            break;
            
            default:
                /* shouldn't come here */
                break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_set_chk
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  target_id           [IN]        
 *  original_status     [IN]        
 *  to_status           [IN]        
 *  tile_set_ptr        [?]         
 *  ptr(?)              [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_set_chk(
        gx_vsmj_tile_id_enum target_id,
        gx_vsmj_chk_status_enum original_status,
        gx_vsmj_chk_status_enum to_status,
        gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (tile_set_ptr[i]->id != WALL_END)
    {
        if (tile_set_ptr[i]->id == target_id)
            if (tile_set_ptr[i]->pos == original_status)
            {
                tile_set_ptr[i]->pos = to_status;
                return TRUE;
            }
        i++;
    }

    /* didn't found it */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_com_think_check_ting_num
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  tile_set        [?]         
 *  ptr(?)          [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
/* call set by value, dont destroy original tiel set */
S16 mmi_gx_vsmj_com_think_check_ting_num(gx_vsmj_tile_struct *tile_set[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gx_vsmj_tile_id_enum assume_get_tile_id;
    S16 temp_ting_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (assume_get_tile_id = 0; assume_get_tile_id <= NU_9T; assume_get_tile_id++)
    {
        /* set init value */
        mmi_gx_vsmj_reset_chk(tile_set);
        mmi_gx_vsmj_set_chk(assume_get_tile_id, CHK_NOTUSED, CHK_USED, tile_set);
        /* set init value */

        if (mmi_gx_vsmj_hou_trial(tile_set, FALSE))
        {
            temp_ting_num++;
            /* for more accuracy, temp _ting should add the number of tile still unseen in game 
               of the id assume_tile_get_id */
        }
    }

    return temp_ting_num;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_hou_trial
 * DESCRIPTION
 *  check eat
 * PARAMETERS
 *  tile_set_ptr        [?]         
 *  pair_used           [IN]        
 *  ptr(?)              [IN]        Array
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gx_vsmj_hou_trial(gx_vsmj_tile_struct *tile_set_ptr[], BOOL pair_used)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (tile_set_ptr[i]->pos == CHK_NOTUSED)
        {
            break;
        }
        else if (tile_set_ptr[i]->pos == CHK_END)   /* all done */
        {
            return TRUE;
        }
        i++;
    }
    
    /* pair case */
    if (pair_used == FALSE)
        if (mmi_gx_vsmj_check_multi(2, tile_set_ptr[i]->id, tile_set_ptr))
        {
            pair_used = TRUE;
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_PAIR, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_PAIR, tile_set_ptr);
            
            if (mmi_gx_vsmj_hou_trial(tile_set_ptr, pair_used))
            {
                return TRUE;
            }
            
            pair_used = FALSE;
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_PAIR, CHK_NOTUSED, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_PAIR, CHK_NOTUSED, tile_set_ptr);
        }
        /* pon case */
        if (mmi_gx_vsmj_check_multi(3, tile_set_ptr[i]->id, tile_set_ptr))
        {
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
            
            if (mmi_gx_vsmj_hou_trial(tile_set_ptr, pair_used))
            {
                return TRUE;
            }
            
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
        }
        
        /* link case */
        if (mmi_gx_vsmj_check_link(3, tile_set_ptr[i]->id, tile_set_ptr))
        {
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_LINE_L, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 1, CHK_NOTUSED, CHK_LINE_M, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_NOTUSED, CHK_LINE_R, tile_set_ptr);
            
            if (mmi_gx_vsmj_hou_trial(tile_set_ptr, pair_used))
            {
                return TRUE;
            }
            
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_LINE_L, CHK_NOTUSED, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 1, CHK_LINE_M, CHK_NOTUSED, tile_set_ptr);
            mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_LINE_R, CHK_NOTUSED, tile_set_ptr);
        }
        
        /* all fail */
        return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_check_connection
 * DESCRIPTION
 *  check hou_pai
 * PARAMETERS
 *  tile_set_ptr        [?]     
 *  temp_ptr            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_check_connection(gx_vsmj_tile_struct *tile_set_ptr[], gx_vsmj_chk_status_enum *temp_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* find first not used tile */
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (tile_set_ptr[i]->pos == CHK_END)    /* all done this turn,start count value and compare */
        {
            S16 j;
            S16 temp_value = 0;
            S16 current_value = 0;
            
            for (j = 0; tile_set_ptr[j]->id != WALL_END; j++)
            {
                mmi_gx_vsmj_com_think_count_value(*(temp_ptr + j), &temp_value);
                mmi_gx_vsmj_com_think_count_value(tile_set_ptr[j]->pos, &current_value);
            }
            if (current_value > temp_value) /* current one better, copy to temp */
            {
                for (j = 0; tile_set_ptr[j]->id != WALL_END; j++)
                {
                    *(temp_ptr + j) = tile_set_ptr[j]->pos;
                }
            }
            return;
        }
        else if (tile_set_ptr[i]->pos == CHK_NOTUSED)
        {
            break;
        }
        i++;
    }
    /* find first not used tile */
    
    /* check quad case */
    if (mmi_gx_vsmj_check_multi(4, tile_set_ptr[i]->id, tile_set_ptr))
    {
        /* set status,do next recursive, change status back and out if */
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_QUAD, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_QUAD, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_QUAD, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_QUAD, tile_set_ptr);
        
        mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
        
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_QUAD, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_QUAD, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_QUAD, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_QUAD, CHK_NOTUSED, tile_set_ptr);
    }
    /* check quad case */
    
    /* check triple case */
    if (mmi_gx_vsmj_check_multi(3, tile_set_ptr[i]->id, tile_set_ptr))
    {
        /* set status,do next recursive, change status back and out if */
        
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
        
        mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
        
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
    }
    /* check triple case */
    
    /* check line case */
    if (mmi_gx_vsmj_check_link(3, tile_set_ptr[i]->id, tile_set_ptr))
    {
        /* set status,do next recursive, change status back and out if */
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_LINE_L, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 1, CHK_NOTUSED, CHK_LINE_M, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_NOTUSED, CHK_LINE_R, tile_set_ptr);
        
        mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
        
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_LINE_L, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 1, CHK_LINE_M, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_LINE_R, CHK_NOTUSED, tile_set_ptr);
    }
    /* check line case */
    
    /* check halfin link */
    if (mmi_gx_vsmj_check_link(2, tile_set_ptr[i]->id, tile_set_ptr))
    {
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_INHLINE_L, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 1, CHK_NOTUSED, CHK_INHLINE_R, tile_set_ptr);
        
        mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
        
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_INHLINE_L, CHK_NOTUSED, tile_set_ptr);
        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 1, CHK_INHLINE_R, CHK_NOTUSED, tile_set_ptr);
    }
    /* check halfinlink */
    
    /* check outinlink */
    if (mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_NOTUSED, tile_set_ptr)        /* simply using set chk bool to know its existence */
        && mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_NOTUSED, CHK_NOTUSED, tile_set_ptr))
        if (tile_set_ptr[i]->id >= NU_1W && tile_set_ptr[i]->id <= NU_9T)
            if (tile_set_ptr[i]->id != NU_8W && tile_set_ptr[i]->id != NU_9W)
                if (tile_set_ptr[i]->id != NU_8S && tile_set_ptr[i]->id != NU_9S)
                    if (tile_set_ptr[i]->id != NU_8T && tile_set_ptr[i]->id != NU_9T)
                    {
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_OUTHLINE_L, tile_set_ptr);
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_NOTUSED, CHK_OUTHLINE_R, tile_set_ptr);
                        
                        mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
                        
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_OUTHLINE_L, CHK_NOTUSED, tile_set_ptr);
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id + 2, CHK_OUTHLINE_R, CHK_NOTUSED, tile_set_ptr);
                    }
                    /* check outinlink */
                    
                    /* check pair */
                    if (mmi_gx_vsmj_check_multi(2, tile_set_ptr[i]->id, tile_set_ptr))
                    {
                        /* set status,do next recursive, change status back and out if */
                        
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_NOTUSED, CHK_TRIPLE, tile_set_ptr);
                        
                        mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
                        
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
                        mmi_gx_vsmj_set_chk(tile_set_ptr[i]->id, CHK_TRIPLE, CHK_NOTUSED, tile_set_ptr);
                    }
                    /* check pair */
                    
                    /* check single */
                    tile_set_ptr[i]->pos = CHK_SINGLE;
                    mmi_gx_vsmj_check_connection(tile_set_ptr, temp_ptr);
                    tile_set_ptr[i]->pos = CHK_NOTUSED;
                    /* check single */
                    
                    /* all tried */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_com_think_count_value
 * DESCRIPTION
 *  Debug use
 * PARAMETERS
 *  status      [IN]        
 *  value       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_com_think_count_value(gx_vsmj_chk_status_enum status, S16 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * check normal drop or original case first so if any special move having equal or less value
     * will be ignored 
     * 
     * special move only when
     * 1. "all tiles having highlight's id are NOT SINGLE" AND
     * 2. "the score is higher then decision made until now"
     * 
     * rule 1 assures that after the special move the tile just got in will be of some use,
     * say make a half link, make a pair, etc.
     */

    /*
     * base consideration : 
     * o  123 345 3 > 333 12 45 
     * o  12 33 > 123 3
     * o  123 33 > 12 333
     * o  123 22 > 13 222
     * make sure the count will follow all the rules above
     */
    switch (status)
    {
        case CHK_QUAD:
            *value += 9;    /* better decrease it when in 2 player mode */
            break;

        case CHK_TRIPLE:
            *value += 9;
            break;
        case CHK_LINE_L:
        case CHK_LINE_M:
        case CHK_LINE_R:
            *value += 9;
            break;
        case CHK_PAIR:
            *value += 7;
            break;
        case CHK_INHLINE_L:
        case CHK_INHLINE_R:
            *value += 4;
            break;
        case CHK_OUTHLINE_L:
        case CHK_OUTHLINE_R:
            *value += 2;
            break;
        case CHK_SINGLE:
            *value -= 7;
            break;
        case CHK_MISSION_OCCUPY:
            /* Mission relative score already added when initialize */
            break;

        default:
            /* shouldn't come here */
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_reset_chk_all_stat_only
 * DESCRIPTION
 *  check hou_pai
 * PARAMETERS
 *  chk_set_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_reset_chk_all_stat_only(gx_vsmj_chk_status_enum *chk_set_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*(chk_set_ptr + i) != CHK_END)
    {
        *(chk_set_ptr + i) = CHK_SINGLE;
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_reset_chk
 * DESCRIPTION
 *  check hou_pai
 * PARAMETERS
 *  tile_set_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_reset_chk(gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (tile_set_ptr[i]->id != WALL_END)
    {
        if (tile_set_ptr[i]->pos != CHK_MISSION_OCCUPY)
        {
            tile_set_ptr[i]->pos = CHK_NOTUSED;
        }
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_reset_chk_all
 * DESCRIPTION
 *  check hou_pai
 * PARAMETERS
 *  tile_set_ptr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_reset_chk_all(gx_vsmj_tile_struct *tile_set_ptr[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (tile_set_ptr[i]->id != WALL_END)
    {
        tile_set_ptr[i]->pos = CHK_NOTUSED;
        i++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_stagegen
 * DESCRIPTION
 *  generate stage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_stagegen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;
    S16 selected;
    S16 id;
    gx_vsmj_tile_id_enum tile_appear[TABLE_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* srand( time(NULL) ); */

    /* set appear num */
    id = TE_EAST;

    for (i = 0; i < 34; i++)    /* 7*4 text tiles + 3*9 *4 num tiles */
    {
        for (j = 0; j < 4; j++)
        {
            tile_appear[4 * i + j] = (gx_vsmj_tile_id_enum) (id);
        }
        id++;
    }
    for (j = 0; j < 8; j++) /* 8 flower tiles */
    {
        tile_appear[4 * i + j] = (gx_vsmj_tile_id_enum) (id);
        id++;
    }
    /* set appear num */

    /* randomize stage */
    for (i = 0; i < TABLE_NUM; i++)
    {
        selected = rand() % (TABLE_NUM - i);
        tile_table[i].id = tile_appear[selected];
        tile_table[i].pos = POS_DESK;
        if (selected != TABLE_NUM - i - 1)
        {
            tile_appear[selected] = tile_appear[TABLE_NUM - i - 1];
        }
    }
    /* randomize stage */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_throwdice
 * DESCRIPTION
 *  throw dice (actually give number to start index and end index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_throwdice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 dice[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dice[0] = 1 + rand() % 6;
    dice[1] = 1 + rand() % 6;
    dice[2] = 1 + rand() % 6;

    /* add show dice animation code here */

    table_offset = (dice[0] + dice[1] + dice[2]) * 2;   /* 2 tiles each block */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_ok_pressed
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_ok_pressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (pen_pos == PP_PENNOTDOWN)
	{
		if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_SPECIAL)
		{
			if (highlight_special == HIGHLIGHT_EAT)
			{
				pen_pos = highlight_eatcase;
			}
			else if (highlight_special == HIGHLIGHT_GUN)
			{
				pen_pos = highlight_guncase;
			}
			else
			{
				pen_pos = highlight_special;
			}
			highlight_special = -1;
			highlight_eatcase = -1;
            highlight_guncase = -1;
		}
		else if (game_move == MOVE_DISCARD_TILE && current_user->id == PLAYER_1)
		{
			if (highlight != &wall_end)
			{
				if (current_user->hand[highlight_tile_index]->id == highlight->id)
				{
					pen_pos = PP_HIGHLIGHT;
				}
				else
				{
					if (highlight_tile_index < mmi_gx_vsmj_get_highlight_tile_index())
					{
						pen_pos = (gx_vsmj_pen_pos_enum) (PP_OWN_0 + highlight_tile_index);
					}
					else
					{
						pen_pos = (gx_vsmj_pen_pos_enum) (PP_OWN_0 + highlight_tile_index - 1);
					}
				}
			}
			else
			{
				pen_pos = (gx_vsmj_pen_pos_enum) (PP_OWN_0 + highlight_tile_index);
			}
			highlight_tile_index = -1;
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_up_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_up_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_SPECIAL)
	{
		if (highlight_special == HIGHLIGHT_EAT)
		{
			highlight_eatcase = mmi_gx_vsmj_get_last_eatcase(highlight_eatcase);
		}
        if (highlight_special == HIGHLIGHT_GUN)
        {
            highlight_guncase = mmi_gx_vsmj_get_last_guncase(highlight_guncase);
        }
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_down_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_down_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_SPECIAL)
	{
		if (highlight_special == HIGHLIGHT_EAT)
		{
			highlight_eatcase = mmi_gx_vsmj_get_next_eatcase(highlight_eatcase);
		}
              if (highlight_special == HIGHLIGHT_GUN)
		{
			highlight_guncase = mmi_gx_vsmj_get_next_guncase(highlight_guncase);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_left_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_left_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 hand_tile_count = 0;
	S32 highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_SPECIAL)
	{
		highlight_special = mmi_gx_vsmj_get_last_specialcase(highlight_special);
	}
	else if (game_move == MOVE_DISCARD_TILE && current_user->id == PLAYER_1)
	{
		for (i = 0; i < 18; i++)
		{
			if (current_user->hand[i]->id == WALL_END)
			{
				hand_tile_count = i;
				break;
			}
		}

		highlight_index = mmi_gx_vsmj_get_highlight_tile_index();
		
		if (highlight != &wall_end)
		{
			if (highlight_tile_index == highlight_index)
			{
				if (highlight_index == hand_tile_count - 1)
				{
					highlight_tile_index = hand_tile_count - 2;
				}
				else
				{
					highlight_tile_index = hand_tile_count - 1;
				}
			}
			else if (highlight_tile_index == 0)
			{
				if (highlight_tile_index == highlight_index)
				{
					highlight_tile_index = hand_tile_count - 1;
				}
				else
				{
					highlight_tile_index = highlight_index;
				}
			}
			else 
			{
				highlight_tile_index--;
				if (highlight_tile_index == highlight_index && highlight_index != 0)
				{
						highlight_tile_index--;
				}
			}
		}
		else
		{
			if (highlight_tile_index == 0)
			{
				highlight_tile_index = hand_tile_count - 1;
			}
			else 
			{
				highlight_tile_index--;
			}
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_right_release
 * DESCRIPTION
 *  Key handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_right_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 hand_tile_count = 0;
	S32 highlight_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (game_move == MOVE_PICK_SPECIAL || game_move == MOVE_DISCARD_SPECIAL)
	{
		highlight_special = mmi_gx_vsmj_get_next_specialcase(highlight_special);
	}
	else if (game_move == MOVE_DISCARD_TILE && current_user->id == PLAYER_1)
	{
		for (i = 0; i < 18; i++)
		{
			if (current_user->hand[i]->id == WALL_END)
			{
				hand_tile_count = i;
				break;
			}
		}

		highlight_index = mmi_gx_vsmj_get_highlight_tile_index();
		
		if (highlight != &wall_end)
		{
			if (highlight_tile_index == highlight_index)
			{
				if (highlight_index == 0)
				{
					highlight_tile_index = 1;
				}
				else
				{
					highlight_tile_index = 0;
				}
			}
			else if (highlight_tile_index == hand_tile_count - 1)
			{
				if (highlight_tile_index == highlight_index)
				{
					highlight_tile_index = 0;
				}
				else
				{
					highlight_tile_index = highlight_index;
				}
			}
			else 
			{
				highlight_tile_index++;
				if (highlight_tile_index == highlight_index && highlight_index != hand_tile_count - 1)
				{
					highlight_tile_index++;
				}
			}
		}
		else
		{
			if (highlight_tile_index == hand_tile_count - 1)
			{
				highlight_tile_index = 0;
			}
			else 
			{
				highlight_tile_index++;
			}
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_next_eatcase
 * DESCRIPTION
 *  get index of the next eat case
 * PARAMETERS
 *  eatcase          [IN]   index of the currently eat case
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_next_eatcase(S32 eatcase)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	index = eatcase - HIGHLIGHT_EATCASE_0 + 1;
	for (i = 0; i < 2; i++)
	{
		if (index > 2)
		{
			index = 0;
		}
		
		if (current_user->can_eat[index])
		{
			return (HIGHLIGHT_EATCASE_0 + index);
		}

		index++;
	}
	return eatcase;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_last_eatcase
 * DESCRIPTION
 *  get index of the last eat case
 * PARAMETERS
 *  eatcase          [IN]   index of the currently eat case
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_last_eatcase(S32 eatcase)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	index = eatcase - HIGHLIGHT_EATCASE_0 - 1;
	for (i = 0; i < 2; i++)
	{
		if (index < 0)
		{
			index = 2;
		}
		
		if (current_user->can_eat[index])
		{
			return (HIGHLIGHT_EATCASE_0 + index);
		}

		index--;
	}
	return eatcase;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_next_guncase
 * DESCRIPTION
 *  get index of the next gun case
 * PARAMETERS
 *  guncase          [IN]   index of the currently gun case
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_next_guncase(S32 guncase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = guncase - HIGHLIGHT_GUNCASE_0 + 1;
    for (i = 0; i < 8; i++)
    {
        if (index > 7)
        {
            index = 0;
        }
        
        if (index < 4)
        {
            if (current_user->can_bugun[index])
            {
                return (HIGHLIGHT_GUNCASE_0 + index);
            }
        }
        else
        {
            if (current_user->can_handgun[index - 4])
            {
                return (HIGHLIGHT_GUNCASE_0 + index);
            }
        }  
        
        index++;
    }
    return guncase;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_last_guncase
 * DESCRIPTION
 *  get index of the last gun case
 * PARAMETERS
 *  guncase          [IN]   index of the currently gun case
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_last_guncase(S32 guncase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = guncase - HIGHLIGHT_GUNCASE_0 - 1;
    for (i = 0; i < 8; i++)
    {
        if (index < 0)
        {
            index = 7;
        }
        
        if (index < 4)
        {
            if (current_user->can_bugun[index])
            {
                return (HIGHLIGHT_GUNCASE_0 + index);
            }
        }
        else
        {
            if (current_user->can_handgun[index - 4])
            {
                return (HIGHLIGHT_GUNCASE_0 + index);
            }
        } 
        
        index--;
    }
    return guncase;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_next_specialcase
 * DESCRIPTION
 *  get index of the next special case
 * PARAMETERS
 *  speciacase          [IN]   index of the currently special case
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_next_specialcase(S32 speciacase)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	BOOL state[5];
	S32 specia_case_list[5];
	S32 i;
	S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (current_user->can_eat[0] || current_user->can_eat[1] || current_user->can_eat[2])
	{
		state[0] = TRUE;
	}
	else
	{
		state[0] = FALSE;
	}
	state[1] = current_user->can_pon;
	if (current_user->can_bugun[0] || current_user->can_handgun[0])
	{
		state[2] = TRUE;
	}
	else
	{
		state[2] = FALSE;
	}
	state[3] = current_user->can_hou;
	state[4] = TRUE;

	specia_case_list[0] = HIGHLIGHT_EAT;
	specia_case_list[1] = HIGHLIGHT_PON;
	specia_case_list[2] = HIGHLIGHT_GUN;
	specia_case_list[3] = HIGHLIGHT_HOU;
	specia_case_list[4] = HIGHLIGHT_CANCEL;

	for (i = 0; i < 5; i++)
	{
		if (specia_case_list[i] == speciacase)
		{
			index = i + 1;
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (index > 4)
		{
			index = 0;
		}
		
		if (state[index])
		{
			return (specia_case_list[index]);
		}

		index++;
	}
	return speciacase;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_last_specialcase
 * DESCRIPTION
 *  get index of the last special case
 * PARAMETERS
 *  speciacase          [IN]   index of the currently special case
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_last_specialcase(S32 speciacase)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	BOOL state[5];
	S32 specia_case_list[5];
	S32 i;
	S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (current_user->can_eat[0] || current_user->can_eat[1] || current_user->can_eat[2])
	{
		state[0] = TRUE;
	}
	else
	{
		state[0] = FALSE;
	}
	state[1] = current_user->can_pon;
	if (current_user->can_bugun[0] || current_user->can_handgun[0])
	{
		state[2] = TRUE;
	}
	else
	{
		state[2] = FALSE;
	}
	state[3] = current_user->can_hou;
	state[4] = TRUE;

	specia_case_list[0] = HIGHLIGHT_EAT;
	specia_case_list[1] = HIGHLIGHT_PON;
	specia_case_list[2] = HIGHLIGHT_GUN;
	specia_case_list[3] = HIGHLIGHT_HOU;
	specia_case_list[4] = HIGHLIGHT_CANCEL;

	for (i = 0; i < 5; i++)
	{
		if (specia_case_list[i] == speciacase)
		{
			index = i - 1;
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (index < 0)
		{
			index = 4;
		}
		
		if (state[index])
		{
			return (specia_case_list[index]);
		}

		index--;
		}
	return speciacase;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_get_highlight_tile_index
 * DESCRIPTION
 *  get index of the highlight tile
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_gx_vsmj_get_highlight_tile_index(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < 18; i++)
	{
		if (current_user->hand[i]->id == highlight->id)
		{
			return i;
		}
	}
	return -1;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_sendtile
 * DESCRIPTION
 *  send tile to player & user[1] own_tile pointer array
 *  and make first time sort tiles / clean flowers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_sendtile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 endofsend_index = start_index + 16 * NUM_PLAYER;
    S16 i, j;
    gx_vsmj_tile_id_enum temp_tile_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    j = 0;
    /* send player and user[1] 17,16 tiles */
    while (start_index != endofsend_index)
    {
        tile_table[start_index].pos = POS_HAND;
        user[0].hand[i++] = &tile_table[start_index++];
        tile_table[start_index].pos = POS_HAND;
        user[0].hand[i++] = &tile_table[start_index++];
        tile_table[start_index].pos = POS_HAND;
        user[1].hand[j++] = &tile_table[start_index++];
        tile_table[start_index].pos = POS_HAND;
        user[1].hand[j++] = &tile_table[start_index++];
    }
    tile_table[start_index].pos = POS_HAND;
	if (banker == PLAYER_1)
	{
		user[0].hand[i++] = &tile_table[start_index++];
	}
	else
	{
		user[1].hand[j++] = &tile_table[start_index++];
	}
    /* send user[0] and user[1] 17,16 tiles */

    user[0].hand[i++] = &wall_end;
    user[1].hand[j++] = &wall_end;

    i = 0;
    j = 0;

    while (1)
    {
        j = 0;  /* store totalreplenish times in this turn */
        for (i = 0; i < NUM_PLAYER; i++)
        {
            for (temp_tile_id = FL_SPRING; temp_tile_id <= FL_J; temp_tile_id++)
            {
                if (mmi_gx_vsmj_find_no_with_tile_id(temp_tile_id, user[i].hand) != -1)
                {
                    user[i].hand[mmi_gx_vsmj_find_no_with_tile_id(temp_tile_id, user[i].hand)]->pos = POS_HIGH;
                    mmi_gx_vsmj_insert_tile(
                        user[i].hand[mmi_gx_vsmj_find_no_with_tile_id(temp_tile_id, user[i].hand)],
                        user[i].flower);
                    mmi_gx_vsmj_eliminate_tile(temp_tile_id, user[i].hand);
                    mmi_gx_vsmj_insert_tile(&tile_table[end_index--], user[i].hand);
                    j++;
                }
            }
        }
        if (j == 0) /* all done */
        {
            break;
        }
    }

    /* first time sort hand ptrs  */
    for (i = 0; i < NUM_PLAYER; i++)
    {
        mmi_gx_vsmj_sort_tile(user[i].hand);
    }
    /* first time sort hand ptrs */

}

#endif /* IS_VSMJ_BASE_GAME */ 


#ifdef VSMJ_DEBUG_ON
/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_1_release
 * DESCRIPTION
 *  set tile of the player to debug
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_1_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
	S32 max_case = 8;
	gx_vsmj_tile_id_enum ting_case[8][16] = 
	{
        {NU_1W, NU_1W, NU_1W, NU_1W, NU_2W, NU_2W, NU_2W, NU_2W, NU_3W, NU_3W, NU_3W, NU_3W, NU_4W, NU_4W, NU_4W, NU_4W},
		{NU_1W, NU_1W, NU_1W, NU_2W, NU_2W, NU_2W, NU_3W, NU_3W, NU_3W, NU_4W, NU_4W, NU_5W, NU_5W, NU_6W, NU_6W, NU_7W},
		{NU_1W, NU_1W, NU_1W, NU_2W, NU_2W, NU_2W, NU_3W, NU_3W, NU_3W, NU_4W, NU_4W, NU_4W, NU_5W, NU_5W, NU_6W, NU_7W},
		{NU_1W, NU_1W, NU_1W, NU_2W, NU_2W, NU_2W, NU_3W, NU_3W, NU_3W, NU_4W, NU_4W, NU_4W, NU_5W, NU_5W, NU_5W, NU_6W},
	    {TE_CHUNG, TE_CHUNG, TE_CHUNG, TE_FA, TE_FA, TE_FA, TE_BAI, TE_BAI, TE_BAI, NU_4W, NU_4W, NU_4W, NU_5W, NU_5W, NU_5W, NU_6W},
		{TE_EAST, TE_EAST, TE_EAST, TE_SOUTH, TE_SOUTH, TE_SOUTH, TE_WEST, TE_WEST, TE_WEST, TE_NORTH, TE_NORTH, TE_NORTH, NU_5W, NU_5W, NU_5W, NU_6W},
		{TE_CHUNG, TE_CHUNG, TE_CHUNG, TE_FA, TE_FA, TE_FA, TE_BAI, TE_BAI, NU_4W, NU_4W, NU_4W, NU_5W, NU_5W, NU_5W, NU_6W, NU_7W},
		{TE_EAST, TE_EAST, TE_EAST, TE_SOUTH, TE_SOUTH, TE_SOUTH, TE_WEST, TE_WEST, TE_WEST, TE_NORTH, TE_NORTH, NU_5W, NU_5W, NU_5W, NU_6W, NU_7W}
	};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < 16; i++)
	{
		user[0].hand[i]->id = ting_case[debug_case][i];
	}
	debug_case++;
	if (debug_case >= max_case)
	{
		debug_case = 0;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_2_release
 * DESCRIPTION
 *  to be used debug, set player's flower tile is CXQD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_2_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 4; i++)
    {
		user[0].flower[i] = &tile_table[112 + i];
        user[0].flower[i]->id = FL_SPRING + i;
		user[0].flower[i]->pos = POS_DESK;
    }
	user[0].flower[4] = &wall_end;
    user[1].flower[0] = &wall_end;
    for (i = 0; i < 40; i++)
    {
        if (tile_table[i].id >= FL_SPRING && tile_table[i].id <= FL_J)
        {
            tile_table[i].id = NU_7W;
        }
    }
	tile_table[40].id = NU_7W;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_gx_vsmj_key_3_release
 * DESCRIPTION
 *  to be used debug, set player's flower tile is MLZJ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_vsmj_key_3_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 4; i++)
    {
		user[0].flower[i] = &tile_table[112 + i];
        user[0].flower[i]->id = FL_M + i;
		user[0].flower[i]->pos = POS_DESK;
    }
	user[0].flower[4] = &wall_end;
    user[1].flower[0] = &wall_end;
    for (i = 0; i < 40; i++)
    {
        if (tile_table[i].id >= FL_SPRING && tile_table[i].id <= FL_J)
        {
            tile_table[i].id = NU_7W;
        }
    }
	tile_table[40].id = NU_7W;
}
#endif 

