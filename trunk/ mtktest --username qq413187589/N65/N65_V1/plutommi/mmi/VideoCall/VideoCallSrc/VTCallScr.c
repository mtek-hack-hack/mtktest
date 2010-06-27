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
 *   VTCallScr.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Telephony Call Screen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_VIDEO_TELEPHONY__

#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */
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

/* tmp include */
#include "VdoPlyResDef.h"

#include "SettingProfile.h"     /* warning tone */
#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* error string id */
#include "FileMgr.h"
#include "USBDeviceGprot.h"     /* USB MS mode */
#include "DataAccountGprot.h"
#include "DateTimeGprot.h"      /* time related */
#include "wgui_status_icons.h"  /* status UI */

#include "mmi_vt_struct.h"      /* User input indication */
#include "BTMMIScrGprots.h" 

#ifdef __MMI_VT_FEATURE_TOUCH__
#include "wgui_touch_screen.h"
#endif 

#include "VTCallScrGprot.h"
#include "VTCallScrProt.h"
#include "resource_vt_skins.h"

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"             /* mdi tvout */
#endif /* __MMI_TVOUT__ */ 

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"          /* DRM support */
#endif /* __DRM_SUPPORT__ */ 

#include "imageviewer.h"
#include "VdoPlyGprot.h"

#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMProt.h"
#include "VTResDef.h" /* Modified by Tony */
#include "VTProt.h" 

#include "CallmanagementIdDef.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_VTCS_SKIN_BUF_DEPTH     (2) /* 16 bit */
#define MMI_VTCS_SKIN_BUF_SIZE      (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * MMI_VTCS_SKIN_BUF_DEPTH * 2) /* *2 for double buffer */

#define MMI_VTCS_ENCODE_BUF_DEPTH   (2) /* 16 bit */
#define MMI_VTCS_ENCODE_BUF_WIDTH   (176)
#define MMI_VTCS_ENCODE_BUF_HEIGHT  (144)
#define MMI_VTCS_ENCODE_BUF_SIZE    (MMI_VTCS_ENCODE_BUF_WIDTH * MMI_VTCS_ENCODE_BUF_HEIGHT * MMI_VTCS_ENCODE_BUF_DEPTH)

#define MMI_VTCS_UPDATE_TIME_DUR                (300) /* 300 ms update once */
#define MMI_VTCS_TOGGLE_TIME_PANEL_DISP_DUR     (5000) /* 5 sec update once */

#define MMI_VTCS_UT_DEBUG
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/



/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
mmi_vtcs_cntx_struct g_mmi_vtcs_cntx;

const U16 mmi_vtcs_dtmf_key[MMI_VTCS_DTMF_KEY_NO] = 
{
    KEY_0, KEY_1, KEY_2, KEY_3,
    KEY_4, KEY_5, KEY_6, KEY_7,
    KEY_8, KEY_9, KEY_STAR,
    KEY_POUND
};


/***************************************************************************** 
 * Local Function
 *****************************************************************************/
static void mmi_vtcs_allocate_resource(void); 
static void mmi_vtcs_free_resource(void);
static void mmi_vtcs_config_display_mode(mmi_vtcs_display_mode_enum mode);
static void mmi_vtcs_toggle_time_panel_display(void);
static void mmi_vtcs_update_call_status_cyclic(void);
static void mmi_vtcs_init_state(void);
static void mmi_vtcs_register_key_event(void);
static void mmi_vtcs_snapshot_key_press(void);
static void mmi_vtcs_snapshot_key_release(void);
static void mmi_vtcs_camera_key_press(void);
static void mmi_vtcs_camera_key_release(void);
static void mmi_vtcs_mic_key_press(void);
static void mmi_vtcs_mic_key_release(void);
static void mmi_vtcs_speaker_key_press(void);
static void mmi_vtcs_speaker_key_release(void);
static void mmi_vtcs_aud_rec_key_press(void);
static void mmi_vtcs_aud_rec_key_release(void);
static void mmi_vtcs_ev_key_press(void);
static void mmi_vtcs_ev_key_release(void);
static void mmi_vtcs_ev_inc_cyclic(void);
static void mmi_vtcs_ev_dec_cyclic(void);
static void mmi_vtcs_ev_inc_key_press(void);
static void mmi_vtcs_ev_inc_key_release(void);
static void mmi_vtcs_ev_dec_key_press(void);
static void mmi_vtcs_ev_dec_key_release(void);
static void mmi_vtcs_zoom_in_cyclic(void);
static void mmi_vtcs_zoom_out_cyclic(void);
static void mmi_vtcs_zoom_in_key_press(void);
static void mmi_vtcs_zoom_in_key_release(void);
static void mmi_vtcs_zoom_out_key_press(void);
static void mmi_vtcs_zoom_out_key_release(void);
static void mmi_vtcs_vol_up_cyclic(void);
static void mmi_vtcs_vol_down_cyclic(void);
static void mmi_vtcs_vol_up_key_press(void);
static void mmi_vtcs_vol_up_key_release(void);
static void mmi_vtcs_vol_down_key_press(void);
static void mmi_vtcs_vol_down_key_release(void);
static void mmi_vtcs_lsk_press(void);
static void mmi_vtcs_lsk_release(void);
static void mmi_vtcs_rsk_press(void);
static void mmi_vtcs_rsk_release(void);
static void mmi_vtcs_ctrl_panel_restore_hdlr(void);
static void mmi_vtcs_enable_ctrl_panel_scroll(
    mmi_vtcs_ctrl_panel_enum state,
    U16 inc_img, 
    U16 dec_img,
    S32 cur_value, 
    S32 total_value);
static void mmi_vtcs_disable_ctrl_panel_scroll(void);
static void mmi_vtcs_update_ctrl_panel_scroll_cur_value(S32 cur_value);
static void mmi_vtcs_ctrl_panel_scroll_inc_press(void);
static void mmi_vtcs_ctrl_panel_scroll_inc_release(void);
static void mmi_vtcs_ctrl_panel_scroll_dec_press(void);
static void mmi_vtcs_ctrl_panel_scroll_dec_release(void);
static U32  mmi_vtcs_get_zoom_factor(void);
static U32  mmi_vtcs_get_ev_factor(void);
static U32  mmi_vtcs_get_cam_rotate_factor(void);
static U32  mmi_vtcs_get_enc_quality_factor(void);
static U32  mmi_vtcs_get_enc_size_factor(void);
static void mmi_vtcs_draw_status(void);
static void mmi_vtcs_draw_title(void);
static void mmi_vtcs_draw_body(void);
static void mmi_vtcs_draw_time_panel(void);
static void mmi_vtcs_draw_ctrl_panel(void);
static void mmi_vtcs_draw_ctrl_panel_camera(void);
static void mmi_vtcs_draw_ctrl_panel_mic(void);
static void mmi_vtcs_draw_ctrl_panel_speaker(void);
static void mmi_vtcs_draw_ctrl_panel_aud_rec(void);
static void mmi_vtcs_draw_ctrl_panel_snapshot(void);
static void mmi_vtcs_draw_ctrl_panel_ev(void);
static void mmi_vtcs_draw_ctrl_panel_zoom(void);
static void mmi_vtcs_draw_softkey(void);
static void mmi_vtcs_set_softkey(U16 lsk_id, U16 rsk_id);
static void mmi_vtcs_draw_main_wnd(void);
static void mmi_vtcs_draw_sub_wnd(void);
static void mmi_vtcs_clean_main_wnd(void);
static void mmi_vtcs_clean_sub_wnd(void);
static void mmi_vtcs_open_main_wnd_hole(void);
static void mmi_vtcs_open_sub_wnd_hole(void);
static void mmi_vtcs_draw_skin(void);
static void mmi_vtcs_draw_encode_layer(void);
static void mmi_vtcs_start_event_callback_hdlr(mdi_video_tel_codec_event_enum tel_event, S32 para);
static void mmi_vtcs_stop_display(void);
static void mmi_vtcs_start_display(void);
static void mmi_vtcs_stop_background_display(void);
static void mmi_vtcs_start_background_display(void);
static void mmi_vtcs_config_layer_seq(void);
static void mmi_vtcs_blt(void);
static U8   mmi_vtcs_convert_key_code_to_ascii(U16 key_code);
static void mmi_vtcs_send_message(module_type mod_src, module_type mod_dest, U8 msg_sap, const U16 msg_id, void *local_p, void *peer_p);
static void mmi_vtcs_send_uii(void);
static void mmi_vtcs_dtmf_key_up(void);
static void mmi_vtcs_dtmf_key_down(void);
static void mmi_vtcs_entry_call_scr_internal(void);
static void mmi_vtcs_exit_call_scr(void);
static U8   mmi_vtcs_delete_call_scr_history(void *ptr);
#if defined(__MMI_SUBLCD__)
static void mmi_vtcs_entry_sublcd_scr(void);
static void mmi_vtcs_exit_sublcd_scr(void);
#endif /* defined(__MMI_SUBLCD__) */

#if defined(__MMI_TOUCH_SCREEN__)
static BOOL mmi_vtcs_touch_scr_hit_test(S32 pos_x, S32 pos_y, mmi_vtcs_touch_struct *touch_obj_ptr);
static void mmi_vtcs_touch_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vtcs_touch_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vtcs_touch_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

#ifdef MMI_VTCS_UT_DEBUG
static void mmi_vtcs_ut_9_press(void);
static void mmi_vtcs_ut_8_press(void);
static void mmi_vtcs_ut_pound_press(void);
static void mmi_vtcs_ut_toggle_mode(void);
static void mmi_vtcs_ut_enter_mode(mmi_vtcs_display_mode_enum mode);
static void mmi_vtcs_ut_exit_mode(void);
#endif /* MMI_VTCS_UT_DEBUG */



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_allocate_resource
 * DESCRIPTION
 *  Allocate resource for UI display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_allocate_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (3) Status Layer                 => from GDI memory pool 
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     *
     * Others
     * (*) Snapshot Layer               => from GDI memory pool
     */

    /* Status */
    gdi_layer_create(
        g_mmi_vtcs_skin_cntx.status_rect.offset_x,
        g_mmi_vtcs_skin_cntx.status_rect.offset_y,    
        g_mmi_vtcs_skin_cntx.status_rect.width,    
        g_mmi_vtcs_skin_cntx.status_rect.height,          
        &g_mmi_vtcs_cntx.status_layer_handle);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.status_layer_handle);
    /* TODO: get theme color ? */
    
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();

    /* Skin Layer, double buffer */
    g_mmi_vtcs_cntx.skin_layer_buf_ptr = mmi_frm_scrmem_alloc(MMI_VTCS_SKIN_BUF_SIZE);
    MMI_ASSERT(g_mmi_vtcs_cntx.skin_layer_buf_ptr != NULL);
    
    gdi_layer_create_double_using_outside_memory(
        g_mmi_vtcs_skin_cntx.title_rect.offset_x, 
        g_mmi_vtcs_skin_cntx.title_rect.offset_y,         
        UI_device_width,
        UI_device_height - MMI_STATUS_BAR_HEIGHT,
        &g_mmi_vtcs_cntx.skin_layer_handle,
        g_mmi_vtcs_cntx.skin_layer_buf_ptr,
        MMI_VTCS_SKIN_BUF_SIZE);

    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    /* Sub Window */
    gdi_layer_create(
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x,
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y,    
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.width,    
        g_mmi_vtcs_skin_cntx.sub_wnd_rect.height,          
        &g_mmi_vtcs_cntx.sub_wnd_layer_handle);

    /* Main Window */
    gdi_layer_create(
        g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x,
        g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y,    
        g_mmi_vtcs_skin_cntx.main_wnd_rect.width,    
        g_mmi_vtcs_skin_cntx.main_wnd_rect.height,          
        &g_mmi_vtcs_cntx.main_wnd_layer_handle);


    /* Encode Layer */
    g_mmi_vtcs_cntx.encode_layer_buf_ptr = mmi_frm_scrmem_alloc(MMI_VTCS_ENCODE_BUF_SIZE);
    MMI_ASSERT(g_mmi_vtcs_cntx.encode_layer_buf_ptr != NULL);  

    gdi_layer_create_using_outside_memory(
        0, 
        0,         
        MMI_VTCS_ENCODE_BUF_WIDTH,
        MMI_VTCS_ENCODE_BUF_HEIGHT,
        &g_mmi_vtcs_cntx.encode_layer_handle,
        g_mmi_vtcs_cntx.encode_layer_buf_ptr,
        MMI_VTCS_ENCODE_BUF_SIZE);


    /* Snapshot Layer */
    gdi_image_get_dimension_id(IMG_ID_VT_SNAPSHOTING, &image_width, &image_height);
    offset_x = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x;
    offset_x += ((g_mmi_vtcs_skin_cntx.main_wnd_rect.width - image_width) >> 1);

    offset_y = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y;
    offset_y += ((g_mmi_vtcs_skin_cntx.main_wnd_rect.height - image_height) >> 1);

    gdi_layer_create(
        offset_x,
        offset_y,    
        image_width,    
        image_height,          
        &g_mmi_vtcs_cntx.snapshot_layer_handle);
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.snapshot_layer_handle);
    gdi_image_draw_id(0, 0, IMG_ID_VT_SNAPSHOTING);
    gdi_layer_pop_and_restore_active();

    /* config layer sequence */
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
    {
        /* hide sub layer */
        gdi_layer_set_blt_layer(
            g_mmi_vtcs_cntx.main_wnd_layer_handle,  /* 0 */
            0,                                      /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,      /* 2 */
            g_mmi_vtcs_cntx.status_layer_handle);   /* 3 */
    }
    else
    {
        /* set layer config */
        gdi_layer_set_blt_layer(
            g_mmi_vtcs_cntx.main_wnd_layer_handle, /* 0 */
            g_mmi_vtcs_cntx.sub_wnd_layer_handle,  /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,     /* 2 */
            g_mmi_vtcs_cntx.status_layer_handle);  /* 3 */
    }
    

    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_free_resource
 * DESCRIPTION
 *  Free resource 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (3) Status Layer                 => from GDI memory pool 
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     */
     
    /* Status Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.status_layer_handle);
    g_mmi_vtcs_cntx.status_layer_handle = GDI_NULL_HANDLE;

    /* Skin Layer, double buffer */
    gdi_layer_free(g_mmi_vtcs_cntx.skin_layer_handle);
    g_mmi_vtcs_cntx.skin_layer_handle = GDI_NULL_HANDLE;
        
    mmi_frm_scrmem_free(g_mmi_vtcs_cntx.skin_layer_buf_ptr);
    g_mmi_vtcs_cntx.skin_layer_buf_ptr = NULL;  

    /* Main Window Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.main_wnd_layer_handle);
    g_mmi_vtcs_cntx.main_wnd_layer_handle = GDI_NULL_HANDLE;

    /* Sub Window Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.sub_wnd_layer_handle);
    g_mmi_vtcs_cntx.sub_wnd_layer_handle = GDI_NULL_HANDLE;

    /* Encode Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.encode_layer_handle);
    g_mmi_vtcs_cntx.encode_layer_handle = GDI_NULL_HANDLE;
        
    mmi_frm_scrmem_free(g_mmi_vtcs_cntx.encode_layer_buf_ptr);
    g_mmi_vtcs_cntx.encode_layer_buf_ptr = NULL;  

    /* Snapshot Layer */
    gdi_layer_free(g_mmi_vtcs_cntx.snapshot_layer_handle);
    g_mmi_vtcs_cntx.snapshot_layer_handle = GDI_NULL_HANDLE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_config_mode
 * DESCRIPTION
 *  Config mode 
 * PARAMETERS
 *  mode        [IN]        display mode
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_config_display_mode(mmi_vtcs_display_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    /*         
     *             Main Window      Sub Window      Note
     * ----------------------------------------------------------------------------
     * MODE 1      Peer Video       Local Video     Encode video to peer
     * MODE 2      Local Video      Peer Video      Encode video to peer
     * MODE 3      Peer Video       Local Image     Encode image to peer
     * MODE 4      Local Image      Peer Video      Encode image to peer 
     * MODE 5      Peer Video       Local Hide      Encode black image to peer, no open sub hole 
     * MODE 6      Peer Image       Local Video     Preview only
     * MODE 7      Local Video      Peer Image      Preview only
     * MODE 8      Peer Image       Local Hide      Will not call driver
     * MODE 9      Local Image      Peer Hide       Will not call driver
     *
     */    
    g_mmi_vtcs_cntx.mode = mode;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_toggle_time_panel_display
 * DESCRIPTION
 *  Toggle time panel display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_toggle_time_panel_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 unit_ptr;
    PS8 cost_ptr;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_DUR)
    {
        if(mmi_vt_get_call_cost_status(unit_ptr, cost_ptr))
        {
            g_mmi_vtcs_cntx.time_panel_disp_state = MMI_VTCS_TIME_PANEL_DISP_COST;
        }
    }
    else if (g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_COST)
    {
        g_mmi_vtcs_cntx.time_panel_disp_state = MMI_VTCS_TIME_PANEL_DISP_DUR;
    }
    else
    {
        /* BOTH shall not tirgger this timer */
        MMI_ASSERT(0);
    }

    gui_start_timer(MMI_VTCS_TOGGLE_TIME_PANEL_DISP_DUR, mmi_vtcs_toggle_time_panel_display);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_update_call_status_cyclic
 * DESCRIPTION
 *  Update call time handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_update_call_status_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_call_dur;
    S32 uint_len;
    S32 cost_len;    
    PS8 unit_ptr;
    PS8 cost_ptr;
    MMI_BOOL need_update = MMI_FALSE;
    
    applib_time_struct cur_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_COST ||
        g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_BOTH)
    {
        if (mmi_vt_get_call_cost_status(unit_ptr, cost_ptr))
        {
            memset(g_mmi_vtcs_cntx.call_cost_str, 0, MMI_VTCS_COST_BUF_SIZE);
            uint_len = mmi_ucs2strlen(unit_ptr);
            MMI_ASSERT(uint_len < MMI_VTCS_COST_LEN-1);
            
            mmi_ucs2cpy(g_mmi_vtcs_cntx.call_cost_str, unit_ptr);
            mmi_ucs2ncat(g_mmi_vtcs_cntx.call_cost_str, cost_ptr, MMI_VTCS_COST_LEN - uint_len - 1);

            need_update = MMI_TRUE;
        }
    }

    if (g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_DUR ||
        g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_BOTH)
    {
        prev_call_dur = g_mmi_vtcs_cntx.call_dur;
        applib_dt_get_rtc_time(&cur_time);

        g_mmi_vtcs_cntx.call_cur_time = applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE);
        g_mmi_vtcs_cntx.call_dur = g_mmi_vtcs_cntx.call_cur_time - g_mmi_vtcs_cntx.call_start_time;

        if (prev_call_dur != g_mmi_vtcs_cntx.call_dur)
        {
            need_update = MMI_TRUE;
        }
    }

    if (need_update)
    {
        mmi_vtcs_draw_time_panel();
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();      
    }

    gui_start_timer(MMI_VTCS_UPDATE_TIME_DUR, mmi_vtcs_update_call_status_cyclic);    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_init_state
 * DESCRIPTION
 *  Init state 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_mode_init;
    PS8 title_ptr;
    applib_time_struct start_time;
    applib_time_struct cur_time;
    
    mmi_vt_incall_pic_status_enum incall_pic_type;
    PS8 incall_pic_name_ptr;
    U16 incall_pic_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VT_FEATURE_TOUCH__
    /* Touch position configuration */

    /* 
     * Touch screen panel icons 
     * [SNAP]   [EV]   [ZOOM]  [CAMERA] [MIC] [SPEAKER]
     *     1      2       3       4       5       6
     */

    g_mmi_vtcs_cntx.touch_snapshot.offset_x = g_mmi_vtcs_skin_cntx.icon_1_pos.offset_x;
    g_mmi_vtcs_cntx.touch_snapshot.offset_y = g_mmi_vtcs_skin_cntx.icon_1_pos.offset_y;

    g_mmi_vtcs_cntx.touch_ev.offset_x = g_mmi_vtcs_skin_cntx.icon_2_pos.offset_x;
    g_mmi_vtcs_cntx.touch_ev.offset_y = g_mmi_vtcs_skin_cntx.icon_2_pos.offset_y;

    g_mmi_vtcs_cntx.touch_zoom.offset_x = g_mmi_vtcs_skin_cntx.icon_3_pos.offset_x;
    g_mmi_vtcs_cntx.touch_zoom.offset_y = g_mmi_vtcs_skin_cntx.icon_3_pos.offset_y;

    g_mmi_vtcs_cntx.touch_camera.offset_x = g_mmi_vtcs_skin_cntx.icon_4_pos.offset_x;
    g_mmi_vtcs_cntx.touch_camera.offset_y = g_mmi_vtcs_skin_cntx.icon_4_pos.offset_y;

    g_mmi_vtcs_cntx.touch_mic.offset_x = g_mmi_vtcs_skin_cntx.icon_5_pos.offset_x;
    g_mmi_vtcs_cntx.touch_mic.offset_y = g_mmi_vtcs_skin_cntx.icon_5_pos.offset_y;

    g_mmi_vtcs_cntx.touch_speaker.offset_x = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_x;
    g_mmi_vtcs_cntx.touch_speaker.offset_y = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_y;
#else /* __MMI_VT_FEATURE_TOUCH__ */
    /* 
     * Non-Touch sreen panel icons 
     * [SNAP] [CAMERA] [MIC] [SPEAKER]
     *    3       4      5       6
     */

    g_mmi_vtcs_cntx.touch_snapshot.offset_x = g_mmi_vtcs_skin_cntx.icon_3_pos.offset_x;
    g_mmi_vtcs_cntx.touch_snapshot.offset_y = g_mmi_vtcs_skin_cntx.icon_3_pos.offset_y;

    g_mmi_vtcs_cntx.touch_camera.offset_x = g_mmi_vtcs_skin_cntx.icon_4_pos.offset_x;
    g_mmi_vtcs_cntx.touch_camera.offset_y = g_mmi_vtcs_skin_cntx.icon_4_pos.offset_y;

    g_mmi_vtcs_cntx.touch_mic.offset_x = g_mmi_vtcs_skin_cntx.icon_5_pos.offset_x;
    g_mmi_vtcs_cntx.touch_mic.offset_y = g_mmi_vtcs_skin_cntx.icon_5_pos.offset_y;

    g_mmi_vtcs_cntx.touch_speaker.offset_x = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_x;
    g_mmi_vtcs_cntx.touch_speaker.offset_y = g_mmi_vtcs_skin_cntx.icon_6_pos.offset_y;

#endif /* __MMI_VT_FEATURE_TOUCH__ */

    g_mmi_vtcs_cntx.touch_inc.offset_x = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x;
    g_mmi_vtcs_cntx.touch_inc.offset_y = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_y;

    g_mmi_vtcs_cntx.touch_dec.offset_x = g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_x;
    g_mmi_vtcs_cntx.touch_dec.offset_y = g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_y;

    /* note: lsk, rsk touch region will be assigned while drawing the text */

    /* init when in ut state */
    if (g_mmi_vtcs_cntx.is_ut)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_ON;
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_ON;
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;  
        g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_OFF;
        g_mmi_vtcs_cntx.ev_state = MMI_VT_EV_0;
        g_mmi_vtcs_cntx.enc_quality_state = MMI_VT_VIDEO_QUALITY_NORMAL;
        g_mmi_vtcs_cntx.enc_size_state = MMI_VT_ENC_SIZE_QCIF;    
        g_mmi_vtcs_cntx.vol_state = MMI_VT_VOL_3;
        g_mmi_vtcs_cntx.ctrl_panel_state = MMI_VTCS_CTRL_PANEL_STATE_ICON;

        memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
        mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"Hello", MMI_VTCS_TITLE_LEN);
        mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_1);
        g_mmi_vtcs_cntx.time_panel_disp_state = MMI_VTCS_TIME_PANEL_DISP_DUR;         
        g_mmi_vtcs_cntx.call_dur = 500;
        g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_DEFAULT_ID;   
        return;
    }
    
    /* camera */
    if (mmi_vt_get_camera_status())
    {
    #ifdef __MMI_VT_TWO_CAMERA__
        if (mmi_vt_get_backend_camera_status())
        {
            g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_BACK;
        }
        else
        {
            g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_FRONT;            
        }
    #else /* __MMI_VT_TWO_CAMERA__ */
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_ON;
    #endif /* __MMI_VT_TWO_CAMERA__ */
    }
    else
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_OFF;        
    }

    /* camera mirror */
    if (mmi_vt_get_mirror_status())
    {
        g_mmi_vtcs_cntx.cam_rotate_state = MMI_VT_CAM_ROTATE_0_MIRROR;
    }
    else
    {
        g_mmi_vtcs_cntx.cam_rotate_state = MMI_VT_CAM_ROTATE_0;
    }

    /* mic */
    if (mmi_vt_get_mic_status())
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_ON;
    }
    else
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_OFF;
    }
    
    /* speaker */
    if (mmi_vt_get_speaker_status())
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;  
    }
    else
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_OFF;  
    }
    
    /* aud record */
    /* TODO: need interface to get status */
    g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_OFF;

    /* ev */
    g_mmi_vtcs_cntx.ev_state = mmi_vt_get_ev_status();

    /* enc quality */
    switch (mmi_vt_get_video_quality_status())
    {
        /* VT MMI only has 3 steps of quality, SMOOTH, NORMAL, SHARP */
        /* BUT, Driver, Media, VT Task has 4 steps, FINE, HIGH, NORMAL, LOW */
       
        case MMI_VT_VIDEO_QUALITY_SMOOTH:
            g_mmi_vtcs_cntx.enc_quality_state = MMI_VT_ENC_QUALITY_LOW;
            break;
            
        case MMI_VT_VIDEO_QUALITY_NORMAL:
            g_mmi_vtcs_cntx.enc_quality_state = MMI_VT_ENC_QUALITY_NORMAL;
            break;
            
        case MMI_VT_VIDEO_QUALITY_SHARP:
            g_mmi_vtcs_cntx.enc_quality_state = MMI_VT_ENC_QUALITY_FINE;
            break;

        default:
            MMI_ASSERT(0);
    }

    /* video size - default QCIF */
    g_mmi_vtcs_cntx.enc_size_state = MMI_VT_ENC_SIZE_QCIF;    

    /* volume */
    g_mmi_vtcs_cntx.vol_state = mmi_vt_get_volume_status();

    /* ctrl panel statsu */
    g_mmi_vtcs_cntx.ctrl_panel_state = MMI_VTCS_CTRL_PANEL_STATE_ICON;

    /* title */
    memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
    
    title_ptr = (PS8)mmi_vt_get_remote_display_name();
    
    if (title_ptr != NULL && (mmi_ucs2strlen(title_ptr) > 0))
    {
        mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)title_ptr, MMI_VTCS_TITLE_LEN);        
    }

    /* out-going image */
    incall_pic_type = mmi_vt_get_incall_pic(&incall_pic_id, &incall_pic_name_ptr);

    if (incall_pic_type == MMI_VT_INCALL_PIC_STATUS_BUILT_IN)
    {
        g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_DEFAULT_ID;   
    }
    else if(incall_pic_type == MMI_VT_INCALL_PIC_STATUS_FILE)
    {
        g_mmi_vtcs_cntx.local_img_state = MMI_VTCS_LOCAL_IMG_USER_FILE;   
        memset(g_mmi_vtcs_cntx.user_img_file_path, 0, FMGR_PATH_BUFFER_SIZE);
        mmi_ucs2ncpy(g_mmi_vtcs_cntx.user_img_file_path, incall_pic_name_ptr, FMGR_PATH_CHAR_COUNT);
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* call cost */
    g_mmi_vtcs_cntx.time_panel_disp_state = MMI_VTCS_TIME_PANEL_DISP_DUR;         

    /* init mode */
    is_mode_init = MMI_FALSE;
    switch (mmi_vt_get_incall_screen_mode())
    {
        case MMI_VT_INCALL_SCREEN_MODE_INCALL:

            /* Mode 1 */
            if (mmi_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_vt_get_pic_switch_status() == MMI_FALSE &&      /* peer on main */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_1);
                is_mode_init = MMI_TRUE;
            }

            /* Mode 2 */
            if (mmi_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_vt_get_pic_switch_status() == MMI_TRUE &&       /* peer on sub */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_2);
                is_mode_init = MMI_TRUE;
            }

            /* Mode 3 */
            if (mmi_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_vt_get_pic_switch_status() == MMI_FALSE &&      /* peer on main */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_3);
                is_mode_init = MMI_TRUE;
            }

            /* Mode 4 */
            if (mmi_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_vt_get_pic_switch_status() == MMI_TRUE &&       /* peer on sub */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_4);
                is_mode_init = MMI_TRUE;
            }      

            /* Mode 5 */
            if (mmi_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_vt_get_pic_switch_status() == MMI_FALSE &&      /* peer on main */
                mmi_vt_get_hide_small_pic_status() == MMI_TRUE)     /* hide sub */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_5);
                is_mode_init = MMI_TRUE;
            }              

            if (mmi_vt_get_hand_free_status())
            {
                g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_FREE;
            }
            else
            {
                g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_HELD;
            }

            /* call dur */
            /* TODO: Tony change MYTIME to applib_time_struct */
            memcpy((void*)&start_time, (void*)mmi_vt_get_call_start_time(), sizeof(applib_time_struct));
            applib_dt_get_rtc_time(&cur_time);

            g_mmi_vtcs_cntx.call_start_time = applib_dt_mytime_2_utc_sec(&start_time, KAL_FALSE);
            g_mmi_vtcs_cntx.call_cur_time = applib_dt_mytime_2_utc_sec(&cur_time, KAL_FALSE);
            g_mmi_vtcs_cntx.call_dur = g_mmi_vtcs_cntx.call_cur_time - g_mmi_vtcs_cntx.call_start_time;

            gui_start_timer(MMI_VTCS_UPDATE_TIME_DUR, mmi_vtcs_update_call_status_cyclic);

        #ifdef __MMI_VTCS_FEATURE_TIME_PANEL_DUAL_LINE__
            g_mmi_vtcs_cntx.time_panel_disp_state = MMI_VTCS_TIME_PANEL_DISP_BOTH;
        #else
            /* only one line, need toggel dur/cost */
            g_mmi_vtcs_cntx.time_panel_disp_state = MMI_VTCS_TIME_PANEL_DISP_DUR;        
            gui_start_timer(MMI_VTCS_TOGGLE_TIME_PANEL_DISP_DUR, mmi_vtcs_toggle_time_panel_display);  
        #endif 

        #ifdef __MMI_BT_HP_SUPPORT__
            if (!mmi_bt_is_incall_aud_swap2bt())
            {
                mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_SCR1002_LOUDSP_H_FREE_RSK);
            }
            else
            {
               mmi_vtcs_set_softkey(0, 0);
            }
        #else /* __MMI_BT_HP_SUPPORT__ */
            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_SCR1002_LOUDSP_H_FREE_RSK);
        #endif /* __MMI_BT_HP_SUPPORT__ */
        
            /* not within any mode */
            MMI_ASSERT(is_mode_init)
            break;

        case MMI_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY:

            /* Mode 6 */
            if (mmi_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_vt_get_pic_switch_status() == MMI_FALSE &&      /* peer on main */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_6);
                is_mode_init = MMI_TRUE;
            }   

            /* Mode 7 */
            if (mmi_vt_get_camera_status() == MMI_TRUE &&           /* camera on */
                mmi_vt_get_pic_switch_status() == MMI_TRUE &&       /* peer on sub */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_7);
                is_mode_init = MMI_TRUE;
            }   

            /* Mode 8 */
            if (mmi_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_vt_get_pic_switch_status() == MMI_FALSE &&      /* peer on main */
                mmi_vt_get_hide_small_pic_status() == MMI_TRUE)     /* hide sub */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_8);
                is_mode_init = MMI_TRUE;
            } 

            /* Mode 9 */
            if (mmi_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_vt_get_pic_switch_status() == MMI_TRUE &&       /* peer on sub */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_9);
                is_mode_init = MMI_TRUE;
            } 

            /* Mode 10 */
            if (mmi_vt_get_camera_status() == MMI_FALSE &&          /* camera off */
                mmi_vt_get_pic_switch_status() == MMI_FALSE &&       /* peer on sub */
                mmi_vt_get_hide_small_pic_status() == MMI_FALSE)    /* sub not hide */
            {
                mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_10);
                is_mode_init = MMI_TRUE;
            } 

            g_mmi_vtcs_cntx.call_start_time = 0;
            g_mmi_vtcs_cntx.call_cur_time = 0;
            g_mmi_vtcs_cntx.call_dur = 0;

            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK);
            
            /* not within any mode */
            MMI_ASSERT(is_mode_init)
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
    }


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_register_key_event
 * DESCRIPTION
 *  Register key event  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_register_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Basic icons */
    SetKeyHandler(mmi_vtcs_camera_key_press, MMI_VTCS_CAMERA_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_camera_key_release, MMI_VTCS_CAMERA_KEY, KEY_EVENT_UP);
    g_mmi_vtcs_cntx.touch_camera.is_usable = MMI_TRUE;    

    SetKeyHandler(mmi_vtcs_mic_key_press, MMI_VTCS_MIC_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_mic_key_release, MMI_VTCS_MIC_KEY, KEY_EVENT_UP);
    g_mmi_vtcs_cntx.touch_mic.is_usable = MMI_TRUE;    

    SetKeyHandler(mmi_vtcs_speaker_key_press, MMI_VTCS_SPEAKER_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_speaker_key_release, MMI_VTCS_SPEAKER_KEY, KEY_EVENT_UP);
    g_mmi_vtcs_cntx.touch_speaker.is_usable = MMI_TRUE;    

    SetKeyHandler(mmi_vtcs_aud_rec_key_press, MMI_VTCS_AUD_REC_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_aud_rec_key_release, MMI_VTCS_AUD_REC_KEY, KEY_EVENT_UP);
    g_mmi_vtcs_cntx.touch_aud_rec.is_usable = MMI_TRUE;   

    /* snapshot */
    SetKeyHandler(mmi_vtcs_snapshot_key_press, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_snapshot_key_release, KEY_CAMERA, KEY_EVENT_UP);  
    g_mmi_vtcs_cntx.touch_snapshot.is_usable = MMI_TRUE;   


    /* EV, Zoom, Vol */
    /* disable inc/dec/scroll touch */
    g_mmi_vtcs_cntx.touch_inc.is_usable = MMI_FALSE;
    g_mmi_vtcs_cntx.touch_dec.is_usable = MMI_FALSE;     
    g_mmi_vtcs_cntx.touch_slider.is_usable = MMI_FALSE;       

#ifdef __MMI_VT_FEATURE_TOUCH__
    /* if has touch screen, show ev, zoom icon, for user to click to active scroll bar */
    g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_TRUE;         
    g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_TRUE;   
#else /* __MMI_VT_FEATURE_TOUCH__ */
    g_mmi_vtcs_cntx.touch_ev.is_usable = MMI_FALSE;         
    g_mmi_vtcs_cntx.touch_zoom.is_usable = MMI_FALSE; 
#endif /* __MMI_VT_FEATURE_TOUCH__ */

    SetKeyHandler(mmi_vtcs_ev_inc_key_press, MMI_VTCS_EV_INC_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_ev_inc_key_release, MMI_VTCS_EV_INC_KEY, KEY_EVENT_UP);
    SetKeyHandler(mmi_vtcs_ev_dec_key_press, MMI_VTCS_EV_DEC_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_ev_dec_key_release, MMI_VTCS_EV_DEC_KEY, KEY_EVENT_UP);    
    
    SetKeyHandler(mmi_vtcs_zoom_in_key_press, MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_zoom_in_key_release, MMI_VTCS_ZOOM_IN_KEY, KEY_EVENT_UP);
    SetKeyHandler(mmi_vtcs_zoom_out_key_press, MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_zoom_out_key_release, MMI_VTCS_ZOOM_OUT_KEY, KEY_EVENT_UP);    

    SetKeyHandler(mmi_vtcs_vol_up_key_press, MMI_VTCS_VOL_UP_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_vol_up_key_release, MMI_VTCS_VOL_UP_KEY, KEY_EVENT_UP);
    SetKeyHandler(mmi_vtcs_vol_down_key_press, MMI_VTCS_VOL_DOWN_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_vol_down_key_release, MMI_VTCS_VOL_DOWN_KEY, KEY_EVENT_UP);    
   
    /* softkeys */
    SetKeyHandler(mmi_vtcs_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_lsk_release, KEY_LSK, KEY_EVENT_UP);    

#ifdef __MMI_BT_HP_SUPPORT__
    if (!mmi_bt_is_incall_aud_swap2bt())
    {
        /* if do not use bt, rsk will toggle hand-held / hand-free */
        SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);    
    }
#else
    SetKeyHandler(mmi_vtcs_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vtcs_rsk_release, KEY_RSK, KEY_EVENT_UP);  
#endif

    if (mmi_ucm_app_total_call(MMI_UCM_VIDEO_CALL_TYPE) > 0)
    {
        SetGroupKeyHandler(mmi_vtcs_dtmf_key_down, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_DOWN);
        SetGroupKeyHandler(mmi_vtcs_dtmf_key_up, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_UP);
    }
    else
    {
        SetGroupKeyHandler(mmi_vt_pre_entry_new_call, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_DOWN);
    }

    /* snapshot testing */
    //SetKeyHandler(mmi_vtcs_snapshot_key_press, KEY_0, KEY_EVENT_DOWN);
   // SetKeyHandler(mmi_vtcs_snapshot_key_release, KEY_0, KEY_EVENT_UP);     

    SetKeyHandler(mmi_ucm_in_call_endkey, KEY_END, KEY_EVENT_DOWN);


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_snapshot_key_press
 * DESCRIPTION
 *  Snapshot key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_snapshot_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_snapshot.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_snapshot.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_snapshot();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_snapshot_key_release
 * DESCRIPTION
 *  Snapshot key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_snapshot_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_pathname[FMGR_PATH_BUFFER_SIZE];
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    MDI_RESULT snap_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* already exit */
//  if (GetExitScrnID() != SCR_ID_VT_CALL_SCR)
//  {
//      return;
//  }

    if (!g_mmi_vtcs_cntx.touch_snapshot.is_press)
    {
        /* not pressed */
        return;
    }

    g_mmi_vtcs_cntx.touch_snapshot.is_press = KAL_FALSE;
    mmi_vtcs_draw_ctrl_panel_snapshot();
    mmi_vtcs_blt();


    memset(buf_pathname, 0, FMGR_PATH_BUFFER_SIZE);

    /* check if storage path is valid or not */
    if (mmi_camera_check_and_restore_valid_drv())
    {
        /* if drv is valid, check if the folder is crated or not */
        mmi_imgview_get_storage_file_path(buf_pathname);
        create_result = mmi_imgview_create_file_dir(buf_pathname);

        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
             DisplayPopup(
                (PU8)GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
             return;
        }
        else if (create_result == FS_DISK_FULL)
        {
             DisplayPopup(
                (PU8)GetString(FMGR_FS_DISK_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
             return;
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
             DisplayPopup(
                (PU8)GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
             return;
        }
        else 
        {
            /* no error */
        }
   
    }
    else
    {   
        /* TODO: shall popup snapshot failed? */
        /* storage not valide */
        return;
    }

    /* get file name snapshot */
    mmi_vdoply_get_next_snapshot_filename(buf_filename, buf_pathname);

    /* stop display */
    mmi_vtcs_stop_display();


    /* config layer sequence */
    gdi_layer_set_blt_layer_ext(
        g_mmi_vtcs_cntx.main_wnd_layer_handle,    /* 0 */
        g_mmi_vtcs_cntx.sub_wnd_layer_handle,     /* 1 */
        g_mmi_vtcs_cntx.skin_layer_handle,        /* 2 */
        g_mmi_vtcs_cntx.status_layer_handle,      /* 3 */
        g_mmi_vtcs_cntx.snapshot_layer_handle,    /* 4 */        
        0);                                       /* 5 */

    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* snapshot - save to file */
    snap_ret = mdi_video_ply_snapshot(g_mmi_vtcs_cntx.main_wnd_layer_handle, buf_filename);

    /* create directory failed */
    if (snap_ret == MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION)
    {
         DisplayPopup(
            (PU8)GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
         return;
    }
    else if (snap_ret == MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL)
    {
         DisplayPopup(
            (PU8)GetString(FMGR_FS_DISK_FULL_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
         return;
    }
    else if (snap_ret == MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK)
    {
         DisplayPopup(
            (PU8)GetString(FMGR_FS_DRIVE_NOT_FOUND_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
         return;
    }
    else
    {
        /* no error */
    }

    /* let snapshot icon show 200 ms */
    kal_sleep_task(50);

    /* start play again */
    mmi_vtcs_config_layer_seq();
    mmi_vtcs_blt();
    mmi_vtcs_start_display();

    /* avoid input to many key event */
    ClearKeyEvents();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_camera_key_press
 * DESCRIPTION
 *  Camera key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_camera_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_camera.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_camera.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_camera();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_camera_key_release
 * DESCRIPTION
 *  Camera key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_camera_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_turn_on;
    MMI_BOOL is_turn_off;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_camera.is_press)
    {
        /* not pressed */
        return;
    }
    
    is_turn_on = MMI_FALSE;
    
#ifdef __MMI_VT_TWO_CAMERA__

    /* Dule Camera */
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_BACK;
        is_turn_off = MMI_FALSE;
        is_turn_on = MMI_FALSE;    

        mmi_vt_set_backend_camera_status(MMI_TRUE);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_OFF;
        is_turn_off = MMI_TRUE;
        is_turn_on = MMI_FALSE;

        /* turn off */
        mmi_vt_set_camera_status(MMI_FALSE);
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_FRONT;
        is_turn_off = MMI_FALSE;
        is_turn_on = MMI_TRUE;        

        /* turn on */
        mmi_vt_set_camera_status(MMI_TRUE);
        mmi_vt_set_backend_camera_status(MMI_FALSE);
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

#else /* __MMI_VT_TWO_CAMERA__ */

    /* Single Camera */
    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_ON)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_OFF;
        is_turn_off = MMI_TRUE;
        is_turn_on = MMI_FALSE;      
        
        /* turn off */
        mmi_vt_set_camera_status(MMI_FALSE);        
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        g_mmi_vtcs_cntx.camera_state = MMI_VT_CAMERA_ON;
        is_turn_off = MMI_FALSE;
        is_turn_on = MMI_TRUE;  

        /* turn on */
        mmi_vt_set_camera_status(MMI_TRUE);        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
#endif /* __MMI_VT_TWO_CAMERA__ */


    g_mmi_vtcs_cntx.touch_camera.is_press = KAL_FALSE;
    mmi_vtcs_draw_ctrl_panel_camera();
    mmi_vtcs_blt();


    /* Mode Transition */
    mmi_vtcs_stop_display();
    mmi_vtcs_config_layer_seq();
    
    if (is_turn_on && !is_turn_off)
    {
        /* turn on */
        if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
        {
            /* sub hide -> preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_1);            
            mmi_vtcs_clean_sub_wnd();  
            mmi_vtcs_open_sub_wnd_hole();            
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
        {
            /* main image -> preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_2);      
            mmi_vtcs_clean_main_wnd();              
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
        {
            /* sub hide -> preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_6);                
            mmi_vtcs_clean_sub_wnd();  
            mmi_vtcs_open_sub_wnd_hole();      
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_9)
        {
            /* main image -> preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_7);               
            mmi_vtcs_clean_main_wnd();                 
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_10)
        {
            /* sub image -> preview */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_6);               
            mmi_vtcs_clean_main_wnd();                 
        }        
    }
    else if (is_turn_off && ! is_turn_on)
    {
        /* trun off */
        if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1)
        {
            /* sub preview -> hide */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_5);               
            mmi_vtcs_draw_body();    
            mmi_vtcs_draw_time_panel();  
            mmi_vtcs_draw_ctrl_panel(); 
            mmi_vtcs_open_main_wnd_hole();
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2)
        {
            /* main preview -> image */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_4);               
            mmi_vtcs_draw_main_wnd();
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
        {
            /* sub preivew -> image */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_10);              
        }
        else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
        {
            /* main preview -> image */
            mmi_vtcs_config_display_mode(MMI_VTCS_DISPLAY_MODE_9);               
            mmi_vtcs_draw_main_wnd();            
        }
    }
    else
    {
        /* do not change */
    }

    mmi_vtcs_config_layer_seq();
    mmi_vtcs_blt();          
   
    mmi_vtcs_start_display();
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_mic_key_press
 * DESCRIPTION
 *  MIC key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_mic_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_mic.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_mic.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_mic();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_mic_key_release
 * DESCRIPTION
 *  MIC key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_mic_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_mic.is_press)
    {
        /* not pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_ON)
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_OFF;
        mmi_vt_set_mic_status(MMI_FALSE);
    }
    else if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_OFF)
    {
        g_mmi_vtcs_cntx.mic_state = MMI_VT_MIC_ON;
        mmi_vt_set_mic_status(MMI_TRUE);        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

    
    g_mmi_vtcs_cntx.touch_mic.is_press = KAL_FALSE;
    mmi_vtcs_draw_ctrl_panel_mic();
    mmi_vtcs_blt();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_speaker_key_press
 * DESCRIPTION
 *  Speaker key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_speaker_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_speaker.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_speaker.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_speaker();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_speaker_key_release
 * DESCRIPTION
 *  Speaker key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_speaker_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_speaker.is_press)
    {
        /* not pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_ON)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_OFF;
        mmi_vt_set_speaker_status(MMI_FALSE);        
    }
    else if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
    {
        g_mmi_vtcs_cntx.speaker_state = MMI_VT_SPEAKER_ON;
        mmi_vt_set_speaker_status(MMI_TRUE);                
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
    
    g_mmi_vtcs_cntx.touch_speaker.is_press = KAL_FALSE;
    mmi_vtcs_draw_ctrl_panel_speaker();
    mmi_vtcs_blt();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_aud_rec_key_press
 * DESCRIPTION
 *  Aud rec key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_aud_rec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_aud_rec.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_aud_rec.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_aud_rec();
    mmi_vtcs_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_aud_rec_key_release
 * DESCRIPTION
 *  Aud rec key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_aud_rec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_aud_rec.is_press)
    {
        /* not pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_aud_rec.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_aud_rec();
    mmi_vtcs_blt();

    if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_ON)
    {
        g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_OFF;
    }
    else if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_OFF)
    {
        g_mmi_vtcs_cntx.aud_rec_state = MMI_VT_AUD_REC_ON;
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_key_press
 * DESCRIPTION
 *  EV key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_ev.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_ev.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_ev();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_key_release
 * DESCRIPTION
 *  EV key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_ev.is_press)
    {
        /* not pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_ev.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_ev();
    mmi_vtcs_blt();

   if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV,
            IMG_ID_VT_EV_INC, 
            IMG_ID_VT_EV_DEC,        
            g_mmi_vtcs_cntx.ev_state,  
            MMI_VT_EV_TOTAL); 

        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();     
   }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_key_press
 * DESCRIPTION
 *  Zoom key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_zoom.is_press)
    {
        /* not pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.touch_zoom.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_zoom.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_zoom();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_key_release
 * DESCRIPTION
 *  EV key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_zoom.is_press)
    {
        /* not pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_zoom.is_press = KAL_TRUE;
    mmi_vtcs_draw_ctrl_panel_zoom();
    mmi_vtcs_blt();

   if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM,
            IMG_ID_VT_ZOOM_IN, 
            IMG_ID_VT_ZOOM_OUT,        
            g_mmi_vtcs_cntx.zoom_state,  
            MMI_VT_ZOOM_TOTAL); 

        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();     
   }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_inc_cyclic
 * DESCRIPTION
 *  EV increase cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_inc_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.ev_state < MMI_VT_EV_P4)
    {
        g_mmi_vtcs_cntx.ev_state++;
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;
        
        mdi_video_tel_update_para_ev(mmi_vtcs_get_ev_factor());        
        mmi_vtcs_update_ctrl_panel_scroll_cur_value(g_mmi_vtcs_cntx.ev_state);  
        mmi_vtcs_ctrl_panel_scroll_inc_press();
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();
    }    

    gui_start_timer(200, mmi_vtcs_ev_inc_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_dec_cyclic
 * DESCRIPTION
 *  EV decrease cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_dec_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.ev_state > MMI_VT_EV_N4)
    {
        g_mmi_vtcs_cntx.ev_state--;
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;
        
        mdi_video_tel_update_para_ev(mmi_vtcs_get_ev_factor());   
        mmi_vtcs_update_ctrl_panel_scroll_cur_value(g_mmi_vtcs_cntx.ev_state);
        mmi_vtcs_ctrl_panel_scroll_dec_press();
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();   
    }

    gui_start_timer(200, mmi_vtcs_ev_dec_cyclic);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_inc_key_press
 * DESCRIPTION
 *  EV increase key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_inc_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* already pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV,
            IMG_ID_VT_EV_INC, 
            IMG_ID_VT_EV_DEC,        
            g_mmi_vtcs_cntx.ev_state,  
            MMI_VT_EV_TOTAL); 

        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_ev_inc_cyclic();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_inc_key_release
 * DESCRIPTION
 *  EV increase key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_inc_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_ctrl_panel_restore_hdlr);  
    gui_cancel_timer(mmi_vtcs_ev_inc_cyclic);

    if (!g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* not pressed */
        return;
    }
    
    mmi_vt_set_ev_status(g_mmi_vtcs_cntx.ev_state);
    
    mmi_vtcs_ctrl_panel_scroll_inc_release();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();      
    mmi_vtcs_blt();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_dec_key_press
 * DESCRIPTION
 *  EV decrease key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_dec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* already pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV,
            IMG_ID_VT_EV_INC, 
            IMG_ID_VT_EV_DEC,        
            g_mmi_vtcs_cntx.ev_state,  
            MMI_VT_EV_TOTAL); 

        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();    
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_ev_dec_cyclic();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ev_dec_key_release
 * DESCRIPTION
 *  EV decrease key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ev_dec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_ctrl_panel_restore_hdlr);  
    gui_cancel_timer(mmi_vtcs_ev_dec_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* not pressed */
        return;
    }

    mmi_vt_set_ev_status(g_mmi_vtcs_cntx.ev_state);
    
    mmi_vtcs_ctrl_panel_scroll_dec_release();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();       
    mmi_vtcs_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_in_cyclic
 * DESCRIPTION
 *  Zoom in cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_in_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.zoom_state < MMI_VT_ZOOM_40X)
    {
        g_mmi_vtcs_cntx.zoom_state++;
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;
        
        mdi_video_tel_update_para_zoom(mmi_vtcs_get_zoom_factor());
        mmi_vtcs_update_ctrl_panel_scroll_cur_value(g_mmi_vtcs_cntx.zoom_state);
        mmi_vtcs_ctrl_panel_scroll_inc_press();
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();            
    }   

    gui_start_timer(200, mmi_vtcs_zoom_in_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_out_cyclic
 * DESCRIPTION
 *  Zoom out cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_out_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.zoom_state > MMI_VT_ZOOM_10X)
    {
        g_mmi_vtcs_cntx.zoom_state--;
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;   
        
        mdi_video_tel_update_para_zoom(mmi_vtcs_get_zoom_factor());  
        mmi_vtcs_update_ctrl_panel_scroll_cur_value(g_mmi_vtcs_cntx.zoom_state); 
        mmi_vtcs_ctrl_panel_scroll_dec_press();
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();
    }   

    gui_start_timer(200, mmi_vtcs_zoom_out_cyclic);    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_in_key_press
 * DESCRIPTION
 *  Zoom in key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_in_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* already pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM,
            IMG_ID_VT_ZOOM_IN, 
            IMG_ID_VT_ZOOM_OUT,        
            g_mmi_vtcs_cntx.zoom_state,  
            MMI_VT_ZOOM_TOTAL); 

        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_zoom_in_cyclic();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_in_key_release
 * DESCRIPTION
 *  Zoom in key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_in_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_ctrl_panel_restore_hdlr);  
    gui_cancel_timer(mmi_vtcs_zoom_in_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* not pressed */
        return;
    }

    mmi_vt_set_zoom_status(g_mmi_vtcs_cntx.zoom_state);
    
    mmi_vtcs_ctrl_panel_scroll_inc_release();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();       
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_out_key_press
 * DESCRIPTION
 *  Zoom out key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_out_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* already pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM,
            IMG_ID_VT_ZOOM_IN, 
            IMG_ID_VT_ZOOM_OUT,        
            g_mmi_vtcs_cntx.zoom_state,  
            MMI_VT_ZOOM_TOTAL); 

        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_zoom_out_cyclic();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_zoom_out_key_release
 * DESCRIPTION
 *  Zoom out key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_zoom_out_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_ctrl_panel_restore_hdlr);      
    gui_cancel_timer(mmi_vtcs_zoom_out_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* not pressed */
        return;
    }

    mmi_vt_set_zoom_status(g_mmi_vtcs_cntx.zoom_state);
    
    mmi_vtcs_ctrl_panel_scroll_dec_release();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();       
    mmi_vtcs_blt();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_up_cyclic
 * DESCRIPTION
 *  Vol up cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_up_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.vol_state < MMI_VT_VOL_6)
    {
        g_mmi_vtcs_cntx.vol_state++;
        g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;               
        
        mmi_vtcs_update_ctrl_panel_scroll_cur_value(g_mmi_vtcs_cntx.vol_state);            
        mmi_vtcs_ctrl_panel_scroll_inc_press();
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();            
    }        
    
    gui_start_timer(200, mmi_vtcs_vol_up_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_down_cyclic
 * DESCRIPTION
 *  Vol down cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_down_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.vol_state > MMI_VT_VOL_0)
    {
        g_mmi_vtcs_cntx.vol_state--;
        g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;   
        
        mmi_vtcs_update_ctrl_panel_scroll_cur_value(g_mmi_vtcs_cntx.vol_state);        
        mmi_vtcs_ctrl_panel_scroll_dec_press();
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();            
    }   

    gui_start_timer(200, mmi_vtcs_vol_down_cyclic);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_up_key_press
 * DESCRIPTION
 *  Vol up key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_up_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   

    if (g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* already pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL,
            IMG_ID_VT_VOL_UP, 
            IMG_ID_VT_VOL_DOWN,        
            g_mmi_vtcs_cntx.vol_state,  
            MMI_VT_VOL_TOTAL); 
        
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();        
    }
    else
    {
        mmi_vtcs_vol_up_cyclic();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_up_key_release
 * DESCRIPTION
 *  Vol up key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_up_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_ctrl_panel_restore_hdlr);      
    gui_cancel_timer(mmi_vtcs_vol_up_cyclic);
    
    if (!g_mmi_vtcs_cntx.touch_inc.is_press)
    {
        /* not pressed */
        return;
    }

    mmi_vt_set_volume_status(g_mmi_vtcs_cntx.vol_state);
    
    mmi_vtcs_ctrl_panel_scroll_inc_release();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();       
    mmi_vtcs_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_down_key_press
 * DESCRIPTION
 *  Vol down key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_down_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   
    
     if (g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* already pressed */
        return;
    }
    
    if (g_mmi_vtcs_cntx.ctrl_panel_state != MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
    {
        mmi_vtcs_enable_ctrl_panel_scroll(
            MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL,
            IMG_ID_VT_VOL_UP, 
            IMG_ID_VT_VOL_DOWN,        
            g_mmi_vtcs_cntx.vol_state,  
            MMI_VT_VOL_TOTAL); 
        
        mmi_vtcs_draw_ctrl_panel();
        mmi_vtcs_open_sub_wnd_hole();      
        mmi_vtcs_blt();              
    }
    else
    {
        mmi_vtcs_vol_down_cyclic();
    }
            
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_vol_down_key_release
 * DESCRIPTION
 *  Vol down key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_vol_down_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(MMI_VTCS_CTRL_PANEL_RESTORE_DUR, mmi_vtcs_ctrl_panel_restore_hdlr);      
    gui_cancel_timer(mmi_vtcs_vol_down_cyclic); 
    
    if (!g_mmi_vtcs_cntx.touch_dec.is_press)
    {
        /* not pressed */
        return;
    }

    mmi_vt_set_volume_status(g_mmi_vtcs_cntx.vol_state);

    mmi_vtcs_ctrl_panel_scroll_dec_release();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();       
    mmi_vtcs_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_lsk_press
 * DESCRIPTION
 *  lsk hdlr when press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_lsk.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_lsk.is_press = MMI_TRUE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_lsk_release
 * DESCRIPTION
 *  lsk hdlr when release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_lsk.is_press)
    {
        /* not pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_lsk.is_press = MMI_FALSE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();

    mmi_vt_entry_incall_option();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_rsk_press
 * DESCRIPTION
 *  rsk hdlr when press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.touch_rsk.is_press)
    {
        /* already pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_TRUE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_rsk_release
 * DESCRIPTION
 *  rsk hdlr when release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_vtcs_cntx.touch_rsk.is_press)
    {
        /* not pressed */
        return;
    }
    
    g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_FALSE;
    mmi_vtcs_draw_softkey();
    mmi_vtcs_blt();       


    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {
        /* mode 1, 2, 3, 4, 5 are VTing state */
        if (g_mmi_vtcs_cntx.hand_state == MMI_VT_HAND_HELD)
        {
            g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_FREE;
            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_SCR1002_LOUDSP_H_HELD_RSK);
            
            mmi_vt_set_hand_free_status(MMI_TRUE);
        }
        else if (g_mmi_vtcs_cntx.hand_state == MMI_VT_HAND_FREE)
        {
            g_mmi_vtcs_cntx.hand_state = MMI_VT_HAND_HELD;
            mmi_vtcs_set_softkey(STR_GLOBAL_OPTIONS, STR_SCR1002_LOUDSP_H_FREE_RSK);            

            mmi_vt_set_hand_free_status(MMI_FALSE);
        }
        else
        {
            /* shall not enter here */
            MMI_ASSERT(0);
        }

        mmi_vtcs_draw_softkey();
        mmi_vtcs_blt();       
        return;
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_9 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_10)
    {
        g_mmi_vtcs_cntx.is_dsiable_bg_play = MMI_TRUE;        
        GoBackHistory();
        return;        
    }
    else
    {
        /* unhandle mode */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ctrl_panel_restore_hdlr
 * DESCRIPTION
 *  Restore control panel to timer state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ctrl_panel_restore_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vtcs_disable_ctrl_panel_scroll();
    mmi_vtcs_draw_ctrl_panel();
    mmi_vtcs_open_sub_wnd_hole();
    mmi_vtcs_blt();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_enable_ctrl_panel_scroll
 * DESCRIPTION
 *  Set control panel's scroll's inc, dec icon images
 * PARAMETERS
 *  state           [IN]        ctrl panel state 
 *  inc_img         [IN]        inc image id
 *  dec_img         [IN]        dec image id 
 *  cur_value       [IN]        cur_value
 *  total_value     [IN]        total_value
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_enable_ctrl_panel_scroll(
    mmi_vtcs_ctrl_panel_enum state,
    U16 inc_img, 
    U16 dec_img,
    S32 cur_value, 
    S32 total_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.touch_dec.is_usable = MMI_TRUE;
    g_mmi_vtcs_cntx.touch_inc.is_usable = MMI_TRUE;    
    g_mmi_vtcs_cntx.touch_slider.is_usable = MMI_TRUE;        
    g_mmi_vtcs_cntx.ctrl_panel_state = state;
    g_mmi_vtcs_cntx.scroll_inc_img_id = inc_img;
    g_mmi_vtcs_cntx.scroll_dec_img_id = dec_img;   
    g_mmi_vtcs_cntx.scroll_cur_value = cur_value;
    g_mmi_vtcs_cntx.scroll_total_value = total_value;     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_disable_ctrl_panel_scroll
 * DESCRIPTION
 *  Disable control panel's scroll, restore to icon state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_disable_ctrl_panel_scroll(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.ctrl_panel_state = MMI_VTCS_CTRL_PANEL_STATE_ICON;    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_update_ctrl_panel_scroll_cur_value
 * DESCRIPTION
 *  Update control panel scroll's cur value
 * PARAMETERS
 *  cur_value           [IN]        cur_value
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_update_ctrl_panel_scroll_cur_value(S32 cur_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.scroll_cur_value = cur_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ctrl_panel_scroll_inc_press
 * DESCRIPTION
 *  Scroll inc press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ctrl_panel_scroll_inc_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.touch_inc.is_press = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ctrl_panel_scroll_inc_release
 * DESCRIPTION
 *  Scroll inc release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ctrl_panel_scroll_inc_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.touch_inc.is_press = MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ctrl_panel_scroll_dec_press
 * DESCRIPTION
 *  Slider dec press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ctrl_panel_scroll_dec_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.touch_dec.is_press = MMI_TRUE;    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_ctrl_panel_scroll_dec_release
 * DESCRIPTION
 *  Scroll dec release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_ctrl_panel_scroll_dec_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.touch_dec.is_press = MMI_FALSE;     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_zoom_factor
 * DESCRIPTION
 *  get zoom factor
 * PARAMETERS
 *  void
 * RETURNS
 *  zoom factor value 
 *****************************************************************************/
static U32 mmi_vtcs_get_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(g_mmi_vtcs_cntx.zoom_state)
    {
        case MMI_VT_ZOOM_10X:
            return 10;
        case MMI_VT_ZOOM_15X:
            return 15;            
            break;
        case MMI_VT_ZOOM_20X:
            return 20;
            break;
        case MMI_VT_ZOOM_25X:
            return 25;
            break;            
        case MMI_VT_ZOOM_30X:
            return 30;
            break;
        case MMI_VT_ZOOM_35X:
            return 35;
            break;            
        case MMI_VT_ZOOM_40X:
            return 40;
            break;       
        default:
            /* wrong value */
            MMI_ASSERT(0);
            return 0;            
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_ev_factor
 * DESCRIPTION
 *  get ev factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_ev_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(g_mmi_vtcs_cntx.ev_state)
    {
        case MMI_VT_EV_N4:
            return MDI_VIDEO_EV_N4;
            break;
        case MMI_VT_EV_N3:
            return MDI_VIDEO_EV_N3;
            break;
        case MMI_VT_EV_N2:
            return MDI_VIDEO_EV_N2;
            break;
        case MMI_VT_EV_N1:
            return MDI_VIDEO_EV_N1;
            break;  
        case MMI_VT_EV_0:
            return MDI_VIDEO_EV_0;
            break;    
        case MMI_VT_EV_P1:
            return MDI_VIDEO_EV_P1;
            break;    
        case MMI_VT_EV_P2:
            return MDI_VIDEO_EV_P2;
            break;    
        case MMI_VT_EV_P3:
            return MDI_VIDEO_EV_P3;
            break;                
        case MMI_VT_EV_P4:
            return MDI_VIDEO_EV_P4;
            break; 
        default:
            /* wrong value */
            MMI_ASSERT(0);
            return 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_cam_rotate_factor
 * DESCRIPTION
 *  get camera rotate factor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_cam_rotate_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (g_mmi_vtcs_cntx.cam_rotate_state)
    {
        case MMI_VT_CAM_ROTATE_0:
            return MDI_VIDEO_PREVIEW_ROTATE_0;
            break;

        case MMI_VT_CAM_ROTATE_0_MIRROR:
            return MDI_VIDEO_PREVIEW_ROTATE_0_MIRROR;
            break;
        default:
            /* wrong value */
            MMI_ASSERT(0);
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_enc_quality_factor
 * DESCRIPTION
 *  Get encode quality
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_enc_quality_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (g_mmi_vtcs_cntx.enc_quality_state)
    {
        case MMI_VT_ENC_QUALITY_FINE:
            return MDI_VIDEO_TEL_ENC_QTY_FINE;
            break;

        case MMI_VT_ENC_QUALITY_NORMAL:
            return MDI_VIDEO_TEL_ENC_QTY_NORMAL;
            break;

        case MMI_VT_ENC_QUALITY_LOW:
            return MDI_VIDEO_TEL_ENC_QTY_LOW;
            break;

        default:
            /* wrong value */
            MMI_ASSERT(0);
            return 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_get_enc_size_factor
 * DESCRIPTION
 *  Get encode size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 mmi_vtcs_get_enc_size_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    switch (g_mmi_vtcs_cntx.enc_size_state)
    {
        case MMI_VT_ENC_SIZE_QCIF:
            return MDI_VIDEO_VIDEO_SIZE_QCIF;
            break;

        case MMI_VT_ENC_SIZE_SQCIF:
            return MDI_VIDEO_VIDEO_SIZE_SQCIF;
            break;
            
        default:
            /* wrong value */
            MMI_ASSERT(0);
            return 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_status
 * DESCRIPTION
 *  Draw statis
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.status_layer_handle);

    /* lock and unlock frame buffer, in case status blt itself */
    gdi_layer_lock_frame_buffer();
    
    wgui_status_icon_set_display_layer(g_mmi_vtcs_cntx.status_layer_handle);
    show_status_icon_bar(0);
    show_status_icons();
    
    gdi_layer_unlock_frame_buffer();
    
    gdi_layer_pop_and_restore_active();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_title
 * DESCRIPTION
 *  Draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 str_width;
    S32 str_height;
    S32 str_len;
    S32 dot_width;
    S32 dot_height;
    S32 char_width;
    S32 char_height;
    S32 str_total_width;
    S32 index;
    UI_character_type *char_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.title_rect.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.title_rect.offset_y - layer_offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_VT_TITLE_BG);


    /* draw title string */
    str_len = mmi_ucs2strlen(g_mmi_vtcs_cntx.title_buf);

    if (str_len != 0)
    {
        gui_measure_string((UI_string_type)g_mmi_vtcs_cntx.title_buf, &str_width, &str_height);

        /* if string too long, change to xxxxxx.. */
        if (str_width > g_mmi_vtcs_skin_cntx.title_rect.width)
        {

            gui_measure_string((UI_string_type) L"..", &dot_width, &dot_height);

            str_total_width = dot_width;
            char_ptr = (UI_character_type*)g_mmi_vtcs_cntx.title_buf;

            for (index = 0; index < str_len; index++)
            {
                gui_measure_character(char_ptr[index], &char_width, &char_height);

                if ((str_total_width + char_width) > g_mmi_vtcs_skin_cntx.title_rect.width)
                {
                    mmi_ucs2cpy(&g_mmi_vtcs_cntx.title_buf[(index - 1) * ENCODING_LENGTH], (PS8) L"..");
                    break;
                }
                else
                {
                    str_total_width += char_width;
                }
            }

            str_width = str_total_width;
        }

        offset_x = (g_mmi_vtcs_skin_cntx.title_rect.width - str_width) >> 1;
        offset_x += g_mmi_vtcs_skin_cntx.title_rect.offset_x;
        offset_x -= layer_offset_x;
        
        offset_y = (g_mmi_vtcs_skin_cntx.title_rect.height - str_height) >> 1;
        offset_y += g_mmi_vtcs_skin_cntx.title_rect.offset_y;
        offset_y -= layer_offset_y;


        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(MMI_VTCS_TITLE_COLOR);
        gui_print_text((UI_string_type)g_mmi_vtcs_cntx.title_buf);
    }
    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_body
 * DESCRIPTION
 *  Draw body bg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_body(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.body_rect.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.body_rect.offset_y - offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_VT_BODY_BG);
    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_time_panel
 * DESCRIPTION
 *  Draw time panel region
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_time_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 str_width;
    S32 str_height;
    S32 char_width;
    S32 char_height;    
    U16 hr;
    U16 min;
    U16 sec;
    U32 remain;
    S8  tmp_buf[20];
    S8  tmp_buf_ucs2[20];    
    S8  time_buf_ucs2[50];  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.time_panel_rect.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.time_panel_rect.offset_y - layer_offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_VT_TIME_PANEL);

    /* TODO: Both case need take care position */
    if (g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_COST ||
        g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_BOTH)
    {
        gui_measure_string((UI_string_type)g_mmi_vtcs_cntx.call_cost_str, &str_width, &str_height);
        gui_measure_character((UI_character_type)'0', &char_width, &char_height);
        
        offset_y =  (g_mmi_vtcs_skin_cntx.time_panel_rect.height - char_width) >> 1;
        offset_y += g_mmi_vtcs_skin_cntx.time_panel_rect.offset_y;
        offset_y -= layer_offset_y;

        offset_x = 
            g_mmi_vtcs_skin_cntx.time_panel_rect.offset_x + 
            g_mmi_vtcs_skin_cntx.time_panel_rect.width - 
            1; /* right margin */

        offset_x -= str_width;
        offset_x -= 2; /* keep 2 space from right margin */
        offset_x -= layer_offset_x; /* move to layer's corrdinate */
         
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(MMI_VTCS_TIME_COLOR);
        gui_print_text((UI_string_type)g_mmi_vtcs_cntx.call_cost_str);
    }


    if (g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_DUR ||
        g_mmi_vtcs_cntx.time_panel_disp_state == MMI_VTCS_TIME_PANEL_DISP_BOTH)
    {
        memset(time_buf_ucs2, 0, sizeof(time_buf_ucs2));
        
        /* hr */
        hr = g_mmi_vtcs_cntx.call_dur / (60 * 60);
        remain = g_mmi_vtcs_cntx.call_dur % (60 * 60);
        
        sprintf(tmp_buf, "%02d", hr);
        mmi_asc_to_ucs2(tmp_buf_ucs2, tmp_buf);
        mmi_ucs2cat(time_buf_ucs2, tmp_buf_ucs2);    
        mmi_ucs2cat(time_buf_ucs2, (PS8)L":");

        /* min */
        min = remain / 60 ;
        sec = remain % 60;
        
        sprintf(tmp_buf, "%02d", min);
        mmi_asc_to_ucs2(tmp_buf_ucs2, tmp_buf);     
        mmi_ucs2cat(time_buf_ucs2, tmp_buf_ucs2);         
        mmi_ucs2cat(time_buf_ucs2, (PS8)L":");   

        /* sec */
        sprintf(tmp_buf, "%02d", sec);
        mmi_asc_to_ucs2(tmp_buf_ucs2, tmp_buf); 
        mmi_ucs2cat(time_buf_ucs2, tmp_buf_ucs2);

        gui_measure_string((UI_string_type)time_buf_ucs2, &str_width, &str_height);
        gui_measure_character((UI_character_type)'0', &char_width, &char_height);
        
        offset_y =  (g_mmi_vtcs_skin_cntx.time_panel_rect.height - char_width) >> 1;
        offset_y += g_mmi_vtcs_skin_cntx.time_panel_rect.offset_y;
        offset_y -= layer_offset_y;

        offset_x = 
            g_mmi_vtcs_skin_cntx.time_panel_rect.offset_x + 
            g_mmi_vtcs_skin_cntx.time_panel_rect.width - 
            1; /* right margin */

        offset_x -= str_width;
        offset_x -= 2; /* keep 2 space from right margin */
        offset_x -= layer_offset_x; /* move to layer's corrdinate */
         
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(MMI_VTCS_TIME_COLOR);
        gui_print_text((UI_string_type)time_buf_ucs2);
    }

   
    gdi_layer_pop_and_restore_active();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel
 * DESCRIPTION
 *  Draw icon panel region
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 img_id;
    S32 bar_width;
    S32 bar_height;
    S32 slider_width;
    S32 slider_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    /* draw panel */
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.ctrl_panel_rect.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.ctrl_panel_rect.offset_y - layer_offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_VT_CTRL_PANEL);

    if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_ICON)
    {
        /* draw icons */
        mmi_vtcs_draw_ctrl_panel_camera();
        mmi_vtcs_draw_ctrl_panel_mic();    
        mmi_vtcs_draw_ctrl_panel_speaker();
        mmi_vtcs_draw_ctrl_panel_aud_rec();
        mmi_vtcs_draw_ctrl_panel_snapshot();        
        mmi_vtcs_draw_ctrl_panel_ev();
        mmi_vtcs_draw_ctrl_panel_zoom();
    }
    else if ((g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV) ||
             (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM) ||
             (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL))
    {
        /* ctrl icon */
        offset_x = g_mmi_vtcs_skin_cntx.ctrl_icon_pos.offset_x - layer_offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.ctrl_icon_pos.offset_y - layer_offset_y;   

        switch (g_mmi_vtcs_cntx.ctrl_panel_state)
        {
            case MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV:
                img_id = IMG_ID_VT_SCROLL_EV;
                break;
            case MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM:
                img_id = IMG_ID_VT_SCROLL_ZOOM;                
                break;
            case MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL:
                img_id = IMG_ID_VT_SCROLL_VOL;                
                break;
            default:
                ASSERT(0);
        }

        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            img_id);
        
        /* inc icon */
        offset_x = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_x - layer_offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.inc_icon_pos.offset_y - layer_offset_y;               

        img_id = g_mmi_vtcs_cntx.scroll_inc_img_id;       
        
        if (g_mmi_vtcs_cntx.touch_inc.is_press)
        {
            img_id++;
        }

        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            img_id);

        /* dec icon */
        offset_x = g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_x - layer_offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.dec_icon_pos.offset_y - layer_offset_y;               

        img_id = g_mmi_vtcs_cntx.scroll_dec_img_id;       
        
        if (g_mmi_vtcs_cntx.touch_dec.is_press)
        {
            img_id++;
        }

        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            img_id);

        /* bar */
        offset_x = g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_x - layer_offset_x;
        offset_y = g_mmi_vtcs_skin_cntx.scroll_bar_pos.offset_y - layer_offset_y;               
        img_id = IMG_ID_VT_SCROLL_BAR;
        
        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            img_id);

        /* slider */
        gdi_image_get_dimension_id(IMG_ID_VT_SCROLL_BAR, &bar_width, &bar_height);
        gdi_image_get_dimension_id(IMG_ID_VT_SCROLL_SLIDER, &slider_width, &slider_height);          

        bar_width -= slider_width;
        slider_height -= bar_height;
        slider_height >>= 1;

        /* shift from bar's position */
        offset_y -=  slider_height;   
        offset_x += g_mmi_vtcs_cntx.scroll_cur_value * bar_width / (g_mmi_vtcs_cntx.scroll_total_value-1);
        
        gdi_image_draw_id(
            offset_x, 
            offset_y, 
            IMG_ID_VT_SCROLL_SLIDER); 
        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }
   
    gdi_layer_pop_and_restore_active();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_panel_camera
 * DESCRIPTION
 *  Draw camera icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_camera.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_camera.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_OFF)
    {
        image_id = IMG_ID_VT_CAMERA_OFF;
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_ON)
    {
        image_id = IMG_ID_VT_CAMERA_ON; 
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_FRONT)
    {
        image_id = IMG_ID_VT_CAMERA_FRONT; 
    }
    else if (g_mmi_vtcs_cntx.camera_state == MMI_VT_CAMERA_BACK)
    {
        image_id = IMG_ID_VT_CAMERA_BACK; 
    }
    else
    {
        MMI_ASSERT(0);
    }
   

    if (g_mmi_vtcs_cntx.touch_camera.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_camera.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_panel_mic
 * DESCRIPTION
 *  Draw mic icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_mic.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_mic.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_OFF)
    {
        image_id = IMG_ID_VT_MIC_OFF;
    }
    else if (g_mmi_vtcs_cntx.mic_state == MMI_VT_MIC_ON)
    {
        image_id = IMG_ID_VT_MIC_ON; 
    }

    if (g_mmi_vtcs_cntx.touch_mic.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_mic.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel_speaker
 * DESCRIPTION
 *  Draw speaker icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_speaker.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_speaker.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_OFF)
    {
        image_id = IMG_ID_VT_SPEAKER_OFF;
    }
    else if (g_mmi_vtcs_cntx.speaker_state == MMI_VT_SPEAKER_ON)
    {
        image_id = IMG_ID_VT_SPEAKER_ON; 
    }    
    
    if (g_mmi_vtcs_cntx.touch_speaker.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_speaker.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel_aud_rec
 * DESCRIPTION
 *  Draw aud_rec icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_aud_rec(void)
{
#ifdef __MMI_VT_FEATURE_AUD_REC__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_aud_rec.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_aud_rec.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_OFF)
    {
        image_id = IMG_ID_VT_AUD_REC_OFF;
    }
    else if (g_mmi_vtcs_cntx.aud_rec_state == MMI_VT_AUD_REC_ON)
    {
        image_id = IMG_ID_VT_AUD_REC_ON; 
    }

    if (g_mmi_vtcs_cntx.touch_aud_rec.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_aud_rec.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);    

    gdi_layer_pop_and_restore_active();    
    
#endif /*  __MMI_VT_FEATURE_AUD_REC__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel_snapshot
 * DESCRIPTION
 *  Draw snapshot icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_snapshot.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_snapshot.offset_y - layer_offset_y;   
    image_id = IMG_ID_VT_SNAPSHOT;
 
    if (g_mmi_vtcs_cntx.touch_snapshot.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_snapshot.is_press)
        {
            /* _PRESS image */
            image_id += 1;
        }
    }
    else
    {
        /* _DISABLE image */
        image_id += 2;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);    

    gdi_layer_pop_and_restore_active();    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel_ev
 * DESCRIPTION
 *  Draw ev icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_ev(void)
{
#ifdef __MMI_VT_FEATURE_TOUCH__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_ev.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_ev.offset_y - layer_offset_y;   

    if (g_mmi_vtcs_cntx.touch_ev.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_ev.is_press)
        {
            image_id = IMG_ID_VT_EV_PRESS;
        }
        else
        {
            image_id = IMG_ID_VT_EV;
        }
    }
    else
    {
        image_id = IMG_ID_VT_EV_DISABLE;
    }
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
#endif /* __MMI_VT_FEATURE_TOUCH__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_ctrl_panel_zoom
 * DESCRIPTION
 *  Draw zoom icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_ctrl_panel_zoom(void)
{
#ifdef __MMI_VT_FEATURE_TOUCH__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    
    offset_x = g_mmi_vtcs_cntx.touch_zoom.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_cntx.touch_zoom.offset_y - layer_offset_y;   
    
    if (g_mmi_vtcs_cntx.touch_zoom.is_usable)
    {
        if (g_mmi_vtcs_cntx.touch_zoom.is_press)
        {
            image_id = IMG_ID_VT_ZOOM_PRESS;
        }
        else
        {
            image_id = IMG_ID_VT_ZOOM;
        }
    }
    else
    {
        image_id = IMG_ID_VT_ZOOM_DISABLE;
    }

    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        image_id);

    gdi_layer_pop_and_restore_active();    
#endif /* __MMI_VT_FEATURE_TOUCH__ */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_set_softkey
 * DESCRIPTION
 *  Set softkey string id
 * PARAMETERS
 *  lsk_id      [IN]         lsk_string_id
 *  rsk_id      [IN]         rsk_string_id 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_set_softkey(U16 lsk_id, U16 rsk_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.lsk_str_id = lsk_id;
    g_mmi_vtcs_cntx.rsk_str_id = rsk_id;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_softkey
 * DESCRIPTION
 *  Draw softkey region
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;    
    S32 str_width;
    S32 str_height;
    S32 lsk_offset_x;
    S32 lsk_offset_y;    
    S32 rsk_offset_x;
    S32 rsk_offset_y;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_reset_clip();
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.softkey_rect.offset_x - layer_offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.softkey_rect.offset_y - layer_offset_y;    
    
    gdi_image_draw_id(
        offset_x, 
        offset_y, 
        IMG_ID_VT_SOFTKEY_BG);


    /* draw softkey string */
    /* LSK */
    if (g_mmi_vtcs_cntx.lsk_str_id != 0)
    {
        gui_measure_string(get_string(g_mmi_vtcs_cntx.lsk_str_id), &str_width, &str_height);

        /* mimic framwork's sk position */
        lsk_offset_x = 2;
        lsk_offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 2;

        if (g_mmi_vtcs_cntx.touch_lsk.is_press)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }

        lsk_offset_x -= layer_offset_x;
        lsk_offset_y -= layer_offset_y;  

        gui_move_text_cursor(lsk_offset_x, lsk_offset_y);
        gui_set_text_color(MMI_VTCS_SOFTKEY_COLOR);
        gui_set_text_border_color(MMI_VTCS_SOFTKEY_COLOR_BORDER);
        
        gui_print_bordered_text(get_string(g_mmi_vtcs_cntx.lsk_str_id));

        g_mmi_vtcs_cntx.touch_lsk.offset_x = lsk_offset_x;
        g_mmi_vtcs_cntx.touch_lsk.offset_y = lsk_offset_y;
        g_mmi_vtcs_cntx.touch_lsk.width = str_width;
        g_mmi_vtcs_cntx.touch_lsk.height = str_height;
        
    }


    /* RSK */
    if (g_mmi_vtcs_cntx.rsk_str_id != 0)
    {
        gui_measure_string(get_string(g_mmi_vtcs_cntx.rsk_str_id), &str_width, &str_height);
        
       /* mimic framwork's sk position */        
        rsk_offset_x = UI_device_width - str_width - 2; 
        rsk_offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 2; 
        if (g_mmi_vtcs_cntx.touch_rsk.is_press)
        {
            rsk_offset_x++;
            rsk_offset_y++;
        }

        rsk_offset_x -= layer_offset_x;
        rsk_offset_y -= layer_offset_y;        

        gui_move_text_cursor(rsk_offset_x, rsk_offset_y);
        gui_set_text_color(MMI_VTCS_SOFTKEY_COLOR);
        gui_set_text_border_color(MMI_VTCS_SOFTKEY_COLOR_BORDER);
        
        gui_print_bordered_text(get_string(g_mmi_vtcs_cntx.rsk_str_id));

        g_mmi_vtcs_cntx.touch_rsk.offset_x = rsk_offset_x;
        g_mmi_vtcs_cntx.touch_rsk.offset_y = rsk_offset_y;
        g_mmi_vtcs_cntx.touch_rsk.width = str_width;
        g_mmi_vtcs_cntx.touch_rsk.height = str_height;
        
    }
    
    gdi_layer_pop_and_restore_active();

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_main_wnd
 * DESCRIPTION
 *  Draw main window layer based on display type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_main_wnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;    
    S32 offset_x;
    S32 offset_y;
    S32 layer_width;
    S32 layer_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;    
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);
 
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {
        /* PEER MAIN (Video) */   
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_10)
    {
        /* PEER MAIN (Image) */        
        gdi_image_get_dimension_id(IMG_ID_VT_MAIN_WND_PEER, &image_width, &image_height);
        
        offset_x = (layer_width - image_width) >> 1;
        offset_y = (layer_height - image_height) >> 1;        

        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
        gdi_image_draw_id(offset_x, offset_y, IMG_ID_VT_MAIN_WND_PEER);           
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7)
    {
        /* LCOAL MAIN (Video) */   
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);        
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_9)
    {
        /* LCOAL MAIN (Image) */   
        if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            gdi_image_get_dimension_id(IMG_ID_VT_MAIN_WND_LOCAL, &image_width, &image_height);

            gdi_image_util_fit_bbox(
                layer_width,
                layer_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);     
            gdi_image_draw_resized_id(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                IMG_ID_VT_MAIN_WND_LOCAL);                 
           
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            ret = gdi_image_get_dimension_id(g_mmi_vtcs_cntx.user_img_id, &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {       
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);     
                gdi_image_draw_resized_id(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_id);          
            }
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            ret = gdi_image_get_dimension_file(g_mmi_vtcs_cntx.user_img_file_path, &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);     
                gdi_image_draw_resized_file(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_file_path);
            
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /* some mode not handled */
        MMI_ASSERT(0);
    }
   
    gdi_layer_pop_and_restore_active();

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_sub_wnd
 * DESCRIPTION
 *  Draw sub window layer based on display type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_sub_wnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;    
    S32 offset_x;
    S32 offset_y;
    S32 layer_width;
    S32 layer_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;       
    GDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_layer_handle);
    gdi_layer_get_dimension(&layer_width, &layer_height);

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {
        /* PEER SUB (Video) */
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_9)
    {
        /* PEER SUB (Image) */
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);        
        gdi_image_get_dimension_id(IMG_ID_VT_SUB_WND_PEER, &image_width, &image_height);
        
        offset_x = (layer_width - image_width) >> 1;
        offset_y = (layer_height - image_height) >> 1;        

        gdi_image_draw_id(offset_x, offset_y, IMG_ID_VT_SUB_WND_PEER);
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6)
    {
        /* LOCAL SUB (Video) */    
        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);    
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_10)
    {
        /* LOCAL SUB (Image) */        
        if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            gdi_image_get_dimension_id(IMG_ID_VT_SUB_WND_LOCAL, &image_width, &image_height);

            gdi_image_util_fit_bbox(
                layer_width,
                layer_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
            gdi_image_draw_resized_id(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                IMG_ID_VT_SUB_WND_LOCAL);  
       
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            ret = gdi_image_get_dimension_id(g_mmi_vtcs_cntx.user_img_id, &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
                gdi_image_draw_resized_id(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_id);             
            }
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            ret = gdi_image_get_dimension_file(g_mmi_vtcs_cntx.user_img_file_path, &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {
               gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
                gdi_image_draw_resized_file(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_file_path);       

            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /* some mode not handled */
        MMI_ASSERT(0);
    }

    gdi_layer_pop_and_restore_active();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_clean_main_wnd
 * DESCRIPTION
 *  Clean main window layer to Black
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_clean_main_wnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.main_wnd_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_clean_sub_wnd
 * DESCRIPTION
 *  Clean sub window layer to Black
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_clean_sub_wnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.sub_wnd_layer_handle); 
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_open_main_wnd_hole
 * DESCRIPTION
 *  Open holes on skin main window display, since these two windows 
 *  are under r the skin layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_open_main_wnd_hole(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y - offset_y;    

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + g_mmi_vtcs_skin_cntx.main_wnd_rect.width - 1,
        offset_y + g_mmi_vtcs_skin_cntx.main_wnd_rect.height - 1, 
        GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_and_restore_active();  
   
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_open_sub_wnd_hole
 * DESCRIPTION
 *  Open holes on skin sub window display, since these two windows 
 *  are under r the skin layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_open_sub_wnd_hole(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
    {
        /* will not open sub region hole in MODE 5 and MODE 8 */
        
        /*         
         *             Main Window      Sub Window      Note
         * ----------------------------------------------------------------------------
         * MODE 5      Peer Video       Local Hide      Encode black image to peer, no open sub hole   
         * MODE 8      Peer Image       Local Hide      Will not call driver         
         *
         */   
        return;
    }
    
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);

    gdi_layer_get_position(&offset_x, &offset_y);

    offset_x = g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_x - offset_x;
    offset_y = g_mmi_vtcs_skin_cntx.sub_wnd_rect.offset_y - offset_y;    

    gdi_draw_solid_rect(
        offset_x,
        offset_y,
        offset_x + g_mmi_vtcs_skin_cntx.sub_wnd_rect.width - 1,
        offset_y + g_mmi_vtcs_skin_cntx.sub_wnd_rect.height - 1, 
        GDI_COLOR_TRANSPARENT);
    
    gdi_layer_pop_and_restore_active();  
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_skin
 * DESCRIPTION
 *  Draw skin to current active skin layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_skin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vtcs_draw_status();
    mmi_vtcs_draw_title();
    mmi_vtcs_draw_body();    
    mmi_vtcs_draw_time_panel();  
    mmi_vtcs_draw_ctrl_panel(); 
    mmi_vtcs_draw_softkey();   
    mmi_vtcs_draw_main_wnd();
    mmi_vtcs_draw_sub_wnd();    
    mmi_vtcs_open_main_wnd_hole();
    mmi_vtcs_open_sub_wnd_hole();
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_draw_encode_layer
 * DESCRIPTION
 *  Draw encode layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_draw_encode_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 layer_width;
    S32 layer_height;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    GDI_RESULT ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4)
    {        
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.encode_layer_handle);        
        gdi_layer_get_dimension(&layer_width, &layer_height);

        gdi_layer_clear(MMI_VTCS_WND_BG_GDI_COLOR);
                
        if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_DEFAULT_ID)
        {
            gdi_image_get_dimension_id(IMG_ID_VT_MAIN_WND_LOCAL, &image_width, &image_height);

            gdi_image_util_fit_bbox(
                layer_width,
                layer_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            gdi_image_draw_resized_id(
                resized_offset_x, 
                resized_offset_y, 
                resized_width, 
                resized_height,
                IMG_ID_VT_MAIN_WND_LOCAL);     
        
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_ID)
        {
            ret = gdi_image_get_dimension_id(g_mmi_vtcs_cntx.user_img_id, &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {            
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_draw_resized_id(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_id);              
            }
        }
        else if (g_mmi_vtcs_cntx.local_img_state == MMI_VTCS_LOCAL_IMG_USER_FILE)
        {
            ret = gdi_image_get_dimension_file(g_mmi_vtcs_cntx.user_img_file_path, &image_width, &image_height);

            if (ret == GDI_SUCCEED && image_width != 0 && image_height != 0)
            {
                gdi_image_util_fit_bbox(
                    layer_width,
                    layer_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);

                gdi_image_draw_resized_file(
                    resized_offset_x, 
                    resized_offset_y, 
                    resized_width, 
                    resized_height,
                    g_mmi_vtcs_cntx.user_img_file_path);         
            }
        }

        gdi_layer_pop_and_restore_active();        
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {        
        gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.encode_layer_handle);         
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();            
    }
    else
    {
        /* ignore other modes */
    }
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_start_event_callback_hdlr
 * DESCRIPTION
 *  Start display event callback handler
 * PARAMETERS
 *  tel_event       [IN]        event type
 *  para            [IN]        parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_start_event_callback_hdlr(mdi_video_tel_codec_event_enum tel_event, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 vt_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(tel_event)
    {
        case MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_SIZE:
            /* in this case, para is MDI_VIDEO_VIDEO_SIZE_XXXX */

            if (para == MDI_VIDEO_VIDEO_SIZE_QCIF)
            {
                vt_para = MMI_VT_ENC_SIZE_QCIF;
            }
            else if (para == MDI_VIDEO_VIDEO_SIZE_SQCIF)
            {
                vt_para = MMI_VT_ENC_SIZE_SQCIF;
            }
            else
            {
                ASSERT(0);
            }

            if (vt_para != g_mmi_vtcs_cntx.enc_size_state)
            {
                /* size changed, need restart */
                /* TODO: maybe need reconfig preview layer size */
                g_mmi_vtcs_cntx.enc_size_state = vt_para;

                if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_1 ||
                    g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_2 ||
                    g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_3)
                {
                    /* background */
                    mmi_vtcs_stop_background_display();
                    mmi_vtcs_start_background_display();                    
                }
                else
                {
                    /* foreground */
                    mmi_vtcs_stop_display();
                    mmi_vtcs_start_display();
                }
            }
            break;

        case MDI_VIDEO_TEL_EVENT_CHANGE_ENCODE_QUALITY:

            if (para == MDI_VIDEO_TEL_ENC_QTY_FINE)
            {
                vt_para = MMI_VT_ENC_QUALITY_FINE;
            }
            else if (para == MDI_VIDEO_TEL_ENC_QTY_NORMAL)
            {
                vt_para = MMI_VT_ENC_QUALITY_NORMAL;
            }
            else if (para == MDI_VIDEO_TEL_ENC_QTY_LOW)
            {
                vt_para = MMI_VT_ENC_QUALITY_LOW;
            }                       
            else
            {
                ASSERT(0);
            }

            if (vt_para != g_mmi_vtcs_cntx.enc_quality_state)
            {
                /* size changed, need restart */
                g_mmi_vtcs_cntx.enc_quality_state = vt_para;
                
                if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_1 ||
                    g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_2 ||
                    g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_BG_3)
                {
                    /* background */
                    mmi_vtcs_stop_background_display();
                    mmi_vtcs_start_background_display();                    
                }
                else
                {
                    /* foreground */
                    mmi_vtcs_stop_display();
                    mmi_vtcs_start_display();
                }
            }
            break;

        default:
            ASSERT(0);
    
    }
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_stop_display
 * DESCRIPTION
 *  stop display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_stop_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_8 && 
        g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_9 &&
        g_mmi_vtcs_cntx.mode != MMI_VTCS_DISPLAY_MODE_10)
    {
        /* stop previous playing */        
        mdi_video_tel_stop();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_start_display
 * DESCRIPTION
 *  Start VT display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_start_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle peer_layer_handle;
    gdi_handle local_layer_handle;
    mdi_video_tel_disp_type_enum local_type;
    mdi_video_tel_disp_type_enum peer_type;    
    U32 blt_layer_flag;
    U32 peer_layer_flag;
    U32 local_layer_flag;
    mdi_video_setting_struct video_setting;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (3) Status Layer                 => from GDI memory pool 
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     */
    
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 1      Peer Video       Local Video     Encode video to peer            
             *
             */
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;            

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;   
            local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;  
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            break;

        case MMI_VTCS_DISPLAY_MODE_2:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 2      Local Video      Peer Video      Encode video to peer         
             *
             */            
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;            

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;  
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            break;

       case MMI_VTCS_DISPLAY_MODE_3:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 3      Peer Video       Local Image     Encode image to peer     
             *
             */  
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;            

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */
            local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;  /* this is used to blt sub_wnd_layer_handler */
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            break;

        case MMI_VTCS_DISPLAY_MODE_4:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 4      Local Image      Peer Video      Encode image to peer   
             *
             */                
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;            

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */
            local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;  /* this is used to blt main_wnd_layer_handler */
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            break;
            
        case MMI_VTCS_DISPLAY_MODE_5:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 5      Peer Video       Local Hide      Encode black image to peer, no open sub hole   
             *
             */    
            peer_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;            

            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.encode_layer_handle;  /* will encode this and send to pper */
            local_layer_flag = 0; /* hide layer, not blt */

            /* will not blt sub layer */
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            break;                  

        case MMI_VTCS_DISPLAY_MODE_6:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 6      Peer Image       Local Video     Preview only
             *
             */        
            peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            peer_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_0;            

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;  
            local_layer_flag = GDI_LAYER_ENABLE_LAYER_1;  
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
            break;

        case MMI_VTCS_DISPLAY_MODE_7:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 7      Local Video      Peer Image      Preview only
             *
             */              
            peer_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            peer_layer_handle = g_mmi_vtcs_cntx.sub_wnd_layer_handle;   
            peer_layer_flag = GDI_LAYER_ENABLE_LAYER_1;            

            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;  
            local_layer_flag = GDI_LAYER_ENABLE_LAYER_0;  
            
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | \
                             GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
                     
            break;
  
        case MMI_VTCS_DISPLAY_MODE_8:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 8      Peer Image       Local Hide      Will not call driver
             *
             */              
            return;           
            break;  

        case MMI_VTCS_DISPLAY_MODE_9:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 9      Local Image      Peer Image      Will not call driver
             *
             */  

        case MMI_VTCS_DISPLAY_MODE_10:
            /*         
             *             Main Window      Sub Window      Note
             * ----------------------------------------------------------------------------
             * MODE 10     Peer Image       Local Image      Will not call driver
             *
             */                
            return;           
            break;  

        default:
            MMI_ASSERT(0);

    }


    /* get default video preview settings */
    mdi_video_rec_load_default_setting(&video_setting);

    video_setting.zoom = mmi_vtcs_get_zoom_factor();
    video_setting.ev = mmi_vtcs_get_ev_factor();
    video_setting.preview_rotate = mmi_vtcs_get_cam_rotate_factor();
    video_setting.video_qty = mmi_vtcs_get_enc_quality_factor();
    video_setting.video_size = mmi_vtcs_get_enc_size_factor();
    
    mdi_video_tel_start(
        peer_layer_handle,         
        local_layer_handle,        
        peer_type,                 
        local_type,  
        blt_layer_flag,
        peer_layer_flag,
        local_layer_flag,
        &video_setting,
        mmi_vtcs_start_event_callback_hdlr);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_start_background_display
 * DESCRIPTION
 *  Start VT display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* TODO: need export ? */
static void mmi_vtcs_start_background_display(void)
{
    /* !!! TDOO: !!! */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle peer_layer_handle;
    gdi_handle local_layer_handle;
    mdi_video_tel_disp_type_enum local_type;
    mdi_video_tel_disp_type_enum peer_type;    
    U32 blt_layer_flag;
    U32 peer_layer_flag;
    U32 local_layer_flag;
    mdi_video_setting_struct video_setting;
    U32 mem_size;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Layer Configuration: 
     *
     * ========== [Up] ============
     * (3) Status Layer                 => from GDI memory pool 
     * (2) Skin Layer (dobule buffer)   => from screen memory
     * (1) Sub Wnd Layer                => from GDI memory pool
     * (0) Main Wnd Layer               => from GDI memory pool
     * ========= [Down] ============
     */

    /* Main Window */
    /* TODO: ask JF if have interface to get default color depth . currently 2 byte color depth */

    
    mem_size = g_mmi_vtcs_skin_cntx.main_wnd_rect.width * g_mmi_vtcs_skin_cntx.main_wnd_rect.height * 2;
    ret = media_get_ext_buffer(MOD_MMI, (void**)&g_mmi_vtcs_cntx.bg_mem_ptr, mem_size);

    MMI_ASSERT(ret != MED_RES_OK);

    gdi_layer_create_using_outside_memory(
        g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_x,
        g_mmi_vtcs_skin_cntx.main_wnd_rect.offset_y,    
        g_mmi_vtcs_skin_cntx.main_wnd_rect.width,    
        g_mmi_vtcs_skin_cntx.main_wnd_rect.height,       
        &g_mmi_vtcs_cntx.main_wnd_layer_handle,   
        (PU8)g_mmi_vtcs_cntx.bg_mem_ptr,
        (S32)mem_size);


    /* change mode from forground to back ground */
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
        case MMI_VTCS_DISPLAY_MODE_2:            
            g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_BG_1;
            break;

        case MMI_VTCS_DISPLAY_MODE_3:
        case MMI_VTCS_DISPLAY_MODE_4:            
            g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_BG_2;
            break;

        case MMI_VTCS_DISPLAY_MODE_5:
            g_mmi_vtcs_cntx.mode = MMI_VTCS_DISPLAY_MODE_BG_3;
            break;
    }
 
    /* TODO: mode */
    switch (g_mmi_vtcs_cntx.mode)
    {
        case MMI_VTCS_DISPLAY_MODE_BG_1:
            /*         
             * BG MODE 1: Encode video to peer         
             */

            /* hide peer */
            peer_type = MDI_VIDEO_TEL_DISPLAY_HIDE;
            peer_layer_handle = GDI_LAYER_EMPTY_HANDLE;   
            peer_layer_flag = 0;            

            /* encode local video */
            local_type = MDI_VIDEO_TEL_DISPLAY_VIDEO;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            local_layer_flag = 0;  
            
            blt_layer_flag = 0;
            break;

        case MMI_VTCS_DISPLAY_MODE_BG_2:
        case MMI_VTCS_DISPLAY_MODE_BG_3:            
            /*         
             * BG MODE 2: Encode image layer to peer         
             * BG MODE 3: Encode back layer to peer                      
             */

            /* hide peer */
            peer_type = MDI_VIDEO_TEL_DISPLAY_HIDE;
            peer_layer_handle = GDI_LAYER_EMPTY_HANDLE;   
            peer_layer_flag = 0;            

            /* encode local video */
            local_type = MDI_VIDEO_TEL_DISPLAY_IMAGE;
            local_layer_handle = g_mmi_vtcs_cntx.main_wnd_layer_handle;   
            local_layer_flag = 0;  
            
            blt_layer_flag = 0;
            break;
  
        default:
            MMI_ASSERT(0);

    }


    /* get default video preview settings */
    mdi_video_rec_load_default_setting(&video_setting);

    video_setting.zoom = mmi_vtcs_get_zoom_factor();
    video_setting.ev = mmi_vtcs_get_ev_factor();
    video_setting.preview_rotate = mmi_vtcs_get_cam_rotate_factor();
    video_setting.video_qty = mmi_vtcs_get_enc_quality_factor();
    video_setting.video_size = mmi_vtcs_get_enc_size_factor();
    
    mdi_video_tel_start(
        peer_layer_handle,         
        local_layer_handle,        
        peer_type,                 
        local_type,  
        blt_layer_flag,
        peer_layer_flag,
        local_layer_flag,
        &video_setting,
        mmi_vtcs_start_event_callback_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_stop_background_display
 * DESCRIPTION
 *  stop display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_stop_background_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previous playing */        
    mdi_video_tel_stop();

    MMI_ASSERT(g_mmi_vtcs_cntx.bg_mem_ptr != NULL);
    
    media_free_ext_buffer(MOD_MMI, (void**)&g_mmi_vtcs_cntx.bg_mem_ptr);
    gdi_layer_free(g_mmi_vtcs_cntx.main_wnd_layer_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_config_layer_seq
 * DESCRIPTION
 *  Config layer 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_config_layer_seq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* config layer sequence */
    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8)
    {
        /* hide sub layer */
        gdi_layer_set_blt_layer(
            g_mmi_vtcs_cntx.main_wnd_layer_handle, /* 0 */
            0,                                     /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,     /* 2 */
            g_mmi_vtcs_cntx.status_layer_handle);  /* 3 */
    }
    else
    {
        /* set layer config */
        gdi_layer_set_blt_layer(
            g_mmi_vtcs_cntx.main_wnd_layer_handle, /* 0 */
            g_mmi_vtcs_cntx.sub_wnd_layer_handle,  /* 1 */
            g_mmi_vtcs_cntx.skin_layer_handle,     /* 2 */
            g_mmi_vtcs_cntx.status_layer_handle);  /* 3 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_blt
 * DESCRIPTION
 *  Blt to LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    /* clone skin */
    gdi_layer_push_and_set_active(g_mmi_vtcs_cntx.skin_layer_handle);
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    gdi_layer_pop_and_restore_active();
}




/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_convert_key_code_to_ascii
 * DESCRIPTION
 *  Conver key code to ascii code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vtcs_convert_key_code_to_ascii(U16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ascii_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(key_code)
    {
        case KEY_0:
        {
            ascii_code = '0';     
        }
        break;
        
        case KEY_1:
        {
            ascii_code = '1';     
        }
        break;
        
        case KEY_2:
        {
            ascii_code = '2';     
        }
        break;

        case KEY_3:
        {
            ascii_code = '3';     
        }
        break;

        case KEY_4:
        {
            ascii_code = '4';     
        }
        break;

        case KEY_5:
        {
            ascii_code = '5';     
        }
        break;

        case KEY_6:
        {
            ascii_code = '6';     
        }
        break;

        case KEY_7:
        {
            ascii_code = '7';     
        }
        break;

        case KEY_8:
        {
            ascii_code = '8';     
        }
        break;

        case KEY_9:
        {
            ascii_code = '9';     
        }
        break;

        case KEY_STAR:
        {
            ascii_code = '*';     
        }
        break;

        case KEY_POUND:
        {
            ascii_code = '#';     
        }
        break;

        default:
        {
            ascii_code = 0;     
        }
        break;        
    }

    return ascii_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  mod_src         [IN]        Source module
 *  mod_dest        [IN]        Destination module
 *  msg_sap         [IN]        Message SAP
 *  msg_id          [IN]        Message ID
 *  local_p         [IN]        Local parameter
 *  peer_p          [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_send_message(
        module_type mod_src,
        module_type mod_dest,
        U8 msg_sap,
        const U16 msg_id,
        void *local_p,
        void *peer_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = mod_src;
    Message.oslDestId = mod_dest;
    Message.oslSapId = msg_sap;
    Message.oslMsgId = msg_id;
    Message.oslDataPtr = local_p;
    Message.oslPeerBuffPtr = peer_p;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_send_uii
 * DESCRIPTION
 *  send UII to VT task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_send_uii(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_vt_uii_struct *msg_req;
    U16 keyCode = 0, keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&keyCode, &keyType);
    
    PRINT_INFORMATION("\n[mmi_vtcs_send_uii] keyCode : %d\n", keyCode);

    msg_req = (mmi_vt_uii_struct*) construct_local_para(sizeof(mmi_vt_uii_struct), TD_CTRL | TD_RESET);

    msg_req->uiiLength = 1;
    msg_req->uiiString[0] = mmi_vtcs_convert_key_code_to_ascii(keyCode);
    
    mmi_vtcs_send_message(
        MOD_MMI,
        MOD_VT,
        0,
        MSG_ID_MMI_VT_UII,
        (oslParaType*) msg_req,
        NULL);
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_dtmf_key_down
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_dtmf_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION("\n[mmi_vtcs_dtmf_key_down] \n");

    mmi_vtcs_send_uii();
    SetGroupKeyHandler(MMI_dummy_function, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_DOWN);
    SetGroupKeyHandler(MMI_dummy_function, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_LONG_PRESS);
    SetGroupKeyHandler(MMI_dummy_function, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_REPEAT);        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_dtmf_key_up
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_dtmf_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    PRINT_INFORMATION("\n[mmi_vtcs_dtmf_key_up] \n");

    SetGroupKeyHandler(mmi_vtcs_dtmf_key_down, (U16*)mmi_vtcs_dtmf_key, MMI_VTCS_DTMF_KEY_NO - 1, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_call_scr_internal
 * DESCRIPTION
 *  Enter call screen internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_entry_call_scr_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_VT_INCALL, 
        mmi_vtcs_exit_call_scr,
        mmi_vtcs_entry_call_scr_internal,
        NULL);

#ifdef __MMI_SUBLCD__
    /* entry sublcd */
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_mmi_vtcs_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vtcs_entry_sublcd_scr);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VT_CALL_SCR);

    if (gui_buffer == NULL)
    {
        /* first time enter */        
        g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_FOREGROUND;
    }
    else
    {
        /* back from history */
        if (g_mmi_vtcs_cntx.state == MMI_VTCS_STATE_BACKGROUND)
        {
            /* back from backgroudn play, stop it */
            mmi_vtcs_stop_background_display();
        }
        
        g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_FOREGROUND;        
    }

    /* hook delete screen hdlr */
    SetDelScrnIDCallbackHandler(SCR_ID_VT_INCALL, mmi_vtcs_delete_call_scr_history);

    /* reset flag */
    g_mmi_vtcs_cntx.is_dsiable_bg_play = MMI_FALSE;   


   /*************************************************************************
    * Init proper state for video applcation                                                                   
    *************************************************************************/
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* suspend background play */
//  mdi_audio_suspend_background_play();d

    /* disalbe align timer */
    UI_disable_alignment_timers();

    /* stop LED patten */
    StopLEDPatternBackGround();

    /* stop lcd sleep in */
    TurnOnBacklight(0);

    /* use medium font */
    gui_set_font(&MMI_medium_font);


#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vtcs_touch_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vtcs_touch_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vtcs_touch_pen_move_hdlr);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

    /******************************
     * Init                                                                 
     ******************************/
    /* init state */
    mmi_vtcs_init_state();

    /* get and init resource */
    mmi_vtcs_allocate_resource();
   
    /* init key event  */
    mmi_vtcs_register_key_event();


    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {        
        /* draw image to encode layer */        
        mmi_vtcs_draw_encode_layer();    
    }

    /******************************
     * draw skin                                                                 
     ******************************/

    mmi_vtcs_draw_skin();
    mmi_vtcs_blt();

    if (mmi_is_redrawing_bk_screens())
    {
        /* redraw due to small screen */
        return;
    }

#ifdef MMI_VTCS_UT_DEBUG
    if (g_mmi_vtcs_cntx.is_ut)
    {
        SetKeyHandler(mmi_vtcs_ut_9_press, KEY_9, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ut_8_press, KEY_8, KEY_EVENT_DOWN);        
        SetKeyHandler(mmi_vtcs_ut_pound_press, KEY_POUND, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vtcs_ut_toggle_mode, KEY_STAR, KEY_EVENT_DOWN);        
        
        mmi_vtcs_ut_enter_mode(MMI_VTCS_DISPLAY_MODE_1);
        return;
    }
#endif

    /* start display */
    mmi_vtcs_start_display();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_exit_call_scr
 * DESCRIPTION
 *  Exit VT call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_exit_call_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.is_ut)
    {
        mmi_vtcs_ut_exit_mode();
    }
    else
    {
        mmi_vtcs_stop_display();
    }

    /* TODO: currently not support background display */
    g_mmi_vtcs_cntx.is_dsiable_bg_play = MMI_TRUE;

    if (!g_mmi_vtcs_cntx.is_dsiable_bg_play && 
        (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 ||
         g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 ||
         g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 ||
         g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 ||
         g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5))
    {
        /* not disable background play, we will start background play */
        g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_BACKGROUND;
        mmi_vtcs_start_background_display();
    }
    else
    {
        g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_EXIT;
        g_mmi_vtcs_cntx.is_dsiable_bg_play = MMI_FALSE;
    }

    /* stop timers */
    gui_cancel_timer(mmi_vtcs_ctrl_panel_restore_hdlr);   
    gui_cancel_timer(mmi_vtcs_update_call_status_cyclic);       
    gui_cancel_timer(mmi_vtcs_toggle_time_panel_display);       
    
    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LCD patten */
    StopLEDPatternPowerOn();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* resume background audio */
//   mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* flatten layer to base */
    gdi_layer_flatten_previous_to_base();

    /* free resource */
    mmi_vtcs_free_resource();

    /* restore status display layer */
    wgui_status_icon_reset_display_layer();

#ifdef __MMI_SUBLCD__
    /* exit sublcd */
    if (g_mmi_vtcs_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_mmi_vtcs_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_delete_call_scr_history
 * DESCRIPTION
 *  Delete call screen from history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vtcs_delete_call_scr_history(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* back from history */
    if (g_mmi_vtcs_cntx.state == MMI_VTCS_STATE_BACKGROUND)
    {
        /* back from backgroudn play, stop it */
        mmi_vtcs_stop_background_display();
        g_mmi_vtcs_cntx.state = MMI_VTCS_STATE_EXIT;
    }
    
    /* remove from histoy, disable background play */
    g_mmi_vtcs_cntx.is_dsiable_bg_play = MMI_TRUE;   
    
    DeleteScreenIfPresent(SCR_ID_VT_CALL_SCR);
}




#ifdef __MMI_SUBLCD__
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_sublcd_scr
 * DESCRIPTION
 *  Enter sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_entry_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_vtcs_exit_sublcd_scr);

    /* draw sub as black */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    g_mmi_vtcs_cntx.is_sub_display = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_exit_sublcd_scr
 * DESCRIPTION
 *  Exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_exit_sublcd_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_vtcs_cntx.is_sub_display)
    {
        g_mmi_vtcs_cntx.is_sub_display = FALSE;

        SubLCDHistory.entryFuncPtr = mmi_vtcs_entry_sublcd_scr;
        AddSubLCDHistory(&SubLCDHistory);
    }
}
#endif /* __MMI_SUBLCD__ */ 


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_hit_test
 * DESCRIPTION
 *  Test if is within touch region
 * PARAMETERS
 *  pos_x                   [IN]        Position x
 *  pos_y                   [IN]        Position y
 *  touch_obj_ptr           [IN]        Touch object structure
 * RETURNS
 *  BOOL
 *****************************************************************************/
static BOOL mmi_vtcs_touch_hit_test(S32 pos_x, S32 pos_y, mmi_vtcs_touch_struct *touch_obj_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!touch_obj_ptr->is_usable)
    {
        return FALSE;
    }
    
    if ((pos_x >= touch_obj_ptr->offset_x) &&
        (pos_x < touch_obj_ptr->offset_x + touch_obj_ptr->width) &&
        (pos_y >= touch_obj_ptr->offset_y) && (pos_y < touch_obj_ptr->offset_y + touch_obj_ptr->height))
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
 *  mmi_vtcs_touch_pen_down_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_touch_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* lsk */
    if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_lsk))
    {
        mmi_vtcs_lsk_press();
        g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_LSK;
        return;
    }

    /* rsk */
    if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_rsk))
    {
        mmi_vtcs_rsk_press();
        g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_RSK;
        return;
    }

    /* panel */
    if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_ICON)
    {
        /* camera */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_camera))
        {
            mmi_vtcs_camera_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_CAMERA;
            return;
        }
        
        /* mic */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_mic))
        {
            mmi_vtcs_mic_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_MIC;
            return;
        }

        /* speaker */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_speaker))
        {
            mmi_vtcs_speaker_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_SPEAKER;
            return;
        }

        /* aud rec */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_aud_rec))
        {
            mmi_vtcs_aud_rec_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_AUD_REC;
            return;
        }

        /* ev */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_ev))
        {
            mmi_vtcs_ev_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_EV;
            return;
        }

        /* zoom */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_zoom))
        {
            mmi_vtcs_zoom_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_ZOOM;
            return;
        }

        /* snapshot */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_snapshot))
        {
            mmi_vtcs_snapshot_key_press();
            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_SNAPSHOT;
            return;
        }
    }
    else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV ||
             g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM ||
             g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
    {
        /* inc */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_inc))
        {        
            if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_inc_key_press();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_in_key_press();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_up_key_press();
            }
            else
            {
                MMI_ASSERT(0);
            }

            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_INC;
            return;
            
        }

        /* dec */
        if (mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_dec))
        {        
            if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_dec_key_press();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_out_key_press();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_down_key_press();
            }
            else
            {
                MMI_ASSERT(0);
            }

            g_mmi_vtcs_cntx.touch_object = MMI_VTCS_TOUCH_DEC;
            return;
        }

        /* TODO: SILDER */
        
    }
    else
    {
        /* shall not enter here */
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_pen_up_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_touch_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_vtcs_cntx.touch_object)
    {
        case MMI_VTCS_TOUCH_NONE:
            /* do nothing */
            break;

        case MMI_VTCS_TOUCH_EV:
            mmi_vtcs_ev_key_release();
            break;

        case MMI_VTCS_TOUCH_ZOOM:
            mmi_vtcs_zoom_key_release();
            break;

        case MMI_VTCS_TOUCH_CAMERA:
            mmi_vtcs_camera_key_release();
            break;

        case MMI_VTCS_TOUCH_MIC:
            mmi_vtcs_mic_key_release();
            break;

        case MMI_VTCS_TOUCH_SPEAKER:
            mmi_vtcs_speaker_key_release();
            break;

        case MMI_VTCS_TOUCH_AUD_REC:
            mmi_vtcs_aud_rec_key_release();
            break;

       case MMI_VTCS_TOUCH_SNAPSHOT:
            mmi_vtcs_snapshot_key_release();
            break;

       case MMI_VTCS_TOUCH_LSK:
            mmi_vtcs_lsk_release();
            break;

       case MMI_VTCS_TOUCH_RSK:
            mmi_vtcs_rsk_release();
            break;

       case MMI_VTCS_TOUCH_INC:
            if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_inc_key_release();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_in_key_release();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_up_key_release();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_ICON)
            {
                /* shall not enter here */
                MMI_ASSERT(0);
            }
            else
            {
                /* shall not enter here */                
                MMI_ASSERT(0);
            }
            break;

       case MMI_VTCS_TOUCH_DEC:
            if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
            {
                mmi_vtcs_ev_dec_key_release();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
            {
                mmi_vtcs_zoom_out_key_release();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
            {
                mmi_vtcs_vol_down_key_release();
            }
            else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_ICON)
            {
                /* shall not enter here */
                MMI_ASSERT(0);
            }
            else
            {
                /* shall not enter here */                
                MMI_ASSERT(0);
            }   
            break;

        /* TODO: SLIDER */
    
        default:
            /* unhandled case */
            MMI_ASSERT(0);
            break;

    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_touch_pen_move_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vtcs_touch_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (g_mmi_vtcs_cntx.touch_object)
    {
        case MMI_VTCS_TOUCH_NONE:
            /* do nothing */
            break;

        case MMI_VTCS_TOUCH_EV:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_ev))
            {
                g_mmi_vtcs_cntx.touch_ev.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_ev();
                mmi_vtcs_blt();
            }            
            break;

        case MMI_VTCS_TOUCH_ZOOM:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_zoom))
            {
                g_mmi_vtcs_cntx.touch_zoom.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_zoom();
                mmi_vtcs_blt();
            }     
            break;

        case MMI_VTCS_TOUCH_CAMERA:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_camera))
            {
                g_mmi_vtcs_cntx.touch_camera.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_camera();
                mmi_vtcs_blt();
            }                 
            break;

        case MMI_VTCS_TOUCH_MIC:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_mic))
            {
                g_mmi_vtcs_cntx.touch_mic.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_mic();
                mmi_vtcs_blt();
            }                 
            break;

        case MMI_VTCS_TOUCH_SPEAKER:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_speaker))
            {
                g_mmi_vtcs_cntx.touch_speaker.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_speaker();
                mmi_vtcs_blt();
            }      
            break;

        case MMI_VTCS_TOUCH_AUD_REC:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_aud_rec))
            {
                g_mmi_vtcs_cntx.touch_aud_rec.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_aud_rec();
                mmi_vtcs_blt();
            }      
            break;

       case MMI_VTCS_TOUCH_SNAPSHOT:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_snapshot))
            {
                g_mmi_vtcs_cntx.touch_aud_rec.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_ctrl_panel_aud_rec();
                mmi_vtcs_blt();
            }   
            break;

       case MMI_VTCS_TOUCH_LSK:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_rsk))
            {
                g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();
            }   
            break;

       case MMI_VTCS_TOUCH_RSK:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_rsk))
            {
                g_mmi_vtcs_cntx.touch_rsk.is_press = MMI_FALSE;
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;                
                mmi_vtcs_draw_softkey();
                mmi_vtcs_blt();
            }  
            break;

       case MMI_VTCS_TOUCH_INC:
            if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_inc))
            {
                if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
                {
                    gui_cancel_timer(mmi_vtcs_ev_inc_cyclic); 
                }
                else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
                { 
                    gui_cancel_timer(mmi_vtcs_zoom_in_cyclic); 
                }
                else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
                {   
                    gui_cancel_timer(mmi_vtcs_vol_up_cyclic);                     
                }
                else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_ICON)
                {
                    /* shall not enter here */
                    MMI_ASSERT(0);
                }
                else
                {
                    /* shall not enter here */                
                    MMI_ASSERT(0);
                }   
                
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;     
                mmi_vtcs_ctrl_panel_scroll_inc_release();
                mmi_vtcs_draw_ctrl_panel();
                mmi_vtcs_open_sub_wnd_hole();       
                mmi_vtcs_blt();

            }
            break;

       case MMI_VTCS_TOUCH_DEC:
           if (!mmi_vtcs_touch_hit_test(pos.x, pos.y, &g_mmi_vtcs_cntx.touch_dec))
            {
                if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_EV)
                {
                    gui_cancel_timer(mmi_vtcs_ev_dec_cyclic); 
                }
                else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_ZOOM)
                { 
                    gui_cancel_timer(mmi_vtcs_zoom_out_cyclic); 
                }
                else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_SCROLL_VOL)
                {   
                    gui_cancel_timer(mmi_vtcs_vol_down_cyclic);                     
                }
                else if (g_mmi_vtcs_cntx.ctrl_panel_state == MMI_VTCS_CTRL_PANEL_STATE_ICON)
                {
                    /* shall not enter here */
                    MMI_ASSERT(0);
                }
                else
                {
                    /* shall not enter here */                
                    MMI_ASSERT(0);
                }   
                
                g_mmi_vtcs_cntx.touch_object = VDOPLY_TOUCH_NONE;     
                mmi_vtcs_ctrl_panel_scroll_dec_release();
                mmi_vtcs_draw_ctrl_panel();
                mmi_vtcs_open_sub_wnd_hole();       
                mmi_vtcs_blt();

            }
            break;

        default:
            /* unhandled case */
            MMI_ASSERT(0);
            break;

    }

//    case VDOPLY_TOUCH_VOLUME_INC:
//        if (!mmi_vdoply_touch_scr_hit_test(pos.x, pos.y, &g_vdoply_cntx.full_touch_volume_inc))
//        {
//            g_vdoply_cntx.full_touch_volume_inc.is_press = FALSE;
//
//            mmi_vdoply_draw_fullscr_osd();
//            mmi_vdoply_blt_screen();
//            g_vdoply_cntx.touch_object = VDOPLY_TOUCH_NONE;
//        }
//        break;
    
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_call_scr
 * DESCRIPTION
 *  Enter call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_entry_call_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.is_ut = MMI_FALSE;
    mmi_vtcs_entry_call_scr_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vtcs_entry_call_scr_for_ut
 * DESCRIPTION
 *  Enter call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vtcs_entry_call_scr_for_ut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_vtcs_cntx.is_ut = MMI_TRUE;
    mmi_vtcs_entry_call_scr_internal();
}



#ifdef MMI_VTCS_UT_DEBUG
/* UT related code */
void vt_qty_test(kal_uint32 q);
static U16 vt_q = 0;
static void mmi_vtcs_ut_9_press(void)
{
//    vt_qty_test(vt_q);
    vt_q++;

    if (vt_q > 3)
    {
        vt_q = 0;
    }
}

void vt_size_test(kal_uint32 s);
static U16 vt_s = 0;
static void mmi_vtcs_ut_8_press(void)
{
//    vt_qty_test(vt_s);
    vt_s++;

    if (vt_s > 1)
    {
        vt_s = 0;
    }
}




static void mmi_vtcs_ut_pound_press(void)
{
    DisplayPopup(
        (PU8)GetString(STR_GLOBAL_OK),
        IMG_GLOBAL_WARNING,
        1,
        ST_NOTIFYDURATION,
        WARNING_TONE);
}

static void mmi_vtcs_ut_toggle_mode(void)
{
    mmi_vtcs_display_mode_enum mode;

    mode = g_mmi_vtcs_cntx.mode;
    if (mode < MMI_VTCS_DISPLAY_MODE_TOTAL - 1)
    {
        mode++;
    }
    else
    {
        mode = MMI_VTCS_DISPLAY_MODE_1;
    }

    mmi_vtcs_ut_exit_mode();
    g_mmi_vtcs_cntx.mode = mode;
    mmi_vtcs_ut_enter_mode(g_mmi_vtcs_cntx.mode);
}


static void mmi_vtcs_ut_enter_mode(mmi_vtcs_display_mode_enum mode)
{
    switch (mode)
    {
        case MMI_VTCS_DISPLAY_MODE_1:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 1", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;

        case MMI_VTCS_DISPLAY_MODE_2:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 2", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;        

        case MMI_VTCS_DISPLAY_MODE_3:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 3", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;        

        case MMI_VTCS_DISPLAY_MODE_4:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 4", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;         

        case MMI_VTCS_DISPLAY_MODE_5:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 5", MMI_VTCS_TITLE_LEN);
            mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_3G324M);
            mdi_audio_speech_codec_start();           
            mdi_video_tel_enable_vt_loopback(); 
            break;     

        case MMI_VTCS_DISPLAY_MODE_6:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 6", MMI_VTCS_TITLE_LEN);
            break;            

        case MMI_VTCS_DISPLAY_MODE_7:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 7", MMI_VTCS_TITLE_LEN);
            break;   

        case MMI_VTCS_DISPLAY_MODE_8:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 8", MMI_VTCS_TITLE_LEN);
            break;       

        case MMI_VTCS_DISPLAY_MODE_9:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 9", MMI_VTCS_TITLE_LEN);
            break;     

        case MMI_VTCS_DISPLAY_MODE_10:
            memset(g_mmi_vtcs_cntx.title_buf, 0, MMI_VTCS_TITLE_BUF_SIZE);
            mmi_ucs2ncpy((void*)g_mmi_vtcs_cntx.title_buf, (void*)L"MODE 10", MMI_VTCS_TITLE_LEN);
            break;     
            
        default:
            MMI_ASSERT(0);
    }

    mmi_vtcs_config_display_mode(mode);        
    mmi_vtcs_draw_skin();
    mmi_vtcs_draw_encode_layer();
    mmi_vtcs_config_layer_seq();
    mmi_vtcs_blt();
    
    mmi_vtcs_start_display();
    
}

static void mmi_vtcs_ut_exit_mode(void)
{
    mmi_vtcs_stop_display();

    if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_1 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_2 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_3 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_4 || 
        g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_5)
    {
        mdi_audio_speech_codec_stop(); 
        mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_3G324M);
        mdi_video_tel_disable_vt_loopback();         
    }
    else if (g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_6 || 
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_7 || 
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_8 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_9 ||
             g_mmi_vtcs_cntx.mode == MMI_VTCS_DISPLAY_MODE_10)
    {
        /* do nothing */
    }
    else
    {
        MMI_ASSERT(0);
    }

}

#endif /* MMI_VTCS_UT_DEBUG */

#endif /* __MMI_VIDEO_TELEPHONY__ */ 

