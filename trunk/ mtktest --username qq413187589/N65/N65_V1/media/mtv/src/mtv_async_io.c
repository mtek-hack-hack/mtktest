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
 *   mtv_async_io.c
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

#include "kal_release.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_timer.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "mtv_async_io.h"
#include "mtv_comm.h"
#include "mtv_main.h"
#include "med_struct.h"
#include "med_utility.h"

#if defined(__MED_MTV_MOD__)

#define MTV_ASYNC_IO_LOCKS_PER_FILE  3
#define MTV_ASYNC_IO_LOCKS_FOR_BE    (3*MTV_ASYNC_IO_LOCKS_PER_FILE)
#define MTV_ASYNC_IO_LOCKS_FOR_CP    MTV_ASYNC_IO_LOCKS_PER_FILE
#define MTV_ASYNC_IO_LOCK_COUNT      (2*MTV_ASYNC_IO_LOCKS_FOR_BE + MTV_ASYNC_IO_LOCKS_FOR_CP)

typedef struct
{
    kal_mutexid pool_lock;
    kal_mutexid locks[MTV_ASYNC_IO_LOCK_COUNT];

} mtv_lock_pool_t;

static mtv_lock_pool_t g_lock_pool;

void mtv_init_lock_pool(void)
{
    kal_uint32 i;

    g_lock_pool.pool_lock = kal_create_mutex("mtv_pool_lock");
    for (i = 0; i < ARRAY_SIZE(g_lock_pool.locks); i++)
    {
        g_lock_pool.locks[i] = kal_create_mutex("mtv_lock");
    }
}

static kal_mutexid mtv_get_lock(void)
{
    kal_uint32 i;
    kal_mutexid lock = 0;

    kal_take_mutex(g_lock_pool.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_lock_pool.locks); i++)
    {
        if (g_lock_pool.locks[i] != NULL)
        {
            lock = g_lock_pool.locks[i];
            g_lock_pool.locks[i] = NULL;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_lock_pool.locks));

    kal_give_mutex(g_lock_pool.pool_lock);

    return lock;
}

    static void mtv_return_lock(kal_mutexid lock)
{
    kal_uint32 i;

    kal_take_mutex(g_lock_pool.pool_lock);

    for (i = 0; i < ARRAY_SIZE(g_lock_pool.locks); i++)
    {
        if (g_lock_pool.locks[i] == NULL)
        {
            g_lock_pool.locks[i] = lock;
            break;
        }
    }
    ASSERT(i != ARRAY_SIZE(g_lock_pool.locks));

    kal_give_mutex(g_lock_pool.pool_lock);
}

static void async_io_init_queue(async_io_block_queue_t* q)
{
    q->head = NULL;
    q->lock = mtv_get_lock();
    q->size = 0;
}

static async_io_block_t* async_io_queue_head(async_io_block_queue_t* q)
{
    return q->head;
}

static async_io_block_t* async_io_dequeue_block(async_io_block_queue_t* q)
{
    async_io_block_t* head;

    kal_take_mutex(q->lock);

    head = q->head;
    if (head)
    {
        q->head = head->next;
        if (q->head) {
            q->head->prev = head->prev;
        }

        head->next = head->prev = NULL;

        q->size--;
        ASSERT((q->head == NULL && q->size == 0) || (q->head != NULL && q->size != 0));
    }

    kal_give_mutex(q->lock);

    return head;
}

/**
  * Enqueue an item.
  *
  * @return the item number in the queue.
  */
static kal_int32 async_io_enqueue_block(async_io_block_queue_t* q, async_io_block_t* block)
{
    kal_int32 q_size;

    ASSERT(block != NULL);

    kal_take_mutex(q->lock);

    block->next = NULL;

    if (q->head != NULL)
    {
        async_io_block_t* tail = q->head->prev;
        tail->next = block;
        block->prev = tail;
        q->head->prev = block;
    }
    else
    {
        q->head = block;
        block->prev = block;
    }

    q_size = ++q->size;
    ASSERT(q->head != NULL && q->size != 0);

    kal_give_mutex(q->lock);

    return q_size;
}

static void async_io_wait_until_empty(async_io_block_queue_t* q)
{
    for (;;)
    {
        kal_take_mutex(q->lock);
        if (q->head == NULL)
        {
            kal_give_mutex(q->lock);
            break;
        }
        else
        {
            kal_give_mutex(q->lock);
            kal_sleep_task(1);
        }
    }
}

static void async_io_uninit_queue(async_io_block_queue_t* q)
{
    async_io_block_t* block;

    /* free all blocks in free queue */
    while ((block = async_io_dequeue_block(q)) != NULL)
    {
        med_free_ext_mem((void**)&block->buffer);
        med_free_ext_mem((void**)&block);
    }
    q->head = NULL;

    mtv_return_lock(q->lock);
}

static void async_io_read_block_in_write_queue(async_io_t* io, kal_uint32 block_no, void* buffer, kal_uint32* read_bytes)
{
    async_io_block_queue_t* q = &io->write_q;
    async_io_block_t* b;

    kal_take_mutex(q->lock);

    *read_bytes = 0;

    if (q->head != NULL)
    {
        b = q->head->prev;
        do
        {
            if (block_no == b->block_no)
            {
                kal_mem_cpy(buffer, (kal_uint8*) b->buffer, b->size);
                *read_bytes = b->size;
                break;
            }

            b = b->prev;
        } while (b != q->head);
    }

    kal_give_mutex(q->lock);
}

kal_int32 async_io_attach(async_io_t* io, FS_HANDLE file_h, kal_uint32 block_size)
{
    io->file_h = file_h;
    ASSERT(io->file_h >= 0);

    io->file_lock = mtv_get_lock();

    ASSERT(block_size != 0);
    io->block_size = block_size;

    io->errors = 0;

    /* use the same lock for two queues */
    async_io_init_queue(&io->write_q);
    async_io_init_queue(&io->free_q);

    io->cleanup = NULL;
    io->cleanup_param = NULL;

    return io->file_h;
}

static void async_io_return_to_free_q(async_io_t* io, async_io_block_t* block)
{
    if (async_io_enqueue_block(&io->free_q, block) > 32)
    {
        async_io_block_t* block = async_io_dequeue_block(&io->free_q);
        if (block)
        {
            med_free_ext_mem((void**)&block->buffer);
            med_free_ext_mem((void**)&block);
        }
    }
}

kal_int32 async_io_process_writing(void* io_param)
{
    kal_int32 ret = 0;
    async_io_t* io = (async_io_t*) io_param;
    async_io_block_t* block;

    while ((block = async_io_queue_head(&io->write_q)) != NULL)
    {
        block->state = ASYNC_IO_BLOCK_STATE_WRITING;

        kal_take_mutex(io->file_lock);

        ret = FS_Seek(io->file_h, block->block_no * io->block_size, FS_FILE_BEGIN);
        if (ret >= 0)
        {
            /* write the block */
            kal_uint32 written;
            kal_uint32 pos;

            ret = FS_Write(io->file_h, block->buffer, block->size, &written);
            if (ret >= 0)
            {
                if (written != block->size) {
                    io->errors++;
                }

                ret = FS_GetFilePosition(io->file_h, &pos);
                ASSERT(ret >= 0 && pos == (block->block_no * io->block_size + written));
            }
            else {
                io->errors++;
            }
        }
        else {
            io->errors++;
        }

        kal_give_mutex(io->file_lock);

        block->state = ASYNC_IO_BLOCK_STATE_FREE;

        /* remove the block from the queue only after it is written to file system */
        async_io_return_to_free_q(io, async_io_dequeue_block(&io->write_q));
    }

    return ret;
}

kal_int32 async_io_write(async_io_t* io, kal_uint32 block_no, void* buffer, kal_uint32 buf_size)
{
    async_io_block_t* block;

    ASSERT(buffer != NULL);
    ASSERT(io->block_size > 0 && io->block_size >= buf_size);
    ASSERT(io->file_h != 0);

    if (io->errors > 0)
    {
        /* some errors has happened. reject subsequent writing. */
        return -1;
    }

    /* get one block from free queue */
    block = async_io_dequeue_block(&io->free_q);
    if (block == NULL)
    {
        /* create a new block */
        block = (async_io_block_t*) med_alloc_ext_mem(sizeof(async_io_block_t));
        if (block == NULL) {
            return MTV_E_OUT_OF_MEMORY;
        }

        block->state = ASYNC_IO_BLOCK_STATE_FREE;
        block->buffer = med_alloc_ext_mem(io->block_size);
        if (block->buffer == NULL)
        {
            med_free_ext_mem((void**)&block);
            return MTV_E_OUT_OF_MEMORY;
        }
    }

    ASSERT(block->state == ASYNC_IO_BLOCK_STATE_FREE);

    /* initialize write block */
    block->block_no = block_no;
    block->size = buf_size;
    block->state = ASYNC_IO_BLOCK_STATE_WAITING;

    /* copy the data buffer */
    kal_mem_cpy(block->buffer, buffer, buf_size);

    /* add the block to write queue */
    if (async_io_enqueue_block(&io->write_q, block) == 1)
    {
        /* send message to background task */
        CONSTRUCT_LOCAL_PARAM(media_mtv_async_write_req_struct, req);
        req->io = io;
        mtv_send_outgoing_ilm(MTV_ASYNC_IO_MOD, MSG_ID_MEDIA_MTV_ASYNC_WRITE, req);
    }

    return 0;
}

kal_int32 async_io_read(async_io_t* io, kal_uint32 block_no, void* buffer, kal_uint32* read_bytes)
{
    kal_int32 ret;

    if (io->errors > 0)
    {
        /* some errors has happened. reject subsequent read. */
        return -1;
    }

    async_io_read_block_in_write_queue(io, block_no, buffer, read_bytes);
    if (*read_bytes == 0)
    {
        kal_uint32 read_pos = block_no * io->block_size;
        kal_uint32 pos;

        kal_take_mutex(io->file_lock);

        /* read from file directly */
        ret = FS_Seek(io->file_h, read_pos, FS_FILE_BEGIN);
        if (ret < 0)
        {
            kal_give_mutex(io->file_lock);
            return ret;
        }

        ret = FS_Read(io->file_h, buffer, io->block_size, read_bytes);
        if (ret < 0)
        {
            kal_give_mutex(io->file_lock);
            return ret;
        }

        ret = FS_GetFilePosition(io->file_h, &pos);
        if (ret < 0)
        {
            kal_give_mutex(io->file_lock);
            return ret;
        }
        else {
            ASSERT(pos == (read_pos + *read_bytes));
        }

        kal_give_mutex(io->file_lock);
    }

    return 0;
}

static void async_io_detach_callback(void* param)
{
    async_io_t* io = (async_io_t*) param;

    ASSERT(io->write_q.head == NULL);   /* write queue should be empty */

    async_io_uninit_queue(&io->write_q);
    async_io_uninit_queue(&io->free_q);

    mtv_return_lock(io->file_lock);

    /* invoke client-supplied callback */
    ASSERT(io->cleanup != NULL);
    io->cleanup(io->cleanup_param);
}

kal_int32 async_io_detach(async_io_t* io, async_io_cleanup_t cleanup, void* cleanup_param)
{
    if (cleanup == NULL)
    {
        /* ensure there is no block in write queue */
        async_io_wait_until_empty(&io->write_q);

        async_io_uninit_queue(&io->write_q);
        async_io_uninit_queue(&io->free_q);

        mtv_return_lock(io->file_lock);
    }
    else
    {
        CONSTRUCT_LOCAL_PARAM(media_mtv_async_callback_req_struct, req);
        req->callback = async_io_detach_callback;
        req->param = io;

        io->cleanup = cleanup;
        io->cleanup_param = cleanup_param;

        mtv_send_outgoing_ilm(MTV_ASYNC_IO_MOD, MSG_ID_MEDIA_MTV_ASYNC_CALLBACK, req);
    }

    return 0;
}

#endif  /* defined(__MED_MTV_MOD__) */
