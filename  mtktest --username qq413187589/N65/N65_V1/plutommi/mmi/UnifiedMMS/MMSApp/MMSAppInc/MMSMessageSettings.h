/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSMessageSettings.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * MMSMessageSettings.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_UMMSMESSAGESETTINGS_H
#define __MMI_UMMSMESSAGESETTINGS_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "MMIDataType.h"

#include "gui_data_types.h"

/* 
 * Define
 */
#ifndef __MMI_MMS_OMA_CONF_273__
	#define __MMI_MMS_OMA_CONF_273__
#endif
#define __MMI_MMS_MEGA_PIXEL_SUPPORT__

#define UMMS_POPUP_TIME    UI_POPUP_NOTIFYDURATION_TIME_2000
#define UMMS_SIGNATURE_OBJECTS			3
#define UMMS_SIGNATURE_EXT_LENGTH		14
#define UMMS_MAX_NO_PAGES_INPUT          2
#define  UMMS_MAX_DEFAULT_SLIDE_TIME_INPUT  2 
#define UMMS_MAX_DEFAULT_SLIDE_TIME_DURATION 99
#define UMMS_MAX_AUTO_SIGN_LENGTH        128
#define  UMMS_MAX_DEADLINE_TIME_VALUE_INPUT 2
#define  UMMS_MAX_REPLY_CHARGE_SIZE_INPUT      3
#define  UMMS_MAX_FILTER_MSG_SIZE_INPUT     3
#define UMMS_MMI_INPROGRESS_TIME_OUT        (1000*(60*2))
#define UMMS_MAX_POSSIBLE_MESSAGES			(WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG -1)  //(100)
#define UMMS_MEMORY_STATUS_TEMP_BUF			(20)
#define UMMS_MEMORY_STATUS_MAX_LENGTH		(106)
#define UMMS_GOBACK_ONE_LEVEL			1

#define UMMS_MAX_POSSIBLE_SLIDES            20	/*(wap_custom_get_max_mms_slides())*/
#define UMMS_DEFAULT_SLIDE_DURATION                5000      /* /ms */
#define UMMS_DEFAULT_HOME_RETRIEVAL_MODE              E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE    /* /immedaite */
#ifdef __CMCC_RETRIVAL_MODE_SETTING__
#define UMMS_DEFAULT_ROAMING_RETRIEVAL_MODE         E_ROAMING_RETRIEVAL_IMMEDAITE
#else
#define UMMS_DEFAULT_ROAMING_RETRIEVAL_MODE         E_ROAMING_RETRIEVAL_AS_HOME
#endif
#define UMMS_DEFAULT_ADVERTISEMENT_FILTER_VALUE       E_ALLOW
#define UMMS_DEFAULT_ANONYMOUS_FILTER_VALUE        E_ALLOW
#define UMMS_DEFAULT_DELIVERY_REPORT_DURING_SENDING  E_OFF
#define UMMS_DEFAULT_READ_REPORT_DURING_SENDING       E_OFF
#define UMMS_DEFAULT_DELIVERY_REPORT_DURING_RETRIEVAL E_ON
#define UMMS_DEFAULT_READ_REPORT_DURING_RETRIEVAL     E_READ_REPORT_SEND_ON_REQUEST
#define UMMS_DEFAULT_PRIORITY						 MMA_PRIORITY_MEDIUM
#define UMMS_DEFAULT_EXPIRY_TIME						 MMA_EXPIRY_MAX
#define UMMS_DEFAULT_SENDER_VISIBILTY				E_OFF
#define UMMS_DEFAULT_DELIVERY_TIME					MMA_DELIVERY_IMMEDIATE

#define UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED	0x01
#define UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED	0x02
#define UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED	0x04
#define UMMS_COMPOSE_SIGNATURE_TEXT_ADDED	0x08
#define UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED	0x10 
//#ifndef __MMI_MMS_OMA_CONF_273__
//#define __MMI_MMS_OMA_CONF_273__
//#endif 
/* 
 * Typedef 
 */
typedef enum
{
	AUDIO_EXT =0,
	IMAGE_EXT,
	VIDEO_EXT,
	TOTAL_EXT
}umms_object_ext;

typedef enum
{
    E_USE_NVRAM_SETTINGS = 1,
    E_USE_LOCAL_SETTINGS,
	E_USE_TOTAL
} umms_use_settings_enum;

typedef enum
{
    E_IMMEDIATE,
    E_1_HR,
    E_12_HRS,
    E_24_HRS,
    DELIEVERY_TOTAL
} umms_delievery_time_enum;

typedef enum
{
    E_OFF,
    E_ON,
	E_ON_OFF_NONE
} umms_off_on_enum;

typedef enum
{
    E_ALLOW,
    E_REJECT,
	E_ALLOW_REJECT_NONE
} umms_allow_reject_enum;

typedef enum
{
    E_PRIORITY_LOW,
    E_PRIORITY_NORMAL,
    E_PRIORITY_HIGH,
    PRIORITY_TOTAL
} umms_priority_enum;

typedef enum
{
    E_VALIDITY_PERIOD_MAX,
    E_VALIDITY_PERIOD_1HR,
	E_VALIDITY_PERIOD_6HRS,
    E_VALIDITY_PERIOD_12HRS,
    E_VALIDITY_PERIOD_1DAY,
    E_VALIDITY_PERIOD_1WEEK,
    VALIDITY_PERIOD_TOTAL
} umms_validity_period_enum;

typedef enum
{
    E_CREAT_MODE_RESTRICTED,
#ifdef __MMS_CREATION_MODE_SUPPORTED__
    E_CREAT_MODE_WARNING,
#endif
    E_CREAT_MODE_FREE,
    CREATION_MODES_TOTAL
} umms_creation_modes_enum;

typedef enum
{
    E_MMS_LAYOUT_POTRAIT,
    E_MMS_LAYOUT_LANDSCAPE,
    LAYOUT_TOTAL
} umms_layout_enum;

typedef enum
{
    E_IMAGE_RESIZE_OFF,
    E_IMAGE_RESIZE_160x120,
    E_IMAGE_RESIZE_320x240,
    E_IMAGE_RESIZE_640x480,
    IMAGE_RESIZE_TOTAL
} umms_image_resize_enum;

typedef enum
{
    E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE = 0x01, /* to match with raoming retrioeve modes */
    E_HOME_NOETWORK_RETRIEVAL_DEFFERED,
    E_HOME_NOETWORK_RETRIEVAL_RESTRICTED,
    HOME_NETWORK_TOTAL
} umms_home_network_retrieval_enum;

typedef enum
{
    E_ROAMING_RETRIEVAL_AS_HOME,
    E_ROAMING_RETRIEVAL_IMMEDAITE,
    E_ROAMING_RETRIEVAL_DEFFERED,
    E_ROAMING_RETRIEVAL_RESTRICTED,
    ROAMING_TOTAL
} umms_roaming_retrieval_enum;

typedef enum
{
    E_READ_REPORT_SEND_ON_REQUEST,
    E_READ_REPORT_SEND_ALWAYS,
    E_READ_REPORT_SEND_NEVER,
    READ_REPORT_SEND_TOTAL
} umms_read_report_enum;

typedef enum
{
    E_FULL_MMS,
    E_TEXT_ONLY,
    REPLY_CHARGING_TYPE_TOTAL
} umms_reply_charging_type_enum;

typedef enum
{
    E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION,
    E_COMPOSE_DEFAULT_SLIDE_TIME,
#ifdef __LAYOUT_SUPPORT__
    E_COMPOSE_LAYOUT_CAPTION,
    E_COMPOSE_LAYOUT,
#endif
#ifdef __DRM_SUPPORT__
#ifdef __UMMS_DRM_SUPPORT__
    E_COMPOSE_ADD_DRM_CAPTION,
    E_COMPOSE_ADD_DRM,
#endif
#endif /* __DRM_SUPPORT__ */ 
    E_COMPOSE_CREATION_MODES_CAPTION,
    E_COMPOSE_CREATION_MODES,
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
	E_COMPOSE_IMAGE_RESIZE_CAPTION,
	E_COMPOSE_IMAGE_RESIZING,
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ /* ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__ */
#ifdef __MAX_PAGE_SUPPORTED__
    E_COMPOSE_MAX_NO_PAGES_CAPTION,
    E_COMPOSE_MAX_NO_PAGES,
#endif
    E_COMPOSE_BEST_PAGE_DURATION_CAPTION,
    E_COMPOSE_BEST_PAGE_DURATION,
    /* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
    E_COMPOSE_AUTO_SIGNATURE_CAPTION,
    E_COMPOSE_AUTO_SIGNATURE,
    E_COMPOSE_AUTO_SIGNATURE_CONTENT,
#endif /* __MMI_MMS_SIGNATURE__ */ 
    /* PMT VIKAS END 20060403 */
    COMPOSE_INLINE_TOTAL
} umms_compose_inline_items_enum;

typedef enum
{
    E_COMPOSE_SIGNATURE_TEXT_CAPTION,
    E_COMPOSE_SIGNATURE_TEXT,

    E_COMPOSE_SIGNATURE_IMAGE_CAPTION,
    E_COMPOSE_SIGNATURE_IMAGE,

    E_COMPOSE_SIGNATURE_VIDEO_CAPTION,
    E_COMPOSE_SIGNATURE_VIDEO,

    E_COMPOSE_SIGNATURE_AUDIO_CAPTION,
    E_COMPOSE_SIGNATURE_AUDIO,

    COMPOSE_SIGNATURE_INLINE_TOTAL
} umms_compose_signature_inline_items_enum;

typedef enum
{
    E_SENDING_VALIDITY_PERIOD_CAPTION,
    E_SENDING_VALIDITY_PERIOD,
    E_SENDING_DELIVERY_REPORT_CAPTION,
    E_SENDING_DELIVERY_REPORT,
    E_SENDING_READ_REPORT_CAPTION,
    E_SENDING_READ_REPORT,
    E_SENDING_PRIORITY_CAPTION,
    E_SENDING_PRIORITY,
    E_SENDING_DELIVERY_TIME_CAPTION,
    E_SENDING_DELIVERY_TIME,
    E_SENDING_HIDE_SENDER_CAPTION,
    E_SENDING_HIDE_SENDER,
	E_SENDING_SEND_AND_SAVE_CAPTION,
	E_SENDING_SEND_AND_SAVE,
    E_SENDING_REPLY_CHARGING_CAPTION,
    E_SENDING_REPLY_CHARGING,
    SENDING_INLINE_TOTAL
} umms_sending_inline_items_enum;

typedef enum
{
    E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION,
    E_SENDING_REPLY_CHARGING_REQUEST_TYPE,
    E_SENDING_REPLY_CHARGING_DEADLINE_CAPTION,
    E_SENDING_REPLY_CHARGING_DEADLINE,
    E_SENDING_REPLY_CHARGING_SIZE_CAPTION,
    E_SENDING_REPLY_CHARGING_SIZE,
    SENDING_REPLY_CHARGING_INLINE_TOTAL
} umms_sending_reply_charging_inline_items_enum;

typedef enum
{

#ifdef __CMCC_RETRIVAL_MODE_SETTING__
   E_RETRIEVAL_ROAMING_CAPTION,
   E_RETRIEVAL_ROAMING,
#else
    E_RETRIEVAL_HOME_NETWORK_CAPTION,
    E_RETRIEVAL_HOME_NETWORK,
    E_RETRIEVAL_ROAMING_CAPTION,
    E_RETRIEVAL_ROAMING,
#endif
    
    E_RETRIEVAL_FILTERS_CAPTION,
    E_RETRIEVAL_READ_REPORT_CAPTION,
    E_RETRIEVAL_READ_REPORT,
    E_RETRIEVAL_DELIVERY_REPORT_CAPTION,
    E_RETRIEVAL_DELIVERY_REPORT,
    RETRIEVAL_INLINE_TOTAL
} umms_retrieval_inline_items_enum;

typedef enum
{
    E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION,
    E_RETRIEVAL_FILTERS_ANONYMOUS,
#ifndef __MMI_MMS_OMA_CONF_273__
    E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION,
    E_RETRIEVAL_FILTERS_MAX_MSG_SIZE,
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION,
    E_RETRIEVAL_FILTERS_ADVERTISEMENT,
    RETRIEVAL_FILTER_INLINE_TOTAL
} umms_retrieval_filters_inline_items_enum;

typedef enum
{
    E_ENTRY_FROM_MMS_SETTINGS,
    E_ENTRY_FROM_WRITE_MMS
} umms_send_settings_entry_control_enum;

typedef struct
{
    U8 layout;
#ifdef __DRM_SUPPORT__
    U8 add_drm;
#endif 
    U8 creation_mode;
	U8 image_resize_option;
    U8 max_no_pages;
    U8 best_page_duration;
    /* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
    U8 auto_signature;
    U8 auto_signature_content[(UMMS_MAX_AUTO_SIGN_LENGTH + 1) *ENCODING_LENGTH];
	U8 auto_signature_image_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	U8 auto_signature_audio_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	U8 auto_signature_video_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];

#endif /* __MMI_MMS_SIGNATURE__ */ 
    /* PMT VIKAS END 20060403 */
    U32 default_slide_time;
} umms_nvram_compose_settings_struct;

typedef struct
{
    U8 validity_period;
    U8 delivery_report;
    U8 read_report;
    U8 priority;
    U8 delivery_time;
    U8 reply_charging;
    U8 request_type;
    U8 hide_sender;
	U32 send_and_save;
    U32 deadline_for_reply;
    U32 size;
} umms_nvram_sending_settings_struct;

/* typedef struct
   {
   S32      home_network;
   S32      roaming;
   S32      anonymous_filter;
   U32      msgsize_filter;
   S32      advertisement_filter;
   S32      read_report;
   S32      delivery_report;
   }jmms_retrieval_settings_struct; */

typedef struct
{
    U8 home_network;
    U8 roaming;
    U8 anonymous_filter;
    U8 advertisement_filter;
    U8 read_report;
    U8 delivery_report;
    U16 msgsize_filter;
} umms_retrieval_settings_struct;

typedef struct
{
    S8 *allow_reject_list[2];
    S8 *on_off_list[2];
} umms_common_inline_lists_struct;

typedef struct
{
    S32 home_network;
    S32 roaming;
    S32 anonymous_filter;
    S32 advertisement_filter;
    S32 read_report;
    S32 delivery_report;

    S8 *home_network_list[HOME_NETWORK_TOTAL - 1];
    S8 *roaming_list[ROAMING_TOTAL];
    S8 *read_report_list[READ_REPORT_SEND_TOTAL];
    U8 msg_size_filter_buffer[(UMMS_MAX_FILTER_MSG_SIZE_INPUT + 1) *ENCODING_LENGTH];
} umms_inline_retrieval_items_struct;

typedef struct
{
    /* /new */
    S32 validity_period;
    S32 delivery_report;
    S32 read_report;
    S32 priority;
    S32 delivery_time;
    S32 reply_charging;
    S32 request_type;
    S32 hide_sender;
	S32 send_and_save;
    S8 *validity_period_list[VALIDITY_PERIOD_TOTAL];
    S8 *priority_list[PRIORITY_TOTAL];
    S8 *delivery_time_list[DELIEVERY_TOTAL];
    S8 *reply_charging_request_list[REPLY_CHARGING_TYPE_TOTAL];
    U8 deadline_for_reply_buffer[(UMMS_MAX_DEADLINE_TIME_VALUE_INPUT + 1) *ENCODING_LENGTH];
    U8 reply_msg_size_buffer[(UMMS_MAX_REPLY_CHARGE_SIZE_INPUT + 1) *ENCODING_LENGTH];
} umms_inline_sending_items_struct;
typedef struct
{
    U8 max_num_pages_buffer[(UMMS_MAX_NO_PAGES_INPUT + 1) *ENCODING_LENGTH];
    U8 defualt_slide_time_buffer[(UMMS_MAX_DEFAULT_SLIDE_TIME_INPUT + 1) *ENCODING_LENGTH];
    S32 layout;
#ifdef __DRM_SUPPORT__
    S32 add_drm;
#endif 
    S32 creation_mode;
	S32 image_resize_option;
    S32 best_page_duration;
    /* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
    S32 auto_signature;
	U8									signature_flag;
#endif 
    /* PMT VIKAS END 20060403 */
    S8 *layout_list[LAYOUT_TOTAL];
    S8 *creation_modes_list[CREATION_MODES_TOTAL];
	S8 *image_resize_list[IMAGE_RESIZE_TOTAL];
    U8 auto_signature_content[(UMMS_MAX_AUTO_SIGN_LENGTH + 1) *ENCODING_LENGTH];
	U8 auto_signature_image_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	U8 auto_signature_audio_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	U8 auto_signature_video_file[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
} umms_inline_compose_items_struct;

typedef union
{
    umms_inline_compose_items_struct		compose_items_list;
    umms_inline_sending_items_struct		sending_items_list;
    umms_inline_retrieval_items_struct		retrieval_items_list;
} umms_setings_inline_items_union;

typedef struct
{	
	FS_HANDLE							file_handle;
	U32									request_id;
	U8									file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) * ENCODING_LENGTH];
	U8*									msg_path;
	U8									buffer_index;
	U32									xml_file_size;
	U32									msg_id;
}umms_setting_create_mms_struct;

typedef struct
{	
	umms_common_inline_lists_struct		*umms_inline_lists;
	umms_setings_inline_items_union		umms_inline_items;
    umms_nvram_compose_settings_struct	nvram_compose_settings;
    umms_nvram_sending_settings_struct	nvram_sending_settings;
    umms_retrieval_settings_struct		nvram_retrieval_settings;
	umms_setting_create_mms_struct		default_mms_creation;
	BOOL								default_creation_progress;
	S32									state;
	U32									request_id;
	U32									msg_id;
	U32									msg_list_index;
	U16									RSK_str_id;
	U16									body_str_id;
	U16									caption_str_id;
	U16									animation_image_id;
	U8									on_bootup;
	U8									current_msg_index;
}umms_context_struct;

typedef struct
{
	U32			used_size;
    U32			free_size;
	U16			total_mms;

}umms_memory_status_struct;

/* 
 * Extern Global Variable
 */
/* 
 * Extern Global Function
 */

/* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
extern void mmi_jmms_auto_signature_highlight_hdlr(S32 index);
#endif 
/* PMT VIKAS END 20060403 */
extern void mmi_umms_compose_settings_highlight_hdlr(S32 index);
extern void mmi_umms_entry_compose_signature_settings(void);
extern void mmi_umms_entry_compose_signature_settings(void);
extern void mmi_umms_signature_done_handler(void);
extern void mmi_umms_compose_signature_fill_inline_struct(void);
extern void mmi_umms_exit_compose_signature_settings(void);
extern void mmi_umms_compose_settings_signature_highlight_hdlr(S32 index);
extern void mmi_umms_compose_image_select_from_file_manager(void);
extern void mmi_umms_compose_image_select_path_from_file_manager(void *path, int is_short);
extern BOOL mmi_umms_compose_image_check_valid_image(S8 *path);
extern void mmi_umms_image_preview_callback(S32 result);
extern void mmi_umms_image_select_from_file_manager_done(void);
extern void mmi_umms_highlight_select_signature(void);
extern void mmi_umms_highlight_delete_signature(void);
extern void mmi_umms_highlight_view_signature(void);
extern void mmi_umms_compose_signature_pre_option_menu(void);
extern void mmi_umms_compose_exit_image_option(void);
extern void mmi_umms_compose_entry_signature_option(BOOL file_selected);
extern void mmi_umms_pre_entry_compose_image_view(void);
extern void mmi_umms_pre_entry_compose_reference_delete(void);
extern void mmi_umms_compose_select_from_file_manager(void);
extern void mmi_umms_compose_video_select_from_file_mamager(void);
//extern BOOL mmi_umms_composer_check_data_space(S8 *path);
extern void mmi_umms_compose_video_select_path_from_file_manager(void *path, int is_short);
extern void mmi_umms_compose_video_select_from_file_manager(void);
extern void mmi_umms_compose_audio_select_path_from_file_manager(void *path, int is_short);
extern void mmi_umms_compose_audio_select_from_file_manager(void);
extern void mmi_umms_check_signature_files(void);
extern void mmi_umms_update_file_information(void);


extern void mmi_umms_highlight_memory_status(void);
extern void mmi_umms_highlight_edit_profile(void);
extern void mmi_umms_highlight_retrieval_setings(void);
extern void mmi_umms_highlight_sending_setings(void);
extern void mmi_umms_highlight_compose_setings(void);
extern void mmi_umms_pre_entry_profile_settings(void);
extern void mmi_umms_entry_message_settings(void);
extern void mmi_umms_pre_entry_sending_settings(void);
extern void mmi_umms_pre_entry_retrieval_settings(void);
extern void mmi_umms_pre_entry_compose_settings(void);
extern void mmi_umms_read_nvram_message_settings(void);
extern void mmi_umms_message_settings_init(void);
extern void mmi_umms_entry_compose_settings(void);
extern void mmi_umms_exit_compose_settings(void);
extern void mmi_umms_compose_fill_inline_struct(void);
extern void mmi_umms_save_compose_settings(void);
extern void mmi_umms_confirm_save_compose_settings(void);
extern void mmi_umms_exit_confirm_screen(void);
extern void mmi_umms_read_back_auto_sign_content(void);
extern void mmi_umms_compose_inline_custom_func(void);
extern void mmi_umms_check_sending_settings_control(U8 control);
extern void mmi_umms_entry_sending_settings(void);
extern void mmi_umms_exit_sending_settings(void);
extern void mmi_umms_sending_fill_inline_struct(void);
extern void mmi_umms_reply_charging_highlight_hdlr(S32 index);
extern void mmi_umms_confirm_save_sending_settings(void);
extern void mmi_umms_sending_reply_charging_settings_done(void);
extern void mmi_umms_pre_entry_sending_reply_charging_settings(void);
extern void mmi_umms_save_sending_settings(void);
extern void mmi_umms_entry_sending_reply_charging_settings(void);
extern void mmi_umms_sending_reply_charging_fill_inline_struct(void);
extern void mmi_umms_exit_sending_reply_charging_settings(void);
extern void mmi_umms_sending_settings_highlight_hdlr(S32 index);
extern void mmi_umms_entry_retrieval_settings(void);
extern void mmi_umms_confirm_save_retrieval_settings(void);
extern void mmi_umms_save_retrieval_settings(void);
extern void mmi_umms_retrieval_fill_inline_struct(void);
extern void mmi_umms_retrieval_settings_highlight_hdlr(S32 index);
extern void mmi_umms_exit_retrieval_settings(void);
extern void mmi_umms_retrieval_filters_fill_inline_struct(void);
extern void mmi_umms_exit_retrieval_filters_settings(void);
extern void mmi_umms_entry_retrieval_filters_settings(void);
extern void mmi_umms_filter_done_handler(void);
extern void mmi_umms_restore_nvram_default_settings(void);
extern void mmi_umms_set_setting_to_mma_req(void);
extern void mmi_umms_entry_processing_generic(void);
extern void mmi_umms_time_out_processing_generic(void);
extern void mmi_umms_exit_processing_generic(void);
extern void mmi_umms_set_processing_screen(U16 captionStrId, U16 bodyStrId, U16 animationImageId, U16 rskStrId);
extern void mmi_umms_set_setting_to_mma_req(void);
extern void mmi_umms_set_setting_rsp(void* InMsg);
extern void mmi_umms_pre_entry_memory_status(void);
extern void mmi_umms_get_setting_memory_status_req(void);
extern void mmi_umms_get_memory_status_rsp(void *inMsg);
extern void mmi_umms_get_total_mms_num_req(void );
extern void mmi_umms_total_mms_num_rsp(void *inMsg);
extern void mmi_umms_entry_memory_status_screen(void);
extern void mmi_umms_set_current_mms_profile(BOOL boot_up);
extern void mmi_umms_set_current_profile_req(void);
extern void mmi_umms_set_current_profile_rsp(void* InMsg);
extern void mmi_umms_progress_screen_end_key_hdlr(void);
extern void mmi_umms_fill_settings_for_mma(wap_mma_set_setting_req_struct *msgSet);
extern BOOL mmi_umms_composer_check_data_space(S8* path, U8 object_type);
extern BOOL mmi_umms_check_media_validity(S8* filepath, U8 object_type);
extern mma_drm_type_enum wap_mma_umms_check_signature_drm_type(const kal_wchar *filepath);
extern S32 mmi_umms_check_resize(U8 *filePath);
extern void mmi_umms_make_file_name(S8* file_name, S8* file_ext);


#endif /* __MMI_MMS_2__ */
#endif /* __MMI_UMMSMESSAGESETTINGS_H */ 

