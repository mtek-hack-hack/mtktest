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
 *   VdoPlyApp.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Player Applcation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_VIDEO_PLAYER__



#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */

/* compile option combination testing */
/******************************************************/
//#undef __VDOPLY_FEATURE_FULLSCREEN__
//#undef __VDOPLY_FEATURE_SPEED__
//#undef __VDOPLY_FEATURE_SNAPSHOT__
//#undef __VDOPLY_FEATURE_TOUCH_SCREEN__
//#undef __MMI_VIDEO_STREAM__
//#undef __MMI_VIDEO_PDL__
//#undef __MMI_BT_MTK_SUPPORT__ 
//#undef __MMI_TVOUT__

//#define __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
//#define __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__
/*****************************************************/

#include "gui.h"                /* Gui functions */
#include "gpioInc.h"            /* LED */
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "MainMenuDef.h"        /* Multi-media icon */
#include "Conversions.h"        /* char set conversion */
#include "PhoneSetupGprots.h"   /* PhnsetGetDefEncodingType() */
#include "CallManagementGProt.h"/* CM */


#include "med_api.h"            /* media task */
#include "med_main.h"           /* media task */

#include "lcd_sw_rnd.h"
#include "lcd_if.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"          /* audio lib */
#include "mdi_video.h"          /* video lib */
#include "mdi_camera.h"         /* camera lib */
#include "CameraApp.h"

#include "SettingProfile.h"     /* warning tone */
#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "USBDeviceGprot.h"     /* USB MS mode */
#include "DataAccountGprot.h"

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#include "resource_video_skins.h"       /* UI custom config */
#include "VdoRecResDef.h"
#include "VdoPlyResDef.h"
#include "VdoRecApp.h"
#include "VdoRecGProt.h"
#include "VdoPlyApp.h"
#include "VdoPlyGProt.h"

#include "ImageViewer.h"

#include "wgui_status_icons.h"  /* status UI */
#include "rtc_sw.h"
#include "app_mine.h"           /* mine type */
#include "custom_data_account.h"

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"             /* mdi tvout */
#include "WallpaperDefs.h"      /* some header for phonsetup.h */
#include "DownloadDefs.h"       /* some header for phonsetup.h */
#include "PhoneSetup.h"         /* tvout display style */
#endif /* __MMI_TVOUT__ */ 

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif /* __DRM_SUPPORT__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
#include "SimDetectionGprot.h"
#include "BTMMIScrGprots.h"
#include "av_bt.h"
#include "app_str.h"
#include "AudioPlayerProt.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)
#include "BTMMICM.h"
#include "BTMMIAVRCPGProt.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_AVRCP_SUPPORT__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_FTS_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIFtpGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_FTS_SUPPORT__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_OPP_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIOppGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_OPP_SUPPORT__ */ 

#ifdef MMS_SUPPORT
#include "wapadp.h"
#endif
#ifdef __SF_MP4_SUPPORT__ 
#define lcd_power_up()  lcd_power_ctrl(KAL_TRUE)
#define lcd_power_down() lcd_power_ctrl(KAL_FALSE)
extern kal_bool vdo_sfmp4_is_active(void);
#endif //__SF_MP4_SUPPORT__

/***************************************************************************** 
* Define
*****************************************************************************/
#define VDOPLY_OSD_FADE_OUT_TIME       (3*1000) /* 3 sec */
#define VDOPLY_OSD_FADE_OUT_VALUE      (32)     /* fade 32/256 */


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    VDOPLY_PLAY_FROM_FILE = 0,
    VDOPLY_PLAY_FROM_ID,
    VDOPLY_PLAY_FROM_STREAMING_RTSP,
    VDOPLY_PLAY_FROM_STREAMING_RAM,    
    VDOPLY_PLAY_FROM_STREAMING_SDP,  
    VDOPLY_PLAY_FROM_PROGRESSIVE_DL   
} vdoply_play_src_enum;

typedef enum
{
    VDOPLY_ADJ_BRIGHTNESS,
    VDOPLY_ADJ_CONTRAST,
    VDOPLY_ADJ_REPEAT,

    /* count */
    VDOPLY_ADJ_TOTAL
} vdoply_adjust_item_enum;

typedef enum
{
    VDOPLY_REPEAT_OFF,
    VDOPLY_REPEAT_ON,

    /* count */
    VDOPLY_REPEAT_TOTAL
} vdoply_repeat_type_enum;

typedef enum
{
    VDOPLY_VOL_1 = LEVEL1,
    VDOPLY_VOL_2,
    VDOPLY_VOL_3,
    VDOPLY_VOL_4,
    VDOPLY_VOL_5,
    VDOPLY_VOL_6,
    VDOPLY_VOL_7,
    VDOPLY_VOL_8,
    VDOPLY_VOL_9,
    VDOPLY_VOL_10,
    VDOPLY_VOL_11,
    VDOPLY_VOL_12,
    VDOPLY_VOL_13,    
    VDOPLY_VOL_14,
    VDOPLY_VOL_15,
    VDOPLY_VOL_16,
    VDOPLY_VOL_MUTE
} vdoply_aud_vol_enum;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern BOOL r2lMMIFlag;

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern kal_uint8 GpioCtrlReq(kal_uint8 action);
extern void AudioStopReq(U16 soundId);
extern U16 GetCurKeypadTone(void);
extern void refresh_status_icon_display(void);  /* in Wgui_status_icons.c */

#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
extern mmi_bt_dev_struct *mmi_audply_get_bt_headset(void); /* tmp use audio player's */
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
vdoply_context_struct g_vdoply_cntx;
vdoply_context_struct *const mmi_vdoply_cntx_p = &g_vdoply_cntx;


/***************************************************************************** 
* Local Function
*****************************************************************************/
static MMI_BOOL mmi_vdoply_is_output_to_bt(void);

/* video player screen */
static void mmi_vdoply_blt_screen(void);
static void mmi_vdoply_null_key_event(void);
static void mmi_vdoply_disply_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id);
static BOOL mmi_vdoply_check_and_display_error_popup(MDI_RESULT result);
static U16  mmi_vdoply_get_speed_image(void);
static void mmi_vdoply_highlight_play(void);
static U8   mmi_vdoply_del_screen_hdlr(void *ptr);
static void mmi_vdoply_entry_player_screen_internal(void);
static void mmi_vdoply_draw_opening_anim(void);
static void mmi_vdoply_clear_opening_anim(void);
static void mmi_vdoply_draw_snapshoting(void);
static void mmi_vdoply_clear_snapshoting(void);
static void mmi_vdoply_draw_aud_only_anim(void);
static void mmi_vdoply_clear_aud_only_anim(void);
static void mmi_vdoply_draw_play_region_bg(void);
#ifdef __MMI_VIDEO_STREAM__
static void mmi_vdoply_draw_loading(S32 percentage, MMI_BOOL draw_bg);
static void mmi_vdoply_draw_connecting_anim(void);
static void mmi_vdoply_clear_connecting_anim(void);
#endif /* __MMI_VIDEO_STREAM__ */
static void mmi_vdoply_draw_bg(void);
static void mmi_vdoply_draw_title(void);
static void mmi_vdoply_draw_panel_state(void);
static void mmi_vdoply_draw_panel_progress(void);
static void mmi_vdoply_draw_panel_timer(void);
static void mmi_vdoply_draw_panel_speed(void);
static void mmi_vdoply_draw_panel_volume(void);
static void mmi_vdoply_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, video_style_text_struct *style_txt);
static void mmi_vdoply_draw_softkey(void);
static void mmi_vdoply_draw_panel(void);
static void mmi_vdoply_init_ui(void);
static void mmi_vdoply_calc_progress_ratio(void);

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_draw_fullscr_panel_progress(void);
static void mmi_vdoply_draw_fullscr_panel_timer(void);
static void mmi_vdoply_draw_fullscr_panel_speed(void);
static void mmi_vdoply_draw_fullscr_panel_volume(void);
static void mmi_vdoply_draw_fullscr_softkey(void);
static void mmi_vdoply_draw_fullscr_osd(void);
static void mmi_vdoply_clear_fullscr_osd(void);
static void mmi_vdoply_draw_fullscr_aud_only_anim(void);
static void mmi_vdoply_clear_fullscr_aud_only_anim(void);
static void mmi_vdoply_draw_fullscr_play_region_bg(void);
static void mmi_vdoply_init_fullscr_ui(void);
static void mmi_vdoply_fullscr_reset_osd_fade(BOOL sleep);
static void mmi_vdoply_fullscr_osd_fade_cyclic(void);
static void mmi_vdoply_fullscr_osd_show_up(void);
static U16 mmi_vdoply_fullscr_get_speed_image(void);
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

static MDI_RESULT mmi_vdoply_play_video(void);
static void mmi_vdoply_stop_video(void);

#ifdef __VDOPLY_FEATURE_SNAPSHOT__
static void mmi_vdoply_player_snapshot(void);
static void mmi_vdoply_player_snapshot_key_press(void);
static void mmi_vdoply_player_snapshot_key_release(void);
#endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 

static void mmi_vdoply_player_timer_cyclic(void);
static void mmi_vdoply_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id);
static void mmi_vdoply_lsk_release(void);
static void mmi_vdoply_rsk_release(void);
static void mmi_vdoply_lsk_press(void);
static void mmi_vdoply_rsk_press(void);
static void mmi_vdoply_ck_press(void);
static void mmi_vdoply_ck_release(void);

#ifdef __VDOPLY_FEATURE_VOLUME__
static void mmi_vdoply_vol_up_key_press(void);
static void mmi_vdoply_vol_up_key_release(void);
static void mmi_vdoply_vol_down_key_press(void);
static void mmi_vdoply_vol_down_key_release(void);
#endif /* __VDOPLY_FEATURE_VOLUME__ */ 

#ifdef __VDOPLY_FEATURE_SPEED__
static void mmi_vdoply_speed_inc_key_press(void);
static void mmi_vdoply_speed_inc_key_release(void);
static void mmi_vdoply_speed_dec_key_press(void);
static void mmi_vdoply_speed_dec_key_release(void);
#endif /* __VDOPLY_FEATURE_SPEED__ */ 

static void mmi_vdoply_seek_result_hdlr(MDI_RESULT result);
static void mmi_vdoply_seek_key_release(void);
static BOOL mmi_vdoply_seek_foward(void);
static void mmi_vdoply_seek_foward_key_press_cyclic(void);
static void mmi_vdoply_seek_foward_key_press(void);
static void mmi_vdoply_seek_foward_key_release(void);
static BOOL mmi_vdoply_seek_backward(void);
static void mmi_vdoply_seek_backward_key_press_cyclic(void);
static void mmi_vdoply_seek_backward_key_press(void);
static void mmi_vdoply_seek_backward_key_release(void);

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_toggle_fullscreen_display(void);
static void mmi_vdoply_toggle_fullscreen_key_press(void);
static void mmi_vdoply_toggle_fullscreen_key_release(void);
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

#ifdef __MMI_TVOUT__
static void mmi_vdoply_toggle_tvout_display(void);
static void mmi_vdoply_toggle_tvout_key_press(void);
static void mmi_vdoply_toggle_tvout_key_release(void);
#endif /* __MMI_TVOUT__ */ 

static void mmi_vdoply_set_state_key_event(U16 state);
static void mmi_vdoply_enter_general_state(U16 state);
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_enter_fullscr_state(U16 state);
#endif
#ifdef __MMI_VIDEO_STREAM__
static void mmi_vdoply_enter_stream_state(U16 state);
#endif
#ifdef __MMI_VIDEO_PDL__
static void mmi_vdoply_enter_progressive_state(U16 state);
#endif
static void mmi_vdoply_enter_state(U16 state);
static void mmi_vdoply_exit_player_screen_internal(void);
static void mmi_vdoply_close_file(void);
static S16 mmi_vdoply_get_speed_factor(void);
static void mmi_vdoply_set_state_softkey(U16 state);
static void mmi_vdoply_set_state_layer_config(U16 state);

#ifdef __MMI_SUBLCD__
static void mmi_vdoply_draw_sublcd_icon(void);
static void mmi_vdoply_entry_sublcd_screen(void);
static void mmi_vdoply_exit_sublcd_screen(void);
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_vdoply_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event);
#endif 

void mmi_vdoply_player_play_finish_hdlr(MDI_RESULT result);
void mmi_vdoply_player_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip);

/* player list */
static void mmi_vdoply_highlight_app(void);
void mmi_vdoply_exit_from_fmgr(void *filename, int is_short);
void mmi_vdoply_exit_from_fmgr_emptry_folder(void);

/* re-enter */
static void mmi_vdoply_re_entry_player_screen_from_file(void);
static void mmi_vdoply_re_entry_player_screen_from_id(void);

/* storage */
static void mmi_vdoply_hint_set_storage(U16 index);
static void mmi_vdoply_highlight_set_storage(void);
static void mmi_vdoply_get_drive_callback(S8 drv_letter);
static void mmi_vdoply_entry_set_storage_screen(void);      /* option -> storage */
static void mmi_vdoply_entry_set_app_storage_screen(void);  /* app -> storage */
static void mmi_vdoply_entry_set_storage_screen_internal(void);

#ifdef __SF_MP4_SUPPORT__ 

/*
* snowfish service extension for vdoply application
*/

typedef struct _mmi_vdoply_touch_area
{
    S16 x;
    S16 y;
    S16 width;
    S16 height;
    U8 is_active;
    U8 is_pressed;
    void* param;
    void (*callback)(struct _mmi_vdoply_touch_area* a);
} mmi_vdoply_touch_area;

typedef struct _mmi_vdoply_upd
{
    U16 iTime;
    U8 bIsActive;
    U8 bActiveLink;
    U8 bPlayed;
    U8* iLinkText;

    mmi_vdoply_touch_area* iAreaList;
    U16 iAreaCount;
    mmi_vdoply_touch_area* iActiveArea;
    
} mmi_vdoply_upd;

static mmi_vdoply_upd appex;

#define SFVDOPLYAPP_TIMER_INTERVAL  200

mmi_vdoply_upd* mmi_vdoply_upd_get_context(void) { return &appex; }
void mmi_vdoply_upd_enter(void);
void mmi_vdoply_upd_redraw(void);
void mmi_vdoply_upd_callback(mmi_vdoply_touch_area* param);
void mmi_vdoply_upd_callback_t(void);
void mmi_vdoply_upd_update_all(void);
void mmi_vdoply_upd_activate(void);
void mmi_vdoply_upd_deactivate(void);
mmi_vdoply_touch_area* mmi_vdoply_upd_ta_from_position(int x,int y);

#if defined(__MMI_TOUCH_SCREEN__)
int mmi_vdoply_upd_on_pen_down(int x,int y);
int mmi_vdoply_upd_on_pen_move(int x,int y);
int mmi_vdoply_upd_on_pen_up(int x,int y);
#endif //defined(__MMI_TOUCH_SCREEN__)


enum
{
    AREA_LINK=0
};
static mmi_vdoply_touch_area area_list[]=
{
    {64,64,64,32,1,0,NULL,NULL}
};

#endif //__SF_MP4_SUPPORT__
/* bluetooth */
#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)    
static void mmi_vdoply_highlight_bluetooth_setting(void);
#endif

#if defined(__VDOPLY_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdoply_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vdoply_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vdoply_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_vdoply_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdoply_ui_touch_struct *touch_obj);
#endif /* defined(__VDOPLY_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */

#if defined(__VDOPLY_FEATURE_LSK_OPTION__)
static void mmi_vdoply_entry_adjust_option_scr(void);
static void mmi_vdoply_exit_adjust_option_scr(void);
static void mmi_vdoply_adjust_option_lsk_hdlr(void);
static void mmi_vdoply_adjust_option_highlight_hdlr(S32 index);
#endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 

#ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__
static void mmi_vdoply_entry_option_scr(void);
static void mmi_vdoply_highlight_video_setting(void);
#endif /* __VDOPLY_FEATURE_ENHNACE_OPTION__ */

#if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)				
static void mmi_vdoply_highlight_url_input_method(void);
static void mmi_vdoply_highlight_network(void);
static void mmi_vdoply_highlight_data_account(void);
static void mmi_vdoply_highlight_proxy(void);
static void mmi_vdoply_highlight_udp_port(void);
static void mmi_vdoply_highlight_streaming_url(void);
static void mmi_vdoply_highlight_predefined_url(void);
static void mmi_vdoply_highlight_history_url(void);
static void mmi_vdoply_highlight_history_play(void);
static void mmi_vdoply_highlight_history_remove(void);
static void mmi_vdoply_highlight_input_url(void);
static void mmi_vdoply_highlight_save_connection(void);
static void mmi_vdoply_highlight_stream_editor_done(void);
static void mmi_vdoply_highlight_stream_editor_cancel(void);
static void mmi_vdoply_highlight_stream_input_method(void);
static void mmi_vdoply_check_filename_and_save(void);
static void mmi_vdoply_cancel_stream_editor_and_exit(void);
static void mmi_vdoply_entry_stream_editor_scr(void);
static void mmi_vdoply_entry_stream_editor_option_scr(void);
static void mmi_vdoply_save_stream_file(void);
static void mmi_vdoply_highlight_url_editor_done(void);
static void mmi_vdoply_highlight_url_editor_cancel(void);
static void mmi_vdoply_highlight_url_input_method(void);
static void mmi_vdoply_hint_data_account(U16 index);
static void mmi_vdoply_check_url_and_enter(void);
static void mmi_vdoply_cancel_url_and_exit(void);
static void mmi_vdoply_return_to_editor_screen(void);
static void mmi_vdoply_entry_url_editor_scr(void);
static void mmi_vdoply_entry_url_editor_option_scr(void);
static void mmi_vdoply_entry_network_setting_scr(void);
static void mmi_vdoply_entry_network_setting_scr_internal(void);
static void mmi_vdoply_entry_network_data_account_scr(void);
static void mmi_vdoply_data_account_callback(U16 index);
static void mmi_vdoply_entry_network_proxy_scr(void);
static void mmi_vdoply_exit_network_proxy_scr(void);
static void mmi_vdoply_network_proxy_highlight_hdlr(S32 index);
static void mmi_vdoply_network_proxy_lsk_hdlr(void);
static void mmi_vdoply_entry_network_udp_port_scr(void);
static void mmi_vdoply_exit_network_udp_port_scr(void);
static void mmi_vdoply_network_udp_port_highlight_hdlr(S32 index);
static void mmi_vdoply_network_udp_port_lsk_hdlr(void);
static void mmi_vdoply_ip_addr_callback(U8 *string_buffer, U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4);
static void mmi_vdoply_entry_streaming_url_scr(void);
static void mmi_vdoply_entry_predefined_url_scr(void);
static void mmi_vdoply_predefined_url_lsk_hdlr(void);
static void mmi_vdoply_entry_history_url_scr(void);
static void mmi_vdoply_entry_history_option_scr(void);
static void mmi_vdoply_history_play_url(void);
static void mmi_vdoply_entry_history_remove_confirm_scr(void);
static void mmi_vdoply_history_remove_url(void);
static void mmi_vdoply_history_insert_url(PS8 wurl_p, PS8 name_p); /* in uincode */
static void mmi_vdoply_history_sync_sdp_file(void);
static void mmi_vdoply_url_highlight_hdlr(S32 index);
#endif /* defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */


#ifdef __MMI_VIDEO_STREAM__
static void mmi_vdoply_re_entry_player_screen_from_rtsp_streaming(void);
static void mmi_vdoply_re_entry_player_screen_from_sdp_streaming(void);
static void mmi_vdoply_stream_connect_result_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip);
static void mmi_vdoply_stream_buffering_cyclic(void);
static void mmi_vdoply_stream_buffering_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip);
static void mmi_vdoply_stream_start_buffering(void);
static void mmi_vdoply_stream_stop_buffering(void);
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_stream_fullscr_buffering_cyclic(void);
static void mmi_vdoply_draw_fullscr_loading(S32 percentage, MMI_BOOL draw_bg);
static void mmi_vdoply_draw_fullscr_connecting_anim(void);
static void mmi_vdoply_clear_fullscr_connecting_anim(void);
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
static void mmi_vdoply_rtsp_url_hdlr(void *msg_ptr);
#endif /* __MMMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_PDL__
static void mmi_vdoply_re_entry_player_screen_from_pdl_file(void);
static void mmi_vdoply_entry_pdl_teminate_confirm_scr(void);
static void mmi_vdoply_pdl_teminate_confirm_yes(void);
static void mmi_vdoply_pdl_teminate_confirm_no(void);
static void mmi_vdoply_pdl_draw_progressbar_cyclic(void);
static void mmi_vdoply_pdl_buffering_cyclic(void);
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_pdl_fullscr_buffering_cyclic(void);
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
#ifdef __MMI_DOWNLOAD_AGENT__
static void mmi_vdoply_pdl_da_report_hdlr(S32 session_id, S32 status, S32 cause, U32 seq_num, U32 acc_size);
static BOOL mmi_vdoply_pdl_da_filepath_hdlr(S32 session_id, S32 mime_type, S32 mime_subtype, PU16 filepath);
#endif /* __MMI_DOWNLOAD_AGENT__ */
#endif /* __MMI_VIDEO_PDL__ */

#ifdef __MMI_AVRCP_SUPPORT__
static U8 mmi_vdoply_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event);
#endif

#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
/*****************************************************************************
*
* Bluetooth related usage                                                        
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_bt_connecting
 * DESCRIPTION
 *  draw bt connecting animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_bt_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        mmi_vdoply_set_state_layer_config(VDOPLY_STATE_BT_CONNECTING);
        mmi_vdoply_draw_panel();
        
        if (g_vdoply_cntx.bt_connecting_anim == GDI_NULL_HANDLE)
        {    
            gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
            
            layer_offset_x = g_vdoply_osd_cntx.loading.rect.offset_x;
            layer_offset_y = g_vdoply_osd_cntx.loading.rect.offset_y;    
            
            gdi_layer_set_position(layer_offset_x, layer_offset_y);

            gdi_layer_clear(GDI_COLOR_TRANSPARENT);

            gdi_image_draw_animation_id(
                g_vdoply_osd_cntx.loading.bg.offset_x-layer_offset_x,
                g_vdoply_osd_cntx.loading.bg.offset_y-layer_offset_y,
                IMG_ID_VDOPLY_OSD_BT_CONNECTING,
                &g_vdoply_cntx.bt_connecting_anim);

            gdi_layer_pop_and_restore_active();
        }

    }
    else
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_BT_CONNECTING);

    #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        mmi_vdoply_draw_fullscr_osd();
    #endif
        
        if (g_vdoply_cntx.bt_connecting_anim == GDI_NULL_HANDLE)
        {    
            gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);

            layer_offset_x = g_vdoply_fullscr_osd_cntx.loading.rect.offset_x;
            layer_offset_y = g_vdoply_fullscr_osd_cntx.loading.rect.offset_y;    
            
            gdi_layer_set_position(layer_offset_x, layer_offset_y);
            
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);

            gdi_image_draw_animation_id(
                g_vdoply_fullscr_osd_cntx.loading.bg.offset_x - layer_offset_x,
                g_vdoply_fullscr_osd_cntx.loading.bg.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_OSD_BT_CONNECTING,
                &g_vdoply_cntx.bt_connecting_anim);

            gdi_layer_pop_and_restore_active();
        }
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */    
    }
    
    mmi_vdoply_blt_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_bt_connecting_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_bt_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.bt_connecting_anim != GDI_NULL_HANDLE)
    {    
        gdi_image_stop_animation(g_vdoply_cntx.bt_connecting_anim);
        g_vdoply_cntx.bt_connecting_anim = GDI_NULL_HANDLE;  
        
        gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_bt_headset
 * DESCRIPTION
 *  retrieve the user selected bt headset
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_bt_dev_struct*
 *****************************************************************************/
mmi_bt_dev_struct *mmi_vdoply_get_bt_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    return mmi_audply_get_bt_headset();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_bt_open_callback
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_bt_open_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_BT_OPEN_CALLBACK, result);       
    
    gui_cancel_timer(mmi_vdoply_draw_bt_connecting_anim);
    mmi_vdoply_clear_bt_connecting_anim();
    
    switch (result)
    {
        case AV_BT_CALLBACK_EVENT_OPEN_OK:
            /* 
             *  NOTICE: even after receive EVENT_OPEN_FAILED or EVENT_OPEN_STOPPED,
             *          bt driver may still send EVENT_OPEN_OK, this is due to driver 
             *          has retry mechanism.
             */
            
            if (g_vdoply_cntx.state == VDOPLY_STATE_BT_CONNECTING)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                   
                av_bt_open_codec(KAL_FALSE);                
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }    
            else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_BT_CONNECTING)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                   
                av_bt_open_codec(KAL_FALSE);                
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }            
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BT_CONNECTING)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);   
                av_bt_open_codec(KAL_FALSE);                
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                   
                av_bt_open_codec(KAL_FALSE);                
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING ||
                     g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING)
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                   
                av_bt_open_codec(KAL_FALSE);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY ||
                     g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY ||
                     g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY ||
                     g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
            {
                /* 
                 * since it is already play, we may set TRUE, which will directly
                 * change output to BT 
                 */
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_CODEC, __LINE__);                    
                av_bt_open_codec(KAL_TRUE);
            }            
            break;

        case AV_BT_CALLBACK_EVENT_OPEN_FAILED:
        case AV_BT_CALLBACK_EVENT_OPEN_STOPPED:
            if (g_vdoply_cntx.state == VDOPLY_STATE_BT_CONNECTING)
            {
                 /* connect failed - play the video */
                 mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_BT_CONNECTING)
            {
                 /* connect failed - play the video */
                 mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }            
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BT_CONNECTING)
            {
                 /* connect failed - start buffering */
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING)
            {
                 /* connect failed - start buffering */
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            }
            else
            {
                /* already connected, driver abort */
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);                   
                av_bt_close_codec();
            }
            break;
            
        case AV_BT_CALLBACK_EVENT_OPEN_CANCELED:
            MMI_ASSERT(0);
            break;
            
        case AV_BT_CALLBACK_EVENT_STREAM_ABORT_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case AV_BT_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case AV_BT_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
            /* TODO: display popup to show BT disconnect */
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);   
            av_bt_close_codec();
            break;
        
        case AV_BT_CALLBACK_EVENT_STREAM_START_IND:
        case AV_BT_CALLBACK_EVENT_INQUIRY_START_IND:        
        case AV_BT_CALLBACK_EVENT_INQUIRY_STOP_IND:        
            /* ignore */
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
}


#endif /* __MMI_AUDIO_PLAYER__ && __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_delete_all_from_history
 * DESCRIPTION
 *  Delete all video player related screen from history
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_delete_all_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    for (scr_id = SCR_ID_VDOPLY_PLAYER; scr_id < SCR_ID_VDOPLY_END; scr_id ++)
    {
        DeleteScreenIfPresent(scr_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_is_output_to_bt
 * DESCRIPTION
 *  a callback function invoked by av_bt_open apis
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_vdoply_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_IS_OUTPUT_TO_BT);      
   
#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)


    if (mmi_audply_is_output_to_bt() &&
        (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
         g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY))
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_RET, MMI_TRUE);          
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_RET, MMI_FALSE);           
        return MMI_FALSE;
    }

#else
    return MMI_FALSE;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_connect_bt
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_connect_bt(void)
{
#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)        
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_stereo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CONNECT_BT);     
    
    if (g_vdoply_cntx.state == VDOPLY_STATE_BT_CONNECTING || 
        g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_BT_CONNECTING || 
        g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BT_CONNECTING ||        
        g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING)
    {
        if (mmi_vdoply_is_output_to_bt())
        {
            /* if connecting is not start in 600ms, we will show bt connecting anim */
            gui_start_timer(600, mmi_vdoply_draw_bt_connecting_anim);

            if (g_vdoply_cntx.video_info.aud_channel_no == 2)
            {
                is_stereo = MMI_TRUE;
            }
            else
            {
                is_stereo = MMI_FALSE;
            }

            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_OPEN_EX, __LINE__);  

            av_bt_open_ex(
                mmi_vdoply_get_bt_headset(),
                g_vdoply_cntx.video_info.aud_sample_rate,
                (kal_bool)is_stereo,
                mmi_vdoply_bt_open_callback,
                TRUE);   

            return;
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
#else
    MMI_ASSERT(0);
#endif /* __MMI_AUDIO_PLAYER__ && __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */


}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_disconnect_bt
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_disconnect_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_DISCONNECT_BT);      

    
#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)    
    gui_cancel_timer(mmi_vdoply_draw_bt_connecting_anim);
    mmi_vdoply_clear_bt_connecting_anim();

    if (mmi_vdoply_is_output_to_bt())
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE, __LINE__);             
        av_bt_close(FALSE);
    }

    /* TODO: stop anim */
#endif /* __MMI_AUDIO_PLAYER__ && __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */
 
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_bt_close_codec
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_bt_close_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_BT_CLOSE_CODEC);      
    
#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)    
    if (mmi_vdoply_is_output_to_bt())
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);          
        av_bt_close_codec();
    }
#endif /* __MMI_AUDIO_PLAYER__ && __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */
 
}



/*****************************************************************************
*
* VDOPLY Play                                                        
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_is_in_app
 * DESCRIPTION
 *  is in video player app or not
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_vdoply_is_in_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.state != VDOPLY_STATE_EXIT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_null_key_event
 * DESCRIPTION
 *  empty key event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_null_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_blt_screen
 * DESCRIPTION
 *  blt full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__        
        gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
    #else
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    #endif
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
#if defined(NOKE_DEBUG)
        noke_dbg_printf("\r\n%s:%d",__FILE__,__LINE__);
#endif
        gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_storage_file_path
 * DESCRIPTION
 *  get current active storage disk path
 * PARAMETERS
 *  filepath        [OUT]       Storage file path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoply_load_setting();
    
    sprintf(buf, "%c:\\", (U8)g_vdoply_cntx.storage);
    mmi_asc_to_ucs2(filepath, buf);
    mmi_ucs2cat((PS8)filepath, (PS8)VDOPLY_STORAGE_FILEPATH_PHONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_create_file_dir
 * DESCRIPTION
 *  create file directory-resursivly
 * PARAMETERS
 *  filepath        [IN]        Filepath to be created
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_vdoply_create_file_dir(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[128];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return FS_NO_ERROR;   /* already exist, 0 means successful in file system */
    }

    /* create directory if it is not there */
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    str_len = mmi_ucs2strlen((PS8) buf_filepath);
    str_len *= ENCODING_LENGTH;

    /* skip drive. "C:\" */
    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
    {
        cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */

            mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
            buf_createpath[i] = '\0';
            buf_createpath[i + 1] = '\0';

            fs_ret = FS_CreateDir((PU16) buf_createpath);

            if (fs_ret < 0)
            {
                return fs_ret;
            }
        }
    }

    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_check_and_restore_valid_drv
 * DESCRIPTION
 *  check if current storage path is valid or not.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_vdoply_check_and_restore_valid_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(g_vdoply_cntx.storage ,FS_MOUNT_STATE_ENUM))
    {
        return TRUE;
    }
    else
    {
        g_vdoply_cntx.storage = (U16)MMI_PUBLIC_DRV;
        if (FS_NO_ERROR == FS_GetDevStatus(g_vdoply_cntx.storage ,FS_MOUNT_STATE_ENUM))
        {
            mmi_vdoply_store_setting();
            return TRUE;
        }
        else
        {
        #ifdef __USB_IN_NORMAL_MODE__
            if (mmi_usb_is_in_mass_storage_mode())
            {            
                /* user driver is mass storage mode */
                return FALSE;
            }
            else
            {
                MMI_ASSERT(0);
            }
        #else /* __USB_IN_NORMAL_MODE__ */
            MMI_ASSERT(0);
        #endif /* __USB_IN_NORMAL_MODE__ */
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_storage
 * DESCRIPTION
 *  get storage
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_vdoply_get_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vdoply_cntx.storage;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_set_storage
 * DESCRIPTION
 *  set storage
 * PARAMETERS
 *  storage     [IN]        Storage location enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_set_storage(U16 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.storage = storage;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_load_setting
 * DESCRIPTION
 *  load setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL is_inited_before;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.is_load_setting)
    {
        return;
    }

    is_inited_before = TRUE;

    g_vdoply_cntx.is_load_setting = TRUE;

    /* storage setting */
    ReadValue(NVRAM_VDOPLY_STORAGE, &g_vdoply_cntx.storage, DS_SHORT, &error);

    
    /* init if needed */
    if (g_vdoply_cntx.storage == 0xffff)
    {
        is_inited_before = FALSE;
        g_vdoply_cntx.storage = (U16)MMI_PUBLIC_DRV;
    }

#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n Huyanwei debug (g_vdoply_cntx.storage=%d) \r\n",g_vdoply_cntx.storage);
#endif
    /* brightness setting */
    ReadValue(NVRAM_VDOPLY_OPTION_BRIGHTNESS, &g_vdoply_cntx.brightness, DS_SHORT, &error);

    if (g_vdoply_cntx.brightness == 0xffff)
    {
        g_vdoply_cntx.brightness = MDI_VIDEO_BRIGHTNESS_0;
    }

    /* contrast setting */
    ReadValue(NVRAM_VDOPLY_OPTION_CONTRAST, &g_vdoply_cntx.contrast, DS_SHORT, &error);

    if (g_vdoply_cntx.contrast == 0xffff)
    {
        g_vdoply_cntx.contrast = MDI_VIDEO_CONTRAST_0;
    }

    /* auto repeat setting */
    ReadValue(NVRAM_VDOPLY_OPTION_REPEAT, &g_vdoply_cntx.repeat, DS_SHORT, &error);

    if (g_vdoply_cntx.repeat == 0xffff)
    {
        g_vdoply_cntx.repeat = VDOPLY_REPEAT_OFF;
    }


#if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)
    /* stream */
    ReadValue(NVRAM_VDOPLY_PROXY_PORT, &g_vdoply_cntx.proxy_port, DS_DOUBLE, &error);    
    ReadValue(NVRAM_VDOPLY_DATA_ACCOUNT_ID, &g_vdoply_cntx.data_account_id, DS_BYTE, &error);        
    ReadValue(NVRAM_VDOPLY_PROXY_IP1, &g_vdoply_cntx.proxy_addr[0], DS_BYTE, &error); 
    ReadValue(NVRAM_VDOPLY_PROXY_IP2, &g_vdoply_cntx.proxy_addr[1], DS_BYTE, &error);     
    ReadValue(NVRAM_VDOPLY_PROXY_IP3, &g_vdoply_cntx.proxy_addr[2], DS_BYTE, &error);         
    ReadValue(NVRAM_VDOPLY_PROXY_IP4, &g_vdoply_cntx.proxy_addr[3], DS_BYTE, &error);   
    ReadValue(NVRAM_VDOPLY_PROXY_ON_OFF, &g_vdoply_cntx.proxy_on_off, DS_BYTE, &error);   

    ReadValue(NVRAM_VDOPLY_HIGHEST_UDP_PORT, &g_vdoply_cntx.highest_udp_port, DS_DOUBLE, &error);   
    ReadValue(NVRAM_VDOPLY_LOWEST_UDP_PORT, &g_vdoply_cntx.lowest_udp_port, DS_DOUBLE, &error);   

    if (!is_inited_before)
    {
        /* get a default DA id */        
        g_vdoply_cntx.data_account_id = CUSTOM_DEFAULT_STREAM_DTCNT_ID;
        g_vdoply_cntx.proxy_port = 0;        
        g_vdoply_cntx.proxy_on_off = 0;
        g_vdoply_cntx.proxy_addr[0] = 0;       
        g_vdoply_cntx.proxy_addr[1] = 0;
        g_vdoply_cntx.proxy_addr[2] = 0;
        g_vdoply_cntx.proxy_addr[3] = 0;    

        g_vdoply_cntx.highest_udp_port = 32000;     /* default value */
        g_vdoply_cntx.lowest_udp_port = 6970;       /* default value */
    }
    
#endif /* defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */

    if (!is_inited_before)
    {
        /* first time init, store the init value */
        mmi_vdoply_store_setting();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_store_setting
 * DESCRIPTION
 *  store storage to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_VDOPLY_STORAGE, &g_vdoply_cntx.storage, DS_SHORT, &error);
    WriteValue(NVRAM_VDOPLY_OPTION_BRIGHTNESS, &g_vdoply_cntx.brightness, DS_SHORT, &error);
    WriteValue(NVRAM_VDOPLY_OPTION_CONTRAST, &g_vdoply_cntx.contrast, DS_SHORT, &error);
    WriteValue(NVRAM_VDOPLY_OPTION_REPEAT, &g_vdoply_cntx.repeat, DS_SHORT, &error);

#if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)
    /* stream */
    WriteValue(NVRAM_VDOPLY_PROXY_PORT, &g_vdoply_cntx.proxy_port, DS_DOUBLE, &error);    
    WriteValue(NVRAM_VDOPLY_DATA_ACCOUNT_ID, &g_vdoply_cntx.data_account_id, DS_BYTE, &error);        
    WriteValue(NVRAM_VDOPLY_PROXY_IP1, &g_vdoply_cntx.proxy_addr[0], DS_BYTE, &error); 
    WriteValue(NVRAM_VDOPLY_PROXY_IP2, &g_vdoply_cntx.proxy_addr[1], DS_BYTE, &error);     
    WriteValue(NVRAM_VDOPLY_PROXY_IP3, &g_vdoply_cntx.proxy_addr[2], DS_BYTE, &error);         
    WriteValue(NVRAM_VDOPLY_PROXY_IP4, &g_vdoply_cntx.proxy_addr[3], DS_BYTE, &error);             
    WriteValue(NVRAM_VDOPLY_PROXY_ON_OFF, &g_vdoply_cntx.proxy_on_off, DS_BYTE, &error);     
    WriteValue(NVRAM_VDOPLY_HIGHEST_UDP_PORT, &g_vdoply_cntx.highest_udp_port, DS_DOUBLE, &error);  
    WriteValue(NVRAM_VDOPLY_LOWEST_UDP_PORT, &g_vdoply_cntx.lowest_udp_port, DS_DOUBLE, &error);  
#endif /* defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_disply_popup
 * DESCRIPTION
 *  display popup. will roate if is horizontal screen
 * PARAMETERS
 *  str_ptr             [IN]        String pointer
 *  img_id              [IN]        Image id
 *  image_on_bottom     [IN]        Is image on bottom
 *  tone_duration       [IN]        Tone duration
 *  tone_id             [IN]        Tine id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_disply_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id)
{
#if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopupRotated(
        (PU8) str_ptr,
        (U16) img_id,
        (U8) image_on_bottom,
        (U32) tone_duration,
        (U8) tone_id,
        MMI_FRM_SCREEN_ROTATE_270);
#else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    DisplayPopup((PU8) str_ptr, (U16) img_id, (U8) image_on_bottom, (U32) tone_duration, (U8) tone_id);
#endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_check_and_display_error_popup
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdoply_check_and_display_error_popup(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0) /* error happened */
    {
        switch (result)
        {
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL:
                mmi_vdoply_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL:
                mmi_vdoply_disply_popup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION:
                mmi_vdoply_disply_popup(
                    (PU8) GetString(STR_ID_VDOPLY_NOTIFY_WRITE_PROTECTION),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK:
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED:
                mmi_vdoply_disply_popup(
                    (PU8)GetString(STR_ID_VDOPLY_NOTIFY_SNAPSHOT_FAILED),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

                /* followings are serious error, has to exit app */
            case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
            case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
                mmi_vdoply_disply_popup(
                    (PU8)GetString(STR_GLOBAL_DRM_PROHIBITED),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);                
                break;             
                
            case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
            case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
            case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
            case MDI_RES_VDOPLY_ERR_FAILED:                
                mmi_vdoply_disply_popup(
                    (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;

            default:
                MMI_ASSERT(0);  /* use assert here, make sure all error case is handled properly */
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_speed_image
 * DESCRIPTION
 *  get speed image
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_vdoply_get_speed_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 speed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    speed = mmi_vdoply_get_speed_factor();

#ifndef __VDOPLY_FEATURE_FWD_BWD_SPEED__
    switch (speed)
    {
        case 50:
            return IMG_ID_VDOPLY_OSD_SPEED_50;
            break;

        case 75:
            return IMG_ID_VDOPLY_OSD_SPEED_75;
            break;

        case 100:
            return IMG_ID_VDOPLY_OSD_SPEED_100;
            break;

        case 125:
            return IMG_ID_VDOPLY_OSD_SPEED_125;
            break;

        case 150:
            return IMG_ID_VDOPLY_OSD_SPEED_150;
            break;

        case 200:
            return IMG_ID_VDOPLY_OSD_SPEED_200;
            break;

        case 400:
            return IMG_ID_VDOPLY_OSD_SPEED_400;
            break;

        case 800:
            return IMG_ID_VDOPLY_OSD_SPEED_800;
            break;

        default:
            return IMG_ID_VDOPLY_OSD_SPEED_UNDEF;
            break;

    }
#else /* __VDOPLY_FEATURE_FWD_BWD_SPEED__ */ 
    if (speed > 0)
    {
        return IMG_ID_VDOPLY_OSD_SPEED_FWD;
    }
    else if (speed < 0)
    {
        return IMG_ID_VDOPLY_OSD_SPEED_BWD;
    }
    else
    {
        return IMG_ID_VDOPLY_OSD_SPEED_UNDEF;
    }
#endif /* __VDOPLY_FEATURE_FWD_BWD_SPEED__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_play
 * DESCRIPTION
 *  highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_player_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_player_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_del_screen_hdlr
 * DESCRIPTION
 *  callback function when someone delete this screen's id
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vdoply_del_screen_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_DEL_SCREEN_HDLR);       

#if defined(__MMI_VIDEO_PDL__) 
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
    {
        if (g_vdoply_cntx.is_pdl_debug)
        {
            g_vdoply_cntx.pdl_dl_session_id = -1;     
            g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_EXIT;   
            g_vdoply_cntx.is_pdl_debug = FALSE;
        }

        if(g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_DOWNLOADING)
        {
            MMI_ASSERT(g_vdoply_cntx.pdl_dl_session_id != -1);
            
            /* progressive DL is not finished */
        #ifdef __MMI_DOWNLOAD_AGENT__
            mmi_da_stop_dl(g_vdoply_cntx.pdl_dl_session_id);
        #endif
        }

        g_vdoply_cntx.pdl_dl_session_id = -1;     
        g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_EXIT;           
    }
#endif /* defined(__MMI_VIDEO_PDL__)  */

#if defined(__MMI_VIDEO_STREAM__)
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP && 
        g_vdoply_cntx.is_da_spd_file)
    {
        /* delete DA's tmp SDP file */
        FS_Delete((kal_wchar*)g_vdoply_cntx.source_path);
    }
#endif /* defined(__MMI_VIDEO_STREAM__) */

    return FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen
 * DESCRIPTION
 *  enter player's screen from filemanger, will use file manager's selected file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOPLY_FEATURE_SPEED__)&&defined(__SF_MP4_SUPPORT__)  //wenshulong,20070911
BOOL g_vdoply_speed_disable = TRUE;
BOOL mmi_vdoply_get_speed_disable()
{
	return g_vdoply_speed_disable;
}
void mmi_vdoply_set_speed_disable(S8* filename)
{
	S8 file_name[FMGR_PATH_BUFFER_SIZE];
	U32 type;

	pfnUnicodeStrcat(file_name,filename);
	type = mmi_fmgr_get_file_type_by_filename((S8*)file_name);

	if(type == FMGR_TYPE_AVI)
		g_vdoply_speed_disable = FALSE;
	else
		g_vdoply_speed_disable = TRUE;
}
#endif
void mmi_vdoply_entry_player_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILE_INFO_STRUCT file_info;
    S32 index;
    S8 buffer[FMGR_PATH_BUFFER_SIZE];
    
#ifdef __DRM_SUPPORT__    
    U8 drm_result;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get file name from file manager's structure  */
    index = mmi_fmgr_kernel_get_cur_idx();

    mmi_fmgr_kernel_get_file_info(index, &file_info);
    mmi_fmgr_kernel_get_path_name(buffer);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_FILE;

    mmi_fmgr_append_file_name(buffer, file_info.file_name);
        
    /* check if is drm file */
#ifdef __DRM_SUPPORT__
    drm_result = fmgr_check_drm_rights(&file_info, DRM_PERMISSION_PLAY);
    if (drm_result == FMGR_DRM_NO_PERMISSION)
    {
        DisplayPopup((PU8)GetString(STR_GLOBAL_DRM_PROHIBITED), IMG_GLOBAL_ERROR, 0, 1000, ERROR_TONE);
        return;
    }
    else if (drm_result == FMGR_DRM_REQUEST_RIGHTS)
    {
        entry_fmgr_request_rights_confirm();
        return;
    }
#endif /* __DRM_SUPPORT__ */ 


    if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_RAM))
    {   
    #ifdef __MMI_VIDEO_STREAM__        
        mmi_vdoply_entry_player_screen_from_ram_file(buffer, FALSE);
    #endif
    }
    else if (FMGR_FILTER_IS_SET(&file_info.file_type, FMGR_TYPE_SDP))
    {
    #ifdef __MMI_VIDEO_STREAM__           
        mmi_vdoply_entry_player_screen_from_sdp_file(buffer, FALSE);
    #endif
    }
    else
    {
       mmi_vdoply_entry_player_screen_from_file(buffer, file_info.is_short);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_from_file
 * DESCRIPTION
 *  enter player's screen and play from file
 * PARAMETERS
 *  filename        [IN]        Filename with full path
 *  is_short        [IN]        Short name, need to covert from BIG5 to Unicode before display
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_entry_player_screen_from_file(PS8 filename, BOOL is_short)
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

        if (mmi_usb_check_path_exported(filename))
        {
            /* file is in exported device */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* avoid re-entry */
    mmi_vdoply_delete_all_from_history();

    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_file,
        MMI_FULL_SCREEN);

    /* allcoate buffer for filename */
    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_FILE;
    g_vdoply_cntx.is_short_filename = is_short;
    mmi_ucs2cpy(g_vdoply_cntx.source_path, filename);

    /* store path to NVRAM, use for recover source path when back from interrupt */
    mmi_fmgr_util_store_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    mmi_vdoply_entry_player_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_re_entry_player_screen_from_file
 * DESCRIPTION
 *  re-entry player screen for playing file
 * PARAMETERS
 *  void
 *  filename(?)     [IN]        Filename with full path
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_re_entry_player_screen_from_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_file,
        MMI_FULL_SCREEN);

    /* get path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_load_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_FILE;

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
#endif 
    mmi_vdoply_entry_player_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_from_id
 * DESCRIPTION
 *  enter player's screen and play from ID
 * PARAMETERS
 *  video_id            [IN]        
 *  video_name_id       [IN]        Video's name string id
 *  vidoe_id(?)         [IN]        Video clip resource id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_entry_player_screen_from_id(U16 video_id, U16 video_name_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid re-entry */
    mmi_vdoply_delete_all_from_history();
    
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_id,
        MMI_FULL_SCREEN);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_ID;

    g_vdoply_cntx.video_id = video_id;
    g_vdoply_cntx.video_name_id = video_name_id;

    if (video_name_id != 0)
    {
        mmi_ucs2cpy(g_vdoply_cntx.source_path, (PS8)GetString(g_vdoply_cntx.video_name_id));        
        g_vdoply_cntx.is_short_filename = FALSE;
    }
    else
    {
        g_vdoply_cntx.is_short_filename = FALSE;
    }

    mmi_vdoply_entry_player_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_re_entry_player_screen_from_id
 * DESCRIPTION
 *  re-enter player's screen and play from ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_re_entry_player_screen_from_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_id,
        MMI_FULL_SCREEN);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_ID;

    if (g_vdoply_cntx.video_id != 0)
    {
        mmi_ucs2cpy(g_vdoply_cntx.source_path, (PS8)GetString(g_vdoply_cntx.video_name_id));                
        g_vdoply_cntx.is_short_filename = FALSE;
    }
    else
    {
        g_vdoply_cntx.is_short_filename = FALSE;
    }

    mmi_vdoply_entry_player_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_internal
 * DESCRIPTION
 *  internal play screen function, allows to play from id and filename
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_player_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 *guiBuffer;
    U8 *inputBuffer;
    S32 str_len;
    S32 i;
#ifdef __MMI_VIDEO_STREAM__    
    mdi_result ret;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();

    g_vdoply_cntx.play_wnd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    /* load image viewer setting for snap shot directory */
    mmi_imgview_load_setting();

    /* load video player setting */
    mmi_vdoply_load_setting();

    entry_full_screen();

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_vdoply_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vdoply_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

    /* hook delete screen hdlr */
    SetDelScrnIDCallbackHandler(SCR_ID_VDOPLY_PLAYER, mmi_vdoply_del_screen_hdlr);

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(
		MMI_FRM_INT_CLAM, 
        mmi_vdoply_clam_close_event_hdlr, 
        NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_PLAYER);
    inputBuffer = GetCurrInputBuffer(SCR_ID_VDOPLY_PLAYER);

    if (guiBuffer == NULL)
    {
        g_vdoply_cntx.is_da_spd_file = FALSE;

        /* newly entry, will consume drm count */
        g_vdoply_cntx.is_consume_drm_count = TRUE;        
    }

    /* first time enter, or interrupted at opening state */
    if ((guiBuffer == NULL) || ((guiBuffer != NULL) && (g_vdoply_cntx.is_source_opened == FALSE)))
    {
        g_vdoply_cntx.cur_status.play_time = 0;
        g_vdoply_cntx.cur_status.start_play_time = 0;
        g_vdoply_cntx.cur_status.max_play_time = 0;
        g_vdoply_cntx.cur_status.speed = VDOPLY_DEFAULT_SPEED;
        g_vdoply_cntx.cur_status.play_ratio = 0;
        g_vdoply_cntx.cur_status.buff_ratio = 0;
        g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;
        
        memset((void*)&g_vdoply_cntx.video_info, 0, sizeof(vdoply_video_info_struct));
        
        if (g_vdoply_cntx.is_from_history)
        {
            mmi_ucs2cpy(g_vdoply_cntx.video_info.title_name, g_vdoply_cntx.history_title_name);
        }
        
        ReadValue((U8)NVRAM_VDOPLY_VOLUMN, (void*)&g_vdoply_cntx.cur_status.volume, DS_BYTE, &error);

        if (g_vdoply_cntx.cur_status.volume == 0xff)
        {
            /* NVRAM not init, give a default value */
            g_vdoply_cntx.cur_status.volume = VDOPLY_VOL_8;
        }

        if (g_vdoply_cntx.cur_status.volume == VDOPLY_VOL_MUTE)
        {
            g_vdoply_cntx.cur_status.volume = VDOPLY_VOL_1;
            g_vdoply_cntx.is_mute = TRUE;
        }

    }
    else
    {
        g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;        
        mmi_vdoply_calc_progress_ratio();
    }

    g_vdoply_cntx.fullscr_osd_opacity = 255;
    g_vdoply_cntx.bt_connecting_anim = GDI_NULL_HANDLE;    
    g_vdoply_cntx.connecting_anim = GDI_NULL_HANDLE;
    g_vdoply_cntx.opening_anim = GDI_NULL_HANDLE;    
    g_vdoply_cntx.aud_only_anim = GDI_NULL_HANDLE;        
    g_vdoply_cntx.is_stream_opened = FALSE;
    g_vdoply_cntx.is_seeking = FALSE;
    
    switch(g_vdoply_cntx.play_source)
    {
        case VDOPLY_PLAY_FROM_FILE:
        case VDOPLY_PLAY_FROM_ID:
        case VDOPLY_PLAY_FROM_PROGRESSIVE_DL:     
            g_vdoply_cntx.is_progress_seekable = TRUE;
            break;            
        case VDOPLY_PLAY_FROM_STREAMING_RTSP:
        case VDOPLY_PLAY_FROM_STREAMING_RAM:
        case VDOPLY_PLAY_FROM_STREAMING_SDP:
            if(guiBuffer == NULL)
            {
                g_vdoply_cntx.is_progress_seekable = FALSE;            
            }
            break;
    }


    /* create title name */
    if (!g_vdoply_cntx.is_from_history)
    {
        /* if not entry from history, we need to init title name */
        memset(g_vdoply_cntx.video_info.title_name, 0, sizeof(g_vdoply_cntx.video_info.title_name));    
        
        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
        {
            /* rtsp streaming, using url as default title */
            /* copy 1 char less to reserve null terminate */
            mmi_ucs2ncpy(
                g_vdoply_cntx.video_info.title_name, 
                g_vdoply_cntx.source_path, 
                MDI_VIDEO_INFO_TITLE_CHAR_COUNT-1);
        }
        else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP ||
                 g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE ||
                 g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            /* from file or sdp streaming , using file name */
            str_len = mmi_ucs2strlen(g_vdoply_cntx.source_path);

            /* find file name - by finding "\\" */
            for (i = str_len * 2 - 2; i >= 2; i -= 2)
            {
                if (mmi_ucs2ncmp((PS8) & g_vdoply_cntx.source_path[i], (PS8) L"\\", 1) == 0)
                {
                    i += 2;
                    break;
                }
            }

            /* copy 1 char less to reserve null terminate */
            mmi_ucs2ncpy(
                (PS8)g_vdoply_cntx.video_info.title_name, 
                (PS8)&(g_vdoply_cntx.source_path[i]),
                MDI_VIDEO_INFO_TITLE_CHAR_COUNT-1);
            
            mmi_fmgr_hide_ext_name(g_vdoply_cntx.video_info.title_name);

        }
        else
        {
            /* others : ex: id, keep it emtpy */
        }
        
        g_vdoply_cntx.is_from_history = FALSE;
    }
    else
    {
        /* if is init from history , title name is already set there, we dont need to init again */
    }
    

    /****************************************************************************
     * Init proper state for video applcation                                                                     
     *****************************************************************************/
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* disalbe align timer */
    UI_disable_alignment_timers();

    /* stop LED patten */
    StopLEDPatternBackGround();

#ifdef __MMI_TVOUT__
    /* if tvout is not enable, stop lcd sleep */
    if (!mdi_tvout_is_enable())
    {
        /* 
         * This is used to solve a very rare situation. When playing a IMELODY 
         * with backlight on/off, and the screen previous to this screen is a 
         * horizontal screen. Before enter this screen, the IMELODY turn off the
         * backlight. While exit previous screen, the layer rotate back to normal
         * size and the content is not correct. So when calling TurnOnBacklight, 
         * LCD is in sleepin state and draw wrong content to LCD.
         * So we need to clear the buffer first to avoid this situation.
         */
        gdi_layer_clear(GDI_COLOR_BLACK);

        TurnOnBacklight(0);
    }
    else
    {
        /* tv out is on, do not let tv to sleep in when lcd sleep in */
        mmi_phnset_tvout_disable_tv_sleep_in();
        mmi_phnset_disable_partial_ss();
    }
#else /* __MMI_TVOUT__ */ 
    /* 
     * This is used to solve a very rare situation. When playing a IMELODY 
     * with backlight on/off, and the screen previous to this screen is a 
     * horizontal screen. Before enter this screen, the IMELODY turn off the
     * backlight. While exit previous screen, the layer rotate back to normal
     * size and the content is not correct. So when calling TurnOnBacklight, 
     * LCD is in sleepin state and draw wrong content to LCD.
     * So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* stop lcd sleep */
    TurnOnBacklight(0);
#endif /* __MMI_TVOUT__ */ 

    /* init aud volume */
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_cntx.cur_status.volume));

    /* register AVRCP */
#ifdef __MMI_AVRCP_SUPPORT__
    PRINT_INFORMATION("video player set avrcp cmd hdlr\n");
    mmi_bt_avrcp_set_cmd_hdlr(mmi_vdoply_bt_avrcp_cmd_hdlr);
#endif 

    /* use medium font */
    gui_set_font(&MMI_medium_font);

#if defined(__VDOPLY_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vdoply_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vdoply_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vdoply_touch_scr_pen_move_hdlr);
#endif /* defined(__VDOPLY_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOPLY_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */

    /* get normal screen layer rotate angle */
#ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
    g_vdoply_cntx.normal_style_rotate = GDI_LAYER_ROTATE_270;
    g_vdoply_cntx.normal_style_lcd_width = UI_device_height;
    g_vdoply_cntx.normal_style_lcd_height = UI_device_width;

    gdi_lcd_set_rotate(g_vdoply_cntx.normal_style_rotate);

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_set_self_rotation_flag(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    gdi_layer_resize(g_vdoply_cntx.normal_style_lcd_width, g_vdoply_cntx.normal_style_lcd_height);

#ifdef __MMI_TVOUT__
    /* since someone change lcd/lcm rotate mechanism (gdi_lcd_set_rotate_by_layer()), 
       we must call this function to change driver's mode */
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

#else /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 
    g_vdoply_cntx.normal_style_rotate = GDI_LAYER_ROTATE_0;
    g_vdoply_cntx.normal_style_lcd_width = UI_device_width;
    g_vdoply_cntx.normal_style_lcd_height = UI_device_height;
#endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 

   /****************************************************************************
   * Init double osd buffer for full screen display                                                              
   *****************************************************************************/
#if defined(__VDOPLY_FEATURE_FULLSCREEN__) && !defined(__VDOPLY_FEATURE_HIDE_FULLSCR_OSD__)
    /* create full screen osd layer */
    g_vdoply_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc(VDOPLY_OSD_BUFFER_SIZE);

    gdi_layer_create_double_using_outside_memory(
        0,
        0,
        UI_device_height,   /* rotate - swap width with height */
        UI_device_width,    /* rotate - swap width with height */
        &g_vdoply_cntx.osd_layer_handle,
        (PU8) g_vdoply_cntx.osd_layer_buf_ptr,
        (S32) (VDOPLY_OSD_BUFFER_SIZE));

    gdi_layer_push_and_set_active(g_vdoply_cntx.osd_layer_handle);

    gdi_layer_set_opacity(TRUE, (U8) g_vdoply_cntx.fullscr_osd_opacity);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

#endif /* defined(__VDOPLY_FEATURE_FULLSCREEN__) && !defined(__VDOPLY_FEATURE_HIDE_FULLSCR_OSD__) */ 

   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
#if defined(__VDOPLY_FEATURE_SPEED__)&&defined(__SF_MP4_SUPPORT__)
	mmi_vdoply_set_speed_disable(g_vdoply_cntx.source_path);
#endif
    /* init panel */
    mmi_vdoply_init_ui();

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    mmi_vdoply_init_fullscr_ui();
#endif 

#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
    /* newer cip has layer bg color, we can split bg into smaller region for better performance */
    gdi_layer_set_blt_layer(
        g_vdoply_cntx.bg_region_0_layer_handle, 
        g_vdoply_cntx.bg_region_1_layer_handle,             
        0,
        0);
#else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
   
    /* MT6219 dont have bg color - we need use bg layer as lcd size */    
    gdi_layer_set_blt_layer(g_vdoply_cntx.bg_layer_handle, 0, 0, 0);
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */


    mmi_vdoply_draw_bg();
    mmi_vdoply_draw_title();
        
    mmi_vdoply_set_state_softkey(g_vdoply_cntx.state);
    mmi_vdoply_draw_softkey();
    mmi_vdoply_draw_panel();


    mmi_vdoply_blt_screen();

    /* this function is entry by small screen's history draw, no need to open file */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    /* reset flag, this need reset after check small screen */
	if (guiBuffer == NULL)
	{
        g_vdoply_cntx.is_source_opened = FALSE;
    }

#ifdef __MMI_TVOUT__
    g_vdoply_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();

    if (!mdi_tvout_is_enable())
    {
        /* if no TV-out, rotate by layer */
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {   
        /* if have Tv-out rotate by LCM */
        gdi_lcd_set_rotate_by_layer(FALSE);
    }
#else /* __MMI_TVOUT__ */

    /* no TV-out */
    g_vdoply_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();
    gdi_lcd_set_rotate_by_layer(TRUE);
    
#endif /* __MMI_TVOUT__ */


    switch(g_vdoply_cntx.play_source)
    {
        case VDOPLY_PLAY_FROM_FILE:
        case VDOPLY_PLAY_FROM_ID:

     
            /* check if it is first entry */
            if ((guiBuffer == NULL) || (g_vdoply_cntx.cur_status.play_time == 0))
            {
                /* (1) First time enter */
                /* (2) Back from interrupt, but was interrupt at idle state */
                mmi_vdoply_enter_state(VDOPLY_STATE_OPENING);
                return;                    
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_INTERRUPTED_OPENING);
                return;                    
            }
            break; 
            
        case VDOPLY_PLAY_FROM_PROGRESSIVE_DL:   
            /* check if it is first entry */
            if ((guiBuffer == NULL) || (g_vdoply_cntx.cur_status.play_time == 0))
            {
                /* (1) First time enter */
                /* (2) Back from interrupt, but was interrupt at idle state */
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_OPENING);
                return;                    
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING);
                return;                    
            }
            break; 

        case VDOPLY_PLAY_FROM_STREAMING_RTSP:
        case VDOPLY_PLAY_FROM_STREAMING_RAM:
        case VDOPLY_PLAY_FROM_STREAMING_SDP:
            
        #ifdef __MMI_VIDEO_STREAM__
            g_vdoply_cntx.is_stream_init = FALSE;
            ret = mdi_video_stream_init();
            
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)      
            {
                /* ture means has error popup */                
                return;
            }
            
            g_vdoply_cntx.is_stream_init = TRUE;
        #endif
            
            if (guiBuffer == NULL)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);    
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING);    
            }
            break;          
            
          
    }

}

#ifdef __SF_MP4_SUPPORT__
static BOOL g_isEnterFullScreen = FALSE;
BOOL SFApp_VdoSetupGDI(void)
{
#ifdef __SF_MP4_FAST_UPDATE_SCREEN__
	if (g_isEnterFullScreen)
		return FALSE;
	else
		g_isEnterFullScreen = TRUE;

   	entry_full_screen();

	gdi_layer_blt_ext(g_vdoply_cntx.fullscr_play_layer_handle, 0, 0, 0,
			#ifdef GDI_6_LAYERS
						0, 0,
			#endif
						0, 0, LCD_HEIGHT-1, LCD_WIDTH-1);	

	lcd_power_up();
    	gdi_layer_lock_frame_buffer();
#endif //__SF_MP4_FAST_UPDATE_SCREEN__
	return TRUE;

}

BOOL SFApp_VdoFreeGDI(void)
{

#ifndef MMI_ON_WIN32	//Add 08Mar14, Matthew
	kal_prompt_trace(MOD_MMI, "SFApp_VdoFreeGDI, g_isEnterFullScreen:%d", g_isEnterFullScreen);
#endif

	if (!g_isEnterFullScreen)
		return FALSE;
	else
		g_isEnterFullScreen = FALSE;

	gdi_layer_unlock_frame_buffer();

#ifndef MMI_ON_WIN32	//Add 08Mar14, Matthew
	lcd_power_down();
#endif

	return TRUE;
}

BOOL mmi_vdoply_is_full_screen(void)
{
	if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
		return TRUE;
	else
		return FALSE;
}

#endif //__SF_MP4_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_play_video
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MDI_RESULT mmi_vdoply_play_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rotate;
    U32 blt_layer;
    U32 play_layer;
    gdi_handle play_layer_handle;
    MDI_RESULT ret;

#if defined(NOKE_DEBUG)
     noke_dbg_printf("\r\ng_vdoply_cntx.state = %d :%s : %d",g_vdoply_cntx.state,__FILE__,__LINE__);
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY || 
        g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
    {
        /* start play video - fullscreen */
        
    #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        /* no OSD */
	//Huyanwei Touch Here
        play_layer_handle = g_vdoply_cntx.fullscr_play_layer_handle;
        blt_layer = GDI_LAYER_ENABLE_LAYER_0;   
        play_layer = GDI_LAYER_ENABLE_LAYER_0;           
        rotate = VDOPLY_PLAYBACK_ROTATE_270;
    #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
        /* have  OSD */
        play_layer_handle = g_vdoply_cntx.fullscr_play_layer_handle;
        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;   
        play_layer = GDI_LAYER_ENABLE_LAYER_0;           
        rotate = VDOPLY_PLAYBACK_ROTATE_270;
    #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY ||
             g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)        
    {
        play_layer_handle = g_vdoply_cntx.play_wnd_layer_handle;
          
    #ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
        /* bg region 0, bg region 1, play layer */
        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;   
        play_layer = GDI_LAYER_ENABLE_LAYER_2;     
    #else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
        /* bg, play layer */    
        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;   
        play_layer = GDI_LAYER_ENABLE_LAYER_1;     
    #endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
        
    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        rotate = VDOPLY_PLAYBACK_ROTATE_270;
    #else 
        rotate = VDOPLY_PLAYBACK_ROTATE_0;
    #endif
    }
    else
    {
        MMI_ASSERT(0);
        return -1;  /* error */
    }

    if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY || 
        g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
    {
        
    #ifdef __DRM_SUPPORT__
        if (g_vdoply_cntx.is_consume_drm_count)
        {
            g_vdoply_cntx.is_consume_drm_count = FALSE;
        }
        else
        {
            mdi_video_ply_drm_disable_consume_count();            
        }
    #endif /* __DRM_SUPPORT__ */
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n%s : %d",__FILE__,__LINE__);
#endif
        ret = mdi_video_ply_play(
                play_layer_handle,                      /* play layer handle */
                blt_layer,                              /* blt layer */
                play_layer,                             /* play_layer_flag */
                1,                                      /* repeat */
                TRUE,                                   /* visual update */
                TRUE,                                   /* play aud */
                MDI_DEVICE_SPEAKER2,                    /* audio path */
                rotate,                                 /* rotate */
                mmi_vdoply_get_speed_factor(),          /* speed factor */
                mmi_vdoply_player_play_finish_hdlr);    /* play layer */
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nres=%d:%s : %d",ret,__FILE__,__LINE__);
#endif
        if (ret == MDI_RES_VDOPLY_SUCCEED)
        {
#if defined(NOKE_DEBUG)
        	    noke_dbg_printf("\r\n g_vdoply_cntx.video_info.track =%d:%s : %d ",g_vdoply_cntx.video_info.track,__FILE__,__LINE__);
#endif
            /* draw aud only anim */
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
            {
#if defined(NOKE_DEBUG)
            	noke_dbg_printf("\r\n %s : %d ",__FILE__,__LINE__);
#endif
                if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
                {
#if defined(NOKE_DEBUG)
               	  noke_dbg_printf("\r\n %s : %d ",__FILE__,__LINE__);
#endif
                    mmi_vdoply_draw_aud_only_anim();
                }
                else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
                {
#if defined(NOKE_DEBUG)
                    noke_dbg_printf("\r\n %s : %d ",__FILE__,__LINE__);
#endif
                #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                    mmi_vdoply_draw_fullscr_aud_only_anim();
                #endif 
                }
                mmi_vdoply_blt_screen();                
            }
#ifdef __SF_MP4_SUPPORT__
            if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY) /*Added by bob, for mp4 display, @20070724*/
            {
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n%s : %d",__FILE__,__LINE__);
#endif
                SFApp_VdoSetupGDI();
            }
#endif //__SF_MP4_SUPPORT__
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n%s : %d",__FILE__,__LINE__);
#endif
            mmi_vdoply_player_timer_cyclic();
            return MDI_RES_VDOPLY_SUCCEED;
        }    
        else
        {
        #if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
            if (mmi_vdoply_is_output_to_bt())
            {
                MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_CALLING_AV_BT_CLOSE_CODEC, __LINE__);                   
                av_bt_close_codec();
            }
        #endif /* __MMI_AUDIO_PLAYER__ && __MMI_BT_MTK_SUPPORT__ && __MMI_A2DP_SUPPORT__ */
            return ret;
        }

    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY || 
             g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__        
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n%s : %d",__FILE__,__LINE__);
#endif
        ret = mdi_video_stream_play(
            play_layer_handle, 
            blt_layer, 
            play_layer, 
            TRUE, 
            MDI_DEVICE_SPEAKER2, 
            rotate, 
            mmi_vdoply_player_play_finish_hdlr);
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nres=%d:%s : %d",ret,__FILE__,__LINE__);
#endif
        if (ret == MDI_RES_VDOPLY_SUCCEED)
        {
            /* draw aud only anim */
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
            {
                if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
                {
                    mmi_vdoply_draw_aud_only_anim();
                }
                else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
                {
                #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                    mmi_vdoply_draw_fullscr_aud_only_anim();
                #endif 
                }
                mmi_vdoply_blt_screen();                
            }
            
            mmi_vdoply_player_timer_cyclic();            
            return MDI_RES_VDOPLY_SUCCEED;           
        }    
        else
        {
            mmi_vdoply_bt_close_codec();
            return ret;        
        }
    
    #else /* __MMI_VIDEO_STREAM__ */
        MMI_ASSERT(0);
    #endif /* __MMI_VIDEO_STREAM__ */

    
    }

    return MDI_RES_VDOPLY_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stop_video
 * DESCRIPTION
 *  stop play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_stop_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoply_player_timer_cyclic);
    
    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY || 
        g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
    {
        mdi_video_ply_stop();
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY || 
             g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__
        mdi_video_stream_stop();
    #endif
    }

    mmi_vdoply_bt_close_codec();
    mmi_vdoply_disconnect_bt();   

    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
    {
        mmi_vdoply_clear_aud_only_anim();           
        mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        mdi_video_ply_seek_and_get_frame(g_vdoply_cntx.cur_status.play_time, g_vdoply_cntx.play_wnd_layer_handle);
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        mmi_vdoply_clear_fullscr_aud_only_anim();                   
        mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        mdi_video_ply_seek_and_get_frame(g_vdoply_cntx.cur_status.play_time, g_vdoply_cntx.fullscr_play_layer_handle);
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__      
        mmi_vdoply_clear_aud_only_anim();  
    
        if (g_vdoply_cntx.video_info.is_seekable)
        {    
            mdi_video_stream_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);                
        }
        else
        {
            mdi_video_stream_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);   
            mdi_video_stream_disconnect();
        }
    #endif 
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__  
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        mmi_vdoply_clear_fullscr_aud_only_anim();    
   
        if (g_vdoply_cntx.video_info.is_seekable)
        {    
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);                
        }
        else
        {
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);   
            mdi_video_stream_disconnect();
        }
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */        
    #endif /* __MMI_VIDEO_STREAM__ */
    }
    else
    {
        MMI_ASSERT(0);
    }
        
}


#if defined(__MMI_VIDEO_STREAM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_resume_stream_video
 * DESCRIPTION
 *  start play video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_resume_stream_video(void)
{
#ifdef __MMI_VIDEO_STREAM__      
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 rotate;
    U32 blt_layer;
    U32 play_layer;
    gdi_handle play_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
    {
        /* start play video - fullscreen */
        
    #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        /* no OSD */
        play_layer_handle = g_vdoply_cntx.fullscr_play_layer_handle;
        blt_layer = GDI_LAYER_ENABLE_LAYER_0;   
        play_layer = GDI_LAYER_ENABLE_LAYER_0;           
        rotate = VDOPLY_PLAYBACK_ROTATE_270;
    #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
        /* have  OSD */
        play_layer_handle = g_vdoply_cntx.fullscr_play_layer_handle;
        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;   
        play_layer = GDI_LAYER_ENABLE_LAYER_0;           
        rotate = VDOPLY_PLAYBACK_ROTATE_270;
    #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)        
    {
        play_layer_handle = g_vdoply_cntx.play_wnd_layer_handle;
          
    #ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
        /* bg region 0, bg region 1, play layer */
        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;   
        play_layer = GDI_LAYER_ENABLE_LAYER_2;     
    #else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
        /* bg, play layer */    
        blt_layer = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;   
        play_layer = GDI_LAYER_ENABLE_LAYER_1;     
    #endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
        
    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        rotate = VDOPLY_PLAYBACK_ROTATE_270;
    #else 
        rotate = VDOPLY_PLAYBACK_ROTATE_0;
    #endif
    }
    else
    {
        MMI_ASSERT(0);
        return;  /* error */
    }
      
    mdi_video_stream_resume(
        play_layer_handle, 
        blt_layer, 
        play_layer, 
        TRUE, 
        MDI_DEVICE_SPEAKER2, 
        rotate);

#endif /* __MMI_VIDEO_STREAM__ */

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_loading
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_loading(S32 percentage, MMI_BOOL draw_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 draw_width;
    S32 offset_x;
    S32 offset_y;   
    S32 layer_offset_x;
    S32 layer_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
    
    layer_offset_x = g_vdoply_osd_cntx.loading.rect.offset_x;
    layer_offset_y = g_vdoply_osd_cntx.loading.rect.offset_y;    
    
    gdi_layer_set_position(layer_offset_x, layer_offset_y);
  
    if (draw_bg)
    {
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    
        gdi_image_draw_id(
            g_vdoply_osd_cntx.loading.bg.offset_x-layer_offset_x,
            g_vdoply_osd_cntx.loading.bg.offset_y-layer_offset_y,
            IMG_ID_VDOPLY_OSD_LOADING_BG);
    }

    if (g_vdoply_osd_cntx.loading.is_draw_progress)
    {
        gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_LOADING_EMPTY, &image_width, &image_height);

        offset_x = g_vdoply_osd_cntx.loading.progress.offset_x-layer_offset_x;
        offset_y = g_vdoply_osd_cntx.loading.progress.offset_y-layer_offset_y;
    
        /* draw empty loading bar */
        gdi_image_draw_id(
            offset_x,
            offset_y,
            IMG_ID_VDOPLY_OSD_LOADING_EMPTY);

        draw_width = image_width * percentage / 100;

        gdi_layer_set_clip(
            offset_x,
            offset_y,
            offset_x + draw_width,
            offset_y + image_height);

        gdi_image_draw_id(
            offset_x,
            offset_y,
            IMG_ID_VDOPLY_OSD_LOADING_FILL);
    }


    gdi_layer_reset_clip();
    gdi_layer_pop_and_restore_active();

        
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_connecting_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.connecting_anim == GDI_NULL_HANDLE)
    {    
        gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
        
        layer_offset_x = g_vdoply_osd_cntx.loading.rect.offset_x;
        layer_offset_y = g_vdoply_osd_cntx.loading.rect.offset_y;    
        
        gdi_layer_set_position(layer_offset_x, layer_offset_y);

        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_image_draw_animation_id(
            g_vdoply_osd_cntx.loading.bg.offset_x-layer_offset_x,
            g_vdoply_osd_cntx.loading.bg.offset_y-layer_offset_y,
            IMG_ID_VDOPLY_OSD_CONNECTING,
            &g_vdoply_cntx.connecting_anim);

        gdi_layer_pop_and_restore_active();
    }
        
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_connecting_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.connecting_anim != GDI_NULL_HANDLE)
    {    
        gdi_image_stop_animation(g_vdoply_cntx.connecting_anim);
        g_vdoply_cntx.connecting_anim = GDI_NULL_HANDLE;  
    }
}
#endif /* __MMI_VIDEO_STREAM__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_opening_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_opening_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.opening_anim == GDI_NULL_HANDLE)
    {    
        gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
        layer_offset_x = g_vdoply_osd_cntx.loading.rect.offset_x;
        layer_offset_y = g_vdoply_osd_cntx.loading.rect.offset_y;    
        
        gdi_layer_set_position(layer_offset_x, layer_offset_y);

        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_image_draw_animation_id(
            g_vdoply_osd_cntx.loading.bg.offset_x-layer_offset_x,
            g_vdoply_osd_cntx.loading.bg.offset_y-layer_offset_y,
            IMG_ID_VDOPLY_OSD_OPENING,
            &g_vdoply_cntx.opening_anim);

        gdi_layer_pop_and_restore_active();
    }
        
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_opening_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_opening_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.opening_anim != GDI_NULL_HANDLE)
    {    
        gdi_image_stop_animation(g_vdoply_cntx.opening_anim);
        g_vdoply_cntx.opening_anim = GDI_NULL_HANDLE;  
    }
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_snapshoting
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_snapshoting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
    layer_offset_x = g_vdoply_osd_cntx.loading.rect.offset_x;
    layer_offset_y = g_vdoply_osd_cntx.loading.rect.offset_y;    
    
    gdi_layer_set_position(layer_offset_x, layer_offset_y);

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    gdi_image_draw_id(
        g_vdoply_osd_cntx.loading.bg.offset_x-layer_offset_x,
        g_vdoply_osd_cntx.loading.bg.offset_y-layer_offset_y,
        IMG_ID_VDOPLY_OSD_SNAPSHOTING);

    gdi_layer_pop_and_restore_active();
       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_snapshoting
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_snapshoting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_aud_only_anim
 * DESCRIPTION
 *  draw audio only animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_aud_only_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width, layer_height;
    S32 image_width, image_height;
    S32 offset_x, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
    {
        gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
        gdi_layer_get_dimension(&layer_width, &layer_height);

        gdi_layer_clear(GDI_COLOR_BLACK);

        gdi_image_get_dimension_id(
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM,
            &image_width,
            &image_height);

        offset_x = (layer_width - image_width) >> 1;
        offset_y = (layer_height - image_height) >> 1;                    

        gdi_image_draw_animation_id(
            offset_x, 
            offset_y, 
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM,
            &g_vdoply_cntx.aud_only_anim);

        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();        
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_play_region_bg
 * DESCRIPTION
 *  draw audio only animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_play_region_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width, layer_height;
    S32 image_width, image_height;
    S32 offset_x, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
    {
        gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
        gdi_layer_get_dimension(&layer_width, &layer_height);

        gdi_layer_clear(GDI_COLOR_BLACK);

        gdi_image_get_dimension_id(
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM,
            &image_width,
            &image_height);

        offset_x = (layer_width - image_width) >> 1;
        offset_y = (layer_height - image_height) >> 1;                    

        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM);

        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();        
    }      
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_aud_only_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_aud_only_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_vdoply_cntx.aud_only_anim != GDI_NULL_HANDLE)
    {
        gdi_image_stop_animation(g_vdoply_cntx.aud_only_anim);
        g_vdoply_cntx.aud_only_anim = GDI_NULL_HANDLE;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_bg
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__    
    S32 offset_x;
    S32 offset_y;
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__    
    /* newer cip has layer bg color, we can split bg into smaller region for better performance */
    gdi_layer_push_and_set_active(g_vdoply_cntx.bg_region_0_layer_handle);
    gdi_layer_get_position(&offset_x, &offset_y);
    gdi_image_draw_id(-offset_x, -offset_y, IMG_ID_VDOPLY_OSD_BG);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(g_vdoply_cntx.bg_region_1_layer_handle);
    gdi_layer_get_position(&offset_x, &offset_y);
    gdi_image_draw_id(-offset_x, -offset_y, IMG_ID_VDOPLY_OSD_BG);
    gdi_layer_pop_and_restore_active();

#ifndef __VDOPLY_FEATURE_HIDE_TIMER__
    /* draw timer bg */
    gdi_layer_push_and_set_active(g_vdoply_cntx.timer_draw_layer);    
    
    gdi_image_draw_id(
        (-offset_x) + g_vdoply_osd_cntx.panel.timer_bg.offset_x,
        (-offset_y) + g_vdoply_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOPLY_OSD_TIMER_BG);
    gdi_layer_pop_and_restore_active();
#endif /* __VDOPLY_FEATURE_HIDE_TIMER__ */


#else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
    /* MT6219 dont have bg color - we need use bg layer as lcd size */   
    gdi_layer_push_and_set_active(g_vdoply_cntx.bg_layer_handle);
    gdi_image_draw_id(0, 0, IMG_ID_VDOPLY_OSD_BG);

#ifndef __VDOPLY_FEATURE_HIDE_TIMER__
    gdi_image_draw_id(
        g_vdoply_osd_cntx.panel.timer_bg.offset_x,
        g_vdoply_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOPLY_OSD_TIMER_BG);
#endif /* __VDOPLY_FEATURE_HIDE_TIMER__ */

    gdi_layer_pop_and_restore_active();
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */


}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_title
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    S32 index;
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    S8 buf_filename_dest[FMGR_PATH_BUFFER_SIZE];
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    S32 dot_width;
    S32 dot_height;
    S32 str_total_width;
    S32 char_width;
    S32 char_height;
    S32 layer_offset_x;
    S32 layer_offset_y;

    UI_character_type *char_ptr;
    video_rect_struct *bbox_rect_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display filename */

    if ((g_vdoply_osd_cntx.title.is_draw_filename) || (g_vdoply_osd_cntx.title.is_draw_app_name))
    {
        if (g_vdoply_osd_cntx.title.is_draw_filename)
        {
            mmi_ucs2ncpy(
                (PS8)buf_filename, 
                (PS8)g_vdoply_cntx.video_info.title_name, 
                MDI_VIDEO_INFO_TITLE_CHAR_COUNT);
        }
        else    
        {
            /* g_vdoply_osd_cntx.title.is_draw_app_name */
            mmi_ucs2cpy((PS8) buf_filename, (PS8) GetString(STR_ID_VDOPLY_APP_NAME));
        }

        gui_measure_string((UI_string_type) buf_filename, &str_width, &str_height);
        bbox_rect_p = &g_vdoply_osd_cntx.title.rect;

        /* if string too long, change to xxxxxx.. */
        if (str_width > bbox_rect_p->width)
        {
            str_len = mmi_ucs2strlen(buf_filename);
            gui_measure_string((UI_string_type) L"..", &dot_width, &dot_height);

            str_total_width = dot_width;
            char_ptr = (UI_character_type*) buf_filename;

            for (index = 0; index < str_len; index++)
            {
                gui_measure_character(char_ptr[index], &char_width, &char_height);

                if ((str_total_width + char_width) > bbox_rect_p->width)
                {
                    mmi_ucs2cpy(&buf_filename[(index - 1) * ENCODING_LENGTH], (PS8) L"..");
                    break;
                }
                else
                {
                    str_total_width += char_width;
                }
            }

            str_width = str_total_width;
        }

        if (g_vdoply_osd_cntx.title.v_align == VIDEO_ALIGN_TOP)
        {
            offset_y = 0;
        }
        else if (g_vdoply_osd_cntx.title.v_align == VIDEO_ALIGN_BOTTOM)
        {
            offset_y = bbox_rect_p->height - str_height;
        }
        else    /* center */
        {
            offset_y = (bbox_rect_p->height - str_height) >> 1;
        }

        offset_y += bbox_rect_p->offset_y;

        if (g_vdoply_osd_cntx.title.h_align == VIDEO_ALIGN_LEFT)
        {
            offset_x = 0;
        }
        else if (g_vdoply_osd_cntx.title.h_align == VIDEO_ALIGN_RIGHT)
        {
            offset_x = bbox_rect_p->width - str_width;
        }
        else
        {
            offset_x = (bbox_rect_p->width - str_width) >> 1;
        }

        offset_x += bbox_rect_p->offset_x;

 
        gdi_layer_push_and_set_active(g_vdoply_cntx.title_draw_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

        /* short file name need covert from BIG5 to unicode */
        if (g_vdoply_cntx.is_short_filename)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) buf_filename_dest,
                sizeof(buf_filename_dest),
                (U8*) buf_filename,
                PhnsetGetDefEncodingType());

            mmi_vdoply_draw_style_text(
                buf_filename_dest, 
                offset_x - layer_offset_x, 
                offset_y - layer_offset_y, 
                &g_vdoply_osd_cntx.title.style_text);
        }
        else
        {
            mmi_vdoply_draw_style_text(
                buf_filename, 
                offset_x - layer_offset_x,
                offset_y - layer_offset_y,
                &g_vdoply_osd_cntx.title.style_text);
        }

        gdi_layer_pop_and_restore_active();
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_panel_state
 * DESCRIPTION
 *  draw panel's state icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_panel_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_FULLSCREEN__

    gdi_layer_push_and_set_active(g_vdoply_cntx.fullscreen_draw_layer);    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    if (!g_vdoply_cntx.touch_fullscreen.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.fullscreen.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.fullscreen.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN_DIS));        
    }
    else if (g_vdoply_cntx.touch_fullscreen.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.fullscreen.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.fullscreen.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN_SEL));
    }
    else
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.fullscreen.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.fullscreen.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_TOUCH_OSD_FULLSCREEN));
    }
    
    gdi_layer_pop_and_restore_active();    
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

#ifdef __VDOPLY_FEATURE_SNAPSHOT__

    gdi_layer_push_and_set_active(g_vdoply_cntx.snapshot_draw_layer);  
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    if (!g_vdoply_cntx.touch_snapshot.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.snapshot.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.snapshot.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_TOUCH_OSD_SNAPSHOT_DIS));        
    }
    else if (g_vdoply_cntx.touch_snapshot.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.snapshot.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.snapshot.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_TOUCH_OSD_SNAPSHOT_SEL));
    }
    else
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.snapshot.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.snapshot.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_TOUCH_OSD_SNAPSHOT));
    }

    gdi_layer_pop_and_restore_active();                
#endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_panel_progress
 * DESCRIPTION
 *  draw panel's progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_panel_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoply_cntx.progress_draw_layer);     
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    if (!g_vdoply_cntx.is_progress_seekable)
    {
        /* can not seek, we will show disable progress bar */
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_empty.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_empty.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_OSD_PROGRESS_DIS));

        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_DIS);

        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_DIS);

        gdi_layer_pop_and_restore_active();

        return;
    }

    
    /* draw empty first */
    gdi_image_draw_id(
        g_vdoply_osd_cntx.panel.progress_empty.offset_x - layer_offset_x,
        g_vdoply_osd_cntx.panel.progress_empty.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY));

#ifdef __MMI_VIDEO_PDL__
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
    {
        if (g_vdoply_cntx.cur_status.buff_ratio != 0)
        {
            /* draw inside filling */
            offset_x = g_vdoply_osd_cntx.panel.progress_fill.offset_x - layer_offset_x,
            offset_y = g_vdoply_osd_cntx.panel.progress_fill.offset_y - layer_offset_y,

            gdi_layer_set_clip(
                offset_x,
                offset_y,
                offset_x + g_vdoply_cntx.cur_status.buff_ratio,
                offset_y + g_vdoply_cntx.progress.fill_height);

            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.progress_fill.offset_x,
                g_vdoply_osd_cntx.panel.progress_fill.offset_y,
                (U16) (IMG_ID_VDOPLY_OSD_PROGRESS_BUFFER));

            gdi_layer_reset_clip();          
        }
    }
#endif /* __MMI_VIDEO_PDL__ */

    if (g_vdoply_cntx.cur_status.play_ratio != 0)
    {
        /* draw inside filling */
        offset_x = g_vdoply_osd_cntx.panel.progress_fill.offset_x - layer_offset_x;
        offset_y = g_vdoply_osd_cntx.panel.progress_fill.offset_y - layer_offset_y;

        gdi_layer_set_clip(
            offset_x,
            offset_y,
            offset_x + g_vdoply_cntx.cur_status.play_ratio,
            offset_y + g_vdoply_cntx.progress.fill_height);

        gdi_image_draw_id(
            offset_x,
            offset_y,
            (U16) (IMG_ID_VDOPLY_OSD_PROGRESS_FILL));
            
        gdi_layer_reset_clip();            
    }


    /* progress inc */
    if (!g_vdoply_cntx.touch_progress_inc.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_DIS);
    }
    else if (g_vdoply_cntx.touch_progress_inc.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC_SEL);
    }
    else
    {

        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_INC);
    }

    /* progress dec */
    if (!g_vdoply_cntx.touch_progress_dec.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_DIS);
    }    
    else if (g_vdoply_cntx.touch_progress_dec.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC_SEL);
    }
    else
    {

        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.progress_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.progress_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_PROGRESS_DEC);
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_panel_timer
 * DESCRIPTION
 *  draw panel's timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_draw_panel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time;
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    S32 layer_offset_x;
    S32 layer_offset_y;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time = (U32) (g_vdoply_cntx.cur_status.play_time / 1000);

    hour = time / 3600;
    hour_remain = time % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (hour > 99)
    {
        hour = 99;
    }

    gdi_layer_push_and_set_active(g_vdoply_cntx.timer_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    /* hr */
    gdi_image_draw_id(
        g_vdoply_cntx.timer.hr_0_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_0 + (U16) hour / 10));

    gdi_image_draw_id(
        g_vdoply_cntx.timer.hr_1_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_0 + (U16) hour % 10));

    gdi_image_draw_id(
        g_vdoply_cntx.timer.col_0_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_COL));

    /* min */
    gdi_image_draw_id(
        g_vdoply_cntx.timer.min_0_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_0 + (U16) min / 10));

    gdi_image_draw_id(
        g_vdoply_cntx.timer.min_1_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_0 + (U16) min % 10));

    gdi_image_draw_id(
        g_vdoply_cntx.timer.col_1_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_COL));

    /* sec */
    gdi_image_draw_id(
        g_vdoply_cntx.timer.sec_0_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_0 + (U16) sec / 10));

    gdi_image_draw_id(
        g_vdoply_cntx.timer.sec_1_offset_x - layer_offset_x,
        g_vdoply_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOPLY_OSD_TIMER_0 + (U16) sec % 10));


    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_panel_speed
 * DESCRIPTION
 *  draw panel's speed icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_panel_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_SPEED__

    gdi_layer_push_and_set_active(g_vdoply_cntx.speed_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_draw_id(
        g_vdoply_osd_cntx.panel.speed.offset_x - layer_offset_x,
        g_vdoply_osd_cntx.panel.speed.offset_y - layer_offset_y,
        mmi_vdoply_get_speed_image());

    if(!g_vdoply_cntx.touch_speed_dec.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.speed_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.speed_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC_DIS);
            
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.speed_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.speed_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC_DIS);        

        gdi_layer_pop_and_restore_active();
        return;
    }

    /* speed inc */
    if (g_vdoply_cntx.touch_speed_inc.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.speed_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.speed_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC_SEL);
    }
    else
    {

        if (g_vdoply_cntx.cur_status.speed < VDOPLY_FEATURE_SPEED_COUNT - 1)
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.speed_inc.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.speed_inc.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC);

        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.speed_inc.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.speed_inc.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_SPEED_INC_DIS);

        }
    }

    /* speed dec */
    if (g_vdoply_cntx.touch_speed_dec.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.speed_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.speed_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC_SEL);
    }
    else
    {
        if (g_vdoply_cntx.cur_status.speed > 0)
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.speed_dec.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.speed_dec.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.speed_dec.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.speed_dec.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_SPEED_DEC_DIS);
        }
    }

    gdi_layer_pop_and_restore_active();
#endif /* __VDOPLY_FEATURE_SPEED__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_panel_volume
 * DESCRIPTION
 *  draw panel's volumn icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_panel_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_VOLUME__

    gdi_layer_push_and_set_active(g_vdoply_cntx.volume_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    if (g_vdoply_cntx.is_mute)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.volume.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.volume.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_OSD_VOLUME_MUTE);
    }
    else
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.volume.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.volume.offset_y - layer_offset_y,
            (U16) (IMG_ID_VDOPLY_OSD_VOLUME_START + g_vdoply_cntx.cur_status.volume + 1));

    }

    if (!g_vdoply_cntx.touch_volume_dec.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.volume_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.volume_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC_DIS);

        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.volume_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.volume_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC_DIS);

        gdi_layer_pop_and_restore_active();
        return;
    } 
    
    /* vol inc */
    if (g_vdoply_cntx.touch_volume_inc.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.volume_inc.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.volume_inc.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC_SEL);
    }
    else
    {
        if (g_vdoply_cntx.cur_status.volume < VDOPLY_VOL_16)
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.volume_inc.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.volume_inc.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.volume_inc.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.volume_inc.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_INC_DIS);
        }
    }

    /* vol dec */
    if (g_vdoply_cntx.touch_volume_dec.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_osd_cntx.panel.volume_dec.offset_x - layer_offset_x,
            g_vdoply_osd_cntx.panel.volume_dec.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC_SEL);
    }
    else
    {

    #ifdef __VDOPLY_FEATURE_VOLUME_MUTE__
        if (!g_vdoply_cntx.is_mute)
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.volume_dec.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.volume_dec.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.volume_dec.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.volume_dec.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC_DIS);
        }
    #else /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 
        if (g_vdoply_cntx.cur_status.volume > VDOPLY_VOL_1)
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.volume_dec.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.volume_dec.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_osd_cntx.panel.volume_dec.offset_x - layer_offset_x,
                g_vdoply_osd_cntx.panel.volume_dec.offset_y - layer_offset_y,
                IMG_ID_VDOPLY_TOUCH_OSD_VOLUME_DEC_DIS);
        }
    #endif /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 

    }

    gdi_layer_pop_and_restore_active();

#endif /* __VDOPLY_FEATURE_VOLUME__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_style_text
 * DESCRIPTION
 *  init panel's UI item
 * PARAMETERS
 *  str             [IN]        In    string pointer
 *  offset_x        [IN]        In    string pos x
 *  offset_y        [IN]        In    string pos y
 *  style_txt       [?]         In    style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, video_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    if (style_txt->style == VIDEO_TEXT_STYLE_NORMAL)
    {
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else if (style_txt->style == VIDEO_TEXT_STYLE_BORDER)
    {
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_bordered_text((UI_string_type) str);
    }
    else if (style_txt->style == VIDEO_TEXT_STYLE_SHADOW)
    {
        gui_move_text_cursor(offset_x + 1, offset_y + 1);
        gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_text((UI_string_type) str);

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_softkey
 * DESCRIPTION
 *  draw panel's buttom bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x;
    S32 lsk_offset_y;
    S32 rsk_offset_x;
    S32 rsk_offset_y;
    S32 ck_offset_x;
    S32 ck_offset_y;
    S32 str_width;
    S32 str_height;
    S32 img_width;
    S32 img_height;
    S32 layer_offset_x;
    S32 layer_offset_y;    
    U16 image_id;

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    vdoply_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
    gdi_layer_push_and_set_active(g_vdoply_cntx.lsk_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    /* horizontal do not need draw buttom bar background */
    gdi_image_draw_id(
        g_vdoply_osd_cntx.softkey.rect.offset_x - layer_offset_x,
        g_vdoply_osd_cntx.softkey.rect.offset_y - layer_offset_y,
        IMG_ID_VDOPLY_OSD_BUTTOM_BAR_BG);

    gdi_layer_pop_and_restore_active();
#endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 
#ifdef __SF_MP4_SUPPORT__
    if(appex.bIsActive)
    {
        static const U16 __chs[]=  {0x9009,0x9879,0};  //Ñ¡Ïî  huyi-20080512  //{0x4E0B,0x8F7D,0};  //ÏÂÔØ
        												
        g_vdoply_cntx.lsk_str_ptr=(PS8)__chs;
    }
#endif //__SF_MP4_SUPPORT__
    if (g_vdoply_osd_cntx.softkey.is_lsk_icon == FALSE)
    {
        /* lsk string */
        if (g_vdoply_cntx.lsk_str_ptr != NULL)
        {

            wgui_softkey_get_offset((UI_string_type)g_vdoply_cntx.lsk_str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY);
            gui_measure_string((UI_string_type)g_vdoply_cntx.lsk_str_ptr, &str_width, &str_height);

            /* TRICKY, shift back from R to L MMI */
            if (r2lMMIFlag)
            {
                lsk_offset_x -= str_width;
            }

            if (g_vdoply_cntx.touch_lsk.is_press)
            {
                lsk_offset_x++;
                lsk_offset_y++;
            }

            gdi_layer_push_and_set_active(g_vdoply_cntx.lsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

            mmi_vdoply_draw_style_text(
                g_vdoply_cntx.lsk_str_ptr,
                lsk_offset_x - layer_offset_x,
                lsk_offset_y - layer_offset_y,
                &g_vdoply_osd_cntx.softkey.lsk_text);

            gdi_layer_pop_and_restore_active();

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            touch_p = &g_vdoply_cntx.touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 

        }
    }
    else
    {
        /* lsk */
        if (g_vdoply_cntx.lsk_img_id != 0)
        {
            if (!g_vdoply_cntx.touch_lsk.is_usable)
            {
                image_id = g_vdoply_cntx.lsk_img_id + 2;       
            }                 
            else if (g_vdoply_cntx.touch_lsk.is_press)
            {
                image_id = g_vdoply_cntx.lsk_img_id + 1;
            }
            else
            {
                image_id = g_vdoply_cntx.lsk_img_id;
            }


            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            lsk_offset_x = g_vdoply_osd_cntx.softkey.icon_lsk_pos.offset_x;
            lsk_offset_y = g_vdoply_osd_cntx.softkey.icon_lsk_pos.offset_y;

            gdi_layer_push_and_set_active(g_vdoply_cntx.lsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y); 
            
            gdi_image_draw_id(
                lsk_offset_x - layer_offset_x, 
                lsk_offset_y - layer_offset_y, 
                image_id);
                
            gdi_layer_pop_and_restore_active();
        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            /* remain these code if design change */
            touch_p = &g_vdoply_cntx.touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }

    }

    if (g_vdoply_osd_cntx.softkey.is_rsk_icon == FALSE)
    {
        /* rsk string */
        if (g_vdoply_cntx.rsk_str_ptr != NULL)
        {
            wgui_softkey_get_offset((UI_string_type)g_vdoply_cntx.rsk_str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY);
            gui_measure_string((UI_string_type) g_vdoply_cntx.rsk_str_ptr, &str_width, &str_height);

            /* TRICKY, shift back from R to L MMI */
            if (r2lMMIFlag)
            {
                rsk_offset_x -= str_width;
            }

            if (g_vdoply_cntx.touch_rsk.is_press)
            {
                rsk_offset_x++;
                rsk_offset_y++;
            }

            gdi_layer_push_and_set_active(g_vdoply_cntx.rsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y); 
 
            mmi_vdoply_draw_style_text(
                g_vdoply_cntx.rsk_str_ptr,
                rsk_offset_x - layer_offset_x,
                rsk_offset_y - layer_offset_y,
                &g_vdoply_osd_cntx.softkey.lsk_text);

            gdi_layer_pop_and_restore_active();
          
        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            touch_p = &g_vdoply_cntx.touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 

        }
    }
    else
    {
        /* rsk */
        if (g_vdoply_cntx.rsk_img_id != 0)
        {
            if (!g_vdoply_cntx.touch_rsk.is_usable)
            {
                image_id = g_vdoply_cntx.rsk_img_id + 2;       
            }            
            else if (g_vdoply_cntx.touch_rsk.is_press)
            {
                image_id = g_vdoply_cntx.rsk_img_id + 1;
            }
            else
            {
                image_id = g_vdoply_cntx.rsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            rsk_offset_x = g_vdoply_osd_cntx.softkey.icon_rsk_pos.offset_x;
            rsk_offset_y = g_vdoply_osd_cntx.softkey.icon_rsk_pos.offset_y;

            gdi_layer_push_and_set_active(g_vdoply_cntx.rsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);             
            
            gdi_image_draw_id(
                rsk_offset_x - layer_offset_x, 
                rsk_offset_y - layer_offset_y,
                image_id);

            gdi_layer_pop_and_restore_active();

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            touch_p = &g_vdoply_cntx.touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }
    }

    if (g_vdoply_osd_cntx.softkey.is_ck_icon)
    {

        /* draw c key */
        if (g_vdoply_cntx.ck_img_id != 0)
        {
            if (!g_vdoply_cntx.touch_ck.is_usable)
            {
                image_id = g_vdoply_cntx.ck_img_id + 2;       
            }
            else if (g_vdoply_cntx.touch_ck.is_press)
            {
                image_id = g_vdoply_cntx.ck_img_id + 1;
            }
            else
            {
                image_id = g_vdoply_cntx.ck_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            ck_offset_x = g_vdoply_osd_cntx.softkey.icon_ck_pos.offset_x;
            ck_offset_y = g_vdoply_osd_cntx.softkey.icon_ck_pos.offset_y;

            gdi_layer_push_and_set_active(g_vdoply_cntx.ck_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);  
            
            gdi_image_draw_id(
                ck_offset_x - layer_offset_x, 
                ck_offset_y - layer_offset_y,
                image_id);
            
            gdi_layer_pop_and_restore_active();

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            touch_p = &g_vdoply_cntx.touch_ck;
            touch_p->offset_x = ck_offset_x;
            touch_p->offset_y = ck_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_panel
 * DESCRIPTION
 *  draw panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoply_draw_panel_volume();
    mmi_vdoply_draw_panel_speed();
    mmi_vdoply_draw_panel_timer();
    mmi_vdoply_draw_panel_progress();
    mmi_vdoply_draw_panel_state();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_init_ui
 * DESCRIPTION
 *  init panel's UI item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_init_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digit_width;
    S32 col_width;
    S32 height;
    PU8 buf_ptr;
    
#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
    S32 region_0_buf_size;
    S32 region_1_buf_size;    
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    video_rect_struct *rect_ptr;
    video_osd_vodply_panel_struct *panel_ptr;
    video_osd_softkey_struct *sk_ptr;    
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
    video_pos_struct *pos_ptr;
    
#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    vdoply_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__    
    /* bg */
    /* newer cip has layer bg color, we can split bg into smaller region for better performance */
    /* we will use base layer's buffer to create two smaller layer region */

    /* region 0 */
    rect_ptr = &g_vdoply_osd_cntx.bg.region_0;

    region_0_buf_size = rect_ptr->width*rect_ptr->height*VDOPLY_BUFFER_DEPTH;
    g_vdoply_cntx.bg_region_0_buf_ptr = mmi_frm_scrmem_alloc(region_0_buf_size);

    MMI_ASSERT(g_vdoply_cntx.bg_region_0_buf_ptr != NULL);
    
    gdi_layer_create_using_outside_memory(
        rect_ptr->offset_x,
        rect_ptr->offset_y,
        rect_ptr->width,        
        rect_ptr->height,        
        &g_vdoply_cntx.bg_region_0_layer_handle,   
        (PU8)g_vdoply_cntx.bg_region_0_buf_ptr,
        (S32)region_0_buf_size);

    gdi_layer_push_and_set_active(g_vdoply_cntx.bg_region_0_layer_handle);       
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    /* region 1 */
    rect_ptr = &g_vdoply_osd_cntx.bg.region_1;    

    region_1_buf_size = rect_ptr->width*rect_ptr->height*VDOPLY_BUFFER_DEPTH;
    g_vdoply_cntx.bg_region_1_buf_ptr = mmi_frm_scrmem_alloc(region_1_buf_size);
    
    MMI_ASSERT(g_vdoply_cntx.bg_region_1_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        rect_ptr->offset_x,
        rect_ptr->offset_y,
        rect_ptr->width,        
        rect_ptr->height,        
        &g_vdoply_cntx.bg_region_1_layer_handle,   
        (PU8)g_vdoply_cntx.bg_region_1_buf_ptr,
        (S32)region_1_buf_size);

    gdi_layer_push_and_set_active(g_vdoply_cntx.bg_region_1_layer_handle);       
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_get_base_handle(&g_vdoply_cntx.bg_layer_handle);

#else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
    gdi_layer_get_base_handle(&g_vdoply_cntx.bg_layer_handle);
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */

    /* create loading layer */
    gdi_layer_create(
        g_vdoply_osd_cntx.loading.rect.offset_x,
        g_vdoply_osd_cntx.loading.rect.offset_y,                
        g_vdoply_osd_cntx.loading.rect.width,                 
        g_vdoply_osd_cntx.loading.rect.height,                                 
        &g_vdoply_cntx.process_layer_handle);

    gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();


#ifdef __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__
    /* create play wnd buffer */
    MMI_ASSERT(g_vdoply_cntx.vdo_frame_buf_ptr == NULL);
    media_get_int_buffer(MOD_MMI, (void**)&g_vdoply_cntx.vdo_frame_buf_ptr, VDOPLY_LAYER_BUFFER_SIZE);
    MMI_ASSERT(g_vdoply_cntx.vdo_frame_buf_ptr != NULL);

    gdi_layer_create_using_outside_memory(
        0, 
        0, 
        UI_device_width, 
        UI_device_height, 
        &g_vdoply_cntx.play_wnd_layer_handle, 
        (PU8)g_vdoply_cntx.vdo_frame_buf_ptr, 
        (S32)VDOPLY_LAYER_BUFFER_SIZE);

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    gdi_layer_create_using_outside_memory(
        0,
        0, 
        UI_device_height,
        UI_device_width,
        &g_vdoply_cntx.fullscr_play_layer_handle,
        (PU8)g_vdoply_cntx.vdo_frame_buf_ptr, 
        (S32)(VDOPLY_LAYER_BUFFER_SIZE));
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        
#else /* __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__ */
    /* create play wnd buffer */
    MMI_ASSERT(g_vdoply_cntx.vdo_frame_buf_ptr == NULL);

    gdi_layer_create(
        0, 
        0, 
        g_vdoply_osd_cntx.play_wnd.rect.width, 
        g_vdoply_osd_cntx.play_wnd.rect.height, 
        &g_vdoply_cntx.play_wnd_layer_handle);

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    /* create full screen layer using base layer's buffer */
    gdi_layer_get_base_handle(&g_vdoply_cntx.bg_layer_handle);

    gdi_layer_push_and_set_active(g_vdoply_cntx.bg_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();

    gdi_layer_create_using_outside_memory(
        0,
        0, 
        UI_device_height,
        UI_device_width,
        &g_vdoply_cntx.fullscr_play_layer_handle,
        (PU8)buf_ptr, 
        (S32)(VDOPLY_LAYER_BUFFER_SIZE));
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    
#endif /* __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__ */

    gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
    gdi_layer_resize(
        g_vdoply_osd_cntx.play_wnd.rect.width, 
        g_vdoply_osd_cntx.play_wnd.rect.height);
    gdi_lcd_set_rotate(g_vdoply_cntx.normal_style_rotate);

    gdi_layer_set_position(
        g_vdoply_osd_cntx.play_wnd.rect.offset_x, 
        g_vdoply_osd_cntx.play_wnd.rect.offset_y);

    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
 

#define ASSIGN_DRAW_LAYER(__offset_x__, __offset_y__, __draw_layer__)       \
do {                                                                        \
    video_rect_struct *rect_0_ptr;                                          \
    video_rect_struct *rect_1_ptr;                                          \
    __draw_layer__ = GDI_LAYER_EMPTY_HANDLE;                                \
    rect_0_ptr = &g_vdoply_osd_cntx.bg.region_0;                            \
    rect_1_ptr = &g_vdoply_osd_cntx.bg.region_1;                            \
    if ((__offset_x__ >= rect_0_ptr->offset_x) &&                           \
        (__offset_x__ <= rect_0_ptr->offset_x+rect_0_ptr->width) &&         \
        (__offset_y__ >= rect_0_ptr->offset_y) &&                           \
        (__offset_y__ <= rect_0_ptr->offset_y+rect_0_ptr->height))          \
    {                                                                       \
        __draw_layer__ = g_vdoply_cntx.bg_region_0_layer_handle;            \
    }                                                                       \
    else if ((__offset_x__ >= rect_1_ptr->offset_x) &&                      \
             (__offset_x__ <= rect_1_ptr->offset_x+rect_1_ptr->width) &&    \
             (__offset_y__ >= rect_1_ptr->offset_y) &&                      \
             (__offset_y__ <= rect_1_ptr->offset_y+rect_1_ptr->height))     \
    {                                                                       \
        __draw_layer__ = g_vdoply_cntx.bg_region_1_layer_handle;            \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        /* object not within any region */                                  \
        MMI_ASSERT(0);                                                      \
    }                                                                       \
} while(0);




#define INIT_TOUCH_OBJ(__x__, __X__)                                                                 \
do {                                                                                                 \
    touch_p = &g_vdoply_cntx.touch_##__x__##;                                                        \
    touch_p->offset_x = g_vdoply_osd_cntx.panel.##__x__##.offset_x;                                  \
    touch_p->offset_y = g_vdoply_osd_cntx.panel.##__x__##.offset_y;                                  \
    touch_p->is_press = FALSE;                                                                       \
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_TOUCH_OSD_##__X__##, &touch_p->width, &touch_p->height);\
} while(0);

#define INIT_TOUCH_FULL_OBJ(__x__, __X__)                                                                 \
do {                                                                                                      \
    touch_p = &g_vdoply_cntx.full_touch_##__x__##;                                                        \
    touch_p->offset_x = g_vdoply_fullscr_osd_cntx.panel.##__x__##.offset_x;                               \
    touch_p->offset_y = g_vdoply_fullscr_osd_cntx.panel.##__x__##.offset_y;                               \
    touch_p->is_press = FALSE;                                                                            \
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_TOUCH_FULL_OSD_##__X__##, &touch_p->width, &touch_p->height);\
} while(0);


    /* timer */
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_TIMER_COL, &col_width, &height);
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_TIMER_0, &digit_width, &height);

    pos_ptr = &g_vdoply_osd_cntx.panel.timer;
    
    g_vdoply_cntx.timer.offset_y = pos_ptr->offset_y;

    g_vdoply_cntx.timer.hr_0_offset_x = pos_ptr->offset_x;
    g_vdoply_cntx.timer.hr_1_offset_x = g_vdoply_cntx.timer.hr_0_offset_x + digit_width;
    g_vdoply_cntx.timer.col_0_offset_x = g_vdoply_cntx.timer.hr_1_offset_x + digit_width;
    g_vdoply_cntx.timer.min_0_offset_x = g_vdoply_cntx.timer.col_0_offset_x + col_width;
    g_vdoply_cntx.timer.min_1_offset_x = g_vdoply_cntx.timer.min_0_offset_x + digit_width;
    g_vdoply_cntx.timer.col_1_offset_x = g_vdoply_cntx.timer.min_1_offset_x + digit_width;
    g_vdoply_cntx.timer.sec_0_offset_x = g_vdoply_cntx.timer.col_1_offset_x + col_width;
    g_vdoply_cntx.timer.sec_1_offset_x = g_vdoply_cntx.timer.sec_0_offset_x + digit_width;


#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;

    /* init touch obj region */
    INIT_TOUCH_OBJ(speed_inc, SPEED_INC);
    INIT_TOUCH_OBJ(speed_dec, SPEED_DEC);
    INIT_TOUCH_OBJ(volume_inc, VOLUME_INC);
    INIT_TOUCH_OBJ(volume_dec, VOLUME_DEC);
    INIT_TOUCH_OBJ(progress_inc, PROGRESS_INC);
    INIT_TOUCH_OBJ(progress_dec, PROGRESS_DEC);
    INIT_TOUCH_OBJ(snapshot, SNAPSHOT);
    INIT_TOUCH_OBJ(fullscreen, FULLSCREEN);
    
    /* progress bar */
    touch_p = &g_vdoply_cntx.touch_progress_bar;
    touch_p->offset_x = g_vdoply_osd_cntx.panel.progress_empty.offset_x;
    touch_p->offset_y = g_vdoply_osd_cntx.panel.progress_empty.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY, &touch_p->width, &touch_p->height);
    g_vdoply_cntx.progress.fill_width = touch_p->width;
    g_vdoply_cntx.progress.fill_height = touch_p->height;   

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    INIT_TOUCH_FULL_OBJ(speed_inc, SPEED_INC);
    INIT_TOUCH_FULL_OBJ(speed_dec, SPEED_DEC);
    INIT_TOUCH_FULL_OBJ(volume_inc, VOLUME_INC);
    INIT_TOUCH_FULL_OBJ(volume_dec, VOLUME_DEC);
    INIT_TOUCH_FULL_OBJ(progress_inc, PROGRESS_INC);
    INIT_TOUCH_FULL_OBJ(progress_dec, PROGRESS_DEC);

    /* progress bar */
    touch_p = &g_vdoply_cntx.full_touch_progress_bar;
    touch_p->offset_x = g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x;
    touch_p->offset_y = g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_EMPTY, &touch_p->width, &touch_p->height);
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
#else /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 

    gdi_image_get_dimension_id(
        IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY, 
        &g_vdoply_cntx.progress.fill_width, 
        &g_vdoply_cntx.progress.fill_height);

    g_vdoply_cntx.touch_speed_inc.is_press = FALSE;
    g_vdoply_cntx.touch_speed_dec.is_press = FALSE;
    g_vdoply_cntx.touch_volume_inc.is_press = FALSE;
    g_vdoply_cntx.touch_volume_dec.is_press = FALSE;
    g_vdoply_cntx.touch_progress_inc.is_press = FALSE;
    g_vdoply_cntx.touch_progress_dec.is_press = FALSE;
    g_vdoply_cntx.touch_snapshot.is_press = FALSE;
    g_vdoply_cntx.touch_fullscreen.is_press = FALSE;
    g_vdoply_cntx.touch_progress_bar.is_press = FALSE;

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    g_vdoply_cntx.full_touch_speed_inc.is_press = FALSE;
    g_vdoply_cntx.full_touch_speed_dec.is_press = FALSE;
    g_vdoply_cntx.full_touch_volume_inc.is_press = FALSE;
    g_vdoply_cntx.full_touch_volume_dec.is_press = FALSE;
    g_vdoply_cntx.full_touch_progress_inc.is_press = FALSE;
    g_vdoply_cntx.full_touch_progress_dec.is_press = FALSE;
    g_vdoply_cntx.full_touch_progress_bar.is_press = FALSE;
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

#endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 

#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ 
    panel_ptr = &g_vdoply_osd_cntx.panel;
    ASSIGN_DRAW_LAYER(panel_ptr->speed.offset_x, panel_ptr->speed.offset_y, g_vdoply_cntx.speed_draw_layer);
    ASSIGN_DRAW_LAYER(panel_ptr->volume.offset_x, panel_ptr->volume.offset_y, g_vdoply_cntx.volume_draw_layer);    
    ASSIGN_DRAW_LAYER(panel_ptr->progress_empty.offset_x, panel_ptr->progress_empty.offset_y, g_vdoply_cntx.progress_draw_layer);       
    ASSIGN_DRAW_LAYER(panel_ptr->snapshot.offset_x, panel_ptr->snapshot.offset_y, g_vdoply_cntx.snapshot_draw_layer);           
    ASSIGN_DRAW_LAYER(panel_ptr->fullscreen.offset_x, panel_ptr->fullscreen.offset_y, g_vdoply_cntx.fullscreen_draw_layer);
    ASSIGN_DRAW_LAYER(panel_ptr->timer.offset_x, panel_ptr->timer.offset_y, g_vdoply_cntx.timer_draw_layer);

    sk_ptr = &g_vdoply_osd_cntx.softkey;
    ASSIGN_DRAW_LAYER(sk_ptr->icon_ck_pos.offset_x, sk_ptr->icon_ck_pos.offset_y, g_vdoply_cntx.ck_draw_layer); 

    if (sk_ptr->is_lsk_icon)
    {
        ASSIGN_DRAW_LAYER(sk_ptr->icon_lsk_pos.offset_x, sk_ptr->icon_lsk_pos.offset_y, g_vdoply_cntx.lsk_draw_layer);        
    }
    else
    {
        gui_measure_string((UI_string_type)L"Test", &str_width, &str_height);    
        offset_x = 2;
        offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 1;
        ASSIGN_DRAW_LAYER(offset_x, offset_y, g_vdoply_cntx.lsk_draw_layer);        
    }

    if (sk_ptr->is_rsk_icon)
    {
        ASSIGN_DRAW_LAYER(sk_ptr->icon_rsk_pos.offset_x, sk_ptr->icon_rsk_pos.offset_y, g_vdoply_cntx.rsk_draw_layer);        
    }
    else
    {
        gui_measure_string((UI_string_type)L"Test", &str_width, &str_height);    
        offset_x = UI_device_width - str_width - 2;
        offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 1;
        ASSIGN_DRAW_LAYER(offset_x, offset_y, g_vdoply_cntx.rsk_draw_layer);        
    }

    if ((g_vdoply_osd_cntx.title.is_draw_filename) || (g_vdoply_osd_cntx.title.is_draw_app_name))
    {
        ASSIGN_DRAW_LAYER(
            g_vdoply_osd_cntx.title.rect.offset_x,\
            g_vdoply_osd_cntx.title.rect.offset_y,\
            g_vdoply_cntx.title_draw_layer);
    }

#else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
    g_vdoply_cntx.speed_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.volume_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.progress_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.snapshot_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.fullscreen_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.rsk_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.lsk_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.ck_draw_layer = g_vdoply_cntx.bg_layer_handle; 
    g_vdoply_cntx.title_draw_layer = g_vdoply_cntx.bg_layer_handle;
    g_vdoply_cntx.timer_draw_layer = g_vdoply_cntx.bg_layer_handle;
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
 

}



#ifdef __VDOPLY_FEATURE_FULLSCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_aud_only_anim
 * DESCRIPTION
 *  draw audio only animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_aud_only_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width, layer_height;
    S32 image_width, image_height;
    S32 offset_x, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
    {    
        gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
        gdi_layer_get_dimension(&layer_width, &layer_height);

        gdi_layer_clear(GDI_COLOR_BLACK);

        gdi_image_get_dimension_id(
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM,
            &image_width,
            &image_height);

        offset_x = (layer_width - image_width) >> 1;
        offset_y = (layer_height - image_height) >> 1;                    

        gdi_image_draw_animation_id(
            offset_x, 
            offset_y, 
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM,
            &g_vdoply_cntx.aud_only_anim);

        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_play_region_bg
 * DESCRIPTION
 *  draw audio only animation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_play_region_bg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_width, layer_height;
    S32 image_width, image_height;
    S32 offset_x, offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
    {    
        gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
        gdi_layer_get_dimension(&layer_width, &layer_height);

        gdi_layer_clear(GDI_COLOR_BLACK);

        gdi_image_get_dimension_id(
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM,
            &image_width,
            &image_height);

        offset_x = (layer_width - image_width) >> 1;
        offset_y = (layer_height - image_height) >> 1;                    

        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            IMG_ID_VDOPLY_OSD_AUD_ONLY_ANIM);

        gdi_layer_pop_and_restore_active();
    }
    else
    {
        gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();        
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_aud_only_anim
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_fullscr_aud_only_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.aud_only_anim != GDI_NULL_HANDLE)
    {
        gdi_image_stop_animation(g_vdoply_cntx.aud_only_anim);
        g_vdoply_cntx.aud_only_anim = GDI_NULL_HANDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_panel_progress
 * DESCRIPTION
 *  draw fullscreen panel's progress bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_panel_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoply_cntx.osd_layer_handle);

    if (!g_vdoply_cntx.is_progress_seekable)
    {
        /* can not seek, we will show disable progress bar */
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_y,
            (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_DIS));

        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC_DIS);

        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC_DIS);

        gdi_layer_pop_and_restore_active();

        return;
    }

    /* draw empty first */
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x,
        g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_EMPTY));

#ifdef __MMI_VIDEO_PDL__
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
    {
        if (g_vdoply_cntx.cur_status.buff_ratio != 0)
        {
            /* draw inside filling */
            offset_x = g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_x;
            offset_y = g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_y;

            gdi_layer_set_clip(
                offset_x,
                offset_y,
                offset_x + g_vdoply_cntx.cur_status.buff_ratio,
                offset_y + g_vdoply_cntx.progress.fill_height);

            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_y,
                (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_BUFFER));

            gdi_layer_reset_clip();        
        }
    }
#endif /* __MMI_VIDEO_PDL__ */

    if (g_vdoply_cntx.cur_status.play_ratio != 0)
    {
        /* draw inside filling */
        offset_x = g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_x;
        offset_y = g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_y;

        gdi_layer_set_clip(
            offset_x,
            offset_y,
            offset_x + g_vdoply_cntx.cur_status.play_ratio,
            offset_y + g_vdoply_cntx.fullscr_progress.fill_height);

        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_fill.offset_y,
            (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_FILL));
        
        gdi_layer_reset_clip();        
    }

    /* progress inc */

    if (!g_vdoply_cntx.full_touch_progress_inc.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC_DIS);
    }
    else if (g_vdoply_cntx.full_touch_progress_inc.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC_SEL);
    }
    else
    {

        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_INC);
    }

    /* progress dec */
    if (!g_vdoply_cntx.full_touch_progress_dec.is_usable)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC_DIS);
    }    
    else if (g_vdoply_cntx.full_touch_progress_dec.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC_SEL);
    }
    else
    {

        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.progress_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_PROGRESS_DEC);
    }

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_panel_timer
 * DESCRIPTION
 *  draw fullscreen panel's timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_draw_fullscr_panel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 time;
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    time = (U32) (g_vdoply_cntx.cur_status.play_time / 1000);

    hour = time / 3600;
    hour_remain = time % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (hour > 99)
    {
        hour = 99;
    }

    /* hr */
    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.hr_0_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0 + (U16) hour / 10));

    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.hr_1_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0 + (U16) hour % 10));

    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.col_0_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_COL));

    /* min */
    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.min_0_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0 + (U16) min / 10));

    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.min_1_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0 + (U16) min % 10));

    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.col_1_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_COL));

    /* sec */
    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.sec_0_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0 + (U16) sec / 10));

    gdi_image_draw_id(
        g_vdoply_cntx.fullscr_timer.sec_1_offset_x,
        g_vdoply_cntx.fullscr_timer.offset_y,
        (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0 + (U16) sec % 10));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_panel_speed
 * DESCRIPTION
 *  draw fullscreen panel's speed icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_panel_speed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_SPEED__
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.panel.speed.offset_x,
        g_vdoply_fullscr_osd_cntx.panel.speed.offset_y,
        mmi_vdoply_fullscr_get_speed_image());


#ifdef __MMI_VIDEO_STREAM__
    /* if is streaming, disable */
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC_DIS);
            
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC_DIS);

        return;
    }
#endif /* __MMI_VIDEO_STREAM__ */



    /* speed inc */
    if (g_vdoply_cntx.full_touch_speed_inc.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC_SEL);
    }
    else
    {

        if (g_vdoply_cntx.cur_status.speed < VDOPLY_FEATURE_SPEED_COUNT - 1)
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC);

        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.speed_inc.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_INC_DIS);

        }
    }

    /* speed dec */
    if (g_vdoply_cntx.full_touch_speed_dec.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC_SEL);
    }
    else
    {
        if (g_vdoply_cntx.cur_status.speed > 0)
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.speed_dec.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_SPEED_DEC_DIS);
        }
    }

#endif /* __VDOPLY_FEATURE_SPEED__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_panel_volume
 * DESCRIPTION
 *  draw fullscreen panel's volumn icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_panel_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_VOLUME__

    if (g_vdoply_cntx.is_mute)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.volume.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.volume.offset_y,
            IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_MUTE);
    }
    else
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.volume.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.volume.offset_y,
            (U16) (IMG_ID_VDOPLY_FULLSCR_OSD_VOLUME_START + g_vdoply_cntx.cur_status.volume + 1));

    }

    /* vol inc */
    if (g_vdoply_cntx.full_touch_volume_inc.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.volume_inc.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.volume_inc.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_INC_SEL);
    }
    else
    {
        if (g_vdoply_cntx.cur_status.volume < VDOPLY_VOL_16)
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.volume_inc.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.volume_inc.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_INC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.volume_inc.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.volume_inc.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_INC_DIS);
        }
    }

    /* vol dec */
    if (g_vdoply_cntx.full_touch_volume_dec.is_press)
    {
        gdi_image_draw_id(
            g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_x,
            g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_y,
            IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC_SEL);
    }
    else
    {
    #ifdef __VDOPLY_FEATURE_VOLUME_MUTE__
        if (!g_vdoply_cntx.is_mute)
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC_DIS);
        }
    #else /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 
        if (g_vdoply_cntx.cur_status.volume > VDOPLY_VOL_1)
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_x,
                g_vdoply_fullscr_osd_cntx.panel.volume_dec.offset_y,
                IMG_ID_VDOPLY_TOUCH_FULL_OSD_VOLUME_DEC_DIS);
        }
    #endif /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 

    }

#endif /* __VDOPLY_FEATURE_VOLUME__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_softkey
 * DESCRIPTION
 *  draw fullscreen's softkey
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x;
    S32 lsk_offset_y;
    S32 rsk_offset_x;
    S32 rsk_offset_y;
    S32 str_width;
    S32 str_height;
    S32 spacing;
    U16 image_id;
    S32 img_width;
    S32 img_height;
    S32 ck_offset_x;
    S32 ck_offset_y;

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    vdoply_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_FULLSCR_OSD_BG, &img_width, &img_height);

    gdi_draw_solid_rect(
        g_vdoply_fullscr_osd_cntx.panel.bg.offset_x + img_width + 1,
        0,
        UI_DEVICE_HEIGHT,
        UI_DEVICE_WIDTH,
        GDI_COLOR_TRANSPARENT);

    /* lsk */
    if (g_vdoply_fullscr_osd_cntx.softkey.is_lsk_icon == FALSE)
    {
        if (g_vdoply_cntx.lsk_str_ptr != NULL)
        {
            gui_measure_string((UI_string_type) g_vdoply_cntx.lsk_str_ptr, &str_width, &str_height);
            spacing = (MMI_SOFTKEY_HEIGHT - str_height) >> 1;

            lsk_offset_x = UI_device_height - str_width - spacing;
            lsk_offset_y = UI_device_width - str_height - spacing;

            if (g_vdoply_cntx.full_touch_lsk.is_press)
            {
                lsk_offset_x++;
                lsk_offset_y++;
            }

            mmi_vdoply_draw_style_text(
                g_vdoply_cntx.lsk_str_ptr,
                lsk_offset_x,
                lsk_offset_y,
                &g_vdoply_fullscr_osd_cntx.softkey.lsk_text);

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            touch_p = &g_vdoply_cntx.full_touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }
    }
    else
    {
        /* lsk */
        if (g_vdoply_cntx.lsk_img_id != 0)
        {
            if (!g_vdoply_cntx.full_touch_lsk.is_usable)
            {
                image_id = g_vdoply_cntx.lsk_img_id + 2;       
            }                           
            else if (g_vdoply_cntx.full_touch_lsk.is_press)
            {
                image_id = g_vdoply_cntx.lsk_img_id + 1;
            }
            else
            {
                image_id = g_vdoply_cntx.lsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            lsk_offset_x = g_vdoply_fullscr_osd_cntx.softkey.icon_lsk_pos.offset_x;
            lsk_offset_y = g_vdoply_fullscr_osd_cntx.softkey.icon_lsk_pos.offset_y;

            gdi_image_draw_id(lsk_offset_x, lsk_offset_y, image_id);

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            /* remain these code if design change */
            touch_p = &g_vdoply_cntx.full_touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }

    }

    /* rsk */
    if (g_vdoply_fullscr_osd_cntx.softkey.is_rsk_icon == FALSE)
    {
        if (g_vdoply_cntx.rsk_str_ptr != NULL)
        {
            gui_measure_string((UI_string_type) g_vdoply_cntx.rsk_str_ptr, &str_width, &str_height);
            spacing = (MMI_SOFTKEY_HEIGHT - str_height) >> 1;

            rsk_offset_x = UI_device_height - str_width - spacing;
            rsk_offset_y = spacing;

            if (g_vdoply_cntx.full_touch_rsk.is_press)
            {
                rsk_offset_x++;
                rsk_offset_y++;
            }

            mmi_vdoply_draw_style_text(
                g_vdoply_cntx.rsk_str_ptr,
                rsk_offset_x,
                rsk_offset_y,
                &g_vdoply_fullscr_osd_cntx.softkey.rsk_text);

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__

            touch_p = &g_vdoply_cntx.full_touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;

        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 

        }
    }
    else
    {

        /* rsk */
        if (g_vdoply_cntx.rsk_img_id != 0)
        {
            if (!g_vdoply_cntx.full_touch_rsk.is_usable)
            {
                image_id = g_vdoply_cntx.rsk_img_id + 2;       
            }                
            else if (g_vdoply_cntx.full_touch_rsk.is_press)
            {
                image_id = g_vdoply_cntx.rsk_img_id + 1;
            }
            else
            {
                image_id = g_vdoply_cntx.rsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            rsk_offset_x = g_vdoply_fullscr_osd_cntx.softkey.icon_rsk_pos.offset_x;
            rsk_offset_y = g_vdoply_fullscr_osd_cntx.softkey.icon_rsk_pos.offset_y;

            gdi_image_draw_id(rsk_offset_x, rsk_offset_y, image_id);

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            /* remain these code if design change */
            touch_p = &g_vdoply_cntx.full_touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }
    }

    /* ck */
    if (g_vdoply_fullscr_osd_cntx.softkey.is_ck_icon)
    {
        /* draw c key */
        if (g_vdoply_cntx.ck_img_id != 0)
        {

            if (!g_vdoply_cntx.full_touch_ck.is_usable)
            {
                image_id = g_vdoply_cntx.ck_img_id + 2;       
            }               
            else if (g_vdoply_cntx.full_touch_ck.is_press)
            {
                image_id = g_vdoply_cntx.ck_img_id + 1;
            }
            else
            {
                image_id = g_vdoply_cntx.ck_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            ck_offset_x = g_vdoply_fullscr_osd_cntx.softkey.icon_ck_pos.offset_x;
            ck_offset_y = g_vdoply_fullscr_osd_cntx.softkey.icon_ck_pos.offset_y;

            gdi_image_draw_id(ck_offset_x, ck_offset_y, image_id);

        #ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
            touch_p = &g_vdoply_cntx.full_touch_ck;
            touch_p->offset_x = ck_offset_x;
            touch_p->offset_y = ck_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
        #endif /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */ 
        }
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_loading
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_STREAM__
static void mmi_vdoply_draw_fullscr_loading(S32 percentage, MMI_BOOL draw_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 draw_width;
    S32 offset_x;
    S32 offset_y;   
    S32 layer_offset_x;
    S32 layer_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);

    layer_offset_x = g_vdoply_fullscr_osd_cntx.loading.rect.offset_x;
    layer_offset_y = g_vdoply_fullscr_osd_cntx.loading.rect.offset_y;    
    
    gdi_layer_set_position(layer_offset_x, layer_offset_y);
    
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.loading.bg.offset_x - layer_offset_x,
        g_vdoply_fullscr_osd_cntx.loading.bg.offset_y - layer_offset_y,
        IMG_ID_VDOPLY_OSD_LOADING_BG);

    if (g_vdoply_fullscr_osd_cntx.loading.is_draw_progress)
    {
        gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_LOADING_EMPTY, &image_width, &image_height);

        offset_x = g_vdoply_fullscr_osd_cntx.loading.progress.offset_x - layer_offset_x;
        offset_y = g_vdoply_fullscr_osd_cntx.loading.progress.offset_y - layer_offset_y;
    
        /* draw empty loading bar */
        gdi_image_draw_id(
            offset_x,
            offset_y,
            IMG_ID_VDOPLY_OSD_LOADING_EMPTY);

        draw_width = image_width * percentage / 100;

        gdi_layer_set_clip(
            offset_x,
            offset_y,
            offset_x + draw_width,
            offset_y + image_height);

        gdi_image_draw_id(
            offset_x,
            offset_y,
            IMG_ID_VDOPLY_OSD_LOADING_FILL);

        gdi_layer_reset_clip();            
    }

    gdi_layer_pop_and_restore_active();
   
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_connecting_anim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.connecting_anim == GDI_NULL_HANDLE)
    {    
        gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);

        layer_offset_x = g_vdoply_fullscr_osd_cntx.loading.rect.offset_x;
        layer_offset_y = g_vdoply_fullscr_osd_cntx.loading.rect.offset_y;    
        
        gdi_layer_set_position(layer_offset_x, layer_offset_y);
        
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        gdi_image_draw_animation_id(
            g_vdoply_fullscr_osd_cntx.loading.bg.offset_x - layer_offset_x,
            g_vdoply_fullscr_osd_cntx.loading.bg.offset_y - layer_offset_y,
            IMG_ID_VDOPLY_OSD_CONNECTING,
            &g_vdoply_cntx.connecting_anim);

        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_fullscr_connecting_anim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_fullscr_connecting_anim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    if (g_vdoply_cntx.connecting_anim)
    {
        gdi_image_stop_animation(g_vdoply_cntx.connecting_anim);
        g_vdoply_cntx.connecting_anim = GDI_NULL_HANDLE;
    }
}
#endif /* __MMI_VIDEO_STREAM__  */

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_fullscr_osd
 * DESCRIPTION
 *  draw fullscreen panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_draw_fullscr_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__    
    gdi_layer_push_and_set_active(g_vdoply_cntx.osd_layer_handle);

    gdi_layer_toggle_double();
    gdi_layer_lock_frame_buffer();
   
    mmi_vdoply_draw_fullscr_softkey();
    mmi_vdoply_draw_fullscr_panel_volume();
    mmi_vdoply_draw_fullscr_panel_speed();
    mmi_vdoply_draw_fullscr_panel_timer();
    mmi_vdoply_draw_fullscr_panel_progress();

    gdi_layer_unlock_frame_buffer();

    gdi_layer_pop_and_restore_active();
#endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clear_fullscr_osd
 * DESCRIPTION
 *  clear fullscreen panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_clear_fullscr_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__     
   /* draw fullscr OSD background */
    gdi_layer_push_and_set_active(g_vdoply_cntx.osd_layer_handle);

    gdi_layer_set_opacity(TRUE, (U8) g_vdoply_cntx.fullscr_osd_opacity);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.panel.bg.offset_x,
        g_vdoply_fullscr_osd_cntx.panel.bg.offset_y,
        IMG_ID_VDOPLY_FULLSCR_OSD_BG);

#ifndef __VDOPLY_FEATURE_HIDE_TIMER__
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.panel.timer_bg.offset_x,
        g_vdoply_fullscr_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_BG);
#endif /* __VDOPLY_FEATURE_HIDE_TIMER__ */

    gdi_layer_toggle_double();

    gdi_layer_set_opacity(TRUE, (U8) g_vdoply_cntx.fullscr_osd_opacity);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.panel.bg.offset_x,
        g_vdoply_fullscr_osd_cntx.panel.bg.offset_y,
        IMG_ID_VDOPLY_FULLSCR_OSD_BG);

#ifndef __VDOPLY_FEATURE_HIDE_TIMER__
    gdi_image_draw_id(
        g_vdoply_fullscr_osd_cntx.panel.timer_bg.offset_x,
        g_vdoply_fullscr_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_BG);
#endif /* __VDOPLY_FEATURE_HIDE_TIMER__ */

    gdi_layer_pop_and_restore_active(); 
#endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */    
}
 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_init_fullscr_ui
 * DESCRIPTION
 *  init fullscreen panel's UI item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_init_fullscr_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digit_width;
    S32 col_width;
    S32 height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* timer */
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_COL, &col_width, &height);
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_FULLSCR_OSD_TIMER_0, &digit_width, &height);

    g_vdoply_cntx.fullscr_timer.offset_y = g_vdoply_fullscr_osd_cntx.panel.timer.offset_y;
    g_vdoply_cntx.fullscr_timer.hr_0_offset_x = g_vdoply_fullscr_osd_cntx.panel.timer.offset_x;
    g_vdoply_cntx.fullscr_timer.hr_1_offset_x = g_vdoply_cntx.fullscr_timer.hr_0_offset_x + digit_width;
    g_vdoply_cntx.fullscr_timer.col_0_offset_x = g_vdoply_cntx.fullscr_timer.hr_1_offset_x + digit_width;
    g_vdoply_cntx.fullscr_timer.min_0_offset_x = g_vdoply_cntx.fullscr_timer.col_0_offset_x + col_width;
    g_vdoply_cntx.fullscr_timer.min_1_offset_x = g_vdoply_cntx.fullscr_timer.min_0_offset_x + digit_width;
    g_vdoply_cntx.fullscr_timer.col_1_offset_x = g_vdoply_cntx.fullscr_timer.min_1_offset_x + digit_width;
    g_vdoply_cntx.fullscr_timer.sec_0_offset_x = g_vdoply_cntx.fullscr_timer.col_1_offset_x + col_width;
    g_vdoply_cntx.fullscr_timer.sec_1_offset_x = g_vdoply_cntx.fullscr_timer.sec_0_offset_x + digit_width;

    /* progress */
    gdi_image_get_dimension_id(
        IMG_ID_VDOPLY_FULLSCR_OSD_PROGRESS_FILL,
        &g_vdoply_cntx.fullscr_progress.fill_width,
        &g_vdoply_cntx.fullscr_progress.fill_height);
  
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_fullscr_reset_osd_fade
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_fullscr_reset_osd_fade(BOOL sleep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);

    if (g_vdoply_cntx.fullscr_osd_opacity != 255)
    {
        /* fade in from totally trasnparent */
        if (g_vdoply_cntx.fullscr_osd_opacity == 0)
        {
            mmi_vdoply_draw_fullscr_osd();
        }

        g_vdoply_cntx.fullscr_osd_opacity = 255;

        gdi_layer_push_and_set_active(g_vdoply_cntx.osd_layer_handle);
        gdi_layer_set_opacity(TRUE, (U8) g_vdoply_cntx.fullscr_osd_opacity);
        gdi_layer_pop_and_restore_active();
    }

    if (sleep)
    {
        /* start fade out timer */
        gui_start_timer(VDOPLY_OSD_FADE_OUT_TIME, mmi_vdoply_fullscr_osd_fade_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_fullscr_osd_fade_cyclic
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_fullscr_osd_fade_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset fullscreen osd fade out timer */
    if (g_vdoply_cntx.fullscr_osd_opacity > VDOPLY_OSD_FADE_OUT_VALUE)
    {
        g_vdoply_cntx.fullscr_osd_opacity -= VDOPLY_OSD_FADE_OUT_VALUE;

        gui_start_timer(100, mmi_vdoply_fullscr_osd_fade_cyclic);
    }
    else
    {
        g_vdoply_cntx.touch_lsk.is_press = FALSE;
        g_vdoply_cntx.touch_rsk.is_press = FALSE;
        g_vdoply_cntx.touch_ck.is_press = FALSE;

        g_vdoply_cntx.fullscr_osd_opacity = 0;

        /* if totally fade out, use any key to wake up */
        ClearInputEventHandler(MMI_DEVICE_KEY);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_1, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_2, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_3, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_4, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_5, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_6, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_7, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_8, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_9, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_POUND, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_LSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_ENTER, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_CLEAR, KEY_EVENT_UP);

        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoply_fullscr_osd_show_up, KEY_VOL_DOWN, KEY_EVENT_UP);

        /* start still use for toggle screen */
        SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);

    }

    gdi_layer_push_and_set_active(g_vdoply_cntx.osd_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) g_vdoply_cntx.fullscr_osd_opacity);
    gdi_layer_pop_and_restore_active();

    mmi_vdoply_blt_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_fullscr_osd_show_up
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_fullscr_osd_show_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoply_set_state_key_event(g_vdoply_cntx.state);
    mmi_vdoply_fullscr_reset_osd_fade(TRUE);

    mmi_vdoply_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_fullscr_get_speed_image
 * DESCRIPTION
 *  fade fullscr osd
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_vdoply_fullscr_get_speed_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 speed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    speed = mmi_vdoply_get_speed_factor();

#ifndef __VDOPLY_FEATURE_FWD_BWD_SPEED__
    switch (speed)
    {
        case 50:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_50;
            break;

        case 75:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_75;
            break;

        case 100:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_100;
            break;

        case 125:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_125;
            break;

        case 150:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_150;
            break;

        case 200:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_200;
            break;

        case 400:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_400;
            break;

        case 800:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_800;
            break;

        default:
            return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_UNDEF;
            break;

    }
#else /* __VDOPLY_FEATURE_FWD_BWD_SPEED__ */ 

    if (speed > 0)
    {
        return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_FWD;
    }
    else if (speed < 0)
    {
        return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_FWD;
    }
    else
    {
        return IMG_ID_VDOPLY_FULLSCR_OSD_SPEED_UNDEF;
    }

#endif /* __VDOPLY_FEATURE_FWD_BWD_SPEED__ */ 

}
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_next_snapshot_filename
 * DESCRIPTION
 *  get next file name to be snapshot
 * PARAMETERS
 *  file_buf        [OUT]       Filename buffer ptr
 *  file_path       [IN]        Filepath
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_SNAPSHOT__
void mmi_vdoply_get_next_snapshot_filename(PS8 file_buf, PS8 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get/store sequentail number */
    ReadValue(NVRAM_VDOPLY_SNAPSHOT_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        /* TODO: if seq no turn around, add some protection */
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }
    WriteValue(NVRAM_VDOPLY_SNAPSHOT_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;

    sprintf((PS8) buffer, "SNP%04d", filename_seq_no);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);

    while (1)
    {
        sprintf((PS8) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((PS8) UCS2_alpha, (PS8) buffer);

        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (PS8) L".jpg");

        mmi_ucs2ncpy((PS8) file_buf, (PS8) file_path, FMGR_MAX_PATH_LEN);
        mmi_ucs2cat((PS8) file_buf, (PS8) UCS2_testname);

        file_handle = FS_Open((U16*) file_buf, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            /* file not exit. return */
            return;
        }

        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count - 1)
        {
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_snapshot
 * DESCRIPTION
 *  snapshot current play screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_player_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_pathname[FMGR_PATH_BUFFER_SIZE];
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    MDI_RESULT ret;
    MDI_RESULT snap_ret;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.is_seeking)
    {
        /* if is seeking, do not take snapshot, this may avoid delay timer and NVRAM access problem */
        return;
    }

    /* already exit */
    if (GetExitScrnID() != SCR_ID_VDOPLY_PLAYER)
    {
        return;
    }

    memset(buf_pathname, 0, FMGR_PATH_BUFFER_SIZE);

    /* init value */
    ret = 0;

    /* check if storage path is valid or not */
    if (mmi_camera_check_and_restore_valid_drv())
    {
        /* if drv is valid, check if the folder is crated or not */
        mmi_imgview_get_storage_file_path(buf_pathname);
        create_result = mmi_imgview_create_file_dir(buf_pathname);

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            ret = MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION;
        }
        else if (create_result == FS_DISK_FULL)
        {
            ret = MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL;
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            ret = MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL;
        }
        else
        {
            /* no error */
            ret = MDI_RES_VDOPLY_SUCCEED;
        }

        /* error check */
        if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)      /* ture means has error popup */
        {
            return;
        }
    }
    else
    {
    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    #else /* __USB_IN_NORMAL_MODE__ */
        MMI_ASSERT(0);
    #endif /* __USB_IN_NORMAL_MODE__ */ 
    }

    /* start snapshot */
    mmi_vdoply_get_next_snapshot_filename(buf_filename, buf_pathname);

    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
    {
        mmi_vdoply_stop_video();           
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__
        if (g_vdoply_cntx.video_info.is_seekable)
        {        
            mmi_vdoply_stop_video();   
        }
        else
        {
            mmi_vdoply_stop_video();   
            mdi_video_stream_disconnect();

            /* reset value after stop video */
            g_vdoply_cntx.cur_status.play_time = 0;            
        }
    #endif /* __MMI_VIDEO_STREAM__ */        
    }

    mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SNAPSHOT);
    mmi_vdoply_draw_snapshoting();
    mmi_vdoply_blt_screen();

    /* show 200 ms */
    kal_sleep_task(50);

    snap_ret = mdi_video_ply_snapshot(g_vdoply_cntx.play_wnd_layer_handle, buf_filename);

    /* error check */
    if (mmi_vdoply_check_and_display_error_popup(snap_ret) == TRUE)     /* ture means has error popup */
    {
        return;
    }

    mmi_vdoply_set_state_layer_config(g_vdoply_cntx.state);
    mmi_vdoply_blt_screen();
    mmi_vdoply_clear_snapshoting();

    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
    {
        /* if is seeking, means snapshot event is insert into seeking event */
        /* since after seeking, video will restart again, we do not need to start play here */

        /* seek again before play */
        mdi_video_ply_seek_and_get_frame(   
            g_vdoply_cntx.cur_status.play_time, 
            g_vdoply_cntx.play_wnd_layer_handle);
        
        /* reset start play time */
        g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;

        if (mmi_vdoply_is_output_to_bt())
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
        }
        else
        {
            ret = mmi_vdoply_play_video();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
                return;
            }
            else if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)      /* ture means has error popup */
            {
                return;
            }
        }
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
    {
        /* reset start play time */
        g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;
        
    #ifdef __MMI_VIDEO_STREAM__
        if (g_vdoply_cntx.video_info.is_seekable)
        {        
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            }
        }
        else
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);
        }
    #endif /* __MMI_VIDEO_STREAM__ */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_snapshot_key_press
 * DESCRIPTION
 *  press snapshot key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_player_snapshot_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw press snapshot key */
    g_vdoply_cntx.touch_snapshot.is_press = TRUE;
    
    mmi_vdoply_draw_panel_state();
    mmi_vdoply_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_snapshot_key_release
 * DESCRIPTION
 *  release snapshot key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_player_snapshot_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.touch_snapshot.is_press)
    {
        /* draw release snapshot key */
        g_vdoply_cntx.touch_snapshot.is_press = FALSE;

        mmi_vdoply_draw_panel_state();
        mmi_vdoply_blt_screen();

        /* snapshot */
        mmi_vdoply_player_snapshot();

        ClearKeyEvents();
    }
}
#endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_timer_cyclic
 * DESCRIPTION
 *  timer. will ask actual play time from driver and display on screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_player_timer_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_play_ratio;
    U64 prev_play_time;
    U32 prev_buff_ratio;
    BOOL is_ui_update;
    S32 speed_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_ui_update = FALSE;
    prev_play_time = (U32) (g_vdoply_cntx.cur_status.play_time);        /* change to sec */
    prev_play_ratio = g_vdoply_cntx.cur_status.play_ratio;
    speed_factor = mmi_vdoply_get_speed_factor();
    prev_buff_ratio = g_vdoply_cntx.cur_status.buff_ratio;

    if ((g_vdoply_cntx.state == VDOPLY_STATE_PLAY) ||
        (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY))
    {
#if defined(NOKE_DEBUG)
    	noke_dbg_printf("\r\n %s:%d",__FILE__,__LINE__);
#endif
        if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
        {
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
        {
        #ifdef __MMI_VIDEO_STREAM__
            mdi_video_stream_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        #endif
        }

        mmi_vdoply_calc_progress_ratio();

        if (((speed_factor > 0) && (g_vdoply_cntx.cur_status.play_time > g_vdoply_cntx.cur_status.start_play_time)) ||      /* play foward */
            ((speed_factor < 0) && (g_vdoply_cntx.cur_status.play_time < g_vdoply_cntx.cur_status.start_play_time)))        /* play backward */
        {        
            if (g_vdoply_cntx.cur_status.play_time != prev_play_time)
            {
                is_ui_update = TRUE;
                mmi_vdoply_draw_panel_timer();
             }

            if (g_vdoply_cntx.cur_status.play_ratio != prev_play_ratio)
            {   
                is_ui_update = TRUE;        
                mmi_vdoply_draw_panel_progress();
            }
        }

        if (is_ui_update)
        {
            mmi_vdoply_blt_screen();
        }


#if 0
//Huyanwei Modify It 
        /* start cyclic timer */
	#ifdef __SF_MP4_SUPPORT__
        		gui_start_timer(400, mmi_vdoply_player_timer_cyclic);
	#else
        		gui_start_timer(200, mmi_vdoply_player_timer_cyclic);
	#endif   //__SF_MP4_SUPPORT__
#else
	#ifdef __SF_MP4_SUPPORT__
        		gui_start_timer(40, mmi_vdoply_player_timer_cyclic);
	#else
	        gui_start_timer(40, mmi_vdoply_player_timer_cyclic);
	#endif   //__SF_MP4_SUPPORT__

#endif
    }
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    else if ((g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY) || 
             (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY))
    {
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n %s:%d",__FILE__,__LINE__);
#endif
        if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
        {
#if defined(NOKE_DEBUG)
        	   noke_dbg_printf("\r\n %s:%d",__FILE__,__LINE__);
#endif
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);

       }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
        {
#if defined(NOKE_DEBUG)
        	noke_dbg_printf("\r\n %s:%d",__FILE__,__LINE__);
#endif
        #ifdef __MMI_VIDEO_STREAM__
            mdi_video_stream_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        #endif
        }


    #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        /* have OSD - calcuate and progress bar*/
    
        mmi_vdoply_calc_progress_ratio();

        /* check timer need update */
        if (((speed_factor > 0) && (g_vdoply_cntx.cur_status.play_time > g_vdoply_cntx.cur_status.start_play_time)) ||      /* play foward */
            ((speed_factor < 0) && (g_vdoply_cntx.cur_status.play_time < g_vdoply_cntx.cur_status.start_play_time)))        /* play backward */
        {        
            if (g_vdoply_cntx.cur_status.play_time != prev_play_time)
            {
                is_ui_update = TRUE;
            }

            /* check play buffer progress bar need update */
            if (g_vdoply_cntx.cur_status.buff_ratio != prev_buff_ratio)
            {
                is_ui_update = TRUE;  
                mmi_vdoply_calc_progress_ratio();                           
            }
        }

        if (is_ui_update)
        {
            if (g_vdoply_cntx.fullscr_osd_opacity != 0)
            {                
                mmi_vdoply_draw_fullscr_osd();        
                mmi_vdoply_blt_screen();
            }
        }

    #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
        /* start cyclic timer */
	#if 1
	//Huyanwei Modify It 
	mmi_vdoply_blt_screen();
	#endif
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n %s:%d",__FILE__,__LINE__);
#endif
	#if 0
	//Huyanwei Modify It 
        gui_start_timer(200, mmi_vdoply_player_timer_cyclic);
	#else
	gui_start_timer(40, mmi_vdoply_player_timer_cyclic);
	#endif

    }
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_set_softkey
 * DESCRIPTION
 *  set softkey display string
 * PARAMETERS
 *  lsk_str_ptr     [IN]        Lsk string
 *  rsk_str_ptr     [IN]        Rsk string
 *  lsk_img_id      [IN]        Lsk image
 *  rsk_img_id      [IN]        Lsk image
 *  ck_img_id       [IN]        Ck image
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.lsk_str_ptr = lsk_str_ptr;
    g_vdoply_cntx.rsk_str_ptr = rsk_str_ptr;

    g_vdoply_cntx.lsk_img_id = lsk_img_id;
    g_vdoply_cntx.rsk_img_id = rsk_img_id;
    g_vdoply_cntx.ck_img_id = ck_img_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_lsk_release
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {    
        if (!g_vdoply_cntx.touch_lsk.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_lsk.is_press = FALSE;
#if defined(__SF_MP4_SUPPORT__) && !defined(__VDOPLY_FEATURE_ENHNACE_OPTION__)
        if(appex.bIsActive)
        {
            mmi_vdoply_upd_callback(NULL);
            return;
        }
#endif //__SF_MP4_SUPPORT__
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (!g_vdoply_cntx.full_touch_lsk.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_lsk.is_press = FALSE;
    }

    /* stop seek key timer */
    if (g_vdoply_cntx.is_seeking)
    {
        gui_cancel_timer(mmi_vdoply_seek_key_release);
    }

    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_OPENING:
        case VDOPLY_STATE_INTERRUPTED_OPENING:

        #ifdef __VDOPLY_FEATURE_LSK_OPTION__
        
           /* link to option screen */
        #ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__
            mmi_vdoply_entry_option_scr();
        #else
            mmi_vdoply_entry_adjust_option_scr();
        #endif 
       
        #endif /* __VDOPLY_FEATURE_LSK_OPTION__ */ 
            break;            
   

        case VDOPLY_STATE_BT_CONNECTING:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            
        #ifdef __VDOPLY_FEATURE_LSK_OPTION__            
        
            /* link to option screen */
        #ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__	
            mmi_vdoply_entry_option_scr();
        #else
            mmi_vdoply_entry_adjust_option_scr();
        #endif
       
        #endif /* __VDOPLY_FEATURE_LSK_OPTION__ */ 
            break;
    
        case VDOPLY_STATE_IDLE:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

        #ifdef __VDOPLY_FEATURE_LSK_OPTION__
    
            /* link to option screen */
        #ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__			
            mmi_vdoply_entry_option_scr();
        #else
            mmi_vdoply_entry_adjust_option_scr();
        #endif 

        #else /* __VDOPLY_FEATURE_LSK_OPTION__ */ 
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
        #endif /* __VDOPLY_FEATURE_LSK_OPTION__ */ 

            break;

        case VDOPLY_STATE_PLAY:
            /* get latest time */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_panel_timer();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

        #ifdef __VDOPLY_FEATURE_LSK_OPTION__

            /* link to option screen */
        #ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__		
            mmi_vdoply_entry_option_scr();
        #else
            mmi_vdoply_entry_adjust_option_scr();
        #endif 

        #else /* __VDOPLY_FEATURE_LSK_OPTION__ */ 
            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);

        #endif /* __VDOPLY_FEATURE_LSK_OPTION__ */ 
            break;

        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        case VDOPLY_STATE_PAUSE:

            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

        #ifdef __VDOPLY_FEATURE_LSK_OPTION__
       
            /* link to option screen */
        #ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__			
            mmi_vdoply_entry_option_scr();
        #else
            mmi_vdoply_entry_adjust_option_scr();
        #endif 

        #else /* __VDOPLY_FEATURE_LSK_OPTION__ */ 
        
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }

            /* after calling exit function, set this flag to TRUE */
            g_vdoply_cntx.is_consume_drm_count = TRUE;            
        #endif /* __VDOPLY_FEATURE_LSK_OPTION__ */ 

            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            /* full screen */
        case VDOPLY_STATE_FULLSCR_IDLE:

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }
            break;

        case VDOPLY_STATE_FULLSCR_PAUSE:
            /* get latest time */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

            break;

        case VDOPLY_STATE_FULLSCR_PLAY:

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PAUSE);
            break;

    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 


    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_PLAY:
        case VDOPLY_STATE_STREAM_CONNECTED:    
        case VDOPLY_STATE_STREAM_DISCONNECT: 
        case VDOPLY_STATE_STREAM_CONNECTING: 
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:            
        case VDOPLY_STATE_STREAM_BUFFERING:
        case VDOPLY_STATE_STREAM_BT_CONNECTING:            
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();        

            /* enter option screen */
            mmi_vdoply_entry_option_scr();
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
            /* not use in these states */
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTED);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
            }
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            }            
            break;      
            
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:  
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
            break;      
    #endif /*  __VDOPLY_FEATURE_FULLSCREEN__ */
            
    #endif /* __MMI_VIDEO_STREAM__ */

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING: 
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING: 

            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_entry_option_scr();
            break;            
    #endif /* defined(__MMI_VIDEO_PDL__) */   

    }

    if (g_vdoply_cntx.is_seeking)
    {
        g_vdoply_cntx.is_seeking = FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_rsk_release
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {    
        if (!g_vdoply_cntx.touch_rsk.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_rsk.is_press = FALSE;
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (!g_vdoply_cntx.full_touch_rsk.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_rsk.is_press = FALSE;
    }

    if (g_vdoply_cntx.is_seeking)
    {
        gui_cancel_timer(mmi_vdoply_seek_key_release);
    }

    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_EXIT: /* exit */
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
            break;
        case VDOPLY_STATE_IDLE: /* exit */
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_close_file();
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
            break;

        case VDOPLY_STATE_PLAY: /* stop */
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            /* user force stop, need consume count */
            g_vdoply_cntx.is_consume_drm_count = TRUE;

            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
            break;


        case VDOPLY_STATE_BT_CONNECTING: 
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
            break;

        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        case VDOPLY_STATE_PAUSE:    /* stop */
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            /* user force stop, need consume count */
            g_vdoply_cntx.is_consume_drm_count = TRUE;
            
            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
            break;

        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:        
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            /* user force stop, need consume count */
            g_vdoply_cntx.is_consume_drm_count = TRUE;

            mdi_video_ply_stop_non_block_seek();
            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);

            break;

        case VDOPLY_STATE_INTERRUPTED_SEEKING:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mdi_video_ply_stop_non_block_seek();
            mmi_vdoply_close_file();
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);

            break;

        case VDOPLY_STATE_INTERRUPTED_OPENING:
        case VDOPLY_STATE_OPENING:  /* exit */
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_clear_opening_anim();
            mmi_vdoply_close_file();
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__

        /* full screen */
        case VDOPLY_STATE_FULLSCR_IDLE:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
            break;

        case VDOPLY_STATE_FULLSCR_PAUSE:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            break;

        case VDOPLY_STATE_FULLSCR_PLAY:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
            break;

        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            mdi_video_ply_stop_non_block_seek();
            
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            break;           
            
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:     
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            mdi_video_ply_stop_non_block_seek();
            
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
            
            break;
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_PLAY:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_stop_video();
            
            g_vdoply_cntx.cur_status.play_time = 0;
            g_vdoply_cntx.cur_status.start_play_time = 0;   
            mmi_vdoply_calc_progress_ratio();

            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
            }
            break;
            
        case VDOPLY_STATE_STREAM_CONNECTED:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            
            mdi_video_stream_disconnect();
            
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
            break;       
            
        case VDOPLY_STATE_STREAM_DISCONNECT:      
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);            
            break;        

        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:            
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_clear_connecting_anim();
            
            mdi_video_stream_disconnect();
            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);            
            break;        
            
        case VDOPLY_STATE_STREAM_BUFFERING:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_stream_stop_buffering();

            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);                
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);                
            }
            break;     

        case VDOPLY_STATE_STREAM_BT_CONNECTING:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_disconnect_bt();

            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);                
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);                
            }
            break;     
            
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /* fullscr */
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
            mmi_vdoply_clear_fullscr_connecting_anim();
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            mdi_video_stream_disconnect();

            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
            mmi_vdoply_clear_fullscr_connecting_anim();
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            mdi_video_stream_disconnect();

            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING);
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            gui_cancel_timer(mmi_vdoply_stream_fullscr_buffering_cyclic);                
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
           break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            mdi_video_stream_pause();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_PLAY);
            break;            

            
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
            break;            
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_STREAM__ */

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:
            mmi_vdoply_clear_opening_anim();

            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            mdi_video_progressive_close_file();
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
            break;
            
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:                 
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING: 
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            gui_cancel_timer(mmi_vdoply_pdl_buffering_cyclic);
            mdi_video_progressive_close_file();
            mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_BUFFERING);
            break;

        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_PDL__ */

    }

    if (g_vdoply_cntx.is_seeking)
    {
        g_vdoply_cntx.is_seeking = FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_vol_up_key_press
 * DESCRIPTION
 *  volume up key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_VOLUME__
static void mmi_vdoply_vol_up_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_VOLUME_MUTE__

    if (g_vdoply_cntx.is_mute == TRUE)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_cntx.cur_status.volume));

        g_vdoply_cntx.is_mute = FALSE;
    }
    else if (g_vdoply_cntx.cur_status.volume < VDOPLY_VOL_16)
    {
        g_vdoply_cntx.cur_status.volume++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_cntx.cur_status.volume));
    }
    else
    {
        return;
    }

#else /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 
    if (g_vdoply_cntx.cur_status.volume < VDOPLY_VOL_16)
    {
        g_vdoply_cntx.cur_status.volume++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_cntx.cur_status.volume));
    }
    else
    {
        return;
    }
#endif /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 

    
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
       g_vdoply_cntx.touch_volume_inc.is_press = TRUE;
       mmi_vdoply_draw_panel_volume();
       mmi_vdoply_blt_screen();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_volume_inc.is_press = TRUE;
        
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__            
            /* show OSD */
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }
    else
    {
        MMI_ASSERT(0);
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_vol_up_key_release
 * DESCRIPTION
 *  volume up key release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_vol_up_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (!g_vdoply_cntx.touch_volume_inc.is_press)
        {
            return;
        }
        
        g_vdoply_cntx.touch_volume_inc.is_press = FALSE;
        mmi_vdoply_draw_panel_volume();
        mmi_vdoply_blt_screen();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        if (!g_vdoply_cntx.full_touch_volume_inc.is_press)
        {
            return;
        }
        
        g_vdoply_cntx.full_touch_volume_inc.is_press = FALSE;
        
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__            
            /* show OSD */
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }
    else
    {
        MMI_ASSERT(0);
    }
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_vol_down_key_press
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_vol_down_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_VOLUME_MUTE__
    if (g_vdoply_cntx.is_mute == TRUE)
    {
        return;
    }

    if (g_vdoply_cntx.cur_status.volume > VDOPLY_VOL_1)
    {
        g_vdoply_cntx.cur_status.volume--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_cntx.cur_status.volume));
    }
    else if (g_vdoply_cntx.cur_status.volume == VDOPLY_VOL_1)
    {
        g_vdoply_cntx.is_mute = TRUE;
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
#else /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 
    if (g_vdoply_cntx.cur_status.volume > VDOPLY_VOL_1)
    {
        g_vdoply_cntx.cur_status.volume--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX(g_vdoply_cntx.cur_status.volume));
    }
    else
    {
        return;
    }
#endif /* __VDOPLY_FEATURE_VOLUME_MUTE__ */ 
    
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
       g_vdoply_cntx.touch_volume_dec.is_press = TRUE;
       mmi_vdoply_draw_panel_volume();
       mmi_vdoply_blt_screen();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_volume_dec.is_press = TRUE;
        
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__            
            /* show OSD */
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_vol_down_key_release
 * DESCRIPTION
 *  volume down key release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_vol_down_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (!g_vdoply_cntx.touch_volume_dec.is_press)
        {
            return;
        }
        
        g_vdoply_cntx.touch_volume_dec.is_press = FALSE;
        mmi_vdoply_draw_panel_volume();
        mmi_vdoply_blt_screen();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        if (!g_vdoply_cntx.full_touch_volume_dec.is_press)
        {
            return;
        }
        
        g_vdoply_cntx.full_touch_volume_dec.is_press = FALSE;
        
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__            
            /* show OSD */
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */

    }
    else
    {
        MMI_ASSERT(0);
    }

}
#endif /* __VDOPLY_FEATURE_VOLUME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_speed_inc_key_press
 * DESCRIPTION
 *  up arrow key press hdlr, for speed up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_SPEED__
static void mmi_vdoply_speed_inc_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEPPD_INC_KEY_PRESS);   
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_IS_KEY_PRESSED, g_vdoply_cntx.touch_speed_inc.is_press);       

    if (g_vdoply_cntx.cur_status.speed >= VDOPLY_FEATURE_SPEED_COUNT - 1)
    {
        return;
    }

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        g_vdoply_cntx.touch_speed_inc.is_press = TRUE;        
        mmi_vdoply_draw_panel_speed();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_speed_inc.is_press = TRUE;      
        mmi_vdoply_fullscr_reset_osd_fade(FALSE);
        mmi_vdoply_draw_fullscr_osd();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    mmi_vdoply_blt_screen();

 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_speed_inc_key_release
 * DESCRIPTION
 *  speed up key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_speed_inc_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEPPD_INC_KEY_RELEASE);   
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_IS_KEY_PRESSED, g_vdoply_cntx.touch_speed_inc.is_press);       
    
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (!g_vdoply_cntx.touch_speed_inc.is_press)
        {
            return;
        }        

        g_vdoply_cntx.cur_status.speed++;
        g_vdoply_cntx.touch_speed_inc.is_press = FALSE;        
        mmi_vdoply_draw_panel_speed();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__

        if (!g_vdoply_cntx.full_touch_speed_inc.is_press)
        {
            return;
        }  

        g_vdoply_cntx.cur_status.speed++;
        g_vdoply_cntx.full_touch_speed_inc.is_press = FALSE;
        mmi_vdoply_fullscr_reset_osd_fade(TRUE);
        mmi_vdoply_draw_fullscr_osd();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }
   
    mmi_vdoply_blt_screen();

    /* if is seeking, it is already stopped */
    if ((g_vdoply_cntx.state == VDOPLY_STATE_PLAY ||
         g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY) && (!g_vdoply_cntx.is_seeking))
    {
        /* speed change, need pause and restart */
        mmi_vdoply_stop_video();

        if (mmi_vdoply_is_output_to_bt())
        {
            if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
        }
        else
        {
            ret = mmi_vdoply_play_video();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                if(g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
                    return;                    
                }
                else if(g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
                    return;
                }
                else
                {
                    MMI_ASSERT(0);
                }
            }
            else if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)      /* ture means has error popup */
            {
                return;
            }
        }

        /* reset start play time */
        g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_speed_dec_key_press
 * DESCRIPTION
 *  down arrow key press hdlr, for speed down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_speed_dec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEPPD_DEC_KEY_PRESS);   
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_IS_KEY_PRESSED, g_vdoply_cntx.touch_speed_dec.is_press);       

    if (g_vdoply_cntx.cur_status.speed == 0)
    {
        return;
    }

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        g_vdoply_cntx.touch_speed_dec.is_press = TRUE;   
        mmi_vdoply_draw_panel_speed();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_speed_dec.is_press = TRUE;       
        mmi_vdoply_fullscr_reset_osd_fade(FALSE);
        mmi_vdoply_draw_fullscr_osd();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_vdoply_blt_screen();
   
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_speed_dec_key_release
 * DESCRIPTION
 *  speed up key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_speed_dec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEPPD_DEC_KEY_RELEASE);   
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_IS_KEY_PRESSED, g_vdoply_cntx.touch_speed_dec.is_press);       

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (!g_vdoply_cntx.touch_speed_dec.is_press)
        {
            return;
        }        

        g_vdoply_cntx.cur_status.speed--;
        g_vdoply_cntx.touch_speed_dec.is_press = FALSE;        
        mmi_vdoply_draw_panel_speed();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        if (!g_vdoply_cntx.full_touch_speed_dec.is_press)
        {
            return;
        }        
        
        g_vdoply_cntx.cur_status.speed--;
        g_vdoply_cntx.full_touch_speed_dec.is_press = FALSE;
        mmi_vdoply_fullscr_reset_osd_fade(TRUE);
        mmi_vdoply_draw_fullscr_osd();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_vdoply_blt_screen();

    /* speed change, need pause and restart */
    if ((g_vdoply_cntx.state == VDOPLY_STATE_PLAY ||
         g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY) && (!g_vdoply_cntx.is_seeking))
    {
        /* speed change, need pause and restart */
        mmi_vdoply_stop_video();

        if (mmi_vdoply_is_output_to_bt())
        {
            if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
        }
        else
        {
            ret = mmi_vdoply_play_video();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                if(g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
                    return;                       
                }
                else if(g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
                    return;                       
                }
                else
                {
                    MMI_ASSERT(0);
                }
                return;
            }
            else if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)      /* ture means has error popup */
            {
                return;
            }
        }

        /* reset start play time */
        g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;
    }
}
#endif /* __VDOPLY_FEATURE_SPEED__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_result_hdlr
 * DESCRIPTION
 *  seek result
 * PARAMETERS
 *  result      [IN]        Seek result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_result_hdlr(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all pressed key */
    g_vdoply_cntx.touch_ck.is_press = FALSE;
    g_vdoply_cntx.touch_lsk.is_press = FALSE;
    g_vdoply_cntx.touch_rsk.is_press = FALSE;
    g_vdoply_cntx.touch_speed_inc.is_press = FALSE;
    g_vdoply_cntx.touch_speed_dec.is_press = FALSE;
    g_vdoply_cntx.touch_volume_inc.is_press = FALSE;
    g_vdoply_cntx.touch_volume_dec.is_press = FALSE;

    /* error check */
    if (mmi_vdoply_check_and_display_error_popup(result) == TRUE)       /* ture means has error popup */
    {
        return;
    }

    /* seek partial done */
    if (result == MDI_RES_VDOPLY_SEEK_PARTIAL_DONE)
    {
        /* get current play time */
        mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        mmi_vdoply_calc_progress_ratio();
    }

    /* enter next state */
    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_SEEKING:
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            break;

        case VDOPLY_STATE_PLAY_SEEKING:
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
            break;

        case VDOPLY_STATE_INTERRUPTED_SEEKING:
            mmi_vdoply_enter_state(VDOPLY_STATE_INTERRUPTED_PAUSE);
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_FULLSCR_SEEKING:
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PAUSE);
            break;

        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_key_release
 * DESCRIPTION
 *  seek key release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_KEY_RELEASE);  

    g_vdoply_cntx.is_seeking = FALSE;

    switch (g_vdoply_cntx.state)
    {
            /* normal */
        case VDOPLY_STATE_IDLE:
        case VDOPLY_STATE_PAUSE:
        case VDOPLY_STATE_INTERRUPTED_PAUSE:
            mmi_vdoply_enter_state(VDOPLY_STATE_SEEKING);
            break;
            
        case VDOPLY_STATE_BT_CONNECTING:  
        case VDOPLY_STATE_PLAY:
            mmi_vdoply_enter_state(VDOPLY_STATE_PLAY_SEEKING);
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            /* full screen */
        case VDOPLY_STATE_FULLSCR_IDLE:
        case VDOPLY_STATE_FULLSCR_PAUSE:
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_SEEKING);
            break;

        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
        case VDOPLY_STATE_FULLSCR_PLAY:
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY_SEEKING);
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_CONNECTED:
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            }
            break;

        case VDOPLY_STATE_STREAM_DISCONNECT:
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);
            break;
            
        case VDOPLY_STATE_STREAM_PLAY:
        case VDOPLY_STATE_STREAM_BUFFERING:            
            if (g_vdoply_cntx.video_info.is_seekable)
            {
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
                }
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);
            }            
            break;

        case VDOPLY_STATE_STREAM_BT_CONNECTING:
            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);
            }              
            break;
            
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            }   
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:            
            if (g_vdoply_cntx.video_info.is_seekable)
            {
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
                }   
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
            }
            break;   

        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
            }
            break;              
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_STREAM__ */ 

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
            mmi_vdoply_enter_state(VDOPLY_STATE_SEEKING);            
            break;
            
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:            
            mmi_vdoply_enter_state(VDOPLY_STATE_PLAY_SEEKING);  
            break;
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_SEEKING);            
            break;            
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:            
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY_SEEKING);  
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_PDL__ */
    
        default:
            MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_foward
 * DESCRIPTION
 *  seek foward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdoply_seek_foward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 jump_time;
    U64 total_time;
    U64 max_play_time;
    U64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_FOWARND);      

    cur_time = g_vdoply_cntx.cur_status.play_time;
    total_time = g_vdoply_cntx.video_info.total_time_duration;

    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
    {
        max_play_time = g_vdoply_cntx.cur_status.max_play_time;
    }
    else
    {
        max_play_time = g_vdoply_cntx.video_info.total_time_duration;
    }

    if (cur_time < max_play_time)
    {
        jump_time = total_time / g_vdoply_cntx.progress.fill_width;

        if (jump_time == 0)
        {
            jump_time = 1;
        }

        jump_time <<= 3;

        if ((jump_time + cur_time) >= max_play_time)   /* time stamp is from 0 to total-1 */
        {
            cur_time = max_play_time - 1;
        }
        else
        {
            cur_time += jump_time;
        }

        g_vdoply_cntx.cur_status.play_time = cur_time;

        if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
        {
             if (g_vdoply_cntx.state == VDOPLY_STATE_IDLE)
            {
                /* change to pause state */
                g_vdoply_cntx.state = VDOPLY_STATE_PAUSE;
            }

            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_panel_timer();
            mmi_vdoply_draw_panel_progress();
        }
        else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
        {
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_IDLE)
            {
                /* change to pause state */
                g_vdoply_cntx.state = VDOPLY_STATE_FULLSCR_PAUSE;
            }
            
            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_fullscr_osd();
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        }

        mmi_vdoply_blt_screen();

        return TRUE;
    }

    return FALSE;   /* reach limit, cant seek anymore */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_foward_key_press_cyclic
 * DESCRIPTION
 *  right arrow long press timer hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_foward_key_press_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vdoply_seek_foward())
    {
        gui_start_timer(100, mmi_vdoply_seek_foward_key_press_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_foward_key_press
 * DESCRIPTION
 *  right arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_foward_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_FOWARD_KEY_PRESS);      

    gui_cancel_timer(mmi_vdoply_seek_key_release);

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (g_vdoply_cntx.touch_progress_inc.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_progress_inc.is_press = TRUE;
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (g_vdoply_cntx.full_touch_progress_inc.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_progress_inc.is_press = TRUE;
    }


    g_vdoply_cntx.is_seeking = TRUE;

    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_PLAY:
            mmi_vdoply_stop_video();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);                 
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_IDLE:
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            g_vdoply_cntx.state = VDOPLY_STATE_PAUSE;
            break;

        case VDOPLY_STATE_PAUSE:
            mmi_vdoply_draw_panel_progress();        
            mmi_vdoply_blt_screen();            
            break;

        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:
            /* stop previous seeking action */
            mdi_video_ply_stop_non_block_seek();

            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_FULLSCR_PLAY:
            mmi_vdoply_stop_video();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_FULLSCR_PAUSE:
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();            
            break;

        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);  
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            /* stop previous seeking action */
            mdi_video_ply_stop_non_block_seek();

            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    
    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_PLAY:
            mmi_vdoply_stop_video();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);  
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_CONNECTED:
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_BUFFERING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);  
            
            mmi_vdoply_stream_stop_buffering();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;
            
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
            mmi_vdoply_stop_video();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);  
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);  
            
            mmi_vdoply_stream_stop_buffering(); 
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;            
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_STREAM__ */

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:            
            gui_cancel_timer(mmi_vdoply_pdl_buffering_cyclic);
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);
            mmi_vdoply_blt_screen();            
            break;
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:            
            gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();          
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_PDL__ */
    
    }

    if (mmi_vdoply_seek_foward())
    {
        gui_start_timer(200, mmi_vdoply_seek_foward_key_press_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_foward_key_release
 * DESCRIPTION
 *  right arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_foward_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_FOWARD_KEY_RELEASE);      

   if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (!g_vdoply_cntx.touch_progress_inc.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_progress_inc.is_press = FALSE;
    }
    else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (!g_vdoply_cntx.full_touch_progress_inc.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_progress_inc.is_press = FALSE;
    }

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);

        mmi_vdoply_draw_panel_progress();
        mmi_vdoply_blt_screen();
    }
    else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        ClearInputEventHandler(MMI_DEVICE_KEY);
        SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);

        mmi_vdoply_fullscr_reset_osd_fade(TRUE);
        mmi_vdoply_draw_fullscr_osd();
        mmi_vdoply_blt_screen();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }

    gui_cancel_timer(mmi_vdoply_seek_foward_key_press_cyclic);
    gui_start_timer(100, mmi_vdoply_seek_key_release);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_backward
 * DESCRIPTION
 *  seek backward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdoply_seek_backward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 jump_time;
    U64 total_time;
    U64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_BACKWARD);  

    cur_time = g_vdoply_cntx.cur_status.play_time;
    total_time = g_vdoply_cntx.video_info.total_time_duration;

    if (cur_time > 0)
    {
        jump_time = total_time / g_vdoply_cntx.progress.fill_width;

        if (jump_time == 0)
        {
            jump_time = 1;
        }

        jump_time <<= 3;

        if (jump_time > cur_time)
        {
            cur_time = 0;
        }
        else
        {
            cur_time -= jump_time;
        }

        g_vdoply_cntx.cur_status.play_time = cur_time;

        if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
        {
             if (g_vdoply_cntx.state == VDOPLY_STATE_IDLE)
            {
                /* change to pause state */
                g_vdoply_cntx.state = VDOPLY_STATE_PAUSE;
            }

            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_panel_timer();
            mmi_vdoply_draw_panel_progress();
        }
        else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
        {
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_IDLE)
            {
                /* change to pause state */
                g_vdoply_cntx.state = VDOPLY_STATE_FULLSCR_PAUSE;
            }
            
            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_fullscr_osd();
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        }

        mmi_vdoply_blt_screen();

        return TRUE;
    }

    return FALSE;   /* reach limit, cant seek anymore */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_backward_key_press_cyclic
 * DESCRIPTION
 *  left arrow long press timer hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_backward_key_press_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_vdoply_seek_backward())
    {
        gui_start_timer(100, mmi_vdoply_seek_backward_key_press_cyclic);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_backward_key_press
 * DESCRIPTION
 *  left arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_backward_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_BACKWARD_KEY_PRESS);

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (g_vdoply_cntx.touch_progress_dec.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_progress_dec.is_press = TRUE;
    }
    else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (g_vdoply_cntx.full_touch_progress_dec.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_progress_dec.is_press = TRUE;
    }

    g_vdoply_cntx.is_seeking = TRUE;
    gui_cancel_timer(mmi_vdoply_seek_key_release);
    
    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_IDLE:
        case VDOPLY_STATE_PAUSE:
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;
        
        case VDOPLY_STATE_PLAY:
            mmi_vdoply_stop_video();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:
            /* stop previous seeking action */
            mdi_video_ply_stop_non_block_seek();

            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_FULLSCR_PLAY:
            mmi_vdoply_stop_video();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            /* stop previous seeking action */
            mdi_video_ply_stop_non_block_seek();

            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    
    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_PLAY:
            mmi_vdoply_stop_video();                         
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);            
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_CONNECTED:
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;
            
        case VDOPLY_STATE_STREAM_BUFFERING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);      
            
            mmi_vdoply_stream_stop_buffering();
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
            mmi_vdoply_stop_video();                           
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);    
            
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
            /* hide process layer */
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);    
            
            mmi_vdoply_stream_stop_buffering();       
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;              
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_STREAM__ */

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:            
            gui_cancel_timer(mmi_vdoply_pdl_buffering_cyclic);
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_SEEKING);
            mmi_vdoply_blt_screen();            
            break;
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:            
            gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);
            mmi_vdoply_set_state_layer_config(VDOPLY_STATE_FULLSCR_SEEKING);
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();          
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_PDL__ */
    }

    if (mmi_vdoply_seek_backward())
    {
        gui_start_timer(200, mmi_vdoply_seek_backward_key_press_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_seek_backward_key_release
 * DESCRIPTION
 *  left arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_seek_backward_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_SEEK_BACKWARD_KEY_RELEASE);

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        if (!g_vdoply_cntx.touch_progress_dec.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_progress_dec.is_press = FALSE;
    }
    else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (!g_vdoply_cntx.full_touch_progress_dec.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_progress_dec.is_press = FALSE;
    }

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);

        mmi_vdoply_draw_panel_progress();
        mmi_vdoply_blt_screen();
    }
    else if  (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        ClearInputEventHandler(MMI_DEVICE_KEY);
        SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);

        mmi_vdoply_fullscr_reset_osd_fade(TRUE);
        mmi_vdoply_draw_fullscr_osd();
        mmi_vdoply_blt_screen();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }
   
    gui_cancel_timer(mmi_vdoply_seek_backward_key_press_cyclic);
    gui_start_timer(200, mmi_vdoply_seek_key_release);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_lsk_press
 * DESCRIPTION
 *  lsk hdlr when pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {    
        g_vdoply_cntx.touch_lsk.is_press = TRUE;        
        mmi_vdoply_draw_softkey();
        mmi_vdoply_blt_screen();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_lsk.is_press = TRUE;            
        mmi_vdoply_fullscr_reset_osd_fade(FALSE);
        mmi_vdoply_draw_fullscr_osd();
        mmi_vdoply_blt_screen();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_rsk_press
 * DESCRIPTION
 *  rsk hdlr when pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {    
        g_vdoply_cntx.touch_rsk.is_press = TRUE;        
        mmi_vdoply_draw_softkey();
        mmi_vdoply_blt_screen();
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_rsk.is_press = TRUE;    
        mmi_vdoply_fullscr_reset_osd_fade(FALSE);
        mmi_vdoply_draw_fullscr_osd();
        mmi_vdoply_blt_screen();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_ck_press
 * DESCRIPTION
 *  ck hdlr when pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_ck_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {    
        g_vdoply_cntx.touch_ck.is_press = TRUE;        
        
    #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
    #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
        mmi_vdoply_draw_softkey();
        mmi_vdoply_blt_screen();
    #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
        mmi_vdoply_lsk_press();
    #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
    #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
        mmi_vdoply_draw_softkey();
        mmi_vdoply_blt_screen();
    #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        g_vdoply_cntx.full_touch_ck.is_press = TRUE;         
    
        mmi_vdoply_fullscr_reset_osd_fade(FALSE);

        mmi_vdoply_draw_fullscr_osd();
        mmi_vdoply_blt_screen();
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_ck_release
 * DESCRIPTION
 *  ck hdlr when release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_ck_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {    
        if (!g_vdoply_cntx.touch_ck.is_press)
        {
            return;
        }
        g_vdoply_cntx.touch_ck.is_press = FALSE;
    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        if (!g_vdoply_cntx.full_touch_ck.is_press)
        {
            return;
        }
        g_vdoply_cntx.full_touch_ck.is_press = FALSE;
    }


    /* stop seek key timer */
    if (g_vdoply_cntx.is_seeking)
    {
        gui_cancel_timer(mmi_vdoply_seek_key_release);
    }

    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_IDLE:

    #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
    #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
    #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            mmi_vdoply_lsk_release();
    #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
    #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
    #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

        case VDOPLY_STATE_PLAY:

    #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
    #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
            /* get latest time */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);

            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_panel_timer();
            mmi_vdoply_draw_panel_progress();

            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
    #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            mmi_vdoply_lsk_release();
    #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
    #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            /* get latest time */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);

            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_panel_timer();
            mmi_vdoply_draw_panel_progress();

            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mdi_video_ply_get_cur_play_time(&cur_time);        
#ifdef __SF_MP4_SUPPORT__
			if(cur_time < g_vdoply_cntx.cur_status.start_play_time
				&& !vdo_sfmp4_is_active())
#else //__SF_MP4_SUPPORT__
            if(cur_time < g_vdoply_cntx.cur_status.start_play_time)
#endif //__SF_MP4_SUPPORT__
            {
                /* 
                 *  this means driver already send out play finish indication, 
                 *  but MMI still not receive yet.
                 */
                mmi_vdoply_enter_state(VDOPLY_STATE_IDLE); 
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            }
    #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 

            break;

        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        case VDOPLY_STATE_PAUSE:    /* resume */

        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
        #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
        #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            mmi_vdoply_lsk_release();
        #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
        case VDOPLY_STATE_STREAM_BUFFERING:
            /* CK is disable in these states */
            break;
            
        case VDOPLY_STATE_STREAM_PLAY:

            /* get latest time */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_draw_panel_timer();
            mmi_vdoply_draw_panel_progress();

            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {            
                mmi_vdoply_stop_video();                             
            }

            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);                
            }
			break;
				
        case VDOPLY_STATE_STREAM_CONNECTED:
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            }           
            break;
            
        case VDOPLY_STATE_STREAM_DISCONNECT: 
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);            
            break;            

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
            /* ck is disable in these stats */
            break;
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();            
            }

            if (g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTED);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
            }
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            }   
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:  
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);    
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_STREAM__ */


    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            /* full screen */
        case VDOPLY_STATE_FULLSCR_IDLE:
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

            break;

        case VDOPLY_STATE_FULLSCR_PAUSE:

            /* get latest time */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
            mmi_vdoply_calc_progress_ratio();
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

            break;

        case VDOPLY_STATE_FULLSCR_PLAY:

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* if is seeking in play state, the video is already stopped */
            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mdi_video_ply_get_cur_play_time(&cur_time);        
#ifdef __SF_MP4_SUPPORT__
			if(cur_time < g_vdoply_cntx.cur_status.start_play_time
							&& !vdo_sfmp4_is_active())
#else //__SF_MP4_SUPPORT__
            if(cur_time < g_vdoply_cntx.cur_status.start_play_time)
#endif //__SF_MP4_SUPPORT__
            {
                /* 
                 *  this means driver already send out play finish indication, 
                 *  but MMI still not receive yet.
                 */
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_IDLE); 
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PAUSE);
            }
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    }

    if (g_vdoply_cntx.is_seeking)
    {
        g_vdoply_cntx.is_seeking = FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_toggle_fullscreen_key_press
 * DESCRIPTION
 *  toggle to fullscreen display key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_toggle_fullscreen_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.touch_fullscreen.is_press = TRUE;

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        mmi_vdoply_draw_panel();
        mmi_vdoply_blt_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_toggle_fullscreen_key_release
 * DESCRIPTION
 *  toggle to fullscreen display key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_toggle_fullscreen_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.touch_fullscreen.is_press)
    {    
        g_vdoply_cntx.touch_fullscreen.is_press = FALSE;            
        
        if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
        {
            mmi_vdoply_draw_panel();
            mmi_vdoply_blt_screen();
        }     
        
        mmi_vdoply_toggle_fullscreen_display();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_toggle_fullscreen_display
 * DESCRIPTION
 *  toggle to fullscreen display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_toggle_fullscreen_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 cur_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flush key event */
    ClearKeyEvents();
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);
#endif
    /* if is seeking, do not allowed toggle */
    if (g_vdoply_cntx.is_seeking)
    {
        return;
    }
          
    switch (g_vdoply_cntx.state)
    {
            /* normal */
        case VDOPLY_STATE_PLAY:
            mmi_vdoply_stop_video();

            mdi_video_ply_get_cur_play_time(&cur_time);        
#ifdef __SF_MP4_SUPPORT__
			if(cur_time < g_vdoply_cntx.cur_status.start_play_time
							&& !vdo_sfmp4_is_active())
#else //__SF_MP4_SUPPORT__
            if(cur_time == 0)
#endif //__SF_MP4_SUPPORT__
            {
                /* 
                 *  this means driver already send out play finish indication, 
                 *  but MMI still not receive yet.
                 */
#if defined(NOKE_DEBUG)
	       noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					                 
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_IDLE);
            }
            else
            {
                if (mmi_vdoply_is_output_to_bt())
                {
#if defined(NOKE_DEBUG)
                   noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                    mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
		
                }
                else
                {//Huyanwei Touch Here
#if defined(NOKE_DEBUG)
                    noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                    mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
                }
            }
            break;

        case VDOPLY_STATE_BT_CONNECTING:
            mmi_vdoply_disconnect_bt();

            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }
            break;

        case VDOPLY_STATE_IDLE:
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD - will directly play*/
            if (mmi_vdoply_is_output_to_bt())
            {
#if defined(NOKE_DEBUG)
	        noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
#if defined(NOKE_DEBUG)
              noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

        #else
            /* have OSD */
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);
#endif
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_IDLE);
        #endif
            break;

        case VDOPLY_STATE_PAUSE:
        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD - will directly play*/
            if (mmi_vdoply_is_output_to_bt())
            {
#if defined(NOKE_DEBUG)
               noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
#if defined(NOKE_DEBUG)
            noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

        #else
            /* have OSD */        
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PAUSE);
        #endif        
            break;

        case VDOPLY_STATE_SEEKING:
            /* stop non-blocking seeking */
            mdi_video_ply_stop_non_block_seek();
            
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD - will directly play*/
            if (mmi_vdoply_is_output_to_bt())
            {
#if defined(NOKE_DEBUG)
                noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
#if defined(NOKE_DEBUG)
               noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

        #else
            /* have OSD */        
#if defined(NOKE_DEBUG)
  	  noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PAUSE);
        #endif                    
            break;

        case VDOPLY_STATE_PLAY_SEEKING:
            /* stop non-blocking seeking */
            mdi_video_ply_stop_non_block_seek();
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }

            break;

            /* fullscreen */
        case VDOPLY_STATE_FULLSCR_PAUSE:
#if defined(NOKE_DEBUG)
   	   noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);							
#endif
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            break;


        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
            mmi_vdoply_disconnect_bt();
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no osd - back to veritcal screen and pause */
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
        #else            
            /* have osd */          
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
        #endif
            break;

        case VDOPLY_STATE_FULLSCR_PLAY:
#if defined(NOKE_DEBUG)
           noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
            mmi_vdoply_stop_video();
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            
            mdi_video_ply_get_cur_play_time(&cur_time);        
#ifdef __SF_MP4_SUPPORT__
			if(cur_time < g_vdoply_cntx.cur_status.start_play_time
						&& !vdo_sfmp4_is_active())
#else //__SF_MP4_SUPPORT__
            if(cur_time < g_vdoply_cntx.cur_status.start_play_time)
#endif //__SF_MP4_SUPPORT__
            {
                /* 
                 *  this means driver already send out play finish indication, 
                 *  but MMI still not receive yet.
                 */
#if defined(NOKE_DEBUG)
                noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
            }
            else
            {
                if (mmi_vdoply_is_output_to_bt())
                {
#if defined(NOKE_DEBUG)
                noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                    mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
                }
                else
                {
#if defined(NOKE_DEBUG)
                noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                    mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
                }
            }
            break;

        case VDOPLY_STATE_FULLSCR_IDLE:
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);								
#endif
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
            /* stop non-blocking seeking */
            mdi_video_ply_stop_non_block_seek();
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
            break;

        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            /* stop non-blocking seeking */
            mdi_video_ply_stop_non_block_seek();
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
            
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no osd - back to veritcal screen and pause */
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);							
#endif
            mmi_vdoply_enter_state(VDOPLY_STATE_PAUSE);
        #else            
            /* have osd */          
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
        #endif            
            break;

    #ifdef __MMI_VIDEO_STREAM__
    
        case VDOPLY_STATE_STREAM_DISCONNECT:  
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ 
            /* no osd - will directly connect, buffer and play */
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
        #else
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
        #endif
            break;

        case VDOPLY_STATE_STREAM_CONNECTING:
            mmi_vdoply_clear_connecting_anim();
            mdi_video_stream_disconnect();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
            break;

        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
            mmi_vdoply_clear_connecting_anim();    
            mdi_video_stream_disconnect();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING);
            break;
            
        case VDOPLY_STATE_STREAM_CONNECTED:
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ 
            /* no osd - will directly buffer and play */
            if (mmi_vdoply_is_output_to_bt())
            {
#if defined(NOKE_DEBUG)
               noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
            }
            else
            {
#if defined(NOKE_DEBUG)
            noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            }   
        #else
#if defined(NOKE_DEBUG)
     	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTED);
        #endif
            break;
            
        case VDOPLY_STATE_STREAM_BUFFERING:
            gui_cancel_timer(mmi_vdoply_stream_buffering_cyclic);            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
            break;
            
        case VDOPLY_STATE_STREAM_PLAY:
            mdi_video_stream_pause();                
            mmi_vdoply_clear_aud_only_anim();  
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_PLAY);
            break;

        case VDOPLY_STATE_STREAM_BT_CONNECTING:
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);            
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING: 
#if defined(NOKE_DEBUG)
	   noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);								
#endif
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);                        
            mmi_vdoply_clear_fullscr_connecting_anim();
            mdi_video_stream_disconnect();            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING); 
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);                        
            mmi_vdoply_clear_fullscr_connecting_anim();
            mdi_video_stream_disconnect();            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING); 
            break;
            
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:   
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);                        
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);         
            break;            
            
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);								
#endif
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);                        
            gui_cancel_timer(mmi_vdoply_stream_fullscr_buffering_cyclic);                        
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);                        
            mmi_vdoply_disconnect_bt();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);								
#endif
            gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);                        
            mmi_vdoply_clear_fullscr_aud_only_anim();               
            
            mdi_video_stream_pause();
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_PLAY);
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */        
    #endif /* __MMI_VIDEO_STREAM__ */

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
            gui_cancel_timer(mmi_vdoply_pdl_buffering_cyclic);      
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING);
            break;
            
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:   
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);								
#endif
            gui_cancel_timer(mmi_vdoply_pdl_buffering_cyclic);      
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
            break;
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);					
#endif
            gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);      
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_BUFFERING);
            break;
            
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:    
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\nHuyanwei Debug : mmi_vdoply_toggle_fullscreen_display():%s:%d",__FILE__,__LINE__);								
#endif
            gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);      
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
            break;            
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_PDL__ */
    
        default:
            MMI_ASSERT(0);

    }

}
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

/* 2009.05.06 added by hongzhe.liu for motion sensor app + */
BOOL mmi_vdoply_is_toggle_fullscreen_enable()
{
    switch ( g_vdoply_cntx.state )
    {
        case VDOPLY_STATE_PLAY:
    
        case VDOPLY_STATE_FULLSCR_IDLE:
        case VDOPLY_STATE_FULLSCR_PAUSE:
        case VDOPLY_STATE_FULLSCR_PLAY:
        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
	     return TRUE;		
	     break;	

	 default:
	     return FALSE;	
	     break;	 
    }
}

void ProcessVdoplayerFullScreenMessage(int full_scr)
{
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
	if(    (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL && full_scr == 0)
	   || (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR && full_scr == 1)
	)
	{
		return;
	}

        if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
        {
            mmi_vdoply_draw_panel();
            mmi_vdoply_blt_screen();
        }     
	mmi_vdoply_toggle_fullscreen_display();
#ifndef WIN32 
	delayms(10);		
#endif	
#endif
}
/* 2009.05.06 added by hongzhe.liu for motion sensor app - */

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_toggle_tvout_key_press
 * DESCRIPTION
 *  toggle to fullscreen display key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TVOUT__
static void mmi_vdoply_toggle_tvout_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.touch_fullscreen.is_press = TRUE;

    mmi_vdoply_draw_panel();
    mmi_vdoply_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_toggle_tvout_key_release
 * DESCRIPTION
 *  toggle to tvout display key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_toggle_tvout_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.touch_fullscreen.is_press)
    {
        g_vdoply_cntx.touch_fullscreen.is_press = FALSE;
        mmi_vdoply_draw_panel();
        mmi_vdoply_blt_screen();
        mmi_vdoply_toggle_tvout_display();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_toggle_tvout_display
 * DESCRIPTION
 *  toggle tvouto display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_toggle_tvout_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U16 prev_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_state = g_vdoply_cntx.state;
    
    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
    {
        /* stop */
        mmi_vdoply_stop_video();
        g_vdoply_cntx.state = VDOPLY_STATE_PAUSE;
    }
    else if(g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__        
        mdi_video_stream_pause();                
    #endif /* __MMI_VIDEO_STREAM__ */
    }

    if (g_vdoply_cntx.is_tvout_fullscreen)
    {
        /* change to normal screen */

        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        /* restore back to mode 1 */
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
    #else /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 
        /* restore back to mode 1 */
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 

        g_vdoply_cntx.is_tvout_fullscreen = FALSE;

    #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
    #ifdef LCM_ROTATE_SUPPORT
        if (mdi_tvout_is_enable())
        {
            mdi_tvout_resize_buffer(UI_device_height, UI_device_width);
        }
    #endif /* LCM_ROTATE_SUPPORT */ 
    #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 

        /* blt to tv buffer */
        mmi_vdoply_blt_screen();
    
    }
    else
    {
        /* change to full screen */

        /* if is fullscreen, we shall set to owner to video here, to avoid GDI's update */
        mdi_tvout_set_owner(MDI_TV_OWNER_VIDEO);

        /* start mode 2 - full screen preview update */
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_FULL_SCR, 0, 0);

        g_vdoply_cntx.is_tvout_fullscreen = TRUE;
    }

    if (prev_state == VDOPLY_STATE_PLAY)
    {
        if (mmi_vdoply_is_output_to_bt())
        {
        mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
        return;
    }
        else
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            return;
        }
    }
    else if ((prev_state == VDOPLY_STATE_IDLE) ||
             (prev_state == VDOPLY_STATE_PAUSE) || 
             (prev_state == VDOPLY_STATE_INTERRUPTED_PAUSE))
    {
        if (g_vdoply_cntx.is_tvout_fullscreen)
        {
            /* seek again. driver will draw to tv */
            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle);
            /* error check */
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
        }

        /* blt screen to LCM */
        mmi_vdoply_blt_screen();
    }
    else if(prev_state == VDOPLY_STATE_STREAM_PLAY)
    {
    #ifdef __MMI_VIDEO_STREAM__
        mmi_vdoply_resume_stream_video();
    #endif /* __MMI_VIDEO_STREAM__ */
    }

}
#endif /* __MMI_TVOUT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_set_state_key_event
 * DESCRIPTION
 *  register player's key event hdlr for different state
 * PARAMETERS
 *  state       [IN]        Video player's state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_set_state_key_event(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);    
    
    /* dont let CK mapping to LSK */
    SetKeyHandler(mmi_vdoply_null_key_event, KEY_ENTER, KEY_EVENT_DOWN);

    g_vdoply_cntx.touch_speed_inc.is_usable = FALSE;
    g_vdoply_cntx.touch_speed_dec.is_usable = FALSE;
    g_vdoply_cntx.touch_volume_inc.is_usable = FALSE;
    g_vdoply_cntx.touch_volume_dec.is_usable = FALSE;
    g_vdoply_cntx.touch_progress_inc.is_usable = FALSE;
    g_vdoply_cntx.touch_progress_dec.is_usable = FALSE;
    g_vdoply_cntx.touch_progress_bar.is_usable = FALSE;
    g_vdoply_cntx.touch_snapshot.is_usable = FALSE;
    g_vdoply_cntx.touch_fullscreen.is_usable = FALSE;
    g_vdoply_cntx.touch_rsk.is_usable = FALSE;
    g_vdoply_cntx.touch_lsk.is_usable = FALSE;
    g_vdoply_cntx.touch_ck.is_usable = FALSE;

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    g_vdoply_cntx.full_touch_speed_inc.is_usable = FALSE;
    g_vdoply_cntx.full_touch_speed_dec.is_usable = FALSE;
    g_vdoply_cntx.full_touch_volume_inc.is_usable = FALSE;
    g_vdoply_cntx.full_touch_volume_dec.is_usable = FALSE;
    g_vdoply_cntx.full_touch_progress_inc.is_usable = FALSE;
    g_vdoply_cntx.full_touch_progress_dec.is_usable = FALSE;
    g_vdoply_cntx.full_touch_progress_bar.is_usable = FALSE;
    g_vdoply_cntx.full_touch_rsk.is_usable = FALSE;
    g_vdoply_cntx.full_touch_lsk.is_usable = FALSE;
    g_vdoply_cntx.full_touch_ck.is_usable = FALSE;
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */

    switch (state)
    {
        case VDOPLY_STATE_IDLE:
        case VDOPLY_STATE_PLAY:
        case VDOPLY_STATE_PAUSE:
        case VDOPLY_STATE_INTERRUPTED_PAUSE:
#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_SEND1, KEY_EVENT_UP);//ghw222

#else
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;

#ifdef NO_LSK
            /*shaokai modify it start.090907*/
            //SetKeyHandler(mmi_vdoply_ck_press, KEY_LSK, KEY_EVENT_DOWN);
            //SetKeyHandler(mmi_vdoply_ck_release, KEY_LSK, KEY_EVENT_UP);//ghw222
            SetKeyHandler(mmi_vdoply_ck_press, KEY_ENTER, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_ENTER, KEY_EVENT_UP);
	     /*shaokai modify it end.090907*/
			

#else
            SetKeyHandler(mmi_vdoply_ck_press, KEY_ENTER, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_ENTER, KEY_EVENT_UP);

#endif

            g_vdoply_cntx.touch_ck.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_ck_press, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_0, KEY_EVENT_UP);

        #ifdef __VDOPLY_FEATURE_VOLUME__

#ifdef __MMI_NO_VOL_KEYS__	
	//Ã»ÓÐÒôÁ¿¼üµÄ´¦Àí//sc.wu __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
	 SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_8, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_8, KEY_EVENT_UP);
	#else
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_5, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_5, KEY_EVENT_UP);
	#endif
#else
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif
            g_vdoply_cntx.touch_volume_dec.is_usable = TRUE;
            g_vdoply_cntx.touch_volume_inc.is_usable = TRUE;        
       #endif /* __VDOPLY_FEATURE_VOLUME__ */ 

        #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
        
        #ifdef __VDOPLY_FEATURE_SPEED__
	 #if defined(__SF_MP4_SUPPORT__)  
	  if(mmi_vdoply_get_speed_disable() == FALSE)
	  {
	 #endif
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {
                SetKeyHandler(mmi_vdoply_speed_inc_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_speed_inc_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_speed_dec_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_speed_dec_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_speed_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_speed_inc.is_usable = TRUE;                
            }            
	  #if defined(__SF_MP4_SUPPORT__)  
	  }
	  #endif
        #endif /* __VDOPLY_FEATURE_SPEED__ */ 

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE;    
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;           
            }
        #else /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ /* not horizontal view */
        
        #ifdef __VDOPLY_FEATURE_SPEED__
	 #if defined(__SF_MP4_SUPPORT__)  
	  if(mmi_vdoply_get_speed_disable() == FALSE)
	  {
	 #endif
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {        
                SetKeyHandler(mmi_vdoply_speed_inc_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_speed_inc_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_speed_dec_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_speed_dec_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_speed_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_speed_inc.is_usable = TRUE;                 
            }
        #if defined(__SF_MP4_SUPPORT__)  
	  }
	 #endif 
        #endif /* __VDOPLY_FEATURE_SPEED__ */ 
        
            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE; 
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;                   
            }
        #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 

        #ifdef __VDOPLY_FEATURE_SNAPSHOT__
            if ((g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                 g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY) && 
                 !mdi_video_ply_is_drm_file())
            {     
                /* if has visual track, and not drm file, will be able to snapshot */
                SetKeyHandler(mmi_vdoply_player_snapshot_key_press, KEY_CAMERA, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_player_snapshot_key_release, KEY_CAMERA, KEY_EVENT_UP);

                if (VDOPLY_SNAP_EXTRA_KEY != -1)
                {
                    SetKeyHandler(mmi_vdoply_player_snapshot_key_press, (U16)VDOPLY_SNAP_EXTRA_KEY, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_player_snapshot_key_release, (U16)VDOPLY_SNAP_EXTRA_KEY, KEY_EVENT_UP);
                }
                
                g_vdoply_cntx.touch_snapshot.is_usable = TRUE;
            }
        #endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 

        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                           
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
                }
            }
            else
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                        
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
                }
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            }
        #else /* __MMI_TVOUT__ */ 

        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {           
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                   
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;            
                }
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        #endif /* __MMI_TVOUT__ */ 
            break;


        case VDOPLY_STATE_BT_CONNECTING:  
        #ifdef __VDOPLY_FEATURE_LSK_OPTION__
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;
        #endif 
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;

        #ifdef __VDOPLY_FEATURE_HORIZONTAL_VIEW__
            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE;    
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;           
            }
        #else /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ /* not horizontal view */
           
            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE; 
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;                   
            }
        #endif /* __VDOPLY_FEATURE_HORIZONTAL_VIEW__ */ 

        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                           
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
                }
            }
            else
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                        
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
                }
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            }
        #else /* __MMI_TVOUT__ */ 

        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {           
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                   
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;            
                }
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        #endif /* __MMI_TVOUT__ */ 
            break;
            break;

        case VDOPLY_STATE_OPENING:
        case VDOPLY_STATE_INTERRUPTED_OPENING:
        case VDOPLY_STATE_INTERRUPTED_SEEKING:
        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:        
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;            
            
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);            
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;            
            break;


        case VDOPLY_STATE_STREAM_PLAY:
        case VDOPLY_STATE_STREAM_CONNECTED:
        case VDOPLY_STATE_STREAM_DISCONNECT:

#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);//ghw222
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_SEND1, KEY_EVENT_UP);

#else
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;

#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_ck_press, KEY_LSK, KEY_EVENT_DOWN);//ghw222
            SetKeyHandler(mmi_vdoply_ck_release, KEY_LSK, KEY_EVENT_UP);

#else
            SetKeyHandler(mmi_vdoply_ck_press, KEY_ENTER, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_ENTER, KEY_EVENT_UP);

#endif

            g_vdoply_cntx.touch_ck.is_usable = TRUE;
            
            SetKeyHandler(mmi_vdoply_ck_press, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_0, KEY_EVENT_UP);

        #ifdef __VDOPLY_FEATURE_VOLUME__



#ifdef __MMI_NO_VOL_KEYS__ 
//sc.wu __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
	//Huyanwei Modify it .Have Side Key			
	 SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_8, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_8, KEY_EVENT_UP);
	#else
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_5, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_5, KEY_EVENT_UP);
	#endif				
#else
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif			
            g_vdoply_cntx.touch_volume_dec.is_usable = TRUE;
            g_vdoply_cntx.touch_volume_inc.is_usable = TRUE;          
        #endif /* __VDOPLY_FEATURE_VOLUME__ */ 

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE; 
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;     
            }

        #ifdef __VDOPLY_FEATURE_SNAPSHOT__
            if ((g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                 g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY) && 
                 !mdi_video_ply_is_drm_file())
            {
                /* if has visual track, and not drm file, will be able to snapshot */                
                SetKeyHandler(mmi_vdoply_player_snapshot_key_press, KEY_CAMERA, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_player_snapshot_key_release, KEY_CAMERA, KEY_EVENT_UP);
                
                if (VDOPLY_SNAP_EXTRA_KEY != -1)
                {
                    SetKeyHandler(mmi_vdoply_player_snapshot_key_press, (U16)VDOPLY_SNAP_EXTRA_KEY, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_player_snapshot_key_release, (U16)VDOPLY_SNAP_EXTRA_KEY, KEY_EVENT_UP);
                }                
                
                g_vdoply_cntx.touch_snapshot.is_usable = TRUE;
            }
        #endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 

        #ifdef __MMI_TVOUT__
        
            if (mdi_tvout_is_enable())
            {
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                          
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                       
                }
            }
            else
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                          
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                       
                }
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            }
        #else /* __MMI_TVOUT__ */ 

        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {            
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                              
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
                }
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        #endif /* __MMI_TVOUT__ */             
            break;

        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);            
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;      

        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                           
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;        
                }
            }
            else
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {              
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;     
                }
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            }
        #else /* __MMI_TVOUT__ */ 

        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {            
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        #endif /* __MMI_TVOUT__ */                    
            break;

        case VDOPLY_STATE_STREAM_BUFFERING:
        case VDOPLY_STATE_STREAM_BT_CONNECTING:            
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);            
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;      

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE;    
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;           
            }

        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                                 
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                       
                }
            }
            else
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {       
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;          
            }
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            }
        #else /* __MMI_TVOUT__ */ 

        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {             
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        #endif /* __MMI_TVOUT__ */        
            
            break;
        
            /* Full Screen */
        case VDOPLY_STATE_FULLSCR_IDLE:
        case VDOPLY_STATE_FULLSCR_PLAY:
        case VDOPLY_STATE_FULLSCR_PAUSE:
          
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD */
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_1, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_2, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_3, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_4, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_5, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_6, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_7, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_8, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_9, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_0, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_ENTER, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);

        #ifdef __VDOPLY_FEATURE_VOLUME__

#ifdef __MMI_NO_VOL_KEYS__   
	//sc.wu  __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
	//Huyanwei Modify it .Have No Side Key 
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_8, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_8, KEY_EVENT_UP);
	#else			
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_5, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_5, KEY_EVENT_UP);
	#endif			
#else
	SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif		
            g_vdoply_cntx.full_touch_volume_dec.is_usable = TRUE;
            g_vdoply_cntx.full_touch_volume_inc.is_usable = TRUE;              
        #endif /* __VDOPLY_FEATURE_VOLUME__ */ 

        #else  /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            /* have OSD */
#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_SEND1, KEY_EVENT_UP);//ghw222

#else
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif
            g_vdoply_cntx.full_touch_lsk.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_rsk.is_usable = TRUE;
                   
#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_ck_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_LSK, KEY_EVENT_UP);//ghw222

#else
            SetKeyHandler(mmi_vdoply_ck_press, KEY_ENTER, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_ENTER, KEY_EVENT_UP);
#endif
                   
            g_vdoply_cntx.full_touch_ck.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_ck_press, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_0, KEY_EVENT_UP);
            
        #ifdef __VDOPLY_FEATURE_SPEED__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {            
                SetKeyHandler(mmi_vdoply_speed_inc_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_speed_inc_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_speed_dec_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_speed_dec_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.full_touch_speed_dec.is_usable = TRUE;
                g_vdoply_cntx.full_touch_speed_inc.is_usable = TRUE;    
            }
        #endif /* __VDOPLY_FEATURE_SPEED__ */ 

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.full_touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.full_touch_progress_inc.is_usable = TRUE;  
                g_vdoply_cntx.full_touch_progress_bar.is_usable = TRUE;       
            }

        #ifdef __VDOPLY_FEATURE_VOLUME__

		//Huyanwei Modify it .Have Side Key 
#ifdef __MMI_NO_VOL_KEYS__
//sc.wu  __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_8, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_8, KEY_EVENT_UP);
	#else
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_5, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_5, KEY_EVENT_UP);
	#endif
#else
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_VOL_UP, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_VOL_UP, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif		
            g_vdoply_cntx.full_touch_volume_dec.is_usable = TRUE;
            g_vdoply_cntx.full_touch_volume_inc.is_usable = TRUE;              
        #endif /* __VDOPLY_FEATURE_VOLUME__ */ 
            
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {            
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);
            }
        #endif 
        
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
  
            break;

        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
          
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD */
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_1, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_2, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_3, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_4, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_5, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_6, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_7, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_8, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_9, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_0, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_ENTER, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);

         #else  /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            /* have OSD */
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_lsk.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_rsk.is_usable = TRUE;

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.full_touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.full_touch_progress_inc.is_usable = TRUE;  
                g_vdoply_cntx.full_touch_progress_bar.is_usable = TRUE;       
            }
                
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {            
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);
            }
        #endif 
        
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
  
            break;


        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT: 

        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD */
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_1, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_2, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_3, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_4, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_5, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_6, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_7, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_8, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_9, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_0, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_ENTER, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);

        #ifdef __VDOPLY_FEATURE_VOLUME__

		//Huyanwei Modify it .Have Side Key 
#ifdef __MMI_NO_VOL_KEYS__   //sc.wu  __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_8, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_8, KEY_EVENT_UP);
	#else
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_5, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_5, KEY_EVENT_UP);
	#endif
#else
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_VOL_UP, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_VOL_UP, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif    
            g_vdoply_cntx.full_touch_volume_dec.is_usable = TRUE;
            g_vdoply_cntx.full_touch_volume_inc.is_usable = TRUE;              
        #endif /* __VDOPLY_FEATURE_VOLUME__ */ 

        #else  /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            /* have OSD */
#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_SEND1, KEY_EVENT_DOWN);//ghw222
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_SEND1, KEY_EVENT_UP);

#else
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);

#endif
            g_vdoply_cntx.full_touch_lsk.is_usable = TRUE;
            
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_rsk.is_usable = TRUE;

#ifdef NO_LSK
            SetKeyHandler(mmi_vdoply_ck_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_LSK, KEY_EVENT_UP);//ghw222

#else
            SetKeyHandler(mmi_vdoply_ck_press, KEY_ENTER, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_ENTER, KEY_EVENT_UP);

#endif

            g_vdoply_cntx.full_touch_ck.is_usable = TRUE;

            SetKeyHandler(mmi_vdoply_ck_press, KEY_0, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_ck_release, KEY_0, KEY_EVENT_UP);

        #ifdef __VDOPLY_FEATURE_VOLUME__
#ifdef __MMI_NO_VOL_KEYS__   //sc.wu  __MMI_NO_VOL_KEYS__
	#if defined(__VOL_WITH_28KEY__)
		//Huyanwei Modify it .Have Side Key 
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_8, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_8, KEY_EVENT_UP);
	#else
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_2, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_2, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_5, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_5, KEY_EVENT_UP);
	#endif
#else
		SetKeyHandler(mmi_vdoply_vol_up_key_press, KEY_VOL_UP, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_up_key_release, KEY_VOL_UP, KEY_EVENT_UP);
		SetKeyHandler(mmi_vdoply_vol_down_key_press, KEY_VOL_DOWN, KEY_EVENT_DOWN);
		SetKeyHandler(mmi_vdoply_vol_down_key_release, KEY_VOL_DOWN, KEY_EVENT_UP);
#endif		
            g_vdoply_cntx.touch_volume_dec.is_usable = TRUE;
            g_vdoply_cntx.touch_volume_inc.is_usable = TRUE;          
        #endif /* __VDOPLY_FEATURE_VOLUME__ */ 

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.full_touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.full_touch_progress_inc.is_usable = TRUE;  
                g_vdoply_cntx.full_touch_progress_bar.is_usable = TRUE;     
            }
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {    
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);
            }
        #endif 
        
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_rsk.is_usable = TRUE;            

            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {     
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            break;            


        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:            
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD */
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_1, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_2, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_3, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_4, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_5, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_6, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_7, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_8, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_9, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_0, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_ENTER, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);

        #else  /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_rsk.is_usable = TRUE;            

            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {     
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;  
            }
            
            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.full_touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.full_touch_progress_inc.is_usable = TRUE;  
                g_vdoply_cntx.full_touch_progress_bar.is_usable = TRUE;     
            }
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */         
            break;         


        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:
        #ifdef __MMI_VIDEO_PDL__
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);     
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;    
        
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;      
        #endif /* __MMI_VIDEO_PDL__ */
            break;

        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:            
        #ifdef __MMI_VIDEO_PDL__
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);     
            g_vdoply_cntx.touch_lsk.is_usable = TRUE;    
        
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.touch_rsk.is_usable = TRUE;      

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.touch_progress_inc.is_usable = TRUE;  
                g_vdoply_cntx.touch_progress_bar.is_usable = TRUE;     
            }
            
        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                    g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
                {                           
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_tvout_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;        
                }
            }
            else
            {
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {                 
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                    SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                    g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                       
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
            }
        #else /* __MMI_TVOUT__ */ 

        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {            
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;                   
            }
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        #endif /* __MMI_TVOUT__ */        
        
        #endif /* __MMI_VIDEO_PDL__ */
            break;
        
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:        
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
        #ifdef __MMI_VIDEO_PDL__
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* no OSD */
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_1, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_2, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_3, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_4, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_5, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_6, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_7, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_8, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_9, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_0, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RSK, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_ENTER, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_UP_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_DOWN_ARROW, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_CLEAR, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoply_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_UP);

        #else  /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            SetKeyHandler(mmi_vdoply_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_lsk_release, KEY_LSK, KEY_EVENT_UP);     
            g_vdoply_cntx.full_touch_lsk.is_usable = TRUE;    
        
            SetKeyHandler(mmi_vdoply_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoply_rsk_release, KEY_RSK, KEY_EVENT_UP);
            g_vdoply_cntx.full_touch_rsk.is_usable = TRUE; 

            if (g_vdoply_cntx.is_progress_seekable)
            {
                SetKeyHandler(mmi_vdoply_seek_backward_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_backward_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
                SetKeyHandler(mmi_vdoply_seek_foward_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_seek_foward_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
                g_vdoply_cntx.full_touch_progress_dec.is_usable = TRUE;
                g_vdoply_cntx.full_touch_progress_inc.is_usable = TRUE;  
                g_vdoply_cntx.full_touch_progress_bar.is_usable = TRUE;     
            }
            
            if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_AV ||
                g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_V_ONLY)
            {     
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_press, KEY_STAR, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdoply_toggle_fullscreen_key_release, KEY_STAR, KEY_EVENT_UP);
                g_vdoply_cntx.touch_fullscreen.is_usable = TRUE;              
            }
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */            
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        #endif /* __MMI_VIDEO_PDL__ */
            break;
    }
   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_set_state_layer_config
 * DESCRIPTION
 *  set layer configuration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_set_state_layer_config(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter next state */
    switch (state)
    {
        case VDOPLY_STATE_IDLE:
        case VDOPLY_STATE_PLAY:       
        case VDOPLY_STATE_PAUSE:
        case VDOPLY_STATE_INTERRUPTED_PAUSE:  
        case VDOPLY_STATE_INTERRUPTED_SEEKING:
        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:
        case VDOPLY_STATE_STREAM_PLAY:
        case VDOPLY_STATE_STREAM_DISCONNECT: 
        case VDOPLY_STATE_STREAM_CONNECTED: 
            gdi_lcd_set_rotate(g_vdoply_cntx.normal_style_rotate);
            gdi_layer_resize(g_vdoply_cntx.normal_style_lcd_width, g_vdoply_cntx.normal_style_lcd_height);

        #ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
            /* newer cip has layer bg color, we can split bg into smaller region for better performance */
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.bg_region_0_layer_handle, 
                g_vdoply_cntx.bg_region_1_layer_handle,             
                g_vdoply_cntx.play_wnd_layer_handle, 
                0);
        #else
            /* MT6219 dont have bg color - we need use bg layer as lcd size */    
            gdi_layer_set_blt_layer(g_vdoply_cntx.bg_layer_handle, g_vdoply_cntx.play_wnd_layer_handle, 0, 0);
        #endif            
            break;

        case VDOPLY_STATE_OPENING:
        case VDOPLY_STATE_INTERRUPTED_OPENING:
        case VDOPLY_STATE_SNAPSHOT: 
        case VDOPLY_STATE_BT_CONNECTING:
        case VDOPLY_STATE_STREAM_BT_CONNECTING: 
        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
        case VDOPLY_STATE_STREAM_BUFFERING: 
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING: 
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:            
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:            
            gdi_lcd_set_rotate(g_vdoply_cntx.normal_style_rotate);
            gdi_layer_resize(g_vdoply_cntx.normal_style_lcd_width, g_vdoply_cntx.normal_style_lcd_height);

        #ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__
            /* newer cip has layer bg color, we can split bg into smaller region for better performance */
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.bg_region_0_layer_handle, 
                g_vdoply_cntx.bg_region_1_layer_handle,  
                g_vdoply_cntx.play_wnd_layer_handle,
                g_vdoply_cntx.process_layer_handle);
        #else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
            /* MT6219 dont have bg color - we need use bg layer as lcd size */    
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.bg_layer_handle, 
                g_vdoply_cntx.play_wnd_layer_handle, 
                g_vdoply_cntx.process_layer_handle,
                0);                
        #endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
            break;
    
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /******************************************/
        /*              Full Screen               */
        /******************************************/
        case VDOPLY_STATE_FULLSCR_IDLE:
        case VDOPLY_STATE_FULLSCR_PLAY: 
        case VDOPLY_STATE_FULLSCR_PAUSE:  
        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:   
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            
            gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);

        #ifndef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__    
            /* if we use multi region in vertical screen, we need to resize the layer here */        
	    	gdi_layer_resize(UI_device_height, UI_device_width);
	    #endif

        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.fullscr_play_layer_handle, 
                0, 
                0, 
                0);
        #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.fullscr_play_layer_handle, 
                g_vdoply_cntx.osd_layer_handle, 
                0, 
                0);
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:            
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:            
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            
            gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);

        #ifndef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__    
            /* if we use multi region in vertical screen, we need to resize the layer here */        
	    	gdi_layer_resize(UI_device_height, UI_device_width);
	    #endif

            /* 
             *  connecting and loading state dont have video performance problem,
             *  we will show the connecting or loading bar 
             */
        #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.fullscr_play_layer_handle, 
                g_vdoply_cntx.process_layer_handle, 
                0, 
                0);
        #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            gdi_layer_set_blt_layer(
                g_vdoply_cntx.fullscr_play_layer_handle, 
                g_vdoply_cntx.osd_layer_handle, 
                g_vdoply_cntx.process_layer_handle, 
                0);
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;

        
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
  

    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_set_state_softkey
 * DESCRIPTION
 *  set softkey based on state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_set_state_softkey(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* enter next state */
    switch (state)
    {
        /***********/
        case VDOPLY_STATE_EXIT:
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL,
                    NULL,
                    IMG_ID_VDOPLY_LSK_OPTION,
                    IMG_ID_VDOPLY_RSK_BACK,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Horizontal] */
                if (g_vdoply_cntx.cur_status.play_time == 0)
                {
                mmi_vdoply_set_softkey(
                    NULL, 
                    NULL, 
                    IMG_ID_VDOPLY_LSK_PLAY, 
                    IMG_ID_VDOPLY_RSK_BACK, 
                    0);
                }
                else
                {
                    mmi_vdoply_set_softkey(
                        NULL, 
                        NULL, 
                        IMG_ID_VDOPLY_LSK_RESUME, 
                        IMG_ID_VDOPLY_RSK_BACK, 
                        0);
                }
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Touch][Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                if (g_vdoply_cntx.cur_status.play_time == 0)
                {
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_PLAY),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
                }
                else
                {
                    mmi_vdoply_set_softkey(
                        (PS8)GetString(STR_ID_VDOPLY_RESUME),
                        (PS8)GetString(STR_GLOBAL_BACK),
                        0,
                        0,
                        IMG_ID_VDOPLY_CK_PLAY);
                }
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

           
        case VDOPLY_STATE_IDLE:
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL,
                    NULL,
                    IMG_ID_VDOPLY_LSK_OPTION,
                    IMG_ID_VDOPLY_RSK_BACK,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Horizontal] */
                mmi_vdoply_set_softkey(
                    NULL, 
                    NULL, 
                    IMG_ID_VDOPLY_LSK_PLAY, 
                    IMG_ID_VDOPLY_RSK_BACK, 
                    0);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Touch][Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Touch] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_PLAY),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;


        /***********/
        case VDOPLY_STATE_PLAY:
        case VDOPLY_STATE_BT_CONNECTING:
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL,
                    NULL,
                    IMG_ID_VDOPLY_LSK_OPTION,
                    IMG_ID_VDOPLY_RSK_STOP,
                    IMG_ID_VDOPLY_CK_PAUSE);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Horizontal] */
                mmi_vdoply_set_softkey(
                    NULL, 
                    NULL, 
                    IMG_ID_VDOPLY_LSK_PAUSE, 
                    IMG_ID_VDOPLY_RSK_STOP, 
                    0);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_ID_VDOPLY_STOP),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PAUSE);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_PAUSE),
                    (PS8) GetString(STR_ID_VDOPLY_STOP),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PAUSE);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;


        /***********/
        case VDOPLY_STATE_PAUSE:
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL, 
                    NULL, 
                    IMG_ID_VDOPLY_LSK_OPTION, 
                    IMG_ID_VDOPLY_RSK_STOP, 
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Horizontal] */
                mmi_vdoply_set_softkey(
                    NULL, 
                    NULL, 
                    IMG_ID_VDOPLY_LSK_PLAY, 
                    IMG_ID_VDOPLY_RSK_STOP, 
                    0);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_ID_VDOPLY_STOP),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_RESUME);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_RESUME),
                    (PS8) GetString(STR_ID_VDOPLY_STOP),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_RESUME);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */   
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;


        /***********/
        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL,
                    NULL,
                    IMG_ID_VDOPLY_LSK_OPTION,
                    IMG_ID_VDOPLY_RSK_STOP,
                    IMG_ID_VDOPLY_CK_RESUME);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Horizontal] */
                mmi_vdoply_set_softkey(NULL, NULL, IMG_ID_VDOPLY_LSK_RESUME, IMG_ID_VDOPLY_RSK_STOP, 0);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_ID_VDOPLY_STOP),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_RESUME);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_RESUME),
                    (PS8) GetString(STR_ID_VDOPLY_STOP),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_RESUME);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

        /***********/
        case VDOPLY_STATE_OPENING:
        case VDOPLY_STATE_INTERRUPTED_OPENING:

        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL,
                    NULL,
                    IMG_ID_VDOPLY_LSK_OPTION,
                    IMG_ID_VDOPLY_RSK_BACK,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                if (g_vdoply_cntx.cur_status.play_time == 0)
                {
                    mmi_vdoply_set_softkey(
                        NULL, 
                        NULL, 
                        IMG_ID_VDOPLY_LSK_PLAY, 
                        IMG_ID_VDOPLY_RSK_BACK, 
                        0);
                }
                else
                {
                    mmi_vdoply_set_softkey(
                        NULL, 
                        NULL, 
                        IMG_ID_VDOPLY_LSK_RESUME, 
                        IMG_ID_VDOPLY_RSK_BACK, 
                        0);
                }
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Touch][Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                if (g_vdoply_cntx.cur_status.play_time == 0)
                {
                   mmi_vdoply_set_softkey(
                        (PS8) GetString(STR_ID_VDOPLY_PLAY),
                        (PS8) GetString(STR_GLOBAL_BACK),
                        0,
                        0,
                        IMG_ID_VDOPLY_CK_PLAY);
                }
                else
                {
                    mmi_vdoply_set_softkey(
                        (PS8)GetString(STR_ID_VDOPLY_RESUME),
                        (PS8)GetString(STR_GLOBAL_BACK),
                        0,
                        0,
                        IMG_ID_VDOPLY_CK_PLAY);
                }
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;


        /***********/
        case VDOPLY_STATE_INTERRUPTED_SEEKING:
        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:
            break;
        
    /*******************************/
    /*******    Fullscreen  ********/
    /*******************************/  
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /***********/    
        case VDOPLY_STATE_FULLSCR_IDLE:
            mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_PLAY),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY);
            break;

            
        /***********/    
        case VDOPLY_STATE_FULLSCR_PLAY:
        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:            
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* have OSD */
            mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_PAUSE),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PAUSE);
         #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;
         
            
        /***********/    
        case VDOPLY_STATE_FULLSCR_PAUSE:
            mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_RESUME),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_RESUME);
            break;


        /***********/    
        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            break;

    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 


    /*******************************/
    /*******    Streaming   ********/
    /*******************************/  
    #ifdef __MMI_VIDEO_STREAM__
        /***********/        
        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:            
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            /* [Horizontal][Option] */
            mmi_vdoply_set_softkey(
                NULL,
                NULL,
                IMG_ID_VDOPLY_LSK_OPTION,
                IMG_ID_VDOPLY_RSK_STOP,
                IMG_ID_VDOPLY_CK_PLAY);
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */
            /* [Touch][Option] */
            mmi_vdoply_set_softkey(
                (PS8)GetString(STR_GLOBAL_OPTIONS),
                (PS8)GetString(STR_ID_VDOPLY_STOP),
                0,
                0,
                IMG_ID_VDOPLY_CK_PLAY);
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

        case VDOPLY_STATE_STREAM_CONNECTED:            
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            /* [Horizontal][Option] */
            mmi_vdoply_set_softkey(
                NULL,
                NULL,
                IMG_ID_VDOPLY_LSK_OPTION,
                IMG_ID_VDOPLY_RSK_BACK,
                IMG_ID_VDOPLY_CK_PLAY);
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */
            /* [Touch][Option] */
            mmi_vdoply_set_softkey(
                (PS8)GetString(STR_GLOBAL_OPTIONS),
                (PS8)GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_CK_PLAY);
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;
 
        case VDOPLY_STATE_STREAM_PLAY:
        case VDOPLY_STATE_STREAM_BUFFERING:
        case VDOPLY_STATE_STREAM_BT_CONNECTING:             
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            /* [Horizontal][Option] */
            mmi_vdoply_set_softkey(
                NULL,
                NULL,
                IMG_ID_VDOPLY_LSK_OPTION,
                IMG_ID_VDOPLY_RSK_STOP,
                IMG_ID_VDOPLY_CK_PAUSE);
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */
            /* [Touch][Option] */
            mmi_vdoply_set_softkey(
                (PS8)GetString(STR_GLOBAL_OPTIONS),
                (PS8)GetString(STR_ID_VDOPLY_STOP),
                0,
                0,
                IMG_ID_VDOPLY_CK_PAUSE);
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */                      
            break;            

           
        case VDOPLY_STATE_STREAM_DISCONNECT:  

        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            /* [Horizontal][Option] */
            mmi_vdoply_set_softkey(
                NULL,
                NULL,
                IMG_ID_VDOPLY_LSK_OPTION,
                IMG_ID_VDOPLY_RSK_BACK,
                IMG_ID_VDOPLY_CK_PLAY);
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */
            /* [Touch][Option] */
            mmi_vdoply_set_softkey(
                (PS8)GetString(STR_GLOBAL_OPTIONS),
                (PS8)GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_CK_PLAY);
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */                
            break;            


   
         /***********/        
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
             mmi_vdoply_set_softkey(
                0,
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY);
         #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:     
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
             mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_PLAY),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY);
         #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;      

        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* have OSD */
            mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_PAUSE),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PAUSE);
         #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;            

        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:     
        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:             
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* have OSD */
            mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_PLAY),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY);
         #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;  
           
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:  
        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            /* have OSD */
            mmi_vdoply_set_softkey(
                (PS8) GetString(STR_ID_VDOPLY_PLAY),
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PLAY);
         #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */      
            break;            
   
    #endif /* __MMI_VIDEO_STREAM__ */

    /*******************************/
    /******* Progressive DL ********/
    /*******************************/    
    #ifdef __MMI_VIDEO_PDL__
        /***********/       
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:

        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Horizontal][Option] */
                mmi_vdoply_set_softkey(
                    NULL,
                    NULL,
                    IMG_ID_VDOPLY_LSK_OPTION,
                    IMG_ID_VDOPLY_RSK_BACK,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Horizontal] */
                mmi_vdoply_set_softkey(NULL, NULL, IMG_ID_VDOPLY_LSK_PLAY, IMG_ID_VDOPLY_RSK_BACK, 0);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Touch][Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Touch] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_PLAY),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

        /***********/       
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:        
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:
        #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                    /* [Horizontal][Option] */
                    mmi_vdoply_set_softkey(
                        NULL,
                        NULL,
                        IMG_ID_VDOPLY_LSK_OPTION,
                        IMG_ID_VDOPLY_RSK_BACK,
                        IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                    /* [Horizontal] */
                    mmi_vdoply_set_softkey(NULL, NULL, IMG_ID_VDOPLY_LSK_PLAY, IMG_ID_VDOPLY_RSK_BACK, 0);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            {
            #if defined(__VDOPLY_FEATURE_LSK_OPTION__)
                /* [Touch][Option] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_GLOBAL_OPTIONS),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #else /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
                /* [Touch] */
                mmi_vdoply_set_softkey(
                    (PS8) GetString(STR_ID_VDOPLY_PLAY),
                    (PS8) GetString(STR_GLOBAL_BACK),
                    0,
                    0,
                    IMG_ID_VDOPLY_CK_PLAY);
            #endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 
            }
        #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
            break;

        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
             mmi_vdoply_set_softkey(
                0,
                (PS8) GetString(STR_GLOBAL_BACK),
                0,
                0,
                IMG_ID_VDOPLY_FULLSCR_OSD_CK_PAUSE);
              break;
              
    #endif /*   __MMI_VIDEO_PDL__ */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_calc_progress_ratio
 * DESCRIPTION
 *  set layer configuration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_calc_progress_ratio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 play_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdoply_cntx.is_source_opened || !g_vdoply_cntx.video_info.is_seekable)
    {
        g_vdoply_cntx.cur_status.play_ratio = 0;      
        return;
    }

    play_time = g_vdoply_cntx.cur_status.play_time;

    if (g_vdoply_cntx.video_info.is_seekable)
    {
        /* avoid driver return play time > video length */
        if (play_time > g_vdoply_cntx.video_info.total_time_duration)
        {
            play_time = g_vdoply_cntx.video_info.total_time_duration;
        }
    }
    
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
        g_vdoply_cntx.cur_status.play_ratio 
            = (U32)(play_time * 
                    g_vdoply_cntx.progress.fill_width / 
                    g_vdoply_cntx.video_info.total_time_duration);

        g_vdoply_cntx.cur_status.buff_ratio 
            =  (U32)(g_vdoply_cntx.cur_status.max_play_time *
                     g_vdoply_cntx.progress.fill_width /
                     g_vdoply_cntx.video_info.total_time_duration); 

    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
        g_vdoply_cntx.cur_status.play_ratio =
            (U32)(play_time * 
                  g_vdoply_cntx.fullscr_progress.fill_width / 
                  g_vdoply_cntx.video_info.total_time_duration);

        g_vdoply_cntx.cur_status.buff_ratio 
            =  (U32)(g_vdoply_cntx.cur_status.max_play_time *
                     g_vdoply_cntx.fullscr_progress.fill_width /
                     g_vdoply_cntx.video_info.total_time_duration);        
    }
    else
    {   
        /* shall not enter here */
        MMI_ASSERT(0);
    }
}



#ifdef __SF_MP4_SUPPORT__ 


void mmi_vdoply_upd_update_all(void)
{
    if(!appex.bIsActive)
        return;
    mmi_vdoply_upd_redraw();
    mmi_vdoply_blt_screen();
}



void mmi_vdoply_upd_callback(mmi_vdoply_touch_area* param)
{
    kal_prompt_trace(MOD_MMI,"mmi_vdoply_upd: link callback");
    appex.bActiveLink=1;
    mmi_vdoply_draw_softkey();
    mmi_vdoply_blt_screen();
    mmi_vdoply_close_file();
    mmi_vdoply_enter_state(VDOPLY_STATE_EXIT);
}

typedef long mmi_vdoply_coord_t;
typedef struct _mmi_vdoply_rect_t
{
    mmi_vdoply_coord_t left;
    mmi_vdoply_coord_t top;
    mmi_vdoply_coord_t right;
    mmi_vdoply_coord_t bottom;
} mmi_vdoply_rect_t;

typedef struct _mmi_vdoply_render_area_t
{
    void* pBuffer;
    int iPitch;
    int iWidth;
    int iHeight;
    
} mmi_vdoply_render_area_t;

#ifndef WIN32
void vdo_render_link(mmi_vdoply_render_area_t* area,int flag);
#endif


extern void vdo_calc_touch_rect(mmi_vdoply_render_area_t* area,struct _mmi_vdoply_rect_t* pRect);


void mmi_vdoply_upd_enter(void)
{
    //kal_prompt_trace(MOD_MMI,"mmi_vdoply_upd: init");
    appex.iTime=0;
    appex.bIsActive=0;
    appex.bActiveLink=0;
    appex.bPlayed=0;
    appex.iLinkText=(U8*)L"For More Video, Click Here";
    appex.iAreaList=area_list;
    appex.iAreaCount=sizeof(area_list)/sizeof(area_list[0]);
    appex.iActiveArea=NULL;
    area_list[AREA_LINK].callback=mmi_vdoply_upd_callback;

}
    
void mmi_vdoply_upd_callback_lv(void)
{
    mmi_vdoply_upd_callback(NULL);
}

void mmi_vdoply_upd_activatee(void)
{
    struct _mmi_vdoply_rect_t rc;
    mmi_vdoply_render_area_t area;
    int w,h,x,y;

#ifndef WIN32
	//Huyanwei Add Macro
	extern const char* vdo_get_wap_service_url(int service_id);
    if(strcmp(vdo_get_wap_service_url(0),"none")!=0)
#else
   if( 0 )	
#endif		

    {
#ifdef WAP_SUPPORT
	    appex.iTime=0;
	    appex.bIsActive=1;
	    appex.bActiveLink=0;
	    //gui_start_timer(SFVDOPLYAPP_TIMER_INTERVAL,mmi_vdoply_upd_callback_t);
	
	    
	    //int text_len=sf_strlen(appex.iLinkText);
		gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
	    
	    gdi_layer_get_buffer_ptr((U8 * *)&area.pBuffer);
	    gdi_layer_get_dimension((S32 *)&w,(S32 *) &h);
	    gdi_layer_get_position((S32 *)&x,(S32 *) &y);
	    area.iWidth=area.iPitch=w;
	    area.iHeight=h;
#ifdef MMI_ON_HARDWARE_P
	    kal_prompt_trace(MOD_MMI,"p %x %d %d",(int)area.pBuffer,w,h);
#endif //MMI_ON_HARDWARE_P
	    vdo_calc_touch_rect(&area,&rc);
	    area_list[AREA_LINK].x=x+rc.left;
	    area_list[AREA_LINK].y=y+rc.top;
	    area_list[AREA_LINK].width=rc.right-rc.left;
	    area_list[AREA_LINK].height=rc.bottom-rc.top;
	    gdi_layer_pop_and_restore_active();
#if !defined(__MMI_TOUCH_SCREEN__)
#ifdef __SF_MP4_LINK_USE_OK_KEY__
	    SetKeyHandler(&mmi_vdoply_upd_callback_lv,KEY_ENTER,KEY_EVENT_UP);
	    ClearKeyHandler(KEY_ENTER,KEY_EVENT_DOWN);
#endif //__SF_MP4_LINK_USE_OK_KEY__
#endif //!defined(__MMI_TOUCH_SCREEN__)
	    SetKeyHandler(&mmi_vdoply_upd_callback_lv,KEY_5,KEY_EVENT_UP);
	    ClearKeyHandler(KEY_5,KEY_EVENT_DOWN);
#endif //WAP_SUPPORT
	}
    
}
void mmi_vdoply_upd_deactivate(void)
{
    if(appex.bIsActive)
    {
        kal_prompt_trace(MOD_MMI,"mmi_vdoply_upd: deactive");
        appex.iTime=0;
        appex.bIsActive=0;
        //gui_cancel_timer(mmi_vdoply_upd_callback_t);
#if !defined(__MMI_TOUCH_SCREEN__)
    ClearKeyHandler(KEY_5,KEY_EVENT_UP);
#endif //!defined(__MMI_TOUCH_SCREEN__)
    }
}
mmi_vdoply_touch_area* mmi_vdoply_upd_ta_from_position(int x,int y)
{
    int i;
    if(!appex.bIsActive)
        return NULL;
    for(i=0;i<appex.iAreaCount;i++)
    {
        mmi_vdoply_touch_area* a=&appex.iAreaList[i];
        if(!a->is_active)
            continue;
        if(x>=a->x && x<a->x+a->width && y>=a->y && y<a->y+a->height)
        {
            return a;
        }
    }
    return NULL;
}

#if defined(__MMI_TOUCH_SCREEN__)
int mmi_vdoply_upd_on_pen_down(int x,int y)
{
    mmi_vdoply_touch_area* a=mmi_vdoply_upd_ta_from_position(x,y);
    if(!appex.bIsActive)
        return 0;
    kal_prompt_trace(MOD_MMI,"mmi_vdoply_upd: pen down");
    if(!a)
        return 0;
    a->is_pressed=1;
    appex.iActiveArea=a;
    mmi_vdoply_upd_update_all();
    return 1;
}
int mmi_vdoply_upd_on_pen_move(int x,int y)
{
    mmi_vdoply_touch_area* a=mmi_vdoply_upd_ta_from_position(x,y);
    if(!appex.bIsActive)
        return 0;
    kal_prompt_trace(MOD_MMI,"mmi_vdoply_upd: pen move");
    if(a!=appex.iActiveArea)
    {
        if(appex.iActiveArea)
            appex.iActiveArea->is_pressed=0;
        if(a)
            a->is_pressed=1;
        appex.iActiveArea=a;
        mmi_vdoply_upd_update_all();
    }
    return a?1:0;
}

int mmi_vdoply_upd_on_pen_up(int x,int y)
{
    mmi_vdoply_touch_area* a;
    if(!appex.bIsActive)
        return 0;
    a=mmi_vdoply_upd_ta_from_position(x,y);
    kal_prompt_trace(MOD_MMI,"mmi_vdoply_upd: pen up");
    if(appex.iActiveArea && appex.iActiveArea->is_pressed)
    {
        appex.iActiveArea->is_pressed=0;
        mmi_vdoply_upd_update_all();
        if(appex.iActiveArea==a && appex.iActiveArea->callback)
            (*appex.iActiveArea->callback)(appex.iActiveArea);
        appex.iActiveArea=NULL;
        return 1;
    }
    else
    {
        return 0;
    }
    
}
#endif //defined(__MMI_TOUCH_SCREEN__)



void mmi_vdoply_upd_redraw(void)
{
    color crlink;
    int w,h;
    int x,y;
    mmi_vdoply_render_area_t area;
    //int text_len=sf_strlen(appex.iLinkText);
    //int w,h;
    if(!appex.bIsActive)
        return;
    switch (g_vdoply_cntx.state)
    {
    case VDOPLY_STATE_IDLE:
	//case VDOPLY_STATE_PAUSE:
	    //mmi_vdoply_draw_play_region_bg();
        kal_prompt_trace(MOD_MMI,"draw link");
    	gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
        gdi_layer_push_clip();
        gdi_layer_push_text_clip();
        
        gdi_layer_get_buffer_ptr((U8 * *)&area.pBuffer);
        gdi_layer_get_dimension((S32 *)&w,(S32 *) &h);
        area.iWidth=area.iPitch=w;
        area.iHeight=h;
        //kal_prompt_trace(MOD_MMI,"p %x %d %d",(int)area.pBuffer,w,h);
#ifndef WIN32        
//Huyanwei Add Macro
#ifdef __SF_MP4_LINK_USE_OK_KEY__
        vdo_render_link(&area,0x40000000|(area_list[AREA_LINK].is_pressed?0x80000000:0));
#else //__SF_MP4_LINK_USE_OK_KEY__
        vdo_render_link(&area,area_list[AREA_LINK].is_pressed?0x80000000:0);
#endif //__SF_MP4_LINK_USE_OK_KEY__
#endif
        //gdi_layer_get_position((S32 *)&offx,(S32 *) &offy)
        
    	//gdi_draw_button_rect(S32 x1,S32 y1,S32 x2,S32 y2,gdi_color rect_color,gdi_color frame_color,U16 frame_width,U16 button_height,BOOL invert)
        
        //if(appex.iTime<text_len){
        //    text_len=appex.iTime;
        //}
        //gui_set_font(&MMI_small_font);
        //gui_set_text_color(area_list[AREA_LINK].is_pressed?gui_color(0,0,255):gui_color(255,255,255));
        //gui_measure_string_n((UI_string_type)appex.iLinkText,text_len,&w,&h);
        //gui_reset_clip();
        //gui_set_text_clip(16,16,w,h);
        //gui_move_text_cursor(16,16);
    	//gui_print_text((UI_string_type)appex.iLinkText);
        gdi_layer_pop_text_clip();
        gdi_layer_pop_clip();
    	gdi_layer_pop_and_restore_active();
        break;
    }
}

void mmi_vdoply_upd_callback_t(void)
{
    if(appex.bIsActive)
    {
#ifndef WIN32    	
	//Huyanwei Add Macro
        int text_len=sf_strlen(appex.iLinkText);
#else
	int text_len= 10 ;
#endif
        int refresh=0;
        gui_start_timer(SFVDOPLYAPP_TIMER_INTERVAL,mmi_vdoply_upd_callback_t);
        if(appex.iTime<text_len)
            refresh=1;
        if(appex.iTime>0xFFFFFFF)
        {
            appex.iTime=0x8000000;
        }
        else
        {
            ++appex.iTime;
        }
        //refresh the screen
        //if(refresh)
            //mmi_vdoply_upd_update_all();
    }
    else
    {
        gui_cancel_timer(mmi_vdoply_upd_callback_t);
    }
}

#endif //__SF_MP4_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_enter_general_state
 * DESCRIPTION
 *  state transition function
 * PARAMETERS
 *  state       [IN]        Video player's state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_enter_general_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U16 prev_state;
    vdoply_ui_type_neum prev_ui_type;
    mdi_video_info_struct video_info;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_state = g_vdoply_cntx.state;
    prev_ui_type = g_vdoply_cntx.ui_type;
    g_vdoply_cntx.state = state;
#ifdef __SF_MP4_SUPPORT__ 
    if(state!=VDOPLY_STATE_IDLE)
    {
        mmi_vdoply_upd_deactivate();
    }
#endif //__SF_MP4_SUPPORT__
    
    switch (state)
    {
        case VDOPLY_STATE_IDLE:
	#if defined(__LOW_POWER_MODE__)
            is_vdoply_on=1;
            TurnOnBacklight(1);
  	#endif
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;
          
            g_vdoply_cntx.cur_status.start_play_time = 0;
            g_vdoply_cntx.cur_status.play_time = 0;
            g_vdoply_cntx.cur_status.play_ratio = 0;

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();
                
                /* back from fulls screen, need draw full skin */
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
                mmi_vdoply_draw_play_region_bg();
            }
            else
            {
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
            }

            gui_cancel_timer(mmi_vdoply_player_timer_cyclic);

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle);

#ifndef WIN32
//Huyanwei Add Macro
#ifdef __SF_MP4_SUPPORT__ 
            if(appex.bPlayed)
            {
                mmi_vdoply_upd_activate();
                mmi_vdoply_upd_redraw();
            }
#endif //__SF_MP4_SUPPORT__
#endif
            mmi_vdoply_blt_screen();

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_PLAY:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;  
#ifdef __SF_MP4_SUPPORT__ 
            appex.bPlayed=1;
#endif //__SF_MP4_SUPPORT__

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();

                /* back from fulls screen, need draw full skin */
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
                mmi_vdoply_draw_play_region_bg();
                
                mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle);
            }
            else
            {
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
            }

            mmi_vdoply_blt_screen();

            g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;

            /* start play video */
            ret = mmi_vdoply_play_video();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
                return;
            }
            else if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_BT_CONNECTING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;  

            /* 
             * TRICKY!! This is used to keep screen display previous's key UI.
             * It avoid bt conecting state too short and some icon will flush.
             */                
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_PLAY);    

            /* clear process layer */
            gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();

                /* back from fulls screen, need draw full skin */
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
                mmi_vdoply_draw_play_region_bg();
                
                mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle);
            }
            else
            {
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
            }

            mmi_vdoply_blt_screen();  
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_BT_CONNECTING);   
              
            mmi_vdoply_connect_bt();
            break;


        case VDOPLY_STATE_PAUSE:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;                    

            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
            
            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();
                
                /* back from fulls screen, need draw full skin */
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
                mmi_vdoply_draw_play_region_bg();
                
                mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle);
            }
            else
            {
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
            }

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_INTERRUPTED_PAUSE:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;            
            
            mmi_vdoply_draw_softkey();
            mmi_vdoply_draw_panel();
            mmi_vdoply_blt_screen();
            break;

        case VDOPLY_STATE_OPENING:
        case VDOPLY_STATE_INTERRUPTED_OPENING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            mmi_vdoply_draw_opening_anim();
            mmi_vdoply_draw_softkey();
            mmi_vdoply_draw_panel();
            mmi_vdoply_blt_screen();

            /* open file */
            if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE)
            {
            #ifdef __DRM_SUPPORT__
                if (!g_vdoply_cntx.is_consume_drm_count)
                {
                    mdi_video_ply_drm_disable_consume_count();            
                }
            #endif /* __DRM_SUPPORT__ */
                
                ret = mdi_video_ply_open_file(g_vdoply_cntx.source_path, mmi_vdoply_player_open_done_hdlr);
            }
            else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_ID)
            {
                /* play from ID is a blocking function, we will call opened done hdlr by ourself */
                ret = mdi_video_ply_open_clip_id(g_vdoply_cntx.video_id, &video_info);

                if (ret == MDI_RES_VDOPLY_SUCCEED)
                {
                    /* open success, call open done hdlr */
                    mmi_vdoply_player_open_done_hdlr(MDI_RES_VDOPLY_SUCCEED, &video_info);
                }
            }
            else
            {
                ret = MDI_RES_VDOPLY_ERR_FAILED;
                ASSERT(0);
            }

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* true means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_INTERRUPTED_SEEKING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;            

            /* seek state dont refresh UI */
            ret = mdi_video_ply_non_block_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle,
                    mmi_vdoply_seek_result_hdlr);

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_SEEKING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            /* seek state dont refresh UI */
            ret = mdi_video_ply_non_block_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle,
                    mmi_vdoply_seek_result_hdlr);

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_BUFFERING);
                return;
            }

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_PLAY_SEEKING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            /* seek state dont refresh UI */
            ret = mdi_video_ply_non_block_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.play_wnd_layer_handle,
                    mmi_vdoply_seek_result_hdlr);

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
                return;                
            }

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_EXIT:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;
            
        #ifdef __MMI_VIDEO_PDL__
            if( g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
            {
                if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_DOWNLOADING)
                {
                    /* file still downloading */
                    mmi_vdoply_entry_pdl_teminate_confirm_scr();
                    return;
                }
                else
                {
                   /* file already downloaded */
                    GoBackHistory();
                    return;
                }
            }
        #endif /* __MMI_VIDEO_PDL__ */

            /* other case */
            GoBackHistory();            
#ifndef WIN32		
// Huyanwei Add Macro
#ifdef __SF_MP4_SUPPORT__ 
		{
		    extern void mmi_vdoply_on_leave_app(void);
		    mmi_vdoply_on_leave_app();
	        }
#endif //__SF_MP4_SUPPORT__    
#endif
            break;
        default:
            MMI_ASSERT(0);
            break;
        
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_enter_fullscr_state
 * DESCRIPTION
 *  state transition function
 * PARAMETERS
 *  state       [IN]        Video player's state
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_enter_fullscr_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U16 prev_state;
    vdoply_ui_type_neum prev_ui_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_state = g_vdoply_cntx.state;
    prev_ui_type = g_vdoply_cntx.ui_type;
    g_vdoply_cntx.state = state;
#if defined(NOKE_DEBUG)
   noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif
#ifdef __SF_MP4_SUPPORT__ 
    mmi_vdoply_upd_deactivate();
#endif //__SF_MP4_SUPPORT__
    switch (state)
    {
        case VDOPLY_STATE_FULLSCR_IDLE:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;
            
            g_vdoply_cntx.cur_status.start_play_time = 0;
            g_vdoply_cntx.cur_status.play_time = 0;
            g_vdoply_cntx.cur_status.play_ratio = 0;

        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
#if defined(NOKE_DEBUG)
        	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                
            }

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);
            
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

        #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
        
            gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);

            mmi_vdoply_blt_screen();

        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            /* error check */
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_FULLSCR_PLAY:
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);				
#endif
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;
#ifdef __SF_MP4_SUPPORT__ 
            appex.bPlayed=1;
#endif //__SF_MP4_SUPPORT__

        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL) 
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg(); 
            }

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);

            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif
            /* start play video */
            ret = mmi_vdoply_play_video();
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
                return;
            }
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }

            /* start draw timer */
            g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;
            
        #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

            gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);

            mmi_vdoply_blt_screen();
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif

            /* start play video */
            ret = mmi_vdoply_play_video();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
                return;
            }
            else if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }

            /* start draw timer */
            g_vdoply_cntx.cur_status.start_play_time = g_vdoply_cntx.cur_status.play_time;
           
        
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;


        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;

        #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);

            /* 
             * TRICKY!! This is used to keep screen display previous's key UI.
             * It avoid bt conecting state too short and some icon will flush.
             */                
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_FULLSCR_PLAY);    

            /* clear process layer */
            gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL) 
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg(); 
            }

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);

            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();            
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_FULLSCR_BT_CONNECTING);                    
            
            mmi_vdoply_connect_bt();
            
        #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

            gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);

            mmi_vdoply_connect_bt();
            mmi_vdoply_blt_screen();            
        #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
            break;

        case VDOPLY_STATE_FULLSCR_PAUSE:
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);				
#endif
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;
            
            /* reset osd's opacity */
            mmi_vdoply_fullscr_reset_osd_fade(TRUE);

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                 
            }

            ret = mdi_video_ply_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle);

            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }

            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;

            ret = mdi_video_ply_non_block_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle,
                    mmi_vdoply_seek_result_hdlr);

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING);
                return;
            }

            /* error check */
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;

        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;

            ret = mdi_video_ply_non_block_seek_and_get_frame(
                    g_vdoply_cntx.cur_status.play_time,
                    g_vdoply_cntx.fullscr_play_layer_handle,
                    mmi_vdoply_seek_result_hdlr);

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();

            if (ret == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
                return;
            }

            /* error check */
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }
            break;
            
        default:
            MMI_ASSERT(0);
            break;
        
    }


}
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_enter_stream_state
 * DESCRIPTION
 *  state transition function
 * PARAMETERS
 *  state       [IN]        Video player's state
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_STREAM__
static void mmi_vdoply_enter_stream_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_VDOPLY_SUCCEED;
    U16 prev_state;
    vdoply_ui_type_neum prev_ui_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_state = g_vdoply_cntx.state;
    prev_ui_type = g_vdoply_cntx.ui_type;
    g_vdoply_cntx.state = state;
    
    switch (state)
    {
        
        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();

                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();              
            }

            mmi_vdoply_draw_panel();
            mmi_vdoply_draw_softkey();                             
            mmi_vdoply_draw_connecting_anim();                
            mmi_vdoply_blt_screen();


            if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
            {
                ret = mdi_video_stream_connect(
                        g_vdoply_cntx.data_account_id, 
                        MDI_VIDEO_STREAM_RTSP_URL, 
                        g_vdoply_cntx.source_path, 
                        (MMI_BOOL)g_vdoply_cntx.proxy_on_off, 
                        g_vdoply_cntx.proxy_addr, 
                        g_vdoply_cntx.proxy_port,
                        (MMI_BOOL)g_vdoply_cntx.is_use_upd_port,
                        g_vdoply_cntx.highest_udp_port,
                        g_vdoply_cntx.lowest_udp_port,                          
                        mmi_vdoply_stream_connect_result_hdlr);
            }
            else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
            {
                ret = mdi_video_stream_connect(
                        g_vdoply_cntx.data_account_id, 
                        MDI_VIDEO_STREAM_SDP_FILE, 
                        g_vdoply_cntx.source_path, 
                        (MMI_BOOL)g_vdoply_cntx.proxy_on_off, 
                        g_vdoply_cntx.proxy_addr, 
                        g_vdoply_cntx.proxy_port,
                        (MMI_BOOL)g_vdoply_cntx.is_use_upd_port,
                        g_vdoply_cntx.highest_udp_port,
                        g_vdoply_cntx.lowest_udp_port,                          
                        mmi_vdoply_stream_connect_result_hdlr);
            }
            else
            {
                MMI_ASSERT(0);
            }

            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }                
            break;

        case VDOPLY_STATE_STREAM_BUFFERING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();

                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();                    
            }

            if(prev_state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING)
            {
                mmi_vdoply_draw_panel();            
                mmi_vdoply_draw_softkey();                    
                mmi_vdoply_stream_buffering_cyclic();                  
            }
            else
            {
                mmi_vdoply_draw_loading(0, MMI_TRUE);
                mmi_vdoply_draw_panel();            
                mmi_vdoply_draw_softkey();                    
                mmi_vdoply_blt_screen();
                
                mmi_vdoply_stream_start_buffering();                
            }
            break;

        case VDOPLY_STATE_STREAM_BT_CONNECTING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            /* 
             * TRICKY!! This is used to keep screen display previous's key UI.
             * It avoid bt conecting state too short and some icon will flush.
             */       
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_STREAM_BUFFERING);    

            /* clear process layer */
            gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();                    
            }

            mmi_vdoply_draw_panel();            
            mmi_vdoply_draw_softkey();    
            mmi_vdoply_blt_screen();
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_STREAM_BT_CONNECTING);     
            
            mmi_vdoply_connect_bt();
            break;

        case VDOPLY_STATE_STREAM_PLAY:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;
            gui_cancel_timer(mmi_vdoply_stream_buffering_cyclic);

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();

                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();  
            }
            
            mmi_vdoply_draw_panel();            
            mmi_vdoply_draw_softkey();                        
            mmi_vdoply_blt_screen();

            if(prev_state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
            {   
                /* toggle from fullscr */
                mmi_vdoply_resume_stream_video();
            }
            else
            {
                ret = mmi_vdoply_play_video();      
                
                if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
                {
                    return;
                }                        
            }
            break;

        case VDOPLY_STATE_STREAM_DISCONNECT:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();                 
            }
            
            mmi_vdoply_draw_panel();
            mmi_vdoply_draw_softkey(); 
            mmi_vdoply_blt_screen();

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();            
            break;

        case VDOPLY_STATE_STREAM_CONNECTED:
           g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;
           
           if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();

                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();                       
            }
            
            mmi_vdoply_draw_panel();
            mmi_vdoply_draw_softkey();  
    		mmi_vdoply_blt_screen();			
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                       
            }
            
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_connecting_anim();
            mmi_vdoply_draw_fullscr_osd();            
            mmi_vdoply_blt_screen();

            if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
            {
                ret = mdi_video_stream_connect(
                        g_vdoply_cntx.data_account_id, 
                        MDI_VIDEO_STREAM_RTSP_URL, 
                        g_vdoply_cntx.source_path, 
                        (MMI_BOOL)g_vdoply_cntx.proxy_on_off,  
                        g_vdoply_cntx.proxy_addr, 
                        g_vdoply_cntx.proxy_port,
                        (MMI_BOOL)g_vdoply_cntx.is_use_upd_port,
                        g_vdoply_cntx.highest_udp_port,
                        g_vdoply_cntx.lowest_udp_port,  
                        mmi_vdoply_stream_connect_result_hdlr);
            }
            else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
            {
                ret = mdi_video_stream_connect(
                        g_vdoply_cntx.data_account_id, 
                        MDI_VIDEO_STREAM_SDP_FILE, 
                        g_vdoply_cntx.source_path, 
                        (MMI_BOOL)g_vdoply_cntx.proxy_on_off, 
                        g_vdoply_cntx.proxy_addr, 
                        g_vdoply_cntx.proxy_port,
                        (MMI_BOOL)g_vdoply_cntx.is_use_upd_port,
                        g_vdoply_cntx.highest_udp_port,
                        g_vdoply_cntx.lowest_udp_port,                        
                        mmi_vdoply_stream_connect_result_hdlr);
            }
            else
            {
                MMI_ASSERT(0);
            }
            
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
            {
                return;
            }                
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                  
            }

            if(prev_state == VDOPLY_STATE_STREAM_BUFFERING)
            {
                mmi_vdoply_fullscr_reset_osd_fade(FALSE);

                mmi_vdoply_draw_fullscr_loading(0, MMI_TRUE);
                mmi_vdoply_draw_fullscr_osd();            
                mmi_vdoply_stream_fullscr_buffering_cyclic();            
            }
            else
            {
                mmi_vdoply_fullscr_reset_osd_fade(FALSE);

                mmi_vdoply_draw_fullscr_loading(0, MMI_TRUE);
                mmi_vdoply_draw_fullscr_osd();            
                mmi_vdoply_blt_screen();

                mmi_vdoply_stream_start_buffering();
                
                mmi_vdoply_stream_fullscr_buffering_cyclic();
            }
            
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;

            /* 
             * TRICKY!! This is used to keep screen display previous's key UI.
             * It avoid bt conecting state too short and some icon will flush.
             */       
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);    

            /* clear process layer */
            gdi_layer_push_and_set_active(g_vdoply_cntx.process_layer_handle);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                  
            }
            
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);
            mmi_vdoply_draw_fullscr_osd();            
            mmi_vdoply_blt_screen();     
            mmi_vdoply_set_state_key_event(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);                
            
            mmi_vdoply_connect_bt();            
            break;

 
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;            
            gui_cancel_timer(mmi_vdoply_stream_fullscr_buffering_cyclic);

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                    
            }

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);
            mmi_vdoply_draw_fullscr_osd();            
            mmi_vdoply_blt_screen();

            if(prev_state == VDOPLY_STATE_STREAM_PLAY)
            {   
                /* toggle from fullscr */
                mmi_vdoply_resume_stream_video();
            }
            else
            {
                ret = mmi_vdoply_play_video();      
                
                if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
                {
                    return;
                }                        
            }
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;    

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                    
            }

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);            
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();

            /* disconnect BT if needed */
            mmi_vdoply_disconnect_bt();            
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;  

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                   
            }

            mmi_vdoply_fullscr_reset_osd_fade(TRUE);            
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        default:
            MMI_ASSERT(0);
            break;
    
    }

}
#endif /* __MMI_VIDEO_STREAM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_enter_progressive_state
 * DESCRIPTION
 *  state transition function
 * PARAMETERS
 *  state       [IN]        Video player's state
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_PDL__
static void mmi_vdoply_enter_progressive_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U16 prev_state;
    vdoply_ui_type_neum prev_ui_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_state = g_vdoply_cntx.state;
    prev_ui_type = g_vdoply_cntx.ui_type;
    g_vdoply_cntx.state = state;
    
    switch (state)
    {
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;  
  
            mmi_vdoply_draw_opening_anim();
            mmi_vdoply_draw_panel();            
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();

            ret = mdi_video_progressive_open_file(
                    g_vdoply_cntx.source_path, 
                    mmi_vdoply_player_open_done_hdlr);

            /* error check */
            if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* true means has error popup */
            {
                /* TODO: Call DA Terminate connection */
                return;
            }
            break;

        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_NORMAL;   

            if (prev_ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_play_region_bg();                   
            }
            else
            {
                g_vdoply_cntx.pdl_buf_percent = 0;
            }

            mmi_vdoply_draw_loading(g_vdoply_cntx.pdl_buf_percent, MMI_TRUE);
            mmi_vdoply_draw_panel();            
            mmi_vdoply_draw_softkey();
            mmi_vdoply_blt_screen();
        
            gui_start_timer(100, mmi_vdoply_pdl_buffering_cyclic);
            break;
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
            g_vdoply_cntx.ui_type = VDOPLY_UI_TYPE_FULLSCR;            
                            
            mmi_vdoply_fullscr_reset_osd_fade(FALSE);

            if (prev_ui_type == VDOPLY_UI_TYPE_NORMAL)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_clear_fullscr_osd();
                mmi_vdoply_draw_fullscr_play_region_bg();                                    
            }
            else
            {
                g_vdoply_cntx.pdl_buf_percent = 0;
            }

            mmi_vdoply_draw_fullscr_loading(g_vdoply_cntx.pdl_buf_percent, MMI_TRUE);
            mmi_vdoply_draw_fullscr_osd();            
            mmi_vdoply_blt_screen();

            gui_start_timer(100, mmi_vdoply_pdl_fullscr_buffering_cyclic);
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
        default:
            MMI_ASSERT(0);
            break;
    }
}
#endif /* __MMI_VIDEO_PDL__ */





/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_enter_state
 * DESCRIPTION
 *  state transition function
 * PARAMETERS
 *  state       [IN]        Video player's state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_enter_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#define STATE_SWITCH_CASE(__STATE__)\
    case VDOPLY_STATE_##__STATE__:\
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_STATE_##__STATE__);\
        break;
    
    switch(state)
    {
        STATE_SWITCH_CASE(EXIT);
        STATE_SWITCH_CASE(OPENING);
        STATE_SWITCH_CASE(IDLE);
        STATE_SWITCH_CASE(PAUSE);
        STATE_SWITCH_CASE(PLAY);
        STATE_SWITCH_CASE(BT_CONNECTING);        
        STATE_SWITCH_CASE(SEEKING);
        STATE_SWITCH_CASE(PLAY_SEEKING);
        STATE_SWITCH_CASE(INTERRUPTED_OPENING);
        STATE_SWITCH_CASE(INTERRUPTED_PAUSE);
        STATE_SWITCH_CASE(INTERRUPTED_SEEKING);
        STATE_SWITCH_CASE(SNAPSHOT);
        STATE_SWITCH_CASE(FULLSCR_IDLE);
        STATE_SWITCH_CASE(FULLSCR_PAUSE);
        STATE_SWITCH_CASE(FULLSCR_PLAY);
        STATE_SWITCH_CASE(FULLSCR_BT_CONNECTING);        
        STATE_SWITCH_CASE(FULLSCR_SEEKING);
        STATE_SWITCH_CASE(FULLSCR_PLAY_SEEKING);        
        STATE_SWITCH_CASE(STREAM_DISCONNECT);        
        STATE_SWITCH_CASE(STREAM_CONNECTING);  
        STATE_SWITCH_CASE(STREAM_INTERRUPTED_CONNECTING);          
        STATE_SWITCH_CASE(STREAM_CONNECTED);  
        STATE_SWITCH_CASE(STREAM_BUFFERING);        
        STATE_SWITCH_CASE(STREAM_PLAY);  
        STATE_SWITCH_CASE(STREAM_BT_CONNECTING);          
        STATE_SWITCH_CASE(STREAM_FULLSCR_DISCONNECT);        
        STATE_SWITCH_CASE(STREAM_FULLSCR_CONNECTING);  
        STATE_SWITCH_CASE(STREAM_FULLSCR_INTERRUPTED_CONNECTING); 
        STATE_SWITCH_CASE(STREAM_FULLSCR_CONNECTED);  
        STATE_SWITCH_CASE(STREAM_FULLSCR_BUFFERING);        
        STATE_SWITCH_CASE(STREAM_FULLSCR_PLAY);
        STATE_SWITCH_CASE(STREAM_FULLSCR_BT_CONNECTING);        
        STATE_SWITCH_CASE(PROGRESSIVE_OPENING);        
        STATE_SWITCH_CASE(PROGRESSIVE_INTERRUPTED_OPENING);  
        STATE_SWITCH_CASE(PROGRESSIVE_BUFFERING);  
        STATE_SWITCH_CASE(PROGRESSIVE_PLAY_BUFFERING);          
        STATE_SWITCH_CASE(PROGRESSIVE_FULLSCR_BUFFERING); 
        STATE_SWITCH_CASE(PROGRESSIVE_FULLSCR_PLAY_BUFFERING);          
        default:
            MMI_ASSERT(0);
            break;
    }

    /* flush key event */
    ClearKeyEvents();

    /* reset key state */
    g_vdoply_cntx.touch_speed_inc.is_press = FALSE;
    g_vdoply_cntx.touch_speed_dec.is_press = FALSE;
    g_vdoply_cntx.touch_volume_inc.is_press = FALSE;
    g_vdoply_cntx.touch_volume_dec.is_press = FALSE;    
    g_vdoply_cntx.touch_progress_inc.is_press = FALSE;   
    g_vdoply_cntx.touch_progress_dec.is_press = FALSE;   
    g_vdoply_cntx.touch_progress_bar.is_press = FALSE;       
    g_vdoply_cntx.touch_snapshot.is_press = FALSE;      
    g_vdoply_cntx.touch_fullscreen.is_press = FALSE;         
    g_vdoply_cntx.touch_rsk.is_press = FALSE; 
    g_vdoply_cntx.touch_lsk.is_press = FALSE;
    g_vdoply_cntx.touch_ck.is_press = FALSE; 
    
    g_vdoply_cntx.full_touch_speed_inc.is_press = FALSE;
    g_vdoply_cntx.full_touch_speed_dec.is_press = FALSE;
    g_vdoply_cntx.full_touch_volume_inc.is_press = FALSE;
    g_vdoply_cntx.full_touch_volume_dec.is_press = FALSE;
    g_vdoply_cntx.full_touch_progress_inc.is_press = FALSE;
    g_vdoply_cntx.full_touch_progress_dec.is_press = FALSE;
    g_vdoply_cntx.full_touch_progress_bar.is_press = FALSE;
    g_vdoply_cntx.full_touch_rsk.is_press = FALSE;    
    g_vdoply_cntx.full_touch_lsk.is_press = FALSE;    
    g_vdoply_cntx.full_touch_ck.is_press = FALSE;

    mmi_vdoply_set_state_layer_config(state);
    mmi_vdoply_set_state_softkey(state);
    mmi_vdoply_set_state_key_event(state);

    /* enter next state */
    switch (state)
    {
        case VDOPLY_STATE_IDLE:
        case VDOPLY_STATE_PLAY:
        case VDOPLY_STATE_BT_CONNECTING:            
        case VDOPLY_STATE_PAUSE:
        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:            
        case VDOPLY_STATE_OPENING: 
        case VDOPLY_STATE_INTERRUPTED_OPENING:            
        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        case VDOPLY_STATE_INTERRUPTED_SEEKING:
        case VDOPLY_STATE_EXIT:
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\nHuyanwei Debug :state=%d, %s:%d",state,__FILE__,__LINE__);	
#endif
            mmi_vdoply_enter_general_state(state);
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        case VDOPLY_STATE_FULLSCR_IDLE:
        case VDOPLY_STATE_FULLSCR_PLAY:
        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:            
        case VDOPLY_STATE_FULLSCR_PAUSE:
        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);			
#endif
            mmi_vdoply_enter_fullscr_state(state);
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
        case VDOPLY_STATE_STREAM_BUFFERING:
        case VDOPLY_STATE_STREAM_PLAY:
        case VDOPLY_STATE_STREAM_BT_CONNECTING:
        case VDOPLY_STATE_STREAM_DISCONNECT:
        case VDOPLY_STATE_STREAM_CONNECTED:
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:
        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:            
        case VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT:
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:
#if defined(NOKE_DEBUG)
	    noke_dbg_printf("\r\nHuyanwei Debug : %s:%d",__FILE__,__LINE__);	
#endif
            mmi_vdoply_enter_stream_state(state);        
            break;   
    #endif /* __MMI_VIDEO_STREAM__ */

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
            mmi_vdoply_enter_progressive_state(state);        
            break;
    #endif /*   __MMI_VIDEO_PDL__ */
        default:
            MMI_ASSERT(0);
            break;
    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_clam_close_event_hdlr
 * DESCRIPTION
 *  handle clam close event
 * PARAMETERS
 *  ptr     [IN]        Message data ptr
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_vdoply_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (interrupt_event & MMI_FRM_INT_CLAM)
    {

        if (interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
        {
            GoBackHistory();
            return FALSE;
        }
    }

    /* return false means will pass this interrut to default handler */
    return FALSE;
}
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_play_finish_hdlr
 * DESCRIPTION
 *  function to be called when play finished.
 * PARAMETERS
 *  result      [IN]        >=0, means successfully finished, if result < 0 measn some error happened)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_player_play_finish_hdlr(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_back_from_fullscreen;
    S32 speed_factor;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if not in player screen */
    /* 
     * this may happend when video has error and driver send out this message, 
     * but before MMI receive this message, MMI stop and play the video again, 
     * that will cause driver to send another play finish message. When MMI 
     * receive first message, it will exit and display popup, when the second 
     * message comes, MMI already exit video play app. so we shall igore this 
     * message.
     */
#ifdef __SF_MP4_SUPPORT__
    if (mmi_vdoply_is_full_screen()) 
        SFApp_VdoFreeGDI();
#endif //__SF_MP4_SUPPORT__

    g_vdoply_cntx.touch_lsk.is_press = FALSE;
    g_vdoply_cntx.touch_rsk.is_press = FALSE;
    g_vdoply_cntx.touch_speed_inc.is_press = FALSE;
    g_vdoply_cntx.touch_speed_dec.is_press = FALSE;
    g_vdoply_cntx.touch_volume_inc.is_press = FALSE;
    g_vdoply_cntx.touch_volume_dec.is_press = FALSE;

    g_vdoply_cntx.touch_snapshot.is_press = FALSE;
    g_vdoply_cntx.touch_fullscreen.is_press = FALSE;

    is_back_from_fullscreen = FALSE;
    speed_factor = mmi_vdoply_get_speed_factor();

    if (GetExitScrnID() != SCR_ID_VDOPLY_PLAYER)
    {
        return;
    }

    /* stop UI seeking */
    gui_cancel_timer(mmi_vdoply_seek_foward_key_press_cyclic);
    gui_cancel_timer(mmi_vdoply_seek_backward_key_press_cyclic);
    g_vdoply_cntx.is_seeking = FALSE;

    /* stop timer */
    gui_cancel_timer(mmi_vdoply_player_timer_cyclic);

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        mmi_vdoply_clear_fullscr_aud_only_anim();  
    #endif
    }
    else
    {
        mmi_vdoply_clear_aud_only_anim();  
    }

    mmi_vdoply_bt_close_codec();

    /* check if has error or not */
    if (mmi_vdoply_check_and_display_error_popup(result) == TRUE)       /* true means have error */
    {
        return;
    }

#ifdef __MMI_VIDEO_PDL__
    /* check if it progressive dl buffer underflow */
    if (result == MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH)
    {
        if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
        {        
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING);
            return;
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY)
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING);
            return;
        }
    }
#endif /* __MMI_VIDEO_PDL__ */

#ifdef __MMI_VIDEO_STREAM__

    if (result == MDI_RES_VDOPLY_STREAM_BUFFER_OVERFLOW ||
        result == MDI_RES_VDOPLY_STREAM_BUFFER_UNDERFLOW)
    {

        if (g_vdoply_cntx.video_info.is_seekable)
        {
            if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
            {        
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
                }
                return;
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
            {
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
                }   
                return;
            }
        }
        else
        {
            if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
            {        
                mdi_video_stream_disconnect();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTING);
                return;
            }
            else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
            {
                mdi_video_stream_disconnect();                
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTING);
                return;
            }

        }
    }
    else if (result == MDI_RES_VDOPLY_ERR_STREAM_CONNECT_FAILED)
    {
        if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
        {
             mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
        {
             mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }

        /* if connect failed - popup and go to previous window */
        mmi_vdoply_disply_popup(
            (PU8) GetString(STR_ID_VDOPLY_NOTIFY_CONNECT_FAILED),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        DeleteNHistory(1);
        return;
    }   
#endif /* __MMI_VIDEO_STREAM__ */


    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY || 
        g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
    {
        /* draw timer bar to end */            
        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_FINISHED)
            {
                g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.video_info.total_time_duration;                                    
                g_vdoply_cntx.cur_status.play_ratio = g_vdoply_cntx.progress.fill_width;
            }
        }
        else
        {
            g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.video_info.total_time_duration;                
            g_vdoply_cntx.cur_status.play_ratio = g_vdoply_cntx.progress.fill_width;
        }

        mmi_vdoply_draw_panel_progress();
        mmi_vdoply_draw_panel_timer();
        mmi_vdoply_blt_screen();


        if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
        {
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
        {
        #ifdef __MMI_VIDEO_STREAM__
            mdi_video_stream_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);
        #endif
        }

        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_ID || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            if (g_vdoply_cntx.repeat == VDOPLY_REPEAT_ON)
            {
                /* start draw timer */
                g_vdoply_cntx.cur_status.start_play_time = 0;
                g_vdoply_cntx.cur_status.play_time = 0;

                mmi_vdoply_calc_progress_ratio();

            #ifdef __DRM_SUPPORT__
                g_vdoply_cntx.is_consume_drm_count = TRUE;
            #endif 

                ret = mdi_video_ply_seek_and_get_frame(
                        g_vdoply_cntx.cur_status.play_time,
                        g_vdoply_cntx.play_wnd_layer_handle);

                mmi_vdoply_draw_panel_progress();
                mmi_vdoply_draw_panel_timer();
                mmi_vdoply_blt_screen();

                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
                    return;
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
                    return;
                }

            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
                return;
            }
        }
        else if(g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
        {
            g_vdoply_cntx.cur_status.start_play_time = 0;
            g_vdoply_cntx.cur_status.play_time = 0;
            
            mmi_vdoply_calc_progress_ratio();

        #ifdef __MMI_VIDEO_STREAM__            
            if (g_vdoply_cntx.repeat == VDOPLY_REPEAT_ON &&
                g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_panel_progress();
                mmi_vdoply_draw_panel_timer();

                mmi_vdoply_blt_screen();

                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
                    return;
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
                    return;
                }
            }
            else
            {
                mmi_vdoply_calc_progress_ratio();

                if (g_vdoply_cntx.video_info.is_seekable)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);
                    return;
                }
                else
                {
                    mdi_video_stream_disconnect();
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
                    return;
                }
            }
        #endif /* __MMI_VIDEO_STREAM__ */
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }

    }
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    else if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY ||
             g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
    {
        /* draw timer bar to end */            
        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_FINISHED)
            {
                g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.video_info.total_time_duration;                                    
                g_vdoply_cntx.cur_status.play_ratio = g_vdoply_cntx.fullscr_progress.fill_width;
            }
        }
        else
        {
            g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.video_info.total_time_duration;                
            g_vdoply_cntx.cur_status.play_ratio = g_vdoply_cntx.fullscr_progress.fill_width;
        }
        
    #ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        /* have OSD */
        mmi_vdoply_draw_fullscr_osd();
        mmi_vdoply_blt_screen();

        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_ID || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            if (g_vdoply_cntx.repeat == VDOPLY_REPEAT_ON)
            {
                /* start draw timer */
                g_vdoply_cntx.cur_status.start_play_time = 0;
                g_vdoply_cntx.cur_status.play_time = 0;
                
                mmi_vdoply_calc_progress_ratio();

            #ifdef __DRM_SUPPORT__
                g_vdoply_cntx.is_consume_drm_count = TRUE;
            #endif 

                ret = mdi_video_ply_seek_and_get_frame(
                        g_vdoply_cntx.cur_status.play_time,
                        g_vdoply_cntx.fullscr_play_layer_handle);

                mmi_vdoply_draw_fullscr_osd();
                mmi_vdoply_blt_screen();

                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
                    return;
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
                    return;
                }

            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_IDLE);
                return;
            }
        }
        else if(g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
        {

            g_vdoply_cntx.cur_status.start_play_time = 0;
            g_vdoply_cntx.cur_status.play_time = 0;
            
            mmi_vdoply_calc_progress_ratio();

        #ifdef __MMI_VIDEO_STREAM__            
            if (g_vdoply_cntx.repeat == VDOPLY_REPEAT_ON &&
                g_vdoply_cntx.video_info.is_seekable)
            {
                mmi_vdoply_draw_fullscr_osd();
                mmi_vdoply_blt_screen();

                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
                    return;
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
                    return;
                }
            }
            else
            {

                if (g_vdoply_cntx.video_info.is_seekable)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTED);
                    return;
                }
                else
                {
                    mdi_video_stream_disconnect();
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
                    return;
                }
            }
        #endif /* __MMI_VIDEO_STREAM__ */
            return;
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }
    #else /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
    
        /* no OSD - repeat again or back to idle */    

        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_ID || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            if (g_vdoply_cntx.repeat == VDOPLY_REPEAT_ON)
            {
                /* start draw timer */
                g_vdoply_cntx.cur_status.start_play_time = 0;
                g_vdoply_cntx.cur_status.play_time = 0;

                mmi_vdoply_calc_progress_ratio();

                ret = mdi_video_ply_seek_and_get_frame(
                        g_vdoply_cntx.cur_status.play_time,
                        g_vdoply_cntx.fullscr_play_layer_handle);
  
                mmi_vdoply_blt_screen();

                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
                    return;
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
                    return;
                }

            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
                return;
            }
        }
        else if(g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
                g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
        {
            g_vdoply_cntx.cur_status.start_play_time = 0;
            g_vdoply_cntx.cur_status.play_time = 0;

            mmi_vdoply_calc_progress_ratio();            
            
       #ifdef __MMI_VIDEO_STREAM__            
            if (g_vdoply_cntx.repeat == VDOPLY_REPEAT_ON &&
                g_vdoply_cntx.video_info.is_seekable)
            {
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
                    return;
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
                    return;
                }
            }
            else
            {
                g_vdoply_cntx.cur_status.start_play_time = 0;
                g_vdoply_cntx.cur_status.play_time = 0;                
                if (g_vdoply_cntx.video_info.is_seekable)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);
                    return;
                }
                else
                {
                    mdi_video_stream_disconnect();
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
                    return;
                }
            }
        #endif /* __MMI_VIDEO_STREAM__ */
            return;        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }            
    #endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */
    }
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_open_done_hdlr
 * DESCRIPTION
 *  function to be called when file is opened.
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened)
 *  vdo_clip        [IN]        Video info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_player_open_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
#ifdef __MMI_VIDEO_PDL__    
    S32 buf_percent;
    S32 ret;
#endif /* __MMI_VIDEO_PDL__ */

    video_osd_play_wnd_struct *play_wnd_ptr = &g_vdoply_osd_cntx.play_wnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if already exit player screen */
    if (GetExitScrnID() != SCR_ID_VDOPLY_PLAYER)
    {
        return;
    }
    
#ifdef __SF_MP4_SUPPORT__ 
        //for player with vdoply UI
        mmi_vdoply_upd_enter();
#endif //__SF_MP4_SUPPORT__
    /* stop loading animation */
#ifdef __MMI_VIDEO_STREAM__
    mmi_vdoply_clear_connecting_anim();
#endif
    mmi_vdoply_clear_opening_anim();
    
    /* if open sucessfully */
    if (result >= 0)
    {
        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)  
        {
        #ifdef __MMI_VIDEO_STREAM__            
            g_vdoply_cntx.is_stream_opened = TRUE;
            
            /* set brightness/contrast for streaming */   
            mdi_video_stream_set_brightness(g_vdoply_cntx.brightness);
            mdi_video_stream_set_contrast(g_vdoply_cntx.contrast);
        #endif /* __MMI_VIDEO_STREAM__ */
        }
        else
        {
            /* set brightness/contrast */
            mdi_video_ply_set_brightness(g_vdoply_cntx.brightness);
            mdi_video_ply_set_contrast(g_vdoply_cntx.contrast);
        }

        /* fit it into player window */
        g_vdoply_cntx.video_info.width = vdo_clip->width;
        g_vdoply_cntx.video_info.height = vdo_clip->height;
        g_vdoply_cntx.video_info.total_time_duration = vdo_clip->total_time_duration;
        g_vdoply_cntx.video_info.is_seekable = vdo_clip->is_seekable;
        g_vdoply_cntx.video_info.track = vdo_clip->track;
        g_vdoply_cntx.video_info.aud_channel_no = vdo_clip->aud_channel_no;        
        g_vdoply_cntx.video_info.aud_sample_rate= vdo_clip->aud_sample_rate;


        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)  
        {
             g_vdoply_cntx.is_progress_seekable = (BOOL)g_vdoply_cntx.video_info.is_seekable;
        }
        
        /* this avoid driver return total time druation == 0, which will cause divid by zero */
        if (g_vdoply_cntx.video_info.total_time_duration == 0)
        {
            g_vdoply_cntx.video_info.total_time_duration = 1;
        }

        /* this is used solve when interrupt happened while video is finish,
           driver already send out finish idication but MMI didnt reveice this message
           and call get time. Will get play time which exceed total time */
        if (g_vdoply_cntx.cur_status.play_time >= g_vdoply_cntx.video_info.total_time_duration)
        {
            g_vdoply_cntx.cur_status.play_time = 0;
            mmi_vdoply_calc_progress_ratio();            
        }

        if (g_vdoply_cntx.video_info.track == MDI_VIDEO_TRACK_A_ONLY)
        {
            mmi_vdoply_draw_play_region_bg();
        }
        else
        {
            /* calc play layer size */
            gdi_image_util_fit_bbox(
                play_wnd_ptr->rect.width,
                play_wnd_ptr->rect.height,
                vdo_clip->width,
                vdo_clip->height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            /* resize play layer */
            gdi_layer_push_and_set_active(g_vdoply_cntx.play_wnd_layer_handle);
            gdi_layer_resize(resized_width, resized_height);
            
            gdi_layer_set_position(
                play_wnd_ptr->rect.offset_x + resized_offset_x,
                play_wnd_ptr->rect.offset_y + resized_offset_y);

            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        }
        


    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
    #if !defined(GDI_USING_LAYER_BACKGROUND)
        /* 
         *  older chip dont have layer background color, the full screen 
         *  video player will be the same size as LCD size 
         */
         
        /* resize and repostion full screen play window  */
        gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
        gdi_layer_resize(UI_device_height, UI_device_width);
        gdi_layer_set_position(0, 0);
        gdi_layer_pop_and_restore_active();

    #else /* !defined(GDI_USING_LAYER_BACKGROUND) */
        /* newer chip support lcd backgroud color */
        gdi_image_util_fit_bbox(
            UI_device_height,
            UI_device_width,
            vdo_clip->width,
            vdo_clip->height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);

        /* resize and repostion full screen play window  */
        gdi_layer_push_and_set_active(g_vdoply_cntx.fullscr_play_layer_handle);
#ifndef __SF_MP4_SUPPORT__
        //there is no need to do so if the flush screen method for the full screen mode is as fast as my START_LCD_TRANSFER
        gdi_layer_resize(UI_device_height, UI_device_width);
        gdi_layer_set_position(0, 0);
#else //__SF_MP4_SUPPORT__
        gdi_layer_resize(resized_width, resized_height);
        gdi_layer_set_position(resized_offset_x, resized_offset_y);
#endif //__SF_MP4_SUPPORT__
        
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    
    #endif /* !defined(GDI_USING_LAYER_BACKGROUND) */
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
        
        /* mute audio */
        if (g_vdoply_cntx.is_mute)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
        }

        switch (g_vdoply_cntx.state)
        {
            case VDOPLY_STATE_OPENING:
                         
                g_vdoply_cntx.cur_status.max_play_time = g_vdoply_cntx.video_info.total_time_duration; 
                mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);                                        
                break;
                
            case VDOPLY_STATE_PROGRESSIVE_OPENING:
            #ifdef __MMI_VIDEO_PDL__                            
                g_vdoply_cntx.cur_status.max_play_time = g_vdoply_cntx.video_info.total_time_duration;       

                ret = mdi_video_progressive_get_buf_percentage(&buf_percent);
                
                if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
                {
                    return;
                }     
                
                ret = mdi_video_progressive_get_max_play_time(&g_vdoply_cntx.cur_status.max_play_time);            

                if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
                {
                    return;
                }                         

                /* start timer to get playabel time */
                if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_DOWNLOADING)
                {
                	gui_start_timer(100, mmi_vdoply_pdl_draw_progressbar_cyclic);
                }

                if (buf_percent == 100)
                {
                    /* have enough buffe, can enter idle state */
                    mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);                                        
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_BUFFERING);                                        
                }
            #endif /* __MMI_VIDEO_PDL__ */
                break;

            case VDOPLY_STATE_INTERRUPTED_OPENING:
                g_vdoply_cntx.cur_status.max_play_time = g_vdoply_cntx.video_info.total_time_duration;            
                mmi_vdoply_enter_state(VDOPLY_STATE_INTERRUPTED_SEEKING);    
                break;

            case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:
            #ifdef __MMI_VIDEO_PDL__
                g_vdoply_cntx.cur_status.max_play_time = g_vdoply_cntx.video_info.total_time_duration;            
            
                ret = mdi_video_progressive_get_buf_percentage(&buf_percent);

                if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
                {
                    return;
                }     

                ret = mdi_video_progressive_get_max_play_time(&g_vdoply_cntx.cur_status.max_play_time);            

                if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
                {
                    return;
                }                

                /* start timer to get playabel time */
                if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_DOWNLOADING)
                {
                	gui_start_timer(100, mmi_vdoply_pdl_draw_progressbar_cyclic);
                }
                
                if (buf_percent == 100)
                {
                    /* have enough buffe, seek  */
                    mmi_vdoply_enter_state(VDOPLY_STATE_INTERRUPTED_SEEKING);                                        
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_PROGRESSIVE_BUFFERING);                                        
                }                    
            #endif /* __MMI_VIDEO_PDL__ */
                break;

            case VDOPLY_STATE_STREAM_BUFFERING:
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_PLAY);
                break;

            case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING:
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_PLAY);
                break;
               
                
        }

        /* set source is opened flag */
        g_vdoply_cntx.is_source_opened = TRUE;

    }
    else
    {
        PU8 err_str = NULL;

        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
        {
            err_str = (PU8)GetString(STR_ID_VDOPLY_NOTIFY_PLAY_FAILED);
        }
        else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE || 
                 g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_ID ||
                 g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
        {
            err_str = (PU8)GetString(STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE);
        }
        else 
        {
            MMI_ASSERT(0);
        }
        
        /* if open file error - popup and go to previous window */
        mmi_vdoply_disply_popup(
            err_str,
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        DeleteNHistory(1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_player_screen_internal
 * DESCRIPTION
 *  exit view detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_exit_player_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 aud_vol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit handler in different state */
    switch (g_vdoply_cntx.state)
    {
        case VDOPLY_STATE_EXIT:
            break;

        case VDOPLY_STATE_IDLE:
        case VDOPLY_STATE_PAUSE:
        case VDOPLY_STATE_OPENING:
        case VDOPLY_STATE_INTERRUPTED_OPENING:
        case VDOPLY_STATE_INTERRUPTED_PAUSE:
        case VDOPLY_STATE_BT_CONNECTING:
            mmi_vdoply_close_file();
            break;

        case VDOPLY_STATE_PLAY:
            /* interrupt while playing, store play time var */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);

            /* if is seeking, it is already stopped */

            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mmi_vdoply_close_file();
            gdi_layer_flatten_previous_to_base();
            break;

        case VDOPLY_STATE_SEEKING:
        case VDOPLY_STATE_PLAY_SEEKING:
        case VDOPLY_STATE_INTERRUPTED_SEEKING:
            /* stop non-blocking seeking */
            mdi_video_ply_stop_non_block_seek();
            mmi_vdoply_close_file();        
            break;

        case VDOPLY_STATE_FULLSCR_IDLE:
        case VDOPLY_STATE_FULLSCR_PAUSE:
        case VDOPLY_STATE_FULLSCR_BT_CONNECTING:
            mmi_vdoply_close_file();    
            break;

        case VDOPLY_STATE_FULLSCR_PLAY:
            /* interrupt while playing, store play time var */
            mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);

            /* if is seeking, it is already stopped */

            if (!g_vdoply_cntx.is_seeking)
            {
                mmi_vdoply_stop_video();
            }

            mmi_vdoply_close_file();    
            break;

        case VDOPLY_STATE_FULLSCR_SEEKING:
        case VDOPLY_STATE_FULLSCR_PLAY_SEEKING:
            /* stop non-blocking seeking */
            mdi_video_ply_stop_non_block_seek();
            mmi_vdoply_close_file();
            break;

    #ifdef __MMI_VIDEO_PDL__
        case VDOPLY_STATE_PROGRESSIVE_OPENING:
        case VDOPLY_STATE_PROGRESSIVE_INTERRUPTED_OPENING:    
            mmi_vdoply_clear_opening_anim();
            mmi_vdoply_close_file();    
            break;
    
        case VDOPLY_STATE_PROGRESSIVE_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING:
        case VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING:
            mmi_vdoply_close_file();    
            break;
    #endif /* __MMI_VIDEO_PDL__ */

    #ifdef __MMI_VIDEO_STREAM__
        case VDOPLY_STATE_STREAM_CONNECTED:  
        case VDOPLY_STATE_STREAM_BT_CONNECTING:            
            mdi_video_stream_disconnect();
            break;

        case VDOPLY_STATE_STREAM_CONNECTING:
        case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:            
            mmi_vdoply_clear_connecting_anim();
            mdi_video_stream_disconnect();            
            break;

        case VDOPLY_STATE_STREAM_BUFFERING:    
            if (!g_vdoply_cntx.is_seeking)
            {            
                mmi_vdoply_stream_stop_buffering();
            }
            mdi_video_stream_disconnect();
            break;

        case VDOPLY_STATE_STREAM_PLAY:
            mmi_vdoply_stop_video(); 
            mdi_video_stream_disconnect();
            break;

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__     
        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTED:  
        case VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING:
            mdi_video_stream_disconnect();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
        case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
            mmi_vdoply_clear_fullscr_connecting_anim();
            mdi_video_stream_disconnect();            
            break;
  
        case VDOPLY_STATE_STREAM_FULLSCR_BUFFERING: 
            if (!g_vdoply_cntx.is_seeking)
            {                     
                mmi_vdoply_stream_stop_buffering();
            }
            mdi_video_stream_disconnect();
            break;

        case VDOPLY_STATE_STREAM_FULLSCR_PLAY:            
            mmi_vdoply_stop_video();                                        
            mdi_video_stream_disconnect();
            break;
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    #endif /* __MMI_VIDEO_STREAM__ */
    }

    /* disconnect bluetooth */
    mmi_vdoply_disconnect_bt();
    
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
       /* clear base as black */
       /* we cant use flatten since layer size is different */
       gdi_layer_clear(GDI_COLOR_BLACK);
    }
    else
    {
       /* flatten to base before release layers */
       gdi_layer_flatten_previous_to_base();
    }

    /* retore default state */
    g_vdoply_cntx.state = VDOPLY_STATE_EXIT;

    /* when exit, set drm consume flag to false */
    g_vdoply_cntx.is_consume_drm_count = FALSE;

#if defined(__LOW_POWER_MODE__)
	is_vdoply_on=0;
	TurnOnBacklight(1);
#endif
#ifdef __MMI_VIDEO_STREAM__
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
    {
        if (g_vdoply_cntx.is_stream_init)
        {
            mdi_video_stream_deinit();
            g_vdoply_cntx.is_stream_init = FALSE;
        }

        if (!g_vdoply_cntx.video_info.is_seekable)
        {
            /* live, clear play time */
            g_vdoply_cntx.cur_status.play_time = 0;
            g_vdoply_cntx.cur_status.start_play_time = 0;
            g_vdoply_cntx.cur_status.play_ratio = 0;
        }
    }
#endif /* __MMI_VIDEO_STREAM__ */

    /* stop all timer */
    gui_cancel_timer(mmi_vdoply_seek_backward_key_press_cyclic);
    gui_cancel_timer(mmi_vdoply_seek_foward_key_press_cyclic);
    gui_cancel_timer(mmi_vdoply_player_timer_cyclic);
    gui_cancel_timer(mmi_vdoply_seek_key_release);

#ifdef __MMI_VIDEO_PDL__
    gui_cancel_timer(mmi_vdoply_pdl_draw_progressbar_cyclic);    
    gui_cancel_timer(mmi_vdoply_pdl_buffering_cyclic); 
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    gui_cancel_timer(mmi_vdoply_pdl_fullscr_buffering_cyclic);        
#endif 
#endif /* __MMI_VIDEO_PDL__ */

#ifdef __MMI_VIDEO_STREAM__
    gui_cancel_timer(mmi_vdoply_stream_buffering_cyclic);
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    gui_cancel_timer(mmi_vdoply_stream_fullscr_buffering_cyclic);
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);
#endif 

    /* restore rotate layer flag */
    gdi_lcd_set_rotate_by_layer(g_vdoply_cntx.prev_rotate_by_layer);

    /* stop all playing animation */
    gdi_image_stop_animation_all();

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LCD patten */
    StopLEDPatternPowerOn();

#ifdef __MMI_TVOUT__
    if (!mdi_tvout_is_enable())
    {
        TurnOffBacklight();
    }
    else
    {
        /* allows tv out to sleep in when lcd is sleep in */
        mmi_phnset_tvout_enable_tv_sleep_in();
        mmi_phnset_enable_partial_ss();
    }
#else /* __MMI_TVOUT__ */ 
    /* let MMI can sleep */
    TurnOffBacklight();
#endif /* __MMI_TVOUT__ */ 

    /* unmute */
    mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);

    /* resume background audio */
    mdi_audio_resume_background_play();

    if (g_vdoply_cntx.is_mute == TRUE)
    {
        aud_vol = VDOPLY_VOL_MUTE;
        WriteValue((U8) NVRAM_VDOPLY_VOLUMN, (void*)&aud_vol, DS_BYTE, &error);
    }
    else
    {
        WriteValue((U8) NVRAM_VDOPLY_VOLUMN, (void*)&g_vdoply_cntx.cur_status.volume, DS_BYTE, &error);
    }

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#ifdef __MMI_AVRCP_SUPPORT__
    PRINT_INFORMATION("video player clear avrcp cmd hdlr\n");
    mmi_bt_avrcp_clear_cmd_hdlr(mmi_vdoply_bt_avrcp_cmd_hdlr);
#endif 

    /* un-hook clam close msg */
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_CLAM_CLOSE);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */

#ifdef __VDOPLY_FEATURE_FULLSCREEN__

#ifndef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
    /* free fullscr osd layer */
    if (g_vdoply_cntx.osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdoply_cntx.osd_layer_handle);
        g_vdoply_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

        /* free buffer */
        mmi_frm_scrmem_free((void*)g_vdoply_cntx.osd_layer_buf_ptr);
        g_vdoply_cntx.osd_layer_buf_ptr = NULL;
    }
#endif /* __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__ */

    /* free fullscr video layer */
    if (g_vdoply_cntx.fullscr_play_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdoply_cntx.fullscr_play_layer_handle);
        g_vdoply_cntx.fullscr_play_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    /* free play wnd layer */
    if (g_vdoply_cntx.play_wnd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdoply_cntx.play_wnd_layer_handle);
        g_vdoply_cntx.play_wnd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /* free video layer buffer */
    #ifdef __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__
        if (g_vdoply_cntx.vdo_frame_buf_ptr != NULL)
        {
            media_free_int_buffer(MOD_MMI, (void**)&g_vdoply_cntx.vdo_frame_buf_ptr);
            g_vdoply_cntx.vdo_frame_buf_ptr = NULL;        
        }
    #endif /* __VDOPLY_FEATURE_INT_RAM_FRAME_BUF__ */

    /* free bg layer */
#ifdef __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__    
    /* bg - we use base layer's buffer, we dont need to free the buffer */
    gdi_layer_free(g_vdoply_cntx.bg_region_0_layer_handle);
    gdi_layer_free(g_vdoply_cntx.bg_region_1_layer_handle);    

    g_vdoply_cntx.bg_region_0_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdoply_cntx.bg_region_1_layer_handle = GDI_LAYER_EMPTY_HANDLE;    

    mmi_frm_scrmem_free(g_vdoply_cntx.bg_region_0_buf_ptr);
    mmi_frm_scrmem_free(g_vdoply_cntx.bg_region_1_buf_ptr);
    
    g_vdoply_cntx.bg_region_0_buf_ptr = NULL;
    g_vdoply_cntx.bg_region_1_buf_ptr = NULL;
    
#else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */
    g_vdoply_cntx.bg_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_BG__ */

    if (g_vdoply_cntx.process_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdoply_cntx.process_layer_handle);
        g_vdoply_cntx.process_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /* if lcd already sleep, clear the layer */
    if (mmi_gpio_is_lcd_sleep())
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }

#ifdef __MMI_TVOUT__
    if (g_vdoply_cntx.is_tvout_fullscreen)
    {
        /* change to normal screen */

        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to mode 1 */
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
        g_vdoply_cntx.is_tvout_fullscreen = FALSE;
    }
#endif /* __MMI_TVOUT__ */ 

    /* set lcm rotate to default */
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

    /* rotate base layer back to normal */
    gdi_layer_resize(UI_device_width, UI_device_height);

    /* restore to base layer only */
    gdi_layer_set_blt_layer(g_vdoply_cntx.bg_layer_handle, 0, 0, 0);

    /* reset flag */
    g_vdoply_cntx.is_from_history = FALSE;

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    if (g_vdoply_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_vdoply_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_close_file
 * DESCRIPTION
 *  close opened files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_close_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_FILE)
    {
        mdi_video_ply_close_file();
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_ID)
    {
        mdi_video_ply_close_clip_id();
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_PROGRESSIVE_DL)
    {
    #ifdef __MMI_VIDEO_PDL__        
        mdi_video_progressive_close_file();
    #endif
    }
    else
    {
        MMI_ASSERT(0);
    }     
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_speed_factor
 * DESCRIPTION
 *  get speed factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mmi_vdoply_get_speed_factor(void)
{
#ifdef __VDOPLY_FEATURE_SPEED__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_vdoply_cntx.cur_status.speed)
    {
        case 0:
            return VDOPLY_FEATURE_SPEED_0;
        case 1:
            return VDOPLY_FEATURE_SPEED_1;
        case 2:
            return VDOPLY_FEATURE_SPEED_2;
        case 3:
            return VDOPLY_FEATURE_SPEED_3;
        case 4:
            return VDOPLY_FEATURE_SPEED_4;
        case 5:
            return VDOPLY_FEATURE_SPEED_5;
        case 6:
            return VDOPLY_FEATURE_SPEED_6;
        case 7:
            return VDOPLY_FEATURE_SPEED_7;
        case 8:
            return VDOPLY_FEATURE_SPEED_8;

        default:
            ASSERT(0);
            return 0;
    }
#else /* __VDOPLY_FEATURE_SPEED__ */ 
    return 100; /* 1x play speed */
#endif /* __VDOPLY_FEATURE_SPEED__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_draw_sublcd_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdoply_draw_sublcd_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 lcd_width;
    S32 lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id((lcd_width - image_width) >> 1, (lcd_height - image_height) >> 1, IMG_ID_VDOPLY_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_vdoply_exit_sublcd_screen);

    /* draw a icon on sub */
    mmi_vdoply_draw_sublcd_icon();

    g_vdoply_cntx.is_sub_display = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    /* also stop preview here */

    if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY)
    {
        /* interrupt while playing, store play time var */
        mdi_video_ply_get_cur_play_time(&g_vdoply_cntx.cur_status.play_time);

        /* if is seeking, it is already stopped */
        if (!g_vdoply_cntx.is_seeking)
        {
            mmi_vdoply_stop_video();
        }

        g_vdoply_cntx.state = VDOPLY_STATE_IDLE;
    }

    /* stop seek skip frame timer */
    gui_cancel_timer(mmi_vdoply_seek_key_release);

    /* exit sub */
    g_vdoply_cntx.is_sub_display = FALSE;

    SubLCDHistory.entryFuncPtr = mmi_vdoply_entry_sublcd_screen;
    AddSubLCDHistory(&SubLCDHistory);
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
*
* Initialization and Entry of Video Player Application                                                                  
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_app
 * DESCRIPTION
 *  app hilight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_init_app
 * DESCRIPTION
 *  init video player applcation, register highlight handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(WAP_SUPPORT) && defined(__MMI_VIDEO_STREAM__)
    SetProtocolEventHandler(mmi_vdoply_rtsp_url_hdlr, MSG_ID_MMI_VDOPLY_RTSP_URL_REQ);
#endif
    
    /* init video player application highlight handler */
    SetHiliteHandler(MENU_ID_VDOPLY_APP, mmi_vdoply_highlight_app);
    SetHiliteHandler(MENU_ID_VDOPLY_PLAY, mmi_vdoply_highlight_play);
    SetHiliteHandler(MENU_ID_VDOPLY_STORAGE, mmi_vdoply_highlight_set_storage);
    SetHintHandler(MENU_ID_VDOPLY_STORAGE, mmi_vdoply_hint_set_storage);
    
#ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__
    SetHiliteHandler(MENU_ID_VDOPLY_OPTION_VIDEO_SETTING, mmi_vdoply_highlight_video_setting);  
#endif

#if defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__)		
    SetHiliteHandler(MENU_ID_VDOPLY_NETWORK, mmi_vdoply_highlight_network);  
    SetHiliteHandler(MENU_ID_VDOPLY_NETWORK_DATA_ACCOUNT, mmi_vdoply_highlight_data_account);     
    SetHiliteHandler(MENU_ID_VDOPLY_NETWORK_PROXY, mmi_vdoply_highlight_proxy);  
    SetHiliteHandler(MENU_ID_VDOPLY_NETWORK_UDP_PORT, mmi_vdoply_highlight_udp_port);   
    SetHiliteHandler(MENU_ID_VDOPLY_STREAMING_URL, mmi_vdoply_highlight_streaming_url);
    SetHiliteHandler(MENU_ID_VDOPLY_PREDEFINED_URL, mmi_vdoply_highlight_predefined_url);
    SetHiliteHandler(MENU_ID_VDOPLY_HISTORY_URL, mmi_vdoply_highlight_history_url);    
    SetHiliteHandler(MENU_ID_VDOPLY_HISTORY_PLAY, mmi_vdoply_highlight_history_play);
    SetHiliteHandler(MENU_ID_VDOPLY_HISTORY_REMOVE, mmi_vdoply_highlight_history_remove);    
    SetHiliteHandler(MENU_ID_VDOPLY_INPUT_URL, mmi_vdoply_highlight_input_url);  
    SetHiliteHandler(MENU_ID_VDOPLY_OPTION_SAVE_CONNECTION, mmi_vdoply_highlight_save_connection);  
    SetHiliteHandler(MENU_ID_VDOPLY_URL_EDITOR_OPTION_DONE, mmi_vdoply_highlight_url_editor_done);
    SetHiliteHandler(MENU_ID_VDOPLY_URL_EDITOR_OPTION_CANCEL, mmi_vdoply_highlight_url_editor_cancel);
    SetHiliteHandler(MENU_ID_VDOPLY_URL_EDITOR_OPTION_INPUT_METHOD, mmi_vdoply_highlight_url_input_method);   
    SetHiliteHandler(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION_DONE, mmi_vdoply_highlight_stream_editor_done);
    SetHiliteHandler(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION_CANCEL, mmi_vdoply_highlight_stream_editor_cancel);
    SetHiliteHandler(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION_INPUT_METHOD, mmi_vdoply_highlight_stream_input_method);
    SetHintHandler(MENU_ID_VDOPLY_NETWORK_DATA_ACCOUNT, mmi_vdoply_hint_data_account);
#endif /* defined(__MMI_VIDEO_STREAM__) || defined(__MMI_VIDEO_PDL__) */

#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)    
    SetHiliteHandler(MENU_ID_VDOPLY_BLUETOOTH_SETTING, mmi_vdoply_highlight_bluetooth_setting);    
#endif

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    SetHiliteHandler(MAIN_MENU_OPTION_VDOPLY_APP, mmi_vdoply_highlight_app);
#endif 
    /* init variable */
    g_vdoply_cntx.is_load_setting = FALSE;
    g_vdoply_cntx.is_sub_display = FALSE;
    g_vdoply_cntx.is_mute = FALSE;
    g_vdoply_cntx.video_id = 0;
    g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_EXIT;
    g_vdoply_cntx.pdl_dl_session_id = -1;
    g_vdoply_cntx.is_stream_opened = FALSE;
    g_vdoply_cntx.is_bt_opened = FALSE;

#ifdef __VDOPLY_FEATURE_UDP_PORT__
    g_vdoply_cntx.is_use_upd_port = TRUE;
#else
    g_vdoply_cntx.is_use_upd_port = FALSE;
#endif 

    g_vdoply_cntx.bg_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdoply_cntx.bg_region_0_layer_handle = GDI_LAYER_EMPTY_HANDLE;    
    g_vdoply_cntx.bg_region_1_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdoply_cntx.play_wnd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdoply_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdoply_cntx.fullscr_play_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdoply_cntx.process_layer_handle = GDI_LAYER_EMPTY_HANDLE; 
    g_vdoply_cntx.video_info.is_pausable = MMI_TRUE; /* currently not used */

    /* create video folder in system driver for streaming history */
#ifdef __MMI_VIDEO_STREAM__
    mmi_vdoply_create_file_dir((PS8)L"Z:\\@VideoStream\\");
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_from_fmgr
 * DESCRIPTION
 *  callback function when exit from fmgr's browser
 * PARAMETERS
 *  filename        [IN]        Not used
 *  is_short        [IN]        Is short name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_exit_from_fmgr(void *filename, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_VDOPLY_APP);
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_from_fmgr_emptry_folder
 * DESCRIPTION
 *  exit from fmgr when enter empty foloder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_exit_from_fmgr_emptry_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_VDOPLY_APP);
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_del_app_screen_hdlr
 * DESCRIPTION
 *  del app screen callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vdoply_del_app_screen_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.is_change_storage = FALSE;
    
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_app
 * DESCRIPTION
 *  video player entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    FMGR_FILTER filter;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load video's setting */
    mmi_vdoply_load_setting();
    mmi_vdoply_get_storage_file_path(buf_filepath);

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8)buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FTS_SUPPORT__) && defined(MT6225)
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
#if defined(__MMI_OPP_SUPPORT__) && defined(MT6225)
/* under construction !*/
/* under construction !*/
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
#endif /* 0 */

    if (g_vdoply_cntx.is_change_storage)
    {
        g_vdoply_cntx.is_change_storage = FALSE;
        mmi_vdoply_entry_set_app_storage_screen();
        return;
    }

    EntryNewScreen(SCR_ID_VDOPLY_APP, NULL, mmi_vdoply_entry_app, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_VDOPLY_APP, mmi_vdoply_del_app_screen_hdlr);

    /* try to create folder */
    create_result = mmi_vdoply_create_file_dir(buf_filepath);

    if (create_result != FS_NO_ERROR)
    {
        if (create_result == FS_WRITE_PROTECTION)
        {
            mmi_vdoply_disply_popup(
                (PU8) GetString(STR_ID_VDOPLY_NOTIFY_WRITE_PROTECTION),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_DISK_FULL)
        {
            mmi_vdoply_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mmi_vdoply_disply_popup(
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_FAT_ALLOC_ERROR)
        {

            mmi_vdoply_disply_popup(
                (PU8) GetString(FMGR_FS_FAT_ALLOC_ERROR_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);            
        }
        else
        {
            /* other error */            
            mmi_vdoply_disply_popup(
                (PU8)GetString(STR_ID_VDOPLY_NOTIFY_STORAGE_NOT_READY),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }

        /* 
         * Storage has error, set this flag and re-enter app screen, 
         * will launch storage selection screen 
         */
        g_vdoply_cntx.is_change_storage = TRUE;
        return;

    }

    /* check if it is valid path */
    file_handle = FS_Open((PU16)buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle >= 0)
    {
        FS_Close(file_handle);

        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_VIDEO(&filter);
        
    #ifdef __MMI_VIDEO_STREAM__
        FMGR_FILTER_SET(&filter, FMGR_TYPE_SDP);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_RAM);
    #endif /* __MMI_VIDEO_STREAM__ */

    #if defined(__DRM_V02__)
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
    #endif 

        mmi_fmgr_select_path_and_enter(
            APP_VDOPLY,
            FMGR_SELECT_BROWSE | FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
            filter,
            buf_filepath,
            (PsExtFuncPtr) mmi_vdoply_exit_from_fmgr);

        /* check if device is busy or not */
        if (FS_GetDevStatus(buf_filepath[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
        {
            /*  mmi_fmgr_select_path_and_enter will also add screen to histry */
            DeleteUptoScrID(SCR_ID_VDOPLY_APP);

            /* Delete up to previous screen */
            DeleteNHistory(1);
        }
    }
    else
    {
        /* shall never enter here */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
*
* Select Prefered Storage                                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_hint_set_storage
 * DESCRIPTION
 *  storage's hint
 * PARAMETERS
 *  index       [IN]        Selection index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_hint_set_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_fmgr_get_drive_name(
        (S8)g_vdoply_cntx.storage, 
        (S8*)&hintData[index], 
        (U8)((FMGR_MAX_DRIVE_NAME_LEN + 1 ) * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_set_storage
 * DESCRIPTION
 *  highlight set storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_set_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_set_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_set_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_bluetooth_setting
 * DESCRIPTION
 *  highlight set storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)    
static void mmi_vdoply_highlight_bluetooth_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_entry_bluetooth_settings, KEY_EVENT_UP);
    SetKeyHandler(mmi_audply_entry_bluetooth_settings, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif /* defined(__MMI_AUDIO_PLAYER__) && defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)  */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_get_drive_callback
 * DESCRIPTION
 *  get drive callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_get_drive_callback(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    U16 prev_storage;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drv_letter != 0)
    {
        prev_storage = g_vdoply_cntx.storage;
        g_vdoply_cntx.storage = (U16)drv_letter;
            
        mmi_vdoply_get_storage_file_path(buf_filepath);
        create_result = mmi_vdoply_create_file_dir(buf_filepath);
        
        if (create_result != FS_NO_ERROR)
        {
            if (create_result == FS_WRITE_PROTECTION)
            {
                mmi_vdoply_disply_popup(
                    (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

                g_vdoply_cntx.storage = prev_storage;         
                /* after popup, will re-enter storage screen */                
                return;
            }
            else if (create_result == FS_DISK_FULL)
            {
                mmi_vdoply_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);        

                g_vdoply_cntx.storage = prev_storage;            
                /* after popup, will re-enter storage screen */
                return;
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                mmi_vdoply_disply_popup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);    

                g_vdoply_cntx.storage = prev_storage;        
                /* after popup, will re-enter storage screen */
                return;
            }
            else if (create_result == FS_FAT_ALLOC_ERROR)
            {
                mmi_vdoply_disply_popup(
                    (PU8) GetString(FMGR_FS_FAT_ALLOC_ERROR_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);            

                g_vdoply_cntx.storage = prev_storage;                     
                /* after popup, will re-enter storage screen */                
                return;
            }        
            else
            {
                /* other error */            
                mmi_vdoply_disply_popup(
                    (PU8)GetString(STR_ID_VDOPLY_NOTIFY_STORAGE_NOT_READY),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

                g_vdoply_cntx.storage = prev_storage;    
                /* after popup, will re-enter storage screen */                
                return;
            }
        }
        else
        {
            /* create folder successful */
            mmi_vdoply_disply_popup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                0,
                ST_NOTIFYDURATION,
                SUCCESS_TONE);    

            mmi_vdoply_store_setting();            
            
            /* after popup, will enter video player file list screen */
            if(g_vdoply_cntx.is_option_storage)
            {        
                /* delete 
                 * (1) FMGR DRV screen 
                 * (2) STORAGE screen
                 * (3) Option screen
                 * (4) FMGR FILE screen 
                 */                
                DeleteNHistory(4);
            }
            else
            {
                /* back to app */
                
                /* delete 
                 * (1) FMGR DRV screen 
                 * (2) STORAGE screen
                 */
                DeleteNHistory(2);
            }
            return;
        }

    }
    else
    {
        /* user press RSK back */
        if(g_vdoply_cntx.is_option_storage)
        {
            /* option -> storage */
            /* back to option */
            
            /* delete 
             * (1) STORAGE screen
             */
            DeleteNHistory(1);
        }
        else
        {
            /* app -> storage */
            /* exit ap */
            
            /* delete 
             * (1) STORAGE screen
             * (2) VDOPLY APP screen
             */
            DeleteNHistory(2);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_set_app_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_set_app_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storage screen for app -> storage */
    g_vdoply_cntx.is_option_storage = FALSE;
    mmi_vdoply_entry_set_storage_screen_internal();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_set_storage_screen
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_set_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* storage screen for option -> storage */
    g_vdoply_cntx.is_option_storage = TRUE;
    mmi_vdoply_entry_set_storage_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_set_storage_screen_internal
 * DESCRIPTION
 *  enter set storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_set_storage_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOPLY_STORAGE, NULL, mmi_vdoply_entry_set_storage_screen_internal, NULL);
    mmi_fmgr_sel_drv_and_enter(APP_VDOPLY, mmi_vdoply_get_drive_callback, g_vdoply_cntx.storage);
}



/*****************************************************************************
 *
 *  Touch Screen Support
 *
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOPLY_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdoply_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 shift;
    S32 ratio;

#if defined(__VDOPLY_FEATURE_FULLSCREEN__) || defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOPLY_FEATURE_FULLSCREEN__) || defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        /* do nothing when pen down */
        return;
    #endif 
    
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__

        /* cord tranfrom, since already rotate */
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;

        if (g_vdoply_cntx.fullscr_osd_opacity != 255)
        {
            /* wake up osd */
            mmi_vdoply_fullscr_osd_show_up();
            return;
        }

        /* show full screen osd, do not allow it sleep */
        mmi_vdoply_fullscr_reset_osd_fade(FALSE);
        gui_cancel_timer(mmi_vdoply_fullscr_osd_fade_cyclic);

        /* volume inc */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_volume_inc))
        {
            mmi_vdoply_vol_up_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_VOLUME_INC;
            return;
        }

        /* volume dec */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_volume_dec))
        {
            mmi_vdoply_vol_down_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_VOLUME_DEC;
            return;
        }


    #ifdef __VDOPLY_FEATURE_SPEED__            
        /* speed inc */        
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_speed_inc))
        {
            mmi_vdoply_speed_inc_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_SPEED_INC;
            return;
        }
    #endif /* __VDOPLY_FEATURE_SPEED__ */
    
    #ifdef __VDOPLY_FEATURE_SPEED__            
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_speed_dec))
        {
            mmi_vdoply_speed_dec_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_SPEED_DEC;
            return;
        }
    #endif /* __VDOPLY_FEATURE_SPEED__ */            
        
        /* progress inc */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_progress_inc))
        {
            mmi_vdoply_seek_foward_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_PROGRESS_INC;
  
            return;
        }

        /* progress dec */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_progress_dec))
        {
            mmi_vdoply_seek_backward_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_PROGRESS_DEC;
            return;
        }

        /* progress bar */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_progress_bar))
        {
            if (!g_vdoply_cntx.is_seeking)
            {
                g_vdoply_cntx.full_touch_progress_bar.is_press = TRUE;

                g_vdoply_cntx.is_seeking = TRUE;

                if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY)
                {
                    mmi_vdoply_stop_video();
                }
                else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING)
                {
                #ifdef __MMI_VIDEO_STREAM__

                    mmi_vdoply_stream_stop_buffering();

                    if (g_vdoply_cntx.video_info.is_seekable)
                    {
                        mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTED);
                    }
                    else
                    {
                        mdi_video_stream_disconnect();
                        mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);                
                    }
                
                #endif /* __MMI_VIDEO_STREAM__ */
                }

                shift = pos.x - g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x;
                ratio = (shift << 10) / g_vdoply_cntx.fullscr_progress.fill_width;

                g_vdoply_cntx.cur_status.play_time = (g_vdoply_cntx.video_info.total_time_duration * ratio) >> 10;

                if (g_vdoply_cntx.cur_status.play_time > g_vdoply_cntx.cur_status.max_play_time)
                {
                    g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.cur_status.max_play_time;
                }

                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_fullscr_osd();
                mmi_vdoply_blt_screen();
                g_vdoply_cntx.touch_object = VDOPLY_TOUCH_PROGRESS_BAR;
            }
            return;
        }

        /* rsk */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_rsk))
        {
            mmi_vdoply_rsk_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_RSK;
            return;
        }

        /* lsk */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_lsk))
        {
            mmi_vdoply_lsk_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_LSK;
            return;
        }

        /* lsk */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_ck))
        {
            mmi_vdoply_ck_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_CK;
            return;
        }

    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 
    }
    else
    {
    #ifdef __SF_MP4_SUPPORT__ 
        if(mmi_vdoply_upd_on_pen_down(pos.x, pos.y))
            return;
    #endif
    #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)

        /* cord tranfrom, since already rotate */
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;

    #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 
    
        /* rsk */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_rsk))
        {
            mmi_vdoply_rsk_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_RSK;
            return;
        }
    
        /* lsk */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_lsk))
        {
            mmi_vdoply_lsk_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_LSK;
            return;
        }

        /* ck */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_ck))
        {
            mmi_vdoply_ck_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_CK;
            return;
        }

        /* volume inc */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_volume_inc))
        {
            mmi_vdoply_vol_up_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_VOLUME_INC;
            return;
        }

        /* volume dec */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_volume_dec))
        {
            mmi_vdoply_vol_down_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_VOLUME_DEC;
            return;
        }

    #ifdef __VDOPLY_FEATURE_SPEED__  
        /* speed inc */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_speed_inc))
        {
            mmi_vdoply_speed_inc_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_SPEED_INC;
            return;
        }
    #endif /* __VDOPLY_FEATURE_SPEED__ */
    
    #ifdef __VDOPLY_FEATURE_SPEED__  
        /* speed dec */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_speed_dec))
        {
            mmi_vdoply_speed_dec_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_SPEED_DEC;
            return;
        }
    #endif /* __VDOPLY_FEATURE_SPEED__ */
    
        /* progress inc */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_progress_inc))
        {
            mmi_vdoply_seek_foward_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_PROGRESS_INC;
            return;
        }

        /* progress dec */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_progress_dec))
        {
            mmi_vdoply_seek_backward_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_PROGRESS_DEC;
            return;
        }

        /* progress bar */
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_progress_bar))
        {
            if (!g_vdoply_cntx.is_seeking)
            {
                g_vdoply_cntx.touch_progress_bar.is_press = TRUE;

                g_vdoply_cntx.is_seeking = TRUE;

                if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY || 
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY)
                {
                    mmi_vdoply_stop_video();
                }
                else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING)
                {
                #ifdef __MMI_VIDEO_STREAM__
                    mmi_vdoply_stream_stop_buffering();

                    if (g_vdoply_cntx.video_info.is_seekable)
                    {
                        mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_CONNECTED);
                    }
                    else
                    {
                        mdi_video_stream_disconnect();
                        mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);                
                    }
                
                #endif /* __MMI_VIDEO_STREAM__ */
                }

                shift = pos.x - g_vdoply_osd_cntx.panel.progress_empty.offset_x;
                ratio = (shift << 10) / g_vdoply_cntx.progress.fill_width;

                g_vdoply_cntx.cur_status.play_time = (g_vdoply_cntx.video_info.total_time_duration * ratio) >> 10;

                if (g_vdoply_cntx.cur_status.play_time > g_vdoply_cntx.cur_status.max_play_time)
                {
                    g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.cur_status.max_play_time;
                }

                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_panel_progress();
                mmi_vdoply_draw_panel_timer();
                mmi_vdoply_blt_screen();
                g_vdoply_cntx.touch_object = VDOPLY_TOUCH_PROGRESS_BAR;
            }
            return;
        }

    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /* toggle fullscreen or tv-out */    
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_fullscreen))
        {
        #ifdef __MMI_TVOUT__
            if (mdi_tvout_is_enable())
            {
                mmi_vdoply_toggle_tvout_key_press();
            }
            else
            {
                mmi_vdoply_toggle_fullscreen_key_press();
            }
        #else /* __MMI_TVOUT__ */ 
            mmi_vdoply_toggle_fullscreen_key_press();
        #endif /* __MMI_TVOUT__ */ 

            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_FULLSCREEN;
            return;
        }
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    #ifdef __VDOPLY_FEATURE_SNAPSHOT__
        /* snapshot */    
        if (mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_snapshot))
        {
            mmi_vdoply_player_snapshot_key_press();
            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_SNAPSHOT;
            return;
        }
    #endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
    S32 tmp_x;
    S32 tmp_y;
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        mmi_vdoply_toggle_fullscreen_display();
        return;
    #endif 
    
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /* cord tranfrom, since already rotate */
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;

        /*  let osd can sleep */
        mmi_vdoply_fullscr_reset_osd_fade(TRUE);

        switch (g_vdoply_cntx.touch_object)
        {
            case VDOPLY_TOUCH_VOLUME_INC:
                mmi_vdoply_vol_up_key_release();
                break;

            case VDOPLY_TOUCH_VOLUME_DEC:
                mmi_vdoply_vol_down_key_release();
                break;

        #ifdef __VDOPLY_FEATURE_SPEED__   
            case VDOPLY_TOUCH_SPEED_INC:
                mmi_vdoply_speed_inc_key_release();
                break;
        #endif /* __VDOPLY_FEATURE_SPEED__ */

        #ifdef __VDOPLY_FEATURE_SPEED__   
            case VDOPLY_TOUCH_SPEED_DEC:
                mmi_vdoply_speed_dec_key_release();
                 break;
        #endif /* __VDOPLY_FEATURE_SPEED__ */
        
            case VDOPLY_TOUCH_PROGRESS_INC:
                mmi_vdoply_seek_foward_key_release();
                break;

            case VDOPLY_TOUCH_PROGRESS_DEC:
                mmi_vdoply_seek_backward_key_release();
                break;

            case VDOPLY_TOUCH_PROGRESS_BAR:
                g_vdoply_cntx.full_touch_progress_bar.is_press = FALSE;
                mmi_vdoply_seek_key_release();
                break;

            case VDOPLY_TOUCH_RSK:
                mmi_vdoply_rsk_release();
                break;

            case VDOPLY_TOUCH_LSK:
                mmi_vdoply_lsk_release();
                break;

            case VDOPLY_TOUCH_CK:
                mmi_vdoply_ck_release();
                break;
        }

    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    }
    else
    {
    #ifdef __SF_MP4_SUPPORT__
        if(mmi_vdoply_upd_on_pen_up(pos.x, pos.y))
            return;
    #endif
        /* not fullscreen */
        switch (g_vdoply_cntx.touch_object)
        {
            case VDOPLY_TOUCH_VOLUME_INC:
                mmi_vdoply_vol_up_key_release();
                break;

            case VDOPLY_TOUCH_VOLUME_DEC:
                mmi_vdoply_vol_down_key_release();
                break;

        #ifdef __VDOPLY_FEATURE_SPEED__   
            case VDOPLY_TOUCH_SPEED_INC:
                mmi_vdoply_speed_inc_key_release();
                break;
        #endif /* __VDOPLY_FEATURE_SPEED__ */
        
        #ifdef __VDOPLY_FEATURE_SPEED__   
            case VDOPLY_TOUCH_SPEED_DEC:
                mmi_vdoply_speed_dec_key_release();
                break;
        #endif /* __VDOPLY_FEATURE_SPEED__ */
            
            case VDOPLY_TOUCH_PROGRESS_INC:
                mmi_vdoply_seek_foward_key_release();
                break;

            case VDOPLY_TOUCH_PROGRESS_DEC:
                mmi_vdoply_seek_backward_key_release();
                break;

            case VDOPLY_TOUCH_PROGRESS_BAR:
                g_vdoply_cntx.touch_progress_bar.is_press = FALSE;
                mmi_vdoply_seek_key_release();
                break;

                /* snapshot */
        #ifdef __VDOPLY_FEATURE_SNAPSHOT__
            case VDOPLY_TOUCH_SNAPSHOT:
                mmi_vdoply_player_snapshot_key_release();
                break;
        #endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 

                /* fullscreen */
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__

            case VDOPLY_TOUCH_FULLSCREEN:
            #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    mmi_vdoply_toggle_tvout_key_release();
                }
                else
                {
                    mmi_vdoply_toggle_fullscreen_key_release();
                }
            #else /* __MMI_TVOUT__ */ 
                mmi_vdoply_toggle_fullscreen_key_release();
            #endif /* __MMI_TVOUT__ */ 
                break;

        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

            case VDOPLY_TOUCH_RSK:
                mmi_vdoply_rsk_release();

                g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                break;

            case VDOPLY_TOUCH_LSK:
                mmi_vdoply_lsk_release();

                g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                break;

            case VDOPLY_TOUCH_CK:
                mmi_vdoply_ck_release();

                g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                break;
        }

    }
    
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 shift;
    S32 ratio;

#if defined(__VDOPLY_FEATURE_FULLSCREEN__) || defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOPLY_FEATURE_FULLSCREEN__) || defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.touch_object == VDOPLY_TOUCH_NONE)
    {
        return;
    }

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {

    #ifdef __VDOPLY_FEATURE_HIDE_FULLSCR_OSD__
        /* do nothing when pen down */
        return;
    #endif 
    
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__

        /* cord tranfrom, since already rotate */
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;

        switch (g_vdoply_cntx.touch_object)
        {
            case VDOPLY_TOUCH_VOLUME_INC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_volume_inc))
                {
                    g_vdoply_cntx.full_touch_volume_inc.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_VOLUME_DEC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_volume_dec))
                {
                    g_vdoply_cntx.full_touch_volume_dec.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_SPEED_INC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_speed_inc))
                {
                    g_vdoply_cntx.full_touch_speed_inc.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_SPEED_DEC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_speed_dec))
                {
                    g_vdoply_cntx.full_touch_speed_dec.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_PROGRESS_INC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_progress_inc))
                {
                    mmi_vdoply_seek_foward_key_release();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_PROGRESS_DEC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_progress_dec))
                {
                    mmi_vdoply_seek_backward_key_release();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_PROGRESS_BAR:

                if (pos.x >
                    (g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x +
                     g_vdoply_cntx.fullscr_progress.fill_width - 1))
                {
                    g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.video_info.total_time_duration;
                }
                else if (pos.x < g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x)
                {
                    g_vdoply_cntx.cur_status.play_time = 0;
                }
                else
                {
                    shift = pos.x - g_vdoply_fullscr_osd_cntx.panel.progress_empty.offset_x + 1;
                    ratio = (shift << 10) / g_vdoply_cntx.fullscr_progress.fill_width;

                    g_vdoply_cntx.cur_status.play_time = (g_vdoply_cntx.video_info.total_time_duration * ratio) >> 10;
                }

                if (g_vdoply_cntx.cur_status.play_time > g_vdoply_cntx.cur_status.max_play_time)
                {
                    g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.cur_status.max_play_time;
                }

                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_fullscr_osd();
                mmi_vdoply_blt_screen();
                break;

            case VDOPLY_TOUCH_RSK:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_rsk))
                {
                    g_vdoply_cntx.touch_rsk.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_LSK:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_lsk))
                {
                    g_vdoply_cntx.touch_lsk.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_CK:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_ck))
                {
                    g_vdoply_cntx.touch_ck.is_press = FALSE;

                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

        }

    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

    }
    else
    {
    #ifdef __SF_MP4_SUPPORT__
        if(mmi_vdoply_upd_on_pen_move(pos.x, pos.y))
            return;
    #endif

    #if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__)

        /* cord tranfrom, since already rotate */
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;

    #endif /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) */ 

        /* not fullscreen */
        switch (g_vdoply_cntx.touch_object)
        {
            case VDOPLY_TOUCH_VOLUME_INC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_volume_inc))
                {
                    g_vdoply_cntx.touch_volume_inc.is_press = FALSE;
 
                    mmi_vdoply_draw_panel_volume();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_VOLUME_DEC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_volume_dec))
                {
                    g_vdoply_cntx.touch_volume_dec.is_press = FALSE;

                    mmi_vdoply_draw_panel_volume();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_SPEED_INC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_speed_inc))
                {
                    g_vdoply_cntx.touch_speed_inc.is_press = FALSE;

                    mmi_vdoply_draw_panel_speed();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_SPEED_DEC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_speed_dec))
                {
                    g_vdoply_cntx.touch_speed_dec.is_press = FALSE;

                    mmi_vdoply_draw_panel_speed();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_PROGRESS_INC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_progress_inc))
                {
                    mmi_vdoply_seek_foward_key_release();

                    mmi_vdoply_draw_panel_progress();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_PROGRESS_DEC:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_progress_dec))
                {
                    mmi_vdoply_seek_backward_key_release();

                    mmi_vdoply_draw_panel_progress();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_PROGRESS_BAR:

                if (pos.x > (g_vdoply_osd_cntx.panel.progress_empty.offset_x + g_vdoply_cntx.progress.fill_width - 1))
                {
                    g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.video_info.total_time_duration;
                }
                else if (pos.x < g_vdoply_osd_cntx.panel.progress_empty.offset_x)
                {
                    g_vdoply_cntx.cur_status.play_time = 0;
                }
                else
                {
                    shift = pos.x - g_vdoply_osd_cntx.panel.progress_empty.offset_x;
                    ratio = (shift << 10) / g_vdoply_cntx.progress.fill_width;

                    g_vdoply_cntx.cur_status.play_time = (g_vdoply_cntx.video_info.total_time_duration * ratio) >> 10;
                }

                if (g_vdoply_cntx.cur_status.play_time > g_vdoply_cntx.cur_status.max_play_time)
                {
                    g_vdoply_cntx.cur_status.play_time = g_vdoply_cntx.cur_status.max_play_time;
                }

                mmi_vdoply_calc_progress_ratio();
                mmi_vdoply_draw_panel_progress();
                mmi_vdoply_draw_panel_timer();
                mmi_vdoply_blt_screen();
                break;

            #ifdef __VDOPLY_FEATURE_SNAPSHOT__
                /* snapshot */            
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_snapshot))
                {
                    /* if move out */
                    g_vdoply_cntx.touch_snapshot.is_press = FALSE;

                    mmi_vdoply_draw_panel_state();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;
            #endif /* __VDOPLY_FEATURE_SNAPSHOT__ */ 


            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                /* fullscreen */            
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_fullscreen))
                {
                    g_vdoply_cntx.touch_fullscreen.is_press = FALSE;

                    mmi_vdoply_draw_panel_state();
                    mmi_vdoply_blt_screen();
                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */ 

            case VDOPLY_TOUCH_RSK:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_rsk))
                {
                    g_vdoply_cntx.touch_rsk.is_press = FALSE;

                    mmi_vdoply_draw_softkey();
                    mmi_vdoply_blt_screen();

                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_LSK:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_lsk))
                {
                     g_vdoply_cntx.touch_lsk.is_press = FALSE;

                    mmi_vdoply_draw_softkey();
                    mmi_vdoply_blt_screen();

                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;

            case VDOPLY_TOUCH_CK:
                if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.touch_ck))
                {
                    g_vdoply_cntx.touch_ck.is_press = FALSE;

                    mmi_vdoply_draw_softkey();
                    mmi_vdoply_blt_screen();

                    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
                }
                break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_touch_scr_hit_test
 * DESCRIPTION
 *  test if is within touch region
 * PARAMETERS
 *  pos_x           [IN]        Position x
 *  pos_y           [IN]        Position y
 *  touch_obj       [?]         
 *  touch(?)        [IN]        Touch object structure
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_vdoply_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdoply_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!touch_obj->is_usable)
    {
        return FALSE;
    }
    
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* defined(__VDOPLY_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOPLY_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_adjust_option_scr
 * DESCRIPTION
 *  entry video player adjustment option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOPLY_FEATURE_LSK_OPTION__)
static void mmi_vdoply_entry_adjust_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 input_buffer_size;
    S32 item_offset = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE item_icons[VDOPLY_ADJ_TOTAL * 2] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
    };

    EntryNewScreen(SCR_ID_VDOPLY_ADJUST_OPTION, mmi_vdoply_exit_adjust_option_scr, NULL, NULL);

    InitializeCategory57Screen();

    g_vdoply_cntx.adjust_data.brightness = g_vdoply_cntx.brightness;
    g_vdoply_cntx.adjust_data.contrast = g_vdoply_cntx.contrast;
    g_vdoply_cntx.adjust_data.repeat = g_vdoply_cntx.repeat;

    /* brightness */
    for (i = 0; i < VDOPLY_BRIGHTNESS_ADJ_LEVEL_COUNT; i++)
    {
        g_vdoply_cntx.adjust_data.brightness_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_VDOPLY_ADJUST_START + i + 1));
    }

    /* contrast */
    for (i = 0; i < VDOPLY_CONTRAST_ADJ_LEVEL_COUNT; i++)
    {
        g_vdoply_cntx.adjust_data.contrast_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_VDOPLY_ADJUST_START + i + 1));
    }

    /* repeat */
    g_vdoply_cntx.adjust_data.repeat_str[0] = (UI_string_type) GetString(STR_GLOBAL_OFF);
    g_vdoply_cntx.adjust_data.repeat_str[1] = (UI_string_type) GetString(STR_GLOBAL_ON);

    /* brightness */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_VDOPLY_BRIGHTNESS)));

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        VDOPLY_BRIGHTNESS_ADJ_LEVEL_COUNT,
        (U8 **) g_vdoply_cntx.adjust_data.brightness_str,
        &g_vdoply_cntx.adjust_data.brightness);

    /* contrast */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_VDOPLY_CONTRAST)));

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        VDOPLY_CONTRAST_ADJ_LEVEL_COUNT,
        (U8 **) g_vdoply_cntx.adjust_data.contrast_str,
        &g_vdoply_cntx.adjust_data.contrast);

    /* repeat */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_VDOPLY_AUTO_REPEAT)));

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        VDOPLY_REPEAT_ADJ_COUNT,
        (U8 **) g_vdoply_cntx.adjust_data.repeat_str,
        &g_vdoply_cntx.adjust_data.repeat);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_ADJUST_OPTION);
    input_buffer = GetCurrNInputBuffer(SCR_ID_VDOPLY_ADJUST_OPTION, &input_buffer_size);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, VDOPLY_ADJ_TOTAL * 2, input_buffer);
    }

    RegisterHighlightHandler(mmi_vdoply_adjust_option_highlight_hdlr);

#if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_ID_VDOPLY_OPTION_VIDEO_SETTING,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdoply_adjust_option_lsk_hdlr);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_adjust_option_scr
 * DESCRIPTION
 *  exit video player adjustment option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_exit_adjust_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 num_of_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    h.scrnID = SCR_ID_VDOPLY_ADJUST_OPTION;
    h.entryFuncPtr = mmi_vdoply_entry_adjust_option_scr;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & num_of_history);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_adjust_option_lsk_hdlr
 * DESCRIPTION
 *  adjust option screen lsk handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_adjust_option_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.brightness = g_vdoply_cntx.adjust_data.brightness;
    g_vdoply_cntx.contrast = g_vdoply_cntx.adjust_data.contrast;
    g_vdoply_cntx.repeat = g_vdoply_cntx.adjust_data.repeat;

    mmi_vdoply_store_setting();

    mmi_vdoply_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);

    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_adjust_option_highlight_hdlr
 * DESCRIPTION
 *  adjust screen highlight handler
 * PARAMETERS
 *  index       [IN]        Selected item's index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_adjust_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdoply_adjust_option_lsk_hdlr);
}
#endif /* defined(__VDOPLY_FEATURE_LSK_OPTION__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_is_in_play_and_tvout_enable
 * DESCRIPTION
 *  check if is in video player and tv out is enable
 *  in this case, we do not sleep ui timer.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifdef __MMI_TVOUT__
MMI_BOOL mmi_vdoply_is_in_play_and_tvout_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetExitScrnID() == SCR_ID_VDOPLY_PLAYER) && mdi_tvout_is_enable())
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;

}
#endif /* __MMI_TVOUT__ */ 


/**********************************
 * Option Screen
 **********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_option_scr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_ENHNACE_OPTION__
static void mmi_vdoply_entry_option_scr(void)
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
    S32 menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set this flag before enter screen */
    EntryNewScreen(SCR_ID_VDOPLY_OPTION, NULL, mmi_vdoply_entry_option_scr, NULL);

    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP)
    {
        menu_id = MENU_ID_VDOPLY_OPTION_STREAMING;
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
    {
        /* ram is from local file, do not let it save */
        menu_id = MENU_ID_VDOPLY_OPTION;
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
    {
        if (g_vdoply_cntx.is_da_spd_file)
        {
            menu_id = MENU_ID_VDOPLY_OPTION_STREAMING;
        }
        else
        {
            /* sdp from local file, do not let it save */
            menu_id = MENU_ID_VDOPLY_OPTION;
        }
    }
    else
    {
        menu_id = MENU_ID_VDOPLY_OPTION;
    }

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_OPTION);
    num_item = GetNumOfChild(menu_id);

    GetSequenceStringIds(menu_id, item_list);
    GetSequenceImageIds(menu_id, item_icons);
    SetParentHandler(menu_id);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(menu_id, popup_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
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
 *  mmi_vdoply_highlight_video_setting
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_video_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_adjust_option_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_adjust_option_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);        
}

#endif /* __VDOPLY_FEATURE_ENHNACE_OPTION__ */


#if defined(__MMI_VIDEO_STREAM__)			
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_network
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_network_setting_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_network_setting_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_data_account
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_network_data_account_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_network_data_account_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);        
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_hint_data_account
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_hint_data_account(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_get_account_name(
        g_vdoply_cntx.data_account_id,
        (S8*)g_vdoply_cntx.data_account_name,
        MAX_DATA_ACCOUNT_NAME_LEN);
    
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*)hintData[index],
        (S8*)g_vdoply_cntx.data_account_name);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_proxy
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_proxy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_network_proxy_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_network_proxy_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);       
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_udp_port
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_udp_port(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_network_udp_port_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_network_udp_port_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);       
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_streaming_url
 * DESCRIPTION
 *  highlight stream url menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_streaming_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_vdoply_entry_streaming_url_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_streaming_url_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_predefined_url
 * DESCRIPTION
 *  highlight stream url menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_predefined_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_vdoply_entry_predefined_url_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_predefined_url_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_history_url
 * DESCRIPTION
 *  highlight stream url menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_history_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_vdoply_entry_history_url_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_history_url_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_history_play
 * DESCRIPTION
 *  highlight history option play menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_history_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SetLeftSoftkeyFunction(mmi_vdoply_history_play_url, KEY_EVENT_UP);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_history_remove
 * DESCRIPTION
 *  highlight history option remove menu item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_history_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SetLeftSoftkeyFunction(mmi_vdoply_entry_history_remove_confirm_scr, KEY_EVENT_UP);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_input_url
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_input_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_url_editor_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_url_editor_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);          
}


/**********************************
 * Save Connection Screen
 **********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_save_connection
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_save_connection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_stream_editor_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_entry_stream_editor_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);            
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_stream_editor_done
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_stream_editor_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_check_filename_and_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_check_filename_and_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_stream_editor_cancel
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_stream_editor_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_cancel_stream_editor_and_exit, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_cancel_stream_editor_and_exit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_stream_input_method
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_stream_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);    
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_save_stream_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_save_stream_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE dest_handle;
    FS_HANDLE src_handle;    
    S8 filename_buf[FMGR_PATH_BUFFER_SIZE];
    S8 url_buf[FMGR_PATH_CHAR_COUNT+1];    
    U8 tmp_buf[100];
    U32 str_len;
    U32 written;
    U32 readed;
    U32 file_size;
    S32 fs_ret;
    U16 stream_seq_no;
    S16 error = 0 ;
    MMI_ID_TYPE error_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoply_get_storage_file_path(filename_buf);

    /* create dir if needed, maybe user already delete the video folder */
    /* but we do not do error check here */
    mmi_vdoply_create_file_dir(filename_buf);
        
    /* file not exist -save SDP or RAM */
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
    {
        mmi_ucs2cat((PS8)filename_buf, (PS8)g_vdoply_cntx.edit_buf);
        mmi_ucs2cat((PS8)filename_buf, (PS8)(L".ram"));
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
    {
        mmi_ucs2cat((PS8)filename_buf, (PS8)g_vdoply_cntx.edit_buf);
        mmi_ucs2cat((PS8)filename_buf, (PS8)(L".sdp"));
    }

    /* delete if already exist */
    FS_Delete((U16*)filename_buf);
    
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
    {
        /* save link to file */          
        dest_handle = FS_Open((U16*)filename_buf, FS_CREATE_ALWAYS);

        if (dest_handle >= 0)
        {
            mmi_ucs2_to_asc((PS8)url_buf, (PS8)g_vdoply_cntx.source_path);
            str_len = strlen(url_buf) + 1; /* +1 for null terminate */
            
            fs_ret = FS_Write(dest_handle, url_buf, str_len, &written);

            if (fs_ret < 0)
            {
                /* error */
                error_str_id = GetFileSystemErrorString(fs_ret);

                mmi_vdoply_disply_popup(
                    (PU8) GetString(error_str_id),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
               
                FS_Close(dest_handle);
                DeleteUptoScrID(SCR_ID_VDOPLY_STREAM_EDITOR);  
                return;
            }
            else
            {
                /* url saved */
                FS_Close(dest_handle);

                mmi_vdoply_disply_popup(
                    (PU8) GetString(STR_GLOBAL_SAVED),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);

                DeleteUptoScrID(SCR_ID_VDOPLY_OPTION);

                /* get/store sequentail number */
                ReadValue(NVRAM_VDOPLY_STREAM_SEQ_NO, &stream_seq_no, DS_SHORT, &error);
                stream_seq_no++;
                if (stream_seq_no > 9999) /* more than 4 digits */
                {
                    stream_seq_no = 1;
                }
                WriteValue(NVRAM_VDOPLY_STREAM_SEQ_NO, &stream_seq_no, DS_SHORT, &error);
                return;

            }
        }
        else
        {
            /* open file error handling */
            error_str_id = GetFileSystemErrorString(dest_handle);

            mmi_vdoply_disply_popup(
                (PU8) GetString(error_str_id),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
               
            return;
        }
       
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
    {
        /* save link to file */          
        dest_handle = FS_Open((U16*)filename_buf, FS_CREATE_ALWAYS);

        if (dest_handle >= 0)
        {
            src_handle = FS_Open((U16*)g_vdoply_cntx.source_path, FS_READ_ONLY);
            
            if (src_handle >= 0)
            {
                /* copy from src to dest */
                FS_GetFileSize(src_handle, &file_size);
                fs_ret = FS_NO_ERROR;
                    
                do {
                    fs_ret = FS_Read(src_handle, tmp_buf, 100, &readed);
                    
                    if(fs_ret < 0)
                    {
                        break;
                    }
                    
                    fs_ret = FS_Write(dest_handle, tmp_buf, readed, &written);

                    if(fs_ret < 0)
                    {
                        break;
                    }

                    file_size -= written;
                } while(file_size);

                FS_Close(src_handle);
                FS_Close(dest_handle);
                
                mmi_vdoply_disply_popup(
                    (PU8) GetString(STR_GLOBAL_SAVED),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);

                DeleteUptoScrID(SCR_ID_VDOPLY_OPTION);

                /* get/store sequentail number */
                ReadValue(NVRAM_VDOPLY_STREAM_SEQ_NO, &stream_seq_no, DS_SHORT, &error);
                stream_seq_no++;
                if (stream_seq_no > 9999) /* more than 4 digits */
                {
                    stream_seq_no = 1;
                }
                WriteValue(NVRAM_VDOPLY_STREAM_SEQ_NO, &stream_seq_no, DS_SHORT, &error);                
                return;                    

            }
            else
            {
                /* src opened error */
                FS_Close(dest_handle);

                error_str_id = GetFileSystemErrorString(src_handle);

                mmi_vdoply_disply_popup(
                    (PU8) GetString(error_str_id),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                return;
            }
        }
        else
        {
            /* dest opened error */
            error_str_id = GetFileSystemErrorString(dest_handle);

            mmi_vdoply_disply_popup(
                (PU8) GetString(error_str_id),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;           
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_check_filename_and_save
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_check_filename_and_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE dest_handle;
    S8 filename_buf[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* file not exist -save SDP or RAM */
    if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
        g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
    {
        mmi_vdoply_get_storage_file_path(filename_buf);
        mmi_ucs2cat((PS8)filename_buf, (PS8)g_vdoply_cntx.edit_buf);
        mmi_ucs2cat((PS8)filename_buf, (PS8)(L".ram"));
    }
    else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
    {
        mmi_vdoply_get_storage_file_path(filename_buf);
        mmi_ucs2cat((PS8)filename_buf, (PS8)g_vdoply_cntx.edit_buf);
        mmi_ucs2cat((PS8)filename_buf, (PS8)(L".sdp"));
    }

    /* check if file already exist or not */
    dest_handle = FS_Open((U16*)filename_buf, FS_READ_ONLY);

    if (dest_handle >= 0)
    {
        /* file exist - popup confirm overwrite */
#if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    DisplayConfirmRotated(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOPLY_NOTIFY_OVERWRITE_FILE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE,
        MMI_FRM_SCREEN_ROTATE_270);
#else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOPLY_NOTIFY_OVERWRITE_FILE),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

        FS_Close(dest_handle);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_vdoply_save_stream_file, KEY_EVENT_UP);
        return;
    }
    else
    {
        /* save file */
        mmi_vdoply_save_stream_file();
        return;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_cancel_stream_editor_and_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_cancel_stream_editor_and_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete: editor */
    DeleteNHistory(1);
    GoBackHistory();   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_stream_editor_scr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_stream_editor_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S16 error = 0;
    U16 stream_seq_no;
    S8 buffer[50];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoply_get_storage_file_path(buf_filepath);
    
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */

        if (mmi_usb_check_path_exported((PS8)buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    
    EntryNewScreen(SCR_ID_VDOPLY_STREAM_EDITOR, NULL, mmi_vdoply_entry_stream_editor_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_STREAM_EDITOR);

    if (gui_buffer == NULL)
    {
        /* get/store sequentail number */
        ReadValue(NVRAM_VDOPLY_STREAM_SEQ_NO, &stream_seq_no, DS_SHORT, &error);
        if (stream_seq_no == 0xffff)
        {
            stream_seq_no = 0;    /* init value */
            WriteValue(NVRAM_VDOPLY_STREAM_SEQ_NO, &stream_seq_no, DS_SHORT, &error);            
            stream_seq_no = 1;
        }
        else
        {
            /* TODO: if seq no turn around, add some protection */
            stream_seq_no++;
            if (stream_seq_no > 9999) /* more than 4 digits */
            {
                stream_seq_no = 1;
            }
        }

        sprintf((PS8)buffer, "STREAM%04d", stream_seq_no);
        mmi_asc_to_ucs2((PS8)g_vdoply_cntx.edit_buf, (PS8)buffer);
     
    }

    ShowCategory5Screen(
        STR_ID_VDOPLY_EDIT_FILENAME,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*)g_vdoply_cntx.edit_buf,
        VDOPLY_MAX_STREAM_LINK_CHAR_COUNT,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdoply_entry_stream_editor_option_scr, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_vdoply_return_to_editor_screen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_stream_editor_option_scr
 * DESCRIPTION
 *  entry edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_stream_editor_option_scr(void)
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
    EntryNewScreen(SCR_ID_VDOPLY_STREAM_EDITOR_OPTION, NULL, mmi_vdoply_entry_stream_editor_option_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_STREAM_EDITOR_OPTION);
    num_item = GetNumOfChild(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION);

    GetSequenceStringIds(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION, item_list);
    GetSequenceImageIds(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION, item_icons);
    SetParentHandler(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_VDOPLY_STREAM_EDITOR_OPTION, popup_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
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
#endif /* defined(__MMI_VIDEO_STREAM__) */




/**********************************
 * URL Editor Screen 
 **********************************/
#if defined(__MMI_VIDEO_STREAM__) 			 
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_url_editor_done
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_url_editor_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_check_url_and_enter, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_check_url_and_enter, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_url_editor_cancel
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_url_editor_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_cancel_url_and_exit, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoply_cancel_url_and_exit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_highlight_url_input_method
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_highlight_url_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_check_url_and_enter
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_check_url_and_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[FMGR_PATH_CHAR_COUNT+1];
    PS8 str_ptr;
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_util_store_filepath(g_vdoply_cntx.edit_buf, FMGR_PATH_ID_VIDEO_STREAM);    
    
    mmi_ucs2_to_asc(buffer, g_vdoply_cntx.edit_buf);

    str_ptr = buffer;
    /* make lower */
    while(*str_ptr != 0)
    {
        if (*str_ptr >= 'A' && *str_ptr <= 'Z')
        {
            *str_ptr = (*str_ptr)+0x20;
        }
        str_ptr++;
    }

    /* RTSP link*/
    /* rtsp:\\...... */
    if (strncmp(buffer, (PS8)"rtsp", 4) == 0)
    {
        mmi_vdoply_entry_player_screen_from_rtsp_link(g_vdoply_cntx.edit_buf);  
        
        /* delete: editor option, editor */
        DeleteNHistory(2);              
        return;        
    }
    else if (strncmp(buffer, (PS8)"http", 4) == 0)
    {
        str_len = strlen(buffer);
        str_ptr = buffer + (str_len - 3);
        
        if (strncmp(str_ptr, (PS8)"sdp", 3) == 0)
        {
            mmi_vdoply_entry_player_screen_from_sdp_file(g_vdoply_cntx.edit_buf, MMI_FALSE);       
            
            /* delete: editor option, editor */
            DeleteNHistory(2);                 
            return;
        }
    }

    DisplayPopup(
        (PU8)GetString(STR_ID_VDOPLY_NOTIFY_INVALID_URL),
        IMG_GLOBAL_WARNING,
        1,
        ST_NOTIFYDURATION,
        WARNING_TONE);
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_cancel_url_and_exit
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_cancel_url_and_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete: editor */
    DeleteNHistory(1);
    GoBackHistory();   
}




/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_return_to_editor_screen
 * DESCRIPTION
 *  return to editor from input selection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_return_to_editor_screen(void)
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
 *  mmi_vdoply_entry_url_editor_scr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_url_editor_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOPLY_URL_EDITOR, NULL, mmi_vdoply_entry_url_editor_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_URL_EDITOR);

    if (gui_buffer == NULL)
    {
        /* load path from NVRAM */
        mmi_fmgr_util_load_filepath(g_vdoply_cntx.edit_buf, FMGR_PATH_ID_VIDEO_STREAM);        
    }

    if (mmi_ucs2strlen(g_vdoply_cntx.edit_buf) == 0)
    {
        /* empty string, add rtsp:// */
        mmi_ucs2cpy(g_vdoply_cntx.edit_buf, (PS8)(L"rtsp://"));
    }

    ShowCategory5Screen(
        STR_ID_VDOPLY_INPUT_URL,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_OVERRIDE_DEFAULT,
        (U8*)g_vdoply_cntx.edit_buf,
        VDOPLY_MAX_URL_CHAR_COUNT,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdoply_entry_url_editor_option_scr, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_vdoply_return_to_editor_screen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_url_editor_option_scr
 * DESCRIPTION
 *  entry edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_url_editor_option_scr(void)
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
    EntryNewScreen(SCR_ID_VDOPLY_URL_EDITOR_OPTION, NULL, mmi_vdoply_entry_url_editor_option_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_URL_EDITOR_OPTION);
    num_item = GetNumOfChild(MENU_ID_VDOPLY_URL_EDITOR_OPTION);

    GetSequenceStringIds(MENU_ID_VDOPLY_URL_EDITOR_OPTION, item_list);
    GetSequenceImageIds(MENU_ID_VDOPLY_URL_EDITOR_OPTION, item_icons);
    SetParentHandler(MENU_ID_VDOPLY_URL_EDITOR_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_VDOPLY_URL_EDITOR_OPTION, popup_list);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
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



/**********************************
 * Network Setting
 **********************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_network_setting_scr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_network_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    DataAccountReadyCheck(mmi_vdoply_entry_network_setting_scr_internal);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_network_setting_scr_internal
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_network_setting_scr_internal(void)
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
    /* set this flag before enter screen */
    EntryNewScreen(SCR_ID_VDOPLY_NETWORK, NULL, mmi_vdoply_entry_network_setting_scr_internal, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_NETWORK);
    num_item = GetNumOfChild(MENU_ID_VDOPLY_NETWORK);

    GetSequenceStringIds(MENU_ID_VDOPLY_NETWORK, item_list);
    GetSequenceImageIds(MENU_ID_VDOPLY_NETWORK, item_icons);
    SetParentHandler(MENU_ID_VDOPLY_NETWORK);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_VDOPLY_NETWORK, popup_list);

    ShowCategory52Screen(
        STR_ID_VDOPLY_NETWORK,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
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
 *  mmi_vdoply_entry_network_data_account_scr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_network_data_account_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dtcnt_select_account(
        mmi_vdoply_data_account_callback,
        MENU_ID_VDOPLY_APP,
        DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI);
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_data_account_callback
 * DESCRIPTION
 *  Callback function for GPRS Data Account
 * PARAMETERS
 *  index       [IN]        Highlight index of selected account
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_data_account_callback(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.data_account_id = (U8) index;
    mmi_dtcnt_get_account_name(
        g_vdoply_cntx.data_account_id,
        (S8*)g_vdoply_cntx.data_account_name,
        MAX_DATA_ACCOUNT_NAME_LEN);

    mmi_vdoply_store_setting();

    mmi_vdoply_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_VDOPLY_NETWORK);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_three_digit_ip_str
 * DESCRIPTION
 *  This Fun Convert the integer value to String with prefix zero.
 *  Works only for three digit integer.(0-256)
 * PARAMETERS
 *  str_ptr         [IN]        string pointer    
 *  digit           [IN]        digit
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_three_digit_ip_str(PS8 str_ptr, U8 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 local_buf[8];
    S8 str_val[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (digit == 0)
    {
        mmi_asc_to_ucs2((PS8)str_val, (PS8)"000");
    }
    else if (digit < 10)
    {
        sprintf(local_buf, "00%d", digit);
        mmi_asc_to_ucs2((PS8)str_val, (PS8)local_buf);
    }
    else if (digit < 100)
    {
        sprintf(local_buf, "0%d", digit);
        mmi_asc_to_ucs2((PS8)str_val, (PS8)local_buf);
    }
    else
    {
        sprintf(local_buf, "%d", digit);
        mmi_asc_to_ucs2((PS8)str_val, (PS8)local_buf);
    }
    mmi_ucs2cpy((PS8)str_ptr, (PS8)str_val);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_network_proxy_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_network_proxy_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 input_buffer_size;
    S32 item_offset = 0;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE item_icons[3 * 2] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,        
    };

    EntryNewScreen(SCR_ID_VDOPLY_NETWORK_PROXY, mmi_vdoply_exit_network_proxy_scr, NULL, NULL);

    InitializeCategory57Screen();

    /* Proxy On/Off */
    g_vdoply_cntx.proxy_on_off_str[0] = (UI_string_type)GetString((U16)(STR_GLOBAL_OFF));
    g_vdoply_cntx.proxy_on_off_str[1] = (UI_string_type)GetString((U16)(STR_GLOBAL_ON));

    SetInlineItemCaption(&wgui_inline_items[item_offset], (PU8) GetString((U16) (STR_ID_VDOPLY_PROXY)));
    item_offset++;

    g_vdoply_cntx.inline_proxy_on_off = g_vdoply_cntx.proxy_on_off;

    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);    
    SetInlineItemSelect(
        &wgui_inline_items[item_offset],
        2,
        (U8 **) g_vdoply_cntx.proxy_on_off_str,
        &g_vdoply_cntx.inline_proxy_on_off);
    item_offset++;

    /* Proxy server */
    SetInlineItemCaption(&wgui_inline_items[item_offset], (U8*) GetString(STR_ID_VDOPLY_PROXY_ADDR));
    item_offset++;

    mmi_vdoply_three_digit_ip_str((PS8)g_vdoply_cntx.inline_proxy_addr[0], g_vdoply_cntx.proxy_addr[0]);
    mmi_vdoply_three_digit_ip_str((PS8)g_vdoply_cntx.inline_proxy_addr[1], g_vdoply_cntx.proxy_addr[1]);
    mmi_vdoply_three_digit_ip_str((PS8)g_vdoply_cntx.inline_proxy_addr[2], g_vdoply_cntx.proxy_addr[2]);
    mmi_vdoply_three_digit_ip_str((PS8)g_vdoply_cntx.inline_proxy_addr[3], g_vdoply_cntx.proxy_addr[3]);    
    
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemIP4(
        &wgui_inline_items[item_offset],
        (U8*)g_vdoply_cntx.inline_proxy_addr[0],
        (U8*)g_vdoply_cntx.inline_proxy_addr[1],
        (U8*)g_vdoply_cntx.inline_proxy_addr[2],
        (U8*)g_vdoply_cntx.inline_proxy_addr[3],
        mmi_vdoply_ip_addr_callback);
    item_offset++;

    /* Proxy port */
    SetInlineItemCaption(&wgui_inline_items[item_offset], (U8*) GetString(STR_ID_VDOPLY_PROXY_PORT));
    item_offset++;
    
    gui_itoa(g_vdoply_cntx.proxy_port, (UI_string_type)g_vdoply_cntx.inline_proxy_port, 10);
    
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);     
    SetInlineItemTextEdit(
        &wgui_inline_items[item_offset],
        (U8*)g_vdoply_cntx.inline_proxy_port,
        VDOPLY_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
        
    EnableInlineItemBoundary(&wgui_inline_items[item_offset]);
    DisableInlineItemHighlight(&wgui_inline_items[item_offset]);    
    item_offset++;

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_NETWORK_PROXY);
    input_buffer = GetCurrNInputBuffer(SCR_ID_VDOPLY_NETWORK_PROXY, &input_buffer_size);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_offset, input_buffer);
    }

    RegisterHighlightHandler(mmi_vdoply_network_proxy_highlight_hdlr);

#if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdoply_network_proxy_lsk_hdlr);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_network_proxy_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_exit_network_proxy_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 num_of_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    h.scrnID = SCR_ID_VDOPLY_NETWORK_PROXY;
    h.entryFuncPtr = mmi_vdoply_entry_network_proxy_scr;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & num_of_history);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_network_proxy_highlight_hdlr
 * DESCRIPTION
 *  adjust screen highlight handler
 * PARAMETERS
 *  index       [IN]        Selected item's index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_network_proxy_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdoply_network_proxy_lsk_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_network_proxy_lsk_hdlr
 * DESCRIPTION
 *  adjust option screen lsk handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_network_proxy_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 port;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    port = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_proxy_port);   
    
    if (port > 65535)
    {
        mmi_vdoply_disply_popup(
            (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_SETTING),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);        
        return;
    }

    
    g_vdoply_cntx.proxy_addr[0] = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_proxy_addr[0]);
    g_vdoply_cntx.proxy_addr[1] = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_proxy_addr[1]);
    g_vdoply_cntx.proxy_addr[2] = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_proxy_addr[2]);    
    g_vdoply_cntx.proxy_addr[3] = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_proxy_addr[3]);
    g_vdoply_cntx.proxy_port = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_proxy_port);     
    g_vdoply_cntx.proxy_on_off = (MMI_BOOL)g_vdoply_cntx.inline_proxy_on_off;

    mmi_vdoply_store_setting();

    mmi_vdoply_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);

    DeleteNHistory(1);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_network_udp_port_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_network_udp_port_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 input_buffer_size;
    S32 item_offset = 0;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lowest, highest */
    MMI_ID_TYPE item_icons[2 * 2] =  
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0
    };

    EntryNewScreen(SCR_ID_VDOPLY_NETWORK_UDP_PORT, mmi_vdoply_exit_network_udp_port_scr, NULL, NULL);

    InitializeCategory57Screen();

    /* lowest udp port */
    SetInlineItemCaption(&wgui_inline_items[item_offset], (U8*) GetString(STR_ID_VDOPLY_LOWEST_UDP_PORT));
    item_offset++;
    
    gui_itoa(g_vdoply_cntx.lowest_udp_port, (UI_string_type)g_vdoply_cntx.inline_lowest_udp_port, 10);
    
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);     
    SetInlineItemTextEdit(
        &wgui_inline_items[item_offset],
        (U8*)g_vdoply_cntx.inline_lowest_udp_port,
        VDOPLY_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
        
    EnableInlineItemBoundary(&wgui_inline_items[item_offset]);
    DisableInlineItemHighlight(&wgui_inline_items[item_offset]);    
    item_offset++;

    /* highest udp port */
    SetInlineItemCaption(&wgui_inline_items[item_offset], (U8*) GetString(STR_ID_VDOPLY_HIGHEST_UDP_PORT));
    item_offset++;
    
    gui_itoa(g_vdoply_cntx.highest_udp_port, (UI_string_type)g_vdoply_cntx.inline_highest_udp_port, 10);
    
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);     
    SetInlineItemTextEdit(
        &wgui_inline_items[item_offset],
        (U8*)g_vdoply_cntx.inline_highest_udp_port,
        VDOPLY_MAX_PORT_LEN,
        INPUT_TYPE_NUMERIC);
        
    EnableInlineItemBoundary(&wgui_inline_items[item_offset]);
    DisableInlineItemHighlight(&wgui_inline_items[item_offset]);    
    item_offset++;

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_NETWORK_UDP_PORT);
    input_buffer = GetCurrNInputBuffer(SCR_ID_VDOPLY_NETWORK_UDP_PORT, &input_buffer_size);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_offset, input_buffer);
    }

    RegisterHighlightHandler(mmi_vdoply_network_udp_port_highlight_hdlr);

#if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdoply_network_udp_port_lsk_hdlr);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_exit_network_udp_port_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_exit_network_udp_port_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 input_buffer_size;
    history h;
    S16 num_of_history = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();

    h.scrnID = SCR_ID_VDOPLY_NETWORK_UDP_PORT;
    h.entryFuncPtr = mmi_vdoply_entry_network_udp_port_scr;

    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & num_of_history);
    input_buffer_size = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, input_buffer_size);

}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_network_udp_port_highlight_hdlr
 * DESCRIPTION
 *  adjust screen highlight handler
 * PARAMETERS
 *  index       [IN]        Selected item's index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_network_udp_port_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdoply_network_udp_port_lsk_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_network_udp_port_lsk_hdlr
 * DESCRIPTION
 *  adjust option screen lsk handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_network_udp_port_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highest_port;
    S32 lowest_port;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lowest_port = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_lowest_udp_port);   
    
    if (lowest_port < 6000 || lowest_port > 65532)
    {
        mmi_vdoply_disply_popup(
            (PU8)GetString(STR_ID_VDOPLY_NOTIFY_INVALID_SETTING),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);        
        return;
    }

    highest_port = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_highest_udp_port);   
    
    if (highest_port < 6003 || highest_port > 65535)
    {
        mmi_vdoply_disply_popup(
            (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_SETTING),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);        
        return;
    }

    if (highest_port -  lowest_port < 3)
    {
        mmi_vdoply_disply_popup(
            (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_SETTING),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);        
        return;
    }

    g_vdoply_cntx.lowest_udp_port = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_lowest_udp_port);     
    g_vdoply_cntx.highest_udp_port = gui_atoi((UI_string_type)&g_vdoply_cntx.inline_highest_udp_port);   
    
    mmi_vdoply_store_setting();

    mmi_vdoply_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);

    DeleteNHistory(1);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_ip_addr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_ip_addr_callback(U8 *string_buffer, U8 *ip1, U8 *ip2, U8 *ip3, U8 *ip4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 point[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) point, (S8*) ".");

    mmi_ucs2cpy((PS8) string_buffer, (PS8) ip1);
    mmi_ucs2cat((PS8) string_buffer, (PS8) point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) ip2);
    mmi_ucs2cat((PS8) string_buffer, (PS8) point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) ip3);
    mmi_ucs2cat((PS8) string_buffer, (PS8) point);
    mmi_ucs2cat((PS8) string_buffer, (PS8) ip4);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_streaming_url_scr
 * DESCRIPTION
 *  entry stream url screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_streaming_url_scr(void)
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
    EntryNewScreen(SCR_ID_VDOPLY_STREAMING_URL, NULL, mmi_vdoply_entry_streaming_url_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_STREAMING_URL);
    num_item = GetNumOfChild(MENU_ID_VDOPLY_STREAMING_URL);

    GetSequenceStringIds(MENU_ID_VDOPLY_STREAMING_URL, item_list);
    GetSequenceImageIds(MENU_ID_VDOPLY_STREAMING_URL, item_icons);
    SetParentHandler(MENU_ID_VDOPLY_STREAMING_URL);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < num_item; i++)
    {
        popup_list[i] = NULL;
    }

    ConstructHintsList(MENU_ID_VDOPLY_STREAMING_URL, popup_list);

    ShowCategory52Screen(
        STR_ID_VDOPLY_STREAMING_URL,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
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
 *  mmi_vdoply_entry_predefined_url_scr
 * DESCRIPTION
 *  entry predefined url screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_predefined_url_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    S16 error;
    S32 url_len;
    S32 server_name_len;
    U16 item_icons[16]; 
    U8 *gui_buffer;    
    nvram_ef_video_url_struct predef_url_list[NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOPLY_PREDEFINED_URL, NULL, mmi_vdoply_entry_predefined_url_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_PREDEFINED_URL);

    ReadRecord(
        NVRAM_EF_VIDEO_PREDEFINED_URL_LID, 
        1,  /* id start from 1 */ 
        (void*)predef_url_list, 
        NVRAM_EF_VIDEO_PREDEFINED_URL_SIZE, 
        &error);

    index = 0;
    for (i = 0 ; i < NVRAM_EF_VIDEO_PREDEFINED_URL_TOTAL; i++)
    {
        url_len = mmi_ucs2strlen((PS8)predef_url_list[i].url);
        server_name_len = mmi_ucs2strlen((PS8)predef_url_list[i].name);
        
        if (url_len == 0 || server_name_len == 0)
        {
            break;
        }

        memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        /* copy char - 1 to keep null terminate */
        mmi_ucs2ncpy((PS8)subMenuDataPtrs[i], (PS8)predef_url_list[i].name, MAX_SUBMENU_CHARACTERS-1);
        index++;
            
    }
    
    if (index == 0)
    {
        /* 
         * this may happend when customer didnt config nvram for predefined url,
         * but turn on display predefined compile option
         */
        ASSERT(0);
    }

    for (i = 0; i < index; i++)
    {
        item_icons[i] = (U16)(IMG_GLOBAL_L1 + i);
    }

    RegisterHighlightHandler(mmi_vdoply_url_highlight_hdlr);

    ShowCategory53Screen(
        STR_ID_VDOPLY_STREAMING_URL,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        subMenuDataPtrs,
        item_icons,
        NULL,
        0,
        0,
        gui_buffer);
    
    SetLeftSoftkeyFunction(mmi_vdoply_predefined_url_lsk_hdlr, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_predefined_url_lsk_hdlr
 * DESCRIPTION
 *  predefine url screen lsk handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_predefined_url_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_video_url_struct predef_url_list[NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT];    
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_VIDEO_PREDEFINED_URL_LID, 
        1,    /* id start from 1 */ 
        (void*)&predef_url_list, 
        NVRAM_EF_VIDEO_PREDEFINED_URL_SIZE, 
        &error);
    
#ifdef MMS_SUPPORT
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)predef_url_list[g_vdoply_cntx.highlight_idx].url);
#endif

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_history_url_scr
 * DESCRIPTION
 *  entry history url screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_history_url_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    S16 error;
    S32 url_len;
    S32 name_len;
    U16 item_icons[16]; 
    U8 *gui_buffer;    
    nvram_ef_video_url_struct history_url;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOPLY_HISTORY_URL, NULL, mmi_vdoply_entry_history_url_scr, NULL);

    /* remove unused files in Z:\VideoStream */
    mmi_vdoply_history_sync_sdp_file();

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_HISTORY_URL);

    index = 0;
    for (i = 0 ; i < NVRAM_EF_VIDEO_HISTORY_URL_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_VIDEO_HISTORY_URL_LID, 
            i+1,    /* id start from 1 */ 
            (void*)&history_url, 
            NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
            &error);

        url_len = mmi_ucs2strlen((PS8)history_url.url);
        name_len = mmi_ucs2strlen((PS8)history_url.name);
        if (url_len == 0)
        {
            /* empty url */
            break;
        }
        
        if (name_len == 0)
        {
            /* dont have name, show url link */
            
            /* have name, show name */
            memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
            
            if (url_len > MAX_SUBMENU_CHARACTERS-1)
            {
                /* researve 3 char for "..." and 1 char for null terminate */
                mmi_ucs2ncpy((PS8)subMenuDataPtrs[i], (PS8)history_url.url, MAX_SUBMENU_CHARACTERS-4);        
                mmi_ucs2cat((PS8)subMenuDataPtrs[i], (PS8)L"...");
            }
            else
            {
                /* 1 char for null terminate */                
                mmi_ucs2ncpy((PS8)subMenuDataPtrs[i], (PS8)history_url.url, MAX_SUBMENU_CHARACTERS-1);  
            }
        }
        else
        {
            /* have name, show name */
            
            memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);

            if (name_len > MAX_SUBMENU_CHARACTERS-1)
            {
                /* researve 3 char for "..." and 1 char for null terminate */
                mmi_ucs2ncpy((PS8)subMenuDataPtrs[i], (PS8)history_url.name, MAX_SUBMENU_CHARACTERS-4);        
                mmi_ucs2cat((PS8)subMenuDataPtrs[i], (PS8)L"...");
            }
            else
            {
                /* 1 char for null terminate */
                mmi_ucs2ncpy((PS8)subMenuDataPtrs[i], (PS8)history_url.name, MAX_SUBMENU_CHARACTERS-1);  
            }
        }

        index ++;
    }

    if (index == 0)
    {
        /* if no history - popup */
        DisplayPopup(
            (PU8)GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);                  
        
        DeleteNHistory(1);
        return;
    }

    for (i = 0; i < index; i++)
    {
        item_icons[i] = (U16)(IMG_GLOBAL_L1 + i);
    }

    RegisterHighlightHandler(mmi_vdoply_url_highlight_hdlr);

    ShowCategory53Screen(
        STR_ID_VDOPLY_HISTORY_URL,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        subMenuDataPtrs,
        item_icons,
        NULL,
        0,
        0,
        gui_buffer);
    
    SetLeftSoftkeyFunction(mmi_vdoply_entry_history_option_scr, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}




/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_history_option_scr
 * DESCRIPTION
 *  entry history option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_history_option_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_list[16];
    U16 item_icons[16];
    U16 num_item;
    U8 *gui_buffer;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOPLY_HISTORY_OPTION, NULL, mmi_vdoply_entry_history_option_scr, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOPLY_HISTORY_OPTION);
    num_item = GetNumOfChild(MENU_ID_VDOPLY_HISTORY_OPTION);

    GetSequenceStringIds(MENU_ID_VDOPLY_HISTORY_OPTION, item_list);
    GetSequenceImageIds(MENU_ID_VDOPLY_HISTORY_OPTION, item_icons);
    SetParentHandler(MENU_ID_VDOPLY_HISTORY_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < num_item; i++)
    {
        item_icons[i] = (U16)(IMG_GLOBAL_L1 + i);
    }

    ShowCategory52Screen(
        STR_ID_VDOPLY_STREAMING_URL,
        GetRootTitleIcon(MENU_ID_VDOPLY_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        item_list,
        item_icons,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_history_play_url
 * DESCRIPTION
 *  play history url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_history_play_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_video_url_struct history_url;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_VIDEO_HISTORY_URL_LID, 
        g_vdoply_cntx.highlight_idx+1,    /* id start from 1 */ 
        (void*)&history_url, 
        NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
        &error);


    memset(g_vdoply_cntx.history_title_name, 0, sizeof(g_vdoply_cntx.history_title_name));        
    mmi_ucs2ncpy(g_vdoply_cntx.history_title_name, (PS8)history_url.name, MDI_VIDEO_INFO_TITLE_CHAR_COUNT - 1);

    g_vdoply_cntx.is_from_history = TRUE;

    /* "Z:\\@VideoStream\\" */
    if (mmi_ucs2ncmp((PS8)L"Z:", (PS8)history_url.url, 2) == 0)
    {
        /* sdp file */
        mmi_vdoply_entry_player_screen_from_sdp_file((PS8)history_url.url, FALSE);       
        
    }
    else
    {
        /* rtsp */
        mmi_vdoply_entry_player_screen_from_rtsp_link((PS8)history_url.url);       
    }

    /* delet to STREAM URL screen */
    DeleteScreenIfPresent(SCR_ID_VDOPLY_HISTORY_URL);
    DeleteScreenIfPresent(SCR_ID_VDOPLY_HISTORY_OPTION);    
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_history_remove_confirm_scr
 * DESCRIPTION
 *  remove history url confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_history_remove_confirm_scr(void)
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
        get_string(STR_ID_VDOPLY_NOTIFY_REMOVE_URL_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdoply_history_remove_url, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_history_remove_url
 * DESCRIPTION
 *  remove history url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_history_remove_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_video_url_struct url;
    S16 error;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.highlight_idx == NVRAM_EF_VIDEO_HISTORY_URL_TOTAL-1)
    {
        /* last element, just remove it by reset all valeu to zero */
        memset((void*)&url, 0, sizeof(nvram_ef_video_url_struct));

        WriteRecord(
            NVRAM_EF_VIDEO_HISTORY_URL_LID, 
            g_vdoply_cntx.highlight_idx+1,    /* id start from 1 */ 
            (void*)&url, 
            NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
            &error);
    }
    else
    {   
        /* not last element, move next upward and clean next one */
        for (i = g_vdoply_cntx.highlight_idx; i < NVRAM_EF_VIDEO_HISTORY_URL_TOTAL - 1; i++)
        {
            /* read next */
            ReadRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                (i+1) + 1,    /* id start from 1 */ 
                (void*)&url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);

            /* write this */
            WriteRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                (i) + 1,    /* id start from 1 */ 
                (void*)&url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);
        }

        /* clean last */
        memset((void*)&url, 0, sizeof(nvram_ef_video_url_struct));

        WriteRecord(
            NVRAM_EF_VIDEO_HISTORY_URL_LID, 
            (NVRAM_EF_VIDEO_HISTORY_URL_TOTAL - 1) + 1,    /* id start from 1 */ 
            (void*)&url, 
            NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
            &error);        
    }
    
    DisplayPopup(
        (PU8)GetString(STR_ID_VDOPLY_NOTIFY_HISTORY_REMOVED),
        IMG_GLOBAL_INFO,
        1,
        ST_NOTIFYDURATION,
        WARNING_TONE);   

    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_history_insert_url
 * DESCRIPTION
 *  insert history url
 * PARAMETERS
 *  url_p       [IN]         url buffer in unicode
 *  name_p      [IN]        name buffer in unicode 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_history_insert_url(PS8 url_p, PS8 name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define VDOPLY_SDP_READ_BUFFER   (30)
    
    S32 history_count;
    S32 i;
    S32 exist_ind;
    S16 error;
    S32 url_len;
    nvram_ef_video_url_struct history_url;
    nvram_ef_video_url_struct move_url;
    U8 history_sdp_file_buf[VDOPLY_SDP_READ_BUFFER];
    U8 sdp_file_buf[VDOPLY_SDP_READ_BUFFER];
    FS_HANDLE history_sdp_h;
    FS_HANDLE sdp_h;
    FS_HANDLE fs_h;    
    U32 history_sdp_read;    
    U32 sdp_read;
    U32 sdp_write;
    MMI_BOOL is_same_file;
    S8 ansii_str[50];
    S8 usc2_str[50];    
                   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p != NULL);
    MMI_ASSERT(name_p != NULL);    
     
    /* 
     * search how many history already in history, 
     * and search if already have this entry 
     */

    history_count = 0;
    exist_ind = -1;
    
    for (i = 0 ; i < NVRAM_EF_VIDEO_HISTORY_URL_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_VIDEO_HISTORY_URL_LID, 
            i+1,    /* id start from 1 */ 
            (void*)&history_url, 
            NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
            &error);


        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
        {
            url_len = mmi_ucs2strlen((PS8)history_url.url);

            if (url_len == 0)
            {
                /* empty entry */
                break;
            }
            
            /* compare two url */
            if (mmi_ucs2cmp((PS8)url_p, (PS8)history_url.url) == 0)
            {
                if (i == 0)
                {
                    /* already is first one */
                    return;
                }
                
                /* hit. already in history */
                exist_ind = i;
                break;
            }

        }
        else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
        {
            /* "Z:\\@VideoStream\\" */
            if (mmi_ucs2ncmp((PS8)L"Z:", (PS8)history_url.url, 2) == 0)
            {
                /* this entry's url is Z:, it is a cached SDP file */
                /* compare two sdp file */
                history_sdp_h = FS_Open((U16*)history_url.url, FS_READ_ONLY);
                sdp_h = FS_Open((U16*)url_p, FS_READ_ONLY);                

                is_same_file = MMI_TRUE;
                while (1)
                {
                    FS_Read(history_sdp_h, history_sdp_file_buf, VDOPLY_SDP_READ_BUFFER, &history_sdp_read);
                    FS_Read(sdp_h, sdp_file_buf, VDOPLY_SDP_READ_BUFFER, &sdp_read);

                    if (sdp_read != history_sdp_read)
                    {
                        /* read size not match, different file */      
                        is_same_file = MMI_FALSE;
                        break;
                    }

                    if (memcmp((void*)sdp_file_buf, (void*)history_sdp_file_buf, sdp_read) != 0)
                    {
                        /* content not match, different file */
                        is_same_file = MMI_FALSE;
                        break;
                    }

                    if (sdp_read < VDOPLY_SDP_READ_BUFFER)
                    {
                        break;
                    }
                }

                if (sdp_h  > 0)
                {
                    FS_Close(sdp_h);
                }

                if (history_sdp_h  > 0)
                {
                    FS_Close(history_sdp_h);
                }

                /* same sdp file */
                if (is_same_file)
                {
                    if (i == 0)
                    {
                        /* already is first one */
                        return;
                    }
                    
                    /* hit. already in history */
                    exist_ind = i;
                    break;
                }
                
            }

        }
        else
        {
            MMI_ASSERT(0);
        }


        history_count++;
    }

    if (exist_ind != -1)
    {
        /* already in history, move it to first and move others down */
        
        for (i = exist_ind - 1; i >= 0 ; i--)
        {
            /* read this */
            ReadRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                i+1,    /* id start from 1 */ 
                (void*)&move_url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);

            /* write to next */
            WriteRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                i+1+1,    /* id start from 1 */ /* +1 for next */
                (void*)&move_url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);
        }
        
        /* insert this to 1st */
        WriteRecord(
            NVRAM_EF_VIDEO_HISTORY_URL_LID, 
            1,    /* id start from 1 */
            (void*)&history_url, 
            NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
            &error);        

        return;
    }
    else
    {
        /* newly added */
        
        if (history_count == NVRAM_EF_VIDEO_HISTORY_URL_TOTAL)
        {
            /* avoid overflow */
            history_count--;
        }

        for (i = history_count - 1; i >= 0 ; i--)
        {
            /* read this */
            ReadRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                i+1,    /* id start from 1 */ 
                (void*)&move_url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);

            /* write to next */
            WriteRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                i+1+1,    /* id start from 1 */ /* +1 for next */
                (void*)&move_url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);
        }

        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM)
        {
            /* insert this to 1st */
            memset((void*)&history_url, 0, sizeof(history_url));
            mmi_ucs2ncpy((PS8)history_url.url , url_p, VIDEO_MAX_URL_LEN);
            mmi_ucs2ncpy((PS8)history_url.name , name_p, VIDEO_MAX_NAME_LEN);     
        
            WriteRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                1,    /* id start from 1 */
                (void*)&history_url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);  
        }
        /* copy file to Z: */
        else if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)
        {
            i = 0;
            /* use a loop to find a empty file name */
            while(1)
            {
                sprintf((PS8)ansii_str, "Z:\\@VideoStream\\%d.sdp", i);
                /* we will store the sdp as Z:\1.sdp ... etc */
                mmi_asc_to_ucs2(usc2_str, ansii_str);
                fs_h = FS_Open((U16*)usc2_str, FS_READ_ONLY);  

                if (fs_h < 0)
                {
                    /* file not exist */
                    break;
                }
                else
                {
                    FS_Close(fs_h);
                }
                i++;
            }
            
            sdp_h = FS_Open((U16*)url_p, FS_READ_ONLY);               
            history_sdp_h = FS_Open((U16*)usc2_str, FS_CREATE);

            /* copy from original sdp file to history */
            while(1)
            {
                FS_Read(sdp_h, sdp_file_buf, VDOPLY_SDP_READ_BUFFER, &sdp_read);
                FS_Write(history_sdp_h, sdp_file_buf, VDOPLY_SDP_READ_BUFFER, &sdp_write);

                if (sdp_read < VDOPLY_SDP_READ_BUFFER)
                {
                    /* read end */
                    break;
                }
            }
            
            FS_Close(sdp_h);
            FS_Close(history_sdp_h);

            /* insert this to 1st */
            memset((void*)&history_url, 0, sizeof(history_url));
            mmi_ucs2ncpy((PS8)history_url.url , usc2_str, VIDEO_MAX_URL_LEN);
            mmi_ucs2ncpy((PS8)history_url.name , name_p, VIDEO_MAX_NAME_LEN);     
        
            WriteRecord(
                NVRAM_EF_VIDEO_HISTORY_URL_LID, 
                1,    /* id start from 1 */
                (void*)&history_url, 
                NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
                &error);  
            
        }
        else
        {
            MMI_ASSERT(0);
        }

    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_history_sync_sdp_file
 * DESCRIPTION
 *  sync sdp file in z:\@VideoStream folder, remove unused files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_history_sync_sdp_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define VDOPLY_HISTORY_BUF_LEN   (50)   /* Z:\@VideoStream\xx.sdp */
        
    FS_DOSDirEntry file_info;
    S8 buf_filename[(VDOPLY_HISTORY_BUF_LEN+1) * ENCODING_LENGTH];
    S8 buf_filepath[(VDOPLY_HISTORY_BUF_LEN+1) * ENCODING_LENGTH]; 
    FS_HANDLE file_handle;
    nvram_ef_video_url_struct history[NVRAM_EF_VIDEO_HISTORY_URL_TOTAL];
    S16 error;
    PS8 filename_p;
    MMI_BOOL is_in_history;
    S32 fs_ret;
    S32 i;
    S8 filter[(VDOPLY_HISTORY_BUF_LEN+1) * ENCODING_LENGTH];
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /* load all histoy into memory */
    for (i = 0; i < NVRAM_EF_VIDEO_HISTORY_URL_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_VIDEO_HISTORY_URL_LID, 
            i+1,    /* id start from 1 */ 
            (void*)&history[i], 
            NVRAM_EF_VIDEO_HISTORY_URL_SIZE, 
            &error);
    }

    mmi_ucs2cpy((PS8)filter, (PS8)L"Z:\\@VideoStream\\*.*");

    file_handle = FS_FindFirst(
                    (U16*)filter, 
                    0, 
                    0, 
                    &file_info, 
                    (U16*)buf_filename, 
                    sizeof(buf_filename));
    

    if (file_handle  > 0)
    {
        /* extrac files in Z:\@VideoStream one by one, and check if it is in hitroy */
        do
        {
            is_in_history = MMI_FALSE;
            
            for (i = 0; i < NVRAM_EF_VIDEO_HISTORY_URL_TOTAL; i++)
            {
                /* check if it a sdp file, not rtsp url */
                if (mmi_ucs2ncmp((PS8)L"Z:", (PS8)history[i].url, 2) == 0)
                {
                    filename_p = mmi_fmgr_extract_file_name((PS8)history[i].url);
                    if (mmi_ucs2cmp(buf_filename, filename_p) == 0)
                    {
                        /* this file is in history */
                        is_in_history = MMI_TRUE;
                        break;
                    }
                }
            } 

            if (!is_in_history)
            {
                /* delete file */
                mmi_ucs2cpy(buf_filepath, (PS8)L"Z:\\@VideoStream\\");
                mmi_ucs2cat(buf_filepath, buf_filename);
                FS_Delete((U16*)buf_filepath);
            }

            fs_ret = FS_FindNext(
                        file_handle, 
                        &file_info,
                        (PU16)buf_filename,
                        sizeof(buf_filename));
            
        }while (fs_ret == FS_NO_ERROR);

        FS_FindClose(file_handle);
    }
   
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_predefined_url_highlight_hdlr
 * DESCRIPTION
 *  entry predefined url screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_url_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoply_cntx.highlight_idx = index;
}




#endif /* defined(__MMI_VIDEO_STREAM__) */




/*****************************************************************************
 *
 * Streaming
 *
 *****************************************************************************/
#ifdef __MMI_VIDEO_STREAM__ 
 /*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_from_rtsp_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_entry_player_screen_from_rtsp_link(PS8 rtsp_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* avoid re-entry */
    mmi_vdoply_delete_all_from_history();
    
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_rtsp_streaming,
        MMI_FULL_SCREEN);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_STREAMING_RTSP;
  
    mmi_ucs2cpy(g_vdoply_cntx.source_path, rtsp_url);

    /* store path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_store_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    mmi_vdoply_entry_player_screen_internal();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_re_entry_player_screen_from_rtsp_streaming
 * DESCRIPTION
 *  re-entry player screen for playing progressive dl file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_re_entry_player_screen_from_rtsp_streaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_rtsp_streaming,
        MMI_FULL_SCREEN);

    /* allcoate buffer for filename */
    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_STREAMING_RTSP;

    /* get path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_load_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
#endif 

    mmi_vdoply_entry_player_screen_internal();
}



 /*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_from_sdp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_entry_player_screen_from_sdp_file(PS8 sdp_filename, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* avoid re-entry */
    mmi_vdoply_delete_all_from_history();
    
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_sdp_streaming,
        MMI_FULL_SCREEN);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_STREAMING_SDP;
    g_vdoply_cntx.is_short_filename = is_short;
  
    mmi_ucs2cpy(g_vdoply_cntx.source_path, sdp_filename);

    /* store path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_store_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    mmi_vdoply_entry_player_screen_internal();

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_re_entry_player_screen_from_sdp_streaming
 * DESCRIPTION
 *  re-entry player screen for playing progressive dl file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_re_entry_player_screen_from_sdp_streaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_sdp_streaming,
        MMI_FULL_SCREEN);

    /* allcoate buffer for filename */
    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_STREAMING_SDP;

    /* get path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_load_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
#endif 

    mmi_vdoply_entry_player_screen_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_re_entry_player_screen_from_ram_streaming
 * DESCRIPTION
 *  re-entry player screen for playing progressive dl file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_re_entry_player_screen_from_ram_streaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_ram_streaming,
        MMI_FULL_SCREEN);

    /* allcoate buffer for filename */
    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_STREAMING_RAM;

    /* get path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_load_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
#endif 

    mmi_vdoply_entry_player_screen_internal();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_from_ram_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_entry_player_screen_from_ram_file(PS8 ram_filename, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 readed;
    S8 url_buf[FMGR_PATH_CHAR_COUNT+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* avoid re-entry */
    mmi_vdoply_delete_all_from_history();
    
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_ram_streaming,
        MMI_FULL_SCREEN);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_STREAMING_RAM;
    
    memset(g_vdoply_cntx.source_path, 0 , FMGR_PATH_BUFFER_SIZE);
    
    file_handle = FS_Open((U16*)ram_filename, FS_READ_ONLY);

    memset(url_buf, 0, FMGR_PATH_CHAR_COUNT+1);
    
    if (file_handle >=0)
    {
        FS_Read(file_handle, (void*)url_buf, FMGR_PATH_CHAR_COUNT, &readed);
        FS_Close(file_handle);
    }

    mmi_asc_to_ucs2((PS8)g_vdoply_cntx.source_path, (PS8)url_buf);

    /* store path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_store_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    mmi_vdoply_entry_player_screen_internal();

}




/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_player_connect_done_hdlr
 * DESCRIPTION
 *  function to be called when file is opened.
 * PARAMETERS
 *  result          [IN]        >=0, means successfully opened, if result < 0 measn some error happened)
 *  vdo_clip        [IN]        Video info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_stream_connect_result_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_len;
    S32 i;
    MMI_BOOL is_valid;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    /* check if already exit player screen */
    if (GetExitScrnID() != SCR_ID_VDOPLY_PLAYER)
    {
        return;
    }    

    if (result == MDI_RES_VDOPLY_ERR_NETWORK_DISCONNECT)
    {
        mmi_vdoply_bt_close_codec();
        
        /* network tear down */
        if (g_vdoply_cntx.ui_type== VDOPLY_UI_TYPE_NORMAL)
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
        }
        else if (g_vdoply_cntx.ui_type== VDOPLY_UI_TYPE_FULLSCR)
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
        }
        else
        {
            MMI_ASSERT(0);
        }
        
        mmi_vdoply_disply_popup(
            (PU8) GetString(STR_ID_VDOPLY_NOTIFY_CONNECT_FAILED),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);


        DeleteNHistory(1);        
        return;
    }

    if (result >= 0)
    {
        /* 
         * connect result will only have     
         * (1) track type
         * (2) total time (media len)
         * (3) seekable or not
         * (4) aud_channel_no
         * (5) aud sample rate
         * (6) video name
         */
        g_vdoply_cntx.video_info.total_time_duration = vdo_clip->total_time_duration;
        g_vdoply_cntx.video_info.is_seekable = vdo_clip->is_seekable;
        g_vdoply_cntx.video_info.track = vdo_clip->track;
        g_vdoply_cntx.video_info.aud_channel_no = vdo_clip->aud_channel_no;        
        g_vdoply_cntx.video_info.aud_sample_rate= vdo_clip->aud_sample_rate;

        str_len = strlen((PS8)vdo_clip->title_name);

        /* stream has title, change title name to this */
        if (str_len != 0)
        {
            /* check if title is all space */
            is_valid = MMI_FALSE;
            for (i = 0; i < str_len; i++)
            {
                if (vdo_clip->title_name[i] != ' ')
                {
                    is_valid = MMI_TRUE;
                    break;                    
                }
            }

            if (is_valid)
            {
                memset(g_vdoply_cntx.video_info.title_name, 0, sizeof(g_vdoply_cntx.video_info.title_name));            
              
                mmi_asc_n_to_ucs2(
                    (PS8)g_vdoply_cntx.video_info.title_name, 
                    (PS8)&vdo_clip->title_name, 
                    MDI_VIDEO_INFO_TITLE_CHAR_COUNT - 1);
            }
        }
       
        /* store url to history */
        mmi_vdoply_history_insert_url(g_vdoply_cntx.source_path, g_vdoply_cntx.video_info.title_name);
        
        g_vdoply_cntx.is_source_opened = TRUE;

        if (g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RTSP || 
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_RAM ||
            g_vdoply_cntx.play_source == VDOPLY_PLAY_FROM_STREAMING_SDP)  
        {
             g_vdoply_cntx.is_progress_seekable = (BOOL)g_vdoply_cntx.video_info.is_seekable;
        }
        
        switch(g_vdoply_cntx.state)
        {
            case VDOPLY_STATE_STREAM_CONNECTING:
                mmi_vdoply_clear_connecting_anim();    
                
                /* update skin from SDP/RTSP's description */
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();

                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
                }
                break;

            case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
                mmi_vdoply_clear_connecting_anim();

                /* update skin from SDP/RTSP's description */
                mmi_vdoply_draw_bg();
                mmi_vdoply_draw_title();
                mmi_vdoply_draw_softkey();
                mmi_vdoply_draw_panel();
                
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_BUFFERING);
                }
                break;
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
                mmi_vdoply_clear_fullscr_connecting_anim();
                if (mmi_vdoply_is_output_to_bt())
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
                }
                else
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
                }   
                break;
		
            case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
                mmi_vdoply_clear_fullscr_connecting_anim();

                if (g_vdoply_cntx.video_info.is_seekable)
                {
                    mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_CONNECTED);
                }
                else
                {
                    if (mmi_vdoply_is_output_to_bt())
                    {
                        mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING);
                    }
                    else
                    {
                        mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
                    }       
                }                
                break;
         #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
            default:
                MMI_ASSERT(0);
                break;                
        }
    }
    else
    {
        switch(g_vdoply_cntx.state)
        {        
            case VDOPLY_STATE_STREAM_CONNECTING:
            case VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING:
                mmi_vdoply_clear_connecting_anim();               
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);           
                break;
        #ifdef __VDOPLY_FEATURE_FULLSCREEN__                  
            case VDOPLY_STATE_STREAM_FULLSCR_CONNECTING:
            case VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING:
                mmi_vdoply_clear_fullscr_connecting_anim();
                mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);    
                break;
        #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
             default:
                MMI_ASSERT(0);
                break;
        }
        
        /* if connect failed - popup and go to previous window */
        mmi_vdoply_disply_popup(
            (PU8) GetString(STR_ID_VDOPLY_NOTIFY_CONNECT_FAILED),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        DeleteNHistory(1);

    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stream_buffering_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_stream_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING);
 
        
    mdi_video_stream_get_buf_percentage(&percentage);
    mmi_vdoply_draw_loading(percentage, MMI_FALSE);
    mmi_vdoply_blt_screen();

    if (percentage < 100)
    {
        gui_start_timer(100, mmi_vdoply_stream_buffering_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stream_fullscr_buffering_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOPLY_FEATURE_FULLSCREEN__)
static void mmi_vdoply_stream_fullscr_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 percentage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING);
    
    mdi_video_stream_get_buf_percentage(&percentage);
    mmi_vdoply_draw_fullscr_loading(percentage, MMI_FALSE);
    mmi_vdoply_draw_fullscr_osd();
    mmi_vdoply_blt_screen();

    if (percentage < 100)
    {
        gui_start_timer(100, mmi_vdoply_stream_fullscr_buffering_cyclic);
    }
    
}
#endif /* defined(__VDOPLY_FEATURE_FULLSCREEN__) */



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stream_stop_buffering
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_stream_stop_buffering(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoply_stream_buffering_cyclic);
#if defined(__VDOPLY_FEATURE_FULLSCREEN__)    
    gui_cancel_timer(mmi_vdoply_stream_fullscr_buffering_cyclic);  
#endif 
    mmi_vdoply_bt_close_codec();
    mmi_vdoply_disconnect_bt();    

    mdi_video_stream_stop_buffering();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stream_start_buffering
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_stream_start_buffering(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoply_cntx.is_stream_opened)
    {
        if (g_vdoply_cntx.video_info.is_seekable)
        {
            ret = mdi_video_stream_start_buffering(
                     g_vdoply_cntx.cur_status.play_time,            
                     mmi_vdoply_stream_buffering_done_hdlr);
        }
        else
        {
            ret = mdi_video_stream_start_buffering(
                     0,            
                     mmi_vdoply_stream_buffering_done_hdlr);
        }
    }
    else
    {
        if (g_vdoply_cntx.video_info.is_seekable)
        {
            ret = mdi_video_stream_start_buffering(
                     g_vdoply_cntx.cur_status.play_time,            
                     mmi_vdoply_player_open_done_hdlr);
        }
        else
        {
            ret = mdi_video_stream_start_buffering(
                     0,            
                     mmi_vdoply_player_open_done_hdlr);
        }
    }
   
    if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
    {
        return;
    }    

    if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING)
    {
        mmi_vdoply_stream_buffering_cyclic();  
    }
    else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        mmi_vdoply_stream_fullscr_buffering_cyclic();   
    #endif
    }
    else
    {
        MMI_ASSERT(0);
    }
 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stream_buffering_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_stream_buffering_done_hdlr(MDI_RESULT result, mdi_video_info_struct *vdo_clip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if already exit player screen */
    if (GetExitScrnID() != SCR_ID_VDOPLY_PLAYER)
    {
        return;
    }

    /* if open sucessfully */
    if (result >= 0)
    {
        mdi_video_stream_set_brightness(g_vdoply_cntx.brightness);
        mdi_video_stream_set_contrast(g_vdoply_cntx.contrast);
        
        if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING)
        {
             mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_PLAY);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING)
        {
             mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_PLAY);
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (result == MDI_RES_VDOPLY_ERR_INVALID_RESOULTION)
        {
            str_id = STR_ID_VDOPLY_NOTIFY_INVALID_RESOLUTION;
        }
        else
        {
            str_id = STR_ID_VDOPLY_NOTIFY_PLAY_FAILED;
        }
            
        if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING)
        {
            mdi_video_stream_disconnect();            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_DISCONNECT);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING)
        {
            mdi_video_stream_disconnect();            
            mmi_vdoply_enter_state(VDOPLY_STATE_STREAM_FULLSCR_DISCONNECT);
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }
                
        /* if open file error - popup and go to previous screen */
        mmi_vdoply_disply_popup(
            (PU8) GetString(str_id),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        
        DeleteNHistory(1);     
            
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_stream_receive_da_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_stream_receive_da_file(
        S32 session_id, 
        S32 mime_type, 
        S32 mime_subtype, 
        S32 action, 
        PU16 file_path, 
        PS8 url, 
        PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_STREAM_RECEIVE_DA_FILE);
    MMI_ASSERT(mime_type == MIME_TYPE_APPLICATION);
    MMI_ASSERT(mime_subtype == MIME_SUBTYPE_SDP);    

    mmi_vdoply_entry_player_screen_from_sdp_file((PS8)file_path, FALSE);
    g_vdoply_cntx.is_da_spd_file = TRUE;
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_rtsp_url_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_rtsp_url_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vdoply_rtsp_url_data_struct *url_data_ptr;
    S32 str_len;
    S8 str_buf[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isInCall() && !IsWapCallPresent())
    {
        /* receive this message after call launched, should igore */
        return;
    }
    
    url_data_ptr = (mmi_vdoply_rtsp_url_data_struct*)msg_ptr;

    str_len = strlen(url_data_ptr->rtsp_url);

    if (str_len > FMGR_PATH_CHAR_COUNT)
    {
        /* TODO: change string to URL too long */
        DisplayPopup(
            (PU8)GetString(STR_ID_VDOPLY_NOTIFY_INVALID_URL),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);            
        return;
    }
    
    /* path is ASCII, we need covent it to Unicode */
    mmi_asc_to_ucs2(str_buf, url_data_ptr->rtsp_url);
    
    mmi_vdoply_entry_player_screen_from_rtsp_link(str_buf);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_send_rtsp_url_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_send_rtsp_url_req(PS8 rtsp_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE message;
    mmi_vdoply_rtsp_url_data_struct *url_data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    url_data_ptr = OslConstructDataPtr(sizeof(mmi_vdoply_rtsp_url_data_struct));
    
    /* url is ascii string */
    strncpy(url_data_ptr->rtsp_url, rtsp_url, FMGR_PATH_BUFFER_SIZE);

    message.oslMsgId = MSG_ID_MMI_VDOPLY_RTSP_URL_REQ;
    message.oslDataPtr = (oslParaType*)url_data_ptr;
    message.oslPeerBuffPtr = NULL;
    message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_MMI;

    OslMsgSendExtQueue(&message);
    
}


#endif /* __MMI_VIDEO_STREAM__ */




/*****************************************************************************
 *
 * Progressive Download
 *
 *****************************************************************************/
#ifdef __MMI_VIDEO_PDL__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_player_screen_from_pdl_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_vdoply_entry_player_screen_from_pdl_file(PS8 filename, BOOL is_short)
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

        if (mmi_usb_check_path_exported(filename))
        {
            /* file is in exported device */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_pdl_file,
        MMI_FULL_SCREEN);

    /* allcoate buffer for filename */
    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_PROGRESSIVE_DL;

    g_vdoply_cntx.is_short_filename = is_short;
    mmi_ucs2cpy(g_vdoply_cntx.source_path, filename);

    /* store path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_store_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    mmi_vdoply_entry_player_screen_internal();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_re_entry_player_screen_from_pdl_file
 * DESCRIPTION
 *  re-entry player screen for playing progressive dl file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_re_entry_player_screen_from_pdl_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOPLY_PLAYER,
        mmi_vdoply_exit_player_screen_internal,
        mmi_vdoply_re_entry_player_screen_from_pdl_file,
        MMI_FULL_SCREEN);

    /* get path to NVRAM, use for recover filename when back from interrupt */
    mmi_fmgr_util_load_filepath(g_vdoply_cntx.source_path, FMGR_PATH_ID_VIDEO);

    g_vdoply_cntx.play_source = VDOPLY_PLAY_FROM_PROGRESSIVE_DL;

#ifdef __VDOPLY_FEATURE_TOUCH_SCREEN__
    g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
#endif 
    mmi_vdoply_entry_player_screen_internal();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_entry_pdl_teminate_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_entry_pdl_teminate_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
#if defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)

    DisplayConfirmRotated(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOPLY_NOTIFY_TEMINATE_PDL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE,
        MMI_FRM_SCREEN_ROTATE_270);
        
#else /* defined(__VDOPLY_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOPLY_NOTIFY_TEMINATE_PDL),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    SetRightSoftkeyFunction(mmi_vdoply_pdl_teminate_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdoply_pdl_teminate_confirm_yes, KEY_EVENT_UP);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_teminate_confirm_yes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_pdl_teminate_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_vdoply_cntx.is_pdl_debug)
    {
        g_vdoply_cntx.pdl_dl_session_id = -1;     
        g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_EXIT;   
        g_vdoply_cntx.is_pdl_debug = FALSE;
    }

    if(g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_DOWNLOADING)
    {
        MMI_ASSERT(g_vdoply_cntx.pdl_dl_session_id != -1);
        
        /* progressive DL is not finished */
    #ifdef __MMI_DOWNLOAD_AGENT__
        mmi_da_stop_dl(g_vdoply_cntx.pdl_dl_session_id);
    #endif
    }

    g_vdoply_cntx.pdl_dl_session_id = -1;     
    g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_EXIT;     
    
    mmi_vdoply_disply_popup(
        (PU8)GetString(STR_ID_VDOPLY_NOTIFY_PDL_TERMINATED), 
        IMG_GLOBAL_ACTIVATED, 
        1, 
        ST_NOTIFYDURATION, 
        SUCCESS_TONE);

    /* delete video player from history */
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_teminate_confirm_no
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_pdl_teminate_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_buffering_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_pdl_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_percent;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_percent = g_vdoply_cntx.pdl_buf_percent;
    
    ret = mdi_video_progressive_get_buf_percentage(&g_vdoply_cntx.pdl_buf_percent);
    
    if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
    {
        return;
    }     

    if (g_vdoply_cntx.pdl_buf_percent > prev_percent)
    {
        /* if bar progress foward, draw it */        
        mmi_vdoply_draw_loading(g_vdoply_cntx.pdl_buf_percent, MMI_FALSE);
        mmi_vdoply_blt_screen();
    }

    if (g_vdoply_cntx.pdl_buf_percent != 100)
    {
        gui_start_timer(300, mmi_vdoply_pdl_buffering_cyclic);
    }
    else
    {
        /* sleep 100ms to let 100% progress bar show longer */
        kal_sleep_task(30);
        
        /* percentage == 100 */
        if (g_vdoply_cntx.state == VDOPLY_STATE_PROGRESSIVE_BUFFERING)
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_IDLE);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_PROGRESSIVE_PLAY_BUFFERING)
        {
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_PLAY);
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_fullscr_buffering_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOPLY_FEATURE_FULLSCREEN__
static void mmi_vdoply_pdl_fullscr_buffering_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 prev_percent;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_percent = g_vdoply_cntx.pdl_buf_percent;
    
    ret = mdi_video_progressive_get_buf_percentage(&g_vdoply_cntx.pdl_buf_percent);
    
    if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
    {
        return;
    }     

    if (g_vdoply_cntx.pdl_buf_percent > prev_percent)
    {
        /* if bar progress foward, draw it */
        mmi_vdoply_draw_fullscr_loading(g_vdoply_cntx.pdl_buf_percent, MMI_FALSE);
        mmi_vdoply_blt_screen();
    }

    if (g_vdoply_cntx.pdl_buf_percent != 100)
    {
        gui_start_timer(300, mmi_vdoply_pdl_fullscr_buffering_cyclic);
    }
    else
    {
        /* sleep 100ms to let 100% progress bar show longer */
        kal_sleep_task(30);
        
        /* percentage == 100 */
        if (g_vdoply_cntx.state == VDOPLY_STATE_PROGRESSIVE_FULLSCR_BUFFERING)
        {
            mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_IDLE);
        }
        else if (g_vdoply_cntx.state == VDOPLY_STATE_PROGRESSIVE_FULLSCR_PLAY_BUFFERING)
        {
            if (mmi_vdoply_is_output_to_bt())
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_BT_CONNECTING);
            }
            else
            {
                mmi_vdoply_enter_state(VDOPLY_STATE_FULLSCR_PLAY);
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}
#endif /* __VDOPLY_FEATURE_FULLSCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_draw_progressbar_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_pdl_draw_progressbar_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_buff_ratio;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION("[VDOPLY] mmi_vdoply_pdl_draw_progressbar_cyclic()");          
    
    prev_buff_ratio = g_vdoply_cntx.cur_status.buff_ratio;

    if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_NORMAL)
    {
       /* get progressisve dl available time */
        ret = mdi_video_progressive_get_max_play_time(&g_vdoply_cntx.cur_status.max_play_time);

        if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
        {
            return;
        }           
        
        mmi_vdoply_calc_progress_ratio();
  
        if (g_vdoply_cntx.cur_status.buff_ratio != prev_buff_ratio)
        {
            mmi_vdoply_draw_panel_progress();
            mmi_vdoply_blt_screen();            
        }

    }
    else if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
    {
    #ifdef __VDOPLY_FEATURE_FULLSCREEN__
        /* get progressisve dl available time */
        ret = mdi_video_progressive_get_max_play_time(&g_vdoply_cntx.cur_status.max_play_time);

        if (mmi_vdoply_check_and_display_error_popup(ret) == TRUE)  /* ture means has error popup */
        {
            return;
        }    

        mmi_vdoply_calc_progress_ratio();

        if (g_vdoply_cntx.cur_status.buff_ratio != prev_buff_ratio)
        {
            mmi_vdoply_draw_fullscr_osd();
            mmi_vdoply_blt_screen();            
        }
    #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
    }
    
    if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_DOWNLOADING)
    {
        /* 1 sec get max time once */
    	gui_start_timer(1000, mmi_vdoply_pdl_draw_progressbar_cyclic);
    }
}

   


#if defined __MMI_DOWNLOAD_AGENT__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_da_notify_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoply_pdl_da_notify_file(
    	S32	session_id,
    	S32	mime_type,                  
    	S32	mime_subtype, 
    	S32 action,
    	U32	filesize,
    	PS8	url,                        
    	PS8	mime_type_string,           
    	U32	content_len,
    	PS8	content,
    	mmi_da_setting_struct *settings_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_pdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_PDL_DA_NOTIFY_FILE);       

    /* not progressive video */
    mmi_da_default_setting(
        session_id,
        mime_type,
        mime_subtype,
        action,
        filesize,
        url,
        mime_type_string,
        content_len,
        content,
        settings_p);
        
    if (action == MMI_DA_WAP_DOWNLOAD)
    {
        mmi_vdoply_load_setting();
        mdi_video_progressive_is_pdl_format((PU8)content, content_len, &is_pdl);

        if (is_pdl)
        {
            /* is progressive dl 3gp and it is from WAP download */

            settings_p->bypass = MMI_FALSE;                               /* bypass */
            settings_p->default_filename = MMI_FALSE;                     /* incoming's name, user can edit */
            settings_p->filepath_hdlr = mmi_vdoply_pdl_da_filepath_hdlr;  /* notify where is the file */
            settings_p->report_hdlr = mmi_vdoply_pdl_da_report_hdlr;      /* download status report */
            settings_p->percentage_bar = MMI_FALSE;                       /* do not show process bar */
            settings_p->storage = MMI_DA_STORAGE_NONE;                    /* let user choose storage */
            settings_p->drv = 0;                                          /* not usesed if storage is none*/
            settings_p->keepfile = TRUE;                                  /* keep file when cancel */
            mmi_ucs2cpy((S8*)settings_p->folder, (S8*)FMGR_DEFAULT_FOLDER_VIDEO);

            g_vdoply_cntx.pdl_dl_session_id = session_id;
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_da_report_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoply_pdl_da_report_hdlr(
                S32 session_id,
                S32 status,
                S32 cause,
                U32 seq_num,
                U32 acc_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    PU8 str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(                             \
        MMI_TRACE_G8_MEDIA,                 \
        MMI_TRC_VDOPLY_PDL_DA_REPORT_HDLR,  \
        cause,                              \
        g_vdoply_cntx.pdl_dl_state,         \
        session_id,                         \
        g_vdoply_cntx.pdl_dl_session_id);   
    
    switch (status)
    {
        case MMI_DA_STATE_DOWNLOADING:
            PRINT_INFORMATION("[VDOPLY_EX] DA Downloading");            
            MMI_ASSERT(session_id == g_vdoply_cntx.pdl_dl_session_id);            
            if (g_vdoply_cntx.pdl_dl_state == VDOPLY_PDL_DL_STATE_EXIT)
            {
                if (isInCall() && !IsWapCallPresent())
                {
                    /* this may happened when WAP send message to DA, at this this, a call happened */
                    mmi_da_stop_dl(g_vdoply_cntx.pdl_dl_session_id);
                    return;
                }
                
                g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_DOWNLOADING;
                mmi_vdoply_entry_player_screen_from_pdl_file(g_vdoply_cntx.source_path, FALSE);            
            }
            break;

        case MMI_DA_STATE_COMPLETE:
            PRINT_INFORMATION("[VDOPLY_EX] DA Complete");                        
            MMI_ASSERT(session_id == g_vdoply_cntx.pdl_dl_session_id);                        
            g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_FINISHED;  
            g_vdoply_cntx.pdl_dl_session_id = -1;
            break;
            
        case MMI_DA_STATE_ABORT:
            PRINT_INFORMATION("[VDOPLY_EX] DA Abort");            
            g_vdoply_cntx.pdl_dl_state = VDOPLY_PDL_DL_STATE_EXIT;               
            g_vdoply_cntx.pdl_dl_session_id = -1;
            
            if (cause == MMI_DA_ERROR_DISK_FULL)
            {
                str_ptr = (PU8)GetString(FMGR_FS_DISK_FULL_TEXT);
            }
            else
            {
                str_ptr = (PU8)GetString(STR_ID_VDOPLY_NOTIFY_NETWORK_ERROR);
            }

            scr_id = GetExitScrnID();

            if (scr_id > SCR_ID_VDOPLY_START && scr_id < SCR_ID_VDOPLY_END)
            {
                mmi_vdoply_disply_popup(
                    str_ptr,
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                
                /* delete up to the prvious screen of video player */
                DeleteUptoScrID(SCR_ID_VDOPLY_PLAYER);
                DeleteNHistory(1);
            }
            
            break;

        case MMI_DA_STATE_USER_CANCEL:
            break;

        default:
            MMI_ASSERT(0);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_pdl_da_filepath_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdoply_pdl_da_filepath_hdlr(
                S32 session_id,
                S32 mime_type, 
                S32 mime_subtype, 
                PU16 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOPLY_PDL_DA_FILEPATH_HDLR);   
    MMI_ASSERT(session_id == g_vdoply_cntx.pdl_dl_session_id);
    MMI_ASSERT(mime_type == MIME_TYPE_VIDEO);

    mmi_ucs2cpy(g_vdoply_cntx.source_path, (PS8)filepath);    

    /* return TRUE will continue the downloading */
    return TRUE;

}
#endif /* __MMI_DOWNLOAD_AGENT__ */
#endif /* __MMI_VIDEO_PDL__ */



#ifdef __MMI_AVRCP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  ACRCP command handler
 * PARAMETERS
 *  command     [IN]     command type
 *  event       [IN]     key event
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static U8 mmi_vdoply_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        case MMI_AVRCP_POP_PAUSE:    
            PRINT_INFORMATION("[VDOPLY_AVRCP] command: PLAY or POP, line:%d", __LINE__);    
                    
            if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
            
                /* full screen */
                if (event == MMI_AVRCP_KEY_UP)
                {
                    PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_UP, line:%d", __LINE__);    
                    mmi_vdoply_ck_release();
                }
                else if (event == MMI_AVRCP_KEY_DOWN)
                {
                    PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_DOWN, line:%d", __LINE__);                        
                    mmi_vdoply_ck_press();
                }
                else if (event == MMI_AVRCP_KEY_CANCELED)
                {
                    PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_CANCELED, line:%d", __LINE__);                      
                    g_vdoply_cntx.touch_ck.is_press = FALSE;
                    mmi_vdoply_draw_fullscr_osd();
                    mmi_vdoply_blt_screen();
                }
                else
                {
                    /* ingore others */
                }        
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */        
            }
            else
            {
                /* normal screen */
                if (event == MMI_AVRCP_KEY_UP)
                {
                    PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_UP, line:%d", __LINE__);                        
                    mmi_vdoply_ck_release();
                }
                else if (event == MMI_AVRCP_KEY_DOWN)
                {
                    PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_DOWN, line:%d", __LINE__);                        
                    mmi_vdoply_ck_press();
                }
                else if (event == MMI_AVRCP_KEY_CANCELED)
                {
                    PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_CANCELED, line:%d", __LINE__);                         
                    g_vdoply_cntx.touch_ck.is_press = FALSE;
                    mmi_vdoply_draw_softkey();
                    mmi_vdoply_blt_screen();
                }
                else
                {
                    /* ingore others */
                }
            }
            break;

        case MMI_AVRCP_POP_STOP:
            PRINT_INFORMATION("[VDOPLY_AVRCP] command: STOP, line:%d", __LINE__);   

            if (g_vdoply_cntx.ui_type == VDOPLY_UI_TYPE_FULLSCR)
            {
            #ifdef __VDOPLY_FEATURE_FULLSCREEN__
                if (g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY || 
                    g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PAUSE ||
                    g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_BT_CONNECTING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_SEEKING || 
                    g_vdoply_cntx.state == VDOPLY_STATE_FULLSCR_PLAY_SEEKING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_PLAY ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_CONNECTING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_INTERRUPTED_CONNECTING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BUFFERING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_FULLSCR_BT_CONNECTING)
                {
                    /* full screen */
                    if (event == MMI_AVRCP_KEY_UP)
                    {
                        PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_UP, line:%d", __LINE__);                            
                        mmi_vdoply_rsk_release();
                    }
                    else if (event == MMI_AVRCP_KEY_DOWN)
                    {
                        PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_DOWN, line:%d", __LINE__);                            
                        mmi_vdoply_rsk_press();
                    }
                    else if (event == MMI_AVRCP_KEY_CANCELED)
                    {
                        PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_CANCELED, line:%d", __LINE__);                             
                        g_vdoply_cntx.touch_rsk.is_press = FALSE;
                        mmi_vdoply_draw_fullscr_osd();
                        mmi_vdoply_blt_screen();
                    }
                    else
                    {
                        /* ingore others */
                    }   
                }
            #endif /* __VDOPLY_FEATURE_FULLSCREEN__ */
            }
            else
            {
                /* normal screen */
                if (g_vdoply_cntx.state == VDOPLY_STATE_PLAY || 
                    g_vdoply_cntx.state == VDOPLY_STATE_PAUSE ||
                    g_vdoply_cntx.state == VDOPLY_STATE_BT_CONNECTING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_SEEKING || 
                    g_vdoply_cntx.state == VDOPLY_STATE_PLAY_SEEKING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_PLAY ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_CONNECTING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_INTERRUPTED_CONNECTING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BUFFERING ||
                    g_vdoply_cntx.state == VDOPLY_STATE_STREAM_BT_CONNECTING)
                {
                    /* full screen */
                    if (event == MMI_AVRCP_KEY_UP)
                    {
                        PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_UP, line:%d", __LINE__);                            
                        mmi_vdoply_rsk_release();
                    }
                    else if (event == MMI_AVRCP_KEY_DOWN)
                    {
                        PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_DOWN, line:%d", __LINE__);                            
                        mmi_vdoply_rsk_press();
                    }
                    else if (event == MMI_AVRCP_KEY_CANCELED)
                    {
                        PRINT_INFORMATION("[VDOPLY_AVRCP] event: KEY_CANCELED, line:%d", __LINE__);                             
                        g_vdoply_cntx.touch_rsk.is_press = FALSE;
                        mmi_vdoply_draw_softkey();
                        mmi_vdoply_blt_screen();
                    }
                    else
                    {
                        /* ingore others */
                    }   
                }
 
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

    return result;

}
#endif /* __MMI_AVRCP_SUPPORT__ */

#endif /* __MMI_VIDEO_PLAYER__ */ 

