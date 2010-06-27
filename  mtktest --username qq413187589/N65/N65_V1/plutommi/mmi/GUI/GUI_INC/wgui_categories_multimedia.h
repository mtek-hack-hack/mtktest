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
 *  wgui_categories_multimedia.h
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MultiMedia related categories.
 *
 *  [Category221]       Empty Screen
 *  [Category222]       View Image Screen
 *  [Category223]       Play Audio Screen
 *  [Category224]       Play Video Full Screen
 *  [Category225]       Play Video Standard Screen (With title & softkey)
 *
 *  [Category331][SUB]  Emptry Sublcd Screen
 *  [Category332][SUB]  Draw a image at center of Sublcd Screen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_CATEGORIES_MULTIMEDIA_H__
#define __WGUI_CATEGORIES_MULTIMEDIA_H__

/***************************************************************************** 
* Define
*****************************************************************************/
#ifdef __MMI_VIDEO_PLAYER__ /* double buffer */
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h"
#include "gdi_include.h"
#define BLACK_BUFFER_SIZE   ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#else
#define BLACK_BUFFER_SIZE   (0)
#endif
#include "Gui_Setting.h"
#include "wgui.h"
#include "wgui_inputs.h"
#define STATUS_ICON_BAR_DOUBLE_BUFFER_SIZE  (((MAIN_LCD_DEVICE_WIDTH*MMI_STATUS_BAR_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2)
#include "TouchScreenGProt.h"

typedef enum _cat226_screen_layout_enum
{
    VERTICAL_NORMAL,
    VERTICAL_FULLSCREEN,
    HORIZONTAL_NORMAL,
    HORIZONTAL_FULLSCREEN
} cat226_screen_layout_enum;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/* Empty screen category - With title bar and softkey */
extern void ShowCategory221Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                gdi_color background_color,
                FuncPtr redraw_content_callback);

/* View image category */
gdi_handle cat222_get_image_handle(void);
extern void ShowCategory222Screen(U16 title,
                                  U16 title_icon,
                                  U16 left_softkey,
                                  U16 left_softkey_icon,
                                  U16 right_softkey,
                                  U16 right_softkey_icon,
                                  gdi_color background_color,
                                  S8 *button_string,
                                  S8 *file_name_ptr, 
                                  BOOL is_short, 
                                  void (*decode_result_callback) (S32),
                                  gdi_image_src_enum src_type);

/* Play audio category */
extern void ShowCategory223Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message_icon,
                U16 flag,
                U32 duration,
                U8 *history_buffer);

/* play fullscreen video */
extern void ShowCategory224Screen(U16 video_id,
                                  PS8 video_filename,
                                  U16 repeat_count,
                                  BOOL is_visaul_update,
                                  BOOL is_play_audio,
                                  BOOL is_lcd_no_sleep,
                                  GDI_COLOR bg_color, void (*play_finish_callback) (S32), void *gui_buffer);

extern void StopCategory224Video(void);

/* play video on standard screen (title & softkey) */
extern void ShowCategory225Screen(U16 title_str,
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
                                  GDI_COLOR bg_color, void (*play_finish_callback) (S32), void *gui_buffer);

/* [Category 226] */
extern void ShowCategory226Screen(U16 left_softkey, U16 left_softkey_icon, U16 right_softkey, U16 right_softkey_icon,
                                  U16 bg_image_id, UI_string_type str_1, UI_string_type str_2,
                                  U16 left_arrow_up, U16 left_arrow_down, FuncPtr event_callback1,
                                  U16 right_arrow_up, U16 right_arrow_down, FuncPtr event_callback2,
                                  U16 icon1_up, U16 icon1_down, FuncPtr event_callback3,
                                  U16 icon2_up, U16 icon2_down, FuncPtr event_callback4,
                                  U16 icon3_up, U16 icon3_down, FuncPtr event_callback5,
                                  U16 icon4_up, U16 icon4_down, FuncPtr event_callback6,
                                  GDI_HANDLE *area1_layer, void (*area1_call_back) (dm_coordinates *coordinate),
                                  GDI_HANDLE *area2_layer, void (*area2_call_back) (dm_coordinates *coordinate),
                                  cat226_screen_layout_enum layout);

extern void ShowCategory227Screen(U8 *title_string,
                                  U16 title_icon,
                                  U16 left_softkey,
                                  U16 left_softkey_icon,
                                  U16 right_softkey,
                                  U16 right_softkey_icon, void (*display_call_back) (dm_coordinates *coordinate),
                                  MMI_BOOL (*pen_all_call_back)(mmi_pen_event_type_enum pen_event,mmi_pen_point_struct point));



#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
extern void Cat226RegisterPenHandlers(U16 ctrl_area_idx, mmi_pen_handler pen_hdlr, mmi_pen_event_type_enum event_type);
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* Empty Sublcd category */
extern void ShowCategory331Screen(void);

/* Draw a image at center Sublcd category */
extern void ShowCategory332Screen(MMI_ID_TYPE image_id);

/* Play audio Sublcd category */
extern void ShowCategory333Screen(void);

#ifdef __MMI_VIDEO_PLAYER__
extern void ResumeCategory224Video(void);
extern void PauseCategory224Video(void);
#endif /* __MMI_VIDEO_PLAYER__ */ 


#ifdef __MMI_SWFLASH__
extern void CatSWFlashPlayEnd(void);
extern void ShowCategory229Screen(
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
            void (*play_finish_callback) (S32 ret),
            void *gui_buffer);
extern void ExitCategorySWFlashScreen(void);
extern void DrawCateSWFlashCategoryControlArea(dm_coordinates *coordinates);
#endif

#ifdef __MMI_AVATAR__
extern void DrawCateAvatarCategoryControlArea(dm_coordinates *coordinate);
extern void ExitCategoryAvatarScreen(void);
#endif

#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
extern void SetSWFlashPlayerLayer(GDI_HANDLE layer_handle);
extern S32 GetCat34MediaType(void);
extern void SetCat34MediaType(S32 media_type);
extern void ShowCategory34Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 bg_media_id,
        S8 *bg_media_filename,
        U8 *history_buffer);
extern void HandleCat34MediaPlayFailed(void);
extern void ExitCategory34Screen(void);
#endif


#ifdef __MMI_CAT44X_SUPPORT__
//----------------------------For Language learning----------------------------------

typedef struct
{   
    S32 x;                          /* -1 for default coordinate */
    S32 y;                          /* -1 for default coordinate */
    S32 width;                      /* -1 for default coordinate */
    S32 height;                     /* -1 for default coordinate */
    U16 keycode;                    /* corresponding key */
    FuncPtr down_event_callback;    /* Button down handler */
    FuncPtr up_event_callback;      /* Button up handler */
    FuncPtr repeat_event_callback;  /* Button repeat handler */
    MMI_ID_TYPE disable_imageid;    /* image if the button is disabled */
    MMI_ID_TYPE off_imageid;        /* image if the button is in normal state */
    MMI_ID_TYPE on_imageid;         /* image if the button gets focused */
    MMI_ID_TYPE down_imageid;       /* image if the button is pressed */
    MMI_BOOL    enabled;            /* Is Panel item enabled.  MMI_TRUE = enabled, MMI_FALSE = disabled */ /* ZN added */
} wgui_panel_element_struct;


typedef struct
{
    PU8  bg_img;                        /* background image of editor */
    U16  header_img_id;                 /* Header image ID */
    PU8  header_img;                    /* Header image of editor */
    S32  header_img_length;             /* length of header image */
    void (*header_img_cb)(void);        /* Header image selected callback */ 
    U8   *buffer;                       /* Buffer the input box should use */
    S32  buffer_size;                   /* Size of the buffer. */ 
    U16  hilite_str_number;             /* Total hilite count */
    HILITE_STR *hilite_str_list;        /* Hilite string list */
    void (*hilite_cb) (S32 idx);        /* Hilite selected callback  */
    color read_line_color;              /* read line color */
    color bg_color;                     /* bg_color */
}wgui_hilite_header_inputbox_struct;    


typedef struct
{
    PU8 area_bg_img;            /* text area background image */
    S32 number_of_lines;        /* total number of lines */
    U8 **string_list;           /* string list to show on text area */
}wgui_text_area_struct;

typedef struct
{
    MMI_ID_TYPE panel_bg_img_id;                /* panel background image buffer */
    wgui_panel_element_struct *element_list;    /* list of panel elements */
    S32 num_of_element;                         /* number of panel elements */
    S32 focused_element;                        /* focused panel element */
    U32 repeat_period;                          /* period of repeat events in milliseconds (0 for default) */
}wgui_panel_area_struct;




/*****************************************************************************
 * FUNCTION
 *  wgui_cat44x_update_inputbox_data
 * DESCRIPTION
 *  Update inputbox data and redraw immediately
 * PARAMETERS
 *  inputbox_area_data      [IN]        Inputbox area data
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat44x_update_inputbox_data(wgui_hilite_header_inputbox_struct *inputbox_area_data);



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
extern void wgui_cat44x_enable_panel_element(S32 elem_idx, MMI_BOOL enabled, MMI_BOOL update_display);


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
 extern S32 wgui_cat44x_get_panel_handle(void);


//-----------------------------------------listening king----------------------------------------------
#if defined(__MMI_MAINLCD_240X320__)
    #define CAT445_CONTROL_AREA_HEIGHT 85
    #define CAT445_EDITOR_GAP_WIDTH    10
#elif defined(__MMI_MAINLCD_320X240__)
    #define CAT445_CONTROL_AREA_HEIGHT 85
    #define CAT445_EDITOR_GAP_WIDTH    15
#elif defined(__MMI_MAINLCD_240X400)
    #define CAT445_CONTROL_AREA_HEIGHT 84
    #define CAT445_EDITOR_GAP_WIDTH    10
#else
    #define CAT445_CONTROL_AREA_HEIGHT 56
    #define CAT445_EDITOR_GAP_WIDTH    10
#endif
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
extern void ShowCategory445Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        U16 bg_img,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        void (*display_call_back) (dm_coordinates *coordinate),
        U8 *history_buffer);


//-----------------------------------------Dictionary king----------------------------------------------
/*****************************************************************************
 * FUNCTION
 *  ShowCategory446Screen
 * DESCRIPTION
 *  category screen of dictionary king search screen
 * PARAMETERS
 *  title                   [IN]        Title id
 *  title_icon              [IN]        Title icon
 *  left_softkey            [IN]        Left soft key label
 *  left_softkey_icon       [IN]        Left soft key icon
 *  right_softkey           [IN]        Right soft key label
 *  right_softkey_icon      [IN]        Right soft key icon
 *  bg_img                  [IN]        panel background image buffer
 *  search_image            [IN]        Seach image
 *  buffer                  [IN]        Buffer
 *  buffer_max_length       [IN]        Buffer size;
 *  number_of_items         [IN]        Number of items
 *  get_item_func           [IN]        Get item callback function
 *  get_hint_func           [IN]        Get hint callback function
 *  highlighted_item        [IN]        Highlighted item index
 *  history_buffer          [IN]        Histpry buffer
 * RETURNS
 *  void
 *****************************************************************************/
/*extern void ShowCategory446Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        PU8 input_bg_img,
        PU8 search_image,
        U8 *buffer,
        S32 buffer_max_length,        
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U8 *history_buffer);*/


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
extern void ShowCategory447Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        U16 bg_id,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        U8 *history_buffer);


//-----------------------------------------Word king----------------------------------------------
#if defined(__MMI_MAINLCD_240X320__)
    #define CAT440_TOP_TEXT_AREA_HEIGHT 43
    #define CAT440_BOTTOM_PANEL_HEIGHT 34
#elif defined(__MMI_MAINLCD_320X240__)
    #define CAT440_TOP_TEXT_AREA_HEIGHT 43
    #define CAT440_BOTTOM_PANEL_HEIGHT 30
#elif defined(__MMI_MAINLCD_240X400__)
    #define CAT440_TOP_TEXT_AREA_HEIGHT 44
    #define CAT440_BOTTOM_PANEL_HEIGHT 35
#else
    #define CAT440_TOP_TEXT_AREA_HEIGHT 36
    #define CAT440_BOTTOM_PANEL_HEIGHT 25
#endif


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
extern void ShowCategory440Screen(
                  U8 *title,
                  PU8 title_icon,
                  U8 *left_softkey,
                  PU8 left_softkey_icon,
                  U8 *right_softkey,
                  PU8 right_softkey_icon,
                  wgui_text_area_struct *top_text_area_data,
                  wgui_hilite_header_inputbox_struct *inputbox_area_data,       
                  wgui_panel_area_struct *panel_area_data,
                  U8 *history_buffer);


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
extern void ShowCategory441Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        wgui_text_area_struct *top_text_area_data,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer);


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
extern void ShowCategory442Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        wgui_text_area_struct *top_text_area_data,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,       
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer);

//-----------------------------------------exam king----------------------------------------------
#if defined(__MMI_MAINLCD_240X320__)
    #define CAT443_PANEL_HEIGHT 30
#elif defined(__MMI_MAINLCD_320X240__)
    #define CAT443_PANEL_HEIGHT 26
#elif defined(__MMI_MAINLCD_240X400__)
    #define CAT443_PANEL_HEIGHT  35
#else
    #define CAT443_PANEL_HEIGHT 24
#endif 
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
extern void ShowCategory443Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        PU8 bg_image,
        void (*display_call_back) (dm_coordinates *coordinate),
        wgui_panel_area_struct *panel_area_data,
        U8 *history_buffer);



//-----------------------------------------E-Book king  2----------------------------------------------
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    #define CAT448_TIME_ID 0
    #define CAT448_INFO_BAR_HEIGHT 22
#elif defined(__MMI_MAINLCD_320X240__)
    #define CAT448_TIME_ID 0
    #define CAT448_INFO_BAR_HEIGHT 22
#else /* defined(__MMI_MAINLCD_240X320__) */
    #define CAT448_TIME_ID 0
    #define CAT448_INFO_BAR_HEIGHT 19
#endif 

#define CAT449_TIME_ID CAT448_TIME_ID
#define CAT449_INFO_BAR_HEIGHT CAT448_INFO_BAR_HEIGHT

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
 *  bg_image                [IN]        Background image buffer
 *  inputbox_area_data      [IN]        Inputbox area data
 *  readline_call_back      [IN]        read line position callback.
 *  pen_get_word_callback   [IN]        pen down cursor change callback
 *  page_change_need_set_highlight[IN]  line or page change need set highlight
 *  page_info_app           [IN]        Page info
 *  is_show_info_bar        [IN]        Is show info bar
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void ShowCategory448Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S8 *bg_image,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,
        void (*readline_call_back) (UI_buffer_type text, S32 cursor_p, S32 text_length),
        void (*pen_get_word_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 buffer_pos, S32 text_length),
        void (*page_change_need_set_highlight) (UI_buffer_type first_display_text, S32 text_length),
        S32 (*get_percentage)(void),
        gui_page_info_app **page_info_app,
        MMI_BOOL is_show_info_bar,
        S8 * info_bar_bg_img,
        U8 *history_buffer);

extern void wgui_cat448_change_highlight(gui_page_info_app **page_info_app);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory449Screen
 * DESCRIPTION
 *  Displays the category449 screen for normal ebook king
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Title Icon
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  bg_image                [IN]        Background image buffer
 *  inputbox_area_data      [IN]        Inputbox area data
 *  readline_call_back      [IN]        read line position callback.
 *  page_info_app           [IN]        Page info
 *  is_get_word_mode        [IN]        Is get word mode
 *  history_buffer          [IN]        history buffer
 * RETURNS
 *  void
 *****************************************************************************/
 extern void ShowCategory449Screen(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        PU8 left_softkey_icon,
        U8 *right_softkey,
        PU8 right_softkey_icon,
        S8 *bg_image,
        wgui_hilite_header_inputbox_struct *inputbox_area_data,
        void (*readline_call_back) (UI_buffer_type text, S32 cursor_p, S32 text_length),
        void (*pen_get_word_callback) (UI_buffer_type text, UI_buffer_type cursor_p, S32 buffer_pos, S32 text_length),
        void (*page_change_need_set_highlight) (UI_buffer_type first_display_text, S32 text_length),
        S32 (*get_percentage)(void),
        gui_page_info_app **page_info_app,
        MMI_BOOL is_show_info_bar,
        S8 * info_bar_bg_img,
        U8 *history_buffer);

#endif /* __MMI_CAT44X_SUPPORT__ */


#endif /* __WGUI_CATEGORIES_MULTIMEDIA_H__ */ 

