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
 * EmailAppUIInterface.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements UI interface of Email application.
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
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : EmailAppUIInterface.c

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : 30-01-2004

**************************************************************/
#include "MMI_include.h"
#ifndef _MMI_EMAILAPPUIINTERFACE_C
#define _MMI_EMAILAPPUIINTERFACE_C

#ifdef __MMI_EMAIL__
#include "CommonScreens.h"
#include "Conversions.h"
#include "app_mine.h"

#include "wgui_status_icons.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "MemPoolContainerProt.h"

#include "fmt_struct.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"

#include "DataAccountGprot.h"
#include "PhoneBookGprot.h"
#include "PhoneSetupGprots.h"

#include "mdi_datatype.h"
#include "AudioPlayerProt.h"
#include "VdoPlyGProt.h"
#include "VdoPlyResDef.h"
#include "ImageViewer.h"

#include "App_usedetails.h" /*to use applib_get_address_list_from_text_ext*/
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif
#include "CallManagementGprot.h"   /*to use MakeCall*/
#include "wapadp.h"  /*to use wap_start_browser*/

#ifdef __MMI_EMAIL_DRM_SUPPORT__
#include "Drm_gprot.h"
#endif 
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard.h"
#endif
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 
#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_PFAL_CC.h"
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#include "MessagesResourceData.h"
#include "EmailAppResDef.h"
#include "EmailAppProt.h"
#include "EmailAppGProt.h"

extern S32 mmi_is_redrawing_bk_screens(void);
extern void set_leading_zero(U8 u8type);
extern void Category53ChangeItemDescription(S32 index, U8 *text);
#ifdef __FLIGHT_MODE_SUPPORT__
extern pBOOL mmi_bootup_get_active_flight_mode(void);
#endif
extern pBOOL mmi_bootup_is_network_service_available(void);

extern BOOL play_warning_tone;
#ifdef __MMI_EMAIL_DRM_SUPPORT__
static BOOL is_drm_file = MMI_FALSE;
extern BOOL drm_file_ignore;
S8 rights_issuer[MAX_LINE_LENGTH];
#endif
/* MTK Elvis for R2L characters */
extern BOOL r2lMMIFlag;

/* for content editor insert template */
static S32 compose_input_length = 0;

static void* mmi_email_malloc(kal_uint32 size);
static void mmi_email_free(void* p);
static void mmi_email_cont_num_addr_sendkey_handler(void);
static kal_bool mmi_email_extract_addr_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num);

/***************************************************************/
const U8 g_email_subj_left_op[] = { '<', '\0', '\0', '\0' };
const U8 g_email_subj_right_op[] = { '>', '\0', '\0', '\0' };
const U8 g_email_3dots[] = { '.', '\0', '.', '\0', '.', '\0', '\0', '\0' };
const S8 g_email_new_line[] = { '\r', '\0', '\n', '\0', '\0', '\0' };
const S16 g_email_addr_input_modes[] = {INPUT_MODE_MULTITAP_UPPERCASE_ABC, \
                                        INPUT_MODE_MULTITAP_LOWERCASE_ABC, \
                                        INPUT_MODE_123, \
                                        INPUT_MODE_SMART_UPPERCASE_ABC, \
                                        INPUT_MODE_SMART_LOWERCASE_ABC, \
                                        -1 };
#ifdef __MMI_TOUCH_SCREEN__
const UI_character_type g_email_allowed[] = L"+_\\-.@A-Za-z0-9";
#endif

extern InlineItem wgui_inline_items[];
extern BOOL delete_abort_req;

#if defined(__MMI_EMAIL_TEMPLATE__)
static void mmi_email_highlight_edit_template(void);
static void mmi_email_highlight_erase_template(void);
static void mmi_email_highlight_template_write_email(void);
static void mmi_email_highlight_save_template(void);
static void mmi_email_entry_template_list(void);
static void mmi_email_hilite_template(void);
static void mmi_email_entry_comp_cont_opt(void);
static pBOOL mmi_email_template_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_email_entry_template_option(void);
static void mmi_email_entry_template_edit_option(void);
static void mmi_email_hilite_use_template(void);
static void mmi_email_save_template_query(void);
static void mmi_email_goback_to_template_list_screen(void);
static void mmi_email_template_exec_write_email(void);
#endif /* defined(__MMI_EMAIL_TEMPLATE__) */

static S8 retrieve_att_size[MMI_EMAIL_MAX_NUM_ATTACH][5 * ENCODING_LENGTH];

#define INIT_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_init_hilite_hdlr
 * DESCRIPTION
 *  Initialize all highlight handlers
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_init_hilite_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Wrirte Email */
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ADDR_ADD, mmi_email_hilite_comp_addr_add);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ADDR_EDIT, mmi_email_hilite_comp_addr_edit);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ADDR_DEL, mmi_email_hilite_comp_addr_del);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ADDR_DEL_ALL, mmi_email_hilite_comp_addr_del_all);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_SUBJ_DONE, mmi_email_hilite_comp_subj_done);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_SUBJ_INPUT_METH, mmi_email_hilite_comp_subj_input_meth);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT_DONE, mmi_email_hilite_comp_addr_done);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT_INPUT_METH, mmi_email_hilite_comp_addr_input_meth);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ATTCH_EDIT, mmi_email_hilite_comp_attach_edit);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ATTCH_VIEW, mmi_email_hilite_comp_attach_view);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_ATTCH_DEL, mmi_email_hilite_comp_attach_del);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_SEND, mmi_email_hilite_comp_send);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_SAVE_N_SEND, mmi_email_hilite_comp_save_n_send);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_SAVE_TO_DRAFT, mmi_email_hilite_comp_save_to_draft);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_QUIT_NO_SAVE, mmi_email_hilite_comp_quit);
#ifdef __MMI_EMAIL_TEMPLATE__
    SetHiliteHandler(MENU_ID_EMAIL_TEMPL_EDIT, mmi_email_highlight_edit_template);
    SetHiliteHandler(MENU_ID_EMAIL_TEMPL_ERASE, mmi_email_highlight_erase_template);
    SetHiliteHandler(MENU_ID_EMAIL_TEMPL_WRITE_EMAIL, mmi_email_highlight_template_write_email);

    SetHiliteHandler(MENU_ID_EMAIL_EDIT_TEMPL_SAVE, mmi_email_highlight_save_template);
    SetHiliteHandler(MENU_ID_EMAIL_EDIT_TEMPL_INPUT_METH, mmi_email_hilite_comp_subj_input_meth);
    
    SetHiliteHandler(MENU_ID_EMAIL_COMP_CONT_DONE, mmi_email_hilite_comp_subj_done);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_CONT_INPUT_METH, mmi_email_hilite_comp_subj_input_meth);
    SetHiliteHandler(MENU_ID_EMAIL_COMP_CONT_USE_TEMPLATE, mmi_email_hilite_use_template);
#endif /*__MMI_EMAIL_TEMPLATE__*/

    /* Read */
    SetHiliteHandler(MENU_ID_EMAIL_READ_ADDR_OPT_SAVE, mmi_email_hilite_read_addr_save_phb);
    SetHiliteHandler(MENU_ID_EMAIL_READ_ADDR_OPT_SEND, mmi_email_hilite_read_addr_send);
    SetHiliteHandler(MENU_ID_EMAIL_READ_ATTCH_OPT_VIEW, mmi_email_hilite_read_attach_view);
    SetHiliteHandler(MENU_ID_EMAIL_READ_ATTCH_OPT_SAVE, mmi_email_hilite_read_attach_save);
    SetHiliteHandler(MENU_ID_EMAIL_READ_ATTCH_SAVE_DONE, mmi_email_hilite_read_attach_save_done);
    SetHiliteHandler(MENU_ID_EMAIL_READ_ATTCH_SAVE_INPUT_METH, mmi_email_hilite_read_attach_save_input_meth);
    SetHiliteHandler(MENU_ID_EMAIL_EXTRACT_PHONENUMBER, mmi_email_hilite_extract_phonenumber);
    SetHiliteHandler(MENU_ID_EMAIL_EXTRACT_EMAILADDR, mmi_email_hilite_extract_emailaddr);
    SetHiliteHandler(MENU_ID_EMAIL_EXTRACT_WEBADDR, mmi_email_hilite_extract_webaddr);
    SetHiliteHandler(MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT_CALL, mmi_email_hilite_cont_addr_phonenumber_call);
    SetHiliteHandler(MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT_SAVE, mmi_email_hilite_cont_addr_phonenumber_save_phb);
    SetHiliteHandler(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SEND_EMAIL, mmi_email_hilite_cont_addr_email_send_email);
    SetHiliteHandler(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SAVE, mmi_email_hilite_cont_addr_email_save_phb);    
    SetHiliteHandler(MENU_ID_EMAIL_CONT_ADDR_URL_OPT_WAP, mmi_email_hilite_cont_addr_url_connect);
    SetHiliteHandler(MENU_ID_EMAIL_CONT_ADDR_URL_OPT_ADD_BOOKMARK, mmi_email_hilite_cont_addr_url_add_bookmark);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    SetHiliteHandler(MENU_ID_EMAIL_FOLDER_OPT_READ, mmi_email_hilite_folder_read);
    SetHiliteHandler(MENU_ID_EMAIL_FOLDER_OPT_NEXT_PAGE, mmi_email_hilite_fldr_next_page);
    SetHiliteHandler(MENU_ID_EMAIL_FOLDER_OPT_PREV_PAGE, mmi_email_hilite_fldr_prev_page);
    SetHiliteHandler(MENU_ID_EMAIL_FOLDER_OPT_JUMP_PAGE, mmi_email_hilite_fldr_jump_to_page);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    /* Inbox */
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_REPLY, mmi_email_hilite_inbox_reply);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_REPLY_WITHOUT, mmi_email_hilite_inbox_reply_without);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_REPLY_ALL, mmi_email_hilite_inbox_reply_all);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_REPLY_ALL_WITHOUT, mmi_email_hilite_inbox_reply_all_without);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_RETRIEVE_OPTION, mmi_email_hilite_read_retrieve_option);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_MARK_UNREAD, mmi_email_hilite_read_mark_unread);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_MARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_UNMARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_FW, mmi_email_hilite_read_forward);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_EXTRACT, mmi_email_hilite_read_extract);
    SetHiliteHandler(MENU_ID_EMAIL_INBOX_OPT_DEL, mmi_email_hilite_read_msg_del);
    /* Sent */
    SetHiliteHandler(MENU_ID_EMAIL_SENT_OPT_FW, mmi_email_hilite_read_forward);
    SetHiliteHandler(MENU_ID_EMAIL_SENT_OPT_RETRIEVE, mmi_email_hilite_read_retrieve_option);
    SetHiliteHandler(MENU_ID_EMAIL_SENT_OPT_MARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_SENT_OPT_UNMARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_SENT_OPT_EXTRACT, mmi_email_hilite_read_extract);
    SetHiliteHandler(MENU_ID_EMAIL_SENT_OPT_DEL, mmi_email_hilite_read_msg_del);
    /* Unsent */
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_SEND, mmi_email_hilite_unsent_send);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_SAVE_N_SEND, mmi_email_hilite_unsent_save_n_send);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_EDIT, mmi_email_hilite_read_edit);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_MOVE, mmi_email_hilite_unsent_move);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_MARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_UNMARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_EXTRACT, mmi_email_hilite_read_extract);
    SetHiliteHandler(MENU_ID_EMAIL_UNSENT_OPT_DEL, mmi_email_hilite_read_msg_del);
    /* Draft */
    SetHiliteHandler(MENU_ID_EMAIL_DRAFT_OPT_EDIT, mmi_email_hilite_read_edit);
    SetHiliteHandler(MENU_ID_EMAIL_DRAFT_OPT_RETRIEVE, mmi_email_hilite_read_retrieve_option);
    SetHiliteHandler(MENU_ID_EMAIL_DRAFT_OPT_MARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_DRAFT_OPT_UNMARK_DELETED, mmi_email_hilite_read_mark_deleted);
    SetHiliteHandler(MENU_ID_EMAIL_DRAFT_OPT_EXTRACT, mmi_email_hilite_read_extract);
    SetHiliteHandler(MENU_ID_EMAIL_DRAFT_OPT_DEL, mmi_email_hilite_read_msg_del);

    /* Profile */
    SetHiliteHandler(MENU_ID_EMAIL_PROF_ACTIVATE, mmi_email_hilite_prof_activate);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDIT, mmi_email_hilite_prof_edit);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDIT_OPT_SETTING, mmi_email_hilite_prof_setting);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDIT_OPT_SMTP, mmi_email_hilite_prof_smtp);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDIT_OPT_POP3_IMAP4, mmi_email_hilite_prof_pop3_impa4);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDIT_OPT_SIG, mmi_email_hilite_prof_sig);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDITOR_OPT_DONE, mmi_email_hilite_prof_done);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_EDITOR_OPT_INPUT_METH, mmi_email_hilite_prof_input_meth_ext);

    /* Account Email Settings Reply-to */
    SetHiliteHandler(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_ADD, mmi_email_hilite_prof_setting_reply_to_add_opt);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_DONE, mmi_email_hilite_prof_setting_reply_to_done_opt);
    SetHiliteHandler(MENU_ID_EMAIL_PROF_SETTING_REPLY_TO_INPUT_METHOD, mmi_email_hilite_prof_input_meth);
    
    /* Signature */
    SetHiliteHandler(MENU_ID_EMAIL_SIG_ATTCH_OPT_VIEW, mmi_email_hilite_prof_sig_view);
    SetHiliteHandler(MENU_ID_EMAIL_SIG_ATTCH_OPT_SEL, mmi_email_hilite_prof_sig_select);
    SetHiliteHandler(MENU_ID_EMAIL_SIG_ATTCH_OPT_DEL, mmi_email_hilite_prof_sig_del);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_highlight_main_menu
 * DESCRIPTION
 *  Highlight handler of Email menu in Message screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_highlight_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    SetLeftSoftkeyFunction(mmi_email_main_pre_entry, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_snr
 * DESCRIPTION
 *  Highlight handler of Send And Receive option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_snr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_SNR;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp
 * DESCRIPTION
 *  Highlight handler of Write Email option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_COMP;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_inbox
 * DESCRIPTION
 *  Highlight handler of Inbox option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_inbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_INBOX;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_sent
 * DESCRIPTION
 *  Highlight handler of Sent option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_sent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_SENT;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_unsent
 * DESCRIPTION
 *  Highlight handler of Unsent option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_unsent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_UNSENT;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_draft
 * DESCRIPTION
 *  Highlight handler of Draft option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_DRAFT;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_del_all
 * DESCRIPTION
 *  Highlight handler of Delete All option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_DEL_ALL;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_del_all_mark
 * DESCRIPTION
 *  Highlight handler of Delete All Mark option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_del_all_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_DEL_ALL_MARK;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_prof
 * DESCRIPTION
 *  Highlight handler of Profile option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_PROF;
    SetLeftSoftkeyFunction(mmi_email_ps_list_acct_profile_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_ps_list_acct_profile_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_refresh
 * DESCRIPTION
 *  Highlight handler of Refresh option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_REFRESH;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_switch
 * DESCRIPTION
 *  Highlight handler of Switch Mode option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_SWITCH;
    SetLeftSoftkeyFunction(mmi_email_main_exec_lsk, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_exec_lsk, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

#define MAIN_MENU_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_pre_entry
 * DESCRIPTION
 *  Pre-entry function of Email application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->main_info.ready_state & EMAIL_READY) == EMAIL_READY)
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
        if (email_p->snr_info.is_auto_chk)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_AUTO_CHECK_BUSY_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
        else
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
        {
            if (email_p->main_info.stop_cause == EMAIL_START_REQ)
            {
                return;
            }
            if (email_p->main_info.stop_cause != EMAIL_STOP_NONE)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_ERROR_CODE_IN_USE_ID),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) WARNING_TONE);
                return;
            }
            /* set current folder and folder info request state  */
            email_p->main_info.curr_menu = MMI_EMAIL_NONE;

            email_p->main_info.main_indx = 0;

            /* if profile is not ready, then don't allow user to connect network */
            mmi_email_fldr_reset_cntx(EMAIL_RESET_ALL_FLDR);
            if (mmi_email_prof_is_activated())
            {
                email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
                /* check for imap4/pop3 */
            #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
                if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
                {
                    mmi_email_display_confirm(
                        STR_EMAIL_COMMON_DOWNLOAD_ID,
                        mmi_email_main_imap4_confirm_yes,
                        mmi_email_main_no_list_fldr);
                }
                else
            #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
                {
                    mmi_email_main_start();
                    /* email_p->mode_status.req_mode = EMAIL_MODE_ONLINE; */
                }
            }
            else
            {
                /* regarded as enter email without list folder request */
                mmi_email_main_no_list_fldr();
            }
        }
    }
    else    /* email application not ready */
    {
    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        }
        else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_SMS_PLEASE_WAIT_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
    }
}

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_imap4_confirm_yes
 * DESCRIPTION
 *  Handler when the user selects "Yes" in IMAP4 confirmation screen.
 *  Enter Email main menu with list folder request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_imap4_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    mmi_email_main_start();
    email_p->mode_status.req_mode = EMAIL_MODE_ONLINE;
}
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_no_list_fldr
 * DESCRIPTION
 *  Handler when the user selects "No" in IMAP4 confirmation screen.
 *  Enter Email main menu directly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_no_list_fldr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.fldr_update_state = EMAIL_LIST_FLDR_REQUIRED;
    mmi_email_main_start();
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    email_p->mode_status.req_mode = EMAIL_MODE_OFFLINE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_start
 * DESCRIPTION
 *  Send start request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_NORMAL;
    mmi_email_ps_start_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_back_from_history
 * DESCRIPTION
 *  Go back to Email main menu.
 *  If folder information changed, send list folder request first,
 *  otherwise, enter Email main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_back_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update email main menu only when it is not in small screen redrawing process */
    if ((email_p->fldr_info.fldr_update_state == EMAIL_LIST_FLDR_REQUIRED) && (mmi_is_redrawing_bk_screens() == 0))
    {
        email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_BACK_MAIN;
        mmi_email_ps_list_folders_req();
    }
    else
    {
        mmi_email_entry_main();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_main
 * DESCRIPTION
 *  Entry function of Email main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems = EMAIL_MAIN_MENU_TOTAL;
    U16 itemIcons[EMAIL_MAIN_MENU_TOTAL];
    U8 *nStrItemList[EMAIL_MAIN_MENU_TOTAL];
    U8 *popUpList[EMAIL_MAIN_MENU_TOTAL];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to free container buffer when back from folder list to main menu */
    mmi_email_util_free_container_pool();

    EntryNewScreen(SCR_ID_EMAIL_MAIN, mmi_email_exit_main_menu, NULL, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_MAIN);
    mmi_email_main_get_menu_detail(nStrItemList, itemIcons, popUpList);

    RegisterHighlightHandler(mmi_email_hilite_main_menu_item);

    /* hide refresh item */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_POP3))
    {
        numItems -= 2;
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    ShowCategory53Screen(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        (U8 **) nStrItemList,
        (U16*) itemIcons,
        (U8 **) popUpList,
        0,
        (S32) email_p->main_info.main_indx,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_email_main_quit_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_main_quit_email, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_MAIN, (HistoryDelCBPtr) mmi_email_main_del_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_main_menu
 * DESCRIPTION
 *  Exit function of Email main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_history(SCR_ID_EMAIL_MAIN, mmi_email_main_back_from_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_del_callback
 * DESCRIPTION
 *  Callback function when main menu is deleted.
 * PARAMETERS
 *  param       [IN]        Parameter from framework
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_email_main_del_callback(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param != (void*)MMI_TRUE)
    {
        /* do not send stop request if deinit request is sent */
        if ((email_p->main_info.ready_state & EMAIL_PS_INIT_DONE) == EMAIL_PS_INIT_DONE &&
            email_p->main_info.stop_cause == EMAIL_MODULE_ACTIVE_NOW)
        {
            email_p->main_info.stop_cause = EMAIL_STOP_BACK_FROM_OTHER;
            /* After save fail, the compose buffer is valid */
            /* mmi_email_comp_reset_member(); */
            mmi_email_ps_stop_req();
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_is_offline_notifier
 * DESCRIPTION
 *  Display offline mode warning.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_email_is_offline_notifier(void)
{
#ifdef __MMI_SLIM_EMAIL_NO_IMAP4__
    return MMI_FALSE;
#endif

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_POP3)
    {
        return MMI_FALSE;
    }
    if (email_p->mode_status.curr_mode == EMAIL_MODE_OFFLINE)
    {
        mmi_email_offline_notifier();
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_offline_notifier
 * DESCRIPTION
 *  Display offline mode warning.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_offline_notifier(void)
{
    DisplayPopup(
        (U8*) GetString(STR_EMAIL_OFFLINE_NOTIFIER_ID),
        IMG_GLOBAL_WARNING,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) WARNING_TONE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_exec_lsk
 * DESCRIPTION
 *  Execute selected item in Email menu menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_exec_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if not profile is not configured,  then user can't go enter any menu except profile */
    if (mmi_email_prof_is_activated() == FALSE)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }

    /* to reset highlight index of folder */
    email_p->fldr_info.curr_mail_indx = 0;

    /* execute current folder key handler */
    switch (email_p->main_info.curr_menu)
    {
        case MMI_EMAIL_SNR:
            if (mmi_email_is_offline_notifier())
            {
                break;
            }
            else
            {
                mmi_email_ps_snr_req();
                break;
            }
        case MMI_EMAIL_COMP:
            if (mmi_email_is_offline_notifier())
            {
                break;
            }
            else
            {
                mmi_email_comp_pre_entry();
                break;
            }
        case MMI_EMAIL_INBOX:
        case MMI_EMAIL_SENT:
        case MMI_EMAIL_UNSENT:
        case MMI_EMAIL_DRAFT:
            mmi_email_fldr_pre_entry();
            break;
        case MMI_EMAIL_DEL_ALL:
            email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_DEL_ALL;
            mmi_email_ps_list_folders_req();
            break;
        case MMI_EMAIL_DEL_ALL_MARK:
            email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_DEL_ALL_MARK;
            mmi_email_ps_list_folders_req();
            break;
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        case MMI_EMAIL_SWITCH:
            if (EMAIL_IS_MODE(EMAIL_MODE_OFFLINE))
            {
                email_p->mode_status.req_mode = EMAIL_MODE_ONLINE;
            }
            else
            {
                email_p->mode_status.req_mode = EMAIL_MODE_OFFLINE;
            }
            email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_SWITCH;
            email_p->mode_status.reset_mode = MMI_TRUE;
            mmi_email_ps_set_mode_req();
            break;
        case MMI_EMAIL_REFRESH:
            if (mmi_email_is_offline_notifier())
            {
                break;
            }
            else
            {
                email_p->fldr_info.list_fldr_cause = EMAIL_LIST_FLDR_REFRESH;
                mmi_email_ps_list_folders_req();
                break;
            }
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_get_menu_detail
 * DESCRIPTION
 *  Get detailed information to display Email main menu.
 * PARAMETERS
 *  strList             [IN]            
 *  iconList            [?]             
 *  hintList            [IN]            
 *  popUpList(?)        [IN/OUT]        Hint list of menu items
 *  itemIcons(?)        [IN/OUT]        Icon list of menu items
 *  nStrItemList(?)     [IN/OUT]        String list of menu items
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_get_menu_detail(U8 **strList, U16 *iconList, U8 **hintList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialization */
    for (i = 0; i < EMAIL_MAIN_MENU_TOTAL; i++)
    {
        strList[i] = (U8*) GetString((U16) (STR_EMAIL_SEND_AND_RECEIVE_ID + i));
        iconList[i] = IMG_EMAIL_SEND_AND_RECEIVE_ID + i;
        hintList[i] = NULL;
    }

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        /* sent folder */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sent_name))
        {
            strList[EMAIL_SENT_ENUM] = (U8*) email_p->prof_info.act_prof.sent_name;
        }

        /* draft folder */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.draft_name))
        {
            strList[EMAIL_DRAFT_ENUM] = (U8*) email_p->prof_info.act_prof.draft_name;
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    hintList[EMAIL_INBOX_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_INBOX_ENUM, MMI_EMAIL_INBOX);
    hintList[EMAIL_SENT_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_SENT_ENUM, MMI_EMAIL_SENT);
    hintList[EMAIL_UNSENT_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_UNSENT_ENUM, MMI_EMAIL_UNSENT);
    hintList[EMAIL_DRAFT_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_DRAFT_ENUM, MMI_EMAIL_DRAFT);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    hintList[EMAIL_SWITCH_MODE_ENUM] = mmi_email_util_get_mode_hint_value();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_update_hint
 * DESCRIPTION
 *  Update hint value of a folder.
 * PARAMETERS
 *  fldr_name       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_update_hint(S8 fldr_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetExitScrnID() == SCR_ID_EMAIL_MAIN)
    {
        S32 index = 0;

        switch (fldr_name)
        {
            case MMI_EMAIL_INBOX:
                index = EMAIL_INBOX_ENUM;
                break;
            case MMI_EMAIL_UNSENT:
                index = EMAIL_UNSENT_ENUM;
                break;
            case MMI_EMAIL_SENT:
                index = EMAIL_SENT_ENUM;
                break;
            case MMI_EMAIL_DRAFT:
                index = EMAIL_DRAFT_ENUM;
                break;
        }
        mmi_email_util_get_fldr_hint_value((U16) index, fldr_name);
        Category53ChangeItemDescription(index, hintData[index]);
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_main_menu_item
 * DESCRIPTION
 *  Highlight handler of main menu items
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_main_menu_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.main_indx = (U8) index;

    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    switch (index)
    {
        case EMAIL_SEND_AND_RECEIVE_ENUM:
            mmi_email_hilite_snr();
            break;
        case EMAIL_WRITE_EMAIL_ENUM:
            mmi_email_hilite_comp();
            break;
        case EMAIL_INBOX_ENUM:
            mmi_email_hilite_inbox();
            break;
        case EMAIL_SENT_ENUM:
            mmi_email_hilite_sent();
            break;
        case EMAIL_UNSENT_ENUM:
            mmi_email_hilite_unsent();
            break;
        case EMAIL_DRAFT_ENUM:
            mmi_email_hilite_draft();
            break;
        case EMAIL_DELETE_ALL_ENUM:
            mmi_email_hilite_del_all();
            break;
        case EMAIL_DELETE_ALL_MARK_ENUM:
            mmi_email_hilite_del_all_mark();
            break;
        case EMAIL_EMAIL_PROFILE_ENUM:
            mmi_email_hilite_prof();
            break;
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        case EMAIL_SWITCH_MODE_ENUM:
            mmi_email_hilite_switch();
            break;
        case EMAIL_REFRESH_ENUM:
            mmi_email_hilite_refresh();
            break;
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    
    #if defined(__MMI_EMAIL_TEMPLATE__)
        case EMAIL_TEMPLATE_ENUM:
            mmi_email_hilite_template();
            break;
    #endif /* defined(__MMI_EMAIL_TEMPLATE__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_goto_idle
 * DESCRIPTION
 *  Stop email application and go to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_goto_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_QUITING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);

    email_p->main_info.stop_cause = EMAIL_STOP_GOTO_IDLE;
    mmi_email_ps_stop_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_quit_email
 * DESCRIPTION
 *  Quit email application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_quit_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.stop_cause = EMAIL_STOP_BACK_HIST;
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_QUITING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
    mmi_email_ps_stop_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_quit_to_app
 * DESCRIPTION
 *  Quit email application and go back to previous application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_quit_to_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.stop_cause = EMAIL_STOP_BACK_FROM_OTHER;
    mmi_email_ps_stop_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_main_quit_to_app_ext
 * DESCRIPTION
 *  Quit email application and go back to previous application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_main_quit_to_app_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_QUITING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
    email_p->main_info.stop_cause = EMAIL_STOP_BACK_FROM_OTHER;
    mmi_email_ps_stop_req();
}


#define COMMON_SCR_UTIL_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_pre_entry_progressing
 * DESCRIPTION
 *  Pre-entry function for progressing screen
 * PARAMETERS
 *  strCaption      [IN]        
 *  imgCaption      [IN]        
 *  strLsk          [IN]        
 *  imgLsk          [IN]        
 *  strRsk          [IN]        
 *  imgRsk          [IN]        
 *  strBody1        [?]         
 *  strBody2        [?]         
 *  imgBody         [IN]        
 *  lskFuncPtr      [IN]        
 *  rskFuncPtr      [IN]        
 *  endFuncPtr      [IN]        
 *  leftAlign       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_pre_entry_progressing(
        U16 strCaption,
        U16 imgCaption,
        U16 strLsk,
        U16 imgLsk,
        U16 strRsk,
        U16 imgRsk,
        U8 *strBody1,
        U8 *strBody2,
        U16 imgBody,
        FuncPtr lskFuncPtr,
        FuncPtr rskFuncPtr,
        FuncPtr endFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.progress_info.strCaption = strCaption;
    email_p->misc_info.progress_info.imgCaption = imgCaption;
    email_p->misc_info.progress_info.strLsk = strLsk;
    email_p->misc_info.progress_info.imgLsk = imgLsk;
    email_p->misc_info.progress_info.strRsk = strRsk;
    email_p->misc_info.progress_info.imgRsk = imgRsk;
    email_p->misc_info.progress_info.strBody1 = strBody1;
    email_p->misc_info.progress_info.strBody2 = strBody2;
    email_p->misc_info.progress_info.imgBody = imgBody;
    email_p->misc_info.progress_info.lskFuncPtr = lskFuncPtr;
    email_p->misc_info.progress_info.rskFuncPtr = rskFuncPtr;
    email_p->misc_info.progress_info.endFuncPtr = endFuncPtr;

    if (mmi_email_util_is_call_interrupt_allow())
    {
        mmi_email_entry_progressing();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_progressing
 * DESCRIPTION
 *  Common entry function for all progressing screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 *show_string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_PROGRESS, mmi_email_exit_progressing, NULL, NULL);

    mmi_email_util_clear_end_key_hdlr();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_PROGRESS);

    if (email_p->misc_info.progress_info.strBody2 == NULL)
    {
        show_string = (S8*)email_p->misc_info.progress_info.strBody1;
    }
    else
    {
        S32 string1_len = mmi_ucs2strlen((S8*)email_p->misc_info.progress_info.strBody1);
        S32 string2_len = mmi_ucs2strlen((S8*)email_p->misc_info.progress_info.strBody2);
        S8 new_line[5];

        show_string = OslMalloc((string1_len + string2_len) * ENCODING_LENGTH + 6);
        memset(show_string, 0, ((string1_len + string2_len) * ENCODING_LENGTH + 6));
        mmi_asc_to_ucs2(new_line, "\r\n");
        mmi_ucs2cpy((S8*)show_string, (S8*)email_p->misc_info.progress_info.strBody1);
        mmi_ucs2cat((S8*)show_string, new_line);
        mmi_ucs2cat((S8*)show_string, (S8*)email_p->misc_info.progress_info.strBody2);
    }

    ShowCategory66Screen(
        email_p->misc_info.progress_info.strCaption,
        email_p->misc_info.progress_info.imgCaption,
        email_p->misc_info.progress_info.strLsk,
        email_p->misc_info.progress_info.imgLsk,
        email_p->misc_info.progress_info.strRsk,
        email_p->misc_info.progress_info.imgRsk,
        (U8*)show_string,
        email_p->misc_info.progress_info.imgBody,
        guiBuffer);

    SetLeftSoftkeyFunction(email_p->misc_info.progress_info.lskFuncPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(email_p->misc_info.progress_info.rskFuncPtr, KEY_EVENT_UP);
    if (email_p->misc_info.progress_info.endFuncPtr)
    {
        SetKeyHandler(email_p->misc_info.progress_info.endFuncPtr, KEY_END, KEY_EVENT_DOWN);
    }
    if (email_p->misc_info.progress_info.strBody2 != NULL)
    {
        OslMfree(show_string);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_progressing
 * DESCRIPTION
 *  Common exit function for all progressing screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!IsScreenPresent(SCR_ID_EMAIL_PROGRESS))
    {
        mmi_email_util_add_history(SCR_ID_EMAIL_PROGRESS, mmi_email_entry_progressing);
    }
}

#define SEND_N_RECV_EMAIL

/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_snr_detail
 * DESCRIPTION
 *  Entry detailed result screen of send and receive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_snr_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 snr_icons[EMAIL_REPORT_TOTAL_ITEM] = 
    {
        IMG_EMAIL_SENT_CAPTION_REPORT_ID, 0,
        IMG_EMAIL_RECEIVED_CAPTION_REPORT_ID, 0
    };

    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_email_util_is_call_interrupt_allow())
    {
        return;
    }
    EntryNewScreen(SCR_ID_EMAIL_SNR_DETAIL, mmi_email_exit_snr_detail, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_SNR_DETAIL);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_SNR_DETAIL, &inputBufferSize);

    InitializeCategory57Screen();
    mmi_email_snr_fill_inline_struct();

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_REPORT_TOTAL_ITEM, inputBuffer);
    }

    ShowCategory57Screen(
        STR_EMAIL_COMMON_DETAILS_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_REPORT_TOTAL_ITEM,
        (U16*) snr_icons,
        wgui_inline_items,
        0,
        guiBuffer);
    SetCategory57RightSoftkeyFunctions(NULL, mmi_email_snr_back_from_result);
    SetKeyHandler(mmi_email_snr_back_from_result, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_snr_detail
 * DESCRIPTION
 *  Exit detailed result screen of send and receive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_snr_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_n_history(SCR_ID_EMAIL_SNR_DETAIL, mmi_email_entry_snr_detail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_snr_fill_inline_struct
 * DESCRIPTION
 *  Fill inline structure for Detailed screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_snr_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    U8 *ansiiTempBuff = OslMalloc(EMAIL_MAX_SNR_RESULT_LEN * ENCODING_LENGTH);
    U8 *ucs2TempBuff = OslMalloc(EMAIL_MAX_SNR_RESULT_LEN * ENCODING_LENGTH);
    S8 ucs2ComaBuff[] = { ',', '\0', ' ', '\0', '\0', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sent string */
    sprintf((S8*) ansiiTempBuff, "%u/%u ", email_p->snr_info.num_sent, email_p->snr_info.num_to_be_sent);
    len = strlen((S8*) ansiiTempBuff);
    mmi_asc_n_to_ucs2((S8*) ucs2TempBuff, (S8*) ansiiTempBuff, len);
    ucs2TempBuff[len * ENCODING_LENGTH] = '\0';
    ucs2TempBuff[len * ENCODING_LENGTH + 1] = '\0';

    mmi_ucs2cpy((S8*) email_p->snr_info.sent_buff, (S8*) ucs2TempBuff);
    mmi_ucs2cat((S8*) email_p->snr_info.sent_buff, (S8*) GetString(STR_EMAIL_MAILS_ID));
    if (email_p->snr_info.sent_err_str)
    {
        mmi_ucs2cat((S8*) email_p->snr_info.sent_buff, (S8*) ucs2ComaBuff);
        mmi_ucs2cat((S8*) email_p->snr_info.sent_buff, (S8*) GetString(email_p->snr_info.sent_err_str));
    }

    /* received string */
    sprintf((S8*) ansiiTempBuff, "%u/%u ", email_p->snr_info.num_recv, email_p->snr_info.num_to_be_recv);
    len = strlen((S8*) ansiiTempBuff);
    mmi_asc_n_to_ucs2((S8*) ucs2TempBuff, (S8*) ansiiTempBuff, len);
    ucs2TempBuff[len * ENCODING_LENGTH] = '\0';
    ucs2TempBuff[len * ENCODING_LENGTH + 1] = '\0';

    mmi_ucs2cpy((S8*) email_p->snr_info.recv_buff, (S8*) ucs2TempBuff);
    mmi_ucs2cat((S8*) email_p->snr_info.recv_buff, (S8*) GetString(STR_EMAIL_MAILS_ID));
    if (email_p->snr_info.recv_err_str)
    {
        mmi_ucs2cat((S8*) email_p->snr_info.recv_buff, (S8*) ucs2ComaBuff);
        mmi_ucs2cat((S8*) email_p->snr_info.recv_buff, (S8*) GetString(email_p->snr_info.recv_err_str));
    }

    /* sent caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_REPORT_SENT_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_REPORT_SENT_CAP], (U8*) GetString(STR_EMAIL_COMMON_SENT_ID));

    /* sent result */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_REPORT_SENT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(&wgui_inline_items[EMAIL_REPORT_SENT], (U8*) email_p->snr_info.sent_buff);

    /* received caption */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_REPORT_RECV_CAP], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemCaption(&wgui_inline_items[EMAIL_REPORT_RECV_CAP], (U8*) GetString(STR_EMAIL_RECEIVED_ID));

    /* received result */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_REPORT_RECV], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly((&wgui_inline_items[EMAIL_REPORT_RECV]), (U8*) email_p->snr_info.recv_buff);

    OslMfree(ansiiTempBuff);
    OslMfree(ucs2TempBuff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_snr_back_from_result
 * DESCRIPTION
 *  Back from Detail Result screen to Email main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_snr_back_from_result(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&email_p->snr_info, 0, sizeof(mmi_email_snr_info_struct));
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    GoBackHistory();
}

#define WRITE_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_addr_add
 * DESCRIPTION
 *  Highlight handler of Write Email->To/CC->Add option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_addr_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_addr_pre_add, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_addr_pre_add, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_addr_edit
 * DESCRIPTION
 *  Highlight handler of Write Email->To/CC->Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_addr_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_addr_pre_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_addr_pre_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_addr_del
 * DESCRIPTION
 *  Highlight handler of Write Email->To/CC->Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_addr_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_addr_del, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_addr_del, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_addr_del_all
 * DESCRIPTION
 *  Highlight handler of Write Email->To/CC->Delete All option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_addr_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_addr_del_all, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_addr_del_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_subj_done
 * DESCRIPTION
 *  Highlight handler of Done option in full screen editor of Write Email->Subject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_subj_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_subj_cont_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_subj_cont_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_subj_input_meth
 * DESCRIPTION
 *  Highlight handler of Input Method option in full screen editor of Write Email->Subject
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_subj_input_meth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_email_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_addr_done
 * DESCRIPTION
 *  Highlight handler of Done option in full screen editor of
 *  Write Email->To/CC-> Option -> Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_addr_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_addr_input_done, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_addr_input_done, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_addr_input_meth
 * DESCRIPTION
 *  Highlight handler of Input Method option in full screen editor of Write Email->To/CC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_addr_input_meth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryAPRequiredInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryAPRequiredInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_email_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_attach_edit
 * DESCRIPTION
 *  Highlight handler of Write Email->Attachment->Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_attach_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_add_attach, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_add_attach, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_attach_view
 * DESCRIPTION
 *  Highlight handler of Write Email->Attachment->View option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_attach_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_pre_entry_view_attach, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_pre_entry_view_attach, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_attach_del
 * DESCRIPTION
 *  Highlight handler of Write Email->Attachment->Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_attach_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_attch_del, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_attch_del, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_send
 * DESCRIPTION
 *  Highlight handler of Write Email->Send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_ps_send_only_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_ps_send_only_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_save_n_send
 * DESCRIPTION
 *  Highlight handler of Write Email->Save and Send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_save_n_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_ps_save_and_send_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_ps_save_and_send_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_save_to_draft
 * DESCRIPTION
 *  Highlight handler of Write Email->Save To Draft option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_save_to_draft(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_ps_save_to_draft_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_ps_save_to_draft_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_quit
 * DESCRIPTION
 *  Highlight handler of Write Email->Quit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_comp_opt_quit, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_comp_opt_quit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_pre_entry
 * DESCRIPTION
 *  Pre-Entry function of Write Email screen.
 *  Reset attachment and add siganture if the mail is not composed yet.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if previous-written mail is not sent/saved */
    if (!mmi_email_comp_get_done_status())
    {
        /* default attach info */
        mmi_email_comp_reset_member();
        /* put signature in the third attachment */
        if (mmi_email_comp_add_sig() == FALSE)
        {
            return;
        }
        /* entry Write Email screen after signature copy complete */
    }

    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_add_sig
 * DESCRIPTION
 *  Add signature attachment into Write Email screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if the called can entry Write Email screen directly; otherwise, FALSE.
 *****************************************************************************/
BOOL mmi_email_comp_add_sig(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->prof_info.act_prof.sig_status) /* if signature is on, insert into Write Email screen */
    {
        /* signature text */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sig_buff))
        {
            /* copy text data with new line char */
            mmi_ucs2cat((S8*) email_p->comp_info.cont_buff, (S8*) g_email_new_line);
            mmi_ucs2cat((S8*) email_p->comp_info.cont_buff, (S8*) email_p->prof_info.act_prof.sig_buff);
        }

        /* image */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sig_img))
        {
            S8 *fileExt;
            S8 *tmp_file = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

            /* insert image to the last slot of attachments */
            S32 i = (MMI_EMAIL_MAX_NUM_ATTACH - 1);

            /* file extension */
            fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.act_prof.sig_img);

            /* delete the original useless file */
            if (mmi_ucs2strlen((PS8)email_p->comp_info.attch_list[i].file_path) != 0)
            {
                mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[i].file_path);
                ret = FS_Delete((U16*) email_p->comp_info.attch_list[i].file_path);
                if (ret < FS_NO_ERROR)
                {
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ADD_SIG_DELETE_FILE, ret);
                }
            }
            /* destination file name */
            mmi_email_util_get_comp_attch_name((U8) (i + 1), (S8*) email_p->comp_info.attch_list[i].file_path);
            mmi_ucs2cat((S8*) email_p->comp_info.attch_list[i].file_path, (S8*) fileExt);

            /* source file name */
            mmi_email_util_get_sig_name((U8) (email_p->prof_info.act_prof.act_indx + 1), (S8*) tmp_file);
            mmi_ucs2cat((S8*) tmp_file, (S8*) fileExt);
            mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) tmp_file);

            if ((ret = mmi_email_util_check_file_exist((S8*) email_p->comm_buff)) != FS_NO_ERROR)
            {
                email_p->comp_info.except_popup |= EMAIL_EXCEPT_SIG_FAILED;
                OslMfree(tmp_file);
                return TRUE;
            }

            email_p->misc_info.file_copy_state = EMAIL_FILE_ADD_SIG;

            /* delete the same name file */
            mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[i].file_path);
            FS_Delete((U16*) email_p->comp_info.attch_list[i].file_path);
            mmi_fmgr_send_copy_req(
                FMGR_ACTION_COPY,
                (U8*) email_p->comm_buff,
                (U8*) email_p->comp_info.attch_list[i].file_path,
                mmi_email_comp_attach_copy_callback);

            OslMfree(tmp_file);
            mmi_email_pre_entry_progressing(
                STR_EMAIL_MAIN_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                0,
                0,
                (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
                (U8*) NULL,
                IMG_GLOBAL_PROGRESS,
                NULL,
                NULL,
                NULL);
            DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
            return FALSE;
        }
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_reset_member
 * DESCRIPTION
 *  Reset variables of Write Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_reset_member(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete the original useless file */
    for (i = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
    {
        if (mmi_ucs2strlen((PS8)email_p->comp_info.attch_list[i].file_path) != 0)
        {
            mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[i].file_path);
            ret = FS_Delete((U16*) email_p->comp_info.attch_list[i].file_path);
            if (ret < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_RESET_MEMBER_DELETE_FILE, ret);
            }
        }
    }
    memset(&email_p->comp_info, 0, sizeof(mmi_email_comp_info_struct));
    memset(&email_p->compose_size, 0, sizeof(email_msg_info_struct));
    email_p->misc_info.curr_hilite_attch = 0;

    /* set <Empty> string for all attachments */
    for (i = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
    {
        mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[i].file_name, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        email_p->comp_info.attch_list[i].ch_set = MMI_CHSET_UTF8;
    }
    email_p->misc_info.temp_priority_indx = 0;

    reset_inscreen_multi_line_input_box_changed();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp
 * DESCRIPTION
 *  Entry function of Write Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    U16 comp_icons[EMAIL_COMP_TOTAL] = 
    {
        IMG_EMAIL_TO_ID,
        IMG_EMAIL_CC_ID,
    #ifdef __MMI_EMAIL_BCC__
        IMG_EMAIL_BCC_ID,
    #endif
        IMG_EMAIL_SUBJECT_ID,
        IMG_EMAIL_ATTACHMENT_ID,
        IMG_EMAIL_PRIORITY_ID,
        0
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP, mmi_email_exit_comp, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_COMP, &inputBufferSize);
    InitializeCategory57Screen();
    mmi_email_comp_fill_inline_struct();
    RegisterHighlightHandler(mmi_email_hilite_comp_inline_item);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_COMP_TOTAL, inputBuffer);
    }
    SetHighlightedAttachment(&wgui_inline_items[EMAIL_COMP_ATTCH], email_p->misc_info.curr_hilite_attch);

    /* fill attachment images */
    mmi_email_comp_fill_attach();

    if ((email_p->comp_info.except_popup & EMAIL_EXCEPT_ATT_EXCEED) == EMAIL_EXCEPT_ATT_EXCEED)
    {
        email_p->comp_info.curr_inline_item = EMAIL_COMP_ATTCH;
    }
    else if ((email_p->comp_info.except_popup & EMAIL_EXCEPT_CON_EXCEED) == EMAIL_EXCEPT_CON_EXCEED)
    {
        email_p->comp_info.curr_inline_item = EMAIL_COMP_CONT;
    }

    ShowCategory57Screen(
        STR_EMAIL_TO_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_EDIT,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_COMP_TOTAL,
        (U16*) comp_icons,
        wgui_inline_items,
        email_p->comp_info.curr_inline_item,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_email_comp_rsk_handler, mmi_email_comp_back_to_hist);

    /* display "message too long!" only if "content" is truncated, due to memory limitation */
    if ((email_p->comp_info.except_popup & EMAIL_EXCEPT_ATT_EXCEED) == EMAIL_EXCEPT_ATT_EXCEED)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    else if ((email_p->comp_info.except_popup & EMAIL_EXCEPT_CON_EXCEED) == EMAIL_EXCEPT_CON_EXCEED)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_CONTENT_MESSAGE_TOO_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    else if ((email_p->comp_info.except_popup & EMAIL_EXCEPT_SIG_FAILED) == EMAIL_EXCEPT_SIG_FAILED)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_SIG_ADD_FAIL_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
    email_p->comp_info.except_popup = EMAIL_EXCEPT_NORMAL;
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    if (drm_file_ignore)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_DRM_FILE_IGNORE_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        drm_file_ignore = FALSE;
    }
#endif

    /* forward an attachment from file manager and plug-out memory card will directly go to file manager main screen 
       without sending stop_req to email, which will cause email serious problem.
       therefore, if SCR_ID_EMAIL_COMP is deleted from history, email should send stop_req */
    if (email_p->main_info.entry_src == EMAIL_FROM_APP)
    {
        SetDelScrnIDCallbackHandler(SCR_ID_EMAIL_COMP, (HistoryDelCBPtr) mmi_email_main_del_callback);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_comp
 * DESCRIPTION
 *  Exit function of Write Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_comp_get_done_status())
    {
        mmi_email_ps_compose_size_req();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_comp
 * DESCRIPTION
 *  Exit function of Write Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_comp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_n_history(SCR_ID_EMAIL_COMP, mmi_email_entry_comp);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_back_to_hist
 * DESCRIPTION
 *  Go back from Write Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_back_to_hist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->main_info.entry_src != EMAIL_FROM_APP)
    {
        GoBackHistory();
    }
    else
    {
        mmi_email_main_quit_email();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_inline_item_changer
 * DESCRIPTION
 *  Notify the changes of priority
 * PARAMETERS
 *  index       [IN]        the index of now
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_inline_item_changer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((!email_p->comp_info.done_flag) && (email_p->comp_info.priority_indx != index))
    {
        email_p->comp_info.done_flag = MMI_TRUE;
    }
    email_p->comp_info.priority_indx = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_fill_inline_struct
 * DESCRIPTION
 *  Fill inline struct for Write Email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Priority */
    email_p->misc_info.priority_list[0] = (U8*) GetString(STR_EMAIL_PRIORITY_MEDIUM_ID);
    email_p->misc_info.priority_list[1] = (U8*) GetString(STR_EMAIL_PRIORITY_LOW_ID);
    email_p->misc_info.priority_list[2] = (U8*) GetString(STR_EMAIL_PRIORITY_HIGH_ID);

    /* TO */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_TO], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[EMAIL_COMP_TO]),
        (U8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
        (PU8) GetImage(IMG_EMAIL_TO_ID),
        (PU8) GetImage(IMG_EMAIL_LEFT_BRACKET_ID),
        (PU8) GetImage(IMG_EMAIL_RIGHT_BRACKET_ID),
        sizeof(email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_TO]),
        STR_EMAIL_TO_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[EMAIL_COMP_TO]), mmi_email_comp_pre_entry_addr);
    ShowAsControl(&(wgui_inline_items[EMAIL_COMP_TO]));

    /* CC */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_CC], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[EMAIL_COMP_CC]),
        (U8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC],
        (PU8) GetImage(IMG_EMAIL_CC_ID),
        (PU8) GetImage(IMG_EMAIL_LEFT_BRACKET_ID),
        (PU8) GetImage(IMG_EMAIL_RIGHT_BRACKET_ID),
        sizeof(email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC]),
        STR_EMAIL_CC_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[EMAIL_COMP_CC]), mmi_email_comp_pre_entry_addr);
    ShowAsControl(&(wgui_inline_items[EMAIL_COMP_CC]));

#ifdef __MMI_EMAIL_BCC__
    /* BCC */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_BCC], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[EMAIL_COMP_BCC]),
        (U8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_BCC],
        (PU8) GetImage(IMG_EMAIL_BCC_ID),
        (PU8) GetImage(IMG_EMAIL_LEFT_BRACKET_ID),
        (PU8) GetImage(IMG_EMAIL_RIGHT_BRACKET_ID),
        sizeof(email_p->comp_info.addr_disp_buff[EMAIL_ADDR_BCC]),
        STR_EMAIL_BCC_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[EMAIL_COMP_BCC]), mmi_email_comp_pre_entry_addr);
    ShowAsControl(&(wgui_inline_items[EMAIL_COMP_BCC]));
#endif

    /* SUBJECT */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_SUBJ], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[EMAIL_COMP_SUBJ]),
        (U8*) email_p->comp_info.subj_buff,
        (PU8) GetImage(IMG_EMAIL_SUBJECT_ID),
        (PU8) GetImage(IMG_EMAIL_LEFT_BRACKET_ID),
        (PU8) GetImage(IMG_EMAIL_RIGHT_BRACKET_ID),
        (EMAIL_COMP_SUBJ_LEN + 1),
        STR_EMAIL_SUBJECT_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[EMAIL_COMP_SUBJ]), mmi_email_entry_comp_subj);
    ShowAsControl(&(wgui_inline_items[EMAIL_COMP_SUBJ]));

    /* ATTACHMENT */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_ATTCH], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageAttachment(
        &wgui_inline_items[EMAIL_COMP_ATTCH],
        (PU8) GetImage(IMG_EMAIL_ATTACHMENT_ID),
        (PU8) GetImage(IMG_EMAIL_LEFT_BRACKET_ID),
        (PU8) GetImage(IMG_EMAIL_RIGHT_BRACKET_ID),
        STR_EMAIL_ATTACHMENT_ID,
        0,
        email_p->misc_info.curr_hilite_attch);
    RegisterAttachmentHighlightedFunction(&wgui_inline_items[EMAIL_COMP_ATTCH], mmi_email_hilite_comp_attch);
    RegisterAttachmentLskFunction(&wgui_inline_items[EMAIL_COMP_ATTCH], mmi_email_comp_attach_lsk_func);
    RegisterAttachmentRskFunction(&wgui_inline_items[EMAIL_COMP_ATTCH], mmi_email_comp_attach_rsk_func);

    /* PRIORITY */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_PRIOTRIY], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_PRIOTRIY], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[EMAIL_COMP_PRIOTRIY],
        EMAIL_MAX_PRIORITY_ITEM,
        email_p->misc_info.priority_list,
        &email_p->misc_info.temp_priority_indx);
    ShowAsControl(&(wgui_inline_items[EMAIL_COMP_PRIOTRIY]));
    RegisterInlineSelectHighlightHandler(&wgui_inline_items[EMAIL_COMP_PRIOTRIY], mmi_email_comp_inline_item_changer);

    /* CONTENT */
    SetInlineItemActivation(&wgui_inline_items[EMAIL_COMP_CONT], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineMultiLineRdOnly(
        &wgui_inline_items[EMAIL_COMP_CONT],
        (U8*) email_p->comp_info.cont_buff,
        mmi_ucs2strlen((S8*) email_p->comp_info.cont_buff),
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        7);
    DisableInlineItemHighlight(&wgui_inline_items[EMAIL_COMP_CONT]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_change_rsk
 * DESCRIPTION
 *  Change right soft key according to current state of inline editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_change_rsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_comp_get_done_status())
    {
        ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
        SetRightSoftkeyFunction(mmi_email_comp_rsk_handler, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_compose_size_goback_history
 * DESCRIPTION
 *  Go back to write email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_compose_size_goback_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_get_done_status
 * DESCRIPTION
 *  Pre-Entry function of Write Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_email_comp_get_done_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->comp_info.done_flag == FALSE)
    {
        if (email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr ||
            email_p->comp_info.addr_list[EMAIL_ADDR_CC].num_addr ||
        #ifdef __MMI_EMAIL_BCC__
            email_p->comp_info.addr_list[EMAIL_ADDR_BCC].num_addr ||
        #endif /*__MMI_EMAIL_BCC__*/
            email_p->comp_info.total_attch ||
            mmi_ucs2strlen((S8*) email_p->comp_info.subj_buff) ||
            (email_p->comp_info.priority_indx != 0) ||
            mmi_ucs2strlen((S8*) email_p->comp_info.cont_buff))
        {
            email_p->comp_info.done_flag = TRUE;
        }
    }
    return email_p->comp_info.done_flag;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_fill_attach
 * DESCRIPTION
 *  Fill image of attachments to Write Email screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_fill_attach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
    {
        if (email_p->comp_info.attch_list[i].attch_present)
        {
            img_id = mmi_email_util_get_attch_icon((S8*) email_p->comp_info.attch_list[i].file_path);
        }
        else
        {
            img_id = IMG_EMAIL_BALNK_ID;
        }

        email_p->comp_info.attch_icon[i].image1 = (PU8) GetImage(img_id);
    }

    /* update to UI */
#ifdef __MMI_EMAIL_BCC__ 
    AddEmailImageAttachmentUI(&wgui_inline_items[EMAIL_COMP_ATTCH], (wgui_inline_images_detail*) email_p->comp_info.attch_icon);
#else
    AddEmailImageAttachmentUI(&wgui_inline_items[3], (wgui_inline_images_detail*) email_p->comp_info.attch_icon);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_attach_lsk_func
 * DESCRIPTION
 *  Left soft key function of attachment component in Write Email screen.
 * PARAMETERS
 *  image       [IN]        Currently no use
 *  str         [IN]        Currently no use
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_attach_lsk_func(PU8 image, UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_entry_comp_attch();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_attach_rsk_func
 * DESCRIPTION
 *  Right soft key function of attachment component in Write Email screen.
 * PARAMETERS
 *  image       [IN]        Currently no use
 *  str         [IN]        Currently no use
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_attach_rsk_func(PU8 image, UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_inline_item
 * DESCRIPTION
 *  Highlight handler of Write Email screen
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_inline_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->comp_info.curr_inline_item = (U8) index;
    email_p->comp_info.curr_addr_type = EMAIL_ADDR_NONE;

    switch (email_p->comp_info.curr_inline_item)
    {
        case EMAIL_COMP_TO:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_TO;
            mmi_email_util_change_title(STR_EMAIL_TO_ID);
            SetKeyHandler(mmi_email_comp_pre_entry_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case EMAIL_COMP_CC:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_CC;
            mmi_email_util_change_title(STR_EMAIL_CC_ID);
            SetKeyHandler(mmi_email_comp_pre_entry_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
    #ifdef __MMI_EMAIL_BCC__
        case EMAIL_COMP_BCC:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_BCC;
            mmi_email_util_change_title(STR_EMAIL_BCC_ID);
            SetKeyHandler(mmi_email_comp_pre_entry_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
    #endif
        case EMAIL_COMP_SUBJ:
            mmi_email_util_change_title(STR_EMAIL_SUBJECT_ID);
            mmi_ucs2cpy((S8*) email_p->misc_info.subj_inline_buff, (S8*) email_p->comp_info.subj_buff);
            SetKeyHandler(mmi_email_entry_comp_subj, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case EMAIL_COMP_CONT:
            mmi_email_util_change_title(STR_EMAIL_CONTENT_ID);
            ChangeLeftSoftkey(STR_GLOBAL_EDIT, IMG_GLOBAL_OK);
            mmi_ucs2cpy((S8*) email_p->misc_info.cont_inline_buff, (S8*) email_p->comp_info.cont_buff);
            SetLeftSoftkeyFunction(mmi_email_entry_comp_cont, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_entry_comp_cont, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        case EMAIL_COMP_ATTCH:
            mmi_email_util_change_title(STR_EMAIL_ATTACHMENT_ID);
            break;
        default:    /* case EMAIL_COMP_PRIOTRIY:  */
            mmi_email_util_change_title(STR_EMAIL_PRIORITY_ID);
            break;
    }

    mmi_email_comp_change_rsk();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_subj_opt
 * DESCRIPTION
 *  Entry function of subject option for full screen editor.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_subj_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only done and input method */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_SUBJ_INPUT_OPT, NULL, mmi_email_entry_comp_subj_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_SUBJ_INPUT_OPT);
    SetParentHandler(MENU_ID_EMAIL_COMP_SUBJ_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_COMP_SUBJ_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_COMP_SUBJ_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_add_attach
 * DESCRIPTION
 *  Enter file manager to select an file to attach
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_add_attach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_ALL(&filter);
    mmi_fmgr_select_path_and_enter(
        APP_EMAIL,
#ifdef __DRM_V02__
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT | FMGR_SELECT_ARCHIVE,
#else
        FMGR_SELECT_FILE | FMGR_SELECT_REPEAT,
#endif
        filter,
        (S8*) L"root",
        mmi_email_comp_add_attach_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_add_attach_callback
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        Path and name of selected file
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_add_attach_callback(void *filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 dirLen;
    S8 *fileName = (S8*) filePath;        
    S32 origLen;
    S32 fileLen;
    S32 f_result, ret = 0;
    S8 *fileExt;
    S8 i = email_p->misc_info.curr_hilite_attch;
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    UI_character_type mp3_str[8];
    UI_character_type mp2_str[8];
#endif
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    U8 mime_type, mime_subtype;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_EMAIL_COMP_ATTCH);
    }
    else
    {
#ifdef __MMI_EMAIL_DRM_SUPPORT__    
        mmi_email_util_get_mine_type(
            (S8*) filePath,
            &mime_type,
            &mime_subtype);
        if ((mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) || (DRM_interdev_movable(0, (kal_wchar*)filePath) == MMI_FALSE))
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }
        mmi_email_drm_is_file_lock((PS8)filePath, (BOOL*)&(email_p->comp_info.attch_list[i].drm.is_valid));
#endif
        if ((f_result = mmi_email_util_get_file_size((S8*) filePath, &fileLen)) == FS_NO_ERROR)
        {
            if (email_p->comp_info.attch_list[i].attch_present == TRUE)
            {
                /* calculate original file size */
                mmi_email_util_get_file_size((S8*) email_p->comp_info.attch_list[i].file_path, &origLen);
            }
            else
            {
                origLen = 0;
            }
            
            if (fileLen == 0)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_EMPTY_FILE_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                return;
            }
            /* ensure previous total attachment size + current attachment size no greater than 90K */
            else if (email_p->comp_info.total_attch_size - origLen + fileLen > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                return;
            }
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString((U16) GetFileSystemErrorString(f_result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            DeleteUptoScrID(SCR_ID_EMAIL_COMP_ATTCH);
            return;
        }

        /* delete the original useless file */
        if (mmi_ucs2strlen((PS8)email_p->comp_info.attch_list[i].file_path) != 0)
        {
            mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[i].file_path);
            ret = FS_Delete((U16*) email_p->comp_info.attch_list[i].file_path);
            if (ret < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ADD_ATTACH_CALLBACK_DELETE_FILE, ret);
            }
        }

        /* proceed adding attachment */
        if (email_p->other_app_info.fmgr_path == NULL)
        {
            email_p->other_app_info.fmgr_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        }
        mmi_ucs2cpy((S8*) email_p->other_app_info.fmgr_path, (S8*) filePath);
        /* extract file name and path */
        dirLen = (S32) mmi_fmgr_get_last_dir_index((S8*) email_p->other_app_info.fmgr_path);
        fileName = (S8*) email_p->other_app_info.fmgr_path;
        fileName += dirLen;
        
        /* file extension */
        fileExt = mmi_email_get_file_ext((S8*) email_p->other_app_info.fmgr_path);
        if (is_short)
        {
            S8* fmgr_name = OslMalloc((FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
            U8 encoding = PhnsetGetDefEncodingType();
            
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) fmgr_name,
                FMGR_PATH_BUFFER_SIZE,
                (U8*) fileName,
                (mmi_chset_enum)encoding);
            mmi_ucs2cpy(fileName, fmgr_name);
            OslMfree(fmgr_name);
        }

        /* destination file name */
        mmi_email_util_get_comp_attch_name((U8) (i + 1), (S8*) email_p->comp_info.attch_list[i].file_path);
        mmi_ucs2cat((S8*) email_p->comp_info.attch_list[i].file_path, (S8*) fileExt);
#ifndef __MMI_SHOW_DAF_FILE_EXT__
        mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
        mmi_asc_to_ucs2((S8*) mp2_str, ".mp2");
        if ((fileExt != NULL) && ((mmi_ucs2icmp(fileExt, (S8*)mp3_str) == 0)))
        {
            S32 ext_len, name_len;

            name_len = mmi_ucs2strlen((S8*) fileName);
            ext_len = mmi_ucs2strlen(fileExt);
            kal_mem_set(&email_p->comp_info.attch_list[i].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
            mmi_ucs2ncpy((S8*) email_p->comp_info.attch_list[i].file_name, fileName, name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
            if (email_p->comp_info.attch_list[i].drm.is_valid)
            {
                email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_APPLICATION;
                email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
                email_p->comp_info.attch_list[i].drm.mime_type = MIME_TYPE_AUDIO;
                email_p->comp_info.attch_list[i].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP3;
            }
            else
#endif
            {
                email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_AUDIO;
                email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_AUDIO_MP3;
            }
        }
        else if ((fileExt != NULL) && ((mmi_ucs2icmp(fileExt, (S8*)mp2_str) == 0)))
        {
            S32 ext_len, name_len;
            
            name_len = mmi_ucs2strlen((S8*) fileName);
            ext_len = mmi_ucs2strlen(fileExt);
            kal_mem_set(&email_p->comp_info.attch_list[i].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
            mmi_ucs2ncpy((S8*) email_p->comp_info.attch_list[i].file_name, fileName, name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
            if (email_p->comp_info.attch_list[i].drm.is_valid)
            {
                email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_APPLICATION;
                email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
                email_p->comp_info.attch_list[i].drm.mime_type = MIME_TYPE_AUDIO;
                email_p->comp_info.attch_list[i].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP2;
            }
            else
#endif
            {
                email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_AUDIO;
                email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_AUDIO_MP2;
            }
        }
        else
#endif
        {
            mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[i].file_name, (S8*) fileName);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
            if (email_p->comp_info.attch_list[i].drm.is_valid)
            {
                email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_APPLICATION;
                email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
                mmi_email_util_get_mine_type(
                    (S8*) email_p->comp_info.attch_list[i].file_name,
                    &email_p->comp_info.attch_list[i].drm.mime_type,
                    &email_p->comp_info.attch_list[i].drm.mime_subtype);
            }
            else
#endif
            {
                mmi_email_util_get_mine_type(
                    (S8*) email_p->comp_info.attch_list[i].file_name,
                    &email_p->comp_info.attch_list[i].attch_type,
                    &email_p->comp_info.attch_list[i].attch_subtype);
            }
        }
        email_p->comp_info.attch_list[i].ch_set = MMI_CHSET_UTF8;

        /* copy source file path+name */
        mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) filePath);

        email_p->misc_info.file_copy_state = EMAIL_FILE_ADD_ATTCH;

        email_p->comp_info.total_attch_size -= origLen;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ADD_ATTACH_CALLBACK_FILE_SIZE,
            origLen, email_p->comp_info.total_attch_size);

        /* delete the same name file */
        mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[i].file_path);
        ret = FS_Delete((U16*) email_p->comp_info.attch_list[i].file_path);
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ADD_ATTACH_CALLBACK_DELETE_FILE, ret);
        }
        /* Use select_repeat, so clear by application itself. */
        fmgr_reset_app_select();
        mmi_fmgr_send_copy_req(
            FMGR_ACTION_COPY,
            (U8*) email_p->comm_buff,
            (U8*) email_p->comp_info.attch_list[i].file_path,
            mmi_email_comp_attach_copy_callback);

        mmi_email_pre_entry_progressing(
            STR_EMAIL_MAIN_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            0,
            0,
            (U8*) GetString(STR_GLOBAL_SAVING),
            (U8*) NULL,
            IMG_GLOBAL_SAVE,
            NULL,
            NULL,
            NULL);
        DeleteUptoScrID(SCR_ID_EMAIL_COMP_ATTCH);
        OslMfree(email_p->other_app_info.fmgr_path);
        email_p->other_app_info.fmgr_path = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_attach_copy_callback
 * DESCRIPTION
 *  Callback function for add attachment in Write Email screen.
 * PARAMETERS
 *  info        [IN]        Variable stores the result of copy
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_attach_copy_callback(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 fileLen;
    mmi_fmt_copy_rsp_strcut *msgPtr;
    BOOL add_sig = MMI_FALSE;
    BOOL interrupt = MMI_FALSE;
    S32 attr = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) info;

    if (!mmi_email_util_is_call_interrupt_allow() && GetExitScrnID() != SCR_ID_EMAIL_PROGRESS)
    {
        /* delete progressing screen */
        DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
        interrupt = MMI_TRUE;
    }

    if (msgPtr->result >= 0)
    {
        if (email_p->misc_info.file_copy_state == EMAIL_FILE_ADD_ATTCH)
        {
            /* add attach into email app */
            i = email_p->misc_info.curr_hilite_attch;

            if (!email_p->comp_info.attch_list[i].attch_present)
            {
                email_p->comp_info.total_attch++;
            }
            /* calculate added file size */
            mmi_email_util_get_file_size((S8*) email_p->comp_info.attch_list[i].file_path, &fileLen);
            email_p->comp_info.attch_list[i].size = fileLen;
            /* if read-only, reset it */
            attr = FS_GetAttributes((const WCHAR*) email_p->comp_info.attch_list[i].file_path);
            if (attr & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes((const WCHAR*) email_p->comp_info.attch_list[i].file_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
            }
            /* update total attachment size */
            email_p->comp_info.total_attch_size += fileLen;
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ATTACH_COPY_CALLBACK_FILE_SIZE,
                fileLen, email_p->comp_info.total_attch_size);
            
            email_p->comp_info.attch_list[i].attch_present = TRUE;

            if (!interrupt)
            {
                mmi_email_util_display_popup(
                    (PU8) GetString(STR_GLOBAL_SAVED),
                    IMG_GLOBAL_ACTIVATED,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    SUCCESS_TONE);
                DeleteUptoScrID(SCR_ID_EMAIL_COMP_ATTCH);
            }
        }
        else if (email_p->misc_info.file_copy_state == EMAIL_FILE_ADD_SIG)
        {
#ifndef __MMI_SHOW_DAF_FILE_EXT__
            UI_character_type mp3_str[8];
            UI_character_type mp2_str[8];
            PS8 file_ext = NULL;
#endif
            i = (MMI_EMAIL_MAX_NUM_ATTACH - 1);

#ifdef __MMI_EMAIL_DRM_SUPPORT__
            mmi_email_drm_is_file_lock(
                (PS8)email_p->comp_info.attch_list[i].file_path,
                (BOOL*)&(email_p->comp_info.attch_list[i].drm.is_valid));
#endif
            /* get mine type */
#ifndef __MMI_SHOW_DAF_FILE_EXT__
            file_ext = mmi_email_get_file_ext((PS8)email_p->prof_info.act_prof.sig_img);
            mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
            mmi_asc_to_ucs2((S8*) mp2_str, ".mp2");
            if ((file_ext != NULL) && ((mmi_ucs2icmp(file_ext, (S8*)mp3_str) == 0)))
            {
                S32 ext_len, name_len;
                
                name_len = mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sig_img);
                ext_len = mmi_ucs2strlen(file_ext);
                kal_mem_set(&email_p->comp_info.attch_list[i].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
                mmi_ucs2ncpy((S8*) email_p->comp_info.attch_list[i].file_name, 
                    (PS8)email_p->prof_info.act_prof.sig_img, 
                    name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
                if (email_p->comp_info.attch_list[i].drm.is_valid)
                {
                    email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_APPLICATION;
                    email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
                    email_p->comp_info.attch_list[i].drm.mime_type = MIME_TYPE_AUDIO;
                    email_p->comp_info.attch_list[i].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP3;
                }
                else
#endif
                {
                    email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_AUDIO;
                    email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_AUDIO_MP3;
                }
            }
            else if ((file_ext != NULL) && ((mmi_ucs2icmp(file_ext, (S8*)mp2_str) == 0)))
            {
                S32 ext_len, name_len;
                
                name_len = mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sig_img);
                ext_len = mmi_ucs2strlen(file_ext);
                kal_mem_set(&email_p->comp_info.attch_list[i].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
                mmi_ucs2ncpy((S8*) email_p->comp_info.attch_list[i].file_name, 
                    (PS8)email_p->prof_info.act_prof.sig_img, 
                    name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
                if (email_p->comp_info.attch_list[i].drm.is_valid)
                {
                    email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_APPLICATION;
                    email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
                    email_p->comp_info.attch_list[i].drm.mime_type = MIME_TYPE_AUDIO;
                    email_p->comp_info.attch_list[i].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP2;
                }
                else
#endif
                {
                    email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_AUDIO;
                    email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_AUDIO_MP2;
                }
            }
            else
#endif
            {
                mmi_ucs2cpy(
                    (S8*) email_p->comp_info.attch_list[i].file_name,
                    (S8*) email_p->prof_info.act_prof.sig_img);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
                if (email_p->comp_info.attch_list[i].drm.is_valid)
                {
                    email_p->comp_info.attch_list[i].attch_type = MIME_TYPE_APPLICATION;
                    email_p->comp_info.attch_list[i].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
                    mmi_email_util_get_mine_type(
                        (S8*) email_p->comp_info.attch_list[i].file_name,
                        &email_p->comp_info.attch_list[i].drm.mime_type,
                        &email_p->comp_info.attch_list[i].drm.mime_subtype);
                }
                else
#endif
                {
                    mmi_email_util_get_mine_type(
                        (S8*) email_p->comp_info.attch_list[i].file_name,
                        &email_p->comp_info.attch_list[i].attch_type,
                        &email_p->comp_info.attch_list[i].attch_subtype);
                }
            }

            /* attach present in this index */
            email_p->comp_info.attch_list[i].attch_present = TRUE;
            email_p->comp_info.total_attch++;            
            /* calculate added file size */
            mmi_email_util_get_file_size((S8*) email_p->comp_info.attch_list[i].file_path, &fileLen);
            email_p->comp_info.attch_list[i].size = fileLen;
            /* if read-only, reset it */
            attr = FS_GetAttributes((const WCHAR*) email_p->comp_info.attch_list[i].file_path);
            if (attr & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes((const WCHAR*) email_p->comp_info.attch_list[i].file_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
            }
            /* update total attachment size */
            email_p->comp_info.total_attch_size += fileLen;
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ATTACH_COPY_CALLBACK_FILE_SIZE,
                fileLen, email_p->comp_info.total_attch_size);

            if (!interrupt)
            {
                if(email_p->other_app_info.app_param.is_save_to_draft == MMI_TRUE)
                {
                    mmi_email_ps_save_to_draft_req();
                }
                else
                {
                    mmi_email_entry_comp();
                    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                }
            }
        }
        else    /* if (email_p->misc_info.file_copy_state == EMAIL_FILE_FROM_APP) */
        {   /* if it's from other application like file manager */
            if (interrupt)
            {
                /* reset state */
                email_p->misc_info.file_copy_state = EMAIL_FILE_ADD_ATTCH;
                email_p->main_info.entry_src = EMAIL_FROM_MSG;
                return;
            }
            i = 0;
            
            email_p->comp_info.total_attch = 1;
            /* calculate added file size */
            mmi_email_util_get_file_size((S8*) email_p->comp_info.attch_list[i].file_path, &fileLen);
            email_p->comp_info.attch_list[i].size = fileLen;
            /* if read-only, reset it */
            attr = FS_GetAttributes((const WCHAR*) email_p->comp_info.attch_list[i].file_path);
            if (attr & FS_ATTR_READ_ONLY)
            {
                FS_SetAttributes((const WCHAR*) email_p->comp_info.attch_list[i].file_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
            }
            /* update total attachment size */
            email_p->comp_info.total_attch_size = fileLen;
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ATTACH_COPY_CALLBACK_FILE_SIZE,
                fileLen, email_p->comp_info.total_attch_size);

            email_p->comp_info.attch_list[i].attch_present = TRUE;

            /* start email module */
            email_p->main_info.curr_menu = MMI_EMAIL_COMP;
            mmi_email_ps_start_req();
        }
    }
    else
    {
        if (email_p->misc_info.file_copy_state == EMAIL_FILE_FROM_APP)
        {
            i = 0;
            if (!interrupt)
            {
                mmi_email_util_display_popup(
                    (PU8) GetString((U16) GetFileSystemErrorString(msgPtr->result)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
            }
            /* reset state */
            email_p->misc_info.file_copy_state = EMAIL_FILE_ADD_ATTCH;
            email_p->main_info.entry_src = EMAIL_FROM_MSG;
        }
        else if (email_p->misc_info.file_copy_state == EMAIL_FILE_ADD_ATTCH)
        {
            i = email_p->misc_info.curr_hilite_attch;
            if (!interrupt)
            {
                mmi_email_util_display_popup(
                    (PU8) GetString((U16) GetFileSystemErrorString(msgPtr->result)),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    ERROR_TONE);
                DeleteUptoScrID(SCR_ID_EMAIL_COMP_ATTCH);
            }
        }
        else    /* if (email_p->misc_info.file_copy_state == EMAIL_FILE_ADD_SIG) */
        {
            i = (MMI_EMAIL_MAX_NUM_ATTACH - 1);
            add_sig = MMI_TRUE;
            if (email_p->comp_info.attch_list[i].attch_present && email_p->comp_info.total_attch)
            {
                email_p->comp_info.total_attch--;
            }
            memset(&email_p->comp_info.attch_list[i], 0, sizeof(mmi_email_attch_info_struct));
            mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[i].file_name, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            email_p->comp_info.attch_icon[i].image1 = NULL;
            if (!interrupt)
            {
                mmi_email_entry_comp();
                DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
                mmi_email_util_display_popup(
                    (PU8) GetString(STR_EMAIL_SIG_ADD_FAIL_ID),
                    IMG_GLOBAL_ERROR,
                    0,
                    1000,
                    ERROR_TONE);
            }
        }

        if (!add_sig)
        {
            if (email_p->comp_info.attch_list[i].attch_present && email_p->comp_info.total_attch)
            {
                email_p->comp_info.total_attch--;
            }
            /* wgui_inline_item will be reset when entering email compose screen */
            memset(&email_p->comp_info.attch_list[i], 0, sizeof(mmi_email_attch_info_struct));
            mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[i].file_name, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
            email_p->comp_info.attch_icon[i].image1 = NULL;
        }
    }

    /* reset state */
    email_p->misc_info.file_copy_state = EMAIL_FILE_ADD_ATTCH;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_pre_entry_addr
 * DESCRIPTION
 *  Pre-Entry function of Write Email -> To/CC.
 *  If no address in the list, display option screen; otherwise, display address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_pre_entry_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.curr_hilite_attch = 0;
    if (email_p->comp_info.addr_list[email_p->comp_info.curr_addr_type].num_addr == 0)
    {
        mmi_email_entry_comp_addr_opt();
    }
    else
    {
        mmi_email_entry_comp_addr();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_get_addr_opt_menu
 * DESCRIPTION
 *  Get menu id of To/CC option according to # of address.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_email_comp_get_addr_opt_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->comp_info.addr_list[email_p->comp_info.curr_addr_type].num_addr)
    {
        case 0:
            {
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_ADD);
                mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ADDR_EDIT);
                mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL);
                mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL_ALL);
            }
            break;
        case 1:
            {
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_ADD);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_EDIT);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL);
                mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL_ALL);
            }
            break;
        case MMI_EMAIL_MAX_LEN_ADDR_LIST:
            {
                mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ADDR_ADD);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_EDIT);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL_ALL);
            }
            break;
        default:
            {
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_ADD);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_EDIT);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL);
                mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ADDR_DEL_ALL);
            }
            break;
    }
    return MENU_ID_EMAIL_COMP_ADDR_OPT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_addr
 * DESCRIPTION
 *  Entry function of To/CC list in Write Email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL emptyList = FALSE;
    U16 numItems;
    U16 capStrId;
    U16 lskStrId = STR_GLOBAL_OPTIONS;
    U8 *nStrMainItemList[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    U8 *nStrPopupItemList[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_ADDR, mmi_email_exit_comp_addr, NULL, NULL);

#ifdef __MMI_EMAIL_BCC__
    if(email_p->comp_info.curr_addr_type == EMAIL_ADDR_TO)
        capStrId = STR_EMAIL_TO_ID;
    else if(email_p->comp_info.curr_addr_type == EMAIL_ADDR_CC)
        capStrId = STR_EMAIL_CC_ID;
    else
        capStrId = STR_EMAIL_BCC_ID;
#else
    capStrId = (email_p->comp_info.curr_addr_type == EMAIL_ADDR_TO) ? STR_EMAIL_TO_ID : STR_EMAIL_CC_ID;
#endif
    
    numItems = mmi_email_comp_get_addr_info(nStrMainItemList, nStrPopupItemList);

    if (numItems == 0)
    {
        emptyList = TRUE;
        numItems = 1;
        lskStrId = STR_GLOBAL_ADD;
        nStrMainItemList[0] = (U8*) GetString(STR_GLOBAL_EMPTY_LIST);
        nStrPopupItemList[0] = NULL;
    }

    if (!email_p->comp_info.new_addr)
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_ADDR);
    }
    else
    {
        guiBuffer = NULL;
    }

    ShowCategory53Screen(
        capStrId,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        lskStrId,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrMainItemList,
        (U16*) gIndexIconsImageList,
        nStrPopupItemList,
        0,
        email_p->misc_info.curr_hilite_attch,
        guiBuffer);

    if (emptyList)
    {
        SetLeftSoftkeyFunction(mmi_email_comp_addr_pre_add, KEY_EVENT_UP);
        SetKeyHandler(mmi_email_comp_addr_pre_add, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_email_entry_comp_addr_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_email_entry_comp_addr_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_comp_addr
 * DESCRIPTION
 *  Exit function of To/CC list in Write Email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_comp_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_history(SCR_ID_EMAIL_COMP_ADDR, mmi_email_entry_comp_addr);
    email_p->misc_info.curr_hilite_attch = GetHighlightedItem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_get_addr_info
 * DESCRIPTION
 *  Retrieve information for To/CC address
 * PARAMETERS
 *  nStrMainItemList        [IN/OUT]        String pointer to store address list
 *  nStrPopupItemList       [IN/OUT]        String pointer to display name list
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_email_comp_get_addr_info(U8 **nStrMainItemList, U8 **nStrPopupItemList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 index = email_p->comp_info.curr_addr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < email_p->comp_info.addr_list[index].num_addr; i++)
    {
        nStrMainItemList[i] = (U8*) email_p->comp_info.addr_list[index].to_cc_mail[i];
        if (!mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[index].to_cc_name[i]))
        {
            nStrPopupItemList[i] = NULL;
        }
        else
        {
            nStrPopupItemList[i] = (U8*) email_p->comp_info.addr_list[index].to_cc_name[i];
        }
    }

    return email_p->comp_info.addr_list[index].num_addr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_addr_opt
 * DESCRIPTION
 *  Display option screen of Write Email -> To/CC
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_addr_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 parentMenuId;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_ADDR_OPT, NULL, mmi_email_entry_comp_addr_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_ADDR_OPT);
    parentMenuId = mmi_email_comp_get_addr_opt_menu();
    SetParentHandler(parentMenuId);
    numItems = GetNumOfChild_Ext(parentMenuId);
    GetSequenceStringIds_Ext(parentMenuId, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_pre_add
 * DESCRIPTION
 *  Prepare data for add new address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_pre_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(email_p->comp_info.addr_input_buff, 0, ENCODING_LENGTH);
    memset(email_p->comp_info.phb_addr, 0, ENCODING_LENGTH);
    memset(email_p->comp_info.phb_name, 0, ENCODING_LENGTH);

    /* add new entry */
    email_p->comp_info.new_addr = TRUE;
    mmi_email_entry_comp_addr_input();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_pre_edit
 * DESCRIPTION
 *  Prepare data for edit current selected address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_pre_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->comp_info.curr_addr_type;
    S32 j = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) email_p->comp_info.addr_input_buff, (S8*) email_p->comp_info.addr_list[i].to_cc_mail[j]);
    mmi_ucs2cpy((S8*) email_p->comp_info.phb_name, (S8*) email_p->comp_info.addr_list[i].to_cc_name[j]);
    mmi_ucs2cpy((S8*) email_p->comp_info.phb_addr, (S8*) email_p->comp_info.addr_list[i].to_cc_mail[j]);

    /* edit an existing entry */
    email_p->comp_info.new_addr = FALSE;
    mmi_email_entry_comp_addr_input();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_addr_input
 * DESCRIPTION
 *  Display full screen editor for Write Email -> To/CC -> Edit/Add
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_addr_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_ADDR_INPUT, NULL, mmi_email_entry_comp_addr_input, NULL);

    if (mmi_ucs2strlen((S8*) email_p->comp_info.phb_addr) && email_p->comp_info.load_addr_done)
    {
        guiBuffer = NULL;
        email_p->comp_info.load_addr_done = FALSE;
    }
    else
    {
        guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_ADDR_INPUT);
    }

    RegisterInputBoxEmptyFunction(mmi_email_comp_addr_empty_lsk_hdlr);
    RegisterInputBoxNotEmptyFunction(mmi_email_comp_addr_no_empty_lsk_hdlr);

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_editor_set_vk_keys(MMI_TRUE, g_email_allowed, NULL);
#endif
    ShowCategory5Screen_ext(
        STR_EMAIL_INPUT_ADDRESS_ID, 
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN), 
        0, 
        0, 
        STR_GLOBAL_BACK, 
        IMG_GLOBAL_BACK, 
        INPUT_TYPE_USE_ONLY_ENGLISH_MODES | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE, 
        (U8*)email_p->comp_info.addr_input_buff, 
        MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1, 
        guiBuffer, 
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        (S16*)g_email_addr_input_modes,
        NULL);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_search_in_phb
 * DESCRIPTION
 *  Address input screen when the editor is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_search_in_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_list_pre_entry_for_number_and_email(MMI_PHB_ENTRY_FIELD_EMAIL, mmi_email_phb_get_addr_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_empty_lsk_hdlr
 * DESCRIPTION
 *  Register LSK handler for Address input screen when the editor is empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_empty_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_SMS_COMMON_SEARCH, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(mmi_email_comp_addr_search_in_phb, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_no_empty_lsk_hdlr
 * DESCRIPTION
 *  Register LSK handler for Address input screen when the editor is not empty.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_no_empty_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
    SetLeftSoftkeyFunction(mmi_email_entry_comp_addr_input_opt, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_addr_input_opt
 * DESCRIPTION
 *  Entry Write Email -> To/CC -> Edit -> Option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_addr_input_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only Done and Input Method */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_ADDR_INPUT_OPT, NULL, mmi_email_entry_comp_addr_input_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_ADDR_INPUT_OPT);
    SetParentHandler(MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_COMP_ADDR_EDIT_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_input_done
 * DESCRIPTION
 *  Handler when finished editing email address.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_input_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_input_buff) &&
        mmi_email_util_chk_addr((U8*) email_p->comp_info.addr_input_buff))
    {
        U8 index;
        S32 i = email_p->comp_info.curr_addr_type;

        if ((email_p->comp_info.addr_list[i].num_addr == 0) && (IsScreenPresent(SCR_ID_EMAIL_COMP_ADDR_OPT)))
        {
            ReplaceNewScreenHandler(SCR_ID_EMAIL_COMP_ADDR_INPUT_OPT, NULL, NULL);
            DeleteNScrId(SCR_ID_EMAIL_COMP_ADDR_OPT);
            mmi_email_exit_comp_addr(); /* add "TO" list screen into history */
        }

        /* get current editing cursor of address list */
        index =
            (email_p->comp_info.new_addr) ? email_p->comp_info.addr_list[i].num_addr : email_p->misc_info.
            curr_hilite_attch;
        /* set list screen high lighted item index */
        email_p->misc_info.curr_hilite_attch = index;
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[i].to_cc_mail[index],
            (S8*) email_p->comp_info.addr_input_buff);
        if (!mmi_ucs2cmp((S8*) email_p->comp_info.phb_addr, (S8*) email_p->comp_info.addr_input_buff))
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_list[i].to_cc_name[index],
                (S8*) email_p->comp_info.phb_name);
        }
        else
        {
            memset(
                email_p->comp_info.addr_list[i].to_cc_name[index],
                0,
                sizeof(email_p->comp_info.addr_list[i].to_cc_name[index]));
        }

        /* add new address */
        if (email_p->comp_info.new_addr)
        {
            email_p->comp_info.addr_list[i].num_addr++;
        }

        /* update inline buffer */
        mmi_email_comp_update_addr_buff();
        email_p->comp_info.done_flag = TRUE;

        GoBackToHistory(SCR_ID_EMAIL_COMP_ADDR);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        DeleteNScrId(SCR_ID_EMAIL_COMP_ADDR_INPUT_OPT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_del
 * DESCRIPTION
 *  Display confirmation screen for deleting address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_display_confirm(STR_EMAIL_DEL_COMP_ADDR_ID, mmi_email_comp_addr_del_yes, mmi_email_comp_addr_del_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_del_no
 * DESCRIPTION
 *  Canceling deleting address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_del_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_del_yes
 * DESCRIPTION
 *  Proceed deleting address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_del_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 i = email_p->comp_info.curr_addr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = email_p->misc_info.curr_hilite_attch; index < email_p->comp_info.addr_list[i].num_addr - 1; index++)
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[i].to_cc_mail[index],
            (S8*) email_p->comp_info.addr_list[i].to_cc_mail[index + 1]);
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[i].to_cc_name[index],
            (S8*) email_p->comp_info.addr_list[i].to_cc_name[index + 1]);
    }

    /*  reset null last entry */
    memset(
        email_p->comp_info.addr_list[i].to_cc_mail[index],
        0,
        sizeof(email_p->comp_info.addr_list[i].to_cc_mail[index]));
    memset(
        email_p->comp_info.addr_list[i].to_cc_name[index],
        0,
        sizeof(email_p->comp_info.addr_list[i].to_cc_name[index]));

    email_p->comp_info.addr_list[i].num_addr--;
    mmi_email_comp_update_addr_buff();
    email_p->comp_info.done_flag = TRUE;
    mmi_email_util_display_popup(
        (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    mmi_email_comp_addr_hist_del();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_hist_del
 * DESCRIPTION
 *  Common function to delete history node when cancel deleting address.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_hist_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_EMAIL_COMP_ADDR_OPT))
    {
        DeleteNScrId(SCR_ID_EMAIL_COMP_ADDR_OPT);
    }
    else if (IsScreenPresent(SCR_ID_EMAIL_COMP_ADDR_INPUT))
    {
        DeleteNScrId(SCR_ID_EMAIL_COMP_ADDR_INPUT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_del_all
 * DESCRIPTION
 *  Display confirmation screen for deleting all addresses
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_display_confirm(STR_EMAIL_DEL_ALL_COMP_ADDR_ID, mmi_email_comp_addr_del_all_yes, mmi_email_comp_addr_del_all_no);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_del_all_no
 * DESCRIPTION
 *  Cancel deleting all addresses
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_del_all_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_addr_del_all_yes
 * DESCRIPTION
 *  Proceed deleting all addresses
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_addr_del_all_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->comp_info.curr_addr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&email_p->comp_info.addr_list[i], 0, sizeof(mmi_email_to_cc_struct));
    memset(email_p->comp_info.addr_disp_buff[i], 0, sizeof(email_p->comp_info.addr_disp_buff[i]));
    email_p->comp_info.done_flag = TRUE;
    mmi_email_util_display_popup(
        (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
        IMG_GLOBAL_ACTIVATED,
        1,
        UI_POPUP_NOTIFYDURATION_TIME,
        (U8) SUCCESS_TONE);
    mmi_email_comp_addr_hist_del();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_update_addr_buff
 * DESCRIPTION
 *  Update address displayed buffer in inline editor screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_update_addr_buff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->comp_info.curr_addr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->comp_info.addr_list[i].num_addr != 0)
    {
        if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[i].to_cc_name[0]))
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_disp_buff[i],
                (S8*) email_p->comp_info.addr_list[i].to_cc_name[0]);
            mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[i], (S8*) g_email_subj_left_op);
            mmi_ucs2cat(
                (S8*) email_p->comp_info.addr_disp_buff[i],
                (S8*) email_p->comp_info.addr_list[i].to_cc_mail[0]);
            mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[i], (S8*) g_email_subj_right_op);
        }
        else
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_disp_buff[i],
                (S8*) email_p->comp_info.addr_list[i].to_cc_mail[0]);
        }

        if (email_p->comp_info.addr_list[i].num_addr > 1)
        {
            mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[i], (S8*) g_email_3dots);
        }
    }
    else
    {
        email_p->comp_info.addr_disp_buff[i][0] = 0x0000;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_attch
 * DESCRIPTION
 *  Display list of attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_attch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 *nStrAttachmentItemList[MMI_EMAIL_MAX_NUM_ATTACH];
    U8 *popUpList[EMAIL_MAX_PART_NUMBER + 1];
    S8 fileNumberAnsii[2 * ENCODING_LENGTH];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_ATTCH, NULL, mmi_email_entry_comp_attch, NULL);

    for (i = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
    {
        memset(retrieve_att_size[i], 0, sizeof(S8) * 5 * ENCODING_LENGTH);
        /* the empty string depends on language setting */
        if (!email_p->comp_info.attch_list[i].attch_present)
        {
            mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[i].file_name, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        }
        else
        {
            sprintf(fileNumberAnsii, "%dK", (email_p->comp_info.attch_list[i].size + 1023)/1024);
            mmi_asc_to_ucs2(retrieve_att_size[i], fileNumberAnsii);
        }
        popUpList[i] = (U8*)retrieve_att_size[i];
        nStrAttachmentItemList[i] = (U8*) email_p->comp_info.attch_list[i].file_name;
    }

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_ATTCH);

    RegisterHighlightHandler(mmi_email_hilite_comp_attch);

    ShowCategory53Screen(
        STR_EMAIL_ATTACHMENT_LIST_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_EMAIL_MAX_NUM_ATTACH,
        nStrAttachmentItemList,
        (U16*) gIndexIconsImageList,
        popUpList,
        0,
        email_p->misc_info.curr_hilite_attch,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_email_entry_comp_attch_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_comp_attch_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_comp_attch
 * DESCRIPTION
 *  Highlight handler of attachment list in Write Email-> Attachment screen.
 * PARAMETERS
 *  index       [IN]        Index of current highlighting item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_comp_attch(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.curr_hilite_attch = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_attch_opt
 * DESCRIPTION
 *  Entry function for Write Email -> Attachment -> Option screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_attch_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];    /* only Edit/View/Delete */
    U8 *guiBuffer;
    S32 i = email_p->misc_info.curr_hilite_attch;
    U8 fileType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_ATTCH_OPT, NULL, mmi_email_entry_comp_attch_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_ATTCH_OPT);

    if (email_p->comp_info.attch_list[i].attch_present == FALSE)
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ATTCH_VIEW);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ATTCH_DEL);
    }
    else
    {
        fileType = mmi_fmgr_get_file_group((S8*) email_p->comp_info.attch_list[i].file_path);
        if ((fileType != FMGR_GROUP_IMAGE) && (fileType != FMGR_GROUP_AUDIO) && (fileType != FMGR_GROUP_VIDEO))
        {
            mmi_frm_hide_menu_item(MENU_ID_EMAIL_COMP_ATTCH_VIEW);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ATTCH_VIEW);
        }
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_COMP_ATTCH_DEL);
    }
    SetParentHandler(MENU_ID_EMAIL_COMP_ATTCH_OPT);
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_COMP_ATTCH_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_COMP_ATTCH_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_pre_entry_view_attach
 * DESCRIPTION
 *  Pre-Entry function of view attachment.
 *  Execute entry function according to type of attachment.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_pre_entry_view_attach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->misc_info.curr_hilite_attch;
    U8 fileType;
#ifdef __MMI_EMAIL_DRM_SUPPORT__    
    U8 permission = DRM_PERMISSION_NONE;
    U8 method = DRM_METHOD_NONE;
    FS_HANDLE fileHandle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* add one more check for file type */
    fileType = mmi_fmgr_get_file_group((S8*) email_p->comp_info.attch_list[i].file_path);
    if ((fileType != FMGR_GROUP_IMAGE) && (fileType != FMGR_GROUP_AUDIO) && (fileType != FMGR_GROUP_VIDEO))
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_NOT_SUPPORT_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    if (email_p->comp_info.attch_list[i].drm.is_valid)
    {
        if (fileType == FMGR_GROUP_IMAGE)
        {
            permission = DRM_PERMISSION_DISPLAY;
        }
        else if (fileType == FMGR_GROUP_AUDIO)
        {
            permission = DRM_PERMISSION_PLAY;
        }
        else if (fileType == FMGR_GROUP_VIDEO)
        {
            permission = DRM_PERMISSION_PLAY;
        }
        if ((fileHandle = DRM_open_file(
                    (UI_string_type)email_p->comp_info.attch_list[i].file_path, 
                    FS_READ_ONLY, 
                    permission)) >= FS_NO_ERROR)
        {
            if ((method = DRM_get_object_method(fileHandle, NULL)) != DRM_METHOD_NONE)
            {
                if (DRM_validate_permission(fileHandle, NULL, permission) == MMI_FALSE)
                {
                    if (method & DRM_METHOD_SEPARATE_DELIVERY)
                    {
                        U32 size = sizeof(rights_issuer);
                        /* request rights from server */
                        memset(rights_issuer, 0, sizeof(rights_issuer));
                        if(FS_NO_ERROR <= DRM_get_rights_issuer(fileHandle, rights_issuer, &size))
                        {
                            if (
                        #ifdef __FLIGHT_MODE_SUPPORT__
                                (mmi_bootup_get_active_flight_mode() == 0) &&
                        #endif
                                (mmi_bootup_is_network_service_available() == TRUE))
                            {
                        #ifdef WAP_SUPPORT
                                mmi_email_display_confirm(STR_FMGR_REQ_RIGHTS, mmi_email_request_rights, GoBackHistory);
                        #else
                                mmi_email_util_display_popup(
                                    (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                                    IMG_GLOBAL_WARNING,
                                    0,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) WARNING_TONE);
                        #endif
                                DRM_close_file(fileHandle);
                                return;
                            }
                        }
                    }
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) WARNING_TONE);
                    DRM_close_file(fileHandle);
                    return;
                }
            }
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_PRE_ENTRY_VIEW_ATTACH_DRM, method, permission);
            DRM_close_file(fileHandle);
        }
        else
        {
            /* open file fail */
            mmi_email_util_display_popup((PU8) GetString(GetFileSystemErrorString(fileHandle)),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }
    }
    is_drm_file = email_p->comp_info.attch_list[i].drm.is_valid;
#endif /* __DRM_SUPPORT__ */ 
    if (fileType == FMGR_GROUP_IMAGE)
    {
        S32 fmgr_type = 0;
        FMGR_FILTER fmgr_set;
        
        FMGR_FILTER_INIT(&fmgr_set);
        fmgr_type = mmi_fmgr_get_file_type_by_filename((PS8)email_p->comp_info.attch_list[i].file_path);
        FMGR_FILTER_SET(&fmgr_set, fmgr_type);
        mmi_imgview_view_image_hdlr(
            (PS8)email_p->comp_info.attch_list[i].file_path,
            MMI_FALSE,
            fmgr_set,
            GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
    }
    else if (fileType == FMGR_GROUP_AUDIO)
    {
        mmi_audply_single_play(
            (UI_string_type)email_p->comp_info.attch_list[i].file_path,
            NULL);
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (fileType == FMGR_GROUP_VIDEO)
    {
        EntryNewScreen(SCR_ID_EMAIL_COMP_VIEW_IMAGE, NULL, mmi_email_comp_pre_entry_view_attach, NULL);
        ShowCategory225Screen(
            STR_GLOBAL_VIEW,
            GetRootTitleIcon(MENU_ID_VDOPLY_APP),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            (S8*) email_p->comp_info.attch_list[i].file_path,
            1,
            TRUE,
            TRUE,
            TRUE,
            GDI_COLOR_BLACK,
            mmi_email_play_video_callback,
            NULL);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_play_video_callback
 * DESCRIPTION
 *  Play video callback function
 * PARAMETERS
 *  result      [IN]        Play result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_play_video_callback(S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (result < 0)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeRightSoftkey(0, 0);

        switch (result)
        {
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL:
            {
                mmi_email_util_display_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            }    
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_ROOT_DIR_FULL:
            {
                 mmi_email_util_display_popup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            }    
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION:
            {    
                mmi_email_util_display_popup(
                    (PU8) GetString(STR_ID_VDOPLY_NOTIFY_WRITE_PROTECTION),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            }    
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_NO_DISK:
            case MDI_RES_VDOPLY_ERR_SNAPSHOT_FAILED:
            {
                mmi_email_util_display_popup(
                    (PU8) GetString(STR_ID_VDOPLY_NOTIFY_SNAPSHOT_FAILED),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            }
            /* followings are serious error, has to exit app */
            case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
            case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
            case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
            case MDI_RES_VDOPLY_ERR_FAILED:                
            {
                mmi_email_util_display_popup(
                    (PU8) GetString(STR_ID_VDOPLY_NOTIFY_INVALID_VIDEO_FILE),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                break;
            }
            case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
            case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
                break;
            }
            default:
            {
                mmi_email_util_display_popup(
                    (PU8) GetString(STR_FMGR_INVALID_FORMAT),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
            }
        }
        DeleteNHistory(1);
    }
}


#ifdef __MMI_EMAIL_DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_email_request_rights
 * DESCRIPTION
 *  Request rights from WAP browser for DRM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_request_rights(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp[MAX_LINE_LENGTH * ENCODING_LENGTH] = {0};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_n_to_ucs2(temp, rights_issuer, strlen((const char *)rights_issuer));
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)temp);
#else
    GoBackHistory();
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_attch_del
 * DESCRIPTION
 *  Display confirmation screen for Write Email->Attachment->Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_attch_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_display_confirm(STR_EMAIL_DEL_COMP_ATT_ID, mmi_email_comp_attch_del_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_attch_del_done
 * DESCRIPTION
 *  Execute Write Email->Attachment->Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_attch_del_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->misc_info.curr_hilite_attch;
    S32 fileLen;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calculate deleted file size */
    if (email_p->comp_info.total_attch)
    {
        mmi_email_util_get_file_size((S8*) email_p->comp_info.attch_list[i].file_path, &fileLen);
        
        mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[i].file_path);
        ret = FS_Delete((U16*)email_p->comp_info.attch_list[i].file_path);
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ATTCH_DEL_DONE_DEL_FILE, ret);
        }
        memset(&email_p->comp_info.attch_list[i], 0, sizeof(mmi_email_attch_info_struct));
        mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[i].file_name, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
        email_p->comp_info.attch_icon[i].image1 = NULL;
        email_p->comp_info.total_attch--;
        /* update total attachment size */
        email_p->comp_info.total_attch_size -= fileLen;
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_ATTCH_DEL_DONE_FILE_SIE, fileLen, email_p->comp_info.total_attch_size);

        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_NOT_DONE),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    if (IsScreenPresent(SCR_ID_EMAIL_COMP_ATTCH_OPT))
    {
        DeleteNScrId(SCR_ID_EMAIL_COMP_ATTCH_OPT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_opt
 * DESCRIPTION
 *  Entry function of option screen of Write Email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[4];    /* only 4 items */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_OPT, NULL, mmi_email_entry_comp_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_OPT);
    SetParentHandler(MENU_ID_EMAIL_COMP_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_COMP_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_COMP_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_EMAIL_EMAIL_OPTION_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(mmi_email_compose_size_goback_history, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_compose_size_goback_history, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    DeleteScreenIfPresent(SCR_ID_EMAIL_COMP_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_opt_quit
 * DESCRIPTION
 *  Execute Quit Without Saving option, display confirmation screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_opt_quit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_display_confirm(STR_EMAIL_QUIT_COMP_ID, mmi_email_comp_opt_quit_yes, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_opt_quit_yes
 * DESCRIPTION
 *  Reset screen variables in Write Email screen and go back to Email main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_opt_quit_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_comp_reset_member();
    if (email_p->main_info.entry_src == EMAIL_FROM_APP)
    {
        mmi_email_main_quit_email();
        DeleteScreenIfPresent(SCR_ID_EMAIL_COMP);
        DeleteScreenIfPresent(SCR_ID_EMAIL_COMP_OPT);
    }
    else
    {
        mmi_email_util_del_between_scr(mmi_email_fldr_get_start_scr(), GetCurrScrnId());
        if (email_p->fldr_info.is_part_download == EMAIL_DOWN_POP3)
        {
            email_p->fldr_info.is_part_download = EMAIL_DOWN_TEMP;
            mmi_email_fldr_reset_list_info_ex();
            mmi_email_fldr_pre_folder_select_req();
        }
        else
        {
            GoBackHistory();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_cont
 * DESCRIPTION
 *  Entry Write Email-> Content screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_CONT_INPUT, mmi_email_exit_comp_cont, mmi_email_entry_comp_cont, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_CONT_INPUT);
    ShowCategory5Screen(
        STR_EMAIL_CONTENT_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) email_p->misc_info.cont_inline_buff,
        (EMAIL_MAX_CONT_LEN + 1),
        guiBuffer);
#ifdef __MMI_EMAIL_TEMPLATE__
    SetLeftSoftkeyFunction(mmi_email_entry_comp_cont_opt, KEY_EVENT_UP);
#else
    SetLeftSoftkeyFunction(mmi_email_entry_comp_subj_opt, KEY_EVENT_UP);
#endif /*__MMI_EMAIL_TEMPLATE__*/
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_exit_comp_cont
* DESCRIPTION
*  Exit function of content editor in Write Email
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_exit_comp_cont(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    compose_input_length = MMI_multiline_inputbox.text_length;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_subj
 * DESCRIPTION
 *  Entry Write Email-> Subject screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_comp_subj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_SUBJ_INPUT, NULL, mmi_email_entry_comp_subj, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_SUBJ_INPUT);
    ShowCategory5Screen(
        STR_EMAIL_SUBJECT_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) email_p->misc_info.subj_inline_buff,
        EMAIL_COMP_SUBJ_LEN + 1,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_email_entry_comp_subj_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_comp_subj_cont_done
 * DESCRIPTION
 *  Handler for Write Email -> Subject/Content -> Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_comp_subj_cont_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* editing subject */
    if (email_p->comp_info.curr_inline_item == EMAIL_COMP_SUBJ)
    {
        mmi_ucs2cpy((S8*) email_p->comp_info.subj_buff, (S8*) email_p->misc_info.subj_inline_buff);
    }
    else
    {   /* editing content */
        mmi_ucs2cpy((S8*) email_p->comp_info.cont_buff, (S8*) email_p->misc_info.cont_inline_buff);
        set_inscreen_multi_line_input_box_changed();
    }
    email_p->comp_info.done_flag = TRUE;
    GoBackToHistory(SCR_ID_EMAIL_COMP);
}

#define INBOX_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_pre_entry
 * DESCRIPTION
 *  Pre-Entry function of folders.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.is_list_updated = TRUE;

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        email_p->fldr_info.is_list_updated = FALSE;
    }
    else
#endif 
    {
        if (!email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
            return;
        }
    }

    email_p->fldr_info.fldr_list.num_msgs = 0;
    email_p->fldr_info.curr_page = 1;
    mmi_email_fldr_reset_list_info();
    mmi_email_fldr_exec_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_folder
 * DESCRIPTION
 *  Entry function of each folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numItems;
    U8* screen_cap = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numItems = mmi_email_fldr_get_num_mails();

    if (numItems)
    {
        U16 lskStrId;
        U8 *guiBuffer;
        S32 list_not_ready;

        EntryNewScreen(SCR_ID_EMAIL_FOLDER, mmi_email_exit_folder, NULL, NULL);

        email_p->fldr_info.need_fldr_sel = FALSE;

        guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_FOLDER);
        RegisterHighlightHandler(mmi_email_hilite_folder_item);
        switch (email_p->main_info.curr_menu)
        {
        case MMI_EMAIL_INBOX:
            screen_cap = mmi_email_util_folder_select_cap_str(STR_EMAIL_INBOX_ID);
            break;
        case MMI_EMAIL_SENT:
            screen_cap = mmi_email_util_folder_select_cap_str(STR_EMAIL_SENT_ID);
            break;
        case MMI_EMAIL_UNSENT:
            screen_cap = mmi_email_util_folder_select_cap_str(STR_EMAIL_UNSENT_ID);
            break;
        case MMI_EMAIL_DRAFT:
            screen_cap = mmi_email_util_folder_select_cap_str(STR_EMAIL_DRAFT_ID);
            break;
        }

    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        /* set LSK string according to current state */
        if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) && 
            (email_p->fldr_info.total_page > 1) &&
            (email_p->main_info.curr_menu != MMI_EMAIL_UNSENT))
        {
            lskStrId = STR_GLOBAL_OPTIONS;
        }
        else
    #endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
            lskStrId = STR_GLOBAL_VIEW;

        /* to prevent the selected mail being deleted */
        if (email_p->fldr_info.curr_mail_indx >= numItems)
        {
            email_p->fldr_info.curr_mail_indx = numItems - 1;
        }

        ShowCategory261Screen(
            screen_cap,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            lskStrId,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            numItems,
            mmi_email_folder_get_async_items,
            NULL,
            email_p->fldr_info.curr_mail_indx,
            IMG_EMAIL_READ_NORMAL_ID,
            IMG_EMAIL_ATTACH_IMAGE_ID,
            guiBuffer,
            2 /* no_of_string */ ,
            4 /* no_of_icons */ ,
            &list_not_ready);

        /* if data in dynamic list is not ready */
        if (list_not_ready)
        {
            mmi_email_fldr_pre_folder_select_req();
        }
        else
        {
            /* to indicate folder list is really displayed */
            email_p->fldr_info.is_list_displayed = TRUE;

            SetLeftSoftkeyFunction(mmi_email_folder_lsk_hdlr, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_folder_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetRightSoftkeyFunction(mmi_email_folder_rsk_hdlr, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_folder_rsk_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        }
    }
    else    /* because the is_list_displayed flag is FALSE, the folder screen is not in history */
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_folder
 * DESCRIPTION
 *  Exit function of Inbox.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_history(SCR_ID_EMAIL_FOLDER, mmi_email_fldr_back_from_history);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_folder_rsk_hdlr
 * DESCRIPTION
 *  Right soft key handler of folder.
 *  If current protocol is IMAP4, will entry option screen first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_folder_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_folder_lsk_hdlr
 * DESCRIPTION
 *  Left soft key handler of folder.
 *  If current protocol is IMAP4, will entry option screen first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_folder_lsk_hdlr(void)
{
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if protocol == IMAP4 and total page > 1, will go to option screen of folder; otherwise will read the mail */
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (email_p->fldr_info.total_page > 1) &&
        (email_p->main_info.curr_menu != MMI_EMAIL_UNSENT))
    {
        mmi_email_entry_folder_opt();
    }
    else
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    {
        mmi_email_ps_folder_msg_select_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_folder_opt
 * DESCRIPTION
 *  Entry function of folder -> Option
 *  This screen exists only when IMAP4 is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_folder_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_FOLDER_OPT, NULL, mmi_email_entry_folder_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_FOLDER_OPT);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_NEXT_PAGE);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_PREV_PAGE);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_JUMP_PAGE);
        if ((email_p->fldr_info.total_page > 1) && (!EMAIL_IS_MENU(MMI_EMAIL_UNSENT)))
        {
            mmi_frm_unhide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_NEXT_PAGE);
            mmi_frm_unhide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_PREV_PAGE);
            mmi_frm_unhide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_JUMP_PAGE);
        }
    }
    else
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_NEXT_PAGE);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_PREV_PAGE);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_FOLDER_OPT_JUMP_PAGE);
    }
    SetParentHandler(MENU_ID_EMAIL_FOLDER_OPT);
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_FOLDER_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_FOLDER_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_folder_item
 * DESCRIPTION
 *  Highlight handler of Inbox list
 * PARAMETERS
 *  index       [IN]        Index of highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_folder_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_mail_info_struct *listMsgsStruct[EMAIL_TOTAL_MSG_BUFF];
    mmi_email_mail_info_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mem_get_values(
        &email_p->mem_pool_info.mem_container,
        (S16) index,
        (S16) index,
        (void **)listMsgsStruct,
        &email_p->mem_pool_info.not_avail_pool);

    temp = listMsgsStruct[0];
    email_p->fldr_info.curr_mail_indx = index;
    email_p->fldr_info.curr_mail_uid = temp->mail_uid;
    email_p->fldr_info.curr_delete_flag = temp->delete_flag;
    if (EMAIL_IS_MENU(MMI_EMAIL_INBOX))
    {
        email_p->fldr_info.curr_unread_flag = FALSE;
    }
    EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_part_mask);
    EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_get_part_mask);
    email_p->fldr_info.curr_total_txt = 0;
    email_p->fldr_info.curr_total_att = 0;
    email_p->fldr_info.curr_num_not_cached_txt = 0;
    email_p->fldr_info.curr_num_not_cached_att = 0;
    email_p->fldr_info.curr_retrieve_indx = 0;
    email_p->fldr_info.is_part_download = EMAIL_DOWN_NONE;
    email_p->fldr_info.curr_sel_flag = EMAIL_SEL_NORMAL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_folder_update_mail_state
 * DESCRIPTION
 *  Update read/unread state of a mail.
 * PARAMETERS
 *  index       [IN]        Mail id of the mail
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_folder_update_mail_state(S32 index, mmi_email_mail_status status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_mail_info_struct *listMsgsStruct[EMAIL_TOTAL_MSG_BUFF];
    mmi_email_mail_info_struct *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mem_get_values(
        &email_p->mem_pool_info.mem_container,
        (S16) index,
        (S16) index,
        (void **)listMsgsStruct,
        &email_p->mem_pool_info.not_avail_pool);

    temp = listMsgsStruct[0];
    email_p->fldr_info.curr_mail_indx = index;

    if ((status == EMAIL_MS_READ) && (!temp->is_read))
    {
        temp->is_read = TRUE;

        /* update idle screen icon status after read one email */
        if (email_p->main_info.unread_mails != 0)
        {
            email_p->main_info.unread_mails--;
            mmi_email_util_update_status_icon();
        }
    }
    else if ((status == EMAIL_MS_UNREAD) && (temp->is_read))
    {
        temp->is_read = FALSE;
        /* update idle screen icon status in set_flag_rsp process */
    }
    else if ((status == EMAIL_MS_DELETED) && (!temp->delete_flag))
    {
        temp->delete_flag = TRUE;
    }
    else if ((status == EMAIL_MS_UNDELETED) && (temp->delete_flag))
    {
        temp->delete_flag = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_folder_get_status_icon
 * DESCRIPTION
 *  Get status icon of a mail in Inbox list
 * PARAMETERS
 *  priority        [IN]        Priority of the mail.
 *  is_read         [IN]        
 *  delete_flag     [IN]        The mark/unmark state of the mail
 * RETURNS
 *  image id of the status icon
 *****************************************************************************/
U16 mmi_email_folder_get_status_icon(U8 priority, BOOL is_read, kal_bool delete_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delete_flag == MMI_TRUE)
    {
        return IMG_EMAIL_MARK_DELETED_BIG_ID;
    }
    else if ((!is_read) && (EMAIL_IS_MENU(MMI_EMAIL_INBOX)))
    {
        if (priority > MMI_EMAIL_NORMAL_PRIORITY)
        {
            return IMG_EMAIL_UNREAD_LOW_ID;
        }
        else if (priority < MMI_EMAIL_NORMAL_PRIORITY)
        {
            return IMG_EMAIL_UNREAD_HIGH_ID;
        }
        else    /* (priority==MMI_EMAIL_NORMAL_PRIORITY) */
        {
            return IMG_EMAIL_UNREAD_NORMAL_ID;
        }
    }
    else
    {
        if (priority > MMI_EMAIL_NORMAL_PRIORITY)
        {
            return IMG_EMAIL_READ_LOW_ID;
        }
        else if (priority < MMI_EMAIL_NORMAL_PRIORITY)
        {
            return IMG_EMAIL_READ_HIGH_ID;
        }
        else    /* (priority==MMI_EMAIL_NORMAL_PRIORITY) */
        {
            return IMG_EMAIL_READ_NORMAL_ID;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_folder_get_attch_icon
 * DESCRIPTION
 *  Get status icon of a mail in Inbox list
 * PARAMETERS
 *  attachNum           [IN]        Number of attachments
 *  attch_type          [IN]        Mine type of attacments
 *  attachImageList     [OUT]       Image list of attachments
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_folder_get_attch_icon(U8 attachNum, U8 *attch_type, U16 *attachImageList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < attachNum; i++)
    {
        if (attch_type[i] == MIME_TYPE_IMAGE)
        {
            attachImageList[i] = IMG_EMAIL_ATTACH_IMAGE_ID;
        }
        else if (attch_type[i] == MIME_TYPE_AUDIO)
        {
            attachImageList[i] = IMG_EMAIL_ATTACH_AUDIO_ID;
        }
        else if (attch_type[i] == MIME_TYPE_VIDEO)
        {
            attachImageList[i] = IMG_EMAIL_ATTACH_VIDEO_ID;
        }
        else
        {
            attachImageList[i] = IMG_EMAIL_ATTACH_UNKNOWN_ID;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_folder_get_async_items
 * DESCRIPTION
 *  Fill dynamic list items of inbox
 * PARAMETERS
 *  start_indx      [IN]            Start index of item to be retrieved.
 *  menuData        [IN/OUT]        UI structure to store the list data.
 *  num_item        [IN]            Number of items revrieved.
 * RETURNS
 *  number of items can be retrieved.
 *****************************************************************************/
S32 mmi_email_folder_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    mmi_mem_pool_ret_enum ret_result;

    mmi_email_mail_info_struct *listMsgsStruct[EMAIL_TOTAL_MSG_BUFF];
    U16 tmp_len; /*len of From and len of subject*/
    U16 n_from_len;
    U16 n_subject_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->mem_pool_info.start_indx = start_indx;
    email_p->mem_pool_info.end_indx = (start_indx + num_item) - 1;
    ret_result = mmi_mem_get_values(
                    &email_p->mem_pool_info.mem_container,
                    (S16) email_p->mem_pool_info.start_indx,
                    (S16) email_p->mem_pool_info.end_indx,
                    (void **)listMsgsStruct,
                    &email_p->mem_pool_info.not_avail_pool);

    if (ret_result != MEM_CT_SUCCESS)
    {
    #if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
        if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_POP3 || email_p->main_info.curr_menu == MMI_EMAIL_UNSENT)
    #endif 
        {
            email_p->fldr_info.curr_page = email_p->mem_pool_info.not_avail_pool + 1;
        }
        if (email_p->fldr_info.is_list_displayed)
        {
            mmi_email_fldr_pre_folder_select_req();
        }
        return 0;   /* no items available */
    }

    /* fill data */
    for (j = 0; j < num_item; j++)
    {
        U16 status_img;
        U16 attch_img[MMI_EMAIL_MAX_NUM_ATTACH];

        mmi_email_mail_info_struct *temp = listMsgsStruct[j];

        /*the first line*/
        /*item_list[i] at most reach MAX_SUB_MENU_SIZE(41) characters*/
        mmi_ucs2cpy((S8*) menuData[j].item_list[0], (S8*)g_email_subj_left_op); /* '<' */
        tmp_len = mmi_ucs2strlen((S8*) temp->addr_buff);
        if(tmp_len > EMAIL_MAX_FROM_STR_LEN)
        {
            n_from_len = EMAIL_MAX_FROM_STR_LEN - mmi_ucs2strlen((S8*) g_email_3dots);
            mmi_ucs2ncat((S8*) menuData[j].item_list[0], (S8*) temp->addr_buff, n_from_len);
            mmi_ucs2cat((S8*) menuData[j].item_list[0], (S8*) g_email_3dots);/*...*/
            n_from_len = EMAIL_MAX_FROM_STR_LEN + 2; /*addr + ... + <>*/ 
        }
        else
        {
            n_from_len = tmp_len;
            mmi_ucs2ncat((S8*) menuData[j].item_list[0], (S8*) temp->addr_buff, n_from_len);
            n_from_len += 2; /*addr + <>*/ 
        }
        mmi_ucs2cat((S8*) menuData[j].item_list[0], (S8*)g_email_subj_right_op); /* '>' */
        
        if (!mmi_ucs2strlen((S8*) temp->subject))
        {
            mmi_ucs2ncat(
                (S8*) menuData[j].item_list[0],
                (S8*) GetString(STR_EMAIL_COMMON_NO_SUBJECT_ID),
                EMAIL_MAX_SUBJ_DISPLAY_STR_LEN);
        }
        else
        {
            tmp_len = mmi_ucs2strlen((S8*) temp->subject);
            if(tmp_len > (MAX_SUB_MENU_SIZE - n_from_len))
            {
                n_subject_len = MAX_SUB_MENU_SIZE - n_from_len - mmi_ucs2strlen((S8*) g_email_3dots);
                mmi_ucs2ncat((S8*) menuData[j].item_list[0], (S8*) temp->subject, n_subject_len);
                mmi_ucs2cat((S8*) menuData[j].item_list[0], (S8*) g_email_3dots);/*...*/
            }
            else
            {
                mmi_ucs2ncat((S8*) menuData[j].item_list[0], (S8*) temp->subject, tmp_len);
            }
        }
        
        /*the second line*/       
        mmi_ucs2cpy((S8*) menuData[j].item_list[1], (S8*) temp->dt_buff);
        mmi_ucs2cat((S8*) menuData[j].item_list[1], (S8*) temp->size_buff);
        
        /*  fill status icon */
        status_img = mmi_email_folder_get_status_icon(temp->priority, temp->is_read, temp->delete_flag);
        menuData[j].image_list[0] = (PU8) GetImage(status_img);
        
        mmi_email_folder_get_attch_icon(temp->attch_num, temp->attch_type, attch_img);
        for (i = 0; i < temp->attch_num; i++)
        {
            menuData[j].image_list[i + 1] = (PU8) GetImage(attch_img[i]);
        }
        
        /* fill null pointer to prevent abnormal cases */
        for (; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
        {
            menuData[j].image_list[i + 1] = NULL;
        }
    }
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_inbox_opt
 * DESCRIPTION
 *  Entry Option screen of Inbox->Read
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_inbox_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;
    U16 parentMenuId = MENU_ID_EMAIL_INBOX_READ_OPT;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_INBOX_OPT, NULL, mmi_email_entry_inbox_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_INBOX_OPT);
    /* extract address menu */
    if(email_p->inbox_info.read_info.curr_inline_item == EMAIL_COMP_CONT)
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_INBOX_OPT_EXTRACT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_INBOX_OPT_EXTRACT);
    }
    /* mark deleted menu */
    if (email_p->fldr_info.curr_delete_flag == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_INBOX_OPT_MARK_DELETED);
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_INBOX_OPT_UNMARK_DELETED);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_INBOX_OPT_MARK_DELETED);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_INBOX_OPT_UNMARK_DELETED);
    }
    mmi_frm_unhide_menu_item(MENU_ID_EMAIL_INBOX_OPT_MARK_UNREAD);
    /* retrieve option menu */
    mmi_frm_unhide_menu_item(MENU_ID_EMAIL_INBOX_OPT_RETRIEVE_OPTION);
    email_p->fldr_info.curr_msg_all = MMI_FALSE;
    if (mmi_email_fldr_is_part_all())
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_INBOX_OPT_RETRIEVE_OPTION);
        email_p->fldr_info.curr_msg_all = MMI_TRUE;
    }
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        if (EMAIL_IS_MODE(EMAIL_MODE_OFFLINE))
        {
            mmi_frm_hide_menu_item(MENU_ID_EMAIL_INBOX_OPT_RETRIEVE_OPTION);
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(parentMenuId);
    numItems = GetNumOfChild_Ext(parentMenuId);
    GetSequenceStringIds_Ext(parentMenuId, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_inbox_fill_reply_data
 * DESCRIPTION
 *  Fill common data for Reply
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_inbox_fill_reply_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 subLenToBeReplied;
    U32 prefixReWithColonStrLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_comp_reset_member();

    email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr = 1;
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.reply_to_addr))
    {
        /* copy Reply-to address to To */
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
            (S8*) email_p->inbox_info.reply_to_addr);
    }
    else
    {
        /* copy From to To */
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
            (S8*) email_p->inbox_info.from_info.from_addr);
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0],
            (S8*) email_p->inbox_info.from_info.from_name);
    }

    /* Display buffer of From */
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]))
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
    }

    /* fill subject with "RE: <previous >" */
    subLenToBeReplied = mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.subj_buff);
    prefixReWithColonStrLen = mmi_ucs2strlen((S8*)GetString(STR_EMAIL_REPLY_IND_ID));
    if ((subLenToBeReplied + prefixReWithColonStrLen) > EMAIL_COMP_SUBJ_LEN)
    {
        subLenToBeReplied = EMAIL_COMP_SUBJ_LEN - prefixReWithColonStrLen;
    }

    mmi_ucs2cpy((S8*) email_p->comp_info.subj_buff, (S8*)GetString(STR_EMAIL_REPLY_IND_ID));
    mmi_ucs2ncat(
        (S8*) email_p->comp_info.subj_buff,
        (S8*) email_p->inbox_info.read_info.subj_buff,
        subLenToBeReplied);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_inbox_reply
 * DESCRIPTION
 *  Execute Read->Reply option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_inbox_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_inbox_fill_reply_data();
    /* content */
    mmi_ucs2cpy((S8*) email_p->comp_info.cont_buff, (S8*) email_p->inbox_info.read_info.cont_buff);

    /* attachment */
    mmi_email_util_rename_read_to_comp();

    /* entry Write Email screen */
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_inbox_reply_without
 * DESCRIPTION
 *  Execute Read->Reply Without Content option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_inbox_reply_without(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_inbox_fill_reply_data();

    /* display compose screen */
    if (mmi_email_comp_add_sig() == FALSE)
    {
        return;
    }
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_inbox_fill_reply_all_data
 * DESCRIPTION
 *  Fill common data for Reply All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_inbox_fill_reply_all_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 j;
    U32 subLenToBeReplied;
    U32 prefixReWithColonStrLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_comp_reset_member();

    if (mmi_ucs2strlen((S8*) email_p->inbox_info.reply_to_addr))
    {
        /* copy Reply-to address to To */
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
            (S8*) email_p->inbox_info.reply_to_addr);
    }
    else
    {
        /* copy From to To */
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
            (S8*) email_p->inbox_info.from_info.from_addr);
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0],
            (S8*) email_p->inbox_info.from_info.from_name);
    }
    email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr = 1;

    /* From TO to TO */
    i = 1;
    for (j = 0; j < email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].num_addr; j++)
    {
        if (mmi_ucs2cmp
            ((S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[j],
             (S8*) email_p->prof_info.act_prof.email_addr))
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[i],
                (S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[j]);
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[i],
                (S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].to_cc_name[j]);
            email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr++;
            i++;
        }

        if (email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr == MMI_EMAIL_MAX_LEN_ADDR_LIST)
        {
            break;
        }
    }

    /* display buffer of TO */
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]))
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
    }

    if (email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr > 1)
    {
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_3dots);
    }

    /* copy CC to CC */
    for (i = 0; i < email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].num_addr; i++)
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_CC].to_cc_mail[i],
            (S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].to_cc_mail[i]);
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_CC].to_cc_name[i],
            (S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].to_cc_name[i]);
        email_p->comp_info.addr_list[EMAIL_ADDR_CC].num_addr++;
    }

    /* display buffer of CC */
    if (email_p->comp_info.addr_list[EMAIL_ADDR_CC].num_addr != 0)
    {
        if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[EMAIL_ADDR_CC].to_cc_name[0]))
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC],
                (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_CC].to_cc_name[0]);
            mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC], (S8*) g_email_subj_left_op);
            mmi_ucs2cat(
                (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC],
                (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_CC].to_cc_mail[0]);
            mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC], (S8*) g_email_subj_right_op);
        }
        else
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC],
                (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_CC].to_cc_mail[0]);
        }

        if (email_p->comp_info.addr_list[EMAIL_ADDR_CC].num_addr > 1)
        {
            mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_CC], (S8*) g_email_3dots);
        }
    }

    /* subject with "RE: <previous >" */
    subLenToBeReplied = mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.subj_buff);
    prefixReWithColonStrLen = mmi_ucs2strlen((S8*)GetString(STR_EMAIL_REPLY_IND_ID));
    if ((subLenToBeReplied + prefixReWithColonStrLen) > EMAIL_COMP_SUBJ_LEN)
    {
        subLenToBeReplied = EMAIL_COMP_SUBJ_LEN - prefixReWithColonStrLen;
    }
    mmi_ucs2cpy((S8*) email_p->comp_info.subj_buff, (S8*)GetString(STR_EMAIL_REPLY_IND_ID));
    mmi_ucs2ncat(
        (S8*) email_p->comp_info.subj_buff,
        (S8*) email_p->inbox_info.read_info.subj_buff,
        subLenToBeReplied);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_inbox_reply_all
 * DESCRIPTION
 *  Execute Read->Reply All option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_inbox_reply_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_inbox_fill_reply_all_data();
    /* content */
    mmi_ucs2cpy((S8*) email_p->comp_info.cont_buff, (S8*) email_p->inbox_info.read_info.cont_buff);

    /* attachment */
    mmi_email_util_rename_read_to_comp();
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_inbox_reply_all_without
 * DESCRIPTION
 *  Execute Read->Reply All Without Content option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_inbox_reply_all_without(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_inbox_fill_reply_all_data();

    /* display compose screen */
    if (mmi_email_comp_add_sig() == FALSE)
    {
        return;
    }
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_inbox_reply
 * DESCRIPTION
 *  Handler for Read Email -> Reply
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_inbox_reply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_inbox_reply, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_inbox_reply, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_inbox_reply_without
 * DESCRIPTION
 *  Handler for Read Email -> Reply Without Content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_inbox_reply_without(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_inbox_reply_without, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_inbox_reply_without, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_inbox_reply_all
 * DESCRIPTION
 *  Handler for Read Email -> Reply All
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_inbox_reply_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_inbox_reply_all, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_inbox_reply_all, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_inbox_reply_all_without
 * DESCRIPTION
 *  Handler for Read Email -> Reply All Without Content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_inbox_reply_all_without(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_inbox_reply_all_without, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_inbox_reply_all_without, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_mark_unread
 * DESCRIPTION
 *  Handler for Read Email -> Mark as unread
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_mark_unread(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_mark_unread, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_mark_unread, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#define READ_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_forward
 * DESCRIPTION
 *  Execute Read->Forward option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_fldr_prepare_forward();

    mmi_email_util_rename_read_to_comp();
    /* display compose screen */
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_edit
 * DESCRIPTION
 *  Execute Read->Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_fldr_prepare_edit();

    mmi_email_util_rename_read_to_comp();
    /* display compose screen */
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_extract
 * DESCRIPTION
 *  Entry Screen: Read->Address extract
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_extract(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    /* display children menu: phone number, email address, web address */
    EntryNewScreen(SCR_ID_EMAIL_READ_OPT_EXTRACT, NULL, mmi_email_read_extract, NULL);

    /* reset the menu item */
    mmi_frm_unhide_menu_item(MENU_ID_EMAIL_EXTRACT_WEBADDR);
    
#ifndef WAP_SUPPORT 
    mmi_frm_hide_menu_item(MENU_ID_EMAIL_EXTRACT_WEBADDR);     
#endif /* WAP_SUPPORT */ 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_OPT_EXTRACT);
    SetParentHandler(MENU_ID_EMAIL_INBOX_OPT_EXTRACT);

    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_INBOX_OPT_EXTRACT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_INBOX_OPT_EXTRACT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_EMAIL_EXTRACT_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_addr_send
 * DESCRIPTION
 *  Execute Read->Address List -> Send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_addr_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->misc_info.curr_hilite_attch;

    S32 activeInputAddrMode = email_p->comp_info.curr_addr_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_comp_reset_member();

    /* copy user SELECETD entry to TO */
    email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr = 1;
    if (activeInputAddrMode == EMAIL_ADDR_FROM)
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
            (S8*) email_p->inbox_info.from_info.from_addr);
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0],
            (S8*) email_p->inbox_info.from_info.from_name);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
            (S8*) email_p->inbox_info.read_info.addr_list[activeInputAddrMode].to_cc_mail[i]);
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0],
            (S8*) email_p->inbox_info.read_info.addr_list[activeInputAddrMode].to_cc_name[i]);
    }

    /* display buffer */
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]))
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
    }

    /* display compose screen */
    if (mmi_email_comp_add_sig() == FALSE)
    {
        return;
    }
    mmi_email_entry_comp();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_addr_save
 * DESCRIPTION
 *  Execute Read->Address List -> Save to Phonebook option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_addr_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMailAddr = NULL;
    S8 *pMailName = NULL;
    S32 curr_addr = email_p->comp_info.curr_addr_type;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->comp_info.curr_addr_type == EMAIL_ADDR_FROM)
    {
        if (mmi_ucs2strlen((S8*) email_p->inbox_info.from_info.from_addr))
        {
            pMailAddr = (S8*) email_p->inbox_info.from_info.from_addr;
        }
        if (mmi_ucs2strlen((S8*) email_p->inbox_info.from_info.from_name))
        {
            pMailName = (S8*) email_p->inbox_info.from_info.from_name;
        }
    }
    else    /* take use of the order of TO and CC */
    {
        if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_list[curr_addr].to_cc_mail[i]))
        {
            pMailAddr = (S8*) email_p->inbox_info.read_info.addr_list[curr_addr].to_cc_mail[i];
        }
        if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_list[curr_addr].to_cc_name[i]))
        {
            pMailName = (S8*) email_p->inbox_info.read_info.addr_list[curr_addr].to_cc_name[i];
        }
    }

    mmi_phb_email_save_entry_to_phb(pMailName, pMailAddr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_phonenumber_call
 * DESCRIPTION
 *  Execute Read->Address Extract ->Number List -> Dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_phonenumber_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pNumber = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.cont_addr_ucs2_buff[i]))
    {
        pNumber = (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i];
#ifdef __MMI_UCM__
        mmi_ucm_app_entry_dial_option((U8*)pNumber, NULL, NULL);
#else
        MakeCall(pNumber);
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_phonenumber_call_ext
 * DESCRIPTION
 *  Execute Read->Address Extract ->Number List -> Dial (SEND_KEY)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_phonenumber_call_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pNumber = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.cont_addr_ucs2_buff[i]))
    {
        pNumber = (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i];
        MakeCall(pNumber);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_phonenumber_save
 * DESCRIPTION
 *  Execute Read->Address Extract ->Number List -> Save to phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_phonenumber_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pNumber = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pNumber = (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i];
    
    SaveNumberFromIdleScrn(pNumber, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_email_send_email
 * DESCRIPTION
 *  Execute Read->Address Extract ->Email Address -> Send email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_email_send_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMailAddr = NULL;
    S8 *pMailName = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_comp_reset_member();
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.cont_addr_ucs2_buff[i]))
    {
        pMailAddr = (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i];
    }

    mmi_ucs2cpy(
    (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
    (S8*) pMailAddr);
    mmi_ucs2cpy(
        (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0],
        (S8*) pMailName);
    email_p->comp_info.addr_list[EMAIL_ADDR_TO].num_addr = 1;

    /* display buffer */
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]))
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
    }

        /* display compose screen */
    if (mmi_email_comp_add_sig() == FALSE)
    {
        return;
    }
    mmi_email_entry_comp();

    /* release the extracted address buffer */
    mmi_email_read_cont_addr_release_buf();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_email_save
 * DESCRIPTION
 *  Execute Read->Address Extract ->Email Address -> Save to phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_email_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pMailAddr = NULL;
    S8 *pMailName = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;
    S8 mmi_email_email_addr_tmp_buf[(MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH];      /*tmp buf for email address to save to phonebook*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*init buf*/
    memset(mmi_email_email_addr_tmp_buf, 0, ((MAX_PB_EMAIL_LENGTH + 1) * ENCODING_LENGTH));
        
    mmi_ucs2ncpy(
        (S8*) mmi_email_email_addr_tmp_buf,
        (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i],
        MAX_PB_EMAIL_LENGTH);

    pMailAddr = mmi_email_email_addr_tmp_buf;

    pMailName = NULL;
    
    mmi_phb_email_save_entry_to_phb(pMailName, pMailAddr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_url_connect
 * DESCRIPTION
 *  Execute Read->Address Extract ->URL address -> connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_url_connect(void)
{
#ifdef WAP_SUPPORT

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pUrlAddr = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pUrlAddr = (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i];
    
    wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)pUrlAddr);

#endif /*WAP_SUPPORT*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_url_add_bookmark
 * DESCRIPTION
 *  Execute Read->Address Extract ->URL address -> add to bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_url_add_bookmark(void)
{
#ifdef WAP_SUPPORT

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pUrlAddr = NULL;
    S32 i = email_p->misc_info.curr_hilite_attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pUrlAddr = (S8*) email_p->inbox_info.cont_addr_ucs2_buff[i];
   
    wap_start_browser(WAP_BROWSER_ADD_BOOKMARK, (const kal_uint8*)pUrlAddr);

#endif /*WAP_SUPPORT*/    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_addr_save_phb
 * DESCRIPTION
 *  Handler for Read Email -> Address -> Save to Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_addr_save_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_addr_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_addr_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_cont_addr_phonenumber_call
 * DESCRIPTION
 *  Handler for Read Email -> Address Extract ->Number List -> Dial
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_cont_addr_phonenumber_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_email_read_cont_addr_phonenumber_call, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_phonenumber_call, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_cont_addr_phonenumber_save_phb
 * DESCRIPTION
 *  Handler for Read Email -> Address Extract ->Number List -> Save to Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_cont_addr_phonenumber_save_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_email_read_cont_addr_phonenumber_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_phonenumber_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_cont_addr_email_send_email
 * DESCRIPTION
 *  Handler for Read Email -> Address Extract ->email address ->send email
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_cont_addr_email_send_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_email_read_cont_addr_email_send_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_email_send_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_cont_addr_email_save_phb
 * DESCRIPTION
 *  Handler for Read Email -> Address Extract ->email address -> Save to Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_cont_addr_email_save_phb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_email_read_cont_addr_email_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_email_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_cont_addr_url_connect
 * DESCRIPTION
 *  Handler for Read Email -> Address Extract ->URL address ->connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_cont_addr_url_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_email_read_cont_addr_url_connect, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_url_connect, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_cont_addr_url_add_bookmark
 * DESCRIPTION
 *  Handler for Read Email -> Address Extract ->URL address ->Add to bookmark
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_cont_addr_url_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_email_read_cont_addr_url_add_bookmark, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_url_add_bookmark, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_addr_send
 * DESCRIPTION
 *  Handler for Read Email -> Address -> Send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_addr_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_addr_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_addr_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attach_view
 * DESCRIPTION
 *  Handler for Read Email -> Attachment -> View
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attach_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_read_attch_view, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_read_attch_view, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attach_save
 * DESCRIPTION
 *  Handler for Read Email -> Attachment -> Save
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attach_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_attach_save, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_attach_save, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attach_save_done
 * DESCRIPTION
 *  Handler for Read Email -> Attachment -> Save -> Done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attach_save_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_save_attch, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_save_attch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attach_save_input_meth
 * DESCRIPTION
 *  Handler for Read Email -> Attachment -> Save -> Input Method
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attach_save_input_meth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    SetKeyHandler(EntryInputMethodScreen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    RegisterInputMethodScreenCloseFunction(mmi_email_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_forward
 * DESCRIPTION
 *  Handler for Read Email -> Forward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_forward, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_forward, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_edit
 * DESCRIPTION
 *  Highlight handler of of folder-> Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_extract
 * DESCRIPTION
 *  Handler for Read Email -> address extract
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_extract(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_extract, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_extract, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_extract_phonenumber
 * DESCRIPTION
 *  Handler for Read Email ->address extract->phone number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_extract_phonenumber(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->inbox_info.curr_cont_addr_type = EMAIL_CONT_ADDR_PHONENUMBER;
    SetLeftSoftkeyFunction(mmi_email_read_goto_cont_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_goto_cont_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_extract_emailaddr
 * DESCRIPTION
 *  Handler for Read Email ->address extract->email address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_extract_emailaddr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->inbox_info.curr_cont_addr_type = EMAIL_CONT_ADDR_EMAIL;
    SetLeftSoftkeyFunction(mmi_email_read_goto_cont_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_goto_cont_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_extract_webaddr
 * DESCRIPTION
 *  Handler for Read Email ->address extract->url address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_extract_webaddr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->inbox_info.curr_cont_addr_type = EMAIL_CONT_ADDR_URL;
    SetLeftSoftkeyFunction(mmi_email_read_goto_cont_addr, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_goto_cont_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_retrieve_option
 * DESCRIPTION
 *  Handler for Read Email -> Retrieve Option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_retrieve_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_retrieve_option, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_retrieve_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_mark_deleted
 * DESCRIPTION
 *  Handler for Read Email -> Mark as Deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_mark_deleted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_mark_deleted, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_mark_deleted, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_rsk_hdlr
 * DESCRIPTION
 *  Right soft key event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->fldr_info.is_part_download == EMAIL_DOWN_POP3))
    {
        email_p->fldr_info.is_part_download = EMAIL_DOWN_TEMP;
        mmi_email_fldr_reset_list_info_ex();
        mmi_email_fldr_pre_folder_select_req();
    }
    else
    {
        GoBackHistory();
    }
    email_p->fldr_info.curr_unread_flag = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read
 * DESCRIPTION
 *  Entry Read Email screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 emailEmailReadEditorIconsinbox[EMAIL_READ_TOTAL] = 
    {
        IMG_EMAIL_READ_FROM_ID,
        IMG_EMAIL_READ_TO_ID,
        IMG_EMAIL_READ_CC_ID,
    #ifdef __MMI_EMAIL_BCC__
        IMG_EMAIL_READ_BCC_ID,
    #endif /*__MMI_EMAIL_BCC__*/
        IMG_EMAIL_READ_SUBJECT_ID,
        IMG_EMAIL_READ_ATTACHMENT_ID,
        0
    };
    U16 emailEmailReadEditorIconsother[EMAIL_READ_TOTAL - 1] = 
    {
        IMG_EMAIL_READ_TO_ID,
        IMG_EMAIL_READ_CC_ID,
#ifdef __MMI_EMAIL_BCC__
        IMG_EMAIL_READ_BCC_ID,
#endif /*__MMI_EMAIL_BCC__*/
        IMG_EMAIL_READ_SUBJECT_ID,
        IMG_EMAIL_READ_ATTACHMENT_ID,
        0
    };

    U16 *emailEmailReadEditorIcons;
    S32 item_number;
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ, mmi_email_exit_read, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_READ, &inputBufferSize);

    InitializeCategory57Screen();
    if (EMAIL_IS_MENU(MMI_EMAIL_INBOX))
    {
        emailEmailReadEditorIcons = emailEmailReadEditorIconsinbox;
        item_number = EMAIL_READ_TOTAL;
    }
    else
    {
        emailEmailReadEditorIcons = emailEmailReadEditorIconsother;
        item_number = EMAIL_READ_TOTAL - 1;
    }

    mmi_email_read_fill_inline_struct();

    RegisterHighlightHandler(mmi_email_hilite_read_item);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, item_number, inputBuffer);
    }

    email_p->fldr_info.curr_sel_flag = EMAIL_SEL_NORMAL;
    /* sync current highlight item as normal email */
    ShowCategory57Screen(
        STR_EMAIL_FROM_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_number,
        (U16*) emailEmailReadEditorIcons,
        wgui_inline_items,
        (S32) email_p->inbox_info.read_info.curr_inline_item,
        guiBuffer);
    SetCategory57RightSoftkeyFunctions(mmi_email_entry_read_opt, mmi_email_read_rsk_hdlr);

    if ((email_p->inbox_info.read_info.except_popup & EMAIL_EXCEPT_CON_EXCEED) == EMAIL_EXCEPT_CON_EXCEED)
    {
        email_p->inbox_info.read_info.except_popup &= ~EMAIL_EXCEPT_CON_EXCEED;
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_CONTENT_MESSAGE_TOO_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_read
 * DESCRIPTION
 *  Exit Read Email screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_n_history(SCR_ID_EMAIL_READ, mmi_email_entry_read);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_fill_inline_struct
 * DESCRIPTION
 *  Fill inline structure for Read Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_fill_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 leftArrowImage;
    PU8 rightArrowImage;
    S32 item_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* "FROM" */
    if (EMAIL_IS_MENU(MMI_EMAIL_INBOX))
    {
        rightArrowImage = NULL;
        leftArrowImage = NULL;
        SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
        if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.from_addr))
        {
            if (!r2lMMIFlag)
            {
                leftArrowImage = NULL;
                rightArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
            }
            else
            {
                rightArrowImage = NULL;
                leftArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
            }
        }
        SetInlineItemImageText(
            &(wgui_inline_items[item_index]),
            (U8*) email_p->inbox_info.read_info.from_addr,
            (PU8) GetImage(IMG_EMAIL_READ_FROM_ID),
            leftArrowImage,
            rightArrowImage,
            sizeof(email_p->inbox_info.read_info.from_addr),
            STR_EMAIL_FROM_ID,
            0,
            INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
        SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[item_index]), mmi_email_entry_read_opt);
#ifdef __MMI_TOUCH_SCREEN__
        if (!r2lMMIFlag)
        {
            SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), NULL, mmi_email_read_goto_addr);
        }
        else
        {
            SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), mmi_email_read_goto_addr, NULL);
        }
#endif 
        ShowAsControl(&(wgui_inline_items[item_index]));
        item_index += 1;
    }

    /* "TO" */
    rightArrowImage = NULL;
    leftArrowImage = NULL;
    SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_TO]))
    {
        if (!r2lMMIFlag)
        {
            leftArrowImage = NULL;
            rightArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
        }
        else
        {
            rightArrowImage = NULL;
            leftArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
        }
    }
    SetInlineItemImageText(
        &(wgui_inline_items[item_index]),
        (U8*) email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_TO],
        (PU8) GetImage(IMG_EMAIL_READ_TO_ID),
        leftArrowImage,
        rightArrowImage,
        sizeof(email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_TO]),
        STR_EMAIL_TO_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[item_index]), mmi_email_entry_read_opt);
#ifdef __MMI_TOUCH_SCREEN__
    if (!r2lMMIFlag)
    {
        SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), NULL, mmi_email_read_goto_addr);
    }
    else
    {
        SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), mmi_email_read_goto_addr, NULL);
    }
#endif 
    ShowAsControl(&(wgui_inline_items[item_index]));
    item_index += 1;

    /* "CC" */
    rightArrowImage = NULL;
    leftArrowImage = NULL;
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_CC]))
    {
        if (!r2lMMIFlag)
        {
            leftArrowImage = NULL;
            rightArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
        }
        else
        {
            rightArrowImage = NULL;
            leftArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
        }
    }
    SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[item_index]),
        (U8*) email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_CC],
        (PU8) GetImage(IMG_EMAIL_READ_CC_ID),
        leftArrowImage,
        rightArrowImage,
        sizeof(email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_CC]),
        STR_EMAIL_CC_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[item_index]), mmi_email_entry_read_opt);
#ifdef __MMI_TOUCH_SCREEN__
    if (!r2lMMIFlag)
    {
        SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), NULL, mmi_email_read_goto_addr);
    }
    else
    {
        SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), mmi_email_read_goto_addr, NULL);
    }
#endif 
    ShowAsControl(&(wgui_inline_items[item_index]));
    item_index += 1;

#ifdef __MMI_EMAIL_BCC__
    /* "BCC" */
    rightArrowImage = NULL;
    leftArrowImage = NULL;
    if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_BCC]))
    {
        if (!r2lMMIFlag)
        {
            leftArrowImage = NULL;
            rightArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
        }
        else
        {
            rightArrowImage = NULL;
            leftArrowImage = (PU8) GetImage(RIGHT_RED_ARROW);
        }
    }
    SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[item_index]),
        (U8*) email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_BCC],
        (PU8) GetImage(IMG_EMAIL_READ_BCC_ID),
        leftArrowImage,
        rightArrowImage,
        sizeof(email_p->inbox_info.read_info.addr_disp_buff[EMAIL_ADDR_BCC]),
        STR_EMAIL_BCC_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[item_index]), mmi_email_entry_read_opt);
#ifdef __MMI_TOUCH_SCREEN__
    if (!r2lMMIFlag)
    {
        SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), NULL, mmi_email_read_goto_addr);
    }
    else
    {
        SetInlineImageTextPenHandler(&(wgui_inline_items[item_index]), mmi_email_read_goto_addr, NULL);
    }
#endif 
    ShowAsControl(&(wgui_inline_items[item_index]));
    item_index += 1;
#endif /*__MMI_EMAIL_BCC__*/

    /* "SUBJECT" */
    SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageText(
        &(wgui_inline_items[item_index]),
        (U8*) email_p->inbox_info.read_info.subj_buff,
        (PU8) GetImage(IMG_EMAIL_READ_SUBJECT_ID),
        NULL,
        NULL,
        sizeof(email_p->inbox_info.read_info.subj_buff),
        STR_EMAIL_SUBJECT_ID,
        0,
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE);
    SetInlineFullScreenEditCustomFunctionImageText(&(wgui_inline_items[item_index]), mmi_email_entry_read_opt);
    ShowAsControl(&(wgui_inline_items[item_index]));
    item_index += 1;

    /* "ATTACHMENT" */
    SetInlineItemActivation(&wgui_inline_items[item_index], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemImageAttachment(
        &wgui_inline_items[item_index],
        (PU8) GetImage(IMG_EMAIL_READ_ATTACHMENT_ID),
        NULL,
        NULL,
        STR_EMAIL_ATTACHMENT_ID,
        0,
        email_p->misc_info.curr_hilite_attch);
    RegisterAttachmentHighlightedFunction(&wgui_inline_items[item_index], mmi_email_hilite_read_attch);
    RegisterAttachmentLskFunction(&wgui_inline_items[item_index], mmi_email_read_attch_lsk);
    RegisterAttachmentRskFunction(&wgui_inline_items[item_index], mmi_email_read_attch_rsk);
    mmi_email_read_fill_attch_icon(item_index);
    item_index += 1;

    /* "CONTENT" */
    SetInlineItemActivation(&wgui_inline_items[item_index], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineMultiLineRdOnly(
        &wgui_inline_items[item_index],
        (U8*) email_p->inbox_info.read_info.cont_buff,
        mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.cont_buff),
        INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        7);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_fill_attch_icon
 * DESCRIPTION
 *  Fill attachment icons according to their types.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_fill_attch_icon(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 img_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllAttachmentImages(&wgui_inline_items[item_index], MMI_EMAIL_MAX_NUM_ATTACH);

    for (i = 0; i < MMI_EMAIL_MAX_NUM_ATTACH; i++)
    {
        if ((!email_p->inbox_info.read_info.attch_list[i].attch_present) && 
            (email_p->inbox_info.read_info.attch_list[i].attch_cached == EMAIL_ATT_NOT))
        {
            continue;
        }
        if (email_p->inbox_info.read_info.attch_list[i].attch_cached == EMAIL_ATT_NOT_CACHED)
        {
            img_id = mmi_email_util_get_attch_icon_ex(email_p->inbox_info.read_info.attch_list[i].attch_type);
        }
        else
        {
            img_id = mmi_email_util_get_attch_icon((S8*) email_p->inbox_info.read_info.attch_list[i].file_path); 
        }

        email_p->inbox_info.read_info.attch_icon[i].image1 = (PU8) GetImage(img_id);
    }

    AddEmailImageAttachmentUI(
        &wgui_inline_items[item_index],
        (wgui_inline_images_detail*) email_p->inbox_info.read_info.attch_icon);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_attch_lsk
 * DESCRIPTION
 *  LSK handler of Inbox->Read->Attachment
 * PARAMETERS
 *  image       [IN]        Currently no use.
 *  str         [IN]        Currently no use.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_attch_lsk(PU8 image, UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((email_p->inbox_info.read_info.total_attch != 0) ||
        (email_p->fldr_info.curr_total_att != 0))
    {
        mmi_email_entry_read_attch();
    }
    else
    {
        mmi_email_entry_read_opt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_attch_rsk
 * DESCRIPTION
 *  RSK handler of Inbox->Read->Attachment
 * PARAMETERS
 *  image       [IN]        Currently no use.
 *  str         [IN]        Currently no use.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_attch_rsk(PU8 image, UI_string_type str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_item
 * DESCRIPTION
 *  Highlight handler of inline items in Read email screen
 * PARAMETERS
 *  index       [IN]        Index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->comp_info.curr_addr_type = EMAIL_ADDR_NONE;
    email_p->inbox_info.read_info.curr_inline_item = (U8) index;
    if (email_p->main_info.curr_menu != MMI_EMAIL_INBOX)
    {
        index += 1;
    }

    switch (index)
    {
        case EMAIL_READ_FROM:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_FROM;
            mmi_email_util_change_title(STR_EMAIL_FROM_ID);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            SetKeyHandler(mmi_email_read_goto_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_email_entry_read_opt, KEY_EVENT_UP);
            break;
        case EMAIL_READ_TO:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_TO;
            mmi_email_util_change_title(STR_EMAIL_TO_ID);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            SetKeyHandler(mmi_email_read_goto_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_email_entry_read_opt, KEY_EVENT_UP);
            break;
        case EMAIL_READ_CC:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_CC;
            mmi_email_util_change_title(STR_EMAIL_CC_ID);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            SetKeyHandler(mmi_email_read_goto_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_email_entry_read_opt, KEY_EVENT_UP);
            break;
    #ifdef __MMI_EMAIL_BCC__
        case EMAIL_READ_BCC:
            email_p->comp_info.curr_addr_type = EMAIL_ADDR_BCC;
            mmi_email_util_change_title(STR_EMAIL_BCC_ID);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            SetKeyHandler(mmi_email_read_goto_addr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_email_entry_read_opt, KEY_EVENT_UP);
            break;
    #endif /*__MMI_EMAIL_BCC__*/
        case EMAIL_READ_SUBJ:
            mmi_email_util_change_title(STR_EMAIL_SUBJECT_ID);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_email_entry_read_opt, KEY_EVENT_UP);
            break;
        case EMAIL_READ_ATTCH:
            mmi_email_util_change_title(STR_EMAIL_ATTACHMENT_ID);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            if (email_p->inbox_info.read_info.total_attch != 0)
            {
                ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OK);
            }
            else
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            }
            break;
        case EMAIL_READ_CONT:
            mmi_email_util_change_title(STR_EMAIL_CONTENT_ID);
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OK);
            SetLeftSoftkeyFunction(mmi_email_entry_read_opt, KEY_EVENT_UP);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_goto_addr
 * DESCRIPTION
 *  Right arrow key handler for Read-> Address list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_goto_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 isEmpty = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->comp_info.curr_addr_type)
    {
        case EMAIL_ADDR_FROM:
            if (mmi_ucs2strlen((S8*) email_p->inbox_info.from_info.from_addr) == 0)
            {
                isEmpty = TRUE;
            }
            break;
        case EMAIL_ADDR_TO:
            if (email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].num_addr == 0)
            {
                isEmpty = TRUE;
            }
            break;
        case EMAIL_ADDR_CC:
            if (email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].num_addr == 0)
            {
                isEmpty = TRUE;
            }
            break;
    #ifdef __MMI_EMAIL_BCC__
        case EMAIL_ADDR_BCC:
            if (email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC].num_addr == 0)
            {
                isEmpty = TRUE;
            }
            break;
    #endif /*__MMI_EMAIL_BCC__*/
    }

    if (isEmpty)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
        mmi_email_entry_read_addr();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_goto_cont_addr
 * DESCRIPTION
 *  get address list(UTF8) from mail content text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_goto_cont_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 isEmpty = FALSE;
    
    U8 *cont_data;
    U16 cont_len;
    U16 inLen;
    U16 outLen;
    kal_int32 tmp_addr_type = 0;
    applib_address_node_struct *p;
    applib_address_node_struct *ptr;
    kal_bool is_stopped = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*free space*/
    mmi_email_read_cont_addr_release_buf();
    
    inLen = (U16) mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.cont_buff) * ENCODING_LENGTH;
    if (inLen)
    {
        switch(email_p->inbox_info.curr_cont_addr_type)
        {
        case EMAIL_CONT_ADDR_PHONENUMBER:
            tmp_addr_type = APPLIB_ADDR_TYPE_PHONENUMBER;
            break;
        case EMAIL_CONT_ADDR_EMAIL:
            tmp_addr_type = APPLIB_ADDR_TYPE_EMAIL;
            break;
        case EMAIL_CONT_ADDR_URL:
            tmp_addr_type = APPLIB_ADDR_TYPE_URL;
            break;
        }         
        
        cont_data = mmi_email_util_ucs2_to_chset((U8*) email_p->inbox_info.read_info.cont_buff, inLen, MMI_CHSET_UTF8, &outLen);
        cont_len = (outLen != 0) ? (outLen - 1) : outLen;
        email_p->inbox_info.cont_addr_list = applib_get_address_list_from_text_ext(
            tmp_addr_type,
            mmi_email_malloc,
            mmi_email_free,
            mmi_email_extract_addr_check_stop_func,
            APPLIB_INPUT_DATA_TYPE_UTF8,
            (char *)cont_data,
            cont_len,
	        &is_stopped);
        
        if(tmp_addr_type == APPLIB_ADDR_TYPE_EMAIL) /*delete email longer than MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS*/
        {
            p = email_p->inbox_info.cont_addr_list;
            ptr = email_p->inbox_info.cont_addr_list;
            while(p != NULL)
            {
                if(p->length > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
                {
                    if (p == email_p->inbox_info.cont_addr_list) /*if the header too long, delete it*/
                    {
                        email_p->inbox_info.cont_addr_list = p->next;
                        OslMfree(p);
                        p = email_p->inbox_info.cont_addr_list;
                        ptr = email_p->inbox_info.cont_addr_list;
                    }
                    else /*delete the node which is not header*/
                    {
                        ptr->next = p->next;
                        OslMfree(p);
                        p = ptr->next; /*set p a new value*/
                    }
                }
                else
                {
                    ptr = p;
                    p = p->next;
                }
            }            
        }

        if(email_p->inbox_info.cont_addr_list == NULL)
        {
            isEmpty = TRUE;
        }
        
        email_p->inbox_info.mmi_email_cont_addr_num = 0; /*init*/
        p = email_p->inbox_info.cont_addr_list;
        while(p != NULL)
        {
            email_p->inbox_info.mmi_email_cont_addr_num++;
            p = p->next;
        }
        
        /*only to display EMAIL_MAX_DISP_ADDR_NUM addresses*/
        if(email_p->inbox_info.mmi_email_cont_addr_num > EMAIL_MAX_DISP_ADDR_NUM)
        {
            email_p->inbox_info.mmi_email_cont_addr_num = EMAIL_MAX_DISP_ADDR_NUM;
        }
        
        if(email_p->inbox_info.mmi_email_cont_addr_num == 0)
        {
            isEmpty = TRUE;
        }
        
        if (cont_data != NULL)
        {
            OslMfree(cont_data);
        }
    }
    else
    {
        isEmpty = TRUE;
    }
    
    if (isEmpty)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
    else
    {
        mmi_email_pre_entry_read_cont_addr();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_addr
 * DESCRIPTION
 *  Entry address list of Read email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U8 *nStrMainItemList[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    U8 *nStrPopupItemList[MMI_EMAIL_MAX_LEN_ADDR_LIST];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ_ADDR, mmi_email_exit_read_addr, mmi_email_entry_read_addr, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_ADDR);
    numItems = mmi_email_read_get_addr_list(nStrMainItemList, nStrPopupItemList);
    ShowCategory53Screen(
        STR_EMAIL_ADDRESS_LIST_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrMainItemList,
        (U16*) gIndexIconsImageList,
        nStrPopupItemList,
        0,
        email_p->misc_info.curr_hilite_attch,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_email_entry_read_addr_opt, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_read_addr_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_pre_entry_read_cont_addr
 * DESCRIPTION
 *  convert address list from UTF8 to UCS2 to display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_pre_entry_read_cont_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numAddr, i = 0, j = 0;
    applib_address_node_struct *p;
    U8 **pTmpBuf;
    U16 out_len;
    kal_int32 tmp_addr_type = 0;
    U8 *tempPtr = NULL;
    U32 tmp_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    numAddr = email_p->inbox_info.mmi_email_cont_addr_num;
    pTmpBuf = (U8**)OslMalloc(sizeof(U8 *) * numAddr);
    
    email_p->inbox_info.cont_addr_ucs2_buff = (U8**)OslMalloc(sizeof(U8 *) * numAddr);
    /*init pointer*/
    for(i=0; i<numAddr; i++)
    {
        email_p->inbox_info.cont_addr_ucs2_buff[i] = NULL;
    }
    
    switch(email_p->inbox_info.curr_cont_addr_type)
    {
    case EMAIL_CONT_ADDR_PHONENUMBER:
        tmp_addr_type = APPLIB_ADDR_TYPE_PHONENUMBER;
        break;
    case EMAIL_CONT_ADDR_EMAIL:
        tmp_addr_type = APPLIB_ADDR_TYPE_EMAIL;
        break;
    case EMAIL_CONT_ADDR_URL:
        tmp_addr_type = APPLIB_ADDR_TYPE_URL;
        break;
    }         
    
    i = 0;
    p = email_p->inbox_info.cont_addr_list;
    while(p != NULL && i < numAddr)
    {
        if(p->dataType == APPLIB_ADDR_TYPE_PHONENUMBER)
        {
            pTmpBuf[i] = (U8 *)p->data2;
        }
        else
        {
            pTmpBuf[i] = (U8 *)p->data;
        }
        i++;

        p = p->next;
    }
    
    for(i = 0; i < numAddr; i++)
    {
        if(pTmpBuf[i] != NULL)
        {
            tempPtr = mmi_email_util_chset_to_ucs2(
                (U8*) pTmpBuf[i],
                (U16) strlen((S8*)pTmpBuf[i]),
                MMI_CHSET_UTF8,
                &out_len);

            if(tempPtr != NULL)
            {
                if(tmp_addr_type == APPLIB_ADDR_TYPE_PHONENUMBER) /*display only 40 characters*/
                {
                    tmp_len = out_len - ENCODING_LENGTH;
                    if(tmp_len > MAX_PB_NUMBER_LENGTH * ENCODING_LENGTH)
                    {
                        tmp_len = MAX_PB_NUMBER_LENGTH * ENCODING_LENGTH;
                    }
                    email_p->inbox_info.cont_addr_ucs2_buff[j] = (U8 *)OslMalloc(tmp_len + ENCODING_LENGTH);
                    mmi_ucs2ncpy((S8*) email_p->inbox_info.cont_addr_ucs2_buff[j], (S8*)tempPtr, (tmp_len/ENCODING_LENGTH));
                    email_p->inbox_info.cont_addr_ucs2_buff[j][tmp_len] = '\0';
                    email_p->inbox_info.cont_addr_ucs2_buff[j][tmp_len + 1] = '\0';                            
                }        
                else if(tmp_addr_type == EMAIL_CONT_ADDR_URL) /*display only 255 characters*/
                {
                    tmp_len = out_len - ENCODING_LENGTH;
                    if(tmp_len > 255 * ENCODING_LENGTH)
                    {
                        tmp_len = 255 * ENCODING_LENGTH;
                    }
                    email_p->inbox_info.cont_addr_ucs2_buff[j] = (U8 *)OslMalloc(tmp_len + ENCODING_LENGTH);
                    mmi_ucs2ncpy((S8*) email_p->inbox_info.cont_addr_ucs2_buff[j], (S8*)tempPtr, (tmp_len/ENCODING_LENGTH));
                    email_p->inbox_info.cont_addr_ucs2_buff[j][tmp_len] = '\0';
                    email_p->inbox_info.cont_addr_ucs2_buff[j][tmp_len + 1] = '\0';
                }
                else /*email address*/
                {
                    tmp_len = out_len - ENCODING_LENGTH;
                    if(tmp_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS * ENCODING_LENGTH)
                    {
                        tmp_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS * ENCODING_LENGTH;
                    }
                    email_p->inbox_info.cont_addr_ucs2_buff[j] = (U8 *)OslMalloc(tmp_len + ENCODING_LENGTH);
                    mmi_ucs2ncpy((S8*) email_p->inbox_info.cont_addr_ucs2_buff[j], (S8*)tempPtr, (tmp_len/ENCODING_LENGTH));
                    email_p->inbox_info.cont_addr_ucs2_buff[j][tmp_len] = '\0';
                    email_p->inbox_info.cont_addr_ucs2_buff[j][tmp_len + 1] = '\0';
                }
                
                OslMfree(tempPtr);
                tempPtr = NULL;
                    
                j++;
            }
        }
        else
        {
            email_p->inbox_info.mmi_email_cont_addr_num--;
        }
    }
    
    if(pTmpBuf != NULL)
    {
        OslMfree(pTmpBuf);
        pTmpBuf = NULL;
    }

    if (email_p->inbox_info.mmi_email_cont_addr_num > 0)
    {
        email_p->misc_info.curr_hilite_attch = 0;
        mmi_email_entry_read_cont_addr();   
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
        /*release buffer*/
        mmi_email_read_cont_addr_release_buf(); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_cont_num_addr_sendkey_handler
 * DESCRIPTION
 *  get highlighted item and Make Call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_cont_num_addr_sendkey_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_read_cont_addr_phonenumber_call_ext();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_cont_addr
 * DESCRIPTION
 *  Entry address list of Read email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_cont_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U8 **nStrMainItemList;
    U8 *guiBuffer;
    U16 i;
    U16 screen_id = SCR_ID_EMAIL_READ_CONT_ADDR_NUMBER_LIST;
    U16 capStrId = STR_EMAIL_PHONENUMBER_ADDRESS_LIST_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*entry addr list screen*/
    switch(email_p->inbox_info.curr_cont_addr_type)
    {
    case EMAIL_CONT_ADDR_PHONENUMBER:
        {
            screen_id = SCR_ID_EMAIL_READ_CONT_ADDR_NUMBER_LIST;
            capStrId = STR_EMAIL_PHONENUMBER_ADDRESS_LIST_ID;
            break;
        }
    case EMAIL_CONT_ADDR_EMAIL:
        {
            screen_id = SCR_ID_EMAIL_READ_CONT_ADDR_EMAIL_LIST;
            capStrId = STR_EMAIL_ADDRESS_LIST_ID;
            break;
        }
    case EMAIL_CONT_ADDR_URL:
        {
            screen_id = SCR_ID_EMAIL_READ_CONT_ADDR_URL_LIST;
            capStrId = STR_EMAIL_URL_ADDRESS_LIST_ID;
            break;
        }
    }
    EntryNewScreen(screen_id, mmi_email_exit_read_cont_addr, mmi_email_entry_read_cont_addr, NULL);

    guiBuffer = GetCurrGuiBuffer(screen_id);

    numItems = email_p->inbox_info.mmi_email_cont_addr_num;

    /*malloc the space for pointer*/
    nStrMainItemList = (U8**)OslMalloc(sizeof(U8 *) * numItems);

    /*init the pointer*/
    for(i=0; i<numItems; i++)
    {
        nStrMainItemList[i] = NULL;
    }
    
    for(i = 0; i < email_p->inbox_info.mmi_email_cont_addr_num; i++)
    {       
        nStrMainItemList[i] = email_p->inbox_info.cont_addr_ucs2_buff[i];      
    }
    
    ShowCategory53Screen(
        capStrId,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrMainItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        email_p->misc_info.curr_hilite_attch,
        guiBuffer);

    if(nStrMainItemList != NULL)
    {
        OslMfree(nStrMainItemList);
        nStrMainItemList = NULL;
    }

    switch(email_p->inbox_info.curr_cont_addr_type)
    {
    case EMAIL_CONT_ADDR_PHONENUMBER:
        {
            SetLeftSoftkeyFunction(mmi_email_entry_read_addr_phonenumber_opt, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_entry_read_addr_phonenumber_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_DUAL_SIM_MASTER__
            MTPNP_PFAL_CC_HandleSendKeys(mmi_email_cont_num_addr_sendkey_handler,KEY_EVENT_DOWN);
#else /* __MMI_DUAL_SIM_MASTER__ */
            SetKeyHandler(mmi_email_cont_num_addr_sendkey_handler, KEY_SEND, KEY_EVENT_DOWN);
#endif /* __MMI_DUAL_SIM_MASTER__ */ 
            break;
        }
    case EMAIL_CONT_ADDR_EMAIL:
        {
            SetLeftSoftkeyFunction(mmi_email_entry_read_addr_email_opt, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_entry_read_addr_email_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        }
    case EMAIL_CONT_ADDR_URL:
        {
            SetLeftSoftkeyFunction(mmi_email_entry_read_addr_url_opt, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_entry_read_addr_url_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            break;
        }
    }         
   
    SetRightSoftkeyFunction(mmi_email_read_cont_addr_rsk_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_cont_addr_rsk_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_read_cont_addr
 * DESCRIPTION
 *  Exit function of address list of email content address extract
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_read_cont_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.curr_hilite_attch = GetHighlightedItem();  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_release_buf
 * DESCRIPTION
 *  free the space of extracted addresses  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_release_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*free space*/
    if(email_p->inbox_info.cont_addr_list != NULL)
    {
        applib_free_address_list((applib_address_node_struct **)&email_p->inbox_info.cont_addr_list, mmi_email_free);
        email_p->inbox_info.cont_addr_list = NULL;
    }

    for(i=0; i<email_p->inbox_info.mmi_email_cont_addr_num; i++)
    {
        if(email_p->inbox_info.cont_addr_ucs2_buff[i] != NULL)
        {
            OslMfree(email_p->inbox_info.cont_addr_ucs2_buff[i]);
            email_p->inbox_info.cont_addr_ucs2_buff[i] = NULL;
        }
    }

    if(email_p->inbox_info.cont_addr_ucs2_buff != NULL)
    {
        OslMfree(email_p->inbox_info.cont_addr_ucs2_buff);
        email_p->inbox_info.cont_addr_ucs2_buff = NULL;
    }

    email_p->inbox_info.mmi_email_cont_addr_num = 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_cont_addr_rsk_hdlr
 * DESCRIPTION
 *  Right soft key handler of read content address.
 *  free the space and go back history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_cont_addr_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*free space*/
    mmi_email_read_cont_addr_release_buf();

    /*go back history*/
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_read_addr
 * DESCRIPTION
 *  Exit function of address list in Read email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_read_addr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.curr_hilite_attch = GetHighlightedItem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_get_addr_list
 * DESCRIPTION
 *  Get address list of Read Email screen
 * PARAMETERS
 *  nStrMainItemList        [IN]        
 *  nStrPopupItemList       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_email_read_get_addr_list(U8 **nStrMainItemList, U8 **nStrPopupItemList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->comp_info.curr_addr_type)
    {
        case EMAIL_ADDR_FROM:
            nStrMainItemList[0] = (U8*) email_p->inbox_info.from_info.from_addr;
            if (mmi_ucs2strlen((S8*) email_p->inbox_info.from_info.from_name))
            {
                nStrPopupItemList[0] = (U8*) email_p->inbox_info.from_info.from_name;
            }
            else
            {
                nStrPopupItemList[0] = NULL;
            }
            return 1;
        case EMAIL_ADDR_TO:
            for (index = 0; index < email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].num_addr; index++)
            {
                nStrMainItemList[index] =
                    (U8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[index];
                if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].to_cc_name[index]))
                {
                    nStrPopupItemList[index] =
                        (U8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].to_cc_name[index];
                }
                else
                {
                    nStrPopupItemList[index] = NULL;
                }
            }
            return email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO].num_addr;
    #ifdef __MMI_EMAIL_BCC__
        case EMAIL_ADDR_BCC:
            for (index = 0; index < email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC].num_addr; index++)
            {
                nStrMainItemList[index] =
                    (U8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC].to_cc_mail[index];
                if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC].to_cc_name[index]))
                {
                    nStrPopupItemList[index] =
                        (U8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC].to_cc_name[index];
                }
                else
                {
                    nStrPopupItemList[index] = NULL;
                }
            }
            return email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC].num_addr;
    #endif /*__MMI_EMAIL_BCC__*/
        default:    /* case EMAIL_ADDR_CC:   */
            for (index = 0; index < email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].num_addr; index++)
            {
                nStrMainItemList[index] =
                    (U8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].to_cc_mail[index];
                if (mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].to_cc_name[index]))
                {
                    nStrPopupItemList[index] =
                        (U8*) email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].to_cc_name[index];
                }
                else
                {
                    nStrPopupItemList[index] = NULL;
                }
            }
            return email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC].num_addr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_addr_phonenumber_opt
 * DESCRIPTION
 *  Entry option screen for Read->address extract ->Number List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_addr_phonenumber_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* save to phb, call*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT, NULL, mmi_email_entry_read_addr_phonenumber_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT);
    SetParentHandler(MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_CONT_ADDR_PHONENUMBER_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
 
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_addr_email_opt
 * DESCRIPTION
 *  Entry option screen for Read->address extract ->email address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_addr_email_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only save to phb and send email */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_CONT_ADDR_EMAIL_OPT, NULL, mmi_email_entry_read_addr_email_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_CONT_ADDR_EMAIL_OPT);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (email_p->mode_status.curr_mode == EMAIL_MODE_OFFLINE))
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SEND_EMAIL);
    }
    else
#endif
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT_SEND_EMAIL);
    }
    SetParentHandler(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT);
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_CONT_ADDR_EMAIL_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_addr_url_opt
 * DESCRIPTION
 *  Entry option screen for Read->address extract ->url address
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_addr_url_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only wap can add to bookmark */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_CONT_ADDR_URL_OPT, NULL, mmi_email_entry_read_addr_url_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_CONT_ADDR_URL_OPT);
    SetParentHandler(MENU_ID_EMAIL_CONT_ADDR_URL_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_CONT_ADDR_URL_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_CONT_ADDR_URL_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_addr_opt
 * DESCRIPTION
 *  Entry option screen for Read->Address List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_addr_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only save to phb can send */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ_ADDR_OPT, NULL, mmi_email_entry_read_addr_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_ADDR_OPT);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4) &&
        (email_p->mode_status.curr_mode == EMAIL_MODE_OFFLINE))
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_READ_ADDR_OPT_SEND);
    }
    else
#endif
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_READ_ADDR_OPT_SEND);
    }
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(MENU_ID_EMAIL_READ_ADDR_OPT);
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_READ_ADDR_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_READ_ADDR_OPT, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_attch
 * DESCRIPTION
 *  Entry attachment list in Read Email screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_attch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 index;
    U8 *nStrItemList[MMI_EMAIL_MAX_NUM_ATTACH];
    U8 *popUpList[EMAIL_MAX_PART_NUMBER + 1];
    S8 fileNumberAnsii[2 * ENCODING_LENGTH];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ_ATTCH, mmi_email_exit_read_attch, mmi_email_entry_read_attch, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_ATTCH);

    for (index = 0; index < email_p->fldr_info.curr_total_att; index++)
    {
        nStrItemList[index] = (U8*) email_p->inbox_info.read_info.attch_list[index].file_name;
        memset(retrieve_att_size[index], 0, sizeof(S8) * 5 * ENCODING_LENGTH);
        sprintf(fileNumberAnsii, "%dK", (email_p->inbox_info.read_info.attch_list[index].size + 1023)/1024);
        mmi_asc_to_ucs2(retrieve_att_size[index], fileNumberAnsii);
        popUpList[index] = (U8*)retrieve_att_size[index];
    }

    RegisterHighlightHandler(mmi_email_hilite_read_attch_item);

    ShowCategory53Screen(
        STR_EMAIL_ATTACHMENT_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U16) email_p->fldr_info.curr_total_att,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        popUpList,
        0,
        email_p->misc_info.curr_hilite_attch,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_read_attch
 * DESCRIPTION
 *  Exit function for attachment list in Read Email screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_read_attch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* store current highlighted index for the usage of Read Email screen */
    email_p->misc_info.curr_hilite_attch = GetHighlightedItem();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attch
 * DESCRIPTION
 *  Callback function of RegisterAttachmentHighlightedFunction
 *  to set current highlight attachment index
 * PARAMETERS
 *  index       [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attch(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.curr_hilite_attch = (U8) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attch_item
 * DESCRIPTION
 *  Highlight handler of attachment in Read email screen
 * PARAMETERS
 *  index       [IN]        Index of current highlighted item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attch_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fileType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.curr_hilite_attch = (U8) index;

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->inbox_info.read_info.attch_list[index].attch_cached == EMAIL_ATT_NOT_CACHED) &&
        (EMAIL_IS_PROT(EMAIL_PROT_IMAP4)))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
        SetLeftSoftkeyFunction(mmi_email_entry_read_attch_opt, KEY_EVENT_UP);
        SetKeyHandler(mmi_email_entry_read_attch_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
#endif
    {
        fileType = mmi_fmgr_get_file_group((S8*) email_p->inbox_info.read_info.attch_list[index].file_path);
        if ((fileType == FMGR_GROUP_IMAGE) || (fileType == FMGR_GROUP_AUDIO) || (fileType == FMGR_GROUP_VIDEO))
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_email_entry_read_attch_opt, KEY_EVENT_UP);
            SetKeyHandler(mmi_email_entry_read_attch_opt, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
        else
        {
            /* unknown attachment types */
            ChangeLeftSoftkey(STR_GLOBAL_SAVE, IMG_GLOBAL_OK);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetLeftSoftkeyFunction(mmi_email_read_attach_save, KEY_EVENT_UP);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_attach_download
 * DESCRIPTION
 *  Handler for Read Email -> Attachment -> Download
 * PARAMETERS
 *  index       [IN]        The index of select item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_attach_download(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_attch_download, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_attch_download, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_attch_opt
 * DESCRIPTION
 *  Entry option screen in Inbox->Read->Attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_attch_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only view and save */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ_ATTCH_OPT, NULL, mmi_email_entry_read_attch_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_ATTCH_OPT);
    kal_mem_set(nStrItemList, 0, 2 * sizeof(U16));
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if ((email_p->inbox_info.read_info.attch_list[email_p->misc_info.curr_hilite_attch].attch_cached == EMAIL_ATT_NOT_CACHED) &&
        (EMAIL_IS_PROT(EMAIL_PROT_IMAP4)))
    {
        numItems = 1;
        nStrItemList[0] = STR_EMAIL_DOWNLOAD_SINGLE_ID;
        RegisterHighlightHandler(mmi_email_hilite_read_attach_download);
    }
    else
#endif
    {
        SetParentHandler(MENU_ID_EMAIL_READ_ATTCH_OPT);
        numItems = GetNumOfChild(MENU_ID_EMAIL_READ_ATTCH_OPT);
        GetSequenceStringIds(MENU_ID_EMAIL_READ_ATTCH_OPT, nStrItemList);
        RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    }

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_attch_download
 * DESCRIPTION
 *  Handler for Read Email -> Attachment -> Download
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_attch_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_get_part_mask);
    SET_PART_MASK(email_p->fldr_info.curr_get_part_mask, 
        EMAIL_PART_MASK_ATTACH(email_p->misc_info.curr_hilite_attch));
    email_p->fldr_info.is_part_download = EMAIL_DOWN_IMAP4;
    mmi_email_ps_folder_msg_select_req();
    DeleteScreenIfPresent(SCR_ID_EMAIL_READ_ATTCH_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_is_part_all
 * DESCRIPTION
 *  Judge current part mask is complete
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mmi_email_fldr_is_part_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    kal_uint8 temp_part_mask[MMI_EMAIL_PART_MASK_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        do
        {
            for (i = 0; i < email_p->fldr_info.curr_total_txt; i++)
            {
                if (!ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, i))
                {
                    return MMI_FALSE;
                }
            }
            for (i = 0; i < email_p->fldr_info.curr_total_att; i++)
            {
                if (!ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(i)))
                {
                    return MMI_FALSE;
                }
            }
        } while(0);
    }
    else
#endif
    {
        EMAIL_SET_GET_CACHE_MASK(temp_part_mask);
        if (kal_mem_cmp(temp_part_mask, email_p->fldr_info.curr_part_mask, MMI_EMAIL_PART_MASK_SIZE * sizeof(kal_uint8)) == 0)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_retrieve_option
 * DESCRIPTION
 *  Execute Retrieve option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_retrieve_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 itemIcons[EMAIL_MAX_PART_NUMBER + 1];
    U8 *nStrItemList[EMAIL_MAX_PART_NUMBER + 1];
    U8 *popUpList[EMAIL_MAX_PART_NUMBER + 1];
    U8 *guiBuffer;
    S32 item_num = 1;
    U16 screen_id = SCR_ID_EMAIL_READ_RETRIEVE_OPT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    if (mmi_email_fldr_is_part_all())
    {
        return;
    }
    screen_id = SCR_ID_EMAIL_READ_RETRIEVE_OPT;
    EntryNewScreen(screen_id, NULL, mmi_email_retrieve_option, NULL);
    guiBuffer = GetCurrGuiBuffer(screen_id);
    kal_mem_set(nStrItemList, 0, (EMAIL_MAX_PART_NUMBER + 1) * sizeof(U8*));
    kal_mem_set(popUpList, 0, (EMAIL_MAX_PART_NUMBER + 1) * sizeof(U8*));
    nStrItemList[0] = (U8*) (GetString((U16) STR_EMAIL_DOWNLOAD_ID));
    popUpList[0] = (U8*) (GetString((U16) STR_EMAIL_DOWNLOAD_ID));
    email_p->fldr_info.curr_retrieve_indx = 0;

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        item_num = mmi_email_retrieve_opt_get_detail(nStrItemList, itemIcons, popUpList);
    }
    if (EMAIL_IS_PROT(EMAIL_PROT_POP3))
    {
        item_num = 1;
    }
#endif

    RegisterHighlightHandler(mmi_email_hilite_retrieve_opt);
    
    ShowCategory53Screen(
        STR_EMAIL_RETRIEVE_OPTION_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_num,
        (U8 **) nStrItemList,
        (U16*) /* itemIcons */ gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        email_p->fldr_info.curr_retrieve_indx,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_email_retrieve_opt_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_email_retrieve_opt_lsk
* DESCRIPTION
*  Left soft key function of Retrieve option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_email_retrieve_opt_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 temp_indx = 0;
    kal_bool set_mask = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->fldr_info.curr_retrieve_indx == 0)
    {
        EMAIL_SET_DOWNALL_MASK(email_p->fldr_info.curr_get_part_mask);
    }
    else 
    {
        EMAIL_SET_GET_CACHE_MASK(email_p->fldr_info.curr_get_part_mask);
        do
        {
            /* Text */
            if (email_p->fldr_info.curr_num_not_cached_txt == 0)
            {
                set_mask = MMI_FALSE;
            }
            else if ((email_p->fldr_info.curr_retrieve_indx - 1) < email_p->fldr_info.curr_num_not_cached_txt)
            {
                temp_indx = email_p->fldr_info.curr_retrieve_indx - 1;
                for (i = 0; temp_indx >= 0; i++)
                {
                    if (!ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, i))
                    {
                        if (temp_indx == 0)
                        {
                            set_mask = MMI_TRUE;
                            break;
                        }
                        else
                        {
                            temp_indx--;
                        }
                    }
                }
                if (set_mask)
                {
                    SET_PART_MASK(email_p->fldr_info.curr_get_part_mask, i);
                    break;
                }
            }
            /* Attachments */
            temp_indx = email_p->fldr_info.curr_retrieve_indx - 1 - email_p->fldr_info.curr_num_not_cached_txt;
            for (i = 0; temp_indx >= 0; i++)
            {
                if (!ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(i)))
                {
                    if (temp_indx == 0)
                    {
                        break;
                    }
                    else
                    {
                        temp_indx--;
                    }
                }
            }
            SET_PART_MASK(email_p->fldr_info.curr_get_part_mask, EMAIL_PART_MASK_ATTACH(i));
        } while(0);
    }    
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_POP3))
    {
        email_p->fldr_info.is_part_download = EMAIL_DOWN_POP3;
    }
    else
    {
        email_p->fldr_info.is_part_download = EMAIL_DOWN_IMAP4;
    }
#else
    email_p->fldr_info.is_part_download = EMAIL_DOWN_POP3;
#endif
    mmi_email_ps_folder_msg_select_req();
    DeleteScreenIfPresent(SCR_ID_EMAIL_READ_RETRIEVE_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_retrieve_opt
 * DESCRIPTION
 *  Hilite Read->Retrieve option
 * PARAMETERS
 *  index       [IN]        The index of hilite item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_retrieve_opt(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.curr_retrieve_indx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_retrieve_opt_get_detail
 * DESCRIPTION
 *  Get data of menu items in Retrieve option screen
 * PARAMETERS
 *  nStrItemList        [IN]        
 *  itemIcons           [OUT]         
 *  popUpList           [IN]        
 * RETURNS
 *  The number of undownloaded item
 *****************************************************************************/
S32 mmi_email_retrieve_opt_get_detail(U8 **str_list_item, U16 *item_icons, U8 **pop_up_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    S32 k = 1;
    S8 fileNumberAnsii[2 * ENCODING_LENGTH];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < email_p->fldr_info.curr_total_txt; i++)
    {    
        if (ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, j) == EMAIL_ATT_CACHED)
        {
            j++;
            continue;
        }
        item_icons[k] = IMG_EMAIL_RETRIEVE_TEXT;
        str_list_item[k] = (U8*) GetString((U16) (STR_EMAIL_DOWNLOAD_TEXT1_ID + j));
        pop_up_item[k] = (U8*) GetString((U16) (STR_EMAIL_DOWNLOAD_TEXT1_ID + j));
        j++;
        k++;
    }
    email_p->fldr_info.curr_num_not_cached_txt = k - 1;
    j = 0;
    for (i = 0; i < email_p->fldr_info.curr_total_att; i++)
    {    
        if (ISSET_PART_MASK(email_p->fldr_info.curr_part_mask, EMAIL_PART_MASK_ATTACH(j)) == EMAIL_ATT_CACHED)
        {
            j++;
            continue;
        }
        item_icons[k] = IMG_EMAIL_RETRIEVE_ATT;
        str_list_item[k] = (U8*) email_p->inbox_info.read_info.attch_list[j].file_name;
        memset(retrieve_att_size[j], 0, sizeof(S8) * 5 * ENCODING_LENGTH);
        sprintf(fileNumberAnsii, "%dK", (email_p->inbox_info.read_info.attch_list[j].size + 1023)/1024);
        mmi_asc_to_ucs2(retrieve_att_size[j], fileNumberAnsii);
        pop_up_item[k] = (U8*)retrieve_att_size[j];
        /* pop_up_item[k] = (U8*) GetString((U16) (STR_EMAIL_DOWNLOAD_ATT1_ID + j)); */
        j++;
        k++;
    }
    email_p->fldr_info.curr_num_not_cached_att = k - 1 - email_p->fldr_info.curr_num_not_cached_txt;
    return k;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_mark_deleted
 * DESCRIPTION
 *  Execute Read->Mark as Deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_mark_deleted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_ps_folder_msg_mark_del_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_mark_unread
 * DESCRIPTION
 *  Execute Read->Mark as Unread
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_mark_unread(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_ps_folder_msg_mark_unread_req();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_attch_view
 * DESCRIPTION
 *  View/Play attachment file according to its type.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_attch_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_p->misc_info.curr_hilite_attch;
    U8 fileType;
#ifdef __MMI_EMAIL_DRM_SUPPORT__    
    U8 permission = DRM_PERMISSION_NONE;
    U8 method = DRM_METHOD_NONE;
    FS_HANDLE fileHandle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fileType = mmi_fmgr_get_file_group((S8*) email_p->inbox_info.read_info.attch_list[i].file_path);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    if (email_p->inbox_info.read_info.attch_list[i].drm.is_valid)
    {
        if (fileType == FMGR_GROUP_IMAGE)
        {
            permission = DRM_PERMISSION_DISPLAY;
        }
        else if (fileType == FMGR_GROUP_AUDIO)
        {
            permission = DRM_PERMISSION_PLAY;
        }
        else if (fileType == FMGR_GROUP_VIDEO)
        {
            permission = DRM_PERMISSION_PLAY;
        }
        if ((fileHandle = DRM_open_file(
                    (UI_string_type)email_p->inbox_info.read_info.attch_list[i].file_path, 
                    FS_READ_ONLY, 
                    permission)) >= FS_NO_ERROR)
        {
            if ((method = DRM_get_object_method(fileHandle, NULL)) != DRM_METHOD_NONE)
            {
                if (DRM_validate_permission(fileHandle, NULL, permission) == MMI_FALSE)
                {
                    if (method & DRM_METHOD_SEPARATE_DELIVERY)
                    {
                        U32 size = sizeof(rights_issuer);
                        /* request rights from server */
                        memset(rights_issuer, 0, sizeof(rights_issuer));
                        if(FS_NO_ERROR <= DRM_get_rights_issuer(fileHandle, rights_issuer, &size))
                        {
                            if (
                        #ifdef __FLIGHT_MODE_SUPPORT__
                                (mmi_bootup_get_active_flight_mode() == 0) &&
                        #endif
                                (mmi_bootup_is_network_service_available() == TRUE))
                            {
                        #ifdef WAP_SUPPORT
                                mmi_email_display_confirm(STR_FMGR_REQ_RIGHTS, mmi_email_request_rights, GoBackHistory);
                        #else
                                mmi_email_util_display_popup(
                                    (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                                    IMG_GLOBAL_WARNING,
                                    0,
                                    UI_POPUP_NOTIFYDURATION_TIME,
                                    (U8) WARNING_TONE);
                        #endif
                                DRM_close_file(fileHandle);
                                return;
                            }
                        }
                    }
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) WARNING_TONE);
                    DRM_close_file(fileHandle);
                    return;
                }
            }
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_READ_ATTCH_VIEW_DRM, permission, method);
            DRM_close_file(fileHandle);
        }
        else
        {
            /* open file fail */
            mmi_email_util_display_popup((PU8) GetString(GetFileSystemErrorString(fileHandle)),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                ERROR_TONE);
            return;
        }    
    }
    is_drm_file = email_p->inbox_info.read_info.attch_list[i].drm.is_valid;
#endif /* __DRM_SUPPORT__ */ 
    if (fileType == FMGR_GROUP_IMAGE)
    {
        S32 fmgr_type = 0;
        FMGR_FILTER fmgr_set;
        
        FMGR_FILTER_INIT(&fmgr_set);
        fmgr_type = mmi_fmgr_get_file_type_by_filename((PS8)email_p->inbox_info.read_info.attch_list[i].file_path);
        FMGR_FILTER_SET(&fmgr_set, fmgr_type);
        mmi_imgview_view_image_hdlr(
            (PS8)email_p->inbox_info.read_info.attch_list[i].file_path,
            MMI_FALSE,
            fmgr_set,
            GetRootTitleIcon(MENU_ID_IMGVIEW_APP));
    }
    else if (fileType == FMGR_GROUP_AUDIO)
    {
        mmi_audply_single_play(
            (UI_string_type) email_p->inbox_info.read_info.attch_list[i].file_path,
            NULL);
    }
#ifdef __MMI_VIDEO_PLAYER__
    else if (fileType == FMGR_GROUP_VIDEO)
    {
        EntryNewScreen(SCR_ID_EMAIL_COMP_VIEW_IMAGE, NULL, mmi_email_entry_read_attch_view, NULL);
        ShowCategory225Screen(
            STR_GLOBAL_VIEW,
            GetRootTitleIcon(MENU_ID_VDOPLY_APP),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            (S8*) email_p->inbox_info.read_info.attch_list[i].file_path,
            1,
            TRUE,
            TRUE,
            TRUE,
            GDI_COLOR_BLACK,
            mmi_email_play_video_callback,
            NULL);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
#endif /* __MMI_VIDEO_PLAYER__ */ 
    else if (email_p->inbox_info.read_info.attch_list[i].attch_type == MIME_TYPE_APPLICATION)        /* only for imelody */
    {
        mmi_audply_single_play(
            (UI_string_type) email_p->inbox_info.read_info.attch_list[i].file_path,
            NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_pre_entry_save_attch
 * DESCRIPTION
 *  Retrieve file extension and go to file name screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_pre_entry_save_attch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fileExt;
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    UI_character_type mp3_str[8];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(
        (S8*) email_p->filename_buff,
        (S8*) email_p->inbox_info.read_info.attch_list[email_p->misc_info.curr_hilite_attch].file_name);
    memset(email_p->fileext_buff, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    if (email_p->inbox_info.read_info.attch_list[email_p->misc_info.curr_hilite_attch].attch_subtype == MIME_SUBTYPE_AUDIO_MP3)
    {
        mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
        mmi_ucs2cpy((S8*) email_p->fileext_buff, (S8*) mp3_str);
    }
    else if (email_p->inbox_info.read_info.attch_list[email_p->misc_info.curr_hilite_attch].attch_subtype == MIME_SUBTYPE_AUDIO_MP2)
    {
        mmi_asc_to_ucs2((S8*) mp3_str, ".mp2");
        mmi_ucs2cpy((S8*) email_p->fileext_buff, (S8*) mp3_str);
    }
    else
#endif
    {
        fileExt = mmi_email_get_file_ext((S8*) email_p->filename_buff);
        if (fileExt)
        {
            if (mmi_ucs2strlen(fileExt) > FMGR_MAX_FILE_LEN)
            {
                mmi_ucs2ncpy((S8*) email_p->fileext_buff, fileExt, FMGR_MAX_FILE_LEN);
            }
            else
            {
                mmi_ucs2cpy((S8*) email_p->fileext_buff, fileExt);
            }
            /* clear file extension */
            fileExt[0] = 0x0000;
        }
        else
        {
            email_p->fileext_buff[0] = 0x0000;
        }
    }
    memset(email_p->save_name_buff, 0, FMGR_MAX_FILE_LEN + 1);
    if (mmi_ucs2strlen((S8*) email_p->filename_buff) > (FMGR_MAX_INPUT_FILE_LEN - 1))
    {
        mmi_ucs2ncpy(
            (S8*) email_p->save_name_buff,
            (S8*) email_p->filename_buff,
            (FMGR_MAX_INPUT_FILE_LEN - 1));
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->save_name_buff,
            (S8*) email_p->filename_buff);
    } 
    
    mmi_email_entry_read_attch_save();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_attch_save
 * DESCRIPTION
 *  Entry input filename screen for attachment.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_attch_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ_ATTCH_SAVE, NULL, mmi_email_entry_read_attch_save, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_ATTCH_SAVE);
    ShowCategory5Screen(
        STR_EMAIL_FILENAME_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) email_p->save_name_buff,
        FMGR_MAX_INPUT_FILE_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_email_entry_read_save_attch_opt, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_save_attch_opt
 * DESCRIPTION
 *  Entry option screen for save attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_save_attch_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[2];    /* only done and input method */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_READ_ATTCH_SAVE_OPT, NULL, mmi_email_entry_read_save_attch_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_READ_ATTCH_SAVE_OPT);
    SetParentHandler(MENU_ID_EMAIL_READ_ATTCH_SAVE_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_READ_ATTCH_SAVE_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_READ_ATTCH_SAVE_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_save_attch
 * DESCRIPTION
 *  Save attachment from Read Email screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_save_attch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 result;
    S8* name_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_ptr = mmi_fmgr_skip_space((S8*) email_p->save_name_buff);
    result = mmi_email_read_copy_attch((S8*) name_ptr);
    switch (result)
    {
        case EMAIL_SAVE_ATTACH_NO_ERR:
            mmi_email_pre_entry_progressing(
                STR_EMAIL_MAIN_ID,
                GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
                0,
                0,
                0,
                0,
                (U8*) GetString(STR_GLOBAL_SAVING),
                (U8*) NULL,
                IMG_GLOBAL_SAVE,
                NULL,
                NULL,
                NULL);
            break;
        case EMAIL_SAVE_ATTACH_DUP_NAME:
            mmi_email_display_confirm(
                STR_GLOBAL_OVERWRITE_EXISTING_FILE,
                mmi_email_replace_dupfile,
                GoBackHistory);
            break;
        case EMAIL_SAVE_ATTACH_EMPTY_NAME:
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_EMPTY_FILENAME),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case EMAIL_SAVE_ATTACH_NAME_TOO_LONG:
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_FILENAME_TOO_LONG),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case EMAIL_SAVE_ATTACH_DEL_ERROR:
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_NOT_DONE),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        case EMAIL_SAVE_ATTACH_NAME_INVALID:
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_INVALID_FILE_NAME_ID),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
        default:
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_ERROR_CODE_UNKNOWN_ID),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            break;
    }
    DeleteScreenIfPresent(SCR_ID_EMAIL_READ_ATTCH_SAVE_OPT);
    /* DeleteUptoScrID(SCR_ID_EMAIL_READ_ATTCH); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_replace_dupfile
 * DESCRIPTION
 *  replace the file when save attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_replace_dupfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* name_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_ptr = mmi_fmgr_skip_space((S8*) email_p->save_name_buff);
    if (email_p->inbox_info.attch_dest_path == NULL)
    {
        email_p->inbox_info.attch_dest_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    }
    /* duplicated file name */
    mmi_ucs2cpy((S8*) email_p->inbox_info.attch_dest_path, (S8*) email_p->comm_buff);
    mmi_ucs2cat(email_p->inbox_info.attch_dest_path, (S8*) name_ptr);
    mmi_ucs2cat(email_p->inbox_info.attch_dest_path, (S8*) email_p->fileext_buff);
    mmi_email_util_reset_file_attr((U16*)email_p->inbox_info.attch_dest_path);
    FS_Delete((U16*)email_p->inbox_info.attch_dest_path);
    OslMfree(email_p->inbox_info.attch_dest_path);
    email_p->inbox_info.attch_dest_path = NULL;
    mmi_email_read_save_attch();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_read_opt
 * DESCRIPTION
 *  Entry Option screen of folder->Read
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_read_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(email_p->main_info.curr_menu)
    {
        case MMI_EMAIL_INBOX:
            mmi_email_entry_inbox_opt();
            break;
        case MMI_EMAIL_SENT:
            mmi_email_entry_sent_opt();
            break;
        case MMI_EMAIL_DRAFT:
            mmi_email_entry_draft_opt();
            break;
        case MMI_EMAIL_UNSENT:
            mmi_email_entry_unsent_opt();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_attach_save
 * DESCRIPTION
 *  Enter file manager to select a folder to save attachment
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_attach_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(
        APP_EMAIL,
        FMGR_SELECT_FOLDER,
        filter,
        (S8*) L"root",
        mmi_email_read_attch_sel_path_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_read_attch_sel_path_callback
 * DESCRIPTION
 *  Enter file manager to select a folder to save attachment
 * PARAMETERS
 *  filePath        [?]         
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_read_attch_sel_path_callback(void *filePath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filePath == NULL)
    {
        GoBackToHistory(SCR_ID_EMAIL_READ_ATTCH);
        return;
    }

    mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) filePath);

    /* use pass file folder to save attachment */
    mmi_email_read_pre_entry_save_attch();
    /* go to attachment screen because not all attachments have attachment option screen */
    DeleteUptoScrID(SCR_ID_EMAIL_READ_ATTCH);
}


#define SENT_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_sent_opt
 * DESCRIPTION
 *  Entry function of Sent->read->Option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_sent_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 parentMenuId = MENU_ID_EMAIL_SENT_OPT;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_SENT_OPT, NULL, mmi_email_entry_sent_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_SENT_OPT);
    /* mark deleted menu */
    if (email_p->fldr_info.curr_delete_flag == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_SENT_OPT_MARK_DELETED);
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_SENT_OPT_UNMARK_DELETED);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_SENT_OPT_MARK_DELETED);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_SENT_OPT_UNMARK_DELETED);
    }
    /* extract address menu */
    if ((email_p->inbox_info.read_info.curr_inline_item + 1) == EMAIL_COMP_CONT)
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_SENT_OPT_EXTRACT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_SENT_OPT_EXTRACT);
    }
    /* retrieve option menu */
    mmi_frm_unhide_menu_item(MENU_ID_EMAIL_SENT_OPT_RETRIEVE);
    email_p->fldr_info.curr_msg_all = MMI_FALSE;
    if (mmi_email_fldr_is_part_all())
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_SENT_OPT_RETRIEVE);
        email_p->fldr_info.curr_msg_all = MMI_TRUE;
    }
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        if (EMAIL_IS_MODE(EMAIL_MODE_OFFLINE))
        {
            mmi_frm_hide_menu_item(MENU_ID_EMAIL_SENT_OPT_RETRIEVE);
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(parentMenuId);
    numItems = GetNumOfChild_Ext(parentMenuId);
    GetSequenceStringIds_Ext(parentMenuId, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


#define UNSENT_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_unsent_opt
 * DESCRIPTION
 *  Entry function of Unsent-> Option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_unsent_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;
    U16 parent_menu_id = MENU_ID_EMAIL_UNSENT_OPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_UNSENT_OPT, NULL, mmi_email_entry_unsent_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_UNSENT_OPT);
    /* mark deleted menu */
    if (email_p->fldr_info.curr_delete_flag == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_UNSENT_OPT_MARK_DELETED);
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_UNSENT_OPT_UNMARK_DELETED);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_UNSENT_OPT_MARK_DELETED);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_UNSENT_OPT_UNMARK_DELETED);
    }
    if ((email_p->inbox_info.read_info.curr_inline_item + 1) == EMAIL_COMP_CONT)
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_UNSENT_OPT_EXTRACT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_UNSENT_OPT_EXTRACT);
    }
    SetParentHandler(parent_menu_id);
    numItems = GetNumOfChild_Ext(parent_menu_id);
    GetSequenceStringIds_Ext(parent_menu_id, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_unsent_send
 * DESCRIPTION
 *  Highlight handler of of Unsent-> Send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_unsent_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_unsent_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_unsent_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_unsent_save_n_send
 * DESCRIPTION
 *  Highlight handler of of Unsent-> Save and Send option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_unsent_save_n_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_unsent_save_n_send, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_unsent_save_n_send, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_unsent_move
 * DESCRIPTION
 *  Highlight handler of of Unsent-> Move to Draft
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_unsent_move(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_ps_move_to_draft_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_ps_move_to_draft_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_unsent_send
 * DESCRIPTION
 *  Handler of Unsent->Option->Send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_unsent_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_ps_send_from_mailbox_req(FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_unsent_save_n_send
 * DESCRIPTION
 *  Handler of Unsent->Option->Save and Send
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_unsent_save_n_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_is_offline_notifier())
    {
        return;
    }
    mmi_email_ps_send_from_mailbox_req(TRUE);
}


#define DRAFT_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_draft_opt
 * DESCRIPTION
 *  Entry function of Draft->Option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_draft_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 parentMenuId = MENU_ID_EMAIL_DRAFT_OPT;
    U16 nStrItemList[MAX_SUB_MENUS];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_DRAFT_OPT, NULL, mmi_email_entry_draft_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_DRAFT_OPT);
    /* mark deleted menu */
    if (email_p->fldr_info.curr_delete_flag == MMI_TRUE)
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_MARK_DELETED);
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_UNMARK_DELETED);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_MARK_DELETED);
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_UNMARK_DELETED);
    }
    /* extract address menu */
    if ((email_p->inbox_info.read_info.curr_inline_item + 1) == EMAIL_COMP_CONT)
    {
        mmi_frm_unhide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_EXTRACT);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_EXTRACT);
    }
    /* retrieve option menu */
    mmi_frm_unhide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_RETRIEVE);
    email_p->fldr_info.curr_msg_all = MMI_FALSE;
    if (mmi_email_fldr_is_part_all())
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_RETRIEVE);
        email_p->fldr_info.curr_msg_all = MMI_TRUE;
    }
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        if (EMAIL_IS_MODE(EMAIL_MODE_OFFLINE))
        {
            mmi_frm_hide_menu_item(MENU_ID_EMAIL_DRAFT_OPT_RETRIEVE);
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    SetParentHandler(parentMenuId);
    numItems = GetNumOfChild_Ext(parentMenuId);
    GetSequenceStringIds_Ext(parentMenuId, nStrItemList);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_draft_edit
 * DESCRIPTION
 *  Highlight handler of Draft->Option->Edit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_draft_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_read_edit, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_read_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#define DELETE_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_del_all
 * DESCRIPTION
 *  Entry function of Delete All option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 itemIcons[EMAIL_DELETE_ALL_OPTION_TOTAL];
    U8 *nStrItemList[EMAIL_DELETE_ALL_OPTION_TOTAL];
    U8 *popUpList[EMAIL_DELETE_ALL_OPTION_TOTAL];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&email_p->del_info, 0, sizeof(mmi_email_del_info_struct));
    EntryNewScreen(SCR_ID_EMAIL_DELETE_ALL, mmi_email_exit_del_all, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_DELETE_ALL);
    mmi_email_del_all_get_menu_detail(nStrItemList, itemIcons, popUpList);
    RegisterHighlightHandler(mmi_email_hilite_del_all_fldr);

    ShowCategory53Screen(
        STR_EMAIL_DELETE_ALL_FOLDER_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_DELETE_ALL_OPTION_TOTAL,
        (U8 **) nStrItemList,
        (U16*) /* itemIcons */ gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        email_p->fldr_info.curr_mail_indx,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_email_del_all_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_del_all_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_del_all
 * DESCRIPTION
 *  Exit function of Delete All option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_del_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_history(SCR_ID_EMAIL_DELETE_ALL, mmi_email_entry_del_all);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_all_get_menu_detail
 * DESCRIPTION
 *  Get data of menu items in Delete All screen
 * PARAMETERS
 *  nStrItemList        [IN]        
 *  itemIcons           [?]         
 *  popUpList           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_all_get_menu_detail(U8 **nStrItemList, U16 *itemIcons, U8 **popUpList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_DELETE_ALL_OPTION_TOTAL; i++)
    {
        itemIcons[i] = IMG_EMAIL_INBOX_ID + i;
        nStrItemList[i] = (U8*) GetString((U16) (STR_EMAIL_INBOX_ID + i));
    }

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        /* sent folder */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sent_name))
        {
            nStrItemList[EMAIL_DEL_ALL_SENT_ENUM] = (U8*) email_p->prof_info.act_prof.sent_name;
        }

        /* draft folder */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.draft_name))
        {
            nStrItemList[EMAIL_DEL_ALL_DRAFT_ENUM] = (U8*) email_p->prof_info.act_prof.draft_name;
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    popUpList[EMAIL_DEL_ALL_INBOX_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_INBOX_ENUM, MMI_EMAIL_INBOX);
    popUpList[EMAIL_DEL_ALL_SENT_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_SENT_ENUM, MMI_EMAIL_SENT);
    popUpList[EMAIL_DEL_ALL_UNSENT_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_UNSENT_ENUM, MMI_EMAIL_UNSENT);
    popUpList[EMAIL_DEL_ALL_DRAFT_ENUM] = mmi_email_util_get_fldr_hint_value(EMAIL_DEL_ALL_DRAFT_ENUM, MMI_EMAIL_DRAFT);
    popUpList[EMAIL_DEL_ALL_FOLDER_ENUM] = mmi_email_util_get_hint_value_all_fldr(EMAIL_DEL_ALL_FOLDER_ENUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_read_msg_del
 * DESCRIPTION
 *  Hililte function Folder List -> Option -> Delete option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_read_msg_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_del_single_msg, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_del_single_msg, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_single_msg
 * DESCRIPTION
 *  Display confirmation screen for Delete option in each folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_single_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_display_confirm(STR_EMAIL_DEL_SEL_MAIL_ID, mmi_email_del_single_msg_done, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_single_msg_done
 * DESCRIPTION
 *  Proceed deleting of current selected folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_single_msg_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->del_info.curr_del_fldr = (email_fldr_enum) email_p->main_info.curr_menu;
    mmi_email_ps_folder_msg_del_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_all_confirm
 * DESCRIPTION
 *  Display confirmation screen for each items in Delete All menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->del_info.curr_del_fldr == EMAIL_DEL_ALL_FOLDER_ENUM)
    {
        U32 num_mails;

        num_mails = email_p->fldr_info.fldr_data[MMI_EMAIL_INBOX].total_mails +
            email_p->fldr_info.fldr_data[MMI_EMAIL_UNSENT].total_mails +
            email_p->fldr_info.fldr_data[MMI_EMAIL_SENT].total_mails +
            email_p->fldr_info.fldr_data[MMI_EMAIL_DRAFT].total_mails;

        if (num_mails != 0)
        {
            email_p->del_info.curr_del_fldr = EMAIL_FLDR_INBOX;
            mmi_email_display_confirm(STR_EMAIL_DEL_ALL_FOLDER_MAILS_ID, mmi_email_del_all_folders, GoBackHistory);
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
        }
    }
    else
    {
        /* the order of folder will not be changed */
        email_p->del_info.del_all_fldr = FALSE;

        if (email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].total_mails != 0)
        {
            mmi_email_display_confirm(STR_EMAIL_DEL_FOLDER_MAILS_ID, mmi_email_ps_folder_msg_del_req, GoBackHistory);
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_del_all_fldr
 * DESCRIPTION
 *  Highlight handler of items in Delete All menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_del_all_fldr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->del_info.curr_del_fldr = (email_fldr_enum) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_all_folders
 * DESCRIPTION
 *  Proceed delete all folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_all_folders(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->del_info.curr_del_fldr != EMAIL_DEL_ALL_FOLDER_ENUM)
    {
        if (delete_abort_req)
        {
            return;
        }
        email_p->del_info.del_all_fldr = MMI_TRUE;
        mmi_email_ps_folder_msg_del_req();
    }
    else
    {
        U16 startSrcnId;

        /* update idle screen icon status */
        email_p->del_info.del_all_fldr = FALSE;
        email_p->main_info.unread_mails = 0;
        email_p->main_info.is_mem_full = FALSE;
        mmi_email_util_update_status_icon();
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        GetNextScrnIdOf(SCR_ID_EMAIL_DELETE_ALL, &startSrcnId);
        mmi_email_util_del_between_scr(startSrcnId, SCR_ID_EMAIL_PROGRESS);
    }
}

#define DELETE_ALL_MARK

/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_del_all_mark
 * DESCRIPTION
 *  Entry function of Delete All Mark option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_del_all_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 itemIcons[EMAIL_DELETE_ALL_OPTION_TOTAL];
    U8 *nStrItemList[EMAIL_DELETE_ALL_OPTION_TOTAL];
    U8 *popUpList[EMAIL_DELETE_ALL_OPTION_TOTAL];
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(&email_p->del_info, 0, sizeof(mmi_email_del_info_struct));
    EntryNewScreen(SCR_ID_EMAIL_DELETE_ALL, mmi_email_exit_del_all_mark, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_DELETE_ALL);
    mmi_email_del_all_mark_get_menu_detail(nStrItemList, itemIcons, popUpList);
    RegisterHighlightHandler(mmi_email_hilite_del_all_mark_fldr);

    ShowCategory53Screen(
        STR_EMAIL_DELETE_ALL_MARK_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_DELETE_ALL_OPTION_TOTAL,
        (U8 **) nStrItemList,
        (U16*) /* itemIcons */ gIndexIconsImageList,
        (U8 **) popUpList,
        0,
        email_p->fldr_info.curr_mail_indx,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_email_del_all_mark_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_del_all_mark_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_del_all_mark
 * DESCRIPTION
 *  Exit function of Delete All Mark option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_del_all_mark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_history(SCR_ID_EMAIL_DELETE_ALL, mmi_email_entry_del_all_mark);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_all_mark_get_menu_detail
 * DESCRIPTION
 *  Get data of menu items in Delete All Mark screen
 * PARAMETERS
 *  nStrItemList        [IN]        
 *  itemIcons           [?]         
 *  popUpList           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_all_mark_get_menu_detail(U8 **nStrItemList, U16 *itemIcons, U8 **popUpList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_DELETE_ALL_OPTION_TOTAL; i++)
    {
        itemIcons[i] = IMG_EMAIL_INBOX_ID + i;
        nStrItemList[i] = (U8*) GetString((U16) (STR_EMAIL_INBOX_ID + i));
    }

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (EMAIL_IS_PROT(EMAIL_PROT_IMAP4))
    {
        /* sent folder */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.sent_name))
        {
            nStrItemList[EMAIL_DEL_ALL_SENT_ENUM] = (U8*) email_p->prof_info.act_prof.sent_name;
        }

        /* draft folder */
        if (mmi_ucs2strlen((S8*) email_p->prof_info.act_prof.draft_name))
        {
            nStrItemList[EMAIL_DEL_ALL_DRAFT_ENUM] = (U8*) email_p->prof_info.act_prof.draft_name;
        }
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 

    popUpList[EMAIL_DEL_ALL_INBOX_ENUM] = mmi_email_util_get_fldr_hint_mark_value(EMAIL_DEL_ALL_INBOX_ENUM, MMI_EMAIL_INBOX);
    popUpList[EMAIL_DEL_ALL_SENT_ENUM] = mmi_email_util_get_fldr_hint_mark_value(EMAIL_DEL_ALL_SENT_ENUM, MMI_EMAIL_SENT);
    popUpList[EMAIL_DEL_ALL_UNSENT_ENUM] = mmi_email_util_get_fldr_hint_mark_value(EMAIL_DEL_ALL_UNSENT_ENUM, MMI_EMAIL_UNSENT);
    popUpList[EMAIL_DEL_ALL_DRAFT_ENUM] = mmi_email_util_get_fldr_hint_mark_value(EMAIL_DEL_ALL_DRAFT_ENUM, MMI_EMAIL_DRAFT);
    popUpList[EMAIL_DEL_ALL_FOLDER_ENUM] = mmi_email_util_get_hint_mark_value_all_fldr(EMAIL_DEL_ALL_FOLDER_ENUM);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_all_mark_confirm
 * DESCRIPTION
 *  Display confirmation screen for each items in Delete All Mark menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_all_mark_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->del_info.curr_del_fldr == EMAIL_DEL_ALL_FOLDER_ENUM)
    {
        U32 num_mails;

        num_mails = email_p->fldr_info.fldr_data[MMI_EMAIL_INBOX].num_mark_del_mails +
            email_p->fldr_info.fldr_data[MMI_EMAIL_UNSENT].num_mark_del_mails +
            email_p->fldr_info.fldr_data[MMI_EMAIL_SENT].num_mark_del_mails +
            email_p->fldr_info.fldr_data[MMI_EMAIL_DRAFT].num_mark_del_mails;

        if (num_mails != 0)
        {
            email_p->del_info.curr_del_fldr = EMAIL_FLDR_INBOX;
            mmi_email_display_confirm(STR_EMAIL_DEL_ALL_FOLDER_MARK_MAILS_ID, mmi_email_del_all_mark_folders, GoBackHistory);
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
        }
    }
    else
    {
        /* the order of folder will not be changed */
        email_p->del_info.del_all_fldr = FALSE;

        if (email_p->fldr_info.fldr_data[email_p->del_info.curr_del_fldr].num_mark_del_mails != 0)
        {
            mmi_email_display_confirm(STR_EMAIL_DEL_FOLDER_MARK_MAILS_ID, mmi_email_ps_folder_msg_del_req, GoBackHistory);
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_del_all_mark_fldr
 * DESCRIPTION
 *  Highlight handler of items in Delete All Mark menu.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_del_all_mark_fldr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->del_info.curr_del_fldr = (email_fldr_enum) index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_del_all_mark_folders
 * DESCRIPTION
 *  Proceed delete all Mark in folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_del_all_mark_folders(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->del_info.curr_del_fldr != EMAIL_DEL_ALL_FOLDER_ENUM)
    {
        if (delete_abort_req)
        {
            return;
        }
        email_p->del_info.del_all_fldr = MMI_TRUE;
        mmi_email_ps_folder_msg_del_req();
    }
    else
    {
        U16 startSrcnId;

        email_p->del_info.del_all_fldr = FALSE;
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_COMMON_DELETED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        GetNextScrnIdOf(SCR_ID_EMAIL_DELETE_ALL, &startSrcnId);
        mmi_email_util_del_between_scr(startSrcnId, SCR_ID_EMAIL_PROGRESS);
    }
}


#define PROFILE_EMAIL




#define UTILITY_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_display_confirm
 * DESCRIPTION
 *  Display common confirmation screen.
 * PARAMETERS
 *  strId           [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_display_confirm(U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_CONFIRM, NULL, NULL, NULL);

    ShowCategory164Screen(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        strId,
        IMG_GLOBAL_QUESTION,
        NULL);

    SetLeftSoftkeyFunction(lskFuncs, KEY_EVENT_UP);
    SetRightSoftkeyFunction(rskFuns, KEY_EVENT_UP);
    playRequestedTone(WARNING_TONE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_display_confirm_ex
 * DESCRIPTION
 *  Display common confirmation screen.(with U8 *strings)
 * PARAMETERS
 *  str             [IN]        Confirmation string.
 *  lskFuncs        [IN]        Left soft key function.
 *  rskFuns         [IN]        Right soft key function.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_display_confirm_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_SIZE, NULL, mmi_email_display_confirm_ex, NULL);
    DeleteScreenIfPresent(SCR_ID_EMAIL_PROGRESS);
    ShowCategory165Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (UI_string_type)email_p->misc_info.str_compose_size,
        IMG_GLOBAL_INFO,
        NULL);

    SetLeftSoftkeyFunction(mmi_email_entry_comp_opt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_email_compose_size_goback_history, KEY_EVENT_UP);
    if (play_warning_tone)
    {
        playRequestedTone(WARNING_TONE);
        play_warning_tone = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_set_insert_history_flag
 * DESCRIPTION
 *  Set the state of inserting history.
 * PARAMETERS
 *  insert_hist     [IN]        State of inserting history
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_util_set_insert_history_flag(BOOL insert_hist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* insert current screen into history */
    email_p->misc_info.insert_hist = insert_hist;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_hint_value_all_fldr
 * DESCRIPTION
 *  Retrieve hint value of total mails of folders in Delete All function.
 * PARAMETERS
 *  index       [IN]        Index of highlight item.
 * RETURNS
 *  Pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_get_hint_value_all_fldr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 hintStr[5 * ENCODING_LENGTH];
    U32 allFolderCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    allFolderCount = email_p->fldr_info.fldr_data[MMI_EMAIL_INBOX].total_mails +
        email_p->fldr_info.fldr_data[MMI_EMAIL_SENT].total_mails +
        email_p->fldr_info.fldr_data[MMI_EMAIL_UNSENT].total_mails +
        email_p->fldr_info.fldr_data[MMI_EMAIL_DRAFT].total_mails;
    sprintf(hintStr, "%u ", allFolderCount);
    mmi_asc_to_ucs2((S8*) hintData[index], hintStr);
    mmi_ucs2cat((S8*) hintData[index], (S8*) GetString(STR_EMAIL_MAILS_ID));
    return (U8*) hintData[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_fldr_hint_value
 * DESCRIPTION
 *  Retrieve hint data of a selected mail.
 * PARAMETERS
 *  index           [IN]        Highlight index of a mail.
 *  curr_fldr       [IN]        Index of selected folder.
 * RETURNS
 *  Pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_get_fldr_hint_value(U16 index, U8 curr_fldr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 hintStr[5 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(hintStr, "%d ", email_p->fldr_info.fldr_data[curr_fldr].total_mails);
    mmi_asc_to_ucs2((S8*) hintData[index], hintStr);
    mmi_ucs2cat((S8*) hintData[index], (S8*) GetString(STR_EMAIL_MAILS_ID));
    return (U8*) hintData[index];
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_hint_mark_value_all_fldr
 * DESCRIPTION
 *  Retrieve hint value of total mails of folders in Delete All Mark function.
 * PARAMETERS
 *  index       [IN]        Index of highlight item.
 * RETURNS
 *  Pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_get_hint_mark_value_all_fldr(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 hintStr[5 * ENCODING_LENGTH];
    U32 allFolderCount = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    allFolderCount = email_p->fldr_info.fldr_data[MMI_EMAIL_INBOX].num_mark_del_mails +
        email_p->fldr_info.fldr_data[MMI_EMAIL_SENT].num_mark_del_mails +
        email_p->fldr_info.fldr_data[MMI_EMAIL_UNSENT].num_mark_del_mails +
        email_p->fldr_info.fldr_data[MMI_EMAIL_DRAFT].num_mark_del_mails;
    sprintf(hintStr, "%u ", allFolderCount);
    mmi_asc_to_ucs2((S8*) hintData[index], hintStr);
    mmi_ucs2cat((S8*) hintData[index], (S8*) GetString(STR_EMAIL_MAILS_ID));
    return (U8*) hintData[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_fldr_hint_mark_value
 * DESCRIPTION
 *  Retrieve hint data of a selected mail for mark.
 * PARAMETERS
 *  index           [IN]        Highlight index of a mail.
 *  curr_fldr       [IN]        Index of selected folder.
 * RETURNS
 *  Pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_get_fldr_hint_mark_value(U16 index, U8 curr_fldr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 hintStr[5 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(hintStr, "%d ", email_p->fldr_info.fldr_data[curr_fldr].num_mark_del_mails);
    mmi_asc_to_ucs2((S8*) hintData[index], hintStr);
    mmi_ucs2cat((S8*) hintData[index], (S8*) GetString(STR_EMAIL_MAILS_ID));
    return (U8*) hintData[index];
}

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
/*****************************************************************************
 * FUNCTION
 *  mmi_email_util_get_mode_hint_value
 * DESCRIPTION
 *  Retrieve hint data of a selected mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  Pointer to the result string.
 *****************************************************************************/
U8 *mmi_email_util_get_mode_hint_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EMAIL_IS_MODE(EMAIL_MODE_OFFLINE))
    {
        return (U8 *) GetString(STR_EMAIL_MODE_HINT_OFFLINE_ID);
    }
    else
    {
        return (U8 *) GetString(STR_EMAIL_MODE_HINT_ONLINE_ID);
    }
}
#endif

#define FOLDER_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_exec_entry
 * DESCRIPTION
 *  Execute entry function of current selected folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_exec_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_p->main_info.curr_menu)
    {
        case MMI_EMAIL_INBOX:
        case MMI_EMAIL_UNSENT:
        case MMI_EMAIL_SENT:
        case MMI_EMAIL_DRAFT:
            mmi_email_entry_folder();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_prepare_forward
 * DESCRIPTION
 *  Prepare data to forward a mail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_prepare_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 subLenToBeForwarded;
    U32 prefixFwWithColonStrLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset inline compose members */
    mmi_email_comp_reset_member();

    /* subject with "Fw: <previous >" */
    subLenToBeForwarded = mmi_ucs2strlen((S8*) email_p->inbox_info.read_info.subj_buff);
    prefixFwWithColonStrLen = mmi_ucs2strlen((S8*)GetString(STR_EMAIL_FWD_IND_ID));
    if ((subLenToBeForwarded + prefixFwWithColonStrLen) > EMAIL_COMP_SUBJ_LEN)
    {
        subLenToBeForwarded = EMAIL_COMP_SUBJ_LEN - prefixFwWithColonStrLen;
    }
    mmi_ucs2cpy((S8*) email_p->comp_info.subj_buff, (S8*)GetString(STR_EMAIL_FWD_IND_ID));
    mmi_ucs2ncat(
        (S8*) email_p->comp_info.subj_buff,
        (S8*) email_p->inbox_info.read_info.subj_buff,
        subLenToBeForwarded);

    /* content */
    mmi_ucs2cpy((S8*) email_p->comp_info.cont_buff, (S8*) email_p->inbox_info.read_info.cont_buff);

    /* priority, encoding type */
    email_p->comp_info.priority_indx = email_p->inbox_info.read_info.priority_indx;
    email_p->misc_info.temp_priority_indx = email_p->inbox_info.read_info.priority_indx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_prepare_edit
 * DESCRIPTION
 *  Prepare data to edit a mail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_prepare_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_comp_reset_member();
    memcpy(
        &email_p->comp_info.addr_list[EMAIL_ADDR_TO],
        &email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_TO],
        sizeof(mmi_email_to_cc_struct));
    memcpy(
        &email_p->comp_info.addr_list[EMAIL_ADDR_CC],
        &email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_CC],
        sizeof(mmi_email_to_cc_struct));
#ifdef __MMI_EMAIL_BCC__
    memcpy(
        &email_p->comp_info.addr_list[EMAIL_ADDR_BCC],
        &email_p->inbox_info.read_info.addr_list[EMAIL_ADDR_BCC],
        sizeof(mmi_email_to_cc_struct));
#endif /*__MMI_EMAIL_BCC__*/
    memcpy(&email_p->comp_info, &email_p->inbox_info.read_info, sizeof(mmi_email_comp_info_struct));
    email_p->misc_info.temp_priority_indx = email_p->inbox_info.read_info.priority_indx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_is_list_ready
 * DESCRIPTION
 *  Function to check if list of items is ready to be displayed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_email_fldr_is_list_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mem_pool_ret_enum ret_result;

    mmi_email_mail_info_struct *listMsgsStruct[EMAIL_TOTAL_MSG_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_result = mmi_mem_get_values(
                    &email_p->mem_pool_info.mem_container,
                    (S16) email_p->mem_pool_info.start_indx,
                    (S16) email_p->mem_pool_info.end_indx,
                    (void **)listMsgsStruct,
                    &email_p->mem_pool_info.not_avail_pool);

    if (ret_result != MEM_CT_SUCCESS)
    {
        email_p->fldr_info.curr_page = email_p->mem_pool_info.not_avail_pool + 1;
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_back_from_history
 * DESCRIPTION
 *  Function to be added to history when back to folders.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_back_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.is_list_updated = TRUE;

    if (email_p->fldr_info.need_fldr_sel == TRUE)
    {
        email_p->fldr_info.is_list_updated = FALSE;
        mmi_email_fldr_reset_list_info();
    }
    mmi_email_fldr_exec_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_pre_folder_select_req
 * DESCRIPTION
 *  Function before sending folder select request to protocol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_pre_folder_select_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->fldr_info.curr_page < 1)
    {
        email_p->fldr_info.curr_page = 1;
    }
    mmi_email_ps_folder_select_req();
    DeleteScreenIfPresent(SCR_ID_EMAIL_FOLDER_OPT);
    DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_JUMP);
}

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_folder_read
 * DESCRIPTION
 *  Highlight handler of folder -> Option -> Read
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_folder_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_ps_folder_msg_select_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_ps_folder_msg_select_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_fldr_next_page
 * DESCRIPTION
 *  Highlight handler of Each Folder -> Option -> Next page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_fldr_next_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_fldr_next_page_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_fldr_next_page_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_fldr_prev_page
 * DESCRIPTION
 *  Highlight handler of Each folder -> Option -> Previous page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_fldr_prev_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_fldr_prev_page_req, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_fldr_prev_page_req, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_fldr_jump_to_page
 * DESCRIPTION
 *  Highlight handler of Each folder -> Option -> Jump to page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_hilite_fldr_jump_to_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_fldr_pre_entry_jump_page, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_fldr_pre_entry_jump_page, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_pre_entry_jump_page
 * DESCRIPTION
 *  Pre-entry function of Jump to Page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_pre_entry_jump_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset input buffer */
    email_p->fldr_info.jump_page_buff[0] = 0;
    mmi_email_entry_jump_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_exec_jump_page
 * DESCRIPTION
 *  Execute next/prev/jump to operation according to "to-go" page.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_exec_jump_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.curr_mail_indx = 0;
    email_p->fldr_info.fldr_list.num_msgs = 0;
    mmi_email_fldr_reset_list_info();
    mmi_email_fldr_pre_folder_select_req();

    DeleteNScrId(SCR_ID_EMAIL_FOLDER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_jump_page
 * DESCRIPTION
 *  Entry Jump To Page screen in each folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_jump_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_FLDR_JUMP, mmi_email_exit_jump_page, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_FLDR_JUMP);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_EMAIL_FLDR_JUMP, &inputBufferSize);
    InitializeCategory57Screen();
    mmi_email_fldr_fill_jump_inline_struct();
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, EMAIL_JUMP_PAGE_TOTAL_ITEM, inputBuffer);
    }

    DisableCategory57ScreenDone();

    ShowCategory57Screen(
        STR_EMAIL_FOLDER_JUMP_TO_PAGE_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        EMAIL_JUMP_PAGE_TOTAL_ITEM,
        NULL,
        wgui_inline_items,
        0,
        guiBuffer);

    SetCategory57RightSoftkeyFunctions(mmi_email_fldr_jump_page_req, GoBackHistory);
    SetLeftSoftkeyFunction(mmi_email_fldr_jump_page_req, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_jump_page
 * DESCRIPTION
 *  Exit function of Jump To Page screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_jump_page(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_n_history(SCR_ID_EMAIL_FLDR_JUMP, mmi_email_entry_jump_page);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_fill_jump_inline_struct
 * DESCRIPTION
 *  Fill inline data structure for Jump to Page screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_fill_jump_inline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *asciiPageNumberInfoBuff = OslMalloc(EMAIL_MAX_FLDR_CAP_LEN);
    S8 *ucs2PageNumberInfoBuff = OslMalloc(EMAIL_MAX_FLDR_CAP_LEN * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Caption */
    SetInlineItemActivation(&wgui_inline_items[0], KEY_LSK, KEY_EVENT_UP);
    sprintf((S8*) asciiPageNumberInfoBuff, " [%u/%u]", email_p->fldr_info.curr_page, email_p->fldr_info.total_page);
    mmi_asc_to_ucs2((S8*) ucs2PageNumberInfoBuff, (S8*) asciiPageNumberInfoBuff);
    mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) GetString(STR_EMAIL_FOLDER_PAGE_NUMBER_ID));
    mmi_ucs2cat((S8*) email_p->comm_buff, (S8*) ucs2PageNumberInfoBuff);
    SetInlineItemCaption(&wgui_inline_items[0], (U8*) email_p->comm_buff);
    SetInlineItemFullWidth(&wgui_inline_items[0]);
    LeftJustifyInlineItem(&wgui_inline_items[0]);

    /* Page number */
    SetInlineItemActivation(&wgui_inline_items[1], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    sprintf((S8*) asciiPageNumberInfoBuff, "%u", email_p->fldr_info.curr_page);
    mmi_asc_to_ucs2((S8*) email_p->fldr_info.jump_page_buff, (S8*) asciiPageNumberInfoBuff);
    SetInlineItemTextEdit(
        &wgui_inline_items[1],
        (U8*) email_p->fldr_info.jump_page_buff,
        EMAIL_MAX_JUMP_PAGE_INPUT_LEN + 1,
        INPUT_TYPE_NUMERIC);
    RightJustifyInlineItem(&wgui_inline_items[1]);
    EnableInlineItemBoundary(&wgui_inline_items[1]);
    SetInlineItemFullWidth(&wgui_inline_items[1]);
    DisableInlineItemHighlight(&wgui_inline_items[1]);

    OslMfree(asciiPageNumberInfoBuff);
    OslMfree(ucs2PageNumberInfoBuff);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_jump_page_req
 * DESCRIPTION
 *  Retrieve data from Jump Page inline editor screen and go to corresponding page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_jump_page_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    if (mmi_ucs2strlen((S8*) email_p->fldr_info.jump_page_buff))
    {
        U16 len;
        U16 pageNumberT;
        S8 ansiiPageNumber[EMAIL_MAX_JUMP_PAGE_INPUT_LEN + 1];

        len = mmi_ucs2_n_to_asc(
                (S8*) ansiiPageNumber,
                (S8*) email_p->fldr_info.jump_page_buff,
                (mmi_ucs2strlen((S8*) email_p->fldr_info.jump_page_buff) * ENCODING_LENGTH));
        ansiiPageNumber[len] = '\0';
        pageNumberT = atoi(ansiiPageNumber);

        if (pageNumberT > email_p->fldr_info.total_page || pageNumberT < 1)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_FOLDER_INVALID_PAGE_NUMBER_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
        else
        {
            email_p->fldr_info.curr_page = pageNumberT;
            mmi_email_fldr_exec_jump_page();
        }
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_next_page_req
 * DESCRIPTION
 *  Get next page index of current page and go to the page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_next_page_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.curr_page++;
    if ((email_p->fldr_info.curr_page > email_p->fldr_info.total_page) || (email_p->fldr_info.curr_page < 1))
    {
        email_p->fldr_info.curr_page = 1;
    }

    mmi_email_fldr_exec_jump_page();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_prev_page_req
 * DESCRIPTION
 *  Get previous page index of current page and go to the page
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_prev_page_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.curr_page--;
    if (email_p->fldr_info.curr_page < 1)
    {
        email_p->fldr_info.curr_page = email_p->fldr_info.total_page;
    }

    mmi_email_fldr_exec_jump_page();
}
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_get_num_mails
 * DESCRIPTION
 *  Get number of mails to be displayed in current folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of mails.
 *****************************************************************************/
S32 mmi_email_fldr_get_num_mails(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 numItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4 && email_p->main_info.curr_menu != MMI_EMAIL_UNSENT)
    {
        numItems =
            (!email_p->fldr_info.fldr_list.num_msgs) ? email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].
            total_mails : email_p->fldr_info.fldr_list.num_msgs;

        /* IMAP4 is page-based, can display one page per time -- this might be redundant because */
        numItems = (numItems > MMI_EMAIL_MAX_MSG_PER_PAGE) ? MMI_EMAIL_MAX_MSG_PER_PAGE : numItems;
    }
    else
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
        numItems = email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails;

    if (email_p->fldr_info.is_list_updated == FALSE && numItems == 0)
    {
        numItems = 1;
    }

    return numItems;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_reset_list_info_ex
 * DESCRIPTION
 *  Reset variables before entry a folder
 *  (for download option use)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_reset_list_info_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 temp_pool;
    S32 temp_start_index;
    S32 temp_end_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_start_index = email_p->mem_pool_info.start_indx;
    temp_end_index = email_p->mem_pool_info.end_indx;
    temp_pool = email_p->mem_pool_info.not_avail_pool;

    mmi_email_fldr_reset_list_info();

    email_p->mem_pool_info.start_indx = temp_start_index;
    email_p->mem_pool_info.end_indx = temp_end_index;
    email_p->mem_pool_info.not_avail_pool = temp_pool;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_reset_list_info
 * DESCRIPTION
 *  Reset variales before entry a folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of malis.(?)
 *****************************************************************************/
void mmi_email_fldr_reset_list_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 totalPool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->fldr_info.is_list_displayed = FALSE;

    mmi_email_util_free_container_pool();

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4 && email_p->main_info.curr_menu != MMI_EMAIL_UNSENT)
    {
        totalPool = 1;
    }
    else
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
        totalPool = EMAIL_TOTAL_POOL + 1;

    /* create pool */
    mmi_mem_create_container(
        totalPool,
        MMI_EMAIL_MAX_MSG_PER_PAGE,
        (void*)email_p->fldr_info.fldr_list.mail_list,
        sizeof(mmi_email_mail_info_struct),
        &email_p->mem_pool_info.mem_container);

    email_p->mem_pool_info.start_indx = 0;

    /* retrieve start/end index of pool */
    /* for IMAP4 related folder, because there is only 1 page, the maximal number is 5 (MMI_EMAIL_MAX_MSG_PER_PAGE),
       for POP3 and Unsent folder, the maximal number depends on maximal size of async pool */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4 && email_p->main_info.curr_menu != MMI_EMAIL_UNSENT)
    {
        if (email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails < MMI_EMAIL_MAX_MSG_PER_PAGE)
        {
            email_p->mem_pool_info.end_indx =
                email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails - 1;
        }
        else
        {
            email_p->mem_pool_info.end_indx = MMI_EMAIL_MAX_MSG_PER_PAGE - 1;
        }
    }
    else
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    {
        if (email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails < MAX_ASYNCDYNAMIC_ITEMS_BUFF)
        {
            email_p->mem_pool_info.end_indx =
                email_p->fldr_info.fldr_data[email_p->main_info.curr_menu].total_mails - 1;
        }
        else
        {
            email_p->mem_pool_info.end_indx = MAX_ASYNCDYNAMIC_ITEMS_BUFF - 1;
        }
    }

    email_p->mem_pool_info.not_avail_pool = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fldr_reset_cntx
 * DESCRIPTION
 *  Reset folder info.
 * PARAMETERS
 *  flag        [IN]        Flag to indicate reseting all folder or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fldr_reset_cntx(email_reset_fldr_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag == EMAIL_RESET_ALL_FLDR)
    {
        memset(&email_p->fldr_info.fldr_data, 0, sizeof(email_folder_info_struct) * EMAIL_FLDR_TOTAL);
    }
    else
    {
        memset(&email_p->fldr_info.fldr_data[MMI_EMAIL_INBOX], 0, sizeof(email_folder_info_struct));
        memset(&email_p->fldr_info.fldr_data[MMI_EMAIL_SENT], 0, sizeof(email_folder_info_struct));
        memset(&email_p->fldr_info.fldr_data[MMI_EMAIL_DRAFT], 0, sizeof(email_folder_info_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_fldr_corrupt_mail
 * DESCRIPTION
 *  Entry function when folder message select failed. Might because of mail corrupted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_fldr_corrupt_mail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_FLDR_CORRUPT_MAIL, mmi_email_exit_fldr_corrupt_mail, NULL, NULL);
    ShowCategory66Screen(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_DELETE,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)GetString(email_p->inbox_info.read_err_msg),
        IMG_GLOBAL_QUESTION,
        NULL);

    /* LSK == Delete, RSK == Back */
    SetLeftSoftkeyFunction(mmi_email_del_single_msg_done, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    if (play_warning_tone)
    {
        playRequestedTone(WARNING_TONE);
        play_warning_tone = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_fldr_corrupt_mail
 * DESCRIPTION
 *  Exit function when folder message select failed.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_fldr_corrupt_mail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_util_add_history(SCR_ID_EMAIL_FLDR_CORRUPT_MAIL, mmi_email_entry_fldr_corrupt_mail);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_fldr_progress
 * DESCRIPTION
 *  Display progressing screen before entry a folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_fldr_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->misc_info.folder_select_req = MMI_TRUE;
    if (GetExitScrnID() != SCR_ID_EMAIL_FLDR_LIST_PROGRESS)
    {
        EntryNewScreen(SCR_ID_EMAIL_FLDR_LIST_PROGRESS, mmi_email_exit_fldr_progress, NULL, NULL);

        ShowCategory66Screen(
            STR_EMAIL_MAIN_ID,
            GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
            0,
            0,
            mmi_email_util_abort_str(),
            mmi_email_util_abort_img(),
            (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
            IMG_GLOBAL_PROGRESS,
            NULL);

        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_email_util_get_abort_func(), KEY_EVENT_UP);
        SetKeyHandler(mmi_email_util_get_abort_func(), KEY_END, KEY_EVENT_DOWN);
        DeleteScreenIfPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_exit_fldr_progress
 * DESCRIPTION
 *  Exit function of folder progressing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_exit_fldr_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to make sure only 1 progressing screen in history */
    if (!IsScreenPresent(SCR_ID_EMAIL_FLDR_LIST_PROGRESS))
    {
        mmi_email_util_add_history(SCR_ID_EMAIL_FLDR_LIST_PROGRESS, mmi_email_entry_fldr_progress);
    }
}


#define FMGR_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_send_file_check
 * DESCRIPTION
 *  Check the file from file manager to send
 * PARAMETERS
 *  filePath        [IN]        Complete file path and name of the selected file
 *  is_short        [IN]        Convert the file name
 * RETURNS
 *  TRUE: can send; FALSE: can not
 *****************************************************************************/
BOOL mmi_email_send_file_check(S8 *filePath, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fileLen;
    S32 sigLen = 0;
    S32 f_result;
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    U8 mime_type, mime_subtype;
#endif
    BOOL ret = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_email_util_is_call_interrupt_allow())
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_IN_CALL_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        mmi_email_fmgr_send_free();
        return FALSE;
    }
    if (email_p->main_info.stop_cause == EMAIL_START_REQ)
    {
        mmi_email_fmgr_send_free();
        return FALSE;
    }
    if (email_p->main_info.stop_cause != EMAIL_STOP_NONE)
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_IN_USE_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        mmi_email_fmgr_send_free();
        return FALSE;
    }
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    if (filePath != NULL)
    {
        mmi_email_util_get_mine_type(
            (S8*) filePath,
            &mime_type,
            &mime_subtype);
        if ((mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) || (DRM_interdev_movable(0, (kal_wchar*)filePath) == MMI_FALSE))
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            mmi_email_fmgr_send_free();
            return FALSE;
        }
    }
#endif
    if (filePath == NULL)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
        ret = FALSE;
    }
    else if (mmi_email_prof_is_activated() == FALSE)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        ret = FALSE;
    }
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    else if (email_p->snr_info.is_auto_chk)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_AUTO_CHECK_BUSY_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        ret = FALSE;
    }
#endif
    else
    {
        if (email_p->prof_info.act_prof.sig_status && mmi_ucs2strlen((S8*)email_p->prof_info.act_prof.sig_img))
        {
            S8 *fileExt;
            S8 *tmp_file = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            
            /* file extension */
            fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.act_prof.sig_img);
            
            /* source file name */
            mmi_email_util_get_sig_name((U8) (email_p->prof_info.act_prof.act_indx + 1), (S8*) tmp_file);
            mmi_ucs2cat((S8*) tmp_file, (S8*) fileExt);
            mmi_email_util_get_file_size((S8*) tmp_file, &sigLen);
            OslMfree(tmp_file);
        }
        /* check file size */
        if ((f_result = mmi_email_util_get_file_size(filePath, &fileLen)) == FS_NO_ERROR)
        {
            if (fileLen == 0)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_EMPTY_FILE_ID),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                ret = FALSE;
            }
            else if (fileLen > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                ret = FALSE;
            }
            /* signature is on and signature image exists */
            else if (sigLen + fileLen > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                ret = FALSE;
            }
            else
            {
                S32 dirLen = 0;

                /* proceed adding attachment */
                if (email_p->other_app_info.fmgr_path == NULL)
                {
                    email_p->other_app_info.fmgr_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
                    mmi_ucs2cpy((S8*) email_p->other_app_info.fmgr_path, (S8*) filePath);
                    email_p->other_app_info.is_short = is_short;
                    /* extract file name and path */
                    dirLen = (S32) mmi_fmgr_get_last_dir_index((S8*) email_p->other_app_info.fmgr_path);
                    email_p->other_app_info.file_info.fileName = (S8*) email_p->other_app_info.fmgr_path;
                    email_p->other_app_info.file_info.fileName += dirLen;
                    /* file extension */
                    email_p->other_app_info.file_info.fileExt = mmi_email_get_file_ext((S8*) email_p->other_app_info.file_info.fileName);
                    /* get DRM information */
#ifdef __MMI_EMAIL_DRM_SUPPORT__
                    mmi_email_drm_is_file_lock(email_p->other_app_info.fmgr_path, (BOOL*)&(email_p->other_app_info.file_info.drm.is_valid));
#endif
                }
                if (email_p->other_app_info.is_short)
                {
                    if (email_p->other_app_info.conv_path == NULL)
                    {
                        S8* fmgr_name = OslMalloc((FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
                        U8 encoding = PhnsetGetDefEncodingType();
                        
                        email_p->other_app_info.conv_path = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
                        mmi_ucs2cpy((S8*) email_p->other_app_info.conv_path, (S8*) email_p->other_app_info.fmgr_path);
                        email_p->other_app_info.file_info.fileName = (S8*) email_p->other_app_info.conv_path;
                        email_p->other_app_info.file_info.fileName += dirLen;
                        mmi_chset_mixed_text_to_ucs2_str(
                            (U8*) fmgr_name,
                            FMGR_PATH_BUFFER_SIZE,
                            (U8*) email_p->other_app_info.file_info.fileName,
                            (mmi_chset_enum)encoding);
                        mmi_ucs2cpy(email_p->other_app_info.file_info.fileName, fmgr_name);
                        OslMfree(fmgr_name);
                        /* file extension */
                        email_p->other_app_info.file_info.fileExt = mmi_email_get_file_ext((S8*) email_p->other_app_info.file_info.fileName);
                    }
                }
                ret = TRUE;
            }
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString((U16) GetFileSystemErrorString(f_result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            ret = FALSE;
        }
    }
    if (ret == FALSE)
    {
        mmi_email_fmgr_send_free();
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_send_free
 * DESCRIPTION
 *  Free allocated memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fmgr_send_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->other_app_info.fmgr_path != NULL)
    {
        OslMfree(email_p->other_app_info.fmgr_path);
        email_p->other_app_info.fmgr_path = NULL;
    }
    if (email_p->other_app_info.conv_path != NULL)
    {
        OslMfree(email_p->other_app_info.conv_path);
        email_p->other_app_info.conv_path = NULL;
    }
    memset(&email_p->other_app_info.file_info, 0, sizeof(mmi_email_fmgr_file_info_struct));
    email_p->other_app_info.is_short = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_free_mem_n_back
 * DESCRIPTION
 *  Free allocated memory and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fmgr_free_mem_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_fmgr_send_free();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_send
 * DESCRIPTION
 *  Interface for file manager to send a file.
 * PARAMETERS
 *  filePath        [IN]        Complete file path and name of the selected file
 *  is_short        [IN]        Convert the file name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fmgr_send(S8 *filePath, BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((email_p->main_info.ready_state & EMAIL_READY) == EMAIL_READY) &&
        (mmi_email_bearer_status_show_icon()))
    {
        if (mmi_email_send_file_check(filePath, is_short))
        {
            if (mmi_email_comp_get_done_status())
            {
                mmi_email_display_confirm(
                    STR_EMAIL_OVERWRITE_WARNING,
                    mmi_email_fmgr_exec_send,
                    mmi_email_fmgr_free_mem_n_back);
            }
            else
            {
                mmi_email_fmgr_exec_send();
            }
        }
    }
    else    /* email application not ready */
    {
        if (!mmi_email_bearer_status_show_icon())
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_IN_CALL_ID),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    #ifdef __USB_IN_NORMAL_MODE__
        else if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        }
        else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_SMS_PLEASE_WAIT_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_exec_send
 * DESCRIPTION
 *  Execute sending of a file.
 *  Initialize global variable of Write Email screen and send email start request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fmgr_exec_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    UI_character_type mp3_str[8];
    UI_character_type mp2_str[8];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_email_send_file_check(email_p->other_app_info.fmgr_path, email_p->other_app_info.is_short))
    {
        return;
    }
    /* set state of Email */
    email_p->main_info.entry_src = EMAIL_FROM_APP;

    /* initialize structure of Write Email screen */
    mmi_email_comp_reset_member();
    
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    memcpy(&email_p->comp_info.attch_list[0].drm, &email_p->other_app_info.file_info.drm.is_valid, sizeof(email_drm_struct));
#endif

    /* copy file to file buffer */
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
    mmi_asc_to_ucs2((S8*) mp2_str, ".mp2");
    if ((email_p->other_app_info.file_info.fileExt != NULL) && ((mmi_ucs2icmp(email_p->other_app_info.file_info.fileExt, (S8*)mp3_str) == 0)))
    {
        S32 ext_len, name_len;
        
        name_len = mmi_ucs2strlen((S8*) email_p->other_app_info.file_info.fileName);
        ext_len = mmi_ucs2strlen(email_p->other_app_info.file_info.fileExt);
        kal_mem_set(&email_p->comp_info.attch_list[0].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
        mmi_ucs2ncpy(
            (S8*) email_p->comp_info.attch_list[0].file_name, 
            email_p->other_app_info.file_info.fileName, 
            name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if (email_p->comp_info.attch_list[0].drm.is_valid)
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_APPLICATION;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
            email_p->comp_info.attch_list[0].drm.mime_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP3;
        }
        else
#endif
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_AUDIO_MP3;
        }
    }
    else if ((email_p->other_app_info.file_info.fileExt != NULL) && ((mmi_ucs2icmp(email_p->other_app_info.file_info.fileExt, (S8*)mp2_str) == 0)))
    {
        S32 ext_len, name_len;
        
        name_len = mmi_ucs2strlen((S8*) email_p->other_app_info.file_info.fileName);
        ext_len = mmi_ucs2strlen(email_p->other_app_info.file_info.fileExt);
        kal_mem_set(&email_p->comp_info.attch_list[0].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
        mmi_ucs2ncpy(
            (S8*) email_p->comp_info.attch_list[0].file_name, 
            email_p->other_app_info.file_info.fileName, 
            name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if (email_p->comp_info.attch_list[0].drm.is_valid)
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_APPLICATION;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
            email_p->comp_info.attch_list[0].drm.mime_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP2;
        }
        else
#endif
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_AUDIO_MP2;
        }
    }
    else
#endif
    {
        mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[0].file_name, (S8*) email_p->other_app_info.file_info.fileName);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if (email_p->comp_info.attch_list[0].drm.is_valid)
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_APPLICATION;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
            mmi_email_util_get_mine_type(
                (S8*) email_p->comp_info.attch_list[0].file_name,
                &email_p->comp_info.attch_list[0].drm.mime_type,
                &email_p->comp_info.attch_list[0].drm.mime_subtype);
        }
        else
#endif
        {
            mmi_email_util_get_mine_type(
                (S8*) email_p->comp_info.attch_list[0].file_name,
                &email_p->comp_info.attch_list[0].attch_type,
                &email_p->comp_info.attch_list[0].attch_subtype);
        }
    }

    /* delete the original useless file */
    if (mmi_ucs2strlen((PS8)email_p->comp_info.attch_list[0].file_path) != 0)
    {
        mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[0].file_path);
        ret = FS_Delete((U16*) email_p->comp_info.attch_list[0].file_path);
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_FMGR_EXEC_SENT_DEL_FILE, ret);
        }
    }
    /* destination file name */
    mmi_email_util_get_comp_attch_name(1, (S8*) email_p->comp_info.attch_list[0].file_path);
    mmi_ucs2cat((S8*) email_p->comp_info.attch_list[0].file_path, (S8*) email_p->other_app_info.file_info.fileExt);

    /* fill copy file path */
    mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) email_p->other_app_info.fmgr_path);
    email_p->misc_info.file_copy_state = EMAIL_FILE_FROM_APP;

    /* delete the same name file */
    mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[0].file_path);
    ret = FS_Delete((U16*) email_p->comp_info.attch_list[0].file_path);
    mmi_fmgr_send_copy_req(
        FMGR_ACTION_COPY,
        (U8*) email_p->comm_buff,
        (U8*) email_p->comp_info.attch_list[0].file_path,
        mmi_email_comp_attach_copy_callback);
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);
    mmi_email_fmgr_send_free();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_fill_addr
 * DESCRIPTION
 *  fill to/cc/bcc address from other application to compose email info 
 * PARAMETERS
 * to_cc_addr        [IN]        to/cc/bcc address
 * addr_type         [IN]        EMAIL_ADDR_TO/EMAIL_ADDR_CC/EMAIL_ADDR_BCC
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_fill_addr(mmi_email_app_send_addr_struct *to_cc_addr,
        email_addr_type_enum addr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
    {
        if (to_cc_addr[i].addr_mail != NULL)
        {
            mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_list[addr_type].to_cc_mail[i],
            (S8*) to_cc_addr[i].addr_mail);
            email_p->comp_info.addr_list[addr_type].num_addr++;
        }
        if (to_cc_addr[i].addr_name != NULL)
        {
            mmi_ucs2cpy(
                (S8*) email_p->comp_info.addr_list[addr_type].to_cc_name[i],
                (S8*) to_cc_addr[i].addr_name);
        }
    }

    /* display buffer */
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[addr_type].to_cc_name[0]))
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[addr_type],
            (S8*) email_p->comp_info.addr_list[addr_type].to_cc_name[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[addr_type], (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->comp_info.addr_disp_buff[addr_type],
            (S8*) email_p->comp_info.addr_list[addr_type].to_cc_mail[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[addr_type], (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[addr_type],
            (S8*) email_p->comp_info.addr_list[addr_type].to_cc_mail[0]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_fill_prior
 * DESCRIPTION
 *  fill subject from other application to compose email info 
 * PARAMETERS
 *  priority     [IN]     priority of a mail
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_fill_prior(S32 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((priority == MMI_EMAIL_PRIOR_LOW) || (priority == MMI_EMAIL_PRIOR_HIGH))
    {
        email_p->comp_info.priority_indx = priority;
    }
    else
    {
        email_p->comp_info.priority_indx = MMI_EMAIL_PRIOR_NORMAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_init_param_to_null
 * DESCRIPTION
 *  init the data struct pointer to NULL
 * PARAMETERS
 *  mail_param     [IN]     data struct pointer of mail param
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_init_param_to_null(mmi_email_app_send_param_struct *mail_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
    {
        mail_param->to_addr[i].addr_mail = NULL;
        mail_param->to_addr[i].addr_name = NULL;
        
        mail_param->cc_addr[i].addr_mail = NULL;
        mail_param->cc_addr[i].addr_name = NULL;
    #ifdef __MMI_EMAIL_BCC__
        mail_param->bcc_addr[i].addr_mail = NULL;
        mail_param->bcc_addr[i].addr_name = NULL;
    #endif /*__MMI_EMAIL_BCC__*/
    }

    mail_param->subj = NULL;

    mail_param->attch_file_path = NULL;

    mail_param->priority = MMI_EMAIL_NORMAL_PRIORITY;

    mail_param->cont = NULL;

    mail_param->is_save_to_draft = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_copy_addr
 * DESCRIPTION
 *  copy to/cc/bcc parameters from other application
 * PARAMETERS
 *  addr_param     [IN]     address parameter
 *  addr_dest      [IN/OUT]     copying destination
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_copy_addr(mmi_email_app_send_addr_struct *addr_param,
        mmi_email_app_send_addr_struct *addr_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf_len;
    MMI_BOOL is_trunc = MMI_FALSE;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_param->addr_mail != NULL)
    {
        buf_len = mmi_ucs2strlen(addr_param->addr_mail);
    
        if (buf_len > MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
        {
            buf_len = MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS;
        }
        addr_dest->addr_mail = OslMalloc((buf_len + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
            (S8*) addr_dest->addr_mail,
            (S8*) addr_param->addr_mail,
            buf_len);
    }
    
    if (addr_param->addr_name != NULL)
    {
        buf_len = mmi_ucs2strlen(addr_param->addr_name);
    
        if (buf_len > EMAIL_PROF_DISP_NAME_LEN)
        {
            buf_len = EMAIL_PROF_DISP_NAME_LEN;
            is_trunc = MMI_TRUE;
        }
        addr_dest->addr_name = OslMalloc((buf_len + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
            (S8*) addr_dest->addr_name,
            (S8*) addr_param->addr_name,
            buf_len);
        if (is_trunc == MMI_TRUE)
        {
            addr_dest->addr_name[((EMAIL_PROF_DISP_NAME_LEN - 3) * ENCODING_LENGTH)] = '\0';
            addr_dest->addr_name[((EMAIL_PROF_DISP_NAME_LEN - 3) * ENCODING_LENGTH + 1)] = '\0';
            mmi_ucs2cat((S8*)addr_dest->addr_name, (S8*) g_email_3dots);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_copy_subj
 * DESCRIPTION
 *  copy subject parameter from other application
 * PARAMETERS
 *  subj     [IN]     subject parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_copy_subj(S8 *subj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf_len;
    MMI_BOOL is_trunc = MMI_FALSE;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (subj!= NULL)
    {
        buf_len = mmi_ucs2strlen(subj);

        if (buf_len > EMAIL_COMP_SUBJ_LEN)
        {
            buf_len = EMAIL_COMP_SUBJ_LEN;
            is_trunc = MMI_TRUE;
        }
        email_p->other_app_info.app_param.subj = OslMalloc((buf_len + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
            (S8*) email_p->other_app_info.app_param.subj,
            (S8*) subj,
            buf_len);
        if (is_trunc == MMI_TRUE)
        {
            email_p->other_app_info.app_param.subj[((EMAIL_COMP_SUBJ_LEN - 3) * ENCODING_LENGTH)] = '\0';
            email_p->other_app_info.app_param.subj[((EMAIL_COMP_SUBJ_LEN - 3) * ENCODING_LENGTH + 1)] = '\0';
            mmi_ucs2cat((S8*)email_p->other_app_info.app_param.subj, (S8*) g_email_3dots);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_copy_cont
 * DESCRIPTION
 *  copy content parameter from other application
 * PARAMETERS
 *  cont     [IN]     content parameter
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_copy_cont(S8 *cont)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf_len;
    MMI_BOOL is_trunc = MMI_FALSE;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cont!= NULL)
    {
        buf_len = mmi_ucs2strlen(cont);

        if (buf_len > EMAIL_MAX_CONT_LEN)
        {
            buf_len = EMAIL_MAX_CONT_LEN;
            is_trunc = MMI_TRUE;
        }
        email_p->other_app_info.app_param.cont= OslMalloc((buf_len + 1) * ENCODING_LENGTH);
        mmi_ucs2ncpy(
            (S8*) email_p->other_app_info.app_param.cont,
            (S8*) cont,
            buf_len);
        if (is_trunc == MMI_TRUE)
        {
            email_p->other_app_info.app_param.cont[((EMAIL_MAX_CONT_LEN - 3) * ENCODING_LENGTH)] = '\0';
            email_p->other_app_info.app_param.cont[((EMAIL_MAX_CONT_LEN - 3) * ENCODING_LENGTH + 1)] = '\0';
            mmi_ucs2cat((S8*)email_p->other_app_info.app_param.cont, (S8*) g_email_3dots);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_copy_param
 * DESCRIPTION
 *  copy parameters from other application
 * PARAMETERS
 *  mail_param              [IN]     parameters from other application
 *  mail_param_fill_flag    [IN]     parameter fill mask
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_copy_param(
        mmi_email_app_send_param_struct *mail_param,
        email_app_send_param_fill_enum mail_param_fill_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buf_len;
    U16 i;
      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*copy param fill flag*/
    email_p->other_app_info.app_param_fill_flag = mail_param_fill_flag;

    /*init email_p->other_app_info.app_param*/
    mmi_email_app_send_init_param_to_null(&email_p->other_app_info.app_param);
     
    /*copy is_save_to_draft*/
    email_p->other_app_info.app_param.is_save_to_draft = mail_param->is_save_to_draft;
     
    /*copy to*/
    if (mail_param_fill_flag & EMAIL_TO_FILL_FLAG)
    {
        for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
        {
            if (mail_param->to_addr[i].addr_mail != NULL)
            {
                mmi_email_app_send_copy_addr(&mail_param->to_addr[i], &email_p->other_app_info.app_param.to_addr[i]);
            }
        }
    }

    /*copy cc*/
    if (mail_param_fill_flag & EMAIL_CC_FILL_FLAG)
    {
        for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
        {
            if (mail_param->cc_addr[i].addr_mail != NULL)
            {
                mmi_email_app_send_copy_addr(&mail_param->cc_addr[i], &email_p->other_app_info.app_param.cc_addr[i]);
            }
        }        
    }
    
#ifdef __MMI_EMAIL_BCC__
    /*copy bcc*/
    if (mail_param_fill_flag & EMAIL_BCC_FILL_FLAG)
    {
        for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
        {
            if (mail_param->bcc_addr[i].addr_mail != NULL)
            {
                mmi_email_app_send_copy_addr(&mail_param->bcc_addr[i], &email_p->other_app_info.app_param.bcc_addr[i]);
            }
        }       
    }
#endif /*__MMI_EMAIL_BCC__*/

    /*copy subject*/
    if (mail_param_fill_flag & EMAIL_SUBJ_FILL_FLAG)
    {
        mmi_email_app_send_copy_subj(mail_param->subj);
    }

    /*copy attachment file path*/
    if (mail_param_fill_flag & EMAIL_ATTCH_FILL_FLAG)
    {
        if (mail_param->attch_file_path!= NULL)
        {
            buf_len = mmi_ucs2strlen(mail_param->attch_file_path);

            if (buf_len > FMGR_MAX_PATH_LEN)
            {
                buf_len = FMGR_MAX_PATH_LEN;
            }
            email_p->other_app_info.app_param.attch_file_path= OslMalloc((buf_len + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy(
                (S8*) email_p->other_app_info.app_param.attch_file_path,
                (S8*) mail_param->attch_file_path,
                buf_len);
        }
    }

    /*copy priority*/
    if (mail_param_fill_flag & EMAIL_PRIOR_FILL_FLAG)
    {
        email_p->other_app_info.app_param.priority = mail_param->priority;
    }

    /*copy content*/
    if (mail_param_fill_flag & EMAIL_CONT_FILL_FLAG)
    {
        mmi_email_app_send_copy_cont(mail_param->cont);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_fill_data_except_attch
 * DESCRIPTION
 *  fill data from other application to compose email info 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_fill_data_except_attch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_p->other_app_info.app_param_fill_flag & EMAIL_TO_FILL_FLAG)
    {
        mmi_email_app_send_fill_addr(email_p->other_app_info.app_param.to_addr, EMAIL_ADDR_TO);
    }

    if (email_p->other_app_info.app_param_fill_flag & EMAIL_CC_FILL_FLAG)
    {
        mmi_email_app_send_fill_addr(email_p->other_app_info.app_param.cc_addr, EMAIL_ADDR_CC);
    }
#ifdef __MMI_EMAIL_BCC__
    if (email_p->other_app_info.app_param_fill_flag & EMAIL_BCC_FILL_FLAG)
    {
        mmi_email_app_send_fill_addr(email_p->other_app_info.app_param.bcc_addr, EMAIL_ADDR_BCC);
    }
#endif /*__MMI_EMAIL_BCC__*/
    if (email_p->other_app_info.app_param_fill_flag & EMAIL_SUBJ_FILL_FLAG)
    {
        mmi_ucs2cpy((S8*) email_p->comp_info.subj_buff, email_p->other_app_info.app_param.subj);
    }
 
    if (email_p->other_app_info.app_param_fill_flag & EMAIL_PRIOR_FILL_FLAG)
    {
        mmi_email_app_send_fill_prior(email_p->other_app_info.app_param.priority);           
    }
    if (email_p->other_app_info.app_param_fill_flag & EMAIL_CONT_FILL_FLAG)
    {
        mmi_ucs2cpy((S8*) email_p->comp_info.cont_buff, email_p->other_app_info.app_param.cont);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_check_send_addr
 * DESCRIPTION
 *  Check the mail address
 * PARAMETERS
 *  mail_param             [IN]        input parameter by other application
 *                                     the input string should bu UCS2
 * RETURNS
 *  TURE: valid, FALSE: invalid
 *****************************************************************************/
BOOL mmi_email_app_check_send_addr(mmi_email_app_send_param_struct *mail_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
    {
        if (mmi_ucs2strlen((S8*) mail_param->to_addr[i].addr_mail) == 0)
        {
            break;
        }
        if (!mmi_email_util_chk_addr((U8*) mail_param->to_addr[i].addr_mail))
        {
            return FALSE;
        }
    }
    for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
    {
        if (mmi_ucs2strlen((S8*) mail_param->cc_addr[i].addr_mail) == 0)
        {
            break;
        }
        if (!mmi_email_util_chk_addr((U8*) mail_param->cc_addr[i].addr_mail))
        {
            return FALSE;
        }
    }
#ifdef __MMI_EMAIL_BCC__
    for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
    {
        if (mmi_ucs2strlen((S8*) mail_param->bcc_addr[i].addr_mail) == 0)
        {
            break;
        }
        if (!mmi_email_util_chk_addr((U8*) mail_param->bcc_addr[i].addr_mail))
        {
            return FALSE;
        }
    }
#endif /*__MMI_EMAIL_BCC__*/
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_file_check
 * DESCRIPTION
 *  Check the file from other APP to send
 * PARAMETERS
 *  filePath                [IN]        Complete file path and name of the selected file
 *  mail_param_fill_flag    [IN]        input parameter fill flag mask
 * RETURNS
 *  TRUE: can send; FALSE: can not
 *****************************************************************************/
BOOL mmi_email_app_send_file_check(S8 *filePath, email_app_send_param_fill_enum mail_param_fill_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fileLen = 0;
    S32 sigLen = 0;
    S32 f_result = FS_NO_ERROR;
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    U8 mime_type, mime_subtype;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_email_util_is_call_interrupt_allow())
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_IN_CALL_ID),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return FALSE;
    }
    if (email_p->main_info.stop_cause == EMAIL_START_REQ)
    {
        return FALSE;
    }
    if (email_p->main_info.stop_cause != EMAIL_STOP_NONE)
    {
        DisplayPopup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_IN_USE_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return FALSE;
    }
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    if (filePath != NULL)
    {
        mmi_email_util_get_mine_type(
            (S8*) filePath,
            &mime_type,
            &mime_subtype);
        if ((mime_subtype == MIME_SUBTYPE_DRM_MESSAGE) || (DRM_interdev_movable(0, (kal_wchar*)filePath) == MMI_FALSE))
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_DRM_PROHIBITED),
                IMG_GLOBAL_WARNING,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return FALSE;
        }
    }
#endif
    if (mail_param_fill_flag == 0x00)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
        return FALSE;
    }
    else if (mmi_email_prof_is_activated() == FALSE)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return FALSE;
    }
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    else if (email_p->snr_info.is_auto_chk)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_AUTO_CHECK_BUSY_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return FALSE;
    }
#endif
    else
    {
        if (email_p->prof_info.act_prof.sig_status && mmi_ucs2strlen((S8*)email_p->prof_info.act_prof.sig_img))
        {
            S8 *fileExt;
            S8 *tmp_file = OslMalloc((FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            
            /* file extension */
            fileExt = mmi_email_get_file_ext((S8*) email_p->prof_info.act_prof.sig_img);
            
            /* source file name */
            mmi_email_util_get_sig_name((U8) (email_p->prof_info.act_prof.act_indx + 1), (S8*) tmp_file);
            mmi_ucs2cat((S8*) tmp_file, (S8*) fileExt);
            f_result = mmi_email_util_get_file_size((S8*) tmp_file, &sigLen);
            if (f_result != FS_NO_ERROR)
            {
                f_result = FS_NO_ERROR;
                sigLen = 0;
            }
            OslMfree(tmp_file);
        }
        /* check file size */
        if ((mail_param_fill_flag & EMAIL_ATTCH_FILL_FLAG) && (f_result == FS_NO_ERROR))
        {
            if ((f_result = mmi_email_util_get_file_size(filePath, &fileLen)) == FS_NO_ERROR)
            {
                if (fileLen == 0)
                {
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_EMAIL_EMPTY_FILE_ID),
                        IMG_GLOBAL_ERROR,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    return FALSE;
                }
                else if (fileLen > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
                {
                    mmi_email_util_display_popup(
                        (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
                        IMG_GLOBAL_ERROR,
                        1,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        (U8) ERROR_TONE);
                    return FALSE;
                }
            }
        }
        if (f_result == FS_NO_ERROR)
        {
            /* signature is on and signature image exists */
            if (sigLen + fileLen > MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_SIZE_TOO_LARGE),
                    IMG_GLOBAL_ERROR,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    (U8) ERROR_TONE);
                return FALSE;
            }
        }
        else
        {
            mmi_email_util_display_popup(
                (U8*) GetString((U16) GetFileSystemErrorString(f_result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return FALSE;
        }
    }
    return TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send
 * DESCRIPTION
 *  Interface for other applications to send a mail.
 * PARAMETERS
 *  mail_param             [IN]        input parameter by other application
 *                                     the input string should bu UCS2
 *  mail_param_fill_flag   [IN]        input parameter fill flag mask
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send(
        mmi_email_app_send_param_struct *mail_param,
        email_app_send_param_fill_enum mail_param_fill_flag)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((email_p->main_info.ready_state & EMAIL_READY) == EMAIL_READY) &&
        (mmi_email_bearer_status_show_icon()))
    {
        if (mail_param == NULL || mail_param_fill_flag == 0x00)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
            return;
        }
        if (mmi_email_app_send_file_check(mail_param->attch_file_path, mail_param_fill_flag))
        {
            mmi_email_app_send_copy_param(mail_param, mail_param_fill_flag);
            if (!mmi_email_app_check_send_addr(mail_param))
            {
                mmi_email_util_display_popup(
                    (U8*) GetString(STR_EMAIL_ERROR_CODE_INVALID_EMAIL_ADDR_ID),
                    IMG_GLOBAL_ERROR,
                    0,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    ERROR_TONE);
                mmi_email_app_send_free_mem();
            }
            else if (mmi_email_comp_get_done_status())
            {
                mmi_email_display_confirm(
                    STR_EMAIL_OVERWRITE_WARNING,
                    mmi_email_app_exec_send,
                    mmi_email_app_free_mem_n_back);
            }
            else
            {
                mmi_email_app_exec_send();
            }
        }
    }
    else    /* email application not ready */
    {
        if (!mmi_email_bearer_status_show_icon())
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_IN_CALL_ID),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
#ifdef __USB_IN_NORMAL_MODE__
        else if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        }
        else
#endif /* __USB_IN_NORMAL_MODE__ */ 
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_SMS_PLEASE_WAIT_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_exec_send
 * DESCRIPTION
 *  Execute sending of a file.
 *  Initialize global variable of Write Email screen and send email start request.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_exec_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dirLen, ret = 0;
    S8 *fileName;
    S8 *fileExt;
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    UI_character_type mp3_str[8];
    UI_character_type mp2_str[8];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_email_app_send_file_check(email_p->other_app_info.app_param.attch_file_path, email_p->other_app_info.app_param_fill_flag))
    {
        mmi_email_app_send_free_mem();
        return;
    }
    /* set state of Email */
    email_p->main_info.entry_src = EMAIL_FROM_APP;

    /* initialize structure of Write Email screen */
    mmi_email_comp_reset_member();

    /*fill compose info except attachment*/
    mmi_email_app_send_fill_data_except_attch();
     
    if((email_p->other_app_info.app_param_fill_flag & EMAIL_ATTCH_FILL_FLAG) == 0)/*No attachment*/
    {
        email_p->main_info.curr_menu = MMI_EMAIL_COMP;
        mmi_email_ps_start_req();
        mmi_email_app_send_free_mem();
        return;
    }
    
    /* extract file name and path */
    dirLen = (S32) mmi_fmgr_get_last_dir_index((S8*) email_p->other_app_info.app_param.attch_file_path);
    fileName = (S8*) email_p->other_app_info.app_param.attch_file_path;
    fileName += dirLen;
    
    /* file extension */
    fileExt = mmi_email_get_file_ext((S8*) fileName);

#ifdef __MMI_EMAIL_DRM_SUPPORT__
    mmi_email_drm_is_file_lock(email_p->other_app_info.app_param.attch_file_path, (BOOL*)&(email_p->comp_info.attch_list[0].drm.is_valid));
#endif
    /* copy file to file buffer */
#ifndef __MMI_SHOW_DAF_FILE_EXT__
    mmi_asc_to_ucs2((S8*) mp3_str, ".mp3");
    mmi_asc_to_ucs2((S8*) mp2_str, ".mp2");
    if ((fileExt != NULL) && ((mmi_ucs2icmp(fileExt, (S8*)mp3_str) == 0)))
    {
        S32 ext_len, name_len;
        
        name_len = mmi_ucs2strlen((S8*) fileName);
        ext_len = mmi_ucs2strlen(fileExt);
        kal_mem_set(&email_p->comp_info.attch_list[0].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
        mmi_ucs2ncpy((S8*) email_p->comp_info.attch_list[0].file_name, fileName, name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if (email_p->comp_info.attch_list[0].drm.is_valid)
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_APPLICATION;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
            email_p->comp_info.attch_list[0].drm.mime_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP3;
        }
        else
#endif
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_AUDIO_MP3;
        }
    }
    else if ((fileExt != NULL) && ((mmi_ucs2icmp(fileExt, (S8*)mp2_str) == 0)))
    {
        S32 ext_len, name_len;
        
        name_len = mmi_ucs2strlen((S8*) fileName);
        ext_len = mmi_ucs2strlen(fileExt);
        kal_mem_set(&email_p->comp_info.attch_list[0].file_name, 0, sizeof(UI_character_type) * (FMGR_MAX_FILE_LEN + 1));
        mmi_ucs2ncpy((S8*) email_p->comp_info.attch_list[0].file_name, fileName, name_len - ext_len);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if (email_p->comp_info.attch_list[0].drm.is_valid)
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_APPLICATION;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
            email_p->comp_info.attch_list[0].drm.mime_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].drm.mime_subtype = MIME_SUBTYPE_AUDIO_MP2;
        }
        else
#endif
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_AUDIO;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_AUDIO_MP2;
        }
    }
    else
#endif
    {
        mmi_ucs2cpy((S8*) email_p->comp_info.attch_list[0].file_name, (S8*) fileName);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
        if (email_p->comp_info.attch_list[0].drm.is_valid)
        {
            email_p->comp_info.attch_list[0].attch_type = MIME_TYPE_APPLICATION;
            email_p->comp_info.attch_list[0].attch_subtype = MIME_SUBTYPE_DRM_CONTENT;
            mmi_email_util_get_mine_type(
                (S8*) email_p->comp_info.attch_list[0].file_name,
                &email_p->comp_info.attch_list[0].drm.mime_type,
                &email_p->comp_info.attch_list[0].drm.mime_subtype);
        }
        else
#endif
        {
            mmi_email_util_get_mine_type(
                (S8*) email_p->comp_info.attch_list[0].file_name,
                &email_p->comp_info.attch_list[0].attch_type,
                &email_p->comp_info.attch_list[0].attch_subtype);
        }
    }

    /* delete the original useless file */
    if (mmi_ucs2strlen((PS8)email_p->comp_info.attch_list[0].file_path) != 0)
    {
        mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[0].file_path);
        ret = FS_Delete((U16*) email_p->comp_info.attch_list[0].file_path);
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_APP_EXEC_SENT_DEL_FILE, ret);
        }
    }
    /* destination file name */
    mmi_email_util_get_attch_name(1, (S8*) email_p->comp_info.attch_list[0].file_path);
    mmi_ucs2cat((S8*) email_p->comp_info.attch_list[0].file_path, (S8*) fileExt);

    mmi_ucs2cpy((S8*) email_p->comm_buff, (S8*) email_p->other_app_info.app_param.attch_file_path);

    email_p->misc_info.file_copy_state = EMAIL_FILE_FROM_APP;
   
    /* delete the same name file */
    mmi_email_util_reset_file_attr(email_p->comp_info.attch_list[0].file_path);
    ret = FS_Delete((U16*) email_p->comp_info.attch_list[0].file_path);
    mmi_fmgr_send_copy_req(
        FMGR_ACTION_COPY,
        (U8*) email_p->comm_buff,
        (U8*) email_p->comp_info.attch_list[0].file_path,
        mmi_email_comp_attach_copy_callback);
    mmi_email_pre_entry_progressing(
        STR_EMAIL_MAIN_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_EMAIL_COMMON_LOADING_ID),
        (U8*) NULL,
        IMG_GLOBAL_PROGRESS,
        NULL,
        NULL,
        NULL);

    mmi_email_app_send_free_mem();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_free_mem
 * DESCRIPTION
 *  Free allocated memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*release to memory*/
    for (i = 0; i < MMI_EMAIL_MAX_LEN_ADDR_LIST; i++)
    {
        if (email_p->other_app_info.app_param.to_addr[i].addr_mail != NULL)
        {
            OslMfree(email_p->other_app_info.app_param.to_addr[i].addr_mail);
            email_p->other_app_info.app_param.to_addr[i].addr_mail = NULL;
        }
        if (email_p->other_app_info.app_param.to_addr[i].addr_name != NULL)
        {
            OslMfree(email_p->other_app_info.app_param.to_addr[i].addr_name);
            email_p->other_app_info.app_param.to_addr[i].addr_name = NULL;
        }
        /*release cc memory*/
        if (email_p->other_app_info.app_param.cc_addr[i].addr_mail != NULL)
        {
            OslMfree(email_p->other_app_info.app_param.cc_addr[i].addr_mail);
            email_p->other_app_info.app_param.cc_addr[i].addr_mail = NULL;
        }
        if (email_p->other_app_info.app_param.cc_addr[i].addr_name != NULL)
        {
            OslMfree(email_p->other_app_info.app_param.cc_addr[i].addr_name);
            email_p->other_app_info.app_param.cc_addr[i].addr_name = NULL;
        }
    #ifdef __MMI_EMAIL_BCC__
        /*release bcc memory*/
        if (email_p->other_app_info.app_param.bcc_addr[i].addr_mail != NULL)
        {
            OslMfree(email_p->other_app_info.app_param.bcc_addr[i].addr_mail);
            email_p->other_app_info.app_param.bcc_addr[i].addr_mail = NULL;
        }
        if (email_p->other_app_info.app_param.bcc_addr[i].addr_name != NULL)
        {
            OslMfree(email_p->other_app_info.app_param.bcc_addr[i].addr_name);
            email_p->other_app_info.app_param.bcc_addr[i].addr_name = NULL;
        }
    #endif /*__MMI_EMAIL_BCC__*/
    }
    /*release subject memory*/
    if (email_p->other_app_info.app_param.subj != NULL)
    {
        OslMfree(email_p->other_app_info.app_param.subj);
        email_p->other_app_info.app_param.subj = NULL;
    }
    /*release attach memory*/
    if (email_p->other_app_info.app_param.attch_file_path != NULL)
    {
        OslMfree(email_p->other_app_info.app_param.attch_file_path);
        email_p->other_app_info.app_param.attch_file_path = NULL;
    }
    /*release content memory*/
    if (email_p->other_app_info.app_param.cont != NULL)
    {
        OslMfree(email_p->other_app_info.app_param.cont);
        email_p->other_app_info.app_param.cont = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_free_mem_n_back
 * DESCRIPTION
 *  Free allocated memory and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_free_mem_n_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_app_send_free_mem();
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_cont
 * DESCRIPTION
 *  Interface for other applications to send a UCS2 string as email content.
 * PARAMETERS
 *  cont             [IN]        input parameter by other application
 *                               the input string should bu UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_cont(const S8* cont)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_send_param_struct email_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cont != NULL)
    {
        mmi_email_app_send_init_param_to_null(&email_param);
        email_param.cont = (S8*)cont;
        mmi_email_app_send(&email_param, EMAIL_CONT_FILL_FLAG);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_to
 * DESCRIPTION
 *  Interface for other applications to use a UCS2 string as TO address
 *  to send an email
 * PARAMETERS
 *  to_addr             [IN]        input parameter by other application
 *                                  the input string should be UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_to(const S8* to_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_send_param_struct email_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (to_addr != NULL)
    {
        mmi_email_app_send_init_param_to_null(&email_param);
        email_param.to_addr[0].addr_mail = (S8*)to_addr;
        mmi_email_app_send(&email_param, EMAIL_TO_FILL_FLAG);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_app_send_attch
 * DESCRIPTION
 *  Interface for other applications to use a UCS2 string
 *  as attachment file path to send an email
 * PARAMETERS
 *  file_path             [IN]        input parameter by other application
 *                                    the input string should be UCS2
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_app_send_attch(const S8* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_email_app_send_param_struct email_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_path != NULL)
    {
        mmi_email_app_send_init_param_to_null(&email_param);
        email_param.attch_file_path = (S8*)file_path;
        mmi_email_app_send(&email_param, EMAIL_ATTCH_FILL_FLAG);
    }
    else
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_fmgr_reset_status_icon
 * DESCRIPTION
 *  When file system formats by file manager, 
 *  it should call the function to reset email status icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_fmgr_reset_status_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef APP_STORAGE_IN_SYS_DRV
    email_p->main_info.unread_mails = 0;
    email_p->main_info.is_mem_full = FALSE;
    HideStatusIcon(STATUS_ICON_UNREAD_EMAIL);
    UpdateStatusIcons();
#endif
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    if (email_p->snr_info.is_auto_chk)
    {
        email_p->main_info.stop_cause = EMAIL_STOP_BACK_FROM_OTHER;
        mmi_email_ps_stop_req();
    }
#endif
}

#define PHONEBOOK_EMAIL


/*****************************************************************************
 * FUNCTION
 *  mmi_email_send_from_phb
 * DESCRIPTION
 *  Interface for sending from Phonebook module
 * PARAMETERS
 *  name        [IN]        Name of selected person
 *  email       [IN]        Email address of selected person
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_send_from_phb(S8 *name, S8 *email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((email_p->main_info.ready_state & EMAIL_READY) == EMAIL_READY) &&
        (mmi_email_bearer_status_show_icon()))
    {
        email_p->other_app_info.phb_name = name;
        email_p->other_app_info.phb_email = email;
        if (!mmi_ucs2strlen((S8*) email_p->other_app_info.phb_email))
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_GLOBAL_EMPTY),
                IMG_GLOBAL_EMPTY,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) EMPTY_LIST_TONE);
            return;
        }
        if (email_p->main_info.stop_cause == EMAIL_START_REQ)
        {
            return;
        }
        if (email_p->main_info.stop_cause != EMAIL_STOP_NONE)
        {
            DisplayPopup(
                (U8*) GetString(STR_EMAIL_ERROR_CODE_IN_USE_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
            return;
        }
        else
        {
            if (mmi_email_comp_get_done_status())
            {
                mmi_email_display_confirm(STR_EMAIL_OVERWRITE_WARNING, mmi_email_send_from_phb_done, GoBackHistory);
            }
            else
            {
                mmi_email_send_from_phb_done();
            }
        }
    }
    else    /* email application not ready */
    {
        if (!mmi_email_bearer_status_show_icon())
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_IN_CALL_ID),
                IMG_GLOBAL_ERROR,
                0,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
        }
    #ifdef __USB_IN_NORMAL_MODE__
        else if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        }
        else
    #endif /* __USB_IN_NORMAL_MODE__ */ 
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_SMS_PLEASE_WAIT_ID),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_send_from_phb_done
 * DESCRIPTION
 *  Execute send from phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_send_from_phb_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_comp_reset_member();

    /* copy address to To */
    mmi_ucs2cpy(
        (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0],
        (S8*) email_p->other_app_info.phb_email);
    mmi_ucs2ncpy(
        (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0],
        (S8*) email_p->other_app_info.phb_name,
        EMAIL_PROF_DISP_NAME_LEN);

    /* copy name if existing */
    if (mmi_ucs2strlen((S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]))
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_name[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_left_op);
        mmi_ucs2cat(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
        mmi_ucs2cat((S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO], (S8*) g_email_subj_right_op);
    }
    else
    {
        mmi_ucs2cpy(
            (S8*) email_p->comp_info.addr_disp_buff[EMAIL_ADDR_TO],
            (S8*) email_p->comp_info.addr_list[EMAIL_ADDR_TO].to_cc_mail[0]);
    }

    email_p->main_info.entry_src = EMAIL_FROM_APP;
    email_p->main_info.curr_menu = MMI_EMAIL_COMP;

    /* start email module */
    mmi_email_ps_start_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_phb_get_addr_callback
 * DESCRIPTION
 *  Callback function for phonebook when finish selecting an Email address
 * PARAMETERS
 *  name        [IN]        Name of selected person
 *  email       [IN]        Email address of selected person
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_phb_get_addr_callback(S8 *name, S8 *email)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen(email) == 0)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_EMAIL_ADDRESS_EMPTY),
            IMG_GLOBAL_ERROR,
            FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            ERROR_TONE);
    }
    else
    {
        mmi_ucs2ncpy((S8*) email_p->comp_info.phb_name, (S8*) name, EMAIL_PROF_DISP_NAME_LEN);
        mmi_ucs2cpy((S8*) email_p->comp_info.phb_addr, (S8*) email);
        mmi_ucs2cpy((S8*) email_p->comp_info.addr_input_buff, (S8*) email);
        email_p->comp_info.load_addr_done = TRUE;
        GoBackToHistory(SCR_ID_EMAIL_COMP_ADDR_INPUT);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_malloc
 * DESCRIPTION
 *  function to call OslMalloc
 * PARAMETERS
 *  size        [IN]        size to malloc
 * RETURNS
 *  address be malloced
 *****************************************************************************/
static void* mmi_email_malloc(kal_uint32 size)
{
    void* p;

    p = OslMalloc(size);
    return p;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_free
 * DESCRIPTION
 *  function to call OslMfree
 * PARAMETERS
 *  p        [IN]        address to be free
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_free(void* p)
{
    OslMfree(p);
    p = NULL;
}

static kal_bool mmi_email_extract_addr_check_stop_func(applib_addr_type_enum type, applib_address_node_struct *addr, kal_uint32 num)
{   
    if (num >= EMAIL_MAX_DISP_ADDR_NUM)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;    
}


#if defined(__MMI_EMAIL_TEMPLATE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_comp_cont_opt
 * DESCRIPTION
 *  Entry function of content option for full screen editor(added template).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_comp_cont_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 numItems;
    U16 nStrItemList[3];    /* done, input method, use template */
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_COMP_CONT_INPUT_OPT, NULL, mmi_email_entry_comp_cont_opt, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_COMP_CONT_INPUT_OPT);
    SetParentHandler(MENU_ID_EMAIL_COMP_CONT_OPT);
    numItems = GetNumOfChild(MENU_ID_EMAIL_COMP_CONT_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_COMP_CONT_OPT, nStrItemList);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_template
 * DESCRIPTION
 *  Highlight handler of Template option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_hilite_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_p->main_info.curr_menu = MMI_EMAIL_TEMPLATE;

    SetLeftSoftkeyFunction(mmi_email_entry_template_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_template_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_insert_template
 * DESCRIPTION
 *  Insert template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_insert_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *templ;
    history temphistory;
    historyNode *History;
    S32 buf_size, text_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_INSERT_TEMPLATE);

    templ = email_p->templates[email_p->curr_template_index];

    if (templ)
    {
        text_len = mmi_ucs2strlen((S8*) templ);

        buf_size = (EMAIL_MAX_CONT_LEN + 1) * ENCODING_LENGTH;
        
        /* 
         * after entry new screen MMI_multiline_inputbox.text_length is reset, 
         * so, remember the length when entry content editor screen    
         */
        if ((compose_input_length + text_len * ENCODING_LENGTH) > buf_size)
        {
            mmi_email_util_display_popup(
                (U8*) GetString(STR_EMAIL_NO_SPACE_ID),
                IMG_GLOBAL_ERROR,
                TRUE,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }
        
        memset(&temphistory, 0, sizeof(temphistory));
        GetHistory(SCR_ID_EMAIL_COMP_CONT_INPUT, &temphistory);

        AppendCategory5String(
            INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
            (U8*)email_p->misc_info.cont_inline_buff,
            buf_size,
            (U8*) templ,
            temphistory.guiBuffer);

        if (GetHistoryScrID(SCR_ID_EMAIL_COMP_CONT_INPUT, &History) == ST_SUCCESS)
        {
            memcpy(History->guiBuffer, temphistory.guiBuffer, MAX_GUI_BUFFER);
        }

        mmi_email_util_go_back_2_hist();
    }

    mmi_email_deinit_templates();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_save_template
 * DESCRIPTION
 *  Save template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_save_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_store_template(email_p->curr_template_index))
    {
        mmi_email_util_display_popup(
            (PU8) GetString(STR_GLOBAL_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SAVE_TONE);
    }
    else
    {
        mmi_email_util_display_popup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    mmi_email_util_del_between_scr(SCR_ID_EMAIL_TEMPLATE_OPTION, SCR_ID_EMAIL_TEMPLATE_EDIT_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_erase_template
 * DESCRIPTION
 *  Erase template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_erase_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_delete_template(email_p->curr_template_index))
    {
        mmi_email_util_display_popup(
            (PU8) GetString(STR_EMAIL_ERASED_ID),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
    }
    else
    {
        mmi_email_util_display_popup(
            (PU8) GetString(STR_GLOBAL_UNFINISHED),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    DeleteScreenIfPresent(SCR_ID_EMAIL_TEMPLATE_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_pre_erase_template
 * DESCRIPTION
 *  Before erase template, check if it is empty
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_pre_erase_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2strlen(email_p->templates[email_p->curr_template_index]))
    {
        mmi_email_util_display_popup(
            (PU8) GetString(STR_GLOBAL_EMPTY),
            IMG_GLOBAL_EMPTY,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) EMPTY_LIST_TONE);        
        DeleteScreenIfPresent(SCR_ID_EMAIL_TEMPLATE_OPTION);
    }
    else
    {
        mmi_email_display_confirm(STR_EMAIL_ERASE_CONFIRM_ID, mmi_email_erase_template, mmi_email_util_go_back_2_hist);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_go_back_from_template
 * DESCRIPTION
 *  Deinit template before go back screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_go_back_from_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_deinit_templates();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_template_list
 * DESCRIPTION
 *  Entry template list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_template_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 hiliteitem = 0;
    U16 lsk_str_id = 0;
    U16 lsk_img_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_TEMPLATE_LIST);

    if (mmi_email_init_templates() == FALSE)
    {        
        mmi_email_util_display_popup(
            (PU8) GetString(STR_EMAIL_NOT_SUPPORT_ID),
            IMG_GLOBAL_ERROR,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return;
    }
    /* may takes time, so check the call status before entry new screen */
    if (!mmi_email_util_is_call_interrupt_allow())
    {
        return;
    }

    EntryNewScreen(SCR_ID_EMAIL_TEMPLATE_LIST, NULL, mmi_email_entry_template_list, NULL);
    mmi_email_load_templates_in_display_list();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_TEMPLATE_LIST);
    if (guiBuffer != NULL)
    {
        hiliteitem = (email_p->curr_template_index < MMI_EMAIL_NUM_TEMPLATES) ? email_p->curr_template_index : 0;
    }
    RegisterHighlightHandler(mmi_email_get_template_index);

    if (IsScreenPresent(SCR_ID_EMAIL_COMP))
    {
        lsk_str_id = STR_GLOBAL_OK;
        lsk_img_id = IMG_GLOBAL_OK;
    }
	else
    {
        lsk_str_id = STR_GLOBAL_OPTIONS;
        lsk_img_id = IMG_GLOBAL_OPTIONS;	
    }
	
    ShowCategory184Screen(
        STR_EMAIL_TEMPLATE_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        lsk_str_id,
        lsk_img_id,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        MMI_EMAIL_NUM_TEMPLATES,
        mmi_email_template_list_get_item,
        NULL,
        hiliteitem,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_email_go_back_from_template, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_go_back_from_template, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

    if (IsScreenPresent(SCR_ID_EMAIL_COMP))
    {
        SetLeftSoftkeyFunction(mmi_email_insert_template, KEY_EVENT_UP);
        SetKeyHandler(mmi_email_insert_template, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_email_entry_template_option, KEY_EVENT_UP);
        SetKeyHandler(mmi_email_entry_template_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_template_list_get_item
 * DESCRIPTION
 *  Get template list item
 * PARAMETERS
 *  item_index          [IN]            
 *  str_buff            [IN]            
 *  img_buff_p          [?]             
 *  str_img_mask        [IN]            
 *  a(?)                [IN]            Item index
 *  d(?)                [IN/OUT]        String image mask
 *  c(?)                [IN/OUT]        Image buffer
 *  b(?)                [IN/OUT]        String buffer
 * RETURNS
 * TRUE
 *****************************************************************************/
static pBOOL mmi_email_template_list_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((item_index < 0) || (item_index >= MMI_EMAIL_NUM_TEMPLATES))
    {
        return FALSE;
    }

    if (mmi_ucs2strlen(email_p->templates[item_index]) == 0)
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        mmi_ucs2cpy((S8*) str_buff, (S8*) email_p->templates[item_index]);
    }

    *img_buff_p = get_image(gIndexIconsImageList[item_index]);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_template_option
 * DESCRIPTION
 *  Entry template option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_template_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_TEMPLATE_OPTION, NULL, mmi_email_entry_template_option, NULL);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_TEMPLATE_OPTION);
    
    //reset the menu item
    mmi_frm_unhide_menu_item(MENU_ID_EMAIL_TEMPL_WRITE_EMAIL);

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    if (email_p->prof_info.act_prof.in_prot == EMAIL_PROT_IMAP4 && email_p->mode_status.curr_mode == EMAIL_MODE_OFFLINE)
    {
        mmi_frm_hide_menu_item(MENU_ID_EMAIL_TEMPL_WRITE_EMAIL);
    }
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_TEMPLATE_OPTION);
    numItems = GetNumOfChild_Ext(MENU_ID_EMAIL_TEMPLATE_OPT);
    GetSequenceStringIds_Ext(MENU_ID_EMAIL_TEMPLATE_OPT, nStrItemList);
    SetParentHandler(MENU_ID_EMAIL_TEMPLATE_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_EMAIL_TEMPLATE_OPTION_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_template_edit
 * DESCRIPTION
 *  Entry template edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_template_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_TEMPLATE_EDIT, NULL, mmi_email_entry_template_edit, NULL);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_TEMPLATE_EDIT);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_TEMPLATE_EDIT);
    if (!guiBuffer)
    {
        mmi_email_get_templates_to_edit(email_p->scratch_templ_rec, email_p->curr_template_index);
    }

    ShowCategory5Screen(
        STR_EMAIL_EDIT_TEMPLATE_ID,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        INPUT_TYPE_ALPHANUMERIC_SENTENCECASE,
        (U8*) email_p->scratch_templ_rec,
        MMI_EMAIL_MAX_TEMPLATE_LENGTH + 1,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_email_entry_template_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    RegisterInputMethodScreenCloseFunction(mmi_email_util_go_back_2_hist);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_template_edit_option
 * DESCRIPTION
 *  Entry template edit option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_entry_template_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_EMAIL_TEMPLATE_EDIT_OPTION, NULL, mmi_email_entry_template_edit_option, NULL);
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_ENTRY_TEMPLATE_EDIT_OPTION);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_EMAIL_TEMPLATE_EDIT_OPTION);

    numItems = GetNumOfChild(MENU_ID_EMAIL_EDIT_TEMPL_OPT);
    GetSequenceStringIds(MENU_ID_EMAIL_EDIT_TEMPL_OPT, nStrItemList);
    SetParentHandler(MENU_ID_EMAIL_EDIT_TEMPL_OPT);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_EMAIL_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_template_exec_write_email
 * DESCRIPTION
 *  Execute Template->Write Email, entry compose screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_template_exec_write_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *templ = NULL;
    U32 tmp_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_comp_reset_member();
    
    templ = email_p->templates[email_p->curr_template_index];

    if(templ != NULL)
    {
        tmp_len = mmi_ucs2strlen((S8*) templ);
            
        if (tmp_len)
        {
            if(tmp_len > EMAIL_MAX_CONT_LEN)
            {
                tmp_len = EMAIL_MAX_CONT_LEN;
            }
            mmi_ucs2ncpy(
                (S8*) email_p->comp_info.cont_buff,
                (S8*) templ,
                tmp_len);
        }
    }
    
    /* display compose screen */
    if (mmi_email_comp_add_sig() == FALSE)
    {
        return;
    }

    email_p->main_info.curr_menu = MMI_EMAIL_COMP;
    mmi_email_entry_comp();

    /*in order to back to Email main menu after send or save*/
    DeleteScreenIfPresent(SCR_ID_EMAIL_TEMPLATE_OPTION);
    DeleteScreenIfPresent(SCR_ID_EMAIL_TEMPLATE_LIST);
    
    /* release the template buffer */
    mmi_email_deinit_templates();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_entry_template_write_email
 * DESCRIPTION
 *  before Execute Template->Write Email,judge some condition to decide whether
 *  to entry compose screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_email_entry_template_write_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_email_prof_is_activated() == FALSE)
    {
        mmi_email_util_display_popup(
            (U8*) GetString(STR_EMAIL_ERROR_CODE_ACCT_NOT_CONFIG_ID),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) WARNING_TONE);
        return;
    }
    mmi_email_template_exec_write_email();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_highlight_save_template
 * DESCRIPTION
 *  Highlight save template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_highlight_save_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_save_template_query, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_goback_to_template_list_screen
 * DESCRIPTION
 *  save template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_goback_to_template_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ID_EMAIL_TEMPLATE_LIST);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_save_template_query
 * DESCRIPTION
 *  save template
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_save_template_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_email_display_confirm(STR_EMAIL_COMMON_SAVE_CHANGES_ID, mmi_email_save_template, mmi_email_goback_to_template_list_screen);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_highlight_erase_template
 * DESCRIPTION
 *  Highlight erase template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_highlight_erase_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_pre_erase_template, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_highlight_edit_template
 * DESCRIPTION
 *  Highlight edit template handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_highlight_edit_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_template_edit, KEY_EVENT_UP);     
    SetKeyHandler(mmi_email_entry_template_edit, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_highlight_template_write_email
 * DESCRIPTION
 *  Highlight template write email handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_highlight_template_write_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_template_write_email, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_template_write_email, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_email_hilite_use_template
 * DESCRIPTION
 *  Highlight handler of Use Template option in full screen editor of Write Email->Content
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_email_hilite_use_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_email_entry_template_list, KEY_EVENT_UP);
    SetKeyHandler(mmi_email_entry_template_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* defined(__MMI_EMAIL_TEMPLATE__) */


#endif /* __MMI_EMAIL__ */ 
#endif /* _MMI_EMAILAPPUIINTERFACE_C */
