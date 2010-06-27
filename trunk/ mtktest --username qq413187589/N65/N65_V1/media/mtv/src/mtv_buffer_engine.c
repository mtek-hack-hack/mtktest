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
 *   mtv_buffer_engine.c
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

#include "med_utility.h"
#include "med_trc.h"
#include "mtv_buffer_engine.h"
#include "mtv_output_mp4.h"
#include "mtv_output_mp2.h"

#if defined(__MTK_TARGET__)
#include "SST_sla.h"
#endif

#define STREAM_TO_SAMPLE_RATIO  16
#define H264_NALU_LENGTH_SIZE   4

#define BE_MIN_BUFFER_SECONDS 1
#define BE_LIVE_BACK_OFF_SECONDS 2

/* allow the debugger to disable async I/O at runtime */
static kal_bool g_mtv_enable_async_io = KAL_TRUE;

typedef struct
{
    kal_int32 head;
    kal_int32 tail;

} mtv_region_t;

typedef struct
{
    kal_int32 num_rgn;   /**< the number of invalidated regions */
    mtv_region_t rgn[2]; /**< the regions to invalidate */

    kal_int32 pos;       /**< where the sample is written */
    kal_uint32 size;     /**< number of bytes written */

} ss_sample_location_t;

/* helper functions */

kal_wchar* mtv_str_dup(const kal_wchar* from, kal_uint32 max_len)
{
    kal_wchar* str = (kal_wchar*) med_alloc_ext_mem(max_len * sizeof(kal_wchar));
    ASSERT(str != NULL);
    kal_wstrcpy(str, from);

    return str;
}

kal_wchar* mtv_filename_dup(const kal_wchar* from)
{
    return mtv_str_dup(from, MAX_FILE_NAME_LEN);
}

static const kal_wchar* mtv_get_format_extension_name(mtv_recording_format_t format)
{
    if (format == MTV_RECORDING_FORMAT_MP4) {
        return L".mp4";
    }
    else if (format == MTV_RECORDING_FORMAT_MP2) {
        return L".mp2";
    }
    else
	{
        return L"";
    }
}

kal_wchar* mtv_generate_new_filename(const kal_wchar* dir, const kal_wchar* basename, const kal_wchar* extname)
{
    kal_uint32 i;
    kal_wchar* fname;
    kal_wchar serial_num[7];

    fname = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    ASSERT(fname);
    for (i = 0; i < 10000; i++)
    {
        if (i == 0)
        {
            kal_wstrcpy(fname, dir);
            kal_wstrcat(fname, basename);
            kal_wstrcat(fname, extname);
        }
        else
        {
            kal_wstrcpy(fname, dir);
            kal_wstrcat(fname, basename);
            kal_wsprintf(serial_num, "(%d)", i);
            kal_wstrcat(fname, serial_num);
            kal_wstrcat(fname, extname);
        }

        if (FS_GetAttributes(fname) < 0) {
            return fname; /* this file does not exist! */
        }
    }

    return NULL;
}

kal_uint32 mtv_process_files(const kal_wchar* dir, const kal_wchar* pattern, mtv_process_file_callback process_file, void* callback_param)
{
    FS_HANDLE ff;
    FS_DOSDirEntry fi;
    kal_uint32 processed = 0;
    kal_wchar* to_find = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    kal_wchar* filename = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    kal_wchar* to_process = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));

    kal_wstrcpy(to_find, dir);
    kal_wstrcat(to_find, pattern);
    if ((ff = FS_FindFirst(to_find, 0, 0, &fi, filename, MAX_FILE_NAME_LEN)) >= 0)
    {
        do
        {
            if (!(fi.Attributes & FS_ATTR_DIR))
            {
                kal_wstrcpy(to_process, dir);
                kal_wstrcat(to_process, filename);
                if (process_file && !process_file(callback_param, to_process)) {
                    break;
                }

                processed++;
            }
        } while ((FS_FindNext(ff, &fi, filename, MAX_FILE_NAME_LEN) == FS_NO_ERROR));

        FS_FindClose(ff);
    }

    med_free_ext_mem((void**) &filename);
    med_free_ext_mem((void**) &to_process);
    med_free_ext_mem((void**) &to_find);

    return processed;
}

static kal_int32 mtv_close_and_delete_file(FS_HANDLE fh)
{
    FS_FileInfo fi;
    kal_int32 ret;

    ret = FS_GetFileInfo(fh, &fi);
    if (ret >= 0)
    {
        kal_wchar* fname = mtv_filename_dup((kal_wchar*)fi.FullName);

        ret = FS_Close(fh);
        ASSERT(ret >= 0);

        ret = FS_Delete(fname);
        ASSERT(ret >= 0);

        med_free_ext_mem((void**)&fname);
    }

	return mtv_error_from_fs(ret);
}

static mtv_result_t copy_file_region(FS_HANDLE dst, FS_HANDLE src, kal_int32 pos, kal_int32 size)
{
    kal_int32 ret;
    kal_uint8* buf;
	kal_uint32 remaining;

    ASSERT(size > 0);

    ret = FS_Seek(src, pos, FS_FILE_BEGIN);
    if (ret < 0) {
        return mtv_error_from_fs(ret);
    }

#define COPY_REGION_BUFFER_SIZE 2048
    buf = (kal_uint8*) med_alloc_ext_mem(COPY_REGION_BUFFER_SIZE);
    ASSERT(buf);

    remaining = (kal_uint32) size;
    do
    {
        kal_uint32 read, written;
        kal_uint32 to_read = remaining < COPY_REGION_BUFFER_SIZE ? remaining : COPY_REGION_BUFFER_SIZE;

        ret = FS_Read(src, buf, to_read, &read);
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            goto copy_region_cleanup;
        }
        ASSERT(to_read == read);

        ret = FS_Write(dst, buf, read, &written);
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            goto copy_region_cleanup;
        }
        ASSERT(read == written);

        remaining -= written;
    } while (remaining != 0);

copy_region_cleanup:

    med_free_ext_mem((void**)&buf);
    return ret;
}

/* sample stream operations */

static mtv_result_t ss_reset(mtv_sample_stream_t* pthis)
{
    ASSERT(pthis->stream_h >= 0);

    pthis->num_rgn =0;

    return MTV_S_OK;
}

static kal_int32 ss_calc_offset(mtv_sample_stream_t* pthis, kal_int32 pos)
{
    kal_int32 i;
    kal_int32 pos_so_far = 0;

    /* iterate each region in order to calculate the offset */
    for (i = 0; i < pthis->num_rgn; i++)
    {
        if (pos >= pthis->head[i] && pos < pthis->tail[i]) {
            return pos_so_far + pos - pthis->head[i];
        }

        pos_so_far += pthis->tail[i] - pthis->head[i];
    }

    return -1;  /* the pos is not in regions */
}

static void ss_sanity_check(mtv_sample_stream_t* pthis)
{
    kal_int32 i, j;

    ASSERT(pthis->stream_h >= 0);
    ASSERT(pthis->max_stream_size > 0);

    ASSERT(pthis->num_rgn >= 0 && pthis->num_rgn <= ARRAY_SIZE(pthis->head));
    for (i = 0; i < pthis->num_rgn; i++)
    {
        ASSERT(pthis->head[i] >= 0 && pthis->head[i] <= pthis->max_stream_size);
        ASSERT(pthis->tail[i] >= 0 && pthis->tail[i] <= pthis->max_stream_size);
        ASSERT(pthis->head[i] <= pthis->tail[i]);

        if (i == 1)
        {
            ASSERT(pthis->head[i] == 0);
        }

        /* check overlaping */
        for (j = 0; j < pthis->num_rgn; j++)
        {
            if (j != i)
            {
                ASSERT(pthis->head[i] < pthis->head[j] || pthis->head[i] >= pthis->tail[j]);
                ASSERT(pthis->tail[i] <= pthis->head[j] || pthis->tail[i] >= pthis->tail[j]);
            }
        }
    }
}

static void ss_check_read_pos(mtv_sample_stream_t* pthis, kal_int32 pos)
{
    ASSERT(ss_calc_offset(pthis, pos) >= 0);
}

mtv_result_t ss_close_ex(mtv_sample_stream_t* pthis, mtv_sample_stream_closed_t* closed_state)
{
    kal_int32 ret;
    FS_FileInfo fi;

    if (pthis->stream_h < 0) {
        return MTV_E_FAIL;
    }

    ret = cached_io_detach(&pthis->cio);
    if (ret >= 0)
    {
        ret = FS_GetFileInfo(pthis->stream_h, &fi);
        if (ret >= 0)
        {
            closed_state->filename = mtv_filename_dup((kal_wchar*)fi.FullName);
            ASSERT(closed_state->filename);

            ret = FS_GetFileSize(pthis->stream_h, &closed_state->size);
            if (ret >= 0)
            {
                ret = FS_Close(pthis->stream_h);
                ASSERT(ret >= 0);
            }
        }

        pthis->stream_h = -1;
    }

    return mtv_error_from_fs(ret);
}

mtv_result_t ss_reopen(mtv_sample_stream_t* pthis, mtv_sample_stream_closed_t* closed_state)
{
    kal_int32 ret;

    ASSERT(pthis->stream_h < 0);
    ret = FS_Open(closed_state->filename, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (ret < 0) {
        return mtv_error_from_fs(ret);
    }
    else
    {
        pthis->stream_h = ret;

        ret = cached_io_attach(&pthis->cio, pthis->stream_h, STREAM_CACHE_BLOCK_SIZE);
        if (ret < 0)
        {
            FS_Close(pthis->stream_h);
            return mtv_error_from_fs(ret);
        }
    }

    if (g_mtv_enable_async_io) {
        cached_io_set_async(&pthis->cio);
    }

    return MTV_S_OK;
}

static mtv_result_t ss_write_buffer(mtv_sample_stream_t* pthis, kal_int32 num_parts, mtv_packet_t* parts, ss_sample_location_t* location)
{
    kal_int32 ret;
    kal_int32 i;
    kal_uint32 stream_rgn;
    kal_int32 inv_rgn = 0;
    kal_uint32 size = 0;

    ASSERT(num_parts >= 1);
    for (i = 0; i < num_parts; i++) {
        size += parts[i].size;
    }

    if (size == 0 || (kal_int32) size > pthis->max_stream_size)
    {
        SHOULD_NOT_HAPPEN("Invalid buffer size!");
        return MTV_E_INVALID_PARAM;
    }

    ss_sanity_check(pthis);

    if (pthis->num_rgn == 0)
    {
        pthis->num_rgn++;
        pthis->head[0] = 0;
        pthis->tail[0] = 0;
    }

    stream_rgn = pthis->num_rgn - 1;    /* write to the last region by default */

    if ((pthis->tail[stream_rgn] + (kal_int32) size) <= pthis->max_stream_size)
    {
        /*
         *
         * |==============|+++++++++++++++++|-----------|
         *               tail            new_tail   max_stream_size
         */
        cached_io_seek(&pthis->cio, pthis->tail[stream_rgn]);
        for (i = 0; i < num_parts; i++)
        {
            ret = cached_io_write(&pthis->cio, parts[i].data, parts[i].size);
            if (ret < 0) {
                return mtv_error_from_fs(ret);
            }
        }

        location->pos = location->rgn[0].head = pthis->tail[stream_rgn];
        location->rgn[0].tail = pthis->tail[stream_rgn] + size;

        if (pthis->num_rgn == 2)
        {
            if (location->rgn[0].tail > pthis->head[0] && location->rgn[0].tail <= pthis->tail[0])
            {
                /*
                 *                                    new tail
                 *                              ++++++++|
                 * |===========================|---|=============|
                 *                            tail           max_stream_size
                 */

                /* adjust the head position of partially overwritten region */
                pthis->head[0] = location->rgn[0].tail;

                if (pthis->head[0] == pthis->tail[0])
                {
                    /* the previous region is completely overwritten */
                    pthis->num_rgn = 1;
                    pthis->head[0] = 0;
                    stream_rgn = 0;
                }
            }
        }

        pthis->tail[stream_rgn] = location->rgn[0].tail;

        ss_sanity_check(pthis);
    }
    else
    {
        kal_int32 padding_bytes;

        if (!pthis->allow_wrap_around) {
            return MTV_E_OVER_LIMIT;
        }

        /*
         *    size                        padding_bytes
         * |++++++++++++++|------------|00000000000000000|
         *             new_tail       tail           max_stream_size
         */
        padding_bytes = pthis->max_stream_size - pthis->tail[stream_rgn];
        ASSERT(padding_bytes >= 0);
        if (padding_bytes > 0)
        {
            /*
             * although we don't overwrite the padding area, we still need to invalidate
             * this region so that samples in this area can be invalidated
             */
            location->rgn[0].head = pthis->tail[stream_rgn];
            location->rgn[0].tail = pthis->tail[stream_rgn] + padding_bytes;
            inv_rgn++;
        }

        /* write the buffer in second region entirely */
        ASSERT(size > 0);
        cached_io_seek(&pthis->cio, 0);
        for (i = 0; i < num_parts; i++)
        {
            ret = cached_io_write(&pthis->cio, parts[i].data, parts[i].size);
            if (ret < 0) {
                return mtv_error_from_fs(ret);
            }
        }

        location->pos = location->rgn[inv_rgn].head = 0;
        location->rgn[inv_rgn].tail = size;

        if (pthis->num_rgn == 1)
        {
            /* extend current region */
            pthis->tail[stream_rgn] = pthis->max_stream_size;

            if (location->rgn[inv_rgn].tail >= pthis->head[stream_rgn] &&
                location->rgn[inv_rgn].tail < pthis->tail[stream_rgn])
            {
                /*
                 *               wr[inv_rgn].tail
                 *  +++++++++++++++++++++|                 ++++++
                 * |----------------|=====================|------|
                 *                                           max_stream_size
                 */
                pthis->head[stream_rgn] = location->rgn[inv_rgn].tail;
            }

            /* add new region */
			pthis->num_rgn++;
            pthis->head[1] = 0;
            pthis->tail[1] = location->rgn[inv_rgn].tail;
        }
        else if (pthis->num_rgn == 2)
        {
            /*
             *   wr[inv_rgn].tail
             * ++++|                        +++++++++++++++++
             * |===========================|---|=============|
             *                            tail           max_stream_size
             */
            pthis->head[0] = location->rgn[inv_rgn].tail;
            pthis->tail[0] = pthis->max_stream_size;
            pthis->head[1] = 0;
            pthis->tail[1] = location->rgn[inv_rgn].tail;
        }
        else
        {
            NOT_REACHED("Impossible region number?!");
        }

        ss_sanity_check(pthis);
    }

    location->num_rgn = inv_rgn + 1;
    location->size = size;
    ASSERT(location->num_rgn == 1 || location->num_rgn == 2);

    return MTV_S_OK;
}

static mtv_result_t ss_read_sample(mtv_sample_stream_t* pthis, kal_int32 pos, kal_uint8* buf, kal_uint32 size)
{
    kal_int32 ret;
    kal_int32 rgn;

    ss_sanity_check(pthis);
    ss_check_read_pos(pthis, pos);

    /* find the region where the read position belongs to*/
    for (rgn = 0; rgn < pthis->num_rgn; rgn++)
    {
        if (pos >= pthis->head[rgn] && pos < pthis->tail[rgn]) {
            break;
        }
    }
    if (rgn == pthis->num_rgn)
    {
        NOT_REACHED("Invalid pos is given!?");
        return MTV_E_INVALID_PARAM;
    }

    if (pos + (kal_int32) size <= pthis->tail[rgn])
    {
        ret = cached_io_read_pos(&pthis->cio, pos, buf, size);
        if (ret < 0) {
            return mtv_error_from_fs(ret);
        }
    }
    else
    {
        kal_int32 padding_bytes;

        if (!pthis->allow_wrap_around) {
            return MTV_E_OVER_LIMIT;
        }

        if (rgn == pthis->num_rgn - 1) {
            return MTV_E_OVER_LIMIT;
        }

        /*
         *        size                    padding_bytes
         * |==============|------------|00000000000000000|
         *                            pos          max_stream_size
         */
        padding_bytes = pthis->tail[rgn] - pos;
        ASSERT(padding_bytes >= 0);

        /* just read the sample from the second region */
        ASSERT(pthis->head[rgn + 1] + (kal_int32) size <= pthis->tail[rgn + 1]);
        ret = cached_io_read_pos(&pthis->cio, pthis->head[rgn + 1], buf, size);
        if (ret < 0) {
            return mtv_error_from_fs(ret);
        }
    }

    return MTV_S_OK;
}

__inline kal_int32 ss_get_maximum_size(mtv_sample_stream_t* pthis)
{
    return pthis->max_stream_size;
}

__inline mtv_result_t ss_set_maximum_size(mtv_sample_stream_t* pthis, kal_int32 max_stream_size)
{
    /* only allow increasing */
    if (max_stream_size <= pthis->max_stream_size || max_stream_size == 0) {
        return MTV_E_INVALID_PARAM;
    }

    if (pthis->num_rgn <= 1)
    {
        /*
         * |-------|==========================|------|################|
         * 0      head                       tail      increased part
         *  ^^^^^^^ head empty space
         */

        /*
         * simply increase the maximum size and assume the head empty space is small and
         * will not waste too much space.
         */
    }
    else if (pthis->num_rgn == 2)
    {
        /*
         * |======*=======|------------|======*======|################|
         * 0     pos     tail         head   pos   max_stream_size
         *                 ^^^^^^^^^^^^ empty space
         */

        kal_int32 new_region = pthis->num_rgn++;

        /*
         * create a new region because we assume the empty space is small and
         * will not waste too much space.
         */
        pthis->head[new_region] = pthis->max_stream_size;
        pthis->tail[new_region] = pthis->max_stream_size;

        /* wrap around need to be turned off */
        pthis->allow_wrap_around = KAL_FALSE;
    }
	else if (pthis->num_rgn == 3)
	{
        ASSERT(pthis->tail[2] < max_stream_size);
        ASSERT(pthis->allow_wrap_around == KAL_FALSE);
	}
    else
    {
        NOT_REACHED("Impossible region number!?");
        return MTV_E_FAIL;
    }

    pthis->max_stream_size = max_stream_size;

    return MTV_S_OK;
}

static mtv_result_t ss_open_from_file_handle(mtv_sample_stream_t* pthis, FS_HANDLE stream_h, kal_uint32 max_stream_size, kal_bool allow_wrap_around, kal_bool use_async_io)
{
    ASSERT(max_stream_size >= MIN_SAMPLE_STREAM_SIZE);

    ASSERT(stream_h >= 0);
    pthis->stream_h = stream_h;
    if (cached_io_attach(&pthis->cio, pthis->stream_h, STREAM_CACHE_BLOCK_SIZE) < 0)
    {
        FS_Close(pthis->stream_h);
        return mtv_error_from_fs(pthis->stream_h);
    }
    if (use_async_io) {
        cached_io_set_async(&pthis->cio);
    }

    pthis->max_stream_size = max_stream_size;
    pthis->allow_wrap_around = allow_wrap_around;

    ss_reset(pthis);

    pthis->close_ex = ss_close_ex;
    pthis->reopen = ss_reopen;
    pthis->read_sample = ss_read_sample;

    return MTV_S_OK;
}

static mtv_result_t ss_open(mtv_sample_stream_t* pthis, kal_wchar* file, kal_uint32 max_stream_size, kal_bool allow_wrap_around)
{
    FS_HANDLE stream_h;

    stream_h = FS_Open(file, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (stream_h < 0) {
        return mtv_error_from_fs(stream_h);
    }

    return ss_open_from_file_handle(pthis, stream_h, max_stream_size, allow_wrap_around, g_mtv_enable_async_io);
}

typedef struct mtv_be_ss_checkpoint_t
{
    kal_int32 max_stream_size;

    kal_int32 num_rgn;
    kal_int32 head[3];
    kal_int32 tail[3];

    kal_wchar filename[MAX_FILE_NAME_LEN];

} mtv_be_ss_checkpoint_t;

mtv_result_t ss_save_checkpoint(mtv_sample_stream_t* pthis, cached_io_t* cp_h)
{
    mtv_be_ss_checkpoint_t* ss_cp = NULL;
    FS_FileInfo fi;
    kal_int32 ret;

    /* flush all cached content */
    ret = cached_io_flush(&pthis->cio);
    if (ret < 0) {
        goto cleanup;
    }

    ss_cp = (mtv_be_ss_checkpoint_t*) med_alloc_ext_mem(sizeof(*ss_cp));
    ASSERT(ss_cp);

    ss_cp->max_stream_size = pthis->max_stream_size;
    ss_cp->num_rgn = pthis->num_rgn;

    ASSERT(sizeof(ss_cp->head) == sizeof(pthis->head));
    kal_mem_cpy(ss_cp->head, pthis->head, sizeof(pthis->head));
    ASSERT(sizeof(ss_cp->tail) == sizeof(pthis->tail));
    kal_mem_cpy(ss_cp->tail, pthis->tail, sizeof(pthis->tail));

    ret = FS_GetFileInfo(pthis->stream_h, &fi);
    if (ret < 0) {
        goto cleanup;
    }
    kal_wstrcpy(ss_cp->filename, (kal_wchar*) fi.FullName);

    ret = cached_io_write(cp_h, ss_cp, sizeof(*ss_cp));

cleanup:

    med_free_ext_mem((void**) &ss_cp);

    return mtv_error_from_fs(ret);
}

static mtv_result_t ss_open_from_checkpoint(mtv_sample_stream_t* pthis, cached_io_t* cp_h)
{
    mtv_be_ss_checkpoint_t* ss_cp = NULL;
    FS_HANDLE stream_h = -1;
    kal_int32 ret;

    ss_cp = (mtv_be_ss_checkpoint_t*) med_alloc_ext_mem(sizeof(*ss_cp));
    ASSERT(ss_cp);

    ret = cached_io_read(cp_h, ss_cp, sizeof(*ss_cp));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    stream_h = FS_Open(ss_cp->filename, FS_READ_ONLY);
    if (stream_h < 0)
    {
        ret = mtv_error_from_fs(stream_h);
        goto cleanup;
    }

    ret = ss_open_from_file_handle(pthis, stream_h, ss_cp->max_stream_size, KAL_FALSE, KAL_FALSE);
    if (ret < 0) {
        goto cleanup;
    }

    pthis->num_rgn = ss_cp->num_rgn;

    ASSERT(sizeof(ss_cp->head) == sizeof(pthis->head));
    kal_mem_cpy(pthis->head, ss_cp->head, sizeof(pthis->head));
    ASSERT(sizeof(ss_cp->tail) == sizeof(pthis->tail));
    kal_mem_cpy(pthis->tail, ss_cp->tail, sizeof(pthis->tail));

cleanup:

    if (ret < 0 && stream_h >= 0)
    {
        FS_Close(stream_h);
        FS_Delete(ss_cp->filename);
    }

    med_free_ext_mem((void**) &ss_cp);
    return ret;
}

static mtv_result_t ss_close(mtv_sample_stream_t* pthis)
{
    if (pthis->stream_h >= 0)
    {
        cached_io_detach(&pthis->cio);

        mtv_close_and_delete_file(pthis->stream_h);
        pthis->stream_h = -1;
    }

    return MTV_S_OK;
}

/* index stream operations */

static kal_int32 si_check_pos(mtv_sample_index_t* pthis, kal_int32 pos)
{
    if (pos < 0) {
        return -1;  /* out of range */
    }
    else if (pos >= pthis->max_index_size) {
        return -1;   /* out of range */
    }

    if (pthis->head < pthis->tail)
    {
        if (pos < pthis->head) {
            return -1;  /* fall behind */
        }
        else if (pos > pthis->tail) {
            return 1;   /* too fast */
        }

        return 0;   /* in correct range */
    }
    else if (pthis->head > pthis->tail)
    {
        if (pos > pthis->tail && pos < pthis->head) {
            return -1;  /* treat it as fall behind */
        }

        return 0; /* in correct range */
    }
    else /* pthis->head == pthis->tail */
    {
        if (pos != pthis->head) {
            return -1;
        }

        return 0;
    }
}

static void si_sanity_check(mtv_sample_index_t* pthis)
{
    ASSERT(pthis->index_h >= 0);
    ASSERT(pthis->max_index_size > 0);
    ASSERT(pthis->head >= 0 && pthis->head < pthis->max_index_size);
    ASSERT(pthis->tail >= 0 && pthis->tail < pthis->max_index_size);
	ASSERT(si_check_pos(pthis, pthis->next) == 0);
}

static kal_int32 si_get_entry_count(mtv_sample_index_t* pthis)
{
    if (pthis->head <= pthis->tail) {
        return  pthis->tail - pthis->head;
    }
    else {
        return pthis->max_index_size - pthis->head + pthis->tail;
    }
}

static mtv_result_t si_peek_entry_by_pos(mtv_sample_index_t* pthis, mtv_sample_index_entry_t* entry, kal_int32 pos)
{
    kal_int32 ret;

    if (pos == pthis->tail || si_check_pos(pthis, pos) != 0) {
        return MTV_E_FAIL;  /* invalid position */
    }

	si_sanity_check(pthis);

    ret = cached_io_read_pos(&pthis->cio, pos * sizeof(*entry), entry, sizeof(*entry));
    return mtv_error_from_fs(ret);
}

static mtv_result_t si_peek_entry_by_index(mtv_sample_index_t* pthis, mtv_sample_index_entry_t* entry, kal_int32 index)
{
    kal_int32 target = (pthis->head + index) % pthis->max_index_size;
    return si_peek_entry_by_pos(pthis, entry, target);
}

static mtv_result_t si_peek_entry(mtv_sample_index_t* pthis, mtv_sample_index_entry_t* entry)
{
    return si_peek_entry_by_pos(pthis, entry, pthis->next);
}

static kal_uint32 si_get_first_timestamp(mtv_sample_index_t* pthis)
{
    kal_uint32 saved_next;
    mtv_sample_index_entry_t entry;
    mtv_result_t ret;

    if (pthis->head == pthis->tail) {
        return 0;
    }

    saved_next = pthis->next;

    pthis->next = pthis->head;
    ret = si_peek_entry(pthis, &entry);
    ASSERT(ret >= 0);

    pthis->next = saved_next;

    return ret >= 0 ? entry.timestamp : 0;
}

static kal_uint32 si_get_last_timestamp(mtv_sample_index_t* pthis)
{
    kal_uint32 saved_next;
    mtv_sample_index_entry_t entry;
    mtv_result_t ret;

    if (pthis->head == pthis->tail) {
        return 0;
    }

    saved_next = pthis->next;

    pthis->next = pthis->tail - 1;
    if (pthis->tail < 0) {
        pthis->next = pthis->max_index_size - 1;
    }
    ret = si_peek_entry(pthis, &entry);
    ASSERT(ret >= 0);

    pthis->next = saved_next;

    return ret >= 0 ? entry.timestamp : 0;
}

static kal_uint32 si_get_duration(mtv_sample_index_t* pthis)
{
    kal_uint32 first_ts, last_ts;

    last_ts = si_get_last_timestamp(pthis);
    first_ts = si_get_first_timestamp(pthis);

    return last_ts - first_ts;
}

static kal_int32 si_get_min_safe_prebuffer(mtv_sample_index_t* pthis)
{
	kal_int32 m = si_get_entry_count(pthis) / 16 + 1;
	kal_int32 n;

	if (pthis->info.type == MTV_STREAM_AUDIO) {
		n = 25 * 8; /* assume one audio entry = 40ms */
	}
	else {
		n = 30 * 8; /* assume one video entry = 33ms */
	}

	return m < n ? m : n;
}

static mtv_result_t si_move_to_time(mtv_sample_index_t* pthis, kal_uint32 time)
{
    kal_int32 ret;
    kal_int32 low, high, probe;
    mtv_sample_index_entry_t entry;
	kal_int32 num_entries;

	/*
	 * Although we assume the reading rate is equal to the writing rate,
	 * the beginning of the buffer still can be easily overwritten depending
	 * on the implemtation of the reading part. Therefore, we keep some minimum
	 * distance from the beginning for safety.
	 */
	num_entries = si_get_entry_count(pthis);
	low = si_get_min_safe_prebuffer(pthis);
    high = num_entries - 1;

    if (low >= num_entries) {
        return MTV_E_FAIL;
    }

    /* use binary search to speed-up the seeking */
	ASSERT(high >= low);
    probe = low + (high - low) / 2;
    while (low <= high)
    {
        ret = si_peek_entry_by_index(pthis, &entry, probe);
        ASSERT(ret >= 0);

        if (entry.timestamp > time) {
            high = probe - 1;
        }
        else if (entry.timestamp < time) {
            low = probe + 1;
        }
        else {
            break;  /* exact match */
        }
        probe = low + (high - low) / 2;
    }

    /* move to the last probe position */
    pthis->next = (pthis->head + probe) % pthis->max_index_size;
	si_sanity_check(pthis);
    return MTV_S_OK;
}

static mtv_result_t si_add_entry(mtv_sample_index_t* pthis, mtv_sample_index_entry_t* entry)
{
    kal_int32 ret;

    ret = cached_io_write_pos(&pthis->cio, pthis->tail * sizeof(mtv_sample_index_entry_t), entry, sizeof(*entry));
    if (ret < 0) {
        return mtv_error_from_fs(ret);
    }

    if (++pthis->tail >= pthis->max_index_size) {
        pthis->tail = 0;
    }
    ASSERT(pthis->head != pthis->tail); /* not allow to be full */
    si_sanity_check(pthis);

    return mtv_error_from_fs(ret);
}

static mtv_result_t si_move_to_head(mtv_sample_index_t* pthis)
{
    pthis->next = pthis->head;

    si_sanity_check(pthis);

    return MTV_S_OK;
}

static mtv_result_t si_move_to_tail(mtv_sample_index_t* pthis)
{
    pthis->next = pthis->tail;

    si_sanity_check(pthis);

    return MTV_S_OK;
}

static mtv_result_t si_move_to_next_entry(mtv_sample_index_t* pthis)
{
    ASSERT(pthis->max_index_size > 0);

    if (++pthis->next >= pthis->max_index_size)
    {
        pthis->next = 0;
    }

    si_sanity_check(pthis);

    return MTV_S_OK;
}

static mtv_result_t si_discard_samples(mtv_sample_index_t* pthis, kal_int32 begin, kal_int32 end)
{
    kal_int32 ret;

	ASSERT(begin <= end);

    while (pthis->head != pthis->tail)  /* until empty */
    {
        kal_int32 entry_pos;
        mtv_sample_index_entry_t entry;

        entry_pos = pthis->head * sizeof(mtv_sample_index_entry_t);
        ret = cached_io_read_pos(&pthis->cio, entry_pos, &entry, sizeof(entry));
        if (ret < 0) {
            return mtv_error_from_fs(ret);
        }

        if (entry.pos < (kal_uint32) begin || entry.pos >= (kal_uint32) end)
        {
            break;
        }

        if (++pthis->head >= pthis->max_index_size) {
            pthis->head = 0;
        }

		if (si_check_pos(pthis, pthis->next) != 0)
		{
			/*
			 * The writing rate is bigger than the reading rate. We can do
			 * nothing but discarding some samples that will be soonly
			 * overwritten to keep smooth playback for a while.
			 *
			 * @see si_move_to_time.
			 */
			pthis->next = (pthis->head + si_get_min_safe_prebuffer(pthis)) % pthis->max_index_size;
		}

        si_sanity_check(pthis);
    }

	return MTV_S_OK;
}

static mtv_result_t si_reset(mtv_sample_index_t* pthis)
{
    pthis->head = 0;
    pthis->tail = 0;
    pthis->next = 0;

    pthis->curr_ts = pthis->tail_ts = 0;

    si_sanity_check(pthis);

	/* it is not necessary to recreate the index file because all pointer are reset */

    return MTV_S_OK;
}

static mtv_result_t si_open_from_file_handle(mtv_sample_index_t* pthis, FS_HANDLE index_h, mtv_stream_info_t* stream_info, kal_int32 max_index_size, kal_bool use_async_io)
{
    ASSERT(pthis->index_h >= 0);
    pthis->index_h = index_h;
    if (cached_io_attach(&pthis->cio, pthis->index_h, INDEX_CACHE_BLOCK_SIZE) < 0)
    {
        FS_Close(pthis->index_h);
        return mtv_error_from_fs(pthis->index_h);
    }
    if (use_async_io) {
        cached_io_set_async(&pthis->cio);
    }

    max_index_size /= sizeof(mtv_sample_index_entry_t);
    ASSERT(max_index_size > 0);
    pthis->max_index_size = max_index_size;

    pthis->info = *stream_info;
    mtv_copy_dec_config_extra(&pthis->info.dec_config, &stream_info->dec_config);

    pthis->get_entry_count = si_get_entry_count;
    pthis->get_duration = si_get_duration;
    pthis->move_to_next_entry = si_move_to_next_entry;
    pthis->peek_entry = si_peek_entry;
    pthis->move_to_head = si_move_to_head;

    si_reset(pthis);

    return MTV_S_OK;
}

static mtv_result_t si_open(mtv_sample_index_t* pthis, kal_wchar* file, mtv_stream_info_t* stream_info, kal_int32 max_index_size)
{
    FS_HANDLE index_h;

    index_h = FS_Open(file, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (index_h < 0) {
        return mtv_error_from_fs(index_h);
    }

    return si_open_from_file_handle(pthis, index_h, stream_info, max_index_size, g_mtv_enable_async_io);
}

typedef struct mtv_be_si_checkpoint_t
{
    kal_int32 head, tail;
    mtv_stream_info_t info;
    kal_int32 max_index_size;

    kal_wchar filename[MAX_FILE_NAME_LEN];

} mtv_be_si_checkpoint_t;

mtv_result_t si_save_checkpoint(mtv_sample_index_t* pthis, cached_io_t* cp_h)
{
    mtv_be_si_checkpoint_t* si_cp = NULL;
    FS_FileInfo fi;
    kal_int32 ret;

    /* flush all cached content */
    ret = cached_io_flush(&pthis->cio);
    if (ret < 0) {
        goto cleanup;
    }

    si_cp = (mtv_be_si_checkpoint_t*) med_alloc_ext_mem(sizeof(*si_cp));
    ASSERT(si_cp);

    si_cp->head = pthis->head;
    si_cp->tail = pthis->tail;
    si_cp->max_index_size = pthis->max_index_size;
    si_cp->info = pthis->info;

    ret = FS_GetFileInfo(pthis->index_h, &fi);
    if (ret < 0) {
        goto cleanup;
    }
    kal_wstrcpy(si_cp->filename, (kal_wchar*) fi.FullName);

    ret = cached_io_write(cp_h, si_cp, sizeof(*si_cp));

cleanup:

    med_free_ext_mem((void**) &si_cp);

    return mtv_error_from_fs(ret);
}

static mtv_result_t si_open_from_checkpoint(mtv_sample_index_t* pthis, cached_io_t* cp_h)
{
    mtv_be_si_checkpoint_t* si_cp = NULL;
    FS_HANDLE index_h = -1;
    kal_int32 ret;

    si_cp = (mtv_be_si_checkpoint_t*) med_alloc_ext_mem(sizeof(*si_cp));
    ASSERT(si_cp);

    ret = cached_io_read(cp_h, si_cp, sizeof(*si_cp));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    index_h = FS_Open(si_cp->filename, FS_READ_ONLY);
    if (index_h < 0)
    {
        ret = mtv_error_from_fs(index_h);
        goto cleanup;
    }

    ret = si_open_from_file_handle(pthis, index_h, &si_cp->info, si_cp->max_index_size * sizeof(mtv_sample_index_entry_t), KAL_FALSE);
    if (ret < 0) {
        goto cleanup;
    }

    pthis->head = si_cp->head;
    pthis->tail = si_cp->tail;
    pthis->next = pthis->head;

cleanup:

    if (ret < 0 && index_h >= 0)
    {
        FS_Close(index_h);
        FS_Delete(si_cp->filename);
    }

    med_free_ext_mem((void**) &si_cp);
    return ret;
}

static FS_HANDLE si_create_new_index_file(mtv_sample_index_t* pthis)
{
    kal_int32 ret;
    FS_FileInfo fi;

    ret = FS_GetFileInfo(pthis->index_h, &fi);
    if (ret >= 0)
    {
        /* generate a new filename */
        kal_wchar* index_fname = kal_wstrcat(mtv_filename_dup((kal_wchar*)fi.FullName), L"~");
        FS_HANDLE index_h;

        index_h = FS_Open(index_fname, FS_READ_WRITE | FS_CREATE_ALWAYS);
        med_free_ext_mem((void**)&index_fname);

        return index_h;
    }

    return -1;
}

static mtv_result_t si_compact(mtv_sample_index_t* pthis)
{
    kal_int32 ret;
    kal_int32 entry_count = si_get_entry_count(pthis);
    kal_int32 next = pthis->next >= pthis->head ? pthis->next - pthis->head : pthis->max_index_size - pthis->head + pthis->next;
    FS_HANDLE index_h;

    ASSERT(pthis->head > pthis->tail);

    index_h = si_create_new_index_file(pthis);
    if (index_h < 0) {
        return mtv_error_from_fs(index_h);
    }

    /*
     * |======*=======|------------|=============|
     * 0     next    tail         head     max_index_size
     *
     * becomes
     *
     * |==================*========|-------------|
     * head              next     tail
     */

    ret = copy_file_region(index_h, pthis->index_h,
		pthis->head * sizeof(mtv_sample_index_entry_t),
		(pthis->max_index_size - pthis->head) * sizeof(mtv_sample_index_entry_t));
    if (ret < 0)
    {
        mtv_close_and_delete_file(index_h);
        return ret;
    }

    ret = copy_file_region(index_h, pthis->index_h,
		0,
		pthis->tail * sizeof(mtv_sample_index_entry_t));
    if (ret < 0)
    {
        mtv_close_and_delete_file(index_h);
        return ret;
    }

    ret = cached_io_detach(&pthis->cio);
    ASSERT(ret >= 0);

    mtv_close_and_delete_file(pthis->index_h);

    pthis->index_h = index_h;
    pthis->head = 0;
    pthis->tail = entry_count;
    pthis->next = next;

    ret = cached_io_attach(&pthis->cio, pthis->index_h, INDEX_CACHE_BLOCK_SIZE);
    if (ret < 0)
    {
        mtv_close_and_delete_file(pthis->index_h);
        return mtv_error_from_fs(ret);
    }
    if (g_mtv_enable_async_io) {
        cached_io_set_async(&pthis->cio);
    }

	si_sanity_check(pthis);

    return MTV_S_OK;
}

static mtv_result_t si_set_maximum_size(mtv_sample_index_t* pthis, kal_int32 max_index_size)
{
	mtv_result_t ret;

    max_index_size /= sizeof(mtv_sample_index_entry_t);

    /* only allow increasing */
    if (max_index_size <= pthis->max_index_size) {
        return MTV_E_INVALID_PARAM;
    }

    if (pthis->head <= pthis->tail)
    {
        /*
         * |-------|==========================|------|################|
         * 0      head                       tail      increased part
         *  ^^^^^^^ head empty space
         */

        /*
         * simply increase the maximum size and assume the head empty space is small and
         * will not waste too much space.
         */
    }
    else
    {
        /*
         * |==============|------------|=============|################|
         * 0             tail         head         max_index_size
         */
        ret = si_compact(pthis);
        if (ret < 0) {
            return ret;
        }
    }

    pthis->max_index_size = max_index_size;

    return MTV_S_OK;
}

static mtv_result_t si_close(mtv_sample_index_t* pthis)
{
    if (pthis->index_h >= 0)
    {
        cached_io_detach(&pthis->cio);

        mtv_close_and_delete_file(pthis->index_h);
        pthis->index_h = -1;

        mtv_free_dec_config_extra(&pthis->info.dec_config);
    }

    return MTV_S_OK;
}

/* buffer engine operations */

static void mtv_be_set_read_state(mtv_buffer_engine_t* pthis, mtv_buffer_engine_read_state_t read_state)
{
    if (pthis->read_state != read_state)
    {
        mtv_buffer_engine_read_state_t old_state = pthis->read_state;

        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_STATE, read_state);
        pthis->read_state = read_state;

        if (pthis->client) {
            pthis->client->on_read_state_change(pthis->client, old_state, pthis->read_state);
        }
    }
}

static mtv_result_t mtv_be_check_min_space_requirement(kal_wchar* dir, kal_uint32 bitrate, kal_uint32 seconds)
{
    FS_DiskInfo di;
    kal_uint64 free_kb;
    kal_int32 fs_ret;

    /* get disk free space */
    fs_ret = FS_GetDiskInfo(dir, &di, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO);
    if (fs_ret < 0) {
        return mtv_error_from_fs(fs_ret);
    }

	free_kb = (kal_uint64) di.FreeClusters * di.SectorsPerCluster * di.BytesPerSector / 1024;

    /* check with estimated bitrate and required duration */
    if (free_kb < bitrate * seconds / 8) {
        return MTV_E_FAIL;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_open(mtv_buffer_engine_t* pthis, mtv_buffer_engine_client_t* client, mtv_buffer_engine_config_t* config)
{
    mtv_result_t ret;
    kal_wchar* stream_path;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_OPEN);

    /* the free disk space should at least allows 30 seconds of recording */
    if (mtv_be_check_min_space_requirement(config->storing_dir, config->estimated_bitrate, MTV_MIN_DURATION_FOR_TIMESHIFT) < 0) {
        return MTV_IO_E_DISK_FULL;
    }

    pthis->client = client;
	pthis->engine_flags = config->flags;
    pthis->estimated_bitrate = config->estimated_bitrate;

    kal_wstrcpy(pthis->storing_dir, config->storing_dir);

    /* create sample stream */
    stream_path = mtv_generate_new_filename(config->storing_dir, AV_STREAM_PREFIX, L"");
    ret = ss_open(&pthis->ss, stream_path, config->max_buffer_kb * 1024, (pthis->engine_flags & MTV_BE_BUFFER_WRAPAROUND) != 0);
    med_free_ext_mem((void**)&stream_path);
    if (ret < 0) {
        return ret;
    }

    pthis->num_packets = 0;
    pthis->timestamp_base = 0;

    pthis->packet_buffer_size = 0;
    pthis->packet_buffer = NULL;

    mtv_be_set_read_state(pthis, MTV_BE_READ_LIVE);

    return MTV_S_OK;
}

static mtv_result_t mtv_be_add_stream(mtv_buffer_engine_t* pthis, mtv_stream_info_t* stream_info)
{
    mtv_result_t ret;
    kal_wchar* index_path;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_ADD_STREAM, stream_info->type);

    if (pthis->num_streams >= ARRAY_SIZE(pthis->si))
    {
        SHOULD_NOT_HAPPEN("Too many buffered streams!");
        return  MTV_E_RESOURCE_CONFLICT;
    }

    if (stream_info->type == MTV_STREAM_AUDIO) {
        index_path = mtv_generate_new_filename(pthis->storing_dir, AUDIO_INDEX_PREFIX, L"");
    }
    else if (stream_info->type == MTV_STREAM_VIDEO) {
        index_path = mtv_generate_new_filename(pthis->storing_dir, VIDEO_INDEX_PREFIX, L"");
    }
    else
    {
        NOT_REACHED("Unhandled stream type!");
        return MTV_E_FAIL;
    }

    /* create sample index */
    ret = si_open(&pthis->si[pthis->num_streams], index_path, stream_info, ss_get_maximum_size(&pthis->ss) / STREAM_TO_SAMPLE_RATIO);
    if (ret >= 0) {
        pthis->num_streams++;
    }

    med_free_ext_mem((void**)&index_path);

    return ret;
}

static mtv_result_t mtv_discard_written_ranges(mtv_buffer_engine_t* pthis, kal_int32 num_rgn, mtv_region_t* rgn)
{
	mtv_result_t ret = MTV_S_OK;
	kal_int32 i, j;

	/* check each stream to discard overwritten samples */
    for (i = 0; i < pthis->num_streams; i++)
    {
        for (j = 0; j < num_rgn; j++)
        {
			ret = si_discard_samples(&pthis->si[i], rgn[j].head, rgn[j].tail);
            ASSERT(ret >= 0);
        }
    }

	return ret;
}

static mtv_result_t mtv_be_write_packet(mtv_buffer_engine_t* pthis, kal_uint32 stream_index, mtv_packet_t* packet)
{
    mtv_result_t ret;
    ss_sample_location_t location;
    kal_int32 num_parts = 1;
    mtv_packet_t parts[2];
    kal_uint32 nalu_size;
    mtv_sample_index_t* si = &pthis->si[stream_index];

    ASSERT(stream_index < (kal_uint32) pthis->num_streams);

    if (pthis->num_packets % 256 == 255)    /* about per 132KB */
    {
        /* abort the write if the free space is not enough to store 10 seconds */
        if (mtv_be_check_min_space_requirement(pthis->storing_dir, pthis->estimated_bitrate, MTV_MIN_DURATION_FOR_TIMESHIFT) < 0) {
            return MTV_IO_E_DISK_FULL;
        }
    }

    if (si->info.dec_config.codec == MTV_CODEC_H264)
    {
        /* append NALU length according to 14496-15 5.2.3 */

        if ((packet->flags & MTV_PACKET_FROM_CL_TDMB_DEMUX) != 0 &&
            *((kal_uint32*)packet->data) == H264_START_CODE)
        {
            ASSERT(packet->size > 4);

            /*
             * Cyberlink demux will always append H.264 start code in the packet. However,
             * the start code is not needed for time-shifting buffer and MP4 recording.
             * Therefore, skip the start code.
             */
            nalu_size = packet->size - 4;

            parts[1].data = packet->data + 4;
            parts[1].size = nalu_size;

            nalu_size = ENDIAN_FLIP(nalu_size);
            parts[0].data = (kal_uint8*) &nalu_size;
            parts[0].size = H264_NALU_LENGTH_SIZE;

            num_parts = 2;
        }
        else /* write 4-byte NALU length before the NALU */
        {
            ASSERT(packet->size > 0);

            nalu_size = ENDIAN_FLIP(packet->size);
            parts[0].data = (kal_uint8*) &nalu_size;
            parts[0].size = H264_NALU_LENGTH_SIZE;

            parts[1].data = packet->data;
            parts[1].size = packet->size;

            num_parts = 2;
        }
    }
    else if (si->info.type == MTV_STREAM_AUDIO)
    {
        ASSERT(packet->size > 0);

        parts[0].data = packet->data;
        parts[0].size = packet->size;

        num_parts = 1;
    }
    else
    {
        return MTV_E_FAIL;  /* unsupported format */
    }

	/* write sample to AV stream */
    ret = ss_write_buffer(&pthis->ss, num_parts, parts, &location);
    if (ret < 0) {
        return ret;
    }

    if (pthis->num_packets == 0)
    {
        pthis->timestamp_base = packet->timestamp;
        MTV_TRACE(TRACE_INFO, MTV_TRC_BE_TIMESTAMP_BASE, pthis->timestamp_base);
    }

	/* check each stream to discard overwritten samples */
    ASSERT(location.num_rgn > 0);
	mtv_discard_written_ranges(pthis, location.num_rgn, location.rgn);

    /* keep tracking of latest timestamp for time-shifting implementation */
    {
        kal_uint32 tail_ts;

        tail_ts = (packet->timestamp - pthis->timestamp_base) / si->info.dec_config.timestamp_resolution;
        if (tail_ts > si->tail_ts)
        {
            si->tail_ts = tail_ts;
        }
        else if (tail_ts < si->tail_ts)
        {
            /*
             * We probably have a timestamp wrap-around here (a repeated play from modulator?)
             * Adjust the timestamp_base so that the timestamp of up-coming packets can continue
             * from current tail timestamp.
             */
            pthis->timestamp_base = packet->timestamp - si->tail_ts * si->info.dec_config.timestamp_resolution;
            MTV_TRACE(TRACE_INFO, MTV_TRC_BE_TIMESTAMP_BASE, pthis->timestamp_base);
        }
    }

    switch (pthis->read_state)
    {
    case MTV_BE_READ_LIVE:
        /*
         * in LIVE state, we need to do whatever is necessary to
         * make the internal states look like the packet
         * is read as soon as it is written.
         */
        si->curr_ts = si->tail_ts;
        si_move_to_tail(si);
        break;

    case MTV_BE_READ_PAUSED:
    case MTV_BE_READ_DELAYED:
    case MTV_BE_READ_PREBUFFERING:
        ASSERT(si->tail_ts >= si->curr_ts);
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }

   	/* update sample index */
   	{
        mtv_sample_index_entry_t entry;

        entry.pos = location.pos;

        /* note that sample_size may not be equal to packet->size
           if some additional info is added such as NALU length for
           H.264 bitstream. */
        entry.size = location.size;

        entry.timestamp = packet->timestamp - pthis->timestamp_base;
        entry.flags = packet->flags;

        ret = si_add_entry(si, &entry);
   	}
    pthis->num_packets++;

    return ret;
}

static mtv_result_t mtv_be_read_next_index_entry(mtv_buffer_engine_t* pthis, kal_uint32* stream_index, mtv_sample_index_entry_t* entry)
{
    mtv_result_t ret;
    kal_int32 i;
    kal_int32 stream = -1;
    kal_int32 min_offset = 0x7fffffff;

    /* find the stream that contains this sample */
    for (i = 0; i < pthis->num_streams; i++)
    {
        mtv_sample_index_entry_t en;

        ret = si_peek_entry(&pthis->si[i], &en);
		if (ret >= 0)
		{
			kal_int32 offset = ss_calc_offset(&pthis->ss, en.pos);
			ASSERT(offset >= 0);

			if (offset <= min_offset)
			{
				min_offset = offset;
				*entry = en;
				stream = i;
			}
		}
    }

    if (stream < 0) {
        return MTV_E_FAIL;  /* no packet is available */
    }

    *stream_index = stream;
    ret = si_move_to_next_entry(&pthis->si[stream]);
    ASSERT(ret >= 0);

    return ret;
}

static void* mtv_be_get_packet_buffer(mtv_buffer_engine_t* pthis, kal_uint32 size)
{
    if (size > pthis->packet_buffer_size)
    {
        med_free_ext_mem(&pthis->packet_buffer);
        pthis->packet_buffer = med_alloc_ext_mem(size);
        ASSERT(pthis->packet_buffer != NULL);

        pthis->packet_buffer_size = size;
    }

    return pthis->packet_buffer;
}

static mtv_result_t mtv_be_read_packet(mtv_buffer_engine_t* pthis, kal_uint32* stream_index, mtv_packet_t* packet)
{
    mtv_result_t ret;
	mtv_sample_index_entry_t entry;
    kal_uint8* packet_buffer;

    if (pthis->read_state != MTV_BE_READ_DELAYED && pthis->read_state != MTV_BE_READ_PREBUFFERING)
    {
        return MTV_E_FAIL;
    }

    ret = mtv_be_read_next_index_entry(pthis, stream_index, &entry);
    if (ret < 0) {
        return ret;
    }

    /* read the sample into packet buffer */
    packet_buffer = mtv_be_get_packet_buffer(pthis, entry.size);
    ret = ss_read_sample(&pthis->ss, entry.pos, packet_buffer, entry.size);
    if (ret >= 0)
    {
        mtv_sample_index_t* si = &pthis->si[*stream_index];

        packet->data = packet_buffer;
        packet->flags = entry.flags;
        packet->size = entry.size;
        packet->timestamp = entry.timestamp + pthis->timestamp_base;

        si->curr_ts = entry.timestamp / si->info.dec_config.timestamp_resolution;
        ASSERT(si->tail_ts >= si->curr_ts);
    }

    return ret;
}

static mtv_result_t mtv_be_read_packet_from_stream(mtv_buffer_engine_t* pthis, kal_uint32 stream_index, mtv_packet_t* packet)
{
    mtv_result_t ret;
	mtv_sample_index_entry_t entry;
    mtv_sample_index_t* si = &pthis->si[stream_index];
    kal_uint8* packet_buffer;

    ASSERT(stream_index < (kal_uint32) pthis->num_streams);

    ret = si_peek_entry(si, &entry);
    if (ret >= 0)
    {
        ret = si_move_to_next_entry(si);
        ASSERT(ret >= 0);

        /* read the sample into packet buffer */
        packet_buffer = mtv_be_get_packet_buffer(pthis, entry.size);
        ret = ss_read_sample(&pthis->ss, entry.pos, packet_buffer, entry.size);
        if (ret >= 0)
        {
            packet->data = packet_buffer;
            packet->flags = entry.flags;
            packet->size = entry.size;
            packet->timestamp = entry.timestamp + pthis->timestamp_base;
        }
    }

    return ret;
}

static mtv_result_t mtv_be_save(mtv_buffer_engine_t* pthis, mtv_recording_format_t format, kal_wchar* file, volatile kal_bool* aborted)
{
    mtv_result_t ret = MTV_E_INVALID_PARAM;
    kal_wchar* output_file;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SAVING);

    output_file = mtv_generate_new_filename(pthis->storing_dir, file, mtv_get_format_extension_name(format));

    if (format == MTV_RECORDING_FORMAT_MP4)
    {
        ret = convert_to_mp4(output_file, pthis->num_streams, pthis->si, &pthis->ss, aborted);
    }
    else if (format == MTV_RECORDING_FORMAT_MP2)
    {
        ASSERT(pthis->num_streams == 1);
        ret = convert_to_mp2(output_file, &pthis->si[0], &pthis->ss, aborted);
    }
    else
    {
        NOT_REACHED("Invalid recording format is specified?!");
    }

    med_free_ext_mem((void**)&output_file);

    /* close itself because its bufffer file has gone and can't be used anymore */
    pthis->close(pthis);

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SAVED);
    return ret;
}

static mtv_result_t mtv_be_discard_all(mtv_buffer_engine_t* pthis)
{
    mtv_result_t ret;
	kal_int32 i;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_DISCARD_ALL);

    ret = ss_reset(&pthis->ss);
    ASSERT(ret >= 0);

    for (i = 0; i < pthis->num_streams; i++)
    {
        ret = si_reset(&pthis->si[i]);
        ASSERT(ret >= 0);
    }

    switch (pthis->read_state)
    {
    case MTV_BE_READ_DELAYED:
    case MTV_BE_READ_PAUSED:
    case MTV_BE_READ_PREBUFFERING:
        /* switch to live mode because there is no buffered content */
        mtv_be_set_read_state(pthis, MTV_BE_READ_LIVE);
        break;

    case MTV_BE_READ_LIVE:
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_close(mtv_buffer_engine_t* pthis)
{
	mtv_result_t ret;
	kal_int32 i;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_CLOSE);

    ret = ss_close(&pthis->ss);
    ASSERT(ret >= 0);

    for (i = 0; i < pthis->num_streams; i++)
    {
        ret = si_close(&pthis->si[i]);
        ASSERT(ret >= 0);
    }
    pthis->num_streams = 0;

    med_free_ext_mem(&pthis->packet_buffer);
    pthis->packet_buffer_size = 0;

    return MTV_S_OK;
}

static mtv_result_t mtv_be_get_control(mtv_buffer_engine_t* pthis, mtv_control_t control_id, void** control)
{
    if (control_id == MTV_CONTROL_TIMESHIFT)
    {
        *control = &pthis->timeshift_ctrl;
        return MTV_S_OK;
    }

    return MTV_E_FAIL;
}

static mtv_result_t mtv_be_seek_by_time(mtv_buffer_engine_t* pthis, kal_uint32 target_time)
{
    kal_int32 i;
    mtv_result_t ret;

    /* seek each stream to the target time */
    for (i = 0; i < pthis->num_streams; i++)
    {
        mtv_sample_index_t* si = &pthis->si[i];
        ret = si_move_to_time(si, target_time * si->info.dec_config.timestamp_resolution);
        if (ret < 0) {
            return ret;
        }

        if (i == 0) /* use only the first stream to upadte last read time */
        {
            mtv_sample_index_entry_t entry;

            ret = si_peek_entry(si, &entry);
            /*
             * Peeking will fail if the next pointer is at the end of buffer. However, the condition
             * should not happen in MTV_BE_READ_DELAYED mode.
             */
            ASSERT(ret >= 0);

            /* adjust the last read time to sync with si_move_to_time */
            si->curr_ts = entry.timestamp / si->info.dec_config.timestamp_resolution;
        }
    }

    if (pthis->client) {
        pthis->client->on_read_seek(pthis->client, target_time);
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_set_delay(mtv_control_timeshift_t* control, kal_uint32 delay)
{
    mtv_buffer_engine_t* pthis = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
    mtv_result_t ret = MTV_S_OK;

    if (pthis->num_streams < 1) {
        return MTV_E_FAIL;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SET_DELAY, delay);

    if (delay != 0) /* delayed playback */
    {
        kal_uint32 max_delay = 0;

        ret = control->get_buffer_status(control, &max_delay, NULL);
        if (ret < 0 || max_delay < BE_MIN_BUFFER_SECONDS) // less than one second
        {
            /*
             * not allow to seek if there are too few content in the buffer.
             * this checking is used to guarantee the delay time can be calculated correctly.
             */
            ret = MTV_E_FAIL;
            goto set_delay_cleanup;
        }

        /* note that we use timestamp information from stream 0 for simplicity */
        ret = mtv_be_seek_by_time(pthis, (delay > pthis->si[0].tail_ts) ? 0 : pthis->si[0].tail_ts - delay);
        if (ret < 0) {
            goto set_delay_cleanup;
        }

        switch (pthis->read_state)
        {
        case MTV_BE_READ_LIVE:
        case MTV_BE_READ_PREBUFFERING:
            mtv_be_set_read_state(pthis, MTV_BE_READ_DELAYED);
            break;

        case MTV_BE_READ_DELAYED:
        case MTV_BE_READ_PAUSED:
            /* keep in the same state */
            break;

        default:
            NOT_REACHED("Unknown read state?!");
            break;
        }
    }
    else /* live playback */
    {
        switch (pthis->read_state)
        {
        case MTV_BE_READ_LIVE:
            /* keep in the same state */
            break;

        case MTV_BE_READ_PAUSED:
        case MTV_BE_READ_DELAYED:

            /*
             * To reduce the duration of decoder stop from DELAYED to LIVE, we need to back off for
             * a little time so that decoder buffers can be filled quickly and therefore playback
             * can be started in short time.
             *
             * However, the back-off time cannot large than the capacity of decoder buffer so that
             * we can drian the stream buffer and go to real LIVE mode.
             */
            ret = mtv_be_seek_by_time(pthis, pthis->si[0].tail_ts <= BE_LIVE_BACK_OFF_SECONDS ?
                0 : pthis->si[0].tail_ts - BE_LIVE_BACK_OFF_SECONDS);
            if (ret < 0) {
                goto set_delay_cleanup;
            }

            mtv_be_set_read_state(pthis, MTV_BE_READ_PREBUFFERING);
            break;

        case MTV_BE_READ_PREBUFFERING:

            /* switch the state to LIVE immediately even when in PAUSED mode */
            mtv_be_set_read_state(pthis, MTV_BE_READ_LIVE);
            break;

        default:
            NOT_REACHED("Unknown read state?!");
            break;
        }
    }

set_delay_cleanup:

    return ret;
}

static mtv_result_t mtv_be_timeshift_get_delay(mtv_control_timeshift_t* control, kal_uint32* delay)
{
    mtv_buffer_engine_t* pthis = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);

    if (pthis->num_streams < 1) {
        return MTV_E_FAIL;
    }

    switch (pthis->read_state)
    {
    case MTV_BE_READ_LIVE:
    case MTV_BE_READ_PREBUFFERING:
        *delay = 0;
        break;

    case MTV_BE_READ_PAUSED:
    case MTV_BE_READ_DELAYED:
        /* returns the offset between recording and playback position */
        ASSERT(pthis->si[0].tail_ts >= pthis->si[0].curr_ts);
        *delay = pthis->si[0].tail_ts - pthis->si[0].curr_ts;
        break;

    default:
        NOT_REACHED("Unknown read state?!");
        break;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_get_buffer_status(mtv_control_timeshift_t* control, kal_uint32* max_delay, kal_uint32* buffer_duration)
{
    mtv_buffer_engine_t* pthis = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
	kal_uint32 max_delay_seconds = 0;
    kal_int32 i;

    /* find the max stream duration */
    for (i = 0; i < pthis->num_streams; i++)
    {
        mtv_sample_index_t* si = &pthis->si[i];
        kal_uint32 seconds;

        seconds = si_get_duration(si) / si->info.dec_config.timestamp_resolution;
        if (seconds > max_delay_seconds) {
            max_delay_seconds = seconds;
        }
    }

    *max_delay = max_delay_seconds;

    if (buffer_duration != NULL)
    {
        /* calculate the buffer duration using maximum bitrate: video = 384kb, audio = 128kb */
        kal_uint32 buffer_duration_seconds = (kal_uint32) ss_get_maximum_size(&pthis->ss) / (64 * 1024);

        /* the estimation of buffer duration may not be accurate and therefore
           ensure it won't be larger than max delay. */
        *buffer_duration = buffer_duration_seconds > max_delay_seconds ? buffer_duration_seconds : max_delay_seconds;
    }

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_set_rate(mtv_control_timeshift_t* control, kal_int32 rate)
{
    UNUSED(control);
    UNUSED(rate);

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_be_timeshift_get_rate(mtv_control_timeshift_t* control, kal_int32* rate)
{
    UNUSED(control);

    *rate = 1000; /* currently trick-mode play is not supported */

    return MTV_S_OK;
}

static mtv_result_t mtv_be_timeshift_take_snapshot(mtv_control_timeshift_t* control)
{
    UNUSED(control);

    return MTV_E_NOT_IMPLEMENTED;
}

static mtv_result_t mtv_be_timeshift_set_pause(mtv_control_timeshift_t* control, kal_bool pause)
{
    mtv_buffer_engine_t* pthis = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);
    kal_uint32 max_delay = 0;
    mtv_result_t ret;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SET_PAUSE, pause);

    ret = control->get_buffer_status(control, &max_delay, NULL);
    if (ret < 0 || max_delay < BE_MIN_BUFFER_SECONDS)
    {
        /*
         * not allow to pause if there are too few content in the buffer.
         * this checking is used to guarantee the delay time can be calculated correctly.
         */
        ret = MTV_E_FAIL;
        goto set_pause_cleanup;
    }

    if (pause)
    {
        switch (pthis->read_state)
        {
        case MTV_BE_READ_PAUSED:
            break;

        case MTV_BE_READ_LIVE:
        case MTV_BE_READ_DELAYED:
        case MTV_BE_READ_PREBUFFERING:
            mtv_be_set_read_state(pthis, MTV_BE_READ_PAUSED);
            break;

        default:
            NOT_REACHED("Unknown read state?!");
            break;
        }
    }
    else
    {
        switch (pthis->read_state)
        {
        case MTV_BE_READ_PAUSED:
            mtv_be_set_read_state(pthis, MTV_BE_READ_DELAYED);
            break;

        case MTV_BE_READ_LIVE:
        case MTV_BE_READ_DELAYED:
        case MTV_BE_READ_PREBUFFERING:
            break;

        default:
            NOT_REACHED("Unknown read state?!");
            break;
        }
    }

set_pause_cleanup:

    return ret;
}

static mtv_result_t mtv_be_timeshift_get_pause(mtv_control_timeshift_t* control, kal_bool* pause)
{
    mtv_buffer_engine_t* pthis = PTHIS(control, mtv_buffer_engine_t, timeshift_ctrl);

    *pause = (pthis->read_state == MTV_BE_READ_PAUSED);

    return MTV_S_OK;
}

static mtv_buffer_engine_read_state_t mtv_be_get_read_state(mtv_buffer_engine_t* pthis)
{
    return pthis->read_state;
}

mtv_result_t mtv_be_set_max_buffer_size(mtv_buffer_engine_t* pthis, kal_uint32 max_buffer_kb)
{
    mtv_result_t ret;
    kal_int32 max_size = max_buffer_kb * 1024;
	kal_int32 i;

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_SETTING_MAX_SIZE, max_buffer_kb);

    /*
     * try increasing the maximum size of index stream first in case that
     * there is not enough disc space.
     */
    for (i = 0; i < pthis->num_streams; i++)
    {
        ret = si_set_maximum_size(&pthis->si[i], max_size / STREAM_TO_SAMPLE_RATIO);
        if (ret < 0) {
            return ret;
        }
    }

    ret = ss_set_maximum_size(&pthis->ss, max_size);
    if (ret < 0) {
        return ret;
    }

    MTV_TRACE(TRACE_INFO, MTV_TRC_BE_MAX_SIZE_APPLIED, max_buffer_kb);
    return MTV_S_OK;
}

mtv_result_t mtv_be_save_checkpoint(mtv_buffer_engine_t* pthis, cached_io_t* cp_h)
{
    kal_int32 ret;
    kal_int32 i;

    ret = cached_io_write(cp_h, pthis->storing_dir, sizeof(pthis->storing_dir));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    ret = cached_io_write(cp_h, &pthis->num_streams, sizeof(pthis->num_streams));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    for (i = 0; i < pthis->num_streams; i++)
    {
        ret = si_save_checkpoint(&pthis->si[i], cp_h);
        if (ret < 0) {
            goto cleanup;
        }
    }

    ret = ss_save_checkpoint(&pthis->ss, cp_h);
    if (ret < 0) {
        goto cleanup;
    }

cleanup:

    return ret;
}

mtv_result_t mtv_be_recover_from_checkpoint(mtv_buffer_engine_t* pthis, cached_io_t* cp_h)
{
    kal_int32 ret;
    kal_int32 i;

    ret = cached_io_read(cp_h, pthis->storing_dir, sizeof(pthis->storing_dir));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    ASSERT(pthis->num_streams == 0);
    ret = cached_io_read(cp_h, &pthis->num_streams, sizeof(pthis->num_streams));
    if (ret < 0)
    {
        ret = mtv_error_from_fs(ret);
        goto cleanup;
    }

    for (i = 0; i < pthis->num_streams; i++)
    {
        ret = si_open_from_checkpoint(&pthis->si[i], cp_h);
        if (ret < 0) {
            goto cleanup;
        }
    }

    ret = ss_open_from_checkpoint(&pthis->ss, cp_h);
    if (ret < 0) {
        goto cleanup;
    }

cleanup:

    return ret;
}

void mtv_be_destroy(mtv_buffer_engine_t* pthis)
{
    med_free_ext_mem((void**) &pthis);
}

mtv_buffer_engine_t* construct_mtv_buffer_engine()
{
    mtv_buffer_engine_t* pthis = (mtv_buffer_engine_t*) med_alloc_ext_mem(sizeof(mtv_buffer_engine_t));
    ASSERT(pthis);

    kal_mem_set(pthis, 0, sizeof(*pthis));

    pthis->open = mtv_be_open;
    pthis->get_control = mtv_be_get_control;
    pthis->add_stream = mtv_be_add_stream;
    pthis->write_packet = mtv_be_write_packet;
    pthis->read_packet = mtv_be_read_packet;
	pthis->read_packet_from_stream = mtv_be_read_packet_from_stream;
    pthis->save = mtv_be_save;
    pthis->discard_all = mtv_be_discard_all;
    pthis->get_read_state = mtv_be_get_read_state;
    pthis->set_max_buffer_size = mtv_be_set_max_buffer_size;
    pthis->save_checkpoint = mtv_be_save_checkpoint;
    pthis->recover_from_checkpoint = mtv_be_recover_from_checkpoint;
    pthis->close = mtv_be_close;
    pthis->destroy = mtv_be_destroy;

    pthis->timeshift_ctrl.set_pause = mtv_be_timeshift_set_pause;
    pthis->timeshift_ctrl.get_pause = mtv_be_timeshift_get_pause;
    pthis->timeshift_ctrl.set_delay = mtv_be_timeshift_set_delay;
    pthis->timeshift_ctrl.get_delay = mtv_be_timeshift_get_delay;
    pthis->timeshift_ctrl.get_buffer_status = mtv_be_timeshift_get_buffer_status;
    pthis->timeshift_ctrl.set_rate = mtv_be_timeshift_set_rate;
    pthis->timeshift_ctrl.get_rate = mtv_be_timeshift_get_rate;
    pthis->timeshift_ctrl.take_snapshot = mtv_be_timeshift_take_snapshot;

    return pthis;
}

static kal_bool delete_found_file(void* param, kal_wchar* filename)
{
    UNUSED(param);

    FS_Delete(filename);
    return KAL_TRUE;    /* continue the searching */
}

void mtv_be_discard_unsaved_buffers(const kal_wchar* dir)
{
    kal_wchar* pattern;

    pattern = (kal_wchar*) med_alloc_ext_mem(MAX_FILE_NAME_LEN * sizeof(kal_wchar));
    ASSERT(pattern);

    kal_wstrcpy(pattern, AV_STREAM_PREFIX);
    kal_wstrcat(pattern, L"*");
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    kal_wstrcpy(pattern, AUDIO_INDEX_PREFIX);
    kal_wstrcat(pattern, L"*");
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    kal_wstrcpy(pattern, VIDEO_INDEX_PREFIX);
    kal_wstrcat(pattern, L"*");
    mtv_process_files(dir, pattern, delete_found_file, NULL);

    med_free_ext_mem((void**) &pattern);
}

#endif /* defined(__MED_MTV_MOD__) */
