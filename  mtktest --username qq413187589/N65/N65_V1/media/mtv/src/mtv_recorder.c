/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   mtv_recorder.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "med_global.h"

#if defined(__MED_MTV_MOD__)

#include "mtv_recorder.h"
#include "med_utility.h"
#include "med_trc.h"

#define MAKEFOURCC(ch0, ch1, ch2, ch3) \
    ((kal_uint32)(kal_uint8)(ch0) | (kal_uint32)(kal_uint8)(ch1) << 8 | \
     (kal_uint32)(kal_uint8)(ch2) << 16 | (kal_uint32)(kal_uint8)(ch3) << 24)

static void mtv_replace_invalid_chars(kal_wchar* str, const kal_wchar* invalid_chars, kal_wchar replacement)
{
    const kal_wchar* ic;
    kal_wchar* p;
    for (ic = invalid_chars; *ic != 0; ic++)
    {
        for (p = str; *p != 0; p++)
        {
            if (*p == *ic) {
                *p = replacement;
            }
        }
    }
}

static void mtv_recorder_delete_checkpoint(mtv_recorder_t* pthis)
{
    if (pthis->checkpoint != NULL)
    {
        FS_Delete(pthis->checkpoint);
        med_free_ext_mem((void**) &pthis->checkpoint);
    }
}

static mtv_recorder_state_t mtv_recorder_get_state(mtv_recorder_t* pthis)
{
    return pthis->state;
}

static void mtv_recorder_set_state(mtv_recorder_t* pthis, mtv_recorder_state_t new_state)
{
    pthis->state = new_state;
    if (pthis->client) {
        pthis->client->on_state_change(pthis->client, pthis->state);
    }
}

static mtv_result_t mtv_recorder_start(
    mtv_recorder_t* pthis,
    mtv_buffer_engine_t* be,
    mtv_recorder_client_t* client,
    kal_wchar* recording_name,
    mtv_recording_format_t recording_format)
{
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STARTING);

    if (pthis->state == MTV_RECORDER_STATE_SAVING) {
        return MTV_E_BUSY;
    }
    else if (pthis->state == MTV_RECORDER_STATE_STARTED) {
        return MTV_S_FALSE;
    }
    else if (pthis->state != MTV_RECORDER_STATE_STOPPED) {
        return MTV_E_WRONG_STATE;
    }

    pthis->client = client;

    ASSERT(be != NULL);
    pthis->be = be;

    /*
     * Increase the max size near to 2GB.
     */
    ret = be->set_max_buffer_size(pthis->be, MAX_RECORDING_SIZE);
    if (ret < 0) {
        return ret;
    }

    mtv_recorder_set_state(pthis, MTV_RECORDER_STATE_STARTED);

    pthis->recording_format = recording_format;
    ASSERT(recording_format != MTV_RECORDING_FORMAT_INVALID);

    kal_wstrcpy(pthis->recording_name, recording_name);
    mtv_replace_invalid_chars(pthis->recording_name, L"\\/:*?\"<>|", L'_');

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STARTED);
    return MTV_S_OK;
}

static mtv_result_t mtv_recorder_save(mtv_recorder_t* pthis, volatile kal_bool* aborted)
{
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_SAVING);

    if (pthis->state != MTV_RECORDER_STATE_STOPPED || pthis->be == NULL) {
        return MTV_E_WRONG_STATE;
    }

    mtv_recorder_set_state(pthis, MTV_RECORDER_STATE_SAVING);

    /* save the recording that may take a long time */
    ret = pthis->be->save(pthis->be, pthis->recording_format, pthis->recording_name, aborted);
    pthis->be = NULL; /* forget it after recording is saved */
    if (ret < 0)
    {
        mtv_recorder_set_state(pthis, MTV_RECORDER_STATE_STOPPED);

        MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_ERROR, ret);
        return ret;
    }

    /* discard the checkpoint if saving is successfull */
    mtv_recorder_delete_checkpoint(pthis);

    mtv_recorder_set_state(pthis, MTV_RECORDER_STATE_STOPPED);

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_SAVED);
    return MTV_S_OK;
}

static mtv_result_t mtv_recorder_stop(mtv_recorder_t* pthis)
{
    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STOPPING);

    if (pthis->state == MTV_RECORDER_STATE_SAVING) {
        return MTV_E_BUSY;
    }
    else if (pthis->state != MTV_RECORDER_STATE_STARTED) {
        return MTV_S_FALSE;
    }

    /* just change the state and do nothing */
    mtv_recorder_set_state(pthis, MTV_RECORDER_STATE_STOPPED);

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_STOPPED);
    return MTV_S_OK;
}

static mtv_result_t mtv_recorder_get_control(mtv_recorder_t* pthis, mtv_control_t control_id, void** control)
{
    if (control_id == MTV_CONTROL_RECORD)
    {
        *control = &pthis->record_ctrl;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t mtv_recorder_get_recorded_duration(mtv_control_record_t* control, kal_uint32* seconds)
{
    mtv_recorder_t* pthis = PTHIS(control, mtv_recorder_t, record_ctrl);
    mtv_result_t ret = MTV_S_OK;
    mtv_control_timeshift_t* timeshift_ctrl = NULL;

    if (pthis->state == MTV_RECORDER_STATE_STARTED)
    {
        ret = pthis->be->get_control(pthis->be, MTV_CONTROL_TIMESHIFT, (void**) &timeshift_ctrl);
        ASSERT(ret >= 0 && timeshift_ctrl != NULL);
        ret = timeshift_ctrl->get_buffer_status(timeshift_ctrl, seconds, NULL);
    }
    else
    {
        *seconds = 0;
    }

    return ret;
}

typedef struct
{
    kal_uint32 signature;
    kal_uint32 ver;
    mtv_recording_format_t recording_format;
    kal_wchar recording_name[MTV_MAX_SERVICE_NAME];

} checkpoint_header_t;

static void mtv_recorder_save_checkpoint_cleanup(void* param)
{
    cached_io_t* cio = (cached_io_t*) param;
    med_free_ext_mem((void**) &cio);
}

#define CHECKPOINT_CACHE_BLOCK_SIZE (2*1024)
#define CHECKPOINT_HEADER_SIG MAKEFOURCC('C', 'H', 'K', 'P')
#define CHECKPOINT_HEADER_VER 0x0001

static mtv_result_t mtv_recorder_save_checkpoint(mtv_recorder_t* pthis, kal_wchar* dir)
{
    cached_io_t* cio;
    kal_int32 ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_SAVING_CHECKPOINT);

    if (!pthis->checkpoint)
    {
        pthis->checkpoint = mtv_generate_new_filename(dir, CHECKPOINT_PREFIX, L"");
        ASSERT(pthis->checkpoint != NULL);
    }

    cio = (cached_io_t*) med_alloc_ext_mem(sizeof(cached_io_t));
    ret = cached_io_open(cio, pthis->checkpoint, FS_READ_WRITE | FS_CREATE_ALWAYS, CHECKPOINT_CACHE_BLOCK_SIZE);
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }
    else
    {
        checkpoint_header_t header = { CHECKPOINT_HEADER_SIG, CHECKPOINT_HEADER_VER };

        cached_io_set_async(cio);

        header.recording_format = pthis->recording_format;
        kal_wstrcpy(header.recording_name, pthis->recording_name);

        ret = cached_io_write(cio, &header, sizeof(header));
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            goto cleanup;
        }

        ret = pthis->be->save_checkpoint(pthis->be, cio);
        if (ret < 0) {
            goto cleanup;
        }
    }

cleanup:

    cached_io_close_async(cio, mtv_recorder_save_checkpoint_cleanup, cio);

    if (ret >= 0)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_CHECKPOINT_SAVED);
    }
    else
    {
        mtv_recorder_delete_checkpoint(pthis);
    }

    return ret;
}

static mtv_result_t mtv_recorder_recover_from_checkpoint(mtv_recorder_t* pthis, kal_wchar* cp_path, volatile kal_bool* aborted)
{
    cached_io_t cio;
    kal_int32 ret;
    mtv_buffer_engine_t* be = NULL;

    ASSERT(pthis->state == MTV_RECORDER_STATE_STOPPED);
    ASSERT(pthis->be == NULL);

    ret = cached_io_open(&cio, cp_path, FS_READ_ONLY, CHECKPOINT_CACHE_BLOCK_SIZE);
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }
    else
    {
        checkpoint_header_t header;

        ret = cached_io_read(&cio, &header, sizeof(header));
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            goto cleanup;
        }

        if (header.signature != CHECKPOINT_HEADER_SIG || header.ver != CHECKPOINT_HEADER_VER)
        {
            ret = MTV_E_FAIL;
            goto cleanup;
        }

        pthis->recording_format = header.recording_format;
        kal_wstrncpy(pthis->recording_name, header.recording_name, ARRAY_SIZE(pthis->recording_name)-1);

        /* create a new buffer engine to recover recording */
        be = construct_mtv_buffer_engine();
        ret = be->recover_from_checkpoint(be, &cio);
        if (ret < 0) {
            goto cleanup;
        }

        /* recover the file */
        pthis->be = be;
        ret = pthis->save(pthis, aborted);
    }

cleanup:

    cached_io_close(&cio);

    /* delete the checkpoint file no matter the recovery succeeded or not */
    FS_Delete(cp_path);

    if (be) {
        be->destroy(be);
    }

    return ret;
}

static void mtv_recorder_destroy(mtv_recorder_t* pthis)
{
    ASSERT(pthis != NULL);

    /* remove checkpoint if the recorder in destroyed in normal way */
    mtv_recorder_delete_checkpoint(pthis);

    med_free_ext_mem((void**) &pthis);
}

mtv_recorder_t* construct_mtv_recorder()
{
    mtv_recorder_t* pthis;

    pthis = (mtv_recorder_t*) med_alloc_ext_mem(sizeof(mtv_recorder_t));
    ASSERT(pthis);

    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->start = mtv_recorder_start;
    pthis->get_control = mtv_recorder_get_control;
    pthis->get_state = mtv_recorder_get_state;
    pthis->stop = mtv_recorder_stop;
    pthis->save = mtv_recorder_save;
    pthis->save_checkpoint = mtv_recorder_save_checkpoint;
    pthis->recover_from_checkpoint = mtv_recorder_recover_from_checkpoint;
    pthis->destroy = mtv_recorder_destroy;

    pthis->record_ctrl.get_recorded_duration = mtv_recorder_get_recorded_duration;

    return pthis;
}

kal_bool mtv_recorder_find_checkpoints(const kal_wchar* dir)
{
    kal_wchar* pattern;
    kal_bool found;

    pattern = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    ASSERT(pattern);
    kal_wstrcpy(pattern, CHECKPOINT_PREFIX);
    kal_wstrcat(pattern, L"*");

    /* check whether there is any checkpoint file */
    found = (mtv_process_files(dir, pattern, NULL, NULL) > 0) ? KAL_TRUE : KAL_FALSE;

    med_free_ext_mem((void**) &pattern);

    return found;
}

static kal_bool delete_found_file(void* param, kal_wchar* filename)
{
    UNUSED(param);

    FS_Delete(filename);
    return KAL_TRUE;    /* continue the searching */
}

void mtv_recorder_discard_unsaved_recording(const kal_wchar* dir)
{
    kal_wchar* pattern;

    pattern = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    ASSERT(pattern);
    kal_wstrcpy(pattern, CHECKPOINT_PREFIX);
    kal_wstrcat(pattern, L"*");

    /* remove all checkpoints first */
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    /* remove all buffers */
    mtv_be_discard_unsaved_buffers(dir);
}

static kal_bool recover_recording_from_checkpoint(void* param, kal_wchar* checkpoint)
{
    mtv_recorder_t* recorder = NULL;
    mtv_result_t ret;
    volatile kal_bool* aborted = param;

    /* construct a recorder to do recovery */
    recorder = construct_mtv_recorder();
    ret = recorder->recover_from_checkpoint(recorder, checkpoint, aborted);
    if (ret < 0)
    {
        MTV_TRACE(TRACE_INFO, MTV_TRC_RECORDER_RECOVERING_FAILED, ret);
    }

    recorder->destroy(recorder);

    return KAL_TRUE;    /* continue the searching */
}

mtv_result_t mtv_recorder_recover_recording(const kal_wchar* dir, volatile kal_bool* aborted)
{
    kal_wchar* pattern;
    kal_uint32 recovered;

    pattern = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    ASSERT(pattern);
    kal_wstrcpy(pattern, CHECKPOINT_PREFIX);
    kal_wstrcat(pattern, L"*");

    /* recover recording with each checkpoint file */
    recovered = mtv_process_files(dir, pattern, recover_recording_from_checkpoint, (void*) aborted);

    med_free_ext_mem((void**) &pattern);

    return recovered > 0 ? MTV_S_OK : MTV_S_FALSE;
}

#endif /* defined(__MED_MTV_MOD__) */
