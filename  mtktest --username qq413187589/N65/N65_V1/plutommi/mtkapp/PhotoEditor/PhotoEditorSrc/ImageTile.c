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
 *  IamgeTile.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Image Tile Applcation Source of PhotoEditor
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
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_PHOTOEDITOR__

#include "nvram_data_items.h"
#include "gui.h"        /* Gui functions */
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "wgui.h"       /* for GetDateTime() */
#include "CommonScreens.h"      /* DisplayPopup() */
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif /* __DRM_SUPPORT__ */ 
#include "FileManagerDef.h"
#include "FileManagerGProt.h"   /* file path */
#include "FileMgr.h"
#include "FileMgrStruct.h"
#include "MainMenuDef.h"
#include "lcd_sw_rnd.h"
#include "med_api.h"    /* media task camera module */
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "PhotoEditor.h"
#include "PhotoEditorGProt.h"
#include "PhoEdtResDef.h"
#include "ImageTile.h"
#include "MMI_features_camera.h"
#include "CameraResDef.h"      /* for camrea error string */

#ifdef __PHOEDT_FEATURE_IMGTILE__

/***************************************************************************** 
* Define
*****************************************************************************/
#define IMGTILE_MAIN_CANVAS_COLOR            (GDI_COLOR_BLACK)
#define IMGTILE_CLIP_CANVAS_COLOR            (GDI_COLOR_WHITE)
#define IMGTILE_RECT_COLOR          (GDI_COLOR_RED)
#define IMGTILE_CLIP_SCREEN_SPACING       (5)
#define IMGTILE_CLIP_FRAME_INSIDE_COLOR      (GDI_COLOR_WHITE)
#define IMGTILE_CLIP_FRAME_OUTSIDE_COLOR  (GDI_COLOR_BLACK)
#define IMGTILE_CLIP_RECT_START_RATIO     (80)
#define IMGTILE_CLIP_RECT_MIN_RATIO       (30)

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern BOOL r2lMMIFlag;
extern fmgr_context_struct *fmgr_p;

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
extern pBOOL mmi_usb_check_path_exported(S8 *path);

/*****************************************************************************
* Local Vairable                                                           
*****************************************************************************/

static imgtile_cntx_struct g_imgtile_cntx;

static S32 no_of_tiles;
static S32 order_of_screen = 0;
static S32 curr_hilighted_index = 0;
static U16 image_icon[MAX_TILE];
static S32 box_offset_x = 0;
static S32 box_offset_y = 0;
static S32 box_width = 0;
static S32 box_height = 0;

/* for tile position */
static mmi_imgtile_tile_t g_imgtile_rect = {
    #ifdef __MMI_IMGTILE_TILE_2__
        #ifdef __MMI_IMGTILE_TILE_2_HORI__
        {{0,0},                         /* tile 1 */
        {LCD_WIDTH/2, 0}},              /* 2nd */
            
        {LCD_WIDTH/2, LCD_HEIGHT}       /* tile width/height */      
        #else
        {{0,0},                         /* tile 1 */
        {0, LCD_HEIGHT/2}},             /* 2nd */
            
        {LCD_WIDTH, LCD_HEIGHT/2}       /* tile width/height */

        #endif
    #endif
};

#ifdef __MMI_TOUCH_SCREEN__
static imgtile_touch_screen_context_struct g_imgtile_touch_screen_cntx;
#endif 

/*****************************************************************************
* Local Function                                                           
*****************************************************************************/
/* app related */
static void mmi_imgtile_hilight_app(void);
static void mmi_imgtile_entry_app_screen(void);

static void mmi_imgtile_lsk_press(void);
static void mmi_imgtile_lsk_release(void);
static void mmi_imgtile_rsk_press(void);
static void mmi_imgtile_rsk_release(void);
static void mmi_imgtile_end_key_press(void);
static void mmi_imgtile_show_press_release_softkey(void);

static U8 mmi_imgtile_del_screen_id_hdlr(void *);
static BOOL mmi_imgtile_load_cache_image(PU8);
static BOOL mmi_imgtile_write_cache_image(PU8);
static void mmi_imgtile_main_draw_osd(void);
static void mmi_imgtile_draw_softkey(PS8, PS8, BOOL);
static void mmi_imgtile_entry_select_file(void);
void mmi_imgtile_fmgr_select_result_callback(void *, int);
static void mmi_imgtile_entry_view_screen(void);
static void mmi_imgtile_entry_clip_option_screen(void);
static void mmi_imgtile_hilight_tile_clip(void);
static void mmi_imgtile_hilight_auto_resize(void);
static void mmi_imgtile_entry_clip_screen(void);
static void mmi_imgtile_exit_clip_screen(void);

static void mmi_imgtile_clip_draw_osd(void);
static void mmi_imgtile_clip_move_clip_rect_cyclic(void);

static void mmi_imgtile_clip_clip_image(void);
static void mmi_imgtile_clip_up_arrow_press(void);
static void mmi_imgtile_clip_down_arrow_press(void);
static void mmi_imgtile_clip_left_arrow_press(void);
static void mmi_imgtile_clip_right_arrow_press(void);
static void mmi_imgtile_clip_up_arrow_release(void);
static void mmi_imgtile_clip_down_arrow_release(void);
static void mmi_imgtile_clip_left_arrow_release(void);
static void mmi_imgtile_clip_right_arrow_release(void);
static void mmi_imgtile_clip_scale_up_press(void);
static void mmi_imgtile_clip_scale_up_release(void);
static void mmi_imgtile_clip_scale_down_press(void);
static void mmi_imgtile_clip_scale_down_release(void);

static void mmi_imgtile_entry_auto_resize(void);
static void mmi_imgtile_entry_option_screen(void);
static void mmi_imgtile_hilight_select(void);
static void mmi_imgtile_hilight_save_as(void);
static void mmi_imgtile_entry_save_as(void);
static void mmi_imgtile_exit_main_confirm(void);
static void mmi_imgtile_exit_main_confirm_yes(void);

static void mmi_imgtile_entry_editor_filename_screen(void);
static void mmi_imgtile_entry_editor_filename_internal(void);
static void mmi_imgtile_entry_editor_option_screen(void);
static void mmi_imgtile_back_from_editor_screen(void);
static void mmi_imgtile_return_to_editor_screen(void);
static void mmi_imgtile_hilight_editor_done(void);
static void mmi_imgtile_hilight_editor_cancel(void);
static void mmi_imgtile_hilight_editor_input(void);

static void mmi_imgtile_cancel_save_file(void);
static void mmi_imgtile_save_file(void);

static void redraw_tile_screen(void);

static void mmi_imgtile_left_arrow(void);
static void mmi_imgtile_right_arrow(void);
static void mmi_imgtile_up_arrow(void);
static void mmi_imgtile_down_arrow(void);

static void mmi_imgtile_hilight_tile_2(void);
static void mmi_imgtile_entry_tile2_screen(void);
static void mmi_imgtile_exit_tile2_screen(void);

static void mmi_imgtile_hilight_tile_4(void);
static void mmi_imgtile_entry_tile4_screen(void);
static void mmi_imgtile_exit_tile4_screen(void);

static void mmi_imgtile_hilight_tile_9(void);
static void mmi_imgtile_entry_tile9_screen(void);
static void mmi_imgtile_exit_tile9_screen(void);

static void mmi_imgtile_set_highlighter(void);
static void mmi_imgtile_entry_select_path(void);

static void mmi_imgtile_flip_edit_hor_button_press(void);
static void mmi_imgtile_flip_edit_hor_button_release(void);
static void mmi_imgtile_flip_edit_horizontal_flip(void);


static void mmi_imgtile_Cat222_result_callback(GDI_RESULT result);

static void mmi_imgtile_create_layers(void);
static S32 mmi_imgtile_draw_img_auto_resize(PS8 p_fname, S32 x1, S32 y1, S32 x2, S32 y2);


/* touch screen */
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_imgtile_set_active_tile(S32 i, S32 tile_style);
void mmi_imgtile_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_imgtile_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_imgtile_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_down_hdlr(mmi_pen_point_struct pos);
MMI_BOOL mmi_imgtile_clip_pen_up_hdlr(mmi_pen_point_struct pos);
MMI_BOOL mmi_imgtile_clip_pen_move_hdlr(mmi_pen_point_struct pos);
MMI_BOOL mmi_imgtile_clip_pen_repeat_hdlr(mmi_pen_point_struct pos);
MMI_BOOL mmi_imgtile_clip_pen_long_tap_hdlr(mmi_pen_point_struct pos);
MMI_BOOL mmi_imgtile_clip_pen_abort_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_init_app
 * DESCRIPTION
 *  init image tile applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgtile_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_IMGTILE_APP, mmi_imgtile_hilight_app);
    SetHiliteHandler(MENU_ID_IMGTILE_TILE_2, mmi_imgtile_hilight_tile_2);
    SetHiliteHandler(MENU_ID_IMGTILE_TILE_4, mmi_imgtile_hilight_tile_4);
    SetHiliteHandler(MENU_ID_IMGTILE_TILE_9, mmi_imgtile_hilight_tile_9);
    SetHiliteHandler(MENU_ID_IMGTILE_CLIP_IMAGE, mmi_imgtile_hilight_tile_clip);
    SetHiliteHandler(MENU_ID_IMGTILE_AUTO_RESIZE, mmi_imgtile_hilight_auto_resize);
    SetHiliteHandler(MENU_ID_IMGTILE_SELECT, mmi_imgtile_hilight_select);
    SetHiliteHandler(MENU_ID_IMGTILE_SAVE_AS, mmi_imgtile_hilight_save_as);
    SetHiliteHandler(MENU_ID_IMGTILE_EDITOR_DONE, mmi_imgtile_hilight_editor_done);
    SetHiliteHandler(MENU_ID_IMGTILE_EDITOR_CANCEL, mmi_imgtile_hilight_editor_cancel);
    SetHiliteHandler(MENU_ID_IMGTILE_EDITOR_INPUT, mmi_imgtile_hilight_editor_input);

    g_imgtile_cntx.is_edited = FALSE;
    g_imgtile_cntx.is_lsk_pressed = FALSE;
    g_imgtile_cntx.is_rsk_pressed = FALSE;
    g_imgtile_cntx.origin_image_buf = NULL;

    g_imgtile_cntx.text_color = *current_MMI_theme->title_text_color;
    g_imgtile_cntx.text_border_color = *current_MMI_theme->title_text_border_color;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_app
 * DESCRIPTION
 *  init image tile applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_app_screen
 * DESCRIPTION
 *  entry image tile applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *guiBuffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.is_clip[i] = 0;
        g_imgtile_cntx.is_auto_resize[i] = 0;
    }
    g_imgtile_cntx.is_edited = 0;
    g_imgtile_cntx.save_file = 0;
    g_imgtile_cntx.is_back_from_clip = FALSE;

    EntryNewScreen(SCR_ID_IMGTILE_APP, NULL, mmi_imgtile_entry_app_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_APP);
    num_item = GetNumOfChild(MENU_ID_IMGTILE_APP);

    GetSequenceStringIds(MENU_ID_IMGTILE_APP, item_list);
    GetSequenceImageIds(MENU_ID_IMGTILE_APP, item_icons);
    SetParentHandler(MENU_ID_IMGTILE_APP);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_IMGTILE_APP, popup_list);

    ShowCategory52Screen(
        STR_ID_IMGTILE_APP,
        GetRootTitleIcon(MENU_ID_IMGTILE_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_tile_2
 * DESCRIPTION
 *  init tile 2 application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_tile_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_tile2_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_entry_tile2_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}

/***************************************************************************** 
*
* Main Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_tile2_screen
 * DESCRIPTION
 *  enter main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_tile2_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 buf_ptr;
    U8 *gui_buffer;
    GDI_RESULT result;
    S32 offset_x;
    S32 offset_y;
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_MAIN, mmi_imgtile_exit_tile2_screen, mmi_imgtile_entry_tile2_screen, NULL);
    no_of_tiles = 2;
    order_of_screen = 1;

    for (i = 0; i < no_of_tiles; i++)
    {
        image_icon[i] = (U16) (IMG_ID_IMGTILE_2TILE_IMAGE_1 + i);
    }


    gui_set_font(&MMI_medium_font);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_MAIN);

    /* set del screen handler */
    SetDelScrnIDCallbackHandler(SCR_ID_IMGTILE_MAIN, mmi_imgtile_del_screen_id_hdlr);

    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        g_imgtile_cntx.origin_image_buf = (PU8) g_phoedt_original_buffer;
    }

    /* default set to do not free memory, only end key and clam-close or self go back will free */
    g_imgtile_cntx.is_free_memory = FALSE;

    /* entry full screen */
    entry_full_screen();

    /* register key hdlr */
#ifdef NO_LSK
    SetKeyHandler(mmi_imgtile_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);//ghw222
    SetKeyHandler(mmi_imgtile_lsk_release, KEY_SEND1, KEY_EVENT_UP);

#else
    SetKeyHandler(mmi_imgtile_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif
    SetKeyHandler(mmi_imgtile_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_rsk_release, KEY_RSK, KEY_EVENT_UP);

#ifdef __MMI_IMGTILE_TILE_2_HORI__
    SetKeyHandler(mmi_imgtile_right_arrow, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_left_arrow, KEY_LEFT_ARROW, KEY_EVENT_UP);   
#else
    SetKeyHandler(mmi_imgtile_up_arrow, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_UP);
#endif /* __MMI_IMGTILE_TILE_2_HORI__ */
#ifdef NO_LSK
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_LSK, KEY_EVENT_DOWN);//ghw222
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_LSK, KEY_EVENT_UP);

#else
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_ENTER, KEY_EVENT_UP);

#endif

    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_2, KEY_EVENT_UP);
    
    /* get end key hdlr and hook ours */
    g_imgtile_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_imgtile_end_key_press, KEY_END, KEY_EVENT_DOWN);

    /***************************************************************************** 
    * Layers
    *****************************************************************************/
    gdi_layer_multi_layer_enable();
    /* create layers */
    mmi_imgtile_create_layers();

    /* lock frame for drawing */
    gdi_layer_lock_frame_buffer();

    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        /* get file name from NVRAM */
        mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);

        gdi_layer_clear_background(IMGTILE_MAIN_CANVAS_COLOR);
        gdi_layer_reset_clip();

        for (i = 0; i < no_of_tiles; i++)
        {
            if (g_imgtile_cntx.is_auto_resize[i] || g_imgtile_cntx.is_clip[i])
            {
                g_imgtile_cntx.is_edited = TRUE;
                break;
            }
        }

        if (g_imgtile_cntx.is_edited)
        {
            for (i = 0; i < no_of_tiles; i++)
            {
                if (g_imgtile_cntx.image_array[i])
                {
                    /* load buffer image first */
                    gdi_layer_get_buffer_ptr(&buf_ptr);
                    mmi_imgtile_load_cache_image(buf_ptr);
                    /* draw newly updated image */
                    if (g_imgtile_cntx.is_auto_resize[i])
                    {
                        ret = mmi_imgtile_draw_img_auto_resize(
                                (PS8)buf_filename,
                                box_offset_x,
                                box_offset_y,
                                box_offset_x + box_width,
                                box_offset_y + box_height);
                        if (ret < 0)
                        {
                            gdi_layer_unlock_frame_buffer();
                            DisplayPopup(
                                (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                                IMG_GLOBAL_WARNING,
                                1,
                                PHOEDT_NOTIFY_DURATION,
                                WARNING_TONE);
                            g_imgtile_cntx.is_auto_resize[i] = g_imgtile_cntx.is_clip[i] = FALSE;
                            g_imgtile_cntx.is_back_from_clip = TRUE;
                            return;
                        }
                        
                    }
                    else if (g_imgtile_cntx.is_clip[i] == TRUE)
                    {
                        offset_x = g_imgtile_rect.t2_pos[i].x;
                        offset_y = g_imgtile_rect.t2_pos[i].y;
                        gdi_draw_solid_rect(
                            box_offset_x,
                            box_offset_y,
                            box_width -1,
                            box_height -1 ,
                            IMGTILE_MAIN_CANVAS_COLOR);
                        gdi_layer_push_clip();
                        gdi_layer_set_clip(
                            box_offset_x,
                            box_offset_y,
                            box_offset_x+box_width -1,
                            box_offset_y+box_height -1);
                        result = gdi_image_jpeg_draw_resized_file_with_output_clipping(
                                    offset_x - g_imgtile_cntx.clipx1[i],
                                    offset_y - g_imgtile_cntx.clipy1[i],
                                    g_imgtile_cntx.res_width[i],
                                    g_imgtile_cntx.res_height[i],
                                    g_imgtile_cntx.clipx1[i],
                                    g_imgtile_cntx.clipy1[i],
                                    g_imgtile_cntx.clipx2[i],
                                    g_imgtile_cntx.clipy2[i],
                                    buf_filename);
                        gdi_layer_pop_clip();
                        /* error handling */
                        if (result < 0)
                        {
                            mmi_imgtile_load_cache_image(buf_ptr);
                            gdi_layer_unlock_frame_buffer();                            
                            if (result == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_IMGTILE_NOTIFY_IMAGE_TOO_WIDE),
                                    IMG_GLOBAL_WARNING,
                                    1,
                                    PHOEDT_NOTIFY_DURATION,
                                    WARNING_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                                    IMG_GLOBAL_WARNING,
                                    1,
                                    PHOEDT_NOTIFY_DURATION,
                                    WARNING_TONE);                                
                            }
                            g_imgtile_cntx.image_array[i] = FALSE;
                            g_imgtile_cntx.is_back_from_clip = FALSE;
                            
                            return;                   
                        }
                        g_imgtile_cntx.resized_image_offset_x = offset_x;
                        g_imgtile_cntx.resized_image_offset_y = offset_y;
                        g_imgtile_cntx.resized_image_width = g_imgtile_cntx.clip_size_width;
                        g_imgtile_cntx.resized_image_height = g_imgtile_cntx.clip_size_height;
                    }
                }
            }
        }
        else
        {
            curr_hilighted_index = 0;
        }

        /* dump original image to cache file */
        gdi_layer_get_buffer_ptr(&buf_ptr);

        if (mmi_imgtile_write_cache_image(buf_ptr) == FALSE)
        {
            /* TODO: error handing */
        }
    }
    else
    {
        /* back from edited screens or interrupt */
        gdi_layer_get_buffer_ptr(&buf_ptr);
        mmi_imgtile_load_cache_image(buf_ptr);
    }

    /* draw main's osd content */
    mmi_imgtile_main_draw_osd();

    /* set highlighter (hilight rect) */
    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        mmi_imgtile_set_highlighter();
    }

    for (i = 0; i < no_of_tiles; i++)
    {
        if ( !g_imgtile_cntx.is_auto_resize[i] && !g_imgtile_cntx.is_clip[i])
        {
            gdi_image_draw_id(g_imgtile_rect.t2_pos[i].x, g_imgtile_rect.t2_pos[i].y, image_icon[i]);
        }
    }
    gdi_draw_rect(box_offset_x, box_offset_y, box_width + box_offset_x - 1, box_height + box_offset_y - 1, IMGTILE_RECT_COLOR);

    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.image_array[i] = FALSE;
    }
    g_imgtile_cntx.image_array[curr_hilighted_index] = TRUE;
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    g_imgtile_cntx.is_back_from_clip = FALSE;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_imgtile_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_imgtile_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_imgtile_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_tile_screen_general
 * DESCRIPTION
 *  general exit tile screen funcations  (for tile2/4/9)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_tile_screen_general(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free memory */
    if (g_imgtile_cntx.is_free_memory)
    {
        g_imgtile_cntx.origin_image_buf = NULL;
    }

    /* merge layer to base */
#ifdef __MMI_PHOEDT_USE_FAKE_BASELAYER__
    gdi_layer_pop_and_restore_active();
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_free(g_imgtile_cntx.base_layer_handle);           /* free base' layer */
    gdi_layer_get_active(&g_imgtile_cntx.base_layer_handle);    
#else   /* __MMI_PHOEDT_USE_FAKE_BASELAYER__ */
    gdi_layer_flatten_previous_to_base();
#endif  /* __MMI_PHOEDT_USE_FAKE_BASELAYER__ */

    /* free layer */
    gdi_layer_free(g_imgtile_cntx.osd_layer_handle);
    gdi_layer_set_blt_layer(g_imgtile_cntx.base_layer_handle, 0, 0, 0);
    gdi_layer_multi_layer_disable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_tile2_screen
 * DESCRIPTION
 *  exit main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_tile2_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgtile_exit_tile_screen_general();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_lsk_press
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_lsk_pressed = TRUE;
    mmi_imgtile_show_press_release_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_show_press_release_softkey
 * DESCRIPTION
 *  draw and show softkey based on different screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_show_press_release_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgtile_main_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_lsk_release
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_lsk_pressed = FALSE;
    mmi_imgtile_show_press_release_softkey();
    if (g_imgtile_cntx.is_edited == FALSE)
    {
        mmi_imgtile_entry_select_file();
    }
    else
    {
        mmi_imgtile_entry_option_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_rsk_press
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_rsk_pressed = TRUE;
    mmi_imgtile_show_press_release_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_rsk_release
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_rsk_pressed = FALSE;
    mmi_imgtile_show_press_release_softkey();
    if (g_imgtile_cntx.is_edited)
    {
        mmi_imgtile_exit_main_confirm();
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_end_key_press
 * DESCRIPTION
 *  press end key hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_end_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * set this flag true, will free memory when exit imgtile main screen
     * (1) User directly press end key.
     * (2) Clam close. Clam close will also call this function 
     */
    g_imgtile_cntx.is_free_memory = TRUE;

    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.is_auto_resize[i] = FALSE;
        g_imgtile_cntx.is_clip[i] = FALSE;
    }
    g_imgtile_cntx.is_edited = FALSE;

    /* call standand end-key handler */
    g_imgtile_cntx.end_key_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_del_screen_id_hdlr
 * DESCRIPTION
 *  callback function when someone delete this screen's id
 * PARAMETERS
 *  ptr     [IN]     not used now.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_imgtile_del_screen_id_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.origin_image_buf = NULL;
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_write_cache_image
 * DESCRIPTION
 *  write buffer to cache file
 * PARAMETERS
 *  buf_ptr     [IN]        Buffer pointer
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_imgtile_write_cache_image(PU8 buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_imgtile_cntx.origin_image_buf, buf_ptr, IMGTILE_FRAME_BUFFER_SIZE);
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_load_cache_image
 * DESCRIPTION
 *  read buffer from cache file
 * PARAMETERS
 *  buf_ptr     [IN]        Buffer pointer
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_imgtile_load_cache_image(PU8 buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(buf_ptr, g_imgtile_cntx.origin_image_buf, IMGTILE_FRAME_BUFFER_SIZE);
    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_main_draw_osd
 * DESCRIPTION
 *  draw flip screen osd layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_main_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgtile_cntx.osd_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    /* init softkey */
    if (g_imgtile_cntx.is_edited)
    {
        mmi_imgtile_draw_softkey((PS8) get_string(STR_GLOBAL_OPTIONS), (PS8) get_string(STR_ID_IMGTILE_EXIT), FALSE);
    }
    else
    {
        mmi_imgtile_draw_softkey((PS8) get_string(STR_GLOBAL_SELECT), (PS8) get_string(STR_GLOBAL_BACK), FALSE);
    }

    /* draw icon */
    /* spacing = 3; */

    gdi_image_get_dimension_id(IMG_ID_IMGTILE_FLIP_HOR_ICON, &image_width, &image_height);

    offset_x = ((UI_device_width - image_width) >> 1);
    offset_y = UI_device_height - image_height;

    /* horizontal flip */
    /* offset_x += image_width+spacing; */
    if (g_imgtile_cntx.is_flip_hor_pressed)
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_IMGTILE_FLIP_HOR_ICON_SEL);
    }
    else
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_IMGTILE_FLIP_HOR_ICON);
    }

#ifdef __MMI_TOUCH_SCREEN__
    g_imgtile_touch_screen_cntx.flip_hor.pos_x = offset_x;
    g_imgtile_touch_screen_cntx.flip_hor.pos_y = offset_y;
    g_imgtile_touch_screen_cntx.flip_hor.width = image_width;
    g_imgtile_touch_screen_cntx.flip_hor.height = image_height;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_draw_softkey
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  lsk_str         [IN]        Lsk string
 *  rsk_str         [IN]        Rsk string
 *  is_clear_bg     [IN]        Clear background flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_draw_softkey(PS8 lsk_str, PS8 rsk_str, BOOL is_clear_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    S32 x1;
    S32 x2;
    S32 y1;
    S32 y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has softkey need update */
    if ((lsk_str == NULL) && (rsk_str == NULL))
    {
        return;
    }
    gdi_layer_push_clip();
    gdi_layer_push_text_clip();
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font(&MMI_medium_font);

    x1 = 0;
    y1 = UI_device_height - MMI_button_bar_height;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;

    /* clear softkey background */
    if (is_clear_bg)
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    }

    /* draw lsk */
    if (lsk_str != NULL)
    {
    #if 1
        wgui_softkey_get_offset((UI_string_type) lsk_str, &offset_x, &offset_y, MMI_LEFT_SOFTKEY);
        gui_measure_string((UI_string_type) lsk_str, &str_width, &str_height);
    #else        
/* under construction !*/
/* under construction !*/
    #endif

        if (g_imgtile_cntx.is_lsk_pressed)
        {
            offset_x++;
            offset_y++;
        }

        gui_move_text_cursor(offset_x, offset_y);

        gui_set_text_color(g_imgtile_cntx.text_color);
        gui_set_text_border_color(g_imgtile_cntx.text_border_color);
        gui_print_bordered_text((UI_string_type) lsk_str);

    #ifdef __MMI_TOUCH_SCREEN__
        g_imgtile_touch_screen_cntx.lsk.pos_x = offset_x;
        g_imgtile_touch_screen_cntx.lsk.pos_y = offset_y;
        g_imgtile_touch_screen_cntx.lsk.width = str_width;
        g_imgtile_touch_screen_cntx.lsk.height = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 

    }
#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_imgtile_touch_screen_cntx.lsk.pos_x = 0;
        g_imgtile_touch_screen_cntx.lsk.pos_y = 0;
        g_imgtile_touch_screen_cntx.lsk.width = 0;
        g_imgtile_touch_screen_cntx.lsk.height = 0;

    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* draw rsk */
    if (rsk_str != NULL)
    {
    #if 1
        wgui_softkey_get_offset((UI_string_type) rsk_str, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
        gui_measure_string((UI_string_type) rsk_str, &str_width, &str_height);
    #else        
/* under construction !*/
/* under construction !*/
    #endif
        if (g_imgtile_cntx.is_rsk_pressed)
        {
            offset_x++;
            offset_y++;
        }

        gui_move_text_cursor(offset_x, offset_y);

        gui_set_text_color(g_imgtile_cntx.text_color);
        gui_set_text_border_color(g_imgtile_cntx.text_border_color);
        gui_print_bordered_text((UI_string_type) rsk_str);

    #ifdef __MMI_TOUCH_SCREEN__
        g_imgtile_touch_screen_cntx.rsk.pos_x = offset_x;
        g_imgtile_touch_screen_cntx.rsk.pos_y = offset_y;
        g_imgtile_touch_screen_cntx.rsk.width = str_width;
        g_imgtile_touch_screen_cntx.rsk.height = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 

    }
#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_imgtile_touch_screen_cntx.rsk.pos_x = 0;
        g_imgtile_touch_screen_cntx.rsk.pos_y = 0;
        g_imgtile_touch_screen_cntx.rsk.width = 0;
        g_imgtile_touch_screen_cntx.rsk.height = 0;

    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gdi_layer_pop_clip();
    gdi_layer_pop_text_clip();
}

/***************************************************************************** 
*
* File Selection Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_select_file
 * DESCRIPTION
 *  entry image tile selection path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_select_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    FMGR_FILTER_INIT(&filter);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(
        APP_PHOEDT,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (PS8) (S8*) L"root",
        (PsExtFuncPtr) mmi_imgtile_fmgr_select_result_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_fmgr_select_result_callback
 * DESCRIPTION
 *  select file result callback function
 * PARAMETERS
 *  filepath        [IN]        Select file path
 *  is_shot         [IN]        Is short filename
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgtile_fmgr_select_result_callback(void *filepath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    FS_HANDLE fs_handle;
    U32 free_space;
    S8 drv_name[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath == NULL)
    {
        g_imgtile_cntx.save_file = FALSE;
        /* cencel file selection - delete up to one level before file selection */
        DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);
        GoBackHistory();
    }
    else
    {

    #ifdef __DRM_SUPPORT__
        if (DRM_METHOD_NONE != DRM_get_object_method(0, (PU16)filepath))
        {
            DisplayPopup(
                (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 

        /* save file path to nvram */
        mmi_fmgr_util_store_filepath(filepath, FMGR_PATH_ID_PHOTO_EDITOR);

        memset(drv_name, 0, sizeof(drv_name));
        mmi_ucs2ncpy((PS8) drv_name, (PS8) filepath, 3);

        fs_handle = FS_GetDiskInfo((PU16) drv_name, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

        if (fs_handle >= 0)
        {
            /* in byte */
            free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

            /* free space not enoguth, display popup */
            if (free_space < IMGTILE_SAVE_PREDICT_SIZE)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_IMGTILE_NOTIFY_FREE_SPACE_NOT_ENOUGH),
                    IMG_GLOBAL_WARNING,
                    1,
                    PHOEDT_NOTIFY_DURATION,
                    WARNING_TONE);

                /* delete up to one level before file selection */
                DeleteUptoScrID(SCR_ID_IMGTILE_APP);
                return;
            }

            /* check memory card lock */
            if (disk_info.WriteProtect)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_IMGTILE_NOTIFY_UNLOCK_MEMORY_CARD),
                    IMG_GLOBAL_WARNING,
                    1,
                    PHOEDT_NOTIFY_DURATION,
                    WARNING_TONE);

                /* delete up to one level before file selection */
                DeleteUptoScrID(SCR_ID_IMGTILE_APP);
                return;
            }

            fmgr_reset_app_select(); /* use select repeat, reset by app it self */
            
            if (g_imgtile_cntx.save_file == TRUE)
            {
                mmi_imgtile_entry_editor_filename_screen();
            }
            else
                /* if no error - enter view screen */
            {
                mmi_imgtile_entry_view_screen();
            }

        }
        else
        {
            /* file system error */
            DisplayPopup(
                (PU8) GetString(FMGR_FS_INVALID_FILE_SYSTEM_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);

            /* delete up to one level before file selection */
            DeleteUptoScrID(SCR_ID_IMGTILE_APP);
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_Cat222_result_callback
 * DESCRIPTION
 *  get the image decode result from category 222 screen, if success, enable
 *  the access of image clipping functions.
 * PARAMETERS
 *  result      [IN]        Image decode result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_Cat222_result_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        /* show LSK, and set it to OK */
        gdi_lcd_get_dimension(&g_imgtile_cntx.clip_size_width, &g_imgtile_cntx.clip_size_height);
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_imgtile_entry_clip_option_screen, KEY_EVENT_UP);
    }
}

/***************************************************************************** 
*
* View Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_view_screen
 * DESCRIPTION
 *  enter view screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    FMGR_FILE_INFO_STRUCT file_info;
    U8 *gui_buffer;
    U16 img_type;
    FS_HANDLE hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_VIEW, NULL, mmi_imgtile_entry_view_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_VIEW);
    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);

    /* check if file still exists *MAUI_00453334 */
    hfile = FS_Open((PU16) buf_filename, FS_READ_ONLY);
    if (hfile < FS_NO_ERROR)
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        DisplayPopup(
            (PU8) GetString((U16)GetFileSystemErrorString(hfile)),
            IMG_GLOBAL_ERROR,
            1,
            PHOEDT_NOTIFY_DURATION,
            ERROR_TONE);
        DeleteNHistory(1);
        return;
    }
    FS_Close(hfile);

    /* block non-JPEG files */
    img_type = gdi_image_get_type_from_file((PS8) buf_filename);
    if (GDI_IMAGE_TYPE_JPG_FILE == img_type)
    {
        ShowCategory222Screen(
            0,                                              /* title */
            GetRootTitleIcon(MENU_ID_IMGTILE_APP),                                              /* title icon */
            0,
            0,                                              /* left soft key */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,                                /* right soft key */
            IMGTILE_CLIP_CANVAS_COLOR,                      /* content BG color */
            (PS8) NULL,                                     /* button bar string */
            (PS8) buf_filename /* fmgr_p->file_path */ ,    /* image file name */
            file_info.is_short,                             /* is_short */
            mmi_imgtile_Cat222_result_callback,
            GDI_IMAGE_SRC_FROM_FILE);            /* decode result callback */
    }
    else
    {
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        DisplayPopup(
            (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
            IMG_GLOBAL_WARNING,
            1,
            PHOEDT_NOTIFY_DURATION,
            WARNING_TONE);
        DeleteNHistory(1);
        return;
    }
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_clip_option_screen
 * DESCRIPTION
 *  entry image tile applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_clip_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *guiBuffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_CLIP_OPTION, NULL, mmi_imgtile_entry_clip_option_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_CLIP_OPTION);
    num_item = GetNumOfChild(MENU_ID_IMGTILE_CLIP_OPTION);

    GetSequenceStringIds(MENU_ID_IMGTILE_CLIP_OPTION, item_list);
    GetSequenceImageIds(MENU_ID_IMGTILE_CLIP_OPTION, item_icons);
    SetParentHandler(MENU_ID_IMGTILE_CLIP_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_IMGTILE_CLIP_OPTION, popup_list);

    ShowCategory52Screen(
        STR_ID_IMGTILE_CLIP,
        GetRootTitleIcon(MENU_ID_IMGTILE_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_tile_clip
 * DESCRIPTION
 *  init tile clip application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_tile_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_clip_screen, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_imgtile_entry_clip_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_clip_screen
 * DESCRIPTION
 *  enter clip screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_clip_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    S32 display_wnd_width;
    S32 display_wnd_height;
    U32 scale_ratio;
    GDI_RESULT result;
    U8 *gui_buffer;
    U16 img_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init variable */
    g_imgtile_cntx.is_up_arrow_pressed = FALSE;
    g_imgtile_cntx.is_down_arrow_pressed = FALSE;
    g_imgtile_cntx.is_left_arrow_pressed = FALSE;
    g_imgtile_cntx.is_right_arrow_pressed = FALSE;
    g_imgtile_cntx.is_scale_up_pressed = FALSE;
    g_imgtile_cntx.is_scale_down_pressed = FALSE;

    EntryNewScreen(SCR_ID_IMGTILE_CLIP, mmi_imgtile_exit_clip_screen, mmi_imgtile_entry_clip_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_CLIP);

	if (gui_buffer == NULL)
	{
        g_imgtile_cntx.scale_ratio = IMGTILE_CLIP_RECT_START_RATIO;
	}

    gdi_layer_lock_frame_buffer();
    ShowCategory221Screen(
        STR_ID_IMGTILE_CLIP_IMAGE,
        GetRootTitleIcon(MENU_ID_IMGTILE_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMGTILE_CLIP_CANVAS_COLOR,
        NULL);

    gdi_lcd_get_dimension(&g_imgtile_cntx.clip_size_width, &g_imgtile_cntx.clip_size_height);

    if (no_of_tiles == 2)
    {
        g_imgtile_cntx.clip_size_width  = g_imgtile_rect.t2_size.w;
        g_imgtile_cntx.clip_size_height  = g_imgtile_rect.t2_size.h;
    }
    else if (no_of_tiles == 4)
    {
        g_imgtile_cntx.clip_size_height = g_imgtile_cntx.clip_size_height / 2;
        g_imgtile_cntx.clip_size_width = g_imgtile_cntx.clip_size_width / 2;
    }
    else
    {
        g_imgtile_cntx.clip_size_width = box_width - box_offset_x + 1;
        g_imgtile_cntx.clip_size_height = box_height - box_offset_y + 1;
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imgtile_clip_clip_image, KEY_EVENT_UP);

    SetKeyHandler(mmi_imgtile_clip_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_up_arrow_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_down_arrow_press, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_left_arrow_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_right_arrow_press, KEY_6, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_imgtile_clip_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_up_arrow_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_down_arrow_release, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_left_arrow_release, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_right_arrow_release, KEY_6, KEY_EVENT_UP);

    SetKeyHandler(mmi_imgtile_clip_scale_up_press, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_scale_up_release, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_clip_scale_down_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_clip_scale_down_release, KEY_POUND, KEY_EVENT_UP);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(mmi_imgtile_clip_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(mmi_imgtile_clip_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(mmi_imgtile_clip_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(mmi_imgtile_clip_pen_long_tap_hdlr, MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(mmi_imgtile_clip_pen_repeat_hdlr, MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(mmi_imgtile_clip_pen_abort_hdlr, MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 

   /***************************************************************************** 
   * Layers
   *****************************************************************************/
    gdi_layer_multi_layer_enable();

    /* base layer */
    gdi_layer_get_active(&g_imgtile_cntx.base_layer_handle);

    /* clip rect layer */
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &g_imgtile_cntx.osd_layer_handle);
    gdi_layer_push_and_set_active(g_imgtile_cntx.osd_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_imgtile_cntx.base_layer_handle, g_imgtile_cntx.osd_layer_handle, 0, 0);

    /* get file name from NVRAM */
    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);
    img_type = gdi_image_get_type_from_file(buf_filename);
    /* draw image */
    result = gdi_image_get_dimension_file(
                (PS8) buf_filename,
                &g_imgtile_cntx.image_width,
                &g_imgtile_cntx.image_height);
    if ((result < 0) || (GDI_IMAGE_TYPE_JPG_FILE != img_type) || (g_imgtile_cntx.image_width <= 0) ||
        (g_imgtile_cntx.image_height <= 0))
    {
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        DisplayPopup(
            (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
            IMG_GLOBAL_WARNING,
            1,
            PHOEDT_NOTIFY_DURATION,
            WARNING_TONE);
        DeleteNHistory(1);
        return;
    }

    /* block images which is too small. */
    if ((g_imgtile_cntx.image_width <= 10) || (g_imgtile_cntx.image_height <= 10))
    {
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        DisplayPopup(
            (PU8) GetString(STR_ID_IMGTILE_NOTIFY_IMAGE_TOO_WIDE),
            IMG_GLOBAL_WARNING,
            1,
            PHOEDT_NOTIFY_DURATION,
            WARNING_TONE);
        DeleteNHistory(1);
        return;
    }

    display_wnd_width = UI_device_width - IMGTILE_CLIP_SCREEN_SPACING * 2;
    display_wnd_height = MMI_content_height - IMGTILE_CLIP_SCREEN_SPACING * 2;

    gdi_layer_reset_clip();
    if ((g_imgtile_cntx.image_width > display_wnd_width) || (g_imgtile_cntx.image_height > display_wnd_height))
    {
        gdi_image_util_fit_bbox(
            display_wnd_width,
            display_wnd_height,
            g_imgtile_cntx.image_width,
            g_imgtile_cntx.image_height,
            &g_imgtile_cntx.resized_image_offset_x,
            &g_imgtile_cntx.resized_image_offset_y,
            &g_imgtile_cntx.resized_image_width,
            &g_imgtile_cntx.resized_image_height);

        if (g_imgtile_cntx.resized_image_width == 0)
        {
            g_imgtile_cntx.resized_image_width = 1;
            g_imgtile_cntx.resized_image_offset_x--;
        }

        if (g_imgtile_cntx.resized_image_height == 0)
        {
            g_imgtile_cntx.resized_image_height = 1;
            g_imgtile_cntx.resized_image_offset_y--;
        }

        if ((g_imgtile_cntx.resized_image_width <= 10) || (g_imgtile_cntx.resized_image_height <= 10))
        {
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            DisplayPopup(
                (PU8) GetString(STR_ID_IMGTILE_NOTIFY_IMAGE_TOO_WIDE),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);
            DeleteNHistory(1);
            return;
        }

        scale_ratio = ((g_imgtile_cntx.resized_image_offset_x) << 10) / g_imgtile_cntx.image_width;

        g_imgtile_cntx.resized_image_offset_x += IMGTILE_CLIP_SCREEN_SPACING;
        g_imgtile_cntx.resized_image_offset_y += MMI_title_height + MMI_title_y + IMGTILE_CLIP_SCREEN_SPACING;

        result = gdi_image_draw_resized_file(
                    g_imgtile_cntx.resized_image_offset_x,
                    g_imgtile_cntx.resized_image_offset_y,
                    g_imgtile_cntx.resized_image_width,
                    g_imgtile_cntx.resized_image_height,
                    buf_filename);

        if (result < 0)
        {
            gdi_layer_unlock_frame_buffer();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            DisplayPopup(
                (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);
            DeleteNHistory(1);
            return;
        }
    }
    else
    {
        scale_ratio = 1 << 10;

        g_imgtile_cntx.resized_image_width = g_imgtile_cntx.image_width;
        g_imgtile_cntx.resized_image_height = g_imgtile_cntx.image_height;

        g_imgtile_cntx.resized_image_offset_x =
            ((display_wnd_width - g_imgtile_cntx.image_width) >> 1) + IMGTILE_CLIP_SCREEN_SPACING;
        g_imgtile_cntx.resized_image_offset_y =
            ((display_wnd_height - g_imgtile_cntx.image_height) >> 1) + MMI_title_height + MMI_title_y +
            IMGTILE_CLIP_SCREEN_SPACING;

        gdi_image_draw_file(g_imgtile_cntx.resized_image_offset_x, g_imgtile_cntx.resized_image_offset_y, buf_filename);
    }

    /* draw a border for image to make it looks better */
    gdi_draw_rect(
        g_imgtile_cntx.resized_image_offset_x - 1,
        g_imgtile_cntx.resized_image_offset_y - 1,
        g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width,
        g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height,
        IMGTILE_CLIP_FRAME_INSIDE_COLOR);

    gdi_draw_rect(
        g_imgtile_cntx.resized_image_offset_x - 2,
        g_imgtile_cntx.resized_image_offset_y - 2,
        g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width + 1,
        g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height + 1,
        IMGTILE_CLIP_FRAME_OUTSIDE_COLOR);

    /* fit clip rect into image */
    gdi_image_util_fit_bbox(
        g_imgtile_cntx.resized_image_width,
        g_imgtile_cntx.resized_image_height,
        g_imgtile_cntx.clip_size_width,
        g_imgtile_cntx.clip_size_height,
        &g_imgtile_cntx.clip_rect_center_x,
        &g_imgtile_cntx.clip_rect_center_y,
        &g_imgtile_cntx.clip_rect_width,
        &g_imgtile_cntx.clip_rect_height);

    g_imgtile_cntx.clip_rect_center_x +=
        (g_imgtile_cntx.clip_rect_width >> 1) + g_imgtile_cntx.resized_image_offset_x;
    g_imgtile_cntx.clip_rect_center_y +=
        (g_imgtile_cntx.clip_rect_height >> 1) + g_imgtile_cntx.resized_image_offset_y;
   
    mmi_imgtile_clip_draw_osd();

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_clip_screen
 * DESCRIPTION
 *  enter clip screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_clip_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel timer */
    gui_cancel_timer(mmi_imgtile_clip_move_clip_rect_cyclic);

    /* free layer */
    gdi_layer_flatten_previous_to_base();

    gdi_layer_free(g_imgtile_cntx.osd_layer_handle);
    gdi_layer_set_blt_layer(g_imgtile_cntx.base_layer_handle, 0, 0, 0);
    gdi_layer_multi_layer_disable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_draw_osd
 * DESCRIPTION
 *  draw clip retangle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rect_x1;
    S32 rect_y1;
    S32 rect_x2;
    S32 rect_y2;
    S32 x_shift;
    S32 y_shift;
    S32 offset_x;
    S32 offset_y;
    S32 image_width;
    S32 image_height;
    S32 spacing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_imgtile_cntx.osd_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    x_shift = (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
    y_shift = (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;

    rect_x1 = g_imgtile_cntx.clip_rect_center_x - x_shift;
    rect_y1 = g_imgtile_cntx.clip_rect_center_y - y_shift;
    rect_x2 = g_imgtile_cntx.clip_rect_center_x + x_shift;
    rect_y2 = g_imgtile_cntx.clip_rect_center_y + y_shift;

    /* rectangle maybe have 1 pixel shifting, make it align to image */
    if (rect_x2 >= g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width)
    {
        rect_x2 = g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width - 1;
    }

    if (rect_y2 >= g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height)
    {
        rect_y2 = g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height - 1;
    }

    g_imgtile_cntx.clip_rect_x1 = rect_x1;
    g_imgtile_cntx.clip_rect_x2 = rect_x2;
    g_imgtile_cntx.clip_rect_y1 = rect_y1;
    g_imgtile_cntx.clip_rect_y2 = rect_y2;

    gdi_draw_rect(rect_x1, rect_y1, rect_x2, rect_y2, GDI_COLOR_RED);

    if (g_imgtile_cntx.is_clip_pressed)
    {
        gdi_draw_rect(rect_x1 + 1, rect_y1 + 1, rect_x2 - 1, rect_y2 - 1, GDI_COLOR_RED);
    }

    /* draw icon */
    spacing = 3;

    gdi_image_get_dimension_id(IMG_ID_IMGTILE_SCALE_UP_ICON, &image_width, &image_height);

    offset_x = ((UI_device_width - (image_width * 2) - spacing) >> 1);
    offset_y = UI_device_height - (MMI_button_bar_height) - spacing - image_height;

    if (g_imgtile_cntx.is_scale_up_pressed)
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_IMGTILE_SCALE_UP_ICON_SEL);
    }
    else
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_IMGTILE_SCALE_UP_ICON);
    }

#ifdef __MMI_TOUCH_SCREEN__
    g_imgtile_touch_screen_cntx.scale_up.pos_x = offset_x;
    g_imgtile_touch_screen_cntx.scale_up.pos_y = offset_y;
    g_imgtile_touch_screen_cntx.scale_up.width = image_width;
    g_imgtile_touch_screen_cntx.scale_up.height = image_height;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    offset_x += image_width + spacing;
    if (g_imgtile_cntx.is_scale_down_pressed)
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_IMGTILE_SCALE_DOWN_ICON_SEL);
    }
    else
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_IMGTILE_SCALE_DOWN_ICON);
    }

#ifdef __MMI_TOUCH_SCREEN__
    g_imgtile_touch_screen_cntx.scale_down.pos_x = offset_x;
    g_imgtile_touch_screen_cntx.scale_down.pos_y = offset_y;
    g_imgtile_touch_screen_cntx.scale_down.width = image_width;
    g_imgtile_touch_screen_cntx.scale_down.height = image_height;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_move_clip_rect_cyclic
 * DESCRIPTION
 *  move clip retangle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_move_clip_rect_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_step;
    S32 diff;
    S32 image_x1;
    S32 image_x2;
    S32 image_y1;
    S32 image_y2;
    S32 rect_x1;
    S32 rect_x2;
    S32 rect_y1;
    S32 rect_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.move_count++;

    if (g_imgtile_cntx.move_count < 5)
    {
        move_step = 1;
    }
    else if (g_imgtile_cntx.move_count < 7)
    {
        move_step = 3;
    }
    else if (g_imgtile_cntx.move_count < 10)
    {
        move_step = 5;
    }
    else if (g_imgtile_cntx.move_count < 15)
    {
        move_step = 7;
    }
    else
    {
        move_step = 10;
    }

    image_x1 = g_imgtile_cntx.resized_image_offset_x;
    image_y1 = g_imgtile_cntx.resized_image_offset_y;
    image_x2 = g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width - 1;
    image_y2 = g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height - 1;

    rect_x1 =
        g_imgtile_cntx.clip_rect_center_x - (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
    rect_y1 =
        g_imgtile_cntx.clip_rect_center_y - (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;
    rect_x2 =
        g_imgtile_cntx.clip_rect_center_x + (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
    rect_y2 =
        g_imgtile_cntx.clip_rect_center_y + (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;

    if (g_imgtile_cntx.is_up_arrow_pressed)
    {
        if (rect_y1 > image_y1)
        {
            diff = (rect_y1 - move_step) - image_y1;

            if (diff > 0)
            {
                g_imgtile_cntx.clip_rect_center_y -= move_step;
            }
            else
            {
                g_imgtile_cntx.clip_rect_center_y -= move_step + diff;
            }

            mmi_imgtile_clip_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
    }
    else if (g_imgtile_cntx.is_down_arrow_pressed)
    {
        if (rect_y2 < image_y2)
        {
            diff = image_y2 - (rect_y2 + move_step);

            if (diff > 0)
            {
                g_imgtile_cntx.clip_rect_center_y += move_step;
            }
            else
            {
                g_imgtile_cntx.clip_rect_center_y += move_step + diff;
            }

            mmi_imgtile_clip_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
    }
    else if (g_imgtile_cntx.is_left_arrow_pressed)
    {
        if (rect_x1 > image_x1)
        {
            diff = (rect_x1 - move_step) - image_x1;

            if (diff > 0)
            {
                g_imgtile_cntx.clip_rect_center_x -= move_step;
            }
            else
            {
                g_imgtile_cntx.clip_rect_center_x -= move_step + diff;
            }

            mmi_imgtile_clip_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
    }
    else if (g_imgtile_cntx.is_right_arrow_pressed)
    {
        if (rect_x2 < image_x2)
        {
            diff = image_x2 - (rect_x2 + move_step);

            if (diff > 0)
            {
                g_imgtile_cntx.clip_rect_center_x += move_step;
            }
            else
            {
                g_imgtile_cntx.clip_rect_center_x += move_step + diff;
            }

            mmi_imgtile_clip_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }

    }
    else
    {
        MMI_ASSERT(0);
    }

    gui_start_timer(100, mmi_imgtile_clip_move_clip_rect_cyclic);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_up_arrow_press
 * DESCRIPTION
 *  move clip region up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_up_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgtile_cntx.is_up_arrow_pressed)
    {
        g_imgtile_cntx.is_up_arrow_pressed = TRUE;
        g_imgtile_cntx.move_count = 0;

        mmi_imgtile_clip_move_clip_rect_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_down_arrow_press
 * DESCRIPTION
 *  move clip region down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_down_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgtile_cntx.is_down_arrow_pressed)
    {
        g_imgtile_cntx.is_down_arrow_pressed = TRUE;
        g_imgtile_cntx.move_count = 0;

        mmi_imgtile_clip_move_clip_rect_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_left_arrow_press
 * DESCRIPTION
 *  move clip region left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_left_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgtile_cntx.is_left_arrow_pressed)
    {
        g_imgtile_cntx.is_left_arrow_pressed = TRUE;
        g_imgtile_cntx.move_count = 0;

        mmi_imgtile_clip_move_clip_rect_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_right_arrow_press
 * DESCRIPTION
 *  move clip region right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_right_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_imgtile_cntx.is_right_arrow_pressed)
    {
        g_imgtile_cntx.is_right_arrow_pressed = TRUE;
        g_imgtile_cntx.move_count = 0;

        mmi_imgtile_clip_move_clip_rect_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_up_arrow_release
 * DESCRIPTION
 *  move clip region up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_up_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_up_arrow_pressed = FALSE;
    gui_cancel_timer(mmi_imgtile_clip_move_clip_rect_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_down_arrow_release
 * DESCRIPTION
 *  move clip region down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_down_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_down_arrow_pressed = FALSE;
    gui_cancel_timer(mmi_imgtile_clip_move_clip_rect_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_left_arrow_release
 * DESCRIPTION
 *  move clip region left
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_left_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_left_arrow_pressed = FALSE;
    gui_cancel_timer(mmi_imgtile_clip_move_clip_rect_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_right_arrow_release
 * DESCRIPTION
 *  stop move clip region right
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_right_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_right_arrow_pressed = FALSE;
    gui_cancel_timer(mmi_imgtile_clip_move_clip_rect_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_scale_up_press
 * DESCRIPTION
 *  increase rect size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_scale_up_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_scale_up_pressed = TRUE;

    mmi_imgtile_clip_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_scale_up_release
 * DESCRIPTION
 *  increase rect size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_scale_up_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_min;
    S32 x_max;
    S32 y_min;
    S32 y_max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_scale_up_pressed = FALSE;

    if (g_imgtile_cntx.scale_ratio < 100)
    {
        g_imgtile_cntx.scale_ratio += 10;

        y_min =
            g_imgtile_cntx.clip_rect_center_y -
            (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;
        y_max =
            g_imgtile_cntx.clip_rect_center_y +
            (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;
        x_min =
            g_imgtile_cntx.clip_rect_center_x -
            (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
        x_max =
            g_imgtile_cntx.clip_rect_center_x +
            (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;

        if (y_min < g_imgtile_cntx.resized_image_offset_y)
        {
            g_imgtile_cntx.clip_rect_center_y += g_imgtile_cntx.resized_image_offset_y - y_min;
        }

        if (y_max > g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height)
        {
            g_imgtile_cntx.clip_rect_center_y -=
                y_max - (g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height);
        }

        if (x_min < g_imgtile_cntx.resized_image_offset_x)
        {
            g_imgtile_cntx.clip_rect_center_x += g_imgtile_cntx.resized_image_offset_x - x_min;
        }

        if (x_max > g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width)
        {
            g_imgtile_cntx.clip_rect_center_x -=
                x_max - (g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width);
        }
    }
    mmi_imgtile_clip_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_scale_down_press
 * DESCRIPTION
 *  decreasee rect size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_scale_down_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_scale_down_pressed = TRUE;

    mmi_imgtile_clip_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_scale_down_release
 * DESCRIPTION
 *  decreasee rect size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_scale_down_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_min;
    S32 x_max;
    S32 y_min;
    S32 y_max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_scale_down_pressed = FALSE;

    if (g_imgtile_cntx.scale_ratio > IMGTILE_CLIP_RECT_MIN_RATIO)
    {
        g_imgtile_cntx.scale_ratio -= 10;

        y_min =
            g_imgtile_cntx.clip_rect_center_y -
            (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;
        y_max =
            g_imgtile_cntx.clip_rect_center_y +
            (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;
        x_min =
            g_imgtile_cntx.clip_rect_center_x -
            (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
        x_max =
            g_imgtile_cntx.clip_rect_center_x +
            (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;

        if (y_min < g_imgtile_cntx.resized_image_offset_y)
        {
            g_imgtile_cntx.clip_rect_center_y += g_imgtile_cntx.resized_image_offset_y - y_min;
        }

        if (y_max > g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height)
        {
            g_imgtile_cntx.clip_rect_center_y -=
                y_max - (g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height);
        }

        if (x_min < g_imgtile_cntx.resized_image_offset_x)
        {
            g_imgtile_cntx.clip_rect_center_x += g_imgtile_cntx.resized_image_offset_x - x_min;
        }

        if (x_max > g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width)
        {
            g_imgtile_cntx.clip_rect_center_x -=
                x_max - (g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width);
        }

    }

    mmi_imgtile_clip_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_clip_image
 * DESCRIPTION
 *  prepare clip para and enter main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_clip_clip_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 scale_ratio;
    S32 resized_width;
    S32 resized_height;
    S32 x1, y1, x2, y2;
    S32 clip_width;
    S32 clip_height;
    S32 shift;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* calculate how large the image will be after resize */
    clip_width = g_imgtile_cntx.clip_rect_width * g_imgtile_cntx.scale_ratio / 100;
    clip_height = g_imgtile_cntx.clip_rect_height * g_imgtile_cntx.scale_ratio / 100;

    if (clip_width == 0)
    {
        clip_width = 1;
    }

    if (clip_height == 0)
    {
        clip_height = 1;
    }

    resized_width = g_imgtile_cntx.resized_image_width * g_imgtile_cntx.clip_size_width / clip_width;

    /* calculate scale ratio and resize image height */
    scale_ratio = resized_width * 100 / g_imgtile_cntx.image_width;
    resized_height = g_imgtile_cntx.resized_image_height * g_imgtile_cntx.clip_size_height / clip_height; 
    
    /* calc offset of clip region on resized image */
    x1 = g_imgtile_cntx.clip_rect_center_x - (clip_width >> 1) - g_imgtile_cntx.resized_image_offset_x;
    x2 = g_imgtile_cntx.clip_rect_center_x + (clip_width >> 1) - g_imgtile_cntx.resized_image_offset_x;

    y1 = g_imgtile_cntx.clip_rect_center_y - (clip_height >> 1) - g_imgtile_cntx.resized_image_offset_y;
    y2 = g_imgtile_cntx.clip_rect_center_y + (clip_height >> 1) - g_imgtile_cntx.resized_image_offset_y;

    /* scale up offset */
    scale_ratio = g_imgtile_cntx.clip_size_width * 100 / clip_width;
    x1 *= scale_ratio;
    x1 /= 100;

    y1 *= scale_ratio;
    y1 /= 100;

    x2 = x1 + g_imgtile_cntx.clip_size_width - 1;
    y2 = y1 + g_imgtile_cntx.clip_size_height - 1;

    g_imgtile_cntx.clip_x1 = x1;
    g_imgtile_cntx.clip_x2 = x2;
    g_imgtile_cntx.clip_y1 = y1;
    g_imgtile_cntx.clip_y2 = y2;

    g_imgtile_cntx.resized_image_width = resized_width;
    g_imgtile_cntx.resized_image_height = resized_height;

    /* 
     * there may have rounding problem, that the clip region maybe outside of image region,
     * we re-align it back to image region 
     */

    if (g_imgtile_cntx.clip_x1 < 0)
    {
        shift = -g_imgtile_cntx.clip_x1;
        g_imgtile_cntx.clip_x1 = 0;
        g_imgtile_cntx.clip_x2 += shift;

        if (g_imgtile_cntx.clip_x2 > g_imgtile_cntx.resized_image_width - 1)
        {
            g_imgtile_cntx.clip_x2 = g_imgtile_cntx.resized_image_width - 1;
        }
    }

    if (g_imgtile_cntx.clip_x2 > g_imgtile_cntx.resized_image_width - 1)
    {
        shift = g_imgtile_cntx.clip_x2 - (g_imgtile_cntx.resized_image_width - 1);
        g_imgtile_cntx.clip_x2 = (g_imgtile_cntx.resized_image_width - 1);
        g_imgtile_cntx.clip_x1 -= shift;

        if (g_imgtile_cntx.clip_x1 < 0)
        {
            g_imgtile_cntx.clip_x1 = 0;
        }
    }

    if (g_imgtile_cntx.clip_y1 < 0)
    {
        shift = -g_imgtile_cntx.clip_y1;
        g_imgtile_cntx.clip_y1 = 0;
        g_imgtile_cntx.clip_y2 += shift;

        if (g_imgtile_cntx.clip_y2 > g_imgtile_cntx.resized_image_height - 1)
        {
            g_imgtile_cntx.clip_y2 = g_imgtile_cntx.resized_image_height - 1;
        }
    }

    if (g_imgtile_cntx.clip_y2 > g_imgtile_cntx.resized_image_height - 1)
    {
        shift = g_imgtile_cntx.clip_y2 - (g_imgtile_cntx.resized_image_height - 1);
        g_imgtile_cntx.clip_y2 = (g_imgtile_cntx.resized_image_height - 1);
        g_imgtile_cntx.clip_y1 -= shift;

        if (g_imgtile_cntx.clip_y1 < 0)
        {
            g_imgtile_cntx.clip_y1 = 0;
        }
    }

    for (i = 0; i < no_of_tiles; i++)
    {
        if (g_imgtile_cntx.image_array[i] == TRUE)
        {
            g_imgtile_cntx.clipx1[i] = g_imgtile_cntx.clip_x1;
            g_imgtile_cntx.clipx2[i] = g_imgtile_cntx.clip_x2;
            g_imgtile_cntx.clipy1[i] = g_imgtile_cntx.clip_y1;
            g_imgtile_cntx.clipy2[i] = g_imgtile_cntx.clip_y2;
            g_imgtile_cntx.res_width[i] = g_imgtile_cntx.resized_image_width;
            g_imgtile_cntx.res_height[i] = g_imgtile_cntx.resized_image_height;

            /* clip image */
            g_imgtile_cntx.is_clip[i] = TRUE;
            g_imgtile_cntx.is_auto_resize[i] = FALSE;

            break;
        }
    }

    DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);   /* won't delete screen IMGTILE_MAIN and IMGTILE_CLIP */

    /* enter main screen */
    g_imgtile_cntx.is_back_from_clip = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_auto_resize
 * DESCRIPTION
 *  init auto resize application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_auto_resize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_auto_resize, KEY_EVENT_UP);
    /* SetKeyHandler(mmi_imgtile_entry_auto_resize, KEY_RIGHT_ARROW, KEY_EVENT_UP); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_auto_resize
 * DESCRIPTION
 *  entry auto resize to fit image to tile size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_auto_resize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < no_of_tiles; i++)
    {
        if (g_imgtile_cntx.image_array[i] == TRUE)
        {
            g_imgtile_cntx.is_auto_resize[i] = TRUE;
            g_imgtile_cntx.is_clip[i] = FALSE;
        }
    }
    DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);
    g_imgtile_cntx.is_back_from_clip = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_option_screen
 * DESCRIPTION
 *  entry image tile option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *guiBuffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_OPTION, NULL, mmi_imgtile_entry_option_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_OPTION);
    num_item = GetNumOfChild(MENU_ID_IMGTILE_OPTION);

    GetSequenceStringIds(MENU_ID_IMGTILE_OPTION, item_list);
    GetSequenceImageIds(MENU_ID_IMGTILE_OPTION, item_icons);
    SetParentHandler(MENU_ID_IMGTILE_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_IMGTILE_OPTION, popup_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_IMGTILE_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_select
 * DESCRIPTION
 *  init select application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_select_file, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_entry_select_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_save_as
 * DESCRIPTION
 *  init save as application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_save_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_save_as, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_entry_save_as, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_save_as
 * DESCRIPTION
 *  entry save as application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_save_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.save_file = TRUE;
    mmi_imgtile_entry_select_path();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_main_confirm
 * DESCRIPTION
 *  exit confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_main_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_IMGTILE_NOTIFY_EXIT_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_imgtile_exit_main_confirm_yes, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_main_confirm_yes
 * DESCRIPTION
 *  exit confirm yes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_main_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_edited = FALSE;
    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.is_auto_resize[i] = FALSE;
        g_imgtile_cntx.is_clip[i] = FALSE;
    }
    /* cencel file selection - delete up to one level before file selection */
    DeleteUptoScrID(SCR_ID_IMGTILE_APP);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_editor_filename_screen
 * DESCRIPTION
 *  entry edit filename screen, this function will prepare valid filename and
 *  call an internal editor function for screen display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_editor_filename_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PS8 ext_ptr;
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get sequentail number */
    ReadValue(NVRAM_IMGTILE_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }

    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;

    sprintf((PS8) buffer, "TILE%04d", filename_seq_no);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);

    while (1)
    {
        mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);
        sprintf((PS8) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((PS8) UCS2_alpha, (PS8) buffer);

        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (PS8) L".jpg");
        mmi_ucs2cat(buf_filename, UCS2_testname);

        file_handle = FS_Open((U16*) buf_filename, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            break;
        }

        /* exit condition - will get a TILEXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count - 1)
        {
            break;
        }
    }

    mmi_ucs2cpy((PS8) g_imgtile_cntx.filename_edit_buf, (PS8) UCS2_testname);

    /* remove extension */
    ext_ptr = mmi_fmgr_extract_ext_file_name(g_imgtile_cntx.filename_edit_buf);
    *(ext_ptr - 2) = 0;
    *(ext_ptr - 1) = 0;

    mmi_imgtile_entry_editor_filename_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_editor_filename_internal
 * DESCRIPTION
 *  entry edit filename internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_editor_filename_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_EDITOR_FILENAME, NULL, mmi_imgtile_entry_editor_filename_internal, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_EDITOR_FILENAME);

    ShowCategory5Screen(
        STR_ID_IMGTILE_EDIT_FILENAME,
        GetRootTitleIcon(MENU_ID_IMGTILE_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (U8*) g_imgtile_cntx.filename_edit_buf,
        IMGTILE_MAX_FILENAME_CHAR,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_imgtile_entry_editor_option_screen, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_imgtile_back_from_editor_screen, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_imgtile_return_to_editor_screen);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_editor_option_screen
 * DESCRIPTION
 *  entry edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_editor_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store edited text to NVRAM */
    mmi_phoedt_store_data();

    EntryNewScreen(SCR_ID_IMGTILE_EDITOR_OPTION, NULL, mmi_imgtile_entry_editor_option_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_EDITOR_OPTION);
    num_item = GetNumOfChild(MENU_ID_IMGTILE_EDITOR_OPTION);

    GetSequenceStringIds(MENU_ID_IMGTILE_EDITOR_OPTION, item_list);
    GetSequenceImageIds(MENU_ID_IMGTILE_EDITOR_OPTION, item_icons);
    SetParentHandler(MENU_ID_IMGTILE_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_IMGTILE_EDITOR_OPTION, popup_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_IMGTILE_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        (U8 **) popup_list,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_back_from_editor_screen
 * DESCRIPTION
 *  back from edit filename screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_back_from_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.save_file = FALSE;
    DisplayPopup(
        (PU8) GetString(STR_ID_IMGTILE_NOTIFY_FILE_NOT_SAVED),
        IMG_GLOBAL_WARNING,
        1,
        PHOEDT_NOTIFY_DURATION,
        WARNING_TONE);
    DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_return_to_editor_screen
 * DESCRIPTION
 *  return to editor from input selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_return_to_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_editor_done
 * DESCRIPTION
 *  hilight editor "done" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_editor_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_imgtile_save_file, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_editor_cancel
 * DESCRIPTION
 *  hilight editor "cancel" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_editor_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_imgtile_cancel_save_file, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_editor_input
 * DESCRIPTION
 *  hilight editor "input" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_editor_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_cancel_save_file
 * DESCRIPTION
 *  cancel save file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_cancel_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.save_file = FALSE;
    DisplayPopup(
        (PU8) GetString(STR_ID_IMGTILE_NOTIFY_FILE_NOT_SAVED),
        IMG_GLOBAL_WARNING,
        1,
        PHOEDT_NOTIFY_DURATION,
        WARNING_TONE);
    DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_save_file
 * DESCRIPTION
 *  entry saving screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    MDI_RESULT ret;
    gdi_handle image_layer_handle;
    U16 filename_seq_no;
    S16 error = 0;
    S32 i;
    FS_HANDLE h_file;
    PS8 p_skip_space = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);
    /* save filename in NVRAM */
    ReadValue(NVRAM_IMGTILE_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }
    /* WriteValue(NVRAM_IMGTILE_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT , &error); */

    /* check if file is empty or not */
    p_skip_space = mmi_fmgr_skip_space((PS8) g_imgtile_cntx.filename_edit_buf);    
    i = mmi_ucs2strlen(p_skip_space);
    if (i == 0)
    {
        DisplayPopup(
            (PU8) GetString(STR_FMGR_EMPTY_FILENAME),
            IMG_GLOBAL_ERROR,
            1,
            PHOEDT_NOTIFY_DURATION,
            ERROR_TONE);
        DeleteNHistory(1);
        return;
    }

    /* prepare filepath */
    /* add new filename to path */
    i += mmi_ucs2strlen((PS8) buf_filename) + 5;
    if (i > FMGR_PATH_CHAR_COUNT)
    {
        DisplayPopup(
            (PU8) GetString(FMGR_FS_PATH_OVER_LEN_ERROR_TEXT),
            IMG_GLOBAL_ERROR,
            1,
            PHOEDT_NOTIFY_DURATION,
            ERROR_TONE);
        DeleteNHistory(1);
        return;        
    }
    else
    {
        if (mmi_ucs2strlen(p_skip_space) > 0)
        {
            mmi_ucs2cat((PS8) buf_filename, p_skip_space);
            mmi_ucs2cat((PS8) buf_filename, (PS8) L".jpg");
        }
    }
    h_file = FS_Open((U16*) buf_filename, FS_READ_ONLY);
    if (h_file >= FS_NO_ERROR)
    {
        FS_Close(h_file);
        DisplayPopup((PU8) GetString(STR_ID_IMGTILE_NOTIFY_DUPLICATE_FILE), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteNHistory(1);
        return;       
    }
    else if (h_file != FS_FILE_NOT_FOUND)
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(h_file)), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        DeleteNHistory(1);
        return;
    }

    WriteValue(NVRAM_IMGTILE_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    /* create a layer and capture this layer as jepg file */
    gdi_layer_create_using_outside_memory(
        0,
        0,
        UI_device_width,
        UI_device_height,
        &image_layer_handle,
        (PU8) g_imgtile_cntx.origin_image_buf,
        (S32) IMGTILE_FRAME_BUFFER_SIZE);

    ret = mdi_camera_encode_layer_to_jpeg(image_layer_handle, (PS8) buf_filename);

    gdi_layer_free(image_layer_handle);

    switch (ret)
    {
        case MDI_RES_CAMERA_SUCCEED:
            DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, PHOEDT_NOTIFY_DURATION, SUCCESS_TONE);
            DeleteUptoScrID(SCR_ID_IMGTILE_APP);
            DeleteNHistory(1);
            for (i = 0; i < no_of_tiles; i++)
            {
                g_imgtile_cntx.is_auto_resize[i] = FALSE;
                g_imgtile_cntx.is_clip[i] = FALSE;
            }
            g_imgtile_cntx.save_file = 0;
            g_imgtile_cntx.is_edited = 0;
            break;

        case MDI_RES_CAMERA_ERR_DISK_FULL:
            DisplayPopup(
                (PU8) GetString(STR_ID_CAMERA_NOTIFY_DISK_FULL),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);
            /* enable user to select another storage */
            DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);
            break;

        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
            DisplayPopup(
                (PU8) GetString(STR_ID_CAMERA_NOTIFY_WRITE_PROTECTION),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);
            /* enable user to select another storage */
            DeleteUptoScrID(SCR_ID_IMGTILE_MAIN);
            break;

        case MDI_RES_CAMERA_ERR_NO_DISK:
            DisplayPopup(
                (PU8) GetString(STR_ID_CAMERA_NOTIFY_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);
            DeleteUptoScrID(SCR_ID_IMGTILE_APP);
            DeleteNHistory(1);
            for (i = 0; i < no_of_tiles; i++)
            {
                g_imgtile_cntx.is_auto_resize[i] = FALSE;
                g_imgtile_cntx.is_clip[i] = FALSE;
            }
            g_imgtile_cntx.save_file = 0;
            g_imgtile_cntx.is_edited = 0;
            break;
        case MDI_RES_CAMERA_ERR_ROOT_DIR_FULL:
            DisplayPopup( 
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                PHOEDT_NOTIFY_DURATION,
                WARNING_TONE);
            break;                

        default:
            DisplayPopup(
                (PU8) GetString(FMGR_FS_INVALID_FILENAME_TEXT),
                IMG_GLOBAL_ERROR,
                1,
                PHOEDT_NOTIFY_DURATION,
                ERROR_TONE);
            DeleteNHistory(1);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  redraw_tile_screen
 * DESCRIPTION
 *  Redraw tile screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void redraw_tile_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 buf_ptr;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_buffer_ptr(&buf_ptr);
    mmi_imgtile_load_cache_image(buf_ptr);

    for (i = 0; i < no_of_tiles; i++)
    {
        if ((g_imgtile_cntx.is_auto_resize[i] == FALSE) && (g_imgtile_cntx.is_clip[i] == FALSE))
        {
            if (no_of_tiles == 2)
            {
                gdi_image_draw_id(g_imgtile_rect.t2_pos[i].x, g_imgtile_rect.t2_pos[i].y, image_icon[i]);
            }
            else if (no_of_tiles == 4)
            {
                gdi_image_draw_id((i % 2) * (UI_device_width/ 2), (i / 2) * (UI_device_height / 2), image_icon[i]);
            }
            else
            {
                gdi_image_draw_id((i % 3) * (UI_device_width / 3), (i / 3) * (UI_device_height / 3), image_icon[i]);
            }
        }
    }

    if (no_of_tiles == 2)
    {
        gdi_draw_rect(box_offset_x, box_offset_y, box_offset_x + box_width -1 , box_offset_y + box_height -1, IMGTILE_RECT_COLOR);
    }
    else
    {
        if (box_width >= UI_device_width)
        {
            box_width = UI_device_width - 1;
        }
        gdi_draw_rect(box_offset_x, box_offset_y, box_width, box_height, IMGTILE_RECT_COLOR);
    }
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_tile_4
 * DESCRIPTION
 *  init tile 4 application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_tile_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_tile4_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_entry_tile4_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_tile4_screen
 * DESCRIPTION
 *  enter main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_tile4_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 buf_ptr;
    U8 *gui_buffer;
    GDI_RESULT result;
    S32 offset_x;
    S32 offset_y;
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_MAIN, mmi_imgtile_exit_tile4_screen, mmi_imgtile_entry_tile4_screen, NULL);

    no_of_tiles = 4;
    order_of_screen = 2;

    for (i = 0; i < no_of_tiles; i++)
    {
        image_icon[i] = (U16) (IMG_ID_IMGTILE_4TILE_IMAGE_1 + i);
    }

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font(&MMI_medium_font);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_MAIN);

    /* set del screen handler */
    SetDelScrnIDCallbackHandler(SCR_ID_IMGTILE_MAIN, mmi_imgtile_del_screen_id_hdlr);

    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        g_imgtile_cntx.origin_image_buf = (PU8) g_phoedt_original_buffer;
    }

    /* default set to do not free memory, only end key and clam-close or self go back will free */
    g_imgtile_cntx.is_free_memory = FALSE;

    /* entry full screen */
    entry_full_screen();

    /* register key hdlr */
#ifdef NO_LSK
    SetKeyHandler(mmi_imgtile_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);//gjw222
    SetKeyHandler(mmi_imgtile_lsk_release, KEY_SEND1, KEY_EVENT_UP);

#else
    SetKeyHandler(mmi_imgtile_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif


    SetKeyHandler(mmi_imgtile_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_rsk_release, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_imgtile_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_imgtile_left_arrow, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_right_arrow, KEY_RIGHT_ARROW, KEY_EVENT_UP);
#ifdef NO_LSK
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_LSK, KEY_EVENT_UP);//gjw222

#else
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_ENTER, KEY_EVENT_UP);

#endif
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_2, KEY_EVENT_UP);

    /* get end key hdlr and hook ours */
    g_imgtile_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_imgtile_end_key_press, KEY_END, KEY_EVENT_DOWN);

    /***************************************************************************** 
    * Layers
    *****************************************************************************/
    gdi_layer_multi_layer_enable();
    mmi_imgtile_create_layers();

    /***************************************************************************** 
    * redraw tiles
    *****************************************************************************/
    /* lock frame for drawing */
    gdi_layer_lock_frame_buffer();

    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        /* get file name from NVRAM */
        mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);
        gdi_layer_clear_background(IMGTILE_MAIN_CANVAS_COLOR);
        gdi_layer_reset_clip();

        for (i = 0; i < no_of_tiles; i++)
            if ((g_imgtile_cntx.is_auto_resize[i] == TRUE) || (g_imgtile_cntx.is_clip[i] == TRUE))
            {
                g_imgtile_cntx.is_edited = TRUE;
            }

        if (g_imgtile_cntx.is_edited == TRUE)
        {
            for (i = 0; i < no_of_tiles; i++)
            {
                if (g_imgtile_cntx.image_array[i] == TRUE)
                {
                    gdi_layer_get_buffer_ptr(&buf_ptr);
                    mmi_imgtile_load_cache_image(buf_ptr);

                    if (g_imgtile_cntx.is_auto_resize[i] == TRUE)
                    {
                        ret = mmi_imgtile_draw_img_auto_resize((PS8)buf_filename,box_offset_x, box_offset_y, box_width, box_height);
                        /* for tile4/9, box_w/h = x2,y2 */
                        
                        if (ret < 0)
                        {
                            gdi_layer_unlock_frame_buffer();
                            DisplayPopup(
                                (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                                IMG_GLOBAL_WARNING,
                                1,
                                PHOEDT_NOTIFY_DURATION,
                                WARNING_TONE);
                            g_imgtile_cntx.is_auto_resize[i] = g_imgtile_cntx.is_clip[i] = FALSE;
                            g_imgtile_cntx.is_back_from_clip = TRUE;
                            return;
                        }
                    }
                    else if (g_imgtile_cntx.is_clip[i] == TRUE)
                    {
                        /* clip image (manual) */
                        /* use gdi's clip jpeg function */
                        if (i < 2)
                        {
                            offset_x = i * UI_device_width / order_of_screen;
                            offset_y = 0;
                        }
                        else
                        {
                            offset_x = (i - 2) * UI_device_width / order_of_screen;
                            offset_y = UI_device_height / order_of_screen;
                        }
                        gdi_draw_solid_rect(
                            box_offset_x,
                            box_offset_y,
                            box_width,
                            box_height,
                            IMGTILE_MAIN_CANVAS_COLOR);

                        gdi_layer_push_clip();
                        gdi_layer_set_clip(
                            box_offset_x,
                            box_offset_y,
                            box_offset_x+box_width,
                            box_offset_y+box_height);
                        result = gdi_image_jpeg_draw_resized_file_with_output_clipping(
                                    offset_x - g_imgtile_cntx.clipx1[i],
                                    offset_y - g_imgtile_cntx.clipy1[i],
                                    g_imgtile_cntx.res_width[i],
                                    g_imgtile_cntx.res_height[i],
                                    g_imgtile_cntx.clipx1[i],
                                    g_imgtile_cntx.clipy1[i],
                                    g_imgtile_cntx.clipx2[i],
                                    g_imgtile_cntx.clipy2[i],
                                    buf_filename);
                        gdi_layer_pop_clip();
                        /* error handling */
                        if (result < 0)
                        {
                            mmi_imgtile_load_cache_image(buf_ptr);
                            gdi_layer_unlock_frame_buffer();                            
                            if (result == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_IMGTILE_NOTIFY_IMAGE_TOO_WIDE),
                                    IMG_GLOBAL_WARNING,
                                    1,
                                    PHOEDT_NOTIFY_DURATION,
                                    WARNING_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                                    IMG_GLOBAL_WARNING,
                                    1,
                                    PHOEDT_NOTIFY_DURATION,
                                    WARNING_TONE);                                
                            }
                            g_imgtile_cntx.image_array[i] = FALSE;
                            g_imgtile_cntx.is_back_from_clip = FALSE;
                            
                            return;                   
                        }

                        g_imgtile_cntx.resized_image_offset_x = offset_x;
                        g_imgtile_cntx.resized_image_offset_y = offset_y;
                        g_imgtile_cntx.resized_image_width = g_imgtile_cntx.clip_size_width;
                        g_imgtile_cntx.resized_image_height = g_imgtile_cntx.clip_size_height;
                    }
                }
            }
        }
        else
        {
            curr_hilighted_index = 0;
        }

        /* dump original image to cache file */
        gdi_layer_get_buffer_ptr(&buf_ptr);
        if (mmi_imgtile_write_cache_image(buf_ptr) == FALSE)
        {
            /* TODO: error handing */
        }
    }
    else
    {
        /* back from edited screens or interrupt */
        gdi_layer_get_buffer_ptr(&buf_ptr);
        mmi_imgtile_load_cache_image(buf_ptr);
    }

    /* draw main's osd content */
    mmi_imgtile_main_draw_osd();

    /* set highlighter */
    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        mmi_imgtile_set_highlighter();
    }

    for (i = 0; i < no_of_tiles; i++)
    {
        if (i < 2)
        {
            if ((g_imgtile_cntx.is_auto_resize[i] == FALSE) && (g_imgtile_cntx.is_clip[i] == FALSE))
            {
                gdi_image_draw_id(UI_device_width * i / order_of_screen, 0, image_icon[i]);
            }
        }
        else
        {
            if ((g_imgtile_cntx.is_auto_resize[i] == FALSE) && (g_imgtile_cntx.is_clip[i] == FALSE))
            {
                gdi_image_draw_id(
                    UI_device_width * (i - 2) / order_of_screen,
                    UI_device_height / order_of_screen,
                    image_icon[i]);
            }
        }
    }

    gdi_draw_rect(box_offset_x, box_offset_y, box_width, box_height, IMGTILE_RECT_COLOR);
    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.image_array[i] = FALSE;
    }
    g_imgtile_cntx.image_array[curr_hilighted_index] = TRUE;
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    g_imgtile_cntx.is_back_from_clip = FALSE;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_imgtile_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_imgtile_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_imgtile_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_tile4_screen
 * DESCRIPTION
 *  exit main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_tile4_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgtile_exit_tile_screen_general();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_set_new_focus_rect
 * DESCRIPTION
 *  imgtile key left handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_set_new_focus_rect(S32 move_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.image_array[i] = FALSE;
    }

    g_imgtile_cntx.image_array[curr_hilighted_index] = TRUE;
    
    if (no_of_tiles == 2)
    {
        i = move_index % 2;
        box_offset_x = g_imgtile_rect.t2_pos[i].x;
        box_offset_y = g_imgtile_rect.t2_pos[i].y;
        box_width = g_imgtile_rect.t2_size.w;
        box_height = g_imgtile_rect.t2_size.h;
    }
    else
    {
        box_offset_x = (move_index % order_of_screen) * (UI_device_width / order_of_screen);
        box_offset_y = (move_index / order_of_screen) * (UI_device_height / order_of_screen);
        box_width = box_offset_x + UI_device_width / order_of_screen - 1;
        box_height = box_offset_y + UI_device_height / order_of_screen - 1;

        /* +1 height for bottom tiles of tile 9*/
        if (move_index / 3 >= 2)
        {
            box_height+= UI_device_height%order_of_screen;
        }
        if (order_of_screen == 3)
        {
            if (move_index % 3 == 2)
            {
                box_width += 2;
            }
        }

    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_left_arrow
 * DESCRIPTION
 *  imgtile key left handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_left_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (no_of_tiles == 0)
    {
        return;
    }

    move_index = curr_hilighted_index - 1;

    /* move to last if needed */
    if (move_index < 0)
    {
        move_index = no_of_tiles - 1;
    }

    curr_hilighted_index = move_index;

    mmi_imgtile_set_new_focus_rect(move_index);


    redraw_tile_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_right_arrow
 * DESCRIPTION
 *  imgtile key right handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_right_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (no_of_tiles == 0)
    {
        return;
    }

    move_index = curr_hilighted_index + 1;

    /* move to first if needed */
    if (move_index > no_of_tiles - 1)
    {
        move_index = 0;
    }

    curr_hilighted_index = move_index;
    mmi_imgtile_set_new_focus_rect(move_index);


    redraw_tile_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_up_arrow
 * DESCRIPTION
 *  imgtile key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_up_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (no_of_tiles == 0)
    {
        return;
    }
    move_index = curr_hilighted_index - order_of_screen;

    /* move to first if needed */
    if (move_index < 0)
    {
        move_index = move_index + no_of_tiles;
    }

    curr_hilighted_index = move_index;
    mmi_imgtile_set_new_focus_rect(move_index);

    redraw_tile_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_down_arrow
 * DESCRIPTION
 *  imgtile key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_down_arrow(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (no_of_tiles == 0)
    {
        return;
    }

    move_index = curr_hilighted_index + order_of_screen;

    /* move to first if needed */
    if (move_index > no_of_tiles - 1)
    {
        move_index = move_index % no_of_tiles;
    }
    curr_hilighted_index = move_index;

    mmi_imgtile_set_new_focus_rect(move_index);

    redraw_tile_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_hilight_tile_9
 * DESCRIPTION
 *  init tile 9 application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_hilight_tile_9(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_imgtile_entry_tile9_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_imgtile_entry_tile9_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_tile9_screen
 * DESCRIPTION
 *  enter main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_tile9_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 buf_ptr;
    U8 *gui_buffer;
    GDI_RESULT result;
    S32 offset_x;
    S32 offset_y;
    S32 i;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_IMGTILE_MAIN, mmi_imgtile_exit_tile9_screen, mmi_imgtile_entry_tile9_screen, NULL);

    no_of_tiles = 9;
    order_of_screen = 3;

    for (i = 0; i < no_of_tiles; i++)
    {
        image_icon[i] = (U16) (IMG_ID_IMGTILE_9TILE_IMAGE_1 + i);
    }

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    gui_set_font(&MMI_medium_font);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_IMGTILE_MAIN);

    /* set del screen handler */
    SetDelScrnIDCallbackHandler(SCR_ID_IMGTILE_MAIN, mmi_imgtile_del_screen_id_hdlr);

    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        g_imgtile_cntx.origin_image_buf = (PU8) g_phoedt_original_buffer;
    }

    /* default set to do not free memory, only end key and clam-close or self go back will free */
    g_imgtile_cntx.is_free_memory = FALSE;

    /* entry full screen */
    entry_full_screen();

    /* register key hdlr */
#ifdef NO_LSK
    SetKeyHandler(mmi_imgtile_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);//ghw222
    SetKeyHandler(mmi_imgtile_lsk_release, KEY_SEND1, KEY_EVENT_UP);

#else
    SetKeyHandler(mmi_imgtile_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif


    SetKeyHandler(mmi_imgtile_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_rsk_release, KEY_RSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_imgtile_up_arrow, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_down_arrow, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_imgtile_left_arrow, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_right_arrow, KEY_RIGHT_ARROW, KEY_EVENT_UP);

#ifdef NO_LSK
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_LSK, KEY_EVENT_UP);//ghw222

#else
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_ENTER, KEY_EVENT_UP);

#endif

    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_imgtile_flip_edit_hor_button_release, KEY_2, KEY_EVENT_UP);


    /* get end key hdlr and hook ours */
    g_imgtile_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_imgtile_end_key_press, KEY_END, KEY_EVENT_DOWN);

    /***************************************************************************** 
    * Layers
    *****************************************************************************/
    gdi_layer_multi_layer_enable();

    mmi_imgtile_create_layers();

    /***************************************************************************** 
    * redraw tiles
    *****************************************************************************/
    /* lock frame for drawing */
    gdi_layer_lock_frame_buffer();

    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        /* get file name from NVRAM */
        mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_PHOTO_EDITOR);
        gdi_layer_clear_background(IMGTILE_MAIN_CANVAS_COLOR);
        gdi_layer_reset_clip();

        for (i = 0; i < no_of_tiles; i++)
            if ((g_imgtile_cntx.is_auto_resize[i] == TRUE) || (g_imgtile_cntx.is_clip[i] == TRUE))
            {
                g_imgtile_cntx.is_edited = TRUE;
            }

        if (g_imgtile_cntx.is_edited == TRUE)
        {
            for (i = 0; i < no_of_tiles; i++)
            {
                if (g_imgtile_cntx.image_array[i] == TRUE)
                {
                    gdi_layer_get_buffer_ptr(&buf_ptr);
                    mmi_imgtile_load_cache_image(buf_ptr);

                    if (g_imgtile_cntx.is_auto_resize[i] == TRUE)
                    {
                        ret = mmi_imgtile_draw_img_auto_resize((PS8)buf_filename,box_offset_x, box_offset_y, box_width, box_height);
                        /* for tile4/9, box_w/h = x2,y2 */
                        if (ret < 0)
                        {
                            gdi_layer_unlock_frame_buffer();
                            DisplayPopup(
                                (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                                IMG_GLOBAL_WARNING,
                                1,
                                PHOEDT_NOTIFY_DURATION,
                                WARNING_TONE);
                            g_imgtile_cntx.is_auto_resize[i] = g_imgtile_cntx.is_clip[i] = FALSE;
                            g_imgtile_cntx.is_back_from_clip = TRUE;
                            return;
                        }
                    }
                    else if (g_imgtile_cntx.is_clip[i] == TRUE)
                    {
                        /* clip image */                      
                        gdi_draw_solid_rect(box_offset_x, box_offset_y, box_width, box_height, IMGTILE_MAIN_CANVAS_COLOR);
                        gdi_layer_push_clip();
                        /* special handling for the bottom line of tile9 screen */
                        gdi_layer_set_clip(
                            box_offset_x,
                            box_offset_y,
                            box_width,
                            box_height);
                        
                        offset_x = i%3 * (UI_device_width / order_of_screen);
                        offset_y = i/3 * (UI_device_height / order_of_screen);
                        
                        result = gdi_image_draw_resized_file(
                                    offset_x - g_imgtile_cntx.clipx1[i],
                                    offset_y - g_imgtile_cntx.clipy1[i],
                                    g_imgtile_cntx.res_width[i],
                                    g_imgtile_cntx.res_height[i],
                                    buf_filename);
                        gdi_layer_pop_clip();
                        /* error handling */
                        if (result < 0)
                        {
                            mmi_imgtile_load_cache_image(buf_ptr);
                            gdi_layer_unlock_frame_buffer();                            
                            if (result == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_IMGTILE_NOTIFY_IMAGE_TOO_WIDE),
                                    IMG_GLOBAL_WARNING,
                                    1,
                                    PHOEDT_NOTIFY_DURATION,
                                    WARNING_TONE);
                            }
                            else
                            {
                                DisplayPopup(
                                    (PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT),
                                    IMG_GLOBAL_WARNING,
                                    1,
                                    PHOEDT_NOTIFY_DURATION,
                                    WARNING_TONE);                                
                            }
                            g_imgtile_cntx.image_array[i] = FALSE;
                            g_imgtile_cntx.is_back_from_clip = FALSE;
                            
                            return;                   
                        }

                        g_imgtile_cntx.resized_image_offset_x = offset_x;
                        g_imgtile_cntx.resized_image_offset_y = offset_y;
                        g_imgtile_cntx.resized_image_width = g_imgtile_cntx.clip_size_width;
                        g_imgtile_cntx.resized_image_height = g_imgtile_cntx.clip_size_height;
                    }
                }

            }
        }
        else
        {
            curr_hilighted_index = 0;
        }

        /* dump original image to cache file */
        gdi_layer_get_buffer_ptr(&buf_ptr);

        if (mmi_imgtile_write_cache_image(buf_ptr) == FALSE)
        {
            /* TODO: error handing */
        }
    }
    else
    {
        /* back from edited screens or interrupt */
        gdi_layer_get_buffer_ptr(&buf_ptr);
        mmi_imgtile_load_cache_image(buf_ptr);
    }

    /* draw main's osd content */
    mmi_imgtile_main_draw_osd();

    /* set highlighter */
    if (gui_buffer == NULL || g_imgtile_cntx.is_back_from_clip)
    {
        mmi_imgtile_set_highlighter();
    }

    /* draw the Number icon */
    for (i = 0; i < no_of_tiles; i++)
    {
        if ((g_imgtile_cntx.is_auto_resize[i] == FALSE) && (g_imgtile_cntx.is_clip[i] == FALSE))
        {
            gdi_image_draw_id(
                (i % 3) * (UI_device_width / order_of_screen),
                (i / 3) * (UI_device_height / order_of_screen),
                image_icon[i]);
        }
    }
    
    gdi_draw_rect(box_offset_x, box_offset_y, box_width, box_height, IMGTILE_RECT_COLOR);
    for (i = 0; i < no_of_tiles; i++)
    {
        g_imgtile_cntx.image_array[i] = FALSE;
    }
    g_imgtile_cntx.image_array[curr_hilighted_index] = TRUE;
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    g_imgtile_cntx.is_back_from_clip = FALSE;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_imgtile_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_imgtile_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_imgtile_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_exit_tile9_screen
 * DESCRIPTION
 *  exit main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_exit_tile9_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_imgtile_exit_tile_screen_general();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_set_highlighter
 * DESCRIPTION
 *  imgtile key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_set_highlighter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 move_index;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (no_of_tiles == 0)
    {
        return;
    }

    move_index = curr_hilighted_index;
    for (i = no_of_tiles - 1; i >= 0; i--)
    {
        if (!(g_imgtile_cntx.is_auto_resize[i] == TRUE || g_imgtile_cntx.is_clip[i] == TRUE))
        {
            move_index = i;
        }
    }

    curr_hilighted_index = move_index;
    if (no_of_tiles == 2)
    {
        i = move_index % 2;
        box_offset_x = g_imgtile_rect.t2_pos[i].x;
        box_offset_y = g_imgtile_rect.t2_pos[i].y;
        box_width = g_imgtile_rect.t2_size.w;
        box_height = g_imgtile_rect.t2_size.h;
    }
    else
    {
        box_offset_x = (move_index % order_of_screen) * (UI_device_width / order_of_screen);
        box_offset_y = (move_index / order_of_screen) * (UI_device_height / order_of_screen);
        box_width = box_offset_x + UI_device_width / order_of_screen - 1;
        box_height = box_offset_y + UI_device_height / order_of_screen - 1;
        /* +1 height for bottom tiles of tile 9*/
        if (move_index / 3 >= 2)
        {
            box_height+= UI_device_height%order_of_screen;
        }
        if (order_of_screen == 3)
        {
            if (move_index % 3 == 2)
            {
                box_width += 2;
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_entry_select_path
 * DESCRIPTION
 *  entry image tile storage selection path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_entry_select_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    mmi_fmgr_select_path_and_enter(
        APP_PHOEDT,
        FMGR_SELECT_FOLDER,
        filter,
        (PS8) (S8*) L"root",
        (PsExtFuncPtr) mmi_imgtile_fmgr_select_result_callback);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_flip_edit_hor_button_press
 * DESCRIPTION
 *  hor button press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_flip_edit_hor_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_flip_hor_pressed = TRUE;

    mmi_imgtile_main_draw_osd();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_flip_edit_hor_button_release
 * DESCRIPTION
 *  hor button release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_flip_edit_hor_button_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_imgtile_cntx.is_flip_hor_pressed = FALSE;
    mmi_imgtile_main_draw_osd();
    mmi_imgtile_flip_edit_horizontal_flip();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_flip_edit_horizontal_flip
 * DESCRIPTION
 *  flip image horizontal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_imgtile_flip_edit_horizontal_flip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *src_pixtel_ptr;
    U16 *dest_pixtel_ptr;
    U16 *buf_ptr;
    U16 temp_color;
    S32 swap_count;
    S32 image_width;
    S32 image_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 count;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!
        (g_imgtile_cntx.is_auto_resize[curr_hilighted_index] == TRUE ||
         g_imgtile_cntx.is_clip[curr_hilighted_index] == TRUE))
    {
        return;
    }
    if (2 != no_of_tiles)
    {
        image_width = UI_device_width / order_of_screen;
        image_height = UI_device_height / order_of_screen;
    }
    else
    {
        image_width = g_imgtile_rect.t2_size.w;
        image_height = g_imgtile_rect.t2_size.h;        
    }
    
    image_offset_x = box_offset_x;
    image_offset_y = box_offset_y;

    entry_full_screen();

    /* get src buffer frame ptr */
    gdi_layer_get_buffer_ptr((PU8*) & buf_ptr);
    mmi_imgtile_load_cache_image((PU8) buf_ptr);

    src_pixtel_ptr = buf_ptr + (image_offset_y * UI_device_width + image_offset_x);
    dest_pixtel_ptr = src_pixtel_ptr + image_width - 1;

    swap_count = image_width >> 1;

    for (i = 0; i < image_height; i++)
    {
        count = 0;
        while (1)
        {
            temp_color = *src_pixtel_ptr;
            *src_pixtel_ptr = *dest_pixtel_ptr;
            *dest_pixtel_ptr = temp_color;

            count++;
            src_pixtel_ptr++;
            dest_pixtel_ptr--;

            if (count >= swap_count)
            {
                break;
            }
        }

        src_pixtel_ptr += UI_device_width - swap_count;
        dest_pixtel_ptr += UI_device_width + swap_count;

    }
    gdi_layer_get_buffer_ptr((PU8*) & buf_ptr);

    if (mmi_imgtile_write_cache_image((PU8) buf_ptr) == FALSE)
    {
        /* TODO: error handing */
    }
    redraw_tile_screen();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_create_layers
 * DESCRIPTION
 *  create layers for tile screen;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_imgtile_create_layers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHOEDT_USE_FAKE_BASELAYER__    
    PU8 buf_ptr;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        /* base layer */
#ifdef __MMI_PHOEDT_USE_FAKE_BASELAYER__
        /* create a fake base layer with 16-bit color */
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        UI_device_width,
        UI_device_height,
        &g_imgtile_cntx.base_layer_handle,
        buf_ptr,
        UI_device_width * UI_device_height * __MMI_MAIN_BASE_LAYER_FORMAT__);
    gdi_layer_push_and_set_active(g_imgtile_cntx.base_layer_handle);
#else   /* __MMI_PHOEDT_USE_FAKE_BASELAYER__ */
    gdi_layer_get_active(&g_imgtile_cntx.base_layer_handle);
#endif  /* __MMI_PHOEDT_USE_FAKE_BASELAYER__ */  
    /* osd layer */
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &g_imgtile_cntx.osd_layer_handle);
    gdi_layer_push_and_set_active(g_imgtile_cntx.osd_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_imgtile_cntx.base_layer_handle, g_imgtile_cntx.osd_layer_handle, 0, 0);
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_create_layers
 * DESCRIPTION
 *  draw the image file inside the retangle, background will clean to IMGTILE_MAIN_CANVAS_COLOR
 *  if image is too large => fit
 *  if smaller than regangle => align to center.
 * PARAMETERS
 *  p_fname     [IN]    filepath
 *  x1          [IN]    (x1,y1) the top left corner of rect
 *  y1          [IN]    
 *  x2          [IN]    (x2,y2) the bottom right corner of rect.
 *  y2          [IN]    
 * RETURNS
 *  0  => no error,  <0  if failed
 *****************************************************************************/
static S32 mmi_imgtile_draw_img_auto_resize(PS8 p_fname, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_x, img_y, img_w, img_h, resize_w, resize_h;
    S32 bbox_w, bbox_h;
    S32 ret = 0;
    U16 img_type;
    GDI_RESULT g_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, IMGTILE_MAIN_CANVAS_COLOR);

    img_type = gdi_image_get_type_from_file(p_fname);
    g_result = gdi_image_get_dimension_file(p_fname, &img_w, &img_h);

    /* error handling */
    if ((g_result < 0) || (img_type != GDI_IMAGE_TYPE_JPG_FILE) || (img_w <= 0) ||
        (img_h <= 0))
    {
        return -1;
    }

    bbox_w = x2 - x1;
    bbox_h = y2 - y1;
    
    if ((img_w > bbox_w) || (img_h > bbox_h))
    {
        /* auto resize if out of tile boundary */
        gdi_image_util_fit_bbox(bbox_w, bbox_h, img_w, img_h, &img_x, &img_y, &resize_w, &resize_h);

        if (resize_w == 0)
        {
            resize_w = 1;
            img_x--;
        }

        if (resize_h == 0)
        {
            resize_h = 1;
            img_y--;
        }

        g_result = gdi_image_draw_resized_file(x1 +img_x, y1 + img_y, resize_w, resize_h, p_fname);
        
        g_imgtile_cntx.resized_image_offset_x = x1 + img_x;
        g_imgtile_cntx.resized_image_offset_y = y1 + img_y;
        g_imgtile_cntx.resized_image_width = resize_w;
        g_imgtile_cntx.resized_image_height = resize_h;


    }
    else
    {
        g_imgtile_cntx.resized_image_offset_x = x1 + ((bbox_w - img_w) >> 1);
        g_imgtile_cntx.resized_image_offset_y = y1 + ((bbox_h - img_h) >> 1);   
        g_imgtile_cntx.resized_image_width = img_w;
        g_imgtile_cntx.resized_image_height = img_h;

        g_result = gdi_image_draw_file(g_imgtile_cntx.resized_image_offset_x, g_imgtile_cntx.resized_image_offset_y, p_fname);
    }

    /* error handling */
    if ((g_result < 0) || (img_w <= 0) || (img_h <= 0))
    {
        ret = -1;
    }

    return ret;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_set_active_tile
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  i           [IN]        index
 *  tile_style  [IN]        total num of tiles (2,4,9);
 * RETURNS
 *  void
 *****************************************************************************/
 #ifdef __MMI_TOUCH_SCREEN__
static void mmi_imgtile_set_active_tile(S32 i_act, S32 tile_style)
{
    /* only work for 2 tile now. */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_imgtile_pos_t *pp_pos = NULL;
    mmi_imgtile_size_t *p_size = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tile_style != 2)
    {
        return;
    }

    if (i_act > tile_style)
    {
        return;
    }

    curr_hilighted_index = i_act;
    for (i = 0; i < tile_style; i++)
    {
        g_imgtile_cntx.image_array[i] = FALSE;
    }
    g_imgtile_cntx.image_array[i_act] = TRUE;

    if (2 == tile_style)
    {
        pp_pos = &(g_imgtile_rect.t2_pos[0]);
        p_size = &g_imgtile_rect.t2_size;
    }

    box_offset_x = pp_pos[i_act].x;
    box_offset_y = pp_pos[i_act].y;

    box_width = p_size->w;
    box_height = p_size->h;

    redraw_tile_screen();
    
}
#endif /* __MMI_TOUCH_SCREEN__ */


/***************************************************************************** 
*
* Touch Screen
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_get_pen_hit_tile_index
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos         [IN]        Pen down postion
 *  no_of_tile  [IN]        number of tiles (2,4,9);
 * RETURNS
 *  index of the hitted tile, -1 if error.
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
S32 mmi_imgtile_get_pen_hit_tile_index(mmi_pen_point_struct *pos, S32 no_of_tile)
{

    S32 i;
    mmi_imgtile_pos_t *p_tile_pos = NULL;
    mmi_imgtile_size_t  *p_tile_size = NULL;
    S32 i_max = no_of_tile - 1;

    if (2 == no_of_tile)
    {
        p_tile_pos = &(g_imgtile_rect.t2_pos[0]);
        p_tile_size = &(g_imgtile_rect.t2_size);
    }
    else
    {
        return 0;
    }
    
    for(i = 0 ; i <= i_max; i++)
    {
        if ( (pos->x >= p_tile_pos[i].x) &&
            (pos->x <= p_tile_pos[i].x + p_tile_size->w) &&
            (pos->y >= p_tile_pos[i].y) &&
            (pos->y <= p_tile_pos[i].y + p_tile_size->h) )
        {
            break;
        }
    }

    if (i > i_max)
    {
        i = 0;
    }

    return i;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_pen_down_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen down postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_imgtile_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LSK */
    if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.lsk) == MMI_TRUE)    /* within LSK */
    {
        /* draw clicked LSK */
        mmi_imgtile_lsk_press();
        g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_LSK;
        return;
    }

    /* RSK */
    if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.rsk) == MMI_TRUE)    /* within RSK */
    {
        /* draw clicked RSK */
        mmi_imgtile_rsk_press();
        g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_RSK;
        return;
    }

    if (GetActiveScreenId() == SCR_ID_IMGTILE_MAIN) /* hor flip screen */
    {
        if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.flip_hor))
        {
            mmi_imgtile_flip_edit_hor_button_press();
            g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_FLIP_HOR;
            return;
        }
    }

    if (GetActiveScreenId() == SCR_ID_IMGTILE_MAIN) /* tile screen */
    {
        g_imgtile_cntx.pen_offset_x = pos.x;
        g_imgtile_cntx.pen_offset_y = pos.y;

        if (no_of_tiles == 2)
        {
            i = mmi_imgtile_get_pen_hit_tile_index(&pos, no_of_tiles);
            mmi_imgtile_set_active_tile(i, no_of_tiles);
        }
        else if (no_of_tiles == 4)
        {
            if ((pos.y < UI_device_height / 2) && (pos.x < UI_device_width / 2) && (curr_hilighted_index != 0))
            {
                curr_hilighted_index = 3;
                mmi_imgtile_right_arrow();
            }
            else if ((pos.y < UI_device_height / 2) && (pos.x > UI_device_width / 2) && (curr_hilighted_index != 1))
            {
                curr_hilighted_index = 0;
                mmi_imgtile_right_arrow();
            }
            else if ((pos.y > UI_device_height / 2) && (pos.x < UI_device_width / 2) && (curr_hilighted_index != 2))
            {
                curr_hilighted_index = 0;
                mmi_imgtile_down_arrow();
            }
            else if ((pos.y > UI_device_height / 2) && (pos.x > UI_device_width / 2) && (curr_hilighted_index != 3))
            {
                curr_hilighted_index = 2;
                mmi_imgtile_right_arrow();
            }
        }
        else
        {
            if (pos.y < UI_device_height / 3)
            {
                if ((pos.x < UI_device_width / 3) && (curr_hilighted_index != 0))
                {
                    curr_hilighted_index = 8;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > UI_device_width / 3) && (pos.x < 2 * UI_device_width / 3) &&
                         (curr_hilighted_index != 1))
                {
                    curr_hilighted_index = 0;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > 2 * UI_device_width / 3) && (pos.x < UI_device_width) && (curr_hilighted_index != 2))
                {
                    curr_hilighted_index = 1;
                    mmi_imgtile_right_arrow();
                }
            }
            else if (pos.y < 2 * UI_device_height / 3)
            {
                if ((pos.x < UI_device_width / 3) && (curr_hilighted_index != 3))
                {
                    curr_hilighted_index = 0;
                    mmi_imgtile_down_arrow();
                }
                else if ((pos.x > UI_device_width / 3) && (pos.x < 2 * UI_device_width / 3) &&
                         (curr_hilighted_index != 4))
                {
                    curr_hilighted_index = 3;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > 2 * UI_device_width / 3) && (pos.x < UI_device_width) && (curr_hilighted_index != 5))
                {
                    curr_hilighted_index = 4;
                    mmi_imgtile_right_arrow();
                }
            }
            else if (pos.y < UI_device_height)
            {
                if ((pos.x < UI_device_width / 3) && (curr_hilighted_index != 6))
                {
                    curr_hilighted_index = 3;
                    mmi_imgtile_down_arrow();
                }
                else if ((pos.x > UI_device_width / 3) && (pos.x < 2 * UI_device_width / 3) &&
                         (curr_hilighted_index != 7))
                {
                    curr_hilighted_index = 6;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > 2 * UI_device_width / 3) && (pos.x < UI_device_width) && (curr_hilighted_index != 8))
                {
                    curr_hilighted_index = 7;
                    mmi_imgtile_right_arrow();
                }
            }
        }

    }

    /* no event */
    g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_NONE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_pen_up_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen up postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_imgtile_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_imgtile_touch_screen_cntx.pen_event_on_object)
    {
        case IMGTILE_LSK:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.lsk))
            {
                mmi_imgtile_lsk_release();
            }
            break;

        case IMGTILE_RSK:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.rsk))
            {
                mmi_imgtile_rsk_release();
            }
            break;
        case IMGTILE_FLIP_HOR:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.flip_hor))
            {
                mmi_imgtile_flip_edit_hor_button_release();
            }
            break;

        default:
            break;
    }

    g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_NONE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_pen_move_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_imgtile_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 softkey_pressed = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_imgtile_touch_screen_cntx.pen_event_on_object)
    {
        case IMGTILE_LSK:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.lsk) == MMI_TRUE)    /* within LSK */
            {
                softkey_pressed = 1;
            }
            else
            {
                softkey_pressed = 0;
            }
            if (softkey_pressed != g_imgtile_cntx.is_lsk_pressed)
            {
                g_imgtile_cntx.is_lsk_pressed = softkey_pressed;
                mmi_imgtile_show_press_release_softkey();
            }
            break;

        case IMGTILE_RSK:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.rsk) == MMI_TRUE)    /* within RSK */
            {
                softkey_pressed = 1;
            }
            else
            {
                softkey_pressed = 0;
            }
            if (softkey_pressed != g_imgtile_cntx.is_rsk_pressed)
            {
                g_imgtile_cntx.is_rsk_pressed = softkey_pressed;
                mmi_imgtile_show_press_release_softkey();
            }
            break;

        case IMGTILE_FLIP_HOR:
            if (!wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.flip_hor))
            {
                g_imgtile_cntx.is_flip_hor_pressed = FALSE;
                mmi_imgtile_main_draw_osd();

                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
            break;
    }

    if ((GetActiveScreenId() == SCR_ID_IMGTILE_MAIN) && (!g_imgtile_touch_screen_cntx.pen_event_on_object))     /* tile screen */
    {
        g_imgtile_cntx.pen_offset_x = pos.x;
        g_imgtile_cntx.pen_offset_y = pos.y;

        if (no_of_tiles == 2)
        {
            i = mmi_imgtile_get_pen_hit_tile_index(&pos, no_of_tiles);
            mmi_imgtile_set_active_tile(i, no_of_tiles);
        }
        else if (no_of_tiles == 4)
        {
            if ((pos.y < UI_device_height / 2) && (pos.x < UI_device_width / 2) && (curr_hilighted_index != 0))
            {
                curr_hilighted_index = 3;
                mmi_imgtile_right_arrow();
            }
            else if ((pos.y < UI_device_height / 2) && (pos.x > UI_device_width / 2) && (curr_hilighted_index != 1))
            {
                curr_hilighted_index = 0;
                mmi_imgtile_right_arrow();
            }
            else if ((pos.y > UI_device_height / 2) && (pos.x < UI_device_width / 2) && (curr_hilighted_index != 2))
            {
                curr_hilighted_index = 0;
                mmi_imgtile_down_arrow();
            }
            else if ((pos.y > UI_device_height / 2) && (pos.x > UI_device_width / 2) && (curr_hilighted_index != 3))
            {
                curr_hilighted_index = 2;
                mmi_imgtile_right_arrow();
            }
        }
        else
        {
            if (pos.y < UI_device_height / 3)
            {
                if ((pos.x < UI_device_width / 3) && (curr_hilighted_index != 0))
                {
                    curr_hilighted_index = 8;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > UI_device_width / 3) && (pos.x < 2 * UI_device_width / 3) &&
                         (curr_hilighted_index != 1))
                {
                    curr_hilighted_index = 0;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > 2 * UI_device_width / 3) && (pos.x < UI_device_width) && (curr_hilighted_index != 2))
                {
                    curr_hilighted_index = 1;
                    mmi_imgtile_right_arrow();
                }
            }
            else if (pos.y < 2 * UI_device_height / 3)
            {
                if ((pos.x < UI_device_width / 3) && (curr_hilighted_index != 3))
                {
                    curr_hilighted_index = 0;
                    mmi_imgtile_down_arrow();
                }
                else if ((pos.x > UI_device_width / 3) && (pos.x < 2 * UI_device_width / 3) &&
                         (curr_hilighted_index != 4))
                {
                    curr_hilighted_index = 3;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > 2 * UI_device_width / 3) && (pos.x < UI_device_width) && (curr_hilighted_index != 5))
                {
                    curr_hilighted_index = 4;
                    mmi_imgtile_right_arrow();
                }
            }
            else if (pos.y < UI_device_height)
            {
                if ((pos.x < UI_device_width / 3) && (curr_hilighted_index != 6))
                {
                    curr_hilighted_index = 3;
                    mmi_imgtile_down_arrow();
                }
                else if ((pos.x > UI_device_width / 3) && (pos.x < 2 * UI_device_width / 3) &&
                         (curr_hilighted_index != 7))
                {
                    curr_hilighted_index = 6;
                    mmi_imgtile_right_arrow();
                }
                else if ((pos.x > 2 * UI_device_width / 3) && (pos.x < UI_device_width) && (curr_hilighted_index != 8))
                {
                    curr_hilighted_index = 7;
                    mmi_imgtile_right_arrow();
                }
            }
        }

    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_pen_down_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen down postion
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.scale_up))
    {
        mmi_imgtile_clip_scale_up_press();
        g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_CLIP_SCALE_UP;

        /* TRUE: this pen event is taken by us */
        return MMI_TRUE;
    }

    if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.scale_down))
    {
        mmi_imgtile_clip_scale_down_press();
        g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_CLIP_SCALE_DOWN;

        /* TRUE: this pen event is taken by us */
        return MMI_TRUE;
    }

    if ((pos.x >= g_imgtile_cntx.clip_rect_x1) &&
        (pos.x <= g_imgtile_cntx.clip_rect_x2) &&
        (pos.y >= g_imgtile_cntx.clip_rect_y1) && (pos.y <= g_imgtile_cntx.clip_rect_y2))
    {
        g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_CLIP_RECT;
        g_imgtile_cntx.is_clip_pressed = TRUE;

        g_imgtile_cntx.pen_offset_x = pos.x;
        g_imgtile_cntx.pen_offset_y = pos.y;

        mmi_imgtile_clip_draw_osd();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        /* TRUE: this pen event is taken by us */
        return MMI_TRUE;
    }

    /* no event */
    g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_NONE;

    /* FALSE: we do not intercept this pen event */
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_pen_up_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen up postion
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_imgtile_touch_screen_cntx.pen_event_on_object)
    {

        case IMGTILE_CLIP_SCALE_UP:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.scale_up) == MMI_TRUE)
            {
                mmi_imgtile_clip_scale_up_release();
            }
            break;

        case IMGTILE_CLIP_SCALE_DOWN:
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.scale_down) == MMI_TRUE)
            {
                mmi_imgtile_clip_scale_down_release();
            }
            break;

        case IMGTILE_CLIP_RECT:
        {
            g_imgtile_cntx.is_clip_pressed = FALSE;

            mmi_imgtile_clip_draw_osd();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
            break;

        default:
            break;
    }

    g_imgtile_touch_screen_cntx.pen_event_on_object = IMGTILE_NONE;

    /* FALSE: we do not intercept this pen event */
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_pen_move_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 diff;
    S32 image_x1;
    S32 image_x2;
    S32 image_y1;
    S32 image_y2;
    S32 rect_x1;
    S32 rect_x2;
    S32 rect_y1;
    S32 rect_y2;
    S32 shift_x;
    S32 shift_y;
    S32 move_step_x;
    S32 move_step_y;
    BOOL is_update;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_imgtile_touch_screen_cntx.pen_event_on_object)
    {
        case IMGTILE_CLIP_SCALE_UP:
            /* if move outside */
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.scale_up) == MMI_FALSE)
            {
                g_imgtile_cntx.is_scale_up_pressed = FALSE;
                mmi_imgtile_clip_draw_osd();

                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
            break;

        case IMGTILE_CLIP_SCALE_DOWN:
            /* if move outside */
            if (wgui_test_object_position(pos, g_imgtile_touch_screen_cntx.scale_down) == MMI_FALSE)
            {
                g_imgtile_cntx.is_scale_down_pressed = FALSE;
                mmi_imgtile_clip_draw_osd();

                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
            break;

        case IMGTILE_CLIP_RECT:
        {
            is_update = FALSE;

            shift_x = pos.x - g_imgtile_cntx.pen_offset_x;
            shift_y = pos.y - g_imgtile_cntx.pen_offset_y;

            move_step_x = (shift_x > 0) ? shift_x : (-shift_x);
            move_step_y = (shift_y > 0) ? shift_y : (-shift_y);

            image_x1 = g_imgtile_cntx.resized_image_offset_x;
            image_y1 = g_imgtile_cntx.resized_image_offset_y;
            image_x2 = g_imgtile_cntx.resized_image_offset_x + g_imgtile_cntx.resized_image_width - 1;
            image_y2 = g_imgtile_cntx.resized_image_offset_y + g_imgtile_cntx.resized_image_height - 1;

            rect_x1 =
                g_imgtile_cntx.clip_rect_center_x -
                (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
            rect_y1 =
                g_imgtile_cntx.clip_rect_center_y -
                (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;
            rect_x2 =
                g_imgtile_cntx.clip_rect_center_x +
                (g_imgtile_cntx.clip_rect_width >> 1) * g_imgtile_cntx.scale_ratio / 100;
            rect_y2 =
                g_imgtile_cntx.clip_rect_center_y +
                (g_imgtile_cntx.clip_rect_height >> 1) * g_imgtile_cntx.scale_ratio / 100;

            if (shift_y < 0)
            {
                /* move up */
                if (rect_y1 > image_y1)
                {
                    diff = (rect_y1 - move_step_y) - image_y1;

                    if (diff > 0)
                    {
                        g_imgtile_cntx.clip_rect_center_y -= move_step_y;
                    }
                    else
                    {
                        g_imgtile_cntx.clip_rect_center_y -= move_step_y + diff;
                    }

                    is_update = TRUE;
                }
            }
            else if (shift_y > 0)
            {
                /* move down */
                if (rect_y2 < image_y2)
                {
                    diff = image_y2 - (rect_y2 + move_step_y);

                    if (diff > 0)
                    {
                        g_imgtile_cntx.clip_rect_center_y += move_step_y;
                    }
                    else
                    {
                        g_imgtile_cntx.clip_rect_center_y += move_step_y + diff;
                    }

                    is_update = TRUE;
                }
            }

            if (shift_x < 0)
            {
                /* move left */
                if (rect_x1 > image_x1)
                {
                    diff = (rect_x1 - move_step_x) - image_x1;

                    if (diff > 0)
                    {
                        g_imgtile_cntx.clip_rect_center_x -= move_step_x;
                    }
                    else
                    {
                        g_imgtile_cntx.clip_rect_center_x -= move_step_x + diff;
                    }

                    is_update = TRUE;
                }
            }
            else if (shift_x > 0)
            {
                /* move right */
                if (rect_x2 < image_x2)
                {
                    diff = image_x2 - (rect_x2 + move_step_x);

                    if (diff > 0)
                    {
                        g_imgtile_cntx.clip_rect_center_x += move_step_x;
                    }
                    else
                    {
                        g_imgtile_cntx.clip_rect_center_x += move_step_x + diff;
                    }

                    is_update = TRUE;
                }
            }

            if (is_update)
            {
                mmi_imgtile_clip_draw_osd();
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }

            g_imgtile_cntx.pen_offset_x = pos.x;
            g_imgtile_cntx.pen_offset_y = pos.y;
        }

        default:
            break;
    }

    /* FALSE: we do not intercept this pen event */
    return MMI_FALSE;

}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_pen_repeat_hdlr
 * DESCRIPTION
 *  pen repeat hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FALSE: we do not intercept this pen event */
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_pen_long_tap_hdlr
 * DESCRIPTION
 *  pen repeat hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FALSE: we do not intercept this pen event */
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_imgtile_clip_pen_abort_hdlr
 * DESCRIPTION
 *  pen aboart hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL mmi_imgtile_clip_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FALSE: we do not intercept this pen event */
    return MMI_FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __PHOEDT_FEATURE_IMGTILE__ */ 
#endif /* __MMI_PHOTOEDITOR__ */ 

