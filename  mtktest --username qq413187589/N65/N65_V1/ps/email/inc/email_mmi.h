/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/ps/email/inc/email_mmi.h,v 1.1 2007/05/17 07:24:37 bw Exp $
*
* $Id: email_mmi.h,v 1.1 2007/05/17 07:24:37 bw Exp $
*
* $Date: 2007/05/17 07:24:37 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: email_mmi.h,v $
* Revision 1.1  2007/05/17 07:24:37  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
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
 * email_mmi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains MMI-EMail SAP definitions, including macros, 
 *   enum and structures.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _EMAIL_MMI_H
#define _EMAIL_MMI_H

extern kal_char email_sys_path[20]; /* eg, "c:\email\" */

#define MMI_EMAIL_PATH                       (const kal_char*)email_sys_path    /* Path of current directory */

#define MMI_EMAIL_KBYTE                     (1024)      /* One kilo byte value */
#define MMI_EMAIL_CHAR_LEN                  (2)

#define MMI_EMAIL_MAX_MSG_PER_PAGE          (5) /* Max number of messages */
#define MMI_EMAIL_MAX_ACCTS                 (3) /* Max number of accounts */
#define MMI_EMAIL_ACCT_NAME_LEN             (64)        /* Account name ength */

#define MMI_EMAIL_MAX_LEN_ADDR_LIST         (3) /* Maximum number of recipents */
#define MMI_EMAIL_DISP_NAME_LEN             (48)        /* Display name ength */

#define MMI_EMAIL_MAX_SERVER_NAME           (32)        /* Server name length */
#define MMI_EMAIL_MAX_SIG_TEXT              (150)       /* Signature text Size */

/*
 * NOTE: 
 * * this macro is better to sync with file manager's macro 
 * * in case APP uses file mgmr to obtain file name.
 */
#define MMI_EMAIL_MAX_FILE_NAME_LEN         (120)       /* length of absolute path */

#define MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS     (60)        /* Max length of address */
#define MMI_EMAIL_MAX_LEN_SUBJECT           (150)       /* Max length of subject */
#define MMI_EMAIL_MAX_LEN_SHORT_SUBJECT     (60)        /* Max length of subject for list */
#define MMI_EMAIL_USR_MAX_LEN               (64)        /* Max length of user name */
#define MMI_EMAIL_PASS_MAX_LEN              (16)        /* Max length of password */
#define MMI_EMAIL_MAX_FOLDER_MSG            (50)        /* Max number of messages in a folder */
#define MMI_EMAIL_MAX_NUM_ATTACH            (3) /* Max attachments */
#define MMI_EMAIL_SUB_TYPE_MAX_LEN          (30)
#define MMI_EMAIL_MAX_CHARSET_NAME_LEN      (83)        /* Maximum length of the charset field */
#define MMI_EMAIL_TOTAL_TEXT_MSGS           (2) /* Total Text Messages */
#define MMI_EMAIL_MAX_AUTOCHECK_TIMEOUT     (120)
#define MMI_EMAIL_MAX_FOLDER_NAME           (48)
#define MMI_EMAIL_MAX_TEXT_SRCH_LEN         (100)       /* Text length used in search criteria */

#define MMI_EMAIL_TEXT_FILE_NAME           "message"
#define MMI_EMAIL_ATTACH_FILE_NAME         "attach"
#define MMI_EMAIL_SIG_FILE_NAME             "sig"

/* Common compiler directives */
#define MMI_EMAIL_SIG_NONE       0      /* There is no signature. */
#define MMI_EMAIL_SIG_IS_TEXT          1        /* Signature is text */
#define MMI_EMAIL_SIG_IS_ATTACH        2        /* Signature is Attachment */
#define MMI_EMAIL_SIG_IS_TEXT_AND_ATTACH   3    /* Signature is Attachment */
#define MMI_EMAIL_PROTOCOL_POP3            0    /* Protocol POP3 */
#define MMI_EMAIL_PROTOCOL_IMAP4           1    /* Protocol IMAP4 */

#ifdef __POP3_LEAVE_COPY_ON_SERVER__
/* 
 * DO NOT change this value!!
 * This value shall be sync with Applib MD5's digest value 
 */
#define POP3_UIDL_DIGEST_LEN (16)
#endif /* __POP3_LEAVE_COPY_ON_SERVER__ */ 

/*
 * Actually, there are 5 priorities. But, we only support 3 priorities.
 * Thus MMI nees to map as following:
 *
 * 1,2 ==> high
 * 3  ==> normal
 * 4,5 ==> low
 *
 */
typedef enum
{
    MMI_EMAIL_HIGH_PRIORITY = 1,
    MMI_EMAIL_NORMAL_PRIORITY = 3,
    MMI_EMAIL_LOW_PRIORITY = 5
} mmi_email_priority_enum;

#if 0   /* use applib's MIME table */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/*
 * like following:
 * Subtype     File Ext. 
 * { "JPEG",   "jpg" }, // 1st entry 
 * { "GIF",    "gif" }, // 2nd entry
 * .....
 */

/* Error types */

/* Major Error types */
#define MMI_EMAIL_MAIL_ERR                -1    /* E-mail Related errors */
#define MMI_EMAIL_SOCKET_ERR        -2  /* Socket related errors */
#define MMI_EMAIL_FS_ERR         -3     /* File system related Errors */

/* 
 * Minor Error types
 */

#define MMI_EMAIL_ACCT_NOT_CONFIG              -1       /* Account not configured          */
#define MMI_EMAIL_INVALID_ACCT_INDEX           -2       /* Account Index does not exist    */
#define MMI_EMAIL_FOLDER_NOT_EXISTING          -3       /* Selected Folder is not existing */
#define MMI_EMAIL_MSG_NOT_EXISTING     -4       /* Folder message does not exist */
#define MMI_EMAIL_CONN_FAIL               -5    /* Sever connection failed */
#define MMI_EMAIL_AUTH_FAIL               -6    /* Authentication failed */
#define MMI_EMAIL_READ_ONLY_ACCESS             -7       /* Read only access of mailbox (IMAP)       */
#define MMI_EMAIL_MOVE_FAIL                    -8       /* Moving of message between folders failed */
#define MMI_EMAIL_NOT_SAVED                    -9       /* Message not saved on specified folder    */
#define MMI_EMAIL_PARTIAL_FETCH_FAIL           -10      /* Partial fetch failed                     */
#define MMI_EMAIL_SEARCH_FAIL                  -11      /* Searching of message in folder failed    */
#define MMI_EMAIL_SEARCH_LIST_FAIL             -12      /* Listing of searched messages failed      */
#define MMI_EMAIL_DNS_ERR                      -13      /* Error recieved during Gethostbyname call */
#define MMI_EMAIL_BAD_PAGE_NUMBER              -14      /* Page number does not exist               */
#define MMI_EMAIL_APP_SOC_TIMEOUT_ERR          -15      /* Error due to APP_SOC_NOTIFY_IND timeout  */
#define MMI_EMAIL_GET_HOST_TIMEOUT_ERR         -16      /* Error due to GET_HOST_BY_NAME_IND timeout */
#define MMI_EMAIL_POP3_MSG_XACTION_ERR         -17      /* Error during msg downloading from POP3 server */
#define MMI_EMAIL_POP3_SESSION_QUIT_ERR        -18      /* Error during session quiting from POP3 server */
#define MMI_EMAIL_INVALID_FOLDER_ID            -19      /* Folder ID supplied is invalid in current context */
#define MMI_EMAIL_MEMORY_ALLOC_FAIL            -20      /* Memory allocaltion failed */
#define MMI_EMAIL_SELECT_FOLDER_FAIL           -21      /* IMAP: Folder Selection failed */
#define MMI_EMAIL_MSG_SELECT_FAIL              -22      /* Message select failed */
#define MMI_EMAIL_NOOP_FAIL                    -23      /* noop fail for IMAP */
#define MMI_EMAIL_INVALID_DISP_NAME_LEN        -24      /* For Invalid Display Name len */
#define MMI_EMAIL_INVALID_EMAIL_ADDR_LEN       -25      /* For Invalid Email address len */
#define MMI_EMAIL_INVALID_USR_LEN              -26      /* For Invalid User Name Len */
#define MMI_EMAIL_INVALID_PASS_LEN             -27      /* For invalid password Len */
#define MMI_EMAIL_INVALID_PORT_NUM             -28      /* For Invalid Port Number */
#define MMI_EMAIL_INVALID_IP_ADDR              -29      /* For Invlaid IP address */
#define MMI_EMAIL_INVALID_ACCT_NAME_LEN        -30      /* For Invalid Account Name len */
#define MMI_EMAIL_INVALID_FILE_PATH            -31
#define MMI_EMAIL_INVALID_SERVER_NAME_LEN      -32
#define MMI_EMAIL_INVALID_SERVICE_TYPE         -33
#define MMI_EMAIL_INVALID_IN_PROTOCOL          -34
#define MMI_EMAIL_INVALID_CHK_INT              -35
#define MMI_EMAIL_INVALID_SIGNATURE_LEN        -36
#define MMI_EMAIL_POP3_FSM_ERR                 -37      /* Error to indicate the Illegal movement in POP3 FSM */
#define MMI_EMAIL_SMTP_VERSION_STATE_FAIL      -38
#define MMI_EMAIL_SMTP_MAIL_FROM_FAIL          -39
#define MMI_EMAIL_SMTP_GREET_FAIL              -40
#define MMI_EMAIL_NO_FROM_ADDRESS              -41
#define MMI_EMAIL_EXCEEDED_MSG_CNT             -42
#define MMI_EMAIL_MAIL_DATA_END_FAIL           -43
#define MMI_EMAIL_SMTP_RCPT_TO_FAIL            -44
#define MMI_EMAIL_SMTP_DATA_FAIL               -45
#define MMI_EMAIL_LIMITED_RESOURCE             -46
#define MMI_EMAIL_CANNOT_GET_LINE              -47
#define MMI_EMAIL_ERROR_MSG_REQ                -48
#define MMI_EMAIL_FILE_QUOTA_EXCEEDED          -49
#define MMI_EMAIL_IMAP_CLOSE_ERROR             -50      /* error CLOSE response from IMAP server */
#define MMI_EMAIL_IMAP_SELECT_ERROR            -51      /* error SELECT response from IMAP Server */
#define MMI_EMAIL_IMAP_FETCH_ERROR             -52      /* error FETCH response from IMAP Server */
#define MMI_EMAIL_IMAP_STORE_ERROR             -53      /* error STORE response from IMAP Server */
#define MMI_EMAIL_IMAP_COPY_ERROR              -54      /* error COPY response from IMAP Server */
#define MMI_EMAIL_IMAP_LOGOUT_FAIL             -55
#define MMI_EMAIL_INVALID_BODY_TYPE            -56
#define MMI_EMAIL_INVALID_BODY_ENCODING        -57
#define MMI_EMAIL_INVALID_MAIL_MESSAGE         -58
#define MMI_EMAIL_FOLDER_SELECT_NOT_PERMITTED  -59
#define MMI_EMAIL_SMTP_QUIT_FAIL               -60
#define MMI_EMAIL_INVALID_DOWNLOAD_SIZE        -61
#define MMI_EMAIL_INVALID_FOLDER_NAME_LEN      -62
#define MMI_EMAIL_STREAM_BUFFER_NOT_ENOUGH     -63
#define MMI_EMAIL_INVALID_CHARSET              -64
#define MMI_EMAIL_ABORT_FAIL                   -65      /* abort fail, still send some mails */
#define MMI_EMAIL_INVALID_SERVER_ADDR          -66      /* not a valid address */
#define MMI_EMAIL_SMTP_AUTH_FAIL               -67      /* authenticated fail */
#define MMI_EMAIL_SMTP_AUTH_NOT_SUPPORT        -68      /* authentication mechanism not supported */
#define MMI_EMAIL_UNSPECIFIED_ERROR            -100

typedef enum foldernames
{
    EMAIL_INBOX = 0,    /* Inbox Folder */
    EMAIL_OUTBOX,       /* Outbox Folder */
    EMAIL_SENT,         /* Sent Folder */
    EMAIL_DRAFT,        /* Draft Folder */
    EMAIL_ARCHIVE,      /* Archive Folder */
    MMI_EMAIL_MAX_FOLDERS,
    EMAIL_INVALID_FOLDER = MMI_EMAIL_MAX_FOLDERS
} email_folder_names_enum;

typedef enum
{
    EMAIL_ASCII,                    /* us-ascii */
    EMAIL_BIG5,                     /* big5 */
    EMAIL_GB,                       /* gb18030 */
    EMAIL_GB2312,                   /* gb2312 */
    EMAIL_UTF8,                     /* utf-8 */
    EMAIL_UTF7,                     /* utf-7 */
    EMAIL_ARABIC_ISO,               /* iso-8859-6 */
    EMAIL_ARABIC_WINDOWS,           /* windows-1256 */
//PMT START PERSIAN
    EMAIL_PERSIAN_CP1097,           /* cp-1097 */
    EMAIL_PERSIAN_CP1098,           /* cp-1098 */
//PMT END PERSIAN
    EMAIL_BALTIC_ISO,               /* iso-8859-13 */
    EMAIL_BALTIC_WINDOWS,           /* windows-1257 */
    EMAIL_CENTRAL_EUROPEAN_ISO,     /* iso-8859-2 */
    EMAIL_CENTRAL_EUROPEAN_WINDOWS, /* windows-1250 */
    EMAIL_GREEK_ISO,                /* iso-8859-7 */
    EMAIL_GREEK_WINDOWS,            /* windows-1253 */
    EMAIL_HEBREW_ISO,               /* iso-8859-8-i */
    EMAIL_HEBREW_WINDOWS,           /* windows-1255 */
    EMAIL_INDIA,                    /* ????? */
    EMAIL_LATIN_ISO,                /* iso-8859-15 */
    EMAIL_NORDIC_ISO,               /* iso-8859-10 */
    EMAIL_SOURTH_EUROPEAN_ISO,      /* iso-8859-3 */
    EMAIL_TURKISH_ISO,              /* iso-8859-9 */
    EMAIL_TURKISH_WINDOWS,          /* windows-1254 */
    EMAIL_WESTERN_ISO,              /* iso-8859-1 */
    EMAIL_WESTERN_WINDOWS,          /* windows-1252 */
    EMAIL_JAPAN,                    /* iso-2022-jp */
    EMAIL_KOREAN_EUC,               /* euc-kr */
    EMAIL_KOREAN,                   /* ks_c_5601-1987 */
    EMAIL_THAI,                     /* tis-620 */
    EMAIL_THAI_WINDOWS,             /* windows-874 */
    EMAIL_VIETNAMESE_WINDOWS,       /* windows-1258 */
    EMAIL_UNSPECIFIED_CHARSET,
    MMI_EMAIL_MAX_CHARSET           /* internal used by e-mail protocol entity */
} email_charset_enum;

/******************** Account Maintenance Data structures**********************/

/* This Structure Lists the accounts for list request */
typedef struct
{
    kal_int8 num_accts;                             /* Number of accounts */
    kal_int8 acct_name_len[MMI_EMAIL_MAX_ACCTS];    /* Account name length */
    kal_uint8 acct_names[MMI_EMAIL_MAX_ACCTS][MMI_EMAIL_ACCT_NAME_LEN]; /* Account name */
    kal_uint8 activated_acct_index;                 /* Activated account index (start from 1) */
    kal_uint8 reserved[3];                          /* Reserved bytes */
} mmi_list_acct_struct;

/* This structure is used to maintain the incoming or outgoing server's IP address and Port number */
typedef struct
{
    kal_uint16 port_number;                                 /* Port number */
    kal_uint8 server_name_len;                              /* not including null characer */
    kal_char server_name[MMI_EMAIL_MAX_SERVER_NAME + 1];    /* Server Name, null terminated */
    kal_uint8 bit_flag;                                     /* email_addr_bitflag_enum */
    kal_uint8 reserved[3];
} server_address_struct;

/* This Structure is used to maintain the login information(Username and Password) */
typedef struct
{
    kal_uint8 user_name_length;                     /* not including null characer  */
    kal_char user_name[MMI_EMAIL_USR_MAX_LEN + 1];  /* Username, null terminated */
    kal_uint8 pass_word_length;                     /* not including null characer */
    kal_char pass_word[MMI_EMAIL_PASS_MAX_LEN + 1]; /* Password, null terminated */
    kal_uint8 bit_flag;                             /* refer to email_login_bitflag_enum */
    kal_uint8 reserved[3];
} login_info_struct;

/* This structure is used to maintian the details about the POP3/IMAP information */
typedef struct
{
    kal_uint8 service_type;     /* data account id */
    kal_uint8 in_protocol;      /* POP3 (0) IMAP (1) */
    kal_uint8 check_interval;   /* Periodical check time of mails.(In minutes) */

    /* For IMAP, can allow user to configure draft / sent folder names */
    kal_char draft_name[MMI_EMAIL_MAX_FOLDER_NAME + 1]; /* null terminated */
    kal_uint8 draft_name_len;
    kal_char sent_name[MMI_EMAIL_MAX_FOLDER_NAME + 1];  /* null terminated */
    kal_uint8 sent_name_len;

    /* in range of MMI_EMAIL_MIN_MSG_SIZE ~ MMI_EMAIL_MAX_MSG_SIZE */
    kal_uint32 max_download_size;

    kal_bool leave_copy_on_server;  /* currently, not support */

    kal_uint16 bit_flag;    /* refer to email_in_bitflag_enum */

} imap_pop3_info_struct;

typedef struct
{
    email_charset_enum charset_attach;
    kal_uint8 mime_type;    /* refer to mmi_email_attachtype_enum */
    kal_uint8 mime_subtype; /* refer to email_mime_subtype_enum */

    kal_uint8 attach_path_len;  /* Contains the absolute path length */
    kal_char attach_file_name[MMI_EMAIL_MAX_FILE_NAME_LEN + 1]; /* Attachment file name, null terminated */

} email_attach_struct;

/* This structure is used to maintain the signature */
typedef struct
{
    kal_bool on_off;                            /* true: on, false: off */
    email_charset_enum charset_text;
    kal_uint8 signature_type;                   /* NONE/TEXT/ATTACHMENT/BOTH */
    kal_uint8 text_len;
    kal_char text[MMI_EMAIL_MAX_SIG_TEXT + 1];  /* Text string, null terminated */
    email_attach_struct attach;                 /* Attachment used as signature */

} signature_struct;

/* The informaiton in this structure is used while sending mail to recipient */
typedef struct
{
    email_charset_enum charset_disp_name;
    kal_uint8 disp_name_len;                            /* not including null character */
    kal_char display_name[MMI_EMAIL_DISP_NAME_LEN + 1]; /* null terminated */
    kal_uint8 email_addr_len;                           /* not including null character */
    kal_char email_address[MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1];        /* null terminated */
    signature_struct signature;                         /* text/attachment/both */

    login_info_struct login_info;   /* used for SMTP auth */
    kal_bool smtp_auth;             /* used for SMTP auth */

    kal_uint8 bit_flag; /* refer to email_out_bitflag_enum */
    kal_uint8 reserved[3];
} smtp_info_struct;

/* This structure is used while setting account profile information */
typedef struct
{
    imap_pop3_info_struct imap_pop3_info;   /* This is used by IMAP or PoP3 module */
    smtp_info_struct smtp_info;             /* SMTP information used by  SMTP module */
    login_info_struct login_info;           /* Login information used to authenticate the server */
    server_address_struct in_address;       /* In coming server address */
    server_address_struct out_address;      /* Out going server address */

    /*
     * Because account name is used locally, e-mail protocol use memory copy for this
     * * thus, the field is not end with null character.
     */
    kal_uint8 acct_name_len;                        /* Actual account name length */
    kal_uint8 acct_name[MMI_EMAIL_ACCT_NAME_LEN];   /* Account name */

    kal_uint8 bit_flag; /* refer to email_acct_bitflag_enum */
    kal_uint8 reserved[1];
} mmi_acct_profile_struct;

/************************* EMAIL information Data Structures *****************************/

typedef struct folder
{
    kal_uint32 num_unread_mails;    /* Number of unread mails */
    kal_bool status;                /* Status indicates folder is existing or not */
    kal_uint32 total_mails;
} email_folder_info_struct;

/* This structure is used to maintain Date and Time information */
typedef struct
{
    kal_uint32 year;    /* Year */
    kal_uint8 seconds;  /* Seconds */
    kal_uint8 minutes;  /* Minutes Field */
    kal_uint8 hours;    /* Hours Field */
    kal_uint8 day;      /* Day of month (1-31) */
    kal_uint8 month;    /* Month of year (1-12) */
    kal_uint8 zminutes; /* Zone Minutes */
    kal_uint8 zhours;   /* Zone Hours */
    kal_bool zind;      /* Zone indication */
} email_date_time_struct;

/* This structure is used to maintain the information related to E-mail Address list */
typedef struct
{
    email_charset_enum charset_disp;
    kal_uint8 disp_name_len;                            /* Actual display name length */
    kal_char display_name[MMI_EMAIL_DISP_NAME_LEN + 1]; /* Display Name, null terminated */
    kal_uint8 email_addr_len;
    kal_char email_address[MMI_EMAIL_MAX_LEN_EMAIL_ADDRESS + 1];        /* null terminated */
} email_address_list;

/* This structure is used to maintain the Folder message information */

typedef struct
{
    kal_uint32 email_msg_uid;                               /* Message number */
    kal_uint32 size;                                        /* Message size */
    kal_bool attach_flag;                                   /* Flag Denoting Attachment */
    kal_bool read_flag;                                     /* Read Flag for  messages */
    email_charset_enum charset_subject;
    email_date_time_struct send_date_time;                  /* Sent date and time */
    email_address_list sender_mail_address;                 /* Sender's Mail address */
    kal_uint8 subject_len;                                  /* Actual Subject length */
    kal_char subject[MMI_EMAIL_MAX_LEN_SHORT_SUBJECT + 1];  /* Subject, null terminated */
    kal_uint8 protocol;                                     /* Either POP3 (0) or IMAP (1) */
    kal_uint8 priority;

    kal_uint8 attachment_num;   /* Attachment count */

    /* exceeded attachment numbers, 
       keep count for which size exceed total size or individual size, or 
       attachment count exceeds total count */
    kal_uint8 remain_attachment_num;

    kal_uint8 mime_type[MMI_EMAIL_MAX_NUM_ATTACH];      /* refer to mmi_email_attachtype_enum */
    kal_uint8 mime_subtype[MMI_EMAIL_MAX_NUM_ATTACH];   /* refer to email_mime_subtype_enum */

} email_folder_msgs_info_struct;

/* This structure is used to maintain the charset related info and file path of a message */
typedef struct
{
    email_charset_enum charset_text;
    kal_uint8 mime_type;    /* refer to mmi_email_attachtype_enum */
    kal_uint8 mime_subtype; /* refer to email_mime_subtype_enum */

} mmi_email_msg;

/* This structure is used to represent the necessary details of the mail message */
typedef struct
{
    email_charset_enum charset_subject;
    email_address_list senders_address; /* Senders email address */
    kal_uint8 total_to_address;
    kal_uint8 total_cc_address;
    email_address_list to_address[MMI_EMAIL_MAX_LEN_ADDR_LIST]; /* Recipient address */
    email_address_list cc_address[MMI_EMAIL_MAX_LEN_ADDR_LIST]; /* Email address in cc */

#ifdef EMAIL_BCC
    kal_uint8 total_bcc_address;
    email_address_list bcc_address[MMI_EMAIL_MAX_LEN_ADDR_LIST];        /* Email address in cc */
#endif /* EMAIL_BCC */ 

    kal_uint8 total_text_msgs;                          /* Total number of text parts */
    mmi_email_msg text_msgs[MMI_EMAIL_TOTAL_TEXT_MSGS];
    kal_uint8 total_attachments;                        /* Total number of attachments */
    kal_uint8 protocol;                                 /* POP3 (0) or IMAP (1) */
    kal_uint8 subject_len;                              /* Actual subject length */
    kal_char subject[MMI_EMAIL_MAX_LEN_SUBJECT + 1];    /* Subject, null terminated */
    kal_uint8 priority;                                 /* Priority of the mail */
    kal_uint32 msg_uid;                                 /* Reply Message UID */
    email_attach_struct attach[MMI_EMAIL_MAX_NUM_ATTACH];
} email_msg_info_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/************* Data structures used between MMI and EMAIL ****************/

/* Initial List account profile Response structure */
typedef struct
{
    LOCAL_PARA_HDR mmi_list_acct_struct list_acct;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_list_acct_profile_rsp_struct;

/* Request structre for Set account profile */
typedef struct
{
    LOCAL_PARA_HDR mmi_acct_profile_struct acct;
    kal_uint8 acct_index;
} mmi_email_set_acct_profile_req_struct;

/* Response structre for Set account profile */
typedef struct
{
    LOCAL_PARA_HDR kal_bool config_status;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_set_acct_profile_rsp_struct;

/* Request structure for Getting account profile of specified account, with account profile index acct_index. */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 acct_index;
} mmi_email_get_acct_profile_req_struct;

/* Response structure for Getting the account profile information */
typedef struct
{
    LOCAL_PARA_HDR mmi_acct_profile_struct acct;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_get_acct_profile_rsp_struct;

/* Request for activating an account with account profile acct_index */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 acct_index;
} mmi_email_activate_acct_req_struct;

/* Response structure for activating the account profile */
typedef struct
{
    LOCAL_PARA_HDR mmi_acct_profile_struct acct;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_activate_acct_rsp_struct;

/* Request for deleting account profile */
typedef struct
{
    LOCAL_PARA_HDR kal_uint8 acct_index;    /* if acct_index = 255, Then Delete all account profiles */
} mmi_email_delete_acct_req_struct;

/* Response structure for deleting account profile */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_delete_acct_rsp_struct;

/* Response structure for listing of folders */
typedef struct
{
    LOCAL_PARA_HDR email_folder_info_struct folders[MMI_EMAIL_MAX_FOLDERS];
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_list_folders_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint32 total_mails;
    kal_uint32 sent_mails;
} mmi_email_msg_sent_ind_struct;

/* Response structure indicating the number of mails */
typedef struct
{
    LOCAL_PARA_HDR kal_uint32 total_mails;  /* 05242005: number of total mail(s) whch is going to be sent */
    kal_uint32 num_new_mails;               /* Number of new mails */
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_num_msgs_sent_ind_struct;

typedef mmi_email_num_msgs_sent_ind_struct mmi_email_num_msgs_ind_struct;

/* Email receive messages indication structure */
typedef struct
{
    LOCAL_PARA_HDR kal_uint32 total_mails;
    kal_uint32 received_mails;

    kal_uint32 num_exceeded_mails;
    kal_uint32 large_size_mails;    /* mail exceed max_download_size */

} mmi_email_recv_msgs_ind_struct;

/* Structure indicating Number of new mails */
typedef struct
{
    LOCAL_PARA_HDR kal_uint32 num_new_mails;    /* Number of downloaded mails */
    kal_uint32 total_mails;                     /* Number of downloadable mails */
    kal_uint32 num_exceeded_mails;
    kal_uint32 large_size_mails;                /* mail exceed max_download_size */

    kal_bool result;
    kal_int32 minor;
    kal_int8 major;

} mmi_email_new_msgs_ind_struct;

/* Folder Select request structure */
typedef struct
{
    LOCAL_PARA_HDR email_folder_names_enum folder;  /* Folder Name */
    kal_uint32 page_number;                         /* Page number requested */
} mmi_email_folder_select_req_struct;

/* Folder Select response Contains Number of pages in the folder */
typedef struct
{
    LOCAL_PARA_HDR email_folder_msgs_info_struct mmi_folder_msgs[MMI_EMAIL_MAX_MSG_PER_PAGE];
    kal_uint32 num_pages;   /* Number of pages available in the folder */
    kal_uint32 curr_page;
    kal_uint8 msgs_in_page;
    kal_uint32 total_num_msgs;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_folder_select_rsp_struct;

/* Request for selection of message */
typedef struct
{
    LOCAL_PARA_HDR email_folder_names_enum folder;
    kal_uint32 email_msg_uid;
} mmi_email_folder_msg_select_req_struct;

/* Response strucutre contains the actual mail message */
typedef struct
{
    LOCAL_PARA_HDR email_msg_info_struct email_msg;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_folder_msg_select_rsp_struct;

/* Request structure for deleting the messages */
typedef struct
{
    LOCAL_PARA_HDR email_folder_names_enum folder;
    kal_bool delete_all;
    kal_uint32 email_msg_uid;
} mmi_email_folder_msg_delete_req_struct;

/* Response structure for delete message */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_folder_msg_delete_rsp_struct;

/* Request structure for moving messages between folders */
typedef struct
{
    LOCAL_PARA_HDR email_folder_names_enum src_folder;  /* Source Folder Name */
    email_folder_names_enum dest_folder;                /* Destination Folder Name */
    kal_uint32 email_msg_uid;                           /* Message UID */
} mmi_email_msg_move_req_struct;

/* Response structre for message move */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_msg_move_rsp_struct;

/* Request structure for SEND Command to send a mail */
typedef struct
{
    LOCAL_PARA_HDR email_msg_info_struct email_msg;
} mmi_email_send_req_struct;

/* Response structure for SEND Command */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_send_rsp_struct;

/* Request structure for SEND NOW Command to send a mail */
typedef struct
{
    LOCAL_PARA_HDR email_msg_info_struct email_msg;
} mmi_email_send_now_req_struct;

/* Response structure for SEND NOW command */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
    kal_bool is_sent;
    kal_bool is_saved;
} mmi_email_send_now_rsp_struct;

/* Request structure for SEND ONLY Command to send a mail */
typedef struct
{
    LOCAL_PARA_HDR email_msg_info_struct email_msg;
} mmi_email_send_only_req_struct;

/* Response structure for SEND Command */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
    kal_bool is_sent;
    kal_bool is_saved;
} mmi_email_send_only_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 folder_id; /* Only Outbox & Draft */
    kal_uint32 email_msg_uid;
    kal_bool need_save;                 /* false: if send succ, mail will be deleted */
} mmi_email_send_from_mailbox_req_struct;

/* Response structure for SEND Command */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
    kal_bool is_sent;
    kal_bool is_saved;
} mmi_email_send_from_mailbox_rsp_struct;

/* Request structure for Saving messages to DRAFTS folder */
typedef struct
{
    LOCAL_PARA_HDR email_msg_info_struct email_msg;
} mmi_email_save_drafts_req_struct;

/* Response structure for saving messages to DRAFTS folder */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_save_drafts_rsp_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

/* Response structure for Abort request */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_abort_rsp_struct;

/* Response structre for init response */
typedef struct
{
    LOCAL_PARA_HDR kal_uint16 no_unread_inbox_msg;
    kal_bool config_activate;
    kal_uint8 in_protocol;
    kal_uint8 activated_acct_index;
    mmi_acct_profile_struct activated_acct;

    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_init_rsp_struct;

/* Response structre for deinit response */
typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_deinit_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_start_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_stop_rsp_struct;

/* Response structure for send and receive */
typedef struct
{
    LOCAL_PARA_HDR kal_uint32 num_new_mails;
    kal_bool result;
    kal_int32 minor;
    kal_int8 major;
} mmi_email_send_recv_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_int32 minor;
    kal_int8 major; /* FILE_ERROR-1, SOC_ERROR -2, EMAIL-3 */
} mmi_email_err_ind_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_list_acct_profile_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_list_folders_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_send_recv_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_abort_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_init_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_deinit_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_start_req_struct;

typedef struct
{
LOCAL_PARA_HDR} mmi_email_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_uint8 state; /* soc_auto_disc_state_enum (soc_api.h) */
    kal_uint8 bearer;               /* soc_bearer_enum (soc_api.h) */
    kal_uint8 ip_addr[4];           /* valid only when state is SOC_ACTIVATED */

    /* connection statistics, valid only when state is SOC_DEACTIVATED */
    kal_uint32 conn_time;   /* unit: secs */
    kal_uint32 sent_bytes;
    kal_uint32 recv_bytes;

} mmi_email_bearer_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result;

    /* valid only when result is TRUE */
    kal_uint32 conn_time;   /* unit: secs */
    kal_uint32 sent_bytes;
    kal_uint32 recv_bytes;

} mmi_email_deactivate_rsp_struct;

/*
 * ENUMs to indicate which fields in account structure are valid
 */
typedef enum
{
    EMAIL_ACCT_IN_FLAG = 0x01,
    EMAIL_ACCT_OUT_FLAG = 0x02,
    EMAIL_ACCT_LOGIN_FLAG = 0x04,
    EMAIL_ACCT_IN_ADDR_FLAG = 0x08,
    EMAIL_ACCT_OUT_ADDR_FLAG = 0x10,
    EMAIL_ACCT_NAME_LEN_FLAG = 0x20,
    EMAIL_ACCT_NAME_FLAG = 0X40
} email_acct_bitflag_enum;

typedef enum
{
    EMAIL_IN_SERVICE_TYPE_FLAG = 0x0001,
    EMAIL_IN_PROTO_FLAG = 0x0002,
    EMAIL_IN_CHECK_INTERVAL_FLAG = 0x0004,
    EMAIL_IN_DRAFT_NAME_FLAG = 0x0008,
    EMAIL_IN_DRAFT_NAME_LEN_FLAG = 0x0010,
    EMAIL_IN_SENT_NAME_FLAG = 0x0020,
    EMAIL_IN_SENT_NAME_LEN_FLAG = 0x0040,
    EMAIL_IN_MAX_SIZE_FLAG = 0x0080,
    EMAIL_IN_LEAVE_COPY_FLAG = 0x0100
} email_in_bitflag_enum;

typedef enum
{
    EMAIL_OUT_DISP_NAME_CHARSET_FLAG = 0x01,
    EMAIL_OUT_DISP_NAME_LEN_FLAG = 0x02,
    EMAIL_OUT_DISP_NAME_FLAG = 0x04,
    EMAIL_OUT_EMAIL_ADDR_LEN_FLAG = 0x08,
    EMAIL_OUT_EMAIL_ADDR_FLAG = 0x10,
    EMAIL_OUT_SIG_FLAG = 0x20,
    EMAIL_OUT_AUTH_FLAG = 0x40, /* SMTP auth */
    EMAIL_OUT_LOGIN_FLAG = 0x80 /* Login for SMTP auth */
} email_out_bitflag_enum;

typedef enum
{
    EMAIL_LOGIN_USER_LEN_FLAG = 0x01,
    EMAIL_LOGIN_USER_FLAG = 0x02,
    EMAIL_LOGIN_PASS_LEN_FLAG = 0x04,
    EMAIL_LOGIN_PASS_FLAG = 0x08
} email_login_bitflag_enum;

typedef enum
{
    EMAIL_ADDR_PORT_FLAG = 0x01,
    EMAIL_ADDR_SERVER_FLAG = 0x02,
    EMAIL_ADDR_SERVER_LEN_FLAG = 0x04
} email_addr_bitflag_enum;

#endif /* _EMAIL_MMI_H */ 

