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
 *   mtv_async_io.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_ASYNC_IO_H
#define _MTV_ASYNC_IO_H

#ifndef _FS_RELEASE_H
#include "fat_fs.h"
#endif

typedef enum
{
    ASYNC_IO_BLOCK_STATE_FREE,
    ASYNC_IO_BLOCK_STATE_WAITING,
    ASYNC_IO_BLOCK_STATE_WRITING

} async_io_block_state_t;

typedef struct async_io_block_t async_io_block_t;

struct async_io_block_t
{
    async_io_block_state_t state;
    kal_uint32 block_no;
    kal_uint8* buffer;
    kal_uint32 size;

    async_io_block_t* prev;
    async_io_block_t* next;
};

typedef struct
{
    kal_mutexid lock;
    async_io_block_t* head;

    kal_uint32 size;

} async_io_block_queue_t;

/**
  * Clean-up callback.
  */
typedef void (*async_io_cleanup_t)(void* param);

/**
  * Asynchronous I/O implementation. Write operations will be done asynchornously by another
  * task. Read operations will still be done synchronously.
  *
  * The implementation allows several tasks to call async_io_write/async_io_write simutaneously.
  * However, async_io_attach and async_io_detach can only be called by one task.
  *
  * Each async_io_t object requires 3 mutexes (1 for file lock and 2 for write and free queue).
  */
typedef struct
{
    FS_HANDLE file_h;
    kal_uint32 block_size;
    kal_mutexid file_lock;

    async_io_block_queue_t write_q;
    async_io_block_queue_t free_q;

    async_io_cleanup_t cleanup;
    void* cleanup_param;

    kal_uint32 errors;

} async_io_t;

/**
  * Attach asynchronous I/O operation to a file handle.
  *
  * @param io [in] the IO object to initialize
  * @param file_h [in] file handle
  * @param block_size [in] the I/O block size in bytes
  */
extern kal_int32 async_io_attach(async_io_t* io, FS_HANDLE file_h, kal_uint32 block_size);

/**
  * Perform file writing asynchronously.
  */
extern kal_int32 async_io_write(async_io_t* io, kal_uint32 block_no, void* buf, kal_uint32 buf_size);

/**
  * Perform file reading synchronously.
  */
extern kal_int32 async_io_read(async_io_t* io, kal_uint32 block_no, void* buf, kal_uint32* read_bytes);

/**
  * Detach the file handle. If a cleanup is given (not NULL), it will detach the file handle
  * asynchronously and call back to the cleanup function in the context of I/O task. Otherwise,
  * it will wait until all blocks are written and detach the file handle.
  */
extern kal_int32 async_io_detach(async_io_t* io, async_io_cleanup_t cleanup, void* cleanup_param);

/**
  * For I/O task to perform asynchronous I/O.
  */
extern kal_int32 async_io_process_writing(void* io_param);

/**
  * Initialize the lock pool for Mobile TV engine.
  */
extern void mtv_init_lock_pool(void);

#endif /* _MTV_ASYNC_IO_H */

