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
 *  MMSMessageSettingsUtils.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_mms_settings_utils.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSMMSSETTINGSUTILS_H
#define __MMI_JMMSMMSSETTINGSUTILS_H

#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "mmsadp.h"
#include "wap_ps_struct.h"
#include "MMSMessageSettings.h"
#define UMMS_MMI_MAKE_SETTINGS_TEXT_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\setting_text0.txt",MMI_SYSTEM_DRV);
typedef enum
{
	MMA_FULL_MMS,
	MMA_TEXT_ONLY,
	MMA_REPLY_CHARGING_TYPE_TOTAL
} mma_reply_charging_type_enum;

/* 
 * Define
 */

/* 
 * Typedef 
 */

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

/* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
extern void mmi_umms_compose_settings_sign_info(mma_signature_struct   *signature);

/* extern void mmi_jmms_compose_settings_auto_sign_content(U8 *content); */
#endif /* __MMI_MMS_SIGNATURE__ */ 
/* PMT VIKAS END 20060403 */
extern U8 mmi_umms_compose_settings_best_page_duration(void);

/* U8   mmi_jmms_compose_settings_creation_mode(void); */
/* extern ECreationMode mmi_jmms_compose_settings_creation_mode(void); */

#ifdef __DRM_SUPPORT__
extern U8 mmi_umms_compose_settings_add_as_drm(void);
#endif 
extern U8 mmi_umms_compose_settings_layout(void);
extern U8 mmi_umms_compose_settings_max_no_pages(void);
extern void mmi_umms_compose_settings_default_slide_time(mma_setting_struct *set);
extern U8 mmi_umms_sending_settings_delivery_report(void);
extern void mmi_umms_compose_setting_image_resize_info(mma_image_resizing_struct *resize);
extern mma_delivery_time_enum mmi_umms_sending_settings_delivery_time(void);

extern U8 mmi_umms_sending_settings_hide_sender(void);
extern U8 mmi_umms_sending_settings_send_and_save(void);
extern mma_priority_enum mmi_umms_sending_settings_priority(void);
extern U8 mmi_umms_sending_settings_read_report(void);
extern mma_expiry_time_enum mmi_umms_sending_settings_validity_period(void);
extern U8 mmi_umms_sending_settings_reply_charging_status(void);
extern mma_reply_charging_type_enum mmi_umms_sending_settings_reply_charging_request_type(void);
extern U32 mmi_umms_sending_settings_deadline_for_reply(void);
extern U32 mmi_umms_sending_settings_reply_charging_size(void);
extern mma_retrieval_mode_enum mmi_umms_retrieval_settings_home_network_retrieval_mode(void);
extern mma_retrieval_mode_enum mmi_umms_retrieval_settings_roaming_retrieval_mode(void);
extern U8 mmi_umms_retrieval_settings_anonymous_filter(void);
extern U8 mmi_umms_retrieval_settings_advertisment_filter(void);
extern umms_read_report_enum mmi_umms_retrieval_settings_read_report(void);
extern U8 mmi_umms_retrieval_settings_delivery_report(void);
extern mma_creation_mode_enum mmi_umms_compose_settings_creation_mode(void);
extern void mmi_umms_set_signature_file_mgr_filter(FMGR_FILTER* filter, const char *mime_types);
#ifndef __MMI_MMS_OMA_CONF_273__
extern U16 mmi_umms_retrieval_settings_msg_size_filter(void);
#endif 
#endif /* __MMI_MMS_2__ */
#endif /* __MMI_JMMSMMSSETTINGSUTILS_H */ 

