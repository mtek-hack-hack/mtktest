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
 * PuzzleDefs_128x160.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game id define Puzzle.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_GX_PUZZLE_DEFS_H
#define _MMI_GX_PUZZLE_DEFS_H

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* String ID */
typedef enum
{
    STR_ID_GX_PUZZLE_GAME_NAME = GAME_PUZZLE_BASE + 1,
    STR_ID_GX_PUZZLE_NEW,
    STR_ID_GX_PUZZLE_RESUME,
    STR_ID_GX_PUZZLE_LEVEL,
    STR_ID_GX_PUZZLE_SCORE,
    STR_ID_GX_PUZZLE_HELP,
    STR_ID_GX_PUZZLE_LEVEL_EASY,
    STR_ID_GX_PUZZLE_LEVEL_NORMAL,
    STR_ID_GX_PUZZLE_LEVEL_HARD,
#if defined(__MMI_TOUCH_SCREEN__)
    STR_ID_GX_PUZZLE_HELP_DESCRIPTION_TP,
#elif defined(__MMI_GAME_PUZZLE_128x128__)
    STR_ID_GX_PUZZLE_HELP_DESCRIPTION_128,
#else 
    STR_ID_GX_PUZZLE_HELP_DESCRIPTION,
#endif 
    STR_ID_GX_PUZZLE_COUNT
} gx_puzzle_str_id_enum;

/* Image ID */
typedef enum
{
    IMG_ID_GX_PUZZLE_GAME_ICON = GAME_PUZZLE_BASE + 1,
    IMG_ID_GX_PUZZLE_NUMBER_0,
    IMG_ID_GX_PUZZLE_NUMBER_1,
    IMG_ID_GX_PUZZLE_NUMBER_2,
    IMG_ID_GX_PUZZLE_NUMBER_3,
    IMG_ID_GX_PUZZLE_NUMBER_4,
    IMG_ID_GX_PUZZLE_NUMBER_5,
    IMG_ID_GX_PUZZLE_NUMBER_6,
    IMG_ID_GX_PUZZLE_NUMBER_7,
    IMG_ID_GX_PUZZLE_NUMBER_8,
    IMG_ID_GX_PUZZLE_NUMBER_9,
    IMG_ID_GX_PUZZLE_BOX,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_PUZZLE_STEP,
    IMG_ID_GX_PUZZLE_TIME,
#endif
    IMG_ID_GX_PUZZLE_LEFT_BAR,
    IMG_ID_GX_PUZZLE_RIGHT_BAR,
    IMG_ID_GX_PUZZLE_TOP_BAR,
    IMG_ID_GX_PUZZLE_BOTTOM_BAR,
    IMG_ID_GX_PUZZLE_SMALL_3,
    IMG_ID_GX_PUZZLE_SMALL_4,
    IMG_ID_GX_PUZZLE_SMALL_5,
    IMG_ID_GX_PUZZLE_3_1,
    IMG_ID_GX_PUZZLE_3_2,
    IMG_ID_GX_PUZZLE_3_3,
    IMG_ID_GX_PUZZLE_3_4,
    IMG_ID_GX_PUZZLE_3_5,
    IMG_ID_GX_PUZZLE_3_6,
    IMG_ID_GX_PUZZLE_3_7,
    IMG_ID_GX_PUZZLE_3_8,
    IMG_ID_GX_PUZZLE_3_SPACE,
    IMG_ID_GX_PUZZLE_4_1,
    IMG_ID_GX_PUZZLE_4_2,
    IMG_ID_GX_PUZZLE_4_3,
    IMG_ID_GX_PUZZLE_4_4,
    IMG_ID_GX_PUZZLE_4_5,
    IMG_ID_GX_PUZZLE_4_6,
    IMG_ID_GX_PUZZLE_4_7,
    IMG_ID_GX_PUZZLE_4_8,
    IMG_ID_GX_PUZZLE_4_9,
    IMG_ID_GX_PUZZLE_4_10,
    IMG_ID_GX_PUZZLE_4_11,
    IMG_ID_GX_PUZZLE_4_12,
    IMG_ID_GX_PUZZLE_4_13,
    IMG_ID_GX_PUZZLE_4_14,
    IMG_ID_GX_PUZZLE_4_15,
    IMG_ID_GX_PUZZLE_4_SPACE,
    IMG_ID_GX_PUZZLE_5_1,
    IMG_ID_GX_PUZZLE_5_2,
    IMG_ID_GX_PUZZLE_5_3,
    IMG_ID_GX_PUZZLE_5_4,
    IMG_ID_GX_PUZZLE_5_5,
    IMG_ID_GX_PUZZLE_5_6,
    IMG_ID_GX_PUZZLE_5_7,
    IMG_ID_GX_PUZZLE_5_8,
    IMG_ID_GX_PUZZLE_5_9,
    IMG_ID_GX_PUZZLE_5_10,
    IMG_ID_GX_PUZZLE_5_11,
    IMG_ID_GX_PUZZLE_5_12,
    IMG_ID_GX_PUZZLE_5_13,
    IMG_ID_GX_PUZZLE_5_14,
    IMG_ID_GX_PUZZLE_5_15,
    IMG_ID_GX_PUZZLE_5_16,
    IMG_ID_GX_PUZZLE_5_17,
    IMG_ID_GX_PUZZLE_5_18,
    IMG_ID_GX_PUZZLE_5_19,
    IMG_ID_GX_PUZZLE_5_20,
    IMG_ID_GX_PUZZLE_5_21,
    IMG_ID_GX_PUZZLE_5_22,
    IMG_ID_GX_PUZZLE_5_23,
    IMG_ID_GX_PUZZLE_5_24,
    IMG_ID_GX_PUZZLE_5_25,
    IMG_ID_GX_PUZZLE_5_SPACE,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_PUZZLE_GOTEXT,
#endif
    IMG_ID_GX_PUZZLE_GRADESMAP,
    IMG_ID_GX_PUZZLE_GOPIC,
#if defined(__MMI_TOUCH_SCREEN__)
    IMG_ID_GX_PUZZLE_UP,
    IMG_ID_GX_PUZZLE_DOWN,
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    //added for multi-language support
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE0,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE1,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE2,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE3,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE4,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE5,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE6,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE7,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE8,
    IMG_ID_GX_PUZZLE_GOTEXT_LANGUAGE9,
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */
    IMG_ID_GX_PUZZLE_COUNT
} gx_puzzle_img_id_neum;

#endif /* _MMI_GX_PUZZLE_DEFS_H */ 

