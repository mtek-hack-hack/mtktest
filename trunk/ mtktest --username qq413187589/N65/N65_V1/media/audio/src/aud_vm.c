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
 * aud_vm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes voice memo related functions of audio manager task.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_VM
 * DESCRIPTION
 *    This module defines the voice memo related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ========*/
#include "med_global.h"
#if defined(VM_SUPPORT) && defined(VM_LOG)

#include "kal_release.h"

#include "kal_trace.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h" /* Event scheduler */

#include "stack_timer.h"        /* Stack timer */

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
/* for FAT FS */
#include "fat_fs.h"
#include "rtc_sw.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#define RANDOM_POS   (8)

#define MAX_VM_DIR_LEN   20
#define FULL_NAME_LEN (MAX_VM_FILE_NAME+MAX_VM_DIR_LEN)

kal_wchar vm_file_name[FULL_NAME_LEN];
kal_wchar vm_file_string[MAX_NUM_OF_VM_FILE][MAX_VM_FILE_NAME];

#ifdef VM_DIR
#undef VM_DIR
#endif 
#define VM_PATH (L"Audio")
kal_wchar VM_DIR[MAX_VM_DIR_LEN];

kal_uint8 file_count;


/*****************************************************************************
 * FUNCTION
 *  aud_vm_init
 * DESCRIPTION
 *  This function is used to init aud_vm module
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_vm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_int16 drv_letter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->vm_rec_dir = AUD_VM_DIR_UL;

#ifdef VOICE_RECOGNITION_TEST
    aud_context_p->vm_sp_type = MEDIA_FORMAT_PCM_8K;    /* MEDIA_FORMAT_GSM_EFR; */
#else 
    aud_context_p->vm_sp_type = MEDIA_FORMAT_GSM_EFR;
#endif 

    aud_context_p->current_file_name[0] = 0;
    aud_context_p->current_file_handle = -1;
    aud_context_p->disc_full = KAL_FALSE;
    aud_context_p->delete_all = KAL_FALSE;
    aud_context_p->play_mode = AUD_MEDIA_PLAY_MODE_NONE;
    aud_context_p->vm_info.num_of_vm = 0;
    aud_context_p->vm_info.free_space = MAX_VM_SIZE;
    aud_context_p->offset = 0;

    for (i = 0; i < MAX_NUM_OF_VM_FILE; i++)
    {
        aud_context_p->vm_info.file_name_list[i] = vm_file_string[i];
    }

    drv_letter = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
    kal_wsprintf((kal_wchar*) VM_DIR, "%c:\\%w", drv_letter, VM_PATH);
    kal_wsprintf(vm_file_name, "%w\\*%s", VM_DIR, ".vm");

#ifdef VM_LOG
    aud_context_p->vm_logging = KAL_FALSE;
    aud_context_p->vm_id = 0;
#endif /* VM_LOG */ 

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_scan_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_vm_scan_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE vm_file_handle;
    kal_int32 result;
    FS_DOSDirEntry de;
    kal_wchar *file_name_p;
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_IN_USB_MS__
    if (stack_query_boot_mode() == USBMS_BOOT)
    {
        return KAL_FALSE;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    /* if vm dir exists, open it ,otherwise create it */
    vm_file_handle = FS_Open(VM_DIR, FS_OPEN_DIR | FS_READ_ONLY);
    if (vm_file_handle < 0)
    {
        result = FS_CreateDir(VM_DIR);
        /* ASSERT(result >= 0) */
    }
    else
    {
        FS_Close(vm_file_handle);
    }

    for (i = 0; i < MAX_NUM_OF_VM_FILE; i++)
    {
        aud_context_p->vm_info.file_name_list[i] = vm_file_string[i];
    }

    /* reset num of vm */
    aud_context_p->vm_info.num_of_vm = 0;

    file_name_p = aud_context_p->vm_info.file_name_list[0];
    vm_file_handle = FS_FindFirst(vm_file_name, 0, 0, &de, file_name_p, MAX_VM_FILE_NAME * ENCODE_BYTE);

    aud_context_p->vm_info.free_space = MAX_VM_SIZE;
    if (vm_file_handle >= 0)
    {
        aud_context_p->vm_info.num_of_vm++;
        file_name_p = aud_context_p->vm_info.file_name_list[aud_context_p->vm_info.num_of_vm];

        /* count the free space */
        if (aud_context_p->vm_info.free_space >= de.FileSize)
        {
            aud_context_p->vm_info.free_space -= de.FileSize;
        }
        else
        {
            aud_context_p->vm_info.free_space = 0;
        }

        while ((result = FS_FindNext(vm_file_handle, &de, file_name_p, MAX_VM_FILE_NAME * ENCODE_BYTE)) == FS_NO_ERROR)
        {
            if (de.Attributes != FS_ATTR_DIR)
            {
                aud_context_p->vm_info.num_of_vm++;
                /* count the free space */
                if (aud_context_p->vm_info.free_space >= de.FileSize)
                {
                    aud_context_p->vm_info.free_space -= de.FileSize;
                }
                else
                {
                    aud_context_p->vm_info.free_space = 0;
                }

                if (aud_context_p->vm_info.num_of_vm >= MAX_NUM_OF_VM_FILE)
                {
                    break;
                }
                /* set the file name pointer for next loop */
                file_name_p = aud_context_p->vm_info.file_name_list[aud_context_p->vm_info.num_of_vm];
            }
        }
        FS_FindClose(vm_file_handle);

        if (aud_context_p->vm_info.free_space > 0)
            /* set disc full to TRUE */
        {
            aud_context_p->disc_full = KAL_FALSE;
        }
        else
            /* set disc full to TRUE */
        {
            aud_context_p->disc_full = KAL_TRUE;
        }
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_startup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_vm_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return aud_vm_scan_file();
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MEDIA, volume1, digital_gain_index) Media_SetOutputVolume(volume1, digital_gain_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_VM, device, -1) Media_SetOutputDevice(device);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_record_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_record_callback(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_vm_read_data_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind_p = (aud_vm_read_data_ind_struct*) construct_local_para(sizeof(aud_vm_read_data_ind_struct), TD_CTRL);

    ind_p->event = (kal_uint8) event;

    aud_send_ilm(MOD_MED, MSG_ID_AUD_VM_READ_DATA_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_check_existing_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_vm_check_existing_file_name(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < aud_context_p->vm_info.num_of_vm && i < MAX_NUM_OF_VM_FILE; i++)
    {
        if (kal_wstrcmp(file_name, aud_context_p->vm_info.file_name_list[i]) == 0)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_new_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_new_file_name(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    t_rtc rtc_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RTC_GetTime(&rtc_time);
#ifdef _WIN32
    rtc_time.rtc_year = 123;
    rtc_time.rtc_mon = 3;
    rtc_time.rtc_day = 6;
    rtc_time.rtc_hour = 12;
    rtc_time.rtc_min = 34;
    rtc_time.rtc_sec = 56;
#endif /* _WIN32 */ 
    kal_wsprintf(
        file_name,
        "%02d%02d%02d%02da.vm",
        rtc_time.rtc_mon,
        rtc_time.rtc_day,
        rtc_time.rtc_hour,
        rtc_time.rtc_min);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_increase_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_increase_file_name(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_count++;
    if (file_count >= MAX_NUM_OF_VM_FILE)
    {
        file_count = 0;
    }

    file_name[RANDOM_POS] = (kal_wchar) (file_count + 'a');
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_get_current_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_get_current_file_name(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_count = 0;
    aud_vm_new_file_name(file_name);
    while (aud_vm_check_existing_file_name(file_name))
    {
        aud_vm_increase_file_name(file_name);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_change_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  old_name        [?]     
 *  new_name        [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_vm_change_file_name(kal_wchar *old_name, kal_wchar *new_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < aud_context_p->vm_info.num_of_vm; i++)
    {
        if (kal_wstrcmp(old_name, aud_context_p->vm_info.file_name_list[i]) == 0)
        {
            kal_wchar full_name_1[FULL_NAME_LEN];
            kal_wchar full_name_2[FULL_NAME_LEN];

            kal_wsprintf(full_name_1, "%w\\%w", VM_DIR, old_name);
            kal_wsprintf(full_name_2, "%w\\%w", VM_DIR, new_name);
            if (FS_Rename(full_name_1, full_name_2) == FS_NO_ERROR)
            {
                kal_mem_cpy(aud_context_p->vm_info.file_name_list[i], new_name, MAX_VM_FILE_NAME * ENCODE_BYTE);
                return MED_RES_OK;
            }
            else
            {
                return MED_RES_FAIL;
            }
        }
    }
    return MED_RES_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_remove_file_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_vm_remove_file_from_list(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i = 0, j = 0;
    kal_int32 result;
    kal_wchar *file_name_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < aud_context_p->vm_info.num_of_vm)
    {
        if (kal_wstrcmp(file_name, aud_context_p->vm_info.file_name_list[i]) == 0)
        {
            kal_wchar full_name[FULL_NAME_LEN];

            kal_wsprintf(full_name, "%w\\%w", VM_DIR, file_name);
            result = FS_Delete(full_name);
            if (result == FS_NO_ERROR)
            {
                file_name_p = aud_context_p->vm_info.file_name_list[i];
                for (j = i + 1; j < aud_context_p->vm_info.num_of_vm; j++)
                {
                    aud_context_p->vm_info.file_name_list[j - 1] = aud_context_p->vm_info.file_name_list[j];
                }
                aud_context_p->vm_info.file_name_list[aud_context_p->vm_info.num_of_vm] = file_name_p;
                aud_context_p->vm_info.num_of_vm--;
                aud_context_p->disc_full = KAL_FALSE;
                return MED_RES_OK;
            }
            else
            {
                return MED_RES_FAIL;
            }
        }
        i++;
    }
    return MED_RES_OPEN_FILE_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_remove_all_file_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_vm_remove_all_file_from_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < aud_context_p->vm_info.num_of_vm && i < MAX_NUM_OF_VM_FILE; i++)
    {
        kal_wchar full_name[FULL_NAME_LEN];

        kal_wsprintf(full_name, "%w\\%w", VM_DIR, aud_context_p->vm_info.file_name_list[i]);
        result = FS_Delete(full_name);
        if (result != FS_NO_ERROR)
        {
            kal_print("[AUD][VM]Delete non-existing file.");
        }
    }

    aud_context_p->vm_info.num_of_vm = 0;
    aud_context_p->disc_full = KAL_FALSE;
    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_add_file_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_vm_add_file_to_list(kal_wchar *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->vm_info.num_of_vm < MAX_NUM_OF_VM_FILE &&
        aud_context_p->vm_info.file_name_list[aud_context_p->vm_info.num_of_vm] != NULL)
    {
        kal_mem_cpy(
            aud_context_p->vm_info.file_name_list[aud_context_p->vm_info.num_of_vm],
            file_name,
            MAX_VM_FILE_NAME * ENCODE_BYTE);
        aud_context_p->vm_info.num_of_vm++;
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_check_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drive_name      [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_check_free_space(kal_wchar *drive_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_GetDiskInfo(drive_name, &disk_info, FS_DI_FREE_SPACE);
    if (disk_info.FreeClusters > 0)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_record_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_record_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnf_result;

    l4aud_vm_record_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_RECORD_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_record_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    /* If the media is playing, return busy */
    if (aud_context_p->media_playing)
    {
        /* send confirm message to L4 */
        aud_send_vm_record_cnf(MED_RES_BUSY);
        return;
    }

    if (aud_context_p->state == AUD_VM_IDLE)
    {

        if (!aud_context_p->disc_full &&
            aud_context_p->vm_info.num_of_vm < MAX_NUM_OF_VM_FILE && aud_check_free_space(L"c:"))
        {
            kal_wchar full_name[FULL_NAME_LEN];

            aud_vm_get_current_file_name(aud_context_p->current_file_name);
            kal_wsprintf(full_name, "%w\\%w", VM_DIR, aud_context_p->current_file_name);
            aud_context_p->current_file_handle = FS_Open(full_name, FS_CREATE | FS_READ_WRITE);

            if (aud_context_p->current_file_handle >= 0 && aud_vm_add_file_to_list(aud_context_p->current_file_name))
            {

                /* call L1AUD to set buffer */
                Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);

                /* start to record */
                Media_Record((Media_Format) aud_context_p->vm_sp_type, aud_vm_record_callback, NULL);

                /* reset offset */
                aud_context_p->offset = 0;

                cnf_result = MED_RES_OK;

                /* enter AUD_VM_RECORD state */
                AUD_ENTER_STATE(AUD_VM_RECORD);
            }
            else if (aud_context_p->current_file_handle >= 0)
            {
                FS_Close(aud_context_p->current_file_handle);
                /* send confirm message to l4 */
                cnf_result = MED_RES_OPEN_FILE_FAIL;
            }
            else
            {
                /* send confirm message to l4 */
                cnf_result = MED_RES_OPEN_FILE_FAIL;
            }

        }
        else
        {
            aud_context_p->disc_full = KAL_TRUE;
            /* send confirm message to l4 */
            cnf_result = MED_RES_DISC_FULL;
        }
    }
    else
    {
        cnf_result = MED_RES_BUSY;
    }
    /* send confirm message to l4 */
    aud_send_vm_record_cnf(cnf_result);

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_play_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_play_callback(Media_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_vm_write_data_ind_struct *ind_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Media_GetWriteBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
    if (aud_context_p->buf_p == NULL || aud_context_p->buf_len == 0)
    {
        return;
    }

    ind_p = (aud_vm_write_data_ind_struct*) construct_local_para(sizeof(aud_vm_write_data_ind_struct), TD_CTRL);

    ind_p->event = (kal_uint8) event;

    aud_send_ilm(MOD_MED, MSG_ID_AUD_VM_WRITE_DATA_IND, ind_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_play_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_play_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_vm_play_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_PLAY_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_play_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    if (aud_context_p->media_playing)
    {
        /* send confirm message to L4 */
        aud_send_vm_play_cnf(MED_RES_BUSY);
        return;
    }

    switch (aud_context_p->state)
    {
        case AUD_VM_IDLE:
        {

            if (aud_vm_check_existing_file_name((kal_wchar*) msg_p->file_name))
            {
                /* open the file */
                kal_wchar full_name[FULL_NAME_LEN];

                kal_wsprintf(full_name, "%w\\%w", VM_DIR, (kal_wchar*) msg_p->file_name);
                aud_context_p->current_file_handle = FS_Open(full_name, FS_READ_ONLY | FS_OPEN_NO_DIR);

                if (aud_context_p->current_file_handle >= 0)
                {
                    kal_uint32 len;

                    /* set current file name */
                    kal_mem_cpy(aud_context_p->current_file_name, msg_p->file_name, MAX_VM_FILE_NAME * ENCODE_BYTE);
                    /* call L1AUD to set buffer */
                    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                    Media_GetWriteBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
                    ASSERT(aud_context_p->buf_p != NULL);

                    /* read data from file to buffer */
                    FS_Read(aud_context_p->current_file_handle, aud_context_p->buf_p, aud_context_p->buf_len * 2, &len);

                    /* update offset */
                    aud_context_p->offset = len;

                    AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1) len = len >> 1;
                    if (len == 0)
                    {
                        /* close the file */
                        FS_Close(aud_context_p->current_file_handle);

                        /* send confirm message to L4 */
                        aud_send_vm_play_cnf(MED_RES_OPEN_FILE_FAIL);
                    }
                    else if (len < aud_context_p->buf_len)
                    {
                        aud_context_p->buf_len = len;

                        /* inform L1AUD the amount of data read from file to ring buffer */
                        Media_WriteDataDone(len);

                        /* follow ring tone volume */
                    #ifdef SET_VOLUME_WHEN_PLAY
                        aud_set_active_ring_tone_volume();
                    #endif 
                        /* start to play */
                        Media_Play(
                            (Media_Format) aud_context_p->vm_sp_type,
                            aud_vm_play_callback,
                            MEDIA_VMP_AS_RINGTONE);
                        Media_DataFinished();

                        /* close the file */
                        FS_Close(aud_context_p->current_file_handle);

                        /* send confirm message to L4 */
                        aud_send_vm_play_cnf(MED_RES_OK);

                        /* play as memo */
                        aud_context_p->play_mode = AUD_VM_PLAY_AS_MEMO;

                        /* enter AUD_VM_PLAY_FINISH state */
                        AUD_ENTER_STATE(AUD_VM_PLAY_FINISH);
                    }
                    else
                    {
                        /* inform L1AUD the amount of data read from file to ring buffer */
                        Media_WriteDataDone(len);

                        /* follow ring tone volume */
                    #ifdef SET_VOLUME_WHEN_PLAY
                        aud_set_active_ring_tone_volume();
                    #endif 
                        /* start to play */
                        Media_Play(
                            (Media_Format) aud_context_p->vm_sp_type,
                            aud_vm_play_callback,
                            MEDIA_VMP_AS_RINGTONE);

                        /* send confirm message to L4 */
                        aud_send_vm_play_cnf(MED_RES_OK);

                        /* play as memo */
                        aud_context_p->play_mode = AUD_VM_PLAY_AS_MEMO;

                        /* enter AUD_VM_PLAY state */
                        AUD_ENTER_STATE(AUD_VM_PLAY);
                    }

                }
                else
                {
                    /* send confirm message to L4 */
                    aud_send_vm_play_cnf(MED_RES_OPEN_FILE_FAIL);
                }

            }
            else
            {
                /* send confirm message to L4 */
                aud_send_vm_play_cnf(MED_RES_OPEN_FILE_FAIL);

            }

            break;
        }
        default:
        {

            /* send confirm message to L4 */
            aud_send_vm_play_cnf(MED_RES_BUSY);
            break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id         [IN]        
 *  play_style      [IN]        
 *  out_device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_play(kal_uint8 file_id, kal_uint8 play_style, kal_uint8 out_device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *vm_file;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->state)
    {
        case AUD_VM_IDLE:
        {
            vm_file = aud_context_p->vm_info.file_name_list[file_id];

            if (aud_vm_check_existing_file_name(vm_file))
            {
                /* open the file */
                kal_wchar full_name[FULL_NAME_LEN];

                kal_wsprintf(full_name, "%w\\%w", VM_DIR, (kal_wchar*) vm_file);
                aud_context_p->current_file_handle = FS_Open(full_name, FS_READ_ONLY | FS_OPEN_NO_DIR);

                if (aud_context_p->current_file_handle >= 0)
                {
                    kal_uint32 len;

                    /* set current file name */
                    kal_mem_cpy(aud_context_p->current_file_name, vm_file, MAX_VM_FILE_NAME * ENCODE_BYTE);
                    /* call L1AUD to set buffer */
                    Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);
                    Media_GetWriteBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
                    ASSERT(aud_context_p->buf_p != NULL);

                    /* read data from file to buffer */
                    FS_Read(aud_context_p->current_file_handle, aud_context_p->buf_p, aud_context_p->buf_len * 2, &len);

                    /* update offset */
                    aud_context_p->offset += len;

                    len = len >> 1;
                    if (len == 0)
                    {
                        /* close the file */
                        FS_Close(aud_context_p->current_file_handle);
                    }
                    else if (len < aud_context_p->buf_len)
                    {
                        aud_context_p->buf_len = len;

                        /* inform L1AUD the amount of data read from file to ring buffer */
                        Media_WriteDataDone(len);

                        /* follow ring tone volume */
                    #ifdef SET_VOLUME_WHEN_PLAY
                        aud_set_active_ring_tone_volume();
                    #endif 
                        /* start to play */
                        Media_Play(
                            (Media_Format) aud_context_p->vm_sp_type,
                            aud_vm_play_callback,
                            MEDIA_VMP_AS_RINGTONE);
                        Media_DataFinished();

                        /* close the file */
                        FS_Close(aud_context_p->current_file_handle);

                        /* play as memo */
                        aud_context_p->play_mode = AUD_VM_PLAY_AS_RING;

                        /* enter AUD_VM_PLAY_FINISH state */
                        AUD_ENTER_STATE(AUD_VM_PLAY_FINISH);
                    }
                    else
                    {
                        /* inform L1AUD the amount of data read from file to ring buffer */
                        Media_WriteDataDone(len);

                        /* follow ring tone volume */
                    #ifdef SET_VOLUME_WHEN_PLAY
                        aud_set_active_ring_tone_volume();
                    #endif 
                        /* start to play */
                        Media_Play(
                            (Media_Format) aud_context_p->vm_sp_type,
                            aud_vm_play_callback,
                            MEDIA_VMP_AS_RINGTONE);

                        /* send confirm message to L4 */
                        aud_send_vm_play_cnf(MED_RES_OK);

                        /* play as memo */
                        aud_context_p->play_mode = AUD_VM_PLAY_AS_RING;

                        /* enter AUD_VM_PLAY state */
                        AUD_ENTER_STATE(AUD_VM_PLAY);
                    }
                }
            }
            break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->state)
    {
        case AUD_VM_PLAY:
        {
            /* Stop voice memo recording process */
            Media_Stop();

            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            /* enter AUD_VM_IDLE state */
            aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state) break;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_stop_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_stop_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_STOP_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        {
            kal_uint8 cnf_result;

            /* Stop voice memo recording process */
            Media_Stop();

            FS_Write(aud_context_p->current_file_handle, aud_context_p->buf_p, aud_context_p->buf_len * 2, &len);

            /* update offset */
            aud_context_p->offset += len;

            AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1) cnf_result = MED_RES_OK;

            FS_Close(aud_context_p->current_file_handle);

            /* send confirm message to L4 */
            aud_send_vm_stop_cnf(cnf_result, aud_context_p->current_file_name);

            /* change to AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }
        case AUD_VM_PLAY:
        {
            /* Stop voice memo recording process */
            Media_Stop();

            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            /* send confirm message to L4 */
            aud_send_vm_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);

            /* enter AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }
        case AUD_VM_RECORD_PAUSED:
        {
            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            /* send confirm message to L4 */
            aud_send_vm_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);

            /* enter AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }
        case AUD_VM_PLAY_PAUSED:
        {
            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            /* send confirm message to L4 */
            aud_send_vm_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);

            /* enter AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }
        case AUD_VM_PLAY_FINISH:
        {
            /* Stop voice memo playing process */
            Media_Stop();

            /* send confirm message to L4 */
            aud_send_vm_stop_cnf(MED_RES_OK, aud_context_p->current_file_name);

            /* enter AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }
        default:
        {
            /* send confirm message to L4 */
            aud_send_vm_stop_cnf(MED_RES_FAIL, NULL);

            /* enter AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_delete_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_delete_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnf_result;

    l4aud_vm_delete_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_DELETE_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_delete_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_VM_IDLE:
        {
            if (msg_p->delete_all)
            {
                /* delete all file from FS */
                cnf_result = aud_vm_remove_all_file_from_list();
            }
            else
            {
                /* delete the file from FS */
                cnf_result = aud_vm_remove_file_from_list((kal_wchar*) msg_p->file_name);
            }
            break;
        }
        default:
            cnf_result = MED_RES_BUSY;
    }
    aud_send_vm_delete_cnf(cnf_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_abort_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_abort_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnf_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_ABORT_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        {
            /* Stop voice memo recording process */
            Media_Stop();

            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            /* Delete the file */
            cnf_result = aud_vm_remove_file_from_list(aud_context_p->current_file_name);

            /* enter AUD_VM_IDLE state */
            aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state) break;
        }
        case AUD_VM_PLAY:
        {
            /* Stop voice memo recording process */
            Media_Stop();

            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            cnf_result = MED_RES_OK;
            /* enter AUD_VM_IDLE state */
            aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state) break;
        }
        case AUD_VM_RECORD_PAUSED:
        {
            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            /* Delete the file */
            cnf_result = aud_vm_remove_file_from_list(aud_context_p->current_file_name);

            /* enter AUD_VM_IDLE state */
            aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state) break;
        }
        case AUD_VM_PLAY_PAUSED:
        {
            /* close the file */
            FS_Close(aud_context_p->current_file_handle);

            cnf_result = MED_RES_OK;
            /* enter AUD_VM_IDLE state */
            aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state) break;
        }
        default:
        {
            cnf_result = MED_RES_FAIL;
            break;
        }

    }
    aud_send_vm_abort_cnf(cnf_result);

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_pause_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_pause_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 len;

    l4aud_vm_pause_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_PAUSE_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_pause_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        {
            kal_uint8 cnf_result;

            /* Stop voice memo recording process */
            Media_Stop();

            result = FS_Write(
                        aud_context_p->current_file_handle,
                        aud_context_p->buf_p,
                        aud_context_p->buf_len * 2,
                        &len);
            /* update offset */
            aud_context_p->offset += len;

            AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1)
                if (result == FS_NO_ERROR && aud_context_p->offset < aud_context_p->vm_info.free_space)
            {
                cnf_result = MED_RES_OK;
                /* change to AUD_VM_RECORD_PAUSED state */
                AUD_ENTER_STATE(AUD_VM_RECORD_PAUSED);
            }
            else if (result == FS_DISK_FULL || aud_context_p->offset >= aud_context_p->vm_info.free_space)
            {
                cnf_result = MED_RES_DISC_FULL;

                /* close current file */
                FS_Close(aud_context_p->current_file_handle);

                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->vm_info.free_space, aud_context_p->disc_full)
                    /* set disc full to TRUE */
                    aud_context_p->disc_full = KAL_TRUE;

                /* change to AUD_VM_IDLE state */
                AUD_ENTER_STATE(AUD_VM_IDLE);
            }
            else
            {
                cnf_result = MED_RES_FAIL;

                /* close current file */
                FS_Close(aud_context_p->current_file_handle);
                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->vm_info.free_space, aud_context_p->disc_full)
                    /* decrease the free space */
                    aud_context_p->vm_info.free_space -= aud_context_p->offset;

                /* change to AUD_VM_IDLE state */
                AUD_ENTER_STATE(AUD_VM_IDLE);
            }

            /* send confirm message to L4 */
            aud_send_vm_pause_cnf(cnf_result, aud_context_p->current_file_name);
            break;
        }
        case AUD_VM_PLAY:
        case AUD_VM_PLAY_FINISH:
        {
            /* Stop voice memo recording process */
            Media_Stop();

            /* send confirm message to L4 */
            aud_send_vm_pause_cnf(MED_RES_OK, aud_context_p->current_file_name);

            /* enter AUD_VM_PLAY_PAUSED state */
            AUD_ENTER_STATE(AUD_VM_PLAY_PAUSED);
            break;
        }
        default:
        {
            /* send confirm message to L4 */
            aud_send_vm_pause_cnf(MED_RES_FAIL, NULL);
            break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_resume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_resume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_vm_resume_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_RESUME_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_resume_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    /* If the media is playing, return busy */
    if (aud_context_p->media_playing)
    {
        /* send confirm message to L4 */
        aud_send_vm_resume_cnf(MED_RES_BUSY);
        return;
    }

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD_PAUSED:
        {

            /* call L1AUD to set buffer */
            Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);

            /* start to record */
            Media_Record((Media_Format) aud_context_p->vm_sp_type, aud_vm_record_callback, NULL);
            aud_send_vm_resume_cnf(MED_RES_OK);

            /* enter AUD_VM_RECORD state */
            AUD_ENTER_STATE(AUD_VM_RECORD);
            break;
        }
        case AUD_VM_PLAY_PAUSED:
        {

            /* follow ring tone volume */
        #ifdef SET_VOLUME_WHEN_PLAY
            aud_set_active_ring_tone_volume();
        #endif 
            /* start to play */
            Media_Play((Media_Format) aud_context_p->vm_sp_type, aud_vm_play_callback, MEDIA_VMP_AS_RINGTONE);

            /* send confirm message to L4 */
            aud_send_vm_resume_cnf(MED_RES_OK);

            /* play as memo */
            aud_context_p->play_mode = AUD_VM_PLAY_AS_MEMO;

            /* enter AUD_VM_PLAY state */
            AUD_ENTER_STATE(AUD_VM_PLAY);

            break;
        }
        default:
        {

            aud_send_vm_resume_cnf(MED_RES_FAIL);
            break;
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_append_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_append_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnf_result;
    l4aud_vm_append_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_APPEND_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_append_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    if (aud_context_p->media_playing)
    {
        /* send confirm message to L4 */
        aud_send_vm_play_cnf(MED_RES_BUSY);
        return;
    }

    if (aud_context_p->state == AUD_VM_IDLE)
    {
        if (aud_context_p->disc_full)
        {
            /* send confirm message to l4 */
            cnf_result = MED_RES_DISC_FULL;
        }
        else if (aud_vm_check_existing_file_name((kal_wchar*) msg_p->file_name))
        {
            /* open the file */
            kal_wchar full_name[FULL_NAME_LEN];

            kal_wsprintf(full_name, "%w\\%w", VM_DIR, (kal_wchar*) msg_p->file_name);
            aud_context_p->current_file_handle = FS_Open(full_name, FS_READ_WRITE | FS_OPEN_NO_DIR);

            if (aud_context_p->current_file_handle >= 0)
            {
                FS_GetFileSize(aud_context_p->current_file_handle, &aud_context_p->offset);
                /* seek to end of file */
                FS_Seek(aud_context_p->current_file_handle, 0, FS_FILE_END);

                /* call L1AUD to set buffer */
                Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);

                /* start to record */
                Media_Record((Media_Format) aud_context_p->vm_sp_type, aud_vm_record_callback, NULL);

                cnf_result = MED_RES_OK;

                /* enter AUD_VM_RECORD state */
                AUD_ENTER_STATE(AUD_VM_RECORD);

            }
            else if (aud_context_p->disc_full || aud_context_p->current_file_handle == FS_DISK_FULL)
            {
                aud_context_p->disc_full = KAL_TRUE;
                /* send confirm message to l4 */
                cnf_result = MED_RES_DISC_FULL;
            }
            else if (aud_context_p->current_file_handle == FS_TOO_MANY_FILES)
            {
                cnf_result = MED_RES_BUSY;
            }
            else
            {
                cnf_result = MED_RES_OPEN_FILE_FAIL;
            }
        }
        else
        {
            cnf_result = MED_RES_OPEN_FILE_FAIL;
        }
    }
    else
    {
        cnf_result = MED_RES_BUSY;
    }
    /* send confirm message to l4 */
    aud_send_vm_append_cnf(cnf_result);

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_rename_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_rename_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cnf_result;

    l4aud_vm_rename_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_RENAME_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_rename_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    switch (aud_context_p->state)
    {
        case AUD_VM_IDLE:
        {
            /* refresh file list */
            aud_vm_scan_file();

            cnf_result = aud_vm_change_file_name((kal_wchar*) msg_p->old_file_name, (kal_wchar*) msg_p->new_file_name);
            break;
        }
        default:
            cnf_result = MED_RES_BUSY;
    }
    /* send confirm message to L4 */
    aud_send_vm_rename_cnf(cnf_result);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_get_info_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_get_info_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    l4aud_vm_get_info_req_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_GET_INFO_REQ_HDLR) aud_context_p->src_mod = ilm_ptr->src_mod_id;

    msg_p = (l4aud_vm_get_info_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->src_id = msg_p->src_id;

    /* scan all vm files in FS */
    aud_vm_scan_file();

    /* send confirm message to L4 */
    aud_send_vm_get_info_cnf();

}

#ifndef VM_LOG


/*****************************************************************************
 * FUNCTION
 *  aud_vm_read_data_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_read_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_READ_DATA_IND_HDLR)
        Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));

#ifdef _WIN32
    aud_context_p->buf_len = 200;
#endif 

    ASSERT(aud_context_p->buf_p != NULL);

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        {
            result = FS_Write(
                        aud_context_p->current_file_handle,
                        aud_context_p->buf_p,
                        aud_context_p->buf_len * 2,
                        &len);
            /* update offset */
            aud_context_p->offset += len;

            AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1)
                if (result == FS_NO_ERROR && aud_context_p->offset < aud_context_p->vm_info.free_space)
            {
                aud_context_p->buf_len = (kal_uint32) (len >> 1);
                Media_ReadDataDone(aud_context_p->buf_len);
            }
            else
            {
                /* inform L1AUD to stop recording process */
                Media_Stop();

                result = FS_Close(aud_context_p->current_file_handle);

                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->vm_info.free_space, aud_context_p->disc_full)
                    if (aud_context_p->offset == 0)
                {
                    result = FS_Delete(aud_context_p->current_file_name);
                    /* send indication message to L4 */
                    aud_send_vm_record_finish_ind(MED_RES_DISC_FULL, aud_context_p->current_file_name);
                }
                else
                    /* send indication message to L4 */
                {
                    aud_send_vm_record_finish_ind(MED_RES_DISC_FULL, aud_context_p->current_file_name);
                }

                /* enter AUD_VM_IDLE state */
                aud_context_p->state = AUD_VM_IDLE;
                AUD_STATE_TRACE(aud_context_p->state)
                    /* reset current vm id */
                    aud_context_p->current_file_handle = -1;
                /* set disc full to TRUE */
                aud_context_p->disc_full = KAL_TRUE;
            }
            break;
        }
        default:
        {
            break;
        }
    }

}
#else /* VM_LOG */ 


/*****************************************************************************
 * FUNCTION
 *  aud_vm_get_file_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_get_file_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar full_name[20];
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!aud_context_p->vm_logging)
    {
        return;
    }
    if (aud_context_p->offset < MAX_VM_LOG_LEN)
    {
        return;
    }

    /* To check the file size consistency */
    FS_GetFileSize(aud_context_p->current_file_handle, &len);
    AUD_VALUE_TRACE(aud_context_p->vm_id, aud_context_p->offset, len) FS_Close(aud_context_p->current_file_handle);

    kal_wsprintf(full_name, "%w\\log%d.vm", VM_DIR, (aud_context_p->vm_id + 2) % 3);
    FS_Delete(full_name);

    aud_context_p->vm_id++;
    if (aud_context_p->vm_id >= 3)
    {
        aud_context_p->vm_id = 0;
    }

    kal_wsprintf(full_name, "%w\\log%d.vm", VM_DIR, aud_context_p->vm_id);
    aud_context_p->current_file_handle = FS_Open(full_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (aud_context_p->current_file_handle >= 0)
    {
        /* reset offset */
        aud_context_p->offset = 0;

        /* enter AUD_VM_RECORD state */
        AUD_ENTER_STATE(AUD_VM_RECORD);
    AUD_VALUE_TRACE(aud_context_p->vm_id, aud_context_p->offset, -1)}
    else
    {
        /* Stop voice memo recording process */
        Media_Stop();

        /* enter AUD_VM_IDLE state */
        aud_context_p->state = AUD_VM_IDLE;
    AUD_STATE_TRACE(aud_context_p->state)}

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_stop_logging
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_stop_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        {
            /* Stop voice memo recording process */
            Media_Stop();
            aud_context_p->vm_logging = KAL_FALSE;

            Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
            result = FS_Write(
                        aud_context_p->current_file_handle,
                        aud_context_p->buf_p,
                        aud_context_p->buf_len * 2,
                        &len);

            /* update offset */
            aud_context_p->offset += len;

            AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1)
                FS_Close(aud_context_p->current_file_handle);

            /* change to AUD_VM_IDLE state */
            AUD_ENTER_STATE(AUD_VM_IDLE);
            break;
        }
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_start_logging
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_start_logging(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar full_name[20];
    Media_Status result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->vm_id++;
    if (aud_context_p->vm_id >= 3)
    {
        aud_context_p->vm_id = 0;
    }

    kal_wsprintf(full_name, "%w\\log%d.vm", VM_DIR, (aud_context_p->vm_id + 1) % 3);
    FS_Delete(full_name);

    kal_wsprintf(full_name, "%w\\log%d.vm", VM_DIR, aud_context_p->vm_id);
    aud_context_p->current_file_handle = FS_Open(full_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (aud_context_p->current_file_handle >= 0)
    {
        /* call L1AUD to set buffer */
        Media_SetBuffer(aud_context_p->ring_buf, AUD_RING_BUFFER_LEN);

        aud_context_p->vm_logging = KAL_TRUE;

        /* start to record */
        result = Media_Record((Media_Format) aud_context_p->vm_sp_type, aud_vm_record_callback, NULL);

        /* reset offset */
        aud_context_p->offset = 0;

        aud_context_p->current_format = MED_TYPE_GSM_EFR;

        /* enter AUD_VM_RECORD state */
        AUD_ENTER_STATE(AUD_VM_RECORD);
    AUD_VALUE_TRACE(aud_context_p->vm_id, aud_context_p->offset, result)}
}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_read_data_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_read_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_READ_DATA_IND_HDLR)
        Media_GetReadBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));

#ifdef _WIN32
    aud_context_p->buf_len = 200;
#endif 

    ASSERT(aud_context_p->buf_p != NULL);

    switch (aud_context_p->state)
    {
        case AUD_VM_RECORD:
        {
            aud_vm_get_file_handle();

            result = FS_Write(
                        aud_context_p->current_file_handle,
                        aud_context_p->buf_p,
                        aud_context_p->buf_len * 2,
                        &len);
            /* update offset */
            aud_context_p->offset += len;

            AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1) if (result == FS_NO_ERROR)
            {
                aud_context_p->buf_len = (kal_uint32) (len >> 1);
                Media_ReadDataDone(aud_context_p->buf_len);
            }
            else
            {
                /* inform L1AUD to stop recording process */
                Media_Stop();

                result = FS_Close(aud_context_p->current_file_handle);

                if (aud_context_p->offset == 0)
                {
                    result = FS_Delete(aud_context_p->current_file_name);
                    /* send indication message to L4 */
                    aud_send_vm_record_finish_ind(MED_RES_DISC_FULL, aud_context_p->current_file_name);
                }
                else
                    /* send indication message to L4 */
                {
                    aud_send_vm_record_finish_ind(MED_RES_DISC_FULL, aud_context_p->current_file_name);
                }

                /* enter AUD_VM_IDLE state */
                aud_context_p->state = AUD_VM_IDLE;
                AUD_STATE_TRACE(aud_context_p->state)
                    /* reset current vm id */
                    aud_context_p->current_file_handle = -1;

                aud_context_p->disc_full = KAL_TRUE;
            }
            break;
        }
        default:
        {
            break;
        }
    }

}

#endif /* VM_LOG */ 


/*****************************************************************************
 * FUNCTION
 *  aud_vm_write_data_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_write_data_ind_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    aud_vm_write_data_ind_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VM_WRITE_DATA_IND_HDLR) msg_p = (aud_vm_write_data_ind_struct*) ilm_ptr->local_para_ptr;

    switch (aud_context_p->state)
    {
        case AUD_VM_PLAY:
        {

            if ((msg_p->event == MEDIA_TERMINATED || msg_p->event == MEDIA_END))
            {

                /* send play finished indication to L4 */
                if (aud_context_p->play_mode != AUD_VM_PLAY_AS_RING)
                {
                    aud_send_vm_play_finish_ind(MED_RES_END_OF_FILE);
                }

                /* enter AUD_VM_IDLE state */
                aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state)}
            else
            {
                kal_uint32 len;

                Media_GetWriteBuffer(&(aud_context_p->buf_p), (kal_uint32*) & (aud_context_p->buf_len));
                ASSERT(aud_context_p->buf_p != NULL);

            #ifdef _WIN32
                aud_context_p->buf_len = 200;
            #endif 
                /* read data from file to buffer */
                FS_Read(aud_context_p->current_file_handle, aud_context_p->buf_p, aud_context_p->buf_len * 2, &len);

                /* update offset */
                aud_context_p->offset += len;

                AUD_VALUE_TRACE(aud_context_p->offset, aud_context_p->buf_len, len >> 1) len = len >> 1;
                ASSERT(len <= aud_context_p->buf_len);
                if (len == 0)
                {
                    /* Stop play */
                    Media_DataFinished();

                    /* close the file */
                    FS_Close(aud_context_p->current_file_handle);

                    /* enter AUD_VM_PLAY_FINISH state */
                    AUD_ENTER_STATE(AUD_VM_PLAY_FINISH);
                }
                else if (len < aud_context_p->buf_len)
                {
                    aud_context_p->buf_len = len;

                    /* inform L1AUD the amount of data read from file to ring buffer */
                    Media_WriteDataDone(len);

                    Media_DataFinished();

                    /* close the file */
                    FS_Close(aud_context_p->current_file_handle);

                    /* enter AUD_VM_PLAY_FINISH state */
                    AUD_ENTER_STATE(AUD_VM_PLAY_FINISH);
                }
                else
                {
                    /* inform L1AUD the amount of data read from file to ring buffer */
                    Media_WriteDataDone(len);

                    /* play as memo */
                    /* aud_context_p->play_mode = AUD_VM_PLAY_AS_MEMO; */

                }
            }
            break;
        }
        case AUD_VM_PLAY_FINISH:
        {

            /* if not the terminated, stop again */
            if ((msg_p->event == MEDIA_TERMINATED || msg_p->event == MEDIA_END))
            {
                /* send play finished indication to L4 */
                if (aud_context_p->play_mode != AUD_VM_PLAY_AS_RING)
                {
                    aud_send_vm_play_finish_ind(MED_RES_END_OF_FILE);
                }

                /* enter AUD_VM_IDLE state */
                aud_context_p->state = AUD_VM_IDLE;
            AUD_STATE_TRACE(aud_context_p->state)}
            break;
        }
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  aud_vm_main
 * DESCRIPTION
 *  This function is main function of aud_vm module
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vm_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_L4AUD_VM_RECORD_REQ:
            aud_vm_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_PLAY_REQ:
            aud_vm_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_STOP_REQ:
            aud_vm_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_DELETE_REQ:
            aud_vm_delete_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_ABORT_REQ:
            aud_vm_abort_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_PAUSE_REQ:
            aud_vm_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_RESUME_REQ:
            aud_vm_resume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_APPEND_REQ:
            aud_vm_append_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_GET_INFO_REQ:
            aud_vm_get_info_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_L4AUD_VM_RENAME_REQ:
            aud_vm_rename_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_AUD_VM_READ_DATA_IND:
            aud_vm_read_data_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_AUD_VM_WRITE_DATA_IND:
            aud_vm_write_data_ind_hdlr(ilm_ptr);
            break;
    }

}

#endif /* defined(VM_SUPPORT) && defined(VM_LOG) */ 

#endif /* MED_NOT_PRESENT */ 

