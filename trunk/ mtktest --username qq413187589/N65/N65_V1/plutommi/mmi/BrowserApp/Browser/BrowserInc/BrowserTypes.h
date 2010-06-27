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
 * BrowserTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains all the data structures used for browser secondary MMI implementation.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERTYPES_H
#define BROWSERTYPES_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "custom_wap_config.h"
#include "custom_nvram_editor_data_item.h"
#include "common_nvram_editor_data_item.h"
#include "wap_ps_struct.h"
#include "app_mem.h"
#include "app_url.h"
#include "bam_lib.h"
#include "FileMgr.h"
#include "DLAgentDef.h"
#include "wgui_status_icons.h"


#define BRW_BKGRD_DOWNLOAD_SUPPORT
//#define BRW_KEYPAD_SHORTCUTS_SUPPORT
//#define BRW_SEND_DEVICE_ID_SUPPORT
//#define BRW_SECURITY_WARNINGS_SUPPORT

/*temp code for implementing ASM support in brw app*/
#define APPMEM_SUPPORT 
#if !defined(APPMEM_SUPPORT) || !defined(WAP_CUSTOM_CFG_BROWSER_MEM_SIZE)
#define WAP_CUSTOM_CFG_BROWSER_MEM_SIZE 0
#endif
/*temp code for implementing ASM support in brw app*/

#define BRW_APPLICATION_ID	30

#define BRW_DCS_ASCII	0x00
#define BRW_DCS_UCS		0x01

#define BRW_ADDRESS_LIST_MAX_ITEMS			NVRAM_BRW_MAX_ADDRESS_HISTORY
#define BRW_ADDRESS_LIST_TITLE_LENGTH		NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH
#define BRW_ADDRESS_LIST_URL_LENGTH			NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH

#define BRW_ADM_MEMORY_POOL_SIZE			50*1024
#define BRW_UTF8_ENCODING_LENGTH			3 /*as some of the chinese chars may take 3 bytes*/

#define BRW_MAX_TITLE_LENGTH				WAP_BAM_MAX_TITLE_LABEL_LENGTH//NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH
#define BRW_MAX_URL_LENGTH					WAP_BAM_MAX_URL_LEN
#define BRW_RECENT_PAGES_COUNT				300

#define BRW_WTAI_PHONE_NUMBER_LEN		127
#define BRW_MEMORY_STATUS_MSG_LEN		200

#define BRW_CURRENT_CERT_STR_LEN	1000
#define BRW_SESSION_INFO_STR_LEN	200

#define BRW_BLANK_HOMEPAGE_URL				"about:blank"
#define BRW_DEFAULT_ENTER_ADDR_STR			"http://"
#define BRW_DEFAULT_URI_SCHEME				"http://"

#define BRW_TEMP_VBKM_FILE_DRIVE			MMI_SYSTEM_DRV
#define BRW_TEMP_VBKM_FILE_PATH				L"\\@wap\\temp\\~bookmark_tmp.url"

#define BRW_DO_ELEMENT_EVENT_TYPE_PREVIOUS	"prev"

#define BRW_URI_REQ_SCHEME_ACTIVATE_JAVA	"ege"
#define BRW_URI_REQ_SCHEME_SEND_SMS			"sms"
#define BRW_URI_REQ_SCHEME_SEND_MMS			"mms"
#define BRW_URI_REQ_SCHEME_SEND_SMS_TO		"smsto"
#define BRW_URI_REQ_SCHEME_SEND_MMS_TO		"mmsto"

/* Time out limits */
#define BRW_TIME_OUT_MIN_VAL	15
#define BRW_TIME_OUT_MAX_VAL	300
/* Time out limits */

/* Maximum number of characters to be shown in case of url */
#define BRW_MAX_VISIBLE_URL_LENGTH	38

#define BRW_PEER_BUFF_TITLE_LEN_BYTES_COUNT	4

/*Browser preferences*/
#define BRW_TIME_OUT_LEN				    3
#define BRW_ZOOM_VAL_LEN				    4
/*Number of options to be shown for different browser preferences items*/
#define BRW_PREFERENCES_INLINE_SHOW_IMAGES_OPTION_COUNT			2
#define BRW_PREFERENCES_INLINE_SHOW_VIDEOS_OPTION_COUNT			2
#define BRW_PREFERENCES_INLINE_PLAY_SOUNDS_OPTION_COUNT			2
#define BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_OPTION_COUNT	2
#define BRW_PREFERENCES_INLINE_CSS_OPTION_COUNT					2
#define BRW_PREFERENCES_INLINE_SCRIPT_OPTION_COUNT				2
#define BRW_PREFERENCES_INLINE_CACHE_OPTION_COUNT				2
#define BRW_PREFERENCES_INLINE_COOKIE_OPTION_COUNT				2
#define BRW_PREFERENCES_INLINE_SHORTCUTS_OPTION_COUNT			2
#define BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_OPTION_COUNT	2
#define BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_OPTION_COUNT		2
/*Number of options to be shown for different browser preferences items*/
/*Browser preferences*/

/* Added for authentication */
#define BRW_MAX_WSP_RETRIES		 4
#define BRW_AUTH_USERNAME_LEN    WPS_MAX_USERNAME_LEN
#define BRW_AUTH_PASSWORD_LEN    WPS_MAX_PASSWORD_LEN

/*stored pages*/
#define BRW_STORED_PAGE_PROPERTIES_COUNT	4
#define BRW_STORED_PAGE_PROPERTIES_DATE_LEN	10
#define BRW_STORED_PAGE_PROPERTIES_SIZE_LEN	20
/*stored pages*/

/*This Page*/
#define BRW_PAGE_OBJECT_PROPERTIES_COUNT	2
#define BRW_PAGE_OBJECT_TYPES_COUNT			4
#define BRW_PAGE_OBJECT_NAME_LEN			50
#define BRW_PAGE_OBJECT_IMAGES_MAX			100
#define BRW_PAGE_OBJECT_BG_IMAGES_MAX		50
#define BRW_PAGE_OBJECT_SOUNDS_MAX			20
#define BRW_PAGE_OBJECT_OTHERS_MAX			50
#define BRW_THIS_PAGE_PROPERTIES_COUNT		3
#define BRW_THIS_PAGE_PROPERTIES_SIZE_LEN	20
/*This Page*/

/*Object Properties*/
//#define BRW_OBJECT_PROPERTIES_MAX_COUNT		4
#define BRW_OBJECT_PROPERTIES_NAME_LEN		BRW_MAX_TITLE_LENGTH
#define BRW_OBJECT_PROPERTIES_ADDRESS_LEN	BRW_MAX_URL_LENGTH
#define BRW_OBJECT_PROPERTIES_SIZE_LEN		50
#define BRW_OBJECT_PROPERTIES_DATE_LEN		20
/*Object Properties*/

#define BRW_SELECT_MODE_IMAGE_PROP_COUNT	2

#define BRW_LAST_WEB_ADDR_LENGTH			NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE

#define BRW_USER_DEFINED_HOMEPAGE_LENGTH	NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE

#define BRW_BYTES_STRING					L" Bytes"

#define BRW_ZOOM_VAL_MIN					10

#define BRW_ZOOM_VAL_MAX					1000

#define BRW_MAX_CONTROL_BUFFER_SIZE			2048

/*this value is given by security layer and we cant change it directly from browser app
until & unless security layer first change its value*/
#define BRW_MAX_TRUSTED_CERTIFICATES		256

/* Typedefs */
typedef enum
{
    BRW_STATUS_FALSE = 0,
    BRW_STATUS_TRUE
} brw_status_enum;


typedef enum
{
    BRW_INLINE_TITLE_CAPTION,
    BRW_INLINE_TITLE,
    BRW_INLINE_ADDRESS_CAPTION,
    BRW_INLINE_URL
} brw_inline_item_display;

typedef enum
{
    BRW_AUTH_DLG_INLINE_USERNAME_CAPTION,
    BRW_AUTH_DLG_INLINE_USERNAME,
    BRW_AUTH_DLG_INLINE_PASSWORD_CAPTION,
    BRW_AUTH_DLG_INLINE_PASSWORD,
    BRW_AUTH_DLG_INLINE_SAVE_OPTION_CAPTION,
    BRW_AUTH_DLG_INLINE_SAVE_OPTION,
    BRW_AUTH_DLG_INLINE_TOTAL
} brw_auth_inline_item_display;

typedef enum
{
    BRW_PREFERENCES_INLINE_TIMEOUT_CAPTION = 0,
    BRW_PREFERENCES_INLINE_TIMEOUT_EDIT,
    BRW_PREFERENCES_INLINE_SHOW_IMAGES_CAPTION,
    BRW_PREFERENCES_INLINE_SHOW_IMAGES_SELECT,
	BRW_PREFERENCES_INLINE_SHOW_VIDEOS_CAPTION,
    BRW_PREFERENCES_INLINE_SHOW_VIDEOS_SELECT,
    BRW_PREFERENCES_INLINE_PLAY_SOUNDS_CAPTION,
    BRW_PREFERENCES_INLINE_PLAY_SOUNDS_SELECT,
    BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_CAPTION,
    BRW_PREFERENCES_INLINE_LOAD_UNKNOWN_MEDIA_SELECT,
    BRW_PREFERENCES_INLINE_CSS_CAPTION,
    BRW_PREFERENCES_INLINE_CSS_SELECT,
    BRW_PREFERENCES_INLINE_SCRIPT_CAPTION,
    BRW_PREFERENCES_INLINE_SCRIPT_SELECT,
    BRW_PREFERENCES_INLINE_CACHE_CAPTION,
    BRW_PREFERENCES_INLINE_CACHE_SELECT,
    BRW_PREFERENCES_INLINE_COOKIE_CAPTION,
    BRW_PREFERENCES_INLINE_COOKIE_SELECT
#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
    ,BRW_PREFERENCES_INLINE_SHORTCUTS_CAPTION
    ,BRW_PREFERENCES_INLINE_SHORTCUTS_SELECT
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
#ifdef  BRW_SECURITY_WARNINGS_SUPPORT
	,BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_CAPTION
    ,BRW_PREFERENCES_INLINE_SECURITY_WARNINGS_SELECT
#endif /* BRW_SECURITY_WARNINGS_SUPPORT */
#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
	,BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_CAPTION
    ,BRW_PREFERENCES_INLINE_SEND_DEVICE_ID_SELECT
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */

	,BROWSER_PREFERENCES_ITEM_COUNT
} brw_preferences_inline_item_display;

typedef enum
{
    BRW_STORED_PAGE_PROPERTIES_NAME_CAPTION = 0,
	BRW_STORED_PAGE_PROPERTIES_NAME_DISPLAY,
    BRW_STORED_PAGE_PROPERTIES_ADDRESS_CAPTION,
	BRW_STORED_PAGE_PROPERTIES_ADDRESS_DISPLAY,
    BRW_STORED_PAGE_PROPERTIES_SIZE_CAPTION,
	BRW_STORED_PAGE_PROPERTIES_SIZE_DISPLAY,
    BRW_STORED_PAGE_PROPERTIES_DATE_CAPTION,
	BRW_STORED_PAGE_PROPERTIES_DATE_DISPLAY
}brw_stored_page_properties_inline_enum;

typedef enum
{
    BRW_THIS_PAGE_PROPERTIES_NAME_CAPTION = 0,
	BRW_THIS_PAGE_PROPERTIES_NAME_DISPLAY,
    BRW_THIS_PAGE_PROPERTIES_ADDRESS_CAPTION,
	BRW_THIS_PAGE_PROPERTIES_ADDRESS_DISPLAY,
    BRW_THIS_PAGE_PROPERTIES_SIZE_CAPTION,
	BRW_THIS_PAGE_PROPERTIES_SIZE_DISPLAY
}brw_this_page_properties_inline_enum;


/* Page fetch event type */
typedef enum
{
    BRW_START_FETCH_EVENT,
    BRW_ACTION_EVENT
} brw_page_fetch_event;

/* Typedefs */
typedef enum
{
    BRW_OBJECT_PROP_NAME = 0,
    BRW_OBJECT_PROP_ADDRESS,
	BRW_OBJECT_PROP_SIZE,
	BRW_OBJECT_PROP_DATE,
	BRW_OBJECT_PROP_MAX_COUNT
} brw_obj_prop_enum;

typedef enum
{
    BRW_USER_DEFINED_HOMEPAGE = 0,
    BRW_ACTIVE_PROFILE_HOMEPAGE
} brw_homepage_settings_enum;


typedef enum
{
	BRW_PAGE_OBJECT_TYPE_IMAGE = 0,
    BRW_PAGE_OBJECT_TYPE_BG_IMAGE,
    BRW_PAGE_OBJECT_TYPE_SOUNDS,
	BRW_PAGE_OBJECT_TYPE_OTHERS
} brw_page_object_types_enum;

typedef enum
{
    BRW_PREF_OFF_INDEX = 0,
    BRW_PREF_ON_INDEX,
    BRW_PREF_ON_OFF_TOTAL
} brw_off_on_string_array_enum;

typedef enum
{
    BRW_PREF_NEVER_INDEX = 0,
    BRW_PREF_ALWAYS_INDEX,
    BRW_PREF_ALWAYS_NEVER_TOTAL
} brw_never_always_string_array_enum;

typedef enum
{
    BRW_PREF_DISABLE_INDEX = 0,
    BRW_PREF_ENABLE_INDEX,
    BRW_PREF_ENABLE_DISABLE_TOTAL
} brw_disable_enable_string_array_enum;

typedef enum
{
    BRW_AUTH_DLG_SAVE_NONE_INDEX = 0,
    BRW_AUTH_DLG_SAVE_BOTH_INDEX,
    BRW_AUTH_DLG_SAVE_USERNAME_INDEX,
    BRW_AUTH_DLG_SAVE_OPTION_TOTAL
} brw_auth_dialog_save_option_string_array_enum;

typedef enum
{
    BRW_LPD_NONE = 0,
    BRW_LPD_MAIN_MENU,
    BRW_LPD_EXTERNAL_LOAD_URL_REQ,
    BRW_LPD_EXTERNAL_LOAD_DATA_REQ,
    BRW_LPD_SETTINGS_PREF,
    BRW_LPD_ASM_TERMINATE,
    BRW_LPD_ACTIVE_PROFILE_CHANGED,
    BRW_LPD_RESTORE_BRW_SETTINGS
} brw_set_profile_launch_pad_enum;

#ifdef BAM_CFG_SUI_ZOOM_ENABLED
typedef enum
{
    BRW_FONT_SIZE_SMALL = 70,
    BRW_FONT_SIZE_MEDIUM = 100,
    BRW_FONT_SIZE_LARGE = 145
} brw_font_size_enum;
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */

typedef struct
{
    U8 *name;
	U8 *host;
    U32 type;
}brw_dynamic_list_struct;

typedef struct
{
	U16	actual_index;
}brw_recent_page_list_struct;

typedef struct
{
	U8  file_path[FMGR_MAX_PATH_LEN * ENCODING_LENGTH];
	S32 is_short;
}brw_file_detail_struct;

/* Browser Context Structure */
typedef struct
{
    brw_set_profile_launch_pad_enum brw_launching_pad;
    KAL_ADM_ID brw_adm_id;
    nvram_brw_hist_title_struct *address_list_title_p; /*it is saved as Ascii or Unicode in NVRAM depending on its content*/
    nvram_brw_hist_url_struct *address_list_url_p; /*it is saved as Ascii in NVRAM*/
    U8 total_bookmark_items;
    U8 total_address_list_items;
    U16 do_element_count;
	U16 top_scr_id;
    MMI_BOOL isWapReady;
    MMI_BOOL isBrowserFetching;
    MMI_BOOL isBrowserInstance;
    MMI_BOOL isDeleteInsReqPending;
    MMI_BOOL mainMenuEntryFlag;
    MMI_BOOL address_list_flag;
    MMI_BOOL reset_hiliter_flag;
	MMI_BOOL common_gateway_flag;
	MMI_BOOL security_dlg_flag;
    MMI_BOOL auth_dlg_flag;
	MMI_BOOL activate_java_flag;
    /*settings fields status*/
    U8 homepage_settings_index;
    U8 rendering_mode;
    U8 navigation_mode;
#ifdef BAM_CFG_SUI_ZOOM_ENABLED
    U8 font_size;
#endif /* BAM_CFG_SUI_ZOOM_ENABLED */
    U8 encoding_method_index;
    U8 sorting_method;
    U8 thumbnail_status;
    U8 screen_size_status;
    U8 show_images_status;
    U8 show_videos_status;
    U8 play_sounds_status;
    U8 load_unknown_media_status;
    U8 css_status;
    U8 script_status;
    U8 cache_status;
    U8 cookie_status;
#ifdef  BRW_KEYPAD_SHORTCUTS_SUPPORT
    U8 shortcuts_status;
#endif /* BRW_KEYPAD_SHORTCUTS_SUPPORT */
    U8 security_warnings_status;
#ifdef  BRW_SEND_DEVICE_ID_SUPPORT
    U8 send_device_id_status;
#endif /* BRW_SEND_DEVICE_ID_SUPPORT */
    U16 timeout_value;
    U8 user_defined_hmpage_url[BRW_USER_DEFINED_HOMEPAGE_LENGTH]; /*it is saved as Ascii in NVRAM*/
    U8 last_web_address[BRW_LAST_WEB_ADDR_LENGTH]; /*it is saved as Ascii in NVRAM*/
    /*settings fields status*/
    U8  selected_page_object_type;
    U32 index_highlighted_item;
    MMI_BOOL push_msg_rcvd_flag;
    MMI_BOOL select_mode_flag;
    MMI_BOOL brw_first_page_flag;
    U16 page_objs_images_count;
    U16 page_objs_bg_images_count;
    U16 page_objs_sounds_count;
    U16 page_objs_others_count;
    MMI_BOOL list_refresh_flag;
    //U8  session_info_str[BRW_SESSION_INFO_STR_LENGTH*ENCODING_LENGTH];
    wap_bam_show_auth_dialog_ind_struct* http_auth_info_p;
    U16	brw_instance_id;
    wps_show_confirm_dialog_ind_struct* sec_confirm_dlg_info_p;
    wps_sec_get_current_cert_rsp_struct* current_cert_p;
    wap_bam_status_ind_struct* brw_status_info_p;
    wap_bam_resource_item_struct* brw_res_item_info_p;
    U16 sap_msg_id;
    U16 sap_request_id;
    U32	dynamic_list_count;
    brw_dynamic_list_struct *dynamic_list;//name in UTF8 encoding*/
    wap_bam_do_element_t *do_element_list;
    wap_bam_document_info_ind_struct *document_info_p;
    wap_bam_element_focused_ind_struct *focused_element_info_p;
    U8** recent_page_host_list;//host name in UTF8 encoding*/
    U16 recent_page_count;
    U16 recent_page_host_count;
    S16 recent_page_host_delete_count;
    brw_recent_page_list_struct* recent_page_list;
    wap_bam_bearer_info_ind_struct* bearer_info_p;
    wap_bam_saved_page_struct* saved_page_properties_p;
    wap_bam_recent_page_struct* recent_page_info_p;
    bam_charset_name_id_t* charset_list_p;
	wap_bam_uri_request_ind_struct* uri_request_p;
#if defined (WAP_SEC_SUPPORT)
    wps_sec_get_session_info_rsp_struct* session_info_p;
    wps_sec_get_cert_ids_rsp_struct trusted_cert_ids;
    wps_sec_get_cert_rsp_struct* trusted_cert_list_p;
#endif /*WAP_SEC_SUPPORT*/
#ifdef BRW_BKGRD_DOWNLOAD_SUPPORT
	mmi_da_download_info_ind_struct* download_info_p;
#endif /*BRW_BKGRD_DOWNLOAD_SUPPORT*/
}brw_context_struct;


typedef struct
{
	U8  page_name[(BRW_MAX_TITLE_LENGTH+1) * ENCODING_LENGTH];
	U8  page_address[(BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH];
	U32 page_size;
	U8  page_date[BRW_STORED_PAGE_PROPERTIES_DATE_LEN];
}brw_stored_page_properties_context;


typedef struct
{
	U8	obj_name[(BRW_OBJECT_PROPERTIES_NAME_LEN+1)*ENCODING_LENGTH];
	U8	obj_address[(BRW_OBJECT_PROPERTIES_ADDRESS_LEN+1)*ENCODING_LENGTH];
	U8	obj_size[BRW_OBJECT_PROPERTIES_SIZE_LEN*ENCODING_LENGTH];
	U8	obj_date[BRW_OBJECT_PROPERTIES_DATE_LEN*ENCODING_LENGTH];
	U8	prop_status[BRW_OBJECT_PROP_MAX_COUNT];
	U8	prop_count;
}brw_object_properties_struct;


typedef struct
{
	U16	height;
	U16	width;
	U16	origin_X;
	U16	origin_Y;
}brw_rendering_area_struct;

typedef struct
{
	U16	res_list_index;
}brw_page_object_struct;


/*globa data*/
extern brw_context_struct g_brw_cntx;
extern U8 g_brw_current_url[(BRW_MAX_URL_LENGTH+1) * ENCODING_LENGTH];
extern U8 g_brw_current_title[(BRW_MAX_TITLE_LENGTH+1) * ENCODING_LENGTH];
extern U8 *g_brw_display_info_str;
extern brw_object_properties_struct g_brw_obj_properties_cntx;
extern MMI_BOOL g_brw_page_object_type[BRW_PAGE_OBJECT_TYPES_COUNT];
extern brw_page_object_struct g_brw_page_objs_image_list[BRW_PAGE_OBJECT_IMAGES_MAX];
extern brw_page_object_struct g_brw_page_objs_bg_image_list[BRW_PAGE_OBJECT_BG_IMAGES_MAX];
extern brw_page_object_struct g_brw_page_objs_sound_list[BRW_PAGE_OBJECT_SOUNDS_MAX];
extern brw_page_object_struct g_brw_page_objs_others_list[BRW_PAGE_OBJECT_OTHERS_MAX];
extern S32 g_brw_preferences[BROWSER_PREFERENCES_ITEM_COUNT];
extern S8 *gBrwOnOffStringArray[BRW_PREF_ON_OFF_TOTAL];
extern S8 *gBrwAlwaysNeverStringArray[BRW_PREF_ALWAYS_NEVER_TOTAL];
extern S8 *gBrwEnableDisableStringArray[BRW_PREF_ENABLE_DISABLE_TOTAL];
extern S8 *gBrwAuthDlgSaveOptionStringArray[BRW_AUTH_DLG_SAVE_OPTION_TOTAL];
extern U8 g_brw_auth_username[(WAP_BAM_MAX_USER_PASSWD_LENGTH+1) * ENCODING_LENGTH];
extern U8 g_brw_auth_password[(WAP_BAM_MAX_USER_PASSWD_LENGTH+1) * ENCODING_LENGTH];
extern U8 g_brw_phone_number[(BRW_WTAI_PHONE_NUMBER_LEN+1) * ENCODING_LENGTH];
extern U8 g_brw_hist_selected_title[(BRW_ADDRESS_LIST_TITLE_LENGTH) * ENCODING_LENGTH];
extern U8 g_brw_hist_selected_url[(BRW_ADDRESS_LIST_URL_LENGTH) * ENCODING_LENGTH];
extern U8 g_brw_auth_dlg_save_option;
extern U32 g_brw_memory_pool_size;
#ifdef APPMEM_SUPPORT
extern void* g_brw_memory_pool;
#else
extern U32 g_brw_memory_pool[BRW_ADM_MEMORY_POOL_SIZE / sizeof(U32)];
#endif /*APPMEM_SUPPORT*/
/*globa data*/

#endif /* __MMI_BROWSER_2__ */
#endif /* BROWSERTYPES_H */

