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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  MMSBGSRGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file global API's Variables  and the context for MMS BGSR Application
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
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_BGSR_GPROT_H_
#define __MMI_BGSR_GPROT_H_

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_features.h"

#include "wapadp.h"
#include "mmsadp.h"
#include "custom_wap_config.h"

/* Dummy API's Start */

/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_MMS_BGSR_CALLBACK_NUM 1
#define MMI_MMS_BGSR_TOTAL_SOLUTION_NUM 2
#define MMI_MMS_BGSR_CFG_RETRY_QUOTA 2          /* can be customized */
#define MMI_MMS_BGSR_MAX_RSP_TEXT_LEN 40
#define MMI_MMS_BGSR_CFG_RETRY_TIMER 1          
#define MMI_MMS_BGSR_POPUP_TIME 2000
#define MMI_MMS_BGSR_FAST_TIMEOUT_TIMER 5000 /* in ms*/
/***************************************************************************** 
* Typedef
*****************************************************************************/

typedef enum
{
    MMI_MMS_BGSR_STATUS_WAITING_FOR_SEND,
    MMI_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD,        
    MMI_MMS_BGSR_STATUS_SENDING,
    MMI_MMS_BGSR_STATUS_SEND_FAIL,
    MMI_MMS_BGSR_STATUS_DOWNLOADING,        
    MMI_MMS_BGSR_STATUS_DOWNLOAD_FAIL,
    MMI_MMS_BGSR_STATUS_DEFERRED_FOR_SEND,
    MMI_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD,
    MMI_MMS_BGSR_STATUS_SAVING,
    MMI_MMS_BGSR_STATUS_DELETING,    
    MMI_MMS_BGSR_STATUS_TOTAL
} mmi_mms_bgsr_msg_status_enum;

typedef enum
{
    MMI_MMS_BGSR_FOLDER_INBOX,
    MMI_MMS_BGSR_FOLDER_OUTBOX,
    MMI_MMS_BGSR_FOLDER_TOTAL
} mmi_mms_bgsr_msg_box_enum;

typedef enum
{
    MMI_MMS_BGSR_SETTING_SEND_ONLY,
    MMI_MMS_BGSR_SETTING_SAVE_AND_SEND,
    MMI_MMS_BGSR_SETTING_TOTAL
} mmi_mms_bgsr_send_setting_enum;

typedef enum
{
    MMI_MMS_BGSR_OP_NOT_USED,
    MMI_MMS_BGSR_OP_DELETE,
    MMI_MMS_BGSR_OP_MOVE_TO_FOLDER,
    MMI_MMS_BGSR_OP_FORMAT,
    MMI_MMS_BGSR_OP_DELETE_ALL_INBOX,
    MMI_MMS_BGSR_OP_DELETE_ALL_OUTBOX,    
    MMI_MMS_BGSR_OP_CANCEL_ALL_INBOX,
    MMI_MMS_BGSR_OP_CANCEL_ALL_OUTBOX,    
    MMI_MMS_BGSR_OP_TOTAL    
} mmi_mms_bgsr_msg_operation_notify_enum;

typedef enum
{
    MMI_MMS_BGSR_INTERRUPT_CALL             = 0x01,
    MMI_MMS_BGSR_INTERRUPT_USB              = 0x02,
    MMI_MMS_BGSR_INTERRUPT_FLIGHT_MODE      = 0x04,
    MMI_MMS_BGSR_INTERRUPT_WAP_RESET        = 0x08,
    MMI_MMS_BGSR_INTERRUPT_TOTAL            = 0xFF
} mmi_mms_bgsr_interrupt_reason_enum;

typedef enum
{
    MMI_MMS_BGSR_RESULT_NOT_USED,                                   /*0*/
    MMI_MMS_BGSR_RESULT_OK,                                         /*1*/
    MMI_MMS_BGSR_RESULT_FAIL,                                       /*2*/
    MMI_MMS_BGSR_RESULT_FAIL_INCALL,                                /*3*/
    MMI_MMS_BGSR_RESULT_FAIL_NOT_READY,                             /*4*/
    MMI_MMS_BGSR_RESULT_FAIL_BUSY,                                  /*5*/
    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY,                   /*6*/
    MMI_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE,                  /*7*/
    MMI_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND,                        /*8*/
    MMI_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED,                        /*9*/
    MMI_MMS_BGSR_RESULT_FAIL_FILE_IN_USE,                           /*10*/
    MMI_MMS_BGSR_RESULT_FAIL_FILE_IO,                               /*11*/
    MMI_MMS_BGSR_RESULT_FAIL_FOLDER_NOT_FOUND,                      /*12*/
    MMI_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT,                     /*13*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT,                /*14*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR,                     /*15*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR,                    /*16*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR,                     /*17*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT,                   /*18*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED,                   /*19*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNKNOWN_APN,                      /*20*/
    MMI_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED,                     /*21*/
    MMI_MMS_BGSR_RESULT_FAIL_USER_CANCEL,                           /*22*/
    MMI_MMS_BGSR_RESULT_FAIL_INVALID_PARAMETER,                     /*23*/
    MMI_MMS_BGSR_RESULT_FAIL_INVALID_MSGID,                         /*24*/
    MMI_MMS_BGSR_RESULT_FAIL_INVALID_FOLDER,                        /*25*/
    MMI_MMS_BGSR_RESULT_FAIL_QUEUE_FULL,                            /*26*/
    MMI_MMS_BGSR_RESULT_FAIL_MSGID_IS_USING,                        /*27*/
    MMI_MMS_BGSR_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED,    /*28*/
    MMI_MMS_BGSR_RESULT_FAIL_UPDATE_CHECKSUM_INVALID_PARAM,         /*29*/
    MMI_MMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE,               /*30*/
    MMI_MMS_BGSR_RESULT_FAIL_RR_MSG_NOT_FOUND,                      /*31*/
    MMI_MMS_BGSR_RESULT_FAIL_TOTAL                                  /*32*/
}mmi_mms_bgsr_result_enum;

typedef enum
{
    MMI_MMS_BGSR_ACTION_SEND_RSP,
    MMI_MMS_BGSR_ACTION_CANCEL_SEND_RSP,    
    MMI_MMS_BGSR_ACTION_DOWNLOAD_RSP,
    MMI_MMS_BGSR_ACTION_CANCEL_DOWNLOAD_RSP,    
    MMI_MMS_BGSR_ACTION_SAVE_RSP,    
    MMI_MMS_BGSR_ACTION_DELETE_RSP,
    MMI_MMS_BGSR_ACTION_SYNC_MSG_RSP,
    MMI_MMS_BGSR_ACTION_GET_MEM_STATUS_RSP,
    MMI_MMS_BGSR_ACTION_TOTAL_NUM
} mmi_mms_bgsr_action_type_enum;

typedef enum
{
    MMI_MMS_BGSR_INDICATOR_BUSY,
    MMI_MMS_BGSR_INDICATOR_IDLE,
    MMI_MMS_BGSR_INDICATOR_TOTAL_NUM
} mmi_mms_bgsr_indicator_type_enum;

typedef enum
{
    MMI_MMS_BGSR_POPUP_NORMAL,
    MMI_MMS_BGSR_POPUP_NO_SOUND,
    MMI_MMS_BGSR_POPUP_NO_POPUP,
    MMI_MMS_BGSR_POPUP_TOTAL_NUM
} mmi_mms_bgsr_popup_type_enum;

typedef struct 
{
    kal_uint32      msg_id;
    kal_uint32      ntt;
    kal_uint8       status;     /*mmi_mms_bgsr_msg_status_enum*/
    kal_uint8       quota;
    kal_uint8       folder;     /*mmi_mms_bgsr_msg_box_enum*/
    kal_uint8       result;     /*mmi_mms_bgsr_result_enum*/
}mmi_mms_bgsr_msg_info_struct;

typedef struct mmi_mms_bgsr_msg_struct_t
{
    kal_uint32      msg_id;
    kal_uint32      ntt;
    kal_uint32      expire_time;
    kal_uint8       status;         /*mmi_mms_bgsr_msg_status_enum*/
    kal_uint8       quota;
    kal_uint8       folder;         /*mmi_mms_bgsr_msg_box_enum*/
    kal_uint8       send_setting;   /*mmi_mms_bgsr_send_setting_enum*/
    kal_uint8       result;         /*mmi_mms_bgsr_result_enum*/
    kal_uint8       fail_retry_flag;
    kal_uint8       size;
    kal_uint8       is_rr;          /*a bool to identify whether it's a RR*/
    kal_uint8       op;             /*mmi_mms_bgsr_msg_operation_notify_enum*/
    
    struct mmi_mms_bgsr_msg_struct_t    *next;
}mmi_mms_bgsr_msg_struct;       /* size = 28 */


typedef void(*mmi_mms_bgsr_funcptr_type) (kal_uint32, kal_uint8);
typedef void(*mmi_mms_bgsr_rsp_funcptr_type) (kal_uint32, kal_uint8, kal_uint16*);
typedef void(*mmi_mms_bgsr_msg_funcptr_type) (kal_uint32, mmi_mms_bgsr_msg_info_struct *);

typedef struct
{
	mmi_mms_bgsr_rsp_funcptr_type 		send_rsp_callback;
	mmi_mms_bgsr_funcptr_type 		cancel_send_rsp_callback;
	mmi_mms_bgsr_rsp_funcptr_type 		download_rsp_callback;
	mmi_mms_bgsr_funcptr_type 		cancel_download_rsp_callback;
} mmi_mms_bgsr_callback_struct;


/***************************************************************************** 
* Global Functions
*****************************************************************************/

extern void mmi_mms_bgsr_send_req( kal_uint32 msg_id, kal_bool is_rr, mmi_mms_bgsr_send_setting_enum send_setting);
extern void mmi_mms_bgsr_cancel_send_req( kal_uint32 msg_id);
extern void mmi_mms_bgsr_download_req( kal_uint32 msg_id, kal_uint32 expire_time, kal_uint8 size);
extern void mmi_mms_bgsr_cancel_download_req( kal_uint32 msg_id);
extern void mmi_mms_bgsr_get_msg_info( kal_uint32 msg_id, mmi_mms_bgsr_msg_info_struct * msg_info, mmi_mms_bgsr_msg_funcptr_type get_msg_info_callback);
extern kal_uint32 mmi_mms_bgsr_get_sending_msg_id(void);
extern kal_uint32 mmi_mms_bgsr_get_downloading_msg_id(void);
extern void mmi_mms_bgsr_change_msg_notify(kal_uint32 msg_id, 
										   mmi_mms_bgsr_msg_operation_notify_enum msg_operation_notify,
										   mmi_mms_bgsr_msg_box_enum msg_folder,
										   mmi_mms_bgsr_funcptr_type change_msg_notify_callback);
extern void mmi_mms_bgsr_interrupt_end_cb(kal_uint32 interrupt_reason);
extern void mmi_mms_bgsr_usb_end_cb(void);
extern void mmi_mms_bgsr_get_mem_status_rsp(void *inMsg);
extern void mmi_mms_bgsr_send_mms_ind_hdlr(void *inMsg);
extern void mmi_mms_bgsr_send_mms_rsp(void *inMsg);
extern void mmi_mms_bgsr_abort_send_mms_rsp(void *in_msg);
extern void mmi_mms_bgsr_delete_mms_rsp(void *in_msg);
extern void mmi_mms_bgsr_save_mms_rsp(void *in_msg);
extern void mmi_mms_bgsr_download_mms_ind_hdlr(void *inMsg);
extern void mmi_mms_bgsr_download_mms_rsp(void *inMsg);
extern void mmi_mms_bgsr_abort_download_mms_rsp(void *in_msg);
extern void mmi_mms_bgsr_msg_is_valid_rsp(void *in_msg);
#endif /* __MMI_BGSR_GPROT_H_ */ 
