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

#ifndef _mmsadp_h
#define _mmsadp_h

#ifndef _KAL_RELEASE_H
#error "Please include kal_release.h first"
#endif


#if defined(JATAAYU_SUPPORT)
#include "JMMSUCHandlingGDefs.h"
#include "custom_wap_config.h"
#endif

/**********************************************************************
 * ENUM definition
 **********************************************************************/
typedef enum
{
    MMA_MODE_EDIT,        /* XML[O]: Header+body (already adjusted for UC) */
    MMA_MODE_SEND,        /* XML[O]: Header+body; XML[I]: Header (already adjusted for UC) */
    MMA_MODE_REPLY,       /* XML[I/O]: Header (already adjusted for UC) */
    MMA_MODE_REPLY_ALL,   /* XML[I/O]: Header (already adjusted for UC) */
    MMA_MODE_FORWARD,     /* XML[O]: Header+body; XML[I]: Header (already adjusted for UC) */
    MMA_MODE_UPLOAD,
    MMA_MODE_HEADER,      /* XML[O]: Header */
    MMA_MODE_VIEW,        /* XML[O]: Header+body */
    MMA_MODE_RAW,         /* XML[I/O]: Header+body (RAW)*/
    MMA_MODE_INT_PARSE
}mma_app_mode_enum;

typedef enum
{
    MMA_RESULT_OK,                              /* 0 */
    MMA_RESULT_DELAYED,                         /* 1 */
    MMA_RESULT_CONTINUE,                        /* 2 */
    MMA_RESULT_FAIL,                            /* 3 */
    MMA_RESULT_FAIL_IN_CALL,                    /* 4 */
    MMA_RESULT_FAIL_NOT_READY,                  /* 5 */
    MMA_RESULT_FAIL_BUSY,                       /* 6 */
    MMA_RESULT_FAIL_INSUFFICIENT_MEMORY,        /* 7 */
    MMA_RESULT_FAIL_INSUFFICIENT_STORAGE,       /* 8 */
    MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED,        /* 9 */
    MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED,       /* 10 */
    MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED,      /* 11 */
    MMA_RESULT_FAIL_MAX_ATTACHMENT_NUM_REACHED, /* 12 */
    MMA_RESULT_FAIL_FILE_EMPTY,                 /* 13 */
    MMA_RESULT_FAIL_FILE_NOT_FOUND,             /* 14 */
    MMA_RESULT_FAIL_FILE_CORRUPTED,             /* 15 */
    MMA_RESULT_FAIL_FILE_IN_USE,                /* 16 */
    MMA_RESULT_FAIL_FILE_IO,                    /* 17 */
    MMA_RESULT_FAIL_FOLDER_NOT_FOUND,           /* 18 */
    MMA_RESULT_FAIL_UNSUPPORT_CONTENT,          /* 19 */
    MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT,     /* 20 */
    MMA_RESULT_FAIL_COMM_CONFIG_ERROR,          /* 21 */
    MMA_RESULT_FAIL_COMM_CONNECT_ERROR,         /* 22 */
    MMA_RESULT_FAIL_COMM_SERVER_ERROR,          /* 23 */
    MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT,        /* 24 */
    MMA_RESULT_FAIL_COMM_SERVICE_DENIED,        /* 25 */
    MMA_RESULT_FAIL_COMM_UNKNOWN_APN,           /* 26 */
    MMA_RESULT_FAIL_COMM_UNAUTHORIZED,          /* 27 */
    MMA_RESULT_FAIL_USER_CANCEL,                /* 28 */
    MMA_RESULT_FAIL_INVALID_PARAMETER,          /* 29 */
    MMA_RESULT_FAIL_INVALID_MSGID,              /* 30 */
    MMA_RESULT_FAIL_INVALID_FOLDER,             /* 31 */
    MMA_RESULT_FAIL_QUEUE_FULL,                 /* 32 */
    MMA_RESULT_FAIL_PARSE,                      /* 33 */
    MMA_RESULT_FAIL_MSGID_IS_USING,             /* 34 */
    MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED,    /* 35 */
    MMA_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM,         /* 36 */
    MMA_RESULT_FAIL_IN_USB_MODE,                /* 37 */
    MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE,    /* 38 */
    MMA_RESULT_FAIL_TERMINATING,                /* 39 */
    MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL,      /* 40 */
    MMA_RESULT_OK_WITH_WARNING_CONTENT,
    MMA_RESULT_END                          
}mma_result_enum;

typedef enum
{
    MMA_FOLDER_NONE = 0x0,
    MMA_FOLDER_INBOX = 0x1,
    MMA_FOLDER_OUTBOX = 0x2,
    MMA_FOLDER_SENT = 0x4,
    MMA_FOLDER_DRAFT = 0x8,
    MMA_FOLDER_TEMPLATE = 0x10,
    MMA_FOLDER_USRDEF_TEMPLATE = 0x20,
    MMA_FOLDER_ARCHIVE = 0x40
}mma_folder_enum;

typedef enum
{
    MMA_CREATION_MODE_FREE,
    MMA_CREATION_MODE_RESTRICTED,
    MMA_CREATION_MODE_WARNING
}mma_creation_mode_enum;

typedef enum
{
    MMA_PRIORITY_NOT_SET,
    MMA_PRIORITY_LOW,
    MMA_PRIORITY_MEDIUM,
    MMA_PRIORITY_HIGH
}mma_priority_enum;

#if defined(OBIGO_Q05A)
typedef enum
{
    MMA_EXPIRY_NOT_SET = 0,
    MMA_EXPIRY_1_HOUR = 3600,
    MMA_EXPIRY_6_HOURS = 21600,
    MMA_EXPIRY_12_HOURS = 43200,
    MMA_EXPIRY_1_DAY = 86400,
    MMA_EXPIRY_1_WEEK = 604800,
    MMA_EXPIRY_MAX = 0
}mma_expiry_time_enum;

typedef enum
{
    MMA_DELIVERY_NOT_SET = 0,
    MMA_DELIVERY_IMMEDIATE = 0,
    MMA_DELIVERY_1_HOUR = 3600,
    MMA_DELIVERY_12_HOURS = 43200,
    MMA_DELIVERY_24_HOURS = 86400
}mma_delivery_time_enum;
#else
typedef enum
{
    MMA_EXPIRY_NOT_SET,
    MMA_EXPIRY_1_HOUR,
    MMA_EXPIRY_6_HOURS,
    MMA_EXPIRY_12_HOURS,
    MMA_EXPIRY_1_DAY,
    MMA_EXPIRY_1_WEEK,
    MMA_EXPIRY_MAX
}mma_expiry_time_enum;

typedef enum
{
    MMA_DELIVERY_NOT_SET,
    MMA_DELIVERY_IMMEDIATE,
    MMA_DELIVERY_1_HOUR,
    MMA_DELIVERY_12_HOURS,
    MMA_DELIVERY_24_HOURS
}mma_delivery_time_enum;
#endif /* OBIGO_Q05A */

typedef enum
{
    MMA_HEADER_UNKNOWN,
    MMA_HEADER_ADDRESS,
    MMA_HEADER_SUBJECT
}mma_header_attr_enum;

typedef enum
{
    MMA_INSERT_UNKNOWN,
    MMA_INSERT_TEXT,
    MMA_INSERT_IMAGE,
    MMA_INSERT_AUDIO,
    MMA_INSERT_VIDEO,
    MMA_INSERT_ATTACHMENT
}mma_insert_type_enum;

typedef enum
{
    MMA_DRM_NONE,
    MMA_DRM_FL_CD,  /* forward-lock or combined delivery */
    MMA_DRM_SD,     /* seperate-delivery */
    MMA_DRM_SD_NO_RIGHT
}mma_drm_type_enum;

typedef enum
{
    MMA_LAYOUT_NONE,
    MMA_LAYOUT_IMAGE_ON_TOP,
    MMA_LAYOUT_TEXT_ON_TOP
}mma_slide_layout_enum;

typedef enum
{
    MMA_CONN_TYPE_HTTP_PROXY,
    MMA_CONN_TYPE_HTTP_DIRECT,
    MMA_CONN_TYPE_WSP_CL,
    MMA_CONN_TYPE_WSP_CO,
    MMA_CONN_TYPE_WSP_SEC_CL,
    MMA_CONN_TYPE_WSP_SEC_CO
}mma_connection_type_enum;

typedef enum
{
    MMA_TEXT_STYLE_BOLD = 0x01,
    MMA_TEXT_STYLE_ITALIC = 0x02
}mma_text_style_enum;

typedef enum
{
    MMA_TEXT_SIZE_SMALL = 1,
    MMA_TEXT_SIZE_MEDIUM,
    MMA_TEXT_SIZE_LARGE
}mma_text_size_enum;

typedef enum
{
    MMA_ADDR_TYPE_NONE,
    MMA_ADDR_TYPE_PHONE_NUMBER,
    MMA_ADDR_TYPE_EMAIL
}mma_addr_type_enum;

typedef enum
{
    MMA_MSG_CLASS_PERSONAL,
    MMA_MSG_CLASS_ADVERTISEMENT,
    MMA_MSG_CLASS_INFORMATIONAL,
    MMA_MSG_CLASS_AUTO
}mma_msg_class_enum;

typedef enum
{
    MMA_MSG_TYPE_NOTIFICATION,
    MMA_MSG_TYPE_DELIVERY_REPORT,
    MMA_MSG_TYPE_READ_REPORT,
    MMA_MSG_TYPE_MMS,
    MMA_MSG_TYPE_JAVA,
    MMA_MSG_TYPE_TEMPLATE
}mma_msg_type_enum;

typedef enum
{
    MMA_MSG_STATUS_WAITING_SENDING,
    MMA_MSG_STATUS_SENDING,    
    MMA_MSG_STATUS_WAITING_DOWNLOADING,
    MMA_MSG_STATUS_DOWNLOADING,
    MMA_MSG_STATUS_NORMAL,    
    MMA_MSG_STATUS_FAILED
}mma_msg_status_enum;

typedef enum
{
    MMA_RETRIEVAL_MODE_IMMED,
    MMA_RETRIEVAL_MODE_DEFERRED,
    MMA_RETRIEVAL_MODE_REJECT,
    MMA_RETRIEVAL_MODE_AS_HOME
}mma_retrieval_mode_enum;

typedef enum
{
    MMA_DR_STATUS_EXPIRED = 0x80,
    MMA_DR_STATUS_RETRIEVED = 0x81,
    MMA_DR_STATUS_REJECTED = 0x82,
    MMA_DR_STATUS_DEFERRED = 0x83,
    MMA_DR_STATUS_UNRECOGNISED = 0x84,
    MMA_DR_STATUS_INDETERMINATE = 0x85,
    MMA_DR_STATUS_FORWARDED = 0x86,
    MMA_DR_STATUS_UNREACHABLE = 0x87
}mma_dr_status_enum;

typedef enum
{
    MMA_RR_STATUS_READ = 0x80,
    MMA_RR_STATUS_DELETED_NO_READ = 0x81
}mma_rr_status_enum;

typedef enum
{
    MMA_VERSION_10 = 0x10,
    MMA_VERSION_11 = 0x11,
    MMA_VERSION_12 = 0x12
}mma_version_enum;

typedef enum
{
    MMA_REGION_FIT_NONE,
    MMA_REGION_FIT_MEET,
    MMA_REGION_FIT_SCROLL,
    MMA_REGION_FIT_HIDDEN,
    MMA_REGION_FIT_FILL,
    MMA_REGION_FIT_SLICE
}mma_region_fit_enum;

typedef enum
{
    MMA_CHARSET_UNKNOWN = 0,
    MMA_CHARSET_ASCII = 3,
    MMA_CHARSET_ISO_8859_1 = 4,
    MMA_CHARSET_UTF8 = 106,
    MMA_CHARSET_UCS2 = 1000,
    MMA_CHARSET_UTF16BE = 1013,
    MMA_CHARSET_UTF16LE = 1014,
    MMA_CHARSET_UTF16 = 1015
}mma_charset_enum;

typedef enum
{
    MMA_UC_FILTER_MODE_AUDIO_OPEN_MODE, /*audio type when creation mode is free*/
    MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE, /*image type when creation mode is free*/
    MMA_UC_FILTER_MODE_TEXT_OPEN_MODE, /*text type when creation mode is free*/
    MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE, /*video type when creation mode is free*/    
    MMA_UC_FILTER_MODE_ATTACHMENT_OPEN_MODE, /*image type when creation mode is free*/
    MMA_UC_FILTER_MODE_AUDIO_RESTRICTED_MODE, /*audio type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_IMAGE_RESTRICTED_MODE, /*image type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_TEXT_RESTRICTED_MODE, /*text type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_VIDEO_RESTRICTED_MODE, /*video type when creation mode is restricted*/
    MMA_UC_FILTER_MODE_ATTACHMENT_RESTRICTED_MODE /*image type when creation mode is restricted*/
}mma_uc_filter_mode_enum;
/**********************************************************************
 * Structure definition
 **********************************************************************/
typedef struct
{
    kal_bool result;
    kal_bool oversize;
    kal_bool creation_mode_violate;
    mma_result_enum detail_result;  /* to replace result and oversize */
    mma_insert_type_enum insert_type;
    mma_drm_type_enum drm_type;
}mma_insert_check_struct;

typedef struct
{
    mma_result_enum result;
    mma_app_mode_enum mode;
}mma_uc_start_rsp_struct;

/**********************************************************************
 * Function declarations
 **********************************************************************/
extern mma_drm_type_enum wap_mma_umms_check_signature_drm_type(const kal_wchar *filepath);
extern kal_uint32 wap_mma_uc_calc_header_attribute_size(mma_header_attr_enum attr, const kal_wchar *data);
extern kal_uint32 wap_mma_uc_calc_object_multipart_size(const kal_wchar *filepath);
extern kal_uint32 wap_mma_uc_calc_slide_smil_size(kal_uint32 sec);
extern kal_uint32 wap_mma_uc_calc_object_smil_size(mma_insert_type_enum type, const kal_wchar *filepath);
extern void wap_mma_uc_insert_object_check(mma_creation_mode_enum creation_mode, const kal_wchar *filepath, 
    mma_insert_type_enum type, kal_uint32 current_msg_size, kal_uint32 max_msg_size, mma_insert_check_struct *info);
extern kal_bool wap_mms_is_storage_exported_to_pc(void);
extern kal_uint32 wap_mma_get_request_id(void);
extern kal_uint32 wap_mma_get_msg_id(kal_uint16 msg_box_type, kal_uint16 msg_index);
extern mma_folder_enum wap_mma_get_box(kal_uint32 msg_id);
extern kal_bool wap_mms_get_home_directory(kal_wchar *buffer, kal_uint32 buffer_size);
extern kal_bool wap_mms_get_message_file_name(kal_uint32 msg_id, kal_wchar *buffer, kal_uint32 buffer_size);

extern kal_uint8 wap_custom_get_max_mms_slide(void);
extern kal_uint8 wap_custom_get_max_mms_address(void);
extern kal_uint8 wap_custom_get_max_mms_attachment(void);
extern kal_uint32 wap_custom_get_max_mms_msg_size(void);
extern void mma_uc_get_file_mgr_filter(void *filter /*fmgr_filter_mask_struct defined in fmt_def.h*/, mma_uc_filter_mode_enum option);


#define MMA_MAX_SLIDE_NO (wap_custom_get_max_mms_slide())              /* default: 20 */
#define MMA_MAX_RECIPIENT_NO (wap_custom_get_max_mms_address())        /* default: 20 */
#define MMA_MAX_ATTACHMENT_NO (wap_custom_get_max_mms_attachment())    /* default: 3 */
#define MMA_MAX_PROCESS_TIME ((wap_custom_get_max_mms_msg_size()/1024) * 300)	/* 30 seconds per 100KB */


#if defined (OBIGO_Q05A)
/**********************************************************************
 * Constant definition
 **********************************************************************/
 
/**********************************************************************
 * Media type definition (should move to unified composer )
 **********************************************************************/
extern const char *wap_get_mms_restricted_image_type(void);
extern const char *wap_get_mms_restricted_text_type(void);
extern const char *wap_get_mms_restricted_audio_type(void);
extern const char *wap_get_mms_restricted_video_type(void);
extern const char *wap_get_mms_restricted_attachment_type(void);
extern const char *mma_get_mms_image_type(void);
extern const char *mma_get_mms_text_type(void);
extern const char *mma_get_mms_audio_type(void);
extern const char *mma_get_mms_video_type(void);
extern kal_uint32 mma_get_mmi_file_size(const kal_wchar *filepath);

#define MMA_OPEN_RESTRICTED_IMAGE_TYPES (wap_get_mms_restricted_image_type())
#define MMA_OPEN_RESTRICTED_TEXT_TYPES (wap_get_mms_restricted_text_type())
#define MMA_OPEN_RESTRICTED_AUDIO_TYPES (wap_get_mms_restricted_audio_type())
#define MMA_OPEN_RESTRICTED_VIDEO_TYPES (wap_get_mms_restricted_video_type())
#define MMA_OPEN_RESTRICTED_ATTACHMENT_TYPES (wap_get_mms_restricted_attachment_type())

#define MMA_OPEN_IMAGE_TYPES (mma_get_mms_image_type())
#define MMA_OPEN_TEXT_TYPES (mma_get_mms_text_type())
#define MMA_OPEN_AUDIO_TYPES (mma_get_mms_audio_type())
#define MMA_OPEN_VIDEO_TYPES ((mma_get_mms_video_type()))

#define MMA_DEFAULT_SMIL_BG_COLOR (0x00FFFFFF) /*MMA_CFG_SMIL_BG_COLOR*/
#define MMA_DEFAULT_SMIL_FG_COLOR (0x00000000) /*MMA_CFG_SMIL_FG_COLOR*/

#elif defined(OBIGO_Q03C) /*OBIGO_Q05A*/

extern const char *MEAlib_getOpenRestrictedImageType(void);
extern const char *MEAlib_getOpenRestrictedTextType(void);
extern const char *MEAlib_getOpenRestrictedAudioType(void);
extern const char *MEAlib_getOpenRestrictedVideoType(void);
extern const char *MEAlib_getOpenRestrictedAttachmentType(void);

extern const char *MEAlib_getOpenImageType(void);
extern const char *MEAlib_getOpenTextType(void);
extern const char *MEAlib_getOpenAudioType(void);
extern const char *MEAlib_getOpenVideoType(void);
extern const char *MEAlib_getOpenAttachmentType(void);

extern const unsigned MEAlib_getDefaultSmilBgColor(void);
extern const unsigned MEAlib_getDefaultSmilFgColor(void);


kal_uint32 mma_compare_request_id(kal_uint32 id1, kal_uint32 id2);
kal_uint32 mma_get_mmi_file_size(const kal_wchar *filepath);

/**********************************************************************
 * Constant definition
 **********************************************************************/
#define MMA_OPEN_RESTRICTED_IMAGE_TYPES (MEAlib_getOpenRestrictedImageType())
#define MMA_OPEN_RESTRICTED_TEXT_TYPES (MEAlib_getOpenRestrictedTextType())
#define MMA_OPEN_RESTRICTED_AUDIO_TYPES (MEAlib_getOpenRestrictedAudioType())
#define MMA_OPEN_RESTRICTED_VIDEO_TYPES (MEAlib_getOpenRestrictedVideoType())
#define MMA_OPEN_RESTRICTED_ATTACHMENT_TYPES (MEAlib_getOpenRestrictedAttachmentType())

#define MMA_OPEN_IMAGE_TYPES (MEAlib_getOpenImageType())
#define MMA_OPEN_TEXT_TYPES (MEAlib_getOpenTextType())
#define MMA_OPEN_AUDIO_TYPES (MEAlib_getOpenAudioType())
#define MMA_OPEN_VIDEO_TYPES (MEAlib_getOpenVideoType())
#define MMA_OPEN_ATTACHMENT_TYPES (MEAlib_getOpenAttachmentType())

#define MMA_DEFAULT_SMIL_BG_COLOR (MEAlib_getDefaultSmilBgColor())
#define MMA_DEFAULT_SMIL_FG_COLOR (MEAlib_getDefaultSmilFgColor())

/* user application */
extern kal_bool mmi_uc_is_uc_screen_in_history(void);
#define MMA_IS_UNIFIED_COMPOSER_ACTIVE mmi_uc_is_uc_screen_in_history

#elif defined(JATAAYU_SUPPORT) /*OBIGO_Q03C*/

/**********************************************************************
 * Constant definition
 **********************************************************************/

#define MMA_OPEN_IMAGE_TYPES JMMS_IMAGE_TYPES
#define MMA_OPEN_TEXT_TYPES JMMS_TEXT_TYPES
#define MMA_OPEN_AUDIO_TYPES JMMS_AUDIO_TYPES
#define MMA_OPEN_VIDEO_TYPES JMMS_VIDEO_TYPES
#define MMA_OPEN_ATTACHMENT_TYPES JMMS_ATTACHMENT_TYPES

#define MMA_OPEN_RESTRICTED_IMAGE_TYPES JMMS_IMAGE_TYPES
#define MMA_OPEN_RESTRICTED_TEXT_TYPES JMMS_TEXT_TYPES
#define MMA_OPEN_RESTRICTED_AUDIO_TYPES JMMS_AUDIO_TYPES
#define MMA_OPEN_RESTRICTED_VIDEO_TYPES JMMS_VIDEO_TYPES
#define MMA_OPEN_RESTRICTED_ATTACHMENT_TYPES JMMS_ATTACHMENT_TYPES

#define MMA_DEFAULT_SMIL_BG_COLOR 0xffffff
#define MMA_DEFAULT_SMIL_FG_COLOR 0x000000

#endif /*JATAAYU_SUPPORT*/
#endif /* _mmsadp_h */
