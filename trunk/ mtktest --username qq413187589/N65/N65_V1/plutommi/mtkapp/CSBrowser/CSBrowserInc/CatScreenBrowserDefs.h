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
 *
 * Filename:
 * ---------
 * CatScreenBrowserDefs.h
 *
 * Description:
 * ------------
 *    
 * (definition of data types)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _CSB_BROWSER_DEFS_H
#define _CSB_BROWSER_DEFS_H

#ifdef __MMI_CSB_BROWSER__

#include "MMI_features.h"
#include "wgui_inputs.h"
#include "MMIDataType.h"
#include "CommonScreens.h"
#include "CatScreenBrowserResDef.h"
/* For category 80 - 81 */
#include "gui_calendar.h"

/* Defines */
#define     CSB_NULL                '\0'
#define     MAX_CSB_SCREEN_NAME_LENGTH    18
#define     MAX_CSB_PATH_LENGTH           25
#define     MAX_CSB_AUTO_MODE_TIME        10
#define     MIN_CSB_AUTO_MODE_TIME        1
#define     MAX_CSB_HINT_LENGTH           4

#define     MAX_LOCAL_BUFFER              256
#define     MAX_LOCAL_BUFFER_1            256

#define     IS_ALPHABET(a)             (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')
#define     IS_NUMERIC(a)              (a >= '0' && a <= '9')

#define     CSB_DEFAULT_FOLDER            ":\\CSB\\"
#define     CSB_DRIVE_LENGTH           5
#define     CSB_NOTIFY_DURATION           2000

/* Flags to define the UI control of the screen */
#define CSB_CALL_SCR             0X00000001
#define CSB_COLOR_PICKER_SCR     0X00000002
#define CSB_EDITOR_SCR           0X00000004
#define CSB_IDLE_SCR          0X00000008
#define CSB_IMAGE_VIEWER_SCR     0X00000010
#define CSB_LIST_MENU_SCR        0X00000020
#define CSB_MATRIX_MENU_SCR         0X00000040
#define CSB_POPUP_SCR            0X00000080
#define CSB_PROGRESS_BAR_SCR     0X00000100
#define CSB_SLIDER_SCR           0X00000200
#define CSB_RADIO_BUTTON_SCR     0X00000400
#define CSB_CHECK_BOX_SCR        0X00000800
#define CSB_SUB_LCD              0X00001000
#define CSB_PANEL              0X00002000//052907 CSB

/* Flags to define the App of the screen */
#define CSB_CALLS             0X00000001
#define CSB_EDITOR               0X00000002
#define CSB_ENGG_MODE            0X00000004
#define CSB_EXTRA             0X00000008
#define CSB_FUN_AND_GAMES        0X00000010
#define CSB_FILE_MANAGER         0X00000020
#define CSB_MESSAGES          0X00000040
#define CSB_MISC              0X00000080
#define CSB_MULTIMEDIA           0X00000100
#define CSB_ORGANIZER            0X00000200
#define CSB_PHONEBOOK            0X00000400
#define CSB_PROFILE              0X00000800
#define CSB_SERVICES          0X00001000
#define CSB_SHORTCUT          0X00002000
#define CSB_SETTINGS          0X00004000
#define CSB_WAP                  0X00008000
#define CSB_UNUSED               0X00010000
#define CSB_HID               0X00020000//052907 CSB


/* Search Modes -- Used by Framework */
typedef enum
{
    SEARCH_BY_CONTROL = 0,
    SEARCH_BY_APP,
    SEARCH_BY_SCREENID,
    SEARCH_BY_VIEW
} CSB_search_modes_enum;

/* Search Mode Menu Enum */
typedef enum
{
    SEARCH_MODE_CONTROL = 0,
    SEARCH_MODE_APP,
    SEARCH_MODE_SCREENID,
    SEARCH_MODE_TOTAL
} csb_search_mode_menu_items_enum;

/* View Mode Menu Enum */
typedef enum
{
    VIEW_MODE_MANUAL = 0,
    VIEW_MODE_AUTO,
    VIEW_MODE_TOTAL
} csb_view_mode_enum;

/* Manual Mode Menu Enum */
typedef enum
{
    MANUAL_MODE_INTERACTIVE = 0,
    MANUAL_MODE_NONINTERACTIVE,
    MAUNAL_MODE_TOTAL
} csb_manual_mode_enum;

/* Category Screen Enum */
typedef enum
{
    CATEGORY_SCREEN_14LST = 0,
    CATEGORY_SCREEN_14MAT,
    CATEGORY_SCREEN_EMS,
    CATEGORY_SCREEN_165ext,
    CATEGORY_SCREEN_1,
    CATEGORY_SCREEN_2,
    CATEGORY_SCREEN_5,
    CATEGORY_SCREEN_6,
    CATEGORY_SCREEN_7,
    CATEGORY_SCREEN_8,
    CATEGORY_SCREEN_9,
#ifdef UI_SMALL_LIST_SCREEN
    CATEGORY_SCREEN_10,
#endif
    CATEGORY_SCREEN_11,
    CATEGORY_SCREEN_12,
    CATEGORY_SCREEN_13,
    CATEGORY_SCREEN_15,
    CATEGORY_SCREEN_16,
    CATEGORY_SCREEN_17,
    CATEGORY_SCREEN_18,
    CATEGORY_SCREEN_19,
    CATEGORY_SCREEN_20,
    CATEGORY_SCREEN_21,
    CATEGORY_SCREEN_22,
    CATEGORY_SCREEN_28,
    CATEGORY_SCREEN_32,
    CATEGORY_SCREEN_33,
    CATEGORY_SCREEN_36,
    CATEGORY_SCREEN_39,
    CATEGORY_SCREEN_52,
    CATEGORY_SCREEN_53,
    CATEGORY_SCREEN_55,
    CATEGORY_SCREEN_56,
    CATEGORY_SCREEN_57,
    CATEGORY_SCREEN_61,
    CATEGORY_SCREEN_62,
    CATEGORY_SCREEN_63,
    CATEGORY_SCREEN_64,
    CATEGORY_SCREEN_65,
    CATEGORY_SCREEN_66,
    CATEGORY_SCREEN_69,
#ifdef __MMI_MENSTRUAL__
    CATEGORY_SCREEN_72,
#endif 
    CATEGORY_SCREEN_73,
    CATEGORY_SCREEN_74,
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    CATEGORY_SCREEN_75,
#endif 
    CATEGORY_SCREEN_76,
#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    CATEGORY_SCREEN_77,
#endif 
    CATEGORY_SCREEN_78,
#ifdef ENABLE_CALENDAR_CONTROL    
#if(ENABLE_CALENDAR_CONTROL) && defined(__USE_OLD_CALENDAR__)
    CATEGORY_SCREEN_80,
    CATEGORY_SCREEN_81,
#endif /* (ENABLE_CALENDAR_CONTROL) && defined(__USE_OLD_CALENDAR__) */ 
#endif
    CATEGORY_SCREEN_84,
#ifdef __MMI_ANALOG_CLOCK__    
    CATEGORY_SCREEN_86,
#endif /* __MMI_ANALOG_CLOCK__ */    
    CATEGORY_SCREEN_87,
    CATEGORY_SCREEN_88,
    CATEGORY_SCREEN_89,
#ifdef __MMI_CALORIE__
/* under construction !*/
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    CATEGORY_SCREEN_91,
#endif 
#if 0 /* remove for code size */
/* under construction !*/
#endif /* remove for code size */
    CATEGORY_SCREEN_105,
    CATEGORY_SCREEN_106,
    CATEGORY_SCREEN_109,
    CATEGORY_SCREEN_111,
#ifdef UI_SMALL_PIN_EDITOR_SCREEN
    CATEGORY_SCREEN_112,
#endif 
	CATEGORY_SCREEN_120,
    CATEGORY_SCREEN_121,
#ifdef __MMI_BMI__
    CATEGORY_SCREEN_122,
#endif 
    CATEGORY_SCREEN_123,
#ifdef __MMI_CALORIE__
/* under construction !*/
#endif 
    CATEGORY_SCREEN_128,
    CATEGORY_SCREEN_129,
    CATEGORY_SCREEN_130,
    CATEGORY_SCREEN_131,
    CATEGORY_SCREEN_140,
    CATEGORY_SCREEN_141,
    CATEGORY_SCREEN_142,
#ifdef __MMI_MESSAGES_EMS__
    CATEGORY_SCREEN_143,
    CATEGORY_SCREEN_144,
#endif /* __MMI_MESSAGES_EMS__ */ 
    CATEGORY_SCREEN_145,
    CATEGORY_SCREEN_150,
    CATEGORY_SCREEN_151,
    CATEGORY_SCREEN_152,
    CATEGORY_SCREEN_153,
    CATEGORY_SCREEN_154,
#ifdef __MMI_LCD_PARTIAL_ON__
    CATEGORY_SCREEN_161,
#endif 
    CATEGORY_SCREEN_162,
    CATEGORY_SCREEN_164,
    CATEGORY_SCREEN_165,
    CATEGORY_SCREEN_166,
    CATEGORY_SCREEN_170,
    CATEGORY_SCREEN_171,
    CATEGORY_SCREEN_172,
    CATEGORY_SCREEN_174,
    CATEGORY_SCREEN_184,
    CATEGORY_SCREEN_185,
    CATEGORY_SCREEN_200,
    CATEGORY_SCREEN_201,
    CATEGORY_SCREEN_204,
    CATEGORY_SCREEN_205,
    CATEGORY_SCREEN_211,
    CATEGORY_SCREEN_212,
    CATEGORY_SCREEN_213,
    CATEGORY_SCREEN_214,
    CATEGORY_SCREEN_221,
    CATEGORY_SCREEN_222,
    CATEGORY_SCREEN_223,
#ifdef __MMI_VIDEO_PLAYER__    
    CATEGORY_SCREEN_224,
    CATEGORY_SCREEN_225,
#endif    
    CATEGORY_SCREEN_227,
    CATEGORY_SCREEN_228,
#ifdef __MMI_WC_TZ_SUPPORT__
    CATEGORY_SCREEN_230,
#endif 
    CATEGORY_SCREEN_257,
    CATEGORY_SCREEN_261,
    CATEGORY_SCREEN_262,
    CATEGORY_SCREEN_263,
#ifdef __MMI_TOUCH_SCREEN__
    CATEGORY_SCREEN_264,
#endif 
#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
    CATEGORY_SCREEN_265,
#endif 
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    CATEGORY_SCREEN_273,
#endif 
    CATEGORY_SCREEN_276,
    CATEGORY_SCREEN_277,
    CATEGORY_SCREEN_284,
#ifdef __MMI_SUBLCD__
    CATEGORY_SCREEN_301,
    CATEGORY_SCREEN_302,
    CATEGORY_SCREEN_303,
    CATEGORY_SCREEN_304,
#endif /* __MMI_SUBLCD__ */ 
    CATEGORY_SCREEN_305,
#ifdef __MMI_STOPWATCH__
    CATEGORY_SCREEN_306,
    CATEGORY_SCREEN_307,
#endif /* __MMI_STOPWATCH__ */ 
#ifdef __MMI_SUBLCD__
    CATEGORY_SCREEN_310,
    CATEGORY_SCREEN_311,
    CATEGORY_SCREEN_312,
    CATEGORY_SCREEN_313,
    CATEGORY_SCREEN_314,
    CATEGORY_SCREEN_332,
    CATEGORY_SCREEN_333,
#endif /* __MMI_SUBLCD__ */ 
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    CATEGORY_SCREEN_334,
#endif
    CATEGORY_SCREEN_353,
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    CATEGORY_SCREEN_357,
#endif 
    CATEGORY_SCREEN_384,
    CATEGORY_SCREEN_400,
    CATEGORY_SCREEN_402,
    CATEGORY_SCREEN_403,
    CATEGORY_SCREEN_404,
    CATEGORY_SCREEN_412,
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    CATEGORY_SCREEN_414,
#endif 
    CATEGORY_SCREEN_420,
    CATEGORY_SCREEN_425,
    CATEGORY_SCREEN_427,
    CATEGORY_SCREEN_430,
    CATEGORY_SCREEN_435,
#ifdef __MMI_CAT44X_SUPPORT__
    CATEGORY_SCREEN_441,
    CATEGORY_SCREEN_442,
    CATEGORY_SCREEN_445,
    CATEGORY_SCREEN_443,
    CATEGORY_SCREEN_447,
    CATEGORY_SCREEN_448,
    CATEGORY_SCREEN_449,
#endif
    CATEGORY_SCREEN_501,
    CATEGORY_SCREEN_626,
    CATEGORY_SCREEN_657,
    TOTAL_CATEGORY_SCREENS
} csb_category_screen_enum;

typedef void (*FuncPointer) (void);

/* structure for dynamic list of category screens */
typedef struct csb_search
{
    U16 screen_index;   /* index of the category screen in dynamic buffer */
    U8 *pscreen_name;   /* name of the category screen in dynamic buffer */
} csb_category_screen;

/* Structure of one category screen information */
typedef struct
{
    U32 cat_ID;                                     /* Category Screen ID */
    U16 cat_scr_name[MAX_CSB_SCREEN_NAME_LENGTH];   /* Category Screen Name */
    U32 app_search_flags;                           /* Application Search Flags */
    U32 cont_search_flags;                          /* Control Search Flags */
    FuncPointer entryFuncPtr;                       /* Entry Function Pointer of category screen */
} csb_screen_info;

/* structure to be stored in NVRAM */
typedef struct
{
    U8 view_mode;       /* AUTO or Manual */
    U8 manual_mode;     /* Interactive or Non-Interactive */
    U16 timer_value;    /* Duration between category screens display */
    U8 csb_screenshots_folder_path[MAX_CSB_PATH_LENGTH *ENCODING_LENGTH];
} csb_setting_struct;

/* main Structure of the CSB application */
typedef struct
{
    U8 search_mode;                     /* Control or App or Screen ID */
    U16 current_index;                  /* It stores the current index selected from the list of category screens */
    U16 screen_counter;                 /* Current screen dislayed */
    U16 number_of_screens;              /* No. of screens found in particular search */
    U16 caption_str_id;                 /* It stores the currently selected control or application to show caption on next screen */
    U32 current_flag;                   /* In search mode, the current flag selected */
    csb_setting_struct csb_settings;    /* Instance of the structure that need to be stored in NVRAM */
    csb_screen_info *pscreen_info;      /* Pointer to category screen database */
} csb_struct;

#endif /* __MMI_CSB_BROWSER__ */ 

#endif /* _CSB_BROWSER_DEFS_H */ 

