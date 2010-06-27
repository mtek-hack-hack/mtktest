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
 *   mtv_cached_io.c
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

#include "mtv_cached_io.h"
#include "mtv_comm.h"
#include "med_utility.h"

kal_int32 cached_io_attach(cached_io_t* io, FS_HANDLE file_h, kal_uint32 block_size)
{
    kal_int32 i;

    io->file_h = file_h;
    if (io->file_h >= 0)
    {
	    FS_GetFilePosition(file_h, &io->pos);
    }
    else {
        io->pos = 0;
    }

    ASSERT(block_size != 0);
    io->block_size = block_size;

    for (i = 0; i < ARRAY_SIZE(io->blocks); i++)
    {
        cached_block_t* block = &io->blocks[i];

        block->block_no = (kal_uint32) -1;
        block->state = BLOCK_STATE_INVALID;
        block->bytes = 0;
#ifdef _DEBUG
        block->read_hits = block->write_hits = 0;
#endif
        if (io->file_h >= 0)
        {
            block->buffer = (kal_uint8*) med_alloc_ext_mem(block_size);
            ASSERT(block->buffer);
        }
        else
        {
            block->buffer = NULL;
        }
    }

    io->aio = NULL;

    return io->file_h;
}

kal_int32 cached_io_open(cached_io_t* io, kal_wchar* filename, kal_uint32 flags, kal_uint32 block_size)
{
    return cached_io_attach(io, FS_Open(filename, flags), block_size);
}

kal_int32 cached_io_set_async(cached_io_t* io)
{
    kal_int32 ret;

    io->aio = (async_io_t*) med_alloc_ext_mem(sizeof(async_io_t));
    ASSERT(io->aio != NULL);

    ret = async_io_attach(io->aio, io->file_h, io->block_size);
    if (ret < 0) {
        med_free_ext_mem((void**) &io->aio);
    }

    return ret;
}

void cached_io_seek(cached_io_t* io, kal_uint32 pos)
{
    io->pos = pos;
}

kal_uint32 cached_io_tell(cached_io_t* io)
{
    return io->pos;
}

static kal_int32 cached_io_flush_block(cached_io_t* io, cached_block_t* block)
{
    kal_int32 ret = 0;

    if (block->state == BLOCK_STATE_DIRTY)
    {
        if (io->aio)
        {
            ret = async_io_write(io->aio, block->block_no, block->buffer, block->bytes);
            if (ret >= 0) {
                block->state = BLOCK_STATE_VALID;
            }
        }
        else
        {
            kal_uint32 bytes;

            ret = FS_Seek(io->file_h, block->block_no * io->block_size, FS_FILE_BEGIN);
            if (ret >= 0)
            {
                ret = FS_Write(io->file_h, block->buffer, block->bytes, &bytes);
                if (ret >= 0)
                {
                    ASSERT(bytes == block->bytes);
                    block->state = BLOCK_STATE_VALID;
                }
            }
        }
    }

    return ret;
}

static kal_int32 cached_io_fill_block(cached_io_t* io, cached_block_t* block, kal_uint32 block_no)
{
    kal_int32 ret;
    kal_uint32 bytes = 0;

    ASSERT(block->state != BLOCK_STATE_DIRTY);
    ASSERT(io->file_h >= 0);

    if (io->aio)
    {
        ret = async_io_read(io->aio, block_no, block->buffer, &bytes);
    }
    else
    {
        ret = FS_Seek(io->file_h, block_no * io->block_size, FS_FILE_BEGIN);
        if (ret >= 0)
        {
            ret = FS_Read(io->file_h, block->buffer, io->block_size, &bytes);
        }
    }

    if (ret >= 0)
    {
        block->bytes = bytes;
        block->block_no = block_no;
        block->state = BLOCK_STATE_VALID;
#ifdef _DEBUG
        block->read_hits = block->write_hits = 0;
#endif
    }

    return ret;
}

kal_int32 cached_io_read_pos(cached_io_t* io, kal_uint32 pos, void* buf, kal_uint32 size)
{
    kal_uint32 i;
    kal_int32 ret = 0;
    kal_uint32 start_block, end_block;
    kal_uint8* dst = buf;

    ASSERT(size > 0);

    start_block = pos / io->block_size;
    end_block = (pos + size - 1) / io->block_size;

    for (i = start_block; i <= end_block; i++)
    {
        cached_block_t* block = NULL;
        kal_uint32 offset_in_block;
        kal_uint32 size_to_read;
        kal_uint32 bytes;

        if (i == start_block)
        {
            offset_in_block = pos % io->block_size;
            size_to_read = (i != end_block) ? (io->block_size - offset_in_block) : size;
        }
        else
        {
            offset_in_block = 0;
            size_to_read = (i != end_block) ? io->block_size : (pos + size) % io->block_size;
        }

        if (i == io->blocks[0].block_no)
        {
            block = &io->blocks[0];
        }
        else if (i == io->blocks[1].block_no)
        {
            block = &io->blocks[1];
        }
        else if (i == start_block || i == end_block)
        {
            block = &io->blocks[0];

            /* flush buffer R if it is dirty */
            ret = cached_io_flush_block(io, block);
            if (ret < 0) {
                break;
            }

            /* fill buffer R with new content */
            ret = cached_io_fill_block(io, block, i);
            if (ret < 0) {
                break;
            }
        }

        if (block != NULL)
        {
            ASSERT(block->state != BLOCK_STATE_INVALID);

            /* check partially-filled block */
            if (offset_in_block + size_to_read > block->bytes)
            {
                ret = -1;
                break;
            }

            kal_mem_cpy(dst, block->buffer + offset_in_block, size_to_read);
#ifdef _DEBUG
            block->read_hits++;
#endif
        }
        else
        {
            ASSERT(io->file_h >= 0);

            if (io->aio)
            {
                ASSERT(offset_in_block == 0);
                ASSERT(size_to_read == io->block_size);

                ret = async_io_read(io->aio, i, dst, &bytes);
            }
            else
            {
                /* read from file directly */
                ret = FS_Seek(io->file_h, i * io->block_size + offset_in_block, FS_FILE_BEGIN);
                if (ret < 0) {
                    break;
                }
                ret = FS_Read(io->file_h, dst, size_to_read, &bytes);
            }

            if (ret < 0) {
                break;
            }
            else if (size_to_read != bytes)
            {
                ret = -1;
                break;
            }
        }

        dst += size_to_read;
    }

    return ret;
}

kal_int32 cached_io_read(cached_io_t* io, void* buf, kal_uint32 size)
{
    kal_int32 ret;

    ret = cached_io_read_pos(io, io->pos, buf, size);
    if (ret >= 0) {
        io->pos += size;
    }

    return ret;
}

kal_int32 cached_io_write_pos(cached_io_t* io, kal_uint32 pos, void* buf, kal_uint32 size)
{
    kal_uint32 i;
    kal_int32 ret = 0;
    kal_uint32 start_block, end_block;
    kal_uint8* src = buf;

    ASSERT(size > 0);

    start_block = pos / io->block_size;
    end_block = (pos + size - 1) / io->block_size;

    for (i = start_block; i <= end_block; i++)
    {
        cached_block_t* block = NULL;
        kal_uint32 offset_in_block;
        kal_uint32 size_to_write;

        if (i == start_block)
        {
            offset_in_block = pos % io->block_size;
            size_to_write = (i != end_block) ? (io->block_size - offset_in_block) : size;
        }
        else
        {
            offset_in_block = 0;
            size_to_write = (i != end_block) ? io->block_size : (pos + size) % io->block_size;
        }

        if (i == io->blocks[0].block_no)
        {
            block = &io->blocks[0];
        }
        else if (i == io->blocks[1].block_no)
        {
            block = &io->blocks[1];
        }
        else if (i == start_block || i == end_block)
        {
            block = &io->blocks[1];

            if (block->state == BLOCK_STATE_DIRTY)
            {
                if (io->blocks[0].state == BLOCK_STATE_INVALID)
                {
                    /* copy from W to R and swap the buffer pointer */
                    kal_uint8* buf = io->blocks[0].buffer;

                    io->blocks[0] = *block;
                    block->buffer = buf;

                    /* invalidate current block */
                    block->state = BLOCK_STATE_INVALID;
                    block->block_no = (kal_uint32) -1;
                }
                else
                {
                    /* flush buffer W */
                    ret = cached_io_flush_block(io, block);
                    if (ret < 0) {
                        break;
                    }
                }
            }

            /* fill buffer W with new content */
            ret = cached_io_fill_block(io, block, i);
            if (ret < 0) {
                break;
            }
        }

        if (block != NULL)
        {
            ASSERT(block->state != BLOCK_STATE_INVALID);

            kal_mem_cpy(block->buffer + offset_in_block, src, size_to_write);
            block->state = BLOCK_STATE_DIRTY;
#ifdef _DEBUG
            block->write_hits++;
#endif
            if (block->bytes < offset_in_block + size_to_write) {
                block->bytes = offset_in_block + size_to_write;
            }
        }
        else
        {
            ASSERT(io->file_h >= 0);

            if (io->aio)
            {
                ASSERT(offset_in_block == 0);
                ASSERT(size_to_write == io->block_size);

                ret = async_io_write(io->aio, i, src, size_to_write);
                if (ret < 0) {
                    break;
                }
            }
            else
            {
                kal_uint32 bytes;

                /* write to file directly */
                ret = FS_Seek(io->file_h, i * io->block_size + offset_in_block, FS_FILE_BEGIN);
                if (ret < 0) {
                    break;
                }
                ret = FS_Write(io->file_h, src, size_to_write, &bytes);
                if (ret < 0) {
                    break;
                }
                else if (size_to_write != bytes)
                {
                    ret = -1;
                    break;
                }
            }
        }

        src += size_to_write;
    }

    return ret;
}

kal_int32 cached_io_write(cached_io_t* io, void* buf, kal_uint32 size)
{
    kal_int32 ret;

    ret = cached_io_write_pos(io, io->pos, buf, size);
    if (ret >= 0) {
        io->pos += size;
    }

    return ret;
}

kal_int32 cached_io_flush(cached_io_t* io)
{
    kal_int32 i;
    kal_int32 ret = 0;

    for (i = 0; i < ARRAY_SIZE(io->blocks); i++)
    {
        ret = cached_io_flush_block(io, &io->blocks[i]);
        if (ret < 0) {
            break;
        }
    }

    return ret;
}

kal_int32 cached_io_detach(cached_io_t* io)
{
    kal_int32 i;
    kal_int32 ret;

    ret = cached_io_flush(io);

    if (io->aio)
    {
        async_io_detach(io->aio, NULL, NULL);
        med_free_ext_mem((void**) &io->aio);
    }

    for (i = 0; i < ARRAY_SIZE(io->blocks); i++) {
        med_free_ext_mem((void**)&io->blocks[i].buffer);
    }

    io->file_h = -1;

    return ret;
}

kal_int32 cached_io_get_state(FS_HANDLE fh, cached_io_file_state_t* state)
{
    FS_FileInfo fi;
    kal_int32 ret;

    ASSERT(fh >= 0);

    ret = FS_GetFileInfo(fh, &fi);
    if (ret >= 0)
    {
        state->filename = mtv_filename_dup((kal_wchar*)fi.FullName);
        ASSERT(state->filename);

        ret = FS_GetFileSize(fh, &state->size);
        ASSERT(ret >= 0);
    }

    return ret;
}

kal_int32 cached_io_get_state_and_close(cached_io_t* io, cached_io_file_state_t* state)
{
    kal_int32 ret;
    FS_HANDLE fh = io->file_h;

    if (fh < 0) {
        return -1;
    }

    ret = cached_io_detach(io);
    if (ret < 0) /* there may not be enough space to flush buffers */
    {
        FS_Close(fh);   /* close the file handle anyway */
        return ret;     /* return error code */
    }

    if (state) {
        cached_io_get_state(fh, state);
    }

    ret = FS_Close(fh);
    ASSERT(ret >= 0);

    return ret;
}

kal_int32 cached_io_close(cached_io_t* io)
{
    return cached_io_get_state_and_close(io, NULL);
}

static void cached_io_async_cleanup(void* param)
{
    cached_io_t* io = (cached_io_t*) param;
    kal_int32 i;
    kal_int32 ret;

    ASSERT(io->aio != NULL);
    med_free_ext_mem((void**) &io->aio);

    for (i = 0; i < ARRAY_SIZE(io->blocks); i++) {
        med_free_ext_mem((void**)&io->blocks[i].buffer);
    }

    ret = FS_Close(io->file_h);
    ASSERT(ret >= 0);
    io->file_h = -1;

    if (io->cleanup != NULL)
    {
        /* invoke client-supplied callback */
        io->cleanup(io->cleanup_param);
    }
}

kal_int32 cached_io_close_async(cached_io_t* io, cached_io_cleanup_t cleanup, void* cleanup_param)
{
    kal_int32 ret;
    FS_HANDLE fh = io->file_h;

    if (fh < 0) {
        return -1;
    }

    if (io->aio != NULL)
    {
        ret = cached_io_flush(io);

        io->cleanup = cleanup;
        io->cleanup_param = cleanup_param;

        async_io_detach(io->aio, cached_io_async_cleanup, io);
    }
    else
    {
        /* no AIO is available. therefore, still perform synchronous close */
        cached_io_close(io);
        cleanup(cleanup_param);
    }

    return 0;
}

#endif /* defined(__MED_MTV_MOD__) */
