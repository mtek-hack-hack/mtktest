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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_SWFLASH__
#ifdef SWFLASH_NEOMTEL
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "app_mine.h"
#include "FileMgr.h"
#include "drm_def.h"
#include "gpioInc.h"
#include "DLAgentDef.h"
#include "DLAgentGprot.h"
#include "DLAgentprot.h"
#include "DLAgentResDef.h"
#include "XML_def.h"
#include "SettingDefs.h"                /* ST_NOTIFICATION */
#include "SettingProfile.h"             /* ERROR_TONE */
#include "PhoneBookDef.h"               /* IMG_PROCESSING_PHONEBOOK */
#ifdef WAP_SUPPORT
#include "Wap_ps_struct.h"
#include "Wapadp.h"
#endif
#include "FileManagerGProt.h"        /* PUBLIC PRIVATE DRV */
#include "wgui_categories_inputs.h "/* INPUT_TYPE_USE_ONLY_ENGLISH_MODES */
#include "Conversions.h"
#include "SWFlashGProt.h"
#include "SWFlashProt.h"
#include "SWFlashDef.h"
#include "che_api.h"
#include "FileManagerDef.h"
 __align(4) static STCHE che_str;
#include "zdd_decoder.h"
#include "med_smalloc.h"
#include "Med_api.h"
#include "AsciiProt.h"

/***************************************************************************** 
* enum & structure define
*****************************************************************************/
typedef enum
{
    MMI_SWFLASH_DL_OBJECT_REQUEST = 1,
    MMI_SWFLASH_SEND_REPORT_REQUEST,
    MMI_SWFLASH_REQEUST_MAX
}mmi_swflash_wps_request_enum;

typedef enum
{
    MMI_SWFLASH_INIT,
    MMI_SWFLASH_GET_USER_AGENT_RSP,
    MMI_SWFLASH_SET_CHANNEL_RSP,
    MMI_SWFLASH_UNSET_CHANNEL_RSP,
    MMI_SWFLASH_HTTP_RSP,
    MMI_SWFLASH_CANCEL_RSP,
    MMI_SWFLASH_DL_PROGRESS_IND,
    MMI_SWFLASH_APP_INSTALL_RSP,
    MMI_SWFLASH_HTTP_AUTH_IND,
    MMI_SWFLASH_STATUS_MAX
} mmi_swflash_dl_action_enum;





/***************************************************************************** 
* function prototype
*****************************************************************************/
static void mmi_swflash_entry_process_bar(void);
static void mmi_swflash_entry_select_storage(void);
static void mmi_swflash_send_wps_http_req(U8 request_id, U8 http_method, S8 * url, S8 * post_data, S8 * file_path);
static void mmi_swflash_wps_http_hdlr(void *MsgStruct);
static void mmi_swflash_dl_process_ind_hdlr(void *MsgStruct);
static void mmi_swflash_send_wps_cancel_req(U8 reqeust_id);
static void mmi_swflash_wps_cancel_hdlr(void *MsgStruct);
static void mmi_swflash_wps_set_channel_req(void);
static void mmi_swflash_wps_set_channel_hdlr(void *MsgStruct);
static MMI_BOOL mmi_swflash_parse_descriptor(S8 * file_path);
static BOOL mmi_swflash_send_unset_channel_req(void);
static void mmi_swflash_unset_channel_hdlr(void *MsgStruct);
static void mmi_swflash_get_full_path(S16 drv_letter);
static MMI_BOOL mmi_swflash_check_space(S32 drv, U32 need_space);
static void mmi_swflash_download_main(S32 status, S32 request_id, S32 result);
static MMI_BOOL mmi_swflash_send_dl_progress_res(S32 request_id, S32 seq_number);
static MMI_BOOL mmi_swflash_zdd_file_encrypt(U8 *mykey, FS_HANDLE dest, FS_HANDLE source, U32 file_len);
static U8 mmi_swflash_process_bar_delete_callback(void *in_param);
static U8 mmi_swflash_view_confirm_delete_callback(void *in_param);
static void mmi_swflash_show_percentage_bar(S32 percentage);
static MMI_BOOL mmi_swflash_zdd_file_decrypt(U8 *mykey, FS_HANDLE source, U32 file_size, U8 *encrypt_buf, U8 *decrypt_buf);
static MMI_BOOL mmi_swflash_encrypt_vis_file(void);
static MMI_BOOL mmi_swflash_encrypt_zdd_file(void);
static MMI_BOOL mmi_swflash_check_folder(void);
static void mmi_swflash_get_destnation_fullname(void);
static void mmi_swflash_send_report(void);
static void mmi_swflash_view_confirm(void);
static void mmi_swflash_replace_confirm(void);
static void mmi_swflash_start_download(void);
static MMI_BOOL mmi_swflash_vis_file_encrypt(U8 *mykey, FS_HANDLE dest, FS_HANDLE source, U32 file_len);
static void mmi_swflash_entry_player(void);
static MMI_BOOL mmi_swflash_dl_check_file_exist(S8 *filename);


/***************************************************************************** 
* macro define
*****************************************************************************/
#define MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE FMGR_PATH_BUFFER_SIZE
#define MMI_SWFLASH_DL_MAX_FILENAME_BUF_SIZE 82
#define MMI_SWFLASH_DL_MAX_URL_BUF_SIZE 512
#define MMI_SWFLASH_DL_MAX_MIME_TYPE_BUF_SIZE 80
#define MMI_SWFLASH_DL_MAX_CONTENT_ID_BUF_SIZE 50
#define MMI_SWFLASH_DL_SEND_REPORT_RSP_BUF_SIZE 12
#define MMI_SWFLASH_DL_REQUEST_ID_BASE 200
#define MMI_SWFLASH_DL_REQUEST_ID_RANGE 32
#define MMI_SWFLASH_IMEI_LEN 16
#define MMI_SWFLASH_MAX_VIS_FILE_SIZE 300*1024
#define MMI_SWFLASH_TEMP_VIS_PATH "Z:\\@swflash\\"
#define MMI_SWFLASH_TEMP_VIS_PATH_WCHAR L"Z:\\@swflash\\"


/***************************************************************************** 
* local variable
*****************************************************************************/
typedef struct
{
    U8 request_id;
    U8 request_method;
    U8 storage_index;
    U8 report_count;
    U16 file_path[MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE];
    U16 zdd_file_path[MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE];
    U16 zdd_temp_file_path[MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE];
    U16 temp_file[MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE];
    U16 zdd_re_dl_path[MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE];
    S16 channel_id;
    S32 dl_status;
    S32 acc_size;
    S32 seq_number;
    S32 percentage;
    S32 http_status;
    U32 zdd_file_size;
    MMI_BOOL is_dl_run;
    MMI_BOOL is_wap_start;
}mmi_swflash_dl_struct;

typedef struct
{
    U8 type[MMI_SWFLASH_DL_MAX_MIME_TYPE_BUF_SIZE];
    U8 content_id[MMI_SWFLASH_DL_MAX_CONTENT_ID_BUF_SIZE];
    U8 object_url[MMI_SWFLASH_DL_MAX_URL_BUF_SIZE];
    U8 status_report_url[MMI_SWFLASH_DL_MAX_URL_BUF_SIZE];
    U8 next_url[MMI_SWFLASH_DL_MAX_URL_BUF_SIZE];
    U8 name[MMI_SWFLASH_DL_MAX_FILENAME_BUF_SIZE];
    U16 method;
    U32 size;
    MMI_BOOL is_save;
    MMI_BOOL is_preview;
}mmi_swflash_info_struct;

typedef struct
{
    mmi_swflash_dl_struct swflash_dl;
    mmi_swflash_info_struct swflash_info;
}mmi_swflash_context_struct;
static mmi_swflash_context_struct swflash_content;
static zdd_info_structure zdd_data;    /*engine structure*/
U8 imei_key_buf[MMI_SWFLASH_IMEI_LEN * ENCODING_LENGTH];
static U8 *zdd_encrypt_buf = NULL;
static U8 *zdd_decrypt_buf = NULL;
static U8 padding_in_buf[16];
static U8 padding_out_buf[16];
static U8 *zdd_buf = NULL;
static U16 create_folder_path[6][MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE];
static U8 g_content_id[MMI_SWFLASH_DL_MAX_CONTENT_ID_BUF_SIZE / ENCODING_LENGTH];
static MMI_BOOL g_re_download = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_receive_da_file
 * DESCRIPTION
 *  this is the callback function when Download Agent complete download descriptor ZDD
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        
 *  mime_subtype            sub type(zdd)        
 *  action                  [IN]        
 *  file_path               full name of works        
 *  url                     [IN]        
 *  mime_type_string        [IN]      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 file_path,
        PS8 url,
        PS8 mime_type_string)
{
     
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL pharse_result;
    S32 result = 0;
    U16 temp_folder[256];
    U16 name_buffer[520];
    U16* ptr;
    FS_HANDLE file_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    /*read IMEI number*/
    if (strncmp(url, "mms", 3) == 0)
    {
        kal_wsprintf(
        (kal_wchar*)temp_folder,
        "%c:\\%w",
        MMI_PUBLIC_DRV,
        FMGR_DEFAULT_FOLDER_RECEIVED);
        file_handle = FS_Open((const WCHAR *) temp_folder, FS_OPEN_DIR | FS_READ_ONLY);
        if (file_handle < 0)
        {
            result = FS_CreateDir((const WCHAR *) temp_folder);
        }
        else
        {
            FS_Close(file_handle);
        }
        if (result < 0)
        {
            
            DisplayPopup(
                (PU8) GetString(GetFileSystemErrorString(result)),
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
            return;
        }
        ptr = file_path + mmi_ucs2strlen((const S8*)file_path);
        while (ptr > file_path)
        {
            if (*ptr == L'\\')
            {
                mmi_ucs2cpy((S8*) name_buffer, (S8*) (ptr + 1));
                break;
            }
            ptr--;
        }
        mmi_ucs2cat((S8*) temp_folder, (const S8*) name_buffer);
        FS_Rename((const WCHAR *) file_path, (const WCHAR *) temp_folder);
        DisplayPopup((PU8) GetString(STR_GLOBAL_DONE), IMG_GLOBAL_ACTIVATED, 1, 1000, (U8) SUCCESS_TONE);
        return;
    }
    g_re_download = MMI_FALSE;
    ReadRecord(NVRAM_EF_IMEI_IMEISV_LID, 1, imei_key_buf, MMI_SWFLASH_IMEI_LEN * ENCODING_LENGTH, &error);
    mmi_ucs2cpy((S8 *) swflash_content.swflash_dl.zdd_temp_file_path, (const S8 *) file_path);
    /*delete all the file in the system drive temp folder*/
    result = FS_XDelete(MMI_SWFLASH_TEMP_VIS_PATH_WCHAR, FS_FILE_TYPE, NULL, 0);
    if (result == FS_DEVICE_BUSY || result == FS_LOCK_MUTEX_FAIL)
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
        return;
    }
    pharse_result = mmi_swflash_parse_descriptor((S8 *)file_path);
    if (pharse_result == MMI_FALSE)
    {
        DisplayPopup((PU8)GetString(STR_ID_SWFLASH_ZDD_FILE_INVALID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
        return;
    }
    else
    {
        if (swflash_content.swflash_info.size > MMI_SWFLASH_MAX_VIS_FILE_SIZE)
        {
            DisplayPopup((PU8)GetString(STR_ID_SWFLASH_NOTIFY_TOO_BIG), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            return;
        }
        mmi_swflash_entry_select_storage();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_parse_descriptor
 * DESCRIPTION
 *  this function is to decrypt the descriptor
 * PARAMETERS
 *  file_path         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_parse_descriptor(S8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    S32 nsize = -1;
    S32 nread = -1;
    S32 result;
    FS_HANDLE handle = -1;
    S32 zdd_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    /*g_re_download is a flag to judge if it is download from FMGR*/
    if (g_re_download == MMI_FALSE)
    {
        handle = FS_Open((U16 *)file_path, FS_READ_ONLY);
        if (handle < 0)
        {
            return MMI_FALSE;
        }
        result = FS_GetFileSize(handle, (U32*) &nsize);
        if (result < 0 || nsize <= 0)
        {
            FS_Close(handle);
            return MMI_FALSE;
        }
            
        media_get_ext_buffer(MOD_MMI, (void **)&zdd_buf, nsize);
        MMI_ASSERT(zdd_buf != NULL);

        result = FS_Read(handle, zdd_buf, nsize, (U32*) &nread);
        if (result < 0)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_buf);
            FS_Close(handle);
            return MMI_FALSE;
        }
        FS_Close(handle);
    }
    else
    {
         zdd_buf = (U8 *)zdd_decrypt_buf;
    }
        
    /*engine API to get the content file name in GB format*/
    zdd_size = zdd_get_name(&zdd_data, (const char*)zdd_buf);
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_SWFLASH_DL_ZDD_GET_NAME,zdd_size);
    if (zdd_size < 0)
    {  
        if (g_re_download == MMI_FALSE)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_buf);
            zdd_buf = NULL;
        }
        return MMI_FALSE;
    }
    
    zdd_size =zdd_initialize(&zdd_data, zdd_buf);
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_SWFLASH_DL_ZDD_INIT,zdd_size);
     if (zdd_size < 0)
    {
        if (g_re_download == MMI_FALSE)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_buf);
            zdd_buf = NULL;
         }
        return MMI_FALSE;
    }
    else
    {
       swflash_content.swflash_info.method = zdd_data.DD_method;
    }
    /*decrypt the zdd file*/
    zdd_size = zdd_parser(0, &zdd_data, zdd_buf);
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_SWFLASH_DL_ZDD_PARSER,zdd_size);
    if (zdd_size < 0)
    {
        if (g_re_download == MMI_FALSE)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_buf);
            zdd_buf = NULL;
         }
        return MMI_FALSE;
    }
    else
    {
       mmi_asc_to_ucs2((S8 *)swflash_content.swflash_info.object_url, (S8 *)zdd_data.DD_ObjectURI);
       mmi_asc_to_ucs2((S8 *)swflash_content.swflash_info.next_url, (S8 *)zdd_data.DD_NextURL);
       mmi_asc_to_ucs2((S8 *)swflash_content.swflash_info.content_id, (S8 *)zdd_data.DD_ContentID);
       mmi_asc_to_ucs2((S8 *)swflash_content.swflash_info.status_report_url, (S8 *)zdd_data.DD_StatusReportURL);
       mmi_asc_to_ucs2((S8 *)swflash_content.swflash_info.type, (S8 *)zdd_data.DD_Type);
       mmi_ucs2cpy((S8 *)swflash_content.swflash_info.name, (const S8 *)zdd_data.DD_Name);
       swflash_content.swflash_info.size = zdd_data.DD_Size;
       swflash_content.swflash_info.is_preview = (MMI_BOOL)zdd_data.DD_preview;
       swflash_content.swflash_info.is_save = (MMI_BOOL)zdd_data.DD_Save;
    } 
    if (g_re_download == MMI_FALSE)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&zdd_buf);
        zdd_buf = NULL;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_init
 * DESCRIPTION
 *  init DD_Save flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_swflash_dl_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    /*init the save flag to judge whether the content will be save in folder*/
    swflash_content.swflash_info.is_save = MMI_TRUE;
#ifdef WAP_SUPPORT
    swflash_content.swflash_dl.dl_status = WPS_DL_STATUS_ABORT;
#endif
    swflash_content.swflash_dl.is_dl_run = MMI_FALSE;
    swflash_content.swflash_dl.is_wap_start = MMI_FALSE;
    swflash_content.swflash_dl.channel_id = -1;
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_drive_callback
 * DESCRIPTION
 *  download select the storage callback function
 * PARAMETERS
 *  drv_letter        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_get_drive_callback(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_space_enough = MMI_TRUE;
    MMI_BOOL file_exsit = MMI_FALSE;
    MMI_BOOL is_create_success = MMI_TRUE;
    MMI_BOOL is_zdd_encrypt = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (drv_letter == 0)
    {
        DeleteNHistory(1);
        return;
    }
    swflash_content.swflash_info.is_save = (MMI_BOOL)zdd_data.DD_Save;
    swflash_content.swflash_dl.storage_index= (U8)drv_letter;
    mmi_swflash_get_full_path(swflash_content.swflash_dl.storage_index);
    is_create_success = mmi_swflash_check_folder();
    if (is_create_success == MMI_FALSE)
    {
        swflash_content.swflash_info.is_save = MMI_TRUE;
        return;
    }
    mmi_swflash_get_destnation_fullname();
    if (g_re_download == MMI_FALSE)
    {
        if (swflash_content.swflash_info.is_save == MMI_TRUE)
        {
            is_zdd_encrypt = mmi_swflash_encrypt_zdd_file();
        }
    }
    if (is_zdd_encrypt == MMI_FALSE)
    {
        swflash_content.swflash_info.is_save = MMI_TRUE;
        return;
    }
	
    is_space_enough = mmi_swflash_check_space(swflash_content.swflash_dl.storage_index, swflash_content.swflash_info.size);
    
    if (is_space_enough == MMI_FALSE)
    {
        swflash_content.swflash_info.is_save = MMI_TRUE;
        DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_DISK_FULL), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        return;
    }
    else
    {  
        file_exsit = mmi_swflash_dl_check_file_exist((S8 *)swflash_content.swflash_dl.file_path);
        if (file_exsit == MMI_TRUE)
            {
            mmi_swflash_replace_confirm();
        }
        else
        { 
            mmi_swflash_start_download();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_full_path
 * DESCRIPTION
 *  get the storage full path
 * PARAMETERS
 *  drv_letter        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_get_full_path(S16 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 6; i++)
    {
        memset((S8 *)create_folder_path[i], 0, MMI_SWFLASH_DL_MAX_FILEPATH_BUF_SIZE);
    }
    kal_wsprintf(
        (kal_wchar*) create_folder_path[0],
        "%c:\\%w",
        drv_letter,
        FMGR_DEFAULT_FOLDER_SWFLASH);

    kal_wsprintf((kal_wchar*)create_folder_path[5], MMI_SWFLASH_TEMP_VIS_PATH);
    
    for (i = 0; i < 4; i++)
    {
        mmi_ucs2cpy((S8 *)create_folder_path[i + 1], (const S8 *)create_folder_path[0]);
    }
    mmi_ucs2cat((S8*) create_folder_path[1], (const S8*)SWFLASH_SUB_FOLDER_ANIMATION);
    mmi_ucs2cat((S8*) create_folder_path[2], (const S8*)SWFLASH_SUB_FOLDER_KARAOK);
    mmi_ucs2cat((S8*) create_folder_path[3], (const S8*)SWFLASH_SUB_FOLDER_GAME);
    mmi_ucs2cat((S8*) create_folder_path[4], (const S8*)SWFLASH_SUB_FOLDER_EXTENT);
}


/*****************************************************************************
* FUNCTION
*   mmi_swflash_check_space
* DESCRIPTION
*   check if have enought space to save file
* PARAMETERS
*   drv         [IN]    Check which storage
*   need_space  [IN]    how many space we need.
* RETURNS
*   MMI_TRUE or MMI_FALSE
*****************************************************************************/
static MMI_BOOL mmi_swflash_check_space(S32 drv, U32 need_space)
{
    S32 fs_ret;
    FS_DiskInfo disk_info;
    U16 path[4];
    U64 disk_free_space = 0;

    path[0] = drv;
    path[1] = ':';
    path[2] = '\\';
    fs_ret = FS_GetDiskInfo((PU16) path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= 0)
    {
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        if (disk_free_space < need_space)
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_entry_select_storage
 * DESCRIPTION
 *  download select the storage screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_entry_select_storage(void)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SWFLASH_STORAGE_SELECT, NULL, mmi_swflash_entry_select_storage, NULL);
    mmi_fmgr_sel_drv_and_enter(APP_FILEMANAGER, mmi_swflash_get_drive_callback, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_send_wps_http_req
 * DESCRIPTION
 *  this function is to send http request to WPS
 * PARAMETERS
 *  request_id        [IN]
 *  http_method        [IN]
 *  url        [IN]
 *  post_data        [IN]
 *  file_path        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_send_wps_http_req(U8 request_id, U8 http_method, S8 * url, S8 * post_data, S8 * file_path)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_http_req_struct *http_req;
    wps_http_req_var_struct http_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 pdu_length;
    U16 len;
    S8 object_url[MMI_SWFLASH_DL_MAX_URL_BUF_SIZE / ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((S8 *)object_url, (S8 *)url);
    http_req = (wps_http_req_struct *) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL);
    http_req->channel_id = swflash_content.swflash_dl.channel_id;
    http_req->request_id = request_id + MMI_SWFLASH_DL_REQUEST_ID_BASE;
    http_req->method = http_method;
    http_req->option = WPS_HTTP_OPTION_NO_CACHE;

    http_req_var.request_url_len = (kal_uint32) strlen(object_url);
    http_req_var.request_url = (kal_uint8 *) object_url;
    http_req_var.request_header_len = 0;
    http_req_var.request_header = NULL;

    if (http_method == WPS_HTTP_METHOD_POST)
    {
        ASSERT(post_data != NULL);
        http_req->reply_type = WPS_DATA_TYPE_BUFFER;
        http_req->reply_segment_len = 0;        /* no use here */
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = strlen(post_data);
        http_req->more_post = MMI_FALSE;
        http_req_var.post_segment_len = strlen(post_data);
        http_req_var.post_segment = (kal_uint8 *) post_data;
        http_req_var.request_header_len = 0;
        http_req_var.request_header = NULL;
    }
    else
    {
        ASSERT(file_path != NULL && mmi_ucs2strlen((S8 *) file_path) < 256);
        http_req->reply_type = WPS_DATA_TYPE_FILE;
        mmi_ucs2cpy((S8 *) http_req->reply_path, (S8 *) file_path);
        http_req->reply_segment_len = 0;        /* no use here */
        http_req->post_type = WPS_DATA_TYPE_BUFFER;
        http_req->post_path[0] = '\0';
        http_req->post_path[1] = '\0';
        http_req->post_total_len = 0;
        http_req->more_post = MMI_FALSE;
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);

    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct *)http_req;
    ilm_ptr->msg_id = MSG_ID_WPS_HTTP_REQ;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct *)peer_buff_ptr;

    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);
    
    SetProtocolEventHandler((PsFuncPtr) mmi_swflash_wps_http_hdlr, MSG_ID_WPS_HTTP_RSP);
    SetProtocolEventHandler((PsFuncPtr) mmi_swflash_dl_process_ind_hdlr, MSG_ID_WPS_DL_PROGRESS_IND);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wps_http_hdlr
 * DESCRIPTION
 *  this funtion is the wps http response hdlr
 * PARAMETERS
 *  MsgStruct        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_wps_http_hdlr(void * MsgStruct)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *p = (wps_http_rsp_struct *) MsgStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(p->request_id > MMI_SWFLASH_DL_REQUEST_ID_BASE &&
           p->request_id < MMI_SWFLASH_DL_REQUEST_ID_BASE+ MMI_SWFLASH_DL_REQUEST_ID_RANGE);

    p->request_id = p->request_id - MMI_SWFLASH_DL_REQUEST_ID_BASE;
    swflash_content.swflash_dl.http_status = p->status;
    mmi_swflash_download_main(MMI_SWFLASH_HTTP_RSP, p->request_id, p->result);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_send_wps_cancel_req
 * DESCRIPTION
 *  this function is to send wps cancel request
 * PARAMETERS
 *  request_id        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_send_wps_cancel_req(U8 request_id)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_cancel_req_struct *cancel_req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/   
    cancel_req = (wps_cancel_req_struct *)construct_local_para(sizeof(wps_cancel_req_struct), TD_CTRL);
    cancel_req->channel_id = swflash_content.swflash_dl.channel_id;
    cancel_req->request_id = request_id + MMI_SWFLASH_DL_REQUEST_ID_BASE;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct *)cancel_req;
    ilm_ptr->msg_id = MSG_ID_WPS_CANCEL_REQ;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);

    SetProtocolEventHandler((PsFuncPtr)mmi_swflash_wps_cancel_hdlr, MSG_ID_WPS_CANCEL_RSP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wps_cancel_hdlr
 * DESCRIPTION
 *  this function is the response hdlr of wps cancel request
 * PARAMETERS
 *  MsgStruct        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_wps_cancel_hdlr(void *MsgStruct)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    wps_cancel_rsp_struct *p = (wps_cancel_rsp_struct *)MsgStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    ASSERT(p->request_id > MMI_SWFLASH_DL_REQUEST_ID_BASE &&
        p->request_id < MMI_SWFLASH_DL_REQUEST_ID_BASE + MMI_SWFLASH_DL_REQUEST_ID_RANGE);

    swflash_content.swflash_dl.request_id = p->request_id - MMI_SWFLASH_DL_REQUEST_ID_BASE;
    mmi_swflash_download_main(MMI_SWFLASH_CANCEL_RSP, swflash_content.swflash_dl.request_id, MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wps_http_hdlr
 * DESCRIPTION
 *  download select the storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_dl_process_ind_hdlr(void * MsgStruct)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    wps_dl_progress_ind_struct *p = (wps_dl_progress_ind_struct*)MsgStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    swflash_content.swflash_dl.dl_status = p->status;
    swflash_content.swflash_dl.seq_number = p->seq_num;
    swflash_content.swflash_dl.acc_size = p->acc_size;
    swflash_content.swflash_dl.request_id = p->request_id - MMI_SWFLASH_DL_REQUEST_ID_BASE;
    mmi_swflash_download_main(MMI_SWFLASH_DL_PROGRESS_IND, swflash_content.swflash_dl.request_id, MMI_TRUE);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_download_main
 * DESCRIPTION
 *  this function is to deal with download status message 
 * PARAMETERS
 *  status        [IN]
 *  request_id        [IN]
 *  result        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_download_main(S32 status, S32 request_id, S32 result)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    S32 percentage;
    MMI_BOOL is_vis_encrypt = MMI_TRUE;
    MMI_BOOL is_space_enough = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    switch (status)
    {
        case MMI_SWFLASH_SET_CHANNEL_RSP:
            /*if set channel is failed, AP will return*/
            if (result != WPS_OK)
            {
                DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_NETWORK_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
                return;
            }
            mmi_swflash_send_wps_http_req(MMI_SWFLASH_DL_OBJECT_REQUEST, WPS_HTTP_METHOD_GET, (S8 *)swflash_content.swflash_info.object_url, NULL, (S8 *)swflash_content.swflash_dl.temp_file);
            break;
        case MMI_SWFLASH_HTTP_RSP:
            if (request_id == MMI_SWFLASH_SEND_REPORT_REQUEST)
            {
                swflash_content.swflash_dl.report_count++;
                if (swflash_content.swflash_dl.http_status < 200 && swflash_content.swflash_dl.http_status >= 300 && swflash_content.swflash_dl.report_count< 3)
                {
                    mmi_swflash_send_report();
                }
                else
                {
                    mmi_swflash_send_unset_channel_req();
                }
            }
            else if (request_id ==MMI_SWFLASH_DL_OBJECT_REQUEST)
            {
                /*if time out HTTP_RSP will not return WPS_OK*/
                if (result != WPS_OK)
                {
                    DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_NETWORK_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
                    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
                    return;
                }
            }
            break;
        case MMI_SWFLASH_DL_PROGRESS_IND:
            mmi_swflash_send_dl_progress_res(request_id, swflash_content.swflash_dl.seq_number);
            if (swflash_content.swflash_dl.dl_status == WPS_DL_STATUS_DOWNLOADING)
            {
                percentage = swflash_content.swflash_dl.acc_size * 100 / swflash_content.swflash_info.size;
                if (percentage >= 100)
                {
                    percentage = 99;
                }
                mmi_swflash_show_percentage_bar(percentage);
            }
            else if (swflash_content.swflash_dl.dl_status == WPS_DL_STATUS_COMPLETE)
            {
                mmi_swflash_show_percentage_bar(99);
                is_space_enough = mmi_swflash_check_space(swflash_content.swflash_dl.storage_index, swflash_content.swflash_info.size);
    
                if (is_space_enough == MMI_FALSE)
                {
                    mmi_swflash_send_unset_channel_req();
                    DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_DISK_FULL), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
                    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
                    return;
                }
                if (swflash_content.swflash_info.is_save == MMI_TRUE)
                {
                    is_vis_encrypt = mmi_swflash_encrypt_vis_file();
                }
                if (is_vis_encrypt == MMI_FALSE)
                {
                    /*if encrypt vis fail, should unset channel*/
                    mmi_swflash_send_unset_channel_req();
                    DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_FILE_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
                    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
                    return;
                }
                if (mmi_ucs2strlen((S8 *)swflash_content.swflash_info.status_report_url) != 0)
                {
                    /*if there is status report url, then should send report*/
                    mmi_swflash_send_report();
                    swflash_content.swflash_dl.report_count= 0;
                }
                else
                {
                    mmi_swflash_send_unset_channel_req();
                }
                if (swflash_content.swflash_info.is_preview == MMI_FALSE)
                {
                    mmi_swflash_view_confirm();
                }
                else
                {
                    /*call player play interface here*/
                    mmi_swflash_entry_player();
                }
            }
            else if (swflash_content.swflash_dl.dl_status == WPS_DL_STATUS_ABORT)
            {
                DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_NETWORK_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
                mmi_swflash_send_unset_channel_req();
                return;
            }
            else
            {
                DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NOTIFY_NETWORK_ERROR), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
                DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
                mmi_swflash_send_unset_channel_req();
                return;
            }
            break;
        case MMI_SWFLASH_CANCEL_RSP:
            break;
       default:
            break;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_send_dl_progress_res
 * DESCRIPTION
 *  this function is to send response to WPS when recieve dl process indication message
 * PARAMETERS
 *  reuqest_id        [IN]
 *  seq_number        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_send_dl_progress_res(S32 request_id, S32 seq_number)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_dl_progress_res_struct *progress_res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    progress_res = (wps_dl_progress_res_struct *)construct_local_para(sizeof(wps_dl_progress_res_struct), TD_CTRL);
    progress_res->request_id = request_id + MMI_SWFLASH_DL_REQUEST_ID_BASE;
    progress_res->channel_id = swflash_content.swflash_dl.channel_id;
    progress_res->seq_num = seq_number;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct *)progress_res;
    ilm_ptr->msg_id = MSG_ID_WPS_DL_PROGRESS_RES;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);
    return MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wps_set_channel_req
 * DESCRIPTION
 *  this function is to send set channel request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_wps_set_channel_req(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_set_channel_req_struct *set_channel_req;
    wps_set_channel_req_var_struct set_channel_req_var;
    peer_buff_struct *peer_buff_ptr = NULL;
    U16 len, pdu_length;
	U16 msg_len, ref_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    set_channel_req = (wps_set_channel_req_struct *)construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL);
    msg_len = set_channel_req->msg_len;
    ref_count = set_channel_req->ref_count;
    memset(set_channel_req, 0 , sizeof(wps_set_channel_req_struct));
    set_channel_req->msg_len = msg_len;
    set_channel_req->ref_count = ref_count;
    set_channel_req->use_default = KAL_TRUE;
	
	set_channel_req_var.static_header_len = 0;
    set_channel_req_var.static_header = NULL;
	pdu_length= wps_pun_var_part(WPS_PUN_SIZE,MSG_ID_WPS_SET_CHANNEL_REQ,&set_channel_req_var,NULL);

    if( pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        if (wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, get_pdu_ptr(peer_buff_ptr, &len)) !=
            pdu_length)
        {
            free_peer_buff(peer_buff_ptr);
            peer_buff_ptr = NULL;
        }
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct *)set_channel_req;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct *)peer_buff_ptr;
    ilm_ptr->msg_id = MSG_ID_WPS_SET_CHANNEL_REQ;

    SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);

    SetProtocolEventHandler((PsFuncPtr) mmi_swflash_wps_set_channel_hdlr, MSG_ID_WPS_SET_CHANNEL_RSP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_wps_set_channel_hdlr
 * DESCRIPTION
 *  this function is setting channel request response hdlr
 * PARAMETERS
 *  MsgStruct        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_wps_set_channel_hdlr(void * MsgStruct)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*)MsgStruct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (p->result == WPS_OK)
    {
        swflash_content.swflash_dl.channel_id = p->channel_id;
    }
    else
    {
       swflash_content.swflash_dl.channel_id = -1;
    }
    
    if (swflash_content.swflash_dl.is_dl_run == MMI_TRUE)
    {
        mmi_swflash_download_main(MMI_SWFLASH_SET_CHANNEL_RSP, 0, p->result);
    }  
    else
    {
        if (swflash_content.swflash_dl.channel_id >= 0)
        {
            mmi_swflash_send_unset_channel_req();
        }
        swflash_content.swflash_dl.channel_id = -1;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*   mmi_swflash_send_unset_channel_req
* DESCRIPTION
*   Send "Unset channel" request to wap to destory channel
* PARAMETERS
*   void
* RETURNS
*   MMI_TRUE: OK
*   MMI_FALSE: FAIL
*****************************************************************************/
static BOOL mmi_swflash_send_unset_channel_req(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    wps_unset_channel_req_struct *unset_channel_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (swflash_content.swflash_dl.channel_id >= 0)
    {
        unset_channel_req =
            (wps_unset_channel_req_struct *) construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL);
        unset_channel_req->channel_id = swflash_content.swflash_dl.channel_id;
        
        ilm_ptr = allocate_ilm(MOD_MMI);
        ilm_ptr->local_para_ptr = (local_para_struct *)unset_channel_req;
        ilm_ptr->msg_id = MSG_ID_WPS_UNSET_CHANNEL_REQ;
        ilm_ptr->peer_buff_ptr = NULL;

        SEND_ILM(MOD_MMI, MOD_WPS, WPS_APP_SAP, ilm_ptr);

        SetProtocolEventHandler((PsFuncPtr) mmi_swflash_unset_channel_hdlr, MSG_ID_WPS_UNSET_CHANNEL_RSP);

        return MMI_TRUE;
    }
    else
    {
        ASSERT(0);
    }
    return MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*   mmi_swflash_unset_channel_hdlr
* DESCRIPTION
*   Handler function: To handle "unset channel response", reset the channel_id
* PARAMETERS
*   Message
* RETURNS
*   void
*****************************************************************************/
static void mmi_swflash_unset_channel_hdlr(void *MsgStruct)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_rsp_struct *p = (wps_unset_channel_rsp_struct *) MsgStruct;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (p->result == WPS_OK)
    {
        swflash_content.swflash_dl.channel_id = -1;
    }
    else
    {
        swflash_content.swflash_dl.channel_id = -2;
    }

    mmi_swflash_download_main(MMI_SWFLASH_UNSET_CHANNEL_RSP, 0, p->result);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_file_encrypt
 * DESCRIPTION
 *  this function is to encypt file using che related API 
 * PARAMETERS
 *  mykey        [IN/OUT]
 *  dest            [IN]
 *  source        [IN]
 *  file_len        [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_zdd_file_encrypt(U8 *mykey, FS_HANDLE dest, FS_HANDLE source, U32 file_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];
    kal_uint8 *in, *out;
    kal_bool done = KAL_FALSE;
    kal_bool success = KAL_FALSE;
    kal_uint32 i = 0, size, len;
    S32 fs_ret = 0;
    U32 byte_count = 0;
    U8 byte_residual = 0;
    U8 padding;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    memset(padding_in_buf, 0, 16);
    memset(padding_out_buf, 0, 16);
    media_get_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf, 2048);
    MMI_ASSERT(zdd_encrypt_buf != NULL);
    media_get_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf, 2048);
    MMI_ASSERT(zdd_decrypt_buf != NULL);
    in = zdd_encrypt_buf;
    out = zdd_decrypt_buf;

    che_init(&che_str);
    che_key_action(&che_str, CHE_SET_KEY, mykey, 16);
    memcpy(iv, "4074BCC61602B5BE5EDF3586C1C7E90905D", 16);
    byte_count = file_len / 16;
    byte_residual = file_len % 16;
    fs_ret = FS_Write(dest, iv, 16, &len);
    if (fs_ret < FS_NO_ERROR)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }
    che_set_iv(&che_str, iv, 16);
    size = byte_count * 16;
    fs_ret = FS_Read(source, in, size, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }
    i += len;

    if (i == file_len)
    {
        done = KAL_TRUE;
    }
    success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_ENC, in, out, len, done);
     if (success == KAL_FALSE)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }    
    fs_ret = FS_Write(dest, out, len, &size);
     if (fs_ret < FS_NO_ERROR)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }

    in = padding_in_buf;
    out = padding_out_buf;
    fs_ret = FS_Read(source, in, 16, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }
    padding = 16 - len;
    memset(in + len, padding, padding);
    i += len;

    if (i == file_len)
    {
        done = KAL_TRUE;
    }
    success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_ENC, in, out, 16, done);
    if (success == KAL_FALSE)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }
    
    fs_ret = FS_Write(dest, out, 16, &size);
     if (fs_ret < FS_NO_ERROR)
    {
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        return MMI_FALSE;
    }
     
    if (zdd_encrypt_buf != NULL)
    {    
        media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
        zdd_encrypt_buf = NULL;
    }
    if (zdd_decrypt_buf != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
        zdd_decrypt_buf = NULL;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_file_encrypt
 * DESCRIPTION
 *  this function is to encypt file using che related API 
 * PARAMETERS
 *  mykey        [IN/OUT]
 *  dest            [IN]
 *  source        [IN]
 *  file_len        [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_vis_file_encrypt(U8 *mykey, FS_HANDLE dest, FS_HANDLE source, U32 file_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];
    kal_uint8 *in, *out;
    kal_bool success = KAL_FALSE;
    kal_uint32 i = 0, size, len;
    S32 fs_ret = 0;
    U8 *pindata = NULL;
    U8 *poutdata = NULL;
    U32 byte_count = 0;
    U8 byte_residual = 0;
    U8 padding;
    U16 type_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    media_get_ext_buffer(MOD_MMI,(void **)&pindata, file_len);
    MMI_ASSERT(pindata != NULL);
    media_get_ext_buffer(MOD_MMI,(void **)&poutdata, file_len);
    MMI_ASSERT(poutdata != NULL);
    memset(padding_in_buf, 0, 16);
    memset(padding_out_buf, 0, 16);
    in = pindata;
    out = poutdata;

    if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"vis") == 0)
    {
        type_info = MMI_SWFLASH_TYPE_ANIMATION;
    }
    else if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"kvis") == 0)
    {
        type_info = MMI_SWFLASH_TYPE_KALAOK;
    }
    else if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"ivis") == 0)
    {
        type_info = MMI_SWFLASH_TYPE_GAME;
    }
    else if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"msf") == 0)
    {
        type_info = MMI_SWFLASH_TYPE_MTV;
    }
    else
    {
        type_info = MMI_SWFLASH_TYPE_OTHER;
    }
    che_init(&che_str);
    che_key_action(&che_str, CHE_SET_KEY, mykey, 16);
    memcpy(iv, "4074BCC61602B5BE5EDF3586C1C7E90905D", 16);
    fs_ret = FS_Write(dest, &type_info, 2, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }
    FS_Write(dest, iv, 16, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }
    che_set_iv(&che_str, iv, 16);

    byte_count = file_len / 16;
    byte_residual = file_len % 16;
    size = byte_count * 16;
    fs_ret = FS_Read(source, in, size, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }
    
    success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_ENC, in, out, len, KAL_FALSE);
     if (success == KAL_FALSE)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }
    fs_ret = FS_Write(dest, out, len, &size);
     if (fs_ret < FS_NO_ERROR)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }

    in = padding_in_buf;
    out = padding_out_buf;
    fs_ret = FS_Read(source, in, 16, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }
    padding = 16 - len;
    memset(in + len, padding, padding);
    i += len;

    success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_ENC, in, out, 16, KAL_TRUE);
     if (success == KAL_FALSE)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }
    fs_ret = FS_Write(dest, out, 16, &size);
     if (fs_ret < FS_NO_ERROR)
    {
        if (pindata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pindata);

        if(poutdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
        return MMI_FALSE;
    }

    if (pindata != NULL)
        media_free_ext_buffer(MOD_MMI, (void **)&pindata);
    if(poutdata != NULL)
        media_free_ext_buffer(MOD_MMI, (void **)&poutdata);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_zdd_file_decrypt
 * DESCRIPTION
 *  decypt the zdd file when re-download
 * PARAMETERS
 *  mykey        [IN]
 *  source        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_zdd_file_decrypt(U8 * mykey, FS_HANDLE source, U32 file_size, U8 *encrypt_buf, U8 *decrypt_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];
    kal_bool success = KAL_FALSE;
    kal_uint8 *in, *out;
    kal_uint32 len;
    S32 fs_ret = 0;
    U32 size;
    U8 cut_count = 0;
    U8 i;
    U32 total_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    memset(padding_in_buf, 0, 16);
    memset(padding_out_buf, 0, 16);
    
    in = zdd_encrypt_buf;
    out = zdd_decrypt_buf;
    che_init(&che_str);
    che_key_action(&che_str, CHE_SET_KEY, mykey, 16);
    size = file_size - 32;
    fs_ret = FS_Read(source, iv, 16, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }
    fs_ret = FS_Read(source, in, size, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }
    if (fs_ret >= FS_NO_ERROR && len > 0)
    {
        che_set_iv(&che_str, iv, 16);
        success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_DEC, in, out, len, KAL_FALSE);
    }
     if (success == KAL_FALSE)
    {
        return MMI_FALSE;
    }
    in = padding_in_buf;
    out = padding_out_buf;
    total_len = len;
    fs_ret = FS_Read(source, padding_in_buf, 16, &len);
     if (fs_ret < FS_NO_ERROR)
    {
        return MMI_FALSE;
    }
    success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_DEC, in, out, len, KAL_TRUE);
     if (success == KAL_FALSE)
    {
        return MMI_FALSE;
    }
    cut_count = padding_out_buf[15];
    len = 16 - cut_count;

    for (i = 0; i < (16 - cut_count); i++)
    {
        zdd_decrypt_buf[i + file_size - 32] = padding_out_buf[i];
    }
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_vis_decipher
 * DESCRIPTION
 *  decypt the zdd file when re-download
 * PARAMETERS
 *  mykey        [IN]
 *  source        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL mmi_swflash_vis_decipher(FS_HANDLE input_handle, const S8 *filename, S32 file_nsize, U8 *outbuf, U16 * type_info, S32 *outsize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];
    kal_bool success = KAL_FALSE;
    kal_uint8 *in, *out;
    kal_uint32 len;
    S32 fs_ret = 0;
    U8 *pdata = NULL;
    U32 size;
    U8 cut_count;
    S16 error;
    S8 *padding_adress = (S8 *)outbuf;
    U8 i;
    U16 type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (filename[0] != 'Z')
    {
        ReadRecord(NVRAM_EF_IMEI_IMEISV_LID, 1, imei_key_buf, MMI_SWFLASH_IMEI_LEN * ENCODING_LENGTH, &error);
        media_get_ext_buffer(MOD_MMI,(void **)&pdata, file_nsize);
        MMI_ASSERT(pdata != NULL);
        memset(padding_in_buf, 0, 16);
        memset(padding_out_buf, 0, 16);
        
        size = file_nsize - 34;
        in = pdata;
        out = outbuf;
        che_init(&che_str);
        che_key_action(&che_str, CHE_SET_KEY, imei_key_buf, 16);
        fs_ret = FS_Read(input_handle, &type, 2, &len);
        if (fs_ret < FS_NO_ERROR)
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }
         
        *type_info = type;
        fs_ret = FS_Read(input_handle, iv, 16, &len);
        if (fs_ret < FS_NO_ERROR)
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }
        fs_ret = FS_Read(input_handle, in, size, &len);
        if (fs_ret < FS_NO_ERROR)
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }

        if (fs_ret >= FS_NO_ERROR && len > 0)
        {
            che_set_iv(&che_str, iv, 16);
            success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_DEC, in, out, len, KAL_FALSE);
	        *outsize = len;
            kal_prompt_trace(MOD_MMI,"che_process=%d,FS_Write=%d",success,fs_ret);
        }
        else
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }
        if (success == KAL_FALSE || fs_ret < FS_NO_ERROR)
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }
        in = padding_in_buf;
        out = padding_out_buf;
        fs_ret = FS_Read(input_handle, padding_in_buf, 16, &len);
        if (fs_ret < FS_NO_ERROR)
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }
         
        success = che_process(&che_str, CHE_AES, CHE_CBC, CHE_DEC, in, out, len, KAL_TRUE);
        
        kal_prompt_trace(MOD_MMI,"laterche_process=%d,",success);
        if (success == KAL_FALSE)
        {
            if (pdata != NULL)
                media_free_ext_buffer(MOD_MMI, (void **)&pdata);
            return MMI_FALSE;
        }
        
        cut_count = padding_out_buf[15];
        if (cut_count <= 16)
        {
        len = 16 - cut_count;
        }    
        else
        {
            len = 16;    
        }
	    *outsize += len;
        padding_adress = padding_adress + file_nsize - 34;
        for (i = 0; i < (16 - cut_count); i++)
        {
            padding_adress[i] = padding_out_buf[i];
        }
        if (pdata != NULL)
            media_free_ext_buffer(MOD_MMI, (void **)&pdata);
    }
    else
    {
        fs_ret = FS_Read(input_handle, outbuf, file_nsize, &len);
	    *outsize = file_nsize;
        if (fs_ret < FS_NO_ERROR)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_entry_process_bar
 * DESCRIPTION
 *  this function is to show process bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_card_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (swflash_content.swflash_dl.storage_index == MMI_CARD_DRV)
    {
        if (IsScreenPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR) && swflash_content.swflash_dl.is_dl_run == MMI_TRUE)
        {
            DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); /* From file manager */
            DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION); /* From APP */
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION); /* From Download agent */
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
        }
        else if (GetActiveScreenId() == SCR_ID_SWFLASH_PERCENTAGE_BAR && swflash_content.swflash_dl.is_dl_run == MMI_TRUE)
        {
            DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); /* From file manager */
            DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION); /* From APP */
            DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION); /* From Download agent */
            DeleteScreenIfPresent(SCR_FMGR_EXPLORER);
            GoBackHistory();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_entry_process_bar
 * DESCRIPTION
 *  this function is to show process bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_entry_process_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_SWFLASH_PERCENTAGE_BAR, NULL, mmi_swflash_entry_process_bar, NULL);
        /* hook delete screen hdlr */
    SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_PERCENTAGE_BAR, (HistoryDelCBPtr)mmi_swflash_process_bar_delete_callback);

    ShowCategory402Screen(
            (U8*) GetString(STR_GLOBAL_DOWNLOADING),
            0,
            0,
            0,
            0,
            0,
            NULL,
            (U16) swflash_content.swflash_dl.percentage,
            NULL);
    /* clear End key */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_process_bar_delete_callback
 * DESCRIPTION
 *  this function is the callback function when process bar screen is deleted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_swflash_process_bar_delete_callback(void *in_param)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (swflash_content.swflash_dl.dl_status != WPS_DL_STATUS_COMPLETE)
    {
        mmi_swflash_send_wps_cancel_req(MMI_SWFLASH_DL_OBJECT_REQUEST);
        if (swflash_content.swflash_dl.channel_id >= 0)
        {
        mmi_swflash_send_unset_channel_req();
        }
        SetProtocolEventHandler(NULL, MSG_ID_WPS_HTTP_RSP);
        SetProtocolEventHandler(NULL, MSG_ID_WPS_DL_PROGRESS_IND);
    }
    swflash_content.swflash_dl.dl_status = WPS_DL_STATUS_ABORT;
    swflash_content.swflash_dl.is_dl_run = MMI_FALSE;
    return FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_show_percentage_bar
 * DESCRIPTION
 *  this function is to update process bar
 * PARAMETERS
 *  percentage
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_show_percentage_bar(S32 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_SWFLASH_PERCENTAGE_BAR)
    {
        if(percentage != swflash_content.swflash_dl.percentage)
        {
            swflash_content.swflash_dl.percentage = percentage;
            UpdateCategory402Value((U16)percentage, NULL);
        }
    }
    else if (!IsScreenPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR))
    {
        swflash_content.swflash_dl.percentage = percentage;
        mmi_swflash_entry_process_bar();
    }
    else
    {
        swflash_content.swflash_dl.percentage = percentage;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_filemanager_re_download
 * DESCRIPTION
 *  this function is the interface for FMGR to re-download 
 * PARAMETERS
 *  file_path
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_option_download(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_ret;
	MMI_BOOL parse_ret;
	S16 error;
    MMI_BOOL zdd_decrpt = MMI_FALSE;
    U32 file_size;
    S32 attr = 0;
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    g_re_download = MMI_TRUE;
    ReadRecord(NVRAM_EF_IMEI_IMEISV_LID, 1, imei_key_buf, MMI_SWFLASH_IMEI_LEN * ENCODING_LENGTH, &error); 
    mmi_swflash_get_current_storage_file_path((PS8)swflash_content.swflash_dl.zdd_re_dl_path);
    result = FS_XDelete(MMI_SWFLASH_TEMP_VIS_PATH_WCHAR, FS_FILE_TYPE, NULL, 0);
    if (result == FS_DEVICE_BUSY || result == FS_LOCK_MUTEX_FAIL)
    {
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
        return;
    }
#ifdef WAP_SUPPORT
    if (!wap_is_ready())
    {
        DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NETWORK_NOT_READY), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
        return;
    }
#endif
    attr = FS_GetAttributes((U16 *)swflash_content.swflash_dl.zdd_re_dl_path);
    if (attr & FS_ATTR_READ_ONLY)
    {
         g_re_download = MMI_FALSE;
         DisplayPopup((PU8) GetString(STR_ID_SWFLASH_ZDD_READ_ONLY), IMG_GLOBAL_WARNING, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
         return;
    }
    fs_ret = FS_Open((U16 *)swflash_content.swflash_dl.zdd_re_dl_path, FS_READ_ONLY);
    if (fs_ret >= FS_NO_ERROR)
    {
        FS_GetFileSize(fs_ret, &file_size);
        if (file_size > 2048)
        {
             g_re_download = MMI_FALSE;
            FS_Close(fs_ret);
            DisplayPopup((PU8)GetString(STR_ID_SWFLASH_ZDD_FILE_INVALID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            return;
        }

        media_get_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf, 2048);
        MMI_ASSERT(zdd_encrypt_buf != NULL);
        media_get_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf, 2048);
        MMI_ASSERT(zdd_decrypt_buf != NULL);
        
        zdd_decrpt = mmi_swflash_zdd_file_decrypt(imei_key_buf, fs_ret, file_size, zdd_encrypt_buf, zdd_decrypt_buf);
    }
    else
    {
         g_re_download = MMI_FALSE;
        FS_Close(fs_ret);
        DisplayPopup((PU8) GetString(GetFileSystemErrorString(fs_ret)), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
        return;
    }
    
    FS_Close(fs_ret);
    
    if (zdd_decrpt == MMI_TRUE)
    {   

        parse_ret = mmi_swflash_parse_descriptor((S8 *)zdd_decrypt_buf);
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
	    if (parse_ret == MMI_TRUE)
        {
            mmi_swflash_entry_select_storage();
        }
        else
        {	
            g_re_download = MMI_FALSE;
            DisplayPopup((PU8)GetString(STR_ID_SWFLASH_ZDD_FILE_INVALID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, ERROR_TONE);
            return;
        }
    }
    else
    {
        g_re_download = MMI_FALSE;
        if (zdd_encrypt_buf != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_encrypt_buf);
            zdd_encrypt_buf = NULL;
        }
        if (zdd_decrypt_buf != NULL)
        {
            media_free_ext_buffer(MOD_MMI, (void **)&zdd_decrypt_buf);
            zdd_decrypt_buf = NULL;
        }
        DisplayPopup((PU8) GetString(STR_ID_SWFLASH_ZDD_FILE_INVALID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_encrypt_vis_file
 * DESCRIPTION
 *  this function is to encrypt content file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_encrypt_vis_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    FS_HANDLE vis_handle, vis_encrypt_handle;
    U32 file_size;
    MMI_BOOL encrypt_res;
    MMI_BOOL file_exist = MMI_FALSE;
    S32 attr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    file_exist = mmi_swflash_dl_check_file_exist((S8 *)swflash_content.swflash_dl.file_path);
    if (file_exist == MMI_TRUE)
    {
        attr = FS_GetAttributes((U16 *)swflash_content.swflash_dl.file_path);
        if (attr & FS_ATTR_READ_ONLY)
        {
             FS_SetAttributes((U16 *)swflash_content.swflash_dl.file_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
        }        
    }
    vis_handle = FS_Open((U16 *)swflash_content.swflash_dl.temp_file, FS_READ_WRITE);
    vis_encrypt_handle = FS_Open((U16 *)swflash_content.swflash_dl.file_path, FS_CREATE | FS_READ_WRITE);
    FS_GetFileSize(vis_handle, &file_size);
    encrypt_res = mmi_swflash_vis_file_encrypt(imei_key_buf, vis_encrypt_handle, vis_handle, file_size);
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_SWFLASH_DL_VIS_ENCRYPT_RESULT,encrypt_res);
    FS_Close(vis_handle);
    FS_Close(vis_encrypt_handle);
    FS_Delete((U16 *)swflash_content.swflash_dl.temp_file);
    if (encrypt_res == MMI_TRUE)
    {
        FS_Delete((U16 *)swflash_content.swflash_dl.zdd_file_path);
        FS_Delete((U16 *)swflash_content.swflash_dl.zdd_re_dl_path);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_encrypt_zdd_file
 * DESCRIPTION
 *  this function is to encrypt content file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_encrypt_zdd_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    FS_HANDLE source_handle, dest_handle;
    MMI_BOOL encrypt_res = MMI_FALSE;
    MMI_BOOL file_exist = MMI_FALSE;
    S32 attr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    file_exist = mmi_swflash_dl_check_file_exist((S8 *)swflash_content.swflash_dl.zdd_file_path);
    if (file_exist == MMI_TRUE)
    {
        attr = FS_GetAttributes((U16 *)swflash_content.swflash_dl.zdd_file_path);
        if (attr & FS_ATTR_READ_ONLY)
        {
            FS_SetAttributes((U16 *)swflash_content.swflash_dl.zdd_file_path, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
        }        
    }
    source_handle = FS_Open((PU16)swflash_content.swflash_dl.zdd_temp_file_path, FS_READ_ONLY);
    dest_handle = FS_Open((PU16)swflash_content.swflash_dl.zdd_file_path, FS_CREATE | FS_READ_WRITE);
    if (source_handle < 0 || dest_handle < 0)
    {
        DisplayPopup((PU8) GetString(STR_ID_SWFLASH_ZDD_FILE_INVALID), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        FS_Close(source_handle);
        FS_Close(dest_handle);
        return MMI_FALSE;
    }
    FS_GetFileSize(source_handle, &swflash_content.swflash_dl.zdd_file_size);
    encrypt_res = mmi_swflash_zdd_file_encrypt(imei_key_buf, dest_handle, source_handle, swflash_content.swflash_dl.zdd_file_size);
    FS_Close(source_handle);
    FS_Close(dest_handle);
    if (encrypt_res == MMI_FALSE)
    {
        MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_SWFLASH_DL_ZDD_ENCRYPT_FAIL);
        DisplayPopup((PU8) GetString(STR_ID_SWFLASH_ZDD_FILE_SAVE_FAIL), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_check_folder
 * DESCRIPTION
 *  this function is to check default folder exist or not, if not, create them
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_swflash_check_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result = 0;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 6; i++)
    {
        file_handle = FS_Open((U16 *)create_folder_path[i], FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle < 0)
        {
            result = FS_CreateDir((U16 *)create_folder_path[i]);
        }
        else
        {
            FS_Close(file_handle);
        }
        if (result < 0)
        {
            DisplayPopup((PU8) GetString(GetFileSystemErrorString(result)), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) WARNING_TONE);
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_get_destnation_fullname
 * DESCRIPTION
 *  this function is to create destnation file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_get_destnation_fullname(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U8 temp[255];
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.temp_file, (const S8 *)create_folder_path[5]);        
    mmi_ucs2cat((S8 *)swflash_content.swflash_dl.temp_file, (const S8 *)swflash_content.swflash_info.name);
    mmi_ucs2cat((S8 *)swflash_content.swflash_dl.temp_file, (PS8)L".vis");
   
    memset(swflash_content.swflash_dl.file_path, 0, sizeof(swflash_content.swflash_dl.file_path));
    memset(swflash_content.swflash_dl.zdd_file_path, 0, sizeof(swflash_content.swflash_dl.zdd_file_path));
    memset(temp, 0, sizeof(temp));
    mmi_ucs2cpy((S8 *)temp, (const S8 *)swflash_content.swflash_info.name);
    
    if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"vis") == 0)
    {
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)create_folder_path[1]);        
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)temp);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (PS8)L".vis");
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.zdd_file_path, (const S8 *)create_folder_path[1]);        
    }
    else if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"kvis") == 0)
    {
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)create_folder_path[2]);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)temp);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (PS8)L".kvis");
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.zdd_file_path, (const S8 *)create_folder_path[2]);        
    }
    else if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"ivis") == 0)
    {
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)create_folder_path[3]);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)temp);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (PS8)L".ivis");
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.zdd_file_path, (const S8 *)create_folder_path[3]);        
    }
    else if (mmi_ucs2cmp((PS8)swflash_content.swflash_info.type, (PS8)L"msf") == 0)
    {
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)create_folder_path[4]);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)temp);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (PS8)L".mvis");
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.zdd_file_path, (const S8 *)create_folder_path[4]);        
    }
    else
    {
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)create_folder_path[1]);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (const S8 *)temp);
        mmi_ucs2cat((S8 *)swflash_content.swflash_dl.file_path, (PS8)L".vis");
        mmi_ucs2cpy((S8 *)swflash_content.swflash_dl.zdd_file_path, (const S8 *)create_folder_path[1]);        
    }
    mmi_ucs2cat((S8 *)swflash_content.swflash_dl.zdd_file_path, (const S8 *)temp);
    mmi_ucs2cat((S8 *)swflash_content.swflash_dl.zdd_file_path, (PS8)L".zdd");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_send_report
 * DESCRIPTION
 *  send report to server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_send_report(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat((S8 *)swflash_content.swflash_info.content_id, (const S8*)L" 0 2 ");
    mmi_ucs2_to_asc((S8 *)g_content_id, (S8 *)swflash_content.swflash_info.content_id);
    mmi_swflash_send_wps_http_req(MMI_SWFLASH_SEND_REPORT_REQUEST, WPS_HTTP_METHOD_POST, (S8 *)swflash_content.swflash_info.status_report_url, (S8 *)g_content_id, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
*   mmi_swflash_view_confirm_delete_callback
* DESCRIPTION
*
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
static U8 mmi_swflash_view_confirm_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    swflash_content.swflash_dl.is_wap_start = MMI_FALSE;
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*   mmi_swflash_exit_view_confirm
* DESCRIPTION
*
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
void mmi_swflash_exit_view_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_SWFLASH_PLAYBACK;
    currHistory.entryFuncPtr = mmi_swflash_view_confirm;
    GetCategoryHistory(currHistory.guiBuffer);
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    AddHistory(currHistory);

    stopRequestedTone(WARNING_TONE);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_view_confirm
 * DESCRIPTION
 *  this function is to ask user play right now or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_view_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SWFLASH_PLAYBACK);

    EntryNewScreen(SCR_ID_SWFLASH_PLAYBACK, mmi_swflash_exit_view_confirm, NULL, NULL);

    ShowCategory165Screen(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO
        , get_string(STR_ID_SWFLASH_ASK_PLAYBACK), IMG_GLOBAL_QUESTION, guiBuffer);

    playRequestedTone(WARNING_TONE);

    SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_PLAYBACK, (HistoryDelCBPtr)mmi_swflash_view_confirm_delete_callback);

    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
    DeleteScreenIfPresent(SCR_ID_SWFLASH_STORAGE_SELECT);
    DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); /* From file manager */
    DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION); /* From APP */
    DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION); /* From Download agent */
    SetLeftSoftkeyFunction(mmi_swflash_entry_player, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_swflash_start_wap_browser, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
*   mmi_swflash_exit_view_confirm
* DESCRIPTION
*
* PARAMETERS
*   void
* RETURNS
*   void
*****************************************************************************/
void mmi_swflash_exit_replace_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    history currHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currHistory.scrnID = SCR_ID_SWFLASH_REPLACE_VIEW;
    currHistory.entryFuncPtr = mmi_swflash_replace_confirm;
    GetCategoryHistory(currHistory.guiBuffer);
    mmi_ucs2cpy((S8*) currHistory.inputBuffer, (S8*) L"");
    AddHistory(currHistory);

    stopRequestedTone(WARNING_TONE);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_view_confirm
 * DESCRIPTION
 *  this function is to ask user replace the duplicate file or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_replace_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    guiBuffer = GetCurrGuiBuffer(SCR_ID_SWFLASH_REPLACE_VIEW);

    EntryNewScreen(SCR_ID_SWFLASH_REPLACE_VIEW, mmi_swflash_exit_replace_confirm, NULL, NULL);

    ShowCategory165Screen(STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO
        , get_string(STR_ID_SWFLASH_FILE_REPLACE), IMG_GLOBAL_QUESTION, guiBuffer);

    playRequestedTone(WARNING_TONE);
    
    SetLeftSoftkeyFunction(mmi_swflash_start_download, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_start_download
 * DESCRIPTION
 *  this function is to start download
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_start_download(void)
{
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
     MMI_BOOL file_exist = MMI_FALSE;
    S32 attr = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (swflash_content.swflash_dl.channel_id >= 0)
    {
        DisplayPopup((PU8) GetString(STR_ID_SWFLASH_NETWORK_BUSY), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_REPLACE_VIEW);
        return;
    }
    file_exist = mmi_swflash_dl_check_file_exist((S8 *)swflash_content.swflash_dl.file_path);
    if (file_exist == MMI_TRUE)
    {
        attr = FS_GetAttributes((U16 *)swflash_content.swflash_dl.file_path);
        if (attr & FS_ATTR_READ_ONLY)
        {
            DisplayPopup((PU8) GetString(FMGR_FS_ACCESS_DENIED_TEXT), IMG_GLOBAL_ERROR, 1, UI_POPUP_NOTIFYDURATION_TIME, (U8) ERROR_TONE);
            DeleteScreenIfPresent(SCR_ID_SWFLASH_REPLACE_VIEW);
            return;
        }        
    }
    mmi_swflash_show_percentage_bar(0);
    DeleteScreenIfPresent(SCR_ID_SWFLASH_REPLACE_VIEW);
    DeleteScreenIfPresent(SCR_ID_SWFLASH_STORAGE_SELECT);
    swflash_content.swflash_dl.is_dl_run = MMI_TRUE;
    mmi_swflash_wps_set_channel_req();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_start_wap_browser
 * DESCRIPTION
 *  this function is to back to next url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swflash_start_wap_browser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    swflash_content.swflash_info.is_save = MMI_TRUE;
    DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); /* From file manager */
    DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION); /* From APP */
    DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION); /* From Download agent */
    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
    if (mmi_ucs2strlen((S8 *)swflash_content.swflash_info.next_url) != 0)
    {
        if (g_re_download == MMI_FALSE)
        {
        #ifdef WAP_SUPPORT
        wap_start_browser(WAP_BROWSER_GOTO_URL_BACKGROUND, (const kal_uint8*)swflash_content.swflash_info.next_url);
        #endif
            GoBackHistory();
        }
        else
        {
            EntryNewScreen(SCR_ID_SWFLASH_DUMMY_SCREEN, NULL, NULL, NULL);
            DeleteScreenIfPresent(SCR_ID_SWFLASH_PLAYBACK);
            DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        #ifdef WAP_SUPPORT
            wap_start_browser(WAP_BROWSER_GOTO_URL, (const kal_uint8*)swflash_content.swflash_info.next_url);
        #endif
        }
    }
    else
    {
        DeleteScreenIfPresent(SCR_FMGR_FILE_OPTION); /* From file manager */
        DeleteScreenIfPresent(SCR_FMGR_APP_FILE_OPTION); /* From APP */
        DeleteScreenIfPresent(SCR_FMGR_DA_FILE_OPTION); /* From Download agent */
        GoBackHistory();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_entry_player
 * DESCRIPTION
 *  this function is to back to next url
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_swflash_entry_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    if (swflash_content.swflash_info.is_save == MMI_TRUE)
    {
        mmi_swflash_set_file_full_path((S8*)swflash_content.swflash_dl.file_path, NULL);
    }
    else
    {
        mmi_swflash_set_file_full_path((S8*)swflash_content.swflash_dl.temp_file, NULL);
    }
    mmi_swflash_set_next_url(MMI_TRUE);
    mmi_swflash_option_play_entry_screen();
    DeleteScreenIfPresent(SCR_ID_SWFLASH_PLAYBACK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_check_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_swflash_dl_check_file_exist(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open((PU16)filename, FS_READ_ONLY);
    if (fd >= 0)
    {
        FS_Close(fd);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_dl_check_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
extern void mmi_swflash_set_save_file(MMI_BOOL save_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    swflash_content.swflash_info.is_save = save_on;
}
#endif
#endif
