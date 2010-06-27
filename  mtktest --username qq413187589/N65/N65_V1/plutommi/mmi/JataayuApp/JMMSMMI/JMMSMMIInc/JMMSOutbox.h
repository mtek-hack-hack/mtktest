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
 *  JMMSOutbox.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_outbox_ui.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSOUTBOXSECMMI_H
#define __MMI_JMMSOUTBOXSECMMI_H

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

extern void mmi_jmms_entry_outbox(void);
extern void mmi_jmms_entry_outbox_screen(void);
extern void mmi_jmms_entry_outbox_options_scren(void);
extern void mmi_jmms_highlight_outbox_options_view(void);
extern void mmi_jmms_highlight_outbox_options_resend(void);

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_jmms_highlight_outbox_options_edit_message(void);
extern void mmi_jmms_pre_outbox_edit_message(void);
extern void mmi_jmms_highlight_outbox_options_save_object(void);
extern void mmi_jmms_highlight_outbox_options_use_number(void);
#else /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_highlight_outbox_options_use_details(void);
extern void mmi_jmms_highlight_outbox_options_sent_to_others(void);
extern void mmi_jmms_highlight_outbox_options_move_to_drafts(void);
extern void mmi_jmms_outbox_sent_to_others(void);
extern void mmi_jmms_outbox_move_to_drafts(void);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
extern void mmi_jmms_highlight_outbox_options_delete(void);
extern void mmi_jmms_highlight_outbox_options_delete_all(void);
extern void mmi_jmms_highlight_outbox_options_properties(void);
extern void mmi_jmms_outbox_view(void);
extern void mmi_jmms_outbox_resend(void);
extern void mmi_jmms_outbox_delete(void);
extern void mmi_jmms_outbox_delete_all(void);
extern void mmi_jmms_outbox_use_details(void);

extern void mmi_jmms_outbox_properties(void);

extern void mmi_jmms_outbox_init(void);

extern S32 mmi_jmms_get_item_hint_outbox(S32 item_index, UI_string_type *hint_array_p);
extern pBOOL mmi_jmms_get_item_data_outbox(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

extern void mmi_jmms_delete_all_message_outbox(void);
extern void mmi_jmms_outbox_delete_on_sent(void);
extern void mmi_jmms_outbox_pre_delete(void);

/******************************************************************************
 Written By : Raj Kumar Gupta
 Date       : 09 June 2006
 *****************************************************************************/
extern void mmi_jmms_outbox_resend_send_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_outbox_resend_parse_async_callback(JC_RETCODE ret_code);
extern void mmi_jmms_outbox_sent_to_others_async_callback(JC_RETCODE ret_code);

#endif /* __MMI_JMMSOUTBOXSECMMI_H */ 

