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
 *  VdoEdtApp.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Video Editor MMI application implement file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_VIDEO_EDITOR__


#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */
#include "gui.h"        /* Gui functions */
#include "gpioInc.h"    /* LED */
#include "SettingDefs.h"        /* popup sound */
#include "CommonScreens.h"      /* Popup */
#include "MainMenuDef.h"        /* Multi-media icon */
#include "Conversions.h"        /* char set conversion */
#include "PhoneSetupGprots.h"   /* PhnsetGetDefEncodingType() */
#include "ProtocolEvents.h"     /* Interrupt message ID */


#include "med_api.h"    /* media task */
#include "med_main.h"   /* media task */

#include "lcd_sw_rnd.h"
#include "lcd_if.h"
#include "gdi_util.h"           /* gdi_resizer */

#include "mdi_datatype.h"
#include "mdi_audio.h"  /* audio lib */
#include "mdi_video.h"  /* video lib */
#include "mdi_camera.h" /* camera lib */
#include "CameraApp.h"

#include "SettingProfile.h"     /* warning tone */
#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "USBDeviceGprot.h"     /* USB MS mode */
#include "CallManagementGprot.h" /* for isInCall() */


#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "resource_vdoedt_skins.h"
#include "VdoEdtResDef.h"

#include "VdoEdtMem.h"
#include "VdoEdtApp.h"
#include "VdoEdtGProt.h"
#include "AudioPlayerDef.h"

#include "wgui_status_icons.h"  /* status UI */
#include "rtc_sw.h"

#include "PhoEdtResDef.h"
#ifdef __MMI_VDOEDT_USE_APPMEM__
#endif /* __MMI_VDOEDT_USE_APPMEM__ */ 
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#include "drm_def.h"
#include "DRM_main.h"
#endif /* __DRM_SUPPORT__ */ 

/***************************************************************************
* Globals.
****************************************************************************/
#define VDOEDT_COLOR_COUNT     (22)
#define MMI_VDOEDT_GET_GDI_COLOR(c) gdi_act_color_from_rgb(255, (c)->r, (c)->g, (c)->b)


vdoedt_context_struct g_vdoedt_cntx;
vdoedt_ui_key_struct g_vdoedt_key_cntx;

extern wgui_inline_item wgui_inline_items[];    /* for effect */
extern BOOL r2lMMIFlag;

static const color g_vdoedt_text_color_list[VDOEDT_COLOR_COUNT] = 
{
    {255, 255, 255},
    {200, 200, 200},
    {150, 150, 150},
    {100, 100, 100},
    {0, 0, 0},
    {61, 102, 206},
    {115, 241, 252},
    {145, 61, 206},
    {203, 161, 205},
    {255, 53, 240},
    {244, 154, 193},
    {254, 132, 0},
    {255, 240, 0},
    {254, 0, 24},
    {249, 173, 129},
    {89, 189, 69},
    {201, 231, 197},
    {0, 114, 54},
    {196, 223, 155},
    {96, 57, 19},
    {200, 159, 113},
    {27, 20, 100}
};

/*--------------------------------------*/
/* function headers                     */
/*--------------------------------------*/

void mmi_vdoedt_hilight_app(void);
void mmi_vdoedt_entry_app(void);

/* main screens */
static void mmi_vdoedt_entry_main_screen(void);
static void mmi_vdoedt_exit_main_screen(void);
static void mmi_vdoedt_entry_frame_edit_screen(void);
static void mmi_vdoedt_exit_frame_edit_screen(void);
static void mmi_vdoedt_entry_cut_screen(void);
static void mmi_vdoedt_exit_cut_screen(void);
static void mmi_vdoedt_entry_save_screen(void);

/* insert video/image */
static void mmi_vdoedt_entry_video_sel(void);
static void mmi_vdoedt_entry_img_sel_option_screen(void);
static void mmi_vdoedt_entry_img_file_select_screen(void);
static void mmi_vdoedt_img_ins_last_frame(void);
static void mmi_vdoedt_img_ins_first_frame(void);
static void mmi_vdoedt_entry_img_ins_color_screen(void);

static void mmi_vdoedt_entry_frame_txt_edt_screen(void);

static void mmi_vdoedt_media_sel_result_callback(void *filepath, int is_short);

static void mmi_vdoedt_video_do_insert(void);
static void mmi_vdoedt_img_do_insert_file(void);
static void mmi_vdoedt_entry_media_preview_scr(void);

static void mmi_vdoedt_remove_hilight_shot(void);
void mmi_vdoedt_shot_remove_internal(S32 i_remov);


static void mmi_vdoedt_back_from_editor_screen(void);
static void mmi_vdoedt_return_to_editor_screen(void);
static void mmi_vdoedt_filename_edit_done(void);
static void mmi_vdoedt_enc_file_overwrite(void);

static void mmi_vdoedt_entry_frame_select_scr(void);
static void mmi_vdoedt_exit_frame_select_scr(void);
static void mmi_vdoedt_entry_frame_clear(void);

static void mmi_vdoedt_entry_text_property_screen(void);
static void mmi_vdoedt_entry_save_filename_edt_screen(void);

static void mmi_vdoedt_frame_sel_done(void);
static void mmi_vdoedt_effect_select_done_hdlr(void);

static void mmi_vdoedt_update_osd_time(void);

static void mmi_vdoedt_img_ins_color_draw_callback(
                S32 idx,
                S32 page_start_idx,
                S32 page_end_idx,
                BOOL is_hilighted,
                BOOL is_need_update,
                BOOL is_new_page,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2);
static void mmi_vdoedt_img_ins_hide_callback(S32 idx);
static void mmi_vdoedt_img_ins_color(void);

/* cut */
static void mmi_vdoedt_adjust_cut_right(void);
static void mmi_vdoedt_adjust_cut_left(void);
static void mmi_vdoedt_adjust_cut_internal(BOOL);
static void mmi_vdoedt_update_cut_preview(void);
static void mmi_vdoedt_video_apply_cut(void);

/* frame */
static void mmi_vdoedt_frame_edit_done(void);
static void mmi_vdoedt_frame_edit_giveup(void);
static void mmi_vdoedt_hide_frmtxt(void);
static void mmi_vdoedt_show_frmtxt(void);

/* play back */
static void mmi_vdoedt_play(void);
static void mmi_vdoedt_play_shot(S32 idx);
static void mmi_vdoedt_shot_finish(void);
static void mmi_vdoedt_play_stop(void);
void mmi_vdoedt_play_shot_updater(void);
S32 mmi_vdoedt_get_shot_idx(U64 *ms_start);
void mmi_vdoedt_update_time_base(U8 idx);

/* option screens */
static void mmi_vdoedt_entry_empty_option_screen(void);
static void mmi_vdoedt_entry_edit_option_screen(void);
static void mmi_vdoedt_entry_preview_option_screen(void);
static void mmi_vdoedt_entry_effect_option_screen(void);
static void mmi_vdoedt_entry_frame_edit_option(void);
static void mmi_vdoedt_entry_filename_edit_option(void);
static void mmi_vdoedt_entry_frame_text_edit_option(void);
static void mmi_vdoedt_entry_img_dur_option_screen(void);


/* key handler */
static void mmi_vdoedt_main_scr_upkey_hdlr(void);
static void mmi_vdoedt_main_scr_downkey_hdlr(void);
static void mmi_vdoedt_main_scr_rightkey_hdlr(void);
static void mmi_vdoedt_main_scr_leftkey_hdlr(void);
static void mmi_vdoedt_lsk_down(void);
static void mmi_vdoedt_rsk_down(void);
static void mmi_vdoedt_lsk_up(void);
static void mmi_vdoedt_rsk_up(void);

static void mmi_vdoedt_ck_down(void);
static void mmi_vdoedt_ck_up(void);

static void mmi_vdoedt_cut_scr_upkey_hdlr(void);
static void mmi_vdoedt_cut_scr_downkey_hdlr(void);

static void mmi_vdoedt_cut_scr_rightkey_down(void);
static void mmi_vdoedt_cut_scr_rightkey_up(void);
static void mmi_vdoedt_cut_scr_leftkey_down(void);
static void mmi_vdoedt_cut_scr_leftkey_up(void);
static void mmi_vdoedt_cut_edit_giveup(void);
static void mmi_vdoedt_frm_sel_rak_up(void);
static void mmi_vdoedt_frm_sel_lak_up(void);
static void mmi_vdoedt_frm_sel_rak_down(void);
static void mmi_vdoedt_frm_sel_lak_down(void);
static void mmi_vdoedt_vol_inc(void);
static void mmi_vdoedt_vol_dec(void);

/* hilight handlers */
static void mmi_vdoedt_hilight_save(void);
static void mmi_vdoedt_hilight_new_w7e(void);

static void mmi_vdoedt_hilight_ins_vdo(void);
static void mmi_vdoedt_hilight_ins_img(void);
static void mmi_vdoedt_hilight_effect(void);
static void mmi_vdoedt_hilight_cut_vdo(void);
static void mmi_vdoedt_hilight_set_dur(void);
static void mmi_vdoedt_hilight_edt_frame(void);
static void mmi_vdoedt_hilight_remove(void);
static void mmi_vdoedt_hilight_frame_sel(void);
static void mmi_vdoedt_hilight_frame_clear(void);
static void mmi_vdoedt_hilight_frame_text(void);
static void mmi_vdoedt_hilight_frame_edit(void);

static void mmi_vdoedt_hilight_img_ins_file(void);
static void mmi_vdoedt_hilight_img_ins_last_frame(void);
static void mmi_vdoedt_hilight_img_ins_first_frame(void);
static void mmi_vdoedt_hilight_img_ins_color(void);

static void mmi_vdoedt_hilight_text_edit_done(void);
static void mmi_vdoedt_hilight_text_edit_cancel(void);
static void mmi_vdoedt_hilight_text_sel_inp_method(void);


static void mmi_vdoedt_hilight_2phone(void);
static void mmi_vdoedt_hilight_2card(void);

/* seek */
static void mmi_vdoedt_seek_internal(BOOL inc);
static void mmi_vdoedt_key_ff_down(void);   /* seek fastforward */
static void mmi_vdoedt_key_seek_up(void);   /* seek fastforward */
static void mmi_vdoedt_seek_ff(void);
static void mmi_vdoedt_key_rw_down(void);
static void mmi_vdoedt_seek_rw(void);
static void mmi_vdoedt_seek_result_callback(MDI_RESULT mdi_res);
static void mmi_vdoedt_update_seek_frame(void);

/* encode */
BOOL mmi_vdoedt_enc_init(PS8 p_fname);
void mmi_vdoedt_enc_next_slice(void);
void mmi_vdoedt_enc_append_cyclic(void);
void mmi_vdoedt_enc_state_update(void);
void mmi_vdoedt_entry_encode_screen(void);
void mmi_vdoedt_exit_encode_screen(void);

/* play effect */
static void mmi_vdoedt_init_in_effect(S32 init_val);
static void mmi_vdoedt_effect_in(void);
static void mmi_vdoedt_set_out_effect(S32 init_val);
static void mmi_vdoedt_effect_out(void);

/* utility function */
static vdoedt_state_enum mmi_vdoedt_get_stat(void);

static void mmi_vdoedt_init_cntx(void);
static void mmi_vdoedt_enter_stat(vdoedt_state_enum);

static void mmi_vdoedt_exit_confirm(void);
static void mmi_vdoedt_delete_main_scr(void);
static S32 mmi_vdoedt_get_free_shot_idx(void);
static void mmi_vdoedt_alloc_shot_mem(vdoedt_shot_struct **p_shot);
static gdi_result mmi_vdoedt_draw_img_file_in_rect(PS8 fname, S32 recw, S32 rech);
static void mmi_vdoedt_update_total_duration(void);

static void mmi_vdoedt_util_create_layers(U8 flag);
static void mmi_vdoedt_util_free_layers(void);
static void mmi_vdoedt_util_set_key_handlers(U16 scr_id);

static U8 mmi_vdoedt_del_main_callback_hdlr(void *ptr);
static void mmi_vdoedt_init_key_objs(void);
static void mmi_vdoedt_init_hilite_hdlrs(void);

static void mmi_vdoedt_save_pre_check(void);
static BOOL mmi_vdoedt_check_disk_space(U32 b_req_size, PS8 drive);

static void mmi_vdoedt_popup(U16 id_str);
static void mmi_vdoedt_ms_2_hms(U32 ms_conv, mmi_vdoedt_time_struct *hms_time_t);
#if 0
/* under construction !*/
#endif

static void mmi_vdoedt_util_suspend_bg_audio(void);
static void mmi_vdoedt_util_resume_bg_audio(void);


#ifdef __MMI_TOUCH_SCREEN__
static void mmi_vdoedt_util_set_touch_hdlr(void);
static void mmi_vdoedt_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vdoedt_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vdoedt_pen_move_hdlr(mmi_pen_point_struct pos);
static void mmi_vdoedt_touch_on_pbar(s16 x, s16 y);
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* draw functions */
static void mmi_vdoedt_redraw_main_scr(U8 item);
static void mmi_vdoedt_redraw_cut_scr(U8 item);
static void mmi_vdoedt_redraw_frm_sel_scr(U8 item);
static void mmi_vdoedt_draw_softkey(PS8 lsk_str, PS8 rsk_str, BOOL is_clear_bg);
static void mmi_vdoedt_draw_shot_hilight(U8 i_shot);
static void mmi_vdoedt_draw_preview(void);
static void mmi_vdoedt_draw_ebar(void);
static void mmi_vdoedt_draw_ebar_keyframes(void);
static void mmi_vdoedt_draw_time(U32 time);
static void mmi_vdoedt_draw_stat(void);
static void mmi_vdoedt_draw_frametxt(U64 time);
static void mmi_vdoedt_redraw(void);
static void mmi_vdoedt_draw_cut_bar(void);
static void mmi_vdoedt_show_option52(U16 id_menu, U16 id_str, PU8 gui_buffer);
static void mmi_vdoedt_frm_sel_restore(void);
static void mmi_vdoedt_draw_main_pbar(U32 ms_t, U32 ms_t_total);
static void mmi_vdoedt_draw_custom_txt(void);
static void mmi_vdoedt_draw_title(U16 id_str);
static void mmi_vdoedt_draw_seek_keys(void);
static void mmi_vdoedt_check_cut_bound(PS32 x);
static void mmi_vdoedt_frmtxt_set(S32 idx, U32 ms_t_offset);
static void mmi_vdoedt_effect_set(S32 idx, U32 ms_t_offset);
static void mmi_vdoedt_enc_append_done(void);

/* cache file related */
static S32 mmi_vdoedt_create_tmpdir(void);
static void mmi_vdoedt_remov_tmpdir(void);
static BOOL mmi_vdoedt_update_cachefile(void);
static void mmi_vdoedt_remov_cachefile(void);

BOOL mmi_vdoedt_seek_result_handler(MDI_RESULT res);

/* appmem */
#ifdef __MMI_VDOEDT_USE_APPMEM__
void mmi_vdoedt_stop_calback(void);
void mmi_vdoedt_free_appmem(void);
#endif /* __MMI_VDOEDT_USE_APPMEM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_init_app
 * DESCRIPTION
 *  initialize video editor global context, Hilight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VDOEDT_USE_APPMEM__
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_VDOEDT,
        STR_ID_VDOEDT_APP,
        IMG_ID_VDOEDT_MAIN_ICON,
        mmi_vdoedt_stop_calback);
#endif /* __MMI_VDOEDT_USE_APPMEM__ */ 
    mmi_vdoedt_init_hilite_hdlrs();
    mmi_vdoedt_init_key_objs();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_init_hilite_hdlrs
 * DESCRIPTION
 *  initialize video editor global context, Hilight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_init_hilite_hdlrs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* main menu */
    SetHiliteHandler(MENU_ID_VDOEDT_APP, mmi_vdoedt_hilight_app);
    /* edit */
    SetHiliteHandler(MENU_ID_VDOEDT_SAVE, mmi_vdoedt_hilight_save);
    SetHiliteHandler(MENU_ID_VDOEDT_NEW_W7E, mmi_vdoedt_hilight_new_w7e);
    SetHiliteHandler(MENU_ID_VDOEDT_INS_VDO, mmi_vdoedt_hilight_ins_vdo);
    SetHiliteHandler(MENU_ID_VDOEDT_INS_IMG, mmi_vdoedt_hilight_ins_img);
    SetHiliteHandler(MENU_ID_VDOEDT_REMOVE, mmi_vdoedt_hilight_remove);
    SetHiliteHandler(MENU_ID_VDOEDT_EFFECT, mmi_vdoedt_hilight_effect);
    SetHiliteHandler(MENU_ID_VDOEDT_CUT_VDO, mmi_vdoedt_hilight_cut_vdo);
    SetHiliteHandler(MENU_ID_VDOEDT_SET_DUR, mmi_vdoedt_hilight_set_dur);
    SetHiliteHandler(MENU_ID_VDOEDT_FRAME, mmi_vdoedt_hilight_edt_frame);
    /* frame */
    SetHiliteHandler(MENU_ID_VDOEDT_FRAME_SEL, mmi_vdoedt_hilight_frame_sel);
    SetHiliteHandler(MENU_ID_VDOEDT_FRAME_CLEAR, mmi_vdoedt_hilight_frame_clear);
    SetHiliteHandler(MENU_ID_VDOEDT_FRAME_TXT, mmi_vdoedt_hilight_frame_text);
    SetHiliteHandler(MENU_ID_VDOEDT_FRAME_EDT, mmi_vdoedt_hilight_frame_edit);
    /* insert image */
    SetHiliteHandler(MENU_ID_VDOEDT_INS_IMG_FROM_FILE, mmi_vdoedt_hilight_img_ins_file);
    SetHiliteHandler(MENU_ID_VDOEDT_INS_IMG_LAST_FRAME, mmi_vdoedt_hilight_img_ins_last_frame);
    SetHiliteHandler(MENU_ID_VDOEDT_INS_IMG_FIRST_FRAME, mmi_vdoedt_hilight_img_ins_first_frame);
    SetHiliteHandler(MENU_ID_VDOEDT_INS_IMG_COLOR, mmi_vdoedt_hilight_img_ins_color);
    /* filename editor option */
    SetHiliteHandler(MENU_ID_VDOEDT_DONE, mmi_vdoedt_hilight_text_edit_done);
    SetHiliteHandler(MENU_ID_VDOEDT_CANCEL, mmi_vdoedt_hilight_text_edit_cancel);
    SetHiliteHandler(MENU_ID_VDOEDT_INPUT_METHOD, mmi_vdoedt_hilight_text_sel_inp_method);
    SetHiliteHandler(MENU_ID_VDOEDT_TEXT_E4R_DONE, mmi_vdoedt_hilight_text_edit_done);
    SetHiliteHandler(MENU_ID_VDOEDT_TEXT_E4R_CANCEL, mmi_vdoedt_hilight_text_edit_cancel);
    SetHiliteHandler(MENU_ID_VDOEDT_TEXT_E4R_INPUT_METHOD, mmi_vdoedt_hilight_text_sel_inp_method);
    SetHiliteHandler(MENU_ID_VDOEDT_2_PHONE, mmi_vdoedt_hilight_2phone);
    SetHiliteHandler(MENU_ID_VDOEDT_2_CARD, mmi_vdoedt_hilight_2card);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_init_key_objs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_init_key_objs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    S32 i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.lsk.pressed = FALSE;
    g_vdoedt_key_cntx.rsk.pressed = FALSE;
    g_vdoedt_key_cntx.ck.pressed = FALSE;

    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_CUT_BAR_BG,
        &g_vdoedt_cut_osd_cntx.cutbar.bg.width,
        &g_vdoedt_cut_osd_cntx.cutbar.bg.height);

    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_EDITBAR_BG,
        &g_vdoedt_main_osd_cntx.editbar.bg.width,
        &g_vdoedt_main_osd_cntx.editbar.bg.height);
    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_EDITBAR_HILIGHT,
        &g_vdoedt_main_osd_cntx.editbar.fill.width,
        &g_vdoedt_main_osd_cntx.editbar.fill.height);
    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_PROGRESS_BAR_BG,
        &g_vdoedt_main_osd_cntx.progress.empty.width,
        &g_vdoedt_main_osd_cntx.progress.empty.height);
    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_CUT_IN,
        &g_vdoedt_cut_osd_cntx.cutbar.in.w,
        &g_vdoedt_cut_osd_cntx.cutbar.in.h);
    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_CUT_OUT,
        &g_vdoedt_cut_osd_cntx.cutbar.out.w,
        &g_vdoedt_cut_osd_cntx.cutbar.out.h);

#ifdef __MMI_TOUCH_SCREEN__
    g_vdoedt_key_cntx.lsk.x = g_vdoedt_main_osd_cntx.softkey.icon_lsk_pos.offset_x;
    g_vdoedt_key_cntx.lsk.y = g_vdoedt_main_osd_cntx.softkey.icon_lsk_pos.offset_y;
    g_vdoedt_key_cntx.rsk.x = g_vdoedt_main_osd_cntx.softkey.icon_rsk_pos.offset_x;
    g_vdoedt_key_cntx.rsk.y = g_vdoedt_main_osd_cntx.softkey.icon_rsk_pos.offset_y;
    g_vdoedt_key_cntx.ck.x = g_vdoedt_main_osd_cntx.softkey.icon_ck_pos.offset_x;
    g_vdoedt_key_cntx.ck.y = g_vdoedt_main_osd_cntx.softkey.icon_ck_pos.offset_y;
    g_vdoedt_key_cntx.pbar.x = g_vdoedt_main_osd_cntx.progress.empty.offset_x;
    g_vdoedt_key_cntx.pbar.y = g_vdoedt_main_osd_cntx.progress.empty.offset_y;
    gdi_image_get_dimension_id(IMG_ID_VDOEDT_PROGRESS_BAR_BG, &g_vdoedt_key_cntx.pbar.w, &g_vdoedt_key_cntx.pbar.h);
    g_vdoedt_key_cntx.ebar.x = g_vdoedt_main_osd_cntx.editbar.bg.offset_x;
    g_vdoedt_key_cntx.ebar.y = g_vdoedt_main_osd_cntx.editbar.bg.offset_y;
    gdi_image_get_dimension_id(IMG_ID_VDOEDT_EDITBAR_BG, &g_vdoedt_key_cntx.ebar.w, &g_vdoedt_key_cntx.ebar.h);
    for (i = 0; i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
    {
        g_vdoedt_key_cntx.shot[i].x = g_vdoedt_key_cntx.ebar.x + g_vdoedt_main_osd_cntx.editbar.shot[i].offset_x;
        g_vdoedt_key_cntx.shot[i].y = g_vdoedt_key_cntx.ebar.y + g_vdoedt_main_osd_cntx.editbar.shot[i].offset_y;
        g_vdoedt_key_cntx.shot[i].w = g_vdoedt_main_osd_cntx.editbar.shot[i].width;
        /* use height of edit bar */
        g_vdoedt_key_cntx.shot[i].h = g_vdoedt_key_cntx.ebar.h;
    }
    /* cut screen */
    g_vdoedt_key_cntx.cut_in.x = g_vdoedt_cut_osd_cntx.cutbar.in.x;
    g_vdoedt_key_cntx.cut_in.y = g_vdoedt_cut_osd_cntx.cutbar.in.y;
    g_vdoedt_key_cntx.cut_in.w = g_vdoedt_cut_osd_cntx.cutbar.in.w;
    g_vdoedt_key_cntx.cut_in.h = g_vdoedt_cut_osd_cntx.cutbar.in.h;
    g_vdoedt_key_cntx.cut_out.x = g_vdoedt_cut_osd_cntx.cutbar.out.x;
    g_vdoedt_key_cntx.cut_out.y = g_vdoedt_cut_osd_cntx.cutbar.out.y;
    g_vdoedt_key_cntx.cut_out.w = g_vdoedt_cut_osd_cntx.cutbar.out.w;
    g_vdoedt_key_cntx.cut_out.h = g_vdoedt_cut_osd_cntx.cutbar.out.h;
    g_vdoedt_key_cntx.cbar.x = g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x;
    g_vdoedt_key_cntx.cbar.y = g_vdoedt_cut_osd_cntx.cutbar.bg.offset_y;
    g_vdoedt_key_cntx.cbar.w = g_vdoedt_cut_osd_cntx.cutbar.bg.width;
    g_vdoedt_key_cntx.cbar.h = g_vdoedt_cut_osd_cntx.cutbar.bg.height;

    g_vdoedt_key_cntx.in_lak.x = g_vdoedt_cut_osd_cntx.cutbar.in_lak.offset_x;
    g_vdoedt_key_cntx.in_lak.y = g_vdoedt_cut_osd_cntx.cutbar.in_lak.offset_y;
    g_vdoedt_key_cntx.in_rak.x = g_vdoedt_cut_osd_cntx.cutbar.in_rak.offset_x;
    g_vdoedt_key_cntx.in_rak.y = g_vdoedt_cut_osd_cntx.cutbar.in_rak.offset_y;
    gdi_image_get_dimension_id(IMG_ID_VDOEDT_ARROW_L, &g_vdoedt_key_cntx.in_lak.w, &g_vdoedt_key_cntx.in_lak.h);
    gdi_image_get_dimension_id(IMG_ID_VDOEDT_ARROW_R, &g_vdoedt_key_cntx.in_rak.w, &g_vdoedt_key_cntx.in_rak.h);
    g_vdoedt_key_cntx.out_lak.w = g_vdoedt_key_cntx.in_lak.w;
    g_vdoedt_key_cntx.out_lak.h = g_vdoedt_key_cntx.in_lak.h;
    g_vdoedt_key_cntx.out_rak.w = g_vdoedt_key_cntx.in_rak.w;
    g_vdoedt_key_cntx.out_rak.h = g_vdoedt_key_cntx.in_rak.h;
    g_vdoedt_key_cntx.out_lak.x = g_vdoedt_cut_osd_cntx.cutbar.out_lak.offset_x;
    g_vdoedt_key_cntx.out_lak.y = g_vdoedt_cut_osd_cntx.cutbar.out_lak.offset_y;
    g_vdoedt_key_cntx.out_rak.x = g_vdoedt_cut_osd_cntx.cutbar.out_rak.offset_x;
    g_vdoedt_key_cntx.out_rak.y = g_vdoedt_cut_osd_cntx.cutbar.out_rak.offset_y;

    gdi_image_get_dimension_id(
        IMG_ID_VDOEDT_FRMSEL_LAK,
        &g_vdoedt_key_cntx.frame_pre.w,
        &g_vdoedt_key_cntx.frame_pre.h);
    g_vdoedt_key_cntx.frame_n.w = g_vdoedt_key_cntx.frame_pre.w;
    g_vdoedt_key_cntx.frame_n.h = g_vdoedt_key_cntx.frame_pre.h;
    g_vdoedt_key_cntx.frame_n.x = g_vdoedt_frm_sel_osd_cntx.next.offset_x;
    g_vdoedt_key_cntx.frame_n.y = g_vdoedt_frm_sel_osd_cntx.next.offset_y;
    g_vdoedt_key_cntx.frame_pre.x = g_vdoedt_frm_sel_osd_cntx.prev.offset_x;
    g_vdoedt_key_cntx.frame_pre.y = g_vdoedt_frm_sel_osd_cntx.prev.offset_y;
    /* ff/rw key */
    g_vdoedt_key_cntx.ffk.x = g_vdoedt_main_osd_cntx.progress.seek_forward.offset_x;
    g_vdoedt_key_cntx.ffk.y = g_vdoedt_main_osd_cntx.progress.seek_forward.offset_y;
    g_vdoedt_key_cntx.rwk.x = g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_x;
    g_vdoedt_key_cntx.rwk.y = g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_y;
    gdi_image_get_dimension_id(IMG_ID_VDOEDT_FF, &g_vdoedt_key_cntx.ffk.w, &g_vdoedt_key_cntx.ffk.h);
    g_vdoedt_key_cntx.rwk.w = g_vdoedt_key_cntx.ffk.w;
    g_vdoedt_key_cntx.rwk.h = g_vdoedt_key_cntx.ffk.h;
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_app
 * DESCRIPTION
 *  initialize video editor global context, Hilight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Check USB                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        if (mmi_usb_check_path_exported((PS8) L"root"))
        {
            mmi_usb_app_unavailable_popup(0);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    /*----------------------------------------------------------------*/
    /* Reset Context.                                                 */
    /*----------------------------------------------------------------*/
    memset((void*)&g_vdoedt_cntx, 0, sizeof(vdoedt_context_struct));

    /*----------------------------------------------------------------*/
    /* Create temp folder                                             */
    /*----------------------------------------------------------------*/
    i = mmi_vdoedt_create_tmpdir();
    if (i < FS_NO_ERROR)
    {
        if (FS_ROOT_DIR_FULL == i)
        {
            mmi_vdoedt_popup(FMGR_FS_ROOT_DIR_FULL_TEXT);
        }
        else
        {
            mmi_vdoedt_popup(STR_ID_VDOEDT_CREATE_DIR_FAIL);
        }
        return;
    }

    /*----------------------------------------------------------------*/
    /* Allocate memory for shots                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VDOEDT_USE_APPMEM__
    /* allocate appmem and init shot mem */
    g_vdoedt_cntx.p_shot_mem[0] =
        (p_vdoedt_shot_struct) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_VDOEDT, MMI_VDOEDT_APPMEM_POOL_SIZE);
    if (g_vdoedt_cntx.p_shot_mem[0] == NULL)
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_VDOEDT,
            IMG_ID_VDOEDT_MAIN_ICON,
            MMI_VDOEDT_APPMEM_POOL_SIZE,
            mmi_vdoedt_entry_app);

        return;
    }
    memset((void*)g_vdoedt_cntx.p_shot_mem[0], 0, sizeof(vdoedt_shot_struct) * 5);
    for (i = 1; i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
    {
        g_vdoedt_cntx.p_shot_mem[i] = (g_vdoedt_cntx.p_shot_mem[0] + i);
    }

#else /* __MMI_VDOEDT_USE_APPMEM__ */ 
    memset((void*)&g_vdoedt_cntx.shot_mem, 0, sizeof(vdoedt_shot_struct) * 5);
    for (i = 0; i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
    {
        g_vdoedt_cntx.p_shot_mem[i] = g_vdoedt_cntx.shot_mem[i];
    }
#endif /* __MMI_VDOEDT_USE_APPMEM__ */ 

        /*----------------------------------------------------------------*/
        /* init video edt context                                         */
        /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
        if (mdi_video_edt_init() != MED_RES_OK)
        {
            mmi_vdoedt_popup(STR_GLOBAL_ERROR);
        #ifdef __MMI_VDOEDT_USE_APPMEM__
            if (g_vdoedt_cntx.p_shot_mem[0] != NULL)
            {
                mmi_vdoedt_free_appmem();
            }
        #endif /* __MMI_VDOEDT_USE_APPMEM__ */
            return;
        }
#endif /* __MTK_TARGET__ */



    /* warning! double check if u wanna exit application here. (if you are using APPMEM) */


    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EMPTY);
    g_vdoedt_cntx.a_volume = MMI_VDOEDT_DEFAULT_AUIDO_VOL;

    mmi_vdoedt_remov_cachefile();
    mmi_vdoedt_entry_main_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_main_screen
 * DESCRIPTION
 *  the entry_function of vdoeditor. decide what to do
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_entry_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    p_vdoedt_context_struct p_cntx = &g_vdoedt_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_MAIN, mmi_vdoedt_exit_main_screen, mmi_vdoedt_entry_main_screen, MMI_FULL_SCREEN);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_MAIN);

    /*----------------------------------------------------------------*/
    /* Create layers & init                                           */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_util_suspend_bg_audio();
    entry_full_screen();
    gdi_layer_multi_layer_enable();

    mmi_vdoedt_util_create_layers(MMI_VDOEDT_LAYER_ALL);
    gdi_layer_set_blt_layer_ext(
        p_cntx->h_osd,
        p_cntx->h_play,
        p_cntx->h_frmtxt,
        p_cntx->h_effect,
        p_cntx->h_keyframe,
        0);
    /*----------------------------------------------------------------*/
    /* draw items                                                     */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_ALL;
    mmi_vdoedt_redraw();

    /*----------------------------------------------------------------*/
    /* set key, touch, callback handlers                              */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_util_set_key_handlers(SCR_ID_VDOEDT_MAIN);
    SetDelScrnIDCallbackHandler(SCR_ID_VDOEDT_MAIN, mmi_vdoedt_del_main_callback_hdlr);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_vdoedt_util_set_touch_hdlr();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_null_screen
 * DESCRIPTION
 *  a null screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_exit_null_screen(void)
{

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_del_main_callback_hdlr
 * DESCRIPTION
 *  delete screen callback handler
 * PARAMETERS
 *  ptr     [IN]    not used
 * RETURNS
 *  FALSE       screen can be deleted without blocking.
 * BOOL
 *****************************************************************************/
U8 mmi_vdoedt_del_main_callback_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry a empty screen to avoid video is closed by other screen which is not under control of video editor */
    EntryNewScreen(SCR_ID_VDOEDT_NULL_SCREEN, mmi_vdoedt_exit_null_screen, 0, NULL);
    
    if (MMI_VDOEDT_S_SEEK_UPDATING == stat || MMI_VDOEDT_S_PLAY_SEEK_UPDATING == stat)
    {
        if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
        {
            mdi_video_ply_stop_non_block_seek();
            mdi_video_edt_deactive();
        }
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW);
    }
    else
    {
        mmi_vdoedt_play_stop();
        gui_cancel_timer(mmi_vdoedt_seek_ff);
        gui_cancel_timer(mmi_vdoedt_seek_rw);
        gui_cancel_timer(mmi_vdoedt_play_shot_updater);
    }
    
    /*----------------------------------------------------------------*/
    /* Close video files                                              */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_vdoedt_cntx.shot_count; i++)
    {
        if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[i]->src_type)
        {
            if (g_vdoedt_cntx.p_shot[i]->h_video)
            {
                mdi_video_edt_close_clip_file(g_vdoedt_cntx.p_shot[i]->h_video);
            }
        }
    }

    /*----------------------------------------------------------------*/
    /* Clear cache files/tmp folder                                   */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_remov_cachefile();
    mmi_vdoedt_remov_tmpdir();

    /*----------------------------------------------------------------*/
    /* other deinits                                                  */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__    
    mdi_video_edt_deinit();
#endif /* __MTK_TARGET__ */

#ifdef __MMI_VDOEDT_USE_APPMEM__
    mmi_vdoedt_free_appmem();
#endif 

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_main_screen
 * DESCRIPTION
 *  the entry_function of vdoeditor. decide what to do
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_exit_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle h_base;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* stop playing/timers                                            */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_SEEK_UPDATING == stat || MMI_VDOEDT_S_PLAY_SEEK_UPDATING == stat)
    {
        if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
        {
            mdi_video_ply_stop_non_block_seek();
            mdi_video_edt_deactive();
        }
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW);
    }
    else
    {
        mmi_vdoedt_play_stop();
        gui_cancel_timer(mmi_vdoedt_seek_ff);
        gui_cancel_timer(mmi_vdoedt_seek_rw);
        gui_cancel_timer(mmi_vdoedt_play_shot_updater);
        gui_cancel_timer(mmi_vdoedt_update_seek_frame);
        if (stat == MMI_VDOEDT_S_SEEK ||
            stat == MMI_VDOEDT_S_PLAY_SEEK ||
            stat == MMI_VDOEDT_S_SEEK_DONE ||stat == MMI_VDOEDT_S_PLAY_SEEK_DONE)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW);
            g_vdoedt_cntx.time_now = 0;
            g_vdoedt_key_cntx.ffk.pressed  = g_vdoedt_key_cntx.rwk.pressed = FALSE;
        }
    }

    /*----------------------------------------------------------------*/
    /* restore layer setting                                          */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_util_free_layers();
    gdi_layer_multi_layer_disable();
    gdi_layer_get_base_handle(&h_base);
    gdi_layer_set_blt_layer(h_base, 0, 0, 0);

    mmi_vdoedt_util_resume_bg_audio();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_empty_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_empty_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_EMPTY_OPION, 0, mmi_vdoedt_entry_empty_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_EMPTY_OPION);
    mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_INS_VDO);
    mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_INS_IMG);
    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_MAIN_EMPTY_OPTION, STR_GLOBAL_OPTIONS, gui_buffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_video_sel
 * DESCRIPTION
 *  entry filemanager for video file selecting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_entry_video_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__

    PopupNoSupport();
    return;

#else /* __MTK_TARGET__ */

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_VIDEO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_VDOEDT,
        FMGR_SELECT_FILE,
        filter,
        (PS8) (S8*) L"root",
        (PsExtFuncPtr) mmi_vdoedt_media_sel_result_callback);
#endif /* __MTK_TARGET__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_media_sel_result_callback
 * DESCRIPTION
 *  file sel result callback
 * PARAMETERS
 *  filepath        [IN]        File path of selected file.
 *  is_short        [IN]        Is short filename
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_media_sel_result_callback(void *filepath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 imgtype;
    FMGR_FILTER ftype;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath == NULL)
    {
        GoBackHistory();
    }
    else
    {
    #ifdef __DRM_SUPPORT__
        if (DRM_METHOD_NONE != DRM_get_object_method(0, (PU16)filepath))
        {
            mmi_vdoedt_popup(STR_GLOBAL_DRM_PROHIBITED);
            return;
        }
    #endif /* __DRM_SUPPORT__ */ 
        mmi_fmgr_get_file_type(filepath, &ftype);
        if (FMGR_FILTER_IS_SET_IMAGE(&ftype))
        {
            imgtype = gdi_image_get_type_from_file(filepath);
            if (imgtype == GDI_IMAGE_TYPE_JPG_FILE ||
                imgtype == GDI_IMAGE_TYPE_PNG_FILE ||
                imgtype == GDI_IMAGE_TYPE_INVALID)
            {
                mmi_fmgr_util_store_filepath(filepath, FMGR_PATH_ID_VIDEO_EDITOR);
                mmi_vdoedt_entry_media_preview_scr();
            }
            else
            {
                mmi_vdoedt_popup(STR_FMGR_INVALID_FORMAT);
            }
        }
        else
        {
            mmi_fmgr_util_store_filepath(filepath, FMGR_PATH_ID_VIDEO_EDITOR);
            mmi_vdoedt_entry_media_preview_scr();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_vdo_ins_preview_res_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_vdo_ins_preview_res_callback(MDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        DisableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        mmi_vdoedt_popup(STR_ID_VDOEDT_INVALID_VDO);
        DeleteScreenIfPresent(SCR_ID_VDOEDT_MEDIA_PREVIEW);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_decode_result_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_decode_result_callback(GDI_RESULT res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res == GDI_SUCCEED)
    {
        SetLeftSoftkeyFunction(mmi_vdoedt_img_do_insert_file, KEY_EVENT_UP);
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_media_preview_scr
 * DESCRIPTION
 *  exit function preview screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_exit_media_preview_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOffBacklight();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_media_preview_scr
 * DESCRIPTION
 *  preview screen of selected video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void mmi_vdoedt_entry_media_preview_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    FMGR_FILTER ftype;
    U16 id_err_str = 0;                         /* error string */
    mdi_video_info_struct v_info;
    U16 img_lsk = IMG_GLOBAL_OK;
    U16 str_lsk = STR_GLOBAL_OK;
    S8 fname[FMGR_MAX_PATH_LEN << 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_MEDIA_PREVIEW, mmi_vdoedt_exit_media_preview_scr, mmi_vdoedt_entry_media_preview_scr, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_MEDIA_PREVIEW);
    
    TurnOnBacklight(0);     /* prevent backlight being turned off */

    mmi_fmgr_util_load_filepath(fname, FMGR_PATH_ID_VIDEO_EDITOR);
    mmi_fmgr_get_file_type(fname, &ftype);
   
    if (FMGR_FILTER_IS_SET_VIDEO(&ftype))
    {
        /* open file first, check if the duration is exist. */
        if (MDI_RES_VDOPLY_SUCCEED == mdi_video_edt_open_clip_file(fname, &v_info))
        {
            mdi_video_edt_close_clip_file(v_info.handle);
            /* block by video length and video resolution */
            if (v_info.total_time_duration < MMI_VDOEDT_INS_VDO_MIN_DUR)
            {
                id_err_str = STR_ID_VDOEDT_ERR_TOO_SHORT;
            }
            else if (v_info.total_time_duration > MMI_VDOEDT_INS_VDO_MAX_DUR)
            {
                id_err_str = STR_ID_VDOEDT_ERR_TOO_LONG;
            }
            else if (v_info.width  > MMI_VDOEDT_VDO_WIDTH ||
                     v_info.height > MMI_VDOEDT_VDO_HEIGHT)
            {
                id_err_str = STR_ID_VDOEDT_ERR_RESOLUTION;
            }

        }
        else
        {
            id_err_str = STR_ID_VDOEDT_ERR_UNSUP_FORMAT;
        }

        if (0 != id_err_str)
        {
           ShowCategory221Screen(
                STR_ID_VDOEDT_PREVIEW,
                GetRootTitleIcon(MENU_ID_VDOEDT_APP),
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                GDI_COLOR_WHITE,
                NULL);
           SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
           mmi_vdoedt_popup(id_err_str);
           DeleteScreenIfPresent(SCR_ID_VDOEDT_MEDIA_PREVIEW);
           return;
        }
        else
        {
            ShowCategory225Screen(
                STR_ID_VDOEDT_PREVIEW,
                GetRootTitleIcon(MENU_ID_VDOEDT_APP),
                img_lsk,
                str_lsk,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                0,
                fname,
                1,
                TRUE,
                TRUE,
                FALSE,
                GDI_COLOR_WHITE,
                mmi_vdoedt_vdo_ins_preview_res_callback,
                gui_buffer);
            SetLeftSoftkeyFunction(mmi_vdoedt_video_do_insert, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoedt_vol_inc, KEY_VOL_UP, KEY_EVENT_UP);
            SetKeyHandler(mmi_vdoedt_vol_dec, KEY_VOL_DOWN, KEY_EVENT_UP);
        }
    }
    else if(FMGR_FILTER_IS_SET_IMAGE(&ftype))
    {
        /* the image type should be checked before entry this screen */
        ShowCategory222Screen(
            STR_ID_VDOEDT_PREVIEW,
            GetRootTitleIcon(MENU_ID_VDOEDT_APP),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            GDI_COLOR_WHITE,
            0,
            fname,
            FALSE,
            mmi_vdoedt_img_decode_result_callback,
            GDI_IMAGE_SRC_FROM_FILE);
    }
    else
    {
        GoBackHistory();
        return;
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_frame_select_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_frame_select_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VDOEDT_FRAME_PREVIEW,
        mmi_vdoedt_exit_frame_select_scr,
        mmi_vdoedt_entry_frame_select_scr,
        NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FRAME_PREVIEW);

    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME_SEL);
    /*----------------------------------------------------------------*/
    /* create layers                                                  */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    gdi_layer_multi_layer_enable();
    gdi_layer_get_base_handle(&g_vdoedt_cntx.h_osd);
    gdi_layer_create(
        g_vdoedt_frm_sel_osd_cntx.play.offset_x,
        g_vdoedt_frm_sel_osd_cntx.play.offset_y,
        g_vdoedt_frm_sel_osd_cntx.play.width,
        g_vdoedt_frm_sel_osd_cntx.play.height,
        &g_vdoedt_cntx.h_play);
    g_vdoedt_cntx.p_scrmem = (PU8) mmi_frm_scrmem_alloc(MMI_VDOEDT_PREV_BUF_SIZE);
    ASSERT(g_vdoedt_cntx.p_scrmem != NULL);
    gdi_layer_create_using_outside_memory(
        g_vdoedt_frm_sel_osd_cntx.play.offset_x,
        g_vdoedt_frm_sel_osd_cntx.play.offset_y,
        g_vdoedt_frm_sel_osd_cntx.play.width,
        g_vdoedt_frm_sel_osd_cntx.play.height,
        &g_vdoedt_cntx.h_frmtxt,
        g_vdoedt_cntx.p_scrmem,
        MMI_VDOEDT_PREV_BUF_SIZE);
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_frmtxt);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_blt_layer(g_vdoedt_cntx.h_osd, g_vdoedt_cntx.h_play, g_vdoedt_cntx.h_frmtxt, 0);

    if(gui_buffer == NULL)
    {
        g_vdoedt_cntx.old_s5g[0] = 
            g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->choosed_frame ? (g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->choosed_frame - IMG_ID_VDOEDT_FRAME1 + 1): 0;
    }
    mmi_vdoedt_util_set_key_handlers(SCR_ID_VDOEDT_FRAME_PREVIEW);
    
    g_vdoedt_cntx.flg_frm_sel_r4w = MMI_VDOEDT_R4W_ALL;
    mmi_vdoedt_redraw();

#ifdef __MMI_TOUCH_SCREEN__
    mmi_vdoedt_util_set_touch_hdlr();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_frame_select_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_exit_frame_select_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE != g_vdoedt_cntx.h_frmtxt)
    {
        gdi_layer_free(g_vdoedt_cntx.h_frmtxt);
        g_vdoedt_cntx.h_frmtxt = GDI_NULL_HANDLE;
    }
    if (GDI_NULL_HANDLE != g_vdoedt_cntx.h_play)
    {
        gdi_layer_free(g_vdoedt_cntx.h_play);
        g_vdoedt_cntx.h_play = GDI_NULL_HANDLE;
    }
    if (g_vdoedt_cntx.p_scrmem)
    {
        mmi_frm_scrmem_free(g_vdoedt_cntx.p_scrmem);
        g_vdoedt_cntx.p_scrmem = NULL;
    }

    gdi_layer_set_blt_layer(g_vdoedt_cntx.h_osd, 0, 0, 0);
    gdi_layer_multi_layer_disable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frm_sel_restore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frm_sel_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frm_sel_rak_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frm_sel_rak_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.frame_n.pressed = FALSE;
    /* 0~5, 0 is no frame */
    g_vdoedt_cntx.old_s5g[0] = (g_vdoedt_cntx.old_s5g[0] +1) % (MMI_VDOEDT_FRAME_STY_CNT + 1);

    g_vdoedt_cntx.flg_frm_sel_r4w |= MMI_VDOEDT_R4W_FRAME | MMI_VDOEDT_R4W_FRM_SEL_BTN;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frm_sel_lak_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frm_sel_lak_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.frame_pre.pressed = FALSE;
    if (g_vdoedt_cntx.old_s5g[0] == 0)
    {
        g_vdoedt_cntx.old_s5g[0] = MMI_VDOEDT_FRAME_STY_CNT;
    }
    else
    {
        g_vdoedt_cntx.old_s5g[0]--;
    }

    /* error check */
    if (g_vdoedt_cntx.old_s5g[0] > MMI_VDOEDT_FRAME_STY_CNT)
    {
        g_vdoedt_cntx.old_s5g[0] = MMI_VDOEDT_FRAME_STY_CNT;
    }
        
    g_vdoedt_cntx.flg_frm_sel_r4w |= MMI_VDOEDT_R4W_FRAME | MMI_VDOEDT_R4W_FRM_SEL_BTN;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frm_sel_rak_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frm_sel_rak_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.frame_n.pressed = TRUE;
    g_vdoedt_cntx.flg_frm_sel_r4w |= MMI_VDOEDT_R4W_FRM_SEL_BTN;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frm_sel_lak_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frm_sel_lak_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.frame_pre.pressed = TRUE;
    g_vdoedt_cntx.flg_frm_sel_r4w |= MMI_VDOEDT_R4W_FRM_SEL_BTN;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_vol_inc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_vol_inc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.a_volume < MDI_MAX_VOLUME_LEVEL - 1)
    {
        mdi_audio_set_volume((U8) VOL_TYPE_MEDIA, ++g_vdoedt_cntx.a_volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_vol_dec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_vol_dec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.a_volume > 0)
    {
        mdi_audio_set_volume((U8) VOL_TYPE_MEDIA, --g_vdoedt_cntx.a_volume);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_frame_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_frame_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot->ms_frm_in = p_shot->ms_cut_in;
    p_shot->ms_frm_out = p_shot->ms_cut_out;
    p_shot->choosed_frame = 0;
    memset((void*)p_shot->p_txt, 0, 20 * ENCODING_LENGTH);
    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_get_stat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
vdoedt_state_enum mmi_vdoedt_get_stat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vdoedt_cntx.state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enter_stat
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enter_stat(vdoedt_state_enum new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.old_state = g_vdoedt_cntx.state;
    g_vdoedt_cntx.state = new_state;

    if (MMI_VDOEDT_S_EDIT == new_state)
    {
        g_vdoedt_cntx.time_now = 0;
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_PWIN | MMI_VDOEDT_R4W_SKEY;
        if (GDI_NULL_HANDLE != g_vdoedt_cntx.h_effect)
        {
            /* hide effect layer when back from preview. */
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
            gdi_layer_set_opacity(TRUE, 0);
            gdi_layer_pop_and_restore_active();
        }
        
    }
    else if (MMI_VDOEDT_S_PREVIEW == new_state)
    {
        g_vdoedt_cntx.time_now = 0; /* for seek */
        g_vdoedt_cntx.i_act_shot = 0;
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_EBAR | MMI_VDOEDT_R4W_PWIN | MMI_VDOEDT_R4W_SKEY;
        
    }
    else if (MMI_VDOEDT_S_EDIT_FRAME <= new_state && MMI_VDOEDT_S_EDIT_CUT_OUT >= new_state)
    {
        g_vdoedt_key_cntx.cut_in.pressed = FALSE;
        g_vdoedt_key_cntx.cut_out.pressed = FALSE;
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_EBAR | MMI_VDOEDT_R4W_IN_BTN | MMI_VDOEDT_R4W_OUT_BTN | MMI_VDOEDT_R4W_SKEY;        
        if (MMI_VDOEDT_S_EDIT_CUT_IN == new_state || MMI_VDOEDT_S_EDIT_FRAME_IN == new_state)
        {
            g_vdoedt_key_cntx.cut_in.pressed = TRUE;
            mmi_vdoedt_update_cut_preview();
        }
        else if (MMI_VDOEDT_S_EDIT_CUT_OUT == new_state || MMI_VDOEDT_S_EDIT_FRAME_OUT == new_state)
        {
            g_vdoedt_key_cntx.cut_out.pressed = TRUE;
            mmi_vdoedt_update_cut_preview();            
        }
    }

#if 1
    /* trace message */
    switch (new_state)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 
        case MMI_VDOEDT_S_EMPTY:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EMPTY);
            break;
        case MMI_VDOEDT_S_EDIT:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT);
            break;
        case MMI_VDOEDT_S_EDIT_IDLE:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_IDLE);
            break;
        case MMI_VDOEDT_S_EDIT_FRAME:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_FRAME);
            break;

        case MMI_VDOEDT_S_EDIT_FRAME_SEL:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_FRAME_SEL);
            break;

        case MMI_VDOEDT_S_EDIT_FRAME_IN:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_FRAME_IN);
            break;

        case MMI_VDOEDT_S_EDIT_FRAME_OUT:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_FRAME_OUT);
            break;

        case MMI_VDOEDT_S_EDIT_FRAME_TXT:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_FRAME_TXT);
            break;

        case MMI_VDOEDT_S_EDIT_CUT:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_CUT);
            break;

        case MMI_VDOEDT_S_EDIT_CUT_IN:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_CUT_IN);
            break;

        case MMI_VDOEDT_S_EDIT_CUT_OUT:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_CUT_OUT);
            break;

        case MMI_VDOEDT_S_PLAY:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_PLAY);
            break;

        case MMI_VDOEDT_S_PREVIEW_PLAY:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_PREVIEW_PLAY);
            break;

        case MMI_VDOEDT_S_EDIT_PLAY:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_EDIT_PLAY);
            break;

        case MMI_VDOEDT_S_CUT_PLAY:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_CUT_PLAY);
            break;

        case MMI_VDOEDT_S_FRM_PLAY:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_FRM_PLAY);
            break;

        case MMI_VDOEDT_S_SEEK:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_SEEK);
            break;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */ 

        case MMI_VDOEDT_S_SEEK_DONE:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_SEEK_DONE);
            break;

        case MMI_VDOEDT_S_PLAY_SEEK:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_PLAY_SEEK);
            break;

        case MMI_VDOEDT_S_PLAY_SEEK_DONE:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_PLAY_SEEK_DONE);
            break;

        case MMI_VDOEDT_S_PREVIEW:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_PREVIEW);
            break;

        case MMI_VDOEDT_S_SAVING:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_SAVING);
            break;

        case MMI_VDOEDT_S_CONFIRM_SAVE:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_TRC_VDOEDT_S_CONFIRM_SAVE);
            break;

        default:
            break;
    }

#endif /* 1 */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_redraw
 * DESCRIPTION
 *  control the redraw of all screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 flag = NULL;
    U16 scrid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scrid = GetActiveScreenId();
    /* main screen */
    if (SCR_ID_VDOEDT_MAIN == scrid)
    {
        flag = &g_vdoedt_cntx.flg_main_r4w;
        if (*flag)
        {
            mmi_vdoedt_redraw_main_scr(*flag);
        }
    }
    else if (SCR_ID_VDOEDT_VIDEO_CUT == scrid || SCR_ID_VDOEDT_FRAME_EDIT == scrid)
    {
        flag = &g_vdoedt_cntx.flg_cut_r4w;
        if (*flag)
        {
            mmi_vdoedt_redraw_cut_scr(*flag);
        }
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == scrid)
    {
        flag = &g_vdoedt_cntx.flg_frm_sel_r4w;
        if (*flag)
        {
            mmi_vdoedt_redraw_frm_sel_scr(*flag);
        }
    }

    if (flag != NULL)
    {
        *flag &= MMI_VDOEDT_R4W_NONE;
    }
    /* other screens */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_redraw_main_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_redraw_main_scr(U8 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 ms_offset = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_osd);

    /* background */
    if (item & MMI_VDOEDT_R4W_BG)
    {
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.bg.offset_x,
            g_vdoedt_main_osd_cntx.bg.offset_y,
            IMG_ID_VDOEDT_EDIT_BG);
        mmi_vdoedt_draw_title(STR_ID_VDOEDT_APP);
    }
    /* play time                        */
    if (item & MMI_VDOEDT_R4W_TIME)
    {
        mmi_vdoedt_draw_time(g_vdoedt_cntx.time_now);
    }
    /* progress bar                     */
    if (item & MMI_VDOEDT_R4W_PBAR)
    {
        mmi_vdoedt_draw_main_pbar(g_vdoedt_cntx.time_now, g_vdoedt_cntx.ms_t_total);
        /* draw key too */
        mmi_vdoedt_draw_seek_keys();
    }

    /* draw softkey     */
    if (item & MMI_VDOEDT_R4W_SKEY)
    {
        mmi_vdoedt_draw_softkey(GetString(STR_GLOBAL_OPTIONS), GetString(STR_ID_VDOEDT_EXIT), TRUE);
    }

    /* edit bar         */
    if (item & MMI_VDOEDT_R4W_EBAR)
    {
        mmi_vdoedt_draw_ebar();
    }
    if (item & MMI_VDOEDT_R4W_KEYFRMS)
    {
        mmi_vdoedt_draw_ebar_keyframes();
    }
    /* status icons     */
    if (item & MMI_VDOEDT_R4W_STAT)
    {
        mmi_vdoedt_draw_stat();
    }
    /* preview window   */
    if (item & MMI_VDOEDT_R4W_PWIN)
    {
        mmi_vdoedt_draw_preview();
        
        if (MMI_VDOEDT_S_EMPTY != mmi_vdoedt_get_stat() && (g_vdoedt_cntx.i_act_shot < g_vdoedt_cntx.shot_count))
        {
            ms_offset = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_in;
        }
        else
        {
            ms_offset = 0;
        }
        mmi_vdoedt_draw_frametxt(ms_offset);
        mmi_vdoedt_effect_set(g_vdoedt_cntx.i_act_shot, 0);
    }

    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_frametxt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [IN]        Offset from start of original video
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_frametxt(U64 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;
    vdoedt_state_enum stat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE != g_vdoedt_cntx.h_frmtxt)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_frmtxt);
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        if (g_vdoedt_cntx.shot_count && g_vdoedt_cntx.i_act_shot < g_vdoedt_cntx.shot_count)
        {
            stat = mmi_vdoedt_get_stat();
            p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

            /* prevent the frame is auto updated by LCM, set opacity first. */
            if (time >= p_shot->ms_frm_in && time <= p_shot->ms_frm_out)
            {
                gdi_layer_set_opacity(FALSE, 0);
            }
            else
            {
                gdi_layer_set_opacity(TRUE, 0);
            }
            
            if (p_shot->choosed_frame)
            {
                gdi_image_draw_id(0, 0, p_shot->choosed_frame);
            }
            /* if have text, draw text */
            if (mmi_ucs2strlen(p_shot->p_txt))
            {
                mmi_vdoedt_draw_custom_txt();
            }
        }
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_seek_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_seek_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = IMG_ID_VDOEDT_FF;
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension_id(IMG_ID_VDOEDT_FF_DOWN, &w, &h);
    if (g_vdoedt_main_osd_cntx.progress.seek_forward.is_show)
    {
        /* clear background */
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            g_vdoedt_main_osd_cntx.progress.seek_forward.offset_x,
            g_vdoedt_main_osd_cntx.progress.seek_forward.offset_y,
            g_vdoedt_main_osd_cntx.progress.seek_forward.offset_x + w - 1,
            g_vdoedt_main_osd_cntx.progress.seek_forward.offset_y + h - 1);
        gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_EDIT_BG);
        gdi_layer_pop_clip();
        if (g_vdoedt_key_cntx.ffk.pressed)
        {
            img_id = IMG_ID_VDOEDT_FF_DOWN;
        }
        else
        {
            img_id = IMG_ID_VDOEDT_FF;
        }
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.progress.seek_forward.offset_x,
            g_vdoedt_main_osd_cntx.progress.seek_forward.offset_y,
            img_id);
    }

    if (g_vdoedt_main_osd_cntx.progress.seek_rewind.is_show)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_x,
            g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_y,
            g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_x + w - 1,
            g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_y + h - 1);
        gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_EDIT_BG);
        gdi_layer_pop_clip();
        if (g_vdoedt_key_cntx.rwk.pressed)
        {
            img_id = IMG_ID_VDOEDT_RW_DOWN;
        }
        else
        {
            img_id = IMG_ID_VDOEDT_RW;
        }
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_x,
            g_vdoedt_main_osd_cntx.progress.seek_rewind.offset_y,
            img_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id_str      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_title(U16 id_str)
{
#ifdef __MMI_MAINLCD_240X320__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w, h, x, y, offset_x;
    U16 scrid = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gui_measure_string((UI_string_type) GetString(id_str), &w, &h);
    x = (UI_device_width - w) >> 1;
    if (SCR_ID_VDOEDT_MAIN == scrid)
    {
        offset_x = g_vdoedt_main_osd_cntx.play_wnd.offset_x;
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == scrid)
    {
        offset_x = g_vdoedt_frm_sel_osd_cntx.play.offset_x;
    }
    else
    {
        offset_x = g_vdoedt_cut_osd_cntx.play_wnd.offset_x;
    }
    y = (offset_x - h) >> 1;
    gdi_layer_push_clip();    
    gdi_layer_set_clip(x - 1, y - 1, x + w, y + h);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(x + w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_set_text_border_color(*current_MMI_theme->title_text_border_color);
    gui_print_bordered_text((UI_string_type) GetString(id_str));
    gdi_layer_pop_clip();
    
#endif /* __MMI_MAINLCD_240X320__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_custom_txt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_custom_txt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_w, str_h, x, y;
    vdoedt_shot_struct *p_shot;
    color c;
    stFontAttribute ftype;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* according to text size, color, position to draw custom text */
    if (!g_vdoedt_cntx.shot_count)
    {
        return;
    }
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /* set text size */
    memcpy(&ftype, &MMI_medium_font, sizeof(stFontAttribute));
    if (MMI_VDOEDT_TXT_SIZE_S == p_shot->size_txt)
    {
        ftype.size = SMALL_FONT;
    }
    else if (MMI_VDOEDT_TXT_SIZE_M == p_shot->size_txt)
    {
        ftype.size = MEDIUM_FONT;
    }
    else if (MMI_VDOEDT_TXT_SIZE_L == p_shot->size_txt)
    {
        ftype.size = LARGE_FONT;
    }
    else
    {
        ASSERT(0);
    }
    gui_set_font(&ftype);

    gui_measure_string((UI_string_type) p_shot->p_txt, &str_w, &str_h);

    /* text pos */
    if (MMI_VDOEDT_TXT_ALIGN_TOP == p_shot->text_align)
    {
        y = MMI_VDOEDT_PWIN_BORDER;
    }
    else if (MMI_VDOEDT_TXT_ALIGN_BOTTOM == p_shot->text_align)
    {
        y = g_vdoedt_main_osd_cntx.play_wnd.height - MMI_VDOEDT_PWIN_BORDER - str_h;
    }
    else    /* center */
    {
        y = (g_vdoedt_main_osd_cntx.play_wnd.height - str_h) >> 1;
    }

    x = (g_vdoedt_main_osd_cntx.play_wnd.width - str_w) >> 1;

    if (r2lMMIFlag)
    {
        if (x + str_w > g_vdoedt_main_osd_cntx.play_wnd.width)
        {
            x = g_vdoedt_main_osd_cntx.play_wnd.width;
        }
        gui_move_text_cursor(x + str_w, y);
    }
    else
    {
        gui_move_text_cursor(x, y);
    }
    if (p_shot->i_txt_color)
    {
        c = gui_color(255, 255, 255);
    }
    else
    {
        /* black */
        c = gui_color(0, 0, 0);
    }
    gui_set_text_color(c);
    /* inverse c */
    c = gui_color(~c.r, ~c.g, ~c.b);
    gui_set_text_border_color(c);

    gui_reset_clip();
    gui_reset_text_clip();
    gui_print_bordered_text((UI_string_type) p_shot->p_txt);

    gui_set_font(&MMI_medium_font);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_ebar
 * DESCRIPTION
 *  redraw the preview window.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_ebar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = mmi_vdoedt_get_stat();    

    if (MMI_VDOEDT_S_EDIT == state)
    {
        mmi_vdoedt_draw_shot_hilight(g_vdoedt_cntx.i_act_shot);
    }
    else
    {
        gdi_layer_push_clip();        
        gdi_layer_set_clip(
            g_vdoedt_main_osd_cntx.editbar.fill.offset_x,
            g_vdoedt_main_osd_cntx.editbar.fill.offset_y,
            g_vdoedt_main_osd_cntx.editbar.fill.offset_x + g_vdoedt_main_osd_cntx.editbar.fill.width - 1,
            g_vdoedt_main_osd_cntx.editbar.fill.offset_y + g_vdoedt_main_osd_cntx.editbar.fill.height - 1);
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.bg.offset_x,
            g_vdoedt_main_osd_cntx.bg.offset_y,
            IMG_ID_VDOEDT_EDIT_BG);
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.editbar.bg.offset_x,
            g_vdoedt_main_osd_cntx.editbar.bg.offset_y,
            IMG_ID_VDOEDT_EDITBAR_BG);
        gdi_layer_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_ebar_keyframes
 * DESCRIPTION
 *  draw the keyframes on edit bar.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_ebar_keyframes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_rect_struct *p_shot_rect;
    vdoedt_shot_struct *p_shot;
    S8 fname[40];
    S32 offset_x, offset_y, res_w, res_h;
    S32 i;
    PU8 p_buff, p_resize_dest, p_layer;
    GDI_HANDLE h_tmp_layer;
    gdi_rect_struct clip;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* key frame                                                */
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_keyframe);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_get_buffer_ptr(&p_layer);
    
    for (i = 0; i < g_vdoedt_cntx.shot_count; i++)
    {
        p_shot = g_vdoedt_cntx.p_shot[i];
        p_shot_rect = &g_vdoedt_main_osd_cntx.editbar.shot[i];
        if (VDOEDT_SRC_COLOR != p_shot->src_type)
        {
            mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
            mmi_ucs2cat(fname, p_shot->ustr_fname);
            gdi_image_util_fit_bbox(
                p_shot_rect->width,
                p_shot_rect->height,
                g_vdoedt_main_osd_cntx.play_wnd.width,
                g_vdoedt_main_osd_cntx.play_wnd.height,
                &offset_x,
                &offset_y,
                &res_w,
                &res_h);
        #ifndef __MTK_TARGET__
            gdi_image_draw_resized_file(
                p_shot_rect->offset_x + offset_x,
                p_shot_rect->offset_y + offset_y,
                res_w,
                res_h,
                fname);
        #else
            p_buff = (PU8) mmi_frm_scrmem_alloc(MMI_VDOEDT_PREV_BUF_SIZE);
            p_resize_dest = (PU8) mmi_frm_scrmem_alloc(res_w * res_h*(gdi_act_layer->bits_per_pixel >> 3));
            if(p_buff != NULL && p_resize_dest != NULL);
            {
                clip.x1 = p_shot_rect->offset_x + offset_x;
                clip.y1 = p_shot_rect->offset_y + offset_y;
                clip.x2 = clip.x1 + res_w - 1;
                clip.y2 = clip.y1 + res_h - 1;

                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    g_vdoedt_main_osd_cntx.play_wnd.width,
                    g_vdoedt_main_osd_cntx.play_wnd.height,
                    &h_tmp_layer,
                    p_buff,
                    MMI_VDOEDT_PREV_BUF_SIZE);
                gdi_layer_push_and_set_active(h_tmp_layer);
                gdi_image_draw_file(0,0,fname);
                gdi_layer_pop_and_restore_active();

                gdi_resizer(
                    p_buff,
                    g_vdoedt_main_osd_cntx.play_wnd.width,
                    g_vdoedt_main_osd_cntx.play_wnd.height,
                    g_vdoedt_main_osd_cntx.play_wnd.width,
                    p_resize_dest,
                    res_w,
                    res_h,
                    0,
                    0,
                    res_w - 1,
                    res_h - 1);
                gdi_2d_memory_blt(
                    p_resize_dest,
                    res_w,
                    0,
                    0,
                    res_w,
                    res_h,
                    p_layer,
                    g_vdoedt_main_osd_cntx.editbar.bg.width,
                    p_shot_rect->offset_x + offset_x,
                    p_shot_rect->offset_y + offset_y,
                    clip,
                    gdi_act_layer->bits_per_pixel);
                gdi_layer_free(h_tmp_layer);
            }
            if (p_buff != NULL)
            {
                mmi_frm_scrmem_free(p_buff);
            }
            if(p_resize_dest != NULL)
            {
                mmi_frm_scrmem_free(p_resize_dest);
            }
        #endif
        }
        else
        {
            gdi_draw_solid_rect(
                p_shot_rect->offset_x,
                p_shot_rect->offset_y,
                p_shot_rect->offset_x + p_shot_rect->width - 1,
                p_shot_rect->offset_y + p_shot_rect->height - 1,
                MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
        }
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_preview
 * DESCRIPTION
 *  redraw the preview window.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum state = mmi_vdoedt_get_stat();
    vdoedt_shot_struct *p_shot;
    S32 w, h;
    S32 x, y;
    S8 fname[40];
    MDI_RESULT mdi_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* assume a layer is created for this window.   */
    /* will use whole layer for drawing             */

    if (MMI_VDOEDT_S_EMPTY == state)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
        /* "Please Insert Video" */
        gdi_layer_clear(GDI_COLOR_BLACK);
        gui_measure_string((UI_string_type) GetString(STR_ID_VDOEDT_PLZ_INS_VDO), &w, &h);
        x = (g_vdoedt_main_osd_cntx.play_wnd.width - w) >> 1;
        y = (g_vdoedt_main_osd_cntx.play_wnd.height - h) >> 1;
        gdi_layer_push_clip();
        gdi_layer_set_clip(x - 1, y - 1, x + w, y + h);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x + w, y);
        }
        else
        {
            gui_move_text_cursor(x, y);
        }
        gui_set_text_color(*current_MMI_theme->title_text_color);
        gui_set_text_border_color(*current_MMI_theme->title_text_border_color);
        gui_print_bordered_text((UI_string_type) GetString(STR_ID_VDOEDT_PLZ_INS_VDO));
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
    }
    else if (MMI_VDOEDT_S_EDIT == state || MMI_VDOEDT_S_SAVING == state)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);        
        /* draw the key frame of hilight shot. */
        gdi_layer_clear(GDI_COLOR_BLACK);
        if (g_vdoedt_cntx.i_act_shot < g_vdoedt_cntx.shot_count)
        {
            p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
            if (VDOEDT_SRC_COLOR != p_shot->src_type)
            {
                /* gen file name and draw file */
                mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
                mmi_ucs2cat(fname, p_shot->ustr_fname);
                gdi_image_draw_file(0, 0, fname);
            }
            else
            {
                gdi_draw_solid_rect(
                    0,
                    0,
                    g_vdoedt_main_osd_cntx.play_wnd.width - 1,
                    g_vdoedt_main_osd_cntx.play_wnd.height - 1,
                    MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
            }
        }
        gdi_layer_pop_and_restore_active();
    }
    else if (MMI_VDOEDT_S_PREVIEW == state)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
        /* draw the key frame of first shot. */
        ASSERT(g_vdoedt_cntx.shot_count);   /* shouldn't be here if there's no shot */
        p_shot = g_vdoedt_cntx.p_shot[0];   /* draw the first shot. */
        if (VDOEDT_SRC_COLOR != p_shot->src_type)
        {
            mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
            mmi_ucs2cat(fname, p_shot->ustr_fname);
            gdi_image_draw_file(0, 0, fname);
        }
        else
        {
            gdi_draw_solid_rect(
                0,
                0,
                g_vdoedt_main_osd_cntx.play_wnd.width - 1,
                g_vdoedt_main_osd_cntx.play_wnd.height - 1,
                MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
        }
        gdi_layer_pop_and_restore_active();
    }
    else if (MMI_VDOEDT_S_EDIT_CUT == state || MMI_VDOEDT_S_EDIT_CUT_IN == state)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);        
        p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
        mdi_video_edt_active(p_shot->h_video);
        mdi_res = mdi_video_ply_seek_and_get_frame(p_shot->ms_cut_in, g_vdoedt_cntx.h_play);
        mdi_video_edt_deactive();
        gdi_layer_pop_and_restore_active();
        if (!mmi_vdoedt_seek_result_handler(mdi_res))
        {
            DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
            return;
        }
    }
    else if (MMI_VDOEDT_S_EDIT_CUT_OUT == state)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);        
        p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
        mdi_video_edt_active(p_shot->h_video);
        mdi_res = mdi_video_ply_seek_and_get_frame(p_shot->ms_cut_out, g_vdoedt_cntx.h_play);
        mdi_video_edt_deactive();
        gdi_layer_pop_and_restore_active();
        if (!mmi_vdoedt_seek_result_handler(mdi_res))
        {
            DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
            return;
        }
    }
    else if (MMI_VDOEDT_S_EDIT_FRAME == state ||
             MMI_VDOEDT_S_EDIT_FRAME_IN == state || MMI_VDOEDT_S_EDIT_FRAME_SEL == state)
    {
        p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
        if (p_shot->src_type == VDOEDT_SRC_VIDEO)
        {
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
            mdi_video_edt_active(p_shot->h_video);
            if (MMI_VDOEDT_S_EDIT_FRAME == state)
            {
                mdi_res = mdi_video_ply_seek_and_get_frame(p_shot->ms_cut_in, g_vdoedt_cntx.h_play);
            }
            else
            {
                mdi_res = mdi_video_ply_seek_and_get_frame(p_shot->ms_frm_in, g_vdoedt_cntx.h_play);
            }
            mdi_video_edt_deactive();
            gdi_layer_pop_and_restore_active();
            if (!mmi_vdoedt_seek_result_handler(mdi_res))
            {
                DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
                return;
            }
        }
        else
        {
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
            if (VDOEDT_SRC_COLOR != p_shot->src_type)
            {
                mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
                mmi_ucs2cat(fname, p_shot->ustr_fname);
                gdi_image_draw_file(0, 0, fname);
            }
            else
            {
                gdi_draw_solid_rect(
                    0,
                    0,
                    g_vdoedt_main_osd_cntx.play_wnd.width - 1,
                    g_vdoedt_main_osd_cntx.play_wnd.height - 1,
                    MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
            }
            gdi_layer_pop_and_restore_active();
        }
    }
    else if (MMI_VDOEDT_S_EDIT_FRAME_OUT == state)
    {
        p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
        if (p_shot->src_type == VDOEDT_SRC_VIDEO)
        {
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
            mdi_video_edt_active(p_shot->h_video);
            mdi_res = mdi_video_ply_seek_and_get_frame(p_shot->ms_frm_out, g_vdoedt_cntx.h_play);
            mdi_video_edt_deactive();
            gdi_layer_pop_and_restore_active();
            if (!mmi_vdoedt_seek_result_handler(mdi_res))
            {
                DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
                return;
            }
        }
        else
        {
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);            
            if (VDOEDT_SRC_COLOR != p_shot->src_type)
            {
                mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
                mmi_ucs2cat(fname, p_shot->ustr_fname);
                gdi_image_draw_file(0, 0, fname);
            }
            else
            {
                gdi_draw_solid_rect(
                    0,
                    0,
                    g_vdoedt_main_osd_cntx.play_wnd.width - 1,
                    g_vdoedt_main_osd_cntx.play_wnd.height - 1,
                    MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
            }
            gdi_layer_pop_and_restore_active();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_time
 * DESCRIPTION
 *  draw the time indication on screen
 * PARAMETERS
 *  time        [IN]        Time (ms)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_time(U32 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 t, hh, mm, ss;
    vdoedt_osd_time_layout_struct *p_t;
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t = time / 1000;
    hh = t / 3600;
    t %= 3600;
    mm = t / 60;
    ss = t % 60;

    if (hh > 99)
    {
        hh = 99;
    }
    p_t = &g_vdoedt_main_osd_cntx.time;

    gdi_image_get_dimension_id(IMG_ID_VDOEDT_D0, &w, &h);
    gdi_layer_push_clip();
    gdi_layer_set_clip(p_t->h1.offset_x, p_t->h1.offset_y, p_t->s2.offset_x + w, p_t->h1.offset_y + h);
    gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_EDIT_BG);
    gdi_layer_pop_clip();
    /* hour */
    if (p_t->h1.is_show)
    {
        gdi_image_draw_id(p_t->h1.offset_x, p_t->h1.offset_y, (U16) (IMG_ID_VDOEDT_D0 + hh / 10));
    }
    if (p_t->h2.is_show)
    {
        gdi_image_draw_id(p_t->h2.offset_x, p_t->h2.offset_y, (U16) (IMG_ID_VDOEDT_D0 + hh % 10));
    }
    if (p_t->c1.is_show)
    {
        gdi_image_draw_id(p_t->c1.offset_x, p_t->c1.offset_y, IMG_ID_VDOEDT_D_COL);
    }
    /* min */
    if (p_t->m1.is_show)
    {
        gdi_image_draw_id(p_t->m1.offset_x, p_t->m1.offset_y, (U16) (IMG_ID_VDOEDT_D0 + mm / 10));
    }
    if (p_t->m2.is_show)
    {
        gdi_image_draw_id(p_t->m2.offset_x, p_t->m2.offset_y, (U16) (IMG_ID_VDOEDT_D0 + mm % 10));
    }
    if (p_t->c2.is_show)
    {
        gdi_image_draw_id(p_t->c2.offset_x, p_t->c2.offset_y, IMG_ID_VDOEDT_D_COL);
    }
    /* second */
    if (p_t->s1.is_show)
    {
        gdi_image_draw_id(p_t->s1.offset_x, p_t->s1.offset_y, (U16) (IMG_ID_VDOEDT_D0 + ss / 10));
    }
    if (p_t->s2.is_show)
    {
        gdi_image_draw_id(p_t->s2.offset_x, p_t->s2.offset_y, (U16) (IMG_ID_VDOEDT_D0 + ss % 10));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_stat
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_stat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_osd_status_layout_struct *p_stat;
    vdoedt_icon_struct *p_icon;
    vdoedt_shot_struct *p_shot = NULL;
    U16 imgid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_stat = &g_vdoedt_main_osd_cntx.status;
    if (g_vdoedt_cntx.shot_count)
    {
        if (MMI_VDOEDT_S_PREVIEW == mmi_vdoedt_get_stat())
        {
            p_shot = g_vdoedt_cntx.p_shot[0];
        }
        else
        {
            p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
        }
    }

    /* frame */
    p_icon = &p_stat->have_frame;
    if (p_icon->is_show)
    {
        if (p_shot != NULL && (p_shot->choosed_frame || mmi_ucs2strlen(p_shot->p_txt)))
        {
            gdi_image_draw_id(p_icon->offset_x, p_icon->offset_y, IMG_ID_VDOEDT_FRAME);
        }
        else
        {
            gdi_image_draw_id(p_icon->offset_x, p_icon->offset_y, IMG_ID_VDOEDT_STAT_EMPTY);
        }
    }

    /* in effect */
    p_icon = &p_stat->in_effect;
    if (p_icon->is_show)
    {
        imgid = IMG_ID_VDOEDT_STAT_EMPTY;
        if (p_shot != NULL)
        {
            switch (p_shot->in_effect)
            {
                case MMI_VDOEDT_EFFECT_IN_FROM_WHITE:
                    imgid = IMG_ID_VDOEDT_FADE_IN;
                    break;
                case MMI_VDOEDT_EFFECT_IN_FROM_BLACK:
                    imgid = IMG_ID_VDOEDT_FADE_OUT;
                    break;                    
                default:
                    imgid = IMG_ID_VDOEDT_STAT_EMPTY;
            }
        }
        gdi_image_draw_id(p_icon->offset_x, p_icon->offset_y, imgid);
    }
    /* out effect */
    p_icon = &p_stat->out_effect;
    if (p_icon->is_show)
    {
        imgid = IMG_ID_VDOEDT_STAT_EMPTY;
        if (p_shot != NULL)
        {
            switch (p_shot->out_effect)
            {
                case MMI_VDOEDT_EFFECT_OUT_2_WHITE:
                    imgid = IMG_ID_VDOEDT_FADE_OUT;
                    break;
                case MMI_VDOEDT_EFFECT_OUT_2_BLACK:
                    imgid = IMG_ID_VDOEDT_FADE_IN;
                    break;

                default:
                    imgid = IMG_ID_VDOEDT_STAT_EMPTY;
            }
        }
        gdi_image_draw_id(p_icon->offset_x, p_icon->offset_y, imgid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_softkey
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  lsk_str         [IN]        Lsk string
 *  rsk_str         [IN]        Rsk string
 *  is_clear_bg     [IN]        Clear background flag
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_softkey(PS8 lsk_str, PS8 rsk_str, BOOL is_clear_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width, str_height;
    S32 offset_x, offset_y;
    S32 x1, x2, y1, y2;
    video_osd_softkey_struct *p_key;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has softkey need update */
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    p_key = &g_vdoedt_main_osd_cntx.softkey;
    gui_set_font(current_MMI_theme->button_font);

    x1 = 0;
    y1 = UI_device_height - MMI_button_bar_height;
    x2 = UI_device_width - 1;
    y2 = UI_device_height - 1;

    /* clear softkey background */
    if (is_clear_bg)
    {
        gdi_layer_set_clip(x1, y1, x2, y2);
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.bg.offset_x,
            g_vdoedt_main_osd_cntx.bg.offset_y,
            IMG_ID_VDOEDT_EDIT_BG);
    }

    /* draw lsk */
    if (lsk_str != NULL)
    {
    #if 1
        wgui_softkey_get_offset((UI_string_type) lsk_str, &offset_x, &offset_y, MMI_LEFT_SOFTKEY);
        gui_measure_string((UI_string_type) lsk_str, &str_width, &str_height);
        p_key->icon_lsk_pos.offset_x = offset_x;
        p_key->icon_lsk_pos.offset_y = offset_y;
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        if (g_vdoedt_key_cntx.lsk.pressed)
        {
            offset_x++;
            offset_y++;
        }
        gui_move_text_cursor(offset_x, offset_y);

        gui_set_text_color(gui_color(p_key->lsk_text.r, p_key->lsk_text.g, p_key->lsk_text.b));
        gui_set_text_border_color(gui_color(p_key->lsk_text.style_r, p_key->lsk_text.style_g, p_key->lsk_text.style_b));
        gui_print_bordered_text((UI_string_type) lsk_str);
    #ifdef __MMI_TOUCH_SCREEN__
        g_vdoedt_key_cntx.lsk.w = str_width;
        g_vdoedt_key_cntx.lsk.h = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 

    }
    /* draw rsk */
    if (rsk_str != NULL)
    {
    #if 1
        wgui_softkey_get_offset((UI_string_type) rsk_str, &offset_x, &offset_y, MMI_RIGHT_SOFTKEY);
        gui_measure_string((UI_string_type) rsk_str, &str_width, &str_height);
        p_key->icon_rsk_pos.offset_x = offset_x;
        p_key->icon_rsk_pos.offset_y = offset_y;
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

        if (g_vdoedt_key_cntx.rsk.pressed)
        {
            offset_x++;
            offset_y++;
        }

        gui_move_text_cursor(offset_x, offset_y);

        gui_set_text_color(gui_color(p_key->rsk_text.r, p_key->rsk_text.g, p_key->rsk_text.b));
        gui_set_text_border_color(gui_color(p_key->rsk_text.style_r, p_key->rsk_text.style_g, p_key->rsk_text.style_b));
        gui_print_bordered_text((UI_string_type) rsk_str);
    #ifdef __MMI_TOUCH_SCREEN__
        g_vdoedt_key_cntx.rsk.w = str_width;
        g_vdoedt_key_cntx.rsk.h = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 

    }

    /* play key */
    if (p_key->is_ck_icon &&
        ((MMI_VDOEDT_S_EDIT == stat && g_vdoedt_cntx.i_act_shot != g_vdoedt_cntx.shot_count) ||
         MMI_VDOEDT_S_PREVIEW == stat ||
         MMI_VDOEDT_S_EDIT_CUT == stat ||
         MMI_VDOEDT_S_EDIT_FRAME == stat) ||
         MMI_VDOEDT_S_SEEK == stat ||
         MMI_VDOEDT_S_SEEK_UPDATING == stat ||
         MMI_VDOEDT_S_SEEK_DONE == stat)
    {
        gdi_image_get_dimension_id(IMG_ID_VDOEDT_PLAY, &str_width, &str_height);
        offset_x = p_key->icon_ck_pos.offset_x - (str_width >> 1);
        offset_y = p_key->icon_ck_pos.offset_y;
        gdi_layer_set_clip(offset_x, offset_y, offset_x + str_width, offset_y + str_height);
        gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_EDIT_BG);
        if (g_vdoedt_key_cntx.ck.pressed)
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_VDOEDT_PLAY_DOWN);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_VDOEDT_PLAY);
        }
    #ifdef __MMI_TOUCH_SCREEN__
        g_vdoedt_key_cntx.ck.x = offset_x;
        g_vdoedt_key_cntx.ck.w = str_width;
        g_vdoedt_key_cntx.ck.h = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    else if ((MMI_VDOEDT_S_PLAY <= stat && MMI_VDOEDT_S_FRM_PLAY >= stat) ||
        MMI_VDOEDT_S_PLAY_SEEK == stat ||
        MMI_VDOEDT_S_PLAY_SEEK_UPDATING == stat ||
        MMI_VDOEDT_S_PLAY_SEEK_DONE == stat)
    {
        /* draw stop key */
        gdi_image_get_dimension_id(IMG_ID_VDOEDT_PLAY, &str_width, &str_height);
        offset_x = p_key->icon_ck_pos.offset_x - (str_width >> 1);
        offset_y = p_key->icon_ck_pos.offset_y;
        gdi_layer_set_clip(offset_x, offset_y, offset_x + str_width, offset_y + str_height);
        gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_EDIT_BG);
        if (g_vdoedt_key_cntx.ck.pressed)
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_VDOEDT_STOP_DOWN);
        }
        else
        {
            gdi_image_draw_id(offset_x, offset_y, IMG_ID_VDOEDT_STOP);
        }
    #ifdef __MMI_TOUCH_SCREEN__
        g_vdoedt_key_cntx.ck.x = offset_x;
        g_vdoedt_key_cntx.ck.w = str_width;
        g_vdoedt_key_cntx.ck.h = str_height;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
#ifdef __MMI_TOUCH_SCREEN__
    else
    {
        g_vdoedt_key_cntx.ck.w = 0;
        g_vdoedt_key_cntx.ck.h = 0;
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_shot_hilight
 * DESCRIPTION
 *  Left soft key handler for main screens.
 * PARAMETERS
 *  i_shot      [IN]        The hilight shot index  [0,4]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_shot_hilight(U8 i_shot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_rect_struct *p_shot;
    vdoedt_rect_struct *p_bar, *p_fillbar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(i_shot < MMI_VDOEDT_MAX_CLIP_NUM);   /* i_shot [0,4] */

    p_fillbar = &g_vdoedt_main_osd_cntx.editbar.fill;
    p_bar = &g_vdoedt_main_osd_cntx.editbar.bg;

    gdi_layer_push_clip();
    gdi_layer_set_clip(
        p_fillbar->offset_x,
        p_fillbar->offset_y,
        p_fillbar->offset_x + p_bar->width + 1,
        p_fillbar->offset_y + p_bar->height + 1);

    gdi_image_draw_id(g_vdoedt_main_osd_cntx.bg.offset_x, g_vdoedt_main_osd_cntx.bg.offset_y, IMG_ID_VDOEDT_EDIT_BG);

    gdi_image_draw_id(p_bar->offset_x, p_bar->offset_y, IMG_ID_VDOEDT_EDITBAR_BG);

    p_shot = (&g_vdoedt_main_osd_cntx.editbar.shot[i_shot]);

    if (i_shot != MMI_VDOEDT_MAX_CLIP_NUM - 1)
    {
        gdi_layer_set_clip(
            p_fillbar->offset_x + p_shot->offset_x - 2,
            p_fillbar->offset_y,
            p_fillbar->offset_x + (p_shot + 1)->offset_x - 2,
            p_fillbar->offset_y + p_bar->height + 2);
    }
    else
    {
        gdi_layer_set_clip(
            p_fillbar->offset_x + p_shot->offset_x - 2,
            p_fillbar->offset_y,
            p_fillbar->offset_x + p_shot->offset_x + p_shot->width + 2,
            p_fillbar->offset_y + p_bar->height + 2);
    }
    gdi_image_draw_id(p_fillbar->offset_x, p_fillbar->offset_y, IMG_ID_VDOEDT_EDITBAR_HILIGHT);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_cut_in_buttons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_cut_in_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear background */
    gdi_layer_push_clip();
#if defined(__MMI_MAINLCD_176X220__)
    gdi_layer_set_clip(
        0,
        g_vdoedt_cut_osd_cntx.cutbar.bg.offset_y + g_vdoedt_cut_osd_cntx.cutbar.bg.height,
        UI_device_width - 1,
        g_vdoedt_cut_osd_cntx.cutbar.in.y + g_vdoedt_cut_osd_cntx.cutbar.in.h + 1);
    gdi_image_draw_id(g_vdoedt_cut_osd_cntx.bg.offset_x, g_vdoedt_cut_osd_cntx.bg.offset_y, IMG_ID_VDOEDT_CUT_BG);
#else /* defined(__MMI_MAINLCD_176X220__) */ 
    gdi_layer_set_clip(
        0,
        g_vdoedt_cut_osd_cntx.cutbar.in.y,
        UI_device_width - 1,
        g_vdoedt_cut_osd_cntx.cutbar.in.y + g_vdoedt_cut_osd_cntx.cutbar.in.h + 1);
    gdi_image_draw_id(g_vdoedt_cut_osd_cntx.bg.offset_x, g_vdoedt_cut_osd_cntx.bg.offset_y, IMG_ID_VDOEDT_CUT_BG);
#endif /* defined(__MMI_MAINLCD_176X220__) */ 
    gdi_layer_pop_clip();

    if (g_vdoedt_cut_osd_cntx.cutbar.in_rak.is_show)
    {
        if (g_vdoedt_key_cntx.cut_in.pressed)
        {
            if (g_vdoedt_key_cntx.in_rak.pressed)
            {
                id_img = IMG_ID_VDOEDT_ARROW_R_DOWN;
            }
            else
            {
                id_img = IMG_ID_VDOEDT_ARROW_R;
            }
        }
        else
        {
            id_img = IMG_ID_VDOEDT_ARROW_R_DISABLE;
        }
        gdi_image_draw_id(
            g_vdoedt_cut_osd_cntx.cutbar.in_rak.offset_x,
            g_vdoedt_cut_osd_cntx.cutbar.in_rak.offset_y,
            id_img);
    }
    if (g_vdoedt_cut_osd_cntx.cutbar.in_lak.is_show)
    {
        if (g_vdoedt_key_cntx.cut_in.pressed)
        {
            if (g_vdoedt_key_cntx.in_lak.pressed)
            {
                id_img = IMG_ID_VDOEDT_ARROW_L_DOWN;
            }
            else
            {
                id_img = IMG_ID_VDOEDT_ARROW_L;
            }
        }
        else
        {
            id_img = IMG_ID_VDOEDT_ARROW_L_DISABLE;
        }
        gdi_image_draw_id(
            g_vdoedt_cut_osd_cntx.cutbar.in_lak.offset_x,
            g_vdoedt_cut_osd_cntx.cutbar.in_lak.offset_y,
            id_img);
    }
    if (g_vdoedt_cut_osd_cntx.cutbar.in_icon.is_show)
    {
        gdi_image_draw_id(
            g_vdoedt_cut_osd_cntx.cutbar.in_icon.offset_x,
            g_vdoedt_cut_osd_cntx.cutbar.in_icon.offset_y,
            IMG_ID_VDOEDT_CUT_IN_ICON);
    }
    if (g_vdoedt_cut_osd_cntx.cutbar.in.is_show)
    {
        if (g_vdoedt_key_cntx.cut_in.pressed)
        {
            id_img = IMG_ID_VDOEDT_CUT_IN_DOWN;
        }
        else
        {
            id_img = IMG_ID_VDOEDT_CUT_IN;
        }
        gdi_image_draw_id(g_vdoedt_key_cntx.x_cut_in, g_vdoedt_cut_osd_cntx.cutbar.in.y, id_img);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_cut_out_buttons
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_cut_out_buttons(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        0,
        g_vdoedt_cut_osd_cntx.cutbar.out.y,
        UI_device_width - 1,
        g_vdoedt_cut_osd_cntx.cutbar.bg.offset_y - 1);
    gdi_image_draw_id(g_vdoedt_cut_osd_cntx.bg.offset_x, g_vdoedt_cut_osd_cntx.bg.offset_y, IMG_ID_VDOEDT_CUT_BG);
    gdi_layer_pop_clip();
    
    if (g_vdoedt_cut_osd_cntx.cutbar.out_rak.is_show)
    {
        if (g_vdoedt_key_cntx.cut_out.pressed)
        {
            if (g_vdoedt_key_cntx.out_rak.pressed)
            {
                id_img = IMG_ID_VDOEDT_ARROW_R_DOWN;
            }
            else
            {
                id_img = IMG_ID_VDOEDT_ARROW_R;
            }
        }
        else
        {
            id_img = IMG_ID_VDOEDT_ARROW_R_DISABLE;
        }
        gdi_image_draw_id(
            g_vdoedt_cut_osd_cntx.cutbar.out_rak.offset_x,
            g_vdoedt_cut_osd_cntx.cutbar.out_rak.offset_y,
            id_img);
    }
    if (g_vdoedt_cut_osd_cntx.cutbar.out_lak.is_show)
    {
        if (g_vdoedt_key_cntx.cut_out.pressed)
        {
            if (g_vdoedt_key_cntx.out_lak.pressed)
            {
                id_img = IMG_ID_VDOEDT_ARROW_L_DOWN;
            }
            else
            {
                id_img = IMG_ID_VDOEDT_ARROW_L;
            }
        }
        else
        {
            id_img = IMG_ID_VDOEDT_ARROW_L_DISABLE;
        }
        gdi_image_draw_id(
            g_vdoedt_cut_osd_cntx.cutbar.out_lak.offset_x,
            g_vdoedt_cut_osd_cntx.cutbar.out_lak.offset_y,
            id_img);
    }
    if (g_vdoedt_cut_osd_cntx.cutbar.out_icon.is_show)
    {
        gdi_image_draw_id(
            g_vdoedt_cut_osd_cntx.cutbar.out_icon.offset_x,
            g_vdoedt_cut_osd_cntx.cutbar.out_icon.offset_y,
            IMG_ID_VDOEDT_CUT_OUT_ICON);
    }
    if (g_vdoedt_cut_osd_cntx.cutbar.out.is_show)
    {
        if (g_vdoedt_key_cntx.cut_out.pressed)
        {
            id_img = IMG_ID_VDOEDT_CUT_OUT_DOWN;
        }
        else
        {
            id_img = IMG_ID_VDOEDT_CUT_OUT;
        }
        gdi_image_draw_id(g_vdoedt_key_cntx.x_cut_out, g_vdoedt_cut_osd_cntx.cutbar.out.y, id_img);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_redraw_cut_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_redraw_cut_scr(U8 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum state;
    U64 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    state = mmi_vdoedt_get_stat();
    /* bg */
    if (item & MMI_VDOEDT_R4W_BG)
    {
        gdi_image_draw_id(g_vdoedt_cut_osd_cntx.bg.offset_x, g_vdoedt_cut_osd_cntx.bg.offset_y, IMG_ID_VDOEDT_CUT_BG);
    #ifdef __MMI_MAINLCD_240X320__
        if (SCR_ID_VDOEDT_VIDEO_CUT == GetActiveScreenId())
        {
            mmi_vdoedt_draw_title(STR_ID_VDOEDT_CUT_VDO);
        }
        else
        {
            mmi_vdoedt_draw_title(STR_ID_VDOEDT_FRAME);
        }
    #endif /* __MMI_MAINLCD_240X320__ */ 
    }

    /* cut bar          */
    if (item & MMI_VDOEDT_R4W_EBAR)
    {
        mmi_vdoedt_draw_cut_bar();
    }
    /* buttom control      */
    if (item & MMI_VDOEDT_R4W_IN_BTN)
    {
        mmi_vdoedt_draw_cut_in_buttons();
    }
    /* top control   */
    if (item & MMI_VDOEDT_R4W_OUT_BTN)
    {
        mmi_vdoedt_draw_cut_out_buttons();
    }
    /* softkey          */
    if (item & MMI_VDOEDT_R4W_SKEY)
    {
        mmi_vdoedt_draw_softkey(GetString(STR_GLOBAL_DONE), GetString(STR_GLOBAL_BACK), TRUE);
    }
    
    /* preview window   */
    if (item & MMI_VDOEDT_R4W_PWIN)
    {
        /* frame and text */
        switch (state)
        {
            case MMI_VDOEDT_S_EDIT_FRAME_IN:
                time = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_frm_in;
                break;

            case MMI_VDOEDT_S_EDIT_FRAME_OUT:
                time = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_frm_out;
                break;

            case MMI_VDOEDT_S_EDIT_CUT_OUT:
                time = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_out;
                break;

            case MMI_VDOEDT_S_EDIT_CUT_IN:
            case MMI_VDOEDT_S_EDIT_FRAME:
            case MMI_VDOEDT_S_EDIT_CUT:
            default:
                time = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_in;
        }
        mmi_vdoedt_draw_frametxt(time);
        
        /* key frame */
        /* put key frame at last, because file may disappear.*/
        mmi_vdoedt_draw_preview();
    }    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_cut_bar
 * DESCRIPTION
 *  Left soft key handler for main screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_cut_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_osd_cutbar_layout_struct *p_cut;
    vdoedt_shot_struct *p_shot;
    S32 w;
    U16 img_id = IMG_ID_VDOEDT_CUT_BAR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_cut = &(g_vdoedt_cut_osd_cntx.cutbar);
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    gdi_layer_push_clip();
    gdi_layer_set_clip(0, p_cut->bg.offset_y, UI_device_width - 1, p_cut->bg.offset_y + p_cut->bg.height - 1);
    gdi_image_draw_id(g_vdoedt_cut_osd_cntx.bg.offset_x, g_vdoedt_cut_osd_cntx.bg.offset_y, IMG_ID_VDOEDT_CUT_BG);
    gdi_image_draw_id(p_cut->bg.offset_x, p_cut->bg.offset_y, IMG_ID_VDOEDT_CUT_BAR_BG);

    /* x1/w = t1/t => x1 = (t1/t)*w  */
    /* set clip */
    w = g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1;
    gdi_layer_set_clip(
        g_vdoedt_key_cntx.x_cut_in + w,
        p_cut->fill.offset_y,
        g_vdoedt_key_cntx.x_cut_out + w,
        p_cut->fill.offset_y + p_cut->bg.height - 1);
    if (SCR_ID_VDOEDT_FRAME_EDIT == GetActiveScreenId())
    {
        if (MMI_VDOEDT_S_EDIT_FRAME == mmi_vdoedt_get_stat())
        {
            img_id = IMG_ID_VDOEDT_FRM_BAR_H;
        }
        else
        {
            img_id = IMG_ID_VDOEDT_FRM_BAR;
        }
    }
    else if (MMI_VDOEDT_S_EDIT_CUT == mmi_vdoedt_get_stat())
    {
        img_id = IMG_ID_VDOEDT_CBAR_H;
    }
    gdi_image_draw_id(p_cut->fill.offset_x, p_cut->fill.offset_y, img_id);
    gdi_layer_pop_clip();
    /* progress bar */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_pbar2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pa      [IN]            % of progressbar
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_pbar2(U8 pa)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_w = g_vdoedt_main_osd_cntx.progress.empty.width;
    S32 img_h = g_vdoedt_main_osd_cntx.progress.empty.height;
    S32 x = g_vdoedt_main_osd_cntx.progress.empty.offset_x;
    S32 y = g_vdoedt_main_osd_cntx.progress.empty.offset_y;
    gdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();

    /* clear progress bar background */
    gdi_layer_reset_clip();
    ret = gdi_image_draw_id(x, y, IMG_ID_VDOEDT_PROGRESS_BAR_BG);

    /* draw current progress */
    if (pa)
    {
        ASSERT(pa <= 100);
        gdi_layer_set_clip(x, y, x + (img_w * 100 / pa), y + img_h);
        gdi_image_draw_id(x, y, IMG_ID_VDOEDT_PROGRESS_BAR);
    }

    /* draw hilight */
    if (MMI_VDOEDT_S_PREVIEW == mmi_vdoedt_get_stat())
    {
        gdi_draw_rect(x, y, x + img_w - 1, y + img_h - 1, MMI_VDOEDT_BAR_HILIGHT_COLOR);
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_main_pbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ms_t            [IN]        
 *  ms_t_total      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_draw_main_pbar(U32 ms_t, U32 ms_t_total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_w, img_h;
    gdi_result ret;
    static U32 last_t = 0;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw progress bar */
    if (stat >= MMI_VDOEDT_S_PLAY && stat <= MMI_VDOEDT_S_FRM_PLAY)
    {
        if (ms_t <= last_t)
        {
            return; /* prevent "shrinking" of progressbar */
        }
        last_t = ms_t;
    }
    else
    {
        last_t = 0;
    }
    img_w = g_vdoedt_main_osd_cntx.progress.empty.width;
    img_h = g_vdoedt_main_osd_cntx.progress.empty.height;
    gdi_layer_push_clip();
    if (MMI_VDOEDT_S_EDIT == mmi_vdoedt_get_stat())
    {
        gdi_layer_set_clip(
            g_vdoedt_main_osd_cntx.progress.empty.offset_x - 2,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y - 2,
            g_vdoedt_main_osd_cntx.progress.empty.offset_x + img_w + 1,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y + img_h + 1);
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.bg.offset_x,
            g_vdoedt_main_osd_cntx.bg.offset_y,
            IMG_ID_VDOEDT_EDIT_BG);
    }
    gdi_layer_reset_clip();
    ret = gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.progress.empty.offset_x,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y,
            IMG_ID_VDOEDT_PROGRESS_BAR_BG);
    if (ms_t)
    {
        if (ms_t < ms_t_total - MMI_VDOEDT_SHOT_UPDATE_INTERVAL)
        {
            /* for boundary condition */
            gdi_layer_set_clip(
                g_vdoedt_main_osd_cntx.progress.full.offset_x,
                g_vdoedt_main_osd_cntx.progress.full.offset_y,
                g_vdoedt_main_osd_cntx.progress.full.offset_x + ms_t * img_w / ms_t_total,
                g_vdoedt_main_osd_cntx.progress.full.offset_y + img_h);
        }
        gdi_image_draw_id(
            g_vdoedt_main_osd_cntx.progress.full.offset_x,
            g_vdoedt_main_osd_cntx.progress.full.offset_y,
            IMG_ID_VDOEDT_PROGRESS_BAR);
    }
    /* hilight progress bar */
    if (MMI_VDOEDT_S_PREVIEW == mmi_vdoedt_get_stat())
    {
        gdi_draw_rect(
            g_vdoedt_main_osd_cntx.progress.empty.offset_x - 1,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y - 1,
            g_vdoedt_main_osd_cntx.progress.empty.offset_x + img_w,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y + img_h,
            MMI_VDOEDT_BAR_HILIGHT_COLOR);
        gdi_draw_rect(
            g_vdoedt_main_osd_cntx.progress.empty.offset_x - 2,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y - 2,
            g_vdoedt_main_osd_cntx.progress.empty.offset_x + img_w + 1,
            g_vdoedt_main_osd_cntx.progress.empty.offset_y + img_h + 1,
            MMI_VDOEDT_BAR_HILIGHT_COLOR);
    }
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_redraw_frm_sel_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_redraw_frm_sel_scr(U8 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    IMG_ID_VDOEDT_ENUM img_id;

    /* vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_osd);
    if (item & MMI_VDOEDT_R4W_BG)
    {
        gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_VIEWER);
        mmi_vdoedt_draw_title(STR_ID_VDOEDT_TXT_CHOOSE_FRM);
    }
    if (item & MMI_VDOEDT_R4W_FRM_SEL_BTN)
    {
        if (g_vdoedt_frm_sel_osd_cntx.prev.is_show)
        {
        #ifdef __MMI_MAINLCD_176X220__
            if (g_vdoedt_key_cntx.frame_pre.pressed)
            {
                img_id = IMG_ID_VDOEDT_ARROW_L_DOWN;
            }
            else
            {
                img_id = IMG_ID_VDOEDT_ARROW_L;
            }
        #else /* __MMI_MAINLCD_176X220__ */
            if (g_vdoedt_key_cntx.frame_pre.pressed)
            {
                img_id = IMG_ID_VDOEDT_FRMSEL_LAK_D;
            }
            else
            {
                img_id = IMG_ID_VDOEDT_FRMSEL_LAK;
            }
        #endif /* __MMI_MAINLCD_176X220__ */
            gdi_image_draw_id(
                g_vdoedt_frm_sel_osd_cntx.prev.offset_x,
                g_vdoedt_frm_sel_osd_cntx.prev.offset_y,
                (U16) img_id);
        }
        if (g_vdoedt_frm_sel_osd_cntx.next.is_show)
        {
        #ifdef __MMI_MAINLCD_176X220__
            if (g_vdoedt_key_cntx.frame_n.pressed)
            {
                img_id = IMG_ID_VDOEDT_ARROW_R_DOWN;
            }
            else
            {
                img_id = IMG_ID_VDOEDT_ARROW_R;
            }
        #else /* #ifdef __MMI_MAINLCD_176X220__ */
            if (g_vdoedt_key_cntx.frame_n.pressed)
            {
                img_id = IMG_ID_VDOEDT_FRMSEL_RAK_D;
            }
            else
            {
                img_id = IMG_ID_VDOEDT_FRMSEL_RAK;
            }
        #endif /* #ifdef __MMI_MAINLCD_176X220__ */
            gdi_image_draw_id(
                g_vdoedt_frm_sel_osd_cntx.next.offset_x,
                g_vdoedt_frm_sel_osd_cntx.next.offset_y,
                (U16) img_id);
        }
    }
    if (item & MMI_VDOEDT_R4W_FRAME)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_frmtxt);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        if (g_vdoedt_cntx.old_s5g[0])
        {
            gdi_image_draw_id(0, 0, IMG_ID_VDOEDT_FRAME1 + g_vdoedt_cntx.old_s5g[0] - 1);
        }
        gdi_layer_pop_and_restore_active();
    }

    if (item & MMI_VDOEDT_R4W_SKEY)
    {
        mmi_vdoedt_draw_softkey(GetString(STR_GLOBAL_DONE), GetString(STR_GLOBAL_BACK), TRUE);
    }
    gdi_layer_pop_and_restore_active();
    
    if (item & MMI_VDOEDT_R4W_PWIN)
    {
        /* redraw key frame */
        /* put key frame at last, becauz file may gone */
        mmi_vdoedt_draw_preview();
    }    
    
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    GDI_UNLOCK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_lsk_up
 * DESCRIPTION
 *  Left soft key handler for main screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_lsk_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 last_scr_id;
    vdoedt_state_enum cur_stat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.lsk.pressed = FALSE;
    /* by exit screen and state to select option menu */
    last_scr_id = GetExitScrnID();
    cur_stat = mmi_vdoedt_get_stat();

    if (SCR_ID_VDOEDT_MAIN == last_scr_id)
    {
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
        /* switch to correct option menu by state. */
        /* if under playing, enter option menu according to old state. */
        if (MMI_VDOEDT_S_EDIT == cur_stat || MMI_VDOEDT_S_EDIT_PLAY == cur_stat)
        {
            mmi_vdoedt_entry_edit_option_screen();
        }
        else if (MMI_VDOEDT_S_PREVIEW == cur_stat || MMI_VDOEDT_S_PREVIEW_PLAY == cur_stat)
        {
            mmi_vdoedt_entry_preview_option_screen();
        }
        else if (MMI_VDOEDT_S_EMPTY == cur_stat)
        {
            mmi_vdoedt_entry_empty_option_screen();
        }
        else if (MMI_VDOEDT_S_SEEK_DONE == cur_stat || MMI_VDOEDT_S_PLAY_SEEK_DONE == cur_stat)
        {
            mmi_vdoedt_entry_preview_option_screen();
        }
        else
        {
            return; /* updating */
        }
    }
    else if (SCR_ID_VDOEDT_VIDEO_CUT == last_scr_id)
    {
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
        mmi_vdoedt_video_apply_cut();
    }
    else if (SCR_ID_VDOEDT_FRAME_EDIT == last_scr_id)
    {
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
        mmi_vdoedt_frame_edit_done();
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == last_scr_id)
    {
        g_vdoedt_cntx.flg_frm_sel_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
        mmi_vdoedt_frame_sel_done();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_rsk_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_rsk_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* use one hdlr for all rsk */
    scrid = GetActiveScreenId();
    g_vdoedt_key_cntx.rsk.pressed = FALSE;

    if (SCR_ID_VDOEDT_MAIN == scrid)
    {
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();        
        mmi_vdoedt_exit_confirm();
    }
    else if (SCR_ID_VDOEDT_VIDEO_CUT == scrid)
    {
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
        mmi_vdoedt_cut_edit_giveup();
    }
    else if (SCR_ID_VDOEDT_FRAME_EDIT == scrid)
    {
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
        mmi_vdoedt_frame_edit_giveup();
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == scrid)
    {
        g_vdoedt_cntx.flg_frm_sel_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();       
        mmi_vdoedt_frm_sel_restore();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_lsk_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_lsk_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrid = GetActiveScreenId(), lsk = STR_GLOBAL_OPTIONS, rsk = STR_GLOBAL_BACK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.lsk.pressed = TRUE;
    if (SCR_ID_VDOEDT_VIDEO_CUT == scrid || SCR_ID_VDOEDT_FRAME_PREVIEW == scrid || SCR_ID_VDOEDT_FRAME_EDIT == scrid)
    {
        if (SCR_ID_VDOEDT_FRAME_PREVIEW == scrid)
        {
            g_vdoedt_cntx.flg_frm_sel_r4w = MMI_VDOEDT_R4W_SKEY;
        }
        else
        {
            g_vdoedt_cntx.flg_cut_r4w = MMI_VDOEDT_R4W_SKEY;
        }
        lsk = STR_GLOBAL_DONE;
    }
    else if (SCR_ID_VDOEDT_MAIN == scrid)
    {
        g_vdoedt_cntx.flg_main_r4w = MMI_VDOEDT_R4W_SKEY;
        rsk = STR_ID_VDOEDT_EXIT;
    }
    mmi_vdoedt_draw_softkey(GetString(lsk), GetString(rsk), TRUE);
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_rsk_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_rsk_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrid = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.rsk.pressed = TRUE;
    if (SCR_ID_VDOEDT_VIDEO_CUT == scrid || SCR_ID_VDOEDT_FRAME_PREVIEW == scrid || SCR_ID_VDOEDT_FRAME_EDIT == scrid)
    {
        if (SCR_ID_VDOEDT_FRAME_PREVIEW == scrid)
        {
            g_vdoedt_cntx.flg_frm_sel_r4w = MMI_VDOEDT_R4W_SKEY;
        }
        else
        {
            g_vdoedt_cntx.flg_cut_r4w = MMI_VDOEDT_R4W_SKEY;
        }        
        mmi_vdoedt_draw_softkey(GetString(STR_GLOBAL_DONE), GetString(STR_GLOBAL_BACK), TRUE);
    }
    else if (SCR_ID_VDOEDT_MAIN == scrid)
    {
        g_vdoedt_cntx.flg_main_r4w = MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_draw_softkey(GetString(STR_GLOBAL_OPTIONS), GetString(STR_ID_VDOEDT_EXIT), TRUE);
    }
    else
    {
        mmi_vdoedt_draw_softkey(GetString(STR_GLOBAL_OPTIONS), GetString(STR_GLOBAL_BACK), TRUE);
    }

    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_ck_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_ck_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_key_cntx.ck.pressed = TRUE;
    mmi_vdoedt_draw_softkey(NULL, NULL, FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_ck_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_ck_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdoedt_key_cntx.ck.pressed)
    {
       return;
    }
    
    g_vdoedt_key_cntx.ck.pressed = FALSE;
    if (stat > MMI_VDOEDT_S_EMPTY && stat < MMI_VDOEDT_S_SAVING)
    {
        if (stat >= MMI_VDOEDT_S_PREVIEW_PLAY && stat <= MMI_VDOEDT_S_FRM_PLAY)
        {
            mmi_vdoedt_play_stop();
            if (SCR_ID_VDOEDT_MAIN == GetActiveScreenId())
            {
                g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_SKEY | MMI_VDOEDT_R4W_TIME;
                mmi_vdoedt_redraw();
            }
            else
            {
                g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
                mmi_vdoedt_redraw();
            }
        }
        else if (stat != MMI_VDOEDT_S_SEEK || stat != MMI_VDOEDT_S_SEEK_UPDATING)
        {
            g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
            mmi_vdoedt_redraw();
            mmi_vdoedt_play();
            stat = mmi_vdoedt_get_stat();
            if (stat >= MMI_VDOEDT_S_PREVIEW_PLAY && stat <= MMI_VDOEDT_S_FRM_PLAY)
            {
                if (SCR_ID_VDOEDT_MAIN == GetActiveScreenId())
                {
                    g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_SKEY;
                    mmi_vdoedt_redraw();
                }
                else
                {
                    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
                    mmi_vdoedt_redraw();
                }
            }
        }
        /* else do nothing */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_play_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_play_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOffBacklight();
    if (stat >= MMI_VDOEDT_S_PLAY && stat <= MMI_VDOEDT_S_FRM_PLAY)
    {
        gui_cancel_timer(mmi_vdoedt_update_osd_time);
        gui_cancel_timer(mmi_vdoedt_effect_in);
        gui_cancel_timer(mmi_vdoedt_effect_out);

        gui_cancel_timer(mmi_vdoedt_play_shot_updater);

        p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

        /* stop playing if it's video */
        if (VDOEDT_SRC_VIDEO == p_shot->src_type)
        {
            mdi_video_ply_stop();
            mdi_video_edt_deactive();
            if (SCR_ID_VDOEDT_MAIN == GetActiveScreenId())
            {
                g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PWIN;
            }
        }

        g_vdoedt_cntx.time_now = 0;

        switch (stat)
        {
            case MMI_VDOEDT_S_PREVIEW_PLAY:
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW);
                break;
            case MMI_VDOEDT_S_EDIT_PLAY:
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
                break;
            case MMI_VDOEDT_S_CUT_PLAY:
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_CUT);
                break;
            case MMI_VDOEDT_S_FRM_PLAY:
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME);
                break;
            default:
                ASSERT(MMI_VDOEDT_S_PREVIEW_PLAY <= stat && stat <= MMI_VDOEDT_S_FRM_PLAY);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_play_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_play_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 t_play;
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_update_osd_time);
    gui_cancel_timer(mmi_vdoedt_effect_in);
    gui_cancel_timer(mmi_vdoedt_effect_out);
    gui_cancel_timer(mmi_vdoedt_play_shot_updater);

    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /* stop video playing */
    if (VDOEDT_SRC_VIDEO == p_shot->src_type)
    {
        mdi_video_ply_get_cur_play_time(&t_play);
        mdi_video_ply_stop();
        mdi_video_edt_deactive();
    }
    /* do not reset time. */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_key_dummy_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_key_dummy_hdlr(void)
{
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_scr_upkey_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_scr_upkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();
    U16 id_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_VDOEDT_VIDEO_CUT == id_scr)
    {
        /* move toward cut out */
        if (MMI_VDOEDT_S_EDIT_CUT_IN == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_CUT);
        }
        else if (MMI_VDOEDT_S_EDIT_CUT == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_CUT_OUT);
        }
        else
        {
            return;     /* nothing should be done */
        }
    }
    else if (SCR_ID_VDOEDT_FRAME_EDIT == id_scr)
    {
        if (MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME);
        }
        else if (MMI_VDOEDT_S_EDIT_FRAME == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME_OUT);
        }
        else
        {
            return;     /* nothing should be done */
        }        
    }

    /* reget new stat */
    stat = mmi_vdoedt_get_stat();
    if (MMI_VDOEDT_S_EDIT_FRAME == stat || MMI_VDOEDT_S_EDIT_CUT == stat)
#ifdef NO_LSK
    {
        SetKeyHandler(mmi_vdoedt_ck_down, KEY_LSK, KEY_EVENT_DOWN);//ghw222
        SetKeyHandler(mmi_vdoedt_ck_up, KEY_LSK, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_LSK, KEY_EVENT_UP);//ghw222
    }

#else
    {
        SetKeyHandler(mmi_vdoedt_ck_down, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_ck_up, KEY_ENTER, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_ENTER, KEY_EVENT_UP);
    }

#endif
    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
    mmi_vdoedt_redraw();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_scr_downkey_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_scr_downkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();
    U16 id_scr = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* move toward cut in */
    if (SCR_ID_VDOEDT_VIDEO_CUT == id_scr)
    {
        if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_CUT);
        }
        else if (MMI_VDOEDT_S_EDIT_CUT == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_CUT_IN);
        }
        else
        {
            return;             /* nothing should be done */
        }
    }
    else if (SCR_ID_VDOEDT_FRAME_EDIT == id_scr)
    {
        if (MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME);
        }
        else if (MMI_VDOEDT_S_EDIT_FRAME == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME_IN);
        }
        else
        {
            return;             /* nothing should be done */
        }
    }

    stat = mmi_vdoedt_get_stat();
    if (MMI_VDOEDT_S_EDIT_FRAME == stat || MMI_VDOEDT_S_EDIT_CUT == stat)
#ifdef NO_LSK
    {
        SetKeyHandler(mmi_vdoedt_ck_down, KEY_LSK, KEY_EVENT_DOWN);//ghw222
        SetKeyHandler(mmi_vdoedt_ck_up, KEY_LSK, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_LSK, KEY_EVENT_DOWN);//ghw222
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_LSK, KEY_EVENT_UP);
    }

#else
    {
        SetKeyHandler(mmi_vdoedt_ck_down, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_ck_up, KEY_ENTER, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_key_dummy_hdlr, KEY_ENTER, KEY_EVENT_UP);
    }

#endif
    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_scr_rightkey_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_scr_rightkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
    {
        if (!g_vdoedt_key_cntx.in_rak.pressed)
        {
            g_vdoedt_cntx.movecount = 0;
            g_vdoedt_key_cntx.in_rak.pressed = TRUE;
            mmi_vdoedt_adjust_cut_right();            
        }
    }
    else if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
    {
        if (!g_vdoedt_key_cntx.out_rak.pressed)
        {
            g_vdoedt_cntx.movecount = 0;
            g_vdoedt_key_cntx.out_rak.pressed = TRUE;
            mmi_vdoedt_adjust_cut_right();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_scr_rightkey_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_scr_rightkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_adjust_cut_right);

    if (MMI_VDOEDT_S_CUT_PLAY != stat && MMI_VDOEDT_S_EDIT_PLAY != stat)
    {
        if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
        {
            g_vdoedt_key_cntx.in_rak.pressed = FALSE;
        }
        else if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
        {
            g_vdoedt_key_cntx.out_rak.pressed = FALSE;
        }
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_OUT_BTN | MMI_VDOEDT_R4W_IN_BTN | MMI_VDOEDT_R4W_EBAR;
        /* start a timer for seek and get frame. */
        gui_cancel_timer(mmi_vdoedt_update_cut_preview);
        gui_start_timer(MMI_VDOEDT_KEY_TRIG_DELAY, mmi_vdoedt_update_cut_preview);
        mmi_vdoedt_redraw();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_scr_leftkey_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_scr_leftkey_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();

    /* U16 id_scr = GetActiveScreenId(); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
    {
        if (!g_vdoedt_key_cntx.in_lak.pressed)
        {
            g_vdoedt_cntx.movecount = 0;
            g_vdoedt_key_cntx.in_lak.pressed = TRUE;
            mmi_vdoedt_adjust_cut_left();
        }
    }
    else if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
    {
        if (!g_vdoedt_key_cntx.out_lak.pressed)
        {
            g_vdoedt_cntx.movecount = 0;            
            g_vdoedt_key_cntx.out_lak.pressed = TRUE;
            mmi_vdoedt_adjust_cut_left();
        }
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_scr_leftkey_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_scr_leftkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_adjust_cut_left);

    if (MMI_VDOEDT_S_CUT_PLAY != stat && MMI_VDOEDT_S_EDIT_PLAY != stat)
    {
        if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
        {
            g_vdoedt_key_cntx.in_lak.pressed = FALSE;
        }
        else if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
        {
            g_vdoedt_key_cntx.out_lak.pressed = FALSE;
        }
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_OUT_BTN | MMI_VDOEDT_R4W_IN_BTN | MMI_VDOEDT_R4W_EBAR;
        /* start a timer for seek and get frame. */
        gui_cancel_timer(mmi_vdoedt_update_cut_preview);
        gui_start_timer(MMI_VDOEDT_KEY_TRIG_DELAY, mmi_vdoedt_update_cut_preview);
        mmi_vdoedt_redraw();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_adjust_cut_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inc     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_adjust_cut_internal(BOOL inc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 stat = mmi_vdoedt_get_stat();
    S32 step;

#ifdef __MMI_TOUCH_SCREEN__
    vdoedt_ui_obj_struct *p_key;
#endif 
    PS32 x = NULL;

    /* S32 x_min, x_max; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.movecount++;
    if (g_vdoedt_cntx.movecount <= 2)
    {
        step = 1;
    }
    else if (g_vdoedt_cntx.movecount <= 5)
    {
        step = 5;
    }
    else
    {
        step = 10;
    }

    if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        p_key = &g_vdoedt_key_cntx.cut_in;
    #endif 
        x = &g_vdoedt_key_cntx.x_cut_in;
    }
    else if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        p_key = &g_vdoedt_key_cntx.cut_out;
    #endif 
        x = &g_vdoedt_key_cntx.x_cut_out;
    }
    else
    {
        return; /* do nothing */
    }
    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_IN_BTN | MMI_VDOEDT_R4W_OUT_BTN | MMI_VDOEDT_R4W_EBAR;

    if (inc)
    {
        *x += step;
    }
    else
    {
        *x -= step;
    }

    mmi_vdoedt_check_cut_bound(x);
#ifdef __MMI_TOUCH_SCREEN__
    p_key->x = *x;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_get_min_cutbar_width
 * DESCRIPTION
 *  calculate the minium cutbar width (in pixels) depends on CUT screen or Frame screen.
 * PARAMETERS
 *  x       [IN]        the x-coordinate of position to check
 * RETURNS
 *  the pixels which is the minimum cutable width of the video or frame bar.
 *  it is MAX(width of cut cursor, MMI_VDOEDT_MIN_CUTABLE_LEN in pixels).
 *****************************************************************************/
S32 mmi_vdoedt_get_min_cutbar_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetActiveScreenId();
    S32 pix_ret = 0;
    U64 ms_total = 0;    
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* caculate the width of MIN_CUTABLE_LEN (in seconds) will be on the cut bar */
    if (SCR_ID_VDOEDT_VIDEO_CUT == scr_id)
    {
        /* only videos is able to be in cut screen */
        ASSERT(p_shot->ms_vdo_src_len != 0);        
        ms_total = p_shot->ms_vdo_src_len;
    }
    else if (SCR_ID_VDOEDT_FRAME_EDIT == scr_id)
    {
        ms_total = p_shot->ms_cut_out - p_shot->ms_cut_in;
    }
    else
    {
        ASSERT(scr_id == SCR_ID_VDOEDT_VIDEO_CUT || scr_id == SCR_ID_VDOEDT_FRAME_EDIT);
    }    
    ASSERT(ms_total >= MMI_VDOEDT_MIN_CUTABLE_LEN);
    /*----------------------------------------------------------------*/
    /* minw = (min_cut_widt * bg_width) / total duration              */
    /*----------------------------------------------------------------*/    
    pix_ret = (MMI_VDOEDT_MIN_CUTABLE_LEN * (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1)) / ms_total;

    /*----------------------------------------------------------------*/
    /* final check                                                    */
    /*----------------------------------------------------------------*/
    if (pix_ret < g_vdoedt_cut_osd_cntx.cutbar.in.w)
    {
        pix_ret = g_vdoedt_cut_osd_cntx.cutbar.in.w;
    }
    return pix_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_check_cut_bound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        the x-coordinate of position to check
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_check_cut_bound(PS32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_min;
    S32 x_max;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    S32 pix_min_w = mmi_vdoedt_get_min_cutbar_width();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_min = g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x - (g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1);
    if (x_min < 0)
    {
        x_min = 0;
    }
    x_max = x_min + g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1;
    if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
    {
        /*x_max = g_vdoedt_key_cntx.x_cut_out - g_vdoedt_cut_osd_cntx.cutbar.out.w;*/
        x_max = g_vdoedt_key_cntx.x_cut_out - pix_min_w;
        if (x_max < x_min)
        {
            x_max = x_min;
        }
    }
    else    /* MMI_VDOEDT_S_EDIT_CUT_OUT */
    {
        /*x_min = g_vdoedt_key_cntx.x_cut_in + g_vdoedt_cut_osd_cntx.cutbar.in.w;*/
        x_min = g_vdoedt_key_cntx.x_cut_in + pix_min_w;
        if (x_min > x_max)
        {
            x_min = x_max;
        }
    }

    if (x_max != x_min)
    {
        if (*x > x_max)
        {
            *x = x_max;
        }
        if (*x < x_min)
        {
            *x = x_min;
        }
    }
    else
    {
        *x = x_min;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_adjust_cut_right
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_adjust_cut_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_update_cut_preview);
    mmi_vdoedt_adjust_cut_internal(TRUE);
    mmi_vdoedt_redraw();
    gui_start_timer(100, mmi_vdoedt_adjust_cut_right);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_adjust_cut_left
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_adjust_cut_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S32 stat = mmi_vdoedt_get_stat(); */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_update_cut_preview);
    mmi_vdoedt_adjust_cut_internal(FALSE);  /* FALSE => decrease */
    mmi_vdoedt_redraw();
    gui_start_timer(100, mmi_vdoedt_adjust_cut_left);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_update_cut_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_update_cut_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    S32 x, btn_offset = g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    U64 *p_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_EDIT_CUT_IN == stat)
    {
        p_time = &(p_shot->ms_cut_in);
        x = g_vdoedt_key_cntx.x_cut_in + btn_offset;
    }
    else if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat)
    {
        p_time = &(p_shot->ms_cut_out);
        x = g_vdoedt_key_cntx.x_cut_out + btn_offset;
    }
    else if (MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
    {
        p_time = &(p_shot->ms_frm_in);
        x = g_vdoedt_key_cntx.x_cut_in + btn_offset;
    }
    else if (MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
    {
        p_time = &(p_shot->ms_frm_out);
        x = g_vdoedt_key_cntx.x_cut_out + btn_offset;
    }
    else
    {
        return;
    }

    if (SCR_ID_VDOEDT_VIDEO_CUT == GetActiveScreenId())
    {
        *p_time = (U64) ((x - g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x) *
                         p_shot->ms_vdo_src_len / (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1));
    }
    else
    {
        *p_time = (U64) ((x - g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x) *
                         (p_shot->ms_cut_out - p_shot->ms_cut_in) / (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1));
        *p_time += p_shot->ms_cut_in;   /* adjust offset to align to source media */
    }

    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_PWIN;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_show_option52
 * DESCRIPTION
 *  interal use for showing option52 screen.
 * PARAMETERS
 *  id_menu         [IN]        Menu id
 *  id_str          [IN]        String id
 *  gui_buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_show_option52(U16 id_menu, U16 id_str, PU8 gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 i;
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nItems = GetNumOfChild_Ext(id_menu);
    GetSequenceStringIds_Ext(id_menu, ItemList);
    for (i = 0; i < nItems; i++)
    {
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }
    SetParentHandler(id_menu);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        id_str,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,  /* hint list */
        0,
        0,
        gui_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_img_sel_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_img_sel_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    vdoedt_shot_struct *p_shot;
    BOOL opt_last_frm = FALSE;
    BOOL opt_first_frm = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_IMAGE_INSERT_OPTION, 0, mmi_vdoedt_entry_img_sel_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_IMAGE_INSERT_OPTION);

    if (g_vdoedt_cntx.shot_count)
    {
        p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

        if (g_vdoedt_cntx.i_act_shot != 0 &&
            VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot - 1]->src_type)
        {
            opt_last_frm = TRUE;
        }

        if (g_vdoedt_cntx.i_act_shot <= g_vdoedt_cntx.shot_count - 1 &&
            VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
        {
            opt_first_frm = TRUE;
        }
    }

    if (opt_last_frm)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_INS_IMG_LAST_FRAME);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_INS_IMG_LAST_FRAME);
    }
    if (opt_first_frm)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_INS_IMG_FIRST_FRAME);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_INS_IMG_FIRST_FRAME);
    }

    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_INS_IMG, STR_ID_VDOEDT_INS_IMG, gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_edit_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_edit_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 id_menu2show = MENU_ID_VDOEDT_MAIN_EDT_OPTION;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_VIDEO_OPTION, 0, mmi_vdoedt_entry_edit_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_VIDEO_OPTION);

    if (MMI_VDOEDT_MAX_CLIP_NUM > g_vdoedt_cntx.shot_count)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_INS_VDO);
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_INS_IMG);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_INS_VDO);
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_INS_IMG);
    }

    if (g_vdoedt_cntx.i_act_shot != g_vdoedt_cntx.shot_count)
    {
        /* hide "duration" for video, "cut" if it's image " */
        if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
        {
            mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_CUT_VDO);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOEDT_CUT_VDO);
        }
        if (VDOEDT_SRC_IMG_FILE > g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOEDT_SET_DUR);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_SET_DUR);
        }

        /* mmi_frm_hide_menu_item(MENU_ID_VDOEDT_EFFECT); */
    }
    else
    {
        id_menu2show = MENU_ID_VDOEDT_MAIN_EMPTY_OPTION;
    }
    mmi_vdoedt_show_option52(id_menu2show, STR_GLOBAL_OPTIONS, gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_preview_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_preview_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_PLAY_OPTION, 0, mmi_vdoedt_entry_preview_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_PLAY_OPTION);

    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_MAIN_P5W_OPTION, STR_GLOBAL_OPTIONS, gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_adjust_duration_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_adjust_duration_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U64 ms_2_check;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetCurrHiliteID();

    /* mmi_vdoedt_update_total_duration() */
    g_vdoedt_cntx.ms_t_total -= p_shot->s_img_dur * 1000;
    
    p_shot->s_img_dur = index + (MMI_VDOEDT_MIN_CUTABLE_LEN/1000);
    
    g_vdoedt_cntx.ms_t_total += p_shot->s_img_dur * 1000;

    p_shot->ms_cut_in = 0;
    p_shot->ms_cut_out = p_shot->s_img_dur * 1000;

    /* check frame length */
    ms_2_check = (g_vdoedt_cut_osd_cntx.cutbar.in.w * (p_shot->ms_cut_out - p_shot->ms_cut_in))/ (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1);
    if (ms_2_check < MMI_VDOEDT_MIN_CUTABLE_LEN)
    {
        ms_2_check = MMI_VDOEDT_MIN_CUTABLE_LEN;
    }
    if (p_shot->ms_frm_out - p_shot->ms_frm_in < ms_2_check ||
        p_shot->ms_frm_out > p_shot->ms_cut_out)
    {
        p_shot->ms_frm_out = p_shot->ms_cut_out;
        p_shot->ms_frm_in = p_shot->ms_cut_in;
    }
    
    DisplayPopup((PU8) GetString((U16) STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteNHistory(1);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_img_dur_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_img_dur_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 i;
    U16 nItems;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_IMAGE_DURATION, 0, mmi_vdoedt_entry_img_dur_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_IMAGE_DURATION);

    nItems = GetNumOfChild_Ext(MENU_ID_VDOEDT_SET_DUR);
    GetSequenceStringIds_Ext(MENU_ID_VDOEDT_SET_DUR, ItemList);
    for (i = 0; i < nItems; i++)
    {
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }
    SetParentHandler(MENU_ID_VDOEDT_SET_DUR);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_VDOEDT_DUR,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,  /* hint list */
        0,
        (g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->s_img_dur - (MMI_VDOEDT_MIN_CUTABLE_LEN/1000)),
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdoedt_img_adjust_duration_done, KEY_EVENT_UP);
    /* mmi_vdoedt_give_up_insert or give up set dur */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frame_sel_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frame_sel_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1.apply the frame to the video segment, */
    /* 2.then move back to frame edit screen  */
    if (g_vdoedt_cntx.old_s5g[0])
    {
        if (!(p_shot->choosed_frame || mmi_ucs2strlen(p_shot->p_txt)))
        {
            /* if this is the first time to add the frame, apply frame lenght to current image duration */
            p_shot->ms_frm_in = p_shot->ms_cut_in;
            p_shot->ms_frm_out = p_shot->ms_cut_out;
        }
        p_shot->choosed_frame = IMG_ID_VDOEDT_FRAME1 + g_vdoedt_cntx.old_s5g[0] - 1;
        g_vdoedt_cntx.old_s5g[0] = 0;
    }
    else
    {
        p_shot->choosed_frame = 0;
    }
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_frame_edit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_frame_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];    
    S32 min_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_shot->ms_cut_out - p_shot->ms_cut_in <= MMI_VDOEDT_MIN_CUTABLE_LEN)
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_VDO_IS_TOO_SHORT);
        return;
    }
    
    EntryNewScreen(
        SCR_ID_VDOEDT_FRAME_EDIT,
        mmi_vdoedt_exit_frame_edit_screen,
        mmi_vdoedt_entry_frame_edit_screen,
        NULL);
    
    mmi_vdoedt_util_suspend_bg_audio();
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FRAME_EDIT);

    if (NULL == gui_buffer)
    {
        g_vdoedt_cntx.t_in_old = p_shot->ms_frm_in;
        g_vdoedt_cntx.t_out_old = p_shot->ms_frm_out;
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_FRAME);

        if (p_shot->ms_frm_in < p_shot->ms_cut_in || p_shot->ms_frm_in > p_shot->ms_cut_out)
        {
            p_shot->ms_frm_in = p_shot->ms_cut_in;
        }
        if (p_shot->ms_frm_out > p_shot->ms_cut_out || p_shot->ms_frm_out <= p_shot->ms_frm_in)
        {
            p_shot->ms_frm_out = p_shot->ms_cut_out;
        }

        if (p_shot->ms_cut_in != p_shot->ms_frm_in)
        {
            g_vdoedt_key_cntx.x_cut_in =
                g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x -
                (g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1) +
                (p_shot->ms_frm_in - p_shot->ms_cut_in) *
                (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1) / (p_shot->ms_cut_out - p_shot->ms_cut_in) + 1;
        }
        else
        {
            g_vdoedt_key_cntx.x_cut_in = g_vdoedt_cut_osd_cntx.cutbar.in.x;
        }
        if (p_shot->ms_frm_out != p_shot->ms_cut_out)
        {
            g_vdoedt_key_cntx.x_cut_out =
                g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x -
                (g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1) +
                (p_shot->ms_frm_out - p_shot->ms_cut_in) *
                (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1) / (p_shot->ms_cut_out - p_shot->ms_cut_in);
        }
        else
        {
            g_vdoedt_key_cntx.x_cut_out = g_vdoedt_cut_osd_cntx.cutbar.out.x;
        }

        /* boundary check */
        if (g_vdoedt_key_cntx.x_cut_out > g_vdoedt_cut_osd_cntx.cutbar.out.x)
        {
            g_vdoedt_key_cntx.x_cut_out = g_vdoedt_cut_osd_cntx.cutbar.out.x;
        }
        if ( g_vdoedt_key_cntx.x_cut_in < g_vdoedt_cut_osd_cntx.cutbar.in.x)
        {
             g_vdoedt_key_cntx.x_cut_in = g_vdoedt_cut_osd_cntx.cutbar.in.x;
        }
        /* minimum width check */        
        min_w = mmi_vdoedt_get_min_cutbar_width();
        if (g_vdoedt_key_cntx.x_cut_out - g_vdoedt_key_cntx.x_cut_in < min_w)
        {
            if ((g_vdoedt_key_cntx.x_cut_in + min_w) < g_vdoedt_cut_osd_cntx.cutbar.out.x)
            {
                g_vdoedt_key_cntx.x_cut_out = g_vdoedt_key_cntx.x_cut_in + min_w;
            }
            else
            {
                g_vdoedt_key_cntx.x_cut_in = g_vdoedt_key_cntx.x_cut_out - min_w;
                if(g_vdoedt_key_cntx.x_cut_in < g_vdoedt_cut_osd_cntx.cutbar.in.x)
                {
                    g_vdoedt_key_cntx.x_cut_in = g_vdoedt_cut_osd_cntx.cutbar.in.x;
                }
            }
        }
        /* end boundary check */
        
    #ifdef __MMI_TOUCH_SCREEN__
        g_vdoedt_key_cntx.cut_in.x = g_vdoedt_key_cntx.x_cut_in;
        g_vdoedt_key_cntx.cut_out.x = g_vdoedt_key_cntx.x_cut_out;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    /*----------------------------------------------------------------*/
    /* Layer                                                          */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    gdi_layer_multi_layer_enable();

    mmi_vdoedt_util_create_layers(MMI_VDOEDT_LAYER_OSD | MMI_VDOEDT_LAYER_EFFECT | MMI_VDOEDT_LAYER_FRM | MMI_VDOEDT_LAYER_PLAY);
    gdi_layer_set_blt_layer(g_vdoedt_cntx.h_osd, g_vdoedt_cntx.h_play, g_vdoedt_cntx.h_frmtxt, g_vdoedt_cntx.h_effect);

    mmi_vdoedt_util_set_key_handlers(SCR_ID_VDOEDT_FRAME_EDIT);    
    /*----------------------------------------------------------------*/
    /* draw screen                                                    */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_ALL;
    mmi_vdoedt_redraw();

    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_vdoedt_util_set_touch_hdlr();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_frame_edit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_exit_frame_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_play_stop();

    gui_cancel_timer(mmi_vdoedt_update_cut_preview);
    gui_cancel_timer(mmi_vdoedt_adjust_cut_right);
    gui_cancel_timer(mmi_vdoedt_adjust_cut_left);    

    mmi_vdoedt_util_free_layers();
    gdi_layer_multi_layer_disable();
    if (g_vdoedt_cntx.h_osd)
    {
        gdi_layer_set_blt_layer(g_vdoedt_cntx.h_osd, 0, 0, 0);
        g_vdoedt_cntx.h_osd = GDI_NULL_HANDLE;
    }
    mmi_vdoedt_util_resume_bg_audio();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_exit_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_EMPTY != mmi_vdoedt_get_stat())
    {
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type) GetString(STR_ID_VDOEDT_EXIT_CONFIRM_MSG),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        SetLeftSoftkeyFunction(mmi_vdoedt_delete_main_scr, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_delete_main_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_delete_main_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_VDOEDT_MAIN);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_get_free_shot_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  -1 if no more shot mem available
 *  the index of array if any shot mem is available.
 *****************************************************************************/
S32 mmi_vdoedt_get_free_shot_idx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    vdoedt_context_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &g_vdoedt_cntx;
    for (i = 0; i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
    {
        if (!p->p_shot_mem[i]->used)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_alloc_shot_mem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_shot      [IN]        [out]   the shot pointer need to be setted
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_alloc_shot_mem(vdoedt_shot_struct **p_shot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = mmi_vdoedt_get_free_shot_idx();
    if (-1 != i)
    {
        memset((void*)(g_vdoedt_cntx.p_shot_mem[i]), 0, sizeof(vdoedt_shot_struct));

        *p_shot = g_vdoedt_cntx.p_shot_mem[i];

        (*p_shot)->used = TRUE;
    }
    else
    {
        p_shot = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_init_new_shot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        The index which will be inserted.
 * RETURNS
 *  
 *****************************************************************************/
static BOOL mmi_vdoedt_init_new_shot(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* move pointer and make the active shot is free */
    ASSERT(idx >= 0 && idx < MMI_VDOEDT_MAX_CLIP_NUM);
    if (g_vdoedt_cntx.shot_count + 1 <= MMI_VDOEDT_MAX_CLIP_NUM)
    {
        if (idx < g_vdoedt_cntx.shot_count)
        {
            /* inside, copy pointer to the left(start from tail.)r */
            for (i = g_vdoedt_cntx.shot_count - 1; i >= idx; i--)
            {
                g_vdoedt_cntx.p_shot[i + 1] = g_vdoedt_cntx.p_shot[i];
            }
        }
    }
    else
    {
        return FALSE;   /* fulled */
    }
    mmi_vdoedt_alloc_shot_mem(&g_vdoedt_cntx.p_shot[idx]);
    g_vdoedt_cntx.shot_count++;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_draw_img_file_in_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fname       [IN]        
 *  recw        [IN]        
 *  rech        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
gdi_result mmi_vdoedt_draw_img_file_in_rect(PS8 fname, S32 recw, S32 rech)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 src_w;
    S32 src_h;
    S32 res_w;  /* resized width */
    S32 res_h;
    S32 x;
    S32 y;
    gdi_result ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = gdi_image_get_dimension_file(fname, &src_w, &src_h);
    if (GDI_SUCCEED == ret)
    {
        if (src_w < recw && src_h < rech)
        {
            ret = gdi_image_draw_file((recw - src_w) >> 1, (rech - src_h) >> 1, fname);
        }
        else
        {
            gdi_image_util_fit_bbox(recw, rech, src_w, src_h, &x, &y, &res_w, &res_h);
            ret = gdi_image_draw_resized_file(x, y, res_w, res_h, fname);
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_video_apply_cut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_video_apply_cut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 xin, xout, btn_offset = g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    U64 ms_in, ms_out;
    U64 ms_trans_effect = MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL;
    U64 ms_2_check = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_play_stop();
    
    xin = g_vdoedt_key_cntx.x_cut_in + btn_offset;
    xout = g_vdoedt_key_cntx.x_cut_out + btn_offset;
    p_shot->ms_cut_in = (U64) ((xin - g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x) *
                                p_shot->ms_vdo_src_len / (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1));
    p_shot->ms_cut_out = (U64) ((xout - g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x) *
                                p_shot->ms_vdo_src_len / (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1));

    ms_in = p_shot->ms_cut_in;
    ms_out = p_shot->ms_cut_out;

    /* if cut is too short, disable transition effect because it's will not work. */
    if (ms_out - ms_in < (ms_trans_effect << 1) )
    {
        p_shot->in_effect = MMI_VDOEDT_EFFECT_IN_NONE;
        p_shot->out_effect = MMI_VDOEDT_EFFECT_OUT_NONE;
    }
    /* reset frame in/out position if it's out of boundary */
    if (p_shot->ms_frm_in < ms_in || 
        p_shot->ms_frm_in > ms_out ||
        p_shot->ms_frm_out > ms_out ||
        p_shot->ms_frm_out < ms_in)
    {
        p_shot->ms_frm_in = p_shot->ms_cut_in;
        p_shot->ms_frm_out = p_shot->ms_cut_out;
    }

    /* final check , if frame duration is too short (either on UI or cutscreen),
    re-align to  cut-in and cut-out                                             */
    ms_2_check = (g_vdoedt_cut_osd_cntx.cutbar.in.w * (p_shot->ms_cut_out - p_shot->ms_cut_in))/(g_vdoedt_cut_osd_cntx.cutbar.bg.width-1);
    if (ms_2_check < MMI_VDOEDT_MIN_CUTABLE_LEN)
    {
        ms_2_check = MMI_VDOEDT_MIN_CUTABLE_LEN;
    }
    if (p_shot->ms_frm_out - p_shot->ms_frm_in < ms_2_check)
    {
        p_shot->ms_frm_out = p_shot->ms_cut_out;
        p_shot->ms_frm_in = p_shot->ms_cut_in;
    }

    mmi_vdoedt_update_total_duration();

    if (mmi_vdoedt_update_cachefile())
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        GoBackHistory();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_cut_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_cut_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    S32 min_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VDOEDT_SRC_VIDEO != p_shot->src_type)
    {
        return;
    }
    else if (p_shot->ms_vdo_src_len  <= MMI_VDOEDT_MIN_CUTABLE_LEN)
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_VDO_IS_TOO_SHORT);
        return;
    }

    EntryNewScreen(SCR_ID_VDOEDT_VIDEO_CUT, mmi_vdoedt_exit_cut_screen, mmi_vdoedt_entry_cut_screen, NULL);
    mmi_vdoedt_util_suspend_bg_audio();    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_VIDEO_CUT);

    if (NULL == gui_buffer)
    {
        g_vdoedt_cntx.t_in_old = p_shot->ms_cut_in;
        g_vdoedt_cntx.t_out_old = p_shot->ms_cut_out;
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_CUT);
        if (p_shot->ms_cut_in != 0)
        {
            g_vdoedt_key_cntx.x_cut_in =
                g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x -
                (g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1) +
                p_shot->ms_cut_in * (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1) / p_shot->ms_vdo_src_len + 1;   /* +1 for rouding error. */
        }
        else
        {
            g_vdoedt_key_cntx.x_cut_in = g_vdoedt_cut_osd_cntx.cutbar.in.x;
        }
        if (p_shot->ms_cut_out != p_shot->ms_vdo_src_len)
        {
            g_vdoedt_key_cntx.x_cut_out =
                g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x -
                (g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1) +
                p_shot->ms_cut_out * (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1) / p_shot->ms_vdo_src_len + 1;  /* +1 for rounding eror */
        }
        else
        {
            g_vdoedt_key_cntx.x_cut_out = g_vdoedt_cut_osd_cntx.cutbar.out.x;
        }
        
        /* boundary check */
        if (g_vdoedt_key_cntx.x_cut_out > g_vdoedt_cut_osd_cntx.cutbar.out.x)
        {
            g_vdoedt_key_cntx.x_cut_out = g_vdoedt_cut_osd_cntx.cutbar.out.x;
        }
        if ( g_vdoedt_key_cntx.x_cut_in < g_vdoedt_cut_osd_cntx.cutbar.in.x)
        {
             g_vdoedt_key_cntx.x_cut_in = g_vdoedt_cut_osd_cntx.cutbar.in.x;
        }
        /* minimum width check */        
        min_w = mmi_vdoedt_get_min_cutbar_width();
        if (g_vdoedt_key_cntx.x_cut_out - g_vdoedt_key_cntx.x_cut_in < min_w)
        {
            if ((g_vdoedt_key_cntx.x_cut_in + min_w) < g_vdoedt_cut_osd_cntx.cutbar.out.x)
            {
                g_vdoedt_key_cntx.x_cut_out = g_vdoedt_key_cntx.x_cut_in + min_w;
            }
            else
            {
                g_vdoedt_key_cntx.x_cut_in = g_vdoedt_key_cntx.x_cut_out - min_w;
                if(g_vdoedt_key_cntx.x_cut_in < g_vdoedt_cut_osd_cntx.cutbar.in.x)
                {
                    g_vdoedt_key_cntx.x_cut_in = g_vdoedt_cut_osd_cntx.cutbar.in.x;
                }
            }
        }
        /* end boundary check */
        
    #ifdef __MMI_TOUCH_SCREEN__
        g_vdoedt_key_cntx.cut_in.x = g_vdoedt_key_cntx.x_cut_in;
        g_vdoedt_key_cntx.cut_out.x = g_vdoedt_key_cntx.x_cut_out;
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
    /*----------------------------------------------------------------*/
    /* Layer                                                          */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    gdi_layer_multi_layer_enable();
    mmi_vdoedt_util_create_layers(MMI_VDOEDT_LAYER_OSD | MMI_VDOEDT_LAYER_EFFECT | MMI_VDOEDT_LAYER_FRM | MMI_VDOEDT_LAYER_PLAY);
    gdi_layer_set_blt_layer(g_vdoedt_cntx.h_osd, g_vdoedt_cntx.h_play, g_vdoedt_cntx.h_frmtxt, g_vdoedt_cntx.h_effect);


    mmi_vdoedt_util_set_key_handlers(SCR_ID_VDOEDT_VIDEO_CUT);
    
    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_ALL;
    mmi_vdoedt_redraw();

    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_vdoedt_util_set_touch_hdlr();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_cut_edit_giveup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_cut_edit_giveup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_play_stop();

    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
    /* load back old shot data */
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_in = g_vdoedt_cntx.t_in_old;
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_out = g_vdoedt_cntx.t_out_old;
    g_vdoedt_cntx.t_in_old = g_vdoedt_cntx.t_out_old = 0;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_cut_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_exit_cut_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_update_cut_preview);
    gui_cancel_timer(mmi_vdoedt_adjust_cut_right);
    gui_cancel_timer(mmi_vdoedt_adjust_cut_left);
    mmi_vdoedt_play_stop();

    /* free things */
    mmi_vdoedt_util_free_layers();
    gdi_layer_multi_layer_disable();
    if (g_vdoedt_cntx.h_osd)
    {
        gdi_layer_set_blt_layer(g_vdoedt_cntx.h_osd, 0, 0, 0);
        g_vdoedt_cntx.h_osd = GDI_NULL_HANDLE;
    }
    mmi_vdoedt_util_resume_bg_audio();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_main_scr_upkey_hdlr
 * DESCRIPTION
 *  handle the upkey of main screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_main_scr_upkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_EDIT == mmi_vdoedt_get_stat())
    {
        g_vdoedt_key_cntx.pbar.pressed = TRUE;
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW);
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_EBAR | MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_main_scr_downkey_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_main_scr_downkey_hdlr(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_PREVIEW == mmi_vdoedt_get_stat() || MMI_VDOEDT_S_SEEK_DONE == mmi_vdoedt_get_stat())
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_EBAR | MMI_VDOEDT_R4W_STAT;
        mmi_vdoedt_redraw();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_main_scr_rightkey_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_main_scr_rightkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_context_struct *p_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_key_cntx.ffk.pressed)
    {

        /* gui_cancel_timer() */
        mmi_vdoedt_key_seek_up();
        /* g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR; */
    }
    else
    {
        p_cntx = &g_vdoedt_cntx;
        if (MMI_VDOEDT_S_EDIT == p_cntx->state)
        {
            if (p_cntx->shot_count)
            {
                /* shot[0,4], shotcount[0,5] */
                if (++(p_cntx->i_act_shot) >= p_cntx->shot_count)
                {
                    if (p_cntx->i_act_shot >= MMI_VDOEDT_MAX_CLIP_NUM)
                    {
                        p_cntx->i_act_shot = MMI_VDOEDT_MAX_CLIP_NUM - 1;
                    }
                    else
                    {
                        p_cntx->i_act_shot = p_cntx->shot_count;
                    }
                }
                /* g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_EBAR | MMI_VDOEDT_R4W_PWIN | MMI_VDOEDT_R4W_STAT; */
                g_vdoedt_cntx.flg_main_r4w = (MMI_VDOEDT_R4W_ALL & ~(MMI_VDOEDT_R4W_KEYFRMS));
                mmi_vdoedt_redraw();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_main_scr_leftkey_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_main_scr_leftkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_context_struct *p_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_key_cntx.rwk.pressed)
    {
        mmi_vdoedt_key_seek_up();
    }
    else
    {
        p_cntx = &g_vdoedt_cntx;
        if (MMI_VDOEDT_S_EDIT == p_cntx->state)
        {
            if (p_cntx->shot_count)
            {
                if (p_cntx->i_act_shot > 0)
                {
                    p_cntx->i_act_shot--;
                }
                /* g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_EBAR | MMI_VDOEDT_R4W_PWIN | MMI_VDOEDT_R4W_STAT; */
                g_vdoedt_cntx.flg_main_r4w = (MMI_VDOEDT_R4W_ALL & ~(MMI_VDOEDT_R4W_KEYFRMS));
                mmi_vdoedt_redraw();
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_frame_edit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_frame_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_FRAME_EDIT_OPTION, 0, mmi_vdoedt_entry_frame_edit_option, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FRAME_EDIT_OPTION);

    if (g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->choosed_frame ||
        mmi_ucs2strlen(g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt))
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_FRAME_EDT);
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_FRAME_CLEAR);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_FRAME_EDT);
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_FRAME_CLEAR);
    }

    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_FRAME, STR_ID_VDOEDT_FRAME, gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frame_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frame_edit_done(void)
{
    S32 xin, xout, btn_offset = g_vdoedt_cut_osd_cntx.cutbar.in.w >> 1;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    mmi_vdoedt_play_stop();
    
    xin = g_vdoedt_key_cntx.x_cut_in + btn_offset;
    xout = g_vdoedt_key_cntx.x_cut_out + btn_offset;
    
    p_shot->ms_frm_in = (U64) p_shot->ms_cut_in + ((xin - g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x) *
                     (p_shot->ms_cut_out - p_shot->ms_cut_in) / (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1));
   
    p_shot->ms_frm_out = (U64) p_shot->ms_cut_in +((xout - g_vdoedt_cut_osd_cntx.cutbar.bg.offset_x) *
                     (p_shot->ms_cut_out - p_shot->ms_cut_in) / (g_vdoedt_cut_osd_cntx.cutbar.bg.width - 1));
    
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT); 
    GoBackHistory();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frame_edit_giveup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_frame_edit_giveup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot->ms_frm_in = g_vdoedt_cntx.t_in_old;
    p_shot->ms_frm_out = g_vdoedt_cntx.t_out_old;
    g_vdoedt_cntx.t_in_old = g_vdoedt_cntx.t_out_old = 0;    
    if (MMI_VDOEDT_S_FRM_PLAY == mmi_vdoedt_get_stat())
    {
        mmi_vdoedt_play_stop();
    }
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_frame_txt_edt_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_frame_txt_edt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /* U8 asc_buffer[20]; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_FRAME_TEXT_EDITOR, NULL, mmi_vdoedt_entry_frame_txt_edt_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FRAME_TEXT_EDITOR);

    if (gui_buffer == NULL)
    {
        if(0 == mmi_ucs2strlen((PS8)(g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt))
            && 0 == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->choosed_frame)
        {
            g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_frm_in = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_in;
            g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_frm_out = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_out;
        }
        /* use fname_buff to store string */
        mmi_ucs2cpy(g_vdoedt_cntx.fname_buff, g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt);
    }
    
    ShowCategory5Screen(
        STR_ID_VDOEDT_TXT,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (PU8) g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt,
        MMI_VDOEDT_MAX_C4M_STRLEN,
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdoedt_entry_frame_text_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_vdoedt_back_from_editor_screen, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_vdoedt_return_to_editor_screen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_text_inline_select_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_text_inline_select_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return; /* do nothing now */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_load_old_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_load_old_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->in_effect = g_vdoedt_cntx.old_s5g[0];
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->out_effect = g_vdoedt_cntx.old_s5g[1];
    g_vdoedt_cntx.old_s5g[0] = g_vdoedt_cntx.old_s5g[1] = 0;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_inline_select_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_effect_inline_select_highlight_hdlr(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdoedt_effect_select_done_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_in_inline_select_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_effect_in_inline_select_highlight_hdlr(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->in_effect = i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_out_inline_select_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_effect_out_inline_select_highlight_hdlr(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->out_effect = i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_effect_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_effect_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 index;
    U16 j;
    UI_string_type *pstr_eff;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
    #ifdef __MMI_VDOEDT_VDO_EFFECT__
        0,
        IMG_GLOBAL_L3,
    #endif /* __MMI_VDOEDT_VDO_EFFECT__ */ 
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check if the duration is too short. */
    if (p_shot->ms_cut_out - p_shot->ms_cut_in < MMI_VDOEDT_MIN_CUTABLE_LEN)
    {
         mmi_vdoedt_popup(STR_ID_VDOEDT_VDO_IS_TOO_SHORT);
         return;
    }
    
    EntryNewScreen(SCR_ID_VDOEDT_VIDEO_EDIT_EFFECT, 0, mmi_vdoedt_entry_effect_option_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_VIDEO_EDIT_EFFECT);

    if (gui_buffer == NULL)
    {
        /* store old settings */
        g_vdoedt_cntx.old_s5g[0] = p_shot->in_effect;
        g_vdoedt_cntx.old_s5g[1] = p_shot->out_effect;
    #ifdef __MMI_VDOEDT_VDO_EFFECT__
        g_vdoedt_cntx.old_s5g[2] = p_shot->play_effect;
    #endif 
    }

    /* input_buffer = GetCurrNInputBuffer */

    /* init strings */
    pstr_eff = g_vdoedt_cntx.pstr_in_eff;
    for (j = MMI_VDOEDT_EFFECT_IN_NONE; j < MMI_VDOEDT_EFFECT_IN_COUNT; j++)
    {
        pstr_eff[j] = (UI_string_type) GetString((U16) STR_ID_VDOEDT_EFFECT_NONE + j);
    }
    pstr_eff = g_vdoedt_cntx.pstr_out_eff;
    pstr_eff[MMI_VDOEDT_EFFECT_OUT_NONE] = (UI_string_type) GetString((U16) STR_ID_VDOEDT_EFFECT_NONE);
    for (j = MMI_VDOEDT_EFFECT_OUT_NONE + 1; j < MMI_VDOEDT_EFFECT_OUT_COUNT; j++)
    {
        pstr_eff[j] = (UI_string_type) GetString((U16) STR_ID_VDOEDT_EFFECT_2_BLACK + j - 1);
    }
#ifdef __MMI_VDOEDT_VDO_EFFECT__
    pstr_eff = g_vdoedt_cntx.pstr_play_eff;
    pstr_eff[VDOEDT_EFFECT_NONE] = (UI_string_type) GetString((U16) STR_ID_VDOEDT_EFFECT_NONE);
    for (j = VDOEDT_EFFECT_GRAYSCALE; j <= VDOEDT_EFFECT_GRAYINV; j++)
    {
        pstr_eff[j] = (UI_string_type) GetString((U16) STR_ID_VDOEDT_EFFECT_GRAYSCALE + j - 1);
    }
#endif /* __MMI_VDOEDT_VDO_EFFECT__ */ 
    memset((void*)wgui_inline_items, 0, sizeof(InlineItem) * VDOEDT_EFFECT_TYPE_COUNT * 2);
    InitializeCategory57Screen();
    index = 0;

    /* In Effect    */
    SetInlineItemCaption(&wgui_inline_items[index++], (PU8) GetString((U16) STR_ID_VDOEDT_EFFECT_IN));
    SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[index++],
        MMI_VDOEDT_EFFECT_IN_COUNT,
        (U8 **) g_vdoedt_cntx.pstr_in_eff,
        &p_shot->in_effect);

    RegisterInlineSelectHighlightHandler(&wgui_inline_items[index - 1], mmi_vdoedt_effect_inline_select_highlight_hdlr);

    /* Out Effect   */
    SetInlineItemCaption(&wgui_inline_items[index++], (PU8) GetString((U16) STR_ID_VDOEDT_EFFECT_OUT));
    SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[index++],
        MMI_VDOEDT_EFFECT_OUT_COUNT,
        (U8 **) g_vdoedt_cntx.pstr_out_eff,
        &p_shot->out_effect);

    RegisterInlineSelectHighlightHandler(&wgui_inline_items[index - 1], mmi_vdoedt_effect_inline_select_highlight_hdlr);

#ifdef __MMI_VDOEDT_VDO_EFFECT__
    /* Video Effect */
    SetInlineItemCaption(&wgui_inline_items[index++], (PU8) GetString((U16) STR_ID_VDOEDT_EFFECT_PLAY));
    SetInlineItemActivation(&wgui_inline_items[index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[index++],
        VDOEDT_EFFECT_PLAY_COUNT,
        (U8 **) g_vdoedt_cntx.pstr_play_eff,
        (S32*) & (p_shot->play_effect));

    RegisterInlineSelectHighlightHandler(&wgui_inline_items[index - 1], mmi_vdoedt_effect_inline_select_highlight_hdlr);
#endif /* __MMI_VDOEDT_VDO_EFFECT__ */ 

    RegisterHighlightHandler(mmi_vdoedt_effect_inline_select_highlight_hdlr);
    ShowCategory57Screen(
        STR_ID_VDOEDT_EFFECT,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        item_icons,
        wgui_inline_items,
        1,
        gui_buffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdoedt_effect_select_done_hdlr);
    SetCategory57RightSoftkeyFunctions(mmi_vdoedt_load_old_setting, mmi_vdoedt_load_old_setting);
    DisableCategory57ScreenDone();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_select_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_effect_select_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayPopup((PU8) GetString((U16) STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SUCCESS_TONE);
    DeleteNHistory(1);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_filename_edit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_filename_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    PS8 p_ext = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_FILENAME_EDITOR_OPTION, 0, mmi_vdoedt_entry_filename_edit_option, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FILENAME_EDITOR_OPTION);

    if (gui_buffer != NULL)
    {
        p_ext = mmi_fmgr_extract_ext_file_name((PS8)g_vdoedt_cntx.fname_buff);
        if (NULL != p_ext)
        {
            /* remove the extension*/
            p_ext -= 2;
            *p_ext = *(p_ext+1) = 0;
        }
    }

    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_FILENAME_OPTION, STR_GLOBAL_OPTIONS, gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_frame_text_edit_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_frame_text_edit_option(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_FRAME_TEXT_EDITOR_OPTION, 0, mmi_vdoedt_entry_frame_text_edit_option, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FRAME_TEXT_EDITOR_OPTION);    /* MAUI_474062 */

    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_TEXT_E4R_OPTION, STR_GLOBAL_OPTIONS, gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_img_file_select_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_img_file_select_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    
    PopupNoSupport();
    return;
    
#else /* __MTK_TARGET__ */  
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_VDOEDT,
        FMGR_SELECT_FILE,
        filter,
        (PS8) (S8*) L"root",
        (PsExtFuncPtr) mmi_vdoedt_media_sel_result_callback);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_from_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  prev        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_from_frame(BOOL prev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;
    S32 i = g_vdoedt_cntx.i_act_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.shot_count < MMI_VDOEDT_MAX_CLIP_NUM)
    {
        mmi_vdoedt_init_new_shot(i);
        p_shot = g_vdoedt_cntx.p_shot[i];
        p_shot->s_img_dur = MMI_VDOEDT_IMG_DUR_DEFAULT;
        p_shot->ms_frm_in = p_shot->ms_cut_in = 0;
        p_shot->ms_frm_out = p_shot->ms_cut_out = p_shot->s_img_dur * 1000;
        g_vdoedt_cntx.ms_t_total += p_shot->s_img_dur * 1000;

        /* assumed that shot is exist */
        if (prev)
        {
            p_shot->src_type = VDOEDT_SRC_LAST_FRAME;
        }
        else
        {
            p_shot->src_type = VDOEDT_SRC_FIRST_FRAME;
        }
        if (mmi_vdoedt_update_cachefile())
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        }
        else
        {
            /* update cache file failed. */
            if(prev)
            {
                i = g_vdoedt_cntx.i_act_shot - 1;
            }
            else
            {
                i = g_vdoedt_cntx.i_act_shot + 1;
            }
            mmi_vdoedt_shot_remove_internal(g_vdoedt_cntx.i_act_shot);
            mmi_vdoedt_shot_remove_internal(i);
            mmi_vdoedt_popup(STR_ID_VDOEDT_BAD_VDO_REMOVE_NOTIFY);
            DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
            g_vdoedt_cntx.i_act_shot = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_ins_last_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_ins_last_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the last frame of previous video */
    mmi_vdoedt_img_from_frame(TRUE);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_ins_first_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_ins_first_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the first frame of next video */
    mmi_vdoedt_img_from_frame(FALSE);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_ins_color_draw_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  page_start_idx      [IN]        
 *  page_end_idx        [IN]        
 *  is_hilighted        [IN]        
 *  is_need_update      [IN]        
 *  is_new_page         [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_ins_color_draw_callback(
        S32 idx,
        S32 page_start_idx,
        S32 page_end_idx,
        BOOL is_hilighted,
        BOOL is_need_update,
        BOOL is_new_page,
        S32 x1,
        S32 y1,
        S32 x2,
        S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const color *c = &g_vdoedt_text_color_list[idx];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_need_update)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        gdi_draw_solid_rect(x1, y1, x2, y2, gdi_act_color_from_rgb(255, c->r, c->g, c->b));

        gdi_layer_pop_clip();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_ins_hide_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_ins_hide_callback(S32 idx)
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
 *  mmi_vdoedt_img_ins_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_ins_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = g_vdoedt_cntx.i_act_shot;
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.shot_count < MMI_VDOEDT_MAX_CLIP_NUM)
    {
        mmi_vdoedt_init_new_shot(i);
        p_shot = g_vdoedt_cntx.p_shot[i];
        p_shot->s_img_dur = MMI_VDOEDT_IMG_DUR_DEFAULT;
        p_shot->ms_frm_in = p_shot->ms_cut_in = 0;
        p_shot->ms_frm_out = p_shot->ms_cut_out = p_shot->s_img_dur * 1000;
        g_vdoedt_cntx.ms_t_total += p_shot->s_img_dur * 1000;

        p_shot->src_type = VDOEDT_SRC_COLOR;
        p_shot->c_shot = &g_vdoedt_text_color_list[g_vdoedt_cntx.old_value];

        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        g_vdoedt_cntx.old_value = 0;

        DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
        GoBackHistory();
    }
    else
    {
        ASSERT(g_vdoedt_cntx.shot_count < MMI_VDOEDT_MAX_CLIP_NUM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_color_select_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_color_select_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reuse variable */
    g_vdoedt_cntx.old_value = idx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_img_ins_color_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_img_ins_color_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_IMAGE_COLOR_SEL, 0, mmi_vdoedt_entry_img_ins_color_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_IMAGE_COLOR_SEL);

    RegisterHighlightHandler(mmi_vdoedt_img_color_select_highlight_hdlr);

    ShowCategory214Screen(
        STR_ID_VDOEDT_COLOR,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        VDOEDT_COLOR_COUNT,                /* num of item */
        mmi_vdoedt_img_ins_color_draw_callback, /* draw image callback */
        mmi_vdoedt_img_ins_hide_callback,       /* hide image callback */
        6,                                      /* number per row */
        4,                                      /* number per col */
        0,                                      /* hilighted item */
        (U8*) gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdoedt_img_ins_color, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_shot_remove_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_shot_remove_internal(S32 i_remov)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.shot_count > 0)
    {
        if (i_remov < g_vdoedt_cntx.shot_count)
        {
            p_shot = g_vdoedt_cntx.p_shot[i_remov];
            /* reset shot memory, free memories */
            if (VDOEDT_SRC_VIDEO == p_shot->src_type)
            {
                mdi_video_edt_close_clip_file(p_shot->h_video);
            }
            memset((void*)p_shot, 0, sizeof(vdoedt_shot_struct));
            p_shot->used = 0;

            if (i_remov < g_vdoedt_cntx.shot_count && i_remov != MMI_VDOEDT_MAX_CLIP_NUM - 1)
            {
                /* fall inside */
                for (; i_remov < g_vdoedt_cntx.shot_count - 1; i_remov++)
                {
                    g_vdoedt_cntx.p_shot[i_remov] = g_vdoedt_cntx.p_shot[i_remov + 1];
                }
                g_vdoedt_cntx.p_shot[i_remov] = NULL;
            }
            if (--g_vdoedt_cntx.shot_count == 0)
            {
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EMPTY);
            }
            else
            {
                if (g_vdoedt_cntx.i_act_shot > 0 && g_vdoedt_cntx.shot_count == g_vdoedt_cntx.i_act_shot)
                {
                    g_vdoedt_cntx.i_act_shot = g_vdoedt_cntx.shot_count - 1;
                }
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
            }
            /* get new totoal time */
            mmi_vdoedt_update_total_duration();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_shot_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_shot_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_shot_remove_internal(g_vdoedt_cntx.i_act_shot);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_seek_result_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_vdoedt_seek_result_handler(MDI_RESULT res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i_shot_remov;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MDI_RES_VDOPLY_SUCCEED != res)
    {
        i_shot_remov = g_vdoedt_cntx.i_act_shot;
        mmi_vdoedt_popup(STR_ID_VDOEDT_BAD_VDO_REMOVE_NOTIFY); /* the i_act_shot will be reset when exit main screen */
        mmi_vdoedt_shot_remove_internal(i_shot_remov);
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_update_total_duration
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_update_total_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, t = 0; i < g_vdoedt_cntx.shot_count; i++)
    {
        if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[i]->src_type)
        {
            ASSERT(g_vdoedt_cntx.p_shot[i]->ms_cut_out > g_vdoedt_cntx.p_shot[i]->ms_cut_in);
            t += g_vdoedt_cntx.p_shot[i]->ms_cut_out - g_vdoedt_cntx.p_shot[i]->ms_cut_in;
        }
        else
        {
            t += g_vdoedt_cntx.p_shot[i]->s_img_dur * 1000;
        }
    }
    g_vdoedt_cntx.ms_t_total = t;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_util_create_layers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_util_create_layers(U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 p_tmp;
    p_vdoedt_context_struct p_cntx = &g_vdoedt_cntx;
    vdoedt_osd_play_wnd_struct *p_rect = &(g_vdoedt_main_osd_cntx.play_wnd);
    gdi_result g_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & MMI_VDOEDT_LAYER_OSD)
    {
        gdi_layer_get_base_handle(&p_cntx->h_osd);
    }
    if (flag & MMI_VDOEDT_LAYER_PLAY)
    {
        /* preview layer */
        g_ret = gdi_layer_create(p_rect->offset_x, p_rect->offset_y, p_rect->width, p_rect->height, &p_cntx->h_play);
        ASSERT(GDI_SUCCEED == g_ret);
    }

    if (flag & MMI_VDOEDT_LAYER_KEYFRM)
    {
        /* keyframe layer */
        g_ret = gdi_layer_create(
                    g_vdoedt_main_osd_cntx.editbar.bg.offset_x,
                    g_vdoedt_main_osd_cntx.editbar.bg.offset_y,
                    g_vdoedt_main_osd_cntx.editbar.bg.width,
                    g_vdoedt_main_osd_cntx.editbar.bg.height,
                    &p_cntx->h_keyframe);
        ASSERT(GDI_SUCCEED == g_ret);
        gdi_layer_push_and_set_active(p_cntx->h_keyframe);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    if (flag & MMI_VDOEDT_LAYER_FRM || flag & MMI_VDOEDT_LAYER_EFFECT)
    {
        /* frame/txt layer */
        p_tmp = (PU8) mmi_frm_scrmem_alloc(MMI_VDOEDT_PREV_BUF_SIZE << 1);
        if (p_tmp != NULL)
        {
            p_cntx->p_scrmem = p_tmp;
            /* g_ret = gdi_layer_create_double_using_outside_memory( */
            g_ret = gdi_layer_create_using_outside_memory(
                        p_rect->offset_x,
                        p_rect->offset_y,
                        p_rect->width,
                        p_rect->height,
                        &p_cntx->h_frmtxt,
                        p_cntx->p_scrmem,
                        MMI_VDOEDT_PREV_BUF_SIZE);
            ASSERT(GDI_SUCCEED == g_ret);
            gdi_layer_push_and_set_active(p_cntx->h_frmtxt);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            /* effect layer */
            p_tmp += MMI_VDOEDT_PREV_BUF_SIZE;
            g_ret = gdi_layer_create_using_outside_memory(
                        p_rect->offset_x,
                        p_rect->offset_y,
                        p_rect->width,
                        p_rect->height,
                        &p_cntx->h_effect,
                        p_tmp,
                        MMI_VDOEDT_PREV_BUF_SIZE << 1);
            ASSERT(GDI_SUCCEED == g_ret);
            /* set opacity of effect layer to 0 */
            gdi_layer_push_and_set_active(p_cntx->h_effect);
            gdi_layer_set_opacity(TRUE, 0);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            /* mem allocation error */
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_util_free_layers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_util_free_layers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.h_play != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_vdoedt_cntx.h_play);
        g_vdoedt_cntx.h_play = GDI_NULL_HANDLE;
    }
    g_vdoedt_cntx.h_osd = GDI_NULL_HANDLE;
    if (g_vdoedt_cntx.h_frmtxt != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_vdoedt_cntx.h_frmtxt);
        g_vdoedt_cntx.h_frmtxt = GDI_NULL_HANDLE;
    }
    if (g_vdoedt_cntx.h_effect != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_vdoedt_cntx.h_effect);
        g_vdoedt_cntx.h_effect = GDI_NULL_HANDLE;
    }
    if (g_vdoedt_cntx.h_keyframe != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_vdoedt_cntx.h_keyframe);
        g_vdoedt_cntx.h_keyframe = GDI_NULL_HANDLE;
    }

    if (g_vdoedt_cntx.p_scrmem)
    {
        mmi_frm_scrmem_free(g_vdoedt_cntx.p_scrmem);
        g_vdoedt_cntx.p_scrmem = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_remove_hilight_shot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_remove_hilight_shot(void)
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
        get_string(STR_ID_VDOEDT_REMOVE_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    SetLeftSoftkeyFunction(mmi_vdoedt_shot_remove, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_save_prepare_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_vdoedt_save_prepare_path()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive = 0;
    S8 buff[8];
    FS_HANDLE h_file = 0;
    U16 errstr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_PHONE == g_vdoedt_cntx.old_value)
    {
        drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    }
    else if (MMI_VDOEDT_CARD == g_vdoedt_cntx.old_value)
    {
        drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    }
    else
    {
        ASSERT(MMI_VDOEDT_PHONE == g_vdoedt_cntx.old_value || MMI_VDOEDT_CARD == g_vdoedt_cntx.old_value);
    }

    if (drive)
    {
        /* check space */
        /* calculate how many disk space needed */
        sprintf(buff, "%c:\\", drive);
        mmi_asc_to_ucs2(g_vdoedt_cntx.fname_buff, buff);
        mmi_ucs2cat(g_vdoedt_cntx.fname_buff, (PS8) FMGR_DEFAULT_FOLDER_VIDEO);
        h_file = FS_Open((kal_uint16*) g_vdoedt_cntx.fname_buff, FS_OPEN_DIR | FS_READ_ONLY);
        if (h_file < FS_NO_ERROR)
        {
            /* create dir */
            drive = FS_CreateDir((PU16) g_vdoedt_cntx.fname_buff);
            if (drive < 0)
            {
                if (drive == FS_WRITE_PROTECTION)
                {
                    errstr = FMGR_FS_WRITE_PROTECTION_TEXT;
                }
                else if (drive == FS_DISK_FULL)
                {
                    errstr = FMGR_FS_DISK_FULL_TEXT;
                }
                else if (drive == FS_ROOT_DIR_FULL)
                {
                    errstr = FMGR_FS_ROOT_DIR_FULL_TEXT;
                }
                
                if (errstr)
                {
                    mmi_vdoedt_popup(errstr);
                }               
            }
        }
        else
        {
            FS_Close(h_file);
        }
    }
    return drive;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_save_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_save_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[5];
    S8 u_buf[10];
    U32 req_size = 0;
    S32 drive = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if disk space is enough, if not, enter filemanager */
    /* use total time. * bps */
    /* req_size = (1000 + g_vdoedt_cntx.ms_t_total * 100 / 1000) >> 8; */
    req_size = g_vdoedt_cntx.ms_t_total * MMI_VDOEDT_BYTE_PER_SEC / 1000;

    if (MMI_VDOEDT_PHONE == g_vdoedt_cntx.old_value)
    {
        drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    }
    else if (MMI_VDOEDT_CARD == g_vdoedt_cntx.old_value)
    {
        drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    }
    sprintf(buf, "%c:\\", (S8) drive);
    mmi_asc_to_ucs2(u_buf, buf);

    if (mmi_vdoedt_check_disk_space(req_size, u_buf))
    {
        if (mmi_vdoedt_save_prepare_path() >= 0 )
        {
            g_vdoedt_cntx.n_pathstr_len = mmi_ucs2strlen(g_vdoedt_cntx.fname_buff);
            mmi_vdoedt_entry_save_filename_edt_screen();
        }
        else
        {
            return; /* create saving path failed */
        }
    }
    else
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_NO_SAVE_SPACE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_util_set_key_handlers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_util_set_key_handlers(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LSK & RSK */
#ifdef NO_LSK
    SetKeyHandler(mmi_vdoedt_lsk_down, KEY_SEND1, KEY_EVENT_DOWN);//ghw222
    SetKeyHandler(mmi_vdoedt_lsk_up, KEY_SEND1, KEY_EVENT_UP);

#else
    SetKeyHandler(mmi_vdoedt_lsk_down, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdoedt_lsk_up, KEY_LSK, KEY_EVENT_UP);

#endif
    SetKeyHandler(mmi_vdoedt_rsk_down, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdoedt_rsk_up, KEY_RSK, KEY_EVENT_UP);
    g_vdoedt_key_cntx.lsk.pressed = g_vdoedt_key_cntx.rsk.pressed = FALSE;
    g_vdoedt_key_cntx.ck.pressed = FALSE;
    
    /* only for main/cut/frame edit/ frame select screen */
    if (SCR_ID_VDOEDT_MAIN == scr_id)
    {
        if (MMI_VDOEDT_S_EMPTY != mmi_vdoedt_get_stat())
#ifdef NO_LSK
    {
        if (MMI_VDOEDT_S_EMPTY != mmi_vdoedt_get_stat())
        {
            SetKeyHandler(mmi_vdoedt_ck_down, KEY_LSK, KEY_EVENT_DOWN);//ghw222
            SetKeyHandler(mmi_vdoedt_ck_up, KEY_LSK, KEY_EVENT_UP);
        }

#else
        {
            SetKeyHandler(mmi_vdoedt_ck_down, KEY_ENTER, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdoedt_ck_up, KEY_ENTER, KEY_EVENT_UP);
        }

#endif
        else
        {
            ClearKeyHandler(KEY_ENTER, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP);
        }
        SetKeyHandler(mmi_vdoedt_main_scr_upkey_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_main_scr_downkey_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_main_scr_rightkey_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_main_scr_leftkey_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);

        SetKeyHandler(mmi_vdoedt_key_ff_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_key_rw_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_vol_inc, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_vol_dec, KEY_VOL_DOWN, KEY_EVENT_UP);

        g_vdoedt_key_cntx.rwk.pressed = g_vdoedt_key_cntx.ffk.pressed = FALSE;
        
    }
    else if (SCR_ID_VDOEDT_VIDEO_CUT == scr_id || SCR_ID_VDOEDT_FRAME_EDIT == scr_id)
    {
#ifdef NO_LSK
        SetKeyHandler(mmi_vdoedt_ck_down, KEY_LSK, KEY_EVENT_DOWN);//ghw222
        SetKeyHandler(mmi_vdoedt_ck_up, KEY_LSK, KEY_EVENT_UP);

#else
        SetKeyHandler(mmi_vdoedt_ck_down, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_ck_up, KEY_ENTER, KEY_EVENT_UP);

#endif
        SetKeyHandler(mmi_vdoedt_cut_scr_leftkey_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_cut_scr_leftkey_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_cut_scr_rightkey_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_cut_scr_rightkey_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_cut_scr_upkey_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_cut_scr_downkey_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_vol_inc, KEY_VOL_UP, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_vol_dec, KEY_VOL_DOWN, KEY_EVENT_UP);

        g_vdoedt_key_cntx.in_lak.pressed = g_vdoedt_key_cntx.out_lak.pressed = FALSE;
        g_vdoedt_key_cntx.in_rak.pressed = g_vdoedt_key_cntx.out_rak.pressed = FALSE;
        
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == scr_id)
    {
        SetKeyHandler(mmi_vdoedt_frm_sel_rak_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_frm_sel_lak_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_vdoedt_frm_sel_rak_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdoedt_frm_sel_lak_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        g_vdoedt_key_cntx.frame_n.pressed = g_vdoedt_key_cntx.frame_pre.pressed = FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_util_suspend_bg_audio
 * DESCRIPTION
 *  suspend audio player background play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_util_suspend_bg_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_suspend_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_util_resume_bg_audio
 * DESCRIPTION
 *  resume audio player background play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_util_resume_bg_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_save_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_save_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    PU8 gui_buffer;
    S32 drive;
    char buf[16];
    char ubuf[32];
    FS_HANDLE h_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_SAVE_OPTION, NULL, mmi_vdoedt_entry_save_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_SAVE_OPTION);
    drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if (drive >= FS_NO_ERROR)
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_2_PHONE);
        g_vdoedt_cntx.old_value = drive;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_2_PHONE);
    }

    drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    sprintf(buf, "%c:\\", (U8) drive);
    mmi_asc_to_ucs2(ubuf, buf);
    h_file = FS_Open((kal_uint16*) ubuf, FS_OPEN_DIR | FS_READ_ONLY);
    if (h_file >= FS_NO_ERROR)
    {
        FS_Close(h_file);
        mmi_frm_unhide_menu_item(MENU_ID_VDOEDT_2_CARD);
        g_vdoedt_cntx.old_value = drive;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOEDT_2_CARD);
    }

    mmi_vdoedt_show_option52(MENU_ID_VDOEDT_SAVE, STR_GLOBAL_SAVE, gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdoedt_save_pre_check, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_save_filename_edt_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_save_filename_edt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 asc_buffer[64];
    S32 offset = g_vdoedt_cntx.n_pathstr_len;
    PS8 p_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_FILENAME_EDITOR, NULL, mmi_vdoedt_entry_save_filename_edt_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FILENAME_EDITOR);
    p_buff = g_vdoedt_cntx.fname_buff + offset * ENCODING_LENGTH;

    if (NULL == gui_buffer)
    {
        sprintf((PS8) asc_buffer, MMI_VDOEDT_SAVENAME_PREFIX);
        mmi_asc_to_ucs2(p_buff, (PS8) asc_buffer);
    }

    ShowCategory5Screen(
        STR_GLOBAL_SAVE,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (PU8) p_buff,
        (MMI_VDOEDT_MAX_SNAME_MAX_LEN - FMGR_MAX_EXT_LEN - offset),
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdoedt_entry_filename_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_vdoedt_back_from_editor_screen, KEY_EVENT_UP);
    RegisterInputMethodScreenCloseFunction(mmi_vdoedt_return_to_editor_screen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_back_from_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_back_from_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_VDOEDT_FRAME_TEXT_EDITOR  == scr_id)
    {
        mmi_ucs2cpy(g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt, g_vdoedt_cntx.fname_buff);
    }
#if 0     /* MAUI_00469867 */
/* under construction !*/
#endif    
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_return_to_editor_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_return_to_editor_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteNHistory(1);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_init_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

#ifdef __MMI_VDOEDT_USE_APPMEM__
    p_vdoedt_shot_struct p_tmp = g_vdoedt_cntx.p_shot_mem[0];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_vdoedt_cntx.shot_count; i++)
    {
        if (g_vdoedt_cntx.p_shot[i]->h_video != NULL)
        {
            mdi_video_edt_close_clip_file(g_vdoedt_cntx.p_shot[i]->h_video);
        }
    }
    mmi_vdoedt_remov_cachefile();

    /* init contex then re_enter videodeitor */
    memset(&g_vdoedt_cntx, 0, sizeof(vdoedt_context_struct));

#ifdef __MMI_VDOEDT_USE_APPMEM__
    g_vdoedt_cntx.p_shot_mem[0] = p_tmp;
    memset((void*)g_vdoedt_cntx.p_shot_mem[0], 0, sizeof(vdoedt_shot_struct) * 5);
    for (i = 1; i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
    {
        g_vdoedt_cntx.p_shot_mem[i] = (p_tmp + i);
    }

#else /* __MMI_VDOEDT_USE_APPMEM__ */ 
    for (i = 0; i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
    {
        g_vdoedt_cntx.p_shot_mem[i] = g_vdoedt_cntx.shot_mem[i];
    }
#endif /* __MMI_VDOEDT_USE_APPMEM__ */ 

    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EMPTY);

    if (IsScreenPresent(SCR_ID_VDOEDT_MAIN))
    {
        DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_new_w7e
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_new_w7e(void)
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
        get_string(STR_ID_VDOEDT_NEW_W7E),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    SetLeftSoftkeyFunction(mmi_vdoedt_init_cntx, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_filename_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_filename_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fbuff[MMI_VDOEDT_MAX_SNAME_MAX_LEN*ENCODING_LENGTH];
    FS_HANDLE h_file = 0;
    PS8 pfname = g_vdoedt_cntx.fname_buff + g_vdoedt_cntx.n_pathstr_len * ENCODING_LENGTH;
    PS8 p_skip_space = pfname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if file already exists */

    p_skip_space = mmi_fmgr_skip_space(pfname);
    if (mmi_ucs2strlen(pfname) == 0)
    {
        mmi_vdoedt_popup(STR_FMGR_EMPTY_FILENAME);
        DeleteScreenIfPresent(SCR_ID_VDOEDT_FILENAME_EDITOR_OPTION);
        return;
    }
    else if (!mmi_fmgr_is_filename_valid(pfname))
    {
        mmi_vdoedt_popup(FMGR_FS_INVALID_FILENAME_TEXT);
        DeleteScreenIfPresent(SCR_ID_VDOEDT_FILENAME_EDITOR_OPTION);  
        return;
    }
    
    if(p_skip_space != pfname)
    {
        mmi_ucs2cpy(fbuff, p_skip_space);
        mmi_ucs2cpy(pfname, fbuff);
    }

    mmi_ucs2cat(g_vdoedt_cntx.fname_buff, (PS8) L".3gp");
    h_file = FS_Open((kal_uint16*) g_vdoedt_cntx.fname_buff, FS_READ_ONLY);

    if (h_file >= FS_NO_ERROR)
    {
        FS_Close(h_file);
        /* prompt over write or not. */
        DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type) GetString(STR_ID_VDOEDT_O7E_CNF),
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
        SetLeftSoftkeyFunction(mmi_vdoedt_enc_file_overwrite, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        /* prepare to encode */
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SAVING);
        mmi_vdoedt_entry_encode_screen();
        DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_file_overwrite
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_file_overwrite(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fs_ret;
    S32 len_str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete file */
    fs_ret = FS_Delete((kal_uint16*) g_vdoedt_cntx.fname_buff);
    if (FS_NO_ERROR == fs_ret)
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SAVING);
        mmi_vdoedt_entry_encode_screen();
        DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    }
    else
    {
        mmi_vdoedt_popup(GetFileSystemErrorString(fs_ret));
        len_str = mmi_ucs2strlen(g_vdoedt_cntx.fname_buff);

        g_vdoedt_cntx.fname_buff[(len_str - 4) * ENCODING_LENGTH] = 0;      /* strlen(".3gp") == 4 */
        g_vdoedt_cntx.fname_buff[(len_str - 4) * ENCODING_LENGTH + 1] = 0;
        DeleteNHistory(1);
    }
}

/*----------------------------------------------------------------------------*/
/* Hilite handlers                                                            */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_save_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_save_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_new_w7e
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_new_w7e(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_new_w7e, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_remove_hilight_shot, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_ins_vdo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_ins_vdo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_video_sel, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_video_sel, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_ins_img
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_ins_img(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_img_sel_option_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_img_sel_option_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_effect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_effect_option_screen, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_cut_vdo
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_cut_vdo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_cut_screen, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_set_dur
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_set_dur(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_img_dur_option_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_img_dur_option_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_edt_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_edt_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_frame_edit_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_frame_edit_option, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_img_ins_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_img_ins_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_img_file_select_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_img_file_select_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_img_ins_last_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_img_ins_last_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_img_ins_last_frame, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_img_ins_first_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_img_ins_first_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_img_ins_first_frame, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_img_ins_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_img_ins_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_img_ins_color_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdoedt_entry_img_ins_color_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_text_edit_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_text_edit_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_VDOEDT_FILENAME_EDITOR_OPTION == GetActiveScreenId())
    {
        SetLeftSoftkeyFunction(mmi_vdoedt_filename_edit_done, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_vdoedt_entry_text_property_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_text_edit_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_text_edit_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_VDOEDT_FRAME_TEXT_EDITOR_OPTION == GetActiveScreenId())
    {
        mmi_ucs2cpy(g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt, g_vdoedt_cntx.fname_buff);
    }
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_text_edit_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_text_edit_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SetLeftSoftkeyFunction(mmi_vdoedt_back_from_editor_screen, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdoedt_text_edit_cancel, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_text_sel_inp_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_text_sel_inp_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_2phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_2phone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.old_value = MMI_VDOEDT_PHONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_2card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_2card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.old_value = MMI_VDOEDT_CARD;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_video_exit_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_video_exit_insert(void)
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
 *  mmi_vdoedt_video_do_insert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_video_do_insert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 fname;
    mdi_video_info_struct v_info;
    vdoedt_shot_struct *p_shot;
    U8 *gui_buffer;
    BOOL is_valid = FALSE;
    mdi_result mdi_openresult;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* insert the video into edit bar, extract keyframe. */
    /* use temp screen id for now */
    EntryNewScreen(SCR_ID_VDOEDT_IMAGE_COLOR_SEL, mmi_vdoedt_video_exit_insert, mmi_vdoedt_video_do_insert, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_IMAGE_COLOR_SEL);

    if (gui_buffer == NULL)
    {
        if (g_vdoedt_cntx.shot_count + 1 <= MMI_VDOEDT_MAX_CLIP_NUM)
        {
            fname = (PS8) mmi_frm_scrmem_alloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
            mmi_fmgr_util_load_filepath((PS8) fname, FMGR_PATH_ID_VIDEO_EDITOR);
            mdi_openresult = mdi_video_edt_open_clip_file((PS8) fname, &v_info);
            mmi_frm_scrmem_free(fname);                
            if (MDI_RES_VDOPLY_SUCCEED == mdi_openresult)
            {
                if (v_info.total_time_duration)
                {
                    is_valid = TRUE;
                    mmi_vdoedt_init_new_shot(g_vdoedt_cntx.i_act_shot);
                    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
                    p_shot->src_type = VDOEDT_SRC_VIDEO;
                    p_shot->h_video = v_info.handle;
                    p_shot->ms_frm_out = p_shot->ms_cut_out = p_shot->ms_vdo_src_len = v_info.total_time_duration;
                    p_shot->src_w = v_info.width;
                    p_shot->src_h = v_info.height;
                    g_vdoedt_cntx.ms_t_total += p_shot->ms_vdo_src_len;

                    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
                    mmi_vdoedt_update_cachefile();
                }
                else
                {
                    mdi_video_edt_close_clip_file(v_info.handle);
                }
            }
        }
    }

    if (!is_valid)
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_INVALID_VDO);
    }

    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_update_time_base
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_update_time_base(U8 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx >= g_vdoedt_cntx.shot_count)
    {
        if (g_vdoedt_cntx.shot_count)
        {
            idx = g_vdoedt_cntx.shot_count - 1;
        }
        else
        {
            idx = 0;
        }
    }
    for (g_vdoedt_cntx.time_base = 0, i = 0; i < idx; i++)
    {
        g_vdoedt_cntx.time_base += g_vdoedt_cntx.p_shot[i]->ms_cut_out - g_vdoedt_cntx.p_shot[i]->ms_cut_in;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* vdoedt_state_enum old_stat; */
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    U16 scr_id = GetActiveScreenId();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(0);
    if (SCR_ID_VDOEDT_MAIN == scr_id)
    {
        if (MMI_VDOEDT_S_PREVIEW == stat)
        {
            /* play whole video in the edit bar */
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW_PLAY);
            g_vdoedt_cntx.i_act_shot = 0;
        }
        else if (MMI_VDOEDT_S_EDIT == stat && g_vdoedt_cntx.i_act_shot != g_vdoedt_cntx.shot_count)
        {
            /* play current hilight shot only */
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT_PLAY);
        }

        stat = mmi_vdoedt_get_stat();
        if (MMI_VDOEDT_S_SEEK_DONE == stat || MMI_VDOEDT_S_EDIT_PLAY == stat || MMI_VDOEDT_S_PREVIEW_PLAY == stat)
        {
            mmi_vdoedt_update_time_base(g_vdoedt_cntx.i_act_shot);
            if (stat == MMI_VDOEDT_S_EDIT_PLAY)
            {
                g_vdoedt_cntx.time_now = g_vdoedt_cntx.time_base;       /* for audio play */
            }
            mmi_vdoedt_play_shot(g_vdoedt_cntx.i_act_shot);
        }
    }
    else if (SCR_ID_VDOEDT_FRAME_EDIT == scr_id && MMI_VDOEDT_S_EDIT_FRAME == stat)
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_FRM_PLAY);
        mmi_vdoedt_play_shot(g_vdoedt_cntx.i_act_shot);
    }
    else if (SCR_ID_VDOEDT_VIDEO_CUT == scr_id && MMI_VDOEDT_S_EDIT_CUT == stat)
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_CUT_PLAY);
        mmi_vdoedt_play_shot(g_vdoedt_cntx.i_act_shot);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_init_in_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_value      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_init_in_effect(S32 init_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.h_effect == GDI_NULL_HANDLE)
    {
        return;
    }
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    if (init_value <= MMI_VDOEDT_EFFECT_MAX)
    {
        g_vdoedt_cntx.old_value = init_value;
    }
    else
    {
        g_vdoedt_cntx.old_value = 0;
    }

    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
    if (MMI_VDOEDT_EFFECT_IN_FROM_BLACK == p_shot->in_effect)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }
    else if (MMI_VDOEDT_EFFECT_IN_FROM_WHITE == p_shot->in_effect)
    {
        gdi_layer_clear(GDI_COLOR_WHITE);
    }
    else
    {
        g_vdoedt_cntx.old_value = 0;
    }
    gdi_layer_set_opacity(TRUE, g_vdoedt_cntx.old_value);
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_set_out_effect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_val        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_set_out_effect(S32 init_val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.h_effect == GDI_NULL_HANDLE)
    {
        return;
    }
    
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    GDI_LOCK;        
    /* assume that in effect has finished it's using of the layer */
    
    /* video will bring out the layer before we finish, set opacity to 0 first. */
    if (init_val == 0)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
        gdi_layer_set_opacity(TRUE, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(
            g_vdoedt_main_osd_cntx.play_wnd.offset_x,
            g_vdoedt_main_osd_cntx.play_wnd.offset_y,
            g_vdoedt_main_osd_cntx.play_wnd.offset_x + g_vdoedt_main_osd_cntx.play_wnd.width - 1,
            g_vdoedt_main_osd_cntx.play_wnd.offset_y + g_vdoedt_main_osd_cntx.play_wnd.height - 1);
    }
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
    if (MMI_VDOEDT_EFFECT_OUT_2_BLACK == p_shot->out_effect)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
        g_vdoedt_cntx.old_value = init_val;

    }
    else if (MMI_VDOEDT_EFFECT_OUT_2_WHITE == p_shot->out_effect)
    {
        gdi_layer_clear(GDI_COLOR_WHITE);
        g_vdoedt_cntx.old_value = init_val;
    }
    else
    {
        g_vdoedt_cntx.old_value = MMI_VDOEDT_EFFECT_MAX;
    }
    gdi_layer_set_opacity(TRUE, (U8) g_vdoedt_cntx.old_value);
    gdi_layer_pop_and_restore_active();
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_vdo_ply_fin_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_vdo_ply_fin_callback(MDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id_scr = GetActiveScreenId();
    S32 i_shot_remov;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        mdi_video_edt_deactive();
        i_shot_remov = g_vdoedt_cntx.i_act_shot; /* the i_act_shot will be reset when exit main screen */
        mmi_vdoedt_popup(STR_ID_VDOEDT_BAD_VDO_REMOVE_NOTIFY);
        mmi_vdoedt_shot_remove_internal(i_shot_remov);
        if (SCR_ID_VDOEDT_MAIN != id_scr)
        {
            DeleteNHistory(1);  /* exit cut/frame edit screen if video is not valid */
        }        
        return;
    }
    else
    {
        mmi_vdoedt_update_osd_time();
        mmi_vdoedt_shot_finish();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_show_frmtxt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_show_frmtxt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_frmtxt);
    gdi_layer_set_opacity(FALSE, 255);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hide_frmtxt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hide_frmtxt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_vdoedt_cntx.h_frmtxt);
    gdi_layer_set_opacity(TRUE, 0);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_in
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_effect_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, step = (MMI_VDOEDT_EFFECT_MAX - MMI_VDOEDT_EFFECT_MIN) / MMI_VDOEDT_EFFECT_LVL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (U8) g_vdoedt_cntx.old_value;
    if (i)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
        if (i >= step)
        {
            i -= step;
        }
        else
        {
            i = 0;
        }
        gdi_layer_set_opacity(TRUE, i);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        g_vdoedt_cntx.old_value = (S32) i;
        gui_start_timer(MMI_VDOEDT_EFFECT_INTERVAL, mmi_vdoedt_effect_in);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_effect_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, step = (MMI_VDOEDT_EFFECT_MAX - MMI_VDOEDT_EFFECT_MIN) / MMI_VDOEDT_EFFECT_LVL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = (U8) g_vdoedt_cntx.old_value;
    if (MMI_VDOEDT_EFFECT_MAX != i)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
        if (MMI_VDOEDT_EFFECT_MAX - i >= step)
        {
            i += step;
        }
        else
        {
            i = MMI_VDOEDT_EFFECT_MAX;
        }
        gdi_layer_set_opacity(TRUE, i);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

        g_vdoedt_cntx.old_value = (S32) i;
        gui_start_timer(MMI_VDOEDT_EFFECT_INTERVAL, mmi_vdoedt_effect_out);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_play_shot_updater_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ms_offset   [in]    start playing offset from cut_in
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_play_shot_updater_init(U64 ms_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    kal_get_time(&g_vdoedt_cntx.ms_shot_start);
    if (ms_offset)
    {
        g_vdoedt_cntx.ms_shot_start -= (U32) ms_offset/ 4.615;
    }

    g_vdoedt_cntx.frmtxt_shown = (p_shot->choosed_frame || mmi_ucs2strlen(p_shot->p_txt)) ? FALSE : TRUE;

    g_vdoedt_cntx.frmtxt_hidden = g_vdoedt_cntx.frmtxt_shown;

    g_vdoedt_cntx.eff_in = p_shot->in_effect ? FALSE : TRUE;
    g_vdoedt_cntx.eff_out = p_shot->out_effect ? FALSE : TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_play_shot_updater
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_play_shot_updater(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ms_now;
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&ms_now);
    ms_now = (U32) (((double)ms_now - g_vdoedt_cntx.ms_shot_start) * 4.615 + 0.5);

    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    /* show frame */
    if (!g_vdoedt_cntx.frmtxt_shown)
    {
        if (ms_now >= (p_shot->ms_frm_in - p_shot->ms_cut_in) && ms_now <= (p_shot->ms_frm_out - p_shot->ms_cut_in))
        {
            mmi_vdoedt_show_frmtxt();
            g_vdoedt_cntx.frmtxt_shown = TRUE;
        }
    }
    /* hide frame */
    if (!g_vdoedt_cntx.frmtxt_hidden)
    {
        /* frame should gone and this time is not the end of the shot. */
        if (ms_now >= (p_shot->ms_frm_out - p_shot->ms_cut_in) && ms_now < (p_shot->ms_cut_out - p_shot->ms_cut_in))
        {
            mmi_vdoedt_hide_frmtxt();
            g_vdoedt_cntx.frmtxt_hidden = TRUE;
        }
    }
    /* trigger in effect */
    /* trigger out effect */
    if (!g_vdoedt_cntx.eff_out)
    {
        if ((p_shot->ms_cut_out - p_shot->ms_cut_in) <= ms_now + MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL)
        {
            gui_cancel_timer(mmi_vdoedt_effect_in);
            if (g_vdoedt_cntx.full_eff_out)
            {
                mmi_vdoedt_set_out_effect(0);
            }
            gui_start_timer(MMI_VDOEDT_EFFECT_INTERVAL, mmi_vdoedt_effect_out);
            g_vdoedt_cntx.eff_out = TRUE;
        }
    }
    /* check if it's cut out */
    if (ms_now + 100 > (p_shot->ms_cut_out - p_shot->ms_cut_in))
    {
        if (VDOEDT_SRC_VIDEO == p_shot->src_type)
        {
            mdi_video_ply_stop();  /* stop as soon as possible to avoid overplaying current video */
        }
        
        /* handle boundary condition of out-effect*/
        if (p_shot->out_effect)
        {
            gui_cancel_timer(mmi_vdoedt_effect_out);
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
            gdi_layer_set_opacity(TRUE, MMI_VDOEDT_EFFECT_MAX);
            gdi_layer_pop_and_restore_active();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        
        /* both handling is the same for video and images */
        mmi_vdoedt_update_osd_time();
        mmi_vdoedt_shot_finish();
    }
    else
    {
        mmi_vdoedt_update_osd_time();
        /* start next timer */
        gui_start_timer(MMI_VDOEDT_SHOT_UPDATE_INTERVAL, mmi_vdoedt_play_shot_updater);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_get_in_eff_lvl_at_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ms_offset       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_vdoedt_get_in_eff_lvl_at_time(U32 ms_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U8 step = (MMI_VDOEDT_EFFECT_MAX - MMI_VDOEDT_EFFECT_MIN) / MMI_VDOEDT_EFFECT_LVL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ms_offset < MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL)
    {
        ret = MMI_VDOEDT_EFFECT_MAX - step * ms_offset / MMI_VDOEDT_EFFECT_INTERVAL;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_get_out_eff_lvl_at_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ms_offset       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_vdoedt_get_out_eff_lvl_at_time(U32 ms_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    U8 step = (MMI_VDOEDT_EFFECT_MAX - MMI_VDOEDT_EFFECT_MIN) / MMI_VDOEDT_EFFECT_LVL;
    S32 shot_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    shot_len = p_shot->ms_cut_out - p_shot->ms_cut_in;
    if (ms_offset >= shot_len)
    {
        ret = MMI_VDOEDT_EFFECT_MAX;
    }
    else if (ms_offset >= (shot_len) - MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL)
    {
        ret = (ms_offset + MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL - shot_len) / MMI_VDOEDT_EFFECT_INTERVAL * step;
    }

    if (ret > MMI_VDOEDT_EFFECT_MAX)
    {
        ret = MMI_VDOEDT_EFFECT_MAX;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_play_shot
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_play_shot(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[idx];
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    MDI_RESULT ret;
    U32 flag = 0;
    U64 ms_2_seek = 0;
    PS8 fname = g_vdoedt_cntx.fname_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_VDOEDT_MAIN == GetActiveScreenId())
    {
        mmi_vdoedt_draw_stat();
    }

    if (MMI_VDOEDT_S_SEEK_DONE == stat || MMI_VDOEDT_S_PLAY_SEEK_DONE == stat)
    {
        ms_2_seek = g_vdoedt_cntx.time_now;
        mmi_vdoedt_get_shot_idx(&ms_2_seek);
    }

    /* prepare play window */
    if (VDOEDT_SRC_VIDEO == p_shot->src_type)
    {
        ret = mdi_video_edt_active(p_shot->h_video);
        if (ret != MDI_RES_VDOPLY_SUCCEED)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);      /* leave play state */
            mmi_vdoedt_popup(STR_ID_VDOEDT_FILE_NOT_FOUND);
            return;
        }
        ret = mdi_video_ply_seek(p_shot->ms_cut_in + ms_2_seek);
        if (ret != MDI_RES_VDOPLY_SUCCEED)
        {
            mdi_video_edt_deactive();
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);

            mmi_vdoedt_seek_result_handler(ret);
            return;
        }

    }
    else if (p_shot->src_type >= VDOEDT_SRC_IMG_FILE && p_shot->src_type < VDOEDT_SRC_COLOR)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
        mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
        mmi_ucs2cat(fname, p_shot->ustr_fname);
        if (GDI_SUCCEED != gdi_image_draw_file(0, 0, fname))
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
            /* and print error string */
        }
        gdi_layer_pop_and_restore_active();
    }
    else if (p_shot->src_type == VDOEDT_SRC_COLOR)
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
        gdi_draw_solid_rect(
            0,
            0,
            g_vdoedt_main_osd_cntx.play_wnd.width - 1,
            g_vdoedt_main_osd_cntx.play_wnd.height - 1,
            MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        ASSERT(VDOEDT_SRC_RESERVED < p_shot->src_type && p_shot->src_type <= VDOEDT_SRC_COLOR);
    }

    if (MMI_VDOEDT_S_SEEK_DONE == stat || MMI_VDOEDT_S_PLAY_SEEK_DONE == stat)
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW_PLAY);
        mmi_vdoedt_update_time_base(idx);
    }

    /* update edit bar (if needed) */
    if (MMI_VDOEDT_S_PREVIEW_PLAY == mmi_vdoedt_get_stat())
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_osd);
        mmi_vdoedt_draw_shot_hilight(idx);
        gdi_layer_pop_and_restore_active();
    }

    /* init in effect */
    if (GDI_NULL_HANDLE != g_vdoedt_cntx.h_effect)
    {
        /* hide effect layer becuz may have out effect only */
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
        gdi_layer_set_opacity(TRUE, 0);
        gdi_layer_pop_and_restore_active();

        if (MMI_VDOEDT_EFFECT_IN_NONE != p_shot->in_effect)
        {
            mmi_vdoedt_init_in_effect(mmi_vdoedt_get_in_eff_lvl_at_time(ms_2_seek));
        }
        if (MMI_VDOEDT_EFFECT_OUT_NONE != p_shot->out_effect)
        {
            g_vdoedt_cntx.full_eff_out = TRUE;
            if (ms_2_seek > (p_shot->ms_cut_out - p_shot->ms_cut_in - 600))
            {
                mmi_vdoedt_set_out_effect(mmi_vdoedt_get_out_eff_lvl_at_time(ms_2_seek));
                g_vdoedt_cntx.full_eff_out = FALSE;
            }
        }
    }
    /* frame/text  */
    if (p_shot->choosed_frame || mmi_ucs2strlen(p_shot->p_txt))
    {
        if (p_shot->ms_frm_in < p_shot->ms_cut_in)
        {
            p_shot->ms_frm_in = p_shot->ms_cut_in;
        }
        if (p_shot->ms_frm_out > p_shot->ms_cut_out)
        {
            p_shot->ms_frm_out = p_shot->ms_cut_out;
        }
        mmi_vdoedt_draw_frametxt(p_shot->ms_frm_in);        
    }
    else
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_frmtxt);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    if (p_shot->ms_cut_in + ms_2_seek < p_shot->ms_frm_in || p_shot->ms_cut_in + ms_2_seek > p_shot->ms_frm_out)
    {
        mmi_vdoedt_hide_frmtxt();
    }

    gdi_layer_blt_previous(
        g_vdoedt_main_osd_cntx.play_wnd.offset_x,
        g_vdoedt_main_osd_cntx.play_wnd.offset_y,
        g_vdoedt_main_osd_cntx.play_wnd.offset_x + g_vdoedt_main_osd_cntx.play_wnd.width,
        g_vdoedt_main_osd_cntx.play_wnd.offset_y + g_vdoedt_main_osd_cntx.play_wnd.height);

    /* start playing */
    if (VDOEDT_SRC_VIDEO == p_shot->src_type && 
        (ms_2_seek + p_shot->ms_cut_in < p_shot->ms_cut_out))
    {
        /* only play the video when seek point is not at cut out. */
        flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;

        if (g_vdoedt_cntx.h_effect != GDI_NULL_HANDLE)
        {
            flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
        if (g_vdoedt_cntx.h_keyframe != GDI_NULL_HANDLE)
        {
            flag |= GDI_LAYER_ENABLE_LAYER_4;
        }
        mdi_audio_set_volume(VOL_TYPE_MEDIA, g_vdoedt_cntx.a_volume);
        ret = mdi_video_ply_play(
                g_vdoedt_cntx.h_play,
                flag,
                GDI_LAYER_ENABLE_LAYER_1,
                1,                                  /* repeat count */
                TRUE,                               /* update to LCM or not */
                !g_vdoedt_cntx.audio_selected,      /* play audio       */
                MDI_DEVICE_SPEAKER2,                /* speaker & earphone */
                GDI_LAYER_ROTATE_0,
                100,                                /* 1x play speed */
                mmi_vdoedt_vdo_ply_fin_callback);   /* hook callback */
        if (ret != MDI_RES_VDOPLY_SUCCEED)
        {
            mdi_video_edt_deactive();
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
            mmi_vdoedt_popup(STR_ID_VDOEDT_FILE_NOT_FOUND);
            return;
        }
    }
    else if (VDOEDT_SRC_VIDEO == p_shot->src_type)
    {
        /* seek over the end of current shot. do not play. */
        mmi_vdoedt_vdo_ply_fin_callback(MDI_RES_VDOPLY_SUCCEED);
        return;
    }
    else
    {
        /* images                                     */
        /* set base time for osd update for the image */
        kal_get_time(&g_vdoedt_cntx.time_start);
        if (ms_2_seek)
        {
            g_vdoedt_cntx.time_start -= (U32) ms_2_seek / 4.615;
        }
    }

    mmi_vdoedt_play_shot_updater_init(ms_2_seek);
    gui_start_timer(MMI_VDOEDT_SHOT_UPDATE_INTERVAL, mmi_vdoedt_play_shot_updater);

    /* start in effect timer */
    if (MMI_VDOEDT_EFFECT_IN_NONE != p_shot->in_effect && mmi_vdoedt_get_in_eff_lvl_at_time(ms_2_seek))
    {
        gui_start_timer(MMI_VDOEDT_EFFECT_INTERVAL, mmi_vdoedt_effect_in);
    }

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_shot_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_shot_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /* vdoedt_state_enum stat_old = mmi_vdoedt_get_old_stat(); */
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_hide_frmtxt);
    gui_cancel_timer(mmi_vdoedt_show_frmtxt);

    if (MMI_VDOEDT_S_EDIT_PLAY == stat)
    {
        /* finished, seek to first frame if need.. */
        mmi_vdoedt_play_stop();
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
    }
    else if (MMI_VDOEDT_S_PREVIEW_PLAY == stat)
    {
        if (g_vdoedt_cntx.i_act_shot + 1 < g_vdoedt_cntx.shot_count)
        {
            if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
            {
                mdi_video_ply_stop();
                mdi_video_edt_deactive();
            }
            /* play next shot */
            g_vdoedt_cntx.i_act_shot++;
            mmi_vdoedt_update_time_base(g_vdoedt_cntx.i_act_shot);
            mmi_vdoedt_play_shot(g_vdoedt_cntx.i_act_shot);
        }
        else
        {
            /* finished */
            mmi_vdoedt_play_stop();
            g_vdoedt_cntx.i_act_shot = 0;
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PREVIEW);
            g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_SKEY;
            mmi_vdoedt_redraw();
        }
    }
    else if (MMI_VDOEDT_S_CUT_PLAY == stat)
    {
        mmi_vdoedt_play_stop();
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
    }
    else if (MMI_VDOEDT_S_FRM_PLAY == stat)
    {
        mmi_vdoedt_play_stop();
        g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_SKEY;
        mmi_vdoedt_redraw();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_update_osd_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_update_osd_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 ms_offset = 0;
    vdoedt_shot_struct *p_shot = NULL;
    U32 time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    if (VDOEDT_SRC_VIDEO == p_shot->src_type)
    {
        mdi_video_ply_get_cur_play_time(&ms_offset);
        if (ms_offset > p_shot->ms_cut_out - 400)
        {
            /* because we can't stop video very precisely, realign time for extera boundary condition */
            ms_offset = p_shot->ms_cut_out;
        }
        if (ms_offset > p_shot->ms_cut_in)
        {
            ms_offset -= p_shot->ms_cut_in;
        }
    }
    else
    {
        if (g_vdoedt_cntx.time_start)
        {
            /* img time */
            kal_get_time(&time);
            ms_offset = (U32) (((double)time - g_vdoedt_cntx.time_start) * 4.615 + 0.5);
        }
    }

    g_vdoedt_cntx.time_now = g_vdoedt_cntx.time_base + ms_offset;

    g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_PBAR;
    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_get_shot_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ms_start        [IN/OUT]        the time to calculate correct index.
 * RETURNS
 *  i               [OUT]           shot index
 *  ms_start        [OUT]           offset from cut in (in ms)
 *****************************************************************************/
S32 mmi_vdoedt_get_shot_idx(U64 *ms_start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U64 ms_temp;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < g_vdoedt_cntx.shot_count; i++)
    {
        p_shot = g_vdoedt_cntx.p_shot[i];
        ms_temp = p_shot->ms_cut_out - p_shot->ms_cut_in;

        if (*ms_start >= ms_temp)
        {
            *ms_start -= ms_temp;
        }
        else
        {
            break;
        }
    }
    /* seek over the end, set play postion at the end. */
    if (i == g_vdoedt_cntx.shot_count)
    {
        i--;
        *ms_start = p_shot->ms_cut_out - p_shot->ms_cut_in;
    }

    /* ms_start will be the time offset from user cut_in point from video */
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_text_select_text_color_hilight_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_text_select_text_color_hilight_callback(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->i_txt_color = index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_text_property_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_text_property_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.flg_cut_r4w |= MMI_VDOEDT_R4W_FRAME;

    /* DeleteUptoScrID(SCR_ID_VDOEDT_FRAME_EDIT); */
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_text_prop_select_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  i       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_text_prop_select_highlight_hdlr(S32 i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdoedt_text_property_done);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_text_property_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_text_property_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U8 *input_buffer;
    U16 item_offset;
    U16 input_buffer_size;
    UI_string_type *pp_str;
    vdoedt_shot_struct *p_shot;

    MMI_ID_TYPE item_icons[] = 
    {
        IMG_GLOBAL_L1,
        0,
        IMG_GLOBAL_L2,
        0,
        IMG_GLOBAL_L3,
        0,
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->p_txt) == 0)
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_EMPTY_STRING);
        DeleteScreenIfPresent(SCR_ID_VDOEDT_FRAME_TEXT_EDITOR_OPTION);
        return;
    }
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    EntryNewScreen(SCR_ID_VDOEDT_FRAME_TEXT_PROPERTY, 0, mmi_vdoedt_entry_text_property_screen, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_FRAME_TEXT_PROPERTY);
    input_buffer = GetCurrNInputBuffer(SCR_ID_VDOEDT_FRAME_TEXT_PROPERTY, &input_buffer_size);

    pp_str = g_vdoedt_cntx.ps_txt_size;
    pp_str[MMI_VDOEDT_TXT_SIZE_S] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_TXT_S));
    pp_str[MMI_VDOEDT_TXT_SIZE_M] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_TXT_M));
    pp_str[MMI_VDOEDT_TXT_SIZE_L] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_TXT_L));
    pp_str = g_vdoedt_cntx.ps_txt_align;
    pp_str[MMI_VDOEDT_TXT_ALIGN_TOP] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_TXT_ALIGN_TOP));
    pp_str[MMI_VDOEDT_TXT_ALIGN_BOTTOM] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_TXT_ALIGN_BTM));
    pp_str[MMI_VDOEDT_TXT_ALIGN_CENTER] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_TXT_ALIGN_CEN));

    pp_str = g_vdoedt_cntx.ps_txt_color;
    pp_str[0] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_BLACK));
    pp_str[1] = (UI_string_type) GetString((U16) (STR_ID_VDOEDT_WHITE));

    /* clear inline item */
    memset((void*)wgui_inline_items, 0, sizeof(InlineItem) * 3 * 2);
    item_offset = 0;

    /* start of Category 57 */
    InitializeCategory57Screen();

    /* text color */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_VDOEDT_TXT_COLOR)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        2,
        (U8 **) g_vdoedt_cntx.ps_txt_color,
        &p_shot->i_txt_color);

    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[item_offset - 1],
        mmi_vdoedt_text_inline_select_highlight_hdlr);
    /* font size */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_VDOEDT_TXT_SIZE)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        MMI_VDOEDT_TXT_SIZE_COUNT,
        (U8 **) g_vdoedt_cntx.ps_txt_size,
        &p_shot->size_txt);

    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[item_offset - 1],
        mmi_vdoedt_text_inline_select_highlight_hdlr);

    /* ailgn */
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_VDOEDT_TXT_POSITION)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);

    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        MMI_VDOEDT_TXT_ALIGN_COUNT,
        (U8 **) g_vdoedt_cntx.ps_txt_align,
        &p_shot->text_align);

    RegisterInlineSelectHighlightHandler(
        &wgui_inline_items[item_offset - 1],
        mmi_vdoedt_text_inline_select_highlight_hdlr);

    if (input_buffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, 3 * 2, input_buffer);
    }

    RegisterHighlightHandler(mmi_vdoedt_text_prop_select_highlight_hdlr);

    /* append a info box on top of cateogory 57 screen */
    /* Category57AppendTopInfoBox(2, mmi_phoart_text_select_draw_info_callback, NULL, TRUE); */

    /* show category */
    ShowCategory57Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
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
    SetCategory57LeftSoftkeyFunction(mmi_vdoedt_text_property_done);
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    DisableCategory57ScreenDone();

    /* g_phoart_cntx.is_text_select_ready = TRUE; */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_img_do_insert_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_img_do_insert_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = g_vdoedt_cntx.i_act_shot;
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ToDo: insert the video into edit bar, extract keyframe. */

    if (g_vdoedt_cntx.shot_count < MMI_VDOEDT_MAX_CLIP_NUM)
    {
        mmi_vdoedt_init_new_shot(i);
        p_shot = g_vdoedt_cntx.p_shot[i];
        p_shot->s_img_dur = MMI_VDOEDT_IMG_DUR_DEFAULT;
        p_shot->ms_frm_in = p_shot->ms_cut_in = 0;
        p_shot->ms_frm_out = p_shot->ms_cut_out = p_shot->s_img_dur * 1000;
        p_shot->src_type = VDOEDT_SRC_IMG_FILE;
        //        mmi_fmgr_util_load_filepath(p_shot->img_fname, FMGR_PATH_ID_VIDEO_EDITOR);
        //        gdi_image_get_dimension_file(p_shot->img_fname, &p_shot->src_w, &p_shot->src_h);
        g_vdoedt_cntx.ms_t_total += p_shot->s_img_dur * 1000;
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);

        mmi_vdoedt_update_cachefile();
    }

    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
    GoBackHistory();
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 * #seek related                                                         
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_frmtxt_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx             [IN]        
 *  ms_t_offset     [IN]     offset from cut-in
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_frmtxt_set(S32 idx, U32 ms_t_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = g_vdoedt_cntx.p_shot[idx];
    if (g_vdoedt_cntx.h_frmtxt != GDI_NULL_HANDLE)
    {
        mmi_vdoedt_draw_frametxt(p_shot->ms_cut_in + ms_t_offset);  /* offset from start of the inserted video */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_effect_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx             [IN]        
 *  ms_t_offset     [IN]        offset from cut-in
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_effect_set(S32 idx, U32 ms_t_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = g_vdoedt_cntx.p_shot[idx];

    if (GDI_NULL_HANDLE != g_vdoedt_cntx.h_effect && p_shot != NULL)
    {
        if (p_shot->in_effect && ms_t_offset <= MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL)
        {
            mmi_vdoedt_init_in_effect(mmi_vdoedt_get_in_eff_lvl_at_time(ms_t_offset));
        }
        else if (p_shot->out_effect && ((p_shot->ms_cut_out - p_shot->ms_cut_in) <= ms_t_offset + MMI_VDOEDT_EFFECT_INTERVAL * MMI_VDOEDT_EFFECT_LVL))
        {
            mmi_vdoedt_set_out_effect(mmi_vdoedt_get_out_eff_lvl_at_time(ms_t_offset));
        }
        else
        {
            gdi_layer_push_and_set_active(g_vdoedt_cntx.h_effect);
            gdi_layer_set_opacity(TRUE, 0);
            gdi_layer_pop_and_restore_active();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_update_seek_frame
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_update_seek_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U64 ms_temp = g_vdoedt_cntx.time_now;
    vdoedt_shot_struct *p_shot;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    S8 fname[52];
    mdi_result mdi_ret = MDI_RES_VDOPLY_SUCCEED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get the shot should be played */
    i = mmi_vdoedt_get_shot_idx(&ms_temp);
    g_vdoedt_cntx.i_act_shot = i;
    p_shot = g_vdoedt_cntx.p_shot[i];

    /* draw frame/text */
    mmi_vdoedt_frmtxt_set(i, ms_temp);
    /* set effect */
    mmi_vdoedt_effect_set(i, ms_temp);

    /* seek to desired frame */
    if (p_shot->src_type == VDOEDT_SRC_VIDEO)
    {
        mdi_video_edt_active(p_shot->h_video);
        if (MMI_VDOEDT_S_SEEK == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK_UPDATING);
            mdi_ret = mdi_video_ply_non_block_seek_and_get_frame(ms_temp + p_shot->ms_cut_in, g_vdoedt_cntx.h_play, mmi_vdoedt_seek_result_callback);
        }
        else if (MMI_VDOEDT_S_PLAY_SEEK == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK_UPDATING);
            mdi_ret = mdi_video_ply_non_block_seek(ms_temp + p_shot->ms_cut_in, mmi_vdoedt_seek_result_callback);            
        }
        else
        {
            ASSERT(stat == MMI_VDOEDT_S_SEEK || stat == MMI_VDOEDT_S_PLAY_SEEK);
        }
        /* handle seek result. */
        if (mdi_ret < MDI_RES_VDOPLY_SUCCEED)
        {
            mdi_video_edt_deactive();
            mmi_vdoedt_seek_result_handler(mdi_ret);
        }
    }
    else
    {
        gdi_layer_push_and_set_active(g_vdoedt_cntx.h_play);
        if (p_shot->src_type == VDOEDT_SRC_COLOR)
        {
            gdi_draw_solid_rect(
                0,
                0,
                g_vdoedt_main_osd_cntx.play_wnd.width - 1,
                g_vdoedt_main_osd_cntx.play_wnd.height - 1,
                MMI_VDOEDT_GET_GDI_COLOR(p_shot->c_shot));
        }
        else
        {
            mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
            mmi_ucs2cat(fname, p_shot->ustr_fname);
            gdi_image_draw_file(0, 0, fname);
        }
        gdi_layer_pop_and_restore_active();
        /* exit seek state */
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        if (MMI_VDOEDT_S_SEEK == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK_DONE);
        }
        else
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK_DONE);
            mmi_vdoedt_play_shot(i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_seek_result_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mdi_res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_seek_result_callback(MDI_RESULT mdi_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 ms_time;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mdi_res >= MDI_RES_VDOPLY_SUCCEED)
    {       
        if (MDI_RES_VDOPLY_SEEK_PARTIAL_DONE == mdi_res)
        {
            mdi_video_ply_get_cur_play_time(&ms_time);
            ms_time -= g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->ms_cut_in;
            /* should update progress bar here */
        }
        mdi_video_edt_deactive();
        if (MMI_VDOEDT_S_SEEK_UPDATING == stat)
        {
            gdi_layer_blt_previous(
                g_vdoedt_main_osd_cntx.play_wnd.offset_x,
                g_vdoedt_main_osd_cntx.play_wnd.offset_y,
                g_vdoedt_main_osd_cntx.play_wnd.offset_x + g_vdoedt_main_osd_cntx.play_wnd.width,
                g_vdoedt_main_osd_cntx.play_wnd.offset_y + g_vdoedt_main_osd_cntx.play_wnd.height);
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK_DONE);
        }
        else if (MMI_VDOEDT_S_PLAY_SEEK_UPDATING == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK_DONE);
            /* auto continue playing. */
            mmi_vdoedt_play_shot(g_vdoedt_cntx.i_act_shot);
        }
    }
    else if (MDI_RES_VDOPLY_ERR_SEEK_FAILED == mdi_res)
    {
        mdi_video_edt_deactive();        
        mmi_vdoedt_seek_result_handler(mdi_res);
        return;
    }
    else
    {
        mdi_video_edt_deactive();        
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        mmi_vdoedt_popup(STR_ID_VDOEDT_INVALID_VDO);
        return;
    }
    /* exit seek state */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_seek_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inc     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_seek_internal(BOOL inc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 step = 0;
    U64 ms_t_total = g_vdoedt_cntx.ms_t_total;
    U32 ms_t_now = g_vdoedt_cntx.time_now;
    U32 x, w = g_vdoedt_main_osd_cntx.progress.empty.width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.movecount++;
    if (g_vdoedt_cntx.movecount <= 2)
    {
        step = 1;
    }
    else if (g_vdoedt_cntx.movecount <= 5)
    {
        step = 5;
    }
    else
    {
        step = 10;
    }

    /* get position from current time, then inc step, then update time */
    x = (U32) (ms_t_now * w / ms_t_total);

    if (inc)
    {
        x += step + 2;          /* fine tune */
        if (x > w)
        {
            x = w;
        }
    }
    else
    {
        if (x > step)
        {
            x -= step;
        }
        else
        {
            x = 0;
        }
    }

    /* adjust time now. */
    ms_t_now = (U64) (x * ms_t_total / w);

    g_vdoedt_cntx.time_now = ms_t_now;

    g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_TIME;
    mmi_vdoedt_redraw();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_key_ff_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_key_ff_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_key_cntx.ffk.pressed)
    {
        return;
    }
    
    switch (stat)
    {
        case MMI_VDOEDT_S_SEEK_DONE:
        case MMI_VDOEDT_S_PREVIEW:
            if (MMI_VDOEDT_S_SEEK != stat)
            {
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK);   /* don't re-enter same state */
                stat = MMI_VDOEDT_S_SEEK;
            }
        case MMI_VDOEDT_S_PLAY:
        case MMI_VDOEDT_S_PREVIEW_PLAY:
            gui_cancel_timer(mmi_vdoedt_update_seek_frame);
            /* pause playing */
            if (MMI_VDOEDT_S_SEEK != stat)
            {
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK);
                mmi_vdoedt_play_pause();
            }

            g_vdoedt_cntx.movecount = 0;
            g_vdoedt_key_cntx.ffk.pressed = TRUE;
            mmi_vdoedt_seek_ff();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_key_seek_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_key_seek_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_key_cntx.ffk.pressed || g_vdoedt_key_cntx.rwk.pressed)
    {
        if (g_vdoedt_key_cntx.ffk.pressed)
        {
            g_vdoedt_key_cntx.ffk.pressed = FALSE;
            gui_cancel_timer(mmi_vdoedt_seek_ff);
        }
        else
        {
            g_vdoedt_key_cntx.rwk.pressed = FALSE;
            gui_cancel_timer(mmi_vdoedt_seek_rw);
        }
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_PBAR | MMI_VDOEDT_R4W_EBAR;
        mmi_vdoedt_redraw();

        gui_start_timer(300, mmi_vdoedt_update_seek_frame);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_seek_ff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_seek_ff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_seek_internal(TRUE);
    gui_start_timer(100, mmi_vdoedt_seek_ff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_key_rw_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_key_rw_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_key_cntx.rwk.pressed)
    {
        return;
    }
    
    switch (stat)
    {
        case MMI_VDOEDT_S_SEEK_DONE:
        case MMI_VDOEDT_S_PREVIEW:
            if (MMI_VDOEDT_S_SEEK != stat)
            {
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK);   /* don't re-enter same state */
                stat = MMI_VDOEDT_S_SEEK;
            }
        case MMI_VDOEDT_S_PLAY:
        case MMI_VDOEDT_S_PREVIEW_PLAY:
            /* pause playing */
            gui_cancel_timer(mmi_vdoedt_update_seek_frame);
            if (MMI_VDOEDT_S_SEEK != stat)
            {
                mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK);
                mmi_vdoedt_play_pause();
            }
            g_vdoedt_cntx.movecount = 0;
            g_vdoedt_key_cntx.rwk.pressed = TRUE;
            mmi_vdoedt_seek_rw();
            break;

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_seek_rw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_seek_rw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_seek_internal(FALSE);
    gui_start_timer(100, mmi_vdoedt_seek_rw);
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_seek_by_touch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_seek_by_touch(S32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 w = g_vdoedt_main_osd_cntx.progress.empty.width;
    S32 offset = g_vdoedt_main_osd_cntx.progress.empty.offset_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x - offset > w)
    {
        x = w + offset;
    }
    else if (x < offset)
    {
        x = offset;
    }

    g_vdoedt_cntx.time_now = (x - offset) * g_vdoedt_cntx.ms_t_total / w;

}
#endif /* __MMI_TOUCH_SCREEN__ */ 

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 * #encode related                                                         
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE f_delete;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearKeyEvents();
    gui_cancel_timer(mmi_vdoedt_enc_append_done);
    gui_cancel_timer(mmi_vdoedt_enc_next_slice);
    gui_cancel_timer(mmi_vdoedt_enc_append_cyclic);

    g_vdoedt_cntx.i_act_shot = 0;
    
    mmi_vdoedt_popup(STR_ID_VDOEDT_ENC_FAILED);
    
    f_delete = FS_Open((kal_uint16*) g_vdoedt_cntx.fname_buff, FS_READ_ONLY);
    if (f_delete > FS_NO_ERROR)
    {
        FS_Close(f_delete);
        f_delete = FS_Delete((PU16)g_vdoedt_cntx.fname_buff);
    }
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
    DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_entry_encode_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_entry_encode_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer;
    S8 a_str[9];
    S8 u_est_time_str[18];  /* estimated time string */
    mmi_vdoedt_time_struct hms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOEDT_ENCODE, mmi_vdoedt_exit_encode_screen, mmi_vdoedt_entry_encode_screen, NULL);

    mmi_vdoedt_util_suspend_bg_audio();
    
    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOEDT_ENCODE);

    TurnOnBacklight(0);

    if (gui_buffer)
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        GoBackToHistory(SCR_ID_VDOEDT_MAIN);
        return;
    }

    /* create layer */
    mmi_vdoedt_util_create_layers(MMI_VDOEDT_LAYER_EFFECT |
                                  MMI_VDOEDT_LAYER_FRM | MMI_VDOEDT_LAYER_OSD | MMI_VDOEDT_LAYER_PLAY);

    if (mmi_vdoedt_enc_init(g_vdoedt_cntx.fname_buff))
    {
        gui_start_timer(100, mmi_vdoedt_enc_next_slice);
    }
    else
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_ENC_FAILED);
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);        
        DeleteNHistory(1);
        return;
    }

    mmi_vdoedt_ms_2_hms(g_vdoedt_cntx.ms_t_total, &hms);
    sprintf(a_str, "%02u:%02u:%02u", hms.hh, hms.mm, hms.ss);
    mmi_asc_to_ucs2(u_est_time_str, a_str);

    ShowCategory402Screen(
        (PU8) GetString(STR_GLOBAL_SAVE),           /* title */
        GetRootTitleIcon(MENU_ID_VDOEDT_APP),
        0,                                          /* lsk */
        0,                                          /* lsk icon */
        STR_GLOBAL_ABORT,                           /* rsk */
        IMG_GLOBAL_BACK,                            /* rsk icon */
        (PU8) GetString(STR_ID_VDOEDT_ENCODING),    /* string on screen */
        0,                                          /* percentage */
        (PU8) u_est_time_str);                      /* progress string */

    SetRightSoftkeyFunction(mmi_vdoedt_enc_rsk_hdlr, KEY_EVENT_UP);

   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
    mmi_frm_block_general_interrupt_event(MMI_FRM_INT_BATTERY | MMI_FRM_INT_SMS | MMI_FRM_INT_FMGR_CARD);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_exit_encode_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_exit_encode_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vdoedt_enc_next_slice);
    gui_cancel_timer(mmi_vdoedt_enc_append_cyclic);
    gui_cancel_timer(mmi_vdoedt_enc_append_done);

    g_vdoedt_cntx.time_now = 0;
    g_vdoedt_cntx.i_act_shot = 0;
    
    mdi_video_edt_close_silence_clip_id();
    
    
    mmi_vdoedt_util_free_layers();
    TurnOffBacklight();
    mdi_video_edt_encode_close();
    
    mmi_vdoedt_util_resume_bg_audio();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_data      [IN]        
 *  num         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdoedt_sort(PU32 p_data, U8 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* use bubble sort first */
    U8 i, j;
    U32 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num - 1; i++)
    {
        tmp = 0;
        for (j = 0; j < num - 1; j++)
        {
            if (p_data[j] > p_data[j + 1])
            {
                tmp = p_data[j];
                p_data[j] = p_data[j + 1];
                p_data[j + 1] = tmp;
            }
        }
        if (!tmp)
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_update_timeline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_update_timeline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;
    U8 u = 0;
    U64 ms_eff_dur = MMI_VDOEDT_EFFECT_LVL * MMI_VDOEDT_EFFECT_INTERVAL; 
    U64 ms_temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];

    for (u = 0; u < 4; u++)
    {
        g_vdoedt_cntx.ms_timeline[u] = 0;
    }

    u = 0;
    if (MMI_VDOEDT_EFFECT_IN_NONE != p_shot->in_effect)
    {
        g_vdoedt_cntx.ms_timeline[u++] = p_shot->ms_cut_in + ms_eff_dur;
    }

    if (p_shot->choosed_frame || mmi_ucs2strlen(p_shot->p_txt))
    {
        if (MMI_VDOEDT_EFFECT_IN_NONE != p_shot->in_effect &&
            p_shot->ms_frm_in < p_shot->ms_cut_in + ms_eff_dur)
        {
            g_vdoedt_cntx.ms_timeline[u++] = 
                p_shot->ms_cut_in + MMI_VDOEDT_EFFECT_INTERVAL * ((p_shot->ms_frm_in/MMI_VDOEDT_EFFECT_INTERVAL) + (p_shot->ms_frm_in%MMI_VDOEDT_EFFECT_INTERVAL)?1:0);
        }
        else
        {
            g_vdoedt_cntx.ms_timeline[u++] = p_shot->ms_frm_in;
        }

        if (MMI_VDOEDT_EFFECT_OUT_NONE != p_shot->out_effect &&
            p_shot->ms_frm_out > p_shot->ms_cut_in - ms_eff_dur)
        {
            ms_temp = p_shot->ms_frm_out - (p_shot->ms_cut_out + ms_eff_dur);
            g_vdoedt_cntx.ms_timeline[u++] = 
                (p_shot->ms_cut_out - ms_eff_dur) + MMI_VDOEDT_EFFECT_INTERVAL * ((ms_temp/MMI_VDOEDT_EFFECT_INTERVAL) + (ms_temp%MMI_VDOEDT_EFFECT_INTERVAL)?1:0);
        }
        else
        {
            if (p_shot->ms_cut_out != p_shot->ms_frm_out)
            {
                g_vdoedt_cntx.ms_timeline[u++] = p_shot->ms_frm_out + 1;
            }
            else
            {
                g_vdoedt_cntx.ms_timeline[u++] = p_shot->ms_frm_out;
            }
        }
    }

    if (MMI_VDOEDT_EFFECT_OUT_NONE != p_shot->out_effect)
    {
        g_vdoedt_cntx.ms_timeline[u++] = p_shot->ms_cut_out - ms_eff_dur;
    }

    mmi_vdoedt_sort(g_vdoedt_cntx.ms_timeline, 4);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_fname     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_vdoedt_enc_init(PS8 p_fname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_context_struct *p_cntx = &g_vdoedt_cntx;
    MDI_RESULT m_ret;
    BOOL res = FALSE;
    U64 aud_dur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_fname != NULL && MMI_VDOEDT_S_SAVING == mmi_vdoedt_get_stat())
    {
        /*----------------------------------------------------------------*/
        /* init layers and time                                           */
        /*----------------------------------------------------------------*/
        p_cntx->i_act_shot = p_cntx->time_now = 0;
        mmi_vdoedt_update_time_base(0);

        ASSERT(GDI_NULL_HANDLE != p_cntx->h_effect && GDI_NULL_HANDLE != p_cntx->h_frmtxt &&
               GDI_NULL_HANDLE != p_cntx->h_play);

        gdi_layer_push_and_set_active(p_cntx->h_effect);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();

        gdi_layer_push_and_set_active(p_cntx->h_frmtxt);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
        mmi_vdoedt_enc_update_timeline();

        m_ret = mdi_video_edt_encode_open(MMI_VDOEDT_VDO_WIDTH, MMI_VDOEDT_VDO_HEIGHT, p_fname);
        if (MDI_RES_VDOREC_SUCCEED == m_ret)
        {
            res = TRUE;
        }
        else
        {
            res = FALSE;
            return res;
        }

        m_ret = mdi_video_edt_open_silence_clip_id(AUD_ID_VDOEDT_SILENT, &aud_dur);
        if (MDI_RES_VDOREC_SUCCEED != m_ret)
        {
            res = FALSE;    /* temperary */
        }
        /* open custom audio file */
    }

    return res;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_res_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_res_callback(MDI_RESULT res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdoedt_cntx.i_act_shot = 0;
    g_vdoedt_cntx.time_now = 0;
    if (MDI_RES_VDOREC_SUCCEED == res)
    {
        mmi_vdoedt_popup(STR_GLOBAL_DONE);
    }
    else
    {
        mmi_vdoedt_popup(STR_ID_VDOEDT_ENC_FAILED);
    }
    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);    
    DeleteScreenIfPresent(SCR_ID_VDOEDT_ENCODE);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_append_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_append_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    mmi_vdoedt_enc_res_callback(MDI_RES_VDOREC_SUCCEED);
#else /* MTK_TARGET */
    /* Aborting is not allowed. */
    ClearKeyHandler(KEY_RSK, KEY_EVENT_UP);
    DisableRightSoftkey(0, 0);
    mdi_video_edt_encode_merge((PS8) g_vdoedt_cntx.fname_buff, mmi_vdoedt_enc_res_callback);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_append_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_append_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_shot_struct *p_shot;
    vdoedt_context_struct *p_cntx = &g_vdoedt_cntx;
    BOOL mor_segment = FALSE;
    U32 ms_end = 0;    
    U32 ms_bgm_start = 0;
    MDI_RESULT res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = p_cntx->p_shot[p_cntx->i_act_shot];
    /* mdi_video_edt_encode_append_XXX is blocking function, cut the slice if its too long. */   
    if (p_cntx->ms_slice_end - p_cntx->ms_slice_start > MMI_VDOEDT_MAX_SLICE_LEN)
    {
        ms_end = p_cntx->ms_slice_start + MMI_VDOEDT_MAX_SLICE_LEN;
        mor_segment = TRUE;
    }
    else
    {
        ms_end = p_cntx->ms_slice_end;
    }

    if (VDOEDT_SRC_VIDEO == p_shot->src_type)
    {
        res = mdi_video_edt_encode_append_video(
            p_shot->h_video,
            p_cntx->h_frmtxt,
            p_cntx->h_effect,
            p_cntx->ms_slice_start,
            ms_end,
            FALSE,
            ms_bgm_start,
            ms_bgm_start + ms_end);
    }
    else
    {
        res = mdi_video_edt_encode_append_image(
            p_cntx->h_play,
            p_cntx->h_frmtxt,
            p_cntx->h_effect,
            (ms_end - p_cntx->ms_slice_start),
            FALSE,
            ms_bgm_start,
            ms_bgm_start + ms_end);
    }

    if (MDI_RES_VDOPLY_SUCCEED == res)
    {
        g_vdoedt_cntx.time_now = g_vdoedt_cntx.time_base + (ms_end - p_shot->ms_cut_in);
        mmi_vdoedt_enc_state_update();
        if (mor_segment)
        {
            p_cntx->ms_slice_start = ms_end;
            gui_start_timer(MMI_VDOEDT_ENCODE_DELAY, mmi_vdoedt_enc_append_cyclic);
        }
        else
        {
            mmi_vdoedt_enc_next_slice();
        }
    }
    else
    {
        /* encode failed */
        if (ms_end - p_cntx->ms_slice_start < MMI_VDOEDT_MIN_APPEND_LEN)
        {
            /* failed becuz we append too short, drop the segment and continue to encode next slice. */
            g_vdoedt_cntx.time_now = g_vdoedt_cntx.time_base + (ms_end - p_shot->ms_cut_in);
            mmi_vdoedt_enc_next_slice();
        }
        else
        {
            if (MDI_RES_VDOREC_ERR_DISK_FULL == res)
            {
                mmi_vdoedt_popup(FMGR_FS_DISK_FULL_TEXT);
            }
            else
            {
                mmi_vdoedt_popup(STR_ID_VDOEDT_ENC_FAILED);
            }
            DeleteUptoScrID(SCR_ID_VDOEDT_MAIN);
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_EDIT);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_get_slice_endtime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_shot          [IN]        the shot which need to get the end time
 *  ms_start        [IN]        offset from start of original video.
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_vdoedt_enc_get_slice_endtime(vdoedt_shot_struct *p_shot, U32 ms_start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ms_end = 0;
    U32 ms_eff_in_end = p_shot->ms_cut_in + MMI_VDOEDT_EFFECT_LVL * MMI_VDOEDT_EFFECT_INTERVAL;

    /* U32 ms_eff_out_begin = p_shot->ms_cut_out - MMI_VDOEDT_EFFECT_LVL * 1000; */
    U8 u;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (u = 0; u < 4; u++)
    {
        if (ms_start < g_vdoedt_cntx.ms_timeline[u])
        {
            ms_end = g_vdoedt_cntx.ms_timeline[u];
            break;
        }
    }
    if (4 == u)
    {
        ms_end = p_shot->ms_cut_out;
    }

    /* Transition effect - in */
    if (p_shot->in_effect)
    {
        if (ms_end == ms_eff_in_end)
        {
            ms_end = ms_start + MMI_VDOEDT_EFFECT_INTERVAL;
        }
    }

    /* transition effect - out */
    if (p_shot->out_effect)
    {
        if (ms_end == p_shot->ms_cut_out && ms_start <= ms_end - MMI_VDOEDT_EFFECT_INTERVAL)
        {
            ms_end = ms_start + MMI_VDOEDT_EFFECT_INTERVAL;
            if (ms_end > p_shot->ms_cut_out)
            {
                ms_end = p_shot->ms_cut_out;
            }
        }
    }

    return ms_end;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_next_slice
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_next_slice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_context_struct *p_cntx = &g_vdoedt_cntx;
    U32 ms_start = p_cntx->time_now - p_cntx->time_base;
    U32 ms_end;
    vdoedt_shot_struct *p_shot;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_shot = p_cntx->p_shot[p_cntx->i_act_shot];
    /* if !end of shot */
    if (ms_start + p_shot->ms_cut_in < p_shot->ms_cut_out)
    {
        mmi_vdoedt_frmtxt_set(p_cntx->i_act_shot, ms_start);
        mmi_vdoedt_effect_set(p_cntx->i_act_shot, ms_start);
        if (VDOEDT_SRC_VIDEO != p_shot->src_type)
        {
            mmi_vdoedt_draw_preview();
        }

        /* get ms_end */
        ms_end = mmi_vdoedt_enc_get_slice_endtime(p_shot, ms_start + p_shot->ms_cut_in);
        /* fill context */
        p_cntx->ms_slice_start = ms_start + p_shot->ms_cut_in;
        p_cntx->ms_slice_end = ms_end;
        /* use timer for my append */
        gui_start_timer(MMI_VDOEDT_ENCODE_DELAY, mmi_vdoedt_enc_append_cyclic);
    }
    else
    {
        if (++p_cntx->i_act_shot < p_cntx->shot_count)
        {
            mmi_vdoedt_update_time_base(p_cntx->i_act_shot);
            mmi_vdoedt_enc_update_timeline();
            /* todo: re-init items for new shot if need. */
            gdi_layer_push_and_set_active(p_cntx->h_frmtxt);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            gui_start_timer(MMI_VDOEDT_ENCODE_DELAY, mmi_vdoedt_enc_next_slice);
        }
        else
        {
            mmi_vdoedt_enc_state_update();
            gui_start_timer(MMI_VDOEDT_ENCODE_DELAY, mmi_vdoedt_enc_append_done);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_enc_state_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_enc_state_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vdoedt_time_struct hms;
    S8 a_str[9];
    S8 u_str[18];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdoedt_cntx.ms_t_total > g_vdoedt_cntx.time_now)
    {
        mmi_vdoedt_ms_2_hms(g_vdoedt_cntx.ms_t_total - g_vdoedt_cntx.time_now, &hms);
        sprintf(a_str, "%02u:%02u:%02u", hms.hh, hms.mm, hms.ss);
        mmi_asc_to_ucs2(u_str, a_str);
        UpdateCategory402Value((U16) (g_vdoedt_cntx.time_now * 100 / g_vdoedt_cntx.ms_t_total), (PU8) u_str);
    }
    else
    {
        sprintf(a_str, "00:00:00");
        mmi_asc_to_ucs2(u_str, a_str);
        UpdateCategory402Value((U16) 100, (PU8) u_str);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_frame_sel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_frame_sel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_frame_select_scr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_frame_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_frame_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_frame_clear, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_frame_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_frame_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_frame_txt_edt_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_hilight_frame_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_hilight_frame_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vdoedt_entry_frame_edit_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_check_disk_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b_req_size      [IN]        
 *  drive           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_vdoedt_check_disk_space(U32 b_req_size, PS8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h_file;
    FS_DiskInfo disk_info;

    /* S8 buf[16]; */
    U32 b_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* mmi_ucs2ncpy(buf, drive, 1); */
    h_file = FS_GetDiskInfo((PU16) drive, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (h_file >= FS_NO_ERROR)
    {
        b_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (b_space >= b_req_size)
        {
            return TRUE;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_create_tmpdir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_vdoedt_create_tmpdir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drive;
    S8 buf[64];

    /* S8 UCS2_buf[128]; */
    FS_HANDLE h_file;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if (drive >= FS_NO_ERROR)
    {
        sprintf(buf, "%c:\\", (U8) drive);
        mmi_asc_to_ucs2(g_vdoedt_cntx.cache_path, buf);

        h_file = FS_Open((kal_uint16*) g_vdoedt_cntx.cache_path, FS_OPEN_DIR | FS_READ_ONLY);
        if (h_file >= FS_NO_ERROR)
        {
            FS_Close(h_file);
            if (mmi_vdoedt_check_disk_space((U32) MMI_VDOEDT_CACHE_SPACE, g_vdoedt_cntx.cache_path))
            {
                /* create dir */
                mmi_ucs2cat(g_vdoedt_cntx.cache_path, (PS8) MMI_VDOEDT_TMP_PATH);
 
                h_file = FS_Open((kal_uint16*) g_vdoedt_cntx.cache_path, FS_OPEN_DIR | FS_READ_ONLY);
                if (h_file >= FS_NO_ERROR)
                {
                    /* folder already exists */
                    FS_Close(h_file);
                    return FS_NO_ERROR;
                }
                /* notenotenote */
                ret = FS_CreateDir((PU16) g_vdoedt_cntx.cache_path);
                if (ret >= 0)
                {
                    drive = FS_GetAttributes((PU16) g_vdoedt_cntx.cache_path);
                    if (drive >= FS_NO_ERROR)
                    {
                        FS_SetAttributes((PU16) g_vdoedt_cntx.cache_path, drive | FS_ATTR_HIDDEN);
                        return FS_NO_ERROR;
                    }
                }
                else
                {
                    memset((void*)g_vdoedt_cntx.cache_path, 0, 32);
                    return ret;
                }
            }
            else
            {
                /* disk space not enough */
                return FS_DISK_FULL;
            }
        }
        else
        {
            return (S32)h_file;
        }
    }

    return drive;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_remov_tmpdir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_remov_tmpdir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(g_vdoedt_cntx.cache_path))
    {
        FS_RemoveDir((PU16) g_vdoedt_cntx.cache_path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_update_cachefile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if updating sucessful.
 *****************************************************************************/
BOOL mmi_vdoedt_update_cachefile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle h_layer = GDI_NULL_HANDLE;
    PU8 p_buff = NULL;
    PS8 p_fbuff = NULL;
    vdoedt_shot_struct *p_shot = g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot];
    vdoedt_shot_struct *p_tmpshot = NULL;
    U64 time = 0;
    gdi_result g_res = 0;
    mdi_result m_res = 0;
    S8 fname[MMI_VDOEDT_TMP_PATH_BUF_SIZE];
    S8 a_fnum[4];
    S8 u_fnum[8];
    S32 strlen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strlen = mmi_ucs2strlen(p_shot->ustr_fname);
    if (0 != strlen && MMI_VDOEDT_TMP_PATH_BUF_SIZE >= strlen)
    {
        mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
        mmi_ucs2cat(fname, p_shot->ustr_fname);
        FS_Delete((PU16)fname);
    }    
    
    /* CHECK DISK SPACE! */
    if (!mmi_vdoedt_check_disk_space(MMI_VDOEDT_PREV_BUF_SIZE, 0))
    {
        mmi_vdoedt_popup(FMGR_FS_DISK_FULL_TEXT);
        return FALSE;
    }

    /* assume source file is valid */
    /* create template layer */
    p_buff = (PU8) mmi_frm_scrmem_alloc(MMI_VDOEDT_PREV_BUF_SIZE);
    g_res = gdi_layer_create_using_outside_memory(
                0,
                0,
                g_vdoedt_main_osd_cntx.play_wnd.width,
                g_vdoedt_main_osd_cntx.play_wnd.height,
                &h_layer,
                p_buff,
                MMI_VDOEDT_PREV_BUF_SIZE);
    ASSERT(g_res == GDI_SUCCEED);
    gdi_layer_push_and_set_active(h_layer);
    if (VDOEDT_SRC_VIDEO == p_shot->src_type)
    {
        mdi_video_edt_active(p_shot->h_video);
        m_res = mdi_video_ply_seek_and_get_frame(p_shot->ms_cut_in, h_layer);
        mdi_video_edt_deactive();
        if (m_res != MDI_RES_VDOPLY_SUCCEED)
        {
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(h_layer);
            mmi_frm_scrmem_free(p_buff);
            mmi_vdoedt_seek_result_handler(m_res);
            return FALSE;
        }
    }
    else if (VDOEDT_SRC_IMG_FILE == p_shot->src_type)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
        p_fbuff = (PS8) mmi_frm_scrmem_alloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        ASSERT(p_fbuff);
        mmi_fmgr_util_load_filepath(p_fbuff, FMGR_PATH_ID_VIDEO_EDITOR);
        g_res = mmi_vdoedt_draw_img_file_in_rect(
                    p_fbuff,
                    g_vdoedt_main_osd_cntx.play_wnd.width,
                    g_vdoedt_main_osd_cntx.play_wnd.height);
        mmi_frm_scrmem_free(p_fbuff);
    }
    else if (VDOEDT_SRC_LAST_FRAME == p_shot->src_type || VDOEDT_SRC_FIRST_FRAME == p_shot->src_type)
    {
        if (VDOEDT_SRC_LAST_FRAME == p_shot->src_type)
        {
            p_tmpshot = (g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot - 1]);
            time = p_tmpshot->ms_cut_out;
        }
        else
        {
            p_tmpshot = (g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot + 1]);
            time = p_tmpshot->ms_cut_in;
        }
        mdi_video_edt_active(p_tmpshot->h_video);
        m_res = mdi_video_ply_seek_and_get_frame(time, h_layer);
        mdi_video_edt_deactive();
        
        if (m_res != MDI_RES_VDOPLY_SUCCEED)
        {
            /* becuz this is insert video frame. 
            if failed => ishot & (ishot+1 or ishot-1) is invalid*/
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(h_layer);
            mmi_frm_scrmem_free(p_buff);
            /* do not remove shot here. remove outside */
            return FALSE;
        }
    }
    else
    {
        ASSERT(VDOEDT_SRC_RESERVED < p_shot->src_type && p_shot->src_type <= VDOEDT_SRC_COLOR);
    }

    gdi_layer_pop_and_restore_active();
    gdi_layer_free(h_layer);
    mmi_frm_scrmem_free(p_buff);
    
    /* if filename is not exist. generate filename */
    if (mmi_ucs2strlen(p_shot->ustr_fname) == 0)
    {
        sprintf(a_fnum, "%d", (p_shot - g_vdoedt_cntx.p_shot_mem[0]));
        mmi_asc_to_ucs2(u_fnum, a_fnum);
        mmi_ucs2cat(p_shot->ustr_fname, (PS8) MMI_VDOEDT_TMP_FNAME);
        mmi_ucs2cat(p_shot->ustr_fname, u_fnum);
        mmi_ucs2cat(p_shot->ustr_fname, (PS8) L".PBM");
    }
    mmi_ucs2cpy(fname, g_vdoedt_cntx.cache_path);
    mmi_ucs2cat(fname, p_shot->ustr_fname);

    g_res = gdi_layer_save_pbm_file(h_layer, fname);

    if (g_res != GDI_SUCCEED)
    {
        memset((void*)p_shot->ustr_fname, 0, MMI_VDOEDT_CACHE_FNAME_SIZE);
        mmi_vdoedt_popup(FMGR_FS_DISK_FULL_TEXT);
        return FALSE;
    }
    return TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_remov_cachefile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_remov_cachefile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fpathname[MMI_VDOEDT_TMP_PATH_BUF_SIZE];
    S32 i;
    S32 ret = 0;
    vdoedt_shot_struct *p_shot;
    PS8 p_fname;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(fpathname, g_vdoedt_cntx.cache_path);
    p_fname = (fpathname + (mmi_ucs2strlen(fpathname) * 2));
    for (i = 0; i < g_vdoedt_cntx.shot_count; i++)
    {
        p_shot = g_vdoedt_cntx.p_shot[i];
        if (mmi_ucs2strlen(p_shot->ustr_fname))
        {
            mmi_ucs2cpy(p_fname, p_shot->ustr_fname);
        }
        ret = FS_Delete((PU16) fpathname);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_popup(U16 id_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id_img = IMG_GLOBAL_ERROR;
    U8  id_tone = ERROR_TONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (isInCall())
    {
        return;  /* do not popup if is in caller screen. */
    }
    
    switch (id_str)
    {
        case STR_FMGR_INVALID_FORMAT:
        case STR_ID_VDOEDT_NO_SAVE_SPACE:
        case STR_ID_VDOEDT_EMPTY_STRING:
        case STR_ID_VDOEDT_INVALID_VDO:
        case STR_GLOBAL_DRM_PROHIBITED:
        case FMGR_FS_ROOT_DIR_FULL_TEXT:
            id_img = IMG_GLOBAL_WARNING;
            id_tone = WARNING_TONE;
            break;

        case STR_GLOBAL_ERROR:
        case FMGR_FS_INVALID_FILENAME_TEXT:
        case FMGR_FS_WRITE_PROTECTION_TEXT:
        case FMGR_FS_DISK_FULL_TEXT:
        case STR_ID_VDOEDT_CREATE_DIR_FAIL:
        case STR_ID_VDOEDT_ENC_FAILED:
        case STR_ID_VDOEDT_BAD_VDO_REMOVE_NOTIFY:
        case STR_ID_VDOEDT_ERR_TOO_SHORT:
        case STR_ID_VDOEDT_ERR_TOO_LONG:
        case STR_ID_VDOEDT_ERR_RESOLUTION:
        case STR_ID_VDOEDT_ERR_UNSUP_FORMAT:
        case STR_FMGR_EMPTY_FILENAME:
            break;
            
        case STR_GLOBAL_DONE:
            id_img = IMG_GLOBAL_ACTIVATED;
            id_tone = SUCCESS_TONE;
            break;
            
        case 0:
            return;
            
        default:
            break;
    }

    DisplayPopup((PU8) GetString(id_str), id_img, 1, UI_POPUP_NOTIFYDURATION_TIME, id_tone);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_ms_2_hms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ms_conv         [IN]        
 *  hms_time_t      [OUT]         the result hh:mm:ss
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_ms_2_hms(U32 ms_conv, mmi_vdoedt_time_struct *hms_time_t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ms_conv /= 1000;
    hms_time_t->hh = ms_conv / 3600;
    ms_conv %= 3600;
    hms_time_t->mm = ms_conv / 60;
    hms_time_t->ss = ms_conv % 60;

    if (hms_time_t->hh > 99)
    {
        hms_time_t->hh = 99;
    }
}

/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 * #appmem related                                                         
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
#ifdef __MMI_VDOEDT_USE_APPMEM__


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_free_appmem
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_free_appmem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free(g_vdoedt_cntx.p_shot_mem[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_stop_calback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_stop_calback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop files */

    /* free memory */
    mmi_vdoedt_free_appmem();
}
#endif /* __MMI_VDOEDT_USE_APPMEM__ */ 

#ifdef __MMI_TOUCH_SCREEN__
/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 * #touch related                                                         
 *-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_util_set_touch_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_util_set_touch_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_pen_down_handler(mmi_vdoedt_pen_down_hdlr);
    wgui_register_pen_move_handler(mmi_vdoedt_pen_move_hdlr);
    wgui_register_pen_up_handler(mmi_vdoedt_pen_up_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_touch_hit
 * DESCRIPTION
 *  test if the coordinate is fall with the range of object.
 * PARAMETERS
 *  x           [IN]        X position
 *  y           [IN]        Y position
 *  p_obj       [IN]        The pointer to object to test.
 * RETURNS
 *  if x,y fall inside the range of p_obj => TRUE, else FALSE.
 *****************************************************************************/
BOOL mmi_vdoedt_touch_hit(S32 x, S32 y, vdoedt_ui_obj_struct *p_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1 = p_obj->x;
    S32 y1 = p_obj->y;
    S32 x2 = x1 + p_obj->w;
    S32 y2 = y1 + p_obj->h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = pos.x;
    S32 y = pos.y;
    S32 i;
    U8 redraw = 0;
    U16 scr_id = GetActiveScreenId();
    vdoedt_ui_key_struct *p_key = &g_vdoedt_key_cntx;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_key->event = VDOEDT_OBJ_RESERVED;

    if (mmi_vdoedt_touch_hit(x, y, &p_key->lsk))
    {
        p_key->lsk.pressed = TRUE;
        p_key->event = VDOEDT_OBJ_LSK;
        redraw |= MMI_VDOEDT_R4W_SKEY;
    }
    else if (mmi_vdoedt_touch_hit(x, y, &p_key->rsk))
    {
        p_key->rsk.pressed = TRUE;
        p_key->event = VDOEDT_OBJ_RSK;
        redraw |= MMI_VDOEDT_R4W_SKEY;
    }
    else if (mmi_vdoedt_touch_hit(x, y, &p_key->ck))
    {
        if (stat == MMI_VDOEDT_S_SEEK || stat == MMI_VDOEDT_S_SEEK_UPDATING)
        {
            return;
        }
        /* play key */
        p_key->ck.pressed = TRUE;
        p_key->event = VDOEDT_OBJ_CK;
        redraw |= MMI_VDOEDT_R4W_SKEY;
    }

    if (SCR_ID_VDOEDT_MAIN == scr_id)
    {
        if (mmi_vdoedt_touch_hit(x, y, &p_key->pbar))
        {
            p_key->event = VDOEDT_OBJ_PBAR;

            if (MMI_VDOEDT_S_SEEK == stat || MMI_VDOEDT_S_PLAY_SEEK == stat)
            {
                gui_cancel_timer(mmi_vdoedt_update_seek_frame);
            }
            else if (MMI_VDOEDT_S_SEEK_UPDATING == stat || MMI_VDOEDT_S_PLAY_SEEK_UPDATING == stat)
            {
                if (VDOEDT_SRC_VIDEO == g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type)
                {
                    mdi_video_ply_stop_non_block_seek();
                }
            }
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->ebar))
        {
            p_key->event = VDOEDT_OBJ_EBAR;
            for (i = 0; MMI_VDOEDT_S_EDIT == stat && i < MMI_VDOEDT_MAX_CLIP_NUM; i++)
            {
                if (mmi_vdoedt_touch_hit(x, y, &p_key->shot[i]))
                {
                    p_key->event = VDOEDT_OBJ_SHOT1 + i;
                    break;
                }
            }
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->ffk))
        {
            p_key->event = VDOEDT_OBJ_FFK;
            mmi_vdoedt_key_ff_down();
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->rwk))
        {
            p_key->event = VDOEDT_OBJ_RWK;
            mmi_vdoedt_key_rw_down();
        }
        g_vdoedt_cntx.flg_main_r4w |= redraw;
    }
    else if ((SCR_ID_VDOEDT_VIDEO_CUT == scr_id || SCR_ID_VDOEDT_FRAME_EDIT == scr_id) &&
            (MMI_VDOEDT_S_CUT_PLAY != stat && MMI_VDOEDT_S_FRM_PLAY != stat))
    {
        /**********************************/
        /* 1.must in cut/frame edit screen*/
        /* 2.must not in playing state    */
        /**********************************/
        
        if (mmi_vdoedt_touch_hit(x, y, &p_key->cbar))
        {
            p_key->event = VDOEDT_OBJ_CBAR;
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->cut_in))
        {
            p_key->event = VDOEDT_OBJ_CUT_IN;
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->cut_out))
        {
            p_key->event = VDOEDT_OBJ_CUT_OUT;
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->in_lak))
        {

            p_key->event = VDOEDT_OBJ_IN_LAK;
            if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
            {
                mmi_vdoedt_cut_scr_leftkey_down();
            }
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->in_rak))
        {
            p_key->event = VDOEDT_OBJ_IN_RAK;
            if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
            {
                mmi_vdoedt_cut_scr_rightkey_down();
            }
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->out_lak))
        {
            p_key->event = VDOEDT_OBJ_OUT_LAK;
            if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
            {
                mmi_vdoedt_cut_scr_leftkey_down();
            }
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->out_rak))
        {
            p_key->event = VDOEDT_OBJ_OUT_RAK;
            if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
            {
                mmi_vdoedt_cut_scr_rightkey_down();
            }
        }
        g_vdoedt_cntx.flg_cut_r4w |= redraw;
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == scr_id)
    {
        if (mmi_vdoedt_touch_hit(x, y, &p_key->frame_n))
        {
            p_key->event = VDOEDT_OBJ_FRAME_NEXT;
            mmi_vdoedt_frm_sel_rak_down();
        }
        else if (mmi_vdoedt_touch_hit(x, y, &p_key->frame_pre))
        {
            p_key->event = VDOEDT_OBJ_FRAME_PREV;
            mmi_vdoedt_frm_sel_lak_down();
        }
		g_vdoedt_cntx.flg_frm_sel_r4w = redraw;
    }

    if (redraw)
    {
        mmi_vdoedt_redraw();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = pos.x;
    S32 y = pos.y;
    U16 scr_id = GetActiveScreenId();
    U8 redraw = 0;
    vdoedt_ui_key_struct *p_key = &g_vdoedt_key_cntx;
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_key->event)
    {
        case VDOEDT_OBJ_LSK:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->lsk))
            {
                /* moved out */
                p_key->lsk.pressed = FALSE;
            }
            else
            {
                p_key->lsk.pressed = TRUE;
            }
            redraw |= MMI_VDOEDT_R4W_SKEY;
            break;

        case VDOEDT_OBJ_RSK:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->rsk))
            {
                p_key->rsk.pressed = FALSE;
            }
            else
            {
                p_key->rsk.pressed = TRUE;
            }
            redraw |= MMI_VDOEDT_R4W_SKEY;
            break;

        case VDOEDT_OBJ_CK:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->ck))
            {
                p_key->ck.pressed = FALSE;
            }
            else
            {
                p_key->ck.pressed = TRUE;
            }
            redraw |= MMI_VDOEDT_R4W_SKEY;
            break;

        case VDOEDT_OBJ_CUT_IN:
            if (MMI_VDOEDT_S_EDIT_CUT_IN == stat || MMI_VDOEDT_S_EDIT_FRAME_IN == stat)
            {
                /* p_key->cut_in.x = x - (p_key->cut_in.w >> 1); */
                p_key->x_cut_in = x - (p_key->cut_in.w >> 1);
                mmi_vdoedt_check_cut_bound(&p_key->x_cut_in);
                p_key->cut_in.x = p_key->x_cut_in;
                redraw |= MMI_VDOEDT_R4W_IN_BTN | MMI_VDOEDT_R4W_EBAR;
            }
            break;

        case VDOEDT_OBJ_CUT_OUT:
            if (MMI_VDOEDT_S_EDIT_CUT_OUT == stat || MMI_VDOEDT_S_EDIT_FRAME_OUT == stat)
            {
                p_key->x_cut_out = x - (p_key->cut_out.w >> 1);
                mmi_vdoedt_check_cut_bound(&p_key->x_cut_out);
                p_key->cut_out.x = p_key->x_cut_out;
                redraw |= MMI_VDOEDT_R4W_OUT_BTN | MMI_VDOEDT_R4W_EBAR;
            }
            break;

        case VDOEDT_OBJ_FRAME_NEXT:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->frame_n))
            {
                p_key->frame_n.pressed = FALSE;
                redraw |= MMI_VDOEDT_R4W_FRM_SEL_BTN;
            }
            break;

        case VDOEDT_OBJ_FRAME_PREV:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->frame_pre))
            {
                p_key->frame_pre.pressed = FALSE;
                redraw |= MMI_VDOEDT_R4W_FRM_SEL_BTN;
            }
            break;

        case VDOEDT_OBJ_FFK:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->ffk))
            {
                mmi_vdoedt_key_seek_up();
            }
            break;

        case VDOEDT_OBJ_RWK:
            if (!mmi_vdoedt_touch_hit(x, y, &p_key->rwk))
            {
                mmi_vdoedt_key_seek_up();
            }
            break;

        case VDOEDT_OBJ_PBAR:
            if (MMI_VDOEDT_S_PREVIEW == stat ||
                MMI_VDOEDT_S_PREVIEW_PLAY == stat || MMI_VDOEDT_S_SEEK == stat || MMI_VDOEDT_S_PLAY_SEEK == stat)
            {
                if (MMI_VDOEDT_S_PREVIEW == stat)
                {
                    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK);
                }
                else if (MMI_VDOEDT_S_PREVIEW_PLAY == stat)
                {
                    mmi_vdoedt_play_pause();
                    mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK);
                }
                mmi_vdoedt_seek_by_touch(x);
                g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_PBAR;
            }
            break;
        default:
            break;
    }

    if (SCR_ID_VDOEDT_MAIN == scr_id)
    {
        g_vdoedt_cntx.flg_main_r4w |= redraw;
    }
    else if (SCR_ID_VDOEDT_VIDEO_CUT == scr_id || SCR_ID_VDOEDT_FRAME_EDIT == scr_id)
    {
        g_vdoedt_cntx.flg_cut_r4w |= redraw;
    }
    else if (SCR_ID_VDOEDT_FRAME_PREVIEW == scr_id)
    {
        g_vdoedt_cntx.flg_frm_sel_r4w |= redraw;
    }

    mmi_vdoedt_redraw();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x = pos.x;
    S32 y = pos.y;
    U16 scr_id = GetActiveScreenId();
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();
    vdoedt_state_enum stat_e, stat_out, stat_in;
    vdoedt_ui_key_struct *p_key = &g_vdoedt_key_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p_key->event)
    {
        case VDOEDT_OBJ_LSK:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->lsk))
            {
                mmi_vdoedt_lsk_up();
            }
            break;

        case VDOEDT_OBJ_RSK:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->rsk))
            {
                mmi_vdoedt_rsk_up();
            }
            break;

        case VDOEDT_OBJ_CK:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->ck) && p_key->ck.pressed)
            {
                if (mmi_vdoedt_ck_up == GetKeyHandler(KEY_ENTER, KEY_EVENT_UP))
                {
                    mmi_vdoedt_ck_up();
                }
            }
            break;

        case VDOEDT_OBJ_PBAR:
            /* if user pen-up outside the progressbar, we should still seek to that point */
            p_key->event = VDOEDT_OBJ_RESERVED;
            mmi_vdoedt_touch_on_pbar(x, y);
            break;

        case VDOEDT_OBJ_EBAR:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->ebar))
            {
                if (MMI_VDOEDT_S_EDIT != stat)
                {
                    mmi_vdoedt_main_scr_downkey_hdlr();
                }
            }
            break;

        case VDOEDT_OBJ_FRAME_NEXT:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->frame_n))
            {
                mmi_vdoedt_frm_sel_rak_up();
            }
            break;

        case VDOEDT_OBJ_FRAME_PREV:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->frame_pre))
            {
                mmi_vdoedt_frm_sel_lak_up();
            }
            break;

        case VDOEDT_OBJ_FFK:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->ffk))
            {
                mmi_vdoedt_key_seek_up();
            }
            break;

        case VDOEDT_OBJ_RWK:
            if (mmi_vdoedt_touch_hit(x, y, &p_key->rwk))
            {
                mmi_vdoedt_key_seek_up();
            }
            break;

        default:
            if ((MMI_VDOEDT_S_EDIT == stat) && mmi_vdoedt_touch_hit(x, y, &p_key->ebar))
            {
                for (i = 0; i <= g_vdoedt_cntx.shot_count; i++)
                {
                    if (p_key->event == (VDOEDT_OBJ_SHOT1 + i) &&
                        mmi_vdoedt_touch_hit(x, y, &p_key->shot[i]) && i != g_vdoedt_cntx.i_act_shot)
                    {
                        g_vdoedt_cntx.i_act_shot = i;
                        //mmi_vdoedt_update_time_base(i);
                        //g_vdoedt_cntx.time_now = g_vdoedt_cntx.time_base;
                        g_vdoedt_cntx.flg_main_r4w = (MMI_VDOEDT_R4W_ALL & ~(MMI_VDOEDT_R4W_KEYFRMS));
                        mmi_vdoedt_redraw();
                        break;
                    }
                }
            }
            break;
    }

    if (SCR_ID_VDOEDT_VIDEO_CUT == scr_id || SCR_ID_VDOEDT_FRAME_EDIT == scr_id)
    {
        if (SCR_ID_VDOEDT_VIDEO_CUT == scr_id)
        {
            stat_e = MMI_VDOEDT_S_EDIT_CUT;
            stat_in = MMI_VDOEDT_S_EDIT_CUT_IN;
            stat_out = MMI_VDOEDT_S_EDIT_CUT_OUT;
        }
        else
        {
            stat_e = MMI_VDOEDT_S_EDIT_FRAME;
            stat_in = MMI_VDOEDT_S_EDIT_FRAME_IN;
            stat_out = MMI_VDOEDT_S_EDIT_FRAME_OUT;
        }
        switch (p_key->event)
        {
            case VDOEDT_OBJ_CBAR:
                if (stat_out == stat)
                {
                    mmi_vdoedt_cut_scr_downkey_hdlr();
                }
                else if (stat_in == stat)
                {
                    mmi_vdoedt_cut_scr_upkey_hdlr();
                }
                break;
            case VDOEDT_OBJ_CUT_IN:
                if (stat_out == stat)
                {
                    mmi_vdoedt_enter_stat(stat_in);
                    mmi_vdoedt_redraw();
                }
                else if (stat_e == stat)
                {
                    mmi_vdoedt_cut_scr_downkey_hdlr();
                }
                else if (stat_in == stat)
                {
                    mmi_vdoedt_check_cut_bound(&g_vdoedt_key_cntx.x_cut_in);
                    g_vdoedt_key_cntx.cut_in.x = g_vdoedt_key_cntx.x_cut_in;
                    gui_cancel_timer(mmi_vdoedt_update_cut_preview);
                    gui_start_timer(MMI_VDOEDT_KEY_TRIG_DELAY, mmi_vdoedt_update_cut_preview);
                }
                break;

            case VDOEDT_OBJ_CUT_OUT:
                if (stat_in == stat)
                {
                    mmi_vdoedt_enter_stat(stat_out);
                    mmi_vdoedt_redraw();
                }
                else if (stat_e == stat)
                {
                    mmi_vdoedt_cut_scr_upkey_hdlr();
                }
                else if (stat_out == stat)
                {
                    mmi_vdoedt_check_cut_bound(&g_vdoedt_key_cntx.x_cut_out);
                    g_vdoedt_key_cntx.cut_out.x = g_vdoedt_key_cntx.x_cut_out;
                    gui_cancel_timer(mmi_vdoedt_update_cut_preview);
                    gui_start_timer(MMI_VDOEDT_KEY_TRIG_DELAY, mmi_vdoedt_update_cut_preview);
                }
                break;

            case VDOEDT_OBJ_IN_LAK:
                if (stat_in == stat)
                {
                    mmi_vdoedt_cut_scr_leftkey_up();
                }
                else if (mmi_vdoedt_touch_hit(x, y, &p_key->in_lak))
                {
                    mmi_vdoedt_enter_stat(stat_in);
                    mmi_vdoedt_redraw();
                }
                break;

            case VDOEDT_OBJ_IN_RAK:
                if (stat_in == stat)
                {
                    mmi_vdoedt_cut_scr_rightkey_up();
                }
                else if (mmi_vdoedt_touch_hit(x, y, &p_key->in_rak))
                {
                    mmi_vdoedt_enter_stat(stat_in);
                    mmi_vdoedt_redraw();
                }
                break;

            case VDOEDT_OBJ_OUT_LAK:
                if (stat_out == stat)
                {
                    mmi_vdoedt_cut_scr_leftkey_up();
                }
                else if (mmi_vdoedt_touch_hit(x, y, &p_key->out_lak))
                {
                    mmi_vdoedt_enter_stat(stat_out);
                    mmi_vdoedt_redraw();
                }
                break;

            case VDOEDT_OBJ_OUT_RAK:
                if (stat_out == stat)
                {
                    mmi_vdoedt_cut_scr_rightkey_up();
                }
                else if (mmi_vdoedt_touch_hit(x, y, &p_key->out_rak))
                {
                    mmi_vdoedt_enter_stat(stat_out);
                    mmi_vdoedt_redraw();
                }
                break;

            default:
                break;
        }
        if (g_vdoedt_cntx.flg_cut_r4w)
        {
            mmi_vdoedt_redraw();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdoedt_touch_on_pbar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdoedt_touch_on_pbar(s16 x, s16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vdoedt_state_enum stat = mmi_vdoedt_get_stat();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_VDOEDT_S_SEEK == stat || MMI_VDOEDT_S_PLAY_SEEK == stat)
    {
        gui_cancel_timer(mmi_vdoedt_update_seek_frame);
        gui_start_timer(300, mmi_vdoedt_update_seek_frame);
    }
    else if (MMI_VDOEDT_S_SEEK_UPDATING == stat || MMI_VDOEDT_S_PLAY_SEEK_UPDATING == stat)
    {
        if (g_vdoedt_cntx.p_shot[g_vdoedt_cntx.i_act_shot]->src_type == VDOEDT_SRC_VIDEO)
        {
            mdi_video_ply_stop_non_block_seek();
            mdi_video_edt_deactive();   /* the callback handler won't be invoked after deactive */
        }
        mmi_vdoedt_seek_by_touch(x);
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_PBAR;
        mmi_vdoedt_redraw();
        if (MMI_VDOEDT_S_SEEK_UPDATING == stat)
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK);
        }
        else
        {
            mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK);
        }
        gui_start_timer(300, mmi_vdoedt_update_seek_frame);
    }
    else if (MMI_VDOEDT_S_PREVIEW == stat || MMI_VDOEDT_S_SEEK_DONE == stat)
    {
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_SEEK);
        mmi_vdoedt_seek_by_touch(x);
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_PBAR;
        mmi_vdoedt_redraw();
        gui_start_timer(300, mmi_vdoedt_update_seek_frame);
    }
    else if (MMI_VDOEDT_S_PREVIEW_PLAY == stat || MMI_VDOEDT_S_PLAY_SEEK_DONE == stat)
    {
        mmi_vdoedt_play_pause();
        mmi_vdoedt_enter_stat(MMI_VDOEDT_S_PLAY_SEEK);
        mmi_vdoedt_seek_by_touch(x);
        g_vdoedt_cntx.flg_main_r4w |= MMI_VDOEDT_R4W_TIME | MMI_VDOEDT_R4W_PBAR;
        mmi_vdoedt_redraw();
        gui_start_timer(300, mmi_vdoedt_update_seek_frame);
    }
    else
    {
        mmi_vdoedt_main_scr_upkey_hdlr();
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 

#endif /* __MMI_VIDEO_EDITOR__ */ 

