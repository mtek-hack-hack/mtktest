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
 *  MotionDiceDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Motion Game - Dice
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
#ifndef _MOTION_DICE_DEFS_H_
#define _MOTION_DICE_DEFS_H_

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    STR_ID_MOTION_DICE_APP = MOTION_DICE_BASE,
    STR_ID_MOTION_DICE_START,
    STR_ID_MOTION_DICE_GAME_SETTING,
    STR_ID_MOTION_DICE_EVENT_SETTING,
    STR_ID_MOTION_DICE_DICE_COUNT,
    STR_ID_MOTION_DICE_SHOW_EVENT,
    STR_ID_MOTION_DICE_SOUND_SWITCH,
    STR_ID_MOTION_DICE_OPTION,
    STR_ID_MOTION_DICE_OPTION_ADD,
    STR_ID_MOTION_DICE_OPTION_REMOVE,
    STR_ID_MOTION_DICE_OPTION_EDIT,
    STR_ID_MOTION_DICE_EVENT_EDIT,
    STR_ID_MOTION_DICE_EVENT_MATCH_NUM,
    STR_ID_MOTION_DICE_EVENT_TEXT,
    STR_ID_MOTION_DICE_EVENT_DEFAULT_TEXT,
    STR_ID_MOTION_DICE_EVENT_EFFECT_FILE,
    STR_ID_MOTION_DICE_EVENT_FILE_NONE,
    STR_ID_MOTION_DICE_EVENT_FILE_SELECT,
    STR_ID_MOTION_DICE_EVENT_EDITOR_TITLE,
    STR_ID_MOTION_DICE_EVENT_PLAY_VIDEO,
    STR_ID_MOTION_DICE_EVENT_PLAY_AUDIO,
    STR_ID_MOTION_DICE_EVENT_VIEW_IMAGE,
    STR_ID_MOTION_DICE_REMOVE_CONFIRM,
    STR_ID_MOTION_DICE_EVENT_REMOVED,
    STR_ID_MOTION_DICE_SAVE_CONFIRM,
    STR_ID_MOTION_DICE_NUMBER_REGION,
    STR_ID_MOTION_DICE_DUP_NUMBER,
    STR_ID_MOTION_DICE_EVENT_FULL,
    STR_ID_MOTION_DICE_1,
    STR_ID_MOTION_DICE_2,
    STR_ID_MOTION_DICE_3,
    STR_ID_MOTION_DICE_4,
    STR_ID_MOTION_DICE_5,
    STR_ID_MOTION_DICE_INVALID_FILE,
    NUM_OF_MOTION_DICE_STR_ID
} motion_dice_str_enum;

typedef enum
{
    IMG_ID_MOTION_DICE_APP = MOTION_DICE_BASE,
    IMG_ID_MOTION_PLAY_BG,

    IMG_ID_MOTION_DICE_1,
    IMG_ID_MOTION_DICE_2,
    IMG_ID_MOTION_DICE_3,
    IMG_ID_MOTION_DICE_4,
    IMG_ID_MOTION_DICE_5,
    IMG_ID_MOTION_DICE_6,

    IMG_ID_MOTION_DICE_ROLL_1,
    IMG_ID_MOTION_DICE_ROLL_2,
    IMG_ID_MOTION_DICE_ROLL_3,
    IMG_ID_MOTION_DICE_ROLL_4,
    IMG_ID_MOTION_DICE_ROLL_5,

    IMG_ID_MOTION_DICE_ROLL_6,
    IMG_ID_MOTION_DICE_ROLL_7,
    IMG_ID_MOTION_DICE_ROLL_8,
    IMG_ID_MOTION_DICE_ROLL_9,
    IMG_ID_MOTION_DICE_ROLL_10,
    IMG_ID_MOTION_DICE_ROLL_11,
    IMG_ID_MOTION_DICE_ROLL_12,

    IMG_ID_MOTION_DICE_EVENT_1,
    IMG_ID_MOTION_DICE_EVENT_2,
    IMG_ID_MOTION_DICE_EVENT_3,
    IMG_ID_MOTION_DICE_EVENT_4,
    IMG_ID_MOTION_DICE_EVENT_5,
    IMG_ID_MOTION_DICE_EVENT_6,

    IMG_ID_MOTION_DICE_EVENT_BG,
    IMG_ID_MOTION_DICE_EVENT_DEFAULT_IMG,

    IMG_ID_MOTION_DICE_FX_ICON_DUMMY,
    IMG_ID_MOTION_DICE_FX_ICON_AUD,
    IMG_ID_MOTION_DICE_FX_ICON_VDO,
    IMG_ID_MOTION_DICE_FX_ICON_IMG,

    IMG_ID_MOTION_DICE_ICON_1,
    IMG_ID_MOTION_DICE_ICON_2,
    IMG_ID_MOTION_DICE_ICON_3,
    IMG_ID_MOTION_DICE_ICON_4,
    IMG_ID_MOTION_DICE_ICON_5,
    IMG_ID_MOTION_DICE_ICON_6,
    IMG_ID_MOTION_DICE_ICON_7,
    IMG_ID_MOTION_DICE_ICON_8,
    IMG_ID_MOTION_DICE_ICON_9,
    IMG_ID_MOTION_DICE_ICON_10,
    IMG_ID_MOTION_DICE_ICON_11,
    IMG_ID_MOTION_DICE_ICON_12,
    IMG_ID_MOTION_DICE_ICON_13,
    IMG_ID_MOTION_DICE_ICON_14,
    IMG_ID_MOTION_DICE_ICON_15,
    IMG_ID_MOTION_DICE_ICON_16,
    IMG_ID_MOTION_DICE_ICON_17,
    IMG_ID_MOTION_DICE_ICON_18,
    IMG_ID_MOTION_DICE_ICON_19,
    IMG_ID_MOTION_DICE_ICON_20,
    IMG_ID_MOTION_DICE_ICON_21,
    IMG_ID_MOTION_DICE_ICON_22,
    IMG_ID_MOTION_DICE_ICON_23,
    IMG_ID_MOTION_DICE_ICON_24,
    IMG_ID_MOTION_DICE_ICON_25,
    IMG_ID_MOTION_DICE_ICON_26,
    IMG_ID_MOTION_DICE_ICON_27,
    IMG_ID_MOTION_DICE_ICON_28,
    IMG_ID_MOTION_DICE_ICON_29,
    IMG_ID_MOTION_DICE_ICON_30,

    IMG_ID_MOTION_DICE_SUBLCD_ICON,

    NUM_OF_MOTION_DICE_IMG_ID
} motion_dice_img_enum;

typedef enum
{
    SCR_ID_MOTION_DICE_APP = MOTION_DICE_BASE,
    SCR_ID_MOTION_DICE_PLAY,
    SCR_ID_MOTION_DICE_SHOW_EVENT,
    SCR_ID_MOTION_DICE_GAME_SETTING,
    SCR_ID_MOTION_DICE_EVENT_SETTING,
    SCR_ID_MOTION_DICE_EVENT_OPTION,
    SCR_ID_MOTION_DICE_EVENT_EDIT,
    SCR_ID_MOTION_DICE_EVENT_TEXT_EDITOR,
    SCR_ID_MOTION_DICE_EVENT_TEXT_EDITOR_OPTION,
    SCR_ID_MOTION_DICE_EVENT_FILE_SELECT_OPTION,
    SCR_ID_MOTION_DICE_EVENT_FILE_VIEW_IMAGE,
    SCR_ID_MOTION_DICE_EVENT_FILE_PLAY_VIDEO,

    NUM_OF_MOTION_DICE_SCR_ID
} motion_dice_scr_enum;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/

#endif /* _MOTION_DICE_DEFS_H_ */ 

