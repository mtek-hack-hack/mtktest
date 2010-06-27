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
 *  MMSJSRSndRcv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * MMSTemplates.c
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JSR_SNDRCV_H
#define _JSR_SNDRCV_H

#ifdef __MMI_MMS_2__
// #include "mmsadp.h"
#include "MMSXMLDef.h"

//#define MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER    (2000)
#define MMI_UMMS_DEFAULT_BG_COLOR               (MMA_DEFAULT_SMIL_BG_COLOR)
#define MMI_UMMS_DEFAULT_FG_COLOR               (MMA_DEFAULT_SMIL_FG_COLOR)
#define DEFAULT_READ_REPORT_DURING_SENDING         FALSE
#define DEFAULT_DELIVERY_REPORT_DURING_SENDING     FALSE
#define DEFAULT_EXPIRY_TIME                     MMA_EXPIRY_MAX
#define DEFAULT_SENDER_VISIBILTY             TRUE
#define DEFAULT_DELIVERY_TIME                MMA_DELIVERY_IMMEDIATE
#define DEFAULT_SLIDE_DURATION                  5000

#define MMI_UMMS_MAX_SUBJECT_LEN             (40)

#define MMI_JSR_SUBJECT_ENCODED_VALUE           106
#if 1
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
} MmsCharset;
#endif /* 1 */ 

#define MMI_UMMS_MAKE_MMS_XML_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\_UC\\template.xml",MMI_PUBLIC_DRV);

extern U8 mmi_jsr_insert_slide(mmi_umms_object_struct *obj, mmi_umms_object_type type);

extern U8 mmi_jsr_add_address_in_addresse_list(
            S8 *address,
            mmi_umms_address_type_enum type,
            mmi_umms_address_group_type_enum group);

extern U8 mmi_jsr_add_media_object(wap_mmc_post_appmms_msg_part_res_struct *message);
extern U8 mmi_jsr_insert_text_object(wap_mmc_post_appmms_msg_part_res_struct *message, U8 *media_buffer_p);
extern U8 mmi_jsr_insert_object(wap_mmc_post_appmms_msg_part_res_struct *message, mmi_umms_object_type type);
extern U8 mmi_jsr_insert_slide(mmi_umms_object_struct *obj, mmi_umms_object_type type);
/*extern void mmi_jsr_reset_msg(void);*/
extern void mmi_jsr_reset_xml_struct_msg(void);
extern void mmi_jsr_create_mms_req(void);
extern void mmi_jsr_send_mms_req(U16 msg_id);
extern U8 mmi_umms_fill_text_data(U16 *file_path, U16 *subject);
extern void mmi_jsr_create_for_send_mms_rsp(void *inMsg);
/* S32 mmi_umms_create_mms_xml_description_file(mmi_umms_xml_msg_struct *umms_msg, U8* file_path); */
extern void mmi_jsr_get_msg_content_req(void);
extern JsrResult mmi_jsr_decode_mms_header(wap_mmc_send_appmms_req_struct *message, U8 *buffer);
#endif /* __MMI_MMS_2__ */
#endif /* _JSR_SNDRCV_H */ 

