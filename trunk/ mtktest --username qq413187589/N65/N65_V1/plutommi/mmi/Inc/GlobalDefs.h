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
 *  GlobalDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 FILENAME   : GlobalDefs.h 
 PURPOSE    : Contains the global resource ids.  
 REMARKS    : 
 AUTHOR     : Vikram
 DATE    : . 26 May 2003
 **************************************************************/
#ifndef __GLOBAL__DEFS_
#define __GLOBAL__DEFS_
#include "MMIDataType.h"

enum STR_GLOBAL_LIST
{
                                    /* [English], [Description] */
    STR_GLOBAL_0 = GLOBAL_BASE,     /* "0", "Global String- 0" */
    STR_GLOBAL_1,                   /* "1", "Global String- 1" */
    STR_GLOBAL_2,                   /* "2", "Global String- 2" */
    STR_GLOBAL_3,                   /* "3", "Global String- 3" */
    STR_GLOBAL_4,                   /* "4", "Global String- 4" */
    STR_GLOBAL_5,                   /* "5", "Global String- 5" */
    STR_GLOBAL_6,                   /* "6", "Global String- 6" */
    STR_GLOBAL_7,                   /* "7", "Global String- 7" */
    STR_GLOBAL_8,                   /* "8", "Global String- 8" */
    STR_GLOBAL_9,                   /* "9", "Global String- 9" */
    STR_GLOBAL_10,                  /* "10", "Global String- 10" */
    STR_GLOBAL_ABORT,               /* "Abort", "Global String- Abort" */
    STR_GLOBAL_ABORTING,            /* "Aborting", "Global String- Aborting" */
    STR_GLOBAL_ACCEPT,              /* "Accept", "Global String- Accept" */
    STR_GLOBAL_ACCOUNTS,            /* "Accounts",	"Accounts- configuration folder" */
    STR_GLOBAL_ACTIVATE,            /* "Activate", "Global String- Activate" */
    STR_GLOBAL_ACTIVATED,           /* "Activated", "Global String- Activated" */  
    STR_GLOBAL_ADD,                 /* "Add", "Global String- Add" */
    STR_GLOBAL_ADDRESS,             /* "Address", "Global String- Address" */
    STR_GLOBAL_ALARM,               /* "Alarm", "Global String- Alarm" */
    STR_GLOBAL_AS_EMAIL,            /* "As Email", "Global String- As Email- sub option of sending command" */
    STR_GLOBAL_AS_MULTIMEDIA_MSG,   /* "As multimedia msg.", "Global String- As multimedia msg.- sub option of sending command" */
    STR_GLOBAL_AS_TEXT_MESSAGE,     /* "As text message", "Global String- As text message- sub option of sending command" */
    STR_GLOBAL_ATTACHMENT,          /* "Attachment", "Global String- Attachment" */
    STR_GLOBAL_AUTHENTICATION,      /* "Authentication","Global String- Authentication" */
    STR_GLOBAL_AUTOMATIC,           /* "Automatic","Global String- Automatic" */
    STR_GLOBAL_BACK,                /* "Back", "Global String- Back" */
    STR_GLOBAL_BUSY_TRY_LATER,      /* "Busy", "STR_GLOBAL_BUSY_TRY_LATER" */
    STR_GLOBAL_CANCEL,              /* "Cancel", "Global String- Cancel" */
    STR_GLOBAL_CANCELLING,          /* "Cancelling", "Global String- Cancelling" */
    STR_GLOBAL_CLEAR,               /* "Clear", "Global String- Clear" */
    STR_GLOBAL_CLOSE,               /* "Close", "Global String- Close" */
    STR_GLOBAL_CONFIRM,             /* "Confirm", "Global String- Confirm" */
    STR_GLOBAL_CONNECT,             /* "Connect", "Global String- Connect" */
    STR_GLOBAL_CONNECTING,          /* "Connecting", "Global String- Connecting" */
    STR_GLOBAL_CONTACTS,            /* "Contacts", "Global String- Contacts" */
    STR_GLOBAL_CONTENT,             /* "Content", "Global String- Content" */
    STR_GLOBAL_CONTINUE,            /* "Cont.", "Global String- Cont.- use as LSK for length limit" */
    STR_GLOBAL_COPYING,             /* "Copying", "Global String- Copying" */
    STR_GLOBAL_CUSTOM,              /* "Custom", "Global String- Custom- user defined" */
    STR_GLOBAL_DATA_ACCOUNT,        /* "Data account", "Global String- Data account" */
    STR_GLOBAL_DATE,                /* "Date", "Global String- Date" */
    STR_GLOBAL_DEACTIVATE,          /* "Deactivate", "Global String- Deactivate" */
    STR_GLOBAL_DEFAULT,             /* "Default", "Global String- Default" */
    STR_GLOBAL_DELETE,              /* "Delete", "Global String- Delete" */
    STR_GLOBAL_DELETE_ALL,          /* "Delete All", "Global String- Delete All" */
    STR_GLOBAL_DELETED,             /* "Deleted", "Global String- Deleted" */
    STR_GLOBAL_DELETING,            /* "Deleting", "Global String- Deleting" */
    STR_GLOBAL_DETAILS,             /* "Details", "Global String- Details" */
    STR_GLOBAL_DIAL,                /* "Call", "Global String- Call" */
    STR_GLOBAL_DISCARD,             /* "Discard","Global String- Discard" */
    STR_GLOBAL_DISCONNECT,          /* "Disconnect", "Global String- Disconnect" */
    STR_GLOBAL_DISCONNECTING,       /* "Disconnecting", "Global String- Disconnecting" */
    STR_GLOBAL_DONE,                /* "Done", "Global String- Done" */
    STR_GLOBAL_DOWNLOAD,            /* "Download", "STR_GLOBAL_DOWNLOAD" */
    STR_GLOBAL_DOWNLOAD_ASK,        /* "Download?", "STR_GLOBAL_DOWNLOAD_ASK" */
    STR_GLOBAL_DOWNLOADING,         /* "Downloading", "STR_GLOBAL_DOWNLOADING" */
    STR_GLOBAL_DRAFTS,              /* "Drafts", "Global String- Drafts- draft folder" */
    STR_GLOBAL_DRM_FILE_EXISTS,     /* "File Exists", "Global String- File Exists" */
    STR_GLOBAL_DRM_FS_ERROR,        /* "File Access Error", "Global String- File Access Error" */
    STR_GLOBAL_DRM_INVALID_FORMAT,  /* "Format Error", "Global String- Format Error" */
    STR_GLOBAL_DRM_NON_DRM,         /* "Not DRM File", "Global String- Not DRM File" */
    STR_GLOBAL_DRM_PROCESSING,      /* "DRM Processing", "Global String- DRM Processing" */
    STR_GLOBAL_DRM_PROHIBITED,      /* "DRM Prohibited", "Global String- DRM Prohibited" */
    STR_GLOBAL_DRM_RO_RECEIVED,     /* "DRM Rights Received", "Global String- DRM Rights Received" */
    STR_GLOBAL_DRM_SIZE_TOO_BIG,    /* "Size Too Big", "Global String- Size Too Big" */
    STR_GLOBAL_EARPHONE_IN,         /* "Earphone plugged in!", "Global String- String Associated with Ear Phone Plug In Popup." */
    STR_GLOBAL_EARPHONE_OUT,        /* "Earphone plugged Out", "Global String- Earphone plugged Out" */
    STR_GLOBAL_EDIT,                /* "Edit", "Global String- Edit" */
    STR_GLOBAL_EMAIL,               /* "Email", "Global String- Email" */
    STR_GLOBAL_EMPTY,               /* "Empty", "Global String- Empty" */
    STR_GLOBAL_EMPTY_LIST,          /* "<Empty>", "Global String- <Empty>" */
    STR_GLOBAL_ERROR,               /* "Error", "Global String- Error" */
    STR_GLOBAL_EXIT,                /* "Exit", "Global String- Exit" */
    STR_GLOBAL_FAILED_TO_SAVE,      /* "Failed to save", "Global String- Failed to save" */
    STR_GLOBAL_FAILED_TO_SEND,      /* "Failed to send", "Global String- Failed to send" */
    STR_GLOBAL_FAST,                /* "Fast", "Global String- Fast" */
    STR_GLOBAL_FILE_ALREADY_EXISTS, /* "File already exists", "Global String- File already exists" */
    STR_GLOBAL_FILENAME,            /* "Filename", "Global String- Filename" */
    STR_GLOBAL_FORMAT,              /* "Format", "Global String- Format- the type of file" */
    STR_GLOBAL_FORWARD,             /* "Forward", "Global String- Forward- send message to other recipients" */
    STR_GLOBAL_GO_TO,               /* "Go to", "Global String- Go to- connect the URL" */
    STR_GLOBAL_GPRS,                /* "GPRS", "Global String- GPRS" */
    STR_GLOBAL_GSM,                 /* "GSM", "Global String- GSM" */
    STR_GLOBAL_HELP,                /* "Help", "Global String- Help- show the usage tips or notes" */
    STR_GLOBAL_HIGH,                /* "High", "Global String- High" */
    STR_GLOBAL_HTTP,                /* "HTTP", "Global String- HTTP" */
    STR_GLOBAL_INBOX,               /* "Inbox", "Global String- Inbox" */
    STR_GLOBAL_INPUT_METHOD,        /* "Input Method", "Global String- Input Method" */
    STR_GLOBAL_INSTALL,             /* "Install", "Global String- Install" */
    STR_GLOBAL_INSUFFICIENT_MEMORY, /* "Insufficient memory", "Global String- Insufficient memory- not enough RAM to operate" */
    STR_GLOBAL_INVALID,             /* "Invalid", "Global String- Invalid" */
    STR_GLOBAL_INVALID_FILENAME,    /* "Invalid filename", "Global String- Invalid filename" */
    STR_GLOBAL_INVALID_FORMAT,      /* "Invalid format", "Global String- Invalid format" */
    STR_GLOBAL_INVALID_INPUT,       /* "Invalid input", "Global String- Invalid input" */
    STR_GLOBAL_INVALID_URL,         /* "Invalid URL", "Global String- Invalid URL" */
    STR_GLOBAL_LIST,                /* "List", "Global String- List" */
    STR_GLOBAL_LOADING,             /* "Loading", "Global String- Loading" */
    STR_GLOBAL_LOGIN,               /* "Login", "Global String- Login" */
    STR_GLOBAL_LOGO,                /* "Logo", "Global String- Logo" */
    STR_GLOBAL_LOGOUT,              /* "Logout", "Global String- Logout" */
    STR_GLOBAL_LOW,                 /* "Low", "Global String- Low" */
    STR_GLOBAL_MANUAL,              /* "Manual", "Global String- Manual" */
    STR_GLOBAL_MARK,                /* "Mark", "Global String- Mark" */
    STR_GLOBAL_MARK_ALL,            /* "Mark all", "Global String- Mark all" */
    STR_GLOBAL_MAXIMUM,             /* "Maximum", "Global String- Maximum" */
    STR_GLOBAL_MEDIUM,              /* "Medium", "Global String- Medium" */
    STR_GLOBAL_MEMORY_CARD,         /* "Memory card", "Global String- Memory card" */
    STR_GLOBAL_MEMORY_FULL,         /* "Memory full", "Global String- Memory full- indicate user not save again" */
    STR_GLOBAL_MEMORY_STATUS,       /* "Memory status", "Global String- Memory status" */
    STR_GLOBAL_MOVING,              /* "Moving", "Global String- Moving" */
    STR_GLOBAL_MULTIMEDIA_MESSAGE,  /* "Multimedia message ", "Global String- Multimedia message " */
    STR_GLOBAL_MUTE,                /* "Mute", "Global String- Mute" */
    STR_GLOBAL_NETWORK_SETTINGS,    /* "Network settings", "Global String- Network settings" */
    STR_GLOBAL_NO,                  /* "No", "Global String- No" */
    STR_GLOBAL_NO_MEMORY_CARD,      /* "No Memory Card", "[Notify-No Memory Card]" */
    STR_GLOBAL_NONE,                /* "None", "Global String- None" */
    STR_GLOBAL_NORMAL,              /* "Normal", "Global String- Normal" */
    STR_GLOBAL_NOT_AVAILABLE,       /* "Not Available", "Global String- Not Available" */
    STR_GLOBAL_NOT_DONE,            /* "Not Done", "Global String- Not Done" */
    STR_GLOBAL_NOT_ENOUGH_MEMORY,   /* "Not enough memory", "Global String- Not enough memory- memory is too small to save" */
    STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR, /* "Not Support at PC Simulator", "Global String- Not Support at PC Simulator" */
    STR_GLOBAL_NOT_SUPPORTED,       /* "Not supported", "Global String- Not supported" */
    STR_GLOBAL_OFF,                 /* "Off", "Global String- Off" */
    STR_GLOBAL_OK,                  /* "Ok", "Global String- OK" */
    STR_GLOBAL_ON,                  /* "On", "Global String- On"*/
    STR_GLOBAL_OPEN,                /* "Open", "Global String- Open" */
    STR_GLOBAL_OPTIONS,             /* "Option", "Global String- Options" */
    STR_GLOBAL_OUTBOX,              /* "Outbox", "Global String- Outbox" */
    STR_GLOBAL_OVERWRITE_EXISTING_FILE, /* "Overwrite existing file?", "Global String- Overwrite existing file?" */
    STR_GLOBAL_PASSWORD,            /* "Password","Global String- Password menu" */
    STR_GLOBAL_PAUSE,               /* "Pause","Global String- Pause" */
    STR_GLOBAL_PHONE,               /* "Phone","Global String- Phone" */
    STR_GLOBAL_PICTURE,             /* "Picture","Global String- Picture" */
    STR_GLOBAL_PLAY,                /* "Play","Global String- Play" */
    STR_GLOBAL_PLEASE_WAIT,         /* "Please Wait", "Global String- Please Wait" */
    STR_GLOBAL_PREFERRED_STORAGE,   /* "Preferred storage", "Global String- Preferred storage" */
    STR_GLOBAL_PREVIEW,             /* "Preview", "Global String- Preview" */
    STR_GLOBAL_PRINT,               /* "Print", "Global String- Print" */
    STR_GLOBAL_PRIORITY,            /* "Priority", "Global String- Priority" */
    STR_GLOBAL_PROXY,               /* "Proxy", "Global String- Proxy" */
    STR_GLOBAL_QUIT,                /* "Quit", "Global String- Quit" */
    STR_GLOBAL_READ,                /* "Read", "Global String- Read" */
    STR_GLOBAL_RECEIVED,            /* "Received", "Global String- Received" */
    STR_GLOBAL_RECEIVING,           /* "Receiving", "Global String- Receiving" */
    STR_GLOBAL_RECIPIENTS,          /* "Recipients", "Global String- Recipients- recipient list name" */
    STR_GLOBAL_REFRESH,             /* "Refresh", "Global String- Refresh" */
    STR_GLOBAL_REMOVE,              /* "Remove", "Global String- Remove- delete the reference link or remove accessory from phone" */
    STR_GLOBAL_REMOVED,             /* "Removed", "Global String- Removed- remove successfully" */
    STR_GLOBAL_RENAME,              /* "Rename", "Global String- Rename" */
    STR_GLOBAL_REPLACE,             /* "Replace", "Global String- Replace" */
    STR_GLOBAL_REPLY,               /* "Reply", "Global String- Reply" */
    STR_GLOBAL_RESET,               /* "Reset", "Global String- Reset" */
    STR_GLOBAL_RESUME,              /* "Resume", "Global String- Resume" */
    STR_GLOBAL_RINGTONE,            /* "Ringtone", "Global String- Ringtone" */
    STR_GLOBAL_SAVE,                /* "Save", "Global String- Save" */
    STR_GLOBAL_SAVE_ASK,            /* "Save?", "Global String- Save?" */
    STR_GLOBAL_SAVE_TO_CONTACTS,    /* "Save to contacts", "Global String- Save to contacts" */
    STR_GLOBAL_SAVED,               /* "Saved", "Global String- Saved"); */
    STR_GLOBAL_SAVING,              /* "Saving", "Global String- Saving" */
    STR_GLOBAL_SEARCH,              /* "Search", "Global String- Search" */
    STR_GLOBAL_SEARCHING,           /* "Searching", "Global String- Searching" */
    STR_GLOBAL_SELECT,              /* "Select", "Global String- Select" */
    STR_GLOBAL_SEND,                /* "Send", "Global String- Send" */
    STR_GLOBAL_SENDING,             /* "Sending", "Global String- Sending"*/
    STR_GLOBAL_SENT,                /* "Sent", "Global String- Sent- send successfully" */
    STR_GLOBAL_SETTINGS,            /* "Settings", "Global String- Settings" */
    STR_GLOBAL_SIM,                 /* "SIM", "Global String- SIM" */
    STR_GLOBAL_SLOW,                /* "Slow", "Global String- Slow" */
    STR_GLOBAL_SORT_BY,             /* "Sort by", "Global String- Sort by- include sub options" */
    STR_GLOBAL_START,               /* "Start", "Global String- Start" */
    STR_GLOBAL_STOP,                /* "Stop", "Global String- Stop" */
    STR_GLOBAL_STORAGE,             /* "Storage", "Global String- Storage" */
    STR_GLOBAL_SUBJECT,             /* "Subject", "Global String- Subject" */
    STR_GLOBAL_SUBMIT,              /* "Submit","Accept" */
    STR_GLOBAL_TEXT,                /* "Text", "Global String- Text" */
    STR_GLOBAL_TEXT_MESSAGE,        /* "Text message", "Global String- Text message- SMS" */
    STR_GLOBAL_TIME,                /* Time", "Global String- Time" */
    STR_GLOBAL_UDP_PORT,            /* "UDP port", "Global String- UDP port" */
    STR_GLOBAL_UNFINISHED,          /* "Unfinished", "Global String- Unfinished" */
    STR_GLOBAL_UNMARK,              /* "Unmark", "Global String- Unmark" */
    STR_GLOBAL_UNMARK_ALL,          /* "Unmark all", "Global String- Unmark all" */
    STR_GLOBAL_UNSUPPORTED_FORMAT,  /* "Unsupported Format", "Global String- Unsupported Format" */
    STR_GLOBAL_URL,                 /* "URL", "Global String- URL" */
    STR_GLOBAL_UPDATE,              /* "Update", "Global String- Update" */
    STR_GLOBAL_USE_TEMPLATE,        /* "Use Template", "Global String- Use Template" */
    STR_GLOBAL_USERNAME,            /* "User Name", "Global String- User name menu" */
    STR_GLOBAL_VIA_BLUETOOTH,       /* "Via Bluetooth", "Global String- Via Bluetooth- sub option of sending command" */
    STR_GLOBAL_VIA_INFRARED,        /* "Via infrared", "Global String- Via infrared- sub option of sending command" */
    STR_GLOBAL_VIDEO,               /* "Video", "Global String- Video" */
    STR_GLOBAL_VIEW,                /* "View", "Global String- View" */
    STR_GLOBAL_VOLUME,              /* "Volume", "Global String- Volume" */
    STR_GLOBAL_WAP,                 /* "WAP", "Global String- WAP" */
    STR_GLOBAL_YES,	                /* "Yes", "Global String- Yes" */

    /* add new resource before here */
	STR_GLOBAL_END

};

enum IMG_GLOBAL_LIST
{
    IMG_GLOBAL_OK = GLOBAL_BASE,
    IMG_GLOBAL_BACK,
    IMG_GLOBAL_YES,
    IMG_GLOBAL_NO,
    IMG_GLOBAL_OPTIONS,
    /* Start of numeric list icons */
    IMG_GLOBAL_LSTART,
    IMG_GLOBAL_L1,
    IMG_GLOBAL_L2,
    IMG_GLOBAL_L3,
    IMG_GLOBAL_L4,
    IMG_GLOBAL_L5,
    IMG_GLOBAL_L6,
    IMG_GLOBAL_L7,
    IMG_GLOBAL_L8,
    IMG_GLOBAL_L9,
    IMG_GLOBAL_L10,
    IMG_GLOBAL_L11,
    IMG_GLOBAL_L12,
    IMG_GLOBAL_L13,
    IMG_GLOBAL_L14,
    IMG_GLOBAL_L15,
    IMG_GLOBAL_L16,
    IMG_GLOBAL_L17,
    IMG_GLOBAL_L18,
    IMG_GLOBAL_L19,
    IMG_GLOBAL_L20,
    IMG_GLOBAL_L21,
    IMG_GLOBAL_L22,
    IMG_GLOBAL_L23,
    IMG_GLOBAL_L24,
    IMG_GLOBAL_L25,
    IMG_GLOBAL_L26,
    IMG_GLOBAL_L27,
    IMG_GLOBAL_L28,
    IMG_GLOBAL_L29,
    IMG_GLOBAL_L30,
    IMG_GLOBAL_LEND,
    /* end of numeric list icons */
    IMG_STATUS,
    IMG_TIME,
    IMG_REPEAT,
    IMG_CAL,
    IMG_GLOBAL_UNFINISHED,
    IMG_GLOBAL_WARNING,
    IMG_GLOBAL_ACTIVATED,
    IMG_GLOBAL_QUESTION,
    IMG_GLOBAL_SAVE,
    IMG_GLOBAL_DELETED,
    IMG_GLOBAL_EMPTY,
    IMG_GLOBAL_DEFAULT,
    IMG_GLOBAL_PROGRESS,
    IMG_GLOBAL_LOADING,
    IMG_GLOBAL_ERASED,
    IMG_GLOBAL_ERROR,
    IMG_GLOBAL_INFO,
    IMG_VICON,
    IMG_GLOBAL_CLEAR,
    IMG_EARPHONE_POPUP_MAINLCD,
    IMG_EARPHONE_POPUP_SUBLCD,
    IMG_GLOBAL_SUB_MENU_BG,
    IMG_GLOBAL_MAIN_MENU_BG,
    IMG_NONE,

    /* add new resource before here */
    IMG_GLOBAL_END
};

/* 101205 audio resource Calvin Start */
enum ADO_GLOBAL_LIST
{
    ADO_GLOBAL_EMPTYAUDIO = GLOBAL_BASE,
    ADO_GLOBAL_EMPTYAUDIO_EXT,  /* for custpack */
    ADO_GLOBAL_NOAUDIO,
    ADO_GLOBAL_DEFAULT,

    /* add new resource before here */
    ADO_GLOBAL_END
};

/* 101205 audio resource Calvin End */

#endif /* __GLOBAL__DEFS_ */ 

