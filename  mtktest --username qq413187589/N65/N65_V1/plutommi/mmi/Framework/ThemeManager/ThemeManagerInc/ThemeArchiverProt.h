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
 * ThemeArchiverDef.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines string, screen, and image ids for Theme Archiver application.
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
 *
 * removed!
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

/**************************************************************

   FILENAME : ThemeArchiverDef.h

   PURPOSE     : Theme Archiver

   REMARKS     : nil

   AUTHOR      : Alok

   DATE     : April 14,05

**************************************************************/
#ifndef _MMI_THEME_ARCHIVER_PROT_H
#define _MMI_THEME_ARCHIVER_PROT_H

#include "MMI_features.h"
#include "ThemeArchiverMsgStruct.h"
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

extern void mmi_ta_init_themearchiver(void);
extern void mmi_ta_da_content_recvd_hdlr(void *inMsg);
extern void mmi_ta_handle_download_response(void *inMsg);
extern void mmi_ta_theme_download_complete_notification(void);
extern void mmi_ta_handle_abort_req(void *inMsg);
extern void mmi_ta_entry_select_storage_screen(void);
extern void mmi_ta_entry_download_info_screen(void);

extern void mmi_ta_select_dlt_storage_type(S32 index);
extern void mmi_ta_exit_dlt_storage_type(void);
extern void mmi_ta_set_dlt_storage_type(void);

extern void mmi_ta_da_handle_non_oma_content(ta_da_content_received_struct *msg);
extern void mmi_ta_da_handle_descriptor(ta_da_content_received_struct *msg);
extern void mmi_ta_da_parse_descriptor(U8 *);

extern void mmi_ta_da_compare_theme_compatibility_withphone(void);
extern void mmi_ta_set_dlt_as_activated(void);
extern void mmi_ta_send_theme_content_req_to_wap(S8 *filepath);
extern void mmi_ta_descriptor_data_handler(void *data, const char *el, const char *value, kal_int32 len);
extern PS8 mmi_ta_parse_url_extract_file_name(S8 *path);
extern void mmi_ta_go_back_history(void);
extern void mmi_ta_free_dynamic_memory(void);
extern void mmi_ta_end_key_handler(void);
extern void mmi_ta_delete_intermediate_dlt_files(U16 *);
extern void mmi_ta_check_if_file_alrdy_exist_in_fm(PS8, PS8);
extern U16 mmi_ta_check_theme_file_version_compatibility(FLOAT theme_version);
extern U16 mmi_ta_check_theme_file_lcd_dim_compatibiltiy(U32 lcd_width, U32 lcd_height);
extern U16 mmi_ta_check_theme_type_compatibility(S8 *input_type);
extern void mmi_ta_thmgr_hide_ext_name(S8 *file_name);

extern void mmi_ta_save_theme_content(S8 *filepath_p);
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ // #ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

#endif /* _MMI_THEME_ARCHIVER_PROT_H */ // #ifndef _MMI_THEME_ARCHIVER_PROT_H

