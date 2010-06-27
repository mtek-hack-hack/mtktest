/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsDisplay.h

功能描述		: 显示参数宏定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSDISPLAY_H
#define CMSDISPLAY_H

#ifdef __cplusplus 
extern "C" {
#endif
/************************************************************************
函数声明
	************************************************************************/
	int Cms_GetSCREEN_W( void );
	int Cms_GetSCREEN_H( void );
	int Cms_GetTITLEHIGHT( void );
	int Cms_GetSTATUSBAR_H( void );
	int Cms_GetORIGIN_X( void );
	int Cms_GetSELECTHIGHT( void );
	int Cms_GetSCROLLBAR_W( void );
	unsigned int Cms_GetCharacterWidth(unsigned char font,unsigned short Utf16);

#ifdef __cplusplus 
}
#endif

/********************** MARCOS（单位均为象素点） ****************************/

//#define		SCREEN_W			(Cms_GetSCREEN_W())//128					/*=== 显示屏宽度 ===*/
//#define		SCREEN_H			(Cms_GetSCREEN_H())//160					/*=== 显示屏高度 ===*/

//#define		SCROLLBAR_W			(Cms_GetSCROLLBAR_W())//4					/*=== 滚动条宽度 ===*/
//#define		STATUSBAR_W			SCREEN_W			/*=== 状态栏宽度 ===*/
//#define		STATUSBAR_H			(Cms_GetSTATUSBAR_H())//24					/*=== 状态栏高度 ===*/

//#define		CMS_TITLEHIGHT		(Cms_GetTITLEHIGHT())//20					/*=== 浏览器顶部标题栏高度 ===*/
//#define		CMS_SELECTHIGHT		(Cms_GetSELECTHIGHT())//24					/*=== 浏览器底部功能选择栏高度 ===*/

//#define		ORIGIN_X_D			(Cms_GetORIGIN_X())//4					/*=== 浏览器显示起始x坐标 ===*/
//#define		FONT_W				pBrowserInfo->font_w					/*=== 浏览器显示字体宽 ===*/

#define		SCREEN_W			pBrowserInfo->DisplayData->Display_Screen_W//128					/*=== 显示屏宽度 ===*/
#define		SCREEN_H			pBrowserInfo->DisplayData->Display_Screen_H//160					/*=== 显示屏高度 ===*/

#define		SCROLLBAR_W			pBrowserInfo->DisplayData->Display_Scrollbar_W//4					/*=== 滚动条宽度 ===*/
#define		STATUSBAR_W			pBrowserInfo->DisplayData->Display_Statusbar_W			/*=== 状态栏宽度 ===*/
#define		STATUSBAR_H			pBrowserInfo->DisplayData->Display_Statusbar_H//24					/*=== 状态栏高度 ===*/

#define		CMS_TITLEHIGHT		pBrowserInfo->DisplayData->Display_Title_H//20					/*=== 浏览器顶部标题栏高度 ===*/
#define		CMS_SELECTHIGHT		pBrowserInfo->DisplayData->Display_Select_H//24					/*=== 浏览器底部功能选择栏高度 ===*/

#define		ORIGIN_X_D			pBrowserInfo->DisplayData->Display_Origin_X_D//4					/*=== 浏览器显示起始x坐标 ===*/
#define		FONT_W				pBrowserInfo->DisplayData->Display_Font_W					/*=== 浏览器显示字体宽 ===*/


extern int  ORIGIN_X;
#define		ORIGIN_Y			(CMS_TITLEHIGHT)	/*=== 浏览器显示起始y坐标 ===*/
#define		CMSFONT				0					/*=== 浏览器显示字体 ===*/
#define		CMSFONT_HEIGHT		(FONT_W*2)			/*=== 浏览器显示字体高 ===*/
#define		LINE_HEIGHT			(CMSFONT_HEIGHT+6)	/*=== 浏览器显示行高 ===*//*20051101 cocoma xu modify for bug 27553*/
#define		PAGEDISPLAY_W		(SCREEN_W-ORIGIN_X-SCROLLBAR_W)		/*=== 浏览器显示区宽度 ===*/
#define		PAGEDISPLAY_H		(SCREEN_H-ORIGIN_Y-CMS_SELECTHIGHT)	/*=== 浏览器显示区高度 ===*/
//#define		PAGEDISPLAY_H		(SCREEN_H-ORIGIN_Y-CMS_SELECTHIGHT-7)	/*=== 浏览器显示区高度 ===*/

#define		PAGEMOVE_LINE		1									/* 浏览器翻页的时候所移动的行 */

#define		SCREEN_LINE			(PAGEDISPLAY_H/LINE_HEIGHT)			/*=== 浏览器单页显示的行 ===*/
#define		CHAR_W_NUM			(PAGEDISPLAY_W/FONT_W)				/*=== 浏览器单行显示的字符数 ===*/
#define		DISPLAY_BOTTOM		(SCREEN_H - CMS_SELECTHIGHT)		/* 显示区底部 */
#define		DISPLAY_RIGHT		(SCREEN_W -SCROLLBAR_W)				/* 显示区右部 */
#define		BOTTOM_Y_POS		(ORIGIN_Y +  PAGEDISPLAY_H)			/*=== 浏览器底线 ===*/

#define		TAB_W				2					/*=== 连接间隔，用于改善显示效果 ===*/
#define		CTRLRECHEIGHT		(CMSFONT_HEIGHT+LINE_HEIGHT)/2+1	/*=== 输入框高度 ===*/
#define		CTRLRECWIDTH		12								/*=== 输入框宽度===*/

#define		CHECKBOXIMG_WIDTH	9					/*=== CHECKBOX框宽度 ===*/
#define		CHECKBOXIMG_HEIGHT	12					/*=== CHECKBOX框高度 ===*/

#define		RADIOIMG_WIDTH		9					/*=== CHECKBOX框宽度 ===*/
#define		RADIOIMG_HEIGHT		9					/*=== CHECKBOX框高度 ===*/

#define		OPTIONIMG_WIDTH		14					/*=== CHECKBOX框宽度 ===*/
#define		OPTIONIMG_HEIGHT	16					/*=== CHECKBOX框高度 ===*/

#define		INPUT_W             74

#define		IMGERRIMG_WIDTH		16
#define		IMGERRIMG_HEIGHT	16

#define		SCROLLBAR_H			PAGEDISPLAY_H				/*=== 滚动条高度 ===*/
#define		SCROLLBAR_X			(SCREEN_W - SCROLLBAR_W)	/*=== 滚动条起始x坐标 ===*/
#define		SCROLLBAR_Y			PAGEDISPLAY_W				/*=== 滚动条起始y坐标 ===*/

#define		STATUSBAR_X			0							/*=== 状态栏起始x坐标 ===*/
#define		STATUSBAR_Y			(PAGEDISPLAY_H-STATUSBAR_H)	/*=== 状态栏起始y坐标 ===*/

#define		STATUSTEXT_X		(STATUSBAR_X+2)		/*=== 状态栏文本显示起始x坐标 ===*/
#define		STATUSTEXT_Y		(STATUSBAR_Y+1)		/*=== 状态栏文本显示起始y坐标 ===*/

#define		MOVE_WIDTH			10					/*table移动的宽度 */

#define COLOR_BLACLK    0x00000000
#define COLOR_WHITE     0x00ffffff
#define COLOR_RED       0x000000ff
#define COLOR_YELLOW    0x0000ffff
#define COLOR_LIME      0x0000ff00    
#define COLOR_AQUA      0x00ffff00
#define COLOR_BLUE      0x00ff0000
#define COLOR_FUCHSIA   0x00ff00ff
#define COLOR_GRAY      0x00808080
#define COLOR_SILVER    0x00c0c0c0
#define COLOR_MAROON    0x00000080
#define COLOR_OLIVE     0x00008080
#define COLOR_GREEN     0x00008000
#define COLOR_TEAL      0x00808000
#define COLOR_NAVY      0x00800000
#define COLOR_PURPLE    0x00800080

#endif
