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
 * GameTemplate.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *  Game Template function.
 *
 *  EX:  Replace TEMPLATE with SNAKE
 *       Replace templae with snake       
 *       Replace Tamplate with Snake
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 *                Game Template Usage Description                    
 *******************************************************************************
 * (1) The Template contains three files.                         
 *    GameTemplate.C", GameTemplateDefs.h, GameTemplateProts.h          
 *
 * (2) Change file names to Xxxxx.c XxxxxDefs.h, XxxxxxProts.h. Xxxxx is game name.
 *                                                          
 * (3) Simply replace the following string with your game name.                     
 *    TEMPLATE with XXXXXX (XXXX is the game name in caption)           
 *    Template with Xxxxxx                                        
 *    template with xxxxxx                                           
 *                                                                
 * (4) Create NVRAM slot in NVRAMEnum.h to store game grade and current game level.
 *    Set those IDs in XXXXX_Enter_GFX( ) where to replace DUMMY_NVRAM_ID.
 *    The grade should be short and index should be byte.
 *
 * (5) Write generate resouce related code in RES_Game.c
 *
 * (6) Add entry point in Game.c
 *
 * (7) Add __MMI_GAME_XXXXXX__ in "MMI_features.h" if you wish to enable this game.
 *
 * (8) Remember to re-generate resource.
 *******************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_GX_TEMPLATE_C
#define _MMI_GX_TEMPLATE_C

#ifdef __MMI_GAME_TEMPLATE__

#include "GameInc.h"
#include "TemplateProts.h"
#include "TemplateResDef.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_STR_ID    (0)
#define DUMMY_IMG_ID    (0)
#define DUMMY_NVRAM_ID  (0)

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* game context */
typedef struct
{
    BOOL is_gameover;
    BOOL is_new_game;
    U8 game_level;
    S16 game_grade;
    U16 timer_elapse;
} gx_template_context_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
gx_template_context_struct g_gx_template_context = 
{
    FALSE,  /* is_gameover */
    TRUE,   /* is_new_game */
    0,      /* game_level */
    0,      /* game_grade */
    100     /* timer_elapse */
};

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Game framework related functions */
S16 mmi_gx_template_calc_best_grade(S16 old_grade, S16 new_grade);      /* descide which is best grade */
void mmi_gx_template_enter_game(void);      /* entry function of the game */
void mmi_gx_template_exit_game(void);       /* exit function - usually will stop timer and release buffer */
void mmi_gx_template_draw_gameover(void);   /* draw gameover screen */

/* Game play functions */
void mmi_gx_template_framemove(void);
void mmi_gx_template_render(void);
void mmi_gx_template_gameover(void);
void mmi_gx_template_cyclic_timer(void);
void mmi_gx_template_init_game(void);   /* draw gameover screen */


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_enter_gfx
 * DESCRIPTION
 *  Set Game Framework (GFX) Parameter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_enter_gfx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Game menu */
    GFX.game_data.game_img_id = IMG_ID_GX_TEMPLATE_GAME_ICON;   /* game icon img ID */
    GFX.game_data.game_str_id = STR_ID_GX_TEMPLATE_GAME_NAME;   /* game name string ID */
    GFX.game_data.menu_resume_str_id = STR_ID_GX_TEMPLATE_RESUME;       /* "Resume" string ID */
    GFX.game_data.menu_new_str_id = STR_ID_GX_TEMPLATE_NEW; /* "New Game" string ID */
    GFX.game_data.menu_level_str_id = STR_ID_GX_TEMPLATE_LEVEL; /* "Game Level" string ID */
    GFX.game_data.menu_grade_str_id = STR_ID_GX_TEMPLATE_SCORE; /* "Best Grade" string ID */
    GFX.game_data.menu_help_str_id = STR_ID_GX_TEMPLATE_HELP;   /* "Game Help" string ID */

    /* level / grade */
    GFX.game_data.level_count = 3;  /* how many levels */
    GFX.game_data.level_str_id_list[0] = STR_ID_GX_TEMPLATE_LEVEL_EASY; /* level string ID */
    GFX.game_data.level_str_id_list[1] = STR_ID_GX_TEMPLATE_LEVEL_NORMAL;       /* level string ID */
    GFX.game_data.level_str_id_list[2] = STR_ID_GX_TEMPLATE_LEVEL_HARD; /* level string ID */

    /* add slot in NVRAMEnum.h */
    GFX.game_data.grade_nvram_id_list[0] = DUMMY_NVRAM_ID;  /* grade slot in NVRAM (short) */
    GFX.game_data.grade_nvram_id_list[1] = DUMMY_NVRAM_ID;  /* grade slot in NVRAM */
    GFX.game_data.grade_nvram_id_list[2] = DUMMY_NVRAM_ID;  /* grade slot in NVRAM */
    GFX.game_data.level_nvram_id = DUMMY_NVRAM_ID;          /* current lvl idnex  in NVRAM (byte) */

    /* help */
    GFX.game_data.help_str_id = STR_ID_GX_TEMPLATE_HELP_DESCRIPTION;    /* help desciption string id */

    /* misc */
    GFX.game_data.grade_value_ptr = (S16*) (&g_gx_template_context.game_grade);        /* current level's grade (S16*) */
    GFX.game_data.level_index_ptr = (U8*) (&g_gx_template_context.game_level); /* ptr to current level index (U8*) */
    GFX.game_data.is_new_game = (BOOL*) (&g_gx_template_context.is_new_game);  /* ptr to new game flag (BOOL*) */

    /* function ptr */
    GFX.game_data.best_grade_func_ptr = mmi_gx_template_calc_best_grade;        /* function to calculate best grade */
    GFX.game_data.enter_game_func_ptr = mmi_gx_template_enter_game;     /* function to enter new game */
    GFX.game_data.exit_game_func_ptr = mmi_gx_template_exit_game;       /* function to exit game */
    GFX.game_data.draw_gameover_func_ptr = mmi_gx_template_draw_gameover;       /* function to draw gameover screen */

    /* some flags */
    GFX.game_data.is_keypad_audio_enable = FALSE;   /* play keypad tone or not */

    mmi_gfx_entry_menu_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_calc_best_grade
 * DESCRIPTION
 *  Calculate new best grade [Callback required by GFX]
 * PARAMETERS
 *  old_grade       [IN]        
 *  new_grade       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_gx_template_calc_best_grade(S16 old_grade, S16 new_grade)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* compare the best grade and return it */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_draw_gameover
 * DESCRIPTION
 *  Draw Gameover Screen [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_draw_gameover(void)
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
 *  mmi_gx_template_enter_game
 * DESCRIPTION
 *  Enter Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_enter_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_gx_template_context.is_new_game == TRUE)
    {
        mmi_gx_template_init_game();    /* is new game, otherwise resume game */
    }

    g_gx_template_context.is_new_game = FALSE;
    g_gx_template_context.is_gameover = FALSE;

    /* start game loop */
    mmi_gx_template_cyclic_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_exit_game
 * DESCRIPTION
 *  Exit Game [Callback required by GFX]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_exit_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_gx_template_cyclic_timer); /* cancle the looping timer */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_init_game
 * DESCRIPTION
 *  Game initilization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_init_game(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init game here */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_framemove
 * DESCRIPTION
 *  Framemove - process the game logic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_framemove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add logic code here */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_render
 * DESCRIPTION
 *  Render the game images
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_render(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add drawing code here */

    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_gameover
 * DESCRIPTION
 *  Gameover function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_gameover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gx_template_context.is_gameover = TRUE;
    g_gx_template_context.is_new_game = TRUE;

    /* call this function to draw gameover screen */
    mmi_gfx_entry_gameover_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_gx_template_cyclic_timer
 * DESCRIPTION
 *  Timer trigger function - looping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_gx_template_cyclic_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(g_gx_template_context.timer_elapse, mmi_gx_template_cyclic_timer);

    if (g_gx_template_context.is_gameover == FALSE)
    {
        mmi_gx_template_framemove();
        mmi_gx_template_render();
    }
}

#endif /* __MMI_GAME_TEMPLATE__ */ 
#endif /* _MMI_GX_TEMPLATE_C */ 

