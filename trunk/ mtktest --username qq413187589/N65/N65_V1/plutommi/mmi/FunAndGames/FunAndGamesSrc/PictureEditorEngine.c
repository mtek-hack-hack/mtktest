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
 *  PictureEditorEngine.c
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

   FILENAME : PictureEditorEngine.c

   PURPOSE     : Main functions of the Picture Editor Engine Function

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : Jan-21-2004

**************************************************************/

#include "MMI_include.h"
#include "PictureEditorDefs.h"
#include "PictureEditorProts.h"
#include "FileManagerGProt.h"
#include "Downloaddefs.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "wgui_status_icons.h"
#ifdef __MMI_TOUCH_SCREEN__
#endif /* __MMI_TOUCH_SCREEN */
#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
/* 051605 Calvin modified */
#if defined (__MMI_MAINLCD_240X320__)
const PE_OSD_STRUCT pe_osd = 
{
    {56, 22, 23, 23},   /* color_picter */
    {21, 22, 23, 23},   /* pen_size */
    {91, 22, 23, 23},   /* zoom */
    {196, 22, 23, 23},  /* draw status */
    {126, 22, 23, 23},  /* undo */
    {161, 22, 23, 23}   /* fill */
};
#else /* defined (__MMI_MAINLCD_240X320__) */ 
const PE_OSD_STRUCT pe_osd = 
{
    {25, 2, 23, 23},    /* color_picter */
    {60, 2, 23, 23},    /* pen_size */
    {95, 2, 23, 23},    /* zoom */
    {130, 2, 23, 23}    /* draw status */
};
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
/* Calvin end */

/**********************Defines************************/
#define IM_COL_TXT_POS 2
#define IM_COL_BOX_POS 37
#define IM_PEN_TXT_POS (UI_device_width-65)
#define IM_PEN_VAL_POS (UI_device_width-34)
#define IM_PEN_IMG_POS (UI_device_width-19)

/**********************Local Variables************************/

/**********************Global Variables************************/
PicEditMarkBox gPicEditZoomWindow;
U8 gPEZoomFactor = 4;

/**********************Extern Variables************************/
extern PictureEditorPen *gpPicEditPen;
extern PicEditMarkBox gPicEditMark;

extern U8 *gpPEFileBuff;
extern U8 gPECurrentAction;
extern U16 gPEAttrib;
extern U32 gPEColorRGB[];
extern U8 gPicEditCurrPic;

/* extern U8 gPEImageCount; */

/* 051605 Calvin added */
#if defined(__MMI_MAINLCD_240X320__)
extern U8 *gpPicEditFillColorIndex;
extern U8 gPEBitsPerPixel;
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
/* Calvin end */

/* MTK Elvis for R2L characters */
extern BOOL r2lMMIFlag;

/* MTK end */

/* 051605 Calvin added */
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;

/* Calvin end */

/* PMT VIKAS START 20050707 */
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__


/*****************************************************************************
 * FUNCTION
 *  shuffle_draw_image_editor_background
 * DESCRIPTION
 *  To Show Softkeys background in imageEditor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
PU8 dbackGround_image;
void shuffle_draw_image_editor_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_show_transparent_image(0, 0, dbackGround_image, gui_transparent_color(0, 0, 0));
}
#endif /* __MMI_UI_DALMATIAN_SOFTKEYS__ */ 
/* PMT VIKAS END 20050707 */


/*****************************************************************************
 * FUNCTION
 *  ShowCategoryScr4PicEdit
 * DESCRIPTION
 *  Special category screen used for viewing and editing image
 * PARAMETERS
 *  colorStringId           [IN]        String Id for Color
 *  penColor                [IN]        Color value
 *  pixelStringId           [IN]        String Id for Pixel
 *  penPixel                [IN]        Pixel value
 *  penImageId              [IN]        Pen Image Id
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the Left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the Right softkey
 *  background_imageid      [IN]        Background image id
 *  imageData               [IN]        Image Data
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategoryScr4PicEdit(
        U16 colorStringId,
        color penColor,
        U16 pixelStringId,
        U8 penPixel,
        U16 penImageId,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 background_imageid,
        U8 *imageData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 backGround_image = (PU8) GetImage(background_imageid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_register_image_editor_pen_handlers();
#endif 

    gui_reset_clip();
    gui_lock_double_buffer();

#if defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#endif 
    dm_set_scr_bg_redraw(MMI_TRUE);
#else /* defined(__MMI_MAINLCD_240X320__) */ 
    entry_full_screen();
#endif /* defined(__MMI_MAINLCD_240X320__) */ 

    clear_category_screen_key_handlers();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);

#if defined (__MMI_MAINLCD_240X320__)
    if (gui_is_entry_new_screen() == MMI_TRUE)
    {
        gui_set_entry_new_screen(MMI_FALSE);

        gdi_layer_multi_layer_enable();
        gdi_layer_get_base_handle(&wgui_base_layer);
        gui_layer_transparent(
            wgui_base_layer,
            UI_SUBMENU_OPACITY_BASED_LAYER,
            0,
            0,
            UI_DEVICE_WIDTH - 1,
            UI_DEVICE_HEIGHT - 1);
        if (wgui_layer_1 == GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_create(0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT, &wgui_layer_1);
        }

        gdi_layer_set_active(wgui_layer_1);
        gdi_layer_lock_frame_buffer();

        gdi_layer_push_clip();
        gdi_layer_reset_clip();

        gdi_layer_set_opacity(TRUE, 255);
        gdi_image_draw_animation(0, 0, (U8*) backGround_image, NULL);

        gdi_layer_pop_clip();

        gdi_layer_unlock_frame_buffer();
        gdi_layer_restore_base_active();

        gdi_layer_set_blt_layer(wgui_layer_1, wgui_base_layer, 0, 0);
        gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1);

        gdi_layer_set_active(wgui_base_layer);
        gdi_draw_solid_rect(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_layer_get_base_handle(&wgui_base_layer);
        gui_layer_transparent(
            wgui_base_layer,
            UI_SUBMENU_OPACITY_BASED_LAYER,
            0,
            0,
            UI_DEVICE_WIDTH - 1,
            UI_DEVICE_HEIGHT - 1);
        gdi_layer_set_active(wgui_base_layer);
        gdi_draw_solid_rect(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1, GDI_COLOR_TRANSPARENT);

    }
#else /* defined (__MMI_MAINLCD_240X320__) */ 
    gui_show_transparent_image(0, 0, backGround_image, gui_transparent_color(0, 0, 0));
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
    show_status_icons();
    ShowPicEditTitleBar(colorStringId, penColor, pixelStringId, penPixel, penImageId);

    ShowPicEditImageWindow(imageData);

    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    register_left_softkey_handler();
    register_right_softkey_handler();
    register_default_hide_softkeys();

#ifndef __MMI_UI_DALMATIAN_SOFTKEYS__
    disable_softkey_background();
#else /* __MMI_UI_DALMATIAN_SOFTKEYS__ */ 
    dbackGround_image = backGround_image;
    gui_register_button_shuffle(shuffle_draw_image_editor_background);  /* register the background drower */
#endif /* __MMI_UI_DALMATIAN_SOFTKEYS__ */ 
    show_left_softkey();
    show_right_softkey();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  ShowPicEditTitleBar
 * DESCRIPTION
 *  To Show title bar for  special category screen used for viewing and editing image
 * PARAMETERS
 *  colorStringId       [IN]        String Id for Color
 *  penColor            [IN]        Color value
 *  pixelStringId       [IN]        String Id for Pixel
 *  penPixel            [IN]        Pixel value
 *  penImageId          [IN]        Pen Image Id
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPicEditTitleBar(U16 colorStringId, color penColor, U16 pixelStringId, U8 penPixel, U16 penImageId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __MMI_TOUCH_SCREEN__
    S32 x, width, height, text_width, text_height;
    PU8 penImage = (PU8) GetImage(penImageId);
    stFontAttribute *f = (UI_font_type) (current_MMI_theme->title_text_font);
    UI_string_type buffer[2];
    S32 w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(f);

    gui_push_clip();

    /* Pen Color */
    gui_set_clip(0, PIC_EDITOR_TITLE_Y, UI_device_width - 1, PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT - 1);

    x = 2;
    gui_measure_string(get_string(colorStringId), &text_width, &text_height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(2 + text_width, PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1));
    }
    else
    {
        gui_move_text_cursor(2, PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1));
    }

    gui_set_text_color(GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
    gui_print_text((UI_string_type) GetString(colorStringId));

    x += text_width;
    gui_draw_rectangle(
        x,
        PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1),
        x + 5,
        PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT - ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1),
        GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
    gui_fill_rectangle(
        x + 1,
        PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1) + 1,
        x + 4,
        PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT - ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1) - 1,
        penColor);

    /* Pen width */
    gui_measure_string(get_string(pixelStringId), &text_width, &text_height);
    x = UI_device_width - text_width;
    gui_measure_character((UI_character_type) '0', &width, &height);
    x -= (width + 2);
    gui_measure_image((PU8) penImage, &width, &height);
    x -= (width + 2);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + text_width, PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1));
    }
    else
    {
        gui_move_text_cursor(x, PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1));
    }

    gui_print_text((UI_string_type) GetString(pixelStringId));

    gui_itoa(penPixel, (UI_string_type) buffer, 10);
    w = gui_get_string_width((UI_string_type) buffer);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            x + text_width + 1 + w,
            PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1));
    }
    else
    {
        gui_move_text_cursor(x + text_width + 1, PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - text_height) >> 1));
    }

    gui_print_text((UI_string_type) buffer);

    gui_show_transparent_image(
        UI_device_width - width - 1,
        PIC_EDITOR_TITLE_Y + ((PIC_EDITOR_TITLE_HEIGHT - height) >> 1),
        penImage,
        gui_transparent_color(0, 0, 0));

    gui_pop_clip();
#else /* __MMI_TOUCH_SCREEN__ */ 

    PU8 penImage = (PU8) GetImage(penImageId);

#ifdef __MMI_MAINLCD_240X320__  /* 110705 image editor Calvin add */
    stFontAttribute *f = &MMI_small_font;
    U16 RedoUndo_id;
#else /* __MMI_MAINLCD_240X320__ */ 
    stFontAttribute *f = (UI_font_type) (current_MMI_theme->title_text_font);
#endif /* __MMI_MAINLCD_240X320__ */ 
    UI_string_type buffer[2];
    S32 w;

    gui_set_text_color(UI_COLOR_BLACK); /* This line needs to be added */
    gui_set_font(f);
    gdi_layer_push_clip();
    gdi_layer_reset_clip();
    /* Pen color */
    gui_draw_rectangle(
        pe_osd.color_picker.pos_x + 5,
        pe_osd.color_picker.pos_y + pe_osd.color_picker.height + 2,
        pe_osd.color_picker.pos_x + pe_osd.color_picker.width - 5,
        pe_osd.color_picker.pos_y + pe_osd.color_picker.height + 14,
        GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
    gui_fill_rectangle(
        pe_osd.color_picker.pos_x + 6,
        pe_osd.color_picker.pos_y + pe_osd.color_picker.height + 3,
        pe_osd.color_picker.pos_x + pe_osd.color_picker.width - 6,
        pe_osd.color_picker.pos_y + pe_osd.color_picker.height + 13,
        penColor);

    /* Pen width */
    gui_itoa(penPixel, (UI_string_type) buffer, 10);
    w = gui_get_string_width((UI_string_type) buffer);
    gui_move_text_cursor(pe_osd.pen_size.pos_x + ((pe_osd.pen_size.width - w) >> 1), pe_osd.color_picker.pos_y + pe_osd.color_picker.height + 2);       /* 051605 Calvin modified */
    gui_print_text((UI_string_type) buffer);

    /* Zoom */
    /* 051605 Calvin mdified */
    w = gui_get_string_width((UI_string_type) L"x1");
    gui_move_text_cursor(
        pe_osd.zoom.pos_x + ((pe_osd.zoom.width - w) >> 1),
        pe_osd.zoom.pos_y + pe_osd.zoom.height + 2);
    if (IS_PE_ZOOM_IMAGE(gPEAttrib))
    {
        gui_print_text((UI_string_type) L"x2");
    }
    else
    {
        gui_print_text((UI_string_type) L"x1");
    }

    /* Draw status */
    w = gui_get_string_width((UI_string_type) L"State");
    gui_move_text_cursor(pe_osd.draw_status.pos_x + ((pe_osd.draw_status.width - w) >> 1), pe_osd.draw_status.pos_y + pe_osd.draw_status.height + 2);   /* 051605 Calvin modified */
    gui_print_text((UI_string_type) L"State");
    gdi_image_draw(pe_osd.draw_status.pos_x, pe_osd.draw_status.pos_y, (U8*) penImage);
    /* Calvin end */

    /* 010306 image editor Calvin Start */
#if defined(__MMI_MAINLCD_240X320__)
    /* Undo */
    if (IS_PE_IMAGE_EDIT(gPEAttrib) && (IS_PE_UNDO_IMAGE(gPEAttrib)))
    {
        RedoUndo_id = STR_PE_EDIT_OPT_REDO;
    }
    else
    {
        RedoUndo_id = STR_PE_EDIT_OPT_UNDO;
    }
    w = gui_get_string_width((UI_string_type) GetString(RedoUndo_id));
    gui_move_text_cursor(
        pe_osd.undo.pos_x + ((pe_osd.undo.width - w) >> 1),
        pe_osd.undo.pos_y + pe_osd.undo.height + 2);
    gui_print_text((UI_string_type) GetString(RedoUndo_id));

    /* Fill */
    gui_draw_rectangle(
        pe_osd.fill_color.pos_x + 5,
        pe_osd.fill_color.pos_y + pe_osd.fill_color.height + 2,
        pe_osd.fill_color.pos_x + pe_osd.fill_color.width - 5,
        pe_osd.fill_color.pos_y + pe_osd.fill_color.height + 14,
        GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
    gui_fill_rectangle(
        pe_osd.fill_color.pos_x + 6,
        pe_osd.fill_color.pos_y + pe_osd.fill_color.height + 3,
        pe_osd.fill_color.pos_x + pe_osd.fill_color.width - 6,
        pe_osd.fill_color.pos_y + pe_osd.fill_color.height + 13,
        GetPEColor(gPEColorRGB[*gpPicEditFillColorIndex]));
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
    /* Calvin end */

    gdi_layer_pop_clip();
#endif /* __MMI_TOUCH_SCREEN__ */ 
}

/* [~PMT  MANISH   20050311 Function to Handle Pen Events on Title Bar of Image Editor */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  HandleImageEditorTitleEvent
 * DESCRIPTION
 *  To handle Pen events on Image Editor Title
 *  
 *  Identifies the component of Image Editor Title on which pen event comes and changes its value accordingly
 * PARAMETERS
 *  X           [IN]        
 *  Y           [IN]        
 *  x(?)        [IN]        
 *  y(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/* 051605 Calvin added */
extern U8 gPECurrentAction;

/* Calvin end */

pBOOL HandleImageEditorTitleEvent(U16 X, U16 Y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (PEN_CHECK_BOUND
        (X, Y, pe_osd.color_picker.pos_x, pe_osd.color_picker.pos_y, pe_osd.color_picker.width,
         pe_osd.color_picker.height))
    {
        /* Pen on Color */
        gui_lock_double_buffer();   /* 051605 Calvin added */
        ChangePEPenColor();
        /* 051605 Calvin added */
    #if defined (__MMI_MAINLCD_240X320__)
        ChangePEFillColor();
    #endif 
        /* Calvin end */
        RedrawPicEditTitleBar();
        gui_unlock_double_buffer(); /* 051605 Calvin added */
        gui_BLT_double_buffer(0, PIC_EDITOR_TITLE_Y, UI_device_width - 1, PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT);        /* 051605 Calvin added */
        return MMI_TRUE;
    }
    if (PEN_CHECK_BOUND
        (X, Y, pe_osd.pen_size.pos_x, pe_osd.pen_size.pos_y, pe_osd.pen_size.width, pe_osd.pen_size.height))
    {
        /* Pen on Pen size */
        ChangePEPenSize();
        RedrawPicEditTitleBar();
        return MMI_TRUE;
    }
    if (PEN_CHECK_BOUND(X, Y, pe_osd.zoom.pos_x, pe_osd.zoom.pos_y, pe_osd.zoom.width, pe_osd.zoom.height))
    {
        /* Pen on Zoom */
        if (IS_PE_ZOOM_IMAGE(gPEAttrib))
        {
            UNSET_PE_ZOOM_IMAGE(gPEAttrib);
        }
        else
        {
            SetPicEditZoomWindow(TRUE);
            SET_PE_ZOOM_IMAGE(gPEAttrib);
        }
        RedrawPicEditTitleBar();
        ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
        return MMI_TRUE;
    }
    if (PEN_CHECK_BOUND
        (X, Y, pe_osd.draw_status.pos_x, pe_osd.draw_status.pos_y, pe_osd.draw_status.width, pe_osd.draw_status.height))
    {
        /* Pen on Draw Status */
        DrawPicOnKey_5();
        return MMI_TRUE;
    }

    /* 051605 Calvin added */
#if defined (__MMI_MAINLCD_240X320__)
    if (PEN_CHECK_BOUND(X, Y, pe_osd.undo.pos_x, pe_osd.undo.pos_y, pe_osd.undo.width, pe_osd.undo.height))
    {
        /* Pen on Undo */
        gPECurrentAction = SEL_PE_EDIT_OPT_UNDO;
        ExchangePEContext();
        SetPicEditZoomWindow(TRUE);
        RedrawPicEditTitleBar();
        ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
        return MMI_TRUE;
    }

    if (PEN_CHECK_BOUND
        (X, Y, pe_osd.fill_color.pos_x, pe_osd.fill_color.pos_y, pe_osd.fill_color.width, pe_osd.fill_color.height))
    {
        /* Pen on Fill color */
        U8 infoPalette[MAX_TYPE_PEN_COLOR * 4];

        GetPaletteInfo(infoPalette);
        gpPicEditPen->penBackgrdColorIndex = *gpPicEditFillColorIndex;

        SavePEContext();
        SET_PE_IMAGE_EDIT(gPEAttrib);
        UNSET_PE_MARK_IMAGE(gPEAttrib);
        UNSET_PE_COPY_IMAGE(gPEAttrib);

        memcpy(&gpPEFileBuff[54], &infoPalette, MAX_TYPE_PEN_COLOR * gPEBitsPerPixel);
        memset(
            &gpPEFileBuff[PIC_EDIT_FILE_HEADER_SIZE],
            ((gpPicEditPen->penBackgrdColorIndex) | (gpPicEditPen->penBackgrdColorIndex << 4)),
            (gpPicEditPen->maxY - gpPicEditPen->minY) * GetImageWidth(gpPicEditPen->minX, gpPicEditPen->maxX));

        RedrawPicEditTitleBar();
        ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
        return MMI_TRUE;
    }
#endif /* defined (__MMI_MAINLCD_240X320__) */ 
    /* Calvin end */

    return MMI_FALSE;
#endif /* (0) */ 
}
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* ~] */


/*****************************************************************************
 * FUNCTION
 *  RedrawPicEditTitleBar
 * DESCRIPTION
 *  To redraw title bar for  special category screen used for editing image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RedrawPicEditTitleBar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 penImageId;

#if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* (0) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PE_PEN_DOWN(gPEAttrib))
    {
        penImageId = IMG_PE_IM_PEN;
    }
    else
    {
        penImageId = 0;
    }
    gui_lock_double_buffer();
    gui_push_clip();

    /* 051605 Calvin modified */
    /* gui_set_clip(0,0,UI_device_width-1,PIC_EDITOR_TITLE_HEIGHT+30); */
    gui_set_clip(0, PIC_EDITOR_TITLE_Y, UI_device_width - 1, PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT);

    if (wgui_is_wallpaper_on_bottom())
    {
        gdi_draw_solid_rect(
            0,
            PIC_EDITOR_TITLE_Y,
            UI_device_width - 1,
            PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_image_draw(0, 0, (U8*) GetImage(IMG_PE_BACKGROUND));
    }
    /* Calvin end */

    ShowPicEditTitleBar(
        STR_PE_TITLE_COLOR_TXT,
        GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]),
        STR_PE_TITLE_PIXEL_TXT,
        gpPicEditPen->penPixel,
        penImageId);

    gui_pop_clip();
    gui_unlock_double_buffer();
    /* 051605 Calvin modified */
    /* gui_BLT_double_buffer(0,0,UI_device_width-1,PIC_EDITOR_TITLE_HEIGHT+30); */
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, PIC_EDITOR_TITLE_Y + PIC_EDITOR_TITLE_HEIGHT);
    /* Calvin end */
#endif /* (0) */ 
    UNSET_PE_CURSOR_TIMER(gPEAttrib);
    gui_start_timer(PE_BLINKING_DURATION, DisplayPECursor);
}


/*****************************************************************************
 * FUNCTION
 *  ShowPicEditImageWindow
 * DESCRIPTION
 *  Shows image passed in the image window of image editor
 * PARAMETERS
 *  imageData       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPicEditImageWindow(U8 *imageData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0, height = 0;

    U16 minX = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
    U16 minY = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_clip(minX - 1, minY - 1, minX + PE_SCR_SIZE_MAX, minY + PE_SCR_SIZE_MAX);
    gui_fill_rectangle(
        minX - 1,
        minY - 1,
        minX + PE_SCR_SIZE_MAX,
        minY + PE_SCR_SIZE_MAX,
        GetPEColor(gPEColorRGB[PE_COLOR_WHITE]));

    gui_measure_image((PU8) imageData, &width, &height);

    if (width > PE_SCR_SIZE_MAX)
    {
        width = PE_SCR_SIZE_MAX;
    }
    if (height > PE_SCR_SIZE_MAX)
    {
        height = PE_SCR_SIZE_MAX;
    }

    gpPicEditPen->minX = SET_WINDOW_MINX(width);
    gpPicEditPen->maxX = gpPicEditPen->minX + (U16) width;
    gpPicEditPen->minY = SET_WINDOW_MINY(height);
    gpPicEditPen->maxY = gpPicEditPen->minY + (U16) height;

    if (IS_PE_VIEW_IMAGE(gPEAttrib))
    {
        gui_draw_rectangle(
            gpPicEditPen->minX - 1,
            gpPicEditPen->minY - 1,
            gpPicEditPen->maxX,
            gpPicEditPen->maxY,
            GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
        gui_set_clip(gpPicEditPen->minX, gpPicEditPen->minY, gpPicEditPen->maxX - 1, gpPicEditPen->maxY - 1);
        gui_show_image(gpPicEditPen->minX, gpPicEditPen->minY, (PU8) imageData);
    }
    else
    {
        if (IS_PE_ZOOM_IMAGE(gPEAttrib))
        {
            U16 minX, minY, maxX, maxY;

            if (((gPicEditZoomWindow.maxX - gPicEditZoomWindow.minX) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
            {
                minX = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
                maxX = minX + PE_SCR_SIZE_MAX;
            }
            else
            {
                minX = SET_WINDOW_MINX((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
                maxX = minX + ((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
            }

            if (((gPicEditZoomWindow.maxY - gPicEditZoomWindow.minY) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
            {
                minY = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);
                maxY = minY + PE_SCR_SIZE_MAX;
            }
            else
            {
                minY = SET_WINDOW_MINY((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
                maxY = minY + ((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
            }
            gui_draw_rectangle(minX - 1, minY - 1, maxX, maxY, GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
            gui_set_clip(minX, minY, maxX - 1, maxY - 1);
            DrawZoomImage(
                gpPEFileBuff,
                gPicEditZoomWindow.minX - gpPicEditPen->minX,
                gPicEditZoomWindow.minY - gpPicEditPen->minY,
                gPEZoomFactor,
                minX,
                minY,
                maxX - minX,
                maxY - minY);
            if (gPECurrentAction != SEL_PE_EDIT_OPT_MARK)
            {
                gui_fill_rectangle(
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor,
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor + gpPicEditPen->penPixel * gPEZoomFactor - 1,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor + gpPicEditPen->penPixel * gPEZoomFactor - 1,
                    GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]));
            }
            else
            {
                gui_fill_rectangle(
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor,
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor,
                    GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]));
            }
            if ((gPECurrentAction == SEL_PE_EDIT_OPT_MARK) || (gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE))
            {
                ShowPicEditMarkBox(minX, minY);
            }
        }
        else
        {
            gui_draw_rectangle(
                gpPicEditPen->minX - 1,
                gpPicEditPen->minY - 1,
                gpPicEditPen->maxX,
                gpPicEditPen->maxY,
                GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
            gui_set_clip(gpPicEditPen->minX, gpPicEditPen->minY, gpPicEditPen->maxX - 1, gpPicEditPen->maxY - 1);
            gui_show_image(gpPicEditPen->minX, gpPicEditPen->minY, (PU8) imageData);
            if (gPECurrentAction != SEL_PE_EDIT_OPT_MARK)
            {
                gui_fill_rectangle(
                    gpPicEditPen->penX,
                    gpPicEditPen->penY,
                    gpPicEditPen->penX + gpPicEditPen->penPixel - 1,
                    gpPicEditPen->penY + gpPicEditPen->penPixel - 1,
                    GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]));
            }
            else
            {
                gui_fill_rectangle(
                    gpPicEditPen->penX,
                    gpPicEditPen->penY,
                    gpPicEditPen->penX,
                    gpPicEditPen->penY,
                    GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]));
            }
            if ((gPECurrentAction == SEL_PE_EDIT_OPT_MARK) || (gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE))
            {
                ShowPicEditMarkBox(0, 0);
            }
        }
        UNSET_PE_CURSOR_TIMER(gPEAttrib);
        gui_start_timer(PE_BLINKING_DURATION, DisplayPECursor);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowPicEditMarkBox
 * DESCRIPTION
 *  Shows mark box when mark option is selected
 * PARAMETERS
 *  scrMinX     [IN]        
 *  scrMinY     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ShowPicEditMarkBox(U16 scrMinX, U16 scrMinY)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 minX = 0, minY = 0, maxX = 0, maxY = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE)
    {
        minX = gPicEditMark.maxX - gPicEditMark.minX;
        minY = gPicEditMark.maxY - gPicEditMark.minY;
        gPicEditMark.maxX = maxX = gpPicEditPen->penX + minX;
        gPicEditMark.minX = minX = gpPicEditPen->penX;
        gPicEditMark.maxY = maxY = gpPicEditPen->penY + minY;
        gPicEditMark.minY = minY = gpPicEditPen->penY;
    }
    else
    {
        if (gpPicEditPen->penX <= gPicEditMark.minX)
        {
            minX = gpPicEditPen->penX;
            maxX = gPicEditMark.maxX;
        }
        else
        {
            minX = gPicEditMark.minX;
            maxX = gpPicEditPen->penX;
        }

        if (gpPicEditPen->penY <= gPicEditMark.minY)
        {
            minY = gpPicEditPen->penY;
            maxY = gPicEditMark.maxY;
        }
        else
        {
            minY = gPicEditMark.minY;
            maxY = gpPicEditPen->penY;
        }
    }
    if (IS_PE_ZOOM_IMAGE(gPEAttrib))
    {
        UI_draw_dashed_rectangle(
            scrMinX + (minX - gPicEditZoomWindow.minX) * gPEZoomFactor,
            scrMinY + (minY - gPicEditZoomWindow.minY) * gPEZoomFactor,
            scrMinX + (maxX - gPicEditZoomWindow.minX + 1) * gPEZoomFactor - 1,
            scrMinY + (maxY - gPicEditZoomWindow.minY + 1) * gPEZoomFactor - 1,
            GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
    }
    else
    {
        UI_draw_dashed_rectangle(minX, minY, maxX, maxY, GetPEColor(gPEColorRGB[PE_COLOR_BLACK]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  DisplayPECursor
 * DESCRIPTION
 *  To Display blinking cursor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DisplayPECursor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U8 curColor = PE_COLOR_WHITE;
    static S32 oldPenpixel;
    U16 minX = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
    U16 minY = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_PE_CURSOR_TIMER(gPEAttrib))
    {
        if (gpPicEditPen->penColorIndex == PE_COLOR_WHITE)
        {
            curColor = PE_COLOR_BLACK;
        }
        else
        {
            curColor = PE_COLOR_WHITE;
        }
    }
    else
    {
        curColor = gpPicEditPen->penColorIndex;
    }

    TOGGLE_PE_CURSOR_TIMER(gPEAttrib);

    gui_lock_double_buffer();

    if (!IS_PE_VIEW_IMAGE(gPEAttrib))
    {
        if (IS_PE_ZOOM_IMAGE(gPEAttrib))
        {
            U16 maxX, maxY;

            if (((gPicEditZoomWindow.maxX - gPicEditZoomWindow.minX) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
            {
                minX = SET_WINDOW_MINX(PE_SCR_SIZE_MAX);
                maxX = minX + PE_SCR_SIZE_MAX;
            }
            else
            {
                minX = SET_WINDOW_MINX((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
                maxX = minX + ((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor);
            }

            if (((gPicEditZoomWindow.maxY - gPicEditZoomWindow.minY) * gPEZoomFactor) >= PE_SCR_SIZE_MAX)
            {
                minY = SET_WINDOW_MINY(PE_SCR_SIZE_MAX);
                maxY = minY + PE_SCR_SIZE_MAX;
            }
            else
            {
                minY = SET_WINDOW_MINY((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
                maxY = minY + ((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor);
            }
            gui_set_clip(minX, minY, maxX - 1, maxY - 1);   /* PMT MANISH   20050325 Set Clip Here to view blinking cursor in whole Zoom Window */
            if (gPECurrentAction != SEL_PE_EDIT_OPT_MARK)
            {
                if (gpPicEditPen->penPixel < oldPenpixel)
                {
                    ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
                    gui_unlock_double_buffer();
                    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
                    oldPenpixel = gpPicEditPen->penPixel;
                    return; /* Smaller pixel size cursor is already displayed */
                }
                oldPenpixel = gpPicEditPen->penPixel;
                gui_fill_rectangle(
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor,
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor + gpPicEditPen->penPixel * gPEZoomFactor - 1,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor + gpPicEditPen->penPixel * gPEZoomFactor - 1,
                    GetPEColor(gPEColorRGB[curColor]));
            }
            else
            {
                gui_fill_rectangle(
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor,
                    minX + (gpPicEditPen->penX - gPicEditZoomWindow.minX) * gPEZoomFactor,
                    minY + (gpPicEditPen->penY - gPicEditZoomWindow.minY) * gPEZoomFactor,
                    GetPEColor(gPEColorRGB[curColor]));
            }
        }
        else
        {
            gui_set_clip(gpPicEditPen->minX, gpPicEditPen->minY, gpPicEditPen->maxX - 1, gpPicEditPen->maxY - 1);       /* PMT MANISH   20050325 Set Clip Here */
            if (gPECurrentAction != SEL_PE_EDIT_OPT_MARK)
            {
                if (gpPicEditPen->penPixel < oldPenpixel)
                {
                    ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
                    gui_unlock_double_buffer();
                    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
                    oldPenpixel = gpPicEditPen->penPixel;
                    return; /* Smaller pixel size cursor is already displayed */
                }
                oldPenpixel = gpPicEditPen->penPixel;
                gui_fill_rectangle(
                    gpPicEditPen->penX,
                    gpPicEditPen->penY,
                    gpPicEditPen->penX + gpPicEditPen->penPixel - 1,
                    gpPicEditPen->penY + gpPicEditPen->penPixel - 1,
                    GetPEColor(gPEColorRGB[curColor]));
            }
            else
            {
                gui_fill_rectangle(
                    gpPicEditPen->penX,
                    gpPicEditPen->penY,
                    gpPicEditPen->penX,
                    gpPicEditPen->penY,
                    GetPEColor(gPEColorRGB[curColor]));
            }
        }
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    gui_start_timer(PE_BLINKING_DURATION, DisplayPECursor);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditShowImage
 * DESCRIPTION
 *  Entry function for Image view
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditShowImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ExecuteCurrExitHandler (); */
    if (GetPicEditCurrentImageId())
    {
        if (SetPicEditImageDataBuff(GetPicEditCurrentImageName()) == MMI_FALSE)
        {
            DisplayPopupCallBack(
                (U8*) GetString(STR_PE_INVALID_FORMAT),
                IMG_GLOBAL_UNFINISHED,
                0,
                1000,
                (U8) ERROR_TONE,
                EntryScr4PicEditDeleteConfirm);
            return;
        }

    }
    else
    {
        SetPicEditEmptyImageDataBuff();
    }
    SET_PE_VIEW_IMAGE(gPEAttrib);
    EntryNewScreen(SCR_PE_VIEW_PIC, ExitScr4PicEditShowImage, NULL, NULL);

    /* if (gPicEditCurrPic<gPEImageCount) */

    ShowCategoryScr4PicEdit(STR_PE_TITLE_COLOR_TXT, GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]),
                            STR_PE_TITLE_PIXEL_TXT, gpPicEditPen->penPixel,
#if (0)
/* under construction !*/
#else 
                            0,
#endif 
                            STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,
                            STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                            IMG_PE_BACKGROUND, &gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);

    ChangePicEditShowImageSoftkey();
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(ShowPicEditPrevImage, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ShowPicEditNextImage, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    /* SetExitHandler (SCR_PE_VIEW_PIC, ExitScr4PicEditShowImage); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditShowImage
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditShowImage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditShowImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_PE_VIEW_PIC;
    h.entryFuncPtr = EntryScr4PicEditShowImage;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
    enable_softkey_background();
    leave_full_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ChangePicEditShowImageSoftkey
 * DESCRIPTION
 *  Changes Softkey of image editor while viewing image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePicEditShowImageSoftkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (gPicEditCurrPic<gPEImageCount) */
    if (GetPicEditCurrentImageId())
    {
        /* Register function for left soft key */
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(EntryScr4PicEditViewOpt, KEY_EVENT_UP);
        SetKeyHandler(EntryScr4PicEditViewOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        /* Register function for left soft key */
        ChangeLeftSoftkey((U16) NULL, (U16) NULL);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  EntryScr4PicEditEditImage
 * DESCRIPTION
 *  Entry function for Image editing Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScr4PicEditEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 penImageId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UNSET_PE_VIEW_IMAGE(gPEAttrib);
    /* ExecuteCurrExitHandler (); */
    EntryNewScreen(SCR_PE_EDIT_PIC, ExitScr4PicEditEditImage, NULL, NULL);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_move_offset(
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if (IS_PE_PEN_DOWN(gPEAttrib))
    {
        penImageId = IMG_PE_IM_PEN;
    }
    else
#if (0)
/* under construction !*/
#else /* (0) */ 
        penImageId = 0;
#endif /* (0) */ 
    switch (gPECurrentAction)
    {
        case SEL_PE_EDIT_OPT_RESIZE:    /* Resize */
        case SEL_PE_EDIT_OPT_MARK:      /* Mark */

            ShowCategoryScr4PicEdit(
                STR_PE_TITLE_COLOR_TXT,
                GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]),
                STR_PE_TITLE_PIXEL_TXT,
                gpPicEditPen->penPixel,
                penImageId,
                STR_GLOBAL_OK,
                IMG_GLOBAL_OK,
                STR_GLOBAL_CANCEL,
                IMG_GLOBAL_NO,
                IMG_PE_BACKGROUND,
                &gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
            break;
        default:

            ShowCategoryScr4PicEdit(
                STR_PE_TITLE_COLOR_TXT,
                GetPEColor(gPEColorRGB[gpPicEditPen->penColorIndex]),
                STR_PE_TITLE_PIXEL_TXT,
                gpPicEditPen->penPixel,
                penImageId,
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                IMG_PE_BACKGROUND,
                &gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);
            break;
    }
    InitPicEditKeyHandlers();
    ChangePicEditEditImageSoftkey();
    /* SetExitHandler (SCR_PE_EDIT_PIC, ExitScr4PicEditEditImage); */
}


/*****************************************************************************
 * FUNCTION
 *  ExitScr4PicEditEditImage
 * DESCRIPTION
 *  Exit function for EntryScr4PicEditEditImage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScr4PicEditEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(DisplayPECursor);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_move_offset(
        MMI_PEN_SKIP_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    h.scrnID = SCR_PE_EDIT_PIC;
    h.entryFuncPtr = EntryScr4PicEditEditImage;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
    enable_softkey_background();
    leave_full_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ChangePicEditEditImageSoftkey
 * DESCRIPTION
 *  Changes Softkey while image editing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ChangePicEditEditImageSoftkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (gPECurrentAction)
    {
        case SEL_PE_EDIT_OPT_RESIZE:    /* Resize */
        case SEL_PE_EDIT_OPT_MARK:      /* Mark */
            /*
             * Remove by Leo
             * ChangeLeftSoftkey(STR_GLOBAL_OK,IMG_GLOBAL_OK);
             * ChangeRightSoftkey(STR_GLOBAL_CANCEL,IMG_GLOBAL_NO);
             */
            /* Register function for left soft key */
            SetLeftSoftkeyFunction(PECommitLastAction, KEY_EVENT_UP);
            /* Register function for right soft key */
            SetRightSoftkeyFunction(PECancelLastAction, KEY_EVENT_UP);

            ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

            break;
        case SEL_PE_EDIT_OPT_SAVE_PIC:      /* Save */
        case SEL_PE_EDIT_OPT_SAVE_PIC_AS:   /* Save As */
        case SEL_PE_EDIT_OPT_PEN_SETTING:   /* Pen Setting */
        case SEL_PE_EDIT_OPT_FILL_PIC:      /* Fill Picture */
        case SEL_PE_EDIT_OPT_CUT:           /* Cut */
        case SEL_PE_EDIT_OPT_COPY:          /* Copy */
        case SEL_PE_EDIT_OPT_PASTE:         /* Paste */
        case SEL_PE_EDIT_OPT_UNDO:          /* Undo */
        case SEL_PE_EDIT_OPT_REDO:          /* Redo */
        case SEL_PE_EDIT_OPT_ZOOM:          /* Zoom */
        case SEL_PE_EDIT_OPT_FULL_SIZE:     /* FULL Size */
        case SEL_PE_EDIT_OPT_HELP:          /* Help */
        default:
            /* Register function for left soft key */
            SetLeftSoftkeyFunction(EntryScr4PicEditEditOpt, KEY_EVENT_UP);
            /* Register function for right soft key */
            SetRightSoftkeyFunction(GoBackHistory4PicEditEditImage, KEY_EVENT_UP);
            //              SetKeyHandler(GoBackHistory4PicEditEditImage, KEY_LEFT_ARROW,KEY_EVENT_DOWN);
            //              SetKeyHandler(EntryScr4PicEditEditOpt,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GoBackHistory4PicEditEditImage
 * DESCRIPTION
 *  Go back History function for Image editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void GoBackHistory4PicEditEditImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!IS_PE_ADD_IMAGE(gPEAttrib)) && (!IS_PE_IMAGE_CHANGED(gPEAttrib)))
    {
        GoBackHistory();
    }
    else
    {
        EntryScr4PicEditSaveImageConfirm();
    }
}


/*****************************************************************************
 * FUNCTION
 *  PECommitLastAction
 * DESCRIPTION
 *  Commits the last Action when pressed ok of image editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PECommitLastAction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE)
    {
        SavePEContext();
        SetPicEditPenBoundary();
        ResizePicEditImageDataBuff();
        if (IS_PE_ZOOM_IMAGE(gPEAttrib))
        {
            SetPicEditZoomWindow(FALSE);
        }
        SET_PE_IMAGE_EDIT(gPEAttrib);
        UNSET_PE_PEN_DOWN(gPEAttrib);
        UNSET_PE_MARK_IMAGE(gPEAttrib);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, PE_NOTIFYDURATION, SUCCESS_TONE);
        gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
    }
    else
    {
        /* Leo start 20050720, mark box display error */
        if (gpPicEditPen->penX <= gPicEditMark.minX)
        {
            /* gPicEditMark.maxX=gPicEditMark.minX; */
            /* Leo end 20050720 */
            gPicEditMark.minX = gpPicEditPen->penX;
        }
        else
        {
            gPicEditMark.maxX = gpPicEditPen->penX;
        }

        /* Leo start 20050720, mark box display error */
        if (gpPicEditPen->penY <= gPicEditMark.minY)
        {
            /* gPicEditMark.maxY=gPicEditMark.minY; */
            /* Leo end 20050720 */
            gPicEditMark.minY = gpPicEditPen->penY;
        }
        else
        {
            gPicEditMark.maxY = gpPicEditPen->penY;
        }

        UNSET_PE_IMAGE_EDIT(gPEAttrib);
        SET_PE_MARK_IMAGE(gPEAttrib);
        UNSET_PE_COPY_IMAGE(gPEAttrib);

        EntryScr4PicEditEditOpt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  PECancelLastAction
 * DESCRIPTION
 *  Cancels the last Action when pressed Cancel of image editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PECancelLastAction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gPECurrentAction == SEL_PE_EDIT_OPT_RESIZE)
    {
        SetCurrentImageParams();
    }
    gPECurrentAction = SEL_PE_EDIT_OPT_SAVE_PIC;
    UNSET_PE_PEN_DOWN(gPEAttrib);
    UNSET_PE_MARK_IMAGE(gPEAttrib);
    gui_push_clip();
    gui_set_clip(0, UI_device_height - MMI_button_bar_height - 1, UI_device_width - 1, UI_device_height - 1);

    /* 051605 Calvin modified */
    if (wgui_is_wallpaper_on_bottom())
    {
        gdi_draw_solid_rect(
            0,
            UI_device_height - MMI_button_bar_height,
            UI_device_width - 1,
            UI_device_height - 1,
            GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_image_draw(0, 0, (U8*) GetImage(IMG_PE_BACKGROUND));
    }
    /* Calvin end */

    gui_pop_clip();
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    /* Register function for left soft key */
    SetLeftSoftkeyFunction(EntryScr4PicEditEditOpt, KEY_EVENT_UP);
    /* Register function for right soft key */
    SetRightSoftkeyFunction(GoBackHistory4PicEditEditImage, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory4PicEditEditImage, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryScr4PicEditEditOpt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    ShowPicEditImageWindow(&gpPEFileBuff[-MAX_IMAGE_HEADER_LENGTH]);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  SetPicEditZoomWindow
 * DESCRIPTION
 *  Sets the parameters of zoom window
 * PARAMETERS
 *  bFlag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPicEditZoomWindow(BOOL bFlag)   /* flag FALSE to init gPicEditZoomWindow */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((gpPicEditPen->maxX - gpPicEditPen->minX) * gPEZoomFactor) > PE_SCR_SIZE_MAX)
    {
        if ((bFlag) || (gpPicEditPen->penX >= gPicEditZoomWindow.maxX) ||
            (gpPicEditPen->penX < gPicEditZoomWindow.minX))
        {
            gPicEditZoomWindow.minX = gpPicEditPen->penX - ((PE_SCR_SIZE_MAX / gPEZoomFactor) >> 1);
        }
        if (gPicEditZoomWindow.minX < gpPicEditPen->minX)
        {
            gPicEditZoomWindow.minX = gpPicEditPen->minX;
        }
        gPicEditZoomWindow.maxX = gPicEditZoomWindow.minX + PE_SCR_SIZE_MAX / gPEZoomFactor;
        if (gPicEditZoomWindow.maxX > gpPicEditPen->maxX)
        {
            gPicEditZoomWindow.maxX = gpPicEditPen->maxX;
            gPicEditZoomWindow.minX = gPicEditZoomWindow.maxX - PE_SCR_SIZE_MAX / gPEZoomFactor;
        }
    }
    else
    {
        gPicEditZoomWindow.minX = gpPicEditPen->minX;
        gPicEditZoomWindow.maxX = gpPicEditPen->maxX;
    }

    if (((gpPicEditPen->maxY - gpPicEditPen->minY) * gPEZoomFactor) > PE_SCR_SIZE_MAX)
    {
        if ((bFlag) || (gpPicEditPen->penY >= gPicEditZoomWindow.maxY) ||
            (gpPicEditPen->penY < gPicEditZoomWindow.minY))
        {
            gPicEditZoomWindow.minY = gpPicEditPen->penY - ((PE_SCR_SIZE_MAX / gPEZoomFactor) >> 1);
        }
        if (gPicEditZoomWindow.minY < gpPicEditPen->minY)
        {
            gPicEditZoomWindow.minY = gpPicEditPen->minY;
        }
        gPicEditZoomWindow.maxY = gPicEditZoomWindow.minY + PE_SCR_SIZE_MAX / gPEZoomFactor;
        if (gPicEditZoomWindow.maxY > gpPicEditPen->maxY)
        {
            gPicEditZoomWindow.maxY = gpPicEditPen->maxY;
            gPicEditZoomWindow.minY = gPicEditZoomWindow.maxY - PE_SCR_SIZE_MAX / gPEZoomFactor;
        }
    }
    else
    {
        gPicEditZoomWindow.minY = gpPicEditPen->minY;
        gPicEditZoomWindow.maxY = gpPicEditPen->maxY;
    }
}

/*
 * void SetPicEditZoomWindow(BOOL bFlag)//flag FALSE to init gPicEditZoomWindow
 * {
 * if (((gpPicEditPen->maxX-gpPicEditPen->minX)*gPEZoomFactor)>PE_SCR_SIZE_MAX)
 * {
 * if ((bFlag)||(gpPicEditPen->penX>=gPicEditZoomWindow.maxX))
 * gPicEditZoomWindow.minX=SET_WINDOW_MINX(gpPicEditPen->penX-PE_SCR_SIZE_MAX/2);
 * if (gPicEditZoomWindow.minX<gpPicEditPen->minX)
 * gPicEditZoomWindow.minX=gpPicEditPen->minX;
 * gPicEditZoomWindow.maxX=gPicEditZoomWindow.minX+PE_SCR_SIZE_MAX;
 * }
 * else
 * {
 * gPicEditZoomWindow.minX=SET_WINDOW_MINX((gpPicEditPen->maxX-gpPicEditPen->minX)*gPEZoomFactor);
 * gPicEditZoomWindow.maxX=gPicEditZoomWindow.minX+((gpPicEditPen->maxX-gpPicEditPen->minX)*gPEZoomFactor);
 * }
 * 
 * if (((gpPicEditPen->maxY-gpPicEditPen->minY)*gPEZoomFactor)>PE_SCR_SIZE_MAX)
 * {
 * if ((bFlag)||(gpPicEditPen->penY>=gPicEditZoomWindow.maxY))
 * gPicEditZoomWindow.minY=SET_WINDOW_MINY(gpPicEditPen->penY-PE_SCR_SIZE_MAX/2);
 * if (gPicEditZoomWindow.minY<gpPicEditPen->minY)
 * gPicEditZoomWindow.minY=gpPicEditPen->minY;
 * gPicEditZoomWindow.maxY=gPicEditZoomWindow.minY+PE_SCR_SIZE_MAX;
 * }
 * else
 * {
 * gPicEditZoomWindow.minY=SET_WINDOW_MINY((gpPicEditPen->maxY-gpPicEditPen->minY)*gPEZoomFactor);
 * gPicEditZoomWindow.maxY=gPicEditZoomWindow.minY+((gpPicEditPen->maxY-gpPicEditPen->minY)*gPEZoomFactor);
 * }
 * }
 */

#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 

