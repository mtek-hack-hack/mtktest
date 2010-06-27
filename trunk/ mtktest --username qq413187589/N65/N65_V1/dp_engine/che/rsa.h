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
 *    file rsa.h
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
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * code review. add log placeholder.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __RSA_H__
#define __RSA_H__



#ifdef __cplusplus
extern "C" {
#endif



#include "rsa_math.h"

#define ERR_RSA_BAD_INPUT_DATA                  0x0300
#define ERR_RSA_INVALID_PADDING                 0x0310
#define ERR_RSA_KEY_GEN_FAILED                  0x0320
#define ERR_RSA_KEY_CHK_FAILED                  0x0330
#define ERR_RSA_PUBLIC_FAILED                   0x0340
#define ERR_RSA_PRIVATE_FAILED                  0x0350
#define ERR_RSA_VERIFY_FAILED                   0x0360

/*
 * PKCS#1 stuff
 */
#define RSA_RAW             0
#define RSA_MD2             2
#define RSA_MD4             3
#define RSA_MD5             4
#define RSA_SHA1            5

#define RSA_SIGN            0x01
#define RSA_CRYPT           0x02

/*
 * DigestInfo ::= SEQUENCE {
 *   digestAlgorithm DigestAlgorithmIdentifier,
 *   digest Digest }
 *
 * DigestAlgorithmIdentifier ::= AlgorithmIdentifier
 *
 * Digest ::= OCTET STRING
 */
#define ASN1_HASH_MDX                       \
    "\x30\x20\x30\x0C\x06\x08\x2A\x86\x48"  \
    "\x86\xF7\x0D\x02\x00\x05\x00\x04\x10"

#define ASN1_HASH_SHA1                      \
    "\x30\x21\x30\x09\x06\x05\x2B\x0E\x03"  \
    "\x02\x1A\x05\x00\x04\x14"

typedef struct
{
    kal_int32 ver;    /*!<  should be 0       */
    kal_int32 len;    /*!<  size(N) in chars  */
    mpi N;      /*!<  public modulus    */
    mpi E;      /*!<  public exponent   */
    mpi D;      /*!<  private exponent  */

    mpi P;      /*!<  1st prime factor  */
    mpi Q;      /*!<  2nd prime factor  */
    mpi DP;     /*!<  D mod (P - 1)     */
    mpi DQ;     /*!<  D mod (Q - 1)     */
    mpi QP;     /*!<  inverse of Q % P  */

    mpi RN;     /*!<  cached R^2 mod N  */
    mpi RP;     /*!<  cached R^2 mod P  */
    mpi RQ;     /*!<  cached R^2 mod Q  */
}
rsa_context;

/**
 * Generate an RSA keypair
 *
 * param ctx      RSA context to be initialized
 * param nbits    size of the public key in bits
 * param exponent public exponent (e.g., 65537)
 * param rng_f    points to the RNG function
 * param rng_d    points to the RNG data 
 *
 * return         0 if successful, or an ERR_RSA_XXX error code
 */
kal_int32 rsa_gen_key( rsa_context *ctx, kal_int32 nbits, kal_int32 exponent,
                 kal_int32 (*rng_f)(void *), void *rng_d );

/*
 *Perform an RSA public key operation
 *
 *return         0 if successful, or an ERR_RSA_XXX error code
 *
 *note           This function does not take care of message
 *               padding: both ilen and olen must be equal to
 *               the modulus size (ctx->len). Also, be sure
 *                 to set input[0] = 0.
 */
kal_int32 rsa_public( rsa_context   *ctx,
                kal_uint8 *input,  kal_int32 ilen,
                kal_uint8 *output, kal_int32 olen );

/**
 *Perform an RSA private key operation
 *
 *return         0 if successful, or an ERR_RSA_XXX error code
 *
 *note           This function does not take care of message
 *               padding: both ilen and olen must be equal to
 *               the modulus size (ctx->len). Also, be sure
 *                 to set input[0] = 0.
 */
kal_int32 rsa_private( rsa_context   *ctx,
                 kal_uint8 *input,  kal_int32 ilen,
                 kal_uint8 *output, kal_int32 olen );

/*
 *Return 0 if the public key is valid,
 *or ERR_RSA_KEY_CHECK_FAILED
 */
kal_int32 rsa_check_pubkey( rsa_context *ctx );

/*
 *Return 0 if the private key is valid,
 *or ERR_RSA_KEY_CHECK_FAILED
 */
kal_int32 rsa_check_privkey( rsa_context *ctx );

/**
 *Add the PKCS#1 v1.5 padding and do a public RSA
 *
 *param ctx      RSA context
 *param input    buffer holding the data to be encrypted
 *param ilen     length of the plaintext; cannot be longer
 *               than the modulus, minus 3+8 for padding
 *param output   buffer that will hold the ciphertext
 *param olen     must be the same as the modulus size
 *               (for example, 128 if RSA-1024 is used)
 *
 *return         0 if successful, or an ERR_RSA_XXX error code
 */
kal_int32 rsa_pkcs1_encrypt( rsa_context   *ctx,
                       kal_uint8 *input,  kal_int32 ilen,
                       kal_uint8 *output, kal_int32 olen );

/*
 *Do a private RSA, removes the PKCS#1 v1.5 padding
 *
 *param ctx      RSA context
 *param input    buffer holding the encrypted data
 *param ilen     must be the same as the modulus size
 *param output   buffer that will hold the plaintext
 *param olen     size of output buffer, will be updated
 *               to contain the length of the plaintext
 *
 *return         0 if successful, or an ERR_RSA_XXX error code
 */
kal_int32 rsa_pkcs1_decrypt( rsa_context   *ctx,
                       kal_uint8 *input,  kal_int32  ilen,
                       kal_uint8 *output, kal_int32 *olen );

/**
 * Perform a private RSA to sign a message digest
 *
 *param ctx      RSA context
 *param alg_id   RSA_RAW, RSA_MD2/4/5 or RSA_SHA1
 *param hash     buffer holding the message digest
 *param hashlen  message digest length
 *param sig      buffer that will hold the ciphertext
 *param siglen   must be the same as the modulus size
 *               (for example, 128 if RSA-1024 is used)
 *
 *return         0 if the signing operation was successful,
 *                 or an ERR_RSA_XXX error code
 */
kal_int32 rsa_pkcs1_sign( rsa_context   *ctx,  kal_int32 alg_id,
                    kal_uint8 *hash, kal_int32 hashlen,
                    kal_uint8 *sig,  kal_int32 siglen );

/**
 * Perform a public RSA and check the message digest
 *
 *param ctx      pokal_int32s to an RSA public key
 *param alg_id   RSA_RAW, RSA_MD2/4/5 or RSA_SHA1
 *param hash     buffer holding the message digest
 *param hashlen  message digest length
 *param sig      buffer holding the ciphertext
 *param siglen   must be the same as the modulus size
 *
 *return         0 if the verify operation was successful,
 *                 or an ERR_RSA_XXX error code
 */
kal_int32 rsa_pkcs1_verify( rsa_context   *ctx,  kal_int32 alg_id,
                      kal_uint8 *hash, kal_int32 hashlen,
                      kal_uint8 *sig,  kal_int32 siglen );

/**
 *Free the components of an RSA key
 */
void rsa_free( rsa_context *ctx );

/**
 * Checkup routine
 *
 * return         0 if successful, or 1 if the test failed
 */
kal_int32 rsa_self_test( void );

#ifdef __cplusplus
}
#endif

#endif /* __RSA_H__ */
