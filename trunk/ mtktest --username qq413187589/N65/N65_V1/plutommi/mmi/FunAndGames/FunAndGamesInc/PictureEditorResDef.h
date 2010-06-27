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
 *  PictureEditorResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Picture editor resource define.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef PICTUREEDITORRESDEF_H
#define PICTUREEDITORRESDEF_H

#include "MMIDataType.h"

typedef enum
{
    SCR_PE_SELECT_PIC_MENU = PICTURE_EDITOR_BASE + 1,
    SCR_PE_VIEW_PIC,
    SCR_PE_VIEW_OPTION,
    SCR_PE_EDIT_PIC,
    SCR_PE_EDIT_PIC_OPT,
    SCR_PE_EDIT_SAVE_AS,
    SCR_PE_EDIT_SAVE_AS_CONFIRM,
    SCR_PE_EDIT_INPUT_FILENAME,
    SCR_PE_EDIT_INPUT_FILENAME_OPTION,
    SCR_PE_PEN_SETTING,
    SCR_PE_PEN_SETTING_SAVE,
    SCR_PE_FILL_PIC,
    SCR_PE_FILL_PIC_SAVE,
    SCR_PE_CUSTOM_COLOR,
    SCR_PE_SCR_RESIZE,
    SCR_PE_HELP,
    SCR_PE_SAVE_IMAGE_CONFIRM,
    SCR_PE_CLEAR_IMAGE_CONFIRM,
    SCR_PE_DELETE_CONFIRM,
    SCR_PE_DELETE_ALL_CONFIRM
} PICTURE_EDITOR_SCREEN_ID;

typedef enum
{
    STR_MENU_PICTURE_EDITOR = PICTURE_EDITOR_BASE + 1,
    STR_PE_DRAW_PICTURE,
    /* STR_PE_EMPTY, */
    STR_PE_TITLE_COLOR_TXT,
    STR_PE_TITLE_PIXEL_TXT,

    //      STR_PE_VIEW_OPT,
    //    STR_PE_ADD_OPT,

    //      STR_PE_VIEW_OPT_EDIT,
    //      STR_PE_VIEW_OPT_DELETE,
    //      STR_PE_VIEW_OPT_DELETEALL,

    //      STR_PE_EDIT_OPT,
    //      STR_PE_EDIT_OPT_SAVE_PIC,
    STR_PE_EDIT_OPT_SAVE_PIC_AS,
    STR_PE_EDIT_OPT_REPLACE,
    STR_PE_EDIT_OPT_PEN_SETTING,
    STR_PE_EDIT_OPT_FILL_PIC,
    STR_PE_EDIT_OPT_MARK,
    STR_PE_EDIT_OPT_CUT,
    STR_PE_EDIT_OPT_COPY,
    STR_PE_EDIT_OPT_PASTE,
    STR_PE_EDIT_OPT_UNDO,
    STR_PE_EDIT_OPT_REDO,
    STR_PE_EDIT_OPT_ZOOM,
    STR_PE_EDIT_OPT_FULL_SIZE,
    STR_PE_EDIT_OPT_RESIZE,
    STR_PE_EDIT_OPT_HELP,

    STR_PE_PEN_SIZE,
    STR_PE_PEN_MOVE_FACTOR,
    STR_PE_PEN_COLOR,

    STR_PE_PEN_SIZE_1,
    STR_PE_PEN_SIZE_2,
    STR_PE_PEN_SIZE_3,
    STR_PE_PEN_SIZE_4,
#ifndef __MMI_TOUCH_SCREEN__    /* PMT MANISH   20050616 */
    STR_PE_PEN_MOVE_1,
    STR_PE_PEN_MOVE_2,
    STR_PE_PEN_MOVE_3,
    STR_PE_PEN_MOVE_4,
#endif /* __MMI_TOUCH_SCREEN__ */ 
    STR_PE_COLOR_NONE,
    STR_PE_COLOR_BLACK,
    STR_PE_COLOR_BROWN,
    STR_PE_COLOR_DARK_GREEN,
    STR_PE_COLOR_DARK_BLUE,
    STR_PE_COLOR_VOILET,
    STR_PE_COLOR_GRAY,
    STR_PE_COLOR_LIGHT_GRAY,
    STR_PE_COLOR_RED,
    STR_PE_COLOR_GREEN,
    STR_PE_COLOR_YELLOW,
    STR_PE_COLOR_BLUE,
    STR_PE_COLOR_PINK,
    STR_PE_COLOR_LIGHT_BLUE,
    STR_PE_COLOR_WHITE,
    STR_PE_COLOR_CUSTOM_1,
    /* STR_PE_SAVE, */
    STR_PE_RESIZE_TO,
    STR_PE_RESIZE_16,
    STR_PE_RESIZE_32,
    STR_PE_RESIZE_64,
#ifdef __MMI_MAINLCD_240X320__
    STR_PE_RESIZE_128,  /* 110805 resize region Calvin add */
#endif 
    STR_PE_RESIZE_CUSTOM,
    STR_PE_RESIZE_WIDTH,
    STR_PE_RESIZE_HEIGHT,
#ifdef __MMI_MAINLCD_240X320__  /* 092005 Image Editor Size Calvin */
    STR_PE_RESIZE_ERROR_BIG,
#else 
    STR_PE_RESIZE_ERROR,
#endif 

    STR_PE_COLOR_SEL,
#ifdef __MMI_TOUCH_SCREEN__
    STR_PE_HELP_DESCRIPTION_TOUCH,
#else 
    STR_PE_HELP_DESCRIPTION,
#endif 
    STR_PE_INVALID_FORMAT
} PIC_EDITOR_STR_IDS;

typedef enum
{
    IMG_PE_CAPTION = PICTURE_EDITOR_BASE + 1,
    IMG_PE_IMAGE_EDITOR,
    IMG_PE_BACKGROUND,
    IMG_PE_IM_ARROW,
    IMG_PE_IM_PEN
} PIC_EDITOR_IMG_IDS;


#endif /* PICTUREEDITORRESDEF_H */ 

