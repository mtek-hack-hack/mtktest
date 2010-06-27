/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   JMMSJSRHandler.h
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * jmms_store_handling.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_JMMSJSRHANDLING_H
#define __MMI_JMMSJSRHANDLING_H

#include "ddl.h"
#include "jcal.h"
#include "jcalnet.h"
#include "jdi_wspdatatype.h"

#include "JsrTypes.h"
#include "miscutils.h"
#include "MM1DataTypes.h"
#include "MessagingDatatypes.h"
#include "MessagingAPI.h"
#include "PrvMessagingDataTypes.h"
#include "JMMSStructs.h"

/* 
 * Define
 */

#define MMI_JMMS_JSR_SUBJECT_ENCODED_VALUE  106

/* 
 * Typedef 
 */

typedef enum
{
    MMS_PLMN,       /* !< PLMN type of address, e.g. +467055566622 */
    MMS_EMAIL,      /* !< E-Mail type of address, e.g. foo@bar.com */
    MMS_IPV4,       /* !< IPv4 type of address, e.g. 123.456.789.123 */
    MMS_UNSUPPORTED /* !< Unknown address type, Not to be sent */
} mmi_jmms_java_addresses_type_enum;

typedef enum
{
    MMS_US_ASCII = 3,
    MMS_UTF8 = 106,
    MMS_UCS2 = 1000,
    MMS_UTF16BE = 1013,
    MMS_UTF16LE = 1014,
    /* < UTF-16 is to be used only if the document starts with a UTF-16 BOM  */
    MMS_UTF16 = 1015,
    MMS_ISO_8859_1 = 4,
    MMS_UNKNOWN_CHARSET = 0,
    MMS_AUTO_RR = 9999  /* Only used for Read report 1.0 choses to use ASCII if only ASCII chars and UTF8 in all other cases. */
} mmi_jmms_charset;

typedef enum
{
    JSR_APPLICATION_ID = 0,
    JSR_REPLY_TO_APPLICATION_ID
} mmi_jsr_string_id_enum;

/* 
 * Extern Global Variable
 */

/* 
 * Extern Global Function
 */

extern void mmi_jmms_get_folder_name_from_folderId(U8 folder_id, S8 *file_name);
extern void mmi_jmms_at_get_folder_info(U8 folder_id, mmi_jsr_folder_info_struct *folder_info_p);
extern void mmi_jmms_at_get_address_and_subject(
                mmi_jsr_message_info_struct *list,
                U32 index,
                S8 *address,
                S8 *subject);
extern void mmi_jmms_at_get_message_list(U8 folder_id, mmi_jsr_message_info_struct *list);

extern mmi_jsr_result_enum mmi_jmms_at_save_mms(char *file_name, U32 *msg_id);
void mmi_jmms_at_delete_mms(U8 folder_id, U32 msg_id, void (*callback) (mmi_jsr_result_enum result));

extern mmi_jsr_result_enum mmi_jmms_jsr_create_mms(wap_mmc_send_appmms_req_struct *message, U8 *peer_buf);
extern JC_RETCODE mmi_jmms_jsr_form_send_request_pdu(MM1_HANDLE mm1_handle, MESSAGING_HANDLER *msg_handle_p);

extern mmi_jsr_result_enum mmi_jmms_java_mms_error(JC_RETCODE error_code);

extern void mmi_jmms_jsr_send_mms(MMI_JMMS_JSR_SEND_CALLBACK send_callback);
extern mmi_jsr_result_enum mmi_jmms_jsr_add_media_object(wap_mmc_post_appmms_msg_part_res_struct *message);
extern void mmi_jmms_jsr_delete_temp_media_files(void);
extern S8 *mmi_jmms_jsr_get_application_string_from_content_type(S8 *content_type_p, mmi_jsr_string_id_enum str_id);
extern void mmi_jmms_jsr_get_message_details(U32 msg_id, MMI_JMMS_JSR_RETRIEVE_CALLBACK recv_callback);

/* PMT HIMANSHU START 20060425 */
extern MMI_BOOL mmi_jmms_jsr_generate_recv_msg_body_part(
                    U32 msg_id,
                    U8 *bdy_part_no,
                    U8 total_objects,
                    wap_mmc_read_appmms_msg_part_rsp_struct *response);
/* PMT HIMANSHU END 20060425 */
void mmi_jmms_jsr_cancel_send_mms(U32 msg_id, void (*callback) (mmi_jsr_result_enum result));
extern MMI_BOOL mmi_jmms_check_msg_id(U32 msg_id);
extern void mmi_jmms_update_folder(void);
extern void mmi_jmms_jsr_delete_msg(U32 msg_id);

extern mmi_jsr_result_enum mmi_jmms_java_mms_error(JC_RETCODE error_code);

extern JC_RETCODE mmi_jmms_is_message_found(U8 folder_id, U32 msg_id);

extern JC_RETCODE mmi_jmms_get_content_type(CONTENT_DATA *encapsulated_content_p, JC_INT8 **mms_content_type);

extern void mmi_jmms_mm1_encode_continue_start_timer(void);
extern void mmi_jmms_mm1_encode_continue_callback(void);

extern void mmi_jmms_mm1_decode_continue_start_timer(JC_UINT32 total_obj, error_callback new_err_cb);

extern void mmi_jmms_mm1_send_callback(JC_RETCODE ret_code);

extern void mmi_jmms_mm1_decode_continue_callback(void);
extern void mmi_jmms_jsr_async_get_message_details_callback(JC_RETCODE ret_code);

extern mmi_jmms_java_addresses_type_enum mmi_jmms_java_map_address_type(MMSAddressTypes type);

/* 
 * This function is defined to get the attachment path for java files.
 * 
 * Written By  : Raj Kumar Gupta
 * Date        : Augest 04, 2006
 */
#ifdef __MMI_JMMS_JAVA_MMS_SUPPORT__
extern void mmi_jmms_get_attachment_filepath(S8 *filename, mms_get_attachment_rsp_struct *msg);
#endif 

#endif /* __MMI_JMMSJSRHANDLING_H */ 

