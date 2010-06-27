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
 *  GameDefs.h
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

#ifndef GAME_DEF_H
#define GAME_DEF_H

#include "MMIDataType.h"
#include "SettingDefs.h"
#include "MMI_features.h"

#include "GameResDef.h"

/* skip audio align in PC environment */
#ifndef __MTK_TARGET__
#define __align(X)
#endif 

typedef enum
{
#ifdef IS_F1RACE_BASE_GAME
/* under construction !*/
#endif 

#ifdef IS_HANOI_BASE_GAME
/* under construction !*/
#endif 

#ifdef IS_RICHES_BASE_GAME
    game_riches,
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
    game_majung,
#endif 

#ifdef IS_COPTER_BASE_GAME
/* under construction !*/
#endif 

#ifdef IS_PUZZLE_BASE_GAME
    game_puzzle,
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
    game_magicsushi,
#endif 

#ifdef IS_FRUIT_BASE_GAME
    game_fruit,
#endif 

#ifdef IS_VSMJ_BASE_GAME
    game_vsmj,
#endif 

    game_list_count
} GAME_LIST_NEUM;

typedef enum
{

#ifdef IS_DICE_BASE_MOTIONGAME
    motion_dice,
#endif 

#ifdef IS_DJ_BASE_MOTIONGAME
    motion_dj,
#endif 

    motion_list_count
} MOTION_LIST_NEUM;

#define GAME_NOTIFYDURATION                  ST_NOTIFYDURATION

#endif /* GAME_DEF_H */ 

