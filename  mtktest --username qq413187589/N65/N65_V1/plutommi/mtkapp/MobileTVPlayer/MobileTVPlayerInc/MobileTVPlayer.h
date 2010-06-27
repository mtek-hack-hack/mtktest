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
 *  MobileTVPlayer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Mobile TV Player Applications v0.1
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _MMI_MOBILE_TV_PLAYER_DATATPYE_H_
#define _MMI_MOBILE_TV_PLAYER_DATATPYE_H_

#include "mmi_features.h"
#include "MobileTVPlayerGProt.h"

#ifdef __MMI_MOBILE_TV_PLAYER__

#define MMI_MTV_MAX_SERVICES 20
#define MMI_MTV_SERVICES_NAME_LENGTH 128
#define MMI_MTV_JUMP_TO_CHANNEL_DELAY 2000

/***************************************
* Hint Box
***************************************/
#define MMI_MOBILE_TV_PLAYER_HINT_POPUP_FADE_TIME          (1200)

#define MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_TIME       (3*1000) /* 3 sec */
#define MMI_MOBILE_TV_PLAYER_OSD_FADE_OUT_VALUE      (32)     /* fade 32/256 */

/***************************************
* Mobile TV Setting Structure
***************************************/
#define MMI_MOBILE_TV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT     (11)       /* -5, -4, ...0 , +4, +5 */
#define MMI_MOBILE_TV_PLAYER_CONTRAST_ADJ_LEVEL_COUNT      (11)       /* -5, -4, ...0 , +4, +5 */
typedef struct
{
    /* strings for inline selection display */
    /* +1 avoid this feature's item is zero */
    UI_string_type brightness_str[MMI_MOBILE_TV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT + 1];
    UI_string_type contrast_str[MMI_MOBILE_TV_PLAYER_BRIGHTNESS_ADJ_LEVEL_COUNT + 1];
    UI_string_type band_str[MMI_MOBILE_TV_PLAYER_BAND_TOTAL_COUNT];

    /* selected item */
    S32 brightness_selected;
    S32 contrast_selected;
    S32 storage_selected;
}mtv_player_menu_context_struct;

typedef enum
{
    MTV_PLAYER_PLAY_SPEED_10X = 0,
    MTV_PLAYER_PLAY_SPEED_20X,
    MTV_PLAYER_PLAY_SPEED_5X,

    MTV_PLAYER_PLAY_SPEED_TOTAL_COUNT
} mtv_player_setting_play_speed_enum;



/***************************************
* Mobile TV Setting Structure
***************************************/
#define MMI_MTV_PLAYER_STORAGE_FILEPATH            FMGR_DEFAULT_FOLDER_VIDEO
typedef enum
{
    MTV_PLAYER_SETTING_BRIGHTNESS = 0,
    MTV_PLAYER_SETTING_CONTRAST,

    MTV_PLAYER_SETTING_ITEM_COUNT
} mtv_player_setting_count_enum;

typedef enum
{
    MTV_PLAYER_STORAGE_NEED_TO_MOUNT = 0,
    MTV_PLAYER_STORAGE_MOUNTED,
    MTV_PLAYER_STORAGE_NOT_AVAILABLE,

    MTV_PLAYER_STORAGE_TOTAL_COUNT
}mtv_player_storage_status_enum;

typedef enum
{
    MTV_PLAYER_SCROLLING_TEXT_OFF = 0,
    MTV_PLAYER_SCROLLING_TEXT_ON,
    MTV_PLAYER_SCROLLING_TEXT_SCROLLING,

    MTV_PLAYER_SCROLLING_TEXT_TOTAL_COUNT
}mtv_player_scrolling_text_state_enum;

/***************************************
* Icon Structure
***************************************/
typedef enum
{
    MTV_PLAYER_VOL_1 = LEVEL1,
    MTV_PLAYER_VOL_2,
    MTV_PLAYER_VOL_3,
    MTV_PLAYER_VOL_4,
    MTV_PLAYER_VOL_5,
    MTV_PLAYER_VOL_6,
    MTV_PLAYER_VOL_7,
    MTV_PLAYER_VOL_8,
    MTV_PLAYER_VOL_9,
    MTV_PLAYER_VOL_10,
    MTV_PLAYER_VOL_11,
    MTV_PLAYER_VOL_12,
    MTV_PLAYER_VOL_13,    
    MTV_PLAYER_VOL_14,
    MTV_PLAYER_VOL_15,
    MTV_PLAYER_VOL_16,
    MTV_PLAYER_VOL_MUTE
} mtv_player_aud_vol_enum;

typedef enum
{
    MTV_PLAYER_ICON_STATUS_ENABLE = 0,
    MTV_PLAYER_ICON_STATUS_DISABLE = 0x0001,
    MTV_PLAYER_ICON_STATUS_CLICKED = 0x0010
} mtv_player_icon_status_enum;

typedef enum
{
    MTV_PLAYER_TOUCH_NONE = 0,
    MTV_PLAYER_TOUCH_PLAY,
    MTV_PLAYER_TOUCH_RECORD,
    MTV_PLAYER_TOUCH_PLAY_SPEED,
    MTV_PLAYER_TOUCH_FULLSCREEN,
    MTV_PLAYER_TOUCH_FORWARD,
    MTV_PLAYER_TOUCH_REWIND,
    MTV_PLAYER_TOUCH_VOL_INC,
    MTV_PLAYER_TOUCH_VOL_DEC,
    MTV_PLAYER_TOUCH_CHANNEL_NEXT,
    MTV_PLAYER_TOUCH_CHANNEL_PREV,
    MTV_PLAYER_TOUCH_TS_BAR,

    MTV_PLAYER_TOUCH_LSK,
    MTV_PLAYER_TOUCH_RSK
} mtv_player_touch_icon_enum;

typedef struct
{
	BOOL is_show;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    mtv_player_icon_status_enum status;
} mtv_player_osd_icon_struct;

typedef struct 
{
	U8		r;
	U8		g;	
	U8		b;		
	U8		style_r;
	U8		style_g;	
	U8		style_b;
	U16	    style;	
} mtv_player_style_text_struct;

typedef struct
{
	BOOL	is_show;
	S32 	offset_x;
	S32 	offset_y;
	S32	    width;
	S32 	height;

} mtv_player_osd_text_struct;

typedef struct 
{
    mtv_player_osd_text_struct title;

    mtv_player_osd_text_struct hint_box;

    mtv_player_osd_icon_struct channel_number;
    mtv_player_osd_icon_struct volume;
    /* top section */
    mtv_player_osd_icon_struct play;
    mtv_player_osd_icon_struct record;
    mtv_player_osd_icon_struct play_speed;
    mtv_player_osd_icon_struct fullscreen;
    mtv_player_osd_icon_struct forward;
    mtv_player_osd_icon_struct rewind;
    mtv_player_osd_icon_struct vol_inc;
    mtv_player_osd_icon_struct vol_dec;
    mtv_player_osd_icon_struct channel_next;
    mtv_player_osd_icon_struct channel_prev;

    mtv_player_osd_icon_struct ts_ind;
    mtv_player_osd_icon_struct ts_bar;

} mtv_player_layout_struct;

typedef struct
{
    U32 max_timeshift_delay;
    U32 max_timeshift_bf_size;

    U16 storage;
    U16 brightness;
    U16 contrast;
    U16 play_speed;
    U16 band;

    U8  vol_level;
    U8  selected_channel;
    U8  max_channel_number;

    mdi_mtv_service_info_struct services[MMI_MTV_MAX_SERVICES];
    U16 num_services;

    pBOOL is_channel_list_init;
    pBOOL is_channel_seleted;
} mtv_player_setting_struct;



typedef struct
{
    mtv_player_storage_status_enum storage_status;
    PS8 storage_filepath;

    mmi_frm_screen_rotate_enum ui_rotate;

    U32 mtv_handle;
    
    void *app_mem_pool;
    KAL_ADM_ID adm_pool_id;

    /* preview layer */
    gdi_handle preview_layer_handle;
#ifdef __MTK_TARGET__
    PU8 preview_layer_buf_ptr;
#else
    U8 preview_layer_buf_ptr[MMI_MTV_PLAYER_PREVIEW_BUFFER_SIZE];
#endif

    /* osd layer */
    gdi_handle osd_layer_handle;
    PU8 osd_layer_buf_ptr;
    S32 osd_layer_width;
    S32 osd_layer_height;

    /* dls layer */
    gdi_handle dls_layer_handle;
    PU8 dls_layer_buf_ptr;

    /* process layer */
    gdi_handle process_layer_handle;
    


    PS8 hint1_buf;
    PS8 hint2_buf;
    U16 fade_time;
    pBOOL is_show_hint;

    mmi_mtv_player_kernel_state_enum kernel_prev_state;
    mmi_mtv_player_kernel_state_enum kernel_state;
    mmi_mtv_player_kernel_state_enum kernel_next_state;

    mmi_mtv_player_player_state_enum player_prev_state;
    mmi_mtv_player_player_state_enum player_state;
    mmi_mtv_player_player_state_enum player_next_state;
    
    mmi_mtv_player_recorder_state_enum recorder_prev_state;
    mmi_mtv_player_recorder_state_enum recorder_state;
    mmi_mtv_player_recorder_state_enum recorder_next_state;

    S8 service_names[MMI_MTV_MAX_SERVICES][MMI_MTV_SERVICES_NAME_LENGTH];
        
    MDI_RESULT last_error;
    
    mtv_player_layout_struct *active_osd_cntx_p;
    mtv_player_touch_icon_enum touch_object;
    mtv_player_osd_icon_struct rsk;
    mtv_player_osd_icon_struct lsk;

    mtv_player_setting_struct setting;

    /* scrolling label */
    scrolling_text              scrolling_label;
    mtv_player_scrolling_text_state_enum scrolling_label_state;
    S8                          label_str[256];

    /* used in channel list */
    U8 selected_channel; 
    U8 backup_channel;
    

    U32 play_delay;
    U32 max_delay;
    U32 max_timeshift_delay;

    S32 selected_band;
    
    U32 signal_strength;

    U16 fullscr_osd_opacity ;

    pBOOL is_live_scanning;
    pBOOL is_live_scan_complete;
    pBOOL is_updating_channel_list;
    pBOOL is_key_pressed;
    pBOOL is_ts_bar_enable;
    pBOOL is_setting_loaded;
    pBOOL is_saving;
    pBOOL is_discarding_file;
    pBOOL is_initializing;
    pBOOL is_bt_connecting;
    pBOOL is_recorder_error;


    pBOOL is_before_cat265;
    pBOOL is_channel_changed;
    pBOOL is_changing_channel_by_key;
    U16   change_to_channel;

    gdi_handle anim_handle;
    gdi_handle bt_connect_amin_handle;

#ifdef __MMI_TOUCH_SCREEN__
    S32                         pen_down_x;
    S32                         pen_down_y;
    pBOOL                       is_pen_down;
    S32                         movement_x;
    S32                         movement_y;
#endif


}mmi_mtv_player_context_struct;

/****************************************************************************
* MACRO
*****************************************************************************/
/****************************************************************************
* Define
*****************************************************************************/
static void mmi_mtv_player_pre_highlight_handler(void);
static void mmi_mtv_player_redraw_preview(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height);
static S32 mmi_mtv_player_cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item);
static void mmi_mtv_player_reset_all_state(void);
static void mmi_mtv_player_entry_option_menu_screen(void);
static void mmi_mtv_player_highlight_channel_hdlr(S32 index);
static void mmi_mtv_player_entry_cl_option_screen(void);
static void mmi_mtv_player_exit_cl_option_screen(void);
static void mmi_mtv_player_entry_channel_list_screen(void);
static void mmi_mtv_player_option_setting_set_value(void);
static void mmi_mtv_player_option_setting_highlight_hdlr(S32 index);
static void mmi_mtv_player_exit_settings_screen(void);
static void mmi_mtv_player_entry_settings_screen(void);
static BOOL mmi_mtv_player_check_and_restore_valid_drv(void);
static void mmi_mtv_player_highlight_storage_hdlr(S32 idx);
static void mmi_mtv_player_entry_storage_screen(void);
static void mmi_mtv_player_exit_select_storage_screen_without_selecting(void);
static void mmi_mtv_player_update_channel_list(void);
static void mmi_mtv_player_highlight_cl(void);
static void mmi_mtv_player_highlight_settings(void);
static void mmi_mtv_player_highlight_storage(void);
static void mmi_mtv_player_highlight_band(void);
static void mmi_mtv_player_highlight_play(void);
static void mmi_mtv_player_highlight_update_list(void);
static void mmi_mtv_player_highlight_app(void);
static void mmi_mtv_player_dummy(void);
static void mmi_mtv_player_register_key_hdlr(void);
static void mmi_mtv_player_exit_init_channel_list_screen(void);
static void mmi_mtv_player_entry_init_channel_list_screen(void);

static void mmi_mtv_player_set_band_value(void);
static void mmi_mtv_player_highlight_band_hdlr(S32 idx);
static void mmi_mtv_player_entry_band_screen(void);
static void mmi_mtv_player_exit_band_screen(void);
static void mmi_mtv_player_entry_app_screen(void);
static void mmi_mtv_player_exit_app_screen(void);

static void mmi_mtv_player_display_done_popup(void);
static void mmi_mtv_player_display_error_popup(U16 stringid);

static BOOL mmi_mtv_player_get_storage_file_path(PS8 filepath);
static BOOL mmi_mtv_player_get_storage_disk_path(PS8 drv_buf);
static S32 mmi_mtv_player_create_file_dir(PS8 filepath);
static void mmi_mtv_player_set_storage_callback(S8 drv_letter);

static void mmi_mtv_player_rsk_press(void);
static void mmi_mtv_player_rsk_release(void);
static void mmi_mtv_player_lsk_press(void);
static void mmi_mtv_player_lsk_release(void);
static void mmi_mtv_player_play_icon_press(void);
static void mmi_mtv_player_play_icon_release(void);
static void mmi_mtv_player_record_icon_press(void);
static void mmi_mtv_player_record_icon_release(void);
static void mmi_mtv_player_play_speed_icon_press(void);
static void mmi_mtv_player_play_speed_icon_release(void);
static void mmi_mtv_player_fullscreen_icon_press(void);
static void mmi_mtv_player_fullscreen_icon_release(void);
static void mmi_mtv_player_forward_icon_press(void);
static void mmi_mtv_player_forward_icon_release(void);
static void mmi_mtv_player_rewind_icon_press(void);
static void mmi_mtv_player_rewind_icon_release(void);
static void mmi_mtv_player_vol_inc_icon_press(void);
static void mmi_mtv_player_vol_inc_icon_release(void);
static void mmi_mtv_player_vol_dec_icon_press(void);
static void mmi_mtv_player_vol_dec_icon_release(void);
static void mmi_mtv_player_channel_next_icon_press(void);
static void mmi_mtv_player_channel_next_icon_release(void);
static void mmi_mtv_player_channel_prev_icon_press(void);
static void mmi_mtv_player_channel_prev_icon_release(void);
static void mmi_mtv_player_switch_ts_bar(void);
static void mmi_mtv_player_key_1_press(void);
static void mmi_mtv_player_key_2_press(void);
static void mmi_mtv_player_key_3_press(void);
static void mmi_mtv_player_key_4_press(void);
static void mmi_mtv_player_key_5_press(void);
static void mmi_mtv_player_key_6_press(void);
static void mmi_mtv_player_key_7_press(void);
static void mmi_mtv_player_key_8_press(void);
static void mmi_mtv_player_key_9_press(void);
static void mmi_mtv_player_key_0_press(void);
static void mmi_mtv_player_jump_to_channel(void);

static void mmi_mtv_player_init_icon_info(void);
#ifdef __MMI_TOUCH_SCREEN__
static void mmi_mtv_player_ts_bar_icon_press(S32 x, S32 y);
static void mmi_mtv_player_ts_bar_icon_release(void);
static BOOL mmi_mtv_player_touch_scr_hit_test(S32 pos_x, S32 pos_y, mtv_player_osd_icon_struct *touch_obj);
static void mmi_mtv_player_pen_down_hdlr_fullscreen(mmi_pen_point_struct pos);
static void mmi_mtv_player_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_mtv_player_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_mtv_player_pen_move_hdlr(mmi_pen_point_struct pos);
#endif

static void mmi_mtv_player_draw_style_text(PS8 str, S32 offset_x, S32 offset_y);
static void mmi_mtv_player_draw_osd_softkey(void);
static void mmi_mtv_player_draw_osd_and_blt_check(void);
static void mmi_mtv_player_draw_osd(void);

static void mmi_mtv_player_fullscr_osd_show_up(void);
static void mmi_mtv_player_fullscr_osd_fade_cyclic(void);
static void mmi_mtv_player_fullscr_reset_osd_fade(BOOL sleep);

static void mmi_mtv_player_app_mem_success_callback(void);
static void mmi_mtv_player_app_mem_stop_callback(void);

static void mmi_mtv_player_create_adm(void);
static void mmi_mtv_player_delete_adm(void);
static void mmi_mtv_player_init_adm_resource(void);
static void mmi_mtv_player_deinit_adm_resource(void);
static void mmi_mtv_player_create_resource(void);
static void mmi_mtv_player_free_resource(void);
static U8 mmi_mtv_player_del_scr_callback(void* ptr);
static void mmi_mtv_player_store_setting(void);
static void mmi_mtv_player_load_setting(void);
static void mmi_mtv_player_restore_setting(void);
static void mmi_mtv_player_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);
static void mmi_mtv_player_draw_hint(void);
static void mmi_mtv_player_hide_hint(void);
static void mmi_mtv_player_init_highlight_hdlr(void);

static void mmi_mtv_player_clear_dls_layer(void);
static void mmi_mtv_player_config_osd_and_dls_layer(void);

static void mmi_mtv_player_on_service_found_hdlr(mdi_mtv_service_info_struct *service_info);
static void mmi_mtv_player_player_event_callback(U32 event_id, S32 param);
static void mmi_mtv_player_recorder_event_callback(U32 event_id, S32 param);
static void mmi_mtv_player_on_search_progress_ind_hdlr(S32 value);
static void mmi_mtv_player_on_complete_saving_ind_hdlr(S32 value);
static void mmi_mtv_player_service_event_callback(U32 event_id, S32 param);

static MDI_RESULT mmi_mtv_player_open_engine(void);

static void mmi_mtv_player_enter_state(mmi_mtv_player_module_enum module);
static void mmi_mtv_player_exit_current_state(mmi_mtv_player_module_enum module);
/*kernel state management*/
static void mmi_mtv_player_kernel_entry_closed_state(void);
static void mmi_mtv_player_kernel_exit_closed_state(void);
static void mmi_mtv_player_kernel_entry_scanning_state(void);
static void mmi_mtv_player_kernel_exit_scanning_state(void);
static void mmi_mtv_player_kernel_entry_save_confirm_state(void);
static void mmi_mtv_player_kernel_exit_save_confirm_state(void);
static void mmi_mtv_player_kernel_entry_saving_state(void);
static void mmi_mtv_player_kernel_exit_saving_state(void);
static void mmi_mtv_player_kernel_entry_opened_state(void);
static void mmi_mtv_player_kernel_exit_opened_state(void);
static void mmi_mtv_player_kernel_entry_init_state(void);
static void mmi_mtv_player_kernel_exit_init_state(void);
static void mmi_mtv_player_kernel_entry_ready_state(void);
static void mmi_mtv_player_kernel_exit_ready_state(void);
/*player state management*/
static void mmi_mtv_player_player_entry_stopped_state(void);
static void mmi_mtv_player_player_exit_stopped_state(void);
static void mmi_mtv_player_player_entry_bt_connect_state(void);
static void mmi_mtv_player_player_exit_bt_connect_state(void);
static void mmi_mtv_player_player_entry_play_state(void);
static void mmi_mtv_player_player_exit_play_state(void);
static void mmi_mtv_player_player_entry_pause_state(void);
static void mmi_mtv_player_player_exit_pause_state(void);
/*recorder state management*/
static void mmi_mtv_player_recorder_entry_stopped_state(void);
static void mmi_mtv_player_recorder_exit_stopped_state(void);
static void mmi_mtv_player_recorder_entry_record_state(void);
static void mmi_mtv_player_recorder_exit_record_state(void);
static void mmi_mtv_player_recorder_entry_save_confirm_state(void);
static void mmi_mtv_player_recorder_exit_save_confirm_state(void);
static void mmi_mtv_player_recorder_entry_saving_state(void);
static void mmi_mtv_player_recorder_exit_saving_state(void);

static void mmi_mtv_player_discard_unsaved_recording(void);
static void mmi_mtv_player_save_recording(void);
static U8 mmi_mtv_player_init_cl_screen_del_hdlr(void *dummy_ptr);
static U8 mmi_mtv_player_saving_screen_del_hdlr(void *dummy_ptr);
static void mmi_mtv_player_player_update_cyclic(void);

static S32 mmi_mtv_player_get_active_channel(void);
static void mmi_mtv_player_scrolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_mtv_player_scrolling_text_handle(void);
static void mmi_mtv_player_set_dynamic_label_and_draw(PS8 str, U16 duration);

/* bluetooth */
#if defined(__MMI_MTV_A2DP_SUPPORT__)
static void mmi_mtv_player_highlight_bluetooth_setting(void);
static void mmi_mtv_player_draw_bt_connecting_anim(void);
static MMI_BOOL mmi_mtv_player_is_output_to_bt(void);
static void mmi_mtv_player_stop_bt_connecting_anim(void);
static mmi_bt_dev_struct *mmi_mtv_player_get_bt_headset(void);
static void mmi_mtv_player_bt_open_callback(S32 result);
static void mmi_mtv_player_disconnect_bt(void);
static void mmi_mtv_player_bt_close_codec(void);
#endif /* __MMI_MTV_A2DP_SUPPORT__ */

#ifdef __MMI_MTV_AVRCP_SUPPORT__
static U8 mmi_mtv_player_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events event);
#endif
MMI_ID_TYPE mmi_mtv_player_get_error_string_by_error_enum(S32 err_code);


#endif /* __MMI_MOBILE_TV_PLAYER__ */ 
#endif /* _MMI_MOBILE_TV_PLAYER_DATATPYE_H_ */ 

