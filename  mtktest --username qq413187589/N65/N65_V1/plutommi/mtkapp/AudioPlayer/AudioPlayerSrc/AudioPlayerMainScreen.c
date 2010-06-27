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
*  AudioPlayerMainScreen.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player main screen
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * rebase maintrunk.MAUI_MBJ on 2007-4-30 14:36:44.
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * rebase maintrunk.MAUI_MBJ on 2007-4-24 0:25:15.
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_include.h"


/* dependent headers for AudioPlayerXXX.h" */
#include "gui_data_types.h"
#include "SettingProfile.h"
#include "mdi_datatype.h"
#include "Conversions.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"
#include "mdi_audio.h"
#include "Ucs2prot.h"
#include "CommonScreens.h"

#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerMainScreen.h"
#include "AudioPlayerPlayList.h"

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
#include "gui_spectrum.h"
#endif 

/* MTK Leo add 20050301, add touch screen support for Audio Player */
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
/* to write NVRAM */
#endif /*__MMI_TOUCH_SCREEN__*/
/* MTK Leo end */

#ifdef __MMI_AUDIO_PLAYER__

static BOOL init_images_done = FALSE;
static BOOL init_title_scrolling_done = FALSE;
signed char g_audply_main_selected_button;
BOOL g_audply_main_selected_button_down;
static color text_border_color;
static gdi_color text_bg_color;
static color text_fg_color;
PU8 audply_main_bg_img;
PU8 audply_main_pause_on_img;
PU8 audply_main_pause_down_img;
audply_main_title_struct audply_main_title;
audply_main_time_struct audply_main_time;
audply_main_file_index_struct audply_main_file_index;
audply_main_playlisticon_struct audply_main_playlisticon;
audply_main_volumebar_struct audply_main_volumebar;
audply_main_progressbar_struct audply_main_progressbar;
audply_main_volumectrl_struct audply_main_volume_inc, audply_main_volume_dec;

#ifdef __MMI_TOUCH_SCREEN__
audply_main_setting_struct audply_main_setting;
BOOL g_audply_main_pen_move_more_than_once ; /*to avoid play\pause icon keep changing from one another when pen move*/
static S32 g_audply_progress_bar_current_x_pos ; /*the x coordinate of progress bar to decide fast forward or rewind*/
S32 g_audply_progress_bar_pen_down_x_pos ; /*the x coordinate of pen down action on progress bar for refine target time*/
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
audply_main_animation_struct audply_main_animation;
#endif 
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
audply_main_repeat_struct audply_main_repeat;
audply_main_shuffle_struct audply_main_shuffle;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 
audply_main_button_struct audply_main_buttons[NO_OF_AUDPLY_MAIN_BUTTONS];
S16 audply_main_buttons_x1;
S16 audply_main_buttons_y1;
S16 audply_main_buttons_x2;
S16 audply_main_buttons_y2;
U8 audply_main_skin_index;
scrolling_text audply_main_scrolling_title;
UI_string_type audply_main_LSK_text;
UI_string_type audply_main_RSK_text;

#ifdef __GDI_MEMORY_PROFILE_2__
GDI_HANDLE audply_osd_layer;
GDI_HANDLE audply_skin_layer;
BOOL is_audply_skin_layer_drawn = FALSE;
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

extern audply_struct g_audply;                              /* from AudioPlayerSrc.c */
extern const audply_skin_struct g_audply_skins[NO_OF_SKIN]; /* from AudioPlayerSrc.c */
#ifdef    __MMI_AUDIO_PLAYER_ON_SUBLCD__ 
#define EXTRA_GDI_BUFFER_SIZE 12288
extern const audply_sub_skin_struct g_audply_skins_sub[NO_OF_SKIN_SUB];
extern S32 new_gdi_buffer[];

extern void (*SUBLCD_ExitCategoryFunction) (void) ;
extern S32(*SUBLCD_GetCategoryHistorySize) (void);
extern void (*SUBLCD_RedrawCategoryFunction) (void);
extern U8 *(*SUBLCD_GetCategoryHistory) (U8 *buffer);

#endif
extern UI_string_type MMI_title_string;                     /* from wgui_categories.c */
extern S32 MMI_title_height;                                /* from wgui_categories.c */
extern S32 UI_device_width;                                 /* from gui_wrapper.c */
extern S32 UI_device_height;                                /* from gui_wrapper.c */

extern BOOL g_mmi_audply_init_done; /* from AudioPlayerSrc.c */
extern BOOL r2lMMIFlag;             /* definedi n gui_inputs.c */

/* sub LCD */
#ifdef __MMI_SUBLCD__
scrolling_text audply_sub_LCD_scrolling_title;
scrolling_text *audply_sub_LCD_scrolling_title_p = NULL;
extern bitmap *current_LCD_device_bitmap;   /* defined in wgui.c */
extern bitmap main_LCD_device_bitmap;       /* defined in wingui.c */
extern bitmap sub_LCD_device_bitmap;        /* defined in wingui.c */
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_TOUCH_SCREEN__

//typedef enum
//{
//    AUDPLY_PEN_SK_UP,
//    AUDPLY_PEN_SK_DOWN
//} AUDPLY_SOFTKEY_STATE;

S32 audply_pen_event_on_object = AUDPLY_PEN_NONE;
static mmi_pen_point_struct LSK_points[4];
static mmi_pen_point_struct RSK_points[4];
static mmi_pen_polygon_area_struct LSK_area;
static mmi_pen_polygon_area_struct RSK_area;

/* MTK Leo end */
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
spectrum_struct g_aud_ply_spectrum;
extern BOOL g_audply_spectrum_valid ;
extern BOOL g_audply_spectrum_blocked;
extern BOOL mmi_gpio_is_lcd_sleep(void);
#ifdef __MMI_SUBLCD__
spectrum_struct g_aud_ply_spectrum_sub_lcd;
#endif 
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
extern audply_lyric_struct audply_lyric;
extern BOOL lyric_reEntry;
audply_lyric_printing_struct audply_lyric_print;
scrolling_text audply_scrolling_lyric1;
scrolling_text *audply_scrolling_lyric_p1 = NULL;
extern BOOL g_audply_lyrics_valid;
#ifndef __MMI_SUBLCD__
extern bitmap *current_LCD_device_bitmap;   /* defined in wgui.c */
extern bitmap main_LCD_device_bitmap;       /* defined in wingui.c */
extern bitmap sub_LCD_device_bitmap;        /* defined in wingui.c */
#endif /* __MMI_SUBLCD__ */ 
//scrolling_text                        audply_scrolling_lyric2;
//scrolling_text*                       audply_scrolling_lyric_p2 = NULL;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
U8  audply_spectrum_lyrics_exclusive ; /* to check if spectrum and lyrics are mutually 
                                          exclusive on settings and main screen*/
#endif

/* from History.c */
extern S32 mmi_is_redrawing_bk_screens(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_init_main_screen_images
 * DESCRIPTION
 *  init audio player main screen images
 * PARAMETERS
 *  skin        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_init_main_screen_images(S8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const audply_skin_struct *skin_p = &g_audply_skins[skin];
    S32 i, w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bg */
    audply_main_bg_img = (PU8) GetImage(skin_p->bg_image_id);

    /* text_border_color, text fg, bg color */
    text_border_color = gui_color(skin_p->text_border_color_r, skin_p->text_border_color_g, skin_p->text_border_color_b);
    text_fg_color = gui_color(skin_p->text_fg_color_r, skin_p->text_fg_color_g, skin_p->text_fg_color_b);
#ifdef __GDI_MEMORY_PROFILE_2__
    text_bg_color = GDI_COLOR_TRANSPARENT ;   /* transparent */
#else 
    text_bg_color = gdi_act_color_from_rgb(255,skin_p->text_bg_color_r, skin_p->text_bg_color_g, skin_p->text_bg_color_b);
#endif 

    /* title */
    audply_main_title.x = skin_p->title_x;
    audply_main_title.y = skin_p->title_y;
    audply_main_title.w = skin_p->title_w;
    audply_main_title.h = skin_p->title_h;

    /* time */
    audply_main_time.x = skin_p->time_x;
    audply_main_time.y = skin_p->time_y;
    audply_main_time.w = skin_p->time_w;
    audply_main_time.h = skin_p->time_h;

    /* file index */
    audply_main_file_index.x = skin_p->file_index_x;
    audply_main_file_index.y = skin_p->file_index_y;
    audply_main_file_index.w = skin_p->file_index_w;
    audply_main_file_index.h = skin_p->file_index_h;

    /* play list icon */
    audply_main_playlisticon.x = skin_p->playlisticon_x;
    audply_main_playlisticon.y = skin_p->playlisticon_y;
    audply_main_playlisticon.list_icon[LIST_FROM_PHONE] =
        (PU8) GetImage(skin_p->playlisticon_images_id[LIST_FROM_PHONE]);
    audply_main_playlisticon.list_icon[LIST_FROM_CARD] = (PU8) GetImage(skin_p->playlisticon_images_id[LIST_FROM_CARD]);
    gui_measure_image(audply_main_playlisticon.list_icon[LIST_FROM_PHONE], &w, &h);
    audply_main_playlisticon.w = (S16) w;
    audply_main_playlisticon.h = (S16) h;

    /* volume */
    audply_main_volumebar.x = skin_p->volumebar_x;
    audply_main_volumebar.y = skin_p->volumebar_y;
    audply_main_volumebar.ind_len = skin_p->volumebar_ind_len;
    audply_main_volumebar.bar_direction = skin_p->volumebar_direction;
    audply_main_volumebar.ind_img = (PU8) GetImage(skin_p->volumebar_ind_image_id);
    gui_measure_image(audply_main_volumebar.ind_img, &w, &h);
    audply_main_volumebar.w = (S16) w;
    audply_main_volumebar.h = (S16) h;

    /* progress bar */
    audply_main_progressbar.x = skin_p->progressbar_x;
    audply_main_progressbar.y = skin_p->progressbar_y;
    audply_main_progressbar.img = (PU8) GetImage(skin_p->progressbar_image_id);
    audply_main_progressbar.img_fail = (PU8) GetImage(skin_p->progressbar_fail_image_id);
    gui_measure_image(audply_main_progressbar.img, &w, &h);
    audply_main_progressbar.w = (S16) w;
    audply_main_progressbar.h = (S16) h;
    
    /* volume inc & dec control */
    audply_main_volume_inc.x = skin_p->volume_inc_x;
    audply_main_volume_inc.y = skin_p->volume_inc_y;
    audply_main_volume_inc.up_img = (PU8) GetImage(skin_p->volume_inc_up_image_id);
    audply_main_volume_inc.down_img = (PU8) GetImage(skin_p->volume_inc_down_image_id);
    gui_measure_image(audply_main_volume_inc.up_img, &w, &h);
    audply_main_volume_inc.w = (S16) w;
    audply_main_volume_inc.h = (S16) h;
    audply_main_volume_inc.down = FALSE;

    audply_main_volume_dec.x = skin_p->volume_dec_x;
    audply_main_volume_dec.y = skin_p->volume_dec_y;
    audply_main_volume_dec.up_img = (PU8) GetImage(skin_p->volume_dec_up_image_id);
    audply_main_volume_dec.down_img = (PU8) GetImage(skin_p->volume_dec_down_image_id);
    gui_measure_image(audply_main_volume_dec.up_img, &w, &h);
    audply_main_volume_dec.w = (S16) w;
    audply_main_volume_dec.h = (S16) h;
    audply_main_volume_dec.down = FALSE;
#ifdef __MMI_TOUCH_SCREEN__

    /* setting icon */
    audply_main_setting.x = skin_p->setting_x;
    audply_main_setting.y = skin_p->setting_y;
    audply_main_setting.up_img = (PU8) GetImage(skin_p->setting_up_image_id);
    audply_main_setting.down_img = (PU8) GetImage(skin_p->setting_down_image_id);
    gui_measure_image(audply_main_setting.up_img, &w, &h);
    audply_main_setting.w = (S16) w;
    audply_main_setting.h = (S16) h;
    audply_main_setting.down = FALSE;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* play, pause, stop, prev, next buttons */
    audply_main_buttons[AUDPLY_MAIN_PREV].x = skin_p->prev_button_x;
    audply_main_buttons[AUDPLY_MAIN_PREV].y = skin_p->prev_button_y;
    audply_main_buttons[AUDPLY_MAIN_PREV].on_img = (PU8) GetImage(skin_p->prev_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].off_img = (PU8) GetImage(skin_p->prev_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].disabled_img = (PU8) GetImage(skin_p->prev_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].down_img = (PU8) GetImage(skin_p->prev_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_NEXT].x = skin_p->next_button_x;
    audply_main_buttons[AUDPLY_MAIN_NEXT].y = skin_p->next_button_y;
    audply_main_buttons[AUDPLY_MAIN_NEXT].on_img = (PU8) GetImage(skin_p->next_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].off_img = (PU8) GetImage(skin_p->next_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].disabled_img = (PU8) GetImage(skin_p->next_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].down_img = (PU8) GetImage(skin_p->next_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_PLAY].x = skin_p->play_button_x;
    audply_main_buttons[AUDPLY_MAIN_PLAY].y = skin_p->play_button_y;
    audply_main_buttons[AUDPLY_MAIN_PLAY].on_img = (PU8) GetImage(skin_p->play_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].off_img = (PU8) GetImage(skin_p->play_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].disabled_img = (PU8) GetImage(skin_p->play_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].down_img = (PU8) GetImage(skin_p->play_button_down_image_id);
    audply_main_pause_on_img = (PU8) GetImage(skin_p->pause_button_on_image_id);
    audply_main_pause_down_img = (PU8) GetImage(skin_p->pause_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_STOP].x = skin_p->stop_button_x;
    audply_main_buttons[AUDPLY_MAIN_STOP].y = skin_p->stop_button_y;
    audply_main_buttons[AUDPLY_MAIN_STOP].on_img = (PU8) GetImage(skin_p->stop_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].off_img = (PU8) GetImage(skin_p->stop_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].disabled_img = (PU8) GetImage(skin_p->stop_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].down_img = (PU8) GetImage(skin_p->stop_button_down_image_id);

    /* calculate buttons boundary */
    gui_measure_image(audply_main_buttons[0].on_img, &w, &h);
    audply_main_buttons[0].w = (S16) w;
    audply_main_buttons[0].h = (S16) h;
    audply_main_buttons_x1 = audply_main_buttons[0].x;
    audply_main_buttons_y1 = audply_main_buttons[0].y;
    audply_main_buttons_x2 = audply_main_buttons[0].x + w - 1;
    audply_main_buttons_y2 = audply_main_buttons[0].y + h - 1;
    for (i = 1; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
        gui_measure_image(audply_main_buttons[i].on_img, &w, &h);
        audply_main_buttons[i].w = (S16) w;
        audply_main_buttons[i].h = (S16) h;
        if (audply_main_buttons[i].x < audply_main_buttons_x1)
        {
            audply_main_buttons_x1 = audply_main_buttons[i].x;
        }
        if (audply_main_buttons[i].y < audply_main_buttons_y1)
        {
            audply_main_buttons_y1 = audply_main_buttons[i].y;
        }
        if (audply_main_buttons[i].x + w - 1 > audply_main_buttons_x2)
        {
            audply_main_buttons_x2 = audply_main_buttons[i].x + w - 1;
        }
        if (audply_main_buttons[i].y + h - 1 > audply_main_buttons_y2)
        {
            audply_main_buttons_y2 = audply_main_buttons[i].y + h - 1;
        }
    }

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    /* animation */
    audply_main_animation.x = skin_p->animation_x;
    audply_main_animation.y = skin_p->animation_y;
    audply_main_animation.animation_img = (PU8) GetImage(skin_p->animation_image_id);
    gui_measure_image(audply_main_animation.animation_img, &w, &h);
    audply_main_animation.w = (S16) w;
    audply_main_animation.h = (S16) h;
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 

#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
    /* repeat */
    audply_main_repeat.x = skin_p->repeat_x;
    audply_main_repeat.y = skin_p->repeat_y;
    audply_main_repeat.off_up_img = (PU8) GetImage(skin_p->repeat_off_up_image_id);
    audply_main_repeat.all_up_img = (PU8) GetImage(skin_p->repeat_all_up_image_id);
    audply_main_repeat.one_up_img = (PU8) GetImage(skin_p->repeat_one_up_image_id);
#ifdef __MMI_TOUCH_SCREEN__
    audply_main_repeat.off_down_img = (PU8) GetImage(skin_p->repeat_off_down_image_id);
    audply_main_repeat.all_down_img = (PU8) GetImage(skin_p->repeat_all_down_image_id);
    audply_main_repeat.one_down_img = (PU8) GetImage(skin_p->repeat_one_down_image_id);
    audply_main_repeat.down = FALSE;
#endif /*__MMI_TOUCH_SCREEN__*/
    gui_measure_image(audply_main_repeat.off_up_img, &w, &h);
    audply_main_repeat.w = (S16) w;
    audply_main_repeat.h = (S16) h;
    /* shuffle */
    audply_main_shuffle.x = skin_p->shuffle_x;
    audply_main_shuffle.y = skin_p->shuffle_y;
    audply_main_shuffle.off_up_img = (PU8) GetImage(skin_p->shuffle_off_up_image_id);
    audply_main_shuffle.on_up_img = (PU8) GetImage(skin_p->shuffle_on_up_image_id);    
#ifdef __MMI_TOUCH_SCREEN__
    audply_main_shuffle.off_down_img = (PU8) GetImage(skin_p->shuffle_off_down_image_id);
    audply_main_shuffle.on_down_img = (PU8) GetImage(skin_p->shuffle_on_down_image_id);
    audply_main_shuffle.down = FALSE;
#endif /*__MMI_TOUCH_SCREEN__*/
    gui_measure_image(audply_main_shuffle.off_up_img, &w, &h);
    audply_main_shuffle.w = (S16) w;
    audply_main_shuffle.h = (S16) h;
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_aud_ply_spectrum.target_lcd = GDI_LCD_MAIN_LCD_HANDLE;
    g_aud_ply_spectrum.start_x = skin_p->spectrum_display_x;
    g_aud_ply_spectrum.start_y = skin_p->spectrum_display_y;
    g_aud_ply_spectrum.width = skin_p->spectrum_display_w;
    g_aud_ply_spectrum.height = skin_p->spectrum_display_h;
    if(g_aud_ply_spectrum.start_x >= 0)
    {
        g_audply_spectrum_valid = TRUE ;
    }
    else
    {
        g_audply_spectrum_valid = FALSE ;
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    audply_lyric_print.start_x = skin_p->lyric_display_x;
    audply_lyric_print.start_y = skin_p->lyric_display_y;
    audply_lyric_print.width = skin_p->lyric_display_w;
    audply_lyric_print.height = skin_p->lyric_display_h;

    audply_lyric_print.lyric_fg_color = gui_color(skin_p->lyric_fg_color_r, skin_p->lyric_fg_color_g, skin_p->lyric_fg_color_b);

    if(audply_lyric_print.start_x >= 0)
    {
        g_audply_lyrics_valid = TRUE ;
    }
    else
    {
        g_audply_lyrics_valid = FALSE ;
//        g_audply.lyrics_display = 0;
    }

    audply_lyric_print.lyric_border_color = gui_color(skin_p->lyric_border_color_r, skin_p->lyric_border_color_g, skin_p->lyric_border_color_b);

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#if defined(__MMI_AUDIO_SPECTRUM_DISPLAY__) && defined(__MMI_AUDIO_PLAYER_LYRIC_DISPLAY__)
    audply_spectrum_lyrics_exclusive = skin_p->spectrum_lyrics_exclusive ;
    /*error checking*/
    if(audply_spectrum_lyrics_exclusive > 0)
    {
        audply_spectrum_lyrics_exclusive = 1;
    }
    else
    {
        audply_spectrum_lyrics_exclusive = 0;
    }
    if(!g_audply_lyrics_valid || !g_audply_spectrum_valid)
    {
        audply_spectrum_lyrics_exclusive = 0;
    }
    /*if both lyircs and spec are valid and initially are both turned on and they shall be mutually exclusive
      force lyrics_display to be turned off*/
    if(g_audply_lyrics_valid && g_audply_spectrum_valid && audply_spectrum_lyrics_exclusive && g_audply.spectrum_style && g_audply.lyrics_display)
    {
        g_audply.lyrics_display = 0 ;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_subLCD_background
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_subLCD_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_fill_rectangle(x1, y1, x2, y2, c);
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_subLCD_text_scroll_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_subLCD_text_scroll_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__
    gui_handle_scrolling_text(&audply_sub_LCD_scrolling_title);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_subLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_show     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_subLCD(BOOL is_show)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUB_WALLPAPER__
    color border_color = gui_color(0, 0, 0);
    color text_color = gui_color(255, 255, 255);
#else /* __MMI_SUB_WALLPAPER__ */ 
    color text_color = gui_color(0, 0, 0);
#endif /* __MMI_SUB_WALLPAPER__ */ 
    S32 x1, y1, x2, y2, x, y, str_w, str_h;
    bitmap *saved_graphics_context = current_LCD_device_bitmap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_audply_init_done)
    {
        return;
    }

    mmi_audply_set_subLCD_shown(TRUE);

    UI_set_sub_LCD_graphics_context();

    gui_lock_double_buffer();

    if (audply_sub_LCD_scrolling_title_p != NULL)
    {
        gui_scrolling_text_stop(audply_sub_LCD_scrolling_title_p);
        audply_sub_LCD_scrolling_title_p = NULL;
    }

    /* clear background */
    x1 = 0;
    y1 = 13;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    mmi_audply_redraw_subLCD_background(x1, y1, x2, y2);

    if (is_show)
    {
        /* draw song name */
        gui_set_font(&MMI_medium_font);
        gui_measure_string(g_audply.title, &str_w, &str_h);
    #ifdef __MMI_SUB_WALLPAPER__
        str_w += 1;
        str_h += 2;
    #endif /* __MMI_SUB_WALLPAPER__ */ 
        x = (UI_device_width - str_w) / 2;
    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
        {
            y = 15;
        }
        else
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
            y = 12 + (UI_device_height - 12 - str_h) / 2;

        if (x >= 0)
        {
            gui_push_text_clip();
            gui_set_text_color(text_color);
        #ifdef __MMI_SUB_WALLPAPER__
            gui_set_text_border_color(border_color);
        #endif 
            if (r2lMMIFlag)
            {
                gui_move_text_cursor(UI_device_width - x - 2, y);
            }
            else
            {
                gui_move_text_cursor(x, y);
            }
        #ifdef __MMI_SUB_WALLPAPER__
            gui_set_text_clip(x, y - 1, x + str_w - 1, y + str_h - 1);
            gui_print_bordered_text(g_audply.title);
        #else /* __MMI_SUB_WALLPAPER__ */ 
            gui_set_text_clip(x, y, x + str_w - 1, y + str_h - 1);
            gui_print_text(g_audply.title);
        #endif /* __MMI_SUB_WALLPAPER__ */ 
            gui_pop_text_clip();
        }
        else
        {
            /* scroll */
            x = 0;
            audply_sub_LCD_scrolling_title_p = &audply_sub_LCD_scrolling_title;
            mmi_ucs2cpy((PS8)g_audply.sub_title,(const PS8)g_audply.title);
            gui_create_scrolling_text(audply_sub_LCD_scrolling_title_p,
                                      x + 2, y, UI_device_width - 4, str_h, g_audply.sub_title,
                                      mmi_audply_subLCD_text_scroll_handler, mmi_audply_redraw_subLCD_background,
                                      text_color,
        #ifdef __MMI_SUB_WALLPAPER__
                                      border_color
        #else 
                                      text_color
        #endif 
                );
            /* Leo start 20050906 */
        #ifdef __MMI_SUB_WALLPAPER__
            audply_sub_LCD_scrolling_title_p->flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
        #endif 
            /* Leo end */
            audply_sub_LCD_scrolling_title_p->text_font = MMI_medium_font;
            gui_show_scrolling_text(audply_sub_LCD_scrolling_title_p);
        }

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        if (g_audply.spectrum_style != 0 && !mmi_gpio_is_lcd_sleep() && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
        {
            /* draw spectrum */
            g_aud_ply_spectrum_sub_lcd.target_layer = 0;
            g_aud_ply_spectrum_sub_lcd.target_lcd = GDI_LCD_SUB_LCD_HANDLE;
            g_aud_ply_spectrum_sub_lcd.start_x = 2;
            g_aud_ply_spectrum_sub_lcd.start_y = y + str_h + 2;
            g_aud_ply_spectrum_sub_lcd.height = UI_device_height - g_aud_ply_spectrum_sub_lcd.start_y - 4;
            g_aud_ply_spectrum_sub_lcd.width = UI_device_width - 4;
            g_aud_ply_spectrum_sub_lcd.style = g_audply.spectrum_style;
            switch (g_aud_ply_spectrum_sub_lcd.style)
            {
                case STYLE_BLOCKS:
                case STYLE_BARS:
                    g_aud_ply_spectrum_sub_lcd.number_of_bars = 16;
                    break;
                case STYLE_CIRCLES:
                    g_aud_ply_spectrum_sub_lcd.number_of_bars = 8;
                    break;
                default:
                    ASSERT(0);
            }

            mmi_audio_spectrum_init_display(&g_aud_ply_spectrum_sub_lcd);
            if (g_audply.state == STATE_PLAY)
            {
                mmi_audio_spectrum_start_display(&g_aud_ply_spectrum_sub_lcd);
            }
        }
    #endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);

    gui_pop_clip();

    if (saved_graphics_context == &main_LCD_device_bitmap)
    {
        UI_set_main_LCD_graphics_context();
    }
    else if (saved_graphics_context == &sub_LCD_device_bitmap)
    {
        UI_set_sub_LCD_graphics_context();
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_subLCD
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_subLCD()
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.is_subLCD_shown)
    {
        bitmap *saved_graphics_context;

    #ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
        mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum_sub_lcd);
    #endif 

        saved_graphics_context = current_LCD_device_bitmap;

        UI_set_sub_LCD_graphics_context();

        if (audply_sub_LCD_scrolling_title_p != NULL)
        {
            gui_scrolling_text_stop(audply_sub_LCD_scrolling_title_p);
            audply_sub_LCD_scrolling_title_p = NULL;
        }
        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }

        mmi_audply_set_subLCD_shown(FALSE);
    }
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_show_mainscreen
 * DESCRIPTION
 *  show audio player main screen
 * PARAMETERS
 *  title               [IN]        
 *  left_softkey        [IN]        
 *  right_softkey       [IN]        
 *  skin                [IN]        
 *  U8* history_buffer(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_show_mainscreen(U16 title, U16 left_softkey, U16 right_softkey, S8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_string = (UI_string_type) GetString(title);
    #ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    if(g_audply.in_sub_screen)
    {
        SUBLCD_ExitCategoryFunction();
        UI_set_sub_LCD_graphics_context();
        }
    #endif
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();

    /* get base layer as skin layer */
    gdi_layer_get_base_handle(&audply_osd_layer);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    #ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(g_audply.in_sub_screen)
    {
        gdi_layer_create_using_outside_memory(0,0,UI_device_width,UI_device_height,&audply_skin_layer,(U8*)new_gdi_buffer,EXTRA_GDI_BUFFER_SIZE);		
	}
    else
    #endif	
    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &audply_skin_layer);
    gdi_layer_set_blt_layer(audply_skin_layer, audply_osd_layer, 0, 0);
#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    g_aud_ply_spectrum.target_layer = audply_osd_layer;
#endif 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    audply_lyric_print.target_layer = audply_osd_layer;
#endif 

#endif /* __GDI_MEMORY_PROFILE_2__ */ 

    /* init images */
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(g_audply.in_sub_screen)
	{
	        mmi_sub_audply_init_main_screen_images(0);
			audply_main_skin_index = -1;//be used to executed the initialization of images when show audio player main
	}                                   //screen on mainlcd after switching from audio player main screen on sublcd.
	else
#endif
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    if (!init_images_done || audply_main_skin_index != skin)
#endif        
    {
        mmi_audply_init_main_screen_images(skin);
        audply_main_skin_index = skin;
        init_images_done = TRUE;
        init_title_scrolling_done = FALSE;
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    is_audply_skin_layer_drawn = FALSE;
#endif 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (g_audply.spectrum_style != 0 )
    {
        g_aud_ply_spectrum.style = g_audply.spectrum_style;
        switch (g_aud_ply_spectrum.style)
        {
            case STYLE_BLOCKS:
            case STYLE_BARS:
                g_aud_ply_spectrum.number_of_bars = 16;
                break;
            case STYLE_CIRCLES:
                g_aud_ply_spectrum.number_of_bars = 8;
                break;
            default:
                ASSERT(0);
        }
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(!g_audply.in_sub_screen)
	{
#endif
		clear_key_handlers();
		clear_left_softkey();
		clear_right_softkey();
		audply_main_LSK_text = (UI_string_type) GetString(left_softkey);
		audply_main_RSK_text = (UI_string_type) GetString(right_softkey);
		SetKeyHandler(mmi_audply_redraw_LSK_down, KEY_LSK, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_audply_redraw_RSK_down, KEY_RSK, KEY_EVENT_DOWN);
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	}
#endif

    /* associate functions */
    #ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    if(g_audply.in_sub_screen)
    {
       SUBLCD_ExitCategoryFunction = MMI_dummy_function;
       SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
       SUBLCD_GetCategoryHistory = dummy_get_history;
       SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    }
    else
    #endif
    {
    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    }
    /* draw screen */
    mmi_audply_redraw_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_exit_mainscreen
 * DESCRIPTION
 *  exit audio player main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_exit_mainscreen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_scrolling_text_stop(&audply_main_scrolling_title);

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__
    mmi_audply_stop_scroll_lyric_and_clean_screen();
    mmi_audply_lyric_check_backlight(0);
    lyric_reEntry = TRUE;
#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    mmi_audply_spectrum_display_stop();
#endif 

#ifdef __MMI_AUDIO_PLAYER_ANIMATION__
    /* stop animation */
    if (audply_main_animation.img_handle != GDI_ERROR_HANDLE)
    {
        gdi_image_stop_animation(audply_main_animation.img_handle);
    }
#endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_flatten_to_base(audply_skin_layer, audply_osd_layer, 0, 0);
    gdi_layer_free(audply_skin_layer);
    gdi_layer_multi_layer_disable();

    /* restore blt layer as base layer only */
    gdi_layer_set_blt_layer(audply_osd_layer, 0, 0, 0);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
    audply_main_volume_inc.down = FALSE;
    audply_main_volume_dec.down = FALSE;
#ifdef __MMI_TOUCH_SCREEN__
    audply_main_setting.down = FALSE;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__    
    audply_main_repeat.down = FALSE;
    audply_main_shuffle.down = FALSE;
#endif
    audply_pen_event_on_object = AUDPLY_PEN_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_LSK_down
 * DESCRIPTION
 *  redraw shifted LSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_LSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    color LSK_text_color = gui_color(255, 255, 255);
    S32 offset_x, offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(LSK_text_color);
    gui_set_text_border_color(text_border_color);

    /* show LSK */
    gui_measure_string(audply_main_LSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(audply_main_LSK_text, &offset_x, &offset_y, MMI_LEFT_SOFTKEY);
    x1 = offset_x;
    y1 = offset_y;
    y2 = offset_y + str_h;
    if(r2lMMIFlag)
    {
        x2 = x1 - str_w ;
    }
    else
    {
        x2 = x1 + str_w;
    }
    gdi_layer_push_clip();
    if(r2lMMIFlag)
    {
        gdi_layer_set_clip(x2 - 2, y1 - 2, x1, y2);

    }
    else
    {
        gdi_layer_set_clip(x1 - 2, y1 - 2, x2, y2);
    }
    
#ifdef __GDI_MEMORY_PROFILE_2__
    if(r2lMMIFlag)
    {
        gdi_draw_solid_rect(x2 - 2, y1 - 2, x1, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(x1 - 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
    }
#else 
    gdi_image_draw(0, 0, audply_main_bg_img);
#endif 
    gdi_layer_pop_clip();
    gui_push_text_clip();
    
    if(r2lMMIFlag)
    {
        gui_set_text_clip(x2, y1 - 1, x1, y2);
    }
    else
    {
        gui_set_text_clip(x1, y1 - 1, x2, y2);
    }

    gui_move_text_cursor(x1, y1);
    gui_print_bordered_text(audply_main_LSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();

    if(r2lMMIFlag)
    {
        gui_BLT_double_buffer(x2 - 2, y1 - 2, x1, y2);
    }
    else
    {
        gui_BLT_double_buffer(x1 - 2, y1 - 2, x2, y2);
    }
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_RSK_down
 * DESCRIPTION
 *  redraw shifted RSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_RSK_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    color RSK_text_color = gui_color(255, 255, 255);
    S32 offset_x, offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(RSK_text_color);
    gui_set_text_border_color(text_border_color);

    /* show RSK */
    gui_measure_string(audply_main_RSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(audply_main_RSK_text, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
    x1 = offset_x;
    y1 = offset_y;
    y2 = offset_y + str_h;
    
    if(r2lMMIFlag)
    {
        x2 = x1 - str_w ;
    }
    else
    {
        x2 = x1 + str_w;
    }
    gdi_layer_push_clip();

    if(r2lMMIFlag)
    {
        gdi_layer_set_clip(x2 - 2, y1 - 2, x1, y2);

    }
    else
    {
        gdi_layer_set_clip(x1 - 2, y1 - 2, x2, y2);
    }
    
#ifdef __GDI_MEMORY_PROFILE_2__
    if(r2lMMIFlag)
    {
        gdi_draw_solid_rect(x2 - 2, y1 - 2, x1, y2, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(x1 - 2, y1 - 2, x2, y2, GDI_COLOR_TRANSPARENT);
    }
#else 
    gdi_image_draw(0, 0, audply_main_bg_img);
#endif 
    gdi_layer_pop_clip();
    gui_push_text_clip();
    if(r2lMMIFlag)
    {
        gui_set_text_clip(x2, y1 - 1, x1, y2);
    }
    else
    {
        gui_set_text_clip(x1, y1 - 1, x2, y2);
    }

    gui_move_text_cursor(x1, y1);
        
    gui_print_bordered_text(audply_main_RSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    if(r2lMMIFlag)
    {
        gui_BLT_double_buffer(x2 - 2, y1 - 2, x1, y2);
    }
    else
    {
        gui_BLT_double_buffer(x1 - 2, y1 - 2, x2, y2);
    }
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_LSK_up
 * DESCRIPTION
 *  redraw shifted LSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_LSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    color LSK_text_color = gui_color(255, 255, 255);
    S32 offset_x, offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(LSK_text_color);
    gui_set_text_border_color(text_border_color);

    /* show LSK */
    gui_measure_string(audply_main_LSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(audply_main_LSK_text, &offset_x, &offset_y, MMI_LEFT_SOFTKEY);
    x1 = offset_x - 1;
    y1 = offset_y - 1;
    y2 = y1 + str_h;

    if(r2lMMIFlag)
    {
        x2 = x1 - str_w;
    }
    else
    {
        x2 = x1 + str_w;
    }

    gdi_layer_push_clip();

    if(r2lMMIFlag)
    {
        gdi_layer_set_clip(x2 - 1, y1 - 1, x1 + 1, y2 + 1);
    }
    else
    {
        gdi_layer_set_clip(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    }
    
#ifdef __GDI_MEMORY_PROFILE_2__
    if(r2lMMIFlag)
    {
        gdi_draw_solid_rect(x2 - 1, y1 - 1, x1 + 1, y2 + 1, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(x1 - 1, y1 - 1, x2 + 1, y2 + 1, GDI_COLOR_TRANSPARENT);
    }
#else 
    gdi_image_draw(0, 0, audply_main_bg_img);
#endif 
    gdi_layer_pop_clip();
    gui_push_text_clip();

    if(r2lMMIFlag)
    {
        gui_set_text_clip(x2 - 1, y1 - 1, x1, y2);
    }
    else
    {
        gui_set_text_clip(x1 - 1, y1 - 1, x2, y2);
    }

    gui_move_text_cursor(x1, y1);

    gui_print_bordered_text(audply_main_LSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    if(r2lMMIFlag)
    {
        gui_BLT_double_buffer(x2 - 1, y1 - 1, x1 + 1, y2 + 1);
    }
    else
    {
        gui_BLT_double_buffer(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    }
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_RSK_up
 * DESCRIPTION
 *  redraw shifted RSK for key press down event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_RSK_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    color RSK_text_color = gui_color(255, 255, 255);
    S32 offset_x, offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(RSK_text_color);
    gui_set_text_border_color(text_border_color);

    /* show RSK */
    gui_measure_string(audply_main_RSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(audply_main_RSK_text, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
    x1 = offset_x - 1;
    y1 = offset_y - 1;
    y2 = y1 + str_h;

    if(r2lMMIFlag)
    {
        x2 = x1 - str_w;
    }
    else
    {
        x2 = x1 + str_w;
    }

    gdi_layer_push_clip();

    if(r2lMMIFlag)
    {
        gdi_layer_set_clip(x2 - 1, y1 - 1, x1 + 1, y2 + 1);
    }
    else
    {
        gdi_layer_set_clip(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    }
#ifdef __GDI_MEMORY_PROFILE_2__

    if(r2lMMIFlag)
    {
        gdi_draw_solid_rect(x2 - 1, y1 - 1, x1 + 1, y2 + 1, GDI_COLOR_TRANSPARENT);
    }
    else
    {
        gdi_draw_solid_rect(x1 - 1, y1 - 1, x2 + 1, y2 + 1, GDI_COLOR_TRANSPARENT);
    }    
#else 
    gdi_image_draw(0, 0, audply_main_bg_img);
#endif 
    gdi_layer_pop_clip();
    gui_push_text_clip();

    if(r2lMMIFlag)
    {
        gui_set_text_clip(x2 - 1, y1 - 1, x1, y2);
    }
    else
    {
        gui_set_text_clip(x1 - 1, y1 - 1, x2, y2);
    }

    gui_move_text_cursor(x1, y1);

    gui_print_bordered_text(audply_main_RSK_text);
    gui_pop_text_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    if(r2lMMIFlag)
    {
        gui_BLT_double_buffer(x2 - 1, y1 - 1, x1 + 1, y2 + 1);
    }
    else
    {
        gui_BLT_double_buffer(x1 - 1, y1 - 1, x2 + 1, y2 + 1);
    }
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_screen
 * DESCRIPTION
 *  redraw audio player main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h;
    S32 x1, y1, x2, y2;
    color head_text_color = gui_color(255, 255, 255);
    S32 offset_x, offset_y;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
    PU8 image_id = NULL;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_push_text_clip();

    /* background ,head, LSK, and RSK */
#ifdef __GDI_MEMORY_PROFILE_2__
    if (!is_audply_skin_layer_drawn)
    {
        gdi_layer_push_and_set_active(audply_skin_layer);
#endif /* __GDI_MEMORY_PROFILE_2__ */ 
        gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
        gui_show_image(0, 0, audply_main_bg_img);
		
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(!g_audply.in_sub_screen)
	{
#endif

    #ifdef __MMI_AUDIO_PLAYER_ANIMATION__
        /* show animation */
        audply_main_animation.img_handle = GDI_ERROR_HANDLE;
        gdi_image_draw_animation(
            audply_main_animation.x,
            audply_main_animation.y,
            audply_main_animation.animation_img,
            &audply_main_animation.img_handle);
    #endif /* __MMI_AUDIO_PLAYER_ANIMATION__ */ 
	
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	}
#endif	

    #ifdef __GDI_MEMORY_PROFILE_2__
        is_audply_skin_layer_drawn = TRUE;
        gdi_layer_pop_and_restore_active();
    }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__
    if (g_audply.spectrum_style != 0 && g_audply_spectrum_valid && !g_audply_spectrum_blocked)
    {
	#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	   if(!g_audply.in_sub_screen)
	   {
	#endif
		if (g_audply.state == STATE_PLAY)
        {
            /* start calc top and vals */
            mmi_audply_calc_spectrum(TRUE);
       	    mmi_audio_spectrum_init_display(&g_aud_ply_spectrum);
     	    mmi_audio_spectrum_start_display(&g_aud_ply_spectrum);
		}
	#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
		}
	#endif
    }
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(!g_audply.in_sub_screen)
	{
#endif
    gui_set_font(&MMI_medium_font);
    gui_set_text_color(head_text_color);
    gui_set_text_border_color(text_border_color);
    gui_measure_string(MMI_title_string, &str_w, &str_h);
    gui_set_line_height(str_h);
    if (str_w > UI_device_width)
    {
        str_w = UI_device_width;
    }
    gui_set_text_clip(0, 0, UI_device_width - 1, MMI_title_height - 1);
    if (r2lMMIFlag)
    {
        x1 = (UI_device_width + str_w) / 2;
    }
    else
    {
        x1 = (UI_device_width - str_w) / 2;
    }
    gui_print_truncated_borderd_text(x1, (MMI_title_height - str_h) / 2, UI_device_width - 2, MMI_title_string);

    /* show LSK */
    gui_measure_string(audply_main_LSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(audply_main_LSK_text, &offset_x, &offset_y, MMI_LEFT_SOFTKEY);
    x1 = offset_x - 1;
    y1 = offset_y - 1;
    y2 = offset_y + str_h - 1;
    if(r2lMMIFlag)
    {
        x2 = x1 - str_w;
        gui_set_text_clip(x2, y1 -1, x1, y2);
    }
    else
    {
        x2 = x1 + str_w ;
        gui_set_text_clip(x1, y1 -1, x2, y2);
    }
    
    gui_move_text_cursor(x1, y1);
    gui_print_bordered_text(audply_main_LSK_text);
#ifdef __MMI_TOUCH_SCREEN__
    LSK_area.num = 4;
    LSK_area.points = (mmi_pen_point_struct*) LSK_points;
    LSK_points[0].x = LSK_points[3].x = x1;
    LSK_points[0].y = LSK_points[1].y = y1;
    LSK_points[1].x = LSK_points[2].x = x2 + 1;
    LSK_points[2].y = LSK_points[3].y = y2 + 1;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* show RSK */
    gui_measure_string(audply_main_RSK_text, &str_w, &str_h);
    wgui_softkey_get_offset(audply_main_RSK_text, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
    x1 = offset_x - 1;
    y1 = offset_y - 1;
    y2 = offset_y + str_h - 1;
    if(r2lMMIFlag)
    {
        x2 = x1 - str_w;
        gui_set_text_clip(x2, y1 -1, x1, y2);
    }
    else
    {
        x2 = x1 + str_w ;
        gui_set_text_clip(x1, y1 -1, x2, y2);
    }
    
    gui_move_text_cursor(x1, y1);
    gui_print_bordered_text(audply_main_RSK_text);
#ifdef __MMI_TOUCH_SCREEN__
    RSK_area.num = 4;
    RSK_area.points = (mmi_pen_point_struct*) RSK_points;
    RSK_points[0].x = RSK_points[3].x = x1;
    RSK_points[0].y = RSK_points[1].y = y1;
    RSK_points[1].x = RSK_points[2].x = x2 + 1;
    RSK_points[2].y = RSK_points[3].y = y2 + 1;
#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	}
#endif
	gui_pop_text_clip();
    gui_pop_clip();
    mmi_audply_redraw_main_title();
    mmi_audply_redraw_main_playlisticon();
    mmi_audply_redraw_main_file_index();
    mmi_audply_redraw_main_time();
    mmi_audply_redraw_main_volumebar();
	
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(!g_audply.in_sub_screen)
	{
#endif
    mmi_audply_redraw_main_progressbar();
#ifdef __MMI_TOUCH_SCREEN__
    mmi_audply_redraw_main_setting(audply_main_setting.down);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    mmi_audply_redraw_main_volumectrl(0, audply_main_volume_dec.down);
    mmi_audply_redraw_main_volumectrl(1, audply_main_volume_inc.down);
    
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	}
#endif
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
    if(g_audply.in_sub_screen)
    {
       mmi_sub_audply_redraw_main_buttons();
    }
    else
#endif

    mmi_audply_redraw_main_buttons();
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	if(!g_audply.in_sub_screen)
	{
#endif

#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
    gui_push_clip();

    /* show repeat icon */
    x1 = (S32) audply_main_repeat.x;
    y1 = (S32) audply_main_repeat.y;
    x2 = x1 + audply_main_repeat.w - 1;
    y2 = y1 + audply_main_repeat.h - 1;
    gui_set_clip(x1, y1, x2, y2);
    switch (g_audply.repeat_mode)
    {
        case REPEAT_OFF:
            image_id = audply_main_repeat.off_up_img;
            break;
        case REPEAT_ALL:
            image_id = audply_main_repeat.all_up_img;
            break;
        case REPEAT_ONE:
            image_id = audply_main_repeat.one_up_img;
            break;
        default:
            ASSERT(0);
    }
    gui_show_image(x1, y1, image_id);

    /* show shuffle icon */
    x1 = (S32) audply_main_shuffle.x;
    y1 = (S32) audply_main_shuffle.y;
    x2 = x1 + audply_main_shuffle.w - 1;
    y2 = y1 + audply_main_shuffle.h - 1;
    gui_set_clip(x1, y1, x2, y2);
    switch (g_audply.random_mode)
    {
        case SHUFFLE_OFF:
            image_id = audply_main_shuffle.off_up_img;
            break;
        case SHUFFLE_ON:
            image_id = audply_main_shuffle.on_up_img;
            break;
        default:
            ASSERT(0);
    }
    gui_show_image(x1, y1, image_id);

    gui_pop_clip();
#endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
	}
#endif

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_title_background
 * DESCRIPTION
 *  redraw audio player main title background
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_title_background(S32 x1, S32 y1, S32 x2, S32 y2)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_scroll_main_title_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_scroll_main_title_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&audply_main_scrolling_title);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_title
 * DESCRIPTION
 *  redraw audio player main title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 character_height, w;
    S32 x1 = audply_main_title.x;
    S32 y1 = audply_main_title.y;
    S32 x2 = audply_main_title.x + audply_main_title.w - 1;
    S32 y2 = audply_main_title.y + audply_main_title.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previous scroll text */
    if (init_title_scrolling_done)
    {
        gui_scrolling_text_stop(&audply_main_scrolling_title);
    }
    else
    {
        init_title_scrolling_done = TRUE;
    }

    gui_create_scrolling_text(
        &audply_main_scrolling_title,
        x1,
        y1,
        audply_main_title.w,
        audply_main_title.h,
        g_audply.title,
        mmi_audply_scroll_main_title_handler,
        mmi_audply_redraw_main_title_background,
        text_fg_color,
        text_border_color);
    audply_main_scrolling_title.text_font = MMI_medium_font;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);

    /* title */
    gui_scrolling_text_stop(&audply_main_scrolling_title);
    gui_set_font(&MMI_medium_font);
    gui_measure_string(g_audply.title, &w, &character_height);
    if (w > audply_main_title.w)
    {
        /* scrolling */
        gui_change_scrolling_text(&audply_main_scrolling_title, g_audply.title);
        gui_show_scrolling_text(&audply_main_scrolling_title);
    }
    else
    {
        /* background */
        mmi_audply_redraw_main_title_background(x1, y1, x2, y2);

        gui_push_text_clip();
        gui_set_text_clip(x1, y1, x2, y2);
        gui_set_text_color(text_fg_color);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + (audply_main_title.w + w) / 2, y1);
        }
        else
        {
            gui_move_text_cursor(x1 + (audply_main_title.w - w) / 2, y1);
        }
        gui_set_line_height(character_height);
        gui_print_text(g_audply.title);
        gui_pop_text_clip();
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_playlisticon
 * DESCRIPTION
 *  redraw audio player present play list icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_playlisticon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_playlisticon.x;
    S32 y1 = audply_main_playlisticon.y;
    S32 x2 = audply_main_playlisticon.x + audply_main_playlisticon.w - 1;
    S32 y2 = audply_main_playlisticon.y + audply_main_playlisticon.h - 1;
    U8 playlist ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_audply.present_list != (U8)MMI_PUBLIC_DRV)
    {
        playlist = LIST_FROM_CARD;
    }
    else
    {
        playlist = LIST_FROM_PHONE;
    }

    
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* play list icon */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, audply_main_playlisticon.list_icon[playlist]);
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_time
 * DESCRIPTION
 *  redraw audio player main time
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_time.x;
    S32 y1 = audply_main_time.y;
    S32 x2 = audply_main_time.x + audply_main_time.w - 1;
    S32 y2 = audply_main_time.y + audply_main_time.h - 1;
    S32 str_w, str_h;
    S8 temp[8];
    UI_character_type time_str[8];
    U32 elapsed_seconds = mmi_audply_get_play_seconds();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    elapsed_seconds /= 1000 ;
    sprintf(temp, "%02d:%02d", elapsed_seconds / 60, elapsed_seconds % 60);
    mmi_asc_to_ucs2((S8*) time_str, (S8*) temp);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & time */
    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(text_fg_color);
    gui_measure_string(time_str, &str_w, &str_h);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + (audply_main_time.w + str_w) / 2, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + (audply_main_time.w - str_w) / 2, y1 + 1);
    }
    gui_print_text(time_str);
    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_file_index
 * DESCRIPTION
 *  mmi_audply_redraw_main_file_index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_file_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_file_index.x;
    S32 y1 = audply_main_file_index.y;
    S32 x2 = audply_main_file_index.x + audply_main_file_index.w - 1;
    S32 y2 = audply_main_file_index.y + audply_main_file_index.h - 1;
    S32 str_w, str_h;
    S8 temp[24];
    UI_character_type file_index[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(temp, "%d/%d", g_audply.pick_index + 1, g_audply.n_total_items);
    mmi_asc_to_ucs2((S8*) file_index, (S8*) temp);

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & file index */
    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_set_text_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);
    gui_set_font(&MMI_small_font);
    gui_set_text_color(text_fg_color);
    gui_measure_string(file_index, &str_w, &str_h);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x1 + (audply_main_file_index.w + str_w) / 2, y1 + 1);
    }
    else
    {
        gui_move_text_cursor(x1 + (audply_main_file_index.w - str_w) / 2, y1 + 1);
    }
    gui_print_text(file_index);
    gui_pop_text_clip();
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_volumebar
 * DESCRIPTION
 *  redraw audio player main volume bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_volumebar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_volumebar.x;
    S32 y1 = audply_main_volumebar.y;
    S32 x2 = audply_main_volumebar.x + audply_main_volumebar.w - 1;
    S32 y2 = audply_main_volumebar.y + audply_main_volumebar.h - 1;
    U32 diff = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(audply_main_volumebar.bar_direction == HORIZONTAL_VOL_BAR )
    {
        diff = audply_main_volumebar.ind_len + 
             ((U32) g_audply.volume + 1) * (audply_main_volumebar.w - 
             audply_main_volumebar.ind_len) / MDI_AUD_VOL_EX_NUM;
        if (diff > (U32) audply_main_volumebar.w)
        {
            diff = (U32) audply_main_volumebar.w;
        }
    }
    else if(audply_main_volumebar.bar_direction == VERTICAL_VOL_BAR )
    {
        diff = audply_main_volumebar.ind_len + 
             ((U32) g_audply.volume + 1) * (audply_main_volumebar.h - 
             audply_main_volumebar.ind_len) / MDI_AUD_VOL_EX_NUM;
        if (diff > (U32) audply_main_volumebar.h)
        {
            diff = (U32) audply_main_volumebar.h;
        }
    }
    else
    {
        ASSERT(0);
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);
    if(audply_main_volumebar.bar_direction == HORIZONTAL_VOL_BAR)
    {
        gui_set_clip(x1, y1, x1 + diff, y2);
    }else
    {
        gui_set_clip(x1, y1+audply_main_volumebar.h-diff, x2, y2);
    }
    
    gui_show_image(x1, y1, audply_main_volumebar.ind_img);
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_volumectrl
 * DESCRIPTION
 *  redraw audio player main volume inc / dec control
 * PARAMETERS
 *  sel         [IN]        0 -> dec, 1 -> inc
 *  down        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_volumectrl(U8 sel, BOOL down)
{
/* because Land scape 128x128 and 128x160 without touch screen should not show volume ctrl buttons. */    
#if (((LCD_WIDTH > 128) && (LCD_HEIGHT > 160)) || ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160) && defined(__MMI_TOUCH_SCREEN__)))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    audply_main_volumectrl_struct *volumectrl_p = (sel == 0) ? &audply_main_volume_dec : &audply_main_volume_inc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = volumectrl_p->x;
    y1 = volumectrl_p->y;
    x2 = volumectrl_p->x + volumectrl_p->w - 1;
    y2 = volumectrl_p->y + volumectrl_p->h - 1;
    /* update the down state */
    volumectrl_p->down = down;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, (down ? volumectrl_p->down_img : volumectrl_p->up_img));
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_progressbar
 * DESCRIPTION
 *  redraw audio player main progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_progressbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_progressbar.x;
    S32 y1 = audply_main_progressbar.y;
    S32 x2 = audply_main_progressbar.x + audply_main_progressbar.w - 1;
    S32 y2 = audply_main_progressbar.y + audply_main_progressbar.h - 1;
    U32 dx ; 
    U32 elapsed_ms = mmi_audply_get_play_seconds();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration));

    dx = (U32)(audply_main_progressbar.w * ((float)elapsed_ms/(float)g_audply.duration)) ;

#ifdef __MMI_TOUCH_SCREEN__
    g_audply_progress_bar_current_x_pos = x1 + dx ;
#endif    

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, text_bg_color);

    if(g_audply.seekable)
    {
        gui_set_clip(x1, y1, x1 + dx, y2);
        if (elapsed_ms != 0)
        {
            gui_show_image(x1, y1, audply_main_progressbar.img);
        }
    }
    else
    {
        gui_set_clip(x1, y1, x2, y2);
        gui_show_image(x1, y1, audply_main_progressbar.img_fail);        
    }
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_proportional_time_from_x
 * DESCRIPTION
 *  calculate the proportional time of audio content from input coordinate
 * PARAMETERS
 *  void
 * RETURNS
 *  returns the current x coordinate
 *****************************************************************************/
S32 mmi_audply_get_current_x_coordinate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_audply_progress_bar_current_x_pos ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_proportional_time_from_x
 * DESCRIPTION
 *  calculate the proportional time of audio content from input coordinate
 * PARAMETERS
 *  cor_x         [IN]      x coordinate
 * RETURNS
 *  returns the proportional time according to the input x coordinate in ms
 *****************************************************************************/
U32 mmi_audply_get_proportional_time_from_x(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cor_x -= audply_main_progressbar.x ;
   
    if(cor_x<0)   /*in front of progress bar, set time to 0*/
    {
        return 0;
    }
    else if(cor_x > audply_main_progressbar.w)  /*in back of progress bar, set time to druation*/
    {
        return g_audply.duration;
    }
    else /*proportional time*/
    {
        return (U32)(g_audply.duration * ((float)cor_x / (float)audply_main_progressbar.w)) ;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_setting
 * DESCRIPTION
 *  redraw audio player main setting icon
 * PARAMETERS
 *  down        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_setting(BOOL down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = audply_main_setting.x;
    S32 y1 = audply_main_setting.y;
    S32 x2 = audply_main_setting.x + audply_main_setting.w - 1;
    S32 y2 = audply_main_setting.y + audply_main_setting.h - 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update the down state */
    audply_main_setting.down = down;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, (down ? audply_main_setting.down_img : audply_main_setting.up_img));
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_repeat
 * DESCRIPTION
 *  redraw audio player main repeat icon
 * PARAMETERS
 *  down        [IN]        to indicate weather the button is up or down.
 *                          down = TURE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_repeat(BOOL down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = (S32) audply_main_repeat.x;
    S32 y1 = (S32) audply_main_repeat.y;
    S32 x2 = x1 + audply_main_repeat.w - 1;
    S32 y2 = y1 + audply_main_repeat.h - 1;

    PU8 image_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update the down state */
    audply_main_repeat.down = down;

    switch (g_audply.repeat_mode)
    {
        case REPEAT_OFF:
            image_id = down ? audply_main_repeat.off_down_img : audply_main_repeat.off_up_img ; 
            break;
        case REPEAT_ALL:
            image_id = down ? audply_main_repeat.all_down_img: audply_main_repeat.all_up_img; 
            break;
        case REPEAT_ONE:
            image_id = down ? audply_main_repeat.one_down_img: audply_main_repeat.one_up_img; 
            break;
        default:
            ASSERT(0);
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, image_id);
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_repeat_toggle
 * DESCRIPTION
 *  handle the switching action among repear sates.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_repeat_toggle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 error ; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.repeat_mode = (g_audply.repeat_mode + 1)%3 ;
    WriteValue(NVRAM_AUDPLY_REPEAT, &g_audply.repeat_mode, DS_BYTE, &error);
    if ( g_audply.pick_index >= 0)
    {
        mmi_audply_start_playlist_at(g_audply.pick_index);
        mmi_audply_pick_playlist_at(g_audply.pick_index);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_shuffle
 * DESCRIPTION
 *  redraw audio player main shuffle icon
 * PARAMETERS
 *  down        [IN]        to indicate weather the button is up or down.
 *                          down = TURE
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_shuffle(BOOL down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = (S32) audply_main_shuffle.x;
    S32 y1 = (S32) audply_main_shuffle.y;
    S32 x2 = x1 + audply_main_shuffle.w - 1;
    S32 y2 = y1 + audply_main_shuffle.h - 1;

    PU8 image_id = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update the down state */
    audply_main_shuffle.down = down;

    switch (g_audply.random_mode)
    {
        case SHUFFLE_OFF:
            image_id = down ? audply_main_shuffle.off_down_img : audply_main_shuffle.off_up_img ; 
            break;
        case SHUFFLE_ON:
            image_id = down ? audply_main_shuffle.on_down_img: audply_main_shuffle.on_up_img; 
            break;
        default:
            ASSERT(0);
    }

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & indicator */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_show_image(x1, y1, image_id);
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_touch_repeat_toggle
 * DESCRIPTION
 *  handle the switching action among repear sates.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_touch_shuffle_toggle()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S16 error ; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.random_mode = (g_audply.random_mode + 1)%2 ;
    WriteValue(NVRAM_AUDPLY_SHUFFLE, &g_audply.random_mode, DS_BYTE, &error);
    if ( g_audply.pick_index >= 0)
    {
        mmi_audply_start_playlist_at(g_audply.pick_index);
        mmi_audply_pick_playlist_at(g_audply.pick_index);
    }
}
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
#endif /* __MMI_TOUCH_SCREEN__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_main_buttons
 * DESCRIPTION
 *  redraw audio player main buttons
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_main_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    /* background & buttons */
    gui_push_clip();
    gui_set_clip(audply_main_buttons_x1, audply_main_buttons_y1, audply_main_buttons_x2, audply_main_buttons_y2);
    for (i = 0; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
        if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
        {
            gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].disabled_img);
        }
        else if (g_audply_main_selected_button == i)
        {
            if (g_audply_main_selected_button_down)
            {
                gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].down_img);
            }
            else
            {
                gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].on_img);
            }
        }
        else
        {
            gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].off_img);
        }
    }
    if (g_audply_main_selected_button == AUDPLY_MAIN_PAUSE)
    {
        if (g_audply_main_selected_button_down)
        {
            gui_show_image(
                audply_main_buttons[AUDPLY_MAIN_PLAY].x,
                audply_main_buttons[AUDPLY_MAIN_PLAY].y,
                audply_main_pause_down_img);
        }
        else
        {
            gui_show_image(
                audply_main_buttons[AUDPLY_MAIN_PLAY].x,
                audply_main_buttons[AUDPLY_MAIN_PLAY].y,
                audply_main_pause_on_img);
        }
    }
    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        audply_main_buttons_x1,
        audply_main_buttons_y1,
        audply_main_buttons_x2,
        audply_main_buttons_y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
}

/* MTK Leo add 20050301, add touch screen support for Audio Player */
#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]mmi_audply_pen_down_hdlr");
    
    audply_pen_event_on_object = AUDPLY_PEN_NONE;

    for (i = AUDPLY_PEN_LSK; i < AUDPLY_PEN_COUNT; i++)
    {
        switch (i)
        {
            case AUDPLY_PEN_LSK:
                area = (mmi_pen_polygon_area_struct*) & LSK_area;
                point = pos;
                break;
            case AUDPLY_PEN_RSK:
                area = (mmi_pen_polygon_area_struct*) & RSK_area;
                point = pos;
                break;
            case AUDPLY_PEN_SEEK:
                area = (mmi_pen_polygon_area_struct*) & skin_p->seek_area;
                point.x = pos.x - skin_p->progressbar_x;
                point.y = pos.y - skin_p->progressbar_y;
                break;
            case AUDPLY_PEN_MAIN_PREV:
                area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
                point.x = pos.x - skin_p->prev_button_x;
                point.y = pos.y - skin_p->prev_button_y;
                break;
            case AUDPLY_PEN_MAIN_NEXT:
                area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
                point.x = pos.x - skin_p->next_button_x;
                point.y = pos.y - skin_p->next_button_y;
                break;
            case AUDPLY_PEN_MAIN_STOP:
                area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
                point.x = pos.x - skin_p->stop_button_x;
                point.y = pos.y - skin_p->stop_button_y;
                break;
            case AUDPLY_PEN_MAIN_PLAY:
                area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
                point.x = pos.x - skin_p->play_button_x;
                point.y = pos.y - skin_p->play_button_y;
                break;
            case AUDPLY_PEN_MAIN_SETTING:
                area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
                point.x = pos.x - skin_p->setting_x;
                point.y = pos.y - skin_p->setting_y;
                break;
        #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__                
            case AUDPLY_PEN_MAIN_REPEAT:
                area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
                point.x = pos.x - skin_p->repeat_x;
                point.y = pos.y - skin_p->repeat_y;
                break;
            case AUDPLY_PEN_MAIN_SHUFFLE:
                area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
                point.x = pos.x - skin_p->shuffle_x;
                point.y = pos.y - skin_p->shuffle_y;
                break;
        #endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
            case AUDPLY_PEN_MAIN_VOLUME_INC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
                point.x = pos.x - skin_p->volume_inc_x;
                point.y = pos.y - skin_p->volume_inc_y;
                break;
            case AUDPLY_PEN_MAIN_VOLUME_DEC:
                area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
                point.x = pos.x - skin_p->volume_dec_x;
                point.y = pos.y - skin_p->volume_dec_y;
                break;
        }
        if (mmi_pen_check_inside_polygon(area, point))
        {
            audply_pen_event_on_object = i;
            break;
        }
    }

    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_LSK:
            mmi_audply_redraw_LSK_down();
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            break;
        case AUDPLY_PEN_RSK:
            mmi_audply_redraw_RSK_down();
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            break;
        case AUDPLY_PEN_SEEK:
            if(g_audply.seekable)
            {
                g_audply_progress_bar_pen_down_x_pos = pos.x ;
                mmi_audply_touch_progress_hdlr(pos.x);
            }
            break;
        case AUDPLY_PEN_MAIN_PREV:
            mmi_audply_press_prev_button_down();
            break;
        case AUDPLY_PEN_MAIN_NEXT:
            mmi_audply_press_next_button_down();
            break;
        case AUDPLY_PEN_MAIN_STOP:
            mmi_audply_press_stop_button_down();
            break;
        case AUDPLY_PEN_MAIN_PLAY:
            mmi_audply_press_play_button_down();
            break;
        case AUDPLY_PEN_MAIN_SETTING:
            mmi_audply_redraw_main_setting(TRUE);
            break;
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
        case AUDPLY_PEN_MAIN_REPEAT:
            mmi_audply_redraw_main_repeat(TRUE);
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            mmi_audply_redraw_main_shuffle(TRUE);
            break;            
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            mmi_audply_redraw_main_volumectrl(1, TRUE);
            break;
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            mmi_audply_redraw_main_volumectrl(0, TRUE);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]mmi_audply_pen_up_hdlr");
    
    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_SEEK:
            if(g_audply.seekable)
            {
                mmi_audply_touch_progress_pen_up();
            }
            break;
        case AUDPLY_PEN_MAIN_NEXT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
            point.x = pos.x - skin_p->next_button_x;
            point.y = pos.y - skin_p->next_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_next_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_PREV:
            area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
            point.x = pos.x - skin_p->prev_button_x;
            point.y = pos.y - skin_p->prev_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_prev_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
            point.x = pos.x - skin_p->stop_button_x;
            point.y = pos.y - skin_p->stop_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_stop_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_PLAY:
            area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
            point.x = pos.x - skin_p->play_button_x;
            point.y = pos.y - skin_p->play_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_play_button_up();
            }
            break;
        case AUDPLY_PEN_MAIN_SETTING:
            area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
            point.x = pos.x - skin_p->setting_x;
            point.y = pos.y - skin_p->setting_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {    
                mmi_audply_redraw_main_setting(FALSE);                
                if (AUDPLY_SETTING_ITEM_COUNT <= 10)
                {
                    mmi_audply_entry_settings();
                }
                else
                {
                    mmi_audply_entry_two_layers_settings();
                }  
            }
            break;
    #ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__
        case AUDPLY_PEN_MAIN_REPEAT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
            point.x = pos.x - skin_p->repeat_x;
            point.y = pos.y - skin_p->repeat_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_touch_repeat_toggle();
                mmi_audply_redraw_main_repeat(FALSE);
            }
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
            point.x = pos.x - skin_p->shuffle_x;
            point.y = pos.y - skin_p->shuffle_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_touch_shuffle_toggle();
                mmi_audply_redraw_main_shuffle(FALSE);
            }
            break;            
    #endif /* __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__ */            
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
            point.x = pos.x - skin_p->volume_dec_x;
            point.y = pos.y - skin_p->volume_dec_y;
            mmi_audply_redraw_main_volumectrl(0, FALSE);
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_dec_volume();
            }
            break;
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
            point.x = pos.x - skin_p->volume_inc_x;
            point.y = pos.y - skin_p->volume_inc_y;
            mmi_audply_redraw_main_volumectrl(1, FALSE);
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_inc_volume();
            }
            break;
        case AUDPLY_PEN_LSK:
            mmi_audply_redraw_LSK_up();
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            break;
        case AUDPLY_PEN_RSK:
            mmi_audply_redraw_RSK_up();
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    mmi_pen_polygon_area_struct *area = NULL;
    const audply_skin_struct *skin_p = &g_audply_skins[g_audply.skin];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_MMI_MEDIA_APP,"[Audply]mmi_audply_pen_move_hdlr");

    switch (audply_pen_event_on_object)
    {
        case AUDPLY_PEN_SEEK:
            if(g_audply.seekable)
            {
                PRINT_INFORMATION("Audply Touch Progress Bar: Pen Move");
                mmi_audply_touch_progress_seeking(pos.x);
            }
            break;
		case AUDPLY_PEN_MAIN_NEXT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->next_button_area;
            point.x = pos.x - skin_p->next_button_x;
            point.y = pos.y - skin_p->next_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_next_button_down();
            }
            else
            {
                if (g_audply.in_main_screen)
                {
                    g_audply_main_selected_button_down = FALSE;
                    /* when stop button down, the play button will be switched to play icon
                       but, if the stylus is moved out of the button, it shall switch back to 
                       pause icon.*/
                    if(g_audply.state == STATE_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }                    
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
		case AUDPLY_PEN_MAIN_PREV:
            area = (mmi_pen_polygon_area_struct*) & skin_p->prev_button_area;
            point.x = pos.x - skin_p->prev_button_x;
            point.y = pos.y - skin_p->prev_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_prev_button_down();
            }else
            {                
                if (g_audply.in_main_screen)
                {
                    g_audply_main_selected_button_down = FALSE;
                    /* when stop button down, the play button will be switched to play icon
                       but, if the stylus is moved out of the button, it shall switch back to 
                       pause icon.*/
                    if(g_audply.state == STATE_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }                    
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
		case AUDPLY_PEN_MAIN_STOP:
            area = (mmi_pen_polygon_area_struct*) & skin_p->stop_button_area;
            point.x = pos.x - skin_p->stop_button_x;
            point.y = pos.y - skin_p->stop_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_press_stop_button_down();
            }
            else
            {
                if (g_audply.in_main_screen)
                {
                    g_audply_main_selected_button_down = FALSE;
                    /* when stop button down, the play button will be switched to play icon
                       but, if the stylus is moved out of the button, it shall switch back to 
                       pause icon.*/
                    if(g_audply.state == STATE_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
		case AUDPLY_PEN_MAIN_PLAY:
            area = (mmi_pen_polygon_area_struct*) & skin_p->play_button_area;
            point.x = pos.x - skin_p->play_button_x;
            point.y = pos.y - skin_p->play_button_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                g_audply_main_pen_move_more_than_once = FALSE;
                mmi_audply_press_play_button_down();
            }else
            {
                if (g_audply.in_main_screen && !g_audply_main_pen_move_more_than_once)
                {
                    g_audply_main_selected_button_down = FALSE;
                    g_audply_main_pen_move_more_than_once = TRUE ;
                    if(g_audply_main_selected_button == AUDPLY_MAIN_PAUSE)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
                    }
                    else if(g_audply_main_selected_button == AUDPLY_MAIN_PLAY)
                    {
                        g_audply_main_selected_button = AUDPLY_MAIN_PAUSE;
                    }
                    mmi_audply_redraw_main_buttons();
                }
            }
			break;
        case AUDPLY_PEN_MAIN_SETTING:
            area = (mmi_pen_polygon_area_struct*) & skin_p->setting_area;
            point.x = pos.x - skin_p->setting_x;
            point.y = pos.y - skin_p->setting_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_setting(TRUE);
            }else
            {
                mmi_audply_redraw_main_setting(FALSE);
            }           
            break;
#ifdef __MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__                
        case AUDPLY_PEN_MAIN_REPEAT:
            area = (mmi_pen_polygon_area_struct*) & skin_p->repeat_area;
            point.x = pos.x - skin_p->repeat_x;
            point.y = pos.y - skin_p->repeat_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_repeat(TRUE);
            }else
            {
                mmi_audply_redraw_main_repeat(FALSE);
            }
            break;
        case AUDPLY_PEN_MAIN_SHUFFLE:
            area = (mmi_pen_polygon_area_struct*) & skin_p->shuffle_area;
            point.x = pos.x - skin_p->shuffle_x;
            point.y = pos.y - skin_p->shuffle_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_shuffle(TRUE);
            }else
            {
                mmi_audply_redraw_main_shuffle(FALSE);
            }
            break;
#endif /*__MMI_AUDIO_PLAYER_SKIN_SHOW_REPEAT_SHUFFLE__*/
        case AUDPLY_PEN_MAIN_VOLUME_INC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_inc_area;
            point.x = pos.x - skin_p->volume_inc_x;
            point.y = pos.y - skin_p->volume_inc_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_volumectrl(1, TRUE);
            }else
            {
                mmi_audply_redraw_main_volumectrl(1, FALSE);
            }
            break;
        case AUDPLY_PEN_MAIN_VOLUME_DEC:
            area = (mmi_pen_polygon_area_struct*) & skin_p->volume_dec_area;
            point.x = pos.x - skin_p->volume_dec_x;
            point.y = pos.y - skin_p->volume_dec_y;
            if (mmi_pen_check_inside_polygon(area, point))
            {
                mmi_audply_redraw_main_volumectrl(0, TRUE);
            }else
            {
                mmi_audply_redraw_main_volumectrl(0, FALSE);
            }
            break;
        case AUDPLY_PEN_LSK:
            if (mmi_pen_check_inside_polygon(&LSK_area, pos))
            {
                mmi_audply_redraw_LSK_down();
            }
            else
            {
                mmi_audply_redraw_LSK_up();
            }
            break;
        case AUDPLY_PEN_RSK:
            if (mmi_pen_check_inside_polygon(&RSK_area, pos))
            {
                mmi_audply_redraw_RSK_down();
            }
            else
            {
                mmi_audply_redraw_RSK_up();
            }
            break;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* MTK Leo end */

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_spectrum_display_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_spectrum_display_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* start calc top and vals */
    mmi_audply_calc_spectrum(TRUE);
    mmi_audio_spectrum_init_display(&g_aud_ply_spectrum);
    mmi_audio_spectrum_start_display(&g_aud_ply_spectrum);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_spectrum_display_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_spectrum_display_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_SUBLCD__)
    /* stop calc top and vals */
    mmi_audply_calc_spectrum(FALSE);
#endif /* !defined(__MMI_SUBLCD__) */ 
    mmi_audio_spectrum_stop_display(&g_aud_ply_spectrum);
}
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 

#ifdef __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_stop_scroll_lyric_and_clean_screen
 * DESCRIPTION
 *  to stop the scrolling lyric and replace with transparent color
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_stop_scroll_lyric_and_clean_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_audply.lyrics_display && g_audply.in_main_screen && g_audply_lyrics_valid && !mmi_is_redrawing_bk_screens())
    {
        /* clean the screen */
        if (audply_scrolling_lyric_p1)
        {
            gui_scrolling_text_stop(audply_scrolling_lyric_p1);
            audply_scrolling_lyric_p1 = NULL;
        }
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_push_and_set_active(audply_lyric_print.target_layer);
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_lock_frame_buffer();
    #endif 
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);
        mmi_audply_redraw_lyric_background(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);

        gdi_layer_pop_clip();
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_lyric_background
 * DESCRIPTION
 *  redraw audio player lyric  background
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_lyric_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_scroll_lyric_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_scroll_lyric_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_scrolling_lyric_p1)
    {
        gui_handle_scrolling_text(audply_scrolling_lyric_p1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_redraw_lyric
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_redraw_lyric()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #ifdef __MMI_SUBLCD__
    if (audply_lyric.is_ready && audply_lyric.cur_line)
    {

        S32 x, y;           /* the cursor position */
        S32 str_w, str_h;   /* the lyric width and height */

        /* S32 next_line_time; */
        audply_lyric_line_struct *cur_line = audply_lyric.cur_line;

        /* S32          scorll_time = 500; */
        bitmap *saved_graphics_context = current_LCD_device_bitmap;

        //              mmi_audply_set_subLCD_shown( TRUE );
        //              UI_set_sub_LCD_graphics_context();

    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_push_and_set_active(audply_lyric_print.target_layer);
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 
    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_lock_frame_buffer();
    #endif 
        gdi_layer_push_clip();

        gdi_layer_set_clip(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);

        if (audply_scrolling_lyric_p1)  /* if there is some scroll lyric, make it stop no matter how. */
        {
            gui_scrolling_text_stop(audply_scrolling_lyric_p1);
            audply_scrolling_lyric_p1 = NULL;
        }

        if (cur_line->line_lyric1)
        {
            gui_set_font(&MMI_medium_font);
            gui_measure_string((UI_string_type) cur_line->line_lyric1, &str_w, &str_h);
            y = audply_lyric_print.start_y + audply_lyric_print.height / 2 - str_h / 2;
            y = y-2 ; /*for bordered*/
            x = audply_lyric_print.start_x + 2  ;  /* +2 to prevent bordered char from exceeding the edge*/

            mmi_audply_redraw_lyric_background(
                audply_lyric_print.start_x,
                audply_lyric_print.start_y,
                audply_lyric_print.start_x + audply_lyric_print.width,
                audply_lyric_print.start_y + audply_lyric_print.height);

            if (str_w <= audply_lyric_print.width - 2)
            {
                S32 temp_x;

                gui_push_text_clip();
                /* gui_set_text_clip( audply_lyric_print.start_x, y-str_h/2-1,  audply_lyric_print.start_x+ audply_lyric_print.width, y + str_h/2+1 ); */
                gui_set_text_clip(x, y, x + audply_lyric_print.width, y + str_h + 4); /* y+4 for bordered lyrics */
                gui_set_text_color(audply_lyric_print.lyric_fg_color);
                gui_set_text_border_color(audply_lyric_print.lyric_border_color);
                if (r2lMMIFlag)
                {
                    temp_x = x + (audply_lyric_print.width + str_w) / 2;
                }
                else
                {
                    temp_x = x + (audply_lyric_print.width - str_w) / 2;
                }
                gui_move_text_cursor(temp_x, y+2);
                //gui_print_text((UI_string_type) cur_line->line_lyric1);
                gui_print_bordered_text((UI_string_type) cur_line->line_lyric1);
                gui_pop_text_clip();
            }
            else    /* scroll */
            {
                audply_scrolling_lyric_p1 = &audply_scrolling_lyric1;
                gui_create_scrolling_text(
                    audply_scrolling_lyric_p1,
                    x,
                    y+2,
                    audply_lyric_print.width-4,   /* -4 to prevent bordered wrods from exceeding the edge*/
                    str_h,
                    (UI_string_type) cur_line->line_lyric1,
                    mmi_audply_scroll_lyric_handler,
                    mmi_audply_redraw_lyric_background,
                    audply_lyric_print.lyric_fg_color,
                    audply_lyric_print.lyric_border_color);

                audply_scrolling_lyric_p1->text_font = MMI_medium_font;
                audply_scrolling_lyric_p1->scroll_size = 3; /* the pixel number of each scroll action. */
                audply_scrolling_lyric_p1->scroll_time = 200;   /* in ms. the time between each scroll action. */
                audply_scrolling_lyric_p1->scroll_pause = 5;    /* the pause time after showing the lyric and strat to scroll.
                                                                   the time is scroll_time*scroll_pause ; */
                audply_scrolling_lyric_p1->flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
                /* audply_scrolling_lyric_p1->scroll_gap = 32 ;  */
                /* while the whole lyric is scroll over, it should re-appear by scrolling out.
                   this is the gap in pixels between the re-appear scrolling out */

                gui_show_scrolling_text(audply_scrolling_lyric_p1);

            }
        }
        else
        {
            mmi_audply_redraw_lyric_background(
                audply_lyric_print.start_x,
                audply_lyric_print.start_y,
                audply_lyric_print.start_x + audply_lyric_print.width,
                audply_lyric_print.start_y + audply_lyric_print.height);
        }

        gdi_layer_pop_clip();

    #if(UI_DOUBLE_BUFFER_SUPPORT)
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(
            audply_lyric_print.start_x,
            audply_lyric_print.start_y,
            audply_lyric_print.start_x + audply_lyric_print.width,
            audply_lyric_print.start_y + audply_lyric_print.height);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

    #ifdef __GDI_MEMORY_PROFILE_2__
        if (audply_lyric_print.target_layer)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif /* __GDI_MEMORY_PROFILE_2__ */ 

        if (saved_graphics_context == &main_LCD_device_bitmap)
        {
            UI_set_main_LCD_graphics_context();
        }
        else if (saved_graphics_context == &sub_LCD_device_bitmap)
        {
            UI_set_sub_LCD_graphics_context();
        }
    }
    // #endif // __MMI_SUBLCD__
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lyric_on_time
 * DESCRIPTION
 *  called during every update_play_seconds() to manipulate the whole action of audply lyrics.
 * PARAMETERS
 *  void
 *  BOOL is_show(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_lyric_on_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (audply_lyric.is_ready && audply_lyric.cur_line)
    {
        S32 next_line_time = 0;
        S32 play_time = mmi_audply_get_play_seconds() - audply_lyric.offset_time;
        audply_lyric_line_struct *cur_line = audply_lyric.first_line;

        if (audply_lyric.cur_line->next)
        {
            next_line_time = audply_lyric.cur_line->next->time;
        }
        else
        {
            next_line_time = 0xffffff;
        }
        if (play_time >= audply_lyric.cur_line->time && play_time < next_line_time)
        {
            if (!lyric_reEntry)
            {
                return;
            }
            else
            {
                lyric_reEntry = FALSE;
            }
        }
        
        if (play_time < audply_lyric.first_line->time)
        {
            return;
        }
        
        while (cur_line)
        {
            if (cur_line->next)
            {
                if (play_time >= cur_line->time && play_time < cur_line->next->time)
                {
                    audply_lyric.cur_line = cur_line;
                    next_line_time = cur_line->next->time;
                    break;
                }
                else
                {
                    cur_line = cur_line->next;
                }
            }
            else
            {
                audply_lyric.cur_line = cur_line;
                next_line_time = 0xffffff;
                break;
            }
        }
        PRINT_INFORMATION("AUDPLY: Print Lrics, time=%d\n",g_audply.new_play_time);
        mmi_audply_redraw_lyric();
    }
}

#endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
#ifdef __MMI_AUDIO_PLAYER_ON_SUBLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_redraw_main_buttons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_sub_audply_redraw_main_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num_of_button;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    num_of_button = NO_OF_AUDPLY_MAIN_BUTTONS -1;

    #if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
    #endif 
    
    /* background & buttons */
     gui_push_clip();
    gui_set_clip(audply_main_buttons_x1, audply_main_buttons_y1, audply_main_buttons_x2, audply_main_buttons_y2);
    for (i = 0; i < num_of_button; i++)
    {
        if(g_audply.state == STATE_PLAY)
		{
			g_audply_main_selected_button = AUDPLY_MAIN_PAUSE;
		}
        if((g_audply.state == STATE_IDLE) &&(g_audply.n_total_items != 0))
        {
        
            g_audply_main_selected_button = AUDPLY_MAIN_PLAY;//12.2 zhongwu
        }
		if (g_audply_main_selected_button == AUDPLY_MAIN_DISABLED)
        {
            gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].disabled_img);
        }
        else if(g_audply_main_selected_button == i)
        {
             if(g_audply_main_selected_button_down)
             {
                gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].down_img);
             }
             else
             {
                 gui_show_image(audply_main_buttons[i].x, audply_main_buttons[i].y, audply_main_buttons[i].on_img);
             }
        }

    }
    if (g_audply_main_selected_button == AUDPLY_MAIN_PAUSE)
    {
        if (g_audply_main_selected_button_down)
        {
            gui_show_image(
                audply_main_buttons[AUDPLY_MAIN_PLAY].x,
                audply_main_buttons[AUDPLY_MAIN_PLAY].y,
                audply_main_pause_down_img);
        }
        else
        {
            gui_show_image(
                audply_main_buttons[AUDPLY_MAIN_PLAY].x,
                audply_main_buttons[AUDPLY_MAIN_PLAY].y,
                audply_main_pause_on_img);
        }
    }
    gui_pop_clip();
    
    #if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
            audply_main_buttons_x1,
            audply_main_buttons_y1,
            audply_main_buttons_x2,
            audply_main_buttons_y2);
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_redraw_main_push_buttons
 * DESCRIPTION
 *  redraw audio player push buttons on sublcd
 * PARAMETERS
 *  U8 button
 *  BOOL is_down
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_sub_audply_redraw_main_push_buttons(U8 button, BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audply_main_button_struct *push_button_p;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case AUDPLY_MAIN_PREV:
            push_button_p = &audply_main_buttons[AUDPLY_MAIN_PREV];
            break;
        case AUDPLY_MAIN_NEXT:
            push_button_p = &audply_main_buttons[AUDPLY_MAIN_NEXT];
            break;
        default:
            return;
    }
    x1 = push_button_p->x;
    y1 = push_button_p->y;
    x2 = push_button_p->x + push_button_p->w - 1;
    y2 = push_button_p->y + push_button_p->h - 1;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

    /* button */
    if (is_down)
    {
        gui_show_image(x1, y1, push_button_p->down_img);
    }
    else
    {
        gui_show_image(x1, y1, push_button_p->on_img);
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */     
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_redraw_main_toggle_buttons
 * DESCRIPTION
 *  redraw audio player toggle buttons on sublcd
 * PARAMETERS
 *  U8 button
 *  BOOL is_down
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_sub_audply_redraw_main_toggle_buttons(U8 button, BOOL is_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audply_main_button_struct *push_button_p;
    S32 x1, y1, x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (button)
    {
        case AUDPLY_MAIN_PLAY:
            push_button_p = &audply_main_buttons[AUDPLY_MAIN_PLAY];
            break;
        case AUDPLY_MAIN_PAUSE:
            push_button_p = &audply_main_buttons[AUDPLY_MAIN_PLAY];
            break;
        default:
            return;
    }
    x1 = push_button_p->x;
    y1 = push_button_p->y;
    x2 = push_button_p->x + push_button_p->w - 1;
    y2 = push_button_p->y + push_button_p->h - 1;

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_lock_double_buffer();
#endif 

    gui_push_clip();

    gui_set_clip(x1, y1, x2, y2);

    /* button */
    if (is_down)
    {
        if(button == AUDPLY_MAIN_PLAY)
			gui_show_image(x1,y1,push_button_p->down_img);
         
              
        else
            gui_show_image(x1, y1, audply_main_pause_down_img);
    }
    else
    {
        if(button == AUDPLY_MAIN_PLAY)
            gui_show_image(x1, y1, audply_main_pause_on_img);
        else
            gui_show_image(x1, y1,push_button_p->on_img);
    }

    gui_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(x1, y1, x2, y2);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */     
}    

/*****************************************************************************
 * FUNCTION
 *  mmi_sub_audply_init_main_screen_images
 * DESCRIPTION
 *  init audio player main screen images of sublcd
 * PARAMETERS
 *  skin        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sub_audply_init_main_screen_images(S8 skin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const audply_sub_skin_struct *skin_p = &g_audply_skins_sub[skin];

    S32 i, w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* bg */       
    audply_main_bg_img = (PU8) GetImage(skin_p->bg_image_id);

    /* text_border_color, text fg, bg color */
    text_border_color = gui_color(skin_p->text_border_color_r, skin_p->text_border_color_g, skin_p->text_border_color_b);
    text_fg_color = gui_color(skin_p->text_fg_color_r, skin_p->text_fg_color_g, skin_p->text_fg_color_b);
#ifdef __GDI_MEMORY_PROFILE_2__
    text_bg_color = GDI_COLOR_TRANSPARENT ;   /* transparent */
#else 
    text_bg_color = gdi_act_color_from_rgb(255,skin_p->text_bg_color_r, skin_p->text_bg_color_g, skin_p->text_bg_color_b);
#endif 

    /* title */
    audply_main_title.x = skin_p->title_x;
    audply_main_title.y = skin_p->title_y;
    audply_main_title.w = skin_p->title_w;
    audply_main_title.h = skin_p->title_h;

    /* time */
    audply_main_time.x = skin_p->time_x;
    audply_main_time.y = skin_p->time_y;
    audply_main_time.w = skin_p->time_w;
    audply_main_time.h = skin_p->time_h;

    /* file index */
    audply_main_file_index.x = skin_p->file_index_x;
    audply_main_file_index.y = skin_p->file_index_y;
    audply_main_file_index.w = skin_p->file_index_w;
    audply_main_file_index.h = skin_p->file_index_h;

    /* play list icon */
    audply_main_playlisticon.x = skin_p->playlisticon_x;
    audply_main_playlisticon.y = skin_p->playlisticon_y;
    audply_main_playlisticon.list_icon[LIST_FROM_PHONE] =
        (PU8) GetImage(skin_p->playlisticon_images_id[LIST_FROM_PHONE]);
    audply_main_playlisticon.list_icon[LIST_FROM_CARD] = (PU8) GetImage(skin_p->playlisticon_images_id[LIST_FROM_CARD]);
    gui_measure_image(audply_main_playlisticon.list_icon[LIST_FROM_PHONE], &w, &h);
    audply_main_playlisticon.w = (S16) w;
    audply_main_playlisticon.h = (S16) h;

    /* volume */
    audply_main_volumebar.x = skin_p->volumebar_x;
    audply_main_volumebar.y = skin_p->volumebar_y;
    audply_main_volumebar.ind_len = skin_p->volumebar_ind_len;
    audply_main_volumebar.ind_img = (PU8) GetImage(skin_p->volumebar_ind_image_id);
    gui_measure_image(audply_main_volumebar.ind_img, &w, &h);
    audply_main_volumebar.w = (S16) w;
    audply_main_volumebar.h = (S16) h;
    audply_main_volumebar.bar_direction = 0;

    /* play, pause, stop, prev, next buttons */
    audply_main_buttons[AUDPLY_MAIN_PREV].x = skin_p->prev_button_x;
    audply_main_buttons[AUDPLY_MAIN_PREV].y = skin_p->prev_button_y;
    audply_main_buttons[AUDPLY_MAIN_PREV].on_img = (PU8) GetImage(skin_p->prev_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].off_img = (PU8) GetImage(skin_p->prev_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].disabled_img = (PU8) GetImage(skin_p->prev_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_PREV].down_img = (PU8) GetImage(skin_p->prev_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_NEXT].x = skin_p->next_button_x;
    audply_main_buttons[AUDPLY_MAIN_NEXT].y = skin_p->next_button_y;
    audply_main_buttons[AUDPLY_MAIN_NEXT].on_img = (PU8) GetImage(skin_p->next_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].off_img = (PU8) GetImage(skin_p->next_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].disabled_img = (PU8) GetImage(skin_p->next_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_NEXT].down_img = (PU8) GetImage(skin_p->next_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_PLAY].x = skin_p->play_button_x;
    audply_main_buttons[AUDPLY_MAIN_PLAY].y = skin_p->play_button_y;
    audply_main_buttons[AUDPLY_MAIN_PLAY].on_img = (PU8) GetImage(skin_p->play_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].off_img = (PU8) GetImage(skin_p->play_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].disabled_img = (PU8) GetImage(skin_p->play_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_PLAY].down_img = (PU8) GetImage(skin_p->play_button_down_image_id);
    audply_main_pause_on_img = (PU8) GetImage(skin_p->pause_button_on_image_id);
    audply_main_pause_down_img = (PU8) GetImage(skin_p->pause_button_down_image_id);

    audply_main_buttons[AUDPLY_MAIN_STOP].x = skin_p->stop_button_x;
    audply_main_buttons[AUDPLY_MAIN_STOP].y = skin_p->stop_button_y;
    audply_main_buttons[AUDPLY_MAIN_STOP].on_img = (PU8) GetImage(skin_p->stop_button_on_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].off_img = (PU8) GetImage(skin_p->stop_button_off_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].disabled_img = (PU8) GetImage(skin_p->stop_button_disabled_image_id);
    audply_main_buttons[AUDPLY_MAIN_STOP].down_img = (PU8) GetImage(skin_p->stop_button_down_image_id);

    /* calculate buttons boundary */
    gui_measure_image(audply_main_buttons[0].on_img, &w, &h);
    audply_main_buttons[0].w = (S16) w;
    audply_main_buttons[0].h = (S16) h;
    audply_main_buttons_x1 = audply_main_buttons[0].x;
    audply_main_buttons_y1 = audply_main_buttons[0].y;
    audply_main_buttons_x2 = audply_main_buttons[0].x + w - 1;
    audply_main_buttons_y2 = audply_main_buttons[0].y + h - 1;
    for (i = 1; i < NO_OF_AUDPLY_MAIN_BUTTONS; i++)
    {
        gui_measure_image(audply_main_buttons[i].on_img, &w, &h);
        audply_main_buttons[i].w = (S16) w;
        audply_main_buttons[i].h = (S16) h;
        if (audply_main_buttons[i].x < audply_main_buttons_x1)
        {
            audply_main_buttons_x1 = audply_main_buttons[i].x;
        }
        if (audply_main_buttons[i].y < audply_main_buttons_y1)
        {
            audply_main_buttons_y1 = audply_main_buttons[i].y;
        }
        if (audply_main_buttons[i].x + w - 1 > audply_main_buttons_x2)
        {
            audply_main_buttons_x2 = audply_main_buttons[i].x + w - 1;
        }
        if (audply_main_buttons[i].y + h - 1 > audply_main_buttons_y2)
        {
            audply_main_buttons_y2 = audply_main_buttons[i].y + h - 1;
        }
    }

}
#endif

#endif /* __MMI_AUDIO_PLAYER__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_display_popup
 * DESCRIPTION
 *  call display pop up with corresponding parameter with the result
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_display_popup(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if(mmi_audply_err_img_tone(result))
    {
        DisplayPopup((PU8) GetString(mmi_audply_err_str(result)), IMG_GLOBAL_ERROR, 0, 1000, (U8) ERROR_TONE);
    }
    else
    {
        DisplayPopup((PU8) GetString(mmi_audply_err_str(result)), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);   
    }

}