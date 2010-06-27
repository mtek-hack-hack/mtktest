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
 *  wgui_categories_multimedia.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Multimedia related categories.
 *
 *  [Category221]       Empty Screen
 *  [Category222]       View Image Screen
 *  [Category223]       Play Audio Screen
 *  [Category224]       Play Video Full Screen
 *  [Category225]       Play Video Standard Screen (With title & softkey)
 *
 *  [Category331][SUB]  Emptry Sublcd Screen
 *  [Category332][SUB]  Image Icon Sublcd Screen 
 *  [Category333][SUB]  Play Audio Sublcd Screen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"

/* framework related include */
#include "EventsGprot.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "GlobalDefs.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"
#include "Unicodexdcl.h"
#include "DebugInitDef.h"
#include "fat_fs.h"
#include "SettingProfile.h"     /* for error tone */

#include "Fs_errcode.h"
#include "Drm_gprot.h"

/* gui related include */
#include "gdi_include.h"        /* include for graphic lib */
#include "lcd_if.h"
#include "gui_themes.h"
#include "gui_clock.h"
#include "wgui.h"
#include "wgui_softkeys.h"
#include "wgui_fixed_menus.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_dynamic_menus.h"
#include "wgui_dynamic_menuitems.h"
#include "wgui_categories.h"
#include "wgui_categories_sublcd.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_inputs.h"     /* MULTILINE_INPUTBOX_HEIGHT_PAD */
#include "wgui_categories_CM.h"
#include "wgui_status_icons.h"
#include "CommonScreens.h"      /* DisplayPopup() */
#include "PhoneSetupGprots.h"   /* PhnsetGetDefEncodingType() */
#include "Conversions.h"        /* char set conversion */
#include "ScrMemMgrGprot.h"     /* screen memeory manager */
#include "NVRAMEnum.h"
#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "wgui_draw_manager.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#include "EditorPenGprot.h"
#include "wgui_virtual_keyboard.h"
#endif 

#include "WallpaperDefs.h"      /* Image size error string */
#include "GpioInc.h"    /* backlight on/off */

#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"

#include "ImageViewer.h"

#include "SubLCDHistoryGprot.h" /* sublcd function */

#include "HistoryGprot.h"

#ifdef __MMI_VIDEO_PLAYER__
#include "med_api.h"    /* media task */
#include "med_main.h"   /* media task */
#include "mdi_datatype.h"
#include "mdi_video.h"  /* video lib */
#include "mdi_audio.h"

#include "lcd_sw_rnd.h"
#include "gdi_include.h"
#include "VdoPlyResDef.h"      /* sublcd video icon */
#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"     /* mdi tvout */
#include "WallpaperDefs.h"      /* some header for phonsetup.h */
#include "DownloadDefs.h"       /* some header for phonsetup.h */
#include "PhoneSetup.h" /* tvout display style */
#endif /* __MMI_TVOUT__ */ 

#include "mmi_phnset_dispchar.h"

#ifdef __MMI_SWFLASH__
#include "mdi_datatype.h"
#include "mdi_swflash.h"
#include "swflashGprot.h"
#include "mmi_phnset_dispchar.h"
#include "TouchScreenGProt.h"

#endif 

#ifdef __MMI_AVATAR__
#include "avatargprot.h"
#endif

/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Global Variable
*****************************************************************************/
extern S16 status_icon;
extern S32 wgui_image_clip_x1;
extern S32 wgui_image_clip_x2;
extern S32 wgui_image_clip_y1;
extern S32 wgui_image_clip_y2;
extern U8 wgui_category_screen_no_buttons;
extern BOOL r2lMMIFlag;
extern U16 title_bg_id;
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
extern S8 *idle_screen_wallpaper_name;
#endif
/****************************************************************************
* Global Function
*****************************************************************************/
extern void wgui_set_animation_image_y(S32 x, S32 y, PU8 img);
extern void wgui_show_transparent_animation(void);
extern void set_main_LCD_time_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern U16 PhnsetGetCurWallPaperIdx(void);
extern void mmi_langln_bsk_stop_auto_scroll(void);

#ifdef __MMI_AUDIO_PLAYER__
extern int mmi_audply_exit_subLCD(void);
extern int mmi_audply_redraw_subLCD(BOOL);
extern BOOL mmi_audply_is_playing(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_FM_RADIO__
extern int mmi_fmrdo_exit_subLCD(void);
extern int mmi_fmrdo_redraw_subLCD(BOOL);
extern BOOL mmi_fmrdo_is_power_on(void);
#endif /* __MMI_FM_RADIO__ */ 

#ifdef __MMI_VIDEO_PLAYER__
mdi_video_info_struct wgui_video_info;
#endif 

#if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
extern void DrawCate16CategoryBeforeBLTCallback(GDI_RESULT return_code);
extern void PhnsetWallpaperBadFileCallBack(U16 imgID);
extern pBOOL mmi_bootup_get_active_flight_mode(void);

extern void dm_category_33_controlled_area(dm_coordinates *coordinate);
extern void ShowCategory33Screen_ext(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);
extern void ExitCategory33Screen(void);
#endif

/****************************************************************************
* Local Variable
*****************************************************************************/
/* [Category 221] */
static FuncPtr cat221_redraw_content_callback = NULL;
static gdi_color cat221_background_color;

/* [Category 222] */
static PS8 cat222_file_name_ptr;
static U16 cat222_title_icon;
static U16 cat222_title;
static PS8 cat222_button_str_ptr;   /* will use subMenu's data buffer to store */
static void (*cat222_decode_result_callback) (GDI_RESULT);
static BOOL cat222_is_short_filename;
static GDI_HANDLE cat222_anim_handle;
static S32 cat222_img_width;
static S32 cat222_img_height;
static gdi_image_src_enum cat222_src_type;

#ifdef __MMI_TVOUT__
static BOOL cat222_is_fullscr_tvout = FALSE;
#endif 

/* [Category 223] */
static BOOL cat223_display_duration = FALSE;

/* [Category Vdoply] */
#ifdef __MMI_VIDEO_PLAYER__
static U16 cat_vdoply_video_repeat_count;
static BOOL cat_vdoply_video_is_visual_update;
static BOOL cat_vdoply_video_is_play_audio;
static BOOL cat_vdoply_video_is_lcd_no_sleep;
static BOOL cat_vdoply_is_video_open;
static BOOL cat_vdoply_is_video_play;
static MDI_RESULT cat_vdoply_is_video_play_result = -1;
static BOOL cat_vdoply_is_video_force_stop; /* force stop flag */
static BOOL cat_vdoply_is_video_from_id;
static GDI_HANDLE cat_vdoply_video_layer = GDI_ERROR_HANDLE;

#ifdef __MMI_SUBLCD__
static BOOL cat_vdoply_is_sublcd_display = FALSE;   /* must init */
#endif 
static void (*cat_vdoply_play_finish_callback) (MDI_RESULT result);
static U8 cat_vdoply_is_full_screen;
#endif /* __MMI_VIDEO_PLAYER__ */ 

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_SWFLASH__)
static U8 cat_vdoply_audio_volumn;
#endif /* __MMI_VIDEO_PLAYER__ */ 

/* [Category 229 ] */

#ifdef __MMI_SWFLASH__
extern mdi_swflash_info_struct wgui_swflash_info;

static U16 cat_swflash_repeat_count;
static U8 cat_swflash_audio_volumn;
static MMI_BOOL cat_swflash_is_audio_on;
static MMI_BOOL cat_swflash_is_vibrate_on;
static MMI_BOOL cat_swflash_is_interaction_on;
static MMI_BOOL cat_swflash_is_lcd_no_sleep;
static MMI_BOOL cat_swflash_is_open;
static MMI_BOOL cat_swflash_is_play;
static MMI_BOOL cat_swflash_is_from_id;
static void (*cat_swflash_play_finish_callback) (MDI_RESULT);
static U8 cat_swflash_is_full_screen;
static MDI_RESULT cat_swflash_play_ret;
#endif /* __MMI_SWFLASH__ */ 

#if defined(__MMI_AVATAR__)
static MMI_BOOL cat_avatar_is_valid;
#endif

#if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
static S32 g_mmi_idle_bg_media_type = 0;
static U32 cat34_avatar_ptr;
static U32 cat34_avatar_serial_num;
static GDI_HANDLE cat34_anim_handle;
static GDI_HANDLE cat_swflash_layer = GDI_ERROR_HANDLE;
#endif
/****************************************************************************
* Local Function
*****************************************************************************/
/* [Category 221] */
static void ExitCategory221Screen(void);

/* [Category 222] */
static void ExitCategory222Screen(void);
static void Cat222DecodeImage(void);
static void Cat222DrawTitle(void);

#ifdef __MMI_TVOUT__
static void Cat222ToggleTVDisplay(void);
#endif 

/* [Category 223] */
static void ExitCategory223Screen(void);

static void DrawCate223CategoryControlArea(dm_coordinates *coordinate);

static void Cat223DrawDurationBar(void);
static void Cat223InitDruration(UI_time *t, U32 duration);
static void Cat223HideDurationDisplay(S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_VIDEO_PLAYER__
   /* [Category Video Play Screen] */
static void ShowCategoryVdoplyScreen(BOOL is_fullscreen,
                                     U16 title_str,
                                     U16 title_icon,
                                     U16 lsk_str,
                                     U16 lsk_icon,
                                     U16 rsk_str,
                                     U16 rsk_icon,
                                     U16 video_id,
                                     PS8 video_filename,
                                     U16 repeat_count,
                                     BOOL is_visual_update,
                                     BOOL is_play_audio,
                                     BOOL is_lcd_no_sleep,
                                     GDI_COLOR bg_color, void (*play_finish_callback) (MDI_RESULT), void *gui_buffer);
static void ExitCategoryVdoplyScreen(void);
static void StopCategoryVdoplyVideo(void);
static void PauseCategoryVdoplyVideo(void);
static void ResumeCategoryVdoplyVideo(void);
static void CatVdoplyPlayFinishCallback(MDI_RESULT result);

#ifdef __MMI_SWFLASH__
extern void DrawCateSWFlashCategoryControlArea(dm_coordinates *coordinate);
#endif

#ifdef __MMI_AVATAR__
extern void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id, U32 *serial_num);
#endif

#ifdef __MMI_SUBLCD__
static void EnterCategoryVdoplySubScreen(void);
static void ExitCategoryVdoplySubScreen(void);
#endif /* __MMI_SUBLCD__ */ 
#endif /* __MMI_VIDEO_PLAYER__ */ 

#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_SWFLASH__)
static void CatVdoplyVolUp(void);
static void CatVdoplyVolDown(void);
#endif /* __MMI_VIDEO_PLAYER__ */ 

#ifdef __MMI_SUBLCD__
/* [Category 331] [SUB] */
static void ExitCategory331Screen(void);

/* [Category 331] [SUB] */
static void ExitCategory332Screen(void);

/* [Category 333] [SUB] */
static U8 *GetCategory333History(U8 *history_buffer);
static S32 GetCategory333HistorySize(void);
static void ExitCategory333Screen(void);
static void RedrawCategory333Screen(void);
#endif /* __MMI_SUBLCD__ */ 

void cat226_hide_button_full_screen(void *button_object);

#ifdef __MMI_SWFLASH__
static void CatSWFlashVolUp(void);
static void CatSWFlashVolDown(void);
void ExitCategorySWFlashScreen(void);
#endif


#ifdef __MMI_ALPHA_BLENDING__
extern void cat33_redraw_alpha_images(void);
#endif /* __MMI_ALPHA_BLENDING__ */

/****************************************************************************
*
* MultiMedia Related [MainLCD] Categories
*
*****************************************************************************/

/*****************************************************************************
* [Category221]
*
* This category is basic frame with caption and softkeys.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *                 <----------- Empty. Will hook call back function to redraw.
*  *                    *
*  *                    *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  DrawCate221CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category221 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate221CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_title_string != 0 || MMI_title_icon != 0)
    {
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
    #if defined(GUI_COMMON_USE_THICK_TITLE)
        wgui_title_set_thick(MMI_TRUE);
        move_title(MMI_TITLE_X, MMI_TITLE_Y);
        resize_title(MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT);
    #else /* defined(GUI_COMMON_USE_THICK_TITLE) */
        wgui_title_set_thick(MMI_FALSE);
        move_title(MMI_TITLE_X, MMI_TITLE_Y);
        resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
    #endif /* defined(GUI_COMMON_USE_THICK_TITLE) */

    #if defined(__MMI_SCREEN_ROTATE__)
        if (!mmi_frm_is_screen_width_height_swapped())
        {
            show_title_status_icon();
        }
    #else /* defined(__MMI_SCREEN_ROTATE__) */ 
        show_title_status_icon();
    #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
#else /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
    #if defined(GUI_COMMON_USE_THICK_TITLE)
        wgui_title_set_thick(MMI_TRUE);
        move_title(MMI_TITLE_X, 0);
        resize_title(MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT);
    #else /* defined(GUI_COMMON_USE_THICK_TITLE) */
        wgui_title_set_thick(MMI_FALSE);
        move_title(MMI_TITLE_X, 0);
        resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
    #endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
#else /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
    #if defined(__MMI_SCREEN_ROTATE__)
        if (!mmi_frm_is_screen_width_height_swapped())
        {
            show_title_status_icon();
        }
    #else /* defined(__MMI_SCREEN_ROTATE__) */ 
        show_title_status_icon();
    #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

        draw_title();
    }

    /* fill background */
    gdi_layer_reset_clip();

    /* if has title - draw content region only */
    if (MMI_title_string != 0 || MMI_title_icon != 0)
    {
        gdi_draw_solid_rect(
            0,
            (MMI_title_y + MMI_title_height),
            UI_device_width - 1,
            (MMI_title_y + MMI_title_height) + MMI_content_height - 1,
            cat221_background_color);
    }
    else
    {
        gdi_draw_solid_rect(
            0,
            0,
            UI_device_width - 1,
            (MMI_title_y + MMI_title_height) + MMI_content_height - 1,
            cat221_background_color);
    }

    /* redraw callback function */
    if (cat221_redraw_content_callback != NULL)
    {
        cat221_redraw_content_callback();
    }

}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory221Screen
 * DESCRIPTION
 *  Show category 221 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  background_color            [IN]        Background color for content region
 *  redraw_content_callback     [IN]        Callback function to redraw context (PS.This redraw callback pointer is used for framework to update content region when theme update.PS. MMI Framework will not call redraw function anymore. The pointer is useless)
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory221Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        gdi_color background_color,
        FuncPtr redraw_content_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    gui_setup_common_layout();

    cat221_background_color = background_color;
    cat221_redraw_content_callback = redraw_content_callback;

    /* hide status if will not draw title bar */
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)
    if (title == 0 && title_icon == 0)
    {
        hide_status_icon_bar(0);
    }
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 

    /* lock */
    gui_lock_double_buffer();

    MMI_menu_shortcut_number = -1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    /* init title */
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory221Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(DrawCate221CategoryControlArea);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY221_ID;
    dm_data.s32flags = 0;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory221Screen
 * DESCRIPTION
 *  Exit category 221
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory221Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)
    show_status_icon_bar(0);
#endif 

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}

/*****************************************************************************
* [Category222]
*
* This category is for view image from file.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *       (Image)      *
*  *                    *
*  *                    *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/
#ifdef __MMI_NONBLOCKING_DECODE__
    #define __MMI_CAT222_NON_BLOCKING_DECODER__
#endif /* __MMI_NONBLOCKING_DECODE__ */

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)
#define     CAT222_IMAGE_SPACING    (5) /* spacing between image and LCM boundry */
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 
#define     CAT222_IMAGE_SPACING    (4) /* spacing between image and LCM boundry */
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 

void DrawCate222CategoryControlArea(dm_coordinates *coordinate);


/*****************************************************************************
 * FUNCTION
 *  cat222_get_image_handle
 * DESCRIPTION
 *  get the animation handle for cat 222
 * PARAMETERS
 *  void
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
gdi_handle cat222_get_image_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gdi_handle)cat222_anim_handle;
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory222Screen
 * DESCRIPTION
 *  Show Category 222 Screen.
 * PARAMETERS
 *  title                       [IN]        Title string
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  background_color            [IN]        Background color for content region
 *  button_string               [IN]        String on LSK region. (If this pointer is not NULL, the string will draw on lsk region.)
 *  file_name_ptr               [IN]        Filename to be decode.
 *  is_short_filename           [IN]        File name is short or not.
 *  decode_result_callback      [IN]        Decode result callback function
 *  EX: It may be used as show index/total number.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory222Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        gdi_color background_color,
        S8 *button_string,
        S8 *file_name_ptr,
        BOOL is_short_filename,
        void (*decode_result_callback) (GDI_RESULT),
        gdi_image_src_enum src_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_setup_common_layout();

    cat222_file_name_ptr = file_name_ptr;
    cat222_title_icon = title_icon;
    cat222_title = title;
    cat222_is_short_filename = is_short_filename;
    cat222_decode_result_callback = decode_result_callback;
    cat222_anim_handle = GDI_NULL_HANDLE;
    cat222_src_type = src_type;
    
    if (button_string != NULL)
    {
        cat222_button_str_ptr = (S8*) (subMenuDataPtrs[0]); /* use submenu's data buffer, not a good solution */

        memset(cat222_button_str_ptr, 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy(cat222_button_str_ptr, button_string, (MAX_SUB_MENU_SIZE / ENCODING_LENGTH) - 1);
    }
    else
    {
        cat222_button_str_ptr = NULL;
    }

    MMI_menu_shortcut_number = -1;
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

#ifdef __MMI_TVOUT__
    SetKeyHandler(Cat222ToggleTVDisplay, KEY_STAR, KEY_EVENT_UP);
#endif 

    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    ExitCategoryFunction = ExitCategory222Screen;

    dm_setup_category_functions(UI_dummy_function, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(DrawCate222CategoryControlArea);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY222_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_NO_BLT | DM_LITE_DISP_WALLPAPER;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
    /* Draw Image */
    Cat222DecodeImage();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory222Screen
 * DESCRIPTION
 *  Exit Category 222 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory222Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_setup_default_layout();

#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
    wgui_status_icon_unlock_redrawing();
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */

    /* restore TV out mode */
#ifdef __MMI_TVOUT__
    if (cat222_is_fullscr_tvout)
    {
        if (mdi_tvout_is_enable())
        {
            /* restore back to GDI */
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

            /* restore back to start mode1 */
            mdi_tvout_set_mode(
                MDI_TV_MODE_LCD_SCR,
                0,  /* layer_width */
                0); /* layer_height */
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (cat222_anim_handle != GDI_NULL_HANDLE)
    {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
        gdi_image_nb_stop(cat222_anim_handle);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        gdi_image_stop_animation(cat222_anim_handle);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
    }

    ClearHighlightHandler();
    reset_softkeys();

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate222CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category222 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate222CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_height;
    S32 str_width;
    S32 spacing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat222_button_str_ptr != NULL)
    {
        gdi_layer_push_text_clip();
        gdi_layer_set_text_clip(0, UI_device_width - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);

        /* draw button string */
        gui_set_font(&MMI_medium_font);

        gui_measure_string((UI_string_type) cat222_button_str_ptr, &str_width, &str_height);
        spacing = (MMI_button_bar_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(spacing + str_width, UI_device_height - MMI_button_bar_height + spacing);
        }
        else
        {
            gui_move_text_cursor(spacing, UI_device_height - MMI_button_bar_height + spacing);
        }

        gui_set_text_color(*current_MMI_theme->list_normal_text_color);
        gui_print_text((UI_string_type) cat222_button_str_ptr);

        gdi_layer_pop_text_clip();
    }

    Cat222DrawTitle();
}


/*****************************************************************************
 * FUNCTION
 *  Cat222DrawTitle
 * DESCRIPTION
 *  draw cat 222 title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222DrawTitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    S32 index;
    S8 buf_filename_no_ext[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    S8 buf_filename_dest[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat222_title == 0)
    {
        /* display filename */
        str_len = mmi_ucs2strlen(cat222_file_name_ptr);

        /* find file name - by finding "\\" */
        for (index = str_len * 2 - 2; index >= 2; index -= 2)
        {
            if (mmi_ucs2ncmp((PS8) & cat222_file_name_ptr[index], (PS8) L"\\", 1) == 0)
            {
                index += 2;
                break;
            }
        }

        mmi_ucs2cpy((PS8) buf_filename_no_ext, (PS8) (&(cat222_file_name_ptr[index])));

        mmi_fmgr_hide_ext_name(buf_filename_no_ext);

        /* short name encoding */
        if (cat222_is_short_filename)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) buf_filename_dest,
                sizeof(buf_filename_dest),
                (U8*) buf_filename_no_ext,
                PhnsetGetDefEncodingType());

            ChangeTitle(cat222_title_icon, (PU8) (buf_filename_dest));
        }
        else
        {
            ChangeTitle(cat222_title_icon, (PU8) (buf_filename_no_ext));
        }
    }

    draw_title();
}


/*****************************************************************************
 * FUNCTION
 *  Cat222ShowErrMsg
 * DESCRIPTION
 *  Display error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222ShowErrMsg(UI_string_type err_str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len, line_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err_str_ptr == NULL)
    {
        return;
    }

    gdi_layer_push_clip();
    gdi_layer_push_text_clip();

    gdi_layer_set_clip(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1);

    gdi_draw_solid_rect(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1,
        gdi_act_color_from_rgb(0xFF, current_MMI_theme->lite_disp_scr_bg_color->r, current_MMI_theme->lite_disp_scr_bg_color->g, current_MMI_theme->lite_disp_scr_bg_color->b));

    /* show error string in multi-line input box */
    str_len = mmi_ucs2strlen((PS8) err_str_ptr);

    create_multiline_inputbox_set_buffer(err_str_ptr, str_len, str_len, 0);
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

    MMI_multiline_inputbox.text_font = &MMI_medium_font;

    /* resize to content size and call show_xx_no_draw function to calc its line count */
    resize_multiline_inputbox(MMI_content_width, MMI_content_height);
    move_multiline_inputbox(MMI_content_x, MMI_content_y);

    /* vertical center alignment */
    show_multiline_inputbox_no_draw();
    line_height = get_multiline_inputbox_line_height();
    resize_multiline_inputbox(
        UI_device_width,
        (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);
    move_multiline_inputbox(
        0,
        MMI_content_y + ((MMI_content_height - MMI_multiline_inputbox.height) >> 1));

    show_multiline_inputbox();

    gdi_layer_pop_text_clip();
    gdi_layer_pop_clip();

    gdi_lcd_repaint_all();
}


/*****************************************************************************
 * FUNCTION
 *  Cat222ImageDoneCallback
 * DESCRIPTION
 *  Display error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222ImageDoneCallback(GDI_RESULT result, GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type err_str_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
    wgui_status_icon_unlock_redrawing();
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
    
    if (result < 0)
    {
        if (err_str_ptr == NULL)
        {
            if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result == GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else
            {
                err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
        }

        Cat222ShowErrMsg(err_str_ptr);
    }

    /* call decode result callback */
    if (cat222_decode_result_callback != NULL)
    {
        cat222_decode_result_callback(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cat222DecodeImage
 * DESCRIPTION
 *  Decode Image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222DecodeImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 display_wnd_width;
    S32 display_wnd_height;

    S32 rect_height = 0;
    S32 rect_width = 0;
    S32 rect_offset_x = 0;
    S32 rect_offset_y = 0;

    S32 offset_x = 0;
    S32 offset_y = 0;
    GDI_RESULT result = 0;
    U16 image_type = 0;
    UI_string_type err_str_ptr = NULL;

    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

#ifdef __MMI_TVOUT__
    S32 tvout_resized_offset_x;
    S32 tvout_resized_offset_y;
    S32 tvout_resized_width;
    S32 tvout_resized_height;
    S32 tvout_max_width;
    S32 tvout_max_height;
    GDI_HANDLE tvout_layer;
#endif /* __MMI_TVOUT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();

    gdi_layer_set_clip(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1);

    /* check file limitation */
    if (result >= 0)
    {
        if (cat222_src_type == GDI_IMAGE_SRC_FROM_FILE)
        {
            if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, cat222_file_name_ptr, (PS8*)&err_str_ptr))
            {
                result = -1;
            }
            else
            {
                err_str_ptr = NULL;
            }
        }
    }

#ifdef __DRM_SUPPORT__
    if (result >= 0)
    {
            result = mmi_imgview_get_drm_result();
            if (result < 0)
            {
                err_str_ptr = (UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED);
            }
    }
#endif /* __DRM_SUPPORT__ */

    /* get image info */
    if (result >= 0 && cat222_src_type == GDI_IMAGE_SRC_FROM_FILE)
    {
        image_type = gdi_image_get_type_from_file(cat222_file_name_ptr);
        result = gdi_image_get_dimension_file((PS8) cat222_file_name_ptr, &image_width, &image_height);
    }
    else if (cat222_src_type == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        image_type = gdi_image_get_type_from_mem(cat222_file_name_ptr);
        result = gdi_image_get_dimension_mem((U8) image_type, (PU8) cat222_file_name_ptr, 0, &image_width, &image_height);
    }
    if (result >= 0)
    {
        cat222_img_width = image_width;
        cat222_img_height = image_height;
    }
    else
    {
        if (err_str_ptr == NULL)
        {
            err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
        }
    }
    
    display_wnd_width = MMI_content_width - CAT222_IMAGE_SPACING * 2;
    display_wnd_height = MMI_content_height - CAT222_IMAGE_SPACING * 2;

    /* clear gdi working buffer */
    gdi_image_clear_work_buffer();

    if (result >= 0)
    {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
        /* set non-blocking parameters */
        gdi_nb_set_blt(TRUE, FALSE);                        /* let GDI to blt the LCD after decoding without progressive blt */
        gdi_nb_set_done_callback(Cat222ImageDoneCallback);  /* register callback after decoding */
        wgui_status_icon_lock_redrawing();
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */

        if ((display_wnd_width >= image_width) && (display_wnd_height >= image_height))
        {
            /* align preview window at the center of screen */
            offset_x = ((display_wnd_width - image_width + 1) >> 1) + CAT222_IMAGE_SPACING;
            offset_y = ((display_wnd_height - image_height + 1) >> 1) + MMI_content_y + CAT222_IMAGE_SPACING;

            rect_offset_x = offset_x;
            rect_offset_y = offset_y;
            rect_width = resized_width = image_width;
            rect_height = resized_height = image_height;
        }
        else
        {
            gdi_image_util_fit_bbox(
                display_wnd_width,
                display_wnd_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            offset_x = resized_offset_x + CAT222_IMAGE_SPACING;
            offset_y = resized_offset_y + (MMI_title_y + MMI_title_height) + CAT222_IMAGE_SPACING;

            rect_offset_x = offset_x;
            rect_offset_y = offset_y;
            rect_width = resized_width;
            rect_height = resized_height;
        }
        
        if (image_type == GDI_IMAGE_TYPE_AVATAR)
        {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
            result = 0;
            cat222_anim_handle = gdi_anim_nb_draw_resized_mem(
                                        offset_x, offset_y, resized_width, resized_height,
                                        (PU8) cat222_file_name_ptr, GDI_IMAGE_TYPE_AVATAR, 0);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
            result = gdi_anim_draw_mem_resized(
                            offset_x, offset_y, resized_width, resized_height,
                            (PS8) cat222_file_name_ptr, GDI_IMAGE_TYPE_AVATAR, 0, // NO USE
                            &cat222_anim_handle);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        }
        else if (image_type == GDI_IMAGE_TYPE_GIF_FILE || image_type == GDI_IMAGE_TYPE_M3D_FILE || image_type == GDI_IMAGE_TYPE_SVG_FILE)
        {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
            result = 0;
            cat222_anim_handle = gdi_anim_nb_draw_resized_file(
                                        offset_x, offset_y, resized_width, resized_height,
                                        (PS8) cat222_file_name_ptr);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
            result = gdi_image_draw_animation_resized_file(
                            offset_x, offset_y, resized_width, resized_height,
                            (PS8) cat222_file_name_ptr, &cat222_anim_handle);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        }
        else
        {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
            result = 0;
            cat222_anim_handle = gdi_image_nb_draw_resized_file(
                                        offset_x, offset_y, resized_width, resized_height,
                                        (PS8) cat222_file_name_ptr);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
            result = gdi_image_draw_resized_file(
                            offset_x, offset_y, resized_width, resized_height,
                            (PS8) cat222_file_name_ptr);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        }
    }

#ifdef __MMI_TVOUT__
    /* prepare decode to TV-Out */
    if (result >= 0 && cat222_is_fullscr_tvout == TRUE)
    {
        /* set TV out mode */
        if (mdi_tvout_is_enable())
        {
            /* calculate size */
            mdi_tvout_get_owner_draw_best_size(&tvout_max_width, &tvout_max_height);

            if ((tvout_max_width >= image_width) && (tvout_max_height >= image_height))
            {
                tvout_resized_width = image_width;
                tvout_resized_height = image_height;
            }
            else
            {
                gdi_image_util_fit_bbox(
                    tvout_max_width,
                    tvout_max_height,
                    image_width,
                    image_height,
                    &tvout_resized_offset_x,
                    &tvout_resized_offset_y,
                    &tvout_resized_width,
                    &tvout_resized_height);
            }

            /* if is fullscreen, we shall set to owner MMI Owner draw, to avoid GDI's update */
            mdi_tvout_set_owner(MDI_TV_OWNER_APP);

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_resized_width,    /* layer_width */
                tvout_resized_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_reset_clip();

            result = gdi_image_draw_resized_file(
                        0,
                        0,
                        tvout_resized_width,
                        tvout_resized_height,
                        (PS8) cat222_file_name_ptr);

            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();
        }
    }
#endif /* __MMI_TVOUT__ */ 

    if (result >= 0)
    {
        /* if is fit content size mode, draw a rect to make the image like a photo */
        gdi_draw_rect(
            rect_offset_x - 1,
            rect_offset_y - 1,
            rect_offset_x + rect_width,
            rect_offset_y + rect_height,
            GDI_COLOR_WHITE);
        gdi_draw_rect(
            rect_offset_x - 2,
            rect_offset_y - 2,
            rect_offset_x + rect_width + 1,
            rect_offset_y + rect_height + 1,
            GDI_COLOR_BLACK);
        gdi_draw_rect(
            rect_offset_x - 3,
            rect_offset_y - 3,
            rect_offset_x + rect_width + 2,
            rect_offset_y + rect_height + 2,
            GDI_COLOR_WHITE);
    }
    else
    {
        if (err_str_ptr == NULL)
        {
            if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
            {
                err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);
            }
            else if (result == GDI_JPEG_ERR_DECODE_TIME_OUT)
            {
                err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);
            }
            else
            {
                err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
            }
        }

        Cat222ShowErrMsg(err_str_ptr);
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();
    
#ifndef __MMI_CAT222_NON_BLOCKING_DECODER__
    if (cat222_decode_result_callback != NULL)
    {
        cat222_decode_result_callback(result);
    }
#endif /* !__MMI_CAT222_NON_BLOCKING_DECODER__ */
}


/*****************************************************************************
 * FUNCTION
 *  Cat222ToggleTVDisplay
 * DESCRIPTION
 *  Toggle TVout display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TVOUT__
static void Cat222ToggleTVDisplay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tvout_max_width;
    S32 tvout_max_height;
    S32 tvout_resized_width;
    S32 tvout_resized_height;
    S32 tvout_resized_offset_x;
    S32 tvout_resized_offset_y;
    S32 result;

    GDI_HANDLE tvout_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_tvout_is_enable())
    {
        if (cat222_is_fullscr_tvout)
        {
            /* restore back to GDI */
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

            /* restore back to start mode1 */
            mdi_tvout_set_mode(
                MDI_TV_MODE_LCD_SCR,
                0,  /* layer_width */
                0); /* layer_height */
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

            cat222_is_fullscr_tvout = FALSE;
        }
        else
        {
            /* calculate size */
            mdi_tvout_get_owner_draw_best_size(&tvout_max_width, &tvout_max_height);

            if ((tvout_max_width >= cat222_img_width) && (tvout_max_height >= cat222_img_height))
            {
                tvout_resized_width = cat222_img_width;
                tvout_resized_height = cat222_img_height;
            }
            else
            {
                gdi_image_util_fit_bbox(
                    tvout_max_width,
                    tvout_max_height,
                    cat222_img_width,
                    cat222_img_height,
                    &tvout_resized_offset_x,
                    &tvout_resized_offset_y,
                    &tvout_resized_width,
                    &tvout_resized_height);
            }

            /* if is fullscreen, we shall set to owner MMI Owner draw, to avoid GDI's update */
            mdi_tvout_set_owner(MDI_TV_OWNER_APP);

            /* set mode to owner draw */
            mdi_tvout_set_mode(
                MDI_TV_MODE_OWNER_DRAW,
                tvout_resized_width,    /* layer_width */
                tvout_resized_height);  /* layer_height */

            tvout_layer = mdi_tvout_get_active_layer();

            gdi_layer_push_and_set_active(tvout_layer);
            gdi_layer_reset_clip();

            result = gdi_image_draw_resized_file(
                        0,
                        0,
                        tvout_resized_width,
                        tvout_resized_height,
                        (PS8) cat222_file_name_ptr);

            gdi_layer_pop_and_restore_active();

            /* blt to TV */
            mdi_tvout_blt();

            cat222_is_fullscr_tvout = TRUE;
        }
    }
}
#endif /* __MMI_TVOUT__ */ 

/*****************************************************************************
* [Category223]
*
* This category is for play audio.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *                    *
*  *       (Icon)       *
*  *                    *
*  *                    *
*  *      00:00:00      *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory223Screen
 * DESCRIPTION
 *  Show sategory 223 screen.
 * PARAMETERS
 *  title                   [IN]        Title string id
 *  title_icon              [IN]        Title image id
 *  left_softkey            [IN]        Lsk string id
 *  left_softkey_icon       [IN]        Lsk image id
 *  right_softkey           [IN]        Rsk string id
 *  right_softkey_icon      [IN]        Rsk image id
 *  message_icon            [IN]        Notification message icon
 *  flag                    [IN]        Time display type
 *  duration                [IN]        Audio duration
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory223Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message_icon,
        U16 flag,
        U32 duration,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 l = 0, y, h = 0, available_height, title_height = 0;
    S32 iwidth, iheight;
    PU8 image;
    UI_time t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif 

    gui_setup_common_layout();

    ADD_SCREEN_STRINGS((4, title, left_softkey, right_softkey, message));
    ADD_SCREEN_IMAGES((4, title_icon, left_softkey_icon, right_softkey_icon, message_icon));
    UI_UNUSED_PARAMETER(history_buffer);

    gui_lock_double_buffer();

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    entry_full_screen();
#endif 

    MMI_menu_shortcut_number = -1;
    clear_category_screen_key_handlers();
    clear_left_softkey();
    clear_right_softkey();

    dm_data.s32flags = 0;

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    
    if ((left_softkey == 0) && (left_softkey_icon == 0) && (right_softkey == 0) && (right_softkey_icon == 0))
    {
        dm_data.s32flags = DM_NO_SOFTKEY;
    }
    else
    {
        dm_data.s32flags = 0;
        wgui_category_screen_no_buttons = 0;
        register_left_softkey_handler();
        register_right_softkey_handler();
        register_default_hide_softkeys();
    }
    if ((title == 0) && (title_icon == 0))
    {
        status_icon = 1;
        ShowStatusIconsTitle();
    }
    else if (!((title == 0xffff) && (title_icon == 0xffff)))
    {
        status_icon = 2;
        MMI_title_string = (UI_string_type) get_string(title);
        MMI_title_icon = (PU8) get_image(title_icon);
    }
    else
    {
        status_icon = 0;
    }
    image = (PU8) get_image(message_icon);
    gui_measure_image(image, &iwidth, &iheight);
    available_height = MMI_content_height;

    if (dm_data.s32flags & DM_NO_SOFTKEY)
    {
        available_height += MMI_button_bar_height;
    }

    switch (status_icon)
    {
        case 0:
            title_height = 0;
            available_height += MMI_status_bar_height;
            break;
        case 1:
            title_height = MMI_title_height + MMI_status_bar_height;
            break;
        case 2:
            title_height = MMI_title_y + MMI_title_height;
            break;
    }

    /* set a fake time display to set the time object attributes for getting time string size */
    set_time_display(0, 0, 0, 0, 0);
    main_LCD_measure_time_duration_string(&l, &h);

    wgui_image_clip_x1 = 0;
    wgui_image_clip_x2 = UI_device_width - 1;
    wgui_image_clip_y1 = title_height;
    if (dm_data.s32flags & DM_NO_SOFTKEY)
    {
        wgui_image_clip_y2 = UI_device_height - 1;
    }
    else
    {
        wgui_image_clip_y2 = UI_device_height - MMI_button_bar_height - 1;
    }

    Cat223InitDruration(&t, (U32) (duration * 0.004615 + 0.5));

    set_main_LCD_time_duration_hide_function(Cat223HideDurationDisplay);

    set_time_duration(&t, duration);
    cat223_display_duration = MMI_TRUE;

    if (image == NULL)
    {
        y = title_height + (available_height >> 1) - (h >> 1);
        set_time_display(flag, (UI_device_width - l) / 2, y, l, h);
    }
    else
    {
        y = title_height + (available_height >> 1) - ((h + iheight + 4) >> 1);
        if (category_screen_layout_flags & WGUI_ORDER_IMAGE_TEXT)
        {
            wgui_set_animation_image_y((UI_device_width >> 1), y + 2, image);
            y = y + iheight + 4;
            set_time_display(flag, (UI_device_width - l) / 2, y, l, h);
        }
        else
        {
            y = title_height + ((available_height - iheight - h) >> 1);

            set_time_display(flag, (UI_device_width - l) / 2, y, l, h);

            y = title_height + available_height - iheight;

            wgui_set_animation_image_y((UI_device_width >> 1), y, image);
        }
    }

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory223Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY223_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND_COLOR;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate223CategoryControlArea);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory223Screen
 * DESCRIPTION
 *  Exit category 223
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory223Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();

    wgui_category_screen_no_buttons = 0;
    category_screen_layout_flags = 0;

    close_main_LCD_time_display();
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate223CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category223 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate223CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();

    if (status_icon == 1)
    {
        show_status_icons();
    }
    else if (status_icon == 2)
    {
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
    #if defined(GUI_COMMON_USE_THICK_TITLE)
        wgui_title_set_thick(MMI_TRUE);
        move_title(MMI_TITLE_X, MMI_TITLE_Y);
        resize_title(MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT);
    #else /* defined(GUI_COMMON_USE_THICK_TITLE) */
        wgui_title_set_thick(MMI_FALSE);
        move_title(MMI_TITLE_X, MMI_TITLE_Y);
        resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
    #endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
        show_title_status_icon();
    
#else /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
    #if defined(GUI_COMMON_USE_THICK_TITLE)
        wgui_title_set_thick(MMI_TRUE);
        move_title(MMI_TITLE_X, 0);
        resize_title(MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT);
    #else /* defined(GUI_COMMON_USE_THICK_TITLE) */
        wgui_title_set_thick(MMI_FALSE);
        move_title(MMI_TITLE_X, 0);
        resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
    #endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
#else /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
        show_title_status_icon();
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

        draw_title();
    }
    gui_set_clip(wgui_image_clip_x1, wgui_image_clip_y1, wgui_image_clip_x2, wgui_image_clip_y2);
    wgui_show_transparent_animation();

    if (cat223_display_duration == MMI_TRUE)
    {
        Cat223DrawDurationBar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cat223DrawDurationBar
 * DESCRIPTION
 *  Draw duration bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat223DrawDurationBar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time_display_duration();
}


/*****************************************************************************
 * FUNCTION
 *  Cat223InitDruration
 * DESCRIPTION
 *  Init duration parameters
 * PARAMETERS
 *  t               [IN]        time
 *  duration        [IN]        duration
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat223InitDruration(UI_time *t, U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf1, buf2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->DayIndex = 0;
    buf1 = duration / 60;
    t->nSec = duration - buf1 * 60;
    buf2 = buf1 / 60;
    t->nMin = buf1 - buf2 * 60;
    t->nHour = (U8) buf2;
}


/*****************************************************************************
 * FUNCTION
 *  Cat223HideDurationDisplay
 * DESCRIPTION
 *  Hide duration display
 * PARAMETERS
 *  x1      [IN]        start x
 *  y1      [IN]        start y
 *  x2      [IN]        end x
 *  y2      [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat223HideDurationDisplay(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = *current_MMI_theme->datetime_bar_duration_background_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_fill_rectangle(x1, y1, x2, y2, c);
    gui_pop_clip();
}

/*****************************************************************************
* [Category224]
*
* This category is for play a video clip. Can be full screen or standard MMI style.
*
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  * (Fullscreen Video) *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  **********************
*
*****************************************************************************/

#ifdef __MMI_VIDEO_PLAYER__
//#define  BLACK_BUFFER_SIZE ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)//061506 double buffer
static U8 *status_icon_buf = NULL;
static GDI_HANDLE status_icon_layer = GDI_ERROR_HANDLE;

U8 *gBlack_buf = NULL;
static gdi_handle *gBlack_layer = NULL;


/*****************************************************************************
 * FUNCTION
 *  ShowCategory224Screen
 * DESCRIPTION
 *  Show Category 224 Screen. Play video in full screen
 * PARAMETERS
 *  video_id                    [IN]        Video ID
 *  video_filename              [IN]        Video filename
 *  repeat_count                [IN]        Repeat count, 0 means infinite
 *  is_visual_update            [IN]        Update visual to LCM or not
 *  is_play_audio               [IN]        Play audio or not
 *  is_lcd_no_sleep             [IN]        Will let lcd no sleep. This shall always TRUE unless u will handle lcd sleeping event
 *  bg_color                    [IN]        Backgroud color
 *  play_finish_callback        [IN]        Play finish call back hdlr
 *  gui_buffer                  [IN]        Gui_buffer, use to detemin if it is newly enter
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory224Screen(
        U16 video_id,
        PS8 video_filename,
        U16 repeat_count,
        BOOL is_visual_update,
        BOOL is_play_audio,
        BOOL is_lcd_no_sleep,
        GDI_COLOR bg_color,
        void (*play_finish_callback) (MDI_RESULT),
        void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__
    ShowCategoryVdoplyScreen(
        TRUE,                   /* is_fullscreen *//* cat224 is fullscreen display */
        0,                      /* title_str */
        0,                      /* title_icon */
        0,                      /* lsk_str */
        0,                      /* lsk_icon */
        0,                      /* rsk_str */
        0,                      /* rsk_icon */
        video_id,               /* video_id */
        video_filename,         /* video_filename */
        repeat_count,           /* repeat_count */
        is_visual_update,       /* is_visual_update */
        is_play_audio,          /* is_play_audio */
        is_lcd_no_sleep,        /* is_lcd_no_sleep */
        bg_color,               /* bg_color */
        play_finish_callback,   /* play_finish_callback */
        gui_buffer);            /* gui_buffer */
#endif /* __MMI_VIDEO_PLAYER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  StopCategory224Video
 * DESCRIPTION
 *  Stop Category224 screen's video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void StopCategory224Video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopCategoryVdoplyVideo();
}


/*****************************************************************************
 * FUNCTION
 *  PauseCategory224Video
 * DESCRIPTION
 *  Pause Category224 screen's video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PauseCategory224Video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PauseCategoryVdoplyVideo();
}


/*****************************************************************************
 * FUNCTION
 *  ResumeCategory224Video
 * DESCRIPTION
 *  Resume Category224 screen's video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ResumeCategory224Video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResumeCategoryVdoplyVideo();
}

/*****************************************************************************
* [ShowCategory225Screen]
*
* Play video screen with title and softkey
*
*  **********************
*  *        Title       *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *       (Video)      *
*  *                    *
*  *                    *
*  *                    *
*  ********      ********
*  * LSK  *      *  RSK *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory225Screen
 * DESCRIPTION
 *  Show Generic Play Video Category.
 * PARAMETERS
 *  title_str                   [IN]        Title string id
 *  title_icon                  [IN]        Title icon id
 *  lsk_str                     [IN]        Lsk str id
 *  lsk_icon                    [IN]        Lsk icon id
 *  rsk_str                     [IN]        Lsk str id
 *  rsk_icon                    [IN]        Lsk icon id
 *  video_id                    [IN]        Video ID
 *  video_filename              [IN]        Video filename
 *  repeat_count                [IN]        Repeat count, 0 means infinite
 *  is_visual_update            [IN]        Update visual to LCM or not
 *  is_play_audio               [IN]        Play audio or not
 *  is_lcd_no_sleep             [IN]        Will let lcd no sleep. This shall always TRUE unless u will handle lcd sleeping event
 *  bg_color                    [IN]        Backgroud color
 *  play_finish_callback        [IN]        Play finish call back hdlr
 *  gui_buffer                  [IN]        Gui_buffer, use to detemin if it is newly enter
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory225Screen(
                U16 title_str,
                U16 title_icon,
                U16 lsk_str,
                U16 lsk_icon,
                U16 rsk_str,
                U16 rsk_icon,
                U16 video_id,
                PS8 video_filename,
                U16 repeat_count,
                BOOL is_visual_update,
                BOOL is_play_audio,
                BOOL is_lcd_no_sleep,
                GDI_COLOR bg_color,
                void (*play_finish_callback) (MDI_RESULT),
                void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAYER__
    ShowCategoryVdoplyScreen(
        FALSE,                  /* is_fullscreen */
        title_str,              /* title_str */
        title_icon,             /* title_icon */
        lsk_str,                /* lsk_str */
        lsk_icon,               /* lsk_icon */
        rsk_str,                /* rsk_str */
        rsk_icon,               /* rsk_icon */
        video_id,               /* video_id */
        video_filename,         /* video_filename */
        repeat_count,           /* repeat_count */
        is_visual_update,       /* is_visual_update */
        is_play_audio,          /* is_play_audio */
        is_lcd_no_sleep,        /* is_lcd_no_sleep */
        bg_color,               /* bg_color */
        play_finish_callback,   /* play_finish_callback */
        gui_buffer);            /* gui_buffer */
#endif /* __MMI_VIDEO_PLAYER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  DrawCateVdoCategoryControlArea
 * DESCRIPTION
 *  draw vdo contro area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coord
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCateVdoCategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resized_width, resized_height;
    S32 resized_offset_x, resized_offset_y;
    S32 content_width, content_height;
    S32 content_offset_x, content_offset_y;
    MDI_RESULT video_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cat_vdoply_is_full_screen)
    {
        content_width = MMI_content_width;
        content_height = MMI_content_height;
        content_offset_x = MMI_content_x;
        content_offset_y = MMI_content_y;
    }
    else
    {
        content_width = UI_device_width;
        content_height = UI_device_height;
        content_offset_x = 0;
        content_offset_y = 0;
    }


    /* 061506 double buffer Start */
    /*******************************************************************************
    *  Special status icon handle with double buffer
    *******************************************************************************/
#if (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_COMMON_USE_SPECIFIC_STYLE))
    if (wgui_is_touch_title_bar_buttons())
    {
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        U32 icon_flag;
    
        if (get_status_icon_bar_layer(0)==GDI_ERROR_HANDLE)
        {
            status_icon_buf = mmi_frm_scrmem_alloc(STATUS_ICON_BAR_DOUBLE_BUFFER_SIZE);
            MMI_ASSERT(status_icon_buf != NULL);
            gdi_layer_create_double_using_outside_memory(0, 0, UI_device_width, MMI_status_bar_height, &status_icon_layer, status_icon_buf, STATUS_ICON_BAR_DOUBLE_BUFFER_SIZE);
            MMI_ASSERT(status_icon_layer != GDI_ERROR_HANDLE);
            dm_add_blt_layer(status_icon_layer, DM_LAYER_TOP);
            gdi_layer_push_and_set_active(status_icon_layer);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
        }
        set_status_icon_bar_layer(0, status_icon_layer);
        icon_flag = get_status_icon_bar_type(0);
        icon_flag |= STATUS_ICON_BAR_ENABLE_DOUBLE_BUFFER;
        set_status_icon_bar_type(0, icon_flag);
        show_status_icons();
    #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
    }
#endif /* (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)) */
    /* 061506 double buffer End */

   /********************************************************************************
   *  Create Video Layer 
   ********************************************************************************/
    /* video is successfully opened, create video playback layer */
    if (cat_vdoply_is_video_open)
    {
        /* we need play video on an extra layer, so will use multi-layer */
        gdi_layer_multi_layer_enable();
        gdi_layer_get_base_handle(&wgui_base_layer);

        if (wgui_is_touch_title_bar_buttons())
        {
            gBlack_buf = mmi_frm_scrmem_alloc(BLACK_BUFFER_SIZE);

            if (GDI_LAYER_SUCCEED != dm_create_layer_using_outside_memory(
                                        0,
                                        0,
                                        UI_device_width,
                                        UI_device_height,
                                        &gBlack_layer,
                                        gBlack_buf,
                                        BLACK_BUFFER_SIZE,
                                        DM_LAYER_BOTTOM))
            {
                MMI_ASSERT(0);
            }
            gdi_layer_push_and_set_active(*gBlack_layer);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        }

        if ((wgui_video_info.width > content_width) || (wgui_video_info.height > content_height))
        {
            /* video larger than drawable region, need resize */

            /* calc draw size */
            gdi_util_fit_box(
                GDI_UTIL_MODE_LONG_SIDE_FIT,
                content_width,
                content_height,
                wgui_video_info.width,
                wgui_video_info.height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
        }
        else
        {
            /* video smaller than content region */
            if (!cat_vdoply_is_full_screen)
            {
                /* not full screen mode, play default size */
                resized_offset_x = (content_width - wgui_video_info.width) >> 1;
                resized_offset_y = (content_height - wgui_video_info.height) >> 1;

                resized_width = wgui_video_info.width;
                resized_height = wgui_video_info.height;
            }
            else
            {
                /* full screen mode, stretch (enlarge) it to fit content region */
                gdi_util_fit_box(
                    GDI_UTIL_MODE_LONG_SIDE_FIT,
                    content_width,
                    content_height,
                    wgui_video_info.width,
                    wgui_video_info.height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
            }

        }

        /* shift to content position */
        resized_offset_x += content_offset_x;
        resized_offset_y += content_offset_y;

        if (wgui_is_touch_title_bar_buttons())
        {
            dm_create_layer(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                &cat_vdoply_video_layer,
                DM_LAYER_ACTIVE_TOP);
        }
        else
        {
            dm_create_layer(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                &cat_vdoply_video_layer,
                DM_LAYER_ACTIVE_BOTTOM);
        }

        /* clear this layer with black */
        gdi_layer_push_and_set_active(cat_vdoply_video_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

        /* Get first frame and start to play */
        video_ret = mdi_video_ply_seek_and_get_frame(0, cat_vdoply_video_layer);
        if (video_ret < 0)
        {
            cat_vdoply_is_video_play = FALSE;
        }
        else
        {
            cat_vdoply_is_video_play = TRUE;
        }
        cat_vdoply_is_video_play_result = video_ret;
    }

}

/*****************************************************************************
* [ShowCategoryVdoplyScreen]
*
* Generic video play screen.
*
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  * (Fullscreen Video) *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  **********************
*
*  **********************
*  *        Title       *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *       (Video)      *
*  *                    *
*  *                    *
*  *                    *
*  ********      ********
*  * LSK  *      *  RSK *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategoryVdoplyScreen
 * DESCRIPTION
 *  Show Generic Play Video Category.
 * PARAMETERS
 *  is_fullscreen               [IN]        Is full screen display, if false, will draw title and softkeys
 *  title_str                   [IN]        Title string id
 *  title_icon                  [IN]        Title icon id
 *  lsk_str                     [IN]        Lsk str id
 *  lsk_icon                    [IN]        Lsk icon id
 *  rsk_str                     [IN]        Lsk str id
 *  rsk_icon                    [IN]        Lsk icon id
 *  video_id                    [IN]        Video ID
 *  video_filename              [IN]        Video filename
 *  repeat_count                [IN]        Repeat count, 0 means infinite
 *  is_visual_update            [IN]        Update visual to LCM or not
 *  is_play_audio               [IN]        Play audio or not
 *  is_lcd_no_sleep             [IN]        Will let lcd no sleep. This shall always TRUE unless u will handle lcd sleeping event
 *  bg_color                    [IN]        Backgroud color
 *  play_finish_callback        [IN]        Play finish call back hdlr
 *  gui_buffer                  [IN]        Gui_buffer, use to detemin if it is newly enter
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategoryVdoplyScreen(
                BOOL is_fullscreen,
                U16 title_str,
                U16 title_icon,
                U16 lsk_str,
                U16 lsk_icon,
                U16 rsk_str,
                U16 rsk_icon,
                U16 video_id,
                PS8 video_filename,
                U16 repeat_count,
                BOOL is_visual_update,
                BOOL is_play_audio,
                BOOL is_lcd_no_sleep,
                GDI_COLOR bg_color,
                void (*play_finish_callback) (MDI_RESULT),
                void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U16 btn_prev_item_id, btn_next_item_id;
    S32 content_width, content_height;
    S32 content_offset_x, content_offset_y;
    MDI_RESULT video_ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter a sublcd screen with static image */
    /* 
     * this is very important since we cant draw anything on sublcd while video is playing,
     * which will casue driver assert.
     * 
     * caller of this category may ignore sublcd handling, it will be handled in this category 
     */
#ifdef __MMI_SUBLCD__
    if (!cat_vdoply_is_sublcd_display)
    {
        ForceSubLCDScreen(EnterCategoryVdoplySubScreen);
    }
#endif /* __MMI_SUBLCD__ */ 

    /* arg check */
    MMI_ASSERT((video_id == 0 && video_filename != NULL) || (video_id != 0 && video_filename == NULL));

    gui_setup_common_layout();
    wgui_softkey_set_filler_disabled(MMI_TRUE);
    
    /* clear keys */
    clear_category_screen_key_handlers();
    clear_key_handlers();
    clear_left_softkey();
    clear_right_softkey();

    /* init var */
    cat_vdoply_is_video_from_id = (video_id != 0) ? TRUE : FALSE;
    cat_vdoply_video_is_visual_update = is_visual_update;
    cat_vdoply_video_is_play_audio = is_play_audio;
    cat_vdoply_video_is_lcd_no_sleep = is_lcd_no_sleep;
    cat_vdoply_play_finish_callback = play_finish_callback;

    /* stop MMI sleep */
    if (cat_vdoply_video_is_lcd_no_sleep)
    {
        TurnOnBacklight(0);
    }

    /* set audio volumn */
    if (gui_buffer == NULL)
    {
        /* first time enter */
        cat_vdoply_audio_volumn = LEVEL5;
    }

    if (cat_vdoply_video_is_play_audio)
    {
        /* full screen play do not allows vol adjustment */
        if (!is_fullscreen)
        {
            SetKeyHandler(CatVdoplyVolUp, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(CatVdoplyVolDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        }

        /* suspend background audio */
        mdi_audio_suspend_background_play();
        
        /* init audio volumn */
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, cat_vdoply_audio_volumn);
    }

    /*
     * user may request to repeat play many times, and wants a callback bewteen each play,
     * so we have to handle repeat play within this category by seeking to first frame 
     * after play finished each time, instead of using driver's repeat play.
     */

    cat_vdoply_video_repeat_count = (repeat_count == 0) ? 0xffff : repeat_count;        /* 0xff means infinte play */

    if (repeat_count != 0)
    {
        cat_vdoply_video_repeat_count--;
    }

   /********************************************************************************
   *  Draw non-full screen UI
   ********************************************************************************/
    if (!is_fullscreen)
    {
        /* not fullscreen, draw title and softkey */

        /* init softkey */
        change_left_softkey(lsk_str, lsk_icon);
        change_right_softkey(rsk_str, rsk_icon);
        register_left_softkey_handler();
        register_right_softkey_handler();
        register_default_hide_softkeys();

        /* init title */
        MMI_title_string = (UI_string_type) get_string(title_str);
        MMI_title_icon = (PU8) get_image(title_icon);

        /* set content size */
        if (wgui_is_touch_title_bar_buttons())
        {
            content_width = UI_device_width;
            content_height = UI_device_height;
            content_offset_x = 0;
            content_offset_y = 0;
            cat_vdoply_is_full_screen = TRUE;
            title_bg_id = IMAGE_VIEW_TITLEBAR_BG;
            wgui_set_wallpaper_on_bottom(MMI_TRUE);
        }
        else
        {
            content_width = MMI_content_width;
            content_height = MMI_content_height;
            content_offset_x = MMI_content_x;
            content_offset_y = MMI_content_y;
            cat_vdoply_is_full_screen = FALSE;
        }

        /* clear shortcut num */
        MMI_menu_shortcut_number = -1;

        /* draw to buffer, but not blt to LCM by using lock */
        gdi_layer_lock_frame_buffer();

        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();

        /* clear content color */
        if (wgui_is_touch_title_bar_buttons())
        {
            gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gdi_draw_solid_rect(
                MMI_content_x,
                MMI_content_y,
                MMI_content_x + MMI_content_width - 1,
                MMI_content_y + MMI_content_height - 1,
                GDI_COLOR_WHITE);
            clear_buttonbar();
        }

        /* 061506 double buffer Start */
#if (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_SUBMENU_USE_SPECIFIC_STYLE))
        if (wgui_is_touch_title_bar_buttons())
        {
        #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
            gOnFullScreen = MMI_IN_NORMAL_SCREEN; /* title shift */
            show_status_icon_bar(0);
            register_hide_status_icon_bar(0, hide_status_icons_bar0);
        #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
        }
#endif /* (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)) */ 
        /* 061506 double buffer End */
 
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
#if defined(GUI_COMMON_USE_THICK_TITLE)
        wgui_title_set_thick(MMI_TRUE);
#else /* defined(GUI_COMMON_USE_THICK_TITLE) */
        wgui_title_set_thick(MMI_FALSE);
#endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
        move_title(MMI_COMMON_TITLE_X, MMI_COMMON_TITLE_Y);
        resize_title(MMI_COMMON_TITLE_WIDTH, MMI_COMMON_TITLE_HEIGHT);
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
        draw_title();
        show_softkey_background();
        show_left_softkey();
        show_right_softkey();

        gdi_layer_unlock_frame_buffer();

    }
    else
    {
        /* entry full screen */
        entry_full_screen();

        /* clear full screen */
        gdi_layer_clear(bg_color);

        /* full screen */
        content_width = UI_device_width;
        content_height = UI_device_height;
        content_offset_x = 0;
        content_offset_y = 0;
        cat_vdoply_is_full_screen = TRUE;
    }

   /********************************************************************************
   *  Open Video
   ********************************************************************************/
    if (video_id != 0)
    {
        /* source from id */
        /* always open with audio, if do not want audio, mute it by calling mdi function */
        video_ret = mdi_video_ply_open_clip_id(video_id, &wgui_video_info);

        cat_vdoply_is_video_open = (video_ret >= 0) ? TRUE : FALSE;
    }
    else if (video_filename != NULL)
    {
        /* source from file */
        /* always open with audio, if do not want audio, dsiable it in play function */
        video_ret = mdi_video_ply_open_clip_file(video_filename, &wgui_video_info);

        cat_vdoply_is_video_open = (video_ret >= 0) ? TRUE : FALSE;
    }
    else
    {
        /* no proper source */
        MMI_ASSERT(0);
    }
    cat_vdoply_is_video_play_result = video_ret;

    /* check if the title bar buttons are enabled for the particular screen. */
    if (wgui_is_touch_title_bar_buttons())
    {
        btn_prev_item_id = dm_add_button(
                            NULL,
                            get_image(LEFT_RED_ARROW),
                            get_image(LEFT_RED_ARROW),
                            cat226_hide_button_full_screen);
        btn_next_item_id = dm_add_button(
                            NULL,
                            get_image(RIGHT_RED_ARROW),
                            get_image(RIGHT_RED_ARROW),
                            cat226_hide_button_full_screen);

    #if defined(__MMI_TOUCH_SCREEN__)

        /* register the handler for pen event down istead of pen event up. */
        dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_down_handler);
        dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_down_handler);

    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    }

    RedrawCategoryFunction = dm_redraw_category_screen;
    ExitCategoryFunction = ExitCategoryVdoplyScreen;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

    if (wgui_is_touch_title_bar_buttons())
    {
        dm_data.s32CatId = MMI_CATEGORY_VDOPLY_BUTTON;
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY_VDOPLY;
    }

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    if (is_fullscreen)
    {
        dm_data.s32flags = DM_NO_TITLE | DM_NO_STATUS_BAR | DM_NO_SOFTKEY | DM_BUTTON_DISABLE_BACKGROUND;
    }
    else
    {
        dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }

    dm_setup_data(&dm_data);

    dm_register_category_controlled_callback(DrawCateVdoCategoryControlArea);
    dm_redraw_category_screen();
    /* 
     * register exit category function befor calling the callback function, 
     * since this call back may exit this category 
     */

    /* if the screen is from the pop-up go-back, do not play video */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    
    video_ret = cat_vdoply_is_video_play_result;
    if (cat_vdoply_is_video_play == TRUE)
    {
        if (wgui_is_touch_title_bar_buttons())
        {
        /* 061506 double buffer Start */
        #if (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)) && ((defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_COMMON_USE_SPECIFIC_STYLE)))
            /* black-video-base-status */
            video_ret = mdi_video_ply_play(
                            cat_vdoply_video_layer,
                            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3,
                            GDI_LAYER_ENABLE_LAYER_1,
                            1,                              /* repeat count */
                            is_visual_update,               /* update to LCM or not */
                            is_play_audio,                  /* play aud or not */                            
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                            100,                            /* 1x play speed */
                            CatVdoplyPlayFinishCallback);   /* hook callback */
        #else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
            /* black-video-base */
            video_ret = mdi_video_ply_play(
                            cat_vdoply_video_layer,
                            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,
                            GDI_LAYER_ENABLE_LAYER_1,
                            1,                              /* repeat count */
                            is_visual_update,               /* update to LCM or not */
                            is_play_audio,                  /* play aud or not */
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                            100,                            /* 1x play speed */
                            CatVdoplyPlayFinishCallback);   /* hook callback */
        #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
        }
        else
        {
            /* base-video */
            video_ret = mdi_video_ply_play(
                            cat_vdoply_video_layer,
                            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
                            GDI_LAYER_ENABLE_LAYER_1,
                            1,                              /* repeat count */
                            is_visual_update,               /* update to LCM or not */
                            is_play_audio,                  /* play aud or not */                            
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                            100,                            /* 1x play speed */
                            CatVdoplyPlayFinishCallback);   /* hook callback */
        }
        /* 061506 double buffer Start */

        cat_vdoply_is_video_play = (video_ret >= 0) ? TRUE : FALSE;
        cat_vdoply_is_video_force_stop = FALSE;
    }

    if (cat_vdoply_is_video_play == FALSE)
    {
        /* open file failed or play failed - reutrn error cause */
        if (cat_vdoply_play_finish_callback != NULL)
        {
            cat_vdoply_play_finish_callback(video_ret);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryVdoplyScreen
 * DESCRIPTION
 *  Exit Category 224 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategoryVdoplyScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_is_video_open)
    {
        /* stop video playing */
        if (cat_vdoply_is_video_play)
        {
            mdi_video_ply_stop();
            cat_vdoply_is_video_play = FALSE;
        }

        /* close video source */
        if (cat_vdoply_is_video_from_id)
        {
            /* source from id */
            mdi_video_ply_close_clip_id();
            cat_vdoply_is_video_open = FALSE;
        }
        else
        {
            /* source from file */
            mdi_video_ply_close_clip_file();
            cat_vdoply_is_video_open = FALSE;
        }
    }

    /* let MMI can sleep */
    if (cat_vdoply_video_is_lcd_no_sleep)
    {
        TurnOffBacklight();
    }

    if (cat_vdoply_video_is_play_audio)
    {
        /* resume background audio */
        mdi_audio_resume_background_play();
    }

    if (wgui_is_touch_title_bar_buttons())
    {
    /* 061506 double buffer Start */
    /*******************************************************************************
    *  Special status icon handle with double buffer
    *******************************************************************************/
#if (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_SUBMENU_USE_SPECIFIC_STYLE))
    #if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        U32 icon_flag;
    
        if (get_status_icon_bar_layer(0)!=GDI_ERROR_HANDLE && status_icon_buf!=NULL)
        {
            mmi_frm_scrmem_free(status_icon_buf);
            status_icon_buf = NULL;
            status_icon_layer = GDI_ERROR_HANDLE;
            set_status_icon_bar_layer(0, GDI_ERROR_HANDLE);
        }
        icon_flag = get_status_icon_bar_type(0);
        icon_flag &= ~ STATUS_ICON_BAR_ENABLE_DOUBLE_BUFFER;
        set_status_icon_bar_type(0, icon_flag);
    #endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
#endif /* (defined(GUI_COMMON_USE_SPECIFIC_STYLE) && defined(GUI_COMMON_SHOW_STATUS_ICON)) || (!defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)) */
    /* 061506 double buffer End */
    
        title_bg_id = 0;

        if (gBlack_buf != NULL)
        {
            mmi_frm_scrmem_free(gBlack_buf);
        }

        gBlack_buf = NULL;
        gBlack_layer = NULL;
        entry_full_screen();
    }
    wgui_reset_touch_title_bar_buttons();

    ExitCategoryFunction = MMI_dummy_function;
    RedrawCategoryFunction = MMI_dummy_function;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;

#ifdef __MMI_SUBLCD__
    /* exit sublcd */
    if (cat_vdoply_is_sublcd_display)
    {
        GoBackSubLCDHistory();
        cat_vdoply_is_sublcd_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  EnterCategoryVdoplySubScreen
 * DESCRIPTION
 *  Entery Category vdoply's sublcd screen, will draw an icon on sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void EnterCategoryVdoplySubScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    cat_vdoply_is_sublcd_display = TRUE;

    ShowCategory332Screen(IMG_ID_VDOPLY_SUBLCD_ICON);

    /* force all animation on sulcd stop, this is prevent IMG_ID_VDOPLY_SUBLCD_ICON is an animation gif */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_image_stop_animation_all();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    SetSubLCDExitHandler(ExitCategoryVdoplySubScreen);

}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryVdoplySubScreen
 * DESCRIPTION
 *  Exit Category Vdoply's sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategoryVdoplySubScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    if (cat_vdoply_is_video_play)
    {
        mdi_video_ply_stop();
        cat_vdoply_is_video_play = FALSE;
    }

    cat_vdoply_is_sublcd_display = FALSE;

    sub_history.entryFuncPtr = EnterCategoryVdoplySubScreen;
    AddSubLCDHistory(&sub_history);

}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  StopCategoryVdoplyVideo
 * DESCRIPTION
 *  Stop Category Vdoply screen's video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void StopCategoryVdoplyVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_vdoply_is_video_force_stop = TRUE;

    if (cat_vdoply_is_video_open)
    {
        /* stop video playing */
        if (cat_vdoply_is_video_play)
        {
            mdi_video_ply_stop();
            cat_vdoply_is_video_play = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PauseCategoryVdoplyVideo
 * DESCRIPTION
 *  Pause video play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PauseCategoryVdoplyVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop video playing */
    if (cat_vdoply_is_video_open)
    {
        if (cat_vdoply_is_video_play)
        {
            mdi_video_ply_stop();
            cat_vdoply_is_video_play = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResumeCategoryVdoplyVideo
 * DESCRIPTION
 *  Resume video play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ResumeCategoryVdoplyVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT video_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the callback function maybe already exit this category and close video file */
    /* check before play this video */
    if (cat_vdoply_is_video_open)
    {
        /* start play again */
        if (wgui_is_touch_title_bar_buttons())
        {
            video_ret = mdi_video_ply_play(
                            cat_vdoply_video_layer,
                            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,
                            GDI_LAYER_ENABLE_LAYER_1,
                            1,                              /* repeat count */
                            cat_vdoply_video_is_visual_update,   /* update to LCM or not */
                            cat_vdoply_video_is_play_audio,      /* play aud or not */
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                            100,                            /* 1x play speed */
                            CatVdoplyPlayFinishCallback);   /* hook callback */
        }
        else
        {
            video_ret = mdi_video_ply_play(
                            cat_vdoply_video_layer,
                            GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
                            GDI_LAYER_ENABLE_LAYER_1,
                            1,                              /* repeat count */
                            cat_vdoply_video_is_visual_update,   /* update to LCM or not */
                            cat_vdoply_video_is_play_audio,      /* play aud or not */                            
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                            100,                            /* 1x play speed */
                            CatVdoplyPlayFinishCallback);   /* hook callback */
        }

        if (video_ret < 0)
        {
            cat_vdoply_play_finish_callback(video_ret);

            if (cat_vdoply_play_finish_callback != NULL)
            {
                cat_vdoply_play_finish_callback(video_ret);
            }
        }
        else
        {
            cat_vdoply_is_video_play = TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  CatVdoplyPlayFinishCallback
 * DESCRIPTION
 *  Play finish callback function, will handle looping here
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void CatVdoplyPlayFinishCallback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT video_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
        /* success play finished */

        /* call callback function */
        if (cat_vdoply_play_finish_callback != NULL)
        {
            cat_vdoply_play_finish_callback(result);
        }

        /* teminate condition */
        if (cat_vdoply_video_repeat_count == 0)
        {
            return;
        }

        /* force stopped, will not loop again */
        if (cat_vdoply_is_video_force_stop == TRUE)
        {
            return;
        }

        /* calc remain count */
        if (cat_vdoply_video_repeat_count > 0)  /* play again */
        {
            if (cat_vdoply_video_repeat_count != 0xffff)
            {
                /* not infite play */
                cat_vdoply_video_repeat_count--;
            }
        }

        /* the callback function maybe already exit this category and close video file */
        /* check before play this video */
        if (cat_vdoply_is_video_open)
        {
            /* seek to first frame */
            video_ret = mdi_video_ply_seek(0);

            if (video_ret < 0)
            {
                if (cat_vdoply_play_finish_callback != NULL)
                {
                    cat_vdoply_play_finish_callback(video_ret);
                }
                return;
            }

            /* start play again */
            if (wgui_is_touch_title_bar_buttons())
            {
                video_ret = mdi_video_ply_play(
                                cat_vdoply_video_layer,
                                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,
                                GDI_LAYER_ENABLE_LAYER_1,
                                1,                      /* repeat count */
                                cat_vdoply_video_is_visual_update,       /* update to LCM or not */
                                cat_vdoply_video_is_play_audio,         /* play aud or not */    
                                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                                MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                                100,                    /* 1x play speed */
                                CatVdoplyPlayFinishCallback);    /* hook callback */
            }
            else
            {
                video_ret = mdi_video_ply_play(
                                cat_vdoply_video_layer,
                                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
                                GDI_LAYER_ENABLE_LAYER_1,
                                1,                      /* repeat count */
                                cat_vdoply_video_is_visual_update,      /* update to LCM or not */
                                cat_vdoply_video_is_play_audio,         /* play aud or not */                                
                                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                                MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                                100,                    /* 1x play speed */
                                CatVdoplyPlayFinishCallback);    /* hook callback */
            }

            if (video_ret < 0)
            {
                cat_vdoply_play_finish_callback(video_ret);

                if (cat_vdoply_play_finish_callback != NULL)
                {
                    cat_vdoply_play_finish_callback(video_ret);
                }
            }
        }
    }
    else
    {
        /* something wrong */

        /* call callback function */
        if (cat_vdoply_play_finish_callback != NULL)
        {
            cat_vdoply_play_finish_callback(result);
        }
    }

}
#endif /* __MMI_VIDEO_PLAYER__ */ 


#if defined(__MMI_VIDEO_PLAYER__) || defined(__MMI_SWFLASH__) 
/*****************************************************************************
 * FUNCTION
 *  CatVdoplyVolUp
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CatVdoplyVolUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_audio_volumn < LEVEL7)
    {
        cat_vdoply_audio_volumn++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, cat_vdoply_audio_volumn);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CatVdoplyVolDown
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CatVdoplyVolDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_audio_volumn > LEVEL1)
    {
        cat_vdoply_audio_volumn--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, cat_vdoply_audio_volumn);
    }
}
#endif /* __MMI_VIDEO_PLAYER__ */ 

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
#endif

/*****************************************************************************
 * FUNCTION
 *  cat226_hide_button_full_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button_object       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void cat226_hide_button_full_screen(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    button *button_obj = (button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        button_obj->x,
        button_obj->y,
        button_obj->x + button_obj->width + 1,
        button_obj->y + button_obj->height + 1);
    gdi_draw_solid_rect(
        button_obj->x,
        button_obj->y,
        button_obj->x + button_obj->width + 1,
        button_obj->y + button_obj->height + 1,
        GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
}

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
/* under construction !*/
#endif

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  Cat226RegisterPenHandlers
 * DESCRIPTION
 *  Register pen event handlers for category control areas in category226
 * PARAMETERS
 *  ctrl_area_idx       [IN]        
 *  pen_hdlr            [IN]        
 *  event_type          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void Cat226RegisterPenHandlers(U16 ctrl_area_idx, mmi_pen_handler pen_hdlr, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ctrl_area_idx == 1)
    {
        wgui_register_category_screen_control_area_pen_handlers(pen_hdlr, event_type);
    }
    else if (ctrl_area_idx == 0)
    {
        wgui_register_category_screen_control_area2_pen_handlers(pen_hdlr, event_type);
    }
    else
    {
        MMI_ASSERT(ctrl_area_idx);
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL (*Cat227ControlAreaPenHandler)(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point) = NULL;


/*****************************************************************************
 * FUNCTION
 *  Cate227CategoryControlAreaPenDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Cate227CategoryControlAreaPenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat227ControlAreaPenHandler != NULL)
    {
        return Cat227ControlAreaPenHandler(MMI_PEN_EVENT_DOWN, point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cate227CategoryControlAreaPenUpHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Cate227CategoryControlAreaPenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat227ControlAreaPenHandler != NULL)
    {
        return Cat227ControlAreaPenHandler(MMI_PEN_EVENT_UP, point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cate227CategoryControlAreaPenMoveHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Cate227CategoryControlAreaPenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat227ControlAreaPenHandler != NULL)
    {
        return Cat227ControlAreaPenHandler(MMI_PEN_EVENT_MOVE, point);
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory227Screen
 * DESCRIPTION
 *  Category screen for image viewer
 *  one preview area, one image view area.
 * PARAMETERS
 *  title_string            [IN]        Title string
 *  title_icon              [IN]        Title icon
 *  left_softkey            [IN]        Left softkey string id
 *  left_softkey_icon       [IN]        Left softkey icon id
 *  right_softkey           [IN]        Right softkey string id
 *  right_softkey_icon      [IN]        Right softkey icon id
 *  display_call_back       [IN]        Event handler application customized area
 *  pen_all_call_back       [IN]        Event handler to handle pen event 
 
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory227Screen(
        U8 *title_string,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        void (*display_call_back) (dm_coordinates *coordinate),
        MMI_BOOL (*pen_all_call_back)(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_string = (UI_string_type) title_string;
    MMI_title_icon = get_image(title_icon);
    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();
    MMI_menu_shortcut_number = -1;

    ExitCategoryFunction = UI_dummy_function;
    GetCategoryHistorySize = dummy_get_history_size;
    GetCategoryHistory = dummy_get_history;
    RedrawCategoryFunction = dm_redraw_category_screen;

    dm_data.s32CatId = MMI_CATEGORY227_ID;
    dm_data.s32ScrId = GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(display_call_back);
#if defined(__MMI_TOUCH_SCREEN__)
    Cat227ControlAreaPenHandler = pen_all_call_back;
    wgui_register_category_screen_control_area_pen_handlers(Cate227CategoryControlAreaPenDownHandler, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cate227CategoryControlAreaPenUpHandler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(Cate227CategoryControlAreaPenMoveHandler, MMI_PEN_EVENT_MOVE);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

    dm_redraw_category_screen();

}

#if defined(__MMI_SWFLASH__)
/*****************************************************************************
 * FUNCTION
 *  CatSWFlashPlayEnd
 * DESCRIPTION
 *  SWflash play end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CatSWFlashPlayEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_swflash_is_open == MMI_FALSE || cat_swflash_is_play == MMI_FALSE)
    {
        /* open file failed or play failed - reutrn error cause */
        if (cat_swflash_play_finish_callback != NULL)
        {
            cat_swflash_play_finish_callback(-1);
        }
    }
}


#ifdef __MMI_ALPHA_BLENDING__
void cat34_swflash_callback(S32 offset_x, S32 offset_y, S32 width, S32 height)
{
    cat33_redraw_alpha_images();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  DrawCateSWFlashCategoryControlArea
 * DESCRIPTION
 *  draw vdo contro area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coord
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCateSWFlashCategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_width, content_height;
    S32 content_offset_x, content_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cat_swflash_is_full_screen)
    {
        content_width = MMI_content_width;
        content_height = MMI_content_height;
        content_offset_x = MMI_content_x;
        content_offset_y = MMI_content_y;
    }
    else
    {
        content_width = UI_device_width;
        content_height = UI_device_height;
        content_offset_x = 0;
        content_offset_y = 0;
    }

   /********************************************************************************
   *  Create Video Layer 
   ********************************************************************************/
    /* video is successfully opened, create video playback layer */
    if (cat_swflash_is_open)
    {
        if (cat_swflash_layer == GDI_ERROR_HANDLE || cat_swflash_layer == GDI_LAYER_EMPTY_HANDLE)
        {/* the swflash layer maybe already set */
            if (wgui_is_touch_title_bar_buttons())
            {
                dm_create_layer(
                    content_offset_x,
                    content_offset_y,
                    content_width,
                    content_height,
                    &cat_swflash_layer,
                    DM_LAYER_ACTIVE_TOP);
            }
            else
            {
                dm_create_layer(
                    content_offset_x,
                    content_offset_y,
                    content_width,
                    content_height,
                    &cat_swflash_layer,
                    DM_LAYER_ACTIVE_BOTTOM);
            }
        }

        /* clear this layer with black */
        gdi_layer_push_and_set_active(cat_swflash_layer);
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_layer_pop_and_restore_active();

#ifdef __MMI_ALPHA_BLENDING__
        gdi_image_abm_set_source_layer(cat_swflash_layer);
	if (g_dm_data.s32CatId == MMI_CATEGORY34_ID)
	{
	    mdi_swflash_register_blt_callback(cat34_swflash_callback, NULL);
	}
/* 073007 abm dialing Start */
    #if (( defined ( __MMI_MAINLCD_176X220__ ) || defined (__MMI_MAINLCD_240X320__)  || defined (__MMI_MAINLCD_320X240__)) && defined (__GDI_MEMORY_PROFILE_2__) )
    #ifndef __MMI_TOUCH_DIAL_SCREEN__
	else if (g_dm_data.s32CatId == MMI_CATEGORY16_ID)
	{
	    mdi_swflash_register_blt_callback(cat16_swflash_callback, NULL);
	}
    #endif
    #endif
/* 073007 abm dialing End */
#endif /* __MMI_ALPHA_BLENDING__ */

        /* Get first frame and start to play */
        cat_swflash_play_ret = mdi_swflash_play(
                                cat_swflash_layer,
                                1,                      /* repeat count */
                                MDI_DEVICE_SPEAKER2,    /* audio_path */
                                cat_swflash_play_finish_callback);     /* play_result_callback */

        cat_swflash_is_play = (cat_swflash_play_ret >= 0) ? MMI_TRUE : MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  CatSWFlashVolUp
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CatSWFlashVolUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_swflash_audio_volumn < LEVEL7)
    {
        cat_swflash_audio_volumn++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, cat_swflash_audio_volumn);
        WriteValue(NVRAM_SWFLASH_VOLUME, &cat_swflash_audio_volumn, DS_BYTE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  CatSWFlashVolDown
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CatSWFlashVolDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_swflash_audio_volumn > LEVEL1)
    {
        cat_swflash_audio_volumn--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, cat_swflash_audio_volumn);
        WriteValue(NVRAM_SWFLASH_VOLUME, &cat_swflash_audio_volumn, DS_BYTE, &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory229Screen
 * DESCRIPTION
 *  show category 229
 * PARAMETERS
 *  title_str                   [IN]        Title for the screen
 *  title_icon                  [IN]        Icon shown with the title
 *  lsk_str                     [IN]        Left softkey label
 *  lsk_icon                    [IN]        Icon for the Left softkey
 *  rsk_str                     [IN]        Right softkey label
 *  rsk_icon                    [IN]        Icon for the Right softkey
 *  resource_id                 [IN]        Resource ID
 *  resource_filename           [IN]        Resource filename
 *  repeat_count                [IN]        repeat count
 *  is_play_audio               [IN]        Is play audio
 *  is_vibrate_on               [IN]        Is vibrate on
 *  is_interaction_on           [IN]        Is interaction on
 *  is_lcd_no_sleep             [IN]        Is lcd no sleep
 *  is_full_screen              [IN]        Is full screen
 *  bg_color                    [IN]        Background color
 *  play_finish_callback        [IN]        Callback of finish play
 *  gui_buffer                  [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory229Screen(
        U8 *title_str,
        U16 title_icon,
        U16 lsk_str,
        U16 lsk_icon,
        U16 rsk_str,
        U16 rsk_icon,
        U16 resource_id,
        PS8 resource_filename,
        U16 repeat_count,
        MMI_BOOL is_play_audio,
        MMI_BOOL is_vibrate_on,
        MMI_BOOL is_interaction_on,
        MMI_BOOL is_lcd_no_sleep,
        MMI_BOOL is_full_screen,
        GDI_COLOR bg_color,
        void (*play_finish_callback) (MDI_RESULT),
        void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U16 btn_prev_item_id, btn_next_item_id;
    U32 playmode;
    MDI_RESULT mfh_ret;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_setup_common_layout();
    /* init var */
    cat_swflash_is_from_id = (resource_id != 0) ? MMI_TRUE : MMI_FALSE;
    cat_swflash_is_audio_on = is_play_audio;
    cat_swflash_is_vibrate_on = is_vibrate_on;
    cat_swflash_is_interaction_on = is_interaction_on;
    cat_swflash_is_lcd_no_sleep = is_lcd_no_sleep;
    cat_swflash_play_finish_callback = play_finish_callback;
    cat_swflash_is_full_screen = is_full_screen;

    /* setup keys */
    set_left_softkey_label(get_string(lsk_str));
    set_left_softkey_icon(get_image(lsk_icon));
    set_right_softkey_label(get_string(rsk_str));
    set_right_softkey_icon(get_image(rsk_icon));
    SetupCategoryKeyHandlers();

    /* setup title */
    MMI_title_string = (UI_string_type) title_str;
    MMI_menu_shortcut_number = -1;

    /* setup top selection bar */
    if (wgui_is_touch_title_bar_buttons())
    {
        MMI_title_icon = NULL;
        wgui_set_wallpaper_on_bottom(MMI_TRUE);
        
        btn_prev_item_id = dm_add_button(
                            NULL,
                            get_image(LEFT_RED_ARROW),
                            get_image(LEFT_RED_ARROW),
                            cat226_hide_button_full_screen);
        btn_next_item_id = dm_add_button(
                            NULL,
                            get_image(RIGHT_RED_ARROW),
                            get_image(RIGHT_RED_ARROW),
                            cat226_hide_button_full_screen);
        title_bg_id = IMAGE_VIEW_TITLEBAR_BG;   /* for showing different title bar. */

    #if defined(__MMI_TOUCH_SCREEN__)
        /* register the handler for pen event down istead of pen event up. */
        dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_down_handler);
        dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_down_handler);
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    }
    else
    {
        MMI_title_icon = (PU8) get_image(title_icon);
    }

    /* Start SWFlash handling */

    /* stop MMI sleep */
    if (cat_swflash_is_lcd_no_sleep)
    {
        TurnOnBacklight(0);
    }

    /* set audio volumn */
    if (gui_buffer == NULL)
    {
        /* first time enter */
        ReadValue(NVRAM_SWFLASH_VOLUME, &cat_swflash_audio_volumn, DS_BYTE, &error);
        if (cat_swflash_audio_volumn == 0xff)
        {
            cat_swflash_audio_volumn = 4;
        }        
    }

    if (cat_swflash_is_audio_on)
    {
        /* full screen play do not allows vol adjustment */
        if (!is_full_screen)
        {
            SetKeyHandler(CatSWFlashVolUp, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(CatSWFlashVolDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        }

        /* suspend background audio */
        mdi_audio_suspend_background_play();
        
        /* init audio volumn */
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, cat_swflash_audio_volumn);
    }

    /*
     * user may request to repeat play many times, and wants a callback bewteen each play,
     * so we have to handle repeat play within this category by seeking to first frame 
     * after play finished each time, instead of using driver's repeat play.
     */

    cat_swflash_repeat_count = (repeat_count == 0) ? 0xffff : repeat_count;      /* 0xff means infinte play */

    if (repeat_count != 0)
    {
        cat_swflash_repeat_count--;
    }


   /********************************************************************************
   *  Open SWFlash
   ********************************************************************************/
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
#endif 
    if (is_play_audio)
    {
        playmode = SWFLASH_PLAYER;
    }
    else
    {
        playmode = SWFLASH_SCREEN;
    }


    if (resource_id != 0)
    {
        /* source from id */
        /* always open with audio, if do not want audio, mute it by calling mdi function */
        mfh_ret = mdi_swflash_open_id(resource_id, playmode, &wgui_swflash_info);

        cat_swflash_is_open = (mfh_ret >= 0) ? MMI_TRUE : MMI_FALSE;
    }
    else if (resource_filename != NULL)
    {
        /* source from file */
        /* always open with audio, if do not want audio, dsiable it in play function */
        mfh_ret = mdi_swflash_open_file(resource_filename, playmode, &wgui_swflash_info);

        cat_swflash_is_open = (mfh_ret >= 0) ? MMI_TRUE : MMI_FALSE;
    }
    else
    {
        /* no proper source */
        MMI_ASSERT(0);
    }

    /* setup draw manager functions */
    ExitCategoryFunction = ExitCategorySWFlashScreen;
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    if (wgui_is_touch_title_bar_buttons())
    {
        dm_data.s32CatId = MMI_CATEGORY229_ID;
    }
    else
    {
        dm_data.s32CatId = MMI_CATEGORY_VDOPLY;
    }

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    if (is_full_screen)
    {
        if (wgui_is_touch_title_bar_buttons())
        {
            dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
        }
        else
        {
            dm_data.s32flags = DM_NO_TITLE | DM_NO_STATUS_BAR | DM_NO_SOFTKEY;
        }
    }
    else
    {
        dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    }

    wgui_softkey_set_filler_disabled(MMI_TRUE);

    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCateSWFlashCategoryControlArea);
    dm_redraw_category_screen();

    CatSWFlashPlayEnd();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategorySWFlashScreen
 * DESCRIPTION
 *  Exit Category 224 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategorySWFlashScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_swflash_is_open)
    {
        /* stop video playing */
        if (cat_swflash_is_play)
        {
            mdi_swflash_stop();
            cat_swflash_is_play = MMI_FALSE;
        }

        /* close video source */
        if (cat_swflash_is_from_id)
        {
            /* source from id */
            mdi_swflash_close_id();
            cat_swflash_is_open = MMI_FALSE;
        }
        else
        {
            /* source from file */
            mdi_swflash_close_file();
            cat_swflash_is_open = MMI_FALSE;
        }
    }

    cat_swflash_is_open = MMI_FALSE;
    cat_swflash_is_play = MMI_FALSE;
    cat_swflash_is_from_id = MMI_FALSE;
    cat_swflash_layer = GDI_ERROR_HANDLE;
    cat_swflash_play_finish_callback = NULL;
    cat_swflash_play_ret = 0;

    /* let MMI can sleep */
    if (cat_swflash_is_lcd_no_sleep)
    {
        TurnOffBacklight();
    }

    if (cat_swflash_is_audio_on)
    {
        /* resume background audio */
        mdi_audio_resume_background_play();
    }

    if (wgui_is_touch_title_bar_buttons())
    {
        title_bg_id = 0;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        entry_full_screen();
    }

    wgui_reset_touch_title_bar_buttons();

}
#endif
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
#ifdef __MMI_AVATAR__
/*****************************************************************************
 * FUNCTION
 *  ExitCategoryAvatarScreen
 * DESCRIPTION
 *  Exit Category 224 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategoryAvatarScreen(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    /* let MMI can sleep, it's mflash's code, may not use*/
    //if (cat_swflash_is_lcd_no_sleep)
    //{
    //    TurnOffBacklight();
    //}

    cat_swflash_layer = GDI_ERROR_HANDLE;



    if (wgui_is_touch_title_bar_buttons())
    {
        title_bg_id = 0;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        entry_full_screen();
    }

    wgui_reset_touch_title_bar_buttons();

}



/*****************************************************************************
 * FUNCTION
 *  DrawCateSWFlashCategoryControlArea
 * DESCRIPTION
 *  draw vdo contro area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coord
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCateAvatarCategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_width, content_height;
    S32 content_offset_x, content_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        content_width = UI_device_width;
        content_height = UI_device_height;
        content_offset_x = 0;
        content_offset_y = 0;
    }


   /********************************************************************************
   *  Create Video Layer 
   ********************************************************************************/
    if (cat_swflash_layer == GDI_ERROR_HANDLE || cat_swflash_layer == GDI_LAYER_EMPTY_HANDLE)
    {/* the swflash layer maybe already set */
        if (wgui_is_touch_title_bar_buttons())
        {
            dm_create_layer(
                content_offset_x,
                content_offset_y,
                content_width,
                content_height,
                &cat_swflash_layer,
                DM_LAYER_ACTIVE_TOP);
        }
        else
        {
            dm_create_layer(
                content_offset_x,
                content_offset_y,
                content_width,
                content_height,
                &cat_swflash_layer,
                DM_LAYER_ACTIVE_BOTTOM);
        }
    }

    /* clear this layer with black */
    gdi_layer_push_and_set_active(cat_swflash_layer);
    gdi_layer_clear(gdi_layer_get_background());
    #ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
    #endif
    
#ifdef __MMI_ALPHA_BLENDING__
    gdi_image_abm_set_source_layer(cat_swflash_layer);
    	if (g_dm_data.s32CatId == MMI_CATEGORY34_ID)
	{
            gdi_anim_set_blt_before_callback((void (*)(GDI_RESULT))cat33_redraw_alpha_images);
	}
/* 073007 abm dialing Start */
    #if (( defined ( __MMI_MAINLCD_176X220__ ) || defined (__MMI_MAINLCD_240X320__)  || defined (__MMI_MAINLCD_320X240__)) && defined (__GDI_MEMORY_PROFILE_2__) )
    #ifndef __MMI_TOUCH_DIAL_SCREEN__
	else if (g_dm_data.s32CatId == MMI_CATEGORY16_ID)
	{
	    gdi_anim_set_blt_before_callback((void (*)(GDI_RESULT))DrawCate16CategoryBeforeBLTCallback);
	}
    #endif
    #endif
/* 073007 abm dialing End */




#endif /* __MMI_ALPHA_BLENDING__ */

    if (cat34_anim_handle!= GDI_NULL_HANDLE)
    {
        gdi_image_stop_animation(cat34_anim_handle);
        cat34_anim_handle = GDI_NULL_HANDLE;
    }

    if(!mmi_avatar_is_avatar_valid((U32) cat34_avatar_ptr, (U32) cat34_avatar_serial_num))
    {
        cat_avatar_is_valid = FALSE;
    }
    else
    {
        gdi_anim_draw_mem(
                0,
                0,
                (PS8) cat34_avatar_ptr,
                GDI_IMAGE_TYPE_AVATAR,
                0, // NO USE
                &cat34_anim_handle);
        cat_avatar_is_valid = TRUE;
    }
    gdi_layer_pop_and_restore_active();  
}
#endif
/*****************************************************************************
 * FUNCTION
 *  SetSWFlashPlayerLayer
 * DESCRIPTION
 *  set swflash player layer
 * PARAMETERS
 *  layer_handle      [IN]        layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void SetSWFlashPlayerLayer(GDI_HANDLE layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_swflash_layer = layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  GetCat34MediaType
 * DESCRIPTION
 *  Get category34 background media type
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 type of media
 *****************************************************************************/
S32 GetCat34MediaType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_idle_bg_media_type;
}


/*****************************************************************************
 * FUNCTION
 *  SetCat34MediaType
 * DESCRIPTION
 *  Get category34 background media type
 * PARAMETERS
 *  media_type      [IN]        media type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCat34MediaType(S32 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_idle_bg_media_type = media_type;
}


/*****************************************************************************
 * FUNCTION
 *  SetupCat34Media
 * DESCRIPTION
 *  Setup category34 background media type
 * PARAMETERS
 *  bg_media_id             [IN]        New bg media ID
 *  bg_media_filename       [IN]        New bg media filename
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result SetupCat34Media(U16 bg_media_id, S8 *bg_media_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result mfh_ret = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
	if(bg_media_id == 0xFFFF && bg_media_filename == NULL)
    {
        bg_media_id = PhnsetGetCurWallPaperIdx();
        bg_media_filename = idle_screen_wallpaper_name;
    }
#endif

#ifdef __MMI_SWFLASH__
    if (dispchar_iswp_swflash() == MMI_TRUE)
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_SWFLASH;
    }
	else 
#endif /* __MMI_SWFLASH__ */
#ifdef __MMI_AVATAR__
    if (PhnsetGetDisplayType(bg_media_id) == PHNSET_TYPE_DISP_AVATAR)
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_AVATAR;
    }
	else
#endif /* __MMI_AVATAR__ */
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
    }

    if (g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR)
    {

    }
#ifdef __MMI_SWFLASH__
    else if (g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_SWFLASH)
    {
        /********************************************************************************
        *  SWFlash Setting
        ********************************************************************************/
        cat_swflash_is_full_screen = MMI_TRUE;
        cat_swflash_repeat_count = 1;
        ReadValue(NVRAM_SWFLASH_VOLUME, &cat_swflash_audio_volumn, DS_BYTE, &error);
        if (cat_swflash_audio_volumn == 0xff)
        {
            cat_swflash_audio_volumn = 4;
        }           
        cat_swflash_is_audio_on = MMI_FALSE;
        cat_swflash_is_vibrate_on = MMI_FALSE;
        cat_swflash_is_interaction_on = MMI_FALSE;
        cat_swflash_is_lcd_no_sleep = MMI_FALSE;

        /********************************************************************************
        *  Open SWFlash
        ********************************************************************************/
        
        if (bg_media_id != 0)
        {
            cat_swflash_is_from_id = MMI_TRUE;
            /* source from id */
            /* always open with audio, if do not want audio, mute it by calling mdi function */
            mfh_ret = mdi_swflash_open_id(bg_media_id, SWFLASH_SCREEN, &wgui_swflash_info);
            cat_swflash_is_open = (mfh_ret >= 0) ? MMI_TRUE : MMI_FALSE;
        }
        else if (bg_media_filename!= NULL)
        {
            cat_swflash_is_from_id = MMI_FALSE;
            /* source from file */
            /* always open with audio, if do not want audio, dsiable it in play function */
            mfh_ret = mdi_swflash_open_file(bg_media_filename, SWFLASH_SCREEN, &wgui_swflash_info);
            cat_swflash_is_open = (mfh_ret >= 0) ? MMI_TRUE : MMI_FALSE;
        }
        else
        {
         /* no proper source */
         MMI_ASSERT(0);
        }
    }
#endif
    else /* g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_SWFLASH */
    {
        return 0;
    }
    return mfh_ret;
}

/*****************************************************************************
 * FUNCTION
 *  HandleCat34MediaPlayFailed
 * DESCRIPTION
 *  Handle media play error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleCat34MediaPlayFailed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SWFLASH__
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_SWFLASH)
    {
        if (cat_swflash_is_open == MMI_FALSE || cat_swflash_play_ret < 0)
        {
                PhnsetWallpaperBadFileCallBack(0);
                g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
        }
    }
#endif

#ifdef __MMI_AVATAR__
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR)
    {
        if (cat_avatar_is_valid == MMI_FALSE)
        {
                PhnsetWallpaperBadFileCallBack(0);
                g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
        }
    }

#endif

}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory34Screen
 * DESCRIPTION
 *  show category 34
 * PARAMETERS
 *  left_softkey            [IN]    Left softkey label
 *  left_softkey_icon       [IN]    Icon for the Left softkey
 *  right_softkey           [IN]    Right softkey label
 *  right_softkey_icon      [IN]    Icon for the Right softkey
 *  bg_media_id             [IN]    background media ID
 *  bg_media_filename       [IN]    Background media filename
 *  history_buffer          [OUT]   History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory34Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 bg_media_id,
        S8 *bg_media_filename,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SWFLASH__
    if (dispchar_iswp_swflash() == MMI_TRUE)
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_SWFLASH;
    }
	else
#endif /* __MMI_SWFLASH__ */
#ifdef __MMI_AVATAR__
    if(PhnsetGetDisplayType(bg_media_id) == PHNSET_TYPE_DISP_AVATAR)
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_AVATAR;
    }
    else
#endif /* __MMI_AVATAR__ */
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
    }
    /********************************************************************************
    *  IdleScreen
    ********************************************************************************/
    ShowCategory33Screen_ext(
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        history_buffer);

    /********************************************************************************
    *  SWFlash Setting
    ********************************************************************************/
    SetupCat34Media(bg_media_id, bg_media_filename);

    ExitCategoryFunction = ExitCategory34Screen;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    RedrawCategoryFunction = dm_redraw_category_screen;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_IMG )
    {
        dm_data.s32CatId = MMI_CATEGORY33_ID;
        dm_register_category_controlled_callback(NULL);
    }
#ifdef __MMI_AVATAR__
    else if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR  )
    {
        dispchar_get_current_avatar_id(bg_media_id, &(cat34_avatar_ptr), (U32 *)&cat34_avatar_serial_num);

        dm_data.s32CatId = MMI_CATEGORY34_ID;

        //if( mmi_avatar_is_avatar_valid((U32) cat34_avatar_ptr, (U32)cat34_avatar_serial_num) )
        {
            cat_avatar_is_valid = TRUE;
            dm_register_category_controlled_callback(DrawCateAvatarCategoryControlArea);
        }
        //else
        //    cat_avatar_is_valid = FALSE;
    }   
#endif
#ifdef __MMI_SWFLASH__
    else if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_SWFLASH )
    {
        dm_data.s32CatId = MMI_CATEGORY34_ID;
        dm_register_category_controlled_callback(DrawCateSWFlashCategoryControlArea);
    }
#endif
    dm_data.s32flags = 0;
#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    if (mmi_bootup_get_active_flight_mode() == 0)
    {
        dm_data.s32flags |= DM_NO_SOFTKEY;
    }
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */ 
    dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled2_callback(dm_category_33_controlled_area);
    dm_redraw_category_screen();

    HandleCat34MediaPlayFailed();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory34Screen
 * DESCRIPTION
 *  Exit category 34
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory34Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_swflash_layer = GDI_ERROR_HANDLE;
#ifdef __MMI_AVATAR__
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR)
    {
        ExitCategoryAvatarScreen();
    }
#endif

#ifdef __MMI_SWFLASH__
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_SWFLASH )
    {
        ExitCategorySWFlashScreen();
    }
#ifdef __MMI_ALPHA_BLENDING__
    mdi_swflash_register_blt_callback(NULL, NULL);
#endif
#endif /* __MMI_SWFLASH__ */

    ExitCategory33Screen();
}

#endif /* __MMI_SWFLASH__ */ 
/****************************************************************************
*
* MultiMedia Related [SubLCD] Categories
*
*****************************************************************************/

/*****************************************************************************
* [Category331] [SUB]
*
* This category is a empty SubLCD category.
*
*  ****************
*  *              *
*  *              *
*  *              *
*  *              *
*  *              *
*  ****************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory331Screen
 * DESCRIPTION
 *  Enter Category 331 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory331Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    SUBLCD_ExitCategoryFunction();

    hide_status_icon_bar(2);

    SUBLCD_ExitCategoryFunction = ExitCategory331Screen;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory331Screen
 * DESCRIPTION
 *  Exit Category 331 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategory331Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
* [Category332] [SUB]
*
* This category is to draw a image on sublcd
*
*  ****************
*  *              *
*  *              *
*  *  [ Image ]   *
*  *              *
*  *              *
*  ****************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory332Screen
 * DESCRIPTION
 *  Enter Category 332 Screen
 * PARAMETERS
 *  image_id        [IN]        Image id
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory332Screen(MMI_ID_TYPE image_id)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    SUBLCD_ExitCategoryFunction();

    UI_set_sub_LCD_graphics_context();

    hide_status_icon_bar(2);

    gdi_layer_reset_clip();
    gdi_layer_clear(GDI_COLOR_WHITE);

    if (image_id != 0)
    {
        gdi_image_get_dimension_id(image_id, &image_width, &image_height);
        gdi_image_draw_id((UI_device_width - image_width) >> 1, (UI_device_height - image_height) >> 1, image_id);
    }

    gdi_layer_blt_base_layer(0, 0, UI_device_width - 1, UI_device_height - 1);

    SUBLCD_ExitCategoryFunction = ExitCategory332Screen;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    UI_set_main_LCD_graphics_context();
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory332Screen
 * DESCRIPTION
 *  Exit Category 332 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategory332Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
* [Category333] [SUB]
*
* This category is for audio player sub display.
*
*  ****************
*  *              *
*  *              *
*  *  XXXXXXXXX   *
*  *              *
*  *              *
*  ****************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory333Screen
 * DESCRIPTION
 *  Enter Category 333 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory333Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    SUBLCD_ExitCategoryFunction();
    UI_set_sub_LCD_graphics_context();

    gui_lock_double_buffer();

    register_hide_status_icon_bar(2, SUBLCD_screens_hide_status_icons);
    show_status_icon_bar(2);

    gui_unlock_double_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory333Screen;
    SUBLCD_RedrawCategoryFunction = RedrawCategory333Screen;
    SUBLCD_GetCategoryHistory = GetCategory333History;
    SUBLCD_GetCategoryHistorySize = GetCategory333HistorySize;
    RedrawCategory333Screen();
    UI_set_main_LCD_graphics_context();
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory333Screen
 * DESCRIPTION
 *  Exit Category 333 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategory333Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_set_sub_LCD_graphics_context();
    close_status_icons();
#ifdef __MMI_AUDIO_PLAYER__
    mmi_audply_exit_subLCD();
#endif 
#ifdef __MMI_FM_RADIO__
    mmi_fmrdo_exit_subLCD();
#endif 
    gui_hide_animations();

    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    UI_set_main_LCD_graphics_context();
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory333Screen
 * DESCRIPTION
 *  Redraw Category 333 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void RedrawCategory333Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(0, 0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_set_sub_LCD_graphics_context();

    gui_lock_double_buffer();

#ifndef __MMI_SUB_WALLPAPER__
    show_sublcd_status_background(0, 0, (UI_device_width - 1), (UI_device_height - 1), MMI_FALSE);
#endif 
    SUBLCD_screens_show_status_icons();
    gui_draw_horizontal_line(0, UI_device_width - 1, 54, c);
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        mmi_audply_redraw_subLCD(TRUE);
    }
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
        mmi_fmrdo_redraw_subLCD(TRUE);
    }
#endif /* __MMI_FM_RADIO__ */ 

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    UI_set_main_LCD_graphics_context();
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetCategory333HistorySize
 * DESCRIPTION
 *  Get Category 333 History Size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static S32 GetCategory333HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetCategory333History
 * DESCRIPTION
 *  *   Get Category 333 History
 * PARAMETERS
 *  history_buffer      [OUT]     History buffer
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static U8 *GetCategory333History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (history_buffer);
}
#endif /* __MMI_SUBLCD__ */ 


#ifdef __MMI_CAT44X_SUPPORT__

#define CAT441_TOTAL_BUTTON_COUNT 2
#define CAT442_TOTAL_BUTTON_COUNT 4
#define CAT443_TOTAL_BUTTON_COUNT 8

#define CAT440_TEXT_AREA_LINE_SPACE 1
#define CAT440_TEXT_AREA_TEXT_COLOR UI_COLOR_WHITE


#if defined(__MMI_MAINLCD_240X320__)
const S32 panel_button_position_cat441[CAT441_TOTAL_BUTTON_COUNT][4] = 
{
    {76,  266,  47,  25  },
    {123, 266,  48,  25  }
};

const S32 panel_button_position_cat442[CAT442_TOTAL_BUTTON_COUNT][4] = 
{
    {27,  266,  47,  25  },
    {74,  266,  46,  25  },
    {120, 266,  46,  25  },
    {166, 266,  48,  25  }
};

const S32 panel_button_position_cat443[CAT443_TOTAL_BUTTON_COUNT][4] = 
{
    {4,   270,  27,  22  },
    {31,  270,  26,  22  },
    {57,  270,  26,  22  },
    {83,  270,  26,  22  },
    {109, 270,  26,  22  },
    {135, 270,  28,  22  },
    {181, 270,  27,  22  },
    {208, 270,  28,  22  },
};
#else /* defined(__MMI_MAINLCD_240X320__) */
const S32 panel_button_position_cat441[CAT441_TOTAL_BUTTON_COUNT][4] = 
{
    {57,  179,  28,  18  },
    {85,  179,  29,  18  }
};

const S32 panel_button_position_cat442[CAT442_TOTAL_BUTTON_COUNT][4] = 
{
    {40,  179,  23,  18  },
    {63,  179,  22,  18  },
    {85,  179,  22,  18  },
    {107, 179,  24,  18  }
};

const S32 panel_button_position_cat443[CAT443_TOTAL_BUTTON_COUNT][4] = 
{
    {1,   179,  20,  18  },
    {21,  179,  19,  18  },
    {40,  179,  19,  18  },
    {59,  179,  19,  18  },
    {78,  179,  19,  18  },
    {97,  179,  21,  18  },
    {128, 179,  23,  18  },
    {151, 179,  24,  18  },
};
#endif /* defined(__MMI_MAINLCD_240X320__) */

const color tran_color = {0, 0, 255};

static S32 wgui_cat44x_panel_handle;
static color old_inputbox_text_color;
static color new_inputbox_text_color;

static wgui_text_area_struct *wgui_top_text_area_data;
static U16 wgui_cat44x_header_img_id;
static PU8 wgui_cat44x_header_img;
static S32 wgui_cat44x_header_img_length;
static S32 wgui_cat44x_header_img_width;
static MMI_BOOL wgui_cat44x_is_show_info_bar;
static void (*wgui_cat44x_inputbox_header_img_cb)(void);

#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
static MMI_ID_TYPE idle_scr_bg_ID;
static S8 *idle_scr_bg_filename;
static S32 idle_scr_bg_x, idle_scr_bg_y;
static U8 idle_scr_bg_opacity;
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */

static void wgui_cat44x_redraw_percentage(S32 percentage_x, S32 percentage_y, S32 area_width, S32 area_height, S32 percentage);
static void wgui_cat44x_setup_hilite(wgui_hilite_header_inputbox_struct *inputbox_area_data);
static void wgui_cat44x_header_callback(U8 type, S32 x, S32 y);
static void wgui_cat44x_setup_header(wgui_hilite_header_inputbox_struct *inputbox_area_data);
static void wgui_cat44x_reset_header(void);
static void wgui_cat440_redraw_top_area_text(dm_coordinates *coordinate);
static void wgui_redraw_inputbox_header_img(MMI_BOOL is_draw, S32 yy, S32 height, S32 x1, S32 y1, S32 x2, S32 y2);
static S32 wgui_cat440_get_history_size(void);
static U8 *wgui_cat440_get_history(U8 *history_buffer);
static U8 wgui_cat440_set_history(U16 history_ID, U8 *history_buffer, S16 *input_type);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_setup_hilite
 * DESCRIPTION
 *  wgui_cat44x_setup_hilite
 * PARAMETERS
 *  inputbox_area_data      [IN]    inputbox area data pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat44x_setup_hilite(wgui_hilite_header_inputbox_struct *inputbox_area_data)
{
    MMI_multiline_inputbox.hilite_list = inputbox_area_data->hilite_str_list;
    MMI_multiline_inputbox.hilite_str_number = inputbox_area_data->hilite_str_number;
    MMI_multiline_inputbox.current_hilite_idx = 0;
    MMI_multiline_inputbox.hilite_cb = inputbox_area_data->hilite_cb;
}


/*****************************************************************************
 * FUNCTION
*  wgui_cat44x_header_callback
* DESCRIPTION
*  wgui_cat44x_header_callback
* PARAMETERS
*  type      [IN]      area type
*  x         [IN]      pen down x
*  y         [IN]      pen down y
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat44x_header_callback(U8 type, S32 x, S32 y)
{
    if (type == 0 && x < wgui_cat44x_header_img_width && wgui_cat44x_inputbox_header_img_cb != NULL)
    {
        wgui_cat44x_inputbox_header_img_cb();
    }    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_setup_header
 * DESCRIPTION
 *  wgui_cat44x_setup_header
 * PARAMETERS
 *  inputbox_area_data      [IN]    inputbox area data pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat44x_setup_header(wgui_hilite_header_inputbox_struct *inputbox_area_data)
{
    U8 head_image_type = 0;
    S32 img_width = 0, img_height = 0;

    if (inputbox_area_data->header_img != NULL)
    {
        head_image_type = (U8) gdi_image_get_type_from_mem((PS8)(inputbox_area_data->header_img));
        gdi_image_get_dimension_mem(head_image_type, inputbox_area_data->header_img, inputbox_area_data->header_img_length, &img_width, &img_height);
    }
    else
    {
        gdi_image_get_dimension_id(inputbox_area_data->header_img_id, &img_width, &img_height);
    }
    MMI_multiline_inputbox.header_height = img_height;  
    MMI_multiline_inputbox.header_callback = wgui_redraw_inputbox_header_img; 
    MMI_multiline_inputbox.pen_down_control_area_callback = wgui_cat44x_header_callback;
    wgui_cat44x_inputbox_header_img_cb = inputbox_area_data->header_img_cb;
    wgui_cat44x_header_img = inputbox_area_data->header_img;
    wgui_cat44x_header_img_length = inputbox_area_data->header_img_length;
    wgui_cat44x_header_img_width = img_width;
    wgui_cat44x_header_img_id = inputbox_area_data->header_img_id;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_reset_header
 * DESCRIPTION
 *  reset header data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat44x_reset_header(void)
{
    wgui_cat44x_inputbox_header_img_cb = NULL;
    wgui_cat44x_header_img = NULL;
    wgui_cat44x_header_img_length = 0;
    wgui_cat44x_header_img_width = 0;
    wgui_cat44x_header_img_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat440_general_key_handler
 * DESCRIPTION
 *  wgui_cat440_general_key_handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat440_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    gui_panel_struct* panel;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    panel = dm_get_panel(wgui_cat44x_panel_handle);
    gui_panel_general_key_handler(panel, keycode, keytype);
}


/*****************************************************************************
* FUNCTION
*  wgui_cat440_redraw_top_area_text
* DESCRIPTION
*  redraw category440 top area text
* PARAMETERS
*  yy      [IN]        (not used)
*  x1      [IN]        start  x
*  y1      [IN]        start  y
*  x2      [IN]        end  x
*  y2      [IN]        end  y
* RETURNS
*  void
*****************************************************************************/
static void wgui_cat440_redraw_top_area_text(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, text_x, text_y, text_width, text_height;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(
        coordinate->s16X, 
        coordinate->s16Y, 
        coordinate->s16X + coordinate->s16Width - 1, 
        coordinate->s16Y + coordinate->s16Height - 1);   
    
    /* show text area background */
    gui_show_image(coordinate->s16X, coordinate->s16Y, (U8*) wgui_top_text_area_data->area_bg_img);

    /* show text */
    text_y = coordinate->s16Y + CAT440_TEXT_AREA_LINE_SPACE;
    for (i = 0; i<wgui_top_text_area_data->number_of_lines; i++)
    {
        gui_measure_string((UI_string_type) wgui_top_text_area_data->string_list[i], &text_width, &text_height);
        text_x = coordinate->s16X + ((coordinate->s16Width - text_width) >> 1);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(text_x + text_width, text_y);
        }
        else
        {
            gui_move_text_cursor(text_x, text_y);
        }
        gui_set_text_color(CAT440_TEXT_AREA_TEXT_COLOR);
        gui_print_text((UI_string_type) wgui_top_text_area_data->string_list[i]);

        /* Move to next line */
        text_y += (text_height + CAT440_TEXT_AREA_LINE_SPACE);
    }
    
    gui_pop_clip();
}


/*****************************************************************************
* FUNCTION
*  wgui_redraw_inputbox_header_img
* DESCRIPTION
*  redraw category44x inbox header
* PARAMETERS
*  yy      [IN]        (not used)
*  x1      [IN]        start  x
*  y1      [IN]        start  y
*  x2      [IN]        end  x
*  y2      [IN]        end  y
* RETURNS
*  void
*****************************************************************************/
static void wgui_redraw_inputbox_header_img(MMI_BOOL is_draw, S32 yy, S32 height, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_type;
    S32 header_y2;
    S32 img_width = 0, img_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_draw == MMI_FALSE)
    {
        return ;
    }
    
    header_y2 = yy + height - 1;

    gui_push_clip();
    gui_set_clip(x1, y1, x2, header_y2>y2 ? y2 : header_y2);

    if (wgui_cat44x_header_img != NULL)
    {
        /* Use outside buffer image */
        image_type = gdi_image_get_type_from_mem((PS8) wgui_cat44x_header_img);
        gdi_image_get_dimension_mem((U8) image_type, (U8*) wgui_cat44x_header_img, wgui_cat44x_header_img_length, &img_width, &img_height);
        gdi_image_draw_resized_mem(x1, yy, img_width, img_height, (U8*) wgui_cat44x_header_img, (U8)image_type, wgui_cat44x_header_img_length);
    }
    else
    {
        /* Use resource image */
        gdi_image_draw_id(x1, yy, wgui_cat44x_header_img_id);
    }
    gui_pop_clip();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat440_get_history_size
 * DESCRIPTION
 *  Gets the history buffer size of category 440
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
static S32 wgui_cat440_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((sizeof(panel_category_history) + 3) / 4) * 4 + sizeof(multiline_inputbox_category_history));
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat440_get_history
 * DESCRIPTION
 *  Gets the history buffer of category440
 * PARAMETERS
 *  history_buffer     [OUT]        Is the buffer into which the history data is stored
 * RETURNS
 *  return history buffer
 *****************************************************************************/
static U8 *wgui_cat440_get_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_panel_category_history(MMI_CATEGORY440_ID, history_buffer);
    s = sizeof(panel_category_history);
    s = (s + 3) / 4;
    s *= 4;
    get_multiline_inputbox_category_history(MMI_CATEGORY440_ID, (U8*) (history_buffer + s), MMI_current_input_type);
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat440_set_history
 * DESCRIPTION
 *  Set the history buffer of category440
 * PARAMETERS
 *  history_ID          [IN]        Is the ID used by category screens
 *  history_buffer      [IN]        Is the buffer into which the history data is stored
 *  input_type          [IN]        Input type
 * RETURNS
 *  return history buffer
 *****************************************************************************/
static U8 wgui_cat440_set_history(U16 history_ID, U8 *history_buffer, S16 *input_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 s;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h_flag = set_panel_category_history(MMI_CATEGORY440_ID, history_buffer);
    if (!h_flag)
    {
        return h_flag;
    }
    s = sizeof(panel_category_history);
    s = (s + 3) / 4;
    s *= 4;
    h_flag = set_multiline_inputbox_category_history(MMI_CATEGORY440_ID, (U8*)(history_buffer + s), input_type);
    return h_flag;
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory440Screen
 * DESCRIPTION
 *  Exits the category440 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory440Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enable_softkey_background();
    MMI_multiline_inputbox.normal_text_color = old_inputbox_text_color;
    wgui_cat44x_reset_header();    
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory440Screen
 * DESCRIPTION
 *  Displays the category440 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon 
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  top_text_area_data      [IN]        Top text area data
 *  inputbox_area_data      [IN]        Inputbox area data
 *  panel_area_data         [IN]        Panel area data
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory440Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        wgui_text_area_struct *top_text_area_data,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    gui_util_painter_struct bg_painter, disable_painter, off_painter, on_painter, down_painter;
    S32 i, l;
    S16 input_type = 0;
    U8 h_flag;
    dm_coordinates gui_multiline_get_coordinates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    /* Setup title */
    MMI_title_string = (UI_string_type) title;
    MMI_title_icon = title_icon;
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    
    /* Setup softkey  */
    set_left_softkey_label((UI_string_type) left_softkey);
    set_left_softkey_icon(left_softkey_icon);
    set_right_softkey_label((UI_string_type) right_softkey);
    set_right_softkey_icon(right_softkey_icon);
    SetupCategoryKeyHandlers();

    /* top text control area redraw callback */
    wgui_top_text_area_data = top_text_area_data;
    dm_register_category_controlled_callback(wgui_cat440_redraw_top_area_text);
    
    /* Multiline inputbox */
    l = gui_strlen((UI_string_type) inputbox_area_data->buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) inputbox_area_data->buffer,  inputbox_area_data->buffer_size, l, 0);
    register_multiline_inputbox_viewer_keys();
    register_multiline_inputbox_hilite_keys();
    
    wgui_cat44x_setup_hilite(inputbox_area_data);
    wgui_cat44x_setup_header(inputbox_area_data);
    
#ifdef __MMI_TOUCH_SCREEN__
    register_multiline_inputbox_hilite_pen_event_handler();
#endif

    /* Modify inputbox text and background color */
    old_inputbox_text_color = MMI_multiline_inputbox.normal_text_color;
    new_inputbox_text_color = UI_COLOR_BLACK;
    MMI_multiline_inputbox.normal_text_color = new_inputbox_text_color;
    gui_set_multi_line_input_box_default_bg_color(&MMI_multiline_inputbox, UI_COLOR_WHITE, MMI_TRUE);
    
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE | 
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND |
        UI_MULTI_LINE_INPUT_BOX_RICHTEXT);

    if (MMI_multiline_inputbox.hilite_str_number != 0)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }

    /* Panel Background */
    gui_util_painter_create_imageid(&bg_painter, panel_area_data->panel_bg_img_id);

    wgui_cat44x_panel_handle = dm_add_panel(0, 0, UI_device_width, UI_device_height, bg_painter, MMI_FALSE, panel_area_data->repeat_period);

    /* add panel buttons */
    for(i = 0; i < panel_area_data->num_of_element; i++)
    {
        gui_util_painter_create_imageid(&disable_painter, panel_area_data->element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, panel_area_data->element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, panel_area_data->element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, panel_area_data->element_list[i].down_imageid);
        dm_add_panel_element(
            wgui_cat44x_panel_handle,
            panel_area_data->element_list[i].x,
            panel_area_data->element_list[i].y,
            panel_area_data->element_list[i].width,
            panel_area_data->element_list[i].height,
            panel_area_data->element_list[i].keycode,
            panel_area_data->element_list[i].down_event_callback,
            panel_area_data->element_list[i].up_event_callback,
            panel_area_data->element_list[i].repeat_event_callback,
            off_painter,
            on_painter,
            down_painter,
            disable_painter,
            MMI_FALSE);
        dm_set_panel_enable_element(wgui_cat44x_panel_handle, i, panel_area_data->element_list[i].enabled, MMI_FALSE); /* ZN added */
    }

    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY440_ID,
        DM_MULTILINE_INPUTBOX1,
        -1,
        &gui_multiline_get_coordinates);
    resize_multiline_inputbox(
        gui_multiline_get_coordinates.s16Width,
        gui_multiline_get_coordinates.s16Height);

    /* Set category440 history */
    h_flag = wgui_cat440_set_history(MMI_CATEGORY440_ID, history_buffer, &input_type);

    /* check inputbox history */
    if (inputbox_area_data->hilite_str_number != 0)
    {
        if (h_flag)
        {
            gui_multi_line_input_box_go_to_hilite(
                &MMI_multiline_inputbox,
                (U16)MMI_multiline_inputbox.current_hilite_idx,
                MMI_FALSE);
        }
        else
        {
            gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
        }
    }

    /* check panel history */
    if(!h_flag)
    {
        dm_set_panel_element_focus(wgui_cat44x_panel_handle, panel_area_data->focused_element, MMI_FALSE);
    }
    
    dm_register_panel_keys(wgui_cat44x_panel_handle, wgui_cat440_general_key_handler);
    
    gdi_layer_unlock_frame_buffer();
        
#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    ExitCategoryFunction = ExitCategory440Screen;
    dm_setup_category_functions(dm_redraw_category_screen, wgui_cat440_get_history, wgui_cat440_get_history_size);
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY440_ID;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory441Screen
 * DESCRIPTION
 *  Displays the category441 screen for Word king 2 icons
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon 
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  top_text_area_data      [IN]        Top text area data
 *  inputbox_area_data      [IN]        Inputbox area data
 *  panel_area_data         [IN]        Panel area data
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory441Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        wgui_text_area_struct *top_text_area_data,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(CAT441_TOTAL_BUTTON_COUNT == panel_area_data->num_of_element);
    for (i = 0; i< CAT441_TOTAL_BUTTON_COUNT; i++)
    {
        panel_area_data->element_list[i].x = panel_button_position_cat441[i][0];
        panel_area_data->element_list[i].y = panel_button_position_cat441[i][1];
        panel_area_data->element_list[i].width = panel_button_position_cat441[i][2];
        panel_area_data->element_list[i].height = panel_button_position_cat441[i][3];
    }

    ShowCategory440Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        top_text_area_data,
        inputbox_area_data,       
        panel_area_data,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory442Screen
 * DESCRIPTION
 *  Displays the category442 screen for Word king 4 icons
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon 
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  top_text_area_data      [IN]        Top text area data
 *  inputbox_area_data      [IN]        Inputbox area data
 *  panel_area_data         [IN]        Panel area data
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory442Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        wgui_text_area_struct *top_text_area_data,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(CAT442_TOTAL_BUTTON_COUNT == panel_area_data->num_of_element);
    for (i = 0; i< CAT442_TOTAL_BUTTON_COUNT; i++)
    {
        panel_area_data->element_list[i].x = panel_button_position_cat442[i][0];
        panel_area_data->element_list[i].y = panel_button_position_cat442[i][1];
        panel_area_data->element_list[i].width = panel_button_position_cat442[i][2];
        panel_area_data->element_list[i].height = panel_button_position_cat442[i][3];
    }

    ShowCategory440Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        top_text_area_data,
        inputbox_area_data,       
        panel_area_data,
        history_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory445Screen
 * DESCRIPTION
 *  Exits the category445 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory445Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
    dm_set_scr_bg_image_no_draw(
        idle_scr_bg_ID,
        idle_scr_bg_filename,
        idle_scr_bg_x,
        idle_scr_bg_y,
        idle_scr_bg_opacity);
#endif    
    enable_softkey_background();
    MMI_multiline_inputbox.normal_text_color = old_inputbox_text_color;
    wgui_cat44x_reset_header(); 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory445Screen
 * DESCRIPTION
 *  Displays the category445 screen for listening king
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon 
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  bg_img                  [IN]        Screen background image buffer
 *  inputbox_area_data      [IN]        Inputbox area data
 *  display_call_back       [IN]        Control area for application to redraw.
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory445Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        U16 bg_img,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        void (*display_call_back) (dm_coordinates *coordinate),
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S16 input_type = 0;
    U8 h_flag;
    S32 l;
    dm_coordinates gui_multiline_get_coordinates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    /* Setup title */
    dm_add_string((UI_string_type)title, &MMI_default_font, UI_COLOR_WHITE, UI_COLOR_BLACK, NULL);
    UI_UNUSED_PARAMETER(title_icon);
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    
    /* Setup softkey  */
    set_left_softkey_label((UI_string_type) left_softkey);
    set_left_softkey_icon(left_softkey_icon);
    set_right_softkey_label((UI_string_type) right_softkey);
    set_right_softkey_icon(right_softkey_icon);
    SetupCategoryKeyHandlers();
    
    /* background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    dm_get_scr_bg_image(&idle_scr_bg_ID, &idle_scr_bg_filename, &idle_scr_bg_x, &idle_scr_bg_y, &idle_scr_bg_opacity);
    dm_set_scr_bg_image_no_draw((MMI_ID_TYPE) bg_img, NULL, -1, -1, (U8)(current_MMI_theme->bg_opacity_full)); 
#endif
    
    /* Multiline inputbox */
    l = gui_strlen((UI_string_type) inputbox_area_data->buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) inputbox_area_data->buffer,  inputbox_area_data->buffer_size, l, 0);
    register_multiline_inputbox_viewer_keys();
    register_multiline_inputbox_hilite_keys();
    
    wgui_cat44x_setup_hilite(inputbox_area_data);
    wgui_cat44x_setup_header(inputbox_area_data);    
    
#ifdef __MMI_TOUCH_SCREEN__
    register_multiline_inputbox_hilite_pen_event_handler();
#endif
    
    /* Modify inputbox text and background color */
    old_inputbox_text_color = MMI_multiline_inputbox.normal_text_color;
    new_inputbox_text_color = UI_COLOR_WHITE;
    MMI_multiline_inputbox.normal_text_color = new_inputbox_text_color;
    
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE | 
        UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND | 
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR | 
        UI_MULTI_LINE_INPUT_BOX_RICHTEXT);
    
    if (MMI_multiline_inputbox.hilite_str_number != 0)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    
    /* buttom control area redraw callback */
    dm_register_category_controlled_callback(display_call_back);

    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY445_ID,
        DM_MULTILINE_INPUTBOX1,
        -1,
        &gui_multiline_get_coordinates);
    resize_multiline_inputbox(
        gui_multiline_get_coordinates.s16Width,
        gui_multiline_get_coordinates.s16Height);

    /* Set multiline inputbox history */
    h_flag = set_multiline_inputbox_category_history(MMI_CATEGORY445_ID, history_buffer, &input_type);

    /* check inputbox history */
    if (inputbox_area_data->hilite_str_number != 0)
    {
        if (h_flag)
        {
            gui_multi_line_input_box_go_to_hilite(
                &MMI_multiline_inputbox,
                (U16)MMI_multiline_inputbox.current_hilite_idx,
                MMI_TRUE);
        }
        else
        {
            gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
        }
    }
   
    gdi_layer_unlock_frame_buffer();
        
#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    ExitCategoryFunction = ExitCategory445Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY445_ID;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_reg_control_area_pen_handlers
 * DESCRIPTION
 *  Register pen event handlers for category control areas in category44x
 * PARAMETERS
 *  ctrl_area_idx       [IN]        
 *  pen_hdlr            [IN]        
 *  event_type          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat44x_reg_control_area_pen_handlers(mmi_pen_handler pen_hdlr, mmi_pen_event_type_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_category_screen_control_area_pen_handlers(pen_hdlr, event_type);
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_cat445_update_inputbox_data
 * DESCRIPTION
 *  update the category445 screen data
 * PARAMETERS
 *  inputbox_area_data      [IN]        Inputbox area data
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat44x_update_inputbox_data(wgui_hilite_header_inputbox_struct *inputbox_area_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    l = gui_strlen((UI_string_type) inputbox_area_data->buffer);
    gui_create_multi_line_input_box_set_buffer(
        &MMI_multiline_inputbox,
        MMI_multiline_inputbox.x,
        MMI_multiline_inputbox.y,
        MMI_multiline_inputbox.width,
        MMI_multiline_inputbox.height,
        (UI_string_type) inputbox_area_data->buffer,
        inputbox_area_data->buffer_size * 2,
        (l + 1) * 2,
        0);

    /* Multiline inputbox */
    wgui_cat44x_setup_hilite(inputbox_area_data);
    wgui_cat44x_setup_header(inputbox_area_data);    
    
    MMI_multiline_inputbox.normal_text_color = new_inputbox_text_color;
    gui_set_multi_line_input_box_default_bg_color(&MMI_multiline_inputbox, UI_COLOR_WHITE, MMI_TRUE);

    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
        UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND | 
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR |
        UI_MULTI_LINE_INPUT_BOX_RICHTEXT);
    
    if (MMI_multiline_inputbox.hilite_str_number != 0)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
        
    /* check inputbox history */
    if (inputbox_area_data->hilite_str_number != 0)
    {
        gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
    }
    show_multiline_inputbox_no_draw();
    wgui_show_inputbox();
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_blt_previous(0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_enable_panel_element
 * DESCRIPTION
 *  Enable/Disable panel element
 * PARAMETERS
 *  elem_idx            [IN]            Element index
 *  enabled             [IN]            Is enable
 *  update_display      [IN]            Is redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat44x_enable_panel_element(S32 elem_idx, MMI_BOOL enabled, MMI_BOOL update_display)
{
    dm_set_panel_enable_element(wgui_cat44x_panel_handle, elem_idx, enabled, update_display);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_get_panel_handle
 * DESCRIPTION
 *  Get panel Handle
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 panel handle
 *****************************************************************************/
S32 wgui_cat44x_get_panel_handle(void)
{
   return wgui_cat44x_panel_handle;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat443_general_key_handler
 * DESCRIPTION
 *  wgui_cat443_general_key_handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat443_general_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keycode, keytype;
    gui_panel_struct* panel;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keycode, &keytype);
    panel = dm_get_panel(wgui_cat44x_panel_handle);
    gui_panel_general_key_handler(panel, keycode, keytype);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory443Screen
 * DESCRIPTION
 *  Exits the category443 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory443Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    enable_softkey_background();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory443Screen
 * DESCRIPTION
 *  Displays the category443 screen for exam king 7 icons
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  bg_image                [IN]        Background image buffer
 *  display_call_back       [IN]        Control area for application to redraw. 
 *  panel_area_data         [IN]        Panel area data
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory443Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        PU8 bg_image,
        void (*display_call_back) (dm_coordinates *coordinate),
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    gui_util_painter_struct bg_painter, disable_painter, off_painter, on_painter, down_painter;
    S32 i;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    /* Setup title */
    MMI_title_string = (UI_string_type) title;
    MMI_title_icon = title_icon;
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    
    /* Setup softkey  */
    set_left_softkey_label((UI_string_type) left_softkey);
    set_left_softkey_icon(left_softkey_icon);
    set_right_softkey_label((UI_string_type) right_softkey);
    set_right_softkey_icon(right_softkey_icon);
    SetupCategoryKeyHandlers();

    dm_add_image(bg_image, NULL, NULL);

    /* App control area redraw callback */
    dm_register_category_controlled_callback(display_call_back);
    
    /* Panel Background */
    gui_util_painter_create_imageid(&bg_painter, panel_area_data->panel_bg_img_id);

    wgui_cat44x_panel_handle = dm_add_panel(0, 0, UI_device_width, UI_device_height, bg_painter, MMI_FALSE, panel_area_data->repeat_period);

    /* add panel buttons */
    for(i = 0; i < panel_area_data->num_of_element; i++)
    {
        panel_area_data->element_list[i].x = panel_button_position_cat443[i][0];
        panel_area_data->element_list[i].y = panel_button_position_cat443[i][1];
        panel_area_data->element_list[i].width = panel_button_position_cat443[i][2];
        panel_area_data->element_list[i].height = panel_button_position_cat443[i][3];

        gui_util_painter_create_imageid(&disable_painter, panel_area_data->element_list[i].disable_imageid);
        gui_util_painter_create_imageid(&off_painter, panel_area_data->element_list[i].off_imageid);
        gui_util_painter_create_imageid(&on_painter, panel_area_data->element_list[i].on_imageid);
        gui_util_painter_create_imageid(&down_painter, panel_area_data->element_list[i].down_imageid);
        dm_add_panel_element(
            wgui_cat44x_panel_handle,
            panel_area_data->element_list[i].x,
            panel_area_data->element_list[i].y,
            panel_area_data->element_list[i].width,
            panel_area_data->element_list[i].height,
            panel_area_data->element_list[i].keycode,
            panel_area_data->element_list[i].down_event_callback,
            panel_area_data->element_list[i].up_event_callback,
            panel_area_data->element_list[i].repeat_event_callback,
            off_painter,
            on_painter,
            down_painter,
            disable_painter,
            MMI_FALSE);
        dm_set_panel_enable_element(wgui_cat44x_panel_handle, i, panel_area_data->element_list[i].enabled, MMI_FALSE); /* ZN added */
    }

    /* Set panel history */
    h_flag = set_panel_category_history(MMI_CATEGORY443_ID, history_buffer);

    /* check panel history */
    if(!h_flag)
    {
        dm_set_panel_element_focus(wgui_cat44x_panel_handle, panel_area_data->focused_element, MMI_FALSE);
    }
    
    dm_register_panel_keys(wgui_cat44x_panel_handle, wgui_cat443_general_key_handler);
    
    gdi_layer_unlock_frame_buffer();
        
#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    ExitCategoryFunction = ExitCategory443Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY443_ID;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory447Screen
 * DESCRIPTION
 *  Exits the category447 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory447Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    enable_softkey_background();
    MMI_multiline_inputbox.normal_text_color = old_inputbox_text_color;
    wgui_cat44x_reset_header(); 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory447Screen
 * DESCRIPTION
 *  Displays the category447 screen for dictionary king search result screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon 
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  inputbox_area_data      [IN]        Inputbox area data
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory447Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        U16 bg_id,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S16 input_type = 0;
    U8 h_flag;
    S32 l;
    dm_coordinates gui_multiline_get_coordinates;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    
    /* Setup title */
    MMI_title_string = (UI_string_type) title;
    MMI_title_icon = title_icon;
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    
    /* Setup softkey  */
    set_left_softkey_label((UI_string_type) left_softkey);
    set_left_softkey_icon(left_softkey_icon);
    set_right_softkey_label((UI_string_type) right_softkey);
    set_right_softkey_icon(right_softkey_icon);
    SetupCategoryKeyHandlers();
    
    /* Multiline inputbox */
    l = gui_strlen((UI_string_type) inputbox_area_data->buffer);
    create_multiline_inputbox_set_buffer((UI_string_type) inputbox_area_data->buffer,  inputbox_area_data->buffer_size, l, 0);
    register_multiline_inputbox_viewer_keys();
    register_multiline_inputbox_hilite_keys();
    
    wgui_cat44x_setup_hilite(inputbox_area_data);
    wgui_cat44x_setup_header(inputbox_area_data);    
    
#ifdef __MMI_TOUCH_SCREEN__
    register_multiline_inputbox_hilite_pen_event_handler();
#endif
    
    /* Modify inputbox text and background color */
    old_inputbox_text_color = MMI_multiline_inputbox.normal_text_color;
    new_inputbox_text_color = UI_COLOR_BLACK;
    MMI_multiline_inputbox.normal_text_color = new_inputbox_text_color;
    gui_set_multi_line_input_box_default_bg_color(&MMI_multiline_inputbox, UI_COLOR_WHITE, MMI_TRUE);
    
    MMI_multiline_inputbox.flags |=
        (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE |
        UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND | 
        UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR |
        UI_MULTI_LINE_INPUT_BOX_RICHTEXT);
    
    if (MMI_multiline_inputbox.hilite_str_number != 0)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
    }
    
    dm_get_control_coordinates_from_category(
        -1,
        MMI_CATEGORY447_ID,
        DM_MULTILINE_INPUTBOX1,
        -1,
        &gui_multiline_get_coordinates);
    resize_multiline_inputbox(
        gui_multiline_get_coordinates.s16Width,
        gui_multiline_get_coordinates.s16Height);
    
    /* Set multiline inputbox history */
    h_flag = set_multiline_inputbox_category_history(MMI_CATEGORY447_ID, history_buffer, &input_type);

    /* check inputbox history */
    if (inputbox_area_data->hilite_str_number != 0)
    {
        if (h_flag)
        {
            gui_multi_line_input_box_go_to_hilite(
                &MMI_multiline_inputbox,
                (U16)MMI_multiline_inputbox.current_hilite_idx,
                MMI_FALSE);
        }
        else
        {
            gui_multi_line_input_box_go_to_hilite(&MMI_multiline_inputbox, 0, MMI_FALSE);
        }
    }
   
    gdi_layer_unlock_frame_buffer();
        
#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

    ExitCategoryFunction = ExitCategory447Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY447_ID;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}


#ifdef __MMI_TOUCH_SCREEN__
static S32 MMI_content_height_prev;
static S32 MMI_content_y_prev;
#endif /* __MMI_TOUCH_SCREEN__ */ 

static U8 old_font_size = 0;
static S8 old_font_style = 0;
static S8 *info_bg_img = NULL;

S32 (*wgui_cat44x_get_percentage)(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat448_redraw_info_bg
 * DESCRIPTION
 *  redraw infobar bg for category 448
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat448_redraw_info_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 infobar_bg_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* redraw info bar background */
    if (info_bg_img != NULL)
    {
#ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            infobar_bg_y = MMI_ROTATED_LCD_HEIGHT - CAT448_INFO_BAR_HEIGHT;
        }
        else
#endif        
        {
            infobar_bg_y = MAIN_LCD_DEVICE_HEIGHT - CAT448_INFO_BAR_HEIGHT;
        }
        gui_show_image(0, infobar_bg_y, (PU8)info_bg_img);
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat448_redraw_control_area
 * DESCRIPTION
 *  redraw function for category 448
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat448_redraw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(
        coordinate->s16X, 
        coordinate->s16Y, 
        coordinate->s16X + coordinate->s16Width - 1, 
        coordinate->s16Y + coordinate->s16Height - 1);   

    redraw_multiline_inputbox();
    if (wgui_cat44x_is_show_info_bar == MMI_TRUE)
    {    
        /* redraw info bar background */
        wgui_cat448_redraw_info_bg();
        set_dt_update_function();      
        wgui_clock_show();
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_redraw_percentage
 * DESCRIPTION
 *  redraw percentage for category 448 & 449
 * PARAMETERS
 *  percentage_x    [IN]     Area x
 *  percentage_y    [IN]     Area y
 *  area_width      [IN]     Area widht
 *  percentage      [IN]     Percentage to redraw
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat44x_redraw_percentage(S32 percentage_x, S32 percentage_y, S32 area_width, S32 area_height, S32 percentage)
{
    S32 user_percentage;
    S32 percentage_width, percentage_height;
    S32 center_align_y;
    U8 buffer[16], tb[16];
    color black = {0,0,0,0};
    color white = {255,255,255,0};

    if (wgui_cat44x_get_percentage != NULL)
    {
        user_percentage = wgui_cat44x_get_percentage();
    }
    else
    {
        user_percentage = percentage;
    }

    sprintf((S8*) tb, "%d%c", user_percentage, '%');
    mmi_asc_to_ucs2((S8*)buffer, (S8*)tb);
    
    gui_set_font(&MMI_small_font);
    gui_measure_string((UI_string_type)buffer, &percentage_width, &percentage_height);
    gui_set_text_color(black);
    gui_set_text_border_color(white);
    center_align_y = percentage_y + ((area_height - percentage_height)>>1);
    gui_push_text_clip();
    gui_set_text_clip(
        percentage_x,
        center_align_y,
        percentage_x + area_width - 1,
        center_align_y + percentage_height);

    if (r2lMMIFlag)
    {
        gui_move_text_cursor(percentage_x + percentage_width, center_align_y + 1);
    }
    else
    {
        gui_move_text_cursor(percentage_x + 1, center_align_y + 1);
    }
    gui_print_bordered_text((UI_string_type)buffer);
    gdi_layer_blt_previous(
        0,
        center_align_y,
        area_width,
        center_align_y + percentage_height);
    gui_pop_text_clip();

}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat448_percentage_change
 * DESCRIPTION
 *  redraw percentage for category 448
 * PARAMETERS
 *  percentage      [IN]     percentage to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat448_percentage_change(S32 percentage)
{
    S32 percentage_x, percentage_y;
    s32 area_width;

    percentage_x = 5;
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        percentage_y = MMI_ROTATED_LCD_HEIGHT - CAT448_INFO_BAR_HEIGHT;
        area_width = MMI_ROTATED_LCD_WIDTH>>1;
    }
    else
#endif
    {
        percentage_y = MAIN_LCD_DEVICE_HEIGHT - CAT448_INFO_BAR_HEIGHT;
        area_width = MAIN_LCD_DEVICE_WIDTH>>1;
    }

    gui_push_clip();
    gui_set_clip(
        percentage_x,
        percentage_y,
        percentage_x + area_width - 1,
        percentage_y + CAT448_INFO_BAR_HEIGHT - 1);
    
    wgui_cat448_redraw_info_bg();
    
    gui_pop_clip();

    wgui_cat44x_redraw_percentage(percentage_x, percentage_y, area_width, CAT448_INFO_BAR_HEIGHT, percentage);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat448_hide_time
 * DESCRIPTION
 *  redraw time bg for category 448
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat448_hide_time(S32 x1, S32 y1, S32 x2, S32 y2)
{
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    wgui_cat448_redraw_info_bg();
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory448Screen
 * DESCRIPTION
 *  Exit category 448 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory448Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat44x_get_percentage = NULL;
    if (wgui_cat44x_is_show_info_bar == MMI_TRUE)
    {
        info_bg_img = NULL;
        close_main_LCD_dt_display();
        wgui_clock_close(CAT448_TIME_ID);
    }
    reset_softkeys();
    reset_multitaps();
    reset_multiline_inputbox();
    leave_full_screen();
    wgui_paging_multiline_inputbox_set_percentage_callback(NULL);
    MMI_multiline_inputbox.previous_shared_bytes = 0;
    MMI_disable_title_shortcut_display = 1;
    wgui_paging_stop_text_scroll();
    wgui_paging_multiline_inputbox_set_stop_scroll_callback(NULL);

#ifdef __MMI_TOUCH_SCREEN__
    MMI_content_height = MMI_content_height_prev;
    MMI_content_y = MMI_content_y_prev;
    mmi_pen_editor_close_input_box();
#endif /* __MMI_TOUCH_SCREEN__ */ 
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
    wgui_cat44x_reset_header(); 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory448Screen
 * DESCRIPTION
 *  Displays the category448 screen for full screen ebook king, support rotated
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  bg_image                [IN]        Background image file name pointer
 *  inputbox_area_data      [IN]        Inputbox area data
 *  readline_call_back      [IN]        read line position callback.
 *  page_info_app           [IN]        Page info
 *  is_show_info_bar        [IN]        Is show info bar
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory448Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S8 *bg_image,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,
        void (*readline_call_back) (UI_buffer_type text, S32 cursor_p, S32 text_length),
        void (*pen_get_word_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length, S32 buffer_pos),
        void (*page_change_need_set_highlight) (UI_buffer_type first_display_text, S32 text_length),
        S32 (*get_percentage)(void),
        gui_page_info_app **page_info_app,
        MMI_BOOL is_show_info_bar,
        S8 * info_bar_bg_img,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    S16 input_type = 0;
    gui_page_info_app *page_info_d = *page_info_app;
    dm_coordinates gui_multiline_get_coordinates;
    S32 time_h = 0, time_w = 0;
    S32 l;
#if defined(__MMI_TOUCH_SCREEN__)
    S32 vk_height = 0;
    mmi_pen_handwriting_area_struct stroke_area;
    const gui_virtual_keyboard_pen_enum disable_backspace_list[] = {GUI_VKBD_PEN_BAKSPACE, GUI_VKBD_PEN_NONE};
    S32 inputbox_y = MMI_title_y + MMI_title_height;
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat44x_get_percentage = get_percentage;
    dm_data.s32flags = 0;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_paging_set_full_screen_flag(TRUE);
#endif
    /* resize for vk */
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
#ifdef __MMI_TOUCH_SCREEN__    
        gui_multiline_get_coordinates.s16X = 0;
        gui_multiline_get_coordinates.s16Y = 0;
        gui_multiline_get_coordinates.s16Width = MMI_ROTATED_LCD_WIDTH;
        gui_multiline_get_coordinates.s16Height = MMI_ROTATED_LCD_HEIGHT - CAT448_INFO_BAR_HEIGHT - vk_height;
        MMI_content_height_prev = MMI_content_height;
        MMI_content_y_prev = MMI_content_y;
        MMI_content_y = 0;
        if (is_show_info_bar == MMI_TRUE)        
        {
            MMI_content_height = MMI_ROTATED_LCD_HEIGHT - CAT448_INFO_BAR_HEIGHT;
        }
        else
        {
            MMI_content_height = MMI_ROTATED_LCD_HEIGHT;
        }
#else /* __MMI_TOUCH_SCREEN__ */ 
        gui_multiline_get_coordinates.s16X = 0;
        gui_multiline_get_coordinates.s16Y = 0;
        gui_multiline_get_coordinates.s16Width = MMI_ROTATED_LCD_WIDTH;
        gui_multiline_get_coordinates.s16Height = MMI_ROTATED_LCD_HEIGHT - CAT448_INFO_BAR_HEIGHT;
#endif /* __MMI_TOUCH_SCREEN__ */     
    }
    else
#endif /* __MMI_SCREEN_ROTATE__ */
    {
#ifdef __MMI_TOUCH_SCREEN__    
        gui_multiline_get_coordinates.s16X = 0;
        gui_multiline_get_coordinates.s16Y = 0;
        gui_multiline_get_coordinates.s16Width = MAIN_LCD_DEVICE_WIDTH;
        gui_multiline_get_coordinates.s16Height = MAIN_LCD_DEVICE_HEIGHT - CAT448_INFO_BAR_HEIGHT - vk_height;
        MMI_content_height_prev = MMI_content_height;
        MMI_content_y_prev = MMI_content_y;
        MMI_content_y = 0;
        if (is_show_info_bar == MMI_TRUE)        
        {
            MMI_content_height = MAIN_LCD_DEVICE_HEIGHT - CAT448_INFO_BAR_HEIGHT;
        }
        else
        {
            MMI_content_height = MAIN_LCD_DEVICE_HEIGHT;
        }
#else /* __MMI_TOUCH_SCREEN__ */ 
        gui_multiline_get_coordinates.s16X = 0;
        gui_multiline_get_coordinates.s16Y = 0;
        gui_multiline_get_coordinates.s16Width = MAIN_LCD_DEVICE_WIDTH;
        gui_multiline_get_coordinates.s16Height = MAIN_LCD_DEVICE_HEIGHT - CAT448_INFO_BAR_HEIGHT;
#endif /* __MMI_TOUCH_SCREEN__ */ 
    }

    if (is_show_info_bar == MMI_FALSE)
    {
        gui_multiline_get_coordinates.s16Height += CAT448_INFO_BAR_HEIGHT;
    }
    else
    {
        info_bg_img = info_bar_bg_img;
    }
    wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);

    if (is_show_info_bar == MMI_TRUE)
    {
        wgui_clock_close_all();
        wgui_clock_create(CAT448_TIME_ID, 0, 0, 0, 0, GUI_CLOCK_TYPE_DIGITAL_TIME);
        wgui_clock_set_time_text_font(CAT448_TIME_ID, &MMI_small_font);
        wgui_clock_measure_time_text(CAT448_TIME_ID, &time_w, &time_h, &MMI_small_font);
        wgui_clock_set_hide_function(CAT448_TIME_ID, wgui_cat448_hide_time);
#ifdef __MMI_SCREEN_ROTATE__
        if (mmi_frm_is_screen_width_height_swapped())
        {
            wgui_clock_move(CAT448_TIME_ID, MMI_ROTATED_LCD_WIDTH - time_w - 10, MMI_ROTATED_LCD_HEIGHT - CAT448_INFO_BAR_HEIGHT + ((CAT448_INFO_BAR_HEIGHT - time_h)>>1));
            wgui_clock_resize(CAT448_TIME_ID, time_w + 5, time_h);
        }
        else
#endif /* __MMI_SCREEN_ROTATE__ */
        {
            wgui_clock_move(CAT448_TIME_ID, MAIN_LCD_DEVICE_WIDTH - time_w - 10, MAIN_LCD_DEVICE_HEIGHT - CAT448_INFO_BAR_HEIGHT + ((CAT448_INFO_BAR_HEIGHT - time_h)>>1));
            wgui_clock_resize(CAT448_TIME_ID, time_w + 5, time_h);
        }

        wgui_paging_multiline_inputbox_set_percentage_callback((void*)wgui_cat448_percentage_change);
    }

    gui_lock_double_buffer();
    entry_full_screen();

    /* Setup title */
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    
    l = gui_strlen((UI_string_type) inputbox_area_data->buffer);
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
    create_multiline_inputbox_set_buffer((UI_string_type) inputbox_area_data->buffer, inputbox_area_data->buffer_size, l, 0);
    
    /* inputbox header */
    wgui_cat44x_setup_header(inputbox_area_data);    
    wgui_cat44x_is_show_info_bar = is_show_info_bar;

    wgui_paging_multiline_inputbox_set_stop_scroll_callback((void*)mmi_langln_bsk_stop_auto_scroll);
    wgui_paging_multiline_set_page(page_info_d->start_id, page_info_d->end_id);
    wgui_paging_multiline_set_font(page_info_d->font_size, page_info_d->font_style);

    wgui_paging_multiline_set_get_page_callback(page_info_d->get_page_cb);                    
    register_multiline_inputbox_viewer_keys();
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
                                    UI_MULTI_LINE_INPUT_BOX_RICHTEXT; 
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;

    dm_add_rectangle(inputbox_area_data->bg_color, DM_RECTANGLE_FILL_COLOR);

    if (bg_image != NULL)
    {
        dm_add_image(NULL, (UI_string_type)bg_image, NULL);
    }
    gui_set_multi_line_input_box_default_bg_color(&MMI_multiline_inputbox, tran_color, MMI_TRUE);

    if (page_info_d->highlight_string == 1)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_SEARCH_WORD;
        wgui_paging_highlight_search_string(page_info_d->jump_offset_from_app, page_info_d->search_str_len);
    }
    else
    {
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE;
        gui_set_multi_line_input_box_underline_color(&MMI_multiline_inputbox, inputbox_area_data->read_line_color);
        MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.text + page_info_d->jump_offset_from_app*ENCODING_LENGTH;
    }

    MMI_multiline_inputbox.displayed_text_callback = page_change_need_set_highlight;
    MMI_multiline_inputbox.locate_cursor_callback = pen_get_word_callback;
    MMI_multiline_inputbox.underline_callback = readline_call_back;

    MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
    show_multiline_inputbox_no_draw();
    wgui_paging_set_scrollbar_range(page_info_d->doc_size);
    wgui_paging_reset_show_percentage_flag();
    MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
    /* Set multiline inputbox history */
    h_flag = set_multiline_inputbox_category_history(MMI_CATEGORY448_ID, history_buffer, &input_type);

    ExitCategoryFunction = ExitCategory448Screen;
    wgui_paging_multiline_set_scroll_info(&page_info_d);
    if(old_font_size != page_info_d->font_size || old_font_style != page_info_d->font_style)
    {
        wgui_paging_multiline_clear_last_percentage();
    }

    old_font_size = page_info_d->font_size;
    old_font_style = page_info_d->font_style;

    if (page_info_d->jump_to_end == 1)
    {
        wgui_paging_jump_to_end();
    }

    MMI_multiline_inputbox.page_offset = 0;

    if (page_info_d->scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON && page_info_d->scroll_speed != 0)
    {
        wgui_paging_start_text_scroll();
    }
    else
    {
        wgui_paging_stop_text_scroll();
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_up_hdlr, MMI_PEN_EVENT_UP);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(wgui_cat448_redraw_control_area);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY448_ID;
    dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND | DM_SET_AS_ABM_LAYER;
#ifdef __MMI_TOUCH_SCREEN__

#endif /* __MMI_TOUCH_SCREEN__ */ 

#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped() && bg_image != NULL)
    {
        dm_data.s32flags |= DM_USER_DEFINE_ROTATE_BG_IMG;
    }
#endif /* __MMI_SCREEN_ROTATE__ */
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

    wgui_paging_multiline_set_percentage(page_info_d->start_id, page_info_d->text_offset);

    SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    if (page_info_d->highlight_string != 1)
    {
        SetKeyHandler(wgui_paging_multiline_inputbox_next_page, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_page, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

    show_multiline_inputbox();
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);    
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat448_redraw_control_area
 * DESCRIPTION
 *  redraw function for category 448
 * PARAMETERS
 *  page_info_app      [IN]     page info struct
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat448_change_highlight(gui_page_info_app **page_info_app)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_page_info_app *page_info_d = *page_info_app;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (page_info_d->highlight_string == 1)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_SEARCH_WORD;
        wgui_paging_highlight_search_string(page_info_d->jump_offset_from_app, page_info_d->search_str_len);
    }
    else
    {
        MMI_multiline_inputbox.flags &= ~UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT;
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat449_redraw_info_bg
 * DESCRIPTION
 *  redraw infobar bg for category 449
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat449_redraw_info_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* redraw info bar background */
    if (info_bg_img != NULL)
    {
        gui_show_image(0, MAIN_LCD_DEVICE_HEIGHT - CAT449_INFO_BAR_HEIGHT - MMI_BUTTON_BAR_HEIGHT, (PU8)info_bg_img);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat449_redraw_control_area
 * DESCRIPTION
 *  redraw function for category 449
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat449_redraw_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(
        coordinate->s16X, 
        coordinate->s16Y, 
        coordinate->s16X + coordinate->s16Width - 1, 
        coordinate->s16Y + coordinate->s16Height - 1);   

    redraw_multiline_inputbox();
    if (wgui_cat44x_is_show_info_bar == MMI_TRUE)
    {   
        wgui_cat449_redraw_info_bg(); 
        set_dt_update_function();        
        wgui_clock_show();
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat449_percentage_change
 * DESCRIPTION
 *  redraw percentage for category 449
 * PARAMETERS
 *  percentage      [IN]     percentage to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat449_percentage_change(S32 percentage)
{
    S32 percentage_x, percentage_y;
    s32 area_width;
    
    percentage_x = 5;
    percentage_y = MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - CAT449_INFO_BAR_HEIGHT - 1;
    area_width = MMI_CONTENT_WIDTH>>1;

    gui_push_clip();
    gui_set_clip(
        percentage_x,
        percentage_y,
        percentage_x + area_width - 1,
        percentage_y + CAT449_INFO_BAR_HEIGHT - 1);
    
    wgui_cat449_redraw_info_bg();
    
    gui_pop_clip();
    
    wgui_cat44x_redraw_percentage(percentage_x, percentage_y, area_width, CAT449_INFO_BAR_HEIGHT, percentage);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat449_hide_time
 * DESCRIPTION
 *  redraw function for category 449
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat449_hide_time(S32 x1, S32 y1, S32 x2, S32 y2)
{
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    wgui_cat449_redraw_info_bg();
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory449Screen
 * DESCRIPTION
 *  Exit category 449 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory449Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat44x_get_percentage = NULL;
    if (wgui_cat44x_is_show_info_bar == MMI_TRUE)
    {
        info_bg_img = NULL;
        close_main_LCD_dt_display();
        wgui_clock_close(CAT449_TIME_ID);
    }
    reset_softkeys();
    reset_multitaps();
    reset_multiline_inputbox();
    leave_full_screen();
    wgui_paging_multiline_inputbox_set_percentage_callback(NULL);
    MMI_multiline_inputbox.previous_shared_bytes = 0;
    MMI_disable_title_shortcut_display = 1;
    wgui_paging_stop_text_scroll();
    wgui_paging_multiline_inputbox_set_stop_scroll_callback(NULL);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_editor_close_input_box();
#endif /* __MMI_TOUCH_SCREEN__ */ 
    MMI_multiline_inputbox.normal_text_color = old_inputbox_text_color;
    MMI_multiline_inputbox.ext_flags &= ~GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;
    wgui_cat44x_reset_header(); 
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory449Screen
 * DESCRIPTION
 *  Displays the category449 screen for full screen ebook king, support rotated
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  bg_image                [IN]        Background image file name pointer
 *  inputbox_area_data      [IN]        Inputbox area data
 *  readline_call_back      [IN]        read line position callback.
 *  page_info_app           [IN]        Page info
 *  is_show_info_bar        [IN]        Is show infobar
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory449Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S8 *bg_image,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,
        void (*readline_call_back) (UI_buffer_type text, S32 cursor_p, S32 text_length),
        void (*pen_get_word_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length, S32 buffer_pos),
        void (*page_change_need_set_highlight) (UI_buffer_type first_display_text, S32 text_length),
        S32 (*get_percentage)(void),
        gui_page_info_app **page_info_app,
        MMI_BOOL is_show_info_bar,
        S8 * info_bar_bg_img,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    S16 input_type = 0;
    gui_page_info_app *page_info_d = *page_info_app;
    dm_coordinates gui_multiline_get_coordinates;
    S32 time_h = 0, time_w = 0;
    S32 l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat44x_get_percentage = get_percentage;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_paging_set_full_screen_flag(TRUE);
#endif

    gui_multiline_get_coordinates.s16X = MMI_content_x;
    gui_multiline_get_coordinates.s16Y = MMI_content_y;
    gui_multiline_get_coordinates.s16Width = MMI_content_width;
    if (is_show_info_bar == MMI_TRUE)
    {
        info_bg_img = info_bar_bg_img;
        gui_multiline_get_coordinates.s16Height = MMI_content_height - CAT449_INFO_BAR_HEIGHT;
    }
    else
    {
        gui_multiline_get_coordinates.s16Height = MMI_content_height;
    }
    wgui_dm_set_multiline_data(&gui_multiline_get_coordinates);

    if (is_show_info_bar == MMI_TRUE)
    {
        wgui_clock_close_all();
        wgui_clock_create(CAT449_TIME_ID, 0, 0, 0, 0, GUI_CLOCK_TYPE_DIGITAL_TIME);
        wgui_clock_set_time_text_font(CAT449_TIME_ID, &MMI_small_font);
        wgui_clock_measure_time_text(CAT449_TIME_ID, &time_w, &time_h, &MMI_small_font);
        wgui_clock_set_hide_function(CAT449_TIME_ID, wgui_cat449_hide_time);
        wgui_clock_move(CAT449_TIME_ID, MMI_CONTENT_WIDTH - time_w - 10, MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - CAT449_INFO_BAR_HEIGHT + ((CAT449_INFO_BAR_HEIGHT - time_h)>>1) );
        wgui_clock_resize(CAT449_TIME_ID, time_w + 5, time_h);

        wgui_paging_multiline_inputbox_set_percentage_callback((void*)wgui_cat449_percentage_change);
    }

    gui_lock_double_buffer();
 
    /* Setup title */
    MMI_title_string = (UI_string_type) title;
    MMI_title_icon = title_icon;
    MMI_menu_shortcut_number = -1;
    MMI_disable_title_shortcut_display = 1;
    
    /* Setup softkey  */
    set_left_softkey_label((UI_string_type) left_softkey);
    set_left_softkey_icon(left_softkey_icon);
    set_right_softkey_label((UI_string_type) right_softkey);
    set_right_softkey_icon(right_softkey_icon);
    SetupCategoryKeyHandlers();

    l = gui_strlen((UI_string_type) inputbox_area_data->buffer);
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
    create_multiline_inputbox_set_buffer((UI_string_type) inputbox_area_data->buffer, inputbox_area_data->buffer_size, l, 0);
    
    /* inputbox header */
    wgui_cat44x_setup_header(inputbox_area_data);    
    wgui_cat44x_is_show_info_bar = is_show_info_bar;

    wgui_paging_multiline_inputbox_set_stop_scroll_callback((void*)mmi_langln_bsk_stop_auto_scroll);
    wgui_paging_multiline_set_page(page_info_d->start_id, page_info_d->end_id);
    wgui_paging_multiline_set_font(page_info_d->font_size, page_info_d->font_style);

    wgui_paging_multiline_set_get_page_callback(page_info_d->get_page_cb);                    
    register_multiline_inputbox_viewer_keys();
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
                                    UI_MULTI_LINE_INPUT_BOX_RICHTEXT;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_VIEW_PAGING_MODE;

    /* Modify inputbox text and background color */
    old_inputbox_text_color = MMI_multiline_inputbox.normal_text_color;
    new_inputbox_text_color = UI_COLOR_BLACK;
    MMI_multiline_inputbox.normal_text_color = new_inputbox_text_color;

    dm_add_rectangle(UI_COLOR_WHITE, DM_RECTANGLE_FILL_COLOR);
    dm_add_rectangle(inputbox_area_data->bg_color, DM_RECTANGLE_FILL_COLOR);

    if (bg_image != NULL)
    {
        dm_add_image(NULL, (UI_string_type)bg_image, NULL);
    }
    gui_set_multi_line_input_box_default_bg_color(&MMI_multiline_inputbox, tran_color, MMI_TRUE);

    if (page_info_d->highlight_string == 1)
    {
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_WORD_HIGHLIGHT | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        wgui_paging_highlight_search_string(page_info_d->jump_offset_from_app, page_info_d->search_str_len);
    }
    else
    {
        MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_UNDERLINE_CURSOR_LINE;
        gui_set_multi_line_input_box_underline_color(&MMI_multiline_inputbox, inputbox_area_data->read_line_color);
        MMI_multiline_inputbox.cursor_p = MMI_multiline_inputbox.text + page_info_d->jump_offset_from_app*ENCODING_LENGTH;
    }

    MMI_multiline_inputbox.displayed_text_callback = page_change_need_set_highlight;
    MMI_multiline_inputbox.locate_cursor_callback = pen_get_word_callback;
    MMI_multiline_inputbox.underline_callback = readline_call_back;

    MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
    show_multiline_inputbox_no_draw();
    wgui_paging_set_scrollbar_range(page_info_d->doc_size);
    wgui_paging_reset_show_percentage_flag();
    MMI_multiline_inputbox.page_offset = page_info_d->text_offset;
    /* Set multiline inputbox history */
    h_flag = set_multiline_inputbox_category_history(MMI_CATEGORY449_ID, history_buffer, &input_type);

    ExitCategoryFunction = ExitCategory449Screen;
    wgui_paging_multiline_set_scroll_info(&page_info_d);
    if(old_font_size != page_info_d->font_size || old_font_style != page_info_d->font_style)
    {
        wgui_paging_multiline_clear_last_percentage();
    }

    old_font_size = page_info_d->font_size;
    old_font_style = page_info_d->font_style;

    if (page_info_d->jump_to_end == 1)
    {
        wgui_paging_jump_to_end();
    }

    MMI_multiline_inputbox.page_offset = 0;

    if (page_info_d->scroll_flag == WGUI_PAGING_AUTO_SCROLL_ON && page_info_d->scroll_speed != 0)
    {
        wgui_paging_start_text_scroll();
    }
    else
    {
        wgui_paging_stop_text_scroll();
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_paging_pen_up_hdlr, MMI_PEN_EVENT_UP);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(wgui_cat449_redraw_control_area);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY449_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND|DM_SET_AS_ABM_LAYER;

    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

    wgui_paging_multiline_set_percentage(page_info_d->start_id, page_info_d->text_offset);

    SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_paging_multiline_inputbox_previous_line_in_paging, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_paging_multiline_inputbox_next_line_in_paging_scroll, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    if (page_info_d->highlight_string != 1)
    {
        SetKeyHandler(wgui_paging_multiline_inputbox_next_page, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(wgui_paging_multiline_inputbox_previous_page, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    }

    show_multiline_inputbox();
    
    gui_unlock_double_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


#endif /* __MMI_CAT44X_SUPPORT__ */


