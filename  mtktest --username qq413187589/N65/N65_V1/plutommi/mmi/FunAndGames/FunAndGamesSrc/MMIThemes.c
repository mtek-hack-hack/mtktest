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
 * MMIthemes.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Theme application.
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
                                                                               ****************************************************************************//**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************
   FILENAME : MMIThemes.c
   PURPOSE     : Theme application
   REMARKS     : nil
   AUTHOR      : Restructured by manju
   DATE     : Restructured on May-24-2003
**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_THEME_C
#define _MMI_THEME_C

/*  Include: MMI header file */
#ifdef __MMI_THEMES_APPLICATION__

#include "FunAndGamesDefs.h"    /* application */
#include "FunAndGamesProts.h"



#include "MainMenuDef.h"
#include "CommonScreens.h"
/* MAUI_00019098_Patch_01 Start */
#include "SettingDefs.h"
#include "WallpaperDefs.h"
/* MAUI_00019098_Patch_01 End */
#include "HelpProt.h"
/* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00221092 */
#include "SimDetectionGexdcl.h"
/* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00221092 */

#include "AlarmFrameworkProt.h"
#include "DateTimeGprot.h"


/* Leo add for DLT */
#include "PhoneBookDef.h"
#include "MMIThemes.h"
#include "Wgui_status_icons.h"
#include "wap_ps_struct.h"
#include "wapadp.h"
#include "mmiapi.h"
#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FrameworkProt.h"
/* Leo end */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#include "SimDetectionGprot.h"
#include "CommonScreens.h"
#else
#endif 

#include "JavaAgencyDef.h"

/* 
 * Define
 */
#define NO_OF_THEME_OPTION_MENUITEMS_IN_USB_MODE 2

/* 
 * Typedef 
 */

/******************************************************************************
 * Local Variable
 *****************************************************************************/

thm_contex_struct g_thm_cntx;

/* map update period to index */
static const U8 g_themes_freq_set[THMEM_FREQ_NUM] =
{
    ALM_FREQ_OFF, 
    ALM_FREQ_HOURLY, 
    ALM_FREQ_EVERYDAY, 
    ALM_FREQ_WEEKLY, 
    ALM_FREQ_MONTHLY, 
    ALM_FREQ_SEASONALLY
};

/******************************************************************************
 * Local Function
 *****************************************************************************/
static void mmi_theme_hint_update_period(U16 index);
#ifdef __MMI_THEMES_V2_SUPPORT__
static	S8 *mmi_thm_ValidSchemeList [THEME_TOTAL_VALID_SCHEME] = {"file","http","https"} ;
#endif

/****************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern wgui_inline_item wgui_inline_items[];    /* shall be move to header file later */

#ifdef __MMI_THEMES_V2_SUPPORT__

tm_theme_list_struct *thm_details;
U16 delete_flag = 1;
U32 setorderIDList[TOTAL_THEMES_COUNT]; /* it is only for stub testing); */
U8 g_temp_thm_index;
S16 currorderindex;                     /* this is only for set order list */

/* U8 thm_file_check=0; */
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

/* Leo add for DLT */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define MAX_URL_LIST_ENTRIES 7
/* S8 g_thm_recent_url[MAX_URL_ENTRIES][MAX_ENTER_ADDRESS_SIZE]; */
thm_nvram_download_list recent_url_list;
S8 g_thm_download_address[MAX_ENTER_ADDRESS_SIZE * ENCODING_LENGTH + ENCODING_LENGTH];
S16 g_total_recent_list;
U16 g_recent_item_index;
U8 dontSaveURLinHistory;
static U8 is_exit_from_browser;
void Add_To_URL_List(void);
void HighlightThmDownloadOption(int index);
void Edit_URL_address(void);
void theme_goto_url(void);
void preEntryThmDownload(void);
void edit_url_address(void);
void exit_url_address(void);
void thm_add_to_URL_List(void);
void entry_url_done_input_option(void);
void exit_url_done_input_option(void);
void EntryInputMethodScreen(void);
void Download2GoBackHistory(void);

extern void mmi_frm_highlight_input_method_generic(void);

#ifdef OBIGO_SUPPORT
extern void wap_entry_widget_not_ready(void);
#elif defined JATAAYU_SUPPORT
extern void mmi_brw_entry_wap_not_ready(void);
#endif 
extern S32 wap_browser_is_open(void);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
/* Leo end */

/****************************************************************************** 
* Global Function
*****************************************************************************/
#ifdef __J2ME__
extern void jvm_pause_dummy_screen(void);
extern void jvm_resume_dummy_screen(void);
#endif /* __J2ME__ */ 

extern void UpdateUITheme(void);
extern const S8 *gDefaultDLT_URL;

/* Leo add for DLT */
extern int wap_is_ready(void);
/* Leo end */
#define __MMI_THEME_AUTO_UPDATE__


/*****************************************************************************
 * FUNCTION
 *  InitThemes
 * DESCRIPTION
 *  Initialize themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitThemes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU3101_THEMES, HighlightThmMenu);
    SetHintHandler(MENU3201_UPDATE_PERIOD, mmi_theme_hint_update_period);
    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__        /* ritesh */
    ConstructThemeList();

    /* ConstructThemeOrderList(); */

    mmi_tm_activate_theme_at_bootup();
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    SetThemes(g_thm_cntx.CurrTheme);
    SetHiliteHandler(MENU_THEMES_DOWNLOAD_URL_DONE, mmi_thm_highlight_edit_url_done);
    SetHiliteHandler(MENU_THEMES_DOWNLOAD_URL_CANCEL, mmi_thm_highlight_edit_url_cancel);
    SetHiliteHandler(MENU_THEMES_DOWNLOAD_URL_INPUT_TYPE, mmi_thm_highlight_edit_url_input_type);
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    FillThemesList();
    MMI_apply_current_theme();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ /* ritesh */
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    g_total_recent_list = 0;
#endif 
    /* Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  ThemesFCBInit
 * DESCRIPTION
 *  Set calback function of alarm framework
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesFCBInit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alm_set_start_index(ALM_TYPE_THEME, ALM_THM_START);
    AlmSetExpiryTimeCB(ALM_TYPE_THEME, ThemesExpiryTimeCBH);
    AlmSetExpiryHandlerCB(ALM_TYPE_THEME, ThemeAlarmCallBack);
#ifdef __MMI_THEMES_V2_SUPPORT__
    AlmSetInitHandlerCB(ALM_TYPE_THEME, ConstructThemeOrderList, ThemesReInitQueueCBH);
#else
	AlmSetInitHandlerCB(ALM_TYPE_THEME, ReadThemesFromNVRAM, ThemesReInitQueueCBH);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  ThemesExpiryTimeCBH
 * DESCRIPTION
 *  Callback handler to get information of theme expiry setting.
 * PARAMETERS
 *  index           [IN]            
 *  alarmTime       [?]             
 *  Freq            [?]             
 *  WeekDays        [?]             
 *  MYTIME(?)       [IN/OUT]        Expiry time set by user
 *  U8(?)           [IN/OUT]        Expiry days of week
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesExpiryTimeCBH(U8 index, MYTIME *alarmTime, U8 *Freq, U8 *WeekDays, MYTIME* preReminder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *Freq = g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];
    *WeekDays = 1;
}


/*****************************************************************************
 * FUNCTION
 *  ThemesReInitQueueCBH
 * DESCRIPTION
 *  Reinit themes to alarm queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemesReInitQueueCBH(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        AlmInsertIntoQueue(ALM_THM_START, FALSE);
    }
}

extern void ExecSubLCDCurrExitHandler(void);
extern void GoBackSubLCDHistory(void);


/*****************************************************************************
 * FUNCTION
 *  SetBothLCDThemes
 * DESCRIPTION
 *  Set themes of both main and sub lcd
 * PARAMETERS
 *  index       [IN]        Index of theme
 * RETURNS
 *  void
 *****************************************************************************/
void SetBothLCDThemes(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    ExecSubLCDCurrExitHandler();
    GoBackSubLCDHistory();
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetThemes(index);
    UpdateUITheme();
    //MTK Leo add, fix theme update issue
    //      SUBLCD_RedrawCategoryFunction();
    ExecSubLCDCurrExitHandler();
    GoBackSubLCDHistory();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ConstructThemeList
 * DESCRIPTION
 *  Get the themes and construct set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_THEMES_V2_SUPPORT__
void ConstructThemeList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U8 i,j; */
    U8 no_of_setorder_themes, themecount;
    U32 *p;
    U8 set_flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    no_of_setorder_themes = GetIDList(&p, &g_thm_cntx.CurrOrderIndex);
    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();

    
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();    
    SetThemes(g_thm_cntx.CurrTheme);

    switch (no_of_setorder_themes)
    {
        case 0:
            for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
            {
                g_thm_cntx.TmpOrderList[no_of_setorder_themes] = g_thm_cntx.TotalTheme;
                g_thm_cntx.SetOrderIDList[no_of_setorder_themes] = p[no_of_setorder_themes];
            }
            break;

        default:
            for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
            {
                g_thm_cntx.SetOrderIDList[no_of_setorder_themes] = p[no_of_setorder_themes];
                for (themecount = 0; themecount < g_thm_cntx.TotalTheme; themecount++)
                {
                    if (g_thm_cntx.SetOrderIDList[no_of_setorder_themes] == 0)
                    {
                        g_thm_cntx.TmpOrderList[no_of_setorder_themes] = g_thm_cntx.TotalTheme;
                        set_flag = 1;
                        break;
                    }
                    else if (g_thm_cntx.SetOrderIDList[no_of_setorder_themes] == thm_details[themecount].theme_id)
                    {
                        g_thm_cntx.TmpOrderList[no_of_setorder_themes] = themecount;
                        set_flag = 1;
                        break;
                    }
                }
                if (set_flag == 0)
                {
                    g_thm_cntx.TmpOrderList[no_of_setorder_themes] = g_thm_cntx.TotalTheme;
                }

                set_flag = 0;
            }
    }

    for (no_of_setorder_themes = 0; no_of_setorder_themes < g_thm_cntx.TotalTheme; no_of_setorder_themes++)
    {
        g_thm_cntx.ThemeName[no_of_setorder_themes] = thm_details[no_of_setorder_themes].theme_name;
    }

    g_thm_cntx.ThemeName[g_thm_cntx.TotalTheme] = (PU8) GetString(STR_THEME_NONE);
}
#else /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  FillThemesList
 * DESCRIPTION
 *  Fill inline item selection items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FillThemesList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.TmpOrderList[0] = (S32) g_thm_cntx.CurrOrderList[0];
    g_thm_cntx.TmpOrderList[1] = (S32) g_thm_cntx.CurrOrderList[1];
    g_thm_cntx.TmpOrderList[2] = (S32) g_thm_cntx.CurrOrderList[2];
    g_thm_cntx.TmpOrderList[3] = (S32) g_thm_cntx.CurrOrderList[3];

    for (index = 0; index < g_thm_cntx.TotalTheme; index++)
    {
        g_thm_cntx.ThemeName[index] = (PU8) GetString((U16) (STR_THEME_DEFAULT + index));
    }

    g_thm_cntx.ThemeName[index] = (PU8) GetString(STR_THEME_NONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_reset_current_theme
 * DESCRIPTION
 *  delete callback function of theme menu screen.
 *  used to reset preview theme.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_thm_reset_current_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrTheme);
    }
    
    g_thm_cntx.IsInThmApp = 0;
    
    return MMI_FALSE;
    
}

#endif /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  SaveOrderThemes
 * DESCRIPTION
 *  set order themes and save in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SaveOrderThemes()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 flag = 0;

    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__
    U32 TempID;
    U8 count = 0;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo end */

#ifdef __MMI_THEMES_V2_SUPPORT__

    for (index = 0; index < g_thm_cntx.TotalTheme; index++)
    {
        TempID = thm_details[g_thm_cntx.TmpOrderList[index]].theme_id;
        if (g_thm_cntx.SetOrderIDList[index] != TempID)
        {
            flag = 1;
            break;
        }
    }

#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        if (g_thm_cntx.CurrOrderList[index] != (U8) g_thm_cntx.TmpOrderList[index])
        {
            flag = 1;
            break;
        }
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

    if (flag)   /* order changed */
    {
        g_thm_cntx.CurrOrderIndex = -1;
        /* Leo add for DLT */
        g_thm_cntx.IsOrderChanged = 1;
        /* Leo end */

    #ifdef __MMI_THEMES_V2_SUPPORT__
        for (index = 0; index < g_thm_cntx.TotalTheme; index++)
        {
            if (g_thm_cntx.TmpOrderList[index] == TOTAL_THEMES_COUNT)
            {
                g_thm_cntx.SetOrderIDList[index] = 0;
            }
            else
            {
                g_thm_cntx.SetOrderIDList[index] = thm_details[g_thm_cntx.TmpOrderList[index]].theme_id;
            }
            if (g_thm_cntx.SetOrderIDList[index] != 0)
            {
                count++;
            }
        }
    #else /* __MMI_THEMES_V2_SUPPORT__ */ 
        g_thm_cntx.CurrOrderList[0] = (S8) g_thm_cntx.TmpOrderList[0];
        g_thm_cntx.CurrOrderList[1] = (S8) g_thm_cntx.TmpOrderList[1];
        g_thm_cntx.CurrOrderList[2] = (S8) g_thm_cntx.TmpOrderList[2];
        g_thm_cntx.CurrOrderList[3] = (S8) g_thm_cntx.TmpOrderList[3];
        g_thm_cntx.IsOrderChanged = 1;
    #endif /* __MMI_THEMES_V2_SUPPORT__ */ 
        SetStartPositionofCurIndex();
        WriteThemesToNVRAM();
    #ifdef __MMI_THEMES_V2_SUPPORT__
        SetOrderIDList(g_thm_cntx.SetOrderIDList, count, g_thm_cntx.CurrOrderIndex);
    #endif 
    }
    DisplayPopup(
        (PU8) GetString(STR_THEME_OFF_UPADTE_SUCCESS),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        0);
    DeleteUptoScrID(SCR_ID_THM_OPTIONS);
    g_thm_cntx.IsInThmApp = 0;
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmSetOrder
 * DESCRIPTION
 *  Set LSK of set order list
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmSetOrder(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);    /* Force LSK label to "Ok" each time */
    SetCategory57LeftSoftkeyFunction(SaveOrderThemes);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_theme_hint_update_period
 * DESCRIPTION
 *  hint the update period menu
 * PARAMETERS
 *  index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_theme_hint_update_period(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FREQ_ALARM theme_freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    theme_freq = (FREQ_ALARM)g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod];
    
    switch (theme_freq)
    {
    case ALM_FREQ_OFF:
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_MENU3301_UPDATE_OFF));
        break;
        
    case ALM_FREQ_HOURLY:
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_MENU3302_UPDATE_HOURLY));
        break;
        
    case ALM_FREQ_EVERYDAY:
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_MENU3303_UPDATE_DAILY));
        break;

    case ALM_FREQ_WEEKLY:
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_MENU3304_UPDATE_WEEKLY));
        break;
        
    case ALM_FREQ_MONTHLY:
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_MENU_UPDATE_MONTHLY));
        break;
        
    case ALM_FREQ_SEASONALLY:
        mmi_ucs2cpy((PS8) hintData[index], (PS8) GetString(STR_MENU_UPDATE_SEASONALLY));
        break;
        
    default:
        break;
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmSetOrder
 * DESCRIPTION
 *  Entry function of set order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmSetOrder()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;        /* added for inline edit history */
    U16 inputBufferSize;    /* added for inline edit history */

    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__
    S16 i;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo end */

    EntryNewScreen(SCR_ID_THM_SET_ORDER, ExitThmSetOrder, NULL, NULL);

    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__
    g_thm_cntx.IsInThmApp = 1;
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
#else 
    g_thm_cntx.IsInThmApp = 2;
#endif 
    /* Leo end */
    
    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_THM_SET_ORDER);
    /* PMT DLT_FIXES - TK 20060306 START */
#ifndef __MMI_THEMES_V2_SUPPORT__
    if (guiBuffer == NULL)
    {
        g_thm_cntx.TmpOrderList[0] = (S32) g_thm_cntx.CurrOrderList[0];
        g_thm_cntx.TmpOrderList[1] = (S32) g_thm_cntx.CurrOrderList[1];
        g_thm_cntx.TmpOrderList[2] = (S32) g_thm_cntx.CurrOrderList[2];
        g_thm_cntx.TmpOrderList[3] = (S32) g_thm_cntx.CurrOrderList[3];
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* PMT DLT_FIXES - TK 20060306 END */
    inputBuffer = GetCurrNInputBuffer(SCR_ID_THM_SET_ORDER, &inputBufferSize);  /* added for inline edit history */
#ifdef __MMI_THEMES_V2_SUPPORT__
    if (!guiBuffer)
    {
        ConstructThemeList();
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_THEMES_V2_SUPPORT__
    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        SetInlineItemActivation(&wgui_inline_items[i], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    }

    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        SetInlineItemSelect(
            &wgui_inline_items[i],
            (g_thm_cntx.TotalTheme + 1),
            g_thm_cntx.ThemeName,
            (PS32) (&g_thm_cntx.TmpOrderList[i]));
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[2], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[0],
        (g_thm_cntx.TotalTheme + 1),
        g_thm_cntx.ThemeName,
        (PS32) (&g_thm_cntx.TmpOrderList[0]));
    SetInlineItemSelect(
        &wgui_inline_items[1],
        (g_thm_cntx.TotalTheme + 1),
        g_thm_cntx.ThemeName,
        (PS32) & g_thm_cntx.TmpOrderList[1]);
    SetInlineItemSelect(
        &wgui_inline_items[2],
        (g_thm_cntx.TotalTheme + 1),
        g_thm_cntx.ThemeName,
        (PS32) & g_thm_cntx.TmpOrderList[2]);
    SetInlineItemSelect(
        &wgui_inline_items[3],
        (g_thm_cntx.TotalTheme + 1),
        g_thm_cntx.ThemeName,
        (PS32) & g_thm_cntx.TmpOrderList[3]);
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

    RegisterHighlightHandler(HighlightThmSetOrder);

#ifdef __MMI_THEMES_V2_SUPPORT__
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, TOTAL_THEMES_COUNT + 1, inputBuffer);
    }
    ShowCategory57Screen(
        STR_MENU3202_SET_ORDER,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_thm_cntx.TotalTheme,
        (PU16) gIndexIconsImageList,
        wgui_inline_items,
        0,
        guiBuffer);
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, NO_OF_ORDERS, inputBuffer);
    }

    ShowCategory57Screen(
        STR_MENU3202_SET_ORDER,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        4,
        (PU16) gIndexIconsImageList,
        wgui_inline_items,
        0,
        guiBuffer);
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);

    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(SaveOrderThemes, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  ExitThmSetOrder
 * DESCRIPTION
 *  Exit function of set order screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitThmSetOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;    /* added for inline edit history */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    g_thm_cntx.IsInThmApp = 0;
#endif 
    h.scrnID = SCR_ID_THM_SET_ORDER;
    CloseCategory57Screen();

    h.entryFuncPtr = EntryThmSetOrder;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();    /* added for inline edit history */
    GetCategory57Data((U8*) h.inputBuffer);             /* added for inline edit history */
    AddNHistory(h, inputBufferSize);                    /* added for inline edit history */
}

#ifdef __MMI_THEMES_V2_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  ActivateDefaultTheme
 * DESCRIPTION
 *  function to activate default theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateDefaultTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_tm_activate_theme(DefaultThmID);
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    SetThemes(g_thm_cntx.CurrTheme);
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  preEntryThmDownload
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void preEntryThmDownload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
        1,
        &recent_url_list,   /* sizeof(thm_nvram_download_list) */
        NVRAM_THEMES_DOWNLOAD_SIZE,
        &error);

    EntryThmDownload();
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmDownload
 * DESCRIPTION
 *  It displays URL list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmDownload(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int number_of_items = 0, i;
    U8 *guiBuffer;

	S8 temp_list_unicode_address[MAX_ENTER_ADDRESS_SIZE * ENCODING_LENGTH + ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* U16 max_sub_menu_length= (MAX_SUB_MENU_SIZE-ENCODING_LENGTH)/ENCODING_LENGTH; */

    EntryNewScreen(SCR_ID_DOWNLOAD_ENTER_ADDRESS, NULL, EntryThmDownload, NULL);

    RegisterHighlightHandler(HighlightThmDownloadOption);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_DOWNLOAD_ENTER_ADDRESS);

    memset(subMenuData, 0, sizeof(subMenuData));
    mmi_ucs2cpy((PS8) subMenuData[number_of_items], (PS8) get_string(STR_DOWNLOAD_ENTER_ADDRESS));
    number_of_items++;
    mmi_asc_n_to_ucs2((PS8) subMenuData[number_of_items], (PS8) gDefaultDLT_URL, MAX_SUBMENU_CHARACTERS);
    number_of_items++;
    for (i = 0; number_of_items < (MAX_URL_ENTRIES + 2) && i < recent_url_list.total_entries; number_of_items++, i++)
    {
            mmi_asc_to_ucs2((S8*)temp_list_unicode_address,(S8*)recent_url_list.g_thm_recent_url[i]);
	    	mmi_ucs2ncpy(								
            (PS8) subMenuData[number_of_items],
            (PS8) temp_list_unicode_address,
            MAX_SUB_MENU_SIZE - ENCODING_LENGTH);
    }

    /* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191533 */
    ShowCategory353Screen(
        (U8*) GetString(STR_THEMES_DOWNLOAD),
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        number_of_items,
        (U8 **) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191533 */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    mmi_asc_to_ucs2((PS8) g_thm_download_address, (PS8) "http://");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_thm_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_thm_highlight_handler(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetLeftSoftkeyFunction(thm_add_to_URL_List, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
        RegisterInputMethodScreenCloseFunction(Download2GoBackHistory);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmDownloadOption
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmDownloadOption(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_recent_item_index = index;
    switch (index)
    {
        case 0:
            SetLeftSoftkeyFunction(edit_url_address, KEY_EVENT_UP);
            break;
        default:

            SetLeftSoftkeyFunction(theme_goto_url, KEY_EVENT_UP);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  edit_url_address
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void edit_url_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /* PMT DNLD_THEME_FIXES: SUKRIT START BUG# MAUI_00221134 */
    /* PMT SHARIQ DLT_PATCH 20060814 START */
    S16 required_input_modes[] = {
		INPUT_MODE_MULTITAP_LOWERCASE_ABC,
		INPUT_MODE_123,                
#ifndef __MMI_TOUCH_SCREEN__
        INPUT_MODE_SMART_UPPERCASE_ABC, 
        INPUT_MODE_SMART_LOWERCASE_ABC,
#endif
		INPUT_MODE_MULTITAP_UPPERCASE_ABC,         
        -1
    };
    /* PMT SHARIQ DLT_PATCH 20060814 END */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT DNLD_THEME_FIXES: SUKRIT END BUG# MAUI_00221134 */

	is_exit_from_browser = 0;
	EntryNewScreen(SCR_ID_DOWNLOAD_EDIT_ADDRESS, exit_url_address, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DOWNLOAD_EDIT_ADDRESS);

    /* PMT DNLD_THEME_FIXES: SUKRIT START BUG# MAUI_00221134 */
    ShowCategory5Screen_ext(
        STR_DOWNLOAD_ENTER_ADDRESS,
        GetRootTitleIcon(MENU3101_THEMES),        
        /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191533 */ STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE | INPUT_TYPE_OVERRIDE_DEFAULT | INPUT_TYPE_USE_ONLY_ENGLISH_MODES,
        (PU8) g_thm_download_address,
        MAX_ENTER_ADDRESS_SIZE + 1,
        guiBuffer,
        0,
        required_input_modes,
        NULL);
    SetLeftSoftkeyFunction(entry_url_done_input_option, KEY_EVENT_UP);
    /* PMT DNLD_THEME_FIXES: SUKRIT END BUG# MAUI_00221134 */
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  exit_url_address
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_highlight_edit_url_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    SetLeftSoftkeyFunction(thm_add_to_URL_List, KEY_EVENT_UP);    
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  exit_url_address
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_highlight_edit_url_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    SetLeftSoftkeyFunction(mmi_thm_cancel_edit_url, KEY_EVENT_UP);    
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  exit_url_address
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_highlight_edit_url_input_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);    
    SetKeyHandler(EntryAPRequiredInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_thm_goback_edit_url);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);  
}

/*****************************************************************************
 * FUNCTION
 *  exit_url_address
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_cancel_edit_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteScreenIfPresent(SCR_ID_DOWNLOAD_EDIT_ADDRESS);
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  exit_url_address
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_goback_edit_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_DOWNLOAD_EDIT_ADDRESS);    
}

/*****************************************************************************
 * FUNCTION
 *  exit_url_address
 * DESCRIPTION
 *  Exit function to edit url address screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_url_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
	S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if(!is_exit_from_browser)
	{
		currHistory.scrnID = SCR_ID_DOWNLOAD_EDIT_ADDRESS;
		currHistory.entryFuncPtr = edit_url_address;
		mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);
		GetCategoryHistory(currHistory.guiBuffer);
		AddHistory(currHistory);		
	}

}


/*****************************************************************************
 * FUNCTION
 *  Download2GoBackHistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Download2GoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBacknHistory(1);

}


/*****************************************************************************
 * FUNCTION
 *  entry_url_done_input_option
 * DESCRIPTION
 *  Entry function to download theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void entry_url_done_input_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[10];
    U16 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dontSaveURLinHistory = 0;
    EntryNewScreen(SCR_ID_DOWNLOAD_DONE_OPTION, exit_url_done_input_option, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DOWNLOAD_DONE_OPTION);
    SetParentHandler(MENU_THEMES_DOWNLOAD);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    numItems = GetNumOfChild(MENU_THEMES_DOWNLOAD);
    GetSequenceStringIds(MENU_THEMES_DOWNLOAD, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  exit_url_done_input_option
 * DESCRIPTION
 *  Exit function to download theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_url_done_input_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_DOWNLOAD_DONE_OPTION;
    currHistory.entryFuncPtr = entry_url_done_input_option;
    GetCategoryHistory(currHistory.guiBuffer);
    if (dontSaveURLinHistory != 1)
    {
        AddHistory(currHistory);
    }

}


/*****************************************************************************
 * FUNCTION
 *  thm_add_to_URL_List
 * DESCRIPTION
 *  Function to add url in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void thm_add_to_URL_List(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    signed char index = 0;
	S8 temp_thm_download_address[MAX_ENTER_ADDRESS_SIZE * ENCODING_LENGTH + ENCODING_LENGTH];
	pBOOL isValid = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2_to_asc((S8*)temp_thm_download_address, (S8*)g_thm_download_address);
    dontSaveURLinHistory = 1;
    if (g_thm_download_address != NULL)
    {
		isValid = mmi_thm_isValidUrl(temp_thm_download_address);
		if(isValid)
		{
			is_exit_from_browser = 1;			
	        if (recent_url_list.total_entries == MAX_URL_ENTRIES)
	        {
	            recent_url_list.total_entries--;
	        }
	
	        if (recent_url_list.total_entries > 0)
	        {
	            for (index = recent_url_list.total_entries - 1; index >= 0; index--)
	            {
	                strcpy(
                        (PS8) recent_url_list.g_thm_recent_url[index + 1],
						(PS8) recent_url_list.g_thm_recent_url[index]);
	
	            }
	
	        }
            strcpy((PS8) recent_url_list.g_thm_recent_url[0], (PS8) temp_thm_download_address);
	        recent_url_list.total_entries++;
	
	    /*
	     * current_index=MAX_URL_ENTRIES-1;
	     * if(g_thm_download_address!=NULL)
	     * {
	     * if(recent_url_list.total_entries<MAX_URL_ENTRIES)
	     * recent_url_list.total_entries++;
	     * current_index=recent_url_list.total_entries-1;
	     * while(current_index>0)
	     * {
	     * mmi_ucs2cpy((PS8)recent_url_list.g_thm_recent_url[current_index],(PS8)recent_url_list.g_thm_recent_url[current_index-1]);
	     * current_index--;
	     * }
	     * 
	     * mmi_ucs2cpy((PS8)recent_url_list.g_thm_recent_url[current_index],(PS8)g_thm_download_address);
	     */
	
		    WriteRecord(
		        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
		        1,
		        &recent_url_list,
		        NVRAM_THEMES_DOWNLOAD_SIZE /* sizeof(thm_nvram_download_list) */ ,
		        &error);
		    g_recent_item_index = 0;
		    theme_goto_url();
		}
		else
		{
			DisplayPopup((PU8) get_string(STR_THEME_INVALID_URL), IMG_GLOBAL_ERROR, 1, 1000, WARNING_TONE);
		}
				
	}
}


/*****************************************************************************
 * FUNCTION
 *  theme_goto_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void theme_goto_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* url[(MAX_ENTER_ADDRESS_SIZE + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_recent_item_index == 0)
    {
        mmi_asc_n_to_ucs2((S8*)url, (S8*)recent_url_list.g_thm_recent_url[g_recent_item_index], MAX_ENTER_ADDRESS_SIZE + 1);
    }
    else if (g_recent_item_index == 1)
    {
        mmi_asc_n_to_ucs2((S8*)url, (S8*)gDefaultDLT_URL, MAX_ENTER_ADDRESS_SIZE + 1);        
    }
    else
    {
        mmi_asc_n_to_ucs2((S8*)url, (S8*)recent_url_list.g_thm_recent_url[g_recent_item_index - 2], MAX_ENTER_ADDRESS_SIZE + 1);
    }
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8) url);
    DeleteUptoScrID(SCR_ID_DOWNLOAD_ENTER_ADDRESS);
}


#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  HighlightThmMenu
 * DESCRIPTION
 *  Hilite function of main themes menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryThmMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(EntryThmMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmUpdatePeriod
 * DESCRIPTION
 *  Hilite function of pupdate period
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmUpdatePeriod(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set IsSetFromMenu flag */
    g_thm_cntx.IsSetFromMenu = 1;
    g_thm_cntx.CurrHiliteItem = (U8) nIndex;

    if (nIndex > 0) /* update theme */
    {
        SetLeftSoftkeyFunction(UpdateThemePeriod, KEY_EVENT_UP);
    }
    else    /* OFF */
    {
        SetLeftSoftkeyFunction(UpdateThemeOff, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmItems
 * DESCRIPTION
 *  Highlight handler of Theme menu,
 *  function show the current selected theme
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmItems(S32 index)
{
#ifdef __MMI_THEMES_V2_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrHiliteTheme = thm_details[index].theme_id;
    g_temp_thm_index = index;
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    g_thm_cntx.CurrHiliteTheme = (U8) index;
    SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
    /* PMT VIKAS START 20050707 */
#if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    gOnFullScreen |= MMI_LEAVE_FULL_SCREEN; /* for showing the updated status bar on Theme menu. */
#endif 
    /* PMT VIKAS END 20050707 */
    /* Reset screen background layer */
    dm_set_scr_bg_redraw(MMI_TRUE); 
    RedrawCategoryFunction();
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ThmHandleRSK
 * DESCRIPTION
 *  Change theme to original one and go back history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmHandleRSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrTheme);
    }

    g_thm_cntx.IsInThmApp = 0;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  ThmRedrawTheme
 * DESCRIPTION
 *  Redraw current hilite theme in option menu to make the user preceive current
 *  selecting theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmRedrawTheme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ExitThmMenu
 * DESCRIPTION
 *  Exit function for theme menu, restore theme after exit theme screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitThmMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
        /* PMT VIKAS START 20050707 */
#if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    {
        gOnFullScreen |= MMI_LEAVE_FULL_SCREEN; /* for showing the updated status bar on Theme menu. */
#endif /* (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__) */ 
        if (IsBackHistory == MMI_TRUE)
        {
            SetBothLCDThemes(g_thm_cntx.CurrTheme);
        }
    #if (defined __MMI_MAINLCD_176X220__) && (defined __MMI_UI_DALMATIAN_STATUSBAR__)
    }
    #endif 
    /* PMT VIKAS END 20050707 */
}


/*****************************************************************************
 * FUNCTION
 *  EntryThmMenuDuringUSB
 * DESCRIPTION
 *  Show a lsit of themes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
void EntryThmMenuDuringUSB(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 i = 0;
    U16 list_icons1[MAX_SUB_MENUS];
    U16 list_icons2[MAX_SUB_MENUS];
    U8 *temp_name;
    U8 nSystemThemeCount;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_THM_MENU, ExitThmMenu, EntryThmMenu, NULL);
    nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
    if (nSystemThemeCount > MAX_SYSTEM_THEMES)
    {
        nSystemThemeCount = MAX_SYSTEM_THEMES;
    }

    for (i = 0; i < nSystemThemeCount; i++)
    {
        if (thm_details[i].theme_type == THEME_TYPE_SYSTEM)
        {
            list_icons2[i] = IMAGE_SYSTEM_THEME;
        }
        else
        {
            list_icons2[i] = 0;
        }

        if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
        {
            g_thm_cntx.CurrThemeIndex = i;
            list_icons1[i] = IMG_VICON;
        }
        else
        {
            list_icons1[i] = IMAGE_NOIMAGE_THEME;
        }

        g_thm_cntx.ThemeName[i] = (PU8) GetString((U16) (STR_THEME_DEFAULT + i));
    }
    
    g_thm_cntx.ThemeName[i] = (PU8) GetString(STR_THEME_NONE);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_THM_MENU);
    RegisterHighlightHandler(HighlightThmItems);
    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),        
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nSystemThemeCount,
        (U8 **) g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16) g_thm_cntx.CurrThemeIndex,
        guiBuffer,
        1);

    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetKeyHandler(EntryThmOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleRSK, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  EntryThmMenu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmMenu(void)
{
#ifdef __MMI_THEMES_V2_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 thm_file_check = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_usb_mode() == MMI_TRUE)
    {
        EntryThmMenuDuringUSB();
        return;
    }
    EntryNewScreen(SCR_ID_THM_MENU, ExitThmMenu, EntryThmMenu, NULL);
    ConstructThemeList();

    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();
    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
        {
            thm_file_check = 1;
        }
    }
    if (thm_file_check == 0)
    {
        ActivateDefaultTheme();
        /* PMT DLT_FIXES - TK 20060321 START */
        /* PMT DLT_FIXES - TK 20060321 END */
        reset_title_status_icon();
    #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
        ShowCategory7Screen(
            STR_SCR3001_THEMES_CAPTION,
            GetRootTitleIcon(MENU3101_THEMES),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            0,
            0,
            (U8*) GetString(STR_DEFAULT_THEME_ACTIVATION),
            NULL);
    #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
        SetLeftSoftkeyFunction(ShowThemeList, KEY_EVENT_UP);
        SetKeyHandler(ShowThemeList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        ShowThemeList();
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 

    U16 nItems;
    U8 *guiBuffer;
    U16 i = 0;
    U16 *list_icons1 = NULL;
    U16 *list_icons2 = NULL;

    g_thm_cntx.IsInThmApp = 1;

    EntryNewScreen(SCR_ID_THM_MENU, ExitThmMenu, EntryThmMenu, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_THM_MENU, (HistoryDelCBPtr)mmi_thm_reset_current_theme);

    FillThemesList();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_THM_MENU);

    nItems = (U16) g_thm_cntx.TotalTheme;
    list_icons1 = (U16*) OslMalloc(nItems * sizeof(PU16));
    list_icons2 = (U16*) OslMalloc(nItems * sizeof(PU16));

    for (i = 0; i < nItems; i++)
    {
        if (i == g_thm_cntx.CurrTheme)
        {
            list_icons1[i] = IMG_VICON;
        }
        else
        {
            list_icons1[i] = IMAGE_NOIMAGE_THEME;
        }
    }

    for (i = 0; i < nItems; i++)
    {
        list_icons2[i] = IMAGE_NOIMAGE_THEME;
    }

    RegisterHighlightHandler(HighlightThmItems);

    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        (U8 **) g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16) g_thm_cntx.CurrTheme,
        guiBuffer,
        0);

    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetKeyHandler(EntryThmOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleRSK, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);

    if (list_icons1)
    {
        OslMfree(list_icons1);
    }

    if (list_icons2)
    {
        OslMfree(list_icons2);
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ShowThemeList
 * DESCRIPTION
 *  Function to show theme list from theme application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_THEMES_V2_SUPPORT__
void ShowThemeList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 i = 0;
    U16 list_icons1[MAX_SUB_MENUS];
    U16 list_icons2[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        if (thm_details[i].theme_type == THEME_TYPE_SYSTEM)
        {
            list_icons2[i] = IMAGE_SYSTEM_THEME;
        }
        else if (thm_details[i].theme_type == THEME_TYPE_DOWNLOADED_PHONE)
        {
            list_icons2[i] = IMAGE_PHONE_THEME;
        }
        else if (thm_details[i].theme_type == THEME_TYPE_DOWNLOADED_CARD)
        {
            list_icons2[i] = IMAGE_CARD_THEME;
        }
    }

    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        list_icons1[i] = IMAGE_NOIMAGE_THEME;
        if (g_thm_cntx.CurrTheme == thm_details[i].theme_id)
        {
            g_thm_cntx.CurrThemeIndex = i;
            list_icons1[i] = IMG_VICON;
        }
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_THM_MENU);
    RegisterHighlightHandler(HighlightThmItems);
    ShowCategory73Screen(
        STR_MENU3101_THEMES,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_thm_cntx.TotalTheme,
        (U8 **) g_thm_cntx.ThemeName,
        list_icons1,
        list_icons2,
        (U16) g_thm_cntx.CurrThemeIndex,
        guiBuffer,
        1);

    SetLeftSoftkeyFunction(EntryThmOptions, KEY_EVENT_UP);
    SetKeyHandler(EntryThmOptions, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(ThmHandleRSK, KEY_EVENT_UP);
    SetKeyHandler(ThmHandleRSK, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_card_plug_out_hdlr
 * DESCRIPTION
 *  callback handler of plug out memory card
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_card_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* theme may be set in fmgr */
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();
    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
        {
            if (thm_details[i].theme_type == THEME_TYPE_DOWNLOADED_CARD &&
                g_thm_cntx.CurrTheme == thm_details[i].theme_id)
            {
                ActivateDefaultTheme();
            }
        }

}

#endif /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  ThmHandleEndKey
 * DESCRIPTION
 *  Function handle end key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThmHandleEndKey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrTheme);
    }

    g_thm_cntx.IsInThmApp = 0;
    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightThmOption
 * DESCRIPTION
 *  Highlight handler of theme menu
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightThmOption(S32 nIndex)
{
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_tm_get_usb_mode() || mmi_bootup_is_sim_removed() || !mmi_bootup_is_network_service_available()
#ifdef __FLIGHT_MODE_SUPPORT__
         || mmi_bootup_get_active_flight_mode()
#endif 
        ) && nIndex == 3)
    {
        nIndex++;
    }
    switch (nIndex)
    {
        case 0:
            SetLeftSoftkeyFunction(ActivateTheme, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case 1:
            SetLeftSoftkeyFunction(EntryThmUpdatePeriod, KEY_EVENT_UP);
            SetKeyHandler(EntryThmUpdatePeriod, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case 2:
            SetLeftSoftkeyFunction(EntryThmSetOrder, KEY_EVENT_UP);
            SetKeyHandler(EntryThmSetOrder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case 3:
            SetLeftSoftkeyFunction(preEntryThmDownload, KEY_EVENT_UP);
            SetKeyHandler(EntryThmDownload, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case 4:
            SetLeftSoftkeyFunction(ThemeDeleteConfirmation, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
    }
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    switch (nIndex)
    {
        case 0:
            SetLeftSoftkeyFunction(ActivateTheme, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case 1:
            SetLeftSoftkeyFunction(EntryThmUpdatePeriod, KEY_EVENT_UP);
            SetKeyHandler(EntryThmUpdatePeriod, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;

        case 2:
            SetLeftSoftkeyFunction(EntryThmSetOrder, KEY_EVENT_UP);
            SetKeyHandler(EntryThmSetOrder, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
    }
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  EntryThmOptions
 * DESCRIPTION
 *  Entry func of themes option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmOptions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *theme_hint[16];
    U8 *guiBuffer;
    U16 ItemList[16];
    U16 nItems;

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    /* PMT DLT_FIXES - TK 20060321 START */
    U8 *temp_name;
    U8 nSystemThemeCount;
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT DLT_FIXES - TK 20060321 END */

    EntryNewScreen(SCR_ID_THM_OPTIONS, NULL, EntryThmOptions, NULL);

    ThmRedrawTheme();

#ifndef __MMI_THEMES_V2_SUPPORT__
    g_thm_cntx.IsInThmApp = 2;
#endif 

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (g_thm_cntx.CurrHiliteTheme == g_thm_cntx.CurrTheme)
    {
        /* PMT DNLD_THEME_FIXES: SUKRIT START BUG# MAUI_00221092 */
        if (!mmi_bootup_is_sim_valid() || !mmi_bootup_is_network_service_available()
    #ifdef __FLIGHT_MODE_SUPPORT__
            || mmi_bootup_get_active_flight_mode()
    #endif 
            )
        {
            nItems = GetNumOfChild(MENU3001_THEMES_LIST_1_FLIGHTMODE);
            GetSequenceStringIds(MENU3001_THEMES_LIST_1_FLIGHTMODE, ItemList);
        }
        else
        {
            nItems = GetNumOfChild(MENU3001_THEMES_LIST_1);
            GetSequenceStringIds(MENU3001_THEMES_LIST_1, ItemList);
        }
        /* PMT DNLD_THEME_FIXES: SUKRIT END BUG# MAUI_00221092 */
    }
    else
    {
        /* PMT DLT_FIXES - TK 20060321 START */
        nSystemThemeCount = (U8) GetThemesNames((U8 ***) & temp_name);
        if (nSystemThemeCount > MAX_SYSTEM_THEMES)
        {
            nSystemThemeCount = MAX_SYSTEM_THEMES;
        }

        if (g_temp_thm_index < nSystemThemeCount)
            /* PMT DLT_FIXES - TK 20060321 START */
        {
            /* PMT DNLD_THEME_FIXES: SUKRIT START BUG# MAUI_00221092 */
            if (mmi_bootup_is_sim_removed() || !mmi_bootup_is_network_service_available()
        #ifdef __FLIGHT_MODE_SUPPORT__
                || mmi_bootup_get_active_flight_mode()
        #endif 
                )
            {
                nItems = GetNumOfChild(MENU3001_THEMES_LIST_1_FLIGHTMODE);
                GetSequenceStringIds(MENU3001_THEMES_LIST_1_FLIGHTMODE, ItemList);

            }
            else
            {
                nItems = GetNumOfChild(MENU3001_THEMES_LIST_1);
                GetSequenceStringIds(MENU3001_THEMES_LIST_1, ItemList);
            }
            /* PMT DNLD_THEME_FIXES: SUKRIT END BUG# MAUI_00221092 */
        }
        else
        {
            /* PMT DNLD_THEME_FIXES: SUKRIT START BUG# MAUI_00221092 */
            if (mmi_bootup_is_sim_removed() || !mmi_bootup_is_network_service_available()
        #ifdef __FLIGHT_MODE_SUPPORT__
                || mmi_bootup_get_active_flight_mode()
        #endif 
                )
            {
                nItems = GetNumOfChild(MENU3001_THEMES_LIST_FLIGHTMODE);
                GetSequenceStringIds(MENU3001_THEMES_LIST_FLIGHTMODE, ItemList);

            }
            else
            {
                nItems = GetNumOfChild(MENU3001_THEMES_LIST);
                GetSequenceStringIds(MENU3001_THEMES_LIST, ItemList);
            }
            /* PMT DNLD_THEME_FIXES: SUKRIT END BUG# MAUI_00221092 */
        }
    }
    if (mmi_tm_get_usb_mode() == MMI_TRUE)
    {
        nItems = NO_OF_THEME_OPTION_MENUITEMS_IN_USB_MODE;  /* First Menuitem active, Second Update Period no other menu items */

    }
#else /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 
    nItems = GetNumOfChild(MENU3001_THEMES_LIST);
    GetSequenceStringIds(MENU3001_THEMES_LIST, ItemList);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */     
    SetParentHandler(MENU3001_THEMES_LIST);
    RegisterHighlightHandler(HighlightThmOption);
    
    ConstructHintsList(MENU3001_THEMES_LIST, theme_hint);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_THM_OPTIONS);

    RegisterHighlightHandler(HighlightThmOption);
    
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (PU16) gIndexIconsImageList,
        theme_hint,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
* FUNCTION
*  mmi_thm_create_freq_table
* DESCRIPTION
*   This fuction builds the display information of the selected alarm, and then enter
*  alarm screen.
* PARAMETERS
*  None.
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
/* void mmi_thm_create_freq_table(void)
   {
   g_themes_freq_set.AlmFreqSet[0] = OFF;
   g_themes_freq_set.AlmFreqSet[1] = HOURLY ;
   g_themes_freq_set.AlmFreqSet[2] = EVERYDAY;
   g_themes_freq_set.AlmFreqSet[3] = WEEKLY;
   g_themes_freq_set.AlmFreqSet[4] = MONTHLY;
   g_themes_freq_set.AlmFreqSet[5] = SEASONALLY;
   } */


/*****************************************************************************
 * FUNCTION
 *  EntryThmUpdatePeriod
 * DESCRIPTION
 *  entry func of themes update period menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryThmUpdatePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_THM_UPDATE_PERIOD, ExitThmUpdatePeriod, NULL, NULL);

#ifdef __MMI_THEMES_V2_SUPPORT__
    g_thm_cntx.IsInThmApp = 1;
#else 
    g_thm_cntx.IsInThmApp = 2;
#endif 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_THM_UPDATE_PERIOD);
    nItems = GetNumOfChild(MENU3201_UPDATE_PERIOD);
    GetSequenceStringIds(MENU3201_UPDATE_PERIOD, ItemList);
    SetParentHandler(MENU3201_UPDATE_PERIOD);

    RegisterHighlightHandler(HighlightThmUpdatePeriod);

    ShowCategory11Screen(
        STR_SCR3003_UPDATE_PERIOD_CAPTION,
        GetRootTitleIcon(MENU3101_THEMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        (U16) g_thm_cntx.CurrUpdatePeriod,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  ExitThmUpdatePeriod
 * DESCRIPTION
 *  Exit func of themes update period menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitThmUpdatePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset IsSetFromMenu flag */
#ifdef __MMI_THEMES_V2_SUPPORT__
    g_thm_cntx.IsInThmApp = 0;
#endif 
    g_thm_cntx.IsSetFromMenu = 0;

    h.scrnID = SCR_ID_THM_UPDATE_PERIOD;
    h.entryFuncPtr = EntryThmUpdatePeriod;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    GetCategoryHistory(h.guiBuffer);
    AddHistory(h);
}


/*****************************************************************************
 * FUNCTION
 *  ActivateTheme
 * DESCRIPTION
 *  Activate theme select bu yser and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateTheme()
{
#ifdef __MMI_THEMES_V2_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(0, NULL, NULL, NULL);
    ShowCategory66Screen(
        STR_SCR3001_THEMES_CAPTION,
        GetRootTitleIcon(MENU3101_THEMES),
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_DLT_THM_PROGRESS),
        IMG_THEME_ACTIVATION,
        NULL);

    result = mmi_tm_activate_theme(g_thm_cntx.CurrHiliteTheme);

    if (result == THEME_ERROR_SUCCESS)
    {
        g_thm_cntx.CurrTheme = g_thm_cntx.CurrHiliteTheme;
        g_thm_cntx.CurrThemeIndex = g_temp_thm_index;
        SetThemes(g_thm_cntx.CurrTheme);
        if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
        {
            SetStartPositionofCurIndex();
        }
        SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
        arrange_status_icons();
    }
    mmi_thm_display_error_msg(result);

    if (result == THEME_ERROR_SUCCESS)
    {
        DeleteUptoScrID(SCR_ID_THM_MENU);
    }

    g_thm_cntx.IsInThmApp = 0;

#else /* __MMI_THEMES_V2_SUPPORT__ */ 

    if (g_thm_cntx.CurrHiliteTheme != g_thm_cntx.CurrTheme)
    {
        SetBothLCDThemes(g_thm_cntx.CurrHiliteTheme);
        g_thm_cntx.CurrTheme = g_thm_cntx.CurrHiliteTheme;

        if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
        {
            SetStartPositionofCurIndex();
        }

        WriteThemesToNVRAM();
    }

    DisplayPopup(
        (PU8) GetString(STR_THEME_ACTIVATE_SUCCESS),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        0);
    DeleteUptoScrID(SCR_ID_THM_MENU);
    g_thm_cntx.IsInThmApp = 0;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  ThemeDeleteConfirmation
 * DESCRIPTION
 *  Function for theme delete confirmation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeDeleteConfirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str[100];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucs2cpy((PS8) str, (PS8) get_string(STR_GLOBAL_DELETE));
    mmi_ucs2cat((PS8) str, (PS8) L" ");
    mmi_ucs2cat((PS8) str, (PS8) g_thm_cntx.ThemeName[g_temp_thm_index]);
    mmi_ucs2cat((PS8) str, (PS8) L"?");
    
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) str,
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(DeleteTheme, KEY_EVENT_UP);
    SetKeyHandler(DeleteTheme, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetKeyHandler(ThmHandleEndKey, KEY_END, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  DeleteTheme
 * DESCRIPTION
 *  Function to delete a theme from theme application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeleteTheme()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tm_theme_error_enum result;
    S32 error_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_tm_delete_theme(g_thm_cntx.CurrHiliteTheme, &error_type);
    if (result == THEME_ERROR_SUCCESS)
    {
        UpdateOrder(g_thm_cntx.CurrHiliteTheme);
        DisplayPopup(
                (PU8) GetString(STR_GLOBAL_DONE),
                IMG_GLOBAL_ACTIVATED,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                SUCCESS_TONE);
    }        
    else
    {
        DisplayPopup(
                    (PU8) GetString(GetFileSystemErrorString(error_type)),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    1000,
                    ERROR_TONE);
    }
    
    DeleteUptoScrID(SCR_ID_THM_MENU);
}


/*****************************************************************************
 * FUNCTION
 *  UpdateOrder
 * DESCRIPTION
 *  Function to update set order during deletion
 * PARAMETERS
 *  thm_del_ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateOrder(U32 thm_del_ID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U8 count = 0;
    U16 tmpidlist[TOTAL_THEMES_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();

    if (g_thm_cntx.CurrTheme == thm_del_ID)
    {
        g_thm_cntx.CurrTheme = DefaultThmID;
        g_thm_cntx.CurrThemeIndex = DefaultThmIndex;
    }

    for (i = 0; i <= g_thm_cntx.CurrOrderIndex; i++)
    {
        if (thm_del_ID == g_thm_cntx.SetOrderIDList[i])
        {
            count++;
        }
    }
    if (g_thm_cntx.CurrOrderIndex >= count)
    {
        g_thm_cntx.CurrOrderIndex = g_thm_cntx.CurrOrderIndex - count;
    }
    count = 0;

    for (i = 0; i < g_thm_cntx.TotalTheme + 1; i++)
    {
        if (thm_del_ID != g_thm_cntx.SetOrderIDList[i])
        {
            tmpidlist[count] = g_thm_cntx.SetOrderIDList[i];
            count++;
        }
    }
    for (i = 0; i <= count; i++)
    {
        g_thm_cntx.SetOrderIDList[i] = tmpidlist[i];

    }
    for (i = count; i < g_thm_cntx.TotalTheme; i++)
    {

        g_thm_cntx.SetOrderIDList[i] = 0;

    }

    SetOrderIDList(g_thm_cntx.SetOrderIDList, count, g_thm_cntx.CurrOrderIndex);
    WriteThemesToNVRAM();
}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  UpdateThemeOff
 * DESCRIPTION
 *  Cancel the update alarm set by user and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemeOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrOrderIndex = -1;
    g_thm_cntx.IsOrderChanged = 0;

    /* if previous setting is not off, some theme-alarm is set before, cancel the alarm */
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        AlmCancelAlarm(ALM_THM_START);
    }

    g_thm_cntx.CurrUpdatePeriod = mmi_alm_get_freq_order(THMEM_FREQ_NUM, g_themes_freq_set, ALM_FREQ_OFF);

    WriteThemesToNVRAM();

    DisplayPopup(
        (PU8) GetString(STR_THEME_OFF_UPADTE_SUCCESS),
        IMG_GLOBAL_ACTIVATED,
        TRUE,
        UI_POPUP_NOTIFYDURATION_TIME,
        0);
    DeleteUptoScrID(SCR_ID_THM_OPTIONS);
    g_thm_cntx.IsInThmApp = 0;
}

/* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */


/*****************************************************************************
 * FUNCTION
 *  AlarmExpireUpdateThemeOff
 * DESCRIPTION
 *  Sets the update theme alarm to off when no theme is present in set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void AlarmExpireUpdateThemeOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.CurrOrderIndex = -1;
    g_thm_cntx.IsOrderChanged = 0;

    /* if previous setting is not off, some theme-alarm is set before, cancel the alarm */
    if (g_thm_cntx.CurrUpdatePeriod > 0)
    {
        AlmCancelAlarm(ALM_THM_START);
    }

    g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;

    WriteThemesToNVRAM();

    g_thm_cntx.IsInThmApp = 0;
}

/* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */


/*****************************************************************************
 * FUNCTION
 *  UpdateThemePeriod
 * DESCRIPTION
 *  Set update period and write to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemePeriod(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
#ifdef __MMI_THEMES_V2_SUPPORT__

    if (g_thm_cntx.IsSetFromMenu == 1 && g_thm_cntx.CurrHiliteItem != g_thm_cntx.CurrUpdatePeriod)
    {
        g_thm_cntx.CurrUpdatePeriod = g_thm_cntx.CurrHiliteItem;
        g_thm_cntx.IsOrderChanged = 1;
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (g_thm_cntx.IsSetFromMenu == 1)
    {
        g_thm_cntx.CurrUpdatePeriod = g_thm_cntx.CurrHiliteItem;
        g_thm_cntx.IsOrderChanged = 1;
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    SetStartPositionofCurIndex();

    WriteThemesToNVRAM();

    AlmSetAlarm(ALM_THM_START);

    if (g_thm_cntx.IsSetFromMenu == 1)  /* not OFF */
    {
        DisplayPopup(
            (PU8) GetString(STR_THEME_OFF_UPADTE_SUCCESS),
            IMG_GLOBAL_ACTIVATED,
            TRUE,
            UI_POPUP_NOTIFYDURATION_TIME,
            SUCCESS_TONE);
        DeleteUptoScrID(SCR_ID_THM_OPTIONS);
        g_thm_cntx.IsInThmApp = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ThemeAlarmCallBack
 * DESCRIPTION
 *  Call back function when theme alarm expires
 * PARAMETERS
 *  index           [IN]        
 *  period          [?]         
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 ThemeAlarmCallBack(U8 index, U16 *period, BOOL power_on)
{
#ifdef __J2ME__
	U8 IsJavaPlaying = FALSE;
#endif	

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_THEMES_V2_SUPPORT__
    U8 no_of_times, result=THEME_ERROR_FAILURE;
    U16 order_theme_id, count, start_index;
    U32 *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00221092 */
    if (mmi_tm_get_usb_mode() == MMI_TRUE)
    {
        mmi_tm_set_was_theme_alarm_cb();
        *period = ALM_WITHOUD_EXPIRY_PERIOD;
        return ALM_HAS_NO_IND;
    }

    count = GetIDList(&p, &g_thm_cntx.CurrOrderIndex);
    g_thm_cntx.CurrTheme = mmi_tm_get_current_theme_id();

    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();
    for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
    {
        g_thm_cntx.SetOrderIDList[no_of_times] = p[no_of_times];
    }

    start_index = g_thm_cntx.CurrOrderIndex;
    if (start_index >= g_thm_cntx.TotalTheme)
    {
        start_index = 0;
    }
    /* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00191466 */
    if (count == 0)
    {
        AlarmExpireUpdateThemeOff();
    }
    /* PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00191466 */
    else
        /* Fix for dodge ball game */
    {
	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671	
	#ifdef __J2ME__
        if (GetActiveScreenId() == SCR_JAVA_APP)
        {
            IsJavaPlaying = TRUE;
            jvm_pause_dummy_screen();
        }
    #endif /* __J2ME__ */ 
	//PMT DNLD FIXES 20060513: SUKRIT END MAUI_00192671

        for (no_of_times = 0; no_of_times < g_thm_cntx.TotalTheme; no_of_times++)
        {
            if ((g_thm_cntx.CurrOrderIndex == (g_thm_cntx.TotalTheme) - 1) ||
                g_thm_cntx.CurrOrderIndex >= g_thm_cntx.TotalTheme)
            {
                g_thm_cntx.CurrOrderIndex = 0;
            }
            else
            {
                g_thm_cntx.CurrOrderIndex++;
            }

            /* There's no theme to updated */
            if (g_thm_cntx.CurrOrderIndex == start_index)
            {
                *period = ALM_WITHOUD_EXPIRY_PERIOD;
                return ALM_HAS_NO_IND;
            }

            order_theme_id = g_thm_cntx.SetOrderIDList[g_thm_cntx.CurrOrderIndex];

            /* if current order theme is "none" */
            if (order_theme_id != 0 && order_theme_id != g_thm_cntx.CurrTheme)
            {
                break;
            }
        }

        /* Update theme */
        if (!g_alm_frm_cntx.IsPwronAlarm)
        {
            if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
            {
                /* To exit previous screen, error case: multimedia screen will allocate lots of memory, and then the cache wallpaper will fail */
                /* 2006/12/31 */
                EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
                result = mmi_tm_activate_theme(order_theme_id); /* PMT TM Coding Conventions - MOHD SHARIQ 20060406 */

                if (result == THEME_ERROR_SUCCESS)
                {
                    g_thm_cntx.CurrTheme = order_theme_id;
                    SetThemes(g_thm_cntx.CurrTheme);
                    DisplayPopup(
                        (PU8) GetString(STR_THEMES_ALARM_ACTIVATION),
                        IMG_GLOBAL_ACTIVATED,
                        TRUE,
                        UI_POPUP_NOTIFYDURATION_TIME_2000,
                        SUCCESS_TONE);
                    /* MAUI_00019098_Patch_01 Start */
                    if (GetCurrScrnId() == SCR_WALLPAPER_VIEW)
                    {
                        DeleteUptoScrID(SCR_IDLE_SCR_DISP);
                    }
                    /* MAUI_00019098_Patch_01 End */
                    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                }
                else
                {
                    mmi_thm_display_error_msg(result);
                    SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                }
            }
        }
        else
        {
            result = mmi_tm_activate_theme(order_theme_id);
            /* PMT SUKRIT START PMTSW00006364 */
            if (result == THEME_ERROR_SUCCESS)
            {
                g_thm_cntx.CurrTheme = order_theme_id;
                /* PMT SUKRIT END PMTSW00006364 */
                SetThemes(g_thm_cntx.CurrTheme);
                SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
                /* PMT SUKRIT START PMTSW00006364 */
            }
            /* PMT SUKRIT END PMTSW00006364 */
        }

	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671
	#ifdef __J2ME__
		if(IsJavaPlaying == TRUE)
		{
			if(result != THEME_ERROR_SUCCESS)
			{
                        jvm_resume_dummy_screen();
			}
		}
	#endif
	//PMT DNLD FIXES 20060513: SUKRIT START MAUI_00192671
	}

    /* Leo add for DLT */
    WriteThemesToNVRAM();
    /* Leo end */
#else /* __MMI_THEMES_V2_SUPPORT__ */ 

    U8 no_of_times;
    U8 order_theme;

	/* check the theme in the orderlist , if all are empty, update the period*/
	if (g_thm_cntx.CurrOrderList[0] == 3 &&
		g_thm_cntx.CurrOrderList[1] == 3 &&
		g_thm_cntx.CurrOrderList[2] == 3 &&
		g_thm_cntx.CurrOrderList[3] == 3)
	{
		AlarmExpireUpdateThemeOff();
	}
	else
	{
	    /* find the next index of theme to be updated */
	    for (no_of_times = 0; no_of_times < NO_OF_ORDERS; no_of_times++)
	    {
	        /* move order to next one */
	        if (g_thm_cntx.CurrOrderIndex == (NO_OF_ORDERS) - 1)
	        {
	            g_thm_cntx.CurrOrderIndex = 0;
	        }
	        else
	        {
	            g_thm_cntx.CurrOrderIndex++;
	        }

	        order_theme = g_thm_cntx.CurrOrderList[g_thm_cntx.CurrOrderIndex];

	        /* if found theme different to current one, found the first one */
	        if (order_theme != g_thm_cntx.CurrTheme && order_theme < g_thm_cntx.TotalTheme)
	        {
	            break;
	        }
	    }
#ifdef __J2ME__
	    if (GetActiveScreenId() == SCR_JAVA_APP)
	    {
	        IsJavaPlaying = TRUE;
	        jvm_pause_dummy_screen();
	    }
#endif /* __J2ME__ */ 
	    if (no_of_times < NO_OF_ORDERS)
	    {
	        g_thm_cntx.CurrTheme = order_theme;
	        WriteThemesToNVRAM();

	        if (!g_alm_frm_cntx.IsPwronAlarm)
	        {
	            if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
	            {
	                SetThemes(g_thm_cntx.CurrTheme);
	                DisplayPopup(
                        (PU8) GetString(STR_THEMES_ALARM_ACTIVATION),
                        IMG_GLOBAL_ACTIVATED,
                        TRUE,
                        UI_POPUP_NOTIFYDURATION_TIME_2000,
                        SUCCESS_TONE);
	                //MTK Leo add, fix theme update issue
	                // EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
	                // GoBackHistory();
	            }
	            else if (g_thm_cntx.IsInThmApp == 1)
	            {
	                DisplayPopup(
                        (PU8) GetString(STR_THEMES_ALARM_ACTIVATION),
                        IMG_GLOBAL_ACTIVATED,
                        TRUE,
                        UI_POPUP_NOTIFYDURATION_TIME_2000,
                        SUCCESS_TONE);                

	                //ClearExitHandler();
	                //EntryThmMenu();
	            }
	            order_theme++;
	        }
	        else
	        {
	            SetThemes(g_thm_cntx.CurrTheme);
	        }
	    }
#ifdef __J2ME__
	    if (IsJavaPlaying == TRUE)
	    {
	        jvm_resume_dummy_screen();
	    }
#endif /* __J2ME__ */ 
	}
	WriteThemesToNVRAM();
	
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* Leo add for DLT */
    /* WriteThemesToNVRAM(); */
    /* Leo end */
    *period = ALM_WITHOUD_EXPIRY_PERIOD;
    return ALM_HAS_NO_IND;
}


/*****************************************************************************
 * FUNCTION
 *  ReadThemesFromNVRAM
 * DESCRIPTION
 *  Read theme settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ReadThemesFromNVRAM(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Leo add for DLT */
#ifndef __MMI_THEMES_V2_SUPPORT__
    S16 error = 0;
    U8 index = 0;
    U8 *temp_name;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize global contex */
    memset(&g_thm_cntx, 0, sizeof(g_thm_cntx));
    g_thm_cntx.TotalTheme = (U8) GetThemesNames((U8 ***) & temp_name);

    ReadRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, 8, &error);

    /* to present abonromal case of NVRAM default value */
    if (nvram_theme.freq_type > ALM_FREQ_SEASONALLY)
    {
        g_thm_cntx.CurrUpdatePeriod = ALM_FREQ_OFF;
    }
    else
    {
        g_thm_cntx.CurrUpdatePeriod = (U8) (nvram_theme.freq_type);
    }

    g_thm_cntx.CurrTheme = nvram_theme.current_theme_index;

    /* set order list */
    if (nvram_theme.set_order_flag >= -1)    /* order has be set before */
    {
        g_thm_cntx.IsOrderChanged = 1;

        g_thm_cntx.CurrOrderIndex = nvram_theme.set_order_flag;

        for (index = 0; index < NO_OF_ORDERS; index++)
        {
            g_thm_cntx.CurrOrderList[index] = nvram_theme.themes_order[index];
        }
    }
    else
    {
        g_thm_cntx.IsOrderChanged = 0;
        g_thm_cntx.CurrOrderIndex = 0;
        for (index = 0; index < NO_OF_ORDERS; index++)
        {
            g_thm_cntx.CurrOrderList[index] = index;
        }
    }

    /* set and apply current theme */
    if (g_thm_cntx.CurrTheme >= g_thm_cntx.TotalTheme)
    {
        g_thm_cntx.CurrOrderIndex = 0;
        g_thm_cntx.CurrTheme = 0;
    }

    SetThemes(g_thm_cntx.CurrTheme);
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  ConstructThemeOrderList
 * DESCRIPTION
 *  function to construct themes order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_THEMES_V2_SUPPORT__
void ConstructThemeOrderList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 index = 0;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialize global contex */

    g_thm_cntx.TotalTheme = mmi_tm_get_total_themes_count();
#if (defined(__MMI_THEMES_V2_SUPPORT__) || defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))        /* ritesh */
    ReadRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, 96, &error);
#endif 

    g_thm_cntx.CurrUpdatePeriod = (U8) (nvram_theme.freq_type);

    /* set order list */
    if (nvram_theme.set_order_flag >= -1)    /* order has be set before */
    {
        g_thm_cntx.IsOrderChanged = 1;
        g_thm_cntx.CurrOrderIndex = nvram_theme.set_order_flag;
        currorderindex = (U8) nvram_theme.set_order_flag;

        for (index = 0; index < TOTAL_THEMES_COUNT; index++)    /* ritesh */
        {
            /* g_thm_cntx.CurrOrderList[index] = nvram_theme.themes_order[index]; */
            setorderIDList[index] = nvram_theme.themes_order[index];
        }
    }
    else
    {
        g_thm_cntx.IsOrderChanged = 0;
    }

    /* set and apply current theme */
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  WriteThemesToNVRAM
 * DESCRIPTION
 *  write theme settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void WriteThemesToNVRAM()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    S16 error = 0;
    thm_nvram_struct nvram_theme;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_THEMES_V2_SUPPORT__
    nvram_theme.freq_type = g_thm_cntx.CurrUpdatePeriod;
#else 
    nvram_theme.freq_type = g_thm_cntx.CurrUpdatePeriod;
#endif 
    if (g_thm_cntx.IsOrderChanged == 1)
#ifdef __MMI_THEMES_V2_SUPPORT__
        nvram_theme.set_order_flag = currorderindex;    /* changes made on saturday 09/04/05 */
#else 
        nvram_theme.set_order_flag = g_thm_cntx.CurrOrderIndex;
#endif 

    if (g_thm_cntx.IsOrderChanged == 0)
    {
        nvram_theme.set_order_flag = -1;
    }

#ifndef __MMI_THEMES_V2_SUPPORT__
    if (g_thm_cntx.CurrTheme < g_thm_cntx.TotalTheme)
    {
        nvram_theme.current_theme_index = (U8) g_thm_cntx.CurrTheme;
    }
    else
    {
        g_thm_cntx.CurrTheme = nvram_theme.current_theme_index = 0;
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#ifdef __MMI_THEMES_V2_SUPPORT__
    for (index = 0; index < TOTAL_THEMES_COUNT; index++)    /* ritesh */
    {
        nvram_theme.themes_order[index] = setorderIDList[index];
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        nvram_theme.themes_order[index] = g_thm_cntx.CurrOrderList[index];
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 

#if (defined(__MMI_THEMES_V2_SUPPORT__) || defined(__MMI_DOWNLOADABLE_THEMES_SUPPORT__))        /* ritesh */
    WriteRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, 96, &error);
#else 
    WriteRecord(NVRAM_EF_THEMES_VALUES, 1, &nvram_theme, 8, &error);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  UpdateThemeAlarm
 * DESCRIPTION
 *  Call by settings application when time/date change
 *  and set the alam of update theme according to current time/date
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateThemeAlarm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_thm_cntx.IsSetFromMenu = 0;

    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF) /* not OFF */
    {
        UpdateThemePeriod();
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetStartPositionofCurIndex
 * DESCRIPTION
 *  set the starting position of update order index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetStartPositionofCurIndex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0, flag = 0;
    U8 curr_order;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    if (g_thm_cntx.CurrOrderIndex < 0 || g_thm_cntx.CurrOrderIndex >= TOTAL_THEMES_COUNT)
#else 
    if (g_thm_cntx.CurrOrderIndex < 0)
#endif 
        curr_order = 0;
    else
    {
        curr_order = (U8) g_thm_cntx.CurrOrderIndex;
    }

    /* find the position of current selected theme */
#ifdef __MMI_THEMES_V2_SUPPORT__
    for (index = 0; index < g_thm_cntx.TotalTheme; index++) /* ritesh */
    {
        if (g_thm_cntx.SetOrderIDList[curr_order] == g_thm_cntx.CurrTheme)
        {
            flag = 1;
            break;
        }
        if (curr_order == (g_thm_cntx.TotalTheme) - 1)
        {
            curr_order = 0;
        }
        else
        {
            curr_order++;
        }
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    for (index = 0; index < NO_OF_ORDERS; index++)
    {
        if (g_thm_cntx.CurrOrderList[curr_order] == g_thm_cntx.CurrTheme)
        {
            flag = 1;
            break;
        }

        if (curr_order == (NO_OF_ORDERS) - 1)
        {
            curr_order = 0;
        }
        else
        {
            curr_order++;
        }
    }
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
    if (flag == 1)  /* it's in the list */
    {
        g_thm_cntx.CurrOrderIndex = curr_order;
        g_thm_cntx.IsOrderChanged = 1;
    }
    else
    {
        g_thm_cntx.CurrOrderIndex = -1;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ATSetTheme
 * DESCRIPTION
 *  To change theme setting from AT command
 * PARAMETERS
 *  index       [IN]        Index of theme to be set
 * RETURNS
 *  void
 *****************************************************************************/
BOOL ATSetTheme(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* added by ritesh for V2 support */
#ifdef __MMI_THEMES_V2_SUPPORT__
    U16 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_thm_cntx.IsInThmApp == 0)
    {
        mmi_tm_get_themes(&thm_details);
        result = mmi_tm_activate_theme(thm_details[index].theme_id);    /* PMT TM Coding Conventions - MOHD SHARIQ 20060406 */
        SetThemes(g_thm_cntx.CurrTheme);

        if (result == THEME_ERROR_SUCCESS)
        {
            g_thm_cntx.CurrTheme = thm_details[index].theme_id;
            if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
            {
                SetStartPositionofCurIndex();
            }
            SetCurrOrderIndex(g_thm_cntx.CurrOrderIndex);
        }
        mmi_thm_display_error_msg(result);
        if (result == THEME_ERROR_SUCCESS)
        {
            DeleteUptoScrID(SCR_ID_THM_MENU);
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }

        WriteThemesToNVRAM();
    }
    else
    {
        return MMI_FALSE;
    }
#else /* __MMI_THEMES_V2_SUPPORT__ */ 
    /* index exceeds boundary or theme is not changed */
    if (index >= g_thm_cntx.TotalTheme || index == g_thm_cntx.CurrTheme)
    {
        return MMI_FALSE;
    }

    g_thm_cntx.CurrTheme = index;

    /* reset postion index of update period */
    if (g_themes_freq_set[g_thm_cntx.CurrUpdatePeriod] != ALM_FREQ_OFF)
    {
        SetStartPositionofCurIndex();
    }

    /* write change to NVRAM */
    WriteThemesToNVRAM();

    /* change theme */
    if (g_thm_cntx.IsInThmApp == 0) /* is not in theme menu */
    {
        SetBothLCDThemes(index);
        /* MTK Leo add, fix theme update issue */
        EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        GoBackHistory();
    }
    else if (g_thm_cntx.IsInThmApp == 1)
    {
        /* SetExitHandler(SCR_ID_THM_MENU, NULL); */
        ClearExitHandler();
        EntryThmMenu();
    }

    return MMI_TRUE;
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
}

#ifdef __MMI_THEMES_V2_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  SetOrderIDList
 * DESCRIPTION
 *  To construct set order ID list
 * PARAMETERS
 *  IDList              [?]         
 *  SetNoOfThemes       [IN]        
 *  index               [IN]        Of the activated theme
 *  three:(?)
 *  pointer to array of ID list(?)
 *  total no of themes in set order list(?)
 * RETURNS
 *  void
 *****************************************************************************/
void SetOrderIDList(U32 IDList[], U8 SetNoOfThemes, S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_thm_cntx.TotalTheme; i++)
    {
        setorderIDList[i] = IDList[i];
    }
    currorderindex = index;
    WriteThemesToNVRAM();
}


/*****************************************************************************
 * FUNCTION
 *  GetIDList
 * DESCRIPTION
 *  function to get set order ID List
 * PARAMETERS
 *  GetIDList       [IN]        
 *  index           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
U8 GetIDList(U32 **GetIDList, S16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = CheckForCorrectOrder();

    if (count == 0)
    {
        currorderindex = -1;
    }
    *GetIDList = setorderIDList;
    *index = currorderindex;
    WriteThemesToNVRAM();
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  CheckForCorrectOrder
 * DESCRIPTION
 *  function to check for correct order in set order list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 CheckForCorrectOrder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j = 0, set_flag = 0;
    U8 count = 0, totaltheme;
    U32 tempIDList[TOTAL_THEMES_COUNT];
/* MAUI_00019288_Patch_01 Start */
	U16 actual_count = 0;
/* MAUI_00019288_Patch_01 End */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totaltheme = mmi_tm_get_themes(&thm_details);

    ConstructThemeOrderList();

    for (i = 0; i < TOTAL_THEMES_COUNT; i++)
    {
        while (j != totaltheme)
        {

            if (setorderIDList[i] == 0)
            {
                tempIDList[i] = setorderIDList[i];
                set_flag = 1;
/* MAUI_00019288_Patch_01 Start */
				actual_count++;
/* MAUI_00019288_Patch_01 End */
                break;
            }
            if (setorderIDList[i] == thm_details[j].theme_id)
            {
                tempIDList[i] = setorderIDList[i];
                count++;
/* MAUI_00019288_Patch_01 Start */
				actual_count++;
/* MAUI_00019288_Patch_01 End */
                set_flag = 1;
                break;
            }
            j++;
        }
        if (set_flag == 0)
        {

            tempIDList[i] = -1;
            if (currorderindex >= i)
            {
                currorderindex--;
            }
        }
        set_flag = 0;
        j = 0;
    }

    /* if(j==g_thm_cntx.TotalTheme-1 && setorderIDList[i]!=thm_details[j].theme_id )
       {
       if(currorderindex>0 && i<currorderindex)
       currorderindex=currorderindex-1;
       break;
       } */
    for (i = 0; i < TOTAL_THEMES_COUNT; i++)
    {
        if (tempIDList[i] != -1)
        {
            setorderIDList[set_flag++] = tempIDList[i];
        }
    }

/* MAUI_00019288_Patch_01 Start */
	for (i = actual_count; i < TOTAL_THEMES_COUNT; i++)
/* MAUI_00019288_Patch_01 End */
    {
        setorderIDList[i] = -1;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrOrderIndex
 * DESCRIPTION
 *  function to set current order index
 * PARAMETERS
 *  index       [IN]        Of current theme in set order list
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrOrderIndex(S16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currorderindex = index;
    WriteThemesToNVRAM();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_thm_isValidUrl
 * DESCRIPTION
 *  function to check valid url.
 * PARAMETERS
 *  pucURLText       [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_thm_isValidUrl(S8 *pucURLText)
{
	S32	iLength ;
	S32	iQueryIndex ;
	S32	iSchemeIndex ;
	S32	iHostIndex ;
	S32	iHostEndIndex ;
	S32	iPortIndex ;
	S32	iPasswordIndex ;
	S32	iPathIndex ;
	S32	iAtIndex ;
	S32	iHashIndex ;
	S32	index ;
	pBOOL	bisValid  = TRUE ;
	pBOOL	bIsFileScheme  =  FALSE ;

	iQueryIndex = iSchemeIndex = iHostIndex = iPortIndex = iAtIndex = iPathIndex = iPasswordIndex = iHashIndex = -1 ;
	iHostEndIndex = 0 ;
	iLength = strlen ((const char *) pucURLText) ;
	for (index = 0; index < iLength; index++)
	{
		switch (pucURLText[index])
		{
			case '@':
				if (iPasswordIndex > 0)
				{
					iHostIndex = index + 1 ;
					iAtIndex = index ;
				}
				break ;

			case '?':
				iQueryIndex = index + 1 ;
				break ;

			case ':':
				if (iQueryIndex < 0)
				{
					if (pucURLText [index + 1] == '/' && pucURLText [index + 2] == '/')
					{
						iSchemeIndex = index ;
						index += 2 ;
					}
					else if (pucURLText [index + 1] == '/')
					{
						iSchemeIndex = index ;
					}
					else 
					{
                        if (strlen(pucURLText) == index + 1)
                        {
                            iSchemeIndex = index;
                        }
                        else if (iPasswordIndex < 0)
						{
							iPasswordIndex = index + 1 ;
						}
						else
						{
							iPortIndex = index + 1 ;
						}
					}
				}
				break ;

			case '#':
				iHashIndex = index ;
				break ;

			case '/':
				if (iQueryIndex < 0 && iPathIndex < 0 && pucURLText [index + 1] != '/' 
					&& pucURLText [index - 1] != '/')
				{
					iPathIndex = index ;
				}
				break ;

			default:
				break ;
		}
		if (iQueryIndex > 0)
		{
			break ;
		}
	}
	if (iPortIndex < 0)
	{
		if (iPasswordIndex > 0 && iAtIndex < 0)
		{
			iPortIndex = iPasswordIndex ;
		}
	}
	if (iHostIndex < 0) 
	{
		if (iSchemeIndex > 0)
		{
			iHostIndex = iSchemeIndex + 3 ;
		}
		else
		{
			iHostIndex = 0 ;
		}
	}
	
	if (iPathIndex < 0)
	{
		if (iQueryIndex > 0)
		{
			iLength = iQueryIndex - 1 ;
		}
		else if (iHashIndex > 0)
		{
			iLength = iHashIndex ;
		}
		iPathIndex = iLength ;
		iHostEndIndex = iLength - 1 ;
	}
	else
	{
		iHostEndIndex = iPathIndex - 1 ;
	}

	if (FALSE == bIsFileScheme)
	{
		if (mmi_thm_checkValidScheme (pucURLText, iSchemeIndex) == 0)
		{
			bisValid = FALSE ;
		}
		if (iPortIndex > 0)
		{
			if (mmi_thm_checkValidPort (pucURLText, iPortIndex, iPathIndex - 1) == 0)
			{
				bisValid =  FALSE ;
			}
		}
		if (iPortIndex < 0)
		{
			if (mmi_thm_checkValidHostname (pucURLText, iHostIndex, iHostEndIndex) == 0)
			{
				bisValid =  FALSE ;
			}
		}
		else
		{
			if (mmi_thm_checkValidHostname (pucURLText, iHostIndex, iPortIndex - 2) == 0)
			{
				bisValid =  FALSE ;
			}
		}
	}
		
	return bisValid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_checkValidIpaddress
 * DESCRIPTION
 *  function to check valid Ip Address.
 * PARAMETERS
 *  psUrl_value        [IN]        
 *  iStart_index       [IN]
 *  iEnd_index         [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_thm_checkValidIpaddress (S8 *psUrl_value, S32 iStart_index, S32 iEnd_index)
{
	S32 index ;
	S8 numeric_value [THEME_IPADDRESS_NUMERIC_LENGTH] ;
	S32 iIndex ;
	S32 iDots_count = 0 ;
	S32 iActual_value ;

	iIndex = 0 ;
	memset (numeric_value, 0, THEME_IPADDRESS_NUMERIC_LENGTH) ; 
	for (index = iStart_index; index <= iEnd_index; index++)
	{
		if ((psUrl_value [index] == '.') || ('\0' == psUrl_value [index]))
		{
			if ('.' == psUrl_value [index])
			{
				iDots_count++ ;
			}
			iActual_value = atoi ((S8 *) numeric_value) ;		
			if (iActual_value > 255 || iActual_value < 0)
			{
				return FALSE ;
			}
			if (iDots_count == 1)
			{
				if (iActual_value == 0)              
				{
					return FALSE ;
				}
			}
			memset (numeric_value, 0, THEME_IPADDRESS_NUMERIC_LENGTH) ; 
			iIndex = 0 ;
		}
		else if ((psUrl_value [index] >= THEME_NUMERIC_BEGIN && psUrl_value [index] <= THEME_NUMERIC_END))
		{
			if (iIndex == THEME_IPADDRESS_NUMERIC_LENGTH)
			{
				return FALSE ;
			}
			numeric_value [iIndex++] = (S8) psUrl_value [index] ;
		}
		else if ((psUrl_value [index] != THEME_NUMERIC_BEGIN && psUrl_value [index] != THEME_NUMERIC_END))
		{
				return FALSE ;
		}
	}
	if (iDots_count != 3)
	{
		return FALSE ;
	}
	return TRUE ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_checkValidScheme
 * DESCRIPTION
 *  function to check valid Scheme.
 * PARAMETERS
 *  pucURLText         [IN]        
 *  iSchemeIndex       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_thm_checkValidScheme (S8 *pucURLText, S32 iSchemeIndex)
{
	S32	index ;
	pBOOL  bValid = TRUE ;

	if (iSchemeIndex > 0)
	{
		if (iSchemeIndex < 4)
		{
			bValid = FALSE ;
		}
		else
		{
			bValid = FALSE ;
			for (index = 0; index < THEME_TOTAL_VALID_SCHEME; index++)
			{
				if (0 == strncmp ((S8 *) pucURLText, mmi_thm_ValidSchemeList[index], iSchemeIndex))
				{
					bValid = TRUE ;
					index = THEME_TOTAL_VALID_SCHEME ;
				}
			}
			index = iSchemeIndex++ ;
			if (pucURLText [index] != ':' && pucURLText [++index] != '/' && pucURLText [++index] != '/')
			{
				bValid = FALSE ;
			}
		}
	}
	else
	{
		bValid = TRUE ;
	}
	return bValid ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_checkValidPort
 * DESCRIPTION
 *  function to check valid Port.
 * PARAMETERS
 *  pucURLText         [IN]        
 *  iStartIndex        [IN]
 *  iEndIndex          [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_thm_checkValidPort (S8 *pucURLText, S32 iStartIndex, S32 iEndIndex)
{
	S32	index = 0 ;
	pBOOL	bIsValid = TRUE ;

	if (iStartIndex > 0 && iEndIndex > 0)
	{
		for (index = iStartIndex; index <= iEndIndex; index++)
		{
			if (! (pucURLText [index] >= THEME_NUMERIC_BEGIN && pucURLText [index] <= THEME_NUMERIC_END))
			{
				bIsValid = FALSE ;
			}
		}
	}
	return bIsValid ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_thm_checkValidHostname
 * DESCRIPTION
 *  function to check Host Name.
 * PARAMETERS
 *  pucURLText         [IN]        
 *  iStartIndex        [IN]
 *  iEndIndex          [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_thm_checkValidHostname (S8 *pucURLText, S32 iStartIndex, S32 iEndIndex)
{
	S16	isIpAddress ;
	S32	iDotsCount ;
	pBOOL	bIsValid = TRUE ;
	S32	index ;

	if (iStartIndex >= 0 && iEndIndex > 0)
	{
		isIpAddress = 1 ;
		iDotsCount = 0 ;
		if (pucURLText [iStartIndex] == '.' || pucURLText [iStartIndex] == '-')
		{
			bIsValid = FALSE ;
		}
		if (pucURLText [iEndIndex] == '.' || pucURLText [iEndIndex] == '-')
		{
			bIsValid = TRUE ;
		}
		if (TRUE == bIsValid)
		{
			for (index = iStartIndex; index <= iEndIndex; index++)
			{
				if (pucURLText [index] != '.' && pucURLText [index] != '-' && pucURLText [index] != '_')
				{
					if (! (pucURLText [index] >= THEME_NUMERIC_BEGIN && pucURLText [index] <= THEME_NUMERIC_END))
					{
						isIpAddress = 0 ;
						if (! ((pucURLText [index] >= THEME_LOWER_CASE_ALPHA_BEGIN && pucURLText [index] <= 
							THEME_LOWER_CASE_ALPHA_END) || (pucURLText [index] >= THEME_UPPER_CASE_ALPHA_BEGIN && pucURLText [index] <= THEME_UPPER_CASE_ALPHA_END)))
						{
							bIsValid = FALSE ;
						}
					}
				}
				else 
				{
					if (pucURLText [index] == '.')
					{
						iDotsCount++ ;
					}
					if (pucURLText [index + 1] == '.' || pucURLText [index + 1] == '-')
					{
						bIsValid = FALSE ;
					}
				}
			}
			if (isIpAddress == 1)
			{
				if (iDotsCount == 3)
				{
					bIsValid = mmi_thm_checkValidIpaddress (pucURLText, iStartIndex, iEndIndex) ;
				}
				else
				{
					bIsValid = FALSE ;
				}
			}
		}
	}
	else
	{
		bIsValid = FALSE ;
	}
	return bIsValid ;
}

/*****************************************************************************
 * FUNCTION
 *  dmmi_thm_display_error_msg
 * DESCRIPTION
 *  Display error msg of theme operation
 * PARAMETERS
 *  thm_del_ID      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_display_error_msg(S32 error_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_type)
    {
        case THEME_ERROR_SUCCESS:                
                DisplayPopup(
                    (PU8) GetString(STR_THEME_ACTIVATE_SUCCESS),
                    IMG_GLOBAL_ACTIVATED,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    SUCCESS_TONE);
                break;
            case THEME_ERROR_ALREADY_ACTIVATED:
                DisplayPopup(
                    (PU8) GetString(STR_ID_FMGR_ALREADY_ACTIVE),
                    IMG_GLOBAL_INFO,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
            case THEME_ERROR_THEME_NOT_AVAILABLE:
                DisplayPopup(
                    (PU8) GetString(STR_THEME_NOT_AVAILABLE),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            case THEME_ERROR_FILE_FORMAT_BAD:
                DisplayPopup(
                    (PU8) GetString(STR_THEME_FORMAT_NOT_SUPPORTED),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            case THEME_ERROR_FAILURE:
                DisplayPopup(
                    (PU8) GetString(STR_THEME_UNKNOWN_ERROR),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;

            case THEME_ERROR_VERSION_FAILURE:
                DisplayPopup(
                    (PU8) GetString(STR_DOWNLOAD_THEME_UNSUPPORTED),
                    IMG_GLOBAL_ERROR,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            case THEME_ERROR_PROCESS_QUEUE_SUCESS:
                DisplayPopup(NULL, IMG_PROCESSING_PHONEBOOK, 1, UI_POPUP_NOTIFYDURATION_TIME, 0);
                break;
                /* PMT DNLD_THEME_FIXES: SHARIQ START BUG# MAUI_00192708 */
            case THEME_ERROR_LCD_SIZE_MISMATCH:
                DisplayPopup(
                    (PU8) GetString(STR_LCD_SIZE_MISMATCH),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
                //PMT DNLD_THEME_FIXES: SHARIQ END BUG# MAUI_00192708
                //PMT DNLD FIXES 20060513: SUKRIT START MAUI_00221313
            case THEME_ERROR_FILENAME_INCORRECT:
                DisplayPopup(
                    (PU8) GetString(STR_THEME_ERROR_FILENAME_INCORRECT),
                    IMG_GLOBAL_ERROR,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
                /* PMT DNLD FIXES 20060513: SUKRIT END MAUI_00221313 */
            case THEME_ERROR_PHONE_MODEL_MISMATCH:
                DisplayPopup(
                    (PU8) GetString(STR_THEME_ERROR_PHONE_MODEL_MISMATCH),
                    IMG_GLOBAL_ERROR,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            default:
                DisplayPopup(
                    (PU8) GetString(STR_THEME_UNKNOWN_ERROR),
                    IMG_GLOBAL_ERROR,
                    TRUE,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
                /* break; */
        #endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */         
    }
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_thm_activate_dflt_theme
 * DESCRIPTION
 *  activate the default system 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_thm_activate_dflt_sys_theme(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_tm_get_curr_theme_type() != THEME_TYPE_SYSTEM)  
    {
        ActivateDefaultTheme();
    }
}
#endif /* __MMI_THEMES_V2_SUPPORT__ */ 
#endif /* __MMI_THEMES_APPLICATION__ */ 
#endif /* _MMI_THEME_C */ 

