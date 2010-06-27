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
 * SmsGuiInterfaceType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SmsGuiInterfaceType.h

   PURPOSE     : ???

   REMARKS     : nil

   AUTHOR      : Manu Vikram and Magesh k

   DATE     : ???

**************************************************************/

#ifndef _PIXCOM_SMS_GUI_INTERFACE_TYPE_H
#define _PIXCOM_SMS_GUI_INTERFACE_TYPE_H
#include "MMIDataType.h"
#include "MessagesL4Def.h"
#include "MessagesMiscell.h"

#include "customer_ps_inc.h"

#if defined(__MMI_MESSAGES_TEMPLATE__)
#include "nvram_user_defs.h"
#ifndef NVRAM_SMS_TEMPL_RECORD_SIZE
#define NVRAM_SMS_TEMPL_RECORD_SIZE      84
#endif 
#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 

#define  MAX_USE_NUMBERS               6
#ifdef __MMI_MESSAGES_USE_URL__
#define     MAX_URL_LEN    (512)
#define TO_LOWER(ch) ( (((ch)>='A') && ((ch)<='Z'))?('a'+((ch)-'A')) :((ch))  )
#endif /* __MMI_MESSAGES_USE_URL__ */ 
#define MAX_WAITING_TYPE_NUM     4
#define MAX_WAITING_LINE_NUM     2
#define MAX_SEND_TO_MANY_ITEMS   10

typedef struct
{
#ifdef __MMI_DUAL_SIM_MASTER__
	U8 isSlave;
#endif
    U8 number[MAX_WAITING_TYPE_NUM];
} msg_waiting_ind_struct;

typedef struct
{
    U8 delivered;
    U8 type;
    U8 number[20];
    U8 timestamp[6];
#ifdef __MMI_DUAL_SIM_MASTER__
	U8 isFromMaster;
#endif
} msg_deliver_report_struct;

typedef struct
{
    U16 length;
    U8 fo;
    U8 dcs;
    U8 totalseg;
    U8 number[(MAX_DIGITS_SMS + 1) *ENCODING_LENGTH];
    U8 timestamp[6];
#ifdef __MMI_DUAL_SIM_MASTER__
	U8 isSlave;
#endif
    U8 *data;
} msg_class0_msg_struct;

typedef struct
{
    /* send by group */
    U16 TotalSendSmsNumbers;
    U16 *PhbIndex;
    /* send to many */
    U8 CurrSendSmsNumbers;
    S8 PhbNumber[MAX_SEND_TO_MANY_ITEMS][(MAX_DIGITS + 2) *ENCODING_LENGTH];
} msg_send_many_struct;

typedef enum
{
    MSG_NEW_NONE,
    MSG_NEW_VOICEMAIL,
    MSG_NEW_FAX,
    MSG_NEW_EMAIL,
    MSG_NEW_NETOTHER,

    MSG_NEW_MSG_NORMAL,
#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))
    MSG_NEW_JMMS_MMS,
    MSG_NEW_JMMS_JAVA_MMS,
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#if (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT))
    MSG_NEW_PUSH, 
    MSG_NEW_PROV_SETTING,
#endif /* (defined (JATAAYU_SUPPORT) && defined(WAP_SUPPORT)) */ 
#if defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    MSG_NEW_MSG_PICTURE,
    MSG_NEW_MSG_RINGTONE,
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 
    MSG_NEW_MSG_CLASS0,
#ifdef __MMI_BROWSER_2__
    MSG_BRW_NEW_PUSH,
	MSG_BRW_NEW_MESSAGE,
#endif  /* __MMI_BROWSER_2__ */
#ifdef __MMI_CCA_SUPPORT__
    MSG_NEW_CCA_SETTING,
#endif  /* __MMI_CCA_SUPPORT__ */
    MSG_NEW_DELIVERY_REPORT,
#ifdef __MMI_MMS_2__
	MSG_UMMS_NEW_JAVA_MMS,
	MSG_UMMS_NEW_MMS,
#endif

    MSG_NEW_MSG_END
} msg_new_msg_enum;

typedef enum
{
    SEND_CASE_SEND_ONLY,
    SEND_CASE_SAVE_N_SEND,
    SEND_CASE_SAVE_ONLY,
    SEND_CASE_REPLY,
    SEND_CASE_SEND_TO_MANY,
    SEND_CASE_SEND_BY_GROUP,
    SEND_CASE_SEND_FROM_PHB,
    SEND_CASE_SEND_VCARD,
    SEND_CASE_SEND_CHAT,
    SEND_CASE_SEND_CLUB_CODE,
    SEND_CASE_REPLY_FROM_OTHER_APP,
    SEND_CASE_SEND_FROM_USE_NUMBER,
	SEND_CASE_SEND_FROM_OTHER_APP
} msg_send_case_enum;

typedef enum
{
    SEND_SAVE_NIL = 0,
    SEND_SUCCESS,
    SEND_FAILED,
    SAVE_SUCCESS,
    SAVE_FAILED,
    SEND_SUCESS_SAVE_FILED,
    SEND_FAILED_SAVE_SUCCESS,
    SEND_SAVE_SUCESS,
    SEND_SAVE_FAILED,
    SAVE_ABORT_SENDING_SMS,
    SAVE_WHEN_SC_IS_EMPTY,
    SAVE_WHEN_SC_IS_EMPTY_FAILED,
    SAVE_WHEN_SC_IS_EMPTY_SUCCESS,
    SAVE_AFTER_FDN_CHECK,
    SAVE_AFTER_FDN_CHECK_FAILED,
    SAVE_AFTER_FDN_CHECK_SUCCESS
} msg_send_save_status_enum;

typedef enum
{
    TO_DISPLAY_MESSAGE_LIST_NONE,
    TO_DISPLAY_MESSAGE_LIST_INBOX,
    TO_DISPLAY_MESSAGE_LIST_OUTBOX,
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    TO_DISPLAY_MESSAGE_LIST_DRAFTBOX,
#endif
#ifdef __MMI_UNIFIED_MESSAGE__
    TO_DISPLAY_MESSAGE_LIST_UNSENTBOX,
#endif /* __MMI_UNIFIED_MESSAGE__ */
    TO_DISPLAY_MESSAGE_LIST_INBOX_AFTER_DELETE_ALL,
    TO_DISPLAY_MESSAGE_LIST_OUTBOX_AFTER_SAVE_MSG,
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__    
    TO_DISPLAY_MESSAGE_LIST_ARCHIVE,
#endif
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    TO_DISPLAY_MESSAGE_LIST_SIMBOX,
#endif 
    TO_DISPLAY_MESSAGE
} msg_display_list_enum;

typedef enum
{
    MSG_STATUS_IDLE,
    MSG_STATUS_INPUT_NUM
} msg_status_enum;

#if defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__))
typedef enum
{
    MMI_SMS_PREFER_GPRS,
    MMI_SMS_PREFER_GSM,
    MMI_SMS_GSM_ONLY
} msg_bearer_enum;
#endif /* defined(__MMI_GPRS_FEATURES__) && (!defined(__MMI_DUAL_SIM_MASTER__)) */ 

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
typedef enum
{
    MMI_NSM_PIC_SUCCESS,
    MMI_NSM_PIC_FORMAT_ERROR,
    MMI_NSM_PIC_MEMORY_ERROR
} pmsg_error_enum;
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#ifdef __MMI_UNIFIED_MESSAGE__
typedef enum
{
    MMI_SMS_PS_ACTION_DEFAULT,
    MMI_SMS_PS_ACTION_SEND_SUCCESS_REMOVE_MSG,
    MMI_SMS_PS_ACTION_MOVE_MSG,
    MMI_SMS_PS_ACTION_TYPE_NUM
} mmi_msg_post_send_action_type_enum;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#ifdef __MMI_MESSAGES_USE_URL__
#define IS_GSM_SPECIAL_CHAR(c)   (( (c)==0x000C || (c)==0x005B || (c)==0x005C || (c)==0x005D || (c)==0x005E || (c)==0x007B || (c)==0x007C || (c)==0x007A || (c)==0x007E))
#define IS_GSM_CHAR(c)  (((c)<=0x007f || IS_GSM_SPECIAL_CHAR((c)))?1:0)
#endif /* __MMI_MESSAGES_USE_URL__ */ 

typedef struct
{
    S32 currHiliteIndex;
    S32 currBoxIndex;
    S32 currTemplateIndex;
    S32 currSendNumIndex;
    U16 MessagesScrnIdToDelHistoryNodes;
    U16 MessagesScrnIdDelUptoHistoryNodes;

    U16 msg_ind_index;
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    U16 sim_msg_ind_index;
    U8 sim_msg_ind_in_idle;
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */ 
    U16 msg_ind_chat_index;
    U8 msg_ind_in_idle;
    U8 msg_ind_after_call;

    U8 msg_class0_ind;
    U8 msg_full_ind;
    U8 msg_exceed_ind;
    U8 msg_exceed_type;
    U8 msg_deliver_ind;
    U8 msg_waiting_ind;
    U8 msg_waiting_line_number;

    U8 msg_init;        /* init to be false */
    U8 number_from_phb; /* init to be 0 */

    S8 smsPhoneNumber[(MAX_DIGITS + 1) *ENCODING_LENGTH];
#ifdef __MMI_MESSAGES_TEMPLATE__
    S8 *templates[NUM_TEMPLATES];
    S8 scratchTemplRec[NVRAM_SMS_TEMPL_RECORD_SIZE + ENCODING_LENGTH];
#endif /* __MMI_MESSAGES_TEMPLATE__ */ 

#ifdef __MMI_UNIFIED_MESSAGE__
    U8 is_background_process;
    U8 post_send_action;
#endif /* __MMI_UNIFIED_MESSAGE__ */ 

    S8 *numbersList[MAX_USE_NUMBERS];
#ifdef __MMI_MESSAGES_USE_URL__
    S8 *URLlist[MAX_USE_NUMBERS];
    U16 URLCount;
#ifdef __MMI_VIDEO_STREAM__
    U8 is_rtspUrl[MAX_USE_NUMBERS];
#endif 
#endif /* __MMI_MESSAGES_USE_URL__ */
#ifdef __MMI_EMAIL__
    S8 *EmailAddrList[MAX_USE_NUMBERS];
    U16 EmailAddrCount;
#endif /* __MMI_EMAIL__ */
    U8 PhbSmsInterfaceState;                    /* MMI_PHB_SMS_INTERFACE */
    msg_display_list_enum toDisplayMessageList; /* init to be TO_DISPLAY_MESSAGE_LIST_NONE */
    msg_send_case_enum sendMessageCase;
    msg_send_save_status_enum sendSaveStatus;
    msg_status_enum msg_status;                 /* store the status in number editing screen */

    msg_waiting_ind_struct msg_waiting_info[MAX_WAITING_LINE_NUM];      /* init to zero */
    msg_class0_msg_struct *msg_class0_p;    /* init to NULL */
    msg_deliver_report_struct *msg_deliver_report[MAX_STATUS_REPORT_NUM];       /* init to NULL */
    msg_send_many_struct msg_send_info;
#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
    U16 dest_port;
#endif 
    U8 msg_waiting_is_show_number;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	U16 background_sending_index;
#endif
	U8 free_class0_data_flag;
#ifdef __MMI_DUAL_SIM_MASTER__
	BOOL isSlave;
	BOOL msg_exceed_from_slave;
	BOOL is_voicemail_from_idle;
#endif
} msg_context_struct;

extern msg_context_struct g_msg_cntx;

#if defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

#define MAX_BMP_SEG     (3)

#define MAX_PICMSG_TEXT_SEGMENT     (((MMI_SMS_MAX_MSG_SEG-MAX_BMP_SEG)>5)?(5):(MMI_SMS_MAX_MSG_SEG-MAX_BMP_SEG))

#define  DEFAULT_DCS_ALLOCATED_LENGTH  (MMI_SMS_MAX_MSG_SEG*153)
#define UCS2_DCS_ALLOCATED_LENGTH      (MMI_SMS_MAX_MSG_SEG*67)

#define MAX_PICMSG_DEFAULT_DCS_TEXT_LEN   (MAX_PICMSG_TEXT_SEGMENT*120)
#define MAX_PICMSG_UCS2_DCS_TEXT_LEN   (MAX_PICMSG_TEXT_SEGMENT*60)

#endif /* defined(__MMI_SMART_MESSAGE_MT__) || (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))

//#define NSM2_GSM7_CHARACTER_LIMIT     612
//#define NSM2_GSM8_CHARACTER_LIMIT   120               /* */

#define PIC_BUFF_MAX_SIZE     (640)
typedef struct
{
    S32 textlength;
    S32 max_textlength;
    S32 picbuffer_length;
    S32 pic_height;
    S32 pic_width;
    S32 UCS2_count;
    S32 remaining_length;
    S32 cursor_pos_after_template;  /* Only use when template inserted */

    U8 textbuffer[(DEFAULT_DCS_ALLOCATED_LENGTH *ENCODING_LENGTH) + (ENCODING_LENGTH *2)];
    U8 picbuffer[PIC_BUFF_MAX_SIZE];
    void (*header_fptr) (U32, S32, S32, S32, S32, S32);

    U8 dcs;
    BOOL is_picmsg;
    BOOL is_template_insert;    /* Only when template inserted */
} nsm_msg_struct;

extern void mmi_nsm2_init_nsm_msg_struct(nsm_msg_struct *);
extern void mmi_nsm2_add_text_in_pEMS(nsm_msg_struct *nsm_msg_context);

#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
typedef enum 
{
	UNSENT_IDLE_STATE,
	UNSENT_SEND_STATE,
	UNSENT_CANCEL_SEND_STATE,
	UNSENT_DELETE_STATE,
	UNSENT_DELETE_ALL_STATE,
	UNSENT_MOVE_TO_DRAFT_STATE
}mmi_msg_unsent_state_enum;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#endif /* _PIXCOM_SMS_GUI_INTERFACE_TYPE_H */ 

