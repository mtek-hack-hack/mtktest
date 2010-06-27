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
 * UnifiedMessageGProt.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines global enum, constant and prototypes for Unified Message
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_UNIFIED_MESSAGE_GPROT_H
#define _MMI_UNIFIED_MESSAGE_GPROT_H

//#include "MMIDataType.h"
//#include "UnifiedMessageResDef.h"

#ifdef __MMI_UNIFIED_MESSAGE__

#define MMI_UM_MAX_GET_LIST_MSG_NUMBER (100)
#define MMI_UM_MAX_GET_MSG_INFO_NUMBER (9)
#define MMI_UM_MAX_ADDR_LEN   (60)
#define MMI_UM_MAX_SUBJECT_LEN   (40)

typedef enum
{
    UM_MSG_BOX_TYPE_INBOX = 0x01,
    UM_MSG_BOX_TYPE_UNSENT = 0x02,
    UM_MSG_BOX_TYPE_SENT = 0x04,
    UM_MSG_BOX_TYPE_DRAFT = 0x08,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    UM_MSG_BOX_TYPE_ARCHIVE = 0x10,
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    UM_MSG_BOX_TYPE_PREDEF_TEMPLATES = 0x20,  /* __MMI_MMS_2__ MMS folder */
    UM_MSG_BOX_TYPE_USRDEF_TEMPLATES = 0x40,  /* __MMI_MMS_2__ MMS folder */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    UM_MSG_BOX_TYPE_SIM = 0x80,
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    UM_MSG_BOX_TYPE_END
} UmMsgBoxType;

typedef enum
{
    UM_STATE_IDLE,
    UM_STATE_ENTRY_MAIN_MENU,
    UM_STATE_ENTRY_WRTIE_MSG,
    UM_STATE_ENTRY_TEMPLATE,
    UM_STATE_ENTRY_DELETE_FOLDER,
    UM_STATE_ENTRY_SETTING,
    UM_STATE_ENTRY_INBOX,
    UM_STATE_ENTRY_UNSENT,
    UM_STATE_ENTRY_SENT,
    UM_STATE_ENTRY_DRAFT,
    UM_STATE_ENTRY_NEW_MSG_IND,
    UM_STATE_ENTRY_ARCHIVE,
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    UM_STATE_ENTRY_SIM,
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    UM_STATE_ENTRY_END
} um_state_type_enum;

typedef enum
{
    UM_MSG_TYPE_SMS = 0x01,
    UM_MSG_TYPE_MMS = 0x02,
    UM_MSG_TYPE_WAP_PUSH = 0x04
} UmMsgType;

typedef enum
{
    UM_ADDR_TYPE_PHONE_NUMBER,
    UM_ADDR_TYPE_EMAIL_ADDRESS
} UmAddrType;

typedef struct
{
    kal_uint32 timestamp;
    kal_uint16 msg_index;
} mmi_um_list_info_struct;

typedef struct
{
    kal_uint16 msg_index;                           /* message index */
    kal_uint32 timestamp;                           /* message timestamp array */
    UmAddrType address_type;
    kal_uint8 address_length;                       /* Number of characters in address string */
    kal_wchar address[MMI_UM_MAX_ADDR_LEN + 1];     /* sender address for MT msg; receiver address for MO msg */
    kal_uint8 subject_length;                       /* Number of characters in subject string */
    kal_wchar subject[MMI_UM_MAX_SUBJECT_LEN + 1];  /* subject for MMS, WAP Push and E-mai; part of content for SMS */
    kal_uint16 icon_id;
} mmi_um_msg_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    UmMsgType msg_type;  /* Type of message */
} mmi_um_generic_req_struct;

typedef struct
{
    LOCAL_PARA_HDR kal_bool result; /* KAL_TRUE means ready; KAL_FALSE means initialization failure */
    UmMsgType msg_type;             /* Type of ready message */
} mmi_um_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    UmMsgType msg_type;  /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */        
} mmi_um_get_msg_num_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool result; /* KAL_TRUE means OK; KAL_FALSE means failed */
    UmMsgType msg_type;             /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
    kal_uint16 inbox_unread_msg_number;
    kal_uint16 inbox_read_msg_number;
    kal_uint16 unsent_msg_number;
    kal_uint16 sent_msg_number;
    kal_uint16 draft_msg_number;
    kal_uint16 predefined_template_msg_number;
    kal_uint16 userdefined_template_msg_number; 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    kal_uint16 archive_msg_number;
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    kal_uint16 sim_msg_number;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
} mmi_um_get_msg_num_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR     
    UmMsgType msg_type;  /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    UmMsgBoxType msg_box_type;          /* Type of message box */
    kal_uint16 start_entry;             /* From which entry to get list info. Start from 0 */
} mmi_um_get_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR     
    kal_bool result; /* KAL_TRUE means OK; KAL_FALSE means failed */
    UmMsgType msg_type;             /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    UmMsgBoxType msg_box_type;      /* Type of message box */
    kal_uint16 start_entry;         /* The first entry number in this response primitive */
    kal_uint16 msg_number;          /* Number of messages in this response primitive */

    mmi_um_list_info_struct list_info[MMI_UM_MAX_GET_LIST_MSG_NUMBER];  /* List info array */

    kal_bool more;  /* If there are more msgs besides this response primitive */
} mmi_um_get_list_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    UmMsgType msg_type;  /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    UmMsgBoxType msg_box_type;          /* Type of message box */
    kal_uint16 start_entry;             /* From which entry to get msg info. Start from 0 */
    kal_uint16 msg_number;              /* Number of messages to get info */
} mmi_um_get_msg_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool result; /* KAL_TRUE means OK; KAL_FALSE means failed */
    UmMsgType msg_type;             /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    UmMsgBoxType msg_box_type;      /* Type of message box */
    kal_uint16 start_entry;         /* The first entry number in this response primitive */
    kal_uint16 msg_number;          /* Number of messages in this response primitive */
    mmi_um_msg_info_struct msg_info[MMI_UM_MAX_GET_MSG_INFO_NUMBER];    /* Message info array */
} mmi_um_get_msg_info_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    UmMsgType msg_type;  /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    UmMsgBoxType msg_box_type;          /* Types of message boxes to delete; bit mask */    
} mmi_um_delete_folder_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    UmMsgType msg_type;  /* Type of message */
    kal_uint32 app_id; /* application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */    
    kal_bool result;                    /* KAL_TRUE means all msgs are deleted successfully; Otherwise KAL_FALSE */
} mmi_um_delete_folder_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR UmMsgType msg_type;  /* Type of message */
    UmMsgBoxType msg_box_type;          /* Types of message boxes */
    kal_uint16 msg_index;
    kal_uint32 timestamp;
} mmi_um_new_msg_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR UmMsgType msg_type;  /* Type of message */
    UmMsgBoxType msg_box_type;          /* Types of message boxes */
    kal_uint16 msg_index;
} mmi_um_highlight_msg_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR UmMsgType msg_type;  /* Type of message */
    UmMsgBoxType msg_box_type;          /* Types of message boxes */
    kal_uint16 msg_index;
} mmi_um_highlight_decided_by_UM_struct;


typedef struct
{
    LOCAL_PARA_HDR UmMsgType msg_type;  /* Type of message */
    UmMsgBoxType msg_box_type;          /* Types of message boxes */
} mmi_um_refresh_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR UmMsgType msg_type;  /* Type of message */
    UmMsgBoxType msg_box_type;          /* Types of message boxes to delete; bit mask */
} mmi_um_delete_all_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR UmMsgType msg_type;  /* Type of message */
    kal_bool result;                    /* KAL_TRUE means all msgs are deleted successfully; Otherwise KAL_FALSE */
} mmi_um_delete_all_res_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    UmMsgType msg_type;         /* Type of message */
    UmMsgBoxType msg_box_type;  /* Types of message boxes only support UM_MSG_BOX_TYPE_INBOX in current design. */
} mmi_um_cancel_new_msg_ind_struct;

//typedef struct mmi_um_delete_folder_req_struct mmi_um_delete_all_ind_struct;
//typedef struct mmi_um_delete_folder_rsp_struct mmi_um_delete_all_res_struct;

extern void mmi_um_highlight_main_menu(void);
extern void mmi_um_init(void);
extern void mmi_um_ready_ind(kal_bool result, UmMsgType msg_type);

extern void mmi_um_skip_write_menu(kal_bool operation);
extern void mmi_um_new_msg_ind(
                UmMsgType msg_type,
                UmMsgBoxType msg_box_type,
                kal_uint16 msg_index,
                kal_uint32 timestamp);
extern void mmi_um_highlight_msg_ind(UmMsgType msg_type, UmMsgBoxType msg_box_type, kal_uint16 msg_index);
extern void mmi_um_highlight_decided_by_um_ind(UmMsgType msg_type, UmMsgBoxType msg_box_type, kal_uint16 msg_index);
extern void mmi_um_set_highlight_msg(kal_uint16 list_index);
extern kal_uint8 mmi_um_check_new_msg(void);
extern void mmi_um_pre_entry_new_msg_ind(void);
extern UmMsgBoxType mmi_um_get_current_msg_box_type(void);
extern kal_bool mmi_um_is_available(void);
extern void mmi_um_on_enter_idle_screen(void);
extern void mmi_um_handle_sim_refresh(UmMsgType msg_type, kal_uint8 popup_displayed);
extern kal_bool mmi_um_check_ready(void);
extern kal_bool mmi_um_is_sending_num_msg(void);
extern kal_uint16 mmi_um_get_not_available_string_id(void);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 
#endif /* _MMI_UNIFIED_MESSAGE_GPROT_H */ 

