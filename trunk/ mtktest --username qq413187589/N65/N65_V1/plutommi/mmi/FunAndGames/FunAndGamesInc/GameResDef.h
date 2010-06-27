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
 *  GameResDef.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game Defines
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef GAME_RES_DEF_H
#define GAME_RES_DEF_H

#include "MMI_features.h"
#include "MMIDataType.h"

/* define game base ID */
/* (GAME_BASE) - (GAME_BASE + 99) is reserved for game.c */

#define GAME_FRAMEWORK                       GAME_BASE + 100

#define GAME_SNAKE_BASE                      GAME_BASE + 150    /* GAME_BASE defined in MMIDataType.h */
#define GAME_F1RACE_BASE                     GAME_BASE + 250
#define GAME_TOH_BASE                        GAME_BASE + 350
#define GAME_RICHES_BASE                     GAME_BASE + 400
#define GAME_COLORBALLS_BASE                 GAME_BASE + 500
#define GAME_SMASH_BASE                      GAME_BASE + 600
#define GAME_DOLL_BASE                       GAME_BASE + 700
#define GAME_MAJUNG_BASE                     GAME_BASE + 800    /* !! Majung needs 150 id for images */
#define GAME_COPTER_BASE                     GAME_BASE + 1050
#define GAME_PUZZLE_BASE                     GAME_BASE + 1100    /* !! Puzzle needs 100 id for images */
#define GAME_PANDA_BASE                      GAME_BASE + 1200
#define GAME_STAIR_BASE                      GAME_BASE + 1300
#define GAME_UFO_BASE                        GAME_BASE + 1400   /* !! Ufo need 100 id for images */
#define GAME_DANCE_BASE                      GAME_BASE + 1500
#define GAME_MAGICSUSHI_BASE                 GAME_BASE + 1600   /* !! magicsushi need 100 id for images */
#define GAME_FRUIT_BASE                      GAME_BASE + 1700   /* !! Fruit need 100 id for images */
#define GAME_VSMJ_BASE                       GAME_BASE + 1800   /* !! VSMJ need 150 id for images */

/* Motion App */
#define MOTIONE_BASE                         GAME_BASE + 2000
#define MOTION_DICE_BASE                     GAME_BASE + 2100   /* reserve 200 */
#define MOTION_DJ_BASE                       GAME_BASE + 2300   /* reserve 100 */


/* Game effect */
/* comment this if you dont want game effect */
#define GAME_AUDIO_ENABLE
#define GAME_VIBRATOR_ENABLE

/* Game define Macro */
#if defined(__MMI_GAME_F1RACE__)
#define IS_F1RACE_BASE_GAME
#endif 

#if defined(__MMI_GAME_HANOI__)
#define IS_HANOI_BASE_GAME
#endif 

#if defined(__MMI_GAME_RICHES__)
#define IS_RICHES_BASE_GAME
#endif 

#if defined(__MMI_GAME_COLORBALLS__)
#define IS_COLORBALL_BASE_GAME
#endif 

#if defined(__MMI_GAME_SNAKE__)
#define IS_SNAKE_BASE_GAME
#endif 

#if defined(__MMI_GAME_SMASH__)
#define IS_SMASH_BASE_GAME
#endif 

#if defined(__MMI_GAME_DOLL__)
#define IS_DOLL_BASE_GAME
#endif 

#if defined(__MMI_GAME_MAJUNG_240x320__) || defined(__MMI_GAME_MAJUNG_176x220__) || defined(__MMI_GAME_MAJUNG_320x240__)
#define IS_MAJUNG_BASE_GAME
#endif 

#if defined(__MMI_GAME_DANCE_176x220__)
#define IS_DANCE_BASE_GAME
#endif 

#if defined(__MMI_GAME_COPTER_128x128__) || defined(__MMI_GAME_COPTER_128x160__) || defined(__MMI_GAME_COPTER_176x220__) || defined(__MMI_GAME_SUBMARINE_128x128__) || defined(__MMI_GAME_SUBMARINE_128x160__) || defined(__MMI_GAME_SUBMARINE_176x220__) || defined(__MMI_GAME_JET_128x128__) || defined(__MMI_GAME_JET_128x160__) || defined(__MMI_GAME_JET_176x220__)
#define IS_COPTER_BASE_GAME
#endif 

#if defined(__MMI_GAME_PUZZLE_128x128__) || defined(__MMI_GAME_PUZZLE_128x160__) || defined(__MMI_GAME_PUZZLE_176x220__) || defined(__MMI_GAME_PUZZLE_240x320__)  || defined(__MMI_GAME_PUZZLE_320x240__)
#define IS_PUZZLE_BASE_GAME
#endif 

#if defined(__MMI_GAME_PANDA_128x128__) || defined(__MMI_GAME_PANDA_128x160__) || defined(__MMI_GAME_PANDA_176x220__) || defined(__MMI_GAME_MONKEY_128x128__) || defined(__MMI_GAME_MONKEY_128x160__) || defined(__MMI_GAME_MONKEY_176x220__)
#define IS_PANDA_BASE_GAME
#endif 

#if defined(__MMI_GAME_CHICKEN_128x160__) || defined(__MMI_GAME_CHICKEN_128x128__) || defined(__MMI_GAME_ROBOT_176x220__) || defined(__MMI_GAME_ROBOT_128x160__)
#define IS_STAIR_BASE_GAME
#endif 

#if defined(__MMI_GAME_UFO_128x128__) || defined(__MMI_GAME_UFO_128x160__) || defined(__MMI_GAME_UFO_176x220__)
#define IS_UFO_BASE_GAME
#endif 

#if defined(__MMI_GAME_MAGICSUSHI_240x320__) || defined(__MMI_GAME_MAGICSUSHI_320x240__)
#define IS_MAGICSUSHI_BASE_GAME
#endif 

#if defined(__MMI_GAME_FRUIT_176x220__)
#define IS_FRUIT_BASE_GAME
#endif 

#if defined(__MMI_GAME_VSMJ_240x320__) ||defined(__MMI_GAME_VSMJ_320x240__) 
#define IS_VSMJ_BASE_GAME
#endif 

#if defined(__MMI_MOTIONGAME_DICE_128x160__) || defined(__MMI_MOTIONGAME_DICE_176x220__) || defined(__MMI_MOTIONGAME_DICE_220x320__)
#define IS_DICE_BASE_MOTIONGAME
#endif 

#if defined(__MMI_MOTIONGAME_DJ_128x160__) || defined(__MMI_MOTIONGAME_DJ_176x220__) || defined(__MMI_MOTIONGAME_DJ_220x320__)
#define IS_DJ_BASE_MOTIONGAME
#endif 

/* Screen ID */
typedef enum
{
    SCR_ID_GAME = GAME_BASE + 1,
    SCR_ID_GAME_SETTING,
    SCR_ID_MOTION_APP,
    SCR_ID_3D_GAME_LIST,
    SCR_ID_3D_GAME
} mmi_game_scr_id_enum;

/* String ID */
typedef enum
{
    STR_GAME_CAPTION = GAME_BASE + 1,
    STR_GAME_LSK,
    STR_GAME_NEW,
    STR_GAME_LEVEL,
    STR_GAME_GRADE,
    STR_GAME_HELP,
    STR_GAME_RESUME,
    STR_GAME_RESET,
    STR_GAME_SCORE,
    STR_MENU3105_GAMES,
    STR_ID_GAME_SETTING,
    STR_ID_GAME_SETTING_AUD,
    STR_ID_GAME_SETTING_MULTICHANNEL_BACKGROUND_MUSIC,
    STR_ID_GAME_SETTING_MULTICHANNEL_SOUND_EFFECT,
    STR_ID_GAME_SETTING_VIB,

    STR_ID_MOTION_APP,
    STR_ID_3D_GAME,
    STR_ID_3D_GAME_TERMINATE_JAVA,

    /* 3D Games */
    STR_ID_3D_GAME_BROGENT_GOGOROBOT,
    STR_ID_3D_GAME_BROGENT_HEATBREAKER2,
    STR_ID_3D_GAME_INTERGRAFX_DEMOGAME,
    STR_ID_3D_GAME_INTERGRAFX_PETFISH,
    STR_ID_3D_GAME_INTERGRAFX_ROLLINGBALL
} mmi_game_str_id_enum;

typedef enum
{
    IMG_MENU3105_GAMES = GAME_BASE + 1,
    IMG_ID_GAME_SUBLCD_ICON,
    IMG_ID_GAME_SETTING,
    IMG_ID_GAME_SETTING_AUD,
    IMG_ID_GAME_SETTING_BACK_AUD,   /* /for background sound */
    IMG_ID_GAME_SETTING_VIB,
    IMG_ID_MOTION_APP,
    IMG_ID_3D_GAME,

    /* 3D Games */
    IMG_ID_3D_GAME_BROGENT_GOGOROBOT,
    IMG_ID_3D_GAME_BROGENT_HEATBREAKER2,
    IMG_ID_3D_GAME_INTERGRAFX_DEMOGAME,
    IMG_ID_3D_GAME_INTERGRAFX_PETFISH,
    IMG_ID_3D_GAME_INTERGRAFX_ROLLINGBALL
} mmi_game_img_id_enum;

#endif /* GAME_RES_DEF_H */ 

