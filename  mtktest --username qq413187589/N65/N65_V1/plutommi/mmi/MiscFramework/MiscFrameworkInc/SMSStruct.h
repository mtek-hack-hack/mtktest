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
 *  SMSStruct.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMI_SMSSTRUCT_H
#define _MMI_SMSSTRUCT_H

typedef enum
{
    MMI_FRM_SMS_INDEX,
    MMI_FRM_SMS_FILE,
    MMI_FRM_SMS_EMSDATA,
    MMI_FRM_SMS_STRING
} mmi_frm_sms_datatype_enum;

typedef enum
{
    MMI_FRM_SMS_NOBOX = 0x00,
    MMI_FRM_SMS_UNREAD = 0x01, //unread 
    MMI_FRM_SMS_INBOX = 0x02,  //read
    MMI_FRM_SMS_OUTBOX = 0x04,
    MMI_FRM_SMS_DRAFTS = 0x08,
    MMI_FRM_SMS_AWAITS = 0x10,
    MMI_FRM_SMS_DATA = 0x20,
#ifdef __MMI_UNIFIED_MESSAGE__
    MMI_FRM_SMS_UNSENT = 0x40,
#endif 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    MMI_FRM_SMS_ARCHIVE = 0x80, 
#endif   
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    MMI_FRM_SMS_SIM = 0x100,
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    MMI_FRM_SMS_MSGBOX_END
} mmi_frm_sms_msgbox_enum;

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
typedef enum
{
    MMI_FRM_SMS_WAITING,
    MMI_FRM_SMS_FAILTOSEND,
    MMI_FRM_SMS_SENDING,
    /* Only used as fresh list */
    MMI_FRM_SMS_SUCTOSEND,
    
    MMI_FRM_SMS_SEND_END
} mmi_frm_sms_send_status_enum;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

typedef struct
{
    module_type mod_src;

    /* pointer to index, file path, EMS data or string
       the action shall know the type itself and cast to the proper structure */
    void *data;

    /* the function to be excuted */
    PsFuncPtr action;

    /* callback for action */
    PsFuncPtrU16 callback;
} mmi_frm_sms_action_struct;

typedef struct
{
    /* the function to be excuted */
    PsExtPeerIntFuncPtr action;

    /* callback for action, return TRUE for update SMS list */
    PsFuncPtrFuncPtr callback;
} mmi_frm_sms_msg_check_struct;

typedef struct
{
    module_type module;

    U16 desport;

    U16 serial;

    BOOL withdata;
	BOOL enable;
	
#ifdef __MMI_DUAL_SIM_MASTER__
	BOOL isSlave;
#endif

    PsFuncPtrU16 callback;
} mmi_frm_sms_data_check_struct;

typedef struct
{
    /* TRUE: success, FALSE: fail */
    U8 result;

    /* contain return data */
    void *data;
} mmi_frm_sms_result_struct;

typedef struct
{
    U16 msgid;

    /* indication destination module */
    U16 molude;

    /* indication check function */
    /* callback for action */
    PsFuncPtrU16 callback;
} mmi_frm_sms_register_struct;

typedef struct
{
    U8 segment;
    U8 nextindex;
    U16 msglen;
    void *data;
} mmi_frm_sms_content_struct;

typedef struct
{
    U16 ref;        /* concat. message reference */
    U8 total_seg;   /* total segments */
    U8 seg;         /* indicate which segment */
} mmi_frm_sms_concat_struct;

typedef struct
{
    U8 startup_seq_num;
    U8 mti;
    U8 status;
    U8 fo;
    U16 index;
    U8 scts[7];
    l4c_number_struct addr_number;
    U8 pid;
    U8 dcs;
    U8 ori_dcs;
    U8 vp;
    U8 mr;
    U8 dt[7];
    U8 st;
    U32 concat_info;
    U16 no_msg_data;
    U8 msg_data[1];
} mmi_frm_sms_startup_read_struct;

typedef struct
{
    U8 fo;
    U8 scts[7];
    l4c_number_struct sca_number;
    l4c_number_struct addr_number;
    U8 pid;
    U8 dcs;
    U8 ori_dcs;
    U16 index;      /* for awaited message, this is the start index */
    U16 dest_port;
    U16 src_port;
    U8 mti;
    U8 display_type;
#ifdef __MMI_MESSAGES_COPY__
    U8 storageType;
#endif 
    U32 concat_info;
    U16 no_msg_data;
    U8 msg_data[1]; /* for awaited message, this is the first segment data */
} mmi_frm_sms_deliver_msg_struct;

typedef struct
{
    U16 dest_mod_id;
    U16 dest_port;
    U16 src_port;
    U8 dcs;
    U8 mti;
    U16 message_len;
    U32 concat_info;
    l4c_number_struct oa;
    U8 scts[7];
#ifdef __MMI_DUAL_SIM_MASTER__
	BOOL isSlave;
#endif
    U8 data[1];
} mmi_frm_sms_deliver_data_struct;

typedef struct
{
    LOCAL_PARA_HDR U16 port_number;
    U8 serial;
    smsal_dcs_enum dcs;
    U8 *data;
} mmi_frm_sms_data_ind_struct;

typedef struct
{
    U8 mmi_frm_sms_ready;
    U8 mmi_frm_sms_number[(MAX_DIGITS_SMS + 1) *ENCODING_LENGTH];
    U16 mmi_frm_sms_msg_box_size;
    U16 mmi_frm_sms_msg_seg_size;
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    BOOL mmi_frm_sms_delivery_report_setting;       /* If deliver report turn on or off */
    BOOL mmi_frm_sms_delivery_report_temp_setting;  /* If deliver report turn on or off */
#ifdef __MMI_DUAL_SIM_MASTER__
    BOOL mmi_frm_sms_slave_delivery_report_setting;       /* If slave deliver report turn on or off */
    BOOL mmi_frm_sms_slave_delivery_report_temp_setting;  /* If slave deliver report turn on or off */
#endif /* __MMI_DUAL_SIM_MASTER__ */ 
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 
    BOOL is_aborting;
} mmi_frm_sms_context_struct;

typedef struct
{
    U16 serial;
    U8 *message;
    U16 dest_port;
    U16 src_port;
    U16 message_len;
    module_type mod_dest;
    mmi_frm_sms_concat_struct concat_info;
    l4_addr_bcd_struct oa;
    U8 scts[7];
    U8 used;
    U8 dcs;
    BOOL is_checked;
} mmi_frm_sms_pool_struct;

typedef struct
{
    U8 *pMailBoxName[2];
    U8 *pMailBoxNumber[2];
    U8 mailboxNameDcs[2];
    U8 mailboxNameLength;
    U8 mailboxNumber;
} mmi_frm_sms_mailbox_struct;

#ifdef __MMI_MESSAGES_COPY__
typedef struct
{
    U16 total_msg_number;   /* inbox/outbox list size OR 1 */
    U16 handled_msg_number; /* number of handled message */
    U16 copy_msg_number;    /* number of copied message */
    U16 msg_list_type;       /* inbox or outbox */
    U16 present_msg_index;  /* inbox/outbox list index */
    U16 present_L4_index;   /* L4 index */
    U8 dst_storage;         /* destination storage */
    U8 action;              /* smsal_copy_action_enum */

    U16 dst_msg_index;  /* new message box index */

    BOOL is_aborted;        /* true if user request to abort */
    BOOL is_memory_full;    /* true if any msg cannot be copied due to lack of storage */

} mmi_frm_sms_copy_info_struct;

typedef struct
{
    U16 msg_number; /* number of message successfully copied/moved */
    U8 cause;       /* error cause */
} mmi_frm_sms_copy_result_struct;
#endif /* __MMI_MESSAGES_COPY__ */ 

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
typedef struct
{
    U8 mr;          /* message reference (segment id) */
    U8 check_bit;   /* if delivery report of this segment received */
} mmi_frm_sms_delivery_report_box_struct;

typedef struct
{
    U8 result;      /* smsal_st_enum */
    U16 ref;        /* reference number */
    U8 box_number;  /* number of mmi_frm_sms_delivery_report_box */
    mmi_frm_sms_delivery_report_box_struct *ptr;
} mmi_frm_sms_delivery_report_list_struct;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */ 

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
typedef enum
{
    MMI_FRM_SMS_SEND_STATE_IDLE,
    MMI_FRM_SMS_SEND_STATE_SENDING,
    MMI_FRM_SMS_SEND_STATE_SUSPEND,
    
    MMI_FRM_SMS_SEND_STATE_END
} mmi_frm_sms_background_send_state_enum;

typedef struct
{
    /* the following variable are used to handle change the status of message */
    U16 msgType;
    U8 dst_status;
    U16 cur_l4_index;

    /* the following variable are used to handle the message background send */
    U16 l4_index;
    U8 background_state;
    U8 foreground_state;
	U8 isBackground;
	
	/* the following vp and sc_addr are used to send the message*/
	U8	vp;
	l4c_number_struct	sc_addr;

} mmi_frm_sms_background_send_info_struct;

extern mmi_frm_sms_background_send_info_struct g_frm_sms_background_send_info;

#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

typedef struct
{	
	U8	fo;
	U8	scts[7];
	U8	dt[7];
	l4c_number_struct	ra_number;
	U8	st; /* smsal_st_enum */
	U8	pid; /* smsal_pid_enum */
	U8	dcs; /* smsal_dcs_enum */
	U8	mr;
	U8	no_msg_data;
#ifdef __MMI_DUAL_SIM_MASTER__
	U8  isFromMaster;
#endif /* __MMI_DUAL_SIM_MASTER__ */
	U8	msg_data[1];
} mmi_frm_sms_status_report_ind_struct;

extern mmi_frm_sms_context_struct g_frm_sms_cntx;

#ifdef __MMI_MESSAGES_COPY__
extern mmi_frm_sms_copy_info_struct g_frm_sms_copy_info;
#endif 

#define MMI_FRM_SMS_FDN_CHECK_REQ_STRUCT  mmi_phb_sms_fdn_check_req_struct
#define MMI_FRM_SMS_FDN_CHECK_RSP_STRUCT  mmi_phb_sms_fdn_check_rsp_struct

#define MMI_FRM_SMS_GET_PROFILE_NUM_RSP_STRUCT     mmi_sms_get_profile_num_rsp_struct
#define MMI_FRM_SMS_SET_PROFILE_PARAMS_REQ_STRUCT  mmi_sms_set_profile_params_req_struct
#define MMI_FRM_SMS_SET_PROFILE_PARAMS_RSP_STRUCT  mmi_sms_set_profile_params_rsp_struct
#define MMI_FRM_SMS_GET_PROFILE_PARAMS_REQ_STRUCT  mmi_sms_get_profile_params_req_struct
#define MMI_FRM_SMS_GET_PROFILE_PARAMS_RSP_STRUCT  mmi_sms_get_profile_params_rsp_struct
#define MMI_FRM_SMS_SET_COMMON_PARAMS_REQ_STRUCT   mmi_sms_set_common_params_req_struct
#define MMI_FRM_SMS_SET_COMMON_PARAMS_RSP_STRUCT   mmi_sms_set_common_params_rsp_struct
#define MMI_FRM_SMS_GET_COMMON_PARAMS_RSP_STRUCT   mmi_sms_get_common_params_rsp_struct
#define MMI_FRM_SMS_GET_MSG_NUM_RSP_STRUCT         mmi_sms_get_msg_num_rsp_struct
#define MMI_FRM_SMS_SET_PREFERRED_STORAGE_REQ_STRUCT  mmi_sms_set_preferred_storage_req_struct
#define MMI_FRM_SMS_SET_PREFERRED_STORAGE_RSP_STRUCT  mmi_sms_set_preferred_storage_rsp_struct
#define MMI_FRM_SMS_GET_PREFERRED_STORAGE_RSP_STRUCT  mmi_sms_get_preferred_storage_rsp_struct
#define MMI_FRM_SMS_SET_MAILBOX_ADDRESS_REQ_STRUCT mmi_sms_set_mailbox_address_req_struct
#define MMI_FRM_SMS_SET_MAILBOX_ADDRESS_RSP_STRUCT mmi_sms_set_mailbox_address_rsp_struct
#define MMI_FRM_SMS_GET_MAILBOX_ADDRESS_RSP_STRUCT mmi_sms_get_mailbox_address_rsp_struct

#define MMI_FRM_SMS_DEL_MSG_REQ_STRUCT mmi_sms_del_msg_req_struct
#define MMI_FRM_SMS_DEL_MSG_RSP_STRUCT mmi_sms_del_msg_rsp_struct
#define MMI_FRM_SMS_GET_MSG_REQ_STRUCT mmi_sms_get_msg_req_struct
#define MMI_FRM_SMS_GET_MSG_RSP_STRUCT mmi_sms_get_msg_rsp_struct
#define MMI_FRM_SMS_SET_MSG_REQ_STRUCT mmi_sms_set_msg_req_struct
#define MMI_FRM_SMS_SET_MSG_RSP_STRUCT mmi_sms_set_msg_rsp_struct
#define MMI_FRM_SMS_SEND_MSG_REQ_STRUCT   mmi_sms_send_msg_req_struct
#define MMI_FRM_SMS_SEND_MSG_RSP_STRUCT   mmi_sms_send_msg_rsp_struct
#define MMI_FRM_SMS_ABORT_RSP_STRUCT   mmi_sms_abort_rsp_struct
#define MMI_FRM_SMS_SEND_ABORT_FINISH_IND_STRUCT   mmi_sms_send_abort_finish_ind_struct

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ 
#define MMI_FRM_SMS_SET_MSG_STATUS_REQ_STRUCT    mmi_sms_set_status_req_struct
#define MMI_FRM_SMS_SET_MSG_STATUS_CNF_STRUCT    mmi_sms_set_status_rsp_struct
#define MMI_FRM_SMS_SEND_MSG_BY_STORAGE_REQ_STRUCT   mmi_sms_send_from_storage_req_struct
#define MMI_FRM_SMS_SEND_MSG_BY_STORAGE_RSP_STRUCT   mmi_sms_send_from_storage_rsp_struct
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#ifdef __MMI_MESSAGES_COPY__
#define MMI_FRM_SMS_COPY_MSG_REQ_STRUCT   mmi_sms_copy_msg_req_struct
#define MMI_FRM_SMS_COPY_MSG_RSP_STRUCT   mmi_sms_copy_msg_rsp_struct
#endif /* __MMI_MESSAGES_COPY__ */ 

#define MMI_FRM_SMS_STARTUP_READ_NEXT_RSP_STRUCT   mmi_sms_startup_read_next_rsp_struct
#define MMI_FRM_SMS_STARTUP_READ_MSG_IND_STRUCT mmi_sms_startup_read_msg_ind_struct
#define MMI_FRM_SMS_READY_IND_STRUCT      mmi_sms_ready_ind_struct
#define MMI_FRM_SMS_SYNC_MSG_IND_STRUCT      mmi_sms_sync_msg_ind_struct
#define MMI_FRM_SMS_REG_PORT_NUM_REQ_STRUCT  mmi_sms_reg_port_num_req_struct
#define MMI_FRM_SMS_REG_PORT_NUM_RSP_STRUCT  mmi_sms_reg_port_num_rsp_struct
#define MMI_FRM_SMS_DELIVER_MSG_IND_STRUCT      mmi_sms_deliver_msg_ind_struct
#define MMI_FRM_SMS_STATUS_REPORT_IND_STRUCT mmi_sms_status_report_ind_struct
#define MMI_FRM_SMS_MEM_FULL_IND_STRUCT            mmi_sms_mem_full_ind_struct
#define  MMI_FRM_SMS_MEM_EXCEED_IND_STRUCT         mmi_sms_mem_exceed_ind_struct
#define  MMI_FRM_SMS_MEM_AVAILABLE_IND_STRUCT      mmi_sms_mem_available_ind_struct
#define MMI_FRM_SMS_APP_DATA_IND_STRUCT      mmi_sms_app_data_ind_struct
#define MMI_FRM_SMS_MSG_WAITING_IND_STRUCT   mmi_sms_msg_waiting_ind_struct

#define MMI_FRM_CB_MSG_IND_STRUCT   mmi_cb_msg_ind_struct
#define MMI_FRM_CB_SUBSCRIBE_REQ_STRUCT   mmi_cb_subscribe_req_struct
#define MMI_FRM_CB_SUBSCRIBE_RSP_STRUCT   mmi_cb_subscribe_rsp_struct
#define MMI_FRM_CB_SET_CB_MODE_REQ_STRUCT mmi_sms_set_cb_mode_req_struct
#define MMI_FRM_CB_SET_CB_MODE_RSP_STRUCT mmi_sms_set_cb_mode_rsp_struct
#define MMI_FRM_CB_GET_CB_MODE_RSP_STRUCT mmi_sms_get_cb_mode_rsp_struct

#ifdef __MMI_MESSAGES_USE_URL__
#define MMI_FRM_SMS_WAP_BROWSER_STARTUP_REQ  wap_browser_startup_req_struct
#endif 

#endif /* _MMI_SMSSTRUCT_H */ 

