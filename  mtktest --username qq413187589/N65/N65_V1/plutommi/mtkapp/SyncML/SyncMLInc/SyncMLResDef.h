/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   SyncMLResDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for SyncML resource definitions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SYNCML_RES_DEF_H__
#define __SYNCML_RES_DEF_H__

#include "MMIDataType.h"    /* for resource base */

/***************************************************************************** 
 * Typedef for Resource Enum
 *****************************************************************************/
/* Screen IDs */
typedef enum
{
    SCR_ID_SYNC_MAIN = SYNCML_BASE, /* sync menu */
    SCR_ID_SYNC_SETTINGS,
    SCR_ID_SYNC_PROFILE_SELECTION,
    SCR_ID_SYNC_PROFILE_OPTION,
    SCR_ID_SYNC_PROFILE_EDIT,
    SCR_ID_SYNC_PROFILE_NAME,
    SCR_ID_SYNC_PROFILE_NAME_OPTION,
    SCR_ID_SYNC_PROFILE_SERVER,
    SCR_ID_SYNC_PROFILE_CONTACT,
    SCR_ID_SYNC_PROFILE_CALENDAR,
    SCR_ID_SYNC_PROFILE_CONNECTION,
    SCR_ID_SYNC_PROFILE_PC,
    SCR_ID_SYNC_OTA_PROFILE_INSTALL,
    SCR_ID_SYNC_OTA_PROFILE_REPLACE,
    SCR_ID_SYNC_OTA_SKIP_CONFIRM,
    SCR_ID_SYNC_APPLICATIONS,
    SCR_ID_SYNC_REGULARITY,
    SCR_ID_SYNC_NOW, /* synchronizing... */
    SCR_ID_SYNC_ABORT,
    SCR_ID_SYNC_BACKGROUND_QUERY,
    SCR_ID_SYNC_ALARM_QUERY,
    SCR_ID_SYNC_TYPE,
    SCR_ID_SYNC_DELETE_ALL,
    SCR_ID_SYNC_REPORT,
    SCR_ID_SYNC_SAS_NOTIFICATION,
    SCR_ID_SYNC_END
} SYNCML_SCR_ID_ENUM;

/* String IDs */
typedef enum
{
    STR_ID_SYNC_MENU = SYNCML_BASE,    /* synchronization */
    STR_ID_SYNC_MENU_SHORT_FORM,       /* sync. */
    STR_ID_SYNC_NOW,                   /* menu item: sync now */
    STR_ID_SYNC_SETTINGS,              /* menu item: sync settings */
    STR_ID_SYNC_PROGRESS,              /* synchronizing... */
    STR_ID_SYNC_NO_PROFILE,            /* no profile! */
    STR_ID_SYNC_EDIT_QUREY,            /* edit profile now? */
    STR_ID_SYNC_PROFILE,               /* menu item: profile */
    STR_ID_SYNC_APPLICATIONS,          /* menu item: applications to sync */
    STR_ID_SYNC_REGULARITY,            /* menu item: regular sync */
    STR_ID_SYNC_PROFILE_NAME,          /* menu item: profile name */
    STR_ID_SYNC_PROFILE_SERVER,        /* menu item: server settings */
    STR_ID_SYNC_PROFILE_CONTACT,       /* menu item: contact database settings */
    STR_ID_SYNC_PROFILE_CALENDAR,      /* menu item: calendar database settings */
    STR_ID_SYNC_PROFILE_CONNECTION,    /* menu item: connection settings */
    STR_ID_SYNC_APP_PHB,               /* selection: phonebook */
    STR_ID_SYNC_APP_TDL,               /* selection: to do list */
    STR_ID_SYNC_APP_EMAIL,             /* selection: email */
    STR_ID_SYNC_REGULARITY_NONE,       /* selection: none */
    STR_ID_SYNC_REGULARITY_DATA,       /* selection: when data is changed */
    STR_ID_SYNC_REGULARITY_POWERON,    /* selection: when handset is turned on */
    STR_ID_SYNC_REGULARITY_DAY,        /* selection: every day */
    STR_ID_SYNC_REGULARITY_WEEK,       /* selection: every week */
    STR_ID_SYNC_REGULARITY_MONTH,      /* selection: every month */
    STR_ID_SYNC_SERVER_ADDRESS,
    STR_ID_SYNC_CONTACT_ADDRESS,
    STR_ID_SYNC_CALENDAR_ADDRESS,
    STR_ID_SYNC_BEARER,
    STR_ID_SYNC_BEARER_USB,            /* selection: data cable */
    STR_ID_SYNC_BEARER_BT,             /* selection: bluetooth */
    STR_ID_SYNC_BEARER_IRDA,           /* selection: irda */
    STR_ID_SYNC_TYPE,

    STR_ID_SYNC_HINT_PHB_ONLY,         /* 1 */
    STR_ID_SYNC_HINT_TDL_ONLY,         /* 2 */
    STR_ID_SYNC_HINT_PHB_TDL,          /* 3 */
    STR_ID_SYNC_HINT_EMAIL_ONLY,       /* 4 */
    STR_ID_SYNC_HINT_PHB_EMAIL,        /* 5 */
    STR_ID_SYNC_HINT_TDL_EMAIL,        /* 6 */
    STR_ID_SYNC_HINT_ALL_APP,          /* 7 */

    STR_ID_SYNC_PROXY_USAGE,           /* Use Proxy */
    STR_ID_SYNC_PROXY_SERVER,          /* Proxy IP */
    STR_ID_SYNC_PROXY_PORT,            /* Proxy Port */

    STR_ID_SYNC_PHB_BUSY,
    STR_ID_SYNC_INCOMPLETE_PROFILE,
    STR_ID_SYNC_NO_APPLICATION,        /* no application! */
    STR_ID_SYNC_BACKGROUND_QUERY,
    STR_ID_SYNC_PLEASE_WAIT,           /* synchronizing now, please wait... */
    STR_ID_SYNC_WAP_NOT_READY,

    STR_ID_SYNC_INVALID_CREDENTIAL,    /* 401: invalid credentials! */
    STR_ID_SYNC_MISSING_CREDENTIAL,    /* 407: missing credentials! */
    STR_ID_SYNC_PAYMENT_REQUIRED,      /* 402: payment required! */
    STR_ID_SYNC_DONE,                  /* 200: sync done */
    STR_ID_SYNC_FAIL,                  /* 500: sync unfinished\n(500).this is also used for all undefined error */ 
    STR_ID_SYNC_LOCALDB_FULL,          /* sync unfinished,\nLocal device full!*/
    STR_ID_SYNC_CODE_FORBIDDEN,        /* 403: synchronizing,\nretry later! */
    STR_ID_SYNC_INCOMPLETE_CMD,        /* 412: sync unfinished\n(412) */
    STR_ID_SYNC_SVR_DEVICE_FULL,       /* 420: sync unfinished,\nServer device full!*/
    STR_ID_SYNC_SERVICE_UNAVAILABLE,   /* 503: server busy,\nretry later! */
    STR_ID_SYNC_DATASTORE_FAIL,        /* 510: sync unfinished,\ncheck Data store setting!*/
    STR_ID_SYNC_SVR_FAIL,              /* 511: sync unfinished\n(511) */
    STR_ID_SYNC_ERR_OCCUR,             /* 512: sync unfinished\n(512) */
    STR_ID_SYNC_PROTOCOL_UNSUPPORT,    /* 513: sync unfinished\n(513)*/
	STR_ID_SYNC_DEFAULT_FAIL,          /* sync unfinished */

    STR_ID_SYNC_ALARM_EXPIRED_QUERY,
    STR_ID_SYNC_POWER_ON_QUERY,
    STR_ID_SYNC_DATA_CHANGED_QUERY,

    STR_ID_PROGRESS_LINK_ESTABLISHED,           /* "Connection Established" */
    STR_ID_PROGRESS_LINK_DISCONNECTED,          /* "Connection Disconnected" */
    STR_ID_PROGRESS_RX_FAILED,                  /* "Received Failed" */
    STR_ID_PROGRESS_TX_FAILED,                  /* "Transmit Failed" */
    STR_ID_PROGRESS_TASK_DATASTORE_SENDING,     /* "Sending Task Database Changes" */
    STR_ID_PROGRESS_CONTACT_DATASTORE_SENDING,  /* "Sending Contact Database Changes" */
    STR_ID_PROGRESS_TASK_DATASTORE_RECEIVED,    /* "Receiving Task Database Changes" */
    STR_ID_PROGRESS_CONTACT_DATASTORE_RECEIVED, /* "Receiving Contact Database Changes" */
    STR_ID_PROGRESS_TASK_DATASTORE_DONE,        /* "Task Databse Done" */
    STR_ID_PROGRESS_CONTACT_DATASTORE_DONE,     /* "Contact Databse Done" */
    STR_ID_PROGRESS_TASK_DATASTORE_FAILED,      /* "Task Database Failed" */
    STR_ID_PROGRESS_CONTACT_DATASTORE_FAILED,   /* "Contact Database Failed" */
    STR_ID_PROGRESS_LINK_REDIRECTED,            /* "URL Redirected" */
    STR_ID_PROGRESS_SESSION_DONE,               /* "Sync Session Done" */
    STR_ID_PROGRESS_TASK_DATASTORE_UPDATING,
    STR_ID_PROGRESS_CONTACT_DATASTORE_UPDATING,

    STR_ID_SYNC_TWOWAY,
    STR_ID_SYNC_BACKUP,
    STR_ID_SYNC_RESTORE,
    STR_ID_SYNC_EXPORT,
    STR_ID_SYNC_IMPORT,
    STR_ID_SYNC_BACKUP_WARNING,
    STR_ID_SYNC_RESTORE_WARNING,

    STR_ID_SYNC_REPORT,
    STR_ID_SYNC_REPORT_CON_OK,
    STR_ID_SYNC_REPORT_CAL_OK,
    STR_ID_SYNC_REPORT_CON_NG,
    STR_ID_SYNC_REPORT_CAL_NG,
    STR_ID_SYNC_REPORT_CON_CK,
    STR_ID_SYNC_REPORT_CAL_CK,
    STR_ID_SYNC_REPORT_CON_NO,
    STR_ID_SYNC_REPORT_CAL_NO,
    STR_ID_SYNC_REPORT_REPLACE,
    STR_ID_SYNC_REPORT_SERVER,
    STR_ID_SYNC_REPORT_CLIENT,

    STR_ID_SYNC_ERROR_PROFILE_IN_USE,
    STR_ID_SYNC_REPLACE_CONFIRM,

    STR_ID_SYNC_INVALID_DATA_ACCOUNT,

    STR_ID_SYNC_PROFILE_DEACTIVATED,

    STR_ID_SYNC_CONN_TYPE,
    STR_ID_SYNC_CONN_HTTP,
    STR_ID_SYNC_CONN_WAP,
    STR_ID_SYNC_INVALID_INPUT,

    STR_ID_SYNC_SAS_NOTIFICATION,
    STR_ID_SYNC_SAS_CONTEXT_1,
    STR_ID_SYNC_SAS_CONTEXT_2,

    /* add syncml string id before this line */
    STR_ID_SYNC_PROFILE_ID1,
    STR_ID_SYNC_PROFILE_ID2,
    STR_ID_SYNC_PROFILE_ID3,
    STR_ID_SYNC_END
} SYNCML_STR_ID_ENUM;

/* Image IDs */
typedef enum
{
    IMG_ID_SYNC_MENU = SYNCML_BASE,
    IMG_ID_SYNC_NOW,
    IMG_ID_SYNC_SETTINGS,

    IMG_ID_SYNC_PROFILE,
    IMG_ID_SYNC_SERVER,
    IMG_ID_SYNC_CONTACT,
    IMG_ID_SYNC_CALENDAR,
    IMG_ID_SYNC_CONNECTION,

    IMG_ID_SYNC_USERNAME,
    IMG_ID_SYNC_PASSWORD,
    IMG_ID_SYNC_END
} SYNCML_IMG_ID_ENUM;

#endif /*__SYNCML_RES_DEF_H__ */

