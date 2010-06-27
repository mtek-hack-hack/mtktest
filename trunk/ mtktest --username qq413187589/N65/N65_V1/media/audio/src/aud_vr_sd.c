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
 * aud_vr_sd.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes vr sd service functions
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

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/
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
#include "fat_fs.h"
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_equipment.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#ifdef __MED_VR_MOD__
static const kal_uint16 *hex_0_9_digits = L"0123456789";
static const kal_uint16 *hex_a_f_digits = L"abcdef";
static const kal_uint16 *hex_A_F_digits = L"ABCDEF";
aud_vr_sd_context_struct vr_sd_ctx;

extern aud_vr_context_struct vr_ctx;


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_find_word_id
 * DESCRIPTION
 *  vr sd find the index of a word id
 * PARAMETERS
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_find_word_id(kal_uint16 group_id, kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 id_length = vr_sd_ctx.id_length[group_id];
    kal_uint16 *id_array = vr_sd_ctx.id_array[group_id];
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < id_length; i++)
    {
        if (id_array[i] == word_id)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_extract_group_id
 * DESCRIPTION
 *  vr sd parse and extract the group id (a decimal integer) from the assigned folder name (without path)
 * PARAMETERS
 *  filename        [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_extract_group_id(kal_uint16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *p;
    kal_uint16 digit_char;
    kal_int32 result;
    kal_int32 filename_len = kal_wstrlen(filename);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_len < 1)
    {
        return -1;
    }

    for (result = 0; *filename; filename++)
    {
        digit_char = *filename;
        if ((p = kal_wstrchr(hex_0_9_digits, (int)digit_char)) != NULL)
        {
            result = (result * 10) + (p - hex_0_9_digits);
        }
        else
        {
            return -1;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_extract_word_id
 * DESCRIPTION
 *  vr sd parse and extract the word id (a hexadecimal integer) from the assigned folder name (without path)
 * PARAMETERS
 *  filename        [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_extract_word_id(kal_uint16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *p;
    kal_uint16 digit_char, i, j;
    kal_int32 result;
    kal_int32 filename_len = kal_wstrlen(filename);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_len < 8)
    {
        return -1;
    }

    for (result = 0, i = 0, j = filename_len - 8; i < 4; i++, j++)
    {
        digit_char = filename[j];
        if ((p = kal_wstrchr(hex_0_9_digits, (int)digit_char)) != NULL)
        {
            result = (result << 4) + (p - hex_0_9_digits);
        }
        else if ((p = kal_wstrchr(hex_a_f_digits, (int)digit_char)) != NULL)
        {
            result = (result << 4) + (p - hex_a_f_digits + 10);
        }
        else if ((p = kal_wstrchr(hex_A_F_digits, (int)digit_char)) != NULL)
        {
            result = (result << 4) + (p - hex_A_F_digits + 10);
        }
        else
        {
            return -1;
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_scan_tags_in_group_folder
 * DESCRIPTION
 *  vr sd scan all tags in a group folder
 * PARAMETERS
 *  group_id        [IN]        
 *  path            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_scan_tags_in_group_folder(kal_uint16 group_id, kal_uint16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 filename[VR_MAX_DB_PATH_LEN + 1];
    kal_uint16 filename_expr[VR_MAX_DB_PATH_LEN + 1];
    kal_int32 word_id;
    FS_HANDLE fd_cursor;
    FS_DOSDirEntry file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vr_sd_ctx.id_length[group_id] = 0;
    kal_wsprintf(filename_expr, "%wMTKVR_????.vrd", path);

    if ((fd_cursor = FS_FindFirst(filename_expr, 0, 0, &file_info, filename, (VR_MAX_DB_PATH_LEN + 1) << 1)) >= 0)
    {
        /* loop through all vrd files in a group folder */
        do
        {
            /* filter out folder results */
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                /* parse word id and add to id array and increment id length */
                if ((word_id = aud_vr_sd_extract_word_id(filename)) >= 0)
                {
                    vr_sd_ctx.id_array[group_id][vr_sd_ctx.id_length[group_id]++] = word_id;
                }
            }
        } while (FS_FindNext(fd_cursor, &file_info, filename, (VR_MAX_DB_PATH_LEN + 1) << 1) == FS_NO_ERROR);
        FS_FindClose(fd_cursor);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_filter_out_not_exist_tags
 * DESCRIPTION
 *  vr sd scan all tags in a group id array and remove non-existing tag ids from the array
 * PARAMETERS
 *  group_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_filter_out_not_exist_tags(kal_uint16 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    kal_wchar file_name[VR_MAX_DB_PATH_LEN + 1];
    kal_uint32 i, count;
    kal_uint16 *id_array = vr_sd_ctx.id_array[group_id];
    kal_uint16 id_len = vr_sd_ctx.id_length[group_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* loop through id array */
    for (i = count = 0; i < id_len; i++)
    {
        /* check does each tag file exist */
        kal_wsprintf(file_name, "%wMTKVR_%04x.vrd", vr_ctx.db_path, id_array[i]);
        if ((file_handle = FS_Open(file_name, FS_READ_ONLY | FS_NOBUSY_CHECK_MODE)) >= 0)
        {
            FS_Close(file_handle);
            id_array[count++] = id_array[i];
        }
    }

    /* update id length to the number of exisiting tag files in id array */
    if (count != id_len)
    {
        vr_sd_ctx.id_length[group_id] = count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_delete_one_tag
 * DESCRIPTION
 *  vr sd delete a tag id with its file and its id in the array
 * PARAMETERS
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_vr_sd_delete_one_tag(kal_uint16 group_id, kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 *id_length_p = &vr_sd_ctx.id_length[group_id];
    kal_uint16 *id_array = vr_sd_ctx.id_array[group_id];
    kal_int32 i, j;
    kal_wchar filename[VR_MAX_DB_PATH_LEN + 1];
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the index of word id in id array */
    if ((j = aud_vr_sd_find_word_id(group_id, word_id)) >= 0)
    {
        /* delete tag file */
        kal_wsprintf(filename, "%c:\\VRDB\\ISD\\%d\\MTKVR_%04x.vrd", (kal_uint8) vr_ctx.db_drive, group_id, word_id);
        if (FS_Delete(filename) == FS_NO_ERROR)
        {
            /* left shift rest word ids in id array */
            (*id_length_p)--;
            for (i = j; i < *id_length_p; i++)
            {
                id_array[i] = id_array[i + 1];
            }
            result = KAL_TRUE;
        }
        else
        {
            result = KAL_FALSE;
        }
    }
    else
    {
        result = KAL_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_rcg_callback
 * DESCRIPTION
 *  vr sd recognition call back function, send a message to media task itself and process then
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_rcg_callback(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_VR_RCG_PROCESS_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_trn_callback
 * DESCRIPTION
 *  vr sd training call back function, send a message to media task itself and process then
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_trn_callback(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_send_ilm(MOD_MED, MSG_ID_MEDIA_VR_TRN_PROCESS_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_rcg_process
 * DESCRIPTION
 *  vr sd recognition call back process function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_rcg_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 med_res;
    kal_uint16 id_array[VR_MAX_RCG_RESULT_NUM];
    kal_uint16 id_length = 0;
    VR_Result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_VOICE_IN_RCG_CALLBACK);

    if (vr_ctx.state != AUD_VR_STATE_RCG_SESSION)
        return;

    result = VR_Process(&vr_ctx.word_id);

    AUD_VALUE_TRACE(result, vr_ctx.state, vr_sd_ctx.stage);

    switch (result)
    {
        case VR_OK:
            return;
        case VR_NO_SOUND:
            med_res = MED_RES_NO_SOUND;
            aud_vr_sd_abort();
            break;
        case VR_TOO_LONG:
            med_res = MED_RES_SPEAK_TOO_LONG;
            aud_vr_sd_abort();
            break;
        case VR_TOO_SHORT:
            med_res = MED_RES_SPEAK_TOO_SHORT;
            aud_vr_sd_abort();
            break;
        case VR_FAILED:
            med_res = MED_RES_NO_MATCH;
            aud_vr_sd_abort();
            break;
        case VR_FINISHED:
            med_res = MED_RES_OK;
            id_array[0] = vr_ctx.word_id;
            id_length = 1;
            med_free_ext_mem((void **)&vr_sd_ctx.buffer);
            /* finish a session naturely */
            vr_ctx.state = AUD_VR_STATE_IDLE;
            vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_NOT_READY;
            break;
        default:    /* other error cases */
            med_res = MED_RES_FAIL;
            aud_vr_sd_abort();
            break;
    }

    aud_send_vr_rcg_result_ind(vr_ctx.src_mod, vr_ctx.session_id, med_res, id_length, id_array);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_trn_process
 * DESCRIPTION
 *  vr sd training call back process function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_trn_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 med_res;
    VR_Result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_VOICE_IN_TRN_CALLBACK);

    if (vr_ctx.state != AUD_VR_STATE_TRN_SESSION)
        return;

    result = VR_Process(&vr_ctx.word_id);

    AUD_VALUE_TRACE(result, vr_ctx.state, vr_sd_ctx.stage);

    switch (result)
    {
        case VR_OK:
            return;
        case VR_NO_SOUND:
            med_res = MED_RES_NO_SOUND;
            aud_vr_sd_abort();
            break;
        case VR_TOO_DIFF:
            med_res = MED_RES_TOO_DIFFERENT;
            aud_vr_sd_abort();
            break;
        case VR_TOO_SIM:
            med_res = MED_RES_TOO_SIMILAR;
            aud_vr_sd_abort();
            break;
        case VR_FLASH_DISK_FULL:
            med_res = MED_RES_DISC_FULL;
            aud_vr_sd_abort();
            break;
        case VR_FLASH_ERROR:
            med_res = MED_RES_FAIL;
            aud_vr_sd_abort();
            break;
        case VR_TOO_LONG:
            med_res = MED_RES_SPEAK_TOO_LONG;
            aud_vr_sd_abort();
            break;
        case VR_TOO_SHORT:
            med_res = MED_RES_SPEAK_TOO_SHORT;
            aud_vr_sd_abort();
            break;
        case VR_FAILED:
            med_res = MED_RES_FAIL;
            aud_vr_sd_abort();
            break;
        case VR_CONTINUE:
            med_res = MED_RES_TRAINING_CONTINUE;
            vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_WAIT;
            break;
        case VR_FINISHED:
            med_res = MED_RES_OK;
            if (aud_vr_sd_find_word_id(vr_ctx.group_id, vr_ctx.word_id) < 0)
            {
                vr_sd_ctx.id_array[vr_ctx.group_id][vr_sd_ctx.id_length[vr_ctx.group_id]++] = vr_ctx.word_id;
            }
            med_free_ext_mem((void **)&vr_sd_ctx.buffer);
            /* finish a session naturely */
            vr_ctx.state = AUD_VR_STATE_IDLE;
            vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_NOT_READY;
            break;
        default:    /* other error cases */
            med_res = MED_RES_FAIL;
            aud_vr_sd_abort();
            break;
    }

    aud_send_vr_trn_result_ind(vr_ctx.src_mod, vr_ctx.session_id, med_res);
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_startup
 * DESCRIPTION
 *  initialize vr sd module
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool aud_vr_sd_startup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 filename[VR_MAX_DB_PATH_LEN + 1];
    kal_uint16 filepath[VR_MAX_DB_PATH_LEN + 1];
    kal_int32 group_id;
    FS_HANDLE fd_cursor;
    FS_DOSDirEntry file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vr_sd_ctx.buffer = NULL;
    vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_NOT_READY;
    kal_mem_set(vr_sd_ctx.id_length, 0, VR_SD_MAX_GROUP_NUM << 1);
    kal_wsprintf(filepath, "%c:\\VRDB\\ISD\\*", (kal_uint8) vr_ctx.db_drive);

#ifdef __NVRAM_IN_USB_MS__
    if (stack_query_boot_mode() == USBMS_BOOT)
    {
        return KAL_FALSE;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    if ((fd_cursor = FS_FindFirst(filepath, 0, 0, &file_info, filename, (VR_MAX_DB_PATH_LEN + 1) << 1)) >= 0)
    {
        /* loop through each group folder */
        do
        {
            /* filter out non-folder results */
            if (file_info.Attributes & FS_ATTR_DIR)
            {
                /* parse group id */
                if ((group_id = aud_vr_sd_extract_group_id(filename)) >= 0)
                {
                    /* scan all tag files in each group folder */
                    kal_wsprintf(filepath, "%c:\\VRDB\\ISD\\%d\\", (kal_uint8) vr_ctx.db_drive, group_id);
                    aud_vr_sd_scan_tags_in_group_folder((kal_uint16) group_id, filepath);
                }
            }
        } while (FS_FindNext(fd_cursor, &file_info, filename, (VR_MAX_DB_PATH_LEN + 1) << 1) == FS_NO_ERROR);
        FS_FindClose(fd_cursor);
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_init_rcg
 * DESCRIPTION
 *  vr sd initialize a recognition session
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_init_rcg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 buff_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vr_ctx.state != AUD_VR_STATE_IDLE)
    {
        return MED_RES_BUSY;
    }

    /* scan and filter out non-exisiting tag files in id array */
    aud_vr_sd_filter_out_not_exist_tags(vr_ctx.group_id);

    /* detect memory leakage */
    ASSERT(vr_sd_ctx.buffer == NULL);

    /* get buffer size and alloc buffer */
    buff_size = VR_GetBufferSize();
    if ((vr_sd_ctx.buffer = (kal_uint8*) med_alloc_ext_mem(buff_size)) == NULL)
    {
        return MED_RES_MEM_INSUFFICIENT;
    }
    VR_SetBuffer(vr_sd_ctx.buffer);

    /* set database dir */
    VR_SetDatabaseDir((kal_uint8*) vr_ctx.db_path);

    /* start a session */
    vr_ctx.state = AUD_VR_STATE_RCG_SESSION;
    vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_READY;

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_init_trn
 * DESCRIPTION
 *  vr sd initialize a training session
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_init_trn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 buff_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vr_ctx.state != AUD_VR_STATE_IDLE)
    {
        return MED_RES_BUSY;
    }

    /* scan and filter out non-exisiting tag files in id array */
    aud_vr_sd_filter_out_not_exist_tags(vr_ctx.group_id);
    /*
     * if( aud_vr_sd_find_word_id( vr_ctx.group_id, vr_ctx.word_id ) >= 0 )
     * return MED_RES_ID_EXIST;
     */
    /* detect memory leakage */
    ASSERT(vr_sd_ctx.buffer == NULL);

    /* get buffer size and alloc buffer */
    buff_size = VR_GetBufferSize();
    if ((vr_sd_ctx.buffer = (kal_uint8*) med_alloc_ext_mem(buff_size)) == NULL)
    {
        return MED_RES_MEM_INSUFFICIENT;
    }
    VR_SetBuffer(vr_sd_ctx.buffer);

    /* set database dir */
    VR_SetDatabaseDir((kal_uint8*) vr_ctx.db_path);

    /* start a session */
    vr_ctx.state = AUD_VR_STATE_TRN_SESSION;
    vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_READY;

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_rcg_voice_in
 * DESCRIPTION
 *  vr sd voice in notification in a recognition session
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_rcg_voice_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_SD_RCG_VOICE_IN_REQ_HDLR);
    AUD_VALUE_TRACE(vr_ctx.state, vr_sd_ctx.stage, -1);

    if (vr_sd_ctx.stage == AUD_VR_SD_SESSION_STAGE_READY)
    {
        if (VR_RCG_Start(
                vr_sd_ctx.id_array[vr_ctx.group_id],
                &vr_sd_ctx.id_length[vr_ctx.group_id],
                aud_vr_sd_rcg_callback) == VR_OK)
        {
            result = MED_RES_OK;
            vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_PROCESS;
        }
        else
        {
            result = MED_RES_FAIL;
            aud_vr_sd_abort();
        }
    }
    else
    {
        result = MED_RES_FAIL;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_trn_voice_in
 * DESCRIPTION
 *  vr sd voice in notification in a training session
 * PARAMETERS
 *  seq_no      [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_trn_voice_in(kal_uint8 seq_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result, i, j;
    kal_uint16 *word_id_list_p;
    kal_uint16 word_id_list[VR_SD_MAX_GROUP_TAG_NUM];
    kal_uint16 word_id_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_VR_SD_TRN_VOICE_IN_REQ_HDLR);
    AUD_VALUE_TRACE(vr_ctx.state, vr_sd_ctx.stage, seq_no);

    if (vr_sd_ctx.stage == AUD_VR_SD_SESSION_STAGE_READY && seq_no == 0)
    {
        /* copy word id list except the training word id */
        word_id_list_p = vr_sd_ctx.id_array[vr_ctx.group_id];
        word_id_length = vr_sd_ctx.id_length[vr_ctx.group_id];
        for (j = 0, i = word_id_length - 1; i >= 0; i--)
        {
            if (word_id_list_p[i] == vr_ctx.word_id)
            {
                word_id_length--;
            }
            else
            {
                word_id_list[j++] = word_id_list_p[i];
            }
        }
        /* 1st training sample */
        if (VR_TRA_Start(vr_ctx.word_id, word_id_list, &word_id_length, aud_vr_sd_trn_callback) == VR_OK)
        {
            result = MED_RES_OK;
            vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_PROCESS;
        }
        else
        {
            result = MED_RES_FAIL;
            aud_vr_sd_abort();
        }
    }
    else if (vr_sd_ctx.stage == AUD_VR_SD_SESSION_STAGE_WAIT && seq_no == 1)
    {
        /* 2nd training sample */
        if (VR_TRA2Start() == VR_OK)
        {
            result = MED_RES_OK;
            vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_PROCESS_2ND;
        }
        else
        {
            result = MED_RES_FAIL;
            aud_vr_sd_abort();
        }
    }
    else
    {
        result = MED_RES_FAIL;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_sync_db
 * DESCRIPTION
 *  vr sd sync database
 * PARAMETERS
 *  group_id        [IN]        
 *  id_length_p     [?]         
 *  id_array        [?]         
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_sync_db(kal_uint16 group_id, kal_uint16 *id_length_p, kal_uint16 *id_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool found;
    kal_int32 i, j, id_length;
    kal_uint16 *target_list = vr_sd_ctx.id_array[group_id];
    kal_uint16 *target_length_p = &(vr_sd_ctx.id_length[group_id]);
    kal_wchar filename[VR_MAX_DB_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* eliminate tags which found in source list, but not in target list or its file doesn't exist */
    for (i = id_length = 0; i < *id_length_p; i++)
    {
        if (aud_vr_sd_find_word_id(group_id, id_array[i]) >= 0)
        {
            id_array[id_length++] = id_array[i];
        }
    }
    *id_length_p = id_length;

    if (id_length != *target_length_p)
    {
        /* delete tag files whose id not in target list */
        for (i = 0; i < *target_length_p; i++)
        {
            found = KAL_FALSE;
            for (j = 0; j < id_length; j++)
            {
                if (id_array[j] == target_list[i])
                {
                    found = KAL_TRUE;
                    break;
                }
            }
            if (!found)
            {
                /* delete tag file */
                kal_wsprintf(
                    filename,
                    "%c:\\VRDB\\ISD\\%d\\MTKVR_%04x.vrd",
                    (kal_uint8) vr_ctx.db_drive,
                    group_id,
                    target_list[i]);
                FS_Delete(filename);
            }
        }

        /* copy id_array to target list and update target id length */
        *target_length_p = id_length;
        if (id_length > 0)
        {
            memcpy(target_list, id_array, id_length << 1);
        }
    }

    return MED_RES_OK;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_delete_tag
 * DESCRIPTION
 *  vr sd delete tag
 * PARAMETERS
 *  group_id        [IN]        
 *  word_id         [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_delete_tag(kal_uint16 group_id, kal_uint16 word_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool done;
    kal_uint16 *id_length_p = &vr_sd_ctx.id_length[group_id];
    kal_uint16 *id_array = vr_sd_ctx.id_array[group_id];
    kal_uint16 id_list[VR_SD_MAX_GROUP_TAG_NUM];
    kal_uint16 i, count;
    kal_int32 result = MED_RES_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (word_id == 0xFFFF)  /* delete all */
    {
        if (*id_length_p > 0)
        {
            /* bcoz we need to delete tags in id array, we'd better copy id array to another array and loop throgh it */
            count = *id_length_p;
            memcpy(id_list, id_array, count << 1);
            done = KAL_TRUE;
            for (i = 0; i < count; i++)
            {
                if (!aud_vr_sd_delete_one_tag(group_id, id_list[i]))
                {
                    done = KAL_FALSE;
                }
            }
            if (done)
            {
                result = MED_RES_OK;
            }
        }
        else
        {
            result = MED_RES_OK;
        }
    }
    else    /* delete one */
    {
        if (aud_vr_sd_delete_one_tag(group_id, word_id))
        {
            result = MED_RES_OK;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_add_tag
 * DESCRIPTION
 *  vr sd add tags
 * PARAMETERS
 *  group_id        [IN]        
 *  cid_array       [?]         
 *  cid_length      [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_add_tag(kal_uint16 group_id, kal_uint16 *cid_array, kal_uint16 cid_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    kal_wchar filename[VR_MAX_DB_PATH_LEN + 1];
    kal_uint16 *id_length_p = &vr_sd_ctx.id_length[group_id];
    kal_uint16 *id_array = vr_sd_ctx.id_array[group_id];
    kal_uint16 i, j;
    kal_int32 result = MED_RES_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* loop through src id array */
    for (i = 0; i < cid_length; i++)
    {
        /* try to find the corresponding index in target id array */
        for (j = 0; j < *id_length_p; j++)
        {
            if (id_array[j] == cid_array[i])
            {
                result = MED_RES_ID_EXIST;
                break;
            }
        }
        if (j == *id_length_p)  /* not found */
        {
            /* check does the tag file exist */
            kal_wsprintf(
                filename,
                "%c:\\VRDB\\ISD\\%d\\MTKVR_%04x.vrd",
                (kal_uint8) vr_ctx.db_drive,
                group_id,
                cid_array[i]);
            if ((file_handle = FS_Open(filename, FS_READ_ONLY | FS_NOBUSY_CHECK_MODE)) >= 0)
            {
                FS_Close(file_handle);
                id_array[(*id_length_p)++] = cid_array[i];
            }
            else
            {
                result = MED_RES_ID_MISMATCH;
            }
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_play_tag
 * DESCRIPTION
 *  vr sd play a tag
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 aud_vr_sd_play_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_wchar filename[VR_MAX_DB_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_context_p->speech_on)
    {
        result = MED_RES_BUSY;
    }
    else
    {
        aud_context_p->src_mod = vr_ctx.src_mod;
        aud_context_p->src_id = 0;
        aud_context_p->play_mode = AUD_MEDIA_PLAY_AS_SONG;
        aud_context_p->play_style = DEVICE_AUDIO_PLAY_ONCE;

        /* if keytone is playing, stop it */
        aud_keytone_stop();

        /* if tone is playing, stop it */
        if (aud_context_p->tone_playing)
        {
            aud_tone_stop();
        }

    #ifdef __MED_MMA_MOD__
        /* close all mma tasks */
        aud_mma_close_all();
    #endif /* __MED_MMA_MOD__ */ 

        if (aud_context_p->state != AUD_MEDIA_RECORD && aud_context_p->state != AUD_MEDIA_RECORD_PAUSED &&
            aud_context_p->state != AUD_VM_RECORD && aud_context_p->state != AUD_VM_RECORD_PAUSED)
        {
            aud_stop_unfinished_process();

            /* set volume and path */
            aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER_BOTH;
            aud_context_p->current_format = MED_TYPE_VR;
            kal_wsprintf(
                filename,
                "%c:\\VRDB\\ISD\\%d\\MTKVR_%04x.vrd",
                (kal_uint8) vr_ctx.db_drive,
                vr_ctx.group_id,
                vr_ctx.word_id);

            aud_context_p->source_type = AUD_FILE;
            aud_context_p->play_style = DEVICE_AUDIO_PLAY_ONCE;
            result = aud_media_play_file_stream(filename, DEVICE_AUDIO_PLAY_ONCE, 1, KAL_FALSE, NULL);
        }
        else
        {
            result = MED_RES_BUSY;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  aud_vr_sd_abort
 * DESCRIPTION
 *  vr sd abort a session
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_vr_sd_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VR_Stop();
    vr_ctx.state = AUD_VR_STATE_IDLE;
    vr_sd_ctx.stage = AUD_VR_SD_SESSION_STAGE_NOT_READY;
    if (vr_sd_ctx.buffer != NULL)
    {
        med_free_ext_mem((void **)&vr_sd_ctx.buffer);
    }
}

#endif /* __MED_VR_MOD__ */ 

#endif /* MED_NOT_PRESENT */ 

