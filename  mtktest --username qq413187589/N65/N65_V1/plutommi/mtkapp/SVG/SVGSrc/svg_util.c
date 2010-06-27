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
 *  svg
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SVG tiny basic library
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_include.h"
#if defined(SVG_SUPPORT)

#include "ctype.h"
#include "Conversions.h"

#include "svg_internal.h"

////////////////////////////////////////////////////////////////////////
///  CONST DATA POOL
///  insert data into hash spool , the same data only appear once
////////////////////////////////////////////////////////////////////////
static svg_hash_t *svg_const_data;


/*****************************************************************************
 * FUNCTION
 *  svg_const_pool_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
svg_enum svg_const_pool_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_const_data = svg_hash_create(16);   /* use 16 entry to store attribute string table */
    if (!svg_const_data)
    {
        return SVG_FAIL_NO_MEMORY;
    }
    return SVG_OK;
}


/*****************************************************************************
 * FUNCTION
 *  svg_const_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value       [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 *svg_const_pool(U8 *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ret_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_hash_add(svg_const_data, value, NULL, &ret_id); /* add into hash */
    return ret_id;
}


/*****************************************************************************
 * FUNCTION
 *  svg_const_pool_raw
 * DESCRIPTION
 *  
 * PARAMETERS
 *  value       [?]         
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 *svg_const_pool_raw(U8 *value, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ret_id;
    U32 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_hash_add_raw(svg_const_data, value, len, NULL, &ret_id, &tmp);
    return ret_id;
}


/*****************************************************************************
 * FUNCTION
 *  svg_const_pool_utf82ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data            [?]     
 *  dest_len        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U8 *svg_const_pool_utf82ucs2(U8 *data, U32 *dest_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *ucs2, *ret;
    U32 ucs2_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_len = mmi_chset_utf8_strlen(data);
    ucs2_len = (ucs2_len + 1) * 2;
    ucs2 = svg_mem_malloc(ucs2_len);
    mmi_chset_utf8_to_ucs2_string(ucs2, ucs2_len, data);
    if (dest_len)
    {
        *dest_len = ucs2_len;
    }
    ret = svg_const_pool_raw(ucs2, ucs2_len);
    svg_mem_free(ucs2);

    return ret;
}

//////////////////////////////////////////////////////////////////////////
/// FILE SYSTEM PATH TOOL
//////////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  svg_fp_to_dos_slash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_fp_to_dos_slash(U16 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*p)
    {
        if (*p == '/')
        {
            *p = '\\';
        }
        p++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_fp_to_dirname
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_fp_to_dirname(U16 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *last_slash = p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*p)
    {
        if (*p == '\\')
        {
            last_slash = p + 1; /* keep slash */
        }
        p++;
    }
    *last_slash = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  svg_fp_split_first_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir             [IN]        
 *  dir1            [IN]        
 *  fullpath        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void svg_fp_split_first_dir(U16 **dir, U16 **dir1, U16 *fullpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (pos = fullpath; *pos; pos++)
        if (*pos == '\\')
        {
            break;
        }

    if (*pos == (U16) NULL) /* can't find '\\' */
    {
        *dir = NULL;
        *dir1 = fullpath;
    }
    else
    {
        *dir = fullpath;
        *pos = '\0';
        *dir1 = pos + 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_fp_drop_last_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_fp_drop_last_dir(U16 *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *q = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*p)
    {
        if (*p == '\\' && *(p + 1) != '\0')
        {
            q = p + 1;  /* keep '\\' */
        }
        p++;
    }
    if (q)
    {
        *q = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  _svg_fp_concat_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 *  folder      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void _svg_fp_concat_path(U16 *path, U16 *folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*folder == '.' && *(folder + 1) == 0)   /* '.' */
    {
        ;
    }
    else if (*folder == '.' && *(folder + 1) == '.' && *(folder + 2) == 0)      /* '..' */
    {
        svg_fp_drop_last_dir(path);
    }
    else
    {
        U16 *p;

        for (p = path; *p; p++);            /* seek to the end */
        if (p != path && *(p - 1) != '\\')  /* append '\\' */
        {
            *p = '\\';
            p++;
        }

        /* concat */
        for (; *folder; folder++, p++)
        {
            *p = *folder;
        }

        *p = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_fp_concat_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     
 *  path1       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_fp_concat_path(U16 *path, U16 *path1)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dir, *dir1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        svg_fp_split_first_dir(&dir, &dir1, path1);
        if (dir == NULL)
        {
            break;
        }
        _svg_fp_concat_path(path, dir);
        path1 = dir1;
    }
    _svg_fp_concat_path(path, path1);
}

////////////////////////////////////////////////////////////////////////
/// BASE64 decode
////////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION
 *  svg_base64_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 svg_base64_len(U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 4 + (len * 3) / 4;
}


/*****************************************************************************
 * FUNCTION
 *  svg_base64_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dest        [?]         
 *  len         [?]         
 *  src         [?]         
 *  srcl        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_base64_decode(U8 *dest, U32 *len, U8 *src, U32 srcl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define SHORT_STRING    128
#define JNK                      0177
#define PAD                      0100

    U8 c, *temp_dst;
    U8 dst[SHORT_STRING];
    U16 e;
    U32 rt = 0, num = 0, cntr;
    const static U8 decode[256] = 
    {
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, 076, JNK, JNK, JNK, 077,
        064, 065, 066, 067, 070, 071, 072, 073, 074, 075, JNK, JNK, JNK, PAD, JNK, JNK,
        JNK, 000, 001, 002, 003, 004, 005, 006, 007, 010, 011, 012, 013, 014, 015, 016,
        017, 020, 021, 022, 023, 024, 025, 026, 027, 030, 031, JNK, JNK, JNK, JNK, JNK,
        JNK, 032, 033, 034, 035, 036, 037, 040, 041, 042, 043, 044, 045, 046, 047, 050,
        051, 052, 053, 054, 055, 056, 057, 060, 061, 062, 063, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK,
        JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK, JNK
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Number of encoded bytes considered for decoding */
    num = ((SHORT_STRING / 3) * 4) - 4;

    *len = 4 + (srcl * 3) / 4;
    cntr = 0;

    memset(dst, 0, SHORT_STRING);
    temp_dst = (U8*) dst;

    *len = 0;   /* in case we return an error */
    /* simple-minded decode */
    for (e = 0; srcl--;)
    {
        switch (c = decode[*src++])
        {
            default:                            /* valid BASE64 data character */
                switch (e++)
                {                               /* install based on quantum position */
                    case 0:
                        *temp_dst = c << 2;
                        break;
                    case 1:
                        *temp_dst++ |= c >> 4;  /* byte 1: low 2 bits */
                        *temp_dst = c << 4;     /* byte 2: high 4 bits */
                        break;
                    case 2:
                        *temp_dst++ |= c >> 2;  /* byte 2: low 4 bits */
                        *temp_dst = c << 6;     /* byte 3: high 2 bits */
                        break;
                    case 3:
                        *temp_dst++ |= c;       /* byte 3: low 6 bits */
                        e = 0;
                        cntr += 4;
                        if (cntr == num)
                        {
                            /* Copying the decoded data on to the source buffer */
                            memcpy(dest + rt, dst, ((U8*) temp_dst - dst));
                            cntr = 0;
                            rt = rt + ((U8*) temp_dst - dst);
                            memset(dst, 0, SHORT_STRING);
                            temp_dst = dst; /* Reset the temp_dst pointer back to dst */
                        }
                        break;
                }       /* switch (e) */
                break;
            case JNK:   /* junk character */
                break;
            case PAD:   /* padding */
                switch (e++)
                {
                    case 3:
                        for (; srcl; --srcl)
                        {
                            switch (decode[*src++])
                            {
                                case JNK:
                                case PAD:   /* ignore junk and extraneous padding */
                                    break;
                                default:    /* valid BASE64 data character */
                                    if (srcl == 0)
                                    {
                                        if (temp_dst != dst)
                                        {
                                            memcpy(dest + rt, dst, ((U8*) temp_dst - dst));
                                            memset(dst, 0, SHORT_STRING);
                                            rt = rt + ((U8*) temp_dst - dst);
                                            temp_dst = dst;
                                        }
                                    }
                                    srcl = 1;   /* don't issue any  more messages */
                                    break;
                            }
                        }
                        if (srcl == 0)
                        {
                            if (temp_dst != dst)        /* When temp_dst and dst are same then
                                                           there are no decoded data present
                                                           in dst */
                            {
                                memcpy(dest + rt, dst, ((U8*) temp_dst - dst));
                                memset(dst, 0, SHORT_STRING);
                                rt = rt + ((U8*) temp_dst - dst);
                                temp_dst = dst; /* Reset the temp_dst back to dst */
                            }
                        }
                        break;
                    case 2: /* expect a second = in quantum 2 */
                        if (srcl == 0)
                        {
                            if (temp_dst != dst)
                            {
                                memcpy(dest + rt, dst, ((U8*) temp_dst - dst));
                                memset(dst, 0, SHORT_STRING);
                                rt = rt + ((U8*) temp_dst - dst);
                                temp_dst = dst;
                            }
                        }
                        if (srcl && (*src == '='))
                        {
                            break;
                        }
                    default:    /* impossible quantum position */
                        return;
                }               /* switch */
                break;
        }                       /* Switch */
    }

    /* Any Left over bytes present in the dst and if needs to be copied */
    if (temp_dst != dst)
    {
        memcpy(dest + rt, dst, ((U8*) temp_dst - dst));
        memset(dst, 0, SHORT_STRING);
        rt = rt + ((U8*) temp_dst - dst);
        temp_dst = dst;
    }
    *len = rt;  /* Assigning the Final decoded data length as in Source buffer */
}


/*****************************************************************************
 * FUNCTION
 *  svg_vec_to_angle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
float svg_vec_to_angle(float x, float y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    float r, angle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    r = sqrt(x * x + y * y);
    if (r == 0)
    {
        return 0;
    }

    angle = asin(y / r);
    if (x < 0)
    {
        angle = M_PI - angle;
    }

    angle += M_PI;

    return angle;
}


/*****************************************************************************
 * FUNCTION
 *  svg_str_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [?]     
 * RETURNS
 *  
 *****************************************************************************/
svg_string_t *svg_str_new(U8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    svg_string_t *str = svg_mem_malloc(sizeof(svg_string_t));
    U32 len = STRLEN(src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str->max_len = len + 16;
    str->data = svg_mem_malloc(str->max_len + 1);
    memcpy(str->data, src, len + 1);    /* copy string content + null char */
    str->len = len;

    return str;
}


/*****************************************************************************
 * FUNCTION
 *  svg_str_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_str_delete(svg_string_t *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    svg_mem_free(str->data);
    svg_mem_free(str);
}


/*****************************************************************************
 * FUNCTION
 *  svg_str_resize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str         [?]         
 *  max_len     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void svg_str_resize(svg_string_t *str, int max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (max_len != str->max_len)
    {
        U8 *new_data = svg_mem_malloc(max_len + 1);

        if (str->max_len <= max_len)
        {
            memcpy(new_data, str->data, str->len + 1);  /* copy string content + null char */
        }
        else
        {
            memcpy(new_data, str->data, max_len);
            new_data[max_len] = 0;  /* append null char */
            str->len = max_len;
        }
        str->max_len = max_len;
        svg_mem_free(str->data);

        str->data = new_data;

    }
}


/*****************************************************************************
 * FUNCTION
 *  svg_str_append
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str         [?]     
 *  data        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void svg_str_append(svg_string_t *str, U8 *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 data_len = STRLEN(data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str->len + data_len > str->max_len)
    {
        svg_str_resize(str, str->len + data_len + 16);
    }

    memcpy(str->data + str->len, data, data_len + 1);   /* append string content + null char */
    str->len += data_len;
}

static void swap(char *a, char *b, unsigned width)
{
    char tmp;

    if (a != b)
    {
        while (width--) 
        {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
    }
}
static void shortsort(char *lo, char *hi, unsigned width, int (*comp)(const void *, const void *))
{
    char *p, *max;

    while (hi > lo) 
    {
        max = lo;
        for (p = lo+width; p <= hi; p += width) 
            if (comp(p, max) > 0) 
                max = p;
        swap(max, hi, width);
        hi -= width;
    }
}

void svg_qsort(void *base, unsigned num, unsigned width, int (*comp)(const void *, const void *))
{
    char *lo, *hi;
    char *mid;
    char *loguy, *higuy;
    unsigned size;
    char *lostk[30], *histk[30];
    int stkptr;

    if (num < 2 || width == 0) return;
    stkptr = 0;

    lo = base;
    hi = (char *) base + width * (num - 1);

recurse:
    size = (hi - lo) / width + 1;

    if (size <= 8) 
    {
        shortsort(lo, hi, width, comp);
    }
    else 
    {
        mid = lo + (size / 2) * width;
        swap(mid, lo, width);

        loguy = lo;
        higuy = hi + width;

        for (;;)
        {
            do { loguy += width; } while (loguy <= hi && comp(loguy, lo) <= 0);
            do { higuy -= width; } while (higuy > lo && comp(higuy, lo) >= 0);
            if (higuy < loguy) break;
            swap(loguy, higuy, width);
        }

        swap(lo, higuy, width);

        if (higuy - 1 - lo >= hi - loguy) 
        {
            if (lo + width < higuy) 
            {
                lostk[stkptr] = lo;
                histk[stkptr] = higuy - width;
                ++stkptr;
            }
            if (loguy < hi) 
            {
                lo = loguy;
                goto recurse;
            }
        }
        else
        {
            if (loguy < hi) 
            {
                lostk[stkptr] = loguy;
                histk[stkptr] = hi;
                ++stkptr;
            }
            if (lo + width < higuy) 
            {
                hi = higuy - width;
                goto recurse;
            }
        }
    }

    --stkptr;
    if (stkptr >= 0) 
    {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;
    }
    else
        return;
}




#endif /* __MMI_SVG__ */ /* __SVG__ */

