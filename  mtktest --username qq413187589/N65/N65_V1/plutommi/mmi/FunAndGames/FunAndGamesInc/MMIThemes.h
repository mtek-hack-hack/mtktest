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
 * MMIThemes.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines enum values, structures, and function prototypes, for the Theme application
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

/**************************************************************

   FILENAME : MMIThemes.h

   PURPOSE     : Prototypes for the Theme application

   REMARKS     : nil

   AUTHOR      : Restructured by manju

   DATE     : Restructured on May-24-2003

**************************************************************/

#ifndef _MMI_THEME_H
#define _MMI_THEME_H

#include "MMI_features.h"
#ifdef __MMI_THEMES_APPLICATION__

#ifdef __MMI_THEMES_V2_SUPPORT__
#include "ThemeManager.h"
#endif 
#include "custom_mmi_default_value.h"   /* NVRAM_REVISE */
/* 
 * Define
 */
#define THMEM_FREQ_NUM        6
#define NO_OF_ORDERS             4
#define MAX_THEMES               10
#define THEME_IPADDRESS_NUMERIC_LENGTH			4
#define THEME_NUMERIC_BEGIN						48
#define THEME_NUMERIC_END							57
#define THEME_TOTAL_VALID_SCHEME					3
#define THEME_LOWER_CASE_ALPHA_BEGIN				97
#define THEME_LOWER_CASE_ALPHA_END				122
#define THEME_UPPER_CASE_ALPHA_BEGIN				65
#define THEME_UPPER_CASE_ALPHA_END				90

/* 
 * Typedef 
 */
#ifdef __MMI_THEMES_V2_SUPPORT__
typedef struct
{

    U8 CurrThemeIndex;                      /* current index of theme */
    U32 CurrTheme;                          /* Current id of theme */
    U32 CurrHiliteTheme;                    /* Current highlighted theme */
    U8 TotalTheme;                          /* Total number of themes */
    U8 CurrHiliteItem;                      /* Current selected item */
    U8 CurrUpdatePeriod;                    /* Current update period */
    U8 IsSetFromMenu;                       /* If theme is updated from menu */
    U8 IsOrderChanged;                      /* Is order changed by user *//* shall be optimize later */
    U8 IsInThmApp;                          /* Is current screen in theme application */
    S16 CurrOrderIndex;                     /* Position of current update order */
    PU8 ThemeName[TOTAL_THEMES_COUNT + 1];  /* Name list + "None"  11 */
    S32 TmpOrderList[TOTAL_THEMES_COUNT];   /* Item of set order  4 */
    U32 SetOrderIDList[TOTAL_THEMES_COUNT];
} thm_contex_struct;
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
typedef struct
{
    U8 CurrTheme;                   /* Current index of theme */
    U8 CurrHiliteTheme;             /* Current highlighted theme */
    U8 TotalTheme;                  /* Total number of themes */
    U8 CurrHiliteItem;              /* Current selected item */
    U8 CurrUpdatePeriod;            /* Current update period */
    U8 IsSetFromMenu;               /* If theme is updated from menu */
    U8 IsOrderChanged;              /* Is order changed by user *//* shall be optimize later */
    U8 IsInThmApp;                  /* Is current screen in theme application */
    S16 CurrOrderIndex;             /* Position of current update order */
    U8 CurrOrderList[NO_OF_ORDERS]; /* Order list of theme 4 */
    PU8 ThemeName[MAX_THEMES + 1];  /* Name list + "None"  11 */
    S32 TmpOrderList[NO_OF_ORDERS]; /* Item of set order  4 */
} thm_contex_struct;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_THEMES_V2_SUPPORT__
typedef struct
{
    U16 freq_type;
    S16 set_order_flag;
    U32 themes_order[23];
} thm_nvram_struct;
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
typedef struct
{
    U8 freq_type;
    U8 current_theme_index;
    S16 set_order_flag;
    U8 themes_order[4];
} thm_nvram_struct;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
/* 
 * Extern Global Variable
 */
extern thm_contex_struct g_thm_cntx;

/* 
 * Extern Global Function
 */
extern void InitThemes(void);
extern BOOL ATSetTheme(U8 index);
extern void UpdateThemeAlarm(void);
extern void ReadThemesFromNVRAM(void);

/*
 * Local Used Function
 */
extern void EntryThmMenu(void);
extern void ActivateTheme(void);

/* Leo add for DLT */
extern void DeleteTheme(void);  /* ritesh */

/* Leo end */
extern void WriteThemesToNVRAM(void);
extern void HighlightThmMenu(void);
extern void HighlightThmItems(S32 nIndex);
extern void ThmHandleEndKey(void);
extern void ThmHandleRSK(void);

#if 1   /* defined(__MMI_THEME_AUTO_UPDATE__) */
extern U8 ThemeAlarmCallBack(U8 index, U16 *period, BOOL power_on);
extern void EntryThmOptions(void);
extern void EntryThmUpdatePeriod(void);
extern void ExitThmUpdatePeriod(void);
extern void EntryThmSetOrder(void);
extern void ExitThmSetOrder(void);

/* Leo add for DLT */
extern void EntryThmDownload(void);
extern void ActivateDefaultTheme(void);

/* Leo end */
extern void UpdateThemeOff(void);
/* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */
extern void AlarmExpireUpdateThemeOff(void);
/* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */
extern void UpdateThemePeriod(void);
extern void SaveOrderThemes(void);
extern void SetStartPositionofCurIndex(void);
extern void FillThemesList(void);
extern U8 mmi_thm_reset_current_theme(void);
extern void HighlightThmUpdatePeriod(S32 nIndex);
extern void HighlightThmOption(S32 nIndex);
extern void HighlightThmSetOrder(S32 nIndex);

extern void ThemesFCBInit(void);
extern void ThemesExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME* preReminder);
extern void ThemesReInitQueueCBH(void);

#ifdef __MMI_THEMES_V2_SUPPORT__
extern void ShowThemeList(void);
extern void ConstructThemeList(void);
extern void ConstructThemeOrderList(void);
extern void UpdateOrder(U32 thm_del_ID);
extern void SetOrderIDList(U32 IDList[], U8 noofthemes, S16 index);
extern U8 GetIDList(U32 **GetIDList, S16 *index);
extern U8 CheckForCorrectOrder(void);
extern void SetCurrOrderIndex(S16 index);
extern void ThemeDeleteConfirmation(void);
extern void mmi_thm_display_error_msg(S32 error_type);
extern void mmi_thm_card_plug_out_hdlr(void);
extern void mmi_thm_activate_dflt_sys_theme(void);
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern void ThemeDeleteConfirmation(void);
extern void DeleteTheme(void);
extern void UpdateOrder(U32 thm_del_ID);
pBOOL mmi_thm_isValidUrl(S8 *pucURLText);
pBOOL mmi_thm_checkValidScheme (S8 *pucURLText, S32 iSchemeIndex) ;
pBOOL mmi_thm_checkValidPort (S8 *pucURLText, S32 iStartIndex, S32 iEndIndex) ;
pBOOL mmi_thm_checkValidHostname (S8 *pucURLText, S32 iStartIndex, S32 iEndIndex) ;
pBOOL mmi_thm_checkValidIpaddress (S8 *psUrl_value, S32 iStart_index, S32 iEnd_index);
extern void mmi_thm_highlight_edit_url_done(void);
extern void mmi_thm_highlight_edit_url_cancel(void);
extern void mmi_thm_highlight_edit_url_input_type(void);
extern void mmi_thm_cancel_edit_url(void);
extern void mmi_thm_goback_edit_url(void);

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

#endif /* 1 */ // #if defined(__MMI_THEME_AUTO_UPDATE__)

#endif /* __MMI_THEMES_APPLICATION__ */ // #ifdef __MMI_THEMES_APPLICATION__

#endif /* _MMI_THEME_H */ 

