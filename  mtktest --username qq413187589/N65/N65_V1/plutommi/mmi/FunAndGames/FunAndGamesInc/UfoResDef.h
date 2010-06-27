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
 * GameUfoDefs.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game id define Ufo.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMI_GX_UFO_DEFS_H
#define _MMI_GX_UFO_DEFS_H

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* String ID */
typedef enum
{
    STR_ID_GX_UFO_GAME_NAME = GAME_UFO_BASE + 1,
    STR_ID_GX_UFO_HELP_DESCRIPTION,
    STR_ID_GX_UFO_SCORE,
    STR_ID_GX_UFO_COUNT
} gx_ufo_str_id_enum;

/* Image ID */
typedef enum
{
    IMG_ID_GX_UFO_GAME_ICON = GAME_UFO_BASE + 1,
    IMG_ID_GX_UFO_DIGIT_0,
    IMG_ID_GX_UFO_DIGIT_1,
    IMG_ID_GX_UFO_DIGIT_2,
    IMG_ID_GX_UFO_DIGIT_3,
    IMG_ID_GX_UFO_DIGIT_4,
    IMG_ID_GX_UFO_DIGIT_5,
    IMG_ID_GX_UFO_DIGIT_6,
    IMG_ID_GX_UFO_DIGIT_7,
    IMG_ID_GX_UFO_DIGIT_8,
    IMG_ID_GX_UFO_DIGIT_9,
    IMG_ID_GX_UFO_BACKGROUND_1,
    IMG_ID_GX_UFO_BACKGROUND_2,
    IMG_ID_GX_UFO_BACKGROUND_3,
    IMG_ID_GX_UFO_BACKGROUND_4,
    IMG_ID_GX_UFO_BACKGROUND_5,
    IMG_ID_GX_UFO_BACKGROUND_6,
    IMG_ID_GX_UFO_ENEMY_1,
    IMG_ID_GX_UFO_ENEMY_2,
    IMG_ID_GX_UFO_ENEMY_3,
    IMG_ID_GX_UFO_ENEMY_4,
    IMG_ID_GX_UFO_BOSS,
    IMG_ID_GX_UFO_ENEMY_1_HIT,
    IMG_ID_GX_UFO_ENEMY_2_HIT,
    IMG_ID_GX_UFO_ENEMY_3_HIT,
    IMG_ID_GX_UFO_ENEMY_4_HIT,
    IMG_ID_GX_UFO_BOSS_HIT,
    IMG_ID_GX_UFO_ENEMY_BULLET_1,
    IMG_ID_GX_UFO_ENEMY_BULLET_2,
    IMG_ID_GX_UFO_ENEMY_BULLET_3,
    IMG_ID_GX_UFO_ENEMY_BULLET_4,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_UFO_ENERGY,
    IMG_ID_GX_UFO_SCORE,
#endif 
    IMG_ID_GX_UFO_ENERGY_UNIT,
    IMG_ID_GX_UFO_WEAPON_1,
    IMG_ID_GX_UFO_WEAPON_2,
    IMG_ID_GX_UFO_ENERGY_FILL_1,
    IMG_ID_GX_UFO_ENERGY_FILL_2,
    IMG_ID_GX_UFO_BOMB_1,
    IMG_ID_GX_UFO_BOMB_2,
    IMG_ID_GX_UFO_FLAME_1,
    IMG_ID_GX_UFO_FLAME_2,
    IMG_ID_GX_UFO_FLAME_3,
    IMG_ID_GX_UFO_ROLE,
    IMG_ID_GX_UFO_ROLE_HIT,
    IMG_ID_GX_UFO_ROLE_BULLET,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_UFO_LEVEL_CLEAR,
#endif 
    IMG_ID_GX_UFO_INVINCIBLE_1,
    IMG_ID_GX_UFO_INVINCIBLE_2,
#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_UFO_GOTEXT,
#endif 
    IMG_ID_GX_UFO_GRADESMAP,
    IMG_ID_GX_UFO_GOPIC,

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    //added for multi-language support
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE0,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE0,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE1,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE1,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE2,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE2,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE3,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE3,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE4,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE4,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE5,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE5,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE6,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE6,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE7,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE7,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE8,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE8,
    IMG_ID_GX_UFO_LEVEL_CLEAR_LANGUAGE9,
    IMG_ID_GX_UFO_GOTEXT_LANGUAGE9,
#endif  /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

    IMG_ID_GX_UFO_COUNT
} gx_ufo_img_id_neum;

#endif /* _MMI_GX_UFO_DEFS_H */ 

