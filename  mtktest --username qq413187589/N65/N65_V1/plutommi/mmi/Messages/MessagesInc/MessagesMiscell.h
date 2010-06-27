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
 * MessagesMiscell.H
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

   FILENAME : MessagesMiscell.h

   PURPOSE     : ---

   REMARKS     : ---

   AUTHOR      : Hiran and Magesh k

   DATE     : ---

**************************************************************/

#ifndef _PIXCOM_MESSAGES_MISCELL_H
#define _PIXCOM_MESSAGES_MISCELL_H
//
//
#include  "MMIDataType.h"
#include "MessagesL4Def.h"

#ifdef __MMI_UNIFIED_MESSAGE__
#include "UnifiedMessageGProt.h"
#endif 

#define     USE_NUM_MIN_LENGTH            3
#define        IS_NUM(c)  (((c)>='0') && ((c)<='9'))

#define MAX_DIGITS               41     /* Maximum number of digits in phone number */
#define MAX_DIGITS_SMS           21     /* Maximum number of digits in sms source/destination */
#define MAX_TIMESTAMP_SIZE    12

#define MAX_PROFILE_EDIT_ITEMS   4
#define MAX_PROFILE_NAME_LEN     30     /* check with ps */

#define MAX_STATUS_REPORT_NUM 10

/* check with l4 value.. */
#define  MESSAGES_POPUP_TIME_OUT             UI_POPUP_NOTIFYDURATION_TIME_2000
#define  MESSAGES_SUBLCD_TIME_OUT            1000*10
#define  MESSAGES_LMS_TIME_OUT            1000*10
#define  MESSAGES_INPROGRESS_TIME_OUT        1000*50

#define MAX_LFOUR_PROFILES                4
#define MAX_LFOUR_VP                   7
#define MAX_LFOUR_MSG_TYPE             4
#define MAX_MAILBOX_PS_SUPPORT            2

typedef void (*FuncPtr) (void);

#define EMS_ESCAPE_CHARACTER  (27)
#define EMS_SPACE_CHARACTER      (32)
#define EMS_CR_CHARACTER      (13)
#define EMS_EURO_CHARACTER_UCS2     (0x20AC)
#define EMS_EURO_CHARACTER       (0xA2)

typedef enum
{
    SMS_OK,
    SMS_ERROR
} msg_result_enum;

typedef enum
{
    POST_PARAMS_FO,
    POST_PARAMS_PROFILE_NAME,
    POST_PARAMS_ALL_LANGUAGES,
    POST_PARAMS_ALL_LANGUAGES_DEFAULT_FACTORY,
    POST_PARAMS_REST    /* PID, DCS, VP */
} msg_post_params_enum;

typedef struct
{
    //PMT START SWEDISH 20050916
    // For some langauges the translation is more than 12 charcaters so we need to make it 14
    U8 totalInboxStr[20 *ENCODING_LENGTH];
    U8 totalOutboxStr[20 *ENCODING_LENGTH];
#ifdef __MMI_MESSAGES_DRAFT_BOX__
    U8 totalDraftboxStr[20 *ENCODING_LENGTH];
    /* PMT END SWEDISH 20050916 */
#endif /* __MMI_MESSAGES_DRAFT_BOX__ */ 
} msg_in_out_struct;

/*  */
typedef struct
{
    S32 vpIndex;
    S32 msgTypeIndex;
    U8 profileName[(MAX_PROFILE_NAME_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
    U8 profileNameDcs;
    U8 profileIndex;
    U8 scAddress[(MAX_CC_ADDR_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
} msg_profile_edit_struct;

typedef struct
{
    U8 mailboxName[(MAX_PROFILE_NAME_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
    U8 mailboxNameDcs;
    U8 malboxNameLength;
    U8 mailboxIndex;
    U8 mailboxAddress[(MAX_CC_ADDR_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
} msg_mailbox_edit_struct;

//
//
#if defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__)
typedef struct
{
    U16 simUsed;
    U16 simTotal;
    U16 meUsed;
    U16 meTotal;
    U8 prefStorage;
} msg_mem_status_struct;

typedef enum
{
    DISP_NONE,
    DISP_MEM_STATUS,
    DISP_PREF_STORAGE,
    UPDATE_MEM_STATUS,
    UPDATE_PREF_STORAGE
} msg_mem_status_enum;
#endif /* defined(__MMI_MESSAGES_PREFER_STORAGE_MEMORY_STATUS__) */ 

/*  */
typedef struct
{
    U8 currReqProfileNo;
    U8 currMaxPsProfiles;
    U8 profileNameLength;
    U8 profileName[MAX_LFOUR_PROFILES][(MAX_PROFILE_NAME_LEN *ENCODING_LENGTH) + ENCODING_LENGTH];
} msg_profile_list_struct;

typedef struct
{
    l4c_number_struct scAddr;
    U8 profile; /* SMS_DEST_NO_ENUM */
    U8 para;    /* MMI_PARA_ENUM */
    U8 vp;      /* smsal_vp_enum */
    U8 pid;     /* smsal_pid_enum */
    U8 dcs;     /* smsal_dcs_enum */
} msg_active_profile_struct;

typedef struct
{
    unsigned short totalinbox;
    unsigned short totaloutbox;
    unsigned short totaldraftbox;
} msg_msgbox_info_struct;

#if defined(__MMI_MESSAGES_TEMPLATE__)
#define     NUM_TEMPLATES              10
#define     MAX_TEMPLATE_LENGTH        40
typedef enum
{
    MSG_TEMPLATE_LANG_ENGLISH,
    MSG_TEMPLATE_LANG_SIMCHINESE,
    MSG_TEMPLATE_LANG_TRACHINESE
} msg_template_lang_enum;
extern U8 InitTemplates(void);
extern void DeInitTemplates(void);
extern void LoadTemplatesInDisplayList(void);
extern void GetTemplatesToEdit(S8 *buffer, U32 index);
extern U8 DeleteTemplate(U32 index);
extern U8 StoreTemplate(U32 index);
extern U16 CalTemplateBase(void);

#endif /* defined(__MMI_MESSAGES_TEMPLATE__) */ 

extern void GetCurrEndKeyDownHandler(void);
extern void ExecCurrEndKeyDownHandler(void);

/*  */
extern void SetMessagesScrnIdToDelHistoryNodes(U16 ScrnId);
extern void SetMessagesScrnIdDelUpToHistoryNodes(U16 StartScrnId);
extern void DeleteMessagesHistoryNodes(void);

/*  */
extern void Messages2GoBackHistory(void);
extern void Messages4GoBackHistory(void);

/*  */
extern U16 GetMessagesCurrScrnID(void);
extern void SetMessagesCurrScrnID(U16 scrnID);

/*  */
extern U16 IsMMIInIdleState(void);
extern U8 IsKeyPadLockState(void);
extern void PlayMessageArrivalTone(void);
extern void RestoreMessagesSettings(void);
extern U8 IsMessagesReEntering(void);
extern U16 ObtainNumbersFromMessageText(char *phNumber, U8 *smsText, U16 textLength, U8 startindex);
extern S8 *GetPhoneNumber(S8 *number);

#ifdef __MMI_MESSAGES_CHAT__
extern pBOOL SmsChatCompareFunction(char *number, U8 len, U8 type, U16 index);
#endif 
/*  */

extern void mmi_msg_highlight_class0_opt_use_number(void);

extern void mmi_msg_free_class0_data(void);
extern U8 mmi_msg_delete_class0_ind_screen_callback(void);
extern void mmi_msg_go_back_from_msg_waiting_ind(void);

#ifdef __MMI_MESSAGES_USE_URL__
extern void mmi_msg_highlight_class0_opt_use_url(void);
extern void mmi_msg_entry_class_0_opt_use_url(void);
#endif /* __MMI_MESSAGES_USE_URL__ */

#ifdef __MMI_UNIFIED_MESSAGE__
extern void mmi_msg_um_entry_msg(UmMsgBoxType msg_box_type, kal_uint16 msg_index);
extern void mmi_msg_um_entry_write(void);
extern void mmi_msg_um_entry_template(void);
extern void mmi_msg_um_entry_setting(void);
extern void mmi_msg_set_background_process(kal_bool flag);
extern kal_bool mmi_msg_check_background_process(void);
extern U8 mmi_msg_get_post_send_action_type(void);
extern void mmi_msg_set_post_send_action_type(U8 action);
extern kal_bool mmi_msg_get_msg_num(
            kal_uint16 *inbox_msg_number,
            kal_uint16 *inbox_unread_msg_number,
            kal_uint16 *unsent_msg_number,
            kal_uint16 *sent_msg_number,
            kal_uint16 *draft_msg_number
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__            
            , kal_uint16 *arch_msg_number
        #endif
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            , kal_uint16 *sim_msg_number
        #endif
            ); 
extern kal_bool mmi_msg_get_list_info(
                    UmMsgBoxType msg_box_type,
                    kal_uint16 start_entry,
                    kal_uint16 max_msg_number,
                    kal_uint16 *msg_number,
                    mmi_um_list_info_struct *list_info,
                    kal_bool *more);
extern kal_bool mmi_msg_get_msg_info(
                    UmMsgBoxType msg_box_type,
                    kal_uint16 start_entry,
                    kal_uint16 req_msg_number,
                    kal_uint16 *rsp_msg_number,
                    mmi_um_msg_info_struct *msg_info);
extern void mmi_msg_get_address(
                kal_uint16 msg_type,
                kal_uint16 msg_index,
                kal_wchar *address,
                kal_uint8 max_address_len);
extern kal_uint16 mmi_msg_get_icon(kal_uint16 msg_type, kal_uint16 msg_index);
extern void mmi_msg_handle_delete_folder_by_um(UmMsgBoxType msg_box_type);
extern void mmi_msg_delete_folder_by_um_callback(void *dummy, module_type mod, U16 result);

#endif /* __MMI_UNIFIED_MESSAGE__ */ 

#endif /* _PIXCOM_MESSAGES_MISCELL_H */ 

