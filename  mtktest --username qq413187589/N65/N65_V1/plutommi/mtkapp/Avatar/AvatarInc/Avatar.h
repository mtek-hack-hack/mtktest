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
 *  Avatar.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Avatar Applications v0.1
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef _AVATAR_DATATPYE_H_
#define _AVATAR_DTATTYPE_H_

#include "mmi_features.h"
#include "avatarGProt.h"

#ifdef __MMI_AVATAR__

/****************************************************************************
* MACRO
*****************************************************************************/


/****************************************************************************
* Define
*****************************************************************************/

#define AVATAR_MENU_LIST


#define AVATAR_HEAD_MESH_ID


#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )

    #define MMI_AVATAR_DISPLAY_WINDOW_WIDTH 82
    #define MMI_AVATAR_DISPLAY_WINDOW_HEIGHT 105
    #define MMI_AVATAR_DISPLAY_WINDOW_OFFSET_X 10
    #define MMI_AVATAR_DISPLAY_WINDOW_OFFSET_Y 44

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )

    #define MMI_AVATAR_DISPLAY_WINDOW_WIDTH 120
    #define MMI_AVATAR_DISPLAY_WINDOW_HEIGHT 172
    #define MMI_AVATAR_DISPLAY_WINDOW_OFFSET_X 11
    #define MMI_AVATAR_DISPLAY_WINDOW_OFFSET_Y 55

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )

    #define MMI_AVATAR_DISPLAY_WINDOW_WIDTH 142
    #define MMI_AVATAR_DISPLAY_WINDOW_HEIGHT 144
    #define MMI_AVATAR_DISPLAY_WINDOW_OFFSET_X 57
    #define MMI_AVATAR_DISPLAY_WINDOW_OFFSET_Y 3

#endif

#define MMI_AVATAR_UI_IMAGE_BOX_SPACING      (2)
#define MMI_AVATAR_UI_TEXT_SPACING           (5)
#define AVATAR_THUMB_IMAGE_CACHE_MAX_COUNT        (50)    /* may cache up to 30 images */
#define AVATAR_THUMB_IMAGE_HANDLE_MAX_COUNT       (16)    /* may decode up to 12 images on a screen at a time */
#ifdef __MMI_TOUCH_SCREEN__
#define AVATAR_UI_DELAY_DECODE_DURATION  (1000)
#else 
#define AVATAR_UI_DELAY_DECODE_DURATION  (100)
#endif 


#define AVATAR_MAX_NAME_LEN 23

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum
{
    AVATAR_STATE_NEW,
    AVATAR_STATE_NEW_EDITING,
    AVATAR_STATE_MODIFYING,
    AVATAR_STATE_SAVING,
    AVATAR_STATE_SAVING_NEW,
    AVATAR_STATE_RENAME,
    AVATAR_STATE_DISPLAYING,
    AVATAR_STATE_SELECT_ANIMATION,
    AVATAR_STATE_CHECK_IF_SAVE,
    AVATAR_STATE_EDITOR_OPTION
}mmi_avatar_editing_state_enum;


typedef enum
{
    AVATAR_ICON_STATUS_ENABLE = 0,
    AVATAR_ICON_STATUS_DISABLE = 0x0001,
    AVATAR_ICON_STATUS_CLICKED = 0x0010
} avatar_icon_status_enum;

typedef enum
{
    /* top section */
    AVATAR_TOUCH_HEAD,
    AVATAR_TOUCH_HAIR,
    AVATAR_TOUCH_EYE,
    AVATAR_TOUCH_BROW,
    AVATAR_TOUCH_LIP,
    AVATAR_TOUCH_DECORATION,
    AVATAR_TOUCH_BODY,

    AVATAR_TOUCH_MAGNIFY,
    AVATAR_TOUCH_MINIFY,
    AVATAR_TOUCH_COLOR,
    AVATAR_TOUCH_MOVEUP,
    AVATAR_TOUCH_MOVEDOWN,
    AVATAR_TOUCH_STRETCH,
    AVATAR_TOUCH_SHRINK,

    AVATAR_TOUCH_LARROW,
    AVATAR_TOUCH_RARROW,

    AVATAR_TOUCH_TOP_LARROW,
    AVATAR_TOUCH_TOP_RARROW,

    AVATAR_TOUCH_TOGGLE,

    AVATAR_TOUCH_LSK,
    AVATAR_TOUCH_RSK,
    AVATAR_TOUCH_NONE
} avatar_touch_obj_enum;

/***************************************
* For Avatar Editor OSD
***************************************/
typedef struct
{
	BOOL is_show;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    avatar_icon_status_enum is_press;
} avatar_osd_icon_struct;

typedef struct 
{
	U8		r;
	U8		g;	
	U8		b;		
	U8		style_r;
	U8		style_g;	
	U8		style_b;
	U16	    style;	
} avatar_style_text_struct;

typedef struct
{
	BOOL	is_show;
	S32 	offset_x;
	S32 	offset_y;
	S32	    width;
	S32 	height;

} avatar_osd_title_struct;

typedef struct 
{
    avatar_osd_title_struct avatar_name;

    /* top section */
    avatar_osd_icon_struct  head;
    avatar_osd_icon_struct  hair;
    avatar_osd_icon_struct  eye;
    avatar_osd_icon_struct  brow;
    avatar_osd_icon_struct  lip;
    avatar_osd_icon_struct  decoration;
    avatar_osd_icon_struct  body;

    /* left section */
    avatar_osd_icon_struct  magnify;
    avatar_osd_icon_struct  minify;
    avatar_osd_icon_struct  color;
    avatar_osd_icon_struct  moveup;
    avatar_osd_icon_struct  movedown;
    avatar_osd_icon_struct  stretch;
    avatar_osd_icon_struct  shrink;
    
    avatar_osd_icon_struct  larrow;
    avatar_osd_icon_struct  rarrow;

    avatar_osd_icon_struct  top_larrow;
    avatar_osd_icon_struct  top_rarrow;

#ifndef __MMI_TOUCH_SCREEN__
    avatar_osd_icon_struct  toggle; 
#endif

} avatar_osd_layout_struct;




typedef S32 (*mmi_avatar_callback) (void);


#define MMI_AVATAR_COUNT 16

typedef struct
{
    /* 12 bytes */
    U32     image_type; /* 0-3 */
    U32     size;       /* 4-7 */ 
    U16     resourceid; /* 8-9 */
    S16     serial_number; /*10-11*/
    S16     idx;
    S16     next;
    S16     prev;
    pBOOL   is_slot_free;
    //S8      filename[MMI_AVATAR_NAME_LENGTH];
}mmi_avatar_meta_header_struct;



typedef struct
{
    /* Header 10 bytes */
    U32 total_count;
    S16 head;
    S16 tail;
    S16 serial_number;
    pBOOL delete_all;
    
    /* 16 * 20 = 320 bytes */
    mmi_avatar_meta_header_struct meta_header[MMI_AVATAR_COUNT];

    /* 4 * 20 = 80 bytes */
    mmi_avatar_meta_header_struct wp;
    mmi_avatar_meta_header_struct ss;    
    mmi_avatar_meta_header_struct pwron;
    mmi_avatar_meta_header_struct pwroff;
}mmi_avatar_meta_manager_struct;

typedef struct
{
    gdi_handle base_layer_handle;
    gdi_handle drawing_layer_handle;
    BOOL    is_gdi_locked;

    S32 m3d_screen_offset_x;
    S32 m3d_screen_offset_y;
    S32 m3d_screen_width;
    S32 m3d_screen_height;

    S32 last_error;
/*******************************************************************************
 * Avatar List (including cache mechanism)
 *******************************************************************************/
    UI_character_type           avatar_name[(AVATAR_MAX_NAME_LEN+1)*ENCODING_LENGTH];
    scrolling_text              scrolling_text;
    S8                          scrolling_text_ptr[(AVATAR_MAX_NAME_LEN+1)*ENCODING_LENGTH];
    U16                         delay_decode_index;
    BOOL                        is_decoder_create;
    mmi_avatar_app_type_enum    app_type;
    avatar_callback             app_callback_ptr;
    U32                         current_avatar_id;
    U32                         selected_avatar_id;
    S32                         high_light_idx;

/*******************************************************************************
 * Avatar Editor
 *******************************************************************************/

    void *app_mem_pool;
    mmi_avatar_editing_state_enum   state;
    mmi_avatar_editing_state_enum   prev_state;
    S16                         page_of_head;
    S16                         page_of_hair;
    S16                         page_of_eye;
    S16                         page_of_lip;
    S16                         page_of_brow;
    S16                         page_of_decoration;
    S16                         page_of_body;

    S16                         selected_itom_idx;
    S16                         selected_itom_page;
    pBOOL                       is_highlighted;
    pBOOL                       is_meta_manager_loaded;
    pBOOL                       is_reload;

#ifndef __MMI_TOUCH_SCREEN__
    pBOOL                       is_editor_phase1;
#endif
/*******************************************************************************
 * Avatar Meta Manager
 *******************************************************************************/
    mmi_avatar_meta_header_struct editor_m3d;
    mmi_avatar_meta_manager_struct meta_manager;
    U16 selected_animation;
    mmi_avatar_avatar_struct  avatar_list[MMI_AVATAR_COUNT];
    gdi_handle anim_handle;

/*******************************************************************************
 * osd layer
 *******************************************************************************/
    PU8 osd_layer_buf_ptr;
    gdi_handle osd_layer_handle;
    
/*******************************************************************************
 * Soft Key
 *******************************************************************************/
    U16 touch_object;
    avatar_touch_obj_enum  selected_top_object;
    avatar_osd_icon_struct lsk;
    avatar_osd_icon_struct rsk;
    scrolling_text              scrolling_title;
    pBOOL                       is_scrolling_title;

/*******************************************************************************
 * for M3D Parser
 *******************************************************************************/
    st_m3d_world* m3d_world;
    st_m3d_world* m3d_world_head;
    st_m3d_world* m3d_world_hair;    
    st_m3d_world* m3d_world_body;

    st_m3d_camera* m3d_camera;
  	st_m3d_light* m3d_light;
   	st_m3d_transform *light_trans;

    U8*  image_buffer_ptr;
    gdi_handle image_buffer_handle;
    
/*******************************************************************************
 * Touch Panel Support
 *******************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
    S32                         pen_down_x;
    S32                         pen_down_y;
    pBOOL                       is_pen_down;
    S32                         movement_x;
    S32                         movement_y;
#endif


}mmi_avatar_cntx_struct;

typedef enum {
    MMI_AVATAR_M3D_TYPE_MAIN_FILE = 0,
    MMI_AVATAR_M3D_TYPE_ANIMATION_ONLY,
    MMI_AVATAR_M3D_TYPE_ACCESSORY,
    MMI_AVATAR_M3D_TYPE_TOTAL_COUNT
}mmi_avatar_m3d_type_enum;


/***************************************************************
*  M3D render engine related functions
****************************************************************/




/***************************************************************
*  Avatar list display related functions 
****************************************************************/
static U32 mmi_avatar_get_id_from_idx(S32 idx);
static void mmi_avatar_get_avatar_name_by_idx(S32 idx, S8* avatarname);
static void mmi_avatar_get_filename_by_idx (S32 idx, S8* filename);
static void mmi_avatar_create_thumb_image_cache(S32 image_size);
static void mmi_avatar_free_thumb_image_cache(void);
static void mmi_avatar_draw_menuitem_callback(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_avatar_hide_menuitem_callback(void);
static void mmi_avatar_decode_thumb_image_result_hdlr(GDI_RESULT decode_result, gdi_handle handle);
static void mmi_avatar_delay_decode_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                S32 icon_offset_x,
                S32 icon_offset_y,
                S32 icon_width,
                S32 icon_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style);

static void mmi_avatar_delay_decode_0(void);
static void mmi_avatar_delay_decode_1(void);
static void mmi_avatar_delay_decode_2(void);
static void mmi_avatar_delay_decode_3(void);
static void mmi_avatar_delay_decode_4(void);
static void mmi_avatar_delay_decode_5(void);
static void mmi_avatar_delay_decode_6(void);
static void mmi_avatar_delay_decode_7(void);
static void mmi_avatar_delay_decode_8(void);
static void mmi_avatar_delay_decode_9(void);



static void mmi_avatar_hilight_text_sel_inp_method(void);
static void mmi_avatar_hilight_text_edit_done(void);
static void mmi_avatar_entry_edit_option_screen(void);
static void mmi_avatar_show_option52(U16 id_menu, U16 id_str, PU8 gui_buffer);
static void mmi_avatar_return_to_editor_screen(void);

/***************************************************************
*  Avatar Screen functions
****************************************************************/
static void mmi_avatar_enter_editor(void);
static void mmi_avatar_entry_list_screen(void);
static void mmi_avatar_exit_list_screen(void);
static void mmi_avatar_entry_editor_screen_internal(void);
static void mmi_avatar_entry_editor_screen(U32 callback_id,U32 serial_num);
static void mmi_avatar_select_path_and_enter_internal(void);
static void mmi_avatar_editor_timeout_hdlr(void);
static void mmi_avatar_exit_editor_screen(void);
static void mmi_avatar_init_option_menu(void);
static void mmi_avatar_entry_option_menu_screen(void);
static void mmi_avatar_exit_editor_option(void);
static void mmi_avatar_entry_editor_option_menu_screen(void);
static void mmi_avatar_entry_editing_name_screen(void);
static void mmi_avatar_exit_select_animation_screen(void);
static void mmi_avatar_entry_select_animation_screen(void);
static void mmi_avatar_update_setting_mh(S16 serial_number);

/***************************************************************
*  High light handler functions
****************************************************************/
static void mmi_avatar_highlight_app(void);
static void mmi_avatar_list_highlight_hdlr(S32 idx);
static void mmi_avatar_highlight_new(void);
static void mmi_avatar_highlight_edit(void);
static void mmi_avatar_highlight_play(void);
static void mmi_avatar_highlight_delete(void);
static void mmi_avatar_highlight_rename(void);
static void mmi_avatar_highlight_delete_all(void);
static void mmi_avatar_highlight_save(void);
static void mmi_avatar_highlight_exit(void);

/***************************************************************
*  OSD related functions
****************************************************************/
static void mmi_avatar_draw_osd(void);
static void mmi_avatar_draw_osd_sofekey(void);
static void mmi_avatar_draw_style_text(PS8 str, S32 offset_x, S32 offset_y);
static void mmi_avatar_draw_bottom_icon(void);
static void mmi_avatar_draw_osd_title(void);


/***************************************************************
*  Avatar editing or misc functions
****************************************************************/
static U8 mmi_avatar_del_scr_callback(void* ptr);
static void mmi_avatar_free_app_mem(void);
static void mmi_avatar_app_mem_stop_callback(void);
static void mmi_avatar_app_mem_success_callback(void);
static S16 mmi_avatar_load_avatar_setting(mmi_avatar_avatar_struct*,U32);
static S16 mmi_avatar_save_avatar_setting(mmi_avatar_avatar_struct*,U32);
static void mmi_avatar_load_avatar_default_setting(void);
static void mmi_avatar_apply_change(S16 old_itom_idx, S16 new_itom_idx);    
static void mmi_avatar_apply_facial_texture_change(void);
static void mmi_avatar_apply_body_texture_change(void);   
static void mmi_avatar_apply_setting_to_avatar(void);
static void mmi_avatar_load_meta_manager(void);
static void mmi_avatar_save_meta_manager(void);
static void mmi_avatar_restore_meta_manager(void);
static void mmi_avatar_load_avatar_list(void);
static void mmi_avatar_saving_timeout(void);
static void mmi_avatar_saving_timeout_by_option_menu(void);
static void mmi_avatar_rename_avatar(void);
static void mmi_avatar_save_new_avatar(void);
static void mmi_avatar_encode_jpeg(void);
static void mmi_avatar_delete_avatar_confirm(void);
static void mmi_avatar_delete_avatar(void);
static void mmi_avatar_delete_all_avatar_confirm(void);
static void mmi_avatar_delete_all_avatar(void);
static void mmi_avatar_display_error_popup(U16 err_code);
static void mmi_avatar_set_caller_picture(void);
#if 0
/* under construction !*/
#endif
static void mmi_avatar_set_animation(void);
static BOOL mmi_avatar_show_thumb_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style);
static void mmi_avatar_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_avatar_draw_hilight_menuitem_timer_callback(void);
static void mmi_avatar_strolling_text_redraw_bg(S32 x1, S32 y1, S32 x2, S32 y2);


#if 0
/* under construction !*/
#endif
/***************************************************************
*  Avatar Editor key or touch related functions
****************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
static BOOL mmi_avatar_touch_scr_hit_test(S32 pos_x, S32 pos_y, avatar_osd_icon_struct *touch_obj);
static void mmi_avatar_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_avatar_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_avatar_pen_move_hdlr(mmi_pen_point_struct pos);
static void mmi_avatar_rarrow_icon_press(void);
static void mmi_avatar_larrow_icon_press(void);
static void mmi_avatar_lsk_release(void);
static void mmi_avatar_rsk_release(void);
static pBOOL mmi_avatar_check_if_modified(void);
static void mmi_avatar_exit_editor_without_save(void);
#endif /* __MMI_TOUCH_SCREEN__ */ 

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
#endif 

#ifndef __MMI_TOUCH_SCREEN__
static void mmi_avtar_lsk_release_enter_option(void);
static void mmi_avatar_set_editor_phase_setting(void);
static void mmi_avatar_toggle_editor_phase(void);
static void mmi_avatar_select_next_item(void);
static void mmi_avatar_select_previous_item(void);
#endif

static void mmi_avatar_reset_right_icon(void);
static void mmi_avatar_right_icon_update(void);
static void mmi_avatar_reset_top_icon(void);
static void mmi_avatar_bottom_icon_page_change(S16 diff);

static void mmi_avatar_moveup_icon_release(void);
static void mmi_avatar_movedown_icon_release(void);
static void mmi_avatar_stretch_icon_release(void);
static void mmi_avatar_shrink_icon_release(void);


static void mmi_avatar_magnify_icon_release(void);
static void mmi_avatar_minify_icon_release(void);
static void mmi_avatar_top_larrow_icon_release(void);
static void mmi_avatar_top_rarrow_icon_release(void);



static void mmi_avatar_head_icon_press(void);
static void mmi_avatar_hair_icon_press(void);
static void mmi_avatar_eye_icon_press(void);
static void mmi_avatar_brow_icon_press(void);
static void mmi_avatar_decoration_icon_press(void);
static void mmi_avatar_lip_icon_press(void);
static void mmi_avatar_body_icon_press(void);
static void mmi_avatar_moveup_icon_press(void);
static void mmi_avatar_movedown_icon_press(void);
static void mmi_avatar_stretch_icon_press(void);
static void mmi_avatar_shrink_icon_press(void);
static void mmi_avatar_color_icon_press(void);
static void mmi_avatar_lsk_press(void);
static void mmi_avatar_rsk_press(void);
static void mmi_avatar_rsk_release_from_select_animation_screen(void);
static void mmi_avatar_magnify_icon_press(void);
static void mmi_avatar_minify_icon_press(void);
static void mmi_avatar_top_larrow_icon_press(void);
static void mmi_avatar_top_rarrow_icon_press(void);


#endif /* __MMI_AVATAR__ */ 
#endif /* _AVATAR_DATATPYE_H_ */ 

