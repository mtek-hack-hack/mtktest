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
 *  MMSTemplates.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the enums,constants,structures, function prototypes used in
 * MMSMessageTemplates.h
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_UMMSTEMPLATESECMMI_H
#define __MMI_UMMSTEMPLATESECMMI_H

#include "MMI_features.h"

#ifdef __MMI_MMS_2__

#include "MMIDataType.h"
#include "MMSXMLDef.h"
#define MAX_PREDEFINED_TEMPLATE	5
#define MAX_USERDEF_TEMPLATE 5
#define UMMS_MMI_MAX_SUBJECT_LEN (40)
#define UMMS_MMI_DEFAULT_BG_COLOR (MMA_DEFAULT_SMIL_BG_COLOR)
#define UMMS_MMI_DEFAULT_FG_COLOR (MMA_DEFAULT_SMIL_FG_COLOR)
//#define MMI_UMMS_MAX_XML_SIZE_IN_PEER_BUFFER  (2000)

#define UMMS_TEMPLATE_TEXT_FILE	"text0.txt"
#define UMMS_TEMPLATE_AUDIO_FILE "audio.mid"

#define MMI_UMMS_MAKE_TEMPLATE_FOLDER_PATH(x)      \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template", \
      MMI_PUBLIC_DRV/*, MMI_UC_FOLDER_NAME*/);

#define UMMS_MMI_MAKE_MMS_TEMPLATE_XML_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\template.xml",/*MMI_SYSTEM_DRV*/MMI_PUBLIC_DRV);

#define UMMS_MMI_MAKE_TEMPLATE_TEXT_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\text0.txt",/*MMI_SYSTEM_DRV*/MMI_PUBLIC_DRV);

#define UMMS_MMI_MAKE_IMAGE_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\",/*MMI_SYSTEM_DRV*/MMI_PUBLIC_DRV);

#define UMMS_MMI_MAKE_AUDIO_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\%s",/*MMI_SYSTEM_DRV*/MMI_PUBLIC_DRV, UMMS_TEMPLATE_AUDIO_FILE);

/* 
 * Define
 */

typedef enum
{
	MMI_UMMS_DEFAULT_TYPE,
	MMI_UMMS_USER_DEFINED_TYPE,
	MMI_UMMS_TYPE_NONE
}mmi_umms_templates_type_enum;

typedef enum
{
	MMI_UMMS_TEMPLATE_GEN_FOREGROUND,
	MMI_UMMS_TEMPLATE_GEN_BACKGROUND,	
	MMI_UMMS_TEMPLATE_GEN_STATE_NONE
}mmi_umms_templates_generation_state;

typedef struct
{
    U16 strId;
    U16 imageId;
    U16 audioId;
} mmi_umms_template_info_struct;

/* 
 * Extern Global Function
 */
extern BOOL mmi_template_fill_audio_data(mmi_umms_object_struct *audio_obj, const U8 *audio_buff, const U32 audio_len);
extern void mmi_umms_reset_template_state_on_end_key(void);
extern void mmi_umms_templates_init(void);
extern void mmi_umms_entry_templates(mmi_umms_templates_type_enum template_type);
extern void mmi_umms_entry_templates_screen(void);
extern void mmi_umms_pre_entry_default_template_screen(void);
extern void mmi_umms_pre_entry_user_defined_template_screen(void);
extern void mmi_umms_highlight_templates_user_defined(void);
extern void mmi_umms_highlight_templates_default(void);
extern void mmi_umms_hint_user_defined_template(U16 index);
extern void mmi_umms_hint_default_template(U16 index);
extern void mmi_umms_highlight_templates_options_view(void);
extern void mmi_umms_highlight_templates_options_write_message(void);
extern void mmi_umms_highlight_templates_options_properties(void);
extern void mmi_umms_highlight_templates_options_delete(void);
extern void mmi_umms_highlight_templates_options_delete_all(void);
extern void mmi_umms_template_hilite_folder_item(S32 index);
extern void mmi_umms_entry_templates_options_screen(void);
extern void mmi_umms_templates_view(void);
extern void mmi_umms_templates_write_message(void);
extern void mmi_umms_templates_properties(void);
extern void mmi_umms_exit_template_screen(void);
extern void mmi_umms_entry_templates_options_msg_id(void);
extern void mmi_umms_init_template_folder(void);
extern pBOOL mmi_umms_get_item_data_templates(
                S32 item_index,
                UI_string_type str_buff,
                PU8 *img_buff_p,
                U8 str_img_mask);

extern BOOL mmi_template_fill_text_data(const U16* file_path,const U16* subject);
extern BOOL mmi_fill_image_data(mmi_umms_object_struct *image_obj, U16 image_id);

extern U8	 mmi_umms_start_generate_template_xml(
                    const S8 *subject,
                    const U16 image_id,                    
                    const U8 *audio_buff,
                    const U32 audio_len);
extern void mmi_umms_get_template_resource(void);
extern void mmi_umms_send_create_template_req(mmi_umms_templates_type_enum template_type);
extern void mmi_umms_create_template_mms_rsp(void *inMsg);
extern void mmi_umms_save_template_mms_req(const U16 msg_id, const U16 msg_box);
extern void mmi_umms_save_template_mms_rsp(void *in_msg);
extern void mmi_umms_reset_template_msg(void);
extern void mmi_umms_get_templates_num_req(void);
extern void mmi_umms_get_templates_num_rsp(void *inMsg);
extern void mmi_umms_delete_all_template_req(void);
extern void mmi_umms_delete_all_template_rsp(void *inMsg);
extern void mmi_ummi_get_template_message_info_req(S32 box_type);
extern void mmi_ummi_get_template_message_info_rsp(void *inMsg);
extern void mmi_ummi_get_template_list_info_req(mmi_umms_templates_type_enum template_type);
extern void mmi_ummi_get_template_list_info_rsp(void *inMsg);
extern void mmi_umms_usr_def_templ_get_msg_content_req(U32 msgId);
extern void mmi_umms_usr_def_templ_get_msg_content_rsp(void *msgRsp);
extern void umms_mmi_show_template_error_msg(U8 result);
extern void mmi_umms_delete_template_rsp(void *inMsg);
extern void mmi_umms_delete_template_req(const U32 msg_id, const mma_folder_enum folder_id);
extern void mmi_umms_save_template_file_callback(void* info);
extern void mmi_umms_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER);
#endif /* __MMI_MMS_2__ */
#endif /* __MMI_UMMSTEMPLATESECMMI_H */ 

