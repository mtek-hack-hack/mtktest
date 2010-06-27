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
 *   ThemeConverterXML.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 * Contains parser side handlers for the DLT project
 *
 * Author:
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/


#include "MMI_features.h"
#include "stdC.h"
#include "L4Dr.h"
#include "MMIDataType.h"
#include "GlobalMenuItems.h"
#include "FrameworkGprot.h"         
#include "FrameworkProt.h" 
#include "Fat_fs.h"
#include "WallpaperDefs.h"
#include "ScreenSaverDefs.h"
#include "MainMenuDef.h"
#include "StatusIconRes.h"
#include "CalendarDef.h"
#include "Phonebookdef.h"
#include "CallManagementIdDef.h"
#include "MessagesResourceData.h"
#include "NetworkSetupGProt.h"
#include "wgui_categories_defs.h"
#include "callhistoryenum.h"
#include "xml_def.h"
#include "wgui_status_icons.h"
#include "PhoneBookDef.h"
#include "ComposeRingToneDefs.h"
#include "FunAndGamesDefs.h"
#include "PhoneSetup.h"

#define __THEME_CONVERTER_XML_C__
#include "ThemeConverterData.h"

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

/* Parser Object */

XML_PARSER_STRUCT g_tc_parser;  /* parser object */

#define NO_IMG_ATTR 300
#define NO_XML_TAGS 42
#define IMAGE_LIST_POS_XML_TAG_MAP 12

/* Temporary Images ID for some images */

/* End of the temporary id's */

/*******book Keeping***************/
extern MMI_theme theme_DLT;
extern U16 g_tm_checkThemeVersion;

/**********************************/

extern MMI_theme g_tc_theme_DLT;

/*****************************************************************************
Various table structures for the themeconverter
******************************************************************************/

const tc_image_tags_index_struct g_tc_image_tags_map[] = 
{
    {"calendar_may", IMG_CALENDAR_MAY},
    {"calendar_jan", IMG_CALENDAR_JAN},
    {"calendar_feb", IMG_CALENDAR_FEB},
    {"calendar_mar", IMG_CALENDAR_MAR},
    {"calendar_apr", IMG_CALENDAR_APR},
    {"calendar_jun", IMG_CALENDAR_JUN},
    {"calendar_jul", IMG_CALENDAR_JUL},
    {"calendar_aug", IMG_CALENDAR_AUG},
    {"calendar_sep", IMG_CALENDAR_SEP},
    {"calendar_oct", IMG_CALENDAR_OCT},
    {"calendar_nov", IMG_CALENDAR_NOV},
    {"calendar_dec", IMG_CALENDAR_DEC},
    {"calendar_week", CAL_ENGLISH_DAYS_IMAGE},
    {"call_scr_out", IMG_CM_STATE_SINGLE_ACTIVE},
    {"call_scr_inc", IMG_PHB_DEFAULT},
    {"call_missed", MISSED_LSK_ICN},
    {"comp_bkg", IMG_RING_COMPOSER_BACKGROUND},
    {"inprogress", IMG_THEME_ACTIVATION},
    {"idle_scr_techno_analog_clock", IMG_TECHNO_ANALOG_CLOCK},
    {"idle_scr_techno_digital_clock", IMG_TECHNO_DIGITAL_CLOCK},
    {"idle_scr_mm_shortcut", IMG_IDLE_MAINMENU_SHORCUT},
    {"idle_scr_msg_shortcut", IMG_IDLE_MESSAGE_SHORTCUT},
    {"idle_scr_phb_shortcut", IMG_IDLE_PHONEBOOK_SHORTCUT},
    {"idle_scr_dialingscr_shortcut", IMG_IDLE_DIALING_SCREEN_SHORTCUT},
    {"idle_scr_mm_shortcut_pressed", IMG_IDLE_MAINMENU_SHORCUT_PRESSED},
    {"idle_scr_msg_shortcut_pressed", IMG_IDLE_MESSAGE_SHORTCUT_PRESSED},
    {"idle_scr_phb_shortcut_pressed", IMG_IDLE_PHONEBOOK_SHORTCUT_PRESSED},
    {"idle_scr_dialingscr_shortcut_pressed", IMG_IDLE_DIALING_SCREEN_SHORTCUT_PRESSED},
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    {"message_sending", IMG_NEW_SMS_SEND},
    {"mm_mm_oft", MAIN_MENU_MATRIX_MULTIMEDIA_ICON},
    {"mm_ch_oft", MAIN_MENU_MATRIX_CALL_HISTORY_ICON},
    {"mm_extras_oft", MAIN_MENU_MATRIX_EXTRA_ICON},
    {"mm_fng_oft", MAIN_MENU_MATRIX_FUNANDGAMES_ICON},
    {"mm_org_oft", MAIN_MENU_MATRIX_ORGANIZER_ICON},
    {"mm_phb_oft", MAIN_MENU_MATRIX_PHONEBOOK_ICON},
    {"mm_profile_oft", MAIN_MENU_MATRIX_PROFILES_ICON},
    {"mm_scut_oft", MAIN_MENU_MATRIX_SHORTCUTS_ICON},
    {"mm_service_oft", MAIN_MENU_MATRIX_SERVICES_ICON},
    {"mm_settings_oft", MAIN_MENU_MATRIX_SETTINGS_ICON},
    {"mm_sms_oft", MAIN_MENU_MATRIX_MESSAGES_ICON},
    {"mm_fm_oft", MAIN_MENU_MATRIX_FILEMNGR_ICON},
    {"mm_bkgrnd", IMG_MAIN_MENU_CIRCULAR_BG},
    {"mm_mm_list_oft", MAIN_MENU_LIST_MULTIMEDIA_ICON},
    {"mm_ch_list_oft", MAIN_MENU_LIST_CALL_HISTORY_ICON},
    {"mm_extras_list_oft", MAIN_MENU_LIST_EXTRA_ICON},
    {"mm_fng_list_oft", MAIN_MENU_LIST_FUNANDGAMES_ICON},
    {"mm_org_list_oft", MAIN_MENU_LIST_ORGANIZER_ICON},
    {"mm_phb_list_oft", MAIN_MENU_LIST_PHONEBOOK_ICON},
    {"mm_profile_list_oft", MAIN_MENU_LIST_PROFILES_ICON},
    {"mm_scut_list_oft", MAIN_MENU_LIST_SHORTCUTS_ICON},
    {"mm_service_list_oft", MAIN_MENU_LIST_SERVICES_ICON},
    {"mm_settings_list_oft", MAIN_MENU_LIST_SETTINGS_ICON},
    {"mm_sms_list_oft", MAIN_MENU_LIST_MESSAGES_ICON},
    {"mm_fm_list_oft", MAIN_MENU_LIST_FILEMNGR_ICON},
    {"mm_mm_circ_oft", MAIN_MENU_CIRCULAR_MULTIMEDIA_ICON},
    {"mm_ch_circ_oft", MAIN_MENU_CIRCULAR_CALL_HISTORY_ICON},
    {"mm_extras_circ_oft", MAIN_MENU_CIRCULAR_EXTRA_ICON},
    {"mm_fng_circ_oft", MAIN_MENU_CIRCULAR_FUNANDGAMES_ICON},
    {"mm_org_circ_oft", MAIN_MENU_CIRCULAR_ORGANIZER_ICON},
    {"mm_phb_circ_oft", MAIN_MENU_CIRCULAR_PHONEBOOK_ICON},
    {"mm_profile_circ_oft", MAIN_MENU_CIRCULAR_PROFILES_ICON},
    {"mm_scut_circ_oft", MAIN_MENU_CIRCULAR_SHORTCUTS_ICON},
    {"mm_service_circ_oft", MAIN_MENU_CIRCULAR_SERVICES_ICON},
    {"mm_settings_circ_oft", MAIN_MENU_CIRCULAR_SETTINGS_ICON},
    {"mm_fm_circ_oft", MAIN_MENU_CIRCULAR_FILEMNGR_ICON},
    {"mm_sms_circ_oft", MAIN_MENU_CIRCULAR_MESSAGES_ICON},
    {"mm_mm_rotate_oft", MAIN_MENU_ROTATE_MULTIMEDIA_ICON},
    {"mm_ch_rotate_oft", MAIN_MENU_ROTATE_CALL_HISTORY_ICON},
    {"mm_extras_rotate_oft", MAIN_MENU_ROTATE_EXTRA_ICON},
    {"mm_fng_rotate_oft", MAIN_MENU_ROTATE_FUNANDGAMES_ICON},
    {"mm_org_rotate_oft", MAIN_MENU_ROTATE_ORGANIZER_ICON},
    {"mm_phb_rotate_oft", MAIN_MENU_ROTATE_PHONEBOOK_ICON},
    {"mm_profile_rotate_oft", MAIN_MENU_ROTATE_PROFILES_ICON},
    {"mm_scut_rotate_oft", MAIN_MENU_ROTATE_SHORTCUTS_ICON},
    {"mm_service_rotate_oft", MAIN_MENU_ROTATE_SERVICES_ICON},
    {"mm_settings_rotate_oft", MAIN_MENU_ROTATE_SETTINGS_ICON},
    {"mm_sms_rotate_oft", MAIN_MENU_ROTATE_MESSAGES_ICON},
    {"mm_fm_rotate_oft", MAIN_MENU_ROTATE_FILEMNGR_ICON},
    {"mm_mm_ma_oft", MAIN_MENU_MATRIX_MULTIMEDIA_ANIMATION},
    {"mm_ch_ma_oft", MAIN_MENU_MATRIX_CALL_HISTORY_ANIMATION},
    {"mm_extras_ma_oft", MAIN_MENU_MATRIX_EXTRA_ANIMATION},
    {"mm_fng_ma_oft", MAIN_MENU_MATRIX_FUNANDGAMES_ANIMATION},
    {"mm_org_ma_oft", MAIN_MENU_MATRIX_ORGANIZER_ANIMATION},
    {"mm_phb_ma_oft", MAIN_MENU_MATRIX_PHONEBOOK_ANIMATION},
    {"mm_profile_ma_oft", MAIN_MENU_MATRIX_PROFILES_ANIMATION},
    {"mm_scut_ma_oft", MAIN_MENU_MATRIX_SHORTCUTS_ANIMATION},
    {"mm_service_ma_oft", MAIN_MENU_MATRIX_SERVICES_ANIMATION},
    {"mm_settings_ma_oft", MAIN_MENU_MATRIX_SETTINGS_ANIMATION},
    {"mm_sms_ma_oft", MAIN_MENU_MATRIX_MESSAGES_ANIMATION},
    {"mm_fm_ma_oft", MAIN_MENU_MATRIX_FILEMNGR_ANIMATION},
    {"mm_mm_pa_oft", MAIN_MENU_PAGE_MULTIMEDIA_ICON},
    {"mm_ch_pa_oft", MAIN_MENU_PAGE_CALL_HISTORY_ICON},
    {"mm_extras_pa_oft", MAIN_MENU_PAGE_EXTRA_ICON},
    {"mm_fng_pa_oft", MAIN_MENU_PAGE_FUNANDGAMES_ICON},
    {"mm_org_pa_oft", MAIN_MENU_PAGE_ORGANIZER_ICON},
    {"mm_phb_pa_oft", MAIN_MENU_PAGE_PHONEBOOK_ICON},
    {"mm_profile_pa_oft", MAIN_MENU_PAGE_PROFILES_ICON},
    {"mm_scut_pa_oft", MAIN_MENU_PAGE_SHORTCUTS_ICON},
    {"mm_service_pa_oft", MAIN_MENU_PAGE_SERVICES_ICON},
    {"mm_settings_pa_oft", MAIN_MENU_PAGE_SETTINGS_ICON},
    {"mm_sms_pa_oft", MAIN_MENU_PAGE_MESSAGES_ICON},
    {"mm_fm_pa_oft", MAIN_MENU_PAGE_FILEMNGR_ICON},
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    /* Bidegree icons */
    {"mm_bideg_ap_bdeg_oft", MAIN_MENU_AUDPLY_ICON},
    {"mm_bideg_ch_oft", MAIN_MENU_CALL_HISTORY_ICON},
    {"mm_bideg_cm_bdeg_oft", MAIN_MENU_CAMERA_ICON},
    {"mm_bideg_extras_oft", MAIN_MENU_EXTRA_ICON},
    {"mm_bideg_fm_oft", MAIN_MENU_FILEMNGR_ICON},
    {"mm_bideg_fng_oft", MAIN_MENU_FUNANDGAMES_ICON},
    {"mm_bideg_mm_oft", MAIN_MENU_MULTIMEDIA_ICON},
    {"mm_bideg_org_oft", MAIN_MENU_ORGANIZER_ICON},
    {"mm_bideg_phb_oft", MAIN_MENU_PHONEBOOK_ICON},
    {"mm_bideg_profile_oft", MAIN_MENU_PROFILES_ICON},
    {"mm_bideg_scut_oft", MAIN_MENU_SHORTCUTS_ICON},
    {"mm_bideg_service_oft", MAIN_MENU_SERVICES_ICON},
    {"mm_bideg_settings_oft", MAIN_MENU_SETTINGS_ICON},
    {"mm_bideg_sms_oft", MAIN_MENU_MESSAGES_ICON},
    {"mm_bideg_vp_bdeg_oft", MAIN_MENU_VDOPLY_ICON},
    {"mm_bideg_vr_bdeg_oft", MAIN_MENU_VDOREC_ICON},
    {"mm_bkgrnd", IMG_MAIN_MENU_BG},
    {"mm_bideg_avzone_selected",MAIN_MENU_AVZONE_ICON_SELECTED},
    {"mm_bideg_pim_selected",MAIN_MENU_PIM_ICON_SELECTED},
    {"mm_bideg_entertainment_selected",MAIN_MENU_ENTERTAINMENT_ICON_SELECTED},
    {"mm_bideg_system_selected",MAIN_MENU_SYSTEM_ICON_SELECTED},
    /* Bidegree icons */
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    {"popup", IMG_PROCESSING_PHONEBOOK},
    {"phb_sub_sear", IMG_ID_PHB_QUICK_SEARCH},
    {"phb_sub_se_en", IMG_PHB_SEARCH_ENTRY},
    {"phb_sub_add", IMG_PHB_ADD_ENTRY},
    {"phb_sub_copy", IMG_PHB_COPY_ALL},
    {"phb_sub_del", IMG_PHB_DELETE_ALL},
    {"phb_sub_grp", IMG_PHB_CALLER_GROUP},
    {"phb_sub_ext", IMG_PHB_OWNER_NUMBER},
    {"phb_sub_sett", IMG_PHB_SETTINGS},
    {"scr_idl_search", IMG_ID_NETSET_NW_SEARCH},
    {"scr_idl_logo", IMG_BOOTUP_SCANNING_LOGO},
    {"scsaver", IMG_ID_DISPCHAR_THEME_SCREENSAVER},
    {"status_battery", IMG_SI_BATTERY_STRENGTH},
    {"status_sig", IMG_SI_SIGNAL_STRENGTH},
    {"st_ROAMING", IMG_SI_ROAMING_INDICATOR},
    {"st_CALL_DIVERT_L1", IMG_SI_CALL_DIVERT_L1},
    {"st_CALL_DIVERT_L2", IMG_SI_CALL_DIVERT_L2},
    {"st_MUTE", IMG_SI_MUTE},
    {"st_INCOMING_SMS", IMG_SI_SMS_INDICATOR},
    {"st_MMS_UNREAD", IMG_SI_MMS_UNREAD_INDICATOR},
    {"st_MMS_BUSY", IMG_SI_MMS_BUSY_INDICATOR},
    {"st_VIBRATION", IMG_SI_VIBRATE},
    {"st_SILENT", IMG_SI_SILENT},
    {"st_RING", IMG_SI_RING},
    {"st_VIBRATE_AND_RING", IMG_SI_VIBRATE_AND_RING},
    {"st_VIBRATE_THEN_RING", IMG_SI_VIBRATE_THEN_RING},
    {"st_GPRS_SERVICE", IMG_SI_GPRS_INDICATOR},
    {"st_EARPHONE_INDICATOR", IMG_SI_EARPHONE_INDICATOR},
    {"st_GPRS_ATT_NO_PDP_INDICATOR", IMG_SI_GPRS_ATT_NO_PDP_INDICATOR},
    {"st_ALARM", IMG_SI_ALARM_ACTIVATED},
    {"st_VOICE_RECORD", IMG_SI_VOICE_RECORD},
    {"st_KEYPAD_LOCK", IMG_SI_KEYPAD_LOCK},
    {"st_KEYPAD_UNLOCK", IMG_SI_KEYPAD_UNLOCK},
    {"st_MISSED_CALL", IMG_SI_MISSED_CALL_INDICATOR},
    {"st_UNREAD_VOICE_L1L2", IMG_SI_UNREAD_VOICE_L1L2},
    {"st_UNREAD_VOICE_L1", IMG_SI_UNREAD_VOICE_L1},
    {"st_UNREAD_VOICE_L2", IMG_SI_UNREAD_VOICE_L2},
    {"st_UNREAD_FAX_L1L2", IMG_SI_UNREAD_FAX_L1L2},
    {"st_UNREAD_FAX_L1", IMG_SI_UNREAD_FAX_L1},
    {"st_UNREAD_FAX_L2", IMG_SI_UNREAD_FAX_L2},
    {"st_UNREAD_EMAIL_L1L2", IMG_SI_UNREAD_EMAIL_L1L2},
    {"st_UNREAD_EMAIL_L1", IMG_SI_UNREAD_EMAIL_L1},
    {"st_UNREAD_EMAIL_L2", IMG_SI_UNREAD_EMAIL_L2},
    {"st_IMPS_MSG", IMG_SI_IMPS_MSG},
    {"st_IMPS_LOGIN", IMG_SI_IMPS_LOGIN},
    {"st_WAP", IMG_SI_WAP},
    {"st_POC", IMG_SI_POC},
    {"st_BT", IMG_SI_BT},
    {"st_IR", IMG_SI_IR_INDICATOR},
    {"st_STOP_WATCH", IMG_SI_STOPWATCH},
    {"st_CHAT_INDICATION_ROOM1", IMG_BLINKINGICON_CHAT_ROOM1},
    {"st_CHAT_INDICATION_ROOM2", IMG_BLINKINGICON_CHAT_ROOM2},
    {"st_NETWORK_CIPHER_GSM", IMG_SI_NETWORK_CIPHER_GSM},
    {"st_NETWORK_CIPHER_GPRS", IMG_SI_NETWORK_CIPHER_GPRS},
    {"st_sig1", IMG_SI_SIGNAL_STRENGTH_L1},
    {"st_sig2", IMG_SI_SIGNAL_STRENGTH_L2},
    {"st_JAVA_PAUSE", IMG_SI_JAVA_PAUSE},
    {"title_mm_mm_icon", MAIN_MENU_TITLE_MULTIMEDIA_ICON},
    {"title_mm_ch_icon", MAIN_MENU_TITLE_CALL_HISTORY_ICON},
    {"title_mm_extras_icon", MAIN_MENU_TITLE_EXTRA_APP_ICON},
    {"title_mm_fng_icon", MAIN_MENU_TITLE_FUNANDGAMES_ICON},
    {"title_mm_org_icon", MAIN_MENU_TITLE_ORGANIZER_ICON},
    {"title_mm_phb_icon", MAIN_MENU_TITLE_PHONEBOOK_ICON},
    {"title_mm_profile_icon", MAIN_MENU_TITLE_PROFILES_ICON},
    {"title_mm_scut_icon", MAIN_MENU_TITLE_SHORTCUTS_ICON},
    {"title_mm_service_icon", MAIN_MENU_TITLE_SERVICES_ICON},
    {"title_mm_settings_icon", MAIN_MENU_TITLE_SETTINGS_ICON},
    {"title_mm_sms_icon", MAIN_MENU_TITLE_MESSAGES_ICON},
    {"title_mm_fm_icon", MAIN_MENU_TITLE_FILE_MNGR_ICON},
    {"wallpaper", IMG_ID_DISPCHAR_THEME_WALLPAPER}
};

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__

const tc_search_image_all_tags_struct g_tc_search_all_tags_image_map[] = 
{
    {0, 0},     /* a */
    {0, 0},     /* b */
    {0, 17},    /* c */
    {0, 0},     /* d */
    {0, 0},     /* e */
    {0, 0},     /* f */
    {0, 0},     /* g */
    {0, 0},     /* h */
    {17, 11},   /* i */
    {0, 0},     /* j */
    {0, 0},     /* k */
    {0, 0},     /* l */
    {28, 74},   /* m */
    {0, 0},     /* n */
    {0, 0},     /* o */
    {102, 9},   /* p */
    {0, 0},     /* q */
    {0, 0},     /* r */
    {111, 48},  /* s */
    {159, 12},  /* t */
    {0, 0},     /* u */
    {0, 0},     /* v */
    {171, 1},   /* w */
    {0, 0},     /* x */
    {0, 0},     /* y */
    {0, 0}      /* z */
};
#elif defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)

const tc_search_image_all_tags_struct g_tc_search_all_tags_image_map[] = 
{
    {0, 0},     /* a */
    {0, 0},     /* b */
    {0, 17},    /* c */
    {0, 0},     /* d */
    {0, 0},     /* e */
    {0, 0},     /* f */
    {0, 0},     /* g */
    {0, 0},     /* h */
    {17, 11},   /* i */
    {0, 0},     /* j */
    {0, 0},     /* k */
    {0, 0},     /* l */
    {28, 21},   /* m */
    {0, 0},     /* n */
    {0, 0},     /* o */
    {49, 9},    /* p */
    {0, 0},     /* q */
    {0, 0},     /* r */
    {58, 48},   /* s */
    {106, 12},  /* t */
    {0, 0},     /* u */
    {0, 0},     /* v */
    {118, 1},   /* w */
    {0, 0},     /* x */
    {0, 0},     /* y */
    {0, 0}      /* z */
};
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */

const tc_search_image_all_tags_struct g_tc_search_all_tags_image_map[] = 
{
    {0, 0},     /* a */
    {0, 0},     /* b */
    {0, 17},    /* c */
    {0, 0},     /* d */
    {0, 0},     /* e */
    {0, 0},     /* f */
    {0, 0},     /* g */
    {0, 0},     /* h */
    {17, 11},   /* i */
    {0, 0},     /* j */
    {0, 0},     /* k */
    {0, 0},     /* l */
    {0, 0},     /* m */
    {0, 0},     /* n */
    {0, 0},     /* o */
    {28, 9},    /* p */
    {0, 0},     /* q */
    {0, 0},     /* r */
    {37, 48},   /* s */
    {85, 12},   /* t */
    {0, 0},     /* u */
    {0, 0},     /* v */
    {97, 1},    /* w */
    {0, 0},     /* x */
    {0, 0},     /* y */
    {0, 0}      /* z */
};
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

static U8 g_tc_thm_process_call_count;  /* theme Process Queue Counter */

/*****************************************************************************
 * FUNCTION
 *  mmi_tc_string_binary_search
 * DESCRIPTION
 *  string binary search.
 *  [Note] all strings in tag_map should be sorted in ascending alphabetic order
 * PARAMETERS
 *  tag_map     [IN] tags map containing sorted tag strings         
 *  num         [IN] total number of tag_map items
 *  str         [IN] tag string to search
 * RETURNS
 *  -1: error, otherwise: index in tag_map where str found
 *****************************************************************************/
static S32 mmi_tc_string_binary_search(const tc_all_tags_index_struct *tag_map, S32 num, const S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 iEnd = num-1;
    S32 iStart = 0;
    S32 result;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (iStart <= iEnd)
    {
        idx = (iStart + iEnd)/2;

        //Trace2((MMI_FW_TRC_G1_FRM, "search index = (%d, %d, %d)\n", iStart, iEnd, idx));

        result = strcmp(str, tag_map[idx].xml_tag);
        if ( result == 0)
        {
            return idx;
        }
        else if (result < 0)
        {
            iEnd = idx-1;
        }
        else
        {
            iStart = idx+1;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_my_xml_elem_start_hdlr
 * DESCRIPTION
 *  (void *data, const char *el, const char **attr)
 *  function for handling of the start element tag
 * PARAMETERS
 *  data_p      [?]         
 *  el_p        [IN]        
 *  attr_p      [IN] 
 *  err_code    [IN]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_my_xml_elem_start_hdlr(void *data_p, const char *el_p, const char **attr_p, S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tag_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_tm_checkThemeVersion)
    {
        if (!(strncmp((PS8) "devicetheme", el_p, strlen(el_p))) || !(strncmp((PS8) "deviceinfo", el_p, strlen(el_p))) ||
            !(strncmp((PS8) "media", el_p, strlen(el_p))))
        {   /* continue */
        }
        else
        {
            xml_free_parse(&g_tc_parser);
            return;
        }
    }

    /* find tag handler by binary search */

    tag_index = mmi_tc_string_binary_search(g_tc_xml_tags_map, 
                                sizeof(g_tc_xml_tags_map)/sizeof(tc_all_tags_index_struct), el_p);

    /* tag should always be found */
    MMI_ASSERT(tag_index >= 0);

    /* execute tag handler */
    g_tc_xml_tags_map[tag_index].tag_handler((U8 **) attr_p, (void*)(g_tc_xml_tags_map+tag_index));
    g_tc_thm_process_call_count++;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_my_xml_elem_end_hdlr
 * DESCRIPTION
 *  (void *data, const char *el)
 *  function for handling of the end element tag
 * PARAMETERS
 *  data_p      [?]         
 *  el_p        [IN]        
 *  err_code    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_my_xml_elem_end_hdlr(void *data_p, const char *el_p, S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 end_element[] = "media";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!strcmp(el_p, (PS8) end_element))
    {
        xml_free_parse(&g_tc_parser);
    }
    else
    {
        if (g_tc_thm_process_call_count == 15)
    #ifdef __DLT_ENABLE_PROCESS_QUEUE__
            theme_process_queue();
    #else /* __DLT_ENABLE_PROCESS_QUEUE__ */ 
        {
        }
    #endif /* __DLT_ENABLE_PROCESS_QUEUE__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_processqueue
 * DESCRIPTION
 *  (void)
 *  function for polling of the queues
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int mmi_tc_processqueue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tc_image_list_tag_handler
 * DESCRIPTION
 *  (U8 **attr)
 *  handles the image_list tag obained by parsing the XML file
 * PARAMETERS
 *  attr_p      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_tc_image_list_tag_handler(U8 **attr_p, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 first_alpha_attr;
    U8 count1;   /* count for total number of the image attributes */
    U8 loc;             /* position of the attribute in the table */
    U8 type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    if (!strcmp((PS8) attr_p[0], "status_sig"))
    {
        strcpy((PS8) attr_p[0], "st_sig1");
    }
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
    first_alpha_attr = attr_p[0][0];
    loc = g_tc_search_all_tags_image_map[first_alpha_attr - 97].index;
    type = (U8) atoi((PS8) attr_p[3]);
    for (count1 = loc; count1 <= (g_tc_search_all_tags_image_map[first_alpha_attr - 97].no_of_elements + loc); count1++)
    {
        S16 check;

        check = strncmp((PS8) g_tc_image_tags_map[count1].image_tag, (PS8) attr_p[0], strlen((PS8) attr_p[0]));
        if (check == 0)
        {
            mmi_tm_set_imageid(g_tc_image_tags_map[count1].imageId, (U32) atoi((PS8) attr_p[1]), type);
            break;
        }
    }
}

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ /* mmi downloadble themes support */

