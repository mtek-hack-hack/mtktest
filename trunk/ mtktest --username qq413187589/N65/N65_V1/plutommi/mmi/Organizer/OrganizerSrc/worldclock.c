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
 * Worldclock.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 /**
 * Copyright Notice
 * (c) 2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      Worldclock.c
   Author:        Vandana M
   Date Created:  June-14-2003
   Contains:      World Clock
**********************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_WORLDCLOCK_C
#define _MMI_WORLDCLOCK_C

/*  Include: MMI header file */
#include "OrganizerDef.h"
#include "worldclock.h"
#include "IdleAppProt.h"
#include "CustDataProts.h"
#include "worldclock.h"
#include "OrganizerDef.h"
#include "CommonScreens.h"
#include "CommonScreens.h"
#include "DateTimeGprot.h"
#ifdef __MMI_WORLDCLOCK_DST__
#include "WallpaperDefs.h"
#include "DownloadDefs.h"
#include "PhoneSetup.h"
#include "Calculator.h"
#endif /* __MMI_WORLDCLOCK_DST__ */ 

/* ... Add More MMI header */

/*  Include: PS header file */
/* ... Add More PS header */
/* 
 * Define
 */
#ifdef __MMI_MAINLCD_128X160__
#define  WC_CITY_NAME_HEIGHT  MMI_TITLE_HEIGHT
#define  WC_HEIGHT_160
#else /* __MMI_MAINLCD_128X160__ */ 
#define WC_CITY_NAME_HEIGHT   0
#endif /* __MMI_MAINLCD_128X160__ */ 

#define WC_V_LINE_Y     (MMI_TITLE_Y+MMI_TITLE_HEIGHT+WC_CITY_NAME_HEIGHT)      /* y-coordinate of vertical line */
#define WC_H_LINE_X     0       /* x-coordinate of horizontal line */
#define WC_LINE_WIDTH   (gdi_layer_get_bit_per_pixel()>>3)
#define WC_NUM_CITY STR_TOTAL_NUM_CITY - STR_WCLOCK_CITY_NONE

// #ifdef __MMI_TOUCH_SCREEN__//061705 Calvin marked
#if defined(__MMI_MAINLCD_240X320__)    /* 041205 Calvin modifed */
#define  WC_TITLE_HEIGHT   40
#define  WC_DATE_HEIGHT 35
#define  WC_TIME_HEIGHT 35
#else /* defined(__MMI_MAINLCD_240X320__) */ 
#define  WC_TITLE_HEIGHT   24
#define  WC_DATE_HEIGHT 22
#define  WC_TIME_HEIGHT 23
#endif /* defined(__MMI_MAINLCD_240X320__) */ 
#ifdef __MMI_WC_TZ_SUPPORT__
#define WC_INDEX_NUM 2
#define WC_MAX_INDEX_INFO_LEN 60

#define WC_TZ_INDEX 0
#define WC_CITY_INDEX 1
#define WC_TZ_SIGN_POS 3
#define WC_GMT_LEN  (WC_TZ_SIGN_POS * sizeof(UI_character_type))
#define WC_MAX_TZ_STR_LEN   5


#define WC_SYM_COMMA    (UI_character_type)','
#define WC_SYM_POSITIVE    (UI_character_type)'+'
#define WC_SYM_NEGATIVE    (UI_character_type)'-'
#define WC_SYM_SPACE    (UI_character_type)' '
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
#ifdef __MMI_NITZ_TZ_SUPPORT__
#define WC_DEFAULT_TZ_NUM   37
#endif 

/* 
 * Typedef 
 */
#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    WC_TOUCH_NONE,
    WC_TOUCH_ON_LEFT_ARROW_UP,
    WC_TOUCH_ON_LEFT_ARROW_DOWN,
    WC_TOUCH_ON_RIGHT_ARROW_UP,
    WC_TOUCH_ON_RIGHT_ARROW_DOWN,
    WC_TOUCH_ON_MAP,
    WC_TOUCH_ON_RSK
} WORLD_CLOCK_PEN_EVENTS;
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* 
 * Local Variable
 */

static U8 gWcTimeZoneIndex[WC_NUM_CITY];
#ifdef __MMI_WC_TZ_SUPPORT__
U8 *homeTime, *foreTime;

#endif /* __MMI_WC_TZ_SUPPORT__ */ 
/*
 * Local Function
 */

/*
 * Global Variable
 */
#ifdef __MMI_WORLD_CLOCK__
wc_context_struct g_wc_cntx;
#endif 
#ifdef __MMI_WC_TZ_SUPPORT__
U8 *gIndexInfo[WC_INDEX_NUM];
extern U8 Cat230HighlightedIndex;
#endif
#if defined (__MMI_NITZ_TZ_SUPPORT__) || defined (__MMI_WC_TZ_SUPPORT__)
const S16 validTZ[WC_DEFAULT_TZ_NUM] =
    { -48, -44, -40, -38, -36, -34, -32, -28, -24, -20, -16, -14, -12, -8, -4, 0, 4, 8, 12, 14, 16, 18, 20, 22, 23, 24,
26, 28, 32, 36, 38, 40, 42, 44, 46, 48, 49};

U8 gWcDefaultCityForTZ[WC_DEFAULT_TZ_NUM];
#endif
U8 g_dst;
/* 
 * Global Function
 */
extern void _show_bitmap(S32 x1, S32 y1, bitmap *b);
extern void _get_bitmap(S32 x1, S32 y1, S32 x2, S32 y2, bitmap *b);
extern U8 PhnsetGetHomeCity(void);
BOOL ATSetHomeCity(U8 CityIndex);
/* MTK Elvis for R2L character */
extern BOOL r2lMMIFlag;

/* MTK end */

#define WC_INITIALIZE


/*****************************************************************************
 * FUNCTION
 *  WcInit
 * DESCRIPTION
 *  Initailze world clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcInit(void)
{
#ifdef __MMI_WORLD_CLOCK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WC_TZ_SUPPORT__
    U8 currentHomeCity;
    S16 currentTimeZone, error;
#endif /* __MMI_WC_TZ_SUPPORT__ */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_wc_cntx, 0, sizeof(wc_context_struct));
    g_wc_cntx.CurrCityIndex = 0xff;
#ifdef __MMI_TOUCH_SCREEN__
    gui_measure_image(get_image(WORLD_CLOCK_LEFT_ARROW_UP), &(g_wc_cntx.arrow_width), &(g_wc_cntx.arrow_height));
    g_wc_cntx.event_on_object = WC_TOUCH_NONE;
#endif 

    SetHiliteHandler(ORGANIZER_WORLDCLOCK_MENU, HighlightWCMenu);
    SetHiliteHandler(MITEM_WORLDCLOCK_BROWSECITY, HighlightWcBrowseCity);

#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
    SetHiliteHandler(MITEM_WORLDCLOCK_SUBLCDDISPLAY, HighlightWcSubLcd);
    SetHintHandler(MITEM_WORLDCLOCK_SUBLCDDISPLAY_CITY1, WcHintCity1);
    SetHintHandler(MITEM_WORLDCLOCK_SUBLCDDISPLAY_CITY2, WcHintCity2);
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
#endif /* __MMI_WORLD_CLOCK__ */ 
    WcGenerateTimeZoneIndex();
	mmi_wc_is_dst();
#ifdef __MMI_NITZ_TZ_SUPPORT__
    mmi_wc_set_default_city_for_tz();
#endif 

#ifdef __MMI_WC_TZ_SUPPORT__
    currentHomeCity = PhnsetGetHomeCity() + 1;    
    currentTimeZone = (S16)(TimeZoneData[currentHomeCity].CityTimeZone * 4);
    WriteValue(NVRAM_TIMEZONE, &currentTimeZone, DS_SHORT, &error);
#endif /* __MMI_WC_TZ_SUPPORT__ */
}

#define WC_UTILITY_FUNCTION


/*****************************************************************************
 * FUNCTION
 *  GetTimeZone
 * DESCRIPTION
 *  Return the time zone of a city
 * PARAMETERS
 *  cityIndex       [IN]        Index of city
 * RETURNS
 *  Time zone
 *****************************************************************************/
FLOAT GetTimeZone(U8 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return TimeZoneData[cityIndex + 1].CityTimeZone;
}


/*****************************************************************************
 * FUNCTION
 *  WcGenerateTimeZoneIndex
 * DESCRIPTION
 *  Generate indexing table of world clock. The table is sorted by time zone and x/y-coordinate.
 * PARAMETERS
 *  void
 *  nIndex(?)       [IN]        Index of item.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void WcGenerateTimeZoneIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    U8 tmp;
    U8 swap = FALSE;
    U8 index1, index2;
    U8 num_city = NUMBER_OF_CITY;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_city - 1; i++)
    {
        gWcTimeZoneIndex[i] = i + 1;
    }

    for (i = 0; i < num_city - 1; i++)
    {
        for (j = 0; j < (num_city - 1) - i - 1; j++)
        {
            index1 = gWcTimeZoneIndex[j + 1];
            index2 = gWcTimeZoneIndex[j];
            if (TimeZoneData[index1].CityTimeZone < TimeZoneData[index2].CityTimeZone)
            {
                swap = TRUE;
            }
            else if (TimeZoneData[index1].CityTimeZone == TimeZoneData[index2].CityTimeZone)
            {
                if (TimeZoneData[index1].CityX < TimeZoneData[index2].CityX)
                {
                    swap = TRUE;
                }
                else if (TimeZoneData[index1].CityX == TimeZoneData[index2].CityX)
                    if (TimeZoneData[index1].CityY < TimeZoneData[index2].CityY)
                    {
                        swap = TRUE;
                    }
            }

            if (swap)
            {
                tmp = gWcTimeZoneIndex[j];  /* swap a[j] and a[j+1]      */
                gWcTimeZoneIndex[j] = gWcTimeZoneIndex[j + 1];
                gWcTimeZoneIndex[j + 1] = tmp;
                swap = FALSE;
            }
        }
    }
}
#ifdef __MMI_NITZ_TZ_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_default_city_for_tz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_set_default_city_for_tz(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 count = 0;
    FLOAT tz;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < NUMBER_OF_CITY; i++)
    {
        tz = (FLOAT) validTZ[count] / (FLOAT) 4;
        if (TimeZoneData[gWcTimeZoneIndex[i]].CityTimeZone == tz)
        {
            gWcDefaultCityForTZ[count] = gWcTimeZoneIndex[i];
            count++;
        }
        else if (TimeZoneData[gWcTimeZoneIndex[i]].CityTimeZone > tz)
        {
            count++;
            /* find the matched timezone for this city, therefore decrease first to balence i++ */
            i--;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wc_set_home_city_from_nitz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nitz_tz     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S16 mmi_wc_set_home_city_from_nitz(S16 nitz_tz, U8 is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < WC_DEFAULT_TZ_NUM; count++)
    {
        if (nitz_tz == validTZ[count])
        {
            if (is_set == 1)
            {
                ATSetHomeCity(gWcDefaultCityForTZ[count]);
            }
            break;
        }
    }

    /* There's no matched city */
    if (count == WC_DEFAULT_TZ_NUM)
    {
        return -1;
    }
    else
    {
        return (S32) gWcDefaultCityForTZ[count];
    }

}
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_home_city
 * DESCRIPTION
 *  Return string of home city
 * PARAMETERS
 *  void
 * RETURNS
 *  String pointer to home city name
 *****************************************************************************/
S8 *mmi_wc_get_home_city(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetString(TimeZoneData[PhnsetGetHomeCity() + 1].CityName);
}


/*****************************************************************************
 * FUNCTION
 *  WcSetCityIndex
 * DESCRIPTION
 *  Set current city.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WcSetCityIndex(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_WORLD_CLOCK__)
    g_wc_cntx.CurrCityIndex = (U8) index;
#ifdef __MMI_WC_TZ_SUPPORT__
    g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
#endif /*__MMI_WC_TZ_SUPPORT__*/
#endif 
}

#ifdef __MMI_WORLD_CLOCK__

#define WC_BROWSE_CITY


/*****************************************************************************
 * FUNCTION
 *  HighlightWCMenu
 * DESCRIPTION
 *  Highlight handler of World Clock menu item.
 *  Register key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWCMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
    SetKeyHandler(EntryWcApp, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(EntryWcApp, KEY_EVENT_UP);
#else /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
    SetLeftSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
    SetKeyHandler(EntryWcBrowseCity, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcBrowseCity
 * DESCRIPTION
 *  Highlight handler of browse city menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryWcBrowseCity, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcBrowseCity
 * DESCRIPTION
 *  Display browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DRAW_MANAGER__
void WcShowCategory(void);
#endif 
void EntryWcBrowseCity(void)
{
#ifdef __MMI_WORLDCLOCK_DST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);

    if (g_wc_cntx.DSTForeign == 0xff)
    {
        g_wc_cntx.DSTForeign = 0;
    }
#endif /* __MMI_WORLDCLOCK_DST__ */ 
    EntryWcBrowseCityEx(EntryWcBrowseCity, ExitWcBrowseCity);
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcBrowseCityEx
 * DESCRIPTION
 *  Display browse city screen
 * PARAMETERS
 *  entry_func      [IN]        
 *  exit_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcBrowseCityEx(void (*entry_func) (void), void (*exit_func) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WC_TZ_SUPPORT__
    S16 error;
    S16 tmpTimeZone;
    U8 *guiBuffer;
    U8 highlight_index;
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize UI related variables */
    EntryNewScreen(SCR_ID_WC_BROWSE_CITY, exit_func, entry_func, MMI_FULL_SCREEN);
    g_wc_cntx.CurrMap = 0xff;
    MMI_title_icon = NULL;
    MMI_menu_shortcut_number = -1;

    if (g_wc_cntx.CurrCityIndex == 0xff)
    {
		if (PhnsetGetHomeCity() != 0xff)
		{
			g_wc_cntx.CurrCityIndex = PhnsetGetHomeCity() + 1;
		}
		else
		{
			g_wc_cntx.CurrCityIndex = 0;
		}
    #ifdef __MMI_WC_TZ_SUPPORT__
        ReadValue(NVRAM_TIMEZONE, &tmpTimeZone, DS_SHORT, &error);		
        g_wc_cntx.CurrTZ = (FLOAT)tmpTimeZone / 4;
    #endif /*__MMI_WC_TZ_SUPPORT__*/
    }
#ifndef __MMI_WC_TZ_SUPPORT__	

    if (g_wc_cntx.VLine == NULL)
    {
        g_wc_cntx.VLine = OslMalloc(sizeof(bitmap));
        g_wc_cntx.VLine->data = OslMalloc(UI_device_height * WC_LINE_WIDTH);
    }

    if (g_wc_cntx.HLine == NULL)
    {
        g_wc_cntx.HLine = OslMalloc(sizeof(bitmap));
        g_wc_cntx.HLine->data = OslMalloc(UI_device_width * WC_LINE_WIDTH);
    }

    /* draw UI */
#ifdef __MMI_DRAW_MANAGER__
    WcShowCategory();
#else 
    WcRedrawWorldClock(0, UI_device_height);
#endif 

    SetKeyHandler(WcHandleKeyLeft, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(WcHandleKeyLeft, KEY_LEFT_ARROW, KEY_LONG_PRESS);
    SetKeyHandler(WcHandleKeyRight, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(WcHandleKeyRight, KEY_RIGHT_ARROW, KEY_LONG_PRESS);
    RedrawCategoryFunction = WcRedrawCategory;

#ifdef __MMI_WORLDCLOCK_DST__
    SetLeftSoftkeyFunction(WcEntryDST, KEY_EVENT_UP);
#endif 
#else /*#ifndef  __MMI_WC_TZ_SUPPORT__*/
    gIndexInfo[WC_TZ_INDEX] = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    gIndexInfo[1] = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    memcpy(gIndexInfo[WC_TZ_INDEX], (S8*) GetString(STR_WORLD_CLOCK_GMT), WC_GMT_LEN);
    homeTime = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    foreTime = OslMalloc(WC_MAX_INDEX_INFO_LEN);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_WC_BROWSE_CITY);
    if (guiBuffer == NULL)  /* not goback from history */
    {
        highlight_index = 0;        
    }    
    else
    {
        highlight_index = g_wc_cntx.highlightIndex;
    }
    
    /* Check if the time zone and city are matched */
    if (g_wc_cntx.CurrTZ != TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone && g_wc_cntx.CurrCityIndex != 0)
    {
        g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);
        ATSetHomeCity((U8) (g_wc_cntx.CurrCityIndex));
		g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (S8*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);

    /* get Home city */
    mmi_wc_get_city_string(g_wc_cntx.CurrCityIndex);
    
    
#ifdef __MMI_TOUCH_SCREEN__
    RegisterCat230PaintPenEventHandler(mmi_wc_paint_pen_handler);
#endif
    ShowCategory230Screen(
        (U8*) GetString(STR_WORLD_CLOCK_TITLE),
        2,
        gIndexInfo,
        highlight_index,
        CAT230_WC_DT,
        mmi_wc_leftkey_handler,
        mmi_wc_rightkey_handler,    /* Cat230RedrawPaint_WC, */
        mmi_wc_get_index_info);

#endif /* __MMI_WC_TZ_SUPPORT__ */ 
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetRightSoftkeyFunction(WcHandleRSK, KEY_EVENT_UP);
#ifdef __MMI_WC_TZ_SUPPORT__
    if (mmi_wc_entry_from_phnset())
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(PhnsetSetHomeCity, KEY_EVENT_UP);        /* set home city */
    }
    else
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
    {
    #ifdef __MMI_WORLDCLOCK_DST__
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(WcEntryDST, KEY_EVENT_UP);
    #else /* __MMI_WORLDCLOCK_DST__ */ 
        ChangeLeftSoftkey(0, 0);
    #endif /* __MMI_WORLDCLOCK_DST__ */ 
    }

    SetKeyHandler(WcHandleKeyEnd, KEY_END, KEY_EVENT_DOWN);
}

#ifdef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_index_info
 * DESCRIPTION
 *  This function is used to get the index information.
 * PARAMETERS
 *  index_info      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_index_info(void *index_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MYTIME currTime, foreignTime;
    cat230_paint_wc_info_struct *index_infomation = (cat230_paint_wc_info_struct*) index_info;
    U8 homeCity = PhnsetGetHomeCity() + 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&currTime, 0, sizeof(MYTIME));
    memset(&foreignTime, 0, sizeof(MYTIME));

    index_infomation->static_x = TimeZoneData[homeCity].CityX;
    index_infomation->static_y = TimeZoneData[homeCity].CityY;

    if (g_wc_cntx.CurrCityIndex == 0)
    {
        index_infomation->dynamic_x = -1;
        index_infomation->dynamic_y = -1;
    }
    else
    {
        index_infomation->dynamic_x = TimeZoneData[g_wc_cntx.CurrCityIndex].CityX;
        index_infomation->dynamic_y = TimeZoneData[g_wc_cntx.CurrCityIndex].CityY;
    }

    index_infomation->hint_string = (U8*) GetString(STR_WORLD_CLOCK_LOCAL);
    index_infomation->city_string = (U8*) GetString(TimeZoneData[homeCity].CityName);

    /* get date/time of home city */
    DTGetRTCTime(&currTime);
    mmi_wc_dt_format(&currTime, homeTime);
    index_infomation->static_string = homeTime;
    /* index_infomation->static_string = (U8*)GetString(STR_WORLD_CLOCK_LOCAL); */

    mmi_wc_get_foreign_city_dt(&foreignTime);
    mmi_wc_dt_format(&foreignTime, foreTime);
    index_infomation->dynamic_string = foreTime;
    /* index_infomation->dynamic_string = (U8*)GetString(STR_WORLD_CLOCK_LOCAL); */

    index_infomation->need_redraw = MMI_TRUE;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_dt_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dt              [?]     
 *  dtString        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_dt_format(MYTIME *dt, U8 *dtString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ascii[WC_MAX_INDEX_INFO_LEN], UniStr[WC_MAX_INDEX_INFO_LEN];
    U8 sizeT = 0, sizeD = 0;
    UI_character_type separate = WC_SYM_COMMA;
    UI_character_type whitespace = WC_SYM_SPACE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dtString, 0, WC_MAX_INDEX_INFO_LEN);
    memset(UniStr, 0, WC_MAX_INDEX_INFO_LEN);
    memset(ascii, 0, WC_MAX_INDEX_INFO_LEN);

    date_string(dt, (UI_string_type) dtString, DT_IDLE_SCREEN);
    //mmi_ucs2_to_asc((S8*) ascii, (S8*) dtString);
    //sizeD = strlen((S8*) ascii);
    sizeD = mmi_ucs2strlen((S8*) dtString);

    memcpy(&(dtString[sizeD * 2]), &separate, sizeof(UI_character_type));
    sizeD++;
    memcpy(&(dtString[sizeD * 2]), &whitespace, sizeof(UI_character_type));
    sizeD++;

    memset(ascii, 0, WC_MAX_INDEX_INFO_LEN);
    time_string(dt, (UI_string_type) UniStr, DT_IDLE_SCREEN);
    //mmi_ucs2_to_asc((S8*) ascii, (S8*) UniStr);
    //sizeT = strlen((S8*) ascii);
    sizeT = mmi_ucs2strlen((S8*) UniStr);
    memcpy(&(dtString[sizeD * 2]), UniStr, sizeT * 2);

    /* mmi_ucs2_to_asc((S8*) &(dtString[size]), (S8*) UniStr); */

    /*
     * time_string(&dt, (UI_string_type) UniStr, DT_IDLE_SCREEN);
     * mmi_ucs2_to_asc((S8*) dtString, (S8*) UniStr);
     * size = strlen(dtString);
     * date_string(&dt, (UI_string_type)UniStr, DT_IDLE_SCREEN);
     * mmi_ucs2_to_asc((S8*) &(dtString[size]), (S8*) UniStr);
     * mmi_asc_to_ucs2(out_buffer, ansii_str);
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_foreign_city_dt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dt      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_foreign_city_dt(MYTIME *dt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME incTime;
    U8 HomeCity;
    FLOAT TimeDiff;
    U8 TimeFlag = 0;
    S32 temp;

#ifdef __MMI_WORLDCLOCK_DST__
    MYTIME dstTime;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get time zone difference */
    HomeCity = PhnsetGetHomeCity() + 1;
    /* TimeDiff = WcTimeZoneDiff(g_wc_cntx.CurrCityIndex, HomeCity); */
    TimeDiff = g_wc_cntx.CurrTZ - TimeZoneData[HomeCity].CityTimeZone;

    memset(&incTime, 0, sizeof(MYTIME));
    DTGetRTCTime(dt);

    if (TimeDiff < 0)
    {
        TimeDiff = TimeDiff * (-1);
        TimeFlag = 1;
    }

    temp = (S32) (TimeDiff * 60);

    incTime.nDay = (U8) (TimeDiff / 24);
    incTime.nHour = ((S32) TimeDiff) % 24;
    incTime.nMin = temp % 60;

    if (TimeFlag)   /* decrement */
    {
        DecrementTime(*dt, incTime, dt);
    }
    else
    {
        IncrementTime(*dt, incTime, dt);
    }

#ifdef __MMI_WORLDCLOCK_DST__
    memset(&dstTime, 0, sizeof(MYTIME));
    dstTime.nHour = 1;
    /* both date light saving is on or off */
    if ((g_wc_cntx.DSTForeign && g_phnset_cntx_p->currentDST) ||
        (g_wc_cntx.DSTForeign == 0 && g_phnset_cntx_p->currentDST == 0) ||
        (g_wc_cntx.CurrCityIndex == HomeCity)) 
    {
        /* do nothing */
    }
    else if (g_phnset_cntx_p->currentDST)   /* only home city turns on DST */
    {
        DecrementTime(*dt, dstTime, dt);
    }
    else if (g_wc_cntx.DSTForeign)  /* only foreign city turns on DST */
    {
        IncrementTime(*dt, dstTime, dt);
    }
#endif /* __MMI_WORLDCLOCK_DST__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_leftkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_leftkey_handler(U8 index_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index_num)
    {
        case WC_TZ_INDEX:
            if (g_wc_cntx.CurrTZ <= -12)
            {
                g_wc_cntx.CurrTZ = 12;
            }
            else
            {
                g_wc_cntx.CurrTZ--;
            }
            g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);

            /* Modify the current time zone to the default city's time zone, ex: GMT 5.5 */
            if (g_wc_cntx.CurrTZ != TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone && g_wc_cntx.CurrCityIndex != 0)
            {
                g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            }
            break;
        case WC_CITY_INDEX:

            /* a time zone without default city is selected as home city */
            if (g_wc_cntx.CurrCityIndex == 0)
            {
                while (g_wc_cntx.CurrCityIndex == 0)
                {
                    if (g_wc_cntx.CurrTZ <= -12)
                    {
                        g_wc_cntx.CurrTZ = 12;
                    }
                    else
                    {
                        g_wc_cntx.CurrTZ--;
                    }
                    g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);
                }
                break;
            }

            curr_index = WcGetCityPosition(g_wc_cntx.CurrCityIndex);
            if (curr_index == 0)
            {
                curr_index = (NUMBER_OF_CITY - 2);
            }
            else
            {
                curr_index--;
            }
            g_wc_cntx.CurrCityIndex = gWcTimeZoneIndex[curr_index];
            g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            break;
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (S8*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);
    mmi_wc_get_city_string(g_wc_cntx.CurrCityIndex);
 
    SetCat230IndexInfo(WC_TZ_INDEX, (U8*) gIndexInfo[WC_TZ_INDEX]);
    SetCat230IndexInfo(WC_CITY_INDEX, (U8*) gIndexInfo[WC_CITY_INDEX]);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_rightkey_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_rightkey_handler(U8 index_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index_num)
    {
        case WC_TZ_INDEX:
            if (g_wc_cntx.CurrTZ >= 12)
            {
                g_wc_cntx.CurrTZ = -12;
            }
            else
            {
                g_wc_cntx.CurrTZ++;
            }
            g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);

            /* Modify the current time zone to the default city's time zone, ex: GMT 5.5 */
            if (g_wc_cntx.CurrTZ != TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone && g_wc_cntx.CurrCityIndex != 0)
            {
                g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            }

            break;
        case WC_CITY_INDEX:
            if (g_wc_cntx.CurrCityIndex == 0)
            {
                while (g_wc_cntx.CurrCityIndex == 0)
                {
                    if (g_wc_cntx.CurrTZ == 12)
                    {
                        g_wc_cntx.CurrTZ = -12;
                    }
                    else
                    {
                        g_wc_cntx.CurrTZ++;
                    }
                    g_wc_cntx.CurrCityIndex = mmi_wc_default_city_of_tz(g_wc_cntx.CurrTZ);
                }
                break;
            }

            curr_index = WcGetCityPosition(g_wc_cntx.CurrCityIndex);

            if (curr_index == (NUMBER_OF_CITY - 2))
            {
                curr_index = 0;
            }
            else
            {
                curr_index++;
            }

            g_wc_cntx.CurrCityIndex = gWcTimeZoneIndex[curr_index];

            g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            break;
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (S8*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);
    mmi_wc_get_city_string(g_wc_cntx.CurrCityIndex);
     
    SetCat230IndexInfo(WC_TZ_INDEX, (U8*) gIndexInfo[WC_TZ_INDEX]);
    SetCat230IndexInfo(WC_CITY_INDEX, (U8*) gIndexInfo[WC_CITY_INDEX]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_default_city_of_tz
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tz      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 mmi_wc_default_city_of_tz(FLOAT tz)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    S16 TZmap = (S16) tz * 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < WC_DEFAULT_TZ_NUM; i++)
	{
		if (validTZ[i] == TZmap)
		{
			return gWcDefaultCityForTZ[i];
		}
	}
    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_tz_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tz          [IN]        
 *  outStr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_tz_string(FLOAT tz, S8 *outStr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type sym;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U8* tmpStr; */

    if (g_wc_cntx.CurrTZ >= 0)
    {
        if (g_wc_cntx.CurrTZ == 0)
        {
            sym = WC_SYM_SPACE;
        }
        else
        {
            sym = WC_SYM_POSITIVE;
        }
        memcpy(outStr, &sym, sizeof(UI_character_type));
        tz = g_wc_cntx.CurrTZ;

    }
    else
    {
        sym = WC_SYM_NEGATIVE;
        memcpy(outStr, &sym, sizeof(UI_character_type));
        tz = -(g_wc_cntx.CurrTZ);
    }

    CalcDouble2String(tz, (S8*) & outStr[sizeof(UI_character_type)], WC_MAX_TZ_STR_LEN);
    //tmpStr = outStr;
    //CalcDouble2String(tz, (S8*) tmpStr, 1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wc_get_city_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tz          [IN]        
 *  outStr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_get_city_string(U8 cityIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *cityName;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cityName = (U8*) GetString(TimeZoneData[g_wc_cntx.CurrCityIndex].CityName);
    /* if home city length to large */
    if (mmi_ucs2strlen((S8*) cityName) >= WC_MAX_INDEX_INFO_LEN / ENCODING_LENGTH)
    {
        memcpy(gIndexInfo[WC_CITY_INDEX], cityName, WC_MAX_INDEX_INFO_LEN - ENCODING_LENGTH);
        mmi_ucs2cat((S8*)gIndexInfo[WC_CITY_INDEX], (S8*)L"\0");
    }
    else
    {
        memcpy(gIndexInfo[WC_CITY_INDEX], cityName, WC_MAX_INDEX_INFO_LEN);
    }
}

#endif /* __MMI_WC_TZ_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitWcBrowseCity
 * DESCRIPTION
 *  Exit function of browse city screen. Free allocated data.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitWcBrowseCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WC_TZ_SUPPORT__
    if (g_wc_cntx.VLine != NULL)
    {
        OslMfree(g_wc_cntx.VLine->data);
        OslMfree(g_wc_cntx.VLine);
        g_wc_cntx.VLine = NULL;
    }

    if (g_wc_cntx.HLine != NULL)
    {
        OslMfree(g_wc_cntx.HLine->data);
        OslMfree(g_wc_cntx.HLine);
        g_wc_cntx.HLine = NULL;
    }
#ifdef __MMI_TOUCH_SCREEN__
    g_wc_cntx.event_on_object = WC_TOUCH_NONE;
#endif     
#else /* __MMI_WC_TZ_SUPPORT__ */ 
    g_wc_cntx.highlightIndex = Cat230HighlightedIndex;
    OslMfree(gIndexInfo[0]);
    OslMfree(gIndexInfo[1]);
    OslMfree(homeTime);
    OslMfree(foreTime);
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  WcHandleRSK
 * DESCRIPTION
 *  LSK handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
    g_wc_cntx.CurrCityIndex = 0xff;
}

#ifdef __MMI_WORLDCLOCK_DST__


/*****************************************************************************
 * FUNCTION
 *  WcChangeDST
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcChangeDST(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wc_cntx.DSTForeign)
    {
        g_wc_cntx.DSTForeign = FALSE;
    }
    else
    {
        g_wc_cntx.DSTForeign = TRUE;
    }

    if (g_wc_cntx.DSTForeign)
    {
        mmi_ucs2cpy((PS8) hintData[0], (PS8) GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(0, hintData[0]);
        ChangeLeftSoftkey(STR_GLOBAL_OFF, 0);
    }
    else
    {
        mmi_ucs2cpy((PS8) hintData[0], (PS8) GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(0, hintData[0]);
        ChangeLeftSoftkey(STR_GLOBAL_ON, 0);
    }
    RedrawCategoryFunction();
}


/*****************************************************************************
 * FUNCTION
 *  WcDSTBackAndSave
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcDSTBackAndSave(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  WcDSTEndKeyHandler
 * DESCRIPTION
 *  End key handler of DST screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcDSTEndKeyHandler(void)
{
	S16 error;
    g_wc_cntx.CurrCityIndex = 0xff;
    WriteValue(NVRAM_WC_DST, &g_wc_cntx.DSTForeign, DS_BYTE, &error);
    DisplayIdleScreen();
}

/*****************************************************************************
 * FUNCTION
 *  WcEntryDST
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcEntryDST(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_items;
    U16 cityarray[1];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_WC_DST, NULL, WcEntryDST, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_WC_DST);

    num_of_items = GetNumOfChild(MENU_ID_WC_DST_OPT);
    GetSequenceStringIds(MENU_ID_WC_DST_OPT, cityarray);
    subMenuDataPtrs[0] = (U8*) GetString(cityarray[0]);
    SetParentHandler(MENU_ID_WC_DST_OPT);

    if (g_wc_cntx.DSTForeign)
    {
        hintDataPtrs[0] = (U8*) GetString(STR_GLOBAL_ON);
    }
    else
    {
        hintDataPtrs[0] = (U8*) GetString(STR_GLOBAL_OFF);
    }

    ShowCategory53Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_ON,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        hintDataPtrs,
        0,
        0,
        guiBuffer);

    if (g_wc_cntx.DSTForeign)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_BACK);
    }

    SetLeftSoftkeyFunction(WcChangeDST, KEY_EVENT_UP);
    SetRightSoftkeyFunction(WcDSTBackAndSave, KEY_EVENT_UP);
    SetKeyHandler(WcDSTEndKeyHandler, KEY_END, KEY_EVENT_DOWN);

}

#endif /* __MMI_WORLDCLOCK_DST__ */ 


/*****************************************************************************
 * FUNCTION
 *  WcTimeZoneDiff
 * DESCRIPTION
 *  Calculate the time zone difference between 2 cities.
 * PARAMETERS
 *  City1       [IN]        Index of city 1.
 *  City2       [IN]        Index of city 2.
 * RETURNS
 *  time tone of city 1 - time zone of city 2.
 *****************************************************************************/
FLOAT WcTimeZoneDiff(U8 City1, U8 City2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (City1 == 0 || City2 == 0)   /* of one the cities is "None" */
    {
        return 25;
    }
    else
    {
        return (TimeZoneData[City1].CityTimeZone - TimeZoneData[City2].CityTimeZone);
    }
}


/*****************************************************************************
 * FUNCTION
 *  WcGetCityPosition
 * DESCRIPTION
 *  Calculate the position of city in timezone order.
 * PARAMETERS
 *  index       [IN]        Index of city.
 * RETURNS
 *  Position on gWcTimeZoneIndex array.
 *****************************************************************************/
U8 WcGetCityPosition(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, num_city;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_city = NUMBER_OF_CITY;
    for (i = 0; i < num_city; i++)
        if (gWcTimeZoneIndex[i] == index)
        {
            break;
        }

    return i;
}

#ifndef __MMI_WC_TZ_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  WcShowDateTime
 * DESCRIPTION
 *  Display date/time in world map
 * PARAMETERS
 *  void
 *  timediff(?)     [IN]        Time difference between current city and home city.
 * RETURNS
 *  Position on gWcTimeZoneIndex array.(?)
 *****************************************************************************/
void WcShowDateTime(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currTime, incTime;

#ifdef __MMI_WORLDCLOCK_DST__
    MYTIME dstTime;
#endif 
    U8 Ucs2Date[30];
    U8 Ucs2Time[30];

#if !defined(__MMI_MAINLCD_176X220__) && !defined (__MMI_MAINLCD_240X320__)     /* 041205 Calvin modieid */
    U8 AsciiDate[30];
#endif 
    PU8 imageday;
    color c;
    U8 HomeCity;
    FLOAT TimeDiff;
    S32 temp;
    U8 TimeFlag = 0;

#if (defined(__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__) || !defined(__MMI_TOUCH_SCREEN__))
    color cblue = {160, 205, 250, 100};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();

    gui_reset_clip();
    gui_reset_text_clip();

    GetDateTime(&currTime);

    /* get time zone difference */
    HomeCity = PhnsetGetHomeCity() + 1;
    TimeDiff = WcTimeZoneDiff(g_wc_cntx.CurrCityIndex, HomeCity);

    memset(&incTime, 0, sizeof(MYTIME));

    if (TimeDiff < 0)
    {
        TimeDiff = TimeDiff * (-1);
        TimeFlag = 1;
    }

    temp = (S32) (TimeDiff * 60);

    incTime.nDay = (U8) (TimeDiff / 24);
    incTime.nHour = ((S32) TimeDiff) % 24;
    incTime.nMin = temp % 60;

    if (TimeFlag)   /* decrement */
    {
        DecrementTime(currTime, incTime, &currTime);
    }
    else
    {
        IncrementTime(currTime, incTime, &currTime);
    }

#ifdef __MMI_WORLDCLOCK_DST__
    if (HomeCity != g_wc_cntx.CurrCityIndex)    /* not home city */
    {
        memset(&dstTime, 0, sizeof(MYTIME));
        dstTime.nHour = 1;
        if (g_wc_cntx.DSTForeign && g_phnset_cntx_p->currentDST)        /* both date light saving is on */
        {
            /* do nothing */
        }
        else if (g_phnset_cntx_p->currentDST)   /* only home city turns on DST */
        {
            DecrementTime(currTime, dstTime, &currTime);
        }
        else if (g_wc_cntx.DSTForeign)  /* only foreign city turns on DST */
        {
            IncrementTime(currTime, dstTime, &currTime);
        }
    }
#endif /* __MMI_WORLDCLOCK_DST__ */ 

    time_string(&currTime, (UI_string_type) Ucs2Time, DT_IDLE_SCREEN);
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)       /* 041205 Calvin modieid */
    date_string(&currTime, (UI_string_type) Ucs2Date, DT_IDLE_SCREEN);
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 
    sprintf((S8*) (AsciiDate), "%02d/%02d", currTime.nMonth, currTime.nDay);
    mmi_asc_to_ucs2((S8*) Ucs2Date, (S8*) AsciiDate);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 

    if ((currTime.nHour >= 6) && (currTime.nHour < 18))
    {
        imageday = get_image(SUN_ICON);
    }
    else
    {
        imageday = get_image(MOON_ICON);
    }
    c = gui_color(0, 0, 0);
    gui_set_text_color(c);
    gui_set_font(&MMI_medium_font);

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        S32 str_w, str_h, str_h1, img_w, img_h, pos_x, pos_y;

    #if defined (__MMI_MAINLCD_240X320__)
        color date_bg = gui_color(106, 133, 98);
    #else 
        color date_bg = gui_color(80, 103, 75);
    #endif 
        color time_bg = gui_color(0, 0, 0);
        color date_time_text_color = gui_color(255, 255, 255);

        gui_set_text_color(date_time_text_color);
        gui_measure_string((UI_string_type) Ucs2Date, &str_w, &str_h1);
        gui_measure_image(imageday, &img_w, &img_h);

        /* show date */
        gui_fill_rectangle(
            0,
            UI_device_height - MMI_button_bar_height - WC_DATE_HEIGHT - WC_TIME_HEIGHT,
            UI_device_width,
            UI_device_height - MMI_button_bar_height - WC_TIME_HEIGHT,
            date_bg);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(
                ((UI_device_width + str_w) >> 1),
                UI_device_height - MMI_button_bar_height - WC_DATE_HEIGHT - WC_TIME_HEIGHT + ((WC_DATE_HEIGHT - str_h1) >> 1));
        }
        else
        {
            gui_move_text_cursor(
                ((UI_device_width - str_w) >> 1),
                UI_device_height - MMI_button_bar_height - WC_DATE_HEIGHT - WC_TIME_HEIGHT + ((WC_DATE_HEIGHT - str_h1) >> 1));
        }
        gui_print_text((U16*) Ucs2Date);

        /* show time */
        gui_measure_string((UI_string_type) Ucs2Time, &str_w, &str_h);
        pos_x = ((UI_device_width - str_w - img_w - 4) >> 1);
        pos_y = UI_device_height - MMI_button_bar_height - WC_TIME_HEIGHT;
        gui_fill_rectangle(0, pos_y, UI_device_width, pos_y + WC_TIME_HEIGHT - 1, time_bg);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(pos_x + str_w, pos_y + ((WC_TIME_HEIGHT - str_h) >> 1));
        }
        else
        {
            gui_move_text_cursor(pos_x, pos_y + ((WC_TIME_HEIGHT - str_h) >> 1));
        }
        gui_print_text((U16*) Ucs2Time);
        /* show day/night image */
        gui_show_transparent_image(pos_x + str_w + 2, pos_y + ((WC_TIME_HEIGHT - img_h) >> 1), imageday, 0);
    #else /* __MMI_TOUCH_SCREEN__ */ 
        S32 str_w, str_h, str_h1;

        gui_fill_rectangle(0, MMI_content_height - 7, UI_device_width - 1, MMI_content_height + WC_V_LINE_Y - 2, cblue);
        gui_measure_string((UI_string_type) Ucs2Date, &str_w, &str_h1);

        /* show date */
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(2 + str_w, MMI_content_height);
        }
        else
        {
            gui_move_text_cursor(2, MMI_content_height);
        }
        gui_print_text((U16*) Ucs2Date);

        str_h1 += MMI_content_height;
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(2 + gui_get_string_width((UI_string_type) Ucs2Time), str_h1 + 2);
        }
        else
        {
            gui_move_text_cursor(2, str_h1 + 2);
        }
        gui_print_text((U16*) Ucs2Time);

        gui_measure_string((UI_string_type) Ucs2Time, &str_w, &str_h);
        gui_show_transparent_image(str_w + 15, str_h1 + 2, imageday, 0);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
    }
#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 
    {
        gui_fill_rectangle(0, MMI_content_height - 7, UI_device_width - 1, UI_device_height - MMI_BUTTON_BAR_HEIGHT, cblue);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(2 + gui_get_string_width((UI_string_type) Ucs2Date), MMI_content_height);
        }
        else
        {
            gui_move_text_cursor(2, MMI_content_height);
        }
        gui_print_text((U16*) Ucs2Date);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(48 + gui_get_string_width((UI_string_type) Ucs2Time), MMI_content_height);
        }
        else
        {
            gui_move_text_cursor(48, MMI_content_height);
        }
        gui_print_text((U16*) Ucs2Time);
        gui_show_transparent_image(110, MMI_content_height, imageday, 0);
    }
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 

#if(UI_DOUBLE_BUFFER_SUPPORT)
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, MMI_content_height - 5, UI_device_width - 1, MMI_content_height + WC_V_LINE_Y);
#endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 

}


/*****************************************************************************
 * FUNCTION
 *  WcDrawTitle
 * DESCRIPTION
 *  Draw title bar and city name of browse city screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcDrawTitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = g_wc_cntx.CurrCityIndex;
    color cblack = {0, 0, 0, 100};
    color cwhite = {255, 255, 255, 100};
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_128X128__)      /* 041205 Calvin modieid */
    S32 str_w = 0, str_h = 0, city_y;
#endif 

#ifdef WC_HEIGHT_160
    S32 width, height;
    UI_string_type CityName;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_title_string = (UI_string_type) GetString(STR_WORLD_CLOCK_TITLE);
    CityName = (UI_string_type) GetString(TimeZoneData[i].CityName);
    gui_measure_string(CityName, &width, &height);
    gui_fill_rectangle(0, (MMI_title_y + MMI_title_height), UI_device_width - 1, WC_V_LINE_Y, cblack);
    /* MTK Elvis for R2L characters */
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(((UI_device_width - width) >> 1) + width, WC_V_LINE_Y - height - 2);
    }
    else
    {
        gui_move_text_cursor((UI_device_width - width) >> 1, WC_V_LINE_Y - height - 2);
    }
    /* MTk end */
    gui_set_text_color(cwhite);
    gui_print_text(CityName);
#else /* WC_HEIGHT_160 */ 
    MMI_title_string = (UI_string_type) GetString(TimeZoneData[i].CityName);
#endif /* WC_HEIGHT_160 */ 

    show_title_status_icon();
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)
    city_y = MMI_status_bar_height;
#elif defined (__MMI_MAINLCD_128X160__)
    city_y = MMI_status_bar_height;
#endif

#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__)       /* 041205 Calvin modieid */
    /* show title string */
    gui_measure_string(MMI_title_string, &str_w, &str_h);
    gui_fill_rectangle(
        0,
        city_y,
        UI_device_width - 1,
        city_y - 1 + WC_TITLE_HEIGHT,
        cblack);
    if (r2lMMIFlag)
    {
        gui_move_text_cursor(
            ((UI_device_width - str_w) >> 1) + str_w,
            city_y + ((WC_TITLE_HEIGHT - str_h) >> 1));
    }
    else
    {
        gui_move_text_cursor((UI_device_width - str_w) >> 1, city_y + ((WC_TITLE_HEIGHT - str_h) >> 1));
    }
    gui_set_text_color(cwhite);
    gui_print_text(MMI_title_string);

#else /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 
    draw_title();
#endif /* defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) */ 

#ifdef __MMI_TOUCH_SCREEN__
    /* show arrows */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_LEFT_ARROW_DOWN)
    {
        gui_show_transparent_image(
            0,
            city_y + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1,
            get_image(WORLD_CLOCK_LEFT_ARROW_DOWN),
            0);
    }
    else
    {
        gui_show_transparent_image(
            0,
            city_y + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1,
            get_image(WORLD_CLOCK_LEFT_ARROW_UP),
            0);
    }

    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_RIGHT_ARROW_DOWN)
    {
        gui_show_transparent_image(
            UI_device_width - g_wc_cntx.arrow_width - 1,
            city_y + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1,
            get_image(WORLD_CLOCK_RIGHT_ARROW_DOWN),
            0);
    }
    else
    {
        gui_show_transparent_image(
            UI_device_width - g_wc_cntx.arrow_width - 1,
            city_y + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1,
            get_image(WORLD_CLOCK_RIGHT_ARROW_UP),
            0);
    }
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  WcRedrawCategory
 * DESCRIPTION
 *  Redraw category function when theme update
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcRedrawCategory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* WcRedrawWorldClock(0,UI_DEVICE_HEIGHT); */
    /* date and time information */
    WcShowDateTime();
    WcDrawTitle();
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(0, 0);
}

/*****************************************************************************
 * FUNCTION
 *  WcRedrawWorldClock
 * DESCRIPTION
 *  Redraw world clock screen
 * PARAMETERS
 *  old_x_vertical          [IN]        Coordinate of previous X.
 *  old_y_horizontal        [IN]        
 *  old_y_vertical(?)       [IN]        Coordinate of previous Y.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void WcRedrawWorldClock(S32 old_x_vertical, S32 old_y_horizontal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    color cred = {255, 0, 0, 100};
    color cwhite = {255, 255, 255, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_reset_clip();
    gui_reset_text_clip();

    gui_lock_double_buffer();

    i = g_wc_cntx.CurrCityIndex;

    if (TimeZoneData[i].MapIndex != g_wc_cntx.CurrMap)
    {
        gui_fill_rectangle(0, MMI_title_y, UI_device_width - 1, MMI_content_height + WC_V_LINE_Y - 2, cwhite);
        g_wc_cntx.CurrMap = TimeZoneData[i].MapIndex;
        gui_show_image(0, WC_V_LINE_Y, get_image((U16) (WORLD_CLOCK_IMAGE1 + g_wc_cntx.CurrMap - 1)));
    }
    else
    {
        _show_bitmap(old_x_vertical, WC_V_LINE_Y, g_wc_cntx.VLine);
        _show_bitmap(WC_H_LINE_X, old_y_horizontal, g_wc_cntx.HLine);
    }

    gui_reset_clip();

    /* get the bitmap of the vertical and horizontal line */
    _get_bitmap(TimeZoneData[i].CityX, WC_V_LINE_Y, TimeZoneData[i].CityX, MMI_content_height - 8, g_wc_cntx.VLine);
    _get_bitmap(
        0,
        TimeZoneData[i].CityY + WC_V_LINE_Y,
        UI_device_height,
        TimeZoneData[i].CityY + WC_V_LINE_Y,
        g_wc_cntx.HLine);

    gui_draw_vertical_line(WC_V_LINE_Y, MMI_content_height - 8, TimeZoneData[i].CityX, cred);
    gui_draw_horizontal_line(0, UI_device_height, TimeZoneData[i].CityY + WC_V_LINE_Y, cred);

    /* date and time information */
    WcShowDateTime();

    /* title */
    WcDrawTitle();
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
#ifdef __MMI_WORLDCLOCK_DST__
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
#else 
    ChangeLeftSoftkey(0, 0);
#endif 

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  WcHandleKeyRight
 * DESCRIPTION
 *  Right arrow key handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcHandleKeyRight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_x_vertical, old_y_horizontal;
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_index = WcGetCityPosition(g_wc_cntx.CurrCityIndex);

    old_x_vertical = TimeZoneData[gWcTimeZoneIndex[curr_index]].CityX;
    old_y_horizontal = TimeZoneData[gWcTimeZoneIndex[curr_index]].CityY + WC_V_LINE_Y;

    if (curr_index == (NUMBER_OF_CITY - 2))
    {
        curr_index = 0;
    }
    else
    {
        curr_index++;
    }

    g_wc_cntx.CurrCityIndex = gWcTimeZoneIndex[curr_index];

    WcRedrawWorldClock(old_x_vertical, old_y_horizontal);
}


/*****************************************************************************
 * FUNCTION
 *  WcHandleKeyLeft
 * DESCRIPTION
 *  Left arrow key handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcHandleKeyLeft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 old_x_vertical, old_y_horizontal;
    U8 curr_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_index = WcGetCityPosition(g_wc_cntx.CurrCityIndex);

    old_x_vertical = TimeZoneData[gWcTimeZoneIndex[curr_index]].CityX;
    old_y_horizontal = TimeZoneData[gWcTimeZoneIndex[curr_index]].CityY + WC_V_LINE_Y;

    if (curr_index == 0)
    {
        curr_index = (NUMBER_OF_CITY - 2);  /* 56; */
    }
    else
    {
        curr_index--;
    }

    g_wc_cntx.CurrCityIndex = gWcTimeZoneIndex[curr_index];

    WcRedrawWorldClock(old_x_vertical, old_y_horizontal);

}
#endif /* __MMI_WC_TZ_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  WcHandleKeyEnd
 * DESCRIPTION
 *  End key handler of browse city screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcHandleKeyEnd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrCityIndex = 0xff;
    DisplayIdleScreen();
}
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#define WC_PEN_GAP   3
#ifndef __MMI_WC_TZ_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  WcPenDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL WcPenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number_of_city = mmi_wc_get_size();
    S32 i = 0, pos_x = point.x, pos_y = point.y;
    U8 backup_idx = g_wc_cntx.CurrCityIndex;
    wgui_component_info_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* left arrow */
    pos.pos_x = 0;
    pos.pos_y = MMI_status_bar_height + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1;
    pos.height = g_wc_cntx.arrow_height;
    pos.width = g_wc_cntx.arrow_width;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* LEFT ARROW */
    {
        g_wc_cntx.event_on_object = WC_TOUCH_ON_LEFT_ARROW_DOWN;
        WcHandleKeyLeft();
        return MMI_TRUE;
    }

    /* right arrow */
    pos.pos_x = UI_device_width - g_wc_cntx.arrow_width - 1;
    pos.pos_y = MMI_status_bar_height + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1;
    if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* RIGHT ARROW */
    {
        g_wc_cntx.event_on_object = WC_TOUCH_ON_RIGHT_ARROW_DOWN;
        WcHandleKeyRight();
        return MMI_TRUE;
    }

    for (i = 0; i < number_of_city; i++)
    {
        S32 old_x_vertical = TimeZoneData[i].CityX;
        S32 old_y_horizontal = TimeZoneData[i].CityY + WC_V_LINE_Y;

        if (TimeZoneData[i].MapIndex == g_wc_cntx.CurrMap && pos_x >= old_x_vertical - WC_PEN_GAP &&
            pos_x <= old_x_vertical + WC_PEN_GAP && pos_y >= old_y_horizontal - WC_PEN_GAP &&
            pos_y <= old_y_horizontal + WC_PEN_GAP)
        {
            g_wc_cntx.CurrCityIndex = i;
            WcRedrawWorldClock(TimeZoneData[backup_idx].CityX, TimeZoneData[backup_idx].CityY + WC_V_LINE_Y);
            g_wc_cntx.event_on_object = WC_TOUCH_ON_MAP;
            return MMI_TRUE;
        }
    }
    g_wc_cntx.event_on_object = WC_TOUCH_NONE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  WcPenUpHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL WcPenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_component_info_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* left arrow */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_LEFT_ARROW_DOWN)
    {
        pos.pos_x = 0;
        pos.pos_y = MMI_status_bar_height + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1;
        pos.height = g_wc_cntx.arrow_height;
        pos.width = g_wc_cntx.arrow_width;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* LEFT ARROW */
        {
            gui_show_transparent_image(pos.pos_x, pos.pos_y, get_image(WORLD_CLOCK_LEFT_ARROW_UP), 0);
            gui_BLT_double_buffer(
                pos.pos_x,
                pos.pos_y,
                pos.pos_x + pos.pos_x + pos.width - 1,
                pos.pos_y + pos.height - 1);
            g_wc_cntx.event_on_object = WC_TOUCH_NONE;
            return MMI_TRUE;
        }
    }

    /* right arrow */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_RIGHT_ARROW_DOWN)
    {
        pos.pos_x = UI_device_width - g_wc_cntx.arrow_width - 1;
        pos.pos_y = MMI_status_bar_height + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1;
        pos.height = g_wc_cntx.arrow_height;
        pos.width = g_wc_cntx.arrow_width;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* RIGHT ARROW */
        {
            gui_show_transparent_image(pos.pos_x, pos.pos_y, get_image(WORLD_CLOCK_RIGHT_ARROW_UP), 0);
            gui_BLT_double_buffer(
                pos.pos_x,
                pos.pos_y,
                pos.pos_x + pos.pos_x + pos.width - 1,
                pos.pos_y + pos.height - 1);
            g_wc_cntx.event_on_object = WC_TOUCH_NONE;
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  WcPenRepeatHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL WcPenRepeatHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* left arrow */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_LEFT_ARROW_DOWN)
    {
        WcHandleKeyLeft();
        return MMI_TRUE;
    }

    /* right arrow */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_RIGHT_ARROW_DOWN)
    {
        WcHandleKeyRight();
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  WcPenMoveHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL WcPenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number_of_city = mmi_wc_get_size();
    S32 i = 0, pos_x = point.x, pos_y = point.y;
    U8 backup_idx = g_wc_cntx.CurrCityIndex;
    wgui_component_info_struct pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* left arrow */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_LEFT_ARROW_DOWN ||
        g_wc_cntx.event_on_object == WC_TOUCH_ON_LEFT_ARROW_UP)
    {
        pos.pos_x = 0;
        pos.pos_y = MMI_status_bar_height + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1;
        pos.height = g_wc_cntx.arrow_height;
        pos.width = g_wc_cntx.arrow_width;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* LEFT ARROW */
        {
            g_wc_cntx.event_on_object = WC_TOUCH_ON_LEFT_ARROW_DOWN;
            return MMI_TRUE;
        }
        else
        {
            if (g_wc_cntx.event_on_object == WC_TOUCH_ON_LEFT_ARROW_DOWN)
            {
                g_wc_cntx.event_on_object = WC_TOUCH_ON_LEFT_ARROW_UP;
                gui_show_transparent_image(pos.pos_x, pos.pos_y, get_image(WORLD_CLOCK_LEFT_ARROW_UP), 0);
                gui_BLT_double_buffer(
                    pos.pos_x,
                    pos.pos_y,
                    pos.pos_x + pos.pos_x + pos.width - 1,
                    pos.pos_y + pos.height - 1);
            }
            return MMI_FALSE;
        }
    }
    /* right arrow */
    if (g_wc_cntx.event_on_object == WC_TOUCH_ON_RIGHT_ARROW_DOWN ||
        g_wc_cntx.event_on_object == WC_TOUCH_ON_RIGHT_ARROW_UP)
    {
        pos.pos_x = UI_device_width - g_wc_cntx.arrow_width - 1;
        pos.pos_y = MMI_status_bar_height + ((WC_TITLE_HEIGHT - g_wc_cntx.arrow_height) >> 1) - 1;
        pos.height = g_wc_cntx.arrow_height;
        pos.width = g_wc_cntx.arrow_width;
        if (wgui_test_object_position(point, pos) == MMI_TRUE)  /* RIGHT ARROW */
        {
            g_wc_cntx.event_on_object = WC_TOUCH_ON_RIGHT_ARROW_DOWN;
            return MMI_TRUE;
        }
        else
        {
            if (g_wc_cntx.event_on_object == WC_TOUCH_ON_RIGHT_ARROW_DOWN)
            {
                g_wc_cntx.event_on_object = WC_TOUCH_ON_RIGHT_ARROW_UP;
                gui_show_transparent_image(pos.pos_x, pos.pos_y, get_image(WORLD_CLOCK_RIGHT_ARROW_UP), 0);
                gui_BLT_double_buffer(
                    pos.pos_x,
                    pos.pos_y,
                    pos.pos_x + pos.pos_x + pos.width - 1,
                    pos.pos_y + pos.height - 1);
            }
            return MMI_FALSE;
        }
    }

    for (i = 0; i < number_of_city; i++)
    {
        S32 old_x_vertical = TimeZoneData[i].CityX;
        S32 old_y_horizontal = TimeZoneData[i].CityY + WC_V_LINE_Y;

        if (TimeZoneData[i].MapIndex == g_wc_cntx.CurrMap && pos_x >= old_x_vertical - WC_PEN_GAP &&
            pos_x <= old_x_vertical + WC_PEN_GAP && pos_y >= old_y_horizontal - WC_PEN_GAP &&
            pos_y <= old_y_horizontal + WC_PEN_GAP)
        {
            g_wc_cntx.CurrCityIndex = i;
            WcRedrawWorldClock(TimeZoneData[backup_idx].CityX, TimeZoneData[backup_idx].CityY + WC_V_LINE_Y);
            g_wc_cntx.event_on_object = WC_TOUCH_ON_MAP;
            return MMI_TRUE;
        }
    }
    g_wc_cntx.event_on_object = WC_TOUCH_NONE;
    return MMI_FALSE;
}

#else /* __MMI_WC_TZ_SUPPORT__ */ 
#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_wc_paint_pen_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wc_paint_pen_handler(S32 x, S32 y, S32 event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 number_of_city = mmi_wc_get_size();
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < number_of_city; i++)
    {
        S32 old_x_vertical = TimeZoneData[i].CityX;
        S32 old_y_horizontal = TimeZoneData[i].CityY;   /* WC_V_LINE_Y; */

        if (x >= old_x_vertical - WC_PEN_GAP && x <= old_x_vertical + WC_PEN_GAP
            && y >= old_y_horizontal - WC_PEN_GAP && y <= old_y_horizontal + WC_PEN_GAP)
        {
            g_wc_cntx.CurrCityIndex = i;
            g_wc_cntx.event_on_object = WC_TOUCH_ON_MAP;
            g_wc_cntx.CurrTZ = TimeZoneData[g_wc_cntx.CurrCityIndex].CityTimeZone;
            break;
        }
    }

    /* get time zone string */
    mmi_wc_get_tz_string(g_wc_cntx.CurrTZ, (S8*) & gIndexInfo[WC_TZ_INDEX][WC_GMT_LEN]);

    /* get Home city */
    memcpy(gIndexInfo[WC_CITY_INDEX], GetString(TimeZoneData[g_wc_cntx.CurrCityIndex].CityName), WC_MAX_INDEX_INFO_LEN);

    SetCat230IndexInfo(WC_TZ_INDEX, (U8*) gIndexInfo[WC_TZ_INDEX]);
    SetCat230IndexInfo(WC_CITY_INDEX, (U8*) gIndexInfo[WC_CITY_INDEX]);
}
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
#endif /* __MMI_TOUCH_SCREEN__ */ 
#ifndef __MMI_WC_TZ_SUPPORT__
#ifdef __MMI_DRAW_MANAGER__


/*****************************************************************************
 * FUNCTION
 *  WcScreenDrawCallBack
 * DESCRIPTION
 *  
 * PARAMETERS
 *  coordinate      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void WcScreenDrawCallBack(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WcRedrawWorldClock(0, UI_device_height);
}


/*****************************************************************************
 * FUNCTION
 *  WcShowCategory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcShowCategory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetupCategoryKeyHandlers();
    dm_register_category_controlled_callback(WcScreenDrawCallBack);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(WcPenDownHandler, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(WcPenUpHandler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(WcPenRepeatHandler, MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(WcPenMoveHandler, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_data.s32CatId = MMI_CATEGORY_WCLOCK;
    dm_data.s32ScrId = GetActiveScreenId();
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
}
#endif /* __MMI_DRAW_MANAGER__ */ 
#endif /* __MMI_WC_TZ_SUPPORT__ */ 
#define WC_SUBLCD_DISPLAY
#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)


/*****************************************************************************
 * FUNCTION
 *  EntryWcApp
 * DESCRIPTION
 *  Entry function of world clock application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 WC_list_of_items[2];
    S32 num_of_items;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_WC_APP, NULL, EntryWcApp, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_WC_APP);

    num_of_items = GetNumOfChild(ORGANIZER_WORLDCLOCK_MENU);

    GetSequenceStringIds(ORGANIZER_WORLDCLOCK_MENU, WC_list_of_items);

    SetParentHandler(ORGANIZER_WORLDCLOCK_MENU);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_WORLD_CLOCK_TITLE,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        WC_list_of_items,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  WcGetNearbyCityNameIndex
 * DESCRIPTION
 *  Get the index of near by city.
 * PARAMETERS
 *  inp     [IN]        First character of city name.
 * RETURNS
 *  index of nearest city.
 *****************************************************************************/
U8 WcGetNearbyCityNameIndex(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 n1 = 0;
    U8 num_city = NUMBER_OF_CITY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 1; (i < (num_city)); i++)
    {
        memcpy(&n1, subMenuDataPtrs[i], ENCODING_LENGTH);
        if (n1 >= inp)
        {
            return (U8) (i - 1);
        }
    }

    return 255;
}


/*****************************************************************************
 * FUNCTION
 *  WcMultitapInputCallBack
 * DESCRIPTION
 *  Call back function when input some characters in the screen.
 * PARAMETERS
 *  inp     [IN]        Input character
 * RETURNS
 *  void
 *****************************************************************************/
void WcMultitapInputCallBack(UI_character_type inp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrHiliteCity = WcGetNearbyCityNameIndex(inp) + 1;
    fixed_list_goto_item(g_wc_cntx.CurrHiliteCity);
}


/*****************************************************************************
 * FUNCTION
 *  WcMultitapCompleteCallBack
 * DESCRIPTION
 *  Call back function when multi-tap opeartion finished.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcMultitapCompleteCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fixed_list_goto_item(g_wc_cntx.CurrHiliteCity);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcSubLcd
 * DESCRIPTION
 *  Highlight handler of Sub Lcd Display menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryWcSubLcd, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  WcSaveSubLcdSetting
 * DESCRIPTION
 *  Save selected city to cache.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WcSaveSubLcdSetting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wc_cntx.CurrHiliteSublcd == 0)
    {
        WriteValue(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.CurrHiliteCity, DS_BYTE, &error);   /* homecity */
    }
    else
    {
        WriteValue(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.CurrHiliteCity, DS_BYTE, &error);
    }

    SubLCDIdleScreen();
    DisplayPopup((U8*) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 0, UI_POPUP_NOTIFYDURATION_TIME, SAVE_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcSubLcdCity
 * DESCRIPTION
 *  Highlight handler of sub-lcd display city list.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcSubLcdCity(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrHiliteCity = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcSelectCity
 * DESCRIPTION
 *  Display list of cities
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcSelectCity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 index;
    U8 num_city = NUMBER_OF_CITY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_WC_OPTIONS, NULL, EntryWcSelectCity, NULL);

    for (i = 0; i < num_city; i++)
    {
        mmi_ucs2cpy((S8*) subMenuDataPtrs[i], (S8*) GetString(TimeZoneData[i].CityName));
    }

    if (g_wc_cntx.CurrHiliteSublcd == 0)
    {
        index = g_wc_cntx.City1;
    }
    else
    {
        index = g_wc_cntx.City2;
    }

    RegisterHighlightHandler(HighlightWcSubLcdCity);

    ShowCategory6Screen(
        STR_WORLD_SELECT_CITY,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_city,
        subMenuDataPtrs,
        index,
        NULL);

    if (!IsChineseSet())
    {
        set_numberless_multitap();
        register_multitap_no_draw_key_handlers();
        set_multitap_functions(WcMultitapInputCallBack, WcMultitapCompleteCallBack);
        change_multitap_mode(0);
    }

    SetLeftSoftkeyFunction(WcSaveSubLcdSetting, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  WcHintCity1
 * DESCRIPTION
 *  Hint handler of city 1.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WcHintCity1(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.City1, DS_BYTE, &error); /* homecity */
    if (g_wc_cntx.City1 == 0xff)    /* not written anything in NVRAM */
    {
        g_wc_cntx.City1 = PhnsetGetHomeCity() + 1;
        WriteValue(NVRAM_DOWNLOAD_CITY1, &g_wc_cntx.City1, DS_BYTE, &error);    /* homecity */
    }

    mmi_ucs2ncpy(
        (S8*) hintData[index],
        (S8*) GetString(TimeZoneData[g_wc_cntx.City1].CityName),
        MAX_SUBMENU_CHARACTERS);
}


/*****************************************************************************
 * FUNCTION
 *  WcHintCity2
 * DESCRIPTION
 *  Hint handler of city 2.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void WcHintCity2(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.City2, DS_BYTE, &error);
    if (g_wc_cntx.City2 == 0xff)
    {
        g_wc_cntx.City2 = 0;
        WriteValue(NVRAM_DOWNLOAD_CITY2, &g_wc_cntx.City2, DS_BYTE, &error);    /* none */
    }
    mmi_ucs2ncpy(
        (S8*) hintData[index],
        (S8*) GetString(TimeZoneData[g_wc_cntx.City2].CityName),
        MAX_SUBMENU_CHARACTERS);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightWcSubLcdMenu
 * DESCRIPTION
 *  Highlight handler of Sub-Lcd menu.
 * PARAMETERS
 *  nIndex      [IN]        Index of item.
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightWcSubLcdMenu(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wc_cntx.CurrHiliteSublcd = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryWcSubLcd
 * DESCRIPTION
 *  Entry function of Sub-LCD display
 * PARAMETERS
 *  void
 *  nIndex(?)       [IN]        Index of item.
 * RETURNS
 *  void
 *****************************************************************************/
void EntryWcSubLcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_items;
    U16 cityarray[2];
    U8 *guiBuffer;
    U8 *u8WorldClockPop[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_WC_SUBLCD, NULL, EntryWcSubLcd, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_WC_SUBLCD);

    num_of_items = GetNumOfChild(MITEM_WORLDCLOCK_SUBLCDDISPLAY);
    GetSequenceStringIds(MITEM_WORLDCLOCK_SUBLCDDISPLAY, cityarray);
    SetParentHandler(MITEM_WORLDCLOCK_SUBLCDDISPLAY);

    RegisterHighlightHandler(HighlightWcSubLcdMenu);

    ConstructHintsList(MITEM_WORLDCLOCK_SUBLCDDISPLAY, u8WorldClockPop);

    ShowCategory52Screen(
        STR_WORLD_CLOCK_MENU2,
        GetRootTitleIcon(ORGANIZER_WORLDCLOCK_MENU),
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        num_of_items,
        cityarray,
        (U16*) gIndexIconsImageList,
        u8WorldClockPop,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(EntryWcSelectCity, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ // #if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
#endif /* __MMI_WORLD_CLOCK__ */ // #ifdef __MMI_WORLD_CLOCK__
/* MTK end */
/*****************************************************************************
* FUNCTION
*	mmi_wc_is_dst
* DESCRIPTION
*   function to get if daylight saving is enabled in MMI
* PARAMETERS
*	None.
* RETURNS	
*	None
* GLOBALS AFFECTED
*	None.
*****************************************************************************/
void mmi_wc_is_dst(void)
{
	S16 error;

	ReadValue(NVRAM_SETTING_DT_DST, &g_dst, DS_BYTE, &error);
}

#endif /* _MMI_WORLDCLOCK_C */ // #ifndef _MMI_WORLDCLOCK_C

