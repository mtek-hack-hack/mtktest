#ifdef ANALOG_TV_SUPPORT
#include "MMI_features.h"

#define __NEWSIMULATOR

#include "stdC.h"
#include "L4Dr1.h"
#include "GlobalDefs.h"
#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */
/* framework related headers */
#include "CustMenuRes.h"
#include "GlobalConstants.h"    /* KEY ID define */
#include "GlobalDefs.h" /* Golbal Image and String ID. */
#include "gui.h"        /* Gui functions */
#include "HistoryGprot.h"       /* Screen history */
#include "Unicodexdcl.h"        /* Unicode transform functions */
#include "NVRAMType.h"  /* NVRAM data type */
#include "NVRAMProt.h"  /* NVRAM access fucntions */
#include "NVRAMEnum.h"  /* NVRAM ID define */
#include "EventsGprot.h"        /* Entery\Exit functions */
#include "EventsDef.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "wgui.h"       /* for GetDateTime() */
#include "gpioInc.h"    /* LED */
#include "IdleAppProt.h"        /* for IsIdleArrived() */
#include "DebugInitDef.h"       /* MMI_ASSERT */
#include "CommonScreens.h"      /* Popup */
#include "keybrd.h"     /* clear key function */
#include "ProtocolEvents.h"     /* Interrupt message ID */
#include "SubLCDHistoryGprot.h" /* SubLCD */
#include "MainMenuDef.h"        /* Multi-media icon */
#include "CallManagementGProt.h"        /* GetWapCallPresent */
#include "ScrMemMgrGprot.h"     /* screen memeory manager */
#include "wgui_categories.h"    /* Categorires */
#include "wgui_categories_popup.h"
#include "wgui_categories_multimedia.h"
#include "wgui_status_icons.h"  /* status UI */
#include "wgui_softkeys.h"      /* softkey */
#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* file error text */
#include "FileMgr.h"
#include "mmiapi_enum.h"        /* Stop LED */
#include "USBDeviceGprot.h"     /* USB MS mode */
#include "AlarmFrameworkProt.h" /* alarm framework */
#include "SettingDefs.h"
/* gdi, mid, video rec headers */
#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "gdi_include.h"        /* graphic library */
#include "mdi_datatype.h"
#include "mdi_video.h"  /* mdi video library */
#ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
/* video recoder related */
#include "resource_video_skins.h"       /* UI custom config */
#include "VdoRecResDef.h"
#include "VdoRecApp.h"
#include "VdoRecGProt.h"
#include "VdoPlyGProt.h"        /* entry function */
#include "VdoPlyResDef.h"
#include "VdoPlyApp.h"
//#ifndef MMI_ON_WIN32
#include "..\AnalogTVAppInc\AnalogTvInc.h"
//#endif
#include "Med_struct.h"
#include "wgui_categories_inputsenum.h"
#include "MessagesresourceData.H"
#include "HealthMenstural.h"			//超出范围的字串
#include "Gui_data_types.h"

#include "custom_mmi_default_value.h"
#include "HealthemnstrurealResDef.h"
#include "Mdi_camera.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#ifndef pixtel_UI_color //hongzhe.liu edd
#define pixtel_UI_color(r, g, b)  gui_color( r, g, b )//UI_color
#define pixtel_UI_measure_image            gui_measure_image
#define pixtel_UI_push_clip                       gui_push_clip
#define pixtel_UI_show_image                  gui_show_image
#define pixtel_UI_reset_clip                      gui_reset_clip
#define pixtel_UI_set_clip                          gui_set_clip
#define pixtel_UI_pop_clip                         gui_pop_clip
#define pixtel_UI_unlock_double_buffer   gui_unlock_double_buffer
#define pixtel_UI_BLT_double_buffer        gui_BLT_double_buffer
#define pixtel_UI_lock_double_buffer       gui_lock_double_buffer
#endif

#define mmi_wgui_register_pen_down_handler wgui_register_pen_down_handler
#define mmi_wgui_register_pen_up_handler wgui_register_pen_up_handler
#define mmi_wgui_register_pen_move_handler wgui_register_pen_move_handler

#define DUMMY_COMMAND               (0)
#define HINT_POPUP_FADE_TIME        (2000)
#define VDOREC_ERR_CORRUPT_FAT      (-1)
#define VDOREC_ERR_PHONE_DISK_FULL  (-2)
#define VDOREC_ERR_CARD_DISK_FULL   (-3)
#define VDOREC_ERR_WRITE_PROTECT    (-4)
#define VDOREC_ERR_ROOT_DIR_FULL    (-5)
#define  MMI_ANALOG_TV_DEFAULT_CHANNEL   1
#define  MMI_ANALOG_TV_DEFAULT_AREA   ANALOG_TV_AREA_CHINA

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern wgui_inline_item wgui_inline_items[];
extern BOOL r2lMMIFlag;
 BOOL r2lMMIFlag02=FALSE;
extern kal_bool mmi_tv_test_on;  

 kal_bool mmi_tv_ssc_test_on = KAL_FALSE; 
/****************************************************************************
* Global Function                                                           
*****************************************************************************/

#ifndef MMI_ON_WIN32
//Huyanwei Add It
extern kal_int16 TLGAPP_GetChannelIndex(kal_uint16 channel);
int  TLGAPP_GetTVSSI(kal_uint16 * sigindicate);
int   TLGAPP_GetTotalGain(kal_uint16 * totalGain);
int   TLGAPP_GetTFCalCode(kal_uint16 *TFCalCode);

int   TLGAPP_GetSSI_FOR_TEST( );
#endif


extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);
extern kal_uint8 GpioCtrlReq(kal_uint8 action);
extern BOOL IsClamClose(void);
extern void AudioStopReq(U16 soundId);
extern U16 GetCurKeypadTone(void);
extern void refresh_status_icon_display(void);  /* in Wgui_status_icons.c */
/*bw_20070427 9:52:40  add analog tv auto test*/
extern U8 FM_Polling_current_test_item(void);
extern U8 FM_Polling_analogtv_test_item(void);
extern vdorec_menu_context_struct g_vdorec_menu_cntx;
extern vdorec_context_struct g_vdorec_cntx;
extern vdoply_context_struct g_vdoply_cntx;

/***************************************************************************** 
* Local Variable
*****************************************************************************/

mmi_analog_tv_context_struct g_analog_tv_cntx;
mmi_analog_tv_menu_context_struct g_analog_tv_menu_cntx;
mmi_AnalogTv_data_struct  g_AnalogTv_data;

static U16 main_tv_option_highlighted_item_text;	
U16 mmi_tv_max_index;
U16 mmi_tv_search_count;

U16 mmi_tv_all_valid_channels=0;  
static S8   index_of_valid_channel=-1;
#define MAX_NAME_INPUT_LEN  21 
static UI_character_type name_text_editor_buffer[MAX_NAME_INPUT_LEN];
static UI_character_type name_inline_editor_buffer[MAX_NAME_INPUT_LEN];
static UI_character_type freq_inline_editor_buffer[MAX_NAME_INPUT_LEN];
static BOOL channel_name_edit_done;
static U16 select_area_highlighted_item_index;
static U16 select_mode_highlighted_item_index; 
static U16 channel_list_highlighted_item_index;
static U16 channel_option_highlighted_item_text;
static U16 channel_name_edit_option_highlighted_item_text;
static void (*analog_tv_search_all_channels_callback_func)(void);
static kal_bool g_analog_tv_acc = KAL_TRUE;
static kal_uint32 g_analog_tv_brightness = 128; //0;
static kal_uint32 g_analog_tv_contrast = 128; //0;
static kal_uint32 g_analog_tv_saturation = 128;  //0;
static kal_uint32 g_analog_tv_hue = 0;
static kal_bool    g_set_channel_permit_flag=KAL_TRUE;

static void mmi_analog_tv_searching_abort( void );
static void mmi_analog_tv_search_all_channels_stop();
static void mmi_analog_tv_lcd_split_hdlr(void);
static void mmi_analog_draw_panel_volume(void);
static void mmi_analog_speed_inc_key_press(void);
static void mmi_analog_speed_dec_key_press(void);

static void mmi_analog_channel_inc_key_press(void);
static void mmi_analog_channel_inc_key_release(void);
static void mmi_analog_channel_dec_key_press(void);
static void mmi_analog_channel_dec_key_release(void);
static void mmi_analog_draw_panel_speed(void);

U8  mmi_get_all_channels_of_current_district(void);
static void mmi_analog_speed_dec_key_release(void);
static void mmi_analog_speed_inc_key_release(void);
static void mmi_analog_tv_draw_search(void);
void mmi_tv_save_channel_LSK(void);
void mmi_analog_tv_save_channel_list(void);
static void mmi_analog_tv_power_up(void);
static void mmi_analog_tv_power_down(void);
#if defined(__MMI_ANALOG_TV_SHOW_PROMPT__)
static void isopentv(void);
#endif

static void mmi_analog_tv_entry_app(void);
static void mmi_analog_tv_exit_app(void);
static void mmi_analog_tv_switch_channel_entry_app(void);
static void mmi_analog_tv_switch_channel_exit_app(void);
static void mmi_analog_tv_entry_sublcd_screen(void);
static void mmi_analog_tv_exit_sublcd_screen(void);
static void mmi_analog_tv_blt_screen(void);
static U8 mmi_analog_tv_clam_close_event_hdlr(void *ptr);
static U8 mmi_analog_tv_battery_status_interrupt_hdlr(void *inMsg);
static U8 mmi_analog_tv_post_interrupt_hdlr(void *inMsg);
static void mmi_analog_tv_draw_panel(void);
static void mmi_analog_tv_draw_panel_state(void);
static void mmi_analog_tv_draw_panel_timer(void);
static void mmi_analog_tv_draw_osd(void);
static void mmi_analog_tv_draw_status(void);
static void mmi_analog_tv_draw_hint(void);
static void mmi_analog_tv_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, video_style_text_struct *style_txt);

//static void mmi_analog_tv_init_panel(void);
static void mmi_analog_tv_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id);

 void mmi_analog_tv_enter_state(U16 state);
static void mmi_analog_tv_draw_color_status(void);
static void mmi_analog_tv_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id);
static void mmi_analog_tv_draw_softkey(void);
static void mmi_analog_tv_lsk_press_hdlr(void);
static void mmi_analog_tv_lsk_release_hdlr(void);
static void mmi_analog_tv_rsk_release_hdlr(void);
static void mmi_analog_tv_rsk_press_hdlr(void);
static void mmi_analog_tv_entry_option_screen(void);
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)
static void mmi_analog_tv_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_analog_tv_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj);
#endif
 void mmi_analog_tv_init_panel(void);
static void mmi_analog_tv_ck_press_hdlr(void);
static void mmi_analog_tv_ck_release_hdlr(void);
static void mmi_analog_tv_start_preview(void);
static void mmi_analog_tv_entry_save_confirm_screen(void);
static void mmi_analog_tv_save_confirm_no(void);
static void mmi_analog_tv_save_confirm_forward_to(void);
static void mmi_analog_tv_entry_saving_screen(void);
static void mmi_analog_tv_disply_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id);
static void mmi_analog_tv_exit_saving_screen(void);
static U8 mmi_analog_tv_saving_screen_del_hdlr(void *dummy_ptr);

 BOOL mmi_analog_tv_check_and_display_error_popup(void);
static void mmi_analog_tv_record_result_hdlr_callback(MDI_RESULT result);
static void mmi_analog_tv_save_result_hdlr_callback(MDI_RESULT result);
static void mmi_analog_tv_init_option_menu(void);
static void mmi_analog_tv_highlight_to_vdoply(void);
static void mmi_analog_tv_highlight_rec_setting(void);
static void mmi_analog_tv_entry_rec_setting_screen(void);
static void mmi_analog_tv_exit_rec_setting_screen(void);
static void mmi_analog_tv_rec_setting_lsk_press(void);
static void mmi_analog_tv_rec_setting_highlight_hdlr(S32 index);
static void mmi_analog_tv_highlight_play_setting(void);
static void mmi_analog_tv_entry_play_setting(void);
static void mmi_analog_tv_highlight_district_select(void);
static void mmi_analog_tv_store_district_select(void);
static void mmi_analog_tv_highlight_acc(void);
static void mmi_analog_tv_entry_district_select(void);
static void mmi_analog_tv_store_acc(void);
static void mmi_analog_tv_highlight_bright_level(S32 index);
static void mmi_analog_tv_highlight_brightness(void);
static void mmi_analog_tv_highlight_contrast_level(S32 index);
static void mmi_analog_tv_highlight_saturation_level(S32 index);
static void mmi_analog_tv_bright_lsk_hdlr(void);
static void mmi_analog_tv_saturation_lsk_hdlr(void);
static void mmi_analog_tv_contrast_lsk_hdlr(void);
static void mmi_analog_tv_highlight_saturation(void);
static void mmi_analog_tv_highlight_contrast(void);
static void mmi_analog_tv_power_up(void);
static void mmi_analog_tv_resize_preview_layer(void);
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)
static void mmi_analog_tv_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_analog_tv_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj);
static void mmi_analog_tv_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
#endif
static void mmi_analog_tv_draw_title(void);
static void mmi_analog_tv_inc_volume(void);
static void mmi_analog_tv_dec_volume(void);
static void mmi_analog_tv_press_step_up_button(void);
static void mmi_analog_tv_release_step_up_button(void);
static void mmi_analog_tv_press_step_down_button(void);
static void mmi_analog_tv_release_step_down_button(void);
/*bw070417A 上下方向键改为在channellist中切换 */
static void mmi_analog_tv_channel_step_up_button(void);  
static void mmi_analog_tv_channel_step_down_button(void); 
static void mmi_analog_tv_release_step_down_button(void);
static void mmi_analog_tv_ct_release_hdlr();
static void mmi_analog_tv_ct_press_hdlr(void);
static void mmi_analog_tv_set_storage(void);
static void mmi_analog_tv_entry_storage_screen(void);
static void mmi_analog_tv_highlight_storage(void);
static void mmi_analog_tv_entry_restore_default_confirm_yes(void);
static void mmi_analog_tv_entry_restore_default_confirm_screen(void);
static void mmi_analog_tv_highlight_restore_default(void);
static void mmi_analog_tv_bright_inc_key_release_hdlr(void);
static void mmi_analog_tv_bright_dec_key_release_hdlr(void);
static void mmi_analog_tv_contrast_inc_key_release_hdlr(void);
static void mmi_analog_tv_contrast_dec_key_release_hdlr(void);
static void mmi_analog_tv_saturation_inc_key_release_hdlr(void);
static void mmi_analog_tv_saturation_dec_key_release_hdlr(void);
static void mmi_analog_tv_hue_inc_key_release_hdlr(void);
static void mmi_analog_tv_hue_dec_key_release_hdlr(void);
static U8 mmi_analog_tv_msdc_interrupt_hdlr(void *inMsg);
static U8 mmi_analog_tv_sms_interrupt_hdlr(void *inMsg);
static void mmi_analog_tv_record_timer_cyclic(void);
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_analog_tv_clam_close_event_hdlr(void* ptr);
#endif /* __MMI_CLAMSHELL__ && __MMI_SLIDE__ */

//#define __EV_LCD_WQVGA_RESOLUTION_SUPPORT__
//#define __EV_TV_PATH_BY_VIDEO__
// #define __ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__
 
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
static U8 	gIsAnalogTvFullScreen = 0;  // 1: full screen 0: normal screen 
static U8        gIsWideScreenDisply=0;     // 1:400*200   0: 320*240

static void mmi_analog_tv_toggle_fullscreen_display(void);  
static void mmi_analog_tv_toggle_320_240_screen_display(void);
BOOL  mmi_analog_tv_is_full_screen(void);
 BOOL mmi_analog_tv_is_320_240_screen(void);
static void mmi_analog_tv_to_full_screen_screen(void);
/*bw_20070427 9:52:40  add analog tv auto test*/
 void mmi_analog_tv_to_normal_screen_screen(void);
static void mmi_analog_tv_osd_blt_screen(void);
void mmi_analog_tv_get_channlelist_to_current_channel(void);
#if defined(__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)
 void set_analog_tv_full_screen_layer_roate(U8 layerid);//bw_20070419  旋转90
#endif
#endif 
#ifdef __MMI_ANALOG_TV_SIGNAL__	
   void GetSingalIndicate();//bw
#endif

#if defined(TV_RECORD_SUPPORT)
static void mmi_analog_tv_record_entry_app(void) ;
void mmi_analog_tv_record_hilight_app(void);
#endif

//p_6226_m24_bw_z0163
/***************************************************************************************
由于在AnalogTvApp.c 这个文件中用了很多g_vdorec_osd_cntx中变量中的内容,
这样g_vdorec_osd_cntx一有改动
就引起电视界面错乱,为了使他独立,又不能改变更多代码,又
保持与原来的一致性,,特用g_vdorec_osd_cntx02替代g_vdorec_osd_cntx

***************************************************************************************/
void mmi_analog_tv_register_num_keys(void);

//added by huanglin for play analog TV via BT 20071015 start
#define ANALOG_TV_VIA_BT

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__) && defined(ANALOG_TV_VIA_BT)
extern void aud_bt_hfp_set_audio_path_off(void);
extern void aud_bt_hfp_set_audio_path_on(void);
static int g_analog_tv_via_bt=0;


void get_bt_a2dp_output_state( int * bt_state )
{
	//if( true == AM_IsBluetoothOn() )
	//	*bt_state = 1;
	//else
		*bt_state = 0;
	//return 0;
}

void  mmi_analog_tv_bt_hfp_on(void)
{
	get_bt_a2dp_output_state(&g_analog_tv_via_bt);
	if(1 == g_analog_tv_via_bt)
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r TV in bt mode ... \n");
#endif
		mmi_profiles_bt_connect_sco(aud_bt_hfp_set_audio_path_on);	
	}
	else
	{
		mdi_tlg_tv_open_path();
	}
}

void  mmi_analog_tv_bt_hfp_off(void)
{
	if(1 == g_analog_tv_via_bt)
	{
		aud_bt_hfp_set_audio_path_off();
		mmi_profiles_bt_disconnect_sco();
		g_analog_tv_via_bt = 0;
	}
}


BOOL mmi_ananlog_tv_if_power_on(void)
{
	return  g_AnalogTv_data.g_analog_tv_enable;
}

#endif
//added by huanglin for play analog TV via BT 20071015 end


 kal_uint8 mmi_analog_tv_get_selected_mode(void)
{
    return  g_AnalogTv_data.ModeSelected;
}
 
static void mmi_analog_tv_set_selected_mode(kal_uint16 sm)
{
    g_AnalogTv_data.ModeSelected= sm;
    return;
}
static kal_uint16 mmi_analog_tv_get_selected_district(void)
{
    return  g_AnalogTv_data.DistrictSelected;
}

static void mmi_analog_tv_set_selected_district(kal_uint16 sf)
{
    g_AnalogTv_data.DistrictSelected= sf;
    return;
}



void mmi_analog_tv_store_district_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ds;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ds =  select_area_highlighted_item_index;

    if (g_AnalogTv_data.DistrictSelected != ds)
	{
  /*bw_20070418 20:07:24 将美国从地区列表中分开*/
  /*bw_20070515 19:36:11 整理更新地区列表*/
    if(ds >=0 && ds <ANALOG_TV_AREA_TOTALNUM)
    {
        mmi_analog_tv_set_selected_district(ds);
    }
    else
    {
        
        ASSERT(0);
    }

		//g_AnalogTv_data.g_current_channel=MMI_ANALOG_TV_DEFAULT_CHANNEL;
		mmi_tv_max_index=mmi_get_all_channels_of_current_district();

		memset(g_AnalogTv_data.ChannelList,0,NVRAM_ANALOG_TV_CHANNEL_SIZE);
		mmi_analog_tv_save_channel_list();
		mmi_analog_tv_get_channlelist_to_current_channel(); //lgadd

		memset(g_AnalogTv_data.name[0] ,0,NVRAM_ANALOG_TV_CHANNEL_SIZE*ANALOG_TV_CHANNEL_NAME_LEN*2);
                 /*bw070717 [ALL][ALL] TV频道存储*/
		WriteRecord( NVRAM_ANALOG_TV_CHANNEL_NAME_LID, 1, (void*)g_AnalogTv_data.name[0], NVRAM_ANALOG_TV_NAME_SIZE, &error );

		WriteValue(NVRAM_ANALOG_TV_DISTRICT_SELECT, &g_AnalogTv_data.DistrictSelected, DS_SHORT, &error);
	}

    mmi_analog_tv_disply_popup((PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        ST_NOTIFYDURATION,
        SUCCESS_TONE);
    DeleteNHistory(1);
   // // TODO: store setting here

   
}
static kal_bool mmi_analog_tv_get_acc(void)
{
    return g_analog_tv_acc;
}

static void mmi_analog_tv_set_acc(kal_bool acc)
{
    g_analog_tv_acc = acc;
    return;
}

static kal_uint32 mmi_analog_tv_get_brightness(void)
{
    return g_analog_tv_brightness;
}

static void mmi_analog_tv_set_brightness(kal_uint32 bri)
{
    g_analog_tv_brightness = bri;
    return;
}
static kal_uint32 mmi_analog_tv_get_contrast(void)
{
    return g_analog_tv_contrast;
}

static void mmi_analog_tv_set_contrast(kal_uint32 cntst)
{
    g_analog_tv_contrast = cntst;
    return;
}
static kal_uint32 mmi_analog_tv_get_saturation(void)
{
    return g_analog_tv_saturation;
}

static void mmi_analog_tv_set_saturation(kal_uint32 sa)
{
    g_analog_tv_saturation = sa;
    return;
}

static kal_uint32 mmi_analog_tv_get_hue(void)
{
    return g_analog_tv_hue;
}

static void mmi_analog_tv_set_hue(kal_uint32 hue)
{
    g_analog_tv_hue= hue;
    return;
}

void mmi_analog_tv_get_channlelist_to_current_channel(void)
{
	S16 error;
	U16 freq;
     /*bw070717 [ALL][ALL] TV频道存储*/
#ifndef MMI_ON_WIN32
  	ReadRecord( NVRAM_ANALOG_TV_CHANNEL_LID, 1, (void*)g_AnalogTv_data.ChannelList, NVRAM_ANALOG_TV_CHANNEL_SIZE, &error );
  	//memset( g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM );
	freq= g_AnalogTv_data.ChannelList[0];
	if( freq == 0 )
		g_AnalogTv_data.g_current_channel=MMI_ANALOG_TV_DEFAULT_CHANNEL;
	else
		g_AnalogTv_data.g_current_channel=freq;
#endif		
		
}	

/*****************************************************************************
 * FUNCTION
 *  mmi_analog_tv_init_app
 * DESCRIPTION
 *  init vdorec applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_analog_tv_init_app(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*msz00137*/

	SetHiliteHandler(MENU_ID_ANALOG_TV_ENTRY, mmi_analog_tv_hilight_app);

#if defined(TV_RECORD_SUPPORT)
	//Huyanwei Add It 
	SetHiliteHandler(MENU_ID_ANALOG_TV_RECORD_ENTRY, mmi_analog_tv_record_hilight_app);
#endif				

#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r  ==============>   mmi_analog_tv_init_app() <===============\n");
#endif
	#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
	SetHiliteHandler(MENU_ID_ANALOG_TV_ENTRY_MAINMENU, mmi_analog_tv_hilight_app);//zrb_bw
	#endif

	g_analog_tv_cntx.state							= ANALOG_TV_STATE_EXIT;
	g_analog_tv_cntx.last_error					= MDI_RES_VDOREC_SUCCEED;
	g_analog_tv_cntx.is_saving						= FALSE;
	g_analog_tv_cntx.is_sub_display				= FALSE;
	g_analog_tv_cntx.is_setting_loaded			= FALSE;

      /*analog tv  default setting */
	g_AnalogTv_data.g_current_channel=MMI_ANALOG_TV_DEFAULT_CHANNEL;
	g_AnalogTv_data.is_power_on=FALSE;
       g_AnalogTv_data.g_analog_tv_enable=FALSE;
	//memset(g_AnalogTv_data.tlg_related_info->ChannelList, 0, ANALOG_TV_CHANNEL_NUM);
   /* Init Option Menu */
        mmi_analog_tv_init_option_menu();
}


kal_uint8  mmi_get_analog_tv_current_channel(void)
{

  return  g_AnalogTv_data.g_current_channel;
}

kal_uint8 mmi_get_analog_tv_selected_district(void)
{
 return  g_AnalogTv_data.DistrictSelected;
}


BOOL  mmi_get_analog_tv_current_state(void)   
{
        
         if( g_AnalogTv_data.g_analog_tv_enable)
		return  KAL_TRUE;
         else
		return  KAL_FALSE;
}
/*modify for TV 大电流by James  11.11.08*/
void  mmi_set_analog_tv_current_state(kal_uint8 uState)   
{
        
          g_AnalogTv_data.g_analog_tv_enable=uState;

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

void mmi_analog_tv_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r  ==============>  mmi_analog_tv_hilight_app <===============\n");
#endif
    #if defined(__MMI_ANALOG_TV_SHOW_PROMPT__)	
	SetLeftSoftkeyFunction(isopentv, KEY_EVENT_UP);
    SetKeyHandler(isopentv, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#else
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif



}



#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It 
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

void mmi_analog_tv_record_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    SetLeftSoftkeyFunction(mmi_analog_tv_record_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_record_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	
}


#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_touch_scr_hit_test
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
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__) 
static BOOL mmi_analog_tv_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj)
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
#endif /* defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)  */ 

static void mmi_analog_vol_up_key_press(void)
{
	S16 error;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\r inc volume  = %d, mute=%d \n", g_AnalogTv_data.volume, g_analog_tv_cntx.is_mute );
   #endif
		if(g_analog_tv_cntx.is_mute == TRUE)
		{
			mdi_tlg_tv_mute(0);
			mdi_tlg_tv_set_volume(g_AnalogTv_data.volume ); 
			g_analog_tv_cntx.is_mute = FALSE;
			WriteValue( NVRAM_ANALOG_TV_VOLUME_MUTE, &g_analog_tv_cntx.is_mute, DS_BYTE, &error );//P_6226_M24_bw_z0149
		}
		else if(g_AnalogTv_data.volume < LEVEL7)
		{
			g_AnalogTv_data.volume++;
			mdi_tlg_tv_set_volume(g_AnalogTv_data.volume );
			WriteValue( NVRAM_ANALOG_TV_VOLUME, &g_AnalogTv_data.volume, DS_BYTE, &error );
				
		}
		else
		{
			return;
		}

	g_analog_tv_cntx.is_vol_inc_key_pressed = TRUE; 	
	
       mmi_analog_draw_panel_volume();  // draw parts ,zrb
	mmi_analog_tv_blt_screen();
}
static void mmi_analog_vol_down_key_press(void)
{
	S16 error;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\rdec volume  = %d, mute=%d \n", g_AnalogTv_data.volume, g_analog_tv_cntx.is_mute );
   #endif
		if(g_analog_tv_cntx.is_mute == TRUE)
		{
			return;
		}
		
		if(g_AnalogTv_data.volume > LEVEL1)
		{
			g_AnalogTv_data.volume--;
			mdi_tlg_tv_set_volume(g_AnalogTv_data.volume );
			WriteValue( NVRAM_ANALOG_TV_VOLUME, &g_AnalogTv_data.volume, DS_BYTE, &error );
		//	mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_vdoply_cntx.cur_status.volume);	
		}
		else if(g_AnalogTv_data.volume == LEVEL1)
		{
			g_analog_tv_cntx.is_mute = TRUE;
			mdi_tlg_tv_mute(1);
			WriteValue( NVRAM_ANALOG_TV_VOLUME_MUTE, &g_analog_tv_cntx.is_mute, DS_BYTE, &error );//P_6226_M24_bw_z0149
			
		}
	
	g_analog_tv_cntx.is_vol_dec_key_pressed = TRUE; 	

	mmi_analog_draw_panel_volume();

	mmi_analog_tv_blt_screen();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_analog_tv_volume_increase_handle
 * DESCRIPTION
 *  volume key handle event,increase volume function
 * PARAMETERS
 *  
 * RETURNS
 *  void
 * bw added 0320.07
 *****************************************************************************/
void mmi_analog_tv_volume_increase_handle()
{
	mmi_analog_vol_up_key_press();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_analog_tv_volume_decrease_handle
 * DESCRIPTION
 *   volume key handle event,decrease volume function
 * PARAMETERS
 *  
 * RETURNS
 *  void
 * bw added  0320.07
 *****************************************************************************/
void mmi_analog_tv_volume_decrease_handle()
{
	mmi_analog_vol_down_key_press();
}
/*****************************************************************************
 * FUNCTION
 * mmi_analog_tv_volume_handle_release
 * DESCRIPTION

 * bw_20070511 添加  vol按键up的处理
 *****************************************************************************/
void mmi_analog_tv_volume_handle_release(U8 index)
{
	switch (index)
    	{
    		case ANALOG_TV_TOUCH_VOLUME_INC:
		g_analog_tv_cntx.touch_volume_inc.is_press = FALSE;
		g_analog_tv_cntx.is_vol_inc_key_pressed = FALSE;
                    
		mmi_analog_draw_panel_volume();
		mmi_analog_tv_blt_screen();
		break;

	  case ANALOG_TV_TOUCH_VOLUME_DEC:
		g_analog_tv_cntx.touch_volume_dec.is_press = FALSE;
		g_analog_tv_cntx.is_vol_dec_key_pressed = FALSE;
		
		mmi_analog_draw_panel_volume();
		mmi_analog_tv_blt_screen();
		break;
	}
	
	return ;
}
/*****************************************************************************
 * FUNCTION
 * mmi_analog_tv_volume_increase_release
 * DESCRIPTION

 * bw_20070511 添加  vol按键up的处理
 *****************************************************************************/		
void mmi_analog_tv_volume_increase_release()
{
  mmi_analog_tv_volume_handle_release(ANALOG_TV_TOUCH_VOLUME_INC);
}
/*****************************************************************************
 * FUNCTION
 * mmi_analog_tv_volume_decrease_release
 * DESCRIPTION

 * bw_20070511 添加  vol按键up的处理
 *****************************************************************************/
void mmi_analog_tv_volume_decrease_release()
{
	mmi_analog_tv_volume_handle_release(ANALOG_TV_TOUCH_VOLUME_DEC);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)
static void mmi_analog_tv_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*For reuse interface, we do not change the cordinate of g_vdorec.cntx*/
if (g_analog_tv_cntx.state==ANALOG_TV_STATE_PREVIEW_FULLSCREEN)
{
		mmi_analog_tv_toggle_fullscreen_display();
}
else
{
    /* rsk */
    if (mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_rsk))
    {
        mmi_analog_tv_rsk_press_hdlr();
        g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_RSK;
        return;
    }

    /* lsk */
    if (mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_lsk))
    {
        mmi_analog_tv_lsk_press_hdlr();
        g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_LSK;
        return;
    }

	//lgadd
	/* volume inc */
	if(mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_volume_inc))
	{
		if(g_AnalogTv_data.volume >= LEVEL7)
			return;
		
		g_analog_tv_cntx.touch_volume_inc.is_press = TRUE;
		mmi_analog_vol_up_key_press();

		g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_VOLUME_INC;			
		return;				
	}	

	/* volume dec */
	if(mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_volume_dec))
	{
		#ifdef __VDOPLY_FEATURE_VOLUME_MUTE__
			if(g_analog_tv_cntx.is_mute == TRUE)
			{
				return;
			}
		#else /* __VDOPLY_FEATURE_VOLUME_MUTE__ */
			if(g_AnalogTv_data.volume == LEVEL1)
			{
				return;
			}
		#endif /* __VDOPLY_FEATURE_VOLUME_MUTE__ */

		g_analog_tv_cntx.touch_volume_dec.is_press = TRUE;
		mmi_analog_vol_down_key_press();

		g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_VOLUME_DEC;					
		return;		
	}
	/* channel inc */
		if(mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_speed_inc))
		{
			g_analog_tv_cntx.touch_speed_inc.is_press = TRUE;
			mmi_analog_speed_inc_key_press();
			
			g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_SPEED_INC;	
			return;
		}	

		/* channel dec */
		if(mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_speed_dec))
		{
			g_analog_tv_cntx.touch_speed_dec.is_press = TRUE;
			mmi_analog_speed_dec_key_press();

			g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_SPEED_DEC;	
			return;		
		}	

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
	/* toogle full screen  */

	if(mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_fullscreen) ||
	    mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, (vdorec_ui_touch_struct*)(&g_analog_tv_osd_cntx.play_wnd.rect )) )
	{
		#if defined(TV_RECORD_SUPPORT)
			if(GetAnalogTvAppFlags() == 1)
			{
						g_analog_tv_cntx.touch_fullscreen.is_press = TRUE;
						mmi_analog_tv_toggle_fullscreen_display();
						g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_FULLSCREEN;	

			}
		#else
			g_analog_tv_cntx.touch_fullscreen.is_press = TRUE;
			mmi_analog_tv_toggle_fullscreen_display();
			g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_FULLSCREEN;	
		#endif
		
		return;		
	}


//	mmi_analog_tv_toggle_fullscreen_display();
//	return;
	
#endif 

#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It 
if ( GetAnalogTvAppFlags() == 0 )
{
	if((pos.x>= 100) && (pos.x<=145) && (pos.y >= 296) && (pos.y<=320))
	{
		mmi_analog_tv_record_release_hdlr();
		return ;
	}
}
#endif

	}	
}
#endif /* defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__) */


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
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)
static void mmi_analog_tv_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_analog_tv_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

    switch (g_analog_tv_cntx.touch_object)
    {
    	case ANALOG_TV_TOUCH_VOLUME_INC:
		g_analog_tv_cntx.touch_volume_inc.is_press = FALSE;
		g_analog_tv_cntx.is_vol_inc_key_pressed = FALSE;
                         #ifdef TVOUT_SUPPORT
		if(!g_analog_tv_cntx.is_tvout_mode) 
                         #endif
		{
		mmi_analog_draw_panel_volume();
		
		mmi_analog_tv_blt_screen();
		}
		g_analog_tv_cntx.touch_object = VDOPLY_TOUCH_NONE;	
		break;

	case ANALOG_TV_TOUCH_VOLUME_DEC:
		g_analog_tv_cntx.touch_volume_dec.is_press = FALSE;
		g_analog_tv_cntx.is_vol_dec_key_pressed = FALSE;
                        #ifdef TVOUT_SUPPORT
		if(!g_analog_tv_cntx.is_tvout_mode) 
                        #endif
		{
		mmi_analog_draw_panel_volume();
		mmi_analog_tv_blt_screen();
		
		}
		g_analog_tv_cntx.touch_object = VDOPLY_TOUCH_NONE;	
		break;

	case ANALOG_TV_TOUCH_SPEED_INC:
		g_analog_tv_cntx.touch_speed_inc.is_press = FALSE;
		g_analog_tv_cntx.is_speed_inc_key_pressed = FALSE;
		mmi_analog_speed_inc_key_release();
		{
		mmi_analog_draw_panel_speed();
		mmi_analog_tv_blt_screen();
		}
		g_analog_tv_cntx.touch_object = VDOPLY_TOUCH_NONE;	
		break;

	case ANALOG_TV_TOUCH_SPEED_DEC:
		g_analog_tv_cntx.touch_speed_dec.is_press = FALSE;
		g_analog_tv_cntx.is_speed_dec_key_pressed = FALSE;
		mmi_analog_speed_dec_key_release();
                    
		{
		mmi_analog_draw_panel_speed();
		mmi_analog_tv_blt_screen();
                        }
		g_analog_tv_cntx.touch_object = VDOPLY_TOUCH_NONE;	
		break;

        case ANALOG_TV_TOUCH_RSK:
            mmi_analog_tv_rsk_release_hdlr();
            g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_NONE;
            break;

        case ANALOG_TV_TOUCH_LSK:
            mmi_analog_tv_lsk_release_hdlr();
            g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_NONE;
            break;

        case ANALOG_TV_TOUCH_CK:
            mmi_analog_tv_ck_release_hdlr();
            g_analog_tv_cntx.touch_object = ANALOG_TV_TOUCH_NONE;
            break;
        //default:
        //    ASSERT(0);
        //    break;
    }

}
#endif /* defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__) 
static void mmi_analog_tv_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
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
    if (g_analog_tv_cntx.touch_object == VDOREC_TOUCH_NONE)
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
        case VDOREC_TOUCH_RSK:
            if (!mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_rsk))
            {
                /* if move out */
                g_analog_tv_cntx.is_rsk_pressed = FALSE;

                mmi_analog_tv_draw_softkey();
                mmi_analog_tv_blt_screen();

                g_analog_tv_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_LSK:
            if (!mmi_analog_tv_touch_scr_hit_test(pos.x, pos.y, &g_analog_tv_cntx.touch_lsk))
            {
                /* if move out */
                g_analog_tv_cntx.is_lsk_pressed = FALSE;

                mmi_analog_tv_draw_softkey();
                mmi_analog_tv_blt_screen();

                g_analog_tv_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;
    }

}
#endif /* defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)  */ /* __ANALOG_TV_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
* FUNCTION
*	mmi_vdorec_post_interrupt_hdlr
* DESCRIPTION
*  Resume popup, will be called after all interrupt
* PARAMETERS
*	a IN  message pointer (not used)
* RETURNS
*  U8
* GLOBALS AFFECTED
*	nil
*****************************************************************************/
static U8 mmi_vdorec_post_interrupt_hdlr(void* inMsg)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	SetInterruptPopupDisplay(POPUP_ALL_ON);
	return FALSE;
}

/*****************************************************************************
* FUNCTION
*	mmi_vdorec_sms_interrupt_hdlr
* DESCRIPTION
*  Message interrupt hdlr
* PARAMETERS
*	a IN  message pointer (not used)
* RETURNS
*  U8
* GLOBALS AFFECTED
*	nil
*****************************************************************************/
static U8 mmi_analog_tv_sms_interrupt_hdlr(void* inMsg)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_OFF);
    return FALSE;
}
#ifdef __MMI_ANALOG_TV_SIGNAL__

#define __MMI_CUSTOM_ANALOG_TV_SIGNAL_COORDINATE__

#ifdef  __MMI_CUSTOM_ANALOG_TV_SIGNAL_COORDINATE__
#define ANALOG_TV_SIGNAL_OFFSET_X     16
/*bw_20070816 808 all 2.6寸屏的改动*/
#ifdef __MMI_UNI_MAINLCD_240X400__
#define ANALOG_TV_SIGNAL_OFFSET_Y    345
#else
#define ANALOG_TV_SIGNAL_OFFSET_Y    270
#endif
#define ANALOG_SIGNAL_BG_COLOR  pixtel_UI_color(196,243,87)
#define CHANNEL_BG_COLOR  pixtel_UI_color(196,243,87)	
#else
#define ANALOG_TV_SIGNAL_OFFSET_BUTTON   8
#endif
/*****************************************************************************
* FUNCTION
*	show_analogtv_signal
* DESCRIPTION
*  draw analog tv signal 
added by bw 07.03.17
*****************************************************************************/

//bw0717 根据泰景的建议加TV测试项
void mmi_TV_redraw_ChromaValueAndGain( int Chroma,U16 Gain,U16 TFCalCode)
{
	S32 x1 = 0;
	S32 y1 = 225;
	S32 x2;
	S32 y2;
	S32 str_w, str_h;
	color c;
	S8 temp[48];
	UI_character_type channel_str[48];
	sprintf( temp, "Chr: %d   TG: %d   TF: %d", Chroma,Gain,TFCalCode);
	AnsiiToUnicodeString( (S8*)channel_str, (S8*)temp );
	UI_set_font( &MMI_medium_bold_font );
	x2=239; 
	y2=255;
/*bw_20070910b 电视信号测试的显示坐标调整*/
#ifdef __MMI_UNI_MAINLCD_240X400__
	y1=g_analog_tv_osd_cntx.play_wnd.rect.offset_y+g_analog_tv_osd_cntx.play_wnd.rect.height+2;
	y2=y1+30;
#endif
#if(UI_DOUBLE_BUFFER_SUPPORT)
	UI_lock_double_buffer();
#endif
	UI_push_clip();
	UI_push_text_clip();
	UI_set_clip( x1, y1, x2, y2 );
	UI_set_text_clip( x1, y1, x2, y2 );
	if(Chroma) {
	  c = pixtel_UI_color( 0, 255, 0);
	} else {
	  c =pixtel_UI_color( 255, 0, 0);
	}
	UI_fill_rectangle( x1, y1, x2, y2, c);
	UI_set_font( &MMI_medium_bold_font );
      UI_set_text_color(pixtel_UI_color(255,255 ,255));//added by bw ,set font color
	if( r2lMMIFlag )
		UI_move_text_cursor(x2 - 2, y1 + 1 );
	else
		UI_move_text_cursor(x1 +2, y1 + 1 );
	UI_print_text( channel_str );
	UI_pop_text_clip();
	UI_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
	UI_unlock_double_buffer();
	UI_BLT_double_buffer( x1, y1, x2, y2 );
#endif
}
//bw0717 end

#define SIG_BAR_GAP 3
#define SIG_BAR_X 159
#define SIG_BAR_Y 4   /*sk 0810*/

void show_analogtv_signal(U16 sigindicate)
{
       S32  sigwidth,sigheight,x1,x2,y1,y2,maxframe;
	S32  icon_width, icon_height;
	//TLGAPP_GetTVSSI(&sigindicate);

	sigindicate = ( sigindicate + 1)/2;  //MAX singal strength is 8, so rescale to 5.

	pixtel_UI_measure_image(get_image(IMG_ID_TV_SIGNAL), &icon_width, &icon_height);

	pixtel_UI_lock_double_buffer();
	pixtel_UI_push_clip();

	//pixtel_UI_reset_clip();
	//pixtel_UI_set_clip(SIG_BAR_X, SIG_BAR_Y, SIG_BAR_X + icon_width, SIG_BAR_Y + icon_height); //sk 0812
	// RM BY HONGZHE.LIU pixtel_UI_show_image(SIG_BAR_X, SIG_BAR_Y, get_image(IMG_ID_ANALOG_SIGNAL_DISABLE));

	pixtel_UI_reset_clip();

	pixtel_UI_set_clip(SIG_BAR_X, SIG_BAR_Y, SIG_BAR_X + icon_width, SIG_BAR_Y + icon_height);   
	//pixtel_UI_show_image(SIG_BAR_X, SIG_BAR_Y, get_image(IMG_ID_TV_SIGNAL)); //hongzhe.liu change it to follows!
	gdi_image_draw_animation_single_frame(SIG_BAR_X,SIG_BAR_Y,get_image(IMG_ID_TV_SIGNAL),sigindicate);
	
	pixtel_UI_pop_clip();
	pixtel_UI_unlock_double_buffer();
	pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
}
/*****************************************************************************
* FUNCTION
*	GetSingalIndicate
* DESCRIPTION
*  indicate analog tv  signal
* added by bw 07.03.17
*****************************************************************************/
//bw0719 增加单独的TV测试工程命令
extern kal_bool mmi_tv_ssc_test_on; 
void DrawSignalHintOnOsd();

void GetSingalIndicate()
{
	 U16 sigindicate;
//bw0717 根据泰景的建议加TV测试项
	 U16 totalGain;
	 U16 TFCalCode;
	 int chroma;

	U16 data = 0;
	 
	 UI_cancel_timer(GetSingalIndicate);
	 #ifndef MMI_ON_WIN32
	 //Huyanwei Add It
	 TLGAPP_GetTVSSI(&sigindicate);
	 #endif

	 if ( !gIsAnalogTvFullScreen ) 
		 show_analogtv_signal(sigindicate);
	 else {
	 	if ( sigindicate < 2 ) 
		 	DrawSignalHintOnOsd();
	 }
	 
if((mmi_tv_test_on==KAL_TRUE)||(mmi_tv_ssc_test_on==KAL_TRUE))//bw0719 增加单独的TV测试工程命令
{
	 #ifndef MMI_ON_WIN32
	//Huyanwei Add It
	 TLGAPP_GetTotalGain(&totalGain);
	 TLGAPP_GetTFCalCode(&TFCalCode);
	 chroma=TLGAPP_GetSSI_FOR_TEST();
	 #endif
	 mmi_TV_redraw_ChromaValueAndGain(chroma,totalGain,TFCalCode);
}	 	 	 

	UI_start_timer(3000, GetSingalIndicate);
}
#endif
/*bw070417A 上下方向键改为在channellist中切换 */
static U8  mmi_analog_tv_search_current_channel_in_channel_list(void)
{
        U8 i;
	index_of_valid_channel=-1;
	for(i=0;i<mmi_tv_all_valid_channels;i++)
	{
#if defined(NOKE_DEBUG)
		noke_dbg_printf( "ChannelList:%d", g_AnalogTv_data.ChannelList[i] );
#endif		
        	if(g_AnalogTv_data.g_current_channel==g_AnalogTv_data.ChannelList[i])
	       {
	        index_of_valid_channel=i;
		return 1;
	        }	
	}
	return 0;     
}
static void mmi_analog_tv_set_channel_result_handler(U8 ret)
{
 
       g_set_channel_permit_flag=KAL_TRUE; 
	mdi_tlg_tv_end_set_channel();
    //   pixtel_UI_start_timer(5000,mmi_analog_tv_lcd_split_hdlr);
}
static void mmi_analog_tv_press_step_up_button(void)
{

	mmi_analog_tv_channel_step_up_button();
	
#if 0  
     kal_uint8  index,chan,max_index;
     index=TLGAPP_GetChannelIndex(g_AnalogTv_data.g_current_channel);
     max_index=mmi_tv_max_index;
     if(index==max_index) 
	 	chan=TLGAPP_GetChannel(0);
      else 
	 	chan=TLGAPP_GetChannel(++index);

       g_AnalogTv_data.g_current_channel=chan;	
    
    mdi_tlg_tv_set_channel( g_AnalogTv_data.g_current_channel,mmi_analog_tv_set_channel_result_handler);

#endif	
     	 
}
static void  mmi_analog_tv_release_step_up_button(void)
{
  
    //TLGAPP_SetChannel(g_AnalogTv_data.g_current_channel);
    //pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
   // pixtel_UI_start_timer(5000,mmi_analog_tv_lcd_split_hdlr);
}

static void mmi_analog_tv_press_step_down_button(void)
{

	mmi_analog_tv_channel_step_down_button();
	
 #if 0
     kal_uint8  index,chan,max_index;
     index=TLGAPP_GetChannelIndex(g_AnalogTv_data.g_current_channel);
     max_index=mmi_tv_max_index;

	 if(index==0) 
	 chan=TLGAPP_GetChannel(max_index);
      else
	  chan=TLGAPP_GetChannel(--index);	
	 	
       g_AnalogTv_data.g_current_channel=chan;	
   	 
       mdi_tlg_tv_set_channel( g_AnalogTv_data.g_current_channel,mmi_analog_tv_set_channel_result_handler);

#endif


}
static void  mmi_analog_tv_release_step_down_button(void)
{
   
    // TLGAPP_SetChannel(g_AnalogTv_data.g_current_channel);
    // pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
   //  pixtel_UI_start_timer(5000,mmi_analog_tv_lcd_split_hdlr);
}
/*bw070417A 上下方向键改为在channellist中切换 */
static void mmi_analog_tv_channel_step_up_button(void)  
{
   //kal_uint8  index;
   if(mmi_analog_tv_search_current_channel_in_channel_list()==0)
   	{
         g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[0];
	 
   	}	
   else
      {
          ASSERT(index_of_valid_channel!=-1);
       
         if(index_of_valid_channel==mmi_tv_all_valid_channels-1) 
          {
	   g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[0];
         }
	 else
	 {
	   g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[index_of_valid_channel+1];
	 }
       }
      
       mdi_tlg_tv_set_channel( g_AnalogTv_data.g_current_channel,mmi_analog_tv_set_channel_result_handler);
   	
}

static void mmi_analog_tv_channel_step_down_button(void)  //pjq  070417
{
 //  kal_uint8  index;
   if(mmi_analog_tv_search_current_channel_in_channel_list()==0)
   	{
        g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[0];

   	}	
   else
      {
         ASSERT(index_of_valid_channel!=-1);
     
         if(index_of_valid_channel==0) 
          {
	   g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[mmi_tv_all_valid_channels-1];
          }
	 else
	 {
	   g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[index_of_valid_channel-1];
	 }
       }
      
       mdi_tlg_tv_set_channel( g_AnalogTv_data.g_current_channel,mmi_analog_tv_set_channel_result_handler);
   	
}


/*****************************************************************************
* FUNCTION
*	mmi_vdorec_battery_status_interrupt_hdlr
* DESCRIPTION
*  Battery status interrput handler
* PARAMETERS
*	a IN  message pointer
* RETURNS
*  U8
* GLOBALS AFFECTED
*	nil
*****************************************************************************/
static U8 mmi_vdorec_battery_status_interrupt_hdlr(void* inMsg)
{
#ifndef MMI_ON_WIN32
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	mmi_eq_battery_status_ind_struct *p=(mmi_eq_battery_status_ind_struct*) inMsg;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	switch(p->battery_status)
	{
		case PMIC_CHARGER_IN:
		case PMIC_CHARGER_OUT:
		case PMIC_CHARGE_COMPLETE:
			SetInterruptPopupDisplay(POPUP_ALL_OFF);
			break;
		default:
		break;
	}	
#endif /* !MMI_ON_WIN32 */
	return FALSE; /* return false will process defualt hdlr */
}

/*****************************************************************************
* FUNCTION
*	mmi_TV_in_msdc_interrupt_hdlr
* DESCRIPTION
*  Memory card interrupt handler.
* PARAMETERS
*	a IN  message pointer (not used)
* RETURNS
*  U8
* GLOBALS AFFECTED
*	nil
*****************************************************************************/
static U8 mmi_analog_tv_msdc_interrupt_hdlr(void* inMsg)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if storage is phone, do not need popup */
    if (mmi_vdoply_get_storage() == MMI_PUBLIC_DRV)    //MMI_VDOPLY_STORAGE_PHONE
        SetInterruptPopupDisplay(POPUP_ALL_OFF);

    return FALSE;
}
/*****************************************************************************
* FUNCTION
*	 mmi_analog_tv_clam_close_event_hdlr()
* DESCRIPTION
*   handle clam close event 
* PARAMETERS
*	 ptr   IN	    message data ptr
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && !defined(MMI_ON_WIN32)
static U8 mmi_analog_tv_clam_close_event_hdlr(void* ptr)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	mmi_eq_gpio_detect_ind_struct *gpioDetectInd;
	
	gpioDetectInd = (mmi_eq_gpio_detect_ind_struct *)ptr;
	
	if((gpioDetectInd->gpio_device == EXT_DEV_CLAM_CLOSE) || 
		(gpioDetectInd->gpio_device == EXT_DEV_CLAM_OPEN) )
	{
		
		if(gpioDetectInd->gpio_device == EXT_DEV_CLAM_CLOSE)
		{
			GoBackHistory();
			return FALSE;	
		}
	}

	/* return false means will pass this interrut to default handler */
	return FALSE;	
}
#endif /* __MMI_CLAMSHELL__ && __MMI_SLIDE__ && !MMI_ON_WIN32 */

#ifdef __MMI_ANALOG_TV_LOGO__

/*****************************************************************************
* FUNCTION
*	DisplayAnalogLogo
* DESCRIPTION
*  
* PARAMETERS
*	nil
* RETURNS
*  void
* GLOBALS AFFECTED
*bw_20070413  添加电视logo
*****************************************************************************/
void DisplayAnalogLogo()
{

    	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
	gdi_layer_reset_clip();
	UI_reset_text_clip();		
       gdi_layer_toggle_double();
       gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
       gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_image_draw_animation_id(g_analog_tv_osd_cntx.play_wnd.rect.offset_x, g_analog_tv_osd_cntx.play_wnd.rect.offset_y,IMG_ID_TV_LOGO, NULL);	
       gdi_layer_pop_and_restore_active();  

	   
       gdi_layer_reset_clip();
	UI_reset_text_clip();		
      gdi_image_draw_id(0, 0, IMG_ID_ANALOG_OSD_BG);
       mmi_analog_tv_draw_title();
       mmi_analog_tv_draw_panel();
      #ifdef __MMI_ANALOG_TV_SIGNAL__	
 /*bw_20070820 all all 进正常播放前有两个白图片*/
 //     GetSingalIndicate();
      #endif
       mmi_analog_tv_set_softkey((PS8)GetString(STR_GLOBAL_OPTIONS),
        (PS8) GetString(STR_GLOBAL_BACK),
        IMG_ID_VDOREC_LSK_OPTION,
        IMG_ID_VDOREC_RSK_BACK,
        0);
      mmi_analog_tv_draw_softkey();
	 
   
      enable_softkey_background();
       reset_softkeys();
	gdi_layer_set_blt_layer(g_analog_tv_cntx.base_layer_handle,g_analog_tv_cntx.preview_layer_handle, 
					g_analog_tv_cntx.osd_layer_handle ,0);
	
	mmi_analog_tv_blt_screen();
	#ifndef MMI_ON_WIN32
	//Huyanwei Add It
	 kal_sleep_task(50);//bw_20070417 修改延长时间延长
	 #endif

}
#endif
/*bw070417A 上下方向键改为在channellist中切换 */
static U8 mmi_analog_tv_get_all_valid_channels(void) //pjq 070417
{
	U8 i;
	
	for(i=0;i<ANALOG_TV_CHANNEL_NUM;i++)
	{
	if(g_AnalogTv_data.ChannelList[i]==0)
		return i;
	}
        return  ANALOG_TV_CHANNEL_NUM;
	
}
//bw0719 增加单独的TV测试工程命令
//#if defined(U806_HUAYI)//bw_20070425c 
/*****************************************************************************
* FUNCTION
*	mmi_entry_tv_idle_screen
* DESCRIPTION
* 

*****************************************************************************/
void mmi_entry_tv_idle_screen()
{
   mmi_analog_tv_entry_app();
}
//#endif
/*bw_20070830 14:10:36  移植28平台振华进入电视前的提示  */
#if defined(__MMI_ANALOG_TV_SHOW_PROMPT__)
//显示部分
void ShowCategoryAlarmScreen(U16 title,U16 title_icon,U16 left_softkey,U16 left_softkey_icon,U16 right_softkey,U16 right_softkey_icon,U8* buffer,S32 buffer_size,U8* history_buffer)
{	
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	dm_data_struct	dm_data;
	S32 l;
	S16	input_type=0;

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	gdi_layer_lock_frame_buffer();

	MMI_menu_shortcut_number=-1;
	MMI_disable_title_shortcut_display=1;
	change_left_softkey(left_softkey,left_softkey_icon);
	change_right_softkey(right_softkey,right_softkey_icon);
	SetupCategoryKeyHandlers();

	MMI_title_string=(UI_string_type)get_string(title);
	MMI_title_icon=(UI_image_type)get_image(title_icon);

	l=UI_strlen((UI_string_type)buffer);
	create_multiline_inputbox_set_buffer((UI_string_type)buffer,buffer_size,l,0);
	register_multiline_inputbox_viewer_keys();
	MMI_multiline_inputbox.flags|=(UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW|UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
	MMI_multiline_inputbox.flags|=UI_MULTI_LINE_INPUT_BOX_AUTO_DISABLE_SCROLLBAR;
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
	MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_TRANSPARENT_BACKGROUND;
#endif

	set_multiline_inputbox_category_history(MMI_CATEGORY74_ID,history_buffer,&input_type);
	gdi_layer_unlock_frame_buffer();

	ExitCategoryFunction=ExitCategory74Screen;
	dm_setup_category_functions(dm_redraw_category_screen,dm_get_category_history,dm_get_category_history_size);
	dm_data.s32ScrId = (S32)GetActiveScreenId();
	dm_data.s32CatId = MMI_CATEGORY74_ID;
	dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
	dm_setup_data(&dm_data);
	dm_redraw_category_screen();	

}
//进入电视前的提示
static void isopentv(void)
{
	PS8 buffer;
	S32 bufferSize;

	EntryNewScreen(SCR_ID_TLG_TV_SEARCHING, NULL, NULL, NULL);

	buffer		= GetString(STR_ID_TLG_TV_ALAMR_INFO);
	bufferSize	= pfnUnicodeStrlen(buffer);

	ShowCategoryAlarmScreen(STR_ID_TLG_TV_ALAMR_TITLE, 
								 0,
								 STR_GLOBAL_OK, 0,
								 STR_GLOBAL_CANCEL,0,
								 (PU8)buffer, bufferSize, NULL);

  SetLeftSoftkeyFunction(mmi_analog_tv_entry_app, KEY_EVENT_UP);
  SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif


extern kal_bool aux_state ;
int InTVScreen = 0 ;

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
extern void Process_TV_G_Sensor(void);
extern void SendMessagesMMIToOne(msg_type MSG_ID );
#endif

#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It 
extern void mmi_tv_record_entry_save_confirm_screen(void);
#endif


unsigned int analog_tv_recording = 0 ;

static void mmi_analog_tv_main(void)
{
		/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S8  buf_filepath[FMGR_PATH_BUFFER_SIZE];
	U8 *guiBuffer;
	U16 cur_storage;
	S32 create_result;
	U8  audio_mode;
#ifdef ISP_SUPPORT
	S32 video_width;
	S32 video_height;
	S32 ui_zoom_limit;
#endif /* ISP_SUPPORT */ 

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	InTVScreen = 1 ;


#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It
	if( GetAnalogTvAppFlags() == 0 )
	{
		 /* allocate storage path by using submenu's buffer */
		g_analog_tv_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);

	       /* if no error. load path into buffer */
	       //mmi_vdoply_get_storage_file_path((PS8) g_analog_tv_cntx.storage_filepath);
	       
		sprintf(buf_filepath, "%c:\\", (U8)'E');
	       mmi_asc_to_ucs2(g_analog_tv_cntx.storage_filepath, buf_filepath);
	       mmi_ucs2cat((PS8)g_analog_tv_cntx.storage_filepath, (PS8)VDOPLY_STORAGE_FILEPATH_PHONE);		   
	       create_result = mmi_vdoply_create_file_dir((PS8) g_analog_tv_cntx.storage_filepath);

		/* check if storage exist or not */
		if (create_result != FS_NO_ERROR)
		{
			if (create_result == FS_WRITE_PROTECTION)
			{
				mmi_analog_tv_disply_popup(
				(PU8) GetString(STR_ID_VDOREC_NOTIFY_WRITE_PROTECTION),
				IMG_GLOBAL_WARNING,
				1,
				ST_NOTIFYDURATION,
				WARNING_TONE);
			}
			else if (create_result == FS_DISK_FULL)
			{
				mmi_analog_tv_disply_popup(
				(PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
				IMG_GLOBAL_WARNING,
				1,
				ST_NOTIFYDURATION,
				WARNING_TONE);
			}
			else if (create_result == FS_ROOT_DIR_FULL)
			{
				mmi_analog_tv_disply_popup(
				(PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
				IMG_GLOBAL_WARNING,
				1,
				ST_NOTIFYDURATION,
				WARNING_TONE);
			}
			else if (create_result == FS_FAT_ALLOC_ERROR)
			{
				mmi_analog_tv_disply_popup(
				(PU8) GetString(FMGR_FS_FAT_ALLOC_ERROR_TEXT),
				IMG_GLOBAL_WARNING,
				1,
				ST_NOTIFYDURATION,
				WARNING_TONE);            
			}
			else
			{
				/* storage not exist */            
				mmi_analog_tv_disply_popup(
				(PU8)GetString(STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY),
				IMG_GLOBAL_WARNING,
				1,
				ST_NOTIFYDURATION,
				WARNING_TONE);
				
			}			
			return ;			
		}
	}
#endif

#if defined(TV_RECORD_SUPPORT)
	if( GetAnalogTvAppFlags() == 0 )
	{
		EntryNewScreen(SCR_ID_TV_IN_APP, mmi_analog_tv_exit_app, mmi_analog_tv_record_entry_app, NULL);
	}
	else
	{
		EntryNewScreen(SCR_ID_TV_IN_APP, mmi_analog_tv_exit_app, mmi_analog_tv_entry_app, NULL);
	}
#else
		EntryNewScreen(SCR_ID_TV_IN_APP, mmi_analog_tv_exit_app, mmi_analog_tv_entry_app, NULL);
#endif

#if defined(NOKE_DEBUG)

	noke_dbg_printf( "\rmmi_analog_tv_entry_app entering \n" );
#endif
	gdi_layer_reset_clip();
	gdi_layer_reset_text_clip();

	entry_full_screen();
	/* enable multi_layer */
	gdi_layer_multi_layer_enable();

	/***************************************************************************** 
	* Create layers 
	*****************************************************************************/

	mmi_analog_tv_to_normal_screen_screen();
	mmi_analog_tv_draw_osd(); //hongzhe.liu add

	guiBuffer = GetCurrGuiBuffer(SCR_ID_TV_IN_APP);

	memset(g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM);

	/* load setting */
	mmi_analog_tv_load_setting();


	/*For reuse the interface of MOD_MED*/
	if (guiBuffer == NULL)
	{
		/* each time newly enter vdorec, zoom will be reset to default */
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n Huyanwei Debug  guiBuffer= NULL %s=%d\r\n",__FILE__,__LINE__);
#endif
		g_analog_tv_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
		g_analog_tv_cntx.zoom_limit = 40;
		mmi_analog_tv_get_channlelist_to_current_channel(); //lgadd	//p_6226_m24_bw_z0167 修改来电话时在回到此界面频道改变	
#ifdef __MMI_ANALOG_TV_LOGO__
		DisplayAnalogLogo();
#endif

#ifdef __MMI_ANALOG_TV_SIGNAL__	
		GetSingalIndicate();
#endif
	}

	/* init some golbal value */
	g_analog_tv_cntx.last_error= MDI_RES_VDOREC_SUCCEED;
	g_analog_tv_cntx.record_time= 0;
	g_analog_tv_cntx.is_lsk_pressed = FALSE;
	g_analog_tv_cntx.is_rsk_pressed = FALSE;
	g_analog_tv_cntx.is_ck_pressed = FALSE;
	g_analog_tv_cntx.is_zoom_in_key_pressed = FALSE;
	g_analog_tv_cntx.is_zoom_out_key_pressed = FALSE;
	g_analog_tv_cntx.is_ev_inc_key_pressed = FALSE;
	g_analog_tv_cntx.is_ev_dec_key_pressed = FALSE;
	
	g_AnalogTv_data.g_analog_tv_enable=TRUE;	 //ISP
	/*bw070417A 上下方向键改为在channellist中切换 */
	mmi_tv_all_valid_channels=mmi_analog_tv_get_all_valid_channels();


#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It For TV Record 
#if defined(NOKE_DEBUG)
       noke_dbg_printf("\r\n Huyanwei Add It For Debug  %s=%d\r\n",__FILE__,__LINE__);
#endif
	g_analog_tv_cntx.state =  ANALOG_TV_STATE_PREVIEW ;

	if( GetAnalogTvAppFlags() == 0 )
	{
		g_AnalogTv_data.g_analog_tv_enable=FALSE ;	 //ISP
		analog_tv_recording = 1 ;
      }
#endif


	/*******************************************************************
	* Init proper global state for video applcation  
	********************************************************************/
	/* force all playing keypad tone off */
	AudioStopReq(GetCurKeypadTone());

	/* disable key pad tone */
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

	/* enable multi_layer */
	//gdi_layer_multi_layer_enable();

	/* suspend background play */
	mdi_audio_suspend_background_play();

	/* disalbe align timer */
	UI_disable_alignment_timers();

	/* stop LED patten */
	GpioCtrlReq(MMIAPI_DEV_CTRL_GET);

	/* 
	This is used to solve a very rare situation.	When playing a IMELODY 
	with backlight on/off, and the screen previous to this screen is a 
	horizontal screen. Before enter this screen, the IMELODY turn off the
	backlight. While exit previous screen, the layer rotate back to normal
	size and the content is not correct. So when calling TurnOnBacklight, 
	LCD is in sleepin state and draw wrong content to LCD.
	So we need to clear the buffer first to avoid this situation.
	*/
	gdi_layer_clear(GDI_COLOR_BLACK);

	/* stop MMI sleep */
	TurnOnBacklight(0);

	/* use medium font */
	UI_set_font(&MMI_medium_font);

	/***************************************************************************** 
	* register interrupt event hdlr
	*****************************************************************************/
#ifndef MMI_ON_WIN32
	/* bettery */
	SetInterruptEventHandler(mmi_analog_tv_battery_status_interrupt_hdlr,mmi_analog_tv_post_interrupt_hdlr,MSG_ID_MMI_EQ_BATTERY_STATUS_IND);
#endif /* MMI_ON_WIN32 */ 

	/* msg */
	SetInterruptEventHandler(mmi_analog_tv_sms_interrupt_hdlr,mmi_analog_tv_post_interrupt_hdlr,PRT_MSG_ID_MMI_SMS_DELIVER_MSG_IND);
	SetInterruptEventHandler(mmi_analog_tv_sms_interrupt_hdlr,mmi_analog_tv_post_interrupt_hdlr, PRT_MSG_ID_MMI_SMS_STATUS_REPORT_IND);
	SetInterruptEventHandler(mmi_analog_tv_sms_interrupt_hdlr,mmi_analog_tv_post_interrupt_hdlr,PRT_MSG_ID_MMI_SMS_MSG_WAITING_IND);

#ifndef MMI_ON_WIN32
	/* memory card */
	SetInterruptEventHandler(mmi_analog_tv_msdc_interrupt_hdlr,mmi_analog_tv_post_interrupt_hdlr,MSG_ID_FMT_MMI_CARD_PLUG_IN_IND);
	SetInterruptEventHandler(mmi_analog_tv_msdc_interrupt_hdlr,mmi_analog_tv_post_interrupt_hdlr,MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND);
#endif /* MMI_ON_WIN32 */


#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && !defined(MMI_ON_WIN32)
	/* register event hdlr */
	SetInterruptEventHandler(mmi_analog_tv_clam_close_event_hdlr, NULL, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif /* __MMI_CLAMSHELL__ && __MMI_SLIDE__ && !MMI_ON_WIN32 */

	/* hook to touch screen callback */
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__) 
	mmi_wgui_register_pen_down_handler(mmi_analog_tv_touch_scr_pen_down_hdlr);
	mmi_wgui_register_pen_up_handler(mmi_analog_tv_touch_scr_pen_up_hdlr);
	mmi_wgui_register_pen_move_handler(mmi_analog_tv_touch_scr_pen_move_hdlr);
#endif /* defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__)  */ 

	/****************************************************************************
	* draw skin                                                                 
	*****************************************************************************/
	mmi_analog_tv_init_panel();

	/* start preview */ 
	//forrest: and this will power on the TLG1100 via the image sensor drvier interface
	//So we needn't to send out a power up req obviously.
	g_analog_tv_cntx.last_error = mdi_video_rec_power_on();

	mmi_analog_tv_enter_state(ANALOG_TV_STATE_PREVIEW);

	/*setup the audio */
#if defined(NOKE_DEBUG)
	//noke_dbg_printf( "mmi_analog_tv_entry_app:: mute status = %d , volume=%d\n\r" , g_analog_tv_cntx.is_mute,g_AnalogTv_data.volume );
#endif
	if(g_analog_tv_cntx.is_mute==FALSE) //P_6226_M24_bw_z0149 modified: volume set mute, still phonate when fist entry
	{  
		mdi_tlg_tv_mute(0);
		mdi_tlg_tv_set_volume(g_AnalogTv_data.volume ); 
	}
	else
		mdi_tlg_tv_mute(1);


#if !defined(TV_RECORD_SUPPORT)

	if(FALSE == mmi_analog_tv_check_and_display_error_popup())
	{
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)  && defined(ANALOG_TV_VIA_BT)
		mmi_analog_tv_bt_hfp_on();//added by huanglin for play analog TV via BT 20071015
#else
		mdi_tlg_tv_open_path();
#endif
		//kal_sleep_task( 1000000000000000);
	}
	
#endif

#if 1
	#ifndef WIN32
	//Huyanwei Add it
	if( aux_state == 0 )
	{
		AFE_TurnOnExtAmplifier();//hongzhe.liu add 20080125
	}
	else
	{
		AFE_TurnOffExtAmplifier();//hongzhe.liu add 20080125
	}		
	#endif
#endif	
#if defined(NOKE_DEBUG)

	noke_dbg_printf( "\rmmi_analog_tv_entry_app exit \n" );
#endif
#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
	SendMessagesMMIToOne(MSG_ID_GSENSOR_ON);
#endif
}

/*****************************************************************************
* FUNCTION
*	mmi_vdorec_entry_app
* DESCRIPTION
*  video record app entry point
* PARAMETERS
*	nil
* RETURNS
*  void
* GLOBALS AFFECTED
*	nil
*****************************************************************************/
static int EntryAnalogTvApp = 1; // 1 For TV Play , 0 For TV Record 

int GetAnalogTvAppFlags(void)
{
	return EntryAnalogTvApp;
}


void SetAnalogTvAppFlags(int data)
{
	EntryAnalogTvApp = data ;
}


static void mmi_analog_tv_entry_app(void)
{
		#if 1
		SetAnalogTvAppFlags(1); // TV Play 
		#else
		SetAnalogTvAppFlags(0); // TV record
		#endif
		mmi_analog_tv_main();
}


static void mmi_analog_tv_record_entry_app(void)
{
		SetAnalogTvAppFlags(0); // TV Record
		mmi_analog_tv_main();
}



#if 1
//Huyanwei Add It  For OutSide InterFace
void mmi_entry_analog_tv(void)
{
	mmi_analog_tv_entry_app() ;
}
#endif



extern void power_off_analog_tv(void);
extern void AnalogTV_PowerOff_Close_I2C_Leakage(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_exit_app
 * DESCRIPTION
 *  TV Recorder ext function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U8  audio_mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef WIN32
	//Huyanwei Add It
	AFE_TurnOffExtAmplifier();//hongzhe.liu add 20080125
	#endif
	g_analog_tv_cntx.state = ANALOG_TV_STATE_EXIT;
	mmi_tv_ssc_test_on=KAL_FALSE;  //bw0719 增加单独的TV测试工程命令

#if defined(TV_RECORD_SUPPORT)
	if( GetAnalogTvAppFlags() == 0 )
	{
		mdi_video_rec_record_stop();
	}
	else
	{
		#ifndef WIN32
		//Huyanwei Add It
		media_cam_stop(MOD_MMI);
		#endif
	}
#else
       #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__) 
          mdi_video_rec_preview_stop();
       #elif defined(__EV_TV_PATH_BY_VIDEO__)
          mdi_video_rec_preview_stop();
       #else	       
		#ifndef WIN32
		//Huyanwei Add It
		media_cam_stop(MOD_MMI);
		#endif
       #endif /*__EV_LCD_WQVGA_RESOLUTION_SUPPORT__*/ 
#endif
	   

	/* retore default state */
	g_vdorec_cntx.state = VDOREC_STATE_EXIT;
//P_6226_M38_bw_Z0001 解决从TV出来后漏电问题     
#ifndef WIN32
//Huyanwei Add It
        analog_tv_Mute(1);
        kal_sleep_task(10);
#endif


#if 1
//Huyanwei Add It 
	power_off_analog_tv();
#endif

	mdi_video_rec_power_off();

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
   if(mmi_analog_tv_is_full_screen())
    {
		gIsAnalogTvFullScreen = 0;
	mmi_analog_tv_to_normal_screen_screen();
    }
#endif 

   g_AnalogTv_data.g_analog_tv_enable=KAL_FALSE;
    audio_mode=mdi_audio_get_audio_mode();
    if(audio_mode==AUD_MODE_NORMAL)
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);	
   mdi_tlg_tv_mute(1);//P_6226_M38_bw_Z0001 解决从TV出来后漏电问题 
  // pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);

	leave_full_screen();

    gdi_layer_flatten_to_base(g_analog_tv_cntx.base_layer_handle,
        g_analog_tv_cntx.preview_layer_handle,
        g_analog_tv_cntx.osd_layer_handle,
        0);

    /* free layers */
    gdi_layer_free(g_analog_tv_cntx.preview_layer_handle);
    g_analog_tv_cntx.preview_layer_handle = 0;

    /* free osd layer */
    gdi_layer_free(g_analog_tv_cntx.osd_layer_handle);
    g_analog_tv_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

    /* free buffer */
    mmi_frm_scrmem_free((void*)g_analog_tv_cntx.osd_layer_buf_ptr);
    g_analog_tv_cntx.osd_layer_buf_ptr = NULL;

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

#ifndef MMI_ON_WIN32
    /* un-hook clam close msg */
    SetInterruptEventHandler(NULL, NULL, MSG_ID_MMI_EQ_GPIO_DETECT_IND);
#endif /* MMI_ON_WIN32 */ 

#ifdef __MMI_ANALOG_TV_SIGNAL__
	UI_cancel_timer(GetSingalIndicate); //bw added
#endif

	gdi_layer_clear(GDI_COLOR_BLACK);	
	/* set lcm rotate to default */
	gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
	/* rotate base layer back to normal */
	gdi_layer_resize(UI_device_width, UI_device_height);
	
	enable_softkey_background();
	reset_softkeys();//reset softkeys 	
	
	/* restore to base layer only */
	gdi_layer_set_blt_layer(g_analog_tv_cntx.base_layer_handle, 0, 0, 0);
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)  && defined(ANALOG_TV_VIA_BT)
	mmi_analog_tv_bt_hfp_off();//added by huanglin for play analog TV via BT 20071015
#endif

#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add it 
    /* free buffer */
   if(GetAnalogTvAppFlags() == 0)
   {
   	gui_free(g_analog_tv_cntx.storage_filepath);
       g_analog_tv_cntx.storage_filepath = NULL;
   }
#endif

#ifndef MMI_ON_WIN32
//Huyanwei Add It
	kal_sleep_task(10);
#endif

	InTVScreen = 0 ;

#if 1
	// 解决从TV出来后漏电问题     
	AnalogTV_PowerOff_Close_I2C_Leakage();
#endif

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
	SendMessagesMMIToOne(MSG_ID_GSENSOR_OFF);
#endif

	analog_tv_recording = 0 ;

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\n\rmmi_analog_tv_exit_app ... \n\r" );
#endif	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_switch_channel_exit_app
 * DESCRIPTION
 *  TV Recorder ext function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_switch_channel_exit_app(void) //P_6226_M37_bw_Z0006  换台和插拔视频线处理
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    if (g_analog_tv_cntx.state == ANALOG_TV_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_analog_tv_cntx.state == ANALOG_TV_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
    }
    else if (g_analog_tv_cntx.state == ANALOG_TV_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
    }

    g_analog_tv_cntx.state = ANALOG_TV_STATE_EXIT;

    mmi_vdorec_store_setting();
    mdi_video_rec_power_off();

 
	
    /* cancel active timer */
	UI_cancel_timer(mmi_analog_tv_record_timer_cyclic);
	//pixtel_UI_cancel_timer(mmi_vdorec_hide_hint);

#ifdef __VDOREC_FEATURE_ZOOM__
		//pixtel_UI_cancel_timer(mmi_vdorec_zoom_in);
		//pixtel_UI_cancel_timer(mmi_vdorec_zoom_out);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

}

static void mmi_analog_tv_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
   if(mmi_analog_tv_is_full_screen())
    #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
     gdi_layer_blt_previous(0, 0, 400 - 1, UI_device_width - 1);  
    #else 
    gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
    #endif
   else
#endif 
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}

static void mmi_analog_tv_osd_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
   //if(mmi_analog_tv_is_full_screen())
    //gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
   //else
#endif 
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
//	gdi_layer_blt_previous( 0 , 	
//						223,
//						UI_device_width - 1, 
//						UI_device_height - 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_clam_close_event_hdlr
 * DESCRIPTION
 *  handle clam close event
 * PARAMETERS
 *  ptr     [IN]        Message data ptr
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && !defined(MMI_ON_WIN32)
static U8 mmi_analog_tv_clam_close_event_hdlr(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct *gpioDetectInd;

    gpioDetectInd = (mmi_eq_gpio_detect_ind_struct*) ptr;

    if ((gpioDetectInd->gpio_device == EXT_DEV_CLAM_CLOSE) || (gpioDetectInd->gpio_device == EXT_DEV_CLAM_OPEN))
    {

        if (gpioDetectInd->gpio_device == EXT_DEV_CLAM_CLOSE)
        {
            GoBackHistory();
            return FALSE;
        }
    }

    /* return false means will pass this interrut to default handler */
    return FALSE;
}
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && !defined(MMI_ON_WIN32) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_battery_status_interrupt_hdlr
 * DESCRIPTION
 *  Battery status interrput handler
 * PARAMETERS
 *  inMsg       [?]         
 *  a(?)        [IN]        Message pointer
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_analog_tv_battery_status_interrupt_hdlr(void *inMsg)
{
#ifndef MMI_ON_WIN32
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_battery_status_ind_struct *p = (mmi_eq_battery_status_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (p->battery_status)
    {
        case PMIC_CHARGER_IN:
        case PMIC_CHARGER_OUT:
        case PMIC_CHARGE_COMPLETE:
            SetInterruptPopupDisplay(POPUP_ALL_OFF);
            break;
        default:
            break;
    }
#endif /* MMI_ON_WIN32 */ 
    return FALSE;   /* return false will process defualt hdlr */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_post_interrupt_hdlr
 * DESCRIPTION
 *  Resume popup, will be called after all interrupt
 * PARAMETERS
 *  inMsg       [?]         
 *  a(?)        [IN]        Message pointer (not used)
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_analog_tv_post_interrupt_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_ON);
    return FALSE;
}
//lgadd
void mmi_TV_redraw_current_channel( void )
{
	S32 x1 = g_analog_tv_osd_cntx.panel.speed.offset_x; 
	S32 y1 = g_analog_tv_osd_cntx.panel.speed.offset_y;
	S32 x2 = x1;
	S32 y2 = y1;
	S32 str_w, str_h;
	color color_temp;
	S8 temp[8];
	UI_character_type channel_str[8];
	S32 churrent_channel = g_AnalogTv_data.g_current_channel;
	sprintf( temp, "%02d", churrent_channel );
	AnsiiToUnicodeString( (S8*)channel_str, (S8*)temp );
	UI_set_font( &MMI_small_font );//p_6226_m24_bw_z0166  解决频道背景残缺问题
	UI_measure_string( channel_str, &str_w, &str_h );
	x2+=str_w+3; //4
	y2+=str_h+2;
#if(UI_DOUBLE_BUFFER_SUPPORT)
	UI_lock_double_buffer();
#endif

	// background & time
	UI_push_clip();
	UI_push_text_clip();
	//UI_set_clip( x1, y1, x2, y2 );
	//UI_set_text_clip( x1, y1, x2, y2 );
	UI_set_clip( 93, 230, 136, 286 );                 //changed by hongzhe.liu
	UI_set_text_clip( 93, 230, 136, 286 );        //changed by hongzhe.liu

#ifdef __MMI_CUSTOM_ANALOG_TV_SIGNAL_COORDINATE__	
	color_temp =  CHANNEL_BG_COLOR;//p_6226_m24_bw_z0156
#else
	color_temp = pixtel_UI_color( 245, 0, 0);
#endif

	//UI_fill_rectangle( x1, y1, x2, y2, color_temp);
	gdi_image_draw_id(
         93,
        227,
        IMG_ID_VDOPLY_OSD_TIMER_BG); //sk 0810
	//UI_fill_rectangle( 116, 260, 136, 286, color_temp); //changed by hongzhe.liu
	UI_set_font( &MMI_small_font );
	//UI_fill_rectangle(0, 0/*MMI_status_bar_height*/,UI_device_width, UI_device_height-MMI_button_bar_height,c);

	//c = pixtel_UI_color( 0, 245, 0);

	UI_set_text_color(pixtel_UI_color(255,255,255));//added by bw ,set font color
	UI_measure_string( channel_str, &str_w, &str_h );
	if( r2lMMIFlag )
		UI_move_text_cursor(x2 - 2, y1 + 1 );
	else
		UI_move_text_cursor(x1 +2, y1 + 1 );
	UI_print_text( channel_str );
	UI_pop_text_clip();
	UI_pop_clip();

#if(UI_DOUBLE_BUFFER_SUPPORT)
	UI_unlock_double_buffer();
//	UI_BLT_double_buffer( x1, y1, x2, y2 );
#endif
}
//speed

static void mmi_analog_draw_panel_speed(void)
{
   	//gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);

	 mmi_TV_redraw_current_channel();

		/* speed inc */
		if( (g_analog_tv_cntx.touch_speed_inc.is_press) || 
			 (g_analog_tv_cntx.is_speed_inc_key_pressed) )
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.speed_inc.offset_x,
									g_analog_tv_osd_cntx.panel.speed_inc.offset_y,
									IMG_ID_ANALOG_TOUCH_OSD_CHANNEL_INC_SEL);			
		}
		else
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.speed_inc.offset_x,
										g_analog_tv_osd_cntx.panel.speed_inc.offset_y,
										IMG_ID_ANALOG_TOUCH_OSD_CHANNEL_INC);		
		}

		/* speed dec */
		if( (g_analog_tv_cntx.touch_speed_dec.is_press) || 
			 (g_analog_tv_cntx.is_speed_dec_key_pressed) )
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.speed_dec.offset_x,
									g_analog_tv_osd_cntx.panel.speed_dec.offset_y,
									IMG_ID_ANALOG_TOUCH_OSD_CHANNEL_DEC_SEL);			
		}
		else
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.speed_dec.offset_x,
										g_analog_tv_osd_cntx.panel.speed_dec.offset_y,
										IMG_ID_ANALOG_TOUCH_OSD_CHANNEL_DEC);		
		}
	
	//gdi_layer_pop_and_restore_active();

}

static void mmi_analog_speed_inc_key_press(void)
{
    if(g_set_channel_permit_flag==KAL_TRUE)
    {
       g_set_channel_permit_flag=KAL_FALSE; 
     //  pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
	mmi_analog_draw_panel_speed();
	mmi_analog_tv_blt_screen();
	mmi_analog_tv_press_step_up_button();

    }
}


/*****************************************************************************
* FUNCTION
*	mmi_vdoply_speed_inc_key_release
* DESCRIPTION
*  speed up key press
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*	nil
*****************************************************************************/

static void mmi_analog_speed_inc_key_release(void)
{
     // mmi_analog_tv_release_step_down_button();
}
/*bw070417A 上下方向键改为在channellist中切换 */
static void mmi_analog_channel_inc_key_press(void)
{

    if(mmi_tv_all_valid_channels==0)   //pjq  070417
   	return;
   
    if(g_set_channel_permit_flag==KAL_TRUE)
    {
       g_set_channel_permit_flag=KAL_FALSE; 
     //  pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
	mmi_analog_tv_channel_step_up_button();
	mmi_analog_draw_panel_speed();
	mmi_analog_tv_blt_screen();
    }
}

static void mmi_analog_channel_inc_key_release(void)
{
                 mmi_analog_draw_panel_speed();
		 mmi_analog_tv_blt_screen();
}

static void mmi_analog_channel_dec_key_press(void)
{


   if(mmi_tv_all_valid_channels==0)   //pjq  070417
   	return;
  if(g_set_channel_permit_flag==KAL_TRUE)
   {
     g_set_channel_permit_flag=KAL_FALSE; 
    // pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
     mmi_analog_tv_channel_step_down_button();
     mmi_analog_draw_panel_speed();
     mmi_analog_tv_blt_screen();
   }
}

static void mmi_analog_channel_dec_key_release(void)
{
          mmi_analog_draw_panel_speed();
          mmi_analog_tv_blt_screen();
}


void ProcessTVChannelUpMessage(void)
{
	static int flags = 0 ;
	if ( (flags == 0) && ( GetActiveScreenId() == SCR_ID_TV_IN_APP  ) )
	{	
		flags = 1 ;	
		mmi_analog_channel_dec_key_press();
#ifndef WIN32 //hongzhe.liu
		delayms(10);		
#endif
		mmi_analog_channel_dec_key_release();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessMusicDownMessage \r\n");
#endif
#ifndef WIN32 //hongzhe.liu
		delayms(10);
#endif
		flags = 0 ;
	}
	return ;
}	

void ProcessTVChannelDownMessage(void)
{
	static int flags = 0 ;
	if ( (flags == 0) && ( GetActiveScreenId() == SCR_ID_TV_IN_APP  ) )
	{	
		flags = 1 ;	
		mmi_analog_channel_inc_key_press();
#ifndef WIN32 //hongzhe.liu
		delayms(10);		
#endif		
		mmi_analog_channel_inc_key_release();
#if defined(NOKE_DEBUG)
		noke_dbg_printf("\r\n ProcessMusicDownMessage \r\n");
#endif
#ifndef WIN32 //hongzhe.liu
		delayms(10);
#endif
		flags = 0 ;
	}
	return ;
}	
//Huyanwei Add It 


/* 2009.05.04 added by hongzhe.liu for m-sensor +  */
void ProcessTVFullScreenMessage(int full_scr)
{
	if(    gIsAnalogTvFullScreen ==  full_scr )
	{
		return;
	}

	mmi_analog_tv_toggle_fullscreen_display();
#ifndef WIN32 
	delayms(10);		
#endif	
}
/* 2009.05.04 added by hongzhe.liu for m-sensor -+  */

/*****************************************************************************
* FUNCTION
*	mmi_vdoply_speed_dec_key_press
* DESCRIPTION
*  down arrow key press hdlr, for speed down
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*	nil
*****************************************************************************/	
static void mmi_analog_speed_dec_key_press(void)
{
   if(g_set_channel_permit_flag==KAL_TRUE)
   {
     g_set_channel_permit_flag=KAL_FALSE; 
    // pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
   mmi_analog_draw_panel_speed();
	mmi_analog_tv_blt_screen();
     mmi_analog_tv_press_step_down_button();

   }
   
	
}

static void mmi_analog_speed_dec_key_release(void)
{
    // mmi_analog_tv_release_step_up_button();
}
/*****************************************************************************
* FUNCTION
*	mmi_analog_channel_refresh_up_handle
* DESCRIPTION
*  redraw panel icon when key up
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*	added by bw
*****************************************************************************/
void mmi_analog_channel_refresh_up_handle()
{
	mmi_analog_draw_panel_speed();
	mmi_analog_tv_blt_screen();
}



#define VOL_BAR_GAP 6
#define VOL_BAR_X 60
#define VOL_BAR_Y 261 /*sk 0810*/
static void mmi_analog_draw_panel_volume_level(void)
{
	S32	icon_width = 0; 
	S32	icon_height = 0;

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\r voluem=%d \n",  g_AnalogTv_data.volume );
#endif
	pixtel_UI_measure_image(get_image(IMG_ID_ANALOG_OSD_VOLUME_1), &icon_width, &icon_height);

	pixtel_UI_lock_double_buffer();
	pixtel_UI_push_clip();

	pixtel_UI_reset_clip();
	pixtel_UI_set_clip(VOL_BAR_X, VOL_BAR_Y, VOL_BAR_X + icon_width, VOL_BAR_Y + icon_height);
	pixtel_UI_show_image(VOL_BAR_X, VOL_BAR_Y, get_image(IMG_ID_ANALOG_OSD_VOLUME_MUTE));
//    changed by hongzhe.liu	pixtel_UI_show_image(VOL_BAR_X, VOL_BAR_Y, get_image(IMG_ID_ANALOG_OSD_VOLUME_DISABLE));
	pixtel_UI_reset_clip();	
//	pixtel_UI_set_clip(VOL_BAR_X, VOL_BAR_Y, VOL_BAR_X + g_AnalogTv_data.volume*VOL_BAR_GAP, VOL_BAR_Y + icon_height);	    
	pixtel_UI_set_clip(VOL_BAR_X, VOL_BAR_Y, VOL_BAR_X + icon_width,  VOL_BAR_Y+icon_height);	    
	pixtel_UI_show_image(VOL_BAR_X, VOL_BAR_Y, get_image(IMG_ID_ANALOG_OSD_VOLUME_1+g_AnalogTv_data.volume));
	pixtel_UI_pop_clip();
	pixtel_UI_unlock_double_buffer();
	pixtel_UI_BLT_double_buffer(0,0,UI_device_width-1,UI_device_height-1);
}


static void mmi_analog_draw_panel_volume(void)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   //	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);

		if(g_analog_tv_cntx.is_mute ) //p_6226_m24_bw_Z0147  when volume is mute ,icon can't  show
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume.offset_x, 
									g_analog_tv_osd_cntx.panel.volume.offset_y,
									IMG_ID_ANALOG_OSD_VOLUME_MUTE);
		}
		else
		{
			mmi_analog_draw_panel_volume_level();

		}

		/* vol inc */
		if( (g_analog_tv_cntx.touch_volume_inc.is_press) || 
			 (g_analog_tv_cntx.is_vol_inc_key_pressed) )
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_inc.offset_x,
									g_analog_tv_osd_cntx.panel.volume_inc.offset_y,
									IMG_ID_ANALOG_TOUCH_OSD_VOLUME_INC_SEL);			
		}
		else
		{
			if(g_AnalogTv_data.volume < LEVEL7)
			{
				gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_inc.offset_x,
										g_analog_tv_osd_cntx.panel.volume_inc.offset_y,
										IMG_ID_ANALOG_TOUCH_OSD_VOLUME_INC);		
			}
			else
			{
					gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_inc.offset_x,
											g_analog_tv_osd_cntx.panel.volume_inc.offset_y,
											IMG_ID_ANALOG_TOUCH_OSD_VOLUME_INC_DIS);	
			}
		}
		/* vol dec */
		if( (g_analog_tv_cntx.touch_volume_dec.is_press) || 
			 (g_analog_tv_cntx.is_vol_dec_key_pressed) )
		{
			gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_dec.offset_x,
									g_analog_tv_osd_cntx.panel.volume_dec.offset_y,
									IMG_ID_ANALOG_TOUCH_OSD_VOLUME_DEC_SEL);			
		}			
		else
		{
			#ifdef __VDOPLY_FEATURE_VOLUME_MUTE__
				if(!g_analog_tv_cntx.is_mute)
				{
					gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_dec.offset_x,
											g_analog_tv_osd_cntx.panel.volume_dec.offset_y,
											IMG_ID_ANALOG_TOUCH_OSD_VOLUME_DEC);		
				}
				else
				{
					gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_dec.offset_x,
											g_analog_tv_osd_cntx.panel.volume_dec.offset_y,
											IMG_ID_ANALOG_TOUCH_OSD_VOLUME_DEC_DIS);	
				}
			#else
				if(g_AnalogTv_data.volume > LEVEL1)
				{
					gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_dec.offset_x,
											g_analog_tv_osd_cntx.panel.volume_dec.offset_y,
											IMG_ID_ANALOG_TOUCH_OSD_VOLUME_DEC);		
				}
				else
				{
					gdi_image_draw_id(g_analog_tv_osd_cntx.panel.volume_dec.offset_x,
											g_analog_tv_osd_cntx.panel.volume_dec.offset_y,
											IMG_ID_ANALOG_TOUCH_OSD_VOLUME_DEC_DIS);	
				}
			#endif /* __VDOPLY_FEATURE_VOLUME_MUTE__ */
		}
	//gdi_layer_pop_and_restore_active();


}
//endlg

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
static void mmi_analog_draw_panel_fullscreen(void)
{
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);

	gdi_image_draw_id(g_analog_tv_osd_cntx.panel.fullscreen.offset_x,
						g_analog_tv_osd_cntx.panel.fullscreen.offset_y,
						IMG_ID_ANALOG_TOUCH_OSD_FULLSCREEN);		//bw 

	gdi_layer_pop_and_restore_active();
}
#endif 

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
static void mmi_analog_tv_draw_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_analog_draw_panel_volume();
    mmi_analog_draw_panel_speed();
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__   
   #if defined(TV_RECORD_SUPPORT)
	   if(GetAnalogTvAppFlags() == 1)
	    mmi_analog_draw_panel_fullscreen();
   #else
	    mmi_analog_draw_panel_fullscreen();
   #endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_panel_state
 * DESCRIPTION
 *  draw panel state (stop, pause, record)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_panel_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_analog_tv_cntx.state)
    {
        case ANALOG_TV_STATE_EXIT:
        case ANALOG_TV_STATE_PREVIEW:
        {
            gdi_image_draw_id(
                5/*g_vdorec_osd_cntx.panel.state.offset_x*/,
                266/*g_vdorec_osd_cntx.panel.state.offset_y*/,
                (U16) (IMG_ID_VDOREC_OSD_STATE_STOP));
        }
            break;

        case ANALOG_TV_STATE_RECORD:
        {
            gdi_image_draw_id(
                5/*g_vdorec_osd_cntx.panel.state.offset_x*/,
                266/*g_vdorec_osd_cntx.panel.state.offset_y*/,
                (U16) (IMG_ID_VDOREC_OSD_STATE_REC));
        }
            break;

        case ANALOG_TV_STATE_PAUSE:
        {
            gdi_image_draw_id(
                5/*g_vdorec_osd_cntx.panel.state.offset_x*/,
                266/*g_vdorec_osd_cntx.panel.state.offset_y*/,
                (U16) (IMG_ID_VDOREC_OSD_STATE_PAUSE));
        }
            break;
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_panel_timer
 * DESCRIPTION
 *  draw panel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_panel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    U32 rec_time;
    // 9 9 2 9 9 2 9 9 
    const int StartPosition = 38 ;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rec_time = (U32) (g_analog_tv_cntx.record_time / 1000);

   /******** draw timer *********/
    hour = rec_time / 3600;
    hour_remain = rec_time % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;
	
    gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
    /* hr */
    gdi_image_draw_id(
        StartPosition/*g_TV_in_cntx.timer.hr_0_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) hour / 10));

    gdi_image_draw_id(
        (StartPosition+9)/*g_TV_in_cntx.timer.hr_1_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) hour % 10));

    gdi_image_draw_id(
        (StartPosition+9*2)/*g_TV_in_cntx.timer.col_0_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_COL));

    /* min */
    gdi_image_draw_id(
        (StartPosition+9*2 + 2)/*g_TV_in_cntx.timer.min_0_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) min / 10));

    gdi_image_draw_id(
        (StartPosition+9*3 + 2)/*g_TV_in_cntx.timer.min_1_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) min % 10));

    gdi_image_draw_id(
       (StartPosition+9*4 + 2)/*g_TV_in_cntx.timer.col_1_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_COL));

    /* sec */
    gdi_image_draw_id(
        (StartPosition+9*4 + 2*2)/*g_TV_in_cntx.timer.sec_0_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) sec / 10));

    gdi_image_draw_id(
        (StartPosition+9*5 + 2*2)/*g_TV_in_cntx.timer.sec_1_offset_x*/,
        266/*g_TV_in_cntx.timer.offset_y*/,
        (U16) (IMG_ID_VDOREC_OSD_TIMER_0 + (U16) sec % 10));

    gdi_layer_pop_and_restore_active();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_osd
 * DESCRIPTION
 *  draw osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_osd(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
	gdi_layer_reset_clip(); /* use full screen clip */
	UI_reset_text_clip();		/* use full screen text clip */

	/* toggle double buffer */
	gdi_layer_toggle_double();
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();

	gdi_layer_reset_clip(); /* use full screen clip */
	UI_reset_text_clip();		/* use full screen text clip */
	/* bg image */
	gdi_image_draw_id(0, 0, IMG_ID_ANALOG_OSD_BG);

	/* drawing */
	mmi_analog_tv_draw_title();
	mmi_analog_tv_draw_panel();	
#ifdef __MMI_ANALOG_TV_SIGNAL__	
	GetSingalIndicate();//bw
#endif
#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It 
	if( GetAnalogTvAppFlags() == 0)
	{
		mmi_analog_tv_draw_panel_timer();
	}
#endif


	mmi_analog_tv_set_softkey((PS8)GetString(STR_GLOBAL_OPTIONS),
	(PS8) GetString(STR_GLOBAL_BACK),
	IMG_ID_VDOREC_LSK_OPTION,
	IMG_ID_VDOREC_RSK_BACK,
	0);//p_6226_m24_bw_z0158 手机电视去掉center key

	mmi_analog_tv_draw_softkey();

	/* clear bg */
	gdi_draw_rect(g_vdorec_osd_cntx02.preview_wnd.rect.offset_x,
				g_vdorec_osd_cntx02.preview_wnd.rect.offset_y,
				g_vdorec_osd_cntx02.preview_wnd.rect.offset_x+g_vdorec_osd_cntx02.preview_wnd.rect.width,
				g_vdorec_osd_cntx02.preview_wnd.rect.offset_y+g_vdorec_osd_cntx02.preview_wnd.rect.height,
	GDI_COLOR_TRANSPARENT);

	//	gdi_layer_pop_and_restore_active();

	enable_softkey_background();
	reset_softkeys();//reset softkeys 

	gdi_layer_set_blt_layer(g_analog_tv_cntx.base_layer_handle,g_analog_tv_cntx.preview_layer_handle, 
				g_analog_tv_cntx.osd_layer_handle ,0);

#ifdef __MMI_ANALOG_TV_SIGNAL__	
	UI_start_timer(3000,GetSingalIndicate);
#endif
	mmi_analog_tv_blt_screen();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_status
 * DESCRIPTION
 *  draw TV recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_osd_vdorec_status_struct *status_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_vdorec_osd_cntx02.status.is_show)
    {
        return;
    }

    status_p = &g_vdorec_osd_cntx02.status;

   /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
   do {                                                                                        \
      if(status_p->##a##.is_show)                                                              \
      {                                                                                        \
         gdi_image_draw_id(status_p->##a##.offset_x+status_p->rect.offset_x,                   \
                           status_p->##a##.offset_y+status_p->rect.offset_y,                   \
                           (U16)(IMG_ID_VDOREC_OSD_##A##_START+g_analog_tv_cntx.setting.##a##+1));\
      }                                                                                        \
   } while(0);

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    DRAW_OSD_ICON(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    //DRAW_OSD_ICON(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    DRAW_OSD_ICON(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    DRAW_OSD_ICON(time_limit, TIME_LIMIT);
#endif 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_title
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    PS8 str_ptr;

    video_rect_struct *bbox_rect_p;

	//return;			//Added by zhul, 2007-10-31, 不显示标题栏
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* display filename */
    if (g_vdorec_osd_cntx02.title.is_draw_app_name)
    {
        bbox_rect_p = &g_vdorec_osd_cntx02.title.rect;

      UI_set_text_clip(
            bbox_rect_p->offset_x,
            bbox_rect_p->offset_y,
            bbox_rect_p->offset_x + bbox_rect_p->width - 1,
            bbox_rect_p->offset_y + bbox_rect_p->height - 1);
		
	if(g_AnalogTv_data.ModeSelected) //p_6226_m24_bw_z0165 模拟电视,有线电视title
        str_ptr = (PS8) GetString(STR_ID_TLG_TV_CATV);
	else
	  str_ptr = (PS8) GetString(STR_ID_TLG_TV_ANALOGTV);	

	#if defined(TV_RECORD_SUPPORT)
	//Huyanwei Add It 
	if(GetAnalogTvAppFlags() == 0 )
		str_ptr = (PS8)GetString(STR_ID_ANALOG_TV_RECORD);
	#endif

     UI_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_vdorec_osd_cntx02.title.v_align == VIDEO_ALIGN_TOP)
        {
            offset_y = 0;
        }
        else if (g_vdorec_osd_cntx02.title.v_align == VIDEO_ALIGN_BOTTOM)
        {
            offset_y = bbox_rect_p->height - str_height;
        }
        else    /* center */
        {
            offset_y = (bbox_rect_p->height - str_height) >> 1;
        }

        offset_y += bbox_rect_p->offset_y;

        if (g_vdorec_osd_cntx02.title.h_align == VIDEO_ALIGN_LEFT)
        {
            offset_x = 0;
        }
        else if (g_vdorec_osd_cntx02.title.h_align == VIDEO_ALIGN_RIGHT)
        {
            offset_x = bbox_rect_p->width - str_width;
        }
        else
        {
            offset_x = (bbox_rect_p->width - str_width) >> 1;
        }

        offset_x += bbox_rect_p->offset_x;

        mmi_analog_tv_draw_style_text(str_ptr, offset_x, offset_y, &g_vdorec_osd_cntx02.title.style_text);
       UI_reset_text_clip();  /* restore clip to full screen */

    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_hint
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_hint(void)
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
    if (!g_vdorec_osd_cntx02.hint.is_show)
    {
        return;
    }

    if (g_analog_tv_cntx.hint1_buf != NULL)
    {
       UI_measure_string((UI_string_type) g_analog_tv_cntx.hint1_buf, &str1_width, &str1_height);

        if (g_analog_tv_cntx.hint2_buf == NULL)
        {
            str1_offset_x = (g_vdorec_osd_cntx02.hint.rect.width - str1_width) >> 1;
            str1_offset_y = (g_vdorec_osd_cntx02.hint.rect.height - str1_height) >> 1;
        }
        else
        {
           UI_measure_string((UI_string_type) g_analog_tv_cntx.hint2_buf, &str2_width, &str2_height);

            str1_offset_x = (g_vdorec_osd_cntx02.hint.rect.width - str1_width) >> 1;

            spacing = g_vdorec_osd_cntx02.hint.rect.height - str1_height - str2_height;
            spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

            str1_offset_y = spacing;

            str2_offset_x = (g_vdorec_osd_cntx02.hint.rect.width - str2_width) >> 1;
            str2_offset_y = spacing * 2 + 1 + str1_height;
        }

        str1_offset_x += g_vdorec_osd_cntx02.hint.rect.offset_x;
        str1_offset_y += g_vdorec_osd_cntx02.hint.rect.offset_y;
        str2_offset_x += g_vdorec_osd_cntx02.hint.rect.offset_x;
        str2_offset_y += g_vdorec_osd_cntx02.hint.rect.offset_y;

        gdi_layer_reset_clip();
        UI_reset_text_clip();

        mmi_analog_tv_draw_style_text(
            g_analog_tv_cntx.hint1_buf,
            str1_offset_x,
            str1_offset_y,
            &g_vdorec_osd_cntx02.hint.style_text);

        if (g_analog_tv_cntx.hint2_buf != NULL)
        {
            mmi_analog_tv_draw_style_text(
                g_analog_tv_cntx.hint2_buf,
                str2_offset_x,
                str2_offset_y,
                &g_vdorec_osd_cntx02.hint.style_text);
        }

        if (g_analog_tv_cntx.fade_time != 0)
        {
            //gui_start_timer(HINT_POPUP_FADE_TIME, mmi_vdorec_hide_hint);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_style_text
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
static void mmi_analog_tv_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, video_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += UI_get_string_width((UI_string_type) str);
    }

    if (style_txt->style == VIDEO_TEXT_STYLE_NORMAL)
    {
       UI_move_text_cursor(offset_x, offset_y);
		UI_set_text_color(pixtel_UI_color(style_txt->r, style_txt->g ,style_txt->b));
	  	UI_print_text((UI_string_type)str);
    }
    else if(style_txt->style == VIDEO_TEXT_STYLE_BORDER)
	{
		UI_move_text_cursor(offset_x, offset_y);
		UI_set_text_color(pixtel_UI_color(style_txt->r, style_txt->g, style_txt->b));
		UI_set_text_border_color(pixtel_UI_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
	  UI_print_bordered_text((UI_string_type)str);
	}
	else if(style_txt->style == VIDEO_TEXT_STYLE_SHADOW)
	{
		UI_move_text_cursor(offset_x+1, offset_y+1);
		UI_set_text_color(pixtel_UI_color(style_txt->style_r, style_txt->style_g ,style_txt->style_b));
	   UI_print_text((UI_string_type)str);	

		UI_move_text_cursor(offset_x, offset_y);	
		UI_set_text_color(pixtel_UI_color(style_txt->r, style_txt->g ,style_txt->b));
	   UI_print_text((UI_string_type)str);	
	}
    else
    {
        MMI_ASSERT(0);
    }

}

void mmi_analog_tv_lcd_split_hdlr(void)
{
  UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);
  // media_cam_set_param(MOD_MMI, CAM_PARAM_RUSUME_LCD_SPLIT, 1);
//UI_start_timer(5000, mmi_analog_tv_lcd_split_hdlr);	
}




#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It  For TV RECORD

#include "VdoRecResDef.h"
#include "VdoRecApp.h"


void mmi_analog_tv_record_press_hdlr(void)
{

    if( (ANALOG_TV_STATE_PREVIEW_FULLSCREEN == g_analog_tv_cntx.state ) || (ANALOG_TV_STATE_PREVIEW ==  g_analog_tv_cntx.state) || (g_analog_tv_cntx.state == ANALOG_TV_STATE_PAUSE ))
   {
	   	
    }
    else
    {

    }

}


void mmi_analog_tv_record_release_hdlr(void)
{
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n huyanwei Debug :  mmi_analog_tv_record_release_hdlr(%d) \r\n",g_analog_tv_cntx.state );
#endif
	if( GetAnalogTvAppFlags() == 0 )
	{
		switch (g_analog_tv_cntx.state )
	       {
	         case ANALOG_TV_STATE_PREVIEW:
	         case ANALOG_TV_STATE_PAUSE:
		  case ANALOG_TV_STATE_PREVIEW_FULLSCREEN:
		  case ANALOG_TV_STATE_PREVIEW_320_240_SCREEN:
		                 mmi_analog_tv_enter_state(ANALOG_TV_STATE_RECORD);
		            break;

	         case ANALOG_TV_STATE_RECORD:
			          mmi_analog_tv_enter_state(ANALOG_TV_STATE_PAUSE);
		            break;
		}	
		
		if(!gIsAnalogTvFullScreen)	
		{
			gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
			mmi_analog_tv_draw_softkey();
			mmi_analog_tv_blt_screen();
			gdi_layer_pop_and_restore_active();
		}	
	}	
}

extern void mmi_analog_tv_record_peview(void);


void mmi_tv_record_get_save_filename(S8 *file_buf_p)
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

            mmi_ucs2ncpy((PS8)file_buf_p, (PS8)	g_analog_tv_cntx.storage_filepath, FMGR_MAX_PATH_LEN);
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

#endif

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
/*bw_20070427 9:52:40  add analog tv auto test*/
 void mmi_analog_tv_enter_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U16 prev_state;
    U8 current_test_item,tv_test_item;
    /*-----f-----------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(NOKE_DEBUG)
    noke_dbg_printf( "\rmmi_analog_tv_enter_state entering\n" );
#endif
    /* flush key event */
    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    /*bw_20070429 9:28:41 add tv auto test*/
    current_test_item=FM_Polling_current_test_item();
    tv_test_item=FM_Polling_analogtv_test_item();

    if((current_test_item==tv_test_item)&&( mmi_tv_test_on==KAL_TRUE))
    {
  
	 ClearKeyHandler(KEY_END,KEY_EVENT_DOWN);
	 SetKeyHandler(GoBackHistory, KEY_END, KEY_EVENT_LONG_PRESS);	
        mmi_analog_tv_register_num_keys();
    }
    else	
    {
    SetKeyHandler(mmi_analog_tv_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_analog_tv_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_analog_tv_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_analog_tv_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);


	#if defined(TV_RECORD_SUPPORT)
	//Huyanwei Add It 
	if( GetAnalogTvAppFlags() == 0 )
	{
		SetKeyHandler(mmi_analog_tv_record_press_hdlr, KEY_ENTER, KEY_EVENT_DOWN);
	       SetKeyHandler(mmi_analog_tv_record_release_hdlr, KEY_ENTER, KEY_EVENT_UP);
	}
	#endif
	
#ifdef MMI_N95_interface //hongzhe.liu 20080122

	SetKeyHandler( mmi_analog_tv_volume_increase_handle, KEY_VOL_UP, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_analog_tv_volume_increase_release, KEY_VOL_UP, KEY_EVENT_UP );
	SetKeyHandler( mmi_analog_tv_volume_decrease_handle, KEY_VOL_DOWN, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_analog_tv_volume_decrease_release, KEY_VOL_DOWN, KEY_EVENT_UP );

	SetKeyHandler( mmi_analog_tv_volume_increase_handle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_analog_tv_volume_increase_release, KEY_RIGHT_ARROW, KEY_EVENT_UP );
	SetKeyHandler( mmi_analog_tv_volume_decrease_handle, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_analog_tv_volume_decrease_release, KEY_LEFT_ARROW, KEY_EVENT_UP );


	if(g_AnalogTv_data.ModeSelected)
       {
	      SetKeyHandler( mmi_analog_speed_inc_key_press,KEY_UP_ARROW,KEY_EVENT_DOWN);
	      SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_UP_ARROW,KEY_EVENT_UP);
	      SetKeyHandler( mmi_analog_speed_dec_key_press,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
	      SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_DOWN_ARROW,KEY_EVENT_UP);
	}
	else{
		SetKeyHandler( mmi_analog_channel_inc_key_press,KEY_UP_ARROW,KEY_EVENT_DOWN);
		SetKeyHandler( mmi_analog_channel_inc_key_release,KEY_UP_ARROW,KEY_EVENT_UP);
		SetKeyHandler( mmi_analog_channel_dec_key_press,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
		SetKeyHandler( mmi_analog_channel_dec_key_release,KEY_DOWN_ARROW,KEY_EVENT_UP);
	}
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
	SetKeyHandler(mmi_analog_tv_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_DOWN);
#endif

#else //hongzhe.liu 20080122
    // register volume inc, dec handlers   ,modified by bw
 #if defined(U__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)//bw_20070425c   huayi改为上下方向键调音量
    SetKeyHandler( mmi_analog_tv_volume_increase_handle, KEY_UP_ARROW, KEY_EVENT_DOWN );
    SetKeyHandler( mmi_analog_tv_volume_decrease_handle, KEY_DOWN_ARROW, KEY_EVENT_DOWN );
   SetKeyHandler( mmi_analog_tv_volume_increase_release, KEY_UP_ARROW, KEY_EVENT_UP );//bw_20070511 
    SetKeyHandler( mmi_analog_tv_volume_decrease_release, KEY_DOWN_ARROW, KEY_EVENT_UP );//bw_20070511 
#else
    SetKeyHandler( mmi_analog_tv_volume_increase_handle, KEY_VOL_UP, KEY_EVENT_DOWN );
    SetKeyHandler( mmi_analog_tv_volume_decrease_handle, KEY_VOL_DOWN, KEY_EVENT_DOWN );
    SetKeyHandler( mmi_analog_tv_volume_increase_release, KEY_VOL_UP, KEY_EVENT_UP );//bw_20070511 
    SetKeyHandler( mmi_analog_tv_volume_decrease_release, KEY_VOL_DOWN, KEY_EVENT_UP );//bw_20070511 
#endif

#if !defined(U__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)
    /*bw070417A 左右方向键控制音量，防止有些客户没有音量键 */
    SetKeyHandler( mmi_analog_tv_volume_increase_handle, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
    SetKeyHandler( mmi_analog_tv_volume_decrease_handle, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
    SetKeyHandler( mmi_analog_tv_volume_increase_release, KEY_RIGHT_ARROW, KEY_EVENT_UP );//bw_20070511 
    SetKeyHandler( mmi_analog_tv_volume_decrease_release, KEY_LEFT_ARROW, KEY_EVENT_UP );//bw_20070511 
#endif

   //channel  key 	,modified by bw
    /*bw070417A 上下方向键改为在channellist中切换 */
#if defined(__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)//bw_20070425c  huayi 上下音量调频道
      if(g_AnalogTv_data.ModeSelected) //bw_20070605c  有线电视按键切换
       {
      SetKeyHandler( mmi_analog_speed_inc_key_press,KEY_VOL_UP,KEY_EVENT_DOWN);
      SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_VOL_UP,KEY_EVENT_UP);
      SetKeyHandler( mmi_analog_speed_dec_key_press,KEY_VOL_DOWN,KEY_EVENT_DOWN);//
      SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_VOL_DOWN,KEY_EVENT_UP);
	}
	else
	{
     SetKeyHandler( mmi_analog_channel_inc_key_press,KEY_VOL_UP,KEY_EVENT_DOWN);
     SetKeyHandler( mmi_analog_channel_inc_key_release,KEY_VOL_UP,KEY_EVENT_UP);
     SetKeyHandler( mmi_analog_channel_dec_key_press,KEY_VOL_DOWN,KEY_EVENT_DOWN);//
     SetKeyHandler( mmi_analog_channel_dec_key_release,KEY_VOL_DOWN,KEY_EVENT_UP);
	 }
#elif defined(__UNI_MMI_VOL_KEY_TO_CHANNEL__)	//bw_20071012 808w all huayi音量键调台上下键调音量
  	if(g_AnalogTv_data.ModeSelected)
	{
	       SetKeyHandler( mmi_analog_speed_inc_key_press,KEY_VOL_DOWN,KEY_EVENT_DOWN);
	       SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_VOL_DOWN,KEY_EVENT_UP);
	       SetKeyHandler( mmi_analog_speed_dec_key_press,KEY_VOL_UP,KEY_EVENT_DOWN);//
	       SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_VOL_UP,KEY_EVENT_UP);
	}
	else
	{
	    	SetKeyHandler( mmi_analog_channel_inc_key_press,KEY_VOL_DOWN,KEY_EVENT_DOWN);
	     	SetKeyHandler( mmi_analog_channel_inc_key_release,KEY_VOL_DOWN,KEY_EVENT_UP);
	     	SetKeyHandler( mmi_analog_channel_dec_key_press,KEY_VOL_UP,KEY_EVENT_DOWN);//
	     	SetKeyHandler( mmi_analog_channel_dec_key_release,KEY_VOL_UP,KEY_EVENT_UP);
	}
      SetKeyHandler( mmi_analog_tv_volume_increase_handle, KEY_UP_ARROW, KEY_EVENT_DOWN );
      SetKeyHandler( mmi_analog_tv_volume_decrease_handle, KEY_DOWN_ARROW, KEY_EVENT_DOWN );
      SetKeyHandler( mmi_analog_tv_volume_increase_release, KEY_UP_ARROW, KEY_EVENT_UP );//bw_20070511 
      SetKeyHandler( mmi_analog_tv_volume_decrease_release, KEY_DOWN_ARROW, KEY_EVENT_UP );
#else
	if(g_AnalogTv_data.ModeSelected)
	{
       SetKeyHandler( mmi_analog_speed_inc_key_press,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
       SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_DOWN_ARROW,KEY_EVENT_UP);
       SetKeyHandler( mmi_analog_speed_dec_key_press,KEY_UP_ARROW,KEY_EVENT_DOWN);//
       SetKeyHandler( mmi_analog_channel_refresh_up_handle,KEY_UP_ARROW,KEY_EVENT_UP);
	}
	else
	{
/*bw_20071015 10:54:38  812_huatang 要求电视上下键功能调整   */
	#ifdef U812_HUATANG  
	 SetKeyHandler( mmi_analog_channel_dec_key_press,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
     SetKeyHandler( mmi_analog_channel_dec_key_press,KEY_DOWN_ARROW,KEY_EVENT_UP);
     SetKeyHandler( mmi_analog_channel_inc_key_release,KEY_UP_ARROW,KEY_EVENT_DOWN);//
     SetKeyHandler( mmi_analog_channel_inc_key_release,KEY_UP_ARROW,KEY_EVENT_UP);
	#else
     SetKeyHandler( mmi_analog_channel_inc_key_press,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
     SetKeyHandler( mmi_analog_channel_inc_key_release,KEY_DOWN_ARROW,KEY_EVENT_UP);
     SetKeyHandler( mmi_analog_channel_dec_key_press,KEY_UP_ARROW,KEY_EVENT_DOWN);//
     SetKeyHandler( mmi_analog_channel_dec_key_release,KEY_UP_ARROW,KEY_EVENT_UP);
	#endif
	}
#endif

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__

/*bw_20070917  u808W huayi 去掉对电视的特殊处理*/
#if defined(U808_HUAYI) && !defined(U808W_HUAYI) || defined(U808_HUAYI_N) && !defined(U808W_HUAYI_N)  //bw_20070425c   huayi 按#全屏切换
	SetKeyHandler(mmi_analog_tv_toggle_fullscreen_display, KEY_POUND, KEY_EVENT_DOWN);
        #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
          if(gIsAnalogTvFullScreen)
	    SetKeyHandler(mmi_analog_tv_toggle_320_240_screen_display, KEY_STAR, KEY_EVENT_DOWN);
        #endif
#else

	if( GetAnalogTvAppFlags() == 1 )
	{
		SetKeyHandler(mmi_analog_tv_toggle_fullscreen_display, KEY_STAR, KEY_EVENT_DOWN);
	}

   #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
    if(gIsAnalogTvFullScreen)
	  SetKeyHandler(mmi_analog_tv_toggle_320_240_screen_display, KEY_POUND, KEY_EVENT_DOWN);
   #endif
   
#endif
	/*bw_20070412 10:39:53 */ //去掉send键切换全屏的功能
	//SetKeyHandler(mmi_analog_tv_toggle_fullscreen_display, KEY_SEND, KEY_EVENT_DOWN);
#endif /* __ANALOG_TV_FEATURE_FULL_SCREEN__ */
#endif /* MMI_N95_interface */
/*bw_20070917  u808W huayi 去掉对电视的特殊处理*/
#if (!defined(U808_HUAYI) && !defined(U808_HUAYI_N)) ||defined(U808W_HUAYI) || defined(U808W_HUAYI_N)    //bw_20070425c   
	mmi_analog_tv_register_num_keys();//added by bw
#else//bw0719 增加单独的TV测试工程命令 解决华易的版本在TV测试模式下不能按数字快捷键
        if(mmi_tv_ssc_test_on==KAL_TRUE)
           mmi_analog_tv_register_num_keys();
#endif

    }
	switch (state)
	{
	case ANALOG_TV_STATE_PREVIEW:
		prev_state = g_analog_tv_cntx.state;
		g_analog_tv_cntx.state = state;
		mmi_analog_tv_draw_osd();
#if defined(TV_RECORD_SUPPORT)		
//Huyanwei Add It 
		mmi_analog_tv_start_preview(); //           mmi_vdorec_start_preview();
#endif
		break;
	case ANALOG_TV_STATE_PREVIEW_FULLSCREEN:
		prev_state = g_analog_tv_cntx.state;
		g_analog_tv_cntx.state = state;

#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__			
		gdi_layer_set_blt_layer(0,g_analog_tv_cntx.preview_layer_handle, 
				g_analog_tv_cntx.osd_layer_handle ,0);
#else 
		gdi_layer_set_blt_layer(0,g_analog_tv_cntx.preview_layer_handle, 
				0 ,0);
#endif

#if defined(__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)
		set_analog_tv_full_screen_layer_roate(1);//bw_20070419  旋转90
#endif
		mmi_analog_tv_blt_screen();
#if defined(TV_RECORD_SUPPORT)		
//Huyanwei Add It 
	      mmi_analog_tv_start_preview(); //           mmi_vdorec_start_preview();
#endif

	break;
	case ANALOG_TV_STATE_PREVIEW_320_240_SCREEN:
		prev_state = g_analog_tv_cntx.state;
		g_analog_tv_cntx.state = state;

#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__			
		gdi_layer_set_blt_layer(0,g_analog_tv_cntx.preview_layer_handle, 
				g_analog_tv_cntx.osd_layer_handle ,0);
#else
		gdi_layer_set_blt_layer(0,/*g_analog_tv_cntx.base_layer_handle,*/g_analog_tv_cntx.preview_layer_handle, 
				0 ,0);
#endif

#if defined(__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)
		set_analog_tv_full_screen_layer_roate(1);//bw_20070419  旋转90
#endif
		mmi_analog_tv_blt_screen();
#if defined(TV_RECORD_SUPPORT)		
//Huyanwei Add It 
	     mmi_analog_tv_start_preview(); //           mmi_vdorec_start_preview();
#endif
	break;
	
#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add it For 

        case ANALOG_TV_STATE_RECORD:
        {
#if defined(NOKE_DEBUG)
	     noke_dbg_printf("\r\n Huyanwei debug  ANALOG_TV_STATE_RECORD   File = %s line = %d \r\n",__FILE__,__LINE__);
#endif		 
            prev_state = g_analog_tv_cntx.state;
            g_analog_tv_cntx.state = state;

            if (prev_state == ANALOG_TV_STATE_PAUSE)
            {
                 g_analog_tv_cntx.last_error = mdi_video_rec_record_resume();
#if defined(NOKE_DEBUG)
		  noke_dbg_printf("\r\n Huyanwei debug prev_state = ANALOG_TV_STATE_PAUSE  File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
                /* 
                 * this may happend Meida send out record finsih message but MMI not receive it,
                 * meanwhile MMI try to pasue.
                 * MDI will ignore this meassge when some one call pause API at this situation, so
                 * MMI has to enter save screen
                 */
                if (g_analog_tv_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
                {
#if defined(NOKE_DEBUG)
                    noke_dbg_printf("\r\n Huyanwei Add It For Debug : mmi_tv_record_entry_save_confirm_screen(before) File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
                    mmi_tv_record_entry_save_confirm_screen();
                    return;					
                }
            }
            else
            {
                {
		      S8 FileBuffer[512]  = { 0 };
		      memset(FileBuffer,0,512);
#if defined(NOKE_DEBUG)
     		      noke_dbg_printf("\r\n Huyanwei debug File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
		      memset(buf_filename,0,FMGR_PATH_BUFFER_SIZE);
                    mmi_tv_record_get_save_filename(buf_filename);                    
			#if 1
			//Huyanwei Add It 		       
			mmi_ucs2_to_asc(FileBuffer,buf_filename);
			FileBuffer[511] = '\0' ;
#if defined(NOKE_DEBUG)
			noke_dbg_printf("\r\n Huyanwei debug FileName = (%s) (0x%x 0x%x 0x%x 0x%x 0x%x 0x%x)\r\n", FileBuffer,
				FileBuffer[0],FileBuffer[1],FileBuffer[2],FileBuffer[3],FileBuffer[4],FileBuffer[5]	);
			#endif
			#endif
                    mmi_fmgr_util_store_filepath(buf_filename, FMGR_PATH_ID_VIDEO);       
#if defined(NOKE_DEBUG)
		      noke_dbg_printf("\r\n Huyanwei debug File = %s line = %d  \r\n",__FILE__,__LINE__);
#endif
                }
                g_analog_tv_cntx.last_error = mdi_video_rec_record_start(buf_filename, mmi_analog_tv_record_result_hdlr_callback);
            }
        }
            /* start draw timer */
            mmi_analog_tv_record_timer_cyclic();
	     return ;			
            break;

        case ANALOG_TV_STATE_PAUSE:
        {
#if defined(NOKE_DEBUG)
      	     noke_dbg_printf("\r\n Huyanwei debug entry ANALOG_TV_STATE_PAUSE  File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
             gui_cancel_timer(mmi_analog_tv_record_timer_cyclic);

            g_analog_tv_cntx.state = state;			
            g_analog_tv_cntx.last_error = mdi_video_rec_record_pause(KAL_FALSE);
			
            /* 
             * this may happend Meida send out record finsih message but MMI not receive it,
             * meanwhile MMI try to pasue.
             * MDI will ignore this meassge when some one call pause API at this situation, so
             * MMI has to enter save screen
             */
            if (g_analog_tv_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
            {
#if defined(NOKE_DEBUG)
                noke_dbg_printf("\r\n Huyanwei Add It For Debug : mmi_tv_record_entry_save_confirm_screen(before) File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
                mmi_tv_record_entry_save_confirm_screen();
            }
            else if (g_analog_tv_cntx.last_error == MDI_RES_VDOREC_DISK_FULL)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_INFO,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }
            else if (g_analog_tv_cntx.last_error == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_SIZE_LIMIT),
                    IMG_GLOBAL_INFO,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }
	     return ;
	 }
        break;
#endif

	default:
		break;
	}

#if !defined(TV_RECORD_SUPPORT)
#if defined(NOKE_DEBUG)
	noke_dbg_printf("\r\n Huyanwei Modify It For before mmi_analog_tv_start_preview() \r\n");
#endif
	/* start preview */
	mmi_analog_tv_start_preview(); //           mmi_vdorec_start_preview();
#endif

	mmi_analog_tv_check_and_display_error_popup();
       //if(FALSE == mmi_analog_tv_check_and_display_error_popup())   //pjqadd  070119
       //pixtel_UI_start_timer(5000,mmi_analog_tv_lcd_split_hdlr);
}
/*****************************************************************************
 * FUNCTION
 *  IsChannelExist
 * DESCRIPTION
 *  check  channelist 
 * RETURNS
 *  void
 * added by bw
 *****************************************************************************/
U8  IsChannelExist()
{
	U8 i;
	
	for(i=0;i<ANALOG_TV_CHANNEL_NUM;i++)
	if(g_AnalogTv_data.ChannelList[i])
		return 1;
	return 0;
		
		
}
/*****************************************************************************
 * FUNCTION
 *  mmi_analog_tv_release_number_key
 * DESCRIPTION
 *  shortcuts key function  on analog tv screen
 * RETURNS
 *  void
 * added by bw
 *****************************************************************************/
void mmi_analog_tv_release_number_key( void )
{
	U16 key_code, key_type,listindex;
	kal_int8  ret;
	U8  current_channel=0;   /*bwB_20070418 优思版本越界，赋初值0*/
	/*bw_20070427 9:52:40  add analog tv auto test*/
	U8  current_test_item=0;
	U8  tv_test_item=0;
	/*bw_20070418 20:12:18  用于生产测试*/
#if defined(U806_UNISCOPE)	 
	GetkeyInfo( (U16*)&key_code, (U16*)&key_type );
	if(key_code==1)
		current_channel=4;  //80M    VHF1
	else if (key_code==2)
		current_channel=10; //current_channel=12;  //219M  VHF2
	else if(key_code==3)		
		current_channel=47;  //786M  UHF

#else
	/*bw_20070427 17:16:55  add for auto test*/	
	current_test_item=FM_Polling_current_test_item();
	tv_test_item=FM_Polling_analogtv_test_item();
	/*bw070530 测试完TV后，按power key退出，再进入电视还是测试模式*/
	//bw0719 增加单独的TV测试工程命令
	if(((current_test_item==tv_test_item)&&( mmi_tv_test_on==KAL_TRUE))||(mmi_tv_ssc_test_on==KAL_TRUE)) //FM_AUTOTEST_ANALOGTV
	{
		GetkeyInfo( (U16*)&key_code, (U16*)&key_type );
		if(key_code==1)
			current_channel=4;  //80M    VHF1
		else if (key_code==2)
			current_channel=10; //current_channel=12;  //219M  VHF2
		else if(key_code==3)		
			current_channel=47;  //786M  UHF
		//bw0717 根据泰景的建议加TV测试项
		else if(key_code==4)
			current_channel=2;	
		else if(key_code==5)
			current_channel=8;	
		else if(key_code==6)
			current_channel=45;	
		else if(key_code==7)
			current_channel=6;	
		else if(key_code==8)
			current_channel=12;	
		else if(key_code==9)
			current_channel=49;		       
	}
	else		
	{
		if(!IsChannelExist())
			return ;
		GetkeyInfo( (U16*)&key_code, (U16*)&key_type );
		listindex=key_code - KEY_1;
		if(listindex<0||listindex>=ANALOG_TV_CHANNEL_NUM)
			return ;	
		current_channel=g_AnalogTv_data.ChannelList[listindex];

	}
#endif
	if( current_channel!= 0 )
	{
	/*bw_20070418 20:28:22 同样的频道不再处理*/
		if(g_AnalogTv_data.g_current_channel!=current_channel)
		{
			g_AnalogTv_data.g_current_channel=current_channel;
			// gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
			mmi_TV_redraw_current_channel();
			/*bw_20070820 all all 进正常播放前有两个白图片*/
			mmi_analog_tv_blt_screen();
			// gdi_layer_pop_and_restore_active();
			//p_6226_m24_bw_z0148  draw channel on base layer 
			mdi_tlg_tv_set_channel( g_AnalogTv_data.g_current_channel,mmi_analog_tv_set_channel_result_handler);//modifid for  keypad  disposal ,bw
		}
	}
	 
}
/*****************************************************************************
 * FUNCTION
 *  mmi_analog_tv_register_num_keys
 * DESCRIPTION
 *  Register Num  KeyHandle
 * RETURNS
 *  void
 * added by bw
 *****************************************************************************/
void mmi_analog_tv_register_num_keys(void)
{
	U16 number_keys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9 };
	S16 error;
      /*bw070717 [ALL][ALL] TV频道存储*/
  	ReadRecord( NVRAM_ANALOG_TV_CHANNEL_LID, 1, (void*)g_AnalogTv_data.ChannelList, NVRAM_ANALOG_TV_CHANNEL_SIZE, &error );
  	//memset( g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM );
	SetGroupKeyHandler( mmi_analog_tv_release_number_key, number_keys, 9, KEY_EVENT_UP );
			
}	
 

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_set_softkey
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
static void mmi_analog_tv_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.lsk_str_ptr = lsk_str_ptr;
    g_analog_tv_cntx.rsk_str_ptr = rsk_str_ptr;

    g_analog_tv_cntx.lsk_img_id = lsk_img_id;
    g_analog_tv_cntx.rsk_img_id = rsk_img_id;
    g_analog_tv_cntx.ck_img_id = ck_img_id;
}


#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It 

#include "VdoRecResDef.h"

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_draw_softkey
 * DESCRIPTION
 *  draw softkey bar (softkey)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_draw_softkey(void)
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
    U16 image_id;

#ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_reset_clip();

#ifndef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    gdi_image_draw_id(
        g_vdorec_osd_cntx02.softkey.rect.offset_x,
        g_vdorec_osd_cntx02.softkey.rect.offset_y,
        IMG_ID_VDOREC_OSD_BUTTOM_BAR_BG);
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    if (g_vdorec_osd_cntx02.softkey.is_lsk_icon == FALSE)
    {
        /* lsk string */
        if (g_analog_tv_cntx.lsk_str_ptr != NULL)
        {
          UI_measure_string((UI_string_type) g_analog_tv_cntx.lsk_str_ptr, &str_width, &str_height);
            lsk_offset_x = 2;
            lsk_offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 1;

            if (g_analog_tv_cntx.is_lsk_pressed)
            {
                lsk_offset_x++;
                lsk_offset_y++;
            }

            mmi_analog_tv_draw_style_text(
                g_analog_tv_cntx.lsk_str_ptr,
                lsk_offset_x,
                lsk_offset_y,
                &g_vdorec_osd_cntx02.softkey.lsk_text);

        #ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__

            touch_p = &g_analog_tv_cntx.touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;

        #endif /* __ANALOG_TV_FEATURE_TOUCH_SCREEN__ */ 
        }
    }
    else
    {
        /* lsk icon */
        if (g_analog_tv_cntx.lsk_img_id != 0)
        {
            if (g_analog_tv_cntx.is_lsk_pressed)
            {
                image_id = g_analog_tv_cntx.lsk_img_id + 1;
            }
            else
            {
                image_id = g_analog_tv_cntx.lsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            lsk_offset_x = g_vdorec_osd_cntx02.softkey.icon_lsk_pos.offset_x;
            lsk_offset_y = g_vdorec_osd_cntx02.softkey.icon_lsk_pos.offset_y;

            gdi_image_draw_id(lsk_offset_x, lsk_offset_y, image_id);

        #ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__

            touch_p = &g_analog_tv_cntx.touch_lsk;
            touch_p->offset_x = lsk_offset_x;
            touch_p->offset_y = lsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;

        #endif /* __ANALOG_TV_FEATURE_TOUCH_SCREEN__ */ 
        }

    }

    if (g_vdorec_osd_cntx02.softkey.is_rsk_icon == FALSE)
    {
        /* rsk string */
        if (g_analog_tv_cntx.rsk_str_ptr != NULL)
        {

          UI_measure_string((UI_string_type) g_analog_tv_cntx.rsk_str_ptr, &str_width, &str_height);
            rsk_offset_x = UI_device_width - str_width - 2;
            rsk_offset_y = (UI_device_height - MMI_button_bar_height) + ((MMI_button_bar_height - str_height) >> 1) + 1;

            if (g_analog_tv_cntx.is_rsk_pressed)
            {
                rsk_offset_x++;
                rsk_offset_y++;
            }

            mmi_analog_tv_draw_style_text(
                g_analog_tv_cntx.rsk_str_ptr,
                rsk_offset_x,
                rsk_offset_y,
                &g_vdorec_osd_cntx02.softkey.lsk_text);

        #ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__

            touch_p = &g_analog_tv_cntx.touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = str_width;
            touch_p->height = str_height;

        #endif /* __ANALOG_TV_FEATURE_TOUCH_SCREEN__ */ 
        }
    }
    else
    {
        /* rsk icon */
        if (g_analog_tv_cntx.rsk_img_id != 0)
        {
            if (g_analog_tv_cntx.is_rsk_pressed)
            {
                image_id = g_analog_tv_cntx.rsk_img_id + 1;
            }
            else
            {
                image_id = g_analog_tv_cntx.rsk_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            rsk_offset_x = g_vdorec_osd_cntx02.softkey.icon_rsk_pos.offset_x;
            rsk_offset_y = g_vdorec_osd_cntx02.softkey.icon_rsk_pos.offset_y;

            gdi_image_draw_id(rsk_offset_x, rsk_offset_y, image_id);

        #ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__

            touch_p = &g_analog_tv_cntx.touch_rsk;
            touch_p->offset_x = rsk_offset_x;
            touch_p->offset_y = rsk_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;

        #endif /* __ANALOG_TV_FEATURE_TOUCH_SCREEN__ */ 
        }

    }

    if (g_vdorec_osd_cntx02.softkey.is_ck_icon)
    {

        /* draw c key */

        if (g_analog_tv_cntx.ck_img_id != 0)
        {
            if (g_analog_tv_cntx.is_ck_pressed)
            {
                image_id = g_analog_tv_cntx.ck_img_id + 1;
            }
            else
            {
                image_id = g_analog_tv_cntx.ck_img_id;
            }

            gdi_image_get_dimension_id(image_id, &img_width, &img_height);

            ck_offset_x = g_vdorec_osd_cntx02.softkey.icon_ck_pos.offset_x;
            ck_offset_y = g_vdorec_osd_cntx02.softkey.icon_ck_pos.offset_y;

            gdi_image_draw_id(ck_offset_x, ck_offset_y, image_id);
        }
    }

   #if defined(TV_RECORD_SUPPORT)
     //Huyanwei Add It 

     if( GetAnalogTvAppFlags() == 0)
     {
	    if( (ANALOG_TV_STATE_PREVIEW ==  g_analog_tv_cntx.state) || (g_analog_tv_cntx.state == ANALOG_TV_STATE_PAUSE ))
	   {
	   	gdi_image_draw_id(100,296,IMG_ID_VDOREC_CK_RECORD);
	    }
	    else
	    {
	    	gdi_image_draw_id(100,296,IMG_ID_VDOREC_CK_PAUSE);		
	    }
     }
	 
   #endif
	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_lsk_press_hdlr
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_lsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_lsk_pressed = TRUE;
 /*bw070919[U808 WQVGA][ALL] 320*240显示时按左软件进入选项重启*/
   if(!gIsAnalogTvFullScreen)	
   {
    gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
    mmi_analog_tv_draw_softkey();
    mmi_analog_tv_blt_screen();
    gdi_layer_pop_and_restore_active();
   }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_lsk_release_hdlr
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_lsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_lsk_pressed = FALSE;
    /*bw070919[U808 WQVGA][ALL] 320*240显示时按左软件进入选项重启*/	
    if(!gIsAnalogTvFullScreen) 
    {
    mmi_analog_tv_draw_softkey();
    mmi_analog_tv_blt_screen();
    }
    mmi_analog_tv_entry_option_screen();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_rsk_press_hdlr
 * DESCRIPTION
 *  rsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_rsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_rsk_pressed = TRUE;
    mmi_analog_tv_draw_softkey();
    mmi_analog_tv_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_rsk_release_hdlr
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_rsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_rsk_pressed = FALSE;
    mmi_analog_tv_draw_softkey();
    mmi_analog_tv_blt_screen();


    switch (g_analog_tv_cntx.state)
    {
        case ANALOG_TV_STATE_PREVIEW:
            GoBackHistory();
            break;

        case ANALOG_TV_STATE_RECORD:
            mdi_video_rec_record_stop();
            UI_cancel_timer(mmi_analog_tv_record_timer_cyclic);

    #ifdef __MMI_VDOREC_MMS_SUPPORT__
            mmi_analog_tv_entry_save_confirm_screen();
    #else 
            mmi_analog_tv_entry_saving_screen();
    #endif 
            break;

        case ANALOG_TV_STATE_PAUSE:
            mdi_video_rec_record_stop();
           UI_cancel_timer(mmi_analog_tv_record_timer_cyclic);

    #ifdef __MMI_VDOREC_MMS_SUPPORT__
            mmi_analog_tv_entry_save_confirm_screen();
    #else 
            mmi_analog_tv_entry_saving_screen();
    #endif 
            break;
    }
  
}

void mmi_tv_select_area_highlight_hdlr( S32 index )
{
	select_area_highlighted_item_index=index;
}

//lgadd
#include "FunAndGamesDefs.h"
PU8 item_texts[ANALOG_TV_AREA_TOTALNUM];
void mmi_tv_entry_select_area(void)
{
//	PU8  item_texts[4];
	U16 item_count, i;
	U8* gui_buffer;
//	U8* item_popups[ANALOG_TV_AREA_TOTALNUM];
	
	U16 selectArea;
	U16 *list_icons1 = NULL;
	U16 *list_icons2 = NULL;

	EntryNewScreen( SCR_ID_TLG_TV_SELECT_AREA, NULL, mmi_tv_entry_select_area, NULL );
	
	gui_buffer = GetCurrGuiBuffer( SCR_ID_TLG_TV_SELECT_AREA );
	item_count=ANALOG_TV_AREA_TOTALNUM;
	/*bw_20070607 添加地区并整理*/
	/*bw_20070515 19:36:11 整理更新地区列表*/
	/*
	item_texts[0]=STR_ID_TLG_TV_CHINA;
	item_texts[1]=STR_ID_TLG_TV_SHENZHEN;
	
	item_texts[ANALOG_TV_EUROPE_START]=STR_ID_TLG_TV_EUROPE;
	item_texts[ANALOG_TV_EUROPE_START+1]=STR_ID_TLG_TV_TURKEY;
	item_texts[ANALOG_TV_EUROPE_START+2]=STR_ID_TLG_TV_UAE;
	item_texts[ANALOG_TV_EUROPE_START+3]=STR_ID_TLG_TV_AFGHANISTAN;
	item_texts[ANALOG_TV_EUROPE_START+4]=STR_ID_TLG_TV_SINGAPORE;
	item_texts[ANALOG_TV_EUROPE_START+5]=STR_ID_TLG_TV_THAILAND;
	item_texts[ANALOG_TV_EUROPE_START+6]=STR_ID_TLG_TV_CAMBODIA;
	item_texts[ANALOG_TV_EUROPE_START+7]=STR_ID_TLG_TV_INDONESIA;
	item_texts[ANALOG_TV_EUROPE_START+8]=STR_ID_TLG_TV_MALAYSIA;
	item_texts[ANALOG_TV_EUROPE_START+9]=STR_ID_TLG_TV_MYANMAR;
	item_texts[ANALOG_TV_EUROPE_START+10]=STR_ID_TLG_TV_LAOS;
	item_texts[ANALOG_TV_EUROPE_START+11]=STR_ID_TLG_TV_SPAIN;
	item_texts[ANALOG_TV_EUROPE_START+12]=STR_ID_TLG_TV_PORTUGAL;
	item_texts[ANALOG_TV_EUROPE_START+13]=STR_ID_TLG_TV_INDIA;

	item_texts[ANALOG_TV_EUROPE_END+1]=STR_ID_TLG_TV_VIETNAM;
	item_texts[ANALOG_TV_EUROPE_END+2]=STR_ID_TLG_TV_HONGKONG;
	item_texts[ANALOG_TV_EUROPE_END+3]=STR_ID_TLG_TV_ENGLAND;
	item_texts[ANALOG_TV_EUROPE_END+4]=STR_ID_TLG_TV_SOUTH_AFRICA;
	item_texts[ANALOG_TV_EUROPE_END+5]=STR_ID_TLG_TV_BRAZIL;
	item_texts[ANALOG_TV_EUROPE_END+6]=STR_ID_TLG_TV_ARGENTINA;
	item_texts[ANLAOG_TV_NTSL_START]=STR_ID_TLG_TV_AMERICA;
	item_texts[ANLAOG_TV_NTSL_START+1]=STR_ID_TLG_TV_CANADA;
	item_texts[ANLAOG_TV_NTSL_START+2]=STR_ID_TLG_TV_KOREA;
	item_texts[ANLAOG_TV_NTSL_START+3]=STR_ID_TLG_TV_TAIWAN;
	item_texts[ANLAOG_TV_NTSL_START+4]=STR_ID_TLG_TV_MEXICO;
	item_texts[ANLAOG_TV_NTSL_START+5]=STR_ID_TLG_TV_CHILE;
	item_texts[ANLAOG_TV_NTSL_START+6]=STR_ID_TLG_TV_VENEZUELA;
	item_texts[ANLAOG_TV_NTSL_START+7]=STR_ID_TLG_TV_PHILIPPINES;
	item_texts[ANLAOG_TV_NTSL_START+8]=STR_ID_TLG_TV_JAPAN;
	*/
	selectArea=mmi_analog_tv_get_selected_district();
	for(i  = 0; i <item_count;i ++)
		item_texts[i ] = (PU8)GetString((U16)(STR_ID_TLG_TV_CHINA + i ));
	
	list_icons1=(U16*)OslMalloc(item_count *sizeof(PU16));
	list_icons2=(U16*)OslMalloc(item_count *sizeof(PU16));
	for(i=0; i<item_count; i++)
	{
		if(i == selectArea)
			list_icons1[i]= IMG_VICON;
		else
			list_icons1[i]= IMAGE_NOIMAGE_THEME;
	}

	for(i=0; i<item_count; i++)
	{
		list_icons2[i]= IMAGE_NOIMAGE_THEME;
	}
	SetParentHandler(MENU_ID_TLG_TV_SELECT_AREA);
//	for( i = 0; i < item_count; i++ )
//		item_popups[i] = NULL;
	

	ShowCategory73Screen(STR_GLOBAL_OPTIONS,MAIN_MENU_TITLE_MULTIMEDIA_ICON,
		STR_GLOBAL_OK,0,
		STR_GLOBAL_BACK,0,
		item_count,(U8**)item_texts,list_icons1,list_icons2,
		(U16)selectArea,gui_buffer,0);
/*	
	ShowCategory52Screen( STR_GLOBAL_OPTIONS, MAIN_MENU_TITLE_MULTIMEDIA_ICON,
		STR_GLOBAL_OK, 0,
		STR_GLOBAL_BACK, 0,
		item_count, item_texts, (PU16)gIndexIconsImageList, (U8**) item_popups, 0, selectArea, gui_buffer );
*/	
	RegisterHighlightHandler( mmi_tv_select_area_highlight_hdlr );
	// register left, right arrow key handlers
	SetKeyHandler( GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_analog_tv_store_district_select, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	
	// register LSK, RSK hanlders
	SetLeftSoftkeyFunction( mmi_analog_tv_store_district_select, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
	if(list_icons1)
		OslMfree(list_icons1);

	if(list_icons2)
		OslMfree(list_icons2);
}
 //P_6226_M14_bw_Z0053 tv添加有线电视的选择菜单
void mmi_analog_tv_store_mode_select()
{
	U16 mode;
	S16 error;
	mode=select_mode_highlighted_item_index;
       /*add func here*/  //pjq
      if(mode!=g_AnalogTv_data.ModeSelected)
      	{
	  mmi_analog_tv_set_selected_mode(mode);
	  WriteValue(NVRAM_ANALOG_TV_MODE_SELECT, &g_AnalogTv_data.ModeSelected, DS_BYTE, &error);
	   mmi_analog_tv_get_channlelist_to_current_channel();//bw_20070605c 有线电视按键切换
      	}
	mmi_analog_tv_disply_popup((PU8) GetString(STR_GLOBAL_DONE),
        IMG_GLOBAL_ACTIVATED,
        1,
        ST_NOTIFYDURATION,
        SUCCESS_TONE);
	
}
void mmi_tv_select_mode_highlight_hdlr(S32 index )
{
	select_mode_highlighted_item_index=index;
}
void mmi_tv_entry_select_mode(void)
{
//	PU8  item_texts[4];
	U16 item_count, i;
	U8* gui_buffer;
	U8* item_popups[2];
	U16 item_texts[2];
	U16 selectmode;
	EntryNewScreen( SCR_ID_TLG_TV_SELECT_MODE, NULL, mmi_tv_entry_select_mode, NULL );
	
	gui_buffer = GetCurrGuiBuffer( SCR_ID_TLG_TV_SELECT_MODE);
	item_count=0;
	item_texts[0]=STR_ID_TLG_TV_ANALOGTV;
	item_count++;
	item_texts[1]=STR_ID_TLG_TV_CATV;
	item_count++;
	SetParentHandler(MENU_ID_TLG_TV_SELECT_MODE);
	for( i = 0; i < item_count; i++ )
		item_popups[i] = NULL;
	selectmode=mmi_analog_tv_get_selected_mode();
	ShowCategory52Screen( STR_GLOBAL_OPTIONS, MAIN_MENU_TITLE_MULTIMEDIA_ICON,
		STR_GLOBAL_OK, 0,
		STR_GLOBAL_BACK, 0,
		item_count, item_texts, (PU16)gIndexIconsImageList, (U8**) item_popups, 0, selectmode, gui_buffer );
	
	RegisterHighlightHandler( mmi_tv_select_mode_highlight_hdlr );
	// register left, right arrow key handlers
	SetKeyHandler( GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_analog_tv_store_mode_select, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	
	// register LSK, RSK hanlders
	SetLeftSoftkeyFunction( mmi_analog_tv_store_mode_select, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
}
//
/*****************************************************************************
* FUNCTION
*     mmi_fmrdo_channel_name_edit_option_highlight_hdlr
* DESCRIPTION
*     
* IMPACT 
*     
* PARAMETERS
*     void
* RETURNS
*     void
* GLOBALS AFFECTED
*     
*****************************************************************************/
void mmi_tv_channel_name_edit_option_highlight_hdlr( S32 index )
{
	U16 item_texts[] = { STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD };
	channel_name_edit_option_highlighted_item_text = item_texts[index];
}

/*****************************************************************************
* FUNCTION
*     mmi_fmrdo_channel_name_edit_option_LSK
* DESCRIPTION
*     
* IMPACT 
*     
* PARAMETERS
*     void
* RETURNS
*     void
* GLOBALS AFFECTED
*     
*****************************************************************************/
void mmi_tv_channel_name_edit_option_LSK( void )
{
	switch( channel_name_edit_option_highlighted_item_text )
	{
		case STR_GLOBAL_DONE:
			pfnUnicodeStrcpy( (S8*)name_inline_editor_buffer, (S8*)name_text_editor_buffer );
			channel_name_edit_done = TRUE;
			GoBackToHistory( SCR_ID_TLG_TV_CHANNEL_EDIT );
			break;
		case STR_GLOBAL_INPUT_METHOD:
			EntryInputMethodScreen();
			break;
	}
}
void mmi_tv_entry_channel_name_edit_option( void )
{
	U16 item_texts[] = { STR_GLOBAL_DONE, STR_GLOBAL_INPUT_METHOD};
	U16 item_icons[] = { IMG_GLOBAL_L1, IMG_GLOBAL_L2 };
	
	EntryNewScreen( SCR_ID_TLG_TV_CHANNEL_NAME_EDIT_OPTION, NULL, NULL, NULL );

	RegisterHighlightHandler( mmi_tv_channel_name_edit_option_highlight_hdlr );

	ShowCategory52Screen( STR_GLOBAL_OPTIONS, MAIN_MENU_TITLE_MULTIMEDIA_ICON, 
		STR_GLOBAL_OK, 0,
		STR_GLOBAL_BACK, 0, 
		2, item_texts, item_icons,
		NULL, 0, 0, NULL );
	
	// register left, right arrow key handlers
	SetKeyHandler( GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_tv_channel_name_edit_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	
	// register LSK, RSK handlers
	SetLeftSoftkeyFunction( mmi_tv_channel_name_edit_option_LSK, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
}
void mmi_Tv_entry_channel_name_edit( void )
{
	U8* gui_buffer;

	EntryNewScreen( SCR_ID_TLG_TV_CHANNEL_NAME_EDIT, NULL, mmi_Tv_entry_channel_name_edit, NULL );

	if( (gui_buffer = GetCurrGuiBuffer( SCR_ID_TLG_TV_CHANNEL_NAME_EDIT)) == NULL )
		pfnUnicodeStrcpy( (S8*)name_text_editor_buffer, (S8*)name_inline_editor_buffer );

	ShowCategory5Screen( STR_GLOBAL_EDIT, MAIN_MENU_TITLE_MULTIMEDIA_ICON,
		STR_GLOBAL_OPTIONS, 0,
		STR_GLOBAL_BACK, 0,
		INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
		(U8*) name_text_editor_buffer, ANALOG_TV_CHANNEL_NAME_LEN-1, 
		gui_buffer );
	
	SetLeftSoftkeyFunction( mmi_tv_entry_channel_name_edit_option, KEY_EVENT_UP );
	SetCategory5RightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
	RegisterInputMethodScreenCloseFunction( GoBackHistory );
}
U16 mmi_tv_get_freq_from_str( UI_string_type input_str )
{
	U16 freq = 0;
	BOOL fraction = FALSE;
	BOOL skip = FALSE;
	BOOL one_digit_dicimal = TRUE;
	S16 i;
	
	for( i = 0; input_str[i] != 0; i++ )
	{
		if( input_str[i] == L'.' )
		{
			if(	(input_str[i+1] != 0) && (input_str[i+2] != 0))
			{
				one_digit_dicimal = FALSE;	
			}
			fraction = TRUE;
		}
		else if( !skip )
		{
			freq = freq * 10 + input_str[i] - L'0';
			if( fraction )
				skip = TRUE;
		}
	}
	
	if( freq != 0 && !skip )
	{
		freq *= 10;
	}

	if(!one_digit_dicimal)
	{
		freq = 	0xffff; /* Only allow one digit after the '.' */
	}

	return freq;
}
void mmi_TV_exit_save_channel_confirm( void )
{
}
void mmi_tv_set_channel( S16 channel_index, U16 freq, UI_string_type name )
{
/*lgadd	if( (g_AnalogTv_data.channel_index == channel_index) && (g_AnalogTv_data.ChannelList[g_fmrdo.channel_index] != freq) )
	{
		g_AnalogTv_data.channel_index = -1;
	}

	if( (g_AnalogTv_data.channel_index == -1)	// && (freq == g_AnalogTv_data.frequency) )
	{
		g_AnalogTv_data.= channel_index;
	}
*/
	pfnUnicodeStrcpy( (S8*)g_AnalogTv_data.name[channel_index], (S8*)name );

//	g_AnalogTv_data.ChannelList[channel_index] = freq;
}

void mmi_tv_save_channel_LSK( void )
{
	S16 error;
	U16 freq = mmi_tv_get_freq_from_str( freq_inline_editor_buffer );
	
	// set channel
	mmi_tv_set_channel( channel_list_highlighted_item_index, freq, name_inline_editor_buffer );

	// write channel list from nvram
	 /*bw070717 [ALL][ALL] TV频道存储*/
	WriteRecord( NVRAM_ANALOG_TV_CHANNEL_NAME_LID, 1, (void*)g_AnalogTv_data.name[0], NVRAM_ANALOG_TV_NAME_SIZE, &error );
	GoBackToHistory( SCR_ID_TLG_TV_CHANNEL_LIST );
}
void mmi_tv_entry_save_channel_confirm( void )
{
	EntryNewScreen( SCR_ID_TLG_TV_SAVE_CHANNEL_CONFIRM, mmi_TV_exit_save_channel_confirm, mmi_tv_entry_save_channel_confirm, NULL );
	
	ShowCategory164Screen( STR_GLOBAL_YES, IMG_GLOBAL_YES,
		STR_GLOBAL_NO,IMG_GLOBAL_NO, 
		STR_GLOBAL_SAVE, IMG_GLOBAL_QUESTION, NULL );

	playRequestedTone( WARNING_TONE );

	SetLeftSoftkeyFunction( mmi_tv_save_channel_LSK, KEY_EVENT_UP );
	SetRightSoftkeyFunction( mmi_tv_save_channel_LSK, KEY_EVENT_UP );
}
void mmi_Tv_exit_clear_channel_confirm( void )
{
}
void mmi_tv_clear_channel_LSK(void)
{
	S16 error;
	U16 item_index;
	item_index=channel_list_highlighted_item_index;
	mmi_tv_set_channel( channel_list_highlighted_item_index, 0, L"" );
//lgadd
	// write channel list from nvram
 /*bw070717 [ALL][ALL] TV频道存储*/
	WriteRecord( NVRAM_ANALOG_TV_CHANNEL_NAME_LID, 1, (void*)g_AnalogTv_data.name[0], NVRAM_ANALOG_TV_NAME_SIZE, &error );
	
	GoBackToHistory( SCR_ID_TLG_TV_CHANNEL_LIST );
}
void mmi_tv_entry_clear_channel_confirm( void )
{
	EntryNewScreen( SCR_ID_TLG_TV_CLEAR_CHANNEL_CONFIRM, mmi_Tv_exit_clear_channel_confirm, mmi_tv_entry_clear_channel_confirm, NULL );
	
	ShowCategory164Screen( STR_GLOBAL_YES, IMG_GLOBAL_YES,
		STR_GLOBAL_NO,IMG_GLOBAL_NO, 
		STR_GLOBAL_CLEAR, IMG_GLOBAL_QUESTION, NULL );

	playRequestedTone( WARNING_TONE );

	SetLeftSoftkeyFunction( mmi_tv_clear_channel_LSK, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
}

void mmi_tv_channel_edit_LSK( void )
{
	// calculate frequency number
	U16 freq = mmi_tv_get_freq_from_str( freq_inline_editor_buffer );
	mmi_tv_entry_save_channel_confirm();
	return;
	// check frequency input
	if( freq_inline_editor_buffer[0] == 0 )
	{
		if( g_AnalogTv_data.ChannelList[(U16) GetCurrHiliteID()] == 0 )// it's empty, no need to clear it
		{
			//DisplayPopup( (PU8)GetString(STR_CANNOT_NAVIGATE_FURTHER_MESSAGE), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME_2000, (U8)WARNING_TONE );
		}			
		else
			mmi_tv_entry_clear_channel_confirm(); // clear channel
	}
	else if(freq == 0xffff) /* invalid decimal digit */
	{
//		DisplayPopup( (PU8)GetString( STR_ID_FMRDO_VALID_FM_DECIMAL ), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME_2000, (U8)WARNING_TONE );
	}	
//	else if( freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY ) /* warning invalid frequency */
//	{
//		DisplayPopup( (PU8)GetString( STR_ID_FMRDO_VALID_FM_BANDWIDTH ), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME_2000, (U8)WARNING_TONE );
//	}
	else
	{
		mmi_tv_entry_save_channel_confirm();
	}
}

void mmi_TV_channel_edit_highlight_hdlr( S32 index )
{
	
	if( index == 1 ) // edit channel name
	{
		ChangeLeftSoftkey( STR_GLOBAL_EDIT, 0 );
		SetCategory57LeftSoftkeyFunction( mmi_Tv_entry_channel_name_edit);
		if( channel_name_edit_done )
		{
			ChangeRightSoftkey( STR_GLOBAL_DONE, 0 );
			SetCategory57RightSoftkeyFunctions( mmi_tv_channel_edit_LSK, mmi_tv_channel_edit_LSK );
		}
		else
			SetCategory57RightSoftkeyFunctions( GoBackHistory, GoBackHistory );
	}
	else
	{
		SetCategory57LeftSoftkeyFunction( mmi_tv_channel_edit_LSK );
		SetCategory57RightSoftkeyFunctions( GoBackHistory, GoBackHistory );
	}
	
}
void mmi_TV_entry_channel_edit( void );
void mmi_TV_exit_channel_edit( void )
{
	history	h;
	U16 inputBufferSize;

	CloseCategory57Screen();
	h.scrnID = SCR_ID_TLG_TV_CHANNEL_EDIT;
	h.entryFuncPtr = mmi_TV_entry_channel_edit;
	GetCategoryHistory( h.guiBuffer );
	inputBufferSize = (U16)GetCategory57DataSize();
	GetCategory57Data( (U8*) h.inputBuffer );
	AddNHistory( h, inputBufferSize );
}
void mmi_TV_entry_channel_edit( void )
{
	U8* guiBuffer;
	U8* inputBuffer;
	U16 inputBufferSize;
	/*bw_20070831 U808_ZHONGXING 频道编辑改动*/
	#ifdef U808_ZHONGXING
	UI_image_ID_type item_icons[] = 
	{
		0,
		0
	};
	#else
	UI_image_ID_type item_icons[] = 
	{
		IMG_GLOBAL_L1,
		0,	//bw_20070809 all all 频道编辑图标更改
		IMG_GLOBAL_L2,
		0
	};
	#endif
	EntryNewScreen( SCR_ID_TLG_TV_CHANNEL_EDIT, mmi_TV_exit_channel_edit, NULL, NULL );
	
	InitializeCategory57Screen();
   
	inputBuffer = GetCurrNInputBuffer( SCR_ID_TLG_TV_CHANNEL_EDIT, &inputBufferSize );

	RegisterHighlightHandler( mmi_TV_channel_edit_highlight_hdlr );

	if( (guiBuffer = GetCurrGuiBuffer( SCR_ID_TLG_TV_CHANNEL_EDIT )) == NULL )
	{
		U16 freq = g_AnalogTv_data.ChannelList[channel_list_highlighted_item_index];
		pfnUnicodeStrcpy( (S8*)name_inline_editor_buffer, (S8*)g_AnalogTv_data.name[channel_list_highlighted_item_index ] );
		if( freq == 0 )
			freq_inline_editor_buffer[0] = 0;
		else
			kal_wsprintf( freq_inline_editor_buffer, "%d", freq );

		channel_name_edit_done = FALSE;
	}

	// channel name label
	SetInlineItemActivation( &wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0 );
	SetInlineItemCaption( &wgui_inline_items[0], (U8*)GetString( STR_CB_CHNL_TITLE ) );

	// channel name
	SetInlineItemActivation( &wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0 );
	SetInlineItemDisplayOnly( &wgui_inline_items[1], (U8*)name_inline_editor_buffer );
	#ifndef U808_ZHONGXING	/*bw_20070831 U808_ZHONGXING 频道编辑改动*/
	// frequency label
	SetInlineItemActivation( &wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0 );
	SetInlineItemCaption( &wgui_inline_items[2], (U8*)GetString( STR_CB_CHNL_NUMBER ) );
	
	// frequency input
	SetInlineItemActivation( &wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0 );
	SetInlineItemCaption( &wgui_inline_items[3], (U8*)freq_inline_editor_buffer );
	#endif
/*
	SetInlineItemTextEdit( &wgui_inline_items[3], (U8*)freq_inline_editor_buffer, MAX_MANUAL_INPUT_LEN, INPUT_TYPE_DECIMAL_NUMERIC );
	LeftJustifyInlineItem( &wgui_inline_items[3] );
	SetInlineItemFullWidth( &wgui_inline_items[3] );
	EnableInlineItemBoundary( &wgui_inline_items[3] );
*/
	DisableCategory57ScreenDone();

	// show category screen
	ShowCategory57Screen( STR_CB_CHNL_TITLE, MAIN_MENU_TITLE_MULTIMEDIA_ICON,	// title text and icon
		STR_GLOBAL_OK, IMG_GLOBAL_OK,								// LSK text and icon
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK,							// RSK text and icon
		#ifndef U808_ZHONGXING	/*bw_20070831 U808_ZHONGXING 频道编辑改动*/
		4,
		#else
		2,
		#endif
		item_icons, wgui_inline_items,
		0, guiBuffer );

	// register volume inc, dec handlers - inline screen will register vol up and vol down key
	//SetKeyHandler( mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN );
	//SetKeyHandler( mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN );
}

void mmi_tv_channel_option_LSK( void )
{
	switch( channel_option_highlighted_item_text )
	{
		case STR_GLOBAL_ON:
			if (0)	//( !g_AnalogTv_data.is_power_on )
			{
					DisplayPopup( (PU8)GetString( STR_CB_CHNL_TITLE ), IMG_GLOBAL_WARNING, 1, 2000, (U8)WARNING_TONE );
					return;
			}
			g_AnalogTv_data.g_current_channel=g_AnalogTv_data.ChannelList[channel_list_highlighted_item_index];
			//mmi_analog_tv_switch_channel_entry_app();
		//	mmi_analog_tv_entry_app();
			GoBackToHistory( SCR_ID_TV_IN_APP );
			break;
		case STR_GLOBAL_EDIT:
			mmi_TV_entry_channel_edit();
			break;
	}

}
void mmi_tv_channel_option_highlight_hdlr( S32 index )
{
	BOOL is_empty_channel = (g_AnalogTv_data.ChannelList[channel_list_highlighted_item_index] == 0);
	U16 item_texts[] = {STR_GLOBAL_ON, STR_GLOBAL_EDIT};//  old   U16 item_texts[] = { STR_GLOBAL_EDIT,STR_GLOBAL_ON};
/*bw_20070420b 11:29:33 没有频道时只显示编辑的功能*/
	channel_option_highlighted_item_text = (is_empty_channel ? item_texts[1]: item_texts[index]);
}
void mmi_TV_entry_channel_option( void )
{
	BOOL is_empty_channel = (g_AnalogTv_data.ChannelList[channel_list_highlighted_item_index] == 0);
	U16 item_texts[] = {STR_GLOBAL_ON,STR_GLOBAL_EDIT};	// old U16 item_texts[] = {STR_GLOBAL_EDIT,STR_GLOBAL_ON};	//STR_ID_AUDPLY_OPTION_PLAY
	
	U16 item_icons[] = { IMG_GLOBAL_L1, IMG_GLOBAL_L2 };
	U8* gui_buffer;
	U8* item_popups[] = { NULL, NULL };
	
	EntryNewScreen( SCR_ID_TLG_TV_CHANNEL_OPTION, NULL, NULL, NULL );
	
	gui_buffer = GetCurrGuiBuffer( SCR_ID_TLG_TV_CHANNEL_OPTION );

	RegisterHighlightHandler( mmi_tv_channel_option_highlight_hdlr );
	
	if( is_empty_channel )
	{
	/*bw_20070420b 11:29:33 没有频道时只显示编辑的功能*/
		ShowCategory52Screen( STR_GLOBAL_OPTIONS, MAIN_MENU_TITLE_MULTIMEDIA_ICON,
			STR_GLOBAL_OK, 0,
			STR_GLOBAL_BACK, 0,
			1, item_texts+1, item_icons, (U8**) item_popups, 0, 0, gui_buffer );
	}
	else
	{
		ShowCategory52Screen( STR_GLOBAL_OPTIONS, MAIN_MENU_TITLE_MULTIMEDIA_ICON,
			STR_GLOBAL_OK, 0,
			STR_GLOBAL_BACK, 0,
			2, item_texts, item_icons, (U8**) item_popups, 0, 0, gui_buffer );
	}

	// register left, right arrow key handlers
	SetKeyHandler( GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_tv_channel_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	
	// register LSK, RSK hanlders
	SetLeftSoftkeyFunction( mmi_tv_channel_option_LSK, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
	
	// register volume inc, dec handlers
//	SetKeyHandler( mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN );
//	SetKeyHandler( mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN );
}

pBOOL mmi_tv_channel_list_item( S32 item_index, UI_string_type str_buff, UI_image_type* img_buff_p, U8 str_img_mask )
{
	// show frequency text
	U16 freq = g_AnalogTv_data.ChannelList[item_index];
	if( freq == 0 )
		pfnUnicodeStrcpy( (S8*)str_buff, GetString( STR_GLOBAL_EMPTY_LIST ) );
	else
		kal_wsprintf( str_buff, "CH %d", freq);
	
	// show order icon
	*img_buff_p = (UI_image_type) GetImage( (U16)(IMG_GLOBAL_L1 + item_index) );

	return TRUE;
}

S32 mmi_tv_channel_list_item_hint( S32 item_index, UI_string_type *hint_array )
{
	U16 freq = g_AnalogTv_data.ChannelList[item_index];
	UI_string_type name = g_AnalogTv_data.name[item_index];//g_fmrdo.channel_list.name[item_index];
	U16 name_len;
	
	if( /*freq == 0 || */(name_len = (U16)pfnUnicodeStrlen((const S8*)name)) == 0 )
		return 0;
	pfnUnicodeStrcpy( (S8*)hint_array[0], (S8*)name );

	return 1;
}
void mmi_tv_channel_list_highlight_hdlr( S32 index )
{
	channel_list_highlighted_item_index = (U16)index;
}

void mmi_tv_entry_channel_list(void)
{
	U8* gui_buffer;
	S32 highlighted_item;
	S16 error;
	EntryNewScreen( SCR_ID_TLG_TV_CHANNEL_LIST, NULL, mmi_tv_entry_channel_list, NULL );
 /*bw070717 [ALL][ALL] TV频道存储*/
	ReadRecord( NVRAM_ANALOG_TV_CHANNEL_LID, 1, (void*)g_AnalogTv_data.ChannelList, NVRAM_ANALOG_TV_CHANNEL_SIZE, &error );
  	//memset( g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM );
 
	// register highligh handler
	RegisterHighlightHandler(mmi_tv_channel_list_highlight_hdlr);
	
	gui_buffer = GetCurrGuiBuffer( SCR_ID_TLG_TV_CHANNEL_LIST );
	if( g_AnalogTv_data.DistrictSelected >= 0 )
		highlighted_item = g_AnalogTv_data.DistrictSelected;
	else
		highlighted_item = 0;

	ShowCategory184Screen( STR_ID_TLG_TV_CHANNEL_LIST, MAIN_MENU_TITLE_MULTIMEDIA_ICON,	// title text and icon
		STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS,							// LSK text and icon
		STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 								// RSK text and icon
		ANALOG_TV_CHANNEL_NUM, mmi_tv_channel_list_item, mmi_tv_channel_list_item_hint,
		highlighted_item, gui_buffer );
	
	// register LSK, RSK hanlders
	SetLeftSoftkeyFunction( mmi_TV_entry_channel_option, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
	
	// register left right arrow key handler
	SetKeyHandler( mmi_TV_entry_channel_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	
	// register volume inc, dec handlers
//	SetKeyHandler( mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN );
//	SetKeyHandler( mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN );
}
void mmi_analog_tv_search_all_channel_confirm_LSK( void );
void mmi_tv_entry_preset_list_confirm(void)
{
//p_6226_m24_bw_z0166 当为有线时不允许自动搜索
    if( g_AnalogTv_data.ModeSelected==1)
    	{
	mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_TLG_TV_CATV_WARNING),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
	   	 return ;
     	}
	mmi_analog_tv_search_all_channel_confirm_LSK();
}
/*****************************************************************************
* FUNCTION
*     mmi_fmrdo_main_option_highlight_hdlr
* DESCRIPTION
*     
* IMPACT 
*     
* PARAMETERS
*     S32 index
* RETURNS
*     void
* GLOBALS AFFECTED
*     
*****************************************************************************/
void mmi_tv_main_option_highlight_hdlr( S32 index )
{
	main_tv_option_highlighted_item_text = (U16) GetSeqItemStringId( (U16)MENU_ID_tlg_TV_OPTION, (U16)index );
}

/*****************************************************************************
* FUNCTION
*     mmi_fmrdo_main_option_LSK
* DESCRIPTION
*     
* IMPACT 
*     
* PARAMETERS
*     void
* RETURNS
*     void
* GLOBALS AFFECTED
*     
*****************************************************************************/
void mmi_tv_main_option_LSK( void )
{
	switch( main_tv_option_highlighted_item_text )
	{
		case STR_ID_TLG_TV_SELECT_AREA:
			mmi_tv_entry_select_area();
			break;
		case STR_ID_TLG_TV_CHANNEL_LIST:
			mmi_tv_entry_channel_list();
			break;
		case STR_ID_TLG_TV_AUTO_SEARCH:
			mmi_tv_entry_preset_list_confirm();
			break;
		case STR_ID_TLG_TV_SELECT_MODE:  //P_6226_M14_bw_Z0053 tv添加有线电视的选择菜单
			mmi_tv_entry_select_mode();
			break;
	}
}

//end

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_entry_option_screen
 * DESCRIPTION
 *  entry option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_analog_tv_cntx.state == ANALOG_TV_STATE_RECORD)
        return;
    EntryNewScreen(SCR_ID_TLG_TV_OPTION, NULL, mmi_analog_tv_entry_option_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_TLG_TV_OPTION);
    nItems = GetNumOfChild(MENU_ID_tlg_TV_OPTION);
    GetSequenceStringIds(MENU_ID_tlg_TV_OPTION, ItemList);
    GetSequenceImageIds(MENU_ID_tlg_TV_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_tlg_TV_OPTION);

    RegisterHighlightHandler(mmi_tv_main_option_highlight_hdlr);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_TV_IN_OPTION, PopUpList);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 
 /*bw070717 [ALL][ALL] TV频道存储*/
	ReadRecord( NVRAM_ANALOG_TV_CHANNEL_NAME_LID, 1, (void*)g_AnalogTv_data.name[0], NVRAM_ANALOG_TV_NAME_SIZE, &error  );
	ReadRecord( NVRAM_ANALOG_TV_CHANNEL_LID, 1, (void*)g_AnalogTv_data.ChannelList, 15, &error  );
  	//memset( g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM );
	
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
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
// register left, right arrow key handlers
	SetKeyHandler( GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN );
	SetKeyHandler( mmi_tv_main_option_LSK, KEY_RIGHT_ARROW, KEY_EVENT_DOWN );
	
	// register LSK, RSK hanlders
	SetLeftSoftkeyFunction( mmi_tv_main_option_LSK, KEY_EVENT_UP );
	SetRightSoftkeyFunction( GoBackHistory, KEY_EVENT_UP );
	
	// register volume inc, dec handlers
//	SetKeyHandler( mmi_fmrdo_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN );
//	SetKeyHandler( mmi_fmrdo_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN );
}

/*****************************************************************************
*
*  Touch Screen Support
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_init_panel
 * DESCRIPTION
 *  init panel (timer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*bw_20070427 9:52:40  add analog tv auto test*/
 void mmi_analog_tv_init_panel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digit_width;
    S32 col_width;
    S32 height;

#ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*bw_20070428 11:37:33 图片应该取电视的图片不是vdoplay的图片*/
#define INIT_TOUCH_OBJ(__x__, __X__)\
	{\
		touch_p = &g_analog_tv_cntx.touch_##__x__##;\
		touch_p->offset_x = g_analog_tv_osd_cntx.panel.##__x__##.offset_x;\
		touch_p->offset_y = g_analog_tv_osd_cntx.panel.##__x__##.offset_y;\
		touch_p->is_press = FALSE;\
		gdi_image_get_dimension_id(IMG_ID_ANALOG_TOUCH_OSD_##__X__##, &touch_p->width, &touch_p->height);\
	}\

	#define INIT_TOUCH_FULL_OBJ(__x__, __X__)\
	{\
		touch_p = &g_analog_tv_cntx.full_touch_##__x__##;\
		touch_p->offset_x = g_vdoply_fullscr_osd_cntx.panel.##__x__##.offset_x;\
		touch_p->offset_y = g_vdoply_fullscr_osd_cntx.panel.##__x__##.offset_y;\
		touch_p->is_press = FALSE;\
		gdi_image_get_dimension_id(IMG_ID_ANALOG_TOUCH_FULL_OSD_##__X__##, &touch_p->width, &touch_p->height);\
	}\

#ifdef __ANALOG_TV_FEATURE_TOUCH_SCREEN__
    g_analog_tv_cntx.touch_object = VDOREC_TOUCH_NONE;

    /* init touch region */
	INIT_TOUCH_OBJ(volume_inc,VOLUME_INC);	
	INIT_TOUCH_OBJ(volume_dec,VOLUME_DEC);	
	INIT_TOUCH_OBJ(speed_inc,CHANNEL_INC);	/*bw_20070428 11:37:33 图片应该取电视的图片不是vdoplay的图片*/
	INIT_TOUCH_OBJ(speed_dec,CHANNEL_DEC);

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__   
	INIT_TOUCH_OBJ(fullscreen,FULLSCREEN);	
#endif

#endif /* __ANALOG_TV_FEATURE_TOUCH_SCREEN__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_ck_press_hdlr
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_ck_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_ck_pressed = TRUE;

    mmi_analog_tv_draw_softkey();
    mmi_analog_tv_blt_screen();
}

void mmi_analog_tv_inc_volume(void)
{
     S16 error;
      if( g_AnalogTv_data.volume < ANALOG_TV_MAX_VOL_LEVEL - 1 )
	{
	      g_AnalogTv_data.volume+=1;
	      WriteValue( NVRAM_ANALOG_TV_VOLUME, &g_AnalogTv_data.volume, DS_BYTE, &error );

		mdi_tlg_tv_set_volume(g_AnalogTv_data.volume);

		/*redraw icon here*/
	}
}
void mmi_analog_tv_dec_volume( void )
{
     S16 error;
	if( g_AnalogTv_data.volume > 0 )
	{
	     g_AnalogTv_data.volume-=1;
	      WriteValue( NVRAM_ANALOG_TV_VOLUME, &g_AnalogTv_data.volume, DS_BYTE, &error );
		 
	     mdi_tlg_tv_set_volume( g_AnalogTv_data.volume);
		/*redraw icon here*/
	}
}

void mmi_analog_tv_get_valid_channel_done(U8 ret)
{

   kal_uint8 chan;
   	mmi_tv_search_count++;	//lgadd
       
       if(ret==1)
      	{
         g_AnalogTv_data.channel_count++;
         g_AnalogTv_data.ChannelList[ g_AnalogTv_data.channel_count-1]=g_AnalogTv_data.channel_is_searching;
       }
     //   kal_sleep_task(2);
	if( (g_AnalogTv_data.channel_index_is_searching<mmi_tv_max_index)&& (g_AnalogTv_data.channel_count<=ANALOG_TV_CHANNEL_NUM))  
	{
	  g_AnalogTv_data.channel_index_is_searching++;
	  #ifndef MMI_ON_WIN32
	  //Huyanwei Add It
	  chan=TLGAPP_GetChannel(g_AnalogTv_data.channel_index_is_searching);
	  #endif
	  g_AnalogTv_data.channel_is_searching=chan;
	   mdi_tlg_tv_get_valid_channels( chan,mmi_analog_tv_get_valid_channel_done);
	   mmi_analog_tv_draw_search();	//lgadd
	}
	else
	{
	  analog_tv_search_all_channels_callback_func();
	}
}
//lgtest

void mmi_analog_tv_search_all_channels_start(void (*callback_func)(void))
 {

        kal_uint8  chan;
	#ifndef MMI_ON_WIN32
	//Huyanwei Add It
	 chan=TLGAPP_GetChannel(0);   
	#endif
	  g_AnalogTv_data.channel_index_is_searching=0;
	 g_AnalogTv_data.channel_is_searching=chan;
	 g_AnalogTv_data.channel_count=0;
        analog_tv_search_all_channels_callback_func=callback_func;
	 mdi_tlg_tv_get_valid_channels( chan,mmi_analog_tv_get_valid_channel_done);

 }
//lgtest

void mmi_analog_tv_save_channel_list(void)
{
	S16 error;
 /*bw070717 [ALL][ALL] TV频道存储*/
	WriteRecord( NVRAM_ANALOG_TV_CHANNEL_LID, 1, (void*)g_AnalogTv_data.ChannelList, NVRAM_ANALOG_TV_CHANNEL_SIZE, &error );
}
 void mmi_analog_tv_search_all_channel_done(void)
 {
     /*1.store channel list */
	mmi_analog_tv_save_channel_list();
	 mmi_analog_tv_get_channlelist_to_current_channel(); //lgadd
     /*2.update mmi*/	 
//lgadd
//p_6226_m24_bw_z0164  修改自动搜索完成时的提示
	 #ifdef __MMI_SCREEN_ROTATE__
	DisplayPopupRotated((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_WARNING, TRUE, 2000, EMPTY_LIST_TONE, MMI_FRM_SCREEN_ROTATE_0);
	#else
	DisplayPopup((PU8)GetString(STR_GLOBAL_DONE), IMG_GLOBAL_WARNING, TRUE, 2000, EMPTY_LIST_TONE);
	#endif
 } 

#include "gui_data_types.h"
static void mmi_analog_tv_draw_search(void)
{
	S32 x1;
	S32 x2;
	S32 y1;
	S32 y2;
	S32 width;
	S32 height;
	S32 str_w, str_h;
	S32 time_w=50;
	S8 temp[8];
	UI_character_type time_str[8];

	color c={255,255,255};
	
	x1=10;
	x2=120;
	y1=120;
	y2=140;
#if(UI_DOUBLE_BUFFER_SUPPORT)
	UI_lock_double_buffer();
#endif
	
	UI_fill_rectangle(0, 0/*MMI_status_bar_height*/,UI_device_width, UI_device_height-MMI_button_bar_height,c);
	gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY, &width, &height);
	x1=(UI_device_width-width)/2;
	x2=x1+width;
	y1=(UI_device_height-MMI_button_bar_height-height)/2;
	y2=y1+height+1;
	gdi_layer_set_clip(x1,y1,x2,y2);
	gdi_image_draw_id(x1,y1,(U16)(IMG_ID_VDOPLY_OSD_PROGRESS_EMPTY));

	x2=x1+(U32)(mmi_tv_search_count*width/mmi_tv_max_index);
	gdi_layer_set_clip(x1,y1,x2,y2);
	gdi_image_draw_id(x1,y1,(U16)(IMG_ID_VDOPLY_OSD_PROGRESS_FILL));
	///////
	sprintf( temp, "%02d %%", mmi_tv_search_count*100/mmi_tv_max_index);
	AnsiiToUnicodeString( (S8*)time_str, (S8*)temp );
	// background & time
	UI_push_clip();
	UI_push_text_clip();
	x1=(UI_device_width-time_w)/2;
	x2=x1+time_w;
	y1=y2+15;
	y2=y1+20;
	UI_set_clip( x1, y1, x2, y2 );
	UI_set_text_clip( x1, y1, x2, y2 );
	UI_fill_rectangle( x1, y1, x2, y2, c );
//	pixtel_UI_set_font( &MMI_small_font );
//	pixtel_UI_set_text_color( text_fg_color );
	UI_measure_string( time_str, &str_w, &str_h );
	if( r2lMMIFlag )
		UI_move_text_cursor( x1 + (time_w + str_w)/2, y1 + 1 );
	else
		UI_move_text_cursor( x1 + (time_w - str_w)/2, y1 + 1 );
	UI_print_text( time_str );
	UI_pop_text_clip();
	UI_pop_clip();
	//
	mmi_analog_tv_blt_screen();
#if(UI_DOUBLE_BUFFER_SUPPORT)
	UI_unlock_double_buffer();
	UI_BLT_double_buffer( 0, 0,UI_device_width, UI_device_height-MMI_button_bar_height );
#endif

}
static void mmi_analog_tv_exit_search(void)
{
		
        g_AnalogTv_data.g_analog_tv_enable=KAL_FALSE;	//pjqadd  070320 

	mmi_analog_tv_search_all_channels_stop();
	 /* resume background audio */
       mdi_audio_resume_background_play();  //pjqadd  070320

      /* re-enable keypad tone */
       mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
}

#if defined ( __ANALOG_TV_FEATURE_TOUCH_SCREEN__ )// add by hongzhe.liu, because 9500 not has a touch screen
void mmi_analog_tv_touch_scr_pen_down_search_hdlr(mmi_pen_point_struct pos)
{
#if 0 // rm by hongzhe.liu
	if(mmi_wgui_test_rsk_position(pos) == MMI_TRUE)
	{
		mmi_analog_tv_searching_abort();
		return;
	}
#endif
}
#endif
void  mmi_analog_tv_entry_searching(void)
{
//lgadd
	EntryNewScreen( SCR_ID_TLG_TV_SEARCHING, mmi_analog_tv_exit_search, NULL, NULL );
	entry_full_screen();
	// clear End key
	ClearKeyHandler( KEY_END, KEY_EVENT_DOWN );
	ClearKeyHandler( KEY_END, KEY_LONG_PRESS );
	// Show searching screen
	
       #if 0    //P_6226_M38_bw_B2762  播放广播时再去搜索电视台，发现一个台都搜索不到
	 /* force all playing keypad tone off */
        AudioStopReq(GetCurKeypadTone());   //jonathan add  070320
       /* disable key pad tone */
       mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
       /* suspend background play */
       mdi_audio_suspend_background_play();
       #endif
	clear_category_screen_key_handlers();
	clear_left_softkey();
	clear_right_softkey();
	set_softkey_label(NULL,MMI_LEFT_SOFTKEY);
	set_softkey_icon(NULL,MMI_LEFT_SOFTKEY);
	set_softkey_label(NULL,MMI_RIGHT_SOFTKEY);
	set_softkey_icon(NULL,MMI_RIGHT_SOFTKEY);
	change_right_softkey(STR_GLOBAL_CANCEL,0);
//	register_left_softkey_handler();
	register_right_softkey_handler();
	register_default_hide_softkeys();
	show_softkey_background();	
	show_left_softkey();
	show_right_softkey();
	//
	mmi_analog_tv_draw_search();
/*	ShowCategory66Screen( STR_ID_TLG_TV_AUTO_SEARCH, 0,
		0, 0, STR_GLOBAL_CANCEL, 0, 
		(U8*)GetString( STR_ID_TLG_TV_AUTO_SEARCH ), IMG_GLOBAL_PROGRESS, NULL );
*/
	// Set RSK to abort searching
	SetRightSoftkeyFunction( mmi_analog_tv_searching_abort, KEY_EVENT_DOWN);
#if defined(__ANALOG_TV_FEATURE_TOUCH_SCREEN__) 

    mmi_wgui_register_pen_down_handler(mmi_analog_tv_touch_scr_pen_down_search_hdlr);

//    mmi_wgui_register_pen_up_handler(mmi_analog_tv_touch_scr_pen_up_hdlr);
 //   mmi_wgui_register_pen_move_handler(mmi_analog_tv_touch_scr_pen_move_hdlr);
#endif
mmi_analog_tv_blt_screen();
}
void mmi_analog_tv_search_all_channel_confirm_LSK( void )
{
     g_AnalogTv_data.g_analog_tv_enable=KAL_TRUE;
//P_6226_M38_bw_B2762  播放广播时再去搜索电视台，发现一个台都搜索不到
    /* force all playing keypad tone off */
      AudioStopReq(GetCurKeypadTone());   
       /* disable key pad tone */
       mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
	 /* suspend background play */
       mdi_audio_suspend_background_play();

     /*power on first*/
    mmi_analog_tv_power_up();

   
   //lgadd
    mmi_tv_search_count=0;
//mmi_tv_max_index=TLGAPP_GetChannelMaxIndex();
    if( g_AnalogTv_data.is_power_on)	 
    {
 
    /*Searching Screen Display*/	 
    mmi_analog_tv_entry_searching();
   
   // g_AnalogTv_data.g_analog_tv_enable=KAL_TRUE;
    memset(g_AnalogTv_data.ChannelList,0,NVRAM_ANALOG_TV_CHANNEL_SIZE);
    mmi_analog_tv_search_all_channels_start(mmi_analog_tv_search_all_channel_done);

    }
    else
    {
       /*Popup some info*/
    }
   
	

}



void mmi_analog_tv_search_all_channels_stop()
{
	
    mmi_analog_tv_power_down();
     analog_tv_search_all_channels_callback_func = NULL;
     mdi_tlg_tv_cancel_getting_valid_channel();
   

     /*update  Screen*/	
}

static void mmi_analog_tv_searching_abort( void )
{
	GoBackHistory();
}	

static void mmi_analog_tv_bright_inc_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_TRUE, TV_IN_PARA_TYPE_BRIGHTESS);
}

static void mmi_analog_tv_bright_dec_key_release_hdlr(void)
{
   // mmi_TV_in_parameter_change(KAL_FALSE, TV_IN_PARA_TYPE_BRIGHTESS);
}

static void mmi_analog_tv_contrast_inc_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_TRUE, TV_IN_PARA_TYPE_CONTRAST);
}

static void mmi_analog_tv_contrast_dec_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_FALSE, TV_IN_PARA_TYPE_CONTRAST);
}

static void mmi_analog_tv_saturation_inc_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_TRUE, TV_IN_PARA_TYPE_SATURATION);
}

static void mmi_analog_tv_saturation_dec_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_FALSE, TV_IN_PARA_TYPE_SATURATION);
}

static void mmi_analog_tv_hue_inc_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_TRUE, TV_IN_PARA_TYPE_HUE);
}

static void mmi_analog_tv_hue_dec_key_release_hdlr(void)
{
    //mmi_TV_in_parameter_change(KAL_FALSE, TV_IN_PARA_TYPE_HUE);
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
static void mmi_analog_tv_ck_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return;
	
    g_analog_tv_cntx.is_ck_pressed = FALSE;

    switch (g_analog_tv_cntx.state)
    {
        case ANALOG_TV_STATE_PREVIEW:
        case ANALOG_TV_STATE_PAUSE:
	
            mmi_analog_tv_draw_softkey();
            mmi_analog_tv_blt_screen();
            mmi_analog_tv_enter_state(ANALOG_TV_STATE_RECORD);
            break;

        case ANALOG_TV_STATE_RECORD:
            mmi_analog_tv_draw_softkey();
            mmi_analog_tv_blt_screen();
            mmi_analog_tv_enter_state(ANALOG_TV_STATE_PAUSE);
            break;

    }

}
#if defined(__ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__)
/*****************************************************************************
 * FUNCTION
 *  set_analog_tv_full_screen_layer_roate
 * DESCRIPTION
 *  设置layer 控制寄存器的值来实现90度旋转(11bit,12bit,13bit)
 *不需在电视退出时重新设置，因每blt会重新设置
 * PARAMETERS
 *  void
 * RETURNS
 *  bw_20070419  
 *****************************************************************************/
 void set_analog_tv_full_screen_layer_roate(U8 layerid)
{ 
  U32 Enable_layer=0;
  if(mmi_analog_tv_is_full_screen()&&GetActiveScreenId()==SCR_ID_TV_IN_APP)
  {
 	switch(layerid)
 	{
 	case 0:
 	Enable_layer=GDI_LAYER_ENABLE_LAYER_0;
	break;
 	case 1:
 	Enable_layer=GDI_LAYER_ENABLE_LAYER_1;
	break;	
	case 2:
 	Enable_layer=GDI_LAYER_ENABLE_LAYER_2;
	break;
	case 3:
 	Enable_layer=GDI_LAYER_ENABLE_LAYER_3;
	break;	
	
 }	
   set_lcd_layer_roate(Enable_layer,GDI_LAYER_ROTATE_90);
  }
}
#endif


extern const U8 vdorec_wb_command_map[VDOREC_SETTING_WB_COUNT+1];
extern const U8 vdorec_ev_command_map[VDOREC_SETTING_EV_COUNT+1];
extern const U8 vdorec_banding_command_map[VDOREC_SETTING_BANDING_COUNT+1];
extern const U8 vdorec_effect_command_map[VDOREC_SETTING_EFFECT_COUNT+1];
extern const U8 vdorec_video_size_command_map[VDOREC_SETTING_VIDEO_SIZE_COUNT+1];
extern const U8 vdorec_video_qty_command_map[VDOREC_SETTING_VIDEO_QTY_COUNT+1];
extern const U8 vdorec_video_format_command_map[VDOREC_SETTING_VIDEO_FORMAT_COUNT+1];
extern const U8 vdorec_effect_command_map[VDOREC_SETTING_EFFECT_COUNT+1];



#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add it As mmi_vdorec_start_preview()

void mmi_analog_tv_record_peview(void)
{

    // Huyanwei Remark It 
    // 
    // Huyanwei Want To Write A Function , But Fine that  mmi_analog_tv_start_preview_by_vdorec most look the same 
    
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

    video_preview_data.zoom = g_vdorec_cntx.zoom_limit; //mmi_vdorec_get_zoom_factor();
    video_preview_data.night = g_vdorec_cntx.setting.night;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    video_preview_data.hue = 0;
    video_preview_data.preview_rotate = VDOREC_MAINLCD_ROTATE;


    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;


#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_270;
#else 
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
#endif 

    video_preview_data.size_limit = 0;
    video_preview_data.record_aud = TRUE;


    video_preview_data.brightness = g_analog_tv_brightness;
    video_preview_data.contrast = g_analog_tv_contrast;
    video_preview_data.saturation = g_analog_tv_saturation;
    video_preview_data.hue  = g_analog_tv_hue;
    
    /*For NTSC/PAL select , user the BAND parameter*/
    video_preview_data.banding = MDI_VIDEO_BANDING_50HZ;
    video_preview_data.zoom = 10;
	
    blt_layer_falg = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;      
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;   

    g_analog_tv_cntx.last_error 
        = mdi_video_rec_preview_start(
            g_analog_tv_cntx.preview_layer_handle,
            blt_layer_falg,
            preview_layer_flag,
            MMI_TRUE,
            &video_preview_data);

}




#endif


#include "mdi_video.h"

static void mmi_analog_tv_start_preview_by_vdorec(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                                                          */
   /*----------------------------------------------------------------*/
	mdi_video_setting_struct	video_preview_data;
	
   /*----------------------------------------------------------------*/
   /* Code Body                                                                                               */
   /*----------------------------------------------------------------*/
#if defined(TV_RECORD_SUPPORT)
	video_preview_data.wb 				= MDI_VIDEO_WB_AUTO ;
	video_preview_data.ev 				= MDI_VIDEO_EV_N4 ;
	video_preview_data.banding 		= MDI_VIDEO_BANDING_50HZ ;			
	video_preview_data.video_size		= MDI_VIDEO_VIDEO_SIZE_QCIF ;
	video_preview_data.video_qty 		= MDI_VIDEO_REC_QTY_LOW ;
	video_preview_data.video_format 	= MDI_VIDEO_VIDEO_FORMAT_MP4 ;	
	video_preview_data.effect 			= MDI_VIDEO_EFFECT_NOMRAL ;
#else
	video_preview_data.wb 				= vdorec_wb_command_map[g_vdorec_cntx.setting.wb];
	video_preview_data.ev 				= vdorec_ev_command_map[g_vdorec_cntx.setting.ev];
	video_preview_data.banding 		= vdorec_banding_command_map[g_vdorec_cntx.setting.banding];			
	video_preview_data.video_size		= vdorec_video_size_command_map[g_vdorec_cntx.setting.video_size];	
	video_preview_data.video_qty 		= vdorec_video_qty_command_map[g_vdorec_cntx.setting.video_qty];
	video_preview_data.video_format 	= vdorec_video_format_command_map[g_vdorec_cntx.setting.video_format];	
	video_preview_data.effect 			= vdorec_effect_command_map[g_vdorec_cntx.setting.effect];
#endif

	video_preview_data.zoom 	 	= g_vdorec_cntx.zoom_limit;  // mmi_vdorec_get_zoom_factor(); //HH
	video_preview_data.night			= g_vdorec_cntx.setting.night;	
	video_preview_data.brightness  	= 128;
	video_preview_data.contrast 	 	= 128;
	video_preview_data.saturation	 	= 128;			
	video_preview_data.hue 	 		= 0;
	video_preview_data.preview_rotate 	 		= VDOREC_MAINLCD_ROTATE; //hongzhe.liu change rotate to preview_rotate

	video_preview_data.overlay_frame_mode  				= FALSE;
	video_preview_data.overlay_frame_depth 				= 0;
	video_preview_data.overlay_frame_width 				= 0;
	video_preview_data.overlay_frame_height 				= 0;
	video_preview_data.overlay_frame_source_key 			= 0;
	video_preview_data.overlay_frame_buffer_address 	= 0;

	
	#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
		video_preview_data.lcm_rotate= MDI_VIDEO_LCD_ROTATE_270;	//hongzhe.liu change lcd_rotate to lcm_rotate
	#else
		video_preview_data.lcm_rotate= MDI_VIDEO_LCD_ROTATE_0;	//hongzhe.liu change lcd_rotate to lcm_rotate
	#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
	

	/* no size limit */
	video_preview_data.time_limit = 0;
	video_preview_data.size_limit = 1024*100;
	video_preview_data.record_aud = TRUE;

	video_preview_data.brightness = g_analog_tv_brightness;
	video_preview_data.contrast = g_analog_tv_contrast;
	video_preview_data.saturation = g_analog_tv_saturation;
	video_preview_data.hue  = g_analog_tv_hue;

	/*For NTSC/PAL select , user the BAND parameter*/
	video_preview_data.banding = MDI_VIDEO_BANDING_50HZ;
	video_preview_data.zoom = 10;


	#if 1
	//Huyanwei Add It For Debug Preview Size
       if(mmi_analog_tv_is_full_screen())
	{
		video_preview_data.video_size=  MDI_VIDEO_VIDEO_SIZE_USER_DEFINE ;
		video_preview_data.user_def_width  =  320 ;
		video_preview_data.user_def_height =  240 ;
	}
	else
	{
		video_preview_data.video_size	= MDI_VIDEO_VIDEO_SIZE_QCIF ;
	}
	#endif


      if( (ANALOG_TV_STATE_PREVIEW_FULLSCREEN == g_analog_tv_cntx.state))
       {
#if defined(NOKE_DEBUG)
              noke_dbg_printf("\r\n Huyanwei  ANALOG_TV_STATE_PREVIEW_FULLSCREEN\r\n");
#endif
	      	g_analog_tv_cntx/*g_vdorec_cntx*/.last_error = 
		mdi_video_rec_preview_start( g_analog_tv_cntx/*g_vdorec_cntx*/.preview_layer_handle,
													GDI_LAYER_ENABLE_LAYER_1,
													GDI_LAYER_ENABLE_LAYER_1,
													MMI_TRUE,/* Hongzhe.liu add */
 													&video_preview_data);
       }
	else if((ANALOG_TV_STATE_PREVIEW_320_240_SCREEN == g_analog_tv_cntx.state ))
	{
#if defined(NOKE_DEBUG)
	       noke_dbg_printf("\r\n Huyanwei  ANALOG_TV_STATE_PREVIEW_320_240_SCREEN \r\n");
#endif
	      	g_analog_tv_cntx/*g_vdorec_cntx*/.last_error = 
		mdi_video_rec_preview_start( g_analog_tv_cntx/*g_vdorec_cntx*/.preview_layer_handle,
													GDI_LAYER_ENABLE_LAYER_1,
													GDI_LAYER_ENABLE_LAYER_1,
													MMI_TRUE,/* Hongzhe.liu add */
 													&video_preview_data);
	}
      else
      {
#if defined(NOKE_DEBUG)
	       noke_dbg_printf("\r\n Huyanwei  ANALOG_TV_STATE_PREVIEW_SCREEN \r\n");
#endif
		g_analog_tv_cntx/*g_vdorec_cntx*/.last_error = 
		mdi_video_rec_preview_start( g_analog_tv_cntx/*g_vdorec_cntx*/.preview_layer_handle,
													GDI_LAYER_ENABLE_LAYER_0|GDI_LAYER_ENABLE_LAYER_1|GDI_LAYER_ENABLE_LAYER_2,
													GDI_LAYER_ENABLE_LAYER_1,
													MMI_TRUE,/* Hongzhe.liu add */
 													&video_preview_data);
      	}

}


static void mmi_analog_tv_start_preview_by_camera(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	media_cam_preview_req_struct	cam_preview_data;
	
	U8							*buf_ptr;	
	S32						layer_width;
	S32						layer_height;
	S32						layer_offset_x;
	S32						layer_offset_y;
	MDI_RESULT				ret;
	S32						lcd_width;
	S32						lcd_height;
	S32						lcd_offset_x;
	S32						lcd_offset_y;
    U8 layer_rotate;    

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
    /* get layer info */

#if defined(NOKE_DEBUG)
   	noke_dbg_printf( "\r mmi_analog_tv_start_preview_by_camera  entering ! \n " );
#endif
	gdi_layer_push_and_set_active(g_analog_tv_cntx.preview_layer_handle);

	gdi_layer_get_buffer_ptr(&buf_ptr);
	gdi_layer_get_dimension(&layer_width, &layer_height);   //240*196
	gdi_layer_get_position(&layer_offset_x, &layer_offset_y);  //0,27
       layer_rotate = gdi_layer_get_rotate();                           //0
	gdi_layer_pop_and_restore_active();

	
	/* preview on main lcm */

	cam_preview_data.lcd_id	= MAIN_LCD;
	lcd_width = LCD_WIDTH;
	lcd_height = LCD_HEIGHT;

#if 1	
	/*bw070711 增加06B添加的变量*/
	cam_preview_data.camera_offset_x = (layer_offset_x < 0) ? 0 : layer_offset_x;
        cam_preview_data.camera_offset_y = (layer_offset_y < 0) ? 0 : layer_offset_y;
#endif
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r ** layer_width = %d, layer_height = %d , lcd_offset_x = %d, lcd_offset_y = %d \n", layer_width, layer_height,lcd_offset_x, lcd_offset_y);
#endif
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__   
   if(mmi_analog_tv_is_full_screen())
   	{
#if defined(NOKE_DEBUG)
   	noke_dbg_printf("\r Full screen preview! \n");
#endif
        cam_preview_data.preview_width			= 320;
	 cam_preview_data.preview_height			= 240;
	 lcd_offset_x = 0;
        lcd_offset_y =0;
        cam_preview_data.lcd_start_x = lcd_offset_x;    //0
	 cam_preview_data.lcd_start_y = lcd_offset_y;    //0
	 cam_preview_data.lcd_end_x	= lcd_offset_x+layer_height-1; //239
	 cam_preview_data.lcd_end_y	= lcd_offset_y+layer_width-1;   //319		
   	}   
   
   else
#endif
     {
#if defined(NOKE_DEBUG)
       noke_dbg_printf("\r Normal preview(not full screen)! \n");
#endif
       cam_preview_data.preview_width			= 240;
	cam_preview_data.preview_height			= 196;
	lcd_offset_x = 0;
       lcd_offset_y = 0;				//Modifyed by zhul, 2007-10-31, 调整了显示位置
	cam_preview_data.lcd_start_x = lcd_offset_x;    //0
	cam_preview_data.lcd_start_y = lcd_offset_y;    //27
	cam_preview_data.lcd_end_x	= lcd_offset_x+layer_width-1;  //239
      cam_preview_data.lcd_end_y	= lcd_offset_y+layer_height-1;	//222
     }

#if 1
	/*bw070711 增加06B添加的变量*/
        cam_preview_data.lcd_update =1;
#endif

      /* preview offset x, y are offset from lcd_start_x, lcd_start_y */
	cam_preview_data.preview_offset_x = 0;	
	cam_preview_data.preview_offset_y = 0;

	cam_preview_data.roi_offset_x	= (kal_uint16)GDI_LAYER_OFFSET+lcd_offset_x;
	cam_preview_data.roi_offset_y	= (kal_uint16)GDI_LAYER_OFFSET+lcd_offset_y;	


	cam_preview_data.image_buffer_p		= (void*)buf_ptr;
	cam_preview_data.image_width			= 320;
	cam_preview_data.image_height			= 240;

	cam_preview_data.buffer_width			= (kal_uint16)layer_width;
	cam_preview_data.buffer_height		= (kal_uint16)layer_height;

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__   
   if(mmi_analog_tv_is_full_screen())
        cam_preview_data.image_buffer_size  = (kal_uint32)((320*240*GDI_LAYER.act_bit_per_pixel)>>3);
   else
#endif 
	cam_preview_data.image_buffer_size  = (kal_uint32)((240*196*GDI_LAYER.act_bit_per_pixel)>>3);

	/* set settings parameters */
	cam_preview_data.effect				= 0;
	cam_preview_data.WB					= 0;
	cam_preview_data.exposure			= 4;
	cam_preview_data.zoom_factor		= 10;
	cam_preview_data.banding_freq		= 0;
	cam_preview_data.flash_mode		= 0;

	cam_preview_data.brightness		= 128;
	cam_preview_data.contrast			= 128;
	cam_preview_data.saturation		= 128;
	cam_preview_data.hue					= 0;
	cam_preview_data.night_mode		= 0;
	
	cam_preview_data.snapshot_number	= 1;

	cam_preview_data.continue_capture = 0;
	
	cam_preview_data.ae_metering_mode 	= 0;
       cam_preview_data.dsc_mode				= 0;
       cam_preview_data.af_metering_mode	= 0;
	cam_preview_data.af_mode=0;			
		
	/* rotate */
	cam_preview_data.rotate 		= 0;//CAMERA_PREVIEW_ROTATE_0;
	
	
#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__   
   if(mmi_analog_tv_is_full_screen())
         cam_preview_data.lcd_rotate= MDI_VIDEO_LCD_ROTATE_270;//MDI_VIDEO_LCD_ROTATE_270;
   else
#endif 
        cam_preview_data.lcd_rotate= 0;//CAMERA_LCM_ROTATE_0;
	/* fixed para */
	cam_preview_data.gamma				= 0;
	cam_preview_data.frame_rate		= 0;
	
	cam_preview_data.update_layer		= GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
	cam_preview_data.update_layer		= GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 ;
	#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__ //bw_20070518 全屏信号差提示
	cam_preview_data.update_layer		=  GDI_LAYER_ENABLE_LAYER_2 ;
	#else
	cam_preview_data.update_layer		=  GDI_LAYER_ENABLE_LAYER_1 ;
	#endif
	cam_preview_data.hw_update_layer	=  GDI_LAYER_ENABLE_LAYER_1;
	cam_preview_data.src_key_color 	=  GDI_COLOR_TRANSPARENT;
	cam_preview_data.roi_background_color = GDI_COLOR_BLACK;


#if defined(NOKE_DEBUG)
	   noke_dbg_printf( "\r mmi_analog_tv_start_preview_by_camera: before cam_preview ! \n " );
#endif
		
    #ifdef __MTK_TARGET__
	ret = media_cam_preview(MOD_MMI, &cam_preview_data);
       if(ret != 0)
	{
		   g_analog_tv_cntx.last_error =MDI_RES_TV_INITIALIZED_ERROR;
	}
	else
	{
	         g_analog_tv_cntx.last_error =MDI_RES_VDOREC_SUCCEED;
	 }
    #endif
	
	mmi_TV_redraw_current_channel();
	mmi_analog_tv_blt_screen();
	mdi_tlg_tv_set_channel( g_AnalogTv_data.g_current_channel,mmi_analog_tv_set_channel_result_handler);//add by hongzhe.liu
#if defined(NOKE_DEBUG)
   	noke_dbg_printf( "\r mmi_analog_tv_start_preview_by_camera  exit [code = %d]! \n ", g_analog_tv_cntx.last_error);
#endif

}

static void mmi_analog_tv_start_preview_wqvga(void)
{

   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_setting_struct video_preview_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    /* user define record size. not used */
//    video_preview_data.user_def_width = 0;
 //   video_preview_data.user_def_height = 0;

    video_preview_data.night = g_analog_tv_cntx.setting.night;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    video_preview_data.hue = 0;
    //video_preview_data.preview_rotate = VDOREC_MAINLCD_ROTATE;
    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__   
   if(mmi_analog_tv_is_full_screen())
    video_preview_data.lcm_rotate= MDI_VIDEO_LCD_ROTATE_270; //hongzhe.liu change lcd_rotate to lcm_rotate
   else
#endif 
    video_preview_data.lcm_rotate= MDI_VIDEO_LCD_ROTATE_0; //hongzhe.liu change lcd_rotate to lcm_rotate

    /* no size limit */
    video_preview_data.size_limit = 0;
            video_preview_data.record_aud = TRUE;
    video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
    video_preview_data.video_format =MDI_VIDEO_VIDEO_FORMAT_MP4;

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
	video_preview_data.video_qty = 1;
#endif 

    video_preview_data.brightness = g_analog_tv_brightness;
    video_preview_data.contrast = g_analog_tv_contrast;
    video_preview_data.saturation = g_analog_tv_saturation;
    video_preview_data.hue  = g_analog_tv_hue;
    
    /*For NTSC/PAL select , user the BAND parameter*/
    video_preview_data.banding = MDI_VIDEO_BANDING_50HZ;
    video_preview_data.zoom = 10;
    /*TO power up TV first*/
    
    //MMI_analog_tv_TRACE(MOD_MMI, "@@@@@TV_IN_POWERED_UP");
    g_analog_tv_cntx.last_error = mdi_video_rec_preview_start(
                                g_analog_tv_cntx.preview_layer_handle,
                               // GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,
                                GDI_LAYER_ENABLE_LAYER_1,
                                GDI_LAYER_ENABLE_LAYER_1,
                                  MMI_TRUE,/*Hongzhe.liu add */
                                &video_preview_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_start_preview
 * DESCRIPTION
 *  Start preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_start_preview(void)
{

    #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\rmmi_analog_tv_start_preview start by wqvga ... \n");
#endif
	 mmi_analog_tv_start_preview_wqvga();
   #elif defined(__EV_TV_PATH_BY_VIDEO__)  //    #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\rmmi_analog_tv_start_preview start by wqvga ... \n");
#endif
	 mmi_analog_tv_start_preview_wqvga();
	  //mmi_analog_tv_start_preview_by_vdorec();
   #else
#if defined(NOKE_DEBUG)
	  noke_dbg_printf("\rmmi_analog_tv_start_preview start by camera begin... \n");
#endif
   	  #if defined(TV_RECORD_SUPPORT)
	   if( GetAnalogTvAppFlags() == 0 )
  	   {
  	   	mmi_analog_tv_start_preview_by_vdorec();
	   }
	  else
	  {
		mmi_analog_tv_start_preview_by_camera();
	  }
	  #else
	  mmi_analog_tv_start_preview_by_camera();
	  #endif
#if defined(NOKE_DEBUG)
	  noke_dbg_printf("\rmmi_analog_tv_start_preview start by camera  end ... \n");	  
#endif
   #endif
}

/*bw_20070427 9:52:40  add analog tv auto test*/
 U8  mmi_get_all_channels_of_current_district(void)
{
/*bw_20070614 重新整理地区列表并将巴西和阿根廷放到n制式里*/
/*bw_20070607 添加地区并整理*/
/*bw_20070515 19:36:11 整理更新地区列表*/
	if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_CHINA_START && g_AnalogTv_data.DistrictSelected<=ANALOG_TV_CHINA_END)		//china
  		return   68;
	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_SHENZHEN_START&& g_AnalogTv_data.DistrictSelected<=ANALOG_TV_SHENZHEN_END)	//shengzhen
  		return 58;
  	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_EUROPE_START && g_AnalogTv_data.DistrictSelected<=ANALOG_TV_EUROPE_END)	//europe
  		return 59;
  	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_VIETNAM_START&& g_AnalogTv_data.DistrictSelected<=ANALOG_TV_VIETNAM_END)	//vietnam
  		return 59;
	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_HONGKONG_START && g_AnalogTv_data.DistrictSelected<=ANALOG_TV_HONGKONG_END)  //Hongkong
		return 57;
	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_AMERICA_START && g_AnalogTv_data.DistrictSelected<=ANALOG_TV_AMERICA_END) 	//usa
		return 67;
	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_BRAZIL_START&& g_AnalogTv_data.DistrictSelected<=ANALOG_TV_BRAZIL_END)   //brazil
		return 67;
	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_ARGENTINA_START&& g_AnalogTv_data.DistrictSelected<=ANALOG_TV_ARGENTINA_END)	//argentina
		return 67;
	else if(g_AnalogTv_data.DistrictSelected>=ANALOG_TV_JAPAN_START&& g_AnalogTv_data.DistrictSelected<=ANALOG_TV_JAPAN_END)	//japan
		return 61;
  	else		//china
  		return 68;
}
	

static void mmi_analog_tv_power_up(void)
{
   
//   if(g_AnalogTv_data.is_power_on)
//   	return;

   g_analog_tv_cntx.last_error=mdi_tlg_tv_power_on();
   g_AnalogTv_data.is_power_on=TRUE;
   /*
   if(g_analog_tv_cntx.last_error==0)
       g_AnalogTv_data.is_power_on=TRUE;
   else
   	g_AnalogTv_data.is_power_on=FALSE;
   */
}


static void mmi_analog_tv_power_down(void)
{
//  if(!g_AnalogTv_data.is_power_on)
 //  	return;
  g_analog_tv_cntx.last_error= mdi_tlg_tv_power_down();
  
//  if(g_analog_tv_cntx.last_error==0)
 //      g_AnalogTv_data.is_power_on=FALSE;
 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_entry_save_confirm_screen
 * DESCRIPTION
 *  enter save confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_entry_save_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ClearInputEventHandler(MMI_DEVICE_KEY);

#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It 
    DisplayConfirm(STR_GLOBAL_YES,IMG_GLOBAL_YES,
        STR_GLOBAL_NO,IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,WARNING_TONE);

    SetRightSoftkeyFunction(mmi_analog_tv_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_saving_screen, KEY_EVENT_UP);

#else
	
#ifdef __MMI_VDOREC_MMS_SUPPORT__
#if defined(NOKE_DEBUG)
    noke_dbg_printf("\r\n mmi_analog_tv_entry_save_confirm_screen () \r\n");
#endif
    /* support link to MMS */
    g_analog_tv_cntx.is_foward_to = FALSE;
    g_analog_tv_cntx.is_save_done_when_mt = FALSE;

    EnableCenterSoftkey(0, IMG_ID_VDOREC_FORWARD_TO_MMS);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)

    DisplayConfirmRotated(STR_GLOBAL_YES,IMG_GLOBAL_YES,
        STR_GLOBAL_NO,IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,WARNING_TONE,
        MMI_FRM_SCREEN_ROTATE_270);
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    DisplayConfirm(STR_GLOBAL_YES,IMG_GLOBAL_YES,
        STR_GLOBAL_NO,IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,WARNING_TONE);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    register_center_softkey_to_enter_key();

    SetRightSoftkeyFunction(mmi_analog_tv_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_saving_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_analog_tv_save_confirm_forward_to, KEY_EVENT_UP);

#else /* __MMI_VDOREC_MMS_SUPPORT__ */ 
    /* do not support link to MMS */

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)

    DisplayConfirmRotated(STR_GLOBAL_YES, IMG_GLOBAL_YES,
        STR_GLOBAL_NO,IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,WARNING_TONE,
        MMI_FRM_SCREEN_ROTATE_270);
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    DisplayConfirm(STR_GLOBAL_YES,IMG_GLOBAL_YES,
        STR_GLOBAL_NO,IMG_GLOBAL_NO,
        get_string(STR_ID_VDOREC_NOTIFY_SAVE_CONFIRM),
        IMG_GLOBAL_QUESTION,WARNING_TONE);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    SetRightSoftkeyFunction(mmi_analog_tv_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_saving_screen, KEY_EVENT_UP);

#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_save_confirm_no
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_save_confirm_no(void)
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
    // TODO: to call the correct function
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);

    /* the seq num is already increase, so if we dont want to save this file, decrease it */
    ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);

    if (g_vdorec_cntx.filename_seq_no > 1)
    {
        g_vdorec_cntx.filename_seq_no--;
    }

    WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);

    GoBackHistory();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_disply_popup
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
static void mmi_analog_tv_disply_popup(PU8 str_ptr, U16 img_id, U16 image_on_bottom, U16 tone_duration, U16 tone_id)
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
 * FUNCTION
 *  mmi_TV_in_exit_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_exit_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resume background play */
    mdi_audio_resume_background_play();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_saving_screen_del_hdlr
 * DESCRIPTION
 *  Del screen callback function
 * PARAMETERS
 *  dummy_ptr       [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_analog_tv_saving_screen_del_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_analog_tv_cntx.is_saving)
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
 *  mmi_TV_in_entry_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_entry_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];


#if defined(TV_RECORD_SUPPORT)
//huyanwei Add It 
#if defined(NOKE_DEBUG)
    noke_dbg_printf("r\n mmi_analog_tv_entry_saving_screen() \r\n");
#endif

    g_analog_tv_cntx.is_saving = TRUE;
    SetDelScrnIDCallbackHandler(SCR_ID_TV_IN_SAVING, mmi_analog_tv_saving_screen_del_hdlr);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_TV_IN_SAVING, mmi_analog_tv_exit_saving_screen, mmi_analog_tv_entry_saving_screen, NULL);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory66Screen(STR_ID_VDOREC_APP_NAME,MAIN_MENU_TITLE_MULTIMEDIA_ICON,
          0,0,0,0,
        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVING),
        IMG_GLOBAL_PROGRESS, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_TV_IN_SAVING);

    if (guiBuffer == NULL)
    {
        /* check is entry from vdorec app */
        mmi_vdoply_get_storage_file_path(buf_filepath);
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\r\n Huyanwei Modify It : mdi_video_rec_save_file( before ) \r\n");
#endif

        g_analog_tv_cntx.last_error = mdi_video_rec_save_file(buf_filepath, mmi_analog_tv_save_result_hdlr_callback);

        if (mmi_analog_tv_check_and_display_error_popup() == TRUE) /* TRUE means has error */
        {
            /* if has error, cant save, delete temp file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);
            return;
        }
    }

#else

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VDOREC_MMS_SUPPORT__
    if (g_analog_tv_cntx.is_save_done_when_mt && g_analog_tv_cntx.is_foward_to)
    {
        /* save done while in MT, when back from MT, will enter here */
        g_analog_tv_cntx.is_save_done_when_mt = FALSE;

        if (g_analog_tv_cntx.save_result >= 0)
        {
            mmi_fmgr_util_load_filepath(buf_filepath, FMGR_PATH_ID_VIDEO);
            mms_content_insert_hdlr((PS8) buf_filepath);
            DeleteUptoScrID(SCR_ID_VDOREC_APP);
            return;
        }
        else if (g_analog_tv_cntx.save_result == MDI_RES_VDOREC_ERR_DISK_FULL)
        {
            mmi_analog_tv_disply_popup((PU8) GetString(FMGR_FS_DISK_FULL_TEXT),IMG_GLOBAL_ACTIVATED,1,ST_NOTIFYDURATION,SUCCESS_TONE);
        }
        else
        {
            mmi_analog_tv_disply_popup((PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),IMG_GLOBAL_WARNING,1,ST_NOTIFYDURATION,WARNING_TONE);
        }

        /* if clam is close, delete one more screen, avoid enter video recorder */
        if (IsClamClose())
        {
            DeleteNHistory(1);
        }

        return;
    }
#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    g_analog_tv_cntx.is_saving = TRUE;
    SetDelScrnIDCallbackHandler(SCR_ID_TV_IN_SAVING, mmi_analog_tv_saving_screen_del_hdlr);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_TV_IN_SAVING, mmi_analog_tv_exit_saving_screen, mmi_analog_tv_entry_saving_screen, NULL);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory66Screen(STR_ID_VDOREC_APP_NAME,MAIN_MENU_TITLE_MULTIMEDIA_ICON,
          0,0,0,0,
        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVING),
        IMG_GLOBAL_PROGRESS, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_TV_IN_SAVING);

    if (guiBuffer == NULL)
    {
        /* check is entry from vdorec app */
        mmi_vdoply_get_storage_file_path(buf_filepath);
#if defined(NOKE_DEBUG)
	 noke_dbg_printf("\r\n Huyanwei Modify It : mdi_video_rec_save_file( before ) \r\n");
#endif

        g_analog_tv_cntx.last_error = mdi_video_rec_save_file(buf_filepath, mmi_analog_tv_save_result_hdlr_callback);

        if (mmi_analog_tv_check_and_display_error_popup() == TRUE) /* TRUE means has error */
        {
            /* if has error, cant save, delete temp file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);
            return;
        }
    }

#endif

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}

#if defined(TV_RECORD_SUPPORT)
//Huyanwei Add It for TV Record

void mmi_tv_record_entry_save_confirm_screen(void)
{
#if defined(NOKE_DEBUG)
       noke_dbg_printf("\r\n Huyanwei Add It For Debug : mmi_tv_record_entry_save_confirm_screen(........) File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
	mmi_analog_tv_entry_saving_screen();
}


#if 0
void mmi_tv_record_get_save_filename(S8 *file_buf_p)
{
	//mmi_vdorec_get_save_filename(file_buf_p);
}
#endif

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_check_and_display_error_popup
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*bw_20070427 9:52:40  add analog tv auto test*/
 BOOL mmi_analog_tv_check_and_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_analog_tv_cntx.last_error != MDI_RES_VDOREC_SUCCEED)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        switch (g_analog_tv_cntx.last_error)
        {
            case MDI_RES_VDOREC_ERR_DISK_FULL:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOREC_ERR_NO_DISK:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_NO_MEMORY_CARD),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case MDI_RES_VDOREC_ERR_WRITE_PROTECTION:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_WRITE_PROTECTION),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

                /* followings are serious error, has to exit app */
            case MDI_RES_VDOREC_ERR_POWER_ON_FAILED:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_HW_NOT_READY),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;
            case MDI_RES_VDOREC_ERR_HW_NOT_READY:
			//mmi_vdorec_disply_popup((PU8)GetString(STR_ID_VDOREC_NOTIFY_HW_NOT_READY), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
			//DeleteNHistory(1);
			break;
		//case MDI_RES_VDOREC_TVIN_NO_SIG:
			//mmi_vdorec_disply_popup((PU8)GetString(STR_ID_VDOREC_NOTIFY_TVIN_NO_SIG), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
			//DeleteNHistory(1);
		//	break;	
	     case MDI_RES_TV_INITIALIZED_ERROR:  //pjqadd 070319
			mmi_analog_tv_disply_popup((PU8)GetString(STR_ID_TV_NOTIFY_INITIALIZED_FAIL), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
			DeleteNHistory(1);
			break;    
            case MDI_RES_VDOREC_ERR_PREVIEW_FAILED:
            case MDI_RES_VDOREC_ERR_RESUME_FAILED:
            case MDI_RES_VDOREC_ERR_PAUSE_FAILED:
            case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
            case MDI_RES_VDOREC_ERR_RECORD_FAILED:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_ERROR),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;

            case VDOREC_ERR_CORRUPT_FAT:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_FAT_ALLOC_ERROR_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;

            case VDOREC_ERR_PHONE_DISK_FULL:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;

            case VDOREC_ERR_WRITE_PROTECT:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case VDOREC_ERR_CARD_DISK_FULL:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                break;

            case VDOREC_ERR_ROOT_DIR_FULL:
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                DeleteNHistory(1);
                break;

            default:
			mmi_analog_tv_disply_popup((PU8)GetString(STR_ID_TV_NOTIFY_INITIALIZED_FAIL), IMG_GLOBAL_WARNING, 1, ST_NOTIFYDURATION, WARNING_TONE);
			DeleteNHistory(1);
			break;    
//                MMI_ASSERT(0);  /* use assert here, make sure all error case is handled properly */
        }

        /* clear record keys */
        ClearKeyHandler(VDOREC_RECORD_KEY, KEY_EVENT_UP);

        if (VDOREC_RECORD_KEY != -1)
        {
            ClearKeyHandler(VDOREC_RECORD_KEY, KEY_EVENT_UP);
        }

        g_analog_tv_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_record_timer_cyclic
 * DESCRIPTION
 *  record timer cyclic to get and draw timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_record_timer_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 prev_time_in_sec;
    U32 time_in_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev_time_in_sec = (U32) (g_analog_tv_cntx.record_time / 1000);

    mdi_video_rec_get_cur_record_time(&g_analog_tv_cntx.record_time);
    time_in_sec = (U32) (g_analog_tv_cntx.record_time / 1000);
    g_analog_tv_cntx.setting.time_limit		= 0;
    /* time limit check */

    if ((time_in_sec > prev_time_in_sec) || (prev_time_in_sec == 0))
    {
        mmi_analog_tv_draw_panel_timer();
        mmi_analog_tv_blt_screen();
    }

   UI_start_timer(200, mmi_analog_tv_record_timer_cyclic);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_record_result_hdlr_callback
 * DESCRIPTION
 *  record result callback hdlr
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN]        Current state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_record_result_hdlr_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((g_analog_tv_cntx.state == ANALOG_TV_STATE_RECORD) || (g_analog_tv_cntx.state == ANALOG_TV_STATE_PAUSE));

    UI_cancel_timer(mmi_analog_tv_record_timer_cyclic);


    if (result == MDI_RES_VDOREC_DISK_FULL)
    {
        mmi_analog_tv_disply_popup(
            (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }
    else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
    {
        mmi_analog_tv_disply_popup(
            (PU8) GetString(STR_ID_VDOREC_NOTIFY_REACH_SIZE_LIMIT),
            IMG_GLOBAL_INFO,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }
    else if (result == MDI_RES_VDOREC_ERR_FAILED)
    {
        mmi_analog_tv_disply_popup(
            (PU8) GetString(STR_ID_VDOREC_NOTIFY_ERROR),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        return;
    }
    else
    {
        /* unhandle return */
        //MMI_ASSERT(0);
    }


#ifdef __MMI_VDOREC_MMS_SUPPORT__
	   mmi_analog_tv_entry_save_confirm_screen();
#else 
	   mmi_analog_tv_entry_saving_screen();
#endif 

#if defined(NOKE_DEBUG)
     noke_dbg_printf("\r\n Huyanwei Add It For Debug : mmi_tv_record_entry_save_confirm_screen(before) File = %s line = %d \r\n",__FILE__,__LINE__);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_save_confirm_forward_to
 * DESCRIPTION
 *  forward to key pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VDOREC_MMS_SUPPORT__
static void mmi_analog_tv_save_confirm_forward_to(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_foward_to = TRUE;
    mmi_analog_tv_entry_saving_screen();
}
#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_save_result_hdlr_callback
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_save_result_hdlr_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VDOREC_MMS_SUPPORT__
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_analog_tv_cntx.is_saving = FALSE;

    /* if video recorder is already removed from history , do not show popup */
    if (!IsScreenPresent(SCR_ID_TV_IN_APP))
    {
        return;
    }

    if (g_analog_tv_cntx.is_foward_to)
    {
    #ifdef __MMI_VDOREC_MMS_SUPPORT__

        /* link to foward to */

        if (!isInCall())
        {
            /* enter only not in call and wap not in call */

            DeleteScreenIfPresent(SCR_ID_TV_IN_SAVING);

            if (result >= 0)
            {
                /* foward to MMS */
                mmi_fmgr_util_load_filepath(buf_filepath, FMGR_PATH_ID_VIDEO);
                mms_content_insert_hdlr((PS8) buf_filepath);
                DeleteUptoScrID(SCR_ID_TV_IN_APP);
                return;
            }
            else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);
            }
            else
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }

            DeleteScreenIfPresent(SCR_ID_TV_IN_SAVING);
            DeleteScreenIfPresent(SCR_ID_TV_IN_SAVE_CONFIRM);

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

            g_analog_tv_cntx.save_result = result;
            g_analog_tv_cntx.is_save_done_when_mt = TRUE;
            return;

        }

    #endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_TV_IN_SAVING);

        /* Alarm playing */
        if (AlmIsTonePlaying())
        {
            return;
        }

        /* is in call, they have higher priority, do not show popup */
        if (!isInCall())
        {
            /* enter only not in call and wap not in call */
            if (result >= 0)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);
            }
            else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);
            }
            else
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVE_FILE_ERROR),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }

            DeleteScreenIfPresent(SCR_ID_TV_IN_SAVING);
            DeleteScreenIfPresent(SCR_ID_TV_IN_SAVE_CONFIRM);

            /* if clam is close, delete one more screen, avoid enter video recorder */
            if (IsClamClose())
            {
                DeleteNHistory(1);
            }

        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_init_option_menu
 * DESCRIPTION
 *  int option menu hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_init_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_TV_IN_TO_PLAYER, mmi_analog_tv_highlight_to_vdoply);

//    SetHiliteHandler(MENU_ID_TV_IN_REC_SETTING, mmi_TV_in_highlight_rec_setting);
  //  SetHiliteHandler(MENU_ID_TV_IN_PLAY_SETTING, mmi_TV_in_highlight_play_setting);

    SetHiliteHandler(MENU_ID_TV_IN_STORAGE_PATH, mmi_analog_tv_highlight_storage);
    //SetHintHandler(MENU_ID_TV_IN_STORAGE_PATH, mmi_vdorec_hint_storage);

    //SetHiliteHandler(MENU_ID_TV_IN_RESTORE, mmi_TV_in_highlight_restore_default);

    /*For submenu of option*/
    SetHiliteHandler(MENU_ID_TV_IN_SOURCE_FORMAT, mmi_analog_tv_highlight_district_select);
    //SetHiliteHandler(MENU_ID_TV_IN_ACC, mmi_TV_in_highlight_acc);
    //SetHiliteHandler(MENU_ID_TV_IN_BRIGHT, mmi_TV_in_highlight_brightness);
    //SetHiliteHandler(MENU_ID_TV_IN_CONTRAST, mmi_TV_in_highlight_contrast);
    //SetHiliteHandler(MENU_ID_TV_IN_SATURATION, mmi_TV_in_highlight_saturation);
    //SetHiliteHandler(MENU_ID_TV_IN_HUE, mmi_TV_in_highlight_hue);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_highlight_to_vdoply
 * DESCRIPTION
 *  hiligith to vdorec menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_highlight_to_vdoply(void)
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
 *  mmi_TV_in_highlight_rec_setting
 * DESCRIPTION
 *  highlight video setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_highlight_rec_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_rec_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_entry_rec_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_entry_rec_setting_screen
 * DESCRIPTION
 *  entry video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_entry_rec_setting_screen(void)
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
	UI_image_ID_type item_icons[VDOREC_VIDEO_SETTING_ITEM_COUNT*2] =
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

    EntryNewScreen(SCR_ID_TV_IN_REC_SETTING, mmi_analog_tv_exit_rec_setting_screen, NULL, NULL);

    InitializeCategory57Screen();

   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define CREATE_VIDEO_SETTING_INLINE_SELECT(a, A)                                                                             \
   {                                                                                                                            \
      g_analog_tv_menu_cntx.video_setting_inline.##a##_selected = g_analog_tv_cntx.setting.##a;                                       \
      for(i = 0 ; i < VDOREC_SETTING_##A##_COUNT; i++)                                                                          \
      {                                                                                                                         \
         g_analog_tv_menu_cntx.video_setting_inline.##a##_str[i] = (UI_string_type)GetString((U16)(STR_ID_VDOREC_##A##_START+1+i));\
      }                                                                                                                         \
      SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_VDOREC_##A)));                        \
      SetInlineItemActivation(&wgui_inline_items[item_offset],                                                                  \
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,                                                           \
                              0 );                                                                                              \
      SetInlineItemSelect( &wgui_inline_items[item_offset++],                                                                   \
                           VDOREC_SETTING_##A##_COUNT,                                                                          \
                           (U8**)g_analog_tv_menu_cntx.video_setting_inline.##a##_str,                                             \
                           &g_analog_tv_menu_cntx.video_setting_inline.##a##_selected);                                            \
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    //CREATE_VIDEO_SETTING_INLINE_SELECT(video_size, VIDEO_SIZE);
#endif 
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
  //  CREATE_VIDEO_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY);
	#endif /* __VDOREC_FEATURE_VIDEO_QTY__ */

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(size_limit, SIZE_LIMIT);
	#endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(time_limit, TIME_LIMIT);
	#endif /* __VDOREC_FEATURE_TIME_LIMIT__ */

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CREATE_VIDEO_SETTING_INLINE_SELECT(record_aud, RECORD_AUD);
	#endif /* __VDOREC_FEATURE_RECORD_AUD__ */

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(video_format, VIDEO_FORMAT);
	#endif /* __VDOREC_FEATURE_VIDEO_FORMAT__ */

    guiBuffer = GetCurrGuiBuffer(SCR_ID_TV_IN_REC_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_TV_IN_REC_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, VDOREC_VIDEO_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_analog_tv_rec_setting_highlight_hdlr);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
	#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ && __MMI_SCREEN_ROTATE__ */

    /* show category */
    ShowCategory57Screen(STR_ID_VDOREC_VIDEO_SETTING,MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_analog_tv_rec_setting_lsk_press);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}
//#endif /* !__VDOREC_FEATURE_MERGE_MENU__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_exit_rec_setting_screen
 * DESCRIPTION
 *  exit video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_exit_rec_setting_screen(void)
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
    h.scrnID = SCR_ID_TV_IN_REC_SETTING;
    h.entryFuncPtr = mmi_analog_tv_entry_rec_setting_screen;
    pfnUnicodeStrcpy((S8*) h.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_rec_setting_highlight_hdlr
 * DESCRIPTION
 *  video setting highlight hdlr
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_analog_tv_rec_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_analog_tv_rec_setting_lsk_press);
}


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
static void mmi_analog_tv_rec_setting_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define VIDEO_SETTING_SET_SELECTED_VALUE(a, A)                                        \
   {                                                                                     \
      g_analog_tv_cntx.setting.##a = g_analog_tv_menu_cntx.video_setting_inline.##a##_selected;\
   }


    VIDEO_SETTING_SET_SELECTED_VALUE(video_size, VIDEO_SIZE);
    VIDEO_SETTING_SET_SELECTED_VALUE(video_qty, VIDEO_QTY);
    VIDEO_SETTING_SET_SELECTED_VALUE(size_limit, SIZE_LIMIT);
    VIDEO_SETTING_SET_SELECTED_VALUE(time_limit, TIME_LIMIT);
    VIDEO_SETTING_SET_SELECTED_VALUE(record_aud, RECORD_AUD);
    VIDEO_SETTING_SET_SELECTED_VALUE(video_format, VIDEO_FORMAT);

    // TODO: modify here
    mmi_analog_tv_store_setting();

    mmi_analog_tv_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_load_setting
 * DESCRIPTION
 *  load setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_analog_tv_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* read storage setting from video player */
S16 index;
#if defined(NOKE_DEBUG)
   	noke_dbg_printf( "\rmmi_analog_tv_load_setting:enter \n" );
#endif
    mmi_vdoply_load_setting();

   /*bw070417A 上下方向键改为在channellist中切换 */
     /*Read Channel list*/
 /*bw070717 [ALL][ALL] TV频道存储*/

       ReadRecord( NVRAM_ANALOG_TV_CHANNEL_LID, 1, (void*)g_AnalogTv_data.ChannelList, NVRAM_ANALOG_TV_CHANNEL_SIZE, &error );
       //memset( g_AnalogTv_data.ChannelList, 0, ANALOG_TV_CHANNEL_NUM );
#if 1
/* Hongzhe.liu add test code here for nvram record read */
#if defined(NOKE_DEBUG)
for( index = 0; index < NVRAM_ANALOG_TV_CHANNEL_SIZE; index ++ )
{
	noke_dbg_printf("\r* g_AnalogTv_data.ChannelList[%d] = 0x%x \n", index, g_AnalogTv_data.ChannelList[index]);
}
#endif

/* Test code end */	   
#endif  
     /* if already loaded into memory, do not need load again */
    if (!g_analog_tv_cntx.is_setting_loaded)
    {
        ReadRecord(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_analog_tv_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE, &error);
        
        g_analog_tv_cntx.setting.led_value = VDOREC_DEFAULT_PREVIEW_LED_VALUE;
	
        /* read analog tv district  */
        ReadValue(NVRAM_ANALOG_TV_DISTRICT_SELECT, &g_AnalogTv_data.DistrictSelected, DS_SHORT, &error);
        if(g_AnalogTv_data.DistrictSelected == 0xffff)
	 {
	 #if defined(U808_HUAYI)&&!defined(U808_HUAYI_N)
		g_AnalogTv_data.DistrictSelected= ANALOG_TV_AREA_SHENZHEN;
	 #elif defined(U808_HUAYI_N)//bw_20070625 U806_HUAYI_N默认印尼
		 g_AnalogTv_data.DistrictSelected=ANALOG_TV_AREA_INDONESIA;
	 #else
	     g_AnalogTv_data.DistrictSelected= ANALOG_TV_AREA_CHINA;
	 #endif
		
	 }
	 ReadValue(NVRAM_ANALOG_TV_MODE_SELECT, &g_AnalogTv_data.ModeSelected, DS_BYTE, &error);
        if(g_AnalogTv_data.ModeSelected == 0xff)
	 {
		g_AnalogTv_data.ModeSelected= 0;
		
	 }	
	 mmi_tv_max_index=mmi_get_all_channels_of_current_district();

	 /*Read Volume*/
	 ReadValue( NVRAM_ANALOG_TV_VOLUME, &g_AnalogTv_data.volume, DS_BYTE, &error );
        ReadValue( NVRAM_ANALOG_TV_VOLUME_MUTE, &g_analog_tv_cntx.is_mute, DS_BYTE, &error );//P_6226_M24_bw_z0149 modified: volume set mute, still phonate when fist entry
		if(g_analog_tv_cntx.is_mute==0xff) //P_6226_M24_bw_z0149 modified: volume set mute, still phonate when fist entry
			g_analog_tv_cntx.is_mute=FALSE;
		if(g_AnalogTv_data.volume==0xff)//added by bw,
			g_AnalogTv_data.volume=2;;

        /*Temp method*/
        // TODO: Make the setting correct
       // g_TV_in_cntx.setting.video_size = MDI_VIDEO_VIDEO_SIZE_QCIF;
	// g_TV_in_cntx.setting.contrast= TV_IN_SOURCE_FORMAT_PAL;  //use contrast para to store tv-in format para.	
        g_analog_tv_cntx.is_setting_loaded = TRUE;

        /*For default value of TV_in Parameter*/
        g_analog_tv_brightness = 128;	//80;
        g_analog_tv_contrast = 128;		//80;
        g_analog_tv_saturation = 128;	//80
        g_analog_tv_hue = 0;			//80

    }

#if defined(NOKE_DEBUG)
   	noke_dbg_printf( "\rmmi_analog_tv_load_setting:exit \n" );
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_store_setting
 * DESCRIPTION
 *  store setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_analog_tv_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_analog_tv_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE, &error);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_TV_in_highlight_play_setting
 * DESCRIPTION
 *  store setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_analog_tv_highlight_play_setting(void)
{

    SetLeftSoftkeyFunction(mmi_analog_tv_entry_play_setting, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_entry_play_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

}


static void mmi_analog_tv_entry_play_setting(void)
{
}

/*
    we need one category for 2 inline item and 3 slide
*/

static void mmi_analog_tv_highlight_district_select(void)
{
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_district_select, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_entry_district_select, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

}
static void mmi_analog_tv_highlight_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_entry_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}

static void mmi_analog_tv_highlight_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_restore_default_confirm_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_analog_tv_entry_restore_default_confirm_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_analog_tv_entry_restore_default_confirm_screen(void)
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
    SetLeftSoftkeyFunction(mmi_analog_tv_entry_restore_default_confirm_yes, KEY_EVENT_UP);
}

static void mmi_analog_tv_entry_restore_default_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* restore default values */
    //mmi_vdorec_restore_setting();

    mmi_analog_tv_disply_popup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, ST_NOTIFYDURATION, SUCCESS_TONE);
    DeleteNHistory(1);
}

static void mmi_analog_tv_entry_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_TV_IN_STORAGE, NULL, mmi_analog_tv_entry_storage_screen, NULL);

    nItems = GetNumOfChild(MENU_ID_TV_IN_STORAGE_PATH);
    GetSequenceStringIds(MENU_ID_TV_IN_STORAGE_PATH, ItemList);
    GetSequenceImageIds(MENU_ID_TV_IN_STORAGE_PATH, ItemIcons);
    SetParentHandler(MENU_ID_TV_IN_STORAGE_PATH);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory11Screen(
        STR_ID_VDOREC_STORAGE,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        mmi_vdoply_get_storage(),   /* current index */
        NULL);

    SetLeftSoftkeyFunction(mmi_analog_tv_set_storage, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

static void mmi_analog_tv_set_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    S8 buf[64];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    S32 create_result;
    U16 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage = (U16) GetCurrHiliteID();

    if (storage == MMI_PUBLIC_DRV)
    {
        ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    }
    else if (storage == MMI_CARD_DRV)
    {
        ret_drv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    }
    else
    {
        ret_drv = 0;
        ASSERT(0);
    }

    mmi_vdoply_set_storage(storage);

    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        AnsiiToUnicodeString(buf_filepath, buf);

        file_handle = FS_Open((kal_uint16*) buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle >= 0)
        {
            /* drive avalialbe */
            FS_Close(file_handle);

            /* check if photo path exist or not */
            mmi_vdoply_get_storage_file_path(buf_filepath);
            create_result = mmi_vdoply_create_file_dir(buf_filepath);

            if (create_result == FS_WRITE_PROTECTION)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                mmi_vdoply_set_storage(MMI_PUBLIC_DRV);
            }
            else if (create_result == FS_DISK_FULL)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                mmi_vdoply_set_storage(MMI_PUBLIC_DRV);
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    0,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
                mmi_vdoply_set_storage(MMI_PUBLIC_DRV);
            }
            else
            {
                mmi_analog_tv_disply_popup(
                    (PU8) GetString(STR_GLOBAL_DONE),
                    IMG_GLOBAL_ACTIVATED,
                    1,
                    ST_NOTIFYDURATION,
                    SUCCESS_TONE);
                DeleteNHistory(1);
            }

        }
        else
        {
            mmi_analog_tv_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                ST_NOTIFYDURATION,
                WARNING_TONE);
            /* set phone internal space as default */
            mmi_vdoply_set_storage(MMI_PUBLIC_DRV);
        }
    }
    else
    {
        /* get drive error  */
        mmi_analog_tv_disply_popup(
            (PU8) GetString(STR_ID_VDOREC_NOTIFY_NO_MEMORY_CARD),
            IMG_GLOBAL_WARNING,
            1,
            ST_NOTIFYDURATION,
            WARNING_TONE);
        /* set phone internal space as default */
        mmi_vdoply_set_storage(MMI_PUBLIC_DRV);
    }

    mmi_vdoply_store_setting();
}
static void mmi_analog_tv_entry_district_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_TV_IN_SOURCE_FORMAT, NULL, mmi_analog_tv_entry_district_select, NULL);

    nItems = GetNumOfChild(MENU_ID_TV_IN_SOURCE_FORMAT);
    GetSequenceStringIds(MENU_ID_TV_IN_SOURCE_FORMAT, ItemList);
    GetSequenceImageIds(MENU_ID_TV_IN_SOURCE_FORMAT, ItemIcons);
    SetParentHandler(MENU_ID_TV_IN_SOURCE_FORMAT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory11Screen(
        STR_ID_TV_IN_SOURCE_FORMAT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        mmi_analog_tv_get_selected_district(),   /* current index */
        NULL);

    SetLeftSoftkeyFunction(mmi_analog_tv_store_district_select, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


static void mmi_analog_tv_resize_preview_layer(void)
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
    if (g_analog_tv_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_SQCIF)
    {
        video_width = 129;
        video_height = 96;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    if (g_analog_tv_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QQVGA)
    {
        video_width = 160;
        video_height = 120;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    if (g_analog_tv_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QCIF)
    {
        video_width = 176;
        video_height = 144;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    if (g_analog_tv_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF)
    {
        video_width = 352;
        video_height = 288;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

    gdi_util_fit_box(
        GDI_UTIL_MODE_LONG_SIDE_FIT,
        g_vdorec_osd_cntx02.preview_wnd.rect.width,
        g_vdorec_osd_cntx02.preview_wnd.rect.height,
        video_width,
        video_height,
        &resized_offset_x,
        &resized_offset_y,
        &resized_width,
        &resized_height);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    gdi_layer_resize(resized_width, resized_height);
    gdi_layer_set_position(
        g_vdorec_osd_cntx02.preview_wnd.rect.offset_x + resized_offset_x,
        g_vdorec_osd_cntx02.preview_wnd.rect.offset_y + resized_offset_y);

    gdi_layer_pop_and_restore_active();

}
#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__//bw_20070518 全屏信号差提示
/*****************************************************************************
 * FUNCTION
 *  SignalQualityHintCycle
 * DESCRIPTION
 * layer fade
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void SignalQualityHintCycle()
{
	 U16 sigindicate;
	static S16  opacity=0;

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "SignalQualityHintCycle calling " );
#endif
	 UI_cancel_timer(SignalQualityHintCycle);

	 return;

	 
	 gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
	 #ifndef MMI_ON_WIN32
	 //Huyanwei Add It
	 TLGAPP_GetTVSSI(&sigindicate);
	 #endif
	 if(sigindicate<3)
	 {
	 	opacity=255;
	 }
	 else
	 {
	 opacity=opacity-32;
	 if(opacity<32)
	 	opacity=0;
	 
	 }

	 
	 gdi_layer_set_opacity(TRUE, opacity);
	 gdi_layer_pop_and_restore_active();
	 mmi_analog_tv_blt_screen();

       UI_start_timer(3000/*200*/,SignalQualityHintCycle);
}
/*****************************************************************************
 * FUNCTION
 *  DrawSignalHintOnOsd
 * DESCRIPTION
 * layer fade
 * draw singnal quality string
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DrawSignalHintOnOsd()
{
	S32 str_w, str_h;
	S32 x1, y1, x2, y2;
	color signal_text_color = pixtel_UI_color( 0, 66, 132 );
	color signal_text_bord_color = pixtel_UI_color( 255, 255, 255 );
	UI_string_type	signal_hint_string=(UI_string_type) GetString(STR_ID_SIGNAL_QUALITY_HINT);
	UI_push_text_clip();
	UI_set_font( &MMI_medium_font );
	UI_set_text_color( signal_text_color );
	UI_set_text_border_color( signal_text_bord_color );
	UI_measure_string(signal_hint_string , &str_w, &str_h );
	x1 = (UI_device_height-str_w)/2;
	y1 = (UI_device_width- str_h )-4;//y1 = (UI_device_width- str_h )/ 2;
	x2 = x1 + str_w;
	y2 = y1 +str_h;
	UI_set_text_clip( x1-1, y1-1, x2+1, y2+1 );
	UI_move_text_cursor( x1, y1 );
UI_print_bordered_text( signal_hint_string);

	UI_pop_text_clip();

}
#endif

#ifdef __ANALOG_TV_FEATURE_FULL_SCREEN__
static void mmi_analog_tv_to_full_screen_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\r mmi_analog_tv_to_full_screen_screen entering \n" );
#endif
	gdi_layer_reset_clip();
	gdi_layer_reset_text_clip();

	entry_full_screen();
	/***************************************************************************** 
	* Create layers 
	*****************************************************************************/
	gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
         g_analog_tv_cntx.lcd_width = 400;
        #else
	g_analog_tv_cntx.lcd_width = UI_device_height;
        #endif
	g_analog_tv_cntx.lcd_height = UI_device_width;

	/************ base layer layer ************/
	gdi_layer_get_base_handle(&g_analog_tv_cntx.base_layer_handle);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_resize(g_analog_tv_cntx.lcd_width, g_analog_tv_cntx.lcd_height);
	//gdi_layer_clear(GDI_COLOR_BLACK);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT); //hongzhe.liu
	/************ preview window layer ************/
	/* free layers */
	if(g_analog_tv_cntx.preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
	{
	gdi_layer_free(g_analog_tv_cntx.preview_layer_handle);
		g_analog_tv_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	}

	/* create at 0,0, then move to correct position after rotate */
	gdi_layer_create(0,
					0,
					g_analog_tv_cntx.lcd_width,
					g_analog_tv_cntx.lcd_height,
					&g_analog_tv_cntx.preview_layer_handle);
	
	gdi_layer_push_and_set_active(g_analog_tv_cntx.preview_layer_handle);

	gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
	
        #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
          gdi_layer_resize(400, UI_device_width);
        #else
	gdi_layer_resize(UI_device_height, UI_device_width);
        #endif
	gdi_layer_clear(GDI_COLOR_BLACK);
	//gdi_layer_clear(GDI_COLOR_TRANSPARENT); //hongzhe.liu add
	gdi_layer_set_position(0,0);
	gdi_layer_pop_and_restore_active();

	/************ osd layer ************/
	/* free osd layer */
	if(g_analog_tv_cntx.osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
	{
	gdi_layer_free(g_analog_tv_cntx.osd_layer_handle);
	g_analog_tv_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	}

	/* free buffer */
	if(g_analog_tv_cntx.osd_layer_buf_ptr != NULL)
	{
	mmi_frm_scrmem_free((void*)g_analog_tv_cntx.osd_layer_buf_ptr);
	g_analog_tv_cntx.osd_layer_buf_ptr = NULL;
	}

	/* create a double layer frame from outside memory */
	g_analog_tv_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc(VDOREC_OSD_BUFFER_SIZE);
	gdi_layer_create_double_using_outside_memory(0,
	                                         0, 
	                                         g_analog_tv_cntx.lcd_width, 
	                                         g_analog_tv_cntx.lcd_height,
	                                         &g_analog_tv_cntx.osd_layer_handle, 
	                                        (PU8) g_analog_tv_cntx.osd_layer_buf_ptr, 
	                                        (S32) VDOREC_OSD_BUFFER_SIZE);        /* this buffer is double buffer size */

	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
	gdi_layer_set_opacity(TRUE, 0);
	/* clear both layer */
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
          gdi_layer_resize(400, UI_device_width);  //jonathan
        #else
	gdi_layer_resize(UI_device_height, UI_device_width);
        #endif
	gdi_layer_toggle_double();
	gdi_layer_set_opacity(TRUE, 0);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        #if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__)
          gdi_layer_resize(400, UI_device_width);  //jonathan
        #else
	gdi_layer_resize(UI_device_height, UI_device_width);
        #endif
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__//bw_20070518 全屏信号差提示
	SignalQualityHintCycle();
	DrawSignalHintOnOsd();
#ifdef __ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__	
	gdi_layer_set_rotate(GDI_LAYER_ROTATE_180); //hongzhe.liu : maybe 270 ???
#endif
#endif
	gdi_layer_pop_and_restore_active();

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\r mmi_analog_tv_to_full_screen_screen end \n" );
#endif
}	
/*bw_20070427 9:52:40  add analog tv auto test*/
 void mmi_analog_tv_to_normal_screen_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\rmmi_analog_tv_to_normal_screen_screen entering \n" );
#endif
	gdi_layer_reset_clip();
	gdi_layer_reset_text_clip();
	/***************************************************************************** 
	* Create layers 
	*****************************************************************************/
	gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__	
	 UI_cancel_timer(SignalQualityHintCycle);
#endif

	/************ base layer layer ************/
	gdi_layer_get_base_handle(&g_analog_tv_cntx.base_layer_handle);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_resize(UI_device_height, UI_device_width);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	g_analog_tv_cntx.lcd_width = UI_device_width;
	g_analog_tv_cntx.lcd_height = UI_device_height;
	gdi_layer_resize(g_analog_tv_cntx.lcd_width, g_analog_tv_cntx.lcd_height);

	/************ preview window layer ************/
	/* free layers */
	if(g_analog_tv_cntx.preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
	{
	gdi_layer_free(g_analog_tv_cntx.preview_layer_handle);
		g_analog_tv_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	}
	/*create layer*/
		gdi_layer_create(g_analog_tv_osd_cntx.play_wnd.rect.offset_x,
					g_analog_tv_osd_cntx.play_wnd.rect.offset_y,
					g_analog_tv_osd_cntx.play_wnd.rect.width,
					g_analog_tv_osd_cntx.play_wnd.rect.height,
					&g_analog_tv_cntx.preview_layer_handle);//p_6226_m24_bw_z0162 修改用video的坐标解决错乱闪动问题

	gdi_layer_push_and_set_active(g_analog_tv_cntx.preview_layer_handle);
	gdi_layer_clear(GDI_COLOR_BLACK);
	gdi_layer_pop_and_restore_active();


	/************ osd layer ************/
	/* free osd layer */
	if(g_analog_tv_cntx.osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
	{
	gdi_layer_free(g_analog_tv_cntx.osd_layer_handle);
	g_analog_tv_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	}

	/* free buffer */
	if(g_analog_tv_cntx.osd_layer_buf_ptr != NULL)
	{
	mmi_frm_scrmem_free((void*)g_analog_tv_cntx.osd_layer_buf_ptr);
	g_analog_tv_cntx.osd_layer_buf_ptr = NULL;
	}


	/* create a double layer frame from outside memory */
	g_analog_tv_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc(VDOREC_OSD_BUFFER_SIZE);

	gdi_layer_create_double_using_outside_memory(0,
	                                         0, 
	                                         g_analog_tv_cntx.lcd_width, 
	                                         g_analog_tv_cntx.lcd_height,
	                                         &g_analog_tv_cntx.osd_layer_handle, 
	                                        (PU8) g_analog_tv_cntx.osd_layer_buf_ptr, 
	                                        (S32) VDOREC_OSD_BUFFER_SIZE);        /* this buffer is double buffer size */

	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
	//gdi_layer_set_opacity(TRUE, 255);
	/* clear both layer */
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_toggle_double();
	
	//gdi_layer_set_opacity(TRUE, 255);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();

#if defined(NOKE_DEBUG)
	noke_dbg_printf( "\rmmi_analog_tv_to_normal_screen_screen end \n" );
#endif
}


static void mmi_analog_tv_to_320_240_screen(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	gdi_layer_reset_clip();
	gdi_layer_reset_text_clip();
	
	entry_full_screen();
	/***************************************************************************** 
	* Create layers 
	*****************************************************************************/
	gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
	g_analog_tv_cntx.lcd_width = 320; 
	g_analog_tv_cntx.lcd_height = 240;

	/************ base layer layer ************/
	gdi_layer_get_base_handle(&g_analog_tv_cntx.base_layer_handle);
	//gdi_layer_resize(g_analog_tv_cntx.lcd_width, g_analog_tv_cntx.lcd_height);
	gdi_layer_resize(400, 240);
	gdi_layer_clear(GDI_COLOR_BLACK);

	/************ preview window layer ************/
	/* free layers */
	if(g_analog_tv_cntx.preview_layer_handle != GDI_LAYER_EMPTY_HANDLE)
	{
	gdi_layer_free(g_analog_tv_cntx.preview_layer_handle);
		g_analog_tv_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	}

	/* create at 0,0, then move to correct position after rotate */
	gdi_layer_create(40,
					0,
					g_analog_tv_cntx.lcd_width,
					g_analog_tv_cntx.lcd_height,
					&g_analog_tv_cntx.preview_layer_handle);
	
	gdi_layer_push_and_set_active(g_analog_tv_cntx.preview_layer_handle);
	gdi_layer_resize(320, UI_device_width);  //jonathan
	gdi_layer_clear(GDI_COLOR_BLACK);
	gdi_layer_set_position(40,0);
	gdi_layer_pop_and_restore_active();

	/************ osd layer ************/
	/* free osd layer */
	if(g_analog_tv_cntx.osd_layer_handle != GDI_LAYER_EMPTY_HANDLE)
	{
	gdi_layer_free(g_analog_tv_cntx.osd_layer_handle);
	g_analog_tv_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	}

	/* free buffer */
	if(g_analog_tv_cntx.osd_layer_buf_ptr != NULL)
	{
	mmi_frm_scrmem_free((void*)g_analog_tv_cntx.osd_layer_buf_ptr);
	g_analog_tv_cntx.osd_layer_buf_ptr = NULL;
	}
#if 0
	/* create a double layer frame from outside memory */
	g_analog_tv_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc(VDOREC_OSD_BUFFER_SIZE);
	gdi_layer_create_double_using_outside_memory(0,
	                                         0, 
	                                         400, 
	                                        240,
	                                         &g_analog_tv_cntx.osd_layer_handle, 
	                                        (PU8) g_analog_tv_cntx.osd_layer_buf_ptr, 
	                                        (S32) VDOREC_OSD_BUFFER_SIZE);        /* this buffer is double buffer size */

	gdi_layer_push_and_set_active(g_analog_tv_cntx.osd_layer_handle);
	gdi_layer_set_opacity(TRUE, 0);
	/* clear both layer */
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_resize(400, 240);  //jonathan
	gdi_layer_toggle_double();
	gdi_layer_set_opacity(TRUE, 0);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	gdi_layer_resize(400, 240);  //jonathan
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#ifdef __MMI_ANALOG_TV_FULLSCREEN_SINGNAL_QUALITY_HINT__//bw_20070518 全屏信号差提示
	SignalQualityHintCycle();
	DrawSignalHintOnOsd();
#ifdef __ANALOG_TV_NORMA_TO_FULLSCREEN_ROTATE_90__	
	gdi_layer_set_rotate(GDI_LAYER_ROTATE_180);
#endif
#endif
	gdi_layer_pop_and_restore_active();
   #endif
}	



static void mmi_analog_tv_toggle_fullscreen_display(void)
{
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* flush key event */
	//ClearKeyEvents();
#if defined(__EV_LCD_WQVGA_RESOLUTION_SUPPORT__) 
        mdi_video_rec_preview_stop();
#elif defined(__EV_TV_PATH_BY_VIDEO__)
	mdi_video_rec_preview_stop();
#else 
	#if defined(TV_RECORD_SUPPORT)
	//Huyanwei Add It 
		if( GetAnalogTvAppFlags() == 0 )
		{
			mdi_video_rec_record_stop();
		}
		else
		{
			#ifndef WIN32
			//Huyanwei Add It
			       media_cam_stop(MOD_MMI);
			#endif		
		}
	#else
		#ifndef WIN32
			//Huyanwei Add It
		         media_cam_stop(MOD_MMI);
		#endif
	#endif
#endif
     //  pixtel_UI_cancel_timer(mmi_analog_tv_lcd_split_hdlr);

	//toggle screen 
	gIsAnalogTvFullScreen = (gIsAnalogTvFullScreen == 1)?0:1;

	if(gIsAnalogTvFullScreen)
	{
	        gIsWideScreenDisply=1;
		mmi_analog_tv_to_full_screen_screen();
		mmi_analog_tv_enter_state(ANALOG_TV_STATE_PREVIEW_FULLSCREEN);
	}
	else
	{
		mmi_analog_tv_to_normal_screen_screen();
		mmi_analog_tv_enter_state(ANALOG_TV_STATE_PREVIEW);
	}
}

static void mmi_analog_tv_toggle_320_240_screen_display(void)
{
   mdi_video_rec_preview_stop();
   gIsWideScreenDisply = (gIsWideScreenDisply)?0:1;
   
      if(gIsWideScreenDisply)  //400*240
	{
		mmi_analog_tv_to_full_screen_screen();
		mmi_analog_tv_enter_state(ANALOG_TV_STATE_PREVIEW_FULLSCREEN);
	}
	else     //320*240
	{
		mmi_analog_tv_to_320_240_screen();
		mmi_analog_tv_enter_state(ANALOG_TV_STATE_PREVIEW_320_240_SCREEN);
	}

}
 BOOL mmi_analog_tv_is_full_screen(void)
{
	if(gIsAnalogTvFullScreen)
		return TRUE;
	else
		return FALSE;
}
 
 BOOL mmi_analog_tv_is_320_240_screen(void)
{
	if(gIsWideScreenDisply)
		return FALSE;
	else
		return TRUE;
}
 
#endif //__ANALOG_TV_FEATURE_FULL_SCREEN__

#endif

