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
 *  SMSApi.h
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

#ifndef _MMI_SMSAPI_H
#define _MMI_SMSAPI_H

typedef enum
{
    MMI_FRM_SMS_APP_NOBOX = 0x00,
    MMI_FRM_SMS_APP_UNREAD = 0x01,
    MMI_FRM_SMS_APP_INBOX = 0x02,
    MMI_FRM_SMS_APP_OUTBOX = 0x04,
    MMI_FRM_SMS_APP_DRAFTS = 0x08,
    MMI_FRM_SMS_APP_AWAITS = 0x10,
    MMI_FRM_SMS_APP_DATA = 0x20,
#ifdef __MMI_UNIFIED_MESSAGE__
    MMI_FRM_SMS_APP_UNSENT = 0x40,
#endif 
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    MMI_FRM_SMS_APP_ARCHIVE = 0x80, 
#endif
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    MMI_FRM_SMS_APP_SIM = 0x100,
#endif     
    MMI_FRM_SMS_APP_MSGBOX_END
} mmi_frm_sms_app_msgbox_enum; // TODO: smsnote: attension! if add more boxype, then many api should be modified! U8-->U16

typedef enum
{
    MMI_FRM_SMS_OK,
    MMI_FRM_SMS_ERROR,
    MMI_FRM_SMS_RETURN,
    MMI_FRM_SMS_END,
    MMI_FRM_SMS_ABORT,
    MMI_FRM_SMS_FDLFAIL,
    MMI_FRM_SMS_NUMEMPTY,
    MMI_FRM_SMS_NUMINVALID,
    MMI_FRM_SMS_DATAEMPTY,
    MMI_FRM_SMS_DATAINVALID,
    MMI_FRM_SMS_DATAEXCEED,
    MMI_FRM_SMS_MEMFULL,
    MMI_FRM_SMS_NOTREADY,
    MMI_FRM_SMS_SC_EMPTY,
    MMI_FRM_SMS_MEMINSUFFICIENT,
    MMI_FRM_SMS_END_FROM_SENDING,
    MMI_FRM_SMS_NOT_DELETE_SENDING
    
} mmi_frm_sms_result;

typedef enum
{
    MMI_FRM_SMS_SC = 0x01,
    MMI_FRM_SMS_DA = 0x02,
    MMI_FRM_SMS_FDL = 0x04,
    MMI_FRM_SMS_SCR = 0x08,
    MMI_FRM_SMS_NOT_ALLOW_EMPTY_SC = 0x10
} mmi_frm_sms_action_enum;

typedef enum
{
    MMI_FRM_SMS_PORT = 0x0001,
    MMI_FRM_SMS_CLASS = 0x0002,
    MMI_FRM_SMS_REPLY = 0x0004,
    MMI_FRM_SMS_SAVE = 0x0008,
    MMI_FRM_SMS_SAVE_AFTER_FAIL = 0x0010,
    MMI_FRM_SMS_RETURN_STRING = 0x0020,
    MMI_FRM_SMS_MORE = 0x0040,
    MMI_FRM_SMS_NUM_SCR = 0x0080,
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    MMI_FRM_SMS_BACKGROUND_SEND = 0x0100,
#endif
#ifdef __MMI_DUAL_SIM_MASTER__
	MMI_FRM_SMS_DISP_SIM_OPT = 0x0200,
#endif /* __MMI_DUAL_SIM_MASTER__ */

    MMI_FRM_SMS_SEND_ENUM_END
} mmi_frm_sms_send_enum;

typedef enum
{
#ifdef __MMI_UNIFIED_MESSAGE__
    MMI_FRM_SMS_SAVE_HIGHLIGHT_NEW_MSG_IND = 0x0001,        /* indicate UM on which message the highlight should be */
    MMI_FRM_SMS_SAVE_HIGHLIGHT_ORIGINAL_MSG_IND = 0x0002,   /* indicate UM on which message the highlight should be */
    MMI_FRM_SMS_SAVE_MODIFY_HIGHLIGHT = 0x0004,             /* modify g_msg_cntx.currBoxIndex if needed after saving message */
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    MMI_FRM_SMS_SAVE_DISPLAY_SAVING_SCREEN = 0x0008,    /* Set means displaying saving screen by SMS framework */
    MMI_FRM_SMS_SAVE_PORT = 0x0010,
    MMI_FRM_SMS_SAVE_CLASS = 0x0020,

    MMI_FRM_SMS_SAVE_ENUM_TOTAL
} mmi_frm_sms_save_enum;

typedef enum
{
    MMI_FRM_SMS_REQ_SEND,
    MMI_FRM_SMS_REQ_SAVE,
    MMI_FRM_SMS_REQ_TOTAL
} mmi_frm_sms_request_type_enum;

typedef enum
{
    MMI_FRM_SMS_ENTRY_WRITE_PORT = 0x0001,
    MMI_FRM_SMS_ENTRY_WRITE_CLASS = 0x0002,
    MMI_FRM_SMS_ENTRY_WRITE_REPLY = 0x0004,
    MMI_FRM_SMS_ENTRY_WRITE_END
} mmi_frm_sms_entry_write_enum;

typedef enum
{
    MMI_FRM_SMS_ABORT_WITH_FINISH_IND,
    MMI_FRM_SMS_ABORT_WITHOUT_FINISH_IND,
    
    MMI_FRM_SMS_ABORT_TOTAL
} mmi_frm_sms_abort_enum;

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
typedef enum
{
    MMI_FRM_SMS_APP_WAITING,
    MMI_FRM_SMS_APP_FAILTOSEND,
    MMI_FRM_SMS_APP_SENDING,
    
    MMI_FRM_SMS_APP_SEND_END
} mmi_frm_send_status_app_enum;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

typedef enum
{
   MMI_FRM_SMS_TYPE_NORMAL ,
   MMI_FRM_SMS_TYPE_CLASS0 ,
   MMI_FRM_SMS_TYPE_UPDATE_ONLY,
#ifdef __MMI_DUAL_SIM_MASTER__
   MMI_FRM_SMS_TYPE_CLASS0_SLAVE,
#endif

	MMI_FRM_SMS_TYPE_END   
} mmi_frm_display_type_enum;

typedef struct
{
    U16 srcport;
    U16 desport;
    U16 replyindex;
    U16 stringlength;

    U8 dcs;
    U8 dcs_class;
    U8 profile;
    U8 status;

    mmi_frm_sms_action_enum sendcheck;
    mmi_frm_sms_send_enum sendrequire;

    U8 number[21];
    S8 *filename;
    S8 *string;
} mmi_frm_sms_send_struct;

typedef struct
{
    U16 result;             /* mmi_frm_sms_app_msgbox_enum */
    U16 request_type;       /* mmi_frm_sms_request_type_enum */
    U8 number[21];          /* Optional. Destination phone number. Needed in send case. Must contain NULL terminator */
    BOOL display_popup;     /* TRUE to display popup. Please set TRUE in general cases */
    BOOL delete_sms_screen; /* TRUE to delete SMS framework screens in history.  Please set TRUE in general cases */
    /* Note: if is_display_pupup is FALSE, then current screen would not be deleted even if it belongs to SMS framwork screens because it is not in history.  */
} mmi_frm_sms_api_result_handler_struct;

typedef struct
{
    U16 srcport;
    U16 desport;
    mmi_frm_sms_entry_write_enum flag;
    U16 stringlength;
    S8 *string;
    S8 *filename;
    U8 dcs;
    U8 dcs_class;
    U8* ascii_addr; /* max number of digit is (MAX_DIGITS_SMS - 1). Must contain NULL terminator. */
} mmi_frm_sms_api_entry_write_struct;

typedef void (*PsFuncPtrU16) (void *, module_type, U16);
typedef U8(*PsFuncPtrFuncPtr) (void *, void *);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
typedef void (*PsFuncForArchPtr) (U16,  U16);  
#endif
#define MMI_FRM_SMS_INVALID_INDEX   0xffff
#define MMI_FRM_SMS_INVALID_NUM     0xff
#define MMI_FRM_SMS_LMS_TIME_OUT    1000*10
#define MMI_FRM_SMS_MSG_LEN         160
#define MMI_FRM_SMS_MAX_CONTROL_BUFFER_SIZE  2048

#ifdef __MMI_MESSAGES_COPY__
/* if segments of one concatenated message have different storage, 
   the storage of this message is determined by this value */
#define MMI_FRM_SMS_PREFER_STORAGE  SMSAL_SM
#endif /* __MMI_MESSAGES_COPY__ */ 

extern void mmi_frm_sms_get_phb_number(U8 name[], U8 number[]);
extern void mmi_frm_sms_get_phb_number_ext(S8* name, S8* number);
extern void mmi_frm_sms_reg_interrupt_check(module_type mod, U16 msgid, PsFuncPtrU16 callback);

extern void mmi_frm_sms_reg_msg_check(PsExtPeerIntFuncPtr action, PsFuncPtrFuncPtr callback);
extern void mmi_frm_sms_read_sms(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index, MMI_BOOL change_status);
extern void mmi_frm_sms_send_sms(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData);
/* this interface is only used by other mudule to send sms */
extern void mmi_frm_sms_send_sms_for_other_app(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData);
extern void mmi_frm_sms_get_sms(PsFuncPtrU16 callback, module_type mod_src, U16 index);
extern void mmi_frm_sms_save_sms(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData);
/* this interface is only used by other mudule to save sms */
extern void mmi_frm_sms_save_sms_for_other_app(PsFuncPtrU16 callback, module_type mod_src, mmi_frm_sms_send_struct *sendData);
extern void mmi_frm_sms_delete_sms(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index);
extern void mmi_frm_sms_delete_sms_by_bitmap(PsFuncPtrU16 callback, module_type mod_src, U8 *bitmap);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern U8 mmi_frm_sms_init_archive(void);
extern void mmi_frm_sms_delete_archive_folder(void);  
extern void mmi_frm_sms_move_to_archive(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index);
extern void mmi_frm_sms_delete_one_archive_msg_req(PsFuncPtrU16 callback, U16 type, U16 index);
extern void mmi_frm_sms_read_one_archive_msg(PsFuncForArchPtr callback,  U16 type, U16 index) ;
#endif

extern void mmi_frm_sms_reg_port(
                PsFuncPtrU16 callback,
                module_type mod_src,
                U16 port_num,
                BOOL enable,
                BOOL withdata,
                PsFuncPtrU16 regcallback);

extern U8 mmi_frm_sms_check_action_pending(void);
extern void mmi_frm_sms_delete_action_pending(void);
extern void mmi_frm_sms_delete_screen_history(void);
extern U8 mmi_frm_sms_check_complete(U16 type, U16 index);
extern U16 mmi_frm_sms_get_status(U16 type, U16 index);
extern U8 mmi_frm_sms_get_dcs(U16 type, U16 index);
extern U8 *mmi_frm_sms_get_address(U16 type, U16 index);
extern U8 *mmi_frm_sms_get_timestamp(U16 type, U16 index);
extern void mmi_frm_sms_get_list_index(U16 *type, U16 *index, U16 msgbox_index);
extern U8 mmi_frm_sms_get_sms_size(U16 type, U16 index);
extern U8 mmi_frm_sms_get_sms_received_size(U16 type, U16 index);
extern U16 mmi_frm_sms_get_sms_list_size(U16 type);
extern U8 mmi_frm_sms_get_data_check(U8 index);
extern void mmi_frm_sms_set_data_check(U8 index, U8 set);
extern void mmi_frm_sms_swap_list_index(U16 type, U16 index1, U16 index2);

#ifdef __MMI_MESSAGES_COPY__
extern U8 mmi_frm_sms_get_storage(U16 type, U16 index);
extern void mmi_frm_sms_copy_abort(void);
#endif /* __MMI_MESSAGES_COPY__ */ 
extern U8 mmi_frm_sms_check_awaited_complete_msg(U8 index);

extern void mmi_frm_sms_init_msgbox(void);
extern void mmi_frm_sms_set_profile_active(PsFuncPtrU16 callback, module_type mod_src, U8 *index);
extern void mmi_frm_sms_get_profile_list(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_get_sc_addr(PsFuncPtrU16 callback, module_type mod_src, U8 index);
extern void mmi_frm_sms_set_sc_addr(PsFuncPtrU16 callback, module_type mod_src, U8 index, S8 scAddr[]);
extern void mmi_frm_sms_get_profile_detail(PsFuncPtrU16 callback, module_type mod_src, U8 index);
extern void mmi_frm_sms_set_profile_detail(PsFuncPtrU16 callback, module_type mod_src, void *profile);
extern void mmi_frm_sms_get_common_settings(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_set_common_settings(PsFuncPtrU16 callback, module_type mod_src, U8 *setting);

#ifdef __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__
extern void mmi_frm_sms_get_memory_status(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_get_preferred_storage(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_set_preferred_storage(PsFuncPtrU16 callback, module_type mod_src, U8 storage);
#endif /* __MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__ */ 
#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
extern void mmi_frm_sms_get_preferred_bearer(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_set_preferred_bearer(PsFuncPtrU16 callback, module_type mod_src, U8 bearer);
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 
extern void mmi_frm_sms_get_mailbox_info(PsFuncPtrU16 callback, module_type mod_src);
extern void mmi_frm_sms_set_mailbox_info(PsFuncPtrU16 callback, module_type mod_src, void *mailbox);

#ifdef __MMI_MESSAGES_COPY__
extern void mmi_frm_sms_copy_sms(
                PsFuncPtrU16 callback,
                module_type mod_src,
                U16 type,
                U16 index,
                U8 action,
                U8 dst_storage);
#endif /* __MMI_MESSAGES_COPY__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
extern kal_bool mmi_frm_sms_get_content(
                    kal_uint16 msg_box_type,
                    kal_uint16 msg_list_index,
                    kal_wchar *content,
                    kal_uint8 max_subject_len);
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

extern BOOL mmi_frm_sms_check_dst_number(U8 *num, U8 numLen);
extern BOOL mmi_frm_sms_is_in_sim_refresh(void);
extern void mmi_frm_sms_api_result_handler(mmi_frm_sms_api_result_handler_struct *result);
extern void mmi_frm_sms_api_entry_write_msg(mmi_frm_sms_api_entry_write_struct *data);

extern void mmi_frm_sms_handle_extension_char(U16 *dstBuffer, U16 *srcBuffer, U16 charNum);
extern BOOL mmi_frm_sms_check_UCS2(U16 *buffer, U16 charNum);
extern U32 mmi_frm_sms_count_extension_char(U16 *buff, U32 char_num);

extern void mmi_frm_sms_init(void);

extern void InitEMSDataStruct(void);
extern void DeInitEMSDataStruct(void);
extern void ReleaseEMSViewBuffer(void);
extern void ReleaseEMSEditBuffer(void);
extern U8 CopyEMSViewToEditBuffer(void);

extern void mmi_frm_sms_remove_escape_symbol_for_extension_char(U16 *dstBuf, U16 *srcBuf, U16 charNum);
extern void mmi_frm_sms_add_escape_symbol_for_extension_char(U16 *dstBuf, U16 *srcBuf, U16 charNum);
extern void mmi_frm_sms_abort_sending_sms(mmi_frm_sms_abort_enum type);

extern BOOL mmi_frm_sms_fill_in_edit_buffer(U8* buffer, U16 char_num, U8 dcs, BOOL is_reset);

extern BOOL mmi_frm_sms_is_hide_send_sms_menu_item(void);
extern BOOL mmi_frm_sms_is_sms_valid(void);

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
extern void mmi_frm_sms_set_unsent_status(PsFuncPtrU16 callback,kal_uint16 index, mmi_frm_send_status_app_enum send_status);
extern U8 mmi_frm_sms_get_unsent_status(kal_uint16 index);
extern void mmi_frm_sms_move_sms_to_otherbox(PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index, U8 dst_type);
extern void mmi_frm_sms_background_send_schedule(void);
extern mmi_frm_sms_result mmi_frm_sms_set_background_save_setting(BOOL isSave);
extern void mmi_frm_sms_get_background_save_setting(BOOL *isSave);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#if defined(__MMI_DUAL_SIM_MASTER__)
extern void mmi_frm_sms_dm_delete_sms(U8 side, PsFuncPtrU16 callback, module_type mod_src, U16 type, U16 index);
extern BOOL mmi_frm_msg_is_from_master_sim(U16 list_index);
extern BOOL mmi_frm_msg_is_from_master_sim_by_l4_index(U16 l4_index);
extern BOOL mmi_frm_msg_is_from_master_sim_by_msgbox_index(U16 type, U16 index);

extern void mmi_frm_sms_reg_port_for_slave(
                PsFuncPtrU16 callback,
                module_type mod_src,
                U16 port_num,
                BOOL enable,
                BOOL withdata,
                PsFuncPtrU16 regcallback);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* _MMI_SMSAPI_H */ 

