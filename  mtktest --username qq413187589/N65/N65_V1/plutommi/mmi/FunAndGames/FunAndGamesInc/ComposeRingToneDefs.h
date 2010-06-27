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

/*******************************************************************************
 * Filename:
 * ---------
 * ComposeRingToneDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for defining enum, constant, and data structure for ring tone composer
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : ComposeRingToneDefs.h

   PURPOSE     : Resource IDs for the ComposeRingTone Application

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : July-28-2003

**************************************************************/
#ifndef _MMI_COMPOSE_RINGTONE_DEFS_H
#define _MMI_COMPOSE_RINGTONE_DEFS_H

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#include "MMIDataType.h"
#include "DownloadDefs.h"
#include "gui_data_types.h"
#include "custom_equipment.h"

/* 
 * Define
 */

#ifndef HARDWARE_LED_NOT_SUPPORT
    #define __MMI_RNGC_ENABLE_INS_LED_NOTE__
#endif /* #ifndef HARDWARE_LED_NOT_SUPPORT */

typedef enum
{
    ENUM_COMP_OPT_PLAY = 0,
    ENUM_COMP_OPT_EDIT,
    ENUM_COMP_OPT_ADD,
    ENUM_COMP_OPT_RENAME,
    ENUM_COMP_OPT_DELETE,
    ENUM_COMP_OPT_DELETE_ALL,
    ENUM_COMP_OPT_FORWARD,
    ENUM_COMP_OPT_TOTAL
} RNGC_TONE_OPTION_ENUM;

typedef enum
{
    ENUM_COMP_ADD = 0,
    ENUM_COMP_EDIT,
    ENUM_COMP_RENAME
} RNGC_EDIT_STATE_ENUM;

typedef enum
{
    ENUM_ADD_TONE_OPT_PLAY = 0,
    ENUM_ADD_TONE_OPT_SPEED,
    ENUM_ADD_TONE_OPT_INSTR,
    ENUM_ADD_TONE_OPT_SAVE,
    ENUM_ADD_TONE_OPT_TOTAL
} RNGC_COMP_TONE_OPTION_ENUM;

typedef enum
{
    ENUM_SPEED_FAST = 0,
    ENUM_SPEED_NORMAL,
    ENUM_SPEED_SLOW,
    ENUM_SPEED_TOTAL
} RNGC_SPEED_ENUM;

typedef enum
{
    ENUM_INSTR1 = 0,
    ENUM_INSTR2,
    ENUM_INSTR3,
    ENUM_INSTR4,
    ENUM_INSTR5,
    ENUM_INSTR6,
    ENUM_INSTR7,
    ENUM_INSTR8,
    ENUM_INSTR9,
    ENUM_INSTR10,
    ENUM_TOTAL_INSTR    /* PMT MANISH   20050617 */
} RNGC_INSTRUMENT_ENUM;

typedef enum
{
    SCR_COMPOSE_RINGTONE = COMPOSE_RINGTONE_BASE + 1,
    SCR_COMPOSE_RINGTONE_OPTION,
    SCR_COMPOSE_RINGTONE_OPTION_PLAY,
    SCR_COMP_RINGTONE_ADD_OPT,
    SCR_COMP_RINGTONE_SPEED,
    SCR_COMP_RINGTONE_INSTRUMENT,
    SCR_COMP_RINGTONE_SAVEFILE,
    SCR_COMP_RINGTONE_SAVE_OPT,
    SCR_COMPOSER_ENGINE,
    SCR_COMPOSE_RINGTONE_DELETE,
    SCR_COMPOSE_RINGTONE_DELETE_CNF,
    SCR_COMP_RINGTONE_SAVE_CNF
} COMPOSE_RINGTONE_SCREEN_ID;

typedef enum
{
    STR_COMPOSER_RINGTONE_LIST = COMPOSE_RINGTONE_BASE + 1,
    STR_COMPOSER_RINGTONE_SELMENUOPT1,
    STR_COMPOSER_RINGTONE_SELMENUOPT2,
    STR_COMPOSER_RINGTONE_ADDOPT,
    STR_COMPOSER_RINGTONE_SAVEOPT,
    STR_COMPOSER_RINGTONE_PLAY,
    STR_COMPOSER_RINGTONE_EDIT,
    STR_COMPOSER_RINGTONE_ADD,
    STR_COMPOSER_RINGTONE_RENAME,
    STR_COMPOSER_RINGTONE_DELETE,
    STR_COMPOSER_RINGTONE_PLAYING,
    STR_COMP_RINGTONE_PLAY_SPEED,
    STR_COMP_RINGTONE_SEL_INST,
    STR_COMP_RINGTONE_SAVE,
    STR_COMP_RINGTONE_FAST,
    STR_COMP_RINGTONE_NORMAL,
    STR_COMP_RINGTONE_SLOW,
    STR_COMP_RINGTONE_PIANO,
    STR_COMP_RINGTONE_GUITAR,
    STR_COMP_RINGTONE_VIOLIN,
    STR_COMP_RINGTONE_SAXOPHONE,
    STR_COMP_RINGTONE_STEELDRUMS,
    STR_COMP_RINGTONE_FLUTE,
    STR_COMP_RINGTONE_HARMONICA,
    STR_COMP_RINGTONE_TRUMPET,
    STR_COMP_RINGTONE_MUSICBOX,
    STR_COMP_RINGTONE_XYLOPHONE,
    STR_COMP_RINGTONE_FILENAME,
    STR_COMP_RINGTONE_INPUTMETHOD,
    STR_COMP_RINGTONE_EMPTY,
    STR_COMP_RINGTONE_DELETED,
    STR_CAP_COMP_RINGTONE_DELETE,
    STR_COMP_RINGTONE_EMPTYRINGTONE,
    STR_COMP_RINGTONE_DUPLICATE,
    STR_MENU3103_RINGTONE_COMPOSER,
    STR_COMP_RINGTONE_EMPTYFILENAME,
    STR_COMP_RINGTONE_MEMORYFULL
} COMPOSER_RINGTONE_STRING_LIST;

typedef enum
{
    IMG_COMP_RINGTONE_PLAY = COMPOSE_RINGTONE_BASE + 1,
    IMG_MENU3103_RINGTONE_COMPOSER
} COMP_RINGTONE_IMG_IDS;

typedef enum
{
    RC_SUCCESS = 0,
    RC_ERROR,
    RC_EMPTY_FILENAME,
    RC_DUP_FILENAME,
    RC_MEMORY_FULL,
    RC_FILENAME_ERR
} RC_ERROR_ENUM;

enum ComposerStr
{
    STR_RING_COMPOSE_TITLE = COMPOSE_RING_TONE_ENGINE_BASE + 1
};

enum ComposeImages
{
    IMG_3BY2_OCT_L_M_N = COMPOSE_RING_TONE_ENGINE_BASE + 1,
    IMG_3BY2_OCT_L_M_F,
    IMG_3BY2_OCT_L_M_S,

    IMG_3BY2_OCT_U_N,
    IMG_3BY2_OCT_U_F,
    IMG_3BY2_OCT_U_S,

    IMG_1_OCT_L_M_N,
    IMG_1_OCT_L_M_F,
    IMG_1_OCT_L_M_S,

    IMG_1_OCT_U_N,
    IMG_1_OCT_U_F,
    IMG_1_OCT_U_S,

    IMG_3BY4_OCT_L_M_N,
    IMG_3BY4_OCT_L_M_F,
    IMG_3BY4_OCT_L_M_S,

    IMG_3BY4_OCT_U_N,
    IMG_3BY4_OCT_U_F,
    IMG_3BY4_OCT_U_S,

    IMG_1BY2_OCT_L_M_N,
    IMG_1BY2_OCT_L_M_F,
    IMG_1BY2_OCT_L_M_S,

    IMG_1BY2_OCT_U_N,
    IMG_1BY2_OCT_U_F,
    IMG_1BY2_OCT_U_S,

    IMG_3BY8_OCT_L_M_N,
    IMG_3BY8_OCT_L_M_F,
    IMG_3BY8_OCT_L_M_S,

    IMG_3BY8_OCT_U_N,
    IMG_3BY8_OCT_U_F,
    IMG_3BY8_OCT_U_S,

    IMG_1BY4_OCT_L_M_N,
    IMG_1BY4_OCT_L_M_F,
    IMG_1BY4_OCT_L_M_S,

    IMG_1BY4_OCT_U_N,
    IMG_1BY4_OCT_U_F,
    IMG_1BY4_OCT_U_S,

    IMG_3BY16_OCT_L_M_N,
    IMG_3BY16_OCT_L_M_F,
    IMG_3BY16_OCT_L_M_S,

    IMG_3BY16_OCT_U_N,
    IMG_3BY16_OCT_U_F,
    IMG_3BY16_OCT_U_S,

    IMG_1BY8_OCT_L_M_N,
    IMG_1BY8_OCT_L_M_F,
    IMG_1BY8_OCT_L_M_S,

    IMG_1BY8_OCT_U_N,
    IMG_1BY8_OCT_U_F,
    IMG_1BY8_OCT_U_S,

    IMG_3BY32_OCT_L_M_N,
    IMG_3BY32_OCT_L_M_F,
    IMG_3BY32_OCT_L_M_S,

    IMG_3BY32_OCT_U_N,
    IMG_3BY32_OCT_U_F,
    IMG_3BY32_OCT_U_S,

    IMG_1BY16_OCT_L_M_N,
    IMG_1BY16_OCT_L_M_F,
    IMG_1BY16_OCT_L_M_S,

    IMG_1BY16_OCT_U_N,
    IMG_1BY16_OCT_U_F,
    IMG_1BY16_OCT_U_S,
    IMG_3BY8_OCT_L_M,
    IMG_1BY4_OCT_L_M,
    IMG_3BY16_OCT_L_M,
    IMG_1BY8_OCT_L_M,
    IMG_3BY32_OCT_L_M,
    IMG_1BY16_OCT_L_M,
    /* start vijay 20050408 */
    TOUCH_IMG_1_OCT_L_M_N,
    TOUCH_IMG_1BY2_OCT_L_M_N,
    TOUCH_IMG_1BY4_OCT_L_M_N,
    TOUCH_IMG_1BY8_OCT_L_M_N,
    TOUCH_IMG_1BY16_OCT_L_M_N,
    TOUCH_IMG_1BY4_OCT_L_M,
    TOUCH_IMG_1BY8_OCT_L_M,
    TOUCH_IMG_1BY16_OCT_L_M,
    /* end vijay */
    /* add note images on top of this********** */
    IMG_RING_EVENTBL_ON,
    IMG_RING_EVENTBL_OFF,
    IMG_RING_EVENTLED_ON,
    IMG_RING_EVENTLED_OFF,
    IMG_RING_EVENTVIB_ON,
    IMG_RING_EVENTVIB_OFF,
    //start vijay 20050331
    //#ifdef __MMI_TOUCH_RING_COMPOSER__
    IMG_TOUCH_RING_UP,
    IMG_TOUCH_RING_DOWN,
    IMG_TOUCH_RNGC_HASH,
    IMG_TOUCH_RING_P,
    IMG_TOUCH_RING_DOT,
    IMG_TOUCH_RING_OK,
    IMG_TOUCH_RING_EDIT,
    IMG_TOUCH_RING_INSERT,
    IMG_TOUCH_RING_PLAY,
    IMG_TOUCH_RING_PAUSE,
    IMG_TOUCH_RING_NEXT,
    IMG_TOUCH_RING_PREV,
    IMG_TOUCH_RING_NORMAL,
    IMG_TOUCH_RING_SELECTION,
    /* IMG_RNGC_UP_OCTAVE_UP,
       IMG_RNGC_UP_OCTAVE_DOWN, */
    //#endif
    //end vijay
    IMG_RING_EVENT1,
    IMG_RING_EVENT2,
    IMG_RING_EVENT3,
    IMG_RING_EVENT4,
    IMG_RING_EVENT5,
    IMG_RING_INSTRU1,
    IMG_RING_INSTRU2,
    IMG_RING_INSTRU3,
    IMG_RING_INSTRU4,
    IMG_RING_INSTRU5,
    IMG_RING_INSTRU6,
    IMG_RING_INSTRU7,
    IMG_RING_INSTRU8,
    IMG_RING_INSTRU9,
    IMG_RING_INSTRU10,
    IMG_RING_COMPOSER_BACKGROUND,
    IMG_TOUCH_RING_COMPOSER_BACKGROUND
#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
        , IMG_RING_INSTRU_LEFT_ARROW_UP,
    IMG_RING_INSTRU_RIGHT_ARROW_UP
#endif /* __MMI_MAINLCD_240X320__ */ 
};

enum NotesList
{
    NOTE_C = 0x0001,
    NOTE_D,
    NOTE_E,
    NOTE_F,
    NOTE_G,
    NOTE_A,
    NOTE_B,
    NOTE_REST,
    NOTE_VIBRATION_ON,
    NOTE_VIBRATION_OFF,
    NOTE_LED_ON,
    NOTE_LED_OFF,
    NOTE_BACKLIGHT_ON,
    NOTE_BACKLIGHT_OFF
};  /* First Four bits of the Note */

enum NoteType
{
    NORMAL = 0x0010,
    FLAT = 0x0020,
    SHARP = 0x0030
};  /* Bit 5 , 6 */

enum Octave
{
    OCTAVE_3 = 0x0040,  /* //000000000100000 */
    OCTAVE_4 = 0x0080,  /* //000000001000000 */
    OCTAVE_5 = 0x00C0   /* //000000001100000 */
};                      /* bits 7,8,9 for octave */

enum Duration
{
    DURATION_3BY2 = 0x0200, /* 00001000000000 */
    DURATION_1 = 0x0400,
    DURATION_3BY4 = 0x0600,
    DURATION_1BY2 = 0x0800,
    DURATION_3BY8 = 0x0A00,
    DURATION_1BY4 = 0x0C00,
    DURATION_3BY16 = 0x0E00,
    DURATION_1BY8 = 0x1000,
    DURATION_3BY32 = 0x1200,
    DURATION_1BY16 = 0x1400
};                          /* bits 10,11,12,13 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* _MMI_COMPOSE_RINGTONE_DEFS_H */ 

