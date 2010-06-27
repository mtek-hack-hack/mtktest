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
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE __CHE_HW__ HEREUNDER WILL BE,
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
 *    rsa_math.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   RSA Engine
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



#ifndef __RSAMATH_H__
#define __RSAMATH_H__



#ifdef __cplusplus
extern "C" {
#endif



#include "kal_release.h"

#define ERR_MPI_INVALID_CHARACTER               0x0002
#define ERR_MPI_INVALID_PARAMETER               0x0004
#define ERR_MPI_BUFFER_TOO_SMALL                0x0006
#define ERR_MPI_NEGATIVE_VALUE                  0x0008
#define ERR_MPI_DIVISION_BY_ZERO                0x000A
#define ERR_MPI_NOT_INVERTIBLE                  0x000C
#define ERR_MPI_IS_COMPOSITE                    0x000E

#define CHK(fc) if( ( ret = fc ) != 0 ) goto cleanup

#define ciL    (int) sizeof(kal_uint32)      /* chars in limb  */
#define biL    (ciL << 3)                    /* bits  in limb  */
#define biH    (ciL << 2)                    /* half limb size */

/**
 * \brief          MPI structure
 */
typedef struct
{
    kal_int32 s;              /*!<  integer sign      */
    kal_int32 n;              /*!<  total # of limbs  */
    kal_uint32 *p;            /*!<  pointer to limbs  */
}
mpi;

//Initialize one or more mpi
void mpi_init( mpi *X, ... );


//Unallocate one or more mpi

void mpi_free( mpi *X, ... );

/*
 * Enlarge X to the specified # of limbs
 *
 * return 0 if successful,
 *         1 if memory allocation failed
 */
kal_int32 mpi_grow( mpi *X, kal_int32 nblimbs );

/*
 *Copy the contents of Y into X
 *
 *return 0 if successful,
 *       1 if memory allocation failed
 */
kal_int32 mpi_copy( mpi *X, mpi *Y );

/*
 * Swap the contents of X and Y
 */
void mpi_swap( mpi *X, mpi *Y );

/*
 *Set value from integer
 *
 * return 0 if successful,
 *        1 if memory allocation failed
 */
kal_int32 mpi_lset( mpi *X, kal_int32 z );

/**
 *  Set value from string
 *
 * param X        destination mpi
 * param s        string to read the value from
 * param radix    numeric base of "s"
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_INVALID_PARAMETER if the radix is invalid
 *                 ERR_MPI_INVALID_CHARACTER if a non-digit is found
 */
kal_int32 mpi_read( mpi *X, unsigned char *s, kal_int32 radix, kal_int32 s_len);



/**
 * Import an unsigned value from binary data
 *
 * param X        destination mpi
 * param buf      input buffer
 * param buflen   size of buffer
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_import( mpi *X, unsigned char *buf, kal_int32 buflen );

/**
 * Export an unsigned value into binary data
 *
 * param X        source mpi
 * param buf      output buffer
 * param buflen   size of buffer
 *
 *return         0 if successful,
 *               ERR_MPI_BUFFER_TOO_SMALL if buf isn't large enough
 *
 *note           Call this function with *buflen = 0 to obtain the
 *                 required buffer size in *buflen.
 */
kal_int32 mpi_export( mpi *X, unsigned char *buf, kal_int32 *buflen );

/**
 * Return actual size in bits (without leading 0s)
 */
kal_int32 mpi_size( mpi *X );

/**
 * Return number of least significant bits
 */
kal_int32 mpi_lsb( mpi *X );

/**
 *Left-shift: X <<= count
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_shift_l( mpi *X, kal_int32 count );

/**
 * Right-shift: X >>= count
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_shift_r( mpi *X, kal_int32 count );

/**
 * Compare unsigned values
 *
 * return         1 if |X| is greater than |Y|,
 *                -1 if |X| is lesser  than |Y| or
 *                 0 if |X| is equal to |Y|
 */
kal_int32 mpi_cmp_abs( mpi *X, mpi *Y );

/**
 * Compare signed values
 *
 * return         1 if X is greater than Y,
 *                -1 if X is lesser  than Y or
 *                 0 if X is equal to Y
 */
kal_int32 mpi_cmp_mpi( mpi *X, mpi *Y );

/**
 * Compare signed values
 *
 * return         1 if X is greater than z,
 *                -1 if X is lesser  than z or
 *                 0 if X is equal to z
 */
kal_int32 mpi_cmp_int( mpi *X, kal_int32 z );

/**
 * Unsigned addition: X = |A| + |B|
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_add_abs( mpi *X, mpi *A, mpi *B );

/**
 * Unsigned substraction: X = |A| - |B|
 *
 * return         0 if successful,
 *                 ERR_MPI_NEGATIVE_VALUE if B is greater than A
 */
kal_int32 mpi_sub_abs( mpi *X, mpi *A, mpi *B );

/**
 * Signed addition: X = A + B
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_add_mpi( mpi *X, mpi *A, mpi *B );

/**
 * Signed substraction: X = A - B
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_sub_mpi( mpi *X, mpi *A, mpi *B );

/**
 * Signed addition: X = A + b
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_add_int( mpi *X, mpi *A, kal_int32 b );

/**
 *Signed substraction: X = A - b
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_sub_int( mpi *X, mpi *A, kal_int32 b );

/**
 * Baseline multiplication: X = A * B
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_mul_mpi( mpi *X, mpi *A, mpi *B );

/**
 * Baseline multiplication: X = A * b
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_mul_int( mpi *X, mpi *A, kal_uint32 b );

/**
 * Division by mpi: A = Q * B + R
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_DIVISION_BY_ZERO if B == 0
 *
 * note           Either Q or R can be NULL.
 */
kal_int32 mpi_div_mpi( mpi *Q, mpi *R, mpi *A, mpi *B );

/**
 * Division by int: A = Q * b + R
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_DIVISION_BY_ZERO if b == 0
 *
 * note           Either Q or R can be NULL.
 */
kal_int32 mpi_div_int( mpi *Q, mpi *R, mpi *A, kal_int32 b );

/**
 * Modulo: R = A mod B
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_DIVISION_BY_ZERO if B == 0
 */
kal_int32 mpi_mod_mpi( mpi *R, mpi *A, mpi *B );

/**
 *modulo: r = A mod b
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_DIVISION_BY_ZERO if b == 0,
 */
kal_int32 mpi_mod_int( kal_uint32 *r, mpi *A, kal_int32 b );

/**
 *  Sliding-window exponentiation: X = A^E mod N
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_INVALID_PARAMETER if N is negative or even
 *
 * note           _RR is used to avoid re-computing R*R mod N across
 *                 multiple calls, which speeds up things a bit. It can
 *                 be set to NULL if the extra performance is unneeded.
 */
kal_int32 mpi_exp_mod( mpi *X, mpi *A, mpi *E, mpi *N, mpi *_RR );

/**
 * Greatest common divisor: G = gcd(A, B)
 *
 * return         0 if successful,
 *                 1 if memory allocation failed
 */
kal_int32 mpi_gcd( mpi *G, mpi *A, mpi *B );

/**
 * Modular inverse: X = A^-1 mod N
 *
 * return         0 if successful,
 *                 1 if memory allocation failed,
 *                 ERR_MPI_INVALID_PARAMETER if N is negative or nil
 *                 ERR_MPI_NOT_INVERTIBLE if A has no inverse mod N
 */
kal_int32 mpi_inv_mod( mpi *X, mpi *A, mpi *N );

/**
 * Miller-Rabin primality test
 *
 *return         0 if successful (probably prime),
 *                 1 if memory allocation failed,
 *                 ERR_MPI_IS_COMPOSITE if X is not prime
 */
kal_int32 mpi_is_prime( mpi *X );

/**
 *  Prime number generation
 *
 * param X        destination mpi
 * param nbits    required size of X in bits
 * param dh_flag  set this to 1 if (X-1)/2 must also be prime
 *                (needed for Diffie-Hellman)
 * param rng_f    points to the RNG function
 * param rng_d    points to the RNG data 
 *
 * return         0 if successful (probably prime),
 *                 1 if memory allocation failed,
 *                 ERR_MPI_INVALID_PARAMETER if nbits is < 3
 */
kal_int32 mpi_gen_prime( mpi *X, kal_int32 nbits, kal_int32 dh_flag,
                   kal_int32 (*rng_f)(void *), void *rng_d );

/**
 *  Checkup routine
 *
 * return         0 if successful, or 1 if the test failed
 */

#define MULADDC_INIT                    \
{                                       \
    kal_uint32 s0, s1, b0, b1;               \
    kal_uint32 r0, r1, rx, ry;               \
    b0 = ( b << biH ) >> biH;           \
    b1 = ( b >> biH );

#define MULADDC_CORE                    \
    s0 = ( *s << biH ) >> biH;          \
    s1 = ( *s >> biH ); s++;            \
    rx = s0 * b1; r0 = s0 * b0;         \
    ry = s1 * b0; r1 = s1 * b1;         \
    r1 += ( rx >> biH );                \
    r1 += ( ry >> biH );                \
    rx <<= biH; ry <<= biH;             \
    r0 += rx; r1 += (r0 < rx);          \
    r0 += ry; r1 += (r0 < ry);          \
    r0 +=  c; r1 += (r0 <  c);          \
    r0 += *d; r1 += (r0 < *d);          \
    c = r1; *(d++) = r0;

#define MULADDC_STOP                    \
}

#ifdef __cplusplus
}
#endif

#endif /* __RSAMATH_H__ */
