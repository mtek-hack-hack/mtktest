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
 *  JMMSInbox.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_inbox_ui.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSINBOXSECMMI_H
#define __MMI_JMMSINBOXSECMMI_H

#include "MMI_features.h"
#include "MMIDataType.h"
// #include "MessagingDataTypes.h"

#include "ddl.h"
#include "jcal.h"
#include "jcalnet.h"
#include "jdi_wspdatatype.h"

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

extern void mmi_jmms_entry_inbox_options_scren(void);
extern void mmi_jmms_entry_inbox_screen(void);
extern void mmi_jmms_entry_inbox(void);

/* inbox option handlers */
extern void mmi_jmms_highlight_inbox_options_view(void);
extern void mmi_jmms_highlight_inbox_options_reply(void);
extern void mmi_jmms_highlight_inbox_options_reply_all(void);
extern void mmi_jmms_highlight_inbox_options_forward(void);
extern void mmi_jmms_highlight_inbox_options_download(void);
extern void mmi_jmms_highlight_inbox_options_delete(void);
extern void mmi_jmms_highlight_inbox_options_delete_all(void);
extern void mmi_jmms_highlight_inbox_options_save_object(void);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_jmms_highlight_inbox_options_edit_message(void);
extern void mmi_jmms_pre_inbox_edit_message(void);
extern void mmi_jmms_highlight_inbox_options_use_number(void);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_highlight_inbox_options_use_details(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_highlight_inbox_options_properties(void);

extern void mmi_jmms_inbox_view(void);
extern void mmi_jmms_inbox_reply(void);
extern void mmi_jmms_inbox_reply_all(void);
extern void mmi_jmms_inbox_forward(void);
extern void mmi_jmms_inbox_download(void);
extern void mmi_jmms_inbox_delete(void);
extern void mmi_jmms_inbox_delete_all(void);

#ifdef __MMI_MMS_DELETE_ALL_READ_REPORT__
extern void mmi_jmms_inbox_delete_read_all(void);
extern void mmi_jmms_delete_read_all(void);
extern void mmi_jmms_highlight_inbox_options_delete_read_all(void);
#endif /* __MMI_MMS_DELETE_ALL_READ_REPORT__ */ 
#ifdef __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__
extern void mmi_jmms_inbox_delete_delivery_all(void);
extern void mmi_jmms_highlight_inbox_options_delete_delivery_all(void);
extern void mmi_jmms_delete_delivery_all(void);
#endif /* __MMI_MMS_DELETE_ALL_DELIVERY_REPORT__ */ 
extern void mmi_jmms_inbox_use_details(void);
extern void mmi_jmms_inbox_properties(void);

extern S32 mmi_jmms_get_item_hint_inbox(S32 item_index, UI_string_type *hint_array_p);
extern pBOOL mmi_jmms_get_item_data_inbox(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

extern void mmi_jmms_inbox_init(void);

extern void mmi_jmms_reply_message(JC_BOOLEAN reply_all);

extern MMI_BOOL mmi_jmms_is_msg_read(U8 index);

extern void mmi_jmms_pre_entry_inbox_options_scren(void);

extern void mmi_jmms_free_read_unread_status_bytes(void);

extern void mmi_jmms_inbox_pre_delete(void);

extern void mmi_jmms_inbox_forward_async_callback(JC_RETCODE ret_code);

extern void mmi_jmms_show_forward_progressing_screen(void);
extern void mmi_jmms_abort_forward_progress(void);

#ifdef __MMI_JATAAYU_MMS_REPLY_BY_SMS__
extern void mmi_jmms_msg_reply_as_sms(void);
extern void mmi_jmms_highlight_inbox_options_reply_by_sms(void);
#endif /* __MMI_JATAAYU_MMS_REPLY_BY_SMS__ */ 

/* PMT VIKAS START 20060405 */
// #ifdef __MMI_MMS_SIGNATURE__
extern MMI_BOOL mmi_jmms_is_fw_from_inbox(void);
extern void mmi_jmms_set_fw_flag_of_inbox(void);
extern void mmi_jmms_reset_fw_flag_of_inbox(void);

// #endif /* __MMI_MMS_SIGNATURE__ */
/* PMT VIKAS END 20060405 */

#endif /* __MMI_JMMSINBOXSECMMI_H */ 

