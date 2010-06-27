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
 * JavaDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define constances and enum values
 *   of Java related routines.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _JAVA_DEF_H
#define _JAVA_DEF_H

#include "MMI_features.h"

#ifdef __J2ME__
#include "GlobalConstants.h"    /* need MAX_SUB_MENUS */
#include "gui_data_types.h"

/*
 * #ifndef _GLOBALCONSTANTS_H_
 * #error "GlobalConstants.h should be include before javaAgencyDef.h"
 * #endif 
 * 
 * #ifndef __GUI_DATA_TYPES_H__
 * #error "gui_data_types.h should be include before javaAgencyDef.h"
 * #endif 
 * 
 * #include "jam_msg_handler.h"
 */
/* Definition */

//#define MAX_JAVA_SETTING_MODE_STR                             5*ENCODING_LENGTH
//#define COPY_MAX_JAVA_SETTING_ON_OFF_STR                                      ((MAX_JAVA_SETTING_MODE_STR/ENCODING_LENGTH)-1) /// not of char, not no of bytes
//#define MAX_MIDS_CONNSET_PERM 9 // {Never, Blanket...}
//#define MAX_MIDS_CONNSET      9 // {HTTP, HTTPS, SSL...}

/* Enum */

typedef enum
{
    SCR_JAVA = JAVA_BASE + 1,
    SCR_JAVA_APP,
    SCR_JAVA_INFO,
    SCR_JAVA_EM,
    SCR_JAVA_EM_TCK,

    SCR_JAVA_APP_MIDS_OPTION,

    SCR_JAVA_APP_OPTION_SELECT,
    SCR_JAVA_APP_OPTION_LAUNCH,
    SCR_JAVA_APP_OPTION_UPDATE,
    SCR_JAVA_APP_OPTION_SETTING,
    SCR_JAVA_APP_OPTION_INFO,
    SCR_JAVA_APP_OPTION_DELETE,

    SCR_JAVA_SETTING_NETWORK_ACCESS,
    SCR_JAVA_SETTING_AUTO_INVOCATION,
    SCR_JAVA_SETTING_MESSAGING,
    SCR_JAVA_SETTING_MULTIMEDIA,
    SCR_JAVA_SETTING_RECORDING,
    SCR_JAVA_SETTING_SNAPSHOT,

    SCR_JAVA_PERM,
    SCR_JAVA_DOMAIN,

    SCR_JAVA_DELETE_CONFIRM,
    SCR_JAVA_INSTALL_CONFIRM,
    SCR_JAVA_UPDATE_CONFIRM,
    SCR_JAVA_TIMEALARM_PUSH_CONFIRM,
    /* SCR_JAVA_TIMEALARM_PUSH_LAUNCH, */
    SCR_JAVA_RESET_RMS_CONFIRM,
    /* SCR_JAVA_PROGRESSING, */

    SCR_JAVA_DELETING,
    /* SCR_JAVA_DELETING2, */
    SCR_JAVA_START_UPDATING,
    SCR_JAVA_START_INSTALLING,
    SCR_J2ME_SCREEN_NOT_READY,
    SCR_JAVA_VM_INSTALLING,
    SCR_JAVA_LAUNCH_AFTER_INSTALL,
    SCR_JAVA_TERMINATE_DIALOG,
    SCR_JAVA_FORCE_TERMINATE_DIALOG,
    SCR_JAVA_RESUME_DIALOG,
    /* SCR_JAVA_DUMMY, */
    SCR_JAVA_PUSH_BUSY,

    SCR_JAVA_GET_PERMISSION,
    SCR_JAVA_GET_CONFIRM,
    SCR_JAVA_SHOW_PERCENTAGE,
    SCR_JAVA_VM_TERMINATING,
    SCR_JAVA_TERMINATE_DIALOG2,
    SCR_JAVA_AUTH,
    SCR_JAVA_DUMMY,
    SCR_JAVA_MAX
} JAVA_SCREEN_ID;

typedef enum
{
    STR_SCR_JAVA_CAPTION = JAVA_BASE + 1,
    STR_MENU3108_JAVA,

    STR_JAVA_EM,

    STR_JAVA_APP_OPTION_SELECT,
    STR_JAVA_APP_OPTION_LAUNCH,
    STR_JAVA_APP_OPTION_UPDATE,
    STR_JAVA_APP_OPTION_SETTING,
    STR_JAVA_APP_OPTION_INFO,
    STR_JAVA_APP_OPTION_DELETE,

    STR_JAVA_EM_NORMAL,
    STR_JAVA_EM_CLDC_TCK,
    STR_JAVA_EM_MIDP_TCK,
    STR_JAVA_EM_WMAPI_TCK,
    STR_JAVA_EM_MMAPI_TCK,

    STR_JAVA_SETTING_NETWORK_ACCESS,
    STR_JAVA_SETTING_AUTO_INVOCATION,
    STR_JAVA_SETTING_MESSAGING,
    STR_JAVA_SETTING_MULTIMEDIA,
    STR_JAVA_SETTING_FILE_READ,
    STR_JAVA_SETTING_FILE_WRITE,
    STR_JAVA_SETTING_LOCAL_CONNECTIVITY,

    STR_JAVA_PERM_USERDENY,
    STR_JAVA_PERM_ONESHOT,
    STR_JAVA_PERM_SESSION,
    STR_JAVA_PERM_BLANKET,
    STR_JAVA_PERM_BLANKET_GRANTED,

    STR_JAVA_PERM_DMN_OPERATOR,
    STR_JAVA_PERM_DMN_MANUFACTURER,
    STR_JAVA_PERM_DMN_3RDPARTY,
    STR_JAVA_PERM_DMN_UNTRUSTED,
    
    STR_JAVA_INFO_NAME,
    STR_JAVA_INFO_SIZE,
    STR_JAVA_INFO_VERSION,
    STR_JAVA_INFO_VENDOR,
    STR_JAVA_INFO_DESC,
    STR_JAVA_INFO_WEB,
    STR_JAVA_INFO_AUTH,
    STR_JAVA_INFO_CONN,
    STR_JAVA_INFO_BYTE,

    STR_JAVA_INFO_DRM_OBJECT,
    STR_JAVA_INFO_DRM_COUNT,
    STR_JAVA_INFO_DRM_START,
    STR_JAVA_INFO_DRM_END,

    STR_JAVA_ABORT,
    STR_JAVA_ABORT_ASK,
    STR_JAVA_ABORTING,
    STR_JAVA_ABORTED,
    STR_JAVA_ABORT_FAILED,

    STR_JAVA_DOWNLOAD,
    STR_JAVA_DOWNLOAD_ASK,
    STR_JAVA_DOWNLOADING,
    STR_JAVA_DOWNLOADED,
    STR_JAVA_DOWNLOAD_FAILED,

    STR_JAVA_INSTALL,
    STR_JAVA_INSTALL_ASK,
    STR_JAVA_START_INSTALLING,
    STR_JAVA_VM_INSTALLING,
    STR_JAVA_INSTALLED,
    STR_JAVA_INSTALL_FAILED,

    STR_JAVA_DELETE,
    STR_JAVA_DELETE_ASK,
    STR_JAVA_DELETING,
    STR_JAVA_DELETED,
    STR_JAVA_DELETE_FAILED,

    STR_JAVA_UPDATE,
    STR_JAVA_UPDATE_ASK,
    STR_JAVA_START_UPDATING,
    STR_JAVA_UPDATED,
    STR_JAVA_UPDATE_FAILED,

    STR_JAVA_LAUNCH_ASK,
    STR_JAVA_KEEP_RMS,
    STR_JAVA_STOPPED,
    STR_JAVA_START_UPDATE_ASK,
    STR_JAVA_PUSH_LAUNCH_ASK,
    STR_JAVA_RESET_RMS_ASK,
    /* VM error message and installation message added by Justin */
    STR_JAVA_ALERT,
    STR_JAVA_ERROR_CODE_OLD_VERSION,
    STR_JAVA_ERROR_CODE_ALREADY_INSTALLED,
    STR_JAVA_ERROR_CODE_NEW_VERSION,
    STR_JAVA_ERROR_CODE_NOT_FOUND,
    STR_JAVA_ERROR_CODE_INVALID_JAD,
    STR_JAVA_ERROR_CODE_MISSING_INFO_JAD,
    STR_JAVA_ERROR_CODE_MISSING_INFO_JAR,
    STR_JAVA_ERROR_CODE_DEVICE_INCOMPATIBLE,
    STR_JAVA_ERROR_CODE_JAD_MOVED,
    STR_JAVA_ERROR_CODE_INSUFFICIENT_STORAGE,
    STR_JAVA_ERROR_CODE_JAR_NOT_FOUND,
    STR_JAVA_ERROR_CODE_INVALID_JAR_URL,
    STR_JAVA_ERROR_CODE_CORRUPT_JAR,
    STR_JAVA_ERROR_CODE_INFO_MISMATCH,
    STR_JAVA_ERROR_CODE_VERIFY_FAILED,
    STR_JAVA_ERROR_CODE_AUTHORIZATION_FAILURE,
    STR_JAVA_ERROR_CODE_PUSH_DUP_FAILURE,
    STR_JAVA_ERROR_CODE_PUSH_PROTO_FAILURE,
    STR_JAVA_ERROR_CODE_TRUSTED_OVERWRITE_FAILURE,
    STR_JAVA_ERROR_CODE_DEFAULT_GAME,
    STR_JAVA_ERROR_CODE_DISK_OP_FAILURE,
    STR_JAVA_ERROR_CODE_UNKNOWN_FAILURE,
    STR_JAVA_ERROR_CODE_CANCEL,
    STR_JAVA_ERROR_CODE_OVER_MAX_INSTALL,
    STR_JAVA_ERROR_CODE_POST_ERROR,
    STR_JAVA_ERROR_CODE_NO_CARD,
    STR_JAVA_ERROR_CODE_BT_IN_USE,
    STR_JAVA_ERROR_CODE_MIDLET_RUNNING,
    STR_JAVA_ERROR_CODE_IN_CALL,
    STR_JAVA_ERROR_CODE_WRITE_PROTECTION,
    STR_JAVA_ERROR_CODE_MEMORY_INSUFFICIENT,
    STR_JAVA_PUSH_INSTALL,
    STR_JAVA_NORMAL_INSTALL,

    STR_JAVA_VM_BUSY,
    STR_JAVA_WAIT,
    STR_JAVA_LAUNCH_AFTER_INSTALL,
    STR_JAVA_TERMINATE_DIALOG_TITLE,
    STR_JAVA_RESUME_DIALOG_TITLE,
    STR_JAVA_PAUSE,
    STR_JAVA_RESUME,
    STR_JAVA_TERMINATE,
    STR_JAVA_BUSY_FOR_PAUSE_MODE,
    STR_JAVA_STOP_TIMEALARM_FOR_PAUSE_MODE,
    STR_JAVA_FORCE_TERMINATE,

    STR_JAVA_INSTALL_NA,
    STR_JAVA_PUSH_BUSY,

    STR_JAVA_PERMISSION_SOCKET,
    STR_JAVA_PERMISSION_HTTP,
    STR_JAVA_PERMISSION_HTTPS,
    STR_JAVA_PERMISSION_SSL,
    STR_JAVA_PERMISSION_DATAGRAM,
    STR_JAVA_PERMISSION_SVR_SOCKET,
    STR_JAVA_PERMISSION_SVR_DATAGRAM,
    STR_JAVA_PERMISSION_COMM,
    STR_JAVA_PERMISSION_PUSH,
    STR_JAVA_PERMISSION_SMS,
    STR_JAVA_PERMISSION_CBS,
    STR_JAVA_PERMISSION_MMS,
    STR_JAVA_PERMISSION_RECORD_CTRL,
    STR_JAVA_PERMISSION_SNAPSHOT,
    STR_JAVA_PERMISSION_FILE_READ,
    STR_JAVA_PERMISSION_FILE_WRITE,
    /* reserved for the future */
    STR_JAVA_PERMISSION_CONTACT_LIST_READ,
    STR_JAVA_PERMISSION_CONTACT_LIST_WRITE,
    STR_JAVA_PERMISSION_EVENT_LIST_READ,
    STR_JAVA_PERMISSION_EVENT_LIST_WRITE,
    STR_JAVA_PERMISSION_TODO_LIST_READ,
    STR_JAVA_PERMISSION_TODO_LIST_WRITE,
    STR_JAVA_PERMISSION_OBEX_CLIENT,
    STR_JAVA_PERMISSION_OBEX_SERVER,
    STR_JAVA_PERMISSION_OBEX_CLIENT_TCP,
    STR_JAVA_PERMISSION_OBEX_SERVER_TCP,
    STR_JAVA_PERMISSION_BT_CLIENT,
    STR_JAVA_PERMISSION_BT_SERVER,
    /* reserved for the future */
    STR_JAVA_PERMISSION_TELEPHONE,
    STR_JAVA_PERMISSION_EXCLUSIVE_PUSH,
    STR_JAVA_PERMISSION_EXCLUSIVE_NET,
    STR_JAVA_PERMISSION_UNKNOWN,
    STR_JAVA_PERMISSION_TITLE,

    STR_JAVA_PERMISSION_SETTING_FAIL,

    STR_JAVA_CONFIRM_VIRTUAL_KEYPAD,
    STR_JAVA_CONFIRM_VIRTUAL_KEYPAD_TITLE,

    STR_JAVA_CONFIRM_BEARER_FALLBACK,
    STR_JAVA_CONFIRM_BEARER_FALLBACK_TITLE,
	
    STR_JAVA_VM_TERMINATING,
    STR_JAVA_NETWORK_SETTING_DEFAULT,
    STR_JAVA_TERMINATE_JAVA_GAME,
    STR_JAVA_TERMINATE_EUREKA,
    STR_JAVA_DATE,
    STR_JAVA_TIME
} JAVA_STRING_LIST;

typedef enum
{
    IMG_MENU3108_JAVA = JAVA_BASE + 1,
    IMG_JAVA_STAR1,
    IMG_JAVA_STAR2,
    IMG_JAVA_POWERED,
    IMG_JAVA_ABORT,
    IMG_JAVA_DONE
} JAVA_IMAGE_LIST;

/*
 * enum 
 * {
 * J2ME_SCREEN_FULLSCREEN_EDITOR = JAVA_BASE+100,
 * J2ME_SCREEN_FULLSCREEN_EDITOR_OPTION,
 * // String ID
 * J2ME_STR_ID_DONE,
 * J2ME_STR_ID_CANCEL,
 * J2ME_STR_ID_INPUT_METHOD,
 * J2ME_STR_ID_OPTION,
 * J2ME_STR_ID_INPUT_TITLE,
 * 
 * J2ME_MAX_ID
 * };
 */
/* used in java mids setting , not global setting */
typedef enum
{
    J2ME_SETTING_NETWORK_ACCESS,
    J2ME_SETTING_AUTO_INVOCATION,
    J2ME_SETTING_MESSAGING,
    J2ME_SETTING_MULTIMEDIA,
    J2ME_SETTING_DATA_READ,
    J2ME_SETTING_DATA_WRITE,
    J2ME_SETTING_LOCAL_CONNECTIVITY,
    J2ME_SETTING_MAX
} java_mids_setting_item_enum;

/* used in java mids setting , not global setting */
typedef enum
{
    J2ME_CHOICE_ALLOW,
    J2ME_CHOICE_PROMPT,
    J2ME_CHOICE_NEVER,

    J2ME_CHOICE_MAX
} java_mids_setting_choice_enum;

typedef enum
{
    J2ME_CHOICE_USERDENY,
    J2ME_CHOICE_ONESHOT,
    J2ME_CHOICE_SESSION,
    J2ME_CHOICE_BLANKET,
    J2ME_CHOICE_PERMISSION_MAX
} java_mids_permission_setting_choice_enum;

typedef enum
{
    J2ME_INLINE_USERNAME_CAPTION,
    J2ME_INLINE_USERNAME,
    J2ME_INLINE_PASSWORD_CAPTION,
    J2ME_INLINE_PASSWORD
} java_auth_inline_item_enum;


typedef enum
{
    INSTALL_ABORT_STATE = -2,
    INSTALL_INVALID_STATE = -1,
    INSTALL_VALID_STATE = 0,
    INSTALL_FINISH_STATE = INSTALL_VALID_STATE,
    INSTALL_JAD_DOWNLOAD_STATE,
    /* INSTALL_CONFIRM_STATE,                   //install_confirm */
    INSTALL_JAR_DOWNLOAD_STATE
} java_install_state_enum;

typedef enum
{
    UPDATE_ABORT_STATE = -2,
    UPDATE_INVALID_STATE = -1,
    UPDATE_VALID_STATE = 0,
    UPDATE_FINISH_STATE = UPDATE_VALID_STATE,
    UPDATE_CONFIRM_UPD_STATE,
    UPDATE_JAD_DOWNLOAD_STATE,
    UPDATE_JAR_DOWNLOAD_STATE
} java_update_state_enum;

typedef enum
{
    DELETE_INVALID_STATE = -1,
    DELETE_VALID_STATE = 0,
    DELETE_FINISH_STATE = DELETE_VALID_STATE,
    DELETE_START_STATE,
    DELETE_CONFIRM_STATE,
    DELETE_VM_STATE
} java_delete_state_enum;

typedef enum
{
    SEND_MID_START_CTRL = 1,
    SEND_MID_GET_LIST_CTRL = 2,
    SEND_MIDS_GET_LIST_CTRL = 4,
    SEND_MIDS_GET_INFORMATION_CTRL = 8,
    SEND_MID_GET_SETTING_CTRL = 16,
    SEND_MID_SET_SETTING_CTRL = 32,
    SEND_GET_DEFAULT_DOMAIN_CTRL = 64,
    SEND_SET_DEFAULT_DOMAIN_CTRL = 128
} mmi_java_message_control_enum;


typedef enum
{
    TER_ENTRY_NONE,
    TER_ENTRY_JAVA_MENU,
    TER_ENTRY_EUREKA_BY_MENU,
    TER_ENTRY_INSTALL_JAVA,
    TER_ENTRY_LAUNCH_AFTER_INSTALL,
    TER_ENTRY_EUREKA_BY_WAP,
    TER_ENTRY_IDLE
} mmi_java_screen_after_terminate_enum;

#endif /* __J2ME__ */
#endif /* _JAVA_DEF_H */

