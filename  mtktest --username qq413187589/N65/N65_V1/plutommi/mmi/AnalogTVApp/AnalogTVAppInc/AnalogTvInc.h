#ifdef ANALOG_TV_SUPPORT

#ifndef  ANALOGTVINC_H
#define  ANALOGTVINC_H

//define touch screen
#if defined(__MMI_TOUCH_SCREEN__)
#define __ANALOG_TV_FEATURE_TOUCH_SCREEN__
#endif

//define full screen preview
#define __ANALOG_TV_FEATURE_FULL_SCREEN__

/* context */

//IMPORTANT: this state MUST BE the same to vdorec_state_neum 
typedef enum {
	ANALOG_TV_STATE_EXIT,
	ANALOG_TV_STATE_PREVIEW,
	ANALOG_TV_STATE_RECORD,
	ANALOG_TV_STATE_PAUSE,
	ANALOG_TV_STATE_PREVIEW_FULLSCREEN,
	ANALOG_TV_STATE_PREVIEW_320_240_SCREEN  /*UNI@bw070816 WQVGA LCD Support*/
} ANALOG_TV_STATE_ENUM;
/*UNI@bw_20070614 重新整理地区列表并将巴西和阿根廷放到n制式里*/
/*UNI@bw_20070607 添加地区并整理*/
/*UNI@bw_20070515 19:36:11 整理更新地区列表*/
/***************************************************
* 此列表共有3个请却保他们的一致性
*否则会出问题tlg1100.h 和tlg1100customize.c
*AnalogTvInc.h并请VdoRecStrEnum.h中字符定义顺序和其一致
*
*****************************************************/
typedef enum
{
/* PAL 制式  */
	ANALOG_TV_PAL_START,	

	ANALOG_TV_CHINA_START=ANALOG_TV_PAL_START,
     	ANALOG_TV_AREA_CHINA=ANALOG_TV_CHINA_START,
     	ANALOG_TV_CHINA_END=ANALOG_TV_AREA_CHINA,

	ANALOG_TV_SHENZHEN_START,
     	ANALOG_TV_AREA_SHENZHEN=ANALOG_TV_SHENZHEN_START,
     	ANALOG_TV_SHENZHEN_END=ANALOG_TV_AREA_SHENZHEN,

	ANALOG_TV_EUROPE_START,
	ANALOG_TV_AREA_EUROPE=ANALOG_TV_EUROPE_START,		//欧洲地区包涵国家和地区
	ANALOG_TV_AREA_TURKEY,
	ANALOG_TV_AREA_UAE,
	ANALOG_TV_AREA_AFGHANISTAN,
	ANALOG_TV_AREA_SINGAPORE,
	ANALOG_TV_AREA_THAILAND,
	ANALOG_TV_AREA_CAMBODIA,
	ANALOG_TV_AREA_INDONESIA,
	ANALOG_TV_AREA_MALAYSIA,
	ANALOG_TV_AREA_MYANMAR,
	ANALOG_TV_AREA_LAOS,
	ANALOG_TV_AREA_SPAIN,
	ANALOG_TV_AREA_PORTUGAL,
	ANALOG_TV_AREA_INDIA,
	ANALOG_TV_AREA_PAKISTAN,
	ANALOG_TV_EUROPE_END=ANALOG_TV_AREA_PAKISTAN,
	
	ANALOG_TV_VIETNAM_START,
	ANALOG_TV_AREA_VIETNAM=ANALOG_TV_VIETNAM_START,		//越南
	ANALOG_TV_VIETNAM_END=ANALOG_TV_AREA_VIETNAM,
	
	ANALOG_TV_ARGENTINA_START,
	ANALOG_TV_AREA_ARGENTINA=ANALOG_TV_ARGENTINA_START,	//阿根廷
	ANALOG_TV_ARGENTINA_END=ANALOG_TV_AREA_ARGENTINA,
	
	ANALOG_TV_HONGKONG_START,	//英国包涵国家地区
	ANALOG_TV_AREA_HONGKONG=ANALOG_TV_HONGKONG_START,	
	ANALOG_TV_AREA_ENGLAND,
	ANALOG_TV_AREA_SOUTH_AFRICA,
	ANALOG_TV_HONGKONG_END=ANALOG_TV_AREA_SOUTH_AFRICA,
	
	ANALOG_TV_PAL_END=ANALOG_TV_HONGKONG_END,
	
/* NTSL 制式  */

	ANLAOG_TV_NTSL_START,	//nts格式开始
	
	ANALOG_TV_AMERICA_START=ANLAOG_TV_NTSL_START,	//美国地区包涵国家
	ANALOG_TV_AREA_AMERICA=ANALOG_TV_AMERICA_START,	
	ANALOG_TV_AREA_CANADA,
	ANALOG_TV_AREA_KOREA,
	ANALOG_TV_AREA_TAIWAN,
	ANALOG_TV_AREA_MEXICO,
	ANALOG_TV_AREA_CHILE,
	ANALOG_TV_AREA_VENEZUELA,
	ANALOG_TV_AREA_PHILIPPINES,
	ANALOG_TV_AMERICA_END=ANALOG_TV_AREA_PHILIPPINES,
	
	ANALOG_TV_BRAZIL_START,
	ANALOG_TV_AREA_BRAZIL=ANALOG_TV_BRAZIL_START,
	ANALOG_TV_BRAZIL_END=ANALOG_TV_AREA_BRAZIL,
	
	ANALOG_TV_JAPAN_START,
	ANALOG_TV_AREA_JAPAN=ANALOG_TV_JAPAN_START,		//日本地区
	ANALOG_TV_JAPAN_END=ANALOG_TV_AREA_JAPAN,

	ANALOG_TV_NTSL_END=ANALOG_TV_JAPAN_END,

	ANALOG_TV_AREA_TOTALNUM
	
}ANALOG_TV_AREA_FORMAT;

typedef enum
{
ANALOG_TV_TOUCH_SPEED_INC,
	ANALOG_TV_TOUCH_SPEED_DEC,
	ANALOG_TV_TOUCH_VOLUME_INC,
	ANALOG_TV_TOUCH_VOLUME_DEC,
	ANALOG_TV_TOUCH_PROGRESS_INC,
	ANALOG_TV_TOUCH_PROGRESS_DEC,
	ANALOG_TV_TOUCH_PROGRESS_BAR,
	ANALOG_TV_TOUCH_SNAPSHOT,
	ANALOG_TV_TOUCH_FULLSCREEN,
     ANALOG_TV_TOUCH_RSK,
     ANALOG_TV_TOUCH_LSK,
     ANALOG_TV_TOUCH_CK,
	ANALOG_TV_TOUCH_COLOR_TYPE,
     ANALOG_TV_TOUCH_NONE
}  ANALOG_TV_TOUCH_OBJECT_ENUM;

#define MMI_ANALOG_TV_TRACE kal_prompt_trace

#define MMI_ANALOG_TV_BRIGHTNESS_MAX    (127)
#define MMI_ANALOG_TV_BRIGHTNESS_MIN    (0)
#define MMI_ANALOG_TV_CONTRAST_MAX      (127)
#define MMI_ANALOG_TV_CONTRAST_MIN      (0)
#define MMI_ANALOG_TV_SATURATION_MAX    (127)
#define MMI_ANALOG_TV_SATURATION_MIN    (0)
#define MMI_ANALOG_TV_HUE_MAX           (127)
#define MMI_ANALOG_TV_HUE_MIN           (0)

#define ANALOG_TV_MAX_VOL_LEVEL         (7)
#define ANALOG_TV_CHANNEL_NUM  (15)
#define ANALOG_TV_CHANNEL_NAME_LEN	(11)
typedef struct
{
    /* strings for inline selection display */
    UI_string_type video_size_str[VDOREC_VIDEO_QTY_ITEM_COUNT];
    UI_string_type video_qty_str[VDOREC_VIDEO_QTY_ITEM_COUNT];
    UI_string_type size_limit_str[VDOREC_SIZE_LIMIT_ITEM_COUNT];
    UI_string_type time_limit_str[VDOREC_TIME_LIMIT_ITEM_COUNT];
    UI_string_type record_aud_str[VDOREC_RECORD_AUD_ITEM_COUNT];
    UI_string_type video_format_str[VDOREC_VIDEO_FORMAT_ITEM_COUNT];

    /* selected item */
    S32 video_size_selected;
    S32 video_qty_selected;
    S32 size_limit_selected;
    S32 time_limit_selected;
    S32 record_aud_selected;
    S32 video_format_selected;
} mmi_analog_tv_rec_setting_inline_data_struct;

typedef enum {
	ANALOG_TV_STATE_NOT_READY = 0,
	ANALOG_TV_STATE_READY,
	ANALOG_TV_STATE_SEARCH_ONE,
	ANALOG_TV_STATE_SEARCH_ALL,
	NO_OF_FMRDO_STATE
} mmi_AnalogTv_state_enum;

typedef struct
{
 U16  DistrictSelected;
 U8    ModeSelected;    //cable tv or wireless tv
 U8   ChannelList[ANALOG_TV_CHANNEL_NUM];
  UI_character_type name[ANALOG_TV_CHANNEL_NUM][ANALOG_TV_CHANNEL_NAME_LEN];  //lgadd
 BOOL   g_analog_tv_enable;
 U8 volume; 
 U8 g_current_channel;
 BOOL  is_power_on;
 U8 state;
 U8 channel_is_searching;
 U8 channel_count;
 U8 channel_index_is_searching;
 void (*callback_func)(void);
}mmi_AnalogTv_data_struct;

/* context */
typedef struct{

    gdi_handle base_layer_handle;
    gdi_handle preview_layer_handle;
    gdi_handle osd_layer_handle;
    gdi_handle overlay_frame_layer_handle;

    U16 state;
    U16 filename_seq_no;
    PU8 osd_layer_buf_ptr;
    PS8 lsk_str_ptr;
    PS8 rsk_str_ptr;
    U16 lsk_img_id;
    U16 rsk_img_id;
    U16 ck_img_id;
    S32 lcd_width;
    S32 lcd_height;
    BOOL is_lsk_pressed;
    BOOL is_rsk_pressed;
    BOOL is_ck_pressed;
    BOOL is_storage_path_changed;
    BOOL is_saving;
    BOOL is_foward_to;
    BOOL is_save_done_when_mt;
    BOOL is_ct_pressed; 
	BOOL is_mute;
	BOOL is_seeking;
   	BOOL								is_vol_inc_key_pressed;
	BOOL								is_vol_dec_key_pressed;	
	BOOL								is_speed_inc_key_pressed;
	BOOL								is_speed_dec_key_pressed;
    S32 save_result;

    BOOL is_zoom_in_key_pressed;
    BOOL is_zoom_out_key_pressed;
    BOOL is_ev_inc_key_pressed;
    BOOL is_ev_dec_key_pressed;

    BOOL is_app_popup;
    BOOL is_sub_display;
    BOOL is_self_record;
    BOOL is_force_self_record;
    BOOL is_setting_loaded;
    BOOL is_force_saving;
    BOOL is_first_time_zoom;
    BOOL is_first_time_ev;
    PS8 storage_filepath;

    S8 hint1_buf[VDOREC_HINT_BUF_SIZE];
    S8 hint2_buf[VDOREC_HINT_BUF_SIZE];
    U16 fade_time;
	U64  record_time;
    U16 zoom_limit;

    MDI_RESULT last_error;

    vdorec_setting_struct setting;
    vdorec_timer_struct timer;

    U16 touch_object;
	/* video clip */
	vdoply_video_info_struct	video_info;
	vdoply_status_struct			cur_status;

vdorec_ui_touch_struct		touch_volume_inc;
vdorec_ui_touch_struct		touch_volume_dec;
vdorec_ui_touch_struct		touch_speed_inc;
	vdorec_ui_touch_struct		touch_speed_dec;
    vdorec_ui_touch_struct touch_lsk;
    vdorec_ui_touch_struct touch_rsk;
    vdorec_ui_touch_struct touch_color_status;
    vdorec_ui_touch_struct touch_ck;
vdorec_ui_touch_struct touch_fullscreen;
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
	vdoply_ui_touch_struct		full_touch_speed_inc;
	vdoply_ui_touch_struct		full_touch_speed_dec;
	vdoply_ui_touch_struct		full_touch_volume_inc;
	vdoply_ui_touch_struct		full_touch_volume_dec;	
	vdoply_ui_touch_struct		full_touch_progress_inc;
	vdoply_ui_touch_struct		full_touch_progress_dec;
	vdoply_ui_touch_struct		full_touch_progress_bar;
	vdoply_ui_touch_struct		full_touch_rsk;		
	vdoply_ui_touch_struct		full_touch_lsk;
	vdoply_ui_touch_struct		full_touch_ck;
	vdorec_ui_touch_struct		full_touch_fullscreen;
#endif   
}mmi_analog_tv_context_struct;

typedef struct
{
    mmi_analog_tv_rec_setting_inline_data_struct video_setting_inline;

} mmi_analog_tv_menu_context_struct;

void mmi_analog_tv_hilight_app(void);
void mmi_analog_tv_init_app(void);
void mmi_analog_tv_load_setting(void);
void mmi_analog_tv_store_setting(void);

int GetAnalogTvAppFlags(void);

#if defined(TV_RECORD_SUPPORT)

void mmi_analog_tv_record_press_hdlr(void) ;
void mmi_analog_tv_record_release_hdlr(void);

#endif

#endif //ANALOGTVINC_H

#endif //ANALOG_TV_SUPPORT
