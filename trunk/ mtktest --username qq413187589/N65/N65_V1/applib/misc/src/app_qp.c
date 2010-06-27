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
 * app_qp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains Quote Printable (QP) decode / encode functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_release.h"
#include "app_qp.h"

/* define */

/* debug assert */
#define QP_ASSERT(b)
#define QP_WARRING()

/* line wrap count, see rfc2045, rfc2047 */
/* the 76th postion is reserved for '=' */
#define QP_LINE_WRAP_COUNT     75

/* encode state */
#define QP_ENCD_STATE_INIT      0
#define QP_ENCD_STATE_LWSP      1
#define QP_ENCD_STATE_CR        2
#define QP_ENCD_STATE_LWSPCR    3

/* decode state */
#define QP_DECODE_STATE_INIT    0
#define QP_DECODE_STATE_PAD     1
#define QP_DECODE_STATE_PADHEX  2
#define QP_DECODE_STATE_PADCR   3

/* character macro */
#define QP_IS_TAB(c)     ((c) == 9)
#define QP_IS_SPACE(c)   ((c) == 32)
#define QP_IS_CR(c)      ((c) == 13)
#define QP_IS_LF(c)      ((c) == 10)
#define QP_IS_PAD(c)     ((c) == 61)
#define QP_IS_UDRLNE(c)  ((c) == 95)

#define QP_IS_CRLF(c)    (QP_IS_CR(c)  || QP_IS_LF(c))
#define QP_IS_LWSP(c)    (QP_IS_TAB(c) || QP_IS_SPACE(c))

#define QP_IS_DIGIT(c)   ((c) >= '0' && (c) <= '9')
#define QP_IS_HEX_UP(c)  ((c) >= 'A' && (c) <= 'F')
#define QP_IS_HEX_LOW(c) ((c) >= 'a' && (c) <= 'f')
#define QP_IS_HEX(c)     (QP_IS_DIGIT(c)  || \
                          QP_IS_HEX_UP(c) || \
                          QP_IS_HEX_LOW(c))

/* decode marco, conver the HH to character */
#define QP_GET_HEX_HALF(c)   \
            (QP_IS_DIGIT(c) ? (c - '0') : \
            (QP_IS_HEX_UP(c) ? (c - 'A' + 10) : \
            (QP_IS_HEX_LOW(c) ? (c - 'a' + 10) : 0)))

#define QP_DECD_HEX(c1,c2)   \
            (((QP_GET_HEX_HALF(c1)) << 4) | \
            (QP_GET_HEX_HALF(c2)))

#define QP_NEED_ENCD_CRLF    \
            ((cntx->opt & QPOPT_ENCODE_CRLF) > 0)

#define QP_NEED_ENCD_SPACE   \
            ((cntx->opt & QPOPT_ENCODE_SPACE_TO_UNDERLINE) > 0)

#define QP_NEED_AUTO_WRAP    \
            ((cntx->opt & QPOPT_ENCODE_AUTO_LINEWRAP) > 0)

#define QP_NEED_DECD_UDRLNE  \
            ((cntx->opt & QPOPT_DECODE_UNDERLINE_TO_SPACE) > 0)

/* static data */
static const kal_char QP_HEX_TABLE[] = "0123456789ABCDEF";

/* static function */
/* encode */
static kal_int32 encode_state_init(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

static kal_int32 encode_state_lwsp(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

static kal_int32 encode_state_cr(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

static kal_int32 encode_state_lwspcr(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

/* decode */
static kal_int32 decode_state_init(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

static kal_int32 decode_state_pad(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

static kal_int32 decode_state_padcr(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);

static kal_int32 decode_state_padhex(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c);
/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_encode_init
 * DESCRIPTION
 *  This function initializes the STREAM-STYLE part by part quote-printable 
 *  encode process and calculate the needed output buffer size per-part.
 * PARAMETERS
 *  cntx            [IN]        point to the applib_qprint_context
 *  max_part_size   [IN]        the number of MAX input buffer size per-part.
 *  opt             [IN]        encode option
 * RETURNS
 *  negative:   invalid parameter.
 *  ow: the MIN output buffer size needed for the per-parts process.
 *****************************************************************************/
kal_int32 applib_qprint_part_encode_init(
            applib_qprint_context* cntx,
            kal_int32 max_part_size,
            kal_uint8 opt)
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
        QP_ASSERT(0);
        return -1;
    }

    cntx->opt = opt;
    cntx->line_cnt = 0;
    cntx->state = QP_ENCD_STATE_INIT;

    if (max_part_size <= 0)
    {
        /* no need to cal the per-part output buffer size */
        return 0;
    }

    size = (max_part_size + 2) * 3;
    if (QP_NEED_AUTO_WRAP)
    {
        size += (size / QP_LINE_WRAP_COUNT + 1) * 3;
    }
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_encode_finish
 * DESCRIPTION
 *  This function finishes the part-by-part encoding process; 
 *  encode the last bytes into Quote-Printable format if there are.
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  dest        [IN/OUT]    pointer to the destination buffer
 *  destl       [IN]        length of destination buffer
 * RETURNS
 *  negative:   the destination buffer is not enough.
 *  ow: the number of bytes written to output buffer.
 *****************************************************************************/
kal_int32 applib_qprint_part_encode_finish(
            applib_qprint_context* cntx,
            kal_char *dst,
            kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt,i_output;
    kal_char  buf[8];
    kal_bool  is_wrap_reached;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        QP_ASSERT(0);
        return -1;
    }

    if (QP_NEED_ENCD_CRLF || QP_NEED_ENCD_SPACE)
    {
        QP_ASSERT(cntx->state == QP_ENCD_STATE_INIT);
        return 0;
    }

    /* cntx->encode_crlf == KAL_FALSE */
    cnt = 0;
    switch (cntx->state)
    {
        case QP_ENCD_STATE_INIT:
            /* all data had been processed before */
            return 0;

        case QP_ENCD_STATE_LWSP:
            /* the end character is a SPACE */
            buf[cnt++] = '=';
            buf[cnt++] = QP_HEX_TABLE[(unsigned char)(cntx->remain) >> 4];
            buf[cnt++] = QP_HEX_TABLE[(unsigned char)(cntx->remain) & 0xF];
            break;

        case QP_ENCD_STATE_CR:
            /* invalide, a single CR be at the end */
            buf[cnt++] = '=';
            buf[cnt++] = QP_HEX_TABLE['\r' >> 4];
            buf[cnt++] = QP_HEX_TABLE['\r' & 0xF];
            break;

        case QP_ENCD_STATE_LWSPCR:
            /* invalide, a SPACE/TAB with a single CR be at the end */
            buf[cnt++] = '=';
            buf[cnt++] = QP_HEX_TABLE[(unsigned char)(cntx->remain) >> 4];
            buf[cnt++] = QP_HEX_TABLE[(unsigned char)(cntx->remain) & 0xF];
            buf[cnt++] = '=';
            buf[cnt++] = QP_HEX_TABLE['\r' >> 4];
            buf[cnt++] = QP_HEX_TABLE['\r' & 0xF];
            break;

        default:
            /* Shouldn't happen */
            QP_ASSERT(0);
            return -1;
    }

    /* need to add soft line break ? */
    if (QP_NEED_AUTO_WRAP && 
        ((cntx->line_cnt + cnt) > QP_LINE_WRAP_COUNT))
    {
        is_wrap_reached = KAL_TRUE;
    }
    else
    {
        is_wrap_reached = KAL_FALSE;
    }
    
    /* check whether dst buffer is enough */
    if (dst == NULL || 
        ((cnt + (is_wrap_reached ? 3 : 0)) > dstl))
    {
        /* dst is not enough */
        QP_ASSERT(0);
        return -1;
    }
    
    i_output = 0;
    if (is_wrap_reached)
    {
        /* add soft line break */
        dst[i_output++] = '=';
        dst[i_output++] = '\r';
        dst[i_output++] = '\n';
        cntx->line_cnt = 0;
    }
    
    /* copy temp buf data to dst */
    kal_mem_cpy(dst+i_output,buf,cnt);
    i_output += cnt;
    if (QP_NEED_AUTO_WRAP)
    {
        cntx->line_cnt += cnt;
    }

    QP_ASSERT(cntx->line_cnt <= QP_LINE_WRAP_COUNT);

    return i_output;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_encode_append
 * DESCRIPTION
 *  This function accepts next part of source data; 
 *  encode them to Quote-Printable format
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  src         [IN]        pointer to the input buffer
 *  srcl        [IN]        length of the input buffer
 *  dest        [IN/OUT]    pointer to the output buffer
 *  destl       [IN]        length of the output buffer
 * RETURNS
 *  negative:   the destination buffer is not enough.
 *  ow: the number of bytes written to output buffer.
 *****************************************************************************/
kal_int32 applib_qprint_part_encode_append(
            applib_qprint_context* cntx,
            const kal_char *src,
            kal_int32 *srcl,
            kal_char *dst,
            kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buf[8];
    kal_int32 cnt;

    kal_char  c;
    kal_int32 i_input,i_output;

    kal_char  pre_state;
    kal_char  pre_lwsp;
    kal_int32 pre_line_cnt;

    kal_bool  is_wrap_reached;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || 
        srcl == NULL || 
        (*srcl > 0 && src == NULL))
    {
        QP_ASSERT(0);
        return -1;
    }

    if (cntx->line_cnt > QP_LINE_WRAP_COUNT)
    {
        QP_ASSERT(0);
        return -1;
    }

    i_input = i_output = 0;
    while(i_input < *srcl)
    {
        QP_ASSERT(cntx->line_cnt <= QP_LINE_WRAP_COUNT);

        /* remember the pre-state to enable roll back */
        pre_lwsp = cntx->remain;
        pre_state = cntx->state;
        pre_line_cnt = cntx->line_cnt;

        /* encode to temp buf*/
        c = src[i_input++];
        switch (cntx->state)
        {
        case QP_ENCD_STATE_INIT:
            cnt = encode_state_init(cntx,buf,c);
            break;

        case QP_ENCD_STATE_LWSP:
            cnt = encode_state_lwsp(cntx,buf,c);
            break;

        case QP_ENCD_STATE_CR:
            cnt = encode_state_cr(cntx,buf,c);
            break;
            
        case QP_ENCD_STATE_LWSPCR:
            cnt = encode_state_lwspcr(cntx,buf,c);
            break;

        default:
            cnt = 0;
            QP_ASSERT(0);
            break;
        }

        /* copy to dst and add hard line break if needed */
        QP_ASSERT(cnt >= 0);
        QP_ASSERT(cnt <= 8);
        if (cnt == 0)
        {
            /* No output data yet */
            continue;
        }
        
        if (dst == NULL)
        {
            QP_ASSERT(0);
            return -1;
        }

        /* need to add soft line break ? */
        if (QP_NEED_AUTO_WRAP && 
            ((cntx->line_cnt + cnt) > QP_LINE_WRAP_COUNT))
        {
            is_wrap_reached = KAL_TRUE;
        }
        else
        {
            is_wrap_reached = KAL_FALSE;
        }

        /* check if dst buffer is enough */
        if ((i_output + cnt + (is_wrap_reached ? 3 : 0)) > dstl)
        {
            /* roll back to pre-state */
            i_input--;
            cntx->state = pre_state;
            cntx->remain = pre_lwsp;
            cntx->line_cnt = pre_line_cnt;
            break;
        }
        
        if (is_wrap_reached)
        {
            /* add soft line break */
            dst[i_output++] = '=';
            dst[i_output++] = '\r';
            dst[i_output++] = '\n';
            cntx->line_cnt = 0;
        }
        
        /* copy temp buf data to dst */
        kal_mem_cpy(dst+i_output,buf,cnt);
        i_output += cnt;
        if (QP_NEED_AUTO_WRAP)
        {
            cntx->line_cnt += cnt;
        }

        QP_ASSERT(cntx->line_cnt <= QP_LINE_WRAP_COUNT);
    }

    if (*srcl != i_input)
    {
        QP_WARRING();
    }

    *srcl = i_input;
    return i_output;
}


/*****************************************************************************
 * FUNCTION
 *  encode_state_init
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of encoded bytes
 *****************************************************************************/
static kal_int32 encode_state_init(applib_qprint_context* cntx,
                    kal_char buf[],kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (QP_IS_TAB(c))
    {
        if (QP_NEED_ENCD_CRLF)
        {
            buf[cnt++] = c;
            cntx->state = QP_ENCD_STATE_INIT;
            return cnt;
        }
        else
        {
            cntx->remain = c;
            cntx->state = QP_ENCD_STATE_LWSP;
            return 0;
        }        
    }

    if (QP_IS_SPACE(c))
    {
        if (QP_NEED_ENCD_SPACE)
        {
            buf[cnt++] = '_';
            cntx->state = QP_ENCD_STATE_INIT;
            return cnt;
        }

        if (QP_NEED_ENCD_CRLF)
        {
            buf[cnt++] = c;
            cntx->state = QP_ENCD_STATE_INIT;
            return cnt;
        }
        else
        {
            cntx->remain = c;
            cntx->state = QP_ENCD_STATE_LWSP;
            return 0;
        }
    }

    if (QP_IS_CR(c))
    {
        if (QP_NEED_ENCD_CRLF)
        {
            buf[cnt++] = '=';
            buf[cnt++] = QP_HEX_TABLE[(unsigned char)c >> 4];
            buf[cnt++] = QP_HEX_TABLE[(unsigned char)c & 0xF];
            cntx->state = QP_ENCD_STATE_INIT;
            return cnt;
        }
        else
        {
            cntx->state = QP_ENCD_STATE_CR;
            return cnt;
        }
    }

    if (QP_IS_LF(c))
    {
        /* single LF without CR, take it as CONTROL character */
        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)c >> 4];
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)c & 0xF];
        cntx->state = QP_ENCD_STATE_INIT;
        return cnt;
    }

    /* Others */
    if (c < 32 || c == 61 || c > 126 || (c == 95 && QP_NEED_ENCD_SPACE))
    {
        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)c >> 4];
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)c & 0xF];
        cntx->state = QP_ENCD_STATE_INIT;
        return cnt;
    }
    else
    {
        buf[cnt++] = c;
        cntx->state = QP_ENCD_STATE_INIT;
        return cnt;
    }
}


/*****************************************************************************
 * FUNCTION
 *  encode_state_lwsp
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of encoded bytes
 *****************************************************************************/
static kal_int32 encode_state_lwsp(applib_qprint_context* cntx,
                    kal_char buf[],kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    QP_ASSERT(!QP_NEED_ENCD_CRLF);

    if (QP_IS_TAB(c))
    {
        buf[cnt++] = cntx->remain;
        cntx->remain = c;
        cntx->state = QP_ENCD_STATE_LWSP;
        return cnt;
    }

    if (QP_IS_SPACE(c))
    {
        buf[cnt++] = cntx->remain;
        if (QP_NEED_ENCD_SPACE)
        {
            buf[cnt++] = '_';
            cntx->state = QP_ENCD_STATE_INIT;
            return cnt;
        }
        else
        {
            cntx->remain = c;
            cntx->state = QP_ENCD_STATE_LWSP;
            return cnt;
        }
    }

    if (QP_IS_CR(c))
    {
        cntx->state = QP_ENCD_STATE_LWSPCR;
        return cnt;
    }

    if (QP_IS_LF(c))
    {        
        /* single LF without CR take it as CONTROL character */
        buf[cnt++] = cntx->remain;

        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)(c) >> 4];
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)(c) & 0xF];

        cntx->state = QP_ENCD_STATE_INIT; 
        return cnt;
    }

    /* Others */
    if (c < 32 || c == 61 || c > 126 || (c == 95 && QP_NEED_ENCD_SPACE))
    {
        buf[cnt++] = cntx->remain; /* NOT LINE_END SPACE / TAB */

        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)c >> 4];
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)c & 0xF];
        cntx->state = QP_ENCD_STATE_INIT;
        return cnt;
    }
    else
    {
        buf[cnt++] = cntx->remain; /* NOT LINE_END SPACE / TAB */

        buf[cnt++] = c;
        cntx->state = QP_ENCD_STATE_INIT;
        return cnt;
    }
}


/*****************************************************************************
 * FUNCTION
 *  encode_state_cr
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of encoded bytes
 *****************************************************************************/
static kal_int32 encode_state_cr(applib_qprint_context* cntx,
                    kal_char buf[],kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    QP_ASSERT(!(QP_NEED_ENCD_CRLF));

    if (QP_IS_LF(c))
    {
        buf[cnt++] = '\r';
        buf[cnt++] = '\n';

        if (QP_NEED_AUTO_WRAP)
        {
            cntx->line_cnt = -(cnt); /* new line */
        }

        cntx->state = QP_ENCD_STATE_INIT;
    }
    else
    {
        /*
         * Invalide! Single CR without LF.
         * take it as CONTROL character
         */
        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE['\r' >> 4];
        buf[cnt++] = QP_HEX_TABLE['\r' & 0xF];
        
        cntx->state = QP_ENCD_STATE_INIT;
        cnt += encode_state_init(cntx,buf+cnt,c);
    }
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  encode_state_lwspcr
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of encoded bytes
 *****************************************************************************/
static kal_int32 encode_state_lwspcr(applib_qprint_context* cntx,
                    kal_char buf[],kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    QP_ASSERT(!(QP_NEED_ENCD_CRLF));
    
    if (QP_IS_LF(c))
    {
        /* check the line-wrap count here */
        if (QP_NEED_AUTO_WRAP &&
            ((cntx->line_cnt + 3) > QP_LINE_WRAP_COUNT))
        {
            buf[cnt++] = '=';
            buf[cnt++] = '\r';
            buf[cnt++] = '\n';
        }
        
        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)(cntx->remain) >> 4];
        buf[cnt++] = QP_HEX_TABLE[(unsigned char)(cntx->remain) & 0xF];

        buf[cnt++] = '\r';
        buf[cnt++] = '\n';

        if (QP_NEED_AUTO_WRAP)
        {
            cntx->line_cnt = -(cnt); /* new line */
        }

        cntx->state = QP_ENCD_STATE_INIT;
    }
    else
    {
        /*
         * Invalide! Single CR without LF.
         * take it as CONTROL character
         */
        buf[cnt++] = cntx->remain;
        buf[cnt++] = '=';
        buf[cnt++] = QP_HEX_TABLE['\r' >> 4];
        buf[cnt++] = QP_HEX_TABLE['\r' & 0xF];
        
        cntx->state = QP_ENCD_STATE_INIT;
        cnt += encode_state_init(cntx,buf+cnt,c);
    }
    
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_decode_init
 * DESCRIPTION
 *  This function initializes the STREAM-STYLE part by part quote-printable 
 *  decode process and calculate the needed output buffer size per-part.
 * PARAMETERS
 *  cntx            [IN]        point to the applib_qprint_context
 *  max_part_size   [IN]        the number of MAX input buffer size per-part.
 *  opt             [IN]        decode option
 * RETURNS
 *  negative:   invalid parameter.
 *  ow: the MIN output buffer size needed for the per-parts process.
 *****************************************************************************/
kal_int32 applib_qprint_part_decode_init(
            applib_qprint_context* cntx,
            kal_int32 max_part_size,
            kal_uint8 opt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        QP_ASSERT(0);
        return -1;
    }

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx->illege = 0;
    cntx->opt = opt;
    cntx->state = QP_DECODE_STATE_INIT;
    cntx->state2 = QP_DECODE_STATE_INIT;
    return max_part_size;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_decode_append
 * DESCRIPTION
 *  This function accepts next part of source data; 
 *  decode them from Quote-Printable format
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  src         [IN]        pointer to the input buffer
 *  srcl        [IN]        length of the input buffer
 *  dest        [IN/OUT]    pointer to the output buffer
 *  destl       [IN]        length of the output buffer
 * RETURNS
 *  negative:   the destination buffer is not enough.
 *  ow: the number of bytes written to output buffer.
 *****************************************************************************/
kal_int32 applib_qprint_part_decode_append(
            applib_qprint_context* cntx,
            const kal_char *src,
            kal_int32 *srcl,
            kal_char *dst,
            kal_int32 dstl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char buf[4];
    kal_int32 cnt;

    kal_char  c,pre_hex;
    kal_int32 i_input,i_output;

    kal_char pre_state,pre_state2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL ||
        srcl == NULL ||
        (*srcl > 0 && src == NULL))
    {
        return -1;
    }

    i_input = i_output = 0;
    while(i_input < *srcl)
    {
        pre_hex = cntx->remain;
        pre_state = cntx->state;
        pre_state2 = cntx->state2;

        cnt = 0;
        c = src[i_input++];
        switch (cntx->state)
        {
        case QP_DECODE_STATE_INIT:
            cnt = decode_state_init(cntx,buf,c);
            break;

        case QP_DECODE_STATE_PAD:
            cnt = decode_state_pad(cntx,buf,c);
            break;

        case QP_DECODE_STATE_PADHEX:
            cnt = decode_state_padhex(cntx,buf,c);
            break;

        case QP_DECODE_STATE_PADCR:
            cnt = decode_state_padcr(cntx,buf,c);
            break;

        default:
            QP_ASSERT(0);
            cntx->state = QP_DECODE_STATE_INIT;
            cntx->state2 = QP_DECODE_STATE_INIT;
            break;
        }

        if (cnt == 0)
        {
            continue;
        }
        QP_ASSERT(cnt == 1);

        if (dst == NULL)
        {
            return -1;
        }

        if (i_output + cnt > dstl)
        {
            /* output buffer size not enough */
            /* roll back to pre-state */
            i_input--;
            cntx->state = pre_state;
            cntx->state2 = pre_state2;
            cntx->remain = pre_hex;
            break;
        }
        kal_mem_cpy(dst+i_output,buf,cnt);
        i_output += cnt;
    }

    if (*srcl != i_input)
    {
        QP_WARRING();
    }

    *srcl = i_input;
    return i_output;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_part_decode_finish
 * DESCRIPTION
 *  This function finishes the part-by-part decoding process.
 * PARAMETERS
 *  cntx           [IN]        point to the applib_qprint_context
 *  illegal_format [IN/OUT]    pointer to the illegal format flag
 * RETURNS
 *  0: success
 *  ow:   the context was NULL
 *****************************************************************************/
kal_int32 applib_qprint_part_decode_finish(
            applib_qprint_context *cntx,
            kal_bool *illegal_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
    {
        QP_ASSERT(0);
        return -1;
    }

    if (cntx->state != QP_DECODE_STATE_INIT)
    {
        cntx->illege = 1;
    }

    if (cntx->illege)
    {
        QP_WARRING();
    }

    if (illegal_format != NULL)
    {        
        *illegal_format = (kal_bool)cntx->illege;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  decode_state_init
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of decoded bytes
 *****************************************************************************/
static kal_int32 decode_state_init(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    QP_ASSERT(cntx->state2 == QP_DECODE_STATE_INIT);
    if (QP_IS_PAD(c))
    {
        cntx->state = QP_DECODE_STATE_PAD;
    }
    else
    {
        if ((c == '_') && QP_NEED_DECD_UDRLNE)
        {
            buf[cnt++] = 32; /* SPACE */
        }
        else
        {
            buf[cnt++] = c;
        }
        cntx->state = QP_DECODE_STATE_INIT;
    }

    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  decode_state_pad
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of decoded bytes
 *****************************************************************************/
static kal_int32 decode_state_pad(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (QP_IS_LWSP(c))
    {
        /* just skip safely */
        cntx->state = QP_DECODE_STATE_PAD;
    }
    else if (QP_IS_CR(c))
    {
        cntx->state = QP_DECODE_STATE_PADCR;
    }
    else if (QP_IS_HEX(c))
    {
        if (cntx->state2 == QP_DECODE_STATE_INIT)
        {
            cntx->remain = c;
            cntx->state = QP_DECODE_STATE_PADHEX;
        }
        else
        {
            /* Invalidate */
            cntx->illege = 1;

            cntx->remain = c;
            cntx->state = QP_DECODE_STATE_PADHEX;
            cntx->state2 = QP_DECODE_STATE_INIT;
        }
    }
    else if (QP_IS_PAD(c))
    {
        if (cntx->state2 == QP_DECODE_STATE_INIT)
        {
            cntx->state = QP_DECODE_STATE_PAD;
            cntx->state2 = QP_DECODE_STATE_PAD;
        }
        else
        {
            /* Invalidate */
            cntx->illege = 1;

            buf[cnt++] = '=';
            cntx->state = QP_DECODE_STATE_PAD;
            cntx->state2 = QP_DECODE_STATE_INIT;
        }
    }
    else
    {
        /* Invalidate */
        cntx->illege = 1;

        buf[cnt++] = c;
        cntx->state = QP_DECODE_STATE_INIT;
        cntx->state2 = QP_DECODE_STATE_INIT;
    }
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  decode_state_padhex
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of decoded bytes
 *****************************************************************************/
static kal_int32 decode_state_padhex(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    QP_ASSERT(cntx->state2 == QP_DECODE_STATE_INIT);

    if (QP_IS_LWSP(c))
    {
        /* just skip safely */
        cntx->state = QP_DECODE_STATE_PADHEX;
    }
    else if (QP_IS_HEX(c))
    {
        /* One QP encoded charater found */
        buf[cnt++] = QP_DECD_HEX(cntx->remain,c);
        cntx->state = QP_DECODE_STATE_INIT;
    }
    else if (QP_IS_PAD(c))
    {
        cntx->state = QP_DECODE_STATE_PAD;
        cntx->state2 = QP_DECODE_STATE_PADHEX;
    }
    else
    {
        /* invalid */
        cntx->illege = 1;

        buf[cnt++] = c;
        cntx->state = QP_DECODE_STATE_INIT;
        cntx->state2 = QP_DECODE_STATE_INIT;
    }
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  decode_state_padcr
 * DESCRIPTION
 * PARAMETERS
 *  cntx        [IN]        point to the applib_qprint_context
 *  buf         [IN/OUT]
 *  c           [IN]
 * RETURNS
 *  length of decoded bytes
 *****************************************************************************/
static kal_int32 decode_state_padcr(applib_qprint_context* cntx,
                    kal_char buf[], kal_char c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (QP_IS_LF(c))
    {
        /* Soft Line Break, just skip safely*/
        if (cntx->state2 == QP_DECODE_STATE_PADHEX || QP_DECODE_STATE_PAD)
        {
            cntx->state = cntx->state2;
            cntx->state2 = QP_DECODE_STATE_INIT;
        }
        else
        {
            cntx->state = QP_DECODE_STATE_INIT;
            cntx->state2 = QP_DECODE_STATE_INIT;
        }
    }
    else
    {
        /* Invalid */
        cntx->illege = 1;

        buf[cnt++] = c;
        cntx->state = QP_DECODE_STATE_INIT;
        cntx->state2 = QP_DECODE_STATE_INIT;
    }
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_encode_basic
 * DESCRIPTION
 *  This function is used to encode quoted printable string.
 * PARAMETERS
 *  src         [IN]        pointer to the buffer containing encoded data
 *  srcl        [IN]        length of the encoded data
 *  dest        [IN/OUT]    pointer to the destination buffer
 *  destl       [IN]        length of destination buffer
 *  opt         [IN]        encode option
 * RETURNS
 *  negative:   the destination buffer is not enough.
 *  ow: the number of bytes written to output buffer.
 *****************************************************************************/
kal_int32 applib_qprint_encode_basic(const kal_char *src,
                kal_int32 srcl,
                kal_char *dst,
                kal_int32 dstl,
                kal_uint8 opt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_qprint_context cntx;
    kal_int32 temp,len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srcl <= 0)
    {
        return 0;
    }

    if (dst == NULL)
    {
        len = srcl * 3;
        if ((opt & QPOPT_ENCODE_AUTO_LINEWRAP) > 0)
        {
            len += (len / QP_LINE_WRAP_COUNT + 1) * 3;
        }
        return len;
    }

    if (srcl > 0 && src == NULL)
    {
        QP_ASSERT(0);
        return -1;
    }

    temp = srcl;
    applib_qprint_part_encode_init(&cntx,0,opt);
    len = applib_qprint_part_encode_append(&cntx,src,&temp,dst,dstl);
    QP_ASSERT(temp == srcl);
    QP_ASSERT(len <= dstl);

    temp = applib_qprint_part_encode_finish(&cntx,dst + len, dstl - len);
    if (temp < 0)
    {
        QP_ASSERT(0);
        return -1;
    }

    len += temp;
    return len;
}


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_decode_basic
 * DESCRIPTION
 *  This function is used to decode quoted printable string.
 * PARAMETERS
 *  src         [IN]        pointer to the buffer containing encoded data
 *  srcl        [IN]        length of the encoded data
 *  dest        [IN/OUT]    pointer to the destination buffer
 *  destl       [IN]        length of destination buffer
 *  opt         [IN]        decode option
 * RETURNS
 *  negative:   the output buffer is not enough.
 *  ow: Length of the decoded data
 *****************************************************************************/
kal_int32 applib_qprint_decode_basic(const kal_char *src,
                kal_int32 srcl,
                kal_char *dst,
                kal_int32 dstl,
                kal_uint8 opt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_qprint_context cntx;
    kal_int32 len,temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srcl <= 0)
    {
        return 0;
    }

    if (dst == NULL)
    {
        return srcl;
    }

    if (src == NULL)
    {
        return -1;
    }

    temp = srcl;
    applib_qprint_part_decode_init(&cntx,0,opt);
    len = applib_qprint_part_decode_append(&cntx,src,&temp,dst,dstl);
    if (len < 0 || temp != srcl)
    {
        /* buffer is not enough */
        QP_ASSERT(0);
        len = -1;
    }
    applib_qprint_part_decode_finish(&cntx,NULL);
    return len;
}






/* 
 * NOTE:
 * the Functions below will be obsoleted.
 * them are here just for compatible with old code.
 */


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_decode
 * DESCRIPTION
 *  This function is used to decode quoted printable string.
 * PARAMETERS
 *  src         [IN]        Pointer to the buffer containing encoded data
 *  srcl        [IN]        Length of the encoded data
 *  dest        [IN]        Length of destination buffer Will append null character.
 *  destl       [IN]        
 * RETURNS
 *  negative: error
 *  ow: Length of the decoded data (not include null character)
 *****************************************************************************/
kal_int32 applib_qprint_decode(kal_char *src, kal_uint32 srcl, kal_char *dest, kal_uint32 destl)
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

    ret = applib_qprint_decode_basic(src,(kal_int32)srcl,dest,(kal_int32)destl,0);
    if (ret <= 0 || ret > (kal_int32)destl)
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
 *  applib_find_qprint_boundary
 * DESCRIPTION
 *  This function finds the boundary in the qprint encoded text.
 * PARAMETERS
 *  ptr     [IN]        Pointer to the encoded buffer
 *  len     [IN]        Length of encoded data
 * RETURNS
 *  number of bytes shall be skipped.
 *****************************************************************************/
kal_uint16 applib_find_qprint_boundary(kal_char *ptr, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* with initial values */
    kal_uint16 left_over_bytes = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len >= 2 && *(ptr + len - 2) == '=')    /* penultimate */
    {
        left_over_bytes = 2;
    }
    else if (len >= 1 && *(ptr + len - 1) == '=')   /* ultimate */
    {
        left_over_bytes = 1;
    }

    return left_over_bytes;

}   /* end of applib_find_qprint_boundary */


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_encode_ext
 * DESCRIPTION
 *  This function is used to encode given string into QP encoded string.
 * PARAMETERS
 *  src             [IN]            Source
 *  srcl            [IN]            Source length
 *  dest            [IN/OUT]        Dest buffer
 *  destl           [IN]            Destination buffer length
 *  encode_crlf     [IN]            TRUE:  "\r\n" ==> "=0D=0A"
 *  FALSE: "\r\n" ==> "\r\n"
 * RETURNS
 *  negative: error
 *  ow: length of QP encoded buffer
 *****************************************************************************/
kal_int32 applib_qprint_encode_ext(
            kal_char *src,
            kal_uint32 srcl,
            kal_char *dest,
            kal_uint32 destl,
            kal_bool encode_crlf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;
    kal_uint8 opt = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest == NULL)
    {
        return -1;
    }

    opt |= QPOPT_ENCODE_AUTO_LINEWRAP;
    if (encode_crlf)
    {
        opt |= QPOPT_ENCODE_CRLF;
    }

    ret = applib_qprint_encode_basic(src,srcl,dest,destl,opt);
    if (ret <= 0 || ret > (kal_int32)destl)
    {
        return -1;
    }

    /* 
     * add the null-end,
     * but the return length not include the null-terminator 
     */
    dest[ret] = 0;
    return ret;
}   /* end of applib_qprint_encode_ext */


/*****************************************************************************
 * FUNCTION
 *  applib_qprint_encode
 * DESCRIPTION
 *  This function is used to encode given string into QP encoded string.
 * PARAMETERS
 *  src         [IN]            Source
 *  srcl        [IN]            Source length
 *  dest        [IN/OUT]        Dest buffer
 *  destl       [IN]            Destination buffer length
 * RETURNS
 *  negative: error
 *  ow: length of QP encoded buffer
 *****************************************************************************/
kal_int32 applib_qprint_encode(kal_char *src, kal_uint32 srcl, kal_char *dest, kal_uint32 destl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_qprint_encode_ext(src, srcl, dest, destl, KAL_FALSE);
}
