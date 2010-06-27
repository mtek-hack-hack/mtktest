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
 *  PictureEditorDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef PICTUREEDITORDEFS_H
#define PICTUREEDITORDEFS_H

#include "MMIDataType.h"
#include "wgui_categories.h"
#include "PictureEditorResDef.h"

/**********************Defines************************/
#if defined (__MMI_MAINLCD_240X320__)
#if defined (__MMI_TOUCH_SCREEN__)
#define PIC_EDITOR_TITLE_Y    18
#define PIC_EDITOR_TITLE_HEIGHT    45
#else /* defined (__MMI_TOUCH_SCREEN__) */ 
#define PIC_EDITOR_TITLE_Y    18 
#define PIC_EDITOR_TITLE_HEIGHT    45
#endif /* defined (__MMI_TOUCH_SCREEN__) */ 
#elif defined ( __MMI_MAINLCD_176X220__)
#define PIC_EDITOR_TITLE_Y    0
#define PIC_EDITOR_TITLE_HEIGHT    44
#else 
#define PIC_EDITOR_TITLE_Y    0
#define PIC_EDITOR_TITLE_HEIGHT    18
#endif 
/* Calvin end */

#define MAX_PERMANENT_COLOR 15
#define MAX_CUSTOM_COLOR 1
#define MAX_TYPE_PEN_COLOR   (MAX_PERMANENT_COLOR+MAX_CUSTOM_COLOR)

#define MAX_TYPE_PEN_PIXEL   4
#define MAX_TYPE_PEN_MOVE    4
#define MAX_TYPE_SCR_TYPE 4

#define MAX_RESIZE_INLINE_EDIT  6

#define PE_NOTIFYDURATION  UI_POPUP_NOTIFYDURATION_TIME
#define PE_BLINKING_DURATION 500

#define PIC_EDIT_PEN_PIXEL_1   0x01
#define PIC_EDIT_PEN_PIXEL_2   0x02
#define PIC_EDIT_PEN_PIXEL_3   0x04
#define PIC_EDIT_PEN_PIXEL_4   0x08

#define PIC_EDIT_PEN_MOVE_1   0x01
#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 For Touch Screen Pen Move is always 1 */
#define PIC_EDIT_PEN_MOVE_2   0x02
#define PIC_EDIT_PEN_MOVE_3   0x04
#define PIC_EDIT_PEN_MOVE_4   0x08
#endif /* __MMI_TOUCH_SCREEN__ */ 
#define PE_IMAGE_WIDTH_EXTRA   (0)      /* (6) */
#define PE_IMAGE_HEIGHT_EXTRA  (0)      /* (-1) */

#define SET_WINDOW_MINX(width) ((U16)((UI_device_width-width)>>1))      /* +PE_IMAGE_WIDTH_EXTRA) //width is width of window */
#define SET_WINDOW_MINY(height) ((U16)((UI_device_height-height)>>1))   /* +PE_IMAGE_HEIGHT_EXTRA) //height is height of window */

/* 051605 Calvin modified */
#if defined (__MMI_MAINLCD_240X320__)
#define  PE_SCR_SIZE_MIN 32
#define  PE_SCR_SIZE_1  32
#define  PE_SCR_SIZE_2  64
#define  PE_SCR_SIZE_MAX 128    /* 090505 Calvin modified */
#else /* defined (__MMI_MAINLCD_240X320__) */ 
#define  PE_SCR_SIZE_MIN 16
#define  PE_SCR_SIZE_1  16
#define  PE_SCR_SIZE_2  32
#define  PE_SCR_SIZE_MAX 64
#endif /* defined (__MMI_MAINLCD_240X320__) */ 

/* 092005 Image Editor Size Calvin */
#ifdef __MMI_MAINLCD_240X320__
#define PE_RESIZE_BUF_SIZE 4
#else 
#define PE_RESIZE_BUF_SIZE 3
#endif 
/* 092005 Image Editor Size Calvin */

#define PE_IMAGE_CHANGED    0x0001
#define PE_PEN_DOWN         0x0002
#define PE_VIEW_IMAGE       0x0004
#define PE_ADD_IMAGE        0x0008
#define PE_ZOOM_IMAGE       0x0010
#define PE_IMAGE_EDIT       0x0020
#define PE_UNDO_IMAGE       0x0040
#define PE_MARK_IMAGE       0x0080
#define PE_COPY_IMAGE       0x0100
#define PE_CURSOR_TIMER     0x0200

#define SET_PE_IMAGE_CHANGED(x)  (x |= PE_IMAGE_CHANGED)
#define UNSET_PE_IMAGE_CHANGED(x)  (x &= (~PE_IMAGE_CHANGED))
#define IS_PE_IMAGE_CHANGED(x)  (x & PE_IMAGE_CHANGED)

#define SET_PE_PEN_DOWN(x)  (x |= PE_PEN_DOWN)
#define UNSET_PE_PEN_DOWN(x)  (x &= (~PE_PEN_DOWN))
#define TOGGLE_PE_PEN_DOWN(x)  (x ^= PE_PEN_DOWN)
#define IS_PE_PEN_DOWN(x)  (x & PE_PEN_DOWN)

#define SET_PE_VIEW_IMAGE(x)  (x |= PE_VIEW_IMAGE)
#define UNSET_PE_VIEW_IMAGE(x)  (x &= (~PE_VIEW_IMAGE))
#define IS_PE_VIEW_IMAGE(x)  (x & PE_VIEW_IMAGE)

#define SET_PE_ADD_IMAGE(x)  (x |= PE_ADD_IMAGE)
#define UNSET_PE_ADD_IMAGE(x)  (x &= (~PE_ADD_IMAGE))
#define IS_PE_ADD_IMAGE(x)  (x & PE_ADD_IMAGE)

#define SET_PE_ZOOM_IMAGE(x)  (x |= PE_ZOOM_IMAGE)
#define UNSET_PE_ZOOM_IMAGE(x)  (x &= (~PE_ZOOM_IMAGE))
#define IS_PE_ZOOM_IMAGE(x)  (x & PE_ZOOM_IMAGE)

#define SET_PE_IMAGE_EDIT(x)  (x = ((x&(~PE_UNDO_IMAGE))|PE_IMAGE_EDIT|PE_IMAGE_CHANGED))
#define UNSET_PE_IMAGE_EDIT(x)  (x &= (~(PE_IMAGE_EDIT|PE_UNDO_IMAGE)))
#define IS_PE_IMAGE_EDIT(x)  (x & PE_IMAGE_EDIT)

#define SET_PE_UNDO_IMAGE(x)  (x |= PE_UNDO_IMAGE)
#define UNSET_PE_UNDO_IMAGE(x)  (x &= (~PE_UNDO_IMAGE))
#define TOGGLE_PE_UNDO_IMAGE(x)  (x ^= PE_UNDO_IMAGE)
#define IS_PE_UNDO_IMAGE(x)  (x & PE_UNDO_IMAGE)

#define SET_PE_MARK_IMAGE(x)  (x |= PE_MARK_IMAGE)
#define UNSET_PE_MARK_IMAGE(x)  (x &= (~PE_MARK_IMAGE))
#define IS_PE_MARK_IMAGE(x)  (x & PE_MARK_IMAGE)

#define SET_PE_COPY_IMAGE(x)  (x |= PE_COPY_IMAGE)
#define UNSET_PE_COPY_IMAGE(x)  (x &= (~PE_COPY_IMAGE))
#define IS_PE_COPY_IMAGE(x)  (x & PE_COPY_IMAGE)

#define SET_PE_CURSOR_TIMER(x)  (x |= PE_CURSOR_TIMER)
#define UNSET_PE_CURSOR_TIMER(x)  (x &= (~PE_CURSOR_TIMER))
#define IS_PE_CURSOR_TIMER(x)  (x & PE_CURSOR_TIMER)
#define TOGGLE_PE_CURSOR_TIMER(x)  (x ^= PE_CURSOR_TIMER)

#define  PIC_EDIT_FILE_HEADER_SIZE     (54+(MAX_TYPE_PEN_COLOR*4))
#define  PIC_EDIT_FILE_MAX_DATA_SIZE ((PE_SCR_SIZE_MAX*PE_SCR_SIZE_MAX)>>1)
#define  PIC_EDIT_FILE_BUFF (PIC_EDIT_FILE_HEADER_SIZE+PIC_EDIT_FILE_MAX_DATA_SIZE)

/**********************TypeDefs************************/
typedef enum
{
    PE_COLOR_NONE = 0,
    PE_COLOR_BLACK,
    PE_COLOR_BROWN,
    PE_COLOR_DARK_GREEN,
    PE_COLOR_DARK_BLUE,
    PE_COLOR_VOILET,
    PE_COLOR_GRAY,
    PE_COLOR_LIGHT_GRAY,
    PE_COLOR_RED,
    PE_COLOR_GREEN,
    PE_COLOR_YELLOW,
    PE_COLOR_BLUE,
    PE_COLOR_PINK,
    PE_COLOR_LIGHT_BLUE,
    PE_COLOR_WHITE,
    PE_COLOR_CUSTOM_1
} PE_COLOR_IDS;

typedef enum
{
    PE_SCR_1 = 0,
    PE_SCR_2,
    PE_SCR_3,
    PE_SCR_4
} PIC_EDIT_SCR_SIZE;

typedef enum
{
    CUR_NO_MOVE,
    CUR_INCREMENT,
    CUR_DECREMENT
} PIC_EDIT_CUR_MOVMENT;

typedef enum
{
    SEL_PE_EDIT_OPT_SAVE_PIC = 0,
    SEL_PE_EDIT_OPT_SAVE_PIC_AS,
    SEL_PE_EDIT_OPT_PEN_SETTING,
    SEL_PE_EDIT_OPT_FILL_PIC,
    SEL_PE_EDIT_OPT_MARK,
    SEL_PE_EDIT_OPT_CUT,
    SEL_PE_EDIT_OPT_COPY,
    SEL_PE_EDIT_OPT_PASTE,
    SEL_PE_EDIT_OPT_UNDO,
    SEL_PE_EDIT_OPT_REDO,
    SEL_PE_EDIT_OPT_ZOOM,
    SEL_PE_EDIT_OPT_FULL_SIZE,
    SEL_PE_EDIT_OPT_RESIZE,
    SEL_PE_EDIT_OPT_HELP,
    SEL_PE_VIEW_OPT_EDIT,
    SEL_PE_VIEW_OPT_DELETE,
    SEL_PE_VIEW_OPT_DELETEALL
} PIC_EDIT_ACTIONS;

typedef struct _picEditCursor
{
    U16 penX;
    U16 penY;
    U16 minX;
    U16 minY;
    U16 maxX;
    U16 maxY;
    U8 penColorIndex;
    U8 penPixel;
    U8 penMove;
    U8 penBackgrdColorIndex;
#ifdef __MMI_TOUCH_SCREEN__
    pBOOL penContextSaved;  /* PMT MANISH   20050329 */
#endif 
} PictureEditorPen;

typedef struct _picEditWindow
{
    U16 minX;
    U16 minY;
    U16 maxX;
    U16 maxY;
} PicEditMarkBox;

/* [~PMT  MANISH   20050616 */
typedef enum
{
    PE_PEN_SIZE_CAPTION = 0,
    PE_PEN_SIZE_SELECT,
#ifndef __MMI_TOUCH_SCREEN__
    PE_PEN_MOVE_CAPTION,
    PE_PEN_MOVE_SELECT,
#endif /* __MMI_TOUCH_SCREEN__ */ 
    PE_PEN_COLOR_CAPTION,
    PE_PEN_COLOR_SELECT
} PIC_EDIT_PEN_SETTINGS;

/* ~] */

typedef struct _bitmap_file_header
{
    char file_type1;
    char file_type2;
    U32 file_size;
    U16 reserved1;
    U16 reserved2;
    U32 bitmap_offset;
} PE_File_Header;

typedef struct _bitmap_info_header
{
    U32 header_size;
    U32 width;
    U32 height;
    U16 number_of_planes;
    U16 bits_per_pixel;
    U32 compression;
    U32 bitmap_size;
    U32 device_width;
    U32 device_height;
    U32 number_of_colors;
    U32 number_of_important_colors;
} PE_Info_Header;

typedef struct _pe_osd_object_struct
{
    U16 pos_x;
    U16 pos_y;
    U16 width;
    U16 height;
} PE_OSD_OBJECT;

typedef struct _pe_osd_struct
{
    PE_OSD_OBJECT color_picker;
    PE_OSD_OBJECT pen_size;
    PE_OSD_OBJECT zoom;
    PE_OSD_OBJECT draw_status;
#if defined (__MMI_MAINLCD_240X320__)
    PE_OSD_OBJECT undo;
    PE_OSD_OBJECT fill_color;
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
} PE_OSD_STRUCT;

#endif /* PICTUREEDITORDEFS_H */ 

