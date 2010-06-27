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
*  Copyright Statement: *  -------------------- *  This software is protected by 
Copyright and the information contained *  herein is confidential. The software 
may not be copied and the information *  contained herein may not be used or 
disclosed except with the written *  permission of MediaTek Inc. (C) 2002 * 
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * EmailAppProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local enum, constant and prototypes for Email application
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
 *==============================================================================
 *******************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : EmailAppProt.h

   PURPOSE     : nil

   REMARKS     : nil

   AUTHOR      : Magesh k

   DATE     : 30-01-2004

**************************************************************/
#ifndef _MMI_EMAILAPPPROT_H
#define _MMI_EMAILAPPPROT_H

/*---------------------------------------------------------------------------*/
/* Header files */
/*---------------------------------------------------------------------------*/
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "email_mmi.h"
#include "wgui_categories.h"
#include "FrameworkStruct.h"
#include "MemPoolContainerProt.h"
#include "customer_ps_inc.h"
#include "DataAccountGProt.h"
#include "FileMgr.h"
#include "EmailAppGprot.h"
#include "app_mine.h"
#ifdef __MMI_EMAIL_OTAP__
#include "CentralConfigAgentGProt.h"
#endif /*__MMI_EMAIL_OTAP__*/

#include "App_usedetails.h"
#ifdef __MMI_EMAIL_DRM_SUPPORT__
#include "drm_gprot.h"
#endif

/*---------------------------------------------------------------------------*/
/* Definition */
/*---------------------------------------------------------------------------*/

/* Path Constants */
#define EMAIL_WORKING_PATH                         MMI_EMAIL_PATH
#define EMAIL_TEMP_FOLDER_NAME                     "EmailTmp\\"
#define EMAIL_TEMP_COMPOSE_FLDR_NAME               "EmailCompTmp\\"
#define EMAIL_READ_TMP_FILE_NAME                   "readattch"
#define EMAIL_COMP_TMP_FILE_NAME                   "compattch"
#define EMAIL_SIG_WORKING_PATH                     MMI_EMAIL_FILE_PATH
#define EMAIL_SIG_FILE_NAME                        "sig"

/* charset Constants */
#define EMAIL_UTF8_ENCODING_LENGTH                 3    /* as some of the chinese char's takes 3 bytes for single char */
#define EMAIL_CHSET_BUFF_LEN                       2048

/* Dynamic List Constants */
#define EMAIL_TOTAL_POOL                           ((MAX_ASYNCDYNAMIC_ITEMS_BUFF + MMI_EMAIL_MAX_MSG_PER_PAGE -1)/MMI_EMAIL_MAX_MSG_PER_PAGE)
#define EMAIL_TOTAL_MSG_BUFF                       ((EMAIL_TOTAL_POOL+1)*MMI_EMAIL_MAX_MSG_PER_PAGE)
#define EMAIL_MAX_DISP_ADDR_NUM                    6

/* Send N Recv Constants */
#define EMAIL_MAX_SNR_RESULT_LEN                   50

/* Folder Constants */
#define EMAIL_MAX_JUMP_PAGE_INPUT_LEN              4
#define EMAIL_MAX_FLDR_CAP_LEN                     24   /* "Draft [50/50]" */
#define EMAIL_MAX_DATE_TIME_STR_LEN                20   /* "2004/01/01 12:12:12" 20 characters + 1 NULL terminate */
#define EMAIL_MAX_SUBJ_DISPLAY_STR_LEN             (MMI_EMAIL_MAX_LEN_SHORT_SUBJECT/EMAIL_UTF8_ENCODING_LENGTH)    /* maximal length of subject to be displayed in folder list */
#define EMAIL_MAX_SIZE_STR_LEN                     10        /* 1023K */
#define EMAIL_MAX_FROM_STR_LEN                     18

/*Email common judgment*/
#define EMAIL_IS_PROT(x)                           ((email_p->prof_info.act_prof.in_prot == x) ? TRUE : FALSE)
#define EMAIL_IS_MENU(x)                           ((email_p->main_info.curr_menu == x) ? TRUE : FALSE)
#define EMAIL_IS_MODE(x)                           ((email_p->mode_status.curr_mode == x) ? TRUE : FALSE)

/* Write Email Constants */
#define EMAIL_MAX_PRIORITY_ITEM                    3
#define EMAIL_LEFT_OPER_LEN                        2    /* < */
#define EMAIL_RIGHT_OPER_LEN                       2    /* > */
#define EMAIL_THREE_DOTS_LEN                       4    /* ... */
#define EMAIL_ADDR_INLINE_BUFF_LEN                 (EMAIL_LEFT_OPER_LEN+EMAIL_RIGHT_OPER_LEN+EMAIL_PROF_DISP_NAME_LEN+MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS)
#define EMAIL_MAX_CONT_LEN                         600
#define EMAIL_COMP_SUBJ_LEN                        (MMI_EMAIL_MAX_LEN_SUBJECT/EMAIL_UTF8_ENCODING_LENGTH)

/* Profile Constants */
#define EMAIL_MAX_DWNL_LEN                         15
#define EMAIL_MAX_PROF_PORT_LEN                    5
#define EMAIL_PROF_SERVER_COPY_STATUS_ITEM         2
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
#define EMAIL_MAX_N_DAYS_LEN                       3       /* the max days n = 100 */
#endif 
#define EMAIL_PROF_DEL_SERVER_STATUS_ITEM          2
#define EMAIL_PROF_DOWNLOAD_OPTION_STATUS_ITEM_POP3      2
#define EMAIL_PROF_DOWNLOAD_OPTION_STATUS_ITEM_IMAP4     3
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
#define EMAIL_DEFAULT_N_DAYS                       10       /* 10 days as default */
#define EMAIL_MIN_DEL_AFTER_N_DAYS                 0        /* 0 indicate not to delete */
#define EMAIL_MAX_DEL_AFTER_N_DAYS                 100      /* 1-100, indicate delete after n days */
#endif /* __MMI_EMAIL_DEL_AFTER_N_DAYS__ */ 
#define EMAIL_PROF_SIG_STATUS_ITEM                 2
#define EMAIL_PROF_SIG_IMG_ITEM                    2
#define EMAIL_MAX_PROT_ITEM                        2
#define EMAIL_MAX_CHK_INTERVAL_ITEM                5
#define EMAIL_DEFAULT_SMTP_PORT                    25
#define EMAIL_DEFAULT_POP3_PORT                    110
#define EMAIL_DEFAULT_IMAP4_PORT                   143
#define EMAIL_MIN_PORT                             1
#define EMAIL_MAX_PORT                             65535
#define EMAIL_PROF_DISP_NAME_LEN                   (MMI_EMAIL_DISP_NAME_LEN/EMAIL_UTF8_ENCODING_LENGTH)
#define EMAIL_MAX_FLDR_NAME_LEN                    (MMI_EMAIL_MAX_FOLDER_NAME/EMAIL_UTF8_ENCODING_LENGTH)
#define EMAIL_MAX_SIG_LEN                          (MMI_EMAIL_MAX_SIG_TEXT/EMAIL_UTF8_ENCODING_LENGTH)
#define EMAIL_MAX_ACCT_NAME                        (MMI_EMAIL_ACCT_NAME_LEN/ENCODING_LENGTH)
#define EMAIL_PROF_AUTH_STATUS_ITEM                2
#define EMAIL_PROF_AUTH_SAME_STATUS_ITEM           2
#ifdef __MMI_EMAIL_TEMPLATE__
#define MMI_EMAIL_NUM_TEMPLATES                    10
#define MMI_EMAIL_MAX_TEMPLATE_LENGTH              40
#endif

/*---------------------------------------------------------------------------*/
/* Enum */
/*---------------------------------------------------------------------------*/
typedef enum
{
    EMAIL_NOT_READY = 0x00,
    EMAIL_PS_INIT_DONE = 0x01,
    EMAIL_CLEAR_BUFF_DONE = 0x02,
    EMAIL_READY = 0x03
} email_ready_state_enum;

typedef enum
{
    EMAIL_STOP = 0,
    EMAIL_START
} email_start_state_enum;

typedef enum
{
    EMAIL_FROM_MSG = 0, /* enter email from Message menu */
    EMAIL_FROM_APP      /* enter email from other applications */
} email_entry_source_enum;

typedef enum
{
    EMAIL_SEND_AND_RECEIVE_ENUM = 0,
    EMAIL_WRITE_EMAIL_ENUM,
    EMAIL_INBOX_ENUM,
    EMAIL_UNSENT_ENUM,
    EMAIL_SENT_ENUM,
    EMAIL_DRAFT_ENUM,
    EMAIL_DELETE_ALL_ENUM,
    EMAIL_DELETE_ALL_MARK_ENUM,
    EMAIL_EMAIL_PROFILE_ENUM,
#if defined(__MMI_EMAIL_TEMPLATE__)
    EMAIL_TEMPLATE_ENUM,
#endif /* defined(__MMI_EMAIL_TEMPLATE__) */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    EMAIL_SWITCH_MODE_ENUM,
    EMAIL_REFRESH_ENUM,
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    EMAIL_MAIN_MENU_TOTAL
} email_main_menu_enum;

/* email_folder_names_enum */
typedef enum
{
    MMI_EMAIL_INBOX = EMAIL_INBOX,      /* Inbox Folder */
    MMI_EMAIL_UNSENT = EMAIL_OUTBOX,    /* Outbox Folder */
    MMI_EMAIL_SENT = EMAIL_SENT,        /* Sent Folder */
    MMI_EMAIL_DRAFT = EMAIL_DRAFT,      /* Draft Folder */
    MMI_EMAIL_SNR,
    MMI_EMAIL_COMP,
    MMI_EMAIL_DEL_ALL,
    MMI_EMAIL_DEL_ALL_MARK,
    MMI_EMAIL_PROF,
#ifdef __MMI_EMAIL_TEMPLATE__
    MMI_EMAIL_TEMPLATE,
#endif /*__MMI_EMAIL_TEMPLATE__*/
    MMI_EMAIL_SWITCH,
    MMI_EMAIL_REFRESH,
    MMI_EMAIL_NONE
} email_ps_menu_enum;

typedef enum
{
    EMAIL_FLDR_INBOX = 0,
    EMAIL_FLDR_UNSENT,
    EMAIL_FLDR_SENT,
    EMAIL_FLDR_DRAFT,
    EMAIL_FLDR_TOTAL
} email_fldr_enum;

typedef enum
{
    EMAIL_COMP_TO = 0,
    EMAIL_COMP_CC,
#ifdef __MMI_EMAIL_BCC__
    EMAIL_COMP_BCC,
#endif 
    EMAIL_COMP_SUBJ,
    EMAIL_COMP_ATTCH,
    EMAIL_COMP_PRIOTRIY,
    EMAIL_COMP_CONT,
    EMAIL_COMP_TOTAL
} email_comp_inline_enum;

typedef enum
{
    EMAIL_ADDR_TO = 0,
    EMAIL_ADDR_CC,
#ifdef __MMI_EMAIL_BCC__
    EMAIL_ADDR_BCC,
#endif 
    EMAIL_ADDR_FROM,
    EMAIL_ADDR_NONE
} email_addr_type_enum;

typedef enum
{
    EMAIL_READ_FROM = 0,
    EMAIL_READ_TO,
    EMAIL_READ_CC,
#ifdef __MMI_EMAIL_BCC__
    EMAIL_READ_BCC, /* the following item should not change order */
#endif 
    EMAIL_READ_SUBJ,
    EMAIL_READ_ATTCH,
    EMAIL_READ_CONT,
    EMAIL_READ_TOTAL
} email_read_inline_item;

typedef enum
{
    EMAIL_DEL_ALL_INBOX_ENUM = 0,
    EMAIL_DEL_ALL_UNSENT_ENUM,
    EMAIL_DEL_ALL_SENT_ENUM,
    EMAIL_DEL_ALL_DRAFT_ENUM,
    EMAIL_DEL_ALL_FOLDER_ENUM,
    EMAIL_DELETE_ALL_OPTION_TOTAL
} email_del_all_item_enum;

typedef enum
{
    EMAIL_RESET_ALL_FLDR = 0,
    EAMIL_RESET_EXCEPT_UNSENT
} email_reset_fldr_enum;

typedef enum
{
    EMAIL_LIST_FLDR_NORMAL = 0,
    EMAIL_LIST_FLDR_REFRESH,
    EMAIL_LIST_FLDR_DEL_ALL,
    EMAIL_LIST_FLDR_DEL_ALL_MARK,
    EMAIL_LIST_FLDR_SWITCH,
    EMAIL_LIST_FLDR_PROF,
    EMAIL_LIST_FLDR_BACK_MAIN,  /* list folder because of back to main menu */
    EMAIL_LIST_FLDR_NONE        /* can be removed because not required */
} email_list_fldr_req_cause_enum;

typedef enum
{
    EMAIL_LIST_FLDR_REQUIRED = 0,   /* require, update */
    EMAIL_LIST_FLDR_NOT_REQUIRED,   /* not require, update */
    EMAIL_LIST_FLDR_DONE,           /* done, update */
    EMAIL_LIST_FLDR_NOT_DONE        /* not done, update */
} email_fldr_update_state_enum;

typedef enum
{
    EMAIL_SAVE_ATTACH_NO_ERR = 0,
    EMAIL_SAVE_ATTACH_DUP_NAME,     /* duplicated file name */
    EMAIL_SAVE_ATTACH_EMPTY_NAME,   /* empty file name */
    EMAIL_SAVE_ATTACH_NAME_TOO_LONG, /* file name too long */
    EMAIL_SAVE_ATTACH_DEL_ERROR,        /* delete file error */
    EMAIL_SAVE_ATTACH_NAME_INVALID      /* invalid file name */
} email_save_attch_state_enum;

typedef enum
{
    EMAIL_SNR_IDLE = 0,     /* send and receive is in Idle(Finished) state */
    EMAIL_SNR_CONN_SMTP,    /* connecting SMTP server */
    EMAIL_SNR_SENDING,      /* sending mail */
    EMAIL_SNR_CONN_POP3,    /* connecting POP3 server */
    EMAIL_SNR_AUTH,         /* authorization */
    EMAIL_SNR_RECVING,      /* receiving mail */
    EMAIL_SNR_ABORTING,
    EMAIL_SNR_ABORTED       /* send and receive is ABORTED state */
} email_snr_state_enum;

typedef enum
{
    EMAIL_REPORT_SENT_CAP = 0,
    EMAIL_REPORT_SENT,
    EMAIL_REPORT_RECV_CAP,
    EMAIL_REPORT_RECV,
    EMAIL_REPORT_TOTAL_ITEM
} email_snr_report_item_enum;

typedef enum
{
    EMAIL_FILE_ADD_ATTCH = 0,
    EMAIL_FILE_ADD_SIG,
    EMAIL_FILE_FROM_APP
} email_file_cpy_enum;

typedef enum
{
    EMAIL_JUMP_PAGE_CAP = 0,
    EMAIL_JUMP_PAGE,
    EMAIL_JUMP_PAGE_TOTAL_ITEM
} email_jump_page_item_enum;

#define PROF_ENUM_DEF
typedef enum
{
    EMAIL_PROF_SETTING = 0,
    EMAIL_PROF_SMTP,
    EMAIL_PROF_POP3_IMAP4,
    EMAIL_PROF_SIG,
    EMAIL_PROF_TOTAL
} email_prof_scr_enum;

typedef enum
{
    EMAIL_SETTING_NAME_CAP = 0,
    EMAIL_SETTING_NAME,
    EMAIL_SETTING_DATA_ACCT_CAP,
    EMAIL_SETTING_DATA_ACCT,
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    EMAIL_SETTING_PROTOCOL_CAP,
    EMAIL_SETTING_PROTOCOL,
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    EMAIL_SETTING_CHK_INT_CAP,
    EMAIL_SETTING_CHK_INT,
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
    EMAIL_SETTING_DWNL_SIZE_CAP,
    EMAIL_SETTING_DWNL_SIZE,
    EMAIL_SETTING_REPLY_TO_CAP,
    EMAIL_SETTING_REPLY_TO,
    EMAIL_SETTING_TOTAL_ITEM
} email_prof_setting_item_enum;

typedef enum
{
    EMAIL_SMTP_AUTH_SAME_CAP = 0,
    EMAIL_SMTP_AUTH_SAME,
    EMAIL_SMTP_USERNAME_CAP,
    EMAIL_SMTP_USERNAME,
    EMAIL_SMTP_PASSWD_CAP,
    EMAIL_SMTP_PASSWD,
    EMAIL_AUTH_TOTAL_ITEM
} email_prof_auth_item_enum;

typedef enum
{
    EMAIL_SMTP_OUT_SERVER_CAP = 0,
    EMAIL_SMTP_OUT_SERVER,
    EMAIL_SMTP_OUT_PORT_CAP,
    EMAIL_SMTP_OUT_PORT,
    EMAIL_SMTP_DISP_NAME_CAP,
    EMAIL_SMTP_DISP_NAME,
    EMAIL_SMTP_ADDR_CAP,
    EMAIL_SMTP_ADDR,
    EMAIL_SMTP_AUTH_CAP,
    EMAIL_SMTP_AUTH,
    EMAIL_SMTP_TOTAL_ITEM
} email_prof_smtp_item_enum;

typedef enum
{
    EMAIL_INCOMING_IN_SERVER_CAP = 0,
    EMAIL_INCOMING_IN_SERVER,
    EMAIL_INCOMING_IN_PORT_CAP,
    EMAIL_INCOMING_IN_PORT,
    EMAIL_INCOMING_USERNAME_CAP,
    EMAIL_INCOMING_USERNAME,
    EMAIL_INCOMING_PASSWD_CAP,
    EMAIL_INCOMING_PASSWD,
    EMAIL_INCOMING_DOWNLOAD_OPTION_CAP,
    EMAIL_INCOMING_DOWNLOAD_OPTION,
    EMAIL_INCOMING_TOTAL_ITEM
} email_prof_incoming_item_enum;

typedef enum
{
    EMAIL_POP3_SERVER_COPY_CAP = EMAIL_INCOMING_TOTAL_ITEM,
    EMAIL_POP3_SERVER_COPY,
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    EMAIL_POP3_DEL_AFTER_N_DAYS_CAP,
    EMAIL_POP3_DEL_AFTER_N_DAYS,
#endif /* __MMI_EMAIL_DEL_AFTER_N_DAYS__ */ 
    EMAIL_POP3_DEL_SERVER_MAILS_CAP,
    EMAIL_POP3_DEL_SERVER_MAILS,
    EMAIL_POP3_TOTAL_ITEM
} email_prof_pop3_item_enum;

typedef enum
{
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    EMAIL_IMAP4_DRAFT_NAME_CAP = EMAIL_INCOMING_TOTAL_ITEM,
    EMAIL_IMAP4_DRAFT_NAME,
    EMAIL_IMAP4_SENT_NAME_CAP,
    EMAIL_IMAP4_SENT_NAME,
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    EMAIL_IMAP4_TOTAL_ITEM
} email_prof_imap4_item_enum;

typedef enum
{
    EMAIL_SIG_STATUS_CAP = 0,
    EMAIL_SIG_STATUS,
    EMAIL_SIG_IMAGE_CAP,
    EMAIL_SIG_IMAGE,
    EMAIL_SIG_TEXT_CAP,
    EMAIL_SIG_TEXT,
    EMAIL_SIG_TOTAL_ITEM
} email_prof_sig_item_enum;

typedef enum
{
    EMAIL_PROT_POP3 = 0,
    EMAIL_PROT_IMAP4
} email_in_prot_enum;

typedef enum
{
    EMAIL_DATA_ACCT_GSM = 0,
    EMAIL_DATA_ACCT_GPRS
} email_data_acct_type_enum;

typedef enum
{
    EMAIL_ATT_NOT = 0,
    EMAIL_ATT_CACHED,
    EMAIL_ATT_NOT_CACHED
} email_att_cache_status;

typedef enum
{
    EMAIL_DOWN_NONE = 0,
    EMAIL_DOWN_POP3,
    EMAIL_DOWN_IMAP4,
    EMAIL_DOWN_TEMP
} email_down_type;

typedef enum
{
    EMAIL_MODE_OFFLINE = 0,
    EMAIL_MODE_ONLINE,
    EMAIL_MODE_TOTAL
} email_mode_enum;

typedef enum
{
    EMAIL_SEL_NORMAL = 0,
    EMAIL_SEL_GET_REQ,
    EMAIL_SEL_GET_RSP,
    EMAIL_SEL_ABT_REQ,
    EMAIL_SEL_ABT_RSP,
    EMAIL_SEL_ABT_NOT
} email_msg_sel_flag_enum;

typedef enum
{
    EMAIL_LIST_NONE = 0,
    EMAIL_LIST_START,
    EMAIL_LIST_ABORT
} email_msg_list_enum;

typedef enum
{
    EMAIL_MS_UNREAD = 0,
    EMAIL_MS_READ,
    EMAIL_MS_DELETED,
    EMAIL_MS_UNDELETED
} mmi_email_mail_status;

typedef enum
{
    EMAIL_EXCEPT_NORMAL = 0x00,
    EMAIL_EXCEPT_CON_EXCEED = 0x01,
    EMAIL_EXCEPT_ATT_EXCEED = 0x02,
    EMAIL_EXCEPT_SIG_FAILED = 0x04
} email_except_popup_enum;

#ifdef __MMI_EMAIL_TEMPLATE__
typedef enum
{
    EMAIL_TEMPLATE_LANG_ENGLISH,
    EMAIL_TEMPLATE_LANG_SIMCHINESE,
    EMAIL_TEMPLATE_LANG_TRACHINESE
} email_template_lang_enum;
#endif /* __MMI_EMAIL_TEMPLATE__ */

/*--------------------------------------------------------------------------*/
/* Struct */
/*---------------------------------------------------------------------------*/
/* structure describes mapping between error cause and string id */
typedef struct
{
    S32 err_no;
    U16 str_id;
} mmi_email_err_string_struct;

typedef struct
{
    U8 *strBody1;
    U8 *strBody2;
    FuncPtr lskFuncPtr;
    FuncPtr rskFuncPtr;
    FuncPtr endFuncPtr;
    U16 strCaption;
    U16 imgCaption;
    U16 strLsk;
    U16 imgLsk;
    U16 strRsk;
    U16 imgRsk;
    U16 imgBody;
} mmi_email_progress_scr_struct;

#define MAIN_STRUCT_EMAIL
typedef struct
{
    U16 unread_mails;
    email_ready_state_enum ready_state; /* if email application ready */
    email_stop_cause_enum stop_cause;
    email_entry_source_enum entry_src;  /* entry source of Email application */
    email_ps_menu_enum curr_menu;       /* current selected menu, according to PS order */
    BOOL is_mem_full;
    BOOL is_uidl_full;
    U8 main_indx;                       /* highlight index in main menu according to menu order */
    BOOL is_acct_change;
} mmi_email_main_info_struct;

#define SNR_STRUCT_EMAIL
typedef struct
{
    U32 num_recv;   /* number of received mails */
    U32 num_sent;
    U32 num_to_be_sent;
    U32 num_to_be_recv;
    U16 sent_err_str;
    U16 recv_err_str;
    UI_character_type recv_buff[EMAIL_MAX_SNR_RESULT_LEN];
    UI_character_type sent_buff[EMAIL_MAX_SNR_RESULT_LEN];
    email_snr_state_enum snr_state;
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    BOOL is_auto_chk;
#endif /* !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__) */ 
} mmi_email_snr_info_struct;

typedef struct
{
    UI_character_type to_cc_mail[MMI_EMAIL_MAX_LEN_ADDR_LIST][(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
    UI_character_type to_cc_name[MMI_EMAIL_MAX_LEN_ADDR_LIST][EMAIL_PROF_DISP_NAME_LEN + 1];
    S8 num_addr;
} mmi_email_to_cc_struct;

typedef struct
{
    UI_character_type from_addr[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
    UI_character_type from_name[EMAIL_PROF_DISP_NAME_LEN + 1];
} mmi_email_from_struct;

typedef struct
{
    UI_character_type file_name[(FMGR_MAX_FILE_LEN + 1)];
    UI_character_type file_path[(FMGR_MAX_PATH_LEN + 1)];
    S32 ch_set;
    U8 attch_type;
    U8 attch_subtype;
    BOOL attch_present;
#ifdef __MMI_EMAIL_DRM_SUPPORT__
    email_drm_struct drm;
#endif
    email_att_cache_status attch_cached;
    S32 size;
} mmi_email_attch_info_struct;

typedef struct
{
    S32 priority_indx;
#ifdef __MMI_EMAIL_BCC__
    mmi_email_to_cc_struct addr_list[3];
#else 
    mmi_email_to_cc_struct addr_list[2];
#endif 
    mmi_email_attch_info_struct attch_list[MMI_EMAIL_MAX_NUM_ATTACH];
    wgui_inline_images_detail attch_icon[MMI_EMAIL_MAX_NUM_ATTACH];
    UI_character_type subj_buff[EMAIL_COMP_SUBJ_LEN + 1];
    UI_character_type cont_buff[EMAIL_MAX_CONT_LEN + 1];
    UI_character_type addr_input_buff[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
#ifdef __MMI_EMAIL_BCC__
    UI_character_type addr_disp_buff[3][EMAIL_ADDR_INLINE_BUFF_LEN + 1];
#else 
    UI_character_type addr_disp_buff[2][EMAIL_ADDR_INLINE_BUFF_LEN + 1];
#endif 
    UI_character_type from_addr[EMAIL_ADDR_INLINE_BUFF_LEN + 1];
    UI_character_type phb_addr[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
    UI_character_type phb_name[EMAIL_PROF_DISP_NAME_LEN + 1];

    email_addr_type_enum curr_addr_type;    /* current input address */
    U8 curr_inline_item;
    BOOL done_flag;
    email_except_popup_enum except_popup;
    BOOL new_addr;                          /* edit or add */
    U32 total_attch_size;                   /* total attachment size */
    U8 total_attch;
    U8 load_addr_done;                      /* finish loading address from phonebook */
} mmi_email_comp_info_struct;

typedef enum
{
    EMAIL_CONT_ADDR_PHONENUMBER = 0,
    EMAIL_CONT_ADDR_EMAIL,
    EMAIL_CONT_ADDR_URL,
    EMAIL_CONT_ADDR_NONE
} email_cont_addr_type_enum;

typedef struct
{
    mmi_email_comp_info_struct read_info;       /* variable to store information in Read Email screen */
    mmi_email_from_struct from_info;
    UI_character_type reply_to_addr[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
    S8 *attch_dest_path;                        /* destination file path info when saving attach */
    email_cont_addr_type_enum curr_cont_addr_type;
    applib_address_node_struct *cont_addr_list; /* addr list pointer to save address in content, UTF8 */
    U16 mmi_email_cont_addr_num;                /* 0~EMAIL_MAX_DISP_ADDR_NUM,number of address to be display */
    U8 **cont_addr_ucs2_buff;                   /* addr array pointer to save address in content, UCS2 */
    U16 read_err_msg;                           /* error string index for read email */
} mmi_email_inbox_info_struct;

#define PROF_STRUCT_EMAIL
/* Setting information */
typedef struct
{
    U32 data_acct;                                          /* data account */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    S32 in_prot;                                            /* incoming protocol */
#endif 
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    S32 chk_interval;                                       /* check interval */
#endif 
    UI_character_type prof_name[(EMAIL_MAX_ACCT_NAME + 1)]; /* profile name buffer */
    UI_character_type dwnl_size[(EMAIL_MAX_DWNL_LEN + 1)];  /* max download size buffer */
    UI_character_type reply_to[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
} mmi_email_prof_setting_struct;

/* SMTP information */
typedef struct
{
    UI_character_type out_server[(MMI_EMAIL_MAX_SERVER_NAME + 1)];
    UI_character_type out_port[(EMAIL_MAX_PROF_PORT_LEN + 1)];
    UI_character_type disp_name[EMAIL_PROF_DISP_NAME_LEN + 1];
    UI_character_type email_addr[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
    UI_character_type user_name[(MMI_EMAIL_USR_MAX_LEN + 1)];
    UI_character_type passwd[(MMI_EMAIL_PASS_MAX_LEN + 1)];
    U8 *auth_status[EMAIL_PROF_AUTH_STATUS_ITEM];
    S32 auth_flag;
    U8 *auth_same_status[EMAIL_PROF_AUTH_SAME_STATUS_ITEM];
    S32 auth_same_flag;
} mmi_email_prof_smtp_struct;

/* POP3/IMAP4 information */
typedef struct
{
    S32 copy_on_server;
#ifdef __MMI_EMAIL_DEL_AFTER_N_DAYS__
    UI_character_type del_after_n_days[(EMAIL_MAX_N_DAYS_LEN + 1)];
#endif 
    S32 del_server_mails;
    UI_character_type in_server[(MMI_EMAIL_MAX_SERVER_NAME + 1)];
    UI_character_type in_port[(EMAIL_MAX_PROF_PORT_LEN + 1)];
    UI_character_type user_name[(MMI_EMAIL_USR_MAX_LEN + 1)];
    UI_character_type passwd[(MMI_EMAIL_PASS_MAX_LEN + 1)];
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    UI_character_type sent_name[EMAIL_MAX_FLDR_NAME_LEN + 1];
    UI_character_type draft_name[EMAIL_MAX_FLDR_NAME_LEN + 1];
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    S32 download_opt;
} mmi_email_prof_pop3_imap4_struct;

/* signature information */
typedef struct
{
    S32 sig_status;
    UI_character_type img_name[(FMGR_MAX_FILE_LEN + 1)];
    UI_character_type sig_buff[(EMAIL_MAX_SIG_LEN + 1)];
    UI_character_type file_name[(FMGR_MAX_FILE_LEN + 1)];
    UI_character_type file_path[(FMGR_MAX_PATH_LEN + 1)];
} mmi_email_prof_sig_struct;

/* misc data for profile */
typedef struct
{
    /* inline selection items */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    U8 *prot_list[EMAIL_MAX_PROT_ITEM];
#endif 
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
    U8 *chk_interval[EMAIL_MAX_CHK_INTERVAL_ITEM];
#endif 
    U8 *copy_on_server[EMAIL_PROF_SERVER_COPY_STATUS_ITEM];
    U8 *del_server_mails[EMAIL_PROF_DEL_SERVER_STATUS_ITEM];
    U8 *sig_status_list[EMAIL_PROF_SIG_STATUS_ITEM];
    U8 *sig_img_list[EMAIL_PROF_SIG_IMG_ITEM];
    S32 curr_hilite_indx;   /* for SMTP to set highlight after warning */
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    S32 curr_prot;
#endif 
    S32 curr_data_acct;
    S32 sig_img_indx;
    U16 curr_scr;           /* screen index of current profile setting screen -- Setting/SMTP/POP3/SIG */
    UI_character_type acct_names[MMI_EMAIL_MAX_ACCTS][(EMAIL_MAX_ACCT_NAME + 1)];
    UI_character_type data_acct_name[(MAX_DATA_ACCOUNT_NAME_LEN + 1)];
    U8 data_acct_type;      /* type of data account */
    U8 curr_sel_prof;       /* current selected profile index */
    U8 is_sig_changed;
    U8 *download_opt[EMAIL_PROF_DOWNLOAD_OPTION_STATUS_ITEM_IMAP4];
} mmi_email_prof_misc_struct;

typedef struct
{
    mmi_email_prof_setting_struct setting_info;
    mmi_email_prof_smtp_struct smtp_info;
    mmi_email_prof_pop3_imap4_struct pop_imap_info;
    mmi_email_prof_sig_struct sig_info;
} mmi_email_prof_struct;

typedef struct
{
    UI_character_type sig_img[(FMGR_MAX_FILE_LEN + 1)];
    UI_character_type sig_buff[(EMAIL_MAX_SIG_LEN + 1)];
    UI_character_type email_addr[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    UI_character_type sent_name[(EMAIL_MAX_FLDR_NAME_LEN + 1)];
    UI_character_type draft_name[(EMAIL_MAX_FLDR_NAME_LEN + 1)];
    U8 in_prot;
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
    U8 act_indx;
    U8 sig_status;
} mmi_email_act_prof_struct;

typedef struct
{
    /* Profile */
    mmi_email_act_prof_struct act_prof;
    mmi_email_prof_misc_struct prof_misc;
    mmi_email_prof_struct editing_prof; /* profile information of email */
} mmi_email_prof_info_struct;

/* This Structure Lists the accounts for list request */
typedef struct
{
    U32 mail_uid;                                           /* Message number */
    UI_character_type addr_buff[(MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1)];
    UI_character_type subject[EMAIL_MAX_SUBJ_DISPLAY_STR_LEN + 1];      /* Subject */
    UI_character_type dt_buff[EMAIL_MAX_DATE_TIME_STR_LEN]; /* Date and Time */
    U8 attch_num;                                           /* total number of attachment present */
    U8 attch_type[MMI_EMAIL_MAX_NUM_ATTACH];                /* each attachment type */
    U8 attch_subtype[MMI_EMAIL_MAX_NUM_ATTACH];             /* can be removec , each attachment type */
    BOOL is_read;                                           /* Read Flag for  messages */
    U8 priority;
    UI_character_type size_buff[EMAIL_MAX_SIZE_STR_LEN];
    kal_bool delete_flag;
} mmi_email_mail_info_struct;

typedef struct
{
    mmi_email_progress_scr_struct progress_info;    /* information for a progress screen */
    U8 *priority_list[EMAIL_MAX_PRIORITY_ITEM];
    UI_character_type folder_cap_buff[EMAIL_MAX_FLDR_CAP_LEN];
    UI_character_type subj_inline_buff[EMAIL_COMP_SUBJ_LEN + 1];
    S8 cont_inline_buff[(EMAIL_MAX_CONT_LEN + 1) *EMAIL_UTF8_ENCODING_LENGTH];
    email_file_cpy_enum file_copy_state;            /* to indicate the source of attachment file */
    U8 curr_hilite_attch;                           /* to, cc, attachment list hilite index for Read/Write email screen */
    BOOL insert_hist;
    kal_bool folder_select_req;
    S8 *str_compose_size;
    BOOL set_flag_result;
    S32 temp_priority_indx;
    BOOL delete_req;
#ifdef __MMI_WLAN_FEATURES__
    BOOL is_wlan_valid;
#endif
} mmi_email_misc_info_struct;

typedef struct
{
    S8 *fileName;
    S8 *fileExt;
#ifdef __DRM_SUPPORT__
    email_drm_struct drm;
#endif /* __DRM_SUPPORT__ */
} mmi_email_fmgr_file_info_struct;

/* structure for other applications */
typedef struct
{
    S8 *fmgr_path;  /* file path from file manager to send an email */
    S8 *phb_name;   /* display name from phonebook to send an email */
    S8 *phb_email;  /* mail address from phonebook to send an email */
    S8 *conv_path;  /* file path after convert from file manager to send an email */
    BOOL is_short;  /* Convert the file name */

    mmi_email_app_send_param_struct app_param;
    email_app_send_param_fill_enum app_param_fill_flag; 
    mmi_email_fmgr_file_info_struct file_info;
} mmi_email_other_app_struct;

#define FOLDER_STRUCT_EMAIL
typedef struct
{
    S32 num_msgs;
    mmi_email_mail_info_struct mail_list[EMAIL_TOTAL_MSG_BUFF];
} mmi_email_fldr_list_info_struct;

typedef struct
{
    mmi_email_fldr_list_info_struct fldr_list;
    email_folder_info_struct fldr_data[EMAIL_FLDR_TOTAL];
    U32 curr_mail_uid;                              /* id of current mail */
    S32 curr_mail_indx;                             /* current highlighting index of a mail */
    U32 total_page;
    U32 curr_page;
    UI_character_type jump_page_buff[EMAIL_MAX_JUMP_PAGE_INPUT_LEN + 1];
    email_fldr_update_state_enum fldr_update_state; /* if update folder list request is required */
    email_list_fldr_req_cause_enum list_fldr_cause; /* cause to send list folder request */
    BOOL need_fldr_sel;                             /* if folder select request is required */
    BOOL is_list_updated;                           /* if the list is already updated, use for empty case of IMAP4 */
    BOOL is_list_displayed;                         /* is list is already displayed */
    email_msg_sel_flag_enum curr_sel_flag;
    email_msg_flag_enum curr_set_flag_req;
    kal_bool curr_delete_flag;
    kal_bool curr_unread_flag;
    kal_bool curr_msg_all;
    email_down_type is_part_download;
    kal_uint8 curr_total_txt;
    kal_uint8 curr_total_att;
    kal_uint8 curr_retrieve_indx;
    kal_uint8 curr_num_not_cached_txt;
    kal_uint8 curr_num_not_cached_att;
    kal_uint8 curr_part_mask[MMI_EMAIL_PART_MASK_SIZE];
    kal_uint8 curr_get_part_mask[MMI_EMAIL_PART_MASK_SIZE];
} mmi_email_fldr_info_struct;

typedef struct
{
    mem_pool_container_struct mem_container;
    S32 start_indx;
    S32 end_indx;
    S16 not_avail_pool; /* current pool index which data is not available */
} mmi_email_mem_pool_info_struct;

#define DEL_STRUCT_EMAIL
typedef struct
{
    /* Delete All */
    email_fldr_enum curr_del_fldr;  /* index of current deleting folder */
    BOOL del_all_fldr;              /* Delete All apply to all folders or single folder */
} mmi_email_del_info_struct;

typedef struct
{
    email_mode_enum curr_mode;
    email_mode_enum req_mode;
    /* U8 req_protocol; */
    kal_bool reset_mode;
    email_msg_list_enum start_req;
} mmi_email_mode_info_struct;

typedef struct
{
    mmi_email_main_info_struct main_info;   /* main information */

    mmi_email_snr_info_struct snr_info; /* Send and Receive */

    mmi_email_prof_info_struct prof_info;   /* Profile */

    mmi_email_comp_info_struct comp_info;   /* Write Email */

    mmi_email_inbox_info_struct inbox_info; /* Inbox */

    mmi_email_fldr_info_struct fldr_info;   /* folder common data */

    mmi_email_del_info_struct del_info; /* Delete All */

    mmi_email_misc_info_struct misc_info;   /* Misc data */

    mmi_email_other_app_struct other_app_info;  /* Data about other entry application */

    mmi_email_mem_pool_info_struct mem_pool_info;   /* Memory pool */

    UI_character_type comm_buff[FMGR_MAX_PATH_LEN + 1]; /* common string shared buffer */

    UI_character_type filename_buff[FMGR_MAX_FILE_LEN + 1]; /* common filename shared buffer */

    UI_character_type save_name_buff[FMGR_MAX_FILE_LEN + 1];    /* common save filename shared buffer */

    UI_character_type fileext_buff[(FMGR_MAX_FILE_LEN + 1)]; /* common filename extension shared buffer */

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
    mmi_email_mode_info_struct mode_status;
#endif 

    email_msg_info_struct compose_size;

#ifdef __MMI_EMAIL_TEMPLATE__
    S8 *templates[MMI_EMAIL_NUM_TEMPLATES];
    S8 scratch_templ_rec[NVRAM_EMAIL_TEMPL_RECORD_SIZE + ENCODING_LENGTH];
    S32 curr_template_index;
#endif /* __MMI_EMAIL_TEMPLATE__ */
} mmi_email_context_struct;


#ifdef __MMI_EMAIL_OTAP__
#define MMI_EMAIL_OTAP_MAX_PROFILE_NUM    MMI_EMAIL_MAX_ACCTS  /*the max number of combined profile*/

#define EMAIL_APPID_LEN  4  /*string len of "25", "110" or "143"*/
#define EMAIL_MAX_PROXY_ID_LEN  40  
/*
 * Email profile used during OTA provisioning to pass to PS.
 */
typedef struct
{
    U8 proxy_id[EMAIL_MAX_PROXY_ID_LEN + 1];                     /*CCA_NS_OMA_PROXY_ID*/
    U16 data_acct_id;                                         /*DATAACCTID*/

    /*indicate whether it is a valid node*/
    MMI_BOOL is_have_proxy_id;
    MMI_BOOL is_have_dataacctid;
} mmi_email_oma_proxy_struct;

typedef struct _mmi_email_oma_proxy_node
{
    mmi_email_oma_proxy_struct proxy_parms;
    struct _mmi_email_oma_proxy_node *next;
} mmi_email_oma_proxy_node;

typedef enum
{
    EMAIL_OTAP_APP_NONE,
    EMAIL_OTAP_APP_SMTP,
    EMAIL_OTAP_APP_POP3,
    EMAIL_OTAP_APP_IMAP4
} email_app_node_type_enum;

/*All the string from CCA is UTF8*/
typedef struct
{
    U8 app_id[EMAIL_APPID_LEN + 1];                                      /*APPID*/ 
    U8 prof_name[EMAIL_MAX_ACCT_NAME * ENCODING_LENGTH + ENCODING_LENGTH];             /*NAME, save as UCS2*/
    U8 provider_id[EMAIL_MAX_ACCT_NAME * ENCODING_LENGTH + ENCODING_LENGTH];           /*PROVIDER-ID*/
    U8 to_proxy[EMAIL_MAX_PROXY_ID_LEN + 1];                             /*CCA_NS_OMA_TO_PROXY*/
    U8 from[EMAIL_ADDR_INLINE_BUFF_LEN * ENCODING_LENGTH + ENCODING_LENGTH];          /*FROM*/
    U8 from_name[EMAIL_PROF_DISP_NAME_LEN * EMAIL_UTF8_ENCODING_LENGTH + 1];          /*nick name after split from*/
    U8 from_addr[MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS * ENCODING_LENGTH + ENCODING_LENGTH];   /*email address after split from*/
    U8 rt_addr[MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS * ENCODING_LENGTH + ENCODING_LENGTH];   /*RT-ADDDR*/
    U8 server_addr[MMI_EMAIL_MAX_SERVER_NAME * ENCODING_LENGTH + ENCODING_LENGTH];     /*ADDR*/
    U16 server_addr_type;                                             /* ADDRTYPE*/
    U8 port_nbr[EMAIL_MAX_PROF_PORT_LEN * ENCODING_LENGTH + ENCODING_LENGTH];          /*PORTNBR*/
    U16 service;                                                    /* SERVICE*/
    U16 auth_type;                                                   /* AAUTHTYPE*/
    U8  username[MMI_EMAIL_USR_MAX_LEN * ENCODING_LENGTH + ENCODING_LENGTH];                            /*AAUTHNAME*/
    U8  password[MMI_EMAIL_PASS_MAX_LEN * ENCODING_LENGTH + ENCODING_LENGTH];                           /*AAUTHSECRET*/

    email_app_node_type_enum app_type;
    
    /*indicate whether it is a valid node*/
    MMI_BOOL is_valid_node;
} mmi_email_oma_application_struct;

typedef struct
{
    U8 prof_name_combined[EMAIL_MAX_ACCT_NAME * ENCODING_LENGTH + ENCODING_LENGTH]; /*convert UTF8 to UCS2 to save to this buffer,profile name after combined*/
    U16 data_acct_id;
    mmi_email_oma_application_struct *smtp_node;
    mmi_email_oma_application_struct *pop3_imap4_node;
    
    U8 to_proxy_combined[EMAIL_MAX_PROXY_ID_LEN + 1];             /*CCA_NS_OMA_TO_PROXY*/
    U8 in_protocol_type;                                          /*POP3 or IMAP4*/
    /*indicate the Profile have what information*/
    MMI_BOOL is_have_dataacctid;
    MMI_BOOL is_have_smtp;
    MMI_BOOL is_have_pop3_imap4;

    /*indicate whether it is a valid profile*/
    MMI_BOOL is_valid_profile;
    cca_status_enum cca_prof_status; /*each profile's status*/
} mmi_email_oma_profile_struct;

typedef struct
{
    U16 conf_id;                        /* Configuration ID                  */
    S32 doc_hdl;                        /* Configuration document handle     */   
    U8 num_profiles;                    /* Num of existed profile, have malloc space*/
    U8 profile_index;                   /* index of profile, after install or skip a profile, profile_index++*/
    mmi_email_oma_application_struct *curr_node; /*no space will malloc, just point to other node*/
    
    mmi_email_oma_proxy_node *proxy_linklist;
    mmi_email_oma_application_struct *tmp_app_node;
    /* Storage for incoming profiles. */
    mmi_email_oma_profile_struct *profile[MMI_EMAIL_OTAP_MAX_PROFILE_NUM];

    cca_status_enum cca_status; /*status to response to CCA*/
    U16 sim_id; /* for_generating_dataaccount */
} mmi_email_otap_struct;

/*
 * Converted symbols used to define CCA namespace mapping table.
 */
typedef enum
{
    EMAIL_OTAP_NS_PROXY,
    EMAIL_OTAP_NS_APPLICATION,
    EMAIL_OTAP_NS_APPADDR,
    EMAIL_OTAP_NS_APPAUTH
} email_otap_symbol_enum;
#endif /*__MMI_EMAIL_OTAP__*/


/*---------------------------------------------------------------------------*/
/* Variables */
/*---------------------------------------------------------------------------*/
extern mmi_email_context_struct *email_p;
extern const U8 g_email_subj_left_op[];
extern const U8 g_email_subj_right_op[];
extern const U8 g_email_3dots[];

/*---------------------------------------------------------------------------*/
/* Prototypes */
/*---------------------------------------------------------------------------*/

extern void mmi_email_init_hilite_hdlr(void);
extern void mmi_email_init_protocol_hdlr(void);

extern BOOL mmi_email_is_offline_notifier(void);
extern void mmi_email_offline_notifier(void);

#define HILITE_EMAIL_DEF
extern void mmi_email_hilite_snr(void);
extern void mmi_email_hilite_comp(void);
extern void mmi_email_hilite_inbox(void);
extern void mmi_email_hilite_sent(void);
extern void mmi_email_hilite_unsent(void);
extern void mmi_email_hilite_draft(void);
extern void mmi_email_hilite_del_all(void);
extern void mmi_email_hilite_del_all_mark(void);
extern void mmi_email_hilite_prof(void);
extern void mmi_email_hilite_refresh(void);

#define MAIN_MENU_EMAIL_DEF
extern void mmi_email_main_pre_entry(void);
extern void mmi_email_main_back_from_history(void);

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
extern void mmi_email_main_imap4_confirm_yes(void);
#endif 
extern void mmi_email_main_no_list_fldr(void);
extern void mmi_email_main_start(void);
extern void mmi_email_entry_main(void);
extern void mmi_email_exit_main_menu(void);
extern U8 mmi_email_main_del_callback(void *param);
extern void mmi_email_main_get_menu_detail(U8 **strList, U16 *iconList, U8 **hintList);
extern void mmi_email_hilite_main_menu_item(S32 index);
extern void mmi_email_main_quit_email(void);
extern void mmi_email_main_exec_lsk(void);
extern void mmi_email_main_update_hint(S8 fldr_name);
extern void mmi_email_main_quit_to_app(void);
extern void mmi_email_main_quit_to_app_ext(void);

#define SEND_N_RECV_DEF
extern void mmi_email_entry_snr_detail(void);
extern void mmi_email_exit_snr_detail(void);
extern void mmi_email_snr_back_from_result(void);
extern void mmi_email_snr_fill_inline_struct(void);

#define WRITER_EMAIL
extern void mmi_email_hilite_comp_addr_add(void);
extern void mmi_email_hilite_comp_addr_edit(void);
extern void mmi_email_hilite_comp_addr_del(void);
extern void mmi_email_hilite_comp_addr_del_all(void);
extern void mmi_email_hilite_comp_addr_done(void);
extern void mmi_email_hilite_comp_addr_input_meth(void);
extern void mmi_email_hilite_comp_subj_done(void);
extern void mmi_email_hilite_comp_subj_input_meth(void);
extern void mmi_email_hilite_comp_attach_edit(void);
extern void mmi_email_hilite_comp_attach_view(void);
extern void mmi_email_hilite_comp_attach_del(void);

extern void mmi_email_hilite_comp_send(void);
extern void mmi_email_hilite_comp_save_n_send(void);
extern void mmi_email_hilite_comp_save_to_draft(void);
extern void mmi_email_hilite_comp_quit(void);

extern BOOL mmi_email_comp_get_done_status(void);
extern void mmi_email_comp_pre_entry(void);
extern void mmi_email_entry_comp(void);
extern void mmi_email_exit_comp(void);
extern BOOL mmi_email_comp_add_sig(void);
extern void mmi_email_comp_reset_member(void);
extern void mmi_email_comp_fill_inline_struct(void);
extern void mmi_email_comp_inline_item_changer(S32 index);

extern void mmi_email_comp_back_to_hist(void);
extern void mmi_email_comp_change_rsk(void);
extern void mmi_email_compose_size_goback_history(void);
extern void mmi_email_comp_fill_attach(void);
extern void mmi_email_entry_comp_subj_opt(void);
extern void mmi_email_comp_subj_cont_done(void);

extern void mmi_email_comp_attach_lsk_func(PU8 image, UI_string_type str);
extern void mmi_email_comp_attach_rsk_func(PU8 image, UI_string_type str);
extern void mmi_email_hilite_comp_inline_item(S32 index);
extern void mmi_email_entry_comp_opt(void);
extern void mmi_email_comp_rsk_handler(void);

extern void mmi_email_comp_pre_entry_addr(void);
extern U16 mmi_email_comp_get_addr_opt_menu(void);
extern void mmi_email_entry_comp_addr(void);
extern void mmi_email_exit_comp_addr(void);
extern U16 mmi_email_comp_get_addr_info(U8 **nStrMainItemList, U8 **nStrPopupItemList);
extern void mmi_email_entry_comp_addr_opt(void);

extern void mmi_email_comp_addr_pre_edit(void);
extern void mmi_email_comp_addr_pre_add(void);
extern void mmi_email_entry_comp_addr_input(void);
extern void mmi_email_comp_addr_empty_lsk_hdlr(void);
extern void mmi_email_comp_addr_no_empty_lsk_hdlr(void);
extern void mmi_email_entry_comp_addr_input_opt(void);
extern void mmi_email_comp_addr_input_done(void);

extern void mmi_email_comp_addr_del(void);
extern void mmi_email_comp_addr_del_no(void);
extern void mmi_email_comp_addr_del_yes(void);
extern void mmi_email_comp_addr_hist_del(void);
extern void mmi_email_comp_addr_del_all(void);
extern void mmi_email_comp_addr_del_all_no(void);
extern void mmi_email_comp_addr_del_all_yes(void);
extern void mmi_email_comp_update_addr_buff(void);

extern void mmi_email_comp_add_attach(void);
extern void mmi_email_comp_add_attach_callback(void *info, int is_short);
extern void mmi_email_comp_attach_copy_callback(void *info);
extern void mmi_email_entry_comp_attch(void);
extern void mmi_email_hilite_comp_attch(S32 index);
extern void mmi_email_entry_comp_attch_opt(void);
extern void mmi_email_comp_attch_del(void);
extern void mmi_email_comp_attch_del_done(void);
extern void mmi_email_comp_pre_entry_view_attach(void);
extern void mmi_email_play_video_callback(S32 result);
extern void mmi_email_request_rights(void);
extern void mmi_email_view_exit(void);
extern void mmi_email_consume_callback(kal_int32 result, kal_int32 id);
extern void mmi_email_entry_comp_cont(void);
extern void mmi_email_exit_comp_cont(void);
extern void mmi_email_entry_comp_subj(void);
extern void mmi_email_comp_opt_quit(void);
extern void mmi_email_comp_opt_quit_yes(void);
extern S8 mmi_email_comp_is_addr_present(void);

#define INBOX_EMAIL_DEF
extern void mmi_email_hilite_read_addr_send(void);
extern void mmi_email_hilite_read_addr_save_phb(void);
extern void mmi_email_hilite_read_attach_view(void);
extern void mmi_email_hilite_read_attach_save(void);
extern void mmi_email_hilite_read_attach_save_done(void);
extern void mmi_email_hilite_read_attach_save_input_meth(void);

extern void mmi_email_hilite_inbox_reply(void);
extern void mmi_email_hilite_inbox_reply_without(void);
extern void mmi_email_hilite_inbox_reply_all(void);
extern void mmi_email_hilite_inbox_reply_all_without(void);

extern void mmi_email_hilite_read_retrieve_option(void);
extern void mmi_email_hilite_read_mark_deleted(void);
extern void mmi_email_hilite_read_mark_unread(void);
extern void mmi_email_hilite_read_forward(void);
extern void mmi_email_hilite_read_msg_del(void);

extern void mmi_email_hilite_read_extract(void);
extern void mmi_email_hilite_extract_phonenumber(void);
extern void mmi_email_hilite_extract_emailaddr(void);
extern void mmi_email_hilite_extract_webaddr(void);

extern void mmi_email_hilite_cont_addr_phonenumber_call(void);
extern void mmi_email_hilite_cont_addr_phonenumber_save_phb(void);
extern void mmi_email_hilite_cont_addr_email_send_email(void);
extern void mmi_email_hilite_cont_addr_email_save_phb(void);
extern void mmi_email_hilite_cont_addr_url_connect(void);
extern void mmi_email_hilite_cont_addr_url_add_bookmark(void);

#define FOLDER_EMAIL_DEF

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
extern void mmi_email_hilite_folder_read(void);
extern void mmi_email_hilite_fldr_next_page(void);
extern void mmi_email_hilite_fldr_prev_page(void);
extern void mmi_email_hilite_fldr_jump_to_page(void);
extern void mmi_email_fldr_jump_page_req(void);
extern void mmi_email_fldr_next_page_req(void);
extern void mmi_email_fldr_prev_page_req(void);
extern void mmi_email_fldr_fill_jump_inline_struct(void);
extern void mmi_email_fldr_pre_entry_jump_page(void);
extern void mmi_email_fldr_exec_jump_page(void);
extern void mmi_email_entry_jump_page(void);
extern void mmi_email_exit_jump_page(void);
#endif /* !defined(__MMI_SLIM_EMAIL_NO_IMAP4__) */ 
extern void mmi_email_entry_fldr_progress(void);
extern void mmi_email_exit_fldr_progress(void);
extern void mmi_email_fldr_back_from_history(void);
extern void mmi_email_fldr_pre_folder_select_req(void);

extern void mmi_email_fldr_pre_entry(void);
extern void mmi_email_entry_folder(void);
extern void mmi_email_exit_folder(void);
extern void mmi_email_hilite_folder_item(S32 index);
extern void mmi_email_folder_lsk_hdlr(void);
extern void mmi_email_folder_rsk_hdlr(void);
extern void mmi_email_entry_folder_opt(void);
extern void mmi_email_folder_update_mail_state(S32 index, mmi_email_mail_status status);
extern void mmi_email_folder_get_attch_icon(U8 attch_num, U8 *attch_type, U16 *attachImageList);
extern void mmi_email_fldr_update_page_num(void);
extern U16 mmi_email_folder_get_status_icon(U8 priority, BOOL is_read, kal_bool delete_flag);
extern S32 mmi_email_folder_get_async_items(S32 start_indx, gui_iconlist_menu_item *menuData, S32 dataSize);

#define READ_EMAIL_DEF

extern void mmi_email_entry_read(void);
extern void mmi_email_exit_read(void);
extern void mmi_email_read_fill_inline_struct(void);
extern void mmi_email_read_fill_attch_icon(S32 item_index);

extern void mmi_email_hilite_read_item(S32 index);
extern void mmi_email_read_attch_lsk(PU8 image, UI_string_type str);
extern void mmi_email_read_attch_rsk(PU8 image, UI_string_type str);
extern void mmi_email_entry_read_attch(void);
extern void mmi_email_exit_read_attch(void);
extern void mmi_email_hilite_read_attch(S32 index);
extern void mmi_email_hilite_read_attch_item(S32 index);
extern void mmi_email_entry_read_attch_opt(void);
extern void mmi_email_entry_read_attch_view(void);

extern void mmi_email_hilite_read_attach_download(S32 index);
extern void mmi_email_read_pre_entry_save_attch(void);
extern void mmi_email_entry_read_attch_save(void);
extern void mmi_email_entry_read_save_attch_opt(void);
extern void mmi_email_read_save_attch(void);
extern void mmi_email_replace_dupfile(void);
extern S8 mmi_email_read_copy_attch(S8 *attchName);

extern void mmi_email_read_goto_addr(void);
extern void mmi_email_read_cont_addr_phonenumber_call(void);
extern void mmi_email_read_cont_addr_phonenumber_call_ext(void);
extern void mmi_email_read_cont_addr_phonenumber_save(void);
extern void mmi_email_read_cont_addr_email_send_email(void);
extern void mmi_email_read_cont_addr_email_save(void);
extern void mmi_email_read_cont_addr_url_connect(void);
extern void mmi_email_read_cont_addr_url_add_bookmark(void);

extern void mmi_email_read_goto_cont_addr(void);
extern void mmi_email_entry_read_addr_phonenumber_opt(void);
extern void mmi_email_entry_read_addr_email_opt(void);
extern void mmi_email_entry_read_addr_url_opt(void);
extern void mmi_email_entry_read_addr_opt(void);

extern void mmi_email_entry_read_addr(void);

extern void mmi_email_pre_entry_read_cont_addr(void);
extern void mmi_email_entry_read_cont_addr(void);
extern void mmi_email_exit_read_cont_addr(void);
extern void mmi_email_read_cont_addr_release_buf(void);
extern void mmi_email_read_cont_addr_rsk_hdlr(void);
extern void mmi_email_exit_read_addr(void);
extern U16 mmi_email_read_get_addr_list(U8 **nStrMainItemList, U8 **nStrPopupItemList);
extern void mmi_email_entry_read_opt(void);

extern void mmi_email_inbox_reply(void);
extern void mmi_email_inbox_reply_without(void);
extern void mmi_email_inbox_reply_all(void);
extern void mmi_email_inbox_fill_reply_all_data(void);
extern void mmi_email_inbox_reply_all_without(void);
extern void mmi_email_read_forward(void);
extern void mmi_email_hilite_read_edit(void);

extern void mmi_email_read_extract(void);
extern void mmi_email_retrieve_option(void);
extern void mmi_email_hilite_retrieve_opt(S32 index);
extern void mmi_email_retrieve_opt_lsk(void);
extern S32 mmi_email_retrieve_opt_get_detail(U8 **str_list_item, U16 *item_icons, U8 **pop_up_item);
extern void mmi_email_read_attch_download(void);
extern void mmi_email_read_mark_deleted(void);
extern void mmi_email_read_mark_unread(void);
extern void mmi_email_read_addr_send(void);
extern void mmi_email_read_addr_save(void);
extern void mmi_email_read_attach_save(void);
extern void mmi_email_read_attch_sel_path_callback(void *filePath, int is_short);
extern void mmi_email_read_attch_copy_callback(void *info);
extern void mmi_email_fldr_prepare_forward(void);
extern void mmi_email_read_edit(void);

/* inbox */
#define INBOX_EMAIL_DEF
extern void mmi_email_entry_inbox_opt(void);
extern void mmi_email_inbox_hilite_option_items(S32 index);

/* sent */
#define SENT_EMAIL_DEF
extern void mmi_email_entry_sent_opt(void);
extern void mmi_email_sent_hilite_option_items(S32 index);

/* unsent */
#define UNSENT_EMAIL_DEF
extern void mmi_email_entry_unsent_opt(void);
extern void mmi_email_unsent_hilite_option_items(S32 index);
extern void mmi_email_unsent_send(void);
extern void mmi_email_unsent_save_n_send(void);
extern void mmi_email_fldr_prepare_edit(void);
extern void mmi_email_hilite_unsent_send(void);
extern void mmi_email_hilite_unsent_save_n_send(void);
extern void mmi_email_hilite_unsent_move(void);

#define DRAFT_EMAIL_DEF
extern void mmi_email_entry_draft_opt(void);
extern void mmi_email_draft_hilite_option_items(S32 index);

#define PS_FOLDER_EMAIL_DEF
extern BOOL mmi_email_fldr_is_list_ready(void);
extern void mmi_email_fldr_reset_list_info(void);
extern void mmi_email_fldr_reset_list_info_ex(void);
extern void mmi_email_fldr_exec_entry(void);
extern U16 mmi_email_fldr_get_start_scr(void);
extern S32 mmi_email_fldr_get_num_mails(void);

extern void mmi_email_fldr_get_msg_rsp_data(mmi_email_folder_msg_select_rsp_struct *msgRsp);
extern void mmi_email_fldr_get_msg_struct(email_msg_info_struct *emailMsg);
extern void mmi_email_fldr_get_msg_cont(U8 totalTextMsg, mmi_email_msg *textMsgList);
extern void mmi_email_fldr_get_msg_subj(U8 *out_buff, U8 *in_buff, U8 len, S32 charSet, BOOL truncate);
extern void mmi_email_fldr_get_msg_from(email_address_list *senderAddr);
extern void mmi_email_fldr_get_msg_addr(U8 total, U8 type);
extern void mmi_email_fldr_get_msg_prot(U8 priority);

extern void mmi_email_fldr_get_msg_part_mask(kal_uint8 *part_mask);
extern kal_bool mmi_email_fldr_is_part_all(void);
extern void mmi_email_fldr_get_msg_attch(U8 totalAttach, email_attach_struct *attachList);
extern S8 mmi_email_fldr_read_cont(S8 fileNo, S32 in_len, S32 ch_set, U8 **out_buff, U16 *out_len);
extern void mmi_email_fldr_exec_curr_rsp(U16 progrScrnId, FuncPtr entryFuncPtr, FuncPtr exitFuncPtr);
extern void mmi_email_fldr_sel_rsp_hdlr(mmi_email_folder_select_rsp_struct *msgRsp);
extern void mmi_email_fldr_enter_curr_list(void);
extern void mmi_email_fldr_reset_cntx(email_reset_fldr_enum resetFolderInfo);
extern void mmi_email_fldr_fill_addr_buff(U8 *appMailAddr, email_address_list *psMailAddrInfoStruct);

#define DELETE_EMAIL_DEF
extern void mmi_email_del_single_msg(void);
extern void mmi_email_del_single_msg_done(void);
extern void mmi_email_entry_del_all(void);
extern void mmi_email_exit_del_all(void);
extern void mmi_email_hilite_del_all_fldr(S32 index);
extern void mmi_email_del_all_get_menu_detail(U8 **nStrItemList, U16 *itemIcons, U8 **popUpList);
extern void mmi_email_del_all_folders(void);
extern void mmi_email_del_all_confirm(void);

/* Delete Mark */
extern void mmi_email_del_single_mark_msg(void);
extern void mmi_email_del_single_mark_msg_done(void);
extern void mmi_email_entry_del_all_mark(void);
extern void mmi_email_exit_del_all_mark(void);
extern void mmi_email_hilite_del_all_mark_fldr(S32 index);
extern void mmi_email_del_all_mark_get_menu_detail(U8 **nStrItemList, U16 *itemIcons, U8 **popUpList);
extern void mmi_email_del_all_mark_folders(void);
extern void mmi_email_del_all_mark_confirm(void);

#define PROF_EMAIL_DEF
/* main */
extern void mmi_email_entry_comm_full_edit_opt(void);
extern void mmi_email_entry_prof(void);
extern void mmi_email_entry_prof_opt(void);
extern void mmi_email_entry_prof_edit(void);
extern void mmi_email_prof_activate(void);
extern void mmi_email_prof_get_data(void);
extern void mmi_email_prof_save_confirm(void);
extern void mmi_email_hilite_prof_full_edit(void);
extern void mmi_email_hilite_prof_full_edit_ext(void);
extern void mmi_email_prof_go_back_to_edit_menu(void);
extern void mmi_email_prof_update_act_info(void);
extern void mmi_email_prof_fill_data(mmi_list_acct_struct *msgRsp);
extern void mmi_email_prof_go_back_to_main(void);

/* highlight handlers */
extern void mmi_email_hilite_prof_activate(void);
extern void mmi_email_hilite_prof_edit(void);
extern void mmi_email_hilite_prof_setting(void);
extern void mmi_email_hilite_prof_smtp(void);
extern void mmi_email_hilite_prof_pop3_impa4(void);
extern void mmi_email_hilite_prof_sig(void);
extern void mmi_email_hilite_prof_gprs(void);
extern void mmi_email_hilite_prof_csd(void);
extern void mmi_email_hilite_prof_done(void);
extern void mmi_email_hilite_prof_input_meth(void);
extern void mmi_email_hilite_prof_input_meth_ext(void);

/* profile setting */
extern void mmi_email_entry_prof_setting(void);
extern void mmi_email_exit_prof_setting(void);
extern void mmi_email_hilite_prof_setting_item(S32 index);
extern void mmi_email_prof_fill_setting_inline_struct(void);
extern void mmi_email_protocol_change_handler(S32 item_index);
extern void mmi_email_prof_save_setting(void);
extern void mmi_email_prof_data_acct_callback(U32 index);
extern void mmi_email_prof_list_data_acct(void);
extern void mmi_email_prof_save_data_acct(void);

/* smtp */
extern void mmi_email_entry_prof_smtp(void);
extern void mmi_email_exit_prof_smtp(void);
extern void mmi_email_prof_fill_smtp_inline_struct(void);
extern void mmi_email_prof_save_smtp(void);

/* pop3/imap4 */
extern void mmi_email_entry_prof_pop3_imap4(void);
extern void mmi_email_exit_prof_pop3_imap4(void);
extern void mmi_email_prof_fill_pop3_imap4_inline_struct(void);
extern void mmi_email_prof_save_pop3_imap4(void);

extern void mmi_email_pop3_copy_on_server_option_init(void);
extern void mmi_email_pop3_copy_on_server_option_handler(S32 item_index);

/* signature */
extern void mmi_email_prof_pre_entry_sig(void);
extern void mmi_email_entry_prof_sig(void);
extern void mmi_email_exit_prof_sig(void);
extern void mmi_email_prof_fill_sig_inline_struct(void);
extern void mmi_email_hilite_prof_sig_inline_sel(S32);
extern void mmi_email_prof_save_sig(void);
extern void mmi_email_prof_sig_save_file_callback(void *info);
extern void mmi_email_hilite_prof_sig_inline_item(S32 index);
extern void mmi_email_hilite_prof_sig_view(void);
extern void mmi_email_hilite_prof_sig_select(void);
extern void mmi_email_hilite_prof_sig_del(void);
extern void mmi_email_entry_prof_sig_sel_file(void);
extern void mmi_email_entry_prof_sig_view_attach(void);
extern void mmi_email_prof_sig_sel_attach(void);
extern void mmi_email_prof_sig_sel_attach_callback(void *filePath, int is_short);
extern void mmi_email_prof_sig_del_attach(void);
extern void mmi_email_prof_update_hint(void);
extern U8 mmi_email_prof_is_activated(void);

/* protocol part */
extern void mmi_email_prof_get_acct_data(mmi_acct_profile_struct *);
extern void mmi_email_prof_fill_act_info(mmi_acct_profile_struct *LocalData);
extern void mmi_email_hilite_prof_list(S32 index);
extern void mmi_email_prof_set_acct_data(mmi_email_set_acct_profile_req_struct *);

#define PS_EMAIL_DEF
/* general */
extern void mmi_email_ps_init_req(void);
extern void mmi_email_ps_deinit_req(void);
extern void mmi_email_ps_start_req(void);
extern void mmi_email_ps_start_rsp(void *inMsg);
extern void mmi_email_ps_mode_status_ready(void);
extern void mmi_email_ps_stop_req(void);
extern void mmi_email_ps_stop_rsp(void *inMsg);
#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
extern void mmi_email_ps_set_mode_req(void);
extern void mmi_email_ps_set_mode_rsp(void *inMsg);
#endif 
extern void mmi_email_ps_popup_callback(void);
extern void mmi_email_ps_popup_callback_ext(void);
extern void mmi_email_ps_abort_req(void);
extern void mmi_email_ps_abort_rsp(void *inMsg);
extern void mmi_email_ps_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

/* profile */
extern void mmi_email_ps_list_acct_profile_req(void);
extern void mmi_email_ps_list_acct_profile_rsp(void *inMsg);
extern void mmi_email_ps_dt_acct_callback(void);
extern void mmi_email_ps_set_acct_profile_req(void);
extern void mmi_email_ps_set_acct_profile_rsp(void *inMsg);
extern void mmi_email_ps_get_acct_profile_req(U8);
extern void mmi_email_ps_get_acct_profile_rsp(void *inMsg);
extern void mmi_email_ps_activate_acct_req(U8);
extern void mmi_email_ps_activate_acct_rsp(void *inMsg);
extern void mmi_email_ps_list_folders_req(void);
extern void mmi_email_ps_list_folders_rsp(void *inMsg);
extern void mmi_email_ps_get_csd_data_acct_req(U8);
extern void mmi_email_ps_get_csd_data_acct_rsp(void *);

#ifdef __MMI_GPRS_FEATURES__
extern void mmi_email_ps_get_gprs_data_acct_req(U8);
extern void mmi_email_ps_get_gprs_data_acct_rsp(void *);
#endif /* __MMI_GPRS_FEATURES__ */ 

extern void mmi_email_ps_snr_req(void);
extern void mmi_email_ps_snr_rsp(void *inMsg);
extern void mmi_email_ps_msg_available_ind(void *inMsg);
extern void mmi_email_ps_msg_full_ind(void *inMsg);
extern void mmi_email_ps_uidl_full_ind(void *inMsg);

extern void mmi_email_ps_compose_size_req(void);
extern void mmi_email_po_compose_size_rsp(void *msgRsp);
#if !defined(__MMI_SLIM_EMAIL_NO_AUTO_CHECK__)
extern void mmi_email_ps_auto_chk_ind(void *inMsg);
#endif 
extern void mmi_email_ps_server_conn_ind(void *inMsg);

extern void mmi_email_ps_msg_sent_ind(void *inMsg);
extern void mmi_email_ps_num_msgs_sent_ind(void *inMsg);
extern void mmi_email_ps_num_msgs_sent_ind(void *inMsg);
extern void mmi_email_ps_authverify_ind(void *inMsg);
extern void mmi_email_ps_recv_msgs_ind(void *inMsg);
extern void mmi_email_ps_new_msgs_ind(void *inMsg);

/* send/save */
extern void mmi_email_ps_compose_size_req(void);
extern void mmi_email_ps_compose_size_rsp(void *inMsg);
extern void mmi_email_ps_send_only_req(void);
extern void mmi_email_ps_send_only_rsp(void *inMsg);
extern void mmi_email_ps_save_and_send_req(void);
extern void mmi_email_ps_save_and_send_rsp(void *inMsg);
extern void mmi_email_ps_save_to_draft_req(void);
extern void mmi_email_ps_save_to_draft_rsp(void *inMsg);
extern void mmi_email_ps_move_to_draft_req(void);
extern void mmi_email_ps_move_to_draft_rsp(void *inMsg);
extern void mmi_email_ps_send_from_mailbox_req(BOOL needSave);
extern void mmi_email_ps_send_from_mailbox_rsp(void *inMsg);
extern void mmi_email_ps_folder_select_req(void);
extern void mmi_email_ps_folder_select_rsp(void *inMsg);
extern void mmi_email_ps_folder_msg_select_req(void);
extern void mmi_email_ps_folder_msg_select_rsp(void *inMsg);
extern void mmi_email_ps_folder_msg_mark_unread_req(void);
extern void mmi_email_ps_folder_msg_mark_del_req(void);
extern void mmi_email_ps_folder_msg_set_flag_rsp(void *inMsg);
extern void mmi_email_ps_folder_msg_del_req(void);
extern void mmi_email_ps_folder_msg_del_rsp(void *inMsg);
extern S32 mmi_email_ps_compose_fill_msg_struct(email_msg_info_struct *emailMsg);
extern S32 mmi_email_ps_compose_fill_addr(U8 *total, email_addr_type_enum type);
extern S32 mmi_email_ps_compose_fill_cont(U8 *totalTextMsg, mmi_email_msg *textMsgList);
extern S32 mmi_email_ps_compose_fill_attach(U8 *totalAttach, email_attach_struct *attachList);
extern void mmi_email_ps_compose_fill_priority(U8 *priority);
extern void mmi_email_ps_compose_fill_subj(U8 *subjectDataLen, U8 *subjectDataPtr, S32 *ch_set);

#define FMGR_EMAIL
extern S8 *mmi_email_get_file_ext(S8 *pFileName);
extern void mmi_email_fmgr_exec_send(void);
extern void mmi_email_fmgr_send_free(void);
extern BOOL mmi_email_send_file_check(S8 *filePath, BOOL is_short);

extern void mmi_email_send_from_phb(S8 *name, S8 *email);
extern void mmi_email_send_from_phb_done(void);

extern void mmi_email_entry_fldr_corrupt_mail(void);
extern void mmi_email_exit_fldr_corrupt_mail(void);

extern void mmi_email_pre_entry_progressing(
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
                FuncPtr endFuncPtr);
extern void mmi_email_display_confirm(U16 strId, FuncPtr lskFuncs, FuncPtr rskFuns);
extern void mmi_email_display_confirm_ex(void);
extern void mmi_email_entry_progressing(void);
extern void mmi_email_exit_progressing(void);

#define UTILITY_EMAIL_DEF
extern U8 *mmi_email_util_get_fldr_hint_value(U16 index, U8 folderSelectState);
extern U8 *mmi_email_util_get_hint_value_all_fldr(U16 index);
extern U8 *mmi_email_util_get_fldr_hint_mark_value(U16 index, U8 folderSelectState);
extern U8 *mmi_email_util_get_hint_mark_value_all_fldr(U16 index);

#if !defined(__MMI_SLIM_EMAIL_NO_IMAP4__)
extern U8 *mmi_email_util_get_mode_hint_value(void);
#endif 
extern void mmi_email_util_free_container_pool(void);
extern U16 mmi_email_util_get_err_string(S32 error);
extern void mmi_email_util_clear_end_key_hdlr(void);
extern void mmi_email_util_set_insert_history_flag(BOOL insert_hist);
extern void mmi_email_util_create_working_dir(void);
extern U16 mmi_email_util_get_fldr_scr_id(void);
extern U16 mmi_email_util_get_err_code(S32 minor, signed char major);
extern FuncPtr mmi_email_util_get_abort_func(void);

/* mine type */
extern void mmi_email_util_get_mine_type(S8 *filename, U8 *mime_type, U8 *mime_subtype);
extern S32 mmi_email_get_ext_by_type(S8 *file_ext, applib_mime_type_enum mime_type, applib_mime_subtype_enum mime_subtype);
extern U16 mmi_email_util_get_attch_icon(S8 *filepath);

extern U16 mmi_email_util_get_attch_icon_ex(U8 file_type);

/* display/screen */
extern void mmi_email_util_add_n_history(U16 scrnId, FuncPtr entryFuncPtr);
extern void mmi_email_util_add_history(U16 scrnId, FuncPtr entryFuncPtr);
extern void mmi_email_util_display_popup(
                U8 *string,
                U16 imageId,
                U8 imageOnBottom,
                U32 popupDuration,
                U8 toneId);
extern void mmi_email_util_display_popup_callback(
                U8 *string,
                U16 imageId,
                U8 imageOnBottom,
                U32 popupDuration,
                U8 toneId,
                FuncPtr f);
extern void mmi_email_util_display_err_popup(S32 minor, signed char major, U16 startDelScrnId, U16 endDelScrnId);
extern void mmi_email_util_exit_scr_by_err(void);
extern BOOL mmi_email_util_is_scrid_owned(U16 scr_id);
extern void mmi_email_util_del_between_scr(U16 start_scr, U16 end_scr);
extern void mmi_email_util_del_upto_scr(U16 end_scr);
extern void mmi_email_util_go_back_2_hist(void);
extern U8 mmi_email_util_is_call_interrupt_allow(void);
extern U8 *mmi_email_util_folder_select_cap_str(U16 strCaptionId);
extern void mmi_email_util_change_title(U16 strId);
extern U16 mmi_email_util_abort_str(void);
extern U16 mmi_email_util_abort_img(void);

/* string */
extern S32 mmi_email_util_get_chset(S32 src_chset);
extern U8 *mmi_email_util_chset_to_ucs2(U8 *data, U16 len, S32 format, U16 *outLen);
extern U8 *mmi_email_util_ucs2_to_chset(U8 *data, U16 len, S32 format, U16 *outLen);
extern S8 *mmi_email_util_ascii_2_ucs2_str(S8 *str);
extern S8 *mmi_email_util_num_2_ucs2_str(S8 num);
extern S32 mmi_email_util_get_num_len(U32 number);
extern BOOL mmi_email_util_chk_addr(U8 *mailAddr);
extern void mmi_email_util_get_cont_name(S8 fileNo, S8 *path_buff);
extern void mmi_email_util_get_attch_name(S8 fileNo, S8 *path_buff);
extern void mmi_email_util_get_comp_attch_name(S8 fileNo, S8 *path_buff);
extern void mmi_email_util_get_sig_name(S8 fileNo, S8 *path_buff);
extern void mmi_email_util_dt_to_str(S8 *appDateTime, email_date_time_struct *psDateTime);

extern void mmi_email_util_size_to_str(S8 *result, kal_uint32 size);
extern BOOL mmi_email_util_is_username_vaild(S8 *username);
extern BOOL mmi_email_util_correct_disp_name(UI_character_type *disp_name);
extern BOOL mmi_email_util_is_password_valid(S8 *password);
extern S8 mmi_email_uti_strnicmp(S8 *src, S8 *dest, S32 maxlen);

extern void mmi_email_util_update_status_icon(void);
extern void mmi_email_util_update_status_icon_ex(void);
extern U32 mmi_email_get_disk_free_blocks(void);
extern BOOL mmi_email_is_sim_valid(void);
extern BOOL mmi_email_bearer_status_show_icon_ex(BOOL check_usb);

/* file */
extern S32 mmi_email_util_get_file_size(S8 *filePathPtr, S32 *fileSizePtr);
extern S32 mmi_email_util_check_file_exist(S8 *filePathPtr);
extern S32 mmi_email_util_rename_attch(S8 fileNo, S8 *srcFilePathPtr);
extern void mmi_email_util_get_cont_size(U8 totalTextMsg, S32 *outContentDataSize);
extern void mmi_email_util_rename_default_to_read(void);
extern void mmi_email_util_rename_read_to_comp(void);
extern void mmi_email_util_rename_after_abort(S8 fileNo, S8 *DestFilePathPtr);
extern void mmi_email_util_rename_to_compose(void);
extern void mmi_email_util_del_file_in_folder(kal_wchar *filename, kal_wchar *fsearch);
extern void mmi_email_util_folder_init(MMI_BOOL is_check_comp);
extern void mmi_email_util_reset_file_attr(U16 *file_name);
#ifdef __MMI_EMAIL_DRM_SUPPORT__
extern BOOL mmi_email_drm_is_file_lock(PS8 file_name, BOOL *is_drm_file);
#endif

extern BOOL mmi_email_app_send_file_check(S8 *filePath, email_app_send_param_fill_enum mail_param_fill_flag);
extern void mmi_email_app_send_copy_addr(mmi_email_app_send_addr_struct *addr_param,
        mmi_email_app_send_addr_struct *addr_dest);
extern void mmi_email_app_send_copy_subj(S8 *subj);
extern void mmi_email_app_send_copy_cont(S8 *cont);
extern void mmi_email_app_send_copy_param(
        mmi_email_app_send_param_struct *mail_param,
        email_app_send_param_fill_enum mail_param_fill_flag);
extern void mmi_email_app_send_fill_addr(mmi_email_app_send_addr_struct *to_cc_addr,
        email_addr_type_enum addr_type);
extern void mmi_email_app_send_fill_prior(S32 priority);
extern void mmi_email_app_send_fill_data_except_attch(void);
extern BOOL mmi_email_app_check_send_addr(mmi_email_app_send_param_struct *mail_param);
extern void mmi_email_app_exec_send(void);
extern void mmi_email_app_send_free_mem(void);
extern void mmi_email_app_free_mem_n_back(void);

#ifdef __MMI_EMAIL_OTAP__
/*for otap*/
extern void mmi_email_otap_entry_prof(void);
extern void mmi_email_otap_prof_set_acct_data(mmi_email_set_acct_profile_req_struct *msgReq);
extern void mmi_email_next_profile(void);
extern void mmi_email_otap_prepare_for_deinit(void);
extern void mmi_email_otap_prof_update_act_info(void);
extern void mmi_email_exec_proc_cca_doc(U16 conf_id, S32 doc_hdl);
#endif /*__MMI_EMAIL_OTAP__*/

#if defined(__MMI_EMAIL_TEMPLATE__)
extern U8 mmi_email_init_templates(void);
extern void mmi_email_deInit_templates(void);
extern void mmi_email_load_templates_in_display_list(void);
extern void mmi_email_get_templates_to_edit(S8 *buffer, U32 index);
extern U8 mmi_email_delete_template(U32 index);
extern U8 mmi_email_store_template(U32 index);
extern U16 mmi_email_calc_template_base(void);
extern void mmi_email_get_template_index(S32 nIndex);
extern void mmi_email_deinit_templates(void);
#endif /* defined(__MMI_EMAIL_TEMPLATE__) */ 

/* For Reply_to */
extern void mmi_email_entry_prof_setting_reply_to(void);
extern void mmi_email_entry_prof_setting_reply_to_opt(void);
extern void mmi_email_hilite_prof_setting_reply_to_add_opt(void);
extern void mmi_email_entry_prof_setting_reply_to_search_in_phb(void);
extern void mmi_email_entry_prof_setting_reply_to_phb_get_addr_callback(S8 *name, S8 *email);
extern void mmi_email_hilite_prof_setting_reply_to_done_opt(void);
extern void mmi_email_save_prof_setting_reply_to(void);

extern BOOL mmi_email_util_is_server_vaild(S8 *server);
#endif /* _MMI_EMAILAPPPROT_H */

