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
 * JPushInboxCommonUI.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_PUSHINBOXCOMMONUI_H_
#define _MMI_PUSHINBOXCOMMONUI_H_

#if defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT)

#include "ddl.h"
#include "jdi_browsermodule.h"
#include "jcal.h"
#include "jdi_BrowserErr.h"
#include "jdi_XML.h"
#include "jdi_WBXML.h"
#include "jdd_fileapi.h"
#include "jdi_servicehandler.h"
#include "jdi_servicestorage.h"
#include "service_handler.h"
#include "service_storage.h"
#include "miscutils.h"
#include "Rtc_sw.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
/* #define BRW_MAX_PUSH_MESSAGES       MMI_UM_MAX_GET_LIST_MSG_NUMBER */
#else /* __MMI_UNIFIED_MESSAGE__ */ 
#include "custom_wap_config.h"
/* #define BRW_MAX_PUSH_MESSAGES       20 */
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#define MMI_BRW_SI_DATE_N_TIME_STRING_LENGTH 62
/*
 * Commented by vikas lal
 * extern SERVICE_VALUE **g_brw_service_msg_list_p;
 * extern U16 g_brw_index_current_highlighted_item;
 * extern SERVICE_VALUE *g_current_service_message;
 * extern S32 g_max_push_messages;
 * extern MMI_BOOL g_mmi_brw_delete_push_notification;
 */
extern void mmi_brw_initialize_push_message_list(void);
extern void mmi_brw_deinitialize_push_message_list(void);

extern void mmi_brw_push_free_service_value_struct(SERVICE_VALUE **service_message);
extern SERVICE_VALUE *mmi_brw_push_service_value_struct_dup(SERVICE_VALUE *service_message);

extern PS8 mmi_brw_create_push_display_format(SERVICE_VALUE *push_message_struct);
extern void mmi_brw_create_ucs2_push_time_format_string(SI_TIME *sisl_time, PS8 ucs2_time_string);

extern void mmi_brw_entry_read_push_message(void);
extern void mmi_brw_delete_push_message(void);
extern void mmi_brw_confirm_delete_all_push_messages(void);
extern void mmi_brw_entry_service_inbox_read_options(void);
extern void mmi_brw_accept_push_message(void);
extern void mmi_brw_create_push_msg_list(void);
extern void mmi_brw_new_push_msg_ind_on_idlescreen(void);
extern void mmi_brw_unread_push_message_indication(void);
extern U32 get_current_utc_time(void);
extern U32 mmi_brw_push_check_for_maximun_time(SI_TIME **gmt_time_p);  /* ADDED BY VIKAS LAL - FIX THE TIME LIMIT */
#endif /* defined (JATAAYU_SUPPORT) && defined (WAP_SUPPORT) */ /* _MMI_PUSHINBOXCOMMONUI_H_ */
#endif /* _MMI_PUSHINBOXCOMMONUI_H_ */ 

