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
 * Res_LangLn.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for populating resource of language learning.
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_LANGLN__)

#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */
#include "GlobalDefs.h"             /* for global string */

#include "LangLnResDef.h"


#ifdef __MMI_LANGLN_LK__
/*****************************************************************************
* FUNCTION
*  populateLanglnLKRes
* DESCRIPTION
*   Populate All resource data for Listening King
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
void populateLanglnLKRes(void)
{
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_BOOK_LIST_EMPTY, "Book list empty", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_BOOK_LIST_TITLE, "Book list", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_HELP_NO_SPEED, "Help", "Listening King help content without speed switch feature" );
    
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_ENTER_DICT, "Enter Dictionary", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SELECT_WORD, "Select word", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_CANCEL_SEL_WORD, "Cancel Select word", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SELECT_BOOK, "Select book", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SELECT_CHAPTER, "Select chapter", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_TIME_GO, "Seek to", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTINGS, "Setting", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_HELP, "Help", "Listening King String" );
    
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_TITLE, "Setting", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_LANG_SHOW, "Language types", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_IMAGE_SHOW, "Show image", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_REPEAT_TIMES, "Repeats", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_INTERVALS, "Interval seconds", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_WORD_HIDE, "Hide percentage", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_REPEAT_ALL, "Repeat all", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SETTING_VOLUME, "Volume", "Listening King String" );
    
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_LANG_SHOW_BOTH, "Both", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_LANG_SHOW_LOCAL, "Local", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_LANG_SHOW_FOREIGN, "Foreign", "Listening King String" );
    
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_WORD_HIDE_10P, "10%", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_WORD_HIDE_30P, "30%", "Listening King String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_WORD_HIDE_50P, "50%", "Listening King String" );

    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_TIME_GOTO_TITLE, "Seek to", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_TOTOL_DURATION, "Total duration:", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_MINUTE, "Minutes:", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_SECONDS, "Seconds:", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_TIPS_SOUND_RECORD_IDLE, "Sound record idle", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_TIPS_IS_RECORDING, "Is recording sound", "Listening King String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK_TIPS_PLAYING_SOUND, "Is playing sound", "Listening King String");
    
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_BUILDING_CACHE, "Building cache", "Listening King String");
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_DISC_FULL, "Disc Full", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_OPEN_FILE_ERROR, "Can't Open", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_CANNOT_PAUSE, "Can't Pause", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_COMMAND_ERROR, "Failed To Play", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_DEVICE_BUSY, "Device Busy", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_BAD_FORMAT, "Bad Format", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_INVALID_FORMAT, "Invalid Format", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_NO_SPACE, "Exceed File Limit", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_ERROR, "Audio Content Error", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_UNSUPPORTED_CHANNEL, "Unsupported Channel", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_UNSUPPORTED_FREQ, "Unsupported Frequency", "Listening King StringA" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_UNSUPPORTED_TYPE, "Unsupported Type", "Listening King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_HELP_DESCRIPTION,"How to use Shorcuts:\nUse Key 1 to Play.\nUse Key 2 to Stop.\nUse Key 3 to Set AB section.\nUse Key 4 to Repeat one setence.\nUse Key 5 to go to Look key word meaning.\nUse Key 6 to Switch mode between listen and speak.","Listening King");
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_LK_KEY_WORD_TITLE, "Key word", "Listening King String");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_BG.gif", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PLAY_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PLAY_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PLAY_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PLAY_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PAUSE_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PAUSE_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PAUSE_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PAUSE_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_RESND_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_RESND_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_RESND_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_RESND_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_RESNDING_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_RESNDING_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_RESNDING_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_RESNDING_DOWN.pbm", "Listening King image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_STOP_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_STOP_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_STOP_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_STOP_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PLAYSND_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PLAYSND_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PLAYSND_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PLAYSND_DOWN.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_NEXT_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_NEXT_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_NEXT_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_NEXT_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PRE_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PRE_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PRE_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PRE_DOWN.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_ABS_IDLE_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_ABS_IDLE_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_ABS_IDLE_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_ABS_IDLE_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_ABS_PARTIAL_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_ABS_PARTIAL_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_ABS_PARTIAL_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_ABS_PARTIAL_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_ABS_SET_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_ABS_SET_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_ABS_SET_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_ABS_SET_DOWN.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_INC_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_INC_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_INC_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_INC_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_INC_BTN_DIS, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_INC_DISABLE.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_DEC_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_DEC_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_DEC_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_DEC_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_DEC_BTN_DIS, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_DEC_DISABLE.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_SLOW2, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_SLOW2.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_SLOW1, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_SLOW1.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_NORMAL, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_NORMAL.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_FAST1, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_FAST1.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SPEED_FAST2, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEED_FAST2.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_CIRCULATE_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_CIRCULATE_IDLE_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_CIRCULATE_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_CIRCULATE_IDLE_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_CIRCULATE_ON_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_CIRCULATE_ON_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_CIRCULATE_ON_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_CIRCULATE_ON_DOWN.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_KEY_WORD_BTN_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_KEY_WORD_UP.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_KEY_WORD_BTN_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_KEY_WORD_DOWN.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_KEY_WORD_BTN_DIS, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_KEY_WORD_DISABLE.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_MODE_BTN_LISTEN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_LISTEN_MODE.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_MODE_BTN_SPEAK, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_SPEAK_MODE.pbm", "Listening King image");

    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_DURATION_TIME_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_TIME_AREA_BG.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PROGRESS_BAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PROGRESS_BAR_BG.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PROGRESS_BAR_RECT, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_PROGRESS_BAR_EMPTY_RECT.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_BTNS_DIS_AREA_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_BUTTONS_OTHER_DISABLE.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_SP_BTNS_DIS_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_BUTTONS_SP_DISABLE.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_PRE_NEXT_DIS_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_NEXT_PRE_DISABLE.pbm", "Listening King image");
    ADD_APPLICATION_IMAGE2(IMG_ID_LANGLN_LK_RECORD_INFO_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LK\\\\LANGLN_LK_RECORDINFO_AREA_BG.pbm", "Listening King image");

}
#endif /*__MMI_LANGLN_LK__*/


/*****************************************************************************
* FUNCTION
*  PopulateLangLnRes
* DESCRIPTION
*   Populate All resource data for language learning
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
void PopulateLangLnRes(void)
{
    /* resource ID check */
    if ((SCR_ID_LANGLN_END > LANGLN_BASE_MAX) ||
        (STR_ID_LANGLN_END > LANGLN_BASE_MAX) ||
        (IMG_ID_LANGLN_END > LANGLN_BASE_MAX))
    {
        RESOURCE_ID_OUT_OF_RANGE_HANDLER();
    }
    
    	/*Add Menu Items*/
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN, MAIN_MENU_EXTRA_MENUID, 
#ifdef __MMI_LANGLN_WK__
        MENU_ID_LANGLN_WK,
#endif
#ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_DK,
#endif
#ifdef __MMI_LANGLN_LK__
        MENU_ID_LANGLN_LK,
#endif
#ifdef __MMI_LANGLN_EK__
        MENU_ID_LANGLN_EK,
#endif
#ifdef __MMI_LANGLN_BK__
        MENU_ID_LANGLN_BK,
#endif
#ifdef __MMI_LANGLN_SK__
        MENU_ID_LANGLN_SK,
#endif
        MENU_ID_LANGLN_COURSEMGR,
        MENU_ID_LANGLN_ABOUT,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN, IMG_ID_LANGLN_APP));

#ifdef __MMI_LANGLN_WK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_WK, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK,0));
#endif

#ifdef __MMI_LANGLN_DK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_DK,0));
#endif

#ifdef __MMI_LANGLN_LK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_LK, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_LK,0));
#endif

#ifdef __MMI_LANGLN_EK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_EK, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK,0));
#endif

#ifdef __MMI_LANGLN_BK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BK, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_BK,0));
#endif

#ifdef __MMI_LANGLN_SK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_SK,0));
#endif

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_ABOUT, MENU_ID_LANGLN, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_ABOUT,0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_COURSEMGR, MENU_ID_LANGLN, 
        MENU_ID_LANGLN_COURSEMGR_UPDATE,
        MENU_ID_LANGLN_COURSEMGR_DOWNLOAD,
        MENU_ID_LANGLN_COURSEMGR_STORAGE,
#ifdef __MMI_LANGLN_WK__
        MENU_ID_LANGLN_COURSEMGR_WK,
#endif
#ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_COURSEMGR_DK,
#endif
#ifdef __MMI_LANGLN_LK__
        MENU_ID_LANGLN_COURSEMGR_LK,
#endif
#ifdef __MMI_LANGLN_EK__
        MENU_ID_LANGLN_COURSEMGR_EK,
#endif
#ifdef __MMI_LANGLN_BK__
        MENU_ID_LANGLN_COURSEMGR_BK,
#endif
#ifdef __MMI_LANGLN_SK__
        MENU_ID_LANGLN_COURSEMGR_SK,
#endif
#if defined(__MMI_LANGLN_WK__)||defined(__MMI_LANGLN_DK__)
        MENU_ID_LANGLN_COURSEMGR_WS,
#endif
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_COURSEMGR, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_UPDATE, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_UPDATE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DOWNLOAD, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_DOWNLOAD,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_STORAGE, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_STORAGE,0));

#ifdef __MMI_LANGLN_WK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_WK, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK,0));
#endif

#ifdef __MMI_LANGLN_DK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DK, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_DK,0));
#endif

#ifdef __MMI_LANGLN_LK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_LK, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_LK,0));
#endif

#ifdef __MMI_LANGLN_EK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_EK, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK,0));
#endif

#ifdef __MMI_LANGLN_BK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_BK, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_BK,0));
#endif

#ifdef __MMI_LANGLN_SK__
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_SK, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_SK,0));
#endif

#if defined(__MMI_LANGLN_WK__)||defined(__MMI_LANGLN_DK__)
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_WS, MENU_ID_LANGLN_COURSEMGR, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WS,0));
#endif

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_COURSEMGR_OPTION, 0, 
        MENU_ID_LANGLN_COURSEMGR_OPTION_REGISTER,
        MENU_ID_LANGLN_COURSEMGR_OPTION_DELETE,
        MENU_ID_LANGLN_COURSEMGR_OPTION_DELSEVERAL,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_OPTION_REGISTER, MENU_ID_LANGLN_COURSEMGR_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_REGISTER,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_OPTION_DELETE, MENU_ID_LANGLN_COURSEMGR_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_GLOBAL_DELETE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_OPTION_DELSEVERAL, MENU_ID_LANGLN_COURSEMGR_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_DEL_SEVERAL,0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_COURSEMGR_DEL_OPTION, 0, 
        MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_MARK,
        MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_UNMARK,
        MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_MARKALL,
        MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_UNMARKALL,
        MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_DELETE,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_MARK, MENU_ID_LANGLN_COURSEMGR_DEL_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_MARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_UNMARK, MENU_ID_LANGLN_COURSEMGR_DEL_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_UNMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_MARKALL, MENU_ID_LANGLN_COURSEMGR_DEL_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_MARKALL,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_UNMARKALL, MENU_ID_LANGLN_COURSEMGR_DEL_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_UNMARKALL,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_COURSEMGR_DEL_OPTION_DELETE, MENU_ID_LANGLN_COURSEMGR_DEL_OPTION, 0, SHOW, NONMOVEABLE, 0, STR_GLOBAL_DELETE,0));

	/*Add Strings*/
	ADD_APPLICATION_STRING2(STR_ID_LANGLN					,"EnglishTo"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK					,"Word King"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_DK					,"Dictionary King"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_LK					,"Listening King"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_EK					,"Exam King"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_BK					,"Ebook King"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_SK					,"Sentence King"				,"Language Learning App String");
  	ADD_APPLICATION_STRING2(STR_ID_LANGLN_WS					,"Sound"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_COURSEMGR					,"Course Manager"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_UPDATE					,"Update"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_DOWNLOAD					,"Download"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_STORAGE				,"Storage"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_UPDATE_MESSAGE					,"Updating, Please wait..."				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_DOWNLOAD_URL					,"wap.englishto.com"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_REGISTER					,"Register"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_DEL_SEVERAL					,"Delete Several"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_MARK					,"Mark"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_UNMARK					,"Unmark"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_MARKALL					,"Mark All"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_UNMARKALL					,"Unmark All"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_REGISTER_MESSAGE1					,"Please input register code,"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_REGISTER_MESSAGE2					,""				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_ABOUT					,"About"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_ABOUT_MESSAGE					,"EnglishTo v2.0\nCopyright2002-2006\nDigidea all rights reserved\nhttp://www.englishto.com "				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_CURRENT_MARKED                  ,"Marked Files"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_EMPTY_BOOK_LIST					,"Empty book list"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_FAILED_CONTINUE                          ,"failed, continue?"                     ,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_DELETE_FAILED_BACK                       ,"failed, back"   ,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_QUESTION                                 ,"?"  ,"Language Learning App String");
    /*error string*/
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_WRONG_TYPE                   ,"Wrong type"  ,    "Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_WRONG_VERSION                ,"Wrong version"  ,    "Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_WRONG_ENCODING               ,"Wrong encoding"  ,    "Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_MEMORY_NOT_ENOUGH            ,"No enough memory"  ,    "Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_INVALID_PARAM                ,"Invalid parameter",     "Language Learning App String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_RESERVED_ERROR               ,"Unknown error" ,    "Language Learning App String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_CRC_ERROR                    ,"CRC error", "Language Learning App String" );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_UNREGISTER                         ,"Unregistered","Language Learning App String"  );
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_POPUP_OPEN_COURSE_FAIL             ,"Open course failed", "Language Learning App String");

	/*Add Prompt String*/
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_REGISTER_CONFIRM					,"Unregistered! Register or not?"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_REGISTER_SUCCESS					,"Registered successfully"				,"Language Learning App String");
	ADD_APPLICATION_STRING2(STR_ID_LANGLN_REGISTER_FAILED					,"Registered failed"				,"Language Learning App String");

	/*Add Image*/
        ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_APP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SB_LANGLN.pbm" , "Icon used for language learning application" );
        ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_REG ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LANGLN_COURSE.pbm" , "Icon used for language learning application" );
        ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_UNREG ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\LANGLN_UNREG.pbm" , "Icon used for language learning application" );

#ifdef __MMI_LANGLN_BK__
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EBK ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_EBK.pbm" , "Icon used for language learning application" );
#endif

#ifdef __MMI_LANGLN_WK__
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_WK.pbm" , "Icon used for language learning application" );
#endif

#ifdef __MMI_LANGLN_EK__
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_EK.pbm" , "Icon used for language learning application" );
#endif

#ifdef __MMI_LANGLN_LK__
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_LK ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_LK.pbm" , "Icon used for language learning application" );
#endif

#ifdef __MMI_LANGLN_SK__
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_SK ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_SK.pbm" , "Icon used for language learning application" );
#endif

#ifdef __MMI_LANGLN_DK__
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_DK ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_DK.pbm" , "Icon used for language learning application" );
#endif

    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_CMANAGER ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_CMANAGER.pbm" , "Icon used for language learning application" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_ABOUT ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\SUB_ABOUT.pbm" , "Icon used for language learning application" );

	/*Populate other resources*/

#ifdef __MMI_LANGLN_WK__
    PopulateLangLnWKRes();
#endif

#ifdef __MMI_LANGLN_LK__
    populateLanglnLKRes();
#endif /*__MMI_LANGLN_LK__*/

#ifdef __MMI_LANGLN_DK__
    PopulateLangLnDKRes();
#endif

#ifdef __MMI_LANGLN_BK__ || __MMI_LANGLN_SK__
    PopulateLangLnBSKRes();
#endif
#ifdef __MMI_LANGLN_EK__
    PopulateLangLnEKRes();
#endif 
}


#ifdef __MMI_LANGLN_WK__
/*****************************************************************************
* FUNCTION
*  PopulateLangLnWKRes
* DESCRIPTION
*   Populate All resource data for language learning word king
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
void PopulateLangLnWKRes(void)
{
    /*Add Menu Items*/
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_OPTION, 0, 
        MENU_ID_LANGLN_WK_ENTER_DICTIONARY,
        MENU_ID_LANGLN_WK_SELECT_BOOK,
        MENU_ID_LANGLN_WK_SELECT_CONTENT,
        MENU_ID_LANGLN_WK_ADD_TO_NOTEBOOK,
        MENU_ID_LANGLN_WK_CLEAR_HISTORY,
        MENU_ID_LANGLN_WK_DELETE_NOTEBOOK,
        MENU_ID_LANGLN_WK_WORD_LIST,
        MENU_ID_LANGLN_WK_PROGRESS_STATUS,
#ifdef __MMI_LANGLN_WK_ALARM__
        MENU_ID_LANGLN_WK_REMINDER_SETTING,
#endif
        MENU_ID_LANGLN_WK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_ENTER_DICTIONARY, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END, 
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_ENTER_DICTIONARY, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_SELECT_BOOK, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END, 
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_SELECT_BOOK, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_SELECT_CONTENT, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ID_LANGLN_WK_TO_BE_LEARNED,
        MENU_ID_LANGLN_WK_TO_BE_REVIEWED,
        MENU_ID_LANGLN_WK_NOTEBOOK,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_SELECT_CONTENT, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_TO_BE_LEARNED, MENU_ID_LANGLN_WK_SELECT_CONTENT, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_TO_BE_LEARNED, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_TO_BE_REVIEWED, MENU_ID_LANGLN_WK_SELECT_CONTENT, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_TO_BE_REVIEWED, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_NOTEBOOK, MENU_ID_LANGLN_WK_SELECT_CONTENT, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_NOTEBOOK, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_ADD_TO_NOTEBOOK, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_ADD_TO_NOTEBOOK, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_CLEAR_HISTORY, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_CLEAR_HISTORY, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_DELETE_NOTEBOOK, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_DEL_FROM_NOTEBOOK, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_WORD_LIST, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ID_LANGLN_WK_WORDLIST_ALL,
        MENU_ID_LANGLN_WK_WORDLIST_TO_BE_LEARNED,
        MENU_ID_LANGLN_WK_WORDLIST_TO_BE_REVIEWED,
        MENU_ID_LANGLN_WK_WORDLIST_NOTEBOOK,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_WORD_LIST, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_WORDLIST_ALL, MENU_ID_LANGLN_WK_WORD_LIST, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_ALL, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_WORDLIST_TO_BE_LEARNED, MENU_ID_LANGLN_WK_WORD_LIST, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_TO_BE_LEARNED, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_WORDLIST_TO_BE_REVIEWED, MENU_ID_LANGLN_WK_WORD_LIST, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_TO_BE_REVIEWED, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_WORDLIST_NOTEBOOK, MENU_ID_LANGLN_WK_WORD_LIST, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_NOTEBOOK, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_PROGRESS_STATUS, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_PROGRESS_STATUS, 0));
    
#ifdef __MMI_LANGLN_WK_ALARM__
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_REMINDER_SETTING, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_SETTING, 0));
#endif 
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_WK_HELP, MENU_ID_LANGLN_WK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_WK_HELP, 0));


    /* Add Strings */
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_ENTER_DICTIONARY					,"Enter Dictionary"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_SELECT_BOOK					,"Select Book"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_SELECT_CONTENT					,"Select Content"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_ADD_TO_NOTEBOOK	,"Add To Notebook"	,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_DEL_FROM_NOTEBOOK	,"Delete From Notebook"	,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_CLEAR_HISTORY,     "Clear history"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_WORD_LIST					,"Word List"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_PROGRESS_STATUS					,"Progress Status"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_SETTING					,"Setting"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_HELP					,"Help"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_TO_BE_LEARNED					,"To Be Learned"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_TO_BE_REVIEWED					,"To Be Reviewed"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_NOTEBOOK					,"Notebook"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_ALL					,"All"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_HELP_MESSAGE1					,"User guide\nNote: The bottom icons mapping the keys of the number top left corner on them.\nIn Word King system, there are three modes for learning one word. They are Learning, Review and Notebook.\n"	,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_HELP_MESSAGE2					,"The five stages, Scan, FN (foreign to native) learning, NF (native to foreign) learning, FN test and NF test, are all appeared under each mode.\n\"Scan\" stage\nKey 1: Next word\n"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_HELP_MESSAGE3					,"Key 5: Cursor mode/Reading mode\nKey 6: Speaker\nThe first screen of \"FN learning\" and \"NF learning\" stages\nKey 1: Show Answers\nThe second screen of \"FN learning\" and \"NF learning\" stages\n"		                                                    ,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_HELP_MESSAGE4					,"Key 1~6: Forgotten, Dim, Remembered, Easy, Cursor mode/Reading mode, Speaker\n\"FN test\" and \"NF test\" stages\nKey 1~4: A~D\nKey 6: Speaker."				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_REVIEW_CONFIRM					,"There is words to be reviewed. Review it or not?"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_CLEAR_HISTORY_CONFIRM	,"Abort learning, clean history or not?"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_DELETE_NOTE	,"Delete?"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_END_OF_GROUP,"End of group!"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_REMINDER,"Reminder"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_REMINDER_TIME,"Time"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_ALARM_INDICATION,"It is time to review words."				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_ALARM_CONTINUE_CONFIRM,"It is time to check whether to review, continue?"				,"Language Learning App String");
    ADD_APPLICATION_STRING2(STR_ID_LANGLN_WK_NO_WORD_TO_REVIEW,"No words to review."				,"Language Learning App String");

    /* Add Images */
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_TOP_BG ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_WORD_BG.gif" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_INPUT_BG ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_CONTENT_BG.gif" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_PANEL_BG ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_BUTTON_BG.gif" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_CURSOR_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_CURSOR_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_CURSOR_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_CURSOR_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_CURSOR_DISABLE,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_CURSOR_DISABLE.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_NEXT_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_NEXT_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_NEXT_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_NEXT_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_A_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_A_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_A_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_A_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_B_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_B_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_B_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_B_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_C_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_C_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_C_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_C_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_D_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_D_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_D_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_D_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_FORGOTTEN_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_FORGOTTEN_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_FORGOTTEN_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_FORGOTTEN_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_DIM_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_DIM_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_DIM_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_DIM_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_REMEMBER_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_REMEMBERED_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_REMEMBER_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_REMEMBERED_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_EASY_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_EASY_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_EASY_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_EASY_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_SPEAKER_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_SPEAKER_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_SPEAKER_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_SPEAKER_DOWN.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_SPEAKER_DISABLE ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_SPEAKER_DISABLE.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_SHOWKEY_UP ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_SHOWKEY_UP.pbm" , "Icon used for language learning word king top area background" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_WK_SHOWKEY_DOWN ,	CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\WK\\\\LANGLN_WK_SHOWKEY_DOWN.pbm" , "Icon used for language learning word king top area background" );
}
#endif


#ifdef __MMI_LANGLN_DK__
/*****************************************************************************
* FUNCTION
*  PopulateLangLnDKRes
* DESCRIPTION
*   Populate All resource data for language learning dictionary king
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
PopulateLangLnDKRes()
{
    /* string for DK */
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SHOW_MEANING, "Show Meaning","show meaning menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SELECT_DICTIONARY, "Select Dictionary","select dictionary menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SELECT_SOUND, "Select Sound", "select sound courseware in dictioanry");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SETTING, "Setting","setting menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_HELP, "Help","help menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_INPUT_METHOD, "Input Method","input method menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_HELP_TEXT1, "Help Text1","help text1");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_HELP_TEXT2, "Help Text2","help text2");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_HELP_TEXT3, "Help Text3","help text3");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_HELP_TEXT4, "Help Text4","help text4");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SELECT_COURSE_EMPTY, "No Select Course","no select course");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SPEAK_MODE, "Speak Mode","speak mode");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_AUTO_SPEAK, "Auto Speaking","help text");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_MANUAL_SPEAK, "Manual Speaking","help text");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_VOLUME, "Volume","volume");    
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_MAX_COURSE_SELECT, "Over Max Num","over the course num can be selected");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_NO_MATCH_FOUND, "No Match Found","no match found");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_EXAMPLE_SENTENCE, "Example Sentence:","no match found");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_SYNONYMY, "Synonymy:","no match found");
    ADD_APPLICATION_STRING2(STR_LANGLN_DK_ANTONYM, "Antonym:","no match found");

     /* Image for DK */
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_DK_SPEAKER, CUST_IMG_PATH"\\\\MainLCD\\\\langln\\\\DK\\\\LANGLN_DK_SPEAKER.pbm","langln_dk speaker image");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_DK_WORD_LSIT, CUST_IMG_PATH"\\\\MainLCD\\\\langln\\\\DK\\\\LANGLN_DK_WORDLIST.pbm","langln_dk word list menu image");

     /* menu for DK */
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_OPTION, 0, 6,
        MENU_ID_LANGLN_DK_SHOW_MEANING,
        MENU_ID_LANGLN_DK_SELECT_DICTIONARY,
        MENU_ID_LANGLN_DK_SELECT_SOUND,
        MENU_ID_LANGLN_DK_SETTING,
        MENU_ID_LANGLN_DK_HELP,
        MENU_ID_LANGLN_DK_INPUT_METHOD,
        SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_SETTING, MENU_ID_LANGLN_DK_OPTION, 2,
        MENU_ID_LANGLN_DK_AUTO_SPEAK,
        MENU_ID_LANGLN_DK_MANUAL_SPEAK,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_SETTING,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_SHOW_MEANING, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_SHOW_MEANING,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_SELECT_DICTIONARY, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_SELECT_DICTIONARY,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_SELECT_SOUND, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_SELECT_SOUND,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_SETTING, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_SETTING,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_HELP, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_HELP,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_INPUT_METHOD, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_INPUT_METHOD,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_AUTO_SPEAK, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_AUTO_SPEAK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_DK_MANUAL_SPEAK, MENU_ID_LANGLN_DK_OPTION,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_DK_MANUAL_SPEAK,0));

}
#endif


#if defined(__MMI_LANGLN_BK__) || defined (__MMI_LANGLN_SK__)
/*****************************************************************************
* FUNCTION
*  PopulateLangLnBSKRes
* DESCRIPTION
*   Populate All resource data for language learning EBook&Sentence king
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
PopulateLangLnBSKRes()
{
    /* string for BSK */
    ADD_APPLICATION_STRING2(STR_LANGLN_SK_SPEAK, "Speak Sentence", "language learning speak menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_SK_AUTO_SPEAK, "Auto Speak", "sentence king speak setting caption");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_NO_HIGHLIGHT, "No Pick Word", "no pick word in change to cursor mode");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_ENTER_DICT, "Enter Dictionary", "enter dictionary menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_SELECT_BOOK, "Select Book", "select book menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_SELECT_FILE, "Select File", "select file menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_BOOKMARK, "Book Mark", "book mark menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_AUTO_ROLL, "Auto Roll", "start roll menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_TEXT_END, "End Of Text", "end of the text in change to auto roll");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_ADD_BOOKMARK, "Add BookMark", "add book mark menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_SEARCH_WORD, "Search", "search menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_GOTO_PERCENT, "Go To Percent", "go to percent menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_INPUT_PERCENT, "Please Input Percent", "go to percent menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_CURSOR_MODE, "Cursor Mode", "cursor mode menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_SETTING, "Setting", "setting menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_HELP, "Help", "help menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_GOTO_MARK, "Go To", "book mark go to menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_DEL_MARK, "Delete", "book mark delete menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_DELALL_MARK, "Delete All", "book mark delete all menu item");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_CONTENT_LANG, "Content Language", "conten langguage");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_LANG_BOTH, "Both", "content both English and Chinese");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_LANG_ENGONLY, "Foreign Only", "content foreign language only");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_LANG_CHNONLY, "Chinese Only", "content Chinese language only");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FORMAT, "Format", "screen format");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FORMAT_NORMAL, "Normal", "screen format normal");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FORMAT_FULL, "Full Screen", "screen format full screen");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FORMAT_LFULL, "Left Full Screen", "screen format left full screen");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FORMAT_RFULL, "Right Full Screen", "screen format right full screen");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_ROLL_SPEED, "Roll Speed", "roll speed");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_ROLL_FAST, "Fast", "roll speed fast");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_ROLL_MEDIUM, "Medium", "roll speed medium");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_ROLL_SLOW, "Slow", "roll speed slow");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_VOLUME, "Volume", "volume");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FONT_SIZE, "Font Size", "font size");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FONT_BIG, "Big", "font size big");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FONT_MEDINUM, "Medium", "font size medium");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FONT_SMALL, "Small", "font size small");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FOREN_COLOR, "Foreign Text Color", "foreign text color");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_CHN_COLOR, "Chinese Text Color", "chinese text color");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_PROG_LINE_COLOR, "Progress Line Color", "progress line color");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_BG_COLOR, "Background Color", "back ground color");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_BG_PICTURE, "Background Picture","background picture" );
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_SELECT_BG_PICTURE, "Select Background Picture", "select background picture");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_STATE_HINT, "State Hint", "state hint");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_HELP_TEXT1, "Help Text1", "help text");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_HELP_TEXT2, "Help Text2", "help text");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_HELP_TEXT3, "Help Text3", "help text");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_HELP_TEXT4, "Help Text4", "help text");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_GOTO_WARNING, "Warning", "warning text");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_EMPTY_BOOKMARK, "Empty BookMark", "book mark is empty");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_FULL_BOOKMARK, "BookMark Is Full", "book mark is full");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_NOTSUPPORT_SEARCH, "Not Support", "search is not support in novel");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_NO_FOUND, "No Found", "search nothing");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_OPEN_FAIL, "Empty Book List", "Empty Book List");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_NO_HL_WORD, "No Select Word", "no highlight word");
    ADD_APPLICATION_STRING2(STR_LANGLN_BSK_WRONG_NUM, "Wrong Number", "wrong number");

     /* Image for BSK */
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_BSK_BOOKMARK, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_BOOKMARK.pbm","Dictionary extra menu image");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_BSK_WORD_LIST, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_SENTENCE.pbm", "search word list icon");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_BSK_CHAPTER, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_CHAPTER.pbm","Dictionary extra menu image");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_SK_LAYER, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_LAYER.pbm","Dictionary extra menu image");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_BSK_STATE_BAR_NORMAL, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_WINDOW_TIMEBAR.gif","normal state bar");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_BSK_STATE_BAR_FULL, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_FULLSCR_TIMEBAR.gif","full screen state bar");
    ADD_APPLICATION_IMAGE2(IMG_LANGLN_BSK_STATE_BAR_ROTATE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\BSK\\\\LANGLN_EBK_VERTICAL_timebar.gif","rotate state bar");


    /* menu for SK*/
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_SK_OPTION_1, 0,
    #ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_BSK_ENTER_DICT,
    #endif
        MENU_ID_LANGLN_SK_SELECT_BOOK,
        MENU_ID_LANGLN_SK_SELECT_FILE, 
        MENU_ID_LANGLN_BSK_BOOKMARK,
        MENU_ID_LANGLN_BSK_AUTO_ROLL,
        MENU_ID_LANGLN_BSK_ADD_BOOKMARK,
        MENU_ID_LANGLN_BSK_SEARCH_WORD,
        MENU_ID_LANGLN_BSK_GOTO_PERCENT,
    #ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_BSK_CURSOR_MODE,
    #endif
        MENU_ID_LANGLN_SK_SETTING,
        MENU_ID_LANGLN_BSK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,0));

    /*read mode*/   
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_SK_OPTION_2, 0,
        MENU_ID_LANGLN_SK_SPEAK,
        MENU_ID_LANGLN_SK_SELECT_BOOK,
        MENU_ID_LANGLN_SK_SELECT_FILE, 
        MENU_ID_LANGLN_BSK_BOOKMARK,
        MENU_ID_LANGLN_BSK_AUTO_ROLL,
        MENU_ID_LANGLN_BSK_ADD_BOOKMARK,
        MENU_ID_LANGLN_BSK_SEARCH_WORD,
        MENU_ID_LANGLN_BSK_GOTO_PERCENT,
        MENU_ID_LANGLN_BSK_CURSOR_MODE,
        MENU_ID_LANGLN_SK_SETTING,
        MENU_ID_LANGLN_BSK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_BOOKMARK, 0, 3,
        MENU_ID_LANGLN_BSK_MARK_GOTO,
        MENU_ID_LANGLN_BSK_MARK_DEL,
        MENU_ID_LANGLN_BSK_MARK_DELALL,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_BOOKMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_ENTER_DICT, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_ENTER_DICT,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SPEAK, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_SK_SPEAK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SELECT_BOOK, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_BOOK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SELECT_FILE, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_FILE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_BOOKMARK, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_BOOKMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_AUTO_ROLL, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_AUTO_ROLL,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_ADD_BOOKMARK, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_ADD_BOOKMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_SEARCH_WORD, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SEARCH_WORD,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_GOTO_PERCENT, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_GOTO_PERCENT,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_CURSOR_MODE, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_CURSOR_MODE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SETTING, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SETTING,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_HELP, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_HELP,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SELECT_BOOK, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_BOOK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SELECT_FILE, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_FILE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_BOOKMARK, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_BOOKMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_AUTO_ROLL, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_AUTO_ROLL,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_ADD_BOOKMARK, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_ADD_BOOKMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_SEARCH_WORD, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SEARCH_WORD,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_GOTO_PERCENT, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_GOTO_PERCENT,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_CURSOR_MODE, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_CURSOR_MODE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_SK_SETTING, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SETTING,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_HELP, MENU_ID_LANGLN_SK_OPTION_2,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_HELP,0));


    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_MARK_GOTO, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_GOTO_MARK,0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_MARK_DEL, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_DEL_MARK,0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_MARK_DELALL, MENU_ID_LANGLN_SK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_DELALL_MARK,0));


    /*BK*/
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_BK_OPTION_1, 0,
    #ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_BSK_ENTER_DICT,
    #endif
        MENU_ID_LANGLN_BK_SELECT_BOOK,
        MENU_ID_LANGLN_BK_SELECT_FILE, 
        MENU_ID_LANGLN_BSK_BOOKMARK,
        MENU_ID_LANGLN_BSK_AUTO_ROLL,
        MENU_ID_LANGLN_BSK_ADD_BOOKMARK,
        MENU_ID_LANGLN_BSK_SEARCH_WORD,
        MENU_ID_LANGLN_BSK_GOTO_PERCENT,
    #ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_BSK_CURSOR_MODE,
    #endif
        MENU_ID_LANGLN_BK_SETTING,
        MENU_ID_LANGLN_BSK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,0));

    /*read mode*/   
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_BK_OPTION_2, 0,
        MENU_ID_LANGLN_BK_SELECT_BOOK,
        MENU_ID_LANGLN_BK_SELECT_FILE, 
        MENU_ID_LANGLN_BSK_BOOKMARK,
        MENU_ID_LANGLN_BSK_AUTO_ROLL,
        MENU_ID_LANGLN_BSK_ADD_BOOKMARK,
        MENU_ID_LANGLN_BSK_SEARCH_WORD,
        MENU_ID_LANGLN_BSK_GOTO_PERCENT,
        MENU_ID_LANGLN_BSK_CURSOR_MODE,
        MENU_ID_LANGLN_BK_SETTING,
        MENU_ID_LANGLN_BSK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST,STR_GLOBAL_OPTIONS,0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BSK_BOOKMARK, 0, 3,
        MENU_ID_LANGLN_BSK_MARK_GOTO,
        MENU_ID_LANGLN_BSK_MARK_DEL,
        MENU_ID_LANGLN_BSK_MARK_DELALL,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_BOOKMARK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BK_SELECT_BOOK, MENU_ID_LANGLN_BK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_BOOK,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BK_SELECT_FILE, MENU_ID_LANGLN_BK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_FILE,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BK_SETTING, MENU_ID_LANGLN_BK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SETTING,0));
    
    ADD_APPLICATION_MENUITEM((MENU_ID_LANGLN_BK_SELECT_BOOK, MENU_ID_LANGLN_BK_OPTION_1,0,
        SHOW, NONMOVEABLE, DISP_LIST,STR_LANGLN_BSK_SELECT_BOOK,0));
}
#endif


#ifdef __MMI_LANGLN_EK__
/*****************************************************************************
* FUNCTION
*  PopulateLangLnEKRes
* DESCRIPTION
*   Populate All resource data for language learning exam king
*
* PARAMETERS
* 
* RETURNS
*  
* GLOBALS AFFECTED
*   
*****************************************************************************/
void PopulateLangLnEKRes(void)
{
    /*Add Menu Items*/
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_OPTION_1, 0, 
#ifdef __MMI_LANGLN_DK__
        MENU_ID_LANGLN_EK_PICK_MODE,
#endif
        MENU_ID_LANGLN_EK_SELECT_PAPER,
        MENU_ID_LANGLN_EK_SELECT_EXAM,
        MENU_ID_LANGLN_EK_GET_SCORE,
        MENU_ID_LANGLN_EK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_OPTION_2, 0, 
        MENU_ID_LANGLN_EK_ENTRY_DICT,
        MENU_ID_LANGLN_EK_NORMAL_MODE,
        MENU_ID_LANGLN_EK_SELECT_PAPER,
        MENU_ID_LANGLN_EK_SELECT_EXAM,
        MENU_ID_LANGLN_EK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_OPTION_3, 0, 
        MENU_ID_LANGLN_EK_REWORK,
        MENU_ID_LANGLN_EK_RETURN_ANSWER,
        MENU_ID_LANGLN_EK_SELECT_PAPER,
        MENU_ID_LANGLN_EK_SELECT_EXAM,
        MENU_ID_LANGLN_EK_HELP,
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_GLOBAL_OPTIONS, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_RETURN_ANSWER, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_RETURN_ANSWER, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_REWORK, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_REWORK, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_PICK_MODE, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_PICK_MODE, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_NORMAL_MODE, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_NORMAL_MODE, 0));  

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_ENTRY_DICT, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_ENTRY_DICT, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_SELECT_PAPER, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_SELECT_PAPER, 0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_SELECT_EXAM, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_SELECT_EXAM, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_GET_SCORE, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_GET_SCORE, 0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_LANGLN_EK_HELP, MENU_ID_LANGLN_EK_OPTION, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, 0, STR_ID_LANGLN_EK_HELP, 0));


    /* Add Strings */
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_APP_NAME, "Exam King", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_PICK_MODE, "Pick Mode", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_NORMAL_MODE, "Answer Mode", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_RETURN_ANSWER, "Return To Continue", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_ENTRY_DICT, "Enter Dictionary", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SELECT_PAPER, "Select Paper", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SELECT_EXAM, "Select Exam", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_GET_SCORE, "Get Score", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_HELP, "Help", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_TIPS, "Tip", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SCORE, "Score", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SCORE_1, "Total Scores:", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SCORE_2, "\nCorrect:", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SCORE_3, "\nWrong:", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_SCORE_4, "\nYour Scores:", "Language Learning Exam King String" );

    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_CHECK, "Check", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_LEAVE, "Leave", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_REWORK, "Rework", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_HELP_TEXT, "Exam King\n Key 1~4:Option A~D\n Key 5, 6:True and False\n Key 7:Audio control\n Key 8:Tip" ,"Language Learning App String");

    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_RESERVED_ERROR, "Unknown Error", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_DAMAGED, "Damaged", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_INVALID_PARAM, "Invalid Param", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_OPEN_FAIL, "Open Fail", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_OPEN_PAPER_FAIL, "Open Paper Fail", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_WRONG_TYPE, "Wrong Type", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_WRONG_VER, "Wrong Version", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_WRONG_ENCODE, "Wrong Encode", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_NO_ENOUGH_MEM, "No Enough Memory", "Language Learning Exam King String" );  
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_UNLOCK, "Unregistered", "Language Learning Exam King String" );  
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_CAN_NOT_FIND_AUDIO, "Can't Find Audio File", "Language Learning Exam King String" );
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_BUILD_CACHE_ERROR, "Build Cache Fail", "Language Learning Exam King String" );        
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_NO_PICK_WORD, "Please Pick a Word", "Language Learning Exam King String" );        
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_PLAY_AUDIO_FAIL, "Play Failed", "Language Learning Exam King String" );     
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_INIT_FAIL, "Init Paper Failed", "Language Learning Exam King String" );     
    ADD_APPLICATION_STRING2( STR_ID_LANGLN_EK_POPUP_END_EXAM, "To end the current exam?", "Language Learning Exam King String" );  
    
    /* Add Images */
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_CONTENT_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_CONTENT_BG.gif", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_ICON_BG, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_BUTTON_BG.gif", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_A_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_A_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_A_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_A_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_A_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_A_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_B_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_B_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_B_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_B_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_B_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_B_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_C_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_C_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_C_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_C_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_C_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_C_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_D_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_D_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_D_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_D_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_D_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_D_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_YES_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_YES_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_YES_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_YES_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_YES_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_YES_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_NO_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_WRONG_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_NO_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_WRONG_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_NO_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_WRONG_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_TIPS_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_TIP_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_TIPS_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_TIP_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_TIPS_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_TIP_DISABLE.pbm", "Language Learning Exam King image" );
    
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_STOP_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_STOP_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_STOP_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_STOP_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_PLAY_UP, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_PLAY_UP.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_PLAY_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_PLAY_DOWN.pbm", "Language Learning Exam King image" );
    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_PLAY_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_PLAY_DISABLE.pbm", "Language Learning Exam King image" );

    ADD_APPLICATION_IMAGE2( IMG_ID_LANGLN_EK_SUB_PAPER, CUST_IMG_PATH"\\\\MainLCD\\\\LangLn\\\\EK\\\\LANGLN_EK_SUB_PAPER.pbm", "Language Learning Exam King image" );
}
#endif /* __MMI_LANGLN_EK__ */

#endif /* __MMI_LANGLN */
