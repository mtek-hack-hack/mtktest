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
*  audio_input_stream.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   audio input stream functions.
*   there is a key object, audio_input_stream, which is to provide a single interface for both file & byte input stream operation.
*   when we want to share one input stream object among several tasks, it's necessary to call 
*   audio_xxxx_input_stream_alloc() & audio_input_stream_free() before & after the object life cycle such that
*   there will be only one task access it at the same time.
*   if you want to use one input stream object for one task, you can call audio_input_stream_init() directly and
*   no more audio_input_stream_free() after all.
*
* Author:
* -------
*  Tim Chen
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef MED_NOT_PRESENT

#include "med_global.h"

#ifdef __RICH_AUDIO_PROFILE__

#include "aud_input_stream.h"
#include "drm_gprot.h"

/* the mutex is for many tasks to share the same audio_input_stream object without data racing */
volatile kal_mutexid audio_input_stream_mutex;
static audio_input_stream_struct audio_input_stream;


/*****************************************************************************
 * FUNCTION
 *  aud_get_bits
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buff            [?]         
 *  pbitcount       [?]         
 *  bitlen          [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 aud_get_bits(kal_uint8 *buff, kal_uint32 *pbitcount, kal_uint32 bitlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static kal_uint8 curbyte;
    kal_uint8 mask;
    kal_uint32 bitpos;
    kal_uint8 val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bitpos = *pbitcount & 0x07; /* *pbitcount % 8 */

    if (bitpos == 0)
    {
        curbyte = buff[*pbitcount >> 3];    /* *pbitcount / 8 */
    }

    *pbitcount += bitlen;
    mask = (kal_uint8) ((1 << (8 - bitpos)) - 1);

    if (bitpos + bitlen <= 8)
    {
        val = (kal_uint8) ((curbyte & mask) >> (8 - (bitpos + bitlen)));
    }
    else
    {
        val = (kal_uint8) ((curbyte & mask) << (bitlen - (8 - bitpos)));
        curbyte = buff[*pbitcount >> 3];    /* *pbitcount / 8 */
        val |= curbyte >> (16 - bitlen - bitpos);
    }

    return val;
}


/*****************************************************************************
 * FUNCTION
 *  audio_file_input_stream_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]        
 * RETURNS
 *  audio_input_stream_struct*
 *****************************************************************************/
audio_input_stream_struct *audio_file_input_stream_alloc(FS_HANDLE file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(audio_input_stream_mutex);
    audio_input_stream_init(&audio_input_stream, file, 0, 0);
    return &audio_input_stream;
}


/*****************************************************************************
 * FUNCTION
 *  audio_byte_input_stream_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_src             [?]         
 *  mem_src_size        [IN]        
 * RETURNS
 *  audio_input_stream_struct*
 *****************************************************************************/
audio_input_stream_struct *audio_byte_input_stream_alloc(kal_uint8 *mem_src, kal_uint32 mem_src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(audio_input_stream_mutex);
    audio_input_stream_init(&audio_input_stream, NULL, mem_src, mem_src_size);
    return &audio_input_stream;
}


/*****************************************************************************
 * FUNCTION
 *  audio_input_stream_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void audio_input_stream_free(audio_input_stream_struct *input_stream)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_give_mutex(audio_input_stream_mutex);
}


/*****************************************************************************
 * FUNCTION
 *  audio_input_stream_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]         
 *  file                [IN]        when file is null, the source is from memory so mem_src must be set
 *  mem_src             [?]         
 *  mem_src_size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void audio_input_stream_init(
        audio_input_stream_struct *input_stream,
        FS_HANDLE file,
        kal_uint8 *mem_src,
        kal_uint32 mem_src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_stream->ptr = input_stream->tail = input_stream->buf;
    input_stream->buf_size = AUDIO_INPUT_STREAM_BUFFER_SIZE;
    input_stream->skip = 0;
    input_stream->total_load = 0;
    input_stream->free_bitrate = 0;
    input_stream->file = file;
    input_stream->mem_src = mem_src;
    input_stream->mem_src_size = mem_src_size;
}


/*****************************************************************************
 * FUNCTION
 *  audio_input_stream_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]         
 *  offset              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void audio_input_stream_seek(audio_input_stream_struct *input_stream, kal_int32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_stream->ptr = input_stream->tail = input_stream->buf;
    if (input_stream->file != NULL)
    {
        DRM_seek_file(input_stream->file, offset, FS_FILE_BEGIN);
    }
    input_stream->total_load = offset;
}


/*****************************************************************************
 * FUNCTION
 *  audio_input_stream_get_data_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]     
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 audio_input_stream_get_data_size(audio_input_stream_struct *input_stream)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input_stream->file == NULL)
    {
        file_size = input_stream->mem_src_size;
    }
    else
    {
        DRM_file_size(input_stream->file, &file_size);
    }

    return (kal_int32) file_size;
}


/*****************************************************************************
 * FUNCTION
 *  audio_input_stream_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_stream        [?]         
 *  size                [IN]        0 means read as many as possible
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 audio_input_stream_read(audio_input_stream_struct *input_stream, kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 prev_data_size, free_size, read_data_size, i;
    kal_uint8 *ptr, *src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = input_stream->buf;
    /* init free data size */
    free_size = (kal_int32) input_stream->buf_size;

    if (size > 0)
    {
        ASSERT(size <= free_size);
        free_size = size;
    }
    else
    {
        /* check if it's full, we must move ptr forward to free space before call stream load */
        if ((prev_data_size = input_stream->tail - input_stream->ptr) == free_size)
        {
            return 0;
        }

        if (prev_data_size > 0)
        {
            // we move data by ourself instead using memcpy because src block maybe overlap with dst block
            // and we don't know how memcpy actually copy data
            // if we always start copying data from src front side, it should be ok
            src = input_stream->ptr;
            for (i = 0; i < prev_data_size; i++)
            {
                *ptr++ = src[i];
            }
            free_size -= prev_data_size;
        }
    }

    if (input_stream->file == NULL)
    {   /* read data from memory */
        read_data_size = (kal_int32) (input_stream->mem_src_size - input_stream->total_load);
        if (read_data_size > 0)
        {
            if (read_data_size > free_size)
            {
                read_data_size = free_size;
            }
            src = input_stream->mem_src + input_stream->total_load;
            memcpy(ptr, src, read_data_size);   /* src block won't never be overlap with dst block */
        }
    }
    else    /* read data from file */
    {
        DRM_read_file(input_stream->file, ptr, free_size, (kal_uint32*) & read_data_size);
    }

    /* update ptr, tail, and total_load */
    input_stream->ptr = input_stream->buf;
    input_stream->tail = ptr + read_data_size;
    input_stream->total_load += read_data_size;

    return read_data_size;
}

#endif /* __RICH_AUDIO_PROFILE__ */ 

#endif /* MED_NOT_PRESENT */ 

