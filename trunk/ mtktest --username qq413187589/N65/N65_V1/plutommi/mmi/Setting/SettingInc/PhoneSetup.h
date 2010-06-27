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
 *  PhoneSetup.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef PHONESETUP_H_
#define PHONESETUP_H_
/*************************************************************
 *  Header File Dependance Check
 *************************************************************/
#include "mmi_phnset_dispchar.h"

/*************************************************************
 *  Defination
 *************************************************************/
#define __MMI_PHNSET_COMMENT__ 0
#define MAX_SS_INLINE_EDIT          4
#define PHNSET_MAX_FILE_LEN            (41)     /* Same size as menuitem's length */
#define PHNSET_MAX_PATH_LEN            (260)
#define PHNSET_MAX_EXT_LEN          (5)


#ifndef UI_character_type
#ifdef __UCS2_ENCODING
typedef U16 UI_character_type;
#else 
typedef U8 UI_character_type;
#endif 
#endif /* UI_character_type */ 
/*************************************************************
 *  Enum Value
 *************************************************************/
typedef enum
{
    SET_SS_SETTING_INLINE_CAPTION_STATUS,
    SET_SS_SETTING_INLINE_SELECT_OFF,
    SET_SS_SETTING_INLINE_SELECT_ON,
    SET_SS_SETTING_INLINE_SELECT_POWER_SAVING,
    SET_SS_SETTING_INLINE_CAPTION_WAITING,
    SET_SS_SETTING_INLINE_SELECT_5SEC,
    SET_SS_SETTING_INLINE_SELECT_15SEC,
    SET_SS_SETTING_INLINE_SELECT_30SEC,
    SET_SS_SETTING_INLINE_SELECT_1MIN,

    SET_SS_SETTING_INLINE_MAX_ID
} SET_SS_SETTING_INLINE_ENUM;

typedef enum
{
    SET_SS_STATUS_OFF = 0,
    SET_SS_STATUS_ON = 1,
    SET_SS_STATUS_POWERSAVING = 2
} SET_SS_SETTING_STATUS;

typedef enum
{
    MMI_SETTING_TVOUT_FORMAT_PAL = 0,
    MMI_SETTING_TVOUT_FORMAT_NTSC
} mmi_setting_tvout_format_enum;

typedef enum
{
    MMI_SETTING_TVOUT_AUD_PATH_BOTH = 0,
    MMI_SETTING_TVOUT_AUD_PATH_TV
} mmi_setting_tvout_aud_path_enum;

#ifdef __GEMINI__
typedef enum
{
	MMI_PHNSET_UART_SIM1 = 0,
	MMI_PHNSET_UART_SIM2,
	MMI_PHNSET_UART_SIM_NONE
}mmi_phnset_uart_sim_config_enum;
#endif 

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
typedef enum
{
    /*
     * MMI_PHNSET_IDLECLKTYPE_NONE,
     */
    MMI_PHNSET_IDLECLKTYPE_ANALOG,
    MMI_PHNSET_IDLECLKTYPE_DIGITAL,
    MMI_PHNSET_IDLECLKTYPE_MAX
} PHNSET_IDLECLKTYPE_ENUM;
#endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */ 
/*************************************************************
 *  Structure Defination
 *************************************************************/
typedef struct
{
    U16 isWPShort;
    U16 isSSShort;
    U16 wallpaper[(PHNSET_MAX_FILE_LEN + PHNSET_MAX_PATH_LEN + PHNSET_MAX_EXT_LEN)];
    U16 screensave[(PHNSET_MAX_FILE_LEN + PHNSET_MAX_PATH_LEN + PHNSET_MAX_EXT_LEN)];
} PHNSET_WPSS_FILENAME_STRUCT;

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
typedef struct
{
    U16 isPwrOnShort;
    U16 isPwrOffShort;
    U16 pwrondisplay[(PHNSET_MAX_FILE_LEN + PHNSET_MAX_PATH_LEN + PHNSET_MAX_EXT_LEN)];
    U16 pwroffdisplay[(PHNSET_MAX_FILE_LEN + PHNSET_MAX_PATH_LEN + PHNSET_MAX_EXT_LEN)];
} PHNSET_PWRONOFF_FILENAME_STRUCT;
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 

typedef struct
{
    U8 month;
    U8 date;
    U8 hour;
    U8 minutes;
    U16 year;
} PHNSET_DATETIME_STRUCT;

/*
 *** Phone Setup context structure
 */
typedef struct
{

    S32 curHightlightItem;
    U16 ScrAnchor;  /* Screen Anchor */

    /* Set Time and Date */
    U8 currentCity;
    U16 CurHomeCityStrID;
    U8 *CurHomeCityStrPtr;
    U32 CurTimeFmt;
    U32 CurDateFmt;
    S32 currentDST;
    S32 prevDST;
    U8 *AM_PM_flag;

    PHNSET_DATETIME_STRUCT settime;

    /* NITZ */
    //pBOOL NITZDirtyFlag;
    U8 curNITZStatus;

    /* Phone Setup */
    U8 curShowDtStatus;
    U8 curShowOwnNumStatus;
#if defined(__MMI_OPERATOR_NAME_MENU__)
    U8 curShowOPNStatus;
#endif 
    pBOOL ShowDtDirtyFlag;
    pBOOL ShowOwnNumDirtyFlag;
#if defined(__MMI_OPERATOR_NAME_MENU__)
    pBOOL ShowOPNDirtyFlag;
#endif 

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    U8 MenuStyle;
#endif 

#ifdef __MMI_SET_DEF_ENCODING_TYPE__
    U8 EncodingType;
#endif 

    /* Language */
    U8 **ppLang;
    U8 LP;
    U8 UsrLangIdx;

#ifdef __FLIGHT_MODE_SUPPORT__
    U8 curFlightMode;   /* current mode */
    U8 selFlightMode;   /* selected mode */
#ifdef __MMI_WLAN_FEATURES__
    U8 curFlightMode2;
#endif
#endif /* __FLIGHT_MODE_SUPPORT__ */ 

    /* Wallpaper & Screen Saver */
    U8 WPSSPreviewScrFlag;
    U16 curtWpID;
#ifdef __MMI_SUB_WALLPAPER__
    U16 curtSubWpID;
#endif 
    U16 curSsID;
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    U16 curtPwrOnID;
    U16 curtPwrOffID;
#endif /* __MMI_POWER_ON_OFF_DISPLAY__ */ 
#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
    U16 curtCLKType;
#endif 
    U8 WPFctyImgNum;
    U8 SSFctyImgNum;
    U8 WPDwnlImgNum;
    U8 SSDwnlImgNum;
    S32 SSStatusInlineHilite;
    S32 SSWaitStatusInlineHilite;
    S32 curSSStatus;
    S32 curSSWaitTime;
    S32 isShort;

    /* Wallpaper & Screen Saver shall code identifier */
    phnset_wpss_type_enum wpss_type;

    U16 SysWPSSList[MMI_MAX_DISPCHAR_IMG + MMI_MAX_DISPCHAR_VDO];
    U16 DwnlWPSSList[MAX_DL_WPSS_NUMBERS];
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    U16 pen_speed;
    U16 pen_color;
    U8 is_default_calibration_set;
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#ifdef __MMI_TVOUT__
    U16 tvout_format;
    U16 tvout_aud_path;
    S32 tvout_y_gamma;
    S32 tvout_u;
    S32 tvout_v;

    S32 tvout_tmp_y_gamma;
    S32 tvout_tmp_u;
    S32 tvout_tmp_v;

    BOOL is_tvout_init;
    BOOL is_tvout_connected;
    BOOL is_tvout_sleep_in;
    BOOL is_tvout_enable_sleep_in;

    /* inline screen */
    S8 *tvout_format_str_list[2];
    S8 *tvout_aud_path_str_list[2];

    S32 tvout_inline_format;
    S32 tvout_inline_aud_path;
#endif /* __MMI_TVOUT__ */ 

#ifdef __GEMINI__
	U8 uart_status;
#endif	/* __GEMINI__ */
		
    U8 isCorrectSet;

    U8 font_size;
    /* Look! Here might be structure alignment problem */
} PHNSET_CNTX;

/* Dynamic FlightMode struct and enum */
#ifdef __GEMINI__
typedef enum
{
    MTPNP_NO_SIM_INSERTED    = 0,
    MTPNP_ONLY_SIM1_INSERTED = 1,
    MTPNP_ONLY_SIM2_INSERTED = 2,
    MTPNP_DUAL_SIM_INSERTED  = 3,
    MTPNP_SIM_INSERT_STATUS_NONE = 0xFF
} dualmode_sim_insert_status_enum; 

typedef enum
{
    MTPNP_SIM1_ONLY_CONFIG  = 0,
    MTPNP_SIM2_ONLY_CONFIG  = 1,
    MTPNP_DAUL_SIM_CONFIG   = 2,
    MTPNP_FLIGHTMODE_CONFIG = 3,
    MTPNP_SIM_CONFIG_STATUS_NONE  = 0xFF
} dualmode_sim_config_status_enum; 

typedef struct
{
    dualmode_sim_insert_status_enum sim_insert;
    dualmode_sim_config_status_enum src_status;
    dualmode_sim_config_status_enum dest_status;
}DUALMODE_SWITCH_STATUS;
#endif /* __GEMINI__ */
/*************************************************************
 *  Global Variable
 *************************************************************/
extern PHNSET_CNTX *g_phnset_cntx_p;
extern void change_font_Theme(void);

/*************************************************************
 *  Function Prototype
 *************************************************************/
extern void PhnsetLangHiliteHandler(S32 index);
extern void PhnsetLangLSKHandler(void);
extern void EntryPhnsetLang(void);
extern void EntryPhnsetScr(void);
extern void ExitPhnsetScr(void);
extern void EntryPhnsetTimeAndDate(void);
extern void ExitPhnsetTimeAndDate(void);
extern void PhnsetTimeAndDateHiliteHandler(S32 index);
extern void PhnsetSetDTHistoryHdlr(void);
extern void PhnsetSetTimeResHdlr(void *info);
extern void PhnsetConstructCityList(void);
extern void HighlightPhnsetLang(void);
extern void HighlightPhnsetWelcomeText(void);
extern void EntryPhnsetWelcomeText(void);
extern void ExitPhnsetWelcomeText(void);

/* static void PhnsetFillWelcomeInlineEditStruct(void *InlineStruct); */
extern void EntryPhnsetWelcomeTextDoneHdlr(void);
extern void HintPhnsetTimeAndDate(U16 index);

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
/* Handwriting setting */
extern void HighlightHandwritingSetting(void);
extern void HighlightCalibrationSetting(void);
extern void SaveHandwritingSetting(void);
extern void GoBackHandwritingSettingConfirm(void);
extern void EntryScrHandwritingSettingConfirm(void);
extern void HandwritingSettingInlineColor(U16 index);

/* Pen calibration */
extern void EntryCalibrationSettingScr(void);
extern void ExitCalibrationSettingScr(void);

#ifdef __MMI_HANDWRITING_PAD__
extern void EntryTestControlAreaScr(void);
extern void ExitTestControlAreaScr(void);
#endif /* __MMI_HANDWRITING_PAD__ */ 

#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

extern void HighlightPhnsetNITZ(void);
extern void EntryPhnsetNITZ(void);
extern void PhnsetWelcomeTextDoneLskHdlr(void);
extern void HighlightPhnsetSetHomeCity(void);
extern void HighlightPhnsetSetDT(void);
extern void HighlightPhnsetSetFormat(void);

/* START: add day light saving setting */
extern void HighlightPhnsetSetDST(S32 index);

/* END:  add day light saving setting */
extern void EntryPhnsetSetDT(void);
extern void ExitPhnsetSetDT(void);
extern void PhnsetSetDT(void);
extern void EntryPhnsetSetFormat(void);
extern void ExitPhnsetSetFormat(void);
extern void PhnsetSetFormatHiliteHandler(S32 highliteIndex);
extern void PhnsetSetFormat(void);
extern void PhnsetSetFormatFillInlineStruct(void *);

/* __MMI_SEPARATE_DT_SETTING__ */
extern void HighlightPhnsetSetTimeAndFormat(void);
extern void HighlightPhnsetSetDateAndFormat(void);
extern void EntryPhnsetSetTimeAndFormat(void);
extern void ExitPhnsetSetTimeAndFormat(void);
extern void EntryPhnsetSetDateAndFormat(void);
extern void ExitPhnsetSetDateAndFormat(void);
extern void PhnsetSetDTAndFormatFillInlineStruct(void *p);
extern void PhnsetSetDTAndFormat(void);

/* __MMI_SEPARATE_DT_SETTING__ */
extern S16 PhnsetSetTimeFormat(U8 timeformat);
extern S16 PhnsetSetDateFormat(U8 dateformat);
extern void EntryPhnsetSetHomeCity(void);
extern void PhnsetHomeCityIdxHiliteHandler(S32 index);
extern void PhnsetSetHomeCity(void);
extern void ExitFunctionHomeCity(void);
extern U8 PhnsetHCGetNearbyIdx(UI_character_type inp);
extern void PhnsetHCMultiTapHdlr(UI_character_type);
extern void PhnsetHCMultiTapCompleteHdlr(void);
extern void PhnsetSetHomeCityPtr(U8 *);
extern void HighlightPhnsetIdleScrDisp(void);
extern void ExitPhnsetIdleScrDisp(void);
extern void EntryPhnsetIdleScrDisp(void);
extern void PhnsetToggleShowOwnNo(void);
extern void HighlightPhnsetShowOwnNo(void);

/* Lisen 0921-1 */
#if defined(__MMI_OPERATOR_NAME_MENU__)
extern void PhnsetToggleShowOPN(void);
extern void HighlightPhnsetShowOPN(void);
#endif /* defined(__MMI_OPERATOR_NAME_MENU__) */ 
extern void PhnsetToggleShowDtTime(void);
extern void HighlightPhnsetShowDtTime(void);
extern void PhnsetSetTimeResHdlrForAT(void *);
extern void HintPhnsetNITZ(U16);
extern void HintPhnsetWelcomeText(U16);
extern void HintPhnsetLanguage(U16);
extern void HintPhnsetOwnerNum(U16);

/* Lisen 0921-1 */
#if defined(__MMI_OPERATOR_NAME_MENU__)
extern void HintPhnsetOPN(U16);
#endif 
extern void HintPhnsetShowDateTime(U16);
extern void HintPhnsetWallpaper(U16);

#ifdef __MMI_SUB_WALLPAPER__
extern void HintPhnsetSubWallpaper(U16);
#endif 
extern void HintPhnsetScreenSaver(U16);

#ifdef __MMI_PREFER_INPUT_METHOD__
extern void HintPhnsetPreferedInputMethod(U16 index);
#endif 

#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
extern void HighlightHandwritingSetting(void);
extern void HighlightCalibrationSetting(void);
extern void EntryHandWritingSettingScr(void);
extern void ExitHandWritingSettingScr(void);
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */ 

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
extern void HintPhnsetMainMenuStyle(U16);
extern void HighlightPhnsetMainMenuStyle(void);
extern void EntryPhnsetMainMenuStyle(void);
extern void HighlightPhnsetMainMenuStyleSelect(void);
extern void PhnsetMainMenuStyleSelectLskHdlr(void);
extern U8 PhnsetGetMainMenuStyle(void);
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#ifdef __MMI_SET_DEF_ENCODING_TYPE__
extern void HighlightPhnsetDefEncoding(void);
extern void HintPhnsetDefEncoding(U16 index);
extern void PhnsetDefEncodingHiliteHandler(S32 index);
extern void PhnsetDefEncodingSelectHandler(void);
extern void EntryPhnsetDefEncoding(void);
#endif /* __MMI_SET_DEF_ENCODING_TYPE__ */ 

/* Robin 0603: G12C request -- Add Display Setup menu */
#ifdef __MMI_DISP_SETUP_LEVEL_UP__
extern void HighlightDispSetup(void);
extern void EntryDispSetup(void);
#endif /* __MMI_DISP_SETUP_LEVEL_UP__ */ 

/* diamond, 2005/07/05 Flight mode */
#ifdef __FLIGHT_MODE_SUPPORT__
extern void HighlightPhnsetFlightMode(void);
extern void HintPhnsetFlightMode(U16);
extern void EntryPhnsetFlightMode(void);
#endif /* __FLIGHT_MODE_SUPPORT__ */ 
/* end, diamond */

#ifdef __MMI_TVOUT__
extern U16 mmi_phnset_tvout_get_style(void);
#endif 

#if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__)
extern void HintPhnsetIdleClockType(U16 index);
extern void HighlightPhnsetIdleClockType(void);
extern void PhnsetReadIdleClockType(void);
#endif /* defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) */ 

#ifdef __MMI_CHANGABLE_FONT__
extern void PhnsetReadFontSize(void);
extern void EntryPhnsetFontSize(void);
extern void PhnsetSetFontSize(void);
extern void HintPhnsetFontSize(U16 index);
extern void HighlightPhnsetFontSize(void);
#endif /* __MMI_CHANGABLE_FONT__ */ 

#ifdef __USB_IN_NORMAL_MODE__
extern pBOOL mmi_usb_check_path_exported(S8 *path);
#endif 
#endif /* PHONESETUP_H_ */ 

