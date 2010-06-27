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
 *   VdoRecApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Recorder Applcation.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VDORECAPP_C
#define _MMI_VDORECAPP_C

#ifdef __MMI_VIDEO_RECORDER__



#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */

/* framework related headers */
#include "gui.h"        /* Gui functions */

#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "wgui.h"       /* for GetDateTime() */
#include "gpioInc.h"    /* LED */
#include "IdleAppProt.h"        /* for IsIdleArrived() */
#include "CommonScreens.h"      /* Popup */
#include "ProtocolEvents.h"     /* Interrupt message ID */
#include "MainMenuDef.h"        /* Multi-media icon */
#include "CallManagementGProt.h"        /* CM releated */

#include "wgui_status_icons.h"  /* status UI */
#include "wgui_softkeys.h"      /* softkey */

#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* file error text */
#include "FileMgr.h"
#include "mmiapi_enum.h"        /* Stop LED */
#include "USBDeviceGprot.h"     /* USB MS mode */
#include "AlarmFrameworkProt.h" /* alarm framework */
#include "DataAccountGprot.h"
#include "SimDetectionGprot.h"  /* flight mode */

/* gdi, mid, video rec headers */
#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "mdi_datatype.h"
#include "mdi_video.h"  /* mdi video library */

#ifdef __VDOREC_COLOR_IDX_FRAME__
#include "imgdma.h"
#include "mdi_camera.h"
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 

#ifdef __MMI_VDOREC_MMS_SUPPORT__
#include "WapProt.h"
#endif 

/* video recoder related */
#include "resource_video_skins.h"       /* UI custom config */

#include "VdoRecResDef.h"
#include "VdoPlyResDef.h"
#include "VdoRecApp.h"
#include "VdoPlyApp.h"
#include "VdoRecGProt.h"
#include "VdoPlyGProt.h"        /* entry function */

#ifdef __MMI_MMS__
#include "wapadp.h"
#endif 

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_FTS_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIFtpGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_FTS_SUPPORT__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_OPP_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIOppGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_OPP_SUPPORT__ */ 


/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND               (0)
#define HINT_POPUP_FADE_TIME        (2000)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern wgui_inline_item wgui_inline_items[];
extern BOOL r2lMMIFlag;

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);
extern kal_uint8 GpioCtrlReq(kal_uint8 action);
extern BOOL IsClamClose(void);
extern void AudioStopReq(U16 soundId);
extern U16 GetCurKeypadTone(void);
extern void refresh_status_icon_display(void);  /* in Wgui_status_icons.c */

/***************************************************************************** 
* Local Variable
*****************************************************************************/
vdorec_context_struct g_vdorec_cntx;
vdorec_menu_context_struct g_vdorec_menu_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/* app */
static void mmi_vdorec_blt_screen(void);
static void mmi_vdorec_hilight_app(void);
static void mmi_vdorec_restore_setting(void);
static void mmi_vdorec_get_save_filename(S8 *file_buf_p);
static void mmi_vdorec_disply_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id);

/* preview */
static BOOL mmi_vdorec_check_and_display_error_popup(void);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_resize_preview_layer(void);
#endif 

static void mmi_vdorec_get_video_size(S32 *video_width, S32 *video_height);
static U16 mmi_vdorec_get_zoom_factor(void);
static U16 mmi_vdorec_get_zoom_image(void);
static void mmi_vdorec_lsk_press_hdlr(void);
static void mmi_vdorec_lsk_release_hdlr(void);
static void mmi_vdorec_rsk_press_hdlr(void);
static void mmi_vdorec_rsk_release_hdlr(void);
static void mmi_vdorec_ck_press_hdlr(void);
static void mmi_vdorec_ck_release_hdlr(void);
static void mmi_vdorec_inc_ev_key_press_hdlr(void);
static void mmi_vdorec_inc_ev_key_release_hdlr(void);
static void mmi_vdorec_dec_ev_key_press_hdlr(void);
static void mmi_vdorec_dec_ev_key_release_hdlr(void);

#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in(void);
static void mmi_vdorec_zoom_in_key_press_hdlr(void);
static void mmi_vdorec_zoom_in_key_release_hdlr(void);
static void mmi_vdorec_zoom_out(void);
static void mmi_vdorec_zoom_out_key_press_hdlr(void);
static void mmi_vdorec_zoom_out_key_release_hdlr(void);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

static void mmi_vdorec_turn_on_led_highlight(void);
static void mmi_vdorec_turn_off_led_highlight(void);
static void mmi_vdorec_record_result_hdlr_callback(MDI_RESULT result);

#ifdef __VDOREC_FEATURE_EFFECT__
static void mmi_vdorec_effect_setting_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_WB__
static void mmi_vdorec_wb_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
static void mmi_vdorec_led_highlight_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
static void mmi_vdorec_night_hotkey_press(void);
#endif 

static void mmi_vdorec_start_preview(void);
static void mmi_vdorec_enter_state(U16 state);


#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_vdorec_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event);
#endif 

static void mmi_vdorec_entry_app_internal(void);
static void mmi_vdorec_entry_app(void);
static void mmi_vdorec_exit_app(void);

#ifdef __MMI_SUBLCD__
static void mmi_vdorec_draw_sublcd_icon(void);
static void mmi_vdorec_entry_sublcd_screen(void);
static void mmi_vdorec_exit_sublcd_screen(void);
#endif /* __MMI_SUBLCD__ */ 

static void mmi_vdorec_record_timer_cyclic(void);
static void mmi_vdorec_draw_title(void);
#ifndef __VDOREC_FEATURE_HIDE_OSD__
static void mmi_vdorec_draw_status(void);
#endif
static void mmi_vdorec_draw_softkey(void);
static void mmi_vdorec_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id);
static void mmi_vdorec_draw_panel_state(void);

#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_draw_panel_ev(void);
#endif 

#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_draw_panel_zoom(void);
#endif 

static void mmi_vdorec_draw_panel_timer(void);
static void mmi_vdorec_draw_panel(void);
static void mmi_vdorec_init_ui(void);
static void mmi_vdorec_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, video_style_text_struct *style_txt);
static void mmi_vdorec_hide_hint(void);
#ifndef __VDOREC_FEATURE_HIDE_OSD__
static void mmi_vdorec_draw_hint(void);
#endif
static void mmi_vdorec_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);
static void mmi_vdorec_draw_osd(void);

/* save */
static void mmi_vdorec_save_confirm_no(void);
static void mmi_vdorec_entry_save_confirm_screen(void);

#ifdef __MMI_VDOREC_MMS_SUPPORT__
static void mmi_vdorec_save_confirm_forward_to(void);
#endif 
static void mmi_vdorec_save_result_hdlr_callback(MDI_RESULT result);
static void mmi_vdorec_exit_saving_screen(void);
static U8 mmi_vdorec_saving_screen_del_hdlr(void *dummy_ptr);
static void mmi_vdorec_entry_saving_screen(void);

/* menu */
static void mmi_vdorec_init_option_menu(void);
static void mmi_vdorec_highlight_to_vdoply(void);
static void mmi_vdorec_entry_option_screen(void);
static void mmi_vdorec_highlight_camcoder_setting(void);
static void mmi_vdorec_camcoder_setting_lsk_press(void);
static void mmi_vdorec_camcoder_setting_highlight_hdlr(S32 index);
static void mmi_vdorec_exit_camcoder_setting_screen(void);
static void mmi_vdorec_entry_camcoder_setting_screen(void);

#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_highlight_video_setting(void);
static void mmi_vdorec_video_setting_lsk_press(void);
static void mmi_vdorec_video_setting_highlight_hdlr(S32 index);
static void mmi_vdorec_exit_video_setting_screen(void);
static void mmi_vdorec_entry_video_setting_screen(void);
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

static void mmi_vdorec_hint_effect_setting(U16 index);
static void mmi_vdorec_highlight_effect_setting(void);
static void mmi_vdorec_set_effect_setting_value(void);
static void mmi_vdorec_entry_effect_setting_screen(void);

#ifdef __VDOREC_COLOR_IDX_FRAME__
static void mmi_vdorec_hint_color_idx_frame(U16 index);
static void mmi_vdorec_highlight_color_idx_frame(void);
static void mmi_vdorec_color_idx_frame_highlight_hdlr(S32 idx);
static void mmi_vdorec_entry_color_idx_frame_view_screen(void);
static void mmi_vdorec_color_idx_frame_goto_previous_frame(void);
static void mmi_vdorec_color_idx_frame_goto_next_frame(void);
static void mmi_vdorec_set_color_idx_frame_value(void);
static void mmi_vdorec_entry_color_idx_frame_screen(void);
static void mmi_vdorec_draw_color_idx_frame(void);
static void mmi_vdorec_preview_change_frame_down(void);
static void mmi_vdorec_preview_change_frame_up(void);
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_STORAGE__
static void mmi_vdorec_hint_storage(U16 index);
static void mmi_vdorec_entry_set_storage_screen(void);
static void mmi_vdorec_highlight_storage(void);
static void mmi_vdorec_entry_set_app_storage_screen(void);
static void mmi_vdorec_entry_set_storage_screen_internal(void);
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
static void mmi_vdorec_set_storage_lsk_hdlr(void);
static void mmi_vdorec_set_storage_rsk_hdlr(void);
static void mmi_vdorec_storage_highlight_handler(S32 index);
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */
#endif /* __VDOREC_FEATURE_STORAGE__ */ 

static void mmi_vdorec_highlight_restore_default(void);
static void mmi_vdorec_entry_restore_default_confirm_yes(void);
static void mmi_vdorec_entry_restore_default_confirm_screen(void);

#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vdorec_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vdorec_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_vdorec_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */

/****************************************************************************
* Setting command map                                                                
*****************************************************************************/

/*********** WB ***********/
const U8 vdorec_wb_command_map[VDOREC_SETTING_WB_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_WB_AUTO__
    MDI_VIDEO_WB_AUTO,  /* CAMREA_SETTING_WB_AUTO */
#endif 

#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
    MDI_VIDEO_WB_DAYLIGHT,  /* VDOREC_SETTING_WB_DAYLIGHT */
#endif 

#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
    MDI_VIDEO_WB_TUNGSTEN,  /* VDOREC_SETTING_WB_TUNGSTEN */
#endif 

#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
    MDI_VIDEO_WB_FLUORESCENT,   /* VDOREC_SETTING_WB_FLUORESCENT */
#endif 

#ifdef __VDOREC_FEATURE_WB_CLOUD__
    MDI_VIDEO_WB_CLOUD, /* VDOREC_SETTING_WB_CLOUD */
#endif 

#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
    MDI_VIDEO_WB_INCANDESCENCE, /* VDOREC_SETTING_WB_INCANDESCENCE */
#endif 

    DUMMY_COMMAND
};

/*********** EV ***********/
const U8 vdorec_ev_command_map[VDOREC_SETTING_EV_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_EV_4__
    MDI_VIDEO_EV_N4,    /* VDOREC_SETTING_EV_N4 */
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    MDI_VIDEO_EV_N3,    /* VDOREC_SETTING_EV_N3 */
#endif 

#ifdef __VDOREC_FEATURE_EV_2__
    MDI_VIDEO_EV_N2,    /* VDOREC_SETTING_EV_N2 */
#endif 

    MDI_VIDEO_EV_N1,    /* VDOREC_SETTING_EV_N1 */
    MDI_VIDEO_EV_0,     /* VDOREC_SETTING_EV_0 */
    MDI_VIDEO_EV_P1,    /* VDOREC_SETTING_EV_P1 */

#ifdef __VDOREC_FEATURE_EV_2__
    MDI_VIDEO_EV_P2,    /* VDOREC_SETTING_EV_P2 */
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    MDI_VIDEO_EV_P3,    /* VDOREC_SETTING_EV_P3 */
#endif 

#ifdef __VDOREC_FEATURE_EV_4__
    MDI_VIDEO_EV_P4,    /* VDOREC_SETTING_EV_P4 */
#endif 

    DUMMY_COMMAND
};

/*********** Banding ***********/
const U8 vdorec_banding_command_map[VDOREC_SETTING_BANDING_COUNT + 1] = 
{
    MDI_VIDEO_BANDING_50HZ,
    MDI_VIDEO_BANDING_60HZ,

    DUMMY_COMMAND
};

/*********** EFFECT ***********/
const U8 vdorec_effect_command_map[VDOREC_SETTING_EFFECT_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_EFFECT_NORMAL__
    MDI_VIDEO_EFFECT_NOMRAL,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    MDI_VIDEO_EFFECT_GRAYSCALE,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA__
    MDI_VIDEO_EFFECT_SEPIA,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    MDI_VIDEO_EFFECT_SEPIA_GREEN,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    MDI_VIDEO_EFFECT_SEPIA_BLUE,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    MDI_VIDEO_EFFECT_COLOR_INVERT,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    MDI_VIDEO_EFFECT_GRAY_INVERT,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    MDI_VIDEO_EFFECT_BLACKBOARD,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    MDI_VIDEO_EFFECT_WHITEBOARD,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    MDI_VIDEO_EFFECT_COPPER_CARVING,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    MDI_VIDEO_EFFECT_BLUE_CARVING,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    MDI_VIDEO_EFFECT_EMBOSSMENT,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_CONTRAST__
    MDI_VIDEO_EFFECT_CONTRAST,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_JEAN__
    MDI_VIDEO_EFFECT_JEAN,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SKETCH__
    MDI_VIDEO_EFFECT_SKETCH,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_OIL__
    MDI_VIDEO_EFFECT_OIL,
#endif 

    DUMMY_COMMAND
};

#if defined(MDI_VIDEO_MT6228_SERIES)

   /*********** Video Size ***********/
const U8 vdorec_video_size_command_map[VDOREC_SETTING_VIDEO_SIZE_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    MDI_VIDEO_VIDEO_SIZE_SQCIF,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    MDI_VIDEO_VIDEO_SIZE_QQVGA,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    MDI_VIDEO_VIDEO_SIZE_QCIF,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    MDI_VIDEO_VIDEO_SIZE_CIF,
#endif 

    DUMMY_COMMAND
};

#else /* MDI_VIDEO_MT6228_SERIES */ 
   /* MT6219 and previous chip only support QCIF size */

   /*********** Video Size ***********/
const U8 vdorec_video_size_command_map[VDOREC_SETTING_VIDEO_SIZE_COUNT + 1] = 
{
    MDI_VIDEO_VIDEO_SIZE_QCIF,
    DUMMY_COMMAND
};
#endif /* MDI_VIDEO_MT6228_SERIES */ 

/*********** Video Qty ***********/
const U8 vdorec_video_qty_command_map[VDOREC_SETTING_VIDEO_QTY_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
    MDI_VIDEO_REC_QTY_FINE,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    MDI_VIDEO_REC_QTY_HIGH,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    MDI_VIDEO_REC_QTY_NORMAL,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
    MDI_VIDEO_REC_QTY_LOW,
#endif 

    DUMMY_COMMAND
};

/*********** Video Format ***********/
const U8 vdorec_video_format_command_map[VDOREC_SETTING_VIDEO_FORMAT_COUNT + 1] = 
{
    MDI_VIDEO_VIDEO_FORMAT_3GP,
    MDI_VIDEO_VIDEO_FORMAT_MP4,

    DUMMY_COMMAND
};

/*****************************************************************************
*
* Applcation Related
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_for_external_request
 * DESCRIPTION
 *  Entry video recorder and record a video with requested size 
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
void mmi_vdorec_entry_for_external_request(
        S8 *filepath, 
        U32 max_size, 
        void (*result_callback)(MMI_BOOL result, S8 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(result_callback != NULL);
    g_vdorec_cntx.ext_req_callback = result_callback;
    g_vdorec_cntx.is_ext_req = MMI_TRUE;
    g_vdorec_cntx.is_use_ext_req_path = MMI_FALSE;       
    g_vdorec_cntx.ext_req_size = max_size;

    /* video can be record so accurate, -5K for margin  */
    g_vdorec_cntx.ext_req_size -= 5;

    /* limited size 10k */
    MMI_ASSERT(g_vdorec_cntx.ext_req_size >= 10);
    
    if (filepath != NULL)
    {
        g_vdorec_cntx.is_use_ext_req_path = MMI_TRUE;        
        mmi_fmgr_util_store_filepath(filepath, FMGR_PATH_ID_VIDEO);
    }

    mmi_vdorec_entry_app_internal();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_in_app
 * DESCRIPTION
 *  is in video recorder app or not
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_vdorec_is_in_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.state != VDOREC_STATE_EXIT)
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
 *  mmi_vdorec_blt_screen
 * DESCRIPTION
 *  blt full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
#else 
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hilight_app
 * DESCRIPTION
 *  highlight vdorec menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_app
 * DESCRIPTION
 *  init vdorec applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VDOREC_APP, mmi_vdorec_hilight_app);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    SetHiliteHandler(MAIN_MENU_OPTION_VDOREC_APP, mmi_vdorec_hilight_app);
#endif 

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;
    g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
    g_vdorec_cntx.is_saving = FALSE;
    g_vdorec_cntx.is_sub_display = FALSE;
    g_vdorec_cntx.is_setting_loaded = FALSE;

    /* Init Option Menu */
    mmi_vdorec_init_option_menu();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_load_setting
 * DESCRIPTION
 *  load setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read storage setting from video player */
    mmi_vdoply_load_setting();

    /* if already loaded into memory, do not need load again */
    if (!g_vdorec_cntx.is_setting_loaded)
    {
        ReadRecord(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_vdorec_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE, &error);

        /* first time init */
        if (g_vdorec_cntx.setting.wb == 0xffff)
        {
            mmi_vdorec_restore_setting();
        }

        g_vdorec_cntx.setting.led_value = VDOREC_DEFAULT_PREVIEW_LED_VALUE;

        g_vdorec_cntx.is_setting_loaded = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_store_setting
 * DESCRIPTION
 *  store setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_vdorec_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_restore_setting
 * DESCRIPTION
 *  restore setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.setting.wb = VDOREC_DEFAULT_SETTING_WB;
    g_vdorec_cntx.setting.ev = VDOREC_DEFAULT_SETTING_EV;
    g_vdorec_cntx.setting.led_highlight = VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT;
    g_vdorec_cntx.setting.night = VDOREC_DEFAULT_SETTING_NIGHT;
    g_vdorec_cntx.setting.banding = VDOREC_DEFAULT_SETTING_BANDING;

    g_vdorec_cntx.setting.effect = VDOREC_DEFAULT_SETTING_EFFECT;

    g_vdorec_cntx.setting.video_size = VDOREC_DEFAULT_SETTING_VIDEO_SIZE;
    g_vdorec_cntx.setting.video_qty = VDOREC_DEFAULT_SETTING_VIDEO_QTY;
    g_vdorec_cntx.setting.size_limit = VDOREC_DEFAULT_SETTING_SIZE_LIMIT;
    g_vdorec_cntx.setting.time_limit = VDOREC_DEFAULT_SETTING_TIME_LIMIT;
    g_vdorec_cntx.setting.record_aud = VDOREC_DEFAULT_SETTING_RECORD_AUD;
    g_vdorec_cntx.setting.video_format = VDOREC_DEFAULT_SETTING_VIDEO_FORMAT;

    g_vdorec_cntx.setting.brightness = 128;
    g_vdorec_cntx.setting.contrast = 128;
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;;

#ifdef __VDOREC_COLOR_IDX_FRAME__
    g_vdorec_cntx.setting.color_idx_frame = VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME;
#endif 
    mmi_vdorec_store_setting();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_save_filename
 * DESCRIPTION
 *  get next file name to be recorded
 * PARAMETERS
 *  file_buf_p      [?]     
 *  a  UUT      filename buffer ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_get_save_filename(S8 *file_buf_p)
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
    ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }

    g_vdorec_cntx.filename_seq_no = filename_seq_no;
    alpha_count = 'Z' - 'A' + 1;

    while(1)
    {

        alpha_index = 0;

        sprintf((PS8)buffer, "MOV%04d", g_vdorec_cntx.filename_seq_no);
        mmi_asc_to_ucs2((PS8)UCS2_buffer, (PS8)buffer);

        while (1)
        {
            sprintf((PS8)buffer, "%c", 'A' + alpha_index);
            mmi_asc_to_ucs2((PS8)UCS2_alpha, (PS8)buffer);

            mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
            mmi_ucs2cat(UCS2_testname, UCS2_alpha);

        #if defined(MP4_CODEC)
            mmi_ucs2cat(UCS2_testname, (PS8)L".3gp");
        #elif defined(MJPG_SUPPORT)
            mmi_ucs2cat(UCS2_testname, (PS8)L".avi");
        #else
            MMI_ASSERT(0);    
        #endif /* chip version */

            mmi_ucs2ncpy((PS8)file_buf_p, (PS8)g_vdorec_cntx.storage_filepath, FMGR_MAX_PATH_LEN);
            mmi_ucs2cat((PS8)file_buf_p, (PS8)UCS2_testname);
			
     	     {
		      S8 FileBuffer[512]  = { 0 };
		      memset(FileBuffer,0,512);
     		      	mmi_ucs2_to_asc(FileBuffer,file_buf_p);
			FileBuffer[511] = '\0' ;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\n 2 Huyanwei debug FileName = (%s) (0x%x 0x%x 0x%x 0x%x 0x%x 0x%x)\r\n", FileBuffer,
			FileBuffer[0],FileBuffer[1],FileBuffer[2],FileBuffer[3],FileBuffer[4],FileBuffer[5]	);
#endif
		}

            file_handle = FS_Open((U16*) file_buf_p, FS_READ_ONLY);

            if (file_handle >= 0)
            {
                /* file exist */
                FS_Close(file_handle);
                alpha_index++;
            }
            else
            {
                /* file not exit. return */
                g_vdorec_cntx.filename_seq_no++;
                WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);
                return;
            }

            if (alpha_index >= alpha_count - 1)
            {
                g_vdorec_cntx.filename_seq_no++;
                /* leave internal while */
                break;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_disply_popup
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
static void mmi_vdorec_disply_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id)
{
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
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
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    DisplayPopup((PU8) str_ptr, (U16) img_id, (U8) image_on_bottom, (U32) tone_duration, (U8) tone_id);
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
}

/*****************************************************************************
*
* Preview Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_check_and_display_error_popup
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_check_and_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.last_error != MDI_RES_VDOREC_SUCCEED)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        switch (g_vdorec_cntx.last_error)
        {
            case MDI_RES_VDOREC_ERR_DISK_FULL:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOREC_ERR_NO_DISK:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOREC_ERR_WRITE_PROTECTION:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_WRITE_PROTECTION),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

                /* followings are serious error, has to exit app */
            case MDI_RES_VDOREC_ERR_HW_NOT_READY:
            case MDI_RES_VDOREC_ERR_POWER_ON_FAILED:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_HW_NOT_READY),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;

            case MDI_RES_VDOREC_ERR_PREVIEW_FAILED:
            case MDI_RES_VDOREC_ERR_RESUME_FAILED:
            case MDI_RES_VDOREC_ERR_PAUSE_FAILED:
            case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
            case MDI_RES_VDOREC_ERR_RECORD_FAILED:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_ERROR),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;
                
            default:
                MMI_ASSERT(0);  /* use assert here, make sure all error case is handled properly */
        }

        /* clear record keys */
        ClearKeyHandler(VDOREC_RECORD_KEY, KEY_EVENT_UP);

        if (VDOREC_RECORD_EXTRA_KEY1 != -1)
        {
            ClearKeyHandler((U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_UP);
        }

        if (VDOREC_RECORD_EXTRA_KEY2 != -1)
        {
            ClearKeyHandler((U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_UP);
        }

        g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_resize_preview_layer
 * DESCRIPTION
 *  resize preview layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_resize_preview_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 video_width;
    S32 video_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_width = 176;
    video_height = 144;

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_SQCIF)
    {
        video_width = 129;
        video_height = 96;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QQVGA)
    {
        video_width = 160;
        video_height = 120;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QCIF)
    {
        video_width = 176;
        video_height = 144;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF)
    {
        video_width = 352;
        video_height = 288;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

    gdi_util_fit_box(
        GDI_UTIL_MODE_LONG_SIDE_FIT,
        g_vdorec_osd_cntx.preview_wnd.rect.width,
        g_vdorec_osd_cntx.preview_wnd.rect.height,
        video_width,
        video_height,
        &resized_offset_x,
        &resized_offset_y,
        &resized_width,
        &resized_height);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    gdi_layer_resize(resized_width, resized_height);
    gdi_layer_set_position(
        g_vdorec_osd_cntx.preview_wnd.rect.offset_x + resized_offset_x,
        g_vdorec_osd_cntx.preview_wnd.rect.offset_y + resized_offset_y);

    gdi_layer_pop_and_restore_active();

}
#endif /* __VDOREC_FEATURE_VIDEO_SIZE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_zoom_factor
 * DESCRIPTION
 *  get zoom factor based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_get_video_size(S32 *video_width, S32 *video_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *video_width = 176;
    *video_height = 144;

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_SQCIF)
    {
        *video_width = 129;
        *video_height = 96;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QQVGA)
    {
        *video_width = 160;
        *video_height = 120;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QCIF)
    {
        *video_width = 176;
        *video_height = 144;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF)
    {
        *video_width = 352;
        *video_height = 288;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_zoom_factor
 * DESCRIPTION
 *  get zoom factor based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_vdorec_get_zoom_factor(void)
{
#ifdef __VDOREC_FEATURE_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define ZOOM_FACTOR_CASE(__id__)                    \
    case __id__:                                    \
        zoom_factor = VDOREC_FEATURE_ZOOM_##__id__; \
        break;
    
    switch (g_vdorec_cntx.setting.zoom)
    {
        ZOOM_FACTOR_CASE(0);
        ZOOM_FACTOR_CASE(1);
        ZOOM_FACTOR_CASE(2);
        ZOOM_FACTOR_CASE(3);
        ZOOM_FACTOR_CASE(4);
        ZOOM_FACTOR_CASE(5);
        ZOOM_FACTOR_CASE(6);
        ZOOM_FACTOR_CASE(7);
        ZOOM_FACTOR_CASE(8);
        ZOOM_FACTOR_CASE(9);
        ZOOM_FACTOR_CASE(10);
        ZOOM_FACTOR_CASE(11);
        ZOOM_FACTOR_CASE(12);
        ZOOM_FACTOR_CASE(13);
        ZOOM_FACTOR_CASE(14);
        ZOOM_FACTOR_CASE(15);
        ZOOM_FACTOR_CASE(16);
        ZOOM_FACTOR_CASE(17);
        ZOOM_FACTOR_CASE(18);
        ZOOM_FACTOR_CASE(19);
        ZOOM_FACTOR_CASE(20);
        ZOOM_FACTOR_CASE(21);        
        ZOOM_FACTOR_CASE(22);
        ZOOM_FACTOR_CASE(23);
        ZOOM_FACTOR_CASE(24);
        ZOOM_FACTOR_CASE(25);        
        ZOOM_FACTOR_CASE(26);
        ZOOM_FACTOR_CASE(27);
        ZOOM_FACTOR_CASE(28);
        ZOOM_FACTOR_CASE(29);        
        ZOOM_FACTOR_CASE(30);
        ZOOM_FACTOR_CASE(31);
        ZOOM_FACTOR_CASE(32);
        ZOOM_FACTOR_CASE(33);        
        ZOOM_FACTOR_CASE(34);
        ZOOM_FACTOR_CASE(35);        
        default:
            ASSERT(0);
            return 0;
    }

#ifdef ISP_SUPPORT
    if (g_vdorec_cntx.zoom_limit < zoom_factor)
    {
        return g_vdorec_cntx.zoom_limit;
    }
    else
    {
        return zoom_factor;
    }
#else /* ISP_SUPPORT */ /* #ifdef ISP_SUPPORT */
    return zoom_factor;
#endif /* ISP_SUPPORT */ /* #ifdef ISP_SUPPORT */

#else /* __VDOREC_FEATURE_ZOOM__ */ 
    return 0;
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_zoom_image
 * DESCRIPTION
 *  get zoom image based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_vdorec_get_zoom_image(void)
{
#ifdef __VDOREC_FEATURE_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zoom_factor = mmi_vdorec_get_zoom_factor();

#define GET_ZOOM_IMAGE_CASE(__id__)              \
    case __id__:                                 \
        return IMG_ID_VDOREC_OSD_ZOOM_##__id__;  \
        break;

    switch (zoom_factor)
    {
        GET_ZOOM_IMAGE_CASE(10);
        GET_ZOOM_IMAGE_CASE(12);
        GET_ZOOM_IMAGE_CASE(14);
        GET_ZOOM_IMAGE_CASE(16);
        GET_ZOOM_IMAGE_CASE(18);
        GET_ZOOM_IMAGE_CASE(20);
        GET_ZOOM_IMAGE_CASE(22);
        GET_ZOOM_IMAGE_CASE(24);
        GET_ZOOM_IMAGE_CASE(26);
        GET_ZOOM_IMAGE_CASE(28);
        GET_ZOOM_IMAGE_CASE(30);
        GET_ZOOM_IMAGE_CASE(32);
        GET_ZOOM_IMAGE_CASE(34);
        GET_ZOOM_IMAGE_CASE(36);        
        GET_ZOOM_IMAGE_CASE(38);
        GET_ZOOM_IMAGE_CASE(40);
        GET_ZOOM_IMAGE_CASE(42);
        GET_ZOOM_IMAGE_CASE(44);        
        GET_ZOOM_IMAGE_CASE(46);
        GET_ZOOM_IMAGE_CASE(48);
        GET_ZOOM_IMAGE_CASE(50);
        GET_ZOOM_IMAGE_CASE(52);
        GET_ZOOM_IMAGE_CASE(54);
        GET_ZOOM_IMAGE_CASE(56);
        GET_ZOOM_IMAGE_CASE(58);
        GET_ZOOM_IMAGE_CASE(60);        
        GET_ZOOM_IMAGE_CASE(62);
        GET_ZOOM_IMAGE_CASE(64);
        GET_ZOOM_IMAGE_CASE(66);        
        GET_ZOOM_IMAGE_CASE(68);
        GET_ZOOM_IMAGE_CASE(70);
        GET_ZOOM_IMAGE_CASE(72);
        GET_ZOOM_IMAGE_CASE(74);
        GET_ZOOM_IMAGE_CASE(76);
        GET_ZOOM_IMAGE_CASE(78);
        GET_ZOOM_IMAGE_CASE(80);        
        default:
            return IMG_ID_VDOREC_OSD_ZOOM_10;
            break;

    }

#endif /* __VDOREC_FEATURE_ZOOM__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lsk_press_hdlr
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_lsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_lsk_pressed = TRUE;
    mmi_vdorec_draw_softkey();
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lsk_release_hdlr
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_lsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_lsk_pressed = FALSE;
    mmi_vdorec_draw_softkey();
    mmi_vdorec_blt_screen();
    mmi_vdorec_entry_option_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_rsk_press_hdlr
 * DESCRIPTION
 *  rsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_rsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_rsk_pressed = TRUE;
    mmi_vdorec_draw_softkey();
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_rsk_release_hdlr
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_rsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    mmi_vdorec_draw_softkey();
    mmi_vdorec_blt_screen();

    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_PREVIEW:
            if (g_vdorec_cntx.is_ext_req)
            {            
                g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
            }
            
            GoBackHistory();
            break;

        case VDOREC_STATE_RECORD:
            mdi_video_rec_record_stop();
            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);

            mmi_vdorec_entry_save_confirm_screen();
            break;

        case VDOREC_STATE_PAUSE:
            mdi_video_rec_record_stop();
            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);

            mmi_vdorec_entry_save_confirm_screen();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_null_key_event
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_null_key_event(void)
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
 *  mmi_vdorec_ck_press_hdlr
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_ck_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_ck_pressed = TRUE;

    mmi_vdorec_draw_softkey();
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_ck_release_hdlr
 * DESCRIPTION
 *  ck release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_ck_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_ck_pressed = FALSE;

    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_PREVIEW:
        case VDOREC_STATE_PAUSE:
            mmi_vdorec_draw_softkey();
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_RECORD);
            break;

        case VDOREC_STATE_RECORD:
            mmi_vdorec_draw_softkey();
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_PAUSE);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev
 * DESCRIPTION
 *  increase ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.setting.ev < VDOREC_SETTING_EV_COUNT - 1)
    {
        g_vdorec_cntx.setting.ev++;

        mdi_video_rec_update_para_ev(vdorec_ev_command_map[g_vdorec_cntx.setting.ev]);

        mmi_vdorec_draw_panel_ev();
        mmi_vdorec_blt_screen();

        if (g_vdorec_cntx.is_first_time_ev)
        {
            /* first time ev, will wait longer to ev again */
            gui_start_timer(300, mmi_vdorec_inc_ev);
            g_vdorec_cntx.is_first_time_ev = FALSE;
        }
        else
        {
            gui_start_timer(100, mmi_vdorec_inc_ev);
        }
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev
 * DESCRIPTION
 *  decrease ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_dec_ev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.setting.ev > 0)
    {
        g_vdorec_cntx.setting.ev--;

        mdi_video_rec_update_para_ev(vdorec_ev_command_map[g_vdorec_cntx.setting.ev]);

        mmi_vdorec_draw_panel_ev();

        mmi_vdorec_blt_screen();

        if (g_vdorec_cntx.is_first_time_ev)
        {
            /* first time ev, will wait longer to ev again */
            gui_start_timer(300, mmi_vdorec_dec_ev);
            g_vdorec_cntx.is_first_time_ev = FALSE;
        }
        else
        {
            gui_start_timer(100, mmi_vdorec_dec_ev);
        }
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev_key_press_hdlr
 * DESCRIPTION
 *  right arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    if (!g_vdorec_cntx.is_ev_inc_key_pressed)
    {
        g_vdorec_cntx.is_ev_inc_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_inc_ev();
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev_key_release_hdlr
 * DESCRIPTION
 *  right arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel timer */
    gui_cancel_timer(mmi_vdorec_inc_ev);
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    mmi_vdorec_draw_panel_ev();
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev_key_press_hdlr
 * DESCRIPTION
 *  left arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_dec_ev_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    if (!g_vdorec_cntx.is_ev_dec_key_pressed)
    {
        g_vdorec_cntx.is_ev_dec_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_dec_ev();
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev_key_release_hdlr
 * DESCRIPTION
 *  left arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_dec_ev_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel timer */
    gui_cancel_timer(mmi_vdorec_dec_ev);
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    mmi_vdorec_draw_panel_ev();
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in
 * DESCRIPTION
 *  zoom in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_zoom_factor;
    U16 next_zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_RECORDING_ZOOM__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 

    if (g_vdorec_cntx.setting.zoom < VDOREC_FEATURE_ZOOM_COUNT - 1)
    {
    #ifdef ISP_SUPPORT
        prev_zoom_factor = mmi_vdorec_get_zoom_factor();

        g_vdorec_cntx.setting.zoom += 1;
        next_zoom_factor = mmi_vdorec_get_zoom_factor();

        if (prev_zoom_factor == next_zoom_factor)
        {
            /* reach sensor zoom limit */
            g_vdorec_cntx.setting.zoom -= 1;
            return;
        }
    #else /* ISP_SUPPORT */ 
        g_vdorec_cntx.setting.zoom += 1;
    #endif /* ISP_SUPPORT */ 

        mdi_video_rec_update_para_zoom(mmi_vdorec_get_zoom_factor());

        mmi_vdorec_draw_panel_zoom();

        mmi_vdorec_blt_screen();

    #if defined(ISP_SUPPORT)
        /* only build-in camera use long pressed zooming feature */
        /* since backend module's zooming time is not stable, will cause zooming jump two level */
        if (g_vdorec_cntx.is_first_time_zoom)
        {
            /* first time zoom, will wait longer to zoom again */
            gui_start_timer(300, mmi_vdorec_zoom_in);
            g_vdorec_cntx.is_first_time_zoom = FALSE;
        }
        else
        {
            gui_start_timer(100, mmi_vdorec_zoom_in);
        }
    #endif /* defined(ISP_SUPPORT) */ 

    }

}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in_key_press_hdlr
 * DESCRIPTION
 *  up arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdorec_cntx.is_zoom_in_key_pressed)
    {
        g_vdorec_cntx.is_zoom_in_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;
        mmi_vdorec_zoom_in();
    }

}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in_key_release_hdlr
 * DESCRIPTION
 *  up arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    gui_cancel_timer(mmi_vdorec_zoom_in);

    mmi_vdorec_draw_panel_zoom();
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out
 * DESCRIPTION
 *  zoom in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_RECORDING_ZOOM__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 

    if (g_vdorec_cntx.setting.zoom > 0)
    {
        g_vdorec_cntx.setting.zoom -= 1;

        mdi_video_rec_update_para_zoom(mmi_vdorec_get_zoom_factor());

        mmi_vdorec_draw_panel_zoom();

        mmi_vdorec_blt_screen();

    #if defined(ISP_SUPPORT)
        /* only build-in camera use long pressed zooming feature */
        /* since backend module's zooming time is not stable, will cause zooming jump two level */
        if (g_vdorec_cntx.is_first_time_zoom)
        {
            /* first time zoom, will wait longer to zoom again */
            gui_start_timer(300, mmi_vdorec_zoom_out);
            g_vdorec_cntx.is_first_time_zoom = FALSE;            
        }
        else
        {
            gui_start_timer(100, mmi_vdorec_zoom_out);
        }
    #endif /* defined(ISP_SUPPORT) */ 
    }

}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out_key_press_hdlr
 * DESCRIPTION
 *  down arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_out_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdorec_cntx.is_zoom_out_key_pressed)
    {
        g_vdorec_cntx.is_zoom_out_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;

        mmi_vdorec_zoom_out();
    }
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out_key_release_hdlr
 * DESCRIPTION
 *  up arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_out_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;
    gui_cancel_timer(mmi_vdorec_zoom_out);

    mmi_vdorec_draw_panel_zoom();
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_turn_on_led_highlight
 * DESCRIPTION
 *  turn on led highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_turn_on_led_highlight(void)
{
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    duty = g_vdorec_cntx.setting.led_value;

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    if (g_vdorec_cntx.setting.led_highlight)
    {
        custom_start_flashlight(1, 1, 1, duty);
    }
#else /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
    /* __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__ */
    switch (g_vdorec_cntx.setting.led_highlight)
    {
        case VDOREC_SETTING_LED_HIGHLIGHT_WHITE:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_RED:
            custom_start_flashlight(1, 0, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_GREEN:
            custom_start_flashlight(0, 1, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_BLUE:
            custom_start_flashlight(0, 0, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_YELLOW:
            custom_start_flashlight(1, 1, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_PURPLE:
            custom_start_flashlight(1, 0, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_CYAN:
            custom_start_flashlight(0, 1, 1, duty);
            break;
    }
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 

#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_turn_off_led_highlight
 * DESCRIPTION
 *  turn off led highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_turn_off_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    custom_stop_flashlight();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_record_result_hdlr_callback
 * DESCRIPTION
 *  record result callback hdlr
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN]        Current state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_record_result_hdlr_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((g_vdorec_cntx.state == VDOREC_STATE_RECORD) || (g_vdorec_cntx.state == VDOREC_STATE_PAUSE));

    gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
    gui_cancel_timer(mmi_vdorec_dec_ev);
    gui_cancel_timer(mmi_vdorec_inc_ev);

#ifdef __VDOREC_FEATURE_ZOOM__
    gui_cancel_timer(mmi_vdorec_zoom_in);
    gui_cancel_timer(mmi_vdorec_zoom_out);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

    if (g_vdorec_cntx.is_ext_req)
    {
        if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_REACH_SIZE_LIMIT),
                IMG_GLOBAL_INFO,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_FAILED)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_ERROR),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);

            DeleteScreenIfPresent(SCR_ID_VDOREC_APP);            
            g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
            return;
        }        
        else
        {
            /* unhandle return */
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_SIZE_LIMIT),
                IMG_GLOBAL_INFO,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_FAILED)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            return;
        }               
        else
        {
            /* unhandle return */
            MMI_ASSERT(0);
        }

    }

    mmi_vdorec_entry_save_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_effect_setting_hotkey_press
 * DESCRIPTION
 *  effect setting hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EFFECT__
static void mmi_vdorec_effect_setting_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.setting.effect < VDOREC_SETTING_EFFECT_COUNT - 1)
    {
        g_vdorec_cntx.setting.effect++;
    }
    else
    {
        g_vdorec_cntx.setting.effect = 0;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_EFFECT_SETTING));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.effect + STR_ID_VDOREC_EFFECT_START + 1)),
        HINT_POPUP_FADE_TIME);

    mmi_vdorec_draw_osd();

    mdi_video_rec_update_para_effect(vdorec_effect_command_map[g_vdorec_cntx.setting.effect]);

    mmi_vdorec_blt_screen();

}
#endif /* __VDOREC_FEATURE_EFFECT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_wb_hotkey_press
 * DESCRIPTION
 *  wb hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_wb_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.setting.wb < VDOREC_SETTING_WB_COUNT - 1)
    {
        g_vdorec_cntx.setting.wb++;
    }
    else
    {
        g_vdorec_cntx.setting.wb = 0;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_WB));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.wb + STR_ID_VDOREC_WB_START + 1)),
        HINT_POPUP_FADE_TIME);

    mmi_vdorec_draw_osd();

    mdi_video_rec_update_para_wb(vdorec_wb_command_map[g_vdorec_cntx.setting.wb]);

    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_led_highlight_hotkey_press
 * DESCRIPTION
 *  led highlight hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__   
static void mmi_vdorec_led_highlight_hotkey_press(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.setting.led_highlight < VDOREC_SETTING_LED_HIGHLIGHT_COUNT - 1)
    {
        g_vdorec_cntx.setting.led_highlight++;
    }
    else
    {
        g_vdorec_cntx.setting.led_highlight = 0;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_LED_HIGHLIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* update osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.led_highlight + STR_ID_VDOREC_LED_HIGHLIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);

    mmi_vdorec_draw_osd();

    /* turn on/of led */
    if (g_vdorec_cntx.setting.led_highlight == VDOREC_SETTING_LED_HIGHLIGHT_OFF)
    {
        mmi_vdorec_turn_off_led_highlight();
    }
    else
    {
        mmi_vdorec_turn_on_led_highlight();
    }

    mmi_vdorec_turn_on_led_highlight();

    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_night_hotkey_press
 * DESCRIPTION
 *  night hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_NIGHT__
static void mmi_vdorec_night_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.setting.night < VDOREC_SETTING_NIGHT_COUNT - 1)
    {
        g_vdorec_cntx.setting.night++;
    }
    else
    {
        g_vdorec_cntx.setting.night = 0;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_NIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");

    /* draw osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.night + STR_ID_VDOREC_NIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);

    mmi_vdorec_draw_osd();

    mdi_video_rec_update_para_night(g_vdorec_cntx.setting.night);

    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_NIGHT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_start_preview
 * DESCRIPTION
 *  Start preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_start_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_setting_struct video_preview_data;
    U32 blt_layer_falg;
    U32 preview_layer_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_preview_data.wb = vdorec_wb_command_map[g_vdorec_cntx.setting.wb];
    video_preview_data.ev = vdorec_ev_command_map[g_vdorec_cntx.setting.ev];
    video_preview_data.banding = vdorec_banding_command_map[g_vdorec_cntx.setting.banding];
    video_preview_data.video_qty = vdorec_video_qty_command_map[g_vdorec_cntx.setting.video_qty];
    video_preview_data.video_format = vdorec_video_format_command_map[g_vdorec_cntx.setting.video_format];
    video_preview_data.effect = vdorec_effect_command_map[g_vdorec_cntx.setting.effect];

    /* user define record size. not used */
    video_preview_data.video_size = vdorec_video_size_command_map[g_vdorec_cntx.setting.video_size];
    video_preview_data.user_def_width = 0;
    video_preview_data.user_def_height = 0;

    video_preview_data.zoom = mmi_vdorec_get_zoom_factor();
    video_preview_data.night = g_vdorec_cntx.setting.night;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    video_preview_data.hue = 0;
    video_preview_data.preview_rotate = VDOREC_MAINLCD_ROTATE;

#ifdef __VDOREC_COLOR_IDX_FRAME__
    if (g_vdorec_cntx.setting.color_idx_frame != VDOREC_SETTING_COLOR_IDX_FRAME_OFF)
    {
        video_preview_data.overlay_frame_mode = TRUE;
        /* although we support 1/2/4/8, but we use 8 only b/c gdi layer support */
        video_preview_data.overlay_frame_depth = OVERLAY_8BPP_PHOTO_FRAME;
        video_preview_data.overlay_frame_width = g_vdorec_cntx.overlay_frame_width;
        video_preview_data.overlay_frame_height = g_vdorec_cntx.overlay_frame_height;
        video_preview_data.overlay_frame_source_key = g_vdorec_cntx.overlay_frame_source_key;
        video_preview_data.overlay_frame_buffer_address = (kal_uint32) g_vdorec_cntx.overlay_frame_buf_ptr;
    }
    else
    {
        video_preview_data.overlay_frame_mode = FALSE;
        video_preview_data.overlay_frame_depth = 0;
        video_preview_data.overlay_frame_width = 0;
        video_preview_data.overlay_frame_height = 0;
        video_preview_data.overlay_frame_source_key = 0;
        video_preview_data.overlay_frame_buffer_address = 0;
    }
#else /* __VDOREC_COLOR_IDX_FRAME__ */ 
    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_270;
#else 
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    switch (g_vdorec_cntx.setting.size_limit)
    {

        case VDOREC_SETTING_SIZE_LIMIT_1:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_1;
            break;

        case VDOREC_SETTING_SIZE_LIMIT_2:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_2;
            break;

        case VDOREC_SETTING_SIZE_LIMIT_3:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_3;
            break;

        default:
            video_preview_data.size_limit = 0;
            break;
    }
#else /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 
    /* no size limit */
    video_preview_data.size_limit = 0;
#endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 

    /* if this is an external record request */
    if (g_vdorec_cntx.is_ext_req)
    {
        if (video_preview_data.size_limit == 0)
        {
            video_preview_data.size_limit = g_vdorec_cntx.ext_req_size;
        }
        else if (g_vdorec_cntx.ext_req_size == 0)
        {
            /* do nothing */
        }
        else
        {
            /* both value not 0 */
            if(g_vdorec_cntx.ext_req_size < video_preview_data.size_limit)
            {
                video_preview_data.size_limit = g_vdorec_cntx.ext_req_size;
            }
        }
    }

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    switch (g_vdorec_cntx.setting.record_aud)
    {
        case VDOREC_SETTING_RECORD_AUD_OFF:
            video_preview_data.record_aud = FALSE;
            break;

        case VDOREC_SETTING_RECORD_AUD_ON:
            video_preview_data.record_aud = TRUE;
            break;
    }
#else /* __VDOREC_FEATURE_RECORD_AUD__ */ 
    video_preview_data.record_aud = TRUE;
#endif /* __VDOREC_FEATURE_RECORD_AUD__ */ 


#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__
    /* multi region */
    /* layer 0 - bg region 0 */
    /* layer 1 - bg region 1 */  
    /* layer 2 - preview */
    blt_layer_falg = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
    
#ifndef __VDOREC_FEATURE_HIDE_OSD__
    /* layer 3 - osd */
    blt_layer_falg |= GDI_LAYER_ENABLE_LAYER_3;
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */
    
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_2;
   
#else /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    /* layer 0 - bg */
    /* layer 1 - preview */
    blt_layer_falg = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    
#ifndef __VDOREC_FEATURE_HIDE_OSD__
    /* layer 2 - osd */
    blt_layer_falg |= GDI_LAYER_ENABLE_LAYER_2;
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */
    
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
    
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */


    g_vdorec_cntx.last_error 
        = mdi_video_rec_preview_start(
            g_vdorec_cntx.preview_layer_handle,
            blt_layer_falg,
            preview_layer_flag,
            MMI_TRUE,
            &video_preview_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_enter_state
 * DESCRIPTION
 *  enter state
 * PARAMETERS
 *  state       [IN]        
 *  a(?)        [IN]        Next state to be entered
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_enter_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U16 prev_state;
    S32 video_width;
    S32 video_height;
    U16 prev_zoom;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flush key event */
    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
#ifdef NO_LSK
    SetKeyHandler(mmi_vdorec_lsk_press_hdlr, KEY_SEND1, KEY_EVENT_DOWN);//ghw111
    SetKeyHandler(mmi_vdorec_lsk_release_hdlr, KEY_SEND1, KEY_EVENT_UP);

#else
    SetKeyHandler(mmi_vdorec_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);

#endif

    SetKeyHandler(mmi_vdorec_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    SetKeyHandler(mmi_vdorec_inc_ev_key_press_hdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_inc_ev_key_release_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_dec_ev_key_press_hdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_dec_ev_key_release_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);

    SetKeyHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ /* normal view */
    SetKeyHandler(mmi_vdorec_inc_ev_key_press_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_inc_ev_key_release_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_dec_ev_key_press_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_dec_ev_key_release_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);

    SetKeyHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

#if !defined(__VDOREC_COLOR_IDX_FRAME__)
    SetKeyHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_VOL_UP, KEY_EVENT_UP);
#endif /* !defined(__VDOREC_COLOR_IDX_FRAME__) */ 

    /* have dedicate record key */
    SetKeyHandler(mmi_vdorec_ck_press_hdlr, VDOREC_RECORD_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_ck_release_hdlr, VDOREC_RECORD_KEY, KEY_EVENT_UP);

    SetKeyHandler(mmi_vdorec_ck_press_hdlr, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_ck_release_hdlr, KEY_0, KEY_EVENT_UP);

    if (VDOREC_RECORD_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_vdorec_ck_press_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdorec_ck_release_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_UP);
        SetKeyHandler(mmi_vdorec_null_key_event, (U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_LONG_PRESS);        
    }

    if (VDOREC_RECORD_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_vdorec_ck_press_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdorec_ck_release_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_UP);
        SetKeyHandler(mmi_vdorec_null_key_event, (U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_LONG_PRESS);                
    }

    /* hot keys */
#ifdef __VDOREC_FEATURE_EFFECT__
    if (VDOREC_EFFECT_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_effect_setting_hotkey_press, (U16)VDOREC_EFFECT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_EFFECT__ */ 

#ifdef __VDOREC_FEATURE_WB__
    if (VDOREC_WB_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_wb_hotkey_press, (U16)VDOREC_WB_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_WB__ */ 

#ifdef __VDOREC_FEATURE_NIGHT__
    if (VDOREC_NIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_night_hotkey_press, (U16)VDOREC_NIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_NIGHT__ */ 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    if (VDOREC_LED_HIGHLIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_led_highlight_hotkey_press, (U16)VDOREC_LED_HIGHLIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

#ifdef NO_LSK
    SetKeyHandler(mmi_vdorec_ck_press_hdlr,KEY_LSK, KEY_EVENT_DOWN);//ghw111
    SetKeyHandler(mmi_vdorec_ck_release_hdlr, KEY_LSK, KEY_EVENT_UP);
#endif
    switch (state)
    {
        case VDOREC_STATE_PREVIEW:
        {
            prev_state = g_vdorec_cntx.state;
            g_vdorec_cntx.state = state;

        #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
            mmi_vdorec_set_softkey(0, 0, IMG_ID_VDOREC_LSK_OPTION, IMG_ID_VDOREC_RSK_BACK, IMG_ID_VDOREC_CK_RECORD);
        #else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 
            mmi_vdorec_set_softkey(
                (PS8) GetString(STR_GLOBAL_OPTIONS),
                (PS8) GetString(STR_GLOBAL_BACK),
                IMG_ID_VDOREC_LSK_OPTION,
                IMG_ID_VDOREC_RSK_BACK,
                IMG_ID_VDOREC_CK_RECORD);
        #endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

        #ifdef __VDOREC_COLOR_IDX_FRAME__
            SetKeyHandler(mmi_vdorec_preview_change_frame_up, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdorec_preview_change_frame_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        #endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

            mmi_vdorec_draw_softkey();
            mmi_vdorec_draw_panel_state();
            mmi_vdorec_blt_screen();

            /* start preview */
            mmi_vdorec_start_preview();
            
            /* error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }

            if (prev_state == VDOREC_STATE_EXIT)
            {
                /* get zoom limit after preview start */
                mmi_vdorec_get_video_size(&video_width, &video_height);
                prev_zoom = g_vdorec_cntx.zoom_limit;
                
                g_vdorec_cntx.zoom_limit = mdi_video_rec_get_max_zoom_factor(video_width, video_height);

                /* if zoom is like 2.6x, round it to 2.0x */
                g_vdorec_cntx.zoom_limit /= 10;
                g_vdorec_cntx.zoom_limit *= 10;

                if (g_vdorec_cntx.zoom_limit < 10)
                {
                    g_vdorec_cntx.zoom_limit = 10;
                }

                if (prev_zoom != g_vdorec_cntx.zoom_limit)
                {
                    mmi_vdorec_draw_panel_zoom();
                    mmi_vdorec_blt_screen();
                }
            }
                        
        }
            break;

        case VDOREC_STATE_RECORD:
        {
            prev_state = g_vdorec_cntx.state;
            g_vdorec_cntx.state = state;

        #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
            mmi_vdorec_set_softkey(0, 0, IMG_ID_VDOREC_LSK_OPTION, IMG_ID_VDOREC_RSK_STOP, IMG_ID_VDOREC_CK_PAUSE);
        #else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 
            mmi_vdorec_set_softkey(
                (PS8) GetString(STR_GLOBAL_OPTIONS),
                (PS8) GetString(STR_ID_VDOREC_STOP),
                IMG_ID_VDOREC_LSK_OPTION,
                IMG_ID_VDOREC_RSK_STOP,
                IMG_ID_VDOREC_CK_PAUSE);
        #endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

            mmi_vdorec_draw_softkey();
            mmi_vdorec_draw_panel_state();

            mmi_vdorec_blt_screen();

            if (prev_state == VDOREC_STATE_PAUSE)
            {
                g_vdorec_cntx.last_error = mdi_video_rec_record_resume();

                /* 
                 * this may happend Meida send out record finsih message but MMI not receive it,
                 * meanwhile MMI try to pasue.
                 * MDI will ignore this meassge when some one call pause API at this situation, so
                 * MMI has to enter save screen
                 */
                if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
                {
                    mmi_vdorec_entry_save_confirm_screen();
                    return;
                }
            }
            else
            {
                if (g_vdorec_cntx.is_ext_req && g_vdorec_cntx.is_use_ext_req_path)
                {
                    mmi_fmgr_util_load_filepath(buf_filename, FMGR_PATH_ID_VIDEO);
                }
                else
                {
                    mmi_vdorec_get_save_filename(buf_filename);                    
                    mmi_fmgr_util_store_filepath(buf_filename, FMGR_PATH_ID_VIDEO);                    
                }
                g_vdorec_cntx.last_error = mdi_video_rec_record_start(buf_filename, mmi_vdorec_record_result_hdlr_callback);
            }

            /* error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }

            /* start draw timer */
            mmi_vdorec_record_timer_cyclic();
        }
            break;

        case VDOREC_STATE_PAUSE:
        {
            g_vdorec_cntx.state = state;

            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);

        #ifdef __VDOREC_COLOR_IDX_FRAME__
            SetKeyHandler(mmi_vdorec_preview_change_frame_up, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdorec_preview_change_frame_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        #endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

        #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
            mmi_vdorec_set_softkey(0, 0, IMG_ID_VDOREC_LSK_OPTION, IMG_ID_VDOREC_RSK_STOP, IMG_ID_VDOREC_CK_RESUME);
        #else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 
            mmi_vdorec_set_softkey(
                (PS8) GetString(STR_GLOBAL_OPTIONS),
                (PS8) GetString(STR_ID_VDOREC_STOP),
                IMG_ID_VDOREC_LSK_OPTION,
                IMG_ID_VDOREC_RSK_STOP,
                IMG_ID_VDOREC_CK_RESUME);
        #endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

            mmi_vdorec_draw_softkey();
            mmi_vdorec_draw_panel_state();

            mmi_vdorec_blt_screen();

            g_vdorec_cntx.last_error = mdi_video_rec_record_pause(KAL_FALSE);

            /* 
             * this may happend Meida send out record finsih message but MMI not receive it,
             * meanwhile MMI try to pasue.
             * MDI will ignore this meassge when some one call pause API at this situation, so
             * MMI has to enter save screen
             */
            if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
            {
                mmi_vdorec_entry_save_confirm_screen();
                return;
            }
            else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_INFO,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                return;
            }
            else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_SIZE_LIMIT),
                    IMG_GLOBAL_INFO,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                return;
            }

            /* pasue error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }
        }
            break;

    }

}


void Analog_tv_entry_state(U16 state)
{
	mmi_vdorec_enter_state( state);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clam_close_event_hdlr
 * DESCRIPTION
 *  handle clam close event
 * PARAMETERS
 *  ptr     [IN]        Message data ptr
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
static U8 mmi_vdorec_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event)
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
 *  mmi_vdorec_del_app_screen_hdlr
 * DESCRIPTION
 *  del app screen callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vdorec_del_app_screen_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_change_storage = FALSE;

    return FALSE;

}

int InVdorecScreen = 0 ;

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app
 * DESCRIPTION
 *  Video recoder entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* disable external reqeust flag */
#if 1
    //Huyanwei Add it 
    InVdorecScreen = 1 ;
#endif
	
    g_vdorec_cntx.is_ext_req = MMI_FALSE;
    g_vdorec_cntx.is_use_ext_req_path = MMI_FALSE;       
    
    mmi_vdorec_entry_app_internal();
}

#if defined(DOUBLE_CAMERA_SUPPORT)
extern BOOL 	mmi_main_camera_active;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_internal
 * DESCRIPTION
 *  video record app entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_app_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    U8 *guiBuffer;
    U16 cur_storage;
    S32 create_result;
    S32 wnd_width;
    S32 wnd_height;
    S32 wnd_offset_x;
    S32 wnd_offset_y;

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__    
    S32 offset_x;
    S32 offset_y;
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */


#if defined(DOUBLE_CAMERA_SUPPORT)
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanei Debug Start mmi_main_camera_active = %d\r\n",mmi_main_camera_active);
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load setting */
    mmi_vdorec_load_setting();
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

#if defined(__MMI_FTS_SUPPORT__) && defined(MT6225)
    /* MT6225 performance issue */
    if (mmi_ftp_server_is_receiving())
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_ID_VDOPLY_NOTIFY_BT_IS_WORKING),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }
#endif

#if defined(__MMI_OPP_SUPPORT__) && defined(MT6225)
    /* MT6225 performance issue */
    if (mmi_opp_is_receiving())
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_ID_VDOPLY_NOTIFY_BT_IS_WORKING),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }
#endif


#if !defined(MDI_VIDEO_MT6228_SERIES)
    /* this is used to solve MMS background send, which will cause bandwidth not enoguth */
    if(isInCall())
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_ID_VDOREC_NOTIFY_SYSTEM_TOO_BUSY),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }
#endif /* !defined(MDI_VIDEO_MT6228_SERIES) */

    /* 
     * Check if device is busy, this may happened user abort file copying, 
     * but driver is till aborting 
     */
    cur_storage = mmi_vdoply_get_storage();

    if (FS_GetDevStatus(cur_storage, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(FMGR_FS_DEVICE_BUSY_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
       return;
    }


#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    /* back to idle if clam is closed */
    if (IsClamClose())
    {
        DisplayIdleScreen();
        return;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 

#ifdef __VDOREC_FEATURE_STORAGE__
    if (g_vdorec_cntx.is_change_storage)
    {
        g_vdorec_cntx.is_direct_exit = TRUE;
        g_vdorec_cntx.is_change_storage = FALSE;
        
    #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
        /* this is used to solved Framework's history behavoir for horizontal and non-horizontal screen */
        /* 
         * HORIZONTAL- when calling mmi_vdorec_entry_set_app_storage_screen(), we will enter storage 
         *             selection screen, then SCR_ID_VDOREC_APP will be removed. Therefor, we have to insert
         *             SCR_ID_VDOREC_APP into history again.
         * NON-HORI  - when calling mmi_vdorec_entry_set_app_storage_screen(), we will enter storage 
         *             selection screen, then will enter fmgr drv selection screen, this will cause 
         *             cur_screen not SCR_ID_VDOREC_APP, so it will remove from history
         */
        EntryNewScreen(SCR_ID_VDOREC_APP, mmi_vdorec_exit_app, mmi_vdorec_entry_app_internal, MMI_FULL_SCREEN);
    #endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */
    
        mmi_vdorec_entry_set_app_storage_screen();
        return;
    }
#endif /* __VDOREC_FEATURE_STORAGE__ */

    EntryNewScreen(SCR_ID_VDOREC_APP, mmi_vdorec_exit_app, mmi_vdorec_entry_app_internal, MMI_FULL_SCREEN);
    SetDelScrnIDCallbackHandler(SCR_ID_VDOREC_APP, mmi_vdorec_del_app_screen_hdlr);

    g_vdorec_cntx.is_direct_exit = FALSE;
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    entry_full_screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_APP);

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_vdorec_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vdorec_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_CLAM, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* hook to touch screen callback */
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vdorec_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vdorec_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vdorec_touch_scr_pen_move_hdlr);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

    if (guiBuffer == NULL)
    {
        /* each time newly enter vdorec, zoom will be reset to default */
        g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
        g_vdorec_cntx.zoom_limit = VDOREC_FEAUTRE_ZOOM_LIMIT;
    }

    /* init some golbal value */
    g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
    g_vdorec_cntx.record_time = 0;
    g_vdorec_cntx.is_lsk_pressed = FALSE;
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    g_vdorec_cntx.is_ck_pressed = FALSE;
    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

    /* clear hint buffer */
    memset(g_vdorec_cntx.hint1_buf, 0, VDOREC_HINT_BUF_SIZE);
    memset(g_vdorec_cntx.hint2_buf, 0, VDOREC_HINT_BUF_SIZE);

    /* allocate storage path by using submenu's buffer */
    g_vdorec_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);

    /* check if path is valid or not. if not will pop up a screen after the preview screen is shown */
    cur_storage = mmi_vdoply_get_storage();

    /* if no error. load path into buffer */
    mmi_vdoply_get_storage_file_path((PS8) g_vdorec_cntx.storage_filepath);
    create_result = mmi_vdoply_create_file_dir((PS8) g_vdorec_cntx.storage_filepath);

   /*******************************************************************
   * Init proper global state for video applcation  
   ********************************************************************/
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* enable multi_layer */
    gdi_layer_multi_layer_enable();

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* disalbe align timer */
    UI_disable_alignment_timers();

    /* stop LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_GET);

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

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* use medium font */
    gui_set_font(&MMI_medium_font);

    g_vdorec_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();


#ifdef __MMI_TVOUT__
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
#endif /* __MMI_TVOUT__ */


   /***************************************************************************** 
   * Create layers 
   *****************************************************************************/
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

   /************ base layer layer ************/
    gdi_layer_get_base_handle(&g_vdorec_cntx.bg_layer_handle);

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    g_vdorec_cntx.lcd_width = UI_device_height;
    g_vdorec_cntx.lcd_height = UI_device_width;

    gdi_layer_resize(g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    g_vdorec_cntx.lcd_width = UI_device_width;
    g_vdorec_cntx.lcd_height = UI_device_height;

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_set_self_rotation_flag(MMI_FRM_SCREEN_ROTATE_270);
#endif 

      /************ preview window layer ************/

    /* create at 0,0, then move to correct position after rotate */
    wnd_width = g_vdorec_osd_cntx.preview_wnd.rect.width;
    wnd_height = g_vdorec_osd_cntx.preview_wnd.rect.height;
    wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;

    gdi_layer_create(
        0,
        0,
        wnd_width,
        wnd_height,
        &g_vdorec_cntx.preview_layer_handle);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#else 
    gdi_layer_clear(GDI_COLOR_BLACK);
#endif 

    gdi_layer_set_position(wnd_offset_x, wnd_offset_y);


#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    /************ preview window layer ************/
    wnd_width = g_vdorec_osd_cntx.preview_wnd.rect.width;
    wnd_height = g_vdorec_osd_cntx.preview_wnd.rect.height;
    wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;

    gdi_layer_create(
        wnd_offset_x,
        wnd_offset_y,
        wnd_width,
        wnd_height,
        &g_vdorec_cntx.preview_layer_handle);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#else 
    gdi_layer_clear(GDI_COLOR_BLACK);
#endif 

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    gdi_layer_pop_and_restore_active();

    /* resized preview layer */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    mmi_vdorec_resize_preview_layer();
#endif 

#ifdef __VDOREC_COLOR_IDX_FRAME__
/************ overlay frame ************/
    /* create overlay frame buffer */
    g_vdorec_cntx.overlay_frame_buf_ptr = mmi_frm_scrmem_alloc(VDOREC_OVERLAY_FRAME_BUFFER_SIZE);
    ASSERT(g_vdorec_cntx.overlay_frame_buf_ptr != NULL);

    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_vdorec_cntx.overlay_frame_layer_handle,
        (PU8) g_vdorec_cntx.overlay_frame_buf_ptr,
        (S32) VDOREC_OVERLAY_FRAME_BUFFER_SIZE);
    gdi_layer_push_and_set_active(g_vdorec_cntx.overlay_frame_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /* update frame */
    if (g_vdorec_cntx.setting.color_idx_frame != VDOREC_SETTING_COLOR_IDX_FRAME_OFF)
    {
        mmi_vdorec_draw_color_idx_frame();
    }

#endif /* __VDOREC_COLOR_IDX_FRAME__ */ /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */


#ifndef __VDOREC_FEATURE_HIDE_OSD__
   /************ osd layer ************/
    /* create a double layer frame from outside memory */
    g_vdorec_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc(VDOREC_OSD_BUFFER_SIZE);

    gdi_layer_create_double_using_outside_memory(
        0, 
        0, 
        g_vdorec_cntx.lcd_width, 
        g_vdorec_cntx.lcd_height, 
        &g_vdorec_cntx.osd_layer_handle, 
        (PU8)g_vdorec_cntx.osd_layer_buf_ptr, 
        (S32)VDOREC_OSD_BUFFER_SIZE);        /* this buffer is double buffer size */

    gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);

    /* clear both layer */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    gdi_layer_toggle_double();

    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#else /* __VDOREC_FEATURE_HIDE_OSD__ */
    g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */


   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
    mmi_frm_block_general_interrupt_event(
        MMI_FRM_INT_CHARGER | 
        MMI_FRM_INT_USB_CHARGER |
        MMI_FRM_INT_SMS | 
        MMI_FRM_INT_FMGR_CARD | 
        MMI_FRM_INT_WAP_MMS | 
        MMI_FRM_INT_BT_TASK);

   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
    mmi_vdorec_init_ui();

    gdi_layer_reset_clip(); /* use full screen clip */
    gui_reset_text_clip();  /* use full screen text clip */

    gdi_layer_lock_frame_buffer();

    /* bg image */

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__    
    /* newer cip has layer bg color, we can split bg into smaller region for better performance */
    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_region_0_layer_handle);
    gdi_layer_get_position(&offset_x, &offset_y);
    gdi_image_draw_id(-offset_x, -offset_y, IMG_ID_VDOREC_OSD_BG);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_region_1_layer_handle);
    gdi_layer_get_position(&offset_x, &offset_y);
    gdi_image_draw_id(-offset_x, -offset_y, IMG_ID_VDOREC_OSD_BG);
    gdi_layer_pop_and_restore_active();

#ifndef __VDOREC_FEATURE_HIDE_TIMER__
    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);
    gdi_image_draw_id(
        (-offset_x) + g_vdorec_osd_cntx.panel.timer_bg.offset_x,
        (-offset_y) + g_vdorec_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOREC_OSD_TIMER_BG);
    gdi_layer_pop_and_restore_active();    
#endif /* __VDOREC_FEATURE_HIDE_TIMER__ */
    
#else /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    /* MT6219 dont have bg color - we need use bg layer as lcd size */   
    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_layer_handle);
    gdi_image_draw_id(0, 0, IMG_ID_VDOREC_OSD_BG);

#ifndef __VDOREC_FEATURE_HIDE_TIMER__
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.timer_bg.offset_x,
        g_vdorec_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOREC_OSD_TIMER_BG);
#endif /* __VDOREC_FEATURE_HIDE_TIMER__ */

    gdi_layer_pop_and_restore_active();
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */

#if 1
    //Huyanwei Add it 
    InVdorecScreen = 1 ;
#endif

    mmi_vdorec_draw_panel_state();
    mmi_vdorec_draw_title();
    mmi_vdorec_draw_panel();
    mmi_vdorec_draw_osd();

    mmi_vdorec_set_softkey(
        (PS8) GetString(STR_GLOBAL_OPTIONS),
        (PS8) GetString(STR_GLOBAL_BACK),
        IMG_ID_VDOREC_LSK_OPTION,
        IMG_ID_VDOREC_RSK_BACK,
        IMG_ID_VDOREC_CK_RECORD);

    mmi_vdorec_draw_softkey();

    gdi_layer_unlock_frame_buffer();

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__
    gdi_layer_set_blt_layer(
        g_vdorec_cntx.bg_region_0_layer_handle,
        g_vdorec_cntx.bg_region_1_layer_handle,
        g_vdorec_cntx.preview_layer_handle,
        g_vdorec_cntx.osd_layer_handle);
#else /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    gdi_layer_set_blt_layer(
        g_vdorec_cntx.bg_layer_handle,
        g_vdorec_cntx.preview_layer_handle,
        g_vdorec_cntx.osd_layer_handle,
        0);    
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */

    mmi_vdorec_blt_screen();

    /* this function is entry by small screen's history draw, no need to open file */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    /* check if storage exist or not */
    if (create_result != FS_NO_ERROR)
    {
        if (create_result == FS_WRITE_PROTECTION)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_WRITE_PROTECTION),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }
        else if (create_result == FS_FAT_ALLOC_ERROR)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_FAT_ALLOC_ERROR_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);            
        }
        else
        {
            /* storage not exist */            
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }

        /* 
         * Storage has error, set this flag and re-enter app screen, 
         * will launch storage selection screen 
         */
        g_vdorec_cntx.is_change_storage = TRUE;

    #ifndef __VDOREC_FEATURE_STORAGE__        
        /* if no storage to change, will leave app */
        DeleteNHistory(1);

        if (g_vdorec_cntx.is_ext_req)
        {
            g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);    
            g_vdorec_cntx.ext_req_callback = NULL;
        }
    #endif /* __VDOREC_FEATURE_STORAGE__ */
        return;

    }

    /* power on HW */
    if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_SUCCEED)
    {
        g_vdorec_cntx.last_error = mdi_video_rec_power_on();
    }

    if (mmi_vdorec_check_and_display_error_popup() != TRUE) /* !TRUE means error popup displayed */
    {
        /* 
         * if record finish has popup, it will not entry saving directly, 
         * after popup gone, we have to enter saving procedure 
         */

        /* ask media if there is a unsaved file */
        mmi_vdoply_get_storage_file_path(buf_filepath);

        if (g_vdorec_cntx.is_ext_req && guiBuffer == NULL)
        {
            /* delete unsaved file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);
            
            mmi_vdorec_enter_state(VDOREC_STATE_PREVIEW);
            mmi_vdorec_turn_on_led_highlight();
        }
        else
        {
            if (mdi_video_rec_has_unsaved_file(buf_filepath) == TRUE)
            {
                mmi_vdorec_entry_save_confirm_screen();
                return;
            }
            else
            {
                mmi_vdorec_enter_state(VDOREC_STATE_PREVIEW);
                mmi_vdorec_turn_on_led_highlight();
            }
        }

    }
}


#if defined(DOUBLE_CAMERA_SUPPORT)
// Huyanwei Modify It 
extern BOOL mmi_main_camera_active;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_app
 * DESCRIPTION
 *  video recorder ext function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.is_direct_exit)
    {
        /* 
         * when enter app and we found that we need to change storage, we will show 
         * change strage screen directly, so we dont need execute this exit function 
         */
        return;
    }
    
    if (g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
    }

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    mmi_vdorec_store_setting();

    mdi_video_rec_power_off();

    mmi_vdorec_turn_off_led_highlight();

    /* cancel active timer */
    gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
    gui_cancel_timer(mmi_vdorec_hide_hint);

#ifdef __VDOREC_FEATURE_ZOOM__
    gui_cancel_timer(mmi_vdorec_zoom_in);
    gui_cancel_timer(mmi_vdorec_zoom_out);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

    gui_cancel_timer(mmi_vdorec_inc_ev);
    gui_cancel_timer(mmi_vdorec_dec_ev);

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__
    gdi_layer_flatten_to_base(
        g_vdorec_cntx.bg_region_0_layer_handle,
        g_vdorec_cntx.bg_region_1_layer_handle,
        g_vdorec_cntx.preview_layer_handle,
        g_vdorec_cntx.osd_layer_handle);
#else /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    gdi_layer_flatten_to_base(
        g_vdorec_cntx.bg_layer_handle,
        g_vdorec_cntx.preview_layer_handle,
        g_vdorec_cntx.osd_layer_handle,
        0);    
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */


    /* free bg layer */
#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__    
    /* bg - we use base layer's buffer, we dont need to free the buffer */
    gdi_layer_free(g_vdorec_cntx.bg_region_0_layer_handle);
    gdi_layer_free(g_vdorec_cntx.bg_region_1_layer_handle);    

    g_vdorec_cntx.bg_region_0_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdorec_cntx.bg_region_1_layer_handle = GDI_LAYER_EMPTY_HANDLE;    
    
#else /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    g_vdorec_cntx.bg_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */

    /* free preview layers */
    gdi_layer_free(g_vdorec_cntx.preview_layer_handle);
    g_vdorec_cntx.preview_layer_handle = 0;

#ifndef __VDOREC_FEATURE_HIDE_OSD__
    /* free osd layer - osd layer using screen memeory, free it also*/
    gdi_layer_free(g_vdorec_cntx.osd_layer_handle);
    g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    mmi_frm_scrmem_free((void*)g_vdorec_cntx.osd_layer_buf_ptr);
    g_vdorec_cntx.osd_layer_buf_ptr = NULL;
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */

#ifdef __VDOREC_COLOR_IDX_FRAME__
    /* free color idx frame layer */
    gdi_layer_free(g_vdorec_cntx.overlay_frame_layer_handle);
    g_vdorec_cntx.overlay_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    mmi_frm_scrmem_free((void*)g_vdorec_cntx.overlay_frame_buf_ptr);
    g_vdorec_cntx.overlay_frame_buf_ptr = NULL;
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    /* restore base layer rotation */

    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

    gdi_layer_resize(UI_device_width, UI_device_height);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    /* clear in black layer if it is horizontal view */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /* restore rotate layer flag */
    gdi_lcd_set_rotate_by_layer(g_vdorec_cntx.prev_rotate_by_layer);

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LED patten */
    GpioCtrlReq(MMIAPI_DEV_CTRL_RELEASE);

    /* let MMI can sleep */
    TurnOffBacklight();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* free buffer */
    gui_free(g_vdorec_cntx.storage_filepath);
    g_vdorec_cntx.storage_filepath = NULL;

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    /* exit app screen if exist , and not exit because toggle self capture to sublcd */
    if (g_vdorec_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_vdorec_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK | MMI_FRM_INT_GPIO);

#if 1
    //Huyanwei Add It 
    InVdorecScreen = 0 ;
#endif
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_sublcd_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_draw_sublcd_icon(void)
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

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_VDOREC_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id((lcd_width - image_width) >> 1, (lcd_height - image_height) >> 1, IMG_ID_VDOREC_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_vdorec_exit_sublcd_screen);

    /* draw a icon on sub */
    mmi_vdorec_draw_sublcd_icon();

    g_vdorec_cntx.is_sub_display = TRUE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_exit_sublcd_screen(void)
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

    if (g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
    }

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    /* exit sub */
    g_vdorec_cntx.is_sub_display = FALSE;

    SubLCDHistory.entryFuncPtr = mmi_vdorec_entry_sublcd_screen;
    AddSubLCDHistory(&SubLCDHistory);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_record_timer_cyclic
 * DESCRIPTION
 *  record timer cyclic to get and draw timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_record_timer_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 prev_time_in_sec;
    U32 time_in_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_time_in_sec = (U32) (g_vdorec_cntx.record_time / 1000);

    mdi_video_rec_get_cur_record_time(&g_vdorec_cntx.record_time);
    time_in_sec = (U32) (g_vdorec_cntx.record_time / 1000);

    /* time limit check */
#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    switch (g_vdorec_cntx.setting.time_limit)
    {
        case VDOREC_SETTING_TIME_LIMIT_1:
            if (time_in_sec > VDOREC_FEATURE_TIME_LIMIT_1)
            {
                mdi_video_rec_record_stop();

                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_TIME_LIMIT),
                    IMG_GLOBAL_INFO,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                return;
            }
            break;

        case VDOREC_SETTING_TIME_LIMIT_2:
            if (time_in_sec > VDOREC_FEATURE_TIME_LIMIT_2)
            {
                mdi_video_rec_record_stop();

                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_TIME_LIMIT),
                    IMG_GLOBAL_INFO,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                return;
            }
            break;

        case VDOREC_SETTING_TIME_LIMIT_3:
            if (time_in_sec > VDOREC_FEATURE_TIME_LIMIT_3)
            {
                mdi_video_rec_record_stop();

                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_TIME_LIMIT),
                    IMG_GLOBAL_INFO,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                return;
            }
            break;
    }
#endif /* __VDOREC_FEATURE_TIME_LIMIT__ */ 

    if ((time_in_sec > prev_time_in_sec) || (prev_time_in_sec == 0))
    {
        mmi_vdorec_draw_panel_timer();
        mmi_vdorec_blt_screen();
    }

    gui_start_timer(200, mmi_vdorec_record_timer_cyclic);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_title
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    PS8 str_ptr;

    video_rect_struct *bbox_rect_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display filename */
    if (g_vdorec_osd_cntx.title.is_draw_app_name)
    {
        gdi_layer_push_and_set_active(g_vdorec_cntx.title_draw_layer);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
        bbox_rect_p = &g_vdorec_osd_cntx.title.rect;

        gui_set_text_clip(
            bbox_rect_p->offset_x - layer_offset_x,
            bbox_rect_p->offset_y - layer_offset_y,
            bbox_rect_p->offset_x + bbox_rect_p->width - layer_offset_x - 1,
            bbox_rect_p->offset_y + bbox_rect_p->height - layer_offset_y - 1);

        str_ptr = (PS8) GetString(STR_ID_VDOREC_APP_NAME);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_vdorec_osd_cntx.title.v_align == VIDEO_ALIGN_TOP)
        {
            offset_y = 0;
        }
        else if (g_vdorec_osd_cntx.title.v_align == VIDEO_ALIGN_BOTTOM)
        {
            offset_y = bbox_rect_p->height - str_height;
        }
        else    /* center */
        {
            offset_y = (bbox_rect_p->height - str_height) >> 1;
        }

        offset_y += bbox_rect_p->offset_y;

        if (g_vdorec_osd_cntx.title.h_align == VIDEO_ALIGN_LEFT)
        {
            offset_x = 0;
        }
        else if (g_vdorec_osd_cntx.title.h_align == VIDEO_ALIGN_RIGHT)
        {
            offset_x = bbox_rect_p->width - str_width;
        }
        else
        {
            offset_x = (bbox_rect_p->width - str_width) >> 1;
        }

        offset_x += bbox_rect_p->offset_x;

        mmi_vdorec_draw_style_text(
            str_ptr, 
            offset_x - layer_offset_x, 
            offset_y - layer_offset_y, 
            &g_vdorec_osd_cntx.title.style_text);

        gui_reset_text_clip();  /* restore clip to full screen */

        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_status
 * DESCRIPTION
 *  draw video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_HIDE_OSD__
static void mmi_vdorec_draw_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_osd_vdorec_status_struct *status_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdorec_osd_cntx.status.is_show)
    {
        return;
    }

    status_p = &g_vdorec_osd_cntx.status;

   /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                     \
   do {                                                                                        \
      if(status_p->##a##.is_show)                                                              \
      {                                                                                        \
         gdi_image_draw_id(status_p->##a##.offset_x+status_p->rect.offset_x,                   \
                           status_p->##a##.offset_y+status_p->rect.offset_y,                   \
                           (U16)(IMG_ID_VDOREC_OSD_##A##_START+g_vdorec_cntx.setting.##a##+1));\
      }                                                                                        \
   } while(0);

#ifdef __VDOREC_FEATURE_NIGHT__
    DRAW_OSD_ICON(night, NIGHT);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    DRAW_OSD_ICON(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    DRAW_OSD_ICON(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    DRAW_OSD_ICON(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    DRAW_OSD_ICON(time_limit, TIME_LIMIT);
#endif 
}
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_softkey
 * DESCRIPTION
 *  draw softkey bar (softkey)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_softkey(void)
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

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();

#ifndef __VDOREC_FEATURE_HORIZONTAL_VIEW__

    gdi_layer_push_and_set_active(g_vdorec_cntx.lsk_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_draw_id(
        g_vdorec_osd_cntx.softkey.rect.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.softkey.rect.offset_y - layer_offset_y,
        IMG_ID_VDOREC_OSD_BUTTOM_BAR_BG);
        
    gdi_layer_pop_and_restore_active();        
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    if (g_vdorec_osd_cntx.softkey.is_lsk_icon == FALSE)
    {
        /* lsk string */
        if (g_vdorec_cntx.lsk_str_ptr != NULL)
        {
            wgui_softkey_get_offset((UI_string_type)g_vdorec_cntx.lsk_str_ptr, &lsk_offset_x, &lsk_offset_y, MMI_LEFT_SOFTKEY);
            gui_measure_string((UI_string_type) g_vdorec_cntx.lsk_str_ptr, &str_width, &str_height);

            if (r2lMMIFlag)
            {
                lsk_offset_x -= str_width;
            }

            if (g_vdorec_cntx.is_lsk_pressed)
            {
                lsk_offset_x++;
                lsk_offset_y++;
            }

            gdi_layer_push_and_set_active(g_vdorec_cntx.lsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

            mmi_vdorec_draw_style_text(
                g_vdorec_cntx.lsk_str_ptr,
                lsk_offset_x - layer_offset_x,
                lsk_offset_y - layer_offset_y,
                &g_vdorec_osd_cntx.softkey.lsk_text);

            gdi_layer_pop_and_restore_active();

        #ifdef __VDOREC_FEATURE_TOUCH_SCREEN__

            touch_p = &g_vdorec_cntx.touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;

        #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
        }
    }
    else
    {
        /* lsk icon */
        if (g_vdorec_cntx.lsk_img_id != 0)
        {
            if (g_vdorec_cntx.is_lsk_pressed)
            {
                image_id = g_vdorec_cntx.lsk_img_id + 1;
            }
            else
            {
                image_id = g_vdorec_cntx.lsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            lsk_offset_x = g_vdorec_osd_cntx.softkey.icon_lsk_pos.offset_x;
            lsk_offset_y = g_vdorec_osd_cntx.softkey.icon_lsk_pos.offset_y;

            gdi_layer_push_and_set_active(g_vdorec_cntx.lsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

            gdi_image_draw_id(
                lsk_offset_x - layer_offset_x, 
                lsk_offset_y - layer_offset_y, 
                image_id);

            gdi_layer_pop_and_restore_active();
        #ifdef __VDOREC_FEATURE_TOUCH_SCREEN__

            touch_p = &g_vdorec_cntx.touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;

        #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
        }

    }

    if (g_vdorec_osd_cntx.softkey.is_rsk_icon == FALSE)
    {
        /* rsk string */
        if (g_vdorec_cntx.rsk_str_ptr != NULL)
        {
            wgui_softkey_get_offset((UI_string_type)g_vdorec_cntx.rsk_str_ptr, &rsk_offset_x, &rsk_offset_y, MMI_RIGHT_SOFTKEY);
            gui_measure_string((UI_string_type) g_vdorec_cntx.rsk_str_ptr, &str_width, &str_height);

            if (r2lMMIFlag)
            {
                rsk_offset_x -= str_width;
            }

            if (g_vdorec_cntx.is_rsk_pressed)
            {
                rsk_offset_x++;
                rsk_offset_y++;
            }

            gdi_layer_push_and_set_active(g_vdorec_cntx.rsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

            mmi_vdorec_draw_style_text(
                g_vdorec_cntx.rsk_str_ptr,
                rsk_offset_x - layer_offset_x,
                rsk_offset_y - layer_offset_y,
                &g_vdorec_osd_cntx.softkey.lsk_text);

            gdi_layer_pop_and_restore_active();

        #ifdef __VDOREC_FEATURE_TOUCH_SCREEN__

            touch_p = &g_vdorec_cntx.touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;

        #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
        }
    }
    else
    {
        /* rsk icon */
        if (g_vdorec_cntx.rsk_img_id != 0)
        {
            if (g_vdorec_cntx.is_rsk_pressed)
            {
                image_id = g_vdorec_cntx.rsk_img_id + 1;
            }
            else
            {
                image_id = g_vdorec_cntx.rsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            rsk_offset_x = g_vdorec_osd_cntx.softkey.icon_rsk_pos.offset_x;
            rsk_offset_y = g_vdorec_osd_cntx.softkey.icon_rsk_pos.offset_y;

            gdi_layer_push_and_set_active(g_vdorec_cntx.rsk_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

            gdi_image_draw_id(
                rsk_offset_x - layer_offset_x, 
                rsk_offset_y - layer_offset_y, 
                image_id);

             gdi_layer_pop_and_restore_active();
             
        #ifdef __VDOREC_FEATURE_TOUCH_SCREEN__

            touch_p = &g_vdorec_cntx.touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;

        #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
        }

    }

    if (g_vdorec_osd_cntx.softkey.is_ck_icon)
    {

        /* draw c key */

        if (g_vdorec_cntx.ck_img_id != 0)
        {
            if (g_vdorec_cntx.is_ck_pressed)
            {
                image_id = g_vdorec_cntx.ck_img_id + 1;
            }
            else
            {
                image_id = g_vdorec_cntx.ck_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            ck_offset_x = g_vdorec_osd_cntx.softkey.icon_ck_pos.offset_x;
            ck_offset_y = g_vdorec_osd_cntx.softkey.icon_ck_pos.offset_y;


            gdi_layer_push_and_set_active(g_vdorec_cntx.ck_draw_layer);
            gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

            gdi_image_draw_id(
                ck_offset_x - layer_offset_x, 
                ck_offset_y- layer_offset_y, 
                image_id);
                
            gdi_layer_pop_and_restore_active();
            
        #ifdef __VDOREC_FEATURE_TOUCH_SCREEN__

            touch_p = &g_vdorec_cntx.touch_ck;
            touch_p->offset_x = ck_offset_x;
            touch_p->offset_y = ck_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;

        #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ /* __VDOPLY_FEATURE_TOUCH_SCREEN__ */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_softkey
 * DESCRIPTION
 *  Set softkey string ptr that will be draw
 * PARAMETERS
 *  lsk_str_ptr     [IN]        Lsk string pointer
 *  rsk_str_ptr     [IN]        Rsk string pointer
 *  lsk_img_id      [IN]        Lsk image id
 *  rsk_img_id      [IN]        Rsk image id
 *  ck_img_id       [IN]        Ck_image id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.lsk_str_ptr = lsk_str_ptr;
    g_vdorec_cntx.rsk_str_ptr = rsk_str_ptr;

    g_vdorec_cntx.lsk_img_id = lsk_img_id;
    g_vdorec_cntx.rsk_img_id = rsk_img_id;
    g_vdorec_cntx.ck_img_id = ck_img_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_state
 * DESCRIPTION
 *  draw panel state (stop, pause, record)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.state_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_EXIT:
        case VDOREC_STATE_PREVIEW:
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.state.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.state.offset_y - layer_offset_y,
                (U16) (IMG_ID_VDOREC_OSD_STATE_STOP));
        }
            break;

        case VDOREC_STATE_RECORD:
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.state.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.state.offset_y - layer_offset_y,
                (U16) (IMG_ID_VDOREC_OSD_STATE_REC));
        }
            break;

        case VDOREC_STATE_PAUSE:
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.state.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.state.offset_y - layer_offset_y,
                (U16) (IMG_ID_VDOREC_OSD_STATE_PAUSE));
        }
            break;
    }

    gdi_layer_pop_and_restore_active();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_ev
 * DESCRIPTION
 *  draw panel ev
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_draw_panel_ev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.ev_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.ev.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.ev.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_EV_START + g_vdorec_cntx.setting.ev + 1));

    /* ev inc */
    if ((g_vdorec_cntx.touch_ev_inc.is_press) || (g_vdorec_cntx.is_ev_inc_key_pressed))
    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_EV_INC_SEL);
    }
    else
    {

        if (g_vdorec_cntx.setting.ev < VDOREC_SETTING_EV_COUNT - 1)
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_INC);

        }
        else
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_INC_DIS);

        }
    }

    /* ev dec */
    if ((g_vdorec_cntx.touch_ev_dec.is_press) || (g_vdorec_cntx.is_ev_dec_key_pressed))

    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_SEL);
    }
    else
    {
        if (g_vdorec_cntx.setting.ev > 0)
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_DIS);
        }
    }

    gdi_layer_pop_and_restore_active();
}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_zoom
 * DESCRIPTION
 *  draw panel zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_draw_panel_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.zoom_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    /* zooming icon */
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y,
        mmi_vdorec_get_zoom_image());

    /* zoom inc */
    if ((g_vdorec_cntx.touch_zoom_inc.is_press) || (g_vdorec_cntx.is_zoom_in_key_pressed))
    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL);
    }
    else
    {
    #ifdef ISP_SUPPORT
        if (mmi_vdorec_get_zoom_factor() != g_vdorec_cntx.zoom_limit)
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS);
        }

    #else /* ISP_SUPPORT */ 
        if (g_vdorec_cntx.setting.zoom < VDOREC_FEATURE_ZOOM_COUNT - 1)
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC);

        }
        else
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS);

        }
    #endif /* ISP_SUPPORT */ 

    }

    /* zoom dec */
    if ((g_vdorec_cntx.touch_zoom_dec.is_press) || (g_vdorec_cntx.is_zoom_out_key_pressed))

    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL);
    }
    else
    {
        if (g_vdorec_cntx.setting.zoom > 0)
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC);
        }
        else
        {
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS);
        }
    }

    gdi_layer_pop_and_restore_active();

}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_timer
 * DESCRIPTION
 *  draw panel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    U32 rec_time;
    S32 layer_offset_x;
    S32 layer_offset_y;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.state_draw_layer);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
   
    rec_time = (U32) (g_vdorec_cntx.record_time / 1000);

   /******** draw timer *********/
    hour = rec_time / 3600;
    hour_remain = rec_time % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

	/*shaokai add it start.090901*/
	/*hide last timer*/
	gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.timer_bg.offset_x,
        g_vdorec_osd_cntx.panel.timer_bg.offset_y,
        IMG_ID_VDOREC_OSD_TIMER_BG);
	/*shaokai add it end.090901*/
    /* hr */
    gdi_image_draw_id(
        g_vdorec_cntx.timer.hr_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) hour / 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.hr_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) hour % 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.col_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_COL));

    /* min */
    gdi_image_draw_id(
        g_vdorec_cntx.timer.min_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) min / 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.min_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) min % 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.col_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_COL));

    /* sec */
    gdi_image_draw_id(
        g_vdorec_cntx.timer.sec_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) sec / 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.sec_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) sec % 10));

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel
 * DESCRIPTION
 *  draw panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdorec_draw_panel_state();
    mmi_vdorec_draw_panel_ev();

#ifdef __VDOREC_FEATURE_ZOOM__
    mmi_vdorec_draw_panel_zoom();
#endif 

    mmi_vdorec_draw_panel_timer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_ui
 * DESCRIPTION
 *  init panel (timer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_init_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digit_width;
    S32 col_width;
    S32 height;

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__        
    PU8 buf_ptr;
    S32 region_0_buf_size;
    S32 region_1_buf_size;    
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    video_rect_struct *rect_ptr;
    video_osd_vodrec_panel_struct *panel_ptr;    
    video_osd_softkey_struct *sk_ptr;    
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__    
    /* bg */
    /* newer cip has layer bg color, we can split bg into smaller region for better performance */
    /* we will use base layer's buffer to create two smaller layer region */

    /* region 0 */
    gdi_layer_get_buffer_ptr(&buf_ptr);
    rect_ptr = &g_vdorec_osd_cntx.bg.region_0;

    region_0_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;

    gdi_layer_create_using_outside_memory(
        rect_ptr->offset_x,
        rect_ptr->offset_y,
        rect_ptr->width,        
        rect_ptr->height,        
        &g_vdorec_cntx.bg_region_0_layer_handle,   
        (PU8)buf_ptr,
        (S32)region_0_buf_size);

    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_region_0_layer_handle);       
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    /* region 1 */
    rect_ptr = &g_vdorec_osd_cntx.bg.region_1;    
    buf_ptr += region_0_buf_size;

    region_1_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;

    gdi_layer_create_using_outside_memory(
        rect_ptr->offset_x,
        rect_ptr->offset_y,
        rect_ptr->width,        
        rect_ptr->height,        
        &g_vdorec_cntx.bg_region_1_layer_handle,   
        (PU8)buf_ptr,
        (S32)region_1_buf_size);

    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_region_1_layer_handle);       
    gdi_layer_set_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

#else /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */
    /* MT6219 dont have bg color - we need use bg layer as lcd size */   
    gdi_layer_get_base_handle(&g_vdorec_cntx.bg_layer_handle);
#endif /* __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ */



#define ASSIGN_DRAW_LAYER(__offset_x__, __offset_y__, __draw_layer__)       \
do {                                                                        \
    video_rect_struct *rect_0_ptr;                                          \
    video_rect_struct *rect_1_ptr;                                          \
    __draw_layer__ = GDI_LAYER_EMPTY_HANDLE;                                \
    rect_0_ptr = &g_vdorec_osd_cntx.bg.region_0;                            \
    rect_1_ptr = &g_vdorec_osd_cntx.bg.region_1;                            \
    if ((__offset_x__ >= rect_0_ptr->offset_x) &&                           \
        (__offset_x__ <= rect_0_ptr->offset_x+rect_0_ptr->width) &&         \
        (__offset_y__ >= rect_0_ptr->offset_y) &&                           \
        (__offset_y__ <= rect_0_ptr->offset_y+rect_0_ptr->height))          \
    {                                                                       \
        __draw_layer__ = g_vdorec_cntx.bg_region_0_layer_handle;            \
    }                                                                       \
    else if ((__offset_x__ >= rect_1_ptr->offset_x) &&                      \
             (__offset_x__ <= rect_1_ptr->offset_x+rect_1_ptr->width) &&    \
             (__offset_y__ >= rect_1_ptr->offset_y) &&                      \
             (__offset_y__ <= rect_1_ptr->offset_y+rect_1_ptr->height))     \
    {                                                                       \
        __draw_layer__ = g_vdorec_cntx.bg_region_1_layer_handle;            \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        /* object not within any region */                                  \
        MMI_ASSERT(0);                                                      \
    }                                                                       \
} while(0);

    
    /* timer */
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_TIMER_COL, &col_width, &height);
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_TIMER_0, &digit_width, &height);

    g_vdorec_cntx.timer.offset_y = g_vdorec_osd_cntx.panel.timer.offset_y;

    g_vdorec_cntx.timer.hr_0_offset_x = g_vdorec_osd_cntx.panel.timer.offset_x;
    g_vdorec_cntx.timer.hr_1_offset_x = g_vdorec_cntx.timer.hr_0_offset_x + digit_width;
    g_vdorec_cntx.timer.col_0_offset_x = g_vdorec_cntx.timer.hr_1_offset_x + digit_width;
    g_vdorec_cntx.timer.min_0_offset_x = g_vdorec_cntx.timer.col_0_offset_x + col_width;
    g_vdorec_cntx.timer.min_1_offset_x = g_vdorec_cntx.timer.min_0_offset_x + digit_width;
    g_vdorec_cntx.timer.col_1_offset_x = g_vdorec_cntx.timer.min_1_offset_x + digit_width;
    g_vdorec_cntx.timer.sec_0_offset_x = g_vdorec_cntx.timer.col_1_offset_x + col_width;
    g_vdorec_cntx.timer.sec_1_offset_x = g_vdorec_cntx.timer.sec_0_offset_x + digit_width;

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;

    /* init touch region */

    /* ev inc */
    touch_p = &g_vdorec_cntx.touch_ev_inc;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.ev_inc.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.ev_inc.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC, &touch_p->width, &touch_p->height);

    /* ev dec */
    touch_p = &g_vdorec_cntx.touch_ev_dec;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.ev_dec.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.ev_dec.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC, &touch_p->width, &touch_p->height);

    /* zoom inc */
    touch_p = &g_vdorec_cntx.touch_zoom_inc;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom_inc.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom_inc.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC, &touch_p->width, &touch_p->height);

    /* zoom dec */
    touch_p = &g_vdorec_cntx.touch_zoom_dec;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom_dec.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom_dec.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC, &touch_p->width, &touch_p->height);

#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_BG__ 
    panel_ptr = &g_vdorec_osd_cntx.panel;
    ASSIGN_DRAW_LAYER(panel_ptr->ev.offset_x, panel_ptr->ev.offset_y, g_vdorec_cntx.ev_draw_layer);
    ASSIGN_DRAW_LAYER(panel_ptr->zoom.offset_x, panel_ptr->zoom.offset_y, g_vdorec_cntx.zoom_draw_layer);    
    ASSIGN_DRAW_LAYER(panel_ptr->timer.offset_x, panel_ptr->timer.offset_y, g_vdorec_cntx.timer_draw_layer);
    ASSIGN_DRAW_LAYER(panel_ptr->state.offset_x, panel_ptr->state.offset_y, g_vdorec_cntx.state_draw_layer);

    sk_ptr = &g_vdorec_osd_cntx.softkey;
    ASSIGN_DRAW_LAYER(sk_ptr->icon_ck_pos.offset_x, sk_ptr->icon_ck_pos.offset_y, g_vdorec_cntx.ck_draw_layer); 

    if (sk_ptr->is_lsk_icon)
    {
        ASSIGN_DRAW_LAYER(sk_ptr->icon_lsk_pos.offset_x, sk_ptr->icon_lsk_pos.offset_y, g_vdorec_cntx.lsk_draw_layer);        
    }
    else
    {
        gui_measure_string((UI_string_type)L"Test", &str_width, &str_height);    
        offset_x = 2;
        offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 1;
        ASSIGN_DRAW_LAYER(offset_x, offset_y, g_vdorec_cntx.lsk_draw_layer);        
    }

    if (sk_ptr->is_rsk_icon)
    {
        ASSIGN_DRAW_LAYER(sk_ptr->icon_rsk_pos.offset_x, sk_ptr->icon_rsk_pos.offset_y, g_vdorec_cntx.rsk_draw_layer);        
    }
    else
    {
        gui_measure_string((UI_string_type)L"Test", &str_width, &str_height);    
        offset_x = UI_device_width - str_width - 2;
        offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 1;
        ASSIGN_DRAW_LAYER(offset_x, offset_y, g_vdorec_cntx.rsk_draw_layer);        
    }

    if (g_vdorec_osd_cntx.title.is_draw_app_name)
    {       
        ASSIGN_DRAW_LAYER(
            g_vdorec_osd_cntx.title.rect.offset_x,\
            g_vdorec_osd_cntx.title.rect.offset_y,\
            g_vdorec_cntx.title_draw_layer);
    }
                              
#else /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_OSD__ */
    g_vdorec_cntx.ev_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.zoom_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.timer_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.state_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.rsk_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.lsk_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.ck_draw_layer = g_vdorec_cntx.bg_layer_handle;
    g_vdorec_cntx.title_draw_layer = g_vdorec_cntx.bg_layer_handle; 
#endif /* __VDOPLY_FEATURE_MULTI_REGION_LAYER_OSD__ */



}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_style_text
 * DESCRIPTION
 *  draw styled text
 * PARAMETERS
 *  str             [IN]        String
 *  offset_x        [IN]        Offset x
 *  offset_y        [IN]        Offset y
 *  style_txt       [IN]        Text style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, video_style_text_struct *style_txt)
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
 *  mmi_vdorec_hide_hint
 * DESCRIPTION
 *  Hide hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdorec_set_hint(NULL, NULL, 0);
    mmi_vdorec_draw_osd();
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_hint
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_HIDE_OSD__
static void mmi_vdorec_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x;
    S32 str1_offset_y;
    S32 str2_offset_x;
    S32 str2_offset_y;
    S32 spacing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdorec_osd_cntx.hint.is_show)
    {
        return;
    }

    if (g_vdorec_cntx.hint1_buf != NULL)
    {
        gui_measure_string((UI_string_type) g_vdorec_cntx.hint1_buf, &str1_width, &str1_height);

        if (g_vdorec_cntx.hint2_buf == NULL)
        {
            str1_offset_x = (g_vdorec_osd_cntx.hint.rect.width - str1_width) >> 1;
            str1_offset_y = (g_vdorec_osd_cntx.hint.rect.height - str1_height) >> 1;
        }
        else
        {
            gui_measure_string((UI_string_type) g_vdorec_cntx.hint2_buf, &str2_width, &str2_height);

            str1_offset_x = (g_vdorec_osd_cntx.hint.rect.width - str1_width) >> 1;

            spacing = g_vdorec_osd_cntx.hint.rect.height - str1_height - str2_height;
            spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

            str1_offset_y = spacing;

            str2_offset_x = (g_vdorec_osd_cntx.hint.rect.width - str2_width) >> 1;
            str2_offset_y = spacing * 2 + 1 + str1_height;
        }

        str1_offset_x += g_vdorec_osd_cntx.hint.rect.offset_x;
        str1_offset_y += g_vdorec_osd_cntx.hint.rect.offset_y;
        str2_offset_x += g_vdorec_osd_cntx.hint.rect.offset_x;
        str2_offset_y += g_vdorec_osd_cntx.hint.rect.offset_y;

        gdi_layer_reset_clip();
        gui_reset_text_clip();

        mmi_vdorec_draw_style_text(
            g_vdorec_cntx.hint1_buf,
            str1_offset_x,
            str1_offset_y,
            &g_vdorec_osd_cntx.hint.style_text);

        if (g_vdorec_cntx.hint2_buf != NULL)
        {
            mmi_vdorec_draw_style_text(
                g_vdorec_cntx.hint2_buf,
                str2_offset_x,
                str2_offset_y,
                &g_vdorec_osd_cntx.hint.style_text);
        }

        if (g_vdorec_cntx.fade_time != 0)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_vdorec_hide_hint);
        }

    }
}
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_hint
 * DESCRIPTION
 *  set hint string
 * PARAMETERS
 *  hint_str1       [IN]        String 1
 *  hint_str2       [IN]        String 2
 *  fade_time       [IN]        Hint fade out time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear buffer */
    memset(g_vdorec_cntx.hint1_buf, 0, VDOREC_HINT_BUF_SIZE);
    memset(g_vdorec_cntx.hint2_buf, 0, VDOREC_HINT_BUF_SIZE);

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_vdorec_cntx.hint1_buf, (PS8) hint_str1, VDOREC_HINT_BUF_SIZE);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_vdorec_cntx.hint2_buf, (PS8) hint_str2, VDOREC_HINT_BUF_SIZE);
    }

    g_vdorec_cntx.fade_time = fade_time;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_osd
 * DESCRIPTION
 *  draw osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __VDOREC_FEATURE_HIDE_OSD__
    gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);

    /* toggle double buffer */
    gdi_layer_toggle_double();

    /* clear bg */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    /* drawing */
    mmi_vdorec_draw_status();
    mmi_vdorec_draw_hint();

    gdi_layer_pop_and_restore_active();
#endif /* __VDOREC_FEATURE_HIDE_OSD__ */
}



/*****************************************************************************
*
*  Save Screen
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_confirm_no
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete unsaved file */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);

    if (g_vdorec_cntx.is_ext_req && g_vdorec_cntx.is_use_ext_req_path)
    {
        /* use external path, do nothing */
    }
    else
    {
        /* the seq num is already increase, so if we dont want to save this file, decrease it */
        ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);

        if (g_vdorec_cntx.filename_seq_no > 1)
        {
            g_vdorec_cntx.filename_seq_no--;
        }
           
        WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);
    }

    if (g_vdorec_cntx.is_ext_req)
    {
        /* delete all video recorder screen */
        DeleteUptoScrID(SCR_ID_VDOREC_APP);
        DeleteNHistory(1);

        /* notify request caller, video is not saved */
        g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
        g_vdorec_cntx.ext_req_callback = NULL;
        GoBackHistory();
    }
    else
    {
        GoBackHistory();
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_save_confirm_screen
 * DESCRIPTION
 *  enter save confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_save_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ClearInputEventHandler(MMI_DEVICE_KEY);
    
#ifdef __MMI_VDOREC_MMS_SUPPORT__
    /* support link to MMS */
    g_vdorec_cntx.is_foward_to = FALSE;
    g_vdorec_cntx.is_save_done_when_mt = FALSE;


#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    if (mms_is_ready() && !g_vdorec_cntx.is_ext_req)
    {
        /* 
         *  (1) Wap ready
         *  (2) Not in flight mode
         *  (3) Not external record request
         */
        DisplayConfirmRotatedExt(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            0,
            IMG_ID_VDOREC_FORWARD_TO_MMS,
            get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE,
            MMI_FRM_SCREEN_ROTATE_270);
    }
    else
    {
       DisplayConfirmRotated(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE,
            MMI_FRM_SCREEN_ROTATE_270);
    }
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    if (mms_is_ready() && !g_vdorec_cntx.is_ext_req)
    {
        DisplayConfirmExt(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            0,
            IMG_ID_VDOREC_FORWARD_TO_MMS,
            get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }
    else
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    }

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    if (mms_is_ready() && !g_vdorec_cntx.is_ext_req)
    {
        register_center_softkey_to_enter_key();
        SetCenterSoftkeyFunction(mmi_vdorec_save_confirm_forward_to, KEY_EVENT_UP);
    }

    SetRightSoftkeyFunction(mmi_vdorec_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdorec_entry_saving_screen, KEY_EVENT_UP);

#else /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    /* do not support link to MMS */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)

    DisplayConfirmRotated(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE,
        MMI_FRM_SCREEN_ROTATE_270);
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    SetRightSoftkeyFunction(mmi_vdorec_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdorec_entry_saving_screen, KEY_EVENT_UP);

#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_confirm_forward_to
 * DESCRIPTION
 *  forward to key pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VDOREC_MMS_SUPPORT__
static void mmi_vdorec_save_confirm_forward_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_foward_to = TRUE;
    mmi_vdorec_entry_saving_screen();
}
#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_result_hdlr_callback
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_result_hdlr_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_saving = FALSE;

    /* if video recorder is already removed from history , do not show popup */
    if (!IsScreenPresent(SCR_ID_VDOREC_APP))
    {
        return;
    }

    if (g_vdorec_cntx.is_foward_to)
    {
    #ifdef __MMI_VDOREC_MMS_SUPPORT__

        /* link to foward to */

        if (!(isInCall() && !IsWapCallPresent()))
        {
            /* enter only not in call and wap not in call */
            if (result >= 0)
            {
                /* foward to MMS */
                mmi_fmgr_util_load_filepath(buf_filepath, FMGR_PATH_ID_VIDEO);
                DeleteUptoScrID(SCR_ID_VDOREC_APP);
                mms_content_insert_hdlr((PS8)buf_filepath);
                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);                
                return;
            }
            else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);
            }
            else
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }

            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);

            /* if clam is close, delete one more screen, avoid enter video recorder */
            if (IsClamClose())
            {
                DeleteNHistory(1);
            }

        }
        else
        {
            /*
             * when it is in MT, do nothing, will handle foward
             * to after back from MT 
             */

            g_vdorec_cntx.save_result = result;
            g_vdorec_cntx.is_save_done_when_mt = TRUE;
            return;

        }

    #endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    }
    else
    {
        if (g_vdorec_cntx.is_ext_req)
        {
            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);

            /* is in call or alarm, they have higher priority, do not show popup */
            if (!(isInCall() && !IsWapCallPresent()) && !(AlmIsTonePlaying()))
            {
                /* enter only not in call and wap not in call */
                if (result >= 0)
                {
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    mmi_fmgr_util_load_filepath(buf_filepath, FMGR_PATH_ID_VIDEO);
                    g_vdorec_cntx.ext_req_callback(MMI_TRUE, buf_filepath);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    GoBackHistory();
                    return;
                }
                else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        ST_NOTIFYDURATION,
                        SUCCESS_TONE);
                    
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);

                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;
                }
                else
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),
                        IMG_GLOBAL_WARNING,
                        1,
                        ST_NOTIFYDURATION,
                        WARNING_TONE);

                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;                    
                }
            }
            else
            {
                /* in call or in WAP or in alarm */
                
                if (result >= 0)
                {
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    mmi_fmgr_util_load_filepath(buf_filepath, FMGR_PATH_ID_VIDEO);
                    g_vdorec_cntx.ext_req_callback(MMI_TRUE, buf_filepath);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;
                }
                else
                {
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;
                }
            }
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);

            /* Alarm playing */
            if (AlmIsTonePlaying())
            {
                return;
            }

            /* is in call, they have higher priority, do not show popup */
            if (!(isInCall() && !IsWapCallPresent()))
            {
                /* enter only not in call and wap not in call */
                if (result >= 0)
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(STR_GLOBAL_SAVED),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        ST_NOTIFYDURATION,
                        SUCCESS_TONE);
                }
                else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                        IMG_GLOBAL_ACTIVATED,
                        1,
                        ST_NOTIFYDURATION,
                        SUCCESS_TONE);
                }
                else
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),
                        IMG_GLOBAL_WARNING,
                        1,
                        ST_NOTIFYDURATION,
                        WARNING_TONE);
                }

                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);

                /* if clam is close, delete one more screen, avoid enter video recorder */
                if (IsClamClose())
                {
                    DeleteNHistory(1);
                }

            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern BOOL g_PopupMsg;
static void mmi_vdorec_exit_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resume background play */
    mdi_audio_resume_background_play();
	g_PopupMsg=FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_saving_screen_del_hdlr
 * DESCRIPTION
 *  Del screen callback function
 * PARAMETERS
 *  dummy_ptr       [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_vdorec_saving_screen_del_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.is_saving)
    {
        return TRUE;    /* if is saving, will not delete this screen from history */
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_PopupMsg=TRUE;
#ifdef __MMI_VDOREC_MMS_SUPPORT__
    if (g_vdorec_cntx.is_save_done_when_mt && g_vdorec_cntx.is_foward_to)
    {
        /* save done while in MT, when back from MT, will enter here */
        g_vdorec_cntx.is_save_done_when_mt = FALSE;

        if (g_vdorec_cntx.save_result >= 0)
        {
            mmi_fmgr_util_load_filepath(buf_filepath, FMGR_PATH_ID_VIDEO);
            DeleteUptoScrID(SCR_ID_VDOREC_APP);
            mms_content_insert_hdlr((PS8)buf_filepath);
            return;
        }
        else if (g_vdorec_cntx.save_result == MDI_RES_VDOREC_ERR_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_ACTIVATED,
                1,
                ST_NOTIFYDURATION,
                SUCCESS_TONE);
        }
        else
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
        }

        /* if clam is close, delete one more screen, avoid enter video recorder */
        if (IsClamClose())
        {
            DeleteNHistory(1);
        }

        return;
    }
#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    g_vdorec_cntx.is_saving = TRUE;
    SetDelScrnIDCallbackHandler(SCR_ID_VDOREC_SAVING, mmi_vdorec_saving_screen_del_hdlr);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_VDOREC_SAVING, mmi_vdorec_exit_saving_screen, mmi_vdorec_entry_saving_screen, NULL);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory66Screen(
        CAT66_AREA_NONE,
        CAT66_AREA_NONE,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVING),
        IMG_GLOBAL_PROGRESS,
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_SAVING);

    if (guiBuffer == NULL)
    {
        /* check is entry from vdorec app */
        mmi_vdoply_get_storage_file_path(buf_filepath);

        g_vdorec_cntx.last_error = mdi_video_rec_save_file(buf_filepath, mmi_vdorec_save_result_hdlr_callback);

        if (mmi_vdorec_check_and_display_error_popup() == TRUE) /* TRUE means has error */
        {
            /* if has error, cant save, delete temp file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);
            return;
        }
    }

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
*
* Menu Screens
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_option_menu
 * DESCRIPTION
 *  int option menu hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_init_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VDOREC_TO_VDOPLY, mmi_vdorec_highlight_to_vdoply);
    SetHiliteHandler(MENU_ID_VDOREC_CAMCODER_SETTING, mmi_vdorec_highlight_camcoder_setting);

#ifndef __VDOREC_FEATURE_MERGE_MENU__
    SetHiliteHandler(MENU_ID_VDOREC_VIDEO_SETTING, mmi_vdorec_highlight_video_setting);
#endif 

#ifdef __VDOREC_COLOR_IDX_FRAME__
    SetHiliteHandler(MENU_ID_VDOREC_COLOR_IDX_FRAME, mmi_vdorec_highlight_color_idx_frame);
    SetHintHandler(MENU_ID_VDOREC_COLOR_IDX_FRAME, mmi_vdorec_hint_color_idx_frame);
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_EFFECT__
    SetHiliteHandler(MENU_ID_VDOREC_EFFECT_SETTING, mmi_vdorec_highlight_effect_setting);
    SetHintHandler(MENU_ID_VDOREC_EFFECT_SETTING, mmi_vdorec_hint_effect_setting);
#endif /* __VDOREC_FEATURE_EFFECT__ */ 

#ifdef __VDOREC_FEATURE_STORAGE__
    SetHiliteHandler(MENU_ID_VDOREC_STORAGE, mmi_vdorec_highlight_storage);
    SetHintHandler(MENU_ID_VDOREC_STORAGE, mmi_vdorec_hint_storage);
#endif /* __VDOREC_FEATURE_STORAGE__ */ 

    SetHiliteHandler(MENU_ID_VDOREC_RESTORE_DEFAULT, mmi_vdorec_highlight_restore_default);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_vdoply
 * DESCRIPTION
 *  hiligith to vdorec menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_highlight_to_vdoply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoply_entry_app, KEY_EVENT_UP);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdoply_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_option_screen
 * DESCRIPTION
 *  entry option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOREC_OPTION, NULL, mmi_vdorec_entry_option_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_OPTION);
    nItems = GetNumOfChild(MENU_ID_VDOREC_OPTION);
    GetSequenceStringIds(MENU_ID_VDOREC_OPTION, ItemList);
    GetSequenceImageIds(MENU_ID_VDOREC_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_VDOREC_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_VDOREC_OPTION, PopUpList);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_camcoder_setting
 * DESCRIPTION
 *  highlight camecoder setting menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_highlight_camcoder_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_camcoder_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_camcoder_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


#if defined(DOUBLE_CAMERA_SUPPORT)
 // Huyanwei Add It For Video Recode Switch Camera
extern   UI_string_type g_camera_select_str[2] ;
extern   S32                 g_camera_selected ; 
extern BOOL  			mmi_main_camera_active ;  
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_camcoder_setting_lsk_press
 * DESCRIPTION
 *  camcoder setting lsk press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_camcoder_setting_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define CAMCODER_SETTING_SELECTED_VALUE(a, A)                                            \
   {                                                                                        \
      g_vdorec_cntx.setting.##a = g_vdorec_menu_cntx.camcoder_setting_inline.##a##_selected;\
   }

#if defined(DOUBLE_CAMERA_SUPPORT)
// Huyanwei Add It For Video Recode Switch Camera	
{
#if defined(WIN32)
	char AsciiString[128];
	memset(AsciiString,0,sizeof(AsciiString)) ;	
	sprintf(AsciiString,"g_camera_selected = %d\r\n",g_camera_selected);
	kal_print((char*)AsciiString );		   
#endif
	mmi_main_camera_active =  ((g_camera_selected ==  0) ? KAL_TRUE : KAL_FALSE );
}
#endif
	

#ifdef __VDOREC_FEATURE_WB__
    CAMCODER_SETTING_SELECTED_VALUE(wb, WB);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    CAMCODER_SETTING_SELECTED_VALUE(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_EV__
    CAMCODER_SETTING_SELECTED_VALUE(ev, EV);
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    CAMCODER_SETTING_SELECTED_VALUE(night, NIGHT);
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    CAMCODER_SETTING_SELECTED_VALUE(banding, BANDING);
#endif 

#ifdef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CAMCODER_SETTING_SELECTED_VALUE(video_size, VIDEO_SIZE);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    CAMCODER_SETTING_SELECTED_VALUE(video_qty, VIDEO_QTY);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CAMCODER_SETTING_SELECTED_VALUE(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CAMCODER_SETTING_SELECTED_VALUE(time_limit, TIME_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CAMCODER_SETTING_SELECTED_VALUE(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CAMCODER_SETTING_SELECTED_VALUE(video_format, VIDEO_FORMAT);
#endif 

#ifdef __VDOREC_FEATURE_ZOOM__
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
#endif 

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

    mmi_vdorec_store_setting();

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_camcoder_setting_highlight_hdlr
 * DESCRIPTION
 *  camcoder setting highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_camcoder_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_camcoder_setting_lsk_press);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_camcoder_setting_screen
 * DESCRIPTION
 *  exit camcoder setting screen (inline selection screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_camcoder_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_VDOREC_CAMCODER_SETTING;
    h.entryFuncPtr = mmi_vdorec_entry_camcoder_setting_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


#if defined(DOUBLE_CAMERA_SUPPORT)
 // Huyanwei Add It For Video Recode Switch Camera
  UI_string_type g_camera_select_str[2] ;
  S32                 g_camera_selected = 0 ; 
  extern BOOL  			mmi_main_camera_active ;  
  #include "MMI_features_camera.h"
  #include "CameraResDef.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_camcoder_setting_screen
 * DESCRIPTION
 *  entry camcoder setting screen (inline selection screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_camcoder_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE item_icons[VDOREC_CAMCODER_SETTING_ITEM_COUNT * 2] = 
    {

    #if defined(DOUBLE_CAMERA_SUPPORT)
    // Huyanwei Add It For Video Recode Switch Camera
    IMG_ID_VDOREC_EV,
    0,
    #endif
	
    #ifdef __VDOREC_FEATURE_WB__
        IMG_ID_VDOREC_WB,
        0,
    #endif /* __VDOREC_FEATURE_WB__ */ 

    #ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
        IMG_ID_VDOREC_LED_HIGHLIGHT,
        0,
    #endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

    #ifdef __VDOREC_FEATURE_EV__
        IMG_ID_VDOREC_EV,
        0,
    #endif /* __VDOREC_FEATURE_EV__ */ 

    #ifdef __VDOREC_FEATURE_NIGHT__
        IMG_ID_VDOREC_NIGHT,
        0,
    #endif /* __VDOREC_FEATURE_NIGHT__ */ 

    #ifdef __VDOREC_FEATURE_BANDING__
        IMG_ID_VDOREC_BANDING,
        0,
    #endif /* __VDOREC_FEATURE_BANDING__ */ 

    #ifdef __VDOREC_FEATURE_MERGE_MENU__

        /* merge "Video Setting" items into "CamCoder Setting" */
    #ifdef __VDOREC_FEATURE_VIDEO_SIZE__
        IMG_ID_VDOREC_VIDEO_SIZE,
        0,
    #endif /* __VDOREC_FEATURE_VIDEO_SIZE__ */ 

    #ifdef __VDOREC_FEATURE_VIDEO_QTY__
        IMG_ID_VDOREC_VIDEO_QTY,
        0,
    #endif /* __VDOREC_FEATURE_VIDEO_QTY__ */ 

    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
        IMG_ID_VDOREC_SIZE_LIMIT,
        0,
    #endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 

    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
        IMG_ID_VDOREC_TIME_LIMIT,
        0,
    #endif /* __VDOREC_FEATURE_TIME_LIMIT__ */ 

    #ifdef __VDOREC_FEATURE_RECORD_AUD__
        IMG_ID_VDOREC_RECORD_AUD,
        0,
    #endif /* __VDOREC_FEATURE_RECORD_AUD__ */ 

    #ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
        IMG_ID_VDOREC_VIDEO_FORMAT,
        0,
    #endif /* __VDOREC_FEATURE_VIDEO_FORMAT__ */ 

    #endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 
    };

    EntryNewScreen(SCR_ID_VDOREC_CAMCODER_SETTING, mmi_vdorec_exit_camcoder_setting_screen, NULL, NULL);

    InitializeCategory57Screen();

   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define CREATE_CAMCODER_SETTING_INLINE_SELECT(a, A)                                                                             \
   {                                                                                                                               \
      g_vdorec_menu_cntx.camcoder_setting_inline.##a##_selected = g_vdorec_cntx.setting.##a;                                       \
      for(i = 0 ; i < VDOREC_SETTING_##A##_COUNT; i++)                                                                             \
      {                                                                                                                            \
         g_vdorec_menu_cntx.camcoder_setting_inline.##a##_str[i] = (UI_string_type)GetString((U16)(STR_ID_VDOREC_##A##_START+i+1));\
      }                                                                                                                            \
      SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_VDOREC_##A)));                           \
      SetInlineItemActivation(&wgui_inline_items[item_offset],                                                                     \
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,                                                              \
                              0 );                                                                                                 \
      SetInlineItemSelect( &wgui_inline_items[item_offset++],                                                                      \
                           VDOREC_SETTING_##A##_COUNT,                                                                             \
                           (U8**)g_vdorec_menu_cntx.camcoder_setting_inline.##a##_str,                                             \
                           &g_vdorec_menu_cntx.camcoder_setting_inline.##a##_selected);                                            \
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/

    #if defined(DOUBLE_CAMERA_SUPPORT)
    // Huyanwei Add It For Video Recode Switch Camera
	g_camera_select_str[0] = (UI_string_type)GetString((U16)(STR_ID_CAMERA_IMAGE_DOUBLE_MODE_MASTER));
	g_camera_select_str[1] = (UI_string_type)GetString((U16)(STR_ID_CAMERA_IMAGE_DOUBLE_MODE_SILVER)) ;
	SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_CAMERA_IMAGE_DOUBLE_MODE)));                           
	SetInlineItemActivation(&wgui_inline_items[item_offset],INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0 );       

	if(mmi_main_camera_active == KAL_TRUE)
	{
		g_camera_selected = 0 ;
	}
	else
	{
		g_camera_selected = 1 ;
	}
	SetInlineItemSelect( &wgui_inline_items[item_offset++], 2,(U8**)g_camera_select_str,  &g_camera_selected);
    #endif

   
#ifdef __VDOREC_FEATURE_WB__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(wb, WB);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_EV__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(ev, EV);
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(night, NIGHT);
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(banding, BANDING);
#endif 

#ifdef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(video_size, VIDEO_SIZE);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(time_limit, TIME_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(video_format, VIDEO_FORMAT);
#endif 

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_CAMCODER_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_VDOREC_CAMCODER_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, VDOREC_CAMCODER_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_vdorec_camcoder_setting_highlight_hdlr);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_ID_VDOREC_CAMCODER_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_camcoder_setting_lsk_press);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_video_setting
 * DESCRIPTION
 *  highlight video setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_highlight_video_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_video_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_video_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_video_setting_lsk_press
 * DESCRIPTION
 *  video setting lsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_video_setting_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define VIDEO_SETTING_SET_SELECTED_VALUE(a, A)                                        \
   {                                                                                     \
      g_vdorec_cntx.setting.##a = g_vdorec_menu_cntx.video_setting_inline.##a##_selected;\
   }

#ifdef __VDOREC_FEATURE_ZOOM__
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
#endif 

    VIDEO_SETTING_SET_SELECTED_VALUE(video_size, VIDEO_SIZE);
    VIDEO_SETTING_SET_SELECTED_VALUE(video_qty, VIDEO_QTY);
    VIDEO_SETTING_SET_SELECTED_VALUE(size_limit, SIZE_LIMIT);
    VIDEO_SETTING_SET_SELECTED_VALUE(time_limit, TIME_LIMIT);
    VIDEO_SETTING_SET_SELECTED_VALUE(record_aud, RECORD_AUD);
    VIDEO_SETTING_SET_SELECTED_VALUE(video_format, VIDEO_FORMAT);

    mmi_vdorec_store_setting();

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_video_setting_highlight_hdlr
 * DESCRIPTION
 *  video setting highlight hdlr
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_video_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_video_setting_lsk_press);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_video_setting_screen
 * DESCRIPTION
 *  exit video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_exit_video_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_VDOREC_VIDEO_SETTING;
    h.entryFuncPtr = mmi_vdorec_entry_video_setting_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_video_setting_screen
 * DESCRIPTION
 *  entry video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_entry_video_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE item_icons[VDOREC_VIDEO_SETTING_ITEM_COUNT * 2] = 
    {
    #ifdef __VDOREC_FEATURE_VIDEO_SIZE__
        IMG_ID_VDOREC_VIDEO_SIZE,
        0,
    #endif /* __VDOREC_FEATURE_VIDEO_SIZE__ */ 

    #ifdef __VDOREC_FEATURE_VIDEO_QTY__
        IMG_ID_VDOREC_VIDEO_QTY,
        0,
    #endif /* __VDOREC_FEATURE_VIDEO_QTY__ */ 

    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
        IMG_ID_VDOREC_SIZE_LIMIT,
        0,
    #endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 

    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
        IMG_ID_VDOREC_TIME_LIMIT,
        0,
    #endif /* __VDOREC_FEATURE_TIME_LIMIT__ */ 

    #ifdef __VDOREC_FEATURE_RECORD_AUD__
        IMG_ID_VDOREC_RECORD_AUD,
        0,
    #endif /* __VDOREC_FEATURE_RECORD_AUD__ */ 

    #ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
        IMG_ID_VDOREC_VIDEO_FORMAT,
        0,
    #endif /* __VDOREC_FEATURE_VIDEO_FORMAT__ */ 
    };

    EntryNewScreen(SCR_ID_VDOREC_VIDEO_SETTING, mmi_vdorec_exit_video_setting_screen, NULL, NULL);

    InitializeCategory57Screen();

   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define CREATE_VIDEO_SETTING_INLINE_SELECT(a, A)                                                                             \
   {                                                                                                                            \
      g_vdorec_menu_cntx.video_setting_inline.##a##_selected = g_vdorec_cntx.setting.##a;                                       \
      for(i = 0 ; i < VDOREC_SETTING_##A##_COUNT; i++)                                                                          \
      {                                                                                                                         \
         g_vdorec_menu_cntx.video_setting_inline.##a##_str[i] = (UI_string_type)GetString((U16)(STR_ID_VDOREC_##A##_START+1+i));\
      }                                                                                                                         \
      SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_VDOREC_##A)));                        \
      SetInlineItemActivation(&wgui_inline_items[item_offset],                                                                  \
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,                                                           \
                              0 );                                                                                              \
      SetInlineItemSelect( &wgui_inline_items[item_offset++],                                                                   \
                           VDOREC_SETTING_##A##_COUNT,                                                                          \
                           (U8**)g_vdorec_menu_cntx.video_setting_inline.##a##_str,                                             \
                           &g_vdorec_menu_cntx.video_setting_inline.##a##_selected);                                            \
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CREATE_VIDEO_SETTING_INLINE_SELECT(video_size, VIDEO_SIZE);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    CREATE_VIDEO_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(time_limit, TIME_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CREATE_VIDEO_SETTING_INLINE_SELECT(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(video_format, VIDEO_FORMAT);
#endif 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_VIDEO_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_VDOREC_VIDEO_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, VDOREC_VIDEO_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_vdorec_video_setting_highlight_hdlr);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_ID_VDOREC_VIDEO_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_video_setting_lsk_press);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_effect_setting
 * DESCRIPTION
 *  hint effect setting
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hint_effect_setting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*) hintData[index],
        (S8*) GetString((U16) (STR_ID_VDOREC_EFFECT_START + g_vdorec_cntx.setting.effect + 1)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_effect_setting
 * DESCRIPTION
 *  highlight effect setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_highlight_effect_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_effect_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_effect_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_effect_setting_value
 * DESCRIPTION
 *  effect setting set value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_effect_setting_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
    g_vdorec_cntx.setting.effect = (U16) GetCurrHiliteID();
    mmi_vdorec_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_effect_setting_screen
 * DESCRIPTION
 *  entry effect setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_effect_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOREC_EFFECT_SETTING, NULL, mmi_vdorec_entry_effect_setting_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOREC_EFFECT_SETTING);

    nItems = GetNumOfChild(MENU_ID_VDOREC_EFFECT_SETTING);
    GetSequenceStringIds(MENU_ID_VDOREC_EFFECT_SETTING, ItemList);
    GetSequenceImageIds(MENU_ID_VDOREC_EFFECT_SETTING, ItemIcons);
    SetParentHandler(MENU_ID_VDOREC_EFFECT_SETTING);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory11Screen(
        STR_ID_VDOREC_EFFECT_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        g_vdorec_cntx.setting.effect,   /* current index */
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdorec_set_effect_setting_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_storage
 * DESCRIPTION
 *  hint storage
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_STORAGE__
static void mmi_vdorec_hint_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_fmgr_get_drive_name(
        (S8)mmi_vdoply_get_storage(), 
        (S8*)&hintData[index], 
        (U8)((FMGR_MAX_DRIVE_NAME_LEN + 1 ) * ENCODING_LENGTH));
}
#endif /* __VDOREC_FEATURE_STORAGE__ */ 



#ifdef __VDOREC_FEATURE_STORAGE__
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
#if !defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) || !defined(__MMI_SCREEN_ROTATE__)
static void mmi_vdorec_get_drive_callback(S8 drv_letter)
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
        prev_storage = mmi_vdoply_get_storage();
        mmi_vdoply_set_storage((U16)drv_letter);
            
        mmi_vdoply_get_storage_file_path(buf_filepath);
        create_result = mmi_vdoply_create_file_dir(buf_filepath);

        if (create_result != FS_NO_ERROR)
        {
            if (create_result == FS_WRITE_PROTECTION)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

               /* restore prev storage setting */
               mmi_vdoply_set_storage((U16)prev_storage);

               /* after popup, will re-enter storage screen */              
               return;
            }
            else if (create_result == FS_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);        

               /* restore prev storage setting */
               mmi_vdoply_set_storage((U16)prev_storage);

               /* after popup, will re-enter storage screen */              
               return;
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);    

               /* restore prev storage setting */            
               mmi_vdoply_set_storage((U16)prev_storage);

               /* after popup, will re-enter storage screen */              
               return;
            }
            else
            {
                /* other file system error */
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);

               /* restore prev storage setting */
               mmi_vdoply_set_storage((U16)prev_storage);

               /* after popup, will re-enter storage screen */              
               return;                
            }
        }
        else
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                0,
                ST_NOTIFYDURATION,
                SUCCESS_TONE);    
            
            /* storge setting to NVRAM */
            mmi_vdoply_store_setting();      
            
            if (g_vdorec_cntx.is_option_storage)
            {
                /* option -> storage */
                DeleteUptoScrID(SCR_ID_VDOREC_OPTION);            
            }
            else
            {
                /* app -> storage */                
                DeleteUptoScrID(SCR_ID_VDOREC_APP);
            }
            return;
        }

    }
    else
    {
        if (g_vdorec_cntx.is_option_storage)
        {
            /* user press RSK in drv selection screen */
            DeleteUptoScrID(SCR_ID_VDOREC_OPTION);
        }
        else
        {
            /* exit video recorder app */
            DeleteUptoScrID(SCR_ID_VDOREC_APP);
            DeleteNHistory(1);
        }
    }
}
#endif /* !defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) || !defined(__MMI_SCREEN_ROTATE__) */




/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) 
static void mmi_vdorec_storage_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vdorec_menu_cntx.cur_idx = index;
}
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)  */




/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdorec_entry_set_storage_screen_internal();

    /* change storage for Option -> Storage */
    g_vdorec_cntx.is_option_storage = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_storage_screen
 * DESCRIPTION
 *  entry app storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_app_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdorec_entry_set_storage_screen_internal();

    /* change storage for App -> Storage */
    /* this is used when enter app, the storage is not exist or folder cant be created */
    g_vdorec_cntx.is_option_storage = FALSE;    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_storage_screen_internal(void)
{
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_num;
    U8 highlighted;
    U16 icon_list[FMGR_TOTAL_STORAGE];
    PU8 pop_ptr_list[FMGR_TOTAL_STORAGE];
	S32 i;
    U32 *inline_list_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOREC_STORAGE, NULL, mmi_vdorec_entry_set_storage_screen_internal, NULL);

    mmi_fmgr_get_exist_storage_inline_list(
        (S8)mmi_vdoply_get_storage(), 
        &total_num, 
        (PU32)&inline_list_p, 
        &highlighted);

    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);

    RegisterHighlightHandler(mmi_vdorec_storage_highlight_handler);

    for (i = 0; i < total_num; i++)
    {
        icon_list[i] = (U16) (IMG_GLOBAL_L1 + i);
    }

    for (i = 0; i < total_num; i++)
    {
        pop_ptr_list[i] = NULL;
    }

    ShowCategory353Screen(
        (PU8)GetString(STR_ID_VDOREC_STORAGE),
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        total_num,
        (PU8*)inline_list_p,
        icon_list,
        pop_ptr_list,
        0,
        (S32)(highlighted),
        NULL);

    SetLeftSoftkeyFunction(mmi_vdorec_set_storage_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vdorec_set_storage_rsk_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_set_storage_rsk_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */
    EntryNewScreen(SCR_ID_VDOREC_STORAGE, NULL, mmi_vdorec_entry_set_storage_screen_internal, NULL);
    mmi_fmgr_sel_drv_and_enter(APP_VDOREC, mmi_vdorec_get_drive_callback, mmi_vdoply_get_storage());
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_storage_lsk_hdlr
 * DESCRIPTION
 *  set storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
static void mmi_vdorec_set_storage_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    S8 drv_letter;
    U16 prev_storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmgr_get_drive_letter_by_inline_index((U8)g_vdorec_menu_cntx.cur_idx, &drv_letter);

    prev_storage = mmi_vdoply_get_storage();
    mmi_vdoply_set_storage(drv_letter);

    sprintf(buf, "%c:\\", (U8)drv_letter);
    mmi_asc_to_ucs2(buf_filepath, buf);

    /* check if photo path exist or not */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    create_result = mmi_vdoply_create_file_dir(buf_filepath);

    if (create_result != FS_NO_ERROR)
    {
        if (create_result == FS_WRITE_PROTECTION)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                IMG_GLOBAL_WARNING,
                0,
                ST_NOTIFYDURATION,
                WARNING_TONE);

            /* restore prev storage setting */            
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;     
        }
        else if (create_result == FS_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                0,
                ST_NOTIFYDURATION,
                WARNING_TONE);


            /* restore prev storage setting */                  
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;     
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                0,
                ST_NOTIFYDURATION,
                WARNING_TONE);


            /* restore prev storage setting */      
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;        
        }
        else
        {
            /* other file system error */
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY),
                IMG_GLOBAL_WARNING,
                0,
                ST_NOTIFYDURATION,
                WARNING_TONE);


            /* restore prev storage setting */      
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;                    
        }
    }
    else
    {
        /* folder created */
        mmi_vdorec_disply_popup(
            (PU8) GetString(STR_GLOBAL_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            ST_NOTIFYDURATION,
            SUCCESS_TONE);

        mmi_vdoply_store_setting();
        
        if (g_vdorec_cntx.is_option_storage)
        {
            /* user press RSK in drv selection screen */
            DeleteUptoScrID(SCR_ID_VDOREC_OPTION);
        }
        else
        {
            /* enter video recorder app */
            DeleteUptoScrID(SCR_ID_VDOREC_APP);
        }
        return;
    }

}
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_storage_rsk_hdlr
 * DESCRIPTION
 *  set storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
static void mmi_vdorec_set_storage_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.is_option_storage)
    {
        /* option -> storage */
        GoBackHistory();
    }
    else
    {   
        /* app -> storage */
        /* exit video recorder app */
        DeleteUptoScrID(SCR_ID_VDOREC_APP);
        DeleteNHistory(1);
        GoBackHistory();
    }
}
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_storage
 * DESCRIPTION
 *  highlight storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_highlight_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_set_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_set_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif /* __VDOREC_FEATURE_STORAGE__ */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_restore_default
 * DESCRIPTION
 *  highlight restore default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_highlight_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_restore_default_confirm_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_restore_default_confirm_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_restore_default_confirm_yes
 * DESCRIPTION
 *  restore default confirm yes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_restore_default_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore default values */
    mmi_vdorec_restore_setting();
    
    /* restore storage vdoply part - storage */
    mmi_vdoply_set_storage((U16)MMI_PUBLIC_DRV);
    mmi_vdoply_store_setting();

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_restore_default_confirm_screen
 * DESCRIPTION
 *  entry restore default confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_restore_default_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)

    DisplayConfirmRotated(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE,
        MMI_FRM_SCREEN_ROTATE_270);
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdorec_entry_restore_default_confirm_yes, KEY_EVENT_UP);
}

/*****************************************************************************
*
*  Touch Screen Support
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)

    /* cord tranfrom, since already rotate */
    tmp_x = pos.x;
    tmp_y = pos.y;
    pos.x = tmp_y;
    pos.y = (UI_device_width - 1) - tmp_x;

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /* ev inc */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc))
    {
        if (g_vdorec_cntx.setting.ev >= VDOREC_SETTING_EV_COUNT - 1)
        {
            return;
        }

        g_vdorec_cntx.touch_ev_inc.is_press = TRUE;
        mmi_vdorec_inc_ev();

        g_vdorec_cntx.touch_object = VDOREC_TOUCH_EV_INC;
        return;
    }

    /* ev dec */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
    {
        if (g_vdorec_cntx.setting.ev == 0)
        {
            return;
        }

        g_vdorec_cntx.touch_ev_dec.is_press = TRUE;
        mmi_vdorec_dec_ev();

        g_vdorec_cntx.touch_object = VDOREC_TOUCH_EV_DEC;
        return;
    }

    /* zoom inc */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc))
    {
        g_vdorec_cntx.touch_zoom_inc.is_press = TRUE;

        mmi_vdorec_zoom_in();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_ZOOM_INC;
        return;
    }

    /* zoom dec */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
    {
        g_vdorec_cntx.touch_zoom_dec.is_press = TRUE;

        mmi_vdorec_zoom_out();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_ZOOM_DEC;
        return;
    }

    /* rsk */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_rsk))
    {
        mmi_vdorec_rsk_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_RSK;
        return;
    }

    /* lsk */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_lsk))
    {
        mmi_vdorec_lsk_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_LSK;
        return;
    }

    /* ck */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ck))
    {
        mmi_vdorec_ck_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_CK;
        return;
    }

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

    switch (g_vdorec_cntx.touch_object)
    {
        case VDOREC_TOUCH_EV_INC:
            g_vdorec_cntx.touch_ev_inc.is_press = FALSE;
            g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_inc_ev);

            mmi_vdorec_draw_panel_ev();
            mmi_vdorec_blt_screen();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_EV_DEC:
            g_vdorec_cntx.touch_ev_dec.is_press = FALSE;
            g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_dec_ev);

            mmi_vdorec_draw_panel_ev();
            mmi_vdorec_blt_screen();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_ZOOM_INC:
            g_vdorec_cntx.touch_zoom_inc.is_press = FALSE;
            g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_zoom_in);

            mmi_vdorec_draw_panel_zoom();
            mmi_vdorec_blt_screen();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_ZOOM_DEC:
            g_vdorec_cntx.touch_zoom_dec.is_press = FALSE;
            g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_zoom_out);

            mmi_vdorec_draw_panel_zoom();
            mmi_vdorec_blt_screen();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_RSK:
            mmi_vdorec_rsk_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_LSK:
            mmi_vdorec_lsk_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_CK:
            mmi_vdorec_ck_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;
    }

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)

    /* cord tranfrom, since already rotate */
    tmp_x = pos.x;
    tmp_y = pos.y;
    pos.x = tmp_y;
    pos.y = (UI_device_width - 1) - tmp_x;

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    switch (g_vdorec_cntx.touch_object)
    {
        case VDOREC_TOUCH_EV_INC:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc))
            {
                /* if move out */
                g_vdorec_cntx.touch_ev_inc.is_press = FALSE;
                g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_inc_ev);

                mmi_vdorec_draw_panel_ev();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_EV_DEC:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
            {
                /* if move out */
                g_vdorec_cntx.touch_ev_dec.is_press = FALSE;
                g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_dec_ev);

                mmi_vdorec_draw_panel_ev();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_ZOOM_INC:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc))
            {
                /* if move out */
                g_vdorec_cntx.touch_zoom_inc.is_press = FALSE;
                g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_zoom_in);

                mmi_vdorec_draw_panel_zoom();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_ZOOM_DEC:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
            {
                /* if move out */
                g_vdorec_cntx.touch_zoom_dec.is_press = FALSE;
                g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_zoom_out);

                mmi_vdorec_draw_panel_zoom();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_RSK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_rsk))
            {
                /* if move out */
                g_vdorec_cntx.is_rsk_pressed = FALSE;

                mmi_vdorec_draw_softkey();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_LSK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_lsk))
            {
                /* if move out */
                g_vdorec_cntx.is_lsk_pressed = FALSE;

                mmi_vdorec_draw_softkey();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_CK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ck))
            {
                /* if move out */
                g_vdorec_cntx.is_ck_pressed = FALSE;

                mmi_vdorec_draw_softkey();
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

    }

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_hit_test
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
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static BOOL mmi_vdorec_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */

#ifdef __VDOREC_COLOR_IDX_FRAME__
/*****************************************************************************
*  color idx frame 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_color_idx_frame
 * DESCRIPTION
 *  hint color idx frame
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hint_color_idx_frame(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*) hintData[index],
        (S8*) GetString((U16) (STR_ID_VDOREC_COLOR_IDX_FRAME_START + g_vdorec_cntx.setting.color_idx_frame + 1)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_color_idx_frame
 * DESCRIPTION
 *  highlight color idx frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_highlight_color_idx_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdorec_entry_color_idx_frame_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_color_idx_frame_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_color_idx_frame_highlight_hdlr
 * DESCRIPTION
 *  color idx frame highlight handler
 * PARAMETERS
 *  idx     [IN]        Highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_color_idx_frame_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_menu_cntx.cur_selected_color_idx_frame = idx;

    if (idx == 0)   /* off */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vdorec_set_color_idx_frame_value, KEY_EVENT_UP);
    }
    else    /* frame */
    {
        ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vdorec_entry_color_idx_frame_view_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_color_idx_frame_view_screen
 * DESCRIPTION
 *  entry color idx frame viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_color_idx_frame_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = 0;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOREC_COLOR_IDX_FRAME_VIEW, NULL, mmi_vdorec_entry_color_idx_frame_view_screen, NULL);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    gdi_layer_lock_frame_buffer();

    str_id = (U16) (STR_ID_VDOREC_COLOR_IDX_FRAME_OFF + g_vdorec_menu_cntx.cur_selected_color_idx_frame);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    img_id = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QVGA_START + g_vdorec_menu_cntx.cur_selected_color_idx_frame);
#elif defined(__VDOREC_FEATURE_VIDEO_SIZE_CIF__) || defined(__VDOREC_FEATURE_VIDEO_SIZE_QCIF__)
    img_id = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QCIF_START + g_vdorec_menu_cntx.cur_selected_color_idx_frame);
#endif 

    ShowCategory221Screen(
        str_id,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_ID_VDOREC_COLOR_IDX_FRAME_SET,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_WHITE,
        NULL);

#ifndef __MMI_TOUCH_SCREEN__
    draw_arrow_indication(0, 0, 1, 1);
#endif 

    gdi_layer_set_clip(
        0,
        MMI_title_y + MMI_title_height,
        UI_device_width - 1,
        MMI_title_y + MMI_title_height + MMI_content_height - 1);

    {
        S32 offset_x, offset_y, img_width, img_height;

        offset_x = MMI_title_x;
        offset_y = MMI_title_y + MMI_title_height;

        gdi_image_get_dimension_id(img_id, &img_width, &img_height);

        if (img_width > img_height)
        {
            if (img_width > MMI_content_width)
            {
                float tmp = (float)img_width / MMI_content_width;

                img_height = (S32) (((float)img_height) / tmp);
                img_width = MMI_content_width;
            }
            else
            {
                offset_x += ((MMI_content_width - img_width) >> 1);
            }

            offset_y += ((MMI_content_height - img_height) >> 1);
        }
        else
        {
            if (img_height > MMI_content_height)
            {
                float tmp = (float)img_height / MMI_content_height;

                img_width = (S32) (((float)img_width) / tmp);
                img_height = MMI_content_height;
            }
            else
            {
                offset_y += ((MMI_content_height - img_height) >> 1);
            }

            offset_x += ((MMI_content_width - img_width) >> 1);
        }
        gdi_image_draw_resized_id(offset_x, offset_y, img_width, img_height, img_id);
    }

    /* gdi_image_draw_id(0, 0, img_id); */

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_base_layer(0, 0, UI_device_width - 1, UI_device_height - 1);

    SetLeftSoftkeyFunction(mmi_vdorec_set_color_idx_frame_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_color_idx_frame_goto_previous_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_color_idx_frame_goto_next_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_color_idx_frame_goto_previous_frame
 * DESCRIPTION
 *  go to previous frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_color_idx_frame_goto_previous_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_menu_cntx.cur_selected_color_idx_frame == 1)
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame = VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1;
    }
    else
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame--;
    }

    mmi_vdorec_entry_color_idx_frame_view_screen();
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_color_idx_frame_goto_next_frame
 * DESCRIPTION
 *  go to next frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_color_idx_frame_goto_next_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_menu_cntx.cur_selected_color_idx_frame >= VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1)
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame = 1;
    }
    else
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame++;
    }

    mmi_vdorec_entry_color_idx_frame_view_screen();
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_color_idx_frame_value
 * DESCRIPTION
 *  set color idx frame setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_color_idx_frame_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* capture size not full screen */
    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteUptoScrID(SCR_ID_VDOREC_OPTION);

    g_vdorec_cntx.setting.color_idx_frame = g_vdorec_menu_cntx.cur_selected_color_idx_frame;
    mmi_vdorec_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_color_idx_frame_screen
 * DESCRIPTION
 *  highlight color idx frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_color_idx_frame_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U16 selected_item = 0;
    U16 menu_id = 0;
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOREC_COLOR_IDX_FRAME, NULL, mmi_vdorec_entry_color_idx_frame_screen, NULL);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    menu_id = MENU_ID_VDOREC_COLOR_IDX_FRAME;
    title_id = STR_ID_VDOREC_COLOR_IDX_FRAME;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_COLOR_IDX_FRAME);
    nItems = GetNumOfChild(menu_id);

    GetSequenceStringIds(menu_id, ItemList);
    GetSequenceImageIds(menu_id, ItemIcons);
    SetParentHandler(menu_id);

    RegisterHighlightHandler(mmi_vdorec_color_idx_frame_highlight_hdlr);

    if (guiBuffer != NULL)
    {
        selected_item = g_vdorec_menu_cntx.cur_selected_color_idx_frame;
    }
    else
    {
        selected_item = g_vdorec_cntx.setting.color_idx_frame;
    }

    ShowCategory11Screen(
        title_id,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        selected_item,  /* current index */
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_color_idx_frame
 * DESCRIPTION
 *  draw colo idx frame on overlay_frame layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_color_idx_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_idx = 0;
    gdi_color *p_gdi_palette;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.overlay_frame_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    /* if frame is set , draw frame */
    if (g_vdorec_cntx.setting.color_idx_frame != VDOREC_SETTING_COLOR_IDX_FRAME_OFF)
    {
        switch (vdorec_video_size_command_map[g_vdorec_cntx.setting.video_size])
        {
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
            case MDI_VIDEO_VIDEO_SIZE_SQCIF:
                ASSERT(0);
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
            case MDI_VIDEO_VIDEO_SIZE_QCIF:
                image_idx = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QCIF_START + g_vdorec_cntx.setting.color_idx_frame);
                g_vdorec_cntx.overlay_frame_width = VDOREC_COLOR_IDX_FRAME_QCIF_WIDTH;
                g_vdorec_cntx.overlay_frame_height = VDOREC_COLOR_IDX_FRAME_QCIF_HEIGHT;
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
            case MDI_VIDEO_VIDEO_SIZE_CIF:
                image_idx = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QCIF_START + g_vdorec_cntx.setting.color_idx_frame);
                g_vdorec_cntx.overlay_frame_width = VDOREC_COLOR_IDX_FRAME_QCIF_WIDTH;
                g_vdorec_cntx.overlay_frame_height = VDOREC_COLOR_IDX_FRAME_QCIF_HEIGHT;
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
            case MDI_VIDEO_VIDEO_SIZE_QQVGA:
                image_idx = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QVGA_START + g_vdorec_cntx.setting.color_idx_frame);
                g_vdorec_cntx.overlay_frame_width = VDOREC_COLOR_IDX_FRAME_QVGA_WIDTH;
                g_vdorec_cntx.overlay_frame_height = VDOREC_COLOR_IDX_FRAME_QVGA_HEIGHT;
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

            default:
                ASSERT(0);
                break;
        }
        gdi_layer_resize(g_vdorec_cntx.overlay_frame_width, g_vdorec_cntx.overlay_frame_height);
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));

        /* get palette and convert it into YUV444 */
        p_gdi_palette = gdi_layer_get_palette();
        g_vdorec_cntx.overlay_frame_source_key = (U8) gdi_image_gif_get_transparent_index();
        g_vdorec_cntx.overlay_frame_palette_size = gdi_image_gif_get_palette_size();
      /*************** RGB to YUV format **************************************************
      *
      *     [MSDN RGB888 to YUV444 (16bits)]
      *
      *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
      *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
      *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
      *     
      *     These formulas produce 8-bit results using coefficients 
      *     that require no more than 8 bits of (unsigned) precision. 
      *     Intermediate results require up to 16 bits of precision.
      *
      ***************************************************************************************/
        {
            U16 i;
            U32 Y, U, V;
            U32 R, G, B;
            U32 *p_overlay_palette;

            p_overlay_palette = &g_vdorec_cntx.overlay_palette[0];
            for (i = 0; i < 256; i++)
            {
                R = (U32) ((U8) (*p_gdi_palette >> 16));
                G = (U32) ((U8) (*p_gdi_palette >> 8));
                B = (U32) ((U8) (*p_gdi_palette));

                Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
                U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
                V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

                (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
                p_overlay_palette++;
                p_gdi_palette++;
            }
        }
        /* set palette, currently we only support 8bpp(256 colors) palette */
        mdi_video_set_overlay_palette(255, &g_vdorec_cntx.overlay_palette[0]);
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_change_frame_down
 * DESCRIPTION
 *  change add frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_change_frame_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently only allows to edit in preview state */
    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        if (g_vdorec_cntx.setting.color_idx_frame == 0)
        {
            g_vdorec_cntx.setting.color_idx_frame = VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1;
        }
        else
        {
            g_vdorec_cntx.setting.color_idx_frame--;
        }

        mdi_video_rec_preview_stop();
        mmi_vdorec_draw_color_idx_frame();
        mmi_vdorec_start_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_change_frame_up
 * DESCRIPTION
 *  change add frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_change_frame_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently only allows to edit in preview state */
    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        if (g_vdorec_cntx.setting.color_idx_frame >= VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1)
        {
            g_vdorec_cntx.setting.color_idx_frame = 0;
        }
        else
        {
            g_vdorec_cntx.setting.color_idx_frame++;
        }

        mdi_video_rec_preview_stop();
        mmi_vdorec_draw_color_idx_frame();
        mmi_vdorec_start_preview();
    }

}
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_usb_mode_hdlr
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_usb_mode_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.is_saving)
    {
        mdi_video_rec_stop_save();
        g_vdorec_cntx.is_saving = FALSE;
    }
}

#endif /* __MMI_VIDEO_RECORDER__ */ 
#endif /* _MMI_VDORECAPP_C */ 

