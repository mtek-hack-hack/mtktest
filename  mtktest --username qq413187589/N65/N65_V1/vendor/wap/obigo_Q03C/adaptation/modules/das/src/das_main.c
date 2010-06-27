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
 *   das_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements DAS internal signal handler and global context
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

#include "msf_cfg.h"

#include "msf_def.h"
#include "msf_int.h"
#include "msf_core.h"
#include "msf_mem.h"
#include "msf_pipe.h"
#include "msf_dcvt.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_hdr.h"
#include "msf_url.h"

#include "bra_if.h"

#include "widget_extension.h"

#include "fat_fs.h"
#include "ctk.h"
#include "das_main.h"
#include "das_view.h"
#include "das_msg.h"

jmp_buf das_jmpbuf;
int das_insideRun;
int das_wantsToRun;

static int job_count;

static das_job_t *das_job_queue;
static das_job_t *das_job_queue_last;

void das_exception_handler(void);
void das_init_job_queue(void);
void das_terminate_job_queue(void);
void das_delete_job(das_job_t *job);
int das_process_download_result(das_job_t *job);

/*****************************************************************************
 * FUNCTION
 *  das_convert
 * DESCRIPTION
 *  Convert signals owned by the DAS module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void* das_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer)
{
  return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  das_destruct
 * DESCRIPTION
 *  Convert signals owned by the DAS module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void das_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p)
{
  if (p == NULL)
    return;

  MSF_MEM_FREE (module, p);
}

/*****************************************************************************
 * FUNCTION
 *  das_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void das_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    das_insideRun = FALSE;
    das_wantsToRun = FALSE;
    job_count = 0;

    MSF_MEM_INIT(MSF_MODID_DAS, das_exception_handler);
    MSF_SIGNAL_REG_FUNCTIONS(MSF_MODID_DAS, das_convert, das_destruct);
    MSF_SIGNAL_REGISTER_QUEUE(MSF_MODID_DAS);
    MSF_MODULE_IS_CREATED(MSF_MODID_DAS, "DAS 0.1");
    das_init_job_queue();
    MSF_MODULE_IS_ACTIVE(MSF_MODID_DAS);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_DAS, DAS_MAIN_7B31C96FEBEB6F20E5682190960316D8, "DAS: Initialized\n"));
}


/*****************************************************************************
 * FUNCTION
 *  das_terminate
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void das_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    das_terminate_job_queue();
    MSF_SIGNAL_DEREGISTER_QUEUE(MSF_MODID_DAS);
    MSF_MEM_FREE_ALL(MSF_MODID_DAS);
    MSF_MODULE_IS_TERMINATED(MSF_MODID_DAS);
    MSF_KILL_TASK(MSF_MODID_DAS);
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_DAS, DAS_MAIN_EF7EB93BDFEB0B70145250956B9F52AB, "DAS: Terminated\n"));
}


/*****************************************************************************
 * FUNCTION
 *  das_exception_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void das_exception_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (das_insideRun)
    {
        longjmp(das_jmpbuf, 1);
    }
}

void das_process(void)
{
    das_job_t *job, *next_job;

    job = das_job_queue;
    
    while(job)
    {
        next_job = job->next;
        switch(job->status)
        {
        case DAS_STATUS_DOWNLOADING:
            das_read_pipe_data(job);
            break;
        case DAS_STATUS_ABORTED:
            das_abort_download(job, job->cause);
            das_delete_job(job);
            break;
        default:
            break;
        }
        job = next_job;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  das_init_job_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void das_init_job_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    das_job_queue = NULL;
    das_job_queue_last = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  das_terminate_job_queue
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void das_terminate_job_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_job_queue;

    while (das_job_queue != NULL)
    {
        das_job_queue = job->next;
        das_delete_job(job);
        job = das_job_queue;
    }
}


/*****************************************************************************
 * FUNCTION
 *  das_create_job
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_id          [IN]
 *  mime_type       [IN]
 *  data_type       [IN]
 *  data            [IN]
 *  data_len        [IN]
 *  pipe_name       [IN]
 *  file_name       [IN]
 * RETURNS
 *
 *****************************************************************************/
static das_job_t *das_create_job(
            int id,
            MSF_UINT8 mod_id,
            const char *url,
            const char *mime_type,
            MsfResourceType data_type,
            const unsigned char *data,
            MSF_INT32 data_len,
            const char *pipe_name,
            const char *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = DAS_ALLOCTYPE(das_job_t);

    job->next = NULL;
    job->id = id;
    job->pipe_handle = 0;
    job->file_handle = 0;
    job->download_size = 0;
    job->total_size = data_len;
    job->mime_type = msf_cmmn_strdup(MSF_MODID_DAS, mime_type);
    job->url = msf_cmmn_strdup(MSF_MODID_DAS, url);
    job->pipe_name = msf_cmmn_strdup(MSF_MODID_DAS, pipe_name);
    job->file_name = msf_cmmn_strdup(MSF_MODID_DAS, file_name);
    memset(job->buffer, 0, DAS_DL_BUFFER_SIZE);
    job->buffer_tail = 0;
    job->seq_num = 0;
    job->cause = WAP_DL_ERROR_OK;
    job->indication_sent = FALSE;
    job->header = NULL;

    return job;
}


/*****************************************************************************
 * FUNCTION
 *  das_find_job_by_screen_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  screen_id       [IN]
 * RETURNS
 *
 *****************************************************************************/
das_job_t *das_find_job_by_session_id(int session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_job_queue;

    while (job != NULL)
    {
        if (job->id == session_id)
        {
            return job;
        }
        job = job->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  das_find_job_by_pipe_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  pipe_handle     [IN]
 * RETURNS
 *
 *****************************************************************************/
das_job_t *das_find_job_by_pipe_handle(int pipe_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_job_queue;

    while (job != NULL)
    {
        if (job->pipe_handle == pipe_handle)
        {
            return job;
        }
        job = job->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  das_add_job
 * DESCRIPTION
 *
 * PARAMETERS
 *  job     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void das_add_job(das_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (das_job_queue == NULL)
    {
        das_job_queue = job;
    }
    else
    {
        das_job_queue_last->next = job;
    }

    das_job_queue_last = job;
}


/*****************************************************************************
 * FUNCTION
 *  das_delete_job
 * DESCRIPTION
 *
 * PARAMETERS
 *  job     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void das_delete_job(das_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *prev_job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (das_job_queue == job)
    {
        das_job_queue = job->next;
    }
    else
    {

        prev_job = das_job_queue;

        while (prev_job != NULL)
        {
            if (prev_job->next == job)
            {
                prev_job->next = job->next;
                break;
            }
            prev_job = prev_job->next;
        }
    }

    if (das_job_queue_last == job)
    {
        das_job_queue_last = prev_job;
    }

    if (job->status == DAS_STATUS_DOWNLOADING || job->status == DAS_STATUS_PREFETCHING)
    {
        FS_Close(job->file_handle);
        FS_Delete((WCHAR *)job->file_name);

        MSF_PIPE_CLOSE(job->pipe_handle);
        MSF_PIPE_DELETE(job->pipe_name);
    }

    DAS_FREE(job->mime_type);
    DAS_FREE(job->url);
    DAS_FREE(job->pipe_name);
    DAS_FREE(job->file_name);
    DAS_FREE(job->header);
    DAS_FREE(job);
    
    /* If there is no more pending job, remove browser if necessary*/ 
    if(!das_job_queue)
    {
        BRAif_downloadComplete(BRA_DNSTATUS_OK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  das_abort_download
 * DESCRIPTION
 *  this function will be called when MSF environment send message to module JAS.
 * PARAMETERS
 *  job         [?]
 *  cause       [IN]
 * RETURNS
 *
 *****************************************************************************/
void das_abort_download(das_job_t *job, int cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Close(job->file_handle);
    //FS_Delete((WCHAR *)job->file_name);

    MSF_PIPE_CLOSE(job->pipe_handle);
    MSF_PIPE_DELETE(job->pipe_name);

    job->status = DAS_STATUS_ABORTED;

    switch (cause)
    {
        case DAS_ERR_CREATE_FILE_FAILED:
            job->cause = WAP_DL_ERROR_INVALID_FILE;
            break;
        case DAS_ERR_SAVE_FULL:
        case DAS_ERR_SAVE_SIZE:
            job->cause = WAP_DL_ERROR_DISK_FULL;
            break;
        case DAS_ERR_DOWNLOAD_FAILED:
        case DAS_ERR_CONNECTION_ABORT:
            job->cause = WAP_DL_ERROR_CONNECTION_CLOSED;
            break;
        case DAS_ERR_USER_CANCELLED:
            return;
        default:
            job->cause = cause;
            break;
    }

    das_send_file_dl_progress_ind(job->id);

}

static int write_to_buffer(das_job_t *job, char *buf, unsigned int size)
{
    unsigned int bytes_to_write, bytes_written;
    int ret;

    if(!buf || size == 0)
        return -1;

    bytes_to_write = (job->buffer_tail + size <= DAS_DL_BUFFER_SIZE) ? size : DAS_DL_BUFFER_SIZE - job->buffer_tail;
    memcpy(job->buffer + job->buffer_tail, buf, bytes_to_write);
    job->buffer_tail = (job->buffer_tail + bytes_to_write) % DAS_DL_BUFFER_SIZE;

    if(job->buffer_tail == 0)
    {
        ret = FS_Write(job->file_handle, job->buffer, DAS_DL_BUFFER_SIZE, (UINT*) &bytes_written);

        if (ret != FS_NO_ERROR)
        {
            return ret;
        }
    }

    if(size > bytes_to_write)
    {
        return write_to_buffer(job, buf + bytes_to_write, size - bytes_to_write);
    }

    return 0;
}

static int flush_buffer(das_job_t *job)
{
    unsigned int bytes_written;
    int ret;

    if(job->buffer_tail > 0)
    {
        ret = FS_Write(job->file_handle, job->buffer, job->buffer_tail, (UINT*) &bytes_written);

        if (ret != FS_NO_ERROR)
        {
            return ret;
        }
    }
	return 0;
}

/*****************************************************************************
 * FUNCTION
 *  das_read_pipe_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  job     [?]
 * RETURNS
 *
 *****************************************************************************/
int das_read_pipe_data(das_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int bufsize = 1024, content_size = 2000;
    char *buf;
    int bytes_read;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job->status != DAS_STATUS_DOWNLOADING && job->status != DAS_STATUS_PREFETCHING)
    {
        return FALSE;
    }

    if(job->header)
    {
       content_size -= strlen(job->header);
    }
    buf = DAS_ALLOC(bufsize);
    do
    {
        if(job->download_size < content_size)
        {
            bufsize = content_size - job->download_size;
        }

        bytes_read = MSF_PIPE_READ(job->pipe_handle, buf, bufsize);

        if (bytes_read > 0)
        {
            ret = write_to_buffer(job, buf, bytes_read);
            if (ret < 0)
            {
                das_abort_download(job, ret);
                das_delete_job(job);
                DAS_FREE(buf);
                return FALSE;
            }

            job->download_size += bytes_read;

            if(job->download_size == content_size)
            {
                das_send_file_dl_ind(job);
                DAS_FREE(buf);
                return TRUE;
            }
        }
    } while (bytes_read >= 0);

    if (bytes_read == MSF_PIPE_ERROR_DELAYED)
    {
        MSF_PIPE_POLL(job->pipe_handle);
    }
    else if(bytes_read == MSF_PIPE_ERROR_CLOSED)
    {
        if(job->status == DAS_STATUS_PREFETCHING)
        {
            das_send_file_dl_ind(job);
        }
        else
        {
            das_process_download_result(job);
        }
    }
    else
    {
        das_abort_download(job, DAS_ERR_CONNECTION_ABORT);
        das_delete_job(job);
        DAS_FREE(buf);
        return FALSE;
    }
    DAS_FREE(buf);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  das_handle_pipe_notify
 * DESCRIPTION
 *  this function will receive msf system pipe notify and receive data.
 *  and write those data into file.
 * CALLS
 *
 * PARAMETERS
 *  handle          [IN]
 *  event_type      [IN]
 * RETURNS
 *
 *****************************************************************************/
int das_handle_pipe_notify(int handle, int event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    das_job_t *job;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    job = das_find_job_by_pipe_handle(handle);

    if (!job)
    {
        return FALSE;
    }

    switch (event_type)
    {
        case MSF_PIPE_EVENT_READ:
        case MSF_PIPE_EVENT_CLOSED:
            ret = das_read_pipe_data(job);
            if(ret && job->indication_sent == 0 && job->status != DAS_STATUS_PREFETCHING)
            {
                das_send_file_dl_progress_ind(job->id);
            }
            break;
        default:
            das_abort_download(job, DAS_ERR_CONNECTION_ABORT);
            das_delete_job(job);
            return TRUE;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  das_get_drive_free_space
 * DESCRIPTION
 *
 * PARAMETERS
 *  drive       [IN]
 * RETURNS
 *
 *****************************************************************************/
static int das_get_drive_free_space(const char *file_name)
{
    kal_int32 result;
    FS_DiskInfo diskinfo;
    kal_uint8 *path;

    path = HDI_FileNameTranslate(file_name);

    result = FS_GetDiskInfo((WCHAR *)path, &diskinfo, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    HDI_FileNameFree(path);

    if(result < 0)
    {
        return result;
    }
    return diskinfo.FreeClusters * diskinfo.SectorsPerCluster * diskinfo.BytesPerSector;
}


/*****************************************************************************
 * FUNCTION
 *  das_create_file
 * DESCRIPTION
 *
 * PARAMETERS
 *  file_name       [?]
 *  size            [IN]
 * RETURNS
 *
 *****************************************************************************/
static kal_uint8 *das_get_save_location(int id, const char *file_name, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *path = WAP_DOWNLOAD_FOLDER;
    char *temp;
    char temp_ext[24] = "";
	kal_uint8 *dest_file;
    int r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msm_remove_files_under_dir(WAP_DOWNLOAD_FOLDER);
    HDIa_fileMkDir(WAP_DOWNLOAD_FOLDER);

    r = das_get_drive_free_space(path);
    if (r < 0)
    {
        das_display_error(r);
        return NULL;
    }
    else if (r < size)
    {
        // If there is no more space on public drive, see if we have memory card or not.

        sprintf(temp_ext, "%s%c:\\", HDI_EXTERNAL_PATH, FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE));
        if(das_get_drive_free_space(temp_ext) < size)
        {
            das_display_error(DAS_ERR_SAVE_SIZE);
            return NULL;
        }
        else
        {
            path = temp_ext;
        }
    }
    temp = msf_cmmn_strcat(MSF_MODID_DAS, path, file_name);
    sprintf(temp_ext, ".t%02d", (short)(id % 10));
    DAS_FREE(temp);
    temp = msf_cmmn_strcat(MSF_MODID_DAS, temp, temp_ext);

    /* Convert to UCS2 filename here, need to be freed by caller */
    dest_file = HDI_FileNameTranslate(temp);
    DAS_FREE(temp);
    return dest_file;
}


/*****************************************************************************
 * FUNCTION
 *  das_process_download_result
 * DESCRIPTION
 *
 * PARAMETERS
 *  job     [?]
 * RETURNS
 *
 *****************************************************************************/
int das_process_download_result(das_job_t *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = flush_buffer(job);
    if (ret < 0)
    {
        das_abort_download(job, ret);
        das_delete_job(job);
        return FALSE;
    }
    FS_Close(job->file_handle);
    MSF_PIPE_CLOSE(job->pipe_handle);
    MSF_PIPE_DELETE(job->pipe_name);
    job->status = DAS_STATUS_COMPLETE;
    das_send_file_dl_progress_ind(job->id);
    das_delete_job(job);
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  das_handle_buffer_content
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_src         [IN]
 *  mime_type       [IN]
 *  data_type       [IN]
 *  data            [IN]
 *  data_len        [IN]
 *  src_path        [IN]
 *  file_name       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void
das_handle_buffer_content(
    int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int file_handle;
    int size_remain;
    int bytes_written;
    int size;
    kal_uint8 *in_filename;
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(file_name == NULL)
    {
        return;
    }

    in_filename = das_get_save_location(id, file_name, data_len);
    
    if (!in_filename)
    {
        return;
    }

    FS_Delete((WCHAR *)in_filename);

    file_handle = FS_Open((WCHAR *)in_filename, FS_READ_WRITE | FS_CREATE | FS_OPEN_SHARED);

    if (file_handle <= 0)
    {
        das_display_error(file_handle);
        return;
    }

    size_remain = data_len;
    bytes_written = 0;

    while (size_remain > 0)
    {
        ret = FS_Write(file_handle, (void*)(data + bytes_written), size_remain, (U32*) & size);
        if (ret != FS_NO_ERROR)
        {
            das_display_error(ret);
            FS_Close(file_handle);
            FS_Delete((WCHAR *)in_filename);
            return;
        }
        if (size <= 0)
        {
            break;
        }
        bytes_written += size;
        size_remain -= size;
    }

    FS_Close(file_handle);
    das_send_dl_ind(mod_src, MsfResourceBuffer, url, mime_type, in_filename, header, network_account_id);
    DAS_FREE(in_filename);
}


/*****************************************************************************
 * FUNCTION
 *  das_handle_file_content
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_src         [IN]
 *  mime_type       [IN]
 *  data_type       [IN]
 *  data            [IN]
 *  data_len        [IN]
 *  src_path        [IN]
 *  file_name       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void
das_handle_file_content(
    int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *to_filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    to_filename = HDI_FileNameTranslate(file_name);

    das_send_dl_ind(mod_src, MsfResourceFile, url, mime_type, to_filename, header, network_account_id);

    DAS_FREE(to_filename);
}


/*****************************************************************************
 * FUNCTION
 *  das_handle_pipe_content
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_src         [IN]
 *  mime_type       [IN]
 *  data_type       [IN]
 *  data            [IN]
 *  data_len        [IN]
 *  src_path        [IN]
 *  file_name       [IN]
 * RETURNS
 *
 *****************************************************************************/
static int
das_handle_pipe_content(
    int id,
    MSF_UINT8 mod_src,
    const char *url,
    const char *mime_type,
    const unsigned char *data,
    MSF_INT32 data_len,
    const char *src_path,
    const char *file_name,
    const char *header,
    MSF_INT32 network_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int pipe_handle;
    das_job_t *job;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(file_name != NULL);

    pipe_handle = MSF_PIPE_OPEN(MSF_MODID_DAS, src_path);
    if (pipe_handle < 0)
    {
        das_display_error(DAS_ERR_CONNECTION_ABORT);
        return FALSE;
    }

    job = das_create_job(id, mod_src, url, mime_type, MsfResourcePipe, NULL, data_len, src_path, file_name);
    job->pipe_handle = pipe_handle;
    if(header)
    {
        job->header = msf_cmmn_strdup(MSF_MODID_DAS, header);
    }
    das_add_job(job);

    job->status = DAS_STATUS_PREFETCHING;
    das_read_pipe_data(job);

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  das_execute_commands
 * DESCRIPTION
 *
 * PARAMETERS
 *  mod_src     [IN]
 *  p           [?]
 * RETURNS
 *
 *****************************************************************************/
int das_execute_commands(MSF_UINT8 mod_src, msf_module_execute_cmd_t *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    msf_content_data_t *contentData;
    char *filename = NULL;
    char *contentType = NULL;
    MSF_UINT32 content_length;
    long data_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p->contentDataExists)
    {
        return FALSE;
    }

    contentData = p->contentData;

    if (contentData->contentDataType == MSF_CONTENT_DATA_NONE)  /* Downloading data */
    {
        return FALSE; /* Not handled */
    }
    if(contentData->contentDataType == MSF_CONTENT_DATA_RAW)
    {
        msf_hdr_t *hdr = msf_hdr_create(MSF_MODID_DAS);
        msf_hdr_add_headers_from_text(hdr, contentData->contentHeaders);
        contentType = msf_cmmn_strdup(MSF_MODID_DAS, msf_hdr_get_string (hdr, MSF_HDR_CONTENT_TYPE));
        msf_hdr_delete(hdr);
    }

    if (contentData->contentHeaders != NULL)
    {
        msf_hdr_t *hdr = msf_hdr_create(MSF_MODID_DAS);

        msf_hdr_add_headers_from_text(hdr, contentData->contentHeaders);
        filename = msf_cmmn_strdup(MSF_MODID_DAS, msf_hdr_get_parameter(hdr, MSF_HDR_CONTENT_DISPOSITION, "filename"));

        if (msf_hdr_get_uint32(hdr, MSF_HDR_CONTENT_LENGTH, &content_length) && (content_length > 0))
        {
            data_length = (long)content_length;
        }
        msf_hdr_delete(hdr);
    }

    if (filename == NULL && contentData->contentUrl != NULL)
    {
        char *s;
        char *f;

        s = msf_url_get_path(MSF_MODID_DAS, (const char *)contentData->contentUrl);
        if (s != NULL)
        {
            f = strrchr(s, '/');
            if (f != NULL)
            {
                filename = msf_cmmn_strdup(MSF_MODID_DAS, (f + 1));
            }
            else
            {
                filename = msf_cmmn_strdup(MSF_MODID_DAS, s);
            }

            DAS_FREE(s);
        }
    }

    job_count++;

    switch (contentData->contentDataType)
    {
        case MSF_CONTENT_DATA_RAW:
            das_handle_buffer_content(
                job_count,
                mod_src,
                contentData->contentUrl,
                contentType,
                contentData->contentData,
                contentData->contentDataLength,
                contentData->contentSource,
                "pushmsg",
                contentData->contentHeaders,
        		contentData->networkAccountId);
            break;

        case MSF_CONTENT_DATA_FILE:
            das_handle_file_content(
                job_count,
                mod_src,
                contentData->contentUrl,
                contentData->routingIdentifier,
                contentData->contentData,
                data_length,
                contentData->contentSource,
                filename,
                contentData->contentHeaders,
        		contentData->networkAccountId);
            break;

        case MSF_CONTENT_DATA_PIPE:
            das_handle_pipe_content(
                job_count,
                mod_src,
                contentData->contentUrl,
                contentData->routingIdentifier,
                contentData->contentData,
                data_length,
                contentData->contentSource,
                filename,
                contentData->contentHeaders,
        		contentData->networkAccountId);
            break;

        default:
            break;
    }

    DAS_FREE(contentType);
    DAS_FREE(filename);
    return TRUE;
}

