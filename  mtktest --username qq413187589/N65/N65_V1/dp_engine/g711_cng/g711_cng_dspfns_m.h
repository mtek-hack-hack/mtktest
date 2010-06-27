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
 *   G711_CNG_dspfns_m.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Standard DSP library for G.711 Appendix II Comfort Noise Generator implementation
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* dspfns.h
 *
 * Copyright 2001 ARM Limited. All rights reserved.
 *
 * RCS $Revision:   1.0  $
 * Checkin $Date:   Aug 19 2005 17:31:14  $
 * Revising $Author:   BM  $
 */

/* ----------------------------------------------------------------------
 * This header file provides a set of DSP-type primitive
 * operations, such as 16-bit and 32-bit saturating arithmetic. The
 * operations it provides are similar to the ones used by the ITU
 * for publishing specifications of DSP algorithms.
 * 
 * This header file is intended as an example implementation. It
 * demonstrates how to use the inline assembly feature in the ARM
 * compilers, to construct intrinsic functions that provide
 * C-language access to the ARM9E's DSP capability.
 * 
 * This header file is NOT SUFFICIENT to be used alone - you need
 * to include "dspfns.c" from the examples\dsp directory as well.
 */

#ifndef G711_CNG_DSPFNS_H
#define G711_CNG_DSPFNS_H

#include "G711_CNG_typedef.h"

#define MAX_32 (Word32)0x7fffffffL
#define MIN_32 (Word32)0x80000000L
#define MAX_16 (Word16)0x7fff
#define MIN_16 (Word16)0x8000

#define ARMDSP_WORD32_MAX ((Word32)0x7FFFFFFF)
#define ARMDSP_WORD32_MIN ((Word32)-0x80000000)
#define ARMDSP_WORD16_MAX ((Word16)0x7FFF)
#define ARMDSP_WORD16_MIN ((Word16)-0x8000)

/*
 * This global variable needs to exist somewhere in the compiled
 * program in order for the flag-using functions to work. You can
 * either include the declaration
 * 
 *   armdsp_flagdata_union armdsp_flagdata;
 * 
 * in at least one of your source files (that includes this
 * header), or compile in "dspfns.c" from the examples\dsp
 * directory.
 */

#ifdef __cplusplus
extern "C" {
#endif

#define __NO_ARM_ASM__

/*
 * Convert a 32-bit signed integer into a 16-bit signed integer by
 * saturation.
 */
__inline Word16 sature(Word32 x)
{
    if (x >= (ARMDSP_WORD16_MAX+1))
        /*Overflow = 1, */x = ARMDSP_WORD16_MAX;
    else if (x < ARMDSP_WORD16_MIN)
        /*Overflow = 1, */x = ARMDSP_WORD16_MIN;
    return (Word16) x;
}

/*
 * Add two 16-bit signed integers with saturation.
 */
__inline Word16 add(Word32 x, Word32 y)
{
#ifdef __NO_ARM_ASM__
    return( qadd( x << 16, y << 16 ) >> 16 );
#else
    Word32 xs, ys, rs;
    __asm {
        mov xs, x, lsl #16;
        mov ys, y, lsl #16;
        qadd rs, xs, ys;
    }
    return (Word16) (rs >> 16);
#endif
}

/*
 * Subtract one 16-bit signed integer from another with saturation.
 */
__inline Word16 sub(Word32 x, Word32 y)
{
#ifdef __NO_ARM_ASM__
    return( qsub( x << 16, y << 16 ) >> 16 );
#else
    Word32 xs, ys, rs;
    __asm {
        mov xs, x, lsl #16;
        mov ys, y, lsl #16;
        qsub rs, xs, ys;
    }
    return (Word16) (rs >> 16);
#endif
}

/*
 * Absolute value of a 16-bit signed integer. Saturating, so
 * abs(-0x8000) becomes +0x7FFF.
 */
__inline Word16 abs_s(Word32 x)
{
    if (x >= 0)
        return x;
    else if (x == ARMDSP_WORD16_MIN)
        return ARMDSP_WORD16_MAX;
    else
        return (Word16) -x;
}

/*
 * Shift a 16-bit signed integer left (or right, if the shift count
 * is negative). Saturate on overflow.
 */
__inline Word16 shl(Word32 x, Word32 shift)
{
    if (shift <= 0 || x == 0)
        return (Word16) (x >> (-shift));
    if (shift > 15)
        shift = 16;
    return sature(x << shift);
}

/*
 * Shift a 16-bit signed integer right (or left, if the shift count
 * is negative). Saturate on overflow.
 */
__inline Word16 shr(Word32 x, Word32 shift)
{
    if (shift >= 0 || x == 0)
        return (Word16) (x >> shift);
    if (shift < -15)
        shift = -16;
    return sature(x << (-shift));
}

/*
 * Multiply two 16-bit signed integers, shift the result right by
 * 15 and saturate it. (Saturation is only necessary if both inputs
 * were -0x8000, in which case the result "should" be 0x8000 and is
 * saturated to 0x7FFF.)
 */
__inline Word16 mult(Word32 x, Word32 y)
{
    Word32 product;
#ifdef __NO_ARM_ASM__
    product = smulbb(x, y);
    return( qadd(product, product) >> 16 );
#else
    __asm {
        smulbb product, x, y;
        qadd product, product, product;
    }
    return (Word16) (product >> 16);   /* the qadd added one to the 15 */
#endif
}

/*
 * Multiply two 16-bit signed integers to give a 32-bit signed
 * integer. Shift left by one, and saturate the result. (Saturation
 * is only necessary if both inputs were -0x8000, in which case the
 * result "should" be 0x40000000 << 1 = +0x80000000, and is
 * saturated to +0x7FFFFFFF.)
 */
__inline Word32 L_mult(Word32 x, Word32 y)
{
    Word32 product;
#ifdef __NO_ARM_ASM__
    product = smulbb(x, y);
    return( qadd(product, product) );
#else
    __asm {
        smulbb product, x, y;
        qadd product, product, product;
    }
    return product;
#endif
}

/*
 * Negate a 16-bit signed integer, with saturation. (Saturation is
 * only necessary when the input is -0x8000.)
 */
__inline Word16 negate(Word32 x)
{
    if (x == ARMDSP_WORD16_MIN)
        return ARMDSP_WORD16_MAX;
    return (Word16) -x;
}

/*
 * Return the top 16 bits of a 32-bit signed integer.
 */
__inline Word32 extract_h(Word32 x)
{
    return (x >> 16);
}

/*
 * Return the bottom 16 bits of a 32-bit signed integer, with no
 * saturation, just coerced into a two's complement 16 bit
 * representation.
 */
__inline Word16 extract_l(Word32 x)
{
    return (Word16) x;
}

/*
 * Divide a 32-bit signed integer by 2^16, rounding to the nearest
 * integer (round up on a tie). Equivalent to adding 0x8000 with
 * saturation, then shifting right by 16.
 */
__inline Word32 round(Word32 x)
{
#ifdef __NO_ARM_ASM__
    x = qadd(x, 0x8000);
#else
    __asm {
        qadd x, x, 0x8000;
    }
#endif
    return extract_h(x);
}

/*
 * Multiply two 16-bit signed integers together to give a 32-bit
 * signed integer, shift left by one with saturation, and add to
 * another 32-bit integer with saturation.
 * 
 * Note the intermediate saturation operation in the definition:
 * 
 *    L_mac(-1, -0x8000, -0x8000)
 * 
 * will give 0x7FFFFFFE and not 0x7FFFFFFF:
 *    the unshifted product is:   0x40000000
 *    shift left with saturation: 0x7FFFFFFF
 *    add to -1 with saturation:  0x7FFFFFFE
 */
__inline Word32 L_mac(Word32 accumulator, Word32 x, Word32 y)
{
    Word32 product;
#ifdef __NO_ARM_ASM__
    product = smulbb(x, y);
    accumulator = qdadd(accumulator, product);
#else
    __asm {
        smulbb product, x, y;
        qdadd accumulator, accumulator, product;
    }
#endif
    return accumulator;
}

/*
 * Multiply two 16-bit signed integers together to give a 32-bit
 * signed integer, shift left by one with saturation, and subtract
 * from another 32-bit integer with saturation.
 * 
 * Note the intermediate saturation operation in the definition:
 * 
 *    L_msu(1, -0x8000, -0x8000)
 * 
 * will give 0x80000002 and not 0x80000001:
 *    the unshifted product is:         0x40000000
 *    shift left with saturation:       0x7FFFFFFF
 *    subtract from 1 with saturation:  0x80000002
 */
__inline Word32 L_msu(Word32 accumulator, Word32 x, Word32 y)
{
    Word32 product;
#ifdef __NO_ARM_ASM__
    product = smulbb(x, y);
    accumulator = qdsub(accumulator, product);
#else
    __asm {
        smulbb product, x, y;
        qdsub accumulator, accumulator, product;
    }
#endif
    return accumulator;
}

/*
 * Add two 32-bit signed integers with saturation.
 */
__inline Word32 L_add(Word32 x, Word32 y)
{
    Word32 result;
#ifdef __NO_ARM_ASM__
    result = qadd(x, y);
#else
    __asm {
        qadd result, x, y;
    }
#endif
    return result;
}

/*
 * Subtract one 32-bit signed integer from another with saturation.
 */
__inline Word32 L_sub(Word32 x, Word32 y)
{
    Word32 result;
#ifdef __NO_ARM_ASM__
    result = qsub(x, y);
#else
    __asm {
        qsub result, x, y;
    }
#endif
    return result;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*
 * Negate a 32-bit signed integer, with saturation. (Saturation is
 * only necessary when the input is -0x80000000.)
 */
__inline Word32 L_negate(Word32 x)
{
    if (x == ARMDSP_WORD32_MIN)
        return ARMDSP_WORD32_MAX;
    return -x;
}

/*
 * Multiply two 16-bit signed integers, shift the result right by
 * 15 with rounding, and saturate it. (Saturation is only necessary
 * if both inputs were -0x8000, in which case the result "should"
 * be 0x8000 and is saturated to 0x7FFF.)
 */
__inline Word16 mult_r(Word32 x, Word32 y)
{
    Word32 product;
#ifdef __NO_ARM_ASM__
    product = qdadd(0x8000, smulbb(x, y));
#else
    __asm {
        smulbb product, x, y;
        qdadd product, 0x8000, product;
    }
#endif
    return (Word16) (product >> 16);   /* qdadd adds one to the 15 */
}

/*
 * Shift a 32-bit signed integer left (or right, if the shift count
 * is negative). Saturate on overflow.
 */
__inline Word32 L_shl(Word32 x, Word32 shift)
{
    int lz;
    int absx;
    if (shift <= 0)
        return x >> (-shift);
    absx = (x < 0 ? -x : x);
#ifdef __NO_ARM_ASM__
    lz = clz(absx);
#else
    __asm {
        clz lz, absx;
    }
#endif
    if (shift < lz || x == 0)
        return x << shift;
    if (x < 0)
        return ARMDSP_WORD32_MIN;
    else
        return ARMDSP_WORD32_MAX;
}

/*
 * Shift a 32-bit signed integer right (or left, if the shift count
 * is negative). Saturate on overflow.
 */
__inline Word32 L_shr(Word32 x, Word32 shift)
{
    int lz;
    int absx;
    if (shift >= 0)
        return x >> shift;
    absx = (x < 0 ? -x : x);
#ifdef __NO_ARM_ASM__
    lz = clz(absx);
#else
    __asm {
        clz lz, absx;
    }
#endif
    if (-shift < lz || x == 0)
        return x << (-shift);
    if (x < 0)
        return ARMDSP_WORD32_MIN;
    else
        return ARMDSP_WORD32_MAX;
}

/*
 * Shift a 16-bit signed integer right, with rounding. Shift left
 * with saturation if the shift count is negative.
 */
__inline Word16 shr_r(Word32 x, Word32 shift)
{
    if (shift == 0 || x == 0)
        return (Word16) (x >> shift);
    if (shift > 0)
        return (Word16) (((x >> (shift-1)) + 1) >> 1);
    if (shift < -15)
        shift = -16;
    return sature(x << (-shift));
}

/*
 * Multiply two 16-bit signed integers together to give a 32-bit
 * signed integer, shift left by one with saturation, and add to
 * another 32-bit integer with saturation (like L_mac). Then shift
 * the result right by 15 bits with rounding (like round).
 */
__inline Word16 mac_r(Word32 accumulator, Word32 x, Word32 y)
{
    return round(L_mac(accumulator, x, y));
}

/*
 * Multiply two 16-bit signed integers together to give a 32-bit
 * signed integer, shift left by one with saturation, and subtract
 * from another 32-bit integer with saturation (like L_msu). Then
 * shift the result right by 15 bits with rounding (like round).
 */
__inline Word16 msu_r(Word32 accumulator, Word32 x, Word32 y)
{
    return round(L_msu(accumulator, x, y));
}

/*
 * Shift a 16-bit signed integer left by 16 bits to generate a
 * 32-bit signed integer. The bottom 16 bits are zeroed.
 */
__inline Word32 L_deposit_h(Word32 x)
{
    return x << 16;
}

/*
 * Sign-extend a 16-bit signed integer by 16 bits to generate a
 * 32-bit signed integer.
 */
__inline Word32 L_deposit_l(Word32 x)
{
    return x;
}

/*
 * Shift a 32-bit signed integer right, with rounding. Shift left
 * with saturation if the shift count is negative.
 */
__inline Word32 L_shr_r(Word32 x, Word32 shift)
{
    int lz;
    int absx;
    if (shift == 0 || x == 0)
        return x >> shift;
    if (shift > 0) {
        Word32 x2 = x >> (shift-1);
        return (x2 >> 1) + (x2 & 1);
    }
    absx = (x < 0 ? -x : x);
#ifdef __NO_ARM_ASM__
    lz = clz(absx);
#else
    __asm {
        clz lz, absx;
    }
#endif
    if (-shift < lz || x == 0)
        return x << (-shift);
    if (x < 0)
        return ARMDSP_WORD32_MIN;
    else
        return ARMDSP_WORD32_MAX;
}

/*
 * Absolute value of a 32-bit signed integer. Saturating, so
 * abs(-0x80000000) becomes +0x7FFFFFFF.
 */
__inline Word32 L_abs(Word32 x)
{
    if (x >= 0)
        return x;
    else if (x == ARMDSP_WORD32_MIN)
        return ARMDSP_WORD32_MAX;
    else
        return -x;
}

/*
 * Return a saturated value appropriate to the most recent carry-
 * affecting operation (L_add_c, L_macNs, L_sub_c, L_msuNs).
 * 
 * In other words: return the argument if the Q flag is clear.
 * Otherwise, return -0x80000000 or +0x7FFFFFFF depending on
 * whether the Carry flag is set or clear (respectively).
 */
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif

/*
 * Return the number of bits of left shift needed to arrange for a
 * 16-bit signed integer to have value >= 0x4000 or <= -0x4001.
 * 
 * Returns zero if x is zero.
 */
__inline Word32 norm_s(Word32 x)
{
    int lz;
    x = (Word16) (x ^ (x >> 15));      /* invert x if it's negative */
#ifdef __NO_ARM_ASM__
    lz = clz(x);
#else
    __asm {
        clz lz, x;
    }
#endif
    return (lz - 17);
}

/*
 * Divide one 16-bit signed integer by another, and produce a
 * 15-bit fixed point fractional result (by multiplying the true
 * mathematical result by 0x8000). The divisor (denominator) is
 * assumed to be non-zero and also assumed to be greater or equal
 * to the dividend (numerator). Hence the (unscaled) result is
 * necessarily within the range [0,1].
 * 
 * Both operands are assumed to be positive.
 * 
 * After division, the result is saturated to fit into a 16-bit
 * signed integer. (The only way this can happen is if the operands
 * are equal, so that the result would be 1, i.e. +0x8000 in 15-bit
 * fixed point.)
 */
__inline Word16 div_s(Word16 x, Word16 y)
{
    Word32 quot;
    if (y!=0) quot = (Word32)(0x8000 * (Word32)x) / y;
    if (y==0 || quot > (ARMDSP_WORD16_MAX))
        return ARMDSP_WORD16_MAX;
    else
        return (Word16)quot;
}

/*
 * Return the number of bits of left shift needed to arrange for a
 * 32-bit signed integer to have value >= 0x40000000 (if 
 * 
 * Returns zero if x is zero.
 */
__inline Word32 norm_l(Word32 x)
{
    int lz;
    x ^= (x >> 31);                    /* invert x if it's negative */
#ifdef __NO_ARM_ASM__
    lz = clz(x);
#else
    __asm {
        clz lz, x;
    }
#endif
    return (lz - 1);
}


__inline Word32 L_mls( Word32 Lv, Word16 v )
{
   Word32 High, ret;
   UWord32 Low;
#if __TARGET_FEATURE_DSPMUL
   __asm {
      smull Low, High, Lv, v;
   }
#else
   Word64 r64 = (Word64)Lv * (Word64)v;
   High = hi64(r64);
   Low = lo64(r64);
#endif

   ret = (High << 17) | (Low >> 15);

   return ret;
}

__inline Word16 i_mult(Word16 a, Word16 b)
{
   return  a*b;
}

// Divide a 31-bits positive integer by 15-bits positive integer
// Return 16-bit result
static __inline Word16 div_l( Word32 num, Word16 den )
{
   Word32 L_num, L_den;
   Word16 sign;

   L_den = den << 16;
   if (num >= 0) {
      L_num = num;
      sign = 1;
   } else {
      L_num = L_negate(num);
      sign = -1;
   }
   
   if ( L_num >= L_den ){
      return (sign * 0x7fff);
   } else {
      return (num / den)>>1;
   }
}


#ifdef __cplusplus
}
#endif

#endif /* ARMDSP_DSPFNS_H */
