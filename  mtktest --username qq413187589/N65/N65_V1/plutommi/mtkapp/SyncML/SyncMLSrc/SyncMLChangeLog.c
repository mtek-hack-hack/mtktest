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
 *    SyncMLChangeLog.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_include.h"

#include "DateTimeGprot.h"
#include "SimDetectionGprot.h"
#include "NetworkSetupDefs.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"


/*
 * Global Variable
 */
extern syncml_context_struct g_syncml_context;


/*
 * Local Variable
 */
static U8 syncml_record[SYNCML_CHANGE_LOG_RECORD_SIZE];


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_return_file_handle
 * DESCRIPTION
 *  Open log file for the specific database
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  access_parameter        [IN]            file access parameter
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
static FS_HANDLE mmi_syncml_return_file_handle(U8 profile_id, U32 access_parameter, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    U8 *fs_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (application_type == SYNCML_DB_PHONEBOOK) /* phb */
    {
        fs_path = OslMalloc(sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((S8*) fs_path, (S8*) SYNCML_PHB_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_PHB_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + profile_id;
    }
    else if (application_type == SYNCML_DB_TODOLIST) /* tdl */
    {
        fs_path = OslMalloc(sizeof(SYNCML_TDL_CHANGE_LOG_FILE_PATH) + 1);
        mmi_ucs2cpy((S8*) fs_path, (S8*) SYNCML_TDL_CHANGE_LOG_FILE_PATH);
        *(fs_path + sizeof(SYNCML_TDL_CHANGE_LOG_FILE_PREFIX) - 2) = 0x30 + profile_id;
    }
    else
    {
        return -9; /* file not found */
    }

    fh = FS_Open((U16*) fs_path, access_parameter);
    OslMfree(fs_path);

    return fh;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_get_current_time
 * DESCRIPTION
 *  Get current time in seconds
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mmi_syncml_get_current_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&t);
    return mmi_dt_mytime_2_utc_sec(&t, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_phb_data_changed_notification
 * DESCRIPTION
 *  Callback for phonebook record changed
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_phb_data_changed_notification(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 luid_exist;
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "SyncML: phonebook data changed, op = %d, LUID = %d", operation, luid);
    /* currently MMI takes the store index as LUID */

    MMI_ASSERT(luid < MAX_PHB_PHONE_ENTRY);

    mmi_syncml_prepare_record_to_save(operation, luid);

    for (i = 1; i < MAX_SYNCML_SV_PROFILES + 1; i++)
    {
        if (g_syncml_context.last_phb_anchor[i - 1] != 0) /* this profile is used to sync before */ 
        {
            if (mmi_syncml_is_phb_sync_now() && i == g_syncml_context.active_profile)
            {
                continue; /* skip the synchronizing profile and update the other profiles */
            }

            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_PHONEBOOK);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_PHONEBOOK, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_PHONEBOOK);
            }
        }
    }

    if ((g_syncml_context.regular_sync == SYNCML_REGULAR_SYNC_DATA_CHANGED) &&
        (g_syncml_context.applications_to_sync & SYNCML_DB_PHONEBOOK) &&
        !mmi_syncml_is_phb_sync_now())
    {
        g_syncml_context.power_on_sync = 1;

        if (mmi_bootup_get_active_flight_mode() != 0)
        {
            mmi_syncml_update_settings_to_nvram();
        }
        else if (mmi_bootup_is_sim_valid() == MMI_FALSE)
        {
        #ifdef __MMI_WLAN_FEATURES__
            if (mmi_netset_get_active_preferred_mode() == 0)
        #endif /* __MMI_WLAN_FEATURES__ */
                mmi_syncml_update_settings_to_nvram();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_tdl_data_changed_notification
 * DESCRIPTION
 *  Callback for to-do-list record changed
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_tdl_data_changed_notification(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 luid_exist;
    U8 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PRINT_INFORMATION_2(MMI_TRACE_G7_MISC, "SyncML: to-do-list data changed, op = %d, LUID = %d", operation, luid);
    /* currently MMI takes the store index as LUID */

    mmi_syncml_prepare_record_to_save(operation, luid);

    for (i = 1; i < MAX_SYNCML_SV_PROFILES + 1; i++)
    {
        if (g_syncml_context.last_tdl_anchor[i - 1] != 0) /* this profile is used to sync before */ 
        {
            if (mmi_syncml_is_tdl_sync_now() && i == g_syncml_context.active_profile)
            {
                continue; /* skip the synchronizing profile and update the other profiles */
            }

            luid_exist = mmi_syncml_search_duplicate_record(luid, i, SYNCML_DB_TODOLIST);
            if (luid_exist >= 0)
            {
                mmi_syncml_merge_record(i, SYNCML_DB_TODOLIST, luid_exist);
            }
            else
            {
                mmi_syncml_append_record(i, SYNCML_DB_TODOLIST);
            }
        }
    }

    if ((g_syncml_context.regular_sync == SYNCML_REGULAR_SYNC_DATA_CHANGED) &&
        (g_syncml_context.applications_to_sync & SYNCML_DB_TODOLIST) &&
        !mmi_syncml_is_tdl_sync_now())
    {
        g_syncml_context.power_on_sync = 1;

        if (mmi_bootup_get_active_flight_mode() != 0)
        {
            mmi_syncml_update_settings_to_nvram();
        }
        else if (mmi_bootup_is_sim_valid() == MMI_FALSE)
        {
        #ifdef __MMI_WLAN_FEATURES__
            if (mmi_netset_get_active_preferred_mode() == 0)
        #endif /* __MMI_WLAN_FEATURES__ */
                mmi_syncml_update_settings_to_nvram();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_search_duplicate_record
 * DESCRIPTION
 *  Search if there is a duplicate change log with the same LUID
 * PARAMETERS
 *  luid                    [IN]            LUID
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
S32 mmi_syncml_search_duplicate_record(U16 luid, U8 profile_id, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    S32 res = SYNCML_CHANGE_LOG_NOT_FOUND;
    U32 fs_size, read_length, i;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
    U16 luid_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = mmi_syncml_return_file_handle(profile_id, FS_READ_ONLY, application_type);

    if (fs_handle >= 0)
    {
        FS_GetFileSize(fs_handle, &fs_size);

        for (i = 0; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
        {
            FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
            memcpy((void *) &luid_temp, (void*) &syncml_temp[0], sizeof(U16));
            if (luid == luid_temp)
            {
                res = i;
                break;
            }
        }

        FS_Close(fs_handle);
    }
    else
    {
        /* file access error... */
    }

    return res;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_prepare_record_to_save
 * DESCRIPTION
 *  Prepare the change log data
 * PARAMETERS
 *  operation              [IN]            operation
 *  luid                   [IN]            LUID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_prepare_record_to_save(U8 operation, U16 luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(syncml_record, (void *)(&luid), sizeof(U16));
    s = mmi_syncml_get_current_time();
    memcpy(syncml_record + sizeof(U16), (void *)(&s), sizeof(U32));
    syncml_record[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] = operation;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_append_record
 * DESCRIPTION
 *  Append the change log data
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
void mmi_syncml_append_record(U8 profile_id, U8 application_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    U32 written_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = mmi_syncml_return_file_handle(profile_id, FS_CREATE | FS_READ_WRITE, application_type);

    FS_Seek(fs_handle, 0, FS_FILE_END);
    FS_Write(fs_handle, (void*) &syncml_record[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length); 
    FS_Close(fs_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_append_record
 * DESCRIPTION
 *  Append the change log data
 * PARAMETERS
 *  profile_id              [IN]            profile id
 *  application_type        [IN]            application/database type
 *  fs_index                [IN]            file index
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
void mmi_syncml_merge_record(U8 profile_id, U8 application_type, S32 fs_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;

    U32 read_length, written_length, fs_size, i;
    U8 old_operation, new_operation;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];
    U8 syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_handle = mmi_syncml_return_file_handle(profile_id, FS_READ_WRITE, application_type);
    FS_GetFileSize(fs_handle, &fs_size);

    /* find out the data for merge */
    FS_Seek(fs_handle, fs_index, FS_FILE_BEGIN);
    FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
    old_operation = syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE - 1];
    new_operation = syncml_record[SYNCML_CHANGE_LOG_RECORD_SIZE - 1];

    memcpy((void*) &syncml_update[0], (void*) &syncml_record[0], SYNCML_CHANGE_LOG_RECORD_SIZE);
    syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] = mmi_syncml_operation_update(old_operation, new_operation);

    /* prepare the updated change log */
    FS_Seek(fs_handle, fs_index, FS_FILE_BEGIN); /* change file content from the modified index */
    if (syncml_update[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] == SYNCML_RECORD_ERASE)
    {
        for (i = fs_index + SYNCML_CHANGE_LOG_RECORD_SIZE; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
        {
            FS_Seek(fs_handle, SYNCML_CHANGE_LOG_RECORD_SIZE, FS_FILE_CURRENT);
            FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
            FS_Seek(fs_handle, 0 - 2 * SYNCML_CHANGE_LOG_RECORD_SIZE, FS_FILE_CURRENT);
            FS_Write(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length);
        }
        FS_Truncate(fs_handle);
    }
    else
    {
        FS_Write(fs_handle, (void*) &syncml_update[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &written_length);
    }

    FS_Close(fs_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_operation_update
 * DESCRIPTION
 *  Check the operation if the change log is duplicted
 * PARAMETERS
 *  old_operation           [IN]            old operation
 *  new_operation           [IN]            new operation
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_syncml_operation_update(U8 old_operation, U8 new_operation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rtn = old_operation;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (old_operation)
    {
        case SYNCML_RECORD_ADD:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */
                    break;
                case SYNCML_RECORD_MODIFY:
                    rtn = SYNCML_RECORD_ADD;
                    break;
                case SYNCML_RECORD_DELETE:
                    rtn = SYNCML_RECORD_ERASE;
                    break;
            }
            break;
        case SYNCML_RECORD_MODIFY:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD: /* error */
                    break;
                case SYNCML_RECORD_MODIFY:
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_DELETE:
                    rtn = SYNCML_RECORD_DELETE;
                    break;
            }
            break;
        case SYNCML_RECORD_DELETE:
            switch (new_operation)
            {
                case SYNCML_RECORD_ADD:
                    rtn = SYNCML_RECORD_MODIFY;
                    break;
                case SYNCML_RECORD_MODIFY: /* error */
                    break;
                case SYNCML_RECORD_DELETE: /* error */
                    break;
            }
            break;
    }

    return rtn;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_clearall_change_log
 * DESCRIPTION
 *  clear all items in change log
 * PARAMETERS
 *  profile_id           [IN]            profile id
 *  database             [IN]            application/database type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_clearall_change_log(U8 profile_id, U8 database)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    fs_handle = mmi_syncml_return_file_handle(profile_id, FS_READ_WRITE, database);
    if (fs_handle >= 0)
    {
        FS_Seek(fs_handle, 0, FS_FILE_BEGIN);
        FS_Truncate(fs_handle);
        FS_Close(fs_handle);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_query_change_log
 * DESCRIPTION
 *  Qurey the change log
 * PARAMETERS
 *  profile_id           [IN]            profile id
 *  database             [IN]            application/database type
 *  luid                 [OUT]           LUID
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_syncml_query_change_log(U8 operation, U8 database, U16 *luid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_length, fs_size, i;
    U16 count = 0;
    U8 syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE];

    FS_HANDLE fs_handle = mmi_syncml_return_file_handle(g_syncml_context.active_profile, FS_READ_ONLY, database);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if  (fs_handle < 0)
    {
		return 0; /* log file not exist, count should be 0 */
    }

    FS_GetFileSize(fs_handle, &fs_size);

    for (i = 0; i < fs_size; i += SYNCML_CHANGE_LOG_RECORD_SIZE)
    {
        FS_Read(fs_handle, (void*) &syncml_temp[0], SYNCML_CHANGE_LOG_RECORD_SIZE, &read_length);
        if (syncml_temp[SYNCML_CHANGE_LOG_RECORD_SIZE - 1] == operation)
        {
            *(luid + count) = ((U16*)syncml_temp)[0]; 
            count++;
        }
    }

    FS_Close(fs_handle);
    return count;
}


#endif /* __SYNCML_SUPPORT__ */

