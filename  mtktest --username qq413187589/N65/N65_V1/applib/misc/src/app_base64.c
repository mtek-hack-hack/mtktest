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
 * app_base64.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains Base64 decode / encode functions.
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
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "app_base64.h"

#define BASE64_WARING() 
#define BASE64_ASSERT(b) 

#define BASE64_LINE_WRAP_COUNT   76

#define DPAD 0x7D
#define DWSP 0x7E
#define DNIL 0x7F

#define BASE64_ENCODE_1(dst,src) do{                                      \
    dst[0] = BASE64_ENCODE_TABLE[src[0] >> 2];                            \
    dst[1] = BASE64_ENCODE_TABLE[(src[0] << 4) & 0x3f];                   \
    dst[2] = '=';                                                         \
    dst[3] = '=';                                                         \
    } while(0)

#define BASE64_ENCODE_2(dst,src) do{                                      \
    dst[0] = BASE64_ENCODE_TABLE[src[0] >> 2];                            \
    dst[1] = BASE64_ENCODE_TABLE[((src[0] << 4) + (src[1] >> 4)) & 0x3f]; \
    dst[2] = BASE64_ENCODE_TABLE[(src[1] << 2) & 0x3f];                   \
    dst[3] = '=';                                                         \
    } while(0)

#define BASE64_ENCODE_3(dst,src) do{                                      \
    dst[0] = BASE64_ENCODE_TABLE[src[0] >> 2];                            \
    dst[1] = BASE64_ENCODE_TABLE[((src[0] << 4) + (src[1] >> 4)) & 0x3f]; \
    dst[2] = BASE64_ENCODE_TABLE[((src[1] << 2) + (src[2] >> 6)) & 0x3f]; \
    dst[3] = BASE64_ENCODE_TABLE[src[2] & 0x3f];                          \
    } while(0)

#define BASE64_DECODE_2(dst,src) do{            \
    dst[0] = (src[0] << 2) | (src[1] >> 4);     \
    } while(0)

#define BASE64_DECODE_3(dst,src) do{            \
    dst[0] = (src[0] << 2) | (src[1] >> 4);     \
    dst[1] = (src[1] << 4) | (src[2] >> 2);     \
    } while(0)

#define BASE64_DECODE_4(dst,src) do{            \
    dst[0] = (src[0] << 2) | (src[1] >> 4);     \
    dst[1] = (src[1] << 4) | (src[2] >> 2);     \
    dst[2] = (src[2] << 6) | (src[3]);          \
    } while(0)

static kal_char BASE64_ENCODE_TABLE[64] =
{
    'A','B','C','D','E','F','G','H', 'I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X', 'Y','Z','a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n', 'o','p','q','r','s','t','u','v',
    'w','x','y','z','0','1','2','3', '4','5','6','7','8','9','+','/'
};

static kal_char BASE64_DECODE_TABLE[256] = 
{
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DWSP, DWSP, DWSP, DNIL, DWSP, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DWSP, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, 0x3E, DNIL, DNIL, DNIL, 0x3F,
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, DNIL, DNIL, DNIL, DPAD, DNIL, DNIL,

    DNIL, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
    0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x19, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30,
    0x31, 0x32, 0x33, DNIL, DNIL, DNIL, DNIL, DNIL,

    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,

    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL,
    DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL, DNIL
};

static void check_illegal_pad(applib_base64_part_context* cntx,
                const kal_char *src,kal_int32 srcl);


/*****************************************************************************
 * FUNCTION
 *  applib_base64_part_encode_init
 * DESCRIPTION
 *  This function initializes the STREAM-STYLE part by part BASE64 
 *  encode process and calculate the needed output buffer size per-part.
 * PARAMETERS
 *  cntx            [IN]        point to the applib_base64_part_context
 *  max_part_size   [IN]        the number of MAX input buffer size per-part.
 *  line_wrap_count [IN]        line wrap count
 * RETURNS
 *  negative:   invalid parameter.
 *  ow: the MIN output buffer size needed for the per-parts process.
 *****************************************************************************/
kal_int32 applib_base64_part_encode_init(
            applib_base64_part_context *cntx,
            kal_int32 max_part_buf_size,
            kal_bool  auto_line_wrap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        BASE64_ASSERT(0);
        return -1;
    }

    size = 0;
    if (max_part_buf_size > 0)
    {
        size = max_part_buf_size + 2; /* the last part remainder */
        size = (size + 2 ) / 3 * 4;   /* 3bytes to 4 bytes */
    }

    cntx->wrap_max = 0;
    if (auto_line_wrap)
    {
        cntx->wrap_max = BASE64_LINE_WRAP_COUNT; /* 76 */
        if (size > 0)
        {
            size += (size / BASE64_LINE_WRAP_COUNT + 1) * 2;
        }
    }

    cntx->buf_cnt = 0;
    cntx->wrap_count = 0;
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_part_encode_append
 * DESCRIPTION
 *  This function encode next part data to BASE64.
 * PARAMETERS
 *  cntx        [IN]            Part process context
 *  src         [IN]            Source data
 *  srcl        [IN/OUT]        Source data length
 *  dest        [IN/OUT]        Encoded data
 *  destl       [IN]            Destination buffer length
 * RETURNS
 *  negative  : parameter error
 *  otherwise : length of encoded bytes
 *****************************************************************************/
kal_int32 applib_base64_part_encode_append(
            applib_base64_part_context *cntx,
            const kal_char *src,
            kal_int32 *srcl,
            kal_char  *dst,
            kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i_input,i_output;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || cntx->buf_cnt > 2 ||
        srcl == NULL || (*srcl > 0 && src == NULL))
    {
        BASE64_ASSERT(0);
        return -1;
    }

    /* encode it */
    i_input = i_output = 0;
    while(i_input < *srcl)
    {
        BASE64_ASSERT(cntx->buf_cnt <= 2);

        cntx->buf[cntx->buf_cnt++] = src[i_input++];
        if (cntx->buf_cnt < 3)
        {
            continue;
        }

        /* cntx->buf_cnt == 3 */
        if (i_output + 4 > dstl)
        {
            /* roll back */
            i_input--;
            cntx->buf_cnt--;
            break;
        }

        /* Encode the three-bytes to four bytes */
        BASE64_ENCODE_3((dst+i_output),cntx->buf);
        i_output += 4;
        cntx->buf_cnt = 0;
        
        /* line break */
        if (cntx->wrap_max == 0)
        {
            /* No need to break line */
            continue;
        }

        cntx->wrap_count += 4;
        if (cntx->wrap_count < cntx->wrap_max)
        {
            /* Not reach the wrap count */
            continue;
        }

        /* Check if output buffer is enough */
        if (i_output + 2 > dstl)
        {
            /* roll back one bytes */
            i_input--;
            cntx->buf_cnt = 2;
            i_output -= 4;
            cntx->wrap_count -= 4;
            break;
        }

        if (dst == NULL)
        {
            BASE64_ASSERT(0);
            return -1;
        }
        dst[i_output++] = '\r';
        dst[i_output++] = '\n';
        cntx->wrap_count = 0;
    }

    if (*srcl != i_input)
    {
        /* Waring */
        BASE64_WARING();
    }

    BASE64_ASSERT(cntx->buf_cnt <= 2);

    *srcl = i_input;
    return i_output;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_part_encode_finish
 * DESCRIPTION
 *  This function finish the part-by-part BASE64 encode.
 * PARAMETERS
 *  cntx        [IN]            Part process context
 *  dest        [IN/OUT]        Encoded data
 *  destl       [IN]            Destination buffer length
 * RETURNS
 *  negative  : parameter error or buffer NOT enough
 *  otherwise : length of encoded bytes
 *****************************************************************************/
kal_int32 applib_base64_part_encode_finish(
            applib_base64_part_context* cntx,
            kal_char *dst,
            kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || cntx->buf_cnt > 2)
    {
        BASE64_ASSERT(0);
        return -1;
    }

    /* no unprocessed data */
    if (cntx->buf_cnt == 0)
    {
        if (cntx->wrap_max > 0 && cntx->wrap_count > 0)
        {
            if (dstl < 2)
            {
                BASE64_ASSERT(0);
                return -1;
            }
            dst[0] = '\r';
            dst[1] = '\n';
            return 2;
        }
        else
        {
            return 0;
        }   
    }

    if (dst == NULL || dstl < 4)
    {
        BASE64_ASSERT(0);
        return -1;
    }

    if (cntx->buf_cnt == 1)
    {
        BASE64_ENCODE_1(dst,cntx->buf);
    }
    else if (cntx->buf_cnt == 2)
    {
        BASE64_ENCODE_2(dst,cntx->buf);
    }
    else
    {
        BASE64_ASSERT(0);
    }

    if (cntx->wrap_max > 0 && cntx->wrap_count > 0)
    {
        if (dstl < 6)
        {
            BASE64_ASSERT(0);
            return -1;
        }
        dst[4] = '\r';
        dst[5] = '\n';
        return 6;
    }
    else
    {
        return 4;
    }   
}



/*****************************************************************************
 * FUNCTION
 *  applib_base64_part_decode_init
 * DESCRIPTION
 *  This function initializes the STREAM-STYLE part by part BASE64 
 *  decode process and calculate the needed output buffer size per-part.
 * PARAMETERS
 *  cntx            [IN]        point to the applib_base64_part_context
 *  max_part_size   [IN]        the number of MAX input buffer size per-part.
 * RETURNS
 *  negative:   invalid parameter.
 *  ow: the MIN output buffer size needed for the per-parts process.
 *****************************************************************************/
kal_int32 applib_base64_part_decode_init(
            applib_base64_part_context *cntx,
            kal_int32 max_part_buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        BASE64_ASSERT(0);
        return -1;
    }

    cntx->buf_cnt = 0;
    cntx->finish_flag = 0;
    cntx->illchr_flag = 0;
    cntx->illpad_flag = 0;
    
    size = 0;
    if (max_part_buf_size > 0)
    {
        size = max_part_buf_size + 3;  /* the last part remainder */
        size = (size + 3 ) / 4 * 3;    /* 4Bytes to 3Bytes */
    }

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_part_decode_append
 * DESCRIPTION
 *  This function accepts next part of source data; 
 *  decode them from BASE64 format
 * PARAMETERS
 *  cntx        [IN]        point to the applib_base64_part_context
 *  src         [IN]        pointer to the input buffer
 *  srcl        [IN]        length of the input buffer
 *  dest        [IN/OUT]    pointer to the output buffer
 *  destl       [IN]        length of the output buffer
 * RETURNS
 *  negative:   Invalid paramter.
 *  ow: the number of bytes written to output buffer.
 *****************************************************************************/
kal_int32 applib_base64_part_decode_append(
            applib_base64_part_context* cntx,
            const kal_char *src,
            kal_int32 *srcl,
            kal_char *dst,
            kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char  c;
    kal_int32 i_input,i_output;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || 
        (cntx->finish_flag && cntx->buf_cnt > 4) ||
        (!cntx->finish_flag && cntx->buf_cnt > 3) ||
        srcl == NULL || 
        (*srcl > 0 && src == NULL))
    {
        BASE64_ASSERT(0);
        return -1;
    }
    
    if (cntx->finish_flag)
    {
        /* the "=" had been reached before */
        if (!cntx->illpad_flag)
        {
            check_illegal_pad(cntx,src,*srcl);
        }
        
        return 0;
    }
    
    /* 
    * begin decode this part content 
    * Skip all NOT BASE64 CHARACTER
    * End the decode if '=' was founded.
    */
    i_input = i_output = 0;
    while(i_input < *srcl)
    {
        /* assert check */
        BASE64_ASSERT(cntx->buf_cnt <= 3);

        c = BASE64_DECODE_TABLE[(kal_uint8)(src[i_input++])];

        if (c == DWSP)
        {
            continue;
        }
        else if (c == DNIL)
        {
            cntx->illchr_flag = 1;
            continue;
        }
        else if (c == DPAD)
        {
            cntx->finish_flag = 1;
            if (cntx->buf_cnt < 2)
            {
                BASE64_WARING();
                cntx->illpad_flag = 1;
                break;
            }

            if (i_output + cntx->buf_cnt - 1 > dstl)
            {
                /* output buffer is NOT enough */
                /* roll back */
                cntx->finish_flag = 0;
                i_input--;
                break;
            }
            
            if (cntx->buf_cnt == 2)
            {
                BASE64_DECODE_2((dst+i_output),cntx->buf);
            }
            else
            {
                BASE64_DECODE_3((dst+i_output),cntx->buf);
            }
            i_output += cntx->buf_cnt - 1;
            cntx->buf[cntx->buf_cnt++] = c;

            check_illegal_pad(cntx,src+i_input,*srcl-i_input);
            i_input = *srcl; /* all data have been processed */
            break;
        }
        else
        {
            /* Decode the bytes upto 4-group */
            cntx->buf[cntx->buf_cnt++] = c;

            /* four bytes readed,DECODE IT */
            if (cntx->buf_cnt < 4)
            {
                continue;
            }           
            
            if (i_output + 3 > dstl)
            {
                /* roll back */
                cntx->buf_cnt--;
                i_input--;
                break;
            }

            BASE64_DECODE_4((dst+i_output),cntx->buf);
            i_output += 3;
            cntx->buf_cnt = 0;
        }
        
        /* assert check */
        BASE64_ASSERT(cntx->buf_cnt <= 3);
    }

    if (*srcl != i_input)
    {
        /* warning */
        BASE64_WARING();
    }
    
    *srcl = i_input;
    return i_output;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_part_decode_finish
 * DESCRIPTION
 *  This function finishes the part-by-part decoding process.
 * PARAMETERS
 *  cntx           [IN]        point to the applib_base64_part_context
 *  illegal_format [IN/OUT]    pointer to the illegal format flag
 * RETURNS
 *  0:    success
 *  ow:   the context was NULL
 *****************************************************************************/
kal_int32 applib_base64_part_decode_finish(
            applib_base64_part_context* cntx,
            kal_bool* illegal_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        BASE64_ASSERT(0);
        return -1;
    }

    /* No need to report the illegal flag */

    
    if (cntx->finish_flag)
    {
        if (cntx->buf_cnt != 4)
        {
            BASE64_WARING();
            cntx->illpad_flag = 1;
        }
    }
    else
    {
        if (cntx->buf_cnt != 0)
        {
            BASE64_WARING();
            cntx->illpad_flag = 1;
        }
    }    
    
    if (illegal_format != NULL)
    {
        if (cntx->illchr_flag || cntx->illpad_flag)
        {
            *illegal_format = KAL_TRUE;
        }
        else
        {       
            *illegal_format = KAL_FALSE;
        }
    }
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  check_illegal_pad
 * DESCRIPTION
 *  This function check if the input data is illegal formatted.
 * PARAMETERS
 *  cntx        [IN]        point to the applib_base64_part_context
 *  src         [IN]        pointer to the input buffer
 *  srcl        [IN]        length of the input buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void check_illegal_pad(applib_base64_part_context* cntx,
                            const kal_char *src,
                            kal_int32 srcl)
{
    kal_int32 pos;
    kal_char  c;
    if (cntx->illpad_flag)
    {
        return;
    }

    if (srcl <= 0)
    {
        return;
    }

    BASE64_ASSERT(src != NULL);

    pos = 0;
    if (cntx->buf_cnt == 3)
    {
        while(pos < srcl)
        {
            c = BASE64_DECODE_TABLE[(kal_uint8)src[pos++]];
            if (c == DPAD)
            {
                cntx->buf[cntx->buf_cnt++] = DPAD;
                break;
            }
            else if (c == DWSP)
            {
                continue;
            }
            else
            {
                BASE64_WARING();
                cntx->illpad_flag = 1;
                /* no need to check the following character */
                return;
            }
        }
    }

    if (cntx->buf_cnt == 4)
    {
        while(pos < srcl)
        {
            c = BASE64_DECODE_TABLE[(kal_uint8)src[pos++]];
            if (c != DWSP)
            {
                BASE64_WARING();
                cntx->illpad_flag = 1;
                /* no need to check the following character */
                return;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_encode_basic
 * DESCRIPTION
 *  This function is used to encode given string into base64 encoded string.
 * PARAMETERS
 *  src         [IN]            Source data
 *  srcl        [IN]            Source data length
 *  dest        [IN/OUT]        Encoded data
 *  destl       [IN]            Destination buffer length
 * RETURNS
 *  negative: error
 *  ow:length of encoded string
 *****************************************************************************/
kal_int32 applib_base64_encode_basic(const kal_char *src, kal_int32 srcl,
            kal_char *dst,kal_int32 dstl,kal_bool auto_line_wrap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len,size,temp;
    applib_base64_part_context cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srcl <= 0)
    {
        return 0;
    }

    /* cal the needed output buffer size */
    size = (srcl + 2) / 3 * 4;
    if (auto_line_wrap)
    {
        size += (size / BASE64_LINE_WRAP_COUNT + 1) * 2;
    }

    if (dst == NULL)
    {
        /* just report the needed output buffer size */
        return size;
    }

    if (src == NULL || dstl < size)
    {
        /* the output buffer is not enough */
        BASE64_ASSERT(0);
        return -1;
    }

    /* encode it */
    applib_base64_part_encode_init(&cntx, 0, auto_line_wrap);

    temp = srcl;
    len = applib_base64_part_encode_append(&cntx, src, &temp, dst, dstl);
    BASE64_ASSERT(temp == srcl);
    BASE64_ASSERT(len <= dstl);

    temp = applib_base64_part_encode_finish(&cntx, dst + len, dstl - len);
    BASE64_ASSERT(temp >= 0);
    len += temp;
    BASE64_ASSERT(len <= dstl);

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_decode_basic
 * DESCRIPTION
 *  This function is used to decode Base64 string.
 * PARAMETERS
 *  src         [IN]            Pointer to the buffer containing encoded data
 *  srcl        [IN]            Length of the encoded data
 *  dest        [IN/OUT]        Pointer to the buffer containing decoded data
 *  destl       [IN]            Length of destination buffer.
 * RETURNS
 *  negative: error
 *  ow: Length of the decoded data
 *****************************************************************************/
kal_int32 applib_base64_decode_basic(const kal_char *src, kal_int32 srcl,
            kal_char *dst,kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len,temp;
    applib_base64_part_context cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srcl <= 0)
    {
        /* No data need to be processed */
        return 0;
    }

    if (dst == NULL)
    {
        /* just report the needed output buffer size */
        len = srcl / 4 * 3;
        if (srcl > 1 && src[srcl-1] == '=')
        {
            len--;
        }
        if (srcl > 2 && src[srcl-1] == '=' && src[srcl - 2] == '=')
        {
            len --;
        }
        return len;
    }

    /* decode it */
    temp = srcl;
    applib_base64_part_decode_init(&cntx,0);
    len = applib_base64_part_decode_append(&cntx,src,&temp,dst,dstl);
    applib_base64_part_decode_finish(&cntx,NULL);

    if (len < 0 || temp != srcl)
    {
        /* the output buffer is not enough */
        BASE64_ASSERT(0);
        return -1;
    }

    return len;
}


/* 
 * NOTE:
 * the Functions below will be obsoleted!
 * them are here just for compatible with old code.
 */


/*****************************************************************************
 * FUNCTION
 *  applib_base64_decode
 * DESCRIPTION
 *  This function is used to decode Base64 string.
 * PARAMETERS
 *  src    [IN]     Pointer to the buffer containing encoded data
 *  srcl   [IN]     Length of the encoded data
 *  dest   [IN/OUT] Pointer to the buffer containing decoded data
 *  destl  [IN]     Length of destination buffer Will append null character.
 * RETURNS
 *  negative: error
 *  ow: Length of the decoded data (not include null character)
 *****************************************************************************/
kal_int32 applib_base64_decode(kal_char *src, kal_uint32 srcl, 
            kal_char *dest, kal_uint32 destl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
    {
        return -1;
    }

    ret = applib_base64_decode_basic(src,srcl,dest,destl);
    if (ret <= 0 || ret >= (kal_int32)destl)
    {
        return -1;
    }

    /* 
     * add the null-end,
     * but the return length not include the null-terminator 
     */
    dest[ret] = 0;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_decode_len
 * DESCRIPTION
 *  This function is used to calculate decoded base64 string length
 * PARAMETERS
 *  len         [IN]            Source data byte length
 * RETURNS
 *  negative: error
 *  ow:length of encoded string
 *****************************************************************************/
kal_uint32 applib_base64_decode_len(const kal_char *str, kal_uint32 len)
{
/*  kal_uint32 new_len = (len / 4) * 3;

  if ((len > 0) && (str[len - 1] == '='))
    new_len--;
  if ((len > 1) && (str[len - 2] == '='))
    new_len--;

  return new_len;*/
  return len;
}


/*****************************************************************************
 * FUNCTION
 *  applib_find_base64_boundary
 * DESCRIPTION
 *  This function finds the boundary in the base64 encoded text.
 * PARAMETERS
 *  ptr     [IN]        Pointer to the encoded buffer
 *  len     [IN]        Length of encoded data
 * RETURNS
 *  number of bytes shall be skipped.
 *****************************************************************************/
kal_uint16 applib_find_base64_boundary(kal_char *ptr, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /* with initial values */
    kal_uint16 left_over_bytes = len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len <= 0)   /* no data */
    {
        return 0;
    }

    for (i = len - 1; i > 0; i--)
    {
        if (*(ptr + i - 1) == '\r' && *(ptr + i) == '\n')
        {
            left_over_bytes = len - i + 1 - 2 /* crlf */ ;
            break;
        }

        /* Handle the case that the line is ended with only LF not CRLF */
        if (*(ptr + i) == '\n')
        {
            left_over_bytes = len - i + 1 - 1 /* lf */ ;
            break;
        }
    }

    return left_over_bytes;

}   /* end of applib_find_base64_boundary */


/*****************************************************************************
 * FUNCTION
 *  applib_base64_encode
 * DESCRIPTION
 *  This function is used to encode given string into base64 encoded string.
 * PARAMETERS
 *  src         [IN]            Source data
 *  srcl        [IN]            Source data length
 *  dest        [IN/OUT]        Encoded data
 *  destl       [IN]            Destination buffer length
 * RETURNS
 *  negative: error
 *  ow:length of encoded string
 *****************************************************************************/
kal_int32 applib_base64_encode(kal_char *src, kal_uint32 srcl, 
            kal_char *dest, kal_uint32 destl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
    {
        return -1;
    }

    ret = applib_base64_encode_basic(src,srcl,dest,destl,KAL_TRUE);
    if (ret <= 0 || (kal_uint32)ret >= destl)
    {
        return -1;
    }

    /* 
     * add the null-end,
     * but the return length not include the null-terminator 
     */
    dest[ret] = 0;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  applib_base64_encode_len
 * DESCRIPTION
 *  This function is used to calculate converted base64 string length
 * PARAMETERS
 *  len         [IN]            Source data byte length
 * RETURNS
 *  negative: error
 *  ow:length of encoded string
 *****************************************************************************/
kal_uint32 applib_base64_encode_len(kal_uint32 len)
{
  /*return ((len + 2) / 3) * 4;*/
  return (2 * len);
}
