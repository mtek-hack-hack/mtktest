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
*  CSBEntryHandlers.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Category Screen Browser Entry Handlers
*
* Author:
* -------
*  
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * created by clearfsimport
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_CSB_BROWSER__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "FileMgr.h"
#include "wgui_tab_bars.h"
#include "DateTimeGprot.h"
/* harendra */
#include "CallhistoryEnum.h"
#include "WPSSProtos.h"
#include "ems.h"
#include "wgui_ems.h"
#include "PhoEdtResDef.h"      /* for 214 screen */
#include "IdleAppProt.h"

/* For Default Image */
#include "UserProfilesResDef.h"
#include "AlarmDef.h"
#include "AudioPlayerDef.h"
#include "CallhistoryEnum.h"
#include "DataAccountResDef.h"
#include "EmailAppResDef.h"
#include "EbookDefs.h"
#include "JavaAgencyDef.h"
#include "FunAndGamesDefs.h"
#include "IdleAppDef.h"
#include "MessagesResourceData.h"
#include "QuickAccessMenuItem_def.h"
#include "PhoneBookDef.h"
#include "SATDefs.h"
#include "SettingDefs.h"
#include "NetworkSetupGProt.h"
#include "SoundRecorderDef.h"
#include "VoIPResDef.h"
#include "VRSDResDef.h"
#include "VRSIResDef.h"
#include "WapResDef.h"



#ifdef __MMI_STOPWATCH__
#endif 

/* For category 91 */
#ifdef __MMI_TOUCH_SCREEN__
#endif 
/* For category 223 */
#include "SoundRecorderDef.h"
/* For category 205 */
#include "FactoryModeDef.h"
/* For category 131 */
#include "ScreenSaverDefs.h"
/* For category 121 */
#include "AlarmDef.h"
/* For category 106 */
#include "ExtDeviceDefs.h"
/* For category 17 */
#include "PhoneBookDef.h"
/* for category 75 */
#include "wgui_inputs.h"
/* For SUB LCD screens */
#include "MainMenuDef.h"
#include "CallManagementIdDef.h"

#include "mmi_phnset_dispchar.h"
#include "WallpaperDefs.h"
#include "PhoneSetupResList.h"

/* For category 230 */
#include "worldclock.h"

/* For category 80 */
#include "wgui_calendar.h"

/* For category 75 and 77 */
#include "wgui_inputs.h"

/* For category 201 */
#include "DictionaryMain.h"

#include "CatScreenBrowserDefs.h"
#include "CatScreenBrowserProts.h"


#ifdef __MMI_CAT44X_SUPPORT__

#include "AudioPlayerDef.h"

#ifdef __MMI_TOUCH_SCREEN__   
extern void wgui_cat44x_reg_control_area_pen_handlers(mmi_pen_handler pen_hdlr, mmi_pen_event_type_enum event_type);
#endif /* __MMI_TOUCH_SCREEN__ */
extern void csb_get_page_callback(U32 start_id, U32 end_id, PU8 buffer);
extern void csb_get_data_during_scrolling_cb(S32 page_id, PU8 buffer);

#ifdef __MMI_TOUCH_SCREEN__   
static MMI_BOOL csb_445_control_area_pen_down(mmi_pen_point_struct point);
static MMI_BOOL csb_445_control_area_pen_up(mmi_pen_point_struct point);
static MMI_BOOL csb_445_control_area_pen_move(mmi_pen_point_struct point);
#endif /* __MMI_TOUCH_SCREEN__ */

static void csb_441_b1_down_event_callback(void);
static void csb_441_b1_up_event_callback(void);
static void csb_441_b1_repeat_event_callback(void);
static void csb_441_b2_down_event_callback(void);
static void csb_441_b2_up_event_callback(void);
static void csb_441_b2_repeat_event_callback(void);
static void csb_441_header_callback(void);
static void csb_441_hilight_callback(S32 idx);
static void csb_44x_change_data_1(void);
static void csb_44x_change_data_2(void);
static void csb_44x_change_data_3(void);



static wgui_panel_element_struct panel_list[7] = 
{
    {-1,-1,-1,-1,KEY_1,csb_441_b1_down_event_callback, csb_441_b1_up_event_callback, csb_441_b1_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L1, IMG_GLOBAL_L1, IMG_PROFILES_OUTDOOR},
    {-1,-1,-1,-1,KEY_2,csb_441_b2_down_event_callback, csb_441_b2_up_event_callback, csb_441_b2_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L2, IMG_GLOBAL_L2, IMG_PROFILES_OUTDOOR},
    {-1,-1,-1,-1,KEY_3,csb_441_b2_down_event_callback, csb_441_b2_up_event_callback, csb_441_b2_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L3, IMG_GLOBAL_L3, IMG_PROFILES_OUTDOOR},
    {-1,-1,-1,-1,KEY_4,csb_441_b2_down_event_callback, csb_441_b2_up_event_callback, csb_441_b2_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L4, IMG_GLOBAL_L4, IMG_PROFILES_OUTDOOR},
    {-1,-1,-1,-1,KEY_5,csb_441_b2_down_event_callback, csb_441_b2_up_event_callback, csb_441_b2_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L5, IMG_GLOBAL_L5, IMG_PROFILES_OUTDOOR},
    {-1,-1,-1,-1,KEY_6,csb_441_b2_down_event_callback, csb_441_b2_up_event_callback, csb_441_b2_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L6, IMG_GLOBAL_L6, IMG_PROFILES_OUTDOOR},
    {-1,-1,-1,-1,KEY_7,csb_441_b2_down_event_callback, csb_441_b2_up_event_callback, csb_441_b2_repeat_event_callback, IMG_GLOBAL_L9, IMG_GLOBAL_L7, IMG_GLOBAL_L7, IMG_PROFILES_OUTDOOR}
};

static wgui_text_area_struct top_text_area_data;
static wgui_hilite_header_inputbox_struct inputbox_area_data;
static wgui_panel_area_struct panel_area_data;
static HILITE_STR strlist[2];

#endif /* __MMI_CAT44X_SUPPORT__ */

void EntryScreen_626(void);
void entry_list_tab_0(void);
void entry_list_tab_1(void);
void exit_list_tab_0(void);
void exit_list_tab_1(void);

void EntryScreen_657(void);
void entry_inline_tab_0(void);
void entry_inline_tab_1(void);
void exit_inline_tab_0(void);
void exit_inline_tab_1(void);


#undef __CSB_SUPPORT_EXT_POPUP_TEST__

/* Global Variables */
extern csb_struct g_CSB_struct;

/* For category screen 22 */
extern U8 *SymbolPickerSymbols[36];
extern U8 SymbolPickerLFString[];
extern U8 SymbolPickerSpaceString[];

extern U8 g_buffer[MAX_LOCAL_BUFFER];
extern U8 g_buffer1[MAX_LOCAL_BUFFER_1];

/* For category 230 */
#ifdef __MMI_WC_TZ_SUPPORT__
extern U8 *gIndexInfo[2];
extern U8 *homeTime, *foreTime;
#endif /* __MMI_WC_TZ_SUPPORT__ */ 

extern U16 g_image_id_list[2];

#define G_BUF_STRING_LEN ((MAX_LOCAL_BUFFER - ENCODING_LENGTH)/ENCODING_LENGTH)
#define G_BUF1_STRING_LEN ((MAX_LOCAL_BUFFER_1 - ENCODING_LENGTH)/ENCODING_LENGTH)
#define CSB_MAX_BUFFER_LEN 5

#ifdef __CSB_SUPPORT_EXT_POPUP_TEST__
    #define MAX_POPUP_IMAGE_INDEX 55-1
#else
    #define MAX_POPUP_IMAGE_INDEX 13-1
#endif

static S32 current_popup_index = 0;

U16 PopupImageGroup[] = 
{
    IMG_GLOBAL_UNFINISHED,
    IMG_GLOBAL_WARNING,
    IMG_GLOBAL_ACTIVATED,
    IMG_GLOBAL_QUESTION,
    IMG_GLOBAL_SAVE,
    IMG_GLOBAL_DELETED,
    IMG_GLOBAL_EMPTY,
    IMG_GLOBAL_DEFAULT,
    IMG_GLOBAL_PROGRESS,
    IMG_GLOBAL_LOADING,
    IMG_GLOBAL_ERASED,
    IMG_GLOBAL_ERROR,
    IMG_GLOBAL_INFO
#ifdef __CSB_SUPPORT_EXT_POPUP_TEST__
    ,IMG_VICON,
    IMG_GLOBAL_CLEAR,
    IMG_EARPHONE_POPUP_MAINLCD,
    IMG_EARPHONE_POPUP_SUBLCD,
    ALARM_ANIMATION_INDICATION_IMAGEID,
    IMG_ID_AUDPLY_PLAY_ANIMATION,
    IMAGE_CCBS_ACTIVATED,
    IMG_CM_SS_OUTGOING,
    IMG_ERROR_NOTIFY,
    IMG_UNFINISHED_NOTIFY,
    IMG_SCR_RESETCALLS_CONFIRM,
    IMG_ID_DTCNT_SAVE,
    IMG_EMAIL_CONNECTING_ID,
    IMG_EMAIL_SENDING_ID,
    IMG_EMAIL_RECEIVING_ID,
    IMG_EMAIL_SEND_FAIL_ID,
    IMG_EMAIL_SEND_SUCCESS_ID,
    IMAGE_EBOOK_WAIT,
    IMG_JAVA_DONE,
    IMG_THEME_ACTIVATION,
    IMG_IDLE_NETWORK_SRCH_SCR,
    IMG_NEW_MESSAGE_NOTIFICATION_MSG,
    IMG_NEW_VOICEMAIL_NOTIFICATION_MSG,
    IMG_NEW_SMS_SEND,
    IMG_SEND_FAIL_PIC_MSG,
    IMG_KPAD_SCR_UNLOCKED_HELP_MESSAGE,
    IMG_COPY_ALL_ABORTING,
    IMG_COPIED,
    IMG_ENTRY_MOVED_MSG,
    IMG_ENTRY_DUPLICATED_MSG,
    IMG_PROCESSING_PHONEBOOK,
    IMG_COPY_ALL_ABORTING,
    SAT_WAIT_IMAGE_ID,
    IMG_FLIGHT_MODE_PROGRESS,
    IMG_ID_NETSET_NW_SEARCH,
    IMG_ID_SNDREC_RECORDING,
    IMG_ID_SNDREC_PLAYING,
    IMG_ID_VOIP_MSG_WAITING,
    IMG_ID_VRSD_RECORDING,
    IMG_ID_VRSI_RECORDING,
    MEA_IMG_BROKEN_IMAGE
#endif
};

static void mmi_icon_select_hide_image_callback(S32 idx);
static void mmi_icon_select_draw_image_callback(
                S32 idx,
                S32 page_start_idx,
                S32 page_end_idx,
                BOOL is_hilighted,
                BOOL is_need_update,
                BOOL is_new_page,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2);

/* For category 201 */
//PMT00006 Need to find a way to remove these
// also defined by dictionary
S16 *g_dictionary_input_mode_CSB;   /* Input mode for dictionary screen */
S16 g_dictionary_input_mode_Chinese_set_CSB[] = 
{
    INPUT_MODE_MULTITAP_UPPERCASE_ABC,
    INPUT_MODE_MULTITAP_LOWERCASE_ABC,
    INPUT_MODE_TR_MULTITAP_BOPOMO,
    INPUT_MODE_SM_MULTITAP_PINYIN,
#if !defined(__MMI_TOUCH_SCREEN__)
    INPUT_MODE_TR_BOPOMO,
    INPUT_MODE_SM_PINYIN,
    INPUT_MODE_TR_STROKE,
    INPUT_MODE_SM_STROKE,
#endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
    -1
};

#ifdef __MMI_MESSAGES_EMS__
U8 EMS_sample_picture_object_t[] = {EMS_PREDEFINED_PICTURE, 0x01, 0x20, 0x00, 0x20, 0x00, 0x80, 0x00,
    0x00, 0xFE, 0x00, 0x00, 0x07, 0xFF, 0x80, 0x00, 0x3F, 0xFF, 0x70, 0x00, 0x7F, 0xFF, 0x8E, 0x00,
    0x47, 0xFF, 0xC1, 0xC0, 0x40, 0xFF, 0xE0, 0x38, 0x40, 0x1F, 0xF0, 0x06, 0x40, 0x03, 0xF8, 0x02,
    0x40, 0x00, 0x7C, 0x0E, 0x40, 0x00, 0x0E, 0x3E, 0x40, 0x00, 0x00, 0xFE, 0x20, 0x78, 0x03, 0xFC,
    0x22, 0x1D, 0x03, 0xFC, 0x27, 0x0F, 0x03, 0xFC, 0x2F, 0x87, 0x03, 0xFC, 0x23, 0xCF, 0x07, 0xF8,
    0x23, 0x03, 0x07, 0xF8, 0x13, 0x00, 0x07, 0xF8, 0x11, 0x00, 0x07, 0xF8, 0x11, 0x08, 0x8F, 0xF0,
    0x10, 0x88, 0x8F, 0xF0, 0x10, 0x59, 0x8F, 0xF0, 0x08, 0x3F, 0x8F, 0xE0, 0x08, 0x1F, 0x1F, 0xE0,
    0x08, 0x0C, 0x1F, 0xE0, 0x04, 0x02, 0x1F, 0xE0, 0x03, 0x00, 0x1F, 0xC0, 0x00, 0xC0, 0x1F, 0xC0,
    0x00, 0x30, 0x3F, 0xC0, 0x00, 0x0C, 0x3F, 0x00, 0x00, 0x03, 0x3C, 0x00, 0x00, 0x00, 0xF0, 0x00,
};
#endif /* __MMI_MESSAGES_EMS__ */ 

/* This is an array to store the information about Category Screens */
csb_screen_info screen_info[TOTAL_CATEGORY_SCREENS] = 
{
    /*   ID,    Category Name,     App Flags,      Control Flags,                   Entry Function Pointer */
    {0, L"14LST", CSB_MISC, CSB_MATRIX_MENU_SCR, EntryScreen_14LST},
    {0, L"14MAT", CSB_MISC, CSB_MATRIX_MENU_SCR, EntryScreen_14MAT},
    {0, L"EMS", CSB_MESSAGES, CSB_MATRIX_MENU_SCR, EntryScreen_EMS},
    {0, L"165EXT", CSB_SETTINGS, CSB_POPUP_SCR, EntryScreen_165ext},
    {1, L"1", CSB_ORGANIZER | CSB_SHORTCUT | CSB_EXTRA | CSB_CALLS, CSB_LIST_MENU_SCR, EntryScreen_1},

    {2, L"2", CSB_MESSAGES | CSB_ENGG_MODE | CSB_WAP | CSB_SETTINGS | CSB_MISC, CSB_EDITOR_SCR, EntryScreen_2},

    {5, L"5", CSB_CALLS | CSB_EDITOR | CSB_EXTRA | CSB_WAP
     | CSB_MESSAGES | CSB_ORGANIZER | CSB_PHONEBOOK
     | CSB_SETTINGS | CSB_FUN_AND_GAMES | CSB_SERVICES | CSB_ENGG_MODE | CSB_MULTIMEDIA, CSB_EDITOR_SCR, EntryScreen_5},

    {6, L"6", CSB_MESSAGES | CSB_ORGANIZER | CSB_SETTINGS
     | CSB_SERVICES | CSB_ENGG_MODE, CSB_LIST_MENU_SCR, EntryScreen_6},

    {7, L"7", CSB_MESSAGES | CSB_ORGANIZER | CSB_PHONEBOOK | CSB_ENGG_MODE | CSB_MISC, CSB_EDITOR_SCR, EntryScreen_7},

    {8, L"8", CSB_CALLS | CSB_MESSAGES | CSB_PHONEBOOK | CSB_EXTRA, CSB_EDITOR_SCR | CSB_POPUP_SCR, EntryScreen_8},

    {9, L"9", CSB_SERVICES | CSB_EXTRA, CSB_EDITOR_SCR | CSB_POPUP_SCR, EntryScreen_9},
#ifdef UI_SMALL_LIST_SCREEN
    {10, L"10", CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_10},
#endif
    {11, L"11", CSB_CALLS | CSB_FUN_AND_GAMES
     | CSB_MESSAGES | CSB_PROFILE | CSB_SETTINGS
     | CSB_SERVICES | CSB_MULTIMEDIA | CSB_ENGG_MODE | CSB_ORGANIZER, CSB_RADIO_BUTTON_SCR, EntryScreen_11},

    {12, L"12", CSB_MESSAGES, CSB_LIST_MENU_SCR | CSB_CHECK_BOX_SCR, EntryScreen_12},
    {13, L"13", CSB_ENGG_MODE, CSB_LIST_MENU_SCR | CSB_CHECK_BOX_SCR, EntryScreen_13},
    {15, L"15", CSB_CALLS | CSB_EXTRA | CSB_SHORTCUT
     | CSB_FUN_AND_GAMES | CSB_ORGANIZER | CSB_PHONEBOOK
     | CSB_SETTINGS | CSB_MULTIMEDIA | CSB_ENGG_MODE
     | CSB_FILE_MANAGER | CSB_SERVICES, CSB_LIST_MENU_SCR, EntryScreen_15},

    {16, L"16", CSB_CALLS | CSB_ENGG_MODE | CSB_MISC, CSB_IDLE_SCR, EntryScreen_16},
    {17, L"17", CSB_CALLS, CSB_CALL_SCR, EntryScreen_17},
    {18, L"18", CSB_CALLS | CSB_SERVICES, CSB_CALL_SCR, EntryScreen_18},
    {19, L"19", CSB_CALLS, CSB_LIST_MENU_SCR, EntryScreen_19},
    {20, L"20", CSB_CALLS, CSB_CALL_SCR, EntryScreen_20},
    {21, L"21", CSB_ENGG_MODE | CSB_MISC, CSB_EDITOR_SCR, EntryScreen_21},
    {22, L"22", CSB_MESSAGES, CSB_MATRIX_MENU_SCR, EntryScreen_22},
    {28, L"28", CSB_MESSAGES, CSB_EDITOR_SCR, EntryScreen_28},
    {32, L"32", CSB_FUN_AND_GAMES | CSB_MISC, CSB_EDITOR_SCR | CSB_POPUP_SCR, EntryScreen_32},
    {33, L"33", CSB_MISC, CSB_IDLE_SCR, EntryScreen_33},
    {36, L"36", CSB_MESSAGES | CSB_SETTINGS | CSB_WAP, CSB_LIST_MENU_SCR | CSB_RADIO_BUTTON_SCR, EntryScreen_36},
    {39, L"39", CSB_MESSAGES, CSB_EDITOR_SCR, EntryScreen_39},
    {52, L"52", CSB_CALLS | CSB_SERVICES | CSB_EXTRA
     | CSB_MESSAGES | CSB_FUN_AND_GAMES | CSB_WAP
     | CSB_ORGANIZER | CSB_PHONEBOOK | CSB_PROFILE
     | CSB_SETTINGS | CSB_SERVICES | CSB_MULTIMEDIA
     | CSB_ENGG_MODE | CSB_EDITOR | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_52},

    {53, L"53", CSB_CALLS | CSB_SERVICES | CSB_MESSAGES | CSB_WAP
     | CSB_ORGANIZER | CSB_PHONEBOOK | CSB_SETTINGS
     | CSB_MULTIMEDIA | CSB_ENGG_MODE | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_53},

    {55, L"55", CSB_CALLS, CSB_LIST_MENU_SCR, EntryScreen_55},
    {56, L"56", CSB_CALLS | CSB_ORGANIZER | CSB_PROFILE, CSB_LIST_MENU_SCR, EntryScreen_56},
    {57, L"57", CSB_CALLS | CSB_MESSAGES | CSB_SERVICES | CSB_EXTRA
     | CSB_ORGANIZER | CSB_FUN_AND_GAMES | CSB_WAP
     | CSB_PHONEBOOK | CSB_SETTINGS | CSB_MULTIMEDIA
     | CSB_ENGG_MODE | CSB_EDITOR | CSB_MISC, CSB_EDITOR_SCR | CSB_LIST_MENU_SCR, EntryScreen_57},

    {61, L"61", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_61},
    {62, L"62", CSB_CALLS, CSB_POPUP_SCR, EntryScreen_62},
    {63, L"63", CSB_CALLS | CSB_ENGG_MODE, CSB_POPUP_SCR, EntryScreen_63},
    {64, L"64", CSB_ENGG_MODE | CSB_MISC, CSB_POPUP_SCR, EntryScreen_64},
    {65, L"65", CSB_SERVICES | CSB_WAP | CSB_MESSAGES | CSB_MULTIMEDIA | CSB_MISC, CSB_POPUP_SCR, EntryScreen_65},

    {66, L"66", CSB_CALLS | CSB_SERVICES | CSB_EXTRA
     | CSB_SETTINGS | CSB_FUN_AND_GAMES | CSB_WAP
     | CSB_ORGANIZER | CSB_PHONEBOOK | CSB_MULTIMEDIA, CSB_EDITOR_SCR | CSB_POPUP_SCR, EntryScreen_66},

    {69, L"69", CSB_SETTINGS, CSB_EDITOR_SCR, EntryScreen_69},
 #ifdef __MMI_MENSTRUAL__
    {72, L"72", CSB_EXTRA, CSB_PROGRESS_BAR_SCR, EntryScreen_72},
 #endif 
    {73, L"73", CSB_MESSAGES | CSB_FUN_AND_GAMES | CSB_SERVICES
     | CSB_PROFILE | CSB_SETTINGS | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_73},

    {74, L"74", CSB_CALLS | CSB_SERVICES | CSB_EXTRA
     | CSB_FUN_AND_GAMES | CSB_WAP | CSB_MESSAGES
     | CSB_ORGANIZER | CSB_SETTINGS | CSB_MULTIMEDIA
     | CSB_ENGG_MODE | CSB_FILE_MANAGER | CSB_MISC, CSB_EDITOR_SCR, EntryScreen_74},

 #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    {75, L"75", CSB_EXTRA, CSB_EDITOR_SCR, EntryScreen_75},
 #endif 

    {76, L"76", CSB_WAP, CSB_EDITOR_SCR, EntryScreen_76},
 #ifdef __UI_PAGING_IN_MULTILINE_EDITOR__
    {77, L"77", CSB_EXTRA, CSB_EDITOR_SCR, EntryScreen_77},
 #endif 
    {78, L"78", CSB_EXTRA | CSB_WAP | CSB_MISC, CSB_EDITOR_SCR, EntryScreen_78},
 #ifdef ENABLE_CALENDAR_CONTROL
 #if (ENABLE_CALENDAR_CONTROL) && defined(__USE_OLD_CALENDAR__)
    {80, L"80", CSB_ORGANIZER, CSB_IMAGE_VIEWER_SCR, EntryScreen_80},
    {81, L"81", CSB_EXTRA, CSB_IMAGE_VIEWER_SCR, EntryScreen_81},
 #endif /* (ENABLE_CALENDAR_CONTROL)  && defined(__USE_OLD_CALENDAR__)*/ 
 #endif 
    {84, L"84", CSB_PHONEBOOK | CSB_CALLS | CSB_FUN_AND_GAMES
     | CSB_ORGANIZER | CSB_SERVICES | CSB_SETTINGS
     | CSB_MULTIMEDIA | CSB_WAP | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_84},
 #ifdef __MMI_ANALOG_CLOCK__
    {86, L"86", CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_86},
 #endif /* __MMI_ANALOG_CLOCK__ */        
    {87, L"87", CSB_SETTINGS | CSB_SHORTCUT | CSB_SERVICES | CSB_ENGG_MODE, CSB_SLIDER_SCR, EntryScreen_87},

    {88, L"88", CSB_SETTINGS, CSB_SLIDER_SCR, EntryScreen_88},
    {89, L"89", CSB_PHONEBOOK | CSB_ORGANIZER | CSB_PROFILE | CSB_MULTIMEDIA, CSB_LIST_MENU_SCR, EntryScreen_89},

 #ifdef __MMI_CALORIE__
/* under construction !*/
 #endif 
 #ifdef __MMI_TOUCH_SCREEN__
    {91, L"91", CSB_EDITOR | CSB_WAP, CSB_COLOR_PICKER_SCR, EntryScreen_91},
 #endif 
#if 0 /* remove for code size */
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* remove for code size */
    {105, L"105", CSB_SETTINGS, CSB_SLIDER_SCR, EntryScreen_105},
    {106, L"106", CSB_MISC, CSB_IMAGE_VIEWER_SCR, EntryScreen_106},
    {109, L"109", CSB_PHONEBOOK | CSB_MESSAGES | CSB_SERVICES, CSB_LIST_MENU_SCR | CSB_RADIO_BUTTON_SCR,
     EntryScreen_109},
    {111, L"111", CSB_CALLS | CSB_PHONEBOOK | CSB_MULTIMEDIA | CSB_SETTINGS | CSB_WAP, CSB_EDITOR_SCR, EntryScreen_111},

 #ifdef UI_SMALL_PIN_EDITOR_SCREEN
    {112, L"112", CSB_CALLS | CSB_PHONEBOOK | CSB_MULTIMEDIA | CSB_SETTINGS | CSB_WAP, CSB_EDITOR_SCR, EntryScreen_112},
 #endif 
	{120, L"120", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_120},
    {121, L"121", CSB_ORGANIZER, CSB_POPUP_SCR, EntryScreen_121},
 #ifdef __MMI_BMI__
    {122, L"122", CSB_EXTRA, CSB_SLIDER_SCR, EntryScreen_122},
 #endif 
    {123, L"123", CSB_CALLS | CSB_ORGANIZER | CSB_SETTINGS | CSB_WAP, CSB_POPUP_SCR, EntryScreen_123},
 #ifdef __MMI_CALORIE__
/* under construction !*/
 #endif 
    {128, L"128", CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_128},
    {129, L"129", CSB_EXTRA | CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_129},
    {130, L"130", CSB_EXTRA | CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_130},
    {131, L"131", CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_131},
    {140, L"140", CSB_MESSAGES | CSB_PHONEBOOK | CSB_SERVICES
     | CSB_ORGANIZER | CSB_PROFILE, CSB_LIST_MENU_SCR | CSB_CHECK_BOX_SCR, EntryScreen_140},

    {141, L"141", CSB_CALLS | CSB_MESSAGES | CSB_ORGANIZER
     | CSB_SERVICES, CSB_EDITOR_SCR | CSB_POPUP_SCR, EntryScreen_141},

    {142, L"142", CSB_PHONEBOOK, CSB_IMAGE_VIEWER_SCR, EntryScreen_142},
 #ifdef __MMI_MESSAGES_EMS__
    {143, L"143", CSB_MESSAGES, CSB_LIST_MENU_SCR, EntryScreen_143},
    {144, L"144", CSB_MESSAGES | CSB_FILE_MANAGER, CSB_IMAGE_VIEWER_SCR, EntryScreen_144},
 #endif /* __MMI_MESSAGES_EMS__ */ 
    {145, L"145", CSB_MESSAGES, CSB_POPUP_SCR, EntryScreen_145},
    {150, L"150", CSB_FUN_AND_GAMES, CSB_LIST_MENU_SCR, EntryScreen_150},
    {151, L"151", CSB_SERVICES | CSB_EXTRA, CSB_POPUP_SCR, EntryScreen_151},
    {152, L"152", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_152},
    {153, L"153", CSB_FUN_AND_GAMES, CSB_LIST_MENU_SCR, EntryScreen_153},
    {154, L"154", CSB_CALLS | CSB_MESSAGES | CSB_WAP | CSB_EXTRA
     | CSB_MULTIMEDIA | CSB_MISC, CSB_POPUP_SCR, EntryScreen_154},

 #ifdef __MMI_LCD_PARTIAL_ON__
    {161, L"161", CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_161},
 #endif 
    {162, L"162", CSB_SETTINGS, CSB_POPUP_SCR, EntryScreen_162},
    {164, L"164", CSB_MESSAGES | CSB_PHONEBOOK | CSB_MULTIMEDIA | CSB_ENGG_MODE, CSB_POPUP_SCR, EntryScreen_164},

    {165, L"165", CSB_WAP | CSB_MISC | CSB_MULTIMEDIA, CSB_POPUP_SCR, EntryScreen_165},
    {166, L"166", CSB_MISC, CSB_IMAGE_VIEWER_SCR, EntryScreen_166},
    {170, L"170", CSB_FUN_AND_GAMES, CSB_LIST_MENU_SCR, EntryScreen_170},
    {171, L"171", CSB_SERVICES, CSB_EDITOR_SCR, EntryScreen_171},
    {172, L"172", CSB_SERVICES, CSB_LIST_MENU_SCR | CSB_RADIO_BUTTON_SCR, EntryScreen_172},
    {174, L"174", CSB_SERVICES, CSB_LIST_MENU_SCR, EntryScreen_174},
    {184, L"184", CSB_EXTRA | CSB_WAP | CSB_MESSAGES | CSB_ORGANIZER
     | CSB_PHONEBOOK | CSB_SERVICES | CSB_SETTINGS | CSB_MULTIMEDIA | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_184},

    {185, L"185", CSB_FUN_AND_GAMES, CSB_LIST_MENU_SCR, EntryScreen_185},
    {200, L"200", CSB_PHONEBOOK | CSB_EXTRA, CSB_LIST_MENU_SCR, EntryScreen_200},
    {201, L"201", CSB_EXTRA, CSB_LIST_MENU_SCR, EntryScreen_201},
    {204, L"204", CSB_ENGG_MODE, CSB_EDITOR_SCR, EntryScreen_204},
    {205, L"205", CSB_ENGG_MODE, CSB_EDITOR_SCR, EntryScreen_205},
    {211, L"211", CSB_PHONEBOOK | CSB_FILE_MANAGER | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_211},
    {212, L"212", CSB_PHONEBOOK | CSB_FILE_MANAGER | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_212},
    {213, L"213", CSB_FILE_MANAGER, CSB_LIST_MENU_SCR, EntryScreen_213},
    {214, L"214", CSB_EDITOR | CSB_FILE_MANAGER, CSB_MATRIX_MENU_SCR, EntryScreen_214},
    {221, L"221", CSB_FUN_AND_GAMES | CSB_MULTIMEDIA | CSB_EDITOR, CSB_IMAGE_VIEWER_SCR, EntryScreen_221},

    {222, L"222", CSB_MESSAGES | CSB_MULTIMEDIA | CSB_FUN_AND_GAMES
     | CSB_PHONEBOOK | CSB_SETTINGS | CSB_FILE_MANAGER | CSB_EDITOR | CSB_MISC, CSB_IMAGE_VIEWER_SCR, EntryScreen_222},

    {223, L"223", CSB_MULTIMEDIA, CSB_IMAGE_VIEWER_SCR, EntryScreen_223},
#ifdef __MMI_VIDEO_PLAYER__    
    {224, L"224", CSB_SETTINGS, CSB_IMAGE_VIEWER_SCR, EntryScreen_224},
    {225, L"225", CSB_PHONEBOOK | CSB_SETTINGS | CSB_FUN_AND_GAMES | CSB_WAP, CSB_IMAGE_VIEWER_SCR, EntryScreen_225},
 #endif /* __MMI_VIDEO_PLAYER__ */ 
    {227, L"227", CSB_MISC, CSB_IMAGE_VIEWER_SCR, EntryScreen_227},
    {228, L"228", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_228},
#ifdef __MMI_WC_TZ_SUPPORT__
    {230, L"230", CSB_ORGANIZER, CSB_IMAGE_VIEWER_SCR, EntryScreen_230},
#endif 
    {257, L"257", CSB_EXTRA, CSB_EDITOR_SCR | CSB_LIST_MENU_SCR, EntryScreen_257},
    {261, L"261", CSB_MESSAGES, CSB_LIST_MENU_SCR, EntryScreen_261},
    {262, L"262", CSB_MESSAGES, CSB_LIST_MENU_SCR, EntryScreen_262},
    {263, L"263", CSB_MESSAGES, CSB_LIST_MENU_SCR, EntryScreen_263},
#ifdef __MMI_TOUCH_SCREEN__
    {264, L"264", CSB_MISC, CSB_POPUP_SCR, EntryScreen_264},
#endif 
#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
    {265, L"265", CSB_MULTIMEDIA, CSB_LIST_MENU_SCR, EntryScreen_265},
#endif 
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    {273, L"273", CSB_PHONEBOOK, CSB_LIST_MENU_SCR, EntryScreen_273},
#endif 
    {276, L"276", CSB_WAP, CSB_PROGRESS_BAR_SCR, EntryScreen_276},
    {277, L"277", CSB_WAP, CSB_EDITOR_SCR, EntryScreen_277},
    {284, L"284", CSB_SETTINGS, CSB_LIST_MENU_SCR, EntryScreen_284},
#ifdef __MMI_SUBLCD__
    {301, L"301", CSB_SETTINGS | CSB_ENGG_MODE | CSB_MULTIMEDIA, CSB_SUB_LCD, EntryScreen_301},
    {302, L"302", CSB_CALLS, CSB_SUB_LCD, EntryScreen_302},
    {303, L"303", CSB_MISC, CSB_SUB_LCD, EntryScreen_303},
    {304, L"304", CSB_CALLS | CSB_MESSAGES | CSB_ORGANIZER | CSB_MISC, CSB_SUB_LCD, EntryScreen_304},
#endif /* __MMI_SUBLCD__ */ 
    {305, L"305", CSB_MESSAGES, CSB_EDITOR_SCR, EntryScreen_305},
#ifdef __MMI_STOPWATCH__
    {306, L"306", CSB_FUN_AND_GAMES, CSB_IMAGE_VIEWER_SCR, EntryScreen_306},
    {307, L"307", CSB_FUN_AND_GAMES, CSB_IMAGE_VIEWER_SCR, EntryScreen_307},
#endif /* __MMI_STOPWATCH__ */ 
#ifdef __MMI_SUBLCD__
    {310, L"310", CSB_MISC, CSB_SUB_LCD, EntryScreen_310},
    {311, L"311", CSB_CALLS, CSB_SUB_LCD, EntryScreen_311},
    {312, L"312", CSB_MISC, CSB_SUB_LCD, EntryScreen_312},
    {313, L"313", CSB_MISC, CSB_SUB_LCD, EntryScreen_313},
    {314, L"314", CSB_MULTIMEDIA, CSB_SUB_LCD, EntryScreen_314},
    {332, L"332", CSB_CALLS | CSB_FUN_AND_GAMES, CSB_SUB_LCD, EntryScreen_332},
    {333, L"333", CSB_MISC, CSB_SUB_LCD, EntryScreen_333},
#endif /* __MMI_SUBLCD__ */ 
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    {334, L"334", CSB_SETTINGS, CSB_SLIDER_SCR, EntryScreen_334},
#endif
    {353, L"353", CSB_FUN_AND_GAMES | CSB_MESSAGES | CSB_SETTINGS | CSB_WAP, CSB_LIST_MENU_SCR, EntryScreen_353},
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    {357, L"357", CSB_EXTRA, CSB_EDITOR_SCR | CSB_LIST_MENU_SCR, EntryScreen_357},
#endif 
    {384, L"384", CSB_PHONEBOOK, CSB_LIST_MENU_SCR, EntryScreen_384},
    {400, L"400", CSB_ENGG_MODE, CSB_EDITOR_SCR, EntryScreen_400},
    {402, L"402", CSB_MISC | CSB_MULTIMEDIA, CSB_PROGRESS_BAR_SCR, EntryScreen_402},
    {403, L"403", CSB_SERVICES, CSB_LIST_MENU_SCR, EntryScreen_403},
    {404, L"404", CSB_SERVICES, CSB_EDITOR_SCR, EntryScreen_404},
    {412, L"412", CSB_MISC | CSB_MULTIMEDIA, CSB_PROGRESS_BAR_SCR, EntryScreen_412},
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    {414, L"414", CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_414},
#endif 
    {420, L"420", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_420},
    {425, L"425", CSB_SERVICES | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_425},
    {427, L"427", CSB_SERVICES | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_427},
    {430, L"430", CSB_CALLS, CSB_EDITOR_SCR, EntryScreen_430},
    {435, L"435", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_435},
#ifdef __MMI_CAT44X_SUPPORT__
    {441, L"441", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_441},
    {442, L"442", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_442},    
    {445, L"445", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_445},
    {443, L"443", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_443},
    {447, L"447", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_447},
    {448, L"448", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_448},
    {449, L"449", CSB_MISC, CSB_EDITOR_SCR, EntryScreen_449},
#endif /* __MMI_CAT44X_SUPPORT__ */
    {501, L"501", CSB_WAP, CSB_EDITOR_SCR, EntryScreen_501},
        
    {626, L"626", CSB_SERVICES | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_626},
    {657, L"657", CSB_SERVICES | CSB_MISC, CSB_LIST_MENU_SCR, EntryScreen_657},   
};

extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
extern void ShowCategory205Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);

/*************************************************************
*********************** ENTRY HANDLERS ***********************
**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_EMS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_EMS(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    U16 ItemList[] = 
    {
        STR_ID_CSB_MENUITEM1_TEXT,
        STR_ID_CSB_MENUITEM2_TEXT,
        STR_ID_CSB_MENUITEM3_TEXT,
        STR_ID_CSB_MENUITEM4_TEXT,
        STR_ID_CSB_MENUITEM5_TEXT,
        STR_ID_CSB_MENUITEM6_TEXT
    };

    U16 Iconlist[] = 
    {
        IMG_GLOBAL_L1,
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        IMG_GLOBAL_L4,
        IMG_GLOBAL_L5,
        IMG_GLOBAL_L6
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategoryEMSScreen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        Iconlist,
        ItemList,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 ItemList[4];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 4; index++)
    {
        ItemList[index] = (U16)(STR_ID_CSB_MENUITEM1_TEXT + index);
    }

    ShowCategory1Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        ItemList,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_2(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory2Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category5");
    
    ShowCategory5Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        IMG_GLOBAL_OK,
        STR_ID_CSB_RSK_TEXT,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (U8*) g_buffer,
        G_BUF_STRING_LEN,
        guiBuffer);
    
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_6
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_6(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U8 *guiBuffer = NULL;
    U8 *itemlist[5];
    U8 *itemlist1[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 5; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        itemlist1[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT_BUF + index));
    }

    ShowCategory6Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        itemlist,
        itemlist1,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_7
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_7(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category 7");

    ShowCategory7Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (PU8) g_buffer,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_8(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory8Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        IMG_GLOBAL_WARNING,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_9
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_9(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory9Screen(STR_ID_CSB_DUMMY_TEXT, IMG_GLOBAL_WARNING, guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef UI_SMALL_LIST_SCREEN
/*****************************************************************************
 * FUNCTION
 *  EntryScreen_10
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_10(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    U16 ItemList[] = 
    {
        STR_ID_CSB_MENUITEM1_TEXT,
        STR_ID_CSB_MENUITEM2_TEXT,
        STR_ID_CSB_MENUITEM3_TEXT
    };

    U16 Iconlist[] = 
    {
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory10Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        3,
        ItemList,
        Iconlist,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#endif /* UI_SMALL_LIST_SCREEN */


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_11
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_11(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;
    U16 ItemList[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 5; index++)
    {
        ItemList[index] = (U16)(STR_ID_CSB_MENUITEM1_TEXT + index);
    }

    ShowCategory11Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        ItemList,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_12
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_12(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;
    U8 *itemlist[5];
    U8 ItemListState[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 5; index++)
    {
        itemlist[index] = (PU8) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        ItemListState[index] = 0;
    }
 
    ShowCategory12Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        itemlist,
        (U8*) ItemListState,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_13
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_13(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;
    U16 ItemList[4];
    U8 ItemListState[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 4; index++)
    {
        ItemList[index] = (U16)(STR_ID_CSB_MENUITEM1_TEXT + index);
        ItemListState[index] = 0;
    }

    ShowCategory13Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        ItemList,
        ItemListState,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

/* New flavour of Main menu categoru 14 */


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_14LST
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_14LST(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 ItemList[] = 
    {
        STR_ID_CSB_MENUITEM1_TEXT,
        STR_ID_CSB_MENUITEM2_TEXT,
        STR_ID_CSB_MENUITEM3_TEXT,
        STR_ID_CSB_MENUITEM4_TEXT,
        STR_ID_CSB_MENUITEM5_TEXT,
        STR_ID_CSB_MENUITEM6_TEXT
    };

    U16 Iconlist[] = 
    {
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory14Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        ItemList,
        Iconlist,
        LIST_MENU,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

/* New flavour of Main menu categoru 14 */


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_14MAT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_14MAT(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 ItemList[] = 
    {
        STR_ID_CSB_MENUITEM1_TEXT,
        STR_ID_CSB_MENUITEM2_TEXT,
        STR_ID_CSB_MENUITEM3_TEXT,
        STR_ID_CSB_MENUITEM4_TEXT,
        STR_ID_CSB_MENUITEM5_TEXT,
        STR_ID_CSB_MENUITEM6_TEXT
    };

    U16 Iconlist[] = 
    {
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory14Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        ItemList,
        Iconlist,
        MATRIX_MENU,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_15
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_15(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nItems;

    U16 nStrItemList[] = 
    {
        STR_ID_CSB_MENUITEM1_TEXT,
        STR_ID_CSB_MENUITEM2_TEXT,
        STR_ID_CSB_MENUITEM3_TEXT,
        STR_ID_CSB_MENUITEM4_TEXT,
        STR_ID_CSB_MENUITEM5_TEXT,
        STR_ID_CSB_MENUITEM6_TEXT,
        STR_ID_CSB_MENUITEM7_TEXT
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    nItems = GetNumOfChild(CSB_DUMMY_PARENT_MENUID);
    SetParentHandler(CSB_DUMMY_PARENT_MENUID);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    ShowCategory15Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        nItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_16
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_16(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);

    ShowCategory16Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        G_BUF_STRING_LEN,
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_17
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_17(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
	U8 display_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "JOE17");

    ShowCategory17Screen(
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        g_buffer1,
        NULL,
        IMG_CM_ICON_LINE2,
        IMG_PHB_DEFAULT,
        IMG_PHB_DEFAULT,
        NULL,
        display_type,
        0,
        FALSE,
        FALSE,
        FALSE,
        (U8*) guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_18
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_18(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "MAC18");

    ShowCategory18Screen(
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        g_buffer1,
        NULL,
        IMG_CM_ICON_LINE2,
        IMG_PHB_DEFAULT,
        NULL,
        FALSE,
        (U8*) guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_19
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_19(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;
    U8 *guiBuffer = NULL;
    S32 index;
    U8 *itemlist[2];
    U16 nImgIds[2];
    U16 callstates[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    callstates[0] = IMG_CM_ICON_LINE2;
    callstates[1] = IMG_CM_ICON_LINE1;

    for (index = 0; index < 2; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        nImgIds[index] = IMG_CM_STATE_ACTIVE;//19210;//061507 128x160 touch
    }

    GetDateTime(&time);

    ShowCategory19Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        itemlist,
        callstates,
        nImgIds,
        (UI_time*) & time,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_20
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_20(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category20");

    GetDateTime(&time);

    ShowCategory20Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        (UI_time*) & time,
        IMG_CM_ICON_LINE1,
        0,
        MMI_TRUE,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_21
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_21(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory21Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_22
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_22(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    SymbolPickerSymbols[34] = SymbolPickerSpaceString;
    SymbolPickerSymbols[35] = SymbolPickerLFString;

    ShowCategory22Screen(
        STR_INPUT_METHOD_MENU_SELECT_SYMBOL,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        36,
        (U8 **) SymbolPickerSymbols,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_28
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_28(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEMSData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    GetEMSDataForEdit(&pEMSData, 0);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    
    pEMSData->textBuffer = (PU8) g_buffer;
    pEMSData->textLength = 0;

    ShowCategory28Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        pEMSData,
        guiBuffer);

    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_32
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_32(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U8 *guiBuffer = NULL;
    U8 *itemlist[3];
    U8 *itemicons[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 3; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        itemicons[index] = (U8*) GetImage((U16)(gIndexIconsImageList[index]));
    }

    ShowCategory32Screen(
        (U8*) get_string(STR_ID_CSB_CATEGORY_TEXT),
        NULL,
        (U8*) GetString(STR_ID_CSB_LSK_TEXT),
        NULL,
        (U8*) GetString(STR_ID_CSB_RSK_TEXT),
        NULL,
        index,
        itemlist,
        itemicons,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_33
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_33(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_idle_pen_block();
#endif 

    ShowCategory33Screen(STR_ID_CSB_LSK_TEXT, 0, STR_ID_CSB_RSK_TEXT, 0, guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_36
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_36(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U8 *guiBuffer = NULL;
    U8 *itemlist[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 6; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
    }

    ShowCategory36Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        itemlist,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_39
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_39(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSData *pEMSData;
    S8 buffer[120 * ENCODING_LENGTH];
    S8 tempbuffer[60];
    S8 buf2[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    GetEMSDataForEdit(&pEMSData, 0);

    mmi_asc_to_ucs2(buf2, "\n");
    mmi_asc_to_ucs2(tempbuffer, "New Message");
    mmi_ucs2cpy(buffer, tempbuffer);
    mmi_ucs2cat(buffer, buf2);

    mmi_asc_to_ucs2(tempbuffer, (S8*) "+9876545465");
    mmi_ucs2cat(buffer, buf2);

    mmi_asc_to_ucs2(tempbuffer, "mitesh");
    mmi_ucs2cat(buffer, tempbuffer);
    mmi_ucs2cat(buffer, buf2);

    mmi_asc_to_ucs2(tempbuffer, "12/12/2006");
    mmi_ucs2cat(buffer, tempbuffer);
    mmi_ucs2cat(buffer, buf2);

    mmi_asc_to_ucs2(tempbuffer, "06:07:05");
    mmi_ucs2cat(buffer, tempbuffer);
    mmi_ucs2cat(buffer, buf2);

    mmi_asc_to_ucs2(tempbuffer, "how about lunch?");

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category39-Message");

    pEMSData->textBuffer = (PU8) g_buffer;
    pEMSData->textLength = 40;

    ShowCategory39Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        pEMSData,
        (U8*) buffer,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_52
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_52(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 ItemIcons[3];
    U8 *guiBuffer;
    U8 *PopUpList[3];
    U16 ItemList[3];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    for (index = 0; index < 3; index++)
    {
        ItemList[index] = (U16)(STR_ID_CSB_MENUITEM1_TEXT + index);
        PopUpList[index] = (PU8) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT_BUF + index));
        ItemIcons[index] = (U16) (IMG_GLOBAL_L1 + index);
    }

    ShowCategory52Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        3,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_53
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_53(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;
    U16 nImgIds[6];

#ifdef __UCS2_ENCODING
    U8 strName[6][12] = { {'N', 0, 'a', 0, 'm', 0, 'e', 0, '1', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '2', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '3', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '4', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '5', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '6', 0, '\0', '\0'}
    };
    U8 strphonenumber[22] = { '9', 0, '8', 0, '7', 0, '7', 0, '5', 0, '5', 0, '4', 0, '3', 0, '9', 0, '8', 0, 0, 0};
    
#else /* __UCS2_ENCODING */ 
    U8 strName[][10] = { "Name1", "Name2", "Name3", "Name4", "Name5", "Name6" };
    U8 strphonenumber[11] = "9875656578";
#endif /* __UCS2_ENCODING */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 6; index++)
    {
        memcpy(subMenuData[index], strName[index], 10);
        subMenuDataPtrs[index] = subMenuData[index];
        nImgIds[index] = IMG_MENU8102_DIALED_CALLS;
    #ifdef __UCS2_ENCODING
        memcpy(subMenuData[index + 6], strphonenumber, 22);
        subMenuDataPtrs[index + 6] = subMenuData[index + 6];
    #else /* __UCS2_ENCODING */ 
        memcpy(subMenuData[index + 6], strphonenumber, 11);
        subMenuDataPtrs[index + 6] = subMenuData[index + 6];
    #endif /* __UCS2_ENCODING */ 
    }

    ShowCategory53Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        subMenuDataPtrs,
        (U16*) nImgIds,
        &subMenuDataPtrs[6],
        LIST_MENU,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_55
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_55(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[6];
    U8 *guiBuffer = NULL;
    S32 index;

#ifdef __UCS2_ENCODING
    U8 strphonenumber[22] = { '9', 0, '8', 0, '7', 0, '7', 0, '5', 0, '5', 0, '4', 0, '3', 0, '9', 0, '8', 0, 0, 0};
#else /* __UCS2_ENCODING */ 
    U8 strphonenumber[11] = "9875656578";
#endif /* __UCS2_ENCODING */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 6; index++)
    {

        ItemList[index] = (U16)(STR_ID_CSB_MENUITEM1_TEXT + index);
    #ifdef __UCS2_ENCODING
        memcpy(subMenuData[index + 7], strphonenumber, 22);
        subMenuDataPtrs[index + 7] = subMenuData[index + 7];
    #else /* __UCS2_ENCODING */ 
        memcpy(subMenuData[index + 7], strphonenumber, 11);
        subMenuDataPtrs[index + 7] = subMenuData[index + 7];
    #endif /* __UCS2_ENCODING */ 
    }

    ShowCategory55Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        ItemList,
        &subMenuDataPtrs[7],
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_56
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_56(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;

#ifdef __UCS2_ENCODING
    U8 strName[6][12] = { {'N', 0, 'a', 0, 'm', 0, 'e', 0, '1', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '2', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '3', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '4', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '5', 0, '\0', '\0'},
    {'N', 0, 'a', 0, 'm', 0, 'e', 0, '6', 0, '\0', '\0'}
    };
    U8 strphonenumber[22] = { '9', 0, '8', 0, '7', 0, '7', 0, '5', 0, '5', 0, '4', 0, '3', 0, '9', 0, '8', 0, 0, 0};
#else /* __UCS2_ENCODING */ 
    U8 strName[][10] = { "Name1", "Name2", "Name3", "Name4", "Name5", "Name6" };
    U8 strphonenumber[11] = "9875656578";
#endif /* __UCS2_ENCODING */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 6; index++)
    {
        memcpy(subMenuData[index], strName[index], 10);
        subMenuDataPtrs[index] = subMenuData[index];
    #ifdef __UCS2_ENCODING
        memcpy(subMenuData[index + 7], strphonenumber, 22);
        subMenuDataPtrs[index + 7] = subMenuData[index + 7];
    #else /* __UCS2_ENCODING */ 
        memcpy(subMenuData[index + 7], strphonenumber, 11);
        subMenuDataPtrs[index + 7] = subMenuData[index + 7];
    #endif /* __UCS2_ENCODING */ 
    }
    ShowCategory56Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        index,
        subMenuDataPtrs,
        &subMenuDataPtrs[7],
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_57
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_57(void)
{
    EntryScreen_657();    
}

void csb_full_screen_edit(void);
/*****************************************************************************
 * FUNCTION
 *  CSBAppFillInlineStruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void CSBAppFillInlineStruct(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tempbuffer[40];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    /* Student Record */
    mmi_asc_to_ucs2((PS8) tempbuffer, (PS8) "Student-Record");
    SetInlineItemActivation(&wgui_inline_items[0], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[0]);

    /* Student Name Caption */
    mmi_asc_to_ucs2((PS8) tempbuffer, (PS8) "Name");
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[1], (U8*) GetString(STR_ID_CSB_MENUITEM2_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[1]);

    /* Name */
     SetInlineItemActivation(&wgui_inline_items[2], KEY_LSK, KEY_EVENT_UP);
    //SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemFullScreenEdit(&wgui_inline_items[2], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer, 20, INPUT_TYPE_NUMERIC);
    //SetInlineItemTextEdit(&wgui_inline_items[4], (U8*) g_buffer1, 20, INPUT_TYPE_NUMERIC);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[2], 
        csb_full_screen_edit);

    /* Student Age Caption */
    mmi_asc_to_ucs2((PS8) tempbuffer, (PS8) "Age");
    SetInlineItemActivation(&wgui_inline_items[3], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[3], (U8*) GetString(STR_ID_CSB_MENUITEM3_TEXT));
    SetInlineItemFullWidth(&wgui_inline_items[3]);

    /* Age */
    SetInlineItemActivation(&wgui_inline_items[4], KEY_LSK, KEY_EVENT_UP);
    //SetInlineItemActivation(&wgui_inline_items[4], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemFullScreenEdit(&wgui_inline_items[4], STR_GLOBAL_OPTIONS, GetRootTitleIcon(SERVICES_WAP_MENU_ID), g_buffer1, 20, INPUT_TYPE_NUMERIC);
    //SetInlineItemTextEdit(&wgui_inline_items[4], (U8*) g_buffer1, 20, INPUT_TYPE_NUMERIC);
    SetInlineFullScreenEditCustomFunction(
        &wgui_inline_items[4], 
        csb_full_screen_edit);
}

void csb_full_screen_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
    SetInputMethodAndDoneCaptionIcon(GetRootTitleIcon(SERVICES_WAP_MENU_ID));
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_61
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_61(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category61");

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);

    ShowCategory61Screen((U8*) g_buffer, IMG_ID_PHNSET_WP_4, guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_62
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_62(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);

    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    ShowCategory62Screen(STR_ID_CSB_CATEGORY_TEXT, PopupImageGroup[current_popup_index], guiBuffer);
    current_popup_index++;
    if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
    {
        current_popup_index = 0;
    }

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_63
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_63(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory63Screen((U8*)get_string(STR_ID_CSB_CATEGORY_TEXT), PopupImageGroup[current_popup_index], guiBuffer);
    current_popup_index++;
    if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
    {
        current_popup_index = 0;
    }
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_64
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_64(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory64Screen(STR_ID_CSB_CATEGORY_TEXT, PopupImageGroup[current_popup_index], guiBuffer);
    current_popup_index++;
    if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
    {
        current_popup_index = 0;
    }
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_65
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_65(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory65Screen((U8*)get_string(STR_ID_CSB_CATEGORY_TEXT), PopupImageGroup[current_popup_index], guiBuffer);
    current_popup_index++;
    if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
    {
        current_popup_index = 0;
    }
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_66
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_66(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory66Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (PU8) GetString(STR_GLOBAL_SEARCHING),
        PopupImageGroup[current_popup_index],
        guiBuffer);
    current_popup_index++;
    if (current_popup_index > MAX_POPUP_IMAGE_INDEX)
    {
        current_popup_index = 0;
    }
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_69
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_69(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);

    ShowCategory69Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        INPUT_TYPE_NUMERIC,
        (U8*) g_buffer,
        G_BUF1_STRING_LEN,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_MENSTRUAL__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_72
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_72(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 Prob = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category72-Message");

    ShowCategory72Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        Prob,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_MENSTRUAL__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_73
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_73(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *itemlist[4];
    U8 index;
    U16 Iconstates[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 4; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        Iconstates[index] = IMG_PROFILES_OUTDOOR;
    }

    ShowCategory73Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        itemlist,
        Iconstates,
        (U16*) gIndexIconsImageList,
        0,
        guiBuffer,
        ICON_ICON_TEXT);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_74
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_74(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category74");

    ShowCategory74Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        mmi_ucs2strlen((S8*) g_buffer),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_75
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_75(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_page_info_app ebook_frm_setting_struct_csb;
    gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category75");
    
    ebook_frm_setting_csb->end_id = 10;
    ebook_frm_setting_csb->start_id = 1;
    ebook_frm_setting_csb->doc_size = 100;
    ebook_frm_setting_csb->last_text_offset_y = 0;
    ebook_frm_setting_csb->jump_offset_from_app = 0;
    ebook_frm_setting_csb->text_offset = 0;
    ebook_frm_setting_csb->scroll_speed = 0;
    ebook_frm_setting_csb->scroll_type = 1;
    ebook_frm_setting_csb->scroll_flag = 0;
    ebook_frm_setting_csb->font_size = 1;
    ebook_frm_setting_csb->search_str_len = 3;
    ebook_frm_setting_csb->font_style = 0;
    ebook_frm_setting_csb->jump_to_end = FALSE;
    ebook_frm_setting_csb->highlight_string = FALSE;
    ebook_frm_setting_csb->search_flag_is_on = FALSE;
    ebook_frm_setting_csb->last_showed_percentage = 10;

    ShowCategory75Screen(
        (U16*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        mmi_ucs2strlen((S8*) g_buffer),
        NULL,
        &ebook_frm_setting_csb);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_76
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_76(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category76");

    ShowCategory76Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        mmi_ucs2strlen((S8*) g_buffer),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __UI_PAGING_IN_MULTILINE_EDITOR__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_77
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_77(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_page_info_app ebook_frm_setting_struct_csb;
    gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category77");
    
    ebook_frm_setting_csb->end_id = 10;
    ebook_frm_setting_csb->start_id = 1;
    ebook_frm_setting_csb->doc_size = 100;
    ebook_frm_setting_csb->last_text_offset_y = 0;
    ebook_frm_setting_csb->jump_offset_from_app = 0;
    ebook_frm_setting_csb->text_offset = 0;
    ebook_frm_setting_csb->scroll_speed = 0;
    ebook_frm_setting_csb->scroll_type = 1;
    ebook_frm_setting_csb->scroll_flag = 0;
    ebook_frm_setting_csb->font_size = 1;
    ebook_frm_setting_csb->search_str_len = 3;
    ebook_frm_setting_csb->font_style = 0;
    ebook_frm_setting_csb->jump_to_end = FALSE;
    ebook_frm_setting_csb->highlight_string = FALSE;
    ebook_frm_setting_csb->search_flag_is_on = FALSE;
    ebook_frm_setting_csb->last_showed_percentage = 1;

    ShowCategory77Screen(
        (U16*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        mmi_ucs2strlen((S8*) g_buffer),
        NULL,
        &ebook_frm_setting_csb);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __UI_PAGING_IN_MULTILINE_EDITOR__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_78
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_78(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category78");

    ShowCategory78Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        NULL,
        (U8*) g_buffer,
        mmi_ucs2strlen((S8*) g_buffer),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


#ifdef ENABLE_CALENDAR_CONTROL
#if(ENABLE_CALENDAR_CONTROL) && defined(__USE_OLD_CALENDAR__)
/*****************************************************************************
 * FUNCTION
 *  EntryScreen_80
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_80(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    InitializeCategory80Screen(01, 30, 06, 06, 2002);

    ShowCategory80Screen(STR_ID_CSB_LSK_TEXT, NULL, STR_ID_CSB_RSK_TEXT, NULL, guiBuffer);

#ifdef __MMI_TOUCH_SCREEN__
    SetCalendarMonthChangeFunctions(wgui_calendar_previous_month, wgui_calendar_next_month);
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
    SetCalendarYearChangeFunctions(wgui_calendar_previous_year, wgui_calendar_next_year);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_81
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_81(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    InitializeCategory81Screen(01, 30, 06, 06, 2002);

    ShowCategory81Screen(
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        STR_ID_CSB_LSK_TEXT,
        NULL,
        STR_ID_CSB_RSK_TEXT,
        NULL,
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        guiBuffer);

#ifdef __MMI_TOUCH_SCREEN__
    SetCalendarMonthChangeFunctions(wgui_calendar_previous_month, wgui_calendar_next_month);
#endif 

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* (ENABLE_CALENDAR_CONTROL) && defined(__USE_OLD_CALENDAR__) */ 
#endif /* ENABLE_CALENDAR_CONTROL */


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_84
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_84(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *itemlist[5];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 5; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
    }

    ShowCategory84Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        5,
        (U8 **) itemlist,
        (PU16) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_ANALOG_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  EntryScreen_86
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_86(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    wgui_set_touch_title_bar_buttons();

    ShowCategory86Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        IMG_ID_PHNSET_WP_5,
        NULL,
        guiBuffer,
        0);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_ANALOG_CLOCK__ */

/*****************************************************************************
 * FUNCTION
 *  EntryScreen_87
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_87(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 value = 2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory87Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        1,
        10,
        &value,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_88
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_88(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 lower_limit[1];
    S32 upper_limit[1];
    S32 *current_value[1];
    S32 value = 25;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    lower_limit[0] = 5;
    upper_limit[0] = 60;
    current_value[0] = &value;

    ShowCategory88Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        IMG_ID_PHNSET_WP_3,
        1,
        NULL,
        lower_limit,
        upper_limit,
        current_value,
        NULL,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_89
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_89(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *itemlist[6];
    U8 *itemlist1[6];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 6; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        itemlist1[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT_BUF + index));
    }

    ShowCategory89Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        itemlist,
        itemlist1,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_CALORIE__
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
#endif /* __MMI_CALORIE__ */ 

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_91
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_cat91_color_slider_enum highlighted_slider = MMI_CAT91_COLOR_SLIDER_RED_COLOR;//061507 128x160 touch
void EntryScreen_91(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 g_custom_color_RGB_list[3];
    U32 g_text_custom_color_RGB = 0x00000064;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    g_custom_color_RGB_list[0] = (U8) ((0xFF000000 & g_text_custom_color_RGB) >> 24);
    g_custom_color_RGB_list[1] = (U8) ((0x00FF0000 & g_text_custom_color_RGB) >> 16);
    g_custom_color_RGB_list[2] = (U8) ((0x0000FF00 & g_text_custom_color_RGB) >> 8);

    ShowCategory91Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        &g_custom_color_RGB_list[0],
        &g_custom_color_RGB_list[1],
        &g_custom_color_RGB_list[2],
        &highlighted_slider,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* 052907 CSB Start */
#if 0 /* remove for code size */
#if defined(__MMI_MAINLCD_128X128__)
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
#elif defined(__MMI_MAINLCD_128X160__)
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
#elif defined(__MMI_MAINLCD_176X220__)
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
#elif defined(__MMI_MAINLCD_240X320__)
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
#endif
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
#endif /* remove for code size */

/*****************************************************************************
 * FUNCTION
 *  EntryScreen_105
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_105(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    volume = 3;

    ShowCategory105Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        &volume,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_106
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_106(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);

    ShowCategory106Screen(IMG_USB_POWER_ON, NULL, guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_109
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_109(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *ItemList[3];
    U8 *hintlist[3];
    U8 nItems = 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ItemList[0] = (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT);
    ItemList[1] = (U8*) GetString(STR_ID_CSB_MENUITEM2_TEXT);
    ItemList[2] = (U8*) GetString(STR_ID_CSB_MENUITEM3_TEXT);

    hintlist[0] = (U8*) "0";
    hintlist[1] = (U8*) "1";
    hintlist[2] = (U8*) "2";

    ShowCategory109Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        nItems,
        ItemList,
        hintlist,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_111
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_111(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Message");

    ShowCategory111Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        INPUT_TYPE_NUMERIC_PASSWORD,
        g_buffer,
        CSB_MAX_BUFFER_LEN,
        g_buffer1,
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef UI_SMALL_PIN_EDITOR_SCREEN


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_112
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_112(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    enable_resized_small_screen();
    
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Password");
    
    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "112");

    ShowCategory112Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer1,
        INPUT_TYPE_NUMERIC_PASSWORD,
        g_buffer,
        CSB_MAX_BUFFER_LEN,
        NULL,
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* UI_SMALL_PIN_EDITOR_SCREEN */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_120
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_120(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

	ShowCategory120Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        0,
        guiBuffer);

	/* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_121
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_121(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Message");

    ShowCategory121Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        g_buffer,
        ALARM_ANIMATION_INDICATION_IMAGEID,
        guiBuffer,
        1);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_BMI__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_122
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_122(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 percentageValue = 50;
    U8 lower_limit[4];
    U8 upper_limit[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) lower_limit, (PS8) "20");
    mmi_asc_to_ucs2((PS8) upper_limit, (PS8) "25");
    
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Message");

    ShowCategory122Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        percentageValue,
        guiBuffer,
        (S8*) g_buffer,
        g_buffer,
        IMG_PROFILES_OUTDOOR,
        (U8*) lower_limit,
        (U8*) upper_limit);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}

#endif /* __MMI_BMI__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_123
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_123(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory123Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_CALORIE__
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
#endif /* __MMI_CALORIE__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_128
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_128(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    wgui_set_touch_title_bar_buttons();

    ShowCategory128Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        IMG_GLOBAL_YES,
        STR_ID_CSB_RSK_TEXT,
        IMG_GLOBAL_NO,
        IMG_ID_PHNSET_WP_3,
        1,
        1,
        1,
        guiBuffer,
        0);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_129
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_129(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    wgui_set_touch_title_bar_buttons(); /* enable the display of title bar buttons */

    ShowCategory129Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        IMG_ID_PHNSET_WP_4,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_130
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_130(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    wgui_set_touch_title_bar_buttons();

    ShowCategory130Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        IMG_GLOBAL_YES,
        STR_ID_CSB_RSK_TEXT,
        IMG_GLOBAL_NO,
        guiBuffer);
        
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_131
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_131(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);

    current_ID = IMG_ID_PHNSET_SS_0;

    ShowCategory131Screen(current_ID, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_140
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_140(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 check_box[3];
    U8 *itemlist[3];
    U8 *guiBuffer = NULL;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 3; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        check_box[index] = index;
    }

    ShowCategory140Screen(STR_ID_CSB_CATEGORY_TEXT, 0, 3, (U8 **) itemlist, (U8*) check_box, 0, guiBuffer);

    /* Special case for Category 140, as the LSK and RSK are passed as parameters of category */
    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_141
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_141(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "");

    ShowCategory141Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        IMG_PROFILES_OUTDOOR,
        NULL);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_142
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_142(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    g_image_id_list[0] = IMG_ID_PHNSET_WP_3;
    g_image_id_list[1] = IMG_ID_PHNSET_WP_4;

    /* category_142_redraw_highlighted_item --> index is not initialized, it may crash */

    ShowCategory142Screen(
        ((U8*) GetString(STR_ID_CSB_CATEGORY_TEXT)),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        NULL,
        g_image_id_list,
        NULL,
        1,
        &index,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_MESSAGES_EMS__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_143
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_143(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    EMSObject *object_list = NULL;
    EMSObject *object_list_1 = NULL;//061507 128x160 touch
    EMSObjData EMS_obj_data;
    S32 nItems = 0;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    /* CreateCategory143ObjectList(GetEMSDataForView(&pEms, 0), &ListPtr); */
    EMS_obj_data.picture.bitsPerPixel = 1;
    EMS_obj_data.picture.hDim = 16;
    EMS_obj_data.picture.vDim = 16;
    EMS_obj_data.picture.pdu_length = 32;
    EMS_obj_data.picture.pdu = (U8*) (EMS_sample_picture_object_t + 8);

    object_list = (EMSObject*) gui_malloc(sizeof(EMSObject));
    object_list_1 = (EMSObject*) gui_malloc(sizeof(EMSObject));//061507 128x160 touch
    object_list->next = object_list_1;
    object_list->prev = NULL;
    object_list->data = &EMS_obj_data;
    object_list->OffsetToText = 0;
    object_list->PredefNo = 0;
    object_list->Type = EMS_TYPE_PIC;

    object_list_1->next = NULL;//061507 128x160 touch
    object_list_1->prev = object_list;
    object_list_1->data = &EMS_obj_data;
    object_list_1->OffsetToText = 0;
    object_list_1->PredefNo = 0;
    object_list_1->Type = EMS_TYPE_PIC;

    ShowCategory143Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        object_list,
        &nItems,
        &index,
        guiBuffer);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_144
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_144(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 Iconlist[2];//061507 128x160 touch
    U8 *itemlist[2];
    S32 currObjectHiliteIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    itemlist[0] = (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT);
    Iconlist[0] = IMG_GLOBAL_L1;//061507 128x160 touch
    itemlist[1] = (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT);
    Iconlist[1] = IMG_GLOBAL_L1;

    ShowCategory144Screen(
        (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        1,
        2,//061507 128x160 touch
        NULL,
        Iconlist,
        FALSE,
        NULL,
        (PS32) & currObjectHiliteIndex,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#endif /* __MMI_MESSAGES_EMS__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_145
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_145(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category145");
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Message");

    ShowCategory145Screen(
        ((U8*) GetString(STR_ID_CSB_CATEGORY_TEXT)),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        IMG_ID_PHNSET_WP_3,
        (U8*) g_buffer,
        g_buffer1,
        0,
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_150
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_150(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *ItemList[3];
    U8 *hintlist[3];
    U8 nItems = 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    hintlist[0] = (U8*) "9";
    hintlist[1] = (U8*) "7";
    hintlist[2] = (U8*) "3";

    ItemList[0] = (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT);
    ItemList[1] = (U8*) GetString(STR_ID_CSB_MENUITEM2_TEXT);
    ItemList[2] = (U8*) GetString(STR_ID_CSB_MENUITEM3_TEXT);

    ShowCategory150Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        nItems,
        (U8 **) ItemList,
        hintlist,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_151
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_151(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category151");

    ShowCategory151Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (PU8) g_buffer,
        (PU8) GetImage(IMG_GLOBAL_OK),
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_152
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_152(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category152");

    ShowCategory152Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) g_buffer,
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_153
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_153(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *ItemList[3];
    U8 *hintlist[3];
    U8 nItems = 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    hintlist[0] = (U8*) "1";
    hintlist[1] = (U8*) "2";
    hintlist[2] = (U8*) "0";

    ItemList[0] = (U8*) GetString(STR_ID_CSB_MENUITEM1_TEXT);
    ItemList[1] = (U8*) GetString(STR_ID_CSB_MENUITEM2_TEXT);
    ItemList[2] = (U8*) GetString(STR_ID_CSB_MENUITEM3_TEXT);

    ShowCategory153Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        nItems,
        (U8 **) ItemList,
        hintlist,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_154
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_154(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory154Screen(
        0,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        IMG_ID_PHNSET_WP_3,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_LCD_PARTIAL_ON__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_161
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_161(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    GetDateTime(&time);
    ShowCategory161Screen(&time);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_LCD_PARTIAL_ON__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_162
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_162(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory162Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        IMG_GLOBAL_QUESTION,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_164
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_164(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory164Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_GLOBAL_SAVE,
        IMG_GLOBAL_QUESTION,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_165
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_165(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory165Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        get_string(STR_ID_CSB_DUMMY_TEXT),
        IMG_GLOBAL_QUESTION,
        0);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_165ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_165ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory165Screen_ext(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        get_string(STR_ID_CSB_DUMMY_TEXT),
        IMG_GLOBAL_QUESTION,
        10,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_166
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_166(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 disp_id;
    PS8 filename_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    disp_id = 0;

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_DOWN);
    DeleteUptoScrID(SCR_ID_CSB_VIEW_SCR_ID);

    filename_ptr = (S8*) PhnsetGetPwrOnFileName();

    ShowCategory166Screen(disp_id, filename_ptr, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_170
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_170(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *itemlist[2];
    U8 *ItemIcons[2];
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 2; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        ItemIcons[index] = (U8*) GetImage((U16)(gIndexIconsImageList[index]));
    }

    ShowCategory170Screen(
        (PU8) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_RSK_TEXT),
        0,
        2,
        (U8 **) itemlist,
        ItemIcons,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_171
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_171(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Category171");

    ShowCategory171Screen(
        (PU8) GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_RSK_TEXT),
        0,
        g_buffer1,
        (PU8) GetImage(IMG_PROFILES_OUTDOOR),
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
        g_buffer,
        G_BUF1_STRING_LEN,
        guiBuffer);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_172
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_172(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U8 *guiBuffer = NULL;
    U8 *itemlist[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 3; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
    }

    ShowCategory172Screen(
        (PU8) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_RSK_TEXT),
        0,
        3,
        itemlist,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_174
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_174(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    U8 *ItemIcons[5];
    U8 *itemlist[5];
    U8 *hintpopup[5];
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 5; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        hintpopup[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT_BUF + index));
        ItemIcons[index] = (U8*) GetImage((U16)(IMG_GLOBAL_L1 + index));
    }

    ShowCategory174Screen(
        (PU8) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (PU8) GetString(STR_ID_CSB_RSK_TEXT),
        0,
        5,
        itemlist,
        ItemIcons,
        hintpopup,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_184
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_184(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nItems = 6;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory184Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        nItems,
        Get_List_Items,
        get_async_hints,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_185
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_185(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 nItems = 6;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory185Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        nItems,
        Get_List_Items,
        get_async_hints,
        0,
        KAL_TRUE,
        NULL,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  cat200_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keyword     [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 cat200_callback(U8 *keyword)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(keyword);
    return 4;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_200
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_200(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);

    RegisterCat200SearchFunction(cat200_callback);

    ShowCategory200Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        Get_List_Items,
        get_async_hints,
        0,
        0,
        (U8*) g_buffer,
        CSB_MAX_BUFFER_LEN,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_201
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_201(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    RegisterCat200SearchFunction(cat200_callback);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);

    g_dictionary_input_mode_CSB = g_dictionary_input_mode_Chinese_set_CSB;

    ShowCategory201Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        Get_List_Items,
        NULL,
        0,
        IMG_PROFILES_OUTDOOR,
        (U8*) g_buffer,
        CSB_MAX_BUFFER_LEN,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        guiBuffer,
        g_dictionary_input_mode_CSB);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_204
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_204(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory204Screen(STR_ID_CSB_LSK_TEXT, 0, STR_ID_CSB_RSK_TEXT, 0, STR_ID_CSB_DUMMY_TEXT, (U16) 204, 0, 0);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_205
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_205(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category205");

    ShowCategory205Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (UI_string_type) g_buffer,
        IMG_ID_PHNSET_WP_3,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_211
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_211(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory211Screen(
        STR_ID_CSB_DUMMY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        1,
        mmi_fmgr_get_drv_item_callback,
        NULL,
        mmi_fmgr_draw_drv_info_callback,
        NULL,
        40,
        0,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_212
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_212(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory212Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        1,
        mmi_fmgr_get_drv_item_callback,
        NULL,
        mmi_fmgr_draw_drv_info_callback,
        NULL,
        2,
        0,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_213
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_213(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory213Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        mmi_fmgr_draw_file_menuitem_callback,
        NULL,
        0,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_214
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_214(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory214Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        5,
        mmi_icon_select_draw_image_callback,
        mmi_icon_select_hide_image_callback,
        3,
        3,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_icon_select_hide_image_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_icon_select_hide_image_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_icon_select_draw_image_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  page_start_idx      [IN]        
 *  page_end_idx        [IN]        
 *  is_hilighted        [IN]        
 *  is_need_update      [IN]        
 *  is_new_page         [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_icon_select_draw_image_callback(
                S32 idx,
                S32 page_start_idx,
                S32 page_end_idx,
                BOOL is_hilighted,
                BOOL is_need_update,
                BOOL is_new_page,
                S32 x1,
                S32 y1,
                S32 x2,
                S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    U16 image_id;
    S32 box_width;
    S32 box_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(is_new_page);
    UI_UNUSED_PARAMETER(is_hilighted);
    UI_UNUSED_PARAMETER(is_need_update);
    UI_UNUSED_PARAMETER(page_end_idx);
    UI_UNUSED_PARAMETER(page_start_idx);

    if (is_need_update)
    {

        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);

        box_width = x2 - x1 + 1;
        box_height = y2 - y1 + 1;

        image_id = (U16) (IMG_ID_PHOART_ICON_START + idx + 1);

        gdi_image_get_dimension_id(image_id, &image_width, &image_height);
        gdi_image_draw_id(((box_width - image_width) >> 1) + x1, ((box_height - image_height) >> 1) + y1, image_id);

        gdi_layer_pop_clip();
    }

}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_221
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_221(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory221Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        GDI_COLOR_BLACK,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_222
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_222(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "C:\\CSB\\category_52.jpg");

    ShowCategory222Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        GDI_COLOR_WHITE,
        NULL,
        (S8*) g_buffer,
        FALSE,
        NULL,
        GDI_IMAGE_SRC_FROM_FILE);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_223
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_223(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory223Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        IMG_GLOBAL_PROGRESS,
        1,
        10,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


#ifdef __MMI_VIDEO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  cat_224_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ret     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cat_224_callback(GDI_RESULT ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Nothing to be done here. The category needs some callback */
    UI_UNUSED_PARAMETER(ret);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_224
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_224(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory224Screen(IMG_ID_PHNSET_ON_0, NULL, 5, TRUE, FALSE, FALSE, GDI_COLOR_RED, cat_224_callback, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_225
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_225(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory225Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        IMG_ID_PHNSET_ON_0,
        NULL,
        1,
        TRUE,
        FALSE,
        TRUE,
        GDI_COLOR_BLACK,
        cat_224_callback,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#endif /* __MMI_VIDEO_PLAYER__ */ 


/*****************************************************************************
 * FUNCTION
 *  Screen227Redraw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  coordinate      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void Screen227Redraw(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(coordinate);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_227
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_227(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory227Screen(
        (PU8) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        Screen227Redraw,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  category228_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  selected_idx        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void category228_callback(S32 selected_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(selected_idx);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_228
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_228(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    HILITE_STR *hilite_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    hilite_list = OslMalloc(sizeof(HILITE_STR));

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category228");

    hilite_list->str_addr = (PS8) g_buffer + 4;
    hilite_list->length = 6;

    ShowCategory228Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (PU8) g_buffer,
        mmi_ucs2strlen((PS8) g_buffer),
        hilite_list,
        (U16) 1,
        category228_callback,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_WC_TZ_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_230
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_230(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    gIndexInfo[0] = OslMalloc(128);
    gIndexInfo[1] = OslMalloc(128);
    homeTime = OslMalloc(128);
    foreTime = OslMalloc(128);

    memcpy(gIndexInfo[0], (S8*) GetString(STR_ID_CSB_DUMMY_TEXT), 40);

#ifdef __MMI_TOUCH_SCREEN__
    RegisterCat230PaintPenEventHandler(mmi_wc_paint_pen_handler);
#endif 
    ShowCategory230Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        2,
        gIndexInfo,
        0,
        CAT230_WC_DT,
        mmi_wc_leftkey_handler,
        mmi_wc_rightkey_handler,
        mmi_wc_get_index_info);

    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    /* Set the key handlers */
    csb_set_key_handlers();

    OslMfree(gIndexInfo[0]);
    OslMfree(gIndexInfo[1]);
    OslMfree(homeTime);
    OslMfree(foreTime);
}
#endif /* __MMI_WC_TZ_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_257
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_257(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Inline, EntryCSBStartView, NULL);

    InitializeCategory57Screen();

    CSBAppFillInlineStruct();

    ShowCategory257Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        CSB_MAX_BUFFER_LEN,
        NULL,
        wgui_inline_items,
        1,
        guiBuffer);

    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_261
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_261(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory261Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        get261_async_items,
        NULL,
        0,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        guiBuffer,
        2,
        4,
        &error);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_262
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_262(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory262Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        3,
        get263_async_items,
        get_async_hints,
        0,
        IMG_PROFILES_OUTDOOR,
        guiBuffer,
        &error);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_263
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_263(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category263");
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "Info text");

    ShowCategory263Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        get263_async_items,
        get_async_hints,
        0,
        0,
        guiBuffer,
        &error);

    RedrawCategory263InfoBox(g_buffer, g_buffer1);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_264
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_264(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory264Screen(
        get_string(STR_ID_CSB_CATEGORY_TEXT),
        get_image(IMG_PROFILES_OUTDOOR),
        IMG_CSK_DIAL_ICON,
        NULL,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
U16 *text0[12] = {L"CH001",
                L"CH002",
                L"CH003",
                L"CH004",
                L"CH005",
                L"CH006",
                L"CH007",
                L"CH008",
                L"CH009",
                L"CH010",
                L"CH011",
                L"CH012"};
U16 *text1[12] = {L"National Geograpics",
                L"ESPN",
                L"MTV",
                L"Channel V",
                L"HBO",
                L"jmomjomioimomi",
                L"77777777777777777777",
                L"88888888888888888888",
                L"99999999999999999999",
                L"1010101010",
                L"111111111111111",
                L"121212121212"};
S32 alm_highlight_item = 0;
S32 alm_number_item = 7;

/*****************************************************************************
 * FUNCTION
 *  cat265_hilite_item
 * DESCRIPTION
 *  application level highlight handler
 * PARAMETERS
 *  index           [IN]        highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void cat265_hilite_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat265_set_title((U8*)text1[index]);
    alm_highlight_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  cat265_get_async_items
 * DESCRIPTION
 *  application level callback function to prepare item content
 * PARAMETERS
 *  start_indx      [IN]        start index of loaded item
 *  menuData        [IN/OUT]    menu data structure
 *  num_item        [IN]        number of items to be loaded
 * RETURNS
 *  number of items have been loaded
 *****************************************************************************/
S32 cat265_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* fill data */
    for (i = 0; i < num_item; ++i)
    {
        U16 status_img;

        /* subject */
        mmi_ucs2ncpy((S8*) menuData[i].item_list[0], (S8*) text0[(start_indx+i)], 10);
        mmi_ucs2ncpy((S8*) menuData[i].item_list[1], (S8*) text1[(start_indx+i)], 50);

        /* status icon */
        menuData[i].image_list[0] = (PU8) GetImage(GetRootTitleIcon(ORGANIZER_ALARM_MENU));
    }
    return num_item;
}

/*****************************************************************************
 * FUNCTION
 *  pre_highlight_handler
 * DESCRIPTION
 *  application level pre-highlight handler
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void pre_highlight_handler(void)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  redraw_preview
 * DESCRIPTION
 *  application level redraw callback function for the preview area
 * PARAMETERS
 *  preview_handle      [IN]        gdi layer handle
 *  blt_layer_flag      [IN]        flags of which layer should be blt
 *  preview_layer_flag  [IN]        flag of hardware blt layer
 *  x                   [IN]        x of preview area
 *  y                   [IN]        y of preview area
 *  width               [IN]        width of preview area
 *  height              [IN]        height of preview area
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_preview(gdi_handle preview_handle, U32 blt_layer_flag, U32 preview_layer_flag, S32 x, S32 y, S32 width, S32 height)
{
    gdi_layer_push_and_set_active(preview_handle);
    gdi_draw_solid_rect(0, 0, width-1, height-1, GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(x, y, x+width-1, y+height-1);
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  EntryScreen_265
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_265(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numItems = 7;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 list_not_ready;
    
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    RegisterHighlightHandler(cat265_hilite_item);

    ShowCategory265Screen(
        0,
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        cat265_get_async_items,
        NULL,
        pre_highlight_handler,
        redraw_preview,
        0,
        //GetRootTitleIcon(ORGANIZER_ALARM_MENU),
        NULL);

    //SetKeyHandler(delete_one_item, KEY_8, KEY_EVENT_DOWN);
    //SetKeyHandler(add_one_item, KEY_2, KEY_EVENT_DOWN);

    //SetLeftSoftkeyFunction(AlmPrepareInlineScreen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    //SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_CAT265_SUPPORT__ */ 

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_273
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_273(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory273Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        Get_List_Items,
        NULL,
        NULL,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_276
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_276(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    wgui_set_touch_title_bar_buttons();

    ShowCategory276Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        0,
        0,
        0,
        0,
        gui_buffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  Get_List_Items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
pBOOL Get_List_Items(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(str_img_mask);
    if (item_index < 0)
    {
        return FALSE;
    }

    mmi_ucs2cpy((S8*) str_buff, (S8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + (U16) item_index)));
    *img_buff_p = (U8*) GetImage(gIndexIconsImageList[item_index]);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_277
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_277(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    U16 area1_height, area2_height;
    stFontAttribute editor_font = MMI_small_font;
    UI_font_type text_font;
    color text_color = {0, 0, 0, 100};
    color selected_text_color = {0, 255, 0, 100};
    color bg_color = {255, 255, 255, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    text_font = &editor_font;

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category277");

    area1_height = 110;
    area2_height = 0;

    ShowCategory277Screen(
        1,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        INPUT_TYPE_ALPHANUMERIC_LOWERCASE,
        (U8*) g_buffer,
        (S32) 20,
        (U16) 10,
        mmi_show_editor_title,
        area1_height,
        mmi_show_editor_draw_area_1,
        area2_height,
        mmi_show_editor_draw_area_2,
        &text_font,
        &text_color,
        &selected_text_color,
        &bg_color,
        gui_buffer);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_show_editor_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_show_editor_title(U32 identifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width, character_height;
    S32 x_start;
    U8 title_buffer[20];
    U8 title_temp_buffer[16];
    U8 page_count = 0;
    U32 mms_size = 0, mms_bytes = 0;
    FLOAT mms_mb_size = 0, mms_gb_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    page_count = 1;
    sprintf((S8*) title_temp_buffer, "%d/%d", identifier, page_count);
    mmi_asc_to_ucs2((S8*) title_buffer, (S8*) title_temp_buffer);

    MMI_title_string = (UI_string_type) title_buffer;
    MMI_title_icon = (PU8) get_image(GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID));

    show_title_status_icon();
    draw_title();

    gui_push_clip();
    gui_push_text_clip();
    gui_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
    gui_set_text_clip(MMI_title_x, MMI_title_y, MMI_title_x + MMI_title_width - 1, MMI_title_y + MMI_title_height - 1);

    gui_set_font(&MMI_small_font);

    mms_size = 512;
    mms_bytes = mms_size % 1024;
    mms_size = mms_size / 1024;
    mms_mb_size = (FLOAT) mms_size / 1024;
    mms_gb_size = mms_mb_size / 1024;

    if (mms_size > 0)
    {
        mms_size++;
    }

    if (mms_mb_size > 0.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.02f%s", mms_mb_size, "MB");
        mmi_asc_to_ucs2((S8*) title_buffer, (S8*) title_temp_buffer);
    }
    else if (mms_gb_size > 0.0)
    {
        sprintf((S8*) title_temp_buffer, "%0.02f%s", mms_gb_size, "GB");
        mmi_asc_to_ucs2((S8*) title_buffer, (S8*) title_temp_buffer);
    }
    else
    {
        sprintf((S8*) title_temp_buffer, "%d%s", mms_size, "KB");
        mmi_asc_to_ucs2((S8*) title_buffer, (S8*) title_temp_buffer);
    }

    gui_measure_string((UI_string_type) title_buffer, &text_width, &character_height);

    x_start = MMI_title_x + MMI_title_width - text_width - 2;

    gui_move_text_cursor(x_start, MMI_title_y + ((MMI_title_height - character_height) >> 1));
    gui_set_text_color(*current_MMI_theme->title_text_color);
    gui_print_text((UI_string_type) title_buffer);
    gui_set_font(&MMI_medium_font);

    gui_pop_text_clip();
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_show_editor_draw_area_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  clip_x1         [IN]        
 *  clip_y1         [IN]        
 *  clip_x2         [IN]        
 *  clip_y2         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_show_editor_draw_area_1(U32 identifier, S32 y_offset, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2, icon_x;
    S32 width, height;
    U32 vbar_width = current_MMI_theme->scrollbar_size;
    U32 largest_y, max_width;
    color c = {100, 150, 200, 100};
    color c1 = {150, 150, 200, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(identifier);
    /* Set clipping */
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);

    /* Show attachment icon */
    x1 = clip_x1;
    y1 = y_offset;
    gui_measure_image((PU8) GetImage(IMG_PROFILES_OUTDOOR), &width, &height);
    y2 = y1 + height;
    x2 = clip_x2 - 2;
    max_width = MMI_content_width - (vbar_width + 2) * 2;
    x2 = ((x2 - x1) > (S32)max_width) ? (x1 + max_width) : x2;
    x1 = x1 + vbar_width;

    largest_y = y2;
    gui_fill_rectangle(x1, y1, x2, y2, c1);

    icon_x = x1 + 2;
    gui_show_image(icon_x, y1, (PU8) GetImage(IMG_PROFILES_OUTDOOR));
    icon_x = icon_x + width + 2;

    gui_measure_image((PU8) GetImage(IMG_PROFILES_OUTDOOR), &width, &height);
    gui_draw_rectangle(x1, largest_y, x2, largest_y + 75, c);

    gdi_image_draw_resized_id(x1 + 2, largest_y + 2, 50, 50, IMG_ID_PHNSET_WP_5);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_show_editor_draw_area_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  identifier      [IN]        
 *  y_offset        [IN]        
 *  clip_x1         [IN]        
 *  clip_y1         [IN]        
 *  clip_x2         [IN]        
 *  clip_y2         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_show_editor_draw_area_2(U32 identifier, S32 y_offset, S32 clip_x1, S32 clip_y1, S32 clip_x2, S32 clip_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_width, x1, x2, y2;
    color c = {100, 150, 200, 100};
    U32 vbar_width = current_MMI_theme->scrollbar_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(identifier);
    gui_push_clip();
    gui_set_clip(clip_x1, clip_y1, clip_x2, clip_y2);
    max_width = MMI_content_width - (vbar_width + 2) * 2;
    x1 = clip_x1;
    x2 = ((clip_x2 - clip_x1) > max_width) ? (clip_x1 + max_width) : clip_x2;
    y2 = y_offset + 40 + 6 + 2 * 2;
    x1 = x1 + vbar_width;
    gui_draw_rectangle(x1, y_offset + 6, x2, y2, c);

    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_284
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_284(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory284Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        3,
        Get_List_Items,
        get_async_hints,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_301
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_301(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory301Screen(
        (PU8) GetString(STR_ID_CSB_DUMMY_TEXT),
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_302
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_302(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory302Screen(NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_303
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_303(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FLOAT diff1, diff2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    diff1 = 3.5;
    diff2 = 2.5;

    ShowCategory303Screen(
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        diff1,
        diff2,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_304
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_304(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory304Screen(IMG_GLOBAL_OK, 0);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_SUBLCD__ */ 

#ifdef __MMI_MESSAGES_CHAT__
/*****************************************************************************
 * FUNCTION
 *  EntryScreen_305
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_305(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL, i;
    chat_message_struct chatStrings[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category305");

    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "13311325167:");
    i = 24;
    g_buffer1[i++] = 0x65;
    g_buffer1[i++] = 0x67;
    g_buffer1[i++] = 0x0D;
    g_buffer1[i++] = 0x4e;
    g_buffer1[i++] = 0xca;
    g_buffer1[i++] = 0x53;
    g_buffer1[i++] = 0;
    g_buffer1[i++] = 0;

    chatStrings[0].chat_message_string = (U8*) g_buffer1;
    chatStrings[0].flag = 1;
    chatStrings[1].chat_message_string = (U8*) GetString(STR_ID_CSB_DUMMY_TEXT);
    chatStrings[1].flag = 1;

    ShowCategory305Screen(
        0,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        2,
        chatStrings,
        guiBuffer,
        (PU8) g_buffer,
        IMG_GLOBAL_OK);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_MESSAGES_CHAT__ */

#ifdef __MMI_STOPWATCH__
/*****************************************************************************
 * FUNCTION
 *  EntryScreen_306
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_306(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 *guiBuffer = NULL;
    UI_stop_watch stopWatchBuffer[MAX_TIMER_RECORDS];
    UI_stop_watch lastStopWatchBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(stopWatchBuffer, 0, sizeof(stopWatchBuffer));
    memset(&lastStopWatchBuffer, 0, sizeof(lastStopWatchBuffer));

    for (index = 0; index < MAX_TIMER_RECORDS; index++)
    {
        stopWatchBuffer[index].normalimagedata = GetImage((U16) (IMG_GLOBAL_L1 + index));
        stopWatchBuffer[index].highlightimagedata = GetImage((U16) (IMG_GLOBAL_L1 + index));
    }

    ShowCategory306Screen(
        &lastStopWatchBuffer,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        stopWatchBuffer,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        guiBuffer,
        0);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_307
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_307(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory307Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        NULL,
        0,
        guiBuffer,
        STOPWATCH_BASE + 5,
        0);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#endif /* __MMI_STOPWATCH__ */ 

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_310
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_310(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory310Screen((U8*) get_string(STR_GLOBAL_LOGO), 0, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_311
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_311(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory311Screen((U8*) GetString(STR_ID_CSB_DUMMY_TEXT), IMG_GLOBAL_OK, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_312
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_312(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FLOAT time_difference;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    time_difference = 1;

    ShowCategory312Screen((U8*) GetString(STR_ID_CSB_DUMMY_TEXT), time_difference, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_313
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_313(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory313Screen(IMG_SUBLCD_SYSTEM_SHUTDOWN, NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_314
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_314(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 ItemList[2];
    U16 ItemIcon[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ItemList[0] = STR_ID_CSB_MENUITEM1_TEXT;
    ItemList[1] = STR_ID_CSB_MENUITEM2_TEXT;

    ItemIcon[0] = IMG_PROFILES_OUTDOOR;
    ItemIcon[1] = IMG_PROFILES_OUTDOOR;

    ShowCategory314Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        2,
        ItemList,
        ItemIcon,
        NULL,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_332
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_332(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    ShowCategory332Screen(IMG_CM_SS_OUTGOING);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_333
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_333(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory310Screen((U8*) get_string(STR_GLOBAL_LOGO), 0, NULL);

    ShowCategory333Screen();

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_SUBLCD__ */ 


#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
/*****************************************************************************
 * FUNCTION
 *  EntryScreen_334
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_334(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    signed char level[8] = {20, 20, 30, 30, 40, 40, 20, 20};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory334Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        level,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_353
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_353(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *itemlist[4];
    U8 *hintlist[4];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 4; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
        hintlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT_BUF + index));
    }

    ShowCategory353Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        itemlist,
        (U16*) gIndexIconsImageList,
        hintlist,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#ifdef __MMI_WALLPAPER_ON_BOTTOM__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_357
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_357(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Inline, EntryCSBStartView, NULL);

    InitializeCategory57Screen();

    CSBAppFillInlineStruct();

    DisableCategory57ScreenDone();

    ShowCategory357Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        CSB_MAX_BUFFER_LEN,
        NULL,
        wgui_inline_items,
        0,
        guiBuffer);

    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}

#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 


#define CAT384_NUMBER_OF_ITEM	5
static U8 cat384_cb_state[CAT384_NUMBER_OF_ITEM] = {0};


/*****************************************************************************
 * FUNCTION
 *  cat384_checkbox_clicked_callback
 * DESCRIPTION
 *  set check-box callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 cat384_checkbox_clicked_callback(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat384_cb_state[item_index] = !cat384_cb_state[item_index];
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cat384_checkbox_get_image_callback
 * DESCRIPTION
 *  get check-box image callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 cat384_checkbox_get_image_callback(S32 item_index, PU8 *checkbox_image)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *checkbox_image = (cat384_cb_state[item_index]) ? (PU8)GetImage(CHECKBOX_ON_IMAGE_ID) : (PU8)GetImage(CHECKBOX_OFF_IMAGE_ID);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_384
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_384(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory384Screen(
        (UI_string_type) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) L"Hint description. This area is dynamically allocated.",
        CAT384_NUMBER_OF_ITEM,
        Get_List_Items,
        get_hint_list,
        cat384_checkbox_get_image_callback,
        cat384_checkbox_clicked_callback,
        0,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_400
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_400(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory400Screen(STR_ID_CSB_CATEGORY_TEXT, 0, STR_ID_CSB_LSK_TEXT, 0, STR_ID_CSB_RSK_TEXT, 0, guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_402
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_402(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory402Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,  
        0,
        0,
        0,
        0,
        NULL,
        (U16) 60,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_403
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_403(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    tab_bar_item_type MMI_tab_bar_items[2];
    MYTIME currTime;
    U8 *guiBuffer = NULL;
    U8 *itemlist[3];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    MMI_tab_bar_items[0].icon = (U8*) GetImage(gIndexIconsImageList[0]);
    MMI_tab_bar_items[1].icon = (U8*) GetImage(gIndexIconsImageList[1]);
    MMI_tab_bar_items[0].text = NULL;
    MMI_tab_bar_items[1].text = NULL;
    MMI_tab_bar_items[0].flags = 0;
    MMI_tab_bar_items[1].flags = 0;

    for (index = 0; index < 3; index++)
    {
        itemlist[index] = (U8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + index));
    }

    DTGetRTCTime(&currTime);

    /* TO DO: Write a function to switch the TAB */
    ShowCategory403Screen(
        (U8*) GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (S8) 2,
        (S8) 0,
        MMI_tab_bar_items,
        &currTime,
        IMG_PROFILES_OUTDOOR,
        itemlist,
        NULL,
        3,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_404
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_404(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category404");

    ShowCategory404Screen(
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        0,
        (U8*) g_buffer,
        G_BUF_STRING_LEN,
        guiBuffer);

    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  RefreshScreen_412
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RefreshScreen_412(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type itemlist[5];
    S32 index;
    S32 number = rand()%5;
    static S32 value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    value = (value + 1) % 11;
    for (index = 0; index < number; index++)
    {
        itemlist[index] = L"zyxwvutsrqponmlkjihgfedcba";
    }
    Cat412UpdateList(
        L"zyxwvutsrqponmlkjihgfedcba",
        (U8)(value * 10),
        number,
        itemlist);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_412
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_412(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type itemlist[5];
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    
    for (index = 0; index < 5; index++)
    {
        itemlist[index] = L"abcdefghijklmnopqrstuvwxyz";
    }
    
    ShowCategory412Screen(
        L"Category 412",
        NULL,
        (UI_string_type)GetString(STR_ID_CSB_LSK_TEXT),
        NULL,
        (UI_string_type)GetString(STR_ID_CSB_RSK_TEXT),
        NULL,
        (U8*)GetImage(IMG_GLOBAL_L30),
        L"abcdefghijklmnopqrstuvwxyz",
        (U8)100,
        5,
        itemlist,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();
    
    SetKeyHandler(RefreshScreen_412, KEY_2, KEY_EVENT_DOWN);
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_414
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_414(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    U16 Iconlist1[4] = 
    {
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR,
        IMG_PROFILES_OUTDOOR
    };
    U16 Itemlist[] = 
    {
        STR_ID_CSB_MENUITEM1_TEXT,
        STR_ID_CSB_MENUITEM2_TEXT,
        STR_ID_CSB_MENUITEM3_TEXT,
        STR_ID_CSB_MENUITEM4_TEXT
    };

    U16 Iconlist[] = 
    {
        IMG_GLOBAL_L1,
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        IMG_GLOBAL_L4
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory414Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        4,
        Itemlist,
        Iconlist,
        Iconlist1,
        NULL,
        0,
        0,
        (U8*) guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_420
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_420(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "JOE");
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "D:\\CSB\\category_52.jpg");

    ShowCategory420Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (UI_string_type) g_buffer1,
        (S8*) g_buffer,
        IMG_GLOBAL_DEFAULT,
        STR_ID_CSB_MENUITEM1_TEXT,
        (UI_string_type) GetString(STR_ID_CSB_DUMMY_TEXT),
        (PU8) GetImage(STR_ID_CSB_DUMMY_TEXT),
        STR_ID_CSB_MENUITEM2_TEXT,
        (UI_string_type) GetString((U16) (STR_ID_CSB_DUMMY_TEXT)),
        (PU8) GetImage((U16) (IMG_PROFILES_OUTDOOR)),
        (U8*) g_buffer1,
        (S32) mmi_ucs2strlen((S8*) g_buffer1),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_425
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_425(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 index;
    BOOL list_is_ready_p;
    tab_bar_item_type MMI_tab_bar_items[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    for (index = 0; index < 2; index++)
    {
        MMI_tab_bar_items[index].icon = (PU8) GetImage(gIndexIconsImageList[index]);
        MMI_tab_bar_items[index].text = NULL;
        MMI_tab_bar_items[index].flags = 0;
    }

    ShowCategory425Screen(
        (UI_string_type) GetString(STR_ID_CSB_CATEGORY_TEXT),
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (S8) 2,
        (S8) 0,
        MMI_tab_bar_items,
        (S32) 4,
        get425_async_items,
        NULL,
        (PU8) GetImage(IMG_PROFILES_OUTDOOR),
        (PU8) GetImage(IMG_PROFILES_OUTDOOR),
        0,
        guiBuffer,
        &list_is_ready_p);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  cat427_get_item_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 cat427_get_item_func(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0 ; i < data_size ; i++)
    {
        mmi_ucs2cpy((S8*)menu_data[i].item_list[0], (S8*)L"abcdefghijklmnopqrstuvwxyz");
        mmi_ucs2cpy((S8*)menu_data[i].item_list[1], (S8*)L"100%");
        mmi_ucs2cpy((S8*)menu_data[i].item_list[2], (S8*)L"8888/8888K");
        menu_data[i].image_list[0] = (U8*)GetImage((U16)(IMG_GLOBAL_L1 + i + start_index));
    }
    
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  RefreshScreen_427
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RefreshScreen_427(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cat_refresh_asyncdynamic_list(2, 1, cat427_get_item_func, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_427
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_427(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    
    ShowCategory427Screen(
        L"Category 427",
        NULL,
        L"LSK",
        NULL,
        L"RSK",
        NULL,
        10,
        cat427_get_item_func,
        0,
        NULL);

    /* Set the key handlers */
    csb_set_key_handlers();

    SetKeyHandler(RefreshScreen_427, KEY_5, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_430
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_430(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    ShowCategory430Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        g_buffer,
        CSB_MAX_BUFFER_LEN,
        g_buffer1,
        CSB_MAX_BUFFER_LEN,
        TRUE,
        CSB_MAX_BUFFER_LEN,
        g_buffer1,
        0,
        (PU8) GetString(STR_ID_CSB_DUMMY_TEXT),
        (PU8) GetString(STR_ID_CSB_DUMMY_TEXT),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_435
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_435(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    tab_bar_item_type MMI_tab_bar_items[3];
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    memset(g_buffer1, 0, MAX_LOCAL_BUFFER_1);

    for (index = 0; index < 3; index++)
    {
        MMI_tab_bar_items[index].icon = (PU8) GetImage(gIndexIconsImageList[index]);
        MMI_tab_bar_items[index].text = NULL;
        MMI_tab_bar_items[index].flags = 0;
    }

    ShowCategory435Screen(
        (UI_string_type) GetString(STR_ID_CSB_CATEGORY_TEXT),
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        0,
        STR_ID_CSB_DUMMY_TEXT,
        0,
        (S8) 3,
        (S8) 1,
        MMI_tab_bar_items,
        FALSE,
        NULL,
        INPUT_TYPE_ALPHANUMERIC_UPPERCASE,
        (U8*) g_buffer,
        G_BUF1_STRING_LEN,
        (U8*) g_buffer1,
        G_BUF1_STRING_LEN,
        NULL,
        (PU8) GetImage(IMG_PROFILES_OUTDOOR),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


#ifdef __MMI_CAT44X_SUPPORT__
#ifdef __MMI_TOUCH_SCREEN__   
/*****************************************************************************
 * FUNCTION
 *  csb_445_control_area_pen_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL csb_445_control_area_pen_down(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  csb_445_control_area_pen_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL csb_445_control_area_pen_up(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  csb_445_control_area_pen_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  point       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL csb_445_control_area_pen_move(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  csb_441_b1_down_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_b1_down_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_b1_up_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_b1_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_b1_repeat_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_b1_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_b2_down_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_b2_down_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_b2_up_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_b2_up_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_b2_repeat_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_b2_repeat_event_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_header_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_header_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_441_hilight_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_441_hilight_callback(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  csb_44x_change_data_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_44x_change_data_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_page_info_app ebook_frm_setting_struct_csb;
    gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ebook_frm_setting_csb->end_id = 3;
    ebook_frm_setting_csb->start_id = 0;
    ebook_frm_setting_csb->doc_size = 4;
    ebook_frm_setting_csb->last_text_offset_y = 0;
    ebook_frm_setting_csb->jump_offset_from_app = 5;
    ebook_frm_setting_csb->text_offset = 0;
    ebook_frm_setting_csb->scroll_speed = 0;
    ebook_frm_setting_csb->scroll_type = 1;
    ebook_frm_setting_csb->scroll_flag = 0;
    ebook_frm_setting_csb->font_size = 1;
    ebook_frm_setting_csb->search_str_len = 10;
    ebook_frm_setting_csb->font_style = 0;
    ebook_frm_setting_csb->jump_to_end = 0;
    ebook_frm_setting_csb->highlight_string = 1;
    ebook_frm_setting_csb->search_flag_is_on = FALSE;
    ebook_frm_setting_csb->last_showed_percentage = 0;
    ebook_frm_setting_csb->get_page_cb = csb_get_page_callback;
#ifdef __MMI_TOUCH_SCREEN__
    ebook_frm_setting_csb->get_data_during_scrolling = csb_get_data_during_scrolling_cb;
#endif /* __MMI_TOUCH_SCREEN__ */
    
    wgui_cat448_change_highlight(&ebook_frm_setting_csb);
}


/*****************************************************************************
 * FUNCTION
 *  csb_44x_change_data_2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_44x_change_data_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "this is a sample code of category44x, 2");
    inputbox_area_data.header_img = (PU8)GetImage(IMG_GLOBAL_QUESTION);
    wgui_cat44x_update_inputbox_data(&inputbox_area_data);
}


/*****************************************************************************
 * FUNCTION
 *  csb_44x_change_data_3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void csb_44x_change_data_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "this is a sample code of category44x, 3");
    inputbox_area_data.header_img = NULL;
    wgui_cat44x_update_inputbox_data(&inputbox_area_data);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_441
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_441(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    static PU8 text_area[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    text_area[0] = (PU8)GetString(STR_ID_CSB_DUMMY_TEXT);
    text_area[1] = (PU8)GetString(STR_ID_CSB_DUMMY_TEXT);

    top_text_area_data.area_bg_img = (PU8)GetImage(IMG_ID_AUDPLY_MAIN_SKIN1_BG);
    top_text_area_data.number_of_lines = 2;
    top_text_area_data.string_list = text_area;

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "this is a sample code of category441");
    inputbox_area_data.buffer = g_buffer;
    inputbox_area_data.buffer_size = G_BUF1_STRING_LEN;
    inputbox_area_data.header_img = (PU8)GetImage(IMG_PROFILES_OUTDOOR);
    inputbox_area_data.header_img_cb = csb_441_header_callback;
    inputbox_area_data.hilite_cb = csb_441_hilight_callback;
    inputbox_area_data.hilite_str_number = 2;
    inputbox_area_data.bg_img = (PU8)GetImage(IMG_ID_AUDPLY_MAIN_SKIN1_BG);
    /* add hilite pointer one by one*/
    strlist[0].length = 6;
    strlist[0].str_addr = (PS8)(g_buffer + 6);
    strlist[1].length = 4;
    strlist[1].str_addr = (PS8)(g_buffer + 22);
    inputbox_area_data.hilite_str_list = strlist;

    panel_area_data.element_list = panel_list;
    panel_area_data.focused_element = 1;
    panel_area_data.num_of_element = 2;
    panel_area_data.panel_bg_img_id = IMG_ID_AUDPLY_MAIN_SKIN1_BG;
    panel_area_data.repeat_period = 0;

    ShowCategory441Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        &top_text_area_data,
        &inputbox_area_data,       
        &panel_area_data,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();

    SetKeyHandler(csb_44x_change_data_2, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(csb_44x_change_data_3, KEY_3, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_442
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_442(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    static PU8 text_area[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    text_area[0] = (PU8)GetString(STR_ID_CSB_DUMMY_TEXT);
    text_area[1] = (PU8)GetString(STR_ID_CSB_DUMMY_TEXT);

    top_text_area_data.area_bg_img = (PU8)GetImage(IMG_ID_AUDPLY_MAIN_SKIN1_BG);
    top_text_area_data.number_of_lines = 2;
    top_text_area_data.string_list = text_area;

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "this is a sample code of category442, It's a panel, a new item in drawmanager.");
    inputbox_area_data.buffer = g_buffer;
    inputbox_area_data.buffer_size = G_BUF1_STRING_LEN;
    inputbox_area_data.header_img = (PU8)GetImage(IMG_PROFILES_OUTDOOR);
    inputbox_area_data.header_img_cb = csb_441_header_callback;
    inputbox_area_data.hilite_cb = csb_441_hilight_callback;
    inputbox_area_data.hilite_str_number = 2;
    /* add hilite pointer one by one*/
    strlist[0].length = 4;
    strlist[0].str_addr = (PS8)(g_buffer + 4);
    strlist[1].length = 6;
    strlist[1].str_addr = (PS8)(g_buffer + 32);
    inputbox_area_data.hilite_str_list = strlist;

    panel_area_data.element_list = panel_list;
    panel_area_data.focused_element = 1;
    panel_area_data.num_of_element = 4;
    panel_area_data.panel_bg_img_id = IMG_ID_AUDPLY_MAIN_SKIN1_BG;
    panel_area_data.repeat_period = 0;

    ShowCategory442Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        &top_text_area_data,
        &inputbox_area_data,       
        &panel_area_data,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
    
    SetKeyHandler(csb_44x_change_data_2, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(csb_44x_change_data_3, KEY_3, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  redraw_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  coordinate      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void redraw_callback(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_445
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_445(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "This is a sample code of category445,category screen browser test text");
    inputbox_area_data.buffer = g_buffer;
    inputbox_area_data.buffer_size = G_BUF1_STRING_LEN;
    inputbox_area_data.header_img = (PU8)GetImage(IMG_PROFILES_OUTDOOR);
    inputbox_area_data.header_img_cb = csb_441_header_callback;
    inputbox_area_data.hilite_cb = csb_441_hilight_callback;
    inputbox_area_data.hilite_str_number = 2;
    /* add hilite pointer one by one*/
    strlist[0].length = 6;
    strlist[0].str_addr = (PS8)(g_buffer + 6);
    strlist[1].length = 4;
    strlist[1].str_addr = (PS8)(g_buffer + 22);
    inputbox_area_data.hilite_str_list = strlist;

    ShowCategory445Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        IMG_ID_AUDPLY_MAIN_SKIN1_BG,
        &inputbox_area_data,       
        redraw_callback,
        guiBuffer);
#ifdef __MMI_TOUCH_SCREEN__    
    wgui_cat44x_reg_control_area_pen_handlers(csb_445_control_area_pen_down, MMI_PEN_EVENT_DOWN);
    wgui_cat44x_reg_control_area_pen_handlers(csb_445_control_area_pen_up, MMI_PEN_EVENT_UP);
    wgui_cat44x_reg_control_area_pen_handlers(csb_445_control_area_pen_move, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* Set the key handlers */
    csb_set_key_handlers();

    SetKeyHandler(csb_44x_change_data_2, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(csb_44x_change_data_3, KEY_3, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_443
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_443(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    panel_area_data.element_list = panel_list;
    panel_area_data.focused_element = 1;
    panel_area_data.num_of_element = 7;
    panel_area_data.panel_bg_img_id = IMG_ID_AUDPLY_MAIN_SKIN1_BG;
    panel_area_data.repeat_period = 0;

    ShowCategory443Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        (PU8)GetImage(IMG_ID_AUDPLY_MAIN_SKIN1_BG),
        redraw_callback,
        &panel_area_data,
        guiBuffer);
#ifdef __MMI_TOUCH_SCREEN__    
    wgui_cat44x_reg_control_area_pen_handlers(csb_445_control_area_pen_down, MMI_PEN_EVENT_DOWN);
    wgui_cat44x_reg_control_area_pen_handlers(csb_445_control_area_pen_up, MMI_PEN_EVENT_UP);
    wgui_cat44x_reg_control_area_pen_handlers(csb_445_control_area_pen_move, MMI_PEN_EVENT_MOVE);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* Set the key handlers */
    csb_set_key_handlers();
    
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_447
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_447(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category 447 category screen browser test text ");
    inputbox_area_data.buffer = g_buffer;
    inputbox_area_data.buffer_size = G_BUF1_STRING_LEN;
    inputbox_area_data.header_img = (PU8)GetImage(IMG_PROFILES_OUTDOOR);
    inputbox_area_data.header_img_cb = csb_441_header_callback;
    inputbox_area_data.hilite_cb = csb_441_hilight_callback;
    inputbox_area_data.hilite_str_number = 2;
    /* add hilite pointer one by one*/
    strlist[0].length = 6;
    strlist[0].str_addr = (PS8)(g_buffer + 6);
    strlist[1].length = 4;
    strlist[1].str_addr = (PS8)(g_buffer + 22);
    inputbox_area_data.hilite_str_list = strlist;

    ShowCategory447Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        IMG_ID_AUDPLY_MAIN_SKIN1_BG,
        &inputbox_area_data,
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();

    SetKeyHandler(csb_44x_change_data_2, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(csb_44x_change_data_3, KEY_3, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  csb_get_page_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_id        [IN]        
 *  end_id          [IN]        
 *  buffer          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void csb_get_page_callback(U32 start_id, U32 end_id, PU8 buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(start_id)
    {
    case 0:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 1.Category 447 category screen browser test text");
        break;
    case 1:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 2.Category 447 category screen browser test text");
        break;
    case 2:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 3.Category 447 category screen browser test text");
        break;
    case 3:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 4.Category 447 category screen browser test text");
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_get_data_during_scrolling_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  page_id     [IN]        
 *  buffer      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void csb_get_data_during_scrolling_cb(S32 page_id, PU8 buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(page_id)
    {
    case 0:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 1.Category 447 category screen browser test text");
        break;
    case 1:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 2.Category 447 category screen browser test text");
        break;
    case 2:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 3.Category 447 category screen browser test text");
        break;
    case 3:
        mmi_asc_to_ucs2((PS8) buffer, (PS8) "Part 4.Category 447 category screen browser test text");
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  csb_pen_get_word_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text            [IN]        
 *  cursor_p        [IN]        
 *  text_length     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void csb_pen_get_word_callback(UI_buffer_type text, UI_buffer_type cursor_p, S32 text_length, S32 buffer_pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_448
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_448(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    gui_page_info_app ebook_frm_setting_struct_csb;
    gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;
    color bg_color = { 0, 200, 100};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category 448 category screen browser test text");
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "D:\\1.jpg");

    ebook_frm_setting_csb->end_id = 3;
    ebook_frm_setting_csb->start_id = 0;
    ebook_frm_setting_csb->doc_size = 4;
    ebook_frm_setting_csb->last_text_offset_y = 0;
    ebook_frm_setting_csb->jump_offset_from_app = 0;
    ebook_frm_setting_csb->text_offset = 0;
    ebook_frm_setting_csb->scroll_speed = 0;
    ebook_frm_setting_csb->scroll_type = 1;
    ebook_frm_setting_csb->scroll_flag = 0;
    ebook_frm_setting_csb->font_size = 1;
    ebook_frm_setting_csb->search_str_len = 3;
    ebook_frm_setting_csb->font_style = 0;
    ebook_frm_setting_csb->jump_to_end = 0;
    ebook_frm_setting_csb->highlight_string = 1;
    ebook_frm_setting_csb->search_flag_is_on = FALSE;
    ebook_frm_setting_csb->last_showed_percentage = 0;
    ebook_frm_setting_csb->get_page_cb = csb_get_page_callback;
#ifdef __MMI_TOUCH_SCREEN__
    ebook_frm_setting_csb->get_data_during_scrolling = csb_get_data_during_scrolling_cb;
#endif /* __MMI_TOUCH_SCREEN__ */
    
    inputbox_area_data.buffer = g_buffer;
    inputbox_area_data.buffer_size = G_BUF1_STRING_LEN;
    inputbox_area_data.header_img = (PU8)GetImage(IMG_PROFILES_OUTDOOR);
    inputbox_area_data.header_img_cb = csb_441_header_callback;
    inputbox_area_data.hilite_cb = csb_441_hilight_callback;
    inputbox_area_data.hilite_str_number = 2;
    inputbox_area_data.bg_color = bg_color;
    /* add hilite pointer one by one*/
    strlist[0].length = 6;
    strlist[0].str_addr = (PS8)(g_buffer + 6);
    strlist[1].length = 4;
    strlist[1].str_addr = (PS8)(g_buffer + 22);
    inputbox_area_data.hilite_str_list = strlist;

    /* If need support rotate, call this function.*/
    /* mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270); */

    ShowCategory448Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        NULL,   /* (S8*)g_buffer1, */
        &inputbox_area_data, 
        NULL,
        csb_pen_get_word_callback,
        NULL,
        NULL,
        &ebook_frm_setting_csb,
        MMI_TRUE,
        (S8*)GetImage(IMG_ID_AUDPLY_MAIN_SKIN1_BG),
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();

    SetKeyHandler(csb_44x_change_data_1, KEY_1, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_449
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_449(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    gui_page_info_app ebook_frm_setting_struct_csb;
    gui_page_info_app *ebook_frm_setting_csb = &ebook_frm_setting_struct_csb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CSB_DUMMY_SCR_ID);

    memset(g_buffer, 0, MAX_LOCAL_BUFFER);
    mmi_asc_to_ucs2((PS8) g_buffer, (PS8) "Category 449 category screen browser test text");
    mmi_asc_to_ucs2((PS8) g_buffer1, (PS8) "D:\\1.jpg");

    ebook_frm_setting_csb->end_id = 3;
    ebook_frm_setting_csb->start_id = 0;
    ebook_frm_setting_csb->doc_size = 4;
    ebook_frm_setting_csb->last_text_offset_y = 0;
    ebook_frm_setting_csb->jump_offset_from_app = 0;
    ebook_frm_setting_csb->text_offset = 0;
    ebook_frm_setting_csb->scroll_speed = 0;
    ebook_frm_setting_csb->scroll_type = 1;
    ebook_frm_setting_csb->scroll_flag = 0;
    ebook_frm_setting_csb->font_size = 1;
    ebook_frm_setting_csb->search_str_len = 3;
    ebook_frm_setting_csb->font_style = 0;
    ebook_frm_setting_csb->jump_to_end = 0;
    ebook_frm_setting_csb->highlight_string = 1;
    ebook_frm_setting_csb->search_flag_is_on = FALSE;
    ebook_frm_setting_csb->last_showed_percentage = 0;
    ebook_frm_setting_csb->get_page_cb = csb_get_page_callback;
#ifdef __MMI_TOUCH_SCREEN__
    ebook_frm_setting_csb->get_data_during_scrolling = csb_get_data_during_scrolling_cb;
#endif /* __MMI_TOUCH_SCREEN__ */
    
    inputbox_area_data.buffer = g_buffer;
    inputbox_area_data.buffer_size = G_BUF1_STRING_LEN;
    inputbox_area_data.header_img = (PU8)GetImage(IMG_PROFILES_OUTDOOR);
    inputbox_area_data.header_img_cb = csb_441_header_callback;
    inputbox_area_data.hilite_cb = csb_441_hilight_callback;
    inputbox_area_data.hilite_str_number = 0;
    /* add hilite pointer one by one*/
    strlist[0].length = 6;
    strlist[0].str_addr = (PS8)(g_buffer + 6);
    strlist[1].length = 4;
    strlist[1].str_addr = (PS8)(g_buffer + 22);
    inputbox_area_data.hilite_str_list = NULL;

    ShowCategory449Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_LSK_TEXT),
        0,
        (U8*)GetString(STR_ID_CSB_RSK_TEXT),
        0,
        (S8*)g_buffer1,
        &inputbox_area_data, 
        NULL,
        csb_pen_get_word_callback,
        NULL,
        NULL,
        &ebook_frm_setting_csb,
        MMI_TRUE,
        (S8*)GetImage(IMG_ID_AUDPLY_MAIN_SKIN1_BG),
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();

    SetKeyHandler(csb_44x_change_data_1, KEY_1, KEY_EVENT_DOWN);
}
#endif /* __MMI_CAT44X_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  EntryScreen_501
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScreen_501(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);

    ShowCategory501Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  get_hint_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 get_hint_list(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) hint_array[0], (S8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + item_index)));
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  get261_async_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_indx      [IN]        
 *  menuData        [?]         
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 get261_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(start_indx);
    for (i = 0; i < num_item; ++i)
    {
        mmi_ucs2cpy((S8*) menuData[i].item_list[0], (S8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + i)));
        mmi_ucs2cpy((S8*) menuData[i].item_list[1], (S8*) GetString((U16)(STR_ID_CSB_DUMMY_TEXT)));
        menuData[i].image_list[0] = (U8*) GetImage(IMG_GLOBAL_DEFAULT);
        menuData[i].image_list[1] = (U8*) GetImage(IMG_GLOBAL_DEFAULT);
        menuData[i].image_list[2] = NULL;
        menuData[i].image_list[3] = NULL;
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  get263_async_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_indx      [IN]        
 *  menuData        [?]         
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 get263_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(start_indx);
    for (i = 0; i < num_item; ++i)
    {
        mmi_ucs2cpy((S8*) menuData[i].item_list[0], (S8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + i)));
        menuData[i].image_list[0] = (U8*) GetImage(IMG_GLOBAL_DEFAULT);
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  get425_async_items
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_indx      [IN]        
 *  menuData        [?]         
 *  num_item        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 get425_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(start_indx);
    for (i = 0; i < num_item; i++)
    {
        mmi_ucs2cpy((S8*) menuData[i].item_list[0], (S8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT + i)));
        mmi_ucs2cpy((S8*) menuData[i].item_list[1], (S8*) GetString((U16)(STR_ID_CSB_DUMMY_TEXT)));
        menuData[i].image_list[0] = NULL;
        menuData[i].image_list[1] = NULL;
        menuData[i].image_list[2] = NULL;
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  get_async_hints
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_indx      [IN]        
 *  hintArray       [?]         
 * RETURNS
 *  
 *****************************************************************************/
S32 get_async_hints(S32 start_indx, UI_string_type *hintArray)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(start_indx);
    mmi_ucs2cpy((S8*) hintArray[0], (S8*) GetString((U16)(STR_ID_CSB_MENUITEM1_TEXT_BUF + start_indx)));
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ExitScreen_Generic
 * DESCRIPTION
 *  A Generic Exit handler for all the entry handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScreen_Generic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CSB_AUTO_MODE_TIMER_ID);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_unblock();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  ExitScreen_Inline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitScreen_Inline(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    ExitScreen_Generic();
}


/*****************************************************************************
 * FUNCTION
 *  csb_set_key_handlers
 * DESCRIPTION
 *  Sets the Key handlers for all the category screens
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void csb_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* In AUTO mode and NON-Interactive manual mode, all key should be disabled */
    if (((VIEW_MODE_MANUAL == g_CSB_struct.csb_settings.view_mode) &&
         (MANUAL_MODE_NONINTERACTIVE == g_CSB_struct.csb_settings.manual_mode))
        || (VIEW_MODE_AUTO == g_CSB_struct.csb_settings.view_mode))
    {
        SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
        SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_idle_pen_block();
    #endif 
    }

    /* LSK and RSK will be disabled in unless the search mode is Search by ScrID */
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetKeyHandler(GoBackToMainMenu, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void exit_list_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_CSB_DUMMY_SCR_ID + 1;
    currHistory.entryFuncPtr = entry_list_tab_0;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);
    
    GetCategoryHistory(currHistory.guiBuffer);
    mmi_frm_add_tab_history(SCR_ID_CSB_DUMMY_SCR_ID + 1, &currHistory);    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void entry_list_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;
    U16 nImgIds[6];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 1 ,exit_list_tab_0, NULL, MMI_TAB_PAGE);

    for (index = 0; index < 6; index++)
    {
        //memcpy(subMenuData[index], strName[index], 10);
        kal_wsprintf((unsigned short *)subMenuData[index], "Name%d", index+1);
        subMenuDataPtrs[index] = subMenuData[index];
        nImgIds[index] = IMG_MENU8102_DIALED_CALLS;
        //memcpy(subMenuData[index + 6], strphonenumber, 22);
        kal_wsprintf((unsigned short *)subMenuData[index + 6], "9875656578");
        subMenuDataPtrs[index + 6] = subMenuData[index + 6]; 
    }

    guiBuffer = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1);        

    
    ShowCategory626Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        subMenuDataPtrs,
        (U16*) nImgIds,
        &subMenuDataPtrs[6],
        LIST_MENU,
        0,
        0,
        guiBuffer);

    /* Set the key handlers */
    csb_set_key_handlers();
    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/ 
void exit_list_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S16 ucs2InputBuffer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_CSB_DUMMY_SCR_ID + 2;
    currHistory.entryFuncPtr = entry_list_tab_1;
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) & ucs2InputBuffer);

    GetCategoryHistory(currHistory.guiBuffer);
    mmi_frm_add_tab_history(SCR_ID_CSB_DUMMY_SCR_ID + 2, &currHistory);    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void entry_list_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 index;
    U16 nImgIds[6];
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 2 ,exit_list_tab_1, NULL, MMI_TAB_PAGE);
    
    for (index = 0; index < 6; index++)
    {
        //memcpy(subMenuData[index], strName[index], 10);
        kal_wsprintf((unsigned short *)subMenuData[index], "Name%d", index+1);
        subMenuDataPtrs[index] = subMenuData[index];
        nImgIds[index] = IMG_MENU8102_DIALED_CALLS;
        //memcpy(subMenuData[index + 6], strphonenumber, 22);
        kal_wsprintf((unsigned short *)subMenuData[index + 6], "3646633");
        subMenuDataPtrs[index + 6] = subMenuData[index + 6]; 
    }
    
    guiBuffer = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 2); 
    
    
    ShowCategory626Screen(
        (U8*)GetString(STR_ID_CSB_CATEGORY_TEXT),
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        6,
        subMenuDataPtrs,
        (U16*) nImgIds,
        &subMenuDataPtrs[6],
        LIST_MENU,
        0,
        1,        
        guiBuffer);
    
    /* Set the key handlers */
    csb_set_key_handlers();
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void EntryScreen_626(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_tab_struct tab_pages_info_array[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tab_pages_info_array[0].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 1;
    tab_pages_info_array[0].tab_entry_func = entry_list_tab_0;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;
    
    tab_pages_info_array[1].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 2;
    tab_pages_info_array[1].tab_entry_func = entry_list_tab_1;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    
    mmi_frm_general_tab_entry(SCR_ID_CSB_DUMMY_SCR_ID, EntryScreen_626, tab_pages_info_array, 2);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void EntryScreen_657(void)
{
    mmi_frm_tab_struct tab_pages_info_array[2];

    tab_pages_info_array[0].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 1;
    tab_pages_info_array[0].tab_entry_func = entry_inline_tab_0;
    tab_pages_info_array[0].tab_icon = (U8*)GetImage(gIndexIconsImageList[0]);
    tab_pages_info_array[0].tab_string = NULL;   

    
    tab_pages_info_array[1].screen_id = SCR_ID_CSB_DUMMY_SCR_ID + 2;
    tab_pages_info_array[1].tab_entry_func = entry_inline_tab_1;
    tab_pages_info_array[1].tab_icon = (U8*)GetImage(gIndexIconsImageList[1]);
    tab_pages_info_array[1].tab_string = NULL;
    
    mmi_frm_general_tab_entry(SCR_ID_CSB_DUMMY_SCR_ID, EntryScreen_657, tab_pages_info_array, 2);
}



/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void exit_inline_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S32 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	CloseCategory57Screen();
    currHistory.scrnID = SCR_ID_CSB_DUMMY_SCR_ID + 1;
    currHistory.entryFuncPtr = entry_inline_tab_0;
            
    GetCategoryHistory(currHistory.guiBuffer);
	inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);    
    mmi_frm_add_tab_n_history(SCR_ID_CSB_DUMMY_SCR_ID + 1, &currHistory, (U16)inputBufferSize); 
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void entry_inline_tab_0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
	U8 *inputBuffer = NULL;
	U16 inputBufferSize;	
    S32 index;
    U16 nImgIds[CSB_MAX_BUFFER_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 1 ,exit_inline_tab_0, NULL, MMI_TAB_PAGE);

    InitializeCategory57Screen();

    CSBAppFillInlineStruct();

    for (index = 0; index < CSB_MAX_BUFFER_LEN; index++)
    {        
        nImgIds[index] = IMG_MENU8102_DIALED_CALLS;        
    }
	
	inputBuffer = mmi_frm_get_cur_tab_n_input_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1,  &inputBufferSize);

    guiBuffer   = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1); 
		
	if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, CSB_MAX_BUFFER_LEN, inputBuffer);
    }

    ShowCategory657Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        CSB_MAX_BUFFER_LEN,
        nImgIds,
        wgui_inline_items,
        0,
        0,
        guiBuffer);    

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void exit_inline_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history currHistory;
    S32  inputBufferSize;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_CSB_DUMMY_SCR_ID + 2;
    currHistory.entryFuncPtr = entry_inline_tab_1;
    
    
    GetCategoryHistory(currHistory.guiBuffer);
	inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) currHistory.inputBuffer);    
    mmi_frm_add_tab_n_history(SCR_ID_CSB_DUMMY_SCR_ID + 2, &currHistory, (U16)inputBufferSize);    
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
void entry_inline_tab_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
	U8 *inputBuffer = NULL;
	U16 inputBufferSize;	
    S32 index;
    U16 nImgIds[CSB_MAX_BUFFER_LEN];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID + 2 ,exit_inline_tab_1, NULL, MMI_TAB_PAGE);
	
    InitializeCategory57Screen();
	
    CSBAppFillInlineStruct();
	
    DisableCategory57ScreenDone();
	
    for (index = 0; index < CSB_MAX_BUFFER_LEN; index++)
    {        
        nImgIds[index] = IMG_MENU8102_DIALED_CALLS;        
    }
	
	inputBuffer = mmi_frm_get_cur_tab_n_input_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1,  &inputBufferSize);
	
    guiBuffer   = mmi_frm_get_cur_tab_gui_buffer(SCR_ID_CSB_DUMMY_SCR_ID + 1); 
	
	if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, CSB_MAX_BUFFER_LEN, inputBuffer);
    }
	
    ShowCategory657Screen(
        STR_ID_CSB_CATEGORY_TEXT,
        0,
        STR_ID_CSB_LSK_TEXT,
        0,
        STR_ID_CSB_RSK_TEXT,
        0,
        CSB_MAX_BUFFER_LEN,
        nImgIds,
        wgui_inline_items,
        0,
        1,        
        guiBuffer);

    ChangeLeftSoftkey(STR_ID_CSB_LSK_TEXT, 0);
    ChangeRightSoftkey(STR_ID_CSB_RSK_TEXT, 0);

    //SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_DOWN);
    //SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, KEY_EVENT_UP);

    /* Set the key handlers */
    //csb_set_key_handlers();

    SetKeyHandler(mmi_frm_general_tab_l_arrow_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_frm_general_tab_r_arrow_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
}



#endif /* __MMI_CSB_BROWSER__ */ 

