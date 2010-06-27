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
 *  JMMSMessageSettings.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_message_settings.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSMESSAGESETTINGS_H
#define __MMI_JMMSMESSAGESETTINGS_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "ddlbase.h"
#include "jcerror.h"
#include "jcevent.h"
#include "jcutils.h"
#include "jdd_MMIdatatype.h"
#include "gui_data_types.h"

/* 
 * Define
 */
#define MAX_NO_PAGES_INPUT          2
#define  MAX_DEFAULT_SLIDE_TIME_INPUT  3
#define MAX_AUTO_SIGN_LENGTH        128
#define  MAX_DEADLINE_TIME_VALUE_INPUT 2
#define  MAX_REPLY_CHARGE_SIZE_INPUT      3
#define  MAX_FILTER_MSG_SIZE_INPUT     3

/* 
 * Typedef 
 */
typedef enum
{
    E_USE_NVRAM_SETTINGS = 1,
    E_USE_LOCAL_SETTINGS
} jmms_use_settings_enum;

typedef enum
{
    E_IMMEDIATE,
    E_1_HR,
    E_12_HRS,
    E_24_HRS,
    DELIEVERY_TOTAL
} jmms_delievery_time_enum;

typedef enum
{
    E_OFF,
    E_ON
} jmms_off_on_enum;

typedef enum
{
    E_ALLOW,
    E_REJECT
} jmms_allow_reject_enum;

typedef enum
{
    E_PRIORITY_LOW,
    E_PRIORITY_NORMAL,
    E_PRIORITY_HIGH,
    PRIORITY_TOTAL
} jmms_priority_enum;

typedef enum
{
    E_VALIDITY_PERIOD_MAX,
    E_VALIDITY_PERIOD_1HR,
    E_VALIDITY_PERIOD_12HRS,
    E_VALIDITY_PERIOD_1DAY,
    E_VALIDITY_PERIOD_1WEEK,
    VALIDITY_PERIOD_TOTAL
} jmms_validity_period_enum;

typedef enum
{
    E_CREAT_MODE_RESTRICTED,
#ifndef __MMI_UNIFIED_COMPOSER__
    E_CREAT_MODE_WARNING,
#endif 
    E_CREAT_MODE_FREE,
    CREATION_MODES_TOTAL
} jmms_creation_modes_enum;

typedef enum
{
    E_MMS_LAYOUT_POTRAIT,
    E_MMS_LAYOUT_LANDSCAPE,
    LAYOUT_TOTAL
} jmms_layout_enum;

typedef enum
{
    E_IMAGE_RESIZE_OFF,
    E_IMAGE_RESIZE_160x120,
    E_IMAGE_RESIZE_320x240,
    E_IMAGE_RESIZE_640x480,
    IMAGE_RESIZE_TOTAL
} jmms_image_resize_enum;

typedef enum
{
    E_HOME_NOETWORK_RETRIEVAL_IMMEDAITE = 0x01, /* to match with raoming retrioeve modes */
    E_HOME_NOETWORK_RETRIEVAL_DEFFERED,
    E_HOME_NOETWORK_RETRIEVAL_RESTRICTED,
    HOME_NETWORK_TOTAL
} jmms_home_network_retrieval_enum;

typedef enum
{
    E_ROAMING_RETRIEVAL_AS_HOME,
    E_ROAMING_RETRIEVAL_IMMEDAITE,
    E_ROAMING_RETRIEVAL_DEFFERED,
    E_ROAMING_RETRIEVAL_RESTRICTED,
    ROAMING_TOTAL
} jmms_roaming_retrieval_enum;

typedef enum
{
    E_READ_REPORT_SEND_ON_REQUEST,
    E_READ_REPORT_SEND_ALWAYS,
    E_READ_REPORT_SEND_NEVER,
    READ_REPORT_SEND_TOTAL
} jmms_read_report_enum;

typedef enum
{
    E_FULL_MMS,
    E_TEXT_ONLY,
    REPLY_CHARGING_TYPE_TOTAL
} jmms_reply_charging_type_enum;

typedef enum
{
    E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION,
    E_COMPOSE_DEFAULT_SLIDE_TIME,
#ifndef __MMI_UNIFIED_COMPOSER__
    E_COMPOSE_LAYOUT_CAPTION,
    E_COMPOSE_LAYOUT,
#ifdef __DRM_SUPPORT__
    E_COMPOSE_ADD_DRM_CAPTION,
    E_COMPOSE_ADD_DRM,
#endif /* __DRM_SUPPORT__ */ 
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    E_COMPOSE_CREATION_MODES_CAPTION,
    E_COMPOSE_CREATION_MODES,
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    E_COMPOSE_IMAGE_RESIZE_CAPTION,
    E_COMPOSE_IMAGE_RESIZING,
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
#ifndef __MMI_UNIFIED_COMPOSER__
    E_COMPOSE_MAX_NO_PAGES_CAPTION,
    E_COMPOSE_MAX_NO_PAGES,
    E_COMPOSE_BEST_PAGE_DURATION_CAPTION,
    E_COMPOSE_BEST_PAGE_DURATION,
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    /* PMT VIKAS START 20060403 */
    // #ifdef __MMI_MMS_SIGNATURE__
    E_COMPOSE_AUTO_SIGNATURE_CAPTION,
    E_COMPOSE_AUTO_SIGNATURE,
    E_COMPOSE_AUTO_SIGNATURE_CONTENT,
    // #endif /* __MMI_MMS_SIGNATURE__ */
    /* PMT VIKAS END 20060403 */
    COMPOSE_INLINE_TOTAL
} jmms_compose_inline_items_enum;

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
#ifndef __MMI_UNIFIED_COMPOSER__
    E_SENDING_HIDE_SENDER_CAPTION,
    E_SENDING_HIDE_SENDER,
#endif /* __MMI_UNIFIED_COMPOSER__ */ 
    E_SENDING_REPLY_CHARGING_CAPTION,
    E_SENDING_REPLY_CHARGING,
    SENDING_INLINE_TOTAL
} jmms_sending_inline_items_enum;

typedef enum
{
    E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION,
    E_SENDING_REPLY_CHARGING_REQUEST_TYPE,
    E_SENDING_REPLY_CHARGING_DEADLINE_CAPTION,
    E_SENDING_REPLY_CHARGING_DEADLINE,
    E_SENDING_REPLY_CHARGING_SIZE_CAPTION,
    E_SENDING_REPLY_CHARGING_SIZE,
    SENDING_REPLY_CHARGING_INLINE_TOTAL
} jmms_sending_reply_charging_inline_items_enum;

typedef enum
{

    E_RETRIEVAL_HOME_NETWORK_CAPTION,
    E_RETRIEVAL_HOME_NETWORK,
    E_RETRIEVAL_ROAMING_CAPTION,
    E_RETRIEVAL_ROAMING,
    E_RETRIEVAL_FILTERS_CAPTION,
    E_RETRIEVAL_READ_REPORT_CAPTION,
    E_RETRIEVAL_READ_REPORT,
    E_RETRIEVAL_DELIVERY_REPORT_CAPTION,
    E_RETRIEVAL_DELIVERY_REPORT,
    RETRIEVAL_INLINE_TOTAL
} jmms_retrieval_inline_items_enum;

typedef enum
{
    E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION,
    E_RETRIEVAL_FILTERS_ANONYMOUS,
#ifdef __MMI_JMMS_CONF_RETRIVE_SIZE__
    E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION,
    E_RETRIEVAL_FILTERS_MAX_MSG_SIZE,
#endif /* __MMI_JMMS_CONF_RETRIVE_SIZE__ */ 
    E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION,
    E_RETRIEVAL_FILTERS_ADVERTISEMENT,
    RETRIEVAL_FILTER_INLINE_TOTAL
} jmms_retrieval_filters_inline_items_enum;

typedef enum
{
    E_ENTRY_FROM_MMS_SETTINGS,
    E_ENTRY_FROM_WRITE_MMS
} jmms_send_settings_entry_control_enum;

typedef struct
{
    U8 layout;
    U8 add_drm;
    U8 creation_mode;
    U8 image_resize_option;
    U8 max_no_pages;
    U8 best_page_duration;
    U8 auto_signature;
    U8 preferred_reply_type;
    U8 auto_signature_content[(MAX_AUTO_SIGN_LENGTH + 1) *ENCODING_LENGTH];
    U16 reserved_2;
    U32 default_slide_time;
} jmms_nvram_compose_settings_struct;

/* typedef struct
   {
   S32      validity_period;
   S32      delivery_report;
   S32      read_report;
   S32      priority;
   S32      delivery_time;
   S32      reply_charging;
   S32      request_type;
   U32      deadline_for_reply;
   U32      size;
   S32      hide_sender;
   }jmms_sending_settings_struct; */

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
    U32 deadline_for_reply;
    U32 size;
} jmms_nvram_sending_settings_struct;

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
} jmms_retrieval_settings_struct;

/* 
 * Extern Global Variable
 */
/* 
 * Extern Global Function
 */

extern void mmi_jmms_exit_compose_settings(void);

/* PMT VIKAS START 20060403 */
// #ifdef __MMI_MMS_SIGNATURE__
extern void mmi_jmms_auto_signature_highlight_hdlr(S32 index);

// #endif
/* PMT VIKAS END 20060403 */
extern void mmi_jmms_compose_fill_inline_struct(void);
extern void mmi_jmms_save_compose_settings(void);
extern void mmi_jmms_confirm_save_compose_settings(void);
extern void mmi_jmms_entry_compose_settings(void);
extern void mmi_jmms_highlight_memory_status(void);
extern void mmi_jmms_highlight_edit_profile(void);
extern void mmi_jmms_highlight_retrieval_setings(void);
extern void mmi_jmms_highlight_sending_setings(void);
extern void mmi_jmms_highlight_compose_setings(void);
extern void mmi_jmms_entry_message_settings(void);
extern void mmi_jmms_validate_max_no_pages(U8 *buffer_p, U8 *cursor_p, S32 text_length);

extern void mmi_jmms_entry_memory_status(void);
extern void mmi_jmms_pre_entry_memory_status(void);
extern void mmi_jmms_entry_retrieval_settings(void);
extern void mmi_jmms_entry_sending_settings(void);
extern void mmi_jmms_exit_confirm_screen(void);
extern void mmi_jmms_compose_inline_custom_func(void);
extern void mmi_jmms_validate_max_no_pages(U8 *buffer_p, U8 *cursor_p, S32 text_length);

extern void mmi_jmms_confirm_save_sending_settings(void);
extern void mmi_jmms_save_sending_settings(void);
extern void mmi_jmms_sending_fill_inline_struct(void);
extern void mmi_jmms_exit_sending_settings(void);

extern void mmi_jmms_reply_charging_highlight_hdlr(S32 index);
extern void mmi_jmms_entry_sending_reply_charging_settings(void);
extern void mmi_jmms_sending_reply_charging_fill_inline_struct(void);
extern void mmi_jmms_exit_sending_reply_charging_settings(void);

extern void mmi_jmms_confirm_save_retrieval_settings(void);
extern void mmi_jmms_save_retrieval_settings(void);
extern U32 mmi_jmms_retrieval_fill_inline_struct(U16 *image_list);
extern void mmi_jmms_retrieval_settings_highlight_hdlr(S32 index);
extern void mmi_jmms_exit_retrieval_settings(void);

extern void mmi_jmms_entry_retrieval_filters_settings(void);
extern void mmi_jmms_filter_done_handler(void);
extern void mmi_jmms_retrieval_filters_fill_inline_struct(void);
extern void mmi_jmms_exit_retrieval_filters_settings(void);

extern void mmi_jmms_pre_entry_sending_settings(void);
extern void mmi_jmms_pre_entry_retrieval_settings(void);
extern void mmi_jmms_pre_entry_compose_settings(void);

extern void mmi_jmms_check_sending_settings_control(U8 control);
extern void mmi_jmms_read_nvram_message_settings(void);
extern void mmi_jmms_sending_reply_charging_settings_done(void);
extern void mmi_jmms_pre_entry_sending_reply_charging_settings(void);

extern void mmi_jmms_sending_settings_highlight_hdlr(S32 index);
extern void mmi_jmms_read_back_auto_sign_content(void);

extern void mmi_jmms_free_addresses_list(void);

/* extern void mmi_jmms_free_addresses_list_on_end(void); */

extern void mmi_jmms_message_settings_init(void);

/* DARA PROFILEHANDLER 020106 */
extern void mmi_jmms_show_profile_list(void);

extern void mmi_jmms_restore_nvram_default_settings(void);
extern U16 mmi_jmms_get_profile_title_icon(void);

/* MAUI_00227929 Start */
extern void mmi_jmms_fill_mms_sending_settings(void);

/* MAUI_00227929 End */

#endif /* __MMI_JMMSMESSAGESETTINGS_H */ 

