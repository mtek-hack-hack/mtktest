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
 *  MMSAppSaveObjectsMain.c
 * 
 * Project:
 * --------
 *  MAUI
 * 
 * Description:
 * ------------
 *  MMS Option 'Save Objects' Related APIs
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _MMI_MMSAPPSAVEOBJECTSMAIN_C
#define _MMI_MMSAPPSAVEOBJECTSMAIN_C

#ifdef __MMI_MMS_2__

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "MMSAppResDef.h"
#include "MMSAppGprot.h"
#include "MessagesResourceData.h"
#include "PhoneBookGprot.h"
#include "app_mine.h"
#include "FileMgr.h"
#include "FileManagerGProt.h"
// #include "FileSystemDef.h"
#include "DLAgentDef.h"
#include "fmt_struct.h"
#include "MMSAppSaveObjects.h"
#include "MMSMsgCommonProt.h"
#include "MMSViewerAPPDefs.h"

extern kal_wchar *mime_get_extension(kal_wchar *file_path);
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

static mmi_mv_object_struct *current_obj_ref;
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_save_objects
 * DESCRIPTION
 *  Entry Function for the 'Save Objects' Option in MMS Options Menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_save_objects(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_item_list[MMI_UMMS_NUM_MEDIA_TYPE]; /* Stores the strings id of submenus returned */
    U16 num_item;                               /* Stores no of children in the submenu */
    U16 disp_Attribute;                         /* Stores display attribue */
    U8 *gui_buffer;                             /* Buffer holding history data */
    U16 parent_id;
    mmi_mv_object_struct *image_info = NULL;
    mmi_mv_object_struct *video_info = NULL;
    mmi_mv_object_struct *audio_info = NULL;
    //MTI SAVETEXT
    mmi_mv_object_struct *text_info = NULL;
    mmi_mv_attachment_info_struct *attachment_list = NULL;

    U32 attachment_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MTI SAVETEXT
    mmi_mv_get_objects_from_current_slide(&image_info, &video_info, &audio_info, &text_info);
    mmi_mv_get_attachment_list(&attachment_list, &attachment_count);
    if ((NULL == attachment_list) && (NULL == image_info) && (NULL == audio_info) && (NULL == video_info) && (NULL == text_info))
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_UMMS_SAVE_OBJECT, NULL, mmi_umms_entry_save_objects, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_SAVE_OBJECT);
    parent_id = MENU_ID_UMMS_OPTIONS_SAVE_OBJECTS;
    SetParentHandler(parent_id);
    disp_Attribute = GetDispAttributeOfItem(parent_id);

    if (NULL == image_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS);
    }

    if (NULL == audio_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS);
    }

    if (NULL == video_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS);
    }

    //MTI SAVETEXT
    if (NULL == text_info)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS);
    }

    if (NULL == attachment_list)
    {
        mmi_frm_hide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS);
    }

    num_item = GetNumOfChild_Ext(parent_id);

    GetSequenceStringIds_Ext(parent_id, str_item_list);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_UMMS_OPTIONS_SAVE_OBJECTS,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        num_item,
        str_item_list,
        (PU16) gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_file_name
 * DESCRIPTION
 *  To generate temp Object File Name
 * PARAMETERS
 *  file_path       [IN]        
 *  file_name       [IN]        [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_umms_get_file_name(S8 **const file_path, S8 const *const file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 path_buf[(FMGR_MAX_PATH_LEN + 1)] = {0};
    U32 fpath_len = 0;
    S32 fsHandle = -1;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path_buf, "%c:\\%w", MMI_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_TEMP);

    fsHandle = FS_Open((WCHAR*) path_buf, FS_READ_ONLY | FS_OPEN_SHARED | FS_OPEN_DIR);
    if (fsHandle <= 0)
    {
        result = FS_CreateDir(path_buf);
        if (result < 0)
        {
            PRINT_INFORMATION_2(MMI_TRACE_G6_SMS,
                             "*[mmsappsaveobjectsmain.c] mmi_umms_get_file_name Create DIR FAIL! result = %d*\n", result);
            
            DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(result)),
            IMG_GLOBAL_ERROR,
            0,
            MMI_UMMS_POPUP_TIME,
            ERROR_TONE);
            return MMI_FALSE;
        }
        FS_SetAttributes((unsigned short*)path_buf, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
    else
    {
        FS_Close(fsHandle);
    }

    mmi_ucs2cat((PS8) path_buf, (PS8) file_name);
    fpath_len = (mmi_ucs2strlen((S8*) path_buf) + 1) * ENCODING_LENGTH;
    *file_path = (S8*) umms_malloc(fpath_len);
    if (*file_path == NULL)
    {
        DisplayPopup((PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY), IMG_GLOBAL_ERROR, 1, MMI_UMMS_POPUP_TIME, ERROR_TONE);
        return MMI_FALSE;
    }

    mmi_ucs2cpy((S8*) * file_path, (S8*) path_buf);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_save_media_as
 * DESCRIPTION
 *  Sending request to file manager for saving temporary object file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_save_media_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mv_object_struct *image_info = NULL;
    mmi_mv_object_struct *video_info = NULL;
    mmi_mv_object_struct *audio_info = NULL;
    mmi_mv_object_struct *text_info = NULL;
    mmi_mv_attachment_info_struct *attachment_list = NULL;
    mmi_mv_attachment_info_struct *temp;
    mmi_mv_object_struct *object_info = NULL;
    U32 num_attachment;
    U16 count;
    S8 *file_path = NULL;
    MMI_BOOL bool_result;
    U16 menu_id;
    S32 hilite_index;
    U16 *object_file = NULL;
    PU16 set_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mv_get_objects_from_current_slide(&image_info, &video_info, &audio_info, &text_info);

    menu_id = mmi_umms_get_menu_id();
    if (MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_TEXT_AS == menu_id)
    {
        if (NULL == text_info)
        {
            DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
            return;
        }
        object_info = text_info;
    }
    else if (MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_AUDIO_AS == menu_id)
    {

        if (NULL == audio_info)
        {
            DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
            return;
        }
        object_info = audio_info;
    }
    else if (MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_VIDEO_AS == menu_id)
    {
        if (NULL == video_info)
        {
            DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
            return;
        }
        object_info = video_info;
    }
    else if (MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_IMAGE_AS == menu_id)
    {
        if (NULL == image_info)
        {
            DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
            return;
        }
        object_info = image_info;
    }
    else if (MENU_ID_UMMS_SAVE_OBJECT_OPTIONS_SAVE_ATTACHMENT_AS == menu_id)
    {
        mmi_mv_get_attachment_list(&attachment_list, &num_attachment);

        if (attachment_list != NULL)
        {
            temp = attachment_list;
            hilite_index = mmi_umms_get_hilite_index();

            for (count = 0; count < hilite_index; count++)
            {
                temp = temp->next;
            }
            object_info = temp->object;
        }
        else
        {
            return;
        }
    }

    current_obj_ref = object_info;
    MMI_ASSERT(current_obj_ref);

    mmi_umms_reset_current_obj_drm_type();

    if (object_info != NULL)
    {
            mmi_umms_set_current_obj_drm_type(object_info->drm_type);
        set_name = (U16*) umms_malloc(ENCODING_LENGTH + (ENCODING_LENGTH * mmi_ucs2strlen((PS8) object_info->file_name)));

        if (set_name)
        {
            mmi_ucs2cpy((PS8) set_name, (PS8) object_info->file_name);
            mmi_umms_set_src_file_name(set_name);
        }
        else
        {
            goto error;
        }

        bool_result = mmi_umms_get_file_name(&file_path, (S8*) set_name);
        if (MMI_FALSE == bool_result)
        {
            goto error;
        }

        if (object_info->is_virtual_file != 0)
        {
            FS_HANDLE file_handle;
            S32 result;
            U16 *ptr = NULL;

            object_file = (U16*) umms_malloc(MMI_MV_VFN_NUM_OF_WCHAR*ENCODING_LENGTH);
            if (NULL == object_file)
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UMMS_POPUP_TIME,
                    ERROR_TONE);
                goto error;
            }
            file_handle = FS_Open(object_info->file_path, FS_READ_ONLY | FS_OPEN_SHARED);
            MMI_ASSERT(file_handle > 0);

            result = FS_GenVirtualFileName(file_handle, object_file, (unsigned int)FS_GenVFN_SIZE, 
                        object_info->offset, object_info->size);
            MMI_ASSERT(result >= 0);

            ptr = (U16*) mime_get_extension(object_info->file_name);
            if (ptr != NULL)
            {
                mmi_ucs2cat((S8*) object_file, (S8*) L".");
                mmi_ucs2cat((S8*) object_file, (S8*) ptr);
            }

            mmi_umms_set_object_file_handle(file_handle);
            mmi_umms_set_virtual_file_name(object_file);
        }
        else
        {
            if (NULL == object_info->file_path)
            {
                DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 1, MMI_UMMS_POPUP_TIME, ERROR_TONE);
                goto error;
            }
            object_file = (U16*) object_info->file_path;
            mmi_umms_set_object_file_handle(FS_NO_ERROR);
        }

        mmi_umms_set_media_info(object_info);
        mmi_umms_set_media_file_path((U16*) file_path);

        mmi_umms_set_progress_scr_id(UMMS_SCR_ID_PLEASE_WAIT);
        mmi_umms_progress_screen();

        FS_Delete((U16*) file_path);
        /* Consider revising names: This API needs src_path & dest_path */
        mmi_fmgr_send_copy_req(
            FMGR_ACTION_COPY,
            (U8*) object_file,
            (U8*) file_path,
            mmi_umms_save_object_file_callback);

    }
    else
    {
        DisplayPopup((PU8) GetString(STR_GLOBAL_ERROR), IMG_GLOBAL_ERROR, 0, MMI_UMMS_POPUP_TIME, ERROR_TONE);
    }

    return;
  error:
    if (object_file != NULL)
    {
        umms_free(object_file);
        object_file = NULL;
    }
    if (file_path != NULL)
    {
        umms_free(file_path);
        file_path = NULL;
    }
    if (set_name != NULL)
    {
        umms_free(set_name);
        mmi_umms_set_src_file_name(NULL);
    }
    mmi_umms_close_object_file_handle();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_save_object_file_callback
 * DESCRIPTION
 *  Temporary File Save response handling and sending request to Download
 *  Agent for saving object file
 * PARAMETERS
 *  msg     [IN]        Variable stores the result of copy
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_save_object_file_callback(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_copy_rsp_strcut *msgPtr;
    S8 *temp_url = NULL;
    mmi_da_dispatch_file_req_struct *mmi_da_dispatch_file_req = NULL;
    S8 *url = NULL;
    int len = 0;
    ilm_struct *ilm_ptr = NULL;
    applib_mime_type_struct *umms_applib_mime_type = NULL;
    S8 *mime_type_string = NULL;
    U16 *object_vf = NULL;
    U16 *file_path = NULL;
    U16 *extn_ptr = NULL;
    S8 file_extn[FMGR_MAX_EXT_LEN + 1] = {0};
    PU16 src_file_name;
    U8 drm_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgPtr = (mmi_fmt_copy_rsp_strcut*) msg;
    MMI_ASSERT(current_obj_ref);

    mmi_umms_close_object_file_handle();
    file_path = mmi_umms_get_media_file_path();

        object_vf = mmi_umms_get_virtual_file_name();
        if (object_vf != NULL)
        {
            umms_free(object_vf);
            object_vf = NULL;
        }

    src_file_name = mmi_umms_get_src_file_name();

    if (GetActiveScreenId() != SCR_ID_UMMS_PROGRESS)
    {
        if (mmi_umms_is_usb_mode())
        {
            goto END;
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            goto END;
        }
    }

    if (msgPtr->result >= 0)
    {
        extn_ptr = (U16*) mime_get_extension(src_file_name);
        if (extn_ptr != NULL)
        {
            mmi_ucs2_to_asc((S8*) file_extn, (S8*) extn_ptr);
        }
        if ((strcmp((S8*) file_extn, (S8*) ("jad")) == 0) || (strcmp((S8*) file_extn, (S8*) ("jar")) == 0))
        {
            temp_url = (S8*) umms_malloc((strlen((S8*) "mms://") + 1) * ENCODING_LENGTH);
            if (temp_url != NULL)
            {
                mmi_asc_to_ucs2((S8*) temp_url, (S8*) ("mms://"));
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UMMS_POPUP_TIME,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
                goto END;
            }
        }
        else
        {
            temp_url = (S8*) umms_malloc((mmi_ucs2strlen((S8*) (src_file_name)) + 2) * ENCODING_LENGTH);
            if (temp_url != NULL)
            {
                mmi_asc_to_ucs2(temp_url, "/");
                mmi_ucs2cat(temp_url, (S8*) (src_file_name));
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY),
                    IMG_GLOBAL_ERROR,
                    1,
                    MMI_UMMS_POPUP_TIME,
                    ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
                goto END;
            }
        }

        mmi_da_dispatch_file_req =
            (mmi_da_dispatch_file_req_struct*) construct_local_para(sizeof(mmi_da_dispatch_file_req_struct), TD_CTRL);

        mmi_da_dispatch_file_req->url[0] = '\0';
        mmi_da_dispatch_file_req->mime_type_string[0] = '\0';
        mmi_da_dispatch_file_req->filepath[0] = '\0';
        mmi_da_dispatch_file_req->action = MMI_DA_DOWNLOAD;
        mmi_da_dispatch_file_req->mime_type = 0;
        mmi_da_dispatch_file_req->mime_subtype = 0;
        mmi_ucs2cpy((S8*) mmi_da_dispatch_file_req->filename, (S8*)src_file_name);

        drm_type = mmi_umms_get_current_obj_drm_type();

        

        if (MMA_DRM_FL_CD == drm_type)
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, "application/vnd.oma.drm.message");
        }
        else if (drm_type != 0)
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, "application/vnd.oma.drm.content");
        }
        else if (mime_get_extension(src_file_name) != NULL)
        {
            umms_applib_mime_type = mime_get_file_type(src_file_name);
            if (NULL == umms_applib_mime_type)
            {
                mime_type_string = NULL;
            }
            else
            {
                mime_type_string = umms_applib_mime_type->mime_string;
            }
            if (mime_type_string != NULL)
            {
                strcpy(mmi_da_dispatch_file_req->mime_type_string, mime_type_string);
            }
            else
            {
                U16 *str_ptr = NULL;
                U8 str_temp[FMGR_MAX_EXT_LEN + 1] = {0};

                str_ptr = (U16*) mime_get_extension(src_file_name);
                mmi_ucs2_to_asc((S8*) str_temp, (S8*) str_ptr);
                strcpy(mmi_da_dispatch_file_req->mime_type_string, (S8*) "application/");
                strcat(mmi_da_dispatch_file_req->mime_type_string, (S8*) str_temp);
            }
        }
        else
        {
            strcpy(mmi_da_dispatch_file_req->mime_type_string, (S8*) "application/octet-stream");
        }

        len = (mmi_charset_ucs2_to_utf8_length_in_bytes((U8*) (temp_url)) + 1);
        url = (S8*) umms_malloc(len);
        if (NULL == url)
        {
            DisplayPopup(
                (PU8) GetString(STR_ID_UMMS_OUT_OF_MEMORY),
                IMG_GLOBAL_ERROR,
                1,
                MMI_UMMS_POPUP_TIME,
                ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
            goto END;
        }
        mmi_chset_ucs2_to_utf8_string((U8*) url, len, (U8*) temp_url);
        memset((void*)mmi_da_dispatch_file_req->url, 0, sizeof(mmi_da_dispatch_file_req->url));
        strncpy(mmi_da_dispatch_file_req->url, url, (sizeof(mmi_da_dispatch_file_req->url) - 1));
        umms_free(url);

        memset((void*)mmi_da_dispatch_file_req->filepath, 0, sizeof(mmi_da_dispatch_file_req->filepath));
        mmi_ucs2ncpy(
            (S8*) mmi_da_dispatch_file_req->filepath,
            (S8*) file_path,
            ((sizeof(mmi_da_dispatch_file_req->filepath) / ENCODING_LENGTH) - 1));
        mmi_umms_saving_progress_screen();

        ilm_ptr = allocate_ilm(MOD_WAP);
        ilm_ptr->src_mod_id = MOD_WAP;
        ilm_ptr->dest_mod_id = MOD_MMI;
        ilm_ptr->sap_id = WAP_MMI_SAP;
        ilm_ptr->msg_id = MSG_ID_MMI_DA_DISPATCH_FILE_REQ;
        ilm_ptr->local_para_ptr = (local_para_struct*) mmi_da_dispatch_file_req;
        ilm_ptr->peer_buff_ptr = NULL;
        msg_send_ext_queue(ilm_ptr);
    }
    else
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(msgPtr->result)),
            IMG_GLOBAL_ERROR,
            0,
            MMI_UMMS_POPUP_TIME,
            ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    }
    current_obj_ref = NULL;
  END:
    if (temp_url != NULL)
    {
        umms_free(temp_url);
        temp_url = NULL;
    }
    if (file_path != NULL)
    {
        umms_free(file_path);
        file_path = NULL;
    }
    mmi_umms_set_object_file_handle(FS_NO_ERROR);
    mmi_umms_set_media_info(NULL);
    mmi_umms_set_media_file_path(NULL);
    mmi_umms_set_virtual_file_name(NULL);

    if (src_file_name != NULL)
    {
        umms_free(src_file_name);
        mmi_umms_set_src_file_name(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_entry_view_attachment
 * DESCRIPTION
 *  Entry Function for Attachments' List
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_entry_view_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 *gui_buffer;
    mmi_mv_attachment_info_struct *attachment_list = NULL;
    U32 num_attachment = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_mv_get_attachment_list(&attachment_list, &num_attachment);

    if (NULL == attachment_list)
    {
        DisplayPopup((U8*) GetString(STR_GLOBAL_EMPTY), IMG_GLOBAL_EMPTY, 1, MMI_UMMS_POPUP_TIME, EMPTY_LIST_TONE);
        return;
    }

    EntryNewScreen(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST, NULL, mmi_umms_entry_view_attachment, NULL);
    gui_buffer = GetCurrGuiBuffer(SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST);

    RegisterHighlightHandler(mmi_umms_view_attachment_highlight_hdlr);
   

   
    ShowCategory184Screen(
        STR_ID_UMMS_OBJECTS_ATTACHMENT_LIST,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
            (S32) num_attachment,
            mmi_umms_get_attachment_data,
        0,
        0,
        gui_buffer);
    SetLeftSoftkeyFunction(mmi_umms_entry_save_media_as, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_get_attachment_data
 * DESCRIPTION
 *  Get attachment list data
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [OUT]       
 *  str_img_mask        [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_umms_get_attachment_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num_attach = 0;
    S32 count = 0;
    S32 len = 0;
    mmi_mv_attachment_info_struct *attach_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index < 0)
    {
        return FALSE;
    }
    mmi_mv_get_attachment_list(&attach_list, &num_attach);
    if (attach_list != NULL)
    {

        while (attach_list != NULL && count != item_index)
        {
            attach_list = attach_list->next;
            count++;
        }

        if (attach_list == NULL)
        {
            return FALSE;
        }

        len = (mmi_ucs2strlen((S8*)attach_list->object->file_name)) * ENCODING_LENGTH;
        if (len <= (MAX_SUB_MENU_SIZE - ENCODING_LENGTH))
        {
            mmi_ucs2cpy((S8*) str_buff, (S8*) attach_list->object->file_name);
        }
        else
        {
            mmi_ucs2ncpy((S8*) str_buff, (S8*) attach_list->object->file_name, (MAX_SUB_MENU_SIZE - (4 * ENCODING_LENGTH)) / ENCODING_LENGTH);
            mmi_ucs2cat((S8*) str_buff, (S8*) L"...");
        }
        *img_buff_p = (PU8) GetImage((U16) (IMG_ID_UMMS_ATTACHMENT_LIST));
    }
    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_saving_progress_screen
 * DESCRIPTION
 *  Progress screen for save object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_umms_saving_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_umms_saving_progress_screen");

    EntryNewScreen(SCR_ID_UMMS_PROGRESS, NULL, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_UMMS_PROGRESS);
    ShowCategory66Screen(
        STR_MMS_MENUENTRY,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_ID_UMMS_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearAllKeyHandler();
}

#endif /* __MMI_MMS_2__ */ 

#endif /* _MMI_MMSAPPSAVEOBJECTSMAIN_C */ 

