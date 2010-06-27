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
 * MessagesExDcl.H
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

   FILENAME : MessagesExDcl.h

   PURPOSE     : ---

   REMARKS     : ---

   AUTHOR      : Hiran and Magesh k

   DATE     : ---

**************************************************************/

#ifndef _PIXCOM_MESSAGES_EXTERN_DCL_H
#define _PIXCOM_MESSAGES_EXTERN_DCL_H

#include "MMIDataType.h"
/*  */

typedef enum
{
    MMI_SEND_ONLY,
    MMI_SEND_BY_NAME,
    MMI_SEND_TO_MANY,
    MMI_CALLER_GROUP_NAMES,
    MMI_CALLER_GROUP_DATA,
    MMI_VOICEMAIL_NUMBERS,
    MMI_SEND_SMS_FROM_PHB,      /* MTK 2004-02-03 Wilson. */
    MMI_SEND_VCARD_FROM_PHB,    /* MTK 2004-03-25 Wilson */
    MMI_SEND_CHAT,
    MMI_SAVE_CHAT,
    MMI_PHB_SMS_INTERFACE_NONE
} MMI_PHB_SMS_INTERFACE;

#ifdef __MMI_MESSAGES_EMS__
typedef enum
{
    EMS_OBJECT_PICTURE_STATE = 1,
    EMS_OBJECT_MY_PICTURE_STATE,
    EMS_OBJECT_PREDEFINED_ANIMATION_STATE,
    EMS_OBJECT_MY_ANIMATION_STATE,
    EMS_OBJECT_MELODY_STATE,
    EMS_OBJECT_MY_MELODY_STATE,
    EMS_OBJECT_PREDEFINED_SOUND_STATE,
    EMS_OBJECT_MY_PICTURE_A_ANIMATION_DOWNLOAD_APP_STATE,
    EMS_OBJECT_MY_MELODY_DOWNLOAD_APP_STATE
} EMS_OBJECT_DISPLAY_STATE;
#endif /* __MMI_MESSAGES_EMS__ */ 

#ifdef __MMI_MESSAGES_CLUB__
#define MSG_CLUB_SERVICE_CODE_LENGTH   6
#define MSG_CLUB_EXPLAIN_CODE_LENGTH   14
#define MSG_CLUB_CODE_LENGTH        30

#define MSG_CLUB_VOICE_CODE_LENGTH  16
#define MSG_CLUB_LONG_CODE_LENGTH   12
#define MSG_CLUB_SHORT_CODE_LENGTH  4

typedef enum
{
    MSG_CLUB_CT,
    MSG_CLUB_CU,
    MSG_CLUB_NETWORK_TOTAL
} msg_club_network_enum;

typedef enum
{
    MSG_CLUB_SERVICE_SUBSCRIBE,
    MSG_CLUB_SERVICE_ORDER,
    MSG_CLUB_SERVICE_EXPLAIN,

    MSG_CLUB_SERVICE_CANCEL,
    MSG_CLUB_SERVICE_MORE
} msg_club_service_enum;

typedef enum
{
    MSG_CLUB_MENU = 0x01,
    MSG_CLUB_DY_DB_ZF_TD = 0x02,
    MSG_CLUB_DY_DB_ZF = 0x04,
    MSG_CLUB_DY_DB = 0x08,
    MSG_CLUB_TD = 0x10,
    MSG_CLUB_INFO = 0x20,
    MSG_CLUB_VOICE_MENU = 0x40,
    MSG_CLUB_CT_ONLY = 0x80
} msg_club_menu_enum;

typedef enum
{
    PHONE_PRE = 0x0001,
    PHONE_END = 0x0002,
    NUMBER_PRE = 0x0004,
    NUMBER_END = 0x0008,
    CODE_PRE = 0x0010,
    CODE_END = 0x0020,
    SERVICE_PRE = 0x0040,
    SER_END = 0x0080,
    INPUT_NUM = 0x0100,
    INPUT_ENG = 0x0200,
    INPUT_CHI = 0x0400,
    INPUT_CODE = 0x0800,
    INPUT_DA = 0x1000,
    INPUT_NAME = 0x2000,
    INPUT_SMS = 0x4000,
    INPUT_PWD = 0x8000
} msg_club_code_enum;

typedef struct
{
    U16 Level2String;
    S8 CodeSubscribe[MSG_CLUB_NETWORK_TOTAL][MSG_CLUB_SERVICE_CODE_LENGTH];
    S8 CodeOrder[MSG_CLUB_NETWORK_TOTAL][MSG_CLUB_SERVICE_CODE_LENGTH];
    S8 ExplainCode[MSG_CLUB_EXPLAIN_CODE_LENGTH];
} msg_club_submenu_struct;

typedef struct
{
    U8 Level1Menu;
    U8 NumOfLevel2Menu;
    U16 Level1String;
    const msg_club_submenu_struct *SubMenu;
} msg_club_menu_struct;

typedef struct
{
    U16 stringID;
    U16 childNum;
    void *childEntry;
} msg_club_entry_struct;

typedef struct
{
    U16 codeType;
    U8 codeNum[MSG_CLUB_LONG_CODE_LENGTH];
} msg_club_long_code_struct;

typedef struct
{
    U8 codeNum[MSG_CLUB_SHORT_CODE_LENGTH];
} msg_club_short_code_struct;

typedef struct
{
    U16 codeType;
    U8 codeNum[MSG_CLUB_LONG_CODE_LENGTH];
} msg_club_service_code_struct;

typedef struct
{
    U8 codeNum[MSG_CLUB_VOICE_CODE_LENGTH];
} msg_club_voice_code_struct;

typedef struct
{
    U16 stringID;
    U8 childNum;
    U8 childType;
    const void *childEntry;
} msg_club_entry_menu_struct;

typedef struct
{
    U16 stringID;
    U8 serverType;
    U8 codeCU;
    U8 strInput_codeCU;
    msg_club_long_code_struct codeDY;
    msg_club_long_code_struct codeDB;
    msg_club_long_code_struct codeZF;
    msg_club_short_code_struct codeTD;
} msg_club_entry_dy_db_zf_struct;

typedef struct
{
    U16 stringID;
    U8 serverType;
    U8 codeCU;
    msg_club_short_code_struct codeTD;
} msg_club_entry_td_struct;

typedef struct
{
    U16 stringID;
    U8 serverType;
    U8 codeCU;
    msg_club_long_code_struct codeInfo;
} msg_club_entry_info_struct;

typedef struct
{
    U16 stringID;
    U8 codeType;
    U8 codeCU;
    msg_club_voice_code_struct codeVoice;
} msg_club_entry_voice_struct;

typedef struct
{
    msg_club_service_code_struct serverDY[MSG_CLUB_NETWORK_TOTAL];
    msg_club_service_code_struct serverDB[MSG_CLUB_NETWORK_TOTAL];
    msg_club_service_code_struct serverZF[MSG_CLUB_NETWORK_TOTAL];
    msg_club_service_code_struct serverTD[MSG_CLUB_NETWORK_TOTAL];
} msg_club_service_num_struct;

#endif /* __MMI_MESSAGES_CLUB__ */ 

#if defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
typedef enum
{
    NORMAL_MESSAGE,
    PICTURE_MESSAGE,
    RINGTONE_MESSAGE
} MESSAGE_TYPE_ENUM;
extern void PrepareEntryNsmRingtoneoption(void);
extern void EntryNsmRingtoneoption(void);
extern void HighlightNsmRingtoneoptionplayHandler(void);
extern void HighlightNsmRingtoneoptionsaveHandler(void);
extern void EntryNsmRingtoneoptionplay(void);
extern void EntryNsmRingtoneoptionsave(void);
extern void mmi_nsm_save_ringtone(void);
extern U16 mmi_nsm_convert_ota_to_midi(U8, U8 *);
extern void EntryNsmPicturemsg(void);
extern void PreEntryNsmRingtoneoptionsave(void);

/* void EntryNsmMytoneList(void); */
extern void ExecuteMyHandler(S32 index);

//void HighlightMyToneplayHandler(void);
//void HighlightMyToneDeleteHandler(void);
extern void mmi_nsm_entry_option_picturemsg(void);
extern void HighlightPicmsgSavePictureHandler(void);
extern void EntryPicmsgSavepic(void);
extern void mmi_nsm_save_picmsg(void);

/* void HighlightMypicDeleteHandler(void); */
extern void PreEntryNsmRingtoneoption(void);
extern void PreEntryNsmPicturemsg(void);
extern void mmi_nsm_ringtone_exit_play(void);
extern void PrepareEntryNsmPicturemsg(void);
extern void ShowPictureErrorMessage(void);

/* void mmi_msg_pre_exit_inbox_list(void); */
extern U16 mmi_nsm_get_msg_type(void);
extern void mmi_nsm_set_msg_type(U8 type);
extern void mmi_nsm_stop_and_goback(void);
extern void mmi_nsm_stop_and_goto_idlescreen(void);
extern void mmi_save_ringtone_options(void);
extern void highlight_save_ringtone_done(void);

#endif /* defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#define MMI_SMS_ARCH_FOLDER_DRV MMI_PUBLIC_DRV
#define MMI_SMS_ARCH_PATH      "\\SMSArch\\"  //before read/write arch file, need to "%s%lx.a", SMSARCH_FOLDER, fileid
#define MMI_SMS_ARCH_SYS_PATH  "\\@SMSArch\\" //to store idx file in sys drive
#define MMI_SMS_MAX_ARCH_PATH_LEN (18 + 6)  //18 for MMI_SMS_ARCH_PATH/MMI_SMS_ARCH_SYS_PATH,  6 for 001.a,...009.a, 00A.a, 00B.a...00F.a, 010.a.... idx.a
#define MMI_SMS_MAX_ARCH_BUF_SIZE (100+ MMI_SMS_MAX_MSG_SEG *160 * ENCODING_LENGTH)
#endif

#if defined(__MMI_SMART_MESSAGE_MT__)

#include "smsguiinterfacetype.h"

extern void highlight_picmsg_edit_text(void);
extern void mmi_picmsg_edit_text(void);
extern void mmi_pic_msg_edit_text_options(void);
extern void highlight_pic_msg_edit_text_done(void);
extern BOOL mmi_nsm_is_unicode_string(void);    /* return : TRUE if pic text is unicode else return FALSE */

/* Start :Added for NSM1 by JP : FOr chinese character support */
#define MAX_PIC_TEXT_BUFF_SIZE    (MAX_PICMSG_DEFAULT_DCS_TEXT_LEN*ENCODING_LENGTH)
#define MAX_PICMSG_TEXT_LEN      (MAX_PICMSG_DEFAULT_DCS_TEXT_LEN)      /* Max text size with picture message */

typedef struct
{
    S32 Infobar_max_limit;
    S32 ucs2_count;
    S8 pic_textbuff[MAX_PIC_TEXT_BUFF_SIZE + (8 *ENCODING_LENGTH)];
} nsm_picmsg_text_struct;
extern void mmi_nsm_init_picmsg_txt_struct(nsm_picmsg_text_struct *text_struct);
extern S32 mmi_nsm_get_infobar_maxlen(void);

/* End : JP 25/02/2005 */

#endif /* defined(__MMI_SMART_MESSAGE_MT__) */ 
// #endif
#if defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__))
extern void highlight_save_pic_msg_done(void);
extern void mmi_save_pic_options(void);
#endif /* defined(__MMI_SMART_MESSAGE_MT__) || ( defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) */ 

extern void PreEntryScrMessagesMenuList(void);
extern void EntryScrMessagesMenuList(void);
extern void InitMessagesApp(void);
extern void InitMessageProtocolEventHandlers(void);
extern void InitCBNVRAMData(void);

#if defined(__MMI_MESSAGES_TEMPLATE__)
extern U8 InitTemplates(void);
#endif 
extern void DeInitMessagesApp(void);
extern void RestoreMessagesSettings(void);
extern U16 GetMessagesCurrScrnID(void);
extern void SetMessagesCurrScrnID(U16 scrnID);
extern void SetMessagesScrnIdToDelHistoryNodes(U16 ScrnId);
extern void SetMessagesScrnIdDelUpToHistoryNodes(U16 StartScrnId);

extern void mmi_msg_get_number_from_phb(U8[], U8[]);
extern void mmi_msg_set_phb_send_case(U8 PhbSmsInterfaceState);
extern void mmi_msg_save_msg(U8 status);
extern void DialVoiceMail(void);
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);

#ifdef __MMI_MESSAGES_CHAT__
extern U16 ObtainChatNumbersFromMessageTextWrapper(char *phNumber, S16);
extern PU8 GetNewChatSmsIndDisplayStr(void);
extern void DeleteChatMsg(S32 index);
extern void GetConcatenatedMessage(void);
#endif /* __MMI_MESSAGES_CHAT__ */ 
#if defined(__MMI_MESSAGES_EMS__)
extern void EnableDisableAudioPlayback(void);
extern void DisplayUserDefinedImageList(void);

#ifdef __MMI_IMELODY_SUPPORT__
extern U8 *GetEmsMelodyNameWithPathInFileSystem(U16 AudioId);
extern U8 DeleteEmsMelodyObject(U16 emsMelodyID);
extern void SendMelodiesByEMS(void);
extern void UpdateIMelodyDataForSyncDownloadFileSystemFunc(void);
#endif /* __MMI_IMELODY_SUPPORT__ */ 
#ifdef __MMI_FILE_MANAGER__
#define CATEGORY144_FMGR_PREVIEW    0x1000
extern void ShowCategory144Screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 object_type,
                S32 n_items,
                U8 **object_titles,
                U16 *predefined_objects,
                MMI_BOOL is_short_name,
                U8 **userdefined_objects,
                S32 *index,
                U8 *history_buffer);
extern void mmi_ems_fm_send_by_ems(S8 *emsObjectFileNameBuf, EMS_OBJECT_DISPLAY_STATE emsObjectType);
extern void mmi_ems_add_object_from_fm(void);
extern void mmi_ems_preview_object_from_fm(PU16 filePath, int is_short);
#endif /* __MMI_FILE_MANAGER__ */ 
#endif /* defined(__MMI_MESSAGES_EMS__) */ 
#if defined (__MMI_VCARD__) || defined (__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
extern void mmi_ems_vobject_send_by_ems(U16 scrport, U16 dstport, S8 *filepath, PsFuncPtr callback);
#endif 
extern void mmi_msg_handle_call_ind(void);
extern U8 mmi_msg_check_interrupt(void);
extern kal_bool mmi_msg_check_ascii_number(U8 *number_string, U16 length);
extern U8 mmi_msg_need_clear_action_queue(void);
extern U8 mmi_msg_need_new_msg_ind(void);
extern U8 mmi_msg_need_new_msg_ind_call_end(void);
extern void mmi_msg_reset_new_msg_ind_call_end(void);
extern U8 mmi_msg_need_class0_msg_ind(void);
extern U8 mmi_msg_need_mem_full_ind(void);
extern U8 mmi_msg_need_mem_exceed_ind(void);
extern U8 mmi_msg_need_delivery_report_ind(void);
extern U8 mmi_msg_need_waiting_ind(void);

extern void mmi_msg_init_msg_data(void);
extern void mmi_msg_init_msg_process(void);
extern void mmi_msg_deinit_msg_data(void);

extern void mmi_msg_entry_msg_waiting_ind(void);
extern void mmi_msg_get_deliver_report_status(U32 *status, U16 *imgID, U16 *strID);
extern U8 *mmi_msg_get_deliver_report_msg(void);
extern void mmi_msg_entry_deliver_report_ind(void);
extern void mmi_msg_entry_mem_exceed_ind(void);
extern void mmi_msg_entry_class0_msg_ind(void);
extern U8 *mmi_msg_get_new_msg_ind_string(void);
extern void mmi_msg_entry_new_msg_ind(void);
extern void mmi_msg_entry_new_cb_ind(void);
extern U8 mmi_msg_need_new_cb_ind(void);
extern U8 *mmi_msg_get_msg_waiting_msg(void);

#ifdef __MMI_MESSAGES_CLUB__
extern void EntryMsgClub(void);
extern void mmi_msg_club_entry_level_1(void);
extern void mmi_msg_club_send_msg_finish(void);
extern U8 mmi_msg_club_get_item_total(void);
extern U8 mmi_msg_club_get_voice_item_index(void);
extern S8 *mmi_msg_club_get_number_ct(void);
extern S8 *mmi_msg_club_get_number_cu(void);
extern S8 *mmi_msg_club_get_number_begin(void);
extern S8 *mmi_msg_club_get_number_end(void);
extern S8 *mmi_msg_club_get_number_other_ct(void);
extern S8 *mmi_msg_club_get_number_other_cu(void);
extern S8 *mmi_msg_club_get_code_sms(void);
extern S8 *mmi_msg_club_get_code_dummy(void);
extern S8 *mmi_msg_club_get_code_devide(void);
extern S8 *mmi_msg_club_get_code_subscribe(void);
extern S8 *mmi_msg_club_get_code_order(void);
extern S8 *mmi_msg_club_get_code_explain(void);
extern S8 *mmi_msg_club_get_code_cancel(void);
extern S8 *mmi_msg_club_get_code_more(void);
#endif /* __MMI_MESSAGES_CLUB__ */ 

#if defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)
extern void highlight_nsm_remove_picture(void);
extern void mmi_nsm2_display_pic_at_index(S32 index);
extern void mmi_nsm2_entry_show_picture(void);
extern void mmi_nsm2_insert_pic_in_editor(void);
extern void mmi_nsm_remove_picture(void);
extern void highlight_nsm2_insert_picture_handler(void);
extern void mmi_entry_get_insert_pic_list(void);
extern void mmi_nsm2_pre_entry_show_pic(PU16 filePath, int is_short);
extern BOOL mmi_nsm2_pack_pic_msg(void);
extern void mmi_nsm2_save_pic_msg(U8 status);
extern void mmi_nsm2_get_pic_plus_txt_ota_data(U8 *bmpDataPtr, U8 *PicTextPtr);
extern U8 mmi_nsm2_get_curr_dcs(void);
extern void mmi_nsm2_save_write_msg_context(void);
extern void mmi_nsm2_save_and_goback(void);
extern void mmi_nsm2_save_reply_msg_context(void);
extern void mmi_nsm2_save_goto_idle_scr(void);
extern void mmi_nsm2_exit_write_msg(void);
extern void HighlightEditOptionInsertObject(void);
extern void Highlight_nsm_insert_SYS_Picture(void);

/* void Highlight_nsm_insert_SYS_Picture (void); */
extern void PictureSYSList(void);
extern void mmi_sys_get_picture_image(void);
extern void EntryScrInsertObjectMenu(void);
extern U16 mmi_nsm2_is_valid_picmsg(void);

/* void mmi_nsm2_entry_send_option(void); */

#endif /* defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__) */ 
#if (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__)
extern void mmi_msg_go_to_msg_menu(void);

/* U8 Is_UCS2_char_present(S8 *str,S32 str_len); */
#endif /* (defined(__MMI_SMART_MESSAGE_MO__) && !defined(__MMI_MESSAGES_EMS__)) || defined(__MMI_SMART_MESSAGE_MT__) */ 

extern void mmi_msg_on_enter_idle_screen(void);

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
extern void mmi_msg_entry_new_sim_msg_ind(void);
extern U8 mmi_msg_need_new_sim_msg_ind(void);
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#endif /* _PIXCOM_MESSAGES_EXTERN_DCL_H */ 

