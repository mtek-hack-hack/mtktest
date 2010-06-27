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
 *
 * Filename:
 * ---------
 *	dt_utility.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ....
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
*****************************************************************************/


#ifndef DT_UTILITY_H
#define DT_UTILITY_H

extern kal_bool dt_eq_fs_read_req(void);
extern kal_bool dt_eq_general_fs_access_req(dt_fs_opcode_enum action,
                                 							dt_app_type_enum app_type, kal_wchar *file_name, 
                                 							kal_uint8 *data, kal_uint16 data_len);
extern void dt_eq_fs_efsl_list(kal_wchar* filename, FS_DOSDirEntry* fileinfo);
extern void dt_eq_fs_efsl_next(void);
extern void dt_start_data_download_timer_hdlr (void);
extern void dt_resume_download(void);
extern void dt_data_download_error_hdlr (void);
extern void dt_clear_download_timer(void);
extern void dt_get_downloadFullpath(kal_wchar * file_name);
//extern void dt_clear_rename_path(void);
extern void dt_unicode_to_string (kal_uint8 *val, kal_uint8 *str);
extern void dt_ascii_to_ucs2(kal_uint8* src, kal_wchar* dest);
extern kal_bool dt_ucs2_to_ascii(kal_wchar* ucs2_src, kal_uint8* ascii_dest);
extern void dt_print_hex_value (kal_uint8 *val, kal_uint8 *str);
extern void dt_toUpper (kal_uint8 *str);
extern void dt_check_hex_value (kal_uint8 *str, kal_uint8 *val);
extern void dt_int_to_ascii_converter (kal_uint32 digit, kal_uint8 *buff_ptr);
extern kal_uint32 dt_int_validator_ext(kal_uint8 *error_cause, dt_string_struct *source_string_ptr, 
									kal_uint8 delimiter);
extern kal_uint32 dt_int_validator(dt_string_struct *source_string_ptr, kal_uint8 delimiter);
extern kal_uint8 dt_string_validator_ext (kal_uint8 * error_cause, dt_string_struct *source_string_ptr, 
										kal_uint8 delimiter, kal_uint16 max_length,  kal_uint8 *str);
extern kal_uint8 dt_string_validator (dt_string_struct *source_string_ptr, kal_uint8 delimiter, kal_uint16 max_length, 
									kal_uint8 *str);
extern kal_uint8 dt_find_cmd_mode (dt_string_struct *source_string_ptr);
extern void dt_reset_state(void);

#endif /*DT_UTILITY_H*/


