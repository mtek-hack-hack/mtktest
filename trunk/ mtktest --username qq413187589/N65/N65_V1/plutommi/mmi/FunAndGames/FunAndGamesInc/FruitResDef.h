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
*  THE TRANSACTION CONFRUITD HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
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
 * GameFruitDefs.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game id define Fruit.
 *    replcae FRUIT with GAMENAME
 *    replcae Fruit with Gamename
 *    replcae fruit with gamename
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
BugFix] Fix re-entry gameover screen will play gameover sound problem.
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef GAME_FRUIT_DEFS_H
#define GAME_FRUIT_DEFS_H

typedef enum
{
    STR_ID_GX_FRUIT_GAME_NAME = GAME_FRUIT_BASE + 1,

    STR_ID_GX_FRUIT_NEW,
    STR_ID_GX_FRUIT_RESUME,
    STR_ID_GX_FRUIT_LEVEL,
    STR_ID_GX_FRUIT_GRADE,
    STR_ID_GX_FRUIT_HELP,

    STR_ID_GX_FRUIT_LEVEL_EASY,
    STR_ID_GX_FRUIT_LEVEL_NORMAL,
    STR_ID_GX_FRUIT_LEVEL_HARD,

    STR_ID_GX_FRUIT_HELP_DESCRIPTION,
    STR_ID_GX_FRUIT_COUNT   /* no use right now */
} mmi_fruit_str_id_enum;

/* Image ID */
typedef enum
{
    /* Image */
    IMG_ID_GX_FRUIT_GAME_ICON = GAME_FRUIT_BASE + 1,

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_FRUIT_GOTEXT,
#endif
    IMG_ID_GX_FRUIT_GRADESMAP,
    IMG_ID_GX_FRUIT_GOPIC,  /* gameover */
    IMG_ID_GX_FRUIT_COUNT,  /* no use right now */

    IMG_ID_GX_FRUIT_FRUIT_BASE,
    IMG_ID_GX_FRUIT_FOODA_ONE_PIECE,    /* item images */
    IMG_ID_GX_FRUIT_FOODA_TWO_PIECE,
    IMG_ID_GX_FRUIT_FOODA_THREE_PIECE,
    IMG_ID_GX_FRUIT_FOODA_MAX_PIECE,

    IMG_ID_GX_FRUIT_FOODB_ONE_PIECE,    /* item images */
    IMG_ID_GX_FRUIT_FOODB_TWO_PIECE,
    IMG_ID_GX_FRUIT_FOODB_THREE_PIECE,
    IMG_ID_GX_FRUIT_FOODB_MAX_PIECE,

    IMG_ID_GX_FRUIT_FOODC_ONE_PIECE,    /* item images */
    IMG_ID_GX_FRUIT_FOODC_TWO_PIECE,
    IMG_ID_GX_FRUIT_FOODC_THREE_PIECE,
    IMG_ID_GX_FRUIT_FOODC_MAX_PIECE,

    IMG_ID_GX_FRUIT_ROCK_ONEPIECE,  /* item images */

    IMG_ID_GX_FRUIT_TREASURE_1,
    IMG_ID_GX_FRUIT_TREASURE_2,
    IMG_ID_GX_FRUIT_TREASURE_3,
    IMG_ID_GX_FRUIT_TREASURE_4,
    IMG_ID_GX_FRUIT_TREASURE_5,

    IMG_ID_GX_FRUIT_SWDWAVEBASE,
    IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_A,
    IMG_ID_GX_FRUIT_SWDWAVELOW_LEFT_B,
    IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_A,
    IMG_ID_GX_FRUIT_SWDWAVEMID_LEFT_B,
    IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_A,
    IMG_ID_GX_FRUIT_SWDWAVEMAX_LEFT_B,
    IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_A,
    IMG_ID_GX_FRUIT_SWDWAVELOW_RIGHT_B,
    IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_A,
    IMG_ID_GX_FRUIT_SWDWAVEMID_RIGHT_B,
    IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_A,
    IMG_ID_GX_FRUIT_SWDWAVEMAX_RIGHT_B,
    IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_A,
    IMG_ID_GX_FRUIT_SWDWAVEKICK_LEFT_B,
    IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_A,
    IMG_ID_GX_FRUIT_SWDWAVEKICK_RIGHT_B,

    IMG_ID_GX_FRUIT_CHEF_BASE,
    IMG_ID_GX_FRUIT_CHEF_GAMEOVER,
    IMG_ID_GX_FRUIT_CHEF_RIGHT_CUTPREP, /* man cut image right */
    IMG_ID_GX_FRUIT_CHEF_RIGHT_CUT,
    IMG_ID_GX_FRUIT_CHEF_RIGHT_KICKPREP,
    IMG_ID_GX_FRUIT_CHEF_RIGHT_KICK,
    IMG_ID_GX_FRUIT_CHEF_LEFT_CUTPREP,  /* man cut image LEFT */
    IMG_ID_GX_FRUIT_CHEF_LEFT_CUT,
    IMG_ID_GX_FRUIT_CHEF_LEFT_KICKPREP,
    IMG_ID_GX_FRUIT_CHEF_LEFT_KICK,

    IMG_ID_GX_FRUIT_CHEF_FAINTA,        /* faint image ,differ by stars above head */
    IMG_ID_GX_FRUIT_CHEF_FAINTB,
    IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKA,   /* rightwalk icon1 */
    IMG_ID_GX_FRUIT_CHEF_RIGHT_WALKB,   /* rightwalk icon2 */
    IMG_ID_GX_FRUIT_CHEF_LEFT_WALKA,
    IMG_ID_GX_FRUIT_CHEF_LEFT_WALKB,

    IMG_ID_GX_FRUIT_SHAKER_OKA,     /* SHAKER just fine */
    IMG_ID_GX_FRUIT_SHAKER_OKB,
    IMG_ID_GX_FRUIT_SHAKER_PBLVA_A, /* having some problem */
    IMG_ID_GX_FRUIT_SHAKER_PBLVA_B,
    IMG_ID_GX_FRUIT_SHAKER_PBLVB_A, /* about to break down */
    IMG_ID_GX_FRUIT_SHAKER_PBLVB_B,
    IMG_ID_GX_FRUIT_SHAKER_BROKEN,

    IMG_ID_GX_FRUIT_WORKER_STEPA,   /* man to fix shaker */
    IMG_ID_GX_FRUIT_WORKER_STEPB,
    IMG_ID_GX_FRUIT_WORKER_FIXA,
    IMG_ID_GX_FRUIT_WORKER_FIXB,

    IMG_ID_GX_FRUIT_PLATFORM,
    IMG_ID_GX_FRUIT_TRACKA,
    IMG_ID_GX_FRUIT_TRACKB, /* track in operation */
    IMG_ID_GX_FRUIT_FRAME,  /* frame */

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_FRUIT_BGROUND,
#endif

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    //added for multi-language support
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE0,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE0,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE1,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE1,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE2,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE2,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE3,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE3,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE4,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE4,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE5,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE5,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE6,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE6,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE7,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE7,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE8,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE8,
    IMG_ID_GX_FRUIT_BGROUND_LANGUAGE9,
    IMG_ID_GX_FRUIT_GOTEXT_LANGUAGE9,
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    IMG_ID_GX_FRUIT_TOTAL
} mmi_fruit_img_id_enum;

#endif /* GAME_FRUIT_DEFS_H */ 

