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

/*******************************************************************************
 * Filename:
 * ---------
 * Worldclock.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, enum value, structure, and function prototype for world clock.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      worldclock.h
   Author:        Vandana M
   Date Created:  July-14-2003
   Contains:      WorldClock
**********************************************************************************/
#ifndef _MMI_WORLDCLOCK_H
#define _MMI_WORLDCLOCK_H

#define __MMI_WORLDCLOCK_DST__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "Gui_data_types.h"
#include "WorldclockResDef.h"
/* 
 * Define
 */

/* 
 * Typedef 
 */
typedef struct
{
    FLOAT CityTimeZone; /* time difference */
    U16 CityName;       /* city name in English. */
    U16 CityAbbr;       /* abbreviation name of city. */
    U8 CityX;           /* the X coordinate of city. */
    U8 CityY;           /* the Y coordinate of city. */
    U8 MapIndex;
} TimeZoneStruct;

typedef struct
{
#ifndef __MMI_WC_TZ_SUPPORT__
    bitmap *VLine;      /* bitmap object to store the image of vertical and horizontal line */
    bitmap *HLine;
#else
    FLOAT CurrTZ;
    U8 highlightIndex;
#endif
    U8 CurrMap;         /* index of current image map */
    U8 CurrCityIndex;   /* index of current selected city in world map */
#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
    U8 CurrHiliteSublcd;
    U8 CurrHiliteCity;  /* for multitap selection of cities */
    U8 City1;
    U8 City2;
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
#ifdef __MMI_WORLDCLOCK_DST__
    U8 DSTForeign;
#endif 
    S32 arrow_width, arrow_height;
#ifdef __MMI_TOUCH_SCREEN__
    U32 event_on_object;
#endif 
} wc_context_struct;


/* 
 * Extern Global Variable
 */
extern const TimeZoneStruct TimeZoneData[];
extern U8 mmi_wc_get_size(void);

#define NUMBER_OF_CITY mmi_wc_get_size()

#define MMI_WC_SET_HOME_CITY    1
#define MMI_WC_CHECK_HOME_CITY    0

#ifdef __MMI_WORLD_CLOCK__
extern wc_context_struct g_wc_cntx;
#endif 

/* 
 * Extern Global Function
 */
extern void WcInit(void);
extern void WcGenerateTimeZoneIndex(void);
extern FLOAT GetTimeZone(U8 cityIndex);
extern S8 *mmi_wc_get_home_city(void);
extern void WcSetCityIndex(U16 index);
#ifdef __MMI_NITZ_TZ_SUPPORT__
extern void mmi_wc_set_default_city_for_tz(void);
extern S16 mmi_wc_set_home_city_from_nitz(S16 nitz_tz, U8 is_set);
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 

#ifdef __MMI_WORLD_CLOCK__
extern void HighlightWCMenu(void);
extern void EntryWcBrowseCity(void);
extern void EntryWcBrowseCityEx(void (*entry_func) (void), void (*exit_func) (void));
extern void ExitWcBrowseCity(void);
extern void HighlightWcBrowseCity(void);
extern FLOAT WcTimeZoneDiff(U8 City1, U8 City2);
extern void WcShowDateTime(void);
extern void WcHandleKeyLeft(void);
extern void WcHandleKeyRight(void);
extern void WcHandleKeyEnd(void);
extern void WcEntryDST(void);
extern void WcHandleRSK(void);
extern void WcRedrawWorldClock(S32 old_x_vertical, S32 old_y_horizontal);
extern U8 WcGetCityPosition(U8 index);
extern void WcRedrawCategory(void);
extern void WcDSTEndKeyHandler(void);

#if defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__)
extern void HighlightWcSubLcd(void);
extern void EntryWcSubLcd(void);
extern void EntryWcSelectCity(void);    /* sub-LCD */
extern void EntryWcApp(void);
extern void WcHintCity1(U16 index);
extern void WcHintCity2(U16 index);
#endif /* defined(__MMI_WORLD_CLOCK_SUBLCD_SETTING__) */ 
#ifdef __MMI_WC_TZ_SUPPORT__
extern void mmi_wc_get_index_info(void* info);
extern void mmi_wc_get_foreign_city_dt(MYTIME* dt);
extern void mmi_wc_leftkey_handler(U8 index_num);
extern void mmi_wc_rightkey_handler(U8 index_num);
extern U8 mmi_wc_default_city_of_tz(FLOAT tz);
extern void mmi_wc_dt_format(MYTIME* dt, U8* dtString);
extern void mmi_wc_paint_pen_handler(S32 x, S32 y, S32 event_type);
extern U8 mmi_wc_entry_from_phnset(void);
extern void mmi_wc_get_tz_string(FLOAT tz, S8* outStr);
extern void mmi_wc_get_city_string(U8 cityIndex);
#endif /* #ifdef __MMI_WC_TZ_SUPPORT__ */ 
#endif /* __MMI_WORLD_CLOCK__ */ 
extern void mmi_wc_is_dst(void);
#endif /* _MMI_WORLDCLOCK_H */ 

