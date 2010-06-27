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
 *  MMSViewer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Viewer APP 
 *
 *
 * Author: Sukrit K Mehra (PMT0050)
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_MMS_2__
#ifdef __DRM_SUPPORT__
#include "Drm_def.h"
#include "Drm_gprot.h"
#endif /* __DRM_SUPPORT__ */ 
#include "App_mine.h"
#include "ProtocolEvents.h"
#include "CallManagementGprot.h"
#include "ProfileGprots.h"

#include "wap_ps_struct.h"
#include "Ps_trace.h"
#include "Conversions.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "mdi_datatype.h"
#include "Mdi_video.h"

#include "MMSAppGprot.h"
#include "MMSMsgXMLTags.h"
#include "MMSViewerAPPDefs.h"
#include "MMSViewerDefs.h"
#include "MMSAppResDef.h"
#include "MMSMsgCommonProt.h"
#include "MMSMessageSettings.h"
#include "MMSMessageSettingsUtils.h"
#include "FileManagerDef.h"

/* Parser Context */
static mmi_mv_msg_parser_cntx_struct g_mv_parser_cntx;

/* Viewer APP Context */
static mmi_mv_context_struct g_mv_cntx;

/* Use Detail Context */
static mmi_mv_use_details_cntx_struct g_use_details_cntx;

/* DRM Process Context */
static mmi_mv_drm_process_cntx_struct g_mv_drm_process_cntx;

/* Pointers to Objects */
static p_mv_object *mmi_mv_object=NULL;

/* Utility Functions */
static U8 mmi_mv_delete_screen_cb(void* unused);
static void mmi_mv_append_temp_path(PS8 file_name);
static MMI_BOOL mmi_mv_get_filename_by_id(U32 id, PU16 vf, PU16 *file_path, PS32 vf_parent_file_handle);
static MMI_BOOL mmi_mv_allow_audio_playing(void);
static void mmi_mv_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER);
static void *mmi_mv_allocate_mem(U32 size);
static void mmi_mv_free_mem(void *pmem);
static void *mmi_mv_alloc_mem_for_use_details(U32 size);
static void mmi_mv_free_use_detail_mem(void *pmem);

/* XML Parser */

/* Attachment Related */
static void mmi_mv_insert_object_to_attachment(
                mmi_mv_object_struct *object,
                mmi_mv_attachment_info_struct *attachment);
static mmi_mv_attachment_info_struct *mmi_mv_insert_attachment(void);

/* Slide Related */
static U32 mmi_mv_convert_ascii_hex_to_dec(const U8 *character);
static wgui_mv_slide_layout_enum mmi_mv_convert_mms_layout_type(U8 layout_type);
static wgui_mv_slide_struct *mmi_mv_get_end_slide(void);
static wgui_mv_slide_struct *mmi_mv_insert_slide(wgui_mv_slide_struct *cur_slide);
static wgui_mv_slide_struct *mmi_mv_insert_slide_by_number(U16 slide_number);

/* Object Related */
static mmi_mv_object_struct *mmi_mv_insert_object_to_list_tail(void);
static void mmi_mv_insert_object_to_slide(
                mmi_mv_object_struct *object,
                wgui_mv_slide_struct *slide,
                mmi_mv_object_type_enum object_type);
static MMI_BOOL mmi_mv_match_object_id(void);

/* XML Parser */
static void mmi_mv_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error);
static void mmi_mv_xml_end_element_hdlr(void *data, const char *el, int error);
static void mmi_mv_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error);
static XML_RESULT_ENUM mmi_mv_parse_mms_xml_description_file(const PU16 file_path, U32 flags);

/* Viewer Category Related Functions */
static void mmi_mv_app_exit_fn(void);
static void mmi_mv_view_msg_no_rr(void);
static void mmi_mv_entry_send_rr_confirmation(void);
static void mmi_mv_view_msg(void);

/* Get Use Detail Functionality */
kal_bool mmi_mv_use_details_check_stop_cb(
            applib_addr_type_enum type,
            applib_address_node_struct *node,
            kal_uint32 num);
static void mmi_mv_end_compute_use_details(void);
static void mmi_mv_get_urls_on_slide(void);
static void mmi_mv_get_emails_on_slide(void);
static void mmi_mv_get_numbers_on_slide(void);
static MMI_BOOL mmi_mv_load_ucs2_txt_to_buffer(PU8 dest_buffer, U32 dest_buffer_size, U32 object_id);
static void mmi_mv_start_compute_use_details(void);
static void mmi_mv_send_get_use_details_rsp(void);
static void mmi_mv_get_use_details_deinit(void);
static void mmi_mv_get_use_details_req_hdlr(void *msgPtr);

/* Send Read Report */
static void mmi_mv_send_read_report_req(void);

/* Set Readmark */
static void mmi_mv_set_readmark_req(void);

/* DRM Related */
static void mmi_mv_image_expired_callback(S32 result, S32 id);
static MMI_BOOL mmi_mv_start_consume_image_rights(U32 object_id, PU16 file_path);
static MMI_BOOL mmi_mv_start_consume_rights(U32 object_id, PU16 file_path);
static void mmi_mv_stop_consume_rights(U32 object_id);
static void mmi_mv_update_rights_by_id(U32 id, MMI_BOOL rights_expired);
static MMI_BOOL mmi_mv_check_rights_by_id(U32 id);
static void mmi_mv_drm_async_cb(kal_uint8 serial, 
                                kal_int32 result, 
                                kal_char *dest_content_type, 
                                kal_char *dest_file_ext, 
                                kal_uint32 plaintext_len, 
                                kal_uint32 plaintext_offset_in_dm);
static void mmi_mv_process_single_drm_file(mmi_mv_object_struct *obj);
static void mmi_mv_process_drm_files(void);

/* Get MMS CONTENT & XML Related */
static MMI_BOOL mmi_mv_add_slide_per_object(mmi_mv_object_struct *obj, U32 id);
static MMI_BOOL mmi_mv_handle_multipart_msg(void);
static void mmi_mv_proceed_to_view(void);
static void mmi_mv_get_mms_content_req(void);

/* ASM Related */
static void mmi_mv_allocate_mem_and_req_msg_content(void);
static void mmi_mv_stop_viewer_callback(void);
static void mmi_mv_request_asm_success_callback(void);
static void mmi_mv_exit_viewer_application(void);

/* Misc */
static void mmi_mv_rsk_fn(void);
static void mmi_mv_progress_screen(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_delete_screen_cb
 * DESCRIPTION
 *  callback for SetDelScrnIDCallbackHandler
 * PARAMETERS
 *  unused
 * RETURNS
 *  return whether successful
 *****************************************************************************/
U8 mmi_mv_delete_screen_cb(void* unused)
{
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] mmi_mv_delete_screen_cb *\n");

    StopTimer(MMS_VIEWER_TIMER);
    
    /* Send Read Report */
    if (g_mv_cntx.send_read_report == MMI_TRUE)
    {
        mmi_mv_send_read_report_req();
    }
    if (g_mv_cntx.deinit_on_exit == MMI_TRUE)
    {
        mmi_umms_reset_global();
    }
    /* If Viewer active progress & confirm already deleted */
    /* If confirm active progress already deleted & viewer not yet entered */
    /* If progress active confirm & viewer not yet entered */
    /* Therefore, no need to delete screens! */

    mmi_mv_get_use_details_deinit();

    if (g_mv_drm_process_cntx.serial != 0)
    {
#ifdef __DRM_SUPPORT__        
        DRM_async_cancel_process(g_mv_drm_process_cntx.serial);
#endif
    }

    if (g_mv_drm_process_cntx.vf_handle != 0)
    {
        FS_Close(g_mv_drm_process_cntx.vf_handle);
    }

    if (g_mv_cntx.adm_pool_id)
    {
        kal_adm_delete(g_mv_cntx.adm_pool_id);
    }
    if (g_mv_cntx.ptr_asm_pool)
    {
        applib_mem_ap_free(g_mv_cntx.ptr_asm_pool);
    }

    /* Do this at last */
    memset(&g_mv_drm_process_cntx, 0, sizeof(g_mv_drm_process_cntx));
    memset(&g_mv_cntx, 0, sizeof(mmi_mv_context_struct));
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_append_temp_path
 * DESCRIPTION
 *  Modiy file_name to file_path
 * PARAMETERS
 *  file_name                          [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_append_temp_path(PS8 file_name)
{
    S32 i=0, j=0;
    U32 file_len = ENCODING_LENGTH * mmi_ucs2strlen(file_name);
    U8 folder_path[MMI_MV_TEMP_PATH_BUFFER_LEN];
    U8 folder_len=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(folder_path, 0, MMI_MV_TEMP_PATH_BUFFER_LEN);
    kal_wsprintf( (kal_uint16 *)folder_path, "%c:\\%s", MMI_PUBLIC_DRV, MMI_MV_TEMP_FOLDER);
    folder_len = mmi_ucs2strlen((PS8)folder_path);

    /* shift whole file_name by len of D:\_mv say 12 */
    for(i=0; i<folder_len;++i)
    {
        for(j=file_len; j>=0;j-=2)
        {
           file_name[j+2] = file_name[j];
           file_name[j+3] = file_name[j+1];
        }
        file_len +=2;
    }

    memcpy(file_name, folder_path, folder_len*ENCODING_LENGTH);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_filename_by_id
 * DESCRIPTION
 *  Get filename by id 
 * PARAMETERS
 *  id                          [IN]        
 *  vf                          [IN]        
 *  file_path                   [OUT]         
 *  vf_parent_file_handle       [IN]        
 * RETURNS
 *  success or not
 *****************************************************************************/
static MMI_BOOL mmi_mv_get_filename_by_id(U32 id, PU16 vf, PU16 *file_path, PS32 vf_parent_file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *temp = mmi_mv_object[id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == NULL)
    {
        return MMI_FALSE;
    }

    if (temp->is_virtual_file == MMI_TRUE)
    {
        S32 file_handle;
        S32 result;
        U32 offset;
        U32 size;

        if (temp->drm_type == MMA_DRM_FL_CD)
        {
            offset = temp->drm_offset;
            size = temp->drm_size;
        }
        else
        {
            offset = temp->offset;
            size = temp->size;
        }

        /* Open Parent File Handle */
        file_handle = FS_Open(temp->file_path, FS_READ_ONLY | FS_OPEN_SHARED);

        if (file_handle <= 0)
        {
            /* Return because can't get parent file handle */
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] Can Not Open Parent File Handle  *\n");
            *vf_parent_file_handle = 0;
            return MMI_FALSE;
        }

        result = FS_GenVirtualFileName(file_handle, (U16*) vf, (unsigned int)FS_GenVFN_SIZE, offset, size);

        if (result < 0)
        {
            /* Can't create VF, close parent file handle */
            FS_Close(file_handle);
            *vf_parent_file_handle = 0;
			PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] Can Not Create VF File  *\n");
            return MMI_FALSE;
        }

        mmi_ucs2cat((PS8) vf, (PS8) ".");
        if (temp->drm_type == MMA_DRM_SD || temp->drm_type == MMA_DRM_SD_NO_RIGHT)
        {
            /* postfix drm extension */
            mmi_ucs2ncat((PS8) vf, (PS8) temp->drm_ext, FMGR_MAX_EXT_LEN);
        }
        else
        {
            mmi_ucs2ncat((PS8) vf, (PS8) mmi_fmgr_extract_ext_file_name((PS8) temp->file_name), FMGR_MAX_EXT_LEN);
        }

        /* Parent File handle & VF is valid */
        *vf_parent_file_handle = file_handle;
        *file_path = vf;
    }
    else
    {
        *file_path = temp->file_path;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_allow_audio_playing
 * DESCRIPTION
 *  Callback to category
 * PARAMETERS
 *  void
 * RETURNS
 *  Allow or Disallow
 *****************************************************************************/
static MMI_BOOL mmi_mv_allow_audio_playing(void)
{

    MMI_ALERT_TYPE alertType = GetMtCallAlertTypeEnum();

    if (
        (alertType != MMI_VIBRATION_AND_RING && alertType != MMI_VIBRATION_THEN_RING && alertType != MMI_RING) 
        || !(!isInCall() || (isInCall() && GetWapCallPresent())) 
        || IsMeetingModeActivated() 
        || IsSilentModeActivated()
        )
    {
        /* If the profile setting is meeting or silent  */
		PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] Disallow Audio Play! *\n");
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_send_message
 * DESCRIPTION
 *  utility function to send a message on ext queue
 * PARAMETERS
 *  MOD_SRC         [IN]        
 *  MOD_DEST        [IN]        
 *  MSG_SAP         [IN]        
 *  MSG_ID          [IN]        
 *  LOCAL           [IN]        
 *  PEER            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_send_message(
                module_type MOD_SRC,
                module_type MOD_DEST,
                U8 MSG_SAP,
                const U16 MSG_ID,
                void *LOCAL,
                void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslSapId = MSG_SAP;
    Message.oslMsgId = MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_allocate_mem
 * DESCRIPTION
 *  alloc memory for mms viewer application
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_mv_allocate_mem(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return kal_adm_alloc(g_mv_cntx.adm_pool_id, size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_free_mem
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  pmem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_free_mem(void *pmem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_mv_cntx.adm_pool_id, pmem);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_alloc_mem_for_use_details
 * DESCRIPTION
 *  alloc memory for use details
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void *mmi_mv_alloc_mem_for_use_details(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_MV_UNIT_TEST
    if (kal_adm_get_max_alloc_size(g_mv_cntx.adm_pool_id) < size)
    {
        ASSERT(0);
    }
#endif /* MMI_MV_UNIT_TEST */ 
    return kal_adm_alloc(g_mv_cntx.adm_pool_id, size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_free_use_detail_mem
 * DESCRIPTION
 *  free use detail memory
 * PARAMETERS
 *  pmem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_free_use_detail_mem(void *pmem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(g_mv_cntx.adm_pool_id, pmem);
}

/* Utility Functions End */

/* XML Parser */

/* Attachment Related */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_insert_object_to_attachment
 * DESCRIPTION
 *  inserts object to attachment
 * PARAMETERS
 *  object          [IN]        
 *  attachment      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_insert_object_to_attachment(
                mmi_mv_object_struct *object,
                mmi_mv_attachment_info_struct *attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attachment->object = object;
    object->reference_count++;

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_insert_attachment
 * DESCRIPTION
 *  create & insert attachment object
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_mv_attachment_info_struct *mmi_mv_insert_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_attachment_info_struct *new_attach = NULL;
    U32 attach_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attach_size = sizeof(mmi_mv_attachment_info_struct);
    new_attach = mmi_mv_allocate_mem(attach_size);

    if (!new_attach)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] mmi_mv_insert_attachment: MMI_MV_OUT_OF_MEM *\n");
        g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
        return new_attach;
    }

    memset(new_attach, 0, attach_size);

    if (g_mv_cntx.total_attachment_num == 0)
    {
        ASSERT(g_mv_cntx.attachment_head == NULL);
        g_mv_cntx.attachment_head = new_attach;

        new_attach->next = NULL;
        new_attach->previous = NULL;
    }
    else
    {
        mmi_mv_attachment_info_struct *cur_attach = g_mv_cntx.attachment_head;

        ASSERT(cur_attach);

        for (; cur_attach->next != NULL; cur_attach = cur_attach->next)
        {
            i++;
        }

        ASSERT(i == g_mv_cntx.total_attachment_num);

        cur_attach->next = new_attach;
        new_attach->next = NULL;
        new_attach->previous = cur_attach;
    }

    g_mv_cntx.total_attachment_num++;
    g_mv_cntx.msg_cntx->show_attachment_icon = MMI_TRUE;

    return new_attach;
}

/* Attachment Related End */

/* Slide Related */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_convert_ascii_hex_to_dec
 * DESCRIPTION
 *  convert from ascii hex to dec
 * PARAMETERS
 *  character       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_mv_convert_ascii_hex_to_dec(const U8 *character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 value = 0;
    U8 c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip prefix "0x" or "0X" */
    if (character[0] == '0' && (character[1] == 'x' || character[1] == 'X'))
    {
        i = 2;
    }

    while ((c = character[i]) != 0)
    {
        value = value * 16;

        if (c > 47 && c < 58)   /* Digits 0..9 */
        {
            value += (c - 48);
        }
        else if (c > 64 && c < 71)  /* Characters A..F */
        {
            value += (c - 55);
        }
        else if (c > 96 && c < 103) /* Characters a..f */
        {
            value += (c - 87);
        }
        i++;
    }
    return value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_convert_mms_layout_type
 * DESCRIPTION
 *  convert mms layout from MMA to WGUI format
 * PARAMETERS
 *  layout_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wgui_mv_slide_layout_enum mmi_mv_convert_mms_layout_type(U8 layout_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (layout_type == MMA_LAYOUT_TEXT_ON_TOP)
    {
        return WGUI_MV_DRAWABLE_MEDIA_ON_BOTTOM;
    }

    return WGUI_MV_DRAWABLE_MEDIA_ON_TOP;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_end_slide
 * DESCRIPTION
 *  iterate to the last slide
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static wgui_mv_slide_struct *mmi_mv_get_end_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *slide = g_mv_cntx.msg_cntx->slide_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide == NULL)
    {
        return NULL;
    }

    while (slide->next != NULL)
    {
        slide = slide->next;
    }

    return slide;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_insert_slide
 * DESCRIPTION
 *  insert a new slide
 * PARAMETERS
 *  cur_slide       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wgui_mv_slide_struct *mmi_mv_insert_slide(wgui_mv_slide_struct *cur_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *new_slide;
    U32 slide_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide_size = sizeof(wgui_mv_slide_struct);
    new_slide = mmi_mv_allocate_mem(slide_size);
    if (!new_slide)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] mmi_mv_insert_slide: MMI_MV_OUT_OF_MEM *\n");
        g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
        return new_slide;
    }
    memset(new_slide, 0, slide_size);

    g_mv_cntx.msg_cntx->total_slide_num++;
    /* new_slide->duration = g_mv_cntx.msg_cntx->sliding_time; */

    /* ASSERT(g_mv_cntx.msg_cntx->total_slide_num <= MMA_MAX_SLIDE_NO); */

    /* First slide */
    if (cur_slide == NULL)
    {
        /* ASSERT( g_umms_p->msg.total_slide_num == 1 ); */
        new_slide->next = g_mv_cntx.msg_cntx->slide_head;
        new_slide->previous = NULL;

        if (g_mv_cntx.msg_cntx->slide_head)
        {
            g_mv_cntx.msg_cntx->slide_head->previous = new_slide;
        }

        g_mv_cntx.msg_cntx->slide_head = new_slide;

        new_slide->slide_num = 1;

        if (new_slide->next)
        {
            wgui_mv_slide_struct *update_slide = mmi_mv_get_end_slide();

            while (update_slide != new_slide)
            {
                update_slide->slide_num++;
                /* mmi_umms_update_text_object_path(update_slide); */
                update_slide = update_slide->previous;
            }
        }
    }
    else
    {
        new_slide->slide_num = cur_slide->slide_num + 1;

        new_slide->next = cur_slide->next;
        new_slide->previous = cur_slide;

        if (cur_slide->next)
        {
            wgui_mv_slide_struct *update_slide = mmi_mv_get_end_slide();

            cur_slide->next->previous = new_slide;

            while (update_slide != new_slide)
            {
                update_slide->slide_num++;
                /* mmi_umms_update_text_object_path(update_slide); */
                update_slide = update_slide->previous;
            }
        }
        cur_slide->next = new_slide;
    }

    return new_slide;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_insert_slide_by_number
 * DESCRIPTION
 *  insert a slide by number
 * PARAMETERS
 *  slide_number        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static wgui_mv_slide_struct *mmi_mv_insert_slide_by_number(U16 slide_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *cur_slide = g_mv_cntx.msg_cntx->slide_head;
    wgui_mv_slide_struct *pre_slide = cur_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide_number == 1)
    {
        return mmi_mv_insert_slide(NULL);
    }
    else
    {
        while (cur_slide && (cur_slide->slide_num < slide_number))
        {
            pre_slide = cur_slide;
            cur_slide = cur_slide->next;
        }

        return mmi_mv_insert_slide(pre_slide);
    }
}

/* Slide Related End */

/* Object Related */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_insert_object_to_list_tail
 * DESCRIPTION
 *  insert slide to list tail
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_mv_object_struct *mmi_mv_insert_object_to_list_tail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *new_object;
    U32 object_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mmi_mv_object_struct);
    new_object = mmi_mv_allocate_mem(object_size);
    if (!new_object)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] mmi_mv_insert_object_to_list_tail: MMI_MV_OUT_OF_MEM *\n");
        g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
        return new_object;
    }

    memset(new_object, 0, object_size);
    g_mv_cntx.total_object_num++;
    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_insert_object_to_slide
 * DESCRIPTION
 *  insert object to slide
 * PARAMETERS
 *  object          [IN]        
 *  slide           [IN]        
 *  object_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_insert_object_to_slide(
                mmi_mv_object_struct *object,
                wgui_mv_slide_struct *slide,
                mmi_mv_object_type_enum object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type)
    {
        case MMI_MV_OBJECT_TYPE_IMAGE:
            object->reference_count++;
            break;
        case MMI_MV_OBJECT_TYPE_AUDIO:
            object->reference_count++;
            break;
        case MMI_MV_OBJECT_TYPE_VIDEO:
            object->reference_count++;
            break;
        case MMI_MV_OBJECT_TYPE_TEXT:
            object->reference_count++;
            break;
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_match_object_id
 * DESCRIPTION
 *  match objects with slide object ids
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mv_match_object_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_mv_slide_struct *cur_slide = g_mv_cntx.msg_cntx->slide_head;
    U32 slide_num = 0;
    mmi_mv_object_struct *cur_object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; cur_slide != NULL; cur_slide = cur_slide->next, slide_num++)
    {
        if (cur_slide->text.id)
        {
            cur_object = mmi_mv_object[cur_slide->text.id];
            ASSERT(cur_object);
            /* if size is too large don't insert */
            if (cur_object->size > MMI_MV_MAX_UTF8_TXT_SLIDE_LEN)
            {
                PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] MMI_MV_MAX_UTF8_TXT_SLIDE_LEN *\n");
                cur_slide->text.str_id = STR_ID_MMS_VIEWER_TEXT_STRIPPED;
                /* Text To Large To Display: To Use First Save From 'Save Object' */
            }

                mmi_mv_insert_object_to_slide(cur_object, cur_slide, MMI_MV_OBJECT_TYPE_TEXT);

            cur_object->type = MMI_MV_OBJECT_TYPE_TEXT;
        }

        if (cur_slide->image.id)
        {
            cur_object = mmi_mv_object[cur_slide->image.id];
            ASSERT(cur_object);
            cur_object->type = MMI_MV_OBJECT_TYPE_IMAGE;
            mmi_mv_insert_object_to_slide(cur_object, cur_slide, MMI_MV_OBJECT_TYPE_IMAGE);
        }

        if (cur_slide->audio.id)
        {
            cur_object = mmi_mv_object[cur_slide->audio.id];
            ASSERT(cur_object);
            cur_object->type = MMI_MV_OBJECT_TYPE_AUDIO;
            mmi_mv_insert_object_to_slide(cur_object, cur_slide, MMI_MV_OBJECT_TYPE_AUDIO);
        }

        if (cur_slide->video.id)
        {
            cur_object = mmi_mv_object[cur_slide->video.id];
            ASSERT(cur_object);
            cur_object->type = MMI_MV_OBJECT_TYPE_VIDEO;
            mmi_mv_insert_object_to_slide(cur_object, cur_slide, MMI_MV_OBJECT_TYPE_AUDIO);
        }
    }

    ASSERT(slide_num == g_mv_cntx.msg_cntx->total_slide_num);
    return MMI_TRUE;
}

/* Object Related End */

/* XML Parser */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_xml_start_element_hdlr
 * DESCRIPTION
 *  start handler for xml parser
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  attr        [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_xml_start_element_hdlr(void *data, const char *el, const char **attr, int error)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != 0)
    {
        return;
    }

    /* Above this line header related tags are handled */

    if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_IGNORE_SLIDES)
    {
        return;
    }

    /* Below this line body related tags are handled */

    if (!strcmp(MMI_UMMS_XML_ELEMENT_BODY, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_BGCOLOR, attr[i]))
            {
                g_mv_cntx.msg_cntx->background_color = mmi_mv_convert_ascii_hex_to_dec((U8*) attr[i + 1]) << 8;
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_FGCOLOR, attr[i]))
            {
                g_mv_cntx.msg_cntx->foreground_color = mmi_mv_convert_ascii_hex_to_dec((U8*) attr[i + 1]) << 8;
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_SLIDE_NUM, attr[i]))
            {
                /* updated in mmi_umms_insert_slide_by_number */
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_OBJ_NUM, attr[i]))
            {
                /* updated in mmi_umms_insert_object_to_list_tail() */
                U32 array_size;
                
                g_mv_cntx.reported_object_num = atoi((S8*) attr[i + 1]);
                array_size = (1+g_mv_cntx.reported_object_num)*sizeof(p_mv_object);
                mmi_mv_object = mmi_mv_allocate_mem(array_size);

                if (!mmi_mv_object)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_start_element_hdlr: MMI_MV_OUT_OF_MEM *\n");
                    g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
                    xml_stop_parse(g_mv_parser_cntx.xml_parser);
                    return;
                }

                memset(mmi_mv_object, 0, array_size);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_LAYOUT, attr[i]))
            {
                g_mv_cntx.msg_cntx->layout = mmi_mv_convert_mms_layout_type((U8) atoi((S8*) attr[i + 1]));
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_SLIDE, el))
    {
        U16 slide_number = 0;
        U16 duration = 0;

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_INDEX, attr[i]))
            {
                slide_number = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_DURATION, attr[i]))
            {
                duration = atoi((S8*) attr[i + 1]);
            }
        }

        if (slide_number)
        {
            g_mv_parser_cntx.slide = mmi_mv_insert_slide_by_number(slide_number);

            if (g_mv_parser_cntx.slide)
            {
                ASSERT(g_mv_parser_cntx.slide->slide_num == slide_number);
                if (duration)
                {
                    g_mv_parser_cntx.slide->duration = duration;
                }
            }
            else
            {
                xml_stop_parse(g_mv_parser_cntx.xml_parser);
                return;
            }
        }
        else
        {
            ASSERT(0);
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_TEXT, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID, attr[i]))
            {
                g_mv_parser_cntx.slide->text.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN, attr[i]))
            {
                g_mv_parser_cntx.slide->text.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END, attr[i]))
            {
                g_mv_parser_cntx.slide->text.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BGCOLOR, attr[i]))
            {
                g_mv_parser_cntx.slide->text.background_color = mmi_mv_convert_ascii_hex_to_dec((U8*) attr[i + 1]) << 8;
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_FGCOLOR, attr[i]))
            {
                g_mv_parser_cntx.slide->text.foreground_color = mmi_mv_convert_ascii_hex_to_dec((U8*) attr[i + 1]) << 8;
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_TEXT_SIZE, attr[i]))
            {
                g_mv_parser_cntx.slide->text.txtSize = atoi((S8*) attr[i + 1]) - 1;
                                                                                  /*-1 to convert from mma_text_size_enum to WGUI_FONT_SIZE */
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_TEXT_STYLE, attr[i]))
            {
                g_mv_parser_cntx.slide->text.txtStyle = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_mv_parser_cntx.slide->text.alt_str = mmi_mv_allocate_mem(MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);

                if (!g_mv_parser_cntx.slide->text.alt_str)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_start_element_hdlr: MMI_MV_OUT_OF_MEM *\n");
                    g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
                    xml_stop_parse(g_mv_parser_cntx.xml_parser);
                    return;
                }

                memset(g_mv_parser_cntx.slide->text.alt_str, 0, MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_mv_parser_cntx.slide->text.alt_str,
                    MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }

        }

        /* Best Fit */
        if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_DO_BEST_FIT)
        {
            if (g_mv_parser_cntx.slide->text.begin > g_mv_parser_cntx.slide->text.end)
            {
                g_mv_parser_cntx.slide->text.begin = 0;
                g_mv_parser_cntx.slide->text.end = g_mv_parser_cntx.slide->duration;
                MMI_TRACE(TRACE_INFO, MMI_MV_FUNC_XML_START_HDLR_TEXT);
            }
            else if (g_mv_parser_cntx.slide->text.end == 0)
            {
                g_mv_parser_cntx.slide->text.end = g_mv_parser_cntx.slide->duration;
            }
            else if (g_mv_parser_cntx.slide->text.end > g_mv_parser_cntx.slide->duration)
            {
                g_mv_parser_cntx.slide->duration = g_mv_parser_cntx.slide->text.end;
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_IMAGE, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID, attr[i]))
            {
                g_mv_parser_cntx.slide->image.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN, attr[i]))
            {
                g_mv_parser_cntx.slide->image.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END, attr[i]))
            {
                g_mv_parser_cntx.slide->image.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_mv_parser_cntx.slide->image.alt_str = mmi_mv_allocate_mem(MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                if (!g_mv_parser_cntx.slide->image.alt_str)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_start_element_hdlr: MMI_MV_OUT_OF_MEM *\n");
                    g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
                    xml_stop_parse(g_mv_parser_cntx.xml_parser);
                    return;
                }
                memset(g_mv_parser_cntx.slide->image.alt_str, 0, MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_mv_parser_cntx.slide->image.alt_str,
                    MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }
        }

        /* Best Fit */
        if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_DO_BEST_FIT)
        {
            if (g_mv_parser_cntx.slide->image.begin > g_mv_parser_cntx.slide->image.end)
            {
                g_mv_parser_cntx.slide->image.begin = 0;
                g_mv_parser_cntx.slide->image.end = g_mv_parser_cntx.slide->duration;
                MMI_TRACE(TRACE_INFO, MMI_MV_FUNC_XML_START_HDLR_AUDIO);
            }
            else if (g_mv_parser_cntx.slide->image.end == 0)
            {
                g_mv_parser_cntx.slide->image.end = g_mv_parser_cntx.slide->duration;
            }
            else if (g_mv_parser_cntx.slide->image.end > g_mv_parser_cntx.slide->duration)
            {
                g_mv_parser_cntx.slide->duration = g_mv_parser_cntx.slide->image.end;
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_AUDIO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID, attr[i]))
            {
                g_mv_parser_cntx.slide->audio.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN, attr[i]))
            {
                g_mv_parser_cntx.slide->audio.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END, attr[i]))
            {
                g_mv_parser_cntx.slide->audio.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_mv_parser_cntx.slide->audio.alt_str = mmi_mv_allocate_mem(MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                if (!g_mv_parser_cntx.slide->audio.alt_str)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_start_element_hdlr: MMI_MV_OUT_OF_MEM *\n");
                    g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
                    xml_stop_parse(g_mv_parser_cntx.xml_parser);
                    return;
                }
                memset(g_mv_parser_cntx.slide->audio.alt_str, 0, MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_mv_parser_cntx.slide->audio.alt_str,
                    MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }
        }

        /* Best Fit */
        if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_DO_BEST_FIT)
        {
            if (g_mv_parser_cntx.slide->audio.begin > g_mv_parser_cntx.slide->audio.end)
            {
                g_mv_parser_cntx.slide->audio.begin = 0;
                g_mv_parser_cntx.slide->audio.end = g_mv_parser_cntx.slide->duration;
                MMI_TRACE(TRACE_INFO, MMI_MV_FUNC_XML_START_HDLR_AUDIO);
            }
            else if (g_mv_parser_cntx.slide->audio.end == 0)
            {
                g_mv_parser_cntx.slide->audio.end = g_mv_parser_cntx.slide->duration;
            }
            else if (g_mv_parser_cntx.slide->audio.end > g_mv_parser_cntx.slide->duration)
            {
                g_mv_parser_cntx.slide->duration = g_mv_parser_cntx.slide->audio.end;
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_VIDEO, el))
    {
        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID, attr[i]))
            {
                g_mv_parser_cntx.slide->video.id = (atoi((S8*) attr[i + 1]));
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_BEGIN, attr[i]))
            {
                g_mv_parser_cntx.slide->video.begin = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_END, attr[i]))
            {
                g_mv_parser_cntx.slide->video.end = atoi((S8*) attr[i + 1]);
            }
            else if (!strcmp(MMI_UMMS_XML_ATRR_ALT_STR, attr[i]))
            {
                g_mv_parser_cntx.slide->video.alt_str = mmi_mv_allocate_mem(MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                if (!g_mv_parser_cntx.slide->video.alt_str)
                {
                    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_start_element_hdlr: MMI_MV_OUT_OF_MEM *\n");
                    g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
                    xml_stop_parse(g_mv_parser_cntx.xml_parser);
                    return;
                }

                memset(g_mv_parser_cntx.slide->video.alt_str, 0, MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string(
                    (kal_uint8*) g_mv_parser_cntx.slide->video.alt_str,
                    MMI_MV_MAX_ALT_STR_LEN * ENCODING_LENGTH,
                    (kal_uint8*) attr[i + 1]);
            }
        }

        /* Best Fit */
        if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_DO_BEST_FIT)
        {
            if (g_mv_parser_cntx.slide->video.begin > g_mv_parser_cntx.slide->video.end)
            {
                g_mv_parser_cntx.slide->video.begin = 0;
                g_mv_parser_cntx.slide->video.end = g_mv_parser_cntx.slide->duration;
                MMI_TRACE(TRACE_INFO, MMI_MV_FUNC_XML_START_HDLR_AUDIO);
            }
            else if (g_mv_parser_cntx.slide->video.end == 0)
            {
                g_mv_parser_cntx.slide->video.end = g_mv_parser_cntx.slide->duration;
            }
            else if (g_mv_parser_cntx.slide->video.end > g_mv_parser_cntx.slide->duration)
            {
                g_mv_parser_cntx.slide->duration = g_mv_parser_cntx.slide->video.end;
            }
        }
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_OBJECT, el))
    {
        MMI_ASSERT(g_mv_cntx.total_object_num < g_mv_cntx.reported_object_num)

        g_mv_parser_cntx.object = mmi_mv_insert_object_to_list_tail();

        if (!g_mv_parser_cntx.object)
        {
            xml_stop_parse(g_mv_parser_cntx.xml_parser);
            return;
        }

        for (i = 0; attr[i]; i = i + 2)
        {
            if (!strcmp(MMI_UMMS_XML_ATTR_ID, attr[i]))
            {
                U16 id;

                /* id is one based while array is zero based so we have take array + 1 for NULL */
                id = (atoi((S8*) attr[i + 1]));
                mmi_mv_object[id] = g_mv_parser_cntx.object;
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_ATTACH, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_mv_parser_cntx.object->type = MMI_MV_OBJECT_TYPE_ATTACHMENT;
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_VIRTUAL_FILE, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_mv_parser_cntx.object->is_virtual_file = MMI_TRUE;
                }
                else
                {
                    g_mv_parser_cntx.object->is_virtual_file = MMI_FALSE;
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_DRM, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_mv_parser_cntx.object->drm_type = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_SIZE, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_mv_parser_cntx.object->size = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_OFFSET, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    g_mv_parser_cntx.object->offset = (atoi((S8*) attr[i + 1]));
                }
            }
            else if (!strcmp(MMI_UMMS_XML_ATTR_ENCODING_SCHEME, attr[i]))
            {
                if (atoi((S8*) attr[i + 1]))
                {
                    U16 mma_encoding_type;

                    mma_encoding_type = (atoi((S8*) attr[i + 1]));
                    switch (mma_encoding_type)
                    {
                        case MMA_CHARSET_UNKNOWN:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_UNKNOWN;
                            break;
                        case MMA_CHARSET_ASCII:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_ASCII;
                            break;
                        case MMA_CHARSET_ISO_8859_1:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_ISO_8859_1;
                            break;
                        case MMA_CHARSET_UTF8:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_UTF8;
                            break;
                        case MMA_CHARSET_UCS2:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_UCS2;
                            break;
                        case MMA_CHARSET_UTF16BE:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_UTF16BE;
                            break;
                        case MMA_CHARSET_UTF16LE:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_UTF16LE;
                            break;
                        case MMA_CHARSET_UTF16:
                            g_mv_parser_cntx.object->encoding_scheme = MMI_MV_CHARSET_UTF16;
                            break;
                    }
                }
            }

        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_xml_end_element_hdlr
 * DESCRIPTION
 *  end handler for xml parser
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_xml_end_element_hdlr(void *data, const char *el, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != 0)
    {
        return;
    }

    /* Above this line header related tags are handled */

    if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_IGNORE_SLIDES)
    {
        return;
    }

    /* Below this line body related tags are handled */

    if (!strcmp(MMI_UMMS_XML_ELEMENT_OBJECT, el))
    {
        if (g_mv_parser_cntx.object->type == MMI_MV_OBJECT_TYPE_ATTACHMENT)
        {
            mmi_mv_attachment_info_struct *att;

            att = mmi_mv_insert_attachment();
            if (att == NULL)
            {
                xml_stop_parse(g_mv_parser_cntx.xml_parser);
                return;
            }
            mmi_mv_insert_object_to_attachment(g_mv_parser_cntx.object, att);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_xml_data_hdlr
 * DESCRIPTION
 *  data handler for xml parser
 * PARAMETERS
 *  data        [IN]        
 *  el          [IN]        
 *  value       [IN]        
 *  len         [IN]        
 *  error       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error != 0)
    {
        return;
    }

    /* Above this line header related tags are handled */

    if (g_mv_parser_cntx.flags & MMI_MV_MSG_PARSER_IGNORE_SLIDES)
    {
        return;
    }

    /* Below this line body related tags are handled */

    if (!strcmp(MMI_UMMS_XML_ELEMENT_NAME, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        ASSERT(len);
        ASSERT(g_mv_parser_cntx.object);
        ASSERT(g_mv_parser_cntx.object->file_name == NULL);

        g_mv_parser_cntx.object->file_name = mmi_mv_allocate_mem(ucs2_len);
        if (!g_mv_parser_cntx.object->file_name)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_data_hdlr: MMI_MV_OUT_OF_MEM *\n");
            g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
            xml_stop_parse(g_mv_parser_cntx.xml_parser);
            return;
        }
        
        memset(g_mv_parser_cntx.object->file_name, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string((kal_uint8*) g_mv_parser_cntx.object->file_name, ucs2_len, (kal_uint8*) value);
    }
    else if (!strcmp(MMI_UMMS_XML_ELEMENT_FILE_PATH, el))
    {
        U32 ucs2_len = (len + 1) * ENCODING_LENGTH;

        ASSERT(len);
        ASSERT(g_mv_parser_cntx.object);
        ASSERT(g_mv_parser_cntx.object->file_path == NULL);

        g_mv_parser_cntx.object->file_path = mmi_mv_allocate_mem(ucs2_len);
        if (!g_mv_parser_cntx.object->file_path)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_xml_data_hdlr: MMI_MV_OUT_OF_MEM *\n");
            g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
            xml_stop_parse(g_mv_parser_cntx.xml_parser);
            return;
        }
        
        memset(g_mv_parser_cntx.object->file_path, 0, ucs2_len);
        mmi_chset_utf8_to_ucs2_string((kal_uint8*) g_mv_parser_cntx.object->file_path, ucs2_len, (kal_uint8*) value);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_parse_mms_xml_description_file
 * DESCRIPTION
 *  xml parser
 * PARAMETERS
 *  file_path       [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static XML_RESULT_ENUM mmi_mv_parse_mms_xml_description_file(const PU16 file_path, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mv_parser_cntx, 0, sizeof(mmi_mv_msg_parser_cntx_struct));

    g_mv_parser_cntx.xml_parser = mmi_mv_allocate_mem(sizeof(XML_PARSER_STRUCT));

    if (!g_mv_parser_cntx.xml_parser)
    {
        g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
        return XML_RESULT_FAIL;
    }

    memset(g_mv_parser_cntx.xml_parser, 0, sizeof(XML_PARSER_STRUCT));

    result = xml_new_parser(g_mv_parser_cntx.xml_parser);

    if (result)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] Can Not Create Parser! *\n");
        xml_close_parser(g_mv_parser_cntx.xml_parser);
        mmi_mv_free_mem(g_mv_parser_cntx.xml_parser);
        g_mv_parser_cntx.xml_parser = NULL;
        return XML_RESULT_FAIL;
    }

    g_mv_parser_cntx.flags = flags;

    xml_register_element_handler(
        g_mv_parser_cntx.xml_parser,
        mmi_mv_xml_start_element_hdlr,
        mmi_mv_xml_end_element_hdlr);

    xml_register_data_handler(g_mv_parser_cntx.xml_parser, mmi_mv_xml_data_hdlr);

    result = xml_parse(g_mv_parser_cntx.xml_parser, file_path);

    xml_close_parser(g_mv_parser_cntx.xml_parser);

    mmi_mv_free_mem(g_mv_parser_cntx.xml_parser);
    g_mv_parser_cntx.xml_parser = NULL;

    if (result)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] Parsing Failed! *\n");
        return XML_RESULT_FAIL;
    }
    else
    {
        if (mmi_mv_match_object_id())
        {
            return XML_RESULT_OK;
        }
        else
        {
            return XML_RESULT_FAIL;
        }
    }
}

/* XML Parser End */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_app_exit_fn
 * DESCRIPTION
 *  application exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_app_exit_fn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_app_exit_fn *\n");
    /* Send Read Report */
    if (g_mv_cntx.send_read_report == MMI_TRUE)
    {
        mmi_mv_send_read_report_req();
        g_mv_cntx.send_read_report = MMI_FALSE; /* Don't care whether read report succeeds or not */
    }

    /* MAUI_00539316 */
    if (g_mv_cntx.deinit_on_exit == MMI_TRUE)
    {
        mmi_umms_reset_global();
        mmi_mv_deinit_viewer();
    }
    /* MAUI_00539316 */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_view_msg_no_rr
 * DESCRIPTION
 *  Confirmation Screen Right Softkey Handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_view_msg_no_rr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_msg_no_rr *\n");
    g_mv_cntx.send_read_report = MMI_FALSE;
    mmi_mv_view_msg();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_send_rr_confirm_or_replace
 * DESCRIPTION
 *  Entry Send RR Confirmation or replace history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_send_rr_confirm_or_replace(void)
{
    if (GetActiveScreenId() == g_mv_cntx.progress_scr_id)
    {
        mmi_mv_entry_send_rr_confirmation();
    }
    else
    {
        if (MMI_TRUE == IsScreenPresent(g_mv_cntx.progress_scr_id))
        {
            MMI_BOOL result;

            result = HistoryReplace(g_mv_cntx.progress_scr_id, SCR_ID_UMMS_RR_CONFIRM_SCREEN, mmi_mv_entry_send_rr_confirmation);
            MMI_ASSERT(result);

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_or_replace:: Success *\n");
        }
        else
        {
            mmi_mv_deinit_viewer();
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_send_rr_confirm_or_replace:: Failed *\n");            
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_entry_send_rr_confirmation
 * DESCRIPTION
 *  Entry Send RR Confirmation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_entry_send_rr_confirmation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_entry_send_rr_confirmation *\n");

    EntryNewScreen(SCR_ID_UMMS_RR_CONFIRM_SCREEN, NULL, mmi_mv_entry_send_rr_confirmation, NULL);
    DeleteScreenIfPresent(g_mv_cntx.progress_scr_id);
    SetDelScrnIDCallbackHandler(SCR_ID_UMMS_RR_CONFIRM_SCREEN, mmi_mv_delete_screen_cb);

    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU16) GetString(STR_ID_MMS_VIEWER_SEND_RR_CONFIRM),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_mv_view_msg, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_mv_view_msg_no_rr, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_view_or_replace
 * DESCRIPTION
 *  View message or replace history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_view_or_replace(void)
{
    if (GetActiveScreenId() == g_mv_cntx.progress_scr_id)
    {
        mmi_mv_view_msg();
    }
    else
    {
        if (MMI_TRUE == IsScreenPresent(g_mv_cntx.progress_scr_id))
        {
            MMI_BOOL result;

            result = HistoryReplace(g_mv_cntx.progress_scr_id, SCR_ID_UMMS_MMS_VIEWER, mmi_mv_view_msg);
            MMI_ASSERT(result);

            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_or_replace:: Success *\n");
        }
        else
        {
            mmi_mv_deinit_viewer();
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_or_replace:: Failed *\n");
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_view_msg
 * DESCRIPTION
 *  view message called from either preview, new msg view or history.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_view_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_MV_UNIT_TEST
    U32 total_memsize = MMI_MV_ASM_MEM_POOL_SIZE;
    U32 usedetail_memsize = MMI_MV_USE_DETAIL_MEM_SIZE;
    U32 address_list_memsize = MMI_MV_ADDRESSES_MEM_SIZE;
    U32 total_object_memsize = MMI_MV_OBJECT_MEM_SIZE;
    U32 single_object_memsize = MMI_MV_MMS_OBJECT_STRUCT_SIZE;
    U32 text_memsize = MMI_MV_TEXT_MEM_SIZE;
    U32 size = sizeof(mmi_mv_attachment_info_struct) + sizeof(mmi_mv_object_struct) + sizeof(wgui_mv_slide_struct);
U32 ZI_DATA = sizeof(mmi_mv_msg_parser_cntx_struct)
              + sizeof (mmi_mv_context_struct)
              + sizeof (mmi_mv_use_details_cntx_struct)
              + sizeof (mmi_mv_drm_process_cntx_struct)
              + (61*(sizeof (p_mv_object)));
#endif /* MMI_MV_UNIT_TEST */ 

    PU8 guibuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearAllKeyHandler();


    ClearDelScrnIDCallbackHandler(SCR_ID_UMMS_RR_CONFIRM_SCREEN, mmi_mv_delete_screen_cb);
    EntryNewScreen(SCR_ID_UMMS_MMS_VIEWER, mmi_mv_app_exit_fn, mmi_mv_view_msg, NULL);

    guibuffer =  GetCurrGuiBuffer(SCR_ID_UMMS_MMS_VIEWER);
    DeleteScreenIfPresent(SCR_ID_UMMS_RR_CONFIRM_SCREEN);
    DeleteScreenIfPresent(g_mv_cntx.progress_scr_id);
    SetDelScrnIDCallbackHandler(SCR_ID_UMMS_MMS_VIEWER, mmi_mv_delete_screen_cb);

    if (NULL == guibuffer)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_msg: First Time *\n");
        ShowCategory630Screen(MMI_FALSE, g_mv_cntx.lsk_fn, g_mv_cntx.lsk_str_id, g_mv_cntx.rsk_fn, guibuffer);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_msg: From History *\n");
        ShowCategory630Screen(MMI_TRUE, g_mv_cntx.lsk_fn, g_mv_cntx.lsk_str_id, g_mv_cntx.rsk_fn, guibuffer);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_use_details_check_stop_cb
 * DESCRIPTION
 *  Use Detail check stop callback
 * PARAMETERS
 *  type        [IN]        
 *  node        [IN]        
 *  num         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_mv_use_details_check_stop_cb(applib_addr_type_enum type, applib_address_node_struct *node, kal_uint32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_use_details_cntx.count += 1;
    g_use_details_cntx.total_count += 1;

    if (g_use_details_cntx.total_count >= MMI_MV_MAX_USE_DETAILS
        || g_use_details_cntx.count >= MMI_MV_MAX_USE_DETAILS_PER_SLIDE)
    {
        return KAL_TRUE;
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_end_compute_use_details
 * DESCRIPTION
 *  End handler for use details flow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_end_compute_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (g_use_details_cntx.state == MMI_MV_GET_USE_DETAILS_SLIDE_ALL)
    {
        if (g_use_details_cntx.current_slide->next && g_use_details_cntx.total_count < MMI_MV_MAX_USE_DETAILS)
        {
            g_use_details_cntx.current_slide = g_use_details_cntx.current_slide->next;
            mmi_mv_start_compute_use_details();
        }
        else
        {
            g_use_details_cntx.use_detail_rsp.result = MMI_MV_GET_USE_DETAILS_RESULT_SUCCESS;
            mmi_mv_send_get_use_details_rsp();
        }
    }
    else if (g_use_details_cntx.state == MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT)
    {
        g_use_details_cntx.use_detail_rsp.result = MMI_MV_GET_USE_DETAILS_RESULT_SUCCESS;
        mmi_mv_send_get_use_details_rsp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_urls_on_slide
 * DESCRIPTION
 *  gets urls on slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_get_urls_on_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (MMI_MV_MAX_USE_DETAILS > g_use_details_cntx.total_count)
    {
        temp = applib_get_address_list_from_text_ext(
                APPLIB_ADDR_TYPE_URL,
                mmi_mv_alloc_mem_for_use_details,
                mmi_mv_free_use_detail_mem,
                mmi_mv_use_details_check_stop_cb,
                APPLIB_INPUT_DATA_TYPE_UNICODE,
                (PS8) g_use_details_cntx.p_ucs2_buffer,
                g_use_details_cntx.ucs2_buffer_len,
                &is_stopped);

        g_use_details_cntx.use_detail_rsp.url_list = applib_concatenate_address_list(g_use_details_cntx.use_detail_rsp.url_list, temp);
    }

    StartTimer(MMS_VIEWER_TIMER, MMI_MV_UNBLOCK_TIME, mmi_mv_end_compute_use_details);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_emails_on_slide
 * DESCRIPTION
 *  get emails on slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_get_emails_on_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (MMI_MV_MAX_USE_DETAILS > g_use_details_cntx.total_count)
    {
        temp = applib_get_address_list_from_text_ext(
                APPLIB_ADDR_TYPE_EMAIL,
                mmi_mv_alloc_mem_for_use_details,
                mmi_mv_free_use_detail_mem,
                mmi_mv_use_details_check_stop_cb,
                APPLIB_INPUT_DATA_TYPE_UNICODE,
                (PS8) g_use_details_cntx.p_ucs2_buffer,
                g_use_details_cntx.ucs2_buffer_len,
                &is_stopped);
        g_use_details_cntx.use_detail_rsp.email_list = applib_concatenate_address_list(g_use_details_cntx.use_detail_rsp.email_list, temp);
    }
    else
    {
        is_stopped = TRUE;
    }

    if (is_stopped == TRUE)
    {
        StartTimer(MMS_VIEWER_TIMER, MMI_MV_UNBLOCK_TIME, mmi_mv_end_compute_use_details);
    }
    else
    {
        StartTimer(MMS_VIEWER_TIMER, MMI_MV_UNBLOCK_TIME, mmi_mv_get_urls_on_slide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_numbers_on_slide
 * DESCRIPTION
 *  get numbers on slide
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_get_numbers_on_slide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *temp;
    kal_bool is_stopped = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);

    if (MMI_MV_MAX_USE_DETAILS > g_use_details_cntx.total_count)
    {
        temp = applib_get_address_list_from_text_ext(
                APPLIB_ADDR_TYPE_PHONENUMBER,
                mmi_mv_alloc_mem_for_use_details,
                mmi_mv_free_use_detail_mem,
                mmi_mv_use_details_check_stop_cb,
                APPLIB_INPUT_DATA_TYPE_UNICODE,
                (PS8) g_use_details_cntx.p_ucs2_buffer,
                g_use_details_cntx.ucs2_buffer_len,
                &is_stopped);

        g_use_details_cntx.use_detail_rsp.num_list = applib_concatenate_address_list(g_use_details_cntx.use_detail_rsp.num_list, temp);
    }
    else
    {
        is_stopped = TRUE;
    }

    if (is_stopped == TRUE)
    {
        StartTimer(MMS_VIEWER_TIMER, MMI_MV_UNBLOCK_TIME, mmi_mv_end_compute_use_details);
    }
    else
    {
        StartTimer(MMS_VIEWER_TIMER, MMI_MV_UNBLOCK_TIME, mmi_mv_get_emails_on_slide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_load_ucs2_txt_to_buffer
 * DESCRIPTION
 *  load ucs2 txt to buffer
 * PARAMETERS
 *  dest_buffer             [IN]        
 *  dest_buffer_size        [IN]        
 *  object_id               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mv_load_ucs2_txt_to_buffer(PU8 dest_buffer, U32 dest_buffer_size, U32 object_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_handle = 0;
    S32 parent_file_handle = 0;
    PU16 file_path;
    S32 result;
    U8 encoding_type;
    mmi_mv_object_struct *temp = mmi_mv_object[object_id];
    U16 txt_vf[FS_GenVFN_SIZE];
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c] No such object! *\n");
        return MMI_FALSE;
    }

    if (temp->is_virtual_file == MMI_TRUE)
    {
        /* Open Parent File Handle */
        parent_file_handle = FS_Open(temp->file_path, FS_READ_ONLY | FS_OPEN_SHARED);

        if (parent_file_handle <= 0)
        {
            /* Return because can't get parent file handle */
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_load_ucs2_txt_to_buffer: Can't get parent file handle *\n");
            return MMI_FALSE;
        }

        result = FS_GenVirtualFileName(
                    parent_file_handle,
                    (U16*) txt_vf,
                    (unsigned int)FS_GenVFN_SIZE,
                    temp->offset,
                    temp->size);

        if (result < 0)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_load_ucs2_txt_to_buffer: Can't create VF *\n");
            /* Can't create VF, close parent file handle */
            FS_Close(parent_file_handle);
            return MMI_FALSE;
        }

        file_path = txt_vf;
    }
    else
    {
        file_path = temp->file_path;
    }

    memset(dest_buffer, 0, dest_buffer_size);
    memset(g_mv_cntx.src_buffer, 0, MMI_MV_MAX_UTF8_TXT_SLIDE_LEN);

    /* Read Src Txt into src buffer */
    file_handle = FS_Open(file_path, FS_READ_ONLY | FS_OPEN_SHARED);
    if (file_handle <= 0)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_load_ucs2_txt_to_buffer: Can't open txt file *\n");
        FS_Close(parent_file_handle);
        return MMI_FALSE;
    }

    result = FS_Read(file_handle, g_mv_cntx.src_buffer, MMI_MV_MAX_UTF8_TXT_SLIDE_LEN, &len);
    MMI_TRACE(TRACE_INFO, MMI_MV_READ_FILE, len);

    FS_Close(file_handle);

    if (result == FS_NO_ERROR)
    {
        switch (temp->encoding_scheme)
        {
            default:
                mmi_chset_utf8_to_ucs2_string(dest_buffer, MMI_MV_TXT_BUF_UCS2_SIZE, g_mv_cntx.src_buffer);
                break;
            case MMI_MV_CHARSET_UTF16:
                encoding_type = mmi_chset_get_utf_byte_order((kal_int8*) g_mv_cntx.src_buffer);
                mmi_chset_convert(
                    encoding_type,
                    CHSET_UCS2,
                    (PS8) g_mv_cntx.src_buffer,
                    (PS8) dest_buffer,
                    dest_buffer_size);
                break;
            case MMI_MV_CHARSET_UTF16BE:
                mmi_chset_convert(
                    MMI_CHSET_UTF16BE,
                    CHSET_UCS2,
                    (PS8) g_mv_cntx.src_buffer,
                    (PS8) dest_buffer,
                    dest_buffer_size);
                break;
            case MMI_MV_CHARSET_UTF16LE:
                mmi_chset_convert(
                    MMI_CHSET_UTF16LE,
                    CHSET_UCS2,
                    (PS8) g_mv_cntx.src_buffer,
                    (PS8) dest_buffer,
                    dest_buffer_size);
                break;
            case MMI_MV_CHARSET_UCS2:
                mmi_ucs2ncpy((PS8) dest_buffer, (PS8) g_mv_cntx.src_buffer, dest_buffer_size);
                break;
        }

        MMI_TRACE(TRACE_INFO, MMI_MV_CONVERTED_TO_UCS2_LEN, mmi_ucs2strlen((PS8) g_mv_cntx.slide_txt_buffer));
    }

    if (parent_file_handle != 0)
    {
        FS_Close(parent_file_handle);
    }

    if (result >= 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_start_compute_use_details
 * DESCRIPTION
 *  start use detail parsing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_start_compute_use_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_use_details_cntx.count = 0;

    /* There is no text object available for this slide. */
    if (g_use_details_cntx.current_slide->text.id == 0)
    {
        mmi_mv_end_compute_use_details();
        return;
    }

    /* We can't assume that the current slide text is in buffer already */
    g_use_details_cntx.p_ucs2_buffer = g_mv_cntx.slide_txt_buffer;

    if (g_use_details_cntx.current_slide->text.id)
    {
        MMI_BOOL result;

        /* Following API opens/closes file Handle(s) */
        result = mmi_mv_load_ucs2_txt_to_buffer(
                    g_use_details_cntx.p_ucs2_buffer,
                    MMI_MV_TXT_BUF_UCS2_SIZE,
                    g_use_details_cntx.current_slide->text.id);
        if (result == MMI_FALSE)
        {
            mmi_mv_end_compute_use_details();
            return;
        }
    }

    g_use_details_cntx.ucs2_buffer_len = ENCODING_LENGTH * mmi_ucs2strlen((PS8) g_use_details_cntx.p_ucs2_buffer);
    StartTimer(MMS_VIEWER_TIMER, MMI_MV_UNBLOCK_TIME, mmi_mv_get_numbers_on_slide);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_send_get_use_details_rsp
 * DESCRIPTION
 *  send use detail rsp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_send_get_use_details_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_mv_get_use_details_rsp_struct *use_detail_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_detail_rsp =
        (mmi_mv_get_use_details_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mv_get_use_details_rsp_struct));
    g_use_details_cntx.use_detail_rsp.returned_type = g_use_details_cntx.state;
    g_use_details_cntx.use_detail_rsp.ref_count = use_detail_rsp->ref_count;
    g_use_details_cntx.use_detail_rsp.msg_len = use_detail_rsp->msg_len;

    memcpy(use_detail_rsp, &g_use_details_cntx.use_detail_rsp, sizeof(mmi_mv_get_use_details_rsp_struct));

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    Message.oslMsgId = MSG_ID_MMI_MV_GET_USE_DETAILS_RSP;
    Message.oslDataPtr = (oslParaType*) use_detail_rsp;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_use_details_deinit
 * DESCRIPTION
 *  get use details functionality deinit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_get_use_details_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL free_mem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_use_details_cntx.use_detail_rsp.num_list != NULL)
    {
        free_mem = applib_free_address_list(&g_use_details_cntx.use_detail_rsp.num_list, mmi_mv_free_use_detail_mem);
        ASSERT(free_mem);

    }

    if (g_use_details_cntx.use_detail_rsp.email_list != NULL)
    {
        free_mem = applib_free_address_list(&g_use_details_cntx.use_detail_rsp.email_list, mmi_mv_free_use_detail_mem);
        ASSERT(free_mem);
    }

    if (g_use_details_cntx.use_detail_rsp.url_list != NULL)
    {
        free_mem = applib_free_address_list(&g_use_details_cntx.use_detail_rsp.url_list, mmi_mv_free_use_detail_mem);
        ASSERT(free_mem);
    }

    memset(&g_use_details_cntx, 0, sizeof(mmi_mv_use_details_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_use_details_req_hdlr
 * DESCRIPTION
 *  get use details req hldr
 * PARAMETERS
 *  msgPtr      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_get_use_details_req_hdlr(void *msgPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_mv_get_use_details_req_struct *use_detail_req = (mmi_mv_get_use_details_req_struct*) msgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mv_get_use_details_deinit();

    if (g_mv_cntx.msg_cntx->slide_head == NULL && use_detail_req->request_type != MMI_MV_GET_USE_DETAILS_MSG_HEADERS)
    {
        g_use_details_cntx.use_detail_rsp.result = MMI_MV_GET_USE_DETAILS_RESULT_FAILED;
    }

    g_use_details_cntx.progress_screen_id = use_detail_req->progress_screen_id;

    if (use_detail_req->request_type == MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT)
    {
        g_use_details_cntx.state = MMI_MV_GET_USE_DETAILS_SLIDE_CURRENT;
        g_use_details_cntx.current_slide = g_mv_cntx.msg_cntx->current_slide;
        mmi_mv_start_compute_use_details();
    }
    else if (use_detail_req->request_type == MMI_MV_GET_USE_DETAILS_SLIDE_ALL)
    {
        g_use_details_cntx.state = MMI_MV_GET_USE_DETAILS_SLIDE_ALL;
        g_use_details_cntx.current_slide = g_mv_cntx.msg_cntx->slide_head;
        mmi_mv_start_compute_use_details();
    }
    else if (use_detail_req->request_type == MMI_MV_GET_USE_DETAILS_MSG_HEADERS)
    {
        /* Remove Code after 7.42 */
        g_use_details_cntx.state = MMI_MV_GET_USE_DETAILS_MSG_HEADERS;
        g_use_details_cntx.use_detail_rsp.header_email_list = NULL;
        g_use_details_cntx.use_detail_rsp.header_num_list = NULL;
        g_use_details_cntx.use_detail_rsp.result = MMI_MV_GET_USE_DETAILS_RESULT_SUCCESS;
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_get_use_details_req_hdlr: Shouldn't come here!*\n");
        mmi_mv_send_get_use_details_rsp();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_send_read_report_rsp
 * DESCRIPTION
 *  send read report rsp
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_send_read_report_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* UNUSED inMsg we don't care whether RR a success */
    /*
     * wap_mma_send_rsp_struct *msg = (wap_mma_send_rsp_struct*) inMsg;
     * if (msg->msg_id == g_mv_cntx.msg_id )
     * {
     * 
     * }
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_send_read_report_req
 * DESCRIPTION
 *  send read report req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_send_read_report_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_send_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_send_read_report_req *\n");
    msgReq = (wap_mma_send_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_VIEWER;
    msgReq->msg_id = g_mv_cntx.msg_id;
    msgReq->req_id = wap_mma_get_request_id();
    msgReq->is_read_report = TRUE;
    mmi_mv_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SEND_REQ, (oslParaType*) msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_set_readmark_rsp
 * DESCRIPTION
 *  set readmark rsp
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_set_readmark_rsp(void *inMsg)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_rsp_struct *msg = (wap_mma_set_readmark_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->result == MMA_RESULT_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_set_readmark_rsp: Valid *\n");
        mmi_umms_update_status_icon_indicator();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_set_readmark_req
 * DESCRIPTION
 *  set readmark req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_set_readmark_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_set_readmark_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_set_readmark_req: Valid *\n");

    msgReq = (wap_mma_set_readmark_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->app_id = MMA_APP_ID_VIEWER;
    msgReq->msg_id = g_mv_cntx.msg_id;
    msgReq->req_id = wap_mma_get_request_id();
    msgReq->readmark = MMI_TRUE;
    mmi_mv_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_SET_READMARK_REQ, (oslParaType*) msgReq, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_image_expired_callback
 * DESCRIPTION
 *  callback from DRM about image expiry
 * PARAMETERS
 *  result      [IN]        
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_image_expired_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *obj;
    wgui_mv_slide_struct *CURRENT_SLIDE = g_mv_cntx.msg_cntx->current_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CURRENT_SLIDE->image.id)
    {
        /* We have a valid image on slide */
        obj = mmi_mv_object[CURRENT_SLIDE->image.id];
        MMI_ASSERT(obj);

        if (obj->consume_id == id)
        {
            /* The object on current slide seems to have expired */            
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_image_expired_callback: Expired *\n");
            mmi_mv_stop_consume_rights (CURRENT_SLIDE->image.id);
            obj->rights_expired = MMI_TRUE;
            Category630ImageRightExpiredNotify();
        }
    }
}

#ifdef MMI_MV_UNIT_TEST
void timercallback(void)
{
    mmi_mv_image_expired_callback(0, 0);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_start_consume_image_rights
 * DESCRIPTION
 *  start to consume image rights
 * PARAMETERS
 *  object_id           [IN]        
 *  file_path           [IN]        
 *  consume_count       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mv_start_consume_image_rights(U32 object_id, PU16 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 drm_fh;
    MMI_BOOL ret_val = MMI_TRUE;
    mmi_mv_object_struct *obj = mmi_mv_object[object_id];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Consuming rights for a null object? */
    ASSERT(obj);

#ifdef __DRM_SUPPORT__

    if (obj->consume_id == 0)
    {
        /* If Not Already Consuming! */
    if ((drm_fh = DRM_open_file((U16*) file_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY)) >= FS_NO_ERROR)
    {
        if (DRM_validate_permission(drm_fh, NULL, DRM_PERMISSION_DISPLAY))
        {
                if (MMI_FALSE == obj->consume_only_timed)
                {
                    /* Consume count and time */
                    obj->consume_id = DRM_consume_rights(drm_fh, DRM_PERMISSION_DISPLAY, mmi_mv_image_expired_callback);
/* MAUI_00472074: even back from popup we want to consume another count! */
#ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
                    obj->consume_only_timed = MMI_TRUE;
#endif
                }
                else
                {
                    /* Consume time only */
                    obj->consume_id = DRM_consume_timed_rights(drm_fh, DRM_PERMISSION_DISPLAY, mmi_mv_image_expired_callback);
                }
            /* Have valid permissions! */
            ret_val = MMI_TRUE;
                obj->rights_expired = MMI_FALSE;
        }
        else
        {
            /* Don't have valid permissions! */
            ret_val = MMI_FALSE;
                obj->rights_expired = MMI_TRUE;
        }
        
        DRM_close_file(drm_fh);
    }
    else
    {
        /* Couldn't open file for some reasons: effectively blocked! */
            obj->rights_expired = MMI_TRUE;
        ret_val = MMI_FALSE;
    }
    }
#endif /* __DRM_SUPPORT__ */


    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_start_consume_rights
 * DESCRIPTION
 *  start to consume media (Image/Audio/Video) rights
 * PARAMETERS
 *  object_id       [IN]        
 *  file_path       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_mv_start_consume_rights(U32 object_id, PU16 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *obj = mmi_mv_object[object_id];
    MMI_BOOL ret_val = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Consuming rights for a null object? */
    ASSERT(obj);

    if (obj->drm_type == 0)
    {
        /* Non DRM object */
        return ret_val;
    }

#ifdef __DRM_SUPPORT__
    switch (obj->type)
    {
        case MMI_MV_OBJECT_TYPE_AUDIO:
            if (MMI_TRUE == obj->consume_only_timed)
            {
                mdi_audio_drm_disable_consume_count();
                
            }
/* MAUI_00472074: even back from popup we want to consume another count! */
#ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
            obj->consume_only_timed = MMI_TRUE;
#endif
            break;
        case MMI_MV_OBJECT_TYPE_VIDEO:
            if (MMI_TRUE == obj->consume_only_timed)
            {
                mdi_video_ply_drm_disable_consume_count();
            }
/* MAUI_00472074: even back from popup we want to consume another count! */
#ifdef MMI_Q05_MMSVIEWER_CONSUME_COUNT_ONCE
            obj->consume_only_timed = MMI_TRUE;
#endif
            break;
        case MMI_MV_OBJECT_TYPE_IMAGE:
            ret_val = mmi_mv_start_consume_image_rights(object_id, file_path);
            break;

    }
#endif
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_start_consume_rights: obj_id %d, rights %d *\n", object_id, ret_val);
        
    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_stop_consume_rights
 * DESCRIPTION
 *  stop consume rights
 * PARAMETERS
 *  object_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_stop_consume_rights(U32 object_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *obj = mmi_mv_object[object_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__

    /* Stop consuming rights for a null object? */
    ASSERT(obj);

    if (obj->drm_type == 0 || obj->consume_id == 0)
    {
        /* Consume didn't start for this id */
        return;
    }

    switch (obj->type)
    {
        case MMI_MV_OBJECT_TYPE_IMAGE:
            DRM_stop_consume(obj->consume_id);
            obj->consume_id = 0;
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_stop_consume_rights: obj_id %d*\n", object_id);
            break;
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_update_rights_by_id
 * DESCRIPTION
 *  update rights for a particular id
 * PARAMETERS
 *  id                  [IN]        
 *  rights_expired      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_update_rights_by_id(U32 id, MMI_BOOL rights_expired)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *obj = mmi_mv_object[id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* updating rights for a null object? */
    ASSERT(obj);
#ifdef __DRM_SUPPORT__    
    if (obj->drm_type != 0)
    {
        U16 vfname[MMI_MV_VFN_NUM_OF_WCHAR];
        PU16 drm_file;
        S32 parent_fh;
        S32 drm_fh;
        U8 permissions;

        if (obj->type == MMI_MV_OBJECT_TYPE_IMAGE)
        {
            permissions = DRM_PERMISSION_DISPLAY;
        }
        else
        {
            permissions = DRM_PERMISSION_PLAY;
        }

        mmi_mv_get_filename_by_id(id, vfname, &drm_file, &parent_fh);
        drm_fh = DRM_open_file((PU16) drm_file, FS_READ_ONLY, permissions);

        if (drm_fh >= FS_NO_ERROR)
        {
            if (MMI_FALSE == DRM_validate_permission(drm_fh, NULL, permissions))
            {
                obj->rights_expired = MMI_TRUE;
            }
            else
            {
                obj->rights_expired = MMI_FALSE;
            }

            DRM_close_file(drm_fh);
        }
        else
        {
            /* As good as rights expired */
            obj->rights_expired = MMI_TRUE;
        }

        if (parent_fh)
        {
            FS_Close(parent_fh);
        }
    }
#else
    obj->rights_expired = rights_expired;
#endif
}

/* Return True if we don't have rights */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_check_rights_by_id
 * DESCRIPTION
 *  check rights for a object id
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  TRUE if DRM locked
 *****************************************************************************/
static MMI_BOOL mmi_mv_check_rights_by_id(U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *obj = mmi_mv_object[id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* checking rights for a null object? */
    ASSERT(obj);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_check_rights_by_id: obj_id %d, rights %d*\n", id, obj->rights_expired);

    return (obj->rights_expired);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_drm_async_cb
 * DESCRIPTION
 *  Callback from DRM Engine after processing
 * PARAMETERS
 *  serial      [IN]        
 *  result      [IN]        
 *  offset      [IN]        
 *  len         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_drm_async_cb(kal_uint8 serial, 
                                kal_int32 result, 
                                kal_char *dest_content_type, 
                                kal_char *dest_file_ext, 
                                kal_uint32 plaintext_len, 
                                kal_uint32 plaintext_offset_in_dm)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *obj = mmi_mv_object[g_mv_cntx.obj_iterator];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    /* obj is NULL? */
    ASSERT(obj);
    /* We didn't call process drm for non drm objs */
    ASSERT(obj->drm_type != MMA_DRM_NONE);
    /* we didn't make this request */
    ASSERT(g_mv_drm_process_cntx.serial == serial);

    if (result < 0)
    {
        obj->rights_expired = MMI_TRUE;
    }
    else if (obj->drm_type == MMA_DRM_FL_CD)
    {
        obj->drm_offset = obj->offset + plaintext_offset_in_dm;
        obj->drm_size = plaintext_len;
        obj->is_virtual_file = MMI_TRUE;
    }
    else if (obj->drm_type == MMA_DRM_SD || obj->drm_type == MMA_DRM_SD_NO_RIGHT)
    {
        ASSERT(dest_file_ext);
        /* Get file extension of g_mv_drm_process_cntx.new_path and store it */
        mmi_ucs2ncpy((PS8) obj->drm_ext, (PS8) dest_file_ext, FMGR_MAX_EXT_LEN);
    }
    else
    {
        ASSERT(0);
    }

    /* validate permissions */

    if (obj->rights_expired == MMI_FALSE)
    {
        U16 vfname[MMI_MV_VFN_NUM_OF_WCHAR];
        PU16 drm_file;
        S32 parent_fh;
        S32 drm_fh;
        U8 permissions;

        if (obj->type == MMI_MV_OBJECT_TYPE_IMAGE)
        {
            permissions = DRM_PERMISSION_DISPLAY;
        }
        else
        {
            permissions = DRM_PERMISSION_PLAY;
        }

        mmi_mv_get_filename_by_id(g_mv_cntx.obj_iterator, vfname, &drm_file, &parent_fh);
        drm_fh = DRM_open_file((PU16) drm_file, FS_READ_ONLY, permissions);

        if (drm_fh >= FS_NO_ERROR)
        {
            if (MMI_FALSE == DRM_validate_permission(drm_fh, NULL, permissions))
            {
                obj->rights_expired = MMI_TRUE;
            }

            DRM_close_file(drm_fh);
        }
        else
        {
            /* As good as rights expired */
            obj->rights_expired = MMI_TRUE;
        }

        if (parent_fh)
        {
            FS_Close(parent_fh);
        }
    }

    /* In any event start to process next obj */
    if (g_mv_drm_process_cntx.vf_handle != 0)
    {
        FS_Close(g_mv_drm_process_cntx.vf_handle);
    }

    mmi_mv_process_drm_files();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_process_single_drm_file
 * DESCRIPTION
 *  process single DRM file
 * PARAMETERS
 *  obj     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_process_single_drm_file(mmi_mv_object_struct *obj)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU16 drm_file;
    S32 install_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj->is_virtual_file)
    {
        S32 result;

        g_mv_drm_process_cntx.vf_handle = FS_Open(obj->file_path, FS_READ_ONLY | FS_OPEN_SHARED);
        ASSERT(g_mv_drm_process_cntx.vf_handle > 0);

        result = FS_GenVirtualFileName(
                    g_mv_drm_process_cntx.vf_handle,
                    (PU16) g_mv_drm_process_cntx.vfname,
                    (unsigned int)FS_GenVFN_SIZE,
                    obj->offset,
                    obj->size);
        ASSERT(result >= 0);
        drm_file = g_mv_drm_process_cntx.vfname;
        /* g_mv_drm_process_cntx.vf_handle is still open */
        /* close in mmi_mv_drm_async_cb etc */
    }
    else
    {
        drm_file = obj->file_path;
    }

    if (obj->drm_type == MMA_DRM_FL_CD)
    {
        install_result = DRM_install_object (TRUE, /* is_async */
                            (PU8) "application/vnd.oma.drm.message", /* content_type */
                            &g_mv_drm_process_cntx.serial, /* serial */
                            drm_file, /* src_path */
                            FALSE, /* src_is_buffer */
                            obj->is_virtual_file, /* src_is_virtual */
                            TRUE, /* src_need_kept */
                            NULL, /* dest_path */
                            0, /* dest_buffer_len */
                            FALSE, /* dest_need_kept */
                            NULL, /* dest_content_type */
                            NULL, /* dest_file_ext */
                            NULL, /* plaintext_len */
                            NULL, /* plaintext_offset_in_dm */
            mmi_mv_drm_async_cb);
        ASSERT(install_result != DRM_RESULT_INVALID_PARA);
        return;

    }
    else if (obj->drm_type == MMA_DRM_SD || obj->drm_type == MMA_DRM_SD_NO_RIGHT)
    {
        install_result = DRM_install_object (TRUE, /* is_async */
                            (PU8) "application/vnd.oma.drm.content", /* content_type */
                            &g_mv_drm_process_cntx.serial, /* serial */
                            drm_file, /* src_path */
                            FALSE, /* src_is_buffer */
                            obj->is_virtual_file, /* src_is_virtual */
                            TRUE, /* src_need_kept */
                            NULL, /* dest_path */
                            0, /* dest_buffer_len */
                            FALSE, /* dest_need_kept */
                            NULL, /* dest_content_type */
                            NULL, /* dest_file_ext */
                            NULL, /* plaintext_len */
                            NULL, /* plaintext_offset_in_dm */
            mmi_mv_drm_async_cb);
        ASSERT(install_result != DRM_RESULT_INVALID_PARA);
        return;
    }

    ASSERT(0);
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_process_drm_files
 * DESCRIPTION
 *  Process all DRM files in MMS
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_process_drm_files(void)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_mv_object_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mv_drm_process_cntx, 0, sizeof(g_mv_drm_process_cntx));

    /* It maybe coming from mmi_mv_handle_multipart_msg (iterator = 0) */
    /* It may have returned w/o incrementing iterator after process_single_drm_file */
    ++g_mv_cntx.obj_iterator;

    /* Find and process DRM files */
    while (g_mv_cntx.obj_iterator <= g_mv_cntx.total_object_num)
    {
        temp = mmi_mv_object[g_mv_cntx.obj_iterator];
        MMI_ASSERT(temp);
        
        /* don't iterate through un referenced objects! */
        if (temp->drm_type != 0 
            && temp->reference_count > 0 
            && (temp->type != MMI_MV_OBJECT_TYPE_ATTACHMENT))
        {
            /* DRM Process FL/CD/SD Files here */
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_process_drm_files: id: %d *\n", g_mv_cntx.obj_iterator);
            mmi_mv_process_single_drm_file(temp);
            return;
        }

        /* See if next object needs to be DRM processed */
        ++g_mv_cntx.obj_iterator;
    }

    /* We have iterated through all objects! */
    mmi_mv_proceed_to_view();
#else
    mmi_mv_proceed_to_view();
#endif /* __DRM_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_add_slide_per_object
 * DESCRIPTION
 *  add slides for objects if no slides in MMS
 * PARAMETERS
 *  obj     [IN]        
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mv_add_slide_per_object(mmi_mv_object_struct *obj, U32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *current_mime_type;
    wgui_mv_slide_struct *new_slide;
    U16 slide_size;
    mmi_mv_attachment_info_struct *att;
    applib_mime_type_enum obj_mime_type;
    MMI_BOOL is_archive = MMI_FALSE;
#ifdef __DRM_SUPPORT__
    S32 vf_handle=0;
    S32 drm_handle=0;
    U16 VF_NAME[MMI_MV_VFN_NUM_OF_WCHAR];
    PU16 drm_file;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj->drm_type == 0)
    {
        current_mime_type = mime_get_file_type(obj->file_name);
        obj_mime_type = current_mime_type->mime_type;
    }
    else
    {
#ifdef __DRM_SUPPORT__
        if (obj->is_virtual_file)
        {
            S32 result;

            vf_handle = FS_Open(obj->file_path, FS_READ_ONLY | FS_OPEN_SHARED);
            ASSERT(vf_handle > 0);

            result = FS_GenVirtualFileName(vf_handle,
                                            (PU16) VF_NAME,
                                            (unsigned int)FS_GenVFN_SIZE,
                                            obj->offset,
                                            obj->size);
            ASSERT(result >= 0);
            drm_file = VF_NAME;
            /* g_mv_drm_process_cntx.vf_handle is still open */
            /* close in mmi_mv_drm_async_cb etc */
        }
        else
        {
            drm_file = obj->file_path;
        }

        drm_handle = DRM_open_file(drm_file, FS_READ_ONLY, DRM_PERMISSION_NONE);

#ifdef __DRM_V02__
        is_archive = DRM_is_archive(drm_handle, NULL);
#endif
        if (MMI_FALSE == is_archive)
        {
            U8 ext[FMGR_MAX_EXT_LEN+1];
            PU8 ext_name;
            /* Even if it's ODF file it's just a single file */
            ext_name = (PU8)DRM_get_content_ext(drm_handle, NULL);
            if (ext_name != NULL)
            {
                mmi_asc_n_to_ucs2((PS8)ext, (PS8)ext_name, FMGR_MAX_EXT_LEN);
                current_mime_type = mime_type_look_up_ext(NULL, NULL, NULL, (PS8)ext, 0, 0);
                obj_mime_type = current_mime_type->mime_type;
            }
            else
            {
                obj_mime_type = MIME_TYPE_UNKNOWN;
            }
        }
        else
        {
            obj_mime_type = MIME_TYPE_UNKNOWN;
        }
#else
        obj_mime_type = MIME_TYPE_UNKNOWN;
#endif
    }

#ifdef __DRM_SUPPORT__
    if (drm_handle)
    {
        FS_Close(drm_handle);
    }

    if (vf_handle)
    {
        FS_Close(vf_handle);
    }
#endif

    switch (obj_mime_type)
    {
        case MIME_TYPE_TEXT:
            obj->type = MMI_MV_OBJECT_TYPE_TEXT;
            obj->reference_count++;
            break;
        case MIME_TYPE_IMAGE:
            obj->type = MMI_MV_OBJECT_TYPE_IMAGE;
            obj->reference_count++;
            break;
        case MIME_TYPE_AUDIO:
            obj->type = MMI_MV_OBJECT_TYPE_AUDIO;
            obj->reference_count++;
            break;
        case MIME_TYPE_VIDEO:
            obj->type = MMI_MV_OBJECT_TYPE_VIDEO;
            obj->reference_count++;
            break;
        default:
            MMI_TRACE(TRACE_INFO, MMI_MV_UNKNOWN_MEDIA, id);
            obj->type = MMI_MV_OBJECT_TYPE_ATTACHMENT;
            obj->reference_count++;
            att = mmi_mv_insert_attachment();
            if (!att)
            {
                return MMI_FALSE;
            }
            mmi_mv_insert_object_to_attachment(obj, att);
            if (!is_archive)
            {
                /* If it is archive we want to add slide with some text! */
                return MMI_TRUE;
            }
            break;
    }

    slide_size = sizeof(wgui_mv_slide_struct);
    new_slide = mmi_mv_allocate_mem(slide_size);
    if (!new_slide)
    {
        g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
        return MMI_FALSE;
    }

    memset(new_slide, 0, slide_size);

    g_mv_cntx.msg_cntx->total_slide_num++;

    /* Set Slide Parameters */
    if (g_mv_cntx.msg_cntx->slide_timing)
    {
        new_slide->duration = g_mv_cntx.msg_cntx->slide_timing;
    }
    else
    {
        new_slide->duration = 5;
    }

    new_slide->slide_num = g_mv_cntx.msg_cntx->total_slide_num;

    switch (obj->type)
    {
        case MMI_MV_OBJECT_TYPE_TEXT:
            new_slide->text.id = id;
            new_slide->text.begin = 0;
            new_slide->text.end = new_slide->duration;
            new_slide->text.background_color = MMI_MV_DEFAULT_BG_COLOR;
            new_slide->text.foreground_color = MMI_MV_DEFAULT_FG_COLOR;
            new_slide->text.txtSize = 1;
            new_slide->text.txtStyle = 0;
            break;
        case MMI_MV_OBJECT_TYPE_IMAGE:
            new_slide->image.id = id;
            new_slide->image.begin = 0;
            new_slide->image.end = new_slide->duration;
            break;
        case MMI_MV_OBJECT_TYPE_AUDIO:
            new_slide->audio.id = id;
            new_slide->audio.begin = 0;
            new_slide->audio.end = new_slide->duration;
            break;
        case MMI_MV_OBJECT_TYPE_VIDEO:
            new_slide->video.id = id;
            new_slide->video.begin = 0;
            new_slide->video.end = new_slide->duration;
            break;
        default:
            new_slide->text.id = 0;
            new_slide->text.begin = 0;
            new_slide->text.end = new_slide->duration;
            new_slide->text.background_color = MMI_MV_DEFAULT_BG_COLOR;
            new_slide->text.foreground_color = MMI_MV_DEFAULT_FG_COLOR;
            new_slide->text.txtSize = 1;
            new_slide->text.txtStyle = 0;
            /* odf moved to attachment */
            new_slide->text.str_id = STR_ID_MMS_VIEWER_ODF_MOVED_TO_ATTACHMENT;
            break;
    }

    /* First slide */
    if (g_mv_cntx.msg_cntx->slide_head == NULL)
    {
        new_slide->next = NULL;
        new_slide->previous = NULL;
        g_mv_cntx.msg_cntx->slide_head = new_slide;

    }
    else
    {
        new_slide->next = NULL;
        new_slide->previous = mmi_mv_get_end_slide();
        new_slide->previous->next = new_slide;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_handle_multipart_msg
 * DESCRIPTION
 *  add slide per non attachment media object [blocking function]
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_mv_handle_multipart_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mv_cntx.obj_iterator = 1; /* Start from 1st element */


    while (g_mv_cntx.obj_iterator <= g_mv_cntx.total_object_num)
    {
        temp = mmi_mv_object[g_mv_cntx.obj_iterator];
        MMI_ASSERT(temp);

        if (temp->type < MMI_MV_OBJECT_TYPE_ATTACHMENT)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_handle_multipart_msg: id: %d *\n", g_mv_cntx.obj_iterator);
            if (MMI_FALSE == mmi_mv_add_slide_per_object(temp, g_mv_cntx.obj_iterator))
            {
                return MMI_FALSE;
            }
        }

        ++g_mv_cntx.obj_iterator;
    }

    g_mv_cntx.obj_iterator = 0; /* Reset global obj_iterator for DRM Process function */

    mmi_mv_process_drm_files();
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_proceed_to_view
 * DESCRIPTION
 *  finally call to show viewer or status message for RR/DR
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_proceed_to_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if zero slide */
    if (g_mv_cntx.msg_cntx->total_slide_num == 0)
    {
        wgui_mv_slide_struct *new_slide;
        U16 slide_size;

        /* Add Empty Slide */
        slide_size = sizeof(wgui_mv_slide_struct);
        new_slide = mmi_mv_allocate_mem(slide_size);
        if (!new_slide)
        {
            /* XML Parser already stopped */
            g_mv_cntx.exit_reason = MMI_MV_OUT_OF_MEM;
            mmi_mv_exit_viewer_application();
            return;
        }

        memset(new_slide, 0, slide_size);
        g_mv_cntx.msg_cntx->total_slide_num++;

        /* Set Slide Parameters */
        if (g_mv_cntx.msg_cntx->slide_timing)
        {
            new_slide->duration = g_mv_cntx.msg_cntx->slide_timing;
        }
        else
        {
            new_slide->duration = 5;
        }

        new_slide->slide_num = g_mv_cntx.msg_cntx->total_slide_num;
        new_slide->next = NULL;
        new_slide->previous = NULL;
        g_mv_cntx.msg_cntx->slide_head = new_slide;
    }

    g_mv_cntx.msg_cntx->current_slide = g_mv_cntx.msg_cntx->slide_head;


    if (g_mv_cntx.msg_type == MMA_MSG_TYPE_MMS)
    {
        wgui_mv_initialize_struct init;

        /* Callbacks to APP */
        init.get_filename_by_id_cb = mmi_mv_get_filename_by_id;
        init.load_slide_txt_cb = mmi_mv_load_ucs2_txt_to_buffer;
        init.check_rights_cb = mmi_mv_check_rights_by_id;
        init.consume_rights_cb = mmi_mv_start_consume_rights;
        init.stop_consume_rights_cb = mmi_mv_stop_consume_rights;
        init.update_rights_cb = mmi_mv_update_rights_by_id;
        init.stop_app_cb = mmi_mv_exit_viewer_application;
        init.allow_audio_cb = mmi_mv_allow_audio_playing;

        /* Data Members */
        init.current_msg = g_mv_cntx.msg_cntx;
        init.ptxtbuffer = g_mv_cntx.slide_txt_buffer;
        init.ptxtbuffersize = MMI_MV_TXT_BUF_UCS2_SIZE;
        init.pinputboxbuffer = g_mv_cntx.inputbox_buffer;

        Category630Initialize(&init);
    }

    if (g_mv_cntx.set_readmark == MMI_TRUE)
    {
        mmi_mv_set_readmark_req();
        g_mv_cntx.set_readmark = MMI_FALSE;
    }

    if (g_mv_cntx.send_read_report == MMI_TRUE)
    {
        umms_read_report_enum rr_status = mmi_umms_retrieval_settings_read_report();

        if (rr_status == E_READ_REPORT_SEND_ON_REQUEST)
        {
            mmi_mv_send_rr_confirm_or_replace();
            return;
        }
        else if (rr_status == E_READ_REPORT_SEND_NEVER)
        {
            g_mv_cntx.send_read_report = MMI_FALSE;
        }
    }

    mmi_mv_view_or_replace();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_mms_content_rsp
 * DESCRIPTION
 *  get mms content rsp
 * PARAMETERS
 *  inMsg       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_get_mms_content_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_rsp_struct *msg_rsp = (wap_mma_get_content_rsp_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(msg_rsp->req_id == g_mv_cntx.request_id);
    ASSERT(msg_rsp->msg_id == g_mv_cntx.msg_id);
    ASSERT(msg_rsp->buffer_index == g_mv_cntx.buffer_index);

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_get_mms_content_rsp: MMA RESULT NOT *\n");
        mmi_mv_exit_viewer_application();
    }
    else
    {
        if (msg_rsp->more)
        {
            /*----------------------------------------------------------------*/
            /* Local Variables                                                */
            /*----------------------------------------------------------------*/
            wap_mma_get_content_req_struct *msg_req;

            /*----------------------------------------------------------------*/
            /* Code Body                                                      */
            /*----------------------------------------------------------------*/
            msg_req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));

            g_mv_cntx.buffer_index++;

            msg_req->req_id = g_mv_cntx.request_id;
            msg_req->msg_id = g_mv_cntx.msg_id;
            msg_req->buffer_index = g_mv_cntx.buffer_index;
            msg_req->app_id = MMA_APP_ID_VIEWER;
            msg_req->mode = MMA_MODE_VIEW;

            mmi_mv_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msg_req, NULL);
        }
        else
        {
            XML_RESULT_ENUM result;

            /* parse the XML file */
                result = mmi_mv_parse_mms_xml_description_file(msg_rsp->xml_filepath, MMI_MV_MSG_PARSER_DO_BEST_FIT);
                if (result == XML_RESULT_OK)
                {
                    g_mv_cntx.obj_iterator = 0; /* start with 0th object */

                    if (g_mv_cntx.msg_cntx->total_slide_num == 0)
                    {
                        /* we need to add slides as this maybe a multipart message */
                        g_mv_cntx.msg_cntx->layout = MMI_MV_DEFAULT_IMAGE_LAYOUT;
                        g_mv_cntx.msg_cntx->background_color = MMI_MV_DEFAULT_BG_COLOR;
                        g_mv_cntx.msg_cntx->foreground_color = MMI_MV_DEFAULT_FG_COLOR;
                        /* following function will call DRM Process function */
                        if (MMI_FALSE == mmi_mv_handle_multipart_msg())
                        {
                            mmi_mv_exit_viewer_application();
                            return;
                        }
                    }
                    else
                    {
                        /* DRM Process */
                        mmi_mv_process_drm_files();
                    }

                }
                else
                {
                    mmi_mv_exit_viewer_application();
                }
            }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_mms_content_req
 * DESCRIPTION
 *  get mms content req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_get_mms_content_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_content_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mv_cntx.request_id = wap_mma_get_request_id();

    msg_req = (wap_mma_get_content_req_struct*) OslConstructDataPtr(sizeof(wap_mma_get_content_req_struct));
    msg_req->req_id = g_mv_cntx.request_id;
    msg_req->msg_id = g_mv_cntx.msg_id;
    msg_req->buffer_index = g_mv_cntx.buffer_index = 0;
    msg_req->app_id = MMA_APP_ID_VIEWER;
    msg_req->mode = MMA_MODE_VIEW;

    msg_req->creation_mode = MMA_CREATION_MODE_FREE;

    mmi_mv_send_message(MOD_MMI, MOD_WAP, 0, MSG_ID_WAP_MMA_GET_CONTENT_REQ, (oslParaType*) msg_req, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_allocate_mem_and_req_msg_content
 * DESCRIPTION
 *  allocate memory and make msg content req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_allocate_mem_and_req_msg_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mv_cntx.adm_pool_id = kal_adm_create(g_mv_cntx.ptr_asm_pool, MMI_MV_ASM_MEM_POOL_SIZE, NULL, MMI_FALSE);
    ASSERT(g_mv_cntx.adm_pool_id);

    /* Do the biggest malloc here to avoid fragmentation related out-of-memory condition later */
    g_mv_cntx.slide_txt_buffer = kal_adm_alloc(g_mv_cntx.adm_pool_id, MMI_MV_TXT_BUF_UCS2_SIZE);
    g_mv_cntx.msg_cntx = kal_adm_alloc(g_mv_cntx.adm_pool_id, sizeof(wgui_mv_xml_msg_struct));
    g_mv_cntx.src_buffer = kal_adm_alloc(g_mv_cntx.adm_pool_id, MMI_MV_MAX_UTF8_TXT_SLIDE_LEN);
    g_mv_cntx.inputbox_buffer = kal_adm_alloc(g_mv_cntx.adm_pool_id, CAT630_MAIN_TXT_BUFFER_SIZE * ENCODING_LENGTH);

    /* Should ASSERT here instead? */
    if (g_mv_cntx.slide_txt_buffer == NULL || g_mv_cntx.msg_cntx == NULL
        || g_mv_cntx.src_buffer == NULL || g_mv_cntx.inputbox_buffer == NULL)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_allocate_mem_and_req_msg_content: No Memory *\n");
        mmi_mv_exit_viewer_application();
        return;
    }

    /* Reminder: g_mv_cntx.msg_cntx is a pointer to msg context */
    memset(g_mv_cntx.msg_cntx, 0, sizeof(wgui_mv_xml_msg_struct));
    /* Reminder: g_mv_cntx.slide_txt_buffer is pointer to slide_txt_buffer */
    memset(g_mv_cntx.slide_txt_buffer, 0, 2 * ENCODING_LENGTH);
    mmi_mv_object = NULL;
    mmi_mv_get_mms_content_req();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_stop_viewer_callback
 * DESCRIPTION
 *  stop viewer from ASM screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_stop_viewer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* What if the viewer - any of the following screen(s) - are open and a call comes? */
    /* Through call we start some APP using ASM */
    /* Viewer Memory is released but viewer related screens are still present! */
    /* Delete Such Screens */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_stop_viewer_callback *\n");
    
    DeleteScreenIfPresent(SCR_ID_UMMS_RR_CONFIRM_SCREEN);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS_ADDRESS_LIST);
    DeleteScreenIfPresent(SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_UMMS_SAVE_OBJECT);
    DeleteScreenIfPresent(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);
    DeleteScreenIfPresent(SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS);
    DeleteScreenIfPresent(SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES);

    /* De-initialize this application - free adm mem, asm pool, deinit app cntx */
    mmi_mv_deinit_viewer();

    /* Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MMS_VIEWER, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_request_asm_success_callback
 * DESCRIPTION
 *  if ASM successfully freed memory then this is called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_request_asm_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mv_cntx.ptr_asm_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MMS_VIEWER, MMI_MV_ASM_MEM_POOL_SIZE);

    if (g_mv_cntx.ptr_asm_pool)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_request_asm_success_callback *\n");
        /* Re-entering Viewer */
        g_mv_cntx.app_state = MMI_MV_EXIT_ASM_SCR;
        mmi_mv_progress_screen();
        DeleteScreenIfPresent(g_mv_cntx.progress_scr_id);
        mmi_mv_allocate_mem_and_req_msg_content();
        return;
    }
    ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_viewer_show_error_popup
 * DESCRIPTION
 *  shows error popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_viewer_show_error_popup(void)
{
    switch (g_mv_cntx.exit_reason)
    {
        case MMI_MV_PARSER_ERROR:
        case MMI_MV_FILE_ERROR:
            DisplayPopup((PU8) GetString(STR_ID_MMS_VIEWER_FILE_ERROR), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;
        case MMI_MV_OUT_OF_MEM:
        case MMI_MV_OBJ_LIMIT_REACHED:
            DisplayPopup((PU8) GetString(STR_ID_MMS_VIEWER_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;
        case MMI_MV_ROOT_DIR_FULL:
            DisplayPopup((PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT), IMG_GLOBAL_WARNING, 1, 1000, (U8) ERROR_TONE);
            break;
        default:
            DisplayPopup((PU8) GetString(STR_GLOBAL_ABORTING), IMG_GLOBAL_ERROR, 1, 1000, (U8) ERROR_TONE);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_exit_viewer_application
 * DESCRIPTION
 *  deinit and go back
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_exit_viewer_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set send RR var to false before exit viewer screen. */
    g_mv_cntx.send_read_report = MMI_FALSE;
    /*
     * If the category call this fn before calling set readmark
     * * we set readmark to false. This is the scenario when user isn't able
     * * to see a single slide and the viewer aborts, in such a case we don't
     * * want to set msg as read.
     */
    g_mv_cntx.set_readmark = MMI_FALSE;
    /* Warn User and Goback */
    mmi_mv_viewer_show_error_popup();
    mmi_mv_deinit_viewer();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_rsk_fn
 * DESCRIPTION
 *  rsk function called from cat
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_rsk_fn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MAUI_00539316 */
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_rsk_fn: RSK BACK *\n");
    g_mv_cntx.deinit_on_exit = MMI_TRUE;
    /* MAUI_00539316 */
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mv_reenter_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_reenter_progress_screen(void)
{
    if (g_mv_cntx.app_state == MMI_MV_ENTER_ASM_SCR)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_reenter_progress_screen: From ASM Scr *\n");
        /* If Coming back from ASM Screen */
        g_mv_cntx.deinit_on_exit = MMI_TRUE;
        g_mv_cntx.app_state = MMI_MV_EXIT_ASM_SCR;
        EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL);
        /* mmi_mv_deinit_viewer -> delete progressscreen */
        mmi_mv_deinit_viewer();
        GoBackHistory();
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_reenter_progress_screen: After Popup *\n");
        /* In Normal Cases let Progress Screen Continue Playing */
        mmi_mv_progress_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_progress_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mv_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 string[MAX_PROGRESS_STRING_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EntryNewScreen(SCR_ID_UMMS_MMS_VIEWER_PROGRESS_SCREEN, NULL, mmi_mv_reenter_progress_screen, NULL);
    mmi_ucs2ncpy((PS8) string, (PS8) GetString(STR_ID_UMMS_PLEASE_WAIT), MAX_PROGRESS_STRING_LENGTH);
#ifdef __MMI_MAINLCD_240X320__
    ShowCategory8Screen(
        0xFFFF,
        0xFFFF,
        0,
        0,
        0,
        0,
        STR_ID_UMMS_PLEASE_WAIT,
        IMG_GLOBAL_PROGRESS,
        NULL);
#else
    ShowCategory8Screen(
        STR_ID_MMS_VIEWER_APP,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        STR_ID_UMMS_PLEASE_WAIT,
        IMG_GLOBAL_PROGRESS,
        NULL);
#endif

    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

    if (isInCall())
    {
        SetKeyHandler(HangupAllCalls, KEY_END, KEY_EVENT_DOWN);
    }
    g_mv_cntx.progress_scr_id = SCR_ID_UMMS_MMS_VIEWER_PROGRESS_SCREEN;
}

/* External Interfaces APP */


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_is_viewer_in_history
 * DESCRIPTION
 *  is viewer running
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_mv_is_viewer_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    return mmi_mv_is_viewer_init();
    /*
     * Incase DR/RR scr is present but viewer not in history then 
     * mmi_umms_is_option_screen_present is/should be checked
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_init_mms_viewer_at_bootup
 * DESCRIPTION
 *  initialise ASM memory at bootup etc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_init_mms_viewer_at_bootup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_use_details_cntx, 0, sizeof(mmi_mv_use_details_cntx_struct));
    memset(&g_mv_cntx, 0, sizeof(mmi_mv_context_struct));
    SetProtocolEventHandler(mmi_mv_get_use_details_req_hdlr, MSG_ID_MMI_MV_GET_USE_DETAILS_REQ);
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_MMS_VIEWER,
        STR_ID_MMS_VIEWER_APP,
        IMG_ID_MMS_VIEWER_APP,
        mmi_mv_stop_viewer_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_deinit_viewer
 * DESCRIPTION
 *  deinit viewer destory ADM pool. called from Idle screen, before entering a MMS etc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_deinit_viewer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* keep in sync with mmi_mv_delete_screen_cb */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MMS_VIEWER_TIMER);
    DeleteScreenIfPresent(g_mv_cntx.progress_scr_id);
    DeleteScreenIfPresent(SCR_ID_UMMS_RR_CONFIRM_SCREEN);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_VIEWER);

    mmi_mv_get_use_details_deinit();

    if (g_mv_drm_process_cntx.serial != 0)
    {
#ifdef __DRM_SUPPORT__
        DRM_async_cancel_process(g_mv_drm_process_cntx.serial);
#endif
    }

    if (g_mv_drm_process_cntx.vf_handle != 0)
    {
        FS_Close(g_mv_drm_process_cntx.vf_handle);
    }

    if (g_mv_cntx.adm_pool_id)
    {
        kal_adm_delete(g_mv_cntx.adm_pool_id);
    }
    if (g_mv_cntx.ptr_asm_pool)
    {
        applib_mem_ap_free(g_mv_cntx.ptr_asm_pool);
    }

    /* Do this at last */
    memset(&g_mv_drm_process_cntx, 0, sizeof(g_mv_drm_process_cntx));
    memset(&g_mv_cntx, 0, sizeof(mmi_mv_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_view_message
 * DESCRIPTION
 *  view a message from message list
 * PARAMETERS
 *  msg_id                  [IN]        
 *  msg_folder              [IN]        
 *  msg_type                [IN]        
 *  is_already_read         [IN]        
 *  send_read_report        [IN]        
 *  progress_scr_id         [IN]        
 *  lsk_fn                  [IN]        
 *  lsk_str_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_view_message(
        U32 msg_id,
        mma_folder_enum msg_folder,
        mma_msg_type_enum msg_type,
        BOOL is_already_read,
        BOOL send_read_report,
        U16 progress_scr_id,
        void (*lsk_fn) (void),
        U16 lsk_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(msg_type == MMA_MSG_TYPE_MMS);
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_message: Start View Process *\n");
    mmi_mv_deinit_viewer();
    mmi_mv_progress_screen();
    DeleteScreenIfPresent(progress_scr_id);
    g_mv_cntx.app_state = MMI_MV_START_VIEW;

    /* msg_folder unused */
    g_mv_cntx.msg_id = msg_id;
    g_mv_cntx.msg_type = msg_type;
    g_mv_cntx.lsk_fn = lsk_fn;
    g_mv_cntx.lsk_str_id = lsk_str_id;
    g_mv_cntx.rsk_fn = mmi_mv_rsk_fn;

    if (is_already_read == MMI_FALSE && msg_type != MMA_MSG_TYPE_NOTIFICATION)
    {
        if (send_read_report == MMI_TRUE && msg_folder == MMA_FOLDER_INBOX && g_mv_cntx.msg_type == MMA_MSG_TYPE_MMS)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_message: Send RR *\n");
            g_mv_cntx.send_read_report = MMI_TRUE;
        }

        g_mv_cntx.set_readmark = MMI_TRUE;
    }

    g_mv_cntx.ptr_asm_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_MMS_VIEWER, MMI_MV_ASM_MEM_POOL_SIZE);

    if (g_mv_cntx.ptr_asm_pool)
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_message: Got ASM *\n");
        mmi_mv_allocate_mem_and_req_msg_content();
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_view_message: Request ASM *\n");
        mmi_frm_appmem_prompt_to_release_mem(
            STR_ID_MMS_VIEWER_APP,
            IMG_ID_MMS_VIEWER_APP,
            MMI_MV_ASM_MEM_POOL_SIZE,
            mmi_mv_request_asm_success_callback);
        /* Exiting Viewer Screen */
        g_mv_cntx.app_state = MMI_MV_ENTER_ASM_SCR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_preview_msg
 * DESCRIPTION
 *  preview a message
 * PARAMETERS
 *  msg_id          [IN]        
 *  scr_id          [IN]        
 *  lsk_fn          [IN]        
 *  lsk_str_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_preview_msg(U32 msg_id, U16 scr_id, void (*lsk_fn) (void), U16 lsk_str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_mv_view_message(msg_id, 0, MMA_MSG_TYPE_MMS, 1, 0, scr_id, lsk_fn, lsk_str_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_review_msg
 * DESCRIPTION
 *  view a message already being viewed in history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_review_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS, "*[MMSViewer.c]mmi_mv_review_msg: *\n");
    if (IsScreenPresent(SCR_ID_UMMS_MMS_VIEWER) == MMI_FALSE)
    {
        MMI_TRACE(TRACE_INFO, MMI_MV_VIEWER_NOT_IN_HISTORY);
        return;
    }
    
    ClearDelScrnIDCallbackHandler(SCR_ID_UMMS_MMS_VIEWER, mmi_mv_delete_screen_cb);
    EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL);
    DeleteUptoScrID(SCR_ID_UMMS_MMS_VIEWER);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_VIEWER);
    mmi_mv_view_msg();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_goto_slide
 * DESCRIPTION
 *  goto a particular slide
 * PARAMETERS
 *  slide_num       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_goto_slide(U16 slide_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_UMMS_MMS_VIEWER) == MMI_FALSE)
    {
        MMI_TRACE(TRACE_INFO, MMI_MV_VIEWER_NOT_IN_HISTORY);
        return;
    }
    /* Slide Numbers are one based */
    ASSERT(slide_num <= g_mv_cntx.msg_cntx->total_slide_num);

    if (g_mv_cntx.msg_cntx->current_slide->slide_num < slide_num)
    {
        do
        {
            g_mv_cntx.msg_cntx->current_slide = g_mv_cntx.msg_cntx->current_slide->next;
        } while (g_mv_cntx.msg_cntx->current_slide->slide_num != slide_num);
    }
    else if (g_mv_cntx.msg_cntx->current_slide->slide_num > slide_num)
    {
        do
        {
            g_mv_cntx.msg_cntx->current_slide = g_mv_cntx.msg_cntx->current_slide->previous;
        } while (g_mv_cntx.msg_cntx->current_slide->slide_num != slide_num);
    }

    ClearAllKeyHandler();

    ClearDelScrnIDCallbackHandler(SCR_ID_UMMS_MMS_VIEWER, mmi_mv_delete_screen_cb);
    EntryNewScreen(SCR_ID_UMMS_DUMMY, NULL, NULL, NULL);
    DeleteUptoScrID(SCR_ID_UMMS_MMS_VIEWER);
    DeleteScreenIfPresent(SCR_ID_UMMS_MMS_VIEWER);
    EntryNewScreen(SCR_ID_UMMS_MMS_VIEWER, mmi_mv_app_exit_fn, mmi_mv_view_msg, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_UMMS_MMS_VIEWER, mmi_mv_delete_screen_cb);
    ShowCategory630Screen(MMI_TRUE, g_mv_cntx.lsk_fn, g_mv_cntx.lsk_str_id, g_mv_cntx.rsk_fn, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_total_slide_num
 * DESCRIPTION
 *  returns number of total slides
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_mv_get_total_slide_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mv_cntx.msg_cntx->total_slide_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_current_slide_num
 * DESCRIPTION
 *  returns the slide num of current slide
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_mv_get_current_slide_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mv_cntx.msg_cntx->current_slide->slide_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_attachment_list
 * DESCRIPTION
 *  returns the attachment list
 * PARAMETERS
 *  attachment_list         [IN]        
 *  num_of_attachments      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_get_attachment_list(mmi_mv_attachment_info_struct **attachment_list, PU32 num_of_attachments)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(*attachment_list == NULL);
    *attachment_list = g_mv_cntx.attachment_head;
    *num_of_attachments = g_mv_cntx.total_attachment_num;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mv_get_objects_from_current_slide
 * DESCRIPTION
 *  returns objects from current slide
 * PARAMETERS
 *  image       [IN]        
 *  video       [IN]        
 *  audio       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mv_get_objects_from_current_slide(
        mmi_mv_object_struct **image,
        mmi_mv_object_struct **video,
        mmi_mv_object_struct **audio,
        mmi_mv_object_struct **text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(*image == NULL && *video == NULL && *audio == NULL && *text == NULL);

    *text = mmi_mv_object[g_mv_cntx.msg_cntx->current_slide->text.id];
    *image = mmi_mv_object[g_mv_cntx.msg_cntx->current_slide->image.id];
    *video = mmi_mv_object[g_mv_cntx.msg_cntx->current_slide->video.id];
    *audio = mmi_mv_object[g_mv_cntx.msg_cntx->current_slide->audio.id];
}

BOOL mmi_mv_is_viewer_init(void)
{
    PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,"*[MMSViewer.c] mmi_mv_is_viewer_init %d *\n", g_mv_cntx.msg_id);
    if(g_mv_cntx.msg_id)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}
#endif /* __MMI_MMS_2__ */ 

