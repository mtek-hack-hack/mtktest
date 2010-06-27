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
 * ComposeRingToneProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines prototypes for Ring Tone Composer application.
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

   FILENAME : ComposeRingToneEngineProts.h

   PURPOSE     : Prototypes for the Fun and Games application

   REMARKS     : nil

   AUTHOR      : Vikram

   DATE     : 

**************************************************************/

#ifndef RING_COMPOSER_PROTS_H
#define RING_COMPOSER_PROTS_H

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

#include "ComposeRingToneDefs.h"
#include "FileMgr.h"
/* start vijay 20050331 */
#ifdef __MMI_TOUCH_RING_COMPOSER__
#include "wgui.h"
#include "gdi_datatype.h"
#include "gdi_image_bmp.h"
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
/* end vijay */
#include "gui_setting.h"        /* 072505 Calvin */


#if (defined(__MMI_TOUCH_RING_COMPOSER__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
#ifndef RNGC_CHANGE_INSTURMENT_SP
#define RNGC_CHANGE_INSTURMENT_SP
#endif /*RNGC_CHANGE_INSTURMENT_SP*/
#else
#ifdef RNGC_CHANGE_INSTURMENT_SP
#undef RNGC_CHANGE_INSTURMENT_SP
#endif /*RNGC_CHANGE_INSTURMENT_SP*/
#endif /*(defined(__MMI_TOUCH_RING_COMPOSER__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))*/

#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
#ifndef RNGC_HAS_INST_RECTANGLE
#define RNGC_HAS_INST_RECTANGLE
#endif /*RNGC_HAS_INST_RECTANGLE*/
#else
#ifdef RNGC_HAS_INST_RECTANGLE
#undef RNGC_HAS_INST_RECTANGLE
#endif /*RNGC_HAS_INST_RECTANGLE*/
#endif /*(defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))*/

#if (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
#ifndef  RNGC_NOTE_STYLE_STANDARD
#define  RNGC_NOTE_STYLE_STANDARD
#endif /* RNGC_NOTE_STYLE_STANDARD*/
#else
#ifdef  RNGC_NOTE_STYLE_STANDARD
#undef  RNGC_NOTE_STYLE_STANDARD
#endif /*RNGC_NOTE_STYLE_STANDARD*/
#endif /*(defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))*/


#define  INSTR_PIANO                     2
#define  INSTR_MUSICBOX                  11
#define  INSTR_XYLOPHONE                 13
#define  INSTR_HARMONICA                 23
#define  INSTR_GUITAR                    26
#define  INSTR_VIOLIN                    45
#define  INSTR_SPHONE                    66
#define  INSTR_FLUTE                     74
#define  INSTR_TRUMPET                   57
#define  INSTR_SDRUMS                    115

#define  SLOW_SPEED                      60
#define  NORMAL_SPEED                    120
#define  FAST_SPEED                      180

#define  MAX_NOTES                       150
#define  RNGC_MAX_FILE_LEN               2048
#define  TIMEOUT_COMPOSER_RINGTONE       2000
#define  RNGC_FILE_LEN                   FMGR_MAX_FILE_LEN*ENCODING_LENGTH
#define  RNGC_INPUT_FILE_LEN             FMGR_MAX_INPUT_FILE_LEN
#define  MELODY_FILE_EXTENSION           ".imy"

/*BEGIN:__MMI_MAINLCD_128X128__*/
#if defined ( __MMI_MAINLCD_128X128__)
#define  BKG_IMG_Y1                         27  
#define  NOTE_BAR_HEIGHT                    9 
#define  RNGC_NOTE_OFFSET                   BKG_IMG_Y1
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14)
#define  NUM_NOTES_IN_STAVE                 5
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (150)
#define  NOTE_SELECTION_WIDTH               (176)
#define  NOTE_SELECTION_HEIGHT              (49)

#define  RNGC_MATRIX_KEY_WIDTH              (18)
#define  RNGC_MATRIX_KEY_HEIGHT             (23)
#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)
#define  NORMAL_TOOLBAR_HEIGHT              (16)
#define  NORMAL_TOOLBAR_WIDTH               (176)
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) 
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47)

#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_128X128__*/

/*BEGIN:__MMI_MAINLCD_128X160__*/
#elif defined (__MMI_MAINLCD_128X160__)
#define  BKG_IMG_Y1                         29 /* y-coordinate of main backgourd image */ 
#define  NOTE_BAR_HEIGHT                    10 /* the height to display remaining number of notes */
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+8)/* y-coordinate based of musical notes */
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14+8)/*y coordinate of effect note offset */
#define  NUM_NOTES_IN_STAVE                 5 /* maximal number of notes per stave */
#define  RNGC_X_POS_BASED                   25 /*x offset to draw the first note in stave*/
#define  RNGC_X_POS_OFFSET                  20 /*offset between two notes*/
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1 /*offset to right align to show notes number*/

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  NOTE_SELECTION_IMAGE_X             (0) /*x coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_IMAGE_Y             (150) /*y coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_WIDTH               (176) /*width of notes select keyboard area*/
#define  NOTE_SELECTION_HEIGHT              (49) /*heigth of notes select keyboard area*/

#define  RNGC_MATRIX_KEY_WIDTH              (18) /*width of the matrix notes soft key*/
#define  RNGC_MATRIX_KEY_HEIGHT             (23)/*height of the matrix notes soft key*/
#define  NORMAL_TOOLBAR_IMAGE_X             (0) /*x coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)/*y coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_HEIGHT              (16)/*height of normal toolbar area*/
#define  NORMAL_TOOLBAR_WIDTH               (176)/*width of normal toolbar area*/
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) /*width of the notes select keyboard area*/
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47) /*height of the notes select keyboard area*/

#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_128X160__*/

/*BEGIN:__MMI_MAINLCD_176X220__*/
#elif defined( __MMI_MAINLCD_176X220__) 
#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  BKG_IMG_Y1                         52
#define  NOTE_BAR_HEIGHT                    11
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+6)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+4+6)

#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (150)
#define  NOTE_SELECTION_WIDTH               (176)
#define  NOTE_SELECTION_HEIGHT              (49)
#define  RNGC_MATRIX_KEY_WIDTH              (18)
#define  RNGC_MATRIX_KEY_HEIGHT             (23)

#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)
#define  NORMAL_TOOLBAR_HEIGHT              (16)
#define  NORMAL_TOOLBAR_WIDTH               (176)
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) 
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47)
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
#define  BKG_IMG_Y1                         52
#define  NOTE_BAR_HEIGHT                    11
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+8)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14+8)
#endif /* __MMI_TOUCH_RING_COMPOSER__ */

#define  NUM_NOTES_IN_STAVE                 7   
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1
/*End:__MMI_MAINLCD_176X220__*/

/*BEGIN:__MMI_MAINLCD_240X320__*/
#elif defined(__MMI_MAINLCD_240X320__)
#define  BKG_IMG_Y1                         (108)
#define  NOTE_BAR_HEIGHT                    (18)  
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+13)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+8+13)
#define  NUM_NOTES_IN_STAVE                 10   
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1
#define  MMI_RNGC_INSTRUMENT_SELECT_HEIGHT  (39)
#define  RNGC_INSTR_SELECT_MARGIN           (1)
#define  RNGC_INSTR_SELECT_X_OFFSET         (6)

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  NOTE_SELECTION_WIDTH               (UI_device_width)
#define  NOTE_SELECTION_HEIGHT              (66)
#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT)   
#define  RNGC_MATRIX_KEY_WIDTH              (24)
#define  RNGC_MATRIX_KEY_HEIGHT             (31)

#define  SOFT_KEY_BOARD_X                   1          
#define  SOFT_KEY_BOARD_Y                   1
#define  NORMAL_TOOLBAR_HEIGHT              (23)
#define  NORMAL_TOOLBAR_WIDTH               (UI_device_width)
#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT)     

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (175)
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (65)
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (2)

#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_240X320__*/

/*BEGIN:__MMI_MAINLCD_320X240__*/
#elif defined(__MMI_MAINLCD_320X240__)
#define  BKG_IMG_Y1                         (0)/* y-coordinate of main backgourd image */
#define  NOTE_BAR_HEIGHT                    (12)/* the height to display remaining number of notes */
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+70)/* y-coordinate based of musical notes */
#define  RNGC_EFFECT_NOTE_OFFSET            (RNGC_NOTE_OFFSET + 13)/*y coordinate of effect note offset */
#define  NUM_NOTES_IN_STAVE                 13  /* maximal number of notes per stave */
#define  RNGC_X_POS_BASED                   30 /*x offset to draw the first note in stave*/
#define  RNGC_X_POS_OFFSET                  20 /*offset between two notes*/
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        6  /*offset to right align to show notes number*/
#define  MMI_RNGC_INSTRUMENT_SELECT_HEIGHT  (33)/*height of instrment select rectangle*/
#define  RNGC_INSTR_SELECT_MARGIN           (0) /*margin value between two different area */
#define  RNGC_INSTR_SELECT_X_OFFSET         (6) /*x offset to draw instrument image*/

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  NOTE_SELECTION_WIDTH               (279)/*width of notes select keyboard area*/
#define  NOTE_SELECTION_HEIGHT              (49)/*heigth of notes select keyboard area*/
#define  NOTE_SELECTION_IMAGE_X             (0)/*x coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT)      

#define  RNGC_MATRIX_KEY_WIDTH              (30)/*width of the matrix notes soft key*/
#define  RNGC_MATRIX_KEY_HEIGHT             (23)/*height of the matrix notes soft key*/
#define  NORMAL_TOOLBAR_HEIGHT              (24)/*height of normal toolbar area*/
#define  NORMAL_TOOLBAR_WIDTH               (276)/*width of normal toolbar area*/
#define  NORMAL_TOOLBAR_IMAGE_X             (0) /*x coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT) 

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (217)/*width of the notes select keyboard area*/
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (49)/*height of the notes select keyboard area*/
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (19)/*x offset of the really soft key area to left align*/
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_320X240__*/

/*BEGIN:else*/
#else 
#define  BKG_IMG_Y1                         27     
#define  NOTE_BAR_HEIGHT                    9  
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+21)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14+21)
#define  NUM_NOTES_IN_STAVE                 5 
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1
#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (150)
#define  NOTE_SELECTION_WIDTH               (176)
#define  NOTE_SELECTION_HEIGHT              (49)
#define  RNGC_MATRIX_KEY_WIDTH              (18)
#define  RNGC_MATRIX_KEY_HEIGHT             (23)

#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)
#define  NORMAL_TOOLBAR_HEIGHT              (16)
#define  NORMAL_TOOLBAR_WIDTH               (176)
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) 
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47)

#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
#endif /*defined ( __MMI_MAINLCD_128X128__)*/


#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_NOTE_SELECTION_FINAL          0x0001
#define  RNGC_SHOW_SELECTION_AREA           0x0002
#define  RNGC_SELECTION_AREA_REDRAW         0x0004
#define  RNGC_PEN_EVENT_UP                  0x0008

#define  RNGC_MAX_ROW                       (2)
#define  RNGC_MAX_COLUMN                    (7)
#define  RNGC_MAX_CUSTOM_KEYS               (3)

#define  RNGC_INSTRUMENT_WIDTH              (24)
#define  RNGC_INSTRUMENT_HEIGHT             (24)
#define  RNGC_INSTRUMENT_X                  (UI_device_width-RNGC_INSTRUMENT_WIDTH-2)
#define  RNGC_INSTRUMENT_Y                  (MMI_title_y)
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 


/* 
 * Typedef 
 */

typedef struct
{
    S8 FileName[RNGC_FILE_LEN];     /* string of filename */
    S8 PrevFileName[RNGC_FILE_LEN]; /* string of filename */
    S8 EditFileNameBuffer[RNGC_FILE_LEN]; /* buffer for save edit file name */
    U8 CurrTone;                    /* index of current composed tone */
    U8 CurrInstr;                   /* current instrument */
    U8 CurrSpeed;                   /* current play speed */
    U8 IsTonePlaying;               /* if tone is playing */
    U8 CurrHiliteItem;              /* index of current selected option */
    U8 CurrEditState;               /* eidt state 0 == Add, 1 == Edit, 2 == Rename */
    U8 IsSelfStop;
} rngc_context_struct;

typedef struct
{
    PU8 ImageList[NUM_NOTES_IN_STAVE];
    S16 TotalNotes;     /* total number of notes */
    U16 CurrNoteIndex;  /* current position of cursor */
    U16 CurrUIPos;      /* current UI position */
    U16 NotesList[MAX_NOTES + 1];
    U8 YPos[NUM_NOTES_IN_STAVE];
    U8 IsRskLP;         /* if RSK is long-pressed */
    U8 CursorWidth;
    U8 IsSefLeftKeyDown; 
} rngc_engine_context_struct;

typedef struct
{
    U16 nNote;
    U8 nImageId;
} NoteInfo;

typedef struct
{
    U16 nImageId;
    U8 nXPos;
    U8 nYPos;
} DisplayInfo;


#ifdef RNGC_CHANGE_INSTURMENT_SP
typedef enum
{
    RNGC_PREVIOUS_INSTR = 0,
    RNGC_NEXT_INSTR,
    RNGC_INSRT_NONE
} RNGC_SELECTED_INSTR;
#endif  /*RNGC_CHANGE_INSTURMENT_SP*/


#ifdef __MMI_TOUCH_RING_COMPOSER__

typedef enum
{
    GUI_RNGC_NORMAL_TOOLBAR = 1,
    GUI_RNGC_NOTE_SELECTION
} touch_rngc_selection_area;

typedef enum
{
    RNGC_PEN_NONE = 1,
    RNGC_PEN_INSTRUMENT,
    RNGC_PEN_STAVE,
    RNGC_PEN_NORMAL_TOOLBAR,
    RNGC_PEN_NOTE_SELECTION,
    TOUCH_RNGC_PEN_LSK,
    TOUCH_RNGC_PEN_RSK
} touch_rngc_pen_state;
typedef enum
{
    GUI_RNGC_VIEW = 1,
    GUI_RNGC_EDIT,
    GUI_RNGC_INSERT,
    GUI_RNGC_INSERT_EDIT,
    RNGC_PLAY,
    RNGC_PAUSE
} touch_rngc_mode;

typedef enum
{
    GUI_RNGC_KEY_SHARP = SHARP,
    GUI_RNGC_KEY_FLAT = FLAT,
    GUI_RNGC_KEY_DOT,
    GUI_RNGC_KEY_OK,
    GUI_RNGC_KEY_EDIT,
    GUI_RNGC_KEY_INSERT,
    GUI_RNGC_KEY_PLAY,
    GUI_RNGC_KEY_NEXT,
    GUI_RNGC_KEY_PREV,
    GUI_RNGC_OCTAVE_UP,
    GUI_RNGC_OCTAVE_DOWN,
    GUI_RNGC_KEY_NOTE1 = (NOTE_C | OCTAVE_4 | DURATION_1 | NORMAL),
    GUI_RNGC_KEY_NOTE2 = (NOTE_C | OCTAVE_4 | DURATION_1BY2 | NORMAL),
    GUI_RNGC_KEY_NOTE3 = (NOTE_C | OCTAVE_4 | DURATION_1BY4 | NORMAL),
    GUI_RNGC_KEY_NOTE4 = (NOTE_C | OCTAVE_4 | DURATION_1BY8 | NORMAL),
    GUI_RNGC_KEY_NOTE5 = (NOTE_C | OCTAVE_4 | DURATION_1BY16 | NORMAL),
    GUI_RNGC_KEY_NOTE6 = (NOTE_REST | OCTAVE_4 | DURATION_1BY4),
    GUI_RNGC_KEY_NOTE7 = (NOTE_REST | OCTAVE_4 | DURATION_1BY8),
    GUI_RNGC_KEY_NOTE8 = (NOTE_REST | OCTAVE_4 | DURATION_1BY16)
} touch_rngc_key_note;

typedef struct
{
    S16 matrix_x, matrix_y;
    S16 n_matrix_rows, n_matrix_columns;
    S16 matrix_width, matrix_height;
    S16 key_width, key_height;
    MMI_ID_TYPE key_image[RNGC_MAX_ROW][RNGC_MAX_COLUMN];
    U16 key_note[RNGC_MAX_ROW][RNGC_MAX_COLUMN];
} rngc_matrix_key_layout_struct;

typedef struct
{
    S16 x, y;
    S16 key_width, key_height;
    MMI_ID_TYPE key_image;
    U16 key_note;
} rngc_custom_key_layout_struct;

typedef struct
{
    S16 n_matrix_keys, n_custom_keys;
    S16 image_x, image_y;
    rngc_matrix_key_layout_struct *matrix_layout;
    rngc_custom_key_layout_struct *custom_keys;
    S16 horizontal_gap, vertical_gap;
    MMI_ID_TYPE imageid;
} rngc_selection_area_layout_struct;

typedef struct
{
    U16 original_key_note;
    touch_rngc_mode mode;
    S32 play_mode;
    S32 selected_key_x, selected_key_y;
    S32 key_width, key_height;
    S32 selected_key_image;
    gdi_image_cache_bmp_struct selected_key_bitmap;
    touch_rngc_selection_area area_type;
    U16 key_note_type;
    U32 flag;
} touch_rngc_struct;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 


typedef struct 
{
    U16 main_bg_img_id;
    S16 main_bg_img_area_y1, main_bg_img_area_y2;

    S16 stave_rectangle_y1, stave_rectangle_y2;

    MMI_BOOL is_draw_notes_rect_bg_color;
    S16 remain_notes_rect_y1, remain_notes_rect_height;

    S16 instr_sel_rect_y1, instr_sel_rect_y2;
    S16 instr_img_x1;

    S16 title_rect_y1, title_rect_height;
} rngc_skin_layout_struct;

extern rngc_context_struct g_rngc_cntx;
extern rngc_engine_context_struct *g_rngc_eng_cntx;

extern void ExitRngcComposerEngine(void);

extern void HandleKey_0(void);
extern void HandleKey_1(void);
extern void ShowNote(U16 nNote);

extern void HandleKey_2(void);
extern void HandleKey_3(void);
extern void HandleKey_4(void);
extern void HandleKey_5(void);
extern void HandleKey_6(void);

extern void HandleKey_7(void);
extern void HandleKey_8(void);
extern void HandleKey_9(void);
extern void HandleKey_STAR(void);
extern void HandleKey_POUND(void);
extern void HandleKey_UP(void);
extern void HandleKey_DOWN(void);
extern void HandleKey_LEFT(void);
extern void HandleKey_RIGHT(void);


extern U16 GetMelodyFromStruct(U8 *pList, U16 nListSize);
extern U8 *GetStringForNode(U8 *pStr, U32 nNote);

extern void GetIndexInList(U16 nNote, U16 *pImageId, U8 *pYVal);


/* UI Functions */
extern void redraw_ringcomposer(void);
extern void SetRingComposer(
                U16 title_id,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 instru_type,
                S32 value,
                U8 *history_buffer);
extern void RefreshNotesList(U16 nTotalNotes, DisplayInfo *psDisplayInfo);
extern U16 GetInstrumentImage(U8 instru_type);
extern S32 GenerateMelodyFile(PS8 pFileName);
extern void RedrawNotes(void);
extern void InsertNote(U16 nNote);
extern void FreeMemory(void);
extern void DeleteCurNote(void);
extern void EditMelody(U8 *pFileName);

extern void RngcComposerRSKUpHandler(void);
extern void RngcComposerRSKDownHandler(void);

extern U8 GetComposerStructFromMelody(U8 *pMelody);
extern U8 CompareMelody(U8 **pptr, void *ps);
extern U8 Tolower(U8 ch);
extern S8 StrnCmp(S8 *s1, S8 *s2, int maxlen);
extern void TrimStr(U8 **pptr);

extern void ClearToEnd(U8 **pptr);
extern U8 GetInstrument(U8 **pptr);
extern U16 GetBeat(U8 **pptr);
extern void SkipSpace(U8 **pptr);
extern S32 GetInteger(U8 **pptr);
extern U8 SetNote(U8 **pptr);
extern U8 SetOctaveFromStream(U8 **pptr);
extern U8 SetLED(U8 **pptr);
extern U8 SetVibration(U8 **pptr);
extern U8 SetBackLight(U8 **pptr);
extern U8 GetMelody(U8 **pptr);
extern void HandleKey_END(void);
extern void InitializeComposer(void);
extern void HandleKey_CLEARLONG(void);
extern void HandleKey_CLEARLONG(void);
extern void PlayCurrentNode(void);
extern void GenerateCompleteComposeFileName(PS8 pFileName, PS8 pCompletePath);
extern S32 RngcCreateDir(void);

#ifdef RNGC_CHANGE_INSTURMENT_SP
extern void mmi_rngc_change_instrument(S32 selected_instrument);
#endif /*RNGC_CHANGE_INSTURMENT_SP*/

#ifdef RNGC_HAS_INST_RECTANGLE
void initialize_rngc_instrument_select_menu_items(S32 x, S32 y, S32 width, S32 height, U8 **list_of_items,
                                                  S32 *highlighted_item, void (*f) (S32 item_index));
extern void rngc_select_previous_instrument(void);
extern void rngc_select_next_instrument(void);
extern void register_rngc_instrument_select_keys(void);
#endif /* RNGC_HAS_INST_RECTANGLE */ 


#ifdef __MMI_TOUCH_RING_COMPOSER__
extern void mmi_rngc_note_selection(touch_rngc_struct *touch_rngc_context);
extern void show_touch_rngc_selection_area(void);
extern MMI_BOOL mmi_rngc_pen_down_selection_area(touch_rngc_struct *touch_rngc_context, mmi_pen_point_struct pos);
extern MMI_BOOL mmi_rngc_pen_down_on_stave(mmi_pen_point_struct pos, S32 *item_index);
extern MMI_BOOL mmi_rngc_pen_down_instrument(mmi_pen_point_struct pos);
extern void mmi_rngc_set_note_type(S32 note_type_to_set);
extern void mmi_rngc_set_note_beat(void);
extern void mmi_rngc_change_stave_notes(touch_rngc_struct *touch_rngc_context, S32 item_index);
extern void mmi_rngc_normal_toolbar(touch_rngc_struct *touch_rngc_context);
extern void mmi_rngc_note_selection(touch_rngc_struct *touch_rngc_context);
extern void mmi_rngc_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_move_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_repeat_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* RING_COMPOSER_PROTS_H */ 

