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
 * app_asyncfile.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for async file operations..
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_ASYNCFILE_H
#define _APP_ASYNCFILE_H

#define APPLIB_FILE_TIMEOUT 1*KAL_TICKS_100_MSEC        /* 100ms */

/* FS_Open Parameter */
#define APPLIB_ASYNC_FILE_READ      0x00000100L
#define APPLIB_ASYNC_FILE_READ_WRITE   0x00000000L
#define APPLIB_ASYNC_FILE_WRITE     0x00000000L
#define APPLIB_ASYNC_FILE_CREATE    0x00010000L

#define APPLIB_ASYNC_FILE_SEEK_SET            0
#define APPLIB_ASYNC_FILE_SEEK_CUR            1
#define APPLIB_ASYNC_FILE_SEEK_END            2

#define APPLIB_ASYNC_FILE_OK              0
#define APPLIB_ASYNC_FILE_ERROR_ACCESS   -1
#define APPLIB_ASYNC_FILE_ERROR_DELAYED  -2
#define APPLIB_ASYNC_FILE_ERROR_PATH     -3
#define APPLIB_ASYNC_FILE_ERROR_INVALID  -4
#define APPLIB_ASYNC_FILE_ERROR_SIZE     -5
#define APPLIB_ASYNC_FILE_ERROR_FULL     -6
#define APPLIB_ASYNC_FILE_ERROR_EOF      -7
#define APPLIB_ASYNC_FILE_ERROR_EXIST    -8

typedef void (*applib_aysnc_file_task_callback_fn) (kal_int32 ret, kal_uint32 totalLen, void *arg);
typedef void *(*applib_async_file_mem_alloc_fn) (kal_uint32 size);
typedef void (*applib_async_file_mem_free_fn) (void *mem_ptr);

#define  APPLIB_CALLOUT_ACTIVE      0x0002      /* callout is currently active */
#define  applib_callout_active(c)   (((c).c_flags & APPLIB_CALLOUT_ACTIVE) && ((c).event_id != NULL))
#define  applib_callout_deactivate(c)              \
{                                                  \
   (c).c_flags &= ~APPLIB_CALLOUT_ACTIVE;          \
   (c).event_id = NULL;                            \
}

typedef struct
{
    int c_flags;    /* state of this entry */
    eventid event_id;
} applib_callout;

typedef enum
{
    APPLIB_ASYNC_FILE_MODE_READ,
    APPLIB_ASYNC_FILE_MODE_WRITE,
    APPLIB_ASYNC_FILE_MODE_READ_WRITE
} applib_async_file_mode_enum;

typedef struct
{
    kal_bool isUsed;
    module_type mod_id;
    kal_bool isFSopen;
    kal_int32 fileHandle;
    applib_async_file_mode_enum op; /* APPLIB_ASYNC_FILE_MODE_READ or APPLIB_ASYNC_FILE_MODE_WRITE */
    kal_uint32 totalLen;
    kal_uint8 *pos;
    kal_uint8 *buffer;
    kal_uint32 dataLen;
    event_scheduler *es;
    applib_callout fs_timer;
    applib_aysnc_file_task_callback_fn callback;
    void *arg_in_callback;
    applib_async_file_mem_alloc_fn mem_alloc_fn;
    applib_async_file_mem_free_fn mem_free_fn;

} applib_async_file_task_struct;

extern kal_bool applib_async_file_task_start(
                    applib_async_file_task_struct *op,
                    module_type mod_id,
                    kal_wchar *filename,
                    applib_async_file_mode_enum access_mode,
                    event_scheduler *es,
                    applib_aysnc_file_task_callback_fn callback,
                    void *return_arg);

extern kal_bool applib_async_file_task_stop(applib_async_file_task_struct *op);

extern void applib_async_file_task_write(
                applib_async_file_task_struct *op,
                kal_uint32 start_pos,
                kal_uint8 *buffer,
                kal_uint32 buffer_size);

extern void applib_async_file_task_read(
                applib_async_file_task_struct *op,
                kal_uint32 start_pos,
                kal_uint8 *buffer,
                kal_uint32 buffer_size);

/*****************************************************************************
* FUNCTION
*  applib_get_file_size
*
* DESCRIPTION
*   This function is used to get the size of one file.
*
* PARAMETERS
*  filename    IN       The filename
*
* RETURNS
*  file size.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
extern kal_uint32 applib_get_file_size(kal_wchar *filename);

/*****************************************************************************
* FUNCTION
*  applib_file_delete_folder
*
* DESCRIPTION
*   This function is used to remove one folder.
*
* PARAMETERS
*  foldername    IN       The foldername
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
extern kal_bool applib_file_delete_folder(kal_wchar *foldername);

/*****************************************************************************
* FUNCTION
*  applib_file_read_line
*
* DESCRIPTION
*   This function is used to read one line from file.
*
* PARAMETERS
*  filehandle    IN       The filehandle
*  buf         IN       The buffer to store data
*  buf_size       IN       The buffer size
*  line_len    IN/OUT       The line length
*  ret      IN/OUT   the result
*
* RETURNS
*  none.
*
* GLOBALS AFFECTED
*  none.
*****************************************************************************/
extern void applib_file_read_line(
                kal_int32 fileHandle,
                kal_uint8 *buf,
                kal_uint32 buf_size,
                kal_uint32 *line_len,
                kal_int32 *ret);
#endif /* _APP_ASYNCFILE_H */ 

