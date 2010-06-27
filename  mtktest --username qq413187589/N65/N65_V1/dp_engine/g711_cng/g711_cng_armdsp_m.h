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
 *   G711_CNG_armdsp_m.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   ARM-DSP instruction library for G.711 Appendix II Comfort Noise Generator implementation
 *
 * Author:
 * -------
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* armdsp.h
 *
 * Copyright 2001 ARM Limited. All rights reserved.
 *
 * RCS $Revision:   1.0  $
 * Checkin $Date:   Aug 19 2005 17:31:10  $
 * Revising $Author:   BM  $
 */

/* ----------------------------------------------------------------------
 * This header file provides a set of DSP-type primitive
 * operations, such as saturating integer arithmetic and 16x16 bit
 * multiplication. The operations it provides are exactly the same
 * operations supported directly by the ARM9E.
 * 
 * This header file is intended as an example implementation. It
 * demonstrates how to use the inline assembly feature in the ARM
 * compilers, to construct intrinsic functions that provide
 * C-language access to the ARM9E's DSP capability.
 */

#ifndef G711_CNG_ARMDSP_H
#define G711_CNG_ARMDSP_H

#include "G711_CNG_typedef.h"

#define MAX_32 (Word32)0x7fffffffL
#define MIN_32 (Word32)0x80000000L
#define MAX_16 (Word16)0x7fff
#define MIN_16 (Word16)0x8000

#define ARMDSP_WORD32_MAX ((Word32)0x7FFFFFFF)
#define ARMDSP_WORD32_MIN ((Word32)-0x80000000)
#define ARMDSP_WORD16_MAX ((Word16)0x7FFF)
#define ARMDSP_WORD16_MIN ((Word16)-0x8000)

#ifndef WIN32
typedef long long Word64;
#else
typedef __int64 Word64;
#endif
#define lo64(a) (((unsigned*) &a)[0])    /* low 32 bits of a long long */
#define hi64(a) (((int*) &a)[1])        /* high 32 bits of a long long */

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#if !__TARGET_FEATURE_DSPMUL
__inline Word32 _saturate(Word64 ret)
{
    if(ret > ARMDSP_WORD32_MAX)
    {
        ret = ARMDSP_WORD32_MAX;
        //armdsp_flagdata_global.armdsp_bitfields.armdsp_q = 1;
    }
    else if(ret < ARMDSP_WORD32_MIN)
    {
        ret = ARMDSP_WORD32_MIN;
        //armdsp_flagdata_global.armdsp_bitfields.armdsp_q = 1;
    }
    return (Word32)ret;
}
#endif

/*
 * Saturating 32-bit integer addition.
 */
__inline Word32 qadd(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        qadd ret, x, y;
    }
#else
    Word64 r64;
    r64 = (Word64)x + (Word64)y;
    ret = _saturate(r64);
#endif
    return ret;
}

/*
 * Saturating 32-bit integer subtraction.
 */
__inline Word32 qsub(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        qsub ret, x, y;
    }
#else
    Word64 r64;
    r64 = (Word64)x - (Word64)y;
    ret = _saturate(r64);
#endif
    return ret;
}

/*
 * Saturating 32-bit integer addition, with the second operand
 * multiplied by two. (i.e. return x + 2 * y)
 */
__inline Word32 qdadd(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        qdadd ret, x, y;
    }
#else
    Word64 r64;
    r64 = (Word64)x + 2*(Word64)y;
    ret = _saturate(r64);
#endif
    return ret;
}

/*
 * Saturating 32-bit integer subtraction, with the second operand
 * multiplied by two. (i.e. return x - 2 * y)
 */
__inline Word32 qdsub(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        qdsub ret, x, y;
    }
#else
    Word64 r64;
    r64 = (Word64)x - 2*(Word64)y;
    ret = _saturate(r64);
#endif
    return ret;
}

/*
 * Multiply two signed 16-bit numbers, taken from the bottom or top
 * halves of the input words. For example, smulbt(x,y) multiplies
 * the bottom 16 bits of x with the top 16 bits of y.
 */

/* smulbb - multiply bottom half of x and bottom half of y */
__inline Word32 smulbb(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smulbb ret, x, y;
    }
#else
    x = (x << 16) >> 16;
    y = (y << 16) >> 16;
    ret = x * y;
#endif
    return ret;
}

/* smulbt - multiply bottom half of x and top half of y */
__inline Word32 smulbt(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smulbt ret, x, y;
    }
#else
    x = (x << 16) >> 16;
    y = y >> 16;
    ret = x * y;
#endif
    return ret;
}

/* smultb - multiply top half of x and bottom half of y */
__inline Word32 smultb(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smultb ret, x, y;
    }
#else
    x = x >> 16;
    y = (y << 16) >> 16;
    ret = x * y;
#endif
    return ret;
}

/* smultt - multiply top half of x and top half of y */
__inline Word32 smultt(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smultt ret, x, y;
    }
#else
    x = x >> 16;
    y = y >> 16;
    ret = x * y;
#endif
    return ret;
}

/*
 * Multiply two signed 16-bit numbers, taken from the bottom or top
 * halves of the input words x and y, and add to the input word a.
 * For example, smlabt(x,y,a) multiplies the bottom 16 bits of x with
 * the top 16 bits of y, and then adds a.
 */

/* smlabb - multiply bottom half of x and bottom half of y */
__inline Word32 smlabb(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlabb ret, x, y, a;
    }
#else
    Word64 L64;
    x = (x << 16) >> 16;
    y = (y << 16) >> 16;
    L64 = (Word64)x * (Word64)y + (Word64)a;
    (void)_saturate( L64 );
    ret = (Word32)L64;
#endif
    return ret;
}

/* smlabt - multiply bottom half of x and top half of y */
__inline Word32 smlabt(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlabt ret, x, y, a;
    }
#else
    Word64 L64;
    x = (x << 16) >> 16;
    y = y >> 16;
    L64 = (Word64)x * (Word64)y + (Word64)a;
    (void)_saturate( L64 );
    ret = (Word32)L64;
#endif
    return ret;
}

/* smlatb - multiply top half of x and bottom half of y */
__inline Word32 smlatb(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlatb ret, x, y, a;
    }
#else
    Word64 L64;
    x = x >> 16;
    y = (y << 16) >> 16;
    L64 = (Word64)x * (Word64)y + (Word64)a;
    (void)_saturate( L64 );
    ret = (Word32)L64;
#endif
    return ret;
}

/* smlatt - multiply top half of x and top half of y */
__inline Word32 smlatt(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlatt ret, x, y, a;
    }
#else
    Word64 L64;
    x = x >> 16;
    y = y >> 16;
    L64 = (Word64)x * (Word64)y + (Word64)a;
    (void)_saturate( L64 );
    ret = (Word32)L64;
#endif
    return ret;
}

/*
 * Multiply two signed 16-bit numbers, taken from the bottom or top
 * halves of the input words x and y, and add to the 64-bit integer
 * stored in the input words lo and hi. For example,
 * smlalbt(&lo,&hi,x,y) multiplies the bottom 16 bits of x with the
 * top 16 bits of y, and then adds the result to (hi,lo).
 * 
 * WARNING: if you use these primitives too often inside the same
 * function, they may fail to be inlined.
 */

/* smlalbb - multiply bottom half of x and bottom half of y */
__inline void smlalbb(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlalbb *lo, *hi, x, y;
    }
#else
    Word64 ret;
    lo64(ret) = *lo;
    hi64(ret) = *hi;
    x = (x << 16) >> 16;
    y = (y << 16) >> 16;
    ret = x * y + ret;
    *lo = lo64(ret);
    *hi = hi64(ret);
#endif
}

/* smlalbt - multiply bottom half of x and top half of y */
__inline void smlalbt(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlalbt *lo, *hi, x, y;
    }
#else
    Word64 ret;
    lo64(ret) = *lo;
    hi64(ret) = *hi;
    x = (x << 16) >> 16;
    y = y >> 16;
    ret = x * y + ret;
    *lo = lo64(ret);
    *hi = hi64(ret);
#endif
}

/* smlaltb - multiply top half of x and bottom half of y */
__inline void smlaltb(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlaltb *lo, *hi, x, y;
    }
#else
    Word64 ret;
    lo64(ret) = *lo;
    hi64(ret) = *hi;
    x = x >> 16;
    y = (y << 16) >> 16;
    ret = x * y + ret;
    *lo = lo64(ret);
    *hi = hi64(ret);
#endif
}

/* smlaltt - multiply top half of x and top half of y */
__inline void smlaltt(Word32 *lo, Word32 *hi, Word32 x, Word32 y)
{
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlaltt *lo, *hi, x, y;
    }
#else
    Word64 ret;
    lo64(ret) = *lo;
    hi64(ret) = *hi;
    x = x >> 16;
    y = y >> 16;
    ret = x * y + ret;
    *lo = lo64(ret);
    *hi = hi64(ret);
#endif
}

/*
 * Multiply a 32-bit signed integer (the input word x) with a
 * 16-bit signed integer (taken from either the top or the bottom
 * half of the input word y). Discard the bottom 16 bits of the
 * 48-bit product.
 */

/* smulwb - multiply x by the bottom half of y */
__inline Word32 smulwb(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smulwb ret, x, y;
    }
#else
    Word64 ret64;
    y = (y << 16) >> 16;
    ret64 = (Word64)x * (Word64)y;
    ret = (Word32)(ret64 >> 16);
#endif
    return ret;
}

/* smulwt - multiply x by the top half of y */
__inline Word32 smulwt(Word32 x, Word32 y)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smulwt ret, x, y;
    }
#else
    Word64 ret64;
    y = y >> 16;
    ret64 = (Word64)x * (Word64)y;
    ret = (Word32)(ret64 >> 16);
#endif
    return ret;
}

/*
 * Multiply a 32-bit signed integer (the input word x) with a
 * 16-bit signed integer (taken from either the top or the bottom
 * half of the input word y). Discard the bottom 16 bits of the
 * 48-bit product, and add to the input word a.
 */

/* smlawb - multiply x by the bottom half of y */
__inline Word32 smlawb(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlawb ret, x, y, a;
    }
#else
    Word64 ret64;
    y = (y << 16) >> 16;
    ret64 = (Word64)x * (Word64)y;
    ret = (Word32)(ret64 >> 16) + a;
#endif
    return ret;
}

/* smlawt - multiply x by the top half of y */
__inline Word32 smlawt(Word32 x, Word32 y, Word32 a)
{
    Word32 ret;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlawt ret, x, y, a;
    }
#else
    Word64 ret64;
    y = y >> 16;
    ret64 = (Word64)x * (Word64)y;
    ret = (Word32)(ret64 >> 16) + a;
#endif
    return ret;
}

__inline Word32 smull(Word32 x, Word32 y)
{
#if __TARGET_FEATURE_DSPMUL
    Word32 a, b;
    __asm {
        smull a, b, x, y;
    }
    return b;
#else
    Word64 ret = (Word64)x * (Word64)y;
    return((Word32)hi64(ret));
#endif
}

__inline Word64 smlal(Word64 LL_acc, Word32 x, Word32 y)
{
#if __TARGET_FEATURE_DSPMUL
    __asm {
        smlal lo64(LL_acc), hi64(LL_acc), x, y;
    }
#else
    LL_acc += (Word64)x * (Word64)y;
#endif
    return LL_acc;
}

__inline Word32 clz(Word32 absx)
{
    Word32 lz;
#if __TARGET_FEATURE_DSPMUL
    __asm {
        clz lz, absx;
    }
#else
    Word32 j = 1 << 31;
    for(lz=0; lz<32; lz++, j>>=1)
      if( absx&j ) break;
#endif
    return lz;
}

#ifdef __cplusplus
}
#endif

#endif /* G711_CNG_ARMDSP_H */
