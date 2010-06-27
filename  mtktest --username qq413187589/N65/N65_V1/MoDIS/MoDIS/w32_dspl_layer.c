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
 *   w32_dslp_layer.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Display functions
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdafx.h"
#include "string.h"
#include "resource.h"
#include <stdio.h>
//#include "w32_dib.h"
//#undef BOOL

#include "kal_non_specific_general_types.h"
#include "w32_dspl.h"
#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stacklib.h"
#include "stack_timer.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "device.h"
#include "mmi_features.h"
#include "pixteldatatypes.h"
#include "lcd_if.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"
#include "lcd_sw.h"
#include "gdi_include.h"
#include "kbd_table.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define	U8		unsigned char
#define	U16	unsigned short
#define	U32	unsigned int
#define	S32	int

#define	NormalDisplay								(0)
#define	PartialDisplay								(1)

#define	BUF_PIXEL_DATA(buff_ptr,x,y, width)	(*(buff_ptr + ((y) * (width) + (x))))
#define  RGB_TO_HW(R,G,B)							((((B) & 0xf8) >> 3) | (((G) & 0xfc) << 3) | (((R) & 0xf8) << 8))
#define  HW_TO_RGB_R(VALUE)						((unsigned char)(((VALUE) & 0xf800) >> 8))
#define  HW_TO_RGB_G(VALUE)						((unsigned char)(((VALUE) & 0x07e0) >> 3))
#define  HW_TO_RGB_B(VALUE)						((unsigned char)(((VALUE) & 0x001f) << 3))

#define SIMULATOR_LAYER_COUNT	(4)

#define VIBRATE_PIXEL			(7)
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct 
{	
	unsigned char r;
	unsigned char g;
	unsigned char b;
} color;


/* it must be identical to what was defined in MODIS_UI.h */
typedef struct {
	unsigned int	layer_enable;
	unsigned int	frame_buffer_address;

	int				text_clip_left;
	int				text_clip_top;
	int				text_clip_right;
	int				text_clip_bottom;

	int				gfx_clip_left;
	int				gfx_clip_top;
	int				gfx_clip_right;
	int				gfx_clip_bottom;

	int				active_layer;

	unsigned short	layer_x_offset;
	unsigned short	layer_y_offset;
	unsigned short	layer_width;
	unsigned short	layer_height;

	unsigned short	roi_x_offset;
	unsigned short	roi_y_offset;
	unsigned short	roi_width;
	unsigned short	roi_height;

	unsigned char	source_key_enable;
	unsigned char	opacity_enable;
	unsigned short	source_key;
	unsigned char	opacity_value;
} MODIS_UI_layer_info_struct;


/***************************************************************************** 
* Local Variable
*****************************************************************************/
HDC									lcd_hdcMem;	
HBITMAP								lcd_hbmp;

HDC									sub_lcd_hdcMem;	
HBITMAP								sub_lcd_hbmp;

BITMAPINFO							bitmap_info;
BITMAPINFO							sub_bitmap_info;

unsigned char						Update_Status;
unsigned char						new_application_flag = 0;

int		mainlcd_backlight_level = 9;

int g_LCD_OFFSET_Y;
int g_LCD_OFFSET_X;
int g_LCD_WIDTH;
int g_LCD_HEIGHT;

int g_SUBLCD_OFFSET_Y;
int g_SUBLCD_OFFSET_X;
int g_SUBLCD_WIDTH;
int g_SUBLCD_HEIGHT;



COLORREF								show_display[LCD_HEIGHT][LCD_WIDTH];

int									SIMULATOR_SKIN_LCD_X;
int									SIMULATOR_SKIN_LCD_Y;
int									SIMULATOR_SKIN_SUB_LCD_X;
int									SIMULATOR_SKIN_SUB_LCD_Y;
int									skin_lcd_width;
int									skin_lcd_height;
int									skin_sublcd_width;
int									skin_sublcd_height;

static int							key_release;

/* Main LCD simulator shadow buffer */
unsigned short						simulator_shadow_buffer[LCD_WIDTH * LCD_HEIGHT];
/* Main LCD frame buffer for bitmap */
unsigned int						simulator_frame_buffer[LCD_WIDTH * LCD_HEIGHT];

/* Sub LCD simulator shadow buffer */
#ifdef DUAL_LCD
unsigned short						simulator_sub_shadow_buffer[SUBLCD_WIDTH*SUBLCD_HEIGHT];
/* Sub LCD frame buffer for bitmap */
unsigned int						simulator_sub_frame_buffer[SUBLCD_WIDTH * SUBLCD_HEIGHT];
#endif

/* layers */
lcd_layer_struct	lcd_layer_data[GDI_LCD_SUM][SIMULATOR_LAYER_COUNT];

/* palette look up table */
unsigned short						layer_sim_LUT0[256];
unsigned short						layer_sim_LUT1[256];

int									keypad_offset_x;
int									keypad_offset_y;

int									lcd_offset_x;
int									lcd_offset_y;
int									sub_lcd_offset_x;
int									sub_lcd_offset_y;

BOOL									lcd_updating;
//BOOL							Vibrate_Timer=FALSE;
int								ViBrate_Num = 0;
T_W32_SCREEN_DEVICE				device;
volatile kal_uint8				current_update_lcd = MAIN_LCD;
kal_eventgrpid						lcd_event_id = NULL;
lcd_frame_update_struct			main_lcd_fb_update_para;
volatile LCD_OPERATION_STATE_ENUM		main_lcd_operation_state = LCD_IDLE_STATE;
#ifdef DUAL_LCD
	volatile LCD_OPERATION_STATE_ENUM	sub_lcd_operation_state = LCD_IDLE_STATE;
	lcd_frame_update_struct		sub_lcd_fb_update_para;
#endif

S32									active_layer;

MODIS_UI_layer_info_struct		MODIS_UI_layer[SIMULATOR_LAYER_COUNT];
MODIS_UI_layer_info_struct		**MODIS_UI_layer_ptr = NULL;
MODIS_UI_layer_info_struct		*uil_ptr;

unsigned short						gShadowBuffer[LCD_HEIGHT][LCD_WIDTH];

// create this table, so we can use for loop to prcess each layer
static DWORD						layer_flag_table[] = {
											LCD_LAYER0_ENABLE,
											LCD_LAYER1_ENABLE,
											LCD_LAYER2_ENABLE,
											LCD_LAYER3_ENABLE};

lcd_frame_update_struct			last_lcd_para[2];



LCD_Funcs MainLCD_temp;
LCD_Funcs SubLCD_temp;
LCD_Funcs *MainLCD = &MainLCD_temp;
LCD_Funcs *SubLCD	= &SubLCD_temp;
BYTE *pResizeData;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/*COLOR_LCD*/
void	LCD_Init_MODIS(kal_uint32 bkground, void **buf_addr);
void	LCDrBlockWrite(unsigned short x1, unsigned short y1, unsigned short x2, unsigned short y2);

void	w32_dspl_init_custom(int sizeX, int sizeY);
extern __declspec(dllimport)
void MoDISCallTimer(BOOL flag);

extern __declspec(dllimport)
void EnlargeDataInt(BYTE *pInBuff,
                    int wWidth,
                    int wHeight,
                    BYTE *pOutBuff,
                    int wNewWidth,
                    int wNewHeight);
extern __declspec(dllimport)
void ShrinkDataInt(BYTE *pInBuff,
                    int wWidth,
                    int wHeight,
                    BYTE *pOutBuff,
                    int wNewWidth,
                    int wNewHeight);			
/***************************************************************************** 
* Global Variable
*****************************************************************************/


/***************************************************************************** 
* Global Function
*****************************************************************************/
extern __declspec(dllimport)
void	MoDisUISetLayerData(
	MODIS_UI_layer_info_struct	**layer,
	int								lcd_width,
	int								lcd_height,
	int								layer_count,
	unsigned char					*new_app_flag
);



/*****************************************************************************
* FUNCTION
*  config_lcd_roi_window
* DESCRIPTION
*  config lcd roi window
*
* PARAMETERS
*  roi_x_offset	IN			lcd layer
*  roi_y_offset	IN			lcd data
*  roi_column		IN			roi column
*  roi_row			IN			roi row
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
kal_bool config_lcd_roi_window(kal_uint16 roi_offset_x, kal_uint16 roi_offset_y, kal_uint16 roi_column,
			   						 kal_uint16 roi_row)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

	return KAL_TRUE;
} /* end of config_lcd_roi_window */


/*****************************************************************************
* FUNCTION
*  lcd_init
* DESCRIPTION
*  lcd initialization
*
* PARAMETERS
*  lcd_id				IN			lcd id
*  background_color	IN			background color
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
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
#endif


/*****************************************************************************
* FUNCTION
*  LCD_SetVoltLevel
* DESCRIPTION
*  set lvd volt level
*
* PARAMETERS
*  voltage				IN			voltage
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void LCD_SetVoltLevel(kal_uint8 voltage)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of LCD_SetVoltLevel */


/*****************************************************************************
* FUNCTION
*  w32_mapping
* DESCRIPTION
*  mapping values
*
* PARAMETERS
*  value			IN			value
* RETURNS
*  mapping value
* GLOBALS AFFECTED
*  void
*****************************************************************************/
unsigned char w32_mapping(unsigned char value)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	switch(value)
	{
	case 0x0f:
		return 0xff;
	case 0x00:
		return 0x00;
	default:
		return (value << 4);
	}
} /* end of w32_mapping */


/*****************************************************************************
* FUNCTION
*  w32_draw_point
* DESCRIPTION
*  draw a point
*
* PARAMETERS
*  x			IN			X position
*  y			IN			Y position
*  color		IN			color of the point
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_draw_point(int x, int y, unsigned short color)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	COLORREF temp;
	

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	temp = DRV_HW_TO_RGB_R(color) << 16 | DRV_HW_TO_RGB_G(color) << 8 | DRV_HW_TO_RGB_B(color);

	show_display[LCD_HEIGHT - y - 1][x] = temp;
} /* end of w32_draw_point */


/*****************************************************************************
* FUNCTION
*  w32_get_device_info
* DESCRIPTION
*  get the information of the display device
*
* PARAMETERS
*	void
* RETURNS
*	the pointer of the information structure of the device
* GLOBALS AFFECTED
*	void
*****************************************************************************/
void* w32_get_device_info(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	return &device;
} /* end of w32_get_device_info */

void w32_dspl_init_custom(int sizeX, int sizeY)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	i;
	HDC	hdc;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (MODIS_UI_layer_ptr == NULL)
	{
		MODIS_UI_layer_ptr = (MODIS_UI_layer_info_struct **)malloc(SIMULATOR_LAYER_COUNT * sizeof(MODIS_UI_layer_info_struct *));

		/* initialize pointer allocation for MODIS_UI_layer */
		for (i = 0; i < SIMULATOR_LAYER_COUNT; i++)
		{
			MODIS_UI_layer_ptr[i] = &MODIS_UI_layer[i];
		}
	}

	/* ATTENTION!!!
	 *
	 * w32_ReadKeyProfile() MUST be called before this function be called!
	 *
	 */

	/* initialize the information about dimension */


	skin_lcd_height = sizeX;
	skin_lcd_width = sizeY;
#ifdef DUAL_LCD
	skin_sublcd_height	= device.sub_lcd_height;
	skin_sublcd_width		= device.sub_lcd_width;
#endif
	lcd_offset_x = device.skin_main_lcd_x;

	lcd_offset_y = device.skin_main_lcd_y;
	/*
	if (skin_lcd_width > LCD_WIDTH)
	{
		lcd_offset_x = device.skin_main_lcd_x + (skin_lcd_width - LCD_WIDTH) / 2;
		device.skin_main_lcd_x = lcd_offset_x;
	}
	else
	{
		lcd_offset_x = device.skin_main_lcd_x;
	}

	if (skin_lcd_height > LCD_HEIGHT)
	{
		lcd_offset_y = device.skin_main_lcd_y + (skin_lcd_height - LCD_HEIGHT) / 2;
		device.skin_main_lcd_y = lcd_offset_y;
	}
	else
	{
		lcd_offset_y = device.skin_main_lcd_y;
	}
	*/

#ifdef DUAL_LCD
	/*
	if (skin_sublcd_width > SUBLCD_WIDTH)
	{
		sub_lcd_offset_x = device.skin_sub_lcd_x + (skin_sublcd_width - SUBLCD_WIDTH) / 2;
		device.skin_sub_lcd_x = sub_lcd_offset_x;
	}
	else
	{
		sub_lcd_offset_x = device.skin_sub_lcd_x;
	}
	if (skin_sublcd_height > SUBLCD_HEIGHT)
	{
		sub_lcd_offset_y = device.skin_sub_lcd_y + (skin_sublcd_height - SUBLCD_HEIGHT) / 2;
		device.skin_sub_lcd_y = sub_lcd_offset_y;
	}
	else
	{
		sub_lcd_offset_y = device.skin_sub_lcd_y;
	}*/
#endif
	
	/* draw to simulator's main LCD region */
	hdc			= GetDC(device.hwnd);
	lcd_hdcMem	= CreateCompatibleDC(hdc);
	//lcd_hbmp		= CreateCompatibleBitmap(hdc, LCD_WIDTH, LCD_HEIGHT);
 	//update by wayne
	lcd_hbmp		= CreateCompatibleBitmap(hdc, skin_lcd_width, skin_lcd_height);
	SelectObject(lcd_hdcMem, lcd_hbmp);

	/* set up the bitmap infomation */
	
	bitmap_info.bmiHeader.biSize				= sizeof(bitmap_info.bmiHeader);
	//bitmap_info.bmiHeader.biWidth				= LCD_WIDTH;
	//bitmap_info.bmiHeader.biHeight			= LCD_HEIGHT;
	bitmap_info.bmiHeader.biWidth				= skin_lcd_width;
	bitmap_info.bmiHeader.biHeight			= skin_lcd_height;
	
	bitmap_info.bmiHeader.biPlanes			= 1;
	bitmap_info.bmiHeader.biBitCount			= 32;
	bitmap_info.bmiHeader.biCompression		= BI_RGB;
	
	//bitmap_info.bmiHeader.biSizeImage		= LCD_WIDTH * LCD_HEIGHT * 4;
	bitmap_info.bmiHeader.biSizeImage		= skin_lcd_width * skin_lcd_height * 4;
	
	bitmap_info.bmiHeader.biClrUsed			= 0;
	bitmap_info.bmiHeader.biClrImportant	= 0;
	
	sub_bitmap_info.bmiHeader.biSize				= sizeof(bitmap_info.bmiHeader);
#ifdef DUAL_LCD
	sub_bitmap_info.bmiHeader.biWidth			= skin_sublcd_width;//SUBLCD_WIDTH;
	sub_bitmap_info.bmiHeader.biHeight			= skin_sublcd_height;//SUBLCD_HEIGHT;
#endif
	sub_bitmap_info.bmiHeader.biPlanes			= 1;
	sub_bitmap_info.bmiHeader.biBitCount		= 32;
	sub_bitmap_info.bmiHeader.biCompression	= BI_RGB;
#ifdef DUAL_LCD
	sub_bitmap_info.bmiHeader.biSizeImage		= skin_sublcd_width*skin_sublcd_height*4;//SUBLCD_WIDTH * SUBLCD_HEIGHT * 4;
#endif
	sub_bitmap_info.bmiHeader.biClrUsed			= 0;
	sub_bitmap_info.bmiHeader.biClrImportant	= 0;

#ifdef DUAL_LCD
	sub_lcd_hdcMem	= CreateCompatibleDC(hdc);
	//sub_lcd_hbmp	= CreateCompatibleBitmap(hdc, SUBLCD_WIDTH, SUBLCD_HEIGHT);
	sub_lcd_hbmp	= CreateCompatibleBitmap(hdc, skin_sublcd_width, skin_sublcd_height);
	SelectObject(sub_lcd_hdcMem, sub_lcd_hbmp);
#endif
	ReleaseDC(device.hwnd, hdc);
} /* end of w32_dspl_init */



/*****************************************************************************
* FUNCTION
*  w32_dspl_init
* DESCRIPTION
*  initialize the display
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_dspl_init(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	i;
	HDC	hdc;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (MODIS_UI_layer_ptr == NULL)
	{
		MODIS_UI_layer_ptr = (MODIS_UI_layer_info_struct **)malloc(SIMULATOR_LAYER_COUNT * sizeof(MODIS_UI_layer_info_struct *));

		/* initialize pointer allocation for MODIS_UI_layer */
		for (i = 0; i < SIMULATOR_LAYER_COUNT; i++)
		{
			MODIS_UI_layer_ptr[i] = &MODIS_UI_layer[i];
		}
	}

	/* ATTENTION!!!
	 *
	 * w32_ReadKeyProfile() MUST be called before this function be called!
	 *
	 */

	/* initialize the information about dimension */
	skin_lcd_height		= device.main_lcd_height;
	skin_lcd_width			= device.main_lcd_width;
//#ifdef DUAL_LCD
	skin_sublcd_height	= device.sub_lcd_height;
	skin_sublcd_width		= device.sub_lcd_width;
//#endif
	lcd_offset_x = device.skin_main_lcd_x;

	lcd_offset_y = device.skin_main_lcd_y;
	/*
	if (skin_lcd_width > LCD_WIDTH)
	{
		lcd_offset_x = device.skin_main_lcd_x + (skin_lcd_width - LCD_WIDTH) / 2;
		device.skin_main_lcd_x = lcd_offset_x;
	}
	else
	{
		lcd_offset_x = device.skin_main_lcd_x;
	}

	if (skin_lcd_height > LCD_HEIGHT)
	{
		lcd_offset_y = device.skin_main_lcd_y + (skin_lcd_height - LCD_HEIGHT) / 2;
		device.skin_main_lcd_y = lcd_offset_y;
	}
	else
	{
		lcd_offset_y = device.skin_main_lcd_y;
	}*/
	

#ifdef DUAL_LCD
	sub_lcd_offset_x = device.skin_sub_lcd_x;
	sub_lcd_offset_y = device.skin_sub_lcd_y;
	/*
	if (skin_sublcd_width > SUBLCD_WIDTH)
	{
		sub_lcd_offset_x = device.skin_sub_lcd_x + (skin_sublcd_width - SUBLCD_WIDTH) / 2;
		device.skin_sub_lcd_x = sub_lcd_offset_x;
	}
	else
	{
		sub_lcd_offset_x = device.skin_sub_lcd_x;
	}
	if (skin_sublcd_height > SUBLCD_HEIGHT)
	{
		sub_lcd_offset_y = device.skin_sub_lcd_y + (skin_sublcd_height - SUBLCD_HEIGHT) / 2;
		device.skin_sub_lcd_y = sub_lcd_offset_y;
	}
	else
	{
		sub_lcd_offset_y = device.skin_sub_lcd_y;
	}*/
#endif
	
	/* draw to simulator's main LCD region */
	hdc			= GetDC(device.hwnd);
	if(lcd_hdcMem) 	
		DeleteDC(lcd_hdcMem); //wayne 0823
	if(lcd_hbmp) 
		DeleteObject(lcd_hbmp); //wayne 0823
	lcd_hdcMem	= CreateCompatibleDC(hdc);
	//lcd_hbmp		= CreateCompatibleBitmap(hdc, LCD_WIDTH, LCD_HEIGHT);
	lcd_hbmp		= CreateCompatibleBitmap(hdc, skin_lcd_width, skin_lcd_height);
 	SelectObject(lcd_hdcMem, lcd_hbmp);

	/* set up the bitmap infomation */
	bitmap_info.bmiHeader.biSize				= sizeof(bitmap_info.bmiHeader);
	//bitmap_info.bmiHeader.biWidth				= LCD_WIDTH;
	//bitmap_info.bmiHeader.biHeight			= LCD_HEIGHT;
	bitmap_info.bmiHeader.biWidth				= skin_lcd_width;
	bitmap_info.bmiHeader.biHeight			= skin_lcd_height;
	bitmap_info.bmiHeader.biPlanes			= 1;
	bitmap_info.bmiHeader.biBitCount			= 32;
	bitmap_info.bmiHeader.biCompression		= BI_RGB;
	//bitmap_info.bmiHeader.biSizeImage		= LCD_WIDTH * LCD_HEIGHT * 4;
	bitmap_info.bmiHeader.biSizeImage		= skin_lcd_width * skin_lcd_height * 4;
	bitmap_info.bmiHeader.biClrUsed			= 0;
	bitmap_info.bmiHeader.biClrImportant	= 0;

	sub_bitmap_info.bmiHeader.biSize				= sizeof(bitmap_info.bmiHeader);
#ifdef DUAL_LCD
	sub_bitmap_info.bmiHeader.biWidth			= skin_sublcd_width;//SUBLCD_WIDTH;
	sub_bitmap_info.bmiHeader.biHeight			= skin_sublcd_height;//SUBLCD_HEIGHT;
#endif
	sub_bitmap_info.bmiHeader.biPlanes			= 1;
	sub_bitmap_info.bmiHeader.biBitCount		= 32;
	sub_bitmap_info.bmiHeader.biCompression	= BI_RGB;
#ifdef DUAL_LCD
	sub_bitmap_info.bmiHeader.biSizeImage		= skin_sublcd_width*skin_sublcd_height*4;//SUBLCD_WIDTH * SUBLCD_HEIGHT * 4;
#endif
	sub_bitmap_info.bmiHeader.biClrUsed			= 0;
	sub_bitmap_info.bmiHeader.biClrImportant	= 0;

#ifdef DUAL_LCD
	if(sub_lcd_hdcMem) DeleteDC(sub_lcd_hdcMem); //wayne 0823
	if(sub_lcd_hbmp) DeleteObject(sub_lcd_hbmp); //wayne 0823
	sub_lcd_hdcMem	= CreateCompatibleDC(hdc);
	//sub_lcd_hbmp	= CreateCompatibleBitmap(hdc, SUBLCD_WIDTH, SUBLCD_HEIGHT);
	sub_lcd_hbmp	= CreateCompatibleBitmap(hdc, skin_sublcd_width, skin_sublcd_height);
	SelectObject(sub_lcd_hdcMem, sub_lcd_hbmp);
	
	
	
#endif

	ReleaseDC(device.hwnd, hdc);
} /* end of w32_dspl_init */


/*****************************************************************************
* FUNCTION
*  w32_update_screen
* DESCRIPTION
*  update the screen
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_update_screen(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	HDC hdc;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (!lcd_updating)
	{
		hdc = GetDC(device.hwnd);
		BitBlt(	hdc, 
					lcd_offset_x,
					lcd_offset_y,
					skin_lcd_width, //LCD_WIDTH
					skin_lcd_height, //LCD_HEIGHT
					lcd_hdcMem, 0, 0, SRCCOPY) ;
#ifdef DUAL_LCD
		BitBlt (hdc, 
				sub_lcd_offset_x,
				sub_lcd_offset_y,
				skin_sublcd_width,  //SUBLCD_WIDTH
				skin_sublcd_height, //SUBLCD_HEIGHT
				sub_lcd_hdcMem, 0, 0, SRCCOPY) ;
#endif
		ReleaseDC(device.hwnd,hdc);
	}
} /* end of w32_update_screen */

void w32_light_black_draw(int x, int y, int w, int h, HDC hdc, HDC lcd)
{
	RECT rc;
	BLENDFUNCTION bf;
	HBRUSH	black_brush;
	

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0; // ignore source alpha channel
	bf.SourceConstantAlpha = mainlcd_backlight_level*255 /9;

	rc.left = x;
	rc.top  = y;
	rc.right = x + w-1;
	rc.bottom = y + h-1;
	
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	black_brush = CreateSolidBrush(RGB(0,0,0));
	FillRect(hdc, &rc, black_brush);					
	AlphaBlend(hdc,x,y,w,h,lcd,0,0,w,h,bf);
	DeleteObject(black_brush);
}



void w32_light_black_draw_mmi(void)
{
	HDC			hdc;
	hdc = GetDC(device.hwnd);
	w32_light_black_draw(g_LCD_OFFSET_X,g_LCD_OFFSET_Y,g_LCD_WIDTH,g_LCD_HEIGHT, hdc,lcd_hdcMem);
}
/*****************************************************************************
* FUNCTION
*  w32_put_screen
* DESCRIPTION
*  put a bitmap to the screen
*
* PARAMETERS
*	lcd_in	IN		LCD ID
*	x		IN		X position
*	y		IN		Y position
*	w		IN		width
*	h		IN		height
*	bmp	IN		pointer to the bitmap
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_put_screen(unsigned char lcd_id, int x, int y, int w, int h, unsigned char *bmp)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	HDC			hdc;
	//mainlcd_backlight_level = 3;
	//kal_print("w32_put_screen");

	hdc = GetDC(device.hwnd);
	//lcd_updating = KAL_TRUE;
	if (lcd_id == MAIN_LCD)
	{
		
		if(w == LCD_WIDTH && h==LCD_HEIGHT)
		{
			SetDIBits(NULL, lcd_hbmp, 0, h, bmp, &bitmap_info, DIB_RGB_COLORS);
		}
		else
		{
			//BYTE *pResizeData =  (BYTE *) malloc(w*h*sizeof(BYTE)*4);
		 if(w >= LCD_WIDTH && h>=LCD_HEIGHT) //resize w,h both >=original W,H
			EnlargeDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,pResizeData,w,h);
		 else if (w < LCD_WIDTH && h< LCD_HEIGHT) //resize w,h both < original W,H
			ShrinkDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,pResizeData,w,h);
			 //The following resize is seldom use
		 else if( w >= LCD_WIDTH && h < LCD_HEIGHT) //resize w,h w >= LCD_WIDTH && h < LCD_HEIGHT
		 {
		    BYTE *ptmpResizeData =  (BYTE *) malloc(w*LCD_HEIGHT*sizeof(BYTE)*4);
			EnlargeDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,ptmpResizeData,w,LCD_HEIGHT);

			ShrinkDataInt(ptmpResizeData,w, LCD_HEIGHT,pResizeData,w,h);
			free(ptmpResizeData);
		 }
		 else if( w < LCD_WIDTH && h >= LCD_HEIGHT)//resize w,h; w < LCD_WIDTH && h >= LCD_HEIGHT
		 {
			BYTE *ptmpResizeData =  (BYTE *) malloc(LCD_WIDTH*h*sizeof(BYTE)*4);
			EnlargeDataInt(bmp,LCD_WIDTH, LCD_HEIGHT,ptmpResizeData,LCD_WIDTH,h);

			ShrinkDataInt(ptmpResizeData,LCD_WIDTH, h,pResizeData,w,h);
			free(ptmpResizeData);
		 }
		SetDIBits(NULL, lcd_hbmp, 0, h, pResizeData, &bitmap_info, DIB_RGB_COLORS);
			//free(pResizeData);
		}
		if(mainlcd_backlight_level==9)
		{
			if(ViBrate_Num==0) //No Vibrate
				BitBlt(hdc,	x,y,w,h,lcd_hdcMem, 0, 0, SRCCOPY);
		
		}
		else if( mainlcd_backlight_level >=0 && mainlcd_backlight_level<=8)
		{
						
			if(ViBrate_Num==0) //No Vibrate
			{
				w32_light_black_draw(x,y,w,h,hdc,lcd_hdcMem);			
			}
		}
	
		ReleaseDC(device.hwnd,hdc);
		g_LCD_OFFSET_X = x;
		g_LCD_OFFSET_Y = y;
		g_LCD_WIDTH = w;
		g_LCD_HEIGHT = h;
	}
	else
	{
	#ifdef DUAL_LCD
		//hdc		= GetDC(device.hwnd);
		//kal_print("DUAL_LCD");
		if(w == SUBLCD_WIDTH && h==SUBLCD_HEIGHT)
		{
			SetDIBits(NULL, sub_lcd_hbmp, 0, h, bmp, &sub_bitmap_info, DIB_RGB_COLORS);
		}
		else
		{
		BYTE *psubResizeData =  (BYTE *) malloc(w*h*sizeof(BYTE)*4);
		 if(w >= SUBLCD_WIDTH && h>=SUBLCD_HEIGHT) //resize w,h both >=original W,H
			EnlargeDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubResizeData,w,h);
		 else if (w < SUBLCD_WIDTH && h< SUBLCD_HEIGHT) //resize w,h both < original W,H
			ShrinkDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubResizeData,w,h);
		 else if( w >= SUBLCD_WIDTH && h < SUBLCD_HEIGHT) //resize w,h w >= LCD_WIDTH && h < LCD_HEIGHT
		 {
		    BYTE *psubtmpResizeData =  (BYTE *) malloc(w*SUBLCD_HEIGHT*sizeof(BYTE)*4);
			EnlargeDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubtmpResizeData,w,SUBLCD_HEIGHT);

			ShrinkDataInt(psubtmpResizeData,w, SUBLCD_HEIGHT,psubResizeData,w,h);
			free(psubtmpResizeData);
		 }
		 else if( w < SUBLCD_WIDTH && h >= SUBLCD_HEIGHT)//resize w,h; w < LCD_WIDTH && h >= LCD_HEIGHT
		 {
			BYTE *psubtmpResizeData =  (BYTE *) malloc(SUBLCD_WIDTH*h*sizeof(BYTE)*4);
			EnlargeDataInt(bmp,SUBLCD_WIDTH, SUBLCD_HEIGHT,psubtmpResizeData,SUBLCD_WIDTH,h);

			ShrinkDataInt(psubtmpResizeData,SUBLCD_WIDTH, h,psubResizeData,w,h);
			free(psubtmpResizeData);
		 }
		SetDIBits(NULL, sub_lcd_hbmp, 0, h, psubResizeData, &sub_bitmap_info, DIB_RGB_COLORS);
			free(psubResizeData);
		}
		if(mainlcd_backlight_level==9)
		{
			if(ViBrate_Num==0) 
				BitBlt(hdc,x,y,w,h,sub_lcd_hdcMem, 0, 0, SRCCOPY);
		}
		else if( mainlcd_backlight_level >=0 && mainlcd_backlight_level<=8)
		{
			if(ViBrate_Num==0) //No Vibrate
			{
				w32_light_black_draw(x,y,w,h,hdc,sub_lcd_hdcMem);			
			}		
		}

		
		ReleaseDC(device.hwnd, hdc);
		g_SUBLCD_OFFSET_X = x;
		g_SUBLCD_OFFSET_Y = y;
		g_SUBLCD_WIDTH = w;
		g_SUBLCD_HEIGHT = h;
	#endif
	}



} /* end of w32_put_screen */

/*****************************************************************************
* FUNCTION
*  w32_lcd_update
* DESCRIPTION
*  update the lcd
*
* PARAMETERS
*	lcd_para			IN		the updating parameters for lcd
*	lcd_layer_data		IN		the related information for each layer
*	layer_flag_table	IN		the table of layer updating flag
*	gdi_w32_lcd_buffer	IN		the merged lcd image
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_lcd_update(
	lcd_frame_update_struct *lcd_para,
	lcd_layer_struct lcd_layer_data[][SIMULATOR_LAYER_COUNT],
	U32 layer_flag_table[],
	U32 *gdi_w32_lcd_buffer
)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	unsigned char	layer_id;
	unsigned char	lcd_id;


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* MODIS UI not init yet */
	if(MODIS_UI_layer_ptr == NULL)
		return; 
	
	/* set up the necessary information for DLL_UI */
	lcd_id = lcd_para->lcd_id;

	if (lcd_id == MAIN_LCD)
	{
		for (layer_id = 0; layer_id < SIMULATOR_LAYER_COUNT; layer_id++)
		{
			uil_ptr = MODIS_UI_layer_ptr[layer_id];

			uil_ptr->layer_x_offset			= lcd_layer_data[lcd_id - 1][layer_id].x_offset;
			uil_ptr->layer_y_offset			= lcd_layer_data[lcd_id - 1][layer_id].y_offset;
			uil_ptr->layer_width			= lcd_layer_data[lcd_id - 1][layer_id].column_number;
			uil_ptr->layer_height			= lcd_layer_data[lcd_id - 1][layer_id].row_number;

			uil_ptr->roi_x_offset			= lcd_para->roi_offset_x;
			uil_ptr->roi_y_offset			= lcd_para->roi_offset_y;
			uil_ptr->roi_width				= lcd_para->lcm_end_x - lcd_para->lcm_start_x;
			uil_ptr->roi_height				= lcd_para->lcm_end_y - lcd_para->lcm_start_y;

			uil_ptr->source_key_enable		= lcd_layer_data[lcd_id - 1][layer_id].source_key_enable;
			uil_ptr->opacity_enable			= lcd_layer_data[lcd_id - 1][layer_id].opacity_enable;
			uil_ptr->source_key				= lcd_layer_data[lcd_id - 1][layer_id].source_key;
			uil_ptr->opacity_value			= lcd_layer_data[lcd_id - 1][layer_id].opacity_value;
			
			uil_ptr->layer_enable			= (lcd_para->update_layer & layer_flag_table[layer_id]);
			uil_ptr->frame_buffer_address	= lcd_layer_data[lcd_id - 1][layer_id].frame_buffer_address;

			uil_ptr->active_layer			= active_layer;
		}
	}

	/* send the main-lcd information to MODIS_UI for displaying */
	if (lcd_id == MAIN_LCD)
	{
		//Info monitor update
		MoDisUISetLayerData(MODIS_UI_layer_ptr, LCD_WIDTH, LCD_HEIGHT, SIMULATOR_LAYER_COUNT, &new_application_flag);
		//MoDisUISetLayerData(MODIS_UI_layer_ptr, skin_lcd_width, skin_lcd_height, SIMULATOR_LAYER_COUNT, &new_application_flag);
	}

	if (lcd_id == MAIN_LCD)
	{
		//w32_put_screen(lcd_id, lcd_offset_x, lcd_offset_y, LCD_WIDTH, LCD_HEIGHT, (unsigned char*)gdi_w32_lcd_buffer);
		w32_put_screen(lcd_id, lcd_offset_x, lcd_offset_y, skin_lcd_width, skin_lcd_height, (unsigned char*)gdi_w32_lcd_buffer);
	}
	else
	{
#ifdef DUAL_LCD
		//w32_put_screen(lcd_id, sub_lcd_offset_x, sub_lcd_offset_y, SUBLCD_WIDTH, SUBLCD_HEIGHT, (unsigned char*)gdi_w32_lcd_buffer);
		w32_put_screen(lcd_id, sub_lcd_offset_x, sub_lcd_offset_y, skin_sublcd_width, skin_sublcd_height, (unsigned char*)gdi_w32_lcd_buffer);
#endif
	}
} /* end of w32_lcd_update */


/*****************************************************************************
* FUNCTION
*  w32_ResetKeyMemory
* DESCRIPTION
*  initialize the memory for images of keys
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_ResetKeyMemory()
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	i;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	device.main_bitmap = NULL;

	for (i = 0; i < PC_KEY_NUMBERS; i++)
	{
		device.key_bitmap[i] = NULL;
		device.key_up_bitmap[i] = NULL;
	}
} /* end of w32_ResetKeyMemory */



typedef struct
{
	int	key_bitmap_id;
	int sw_drv_key_code;
	unsigned int	pc_key_code;
} key_mapping_struct;

/* MoDIS keycode mapping table :
 * according "read key profile setting", "MoDIS.ini setting" and driver key code*/
static key_mapping_struct key_mapping_table[] =
{
	{0,		DEVICE_KEY_1,		VK_NUMPAD1},
	{1,		DEVICE_KEY_2,		VK_NUMPAD2},
	{2,		DEVICE_KEY_3,		VK_NUMPAD3},
	{3,		DEVICE_KEY_4,		VK_NUMPAD4},
	{4,		DEVICE_KEY_5,		VK_NUMPAD5},
	{5,		DEVICE_KEY_6,		VK_NUMPAD6},
	{6,		DEVICE_KEY_7,		VK_NUMPAD7},
	{7,		DEVICE_KEY_8,		VK_NUMPAD8},
	{8,		DEVICE_KEY_9,		VK_NUMPAD9},
	{9,		DEVICE_KEY_0,		VK_NUMPAD0},
	{10,	DEVICE_KEY_STAR,	VK_DIVIDE},		/* start */
	{11,	DEVICE_KEY_HASH,	VK_MULTIPLY},   /* hash */
	{12,	DEVICE_KEY_SK_LEFT,	VK_INSERT},		/* LSK */
	{13,	DEVICE_KEY_SK_RIGHT,VK_PRIOR},		/* RSK */
	{14,	DEVICE_KEY_SEND,	VK_DELETE},		/* send */
	{15,	DEVICE_KEY_END,		VK_NEXT},		/* end */
	{16,	DEVICE_KEY_UP,		VK_UP},			/* up */
	{17,	DEVICE_KEY_DOWN,	VK_DOWN},		/* down */
	{18,	DEVICE_KEY_LEFT,	VK_LEFT},		/* left */
	{19,	DEVICE_KEY_RIGHT,	VK_RIGHT},		/* right */
	{20,	DEVICE_KEY_MENU,	VK_HOME},		/* menu key */
	{21,	DEVICE_KEY_FUNCTION,VK_DECIMAL},	/* func key */
	{22,	DEVICE_KEY_VOL_UP,	VK_ADD},		/* Vol Up */
	{23,	DEVICE_KEY_VOL_DOWN,VK_SUBTRACT},   /* Vol Down */
	{24,	DEVICE_KEY_POWER,	VK_RETURN},		/* power key */
	{25,	DEVICE_KEY_CLEAR,	VK_END},		/* clear key */
	{26,	DEVICE_KEY_MP3_FWD,	0x7a},		/* clear key */
	{27,	DEVICE_KEY_MP3_PLAY_STOP,	0x78},		/* clear key */
	{28,	DEVICE_KEY_MP3_BACK,	0x63},		/* clear key */
};


/*****************************************************************************
* FUNCTION
*  w32_convert_key_code
* DESCRIPTION
*  convert PC key code to SW driver key code
*
* PARAMETERS
*	void
* RETURNS
*  the index of the key mapping table
* GLOBALS AFFECTED
*  void
*****************************************************************************/
int w32_convert_key_code(unsigned int vk)
{
	int i=0;

	for (i=0; i<(sizeof(key_mapping_table)/sizeof(key_mapping_struct)); i++)
	{
		if (key_mapping_table[i].pc_key_code == vk)
		{
			/* find the mapping key code */
			return i;
		}
	}
	return -1;
}

unsigned int _hex2int(char c)
{
	if (c >= '0' && c <= '9')
		return (unsigned int)(c-'0');
	if (c >= 'a' && c <= 'f')
		return (unsigned int)(c-'a'+10);
	if (c >= 'A' && c <= 'F')
		return (unsigned int)(c-'A'+10);

	return 0;
}

/* ANSII to hex value */
unsigned int atohex(char *in)
{
	unsigned int value = 0;
	if (in[0]=='0' && (in[1]=='x' || in[1]=='X'))
	{
		in = in+2;
		while (*in != 0)
		{
			value = value*16 + _hex2int(*in);
			in++;
		}
	}
	return value;
}


/*****************************************************************************
* FUNCTION
*  w32_ReadKeyMapping
* DESCRIPTION
*  read the key mapping from the INI file
*
* PARAMETERS
*	in_path		IN		path for INI file
*	hwnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
extern 
void w32_ReadKeyMapping(char in_path[], HWND hwnd)
{
	char	buffer[512], path[512];

	HANDLE	hFind;
	WIN32_FIND_DATA FindFileData;


	hFind = FindFirstFile("MoDIS.ini", &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		/* Can't find the file "MoDIS.ini" */
		return ;
	}
	FindClose(hFind);

	/* get the complete name for opening the INI file */
	strcpy(path, "./MoDIS.ini");
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_1", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[0].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_2", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[1].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_3", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[2].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_4", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[3].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_5", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[4].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_6", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[5].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_7", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[6].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_8", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[7].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_9", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[8].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_0", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[9].pc_key_code = atohex(buffer);

	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_STAR", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[10].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_HASH", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[11].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_SK_LEFT", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[12].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_SK_RIGHT", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[13].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_SEND", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[14].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_END", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[15].pc_key_code = atohex(buffer);

	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_UP", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[16].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_DOWN", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[17].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_LEFT", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[18].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_RIGHT", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[19].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_MENU", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[20].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_FUNCTION", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[21].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_VOL_UP", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[22].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_VOL_DOWN", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[23].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_POWER", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[24].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_CLEAR", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[25].pc_key_code = atohex(buffer);

	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_MP3_FWD", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[26].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_MP3_PLAY_STOP", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[27].pc_key_code = atohex(buffer);
	GetPrivateProfileString("Keyboard-Mapping", "DEVICE_KEY_MP3_BACK", NULL, buffer, sizeof(buffer), path);
	key_mapping_table[28].pc_key_code = atohex(buffer);

}


/*****************************************************************************
* FUNCTION
*  w32_ReadKeyProfile
* DESCRIPTION
*  read the key information from the INI file
*
* PARAMETERS
*	in_path		IN		path for INI file
*	hwnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/

void w32_ReadKeyProfile(char in_path[], HWND hwnd)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	char			buffer[512], old_path[512], path[512];
	int			buffer_size = 512;
	HBITMAP		img;
	BITMAP		bmp;
	HDC			hdc;
	RECT			window_info, client_info, menu_info;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	/* save the original working directory */
	GetCurrentDirectory(512, old_path);
	/* get the complete name for opening the INI file */
	SetCurrentDirectory(in_path);
	strcpy(path, "./Profile.ini");

	/* get layout related date */
	GetPrivateProfileString("Layout", "WINDOW_WIDTH", NULL, buffer, buffer_size, path);
	device.window_width = atoi(buffer);
	GetPrivateProfileString("Layout", "WINDOW_HEIGHT", NULL, buffer, buffer_size, path);
	device.window_height = atoi(buffer);
	/*
	if(device.window_width>2000)
	{
		device.window_height = atoi(buffer);
	}*/
	GetPrivateProfileString("Layout", "MAIN_LCD_WIDTH", NULL, buffer, buffer_size, path);
	device.main_lcd_width = atoi(buffer);
	GetPrivateProfileString("Layout", "MAIN_LCD_HEIGHT", NULL, buffer, buffer_size, path);
	device.main_lcd_height = atoi(buffer);
	GetPrivateProfileString("Layout", "MAIN_LCD_X", NULL, buffer, buffer_size, path);
	device.skin_main_lcd_x = atoi(buffer);
	GetPrivateProfileString("Layout", "MAIN_LCD_y", NULL, buffer, buffer_size, path);
	device.skin_main_lcd_y = atoi(buffer);
	GetPrivateProfileString("Layout", "SUB_LCD_WIDTH", NULL, buffer, buffer_size, path);
	device.sub_lcd_width = atoi(buffer);
	GetPrivateProfileString("Layout", "SUB_LCD_HEIGHT", NULL, buffer, buffer_size, path);
	device.sub_lcd_height = atoi(buffer);
	GetPrivateProfileString("Layout", "SUB_LCD_X", NULL, buffer, buffer_size, path);
	device.skin_sub_lcd_x = atoi(buffer);
	GetPrivateProfileString("Layout", "SUB_LCD_y", NULL, buffer, buffer_size, path);
	device.skin_sub_lcd_y = atoi(buffer);

	/* reset window size */
	GetWindowRect(hwnd, &window_info);
	GetClientRect(hwnd, &client_info);
	GetMenuItemRect(hwnd, GetMenu(hwnd), 0, &menu_info);
	SetWindowPos(hwnd, 0, 0, 0, device.window_width, device.window_height + (window_info.bottom - client_info.bottom) - (menu_info.bottom - menu_info.top), SWP_NOMOVE | SWP_NOZORDER);
	SendMessage(hwnd, WM_MOVE, 0, (client_info.top << 2 * sizeof(short)) + client_info.left);

	hdc = GetDC(hwnd);

	/* get coordinates & images */
	
	/* background image */
	GetPrivateProfileString("Image", "BACKGROUND", NULL, buffer, buffer_size, path);
	if (device.main_bitmap != NULL)
	{
		DeleteDC(device.main_bitmap);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.main_bitmap = CreateCompatibleDC(hdc);
	SelectObject(device.main_bitmap, img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.main_bitmap_width = (U16)bmp.bmWidth;
	device.main_bitmap_height = (U16)bmp.bmHeight;
	DeleteObject(img);
	/* key 0 */
	GetPrivateProfileString("Coordinate", "KEY_0_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[9].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_0_TOP", NULL, buffer, buffer_size, path);
	device.key_location[9].top = atoi(buffer);
	
	GetPrivateProfileString("Image", "KEY_0", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[9] != NULL)
	{
		DeleteDC(device.key_bitmap[9]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[9] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[9], img);
	
	GetPrivateProfileString("Image", "KEY_0_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[9] != NULL)
	{
		DeleteDC(device.key_up_bitmap[9]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[9] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[9], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[9].right = device.key_location[9].left + bmp.bmWidth - 1;
	device.key_location[9].bottom = device.key_location[9].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 1 */
	GetPrivateProfileString("Coordinate", "KEY_1_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[0].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_1_TOP", NULL, buffer, buffer_size, path);
	device.key_location[0].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_1", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[0] != NULL)
	{
		DeleteDC(device.key_bitmap[0]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[0] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[0], img);

	GetPrivateProfileString("Image", "KEY_1_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[0] != NULL)
	{
		DeleteDC(device.key_up_bitmap[0]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[0] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[0], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[0].right = device.key_location[0].left + bmp.bmWidth - 1;
	device.key_location[0].bottom = device.key_location[0].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 2 */
	GetPrivateProfileString("Coordinate", "KEY_2_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[1].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_2_TOP", NULL, buffer, buffer_size, path);
	device.key_location[1].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_2", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[1] != NULL)
	{
		DeleteDC(device.key_bitmap[1]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[1] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[1], img);

	GetPrivateProfileString("Image", "KEY_2_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[1] != NULL)
	{
		DeleteDC(device.key_up_bitmap[1]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[1] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[1], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[1].right = device.key_location[1].left + bmp.bmWidth - 1;
	device.key_location[1].bottom = device.key_location[1].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 3 */
	GetPrivateProfileString("Coordinate", "KEY_3_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[2].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_3_TOP", NULL, buffer, buffer_size, path);
	device.key_location[2].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_3", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[2] != NULL)
	{
		DeleteDC(device.key_bitmap[2]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[2] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[2], img);

	GetPrivateProfileString("Image", "KEY_3_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[2] != NULL)
	{
		DeleteDC(device.key_up_bitmap[2]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[2] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[2], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[2].right = device.key_location[2].left + bmp.bmWidth - 1;
	device.key_location[2].bottom = device.key_location[2].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 4 */
	GetPrivateProfileString("Coordinate", "KEY_4_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[3].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_4_TOP", NULL, buffer, buffer_size, path);
	device.key_location[3].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_4", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[3] != NULL)
	{
		DeleteDC(device.key_bitmap[3]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[3] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[3], img);

	GetPrivateProfileString("Image", "KEY_4_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[3] != NULL)
	{
		DeleteDC(device.key_up_bitmap[3]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[3] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[3], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[3].right = device.key_location[3].left + bmp.bmWidth - 1;
	device.key_location[3].bottom = device.key_location[3].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 5 */
	GetPrivateProfileString("Coordinate", "KEY_5_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[4].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_5_TOP", NULL, buffer, buffer_size, path);
	device.key_location[4].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_5", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[4] != NULL)
	{
		DeleteDC(device.key_bitmap[4]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[4] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[4], img);

	GetPrivateProfileString("Image", "KEY_5_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[4] != NULL)
	{
		DeleteDC(device.key_up_bitmap[4]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[4] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[4], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[4].right = device.key_location[4].left + bmp.bmWidth - 1;
	device.key_location[4].bottom = device.key_location[4].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 6 */
	GetPrivateProfileString("Coordinate", "KEY_6_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[5].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_6_TOP", NULL, buffer, buffer_size, path);
	device.key_location[5].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_6", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[5] != NULL)
	{
		DeleteDC(device.key_bitmap[5]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[5] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[5], img);

	GetPrivateProfileString("Image", "KEY_6_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[5] != NULL)
	{
		DeleteDC(device.key_up_bitmap[5]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[5] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[5], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[5].right = device.key_location[5].left + bmp.bmWidth - 1;
	device.key_location[5].bottom = device.key_location[5].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 7 */
	GetPrivateProfileString("Coordinate", "KEY_7_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[6].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_7_TOP", NULL, buffer, buffer_size, path);
	device.key_location[6].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_7", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[6] != NULL)
	{
		DeleteDC(device.key_bitmap[6]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[6] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[6], img);

	GetPrivateProfileString("Image", "KEY_7_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[6] != NULL)
	{
		DeleteDC(device.key_up_bitmap[6]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[6] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[6], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[6].right = device.key_location[6].left + bmp.bmWidth - 1;
	device.key_location[6].bottom = device.key_location[6].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 8 */
	GetPrivateProfileString("Coordinate", "KEY_8_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[7].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_8_TOP", NULL, buffer, buffer_size, path);
	device.key_location[7].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_8", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[7] != NULL)
	{
		DeleteDC(device.key_bitmap[7]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[7] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[7], img);

	GetPrivateProfileString("Image", "KEY_8_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[7] != NULL)
	{
		DeleteDC(device.key_up_bitmap[7]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[7] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[7], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[7].right = device.key_location[7].left + bmp.bmWidth - 1;
	device.key_location[7].bottom = device.key_location[7].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* key 9 */
	GetPrivateProfileString("Coordinate", "KEY_9_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[8].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_9_TOP", NULL, buffer, buffer_size, path);
	device.key_location[8].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_9", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[8] != NULL)
	{
		DeleteDC(device.key_bitmap[8]);
	}
	
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[8] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[8], img);
	GetPrivateProfileString("Image", "KEY_9_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[8] != NULL)
	{
		DeleteDC(device.key_up_bitmap[8]);
	}

	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[8] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[8], img);
	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[8].right = device.key_location[8].left + bmp.bmWidth - 1;
	device.key_location[8].bottom = device.key_location[8].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* LSK */
	GetPrivateProfileString("Coordinate", "KEY_LSK_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[12].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_LSK_TOP", NULL, buffer, buffer_size, path);
	device.key_location[12].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_LSK", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[12] != NULL)
	{
		DeleteDC(device.key_bitmap[12]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[12] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[12], img);

	GetPrivateProfileString("Image", "KEY_LSK_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[12] != NULL)
	{
		DeleteDC(device.key_up_bitmap[12]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[12] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[12], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[12].right = device.key_location[12].left + bmp.bmWidth - 1;
	device.key_location[12].bottom = device.key_location[12].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* RSK */
	GetPrivateProfileString("Coordinate", "KEY_RSK_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[13].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_RSK_TOP", NULL, buffer, buffer_size, path);
	device.key_location[13].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_RSK", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[13] != NULL)
	{
		DeleteDC(device.key_bitmap[13]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[13] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[13], img);

	GetPrivateProfileString("Image", "KEY_RSK_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[13] != NULL)
	{
		DeleteDC(device.key_up_bitmap[13]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[13] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[13], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[13].right = device.key_location[13].left + bmp.bmWidth - 1;
	device.key_location[13].bottom = device.key_location[13].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* up arrow key */
	GetPrivateProfileString("Coordinate", "KEY_UP_ARROW_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[16].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_UP_ARROW_TOP", NULL, buffer, buffer_size, path);
	device.key_location[16].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_UP_ARROW", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[16] != NULL)
	{
		DeleteDC(device.key_bitmap[16]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[16] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[16], img);

	GetPrivateProfileString("Image", "KEY_UP_ARROW_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[16] != NULL)
	{
		DeleteDC(device.key_up_bitmap[16]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[16] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[16], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[16].right = device.key_location[16].left + bmp.bmWidth - 1;
	device.key_location[16].bottom = device.key_location[16].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* down arrow key */
	GetPrivateProfileString("Coordinate", "KEY_DOWN_ARROW_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[17].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_DOWN_ARROW_TOP", NULL, buffer, buffer_size, path);
	device.key_location[17].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_DOWN_ARROW", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[17] != NULL)
	{
		DeleteDC(device.key_bitmap[17]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[17] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[17], img);

	GetPrivateProfileString("Image", "KEY_DOWN_ARROW_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[17] != NULL)
	{
		DeleteDC(device.key_up_bitmap[17]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[17] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[17], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[17].right = device.key_location[17].left + bmp.bmWidth - 1;
	device.key_location[17].bottom = device.key_location[17].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* left arrow key */
	GetPrivateProfileString("Coordinate", "KEY_LEFT_ARROW_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[18].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_LEFT_ARROW_TOP", NULL, buffer, buffer_size, path);
	device.key_location[18].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_LEFT_ARROW", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[18] != NULL)
	{
		DeleteDC(device.key_bitmap[18]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[18] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[18], img);

	GetPrivateProfileString("Image", "KEY_LEFT_ARROW_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[18] != NULL)
	{
		DeleteDC(device.key_up_bitmap[18]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[18] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[18], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[18].right = device.key_location[18].left + bmp.bmWidth - 1;
	device.key_location[18].bottom = device.key_location[18].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* righy arrow key */
	GetPrivateProfileString("Coordinate", "KEY_RIGHT_ARROW_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[19].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_RIGHT_ARROW_TOP", NULL, buffer, buffer_size, path);
	device.key_location[19].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_RIGHT_ARROW", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[19] != NULL)
	{
		DeleteDC(device.key_bitmap[19]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[19] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[19], img);

	GetPrivateProfileString("Image", "KEY_RIGHT_ARROW_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[19] != NULL)
	{
		DeleteDC(device.key_up_bitmap[19]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[19] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[19], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[19].right = device.key_location[19].left + bmp.bmWidth - 1;
	device.key_location[19].bottom = device.key_location[19].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* SEND key */
	GetPrivateProfileString("Coordinate", "KEY_SEND_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[14].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_SEND_TOP", NULL, buffer, buffer_size, path);
	device.key_location[14].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_SEND", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[14] != NULL)
	{
		DeleteDC(device.key_bitmap[14]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[14] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[14], img);

	GetPrivateProfileString("Image", "KEY_SEND_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[14] != NULL)
	{
		DeleteDC(device.key_up_bitmap[14]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[14] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[14], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[14].right = device.key_location[14].left + bmp.bmWidth - 1;
	device.key_location[14].bottom = device.key_location[14].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* END key */
	GetPrivateProfileString("Coordinate", "KEY_END_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[15].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_END_TOP", NULL, buffer, buffer_size, path);
	device.key_location[15].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_END", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[15] != NULL)
	{
		DeleteDC(device.key_bitmap[15]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[15] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[15], img);

	GetPrivateProfileString("Image", "KEY_END_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[15] != NULL)
	{
		DeleteDC(device.key_up_bitmap[15]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[15] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[15], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[15].right = device.key_location[15].left + bmp.bmWidth - 1;
	device.key_location[15].bottom = device.key_location[15].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* STAR key */
	GetPrivateProfileString("Coordinate", "KEY_STAR_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[10].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_STAR_TOP", NULL, buffer, buffer_size, path);
	device.key_location[10].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_STAR", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[10] != NULL)
	{
		DeleteDC(device.key_bitmap[10]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[10] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[10], img);

	GetPrivateProfileString("Image", "KEY_STAR_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[10] != NULL)
	{
		DeleteDC(device.key_up_bitmap[10]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[10] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[10], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[10].right = device.key_location[10].left + bmp.bmWidth - 1;
	device.key_location[10].bottom = device.key_location[10].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* POUND key */
	GetPrivateProfileString("Coordinate", "KEY_POUND_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[11].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_POUND_TOP", NULL, buffer, buffer_size, path);
	device.key_location[11].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_POUND", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[11] != NULL)
	{
		DeleteDC(device.key_bitmap[11]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[11] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[11], img);

	GetPrivateProfileString("Image", "KEY_POUND_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[11] != NULL)
	{
		DeleteDC(device.key_up_bitmap[11]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[11] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[11], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[11].right = device.key_location[11].left + bmp.bmWidth - 1;
	device.key_location[11].bottom = device.key_location[11].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* volume-up key */
	GetPrivateProfileString("Coordinate", "KEY_VOL_UP_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[22].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_VOL_UP_TOP", NULL, buffer, buffer_size, path);
	device.key_location[22].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_VOL_UP", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[22] != NULL)
	{
		DeleteDC(device.key_bitmap[22]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[22] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[22], img);

	GetPrivateProfileString("Image", "KEY_VOL_UP_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[22] != NULL)
	{
		DeleteDC(device.key_up_bitmap[22]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[22] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[22], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[22].right = device.key_location[22].left + bmp.bmWidth - 1;
	device.key_location[22].bottom = device.key_location[22].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* volume-down key */
	GetPrivateProfileString("Coordinate", "KEY_VOL_DOWN_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[23].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_VOL_DOWN_TOP", NULL, buffer, buffer_size, path);
	device.key_location[23].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_VOL_DOWN", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[23] != NULL)
	{
		DeleteDC(device.key_bitmap[23]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[23] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[23], img);

	GetPrivateProfileString("Image", "KEY_VOL_DOWN_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[23] != NULL)
	{
		DeleteDC(device.key_up_bitmap[23]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[23] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[23], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[23].right = device.key_location[23].left + bmp.bmWidth - 1;
	device.key_location[23].bottom = device.key_location[23].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* KEY_CLEAR */
	GetPrivateProfileString("Coordinate", "KEY_CLEAR_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[25].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_CLEAR_TOP", NULL, buffer, buffer_size, path);
	device.key_location[25].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_CLEAR", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[25] != NULL)
	{
		DeleteDC(device.key_bitmap[25]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[25] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[25], img);

	GetPrivateProfileString("Image", "KEY_CLEAR_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[25] != NULL)
	{
		DeleteDC(device.key_up_bitmap[25]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[25] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[25], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[25].right = device.key_location[25].left + bmp.bmWidth - 1;
	device.key_location[25].bottom = device.key_location[25].top + bmp.bmHeight - 1;
	DeleteObject(img);

	/* KEY_FWD */
	GetPrivateProfileString("Coordinate", "KEY_FWD_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[26].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_FWD_TOP", NULL, buffer, buffer_size, path);
	device.key_location[26].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_FWD", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[26] != NULL)
	{
		DeleteDC(device.key_bitmap[26]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[26] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[26], img);

	GetPrivateProfileString("Image", "KEY_FWD_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[26] != NULL)
	{
		DeleteDC(device.key_up_bitmap[26]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[26] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[26], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[26].right = device.key_location[26].left + bmp.bmWidth - 1;
	device.key_location[26].bottom = device.key_location[26].top + bmp.bmHeight - 1;

	/* KEY_PLAY_STOP */
	GetPrivateProfileString("Coordinate", "KEY_PLAY_STOP_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[27].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_PLAY_STOP_TOP", NULL, buffer, buffer_size, path);
	device.key_location[27].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_PLAY_STOP", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[27] != NULL)
	{
		DeleteDC(device.key_bitmap[27]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[27] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[27], img);

	GetPrivateProfileString("Image", "KEY_PLAY_STOP_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[27] != NULL)
	{
		DeleteDC(device.key_up_bitmap[27]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[27] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[27], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[27].right = device.key_location[27].left + bmp.bmWidth - 1;
	device.key_location[27].bottom = device.key_location[27].top + bmp.bmHeight - 1;

	/* KEY_BACK */
	GetPrivateProfileString("Coordinate", "KEY_BACK_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[28].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_BACK_TOP", NULL, buffer, buffer_size, path);
	device.key_location[28].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_BACK", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[28] != NULL)
	{
		DeleteDC(device.key_bitmap[28]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[28] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[28], img);

	GetPrivateProfileString("Image", "KEY_BACK_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[28] != NULL)
	{
		DeleteDC(device.key_up_bitmap[28]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[28] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[28], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[28].right = device.key_location[28].left + bmp.bmWidth - 1;
	device.key_location[28].bottom = device.key_location[28].top + bmp.bmHeight - 1;
	/* KEY_QUICK_ACS */
	GetPrivateProfileString("Coordinate", "KEY_QUICK_ACS_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[21].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_QUICK_ACS_TOP", NULL, buffer, buffer_size, path);
	device.key_location[21].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_QUICK_ACS", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[21] != NULL)
	{
		DeleteDC(device.key_bitmap[21]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[21] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[21], img);

	GetPrivateProfileString("Image", "KEY_QUICK_ACS_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[21] != NULL)
	{
		DeleteDC(device.key_up_bitmap[21]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[21] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[21], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[21].right = device.key_location[21].left + bmp.bmWidth - 1;
	device.key_location[21].bottom = device.key_location[21].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* KEY_ENTER */
	GetPrivateProfileString("Coordinate", "KEY_ENTER_LEFT", NULL, buffer, buffer_size, path);
	device.key_location[20].left = atoi(buffer);
	GetPrivateProfileString("Coordinate", "KEY_ENTER_TOP", NULL, buffer, buffer_size, path);
	device.key_location[20].top = atoi(buffer);

	GetPrivateProfileString("Image", "KEY_ENTER", NULL, buffer, buffer_size, path);
	if (device.key_bitmap[20] != NULL)
	{
		DeleteDC(device.key_bitmap[20]);
	}
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_bitmap[20] = CreateCompatibleDC(hdc);
	SelectObject(device.key_bitmap[20], img);

	GetPrivateProfileString("Image", "KEY_ENTER_UP", NULL, buffer, buffer_size, path);
	if (device.key_up_bitmap[20] != NULL)
	{
		DeleteDC(device.key_up_bitmap[20]);
	}
	DeleteObject(img);
	img = (HBITMAP)LoadImage(0, buffer, IMAGE_BITMAP, 0, 0, LR_DEFAULTCOLOR | LR_LOADFROMFILE);
	device.key_up_bitmap[20] = CreateCompatibleDC(hdc);
	SelectObject(device.key_up_bitmap[20], img);

	GetObject(img, sizeof(BITMAP), &bmp);
	device.key_location[20].right = device.key_location[20].left + bmp.bmWidth - 1;
	device.key_location[20].bottom = device.key_location[20].top + bmp.bmHeight - 1;
	DeleteObject(img);
	/* restore the original working directory */
	SetCurrentDirectory(old_path);
	ReleaseDC(hwnd, hdc);
	w32_ReadKeyMapping(old_path, hwnd);
} /* end of w32_ReadKeyProfile */


/*****************************************************************************
* FUNCTION
*  w32_screen_init
* DESCRIPTION
*  initialize the screen
*
* PARAMETERS
*	hWnd			IN		window handle
*	hInstance	IN		handle of instance
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_screen_init(HWND hWnd, HINSTANCE hInstance)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   //int i,j;


   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	device.hwnd = hWnd;

	w32_dspl_init();
} /* end of w32_screen_init */


/*****************************************************************************
* FUNCTION
*  w32_draw_main_bitmap
* DESCRIPTION
*  draw the main bitmap
*
* PARAMETERS
*	hdc			IN		dc handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_draw_main_bitmap(HDC hdc)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	
	BitBlt(hdc, 0, 0, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
	
} /* end of w32_draw_main_bitmap */


/*****************************************************************************
* FUNCTION
*  w32_vibrate_by_move
* DESCRIPTION
*  vibrate_by_move
*
* PARAMETERS
*	interval means millsecond
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_vibrate_by_move(kal_uint8 onoff) //interval mean milisecond
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	//char		buf[64];
	
	HDC		hdc;
	//int i;
	hdc = GetDC(device.hwnd);
	
	if(!onoff)
	{
		//Vibrate_Timer = FALSE;
		if(ViBrate_Num!=0)
			MoDISCallTimer(FALSE);
		BitBlt(hdc, 0, 0, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
		ViBrate_Num = 0 ;
		return;
	}
	else
	{
		if(ViBrate_Num==0)
			MoDISCallTimer(TRUE);
		//Vibrate_Timer = TRUE;
		if(ViBrate_Num%2==0)
		{	
			BitBlt(hdc, 0, 0, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
			if(mainlcd_backlight_level ==9)
				BitBlt(hdc,	g_LCD_OFFSET_X,g_LCD_OFFSET_Y,g_LCD_WIDTH,g_LCD_HEIGHT,lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=0 && mainlcd_backlight_level<=8)
				w32_light_black_draw(g_LCD_OFFSET_X,g_LCD_OFFSET_Y,g_LCD_WIDTH,g_LCD_HEIGHT, hdc,lcd_hdcMem);
			#ifdef DUAL_LCD
			
			if(mainlcd_backlight_level ==9)
				BitBlt(hdc,	g_SUBLCD_OFFSET_X,g_SUBLCD_OFFSET_Y,g_SUBLCD_WIDTH,g_SUBLCD_HEIGHT,sub_lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=0 && mainlcd_backlight_level<=8)
				w32_light_black_draw(g_SUBLCD_OFFSET_X,g_SUBLCD_OFFSET_Y,g_SUBLCD_WIDTH,g_SUBLCD_HEIGHT, hdc,sub_lcd_hdcMem);
		
			#endif
		
		}
		//Sleep(300);
		else
		{
			BitBlt(hdc, VIBRATE_PIXEL, VIBRATE_PIXEL, device.main_bitmap_width, device.main_bitmap_height, device.main_bitmap, 0, 0, SRCCOPY);
			if(mainlcd_backlight_level ==9)
				BitBlt(hdc,	g_LCD_OFFSET_X+VIBRATE_PIXEL,g_LCD_OFFSET_Y+VIBRATE_PIXEL,g_LCD_WIDTH,g_LCD_HEIGHT,lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=0 && mainlcd_backlight_level<=8)
				w32_light_black_draw(g_LCD_OFFSET_X+VIBRATE_PIXEL,g_LCD_OFFSET_Y+VIBRATE_PIXEL,g_LCD_WIDTH,g_LCD_HEIGHT, hdc,lcd_hdcMem);
			#ifdef DUAL_LCD
			
			if(mainlcd_backlight_level ==9)
				BitBlt(hdc,	g_SUBLCD_OFFSET_X+VIBRATE_PIXEL,g_SUBLCD_OFFSET_Y+VIBRATE_PIXEL,g_SUBLCD_WIDTH,g_SUBLCD_HEIGHT,sub_lcd_hdcMem, 0, 0, SRCCOPY);
			else if (mainlcd_backlight_level >=0 && mainlcd_backlight_level<=8)
				w32_light_black_draw(g_SUBLCD_OFFSET_X+VIBRATE_PIXEL,g_SUBLCD_OFFSET_Y+VIBRATE_PIXEL,g_SUBLCD_WIDTH,g_SUBLCD_HEIGHT, hdc,sub_lcd_hdcMem);
		
			#endif
		
		}
		ViBrate_Num++;
	}
	ReleaseDC(device.hwnd, hdc);
}/* end of w32_vibrate_by_move */


/*****************************************************************************
* FUNCTION
*  w32_keyup_by_mouse
* DESCRIPTION
*  function for mouse button up
*
* PARAMETERS
*	hWnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keyup_by_mouse(HWND hWnd,int wParam,int xNewPos,int yNewPos)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	//char		buf[64];
	HDC		hdc;


   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	
	hdc = GetDC(hWnd);
	if ((wParam>=96 && wParam <=106)||wParam==111)//111 means *, 106 means#
	{
		int keyvalue;
		
		switch(wParam)
		{
		case 96:
					 keyvalue = 9;
					 break;
		case 106:
					 keyvalue = 11;
					 break;
		case 111:
					 keyvalue = 10;
					 break;
			default:
				keyvalue=wParam-97;
		}
		
		BitBlt(hdc, device.key_location[keyvalue].left, device.key_location[keyvalue].top, device.key_location[keyvalue].right - device.key_location[keyvalue].left + 1, device.key_location[keyvalue].bottom - device.key_location[keyvalue].top + 1, device.key_up_bitmap[keyvalue], 0, 0, SRCCOPY);
		if (key_release != -1)
		{
			w32_key_detect_ind((unsigned char)1, (unsigned char)keyvalue);
		}
	}
	else
	{
		BitBlt(hdc, device.key_location[key_release].left, device.key_location[key_release].top, device.key_location[key_release].right - device.key_location[key_release].left + 1, device.key_location[key_release].bottom - device.key_location[key_release].top + 1, device.key_up_bitmap[key_release], 0, 0, SRCCOPY);
	
		if (key_release != -1)
		{
			w32_key_detect_ind((unsigned char)1, (unsigned char)key_release);
		}
	}
	ReleaseDC(hWnd, hdc);
	
  
} /* end of w32_keyup_by_mouse */


/*****************************************************************************
* FUNCTION
*  w32_keydown_by_mouse
* DESCRIPTION
*  function for mouse button down
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keydown_by_mouse(HWND hWnd, int xPos, int yPos,int xNewPos,int yNewPos)
{

	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	HDC		hdc;
	int		i; 
	BOOL		status = FALSE;


   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	key_release = -1;

	xPos -= keypad_offset_x;
	yPos -= keypad_offset_y;

	for (i=0; i < PC_KEY_NUMBERS; i++)
	{
		if (xPos > device.key_location[i].left && xPos < device.key_location[i].right &&
			yPos > device.key_location[i].top && yPos < device.key_location[i].bottom)
		{	
         status = TRUE;
			break;	
      }
	}
	if (status)
	{
		hdc = GetDC(hWnd);
		BitBlt(hdc, device.key_location[i].left, device.key_location[i].top, device.key_location[i].right - device.key_location[i].left + 1, device.key_location[i].bottom - device.key_location[i].top + 1, device.key_bitmap[i], 0, 0, SRCCOPY);

		w32_key_detect_ind((unsigned char)0, (unsigned char)i);
		key_release = i;
		ReleaseDC(hWnd, hdc);
	}

} /* end of w32_keydown_by_mouse */


/*****************************************************************************
* FUNCTION
*  w32_mouse_move_enable
* DESCRIPTION
*  mouse move enable
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_mouse_move_enable(HWND hWnd, int xPos, int yPos,int xNewScrnSize,int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int		i; 
	int		mx, my;
	BOOL		status = FALSE;
	HDC		hdc;
	char		buf[128];
	RECT		rect;
	COLORREF	crBkgnd;
	HBRUSH	hbrBkgnd;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	mx = xPos;
	my = yPos;
 
	xPos -= keypad_offset_x;
	yPos -= keypad_offset_y;
	
	for (i=0 ; i < PC_KEY_NUMBERS; i++)
	{
		if (xPos > device.key_location[i].left && xPos < device.key_location[i].right &&
			yPos > device.key_location[i].top && yPos < device.key_location[i].bottom)
		{	
         status = TRUE;
			break;	
      }
	}  
	if (status)
	{
		SetCursor(LoadCursor(0, MAKEINTRESOURCE(32649)));
	}

	// display position
	hdc			= GetDC(device.hwnd);
	rect.top		= keypad_offset_y;
	rect.left	= keypad_offset_x;
	rect.right	= keypad_offset_x + 50;
	rect.bottom	= keypad_offset_y + 15;

	crBkgnd = GetBkColor(hdc); 
	hbrBkgnd = CreateSolidBrush(crBkgnd); 
	FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));

	sprintf(buf, "(%d,%d)", mx - lcd_offset_x, my - lcd_offset_y);
	DrawText(hdc, buf, strlen(buf), &rect, DT_CENTER);

	ReleaseDC(device.hwnd, hdc);
} /* end of w32_mouse_move_enable */


/*****************************************************************************
* FUNCTION
*  w32_keydown_by_shortcut
* DESCRIPTION
*  keydown from shortcut
*
* PARAMETERS
*	hWnd			IN		window handle
*	vk				IN		key
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/

extern signed int osc_platform_print_msg ( const char *format, ... );

void w32_keydown_by_shortcut( HWND hWnd, int vk )
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	i = 0;
	HDC	hdc;

	
	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	osc_platform_print_msg("key down %d\n", vk);

	i = key_release = -1;

	i = w32_convert_key_code(vk);

	if (i >= 0)
	{
		hdc = GetDC(hWnd);
		BitBlt(hdc, device.key_location[i].left, device.key_location[i].top, device.key_location[i].right - device.key_location[i].left + 1, device.key_location[i].bottom - device.key_location[i].top + 1, device.key_bitmap[i], 0, 0, SRCCOPY);
		
		w32_key_detect_ind((unsigned char)0, (unsigned char)i);
		key_release = i;
		ReleaseDC(hWnd, hdc);
	}
} /* end of w32_keydown_by_shortcut */


/*****************************************************************************
* FUNCTION
*  w32_keyup_by_shortcut
* DESCRIPTION
*  keydown from shortcut
*
* PARAMETERS
*	hWnd			IN		window handle
*	wParam		IN		wParam
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void w32_keyup_by_shortcut(HWND hWnd, unsigned int wParam)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	osc_platform_print_msg("keyup\n");
	w32_keyup_by_mouse(hWnd,wParam,LCD_WIDTH,LCD_HEIGHT);

} /* end of w32_keyup_by_shortcut */


/*****************************************************************************
* FUNCTION
*  DisplayToDebugwindow
* DESCRIPTION
*  display to debug window
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void DisplayToDebugwindow(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of DisplayToDebugwindow */


/*****************************************************************************
* FUNCTION
*  LCD_Dummy
* DESCRIPTION
*  LCD dummy function
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void LCD_Dummy(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of LCD_Dummy */


/*****************************************************************************
* FUNCTION
*  LCD_Dummy_Return
* DESCRIPTION
*  LCD dummy return
*
* PARAMETERS
*	void
* RETURNS
*  3
* GLOBALS AFFECTED
*  void
*****************************************************************************/
kal_uint8 LCD_Dummy_Return()
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   return 3;
} /* end of LCD_Dummy_Return */




/*****************************************************************************
* FUNCTION
*  LCD_Init_MODIS
* DESCRIPTION
*  LCD initialization for MODIS
*
* PARAMETERS
*	bkground		IN		background
*	buf_addr		IN		address for the buffer
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void LCD_Init_MODIS(kal_uint32 bkground, void **buf_addr)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	x;
	int	y;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	for (x = 0; x < LCD_WIDTH; x++)
	{
		for (y = 0; y < LCD_HEIGHT; y++)
		{
			gShadowBuffer[y][x] = bkground;
		}
	}

	if (buf_addr)
	{
		*buf_addr = &gShadowBuffer[0][0];
	}
} /* end of LCD_Init_MODIS */



/*****************************************************************************
* FUNCTION
*  get_lcd_status
* DESCRIPTION
*  get lcd status
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
kal_bool get_lcd_status(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	return 0;
} /* end of get_lcd_status */


/*****************************************************************************
* FUNCTION
*  modis_ui_set_new_application_flag
* DESCRIPTION
*  set the flag to indicate that a new application starts
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void modis_ui_set_new_application_flag()
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	new_application_flag = 1;
} /* end of modis_ui_set_new_application_flag */


/*****************************************************************************
* FUNCTION
*  modis_ui_set_layer_data
* DESCRIPTION
*  set the flag to indicate that a new application starts
*
* PARAMETERS
*	layer_index			IN		index for the layer
*	lcd_id				IN		lcd id
*	text_clip_left		IN		text clipping region info
*	text_clip_top		IN		text clipping region info
*	text_clip_right	IN		text clipping region info
*	text_clip_bottom	IN		text clipping region info
*	gfx_clip_left		IN		clipping region info
*	gfx_clip_top		IN		clipping region info
*	gfx_clip_right		IN		clipping region info
*	gfx_clip_bottom	IN		clipping region info
*	current_handle		IN		current lcd handle
*	active_handle		IN		active lcd handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void modis_ui_set_layer_data(
	U8			layer_index,
	U8			lcd_id,
	S32		text_clip_left,
	S32		text_clip_top,
	S32		text_clip_right,
	S32		text_clip_bottom,

	S32		gfx_clip_left,
	S32		gfx_clip_top,
	S32		gfx_clip_right,
	S32		gfx_clip_bottom,

	S32		current_handle,
	S32		active_handle
)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	int	 i;


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (MODIS_UI_layer_ptr == NULL)
	{
		MODIS_UI_layer_ptr = (MODIS_UI_layer_info_struct **)malloc(SIMULATOR_LAYER_COUNT * sizeof(MODIS_UI_layer_info_struct *));

		/* initialize pointer allocation for MODIS_UI_layer */
		for (i = 0; i < SIMULATOR_LAYER_COUNT; i++)
		{
			MODIS_UI_layer_ptr[i] = &MODIS_UI_layer[i];
		}
	}

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
} /* end of modis_ui_set_layer_data */



void lcd_fb_update_previous(int lcd_id)
{
	if(lcd_id == MAIN_LCD)
	{
		last_lcd_para[0].lcm_start_x = 0;
		last_lcd_para[0].lcm_start_y = 0;
		last_lcd_para[0].lcm_end_x = LCD_WIDTH;
		last_lcd_para[0].lcm_end_y = LCD_HEIGHT;
		last_lcd_para[0].roi_offset_x = 0+LCD_WIDTH;
		last_lcd_para[0].roi_offset_y = 0+LCD_HEIGHT;
		lcd_fb_update(&last_lcd_para[0]);
	}
	else
		lcd_fb_update(&last_lcd_para[1]);
}


/*****************************************************************************
* FUNCTION
*  resume_lcd_layer_rotate
* DESCRIPTION
*  resume lcd layer rotation
*
* PARAMETERS
*	void
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void resume_lcd_layer_rotate(void)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of resume_lcd_layer_rotate */


/*****************************************************************************
* FUNCTION
*  set_lcd_layer_roate
* DESCRIPTION
*  set lcd layer rotation
*
* PARAMETERS
*	rotate_layer	IN		the layer for rotating
*	rotate_value	IN		the rotation value
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void set_lcd_layer_roate(kal_uint32 rotate_layer, kal_uint8 rotate_value)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/


} /* end of set_lcd_layer_roate */
#ifdef __MMI_TOUCH_SCREEN__

#include "assert.h"

extern void mmi_pen_MODIS_enqueue_down(kal_int16 x, kal_int16 y);
extern void mmi_pen_MODIS_enqueue_move(kal_int16 x, kal_int16 y);
extern void mmi_pen_MODIS_enqueue_up(kal_int16 x, kal_int16 y);

static int w32_touch_screen_mouse_down;

static void w32_touch_screen_get_point_mapping(int *x, int *y,int xNewScrnSize,int yNewScrnSize)
{
	POINT point;
	
	GetCursorPos(&point);

	ScreenToClient(device.hwnd, &point);
	
	*x = (point.x - lcd_offset_x)*LCD_WIDTH/xNewScrnSize;
	*y = (point.y - lcd_offset_y)*LCD_HEIGHT/yNewScrnSize;
	kal_printf("X=%d, Y= %d\n", point.x,point.y);
	kal_printf("lcd_offsetX=%d, Y= %d\n", lcd_offset_x,lcd_offset_y);
	kal_printf("xNewScrnSize=%d, yNewScrnSize= %d\n", xNewScrnSize,yNewScrnSize);
	kal_printf("mapping X=%d, Y= %d\n", *x,*y);
}
static void w32_touch_screen_get_point(int *x, int *y)
{
	POINT point;
	GetCursorPos(&point);
	kal_printf("X=%d, Y= %d\n", point.x,point.y);
	ScreenToClient(device.hwnd, &point);

	*x = point.x - lcd_offset_x;
	*y = point.y - lcd_offset_y;
	kal_printf("minus lcd_offset X=%d, Y= %d\n", *x,*y);
}


BOOL w32_touch_screen_button_down(int xNewScrnSize, int yNewScrnSize)
{
	int x, y;
	assert(!w32_touch_screen_mouse_down);
	w32_touch_screen_get_point_mapping(&x, &y,xNewScrnSize,yNewScrnSize);

	if (x >= 0 && x < LCD_WIDTH && y >= 0 && y < LCD_HEIGHT)
	{
		mmi_pen_MODIS_enqueue_down((S16)x, (S16)y);
		w32_touch_screen_mouse_down = 1;
		SetCapture(device.hwnd);
		return 1;
	}
	else
	{
		return 0;
	}
}

BOOL w32_touch_screen_button_move(int xNewScrnSize, int yNewScrnSize)
{
	int x, y;

	if (w32_touch_screen_mouse_down)
	{
		//w32_touch_screen_get_point(&x, &y);
		w32_touch_screen_get_point_mapping(&x, &y,xNewScrnSize,yNewScrnSize);
		mmi_pen_MODIS_enqueue_move((S16)x, (S16)y);
		return 1;
	}
	else
	{
		return 0;
	}
}

BOOL w32_touch_screen_button_up(int xNewScrnSize, int yNewScrnSize)
{
	int x, y;

	if (w32_touch_screen_mouse_down)
	{
		//w32_touch_screen_get_point(&x, &y);
		w32_touch_screen_get_point_mapping(&x, &y,xNewScrnSize,yNewScrnSize);
		mmi_pen_MODIS_enqueue_up((S16)x, (S16)y);
		w32_touch_screen_mouse_down = 0;
		ReleaseCapture();
		return 1;
	}
	else
	{
		return 0;
	}
}

#else /* __MMI_TOUCH_SCREEN__ */

BOOL w32_touch_screen_button_down(void)
{
	return FALSE;
}

BOOL w32_touch_screen_button_move(void)
{
	return FALSE;
}

BOOL w32_touch_screen_button_up(void)
{
	return FALSE;
}

#endif /* __MMI_TOUCH_SCREEN__ */

#if defined(MT6205B)
kal_uint32 get_lcd_frame_buffer_address(void){}
#endif


/*****************************************************************************
* FUNCTION
*  mouse_mouse
* DESCRIPTION
*  mouse move enable
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void mouse_move(HWND hWnd, int xPos, int yPos,int xNewScrnSize, int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (!w32_touch_screen_button_move(xNewScrnSize, yNewScrnSize))
	{
		w32_mouse_move_enable(hWnd, xPos, yPos,xNewScrnSize, yNewScrnSize);
	}
} /* end of mouse_mouse */


/*****************************************************************************
* FUNCTION
*  mouse_lbutton_up
* DESCRIPTION
*  function for mouse button up
*
* PARAMETERS
*	hWnd			IN		window handle
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void mouse_lbutton_up(HWND hWnd,int wParam,int xNewScrnSize, int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (!w32_touch_screen_button_up(xNewScrnSize, yNewScrnSize))
	{
		w32_keyup_by_mouse(hWnd,wParam,xNewScrnSize, yNewScrnSize);//0 mean nothing, just default
	}
} /* end of mouse_lbutton_up */


/*****************************************************************************
* FUNCTION
*  mouse_lbutton_down
* DESCRIPTION
*  function for mouse button down
*
* PARAMETERS
*	hWnd			IN		window handle
*	xPos			IN		X position
*	yPos			IN		Y position
* RETURNS
*  void
* GLOBALS AFFECTED
*  void
*****************************************************************************/
void mouse_lbutton_down(HWND hWnd, int xPos, int yPos, int xNewScrnSize, int yNewScrnSize)
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	if (!w32_touch_screen_button_down(xNewScrnSize,yNewScrnSize))
	{
		w32_keydown_by_mouse(hWnd, xPos, yPos,xNewScrnSize,yNewScrnSize);
	}
} /* end of mouse_lbutton_down */


/*****************************************************************************
 * FUNCTION
 *  get_mainlcd_hbitmap
 * DESCRIPTION
 *  Allocate a BITMAP object and save the main lcd content to it
 * PARAMETERS
 *  void
 * RETURNS
 *  HBITMAP
 *****************************************************************************/
HBITMAP get_mainlcd_hbitmap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    HBITMAP hb;
    HDC tempdc, hdc;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hdc	= GetDC(device.hwnd);
    tempdc = CreateCompatibleDC(hdc);
    hb = CreateCompatibleBitmap(hdc, skin_lcd_width, skin_lcd_height);
    SelectObject(tempdc, hb);

    BitBlt(
        tempdc, 
        0,
        0,
        skin_lcd_width,
        skin_lcd_height,
        lcd_hdcMem, 
        0, 
        0, 
        SRCCOPY);

    ReleaseDC(device.hwnd, hdc);
    ReleaseDC(device.hwnd, tempdc);

    return hb;
}
