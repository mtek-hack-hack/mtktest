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
 * PhoneBookGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PhoneBook global prototypes 
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
#ifndef _PHONEBOOKGPROT_H
#define _PHONEBOOKGPROT_H

#include "MMIDataType.h"
#include "PhoneBookTypes.h"

/* 
 * Typedef 
 */
typedef void (*FuncPhbListCallback) (MMI_PHB_VCARD_STRUCT *resut_entry);
typedef void (*mmi_phb_get_data_callback_type)(S8* phb_name, S8* phb_data);
typedef void (*mmi_phb_get_index_from_group_callback_type)(U16 cnt, U16 *PhbIndex);
#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
typedef MMI_BOOL (*mmi_phb_check_selected_index_callback_type)(U16 cnt, U16 *PhbIndex);
#endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */
#if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__)
typedef void (*mmi_phb_save_entry_from_others_callback_type) (mmi_phb_add_from_others_error_enum error_result, U16 store_index);
#endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */

/* 
 * Extern Global Function
 */
extern PS8 lookUpName(PS8);     /* Search for the number entry for corresponding name input */
extern PS8 lookUpNumber(PS8);   /* Search for the name entry for corresponding number input */
extern void mmi_phb_generic_enter_list(FuncPhbListCallback func_list);
extern void mmi_phb_generic_enter_list_result(void);

extern void mmi_phb_idle_enter_phb_list(void);
extern void SaveNumberFromIdleScrn(PS8, U8);    /* Saves a number from the idle screen */
extern void mmi_phb_get_sim_entry_by_location(U16);

#ifdef __MMI_DUAL_SIM_MASTER__
extern PHB_CM_INTERFACE mmi_phb_call_get_data_for_call_mgnt(PU8 number, BOOL is_mo_call, U8 simInterface);
#else /* __MMI_DUAL_SIM_MASTER__ */
extern PHB_CM_INTERFACE mmi_phb_call_get_data_for_call_mgnt(PU8 number, BOOL is_mo_call);
#endif /* __MMI_DUAL_SIM_MASTER__ */
extern void mmi_phb_call_set_dial_from_list(U8 value);
extern MMI_BOOL mmi_phb_get_num_by_sim_index(U8 sim_location, U16 index, S8* ucs2_num, U16 ucs2_len);
extern void mmi_phb_set_global_store_index(U16 store_index);
extern S8 *mmi_phb_image_get_path_from_id(U16 record_index);
extern S8 *mmi_phb_video_get_path_from_id(U16 record_index);
extern void mmi_phb_call_enter_from_active_call(void);
extern void mmi_phb_call_enter_from_deflect_option(void);
extern void mmi_phb_call_enter_from_divert(void);
extern void mmi_phb_call_send_data_for_deflect(void);
extern void mmi_phb_list_enter_first_from_active_call(void);
extern void mmi_phb_list_enter_last_from_active_call(void);

extern void mmi_phb_sat_handler(BOOL reset_adn);
extern void mmi_phb_sat_handler_end_current_op(void);

#if defined(__MMI_PHB_GENERIC_MULTI_SELECT__)
extern void mmi_phb_generic_multi_select_list_pre_entry(U8 filter_type, U16 select_limit, mmi_phb_get_index_from_group_callback_type list_view_call_back, mmi_phb_check_selected_index_callback_type list_check_call_back);
#endif /* defined(__MMI_PHB_GENERIC_MULTI_SELECT__) */

extern void mmi_phb_sms_enter_send_by_group(void);
extern void mmi_phb_sms_send_data_choose_entry(void);
extern void mmi_phb_sms_send_data_for_entry_name_only(void);
extern void mmi_phb_sms_send_data_for_entry_list(void);
extern void mmi_phb_sms_send_data_for_entry(S8 *number);
extern void mmi_phb_sms_send_data_for_group(void);

extern BOOL mmi_phb_callergroup_restore_default(void);
extern void mmi_phb_speed_dial_enter_phb(void);

extern void mmi_phb_update_delete_image(U16);
extern void mmi_phb_update_delete_image_caller_group(U16);
extern void mmi_phb_update_delete_audio(U16);
extern void mmi_phb_update_delete_audio_caller_group(U16);
#ifdef __MMI_DUAL_SIM_MASTER__
extern U8 mmi_phb_check_valid_sos_number(S8 *, U8);
#else
extern U8 mmi_phb_check_valid_sos_number(S8 *);
#endif

extern void mmi_phb_fdn_get_list_to_ram(void);

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
extern void mmi_phb_retrieve_bday(S8* b_string, S8* pb_year, S8* pb_mon, S8* pb_day, BOOL change_flag);
#endif

#ifdef __MMI_PHB_INFO_FIELD__
extern void mmi_phb_info_read_data_to_buff(U16 store_index);
#endif

#if defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__)
extern void mmi_phb_save_entry_from_others(
        S8 *ucs2_name,
        S8 *number,
        PHB_OPTIONAL_FIELDS_STRUCT *opt_fields,
        S8 *b_day,
        PHB_INFO_FIELDS_STRUCT *info_fields,
        S8 *nick_name,
        mmi_phb_save_entry_from_others_callback_type phb_callback);
#endif /* defined(__MMI_BARCODEREADER__) || defined(__MMI_BROWSER_2__) */

extern void mmi_phb_list_pre_entry_for_number_and_email(U8 filter_type, mmi_phb_get_data_callback_type list_view_call_back);

#if defined(MMS_SUPPORT)
extern void EntryPhbFromMMSNumber(void);
extern void EntryPhbFromMMSEmail(void);
extern void EntryPhbFromMMSAll(void);

#ifdef __MMI_PHB_SEND_MMS_FROM_PHB__
extern void mmi_phb_mms_send_data_choose_entry(void);
#endif 
#endif /* defined(MMS_SUPPORT) */ 

extern void mmi_phb_fmgr_from_file_mgr(S8 *path);
extern U32 mmi_phb_util_convert_number_to_int(PU8);

extern PS8 BigEndianToLittleEndian(PS8, PS8);
extern pBOOL GetUCS2Flag(PS8);
extern U8 GetUCS2ExtendedNum(PS8 buffer, U8 max_buffer_len);
extern void PhbAsciiToGSM7Bit(PU8);
extern void PhbGSM7BitToAscii(PU8, U8);
extern void mmi_phb_truncate_pbname_buffer(U8 storage);

#if defined(__MMI_EMAIL__)
extern void mmi_phb_email_enter_list(void);
extern void mmi_phb_email_choose_entry(void);
extern void mmi_phb_email_save_entry_to_phb(S8 *ucs2_name, S8 *ucs2_email);
#endif /* defined(__MMI_EMAIL__) */ 

#if defined(MMS_SUPPORT)
extern void mmi_phb_email_save_entry_to_phb_from_jmms(S8 *ucs2_email);
extern void mmi_phb_entry_dummy_screen(void);
#endif /* defined(MMS_SUPPORT) */ 

#if defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__)
extern void mmi_phb_get_address_from_caller_group(U8 address_type, mmi_phb_get_index_from_group_callback_type get_address_call_back);
#endif /* defined(__MMI_MESSAGES_SEND_BY_GROUP__) || defined(__UNIFIED_COMPOSER_SUPPORT__)  || defined(__MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__)*/
#if defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__)
extern U8* mmi_phb_get_email_p(U16 store_index, U8* address_length);
#endif /* __UNIFIED_COMPOSER_SUPPORT__  || defined(__MMI_JATAAYU_MMS_ADD_NUMBER_BY_GROUP__)*/

#if defined(__MMI_VRSD_DIAL__)
extern void mmi_phb_vrsddial_enter_tag_list(void);
extern void mmi_phb_vrsddial_get_tag_list_index(S32 nIndex);
extern void mmi_phb_vrsddial_playback_by_store_index(void);
extern void mmi_phb_vrsddial_enter_no_tag_list(void);
extern void mmi_phb_highlight_op_voice_dial(void);
extern void mmi_phb_vrsddial_auto_dial(U16 store_index);
#endif /* defined(__MMI_VRSD_DIAL__) */ 

#if defined(__MMI_VRSI__) && defined(__MMI_VRSI_TRAIN_TAG__)
extern void mmi_phb_vrsi_pre_entry_list(void);
extern void mmi_phb_vrsi_exit_entry_list(void);
extern void mmi_phb_vrsi_entry_list_callback(void);
#endif /* defined(__MMI_VRSI__) && defined(__MMI_VRSI_TRAIN_TAG__) */ 

#ifdef __MMI_VOIP__
extern PHB_VOIP_INTERFACE mmi_phb_call_get_data_for_voip(PU8 uri, BOOL is_mo_call);
extern void mmi_phb_save_entry_for_service_field(PS8 name, PS8 uri, U8 enter);
#endif /* __MMI_VOIP__ */

#ifdef __SYNCML_SUPPORT__
extern U16 mmi_phb_get_phone_index_arrary(U16* index_array);
extern void mmi_phb_sync_vcard(U8 action, S8 *path, U16 index, U8 sync_charset);
extern U16 mmi_phb_sync_get_record_size(void);
#endif /* __SYNCML_SUPPORT__ */

#ifdef __MMI_BIRTHDAY_REMINDER__
MMI_BOOL mmi_phb_get_name_number(U16 store_index, U8* out_name, U8* out_number);
#endif /* __MMI_BIRTHDAY_REMINDER__ */

extern BOOL mmi_phb_util_check_entry_exist(U16 store_index);
extern U8 mmi_phb_check_is_phonebook_full(void);
extern U8 mmi_phb_calculate_number_valid_length(S8 *in_number);
#if defined(__MMI_UCM__)
/* used for getting image and video id or path */
extern void mmi_phb_get_caller_image_info(const mmi_phb_caller_image_input_struct* image_input, mmi_phb_caller_image_info_struct* image_info);
#endif /* defined(__MMI_UCM__) */
extern U16 mmi_phb_get_max_pb_phone_entries(void);
extern U16 mmi_phb_get_max_pb_sim_entries(void);
#ifdef __MMI_DUAL_SIM_MASTER__
extern U16 mmi_phb_get_max_pb_sim2_entries(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */

extern MMI_BOOL mmi_phb_compare_numbers(S8 *number1, S8 *number2);

#endif /* _PHONEBOOKGPROT_H */ 

