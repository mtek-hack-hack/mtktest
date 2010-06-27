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
 *   mtv_output_mp2.c
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
#include "mtv_output_mp2.h"
#include "mtv_buffer_engine.h"

#include "fat_fs.h"

mtv_result_t convert_to_mp2(kal_wchar* mp2_file, mtv_sample_index_t* si, mtv_sample_stream_t* ss, volatile kal_bool* aborted)
{
    cached_io_t cio;
	mtv_sample_index_entry_t entry;
	kal_uint32 entry_count;
    kal_uint8* buf = NULL;
    kal_uint32 buf_size = 0;
	kal_uint32 i;
    mtv_result_t ret;

    ret = cached_io_open(&cio, mp2_file, FS_READ_WRITE | FS_CREATE_ALWAYS, MP2_CACHE_BLOCK_SIZE);
    if (ret < 0) {
        return mtv_error_from_fs(ret);
    }

    entry_count = si->get_entry_count(si);

    ret = si->move_to_head(si);
    ASSERT(ret >= 0);

    for (i = 0; i < entry_count; i++)
    {
        if (*aborted)
        {
            ret = MTV_E_ABORTED;
            break;
        }

        ret = si->peek_entry(si, &entry);
        if (ret < 0) {
            break;
        }

        ret = si->move_to_next_entry(si);
        if (ret < 0) {
            break;
        }

        /* alloc buffer if necessary */
        if (entry.size > buf_size)
        {
            med_free_ext_mem((void**) &buf);

            buf_size = entry.size;
            buf = med_alloc_ext_mem(buf_size);
            if (!buf)
            {
                ret = MTV_E_OUT_OF_MEMORY;
                break;
            }
        }

        /* read the sample */
        ret = ss->read_sample(ss, entry.pos, buf, entry.size);
        if (ret < 0) {
            break;
        }

        /* write to output file */
        ret = cached_io_write(&cio, buf, entry.size);
        if (ret < 0)
        {
            ret = mtv_error_from_fs(ret);
            break;
        }
    }

	med_free_ext_mem((void**) &buf);

    if (ret < 0)
    {
        FS_Delete(mp2_file);
        return ret;
    }

    ret = cached_io_close(&cio);
    if (ret < 0)
    {
        FS_Delete(mp2_file);
        return mtv_error_from_fs(ret);
    }

    return MTV_S_OK;
}

#endif /* defined(__MED_MTV_MOD__) */

