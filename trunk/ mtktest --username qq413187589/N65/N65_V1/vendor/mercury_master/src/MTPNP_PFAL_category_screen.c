/***********************************************
File name : MTPNP_PFAL_category_screen.c
Contents : MTPNP pfal category screen API
History : Create by : Zhang Nan, May 9, 2007
************************************************/
#include "MMI_features.h"

#ifdef __MMI_DUAL_SIM_MASTER__

/* MTK header file */
#include "stdC.h"
#include "L4Dr1.h"
#include "PixtelDataTypes.h"
#include "GlobalDefs.h"
#include "gui_data_types.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "EventsDef.h"
#include "gui_themes.h"
#include "wgui.h"
#include "CustThemesRes.h"
#include "gdi_include.h"
#include "wgui_inputs.h"
#include "wgui_categories.h"
#include "wgui_softkeys.h"
#include "wgui_status_icons.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_defs.h"
#include "TimerEvents.h"
#include "HistoryGprot.h"       //__MMI_UI_SMALL_SCREEN_SUPPORT__
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "wgui_touch_screen.h"
#include "PhoneSetupGprots.h"
#endif /* __MMI_TOUCH_SCREEN__ || __MMI_HANDWRITING_PAD__ */

#ifdef __MMI_HANDWRITING_PAD__
#include "touch_panel_custom.h"
#endif

#include "wgui_draw_manager.h"
#include "CommonScreens.h"      //101705
#include "QuickAccessMenuItemProt.h"
#include "ScreenRotationGprot.h"
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "ProfileGprots.h"
/* MTK header file */

/* MTPNP header file */
#include "MTPNP_OSAL_common.h"
#include "MTPNP_PFAL_category_screen.h"
/* MTPNP header file */

#include "wgui_categories_idlescreen.h"
#if 0
/* under construction !*/
#endif

/* exern MTK define */
#if (defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__MMI_MAINLCD_240X320__))
extern stFontAttribute idle_screen_network_name_font;
#else
extern stFontAttribute idle_screen_network_name_font;
#endif
extern stFontAttribute idle_screen_network_status_font;
extern MMI_theme *current_MMI_theme;
extern S32 UI_device_width;
extern S32 UI_device_height;

extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;

#ifdef __MMI_SUBLCD__
extern S32 SUB_LCD_device_width;
extern S32 SUB_LCD_device_height;

extern BOOL r2lMMIFlag;
#endif /* __MMI_SUBLCD__ */

static MTPNP_INT32 CatSelRadioCountDownValue;
static MTPNP_AD_FuncPtr CatSelRadioTimerExpireCallBack = UI_dummy_function;

extern MTPNP_UINT16 g_default_sel_item;
extern void ExitListCategoryScreen(void);

extern UI_string_type g_slave_idle_screen_line1text;
extern UI_string_type g_slave_idle_screen_line2text;

static void Cat363CountDownCallBack(void);
static void UpdateCat363ScreenCountDisplay(MTPNP_INT item_index);
static void Cat363HighlightHandler(MTPNP_INT item_index);


static void Cat363CountDownCallBack(void)
{
    MTPNP_UINT8 buf[6];
    UI_font_type saved_font = UI_font;
    color saved_color = UI_text_color;

    if (CatSelRadioCountDownValue == 0)
    {
        gui_cancel_timer(Cat363CountDownCallBack);
        if (CatSelRadioTimerExpireCallBack != NULL)
            CatSelRadioTimerExpireCallBack();
        CatSelRadioTimerExpireCallBack = UI_dummy_function;
    }
    else
    {
        MTPNP_INT str_width, str_height, width, height;

        gui_set_font(&MMI_medium_font);
        gui_set_text_color(UI_COLOR_BLACK);
        gui_itoa(CatSelRadioCountDownValue, (UI_string_type) buf, 10);
        gdi_layer_push_clip();
        gdi_layer_reset_clip();
        gui_measure_string((UI_string_type) buf, &str_width, &str_height);
        width = MMI_pop_up_dialog_width - 5 - str_width;
        height = MMI_pop_up_dialog_height - 10 - str_height;
        gdi_draw_solid_rect(MMI_pop_up_dialog_x + 10,
                            MMI_pop_up_dialog_y + height,
                            MMI_pop_up_dialog_x + MMI_pop_up_dialog_width - 10,
                            MMI_pop_up_dialog_y + height + str_height, GDI_COLOR_TRANSPARENT);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(MMI_pop_up_dialog_x + ((MMI_pop_up_dialog_width + str_width) >> 1),
                                 MMI_pop_up_dialog_y + height);
        }
        else
        {
            gui_move_text_cursor(MMI_pop_up_dialog_x + ((MMI_pop_up_dialog_width - str_width) >> 1),
                                 MMI_pop_up_dialog_y + height);
        }
        gui_print_text((UI_string_type) buf);
        gdi_layer_pop_clip();
        gui_BLT_double_buffer(MMI_pop_up_dialog_x + 10, MMI_pop_up_dialog_y + height,
                              MMI_pop_up_dialog_x + MMI_pop_up_dialog_width - 10,
                              MMI_pop_up_dialog_y + height + str_height);
        gui_set_font(saved_font);
        gui_set_text_color(saved_color);
        CatSelRadioCountDownValue--;
        gui_start_timer(1000, Cat363CountDownCallBack);
    }
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
#endif
void ShowCategory363Screen(
                        MTPNP_UINT16 title,
                        MTPNP_UINT16 title_icon,
                        MTPNP_UINT16 left_softkey,
                        MTPNP_UINT16 left_softkey_icon,
                        MTPNP_UINT16 right_softkey,
                        MTPNP_UINT16 right_softkey_icon,
                        MTPNP_INT32 number_of_items,
                        MTPNP_UINT8 ** list_of_items,
                        MTPNP_UINT16 highlighted_item,
                        MTPNP_UINT32 duration, 
                        MTPNP_AD_FuncPtr callback, 
                        MTPNP_UINT8 * history_buffer)
{
    dm_data_struct dm_data;
    MTPNP_INT32 i;
    MTPNP_UCHAR h_flag;

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    set_small_screen();
#endif
    gdi_layer_lock_frame_buffer();

    create_fixed_twostate_menuitems(get_image(RADIO_ON_IMAGE_ID), get_image(RADIO_OFF_IMAGE_ID));
    associate_fixed_twostate_list();

    ShowListCategoryScreen(get_string(title),
                           get_image(title_icon),
                                   get_string(left_softkey),
                                   get_image(left_softkey_icon),
                                   get_string(right_softkey), get_image(right_softkey_icon), number_of_items);

    resize_fixed_twostate_menuitems(0, MMI_MENUITEM_HEIGHT);
    set_fixed_twostate_positions(MMI_MENUITEM_HEIGHT, 0, 1, 0);

    for (i = 0; i < number_of_items; i++)
    {
        add_fixed_twostate_item((UI_string_type) list_of_items[i]);
    }

    register_fixed_list_highlight_handler(Cat363HighlightHandler);

    h_flag = set_list_menu_category_history(MMI_CATEGORY363_ID, history_buffer);

    if (h_flag)
    {
        fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
    }
    else
    {
        fixed_list_goto_item_no_redraw(highlighted_item);
    }

    select_fixed_twostate_item(MMI_fixed_list_menu.highlighted_item);
    resize_fixed_twostate_menuitems_to_list_width();

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitListCategoryScreen;
    RedrawCategoryFunction = dm_redraw_category_screen;
    GetCategoryHistory = dm_get_category_history;
    GetCategoryHistorySize = dm_get_category_history_size;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY363_ID;
    dm_data.s32flags = DM_NO_STATUS_BAR | DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

    CatSelRadioCountDownValue = duration;
    if (CatSelRadioCountDownValue != 0)
    {
        Cat363CountDownCallBack();
    }

    SetCat363TimerExpireFunc(callback);
}                               /* end of ShowCategorySelRadioScreen */

void SetCat363TimerExpireFunc(MTPNP_AD_FuncPtr f)
{
    CatSelRadioTimerExpireCallBack = f;
}

static void UpdateCat363ScreenCountDisplay(MTPNP_INT item_index)
{
    if (item_index != g_default_sel_item && CatSelRadioCountDownValue > 0)
    {
        CatSelRadioTimerExpireCallBack = UI_dummy_function;
        /*if (popupToneId)
        {
            stopRequestedTone(popupToneId);
            popupToneId = 0;
        }*/
        CatSelRadioCountDownValue = 0;
    }
}

static void Cat363HighlightHandler(MTPNP_INT item_index)
{
    MMI_menu_shortcut_number = item_index + 1;

#ifndef __MMI_RADIO_BUTTON_HIGHLIGHT_NO_SELECT__
    radio_list_handle_item_select_no_draw(item_index);
#endif

    MMI_highlighted_item_text = get_item_text(item_index);
    if (!menu_shortcut_handler_display)
    {
        gui_redraw_menu_shortcut();
    }
    MMI_list_highlight_handler(item_index);
    gui_pop_up_description_stop_scroll();
    wgui_current_pop_up_description_index = item_index;

    UpdateCat363ScreenCountDisplay(item_index);
}

void wgui_cat363_clear_callback(void)
{
    CatSelRadioTimerExpireCallBack = UI_dummy_function;
    CatSelRadioCountDownValue = 0;
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
#ifdef __MMI_MAINLCD_128X128__
/* under construction !*/
#else /* __MMI_MAINLCD_128X128__ */
/* under construction !*/
#endif /* __MMI_MAINLCD_128X128__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


/* idle screen */
void idle_screen_show_card2_network_name(MMI_BOOL is_clock)
{
    if (g_slave_idle_screen_line1text != NULL)
    {
        MTPNP_INT width = 0, height = 0, x = 0, y = 0,x2,y2;
        MTPNP_INT w_inset = MMI_IDLE_STRING_MARGIN_GAP;

	#if defined (E5221)
       	S32 image_width, image_height;
	#endif

        gdi_layer_push_clip();

        gui_set_font(&idle_screen_network_name_font);

	#if !defined(E5221)
        gui_set_text_color(*current_MMI_theme->idle_scr_network_name_color);
        gui_set_text_border_color(*current_MMI_theme->idle_scr_network_name_border_color);
	#else
	 gui_set_text_color(gui_color(0, 0, 0));
	 gui_set_text_border_color(gui_color(255, 255, 255));
	#endif

        width = gui_get_string_width(g_slave_idle_screen_line1text);
        height = gui_get_string_height(g_slave_idle_screen_line1text);
	#if defined(E5221)
        gui_measure_image((PU8) GetImage(IMG_IDLE_SHORCUT_SIM2), &image_width, &image_height);
	#endif

        if (is_clock)
        {
            y = MMI_IDLE_SIM2_NETWORK_NAME_Y_WITH_CLOCK_BG;
        }
        else
        {
		#if defined (E5221)
			w_inset = (r2lMMIFlag)? 78: 88;
			y = 149;
		#else
            		y = MMI_IDLE_SIM2_NETWORK_NAME_Y;
		#endif

        }
	#if defined (E5221)
	 if(r2lMMIFlag)
	 {
		gdi_layer_set_clip(
            		0 , y-1,
            		UI_device_width/2, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
		#ifdef __GDI_MEMORY_PROFILE_2__
        		gdi_draw_solid_rect(
           			0 , y,
            			UI_device_width/2, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            			GDI_COLOR_TRANSPARENT);
		#else
        		draw_wallpaper();
		#endif 
		}
else
{
		gdi_layer_set_clip(
            		w_inset, y-1,
            		w_inset + width+image_width + 2, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
		#ifdef __GDI_MEMORY_PROFILE_2__
        		gdi_draw_solid_rect(
           			w_inset, y,
            			w_inset + width+image_width, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            			GDI_COLOR_TRANSPARENT);
		#else
        		draw_wallpaper();
		#endif 
		}	
	#else

        #if defined(__MMI_VISTA_IDLE__)//for sim2
	 #if defined(__MMI_DOUBLE_BATTERY__)
	         x = (r2lMMIFlag) ? (UI_device_width -120-38 ): (152);      
   		 y= 239;
	#else
            #if defined D220_MUL
                  x = (r2lMMIFlag) ? (UI_device_width -120-38 ): (110);
             #else
	         x = (r2lMMIFlag) ? (UI_device_width -120-38 ): (148);
             #endif
		 y = 248;
        #endif
	#if defined(__MMI_NOKIA_128X160__)
        x = (r2lMMIFlag) ? (UI_device_width - 38) : (idle_text_x); //caolina080814
	        // x =  30;
    		 y = 67;
	x2 = (r2lMMIFlag) ? (UI_device_width - 100) : (120); 
	#else
              x2 = (r2lMMIFlag) ? (0): (240);
	    		 
	#endif

if(r2lMMIFlag)
{
     #if !defined(__MMI_LANG_SM_CHINESE__)&& defined D15C_ZB //caolina080814
	 gdi_layer_set_clip(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
      #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_draw_solid_rect(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            GDI_COLOR_TRANSPARENT);
      #else
        draw_wallpaper();
      #endif /* __GDI_MEMORY_PROFILE_2__ */
#else
		 gdi_layer_set_clip(
	x2,y,
            x, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
#endif

}
else
{
 #if !defined(__MMI_LANG_SM_CHINESE__)&& defined D15C_ZB  //caolina080814
	 gdi_layer_set_clip(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
      #ifdef __GDI_MEMORY_PROFILE_2__
        gdi_draw_solid_rect(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            GDI_COLOR_TRANSPARENT);
      #else
        draw_wallpaper();
      #endif /* __GDI_MEMORY_PROFILE_2__ */
#else
		 gdi_layer_set_clip(
	x,y,
            x2, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
#endif

}
#ifdef __GDI_MEMORY_PROFILE_2__
if(r2lMMIFlag)
{
        gdi_draw_solid_rect(
	x2, y,
            x, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            GDI_COLOR_TRANSPARENT);
}
else
{
        gdi_draw_solid_rect(
	x, y,
            x2, (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            GDI_COLOR_TRANSPARENT);
}
#else
        draw_wallpaper();
#endif 

	#else
        /* clear background */
        gdi_layer_set_clip(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
#ifdef __GDI_MEMORY_PROFILE_2__
        gdi_draw_solid_rect(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            GDI_COLOR_TRANSPARENT);
#else
        draw_wallpaper();
#endif /* __GDI_MEMORY_PROFILE_2__ */
#endif
#endif
        if (width <= (UI_device_width - (w_inset * 2)))
        {
	 	#if defined (E5221)
			x =(r2lMMIFlag) ? 69: 107;
#else
         #if defined(__MMI_VISTA_IDLE__)
            x = (r2lMMIFlag) ? (UI_device_width -120-38) : (148);
	 #if defined(__MMI_DOUBLE_BATTERY__)
            x = (r2lMMIFlag) ? (UI_device_width -120-38) : (152);
              #endif
	#if defined(__MMI_NOKIA_128X160__)
	 x = (r2lMMIFlag) ?((UI_device_width+width)/2) :((UI_device_width-width)/2);//caolina080814
	#endif
       #if defined D220_MUL
	  x = (r2lMMIFlag) ? (UI_device_width -120-38) : (128);    //caolina080827
	 #endif
		 #else
            x = (r2lMMIFlag) ? ((UI_device_width >> 1) + (width >> 1)) : ((UI_device_width >> 1) - (width >> 1));
            x += (r2lMMIFlag) ? (-1) : (1); /* border text */
	    #endif
#endif
            y += 1; /* border text */
#if (defined(__MMI_NOKIA_IDLE__)||defined(__MMI_DOUBLE_BATTERY__) || defined(__MMI_LOGIC_IDLE__)) 
		if (r2lMMIFlag)
		gui_show_image(72 , 149, (PU8) GetImage(IMG_IDLE_SHORCUT_SIM2));
		else
            	gui_show_image(91 , 149, (PU8) GetImage(IMG_IDLE_SHORCUT_SIM2));
#endif
            gui_move_text_cursor(x, y);
            gui_print_bordered_text(g_slave_idle_screen_line1text);
        }
        else
        {
            MTPNP_INT w;
		#if defined (E5221)
            		x =(r2lMMIFlag) ? 69: 107;
            		w = x + width;
		#else
            x = (r2lMMIFlag) ? (UI_device_width - w_inset - 1) : (w_inset + 1);
            x += (r2lMMIFlag) ? (-1) : (1); /* border text */
            y += 1; /* border text */
            w = UI_device_width - (w_inset * 2) - 2/* border text */;
		#endif
#if (defined(__MMI_NOKIA_IDLE__)||defined(__MMI_DOUBLE_BATTERY__) || defined(__MMI_LOGIC_IDLE__)) 
		if (r2lMMIFlag)
			gui_show_image(72 , 149, (PU8) GetImage(IMG_IDLE_SHORCUT_SIM2));
		else
            	gui_show_image(91 , 149, (PU8) GetImage(IMG_IDLE_SHORCUT_SIM2));
#endif
            gui_print_truncated_borderd_text(x, y, w, g_slave_idle_screen_line1text);
        }
        gdi_layer_pop_clip();
    }
}

void idle_screen_show_card2_network_status(void)
{
    MTPNP_INT width = 0, height = 0, x = 0, y = 0;

    /* show slave network status */
    if (g_slave_idle_screen_line2text != NULL)
    {
        MTPNP_INT w_inset = MMI_IDLE_STRING_MARGIN_GAP;
	#if defined(__MMI_NOKIA_IDLE__)
	w_inset = 130;	
       #endif
	

        gdi_layer_push_clip();
	
        gui_set_font(&idle_screen_network_status_font);
        gui_set_text_color(*current_MMI_theme->idle_scr_network_status_color);
        gui_set_text_border_color(*current_MMI_theme->idle_scr_network_status_border_color);

        width = gui_get_string_width(g_slave_idle_screen_line2text);
        height = gui_get_string_height(g_slave_idle_screen_line2text);

        y = MMI_IDLE_SIM2_NETWORK_STATUS_Y;
#if defined(D15_ZB_UI)
        if( y<75 )
        
           y =y+20;
        else
           y=95;

#endif
	#if defined(__MMI_NOKIA_IDLE__)
	y = 242;	
        #endif

        /* clear background */
        gdi_layer_set_clip(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)));
#ifdef __GDI_MEMORY_PROFILE_2__
        gdi_draw_solid_rect(
            w_inset, y,
            (UI_device_width - w_inset), (y + Get_CharDisplayHeightOfAllLangAndType(idle_screen_network_name_font.size)),
            GDI_COLOR_TRANSPARENT);
#else
        draw_wallpaper();
#endif /* __GDI_MEMORY_PROFILE_2__ */

        if (width <= (UI_device_width - (w_inset * 2)))
        {
            x = (r2lMMIFlag) ? ((UI_device_width >> 1) + (width >> 1)) : ((UI_device_width >> 1) - (width >> 1));
            x += (r2lMMIFlag) ? (-1) : (1); /* border text */
            y += 1; /* border text */
            gui_move_text_cursor(x, y);
            gui_print_bordered_text(g_slave_idle_screen_line2text);
        }
        else
        {
            MTPNP_INT w;

            x = (r2lMMIFlag) ? (UI_device_width - w_inset - 1) : (w_inset + 1);
            x += (r2lMMIFlag) ? (-1) : (1); /* border text */
            y += 1; /* border text */
            w = UI_device_width - (w_inset * 2) - 2/* border text */;
            gui_print_truncated_borderd_text(x, y, w, g_slave_idle_screen_line2text);
        }
        gdi_layer_pop_clip();
    }
}

/* idle screen */

void mmi_mtpnp_entry_menu( U16 scr_id, FuncPtr exit_func, FuncPtr entry_func, U16 menu_id, U16 str_id, U16 img_id)
{
    U8 *guiBuffer;
    U16 nStrItemList[MAX_SUB_MENUS];
    U16 nImgIltemList[MAX_SUB_MENUS];
    U16 nNumofItem;
    U8 *hintList[MAX_SUB_MENUS];

    EntryNewScreen(scr_id, exit_func, entry_func, NULL);
    guiBuffer = GetCurrGuiBuffer(scr_id);

    nNumofItem = GetNumOfChild_Ext(menu_id);
    GetSequenceStringIds_Ext(menu_id, nStrItemList);
    GetSequenceImageIds_Ext(menu_id, nImgIltemList);
    ConstructHintsList(menu_id, hintList);
    SetParentHandler(menu_id);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(str_id, img_id,
                         STR_GLOBAL_OK, IMG_GLOBAL_OK,
                         STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                         nNumofItem, nStrItemList, (U16 *)gIndexIconsImageList, hintList, 0, 0, guiBuffer); /* maybe use nImgIltemList */

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* __MMI_DUAL_SIM_MASTER__ */
