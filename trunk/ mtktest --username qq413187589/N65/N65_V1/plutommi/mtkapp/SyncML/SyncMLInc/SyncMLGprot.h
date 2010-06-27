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
 *    SyncMLGprot.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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

#ifndef __SYNCML_GPROT_H__
#define __SYNCML_GPROT_H__

#ifdef __SYNCML_SUPPORT__

/* SyncMLMain.c */
extern void mmi_syncml_init(void);

extern void mmi_syncml_update_settings_to_nvram(void);
extern void mmi_syncml_read_settings_from_nvram(void);

extern pBOOL mmi_syncml_is_phb_sync_now(void);
extern pBOOL mmi_syncml_is_tdl_sync_now(void);

extern void mmi_syncml_entry_sync_pre_check(void);

/* SyncMLProfile.c */
extern void mmi_syncml_list_data_account(void);
extern void mmi_syncml_prof_ip_addr_callback(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
extern void* mmi_syncml_get_profile_edit_context(void);
extern void* mmi_syncml_get_data_account_edit_context(void);
extern void* mmi_syncml_get_syncml_profile(void);

/* SyncMLChangeLog.c */
extern void mmi_syncml_phb_data_changed_notification(U8 operation, U16 luid);
extern void mmi_syncml_tdl_data_changed_notification(U8 operation, U16 luid);

/* SyncMLHandler.c */
extern void mmi_syncml_phb_sync_rsp(U16 phb_result, U16 store_index);
extern void mmi_syncml_abort_sync_req(void);
extern pBOOL mmi_syncml_compare_sync_server(U8 *comp_server_address);

/* SyncMLRegularity.c */
extern void mmi_syncml_init_alarm(void);
extern U8 mmi_syncml_is_sync_alarm_expired(void);
extern void mmi_syncml_sync_alarm_hdlr(void);

/* SyncMLReport.c */

/* SyncMLSAS.c */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
extern void mmi_syncml_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string);
#endif /* __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__ */

/*for provisioning & DM*/
#ifdef __MMI_SYNCML_CCA_SUPPORT__
void mmi_syncml_construct_cca_document_for_dm(U16 app_id, S32 prof_id);
void mmi_syncml_install_cca_document_from_dm(U16 app_id, S32 prof_id, S32 hConfig);
void mmi_syncml_proc_cca_doc(U16 conf_id, S32 doc_hdl);
#endif /* __MMI_SYNCML_CCA_SUPPORT__ */

#endif /* __SYNCML_SUPPORT__ */

#endif /* __SYNCML_GPROT_H__ */

