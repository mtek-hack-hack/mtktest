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
 *  SlideShow.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Slide Show Applcation Source of PhotoEditor
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
#ifdef __MMI_SLIDESHOW__

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
#include "Conversions.h"        /* short file name conversion */
#include "PhoneSetupGprots.h"   /* encoding type */
#include "lcd_if.h"
#include "MainMenuDef.h"
#include "lcd_sw_rnd.h"
#include "med_api.h"    /* media task camera module */
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "SlideShowResDef.h"
#include "SlideShow.h"
#include "SlideShowMem.h"

#include "MMI_features_camera.h"
#include "CameraResDef.h"      /* for camrea error string */
#include "mdi_audio.h"
#include "MessagesExDcl.h"
#include "AudioPlayerProt.h"

#ifdef __MMI_VIDEO_PLAYER__
#include "mdi_video.h"  /* video */
#ifdef __MMI_SUBLCD__
#include "VdoPlyResDef.h" /* for drawing sublcd icon */
#endif
#endif /* __MMI_VIDEO_PLAYER__ */

#include "gpioInc.h"    /* LED related */

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"     /* mdi tvout */
#include "WallpaperDefs.h"      /* some header for phonsetup.h */
#include "DownloadDefs.h"       /* some header for phonsetup.h */
#include "PhoneSetup.h" /* tvout display style */
#endif /* __MMI_TVOUT__ */
#include <ctype.h>

#ifdef __SLIDESHOW_USE_APP_ASM__
#endif


/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern BOOL r2lMMIFlag;

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
extern pBOOL mmi_usb_check_path_exported(S8 *path);
extern void mmi_fmgr_kernel_set_cur_idx(S32 index);


/*****************************************************************************
* Local Vairable                                                           
*****************************************************************************/

static slidshow_cntx_struct g_slidshow_cntx;


static S32 resume_index;
static S32 lcd_width = 0;
static S32 lcd_height = 0;

#ifdef __SLIDESHOW_USE_APP_ASM__
PU8 g_slidshow_layer1_buffer;
PU8 g_slidshow_layer2_buffer;
#else /* __SLIDESHOW_USE_APP_ASM__ */
U8 g_slidshow_layer1_buffer[SLIDESHOW_FRAME_BUFFER_SIZE];
U8 g_slidshow_layer2_buffer[SLIDESHOW_FRAME_BUFFER_SIZE];
#endif /* __SLIDESHOW_USE_APP_ASM__ */

#ifdef __MMI_TOUCH_SCREEN__
static slidshow_touch_screen_context_struct g_slidshow_touch_screen_cntx;
#endif 

U8 g_slidshow_option_bgm_hilight_index;
U8 g_slidshow_option_bgm_select_file_hilight_index;

/*****************************************************************************
* Local Function                                                           
*****************************************************************************/
/* app related */
static void mmi_slidshow_hilight_app(void);
static void mmi_slideshow_entry_app(void);
static void mmi_slidshow_entry_select_folder(void);
void mmi_slidshow_fmgr_select_result_callback(void *filepath, int is_short);

static void mmi_slidshow_entry_option_screen(void);
static void mmi_slidshow_hilight_play(void);
static void mmi_slidshow_entry_play_screen(void);

static void mmi_slidshow_entry_image_display_screen(void);
static void mmi_slidshow_exit_image_display_screen(void);

static void mmi_slidshow_right_arrow_press(void);
static void mmi_slidshow_right_arrow_release(void);
static void mmi_slidshow_left_arrow_press(void);
static void mmi_slidshow_left_arrow_release(void);

static void mmi_slidshow_main_draw_osd(void);
static void mmi_slidshow_draw_softkey(PS8 lsk_str, PS8 rsk_str, BOOL is_clear_bg);

static void mmi_slidshow_end_key_press(void);
static void mmi_slidshow_lsk_press(void);
static void mmi_slidshow_show_press_release_softkey(void);
static void mmi_slidshow_lsk_release(void);
static void mmi_slidshow_rsk_press(void);
static void mmi_slidshow_rsk_release(void);

static void mmi_slidshow_hilight_resume(void);
static void mmi_slidshow_entry_resume_screen(void);

static void mmi_slidshow_hilight_setting(void);
static void mmi_slidshow_entry_setting_screen(void);
static void mmi_slidshow_exit_setting_screen(void);


void mmi_slidshow_setting_inline_done_hdlr(void);
static void mmi_slidshow_setting_screen_confirm_save(void);
static void mmi_slidshow_GoBackHistory1(void);

static void mmi_slidshow_entry_select_audio(void);
void mmi_slidshow_fmgr_select_audio_result_callback(void *filepath, int is_short);
#ifdef __MMI_VIDEO_PLAYER__
static void mmi_slidshow_entry_video_screen(void);
static void mmi_slidshow_exit_video_screen(void);
static void mmi_slidshow_play_finish_callback(MDI_RESULT result);
#endif /* __MMI_VIDEO_PLAYER__ */
static void mmi_slidshow_reset_osd_fade(BOOL sleep);
static void mmi_slidshow_osd_fade_cyclic(void);
static void mmi_slidshow_osd_show_up(void);

static void mmi_slidshow_entry_next_file(void);
static void mmi_slidshow_apply_index_change(void);


#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__
static void mmi_slidshow_effect_wipe_cyclic(void);
#endif
static void mmi_slidshow_effect_split_cyclic(void);
static void mmi_slidshow_effect_fade_in_cyclic(void);
static void mmi_slidshow_image_effect_finished(void);
static void mmi_slidshow_slice_time_out(void);

void mmi_slidshow_anim_finish_callback(GDI_RESULT result);

void mmi_slidshow_option_hilight_hdlr(S32 index);
void mmi_slidshow_bgm_highlight_hdlr(S32 index);
void mmi_slidshow_bgm_pre_entry_file_option(void);
void mmi_slidshow_entry_bgm_file_option(U8 type);

void mmi_slidshow_hilight_entry_select(void);

void mmi_slidshow_highlight_audio_file_play(void);
void mmi_slidshow_entry_audio_file_play(void);

static void mmi_slidshow_draw_arrow_key_osd(void);
static void mmi_slidshow_right_arrow_icon_key_press(void);
static void mmi_slidshow_right_arrow_icon_key_release(void);
static void mmi_slidshow_left_arrow_icon_key_press(void);
static void mmi_slidshow_left_arrow_icon_key_release(void);

static void mmi_slidshow_vol_up(void);
static void mmi_slidshow_vol_down(void);
static void mmi_slidshow_set_keys(void);
static U8 mmi_slidshow_deleteScr_callback(void* ptr);
static void mmi_slidshow_turn_off_bl_hdlr(void);
static void mmi_slidshow_auto_next(void);

void mmi_slidshow_load_setting(void);
void mmi_slidshow_store_setting(void);

#ifdef __MMI_TVOUT__
void mmi_slidshow_draw_img_2_tv(PS8 p_filename, U16 img_id,S32 img_w, S32 img_h, BOOL anim, BOOL reset_tvout);
void mmi_slidshow_anim_blt_after_callback(GDI_RESULT result);
#endif

/* touch screen */
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_slidshow_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_slidshow_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* draw sublcd for preventing updating sublcd while video playing on main lcd */
#ifdef __MMI_VIDEO_PLAYER__
#ifdef __MMI_SUBLCD__
void mmi_slidshow_entry_sublcd_screen(void);
void mmi_slidshow_exit_sublcd_screen(void);
void mmi_slidshow_draw_sublcd_icon(void);
#endif /* __MMI_SUBLCD__ */
#endif /* __MMI_VIDEO_PLAYER */

#ifdef __DRM_SUPPORT__
static void mmi_slidshow_drm_timeup_callback(S32 result, S32 id);
#endif /* __DRM_SUPPORT__ */

#ifdef __SLIDESHOW_USE_APP_ASM__
BOOL mmi_slidshow_alloc_app_asm(void);
void mmi_slidshow_free_app_asm(void);
U8 mmi_slidshow_del_scr_callback(void* ptr);
extern void mmi_slidshow_stop_callback(void);
#endif /* __SLIDESHOW_USE_APP_ASM__ */

void mmi_slidshow_store_data(void);
void mmi_slidshow_load_data(void);
static void mmi_slidshow_exit_hdlr(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_init_app
 * DESCRIPTION
 *  init slide show applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_SLIDSHOW_APP, mmi_slidshow_hilight_app);
    SetHiliteHandler(MENU_ID_SLIDSHOW_RESUME, mmi_slidshow_hilight_resume);
    SetHiliteHandler(MENU_ID_SLIDSHOW_PLAY, mmi_slidshow_hilight_play);
    SetHiliteHandler(MENU_ID_SLIDSHOW_SETTING, mmi_slidshow_hilight_setting);
    SetHiliteHandler(MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_SELECT, mmi_slidshow_hilight_entry_select);
    SetHiliteHandler(MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY, mmi_slidshow_highlight_audio_file_play);

    g_slidshow_cntx.text_color = *current_MMI_theme->title_text_color;
    g_slidshow_cntx.text_border_color = *current_MMI_theme->title_text_border_color;
    g_slidshow_cntx.audio_volume = SLIDSHOW_INIT_AUDIO_VOL;
    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
    g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;

#ifdef __SLIDESHOW_USE_APP_ASM__
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_SLIDESHOW,
        STR_ID_SLIDSHOW_APP,
        IMG_ID_SLIDSHOW_APP,
        mmi_slidshow_stop_callback);
    g_slidshow_layer1_buffer = NULL;
    g_slidshow_layer2_buffer = NULL;
#endif

    /* load setting from NVRAM */
    mmi_slidshow_load_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_app
 * DESCRIPTION
 *  init slide show applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_slideshow_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_slideshow_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_select_folder
 * DESCRIPTION
 *  entry slide show image folder selection path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slideshow_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

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
    
#ifdef __SLIDESHOW_USE_APP_ASM__
    if (NULL == g_slidshow_layer1_buffer && NULL == g_slidshow_layer2_buffer)
    {
        if (!mmi_slidshow_alloc_app_asm())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                STR_ID_SLIDSHOW_APP,
                IMG_ID_SLIDSHOW_APP,
                SLIDSHOW_FRAME_BUFFER_SIZE<<1,
                mmi_slideshow_entry_app);
            return;
        }
    }
#endif /* __SLIDESHOW_USE_APP_ASM__ */

    /* we use this screen to do some check, and allocate application memory only */
    EntryNewScreen(SCR_ID_SLIDSHOW_APP, NULL, mmi_slideshow_entry_app, NULL);

#ifdef __SLIDESHOW_USE_APP_ASM__
    SetDelScrnIDCallbackHandler(SCR_ID_SLIDSHOW_APP, mmi_slidshow_del_scr_callback);
#endif /* __SLIDESHOW_USE_APP_ASM__ */

    mmi_slidshow_entry_select_folder();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_select_folder
 * DESCRIPTION
 *  entry slide show image folder selection path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_select_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SLIDSHOW_FMGR, NULL, mmi_slidshow_entry_select_folder, NULL);


    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_SLIDESHOW,
        FMGR_SELECT_FOLDER | FMGR_SELECT_REPEAT,
        filter,
        (PS8) (S8*) L"root",
        (PsExtFuncPtr) mmi_slidshow_fmgr_select_result_callback);

    DisplayPopup((PU8) GetString(STR_ID_SLIDSHOW_NOTIFY_SELECT_FOLDER), IMG_GLOBAL_INFO, 0, 1000, WARNING_TONE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_fmgr_select_result_callback
 * DESCRIPTION
 *  select folder result callback function
 * PARAMETERS
 *  filepath        [?]         
 *  is_short        [IN]        
 *  filename(?)     [IN]        Filename(not used here)
 *  is_shot(?)      [IN]        Is it short naming
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_fmgr_select_result_callback(void *filepath, int is_short)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    FMGR_FILE_INFO_STRUCT file_info;
    U16 file_count;
    S32 index = 0;
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_edited = FALSE;
    if (filepath == NULL)
    {
        /* cencel file selection - delete up to one level before file selection */
        mmi_slidshow_exit_hdlr();
    }
    else
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
    #ifndef __MMI_SLIDSHOW_M3D_SUPPORT__        
        FMGR_FILTER_CLEAR(&filter,FMGR_TYPE_M3D);
    #endif
    #ifdef __MMI_VIDEO_PLAYER__
        FMGR_FILTER_SET_VIDEO(&filter);
    #endif /* __MMI_VIDEO_PLAYER__ */
    #ifdef __DRM_V02__
        FMGR_FILTER_SET(&filter,FMGR_TYPE_ODF);
    #endif /* __DRM_V02__ */

        mmi_fmgr_kernel_init_by_app(filepath, filter, &file_count);
        if (file_count)
        {
            mmi_fmgr_kernel_get_file_info(index, &file_info);
            mmi_ucs2cpy(buf_filename, filepath);
            mmi_ucs2cat(buf_filename, file_info.file_name);
            mmi_fmgr_util_store_filepath(buf_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);
            DeleteUptoScrID(SCR_ID_SLIDSHOW_APP);   /* kill file manager */
            mmi_slidshow_entry_option_screen();
        }
        else
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            mmi_fmgr_kernel_init_by_app(filepath, filter, &file_count);
            DeleteNHistory(1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_option_screen
 * DESCRIPTION
 *  entry slide show option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *guiBuffer = NULL;
    U8 *popup_list[16];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_bgm_play = TRUE;
    EntryNewScreen(SCR_ID_SLIDSHOW_OPTION, NULL, mmi_slidshow_entry_option_screen, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SLIDSHOW_OPTION);

    if (g_slidshow_cntx.is_edited)
    {

        num_item = GetNumOfChild(MENU_ID_SLIDSHOW_OPTION_EDIT);

        GetSequenceStringIds(MENU_ID_SLIDSHOW_OPTION_EDIT, item_list);
        GetSequenceImageIds(MENU_ID_SLIDSHOW_OPTION_EDIT, item_icons);
        SetParentHandler(MENU_ID_SLIDSHOW_OPTION_EDIT);

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < num_item; i++)
        {
            item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
        }

        for (i = 0; i < num_item; i++)
        {
            popup_list[i] = NULL;
        }

        ConstructHintsList(MENU_ID_SLIDSHOW_OPTION_EDIT, popup_list);
    }
    else
    {
        num_item = GetNumOfChild(MENU_ID_SLIDSHOW_OPTION);

        GetSequenceStringIds(MENU_ID_SLIDSHOW_OPTION, item_list);
        GetSequenceImageIds(MENU_ID_SLIDSHOW_OPTION, item_icons);
        SetParentHandler(MENU_ID_SLIDSHOW_OPTION);

        RegisterHighlightHandler(ExecuteCurrHiliteHandler);

        for (i = 0; i < num_item; i++)
        {
            item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
        }

        for (i = 0; i < num_item; i++)
        {
            popup_list[i] = NULL;
        }

        ConstructHintsList(MENU_ID_SLIDSHOW_OPTION, popup_list);
        if (g_slidshow_cntx.is_finished == TRUE)
        {
            guiBuffer = NULL;
            g_slidshow_cntx.is_finished = FALSE;
        }
    }
    SetDelScrnIDCallbackHandler(SCR_ID_SLIDSHOW_OPTION, mmi_slidshow_deleteScr_callback);    
    
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_SLIDSHOW_APP),
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
    SetRightSoftkeyFunction(mmi_slidshow_exit_hdlr, KEY_EVENT_UP);

    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_play
 * DESCRIPTION
 *  hilight "play" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_hilight_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_slidshow_entry_play_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_play_screen
 * DESCRIPTION
 *  entry slide show play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_play_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    FMGR_FILE_INFO_STRUCT file_info;
    S32 index;
    U16 file_count;
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.osd_opacity = 255;
    g_slidshow_cntx.is_video_file = FALSE;

    g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
    g_slidshow_cntx.is_valid_bgm = FALSE;    
    g_slidshow_cntx.is_animation = FALSE;
    g_slidshow_cntx.is_diff_anim = FALSE;
    g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    g_slidshow_cntx.is_from_next = FALSE;
    g_slidshow_cntx.idx2shift = 0;

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        lcd_width = UI_device_height;
        lcd_height = UI_device_width;
    }
    else
    {
        lcd_width = UI_device_width;
        lcd_height = UI_device_height;
    }

    /* reset current index (or need to check boundary)*/
    mmi_fmgr_kernel_set_cur_idx(0);
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_IMAGE(&filter);
#ifdef __MMI_VIDEO_PLAYER__    
    FMGR_FILTER_SET_VIDEO(&filter);
#endif

#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /* __DRM_SUPPORT__ */

    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);
    mmi_fmgr_remove_last_dir((PS8) buf_filename);
    mmi_fmgr_kernel_init_by_app(buf_filename, filter, &file_count);
    
    if (file_count > 0)
    {
        g_slidshow_cntx.is_bgmusic_selected = FALSE;
        g_slidshow_cntx.is_edited = FALSE;

        index = mmi_fmgr_kernel_get_cur_idx();
        mmi_fmgr_kernel_get_file_info(index, &file_info);

        /* append the name to path */
        mmi_fmgr_kernel_get_path_name(buf_filename);
        mmi_ucs2cat(buf_filename, file_info.file_name);
        mmi_fmgr_util_store_filepath(buf_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);

    #ifdef __DRM_V02__
        if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_ODF))
        {
            mmi_fmgr_get_drm_file_type_by_path(buf_filename, &file_info.file_type);
        }
    #endif /* __DRM_V02__ */
    
    #ifdef __MMI_VIDEO_PLAYER__
        if (FMGR_FILTER_IS_SET_VIDEO(&file_info.file_type))
        {
            g_slidshow_cntx.is_video_file = TRUE;
            g_slidshow_cntx.play_time = g_slidshow_cntx.vdo_total_duration = 0;
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
            mmi_slidshow_entry_video_screen();
        }
        else
    #endif /* __MMI_VIDEO_PLAYER__ */        
        {
            mmi_slidshow_entry_image_display_screen();  /* archive/ invalid odf */
        }
    }
    else
    {
        /* error handling: this dictionary is empty, or being deleted after entering this directory */
        DisplayPopup((PU8) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 0, 1000, EMPTY_LIST_TONE);
        DeleteNHistory(1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_resume
 * DESCRIPTION
 *  hilight "play" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_hilight_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_slidshow_entry_resume_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_resume_screen
 * DESCRIPTION
 *  entry slide show resume play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_resume_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_SLIDSHOW_OPTION);
#ifdef __MMI_VIDEO_PLAYER__
    if (g_slidshow_cntx.is_video_file == TRUE)
    {
        mmi_slidshow_entry_video_screen();
    }
    else
#endif /* __MMI_VIDEO_PLAYER__ */    
    {
        mmi_slidshow_entry_image_display_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_image_display_screen
 * DESCRIPTION
 *  enter play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_image_display_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    S32 image_width;
    S32 image_height;
    U8 *gui_buffer;
    PU8 p_src_buf;
    PU8 p_dest_buf;
    gdi_rect_struct dest_clip;
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data = NULL;
    FS_HANDLE fs_handle;
    U16 id_err_str = 0;
    PS8 p_err_str;
    U32 file_size;
    U16 image_type = 0;
#ifdef __DRM_SUPPORT__
    slideshow_drm_type_enum drm_type = SLIDESHOW_DRM_FREE_TO_DISP;
#endif
    S32 n_audio_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.result = 0;

    EntryNewScreen(
        SCR_ID_SLIDSHOW_PLAY,
        mmi_slidshow_exit_image_display_screen,
        mmi_slidshow_entry_image_display_screen,
        NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_SLIDSHOW_PLAY);  
    entry_full_screen();
    gdi_layer_reset_clip();

    if (gui_buffer == NULL)
    {
        g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    }
    TurnOnBacklight(0);                     /* stop MMI sleep */
    if ((g_slidshow_cntx.is_bgm_set && g_slidshow_cntx.is_bgm_play) || (!g_slidshow_cntx.is_valid_bgm && g_slidshow_cntx.is_sound_effect_selected))
    {
        mdi_audio_suspend_background_play();
    }

    g_slidshow_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_slidshow_end_key_press, KEY_END, KEY_EVENT_DOWN);
 
    SetKeyHandler(mmi_slidshow_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_slidshow_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    if ( g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL)
    {
        /* because LSK didn't show up, so do not set LSK here */
        SetKeyHandler(mmi_slidshow_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_lsk_release, KEY_LSK, KEY_EVENT_UP);
    }

    mmi_slidshow_set_keys();
    
    gdi_image_clear_work_buffer();
#ifdef __MMI_TVOUT__
   if (mdi_tvout_is_enable())
   {
       /* if is fullscreen, we shall set to owner APP Owner draw, to avoid GDI's update */
       mdi_tvout_set_owner(MDI_TV_OWNER_APP);
   }
#endif /* __MMI_TVOUT__ */
   /***************************************************************************** 
   * Layers
   *****************************************************************************/
    gdi_layer_multi_layer_enable();

    /* base layer */
    gdi_layer_get_active(&g_slidshow_cntx.base_layer_handle);

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        gdi_layer_resize(lcd_width, lcd_height);
        gdi_lcd_set_rotate_by_layer(TRUE);      
    }
    
    if (!g_slidshow_cntx.is_image_type)
    {
        gdi_layer_clear_background(GDI_COLOR_BLACK);
    }
    
    /* disable the source key of base layer for blue pictures*/
    gdi_layer_get_source_key(&g_slidshow_cntx.s7y_enable,&g_slidshow_cntx.old_source_key);
    if (g_slidshow_cntx.s7y_enable)
    {
        gdi_layer_set_source_key(FALSE, GDI_COLOR_BLACK); 
    }

    /* osd layer */
    g_slidshow_cntx.osd_layer_buf_ptr = (PU8) g_slidshow_layer2_buffer;
    gdi_layer_create_using_outside_memory(
        0,
        0,
        lcd_width,
        lcd_height,
        &g_slidshow_cntx.osd_layer_handle,
        (PU8) g_slidshow_cntx.osd_layer_buf_ptr,
        (S32) SLIDSHOW_FRAME_BUFFER_SIZE);
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    g_slidshow_cntx.play_layer_buf_ptr = (PU8) g_slidshow_layer1_buffer;
    gdi_layer_create_using_outside_memory(
        0,
        0,
        lcd_width,
        lcd_height,
        &g_slidshow_cntx.play_layer_handle,
        (PU8) g_slidshow_cntx.play_layer_buf_ptr,
        (S32) SLIDSHOW_FRAME_BUFFER_SIZE);

    gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
#if 0    
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
#endif    

    gdi_layer_set_blt_layer(
        g_slidshow_cntx.base_layer_handle,
        g_slidshow_cntx.osd_layer_handle,
        0,
        0);

    mmi_slidshow_main_draw_osd();
    
    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    if (g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_MANUAL)
    {
        mmi_slidshow_reset_osd_fade(FALSE);
    }
    
    if ((g_slidshow_cntx.is_effect_set != SLIDSHOW_EFFECT_SPLIT) || (gui_buffer != NULL))
    {
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.base_layer_handle,
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            0);
    }

    /****************************************************************/
    /*Draw image/ play bgm                                          */
    /****************************************************************/
    g_slidshow_cntx.effect_finish = TRUE;

    /* play bgm sound */
    if ((g_slidshow_cntx.is_bgm_set) && (g_slidshow_cntx.is_bgm_play) && (!g_slidshow_cntx.is_edited))
    {   
        n_audio_result = mdi_audio_play_file_with_vol_path(
                            (PU16) g_slidshow_cntx.audio_file_path, 
                            DEVICE_AUDIO_PLAY_INFINITE, 
                            NULL, 
                            NULL, 
                            g_slidshow_cntx.audio_volume, 
                            MDI_DEVICE_SPEAKER2);
        if (n_audio_result != MDI_AUDIO_SUCCESS)
        {
            g_slidshow_cntx.is_valid_bgm = FALSE;
        }
        else
        {
            g_slidshow_cntx.is_valid_bgm = TRUE;
        }
        g_slidshow_cntx.is_bgm_play = FALSE;
    }

    
    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);
    
#ifdef __DRM_SUPPORT__

    /*--------------------------------------------------------------*/
    /* new drm                                                      */
    /* check is archive or not. */

    fs_handle = DRM_open_file((PU16) buf_filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    if (fs_handle >= FS_NO_ERROR)
    {
    #ifdef __DRM_V02__
        if (DRM_is_archive(fs_handle, NULL))
        {
            drm_type = SLIDESHOW_DRM_ARCHIVE;
            g_slidshow_cntx.result = -1;
        }
        else 
    #endif /* __DRM_V02__ */            
        {
            if (!DRM_validate_permission(fs_handle, NULL, DRM_PERMISSION_DISPLAY))
            {
                /* no permission, will display key icon.*/
                drm_type = SLIDESHOW_DRM_PROHIBIT;
                g_slidshow_cntx.result = -1;
            }
        }
        DRM_close_file(fs_handle);
    }
    else if (fs_handle == DRM_RESULT_NO_PERMISSION)
    {
        drm_type = SLIDESHOW_DRM_PROHIBIT;
        g_slidshow_cntx.result = -1;
    }  

    /* end new drm                                                  */
    /*--------------------------------------------------------------*/
#endif /* __DRM_SUPPORT__ */

    /******* draw image ********/
    if (g_slidshow_cntx.result != -1)
    {
    g_slidshow_cntx.result = gdi_image_get_dimension_file((PS8) buf_filename, &image_width, &image_height);
        if ((image_width <= 0) || (image_height <= 0) || g_slidshow_cntx.result < GDI_SUCCEED )
        {
            if (g_slidshow_cntx.result == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)    /*MAUI_00547076*/
            {
                id_err_str = STR_ID_FMGR_FILE_TOO_LARGE_NO_DISPLAY;
            }
            else
            {
                id_err_str = STR_ID_FMGR_INVALID_IMAGE_FORMAT;
            }
            g_slidshow_cntx.result = -1;                                    /*MAUI_00547076*/
        }
        image_type = gdi_image_get_type_from_file(buf_filename);
    }


    fs_handle = FS_Open((U16*) buf_filename, FS_READ_ONLY);
    if (fs_handle >= FS_NO_ERROR)
    {
        FS_GetFileSize(fs_handle, (kal_uint32*) & file_size);
        FS_Close(fs_handle);
    }
    else if (fs_handle < FS_ERROR_RESERVED)
    {
       DisplayPopup((PU8) GetString(FMGR_FS_FILE_NOT_FOUND_TEXT), IMG_GLOBAL_ERROR, 1, 1000, ERROR_TONE);
       DeleteUptoScrID(SCR_ID_SLIDSHOW_APP);
       DeleteNHistory(1);
       return;
    }
#if !defined( __DRM_SUPPORT__ )           
    else
    {       
        MMI_ASSERT(0);  /* fs_handle == FS_ERROR_RESERVED, shouldn't be here. */
    }
#endif

    /* check file size limit and image size limit */
    if (g_slidshow_cntx.result >= 0 && g_slidshow_cntx.error_code == SLIDESHOW_ERR_NO_ERROR)
    {
        /* image size & animation check*/
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (PS8) buf_filename, &p_err_str))
        {
            g_slidshow_cntx.result = -1;
            /* result < 0 */
        #ifdef __MMI_TVOUT__
            mmi_slidshow_draw_img_2_tv(NULL, 0, 0, 0, FALSE, TRUE);   /* draw a black block */
        #endif /* __MMI_TVOUT__ */
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                DisplayPopupRotated((PU8) p_err_str, IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE, MMI_FRM_SCREEN_ROTATE_270);
            }
            else
        #endif                
            {
                DisplayPopup((PU8) p_err_str, IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE);
            }
            return;
        }
        else
        {
            switch (image_type)
            {
            #ifdef __MMI_SLIDSHOW_M3D_SUPPORT__                   
                case GDI_IMAGE_TYPE_M3D_FILE: 
            #endif                
                case GDI_IMAGE_TYPE_GIF_FILE:
                case GDI_IMAGE_TYPE_SVG_FILE:
                    g_slidshow_cntx.is_animation = TRUE;
                    break;
                default:
                    break;
            }
        }
    }

    if (g_slidshow_cntx.result >= 0)
    {
        if ((image_width > lcd_width) || (image_height > lcd_height))
        {
            gdi_image_util_fit_bbox(
                lcd_width,
                lcd_height,
                image_width,
                image_height,
                &g_slidshow_cntx.resized_image_offset_x,
                &g_slidshow_cntx.resized_image_offset_y,
                &g_slidshow_cntx.resized_image_width,
                &g_slidshow_cntx.resized_image_height);

            if (g_slidshow_cntx.resized_image_width == 0)
            {
                g_slidshow_cntx.resized_image_width = 1;
                g_slidshow_cntx.resized_image_offset_x--;
            }

            if (g_slidshow_cntx.resized_image_height == 0)
            {
                g_slidshow_cntx.resized_image_height = 1;
                g_slidshow_cntx.resized_image_offset_y--;
            }
        }
        else
        {
            g_slidshow_cntx.resized_image_offset_x = (lcd_width - image_width) >> 1;
            g_slidshow_cntx.resized_image_offset_y = (lcd_height - image_height) >> 1;
            g_slidshow_cntx.resized_image_width = image_width;
            g_slidshow_cntx.resized_image_height = image_height;
        }
        
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        if (gui_buffer != NULL && g_slidshow_cntx.error_code)
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
        }
        else
        {
            g_slidshow_cntx.result = gdi_image_draw_resized_file(
                                        g_slidshow_cntx.resized_image_offset_x,
                                        g_slidshow_cntx.resized_image_offset_y,
                                        g_slidshow_cntx.resized_image_width,
                                        g_slidshow_cntx.resized_image_height,
                                        buf_filename);
        }
        gdi_layer_pop_and_restore_active();
        
        if (g_slidshow_cntx.result < 0)
        {
            if(g_slidshow_cntx.result == GDI_IMAGE_ERR_DECODE_TIME_OUT)
            {
                id_err_str = STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE;
            }
            else
            {
                id_err_str = STR_ID_FMGR_INVALID_IMAGE_FORMAT;
            }
        }
        else
        {
        #ifdef __DRM_SUPPORT__
            /* all ok, consume DRM right */
            if(DRM_get_object_method(0, (PU16)buf_filename) != DRM_METHOD_NONE)
            {
                fs_handle = DRM_open_file((PU16) buf_filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
                if (fs_handle >= FS_NO_ERROR)
                {                      
                    g_slidshow_cntx.id_DRM = 0;
                    if (gui_buffer == NULL)
                    {
                        g_slidshow_cntx.id_DRM = 
                            DRM_consume_rights(fs_handle, DRM_PERMISSION_DISPLAY, mmi_slidshow_drm_timeup_callback);
                    }
                    else
                    {
                        /* back from interrupt, only timed right will be consume */
                        g_slidshow_cntx.id_DRM = 
                            DRM_consume_timed_rights(fs_handle, DRM_PERMISSION_DISPLAY, mmi_slidshow_drm_timeup_callback);
                    }
                }
                else
                {
                    ASSERT(0);      /* should not enter here */
                }
                DRM_close_file(fs_handle);
            }
        #endif /* __DRM_SUPPORT__ */
        }            
    }
#ifdef __MMI_TVOUT__
    if(g_slidshow_cntx.result >= 0 && !g_slidshow_cntx.error_code)
    {
        mmi_slidshow_draw_img_2_tv(buf_filename, 0, image_width, image_height, FALSE, TRUE);
    }
#endif /* __MMI_TVOUT__ */     

    if (g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL)
    {
        if (!g_slidshow_cntx.is_image_type)
        {
            gui_start_timer(SLIDSHOW_OSD_FADE_OUT_TIME, mmi_slidshow_osd_fade_cyclic);
        }
        else if(g_slidshow_cntx.osd_opacity <= 255 && g_slidshow_cntx.osd_opacity > 0)
        {
            gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
            mmi_slidshow_osd_fade_cyclic();
        }
    }
    g_slidshow_cntx.is_image_type = FALSE;
    
    if ((gui_buffer == NULL) && (g_slidshow_cntx.result >= 0))
    {
        /* play sound effect                                */
        /* BGM > SOUND, no sound effect while playing BGM   */
        if ((!g_slidshow_cntx.is_bgm_set && g_slidshow_cntx.is_sound_effect_selected) || (g_slidshow_cntx.is_sound_effect_selected && !g_slidshow_cntx.is_valid_bgm))
        {
            switch (g_slidshow_cntx.is_sound_effect_selected)
            {
                case SLIDSHOW_AUDIO1:
                    audio_data = get_audio((U16) (AUD_ID_SLIDSHOW_1), &audio_type, &audio_len);
                    break;
                case SLIDSHOW_AUDIO2:
                    audio_data = get_audio((U16) (AUD_ID_SLIDSHOW_2), &audio_type, &audio_len);
                    break;
                case SLIDSHOW_AUDIO3:
                    audio_data = get_audio((U16) (AUD_ID_SLIDSHOW_3), &audio_type, &audio_len);
                    break;
                default:
                    MMI_ASSERT(0);
            }
            if (audio_data != NULL)
            {
                mdi_audio_play_string_with_vol_path(
                    (void*)audio_data,
                    (U32) audio_len,
                    MDI_FORMAT_WAV,
                    DEVICE_AUDIO_PLAY_ONCE,
                    NULL,
                    NULL,
                    SLIDSHOW_INIT_AUDIO_VOL,
                    MDI_DEVICE_SPEAKER2);
            }
        }
        g_slidshow_cntx.is_diff_anim = FALSE;
        g_slidshow_cntx.effect_finish = FALSE;
        switch (g_slidshow_cntx.is_effect_set)
        {
        #ifdef __MMI_SLIDSHOW_WIPE_ENABLE__            
            case SLIDSHOW_EFFECT_WIPE:
                g_slidshow_cntx.effect_value = -lcd_height;
                gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
                gdi_layer_set_position(0, g_slidshow_cntx.effect_value);                
                gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
                gdi_layer_pop_and_restore_active();
                mmi_slidshow_effect_wipe_cyclic();
                break;
        #endif /* __MMI_SLIDSHOW_WIPE_ENABLE__ */

            case SLIDSHOW_EFFECT_SPLIT:
            #if 1
                gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
                gdi_layer_get_buffer_ptr(&p_src_buf);
                gdi_layer_pop_and_restore_active();
            #endif
                g_slidshow_cntx.extra_layer_var = TRUE;
                gdi_layer_create(0, 0, lcd_width / 2, lcd_height, &g_slidshow_cntx.extra_layer_1);
                gdi_layer_create(lcd_width / 2, 0, lcd_width / 2, lcd_height, &g_slidshow_cntx.extra_layer_2);
                gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
                gdi_layer_get_buffer_ptr(&p_dest_buf);
                dest_clip.x1 = 0;
                dest_clip.y1 = 0;
                dest_clip.x2 = (lcd_width >> 1) -1;
                dest_clip.y2 = lcd_height - 1;
                gdi_2d_memory_blt(
                    p_src_buf,
                    lcd_width,
                    0,
                    0,
                    lcd_width,
                    lcd_height,
                    p_dest_buf,
                    lcd_width >> 1,
                    0,
                    0,
                    dest_clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);
                gdi_layer_pop_and_restore_active();
                gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
                gdi_layer_get_buffer_ptr(&p_dest_buf);

                gdi_2d_memory_blt(
                    p_src_buf,
                    lcd_width,
                    lcd_width >> 1,                 /* the offset x,y of copy pointer*/
                    0,
                    lcd_width >> 1,                 /* the width/height to be copied */
                    lcd_height,
                    p_dest_buf,
                    lcd_width >> 1,
                    0,                              /* the offset on the dest buffer */
                    0,
                    dest_clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);

                gdi_layer_pop_and_restore_active();
                gdi_layer_set_blt_layer(
                    g_slidshow_cntx.base_layer_handle,
                    g_slidshow_cntx.extra_layer_1,
                    g_slidshow_cntx.extra_layer_2,
                    g_slidshow_cntx.osd_layer_handle);
                g_slidshow_cntx.effect_value = -lcd_width;
                mmi_slidshow_effect_split_cyclic();
                break;

            case SLIDSHOW_EFFECT_FADE_IN:
                g_slidshow_cntx.effect_value = SLIDSHOW_OSD_FADE_IN_VALUE - 1;
                mmi_slidshow_effect_fade_in_cyclic();
                break;

            default:
                gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
                mmi_slidshow_image_effect_finished();
                break;
                
        }
        
    #ifdef SLIDSHOW_POWER_SAVING
        if (g_slidshow_cntx.is_edited)
        {
            gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
        }
    #endif
    
    }
    else   /* gui buffer != NULL || result < 0 */
    {
        /* error handling */
    #ifdef __DRM_SUPPORT__
        if(SLIDESHOW_DRM_FREE_TO_DISP != drm_type)
        {
            /* draw the key icon. */
            gdi_layer_set_blt_layer(
                g_slidshow_cntx.base_layer_handle,
                g_slidshow_cntx.play_layer_handle,
                g_slidshow_cntx.osd_layer_handle,
                0);
            /* draw archive icon if it is archive */
            gdi_image_get_dimension_id(IMG_ID_FMGR_DRM_LOCKED, &image_width, &image_height);
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            gdi_image_draw_id((lcd_width - image_width)>>1, (lcd_height - image_height) >> 1, IMG_ID_FMGR_DRM_LOCKED);
            gdi_layer_pop_and_restore_active();
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        #ifdef __MMI_TVOUT__
            mmi_slidshow_draw_img_2_tv(NULL, IMG_ID_FMGR_DRM_LOCKED, image_width, image_height, FALSE, TRUE);
        #endif /* __MMI_TVOUT__ */       
            if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
            {
                gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
            }
            
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_pen_down_handler(mmi_slidshow_pen_down_hdlr);
            wgui_register_pen_up_handler(mmi_slidshow_pen_up_hdlr);
            wgui_register_pen_move_handler(mmi_slidshow_pen_move_hdlr);
        #endif /* __MMI_TOUCH_SCREEN__ */
        
            return;
        }
    #endif /* __DRM_SUPPORT__ */
    
        if (gui_buffer == NULL)
        { 
            /* result < 0 */
        #ifdef __MMI_TVOUT__
            mmi_slidshow_draw_img_2_tv(NULL, 0, 0, 0, FALSE, TRUE);   /* draw a black block */
        #endif /* __MMI_TVOUT__ */
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                DisplayPopupRotated((PU8) GetString(id_err_str), IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE, MMI_FRM_SCREEN_ROTATE_270);
            }
            else
        #endif                
            {
                DisplayPopup((PU8) GetString(id_err_str), IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE);
            }
            return;
        }
        else
        {
            /* restore from interrupt */
            /* add animation handling */
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            if(g_slidshow_cntx.error_code)
            {
                if(g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL && !g_slidshow_cntx.is_edited)
                {
                    if (g_slidshow_cntx.is_from_next)
                    {
                        gui_start_timer(SLIDSHOW_ERROR_SKIP_DELAY, mmi_slidshow_left_arrow_release);
                        g_slidshow_cntx.is_from_next = FALSE;
                    }
                    else
                    {
                        gui_start_timer(SLIDSHOW_ERROR_SKIP_DELAY, mmi_slidshow_auto_next);
                    }
                }
            #ifdef __MMI_TVOUT__
                mmi_slidshow_draw_img_2_tv(NULL, 0, 0, 0, FALSE, TRUE); /* clean TVOUT screen */
            #endif /* __MMI_TVOUT__ */
            }
            else
            {
                mmi_slidshow_image_effect_finished();
            }
        #ifdef SLIDSHOW_POWER_SAVING
            if (g_slidshow_cntx.is_edited)
            {
                gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
            }
        #endif /* #ifdef SLIDSHOW_POWER_SAVING */
        }
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_slidshow_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_slidshow_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_slidshow_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_image_display_screen
 * DESCRIPTION
 *  exit play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_exit_image_display_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    if (g_slidshow_cntx.id_DRM)
    {
        DRM_stop_consume(g_slidshow_cntx.id_DRM);
        g_slidshow_cntx.id_DRM = 0;
    }
#endif /* __DRM_SUPPORT__ */

#ifdef SLIDSHOW_POWER_SAVING
    gui_cancel_timer(mmi_slidshow_turn_off_bl_hdlr);    
#endif

    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    if (!(g_slidshow_cntx.is_image_type || g_slidshow_cntx.is_video_type))
    {
        if ((g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON) && (!g_slidshow_cntx.is_edited))
        {
            mdi_audio_stop_file();
            g_slidshow_cntx.is_bgm_play = TRUE;
        }
    }

    if(!g_slidshow_cntx.error_code && ((g_slidshow_cntx.is_bgm_play && g_slidshow_cntx.is_bgm_set) || (!g_slidshow_cntx.is_valid_bgm && g_slidshow_cntx.is_sound_effect_selected)))
    {   
        /* error popup don't resume */
        mdi_audio_resume_background_play();
    }

    switch (g_slidshow_cntx.is_effect_set)
    {
    #ifdef __MMI_SLIDSHOW_WIPE_ENABLE__        
        case SLIDSHOW_EFFECT_WIPE:
            gui_cancel_timer(mmi_slidshow_effect_wipe_cyclic);
            break;
    #endif /* __MMI_SLIDSHOW_WIPE_ENABLE__ */            
        case SLIDSHOW_EFFECT_SPLIT:
            gui_cancel_timer(mmi_slidshow_effect_split_cyclic);
            break;
        case SLIDSHOW_EFFECT_FADE_IN:
            gui_cancel_timer(mmi_slidshow_effect_fade_in_cyclic);
            break;
        default:
            break;
    }
    /* stop animation if needed */
    if (g_slidshow_cntx.h_animate != GDI_NULL_HANDLE)
    {
        gdi_anim_stop(g_slidshow_cntx.h_animate);
        g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
    }

    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_right_arrow_release);
    gui_cancel_timer(mmi_slidshow_slice_time_out);
    gui_cancel_timer(mmi_slidshow_left_arrow_release);
    gui_cancel_timer(mmi_slidshow_apply_index_change);

    /* let MMI can sleep */
    TurnOffBacklight();

#if defined(LCM_ROTATE_SUPPORT)
    if (g_slidshow_cntx.error_code)
    {
        gdi_layer_flatten_to_base(
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }
    else
    {
        gdi_layer_flatten_to_base(g_slidshow_cntx.play_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
    }    
#else
    if (g_slidshow_cntx.error_code && g_slidshow_cntx.is_horz_view_set != SLIDSHOW_HORIZONTAL_VIEW)
    {
        gdi_layer_flatten_to_base(
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }
    else
    {
        /* clean base layer because we won't flatten*/
        gdi_layer_push_and_set_active(g_slidshow_cntx.base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
#endif

    /* free layers */
    if (g_slidshow_cntx.osd_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.osd_layer_handle);
        g_slidshow_cntx.osd_layer_buf_ptr = NULL;
        g_slidshow_cntx.osd_layer_handle = GDI_NULL_HANDLE;

    }
    
    if (g_slidshow_cntx.play_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.play_layer_handle);
        g_slidshow_cntx.play_layer_buf_ptr = NULL;
        g_slidshow_cntx.play_layer_handle = GDI_NULL_HANDLE;
    }
    
    if (g_slidshow_cntx.extra_layer_var == TRUE)
    {
        g_slidshow_cntx.extra_layer_var = FALSE;
        gdi_layer_free(g_slidshow_cntx.extra_layer_1);
        gdi_layer_free(g_slidshow_cntx.extra_layer_2);
    }

    if ((g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW) && (!g_slidshow_cntx.is_image_type))
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_set_rotate_by_layer(FALSE);
    }

        /* restore TV out mode */
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && g_slidshow_cntx.h_animate_tv != GDI_NULL_HANDLE)
    {
        gdi_anim_stop(g_slidshow_cntx.h_animate_tv);
        g_slidshow_cntx.h_animate_tv = GDI_NULL_HANDLE;
    }
    
    if ((mdi_tvout_is_enable()) && (!g_slidshow_cntx.is_image_type))
    {
        /* restore back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to start mode1 */
        mdi_tvout_set_mode(
            MDI_TV_MODE_LCD_SCR,
            0,  /* layer_width */
            0); /* layer_height */
    }
#endif /* __MMI_TVOUT__ */
    
    /* restore baselayer sourcekey */
    if (g_slidshow_cntx.s7y_enable)
    {
        gdi_layer_set_source_key(g_slidshow_cntx.s7y_enable, g_slidshow_cntx.old_source_key);
    }
    g_slidshow_cntx.effect_finish = TRUE;

    gdi_layer_set_blt_layer(g_slidshow_cntx.base_layer_handle, 0, 0, 0);
    gdi_layer_multi_layer_disable();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_press
 * DESCRIPTION
 *  right arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slidshow_reset_osd_fade(TRUE);
    mmi_slidshow_right_arrow_icon_key_press();
}


void mmi_slidshow_auto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_slidshow_right_arrow_release);
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    g_slidshow_cntx.idx2shift = 1;
    mmi_slidshow_apply_index_change();
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_release
 * DESCRIPTION
 *  right arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    mmi_slidshow_right_arrow_icon_key_release();
    g_slidshow_cntx.idx2shift++;
    gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_apply_index_change);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_apply_index_change
 * DESCRIPTION
 *  apply the file index change to file system.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_apply_index_change(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;
    FMGR_FILE_INFO_STRUCT file_info;
    S32 index = 0;
    U16 file_count;
    S32 count;
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.effect_finish)
    {
        gui_cancel_timer(mmi_slidshow_apply_index_change);
        gui_start_timer(SLIDSHOW_ANIM_NEXT_IMG_DELAY, mmi_slidshow_apply_index_change);
        return;
    }    
    
    g_slidshow_cntx.is_diff_anim = TRUE;
    g_slidshow_cntx.is_video_file = FALSE;
    g_slidshow_cntx.is_edited = FALSE;
    g_slidshow_cntx.is_from_next = FALSE;
    
    if (g_slidshow_cntx.is_bgmusic_selected)
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
    #ifdef __MMI_VIDEO_PLAYER__        
        FMGR_FILTER_SET_VIDEO(&filter);
    #endif /* __MMI_VIDEO_PLAYER__ */

        mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);
        mmi_fmgr_remove_last_dir((PS8) buf_filename);
        mmi_fmgr_kernel_init_by_app(buf_filename, filter, &file_count);
        g_slidshow_cntx.is_bgmusic_selected = FALSE;
        while (index != resume_index)
        {
            mmi_fmgr_kernel_move_selection_down();
            index += 1;
        }
    }
    g_slidshow_cntx.filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    index = mmi_fmgr_kernel_get_cur_idx();
    file_count = mmi_fmgr_kernel_get_file_count();

    /* move index */
    index += g_slidshow_cntx.idx2shift;
    while(index < 0)
    {
        index += file_count;
    }
    count = index;          /* if count > file_count && auto_once => stop playback. */

    index %= file_count;
    mmi_fmgr_kernel_set_cur_idx(index);

    g_slidshow_cntx.idx2shift = 0;
    
    mmi_fmgr_kernel_get_file_info(index, &file_info);

    resume_index = index;
    if (g_slidshow_cntx.is_random_effect == TRUE)
    {
        g_slidshow_cntx.is_effect_set = (g_slidshow_cntx.is_effect_set + 1) % (SLIDSHOW_EFFECT_TOTAL - 1);
    }

    /* append the name to path */
    mmi_fmgr_kernel_get_path_name(g_slidshow_cntx.filepath);
    mmi_ucs2cat(g_slidshow_cntx.filepath, file_info.file_name);
    mmi_fmgr_util_store_filepath(g_slidshow_cntx.filepath, FMGR_PATH_ID_SLIDE_SHOW_PLAY);
    gui_free(g_slidshow_cntx.filepath);

    if ((count == file_count) && (g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_AUTO_ONCE))
    {
        g_slidshow_cntx.is_finished = TRUE;
        gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
        mmi_slidshow_reset_osd_fade(FALSE);
        DeleteUptoScrID(SCR_ID_SLIDSHOW_OPTION);
        GoBackHistory();
    }
    else
    {
        mmi_slidshow_entry_next_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_press
 * DESCRIPTION
 *  left arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slidshow_reset_osd_fade(TRUE);
    mmi_slidshow_left_arrow_icon_key_press();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_release
 * DESCRIPTION
 *  left arrow key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_release(void)
{
    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    mmi_slidshow_left_arrow_icon_key_release();
    g_slidshow_cntx.idx2shift--;
    gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_apply_index_change);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_main_draw_osd
 * DESCRIPTION
 *  draws softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_main_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 lsk_str, rsk_str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.osd_opacity);

    /******* draw softkey ********/
    rsk_str = (PS8) get_string(STR_GLOBAL_BACK);
    if (g_slidshow_cntx.error_code && g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_MANUAL)
    {
        lsk_str = NULL;
    }
    else if (g_slidshow_cntx.is_edited)
    {
        lsk_str = (PS8) get_string(STR_GLOBAL_CONTINUE);
    }
    else
    {
        lsk_str = (PS8) get_string(STR_ID_SLIDSHOW_PAUSE);
    }
    
    mmi_slidshow_draw_softkey(lsk_str, rsk_str, FALSE);

    gdi_layer_pop_and_restore_active();
    mmi_slidshow_draw_arrow_key_osd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_softkey
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  lsk_str         [IN]        Lsk string
 *  rsk_str         [IN]        Rsk string
 *  is_clear_bg     [IN]        Clear background flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_draw_softkey(PS8 lsk_str, PS8 rsk_str, BOOL is_clear_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 x1;
    S32 x2;
    S32 y1;
    S32 y2;
    S32 spacing;

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
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        if (lsk_str != NULL)
        {
            wgui_softkey_get_offset((UI_string_type) lsk_str, &offset_x, &offset_y, MMI_LEFT_SOFTKEY);
            gui_measure_string((UI_string_type) lsk_str, &str_width, &str_height);
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                spacing = (MMI_SOFTKEY_HEIGHT - str_height) >> 1;
                offset_x = UI_device_height - str_width - spacing;
                offset_y = UI_device_width - str_height - spacing;
               
            }
            
            if (g_slidshow_cntx.is_lsk_pressed)
            {
                offset_x++;
                offset_y++;
            }
            
            if (r2lMMIFlag && g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                gui_move_text_cursor(offset_x + str_width, offset_y);
            }
            else
            {
                gui_move_text_cursor(offset_x, offset_y);
            }
            
            gui_set_text_color(g_slidshow_cntx.text_color);
            gui_set_text_border_color(g_slidshow_cntx.text_border_color);
            gui_print_bordered_text((UI_string_type) lsk_str);

        #ifdef __MMI_TOUCH_SCREEN__
            g_slidshow_touch_screen_cntx.lsk.pos_x = offset_x;
            g_slidshow_touch_screen_cntx.lsk.pos_y = offset_y;
            g_slidshow_touch_screen_cntx.lsk.width = str_width;
            g_slidshow_touch_screen_cntx.lsk.height = str_height;
        #endif /* __MMI_TOUCH_SCREEN__ */ 

        }
    #ifdef __MMI_TOUCH_SCREEN__
        else
        {
            g_slidshow_touch_screen_cntx.lsk.pos_x = 0;
            g_slidshow_touch_screen_cntx.lsk.pos_y = 0;
            g_slidshow_touch_screen_cntx.lsk.width = 0;
            g_slidshow_touch_screen_cntx.lsk.height = 0;

        }
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }

    /* draw rsk */
    if (rsk_str != NULL)
    {
        wgui_softkey_get_offset((UI_string_type) rsk_str, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
        gui_measure_string((UI_string_type) rsk_str, &str_width, &str_height);        
        if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
        {
            spacing = (MMI_SOFTKEY_HEIGHT - str_height) >> 1;
            offset_x = UI_device_height - str_width - spacing;
            offset_y = spacing;
        }
    
        if (g_slidshow_cntx.is_rsk_pressed)
        {
            offset_x++;
            offset_y++;
        }

        if (r2lMMIFlag && g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_set_text_color(g_slidshow_cntx.text_color);
        gui_set_text_border_color(g_slidshow_cntx.text_border_color);
        gui_print_bordered_text((UI_string_type) rsk_str);

    #ifdef __MMI_TOUCH_SCREEN__
        g_slidshow_touch_screen_cntx.rsk.pos_x = offset_x;
        g_slidshow_touch_screen_cntx.rsk.pos_y = offset_y;
        g_slidshow_touch_screen_cntx.rsk.width = str_width;
        g_slidshow_touch_screen_cntx.rsk.height = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 

    }

#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_slidshow_touch_screen_cntx.rsk.pos_x = 0;
        g_slidshow_touch_screen_cntx.rsk.pos_y = 0;
        g_slidshow_touch_screen_cntx.rsk.width = 0;
        g_slidshow_touch_screen_cntx.rsk.height = 0;

    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gdi_layer_pop_clip();
    gdi_layer_pop_text_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_end_key_press
 * DESCRIPTION
 *  press end key hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_end_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * set this flag true, will free memory when exit slide show screen
     * (1) User directly press end key.
     * (2) Clam close. Clam close will also call this function 
     */
    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    mmi_slidshow_reset_osd_fade(FALSE);
    /* call standand end-key handler */
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    g_slidshow_cntx.end_key_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_lsk_press
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity || (g_slidshow_cntx.is_animation && g_slidshow_cntx.h_animate == NULL))
    {
        return;
    }
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_reset_osd_fade(TRUE);
    }
    g_slidshow_cntx.is_lsk_pressed = TRUE;
    mmi_slidshow_show_press_release_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_show_press_release_softkey
 * DESCRIPTION
 *  draw and show softkey based on different screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_show_press_release_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
    }
    gdi_layer_pop_and_restore_active();    
    mmi_slidshow_main_draw_osd();    

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_lsk_release
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__    
    MDI_RESULT ret;
    U64 ms_current_play_time;
    U32 flg_blt, flg_play;
#endif    
    S8 audio_buffer[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }
    g_slidshow_cntx.is_lsk_pressed = FALSE;
    if (g_slidshow_cntx.is_edited == TRUE)
    {
    #ifdef SLIDSHOW_POWER_SAVING
        gui_cancel_timer(mmi_slidshow_turn_off_bl_hdlr);
        TurnOffBacklight();
    #endif
        /* resume playing. */
        g_slidshow_cntx.is_edited = FALSE;
    #ifdef __MMI_VIDEO_PLAYER__        
        if (g_slidshow_cntx.is_video_file)
        {
            /* resume video */
            if (g_slidshow_cntx.is_vdo_opened && SLIDSHOW_VIDEO_PAUSE == g_slidshow_cntx.v_state)
            {
                mdi_audio_set_volume(VOL_TYPE_MEDIA, g_slidshow_cntx.audio_volume);
                /* check for situations that the video has finished but it still in pause state. */
                mdi_video_ply_get_cur_play_time(&ms_current_play_time);
                if ((ms_current_play_time == g_slidshow_cntx.play_time) && (ms_current_play_time < g_slidshow_cntx.vdo_total_duration))
                {
                #ifdef GDI_USING_LAYER_BACKGROUND
                    flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
                    flg_play = GDI_LAYER_ENABLE_LAYER_0;
                #else  /* GDI_USING_LAYER_BACKGROUND */
                    flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
                    flg_play = GDI_LAYER_ENABLE_LAYER_1;
                #endif /* GDI_USING_LAYER_BACKGROUND */
                    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PLAYING;
                    ret = mdi_video_ply_play(
                            g_slidshow_cntx.play_layer_handle,
                            flg_blt,
                            flg_play,
                            1,                              /* repeat count */
                            TRUE,                           /* update to LCM or not */
                            TRUE,                           /* play aud */
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            (g_slidshow_cntx.is_horz_view_set ? MDI_VIDEO_LCD_ROTATE_270 : MDI_VIDEO_LCD_ROTATE_0),       /* rotate */
                            100,                            /* 1x play speed */
                            mmi_slidshow_play_finish_callback);    /* hook callback */
                }
                else
                {
                    /* video has already finished. */
                    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
                    gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_auto_next);
                }
            }
            else
            {
                /* video stopped (error/finished). resume play next slide. */
                gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_auto_next);
            }
        }
        else
    #endif /* __MMI_VIDEO_PLAYER__  */
        {
            /* resume image */
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
            if (g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON)
            {
                mmi_fmgr_util_load_filepath(audio_buffer, FMGR_PATH_ID_SLIDE_SHOW_AUDIO);
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
                mdi_audio_play_file_with_vol_path(
                    (PU16) audio_buffer, 
                    DEVICE_AUDIO_PLAY_INFINITE, 
                    NULL, 
                    NULL, 
                    g_slidshow_cntx.audio_volume, 
                    MDI_DEVICE_SPEAKER2);
                g_slidshow_cntx.is_bgm_play = FALSE;
            }
        }
    }
    else if (g_slidshow_cntx.is_video_file || !(g_slidshow_cntx.is_animation && g_slidshow_cntx.h_animate == NULL))
    {
        /* MAUI_458909 don't pause if the animation is finished and ready to enter next image */
        
        /* Pause */
        g_slidshow_cntx.is_edited = TRUE;
        gui_cancel_timer(mmi_slidshow_auto_next);
        gui_cancel_timer(mmi_slidshow_apply_index_change);
        g_slidshow_cntx.idx2shift = 0;          /* timer may up, so reset the shift index */
    #ifdef __MMI_VIDEO_PLAYER__        
        if (g_slidshow_cntx.is_video_file && g_slidshow_cntx.is_vdo_opened )
        {
            /* pause video */
            if (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING)
            {
                mdi_video_ply_stop();
                mdi_video_ply_get_cur_play_time(&g_slidshow_cntx.play_time);
                g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PAUSE;
            }
        }
        else
    #endif /* __MMI_VIDEO_PLAYER */
        {
            /* playing images, pause background music. */
            if (g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON)
            {
                mdi_audio_stop_file();
                g_slidshow_cntx.is_bgm_play = TRUE;
            }
        }

    #ifdef SLIDSHOW_POWER_SAVING
        gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
    #endif
    
    }
    mmi_slidshow_show_press_release_softkey();

/*    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_rsk_press
 * DESCRIPTION
 *  rsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        return;
    }
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_reset_osd_fade(TRUE);
    }
    g_slidshow_cntx.is_rsk_pressed = TRUE;
    mmi_slidshow_show_press_release_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_rsk_release
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }
    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    g_slidshow_cntx.is_rsk_pressed = FALSE;
    if ((g_slidshow_cntx.is_bgm_set) && (!g_slidshow_cntx.is_edited))
    {
        mdi_audio_stop_file();
    }
    /* enter pause state */
    g_slidshow_cntx.is_edited = TRUE;
    if (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING)
    {
        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PAUSE;
    }    
    
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_setting
 * DESCRIPTION
 *  highlight setting game
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_hilight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_slidshow_entry_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_slidshow_entry_setting_screen, KEY_EVENT_UP);
    
    g_slidshow_cntx.cat57_done_flag = FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_setting_screen
 * DESCRIPTION
 *  entry point for slide show setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer;
    U8 *input_buffer;
    U16 item_offset;
    U16 input_buffer_size;
    PS8 buf_filename;
    FS_HANDLE h_file;
    S8 eff_cnt;
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;

#if !defined( __MMI_SHOW_DAF_FILE_EXT__)    
    PS8 ext_name;
#endif /* defined( __MMI_SHOW_DAF_FILE_EXT__) */

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_ID_SLIDSHOW_SETTING_TYPE_OF_PLAY,
        0,
        IMG_ID_SLIDSHOW_SETTING_SPEED,
        0,
        IMG_ID_SLIDSHOW_SETTING_EFFECT,
        0,
        IMG_ID_SLIDSHOW_SETTING_BACK_SOUND,
        0,
        IMG_ID_SLIDSHOW_SETTING_HORZ_DISPLAY,
        0,
        IMG_ID_SLIDSHOW_SETTING_SOUND_EFFECT,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SLIDSHOW_SETTING, mmi_slidshow_exit_setting_screen, NULL, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_SLIDSHOW_SETTING);
    input_buffer = GetCurrNInputBuffer(SCR_ID_SLIDSHOW_SETTING, &input_buffer_size);

    if (gui_buffer == NULL)
    {
        /* load data from nvram */
        mmi_slidshow_load_setting();
    }

    if (g_slidshow_cntx.setting.bgm)
    {
        /* to save code size, we use layer buffer in slideshow to store file path
           if this line is asserted, we have to allocate a global static array for buf_filename */
        ASSERT(FMGR_MAX_PATH_LEN <= SLIDESHOW_FRAME_BUFFER_SIZE);
        ASSERT(g_slidshow_layer1_buffer != NULL);
        buf_filename = (PS8) g_slidshow_layer1_buffer;        
        
        g_slidshow_cntx.is_bgmusic_selected = TRUE;
        
        /* check if the file exists */
        h_file = FS_Open((U16 *) g_slidshow_cntx.audio_file_path, FS_READ_ONLY);
        if (h_file >= FS_NO_ERROR )
        {
            FS_Close(h_file);
            /* handle short filename */
            if (g_slidshow_cntx.is_short_path)
            {
                mmi_chset_mixed_text_to_ucs2_str(
                    (U8*) buf_filename,
                    FMGR_MAX_PATH_LEN,
                    (U8*) g_slidshow_cntx.audio_file_path + mmi_fmgr_get_last_dir_index(g_slidshow_cntx.audio_file_path),
                    PhnsetGetDefEncodingType());
            }
            else
            {
                mmi_ucs2cpy(
                    buf_filename,
                    (g_slidshow_cntx.audio_file_path + mmi_fmgr_get_last_dir_index(g_slidshow_cntx.audio_file_path)));
            }

        #if !defined(__MMI_SHOW_FILE_EXT__) 
            if (mmi_fmgr_extract_ext_file_name(buf_filename)!= NULL)
            {
                mmi_fmgr_hide_ext_name(buf_filename);
            }
        #elif !defined( __MMI_SHOW_DAF_FILE_EXT__)
            if(mmi_fmgr_get_file_type_by_filename(buf_filename) ==FMGR_TYPE_DAF)
            {
                ext_name = mmi_fmgr_extract_ext_file_name(buf_filename);
                ext_name -= 2;  /* '.' */
                *ext_name = *(ext_name+1) =  '\0';
            }
        #endif
        
        }
        else
        {
            mmi_ucs2cpy(
                buf_filename,
                (const S8*)(UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_SELECT_BGM)));
            p_setting->bgm = 0;
            /* clean audio_file_path */
            g_slidshow_cntx.audio_file_path[0] = g_slidshow_cntx.audio_file_path[1] = 0;
        }
    }
    else
    {
        buf_filename = (PS8) GetString((U16) STR_ID_SLIDSHOW_SELECT_BGM);
    }

    g_slidshow_cntx.play_type_str[0] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_AUTO_ONCE));
    g_slidshow_cntx.play_type_str[1] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_AUTO_REPEAT));
    g_slidshow_cntx.play_type_str[2] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_MANUAL));
    g_slidshow_cntx.speed_str[0] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_LOW));
    g_slidshow_cntx.speed_str[1] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_MEDIUM));
    g_slidshow_cntx.speed_str[2] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_FAST));
    eff_cnt = 0;
    g_slidshow_cntx.effect_str[eff_cnt++] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_NORMAL));
    g_slidshow_cntx.effect_str[eff_cnt++] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_FADE_IN));
    g_slidshow_cntx.effect_str[eff_cnt++] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_SPLIT));
#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__    
    g_slidshow_cntx.effect_str[eff_cnt++] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_WIPE));
#endif
    g_slidshow_cntx.effect_str[eff_cnt] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_RANDOM));
    g_slidshow_cntx.bgm_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_slidshow_cntx.bgm_str[1] = (UI_string_type) buf_filename;
    g_slidshow_cntx.horz_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_slidshow_cntx.horz_str[1] = (UI_string_type) GetString((U16) (STR_GLOBAL_ON));
    g_slidshow_cntx.sound_effect_str[0] = (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));
    g_slidshow_cntx.sound_effect_str[1] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_AUD1));
    g_slidshow_cntx.sound_effect_str[2] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_AUD2));
    g_slidshow_cntx.sound_effect_str[3] = (UI_string_type) GetString((U16) (STR_ID_SLIDSHOW_AUD3));

    if (g_slidshow_cntx.is_random_effect == TRUE)
    {
        p_setting->effect = SLIDSHOW_EFFECT_RANDOM;
    }
    /* clear inline item */
    memset((void*)wgui_inline_items, 0, sizeof(InlineItem) * SLIDSHOW_SETTING_COUNT * 2);
    item_offset = 0;

    /* start of Category 57 */
    InitializeCategory57Screen();

    /* type of play */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_SLIDSHOW_TYPE_OF_PLAY)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        3,
        (U8 **) g_slidshow_cntx.play_type_str,
        &p_setting->type_of_play);

    /* speed */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_SLIDSHOW_SPEED)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        3,
        (U8 **) g_slidshow_cntx.speed_str,
        &p_setting->speed);

    /* effect */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_SLIDSHOW_EFFECT)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        SLIDSHOW_EFFECT_TOTAL,
        (U8 **) g_slidshow_cntx.effect_str,
        &p_setting->effect);

    /* background music */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_SLIDSHOW_BGM)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        2,
        (U8 **) g_slidshow_cntx.bgm_str,
        &p_setting->bgm);
    g_slidshow_option_bgm_hilight_index = item_offset;
    
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[item_offset++], mmi_slidshow_bgm_highlight_hdlr);



    /* horizontal display */
    SetInlineItemCaption(
        &wgui_inline_items[item_offset++],
        (PU8) GetString((U16) (STR_ID_SLIDSHOW_HORIZONTAL_DISPLAY)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        2,
        (U8 **) g_slidshow_cntx.horz_str,
        &p_setting->horz);

    /* sound effect */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_SLIDSHOW_SOUND_EFFECT)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        4,
        (U8 **) g_slidshow_cntx.sound_effect_str,
        &p_setting->sound_effect);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, SLIDSHOW_SETTING_COUNT * 2, input_buffer);
    }

    /* show category */
    ShowCategory57Screen(
        STR_ID_SLIDSHOW_SETTING,
        GetRootTitleIcon(MENU_ID_SLIDSHOW_APP),
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);
    /* set key hdlr */

    SetCategory57RightSoftkeyFunctions(mmi_slidshow_setting_screen_confirm_save, GoBackHistory);
    EnableCategory57ScreenDone();
    RegisterHighlightHandler(mmi_slidshow_option_hilight_hdlr);

    if (g_slidshow_cntx.cat57_done_flag)
    {
        g_slidshow_cntx.cat57_done_flag = FALSE;
        set_wgui_inline_list_menu_changed();
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_setting_screen
 * DESCRIPTION
 *  exit slide show setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_exit_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 n_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h.scrnID = SCR_ID_SLIDSHOW_SETTING;
    CloseCategory57Screen();
    h.entryFuncPtr = mmi_slidshow_entry_setting_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & n_history);
    GetCategory57History(h.guiBuffer);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_setting_screen_confirm_save
 * DESCRIPTION
 *  popup confirm for slideshow setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_setting_screen_confirm_save(void)
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
        get_string(STR_ID_SLIDSHOW_SAVE_SETTING),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_slidshow_setting_inline_done_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_slidshow_GoBackHistory1,KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_GoBackHistory2
 * DESCRIPTION
 *  popup confirm for slideshow setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_GoBackHistory1(void)
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
 *  mmi_slidshow_setting_inline_done_hdlr
 * DESCRIPTION
 *  done hdlr for slide show setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_setting_inline_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* type of play */

    g_slidshow_cntx.is_typeofplay_set = p_setting->type_of_play;

    /* speed */

    g_slidshow_cntx.is_speed_set = p_setting->speed;

    switch (g_slidshow_cntx.is_speed_set)
    {
        case SLIDSHOW_LOW:
            g_slidshow_cntx.speed_value = SLIDSHOW_LOW_SPEED;
            break;

        case SLIDSHOW_MEDIUM:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;

        case SLIDSHOW_FAST:
            g_slidshow_cntx.speed_value = SLIDSHOW_FAST_SPEED;
            break;

        default:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;
    }

    /* Effect */

    g_slidshow_cntx.is_effect_set = p_setting->effect;

    if (g_slidshow_cntx.is_effect_set == SLIDSHOW_EFFECT_RANDOM)
    {
        g_slidshow_cntx.is_random_effect = TRUE;
    }
    else
    {
        g_slidshow_cntx.is_random_effect = FALSE;
    }

    /* BGM */
    g_slidshow_cntx.is_bgm_set = p_setting->bgm;
    if (g_slidshow_cntx.is_bgm_set)
    {
        if (mmi_ucs2strlen(g_slidshow_cntx.audio_file_path) == 0)
        {
            g_slidshow_cntx.is_bgm_set = p_setting->bgm = 0;
        }
        else
        {
            mmi_fmgr_util_store_filepath(g_slidshow_cntx.audio_file_path, FMGR_PATH_ID_SLIDE_SHOW_AUDIO);
        }
    }
    else
    {
        memset(g_slidshow_cntx.audio_file_path, 0,FMGR_PATH_BUFFER_SIZE);
    }


    /* horz display */

    g_slidshow_cntx.is_horz_view_set = p_setting->horz;

    /* Sound Effect */
    g_slidshow_cntx.is_sound_effect_selected = p_setting->sound_effect;

    p_setting->is_bgm_path_short = g_slidshow_cntx.is_short_path;

    /* store setting to nvram */
    mmi_slidshow_store_setting();

    DisplayPopup((PU8) GetString(STR_GLOBAL_SAVED), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    g_slidshow_cntx.is_edited = FALSE;
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_load_setting
 * DESCRIPTION
 *  load setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load data from nvram */
    mmi_slidshow_load_data();

    g_slidshow_cntx.is_typeofplay_set = p_setting->type_of_play;

    g_slidshow_cntx.is_speed_set = p_setting->speed;

    switch (g_slidshow_cntx.is_speed_set)
    {
        case SLIDSHOW_LOW:
            g_slidshow_cntx.speed_value = SLIDSHOW_LOW_SPEED;
            break;

        case SLIDSHOW_MEDIUM:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;

        case SLIDSHOW_FAST:
            g_slidshow_cntx.speed_value = SLIDSHOW_FAST_SPEED;
            break;

        default:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;
    }

    g_slidshow_cntx.is_effect_set = p_setting->effect;

    if (g_slidshow_cntx.is_effect_set == SLIDSHOW_EFFECT_RANDOM)
    {
        g_slidshow_cntx.is_random_effect = TRUE;
    }

    g_slidshow_cntx.is_bgm_set = p_setting->bgm;

    if (g_slidshow_cntx.is_bgm_set)
    {
        mmi_fmgr_util_load_filepath(g_slidshow_cntx.audio_file_path, FMGR_PATH_ID_SLIDE_SHOW_AUDIO);
    }
    else
    {
        g_slidshow_cntx.audio_file_path[0] = g_slidshow_cntx.audio_file_path[1] = '\0';
    }

    g_slidshow_cntx.is_horz_view_set = p_setting->horz;

    g_slidshow_cntx.is_sound_effect_selected = p_setting->sound_effect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_store_setting
 * DESCRIPTION
 *  store setting to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slidshow_store_data();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_select_audio
 * DESCRIPTION
 *  entry select audio from file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_select_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_AUDIO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    #ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
    #endif /* __DRM_V02__ */

    mmi_fmgr_select_path_and_enter(
        APP_SLIDESHOW,
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
        filter,
        (PS8) (S8*) L"root",
        (PsExtFuncPtr) mmi_slidshow_fmgr_select_audio_result_callback);

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_fmgr_select_audio_result_callback
 * DESCRIPTION
 *  select folder result callback function
 * PARAMETERS
 *  filepath        [?]         
 *  is_short        [IN]        
 *  filename(?)     [IN]        Filename(not used here)
 *  is_shot(?)      [IN]        Is it short naming
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_fmgr_select_audio_result_callback(void *filepath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath == NULL)
    {
        GoBackHistory();
        return;
    }
    else
    {
        g_slidshow_cntx.is_short_path = is_short;
        mmi_ucs2cpy((PS8)g_slidshow_cntx.audio_file_path, (PS8) filepath);
        g_slidshow_cntx.setting.bgm = TRUE;
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, TRUE, 1000, SUCCESS_TONE);
        g_slidshow_cntx.cat57_done_flag = TRUE;

        DeleteUptoScrID(SCR_ID_SLIDSHOW_SETTING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_video_screen
 * DESCRIPTION
 *  enter video play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_PLAYER__
static void mmi_slidshow_entry_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U8 *gui_buffer;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    PU8 buf_ptr;
    U16 rotate;
    FS_HANDLE fs_handle;
    MDI_RESULT ret = 0;
    mdi_video_info_struct vid_info;
    U32 flg_blt, flg_play;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */
    EntryNewScreen(SCR_ID_SLIDSHOW_PLAY, mmi_slidshow_exit_video_screen, mmi_slidshow_entry_video_screen, NULL);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_owner(MDI_TV_OWNER_APP);
            /* start mode - full screen preview update */
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_FULL_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */

    gui_buffer = GetCurrGuiBuffer(SCR_ID_SLIDSHOW_PLAY);

    if (gui_buffer == NULL)
    {
        g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    }

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* register key hdlr */
    if (!g_slidshow_cntx.error_code || !g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_MANUAL)
    {
        /* don't show lsk if it's back from error and video is failed */
        SetKeyHandler(mmi_slidshow_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_lsk_release, KEY_LSK, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_slidshow_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_slidshow_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* set keys */
    mmi_slidshow_set_keys();

    /* get end key hdlr and hook ours */
    g_slidshow_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_slidshow_end_key_press, KEY_END, KEY_EVENT_DOWN);

    g_slidshow_cntx.effect_finish = TRUE;
   /*----------------------------------------------------------------*/
   /* Layers                                                         */
   /*----------------------------------------------------------------*/
    gdi_layer_multi_layer_enable();
    gdi_layer_get_base_handle(&g_slidshow_cntx.base_layer_handle);
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        rotate = GDI_LAYER_ROTATE_270;
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        gdi_layer_resize(lcd_width, lcd_height);
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {
        rotate = GDI_LAYER_ROTATE_0;
    }
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif

        /* get file name from NVRAM */
    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);

    if (!mmi_is_redrawing_bk_screens() && !g_slidshow_cntx.error_code)        /* not small screen */
    {
    #ifdef __DRM_SUPPORT__
        if (gui_buffer != NULL)
        {
            mdi_video_ply_drm_disable_consume_count();  /* do not consume rights if back from interrupt */
        }
    #endif /* __DRM_SUPPORT__ */
    
        /* open video file */
        ret = mdi_video_ply_open_clip_file(buf_filename, &vid_info);
        if (ret >= 0)
        {
            g_slidshow_cntx.is_vdo_opened = TRUE;
            g_slidshow_cntx.vdo_total_duration = vid_info.total_time_duration;
            if (g_slidshow_cntx.v_state != SLIDSHOW_VIDEO_PAUSE)
            {
                g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
            }
        }
        else
        {
            /* check if it's invalid format or a file not found */
            fs_handle = FS_Open((U16*) buf_filename, FS_READ_ONLY);
            if (fs_handle < 0 )
            {
                g_slidshow_cntx.osd_layer_buf_ptr = NULL;
                g_slidshow_cntx.osd_layer_handle = NULL;
                g_slidshow_cntx.is_video_type = FALSE;
                DisplayPopup(
                    (PU8) GetString(FMGR_FS_FILE_NOT_FOUND_TEXT), 
                    IMG_GLOBAL_ERROR, 
                    1, 
                    1000, 
                    ERROR_TONE);
                DeleteUptoScrID(SCR_ID_SLIDSHOW_APP);
                DeleteNHistory(1);
                return;
            }
            FS_Close(fs_handle);
            g_slidshow_cntx.is_vdo_opened= FALSE;
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
   
        #ifdef __DRM_SUPPORT__         /* valid after 07A*/
            if (ret == MDI_RES_VDOPLY_ERR_DRM_PROHIBITED)              
            {
                g_slidshow_cntx.is_vdo_opened = FALSE;      /* redraw osd only, don't need to open vdo */
                g_slidshow_cntx.play_layer_buf_ptr = NULL;
                g_slidshow_cntx.error_code = SLIDESHOW_ERR_PROHIBIT;
            }
        #endif /* __DRM_SUPPORT__ */   /* valid after 07A*/
        }

        /* create preview layer */
        gdi_image_util_fit_bbox(
            lcd_width,
            lcd_height,
            vid_info.width,
            vid_info.height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);
        buf_ptr = (PU8) mmi_frm_scrmem_alloc( (resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3 );
        if (buf_ptr!=NULL)
        {
            g_slidshow_cntx.play_layer_buf_ptr=buf_ptr;
        }
        ASSERT(buf_ptr != NULL);
        gdi_layer_create_using_outside_memory(
            resized_offset_x,
            resized_offset_y,
            resized_width,
            resized_height,
            &g_slidshow_cntx.play_layer_handle,
            (PU8) buf_ptr,
            (S32) ((resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3) );
    #ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    #endif
    }
    else
    {
        g_slidshow_cntx.is_vdo_opened = FALSE;      /* redraw osd only, don't need to open vdo */
        g_slidshow_cntx.play_layer_buf_ptr = NULL;
    }
    /*----------------------------------------------------------------*/
    /* allocate osd layer                                             */
    /*----------------------------------------------------------------*/
    /* use double buffer for osd layer */
    g_slidshow_cntx.osd_layer_buf_ptr = g_slidshow_layer1_buffer;
    gdi_layer_create_cf_double_using_outside_memory(
        GDI_LCD->cf,
        0,
        0,
        lcd_width,
        lcd_height,
        &g_slidshow_cntx.osd_layer_handle, 
        g_slidshow_layer1_buffer, 
        SLIDESHOW_FRAME_BUFFER_SIZE, 
        g_slidshow_layer2_buffer, 
        SLIDESHOW_FRAME_BUFFER_SIZE);

    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    if (!mmi_is_redrawing_bk_screens() && !g_slidshow_cntx.error_code)
    {
    #ifdef GDI_USING_LAYER_BACKGROUND        
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.play_layer_handle, 
            g_slidshow_cntx.osd_layer_handle,
            0,
            0);    
    #else
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.base_layer_handle, 
            g_slidshow_cntx.play_layer_handle, 
            g_slidshow_cntx.osd_layer_handle, 
            0);
    #endif /* GDI_USING_LAYER_BACKGROUND */
    }
    else
    {
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.base_layer_handle, 
            g_slidshow_cntx.osd_layer_handle, 
            0,
            0);    
    }
    /************************************************/
    /* play video                                   */
    /************************************************/
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens() && !g_slidshow_cntx.error_code)
    {
        if (!g_slidshow_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_slidshow_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */

    if ( g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_STOP && !g_slidshow_cntx.error_code)
    {
        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PLAYING;
    }
    /* draw both OSD buffer first. */
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    mmi_slidshow_main_draw_osd();       
    gdi_layer_toggle_double();
    mmi_slidshow_main_draw_osd();    
    gdi_layer_pop_and_restore_active();

    if (g_slidshow_cntx.is_vdo_opened && (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING || g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PAUSE))
    {
        /* Get first frame and start to play */
        if (g_slidshow_cntx.play_time)
        {
            ret = mdi_video_ply_seek_and_get_frame(g_slidshow_cntx.play_time, g_slidshow_cntx.play_layer_handle);
        }
        else
        {
            ret = mdi_video_ply_seek_and_get_frame(0, g_slidshow_cntx.play_layer_handle);
        }

        if (ret >= 0)
        {
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            if (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING)
            {
            #ifdef GDI_USING_LAYER_BACKGROUND
                flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
                flg_play = GDI_LAYER_ENABLE_LAYER_0;
            #else  /* GDI_USING_LAYER_BACKGROUND */
                flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
                flg_play = GDI_LAYER_ENABLE_LAYER_1;
            #endif /* GDI_USING_LAYER_BACKGROUND */
                mdi_audio_set_volume(VOL_TYPE_MEDIA, g_slidshow_cntx.audio_volume);
                ret = mdi_video_ply_play(
                        g_slidshow_cntx.play_layer_handle,
                        flg_blt,
                        flg_play,
                        1,                              /* repeat count */
                        TRUE,                           /* update to LCM or not */
                        TRUE,                           /* play aud */
                        MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                        rotate,
                        100,                            /* 1x play speed */
                        mmi_slidshow_play_finish_callback);    /* hook callback */
                if(ret < 0)
                {
                    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
                    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
                    gdi_layer_toggle_double();
                    mmi_slidshow_main_draw_osd();                    
                    gdi_layer_pop_and_restore_active();
                    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);                    
                }
            }
        }
    }
    if ((!g_slidshow_cntx.is_vdo_opened || ret < 0) && !g_slidshow_cntx.error_code)
    {
        /* something wrong, clear play layer */
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_slidshow_cntx.is_video_type)
        {
            gui_start_timer(SLIDSHOW_OSD_FADE_OUT_TIME, mmi_slidshow_osd_fade_cyclic);
        }
        else if(g_slidshow_cntx.osd_opacity <= 255 && g_slidshow_cntx.osd_opacity > 0)
        {
            gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
            mmi_slidshow_osd_fade_cyclic();
        }
    }
    else
    {
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        return;
    }

    if(g_slidshow_cntx.error_code == SLIDESHOW_ERR_PROHIBIT)
    {
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRM_LOCKED, &resized_width, &resized_height);
        gdi_image_draw_id( (lcd_width - resized_width)>>1, (lcd_height - resized_height)>>1, IMG_ID_FMGR_DRM_LOCKED);
    #ifdef __MMI_TVOUT__        
        if (mdi_tvout_is_enable())
        {
            mdi_tvout_set_owner(MDI_TV_OWNER_APP);
        }
        mmi_slidshow_draw_img_2_tv(NULL, IMG_ID_FMGR_DRM_LOCKED,resized_width,resized_height, FALSE, TRUE);
    #endif 
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
        {
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }

#ifdef SLIDSHOW_POWER_SAVING
        if (g_slidshow_cntx.is_edited)
        {
            gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
        }
#endif

    }
    else if ((ret < 0) || (!g_slidshow_cntx.is_vdo_opened))
    {
    #ifdef __MMI_TVOUT__
        /* restore TV out mode */
        if (mdi_tvout_is_enable() && !g_slidshow_cntx.error_code)
        {
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);              /* restore back to GDI */
            mdi_tvout_set_mode(
                MDI_TV_MODE_LCD_SCR,
                0,  /* layer_width */
                0); /* layer_height */                          /* restore back to start mode1 */
        }
    #endif /* __MMI_TVOUT__ */ 

        if (gui_buffer == NULL)
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);       
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {

                DisplayPopupRotated((PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT), IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE, 
                                MMI_FRM_SCREEN_ROTATE_270);
                return;
            }
            else
        #endif                
            {
                DisplayPopup((PU8) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT), IMG_GLOBAL_WARNING, 1, 1000, WARNING_TONE);
                return;
            }
        }
        else
        {
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
            {
                gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_auto_next);
            }
        }
        
        TurnOffBacklight();
        
    }
    g_slidshow_cntx.is_video_type = FALSE;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_slidshow_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_slidshow_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_slidshow_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_video_screen
 * DESCRIPTION
 *  exit video play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_exit_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL flat_play_layer = g_slidshow_cntx.is_vdo_opened;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);

    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_right_arrow_release);
    gui_cancel_timer(mmi_slidshow_left_arrow_release);
    gui_cancel_timer(mmi_slidshow_apply_index_change);

#ifdef SLIDSHOW_POWER_SAVING
    gui_cancel_timer(mmi_slidshow_turn_off_bl_hdlr);    
#endif

    g_slidshow_cntx.is_bgm_play = TRUE;
        /* stop video playing */
    if (g_slidshow_cntx.play_layer_buf_ptr != NULL)
    {
        mdi_video_ply_stop();
        if (g_slidshow_cntx.v_state != SLIDSHOW_VIDEO_PAUSE)
        {
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
        }
        mdi_video_ply_get_cur_play_time(&g_slidshow_cntx.play_time);
        if (g_slidshow_cntx.is_vdo_opened)
        {
            mdi_video_ply_close_clip_file();
            if (g_slidshow_cntx.v_state != SLIDSHOW_VIDEO_PAUSE)            
            {
                g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
            }
            g_slidshow_cntx.is_vdo_opened = FALSE;
        }
 
#if defined(LCM_ROTATE_SUPPORT)
        if (g_slidshow_cntx.error_code)
        {
            gdi_layer_flatten_previous_to_base();
        }
        else if (flat_play_layer)
        {
            gdi_layer_flatten_to_base(g_slidshow_cntx.play_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
        }
#else
        if (g_slidshow_cntx.error_code)
        {
            gdi_layer_flatten_previous_to_base();
        }
#endif
    }

    /* free layer */

    if ( g_slidshow_cntx.osd_layer_handle != NULL)
    {
        g_slidshow_cntx.osd_layer_buf_ptr = NULL;
        gdi_layer_free(g_slidshow_cntx.osd_layer_handle);
        g_slidshow_cntx.osd_layer_handle = GDI_NULL_HANDLE;
    }
    if (g_slidshow_cntx.play_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.play_layer_handle);
        mmi_frm_scrmem_free((void*)g_slidshow_cntx.play_layer_buf_ptr);
        g_slidshow_cntx.play_layer_buf_ptr = NULL;
        g_slidshow_cntx.play_layer_handle= GDI_NULL_HANDLE;
    }
    
    if ((g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW) && (!g_slidshow_cntx.is_video_type))
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_set_rotate_by_layer(FALSE);
    }

    gdi_layer_set_blt_layer(g_slidshow_cntx.base_layer_handle, 0, 0, 0);

    TurnOffBacklight();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* disenable multi-layer */
    gdi_layer_multi_layer_disable();

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_WHITE);
#endif

#ifdef __MMI_SUBLCD__
    if (g_slidshow_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_slidshow_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

    /* restore TV out mode */
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (SCR_ID_SLIDSHOW_PLAY != GetActiveScreenId())
        {
            /* restore back to GDI */
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            /* restore back to start mode1 */
            mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR,0,0);
        }
        else
        {
            /* change mode to clear layer */
            mdi_tvout_set_mode(MDI_TV_MODE_OWNER_DRAW, 16, 16);
        }
    }
#endif /* __MMI_TVOUT__ */


}

#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_VIDEO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_play_finish_callback
 * DESCRIPTION
 *  Play finish callback function
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_play_finish_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_toggle_double();
    mmi_slidshow_main_draw_osd();
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);    
    
    if (result >= 0)
    {
        /* success play finished */
        if (g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL)
        {
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }
        /* in MANUAL mode, change state to video playback finished. unset LSK  from pause */
    }
    else
    {
        if (result == MDI_RES_VDOPLY_ERR_DRM_DURATION_USED)
        {
            DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER; 
        }
        else if (g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL)
        {
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }
    }
}
#endif /* __MMI_VIDEO_PLAYER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_reset_osd_fade
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_reset_osd_fade(BOOL sleep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.osd_opacity != 255)
    {
        g_slidshow_cntx.osd_opacity = 255;

        gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.osd_opacity);
        gdi_layer_pop_and_restore_active();
    }

    if (sleep)
    {
        /* start fade out timer */
        gui_start_timer(SLIDSHOW_OSD_FADE_OUT_TIME, mmi_slidshow_osd_fade_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_osd_fade_cyclic
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_osd_fade_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.osd_layer_handle == GDI_NULL_HANDLE)
    {
        gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
        return;
    }

    /* reset osd fade out timer */
    if (g_slidshow_cntx.osd_opacity > SLIDSHOW_OSD_FADE_OUT_VALUE)
    {
        g_slidshow_cntx.osd_opacity -= SLIDSHOW_OSD_FADE_OUT_VALUE;
        gui_start_timer(100, mmi_slidshow_osd_fade_cyclic);
    }
    else
    {
        g_slidshow_cntx.osd_opacity = 0;
    }

    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.osd_opacity);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_osd_show_up
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_osd_show_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register key hdlr */
    if (g_slidshow_cntx.osd_layer_handle == GDI_NULL_HANDLE)
    {
        return;
    }

    SetKeyHandler(mmi_slidshow_end_key_press, KEY_END, KEY_EVENT_DOWN);
    mmi_slidshow_reset_osd_fade(TRUE);

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_next_file
 * DESCRIPTION
 *  entry next file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILE_INFO_STRUCT file_info;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = mmi_fmgr_kernel_get_cur_idx();
    mmi_fmgr_kernel_get_file_info(index, &file_info);
 
    g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;  /* becuz file index is changed. */
    g_slidshow_cntx.idx2shift = 0;

#ifdef __DRM_V02__
    mmi_fmgr_get_drm_file_type_by_path(file_info.file_name, &file_info.file_type);
#endif
    
#ifdef __MMI_VIDEO_PLAYER__    
    if (FMGR_FILTER_IS_SET_VIDEO(&file_info.file_type))
    {
        g_slidshow_cntx.is_video_file = TRUE;
        g_slidshow_cntx.is_video_type = TRUE;
        EntryNewScreen(SCR_ID_SLIDSHOW_PLAY, NULL, NULL, NULL);
        DeleteScreenIfPresent(SCR_ID_SLIDSHOW_PLAY);
        gui_cancel_timer(mmi_slidshow_auto_next);
        gui_cancel_timer(mmi_slidshow_right_arrow_release);
        g_slidshow_cntx.play_time = 0;
        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
        mmi_slidshow_entry_video_screen();
    }
    else
#endif /* __MMI_VIDEO_PLAYER__ */    
    {
        g_slidshow_cntx.is_video_file = FALSE;
        g_slidshow_cntx.is_image_type = TRUE;
        g_slidshow_cntx.is_animation = FALSE;
        g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
        EntryNewScreen(SCR_ID_SLIDSHOW_PLAY, NULL, NULL, NULL);
        DeleteScreenIfPresent(SCR_ID_SLIDSHOW_PLAY);
        mmi_slidshow_entry_image_display_screen();
    }
}


#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_wipe_cyclic
 * DESCRIPTION
 *  wipe image cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_effect_wipe_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.effect_value < 0)
    {
        gui_start_timer(100, mmi_slidshow_effect_wipe_cyclic);
    }
    else
    {
        mmi_slidshow_image_effect_finished();    /* final effect has been drawed. */
    }
    

    for (; i && (g_slidshow_cntx.effect_value <= 0); i--)
    {  
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);        
        gdi_layer_set_position(0, g_slidshow_cntx.effect_value);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, g_slidshow_cntx.effect_value + lcd_height - 1);
        g_slidshow_cntx.effect_value += SLIDSHOW_EFFECT_SHIFT_VALUE;
    }
    /* boundary condition correction for 176x220,128x128 screens */
    if (g_slidshow_cntx.effect_value >0 && 
        g_slidshow_cntx.effect_value < SLIDSHOW_EFFECT_SHIFT_VALUE)
    {
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_set_position(0, 0);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        gdi_layer_pop_and_restore_active();        
    }
}
#endif /* __MMI_SLIDSHOW_WIPE_ENABLE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_split_cyclic
 * DESCRIPTION
 *  split image cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_effect_split_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.effect_value < 0)
    {
        gui_start_timer(100, mmi_slidshow_effect_split_cyclic);
    }
    else
    {
        mmi_slidshow_image_effect_finished();
    }

    for (; i && (g_slidshow_cntx.effect_value <= 0); i--)
    {
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
        gdi_layer_set_position(g_slidshow_cntx.effect_value, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
        gdi_layer_set_position(-g_slidshow_cntx.effect_value + lcd_width / 2, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        g_slidshow_cntx.effect_value += SLIDSHOW_EFFECT_SHIFT_VALUE;
    }
    
    if (g_slidshow_cntx.effect_value >0 && 
        g_slidshow_cntx.effect_value < SLIDSHOW_EFFECT_SHIFT_VALUE)
    {
        g_slidshow_cntx.effect_value = 0;
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
        gdi_layer_set_position(g_slidshow_cntx.effect_value, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
        gdi_layer_set_position(-g_slidshow_cntx.effect_value + lcd_width / 2, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_fade_in_cyclic
 * DESCRIPTION
 *  fade in image cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_effect_fade_in_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.effect_value < 255)
    {
        gui_start_timer(100, mmi_slidshow_effect_fade_in_cyclic);
    }
    else
    {
        mmi_slidshow_image_effect_finished();
    }
    gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
    for (; i && (g_slidshow_cntx.effect_value <= 255); i--)
    {
        gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.effect_value);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        g_slidshow_cntx.effect_value += SLIDSHOW_OSD_FADE_IN_VALUE / 2;
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_finish
 * DESCRIPTION
 *  draw animation, start timer after image effect finishes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_image_effect_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 p_filename = NULL;
    gdi_result ret_anim;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.effect_finish = TRUE;
    if(g_slidshow_cntx.is_diff_anim)
    {
        return;
    }
    if ( g_slidshow_cntx.is_animation && g_slidshow_cntx.result != -1)
    {
        /* animation image, start to play animation */
        if(g_slidshow_cntx.h_animate != GDI_NULL_HANDLE)
        {
            return;                                         /* if an animation is already started, do nothing. */
        }
        /* save tvout bandwidth */
        gdi_layer_set_blt_layer(g_slidshow_cntx.play_layer_handle, g_slidshow_cntx.osd_layer_handle,0,0);
        p_filename = (PS8) gui_malloc(FMGR_PATH_BUFFER_SIZE);
        ASSERT(p_filename != NULL);

        mmi_fmgr_util_load_filepath(p_filename, FMGR_PATH_ID_SLIDE_SHOW_PLAY);

        gdi_anim_set_last_frame_callback(mmi_slidshow_anim_finish_callback);
    #ifdef __MMI_TVOUT__
        if (mdi_tvout_is_enable())
        {
            gdi_anim_set_draw_after_callback(mmi_slidshow_anim_blt_after_callback);
        }
    #endif /* __MMI_TVOUT__ */
    
        if (!g_slidshow_cntx.is_diff_anim)
        {
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            ret_anim = gdi_anim_draw_file_resized(
                 g_slidshow_cntx.resized_image_offset_x,
                 g_slidshow_cntx.resized_image_offset_y,
                 g_slidshow_cntx.resized_image_width,
                 g_slidshow_cntx.resized_image_height,
                 (PS8) p_filename,
                 (&g_slidshow_cntx.h_animate));
            gdi_layer_pop_and_restore_active();
            if (ret_anim < GDI_SUCCEED)
            {         
                g_slidshow_cntx.result = -1;
            }
        } /* if (g_slidshow_cntx.is_diffanim) */
        gui_free(p_filename);    
    }
    
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
    {
        g_slidshow_cntx.time_4_next_img= FALSE;
        if(g_slidshow_cntx.is_animation && g_slidshow_cntx.result != -1)
        {
            gui_cancel_timer(mmi_slidshow_slice_time_out);
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_slice_time_out);
        }
        else
        {
            gui_cancel_timer(mmi_slidshow_auto_next);
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_anim_finish_callback
 * DESCRIPTION
 *  start timer for next image if animation finished playing.
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_slidshow_anim_finish_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == GDI_SUCCEED)
    {
        if(g_slidshow_cntx.time_4_next_img)
        {
            if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
            {
                /*stop animation and start timer.*/
        #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    gdi_anim_stop(g_slidshow_cntx.h_animate_tv);
                    g_slidshow_cntx.h_animate_tv = GDI_NULL_HANDLE;
                }
        #endif
                if(g_slidshow_cntx.h_animate != GDI_NULL_HANDLE)
                {
                    gdi_anim_stop(g_slidshow_cntx.h_animate);
                    g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
                }
                gui_cancel_timer(mmi_slidshow_auto_next);
                gui_start_timer(SLIDSHOW_ANIM_NEXT_IMG_DELAY, mmi_slidshow_auto_next);
            }
        }
    }
    else
    {
        if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
        {            
            /* this is still image, callback will only be invoked once */
            gui_cancel_timer(mmi_slidshow_slice_time_out);
            gui_cancel_timer(mmi_slidshow_auto_next);
            gui_start_timer(g_slidshow_cntx.speed_value,mmi_slidshow_auto_next);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_slice_time_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_slidshow_slice_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.time_4_next_img = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_bgm_highlight_hdlr
 * DESCRIPTION
 *  set lsk for inline item
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_bgm_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_slidshow_option_bgm_select_file_hilight_index = index;

    if (index == SLIDSHOW_BGM_SELECT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_slidshow_bgm_pre_entry_file_option, KEY_EVENT_UP);
    }
    else
    {
       ChangeLeftSoftkey(NULL,NULL);      
       ClearKeyHandler(KEY_LSK,KEY_EVENT_UP);
    }



}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_option_highlight_hdlr
 * DESCRIPTION
 *  set lsk for option menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_option_hilight_hdlr(S32 index)
{

    if(index == g_slidshow_option_bgm_hilight_index)
    {
        /* bgm is hilighted in the option menu */
        if(g_slidshow_option_bgm_select_file_hilight_index == SLIDSHOW_BGM_SELECT)
        {
            /* not off */
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);        
            SetLeftSoftkeyFunction(mmi_slidshow_bgm_pre_entry_file_option, KEY_EVENT_UP);
        }
    }
    else
    {
        /* set left soft key to null */
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_bgm_pre_entry_file_option
 * DESCRIPTION
 *  select option to enter bgm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_bgm_pre_entry_file_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(g_slidshow_cntx.audio_file_path) != 0)
    {
        mmi_slidshow_entry_bgm_file_option(1);
    }
    else
    {
        mmi_slidshow_entry_bgm_file_option(2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_bgm_file_option
 * DESCRIPTION
 *  entry bgm screen
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_entry_bgm_file_option(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *guiBuffer;
    U16 nStrItemList[5];
    U16 nNumofItem;
    U8 *hintList[5];    /* Array for hint */
    U32 HideItemId = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SLIDSHOW_BGM_FILE_OPTION, NULL, mmi_slidshow_bgm_pre_entry_file_option, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SLIDSHOW_BGM_FILE_OPTION);      /* Getting the Index from history */

    nNumofItem = GetNumOfChild(MENU_ID_SLIDSHOW_BGM_FILE_OPTION);
    GetSequenceStringIds(MENU_ID_SLIDSHOW_BGM_FILE_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_SLIDSHOW_BGM_FILE_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Construct List To Show Hint */
    ConstructHintsList(MENU_ID_SLIDSHOW_BGM_FILE_OPTION, hintList);

    /* File not selected */
    if (type == 2)
    {
        HideItemId = GetChildMenuIDIndexByParentMenuID(MENU_ID_SLIDSHOW_BGM_FILE_OPTION, MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY);
        if (HideItemId != -1)
        {
            ResetBit(maskingByte, HideItemId);
            MaskHiliteItems(MENU_ID_SLIDSHOW_BGM_FILE_OPTION, maskingByte);
            MaskStringItems(hintList, (U8) nNumofItem, maskingByte);
            nNumofItem = MaskItems(nStrItemList, (U8) nNumofItem, maskingByte);
        }
    }
    else
    {
        SetHiliteHandler(MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY, mmi_slidshow_highlight_audio_file_play);
    }

    /* Screen with hint */
    ShowCategory52Screen(
        STR_ID_SLIDSHOW_ASSOCIATE_AUDIO,
        GetRootTitleIcon(MENU_ID_SLIDSHOW_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        hintList,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_entry_select
 * DESCRIPTION
 *  highlighter for select audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_hilight_entry_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_slidshow_entry_select_audio, KEY_EVENT_UP);
    SetKeyHandler(mmi_slidshow_entry_select_audio, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_highlight_audio_file_play
 * DESCRIPTION
 *  highligher to play audio file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_highlight_audio_file_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_slidshow_entry_audio_file_play, KEY_EVENT_UP);
    SetKeyHandler(mmi_slidshow_entry_audio_file_play, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_audio_file_play
 * DESCRIPTION
 *  Play Audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_entry_audio_file_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_single_play((UI_string_type) g_slidshow_cntx.audio_file_path, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_aud_is_playing
 * DESCRIPTION
 *  return status about wheatehr BGM is playing in slidshow or not
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if slideshow will play (or is playing BGM while playing)
 *****************************************************************************/
BOOL mmi_slidshow_aud_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return (g_slidshow_cntx.is_bgm_set && g_slidshow_cntx.is_valid_bgm || (SLIDSHOW_VIDEO_PLAYING == g_slidshow_cntx.v_state));
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_arrow_key_osd
 * DESCRIPTION
 *  draws softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_draw_arrow_key_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 offset_x;
    S32 offset_y;
    S32 image_width;
    S32 image_height;
    S32 spacing = 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    /* draw icon */
    gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_LEFT_ARROW, &image_width, &image_height);

    offset_y = lcd_height - image_height - 1;
    offset_x = ((lcd_width - (image_width << 1) - spacing) >> 1);
    if (g_slidshow_cntx.is_left_arrow_pressed)
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_SLIDSHOW_LEFT_ARROW_SEL);
    }
    else
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_SLIDSHOW_LEFT_ARROW);
    }
    
#ifdef __MMI_TOUCH_SCREEN__
    g_slidshow_touch_screen_cntx.left_arrow.pos_x = offset_x;
    g_slidshow_touch_screen_cntx.left_arrow.pos_y = offset_y;
    g_slidshow_touch_screen_cntx.left_arrow.width = image_width;
    g_slidshow_touch_screen_cntx.left_arrow.height = image_height;
#endif /* __MMI_TOUCH_SCREEN__ */ 

    offset_x += image_width + spacing;
    if (g_slidshow_cntx.is_right_arrow_pressed)
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_SLIDSHOW_RIGHT_ARROW_SEL);
    }
    else
    {
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_SLIDSHOW_RIGHT_ARROW);
    }
#ifdef __MMI_TOUCH_SCREEN__
    g_slidshow_touch_screen_cntx.right_arrow.pos_x = offset_x;
    g_slidshow_touch_screen_cntx.right_arrow.pos_y = offset_y;
    g_slidshow_touch_screen_cntx.right_arrow.width = image_width;
    g_slidshow_touch_screen_cntx.right_arrow.height = image_height;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_icon_key_press
 * DESCRIPTION
 *  right arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_icon_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_right_arrow_pressed = TRUE;

    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();        
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }
    gdi_layer_pop_and_restore_active();    

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_icon_key_release
 * DESCRIPTION
 *  right arrow key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_icon_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_right_arrow_pressed = FALSE;
    
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle); 
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();   /* redraw softkey too for video */
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_icon_key_press
 * DESCRIPTION
 *  left arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_icon_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_left_arrow_pressed = TRUE;
    
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();        
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }

    gdi_layer_pop_and_restore_active();
    
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_icon_key_release
 * DESCRIPTION
 *  left arrow key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_icon_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_left_arrow_pressed = FALSE;
    
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);  
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}

#ifdef __MMI_TVOUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_img_2_tv
 * DESCRIPTION
 *  output the image to tv. display a black block if the filename and image id is null.
 *  if both image_id and file name is specified, will ignore the image id.
 * PARAMETERS
 * p_filename   [IN]    the file to be draw (with full path)
 * img_id       [IN]    Image id to be draw
 * img_w        [IN]    the width of image
 * img_h        [IN]    the height of image
 * anim         [IN]    is animation or not.
 * reset_tvout  [IN]    reset the mode of tvout or not. (reset mode will clean TV layer with black)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_draw_img_2_tv(PS8 p_filename, U16 img_id, S32 img_w, S32 img_h, BOOL anim, BOOL reset_tvout)
{   
    S32 tvout_resized_offset_x;
    S32 tvout_resized_offset_y;
    S32 tvout_resized_img_w;    /* the resized image w/h on TV */
    S32 tvout_resized_img_h;
    S32 tvout_max_width;        /* tvout max size */
    S32 tvout_max_height;
    S32 tvout_layer_w;          /* the actually tvout layer size (cuz we need to make layer pix %8 ==0 ) */
    S32 tvout_layer_h;
    GDI_HANDLE tvout_layer;

    S32 offset_x = 0;
    S32 offset_y = 0;
    
    if (mdi_tvout_is_enable())
    {
        if(p_filename != NULL)
        {
            tvout_resized_img_w = g_slidshow_cntx.resized_image_width;
            tvout_resized_img_h = g_slidshow_cntx.resized_image_height;
        }
        else if (img_id)
        {
            /* get best fit size for PAL/NTSC */
            mdi_tvout_get_owner_draw_best_size(&tvout_max_width, &tvout_max_height);           
            if ((tvout_max_width >= img_w) && (tvout_max_height >= img_h))
            {
                ASSERT(img_w > 0 && img_h > 0 );        /* image width/height must > 0 */
                tvout_resized_img_w = img_w;
                tvout_resized_img_h = img_h;
            }
            else
            {
                gdi_image_util_fit_bbox(
                    tvout_max_width,
                    tvout_max_height,
                    img_w,
                    img_h,
                    &tvout_resized_offset_x,
                    &tvout_resized_offset_y,
                    &tvout_resized_img_w,
                    &tvout_resized_img_h);
            }
        }
        else
        {
            tvout_resized_img_w = tvout_resized_img_h = 16;
        }


        tvout_layer_w = tvout_resized_img_w;
        tvout_layer_h = tvout_resized_img_h;
        /* tvout layer width || height  cannot be 1 */        
        if (tvout_layer_w < 8)
        {
            tvout_layer_w = 8;
            offset_x = (8 - tvout_resized_img_w) >> 1;
        }
        if (tvout_layer_h < 8)
        {
            tvout_layer_h = 8;
            offset_y = (8 - tvout_resized_img_h) >> 1;
        }

    #ifdef MDI_TVOUT_MT6228_SERIES
        if (tvout_layer_w % 8 != 0)
        {
            tvout_layer_w = ((tvout_layer_w +7) >> 3 ) << 3;
            offset_x = (tvout_layer_w - tvout_resized_img_w) >> 1;
        }
    #endif /* MDI_TVOUT_MT6228_SERIES */
    if (reset_tvout)
    {
        /* set mode to owner draw */
        mdi_tvout_force_disable_vertical_filter();
        mdi_tvout_set_mode(
            MDI_TV_MODE_OWNER_DRAW,
            tvout_layer_w,    /* layer_width */
            tvout_layer_h);  /* layer_height */
    }
        g_slidshow_cntx.tv_layer_h = tvout_layer_h;
        g_slidshow_cntx.tv_layer_w = tvout_layer_w;

        tvout_layer = mdi_tvout_get_active_layer();

        gdi_lcd_set_active(GDI_LCD_TVOUT_HANDLE);
        gdi_layer_push_and_set_active(tvout_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_reset_clip();
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            offset_x,
            offset_y,
            tvout_resized_img_w + offset_x - 1,
            tvout_resized_img_h + offset_y - 1);
        if (p_filename!= NULL)
        {
            if(anim)
            {
                gdi_image_draw_animation_resized_file(
                    offset_x,
                    offset_y,
                    tvout_resized_img_w,
                    tvout_resized_img_h,
                    (PS8) p_filename,
                    &g_slidshow_cntx.h_animate_tv);
            }
            else
            {
                gdi_image_draw_resized_file(
                    offset_x, 
                    offset_y, 
                    tvout_resized_img_w,
                    tvout_resized_img_h, 
                    p_filename);
            }
        }
        else if (img_id != 0)
        {
            gdi_image_draw_id(0, 0, img_id);
        }
        g_slidshow_cntx.tv_offset_x = offset_x;
        g_slidshow_cntx.tv_offset_y = offset_y;
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        mdi_tvout_blt();

    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_anim_blt_after_callback
 * DESCRIPTION
 *  increase the volume of audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_anim_blt_after_callback(GDI_RESULT result)
{
    GDI_HANDLE tvout_layer;
    PU8 p_src,p_dest;
    gdi_rect_struct clip;

    if (result < GDI_SUCCEED)
    {
        return;
    }
    
    if (mdi_tvout_is_enable())
    {
        clip.x1 = g_slidshow_cntx.tv_offset_x;
        clip.y1 = g_slidshow_cntx.tv_offset_y;
        clip.x2 = g_slidshow_cntx.tv_layer_w - 1;
        clip.y2 = g_slidshow_cntx.tv_layer_h - 1;
        /* buffer should only need to be get once. */
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_get_buffer_ptr(&p_src);
        gdi_layer_pop_and_restore_active();
        
        tvout_layer = mdi_tvout_get_active_layer();
        gdi_lcd_set_active(GDI_LCD_TVOUT_HANDLE);
        gdi_layer_push_and_set_active(tvout_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_get_buffer_ptr(&p_dest);


        gdi_2d_memory_blt(
            p_src,
            lcd_width,
            g_slidshow_cntx.resized_image_offset_x,
            g_slidshow_cntx.resized_image_offset_y,  /* the offset x,y of copy pointer*/
            g_slidshow_cntx.resized_image_width,
            g_slidshow_cntx.resized_image_height,   /* the width/height to be copied */
            p_dest,
            g_slidshow_cntx.tv_layer_w,        /* dest_pitch */
            clip.x1,                       /* the offset on the dest buffer */
            clip.y1,
            clip,
            GDI_MAINLCD_BIT_PER_PIXEL);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        mdi_tvout_blt();
    }
}

#endif /* __MMI_TVOUT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_vol_up
 * DESCRIPTION
 *  increase the volume of audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_slidshow_vol_up(void)
{
    if (mdi_audio_is_background_play_suspended())
    {
        if (g_slidshow_cntx.audio_volume < MAX_VOL_LEVEL - 1)
        {
            mdi_audio_set_volume(VOL_TYPE_MEDIA, ++g_slidshow_cntx.audio_volume);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_vol_down
 * DESCRIPTION
 *  increase the volume of audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    
static void mmi_slidshow_vol_down(void)
{
    if (mdi_audio_is_background_play_suspended())
    {
        if (g_slidshow_cntx.audio_volume >0 )
        {
            mdi_audio_set_volume(VOL_TYPE_MEDIA, --g_slidshow_cntx.audio_volume);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_set_keys
 * DESCRIPTION
 *  set key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_slidshow_set_keys(void)
{
    static U16 keys_to_set[] = 
                        {
                        KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
                        KEY_POUND, KEY_STAR, KEY_CLEAR};
    SetGroupKeyHandler(mmi_slidshow_osd_show_up, keys_to_set, 13, KEY_EVENT_UP);
    SetKeyHandler(mmi_slidshow_vol_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_slidshow_vol_down, KEY_VOL_DOWN, KEY_EVENT_UP);
    /* if LCD is Horizontal, down:next pic, up:previous pic */
    if (SLIDSHOW_HORIZONTAL_VIEW == g_slidshow_cntx.is_horz_view_set)
    {
        SetKeyHandler(mmi_slidshow_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
              
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_slidshow_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_display_screens
 * DESCRIPTION
 *  delete screens when the fmgr which slideshow was calling has been killed
 * PARAMETERS
 *  app_id      [IN] application ID
 * RETURNS
 *  void
 *****************************************************************************/

extern void mmi_slidshow_exit_display_screens(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (APP_SLIDESHOW != app_id)
    {
        for(scrnid= SCR_ID_SLIDSHOW_APP; scrnid <= SCR_ID_SLIDSHOW_BGM_FILE_OPTION; scrnid++)
        {
            DeleteScreenIfPresent(scrnid);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_deleteScr_callback
 * DESCRIPTION
 *  delete screens when the fmgr which slideshow was calling has been killed
 * PARAMETERS
 *  ptr      [IN] not used.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_slidshow_deleteScr_callback(void* ptr)
{
    g_slidshow_cntx.is_valid_bgm = FALSE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    return MMI_FALSE;
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_drm_timeup_callback
 * DESCRIPTION
 *  handle the return value of DRM timeout.
 * PARAMETERS
 *  ptr      [IN] not used.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_drm_timeup_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0 && g_slidshow_cntx.play_layer_handle != GDI_NULL_HANDLE)
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
    }
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_deleteScr_callback
 * DESCRIPTION
 *  delete screens when the fmgr which slideshow was calling has been killed
 * PARAMETERS
 *  ptr      [IN] not used.
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_slidshow_turn_off_bl_hdlr(void)
{
    TurnOffBacklight();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_hdlr
 * DESCRIPTION
 *  for back and select is null
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_slidshow_exit_hdlr(void)
{
    DeleteUptoScrID(SCR_ID_SLIDSHOW_APP);
    DeleteScreenIfPresent(SCR_ID_SLIDSHOW_APP);
    GoBackHistory();
}


/***************************************************************************** 
*
* Touch Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_pen_down_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen down postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tmp_x;
    S32 tmp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;
    }
    /* LSK */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.lsk))
    {
        /* draw clicked LSK */
        if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
        {
            mmi_slidshow_lsk_press();
            g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_LSK;
        }
        return;
    }
    /* RSK */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.rsk))
    {
        /* draw clicked RSK */
        mmi_slidshow_rsk_press();
        g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_RSK;
        return;
    }
    /* left arrow */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.left_arrow))
    {
        mmi_slidshow_left_arrow_press();
        g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_LEFT_ARROW;
        return;
    }
    /* right arrow */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.right_arrow))
    {
        mmi_slidshow_right_arrow_press();
        g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_RIGHT_ARROW;
        return;
    }
    
    /* no event */
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_osd_show_up();
    }
    g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_NONE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_pen_up_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen up postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 tmp_x;
    S32 tmp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;
    }

    switch (g_slidshow_touch_screen_cntx.pen_event_on_object)
    {
        case SLIDSHOW_LSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.lsk))
            {
                mmi_slidshow_lsk_release();
            }
            break;

        case SLIDSHOW_RSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.rsk))
            {
                mmi_slidshow_rsk_release();
            }
            break;

        case SLIDSHOW_LEFT_ARROW:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.left_arrow))
            {
                mmi_slidshow_left_arrow_icon_key_release();
                gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY,mmi_slidshow_left_arrow_release);
            }
            break;

        case SLIDSHOW_RIGHT_ARROW:
                mmi_slidshow_right_arrow_icon_key_release();
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.right_arrow))
            {
                gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY,mmi_slidshow_right_arrow_release);
            }
            break;

        default:
            break;
    }

    g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_NONE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_pen_move_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 softkey_pressed = 0;

    S32 tmp_x;
    S32 tmp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;
    }

    switch (g_slidshow_touch_screen_cntx.pen_event_on_object)
    {
        case SLIDSHOW_LSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.lsk) == MMI_TRUE)   /* within LSK */
            {
                softkey_pressed = 1;
            }
            else
            {
                softkey_pressed = 0;
            }
            if (softkey_pressed != g_slidshow_cntx.is_lsk_pressed)
            {
                g_slidshow_cntx.is_lsk_pressed = softkey_pressed;
                mmi_slidshow_show_press_release_softkey();
            }
            break;

        case SLIDSHOW_RSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.rsk) == MMI_TRUE)   /* within RSK */
            {
                softkey_pressed = 1;
            }
            else
            {
                softkey_pressed = 0;
            }
            if (softkey_pressed != g_slidshow_cntx.is_rsk_pressed)
            {
                g_slidshow_cntx.is_rsk_pressed = softkey_pressed;
                mmi_slidshow_show_press_release_softkey();
            }
            break;

    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_VIDEO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_sublcd_screen
 * DESCRIPTION
 *  handle our own sublcd screen while playing a video clip in order to 
 *  prevent driver assert caused by time update onstandard MMI sublcd screen
 *  (c.f. video player)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_slidshow_entry_sublcd_screen(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_slidshow_exit_sublcd_screen);

    mmi_slidshow_draw_sublcd_icon();
    
    g_slidshow_cntx.is_sub_display = TRUE;
}
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_sublcd_screen
 * DESCRIPTION
 *  exit sub lcd screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_slidshow_exit_sublcd_screen(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode his_sublcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reference video player.                                      
     * some application may exit sub lcd first before exit main lcd.
     * so need to check if video is still playing on main lcd for this case.
     */

    if (SLIDSHOW_VIDEO_PLAYING == g_slidshow_cntx.v_state)
    {   
        mdi_video_ply_stop();
        mdi_video_ply_get_cur_play_time(&g_slidshow_cntx.play_time);

        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
    }

    g_slidshow_cntx.is_sub_display = FALSE;

    his_sublcd.entryFuncPtr = mmi_slidshow_entry_sublcd_screen;
    AddSubLCDHistory(&his_sublcd);
}
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_sublcd_icon
 * DESCRIPTION
 *  draw a icon on sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_slidshow_draw_sublcd_icon(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_img_width;
    S32 n_img_height;
    S32 n_lcd_width;
    S32 n_lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);         /* active sub lcd before drawing    */
    gdi_lcd_get_dimension(&n_lcd_width, &n_lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    /* we use the same sublcd img from video player */
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_SUBLCD_ICON, &n_img_width, &n_img_height);
    gdi_image_draw_id(
        (n_lcd_width - n_img_width) >> 1, 
        (n_lcd_height - n_img_height) >> 1, 
        IMG_ID_VDOPLY_SUBLCD_ICON);

    gdi_layer_blt_base_layer(0, 0, n_lcd_width - 1, n_lcd_height -1);
    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);        /* done, return control to main lcd */
}
#endif /*__MMI_SUBLCD__*/
#endif /* __MMI_VIDEO_PLAYER__ */


#ifdef __SLIDESHOW_USE_APP_ASM__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_alloc_app_asm
 * DESCRIPTION
 *  allocate memory from app asm's pool
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL        TRUE if memory is successfully allocated
 *****************************************************************************/
BOOL mmi_slidshow_alloc_app_asm(void)
{
    PU8 p_appmem_buf;
    
    p_appmem_buf = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_SLIDESHOW, SLIDESHOW_FRAME_BUFFER_SIZE << 1 );
    if (p_appmem_buf)
    {
        g_slidshow_layer1_buffer = p_appmem_buf;
        g_slidshow_layer2_buffer = (p_appmem_buf+SLIDESHOW_FRAME_BUFFER_SIZE);
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_free_app_asm
 * DESCRIPTION
 *  free app based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_free_app_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_slidshow_layer1_buffer);
    applib_mem_ap_free(g_slidshow_layer1_buffer);
    g_slidshow_layer1_buffer = NULL;
    g_slidshow_layer2_buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of slideshow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_slidshow_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slidshow_free_app_asm();
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_stop_callback
 * DESCRIPTION
 *  stop the program for app_based_memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_slidshow_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_SLIDSHOW_APP);
    DeleteScreenIfPresent(SCR_ID_SLIDSHOW_APP);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_SLIDESHOW, KAL_TRUE);
}

#endif /* __SLIDESHOW_USE_APP_ASM__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_load_data
 * DESCRIPTION
 *  load slideshow setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_load_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded, avoid load again to save time */

    ReadRecord(
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        1,
        (void*)&g_slidshow_cntx.setting,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        &error);

    /* first time init */
    if (g_slidshow_cntx.setting.type_of_play== 0xffffffff)
    {
        g_slidshow_cntx.setting.type_of_play = 0;
        g_slidshow_cntx.setting.speed = 1;
        g_slidshow_cntx.setting.effect = 0;
        g_slidshow_cntx.setting.bgm = 0;
        g_slidshow_cntx.setting.horz = 0;
        g_slidshow_cntx.setting.sound_effect = 0;

        mmi_slidshow_store_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_store_data
 * DESCRIPTION
 *  load slide show setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_store_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        1,
        (void*)&g_slidshow_cntx.setting,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        &error);
}


#endif /* __MMI_SLIDESHOW__ */ 

