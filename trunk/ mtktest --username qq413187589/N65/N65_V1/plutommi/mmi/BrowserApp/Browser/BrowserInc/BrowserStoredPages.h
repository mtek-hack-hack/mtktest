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
 * BrowserStoredPages.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *	This file contains declaration of all the functions that are being used in the 
 *  implementation of Stored Pages.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef BROWSERSTOREDPAGES_H
#define BROWSERSTOREDPAGES_H

#include "MMI_features.h"

#ifdef __MMI_BROWSER_2__
#include "MMIDataType.h"

/*Highlight Handlers*/
extern void mmi_brw_stored_pages_highlight_hdlr(void);
extern void mmi_brw_stored_page_open_highlight_hdlr(void);
extern void mmi_brw_stored_page_properties_highlight_hdlr(void);
extern void mmi_brw_stored_page_rename_highlight_hdlr(void);
extern void mmi_brw_stored_page_delete_highlight_hdlr(void);
extern void mmi_brw_stored_page_delete_all_highlight_hdlr(void);
extern void mmi_brw_stored_page_set_as_homepage_highlight_hdlr(void);
extern void mmi_brw_stored_page_add_to_bmk_highlight_hdlr(void);
extern void mmi_brw_stored_page_send_address_highlight_hdlr(void);
extern void mmi_brw_stored_page_memory_status_highlight_hdlr(void);
extern void mmi_brw_stored_page_rename_editor_done_option_highlight_hdlr(void);
/*Highlight Handlers*/

extern void mmi_brw_entry_stored_page_list(void);
extern void mmi_brw_stored_page_entry_options(void);
extern void mmi_brw_stored_page_pre_entry_options(void);
extern void mmi_brw_stored_page_entry_rename(void);
extern void mmi_brw_stored_page_pre_entry_page_properties(void);

extern pBOOL mmi_brw_stored_pages_list_get_item(S32, UI_string_type, PU8 *, U8);
extern void mmi_brw_stored_page_delete_confirm(void);
extern void mmi_brw_stored_pages_delete(void);
extern void mmi_brw_stored_pages_delete_all_confirm(void);
extern void mmi_brw_stored_pages_delete_all(void);
extern void mmi_brw_stored_pages_open(void);
extern void mmi_brw_entry_stored_page_properties(void);
extern void mmi_brw_stored_page_set_as_homepage(void);
extern void mmi_brw_stored_page_memory_status(void);
extern void mmi_brw_stored_pages_send_address(void);
extern void mmi_brw_stored_page_get_page_properties(void);
extern void mmi_brw_stored_page_rename(void);
extern void mmi_brw_stored_page_load_saved_page_req(U32);
extern void mmi_brw_stored_page_delete_saved_page_req(U32);
extern void mmi_brw_stored_page_delete_all_saved_page_req(void);
extern void mmi_brw_stored_page_rename_saved_page_req(U8*);
extern void mmi_brw_stored_page_get_saved_page_req(U32);
extern void mmi_brw_stored_pages_get_saved_pages_list_start_req(void);
extern void mmi_brw_stored_pages_get_saved_pages_list_continue_req(U32);
extern void mmi_brw_stored_pages_get_saved_pages_list_end_req(void);
extern void mmi_brw_stored_pages_add_to_bookmark(void);
extern void mmi_brw_stored_page_rename_confirm(void);

/*Interfaces of other internal modules*/
#ifdef __MMI_VBOOKMARK__
extern void mmi_brw_bookmarks_entry_add_bookmark(void);
#endif /*__MMI_VBOOKMARK__*/
/*Interfaces of other internal modules*/

#endif /* __MMI_BROWSER_2__ */ 
#endif /* BROWSERSTOREDPAGES_H */ 

