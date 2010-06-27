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
 *  mainlcd.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  define LCD and sub-LCD routines.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MAINLCD_C
#define _MAINLCD_C
#include "mmi_features.h"
#include "kal_non_specific_general_types.h"
#include "gui.h"

/* target    : custom/drv/LCD/XXXXLCM/lcd_sw_inc.h */
/* simulator : plutommi/mmi/DrvSim/DrvSimInc/lcd_sw_inc.h */
#include "lcd_sw.h"

/* interface/Include/lcd_if.h */
#include "lcd_if.h"
#include "gdi_include.h"
#include "KeyMap.h"
#include "lcd_sw_rnd.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

#define SIMULATOR_LAYER_COUNT       (4)

#define  BUF_PIXEL_DATA(buff_ptr,x , y, width)  (*(buff_ptr + ((y) * width + (x))))
#define  RGB_TO_HW(R, G, B)                     ((((B) & 0xf8) >> 3) | (((G) & 0xfc) << 3) | (((R) & 0xf8) << 8))
#define  HW_TO_RGB_R(VALUE)                     ((U8)(((VALUE) & 0xf800) >> 8))
#define  HW_TO_RGB_G(VALUE)                     ((U8)(((VALUE) & 0x07e0) >> 3))
#define  HW_TO_RGB_B(VALUE)                     ((U8)(((VALUE) & 0x001f) << 3))

#define  LCD_LAYER0_ENABLE    0x80000000
#define  LCD_LAYER1_ENABLE    0x40000000
#define  LCD_LAYER2_ENABLE    0x20000000
#define  LCD_LAYER3_ENABLE    0x10000000

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* it must be identical to what was defined in MODIS_UI.h */
typedef struct
{
    unsigned int layer_enable;
    unsigned int frame_buffer_address;

    int text_clip_left;
    int text_clip_top;
    int text_clip_right;
    int text_clip_bottom;

    int gfx_clip_left;
    int gfx_clip_top;
    int gfx_clip_right;
    int gfx_clip_bottom;

    int active_layer;

    unsigned short layer_x_offset;
    unsigned short layer_y_offset;
    unsigned short layer_width;
    unsigned short layer_height;

    unsigned short roi_x_offset;
    unsigned short roi_y_offset;
    unsigned short roi_width;
    unsigned short roi_height;

    unsigned char source_key_enable;
    unsigned char opacity_enable;
    unsigned short source_key;
    unsigned char opacity_value;
} MODIS_UI_layer_info_struct;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* Main LCD simulator shadow buffer */
U16 simulator_shadow_buffer[LCD_WIDTH * LCD_HEIGHT];

/* Sub LCD simulator shadow buffer */
#ifdef __MMI_SUBLCD__
U16 simulator_sub_shadow_buffer[SUBLCD_WIDTH * SUBLCD_HEIGHT];
#endif 

/* Main LCD frame buffer for bitmap */
unsigned int simulator_frame_buffer[LCD_WIDTH * LCD_HEIGHT];

#ifdef __MMI_SUBLCD__
/* Sub LCD frame buffer for bitmap */
unsigned int sub_simulator_frame_buffer[SUBLCD_WIDTH * SUBLCD_HEIGHT];
#endif /* __MMI_SUBLCD__ */ 

BITMAPINFO bitmap_info;
BITMAPINFO sub_bitmap_info;

T_W32_SCREEN_DEVICE *device;

U16 SIMULATOR_SKIN_LCD_X;
U16 SIMULATOR_SKIN_LCD_Y;
U16 SIMULATOR_SKIN_SUB_LCD_X;
U16 SIMULATOR_SKIN_SUB_LCD_Y;

#ifdef __MMI_SUBLCD__
const kal_uint8 SubLCDSetArray[] = 
{
    0x01,   /* 0000 0001 */
    0x02,   /* 0000 0010 */
    0x04,   /* 0000 0100 */
    0x08,   /* 0000 1000 */
    0x10,   /* 0001 0000 */
    0x20,   /* 0010 0000 */
    0x40,   /* 0100 0000 */
    0x80    /* 1000 0000 */
};

const kal_uint8 SubLCDReSetArray[] = 
{
    0xFE,   /* 1111 1110 */
    0xFD,   /* 1111 1101 */
    0xFB,   /* 1111 1011 */
    0xF7,   /* 1111 0111 */
    0xEF,   /* 1110 1111 */
    0xDF,   /* 1101 1111 */
    0xBF,   /* 1011 1111 */
    0x7F    /* 0111 1111 */
};
#endif /* __MMI_SUBLCD__ */ 

/* main window */
/* layer_sim_size    layer_sim_main_window; */

/* ROI */
/* layer_sim_offset  layer_sim_ROI_offset; */
/* layer_sim_size    layer_sim_ROI_size; /*
   
   /* layers */
lcd_layer_struct lcd_layer_data[SIMULATOR_LAYER_COUNT];

/* palette look up table */
U16 layer_sim_LUT0[256];
U16 layer_sim_LUT1[256];

BOOL IsLcdFirstInit = TRUE;

HDC hdcMem, hdc;

#ifdef __MMI_SUBLCD__
HDC sub_hdcMem;
HBITMAP sub_hbmp;
#endif /* __MMI_SUBLCD__ */ 
HBITMAP hbmp;

MODIS_UI_layer_info_struct MODIS_UI_layer[SIMULATOR_LAYER_COUNT];
MODIS_UI_layer_info_struct **MODIS_UI_layer_ptr;
MODIS_UI_layer_info_struct *uil_ptr;

unsigned char new_application_flag = 0;
S32 active_layer;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern HWND hWnd;

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern T_W32_SCREEN_DEVICE *GetDeviceData();
extern __declspec(dllimport)
     void set_MODIS_UI_layer_data(MODIS_UI_layer_info_struct **layer,
                                  int lcd_width, int lcd_height, int layer_count, unsigned char *new_app_flag);


/*****************************************************************************
 * FUNCTION
 *  assert_lcd_fb_update
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id              [IN]        U8
 *  start_x             [IN]        U16
 *  start_y             [IN]        U16
 *  end_x               [IN]        U16
 *  end_y               [IN]        U16
 *  roi_offset_x        [IN]        U16
 *  roi_offset_y        [IN]        U16
 *  update_layer        [IN]        U32
 * RETURNS
 *  void
 *****************************************************************************/
     void assert_lcd_fb_update(
            kal_uint8 lcd_id,
            kal_uint16 start_x,
            kal_uint16 start_y,
            kal_uint16 end_x,
            kal_uint16 end_y,
            kal_uint16 roi_offset_x,
            kal_uint16 roi_offset_y,
            kal_uint32 update_layer)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of assert_lcd_fb_update */


/*****************************************************************************
 * FUNCTION
 *  reset_lcd_if
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_lcd_if(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of reset_lcd_if */


/*****************************************************************************
 * FUNCTION
 *  config_lcd_layer_window
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_layer       [IN]        Unsigned char
 *  layer_data      [IN]        Lcd_layer_struct
 * RETURNS
 * TRUE
 *****************************************************************************/
BOOL config_lcd_layer_window(unsigned char lcd_layer, lcd_layer_struct *layer_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lcd_layer_data[lcd_layer] = *layer_data;

    return TRUE;
}   /* end of config_lcd_layer_window */


/*****************************************************************************
 * FUNCTION
 *  lcd_dspl_init
 * DESCRIPTION
 *  screen initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_dspl_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MODIS_UI_layer_ptr =
        (MODIS_UI_layer_info_struct **) malloc(SIMULATOR_LAYER_COUNT * sizeof(MODIS_UI_layer_info_struct*));

    /* initialize pointer allocation for MODIS_UI_layer */
    for (i = 0; i < SIMULATOR_LAYER_COUNT; i++)
    {
        MODIS_UI_layer_ptr[i] = &MODIS_UI_layer[i];
    }

    /* initialize layout data */
    device = GetDeviceData();

    SIMULATOR_SKIN_LCD_X = device->skin_main_lcd_x;
    SIMULATOR_SKIN_LCD_Y = device->skin_main_lcd_y;

#ifdef __MMI_SUBLCD__
    SIMULATOR_SKIN_SUB_LCD_X = device->skin_sub_lcd_x;
    SIMULATOR_SKIN_SUB_LCD_Y = device->skin_sub_lcd_y;
#endif /* __MMI_SUBLCD__ */ 

    /* adjust the diplaying position for LCD if the skin is bigger than real one */
    if (LCD_WIDTH < device->main_lcd_width)
    {
        SIMULATOR_SKIN_LCD_X = SIMULATOR_SKIN_LCD_X + (device->main_lcd_width - LCD_WIDTH) / 2;
        device->skin_main_lcd_x = SIMULATOR_SKIN_LCD_X;
    }
    if (LCD_HEIGHT < device->main_lcd_height)
    {
        SIMULATOR_SKIN_LCD_Y = SIMULATOR_SKIN_LCD_Y + (device->main_lcd_height - LCD_HEIGHT) / 2;
        device->skin_main_lcd_y = SIMULATOR_SKIN_LCD_Y;
    }

#ifdef __MMI_SUBLCD__
    /* adjust the diplaying position for sub-LCD if the skin is bigger than real one */
    if (SUBLCD_WIDTH < device->sub_lcd_width)
    {
        SIMULATOR_SKIN_SUB_LCD_X = SIMULATOR_SKIN_SUB_LCD_X + (device->sub_lcd_width - SUBLCD_WIDTH) / 2;
        device->skin_sub_lcd_x = SIMULATOR_SKIN_SUB_LCD_X;
    }
    if (SUBLCD_HEIGHT < device->sub_lcd_height)
    {
        SIMULATOR_SKIN_SUB_LCD_Y = SIMULATOR_SKIN_SUB_LCD_Y + (device->sub_lcd_height - SUBLCD_HEIGHT) / 2;
        device->skin_sub_lcd_y = SIMULATOR_SKIN_SUB_LCD_Y;
    }
#endif /* __MMI_SUBLCD__ */ 

    /* set up the bitmap infomation */
    bitmap_info.bmiHeader.biSize = sizeof(bitmap_info.bmiHeader);
    bitmap_info.bmiHeader.biWidth = LCD_WIDTH;
    bitmap_info.bmiHeader.biHeight = LCD_HEIGHT;
    bitmap_info.bmiHeader.biPlanes = 1;
    bitmap_info.bmiHeader.biBitCount = 32;
    bitmap_info.bmiHeader.biCompression = BI_RGB;
    bitmap_info.bmiHeader.biSizeImage = LCD_WIDTH * LCD_HEIGHT * 4;
    bitmap_info.bmiHeader.biClrUsed = 0;
    bitmap_info.bmiHeader.biClrImportant = 0;

#ifdef __MMI_SUBLCD__
    /* set up the sub-bitmap infomation */
    sub_bitmap_info.bmiHeader.biSize = sizeof(sub_bitmap_info.bmiHeader);
    sub_bitmap_info.bmiHeader.biWidth = SUBLCD_WIDTH;
    sub_bitmap_info.bmiHeader.biHeight = SUBLCD_HEIGHT;
    sub_bitmap_info.bmiHeader.biPlanes = 1;
    sub_bitmap_info.bmiHeader.biBitCount = 32;
    sub_bitmap_info.bmiHeader.biCompression = BI_RGB;
    sub_bitmap_info.bmiHeader.biSizeImage = SUBLCD_WIDTH * SUBLCD_HEIGHT * 4;
    sub_bitmap_info.bmiHeader.biClrUsed = 0;
    sub_bitmap_info.bmiHeader.biClrImportant = 0;
#endif /* __MMI_SUBLCD__ */ 

    /* draw to simulator's main LCD region */
    hdc = GetDC(hWnd);
    hdcMem = CreateCompatibleDC(hdc);
    hbmp = CreateCompatibleBitmap(hdc, LCD_WIDTH, LCD_HEIGHT);
    SelectObject(hdcMem, hbmp);

#ifdef __MMI_SUBLCD__
    /* draw to simulator's sub LCD region */
    hdc = GetDC(hWnd);
    sub_hdcMem = CreateCompatibleDC(hdc);
    sub_hbmp = CreateCompatibleBitmap(hdc, SUBLCD_WIDTH, SUBLCD_HEIGHT);
    SelectObject(sub_hdcMem, sub_hbmp);
#endif /* __MMI_SUBLCD__ */ 

}   /* end of lcd_dspl_init */


/*****************************************************************************
 * FUNCTION
 *  set_global_window_handle
 * DESCRIPTION
 *  set global the window handle
 * PARAMETERS
 *  hwnd        [IN]        The input window handle
 * RETURNS
 *  void
 *****************************************************************************/
void set_global_window_handle(HWND hwnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hWnd = hwnd;
}   /* end of set_global_window_handle */


/*****************************************************************************
 * FUNCTION
 *  lcd_screen_init
 * DESCRIPTION
 *  screen initialization
 * PARAMETERS
 *  hWnd            [IN]        
 *  hInstance       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_screen_init(HWND hWnd, HINSTANCE hInstance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    device = GetDeviceData();

    device->hwnd = hWnd;
    set_global_window_handle(hWnd);
    lcd_dspl_init();
}   /* end of lcd_screen_init */


/*****************************************************************************
 * FUNCTION
 *  update_screen
 * DESCRIPTION
 *  update the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void update_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hdc = GetDC(hWnd);
    hdcMem = CreateCompatibleDC(hdc);
    hbmp = CreateCompatibleBitmap(hdc, LCD_WIDTH, LCD_HEIGHT);
    SelectObject(hdcMem, hbmp);

    if (simulator_frame_buffer != NULL)
    {
        SetDIBits(NULL, hbmp, 0, LCD_HEIGHT, simulator_frame_buffer, &bitmap_info, DIB_RGB_COLORS);
    }
    BitBlt(
        hdc,
        SIMULATOR_SKIN_LCD_X,
        SIMULATOR_SKIN_LCD_Y,
        SIMULATOR_SKIN_LCD_X + LCD_WIDTH,
        SIMULATOR_SKIN_LCD_Y + LCD_HEIGHT,
        hdcMem,
        0,
        0,
        SRCCOPY);

    ReleaseDC(hWnd, hdc);
    DeleteDC(hdcMem);
    DeleteObject(hbmp);

#ifdef __MMI_SUBLCD__
    hdc = GetDC(hWnd);
    sub_hdcMem = CreateCompatibleDC(hdc);
    sub_hbmp = CreateCompatibleBitmap(hdc, SUBLCD_WIDTH, SUBLCD_HEIGHT);
    SelectObject(sub_hdcMem, sub_hbmp);

    if (sub_simulator_frame_buffer != NULL)
    {
        SetDIBits(NULL, sub_hbmp, 0, SUBLCD_HEIGHT, sub_simulator_frame_buffer, &sub_bitmap_info, DIB_RGB_COLORS);
    }
    BitBlt(
        hdc,
        SIMULATOR_SKIN_SUB_LCD_X,
        SIMULATOR_SKIN_SUB_LCD_Y,
        SIMULATOR_SKIN_SUB_LCD_X + SUBLCD_WIDTH,
        SIMULATOR_SKIN_SUB_LCD_Y + SUBLCD_HEIGHT,
        sub_hdcMem,
        0,
        0,
        SRCCOPY);

    ReleaseDC(hWnd, hdc);
    DeleteDC(sub_hdcMem);
    DeleteObject(sub_hbmp);
#endif /* __MMI_SUBLCD__ */ /* end of __MMI_SUBLCD__ */
}   /* end of update_screen */


/*****************************************************************************
 * FUNCTION
 *  win32_ui_set_layer_data
 * DESCRIPTION
 *  set the flag to indicate that a new application starts
 * PARAMETERS
 *  layer_index             [IN]        Index for the layer
 *  lcd_id                  [IN]        Lcd id
 *  text_clip_left          [IN]        Text clipping region info
 *  text_clip_top           [IN]        Text clipping region info
 *  text_clip_right         [IN]        Text clipping region info
 *  text_clip_bottom        [IN]        Text clipping region info
 *  gfx_clip_left           [IN]        Clipping region info
 *  gfx_clip_top            [IN]        Clipping region info
 *  gfx_clip_right          [IN]        Clipping region info
 *  gfx_clip_bottom         [IN]        Clipping region info
 *  current_handle          [IN]        Current lcd handle
 *  active_handle           [IN]        Active lcd handle
 * RETURNS
 *  void
 *****************************************************************************/
void win32_ui_set_layer_data(
        U8 layer_index,
        U8 lcd_id,
        S32 text_clip_left,
        S32 text_clip_top,
        S32 text_clip_right,
        S32 text_clip_bottom,
        S32 gfx_clip_left,
        S32 gfx_clip_top,
        S32 gfx_clip_right,
        S32 gfx_clip_bottom,
        S32 current_handle,
        S32 active_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (lcd_id == MAIN_LCD)
    {
        /* UIL := UI Layer */
        uil_ptr = MODIS_UI_layer_ptr[layer_index];

        uil_ptr->text_clip_left = text_clip_left;
        uil_ptr->text_clip_top = text_clip_top;
        uil_ptr->text_clip_right = text_clip_right;
        uil_ptr->text_clip_bottom = text_clip_bottom;

        uil_ptr->gfx_clip_left = gfx_clip_left;
        uil_ptr->gfx_clip_top = gfx_clip_top;
        uil_ptr->gfx_clip_right = gfx_clip_right;
        uil_ptr->gfx_clip_bottom = gfx_clip_bottom;

        if (current_handle == active_handle)
        {
            active_layer = layer_index;
        }
    }
}   /* end of win32_ui_set_layer_data */


/*****************************************************************************
 * FUNCTION
 *  lcd_fb_update
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_para        [IN]        Lcd_frame_update_struct
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_fb_update(lcd_frame_update_struct *lcd_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 x, y;
    U16 x_layer, y_layer;
    U16 origin_pixel;
    U16 layer_pixel;
    U16 layer_pixel_index;  /* used for LUT */
    U8 *index_ptr;          /* used for LUT, get index value */
    U16 *buffer_ptr;
    U16 *shadow_ptr;
    BOOL source_enable;
    BOOL opacity_enable;
    BOOL LUT_enable;
    U32 r, g, b;
    U8 op_value;            /* opacity value */
    U8 op_value_c;          /* opacity value complement */
    U32 layer_flag_table[4];
    U8 layer_id;
    U8 skip;
    U32 i, j;
    color c;
    U16 y1, y2, x1, x2;
    S32 roi_width;
    S32 roi_height;

    U8 lcd_id;
    U16 start_x;
    U16 start_y;
    U16 end_x;
    U16 end_y;
    U16 roi_offset_x;
    U16 roi_offset_y;
    DWORD update_layer;
    U8 is_first_layer;

    lcd_layer_struct *layer_ptr;    /* use this ptr to make code shorter */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsLcdFirstInit != FALSE)
    {
        /* lcd_screen_init(hWnd, 0); */

        IsLcdFirstInit = FALSE;
    }

    lcd_id = lcd_para->lcd_id;
    start_x = lcd_para->lcm_start_x;
    start_y = lcd_para->lcm_start_y;
    end_x = lcd_para->lcm_end_x;
    end_y = lcd_para->lcm_end_y;
    roi_offset_x = lcd_para->roi_offset_x;
    roi_offset_y = lcd_para->roi_offset_y;
    update_layer = lcd_para->update_layer;

    if (lcd_id == MAIN_LCD)
    {
        shadow_ptr = (U16*) simulator_shadow_buffer;
    }
#ifdef __MMI_SUBLCD__
    else if (lcd_id == SUB_LCD)
    {
        shadow_ptr = (U16*) simulator_sub_shadow_buffer;
    }
#endif /* __MMI_SUBLCD__ */ 

    /* create this table, so we can use for loop to prcess each layer */
    layer_flag_table[0] = LCD_LAYER0_ENABLE;
    layer_flag_table[1] = LCD_LAYER1_ENABLE;
    layer_flag_table[2] = LCD_LAYER2_ENABLE;
    layer_flag_table[3] = LCD_LAYER3_ENABLE;

    roi_width = end_x - start_x;
    roi_height = end_y - start_y;
    /* copy base layer to shadow buffer directly for faster speed */
    /* lcd_layer_data[0].offset_x */

    /* 
     * buffer_ptr = (U16 *)lcd_layer_data[0].frame_buffer_address;
     * memcpy(shadow_ptr, buffer_ptr, LCD_WIDTH * LCD_HEIGHT * 2);
     */

    is_first_layer = 1;
    for (layer_id = 0; layer_id < SIMULATOR_LAYER_COUNT; layer_id++)
    {
        /* set necessary data for MODIS UI displaying */
        /* UIL := UI Layer */
        if (lcd_id == MAIN_LCD)
        {
            uil_ptr = MODIS_UI_layer_ptr[layer_id];

            uil_ptr->layer_x_offset = lcd_layer_data[layer_id].x_offset;
            uil_ptr->layer_y_offset = lcd_layer_data[layer_id].y_offset;
            uil_ptr->layer_width = lcd_layer_data[layer_id].column_number;
            uil_ptr->layer_height = lcd_layer_data[layer_id].row_number;

            uil_ptr->roi_x_offset = roi_offset_x;
            uil_ptr->roi_y_offset = roi_offset_y;
            uil_ptr->roi_width = roi_width;
            uil_ptr->roi_height = roi_height;

            uil_ptr->source_key_enable = lcd_layer_data[layer_id].source_key_enable;
            uil_ptr->opacity_enable = lcd_layer_data[layer_id].opacity_enable;
            uil_ptr->source_key = lcd_layer_data[layer_id].source_key;
            uil_ptr->opacity_value = lcd_layer_data[layer_id].opacity_value;

            uil_ptr->layer_enable = (update_layer & layer_flag_table[layer_id]);
            uil_ptr->frame_buffer_address = lcd_layer_data[layer_id].frame_buffer_address;

            uil_ptr->active_layer = active_layer;
        }

        /* check if this layer need to merge or not */
        if ((update_layer & layer_flag_table[layer_id]) != 0)
        {

            buffer_ptr = (U16*) lcd_layer_data[layer_id].frame_buffer_address;
            index_ptr = (U8*) lcd_layer_data[layer_id].frame_buffer_address;
            layer_ptr = &lcd_layer_data[layer_id];
            source_enable = layer_ptr->source_key_enable;
            opacity_enable = layer_ptr->opacity_enable;
            LUT_enable = layer_ptr->color_palette_enable;

            /* for each pixel within region */
            for (y = roi_offset_y; y <= roi_offset_y + roi_height; y++)
            {
                for (x = roi_offset_x; x <= roi_offset_x + roi_width; x++)
                {
                    skip = FALSE;
               /***********************************************************/
                    /* test if within region */
                    if ((x >= layer_ptr->x_offset) &&
                        (y >= layer_ptr->y_offset) &&
                        (x <= layer_ptr->x_offset + layer_ptr->column_number - 1) &&
                        (y <= layer_ptr->y_offset + layer_ptr->row_number - 1))
                    {

                        /* transform to layer's local coordinate */
                        x_layer = x - layer_ptr->x_offset;
                        y_layer = y - layer_ptr->y_offset;

                        /* GDI_ASSERT(x - layer_ptr->x_offset>=0); */

                        /* get original's pixel color */
                        if (is_first_layer)
                        {
                        #ifdef GDI_USING_LAYER_BACKGROUND
                            if (lcd_para->roi_background_color == 0)
                            {
                                origin_pixel = 0;
                            }
                            else
                            {
                                origin_pixel = 0xffff;
                            }
                        #else /* GDI_USING_LAYER_BACKGROUND */ 
                            origin_pixel = 0xffff;
                        #endif /* GDI_USING_LAYER_BACKGROUND */ 
                        }
                        else
                        {
                            if (lcd_id == MAIN_LCD)
                            {
                                origin_pixel = BUF_PIXEL_DATA(
                                                shadow_ptr,
                                                x - roi_offset_x + start_x,
                                                y - roi_offset_y + start_y,
                                                LCD_WIDTH);
                            }
                        #ifdef __MMI_SUBLCD__
                            else
                            {
                                origin_pixel = BUF_PIXEL_DATA(
                                                shadow_ptr,
                                                x - roi_offset_x + start_x,
                                                y - roi_offset_y + start_y,
                                                SUBLCD_WIDTH);
                            }
                        #endif /* __MMI_SUBLCD__ */ 
                        }
                        /* get layer's pixel color, check if it use LUT */
                        if (layer_ptr->color_palette_enable == KAL_TRUE)
                        {
                            /* get index, (U8) */
                            layer_pixel_index = BUF_PIXEL_DATA(index_ptr, x_layer, y_layer, layer_ptr->column_number);

                            /* ingore this error currently. just set index = 0 */
                            if ((layer_pixel_index < 0) || (layer_pixel_index > 255))
                            {
                                layer_pixel_index = 0;
                            }

                            /* this might contain error. but ignore. palette must be 0 or 1 */
                            if (layer_ptr->color_palette_select == 0)
                            {
                                layer_pixel = layer_sim_LUT0[layer_pixel_index];
                            }
                            else
                            {
                                layer_pixel = layer_sim_LUT1[layer_pixel_index];
                            }
                        }
                        else
                        {
                            U8 *b1 = GDI_LAYER.act_buf_ptr;
                            S32 b2 = GDI_LAYER.act_pitch;

                            GDI_LAYER.act_buf_ptr = (U8*) layer_ptr->frame_buffer_address;
                            GDI_LAYER.act_pitch = layer_ptr->column_number;

                            if (lcd_id == MAIN_LCD)
                            {
                                DRV_MAINLCD_GET_BUFFER_PIXEL(x_layer, y_layer, layer_pixel);
                            }
                        #ifdef __MMI_SUBLCD__
                            else
                            {
                                DRV_SUBLCD_GET_BUFFER_PIXEL(x_layer, y_layer, layer_pixel);
                            }
                        #endif /* __MMI_SUBLCD__ */ 
                            GDI_LAYER.act_buf_ptr = b1;
                            GDI_LAYER.act_pitch = b2;
                        }

                        /* source key check - tansparency */
                        if (source_enable == KAL_TRUE)
                        {
                            if (layer_ptr->source_key == layer_pixel)
                            {
                                skip = KAL_TRUE;
                            }
                        }

                        /* opacity check */
                        if (skip == FALSE)
                        {
                            if (opacity_enable == KAL_TRUE)
                            {
                                /* calc opacity ratio */
                            #ifdef LCD_MAX_OPACITY
                                op_value = layer_ptr->opacity_value * 255 / LCD_MAX_OPACITY;
                            #else 
                                op_value = layer_ptr->opacity_value << 3;
                            #endif 
                                op_value_c = ~op_value;

                                if (op_value != 0)
                                {
                                    if (lcd_id == MAIN_LCD)
                                    {
                                        r = HW_TO_RGB_R(origin_pixel) * op_value_c +
                                            DRV_HW_TO_RGB_R(layer_pixel) * op_value;
                                        g = HW_TO_RGB_G(origin_pixel) * op_value_c +
                                            DRV_HW_TO_RGB_G(layer_pixel) * op_value;
                                        b = HW_TO_RGB_B(origin_pixel) * op_value_c +
                                            DRV_HW_TO_RGB_B(layer_pixel) * op_value;
                                    }
                                #ifdef __MMI_SUBLCD__
                                    else
                                    {
                                        r = HW_TO_RGB_R(origin_pixel) * op_value_c +
                                            HW_FORMAT_TO_SUBMMI_R(layer_pixel) * op_value;
                                        g = HW_TO_RGB_G(origin_pixel) * op_value_c +
                                            HW_FORMAT_TO_SUBMMI_G(layer_pixel) * op_value;
                                        b = HW_TO_RGB_B(origin_pixel) * op_value_c +
                                            HW_FORMAT_TO_SUBMMI_B(layer_pixel) * op_value;
                                    }
                                #endif /* __MMI_SUBLCD__ */ 
                                    r >>= 8;
                                    g >>= 8;
                                    b >>= 8;
                                    origin_pixel = (U16) RGB_TO_HW(r, g, b);
                                }
                            }
                            else
                            {
                                if (lcd_id == MAIN_LCD)
                                {
                                    r = DRV_HW_TO_RGB_R(layer_pixel);
                                    g = DRV_HW_TO_RGB_G(layer_pixel);
                                    b = DRV_HW_TO_RGB_B(layer_pixel);
                                }
                            #ifdef __MMI_SUBLCD__
                                else
                                {
                                    r = HW_FORMAT_TO_SUBMMI_R(layer_pixel);
                                    g = HW_FORMAT_TO_SUBMMI_G(layer_pixel);
                                    b = HW_FORMAT_TO_SUBMMI_B(layer_pixel);
                                }
                            #endif /* __MMI_SUBLCD__ */ 
                                origin_pixel = (U16) RGB_TO_HW(r, g, b);
                            }
                        }

                        /* write back to shadow buffer */
                        if (lcd_id == MAIN_LCD)
                        {
                            BUF_PIXEL_DATA(shadow_ptr, x - roi_offset_x + start_x, y - roi_offset_y + start_y, LCD_WIDTH) = origin_pixel;       /* 040105 JF modified */
                        }
                    #ifdef __MMI_SUBLCD__
                        else
                        {
                            BUF_PIXEL_DATA(shadow_ptr, x - roi_offset_x + start_x, y - roi_offset_y + start_y, SUBLCD_WIDTH) = origin_pixel;    /* 040105 JF modified */
                        }
                    #endif /* __MMI_SUBLCD__ */ 
                  /***********************************************************/

                    }   /* if within region */
                }       /* for loop  x */
            }           /* for loop - y */
            is_first_layer = 0;
        }               /* if flag */
    }                   /* for each layer */

    /* send the main-lcd information to MODIS_UI for displaying */
    if (lcd_id == MAIN_LCD)
    {
        set_MODIS_UI_layer_data(
            MODIS_UI_layer_ptr,
            LCD_WIDTH,
            LCD_HEIGHT,
            SIMULATOR_LAYER_COUNT,
            &new_application_flag);
    }

    /* draw to dc */
    if (lcd_id == MAIN_LCD)
    {
        /* draw to simulator's main LCD region */
        hdc = GetDC(hWnd);
        hdcMem = CreateCompatibleDC(hdc);
        hbmp = CreateCompatibleBitmap(hdc, LCD_WIDTH, LCD_HEIGHT);
        SelectObject(hdcMem, hbmp);

        y1 = 0;
        y2 = LCD_WIDTH - 1;
        x1 = 0;
        x2 = LCD_HEIGHT - 1;

        for (i = 0; i < LCD_HEIGHT; i++)
        {
            for (j = 0; j < LCD_WIDTH; j++)
            {
                c.r = HW_TO_RGB_R(simulator_shadow_buffer[i * LCD_WIDTH + j]);
                c.g = HW_TO_RGB_G(simulator_shadow_buffer[i * LCD_WIDTH + j]);
                c.b = HW_TO_RGB_B(simulator_shadow_buffer[i * LCD_WIDTH + j]);
                c.alpha = 100;

                /* SetPixel(hdcMem, j, i ,RGB(c.r, c.g, c.b)); */
                BUF_PIXEL_DATA(simulator_frame_buffer, j, LCD_HEIGHT - 1 - i, LCD_WIDTH) = RGB(c.b, c.g, c.r);
            }
        }

        SetDIBits(NULL, hbmp, 0, LCD_HEIGHT, simulator_frame_buffer, &bitmap_info, DIB_RGB_COLORS);
        BitBlt(
            hdc,
            SIMULATOR_SKIN_LCD_X,
            SIMULATOR_SKIN_LCD_Y,
            SIMULATOR_SKIN_LCD_X + LCD_WIDTH,
            SIMULATOR_SKIN_LCD_Y + LCD_HEIGHT,
            hdcMem,
            0,
            0,
            SRCCOPY);

        ReleaseDC(hWnd, hdc);
        DeleteDC(hdcMem);
        DeleteObject(hbmp);
    }
#ifdef __MMI_SUBLCD__
    else if (lcd_id == SUB_LCD)
    {
        /* draw to simulator's sub LCD region */
        hdc = GetDC(hWnd);
        sub_hdcMem = CreateCompatibleDC(hdc);
        sub_hbmp = CreateCompatibleBitmap(hdc, SUBLCD_WIDTH, SUBLCD_HEIGHT);
        SelectObject(sub_hdcMem, sub_hbmp);

        y1 = 0;
        y2 = SUBLCD_WIDTH - 1;
        x1 = 0;
        x2 = SUBLCD_HEIGHT - 1;

        for (i = 0; i < SUBLCD_HEIGHT; i++)
        {
            for (j = 0; j < SUBLCD_WIDTH; j++)
            {
                c.r = HW_TO_RGB_R(simulator_sub_shadow_buffer[i * SUBLCD_WIDTH + j]);
                c.g = HW_TO_RGB_G(simulator_sub_shadow_buffer[i * SUBLCD_WIDTH + j]);
                c.b = HW_TO_RGB_B(simulator_sub_shadow_buffer[i * SUBLCD_WIDTH + j]);
                c.alpha = 100;

                /* SetPixel(sub_hdcMem, j, i ,RGB(c.r, c.g, c.b)); */
                BUF_PIXEL_DATA(sub_simulator_frame_buffer, j, SUBLCD_HEIGHT - 1 - i, SUBLCD_WIDTH) = RGB(c.b, c.g, c.r);
            }
        }

        SetDIBits(NULL, sub_hbmp, 0, SUBLCD_HEIGHT, sub_simulator_frame_buffer, &sub_bitmap_info, DIB_RGB_COLORS);
        BitBlt(
            hdc,
            SIMULATOR_SKIN_SUB_LCD_X,
            SIMULATOR_SKIN_SUB_LCD_Y,
            SIMULATOR_SKIN_SUB_LCD_X + SUBLCD_WIDTH,
            SIMULATOR_SKIN_SUB_LCD_Y + SUBLCD_HEIGHT,
            sub_hdcMem,
            0,
            0,
            SRCCOPY);

        ReleaseDC(hWnd, hdc);
        DeleteDC(sub_hdcMem);
        DeleteObject(sub_hbmp);
    }
#endif /* __MMI_SUBLCD__ */ 
}   /* end of lcd_fb_update */


/*****************************************************************************
 * FUNCTION
 *  config_lcd_roi_window
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  roi_x_offset        [IN]        U16
 *  roi_y_offset        [IN]        Kal_uint16
 *  roi_column          [IN]        Kal_uint16
 *  roi_row             [IN]        Kal_uint16
 * RETURNS
 * TRUE
 *****************************************************************************/
kal_bool config_lcd_roi_window(U16 roi_x_offset, kal_uint16 roi_y_offset, kal_uint16 roi_column, kal_uint16 roi_row)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;

}   /* end of config_lcd_roi_window */


/*****************************************************************************
 * FUNCTION
 *  lcd_init
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id                  [IN]        Kal_uint8
 *  background_color        [IN]        Kal_uint16
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_init(kal_uint8 lcd_id, kal_uint16 background_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_init */


/*****************************************************************************
 * FUNCTION
 *  lcd_sleep_in
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_sleep_in(kal_uint8 lcd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_sleep_in */


/*****************************************************************************
 * FUNCTION
 *  lcd_sleep_out
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_sleep_out(kal_uint8 lcd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_sleep_out */


/*****************************************************************************
 * FUNCTION
 *  lcd_partial_on
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id          [IN]        Kal_uint8
 *  start_line      [IN]        Kal_uint16
 *  end_line        [IN]        Kal_uint16
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_partial_on(kal_uint8 lcd_id, kal_uint16 start_line, kal_uint16 end_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_partial_on */


/*****************************************************************************
 * FUNCTION
 *  lcd_partial_off
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_partial_off(kal_uint8 lcd_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_partial_off */


/*****************************************************************************
 * FUNCTION
 *  lcd_bright_level
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id              [IN]        Kal_uint8
 *  bright_level        [IN]        Kal_uint8
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_bright_level(kal_uint8 lcd_id, kal_uint8 bright_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_bright_level */


/*****************************************************************************
 * FUNCTION
 *  lcd_power_on
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 *  on          [IN]        Kal_bool
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_power_on(kal_uint8 lcd_id, kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_power_on */


/*****************************************************************************
 * FUNCTION
 *  lcd_screen_on
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 *  on          [IN]        Kal_bool
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_screen_on(kal_uint8 lcd_id, kal_bool on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_screen_on */


/*****************************************************************************
 * FUNCTION
 *  lcd_get_parameter
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 *  type        [IN]        Lcd_func_type
 * RETURNS
 *  0
 *****************************************************************************/
kal_uint8 lcd_get_parameter(kal_uint8 lcd_id, lcd_func_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}   /* end of lcd_get_parameter */


/*****************************************************************************
 * FUNCTION
 *  lcd_get_size
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id          [IN]        Kal_uint8
 *  lcd_width       [IN]        Kal_uint16 *
 *  lcd_height      [IN]        Kal_uint16 *
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_get_size(kal_uint8 lcd_id, kal_uint16 *lcd_width, kal_uint16 *lcd_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_get_size */


/*****************************************************************************
 * FUNCTION
 *  lcd_set_bias
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id      [IN]        Kal_uint8
 *  bias        [IN]        Kal_uint8 *
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_set_bias(kal_uint8 lcd_id, kal_uint8 *bias)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_set_bias */


/*****************************************************************************
 * FUNCTION
 *  lcd_set_contrast
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id          [IN]        Kal_uint8
 *  contrast        [IN]        Kal_uint8 *
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_set_contrast(kal_uint8 lcd_id, kal_uint8 *contrast)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_set_contrast */


/*****************************************************************************
 * FUNCTION
 *  lcd_set_linerate
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id          [IN]        Kal_uint8
 *  linereate       [IN]        Kal_uint8 *
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_set_linerate(kal_uint8 lcd_id, kal_uint8 *linereate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_set_linerate */


/*****************************************************************************
 * FUNCTION
 *  lcd_set_temp_compensate
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id          [IN]        Kal_uint8
 *  compensate      [IN]        Kal_uint8 *
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_set_temp_compensate(kal_uint8 lcd_id, kal_uint8 *compensate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_set_temp_compensate */


/*****************************************************************************
 * FUNCTION
 *  lcd_cmd_update
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  lcd_id              [IN]        Kal_uint8
 *  start_x             [IN]        Kal_uint16
 *  start_y             [IN]        Kal_uint16
 *  end_x               [IN]        Kal_uint16
 *  end_y               [IN]        Kal_uint16
 *  roi_offset_x        [IN]        Kal_uint16
 *  roi_offset_y        [IN]        Kal_uint16
 *  update_layer        [IN]        Kal_uint32
 * RETURNS
 *  void
 *****************************************************************************/
void lcd_cmd_update(
        kal_uint8 lcd_id,
        kal_uint16 start_x,
        kal_uint16 start_y,
        kal_uint16 end_x,
        kal_uint16 end_y,
        kal_uint16 roi_offset_x,
        kal_uint16 roi_offset_y,
        kal_uint32 update_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}   /* end of lcd_cmd_update */


/*****************************************************************************
 * FUNCTION
 *  win32_ui_set_new_application_flag
 * DESCRIPTION
 *  set the flag to indicate that a new application starts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void win32_ui_set_new_application_flag()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_application_flag = 1;
}   /* end of win32_ui_set_new_application_flag */


/*****************************************************************************
 * FUNCTION
 *  set_lcd_color_palette
 * DESCRIPTION
 *  
 * PARAMETERS
 *  color_palette_select        [IN]        
 *  color_palette_addr_ptr      [?]         
 *  start_index                 [IN]        
 *  number_of_color             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void set_lcd_color_palette(
        kal_uint8 color_palette_select,
        kal_uint32 *color_palette_addr_ptr,
        kal_uint8 start_index,
        kal_uint8 number_of_color)
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
 *  config_lcd_output
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lcd_output      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void config_lcd_output(kal_bool lcd_output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* _MAINLCD_C */ 

