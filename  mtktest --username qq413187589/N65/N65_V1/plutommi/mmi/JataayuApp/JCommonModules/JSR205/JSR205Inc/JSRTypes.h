/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * JsrTypes.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file intends for handling the JSR messages.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _JSR_TYPES_H
#define _JSR_TYPES_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "ProtocolEvents.h"
#include "wap_ps_struct.h"

/* if some header should be include before this one */
/***************************************************************************** 
* Define
*****************************************************************************/

#define JSR_MAX_APP_ID_NUM 5
#define JSR_MAX_APP_ID_LENGTH 100
#define JSR_MAX_MSGS_NUM 10

#define JSR_INFO "info.db"
#define MMS_FOLDER "C:\\"
#define JSR_INFO_FILE MMS_FOLDER JSR_INFO

#define MMS_SYS_FOLDER "C:\\"
#define JSR_APPID_LIST "appidlist.cn"
#define JSR_APPID_LIST_TMP "appidlist.tp"
#define JSR_APPID_LIST_FILE MMS_SYS_FOLDER JSR_APPID_LIST
#define JSR_APPID_LIST_FILE_TMP MMS_SYS_FOLDER JSR_APPID_LIST_TMP
#define JSR_MEDIA_OBJECT "jsrmedia.mo"
#define JSR_MEDIA_OBJECT_FILE MMS_FOLDER JSR_MEDIA_OBJECT

#define JSR_MMS_FILE_NAME_LENGTH 40
#define JSR_ADDRESS_FIELD_LENGTH 40
#define JSR_SUBJECT_FIELD_LENGTH 40

#define JSR_MMS_FILE_PATH_LENGTH 100

typedef enum
{
    JSR_OP_IDLE,
    JSR_OP_SEND_MSG,
    JSR_OP_RECV_MSG,
    JSR_OP_ABORT_SENDING_MSG,
    JSR_OP_ABORT_RECIEVING_MSG,
    JSR_OP_UPLOAD_MSG,
    JSR_OP_DELETE_MSG,
    JSR_OP_CHECK_MSG,
    JSR_OP_READ_MSG,
    JSR_OP_CFG_APP_ID
} mmi_jsr_operations_enum;

typedef enum
{
    JSR_STATE_IDLE,
    JSR_STATE_READ_FOLDER,
    JSR_STATE_CREATE_MSG,
    JSR_STATE_UPLOAD_MSG,
    JSR_STATE_DELETE_MSG,
    JSR_STATE_PROCESS_SEND_MSG_HDR,
    JSR_STATE_PROCESS_SEND_MSG_BDY,
    JSR_STATE_RECV_MSG_HDR,
    JSR_STATE_RECV_MSG_BDY
} mmi_jsr_states_enum;

typedef enum
{
    JSR_RESULT_OK,
    JSR_RESULT_BUSY,
    JSR_RESULT_INSUFFICIENT_MEMORY,
    JSR_RESULT_INSUFFICIENT_PERSISTENT_STORAGE,
    JSR_RESULT_INVALID_MESSAGE,
    JSR_RESULT_INVALID_MESSAGE_BODY,
    JSR_RESULT_MESSAGE_ID_NOT_FOUND,
    JSR_RESULT_FILE_OPERATION_ERROR,
    JSR_RESULT_INVALID_FOLDER,
    JSR_RESULT_ACCESS_DENY,
    JSR_RESULT_INVALID_PARAMETER,
    JSR_RESULT_EXCEED_MAX_MSGS,
    JSR_RESULT_ERROR,
    JSR_RESULT_MMS_NO_READY,
    JSR_RESULT_NO_MSG_FOR_JAVA,
    JSR_RESULT_ERROR_APPID_EXIST,
    JSR_RESULT_ERROR_APPID_NOT_FOUND,
    JSR_RESULT_ERROR_APPID_TOO_LARGE,
    JSR_RESULT_ERROR_APPID_FULL,
    JSR_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR,
    JSR_RESULT_ERROR_FAIL_TO_WR_MMS_HDR,
    JSR_RESULT_ERROR_MSG_CORRUPTED,
    JSR_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM
} mmi_jsr_result_enum;

typedef enum
{
    JSR_BASIC = 1,
    JSR_FULL
} mmi_jsr_retrieval_mode_enum;

typedef enum
{
    JSR_NO_FOLDER = 0x00,
    JSR_INBOX = 0x01,       /* Incoming messages */
    JSR_OUTBOX = 0x02,      /* Outgoing messages */
    JSR_SENT = 0x04,        /* Successfully sent messages */
    JSR_DRAFTS = 0x08,      /* Messages during work */
    JSR_NOTIFY = 0x10,
    JSR_HIDDEN = 0x20,
    JSR_TEMPLATES = 0x40,   /* Template folder */
    JSR_ALL_FOLDERS = 0xFFFF
} mmi_jsr_folder_type_enum;

typedef enum
{
    JSR_WAP_MMS_PROF_MMSC_ADDRESS   /* WAP MMSC address */
} mmi_jsr_wap_mms_prof_access_enum;

typedef struct mmi_jsr_msg_info_struct
{
    U32 msg_id;
    U8 is_checked;
    struct mmi_jsr_msg_info_struct *next;
    struct mmi_jsr_msg_info_struct *prev;
} mmi_jsr_msg_info;

typedef struct mmi_jsr_appid_list_struct
{
    char *app_id;
    mmi_jsr_msg_info *msgs;
    struct mmi_jsr_appid_list_struct *next;
    struct mmi_jsr_appid_list_struct *prev;
} mmi_jsr_appid_msgid_list;

typedef struct
{
    char *app_id;
} mmi_jsr_appid_info_struct;

typedef struct
{
    U32 num_of_msg;
    U32 num_of_unread_msg;
    U8 mms_home_directory[JSR_MMS_FILE_PATH_LENGTH];
    U8 info_file_path[JSR_MMS_FILE_PATH_LENGTH];
} mmi_jsr_folder_info_struct;

typedef struct
{
    U32 msg_id;
    U32 offset;
    U32 size;
    U32 date;
    /* for new phone suite */
    U8 filename[JSR_MMS_FILE_NAME_LENGTH];
    U8 address[JSR_ADDRESS_FIELD_LENGTH];
    U8 subject[JSR_SUBJECT_FIELD_LENGTH];
} mmi_jsr_message_info_struct;

typedef struct
{
    U8 op;
    U8 state;
    U32 msg_id;
    U8 curr_media_obj_no;
    U8 total_media_obj_no;
    U8 retrievalMode;
    mmi_jsr_appid_msgid_list *jsr_appid_object_list;
    mmi_jsr_appid_info_struct *jsr_appid_db[JSR_MAX_APP_ID_NUM];
} mmi_jsr_context_struct;

#endif /* _JSR_TYPES_H */ 

