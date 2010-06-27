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
 * PandaDefs_128x160.h
  *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Game id define Panda.
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
#ifndef _MMI_GX_PANDA_DEFS_H
#define _MMI_GX_PANDA_DEFS_H

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* String ID */
typedef enum
{
#if defined(__MMI_GAME_PANDA_128x160__) || defined(__MMI_GAME_PANDA_128x128__) || defined(__MMI_GAME_PANDA_176x220__)
    STR_ID_GX_PANDA_GAME_NAME = GAME_PANDA_BASE + 1,
    STR_ID_GX_PANDA_HELP_DESCRIPTION,
#elif defined(__MMI_GAME_MONKEY_128x160__) || defined(__MMI_GAME_MONKEY_128x128__) || defined(__MMI_GAME_MONKEY_176x220__)
    STR_ID_GX_PANDA_GAME_NAME_MONKEY = GAME_PANDA_BASE + 1,
    STR_ID_GX_PANDA_HELP_DESCRIPTION_MONKEY,
#endif 

    STR_ID_GX_PANDA_COUNT
} gx_panda_str_id_enum;

/* Image ID */
typedef enum
{
    IMG_ID_GX_PANDA_GAME_ICON = GAME_PANDA_BASE + 1,
    IMG_ID_GX_PANDA_DIGIT_0,
    IMG_ID_GX_PANDA_DIGIT_1,
    IMG_ID_GX_PANDA_DIGIT_2,
    IMG_ID_GX_PANDA_DIGIT_3,
    IMG_ID_GX_PANDA_DIGIT_4,
    IMG_ID_GX_PANDA_DIGIT_5,
    IMG_ID_GX_PANDA_DIGIT_6,
    IMG_ID_GX_PANDA_DIGIT_7,
    IMG_ID_GX_PANDA_DIGIT_8,
    IMG_ID_GX_PANDA_DIGIT_9,
    IMG_ID_GX_PANDA_BACKGROUND,
    IMG_ID_GX_PANDA_CLOCK,
    IMG_ID_GX_PANDA_SCORE,
    IMG_ID_GX_PANDA_ROLE_JUMP,
    IMG_ID_GX_PANDA_ROLE_FALL_FRAME_0,
    IMG_ID_GX_PANDA_ROLE_FALL_FRAME_1,
    IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_0,
    IMG_ID_GX_PANDA_ROLE_LEFT_FRAME_1,
    IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_0,
    IMG_ID_GX_PANDA_ROLE_RIGHT_FRAME_1,
    IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_0,
    IMG_ID_GX_PANDA_ROLE_ATTACK_L_FRAME_1,
    IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_0,
    IMG_ID_GX_PANDA_ROLE_ATTACK_R_FRAME_1,
    IMG_ID_GX_PANDA_ENEMY_1_LEFT,
    IMG_ID_GX_PANDA_ENEMY_2_LEFT,
    IMG_ID_GX_PANDA_ENEMY_3_LEFT,
    IMG_ID_GX_PANDA_ENEMY_1_LEFT_FRAME_2,
    IMG_ID_GX_PANDA_ENEMY_2_LEFT_FRAME_2,
    IMG_ID_GX_PANDA_ENEMY_3_LEFT_FRAME_2,
    IMG_ID_GX_PANDA_ENEMY_1_RIGHT,
    IMG_ID_GX_PANDA_ENEMY_2_RIGHT,
    IMG_ID_GX_PANDA_ENEMY_3_RIGHT,
    IMG_ID_GX_PANDA_ENEMY_1_RIGHT_FRAME_2,
    IMG_ID_GX_PANDA_ENEMY_2_RIGHT_FRAME_2,
    IMG_ID_GX_PANDA_ENEMY_3_RIGHT_FRAME_2,

#ifndef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    IMG_ID_GX_PANDA_GOTEXT,
#else
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE0,    
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE1,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE2,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE3,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE4,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE5,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE6,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE7,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE8,
    IMG_ID_GX_PANDA_GOTEXT_LANGUAGE9,
#endif

    IMG_ID_GX_PANDA_GRADESMAP,
    IMG_ID_GX_PANDA_GOPIC,

    IMG_ID_GX_PANDA_COUNT
} gx_panda_img_id_neum;

#endif /* _MMI_GX_PANDA_DEFS_H */ 

