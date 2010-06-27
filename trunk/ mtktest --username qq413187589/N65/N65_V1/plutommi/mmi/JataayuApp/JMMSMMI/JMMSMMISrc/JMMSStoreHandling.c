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
 *  JMMSStoreHandling.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file conains the store APIs for interacting with Jatayu Store module
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
#include "MMI_include.h"
#ifndef _MMI_JMMSSTOREHANDLING_C
#define _MMI_JMMSSTOREHANDLING_C

/***************************************************************************** 
* Include
*****************************************************************************/

#if (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT))

#include "SettingProfile.h"
#include "CommonScreens.h"
#include "wgui_inputs.h"
#include "MainMenuDef.h"

#include <ddl.h>
#include <jcal.h>
#include <ddlbase.h>

#include <MessagingDataTypes.h>
#include <MessagingAPI.h>

#include "JMMSConfig.h"
#include "JMMSMessageSettings.h"
#include "JMMSCoreAPI.h"
#include "JMMSDrafts.h"
#include "JMMSExdcl.h"
#include "JMMSCompose.h"
#include "JMMSGprot.h"
#include "JMMSInbox.h"
#include "JMMSJSRHandler.h"
#include "JMMSMainMMS.h"
#include "JMMSMessageSettingsUtils.h"
#include "JMMSOutbox.h"
#include "JMMSProtocols.h"
#include "JMMSPushHandling.h"
#include "JMMSResDef.h"
#include "JMMSSent.h"
#include "JMMSStoreHandling.h"
#include "JMMSStructs.h"
#include "JMMSTemplates.h"
#include "JMMSUseDetails.h"
#include "JMMSView.h"
#include "JMMSWriteMMS.h"
#include "JMMSTemplates.h"


#include "PrvStoreDataTypes.h"
#include "PrvStoreHandleInterfaces.h"
#include "JSRProts.h"
#include "FileMgr.h"
#include "app_str.h"

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern JC_RETCODE jdd_FSCreateWapMmsSysFoldersExt(
                    JC_BOOLEAN isWAPsysFolder,
                    JC_BOOLEAN isMMSsysFolder,
                    JC_BOOLEAN is_remove_temp_files);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_normal_msgid_value_from_nvram
 * DESCRIPTION
 *  used to get msg id value store in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_normal_msgid_value_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_JMMS_NORMAL_MESSAGE_ID, &g_jmms_context->g_jmms_normal_msgid, DS_DOUBLE, &error);
    if (g_jmms_context->g_jmms_normal_msgid > (0x00FFFFFF)) /* COMPILER WARNING REMOVAL */
    {
        g_jmms_context->g_jmms_normal_msgid = MMI_JMMS_MAX_JAVA_MSG_ID;
        WriteValue(NVRAM_JMMS_NORMAL_MESSAGE_ID, &g_jmms_context->g_jmms_normal_msgid, DS_DOUBLE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_java_msgid_value_from_nvram
 * DESCRIPTION
 *  Used to  get msg ID value stored in NVRAM for JAVA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_java_msgid_value_from_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_JMMS_JAVA_MESSAGE_ID, &g_jmms_context->g_jmms_java_msgid, DS_DOUBLE, &error);
    if ((g_jmms_context->g_jmms_java_msgid + 1) >= (MMI_JMMS_MAX_JAVA_MSG_ID))  /* COMPILER WARNING REMOVAL */
    {
        g_jmms_context->g_jmms_java_msgid = 0;
        WriteValue(NVRAM_JMMS_JAVA_MESSAGE_ID, &g_jmms_context->g_jmms_java_msgid, DS_DOUBLE, &error);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_normal_msgid_value_to_nvram
 * DESCRIPTION
 *  Used to set msg ID value in NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_normal_msgid_value_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_JMMS_NORMAL_MESSAGE_ID, &g_jmms_context->g_jmms_normal_msgid, DS_DOUBLE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_java_msgid_value_to_nvram
 * DESCRIPTION
 *  Used to set msg ID value in NVRAM for JAVA
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_java_msgid_value_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteValue(NVRAM_JMMS_JAVA_MESSAGE_ID, &g_jmms_context->g_jmms_java_msgid, DS_DOUBLE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_folder_list
 * DESCRIPTION
 *  This function is to get the folder list from store
 * PARAMETERS
 *  folder_list_p       [OUT]       - list of folders
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_folder_list(FOLDER_INFO **folder_list_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FOLDER_INFO *folder_list = NULL;
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_jdi_get_folders(g_jmms_context->store_handle, &folder_list);
    if (JC_OK == error_code)
    {
        *folder_list_p = folder_list;
    }
    else
    {
        folder_list_p = NULL;
    }

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_messages_list
 * DESCRIPTION
 *  This function is to get the msg list from a folder
 * PARAMETERS
 *  folder_name_p           [IN]        - name of folder from which messages are to fetch out
 *  msg_list                [OUT]       - list of mesages
 *  retrieve_filters        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_messages_list(S8 *folder_name_p, MESSAGE_LIST **msg_list, RETRIEVE_FILTERS *retrieve_filters)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);
    if (JC_OK != error_code)
    {
        return error_code;
    }

    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, msg_list, retrieve_filters);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, msg_list, retrieve_filters);
            }
        }
    }

    return error_code;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mms_get_number_of_messages
 * DESCRIPTION
 *  This function is to get the total number of messages present in a folder
 * PARAMETERS
 *  folder_name_p           [IN]        - name of folder from which messages are to fetch out(?)(?)
 *  total_num_messages      [OUT]       - list of mesages
 * RETURNS
 *  void
 *****************************************************************************/
JC_RETCODE mmi_mms_get_number_of_messages(S8 *folder_name_p, U8 *total_num_messages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    S8 *folder_name = NULL;
    JC_RETCODE error_code = JC_OK;
    FOLDER_INFO *folder_info = NULL;
    FOLDER_LIST *folder_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *total_num_messages = 0;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_get_number_of_messages: %s", folder_name_p);

    len = (strlen((PS8) folder_name_p) + 1) * ENCODING_LENGTH;
    folder_name = (PS8) jdd_MemAlloc(sizeof(S8), len);
    if (NULL == folder_name)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    mmi_asc_to_ucs2((PS8) folder_name, (PS8) folder_name_p);

    /* manish changing */
    error_code = mmi_jmms_jdi_get_folders(g_jmms_context->store_handle, &folder_info);
    if (JC_OK != error_code)
    {
        goto END;
    }

    folder_list = folder_info->pFolderList;
    while (folder_list != NULL)
    {
        if (mmi_ucs2cmp((S8*) folder_list->pFolderName, (S8*) folder_name) == NULL)
        {
            *total_num_messages = folder_list->uiTotalMessages;
            break;
        }
        folder_list = folder_list->pNext;
    }

  END:

    if (folder_name != NULL)
    {
        jdd_MemFree(folder_name);
        folder_name = NULL;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_get_number_of_messages returns: %d", error_code);
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_total_number_of_messages
 * DESCRIPTION
 *  Used to get total number of messages
 * PARAMETERS
 *  total_num_messages      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_total_number_of_messages(U8 *total_num_messages)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 num_messages = 0;
    S8 *folder_list_p[MMI_JMMS_NO_OF_SYSTEM_FOLDERS] = {MMI_JMMS_INBOX,
        MMI_JMMS_OUTBOX,
        MMI_JMMS_SENT,
        MMI_JMMS_DRAFTS,
        MMI_JMMS_TEMPLATES
    };
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *total_num_messages = 0;

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_get_total_number_of_messages");

    error_code = mmi_mms_get_number_of_messages(MMI_JMMS_TEMPLATES, &num_messages);
    if (error_code == JC_OK)
    {
        *total_num_messages = __MMI_MMS_TEMPLATES_NUM__ - num_messages;
    }

    for (i = 0; i < MMI_JMMS_NO_OF_SYSTEM_FOLDERS; i++)
    {
        num_messages = 0;
        error_code = mmi_mms_get_number_of_messages(folder_list_p[i], &num_messages);
        if (error_code != JC_OK)
        {
            return error_code;
        }
        *total_num_messages += num_messages;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_get_total_number_of_messages returns:%d", error_code);
    return error_code;
}

/* PMT VIKAS START 20060325 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_free_size_for_mms
 * DESCRIPTION
 *  This function is to get the total free space for mms
 * PARAMETERS
 *  disk_free_space_p       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_get_free_size_for_mms(U64 *disk_free_space_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[6];
    FS_HANDLE file_handle;
    FS_DiskInfo disk_info;
    S32 fs_ret_drv = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *disk_free_space_p = 0;

#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
    fs_ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif /* MMS_IN_LARGE_STORAGE */ 
    sprintf(buf, "%c:\\", (U8) fs_ret_drv);
    memset(subMenuData, 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((S8*) subMenuData, (S8*) buf);
    file_handle = FS_Open((kal_uint16*) subMenuData, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle)
    {
        FS_GetDiskInfo((PU16) subMenuData, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        *disk_free_space_p = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
        FS_Close(file_handle);
    }
}

/* PMT VIKAS END 20060325 */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sys_folders_exist
 * DESCRIPTION
 *  This function is check whether MMS Sys folders have been created or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_jmms_sys_folders_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FSHANDLE fs_handle = NULL;
    JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
    JC_INT8 mms_folder_path_ascii[FMGR_MAX_PATH_LEN + 1];
    JC_CHAR mms_folder_path_ucs2[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    JC_CHAR *mms_sys_filepath_ucs2_p = NULL;
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif /* MMS_IN_LARGE_STORAGE */ 
    if (fs_handle == NULL)
    {
        if (jdd_FSInitialize(&fs_handle) != JC_OK)
        {
            return -1;
        }
    }
    jdi_UtilsCharToTchar(&mms_sys_filepath_ucs2_p, JDD_FS_MMS_SYS_FOLDER);
    if (jdd_FSIsDirExist(fs_handle, mms_sys_filepath_ucs2_p) == E_FALSE)
    {
        error_code = -1;
        goto error;
    }
    sprintf(mms_folder_path_ascii, "%c:\\@mms", drive_letter);
    app_asc_str_to_ucs2_str((kal_int8*) mms_folder_path_ucs2, (kal_int8*) mms_folder_path_ascii);
    if (jdd_FSIsDirExist(fs_handle, mms_folder_path_ucs2) == E_FALSE)
    {
        error_code = -1;
        goto error;
    }
  error:
    jdd_MemFree(mms_sys_filepath_ucs2_p);
    if (fs_handle != NULL)
    {
        jdd_FSDeinitialize(fs_handle);
        fs_handle = NULL;
    }
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_init_store
 * DESCRIPTION
 *  This function is to initialize the store.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_init_store(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    JC_CHAR *folder_name_p = NULL;
    U32 len = 0;
    U32 i = 0;
    S8 *folder_list_p[MMI_JMMS_NO_OF_SYSTEM_FOLDERS] = {MMI_JMMS_INBOX,
        MMI_JMMS_OUTBOX,
        MMI_JMMS_SENT,
        MMI_JMMS_DRAFTS,
        MMI_JMMS_TEMPLATES
    };

    JC_UINT32 drive_letter = 0;
    JC_INT8 folder_path[32] = {0, };
    JC_INT8 folder_name[32] = {0, };
    JC_CHAR file_buffer[MAX_FILE_NAME_LENGTH] = {NULL};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init_store");

    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    sprintf(folder_name, "%c:\\@mms", drive_letter);
    mmi_asc_to_ucs2((S8*) folder_path, (S8*) folder_name);
    mmi_asc_to_ucs2((S8*) folder_name, (S8*) "@mms");

    error_code = mmi_jmms_set_folder_attribute((JC_CHAR*) folder_path, 0, FS_ATTR_READ_ONLY, file_buffer);

    error_code = mmi_jmms_jdi_store_init(&g_jmms_context->store_handle);
    if (mmi_jmms_sys_folders_exist() != JC_OK)
    {
        if (error_code == JC_OK)
        {
            error_code = jdd_FSCreateWapMmsSysFoldersExt(E_FALSE, E_TRUE, E_FALSE);
        }
        if (error_code != JC_OK)
        {
            g_jmms_context->init_done = JMMS_NOT_INITIALIZED;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init_store: %d", error_code);
            return;
        }
    }
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();

            if (error_code != JC_OK)
            {
                ASSERT(0);
            }
        }
        else
        {
            ASSERT(0);
        }
    }

    for (i = 0; i < MMI_JMMS_NO_OF_SYSTEM_FOLDERS; i++)
    {
        len = (strlen((S8*) folder_list_p[i]) + 1) * ENCODING_LENGTH;
        folder_name_p = (JC_CHAR*) jdd_MemAlloc(sizeof(S8), len);
        if (NULL == folder_name_p)
        {
            ASSERT(0);
        }
        mmi_asc_to_ucs2((PS8) folder_name_p, (PS8) folder_list_p[i]);
        error_code = mmi_jmms_jdi_create_folder(g_jmms_context->store_handle, (JC_CHAR*) folder_name_p, NULL);
        /* don't free memory on success. It will be used in Store. */
        if (error_code != JC_OK)
        {
            jdd_MemFree(folder_name_p);
            if (error_code != JC_ERR_STORE_FOLDER_ALREADY_EXIST)
            {
                g_jmms_context->init_done = JMMS_NOT_INITIALIZED;
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_init_store at bottom: %d", g_jmms_context->init_done);
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_create_templates_in_store
 * DESCRIPTION
 *  This function is to initialize the templates. Should always be called after Initializing ans syncing store
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_create_templates_in_store(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    U8 num_mms = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_mms_get_number_of_messages(MMI_JMMS_TEMPLATES, &num_mms);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_mms_get_number_of_messages returns error_code = %d, No MMS =%d",
                         error_code, num_mms);
    if (error_code != JC_OK)
    {
        mmi_jmms_update_status_icon_indicator();
        g_jmms_context->init_done = JMMS_TEMPLATES_INITIALIZED; /* we won't be creating templates so let's READY JMMS anyway */
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_create_templates_in_store: %d", g_jmms_context->init_done);
        return;
    }
    if (num_mms < __MMI_MMS_TEMPLATES_NUM__)
    {
        error_code = mmi_jmms_delete_all_message(MMI_JMMS_TEMPLATES);
        ASSERT(!(error_code != JC_OK && num_mms > 0));
        mmi_jmms_create_template_messages();
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_create_templates_in_store returns from second: %d ", num_mms);
    }
    else
    {
        g_jmms_context->init_done = JMMS_TEMPLATES_INITIALIZED;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_create_templates_in_store at bottom: %d",
                             g_jmms_context->init_done);
    }
    mmi_jmms_update_status_icon_indicator();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_de_init_store
 * DESCRIPTION
 *  This function is to deinitialize the store.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_de_init_store(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_jmms_context != NULL)
    {
        error_code = mmi_jmms_jdi_store_dinit(g_jmms_context->store_handle);
        if (error_code == JC_OK)
        {
            g_jmms_context->store_handle = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_folder_attribute
 * DESCRIPTION
 *  This function revert the read only attributes of a given folder.
 * PARAMETERS
 *  folderpath      [IN]
 *  reset_flag      [IN]
 *  attribute       [IN]
 *  filename_buffer [IN]    calling function has to provide the memory for that
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_folder_attribute(
            JC_CHAR *folderpath,
            JC_INT8 set_flag,
            JC_INT32 attribute,
            JC_CHAR *filename_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static JC_UINT8 dir_level_count = 0;
    JC_INT32 fs_handle = 0;
    JC_UINT32 len = 0;
    JC_UINT32 error_code = FS_NO_ERROR;
    JC_CHAR *full_folder_path = NULL;
    JC_CHAR *subfolder_path = NULL;
    JC_CHAR *content_file_path = NULL;
    JC_RETCODE ret_code = JC_OK;
    FS_DOSDirEntry info = {0, };
    JC_INT8 current_dir[] = { '.', '\0', '\0', '\0' };
    JC_INT8 parent_dir[] = { '.', '\0', '.', '\0', '\0', '\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_set_folder_attribute");
    jdd_CheckMemCorruption();
    ASSERT(filename_buffer);

    if (set_flag)
    {
        ret_code = mmi_jmms_set_attribute(folderpath, attribute);
        if (ret_code < 0)
        {
            goto ERROR;
        }
    }
    else
    {
        ret_code = mmi_jmms_reset_attribute(folderpath, attribute);
        if (ret_code < 0)
        {
            goto ERROR;
        }
    }

    len = mmi_ucs2strlen((S8*) folderpath) + 3;
    full_folder_path = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), len);
    mmi_ucs2cpy((S8*) full_folder_path, (S8*) folderpath);
    jc_wstrcat((JC_CHAR*) full_folder_path, L"\\*");

    fs_handle = FS_FindFirst((JC_CHAR*) full_folder_path, 0, 0, &info, (JC_CHAR*) filename_buffer, MAX_FILE_NAME_LENGTH);
    if (full_folder_path)
    {
        jdd_MemFree(full_folder_path);
        full_folder_path = NULL;
    }
    if (fs_handle < 0)
    {
        /* it is OK if the error is FS_NO_MORE_FILES it means the directory is empty */
        if (fs_handle != FS_NO_MORE_FILES)
        {
            ret_code = fs_handle;
        }
        goto ERROR;
    }

    do
    {
        if ((mmi_ucs2cmp((S8*) filename_buffer, (S8*) current_dir) == 0) ||
            (mmi_ucs2cmp((S8*) filename_buffer, (S8*) parent_dir) == 0))
        {
            continue;
        }
        if (info.Attributes & FS_ATTR_DIR)
        {
            if (dir_level_count < 10)
            {
                dir_level_count++;
                ret_code = mmi_jmms_get_file_path(
                            (JC_CHAR*) folderpath,
                            (JC_CHAR*) filename_buffer,
                            (JC_CHAR **) & subfolder_path);
                if (ret_code != JC_OK)
                {
                    goto ERROR;
                }
                ret_code = mmi_jmms_set_folder_attribute(subfolder_path, set_flag, attribute, filename_buffer);
                if (subfolder_path)
                {
                    jdd_MemFree(subfolder_path);
                    subfolder_path = NULL;
                }
                if (ret_code != JC_OK)
                {
                    goto ERROR;
                }
                dir_level_count--;
                continue;
            }
            else
            {
                goto ERROR;
            }
        }

        ret_code = mmi_jmms_get_file_path(
                    (JC_CHAR*) folderpath,
                    (JC_CHAR*) filename_buffer,
                    (JC_CHAR **) & content_file_path);
        if (ret_code != JC_OK)
        {
            goto ERROR;
        }
        if (set_flag)
        {
            ret_code = mmi_jmms_set_attribute(content_file_path, attribute);
            if (ret_code < 0)
            {
                goto ERROR;
            }
        }
        else
        {
            ret_code = mmi_jmms_reset_attribute(content_file_path, attribute);
            if (ret_code < 0)
            {
                goto ERROR;
            }
        }
        if (content_file_path != NULL)
        {
            jdd_MemFree(content_file_path);
            content_file_path = NULL;
        }
    } while ((error_code = FS_FindNext(fs_handle, &info, (kal_wchar*) filename_buffer, MAX_FILE_NAME_LENGTH)) == FS_NO_ERROR);

  ERROR:

    if (subfolder_path)
    {
        jdd_MemFree(subfolder_path);
        subfolder_path = NULL;
    }
    if (content_file_path != NULL)
    {
        jdd_MemFree(content_file_path);
        content_file_path = NULL;
    }
    if (JC_OK != ret_code)
    {
        dir_level_count = 0;
    }
    if (fs_handle > 0)
    {
        FS_FindClose(fs_handle);
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_set_folder_attribute: %d", ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_restore_folder_info
 * DESCRIPTION
 *  Used to restore folder info
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_OK           on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_restore_folder_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    JC_CHAR *folder_name_p = NULL;
    U32 len = 0;
    U32 i = 0;
    S8 *folder_list_p[MMI_JMMS_NO_OF_SYSTEM_FOLDERS] = {MMI_JMMS_INBOX,
        MMI_JMMS_OUTBOX,
        MMI_JMMS_SENT,
        MMI_JMMS_DRAFTS,
        MMI_JMMS_TEMPLATES
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Enter mmi_jmms_restore_folder_info");
    error_code = mmi_jmms_jdi_store_restore(g_jmms_context->store_handle);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s (%d)", "mmi_jmms_jdi_store_restore returns: ", error_code);
    if (error_code != JC_OK)
    {
        ASSERT(0);
    }
    error_code = mmi_jmms_jdi_store_dinit(g_jmms_context->store_handle);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s (%d)", "mmi_jmms_jdi_store_dinit returns: ", error_code);
    if (error_code != JC_OK)
    {
        ASSERT(0);
    }

    g_jmms_context->store_handle = NULL;

    error_code = mmi_jmms_jdi_store_init(&g_jmms_context->store_handle);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s (%d)", "mmi_jmms_jdi_store_init returns: ", error_code);
    if (error_code != JC_OK)
    {
        ASSERT(0);
    }

    for (i = 0; i < MMI_JMMS_NO_OF_SYSTEM_FOLDERS; i++)
    {
        JC_RETCODE ret_code_temp = JC_OK;

        len = (strlen((S8*) folder_list_p[i]) + 1) * ENCODING_LENGTH;
        folder_name_p = (JC_CHAR*) jdd_MemAlloc(sizeof(S8), len);
        if (NULL == folder_name_p)
        {
            ASSERT(0);
        }
        mmi_asc_to_ucs2((PS8) folder_name_p, (PS8) folder_list_p[i]);
        ret_code_temp = mmi_jmms_jdi_create_folder(g_jmms_context->store_handle, (JC_CHAR*) folder_name_p, NULL);
        /* don't free memory on success. It will be used in Store. */
        if (ret_code_temp != JC_OK)
        {
            jdd_MemFree(folder_name_p);
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s (%d)", "mmi_jmms_restore_folder_info returns: ", error_code);
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_message_as_per_id
 * DESCRIPTION
 *  This function is to delete the message from the store.
 * PARAMETERS
 *  msg_id      [IN]        Message Id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_message_as_per_id(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *message_list_p = NULL;
    MESSAGE_LIST *temp_message_list_p = NULL;
    S8 file_name_p[100];
    U32 msg_index = 0;
    JC_RETCODE error_code = JC_OK;

    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(file_name_p, 0, 100);
    mmi_jmms_get_folder_name_from_folderId(JSR_INBOX, file_name_p);

    /* /manish chnging here 0n 2 Feb */
    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

    mmi_jmms_get_messages_list((S8*) file_name_p, &message_list_p, &retrieve_filter);
    temp_message_list_p = message_list_p;

    while (temp_message_list_p)
    {
        msg_index++;
        if ((temp_message_list_p->uiExtraBytes & 0x0FFFFFFF) == msg_id) /* msg_id is stored in the extra bytes of message list. */
        {
            error_code = mmi_jmms_delete_message(file_name_p, msg_index);
            if (error_code == JC_OK)
            {
                mmi_jmms_delete_msg_status((U8) (msg_index - 1));
            }
            break;
        }
        temp_message_list_p = temp_message_list_p->pNext;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_message
 * DESCRIPTION
 *  This function is to delete the message from the store.
 * PARAMETERS
 *  folder_name_p       [IN]        - name of folder from where the message to be deleted(?)(?)
 *  msg_index           [IN]        - index of the message
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_delete_message(S8 *folder_name_p, JC_UINT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *message_list_p = NULL;
    JC_RETCODE error_code = JC_OK;
    RETRIEVE_FILTERS retrieve_filter = {0, };
    U8 number_mms = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);
    if (JC_OK != error_code)
    {
        return error_code;
    }
    retrieve_filter.uiStartIndex = msg_index;
    retrieve_filter.uiNumMessage = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
    if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
    {
        error_code = mmi_jmms_restore_folder_info();
        if (error_code == JC_OK)
        {
            error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
        }
    }

    if (error_code != JC_OK)
    {
        return error_code;
    }

    error_code = mmi_jmms_jdi_delete_msg(g_jmms_context->store_handle, msg_index);
    if (JC_OK != error_code)
    {
        return error_code;
    }

    if ((g_jmms_context->msg_handle != NULL) && (g_jmms_context->is_at_delete_mms == MMI_FALSE))
    {
        error_code = mmi_jmms_jdi_msg_deinit(g_jmms_context->msg_handle);
        if (JC_OK != error_code)
        {
            return error_code;
        }
        g_jmms_context->msg_handle = NULL;
    }

    error_code = mmi_jmms_jdi_update_msg_list(g_jmms_context->store_handle, E_FALSE);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
        }
    }

    if (error_code == JC_OK)
    {
        error_code = mmi_jmms_get_total_number_of_messages(&number_mms);
        if (error_code != JC_OK)
        {
            return error_code;
        }
        if (number_mms < MAX_POSSIBLE_MESSAGES)
        {
            mmi_jmms_remove_memory_full_node_if_present();
        }

    }
    mmi_jmms_update_status_icon_indicator();
    g_jmms_context->is_unread_msg_deleted = 0;

    if (strcmp(folder_name_p, MMI_JMMS_INBOX) == 0)
    {
        if (g_jmms_context->is_unread_msg_deleted == 1)
        {
            mmi_jmms_handle_read_report(g_jmms_context->msg_header_type_p);
        }
    }

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_message_buffer_in_Store
 * DESCRIPTION
 *  Used to save the message in store
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_index_p         [IN]        
 *  msg_headers_p       [IN]        
 *  content_p           [IN]        
 *  extra_bytes_p       [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_save_message_buffer_in_Store(
            S8 *folder_name_p,
            JC_UINT32 *msg_index_p,
            MESSAGE_HEADERS *msg_headers_p,
            CONTENT_DATA *content_p,
            JC_UINT32 *extra_bytes_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_jmms_save_message_buffer_in_Store_ext(
            folder_name_p,
            msg_index_p,
            msg_headers_p,
            content_p,
            extra_bytes_p,
            1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_message_buffer_in_Store_ext
 * DESCRIPTION
 *  Used to save the message in store
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_index_p         [IN]        
 *  msg_headers_p       [IN]        
 *  content_p           [IN]        
 *  extra_bytes_p       [IN]        
 *  show_pop_up         [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_save_message_buffer_in_Store_ext(
            S8 *folder_name_p,
            JC_UINT32 *msg_index_p,
            MESSAGE_HEADERS *msg_headers_p,
            CONTENT_DATA *content_p,
            JC_UINT32 *extra_bytes_p,
            S8 show_pop_up)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    S8 *folder_name = NULL;
    JC_RETCODE error_code = JC_OK;
    U32 msg_id = 0;
    U8 number_mms = 0;
    U8 num_mms_t = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* /check whether Total msgs count have been reached to max limit */
    error_code = mmi_jmms_get_total_number_of_messages(&number_mms);
    if (error_code != JC_OK)
    {
        return error_code;
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Total Messages Before Template=", number_mms);
    /* if the destination folder to save message is Template then total number
       of messages should be minus the number of templates already created */
    if (strcmp(MMI_JMMS_TEMPLATES, folder_name_p) == 0)
    {
        error_code = mmi_mms_get_number_of_messages(MMI_JMMS_TEMPLATES, &num_mms_t);
        if (error_code == JC_OK)
        {
            number_mms -= __MMI_MMS_TEMPLATES_NUM__ - num_mms_t;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "Total Messages After Template = ", number_mms);
    if (number_mms >= MAX_POSSIBLE_MESSAGES)
    {
        if (show_pop_up)
        {
            mmi_jmms_add_memory_full_node_if_not_already();
        }
        else
        {
            mmi_jmms_update_status_icon_indicator();
        }
        return E_MEMORY_FULL_ERROR;
    }

    len = (strlen((PS8) folder_name_p) + 1) * ENCODING_LENGTH;
    folder_name = (PS8) jdd_MemAlloc(sizeof(S8), len);

    if (NULL == folder_name)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    mmi_asc_to_ucs2((PS8) folder_name, (PS8) folder_name_p);

    error_code = mmi_jmms_set_active_folder(folder_name_p);
    if (JC_OK != error_code)
    {
        jdd_MemFree(folder_name);
        return error_code;
    }

    msg_id = mmi_jmms_get_valid_msg_id(folder_name_p);
    ASSERT(msg_id);

    if (extra_bytes_p != NULL)
    {
        *extra_bytes_p &= 0xFF000000;
        *extra_bytes_p = msg_id | *extra_bytes_p;
        *extra_bytes_p = *extra_bytes_p & 0xF0FFFFFF;
        *extra_bytes_p |= mmi_jmms_get_message_folder_type_for_extra_bytes(folder_name_p);

        g_jmms_context->saved_mms_id = (*extra_bytes_p) & 0x0FFFFFFF;

        error_code = mmi_jmms_jdi_save_msg(
                        g_jmms_context->store_handle,
                        (JC_CHAR*) folder_name,
                        0,
                        msg_headers_p,
                        content_p,
                        msg_index_p,
                        *extra_bytes_p);
    }
    else
    {
        msg_id = msg_id & 0xF0FFFFFF;
        msg_id = msg_id | mmi_jmms_get_message_folder_type_for_extra_bytes(folder_name_p);
        error_code = mmi_jmms_jdi_save_msg(
                        g_jmms_context->store_handle,
                        (JC_CHAR*) folder_name,
                        0,
                        msg_headers_p,
                        content_p,
                        msg_index_p,
                        msg_id);
        g_jmms_context->saved_mms_id = msg_id & 0x0FFFFFFF;
    }

    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
        }
    }
    else
    {
        msg_id = msg_id & 0x00FFFFFF;   /* msg_id is 3 byte long rest is other information */
        g_jmms_context->g_jmms_normal_msgid = msg_id;
        mmi_jmms_set_normal_msgid_value_to_nvram();

        // sandeep: update status icon indicator to show memory threshold for all the folders except Inbox 
        // this is to avoid showing memory full icon while saving mms notification in case of immediate download
        if ((number_mms + 1) >= MAX_POSSIBLE_MESSAGES_THRESHOLD)
        {
            if (jc_strcmp(folder_name_p, MMI_JMMS_INBOX) != 0)
            {
                mmi_jmms_update_status_icon_indicator();
            }
        }
    }

    jdd_MemFree(folder_name);
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_message
 * DESCRIPTION
 *  Used to get MMS message for the given index
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  content_p           [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_message(S8 *folder_name_p, CONTENT_DATA *content_p, JC_INT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);

    if (JC_OK != error_code)
    {
        return error_code;
    }
    retrieve_filter.uiStartIndex = msg_index;
    retrieve_filter.uiNumMessage = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);

    if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
    {
        error_code = mmi_jmms_restore_folder_info();
        if (error_code == JC_OK)
        {
            error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
        }
    }

    if (error_code == JC_OK)
    {
        error_code = mmi_jmms_jdi_get_msg(g_jmms_context->store_handle, msg_index, content_p);
    }

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_store_move_message
 * DESCRIPTION
 *  Used to move a message from one folder to another
 * PARAMETERS
 *  src_folder_name_p       [IN]        
 *  dest_folder_name_p      [IN]        
 *  msg_index_p             [IN]        
 * RETURNS
 *  JC_OK                   on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_store_move_message(S8 *src_folder_name_p, S8 *dest_folder_name_p, JC_UINT32 *msg_index_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    S8 *folder_name_p = NULL;
    JC_RETCODE error_code = JC_OK;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };
    JC_UINT32 extra_bytes = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(src_folder_name_p);
    if (JC_OK != error_code)
    {
        return error_code;
    }

    retrieve_filter.uiStartIndex = *msg_index_p;
    retrieve_filter.uiNumMessage = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
                if (error_code != JC_OK)
                {
                    goto END;
                }
            }
            else
            {
                goto END;
            }
        }
        else
        {
            goto END;
        }

    }

    len = (strlen((S8*) dest_folder_name_p) + 1) * ENCODING_LENGTH;
    folder_name_p = (S8*) jdd_MemAlloc(sizeof(S8), len);
    if (NULL == folder_name_p)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    mmi_asc_to_ucs2((S8*) folder_name_p, (PS8) dest_folder_name_p);

    extra_bytes = mmi_jmms_get_message_extra_bytes((S8*) src_folder_name_p, *msg_index_p);
    if (extra_bytes == 0)
    {
        ASSERT(0);
    }
    extra_bytes = extra_bytes & 0xF0FFFFFF; /* clean old folder information */
    extra_bytes |= mmi_jmms_get_message_folder_type_for_extra_bytes(dest_folder_name_p);        /* set new folder information */

    error_code = mmi_jmms_jdi_move_msg(
                    g_jmms_context->store_handle,
                    (JC_UINT32) (*msg_index_p),
                    (JC_CHAR*) folder_name_p,
                    extra_bytes);
    if (JC_OK != error_code)
    {
    #ifdef __USB_IN_NORMAL_MODE__
        if (mmi_jmms_check_usb_mode() == 0)
    #endif 
        {
            ASSERT(0);
        }
    #ifdef __USB_IN_NORMAL_MODE__
        else
    #endif 
        {
            goto END;
        }
    }
    else
    {
        g_jmms_context->saved_mms_id = extra_bytes & 0x0FFFFFFF;
    }

    error_code = mmi_jmms_jdi_update_msg_list(g_jmms_context->store_handle, E_FALSE);
    if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
    {
        error_code = mmi_jmms_restore_folder_info();
    }
  END:

    jdd_MemFree(folder_name_p);
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_store_update_message
 * DESCRIPTION
 *  Used update an already stored message
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_index_p         [IN]        
 *  msg_headers_p       [IN]        
 *  content_p           [IN]        
 *  extra_bytes_p       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_store_update_message(
            S8 *folder_name_p,
            JC_UINT32 *msg_index_p,
            MESSAGE_HEADERS *msg_headers_p,
            CONTENT_DATA *content_p,
            JC_UINT32 extra_bytes_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };
    U32 msg_id = 0;
    MMI_BOOL is_java_message = MMI_FALSE;
    JC_INT8 *content_type = NULL;
    JC_UINT32 new_extraBytes = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);
    if (JC_OK != error_code)
    {
        return error_code;
    }

    retrieve_filter.uiStartIndex = *msg_index_p;
    retrieve_filter.uiNumMessage = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
            }
        }
        if (error_code != JC_OK)
        {
            return error_code;
        }
    }
    if (message_list_p == NULL)
    {
        return -1;
    }
    mmi_jmms_get_content_type(content_p, &content_type);

    if (content_type != NULL)
    {
        is_java_message = mmi_jsr_check_recv_mms_for_java(content_type);
    }

    if (is_java_message == MMI_TRUE)
    {
        mmi_jmms_get_java_msgid_value_from_nvram();
        g_jmms_context->g_jmms_java_msgid++;
        mmi_jmms_set_java_msgid_value_to_nvram();
        msg_id = (U32) g_jmms_context->g_jmms_java_msgid;
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_store_update_message initial msg_id(%X) \n", msg_id);
        msg_id |= (message_list_p->uiExtraBytes & 0x0F000000);
    }
    else
    {
        msg_id = (U32) (message_list_p->uiExtraBytes & 0x0FFFFFFF);
    }
    if (extra_bytes_p != 0)
    {
        new_extraBytes = (extra_bytes_p & 0xF0000000);
    }
    else
    {
        new_extraBytes = (message_list_p->uiExtraBytes & 0xF0000000);
    }

    new_extraBytes |= msg_id;

    error_code = mmi_jmms_jdi_update_msg(g_jmms_context->store_handle, *msg_index_p, msg_headers_p, content_p, new_extraBytes);

    if (error_code == JC_OK)
    {
        if (is_java_message == E_TRUE)
        {
            mmi_jsr_add_recv_java_mms_content(msg_id, content_type);
        }
    }

    if (content_type != NULL)
    {
        jdd_MemFree(content_type);
        content_type = NULL;
    }

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_store_update_message_extrabyte
 * DESCRIPTION
 *  Used to update message extra bytes
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_index           [IN]        
 *  extra_bytes         [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_store_update_message_extrabyte(S8 *folder_name_p, JC_UINT32 msg_index, JC_UINT32 extra_bytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *message_list_p = NULL;
    JC_RETCODE error_code = JC_OK;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);
    if (JC_OK != error_code)
    {
        return error_code;
    }

    retrieve_filter.uiStartIndex = msg_index;
    retrieve_filter.uiNumMessage = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
            }
            else
            {
                return error_code;
            }

        }
        else
        {
            return error_code;
        }
    }

    if (error_code != JC_OK)
    {
        return error_code;
    }
    error_code = mmi_jmms_jdi_update_extrabytes(g_jmms_context->store_handle, msg_index, extra_bytes);
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_message
 * DESCRIPTION
 *  Used to delete all messages froma particular folder.
 * PARAMETERS
 *  folder_name_p       [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_delete_all_message(S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    U8 number_mms = 0;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_delete_all_message: %s", folder_name_p);
    if (JC_OK != error_code)
    {
        return error_code;

    }

    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);

    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
            }
        }
        if (error_code != JC_OK)
        {
            return error_code;
        }
    }

    error_code = mmi_jmms_store_jdi_delete_all_msg(g_jmms_context->store_handle);
    if (JC_OK != error_code)
    {
        return error_code;
    }

    error_code = mmi_jmms_jdi_update_msg_list(g_jmms_context->store_handle, E_FALSE);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code != JC_OK)
            {
                return error_code;
            }
        }
        else if (JC_ERR_FILE_NOT_FOUND == error_code)
        {
            error_code = mmi_mms_get_number_of_messages(folder_name_p, &number_mms);
            if (number_mms || (error_code != JC_OK))
            {
                return error_code;
            }
        }
    }

    if (error_code == JC_OK)
    {
        error_code = mmi_jmms_get_total_number_of_messages(&number_mms);
        if (error_code != JC_OK)
        {
            return error_code;
        }

        if (number_mms < MAX_POSSIBLE_MESSAGES)
        {
            mmi_jmms_remove_memory_full_node_if_present();
        }
        /* PMT VIKAS START 20060405 */
        mmi_jmms_update_status_icon_indicator();
        /* PMT VIKAS END 20060405 */
    }

    return error_code;
}

/* Vishal Start */
#if (defined (__MMI_MMS_DELETE_ALL_DELIVERY_REPORT__) || defined(__MMI_MMS_DELETE_ALL_READ_REPORT__))


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_message_by_type
 * DESCRIPTION
 *  this api deletes all the messages of a given type
 * PARAMETERS
 *  folder_name_p     
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_delete_all_message_by_type(S8 *folder_name_p, EMsgType msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    U8 number_mms = 0;

    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS store_ret_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_code = mmi_jmms_set_active_folder(folder_name_p);
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_delete_delivery_all_message: %s", folder_name_p);
    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error in setting active folder: %s", folder_name_p);
        return ret_code;

    }

    store_ret_filter.uiStartIndex = 1;
    store_ret_filter.uiNumMessage = 0;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    ret_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &store_ret_filter);

    if (JC_OK != ret_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == ret_code)
        {
            ret_code = mmi_jmms_restore_folder_info();
            if (ret_code == JC_OK)
            {
                ret_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &store_ret_filter);
            }
        }
        if (ret_code != JC_OK)
        {
            return ret_code;
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error in getting message list from folder : %s", folder_name_p);
        }
    }

    ret_code = jdi_StoreDeleteAllMsgsByType(g_jmms_context->store_handle, msg_type);

    if (JC_OK != ret_code)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error in deleting message from folder : %s", folder_name_p);
        return ret_code;
    }

    ret_code = mmi_jmms_jdi_update_msg_list(g_jmms_context->store_handle, E_FALSE);
    if (JC_OK != ret_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == ret_code)
        {
            ret_code = mmi_jmms_restore_folder_info();
            if (ret_code != JC_OK)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error in restoring folder information of folder : %s",
                                     folder_name_p);
                return ret_code;
            }
        }
    }

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_get_total_number_of_messages(&number_mms);
        if (ret_code != JC_OK)
        {
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "Error in getting total number of messages from folder : %s",
                                 folder_name_p);
            return ret_code;
        }

        if (number_mms < MAX_POSSIBLE_MESSAGES)
        {
            mmi_jmms_remove_memory_full_node_if_present();
        }
        mmi_jmms_update_status_icon_indicator();
    }
    return ret_code;
}
#endif /* (defined (__MMI_MMS_DELETE_ALL_DELIVERY_REPORT__) || defined(__MMI_MMS_DELETE_ALL_READ_REPORT__)) */ 
/* Vishal end */


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_message_id
 * DESCRIPTION
 *  Used to get message ID from its index and folder name
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  message id of the requested message
 *****************************************************************************/
JC_UINT32 mmi_jmms_get_message_id(S8 *folder_name_p, JC_UINT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    JC_UINT32 msg_id = 0;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);

    if (JC_OK != error_code)
    {
        return 0;
    }

    retrieve_filter.uiStartIndex = msg_index;
    retrieve_filter.uiNumMessage = 1;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &retrieve_filter);
            }
        }
        if (error_code != JC_OK)
        {
            return 0;
        }
    }
    msg_id = message_list_p->uiExtraBytes & 0x0FFFFFFF;
    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_free_messages_list
 * DESCRIPTION
 *  Used to free message list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_free_messages_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    STORAGE_CTX *storage_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage_handle = (STORAGE_CTX*) (g_jmms_context->store_handle);

    if (storage_handle->pMessageList != NULL)
    {
        StoreFreeMessageList(storage_handle->pMessageList);
        storage_handle->pMessageList = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_number_of_unread_messages_in_inbox
 * DESCRIPTION
 *  Used to the number of unread messages from the inbox
 * PARAMETERS
 *  total_num_unread_messages_p     [OUT]       
 * RETURNS
 *  JC_OK                           on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_number_of_unread_messages_in_inbox(U8 *total_num_unread_messages_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    U8 num_messages = 0;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *total_num_unread_messages_p = 0;
    error_code = mmi_mms_get_number_of_messages(MMI_JMMS_INBOX, &num_messages);
    if (error_code != JC_OK)
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_get_number_of_unread_messages_in_inbox returns = ",
                             error_code);
        return error_code;
    }

    for (i = 0; i < num_messages; i++)
    {
        U8 msg_index = 0;

        msg_index = num_messages - i;
        msg_index = msg_index - 1;
        if (mmi_jmms_is_msg_read(msg_index) == MMI_FALSE)
        {
            *total_num_unread_messages_p = *total_num_unread_messages_p + 1;
        }
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "unread_messages_in_inbox = ", *total_num_unread_messages_p);
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_active_folder
 * DESCRIPTION
 *  Used to set a folder as active folder
 * PARAMETERS
 *  folder_name_p       [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_active_folder(S8 *folder_name_p)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    JC_CHAR *folder_name = NULL;
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen((PS8) folder_name_p);
    folder_name = (JC_CHAR*) jdd_MemAlloc(sizeof(JC_CHAR), len + 1);

    if (NULL == folder_name)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    mmi_asc_to_ucs2((PS8) folder_name, (PS8) folder_name_p);
    error_code = mmi_jmms_jdi_set_active_folder(g_jmms_context->store_handle, (JC_CHAR*) folder_name);
    jdd_MemFree(folder_name);

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_progresing_screen
 * DESCRIPTION
 *  Used to delete progress screen
 * PARAMETERS
 *  title_str_id        [IN]        
 *  image_id            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_progresing_screen(U16 title_str_id, U16 image_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_JMMS_DELETING_PROGRESS, NULL, NULL, NULL);

    ShowCategory8Screen(
        title_str_id,
        GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID),
        0,
        0,
        0,
        0,
        STR_ID_JMMS_DELETING_MMS,
        image_id,
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_recreate_sys_folders
 * DESCRIPTION
 *  Used to recreate mms_sys folder
 * PARAMETERS
 *  void
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_recreate_sys_folders(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FSHANDLE fs_handle = NULL;
    JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
    JC_CHAR *mms_sys_filepath_ucs2_p = NULL;
    JC_RETCODE error_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif /* MMS_IN_LARGE_STORAGE */ 
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "Enters mmi_jmms_recreate_sys_folders");
    if (fs_handle == NULL)
    {
        if (jdd_FSInitialize(&fs_handle) != JC_OK)
        {
            return -1;
        }
    }
    jdi_UtilsCharToTchar(&mms_sys_filepath_ucs2_p, JDD_FS_MMS_SYS_FOLDER);
    if (jdd_FSIsDirExist(fs_handle, mms_sys_filepath_ucs2_p) == E_TRUE)
    {
        error_code = jdd_FSDelDir(fs_handle, mms_sys_filepath_ucs2_p);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_delete_sys_folders: %d", error_code);
        error_code = jdd_FSMakeDir(fs_handle, mms_sys_filepath_ucs2_p);
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_create_sys_folders: %d", error_code);
    }
    jdd_MemFree(mms_sys_filepath_ucs2_p);
    if (fs_handle != NULL)
    {
        jdd_FSDeinitialize(fs_handle);
        fs_handle = NULL;
    }
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_message_folder_type_from_id
 * DESCRIPTION
 *  Used to get folder type from folder ID.
 * PARAMETERS
 *  msgid       [IN]        
 * RETURNS
 *  folder type
 *****************************************************************************/
JC_UINT32 mmi_jmms_get_message_folder_type_from_id(JC_UINT32 msgid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == msgid)
    {
        return NULL;
    }
    /* return the value in the 3rd byte. It contains folder type */
    msgid = msgid & 0x0F000000;
    msgid = (msgid >> 24);
    return msgid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_message_folder_type_for_extra_bytes
 * DESCRIPTION
 *  Used to get folder type from folder name to be embedded for extra bytes.
 * PARAMETERS
 *  folder_name_p       [IN]        
 * RETURNS
 *  folder type tobe embedded for extra bytes
 *****************************************************************************/
JC_UINT32 mmi_jmms_get_message_folder_type_for_extra_bytes(S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_UINT32 folder_type = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == folder_name_p)
    {
        return NULL;
    }

    if (strcmp(folder_name_p, MMI_JMMS_INBOX) == 0)
    {
        folder_type = 0x01000000;
    }
    else if (strcmp(folder_name_p, MMI_JMMS_OUTBOX) == 0)
    {
        folder_type = 0x02000000;
    }
    else if (strcmp(folder_name_p, MMI_JMMS_SENT) == 0)
    {
        folder_type = 0x03000000;
    }
    else if (strcmp(folder_name_p, MMI_JMMS_DRAFTS) == 0)
    {
        folder_type = 0x04000000;
    }
    else if (strcmp(folder_name_p, MMI_JMMS_TEMPLATES) == 0)
    {
        folder_type = 0x05000000;
    }

    return folder_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_message_index
 * DESCRIPTION
 *  Used to get message index from message ID
 * PARAMETERS
 *  store_handle        [IN]        
 *  msgid               [IN]        
 *  msg_index_p         [IN]        
 * RETURNS
 *  JC_OK           on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_message_index(STORE_HANDLE store_handle, JC_UINT32 msgid, JC_UINT32 *msg_index_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_LIST *temp_message_list_p = NULL;
    JC_RETCODE error_code = JC_OK;
    JC_INT8 folder_type = NULL;
    JC_INT8 *message_info_p = NULL;
    RETRIEVE_FILTERS retrieve_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == msgid)
    {
        return JC_ERR_INVALID_PARAMETER;
    }

    message_info_p = (JC_INT8*)&msgid;

    /* copy fourth byte to get the folder type */
    jc_memcpy(&folder_type, (void*)(message_info_p + 3), sizeof(JC_INT8));
    if (NULL == folder_type)
    {
        return JC_ERR_INVALID_PARAMETER;
    }

    folder_type = folder_type & 0x0F;
    retrieve_filter.uiStartIndex = 1;
    retrieve_filter.uiNumMessage = 0;
    retrieve_filter.eRetrieve = E_RETRIEVE_BY_INDEX;

    switch (folder_type)
    {
        case MMS_INBOX_FOLDER:
            error_code = mmi_jmms_set_active_folder((S8*) MMI_JMMS_INBOX);
            break;
        case MMS_OUTBOX_FOLDER:
            error_code = mmi_jmms_set_active_folder((S8*) MMI_JMMS_OUTBOX);
            break;
        case MMS_SENT_FOLDER:
            error_code = mmi_jmms_set_active_folder((S8*) MMI_JMMS_SENT);
            break;
        case MMS_DRAFTS_FOLDER:
            error_code = mmi_jmms_set_active_folder((S8*) MMI_JMMS_DRAFTS);
            break;
        case MMS_TEMPLATES_FOLDER:
            error_code = mmi_jmms_set_active_folder((S8*) MMI_JMMS_TEMPLATES);
            break;
        default:
            error_code = JC_ERR_INVALID_PARAMETER;
            break;
    }
    if (error_code == JC_OK)
    {
        error_code = mmi_jmms_jdi_get_msg_list(store_handle, &temp_message_list_p, &retrieve_filter);
        if (JC_OK == error_code)
        {
            while (temp_message_list_p)
            {
                ++(*msg_index_p);
                if (msgid == (temp_message_list_p->uiExtraBytes & 0x0FFFFFFF))
                {
                    break;
                }
                temp_message_list_p = temp_message_list_p->pNext;
            }
            /* It means message was not found */
            if (NULL == temp_message_list_p)
            {
                error_code = JC_ERR_FILE_EXIST;
            }
        }
    }
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_message_extra_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  Message extra bytes
 *****************************************************************************/
JC_UINT32 mmi_jmms_get_message_extra_bytes(S8 *folder_name_p, JC_UINT32 msg_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE error_code = JC_OK;
    MESSAGE_LIST *message_list_p = NULL;
    RETRIEVE_FILTERS store_ret_filter = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    error_code = mmi_jmms_set_active_folder(folder_name_p);

    if (JC_OK != error_code)
    {
        return 0;
    }

    store_ret_filter.uiStartIndex = msg_index;
    store_ret_filter.uiNumMessage = 1;
    store_ret_filter.eRetrieve = E_RETRIEVE_BY_INDEX;
    error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &store_ret_filter);
    if (JC_OK != error_code)
    {
        if (JC_ERR_STORE_FILE_CORRUPTED == error_code)
        {
            error_code = mmi_jmms_restore_folder_info();
            if (error_code == JC_OK)
            {
                error_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &message_list_p, &store_ret_filter);
            }
        }
        if (error_code != JC_OK)
        {
            return 0;
        }
    }
    return message_list_p->uiExtraBytes;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_valid_msg_id
 * DESCRIPTION
 *  Used to get unique message ID
 * PARAMETERS
 *  folder_name_p       [IN]        
 * RETURNS
 *  Unique message ID
 *****************************************************************************/
JC_UINT32 mmi_jmms_get_valid_msg_id(S8 *folder_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_UINT32 msg_id = 0;
    JC_UINT32 msg_index = 0;
    JC_UINT32 folder_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_jmms_get_normal_msgid_value_from_nvram();
    msg_id = (U32) (g_jmms_context->g_jmms_normal_msgid) + 1;
    if (msg_id >= MMI_JMMS_MAX_NORMAL_MSG_ID)
    {
        msg_id = MMI_JMMS_MAX_JAVA_MSG_ID + 1;
    }

    folder_type = mmi_jmms_get_message_folder_type_for_extra_bytes(folder_name_p);

    /* check if the message id is unique */
    while (mmi_jmms_get_message_index(
            g_jmms_context->store_handle,
            msg_id | folder_type,
            &msg_index) != JC_ERR_FILE_EXIST)
    {
        if (msg_id >= 0x00FFFFFF)
        {
            msg_id = MMI_JMMS_MAX_JAVA_MSG_ID + 1;
            continue;
        }
        msg_id++;
    }
    return msg_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_file_path
 * DESCRIPTION
 *  Used to get file path
 * PARAMETERS
 *  folder_name_p     [IN]
  * RETURNS
 *  Unique message ID
 *****************************************************************************/
JC_RETCODE mmi_jmms_get_file_path(JC_CHAR *folderpath, JC_CHAR *filename, JC_CHAR **absolute_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE eRet = JC_OK;
    JC_UINT32 stringlen = 0;
    JC_UINT32 folderlen = jc_tcslen(folderpath);
    JC_CHAR folder_backslash = *(folderpath + folderlen - 1);
    JC_CHAR file_backslash = *filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folderpath == NULL || filename == NULL || absolute_filepath == NULL)
    {
        return JC_ERR_INVALID_PARAMETER;
    }

    stringlen = (jc_tcslen(folderpath) * 2) + (jc_tcslen(filename) * 2) + ENCODING_LENGTH;

    if (file_backslash != '\\' && folder_backslash != '\\')
    {
        stringlen += 2;
    }

    *absolute_filepath = (JC_CHAR*) jdd_MemAlloc(1, stringlen + 2);
    if (NULL == *absolute_filepath)
    {
        return JC_ERR_MEMORY_ALLOCATION;
    }

    jc_tcscpy(*absolute_filepath, folderpath);
    if (file_backslash != '\\' && folder_backslash != '\\')
    {
        jc_tcscat(*absolute_filepath, (JC_CHAR*) "\\");
    }
    else if (file_backslash == '\\' && folder_backslash == '\\')
    {
        filename += 1;
    }
    jc_tcscat(*absolute_filepath, filename);
    return eRet;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_reset_attribute
 * DESCRIPTION
 *  Used to reset file/directory attributes
 * PARAMETERS
 *  folderpath      [IN]        
 *  attribute       [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_reset_attribute(JC_CHAR *folderpath, JC_INT32 attribute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT32 temp_attribute = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_attribute = FS_GetAttributes((JC_CHAR*) folderpath);
    if (temp_attribute < 0)
    {
        ret_code = temp_attribute;
        goto ERROR;
    }

    temp_attribute &= (~attribute);
    FS_SetAttributes(folderpath, (kal_uint8) temp_attribute);

  ERROR:
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_attribute
 * DESCRIPTION
 *  Used to set file/directory attributes
 * PARAMETERS
 *  folderpath      [IN]        
 *  attribute       [IN]        
 * RETURNS
 *  JC_RETCODE
 *****************************************************************************/
JC_RETCODE mmi_jmms_set_attribute(JC_CHAR *folderpath, JC_INT32 attribute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT32 temp_attribute = 0;
    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_attribute = FS_GetAttributes((JC_CHAR*) folderpath);
    if (temp_attribute < 0)
    {
        ret_code = temp_attribute;
        goto ERROR;
    }

    temp_attribute |= attribute;
    FS_SetAttributes(folderpath, (kal_uint8) temp_attribute);
  ERROR:
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_sd_plug_out_hdlr
 * DESCRIPTION
 *  Handles SD card plug-out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_sd_plug_out_hdlr");
    if (mmi_jmms_is_call_active())
    {
        return;
    }
    mmi_jmms_delete_mms_screens();
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_read_callback
 * DESCRIPTION
 *  Read Callback to read the MMS file.
 * PARAMETERS
 *  stream_p        [IN]        
 *  offset          [IN]        
 *  size            [IN]        
 *  buffer_p        [IN]        
 *  size_read_p     [IN]        
 * RETURNS
 *  JC_OK               on sucess
 *****************************************************************************/
JC_RETCODE mmi_jmms_read_callback(
            void *stream_p,
            JC_INT32 offset,
            JC_UINT32 size,
            JC_UINT8 *buffer_p,
            JC_UINT32 *size_read_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JDD_FILE file_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Read Callback");

    if (stream_p == NULL || buffer_p == NULL)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto error;
    }

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_OPEN;
            goto error;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) stream_p, E_OPEN_READ_MODE);
    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto error;
    }
    if (offset > 0)
    {
        ret_code = jdd_FSSeek(file_handle, offset, E_FILE_SEEK_SET);
        if (ret_code != JC_OK)
        {
            goto error;
        }
    }
    *size_read_p = jdd_FSRead(buffer_p, sizeof(JC_INT8), size, file_handle);
    if (*size_read_p != size)
    {
        ret_code = JC_ERR_FILE_READ;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "File Name: %s, bytes read = %d", stream_p, *size_read_p);

  error:
    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_write_callback
 * DESCRIPTION
 *  Write callback to write in the MMS file
 * PARAMETERS
 *  stream_p        [IN]        
 *  buffer_p        [IN]        
 *  size            [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
JC_RETCODE mmi_jmms_write_callback(void *stream_p, JC_UINT8 *buffer_p, JC_UINT32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_RETCODE ret_code = JC_OK;
    JC_INT32 bytes_written = 0;
    JDD_FILE file_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS Write Callback");

    if (stream_p == NULL || buffer_p == NULL)
    {
        ret_code = JC_ERR_NULL_POINTER;
        goto error;
    }
    if (size == 0)
    {
        ret_code = JC_ERR_INVALID_PARAMETER;
        goto error;
    }

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_OPEN;
            goto error;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) stream_p, E_CREATE_APPEND_WRITE_MODE);
    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto error;
    }

    bytes_written = jdd_FSWrite(buffer_p, 1, size, file_handle);
    if (bytes_written != size)
    {
        ret_code = JC_ERR_FILE_WRITE;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "File Name: %s, bytes written = %d", stream_p, bytes_written);

  error:
    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "JMMS Write Callback return: %d", ret_code);

    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_mms
 * DESCRIPTION
 *  Used to save MMS
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_handle          [IN]        
 *  is_store_update     [IN]        
 *  msg_index           [IN]        
 *  err_cb              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
JC_RETCODE mmi_jmms_save_mms(
            S8 *folder_name_p,
            MSG_HANDLE msg_handle,
            MMI_BOOL is_store_update,
            JC_UINT32 msg_index,
            error_callback err_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_RETCODE ret_code = JC_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_save_mms");

    if (g_jmms_context->save_content_p != NULL)
    {
        jdd_MemFree(g_jmms_context->save_content_p);
    }

    g_jmms_context->save_content_p = (CONTENT_DATA*) jdd_MemAlloc(sizeof(CONTENT_DATA), 1);

    if (g_jmms_context->async_save_context.params != NULL)
    {
        jdd_MemFree(g_jmms_context->async_save_context.params);
    }

    g_jmms_context->async_save_context.params =
        (mmi_jmms_async_save_params_struct*) jdd_MemAlloc(sizeof(mmi_jmms_async_save_params_struct), 1);

    memcpy(g_jmms_context->async_save_context.params->folder_name_p, folder_name_p, strlen(folder_name_p) + 1);
    g_jmms_context->async_save_context.params->is_store_update = is_store_update;
    g_jmms_context->async_save_context.params->msg_index = msg_index;
    g_jmms_context->async_save_context.params->msg_handle = msg_handle;

    g_jmms_context->save_content_p->bIsStream = E_TRUE;
    g_jmms_context->save_content_p->cbWriteCallback = mmi_jmms_write_callback;
    jdi_UtilsCharToTchar((JC_CHAR **) & (g_jmms_context->save_content_p->pStream), "@mms\\temp\\jmms_tempEncFile.bin");
    g_jmms_context->save_content_p->pFileName = g_jmms_context->save_content_p->pStream;

    ret_code = mmi_jmms_jdi_encapsulate_buffer(msg_handle, g_jmms_context->save_content_p);

    mmi_jmms_add_save_callback_node(err_cb);
    mmi_jmms_add_save_callback_node(mmi_jmms_save_mms_async_callback);

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "JMMS ENCODING START");
    if (ret_code == JC_ERR_MMS_ENCODE_PENDING)
    {
        mmi_jmms_save_continue_start_timer(msg_handle);
        return ret_code;
    }
    mmi_jmms_decrement_save_callback_node(ret_code);
    return ret_code;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_save_mms_async_callback
 * DESCRIPTION
 *  Used for async saving of MMS
 * PARAMETERS
 *  ret_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_save_mms_async_callback(JC_RETCODE ret_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MESSAGE_HEADERS *msg_headers_p = NULL;
    mmi_jmms_async_save_params_struct save_params;

    // CONTENT_DATA content = {0, }; // COMPILER WARNING  REMOVAL
    //sandeep starts
    RETRIEVE_FILTERS StoreRetFilter = {0, };
    MESSAGE_LIST *pMessageList = NULL;

    /* sandeep ends */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_save_mms_async_callback with Ret Code: ", ret_code);
    memcpy(&save_params, (g_jmms_context->async_save_context.params), sizeof(mmi_jmms_async_save_params_struct));

    if (JC_OK != ret_code || g_jmms_context->async_save_context.params == NULL)
    {
        goto ERROR_HANDLE;
    }

    g_jmms_context->save_content_p->cbWriteCallback = NULL;
    g_jmms_context->save_content_p->cbReadCallback = mmi_jmms_read_callback;

    ret_code = mmi_jmms_jdi_get_msg_headers(save_params.msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        goto ERROR_HANDLE;
    }

    if (save_params.is_store_update == MMI_FALSE)
    {
        {
            JC_UINT32 temp_extrabyte1 = 0x10000000, temp_extrabyte2 = 0x20000000;

            if (g_jmms_context->num_attachments > 0)
            {
                ret_code = mmi_jmms_save_message_buffer_in_Store(
                            save_params.folder_name_p,
                            &(save_params.msg_index),
                            msg_headers_p,
                            g_jmms_context->save_content_p,
                            &temp_extrabyte1);
            }
            else
            {
                ret_code = mmi_jmms_save_message_buffer_in_Store(
                            save_params.folder_name_p,
                            &(save_params.msg_index),
                            msg_headers_p,
                            g_jmms_context->save_content_p,
                            &temp_extrabyte2);
            }
        }
    }
    else
    {
        if (g_jmms_context->num_attachments > 0)
        {
            ret_code = mmi_jmms_store_update_message(
                        save_params.folder_name_p,
                        &(save_params.msg_index),
                        msg_headers_p,
                        g_jmms_context->save_content_p,
                        0x10000000);
        }
        else
        {
            ret_code = mmi_jmms_store_update_message(
                        save_params.folder_name_p,
                        &(save_params.msg_index),
                        msg_headers_p,
                        g_jmms_context->save_content_p,
                        0x20000000);
        }
    }

    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }

    //sandeep starts
    //ret_code = mmi_jmms_get_message(save_params.folder_name_p, &content, save_params.msg_index);
    StoreRetFilter.uiStartIndex = 1;
    StoreRetFilter.eRetrieve = E_RETRIEVE_BY_INDEX;
    StoreRetFilter.uiNumMessage = 0;

    ret_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &pMessageList, &StoreRetFilter);
    /* sandeep ends */

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_store_update_extra_byte_1(
                    g_jmms_context->store_handle,
                    save_params.msg_index,
                    get_current_utc_time());
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "JMMS Store Save API returned with Ret Code: ", ret_code);

  ERROR_HANDLE:

    if (g_jmms_context->save_content_p != NULL)
    {

        if (g_jmms_context->save_content_p->bIsStream == E_FALSE)
        {
            jdd_MemFree(g_jmms_context->save_content_p->pBuffer);
            g_jmms_context->save_content_p->pBuffer = NULL;
        }
        if (g_jmms_context->save_content_p->pStream != NULL)
        {
            if (g_jmms_context->jmms_fs_handle == NULL)
            {
                if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
                {
                    jdd_MemFree(g_jmms_context->async_save_context.params);
                    g_jmms_context->async_save_context.params = NULL;
                    mmi_jmms_decrement_save_callback_node(JC_ERR_FILE_SYS_INIT);
                    return;
                }
            }

            jdd_FSDelete(g_jmms_context->jmms_fs_handle, g_jmms_context->save_content_p->pStream);
            if (g_jmms_context->jmms_fs_handle != NULL)
            {
                jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
                g_jmms_context->jmms_fs_handle = NULL;
            }
            jdd_MemFree(g_jmms_context->save_content_p->pStream);
        }
        jdd_MemFree(g_jmms_context->save_content_p);
        g_jmms_context->save_content_p = NULL;
    }

    jdd_MemFree(g_jmms_context->async_save_context.params);
    g_jmms_context->async_save_context.params = NULL;
    mmi_jmms_decrement_save_callback_node(ret_code);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_send_and_store_mms
 * DESCRIPTION
 *  Used to send and save MMS
 * PARAMETERS
 *  folder_name_p       [IN]        
 *  msg_handle          [IN]        
 *  comm_node_p         [IN]        
 * RETURNS
 *  JC_OK               on success
 *****************************************************************************/
/* It is called in case of send and save, PDU is already in file. */
JC_RETCODE mmi_jmms_send_and_store_mms(
            S8 *folder_name_p,
            MSG_HANDLE msg_handle,
            mmi_jmms_communication_state_node_struct *comm_node_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    JC_UINT32 msg_index = 0;
    CONTENT_DATA encapsulated_content = {0, };
    MESSAGE_HEADERS *msg_headers_p = NULL;
    JC_RETCODE ret_code = JC_OK;
    JC_UINT32 file_length = 0;
    JDD_FILE file_handle = NULL;

    /* sandeep starts */
    RETRIEVE_FILTERS StoreRetFilter = {0, };
    MESSAGE_LIST *pMessageList = NULL;

    /* sandeep ends */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_send_and_store_mms");

    encapsulated_content.bIsStream = E_TRUE;

    encapsulated_content.cbWriteCallback = NULL;
    encapsulated_content.cbReadCallback = mmi_jmms_read_callback;
    encapsulated_content.pStream = comm_node_p->send_file_name_p;
    encapsulated_content.pFileName = comm_node_p->send_file_name_p;

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            ret_code = JC_ERR_FILE_OPEN;
            goto ERROR_HANDLE;
        }
    }

    file_handle = jdd_FSOpen(g_jmms_context->jmms_fs_handle, (JC_CHAR*) encapsulated_content.pStream, E_OPEN_READ_MODE);
    if (file_handle == NULL)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto ERROR_HANDLE;
    }

    ret_code = jdd_FSGetSize(file_handle, &file_length);
    if (JC_OK != ret_code)
    {
        ret_code = JC_ERR_FILE_OPEN;
        goto ERROR_HANDLE;
    }

    encapsulated_content.uiTotalSize = file_length;

    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
        file_handle = NULL;
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    ret_code = mmi_jmms_jdi_get_msg_headers(msg_handle, &msg_headers_p);
    if (ret_code != JC_OK || msg_headers_p == NULL)
    {
        goto ERROR_HANDLE;
    }
    {
        JC_UINT32 temp_extrabyte1 = 0x10000000, temp_extrabyte2 = 0x20000000;

        if (g_jmms_context->num_attachments > 0)
        {
            ret_code = mmi_jmms_save_message_buffer_in_Store(
                        folder_name_p,
                        &msg_index,
                        msg_headers_p,
                        &encapsulated_content,
                        &temp_extrabyte1);
        }
        else
        {
            ret_code = mmi_jmms_save_message_buffer_in_Store(
                        folder_name_p,
                        &msg_index,
                        msg_headers_p,
                        &encapsulated_content,
                        &temp_extrabyte2);
        }
    }
    if (ret_code != JC_OK)
    {
        goto ERROR_HANDLE;
    }

#ifndef __MMI_UNIFIED_MESSAGE__
    if ((strcmp(folder_name_p, MMI_JMMS_OUTBOX) == 0) && IsScreenPresent(SCR_ID_JMMS_OUTBOX))
    {
        g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
    }
    else if ((strcmp(folder_name_p, MMI_JMMS_SENT) == 0) && IsScreenPresent(SCR_ID_JMMS_SENT))
    {
        g_jmms_context->store_context->update_nmsgs_in_current_folder = 1;
    }
#endif /* __MMI_UNIFIED_MESSAGE__ */ 
    //sandeep starts
    //ret_code = mmi_jmms_get_message(save_params.folder_name_p, &content, save_params.msg_index);
    StoreRetFilter.uiStartIndex = 1;
    StoreRetFilter.eRetrieve = E_RETRIEVE_BY_INDEX;
    StoreRetFilter.uiNumMessage = 0;

    ret_code = mmi_jmms_jdi_get_msg_list(g_jmms_context->store_handle, &pMessageList, &StoreRetFilter);
    /* sandeep ends */

    if (ret_code == JC_OK)
    {
        ret_code = mmi_jmms_jdi_store_update_extra_byte_1(g_jmms_context->store_handle, msg_index, get_current_utc_time());
    }

  ERROR_HANDLE:

    if (file_handle != NULL)
    {
        jdd_FSClose(file_handle);
        file_handle = NULL;
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }

    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s%d", "mmi_jmms_send_and_store_mms returns: ", ret_code);
    return ret_code;
}

#ifdef __USB_IN_NORMAL_MODE__

extern JC_UINT32 mmi_jmms_uc_get_msg_id_from_msg_handle(MSG_HANDLE msg_handle);


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_usb_enter_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_usb_enter_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __UNIFIED_COMPOSER_SUPPORT__
    JC_RETCODE ret_code = JC_OK;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Enters function mmi_jmms_handle_usb_enter_req");

#ifdef __UNIFIED_COMPOSER_SUPPORT__
    mmi_jmms_uc_wap_send_failure_msg_rsp(g_jmms_context->msg_id);
#else /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    /* sandeep start inorder to fix PMT_ */
    if (g_jmms_context->msg_handle)
    {
        mmi_jmms_communication_state_node_struct *comm_node = mmi_jmms_get_comm_state(g_jmms_context, g_jmms_context->reference_id);
        if (comm_node->mms_communication_state == E_TYPE_NEW_MMS)
        {
            ret_code = mmi_jmms_send_and_store_mms("Outbox", g_jmms_context->msg_handle, comm_node);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s",
                                 "mmi_jmms_handle_usb_enter_req mmi_jmms_send_and_store_mms returns: %d", ret_code);
            if (JC_OK == ret_code)
            {
                ret_code = mmi_jmms_add_pending_mms_info_node(
                            (U16) STR_ID_JMMS_COMM_ABORTED_MMS_STORED,
                            (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                            NULL);
                if (JC_OK == ret_code)
                {
                    mmi_jmms_check_for_idle_screen();
                }
            }
            else
            {
                if (ret_code == E_MEMORY_FULL_ERROR)
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEMORY,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                    if (JC_OK == ret_code)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
                else if (ret_code == JC_ERR_MEMORY_ALLOCATION || ret_code == JC_ERR_FILE_WRITE)
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE_MEM_FULL,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                    if (JC_OK == ret_code)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
                else
                {
                    ret_code = mmi_jmms_add_pending_mms_info_node(
                                (U16) STR_ID_JMMS_COMM_ABORTED_AND_FAIL_STORE,
                                (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                NULL);
                    if (JC_OK == ret_code)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
            }
        }
    }
#endif /* __UNIFIED_COMPOSER_SUPPORT__ */ 
    /* sandeep */

    mmi_jmms_delete_compose_temp_files();
    mmi_jmms_usb_create_mms_system_folder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_handle_usb_exit_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_handle_usb_exit_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "Enter mmi_jmms_handle_usb_exit_req");

    if (g_jmms_context) /*  The usb exit can come before the MMS has been initialized. */
    {
        if (g_jmms_context->init_done == JMMS_READY_WITHOUT_STORE)
        {
            if (mmi_jmms_is_ready_without_store(0))
            {
                mmi_jmms_usb_delete_mms_system_folder();

                PRINT_INFORMATION_2(MMI_TRACE_INFO, "Store is not ready: %d", g_jmms_context->init_done);
                goto end;
            }
            else
            {
                mmi_jmms_cached_pending_mms();
                mmi_jmms_usb_delete_mms_system_folder();
                mmi_jmms_store_jdi_sync_files(g_jmms_context->store_handle);
                goto end;
            }
        }
        jdd_FSCreateWapMmsSysFoldersExt(E_FALSE, E_TRUE, E_FALSE);
        if (mmi_jmms_sys_folders_exist() != JC_OK)
        {
            mmi_jmms_usb_delete_mms_system_folder();
            mmi_jmms_delete_all_msgs_status();
            mmi_jmms_deinit_shutdown_with_protocol_init();
            g_jmms_context->init_done = JMMS_READY_WITHOUT_STORE;
            /* since the MMS folder does not exist so there is no message in inbox. */
            mmi_jmms_show_mms_status_icon(MMS_STATUS_OFF);
            PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_handle_usb_exit_req: %d", g_jmms_context->init_done);
        }
        else
        {
            mmi_jmms_cached_pending_mms();
            mmi_jmms_usb_delete_mms_system_folder();
            mmi_jmms_store_jdi_sync_files(g_jmms_context->store_handle);
        }
    }
  end:
    if (g_jmms_context->init_done != JMMS_READY_WITHOUT_STORE)
    {
        mmi_jmms_update_status_icon_indicator();
    }

    if (g_jmms_context->pending_mms_info_list || g_jmms_context->pending_read_reports)
    {
        mmi_jmms_delete_mms_pop_ups_list_on_inbox_entry();
    }
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "EXIT mmi_jmms_handle_usb_exit_req");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_check_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_jmms_check_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_usb_is_in_mass_storage_mode() && jdd_FSIsMMSStorageExported())
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s, return value = 1", "mmi_jmms_check_usb_mode");
        return 1;
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s, return value = 0", "mmi_jmms_check_usb_mode");
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_delete_uncached_file_from_folder_file
 * DESCRIPTION
 *  Deletes the file from folder if it can not be moved.
 * PARAMETERS
 *  new_mms_path_src_ucs2       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_delete_uncached_file_from_folder_file(JC_CHAR *new_mms_path_src_ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fhandle = -1;
    JC_UINT32 uiExtraBytes;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fhandle = FS_Open(new_mms_path_src_ucs2, FS_READ_ONLY);
    if (fhandle < 0)
    {
        return;
    }
    mmi_jmms_set_active_folder(MMI_JMMS_INBOX);
    mmi_jmms_jdi_get_extrabytes(g_jmms_context->store_handle, (JDD_FILE) fhandle, &uiExtraBytes);
    uiExtraBytes &= 0x0FFFFFFF;
    FS_Close(fhandle);
    mmi_jmms_delete_message_as_per_id(uiExtraBytes);
    if (FS_Delete(new_mms_path_src_ucs2) != FS_NO_ERROR)
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_cached_pending_mms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_cached_pending_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 mms_path_ascii[FMGR_MAX_PATH_LEN + 1];
    JC_CHAR mms_path_src_ucs2[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    JC_RETCODE ret_code = JC_OK;
    JC_RETCODE return_code = JC_OK;
    U8 file_index = 0;
    U16 file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
    JC_UINT32 file_size = 0;
    JDD_FILE_TYPE_enum file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "mmi_jmms_cached_pending_mms");

    sprintf(mms_path_ascii, "%c:\\@wap\\mms_sys\\@mms", drive_letter);
    mmi_asc_to_ucs2((S8*) mms_path_src_ucs2, (S8*) mms_path_ascii);

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return;
        }
    }

    while (ret_code == JC_OK)
    {
        JC_CHAR mms_path_dst_ucs2[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
        JC_CHAR new_mms_path_src_ucs2[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];

        ret_code = jdd_FSReadDir(
                    g_jmms_context->jmms_fs_handle,
                    mms_path_src_ucs2,
                    file_index,
                    file_name,
                    FMGR_MAX_FILE_LEN,
                    &file_type,
                    &file_size);

        if (ret_code == JC_OK)
        {
            if (file_type == JDD_FILE_TYPE_FOLDER)
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "found folder");
                file_index++;
            }
            else
            {
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "%s", "found file");

                mmi_ucs2cpy((S8*) new_mms_path_src_ucs2, (S8*) mms_path_src_ucs2);
                mmi_asc_to_ucs2((S8*) mms_path_dst_ucs2, "\\");
                mmi_ucs2cat((S8*) new_mms_path_src_ucs2, (S8*) mms_path_dst_ucs2);
                mmi_ucs2cat((S8*) new_mms_path_src_ucs2, (S8*) file_name);
                mmi_ucs2_to_asc((S8*) mms_path_ascii, (S8*) new_mms_path_src_ucs2);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "source path: %s", mms_path_ascii);

            #ifdef MMS_IN_LARGE_STORAGE
                drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
            #endif 

                sprintf(mms_path_ascii, "%c:\\@mms\\", drive_letter);
                mmi_asc_to_ucs2((S8*) mms_path_dst_ucs2, (S8*) mms_path_ascii);
                mmi_ucs2cat((S8*) mms_path_dst_ucs2, (S8*) file_name);

                mmi_ucs2_to_asc((S8*) mms_path_ascii, (S8*) mms_path_dst_ucs2);
                PRINT_INFORMATION_2(MMI_TRACE_INFO, "Destination path: %s", mms_path_ascii);

                return_code = jdd_FSMove(NULL, new_mms_path_src_ucs2, NULL, mms_path_dst_ucs2);

                if (return_code != JC_OK)
                {
                    mms_delete_uncached_file_from_folder_file(new_mms_path_src_ucs2);
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "ERROR in caching mms files at file index: %d, ret code: %d",
                                         file_index, return_code);
                    return_code = mmi_jmms_add_pending_mms_info_node(
                                    (U16) STR_ID_JMMS_MEMORY_ERROR_NEW_MMS_NOTIF_SAVING,
                                    (U8) E_MSG_TYPE_IDLE_SCREEN_POP_UP,
                                    NULL);
                    if (JC_OK == return_code)
                    {
                        mmi_jmms_check_for_idle_screen();
                    }
                }
                else
                {
                    PRINT_INFORMATION_2(MMI_TRACE_INFO, "DELETED FILE in caching mms files at file index: %d",
                                         file_index);
                }
            }
        }
    }

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_usb_create_mms_system_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_usb_create_mms_system_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JDD_FILE fh;
    JC_INT8 folder_path_ascii[FMGR_MAX_PATH_LEN + 1];
    JC_CHAR folder_path_ucs2[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
    JDD_FSHANDLE fs_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_usb_create_mms_system_folder");

    if (fs_handle == NULL)
    {
        if (jdd_FSInitialize(&fs_handle) != JC_OK)
        {
            return;
        }
    }

    sprintf(folder_path_ascii, "%c:\\@wap\\mms_sys\\@mms", drive_letter);
    mmi_asc_to_ucs2((S8*) folder_path_ucs2, (S8*) folder_path_ascii);

    fh = jdd_FSOpen(fs_handle, (U16*) folder_path_ucs2, E_OPEN_READ_MODE);

    if (fh == NULL) /* Folder Does Not Exist */
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Creating @wap\\mms_sys\\@mms folder as it does not exists.");
        jdd_FSMakeDir(fs_handle, (U16*) folder_path_ucs2);
        drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
        sprintf(folder_path_ascii, "%c:\\@wap\\mms_sys\\@mms\\temp", drive_letter);
        mmi_asc_to_ucs2((S8*) folder_path_ucs2, (S8*) folder_path_ascii);
        jdd_FSMakeDir(fs_handle, (U16*) folder_path_ucs2);
    }
    else
    {
        PRINT_INFORMATION_2(MMI_TRACE_INFO, "Folder @wap\\mms_sys\\@mms already exists.");
        jdd_FSClose(fh);
        mmi_jmms_cached_pending_mms();
    }

    if (fs_handle != NULL)
    {
        jdd_FSDeinitialize(fs_handle);
        fs_handle = NULL;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_usb_delete_mms_system_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_usb_delete_mms_system_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    JC_INT8 mms_path_ascii[FMGR_MAX_PATH_LEN];
    JC_CHAR mms_path_src_ucs2[(FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    JC_INT32 drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_INFO, "mmi_jmms_usb_delete_mms_system_folder");

    if (g_jmms_context->jmms_fs_handle == NULL)
    {
        if (jdd_FSInitialize(&g_jmms_context->jmms_fs_handle) != JC_OK)
        {
            return;
        }
    }

    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
    sprintf(mms_path_ascii, "%c:\\@wap\\mms_sys\\@mms\\temp", drive_letter);
    mmi_asc_to_ucs2((S8*) mms_path_src_ucs2, (S8*) mms_path_ascii);

    jdd_FSDelDir(g_jmms_context->jmms_fs_handle, (U16*) mms_path_src_ucs2);

    sprintf(mms_path_ascii, "%c:\\@wap\\mms_sys\\@mms", drive_letter);
    mmi_asc_to_ucs2((S8*) mms_path_src_ucs2, (S8*) mms_path_ascii);

    jdd_FSDelDir(g_jmms_context->jmms_fs_handle, (U16*) mms_path_src_ucs2);

    if (g_jmms_context->jmms_fs_handle != NULL)
    {
        jdd_FSDeinitialize(g_jmms_context->jmms_fs_handle);
        g_jmms_context->jmms_fs_handle = NULL;
    }
}

#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_msg_as_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_msg_as_read(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 byte_number;
    U8 bit_number;
    U8 oring_byte;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_number = index / 8;
    bit_number = index % 8;

    oring_byte = (0x80 >> bit_number);

    g_jmms_context->store_context->inbox_msgs_read_status[byte_number] =
        g_jmms_context->store_context->inbox_msgs_read_status[byte_number] | oring_byte;

    WriteRecord(
        NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
        1,
        (g_jmms_context->store_context->inbox_msgs_read_status),
        (U16) MAX_READ_UNREAD_STATUS_BYTES,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_set_msg_as_unread
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_set_msg_as_unread(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 byte_number;
    U8 bit_number;
    U8 oring_byte;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_number = index / 8;
    bit_number = index % 8;

    oring_byte = (0x80 >> bit_number);

    g_jmms_context->store_context->inbox_msgs_read_status[byte_number] =
        g_jmms_context->store_context->inbox_msgs_read_status[byte_number] & (~oring_byte);

    WriteRecord(
        NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
        1,
        (g_jmms_context->store_context->inbox_msgs_read_status),
        (U16) MAX_READ_UNREAD_STATUS_BYTES,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_is_msg_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_jmms_is_msg_read(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 byte_number;
    U8 bit_number;
    U8 temp_byte;
    U8 anding_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_number = index / 8;
    bit_number = index % 8;

    temp_byte = g_jmms_context->store_context->inbox_msgs_read_status[byte_number];
    anding_byte = (0x80 >> bit_number);

    if ((temp_byte & anding_byte) == 0x00)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_msg_status(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp1, temp2;
    U8 byte_number;
    U8 bit_number;
    U8 i = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    byte_number = index / 8;
    bit_number = index % 8;

    temp1 = (g_jmms_context->store_context->inbox_msgs_read_status[byte_number]) >> (8 - bit_number);
    temp1 = temp1 << (8 - bit_number);
    temp2 = (g_jmms_context->store_context->inbox_msgs_read_status[byte_number]) << (bit_number + 1);
    temp2 = temp2 >> bit_number;

    g_jmms_context->store_context->inbox_msgs_read_status[byte_number] = temp1 | temp2;

    for (i = byte_number; i < (MAX_READ_UNREAD_STATUS_BYTES - 1); i++)
    {
        temp1 = (g_jmms_context->store_context->inbox_msgs_read_status[i + 1]) >> 7;
        g_jmms_context->store_context->inbox_msgs_read_status[i] =
            g_jmms_context->store_context->inbox_msgs_read_status[i] | temp1;
        g_jmms_context->store_context->inbox_msgs_read_status[i + 1] =
            (g_jmms_context->store_context->inbox_msgs_read_status[i + 1]) << 1;
    }

    /* WriteRecord(NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID, 1, &(g_jmms_context->store_context->inbox_read_status),MAX_READ_UNREAD_STATUS_BYTES, &error); */
    WriteRecord(
        NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
        1,
        (g_jmms_context->store_context->inbox_msgs_read_status),
        (U16) MAX_READ_UNREAD_STATUS_BYTES,
        &error);

    mmi_jmms_update_pending_downloads(index + 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_delete_all_msgs_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_jmms_delete_all_msgs_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_READ_UNREAD_STATUS_BYTES; i++)
    {
        g_jmms_context->store_context->inbox_msgs_read_status[i] = 0x00;
    }

    /* WriteRecord(NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID, 1, &(g_jmms_context->store_context->inbox_read_status),MAX_READ_UNREAD_STATUS_BYTES, &error); */
    WriteRecord(
        NVRAM_EF_JMMS_INBOX_READ_UNREAD_LID,
        1,
        (g_jmms_context->store_context->inbox_msgs_read_status),
        (U16) MAX_READ_UNREAD_STATUS_BYTES,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_jmms_get_free_space
 * DESCRIPTION
 *  Get free space
 * PARAMETERS
 *  void
 * RETURNS
 *  Free space
 *****************************************************************************/
JC_UINT32 mmi_jmms_get_free_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jdd_FSGetMMSFolderFreeSpace();
}
#endif /* (defined (JATAAYU_SUPPORT) && defined(MMS_SUPPORT)) */ 
#endif /* _MMI_JMMSSTOREHANDLING_C */ /* _MMI_STOREHANDLING_C */

