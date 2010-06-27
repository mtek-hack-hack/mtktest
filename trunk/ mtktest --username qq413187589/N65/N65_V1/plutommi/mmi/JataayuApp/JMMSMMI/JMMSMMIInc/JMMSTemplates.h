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
 *  JMMSTemplates.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_templates_ui.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSTEMPLATESECMMI_H
#define __MMI_JMMSTEMPLATESECMMI_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

/* 
 * Define
 */

/* 
 * Typedef 
 */

typedef struct
{
    unsigned short strId;
    unsigned short imageId;
    unsigned short audioId;
} mmi_jmms_template_info_struct;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void mmi_jmms_entry_templates_screen(void);
extern S32 mmi_jmms_re_create_templates(FuncPtr template_complete_callback, MMI_BOOL show_popup);
extern void mmi_jmms_entry_templates_options_scren(void);
extern void mmi_jmms_highlight_templates_options_view(void);
extern void mmi_jmms_highlight_templates_options_write_message(void);
extern void mmi_jmms_highlight_templates_options_properties(void);
extern void mmi_jmms_templates_view(void);
extern void mmi_jmms_templates_write_message(void);
extern void mmi_jmms_templates_properties(void);
extern pBOOL mmi_jmms_get_item_data_templates(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);

extern void mmi_jmms_templates_init(void);

extern JC_RETCODE mmi_jmms_create_template_mms(
                    S8 *subject_p,
                    U8 *image_buff_p,
                    U32 image_len,
                    U8 *audio_buff_p,
                    U32 audio_len);

extern void mmi_jmms_show_template_properties(void);
extern void mmi_jmms_entry_templates(void);
extern void mm_jmms_back_from_template_properties(void);
extern void mm_jmms_end_from_template_properties(void);
extern void mmi_jmms_create_template_mms_return_callback(JC_RETCODE ret_code);
extern void mmi_jmms_templates_write_message_async_callback(JC_RETCODE ret_code);

extern void mmi_jmms_entry_template_progress_screen(void);
extern void mmi_jmms_create_template_messages(void);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_jmms_template_use_number(void);
extern void mmi_jmms_highlight_templates_view_options_use_number(void);
extern void mmi_jmms_highlight_templates_view_options_save_objects(void);
extern void mmi_jmms_entry_templates_view_options_scren(void);
extern void mmi_jmms_entry_templates_view_options_scren(void);
extern void mmi_jmms_highlight_templates_options_view_view_as(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_entry_new_mms_template_properties(void);
#endif /* __MMI_JMMSTEMPLATESECMMI_H */ 

