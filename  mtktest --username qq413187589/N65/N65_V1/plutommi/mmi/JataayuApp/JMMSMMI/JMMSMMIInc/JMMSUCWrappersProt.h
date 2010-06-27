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
 *  JMMSUCWrappersProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for providing all wrappers for Jataayu UC integration.
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_UC_JMMS_WRAPPER_H
#define __MMI_UC_JMMS_WRAPPER_H

#if defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__)

#include "mmsadp.h"

extern UmMsgBoxType mmi_jmms_uc_um_folder_conversion(mma_folder_enum msg_box_type);
extern mmi_jmms_folder_info_enum mmi_jmms_uc_mma_jmms_folder_conversion(mma_folder_enum msg_box_type);
extern mma_creation_mode_enum mmi_jmms_uc_get_creation_mode(void);
extern mma_priority_enum mmi_jmms_uc_conf_get_priority(void);
extern mma_expiry_time_enum mmi_jmms_uc_conf_get_expiry_time(void);
extern mma_delivery_time_enum mmi_jmms_uc_conf_get_delivery_time(void);
extern kal_bool mmi_jmms_uc_conf_get_delivery_report(void);
extern kal_bool mmi_jmms_uc_conf_get_read_report(void);
extern kal_uint32 mmi_jmms_uc_conf_get_max_mms_size(void);
extern BOOL mmi_jmms_uc_sending_settings_sender_visibility(void);
extern void mmi_jmms_uc_conf_get_image_resizing(mma_image_resizing_struct *resizing_p);
extern void mmi_jmms_uc_conf_get_signature(mma_signature_struct *sig_p);
extern void mmi_jmms_uc_conf_get_sliding_time(mma_setting_struct *sliding_p);
extern mmi_uc_layout_enum mmi_jmms_uc_conf_get_mms_resion_layout(void);

extern mma_folder_enum mmi_jmms_get_mma_folder_type_from_id(kal_uint32 msg_id);
extern mma_insert_type_enum mmi_jmms_uc_get_mms_media_type_from_file(
                                const kal_wchar *filename_p,
                                mma_insert_type_enum type);
extern const kal_wchar *mmi_jmms_uc_get_name_from_path_ucs2(const kal_wchar *path_p);
extern kal_uint8 *mmi_jmms_uc_get_mime_string_from_file(const kal_wchar *filename_p, mma_insert_type_enum type);
extern mma_delivery_time_enum mmi_jmms_uc_conf_get_local_delivery_time(JC_UINT32 delivery_time);
extern mma_expiry_time_enum mmi_jmms_uc_conf_get_local_expiry_time(JC_UINT32 expiry_time);
extern mma_priority_enum mmi_jmms_uc_conf_get_local_priority(jmms_priority_enum type);
#endif /* defined (JATAAYU_SUPPORT) && defined (MMS_SUPPORT) && defined (__UNIFIED_COMPOSER_SUPPORT__) */ 
#endif /* __MMI_UC_JMMS_WRAPPER_H */

