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
 * PushInboxDefs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This defines the String ,screen,& Image ID for push inbox module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/*
 * #ifndef _JPROFILEHANDLERDEFS_H
 * #define _JPROFILEHANDLERDEFS_H
 */
#define __NEWSIMULATOR

#include "MMI_features.h"
#include "MMIDataType.h"
#include "custom_nvram_editor_data_item.h"
#include "pmg_struct.h"
#undef __NEWSIMULATOR
#ifdef __MMI_BROWSER_2__

/*
 * typedef enum
 * {
 * PMG_MSGTYPE_NOT_SPECIFY = 0,
 * PMG_MSGTYPE_SI,
 * PMG_MSGTYPE_SL
 * }PUSH_SERVICE_MSG_TYPE_ENUM;
 * 
 * typedef enum
 * {
 * PMG_STATUS_OK = 0,
 * PMG_MSGTYPE_NOT_FOUND,
 * }PUSH_SERVICE_MSG_STATUS_ENUM;
 * 
 * typedef enum
 * {
 * PMG_STRTYPE_ASCII = 0,
 * PMG_STRTYPE_UCS2,
 * }PUSH_SERVICE_MSG_TEXT_TYPE_ENUM;
 * 
 * typedef enum
 * {
 * 
 * PMG_PARAM_NOT_SPECIFIED =0,
 * PMG_PARAM_READ_YES,
 * PMG_PARAM_READ_NO,
 * PMG_PARAM_EXPIRED_YES,
 * PMG_PARAM_EXPIRED_NO,
 * PMG_PARAM_INFOTAG_YES,
 * PMG_PARAM_INFOTAG_NO,
 * 
 * }PUSH_SERVICE_MSG_PARAM_TYPE_ENUM;
 * 
 * typedef struct
 * {
 * U8 addr[129];
 * U8 addr_type;
 * }pmg_addr_struct;
 * 
 * 
 * typedef struct
 * {
 * S16 msgID;
 * U8 msgType;
 * S8  href[48];
 * S32 created;
 * S32   expired;
 * U8 priority;
 * S8 text[32];
 * U8 textType;
 * U8 read;
 * }pmg_msg_list_struct;
 * 
 * 
 * typedef struct
 * {
 * S16 msgID;
 * U8 msgType;
 * S32 created;
 * S32   expired;
 * U8 priority;
 * S8 text[361];
 * U8 textType;
 * U8 read;
 * pmg_addr_struct   from;
 * U8 hasInfo;
 * }pmg_detailed_msg_struct;
 * 
 * typedef struct
 * {
 * S32 transID;
 * S32 msgID;
 * }pmg_delete_msg_req_struct;
 * 
 * typedef struct
 * {
 * S16 transID;
 * U8  status;
 * }pmg_delete_msg_cnf_struct;
 * 
 * typedef struct
 * {
 * S32 transID;
 * S32 msgID;
 * }pmg_get_msg_req_struct;
 * 
 * 
 * typedef struct
 * {
 * S8 transID;
 * pmg_detailed_msg_struct msgData;
 * U8 status;
 * }pmg_get_msg_cnf_struct;
 * 
 * typedef struct
 * {
 * S16 transID;
 * U8 msgType;
 * U8 isRead;
 * U8 isExpired;
 * U8 hasInfo;
 * }pmg_msg_count_req_struct;
 * 
 * typedef struct
 * {
 * S16 transID;
 * U32 msg_count;
 * }pmg_msg_count_cnf_struct;
 * 
 * typedef struct
 * {
 * S16 transID;
 * U8 msgType;
 * U8 isRead;
 * U8 isExpired;
 * U8 hasInfo;
 * U8 startFrom;
 * U16 size;
 * }pmg_msg_list_req_struct;
 * 
 * typedef struct
 * {
 * S16 transID;
 * pmg_msg_list_struct pmg_msg_list_struct[20];
 * U8 size;
 * U8 more;
 * U8 size_remained;
 * }pmg_msg_list_cnf_struct;
 * 
 * 
 * typedef struct
 * {
 * S16 transID;
 * U8 msgType;
 * }pmg_delete_all_req_struct;
 * 
 * 
 * typedef struct
 * {
 * S16 transID;
 * U8 status;
 * }pmg_delete_all_cnf_struct;
 * 
 * typedef struct
 * {
 * S16 msgID;
 * U8 msgType;
 * }pmg_delete_ind_struct;
 * 
 * typedef struct
 * {
 * S16   transID;
 * S16   msgID;
 * U8 read;
 * }pmg_update_msg_req_struct;
 * 
 * typedef struct
 * {
 * S16   transID;
 * U8 status;
 * }pmg_update_msg_cnf_struct;
 */
typedef struct
{
    S16 msgID;
    U8 msgType;
    U8 priority;
    /* U8   addr_type; */
    U8 addr[WAP_PMG_MAX_ADDR_CHARS + 1];
    U8 trust_addr_type;
} push_msg_data_struct;

typedef struct queue
{
    push_msg_data_struct data;
    struct queue *next;
} push_msg_ind_queue_struct;

/*
 * typedef enum
 * {
 * PMG_MSGPRIO_HIGH,
 * PMG_MSGPRIO_MEDIUM,
 * PMG_MSGPRIO_LOW
 * }push_si_msg_priority_enum;
 */
#define MAX_IP_ADDRES_LEN                    (4)

typedef enum
{
    PUSH_ENABLE_ON = 0,
    PUSH_ENABLE_OFF
} push_enable_enum;

typedef enum
{
    PUSH_SL_SETTING_NEVER = 0,
    PUSH_SL_SETTING_CONFIRM,
    PUSH_SL_SETTING_WITHOUT_CONFIRM
} push_sl_setting_enum;

typedef enum
{
    PUSH_TRUST_SETTING_DISABLE = 0,
    PUSH_TRUST_SETTING_ALWAYS,
    PUSH_TRUST_SETTING_ALWAYS_ASK
} push_trust_setting_enum;

typedef enum
{
    PUSH_ADD_NEW_TRUST_ENTRY = 1,
    PUSH_MODIFY_TRUST_ENTRY
} push_add_modify_trust_entry_enum;

typedef enum
{
    NEW_MSG_DEL_ID = 0,
    NEW_MSG_IDLE_SCR_DEL_ID,
    INBOX_MSG_DEL_ID,
    NEW_MSG_OPTION_DEL_ID,
    INVALID_MSG_INBOX_DEL_ID,
    PUSH_INIT_UNREAD_COUNT_ID,
    PUSH_MSG_DISPLAY_UNREAD_COUNT_ID,
    PUSH_INBOX_MSG_COUNT_ID,
    PUSH_NEW_MSG_PROCESS_ID,
    PUSH_SL_HIGH_UNREAD_COUNT_ID,
	PUSH_MSG_UPDATE_ID,
	SL_HIGH_UPDATE_ID,
	SL_HIGH_DISP_ID,
	GENERAL_MSG_ID,
	UM_LIST_MSG_COUNT_ID,
	UM_MSG_LIST_DEL_ID,
	PUSH_DELIND_UNREAD_COUNT_ID
} push_transID_enum;

typedef struct
{
  //  pBOOL push_msg_recv_flag;
    U16 enable_push_strid;
    U16 sl_setting_strid;
    U16 trust_setting_strid;
    U8 trust_addr_index;
    U8 trust_addr_count;
    U8 trust_address[(NVRAM_PUSH_ADDR_LEN_MAX + 1) *ENCODING_LENGTH];
    U8 trust_addr_type;
    U8 IP1[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 IP2[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 IP3[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 IP4[MAX_IP_ADDRES_LEN *ENCODING_LENGTH];
    U8 add_entry_flag;
    S32 push_msg_index;
    S32 push_msg_count;
    S32 unread_msg_count;
 //   S32 start_index;
//    S32 end_index;
 //   S32 num_item;
#ifdef __MMI_UNIFIED_MESSAGE__
    S16 um_msgID;
#endif 
    //      U8        start_index_entry;
    //      U8    last_index_entry;
    pBOOL arrived_service_msg;
	S32 unknown_addr_index;
} global_push_cntx;

typedef struct
{
    pmg_msg_list_struct data;
    /* S32 index; */
} global_push_inbox_msg_struct;


extern nvram_push_setting_struct *push_setting_data;
extern global_push_cntx g_push_cntx;

#define SI_DATE_N_TIME_STRING_LENGTH (62)
#define PUSH_MAX_MSG_BUFEER (25)
#define MAX_MSG_COUNT   (10)

#define MAX_PUSH_MSG WAP_PMG_MAX_PUSH_MESSAGES

#define MSG_SIZE_ADM       (sizeof(global_push_inbox_msg_struct) + 8)
#define PUSH_MAX_MEM_SIZE  ((MAX_PUSH_MSG*MSG_SIZE_ADM)+512)

/***** structure & macro's defined for service inbox dialogue ****/
typedef struct
{
    U8 title[WAP_PMG_DLG_MAX_TITLE_SIZE];    /* UCS2 string with zero-terminate */
    U8 content[WAP_PMG_DLG_MAX_CONTENT_SIZE]; 
    U8 items[WAP_PMG_DLG_MAX_SELECT_ITEMS][WAP_PMG_DLG_MAX_ITEM_TEXT_SIZE];  /* UCS2 string with zero-terminate */
    U32 numItems;
    U32 trans_id;
}push_service_dlg_struct;

typedef struct dlg_queue
{
	push_service_dlg_struct msgData;
	struct dlg_queue *next;
}push_dlg_queue_struct;


//#endif /* defined (JATAAYU_SUPPORT) */ // #if defined (JATAAYU_SUPPORT)
//#endif /* _JPROFILEHANDLERDEFS_H */ 

#endif
