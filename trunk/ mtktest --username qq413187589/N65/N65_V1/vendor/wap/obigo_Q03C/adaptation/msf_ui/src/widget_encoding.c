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
 * widget_encoding.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  1. UTF8/UCS2 encoding conversion
 * 2. basic string processing routines
 * 3. Extra charset: e..g Big5 & GB2312 
 *
 * Author:
 * -------
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "app_str.h"
#include "conversions.h"        /* Native encoding */


extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern int mmi_charset_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw);
#ifdef __MMI_CHSET_GB18030__
extern kal_uint16 mmi_chset_gb18030_to_ucs2(unsigned char *pOutBuffer, unsigned char *pInBuffer, kal_int32 inLen);
extern kal_uint16 mmi_chset_ucs2_to_gb18030(unsigned char *pOutBuffer, unsigned char *pInBuffer);
#endif /* #ifdef __MMI_CHSET_GB18030__ */

/*
 * Note 1: UTF8 has the following characteristics:
 * * 1. byte are not zero
 * * 2. first byte must not be 0x80 to 0xBF
 * * 3. UTF8 converted from UCS4 will start by 0xFx
 * *
 * * Some UTF-8 string starts with BOM (0xEF 0xBB 0xBF)
 * *
 * * Note 2: We do not require input UCS2 string be aligned to 2 byte since
 * * 1. MMI use U8 to store UCS2 string. It might be odd-aligned if it is a data member in a struct.
 * * 2. kal_dchar_xxx() and UCS2XXX() can handle it.
 * *
 */


static const unsigned char widget_utf8_bytes_per_character[16] = 
{
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 2, 2, 3, 4  /* we don't support UCS4 */
};

/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_length
 * DESCRIPTION
 *  Compute the "character count" of an UCS2 string
 * PARAMETERS
 *  s       [IN]        UCS2 string
 * RETURNS
 *  The length in "characters", not in bytes
 *  The tailing character ('\0\0') is not counted in the length.
 *****************************************************************************/
int widget_ucs2_length(const kal_uint8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(s);

    return app_ucs2_strlen((const kal_int8*)s);
}


/* Not including zero character '\0' */

/*****************************************************************************
 * FUNCTION
 *  widget_utf8_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_utf8_length(const kal_uint8 *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(s);

    return mmi_chset_utf8_strlen(s);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_to_utf8_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static __inline int widget_ucs2_to_utf8_len(kal_uint16 ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2 < (kal_uint16) 0x80)
    {
        return 1;
    }
    else if (ucs2 < (kal_uint16) 0x800)
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

/* The parameter 'dest_size' should be retrieved by widget_utf8_length, it includes the space for zero character ('\0\0') */


/*****************************************************************************
 * FUNCTION
 *  widget_utf8_to_ucs2_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]         
 *  dest_size       [IN]        
 *  src             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_utf8_to_ucs2_string(kal_uint8 *dest, int dest_size, const kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_utf8_to_ucs2_string(dest, dest_size, (kal_uint8 *)src);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_to_utf8_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest            [OUT]         
 *  dest_size       [IN]        
 *  src             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_ucs2_to_utf8_string(kal_uint8 *dest, int dest_size, const kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_chset_ucs2_to_utf8_string(dest, dest_size, (kal_uint8 *)src);
}


/* Not including zero character '\0' */
/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_to_utf8_length_in_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  raw     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_charset_ucs2_to_utf8_length_in_bytes(raw);
}

/* Not including zero character "\0\0" */


/*****************************************************************************
 * FUNCTION
 *  widget_utf8_to_ucs2_length_in_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  raw     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_utf8_to_ucs2_length_in_bytes(const kal_uint8 *raw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_charset_utf8_to_ucs2_length_in_bytes(raw);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_strcpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [OUT]         
 *  src     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *widget_ucs2_strcpy(kal_uint8 *dst, const kal_uint8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_dchar_strcpy((char*)dst, (const char*)src);
    return dst;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_strncpy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst         [OUT]         
 *  src         [IN]        
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *widget_ucs2_strncpy(kal_uint8 *dst, const kal_uint8 *src, int size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT((size % 2) == 0);    /* Otherwise, API user might do something wrong */
    size -= (size % 2);
    /* kal_dchar_strncpy is different from strncpy() in string termination handling */
    kal_dchar_strncpy((char*)dst, (const char*)src, size - 2);
    return dst;
}


/*****************************************************************************
 * FUNCTION
 *  widget_string_length_in_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int widget_string_length_in_bytes(MsfStringHandle str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *raw = widget_string_content(str);
    int len = STR_LEN(raw);
    int utf8_len = 0;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!raw)
    {
        WAP_DBG_ASSERT(0);
        return 0;
    }

    for (i = 0; i < len; i++)
    {
        utf8_len += widget_ucs2_to_utf8_len(CHR_AT(raw, i));
    }

    return utf8_len;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_strdup
 * DESCRIPTION
 *  Duplicate an UCS2 string
 * PARAMETERS
 *  modId       [IN]        
 *  str         [IN]        
 * RETURNS
 *  duplicated string
 *****************************************************************************/
kal_uint8 *widget_ucs2_strdup(MSF_UINT8 modId, const kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *dst;
    int size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = STR_SIZE(widget_ucs2_length(str) + 1);
    dst = MSF_MEM_ALLOC(modId, size);
    memcpy(dst, str, size);

    return dst;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2_strdup_from_utf8
 * DESCRIPTION
 *  Create a new UCS2 string from a UTF-8 string
 * PARAMETERS
 *  modId       [IN]        
 *  str         [IN]        
 * RETURNS
 *  duplicated string
 *****************************************************************************/
kal_uint8 *widget_ucs2_strdup_from_utf8(MSF_UINT8 modId, const kal_uint8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return widget_ucs2str_append_utf8(modId, NULL, NULL, str);
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2str_append_utf8
 * DESCRIPTION
 *  Append an UCS2 string with an UTF-8 string.
 *  Note: 'src' MIGHT BE DEALLOCATED depending on the original allocated size.
 * PARAMETERS
 *  modId               [IN]            
 *  src                 [IN/OUT]        The source string. We might deallocate it or append its content.
 *  allocated_size      [IN/OUT]        Input original allocated size, and output the new allocated size. (in bytes) Otherwise, use NULL to ignore it.
 *  add_utf8_str        [IN]            The UTF-8 string to be appended after 'src'
 * RETURNS
 *  The appended string
 *****************************************************************************/
kal_uint8 *widget_ucs2str_append_utf8(
            MSF_UINT8 modId,
            kal_uint8 *src,
            int *allocated_size,
            const kal_uint8 *add_utf8_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int size = 0;
    kal_uint8 *dst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(add_utf8_str);

    if (src == NULL)
    {
        /* Duplicated add_utf8_str */
        size = widget_utf8_to_ucs2_length_in_bytes(add_utf8_str) + ENCODING_LENGTH;
        dst = MSF_MEM_ALLOC(modId, size);
        widget_utf8_to_ucs2_string(dst, size, add_utf8_str);
    }
    else if (allocated_size == NULL)
    {
        /* Always allocate a new string */
        int src_len = widget_ucs2_length(src) * ENCODING_LENGTH;

        size = src_len;
        size += widget_utf8_to_ucs2_length_in_bytes(add_utf8_str) + ENCODING_LENGTH;
        dst = MSF_MEM_ALLOC(modId, size);

        memcpy(dst, src, src_len);
        widget_utf8_to_ucs2_string(dst + src_len, size - src_len, add_utf8_str);
        MSF_MEM_FREE(modId, src);
    }
    else
    {
        /* Check allocated_size to find out whether to allocate a new string */
        int src_len = widget_ucs2_length(src) * ENCODING_LENGTH;

        size = src_len;
        size += widget_utf8_to_ucs2_length_in_bytes(add_utf8_str) + ENCODING_LENGTH;
        if (*allocated_size >= size)
        {
            dst = src;
        }
        else
        {
            dst = MSF_MEM_ALLOC(modId, size);
            *allocated_size = size;
        }

        memcpy(dst, src, src_len);
        widget_utf8_to_ucs2_string(dst + src_len, size - src_len, add_utf8_str);
        if (dst != src)
        {
            MSF_MEM_FREE(modId, src);
        }
    }
    return dst;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2str_append_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  src                 [IN]         
 *  allocated_size      [OUT]         
 *  add_ucs2_str        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *widget_ucs2str_append_ucs2(
            MSF_UINT8 modId,
            kal_uint8 *src,
            int *allocated_size,
            const kal_uint8 *add_ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int size = 0;
    kal_uint8 *dst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WAP_DBG_ASSERT(add_ucs2_str);

    if (src == NULL)
    {
        /* Duplicated add_ucs2_str */
        return widget_ucs2_strdup(modId, add_ucs2_str);
    }
    else if (allocated_size == NULL)
    {
        /* Always allocate a new string */
        int src_len = widget_ucs2_length(src) * ENCODING_LENGTH;
        int add_len = widget_ucs2_length(add_ucs2_str) * ENCODING_LENGTH;

        size = src_len + add_len + ENCODING_LENGTH;
        dst = MSF_MEM_ALLOC(modId, size);

        memcpy(dst, src, src_len);
        memcpy(dst + src_len, add_ucs2_str, add_len + ENCODING_LENGTH);
        MSF_MEM_FREE(modId, src);
    }
    else
    {
        /* Check allocated_size to find out whether to allocate a new string */
        int src_len = widget_ucs2_length(src) * ENCODING_LENGTH;
        int add_len = widget_ucs2_length(add_ucs2_str) * ENCODING_LENGTH;

        size = src_len + add_len + ENCODING_LENGTH;

        if (*allocated_size >= size)
        {
            dst = src;
        }
        else
        {
            dst = MSF_MEM_ALLOC(modId, size);
            *allocated_size = size;
        }

        memcpy(dst, src, src_len);
        memcpy(dst + src_len, add_ucs2_str, add_len + ENCODING_LENGTH);
        if (dst != src)
        {
            MSF_MEM_FREE(modId, src);
        }
    }
    return dst;
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2str_append_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  src                 [IN]         
 *  allocated_size      [OUT]         
 *  stringHandle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *widget_ucs2str_append_handle(
            MSF_UINT8 modId,
            kal_uint8 *src,
            int *allocated_size,
            MsfStringHandle stringHandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return widget_ucs2str_append_ucs2(modId, src, allocated_size, (kal_uint8*) widget_string_content(stringHandle));
}


/*****************************************************************************
 * FUNCTION
 *  widget_ucs2str_append_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  src                 [IN]         
 *  allocated_size      [OUT]         
 *  strid               [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 *widget_ucs2str_append_id(MSF_UINT8 modId, kal_uint8 *src, int *allocated_size, int strid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return widget_ucs2str_append_ucs2(modId, src, allocated_size, HDIa_widgetExtStringGetPredefinedUCS2buffer(strid));
}

/****************************************************************
 *
 *  Extended Charset Encoding 
 * 
 * Reference: msf_chrs.c 
 *
 * 1. It does not add null-termination characters nor check null-termination.
 * 2. (Optional) We may use '?' char to replace invalid characters instead of returning failure.
 *   However, it is not always appropriate to fix an invalid multi-byte (Big5, GB, ..) string with invalid bytes.
 * 3. Since not all application code check return value from msf_charset_convert_t ,
 *   we should always put correct value in srcLen and dstLen even if the conversion fails.
 *
 ***************************************************************/

/* Convert native encoding to UTF-8 string */


/*****************************************************************************
 * FUNCTION
 *  widget_encoding_convert_charset_to_utf8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  dst         [OUT]         
 *  srcLen      [IN]        
 *  dstLen      [IN]        
 *  srcUsed     [OUT]         
 *  dstUsed     [OUT]         
 *  charset     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_encoding_convert_charset_to_utf8(
                    const kal_uint8 *src,
                    kal_uint8 *dst,
                    kal_int32 srcLen,
                    kal_int32 dstLen,
                    kal_int32 *srcUsed,
                    kal_int32 *dstUsed,
                    chset_enum charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *src_begin, *dst_begin;
    const kal_uint8 *src_end, *dst_end;
    kal_uint16 dst_char;
    int dst_char_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note that 'dst' might be NULL */
    src_begin = src;
    src_end = src + srcLen;
    dst_begin = dst;
    dst_end = dst + dstLen;

    while (src < src_end && dst < dst_end)
    {
        if (*src < 0x80)
        {
            if (dst_begin)
            {
                *dst++ = *src++;
            }
            else
            {
                src++;
                dst++;
            }
        }
        else if (src + 2 <= src_end)
        {
        #ifdef __MMI_CHSET_BIG5__
            if (charset == CHSET_BIG5)
            {
                /* mmi_chset_wchar_to_ucs2() only supports BIG5 and GB2312 */
                dst_char = mmi_chset_wchar_to_ucs2((kal_uint16) (src[1] << 8 | src[0]), BIG_5_ENCODING_TYPE);
                src += 2;
            }
            else
        #endif /* #ifdef __MMI_CHSET_BIG5__ */
        #ifdef __MMI_CHSET_GB2312__
                 if (charset == CHSET_GB2312)
            {
                /* mmi_chset_wchar_to_ucs2() only supports BIG5 and GB2312 */
                dst_char = mmi_chset_wchar_to_ucs2((kal_uint16) (src[1] << 8 | src[0]), GB2312_ENCODING_TYPE);
                src += 2;
            }
            else
        #endif /* #ifdef __MMI_CHSET_GB2312__ */
        #ifdef __MMI_CHSET_GB18030__            
                 if (charset == CHSET_GB18030)
            {
                src += mmi_chset_gb18030_to_ucs2((unsigned char *)&dst_char, (unsigned char *)src, (kal_int32)(src_end-src));
            }
            else
        #endif /*#ifdef __MMI_CHSET_GB18030__ */
            {
                kal_uint32 src_end_pos = (kal_uint32) src;
                char tmp[4];

                mmi_chset_convert_ex(charset, MMI_CHSET_UCS2, (char*)src, (char*)tmp, 4, &src_end_pos);
                src += src_end_pos - (kal_uint32)src;
                memcpy(&dst_char, tmp, sizeof(kal_uint16));
            }
            dst_char_len = widget_ucs2_to_utf8_len(dst_char);
            if (dst + dst_char_len <= dst_end)
            {
                if (dst_begin)
                {
                    mmi_chset_ucs2_to_utf8(dst, dst_char);
                }
                dst += dst_char_len;
            }
            else
            {
                /* dest buffer is full */
                break;
            }
        }
        else
        {
            /* source data is empty */
            break;
        }
    }
    *srcUsed = src - src_begin;
    *dstUsed = dst - dst_begin;

    /* We may instead use UNKOWN_UCS2_CHAR to check validity of source string */
    return KAL_TRUE;
}

/* Convert UTF-8 string to native encoding */


/*****************************************************************************
 * FUNCTION
 *  widget_encoding_convert_utf8_to_charset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  dst         [OUT]         
 *  srcLen      [IN]        
 *  dstLen      [IN]        
 *  srcUsed     [OUT]         
 *  dstUsed     [OUT]         
 *  charset     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool widget_encoding_convert_utf8_to_charset(
                    const kal_uint8 *src,
                    kal_uint8 *dst,
                    kal_int32 srcLen,
                    kal_int32 dstLen,
                    kal_int32 *srcUsed,
                    kal_int32 *dstUsed,
                    chset_enum charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 *src_begin, *dst_begin;
    const kal_uint8 *src_end, *dst_end;
    kal_uint16 src_char, dst_char;
    int src_char_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Note that 'dst' might be NULL */
    src_begin = src;
    src_end = src + srcLen;
    dst_begin = dst;
    dst_end = dst + dstLen;

    while (src < src_end && dst < dst_end)
    {
        src_char_len = widget_utf8_bytes_per_character[*src >> 4];

        if (src_char_len == 0 /* invalid UTF-8 string */  ||
            src + src_char_len > src_end /* incomplete source string */ )
        {
            break;
        }

        if (*src < 0x80)
        {
            WAP_DBG_ASSERT(src_char_len == 1);
            if (dst_begin)
            {
                *dst++ = *src++;
            }
            else
            {
                src++;
                dst++;
            }
        }
        else if (dst + 2 <= dst_end)
        {
            mmi_chset_utf8_to_ucs2((kal_uint8*)&src_char, (kal_uint8*)src);

        #ifdef __MMI_CHSET_BIG5__
            if (charset == CHSET_BIG5)
            {
                if (dst_begin)
                {
                    /* mmi_chset_wchar_to_ucs2() only supports BIG5 and GB2312 */
                    dst_char = mmi_chset_ucs2_to_wchar(src_char, BIG_5_ENCODING_TYPE);
                    *dst = (dst_char >> 8) & 0xFF;
                    *(dst + 1) = dst_char & 0xFF;
                }
                dst += 2;
            }
            else 
        #endif /* #ifdef __MMI_CHSET_BIG5__ */
        #ifdef __MMI_CHSET_GB2312__
                 if (charset == CHSET_GB2312)
            {
                if (dst_begin)
                {
                    /* mmi_chset_wchar_to_ucs2() only supports BIG5 and GB2312 */
                    dst_char = mmi_chset_ucs2_to_wchar(src_char, GB2312_ENCODING_TYPE);
                    *dst = (dst_char >> 8) & 0xFF;
                    *(dst + 1) = dst_char & 0xFF;
                }
                dst += 2;
            }
            else
        #endif /* #ifdef __MMI_CHSET_GB2312__ */
        #ifdef __MMI_CHSET_GB18030__
                 if (charset == CHSET_GB18030)
            {
                char tmp_result[4];
                int  i;
                int  result_len;

                result_len = (int)mmi_chset_ucs2_to_gb18030((unsigned char*)&tmp_result, (unsigned char*)&src_char);
                if (dst + result_len <= dst_end)
                {
                    if (dst_begin)
                    {
                        for (i = (result_len - 1); i >= 0; i--)
                        {
                            dst[i] = tmp_result[i];
                        }
                    }
                    dst += result_len;
                }
                else
                {
                    /* dest buffer is not enough */
                    break;
                }
            }
            else
        #endif /* #ifdef __MMI_CHSET_GB18030__ */
            {
                char tmp[4];
                char dst_tmp[4];
                kal_uint32 dst_end_pos = (kal_uint32) dst_tmp;

                memset(tmp, 0, 4);
                memset(dst_tmp, 0, 6);
                memcpy(tmp, &src_char, sizeof(kal_uint16));
                mmi_chset_convert_ex(MMI_CHSET_UCS2, charset, (char*)tmp, (char*)dst_tmp, 4, &dst_end_pos);
                if (dst + (dst_end_pos - (kal_uint32)dst_tmp) <= dst_end)
                {
                    if (dst_begin)
                    {
                        memcpy(dst, dst_tmp, dst_end_pos - (kal_uint32)dst_tmp);
                    }
                    dst += dst_end_pos - (kal_uint32)dst_tmp;
                }
                else
                {
                    /* dest buffer may be corrupted */
                    WAP_DBG_ASSERT(0);
                    break;
                }
            }

            src += src_char_len;
        }
        else
        {
            /* dest buffer is not enough */
            break;
        }
    }
    *srcUsed = src - src_begin;
    *dstUsed = dst - dst_begin;

    /* We may instead use UNKOWN_UCS2_CHAR to check validity of source string */
    return KAL_TRUE;
}

/****************************************************************
 *
 *  Big5
 *
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtBig5ToUTF8
 * DESCRIPTION
 *  1. convert Big5 string to UTF8 string. (if 'dst' paremeter != NULL)
 *  2. determine the required size of destination buffer (if 'dst' paremeter == NULL)
 *  (derived from msf_charset_convert_t)
 * PARAMETERS
 *  src         [IN]            The source buffer
 *  srcLen      [IN/OUT]        On input, number of bytes available in the source buffer On output, the number of bytes consumed.
 *  dst         [OUT]           Is NULL, it will still update *srcLen and *dstLen.
 *  dstLen      [IN/OUT]        On input, free space of destination buffer in bytes On output, the number of bytes placed (not null-terminated).
 * RETURNS
 *  Success or failure (invalid data detected)
 *****************************************************************************/
#ifdef __MMI_CHSET_BIG5__

kal_bool HDIa_widgetExtBig5ToUTF8(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src || !srcLen || !dstLen || *srcLen < 0 || *dstLen < 0)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    if ((dst && !*dstLen) || !*srcLen)
    {
        WAP_DBG_ASSERT(0);
        *srcLen = *dstLen = 0;
        return KAL_TRUE;
    }

    return widget_encoding_convert_charset_to_utf8(src, dst, *srcLen, *dstLen, srcLen, dstLen, CHSET_BIG5);
}

#else /* __MMI_CHSET_BIG5__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtBig5ToUTF8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  srcLen      [IN/OUT]         
 *  dst         [OUT]         
 *  dstLen      [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtBig5ToUTF8(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsupported */
    WAP_DBG_ASSERT(0);
    if (dstLen)
    {
        *dstLen = 0;
    }
    return KAL_FALSE;
}

#endif /* __MMI_CHSET_BIG5__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUTF8ToBig5
 * DESCRIPTION
 *  1. convert UTF8 string to Big5 string. (if 'dst' paremeter != NULL)
 *  2. determine the required size of destination buffer (if 'dst' paremeter == NULL)
 *  (derived from msf_charset_convert_t)
 * PARAMETERS
 *  src         [IN]            The source buffer
 *  srcLen      [IN/OUT]        On input, number of bytes available in the source buffer On output, the number of bytes consumed.
 *  dst         [OUT]           Is NULL, it will still update *srcLen and *dstLen.
 *  dstLen      [IN/OUT]        On input, free space of destination buffer in bytes On output, the number of bytes placed (not null-terminated).
 * RETURNS
 *  Success or failure (invalid data detected)
 *****************************************************************************/
#ifdef __MMI_CHSET_BIG5__

kal_bool HDIa_widgetExtUTF8ToBig5(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src || !srcLen || !dstLen || *srcLen < 0 || *dstLen < 0)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    if ((dst && !*dstLen) || !*srcLen)
    {
        WAP_DBG_ASSERT(0);
        *srcLen = *dstLen = 0;
        return KAL_TRUE;
    }

    return widget_encoding_convert_utf8_to_charset(src, dst, *srcLen, *dstLen, srcLen, dstLen, CHSET_BIG5);
}

#else /* __MMI_CHSET_BIG5__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUTF8ToBig5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  srcLen      [IN/OUT]         
 *  dst         [OUT]         
 *  dstLen      [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtUTF8ToBig5(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsupported */
    WAP_DBG_ASSERT(0);
    if (dstLen)
    {
        *dstLen = 0;
    }
    /* keep srcLen unchanged */
    return KAL_FALSE;
}

#endif /* __MMI_CHSET_BIG5__ */ 

/****************************************************************
 *
 *  GB2312
 *
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGB2312ToUTF8
 * DESCRIPTION
 *  1. convert GB2312 string to UTF8 string. (if 'dst' paremeter != NULL)
 *  2. determine the required size of destination buffer (if 'dst' paremeter == NULL)
 *  (derived from msf_charset_convert_t)
 * PARAMETERS
 *  src         [IN]            The source buffer
 *  srcLen      [IN/OUT]        On input, number of bytes available in the source buffer On output, the number of bytes consumed.
 *  dst         [OUT]           Is NULL, it will still update *srcLen and *dstLen.
 *  dstLen      [IN/OUT]        On input, free space of destination buffer in bytes On output, the number of bytes placed (not null-terminated).
 * RETURNS
 *  Success or failure (invalid data detected)
 *****************************************************************************/
#ifdef __MMI_CHSET_GB2312__

kal_bool HDIa_widgetExtGB2312ToUTF8(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src || !srcLen || !dstLen || *srcLen < 0 || *dstLen < 0)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    if ((dst && !*dstLen) || !*srcLen)
    {
        WAP_DBG_ASSERT(0);
        *srcLen = *dstLen = 0;
        return KAL_TRUE;
    }

    return widget_encoding_convert_charset_to_utf8(src, dst, *srcLen, *dstLen, srcLen, dstLen, CHSET_GB2312);
}

#else /* __MMI_CHSET_GB2312__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGB2312ToUTF8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  srcLen      [IN/OUT]         
 *  dst         [OUT]         
 *  dstLen      [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtGB2312ToUTF8(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsupported */
    WAP_DBG_ASSERT(0);
    if (dstLen)
    {
        *dstLen = 0;
    }
    return KAL_FALSE;
}

#endif /* __MMI_CHSET_GB2312__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUTF8ToGB2312
 * DESCRIPTION
 *  1. convert GB2312 string to UTF8 string. (if 'dst' paremeter != NULL)
 *  2. determine the required size of destination buffer (if 'dst' paremeter == NULL)
 *  (derived from msf_charset_convert_t)
 * PARAMETERS
 *  src         [IN]            The source buffer
 *  srcLen      [IN/OUT]        On input, number of bytes available in the source buffer On output, the number of bytes consumed.
 *  dst         [OUT]           Is NULL, it will still update *srcLen and *dstLen.
 *  dstLen      [IN/OUT]        On input, free space of destination buffer in bytes On output, the number of bytes placed (not null-terminated).
 * RETURNS
 *  Success or failure (invalid data detected)
 *****************************************************************************/
#ifdef __MMI_CHSET_GB2312__

kal_bool HDIa_widgetExtUTF8ToGB2312(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src || !srcLen || !dstLen || *srcLen < 0 || *dstLen < 0)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    if ((dst && !*dstLen) || !*srcLen)
    {
        WAP_DBG_ASSERT(0);
        *srcLen = *dstLen = 0;
        return KAL_TRUE;
    }

    return widget_encoding_convert_utf8_to_charset(src, dst, *srcLen, *dstLen, srcLen, dstLen, CHSET_GB2312);
}

#else /* __MMI_CHSET_GB2312__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUTF8ToGB2312
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  srcLen      [IN/OUT]         
 *  dst         [OUT]         
 *  dstLen      [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtUTF8ToGB2312(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsupported */
    WAP_DBG_ASSERT(0);
    if (dstLen)
    {
        *dstLen = 0;
    }
    /* keep srcLen unchanged */
    return KAL_FALSE;
}

#endif /* __MMI_CHSET_GB2312__ */ 



/****************************************************************
 *
 *  GB18030
 *
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGB18030ToUTF8
 * DESCRIPTION
 *  1. convert GB18030 string to UTF8 string. (if 'dst' paremeter != NULL)
 *  2. determine the required size of destination buffer (if 'dst' paremeter == NULL)
 *  (derived from msf_charset_convert_t)
 * PARAMETERS
 *  src         [IN]            The source buffer
 *  srcLen      [IN/OUT]        On input, number of bytes available in the source buffer On output, the number of bytes consumed.
 *  dst         [OUT]           Is NULL, it will still update *srcLen and *dstLen.
 *  dstLen      [IN/OUT]        On input, free space of destination buffer in bytes On output, the number of bytes placed (not null-terminated).
 * RETURNS
 *  Success or failure (invalid data detected)
 *****************************************************************************/
#ifdef __MMI_CHSET_GB18030__

kal_bool HDIa_widgetExtGB18030ToUTF8(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32)src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src || !srcLen || !dstLen || *srcLen < 0 || *dstLen < 0)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    if ((dst && !*dstLen) || !*srcLen)
    {
        WAP_DBG_ASSERT(0);
        *srcLen = *dstLen = 0;
        return KAL_TRUE;
    }

    return widget_encoding_convert_charset_to_utf8(src, dst, *srcLen, *dstLen, srcLen, dstLen, CHSET_GB18030);
}

#else /* __MMI_CHSET_GB18030__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtGB18030ToUTF8
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  srcLen      [IN/OUT]         
 *  dst         [OUT]         
 *  dstLen      [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtGB18030ToUTF8(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsupported */
    WAP_DBG_ASSERT(0);
    if (dstLen)
    {
        *dstLen = 0;
    }
    return KAL_FALSE;
}

#endif /* __MMI_CHSET_GB18030__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUTF8ToGB18030
 * DESCRIPTION
 *  1. convert UTF8 string to GB18030 string. (if 'dst' paremeter != NULL)
 *  2. determine the required size of destination buffer (if 'dst' paremeter == NULL)
 *  (derived from msf_charset_convert_t)
 * PARAMETERS
 *  src         [IN]            The source buffer
 *  srcLen      [IN/OUT]        On input, number of bytes available in the source buffer On output, the number of bytes consumed.
 *  dst         [OUT]           Is NULL, it will still update *srcLen and *dstLen.
 *  dstLen      [IN/OUT]        On input, free space of destination buffer in bytes On output, the number of bytes placed (not null-terminated).
 * RETURNS
 *  Success or failure (invalid data detected)
 *****************************************************************************/
#ifdef __MMI_CHSET_GB18030__

kal_bool HDIa_widgetExtUTF8ToGB18030(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 src_end_pos = (kal_uint32)src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src || !srcLen || !dstLen || *srcLen < 0 || *dstLen < 0)
    {
        WAP_BYPASS_ASSERT(0);
        return KAL_FALSE;
    }

    if ((dst && !*dstLen) || !*srcLen)
    {
        WAP_DBG_ASSERT(0);
        *srcLen = *dstLen = 0;
        return KAL_TRUE;
    }

    return widget_encoding_convert_utf8_to_charset(src, dst, *srcLen, *dstLen, srcLen, dstLen, CHSET_GB18030);
}

#else /* __MMI_CHSET_GB18030__ */ 


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetExtUTF8ToGB18030
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src         [IN]        
 *  srcLen      [IN/OUT]         
 *  dst         [OUT]         
 *  dstLen      [IN/OUT]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool HDIa_widgetExtUTF8ToGB18030(const kal_uint8 *src, kal_int32 *srcLen, kal_uint8 *dst, kal_int32 *dstLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Unsupported */
    WAP_DBG_ASSERT(0);
    if (dstLen)
    {
        *dstLen = 0;
    }
    /* keep srcLen unchanged */
    return KAL_FALSE;
}

#endif /* __MMI_CHSET_GB2312__ */ 




