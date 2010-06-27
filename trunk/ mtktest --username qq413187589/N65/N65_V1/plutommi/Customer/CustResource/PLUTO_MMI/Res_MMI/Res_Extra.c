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
 * Res_Extra.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Populate Resource for Extra. 
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
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif
#include "MMI_features.h"

#include "ExtraResDef.h"

#if defined(__MMI_BMI__)
#include "bmiResDef.h"
#endif
#if defined(__MMI_CALORIE__)
/* under construction !*/
#endif
#if defined(__MMI_MENSTRUAL__)
#include "HealthemnstrurealResDef.h"
#endif
#if defined(__MMI_DICTIONARY__)
#include "DictionaryResDef.h"
#endif

#if defined(__MMI_CURRENCY_CONVERTER__)
#include "CurrencyConvertorResDef.h"
#elif defined(__MMI_EXTENDED_CURRENCY_CONVERTER__)
#include "CurrencyConvertorEResDef.h"
#endif

#if defined(__MMI_UNIT_CONVERTER__) || defined	(__MMI_EXTENDED_UNIT_CONVERTER__)
#include "UnitconvertorResDef.h"
#endif

#if defined(__MMI_CALCULATOR__)
#include "CalculatorResDef.h"
#endif
#if defined(__MMI_EBOOK_READER__)
#include "EbookResDef.h"
#include "FileManagerResDef.h"
#endif 

#ifndef __DISABLE_SHORTCUTS_MENU__
#include "ShortcutsResDef.h"
#endif


#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"
#include "CustResDef.h"

// Health Enum
typedef enum
{
#if defined(__MMI_BMI__)
	HALETH_ENUM_BMI,
#endif

#if defined(__MMI_MENSTRUAL__)
	HALETH_ENUM_MENSTRUAL,
#endif

#if defined(__MMI_CALORIE__)
/* under construction !*/
#endif
	HALETH_ENUM_TOTAL
} HealthMenu;

#if defined(__MMI_CALCULATOR__)

void PopulateCalculator(void)
{
	ADD_APPLICATION_STRING2(STR_ID_CALC_MENU,"Calculator","To Go to Calculator Screen.");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MENU_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\SB_OCACU.PBM","Icon for Calculator Options Menu.");

#if defined(__MMI_VERSION_2__)
		ADD_APPLICATION_MENUITEM((EXTRA_CALCULATOR_MENU,MAIN_MENU_EXTRA_MENUID,0,SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
			STR_ID_CALC_MENU,IMG_ID_CALC_MENU_ICON));
#else
	ADD_APPLICATION_MENUITEM((EXTRA_CALCULATOR_MENU,MAIN_MENU_ORGANIZER_MENUID,0,SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
		STR_ID_CALC_MENU,IMG_ID_CALC_MENU_ICON));
#endif
	
#ifndef __MMI_TOUCH_CALCULATOR__
#ifdef __MMI_SLIM_CALCULATOR__
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_PLUS,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\PLUS.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MINUS,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\SUBTRACT.bmp","DIVIDE BMP");	
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MULTIPLY,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\MULTI.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_DIVIDE,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\DIVIDE.bmp","DIVIDE BMP");	
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_EQUAL,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\EQUAL.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MAIN,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Slim\\\\MAP.bmp","DIVIDE BMP");
#else
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_PLUS,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\PLUS.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MINUS,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\SUBTRACT.bmp","DIVIDE BMP");	
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MULTIPLY,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\MULTI.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_DIVIDE,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\DIVIDE.bmp","DIVIDE BMP");	
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_EQUAL,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\EQUAL.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MAIN,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\MAP.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MP,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\MP.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MM,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Mm.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MC,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\MC.bmp","DIVIDE BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_CALC_MR,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\MR.bmp","DIVIDE BMP");
#endif	
#else
//#ifdef __MMI_TOUCH_CALCULATOR__
       /*shaokai modify bmp to gif.start  090813*/
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MAIN,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_MAIN.gif","MAIN TOUCH CALC BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY0,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY0.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY1,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY1.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY2,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY2.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY3,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY3.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY4,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY4.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY5,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY5.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY6,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY6.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY7,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY7.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY8,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY8.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY9,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_KEY9.gif","TOUCH CALC KEY BMP");

	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY_DOT,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_DOT.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_KEY_EQUAL,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_EQUAL.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_PLUS,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_PLUS.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MINUS,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_SUBTRACT.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MULTIPLY,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_MULTI.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_DIVIDE,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_DIV.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MP,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_MP.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MM,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_MM.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MC,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_MC.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_MR,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\TH_CALC_MR.gif","TOUCH CALC KEY BMP");
	ADD_APPLICATION_IMAGE2(IMG_ID_TOUCH_CALC_TITLE,CUST_IMG_PATH"\\\\MainLCD\\\\Calculator\\\\Touch\\\\CALC_TITLE.gif","TOUCH CALC KEY BMP");
	/*shaokai modify bmp to gif.end  090813*/
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  PopulateEbook
 * DESCRIPTION
 *  To populate the Ebook Resources
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined (__MMI_EBOOK_READER__)
void PopulateEbook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ADD_APPLICATION_STRING2(STR_OPEN_CARD_DRV, "Card Memory", "Bookshelf Screen");
    ADD_APPLICATION_STRING2(STR_OPEN_PRIVATE_DRV, "Phone Memory", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(EBOOK_TITLE_BOOKSHELF, "Bookshelf", "Bookshelf Screen");
    ADD_APPLICATION_STRING2(EBOOK_BKSLF_OPTION, "Bookshelf Options", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_REFRESH_EBOOK,"Clean Up bookshelf","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_OPEN_EBOOK, "Open E-Book", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_RENAME_BOOK_OPTIONS, "Rename", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_INFO_EBOOK, "Book Info", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_DELETE_EBOOK, "Delete E-Book", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_DELETE_ALL_EBOOK, "Delete All E-Books", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_RESTORE_DEFAULT, "Apply Settings", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_HELP_EBOOK, "Help", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_EBOOK, "Global Settings", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_DELETE_INQUIRE, "Delete ebook?", "Bookshelf Option Screen");

	
	ADD_APPLICATION_STRING2(STR_EBOOK_MEMORY_LESS,"Not Enough Memory","Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_EBOOK_LIST_LSK_EDIT,"Edit","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_BOOK_MARK_NAME_IS_EMPTY, "Empty Bookmark", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_CONFIRM_SAVE_SETTINGS, "Do you want to save the settings?", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_NO_BOOK_MARK_PRESENT, "Bookmark Name list is Empty", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_EBOOK_FORMAT_NOT_SUPPORTED,"Internal Pdb File Format Is invalid","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_SEARCH_UN_SUCESSFULL, "Searched string not found", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_ERROR_OPENINIG_BOOK, "Error Occured While Opening the Book", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_ADD_TO_BOOK_SHELF,"This book is not added in bookshelf.Add Now?","Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_ADD_TO_EBOOK_FOLDER,"Book not present in Ebook Folder, do you want to move and open?","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_OPEN_BOOK_ERROR, "Error Occured While Opening the File", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_STYLE, "Font Style", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_SIZE, "Font Size", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_SCROLL_BY, "Scroll By", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL, "Auto Scroll", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_SPEED, "Scroll Speed", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FULL_SCREEN, "Full Screen", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_ENCODING_FORMAT, "Encoding Format", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_STYLE_BOLD, "Bold", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_STYLE_ITALIC, "Italic", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_STYLE_NORMAL, "Normal", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_SIZE_LARGE, "Large", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_SIZE_SMALL, "Small", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FONT_SIZE_MEDIUM, "Medium", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_SCROLL_BY_PAGE, "Page", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_SCROLL_BY_LINE, "Line", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_ON, "On", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_OFF, "Off", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FULL_SCREEN_ON, "On", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_FULL_SCREEN_OFF, "Off", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_SPEED_1, "1", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_SPEED_2, "2", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_SPEED_3, "3", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_SPEED_4, "4", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_AUTO_SCROLL_SPEED_5, "5", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_SELECT_MEMORY, "Select Memory", "Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_EBOOK_WAIT, "Ebook: Please Wait!", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_WAIT_FOR_MOVING_FILE, "Ebook: Moving file ", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SUCESSFULL_RESTORE_DEFAULT, "Settings Applied", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_UNSUCESSFULL_RESTORE_DEFAULT,"Error Occured while Restoring the default settings.","Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_SETTINGS_PHONE_MEMORY, "Phone Memory", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SETTINGS_CARD_MEMORY, "Card Memory", "Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_DELETED, "Bookmark deleted", "Bookmark deleted");
    ADD_APPLICATION_STRING2(STR_MAX_BOOK_MARK, "Maximum Number of Bookmarks Added", "Deleted");
	ADD_APPLICATION_STRING2(STR_EBOOK_TOUCH_SCREEN_HELP,"How to Use Shortcuts\n\nUse Key 0 to Go to Book Settings Screen.\n\nUse Key 1 for Help.\n\nUse Key 2 to Add a Bookmark.\n\nUse Key 3 to Go to Find Screen.\n\nUse Key 4 to Go to Jump To Screen.\n\nUse Key 5 to Go to Bookmark.\n\nUse Key 6 for Find Next.\n\nUse Key 7 to Toggle the Auto Scroll.\n\nUse Key 8 to Remove Bookmark.\n\nUse Key 9 to Toggle Full Screen Mode","Ebook Help Description");
	 ADD_APPLICATION_STRING2(STR_INCOMPLETE_SEARCH_STRING, "Search String is Incomplte", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_FIND_EBOOK, "Find", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_FIND_NEXT_EBOOK, "Find Next", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_JUMP_EBOOK, "Jump To", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_GOTO_BOOKMARK_EBOOK, "Go To Bookmark", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_ADD_BOOKMARK_EBOOK, "Add Bookmark", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_RMV_BOOKMARK_EBOOK, "Delete Bookmark", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_BOOK_INFO_EBOOK, "Book Info", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_BOOK_SETTINGS_EBOOK, "Settings", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_CLOSE_EBOOK, "Close", "Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_FULL_SCREEN_OFF, "Full Screen Off", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_FULL_SCREEN_ON, "Full Screen On", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_AUTO_SCROLL_ON, "Auto Scroll On", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_AUTO_SCROLL_OFF, "Auto Scroll Off", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_WAIT_STRING, "Please Wait", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(EBOOK_DRIVE_SELECT_TYPE, "Select Drive", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SRCH_CASE_EBOOK, "Case Sensitive", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_SRCH_CASEIN_EBOOK, "Case Insensitive", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_JMP_BEG_EBOOK, "Beginning", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_JMP_MID_EBOOK, "Middle", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_JMP_END_EBOOK, "End", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_JMP_PERCENTAGE_EBOOK, "Enter Percentage", "Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_USB_IS_PLUGGED_IN,"Usb Plugged in","Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_EBOOK_BOOK_INFO_TITLE,"Title:","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_BOOK_INFO_SIZE,"Size:","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_BOOK_INFO_FORMAT,"Format :","Bookshelf Option Screen");


	//ADD_APPLICATION_STRING2(STR_CHANGE_CARD_TO_PHONE,"Do you want the default memory location to be changed from card to phone?","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_CHANGE_CARD_TO_PHONE,"Change E-Book Bookshelf location from card to phone?","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_CHANGE_PHONE_TO_CARD,"Change E-Book Bookshelf location from phone to card?","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_MEMORY_TYPE_CHANGED, "Memory Type Changed", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_RESTORE_DEFAULT_SETTINGS, "Apply Global Settings?", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_DELETE_ALL_EBOOK_CONFIRM, "Delete All E-Books?", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_PERCENTAGE_SCREEN, "Enter Percentage", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_DELETE_EBOOK_CONFIRM, "Delete E-Book?", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_DUPLICATE_BOOK_MARK,"Overwrite the previous bookmark with the same name?","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_OPEN_BOOK_OPTION, "Open Book Options", "Bookshelf Option Screen");

    ADD_APPLICATION_STRING2(STR_BOOK_TOO_SMALL, "Book size too small", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_WRONG_PERCENTAGE_VALUE,"Percentage entered must be in the Range 1-100","Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_DELETE_BOOK_MARK, "Delete the Bookmark?", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_BOOKMARK_ADDED, "Bookmark Added", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_DEFAULT_BOOKMARK, "Bookmark ", "Default Bookmark name");
    ADD_APPLICATION_STRING2(STR_BOOK_SHELF_REFRESHED, "Bookshelf Cleaned", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_EBOOK_SEARCH_INVALID, "Incorrect Encoding", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING(MAIN_MENU_EBOOK_TEXT, "E-Book Reader");

	ADD_APPLICATION_IMAGE2(MAIN_MENU_EBOOK_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\SubMenu\\\\Ebook\\\\EbookAppIcon.pbm","Icon for Ebook Reader Application.");
	ADD_APPLICATION_IMAGE2(IMAGE_EBOOK_WAIT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\progress\\\\progress"__MMI_RES_TYPE_POPUP_SCREEN__, "Image Diaplayed in Please Wait Screen");
    /*
	ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BOOKSHELF,IDLE_SCREEN_MENU_ID,0,
			SHOW, MOVEABLEWITHINPARENT, DISP_LIST,MAIN_MENU_EBOOK_TEXT,IMG_GLOBAL_OPTIONS));
     */
    ADD_APPLICATION_MENUITEM((MAIN_MENU_EBOOK_MENUID, MAIN_MENU_EXTRA_MENUID, 0,
                              SHOW, MOVEABLEWITHINPARENT | INSERTABLE, DISP_LIST | SHORTCUTABLE,
                              MAIN_MENU_EBOOK_TEXT, MAIN_MENU_EBOOK_ICON));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BOOKSHELF_OPTION, 0, 9,
                              MENU_ID_EBK_OPEN,
                              MENU_ID_EBK_RFS_OPTION,
                              MENU_ID_EBK_SETTINGS,
                              MENU_ID_EBK_INFO,
                              MENU_ID_EBK_DELETE,
                              MENU_ID_EBK_DELETE_ALL,
							  MENU_FMGR_GEN_OPTION_SORT,
                              MENU_ID_EBK_RESTORE_DEFAULT,
                              MENU_ID_EBK_HELP,
                              SHOW, MOVEABLEWITHINPARENT | INSERTABLE, DISP_LIST,
                              MAIN_MENU_EBOOK_TEXT, MAIN_MENU_EBOOK_ICON));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION, 0, 2,
                              MENU_ID_EBK_RFS_OPTION_LIMITED,
                              MENU_ID_EBK_SETTINGS_LIMITED,
                              SHOW, MOVEABLEWITHINPARENT | INSERTABLE, DISP_LIST,
                              MAIN_MENU_EBOOK_TEXT, MAIN_MENU_EBOOK_ICON));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_RFS_OPTION, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_REFRESH_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_DELETE_ALL, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_DELETE_ALL_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_RESTORE_DEFAULT, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_RESTORE_DEFAULT, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_RFS_OPTION_LIMITED, MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_REFRESH_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_SETTINGS_LIMITED, MENU_ID_EBK_LIMITED_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SETTINGS_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_OPEN, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));
#ifdef __MMI_BPP_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_OPEN_OPTIONS, 0, 11,
                              MENU_ID_EBK_FIND,
                              MENU_ID_EBK_JUMP,
                              MENU_ID_EBK_GOTO_BOOKMARK,
                              MENU_ID_EBK_ADD_BOOKMARK,
                              MENU_ID_EBK_REMOVE_BOOKMARK,
                              MENU_ID_EBK_BOOK_INFO,
                              MENU_ID_EBK_BOOK_SETTINGS,
                              MENU_ID_EBK_BOOK_RESTORE_DEFAULT,
                              MENU_ID_EBK_BPP_PRINT,
                              MENU_ID_EBK_HELP,
                              MENU_ID_EBK_CLOSE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));
#else
    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_OPEN_OPTIONS, 0, 10,
                              MENU_ID_EBK_FIND,
                              MENU_ID_EBK_JUMP,
                              MENU_ID_EBK_GOTO_BOOKMARK,
                              MENU_ID_EBK_ADD_BOOKMARK,
                              MENU_ID_EBK_REMOVE_BOOKMARK,
                              MENU_ID_EBK_BOOK_INFO,
                              MENU_ID_EBK_BOOK_SETTINGS,
                              MENU_ID_EBK_BOOK_RESTORE_DEFAULT,
                              MENU_ID_EBK_HELP,
                              MENU_ID_EBK_CLOSE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));
#endif

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_REDUCED_OPEN_OPTIONS_1, 0, 9,
                              MENU_ID_EBK_FIND,
                              MENU_ID_EBK_GOTO_BOOKMARK,
                              MENU_ID_EBK_ADD_BOOKMARK,
                              MENU_ID_EBK_REMOVE_BOOKMARK,
                              MENU_ID_EBK_BOOK_INFO,
                              MENU_ID_EBK_BOOK_SETTINGS,
                              MENU_ID_EBK_BOOK_RESTORE_DEFAULT,
                              MENU_ID_EBK_HELP,
                              MENU_ID_EBK_CLOSE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_REDUCED_OPEN_OPTIONS, 0, 10,
                              MENU_ID_EBK_FIND,
                              MENU_ID_EBK_FIND_NEXT,
                              MENU_ID_EBK_GOTO_BOOKMARK,
                              MENU_ID_EBK_ADD_BOOKMARK,
                              MENU_ID_EBK_REMOVE_BOOKMARK,
                              MENU_ID_EBK_BOOK_INFO,
                              MENU_ID_EBK_BOOK_SETTINGS,
                              MENU_ID_EBK_BOOK_RESTORE_DEFAULT,
                              MENU_ID_EBK_HELP,
                              MENU_ID_EBK_CLOSE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_EBOOK_EDIT_BOOK_MARK_NAME, 0, 2,
                              MENU_ID_EBK_DONE_BOOK_MARK,
                              MENU_ID_EBK_INPUT_METHOD_BOOK_MARK,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FIND_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_DONE_BOOK_MARK, MENU_EBOOK_EDIT_BOOK_MARK_NAME, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_EBOOK_DONE, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_INPUT_METHOD_BOOK_MARK, MENU_EBOOK_EDIT_BOOK_MARK_NAME, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_INPUT_METHOD, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_STRING2(STR_EBOOK_DONE, "Done", "Bookshelf Option Screen");
    ADD_APPLICATION_STRING2(STR_EBOOK_INPUT_METHOD, "Input Method", "Bookshelf Option Screen");

#ifdef __MMI_BPP_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_OPEN_OPTIONS_1, 0, 12,
                              MENU_ID_EBK_FIND,
                              MENU_ID_EBK_FIND_NEXT,
                              MENU_ID_EBK_JUMP,
                              MENU_ID_EBK_GOTO_BOOKMARK,
                              MENU_ID_EBK_ADD_BOOKMARK,
                              MENU_ID_EBK_REMOVE_BOOKMARK,
                              MENU_ID_EBK_BOOK_INFO,
                              MENU_ID_EBK_BOOK_SETTINGS,
                              MENU_ID_EBK_BOOK_RESTORE_DEFAULT,
                              MENU_ID_EBK_BPP_PRINT,
                              MENU_ID_EBK_HELP,
                              MENU_ID_EBK_CLOSE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));
#else
    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_OPEN_OPTIONS_1, 0, 11,
                              MENU_ID_EBK_FIND,
                              MENU_ID_EBK_FIND_NEXT,
                              MENU_ID_EBK_JUMP,
                              MENU_ID_EBK_GOTO_BOOKMARK,
                              MENU_ID_EBK_ADD_BOOKMARK,
                              MENU_ID_EBK_REMOVE_BOOKMARK,
                              MENU_ID_EBK_BOOK_INFO,
                              MENU_ID_EBK_BOOK_SETTINGS,
                              MENU_ID_EBK_BOOK_RESTORE_DEFAULT,
                              MENU_ID_EBK_HELP,
                              MENU_ID_EBK_CLOSE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_OPEN_EBOOK, IMG_GLOBAL_OPTIONS));
#endif

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_FIND, MENU_ID_EBK_OPEN_OPTIONS, 2,
                              MENU_ID_EBK_CASE_SENSITIVE,
                              MENU_ID_EBK_CASE_INSENSITIVE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FIND_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_FIND_NEXT, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FIND_NEXT_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_CASE_SENSITIVE, MENU_ID_EBK_FIND, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SRCH_CASE_EBOOK, IMG_GLOBAL_OPTIONS));
#ifdef __MMI_BPP_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BPP_PRINT, MENU_ID_EBK_FIND, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_EBOOK_BPP_PRINT, IMG_GLOBAL_OPTIONS));
    ADD_APPLICATION_STRING2(STR_EBOOK_BPP_PRINT, "Print", "BPP Print");
#endif

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BOOK_RESTORE_DEFAULT, MENU_ID_EBK_FIND, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_RESTORE_DEFAULT, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_CASE_INSENSITIVE, MENU_ID_EBK_FIND, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SRCH_CASEIN_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_JUMP, MENU_ID_EBK_OPEN_OPTIONS, 4,
                              MENU_ID_EBK_BEGINNING,
                              MENU_ID_EBK_MIDDLE,
                              MENU_ID_EBK_END,
                              MENU_ID_EBK_PERCENTAGE,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_JUMP_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BEGINNING, MENU_ID_EBK_JUMP, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_JMP_BEG_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_MIDDLE, MENU_ID_EBK_JUMP, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_JMP_MID_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_END, MENU_ID_EBK_JUMP, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_JMP_END_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_PERCENTAGE, MENU_ID_EBK_JUMP, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_JMP_PERCENTAGE_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_GOTO_BOOKMARK, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GOTO_BOOKMARK_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_ADD_BOOKMARK, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ADD_BOOKMARK_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_REMOVE_BOOKMARK, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_RMV_BOOKMARK_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BOOK_INFO, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_BOOK_INFO_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_BOOK_SETTINGS, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_BOOK_SETTINGS_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_CLOSE, MENU_ID_EBK_OPEN_OPTIONS, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_CLOSE_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_INFO, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_INFO_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_DELETE, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_DELETE_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_HELP, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_HELP_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_MENUITEM((MENU_ID_EBK_SETTINGS, MENU_ID_EBK_BOOKSHELF_OPTION, 0,
                              SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_SETTINGS_EBOOK, IMG_GLOBAL_OPTIONS));

    ADD_APPLICATION_STRING2(STR_SETTINGS_ENCODING_FORMAT_UCS2, "UCS2(Unicode)", "Bookshelf Option Screen");
	ADD_APPLICATION_STRING2(STR_SETTINGS_ENCODING_FORMAT_UTF8, "UTF8", "Bookshelf Option Screen");

#ifdef __MMI_CHSET_BIG5__
    ADD_APPLICATION_STRING2(STR_SETTINGS_ENCODING_FORMAT_BIG5, "BIG5(Traditional Chienese)", "Bookshelf Option Screen");
#endif 

#ifdef __MMI_CHSET_GB2312__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_GB2312,
        "GB2312(Simplified Chienese)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_GB2312__ */ 

#ifdef __MMI_CHSET_TURKISH_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_TURKISH_ISO,
        "TURKISH ISO(Turkish International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_TURKISH_ISO__ */ 

#ifdef __MMI_CHSET_TURKISH_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_TURKISH_WIN,
        "TURKISH WIN(Turkish Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_TURKISH_WIN__ */ 
#ifdef __MMI_CHSET_BALTIC_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_BALTIC_ISO,
        "BALTIC ISO(Baltic International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_BALTIC_ISO__ */ 
#ifdef __MMI_CHSET_BALTIC_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_BALTIC_WIN,
        "BALTIC WIN(Baltic Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_BALTIC_WIN__ */ 
#ifdef __MMI_CHSET_CEURO_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_CUEURO_ISO,
        "EURO ISO(Euro International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_CEURO_ISO__ */ 
#ifdef __MMI_CHSET_CEURO_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_CUEURO_WIN,
        "EURO WIN(Euro Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_CEURO_WIN__ */ 
#ifdef __MMI_CHSET_GREEK_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_GREEK_ISO,
        "GREEK ISO(Euro International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_GREEK_ISO__ */ 
#ifdef __MMI_CHSET_GREEK_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_GREEK_WIN,
        "GREEK WIN(Euro Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_GREEK_WIN__ */ 
#ifdef __MMI_CHSET_HEBREW_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_HEBREW_ISO,
        "HEBREW ISO(Hebrew International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_HEBREW_ISO__ */ 
#ifdef __MMI_CHSET_LATIN_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_LATIN_ISO,
        "LATIN ISO(Latin International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_LATIN_ISO__ */ 
#ifdef __MMI_CHSET_NORDIC_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_NORDIC_ISO,
        "NORDIC ISO(Nordic International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_NORDIC_ISO__ */ 
#ifdef __MMI_CHSET_SEURO_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_SEURO_ISO,
        "SEURO ISO(Seuro International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_SEURO_ISO__ */ 
#ifdef __MMI_CHSET_WESTERN_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_WESTERN_ISO,
        "WESTERN ISO(Western International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_WESTERN_ISO__ */ 
#ifdef __MMI_CHSET_WESTERN_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_WESTERN_WIN,
        "ASCII(Western Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_WESTERN_WIN__ */ 
#ifdef __MMI_CHSET_ARABIC_ISO__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_ARABIC_ISO,
        "ARABIC ISO(Arabic International)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_ARABIC_ISO__ */ 
#ifdef __MMI_CHSET_ARABIC_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_ARABIC_WIN,
        "ARABIC WIN(Arabic Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_ARABIC_WIN__ */ 
#ifdef __MMI_CHSET_HEBREW_WIN__
    ADD_APPLICATION_STRING2(
        STR_SETTINGS_ENCODING_FORMAT_HEBREW_WIN,
        "HEBREW WIN(Hebrew Windows)",
        "Bookshelf Option Screen");
#endif /* __MMI_CHSET_HEBREW_WIN__ */ 

}

#endif /* defined (__MMI_EBOOK_READER__) */ 
#if defined(__MMI_CALORIE__)
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
#endif //#if defined(__MMI_CALORIE__)


#if defined(__MMI_MENSTRUAL__)
/***********************************************************************

	FUNCTION NAME		: PopulateHealthMensisRes(void)

  	PURPOSE				: Populate Menu for Health Mensis Application

	INPUT PARAMETERS	: nil

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

************************************************************************/
void PopulateHealthMensisRes(void)
{
	ADD_APPLICATION_STRING2(EXTRA_HEALTH_MENU_MENSTRUAL_STRINGID,"Menstrual","Health->Menstrual");
	ADD_APPLICATION_MENUITEM((EXTRA_HEALTH_MENU_MENSTRUAL,EXTRA_HEALTH_MENU,0,
		SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
		EXTRA_HEALTH_MENU_MENSTRUAL_STRINGID,0));
	
	ADD_APPLICATION_STRING2(STR_HEALTH_MENSIS_DATE_CAPTION,"Input", "Input Menstrual Health screen title");
	ADD_APPLICATION_STRING2(STR_SCR_HEALTH_MENSIS_CAPTION,"Menstrual", "Health Menstrual screen title");

	ADD_APPLICATION_STRING2(STR_SCR_HEALTH_MENSIS_PROBABILITY_CAPTION,"Pregnancy", "Pregnancy Probability caption");

	ADD_APPLICATION_STRING2(STR_SCR_HEALTH_MENSIS_PROBABILITY_MESSAGE,"Today's Probability", "Today's Probability");

	ADD_APPLICATION_STRING2(STR_LAST_DATE,"Last Mens Date", "Health Menstrual screen last date");
	ADD_APPLICATION_STRING2(STR_DATE_FORMAT_HEALTH_MENSIS,"(Days)", "Date format Health Screen Mensis");

	ADD_APPLICATION_STRING2(STR_INVALID_AVERAGE_DAY_MESSAGE,"Days: 14 ~ 99", "Invalid avg days message in Health Screen Mensis");

	ADD_APPLICATION_STRING2(STR_CANNOT_NAVIGATE_FURTHER_MESSAGE,"Out of Boundary","Sorry You Cannot Navigate Further Message");

	ADD_APPLICATION_STRING2(STR_AVERAGE_DAYS_HEALTH_MENSIS,"Average Period", "Average Period Days Health Screen Mensis");




	ADD_APPLICATION_STRING2(STR_CALENDER_MESSAAGE1_PP,"P.P", "Menses Calender message 1");
#ifndef __MMI_CLNDR_SMALL_SIZE_SCREEN__
	ADD_APPLICATION_STRING2(STR_CALENDER_MESSAAGE2_MENS,"Menses", "Menses Calender message 2");
#else	
    ADD_APPLICATION_STRING2(STR_CALENDER_MESSAAGE2_SHORT_MENS,"Mens.", "Menses Calender message 2");
#endif

	ADD_APPLICATION_STRING2(STR_HEALTH_WRONG_DATE_MSG,"Enter Correct Date"," Notification Msg for wrong date in health mestural.");

	ADD_APPLICATION_IMAGE2(IMG_SCR_HEALTH_MENSIS,CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_MENS.BMP","Health screen title image");	

#ifdef __MMI_CALENDAR_V2__
        ADD_APPLICATION_IMAGE2(IMG_HEALTH_MENSIS_PP,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\PP.pbm","PP color");	

        ADD_APPLICATION_IMAGE2(IMG_HEALTH_MENSIS_MENSES,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\icon\\\\MENS.pbm","Menses color");	
#endif /*__MMI_CALENDAR_V2__*/ 
}
#endif // #if defined(__MMI_MENSTRUAL__)

#if defined(__MMI_BMI__)
/**************************************************************

	FUNCTION NAME		: PopulateBMIData

  	PURPOSE				: 

	INPUT PARAMETERS	: void 

	OUTPUT PARAMETERS	: nil

	RETURNS				: void

	REMARKS				: 

**************************************************************/
void PopulateBMIData()
{
	ADD_APPLICATION_STRING2(EXTRA_HEALTH_MENU_BMI_STRINGID,"BMI","Health->BMI");
	ADD_APPLICATION_MENUITEM((EXTRA_HEALTH_MENU_BMI,EXTRA_HEALTH_MENU,0,
		SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
		EXTRA_HEALTH_MENU_BMI_STRINGID,0));
	
	ADD_APPLICATION_IMAGE2(IMG_BMI_WELCOME_SCREEN,CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_BMI.bmp","BMI welcome image");

	ADD_APPLICATION_IMAGE2(IMG_BMI_RED_FLOWER,CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_RF.bmp","red flower image");
	ADD_APPLICATION_IMAGE2(IMG_BMI_BLUE_FLOWER,CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\H_BF.bmp","Blue flower image");

	ADD_APPLICATION_STRING2(STR_BMI_WELCOME_CAPTION,"BMI", "BMI Welcome title");
	ADD_APPLICATION_STRING2(STR_BMI_INPUT_CAPTION,"Input", "BMI Input title");
	ADD_APPLICATION_STRING2(STR_BMI_RESULT_CAPTION,"BMI Result", "BMI Result title");

	ADD_APPLICATION_STRING2(STR_BMI_MALE_TEXT,"Male", "Male Gender");
	ADD_APPLICATION_STRING2(STR_BMI_FEMALE_TEXT,"Female", "Female Gender");
	ADD_APPLICATION_STRING2(STR_BMI_HEIGHT_TEXT,"Height (Cm)", "Height");
	ADD_APPLICATION_STRING2(STR_BMI_WEIGHT_TEXT,"Weight (Kg)", "Weight");

	ADD_APPLICATION_STRING2(STR_BMI_HEIGHT_ERROR_TEXT,"Height: 30 ~ 300", "Height");
	ADD_APPLICATION_STRING2(STR_BMI_WEIGHT_ERROR_TEXT,"Weight: 1 ~ 300", "Weight");
	ADD_APPLICATION_STRING2(STR_BMI_HEIGHT_WEIGHT_ERROR,"Height: 30 ~ 300 \nWeight: 1 ~ 300 ", "Height & Weight error");
	
	ADD_APPLICATION_STRING2(STR_BMI_BMI_TEXT,"BMI :", "BMI text ");
	ADD_APPLICATION_STRING2(STR_BMI_NORMAL,"Normal", "BMI Normal");
	ADD_APPLICATION_STRING2(STR_BMI_FAT,"Fat", "BMI Fat ");
	ADD_APPLICATION_STRING2(STR_BMI_THIN,"Thin", "BMI Thin ");

}
#endif //#if defined(__MMI_BMI__)

#if defined (__MMI_CURRENCY_CONVERTER__) || defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)

void PopulateCurrencyConvertor(void)
{	
	ADD_APPLICATION_IMAGE2(EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID,CUST_IMG_PATH"\\\\MainLCD\\\\Currency\\\\SB_OCUR.PBM","Icon for Currency Convertor Menu.");
	ADD_APPLICATION_STRING2(EXTRA_MENU_CURRENCYCONVERTOR_STRINGID,"Currency Converter","To Go to Currency Convertor Screen.");
	
	#if defined(__MMI_VERSION_2__)
		ADD_APPLICATION_MENUITEM((EXTRA_CURRENCYCONVERTOR_MENU,MAIN_MENU_EXTRA_MENUID,0,SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
			EXTRA_MENU_CURRENCYCONVERTOR_STRINGID,EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID));
	#else
	ADD_APPLICATION_MENUITEM((EXTRA_CURRENCYCONVERTOR_MENU,MAIN_MENU_ORGANIZER_MENUID,0,SHOW,MOVEABLEACROSSPARENT|SHORTCUTABLE,DISP_LIST,
		EXTRA_MENU_CURRENCYCONVERTOR_STRINGID,EXTRA_MENU_CURRENCYCONVERTOR_IMAGEID));
	#endif

       ADD_APPLICATION_STRING2(STR_ID_CURRENCYCONVERTOR_RESET,"Reset","Reset Input Text");
        
#if defined (__MMI_CURRENCY_CONVERTER__)
	ADD_APPLICATION_STRING2(STR_CURRENCYCONVERTOR_RATEINPUT,"Rate Input","Title for CC.");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONVERTOR_RATE,"Rate","Rate.");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONVERTOR_INPUT,"Input Currency","Input Currency");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONVERTOR_LOCAL,"Local","Local");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONVERTOR_FOREIGN,"Foreign","Foreign");

	ADD_APPLICATION_STRING2(ERROR_CURRENCYCONVERTOR_RATE1,"Wrong Entry","error1");

	ADD_APPLICATION_IMAGE2(CURRENCY_CONVERTOR_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\Currency\\\\C_RATE.bmp","currency convertor image");
#else
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_RATEINPUT,"Rate Input","Title for CC.");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_RATE,"Rate","Rate.");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_INPUT,"Input Currency","Input Currency");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_LOCAL,"Local","Local");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_FOREIGN,"Foreign","Foreign");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_USD,"USD (US Dollars)","USD");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_EUR,"EUR (Euro)","EUR");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_RUB,"RUB (Russia Rubles)","RUB");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_JPY,"JPY (Japanese Yen)","JPY");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_GBP,"GBP (UK Pounds)","GBP");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_HKD,"HKD (Hong Kong Dollar)","HKD");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_CUSTOM1,"Custom1","Custom1");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_CUSTOM2,"Custom2","Custom2");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_CUSTOM3,"Custom3","Custom3");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_USD_ABBR,"USD","USD");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_EUR_ABBR,"EUR","EUR");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_RUB_ABBR,"RUB","RUB");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_JPY_ABBR,"JPY","JPY");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_GBP_ABBR,"GBP","GBP");
	ADD_APPLICATION_STRING2(STR_CURRENCYCONV_HKD_ABBR,"HKD","HKD");

	ADD_APPLICATION_STRING2(ERROR_CURRENCYCONV_RATE1,"Wrong Entry","error1");
	ADD_APPLICATION_STRING2(ERROR_CURRENCYCONV_RATE2,"Enter exchange rates now?", "No exchange rate is defined.");

	ADD_APPLICATION_IMAGE2(CURRENCY_CONVERTOR_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\Currency\\\\C_RATE.bmp","currency convertor image");
#endif
}
#endif

#if defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__)
void PopulateUnitConvertor()
{

	ADD_APPLICATION_IMAGE2(EXTRA_MENU_UNITSCONVERTOR_IMAGEID,CUST_IMG_PATH"\\\\MainLCD\\\\UnitsConverter\\\\SB_OUNIT.PBM","Icon for Calculator Units Converter.");
	ADD_APPLICATION_STRING2(EXTRA_MENU_UNITSCONVERTOR_STRINGID,"Units Converter","To Go to Units Converter Screen.");

 #ifdef __MMI_EXTENDED_UNIT_CONVERTER__
	#if defined(__MMI_VERSION_2__)
	ADD_APPLICATION_MENUITEM((EXTRA_UNITCONVERTOR_MENU,MAIN_MENU_EXTRA_MENUID,8,		
		EXTRA_UNITCONVERTOR_WEIGHT,
		EXTRA_UNITCONVERTOR_LENGTH,
		MENU_ID_EXTRA_UNITCONVERTOR_VOLUME,
		MENU_ID_EXTRA_UNITCONVERTOR_TEMPERATURE,
		MENU_ID_EXTRA_UNITCONVERTOR_VELOCITY,
		MENU_ID_EXTRA_UNITCONVERTOR_SHOEW,		
		MENU_ID_EXTRA_UNITCONVERTOR_CLOTHES,
		MENU_ID_EXTRA_UNITCONVERTOR_SURFACE,		
		SHOW,MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE,DISP_LIST,
		EXTRA_MENU_UNITSCONVERTOR_STRINGID,EXTRA_MENU_UNITSCONVERTOR_IMAGEID));
	
	#else
	ADD_APPLICATION_MENUITEM((EXTRA_UNITCONVERTOR_MENU,MAIN_MENU_ORGANIZER_MENUID,8,
		EXTRA_UNITCONVERTOR_WEIGHT,
		EXTRA_UNITCONVERTOR_LENGTH,
		MENU_ID_EXTRA_UNITCONVERTOR_VOLUME,
		MENU_ID_EXTRA_UNITCONVERTOR_TEMPERATURE,
		MENU_ID_EXTRA_UNITCONVERTOR_VELOCITY,
		MENU_ID_EXTRA_UNITCONVERTOR_SHOEW,		
		MENU_ID_EXTRA_UNITCONVERTOR_CLOTHES,
		MENU_ID_EXTRA_UNITCONVERTOR_SURFACE,		
		SHOW,MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE,DISP_LIST,
		EXTRA_MENU_UNITSCONVERTOR_STRINGID,EXTRA_MENU_UNITSCONVERTOR_IMAGEID));	
	#endif
 #else 
	#if defined(__MMI_VERSION_2__)
	ADD_APPLICATION_MENUITEM((EXTRA_UNITCONVERTOR_MENU,MAIN_MENU_EXTRA_MENUID,2,
		EXTRA_UNITCONVERTOR_WEIGHT,
		EXTRA_UNITCONVERTOR_LENGTH,SHOW,MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE,DISP_LIST,
		EXTRA_MENU_UNITSCONVERTOR_STRINGID,EXTRA_MENU_UNITSCONVERTOR_IMAGEID));
	
	#else
	ADD_APPLICATION_MENUITEM((EXTRA_UNITCONVERTOR_MENU,MAIN_MENU_ORGANIZER_MENUID,2,
		EXTRA_UNITCONVERTOR_WEIGHT,
		EXTRA_UNITCONVERTOR_LENGTH,SHOW,MOVEABLEACROSSPARENT|INSERTABLE|SHORTCUTABLE,DISP_LIST,
		EXTRA_MENU_UNITSCONVERTOR_STRINGID,EXTRA_MENU_UNITSCONVERTOR_IMAGEID));
	#endif
 #endif
	
	ADD_APPLICATION_MENUITEM((EXTRA_UNITCONVERTOR_WEIGHT,EXTRA_UNITCONVERTOR_MENU,0,SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_UNITCONVERTOR_WEIGHT,0));
	ADD_APPLICATION_MENUITEM((EXTRA_UNITCONVERTOR_LENGTH,EXTRA_UNITCONVERTOR_MENU,0,SHOW,MOVEABLEWITHINPARENT,DISP_LIST,STR_UNITCONVERTOR_LENGTH,0));

	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_WEIGHT,"Weight","weight");	
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_LENGTH,"Length","Length");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_CAPTION1,"Input","Input");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_RESET,"Reset","Reset Input Text");
	
#ifdef __MMI_EXTENDED_UNIT_CONVERTER__
	ADD_APPLICATION_MENUITEM((MENU_ID_EXTRA_UNITCONVERTOR_VOLUME,EXTRA_UNITCONVERTOR_MENU,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_UNITCONVERTOR_VOLUME,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EXTRA_UNITCONVERTOR_TEMPERATURE,EXTRA_UNITCONVERTOR_MENU,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_UNITCONVERTOR_TEMPERATURE,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EXTRA_UNITCONVERTOR_VELOCITY,EXTRA_UNITCONVERTOR_MENU,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_UNITCONVERTOR_VELOCITY,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EXTRA_UNITCONVERTOR_SHOEW,EXTRA_UNITCONVERTOR_MENU,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_UNITCONVERTOR_SHOES,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EXTRA_UNITCONVERTOR_CLOTHES,EXTRA_UNITCONVERTOR_MENU,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_UNITCONVERTOR_CLOTHES,0));
	ADD_APPLICATION_MENUITEM((MENU_ID_EXTRA_UNITCONVERTOR_SURFACE,EXTRA_UNITCONVERTOR_MENU,0,SHOW,NONMOVEABLE,DISP_LIST,STR_ID_UNITCONVERTOR_SURFACE,0));

	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_VOLUME,"Volume","Volume");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_MILLILITER,"Milliliter","Milliliter");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LITER,"Liter","Liter");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CUBICMM,"Cubic Mm","Cubic Mm");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CUBICCM,"Cubic Cm","Cubic Cm");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CUBICMETER,"Cubic Meter","Cubic Meter");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CUBICINCH,"Cubic Inch","Cubic Inch");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_GALLON,"Gallon","Gallon");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LIQPT,"Liq. Pt","Liquid Pint");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LIQOZ,"Liq. Oz","Liquid Ounce");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_FLOZ,"Fluid Oz","Fluid Ounce");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_BARREL,"Barrel","Barrel");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_TEMPERATURE,"Temperature","Temperature");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CELSIUS,"Celsius","Celsius");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_FAHRENHEIT,"Fahrenheit","Fahrenheit");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_VELOCITY,"Velocity","Velocity");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_KMH,"Km/H","KmPerHour");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_METERSEC,"Meter/S","MeterPerSecond");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_MPH,"Mile/H","MilePerHour");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_FEETSEC,"Feet/S","FeelPerSecond");

	ADD_APPLICATION_IMAGE2(IMG_ID_UNITCONVERTOR_RESET, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp","Reset RSK image");
	
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_MM,"MM","MM");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_CM,"CM","CM");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_M,"M","M");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_KM,"KM","KM");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_INCH,"Inch","Inch");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_FEET,"Feet","Feet");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_YARD,"Yard","Yard");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_LENGTH_MILES,"Miles","Miles");
	
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_WEIGHT_MG,"MG","MG");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_WEIGHT_G,"G","G");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_WEIGHT_KG,"KG","KG");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_WEIGHT_TON,"Ton","Ton");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_WEIGHT_OUNCE,"Ounce","Ounce");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_WEIGHT_POUND,"Pound","Pound");
	
	ADD_APPLICATION_STRING2(UC_ERROR_UNCORRECT_INPUT,"Incorrect Input","Incorrect Input");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SHOES,"Shoes","Shoes");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SHOES_USA,"USA","USA");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SHOES_EUROPE,"EUROPE","EUROPE");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SHOES_KOREA,"KOREA","KOREA");
	
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES,"Clothes","Clothes");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES_EUROPE,"Europe","Europe");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES_KOREA1,"Korea1","Korea1");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES_KOREA2,"Korea2","Korea2");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES_JAPAN,"JAPAN","JAPAN");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES_USA,"USA","USA");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_CLOTHES_UK,"UK","UK");
	
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE,"Surface","Surface");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_ACRE,"Acre","Acre");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_HECTARE,"Hectare","Hectare");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_IN,"Square Inch","Square Inch");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_FEET,"Square Feet","Square feet");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_YD,"Square Yard","Square yard");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_MILES,"Square Miles","Square miles");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_MM,"Square MM","Square MM");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_CM,"Square CM","Square CM");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_M,"Square M","Square M");
	ADD_APPLICATION_STRING2(STR_ID_UNITCONVERTOR_SURFACE_SQUARE_KM,"Square KM","Square KM");

#else 
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_KGPOUND,"Kg<-->Pound","kgtopound");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_KG,"Kg","kg");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_POUND,"Pound","Pound");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_KMMILE,"Km<-->Mile","KmtoMile");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_MYARD,"M<-->Yard","MtoYard");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_MFOOT,"M<-->Foot","MtoFoot");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_CMINCH,"Cm<-->Inch","CmToInch");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_KM,"Km","Km");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_MILE,"Mile","Mile");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_CM,"Cm","Cm");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_INCH,"Inch","Inch");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_METER,"Meter","Meter");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_YARD,"Yard","Yard");
	ADD_APPLICATION_STRING2(STR_UNITCONVERTOR_FOOT,"Foot","Foot");
	ADD_APPLICATION_STRING2(UC_ERROR_EMPTY_STRING,"Empty","Number is null");
	ADD_APPLICATION_STRING2(STR_UCONV_KGOUNCE,"Kg<-->Ounce","KG to Ounce");
	ADD_APPLICATION_STRING2(STR_UCONV_OUNCE,"Ounce","Ounce");

#endif
}
#endif

#ifndef __DISABLE_SHORTCUTS_MENU__
void PopulateShortcutsRes(void)
{
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_MENUID,0,7,
		EXTRA_SHORTCUTS_OPTION_ADD_MENUID,
		EXTRA_SHORTCUTS_OPTION_EDIT_MENUID,
		EXTRA_SHORTCUTS_OPTION_DELETE_MENUID,
		EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID,
		EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID,
		EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID,
		EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID,
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,
		STR_GLOBAL_OPTIONS,0));

	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_ADD_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,STR_GLOBAL_ADD,0));
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_EDIT_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,STR_GLOBAL_EDIT,0));
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_DELETE_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,STR_GLOBAL_DELETE,0));
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,STR_GLOBAL_DELETE_ALL,0));	
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_ENABLE_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,SHORTCUTS_ENABLE_STRING_ID,0));	
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_DISABLE_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,SHORTCUTS_DISABLE_STRING_ID,0));	
	ADD_APPLICATION_MENUITEM((EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID,EXTRA_SHORTCUTS_OPTION_MENUID,0,		
		SHOW,MOVEABLEWITHINPARENT|INSERTABLE,DISP_LIST,SHORTCUTS_CHANGE_ORDER_STRING_ID,0));	
	/* Resources for Shortcuts Screen */
	ADD_APPLICATION_STRING2(SHORTCUTS_TITLE_STRING_ID,"Shortcuts","Title displayed in Shortcuts Application.");

	ADD_APPLICATION_IMAGE2(SHORTCUTS_TITLE_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\TitleBar\\\\TB_SC.PNG","Icon for Title displayed in Shortcuts Application.");

	/* Resources for Options Screen */
	ADD_APPLICATION_IMAGE2(SHORTCUTS_OPTIONS_EDIT_IMAGE_ID,CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp","Image for Edit Button displayed in Shortcuts Screen Menu.");
	ADD_APPLICATION_STRING2(SHORTCUTS_HINT_STRING_ID,"Press UP key in IDLE to use","Hint message for shortcut");
	ADD_APPLICATION_STRING2(SHORTCUTS_ENABLE_STRING_ID,"Enable","Enable a shortcut item");
	ADD_APPLICATION_STRING2(SHORTCUTS_DISABLE_STRING_ID,"Disable","Disable a shortcut item");
	ADD_APPLICATION_STRING2(SHORTCUTS_DELETE_ASK_STRING_ID,"Delete this item?","Delete this item?");
	ADD_APPLICATION_STRING2(SHORTCUTS_DELETE_ALL_ASK_STRING_ID,"Delete all items?","Delete all item?");
	ADD_APPLICATION_STRING2(SHORTCUTS_FULL_MSG_STRING_ID,"Full","Message to User:- full Shortcut");
	ADD_APPLICATION_STRING2(SHORTCUTS_CHANGE_ORDER_STRING_ID,"Change Order","change shortcuts order");
    ADD_APPLICATION_STRING2(SHORTCUTS_NO_SIM_WARNING_ID,"No SIM","No SIM");
    ADD_APPLICATION_STRING2(SHORTCUTS_INVALID_SIM_WARNING_ID,"unavailable SIM","unavailable SIM");
    ADD_APPLICATION_STRING2(SHORTCUTS_INVALID_NO_IDLE_WARNING_ID,"No idle screen, function not allowed","No idle screen, function not allowed");
#ifdef __MMI_DUAL_SIM_MASTER__	   
        ADD_APPLICATION_STRING2(SHORTCUTS_NO_SIM1_WARNING_ID,"No SIM1","No SIM1");
       ADD_APPLICATION_STRING2(SHORTCUTS_INVALID_SIM1_WARNING_ID,"Invalid SIM1","Invalid SIM1");
        ADD_APPLICATION_STRING2(SHORTCUTS_NO_SIM2_WARNING_ID,"No SIM2","No SIM2");
       ADD_APPLICATION_STRING2(SHORTCUTS_INVALID_SIM2_WARNING_ID,"Invalid SIM2","Invalid SIM2");	   
	ADD_APPLICATION_STRING2(SHORTCUTS_SIM1_CLOSED_WARNING_ID,"SIM1 closed","SIM1 closed");
	ADD_APPLICATION_STRING2(SHORTCUTS_SIM2_CLOSED_WARNING_ID,"SIM2 closed","SIM2 closed");	
#endif	

}
#endif

void PopulateExtraRes(void)
{
	//ADD_APPLICATION_IMAGE2(ORGANIZER_TITLE_IMAGEID,CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_OR.PBM","Icon for Title of Organizer Screen.");
/* Menu item of Unit Converter */
#if defined (__MMI_UNIT_CONVERTER__) || defined (__MMI_EXTENDED_UNIT_CONVERTER__)
 PopulateUnitConvertor();
#endif

/* Menu item of Currency Converter */
#if defined (__MMI_CURRENCY_CONVERTER__) || defined (__MMI_EXTENDED_CURRENCY_CONVERTER__)
	PopulateCurrencyConvertor();
#endif

#if defined(__MMI_BMI__) || defined(__MMI_MENSTRUAL__) || defined(__MMI_CALORIE__)

	ADD_APPLICATION_IMAGE2(EXTRA_MENU_HEALTH_IMAGEID,CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\SB_HEAL.PBM","Icon for Health Menu.");
	ADD_APPLICATION_STRING2(EXTRA_MENU_HEALTH_STRINGID,"Health","To Go to Health Screen.");
	ADD_APPLICATION_STRING2(STR_SCR_HEALTH_CAPTION,"Health", "Health screen title");
	
	#if defined(__MMI_VERSION_2__)
		ADD_APPLICATION_MENUITEM((EXTRA_HEALTH_MENU,MAIN_MENU_EXTRA_MENUID,HALETH_ENUM_TOTAL,
		#if defined(__MMI_BMI__)
			EXTRA_HEALTH_MENU_BMI,
		#endif
		#if defined(__MMI_MENSTRUAL__)
			EXTRA_HEALTH_MENU_MENSTRUAL,
		#endif
		#if defined(__MMI_CALORIE__)
/* under construction !*/
		#endif
			SHOW,MOVEABLEACROSSPARENT,DISP_LIST,
			EXTRA_MENU_HEALTH_STRINGID,EXTRA_MENU_HEALTH_IMAGEID));
	#else
			ADD_APPLICATION_MENUITEM((EXTRA_HEALTH_MENU,MAIN_MENU_ORGANIZER_MENUID,HALETH_ENUM_TOTAL,
		#if defined(__MMI_BMI__)
			EXTRA_HEALTH_MENU_BMI,
		#endif
		#if defined(__MMI_MENSTRUAL__)
			EXTRA_HEALTH_MENU_MENSTRUAL,
		#endif
		#if defined(__MMI_CALORIE__)
/* under construction !*/
		#endif
			SHOW,MOVEABLEACROSSPARENT,DISP_LIST,
			EXTRA_MENU_HEALTH_STRINGID,EXTRA_MENU_HEALTH_IMAGEID));
	#endif
#endif

#if defined(__MMI_APHORISM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#if defined(__MMI_VERSION_2__)
/* under construction !*/
/* under construction !*/
		#else
/* under construction !*/
/* under construction !*/
		#endif
#endif
	//ADD_APPLICATION_STRING2(ORGANIZER_TITLE_STRINGID,"Organizer","Title of Organizer Screen.");

#ifdef __MMI_CALCULATOR__
	PopulateCalculator();
#endif
#if defined(__MMI_EBOOK_READER__)
    PopulateEbook();
#endif 
#if defined(__MMI_BMI__)
	PopulateBMIData();
#endif

#if defined(__MMI_MENSTRUAL__)
	PopulateHealthMensisRes();
#endif

#if defined(__MMI_CALORIE__)
/* under construction !*/
#endif
#ifndef __DISABLE_SHORTCUTS_MENU__
	PopulateShortcutsRes();
#endif
	#if defined(__MMI_DICTIONARY__)
		PopulateDictionaryData();
		ADD_APPLICATION_MENUITEM((EXTRA_DICTIONARY_MENU,MAIN_MENU_EXTRA_MENUID,0,SHOW,NONMOVEABLE,DISP_LIST,
				STR_DICTIONARY_TITLE,IMG_DICTIONARY_EXTRA_MENU_SCREEN));
		
		
	#endif
}
#endif