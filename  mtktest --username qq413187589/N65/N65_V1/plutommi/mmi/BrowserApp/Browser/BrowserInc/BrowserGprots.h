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
 * BrowserGprots.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains declaration of interfacing functions for external modules.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERGPROTS_H
#define BROWSERDEFS_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"
#include "FS_type.h"

/*Interfaces for external modules*/
extern void mmi_brw_wap_init(void);
extern void mmi_brw_wap_deinit(void);
extern void mmi_brw_pre_entry_internet_services(void);
extern void mmi_brw_active_profile_changed(void);
extern void mmi_brw_active_profile_changed_without_ui(void);
extern void mmi_brw_set_as_homepage(U8 *url_p);
extern void mmi_brw_load_url(U8 *url_p);
extern void mmi_brw_open_file_callback(void *fullname, int is_short);
#ifdef __MMI_VBOOKMARK__
extern S16 mmi_brw_add_to_bookmark(U8* title_p, U8* url_p);
extern void mmi_brw_bookmarks_recv_file_view(U8* file_path, U8* file_name);
extern void mmi_brw_bookmarks_recv_file_save_to_bookmark(U8* file_path, U8* file_name, U8* file_extn);
extern void mmi_brw_bookmarks_recv_file_save_to_fmgr(U8* file_path, U8* file_name, U8* file_extn);
extern void mmi_brw_bookmarks_goto_from_fmgr(void *fullname, int is_short);
extern void mmi_brw_bookmarks_open_from_fmgr(void *fullname, int is_short);
#endif /*__MMI_VBOOKMARK__*/
extern void mmi_brw_start_browser_action(U8 option, U8* url);
extern U16 mmi_brw_get_screen_id(void);
extern void mmi_brw_open_file_from_fmgr(void *fullname, int is_short);
extern void mmi_brw_memory_card_plug_out_hdlr(void);
/*Interfaces for external modules*/

/*Interfaces of external modules*/
extern nvram_profile_content_struct *mmi_brw_prof_get_activated_wap_profile(void);
extern pBOOL mmi_brw_prof_wap_set_homepage (S8 *homepage_url);
extern U8 mmi_dtcnt_get_bearer_type(U8 account_id);//data account module
extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);
extern void mmi_brw_push_inbox_init(void);
extern void mmi_prov_init(void);
extern void mmi_brw_push_free_memory(void);
extern void mmi_brw_push_pre_entry_inbox_validation(void);
extern void mmi_brw_phs_pre_entry_push_setting(void);
extern MMI_ID_TYPE GetFileSystemErrorString(S32 error);
//extern UI_string_type UCS2StrLastChr(UI_string_type ustring1, UI_character_type uchar2);
extern void mms_content_insert_hdlr(char *content_source);
extern pBOOL isInCall(void);
extern kal_uint16 wap_get_screen_id(void);
#ifdef APPMEM_SUPPORT
extern void resetAppMemPool(void);
extern void setAppMemPool(void *memory_addr);
extern void mmi_frm_appmem_prompt_to_release_mem(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void));
#endif /*APPMEM_SUPPORT*/
extern int applib_url_is_valid(const char *url);
extern void mmi_brw_prof_display_activation_popup(void);
extern unsigned int bam_get_bits(char *data, int numbits);
extern pBOOL mmi_bootup_get_active_flight_mode(void);
extern pBOOL mmi_bootup_is_sim_valid(void);
extern void mmi_irda_obex_snd_abort(void);
extern BOOL mmi_irda_is_sending(void);
extern void mmi_email_app_send_attch(const S8* file_path);
extern void mmi_email_app_send_cont(const S8* cont);
extern void MakeCall(PS8 strNumber);
/*Interfaces of external modules*/

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERGPROTS_H */ 

