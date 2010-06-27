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
 *  JMMSMessageSettingsUtils.h
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
#ifndef __MMI_JMMSMMSSETTINGSUTILS_H
#define __MMI_JMMSMMSSETTINGSUTILS_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

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
// #ifdef __MMI_MMS_SIGNATURE__
extern U8 mmi_jmms_compose_settings_auto_sign_status(void);

#ifdef __UNIFIED_COMPOSER_SUPPORT__
extern S32 mmi_jmms_compose_settings_auto_sign_content(U8 *content_p, S32 buffer_size);
#else 
extern void mmi_jmms_compose_settings_auto_sign_content(U8 *content_p);
#endif 

// #endif /* __MMI_MMS_SIGNATURE__ */
/* PMT VIKAS END 20060403 */
extern U8 mmi_jmms_compose_settings_best_page_duration(void);

/* U8   mmi_jmms_compose_settings_creation_mode(void); */
extern ECreationMode mmi_jmms_compose_settings_creation_mode(void);

#ifdef __DRM_SUPPORT__
extern U8 mmi_jmms_is_compose_add_as_drm(JC_CHAR *filePath_p);
#endif 
extern U8 mmi_jmms_compose_settings_layout(void);
extern U8 mmi_jmms_compose_settings_max_no_pages(void);
extern U32 mmi_jmms_compose_settings_default_slide_time(void);
extern U8 mmi_jmms_sending_settings_delivery_report(void);

extern U32 mmi_jmms_sending_settings_delivery_time(void);

extern U8 mmi_jmms_sending_settings_hide_sender(void);
extern U8 mmi_jmms_sending_settings_priority(void);
extern U8 mmi_jmms_sending_settings_read_report(void);
extern U32 mmi_jmms_sending_settings_validity_period(void);
extern U8 mmi_jmms_sending_settings_reply_charging_status(void);
extern U8 mmi_jmms_sending_settings_reply_charging_request_type(void);
extern U32 mmi_jmms_sending_settings_deadline_for_reply(void);
extern U32 mmi_jmms_sending_settings_reply_charging_size(void);
extern U8 mmi_jmms_retrieval_settings_home_network_retrieval_mode(void);
extern U8 mmi_jmms_retrieval_settings_roaming_retrieval_mode(void);
extern U8 mmi_jmms_retrieval_settings_anonymous_filter(void);
extern U8 mmi_jmms_retrieval_settings_advertisment_filter(void);
extern U8 mmi_jmms_retrieval_settings_read_report(void);
extern U8 mmi_jmms_retrieval_settings_delivery_report(void);
extern S32 mmi_jmms_sending_settings_validity_period_enum(void);
extern S32 mmi_jmms_sending_settings_delivery_time_enum(void);
extern S32 mmi_jmms_image_resige_option(void);
extern U32 mmi_jmms_retrieval_settings_msg_size_filter(void);
#endif /* __MMI_JMMSMMSSETTINGSUTILS_H */ 

