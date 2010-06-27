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
 * applib_asyncfile.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is intends for async file operations.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define  _APP_ASYNCFILE_C

#include "kal_release.h"
#include "stacklib.h"
#include "event_shed.h" /* event schedulet */
#include "stack_timer.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "app_asyncfile.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "app_ltlcom.h"

#include "app_str.h"
#include "FS_func.h"

extern task_indx_type mod_task_g[RPS_TOTAL_STACK_MODULES];

void applib_async_file_task_write_continue(applib_async_file_task_struct *op);
void applib_async_file_task_read_continue(applib_async_file_task_struct *op);


/*****************************************************************************
 * FUNCTION
 *  transferFsError
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fs_err      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_int32 transferFsError(kal_int32 fs_err)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (fs_err)
    {
        case FS_NO_ERROR:
            return APPLIB_ASYNC_FILE_OK;
        case FS_FILE_NOT_FOUND:
        case FS_INVALID_FILENAME:
            return APPLIB_ASYNC_FILE_ERROR_PATH;    /* Note that applications might check this error code */

        case FS_ACCESS_DENIED:
            return APPLIB_ASYNC_FILE_ERROR_ACCESS;

        case FS_MEDIA_CHANGED:
            return APPLIB_ASYNC_FILE_ERROR_ACCESS;

        case FS_TOO_MANY_FILES:
            return APPLIB_ASYNC_FILE_ERROR_ACCESS;

        case FS_DISK_FULL:
        case FS_APP_QUOTA_FULL:
            return APPLIB_ASYNC_FILE_ERROR_FULL;    /* Note that applications might check this error code */

        case FS_FILE_EXISTS:
            return APPLIB_ASYNC_FILE_ERROR_EXIST;   /* Note that applications might check this error code */

            /* File System is busy now, return immediately with cause "DELAY" */
        case FS_FLASH_ERASE_BUSY:
        case FS_LOCK_MUTEX_FAIL:
            return APPLIB_ASYNC_FILE_ERROR_DELAYED;
        default:
            return APPLIB_ASYNC_FILE_ERROR_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_internal_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_async_file_task_internal_write(applib_async_file_task_struct *op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_uint32 wr_no;
    kal_uint32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL)
    {
        ASSERT(0);
    }

    length = op->buffer - op->pos + op->dataLen;
    while (1)
    {
        if (length == 0)
        {
            op->callback(APPLIB_ASYNC_FILE_OK, op->totalLen, op->arg_in_callback);
            return;
        }

        wr_no = 0;
    #ifndef __MTK_TARGET__
        if (length > 512)
        {
            ret = FS_Write(op->fileHandle, op->pos, 512, &wr_no);
            ret = FS_FLASH_ERASE_BUSY;
        }
        else
        {
            ret = FS_Write(op->fileHandle, op->pos, length, &wr_no);
        }
    #else /* __MTK_TARGET__ */ 
        ret = FS_Write(op->fileHandle, op->pos, length, &wr_no);
    #endif /* __MTK_TARGET__ */ 
        if (wr_no > 0)
        {
            op->totalLen += (unsigned long)wr_no;
            op->pos += wr_no;
            length -= wr_no;
        }
        switch (transferFsError(ret))
        {
                /* File system busy */
            case APPLIB_ASYNC_FILE_ERROR_DELAYED:
            {
                if (applib_callout_active(op->fs_timer))
                {
                    ASSERT(0);
                }
                op->fs_timer.c_flags |= APPLIB_CALLOUT_ACTIVE;
                op->fs_timer.event_id = evshed_set_event(
                                            op->es,
                                            (kal_timer_func_ptr) applib_async_file_task_write_continue,
                                            op,
                                            APPLIB_FILE_TIMEOUT);
                return;
            }
            default:
                if (ret < 0)
                {
                    op->callback(transferFsError(ret), op->totalLen, op->arg_in_callback);
                    return;
                }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_internal_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void applib_async_file_task_internal_read(applib_async_file_task_struct *op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_uint32 rd_no;
    kal_uint32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL)
    {
        ASSERT(0);
    }

    length = op->buffer + op->dataLen - op->pos;
    while (1)
    {
        if (length == 0)
        {
            op->callback(APPLIB_ASYNC_FILE_OK, op->totalLen, op->arg_in_callback);
            return;
        }

        rd_no = 0;

    #ifndef __MTK_TARGET__
        if (length > 512)
        {
            ret = FS_Read(op->fileHandle, op->pos, 512, &rd_no);
            ret = FS_FLASH_ERASE_BUSY;
        }
        else
        {
            ret = FS_Read(op->fileHandle, op->pos, length, &rd_no);
        }
    #else /* __MTK_TARGET__ */ 
        ret = FS_Read(op->fileHandle, op->pos, length, &rd_no);
    #endif /* __MTK_TARGET__ */ 

        if (rd_no > 0)
        {
            op->totalLen += (unsigned long)rd_no;
            op->pos += rd_no;
            length -= rd_no;
        }
        switch (transferFsError(ret))
        {
                /* File system busy */
            case APPLIB_ASYNC_FILE_ERROR_DELAYED:
            {
                if (applib_callout_active(op->fs_timer))
                {
                    ASSERT(0);
                }
                op->fs_timer.c_flags |= APPLIB_CALLOUT_ACTIVE;
                op->fs_timer.event_id = evshed_set_event(
                                            op->es,
                                            (kal_timer_func_ptr) applib_async_file_task_read_continue,
                                            op,
                                            APPLIB_FILE_TIMEOUT);
                return;
            }

            default:
                if (ret < 0)
                {
                    op->callback(transferFsError(ret), op->totalLen, op->arg_in_callback);
                    return;
                }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op              [?]         
 *  mod_id          [IN]        
 *  filename        [?]         
 *  access_mode     [IN]        
 *  es              [?]         
 *  callback        [IN]        
 *  return_arg      [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool applib_async_file_task_start(
            applib_async_file_task_struct *op,
            module_type mod_id,
            kal_wchar *filename,
            applib_async_file_mode_enum access_mode,
            event_scheduler *es,
            applib_aysnc_file_task_callback_fn callback,
            void *return_arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fileHandle;
    int openMode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL || filename == NULL)
    {
        return NULL;
    }

    kal_mem_set(op, 0, sizeof(applib_async_file_task_struct));

    switch (access_mode)
    {
        case APPLIB_ASYNC_FILE_MODE_READ:
            openMode = APPLIB_ASYNC_FILE_READ | FS_NONBLOCK_MODE | FS_OPEN_SHARED;
            break;

        case APPLIB_ASYNC_FILE_MODE_READ_WRITE:
        case APPLIB_ASYNC_FILE_MODE_WRITE:
            openMode = APPLIB_ASYNC_FILE_WRITE | APPLIB_ASYNC_FILE_CREATE | FS_NONBLOCK_MODE;
            break;

        default:
            openMode = APPLIB_ASYNC_FILE_WRITE | APPLIB_ASYNC_FILE_CREATE | FS_NONBLOCK_MODE;
            break;
    }

    fileHandle = FS_Open(filename, openMode);
    if (fileHandle < 0)
    {
        return KAL_FALSE;
    }
    op->mod_id = mod_id;
    op->isFSopen = KAL_TRUE;
    op->fileHandle = fileHandle;
    op->es = es;
    op->callback = callback;
    op->arg_in_callback = return_arg;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [?]     
 * RETURNS
 *  
 *****************************************************************************/
kal_bool applib_async_file_task_stop(applib_async_file_task_struct *op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL)
    {
        return KAL_FALSE;
    }
    if (op->isFSopen == KAL_TRUE)
    {
        FS_Close(op->fileHandle);
        op->isFSopen = KAL_FALSE;
    }

    if (op->es != NULL)
    {
        if (applib_callout_active(op->fs_timer))
        {
            op->fs_timer.c_flags &= ~APPLIB_CALLOUT_ACTIVE;
            ASSERT(op->fs_timer.event_id != NULL);
            evshed_cancel_event(op->es, &(op->fs_timer.event_id));
            op->fs_timer.event_id = NULL;
        }
        else
        {
            applib_callout_deactivate(op->fs_timer);
        }
        op->es = NULL;
    }
    kal_mem_set(op, 0, sizeof(applib_async_file_task_struct));
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op              [?]         
 *  start_pos       [IN]        
 *  buffer          [?]         
 *  buffer_size     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void applib_async_file_task_write(
        applib_async_file_task_struct *op,
        kal_uint32 start_pos,
        kal_uint8 *buffer,
        kal_uint32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL || op->isFSopen == KAL_FALSE)
    {
        return;
    }
    op->totalLen = 0;
    op->buffer = buffer;
    op->pos = buffer;
    op->dataLen = buffer_size;

    if (start_pos == -1)
    {
        FS_Seek(op->fileHandle, 0, APPLIB_ASYNC_FILE_SEEK_END);
    }
    else
    {
        FS_Seek(op->fileHandle, start_pos, APPLIB_ASYNC_FILE_SEEK_SET);
    }

    applib_async_file_task_internal_write(op);
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op              [?]         
 *  start_pos       [IN]        
 *  buffer          [?]         
 *  datelen         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void applib_async_file_task_read(
        applib_async_file_task_struct *op,
        kal_uint32 start_pos,
        kal_uint8 *buffer,
        kal_uint32 datelen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL || op->isFSopen == KAL_FALSE)
    {
        return;
    }
    op->totalLen = 0;
    op->buffer = buffer;
    op->pos = buffer;
    op->dataLen = datelen;

    if (start_pos == -1)
    {
        FS_Seek(op->fileHandle, 0, APPLIB_ASYNC_FILE_SEEK_END);
    }
    else
    {
        FS_Seek(op->fileHandle, start_pos, APPLIB_ASYNC_FILE_SEEK_SET);
    }

    applib_async_file_task_internal_read(op);
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_write_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void applib_async_file_task_write_continue(applib_async_file_task_struct *op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL || op->isFSopen == KAL_FALSE)
    {
        ASSERT(0);
    }
    if (applib_callout_active(op->fs_timer))
    {
        op->fs_timer.c_flags &= ~APPLIB_CALLOUT_ACTIVE;
        ASSERT(op->fs_timer.event_id != NULL);
        op->fs_timer.event_id = NULL;
    }
    applib_async_file_task_internal_write(op);
}


/*****************************************************************************
 * FUNCTION
 *  applib_async_file_task_read_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void applib_async_file_task_read_continue(applib_async_file_task_struct *op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (op == NULL || op->isFSopen == KAL_FALSE)
    {
        ASSERT(0);
    }
    if (applib_callout_active(op->fs_timer))
    {
        op->fs_timer.c_flags &= ~APPLIB_CALLOUT_ACTIVE;
        ASSERT(op->fs_timer.event_id != NULL);
        op->fs_timer.event_id = NULL;
    }
    applib_async_file_task_internal_read(op);
}


/*****************************************************************************
 * FUNCTION
 *  applib_file_read_line
 * DESCRIPTION
 *  This function is used to read one line from file.
 * PARAMETERS
 *  fileHandle          [IN]            
 *  buf                 [IN]            The buffer to store data
 *  buf_size            [IN]            The buffer size
 *  line_len            [IN/OUT]        The line length
 *  ret                 [IN/OUT]        The result
 *  filehandle(?)       [IN]            The filehandle
 * RETURNS
 *  void
 *****************************************************************************/
void applib_file_read_line(
        kal_int32 fileHandle,
        kal_uint8 *buf,
        kal_uint32 buf_size,
        kal_uint32 *line_len,
        kal_int32 *ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *pos = buf;
    kal_uint32 rd_no = 0;
    kal_uint32 count = 0;
    kal_bool CR = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(buf, 0, buf_size);
    *line_len = 0;
    while (buf_size)
    {
        *ret = FS_Read(fileHandle, pos, 1, &rd_no);
        if (*ret < 0)
        {
            *line_len = count;
            return;
        }
        else if (rd_no != 1)
        {
            *line_len = count;
            return;
        }
        else
        {
            count++;
            if (*pos == '\r')
            {
                CR = KAL_TRUE;
            }
            else if (*pos == '\n')
            {
                if (CR == KAL_TRUE)
                {
                    *line_len = count;
                    return;
                }
                else
                {
                    CR = KAL_FALSE;
                }
            }
            else
            {
                CR = KAL_FALSE;
            }
        }
        buf_size--;
        pos++;
    }
    *ret = -1;
    *line_len = rd_no;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  applib_get_file_size
 * DESCRIPTION
 *  This function is used to get the size of one file.
 * PARAMETERS
 *  filename        [IN]        The filename
 * RETURNS
 *  file size.
 *****************************************************************************/
kal_uint32 applib_get_file_size(kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fileHandle;
    kal_uint32 fileSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        return 0;
    }

    fileHandle = FS_Open(filename, APPLIB_ASYNC_FILE_READ | FS_NONBLOCK_MODE | FS_OPEN_SHARED);
    if (fileHandle < 0)
    {
        return 0;
    }
    FS_GetFileSize(fileHandle, &fileSize);
    FS_Close(fileHandle);
    return fileSize;
}


/*****************************************************************************
 * FUNCTION
 *  applib_file_delete_folder
 * DESCRIPTION
 *  This function is used to remove one folder.
 * PARAMETERS
 *  foldername      [IN]        The foldername
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool applib_file_delete_folder(kal_wchar *foldername)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int h = -1; /* save temp. file handle for find */
    FS_DOSDirEntry info;
    kal_wchar path[200];
    kal_wchar filename[100];
    kal_wchar wildcard[6];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (foldername == NULL)
    {
        return KAL_FALSE;
    }
    else if (app_ucs2_strlen((kal_int8*) foldername) > 97)
    {
        return KAL_FALSE;
    }
    else
    {

        kal_mem_set(path, 0, 400);
        app_ucs2_strcpy((kal_int8*) path, (kal_int8*) foldername);
        kal_wsprintf(wildcard, "\\*");
        app_ucs2_strcat((kal_int8*) path, (kal_int8*) wildcard);

        h = FS_FindFirst(path, 0, 0, &info, filename, 200);
        if (h < 0)
        {
            return KAL_FALSE;
        }
        do
        {
            /* filter out folder results */
            if (!(info.Attributes & FS_ATTR_DIR))
            {
                kal_mem_set(path, 0, 400);
                app_ucs2_strcpy((kal_int8*) path, (kal_int8*) foldername);
                kal_wsprintf(wildcard, "\\");
                app_ucs2_strcat((kal_int8*) path, (kal_int8*) wildcard);
                app_ucs2_strcat((kal_int8*) path, (kal_int8*) filename);
                FS_Delete(path);
                kal_mem_set(filename, 0x00, 200);
            }
        } while (FS_FindNext(h, &info, filename, 200) == FS_NO_ERROR);
        FS_FindClose(h);
    }
    return KAL_TRUE;
}

