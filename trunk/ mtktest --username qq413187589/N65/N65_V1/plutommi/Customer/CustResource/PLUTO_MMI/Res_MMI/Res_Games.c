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
 *	 Res_Game.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Game Resource
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "CustomCfg.h"

#include "MMI_features.h"

#ifdef __MMI_GAME__

#include "FunAndGamesResDef.h"
#include "GameResDef.h"

#ifdef IS_F1RACE_BASE_GAME
/* under construction !*/
#endif /* IS_F1RACE_BASE_GAME */

#ifdef IS_HANOI_BASE_GAME
/* under construction !*/
#endif /* IS_HANOI_BASE_GAME */

#ifdef IS_RICHES_BASE_GAME
#include "RichesResDef.h"
#endif /* IS_RICHES_BASE_GAME */

#ifdef IS_COLORBALL_BASE_GAME
/* under construction !*/
#endif /* IS_COLORBALL_BASE_GAME */

#ifdef IS_SNAKE_BASE_GAME
/* under construction !*/
#endif /* IS_SNAKE_BASE_GAME */

#ifdef IS_SMASH_BASE_GAME
/* under construction !*/
#endif /* IS_SMASH_BASE_GAME */

#ifdef IS_DOLL_BASE_GAME
/* under construction !*/
#endif /* IS_DOLL_BASE_GAME */

#ifdef IS_MAJUNG_BASE_GAME
#include "MajungResDef.h"
#endif /* IS_MAJUNG_BASE_GAME */

#ifdef IS_COPTER_BASE_GAME
/* under construction !*/
#endif /* IS_COPTER_BASE_GAME */
		 
#ifdef IS_PUZZLE_BASE_GAME
#include "PuzzleResDef.h"
#endif /* IS_PUZZLE_BASE_GAME */

#ifdef IS_PANDA_BASE_GAME
/* under construction !*/
#endif /* IS_PANDA_BASE_GAME */

#ifdef IS_STAIR_BASE_GAME
/* under construction !*/
#endif /* IS_STAIR_BASE_GAME */

#ifdef IS_UFO_BASE_GAME 
/* under construction !*/
#endif /* IS_UFO_BASE_GAME */

#ifdef IS_DANCE_BASE_GAME
/* under construction !*/
#endif /* IS_DANCE_BASE_GAME */

#ifdef IS_MAGICSUSHI_BASE_GAME
#include "MagicsushiResDef.h"
#endif /* IS_MAGICSUSHI_BASE_GAME */

#ifdef IS_FRUIT_BASE_GAME
#include "FruitResDef.h"
#endif /* IS_FRUIT_BASE_GAME */

#ifdef IS_VSMJ_BASE_GAME
#include "VsmjResDef.h"
#endif /* IS_VSMJ_BASE_GAME */

#include "PopulateRes.h"
#include "CustResDef.h"


/************************************************************************/
/* Dance                																*/		
/************************************************************************/
#ifdef IS_DANCE_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
/* under construction !*/
#endif /* IS_DANCE_BASE_GAME */


#ifdef IS_DOLL_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_DOLL_BASE_GAME */

/************************************************************************/
/* F1 Race																*/		
/************************************************************************/
#ifdef __MMI_GAME_F1RACE__
void PopulateF1RaceRes(void)
{
	/* Create Strings */ 
	ADD_APPLICATION_STRING2(STR_GX_F1RACE_GAME_NAME,"F1 Race","Caption String");
	ADD_APPLICATION_STRING2(STR_GX_F1RACE_HELP_DESCRIPTION, "(1)Avoid to hit other cars.\n(2)Use button 2,4,6,8 to control the car and 5 to fly.\n(3)Run over a car will charge the fly power." ,"F1 race help");

	/* resources for F1Race game kernal */
	ADD_APPLICATION_IMAGE2(IMG_GX_F1RACE_GAME_ICON,				CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\Race.BMP","Games image");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_PLAYER_CAR,				CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_PLAYER_CAR_FLY,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_PLAYER_CAR_FLY_DOWN,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY_DOWN.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_PLAYER_CAR_FLY_UP,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_FLY_UP.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_PLAYER_CAR_CRASH,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_CRASH.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_0,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_0.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_1,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_1.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_2,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_2.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_3,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_3.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_4,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_4.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_5,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_5.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_OPPOSITE_CAR_6,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_OPPOSITE_CAR_6.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_PLAYER_CAR_HEAD_LIGHT,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_PLAYER_CAR_HEAD_LIGHT.GIF");

	/* status misc*/
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_LOGO,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_LOGO.BMP");
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_SCORE,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_SCORE.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_LEVEL,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_LEVEL.GIF");
#endif
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_BOX,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_BOX.GIF");
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_FLY,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_STATUS_FLY.GIF");
#endif

	/* number */
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_0, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_0.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_1, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_1.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_2, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_2.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_3, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_3.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_4, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_4.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_5, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_5.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_6, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_6.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_7, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_7.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_8, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_8.gif");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_NUMBER_9, CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\GAME_F1RACE_NUMBER_9.gif");

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_GX_F1RACE_GOTEXT,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\gameover.bmp",	"Riches Image");
#endif
	ADD_APPLICATION_IMAGE2(IMG_GX_F1RACE_GRADESMAP,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\gradesmap.bmp",	"Riches Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_F1RACE_GOPIC,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\gameover\\\\pic.bmp",		"Riches Image");

#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE0,  CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_SCORE.gif");
        ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_LEVEL_LANGUAGE0,    CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_LEVEL.GIF");
        ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_FLY_LANGUAGE0,       CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_FLY.GIF");
        ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_GOTEXT_LANGUAGE0,              CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\gameover.bmp");

	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_SCORE_LANGUAGE1,   CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_SCORE_C.GIF");
        ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_LEVEL_LANGUAGE1,    CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_LEVEL_C.GIF");
	ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_STATUS_FLY_LANGUAGE1,      CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\GAME_F1RACE_STATUS_FLY_C.GIF");
        ADD_APPLICATION_IMAGE(IMG_GX_F1RACE_GOTEXT_LANGUAGE1,              CUST_IMG_BASE_PATH"\\\\GameImages\\\\f1race\\\\multi_lan\\\\gameover_C.bmp");
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
}
#endif /* __MMI_GAME_F1RACE__ */



/************************************************************************/
/* Smash																*/	
/************************************************************************/
#ifdef __MMI_GAME_SMASH__
void PopulateSmashRes(void)
{
	/* Smash String */
	ADD_APPLICATION_STRING2(STR_GX_SMASH_GAME_NAME, "Smash","Smash Game Name");
	ADD_APPLICATION_STRING2(STR_GX_SMASH_TIME_SEC,	"sec","#NO_TRANS# String displayed in Time Bar for seconds");
	ADD_APPLICATION_STRING2(STR_GX_SMASH_NORMAL,	"Normal","String displayed in Level Normal");
	ADD_APPLICATION_STRING2(STR_GX_SMASH_SPEEDY,	"Speedy","String displayed in Level Speedy");
	ADD_APPLICATION_STRING2(STR_GX_SMASH_ACCURACY,	"Accuracy","String displayed in Level Accuracy");
	ADD_APPLICATION_STRING2(STR_GX_SMASH_HELP_DESCRIPTION,"The Smash contains 3 mini games.\n(1)Normal game. Hit the animals, but not the skeleton.\n(2)Speedy game. Hit as fast as you can.\n(3)Accuracy game. Hit the designate ones.","actual help string for smash game");

	/* Smash Images */

	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_GAME_ICON,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\smash.BMP", "Smash Game Bg 0" );

	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_0,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_0.pbm", "Smash Game Bg 0" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_2,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_2.pbm", "Smash Game Bg 2" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_3,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_3.pbm", "Smash Game Bg 3" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_4,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_4.pbm", "Smash Game Bg 4" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_5,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_5.pbm", "Smash Game Bg 5" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_6,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_6.pbm", "Smash Game Bg 6" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_7,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_7.pbm", "Smash Game Bg 7" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_8,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_8.pbm", "Smash Game Bg 8" );
	
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_MOUSE_0,	 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_01.pbm", "Smash Game Mouse" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_MOUSE_1,	 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_02.pbm", "Smash Game Mouse" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_MOUSE_2,	 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_03.pbm", "Smash Game Mouse" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_MOUSE_3,	 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_04.pbm", "Smash Game Mouse" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_MOUSE_4,	 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_05.pbm", "Smash Game Mouse" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_MOUSE_5,	 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\mouse\\\\m_06.pbm", "Smash Game Mouse" );

	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_COW_0,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_01.pbm", "Smash Game Cow" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_COW_1,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_02.pbm", "Smash Game Cow" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_COW_2,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_03.pbm", "Smash Game Cow" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_COW_3,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_04.pbm", "Smash Game Cow" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_COW_4,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_05.pbm", "Smash Game Cow" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_COW_5,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\cow\\\\c_06.pbm", "Smash Game Cow" );

	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BONE_0,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_01.pbm", "Smash Game Bone" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BONE_1,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_02.pbm", "Smash Game Bone" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BONE_2,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_03.pbm", "Smash Game Bone" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BONE_3,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_04.pbm", "Smash Game Bone" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BONE_4,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_05.pbm", "Smash Game Bone" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BONE_5,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bone\\\\b_06.pbm", "Smash Game Bone" );

	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_PIG_0,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_01.pbm", "Smash Game pig" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_PIG_1,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_02.pbm", "Smash Game pig" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_PIG_2,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_03.pbm", "Smash Game pig" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_PIG_3,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_04.pbm", "Smash Game pig" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_PIG_4,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_05.pbm", "Smash Game pig" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_PIG_5,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\pig\\\\p_06.pbm", "Smash Game pig" );

	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_HAND_0,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\hand\\\\hand01.pbm", "Smash Game hand" );
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_HAND_1,		 CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\hand\\\\hand03.pbm", "Smash Game hand" );
	
	
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_GRADESMAP,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gradesmap.bmp",	"Smash Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_GOPIC,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\pic.bmp","Smash Image");

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_BG_1,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_1.pbm", "Smash Game Bg 1" ); 
       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_HITTHIS,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\hitthis.gif", "Hitthis" ); 
       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_GOTEXT,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gameover.bmp",	"Smash Image"); 
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_SCORE_LANGUAGE0,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\bg_1.pbm", "Smash Game Bg 1" ); 
       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_HITTHIS_LANGUAGE0, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\bg\\\\hitthis.gif", "Hitthis" ); 
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_GOTEXT_LANGUAGE0,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\gameover\\\\gameover.bmp",	"Smash Image");

       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_SCORE_LANGUAGE1, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\bg_1_C.pbm", "Hitthis" ); 
       ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_HITTHIS_LANGUAGE1, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\hitthis_C.gif", "Hitthis" ); 
	ADD_APPLICATION_IMAGE2(IMG_GX_SMASH_GOTEXT_LANGUAGE1,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Smash\\\\multi_lan\\\\gameover_C.bmp",	"Smash Image");  
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

}	
#endif /* __MMI_GAME_SMASH__ */

	


/************************************************************************/
/* Riches																					*/	
/************************************************************************/
#ifdef IS_RICHES_BASE_GAME
void PopulateRichesRes(void)
{
	ADD_APPLICATION_STRING2(STR_GX_RICHES_GAME_NAME, "Riches", "STR_RICHES_MAIN_CAPTION");

	ADD_APPLICATION_STRING2(STR_GX_RICHES_EASY,		"Easy",		"Easy" );
	ADD_APPLICATION_STRING2(STR_GX_RICHES_NORMAL,	"Normal",	"Normal" );
	ADD_APPLICATION_STRING2(STR_GX_RICHES_HARD,		"Hard",		"Hard" );

	ADD_APPLICATION_STRING2(STR_GX_RICHES_HELP_DESCRIPTION,	"Catch correct falling objects, otherwise will lose score and power.\nUse Key 4 and 6 to move the box left and right.", "HELP Details" );


	/* images */
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_GAME_ICON,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\riches.bmp", "Riches icon" );

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BASKET,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\basket.bmp", "Riches Basket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_APPLE,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\apple.bmp", "Riches Apple" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_BOMB,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bomb.bmp", "Riches Bomb" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_GIFT,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\gift.bmp", "Riches Gift" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_GOLDNOTE,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\goldnote.bmp", "Riches Gold" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_SPIDER,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\spider.bmp", "Riches Spider" );

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_ANGLE,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\angel.bmp", "Riches Buck" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_BATTERY20,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bluebattery.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_DENONATOR,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\detonator.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_EVIL,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\evil.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_MONEY,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\money.bmp", "Riches Bucket" );

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_BATTERYFULL,CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\redbattery.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_THEIF,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\thief.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_ENERGYBG,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\energybg.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_ENERGYBAR,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\enerygybar.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_BAT,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\picture\\\\bat.bmp", "Riches Bucket" );

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_ENERGY20,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\1.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_ENERGY40,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\2.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_ENERGY60,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\3.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_ENERGY80,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\4.bmp", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_ENERGY100,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\energy\\\\5.bmp", "Riches Bucket" );

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_OBJECT_LEVEL,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\level\\\\basket.bmp", "Riches Bucket" );
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND,		CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\bg.gif", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_TIMER,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\timer.gif", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_LEVEL,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\level.gif", "Riches Bucket" );

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_GOTEXT,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\gameover.bmp",	"Riches Image");
#endif
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_GRADESMAP,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\gradesmap.bmp",	"Riches Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_GOPIC,				CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\gameover\\\\pic.bmp",		"Riches Image");

#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_LANGUAGE0,               CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\bg.gif", "Riches Bucket" );
    	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_TIMER_LANGUAGE0,    CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\timer.gif", "Riches Bucket" );
    	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_LEVEL_LANGUAGE0,     CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\\map\\\\level.gif", "Riches Bucket" );
    	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_GOTEXT_LANGUAGE0,                         CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\multi_lan\\\\gameover.bmp",	"Riches Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_LANGUAGE1,               CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\multi_lan\\\\bg_C.gif", "Riches Bucket" );
    	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_TIMER_LANGUAGE1,    CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\multi_lan\\\\timer_C.gif", "Riches Bucket" );
	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_BACKGROUND_LEVEL_LANGUAGE1,     CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\multi_lan\\\\level_C.gif", "Riches Bucket" );
    	ADD_APPLICATION_IMAGE2(IMG_GX_RICHES_GOTEXT_LANGUAGE1,                        CUST_IMG_BASE_PATH"\\\\GameImages\\\\Riches\\\multi_lan\\\\gameover_C.bmp",	"Riches Image");
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
}
#endif /* IS_RICHES_BASE_GAME */



/************************************************************************/
/* Snake																						*/		
/************************************************************************/
#ifdef IS_SNAKE_BASE_GAME 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_SNAKE_BASE_GAME */




/************************************************************************/
/* Tower of Hanoi																			*/	
/************************************************************************/
#ifdef IS_HANOI_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_HANOI_BASE_GAME */




/************************************************************************/
/* ColorBalls																				*/	
/************************************************************************/
#ifdef IS_COLORBALL_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_COLORBALL_BASE_GAME */

/************************************************************************/
/* Majung 128x96,176x220,240x320 Game																	*/	
/************************************************************************/
#ifdef IS_MAJUNG_BASE_GAME
void PopulateMajungRes(void)
{
/* set the base path */

#if defined(__MMI_GAME_MAJUNG_176x220__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_176x220_majung\\\\"
#elif defined(__MMI_GAME_MAJUNG_240x320__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_240x320_majung\\\\"
#elif defined(__MMI_GAME_MAJUNG_320x240__)
	#define MAJUNG_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\majung\\\\majung_320x240_majung\\\\"
#endif

	ADD_APPLICATION_STRING2(STR_GX_MAJUNG_GAME_NAME,		"Majung",	"Majung game name");
	ADD_APPLICATION_STRING2(STR_GX_MAJUNG_LEVEL_EASY,		"Easy",		"Majung easy");
	ADD_APPLICATION_STRING2(STR_GX_MAJUNG_LEVEL_NORMAL,	"Normal",	"Majung normal");
	ADD_APPLICATION_STRING2(STR_GX_MAJUNG_LEVEL_HARD,		"Hard",		"Majung hard");

	ADD_APPLICATION_STRING2(STR_GX_MAJUNG_HELP_DESCRIPTION,	"Select two bricks with same pattern. If two bricks can be connected by making less than two turns, they will disappear and user may gain extra time. Use arrow keys (or key 2,4,6,8) to move selection.\n(2)Use key 5 to select.","Majung Help Desc");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_GAME_ICON,			MAJUNG_IMG_PATH"majung_icon.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_1W,			MAJUNG_IMG_PATH"brick_1w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_2W,			MAJUNG_IMG_PATH"brick_2w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_3W,			MAJUNG_IMG_PATH"brick_3w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_4W,			MAJUNG_IMG_PATH"brick_4w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_5W,			MAJUNG_IMG_PATH"brick_5w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_6W,			MAJUNG_IMG_PATH"brick_6w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_7W,			MAJUNG_IMG_PATH"brick_7w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_8W,			MAJUNG_IMG_PATH"brick_8w.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_9W,			MAJUNG_IMG_PATH"brick_9w.pbm",	"Majung Image");
	
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_2S,			MAJUNG_IMG_PATH"brick_2s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_3S,			MAJUNG_IMG_PATH"brick_3s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_4S,			MAJUNG_IMG_PATH"brick_4s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_5S,			MAJUNG_IMG_PATH"brick_5s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_6S,			MAJUNG_IMG_PATH"brick_6s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_7S,			MAJUNG_IMG_PATH"brick_7s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_8S,			MAJUNG_IMG_PATH"brick_8s.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_9S,			MAJUNG_IMG_PATH"brick_9s.pbm",	"Majung Image");
	
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_1T,			MAJUNG_IMG_PATH"brick_1t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_2T,			MAJUNG_IMG_PATH"brick_2t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_3T,			MAJUNG_IMG_PATH"brick_3t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_4T,			MAJUNG_IMG_PATH"brick_4t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_5T,			MAJUNG_IMG_PATH"brick_5t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_6T,			MAJUNG_IMG_PATH"brick_6t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_7T,			MAJUNG_IMG_PATH"brick_7t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_8T,			MAJUNG_IMG_PATH"brick_8t.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_9T,			MAJUNG_IMG_PATH"brick_9t.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_A,			MAJUNG_IMG_PATH"brick_a.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_B,			MAJUNG_IMG_PATH"brick_b.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_C,			MAJUNG_IMG_PATH"brick_c.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_D,			MAJUNG_IMG_PATH"brick_d.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_F,			MAJUNG_IMG_PATH"brick_f.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_G,			MAJUNG_IMG_PATH"brick_g.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_H,			MAJUNG_IMG_PATH"brick_h.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_1W_SEL,		MAJUNG_IMG_PATH"brick_1w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_2W_SEL,		MAJUNG_IMG_PATH"brick_2w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_3W_SEL,		MAJUNG_IMG_PATH"brick_3w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_4W_SEL,		MAJUNG_IMG_PATH"brick_4w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_5W_SEL,		MAJUNG_IMG_PATH"brick_5w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_6W_SEL,		MAJUNG_IMG_PATH"brick_6w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_7W_SEL,		MAJUNG_IMG_PATH"brick_7w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_8W_SEL,		MAJUNG_IMG_PATH"brick_8w_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_9W_SEL,		MAJUNG_IMG_PATH"brick_9w_sel.pbm",	"Majung Image");
	
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_2S_SEL,		MAJUNG_IMG_PATH"brick_2s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_3S_SEL,		MAJUNG_IMG_PATH"brick_3s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_4S_SEL,		MAJUNG_IMG_PATH"brick_4s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_5S_SEL,		MAJUNG_IMG_PATH"brick_5s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_6S_SEL,		MAJUNG_IMG_PATH"brick_6s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_7S_SEL,		MAJUNG_IMG_PATH"brick_7s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_8S_SEL,		MAJUNG_IMG_PATH"brick_8s_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_9S_SEL,		MAJUNG_IMG_PATH"brick_9s_sel.pbm",	"Majung Image");
	
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_1T_SEL,		MAJUNG_IMG_PATH"brick_1t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_2T_SEL,		MAJUNG_IMG_PATH"brick_2t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_3T_SEL,		MAJUNG_IMG_PATH"brick_3t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_4T_SEL,		MAJUNG_IMG_PATH"brick_4t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_5T_SEL,		MAJUNG_IMG_PATH"brick_5t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_6T_SEL,		MAJUNG_IMG_PATH"brick_6t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_7T_SEL,		MAJUNG_IMG_PATH"brick_7t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_8T_SEL,		MAJUNG_IMG_PATH"brick_8t_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_9T_SEL,		MAJUNG_IMG_PATH"brick_9t_sel.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_A_SEL,		MAJUNG_IMG_PATH"brick_a_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_B_SEL,		MAJUNG_IMG_PATH"brick_b_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_C_SEL,		MAJUNG_IMG_PATH"brick_c_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_D_SEL,		MAJUNG_IMG_PATH"brick_d_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_F_SEL,		MAJUNG_IMG_PATH"brick_f_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_G_SEL,		MAJUNG_IMG_PATH"brick_g_sel.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BRICK_H_SEL,		MAJUNG_IMG_PATH"brick_h_sel.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_CONNECT_HOR,		MAJUNG_IMG_PATH"connect_hor.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_CONNECT_VER,		MAJUNG_IMG_PATH"connect_ver.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_CONNECT_LU,		MAJUNG_IMG_PATH"connect_lu.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_CONNECT_RU,		MAJUNG_IMG_PATH"connect_ru.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_CONNECT_LD,		MAJUNG_IMG_PATH"connect_ld.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_CONNECT_RD,		MAJUNG_IMG_PATH"connect_rd.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_THICK,				MAJUNG_IMG_PATH"thick.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_1,		MAJUNG_IMG_PATH"bar_fill_01.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_2,		MAJUNG_IMG_PATH"bar_fill_02.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_3,		MAJUNG_IMG_PATH"bar_fill_03.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_4,		MAJUNG_IMG_PATH"bar_fill_04.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_5,		MAJUNG_IMG_PATH"bar_fill_05.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_6,		MAJUNG_IMG_PATH"bar_fill_06.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_7,		MAJUNG_IMG_PATH"bar_fill_07.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_8,		MAJUNG_IMG_PATH"bar_fill_08.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_9,		MAJUNG_IMG_PATH"bar_fill_09.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_10,		MAJUNG_IMG_PATH"bar_fill_10.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_11,		MAJUNG_IMG_PATH"bar_fill_11.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_12,		MAJUNG_IMG_PATH"bar_fill_12.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_13,		MAJUNG_IMG_PATH"bar_fill_13.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_14,		MAJUNG_IMG_PATH"bar_fill_14.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_15,		MAJUNG_IMG_PATH"bar_fill_15.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_16,		MAJUNG_IMG_PATH"bar_fill_16.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_17,		MAJUNG_IMG_PATH"bar_fill_17.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_18,		MAJUNG_IMG_PATH"bar_fill_18.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_19,		MAJUNG_IMG_PATH"bar_fill_19.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_FILL_20,		MAJUNG_IMG_PATH"bar_fill_20.pbm",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_1,		MAJUNG_IMG_PATH"bar_empty_01.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_2,		MAJUNG_IMG_PATH"bar_empty_02.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_3,		MAJUNG_IMG_PATH"bar_empty_03.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_4,		MAJUNG_IMG_PATH"bar_empty_04.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_5,		MAJUNG_IMG_PATH"bar_empty_05.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_6,		MAJUNG_IMG_PATH"bar_empty_06.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_7,		MAJUNG_IMG_PATH"bar_empty_07.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_8,		MAJUNG_IMG_PATH"bar_empty_08.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_9,		MAJUNG_IMG_PATH"bar_empty_09.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_10,		MAJUNG_IMG_PATH"bar_empty_10.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_11,		MAJUNG_IMG_PATH"bar_empty_11.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_12,		MAJUNG_IMG_PATH"bar_empty_12.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_13,		MAJUNG_IMG_PATH"bar_empty_13.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_14,		MAJUNG_IMG_PATH"bar_empty_14.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_15,		MAJUNG_IMG_PATH"bar_empty_15.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_16,		MAJUNG_IMG_PATH"bar_empty_16.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_17,		MAJUNG_IMG_PATH"bar_empty_17.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_18,		MAJUNG_IMG_PATH"bar_empty_18.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_19,		MAJUNG_IMG_PATH"bar_empty_19.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BAR_EMPTY_20,		MAJUNG_IMG_PATH"bar_empty_20.pbm",	"Majung Image");
	
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_GAMEOVER,			MAJUNG_IMG_PATH"gameover.pbm",		"Majung Image");
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
       ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_GAMEOVER_LANGUAGE0,			MAJUNG_IMG_PATH"gameover.pbm",		"Majung Image");
       ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_GAMEOVER_LANGUAGE1,			MAJUNG_IMG_PATH"multi_lan\\\\gameover_c.pbm",		"Majung Image"); 
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_GRADESMAP,			MAJUNG_IMG_PATH"gradesmap.pbm",		"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_COUNT,				MAJUNG_IMG_PATH"count.pbm",			"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_1,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_1.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_2,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_2.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_3,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_3.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_4,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_4.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_5,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_5.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_6,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_6.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_7,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_7.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_8,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_8.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_9,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_9.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_0,					MAJUNG_IMG_PATH"MAJUNG_NUMBER_0.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_BOX,					MAJUNG_IMG_PATH"MAJUNG_box.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_EXIT_UP,			MAJUNG_IMG_PATH"MAJUNG_exit_up.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_GX_MAJUNG_EXIT_DOWN,			MAJUNG_IMG_PATH"MAJUNG_exit_down.pbm",	"Majung Image");
}
#endif /* IS_MAJUNG_BASE_GAME */


/************************************************************************/
/* Copter	128x160																		*/	
/************************************************************************/
#ifdef IS_COPTER_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_COPTER_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_COPTER_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_COPTER_176x220__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_SUBMARINE_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_SUBMARINE_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_SUBMARINE_176x220__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_JET_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_JET_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_JET_176x220__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_COPTER_128x128__) || defined(__MMI_GAME_COPTER_128x160__) || defined(__MMI_GAME_COPTER_176x220__)
/* under construction !*/
	#if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
#elif defined(__MMI_GAME_SUBMARINE_128x128__) || defined(__MMI_GAME_SUBMARINE_128x160__) || defined(__MMI_GAME_SUBMARINE_176x220__)
/* under construction !*/
	#if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
#elif defined(__MMI_GAME_JET_128x128__) || defined(__MMI_GAME_JET_128x160__) || defined(__MMI_GAME_JET_176x220__)
/* under construction !*/
	#if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
	#else
/* under construction !*/
	#endif
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
	#if defined(__MMI_GAME_COPTER_128x160__) || defined(__MMI_GAME_COPTER_176x220__) || defined(__MMI_GAME_SUBMARINE_128x160__) || defined(__MMI_GAME_SUBMARINE_176x220__) || defined(__MMI_GAME_JET_128x160__) || defined(__MMI_GAME_JET_176x220__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
#endif /* IS_COPTER_BASE_GAME */


/************************************************************************/
/* Puzzle	128x160  																	*/	
/************************************************************************/
#ifdef IS_PUZZLE_BASE_GAME
void PopulatePuzzleRes(void)
{
	/* set the base path */
#if defined(__MMI_GAME_PUZZLE_128x128__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_128x128_puzzle\\\\"
#elif defined(__MMI_GAME_PUZZLE_128x160__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_128x160_puzzle\\\\"
#elif defined(__MMI_GAME_PUZZLE_176x220__)
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_176x220_puzzle\\\\"
#elif  defined(__MMI_GAME_PUZZLE_240x320__)	
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_240x320_puzzle\\\\"
#elif  defined(__MMI_GAME_PUZZLE_320x240__)	
	#define PUZZLE_IMG_PATH	CUST_IMG_BASE_PATH"\\\\GameImages\\\\puzzle\\\\puzzle_320x240_puzzle\\\\"
#endif

	/* set game strings */
	ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_GAME_NAME,			         "Puzzle",		"Puzzle Game Name");
	
	#if defined(__MMI_TOUCH_SCREEN__)
		ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_HELP_DESCRIPTION_TP,			"Move the small pictures to make it become the original image.\n(1)touch the small picture around the blank block to make it move toward to the blank block.",	"Puzzle Help Description");
	#elif defined(__MMI_GAME_PUZZLE_128x128__)
		ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_HELP_DESCRIPTION_128,			"Move the small pictures to make it become the original image.\n(1)Use key 2(or up-arrow key) to make a picture go upward, key 4(or left-arrow key) to make a picture go leftward, key 6(or right-arrow key) to make a picture go rightward, and key 8(or down-arrow key) to make a picture go downward.\n(2)Press key 5 to see the original image and the gameplay information.",	"Puzzle Help Description");
	#else
		ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_HELP_DESCRIPTION,				"Move the small pictures to make it become the original image.\n(1)Use key 2(or up-arrow key) to make a picture go upward, key 4(or left-arrow key) to make a picture go leftward, key 6(or right-arrow key) to make a picture go rightward, and key 8(or down-arrow key) to make a picture go downward.",	"Puzzle Help Description");
	#endif 

	ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_LEVEL_EASY,		"Easy", "Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_LEVEL_NORMAL,	"Normal", "Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_PUZZLE_LEVEL_HARD,		"Hard", "Menu string");

	/* set game images */
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_GAME_ICON,		PUZZLE_IMG_PATH"gx_puzzle_icon.bmp",					"Puzzle icon image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_0,		PUZZLE_IMG_PATH"gx_puzzle_number_0.gif",				"Image for 0");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_1,		PUZZLE_IMG_PATH"gx_puzzle_number_1.gif",				"Image for 1");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_2,		PUZZLE_IMG_PATH"gx_puzzle_number_2.gif",				"Image for 2");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_3,		PUZZLE_IMG_PATH"gx_puzzle_number_3.gif",				"Image for 3");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_4,		PUZZLE_IMG_PATH"gx_puzzle_number_4.gif",				"Image for 4");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_5,		PUZZLE_IMG_PATH"gx_puzzle_number_5.gif",				"Image for 5");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_6,		PUZZLE_IMG_PATH"gx_puzzle_number_6.gif",				"Image for 6");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_7,		PUZZLE_IMG_PATH"gx_puzzle_number_7.gif",				"Image for 7");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_8,		PUZZLE_IMG_PATH"gx_puzzle_number_8.gif",				"Image for 8");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_NUMBER_9,		PUZZLE_IMG_PATH"gx_puzzle_number_9.gif",				"Image for 9");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_BOX,				PUZZLE_IMG_PATH"gx_puzzle_box.gif",						"Image for box");
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_STEP,			PUZZLE_IMG_PATH"gx_puzzle_step.gif",					"Image for alphabet: STEP");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_TIME,			PUZZLE_IMG_PATH"gx_puzzle_time.gif",					"Image for alphabet: TIME");
#endif
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_LEFT_BAR,		PUZZLE_IMG_PATH"gx_puzzle_left_bar.gif",				"Image for left border");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_RIGHT_BAR,		PUZZLE_IMG_PATH"gx_puzzle_right_bar.gif",				"Image for right border");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_TOP_BAR,		PUZZLE_IMG_PATH"gx_puzzle_top_bar.gif",				"Image for top border");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_BOTTOM_BAR,	PUZZLE_IMG_PATH"gx_puzzle_bottom_bar.gif",			"Image for bottom border");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_SPACE,		PUZZLE_IMG_PATH"gx_puzzle_3_space.gif",				"Space Image of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_SPACE,		PUZZLE_IMG_PATH"gx_puzzle_4_space.gif",				"Space Image of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_SPACE,		PUZZLE_IMG_PATH"gx_puzzle_5_space.gif",				"Space Image of 5x5 puzzle");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_SMALL_3,		PUZZLE_IMG_PATH"gx_puzzle_small_3.gif",				"Small image for original image 3x3");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_SMALL_4,		PUZZLE_IMG_PATH"gx_puzzle_small_4.gif",				"Small image for original image 4x4");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_SMALL_5,		PUZZLE_IMG_PATH"gx_puzzle_small_5.gif",				"Small image for original image 5x5");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_1,				PUZZLE_IMG_PATH"gx_puzzle_3_1.gif",						"Image 1 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_2,				PUZZLE_IMG_PATH"gx_puzzle_3_2.gif",						"Image 2 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_3,				PUZZLE_IMG_PATH"gx_puzzle_3_3.gif",						"Image 3 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_4,				PUZZLE_IMG_PATH"gx_puzzle_3_4.gif",						"Image 4 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_5,				PUZZLE_IMG_PATH"gx_puzzle_3_5.gif",						"Image 5 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_6,				PUZZLE_IMG_PATH"gx_puzzle_3_6.gif",						"Image 6 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_7,				PUZZLE_IMG_PATH"gx_puzzle_3_7.gif",						"Image 7 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_3_8,				PUZZLE_IMG_PATH"gx_puzzle_3_8.gif",						"Image 8 of 3x3 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_1,				PUZZLE_IMG_PATH"gx_puzzle_4_1.gif",						"Image 1 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_2,				PUZZLE_IMG_PATH"gx_puzzle_4_2.gif",						"Image 2 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_3,				PUZZLE_IMG_PATH"gx_puzzle_4_3.gif",						"Image 3 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_4,				PUZZLE_IMG_PATH"gx_puzzle_4_4.gif",						"Image 4 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_5,				PUZZLE_IMG_PATH"gx_puzzle_4_5.gif",						"Image 5 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_6,				PUZZLE_IMG_PATH"gx_puzzle_4_6.gif",						"Image 6 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_7,				PUZZLE_IMG_PATH"gx_puzzle_4_7.gif",						"Image 7 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_8,				PUZZLE_IMG_PATH"gx_puzzle_4_8.gif",						"Image 8 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_9,				PUZZLE_IMG_PATH"gx_puzzle_4_9.gif",						"Image 9 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_10,			PUZZLE_IMG_PATH"gx_puzzle_4_10.gif",					"Image 10 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_11,			PUZZLE_IMG_PATH"gx_puzzle_4_11.gif",					"Image 11 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_12,			PUZZLE_IMG_PATH"gx_puzzle_4_12.gif",					"Image 12 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_13,			PUZZLE_IMG_PATH"gx_puzzle_4_13.gif",					"Image 13 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_14,			PUZZLE_IMG_PATH"gx_puzzle_4_14.gif",					"Image 14 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_4_15,			PUZZLE_IMG_PATH"gx_puzzle_4_15.gif",					"Image 15 of 4x4 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_1,				PUZZLE_IMG_PATH"gx_puzzle_5_1.gif",						"Image 1 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_2,				PUZZLE_IMG_PATH"gx_puzzle_5_2.gif",						"Image 2 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_3,				PUZZLE_IMG_PATH"gx_puzzle_5_3.gif",						"Image 3 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_4,				PUZZLE_IMG_PATH"gx_puzzle_5_4.gif",						"Image 4 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_5,				PUZZLE_IMG_PATH"gx_puzzle_5_5.gif",						"Image 5 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_6,				PUZZLE_IMG_PATH"gx_puzzle_5_6.gif",						"Image 6 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_7,				PUZZLE_IMG_PATH"gx_puzzle_5_7.gif",						"Image 7 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_8,				PUZZLE_IMG_PATH"gx_puzzle_5_8.gif",						"Image 8 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_9,				PUZZLE_IMG_PATH"gx_puzzle_5_9.gif",						"Image 9 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_10,			PUZZLE_IMG_PATH"gx_puzzle_5_10.gif",					"Image 10 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_11,			PUZZLE_IMG_PATH"gx_puzzle_5_11.gif",					"Image 11 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_12,			PUZZLE_IMG_PATH"gx_puzzle_5_12.gif",					"Image 12 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_13,			PUZZLE_IMG_PATH"gx_puzzle_5_13.gif",					"Image 13 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_14,			PUZZLE_IMG_PATH"gx_puzzle_5_14.gif",					"Image 14 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_15,			PUZZLE_IMG_PATH"gx_puzzle_5_15.gif",					"Image 15 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_16,			PUZZLE_IMG_PATH"gx_puzzle_5_16.gif",					"Image 16 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_17,			PUZZLE_IMG_PATH"gx_puzzle_5_17.gif",					"Image 17 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_18,			PUZZLE_IMG_PATH"gx_puzzle_5_18.gif",					"Image 18 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_19,			PUZZLE_IMG_PATH"gx_puzzle_5_19.gif",					"Image 19 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_20,			PUZZLE_IMG_PATH"gx_puzzle_5_20.gif",					"Image 20 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_21,			PUZZLE_IMG_PATH"gx_puzzle_5_21.gif",					"Image 21 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_22,			PUZZLE_IMG_PATH"gx_puzzle_5_22.gif",					"Image 22 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_23,			PUZZLE_IMG_PATH"gx_puzzle_5_23.gif",					"Image 23 of 5x5 puzzle");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_5_24,			PUZZLE_IMG_PATH"gx_puzzle_5_24.gif",					"Image 24 of 5x5 puzzle");
	
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_GOTEXT,			PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_gameover.gif","game over text");
#endif
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_GRADESMAP,		PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_gradesmap.gif","grade background");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_GOPIC,			PUZZLE_IMG_PATH"gameover\\\\gx_puzzle_pic.gif",		"game over image");
#if  defined(__MMI_TOUCH_SCREEN__)&& (defined(__MMI_GAME_PUZZLE_240x320__) || defined(__MMI_GAME_PUZZLE_320x240__))
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_UP,			PUZZLE_IMG_PATH"gx_puzzle_up.pbm","Tower Bar Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_DOWN,		PUZZLE_IMG_PATH"gx_puzzle_down.pbm","Tower Bar Image");
	#endif

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE0,		PUZZLE_IMG_PATH"multi_lan\\\gx_puzzle_gameover.gif","game over text");
       
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE1,		PUZZLE_IMG_PATH"multi_lan\\\gx_puzzle_gameover_C.gif","game over text");
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
}
#endif /* IS_PUZZLE_BASE_GAME */
	

/************************************************************************/
/* Panda	  128x128, 128x160															*/	
/************************************************************************/
#ifdef IS_PANDA_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_PANDA_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_PANDA_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_PANDA_176x220__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_MONKEY_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_MONKEY_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_MONKEY_176x220__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_PANDA_128x128__) || defined(__MMI_GAME_PANDA_128x160__) || defined(__MMI_GAME_PANDA_176x220__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_MONKEY_128x128__) || defined(__MMI_GAME_MONKEY_128x160__) || defined(__MMI_GAME_MONKEY_176x220__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* IS_PANDA_BASE_GAME */


/************************************************************************/
/* Stair	128x160  																	   */	
/************************************************************************/
#ifdef IS_STAIR_BASE_GAME
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_STAIR_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_STAIR_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_STAIR_176x220__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_CHICKEN_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_CHICKEN_128x160__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_ROBOT_176x220__)
/* under construction !*/
#elif defined(__MMI_GAME_ROBOT_128x160__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_STAIR_128x160__) || defined(__MMI_GAME_STAIR_128x128__) || defined(__MMI_GAME_STAIR_176x220__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_CHICKEN_128x128__) || defined(__MMI_GAME_CHICKEN_128x160__)
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_GAME_ROBOT_176x220__) || defined(__MMI_GAME_ROBOT_128x160__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if defined(__MMI_GAME_STAIR_128x160__) || defined(__MMI_GAME_STAIR_176x220__) || defined(__MMI_GAME_CHICKEN_128x160__) || defined(__MMI_GAME_ROBOT_176x220__) || defined(__MMI_GAME_ROBOT_128x160__)
/* under construction !*/
	#elif defined(__MMI_GAME_STAIR_128x128__) || defined(__MMI_GAME_CHICKEN_128x128__)
/* under construction !*/
	#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else   /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/* under construction !*/
/* under construction !*/
#endif /* IS_STAIR_BASE_GAME */


/************************************************************************/
/* Ufo	128x160  																	   */	
/************************************************************************/
#ifdef IS_UFO_BASE_GAME 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME_UFO_128x128__)
/* under construction !*/
#elif defined(__MMI_GAME_UFO_128x160__)
/* under construction !*/
#elif defined(__MMI_GAME_UFO_176x220__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__	
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
/* under construction !*/
#endif /* IS_UFO_BASE_GAME */

/************************************************************************/
/* Magicsushi																				*/	
/************************************************************************/
#ifdef IS_MAGICSUSHI_BASE_GAME
void PopulateMagicsushiRes(void)
{
#if defined(__MMI_GAME_MAGICSUSHI_240x320__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_240x320_magicsushi\\\\"
#elif defined(__MMI_GAME_MAGICSUSHI_320x240__)
	#define MAGICSUSHI_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Magicsushi\\\\magicsushi_320x240_magicsushi\\\\"
#endif
	/* strings */
	ADD_APPLICATION_STRING2(STR_ID_GX_MAGICSUSHI_GAME_NAME,"Magicsushi","Title displayed in Games Menu");
	//ADD_APPLICATION_STRING2(STR_ID_GX_MAGICSUSHI_TITLE,"Hanoi","String displayed in Hanio Title Bar");
	
	ADD_APPLICATION_STRING2(STR_ID_GX_MAGICSUSHI_HELP_DESCRIPTION,"Use the following methods to eliminate susui:\n(1)\n(2)star:will randomly eliminate one kind of susui.\n(3)cross: will eliminate all susuis on the cross' column and row.\n(4)little ball: will eliminate susuis by 3x3 matrix which is centered by the little ball.", "String for Help In Hanio Game");
	
	/* images */
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_GAME_ICON,	MAGICSUSHI_IMG_PATH"Magicsushi.BMP","Games image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_0,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_0.pbm","Number 0 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_1,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_1.pbm","Number 1 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_2,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_2.pbm","Number 2 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_3,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_3.pbm","Number 3 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_4,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_4.pbm","Number 4 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_5,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_5.pbm","Number 5 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_6,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_6.pbm","Number 6 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_7,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_7.pbm","Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_8,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_8.pbm","Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NUMBER_9,MAGICSUSHI_IMG_PATH"gx_magicsushi_num_9.pbm","Number 9 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_NULL,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_null.pbm","null item's Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_SELECTED,MAGICSUSHI_IMG_PATH"gx_magicsushi_select.pbm","Image for the selected item");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_PROGRESS,MAGICSUSHI_IMG_PATH"gx_magicsushi_progress.pbm","progress bar Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_0,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_1.pbm","susui 1");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_1,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_2.pbm","susui 2");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_2,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_3.pbm","susui 3");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_3,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_4.pbm","susui 4");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_4,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_5.pbm","susui 5");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_5,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_6.pbm","susui 6");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_6,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_7.pbm","susui 7");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_7,MAGICSUSHI_IMG_PATH"gx_magicsushi_item_8.pbm","susui 8");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC1,MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_1.pbm","magic item 1");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC2,MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_2.pbm","magic item 2");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_TYPE_MAGIC3,MAGICSUSHI_IMG_PATH"gx_magicsushi_magic_3.pbm","magic item 3");
    
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_GAME_BACKGROUND,MAGICSUSHI_IMG_PATH"gx_magicsushi_background.Pbm","Game's background image"); 
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_GAMEOVER,MAGICSUSHI_IMG_PATH"gx_magicsushi_gameover.gif","gameover image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_UPLEVEL,MAGICSUSHI_IMG_PATH"gx_magicsushi_uplevel.gif","uplevel image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NOMOREMOVE,MAGICSUSHI_IMG_PATH"gx_magicsushi_nomoremove.gif","no more move Image");
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
    ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_BACKGROUND_LANGUAGE0,MAGICSUSHI_IMG_PATH"gx_magicsushi_background.Pbm","Game's background image"); 
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_GAMEOVER_LANGUAGE0,MAGICSUSHI_IMG_PATH"gx_magicsushi_gameover.gif","uplevel image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_UPLEVEL_LANGUAGE0,MAGICSUSHI_IMG_PATH"gx_magicsushi_uplevel.gif","no more move Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NOMOREMOVE_LANGUAGE0,MAGICSUSHI_IMG_PATH"gx_magicsushi_nomoremove.gif","gameover image");

    ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_BACKGROUND_LANGUAGE1,MAGICSUSHI_IMG_PATH"multi_lan\\\\bkg_C.pbm","gameover image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_GAMEOVER_LANGUAGE1,MAGICSUSHI_IMG_PATH"multi_lan\\\\gameover_C.gif","uplevel image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_UPLEVEL_LANGUAGE1,MAGICSUSHI_IMG_PATH"multi_lan\\\\uplevel_C.gif","no more move Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_NOMOREMOVE_LANGUAGE1,MAGICSUSHI_IMG_PATH"multi_lan\\\\nomoremove_C.gif","gameover image");
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_CURSOR,MAGICSUSHI_IMG_PATH"gx_magicsushi_select1.pbm","cursor Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_UP,			MAGICSUSHI_IMG_PATH"gx_magicsushi_up.pbm","Tower Bar Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_MAGICSUSHI_DOWN,		MAGICSUSHI_IMG_PATH"gx_magicsushi_down.pbm","Tower Bar Image");

}
#endif /* IS_MAGICSUSHI_BASE_GAME */

/************************************************************************/
/* Fruit	  176x220																		*/	
/************************************************************************/

#ifdef IS_FRUIT_BASE_GAME
void PopulateFruitRes(void)
{
	/* set image path */
	#define FRUIT_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Fruit\\\\fruit_176x220_fruit\\\\"

	/* set game strings */
	ADD_APPLICATION_STRING2(STR_ID_GX_FRUIT_GAME_NAME,				"Fruit",				"Fruit Game Name");
	ADD_APPLICATION_STRING2(STR_ID_GX_FRUIT_HELP_DESCRIPTION,	"just play it",	"Fruit Help Description");
	ADD_APPLICATION_STRING2(STR_ID_GX_FRUIT_LEVEL_EASY,			"Easy",				"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_FRUIT_LEVEL_NORMAL,			"Normal",			"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_FRUIT_LEVEL_HARD,			"Hard",				"Menu string");

	/* set game images */
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_GAME_ICON,					FRUIT_IMG_PATH"gx_fruit_icon.pbm",						"Fruit icon image");
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_GOTEXT,						FRUIT_IMG_PATH"gx_fruit_gameover_title.pbm",			"game over text");
#endif
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_GRADESMAP,					FRUIT_IMG_PATH"gx_fruit_gradesmap.pbm",				"grade background");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_GOPIC,						FRUIT_IMG_PATH"gx_fruit_gameover_pic.pbm",			"game over image");

#if defined(__MMI_GAME_FRUIT_176x220__)
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODA_ONE_PIECE,			FRUIT_IMG_PATH"gx_fruit_fooda1.pbm",		"fooda image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODA_TWO_PIECE,			FRUIT_IMG_PATH"gx_fruit_fooda2.pbm",		"fooda image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODA_THREE_PIECE,		FRUIT_IMG_PATH"gx_fruit_fooda3.pbm",		"fooda image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODA_MAX_PIECE,			FRUIT_IMG_PATH"gx_fruit_fooda4.pbm",		"fooda image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODB_ONE_PIECE,			FRUIT_IMG_PATH"gx_fruit_foodb1.pbm",		"foodb image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODB_TWO_PIECE,			FRUIT_IMG_PATH"gx_fruit_foodb2.pbm",		"foodb image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODB_THREE_PIECE,		FRUIT_IMG_PATH"gx_fruit_foodb3.pbm",		"foodb image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODB_MAX_PIECE,			FRUIT_IMG_PATH"gx_fruit_foodb4.pbm",		"foodb image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODC_ONE_PIECE,			FRUIT_IMG_PATH"gx_fruit_foodc1.pbm",		"foodc image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODC_TWO_PIECE,			FRUIT_IMG_PATH"gx_fruit_foodc2.pbm",		"foodc image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODC_THREE_PIECE,		FRUIT_IMG_PATH"gx_fruit_foodc3.pbm",		"foodc image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_FOODC_MAX_PIECE,			FRUIT_IMG_PATH"gx_fruit_foodc4.pbm",		"foodc image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_ROCK_ONEPIECE,				FRUIT_IMG_PATH"gx_fruit_rock.pbm",			"rock image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TREASURE_1,					FRUIT_IMG_PATH"gx_fruit_item_treasure_01.pbm",			"rock image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TREASURE_2,					FRUIT_IMG_PATH"gx_fruit_item_treasure_02.pbm",			"rock image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TREASURE_3,					FRUIT_IMG_PATH"gx_fruit_item_treasure_03.pbm",			"rock image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TREASURE_4,					FRUIT_IMG_PATH"gx_fruit_item_treasure_04.pbm",			"rock image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TREASURE_5,					FRUIT_IMG_PATH"gx_fruit_item_treasure_05.pbm",			"rock image");
	
	/* sword need 2 way image */
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_A,				FRUIT_IMG_PATH"gx_fruit_item_wave_left_1a.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_B,				FRUIT_IMG_PATH"gx_fruit_item_wave_left_1b.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_A,				FRUIT_IMG_PATH"gx_fruit_item_wave_left_2a.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_B,				FRUIT_IMG_PATH"gx_fruit_item_wave_left_2b.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_A,				FRUIT_IMG_PATH"gx_fruit_item_wave_left_3a.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_B,				FRUIT_IMG_PATH"gx_fruit_item_wave_left_3b.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_A,				FRUIT_IMG_PATH"gx_fruit_item_wave_right_1a.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_B,				FRUIT_IMG_PATH"gx_fruit_item_wave_right_1b.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_A,				FRUIT_IMG_PATH"gx_fruit_item_wave_right_2a.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_B,				FRUIT_IMG_PATH"gx_fruit_item_wave_right_2b.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_A,				FRUIT_IMG_PATH"gx_fruit_item_wave_right_3a.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_B,				FRUIT_IMG_PATH"gx_fruit_item_wave_right_3b.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_A,				FRUIT_IMG_PATH"gx_fruit_kickwavela.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_B,				FRUIT_IMG_PATH"gx_fruit_kickwavelb.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_A,				FRUIT_IMG_PATH"gx_fruit_kickwavera.pbm",		"swordwave image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_B,				FRUIT_IMG_PATH"gx_fruit_kickwaverb.pbm",		"swordwave image");
	/* sword need 2 way image */
	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_GAMEOVER,				FRUIT_IMG_PATH"gx_fruit_chef_gameover.pbm",				"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_RIGHT_CUTPREP,		FRUIT_IMG_PATH"gx_fruit_chef_right_cutprep.pbm",		"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_RIGHT_CUT,			FRUIT_IMG_PATH"gx_fruit_chef_right_cut.pbm",				"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_RIGHT_KICKPREP,		FRUIT_IMG_PATH"gx_fruit_chef_right_kickprep.pbm",		"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_RIGHT_KICK,			FRUIT_IMG_PATH"gx_fruit_chef_right_kick.pbm",			"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_LEFT_CUTPREP,		FRUIT_IMG_PATH"gx_fruit_chef_left_cutprep.pbm",			"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_LEFT_CUT,				FRUIT_IMG_PATH"gx_fruit_chef_left_cut.pbm",				"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_LEFT_KICKPREP,		FRUIT_IMG_PATH"gx_fruit_chef_left_kickprep.pbm",		"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_LEFT_KICK,			FRUIT_IMG_PATH"gx_fruit_chef_left_kick.pbm",				"chef motion image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_FAINTA,		FRUIT_IMG_PATH"gx_fruit_chef_fainta.pbm",								"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_FAINTB,		FRUIT_IMG_PATH"gx_fruit_chef_faintb.pbm",								"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKA,	FRUIT_IMG_PATH"gx_fruit_chef_right_walka.pbm",					"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKB,	FRUIT_IMG_PATH"gx_fruit_chef_right_walkb.pbm",					"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_LEFT_WALKA,	FRUIT_IMG_PATH"gx_fruit_chef_left_walka.pbm",					"chef motion image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_CHEF_LEFT_WALKB,	FRUIT_IMG_PATH"gx_fruit_chef_left_walkb.pbm",					"chef motion image");			

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_PLATFORM,			FRUIT_IMG_PATH"gx_fruit_platform.pbm",		"platform image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TRACKA,				FRUIT_IMG_PATH"gx_fruit_tracka.pbm",			"track image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_TRACKB,				FRUIT_IMG_PATH"gx_fruit_trackb.pbm",			"track image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_OKA,	FRUIT_IMG_PATH"gx_fruit_shaker_ok_a.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_OKB,	FRUIT_IMG_PATH"gx_fruit_shaker_ok_b.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_PBLVA_A,	FRUIT_IMG_PATH"gx_fruit_shaker_pblva_a.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_PBLVA_B,	FRUIT_IMG_PATH"gx_fruit_shaker_pblva_b.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_PBLVB_A,	FRUIT_IMG_PATH"gx_fruit_shaker_pblvb_a.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_PBLVB_B,	FRUIT_IMG_PATH"gx_fruit_shaker_pblvb_b.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_SHAKER_BROKEN,	FRUIT_IMG_PATH"gx_fruit_shaker_broken.pbm",		"shaker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_WORKER_STEPA,	FRUIT_IMG_PATH"gx_fruit_worker_walka.pbm",		"worker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_WORKER_STEPB,	FRUIT_IMG_PATH"gx_fruit_worker_walkb.pbm",		"worker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_WORKER_FIXA,	FRUIT_IMG_PATH"gx_fruit_worker_fixa.pbm",			"worker image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_WORKER_FIXB,	FRUIT_IMG_PATH"gx_fruit_worker_fixb.pbm",			"worker image");
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_BGROUND,			FRUIT_IMG_PATH"gx_fruit_bg.gif",						"backgruond image");
#endif

#ifdef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_BGROUND_LANGUAGE0,    FRUIT_IMG_PATH"gx_fruit_bg.gif",						"backgruond image");
    	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE0,       FRUIT_IMG_PATH"gx_fruit_gameover_title.pbm",			"game over text");
        
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_BGROUND_LANGUAGE1,     FRUIT_IMG_PATH"multi_lan\\\gx_fruit_bg_C.gif",						"backgruond image");
    	ADD_APPLICATION_IMAGE2(IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE1,        FRUIT_IMG_PATH"multi_lan\\\gx_fruit_gameover_C.pbm",			"game over text");
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#endif


}
#endif /* IS_FRUIT_BASE_GAME */	

/************************************************************************/
/* Vsmj	  240x320																		*/	
/************************************************************************/

#ifdef IS_VSMJ_BASE_GAME
void PopulateVsmjRes(void)
{
	/* set image path */
#if defined(__MMI_GAME_VSMJ_240x320__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_240x320_vsmj\\\\"
#elif defined(__MMI_GAME_VSMJ_320x240__)
	#define VSMJ_IMG_PATH CUST_IMG_BASE_PATH"\\\\GameImages\\\\Vsmj\\\\vsmj_320x240_vsmj\\\\"
#endif
	

	/* set game strings */
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_GAME_NAME,			"Vsmj",				"Vsmj Game Name");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_HELP_DESCRIPTION,	"vsmj help",	"Vsmj Help Description");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_LEVEL_NORMAL,		"Normal",				"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_LEVEL_CPUVSCPU,	"CpuVsCpu",				"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_LEVEL1,				"4 games play",		"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_LEVEL2,				"8 games play",		"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_LEVEL3,				"16 games play",	"Menu string");
	ADD_APPLICATION_STRING2(STR_ID_GX_VSMJ_CUR_GAME,			"games",			"Menu string");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GAME_ICON,				VSMJ_IMG_PATH"gx_vsmj_icon.gif",						"Vsmj icon image");
#ifndef    __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GOTEXT,					VSMJ_IMG_PATH"gx_vsmj_gameover_title.gif",			"game over text");
#else   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE0,		VSMJ_IMG_PATH"gameover.gif",			"game over text");
       
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GOTEXT_LANGUAGE1,		VSMJ_IMG_PATH"multi_lan\\\gameover_c.gif",			"game over text");
#endif   /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GRADESMAP,				VSMJ_IMG_PATH"gx_vsmj_gradesmap.gif",				"grade background");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GOPIC,						VSMJ_IMG_PATH"gx_vsmj_gameover_pic.gif",			"game over image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_EAST,		VSMJ_IMG_PATH"T28.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_WEST,		VSMJ_IMG_PATH"T29.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_SOUTH,		VSMJ_IMG_PATH"T30.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_NORTH,		VSMJ_IMG_PATH"T31.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_CHUNG,		VSMJ_IMG_PATH"T32.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_FA,			VSMJ_IMG_PATH"T33.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_BAI,		VSMJ_IMG_PATH"T34.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_1W,		VSMJ_IMG_PATH"T1.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_2W,		VSMJ_IMG_PATH"T2.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_3W,		VSMJ_IMG_PATH"T3.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_4W,		VSMJ_IMG_PATH"T4.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_5W,		VSMJ_IMG_PATH"T5.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_6W,		VSMJ_IMG_PATH"T6.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_7W,		VSMJ_IMG_PATH"T7.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_8W,		VSMJ_IMG_PATH"T8.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_9W,		VSMJ_IMG_PATH"T9.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_1S,			VSMJ_IMG_PATH"T19.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_2S,			VSMJ_IMG_PATH"T20.gif",	"Majung Image");
 	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_3S,			VSMJ_IMG_PATH"T21.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_4S,			VSMJ_IMG_PATH"T22.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_5S,			VSMJ_IMG_PATH"T23.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_6S,			VSMJ_IMG_PATH"T24.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_7S,			VSMJ_IMG_PATH"T25.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_8S,			VSMJ_IMG_PATH"T26.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_9S,			VSMJ_IMG_PATH"T27.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_1T,			VSMJ_IMG_PATH"T10.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_2T,			VSMJ_IMG_PATH"T11.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_3T,			VSMJ_IMG_PATH"T12.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_4T,			VSMJ_IMG_PATH"T13.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_5T,			VSMJ_IMG_PATH"T14.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_6T,			VSMJ_IMG_PATH"T15.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_7T,			VSMJ_IMG_PATH"T16.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_8T,			VSMJ_IMG_PATH"T17.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_9T,			VSMJ_IMG_PATH"T18.gif",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_SPRING,			VSMJ_IMG_PATH"T35.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_SUMMER,		VSMJ_IMG_PATH"T36.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_AUTUMN,		VSMJ_IMG_PATH"T37.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_WINTER,		VSMJ_IMG_PATH"T38.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_M,			VSMJ_IMG_PATH"T39.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_L,			VSMJ_IMG_PATH"T40.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_Z,			VSMJ_IMG_PATH"T41.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_J,			VSMJ_IMG_PATH"T42.gif",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_TABLE_VER_BACK,			VSMJ_IMG_PATH"table_ver_back.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_TABLE_HOR_BACK,			VSMJ_IMG_PATH"table_hor_back.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_USER_LEFT_BACK,			VSMJ_IMG_PATH"user_left_back.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_USER_RIGHT_BACK,			VSMJ_IMG_PATH"user_right_back.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_USER_UP_BACK,				VSMJ_IMG_PATH"user_up_back.pbm",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_USER_LR_HIDE_BACK,			VSMJ_IMG_PATH"user_lr_hide_back.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BRICK_USER_UD_HIDE_BACK,		VSMJ_IMG_PATH"user_ud_hide_back.gif",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_EAT_BASE,				VSMJ_IMG_PATH"gx_vsmj_sign_eat_base.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_EAT_INVALID,			VSMJ_IMG_PATH"gx_vsmj_sign_eat_invalid.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_EAT_HIGHLIGHT,		VSMJ_IMG_PATH"gx_vsmj_sign_eat_highlight.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_EAT_0,				VSMJ_IMG_PATH"gx_vsmj_sign_eat_0.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_EAT_1,				VSMJ_IMG_PATH"gx_vsmj_sign_eat_1.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_EAT_2,				VSMJ_IMG_PATH"gx_vsmj_sign_eat_2.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_PON_BASE,				VSMJ_IMG_PATH"gx_vsmj_sign_pon_1.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_PON_INVALID,			VSMJ_IMG_PATH"gx_vsmj_sign_pon_invalid.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_PON_HIGHLIGHT,		VSMJ_IMG_PATH"gx_vsmj_sign_pon_highlight.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_GUN_BASE,			VSMJ_IMG_PATH"gx_vsmj_sign_gun_base.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_GUN_INVALID,			VSMJ_IMG_PATH"gx_vsmj_sign_gun_invalid.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_GUN_HIGHLIGHT,		VSMJ_IMG_PATH"gx_vsmj_sign_gun_highlight.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_HOU_BASE,				VSMJ_IMG_PATH"gx_vsmj_sign_hou_1.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_HOU_INVALID,			VSMJ_IMG_PATH"gx_vsmj_sign_hou_invalid.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_HOU_HIGHLIGHT,		VSMJ_IMG_PATH"gx_vsmj_sign_hou_highlight.gif",	"Majung Image");		
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_CANCEL_BASE,			VSMJ_IMG_PATH"gx_vsmj_sign_cancel.GIF",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_CANCEL_HIGHLIGHT,		VSMJ_IMG_PATH"gx_vsmj_sign_cancel_highlight.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SPECIAL_LIOU_GU,				VSMJ_IMG_PATH"gx_vsmj_sign_liou_gu.gif",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_PEN_CURSOR_OFF,					VSMJ_IMG_PATH"gx_vsmj_pen_cursor_off.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_PEN_CURSOR_ON,					VSMJ_IMG_PATH"gx_vsmj_pen_cursor_on.gif",	"Majung Image");
	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_8_FLOWER,				VSMJ_IMG_PATH"score_8_flower.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_7_1_FLOWER,			VSMJ_IMG_PATH"score_7_1_flower.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_ZE_MO,					VSMJ_IMG_PATH"score_ze_mo.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_HUO_BY_GUN,			VSMJ_IMG_PATH"score_hou_by_gun.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_MEN_CHIN,				VSMJ_IMG_PATH"score_men_chin.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_MENCHIN_ZEMO,			VSMJ_IMG_PATH"score_menchin_zemo.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_FLOWER_SEASON_SET,	VSMJ_IMG_PATH"score_flower_season_set.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_FLOWER_PLANT_SET,		VSMJ_IMG_PATH"score_flower_plant_set.gif",	"Majung Image");
	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_SEA_MOON,				VSMJ_IMG_PATH"score_sea_moon.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_ALL_ASK,				VSMJ_IMG_PATH"score_chuan_chio.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_BIG_3_YUANG,			VSMJ_IMG_PATH"score_big_3_yuang.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_SMALL_3_YUANG,			VSMJ_IMG_PATH"score_small_3_yuang.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_CHUNG,					VSMJ_IMG_PATH"score_chung.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_FA,						VSMJ_IMG_PATH"score_fa.gif",	"Majung Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_BAI,					VSMJ_IMG_PATH"score_bai.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_BIG_4_WIND,			VSMJ_IMG_PATH"score_big_4_shi.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_SMALL_4_WIND,			VSMJ_IMG_PATH"score_small_4_shi.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_3_ENKE,				VSMJ_IMG_PATH"score_3_enke.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_4_ENKE,				VSMJ_IMG_PATH"score_4_enke.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_5_ENKE,				VSMJ_IMG_PATH"score_5_enke.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_NUM_1_COLOR,			VSMJ_IMG_PATH"score_chin_1_color.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_MIX_1_COLOR,			VSMJ_IMG_PATH"score_mix_1_color.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_PAIR_PAIR_HOU,			VSMJ_IMG_PATH"score_pair_pair_hou.gif",	"Majung Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_SCORE_NOTHING,				VSMJ_IMG_PATH"score_nothing.gif",	"Majung Image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_0,VSMJ_IMG_PATH"gx_VSMJ_number_0.gif","Number 0 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_1,VSMJ_IMG_PATH"gx_VSMJ_number_1.gif","Number 1 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_2,VSMJ_IMG_PATH"gx_VSMJ_number_2.gif","Number 2 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_3,VSMJ_IMG_PATH"gx_VSMJ_number_3.gif","Number 3 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_4,VSMJ_IMG_PATH"gx_VSMJ_number_4.gif","Number 4 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_5,VSMJ_IMG_PATH"gx_VSMJ_number_5.gif","Number 5 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_6,VSMJ_IMG_PATH"gx_VSMJ_number_6.gif","Number 6 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_7,VSMJ_IMG_PATH"gx_VSMJ_number_7.gif","Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_8,VSMJ_IMG_PATH"gx_VSMJ_number_8.gif","Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_NUMBER_9,VSMJ_IMG_PATH"gx_VSMJ_number_9.gif","Number 9 Image");

	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_ARROWHEAD,	VSMJ_IMG_PATH"gx_vsmj_arrowhead.gif","Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_TOP_SOLID,	VSMJ_IMG_PATH"gx_vsmj_user_top_solid.gif","Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_BOTTOM_SOLID,	VSMJ_IMG_PATH"gx_vsmj_user_bottom_solid.gif","Number 9 Image");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_EATCASE_BG1,	VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG1.gif","Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_EATCASE_BG2,	VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG2.gif","Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_EATCASE_BG3,	VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_BG3.gif","Number 9 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_EATCASE_HIGHLIGHT,	VSMJ_IMG_PATH"gx_vsmj_sign_eatcase_highlight.gif","Number 7 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GUNCASE_BG1,	VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG1.gif","Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GUNCASE_BG2,	VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG2.gif","Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GUNCASE_BG3,	VSMJ_IMG_PATH"gx_vsmj_sign_guncase_BG3.gif","Number 9 Image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GX_VSMJ_GUNCASE_HIGHLIGHT,	VSMJ_IMG_PATH"gx_vsmj_sign_guncase_highlight.gif","Number 7 Image");
}
#endif /* IS_VSMJ_BASE_GAME */	

/************************************************************************/
/* Games																						*/		
/************************************************************************/
void PopulateGamesRes(void)
{
	/* create string */
	ADD_APPLICATION_STRING2(STR_GAME_CAPTION,		"Games","Caption string");
	ADD_APPLICATION_STRING2(STR_GAME_LSK,			"Select","LSK String");

	ADD_APPLICATION_STRING2(STR_GAME_NEW,			"Start Game","Start Menu String");	
	ADD_APPLICATION_STRING2(STR_GAME_LEVEL,		"Game Level","Resume Menu String");	
	ADD_APPLICATION_STRING2(STR_GAME_GRADE,		"Best Grades","Grades Menu-Caption String");	
	ADD_APPLICATION_STRING2(STR_GAME_HELP,			"Game Help","Help Menu-Caption String");	
	ADD_APPLICATION_STRING2(STR_GAME_RESUME,		"Resume","Resume Menu String");	
	ADD_APPLICATION_STRING2(STR_GAME_RESET,		"Reset","Game Score Reset LSK String");	
	ADD_APPLICATION_STRING2(STR_GAME_SCORE,		"Score","Score string");	
	ADD_APPLICATION_STRING2(STR_MENU3105_GAMES,	"Games","Games menu");

	/* game seting */
	ADD_APPLICATION_STRING2(STR_ID_GAME_SETTING, "Game Setting", "Game Settings");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GAME_SETTING, CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_FGST.pbm",	"effect setting");

	ADD_APPLICATION_STRING2(STR_ID_GAME_SETTING_AUD, "Game Audio",	"Game Audio setting");

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
	ADD_APPLICATION_STRING2(STR_ID_GAME_SETTING_MULTICHANNEL_BACKGROUND_MUSIC, "BGM",	"Game Audio setting");
	ADD_APPLICATION_STRING2(STR_ID_GAME_SETTING_MULTICHANNEL_SOUND_EFFECT, "Sound Effect",	"Game Audio setting");
#endif  /*__MMI_GAME_MULTICHANNEL_SOUND__*/
	ADD_APPLICATION_STRING2(STR_ID_GAME_SETTING_VIB, "Game Vibration",	"Game Vibration setting");	
	ADD_APPLICATION_IMAGE2(IMG_ID_GAME_SETTING_AUD, CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEAUD.pbm",	"Game Audio Icon");	
	#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
		ADD_APPLICATION_IMAGE2(IMG_ID_GAME_SETTING_BACK_AUD, CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEBACKAUD.pbm",	"Game BACK Audio Icon");	
#endif  /*__MMI_GAME_MULTICHANNEL_SOUND__*/
	ADD_APPLICATION_IMAGE2(IMG_ID_GAME_SETTING_VIB, CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Funandgame\\\\Gamesetting\\\\SB_GAMEVIB.pbm",	"Game Vib Icon");	


	/* create image */
	ADD_APPLICATION_IMAGE2(IMG_MENU3105_GAMES,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_FGGAME.PBM","Games image");
	ADD_APPLICATION_IMAGE2(IMG_ID_GAME_SUBLCD_ICON,CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\sb_game.bmp","Sublcd games icon");


#ifdef IS_F1RACE_BASE_GAME
/* under construction !*/
#endif /* IS_F1RACE_BASE_GAME */

#ifdef IS_HANOI_BASE_GAME
/* under construction !*/
#endif /* IS_HANOI_BASE_GAME */

#ifdef IS_RICHES_BASE_GAME
	PopulateRichesRes();
#endif /* IS_RICHES_BASE_GAME */

#ifdef IS_COLORBALL_BASE_GAME
/* under construction !*/
#endif /* IS_COLORBALL_BASE_GAME */

#ifdef IS_SNAKE_BASE_GAME
/* under construction !*/
#endif /* IS_SNAKE_BASE_GAME */

#ifdef IS_SMASH_BASE_GAME
/* under construction !*/
#endif /* IS_SMASH_BASE_GAME */

#ifdef IS_DOLL_BASE_GAME
/* under construction !*/
#endif /* IS_DOLL_BASE_GAME */

#ifdef IS_MAJUNG_BASE_GAME
	PopulateMajungRes();
#endif  /* IS_MAJUNG_BASE_GAME */

#ifdef IS_COPTER_BASE_GAME
/* under construction !*/
#endif /* IS_COPTER_BASE_GAME */

#ifdef IS_PUZZLE_BASE_GAME
	PopulatePuzzleRes();
#endif /* IS_PUZZLE_BASE_GAME */

#ifdef IS_PANDA_BASE_GAME
/* under construction !*/
#endif /* IS_PANDA_BASE_GAME */

#ifdef IS_STAIR_BASE_GAME
/* under construction !*/
#endif /* IS_STAIR_BASE_GAME */

#ifdef IS_UFO_BASE_GAME 
/* under construction !*/
#endif /* IS_UFO_BASE_GAME */

#ifdef IS_DANCE_BASE_GAME
/* under construction !*/
#endif /* IS_DANCE_BASE_GAME */

#ifdef IS_MAGICSUSHI_BASE_GAME
	PopulateMagicsushiRes();
#endif /* IS_MAGICBALLOON_BASE_GAME */

#ifdef IS_FRUIT_BASE_GAME
	PopulateFruitRes();
#endif /* IS_FRUIT_BASE_GAME */

#ifdef IS_VSMJ_BASE_GAME
	PopulateVsmjRes();
#endif /* IS_VSMJ_BASE_GAME */
}


#endif /* __MMI_GAME__ */


/*****************************************************************************
*
*	Motion Sensor Applications
*
*****************************************************************************/
#ifdef __MMI_MOTION_APP__

#include "FunAndGamesResDef.h"
#include "GameResDef.h"

#ifdef IS_DICE_BASE_MOTIONGAME
#include "MotionDiceResDef.h"
#endif /* IS_DICE_BASE_MOTIONGAME */

#ifdef IS_DJ_BASE_MOTIONGAME
#include "MotionDJResDef.h"
#endif /* IS_DJ_BASE_MOTIONGAME */


/*****************************************************************************
* FUNCTION
*	 PopulateMotionDiceRes()
* DESCRIPTION
*   populate motion game - dice
* PARAMETERS
*	 nil
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#ifdef IS_DICE_BASE_MOTIONGAME
void PopulateMotionDiceRes(void)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/	

  	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_APP,						"Dice", "STR_ID_MOTION_DICE_APP");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_START,					"Start","STR_ID_MOTION_DICE_START");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_GAME_SETTING,			"Game Setting","STR_ID_MOTION_DICE_GAME_SETTING");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_SETTING,		"Event Setting","STR_ID_MOTION_DICE_EVENT_SETTING");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_DICE_COUNT,			"Dice Number","STR_ID_MOTION_DICE_DICE_COUNT");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_SHOW_EVENT,			"Show Event","STR_ID_MOTION_DICE_SHOW_EVENT");
        ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_SOUND_SWITCH,			"Sound","STR_ID_MOTION_DICE_SOUND_SWITCH");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_OPTION,					"Option","STR_ID_MOTION_DICE_OPTION");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_OPTION_ADD,			"Add","STR_ID_MOTION_DICE_OPTION_ADD");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_OPTION_REMOVE,		"Remove","STR_ID_MOTION_DICE_OPTION_REMOVE");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_OPTION_EDIT,			"Edit","STR_ID_MOTION_DICE_OPTION_EDIT");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_EDIT,			"Edit Event","STR_ID_MOTION_DICE_EVENT_EDIT");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_MATCH_NUM,		"Match Number","STR_ID_MOTION_DICE_EVENT_MATCH_NUM");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_TEXT,			"Text","STR_ID_MOTION_DICE_EVENT_TEXT");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_DEFAULT_TEXT,	"Event","STR_ID_MOTION_DICE_EVENT_DEFAULT_TEXT");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_EFFECT_FILE,	"Effect File","STR_ID_MOTION_DICE_EVENT_EFFECT_FILE");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_FILE_NONE,		"None","STR_ID_MOTION_DICE_EVENT_FILE_NONE");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_FILE_SELECT,	"Select From File","STR_ID_MOTION_DICE_EVENT_FILE_SELECT");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_EDITOR_TITLE,	"Text Editor","STR_ID_MOTION_DICE_EVENT_EDITOR_TITLE");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO,	"Play Video","STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO,	"Play Audio","STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE,	"View Image","STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_REMOVE_CONFIRM,		"Remove?","STR_ID_MOTION_DICE_REMOVE_CONFIRM");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_REMOVED,		"Removed","STR_ID_MOTION_DICE_EVENT_REMOVED");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_SAVE_CONFIRM,			"Save Change?","STR_ID_MOTION_DICE_SAVE_CONFIRM");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_NUMBER_REGION,		"Valid Number","STR_ID_MOTION_DICE_NUMBER_REGION");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_DUP_NUMBER,			"Number Duplicated","STR_ID_MOTION_DICE_DUP_NUMBER");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_EVENT_FULL,			"Events Full","STR_ID_MOTION_DICE_EVENT_FULL");			
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_1,						"1","STR_ID_MOTION_DICE_1");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_2,						"2","STR_ID_MOTION_DICE_1");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_3,						"3","STR_ID_MOTION_DICE_1");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_4,						"4","STR_ID_MOTION_DICE_1");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_5,						"5","STR_ID_MOTION_DICE_1");			
        ADD_APPLICATION_STRING2(STR_ID_MOTION_DICE_INVALID_FILE,						"Invalid File","STR_ID_MOTIONDICE_INVALID_FILE");	

	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_APP, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_app.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_1, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_1.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_2, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_2.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_3, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_3.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_4, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_4.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_5, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_5.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_6, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_6.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_7, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_7.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_8, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_8.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_9, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_9.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_10, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_10.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_11, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_11.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_12, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_12.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_13, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_13.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_14, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_14.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_15, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_15.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_16, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_16.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_17, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_17.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_18, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_18.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_19, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_19.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_20, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_20.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_21, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_21.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_22, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_22.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_23, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_23.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_24, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_24.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_25, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_25.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_26, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_26.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_27, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_27.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_28, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_28.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_29, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_29.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ICON_30, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_30.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_1, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_1.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_2, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_2.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_3, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_3.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_4, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_4.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_5, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_5.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_6, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_6.pbm","Dice");	

	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_1, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_01.pbm","Dice");		
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_2, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_02.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_3, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_03.pbm","Dice");		
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_4, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_04.pbm","Dice");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_5, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_05.pbm","Dice");	

	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_6, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_06.pbm","Dice");		
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_7, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_07.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_8, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_08.pbm","Dice");		
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_9, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_09.pbm","Dice");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_10, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_10.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_11, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_11.pbm","Dice");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_ROLL_12, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_roll_12.pbm","Dice");	

	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_1, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_1.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_2, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_2.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_3, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_3.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_4, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_4.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_5, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_5.pbm","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_6, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_6.pbm","Dice");		
	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_PLAY_BG, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_bg.gif","Dice");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_BG, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_bg.gif","Dice");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_EVENT_DEFAULT_IMG, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_event_def.gif","Dice");		

	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_FX_ICON_DUMMY, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_dummy.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_FX_ICON_AUD, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_aud.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_FX_ICON_VDO, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_vdo.pbm","Dice");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DICE_FX_ICON_IMG, CUST_IMG_BASE_PATH"\\\\GameImages\\\\Dice\\\\dice_icon_img.pbm","Dice");	

	/* App Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_APP, 
										MENU_ID_MOTION_APP,
										3,
										MENU_ID_MOTION_DICE_START,
										MENU_ID_MOTION_DICE_GAME_SETTING,
										MENU_ID_MOTION_DICE_EVENT_SETTING,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_APP,
										IMG_ID_MOTION_DICE_APP));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_START, MENU_ID_MOTION_DICE_APP,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_START,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_GAME_SETTING, MENU_ID_MOTION_DICE_APP,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_GAME_SETTING,0));
	
	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EVENT_SETTING, MENU_ID_MOTION_DICE_APP,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_EVENT_SETTING,0));	

	/* Event Option Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_OPTION, 
										0,
										3,
										MENU_ID_MOTION_DICE_OPTION_ADD,
										MENU_ID_MOTION_DICE_OPTION_REMOVE,
										MENU_ID_MOTION_DICE_OPTION_EDIT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_OPTION,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_OPTION_ADD, MENU_ID_MOTION_DICE_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_OPTION_ADD,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_OPTION_REMOVE, MENU_ID_MOTION_DICE_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_OPTION_REMOVE,0));
	
	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_OPTION_EDIT, MENU_ID_MOTION_DICE_OPTION,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_OPTION_EDIT,0));	

	/* Editor Option */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_EDT_OPT_ROOT, 
										0,
										3,
										MENU_ID_MOTION_DICE_EDT_OPT_DONE,
										MENU_ID_MOTION_DICE_EDT_OPT_CANCEL,
										MENU_ID_MOTION_DICE_EDT_OPT_INPUT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_GLOBAL_OPTIONS,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EDT_OPT_DONE, MENU_ID_MOTION_DICE_EDT_OPT_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_DONE,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EDT_OPT_CANCEL, MENU_ID_MOTION_DICE_EDT_OPT_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_CANCEL,0));
	
	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EDT_OPT_INPUT, MENU_ID_MOTION_DICE_EDT_OPT_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_GLOBAL_INPUT_METHOD,0));	
	
	/* Select File */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_EVENT_FILE_SELECT_ROOT, 
										0,
										1,
										MENU_ID_MOTION_DICE_EVENT_FILE_SELECT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_EVENT_EFFECT_FILE,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EVENT_FILE_SELECT, MENU_ID_MOTION_DICE_EVENT_FILE_SELECT_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_EVENT_FILE_SELECT,0));

	/* Select File + View Image */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE_ROOT, 
										0,
										2,
										MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE,
										MENU_ID_MOTION_DICE_EVENT_FILE_SELECT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_EVENT_EFFECT_FILE,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE, MENU_ID_MOTION_DICE_EVENT_VIEW_IMAGE_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE,0));


	/* Select File + Play Video */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO_ROOT, 
										0,
										2,
										MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO,
										MENU_ID_MOTION_DICE_EVENT_FILE_SELECT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_EVENT_EFFECT_FILE,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO, MENU_ID_MOTION_DICE_EVENT_PLAY_VIDEO_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO,0));

	/* Select File + Play Audio */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO_ROOT, 
										0,
										2,
										MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO,
										MENU_ID_MOTION_DICE_EVENT_FILE_SELECT,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_EVENT_EFFECT_FILE,
										0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO, MENU_ID_MOTION_DICE_EVENT_PLAY_AUDIO_ROOT,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO,0));
	
}
#endif /* IS_DICE_BASE_MOTIONGAME */



/*****************************************************************************
* FUNCTION
*	 PopulateMotionDJRes()
* DESCRIPTION
*   populate motion game - dj
* PARAMETERS
*	 nil
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#ifdef IS_DJ_BASE_MOTIONGAME
void PopulateMotionDJRes(void)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/	

  	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_APP,		"Music DJ", "STR_ID_MOTION_DJ_APP");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_START,		"Start", "STR_ID_MOTION_DJ_START");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_SETTING,	"Music Setting", "STR_ID_MOTION_DJ_SETTING");
	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1,	"Instrument 1", "STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_TITLE_2,	"Instrument 2", "STR_ID_MOTION_DJ_INSTRUMENT_TITLE_2");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_TITLE_3,	"Instrument 3", "STR_ID_MOTION_DJ_INSTRUMENT_TITLE_3");	
	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_TITLE_1,	"Vocal 1", "STR_ID_MOTION_DJ_VOCAL_TITLE_1");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_TITLE_2,	"Vocal 2", "STR_ID_MOTION_DJ_VOCAL_TITLE_2");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_TITLE_3,	"Vocal 3", "STR_ID_MOTION_DJ_VOCAL_TITLE_3");	

	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_0,	"Ins 0", "STR_ID_MOTION_DJ_INSTRUMENT_0");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_1,	"Ins 1", "STR_ID_MOTION_DJ_INSTRUMENT_1");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_2,	"Ins 2", "STR_ID_MOTION_DJ_INSTRUMENT_2");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_3,	"Ins 3", "STR_ID_MOTION_DJ_INSTRUMENT_3");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_4,	"Ins 4", "STR_ID_MOTION_DJ_INSTRUMENT_4");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_5,	"Ins 5", "STR_ID_MOTION_DJ_INSTRUMENT_5");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_6,	"Ins 6", "STR_ID_MOTION_DJ_INSTRUMENT_6");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_7,	"Ins 7", "STR_ID_MOTION_DJ_INSTRUMENT_7");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_8,	"Ins 8", "STR_ID_MOTION_DJ_INSTRUMENT_8");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_INSTRUMENT_9,	"Ins 9", "STR_ID_MOTION_DJ_INSTRUMENT_9");	

	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_0,	"Vox 0", "STR_ID_MOTION_DJ_VOCAL_0");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_1,	"Vox 1", "STR_ID_MOTION_DJ_VOCAL_1");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_2,	"Vox 2", "STR_ID_MOTION_DJ_VOCAL_2");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_3,	"Vox 3", "STR_ID_MOTION_DJ_VOCAL_3");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_4,	"Vox 4", "STR_ID_MOTION_DJ_VOCAL_4");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_5,	"Vox 5", "STR_ID_MOTION_DJ_VOCAL_5");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_6,	"Vox 6", "STR_ID_MOTION_DJ_VOCAL_6");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_7,	"Vox 7", "STR_ID_MOTION_DJ_VOCAL_7");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_8,	"Vox 8", "STR_ID_MOTION_DJ_VOCAL_8");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_VOCAL_9,	"Vox 9", "STR_ID_MOTION_DJ_VOCAL_9");	

	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_0,			"Key 0", "STR_ID_MOTION_DJ_KEY_0");
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_1,			"Key 1", "STR_ID_MOTION_DJ_KEY_1");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_2,			"Key 2", "STR_ID_MOTION_DJ_KEY_2");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_3,			"Key 3", "STR_ID_MOTION_DJ_KEY_3");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_4,			"Key 4", "STR_ID_MOTION_DJ_KEY_4");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_5,			"Key 5", "STR_ID_MOTION_DJ_KEY_5");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_6,			"Key 6", "STR_ID_MOTION_DJ_KEY_6");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_7,			"Key 7", "STR_ID_MOTION_DJ_KEY_7");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_8,			"Key 8", "STR_ID_MOTION_DJ_KEY_8");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_9,			"Key 9", "STR_ID_MOTION_DJ_KEY_9");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_STAR,		"Key *", "STR_ID_MOTION_DJ_KEY_STAR");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_KEY_POUND,	"Key #", "STR_ID_MOTION_DJ_KEY_POUND");	

	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_AUDIO,		"Audio", "STR_ID_MOTION_DJ_EDIT_AUDIO");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_VOLUME,		"Volume", "STR_ID_MOTION_DJ_EDIT_VOLUME");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_TRIGGER,	"Trigger", "STR_ID_MOTION_DJ_EDIT_TRIGGER");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_KEY,			"Key", "STR_ID_MOTION_DJ_EDIT_KEY");		

	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO,			"Auto", "STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_TRIGGER_SHAKE,		"Shake", "STR_ID_MOTION_DJ_EDIT_TRIGGER_SHAKE");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_EDIT_TRIGGER_KEY_PRESS,	"Key Press", "STR_ID_MOTION_DJ_EDIT_TRIGGER_KEY_PRESS");		

	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO,				"Already has [Auto] trigger", "STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO");	
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE,				"Already has [Shake]", "STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY,	"Already has [Shake] trigger with same key", "STR_ID_MOTION_DJ_NOTIFY_HAS_SAME_KEY");		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_NOTIFY_HAS_PRESS_SAME_KEY,	"Already has [Key Press] trigger with same key", "STR_ID_MOTION_DJ_NOTIFY_HAS_SAME_KEY");			
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER,			"Please set trigger first", "STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER");				
	ADD_APPLICATION_STRING2(STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY,				"Key is not set", "STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY");				



	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_APP, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_app.pbm","DJ");
	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_TRIGGER_NONE, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_icon_none.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_TRIGGER_AUTO, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_icon_auto.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_TRIGGER_SHAKE, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_icon_shake.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_TRIGGER_PRESS, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_icon_press.pbm","DJ");
	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_DUMMY , CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_dummy.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_0, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_0.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_1, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_1.pbm","DJ");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_2, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_2.pbm","DJ");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_3, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_3.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_4, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_4.pbm","DJ");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_5, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_5.pbm","DJ");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_6, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_6.pbm","DJ");			
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_7, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_7.pbm","DJ");		
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_8, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_8.pbm","DJ");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_9 , CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_9.pbm","DJ");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_STAR , CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_star.pbm","DJ");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_ICON_KEY_POUND , CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_key_pound.pbm","DJ");	

	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_BG,			CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_bg.gif","DJ");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_NONE, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_none.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_AUTO, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_auto.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_AUTO_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_auto_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_SHAKE, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_shake.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_SHAKE_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_shake_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_PRESS, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_press.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_PRESS_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_press_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_0, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_0.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_0_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_0_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_1, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_1.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_1_SEL,	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_1_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_2,	 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_2.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_2_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_2_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_3, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_3.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_3_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_3_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_4, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_4.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_4_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_4_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_5, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_5.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_5_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_5_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_6, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_6.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_6_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_6_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_7, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_7.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_7_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_7_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_8, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_8.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_8_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_8_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_9, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_9.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_9_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_9_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_STAR, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_star.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_STAR_SEL, 	CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_star_sel.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_POUND, 		CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_pound.pbm","DJ");	
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_DJ_PLAY_KEY_POUND_SEL, CUST_IMG_BASE_PATH"\\\\GameImages\\\\DJ\\\\dj_play_key_pound_sel.pbm","DJ");	

	/* App Menu */
	ADD_APPLICATION_MENUITEM((	MENU_ID_MOTION_DJ_APP, 
										MENU_ID_MOTION_APP,
										2,
										MENU_ID_MOTION_DJ_START,
										MENU_ID_MOTION_DJ_SETTING,
										SHOW,
										NONMOVEABLE,
										DISP_LIST,
										STR_ID_MOTION_DICE_APP,
										IMG_ID_MOTION_DICE_APP));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DJ_START, MENU_ID_MOTION_DJ_APP,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DJ_START,0));

	ADD_APPLICATION_MENUITEM((MENU_ID_MOTION_DJ_SETTING, MENU_ID_MOTION_DJ_APP,0,
					SHOW,NONMOVEABLE,1,STR_ID_MOTION_DJ_SETTING,0));

}
#endif /* IS_DJ_BASE_MOTIONGAME */



/*****************************************************************************
* FUNCTION
*	 PopulateMotionAppRes()
* DESCRIPTION
*   populate motion app's resource
* PARAMETERS
*	 nil
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
void PopulateMotionAppRes(void)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/		
	ADD_APPLICATION_STRING2(STR_ID_MOTION_APP, "Motion Games","STR_ID_MOTION_APP");
	ADD_APPLICATION_IMAGE2(IMG_ID_MOTION_APP,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_MOTION.PBM","IMG_ID_MOTION_APP");


	#ifdef IS_DICE_BASE_MOTIONGAME
		PopulateMotionDiceRes();
	#endif /* IS_DICE_BASE_MOTIONGAME */

	#ifdef IS_DJ_BASE_MOTIONGAME
		PopulateMotionDJRes();
	#endif /* IS_DJ_BASE_MOTIONGAMEs */
	
}

#endif /* __MMI_MOTION_APP__ */


#ifdef __MMI_3D_GAME__

#include "FunAndGamesResDef.h"
#include "GameResDef.h"
#include "PopulateRes.h"
#include "CustResDef.h"

/*****************************************************************************
* FUNCTION
*	 Populate3DGameRes()
* DESCRIPTION
*   populate 3d game's resource
* PARAMETERS
*	 nil
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
void Populate3DGameRes(void)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/		
	ADD_APPLICATION_STRING2(STR_ID_3D_GAME, "3D Game","STR_ID_3D_GAME");
	ADD_APPLICATION_STRING2(STR_ID_3D_GAME_TERMINATE_JAVA, 
	                        "Insufficient memory. Terminate Java first.",
	                        "STR_ID_3D_GAME_TERMINATE_JAVA");

	
	ADD_APPLICATION_IMAGE2(
		IMG_ID_3D_GAME,
		CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\FunANDGame\\\\SB_3DGAME.PBM",
		"IMG_ID_3D_GAME");

	 
#if defined(__MMI_3D_GAME_BROGENT_GGR2_240x320__) || defined(__MMI_3D_GAME_BROGENT_GGR2_176x220__)
	ADD_APPLICATION_STRING2(
		STR_ID_3D_GAME_BROGENT_GOGOROBOT, 
		"GoGoRobot",
		"STR_ID_3D_GAME_BROGENT_GOGOROBOT");
	
	ADD_APPLICATION_IMAGE2(
		IMG_ID_3D_GAME_BROGENT_GOGOROBOT,
		CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Funandgame\\\\3DGame\\\\GoGoRobot.pbm",		
		"IMG_ID_3D_GAME_BROGENT_GOGOROBOT");
#endif /* defined(__MMI_3D_GAME_BROGENT_GGR2_240x320__) || defined(__MMI_3D_GAME_BROGENT_GGR2_176x220__) */


	 
#if defined(__MMI_3D_GAME_BROGENT_HB2_240x320__) || defined(__MMI_3D_GAME_BROGENT_HB2_176x220__) 
	ADD_APPLICATION_STRING2(
		STR_ID_3D_GAME_BROGENT_HEATBREAKER2, 
		"HeatBreaker",
		"STR_ID_3D_GAME_BROGENT_HEATBREAKER2");
	
	ADD_APPLICATION_IMAGE2(
		IMG_ID_3D_GAME_BROGENT_HEATBREAKER2,
		CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Funandgame\\\\3DGame\\\\HeatBreaker2.pbm",
		"IMG_ID_3D_GAME_BROGENT_HEATBREAKER2");
#endif /* defined(__MMI_3D_GAME_BROGENT_HB2_240x320__) || defined(__MMI_3D_GAME_BROGENT_HB2_176x220__)  */


#if defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_DEMOGAME_176x220__) 
	ADD_APPLICATION_STRING2(
		STR_ID_3D_GAME_INTERGRAFX_DEMOGAME, 
		"DemoGame",
		"STR_ID_3D_GAME_INTERGRAFX_DEMOGAME");
	
	ADD_APPLICATION_IMAGE2(
		IMG_ID_3D_GAME_INTERGRAFX_DEMOGAME,
		CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Funandgame\\\\3DGame\\\\DemoGame.pbm",
		"IMG_ID_3D_GAME_INTERGRAFX_DEMOGAME");
#endif /* defined(__MMI_3D_GAME_BROGENT_HB2_240x320__) || defined(__MMI_3D_GAME_BROGENT_HB2_176x220__)  */

#if defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_176x220__) 
	ADD_APPLICATION_STRING2(
		STR_ID_3D_GAME_INTERGRAFX_PETFISH, 
		"PetFish",
		"STR_ID_3D_GAME_INTERGRAFX_PETFISH");
	
	ADD_APPLICATION_IMAGE2(
		IMG_ID_3D_GAME_INTERGRAFX_PETFISH,
		CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Funandgame\\\\3DGame\\\\PETFISH.pbm",
		"IMG_ID_3D_GAME_INTERGRAFX_PETFISH");
#endif /* defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_PETFISH_176x220__)  */

#if defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_176x220__)
	ADD_APPLICATION_STRING2(
		STR_ID_3D_GAME_INTERGRAFX_ROLLINGBALL, 
		"Rolling Ball",
		"STR_ID_3D_GAME_INTERGRAFX_ROLLINGBALL");
	
	ADD_APPLICATION_IMAGE2(
		IMG_ID_3D_GAME_INTERGRAFX_ROLLINGBALL,
		CUST_IMG_PATH"\\\\MainLCD\\\\Submenu\\\\Funandgame\\\\3DGame\\\\ROLLINGBALL.pbm",
		"IMG_ID_3D_GAME_INTERGRAFX_ROLLINGBALL");
#endif /* defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_240x320__) || defined(__MMI_3D_GAME_INTERGRAFX_ROLLINGBALL_176x220__)*/

	
}

#endif /* __MMI_3D_GAME__ */


